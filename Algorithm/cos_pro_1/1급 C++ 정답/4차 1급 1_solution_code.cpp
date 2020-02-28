#include <string>
#include <vector>
using namespace std;


string vowels[5] = {"A", "E", "I", "O", "U"};
vector<string> words;

void create_words(int lev, string str) {
    words.push_back(str);
    for (int i = 0; i < 5; i++) {
        if (lev < 5) {
            create_words(lev + 1, str + vowels[i]);
        }
    }
}

int solution(string word) {
    int answer = 0;
    create_words(0, "");
    int words_n = words.size();
    for (int i = 0; i < words_n; i++) {
        if (word.compare(words[i]) == 0) {
            answer = i;
            break;
        }
    }
    return answer;
}