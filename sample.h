#ifndef SAMPLE_H
#define SAMPLE_H

#include <iostream>
#include <string>

class Sample
{
private:
	int id;
	std::string date;
	int *numbers;

public:
	Sample(int id, std::string date, int* numbers);
	int getId(){return id;}
	std::string getDate(){return date;}
	int* getNumbers(){return numbers;}

	friend std::ostream & operator<< (std::ostream &wyjscie, Sample &s);
};

#endif
