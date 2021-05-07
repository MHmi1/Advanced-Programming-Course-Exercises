#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <cstring>
#include "cal.hpp"

typedef unsigned int ui;
using namespace std;
//*******************************************
class mes : public std::logic_error  //exception handling 
{
public:
    mes() : logic_error("your operand is incorrect !!"){};
};

//  ****************************************
template <class L, class R>   // Add two strings and sort alphabetically by ASCII code + operator
string sum(L left, R right)
{
    string temp = left + right;
    sort(temp.begin(), temp.end());

    return temp;
}

//  ****************************************
template <class L, class R>  //Implementation  of - operator
string _minus(L left, R right)
{
    string leftop = left, rightop = right;
    string temp = "";
    string temp1 = "";

    if (leftop.size() > rightop.size())
    {
        for (int i = 0; i <= rightop.size(); i++)
        {
            temp = leftop[i];
        }
        cout << " -> " << (leftop.size() - rightop.size()) << endl;
        return temp;
    }
    else if (leftop.size() < rightop.size())
    {
        for (int k = 0; k <= rightop.size(); k++)
        {
            temp1 = leftop[k];
        }
        cout << " -> " << (rightop.size() - leftop.size()) << endl;
        return temp1;
    }

    return temp;
}

//  ****************************************
template <class L, class R> //Implementation  of * operator
string mul(L left, R right, size_t len)
{
    string temp = "";
    for (int i = 0; i < len; i++)
    {
        temp += right;
    }
    return temp;
}

//  ****************************************
template <class L, class R> //Implementation  of / operator
string div(L left, R right)
{
    string leftop = left, rightop = right;
    string temp = "";

    for (int k = 0; k < leftop.size(); k++)
    {
        temp += tolower(leftop[k]);
    }

    for (int i = 0; i < leftop.size(); i++)
    {
        for (int j = 0; j < rightop.size(); j++)
        {
            if (temp[i] == rightop[j])
            {
                leftop[i] = temp[i];
            }
        }
    }

    return leftop;
}

//  ****************************************
template <class L, class R> //Implementation  of < operator
string compare(L left, R right)
{
    string leftop = left, rightop = right;
    if (rightop.size() != 1)
    {
        throw invalid_argument("The second operand must be single character !!");
    }
    string temp = "";
    for (int k = 0; k < leftop.size(); k++)
    {
        if (leftop[k] < rightop[0])
        {
            temp += leftop[k];
        }
    }
    return temp;
}

//  ****************************************
template <class L, class R> //Implementation  of && operator
bool _and(L left, R right)
{
    string leftop = left;
    string rightop = right;
    bool b1 = false, b2 = false;
    for (int i = 0; i < leftop.size(); i++)
    {
        if (leftop[i] == 'a' || leftop[i] == 'e' || leftop[i] == 'i' || leftop[i] == 'o' || leftop[i] == 'u' || leftop[i] == 'A' || leftop[i] == 'E' || leftop[i] == 'I' || leftop[i] == 'O' || leftop[i] == 'U')
            b1 = true;
        if (rightop[i] == 'a' || rightop[i] == 'e' || rightop[i] == 'i' || rightop[i] == 'o' || rightop[i] == 'u' || rightop[i] == 'A' || rightop[i] == 'E' || rightop[i] == 'I' || rightop[i] == 'O' || rightop[i] == 'U')
            b2 = true;
    }
    return (b1 && b2);
}

//  ****************************************
template <class L, class R> //Implementation  of || operator
bool _or(L left, R right)
{

    string leftop = left;
    string rightop = right;
    bool b1 = false, b2 = false;
    for (int i = 0; i < leftop.size(); i++)
    {
        if (leftop[i] == 'a' || leftop[i] == 'e' || leftop[i] == 'i' || leftop[i] == 'o' || leftop[i] == 'u' || leftop[i] == 'A' || leftop[i] == 'E' || leftop[i] == 'I' || leftop[i] == 'O' || leftop[i] == 'U')
            b1 = true;
        if (rightop[i] == 'a' || rightop[i] == 'e' || rightop[i] == 'i' || rightop[i] == 'o' || rightop[i] == 'u' || rightop[i] == 'A' || rightop[i] == 'E' || rightop[i] == 'I' || rightop[i] == 'O' || rightop[i] == 'U')
            b2 = true;
    }
    return (b1 || b2);
}

//  ****************************************
template <class L, class R> //Implementation  of != operator
string unequal(L left, R right)
{
    string leftop = left;
    string rightop = right;
    ui index;
    bool find = 0;
 
 if (rightop.size() != 1)
    {
        throw invalid_argument("The second operand must be single character !!");
    }

    for (int i = 0; i < leftop.size(); i++)
    {
        if (leftop[i] == rightop[0])
        {
            find = true;
            index = i;
            break;
        }
    }

    if (find)
    {
        string str1 = "", str2 = "";

        for (int i = 0; i < leftop.size(); i++)
        {
            if (i < index)
            {
                str1 += leftop[i];
            }
            if (i > index)
            {
                str2 += leftop[i];
            }
        }

        leftop = "";
        leftop += str2;
        leftop += rightop;
        leftop += str1;
        return leftop;
    }
    else
    {
        return "The first operand cannot be rotated !!";
    }
}

//  ****************************************
template <class L, class R> //Implementation  of += operator
string plus_equal(L left, R right)
{
    string leftop = left;
    string rightop = right;
    string temp = "";
    for (int j = 0; j < leftop.size(); j++)
    {
        temp += leftop[j];
        temp += rightop[0];
    }
    return temp;
}

//  ****************************************
template <class L, class R> //Implementation  of -= operator
string minus_equal(L left, R right)
{
    string leftop = left;
    string rightop = right;
    string temp = "";
    bool flag;

    if (rightop.size() <= leftop.size())
    {
        for (int i = 0; i < leftop.size(); i++)
        {
            flag = false;
            for (int j = 0; j < rightop.size(); j++)
            {
                if (leftop[i] == rightop[j])
                {
                    flag = true;
                }
            }

            if (!flag)
            {
                temp += leftop[i];
            }
        }
    }
    else
    {
        cerr << "error in entered operand !" << endl;
        throw invalid_argument("The second operand must be less or equal than the first operand !!");
    }

    temp.erase(std::remove_if(temp.begin(), temp.end(), ::isspace), temp.end()); //del white spaces
    return temp;
}
