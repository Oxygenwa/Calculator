#pragma once
#include "baseCalc.h"
#include <cctype>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
class normalCalc :
    public baseCalc
{
private:
    string m_s;
    vector<string> m_temp;
    vector<string> m_opt;

    void small_cal(int index);
    void middle_cal();
    void scan();
    void printANS();
    void error();
    void kh_cal();
public:
    normalCalc();
    normalCalc(baseCalc& b);
    ~normalCalc();

    void cal(string& s);
    void options(string&);

};

