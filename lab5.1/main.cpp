#include <iostream>
using namespace std;


class Except
{
public:
    virtual void PrintInfo() =0;
};

class Except1 : public Except
{
public:
    virtual void PrintInfo() {cout << "BLAD 1" << endl;}
};

class Except2 : public Except
{
public:
    virtual void PrintInfo() 
    {
        l = __LINE__;
        cout << "wyjatek w lini numer: " << l << endl;
    }
private:
    int l;
};

void fun2()
{
    throw 1;
};

void fun()
{
    //throw 3.14;
    //throw Except2();
    //throw Except1();
    //fun2();
    //throw "To jest wyjatek!";
};

int main()
{
    cout << "start" << endl;

    try 
    {
        fun();
    }
    catch(char *s)
    {
       cout << s << endl;
    }
    catch(int a)
    {
        cout << "blad numer: " << a << endl;
    }
    catch (Except& e)
    {
    e.PrintInfo();
    }
    catch (...)
    {
        cout << "nieznany blad" << endl;
    }

    return 0;
}