#include <string>
#include <vector>

using namespace std;

int solution(int n, int mix, int k) {
    int answer = 0;
    
    vector<int> card(n);
    for(int i = 0; i < n; i++) 
        card[i] = i+1;
    
    while(mix--) {
        vector<int> card_a(n/2), card_b(n/2);
        
        for(int i = 0; i < n; i++) {
            if(i < n/2)
            	card_a[i] = card[i];
            else
                card_b[i-n/2] = card[i];
        }
        
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0)
                card[i] = card_a[i/2];
            else
                card[i] = card_b[i/2];
        }
    }
    
    answer = card[k-1];
    
    return answer;
}