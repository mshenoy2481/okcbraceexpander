#include <okc_braceexpander_expression.h>
#include <okc_braceexpander_expression_parser.h>
#include <okc_braceexpander_exceptions.h>
#include <okc_braceexpander_expression_preprocessor.h>

#include <stack>
#include <queue>
#include <set>
#include <string>
#include <memory>
#include <iostream>
#include <functional>

namespace okc {
namespace BraceExpander {

namespace {

enum ExpressionTerm
{
    ADD = 0,
    MULTIPLY,
    PAREN_OPEN,
    PAREN_CLOSE,
    LITERAL
};

/**
 * Translates the next character in the string to corresponding arithmetic term
 */
ExpressionTerm charToTerm(char c)
{
    switch (c)
    {
    case '{':
        return PAREN_OPEN;
    case ',':
        return ADD;
    case '}':
        return PAREN_CLOSE;
    default:
        return LITERAL;
    }
}

/**
 * Evaluate the expression/operation stacks while condition is true.
 * Evaluation involves popping an expression from the expression stack and
 * an operation from the operation stack, and merging the popped expression into
 * the top of the expression stack based on the operation.
 */
void evaluateStacksWhile(
        std::stack<std::shared_ptr<Expression> > &expressionStack,
        std::stack<ExpressionTerm> &operationStack,
        std::function<bool(std::stack<ExpressionTerm>&)> condition)
{
    std::shared_ptr<Expression> nextExpr = expressionStack.top();
    expressionStack.pop();
    while (condition(operationStack))
    {
        ExpressionTerm nextOperation = operationStack.top();
        operationStack.pop();
        if (nextOperation == ADD)
        {
            *(expressionStack.top()) += *nextExpr;
        } else if (nextOperation == MULTIPLY)
        {
            *(expressionStack.top()) *= *nextExpr;
        }
        nextExpr = expressionStack.top();
        expressionStack.pop();
    }
    expressionStack.emplace(nextExpr);
}
}

std::string ExpressionParser::parse(const std::string &inputStr)
{
    //Trim and validate
    std::string trimmedInput = okc::BraceExpander::ExpressionPreprocessor::trim(
            inputStr);
    okc::BraceExpander::ExpressionPreprocessor::validate(trimmedInput);

    std::stack<std::shared_ptr<Expression> > expressionStack;
    std::stack<ExpressionTerm> operationStack;

    int inputLen = trimmedInput.length();
    int curr = 0;
    while (curr < inputLen)
    {
        ExpressionTerm currentTerm = charToTerm(trimmedInput[curr]);

        switch (currentTerm)
        {
        case PAREN_OPEN:
        {
            //Check for implied multiplication - if the previous character is a
            //closing brace (e.g. ..A}{B..) or a literal (e.g. ..A{..), this is
            //a multiplication.
            if (curr - 1 >= 0)
            {
                ExpressionTerm prevTerm = charToTerm(trimmedInput[curr - 1]);
                if (prevTerm == LITERAL || prevTerm == PAREN_CLOSE)
                {
                    operationStack.emplace(MULTIPLY);
                }
            }
            operationStack.emplace(PAREN_OPEN);
            ++curr;
            break;
        }
        case PAREN_CLOSE:
        {
            //Parenthesis have the highest precedence in PEMDAS, so evaluate
            //the stack until open parenthesis is hit.
            evaluateStacksWhile(expressionStack, operationStack,
                    [](std::stack<ExpressionTerm> &operationStack) -> bool
                    {
                        return (operationStack.top() != PAREN_OPEN);
                    });
            operationStack.pop();

            //Check for implied multiplication - if the following character is a
            //literal (e.g. ..}A..), this is a multiplication.
            if (curr + 1 < inputLen)
            {
                ExpressionTerm nextTerm = charToTerm(trimmedInput[curr + 1]);
                if (nextTerm == LITERAL)
                {
                    operationStack.emplace(MULTIPLY);
                }
            }
            ++curr;
            break;
        }
        case ADD:
        {
            //Multiplication has higher precedence than addition in PEMDAS, so evaluate
            //all multiply operations on the stack until a non-multiplication operation is found.
            evaluateStacksWhile(expressionStack, operationStack,
                    [](std::stack<ExpressionTerm> &operationStack) -> bool
                    {
                        return (!operationStack.empty() && operationStack.top() == MULTIPLY);
                    });
            //Special case - commas (additions) are not allowed outside braces. Since we have hit
            //the bottom of the operation stack, an attempt is being made here to add an addition operation
            //outside of braces, so throw.
            if(operationStack.empty())
            {
                throw InvalidExpresionException("Commas(append) outside braces not allowed.");
            }
            operationStack.emplace(ADD);
            ++curr;
            break;
        }
        case LITERAL:
        {
            //Scrape the next literal from the input and add it onto the expression stack.
            std::string literal = "";
            while (isalpha(trimmedInput[curr]) && curr < inputLen)
            {
                literal.append(1, trimmedInput[curr]);
                ++curr;
            }
            std::shared_ptr<Expression> expr(new Expression(literal));
            expressionStack.emplace(expr);
            break;
        }
        }
    }
    //All the parenthesis have been evaluated by this point, so the only operations left to evaluate must
    //be multiplications. So, evaluate them.
    evaluateStacksWhile(expressionStack, operationStack,
            [](std::stack<ExpressionTerm> &operationStack) -> bool
            {
                return (!operationStack.empty() && operationStack.top() == MULTIPLY);
            });
    if(expressionStack.size() > 1)
    {
        throw InvalidExpresionException("Unevaluated expressions on stack.");
    }
    return expressionStack.top()->str();
}

}
}
