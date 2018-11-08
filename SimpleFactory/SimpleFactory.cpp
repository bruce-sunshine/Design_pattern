#include <iostream>
#include <string>
using namespace std;

class Operation
{
    private:
    double _numberA = 0;
    double _numberB = 0;

    public:
    void set_NumberA(double NumberA)
    {
        _numberA = NumberA;
    }
    double get_NumberA() const
    {
        return _numberA;
    }

    void set_NumberB(double NumberB)
    {
        _numberB = NumberB;
    }
    double get_NumberB() const
    {
        return _numberB;
    }

    virtual double GetResult()
    {
        return 0;
    }
};

//add sub mul div
class OperationAdd : public Operation
{
    public:
    double GetResult()
    {
        return get_NumberA() + get_NumberB();
    }
};

class OperationSub : public Operation
{
    public:
    double GetResult()
    {
        return get_NumberA() - get_NumberB();
    }
};

class OperationMul : public Operation
{
    public:
    double GetResult()
    {
        return get_NumberA() * get_NumberB();
    }
};

class OperationDiv : public Operation
{
    public:
    double GetResult()
    {
        double result = 0;
        if(get_NumberB() == 0)
        {
            cout << "除数不能为0" << endl;
            exit(-1);
        }
        return get_NumberA() / get_NumberB();
    }
};

class OperationFactory
{
    public:
    static Operation* createOperate(char operate)
    {
        Operation* oper = NULL;
        switch(operate)
        {
            case '+':
                oper = new OperationAdd();
                break;
            case '-':
                oper = new OperationSub();
                break;
            case '*':
                oper = new OperationMul();
                break;
            case '/':
                oper = new OperationDiv();
                break;    
        }
        return oper;
    }
};

int main(int argc, char** argv)
{
    char ch = '/';
    Operation* oper = OperationFactory::createOperate(ch);
    oper->set_NumberA(1.2);
    oper->set_NumberB(2);
    double result = oper->GetResult();
    std::cout << "result = " << result << std::endl;
    delete(oper);
    return 1; 
}