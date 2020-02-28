#include <string>
#include <vector>

using namespace std;

bool solution(string password) {
    int length = password.length();
    for(int i = 0; i < length - 2; ++i){
        int firstCheck = password[i + 1] - password[i];
        int secondCheck = password[i + 2] - password[i + 1];
        if(firstCheck == secondCheck && (firstCheck == 1 || firstCheck == -1))
            return false;
    }
    return true;
}