#include "stdafx.h"


#include <stdio.h>
 #include <cstdlib>
 #include <string>
 #include <iostream>

using namespace std;

string intToPolish(int n);
int binary(int n);

int main(int argc, char *argv[])
{
	printf("Hello, World!\n");
	int n = atoi(argv[1]);
	int k = binary(n);
	cout << "n: " << n << endl;
	cout << "k: " << k << " -> " << intToPolish(k) << endl;
	cout << "n*k: " << n * k << " -> " << intToPolish(n*k) << endl;
	cin >> n;
}

string intToPolish(int n)
 {
	const string unity[10] = { "", " jeden", " dwa", " trzy", " cztery", " piec", " szesc", " siedem", " osiem", " dziewiec" };
	const string teens[10] = { "dziesiec", " jedenascie", " dwanascie", " trzynascie", " czternascie", " pietnascie", " szesnascie", " siedemnascie", " osiemnascie", " dziewietnascie" };
	const string dozens[10] = { "", " dziesiec", " dwadziescia", " trzydziesci", " czterdziesci", " piecdziesiat", " szescdziesiat", " siedemdziesiat", " osiemdziesiat", " dziewiecdziesiat" };
	const string hundreds[10] = { "", " sto", " dwiescie", " trzysta", " czterysta", " piecset", " szescset", " siedemset", " osiemset", " dziewiecset" };
	const string x[2] = { "", " tys." };
	
		if (n >= 1000000 || n < 0) return "Zbyt duża n!";
	
		string numeral;
	
		if (n == 0) numeral == "zero";
	
		int ending;
	int row = 0;
	int j = 0;
	
		while (n>0)
		 {
		ending = (n % 10);
		n /= 10;
		
			if ((j == 0) && (n % 100 != 0 || ending != 0)) numeral = x[row] + numeral;
		if ((j == 0) && (n % 10 != 1)) numeral = unity[ending] + numeral;
		if ((j == 0) && (n % 10 == 1))
			 {
			numeral = teens[ending] + numeral;
			n /= 10;
			j += 2;
			continue;
			}
		if (j == 1) numeral = dozens[ending] + numeral;
		if (j == 2)
			 {
			numeral = hundreds[ending] + numeral;
			j = -1;
			row++;
			}
		j++;
		}
	return numeral;
	}

int binary(int n)
 {
	for (int k = 1; ; k++)
		 {
		int result = n * k;
		while (result % 10 <= 1)
			{
			if (result < 10) return k;
			else result /= 10;
			}
		}

}
