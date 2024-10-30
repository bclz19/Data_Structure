#include <iostream>
#include <stack>
#include <vector>
#include <string.h>
#include <math.h>
int isp(char c)
{
    switch (c)
    {
    case ';':
        return 0;
        break;
    case '(':
        return 1;
        break;
    case '*':
        return 5;
        break;
    case '/':
        return 5;
        break;
    case '+':
        return 3;
        break;
    case '-':
        return 3;
        break;
    case ')':
        return 8;
        break;
    case '^':
        return 6;
    default:
        return -1;
        break;
    }
}
int icp(char c)
{
    switch (c)
    {
    case ';':
        return 0;
        break;
    case '(':
        return 8;
        break;
    case '*':
        return 4;
        break;
    case '/':
        return 4;
        break;
    case '+':
        return 2;
        break;
    case '-':
        return 2;
        break;
    case ')':
        return 1;
        break;
    case '^':
        return 7;
    default:
        return -1;
        break;
    }
}
using namespace std;
int main()
{
    char s[500];
    cin >> s;
    int len = strlen(s);
    s[len++] = ';';
    stack<char> op;
    op.push(';');
    vector<char> s2;
    int index = 0;
    while (1)
    {
        if (s[index] >= '0' && s[index] <= '9')
        {
            s2.push_back(s[index++]);
        }
        else
        {
            if (icp(s[index]) > isp(op.top()))
            {
                op.push(s[index++]);
            }
            else if (icp(s[index]) < isp(op.top()))
            {
                s2.push_back(op.top());
                op.pop();
            }
            else
            {
                if (op.top() == '(')
                {
                    index++;
                }
                else
                    break;
                op.pop();
            }
        }
    }
    for (int i = 0; i < s2.size(); i++)
    {
        cout << s2[i] << ' ';
    }
    cout << endl;
    vector<int> print;
    index = 0;
    while (1)
    {
        if (s2[index] >= '0' && s2[index] <= '9')
        {
            print.push_back(s2[index] - '0');
            index++;
        }
        else
        {
            int print_len = print.size();
            int temp1 = print[print_len - 2], temp2 = print[print_len - 1];
            print.resize(print_len - 2);
            if (s2[index] == '+')
                print.push_back(temp1 + temp2);
            else if (s2[index] == '-')
                print.push_back(temp1 - temp2);
            else if (s2[index] == '*')
                print.push_back(temp1 * temp2);
            else if (s2[index] == '/')
                print.push_back(temp1 / temp2);
            else
                print.push_back(pow(temp1, temp2));
            index++;
            for (int i = 0; i < print.size(); i++)
            {
                cout << print[i] << ' ';
            }
            for (int i = index; i < s2.size(); i++)
            {
                cout << s2[i] << ' ';
            }
            cout << endl;
        }
        if (index == s2.size())
            break;
    }
    return 0;
}