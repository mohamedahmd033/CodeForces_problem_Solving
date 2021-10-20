#include "FactorialFunctions.h"

vector<int> largeFactorial(int number)
{
	/*This funciton take an int number as magnitude and return its factorial in a vector
	the returned vector contains contains the number digit, for example index 0 contains the digit at ones place,
	while index 1 contains the digit at tens place, etc..

	this function is developed to return large factorial numbers which can't be fitted in int datatype

	*/


	vector<int >result; //The vector that will hold the factorial result
	int tempNumber = 0; //storing the number vairable to the tempNumber variable
	int carry = 0; //variable hold the carry in the multiplication process
	int carryTemp = 0; //variable save the carry variable value during the multiplication process
	bool numberSign = true; // true if number sign is positive, false if negative

	//if number is negative value, then it will make it positive as the calculations depend on that
	if (number < 0)
	{
		number *= -1;
		numberSign = false;
	}

	//return vector with single value equal 1, as 0! = 1
	if (number == 0) 
	{
		result.push_back(0);
		return result;
	}

	//store the number variable digits to the result vector
	//index 0 contains the digit at ones place, while index 1 contains the digit at tens place, etc..
	tempNumber = number;
	while (tempNumber != 0)
	{
		result.push_back(tempNumber % 10); //push the least digit of number variable to the vector result
		tempNumber /= 10; //getting rid of the least digit stored in the vector;
	}

	for (int i = number-1; i > 0; i--)
	{
		
		for (int j = 0; j < result.size(); j++) //multiplaying each digit in i which is the factorial number - n
												// n range is (number-1 to 1)
		{					
			carryTemp = carry; //save carry value to carryTemp
			carry = ((result[j] * i) + carryTemp) / 10; //calculate the carry of multiplicaiton
			result[j] = ((result[j] * i) + carryTemp) % 10; //get the first digit of multiplicaiton
		}

		if (carry != 0) //reaching the end of the loop and still there is carry to be stored 
		{
			while (carry != 0) //storing the carry digits to the result vector
			{

				result.push_back(carry % 10);
				carry /= 10;
			}

		}
	}



	return result;
}


void displayFactorialVector(vector<int> v)
{
	for (int i = v.size() - 1; i >= 0; i--)
	{
		cout << v[i];
	}
}
