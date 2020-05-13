
#include "common.h"

//字符串
class StringProblem{
public:
	StringProblem(){
		count = 0;
	}
	int count;
	string togjizifuchuan(string& str){
		if (str.empty()){
			return string();
		}
		stringstream s;
		int count = 1;
		char curCh = str[0];
		for (size_t i = 1; i < str.size(); ++i){
			if (curCh == str[i]){
				++count;
			}
			else{
				s << curCh << '_' << count << '_';
				curCh = str[i];
				count = 1;
			}
		}
		s << curCh << '_' << count;
		return s.str();
	}
	//数字字符串的含义
	void digistStringMeaing(string& str, int i, string& ret){
		if (i == str.size()){
			cout << ret << endl;
			++count;
			return;
		}
		//cout << map_digist_char[str[i]];
		for (const auto& ch : map_digist_char[str[i] - '0']){
			ret.push_back(ch);
			digistStringMeaing(str, i + 1, ret);
			ret.pop_back();
		}

	}
	vector<int> get_next(string& str){
		vector<int> next(str.size(), -1);
		if (str.size() < 2){
			return next;
		}
		next[1] = 0;
		size_t pos = 2;
		size_t cn = 0;
		while (pos < str.size()){
			if (str[pos - 1] == str[cn]){
				next[pos++] = ++cn;
			}
			else if (next[cn] > 0){
				cn = next[cn];
			}
			else{
				next[pos++] = 0;
			}
		}
		return next;
	}
	int issubstring(string& str1, string& str2){
		if (str1.size() < str2.size() || str2.empty()){
			return -1;
		}
		vector<int> next = get_next(str1);
		size_t i = 0;
		size_t j = 0;
		while (i < str1.size() && j < str2.size()){
			if (str1[i] == str2[j]){
				++i; ++j;
			}
			else if (next[j] > -1){
				j = next[j];
			}
			else{
				++i;
			}
		}
		return j == str2.size() ? i - str2.size() : -1;
	}
	//滑动窗口最大值
	vector<int> getwindowsmax(vector<int>& v, int k){
		vector<int> ret;
		if (v.size() < k){
			return ret;
		}
		deque<int> dq;
		for (size_t i = 0; i < v.size(); ++i){
			while (!dq.empty() && v[dq.back()] < v[i]){
				dq.pop_back();
			}
			dq.push_back(i);
			if (i >= (k - 1)){
				ret.push_back(v[dq.front()]);
			}
			if (dq.front() <= i - k + 1){
				dq.pop_front();
			}
		}
		return ret;
	}
	//manacher
	int longestHuiWen(string& str){
		int n = 2 * str.size() + 1;
		string manacher(n, '*');
		for (size_t i = 0; i < str.size(); ++i){
			manacher[2 * i + 1] = str[i];
		}
		int c = -1, pR = -1;
		int ret = 0;
		vector<int> pArr(n, 0);
		for (int i = 0; i < n; ++i){
			pArr[i] = pR > i ? min(pR - i, pArr[2 * c - i]) : 1;
			while (i + pArr[i] < n && i - pArr[i] > 0
				&& (manacher[i + pArr[i]] == manacher[i - pArr[i]])){
				pArr[i]++;
			}
			if (i + pArr[i] > pR){
				pR = i + pArr[i];
				c = i;
			}
			ret = max(ret, pArr[i]);
		}
		return ret - 1;
	}
	void rotatetring(string& str, int k){
		reverse(str.begin(), str.begin() + k);
		reverse(str.begin() + k, str.end());
		reverse(str.begin(), str.end());
	}
	void rotatetring2(string& str, int k){
		int first = 0;
		int mid = k;
		int i = mid;
		int last = str.size();
		while (1){
			swap(str[first], str[i]);
			++i; ++first;
			if (first == mid){
				if (i == last){
					return;
				}
				mid = i;
			}
			else if (i == last){
				i = mid;
			}
		}
	}
	//字符串最长的回文子序列
	int stringLongestHuiWenSub(string& str, int i, int j){
		if (i > j){
			return 0;
		}
		if (i == j){
			return 1;
		}
		if (str[i] == str[j]){
			return stringLongestHuiWenSub(str, i + 1, j - 1) + 2;
		}
		else{
			return max(stringLongestHuiWenSub(str, i + 1, j), stringLongestHuiWenSub(str, i, j - 1));
		}
	}
	int stringLongestHuiWenSub_dp(string& str){
		vector<vector<int>> dp(str.size(), vector<int>(str.size(), 0));

		for (size_t i = 0; i < str.size(); ++i){
			dp[i][i] = 1;
		}
		for (size_t j = 1; j < str.size(); ++j){
			for (size_t i = 0; i < str.size() - j; ++i){
				if (str[i] == str[i + j]){
					dp[i][i + j] = dp[i + 1][i + j - 1] + 2;
				}
				else{
					dp[i][i + j] = max(dp[i + 1][i + j], dp[i][i + j - 1]);
				}
			}
		}
		return dp[0][str.size() - 1];
	}
	int longestHuiwenSubStr(string& str){
		int maxL = 1;
		vector<vector<bool>> dp(str.size(), vector<bool>(str.size(), false));
		for (int i = 0; i < str.size() - 1; ++i){
			dp[i][i] = true;
			dp[i][i + 1] = str[i] == str[i + 1] ? maxL = 2, true : false;
		}
		dp[str.size() - 1][str.size() - 1] = 1;
		for (int j = 2; j < str.size(); ++j){
			for (int i = 0; i < str.size() - j; ++i){
				if (str[i] == str[i + j] && dp[i + 1][j - 1]){
					dp[i][i + j] = true;
					maxL = max(maxL, j + 1);
				}
			}
		}
		return maxL;
	}
private:
	static const vector<string> map_digist_char;
};
const vector<string> StringProblem::map_digist_char{ "", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz" };
