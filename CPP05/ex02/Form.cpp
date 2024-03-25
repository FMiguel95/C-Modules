/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:45:23 by fernacar          #+#    #+#             */
/*   Updated: 2024/02/04 17:04:57 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _gradeReqSign(150), _gradeReqExec(150) {}

Form::Form(const std::string& name, const int& gradeReqSign, const int& gradeReqExec) : _name(name), _signed(false), _gradeReqSign(gradeReqSign), _gradeReqExec(gradeReqExec)
{
	if (_gradeReqSign < 1 || _gradeReqExec < 1)
		throw GradeTooHighException();
	else if (_gradeReqSign > 150 || _gradeReqExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& src) : _name(src._name), _signed(src._signed), _gradeReqSign(src._gradeReqSign), _gradeReqExec(src._gradeReqExec) {}

Form::~Form() {}

Form& Form::operator = (const Form& src)
{
	if (this != &src)
	{
		_signed = src.getSigned();
	}
	return *this;
}

const std::string Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getGradeReqSign() const
{
	return _gradeReqSign;
}

int Form::getGradeReqExec() const
{
	return _gradeReqExec;
}
		
void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeReqSign)
		throw GradeTooLowException();
	else
		_signed = true;
}

void Form::execute(const Bureaucrat& executor) const
{
	if (!getSigned())
		throw NotSignedException();
	else if (executor.getGrade() > getGradeReqExec())
		throw GradeTooLowException();
	else
		formEffect();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("grade is is too high.");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("grade is too low.");
}

const char* Form::NotSignedException::what() const throw()
{
	return ("the form is not signed.");
}

std::ostream& operator << (std::ostream& os, const Form& form)
{
	os << "Form name:" << form.getName() << ", signed:" << form.getSigned() << ", gradeReqSign:" << form.getGradeReqSign() << ", gradeReqExec:" << form.getGradeReqExec();
	return os;
}
