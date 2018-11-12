#include <iostream>

using namespace std;

class Person
{
public:
    Person(){};
    Person(string name):_name(name){};
    virtual void Show()
    {
        cout << _name << "装扮的:" << endl;
    }
    virtual ~Person() {}
private:
    string _name;
};

class Finery: public Person
{
protected:
    Person* component;
public:
    Finery() {}
    ~Finery() {}
    void Decorate(Person* comp)
    {
     component = comp;   
    }
    
    void Show()
    {
        if(component != NULL)
            component->Show();
    }
};

class TShirt: public Finery
{
public:
    void Show()
    {
        Finery::Show();
        AddDecorate_tshirt();         
    }
    void AddDecorate_tshirt()
    {
        cout << "大T恤" <<endl; 
    }    
};

class BigTrouser: public Finery
{
public:
    void Show()
    {
        Finery::Show();
        AddDecorate_bigtrouser();       
    }
private:
    void AddDecorate_bigtrouser()
    {
        cout << "大裤衩" <<endl; 
    }
};

int main()
{
    Person* pr = new Person("bruce");
    TShirt* th = new TShirt();
    BigTrouser* bt = new BigTrouser();
    th->Decorate(pr);
    bt->Decorate(th);
    bt->Show();
    delete bt;
    delete th;
    delete pr;
    return 1;   
}

