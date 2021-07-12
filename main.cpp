#include <iostream>
#include "normalCalc.h"
using namespace std;
void version_message();
void gn_message();
int main()
{
	version_message();
	gn_message();
	int g;
	baseCalc b;
	normalCalc Ca(b);
	while (cin >> g)
	{
		if (g == 1)
		{
			string formulate;
			cout << "enter:";
			cin >> formulate;
			if (formulate == "q" || formulate == "Q")
			{
				gn_message();
				continue;
			}
			else if (formulate[0] == '/')
			{
				Ca.options(formulate);
			}
			else
			{
				Ca.cal(formulate);
			}
			gn_message();
			continue;
		}
	}
}

void version_message()
{
}

void gn_message()
{
}
