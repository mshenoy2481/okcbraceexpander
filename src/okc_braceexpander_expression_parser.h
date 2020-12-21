#ifndef OKC_BRACEEXPANDER_EXPRESSION_PARSER_H
#define OKC_BRACEEXPANDER_EXPRESSION_PARSER_H

namespace okc {
namespace BraceExpander {

namespace ExpressionParser {

/**
 * Expression parsing utility for bash-like brace expansion.
 * A bash brace expression is not that different than an arithmetic expression with braces standing in for brackets and
 * commas standing in for addition. Multiply is implied - if a brace is immediately preceded/followed by a literal, that's
 * an implied multiplication. A special case is commas not appearing outside of braces (which means no addition outside brackets).
 * This function does the following:
 *    - clean and validate the input string
 *    - translate the brace expression to an arithmetic expression using the above set of rules.
 *    - evaluate that expression using an arithmetic parser pattern with PEMDAS rules.
 *
 * @param inputStr - user-entered input string
 */
std::string parse(const std::string &inputStr);

}
}
}

#endif
