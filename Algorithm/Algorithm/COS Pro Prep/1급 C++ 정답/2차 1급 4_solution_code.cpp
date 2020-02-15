#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr, int K) {
    int n = arr.size();
    int count = 0;
    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j)
            for(int k = j + 1; k < n; ++k)
                if((arr[i]+arr[j]+arr[k])%K == 0)
                    count += 1;
    return count;
}