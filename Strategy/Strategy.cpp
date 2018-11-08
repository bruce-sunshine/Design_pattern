#include <iostream>
#include <string>
using namespace std;

class CashSuper
{
public:
    virtual double acceptCash(double money)=0;
};

class CashNormal:public CashSuper
{
public:
    double acceptCash(double money)
    {
        return money;
    }
};

class CashRebate:public CashSuper
{
public:
    CashRebate(double reb):money_rebate(reb){};
    double acceptCash(double money)
    {
        return money * money_rebate;
    }
private:
    double money_rebate = 1;
};

class CashReturn: public CashSuper
{
public:
    CashReturn(double condition, double ret):money_condition(condition),money_return(ret){};
    double acceptCash(double money)
    {
        if(money < money_condition)
            return money;
        else
        {
            return money - money / money_condition * money_return;
        }
    }
private:
    double money_condition = 0;
    double money_return = 0;
};

//strategy and simpleFactory 
class CashContext
{
public:
    CashContext(char c)
    {
        switch(c)
        {
            case 'N':
                cs = new CashNormal();
                break;
            case 'B':
                cs = new CashRebate(0.8);
                break;
            case 'R':
                cs =new CashReturn(500,150);
                break;
        }
    } 
    ~CashContext()
    {
        if(cs != NULL)
        delete cs;
        cs =NULL;
    }
    double GetResult(double money)
    {
        return cs->acceptCash(money);
    }

private:
    CashSuper* cs = NULL;
};

int main()
{
    double money = 1000;
    CashContext* cs_con = new CashContext('R');
    double total = cs_con->GetResult(money);
    cout << "Need to pay money is " << total << endl;
    free(cs_con);
    return 1;
}