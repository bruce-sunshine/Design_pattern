#include <iostream>
#include <string>
using namespace std;

class LeiFeng
{
public:
    void Sweep()
    {
        cout << "扫地" << endl;
    }
    void Wash()
    {
        cout << "洗衣" << endl;
    }
    void Cook()
    {
        cout << "做饭" << endl;
    }
};


class Undergraduate : public LeiFeng
{
    
};

class Volunteer : public LeiFeng
{
    
};

class IFactory
{
public:
    LeiFeng* CreateLeiFeng()
    {
        return new LeiFeng();
    }
};


class UndergraduateFactory : public IFactory
{
public:
    LeiFeng* CreateLeiFeng()
    {   
        return new Undergraduate();
    }
};


class VolunteerFactory : public IFactory
{
public:
    LeiFeng* CreateLeiFeng()
    {   
        return new Volunteer();
    }
};

int main()
{
    IFactory* factory = new UndergraduateFactory();
    LeiFeng* student = factory->CreateLeiFeng();

    student->Wash();
    student->Sweep();
    student->Cook();

    delete student;
    delete factory;

    return 0;
}


