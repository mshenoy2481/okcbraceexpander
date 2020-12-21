#ifndef OKC_BRACEEXPANDER_EXPRESSION_H
#define OKC_BRACEEXPANDER_EXPRESSION_H

#include <vector>
#include <string>

namespace okc {
namespace BraceExpander {

/**
 * An expression is a list of one or more literals.
 * An expression can be merged into another expression through addition (append)
 * or multiplication (generating combinations).
 * Copy and assignment are disabled to block internal vector copies.
 */
class Expression
{
public:
    Expression();
    Expression(const std::string &literal);
    Expression(Expression&& exp);

    /**
     * Literal list in the input expression is appended at the
     * end of this expression
     */
    Expression& operator +=(const Expression &expr);

    /**
     * Contents of this literal list are replaced by combinations
     * of this literal list and the input expression literal list
     */
    Expression& operator *=(const Expression &expr);

    /**
     * Prints out the literal list with spaces in between
     */
    std::string str();

private:
    Expression(const Expression &exp);
    Expression& operator=(const Expression&);

    std::vector<std::string> _literalList;
};

}
}

#endif
