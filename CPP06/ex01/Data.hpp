#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data
{
public:
	Data();
	Data(const Data& src);
	~Data();
	Data& operator =(const Data& src);

	char getChar() const;
	int getInt() const;
	float getFloat() const;
	double getDouble() const;

private:
	char c;
	int i;
	float f;
	double d;
};

std::ostream& operator <<(std::ostream &out, const Data& d);

#endif
