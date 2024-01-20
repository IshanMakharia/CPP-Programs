

#include <iostream>

using namespace std;

class Player{
private:
    string name;
    int health, xp;
    //int *i;
public:
    string get_name() {return name;}
    int get_health() {return health;}
    int get_xp() {return xp;}
    //int* get_pointer() {return i;}
    //int get_pointer() {return (*i);} 
    Player(string name_val="None", int health_val=0, int xp_val=0);
    //Player(string name_val, int health_val, int xp_val, int *i);
    //Player(const Player &source);
    ~Player() {cout << "Destructor for " + name << endl;}
};

Player::Player(string name_val, int health_val, int xp_val)
    :name{name_val}, health{health_val}, xp{xp_val} {
        cout << "Constructor for " + name << endl;
    }

/*Player::Player(string name_val, int health_val, int xp_val, int *i_val)
    :name{name_val}, health{health_val}, xp{xp_val}, i{i_val} {
        cout << "Constructor for " + name << endl;
    }

Player::Player(const Player &source)
    //:name{source.name}, health{source.health}, xp{source.xp} {
    :Player{source.name, source.health, source.xp, source.i} {
        cout << "Copy constructor for " + name << endl;
    }*/

void display_player(Player p) {
    cout << "Name : " << p.get_name() << endl;
    cout << "Health : " << p.get_health() << endl;
    cout << "XP : " << p.get_xp() << endl;
    //cout << "Pointer : " << p.get_pointer() << endl;
}

int main()
{
    Player empty;
    display_player(empty);
    Player frank{"Frank"};
    Player hero{"Hero", 100};
    Player villain{"Villain", 100, 55};
    display_player(villain);
    Player enemy(villain);
    display_player(enemy);
    /*int j = 10;
    cout << &j << endl;
    Player trainee{"Trainee", 100, 50, &j};
    display_player(trainee);*/
    return 0;
}