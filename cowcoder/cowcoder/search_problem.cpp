#include "common.h"

class Search{
public:
	int sequenceSearch(vector<int>& v, int key){
		int n = (int)(v.size());
		for (int i = 0; i < n; ++i){
			if (v[i] == key){
				return i;
			}
		}
		return -1;
	}
	int binarySearch(vector<int>& v, int key){
		int first = 0;
		int last = (int)(v.size() - 1);
		while (first <= last){
			int mid = first + ((last - first) >> 1);
			if (v[mid] == key){
				return mid;
			}
			else if (v[mid] > key){
				last = mid - 1;
			}
			else{
				first = mid + 1;
			}
		}
		return -1;
	}
	int binarySearch_recursion(vector<int>& v, int first, int last, int key){
		if (first > last){
			return -1;
		}
		int mid = first + ((last - first) >> 1);
		if (v[mid] == key){
			return mid;
		}
		else if (v[mid] > key){
			return binarySearch_recursion(v, first, mid - 1, key);
		}
		else{
			return binarySearch_recursion(v, mid + 1, last, key);
		}
	}
	int lowwerBoundSearch(vector<int>& v, int key){
		int first = 0;
		int last = (int)(v.size() - 1);
		while (first <= last){
			int mid = first + ((last - first) >> 1);
			if (v[mid] < key){
				first = mid + 1;
			}
			else {
				last = mid - 1;
			}
		}
		return first;
	}

	int lowerBoundSearch2(vector<int>& v, int key){
		int first = 0;
		int last = (int)(v.size() - 1);
		while (first < last){
			int mid = first + ((last - first) >> 1);
			if (v[mid] < key){
				first = mid + 1;
			}
			else {
				last = mid;
			}
		}
		return first;
	}


