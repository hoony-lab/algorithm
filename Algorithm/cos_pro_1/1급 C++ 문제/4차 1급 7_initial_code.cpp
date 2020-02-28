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

class Monster : @@@{
public:
    int attack_point;
    Monster(int attack_point){
        this->attack_point = attack_point;
    }
    @@@{
        this->HP -= damage;
    }
    @@@{
        return attack_point;
    }
};

class Warrior : @@@{
public:
    int attack_point;
    Warrior(int attack_point){
        this->attack_point = attack_point;
    }
    @@@{
        this->HP -= damage;
    }
    @@@{
        return attack_point;
    }
};

class Healer : @@@{
public:
    int healing_point;
    Healer(int healing_point){
        this->healing_point = healing_point;
    }
    @@@{
        this->HP -= damage;
    }
    @@@{
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


// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main(){
    int monster_attack_point = 100;
    int warrior_attack_point = 90;
    int healing_point = 30;
    
    vector<int> ret = solution(monster_attack_point, warrior_attack_point, healing_point);
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 {";
    for(int i = 0; i < ret.size(); i++){
        if (i != 0) cout << ", ";
        cout << ret[i];
    }
    cout << "} 입니다." << endl;
}