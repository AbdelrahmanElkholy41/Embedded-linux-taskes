#include <iostream>
#include <string>

class BackTrace
{
    std::string name;
public:
    BackTrace(const std::string& funcName) : name(funcName)
    {
        std::cout << "Enter to [" << name << "]" << std::endl;
    }

    ~BackTrace()
    {
        std::cout << "Exit From [" << name << "]" << std::endl;
    }
};

#define BACKTRACE BackTrace trace(__PRETTY_FUNCTION__)

void fun1();
void fun2();
void fun3();

void fun1()
{
    BACKTRACE;
    fun2();
}

void fun2()
{
    BACKTRACE;
    fun3();
}

void fun3()
{
    BACKTRACE;
}

int main()
{
    BACKTRACE;
    fun1();

    return 0;
}
