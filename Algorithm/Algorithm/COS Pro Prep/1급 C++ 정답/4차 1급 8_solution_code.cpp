#include <string>
#include <vector>

using namespace std;

vector<int> func_a(vector<int> card) {
    vector<int> card_count(10, 0);
    for (int i = 0; i < card.size(); i++) {
        card_count[card[i]]++;
    }
    return card_count;
}

vector<int> num_list;
void func_b(int level, int max_level, int num, vector<int> current_count, vector<int> max_count) {
    if (level == max_level) {
        num_list.push_back(num);
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (current_count[i] < max_count[i]) {
            current_count[i] += 1;
            func_b(level + 1, max_level, num * 10 + i, current_count, max_count);
            current_count[i] -= 1;
        }
    }
}

int func_c(vector<int> list, int n) {
    for (int i = 0; i < list.size(); i++) {
        if (n == list[i])
            return i + 1;
    }
    return -1;
}

int solution(vector<int> card, int n) {
    vector<int> card_count = func_a(card);
    func_b(0, card.size(), 0, vector<int>(10, 0), card_count);
    int answer = func_c(num_list, n);
    return answer;
}