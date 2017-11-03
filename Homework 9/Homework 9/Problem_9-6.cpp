#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using std::string;
using std::endl;

std::ifstream fileIn;
std::ofstream fileOut;

const string fileIn_name = "barometric.dat";
const string fileOut_name = "differences.dat";

float yearly_min = -1;	//The minimum and maximum values for each line
float yearly_max = -1;	//They are initialized to -1 so that they are garunteed to be updated to the first value

						
//Converts 'data' to a float
float toNumber(string data)
{
	float ret;
	std::stringstream convert;
	convert << data;
	convert >> ret;
	return ret;
}

//Converts 'data' to a string
string toString(float data)
{
	string ret;
	std::stringstream convert;
	convert << data;
	convert >> ret;
	return ret;
}

//Returns the minimum, maximum, and the difference between them, formatted.
string formatOutput(float min, float max)
{
	return "Min: " + toString(min) + " Max: " + toString(max) + " Diff: " + toString(max - min) + "\n";
}

//Compares 'value' against 'min' and 'max', replacing 'min' with 'value' if min < value, and replacing 'max' with 'value' if max < value.  If 'min' or 'max' is -1, they will be set to 'value'
void processMinMax(float value, float & min, float & max)
{
	//Check to see if 'value' is less than the minimum
	if (min == -1 || min > value)
	{
		min = value;
	}

	//Check to see if 'value' is greater than the maximum
	if (max == -1 || max < value)
	{
		max = value;
	}
}

//Process each line in the file, extracting data from it and processing min/max
void processLine()
{
	string line;
	std::getline(fileIn, line);

	if (line.size() == 0) return;	//Processing an empty line is useless

	string entry;
	float value;

	float min = -1;	//The minimum and maximum values for each line
	float max = -1;	//They are initialized to -1 so that they are garunteed to be updated to the first value

	//Run through each character in 'line', appending them to 'entry'.  Every time a space is encountered, the value in 'entry' is converted to a number, and compared against the min and max
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] == ' ')		//If we've reached the end of a value
		{
			processMinMax(toNumber(entry), min, max);
			entry = "";	//Reset entry for the next loop
		}
		else
		{
			entry.push_back(line[i]);
		}
	}

	if(entry.size() > 0) processMinMax(toNumber(entry), min, max);	//Process the remaining data, if it exists

	//Write the data to a file
	fileOut << formatOutput(min, max);

	//Compare the min and max to yearly records
	processMinMax(min, yearly_min, yearly_max);
	processMinMax(max, yearly_min, yearly_max);
}


int main()
{
	fileIn.open(fileIn_name);
	fileOut.open(fileOut_name);

	do
	{
		processLine();
	} while (!fileIn.eof());


	fileIn.close();
	fileOut.close();

	std::cout << "Yearly stats:" << endl;
	std::cout << formatOutput(yearly_min, yearly_max);
	std::cin.get();	//Hold the window;

	return 0;
}