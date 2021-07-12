#include "normalCalc.h"
#include <iostream>
using namespace std;
void normalCalc::small_cal(int index)
{
	vector<string>::iterator it = m_temp.begin() + index - 1;
	switch (m_temp[index][0])
	{
	case '+':
		*it = to_string(stod(m_temp[index - 1]) + stod(m_temp[index + 1]));
		m_temp.erase(m_temp.begin() + index, m_temp.begin() + index + 1);
		break;
	case '-':
		*it = to_string(stod(m_temp[index - 1]) - stod(m_temp[index + 1]));
		m_temp.erase(m_temp.begin() + index, m_temp.begin() + index + 1);
		break;
	case '*':
		*it = to_string(stod(m_temp[index - 1]) * stod(m_temp[index + 1]));
		m_temp.erase(m_temp.begin() + index, m_temp.begin() + index + 1);
		break;
	case '/':
		*it = to_string(stod(m_temp[index - 1]) / stod(m_temp[index + 1]));
		m_temp.erase(m_temp.begin() + index, m_temp.begin() + index + 1);
		break;
	}
	
}

void normalCalc::middle_cal()
{
	for (int i = 0; i < m_temp.size(); i++)
	{
		if (m_temp[i] == "*" || m_temp[i] == "/")
		{
			small_cal(i);
			i = 0;
		}
		else if (m_temp[i] == "+" || m_temp[i] == "-")
		{
			small_cal(i);
			i = 0;
		}
		else continue;
	}
	ANS = stod(m_temp[0]);
}

void normalCalc::scan()
{
	string temp = "";
	for (int i = 0; i < m_s.size(); i++)
	{
		if (isdigit(m_s[i]) || m_s[i] == '.')
		{
			temp += m_s[i];
			continue;
		}
		else if (isgraph(m_s[i]))
		{
			m_temp.push_back(temp);
			temp = m_s[i];
			m_temp.push_back(temp);
		}
		else
			break;
	}
}

void normalCalc::printANS()
{
	cout << ANS;
}

normalCalc::normalCalc(baseCalc& b)
{
}

normalCalc::~normalCalc()
{
}

void normalCalc::cal(string& s)
{
	m_s = s;
	scan();
	middle_cal();
	printANS();
}

void normalCalc::options(string&)
{
}
