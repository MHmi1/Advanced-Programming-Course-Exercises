
#include <string>
#include <vector>
#include <array>
#include <cstdlib>
#include <random>
#include <ctime>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <stdio.h>

#include "cal.cpp"

using namespace std;
vector<string> history_vec; //vector for store answers history
void history() //print answer(s)
{
    cout << " >history " << endl;
    for (int v = 0; v < history_vec.size(); v++)
    {
        cout << " > " << history_vec[v] << endl;
    }
}

void calculate(string opr1,string opr2,size_t oprator)//Build suitable objects and call functions that fit any operator 
{
    if (opr1.size() == 1 && opr2.size() == 1) //creat object
    {
        one op1, op2;
        op1.set_op(opr1);
        op2.set_op(opr2);
    }
    if (opr1.size() == 2 && opr2.size() == 2) //creat object
    {
        two op1, op2;
        op1.set_op(opr1);
        op2.set_op(opr2);
    }
    if (opr1.size() == 3 && opr2.size() == 3)  //creat object
    {
        three op1, op2;
        op1.set_op(opr1);
        op2.set_op(opr2);
    }
    if (opr1.size() == 4 && opr2.size() == 4)  //creat object
    {
        four op1, op2;
        op1.set_op(opr1);
        op2.set_op(opr2);
    }
    if (opr1.size() == 5 && opr2.size() == 5)  //creat object
    {
        five op1, op2;
        op1.set_op(opr1);
        op2.set_op(opr2);
    }
    if (opr1.size() == 6 && opr2.size() == 6)  //creat object
    {
        six op1, op2;
        op1.set_op(opr1);
        op2.set_op(opr2);
    }
    if (opr1.size() == 7 && opr2.size() == 7)  //creat object
    {
        seven op1, op2;
        op1.set_op(opr1);
        op2.set_op(opr2);
    }
    if (opr1.size() == 8 && opr2.size() == 8)  //creat object
    { 
        eight op1, op2;
        op1.set_op(opr1);
        op2.set_op(opr2);
    }
    if (opr1.size() == 9 && opr2.size() == 9)  //creat object
    {
        nine op1, op2;
        op1.set_op(opr1);
        op2.set_op(opr2);
    }
    if (opr1.size() == 10 && opr2.size() == 10)  //creat object
    {
        ten op1, op2;
        op1.set_op(opr1);
        op2.set_op(opr2);
    }

    if (oprator == 1) // operator + function call
    {
        cout << sum(opr1, opr2) << endl;
        history_vec.push_back(sum(opr1, opr2));
    }

    if (oprator == 2) //operator - function call
    {
        cout.flush();
        cout<< _minus(opr1, opr2) <<endl;
        history_vec.push_back(_minus(opr1, opr2));
    }

    if (oprator == 3) //operator * function call
    {
        if (opr1.size() > opr2.size())
        {
            cout << mul(opr1, opr2, opr1.size()) << endl;
            history_vec.push_back(mul(opr1, opr2, opr1.size()));
        }
        else
        {
            cout << mul(opr2, opr1, opr2.size()) << endl;
            history_vec.push_back(mul(opr2, opr1, opr2.size()));
        }
    }

    if (oprator == 4) //operator / function call
    {
        cout << div(opr1, opr2) << endl;
        history_vec.push_back(div(opr1, opr2));
    }

    if (oprator == 5)  //operator < function call
    {
        try
        {
            cout << compare(opr1, opr2) << endl;
            history_vec.push_back(compare(opr1, opr2));
            if (compare(opr1, opr2) == "")
            {
                history_vec.push_back("Null");
                cout << " NULL" << endl;
            }
        }
        catch (invalid_argument &e)
        {
            std::cerr <<"error ! "<< e.what() << '\n';
        }
    }

    if (oprator == 6)  //operator && function call
    {
        cout << boolalpha << _and(opr1, opr2) << endl;
        if (_and(opr1, opr2) == 1)
            history_vec.push_back("True");
        else
            history_vec.push_back("False");
    }

    if (oprator == 7)  //operator || function call
    {
        cout << boolalpha << _or(opr1, opr2) << endl;
        if (_or(opr1, opr2) == 1)
            history_vec.push_back("True");
        else
            history_vec.push_back("False");
    }

    if (oprator == 8)  //operator != function call
    {
        try
        {
             cout << unequal(opr1, opr2) << endl;
        }
        catch(invalid_argument &e)
        {
            std::cerr <<"error ! "<< e.what() << '\n';
        }
        
       
        //******************** cout << boolalpha << _or(opr1, opr2) << endl;
    }

    if (oprator == 9) //operator += function call
    {
        cout << plus_equal(opr1, opr2) << endl;
        history_vec.push_back(plus_equal(opr1, opr2));
    }

    if (oprator == 10) //operator -= function call
    {
        try
        {
            if (minus_equal(opr1, opr2) == "")
            {
                cout << "NULL " << endl;
                history_vec.push_back("NULL");
            }
            else
                cout << minus_equal(opr1, opr2) << endl;
            history_vec.push_back(minus_equal(opr1, opr2));
        }
        catch (invalid_argument &e)
        {
            cout << e.what() << endl;
        }
    }
}

