#ifndef OKC_BRACEEXPANDER_EXCEPTIONS_H
#define OKC_BRACEEXPANDER_EXCEPTIONS_H

#include <exception>
#include <string>

namespace okc {
namespace BraceExpander {

/**
 * Thrown when a problems in user input are detected. Problems can include non-matching braces,
 * characters not in [a-zA-Z{},] etc.
 */
class InvalidExpresionException: public std::exception
{
private:
    /**
     * Error message describing what caused this exception to be thrown
     */
    std::string _msg;

public:
    InvalidExpresionException(const std::string &msg);
    const char* what() const throw ();
};

/**
 * Internal exception. Thrown if an unimplemented function is accidentally invoked.
 */
class NotImplementedException
{
public:
    NotImplementedException();
};

}
}

#endif
