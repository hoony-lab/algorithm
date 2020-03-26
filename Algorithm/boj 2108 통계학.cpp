#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::vector<int> num;
	float sum = 0;
	int n, tmp;
	std::cin >> n;
	
	for (int i = 0; i < n; ++i) {
		std::cin >> tmp;
		num.push_back(tmp);
		sum += tmp;
	}

	std::sort(num.begin(), num.end());

	//»ê¼úÆò±Õ
	std::cout << (int)floor((sum / n) + 0.5) << '\n';

	//Áß¾Ó°ª
	std::cout << num[n / 2] << '\n';

	//ÃÖºó°ª
	std::vector<std::pair<int, int>> v;

	for (int i = 0; i < n; ++i) {
		if (v.empty()) {
			v.push_back(std::make_pair(num[i], 1));
			continue;
		}

		if (v.back().first == num[i]) {
			std::pair<int, int> tmp = v.back();
			tmp.second++;
			v.pop_back();
			v.push_back(tmp);
		}
		else v.push_back(std::make_pair(num[i], 1));
	}

	std::sort(v.begin(), v.end(), [](std::pair<int, int> v1, std::pair<int, int> v2) {
		if (v1.second == v2.second)
			return v1.first < v2.first;
		return v1.second > v2.second;
		});

	if (v[0].second == v[1].second)
		std::cout << v[1].first << '\n';
	else std::cout << v[0].first << '\n';

	//¹üÀ§
	std::cout << num.back() - num.front();

	return 0;
}

/*

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    vector<int> v;
    int key;
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        v.push_back(key);

        sum += key;
    }
    sort(v.begin(), v.end());

    printf("%d\n", (int)floor((sum / n) + 0.5));

    printf("%d\n", v[n / 2]);

    vector<pair<int, int>> st;


    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            st.push_back(pair<int, int>(v[i], 1));
            continue;
        }

        if (st.back().first == v[i])
        {
            pair<int, int> temp = st.back();
            temp.second++;
            st.pop_back();
            st.push_back(temp);
        }
        else
        {
            st.push_back(pair<int, int>(v[i], 1));
        }
    }

    sort(st.begin(), st.end(),[](std::pair<int, int> v1, std::pair<int, int> v2) {
        if (v1.second == v2.second)
            return v1.first < v2.first;
        return v1.second > v2.second;
    });

    if (st[0].second == st[1].second)
    {
        printf("%d\n", st[1].first);
    }
    else
    {
        printf("%d\n", st[0].first);
    }

    printf("%d", v.back() - v.front());

    return 0;
}

*/