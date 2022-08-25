#include "LiteralConverter.hpp"
#include <string>
#include <iostream>

LiteralConverter::LiteralConverter(const std::string &literal) :
								   char_repr_(nullptr),
								   int_repr_(nullptr),
								   float_repr_(nullptr),
								   double_repr_(nullptr) {
	fillCurrentType(literal);
	std::string new_info[4] = {"not_set", "not_set", "not_set", "not_set"};
	std::memcpy(&this->info, &new_info, sizeof(std::string) * 4);
}

LiteralConverter::~LiteralConverter() {
	delete char_repr_;
	delete int_repr_;
	delete float_repr_;
	delete double_repr_;
}

LiteralConverter::LiteralConverter(const LiteralConverter &copy) :
								   char_repr_(nullptr),
								   int_repr_(nullptr),
								   float_repr_(nullptr),
								   double_repr_(nullptr) {
	*this = copy;
}

void LiteralConverter::clearInfo() {
	delete char_repr_;      this->char_repr_ = nullptr;
	delete int_repr_;       this->int_repr_ = nullptr;
	delete float_repr_;     this->float_repr_ = nullptr;
	delete double_repr_;    this->double_repr_ = nullptr;
}

LiteralConverter &LiteralConverter::operator=(const LiteralConverter &other) {
	if (this == &other)
		return *this;
	clearInfo();
	if (other.char_repr_ != 0)
		this->char_repr_ = new unsigned char(*(other.char_repr_));
	if (other.int_repr_ != 0)
		this->int_repr_ = new int(*(other.int_repr_));
	if (other.float_repr_ != 0)
		this->float_repr_ = new float(*(other.float_repr_));
	if (other.double_repr_ != 0)
		this->double_repr_ = new double(*(other.double_repr_));
	std::memcpy(&this->info, &other.info, sizeof(std::string) * 4);
	return *this;
}

void LiteralConverter::fillCurrentType(const std::string &literal) {
	if (literal.length() == 1 && isalpha(literal[0])) {
		this->char_repr_ = new unsigned char(literal[0]); return; }
	if (literal == "nan" || literal == "nanf") {
		this->float_repr_ = new float(0.0f / 0.0f); return; }
	if (literal == "+inf" || literal == "inf" || literal == "inff" || literal == "+inff" ) {
		this->float_repr_ = new float(1.0f / 0.0f); return; }
	if (literal == "-inf" || literal == "-inff") {
		this->float_repr_ = new float(-1.0f / 0.0f); return; }

	double d;
	try {
		d = std::stod(literal);
		size_t i;
		for (i = 0; i < literal.length(); ++i) {
			if (!isdigit(literal[i]) && !(literal[i] == '+' || literal[i] == '-'))
				break;
		}
		if (i == literal.length()) {
			try {
				this->int_repr_ = new int(stoi(literal)); return;
			} catch (std::out_of_range) {
				this->double_repr_ = new double(d); return;
			}
		}
		if (literal[i] == '.') {
			++i;
			for (; i < literal.length(); ++i) {
				if (!isdigit(literal[i]))
					break;
			}
		}
		if (literal[i] == 'f' && i == literal.length() - 1) {
			this->float_repr_ = new float(stof(literal)); return; }
		if (i == literal.length()) {
			this->double_repr_ = new double(d); return; }
		throw LiteralConverter::LiteralNotIdentifiedException();
	} catch (...) {
		throw LiteralConverter::LiteralNotIdentifiedException();
	}
}

void LiteralConverter::convertToChar() {
	if (this->char_repr_ != nullptr)
		return;
	convertToInt();
	if (this->int_repr_ == nullptr) {
		this->info[0] = "impossible"; return; }
	if (*this->int_repr_ > UCHAR_MAX || *this->int_repr_ < 0) {
		this->info[0] = "impossible"; return; }
	if (!std::isprint(*this->int_repr_)) {
		this->info[0] = "not displayable"; return; }
	this->char_repr_ = new unsigned char(static_cast<unsigned char>(*this->int_repr_));
}

void LiteralConverter::convertToInt() {
	if (this->int_repr_ != nullptr)
		return;
	if (this->char_repr_ != nullptr) {
		this->int_repr_ = new int(static_cast<int>(*this->char_repr_)); return; }
	convertToFloat();
	if (((*this->float_repr_) >= (float)INT_MIN) && ((*this->float_repr_) <= (float)INT_MAX)) {
		this->int_repr_ = new int(static_cast<int>(*this->float_repr_)); return; }
	this->info[1] = "impossible";
}

void LiteralConverter::convertToFloat() {
	if (this->float_repr_ != nullptr)
		return;
	if (this->char_repr_ != nullptr) {
		this->float_repr_ = new float(static_cast<float>(*this->char_repr_)); return; }
	if (this->int_repr_ != nullptr) {
		this->float_repr_ = new float(static_cast<float>(*this->int_repr_)); return; }
	this->float_repr_ = new float(static_cast<float>(*this->double_repr_));
}

void LiteralConverter::convertToDouble() {
	if (this->double_repr_ != nullptr)
		return;
	if (this->char_repr_ != nullptr) {
		this->double_repr_ = new double(static_cast<double>(*this->char_repr_)); return; }
	if (this->int_repr_ != nullptr) {
		this->double_repr_ = new double(static_cast<double>(*this->int_repr_)); return; }
	this->double_repr_ = new double(static_cast<double>(*this->float_repr_));
}

void LiteralConverter::printInfo() {
	std::cout << "char: ";
	(this->char_repr_ == nullptr) ? std::cout << this->info[0]: std::cout << "'" << *this->char_repr_ << "'";
	std::cout << std::endl << "int: ";
	(this->int_repr_ == nullptr) ? std::cout << this->info[1]: std::cout << *this->int_repr_;
	std::cout << std::endl << "float: ";
	(this->float_repr_ == nullptr) ? std::cout << this->info[2]: std::cout << *this->float_repr_ << 'f';
	std::cout << std::endl << "double: ";
	(this->double_repr_ == nullptr) ? std::cout << this->info[3]: std::cout << *this->double_repr_;
	std::cout << std::endl;
}

LiteralConverter::LiteralNotIdentifiedException::LiteralNotIdentifiedException() :
	std::invalid_argument("\033[3;31mLiteral not identified\033[0m") {}