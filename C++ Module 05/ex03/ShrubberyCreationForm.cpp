#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>

#define TREES "\
       000  000000             0000000\n\
   0 00000000000000000       00000000000   000\n\
  0000000000000000000000    0000000000000000000\n\
 0000000000000000000000     00000000000000000000\n\
    00000  0000000000000      0000000000000000\n\
           11 00000000          00  111  0000\n\
           11                       111\n\
           11                       111"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
		Form("ShrubberyCreationForm", 145, 137), target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) :
		Form(copy), target_(copy.target_) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this == &other)
		return *this;
	this->Form::operator=(other);
	this->target_ = other.target_;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	std::ofstream out_file;
	if (!this->isSigned())
		throw Form::ShouldBeSignedException();
	if (this->getGradeNeedToExecute() < executor.getGrade())
		throw Bureaucrat::GradeTooLowException();
	out_file.open(this->target_ + "_shrubbery");
	out_file << TREES;
	out_file.close();
}