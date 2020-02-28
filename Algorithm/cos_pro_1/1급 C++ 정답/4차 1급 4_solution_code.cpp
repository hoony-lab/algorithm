#include <iostream>
#include <vector>
using namespace std;

const int n = 4;

vector<int> find_not_exist_nums(vector<vector<int> > matrix) {
    vector<int> nums;
    bool exist[n * n + 1] = {false};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                exist[matrix[i][j]] = true;
            }
        }
    }
    for (int i = 1; i <= n * n; i++) {
        if (!exist[i]) {
            nums.push_back(i);
        }
    }
    return nums;
}

vector<pair<int, int> > find_blank_coords(vector<vector<int> > matrix) {
    vector<pair<int, int> > coords;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                coords.push_back( make_pair(i, j) );
            }
        }
    }
    return coords;
}

bool is_magic_square(vector<vector<int> > matrix) {
    int i, j;
    int sum = 0;
    for (i = 1; i <= n * n; i++) {
        sum += i;
    }
    sum = sum / n;
    for (i = 0; i < n; i++) {
        int row_sum = 0;
        int col_sum = 0;
        for (j = 0; j < n; j++) {
            row_sum += matrix[i][j];
            col_sum += matrix[j][i];
        }
        if (row_sum != sum) {
            return false;
        }
        if (col_sum != sum) {
            return false;
        }
    }
    int main_diagonal_sum = 0;
    int skew_diagonal_sum = 0;
    for (i = 0; i < n; i++) {
        main_diagonal_sum += matrix[i][i];
        skew_diagonal_sum += matrix[i][n-1-i];
    }
    if (main_diagonal_sum != sum) {
        return false;
    }
    if (skew_diagonal_sum != sum) {
        return false;
    }
    return true;
}

vector<int > solution(vector<vector<int> > matrix) {
    vector<int> answer;
    vector<pair<int, int> > coords = find_blank_coords(matrix);
    vector<int> nums = find_not_exist_nums(matrix);

    matrix[coords[0].first][coords[0].second] = nums[0];
    matrix[coords[1].first][coords[1].second] = nums[1];
    if (is_magic_square(matrix)) {
        for (int i = 0; i <= 1; i++) {
            answer.push_back(coords[i].first + 1);
            answer.push_back(coords[i].second + 1);
            answer.push_back(nums[i]);
        }
    }
    else {
        matrix[coords[0].first][coords[0].second] = nums[1];
        matrix[coords[1].first][coords[1].second] = nums[0];
        for (int i = 0; i <= 1; i++) {
            answer.push_back(coords[1-i].first + 1);
            answer.push_back(coords[1-i].second + 1);
            answer.push_back(nums[i]);
        }
    }
    return answer;
}