#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Operation //here we are declaring a class for our operations.
{
public:

	int Exp; //Our Exponantial number variable is declared.

	int Base; //Our Base number variable for the calculator.

	int Mod; //Modulus number for the exponential caltulation.

	Operation()

	{
		cout << "MODULAR EXPONENTIATION CALCULATOR" << endl;

		cout << "(a^b mod m solver)" << endl;

		cout << endl;

		cout << "Enter Base(a): ";

		cin >> Base;

		cout << "Enter Exponent(b): ";

		cin >> Exp;

		cout << "Enter Modulus(m): ";

		cin >> Mod;

		cout << endl;

		cout << ModExp(Base, Exp, Mod); //Here we recall the ModExp function.

		
	}



	int ExpToStr(int ExpNum)

	{
		int i = 0;

		int BinNum[32]; //Binary number Array is created for us to store the ExpNum into the indexes.

		while (ExpNum > 0) //This while loop 

		{
			BinNum[i] = ExpNum % 2;

			ExpNum = ExpNum / 2;

			i++; //i gets updated every time we go in for the loop and when its repeated i counter gets incremented.

		}

		return ExpNum; //We return the ExpNum.

	}




	int ModExp(int BaseNum, int ExpNum, int Modul)

	{
		int x = 1;

		int power = BaseNum % Modul; //Power gets equal to BaseNum divided by Modul.

		int ConvArr[10]; // We declare an array for the ModularExponantial for our for loop.

		int i = 0;

		while (ExpNum > 0)

		{
			ConvArr[i] = ExpNum % 2;

			ExpNum = ExpNum / 2;

			i++;

		}

		for (int j = 0; j < i ; j++)

		{
			if (ConvArr[j] == 1) //Arrays index is getting updated each time the for loop itaretes.

			{   //we print out the values here.

				cout << "Because b" << j << " is " << ConvArr[j] << " we have x = (" << x << " * " << power << ") and power = " << power << " ^ 2 mod " << Modul << " = " << (power * power) % Modul << endl;

				x = (x * power) % Modul; //We modify the values of x according to our solutions.

			}

			cout << "Because b" << j << " is " << ConvArr[j] << ", we have x = " << x << " and power = " << power << " ^ 2 mod " << Modul << " = " << (power * power) % Modul << endl;

			power = (power * power) % Modul; //And the last modification gets set here.

		}

		cout << endl << "Modular Exponentiation of (" << BaseNum << "^" << ExpNum << ")" << " mod (" << Modul << ") = " << x % Modul << endl;

		return x; //We return the x.

	}




};

int main(void)

{

	Operation Op; //here we decalre an objective for the class.

}