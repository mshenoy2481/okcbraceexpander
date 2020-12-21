#include <iostream>
#include <okc_braceexpander_expression_preprocessor.h>
#include <okc_braceexpander_exceptions.h>
#include <okc_braceexpander_expression_parser.h>

int main(int argc, char** argv)
{
	try{
        std::string inputLine;
        std::getline(std::cin, inputLine);
        std::cout << okc::BraceExpander::ExpressionParser::parse(inputLine) << std::endl;
	}
	catch(okc::BraceExpander::InvalidExpresionException& e)
	{
	    //handle exception
	    return -1;
	}
	return 0;
}
