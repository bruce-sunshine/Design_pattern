#include <iostream>
#include <string>
using namespace std;

class TestPaper
{
public:
    void TestQuestion1()
    {
        cout << "试题一" << endl;
        cout << "答案是" << Answer1() << endl;
    }
    virtual string Answer1()
    {
        return "";
    }

    void TestQuestion2()
    {
        cout << "试题二" << endl;
        cout << "答案是" << Answer2() << endl;
    }
    virtual string Answer2()
    {
        return "";
    }

    void TestQuestion3()
    {
        cout << "试题三" << endl;
        cout << "答案是" << Answer3() << endl;
    }
    virtual string Answer3()
    {
        return "";
    }

};

class TestPaperA: public TestPaper
{
    string Answer1()
    {
        return "b";
    }

    string Answer2()
    {
        return "c";
    }

    string Answer3()
    {
        return "d";
    }

};


class TestPaperB: public TestPaper
{
    string Answer1()
    {
        return "a";
    }

    string Answer2()
    {
        return "b";
    }

    string Answer3()
    {
        return "c";
    }

};

int main()
{

    TestPaper* studentA = new TestPaperA();
    studentA->TestQuestion1();
    studentA->TestQuestion2();
    studentA->TestQuestion3();

    TestPaper* studentB = new TestPaperB();
    studentB->TestQuestion1();
    studentB->TestQuestion2();
    studentB->TestQuestion3();

    delete studentA;
    delete studentB;
    
    return 1;
}