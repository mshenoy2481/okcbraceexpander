#include <okc_braceexpander_expression_preprocessor.h>
#include <okc_braceexpander_exceptions.h>

#include <iostream>

namespace okc {
namespace BraceExpander {

namespace {

const char BRACE_OPEN = '{';
const char BRACE_CLOSE = '}';
const char COMMA = ',';

}

std::string ExpressionPreprocessor::trim(const std::string &inputStr)
{
    size_t first = inputStr.find_first_not_of(' ');
    if (std::string::npos == first)
    {
        return "";
    }
    size_t last = inputStr.find_last_not_of(' ');
    return inputStr.substr(first, (last - first + 1));
}

void ExpressionPreprocessor::validate(const std::string &inputStr)
{
    int inputStrLen = inputStr.length();
    int braceCount = 0;
    char prevChar = '\0';
    if (inputStr.empty())
    {
        throw InvalidExpresionException("Empty expression");
    }
    for (auto currChar : inputStr)
    {
        bool isCurrCharLiteral = isalpha(currChar);
        if (!isCurrCharLiteral && currChar != BRACE_OPEN
                && currChar != BRACE_CLOSE && currChar != COMMA)
        {
            throw InvalidExpresionException("Invalid character found in the expression.");
        }
        if (currChar == BRACE_CLOSE)
        {
            if (braceCount != 0)
            {
                --braceCount;
            } else
            {
                throw InvalidExpresionException(
                        "Expression has fewer { than }.");
            }
        }
        if (currChar == BRACE_OPEN)
        {
            ++braceCount;
        }
        if (prevChar == BRACE_OPEN || prevChar == COMMA)
        {
            if (currChar == BRACE_CLOSE || currChar == COMMA)
            {
                throw InvalidExpresionException("Empty sub-expression found");
            }
        }
        prevChar = currChar;
    }
    if (braceCount > 0)
    {
        throw InvalidExpresionException("Expression has fewer } than {.");
    }
}

}
}
