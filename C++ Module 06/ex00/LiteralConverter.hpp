#ifndef LITERALCONVERTER_HPP
#define LITERALCONVERTER_HPP

#include <string>
#include <exception>

class LiteralConverter {
private:
	unsigned char       *char_repr_;
	int                 *int_repr_;
	float               *float_repr_;
	double              *double_repr_;
	std::string         info[4];
	void                fillCurrentType(const std::string &literal);
	void                clearInfo();
public:
	LiteralConverter(const std::string &literal);
	~LiteralConverter();
	LiteralConverter(const LiteralConverter &copy);
	LiteralConverter    &operator=(const LiteralConverter &other);
	void                convertToChar();
	void                convertToInt();
	void                convertToFloat();
	void                convertToDouble();
	void                printInfo();

	class LiteralNotIdentifiedException : public std::invalid_argument {
	public:
		LiteralNotIdentifiedException();
	};
};

#endif
