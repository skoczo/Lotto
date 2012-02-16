#include "loader.h"

Loader::Loader()
{
	QFile file(Lotto::sampleFile.c_str());
	file.open(QFile::ReadOnly);

	if (file.exists() && file.isReadable())
	{
		QByteArray allFile = file.readAll();
		std::string data = allFile.data();
		for (unsigned int i = 0; i < data.length(); i++)
		{
			if (data[i] == '#' || data[i] == '\n' || data[i] == ' ' || data[i]
					== '\r')
			{
				while (data[i] != '\n')
				{
					i++;
				}
				continue;
			}

			try
			{
				int id = getNumber(i, data);
				std::string date = getData(i, data);
				int *numbers = getNumbers(i, data);
				Sample* s = new Sample(id, date, numbers);
				i--;
				list.push_front(s);

				if (debug)
				{
					std::cout << *s;
				}
			} catch (NumberException &e)
			{
				std::cout << "NumberExceptionError\nLine: " << __LINE__
						<< "\nFile: " << __FILE__ << std::endl;
				throw;
			}

		}
	}
	else
	{
		throw FileError();
	}
}

int Loader::getNumber(unsigned int &i, std::string &data)
{
	std::string tmp = "";

	while (data[i] != ';' && data[i] != '\n' && data[i] != '\r')
	{
		if (data[i] != ' ')
			tmp += data[i];
		i++;
	}

	i++;
	if (tmp.length() > 0)
	{
		int number;
		std::istringstream iss(tmp);
		iss >> number;
		return number;
	}

	throw NumberException();
}

std::string Loader::getData(unsigned int &i, std::string &data)
{
	std::string tmp = "";

	while (data[i] != ';')
	{
		tmp += data[i];
		i++;
	}
	i++;
	return tmp;
}

int* Loader::getNumbers(unsigned int &i, std::string &data)
{
	int *numbers = new int[6];

	for (int j = 0; j < 6; j++)
	{
		numbers[j] = getNumber(i, data);
	}

	return numbers;
}
