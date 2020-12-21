#include <okc_braceexpander_exceptions.h>

namespace okc {
namespace BraceExpander {

InvalidExpresionException::InvalidExpresionException(const std::string &msg) :
        _msg(msg)
{

}

const char* InvalidExpresionException::what() const throw ()
{
    return _msg.c_str();
}

NotImplementedException::NotImplementedException()
{

}

}
}
