#include <iostream>
#include <string>
#include "LiteralConverter.hpp"

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Usage: ./conversionOfScalarTypes < literal >" << std::endl;
		return 0;
	}
	try {
		LiteralConverter converter(argv[1]);
		converter.convertToChar();
		converter.convertToInt();
		converter.convertToFloat();
		converter.convertToDouble();
		converter.printInfo();
	} catch (LiteralConverter::LiteralNotIdentifiedException &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