	int upperBoundSearch(vector<int>& v, int key){
		int first = 0;
		int last = (int)(v.size() - 1);
		while (first <= last){
			int mid = first + ((last - first) >> 1);
			if (v[mid] <= key){
				first = mid + 1;
			}
			else {
				last = mid - 1;
			}
		}
		return first;
	}
	int insertSearch(vector<int>& v, int key){
		int first = 0;
		int last = (int)(v.size() - 1);
		while (first <= last){
			int mid = first + (key - v[first]) *(last - first) / (v[last] - v[first]);
			if (v[mid] == key){
				return mid;
			}
			else if (v[mid] > key){
				last = mid - 1;
			}
			else{
				first = mid + 1;
			}
		}
		return -1;
	}
	int insertSearch_recursion(vector<int>& v, int first, int last, int key){
		if (first > last){
			return -1;
		}
		int mid = first + (key - v[first])*(last - first) / (v[last] - v[first]);
		if (v[mid] == key){
			return mid;
		}
		else if (v[mid] > key){
			return insertSearch_recursion(v, first, mid - 1, key);
		}
		else{
			return insertSearch_recursion(v, mid + 1, last, key);
		}
	}
	vector<int> fio(int n = 20){
		static vector<int> ret{ 1, 1, 2, 3 };
		for (int i = (int)(ret.size()); i < n; ++i){
			ret.push_back(ret[i - 1] + ret[i - 2]);
		}
		return ret;
	}
	int fioSearch(vector<int>& v, int key){
		vector<int> fib = fio();
		while (fib.back() < v.size()){
			fio(fib.size() + 10);
		}
		int ret = lowwerBoundSearch(fib, v.size() + 1);
		vector<int> temp = v;
		for (size_t i = v.size(); i < fib[ret] - 1; ++i){
			temp.push_back(v[v.size() - 1]);
		}
		int first = 0;
		int last = temp.size();
		while (first <= last){
			int mid = first + fib[ret - 1] - 1;
			if (v[mid] == key){
				if (mid > v.size()){
					mid = v.size();
				}
				return mid;
			}
			else if (v[mid] > key){
				last = mid - 1;
				ret -= 1;
			}
			else{
				first = mid + 1;
				ret -= 2;
			}
		}
		return -1;
	}
	int fioSearch_re(vector<int>& v, int key){
		vector<int> fib = fio();
		while (fib.back() < v.size()){
			fio(fib.size() + 10);
		}
		int fibonace = lowwerBoundSearch(fib, v.size() + 1);
		vector<int> temp = v;
		for (size_t i = v.size(); i < fib[fibonace] - 1; ++i){
			temp.push_back(v[v.size() - 1]);
		}
		int ret = fioSearch_re_core(v, 0, v.size() - 1, fib, fibonace, key);
		return ret > v.size() ? v.size() : ret;
	}
	int fioSearch_re_core(vector<int>& v, int first, int last, vector<int>& fib, int fibonace, int key){
		if (first > last){
			return -1;
		}
		int mid = first + fib[fibonace - 1] - 1;
		if (v[mid] == key){
			return mid;
		}
		else if (v[mid] > key){
			return fioSearch_re_core(v, first, mid - 1, fib, fibonace - 1, key);
		}
		else{
			return fioSearch_re_core(v, mid + 1, last, fib, fibonace - 2, key);
		}
	}
	vector<int> generateVector(size_t n){
		vector<int> ret(n, 0);
		srand((unsigned(time(NULL))));
		for (size_t i = 0; i < n; ++i){
			ret[i] = rand() % 1000;
		}
		return ret;
	}
	vector<int> getRealOrder(vector<int>& v){
		vector<int> ret = v;
		sort(ret.begin(), ret.end(), less<int>());
		return ret;
	}
	//广度搜索
	bool is_surrounded(vector<vector<char>>& m, int row, int col){
		int left = 0;
		for (int i = row - 1; i > -1; --i){
			if (m[row][i] == 'X'){
				left = 1; break;
			}
		}
		if (left == 0){ return false; }

		int right = 0;
		for (int i = row + 1; i < (int)m[0].size(); ++i){
			if (m[row][i] == 'X'){
				right = 1; break;
			}
		}
		if (right == 0){ return false; }

		int up = 0;
		for (int i = row - 1; i > -1; --i){
			if (m[i][col] == 'X'){
				up = 1; break;
			}
		}
		if (up == 0){ return false; }

		int down = 0;
		for (int i = row + 1; i < (int)m.size(); ++i){
			if (m[i][col] == 'X'){
				down = 1; break;
			}
		}
		if (down == 0){ return false; }
		return true;
	}
	void suround_region(vector<vector<char>>& m){
		for (int i = 0; i < (int)m.size(); ++i){
			for (int j = 0; j < (int)m[0].size(); ++j){
				if (m[i][j] == '0' && is_surrounded(m, i, j)){
					m[i][j] = 'X';
				}
			}
		}
	}
	//深度搜索
	void get_string_palindrome_sub(string& str, int index, vector<string>& path, vector<vector<string>>& ret){
		if (index == (int)str.size()){
			ret.push_back(path);
			return;
		}
		vector<vector<bool>> dp(str.size(), vector<bool>(str.size(), false));
		for (int i = 0; i < (int)str.size(); ++i){
			dp[i][i] = true;
			if (str[i] == str[i + 1]){
				dp[i][i + 1] = true;
			}
		}
		dp[str.size() - 1][str.size() - 1] = true;
		for (int i = (int)str.size() - 3; i > -1; --i){
			for (int j = i + 3; j < (int)str.size(); ++j){
				if (str[i] == str[j]){
					dp[i][j] = true;
				}
			}
		}
		for (int i = index; i < (int)str.size(); ++i){
			if (dp[index][i] == true){
				path.push_back(str.substr(index, i - index + 1));
				get_string_palindrome_sub(str, i + 1, path, ret);
				path.pop_back();
			}
		}
	}
	int unique_path_sum(int row, int col, int i, int j){
		if (i == row || j == col){
			return 1;
		}
		return unique_path_sum(row, col, i + 1, j) + unique_path_sum(row, col, i, j+1);
	}
	int unique_path_sum_obstacle(vector<vector<int>>& m, int i, int j){
		if (i == (int)m.size()-1 && j == (int)m[0].size() - 1){
			return 1;
		}
		int ret = 0;
		if (i < (int)m.size() - 1 && j < (int)m[0].size() - 1){
			if (m[i][j + 1] == 0){
				ret += unique_path_sum_obstacle(m, i, j + 1);
			}if (m[i + 1][j] == 0){
				ret += unique_path_sum_obstacle(m, i + 1, j);
			}
		}
		else if (i == (int)m.size() - 1 ){
			if (m[i][j + 1] == 0){
				ret += unique_path_sum_obstacle(m, i, j + 1);
			}
		}
		else {
			if (m[i + 1][j] == 0){
				ret += unique_path_sum_obstacle(m, i + 1, j);
			}
		}
		return ret;
	}

};

