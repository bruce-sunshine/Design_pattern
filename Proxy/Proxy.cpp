#include <iostream>
#include <string>
using namespace std;

class Girl
{
public:
    Girl(string name):_name(name){}
    string GetName()
    {
        return _name;
    }
    void SetName(string str)
    {
        _name = str;
    }
private:
    string _name;
};

class GiveGift
{
public:
    virtual void GiveDolls() = 0;
    virtual void GiveFlowers() = 0;
    virtual void GiveChocolate() = 0;
};

class Persuit: public GiveGift
{
public:
    Persuit(Girl mm):_mm(mm){}

    virtual void GiveDolls()
    {
        cout << "送" << _mm.GetName() << "玩具!" << endl;
    }

    virtual void GiveFlowers()
    {
        cout << "送" << _mm.GetName() << "花!" << endl;
    }

    virtual void GiveChocolate()
    {
        cout << "送" << _mm.GetName() << "巧克力!" << endl;
    }

private:
    Girl _mm;
};

class Proxy: public GiveGift
{
public:
    Proxy(Girl mm)
    {
        _persuit = new Persuit(mm);
    }

    virtual ~Proxy()
    {
        if(_persuit != NULL)
        {
            delete _persuit;
            _persuit = NULL;
        }
    }

    virtual void GiveDolls()
    {
        _persuit->GiveDolls();
    }

        virtual void GiveFlowers()
    {
        _persuit->GiveFlowers();
    }

        virtual void GiveChocolate()
    {
        _persuit->GiveChocolate();
    }

private:
    Persuit* _persuit;
};


int main()
{
    Girl mm("姝玉妹妹");
    Proxy pro(mm);
    pro.GiveDolls();
    pro.GiveFlowers();
    pro.GiveChocolate();

    return 0;
}