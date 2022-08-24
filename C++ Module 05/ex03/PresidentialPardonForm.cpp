#include "Form.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
		Form("PresidentialPardonForm", 25, 5), target_(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) :
		Form(copy), target_(copy.target_) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this == &other)
		return *this;
	this->Form::operator=(other);
	this->target_ = other.target_;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!this->isSigned())
		throw Form::ShouldBeSignedException();
	if (this->getGradeNeedToExecute() < executor.getGrade())
		throw Bureaucrat::GradeTooLowException();
	std::cout << this->target_ << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}