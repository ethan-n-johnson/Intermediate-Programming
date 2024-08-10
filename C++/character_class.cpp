#include <iostream>
#include <string>

using namespace std;

class character
{
    private:
        string name;
        int hp;
        int ac;
        int dex;
        int str;

    public:
        string getName() const
        {
            return name;
        }
        void setName(string n)
        {
            name = n;
        }
        int getHP() const
        {
            return hp;
        }
        void setHP(int n)
        {
            if (n > 0)
            {
                hp = n;
            }
            else
            {
                hp = 0;
            }
        }
        int getAC() const
        {
            return hp;
        }
        void setAC(int n)
        {
            ac = n;
        }
        int getDEX() const
        {
            return hp;
        }
        void setDEX(int n)
        {
            dex = n;
        }
        int getSTR() const
        {
            return hp;
        }
        void setSTR(int n)
        {
            str = n;
        }
};

void Attack(string name1, string name2)
{
    cout << name1 <<" Attacked " << name2 << endl;
}

int main()
{
    character a;
    character b;
    a.setName("Player1");
    a.setHP(15);
    a.setAC(12);
    a.setDEX(7);
    a.setSTR(3);

    b.setName("Player2");
    b.setHP(20);
    b.setAC(10);
    b.setDEX(5);
    b.setSTR(5);

    Attack(a.getName(), b.getName());
}