#include <iostream>
#include <algorithm>
#define FOR(i,n) for(int i = 0 ; i < n ; ++i)

int tree[1000001], n, goal, max_len;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> goal;

	FOR(i,n) {
		std::cin >> tree[i];
		max_len < tree[i] ? max_len = tree[i] : max_len;
	}

	std::sort(tree, tree + n);

	int start = 1, end = max_len;
	while (start <= end) {
		int mid = (start + end) / 2;
		long long len_sum = 0;
		
		FOR(i, n) 
			if (tree[i] > mid) len_sum += tree[i] - mid;
		

		//std::cout << start << ", " << mid << ", " << end << " SUM : " << len_sum << '\n';

		if (len_sum < goal)			end = mid - 1;
		else						start = mid + 1;
	
		/*else if (len_sum == goal) {
			std::cout << mid;

			return 0;
		}*/
	}


	std::cout << end;

	return 0;
}
/*
4 7
20 15 10 17

> 15




*/

//void q::q2805()
//{
//	long long tree_num, target, tree_length[100001], max_length = 0, height = 0, total = 0;
//	cin >> tree_num >> target;
//	for (long long i = 0; i < tree_num; i++)
//	{
//		cin >> tree_length[i];
//		max_length > tree_length[i] ?
//			max_length = max_length : max_length = tree_length[i];
//	}
//
//	long long start = 1, end = max_length, mid;
//	while (start <= end) {
//		total = 0;
//		mid = (start + end) / 2;
//		for (long long i = 0; i < tree_num; i++)
//		{
//			if (mid < tree_length[i])
//				total += tree_length[i] - mid;
//		}
//
//		if (total < target) {
//			end = mid - 1;
//		}
//		else if (total >= target) {
//			start = mid + 1;
//
//			if (height < mid)
//				height = mid;
//		}
//
//	}
//
//	cout << height;
//}