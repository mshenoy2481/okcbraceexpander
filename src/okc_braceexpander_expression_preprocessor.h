#ifndef OKC_BRACEEXPANDER_EXPRESSION_PREPROCESSOR_H
#define OKC_BRACEEXPANDER_EXPRESSION_PREPROCESSOR_H

#include <string>

namespace okc {
namespace BraceExpander {

namespace ExpressionPreprocessor {

/**
 * Remove whitespaces before and after the string
 */
std::string trim(const std::string &inputStr);

/**
 * Validate the input string based on a simple linear scan.
 * This will catch most common user errors including mismatched brackets,
 * invalid characters etc. More uncommon errors like commas outside brackets
 * will be caught at the time of actual evaluation.
 */
void validate(const std::string &inputStr);

}

}
}

#endif
