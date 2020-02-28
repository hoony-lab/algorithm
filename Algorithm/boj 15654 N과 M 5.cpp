#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int N, M, arr[10], perm[10];
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		perm[i] = 0;
	}
	for (int i = 0; i < M; i++)
	{
		perm[M-i-1] = 1;
	}

	sort(arr, arr + N);
	sort(perm, perm + N);
	int num = 0;

	do {

		for (int i = 0; i < N; i++){
			if(perm[i])
				cout << arr[i] << " ";
		}cout << '\n';
		
	} while (next_permutation(perm, perm+N));



	cout << endl << endl;

	sort(arr, arr + N);
	sort(perm, perm + N);

	do {
		for (int i = 0; i < N; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
	} while (next_permutation(arr, arr + N));


	return 0;
}