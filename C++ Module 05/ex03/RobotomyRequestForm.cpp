#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
		Form("RobotomyRequestForm", 72, 45), target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) :
		Form(copy), target_(copy.target_) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this == &other)
		return *this;
	this->Form::operator=(other);
	this->target_ = other.target_;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	static int random_val;
	random_val++;
	if (!this->isSigned())
		throw Form::ShouldBeSignedException();
	if (this->getGradeNeedToExecute() < executor.getGrade())
		throw Bureaucrat::GradeTooLowException();
	std::cout << "*beep-drdrdrdr-beep!" << std::endl;
	if (random_val % 2)
		std::cout << this->target_ << " has been robotomized successfully" << std::endl;
	else
		std::cout << "the robotomy failed" << std::endl;
}