#if 0

int main(){
	Search S;
	//vector<vector<char>> m{ { 'X', 'X', 'X', 'X' }, { 'X', '0', '0', 'X' },
	//{ 'X', 'X', '0', 'X' }, { 'X', '0', 'X', 'X' } };
	//S.suround_region(m);
	//for (int i = 0; i < (int)m.size(); ++i){
	//	for (int j = 0; j < (int)m[0].size(); ++j){
	//		cout << m[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//string str("aab");
	//vector<string> path;
	//vector<vector<string>> ret;
	//S.get_string_palindrome_sub(str, 0, path, ret);
	//for (auto& data : ret){
	//	for (auto& str : data){
	//		cout << str << " ";
	//	}
	//	cout << endl;
	//}
	vector<vector<int>> m{{0, 0, 0}, { 0, 1, 0 }, { 0, 1, 0 }};
	cout << S.unique_path_sum_obstacle(m, 0, 0) << endl;
	//cout << S.unique_path_sum(2, 6,0,0) << endl;
	return 0;
}

#endif




//int main(){
//	if (0){
		//cout << "____________ Search _________" << endl;
		//Search SE;
		//vector<int> raw = SE.generateVector(20);
		//vector<int> order = SE.getRealOrder(raw);
		//
		//const int FIND = 12;
		//int ret = SE.sequenceSearch(order, order[FIND]);
		//cout << "____________ binarySearch _________" << endl;
		//cout << (SE.binarySearch(order, order[FIND]) == ret) << endl;
		//cout << (SE.binarySearch_recursion(order, 0, order.size() - 1, order[FIND]) == ret) << endl;
		//cout << "____________ insertSearch _________" << endl;
		//cout << (SE.insertSearch(order, order[FIND]) == ret) << endl;
		//cout << (SE.insertSearch_recursion(order, 0, order.size() - 1, order[FIND]) == ret) << endl;
		//cout << "____________ fioSearch _________" << endl;
		//cout << (SE.fioSearch(order, order[FIND]) == ret) << endl;
		//cout << (SE.fioSearch_re(order, order[FIND]) == ret) << endl;
		//cout << endl;
		//ret = SE.sequenceSearch(order, FIND);
		//cout << "____________ binarySearch _________" << endl;
		//cout << (SE.binarySearch(order, FIND)) << endl;
		//cout << (SE.binarySearch_recursion(order, 0, order.size() - 1, FIND)) << endl;
		//cout << "____________ insertSearch _________" << endl;
		//cout << (SE.insertSearch(order, FIND)) << endl;
		//cout << (SE.insertSearch_recursion(order, 0, order.size() - 1, FIND)) << endl;
		//cout << "____________ fioSearch _________" << endl;
		//cout << (SE.fioSearch(order, FIND)) << endl;
		//cout << (SE.fioSearch_re(order, FIND)) << endl;

//	}
//	return 0;
//}