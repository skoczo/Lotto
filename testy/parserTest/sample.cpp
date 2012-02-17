#include "sample.h"

Sample::Sample(int id, std::string date, int* numbers)
{
	this->id = id;
	this->date = date;
	this->numbers = numbers;
}

std::ostream & operator<< (std::ostream &wyjscie, Sample &s)
 {
   wyjscie << s.getId() << " " << s.getDate();

	for (int i = 0; i < 6; i++) {
		wyjscie << " " << s.getNumbers()[i];
	}

	return wyjscie << std::endl;
 }
