#include "Form.hpp"
#include <iostream>

Form::Form() : name_("empty_name"),
               signed_(false),
			   grade_need_to_sign_(150),
			   grade_need_to_execute_(150) {}

Form::Form(const std::string &name,
           const int grade_need_to_sign,
           const int grade_need_to_execute) :
		   name_(name),
		   signed_(false),
		   grade_need_to_sign_(grade_need_to_sign),
		   grade_need_to_execute_(grade_need_to_execute) {
	if (grade_need_to_sign < 1 || grade_need_to_execute < 1)
		throw Form::GradeTooHighException();
	if (grade_need_to_sign > 150 || grade_need_to_execute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &copy) :
				name_(copy.name_),
				signed_(copy.signed_),
				grade_need_to_sign_(copy.grade_need_to_sign_),
				grade_need_to_execute_(copy.grade_need_to_execute_) {}

Form::~Form() {}

Form &Form::operator=(const Form &other) {
	if (this != &other)
		this->signed_ = other.signed_;
	return *this;
}

void Form::beSigned(const Bureaucrat &b) {
	if (!this->isSigned() && b.getGrade() <= this->grade_need_to_sign_) {
		this->signed_ = true;
		std::cout << this->name_ << "\033[3;32m SIGNED!\033[0m" << std::endl;
	}
}

std::string Form::getName() const {
	return this->name_;
}

int Form::getGradeNeedToSign() const {
	return this->grade_need_to_sign_;
}

int Form::getGradeNeedToExecute() const {
	return this->grade_need_to_execute_;
}

bool Form::isSigned() const {
	return this->signed_;
}

Form::GradeTooHighException::GradeTooHighException() :
  std::invalid_argument("\033[3;32mThe highest grade is 1\033[0m") {}

Form::GradeTooLowException::GradeTooLowException() :
  std::invalid_argument("\033[3;31mThere is no grade lower than 150\033[0m") {}

Form::ShouldBeSignedException::ShouldBeSignedException() :
	std::invalid_argument("\033[3;31mForm should be signed!\033[0m") {}

std::ostream &operator<<(std::ostream &os, const Form &output) {
	os << "\033[3;37m"
	   << output.getName() << ", is signed : " << output.isSigned()
	   << ", grade need to sign : " << output.getGradeNeedToSign()
	   << ", grade need to execute : " << output.getGradeNeedToExecute()
	   << "\033[0m";
	return os;
}