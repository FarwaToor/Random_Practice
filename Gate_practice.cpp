// ConsoleApplication119.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class logic_gates 
{
protected:
    int n1, n2, n3, n4;
public:
    void setter() 
    {
        cout << "     G1      " << endl;
        cout << " Enter 1st input : ";
        cin >> n1;
        cout << " Enter 2nd input : ";
        cin >> n2;
        cout << "     G2      " << endl;
        cout << " Enter 3rd input : ";
        cin >> n3;
        cout << " Enter 4th input : ";
        cin >> n4;
    }
};
class binary :public logic_gates
{
protected:
public:
    void setter()
    {
        logic_gates::setter();

    }
};
class CLASS_AND :public binary
{
protected:
    int G1_out, G2_out;
public:
    void setter() 
    {
        binary::setter();
    }
    void AND1() 
    {
        if (n1 == 1 && n2 == 1)
            G1_out = 1;
        else
            G1_out = 0;

        cout << " G1--> " << G1_out;
    }
    void AND2()
    {
        if (n3 == 1 && n4 == 1)
            G2_out = 1;
        else
            G2_out = 0;

        cout << " G2--> " << G2_out;
    }

    int get_G1_in() 
    {
        return G1_out;
    }

    int get_G2_in()
    {
        return G2_out;
    }

};
class CLASS_OR:public binary
{
protected:
    int G3_out;
    CLASS_AND a;
public:
    void OR() 
    {
        if (a.get_G1_in() == 0 && a.get_G2_in() == 0)
            G3_out = 0;
        else
            G3_out = 1;
        cout << " G3--> " << G3_out;
    }

    void apply()
    {
        a.setter();
        a.AND1();
        a.AND2();
        OR();

    }
    int get_G3_in() { return G3_out; }
};
class unary:public logic_gates{};
class CLASS_NOT:public unary
{
protected:
    CLASS_OR o;
    int G4_out;
public:

    void NOT()
    {
        if (o.get_G3_in() == 1)
            G4_out = 0;
        else if (o.get_G3_in() == 0)
            G4_out = 1;

        cout << " G4--> " << G4_out << endl;
    }

    void calling() 
    {
        o.apply();
        NOT();
    }

};
class connection 
{
private:
    binary b;
    CLASS_NOT n;
public:
    connection(){}

    void call() 
    {
       
        n.calling();
    }




};
int main()
{
    connection c;
    c.call();
}
