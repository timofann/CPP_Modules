#ifndef FORM_HPP
#define FORM_HPP

class Bureaucrat;

#include "Bureaucrat.hpp"
#include <string>

class Form {

private:
	Form();
	const std::string   name_;
	bool                signed_;
	const int           grade_need_to_sign_;
	const int           grade_need_to_execute_;

public:
	Form(const std::string &name,
		 const int grade_need_to_sign,
		 const int grade_need_to_execute);
	Form(const Form &copy);
	virtual             ~Form();
	Form                &operator=(const Form &other);
	void                beSigned(const Bureaucrat &b);
	virtual void        execute(Bureaucrat const &executor) const = 0;
	std::string         getName() const;
	int                 getGradeNeedToSign() const;
	int                 getGradeNeedToExecute() const;
	bool                isSigned() const;

	class GradeTooHighException : public std::invalid_argument {
	public:
		GradeTooHighException();
	};

	class GradeTooLowException : public std::invalid_argument {
	public:
		GradeTooLowException();
	};

	class ShouldBeSignedException : public std::invalid_argument {
	public:
		ShouldBeSignedException();
	};
};

std::ostream &operator<<(std::ostream &os, const Form &output);

#endif
