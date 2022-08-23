#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat {

private:
	Bureaucrat(void);
	std::string name_;
	int         grade_;

public:
	~Bureaucrat(void);
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat  &operator=(const Bureaucrat &other);
	void        incrementGrade(void);
	void        decrementGrade(void);
	std::string getName(void) const;
	int         getGrade(void) const;

	class GradeTooHighException : public std::out_of_range {
	public:
		GradeTooHighException();
	};

	class GradeTooLowException : public std::out_of_range {
	public:
		GradeTooLowException();
	};
};

std::ostream&   operator<<(std::ostream &os, const Bureaucrat &output);


#endif