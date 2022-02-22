#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
void print(vector<string>);
int main()
{
    //创建一个源数据string
    string src;
    cin >> src;
    //判断是否为符号
    int* isNum = new int[src.size()]();
    int n = 0;
    int chs = 0;
    for (char ch : src)
    {
        if (isdigit(ch))
            isNum[n] = 1;
        else if (ch == '.')
            isNum[n] = 1;
        else {
            isNum[n] = 0;
            chs++;
        }
        n++;
    }
    //组合
    vector<string> formulate(2 * chs + 1);
    int a = 0;
    string temp = "";
    for (int i = 0; i < src.size(); i++)
    {
        if (isNum[i] == 1)
            temp += src[i];
        else
        {
            formulate[a] = temp;
            temp = ""; a += 2;
        }
    }
    formulate[a] = temp;
    a = 1;
    for (int i = 0; i < src.size(); i++)
    {
        if (isNum[i] == 0)
        {
            formulate[a] = src[i];
            a += 2;
        }
    }
    //计算
    while (formulate.size()!=1)
    {
        n = 0;
        vector<string>::iterator it = formulate.begin();
        for (it;it!=formulate.end();)
        {
            double temp = 0;
            if (*it == "*")
                temp = stod(formulate[n - 1]) * stod(formulate[n + 1]);
            else if (*it == "/")
                temp = stod(formulate[n - 1]) / stod(formulate[n + 1]);
            else {
                ++it; n++; continue;
            }
            formulate[n - 1] = to_string(temp);
            formulate.erase(it,it+2);
            it = formulate.begin();
            n = 0;
        }
        n = 0; it = formulate.begin();
        for (it; it != formulate.end();)
        {
            double temp = 0;
            if (*it == "+")
                temp = stod(formulate[n - 1]) + stod(formulate[n + 1]);
            else if (*it == "-")
                temp = stod(formulate[n - 1]) - stod(formulate[n + 1]);
            else {
                ++it; n++; continue;
            }
            formulate[n - 1] = to_string(temp);
            formulate.erase(it, it + 2);
            it = formulate.begin();
            n = 0;
        }
    }
    cout << endl;
    print(formulate);
    return 0;
}

void print(vector<string> n)
{
    for (string i : n)
        cout << i << " ";
}