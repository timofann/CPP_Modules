#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name_("empty_name"), grade_(150) {};

Bureaucrat::~Bureaucrat(void) {} ;

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name_(name) {
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) :
										name_(copy.name_),
										grade_(150) {};

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other)
		this->grade_ = other.grade_;
	return *this;
}

void Bureaucrat::executeForm(Form const &f) {
	try {
		f.execute(*this);
		std::cout << "\033[3;32m"
		          << this->name_ << " executed " << f.getName()
		          << "\033[0m" << std::endl;
	} catch (std::exception &e) {
		std::cout << "\033[3;31m"
				  << this->name_ << " not executed " << f.getName()
				  << ": \033[0m";
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(Form &f) {
	if (f.isSigned())
		std::cout << "\033[3;31m"
		          << this->name_ << " couldn’t sign " << f.getName()
		          << " because it is already signed\033[0m" << std::endl;
	else {
		if (this->grade_ <= f.getGradeNeedToSign()) {
			f.beSigned(*this);
			std::cout << "\033[3;32m"
			          << this->name_ << " signed " << f.getName()
					  << "\033[0m" << std::endl;
		}
		else
			std::cout << "\033[3;31m"
			          << this->name_ << " couldn’t sign " << f.getName()
			          << " because his grade is too low\033[0m" << std::endl;
	}
}

void Bureaucrat::incrementGrade(void) {
	if (this->grade_ == 1)
		throw Bureaucrat::GradeTooHighException();
	--this->grade_;
}

void Bureaucrat::decrementGrade(void) {
	if (this->grade_ == 150)
		throw Bureaucrat::GradeTooLowException();
	++this->grade_;
}

std::string Bureaucrat::getName(void) const {
	return this->name_;
}

int Bureaucrat::getGrade(void) const {
	return this->grade_;
}

Bureaucrat::GradeTooHighException::GradeTooHighException() :
	std::out_of_range("\033[3;31mGrade too high\033[0m") {}

Bureaucrat::GradeTooLowException::GradeTooLowException() :
	std::out_of_range("\033[3;31mGrade too low\033[0m") {}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &output) {
	os << "\033[3;37m"
	   << output.getName() << ", bureaucrat grade " << output.getGrade()
	   << "\033[0m";
	return os;
}