string subs(string s, size_t begin, size_t end) // Function for separating a string based on its upper and lower bounds 
{
    string temp;
    if (end > s.size() || begin > end)
    {
        return "false";
    }
    for (int i = begin; i <= end; i++)
    {
        temp += s[i];
    }
    return temp;
}

void getcmnd(string str) // Analyze the entered string and detect its operator for next calculations
{
    size_t mode = 0;
    string op1;
    string op2;
    for (int i = 0; i < str.size(); i++)
    {

        if (str[i] == '+') // Analyze the entered string and del white spaces 
        {
            mode = 1;
            op1 = str.substr(0, i);
            op1.erase(std::remove_if(op1.begin(), op1.end(), ::isspace), op1.end());
            op2 = str.substr(i + 1, subs(str, i + 1, str.size()).size());
            op2.erase(std::remove_if(op2.begin(), op2.end(), ::isspace), op2.end());
            if (op1.size() > 10 || op2.size() > 10) //exceptions handling 
            {
                throw invalid_argument("max of each operand length in 10 char !!");
            }
        }
        else if (str[i] == '-') // Analyze the entered string and del white spaces 
        {
            mode = 2;
            op1 = str.substr(0, i);
            op1.erase(std::remove_if(op1.begin(), op1.end(), ::isspace), op1.end());
            op2 = str.substr(i + 1, subs(str, i + 1, str.size()).size());
            op2.erase(std::remove_if(op2.begin(), op2.end(), ::isspace), op2.end());
            if (op1.size() > 10 || op2.size() > 10) //exceptions handling 
            {
                throw invalid_argument("max of each operand length in 10 char !!");
            }
        }
        else if (str[i] == '*') // Analyze the entered string and del white spaces 
        {
            mode = 3;
            op1 = str.substr(0, i);
            op1.erase(std::remove_if(op1.begin(), op1.end(), ::isspace), op1.end());
            op2 = str.substr(i + 1, subs(str, i + 1, str.size()).size());
            op2.erase(std::remove_if(op2.begin(), op2.end(), ::isspace), op2.end());
            if (op1.size() > 10 || op2.size() > 10) //exceptions handling 
            {
                throw invalid_argument("max of each operand length in 10 char !!");
            }
        }
        else if (str[i] == '/') // Analyze the entered string and del white spaces 
        {
            mode = 4;
            op1 = str.substr(0, i);
            op1.erase(std::remove_if(op1.begin(), op1.end(), ::isspace), op1.end());
            op2 = str.substr(i + 1, subs(str, i + 1, str.size()).size());
            op2.erase(std::remove_if(op2.begin(), op2.end(), ::isspace), op2.end());
            if (op1.size() > 10 || op2.size() > 10 || op2.size() < 1) //exceptions handling 
            {
                throw invalid_argument("max of each operand length in 10 char !!");
            }
        }
        else if (str[i] == '<') // Analyze the entered string and del white spaces 
        {
            mode = 5;
            op1 = str.substr(0, i);
            op1.erase(std::remove_if(op1.begin(), op1.end(), ::isspace), op1.end());
            op2 = str.substr(i + 1, subs(str, i + 1, str.size()).size());
            op2.erase(std::remove_if(op2.begin(), op2.end(), ::isspace), op2.end());
            if (op1.size() > 10 || op2.size() > 10 || op2.size() != 1) //exceptions handling 
            {
                throw invalid_argument("max of each operand length in 10 char !!");
            }
        }

        //******************************************************************************************

        if (str[i] == '&' && str[i + 1] == '&') // Analyze the entered string and del white spaces 
        {
            mode = 6;
            op1 = str.substr(0, i);
            op1.erase(std::remove_if(op1.begin(), op1.end(), ::isspace), op1.end());
            op2 = str.substr(i + 2, subs(str, i + 2, str.size()).size());
            op2.erase(std::remove_if(op2.begin(), op2.end(), ::isspace), op2.end());
            if (op1.size() > 10 || op2.size() > 10) //exceptions handling 
            {
                throw invalid_argument("max of each operand length is 10 char !!");
            }
        }
        else if (str[i] == '|' && str[i + 1] == '|') // Analyze the entered string and del white spaces 
        {
            mode = 7;
            op1 = str.substr(0, i);
            op1.erase(std::remove_if(op1.begin(), op1.end(), ::isspace), op1.end());
            op2 = str.substr(i + 2, subs(str, i + 2, str.size()).size());
            op2.erase(std::remove_if(op2.begin(), op2.end(), ::isspace), op2.end());
            if (op1.size() > 10 || op2.size() > 10) //exceptions handling 
            {
                throw invalid_argument("max of each operand length is 10 char !!");
            }
        }
        else if (str[i] == '!' && str[i + 1] == '=') // Analyze the entered string and del white spaces 
        {
            mode = 8;
            op1 = str.substr(0, i);
            op1.erase(std::remove_if(op1.begin(), op1.end(), ::isspace), op1.end());
            op2 = str.substr(i + 2, subs(str, i + 2, str.size()).size());
            op2.erase(std::remove_if(op2.begin(), op2.end(), ::isspace), op2.end());
            if (op1.size() > 10 || op2.size() > 10 || op2.size() != 1) //exceptions handling 
            {
                throw invalid_argument("max of each operand length is 10 char !!");
            }
        }
        else if (str[i] == '+' && str[i + 1] == '=') // Analyze the entered string and del white spaces 
        {
            mode = 9;
            op1 = str.substr(0, i);
            op1.erase(std::remove_if(op1.begin(), op1.end(), ::isspace), op1.end());
            op2 = str.substr(i + 2, subs(str, i + 2, str.size()).size());
            op2.erase(std::remove_if(op2.begin(), op2.end(), ::isspace), op2.end());
            if (op1.size() > 10 || op2.size() > 10) //exceptions handling 
            {
                throw invalid_argument("max of each operand length  is 10 char !!");
            }
        }
        else if (str[i] == '-' && str[i + 1] == '=') // Analyze the entered string and del white spaces 
        {
            mode = 10;
            op1 = str.substr(0, i);
            op1.erase(std::remove_if(op1.begin(), op1.end(), ::isspace), op1.end());
            op2 = str.substr(i + 2, subs(str, i + 2, str.size()).size());
            op2.erase(std::remove_if(op2.begin(), op2.end(), ::isspace), op2.end());
            if (op1.size() > 10 || op2.size() > 10) //exceptions handling 
            {
                throw invalid_argument("max of each operand length is 10 char !!");
            }
        }
    }

    if (str == ">history") //function history call
    {
        history();
    }

    if (str == "exit") //Exit command  
    {
        exit(0);
    }

    calculate(op1, op2, mode); // send two objects of operand(op1,op2) and operator (mode)
}

int main()
{
    while (1)
    {
        string str;
        cout << "welcome , enter your statement : " << endl;
        getline(cin, str, '\n');
        //cin >> setw(50) >> str;
        try
        {
            getcmnd(str);
        }
        catch (invalid_argument &e)
        {
            e.what();
            cerr << "error in length limit : re enter your statement " << endl;
            getline(cin, str, '\n');
            getcmnd(str);
        }
    }

    return 0;
}