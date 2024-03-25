#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential Pardon", 25, 5), _target("") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : Form("Presidential Pardon", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : Form(src), _target(src._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm& src)
{
	if (this != &src)
	{
		_target = src._target;
	}
	return *this;
}

void PresidentialPardonForm::formEffect() const
{
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
