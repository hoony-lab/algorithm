#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Unit{
public:
    int HP;
    Unit(){
        this->HP = 1000;
    }
    void under_attack(int damage){
        return ;
    }
};

class Monster : public Unit{
public:
    int attack_point;
    Monster(int attack_point){
        this->attack_point = attack_point;
    }
    void under_attack(int damage){
        this->HP -= damage;
    }
    int attack(){
        return attack_point;
    }
};

class Warrior : public Unit{
public:
    int attack_point;
    Warrior(int attack_point){
        this->attack_point = attack_point;
    }
    void under_attack(int damage){
        this->HP -= damage;
    }
    int attack(){
        return attack_point;
    }
};

class Healer : public Unit{
public:
    int healing_point;
    Healer(int healing_point){
        this->healing_point = healing_point;
    }
    void under_attack(int damage){
        this->HP -= damage;
    }
    void healing(Unit& unit){
        unit.HP += healing_point;
    }
};


vector<int> solution(int monster_attack_point, int warrior_attack_point, int healing_point){
    Monster monster(monster_attack_point);
    Warrior warrior(warrior_attack_point);
    Healer healer(healing_point);
    
    //전사가 몬스터를 한 번 공격
    monster.under_attack(warrior.attack());
    //몬스터가 전사를 한 번 공격
    warrior.under_attack(monster.attack());
    //몬스터가 힐러를 한 번 공격
    healer.under_attack(monster.attack());
    //힐러가 전사의 체력을 한 번 회복
    healer.healing(warrior);
    //힐러가 몬스터의 체력을 한 번 회복
    healer.healing(monster);
    
    vector<int> answer = {monster.HP, warrior.HP, healer.HP};
    return answer;
}