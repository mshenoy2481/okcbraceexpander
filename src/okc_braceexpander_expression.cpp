#include <okc_braceexpander_expression.h>
#include <okc_braceexpander_exceptions.h>

#include <sstream>

namespace okc {
namespace BraceExpander {

Expression::Expression() :
        _literalList()
{

}

Expression::Expression(const std::string &literal) :
        _literalList({literal})
{
}

Expression::Expression(Expression&& exp) :
        _literalList(std::move(exp._literalList))
{
}

Expression& Expression::operator +=(const Expression &expr)
{
    for (auto &nextStr : expr._literalList)
    {
        _literalList.emplace_back(nextStr);
    }
    return *this;
}

Expression& Expression::operator *=(const Expression &expr)
{
    std::vector<std::string> resExpr;
    for (auto &lStr : _literalList)
    {
        for (auto &rStr : expr._literalList)
        {
            resExpr.emplace_back(lStr + rStr);
        }
    }
    _literalList = std::move(resExpr);
    return *this;
}

std::string Expression::str()
{
    std::stringstream sstr;
    int size = _literalList.size();
    for (int i = 0; i < size; ++i)
    {
        sstr << _literalList[i];
        if (i != (size - 1))
        {
            sstr << " ";
        }
    }
    return sstr.str();
}

Expression::Expression(const Expression &exp)
{
    //Not implemented
    throw NotImplementedException();
}

Expression& Expression::operator=(const Expression&)
{
    //Not implemented
    throw NotImplementedException();
    return *this;
}

}
}
