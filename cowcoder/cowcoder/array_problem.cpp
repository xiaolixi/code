#include "common.h"
class ArrayProblem{
public:
	//最大累加和子数组的大小（数组最大累加和数组）
	int maxAcclemationSubArray(vector<int>& v){
		int cur = 0;
		int ma = INT_MIN;
		for (auto i : v){
			cur += i;
			if (cur < i){
				cur = i;
			}
			if (ma <= cur){
				ma = cur;
			}
		}
	}
	//最大累加和子数组的区间
	int maxAcclemationSubArray_range(vector<int>& v){
		int cur = 0;
		int ma = INT_MIN;
		vector<int> curpath;
		vector<int> maxpath;
		for (auto i : v){
			cur += i;
			curpath.push_back(i);
			if (cur < i){
				cur = i;
				curpath.clear();
				curpath.push_back(i);
			}
			if (ma <= cur){
				ma = cur;
				maxpath = curpath;
			}
		}
	}
	//两互不相容子数组最大累加和
	int maxAcclemationSubArray2(vector<int>& v){
		int his = INT_MIN;
		int cur = 0;
		vector<int> L = v;
		for (int i = 0; i < v.size(); ++i){
			cur += v[i];
			his = max(his, cur);
			cur = cur < 0 ? 0 : cur;
			L[i] = his;
		}
		his = INT_MIN;
		cur = 0;
		vector<int> R = v;
		for (int i = v.size() - 1; i > -1; --i){
			cur += v[i];
			his = max(his, cur);
			cur = cur < 0 ? 0 : cur;
			R[i] = his;
		}

		int ret = INT_MIN;
		for (int i = 0; i < v.size() - 1; ++i){
			ret = max(ret, L[i] + R[v.size() - 2 - i]);
		}
		return ret;
	}
	//累加和为K的最长子数组
	int maxAcclemationKSubArray(vector<int>& v, int K){
		int sum = 0;
		int len = 0;
		map<int, int> m;
		m.insert(make_pair(0, -1));
		for (int i = 0; i < v.size(); ++i){
			sum += v[i];
			if (m.find(sum - K) != m.end()){
				len = max(len, i - m[sum - K]);
			}
			if (m.find(sum) == m.end()){
				m.insert(make_pair(sum, i));
			}
		}
		return len;
	}
	//最长递增子序列(以i结尾的最长递增子序列）
	int lengestIncSubSerial(vector<int>& v){
		vector<int> sumArr(v.size(), 1);
		int ret = INT_MIN;
		for (int i = 1; i < v.size(); ++i){
			for (int j = i - 1; j > -1; --j){
				if (v[j] < v[i]){
					sumArr[i] = max(sumArr[i], sumArr[j] + 1);
				}
			}
			ret = max(ret, sumArr[i]);
		}
		return ret;
	}
	//是否有和为K的子序列
	bool sumIsAim(vector<int>& v, int i, int sum, int aim){
		if (i == v.size()){
			return sum == aim;
		}
		return sumIsAim(v, i + 1, sum, aim) || sumIsAim(v, i + 1, sum + v[i], aim);
	}
	void sumIsAim_path(vector<int>& v, int i, int sum, int aim, vector<int>& path){
		if (i == v.size()){
			if (sum == aim){
				for (auto data : path){
					cout << data << " ";
				}
				cout << endl;
			}
			return;
		}
		sumIsAim_path(v, i + 1, sum, aim, path);
		path.push_back(i);
		sumIsAim_path(v, i + 1, sum + v[i], aim, path);
		path.pop_back();
	}
	bool sumIsAim_dp(vector<int>& v, int aim){
		int sum = 0;
		for (auto i : v){
			sum += v[i];
		}
		if (sum < aim){
			return false;
		}if (sum == aim){
			return true;
		}

		vector<vector<bool>> dp(v.size() + 1, vector<bool>(sum + 1, false));
		dp[v.size()][aim] = 1;
		for (int i = v.size() - 1; i > -1; --i){
			for (int j = 0; j < sum + 1; ++j){
				if (dp[i + 1][j] == 1){
					dp[i][j] = 1;
				}
				if (j + v[i] < sum + 1){
					if (dp[i + 1][j + v[i]] == 1){
						dp[i][j] = 1;
					}
				}
			}
		}
		return (bool)dp[0][0];
	}
	//是否有路径
	bool havePathInMatrix(vector<vector<char>>& m, const string& str){
		if (str.empty()){
			return true;
		}
		for (int i = 0; i < (int)m.size(); ++i){
			for (int j = 0; j < (int)m[0].size(); ++j){
				if (m[i][j] == str[0] && matrix_ganran(m, i, j, 0, str)){
					return true;
				}
			}
		}
		return false;
	}
	bool matrix_ganran(vector<vector<char>>& m, int i, int j, int i_str, const string& str){
		if (i_str == str.size() - 1){
			return true;
		}
		char temp = m[i][j];
		m[i][j] = 0x01;
		bool up = false;
		bool down = false;
		bool left = false;
		bool right = false;
		if (i > 0 && m[i - 1][j] == str[i_str + 1]){
			up = matrix_ganran(m, i - 1, j, i_str + 1, str);
		}
		if (i < m.size() - 1 && m[i + 1][j] == str[i_str + 1]){
			down = matrix_ganran(m, i + 1, j, i_str + 1, str);
		}
		if (j > 0 && m[i][j - 1] == str[i_str + 1]){
			down = matrix_ganran(m, i, j - 1, i_str + 1, str);
		}
		if (j < m[0].size() - 1 && m[i][j + 1] == str[i_str + 1]){
			down = matrix_ganran(m, i, j + 1, i_str + 1, str);
		}
		m[i][j] = temp;
		return up || down || left || right;
	}
	//数组子序列累加和>=K的最小值
	int subAccK(vector<int>& v, int i, int sum, int K){
		if (i == v.size()){
			return sum >= K ? sum : INT_MAX;
		}
		return min(subAccK(v, i + 1, sum, K), subAccK(v, i + 1, sum + v[i], K));
	}
	//数组和为K的最大乘积
	class MaxMutli{
	public:
		int maxMutli_core(vector<int>& v, int i, int sum, int K){
			if (i == v.size()){
				if (sum == K){
					return 1;
				}
				else{
					return 0;
				}
			}
			if (sum > K){
				return 0;
			}
			return max(maxMutli_core(v, i + 1, sum, K), v[i] * maxMutli_core(v, i + 1, sum + v[i], K));
		}
		int maxMutli(vector<int>& v){
			return maxMutli_core(v, 0, 0, 10);
		}

		int maxMutli_dp(vector<int>& v, int K){
			vector<vector<int>> dp(v.size() + 1, vector<int>(K + 1, 0));
			dp[v.size()][K] = 1;

			for (int i = v.size() - 1; i > -1; --i){
				for (int j = 0; j <= K; ++j){
					dp[i][j] = dp[i + 1][j];
					if (j + v[i] <= K){
						dp[i][j] = max(dp[i][j], v[i] * dp[i + 1][j + v[i]]);
					}
				}
			}
			return dp[0][0];
		}
	};
	//矩阵的最大累加和矩阵
	int subMatrixMaxSum(vector<vector<int>>& m){
		int ma = INT_MIN;
		for (size_t i = 0; i < m.size(); ++i){
			vector<int> accArr(m[0].size(), 0);
			for (size_t j = i; j < m.size(); ++j){
				int cur = 0;
				for (size_t k = 0; k < m[0].size(); ++k){
					accArr[i] += m[i][k];
					cur += accArr[i];
					ma = max(ma, cur);
					cur = cur < 0 ? 0 : cur;
				}
			}

		}
	}
	//矩阵的最长递增长度
	int longestIncPath_ij(vector<vector<int>>& m, int i, int j){
		int res = 1;
		if (i > 0 && m[i - 1][j] > m[i][j]){
			res = max(res, longestIncPath_ij(m, i - 1, j) + 1);
		}
		if (i < m.size() - 1 && m[i + 1][j] > m[i][j]){
			res = max(res, longestIncPath_ij(m, i + 1, j) + 1);
		}
		if (j > 0 && m[i][j - 1] > m[i][j]){
			res = max(res, longestIncPath_ij(m, i, j - 1) + 1);
		}
		if (j < m[0].size() - 1 && m[i][j + 1] > m[i][j]){
			res = max(res, longestIncPath_ij(m, i, j + 1) + 1);
		}
		return res;
	}
	int longestIncPath(vector<vector<int>>& m){
		int ma = 0;
		for (int i = 0; i < m.size(); ++i){
			for (int j = 0; j < m[0].size(); ++j){
				ma = max(ma, longestIncPath_ij(m, i, j));
			}
		}
		return ma;
	}
	//矩阵的最长递增长度(dp)
	int longestIncPath_ij_dp(vector<vector<int>>& m, int i, int j, vector<vector<int>>& dp){
		if (dp[i][j] == 0){
			dp[i][j] = 1;
			if (i > 0 && m[i - 1][j] > m[i][j]){
				dp[i][j] = max(dp[i][j], longestIncPath_ij_dp(m, i - 1, j, dp) + 1);
			}
			if (i < m.size() - 1 && m[i + 1][j] > m[i][j]){
				dp[i][j] = max(dp[i][j], longestIncPath_ij_dp(m, i + 1, j, dp) + 1);
			}
			if (j > 0 && m[i][j - 1] > m[i][j]){
				dp[i][j] = max(dp[i][j], longestIncPath_ij_dp(m, i, j - 1, dp) + 1);
			}
			if (j < m[0].size() - 1 && m[i][j + 1] > m[i][j]){
				dp[i][j] = max(dp[i][j], longestIncPath_ij_dp(m, i, j + 1, dp) + 1);
			}
		}
		return dp[i][j];
	}
	int longestIncPath_dp(vector<vector<int>>& m){
		int ma = 0;
		vector<vector<int>> dp(m.size(), vector<int>(m[0].size(), 0));

		for (int i = 0; i < m.size(); ++i){
			for (int j = 0; j < m[0].size(); ++j){
				ma = max(ma, longestIncPath_ij_dp(m, i, j, dp));
			}
		}
		return ma;
	}
	//最小通路值
	int minPathValue(vector<vector<int>>& m, int i, int j){
		m[i][j] = 0;
		if (i == m.size() - 1 && j == m[0].size() - 1){
			m[i][j] = 1;
			return 1;
		}
		int down = INT_MAX;
		int right = INT_MAX;
		int up = INT_MAX;
		int left = INT_MAX;
		if (i < m.size() - 1 && m[i + 1][j] == 1){
			down = minPathValue(m, i + 1, j);
		}
		if (j < m[0].size() - 1 && m[i][j + 1] == 1){
			right = minPathValue(m, i, j + 1);
		}
		if (i > 0 && m[i - 1][j] == 1){
			up = minPathValue(m, i - 1, j);
		}
		if (j > 0 && m[i][j - 1] == 1){
			left = minPathValue(m, i, j - 1);
		}
		m[i][j] = 1;
		int mi = min(min(down, right), min(up, left));
		if (mi == INT_MAX){
			return mi;
		}
		else{
			return mi + 1;
		}
	}
	//分糖果
	int tangguo(vector<int>& v){
		vector<int> dp(v.size(), 0);
		dp[0] = 1;
		for (int i = 1; i < v.size(); ++i){
			if (v[i - 1] < v[i]){
				dp[i] = dp[i - 1] + 1;
			}
			else{
				dp[i] = 1;
				int j = i - 1;
				while (j > -1 && v[j] > v[j + 1] && dp[j] <= dp[j + 1]){
					dp[j] = dp[j + 1] + 1;
				}
			}
		}
		int ret = 0;
		for (auto data : dp){
			ret += data;
		}
		return ret;
	}
	//子序列2^n
	void subSerial(vector<int>& v, int i, vector<int>& ret){
		if (i == v.size()){
			for (auto& d : ret){
				cout << d << " ";
			}
			cout << endl;
			return;
		}
		ret.push_back(v[i]);
		subSerial(v, 1 + i, ret);
		ret.pop_back();
		subSerial(v, 1 + i, ret);
	}
	//字组合
	void subCombinations(vector<int>& v, int i, int k, vector<int>& ret){
		if (k == 0){
			for (auto& d : ret){cout << d << " ";}
			cout << endl;return;
		}
		for (; i <= v.size() - k; ++i){
			ret.push_back(v[i]);
			subCombinations(v, i + 1, k - 1, ret);
			ret.pop_back();
		}
	}
	//数组的波峰波谷个数
	int wiggleMaxLength(vector<int>& v){
		int count = 1;
		for (size_t i = 1; i < v.size(); /*++i*/){
			if (v[i - 1] <= v[i]){
				while (i < v.size() && v[i - 1] <= v[i]){
					++i;
				}
				++count;
				//--i;
			}
			if (i < v.size() && v[i - 1] >= v[i]){
				while (i < v.size() && v[i - 1] >= v[i]){
					++i;
				}
				++count;
				//--i;
			}
		}
		return count;
	}
	//两个依序数组中找中位数
	int getMedian(vector<int>& v1, vector<int>& v2){
		int st1 = 0;
		int en1 = (int)v1.size() - 1;
		int st2 = 0;
		int en2 = (int)v2.size() - 1;
		while (st1 < en1){
			int mid1 = (st1 + en1) / 2;
			int mid2 = (st2 + en2) / 2;
			int offset = ((en1 - st1 + 1) & 1) ^ 1;
			if (v1[mid1] > v2[mid2]){
				en1 = mid1;
				st2 = mid2 + offset;
			}else if(v1[mid1] < v2[mid2]){
				st1 = mid1 + offset;
				en2 = mid2;
			}
			else{
				return v1[mid1];
			}
		}
		return min(v1[st1],v2[st2]);
	}
};
#if 0
int main(){
	ArrayProblem AP;
	//vector<int> v{ 0,3,2, 1,1,1,1, 3, 1, 2,3 };
	//cout << AP.wiggleMaxLength(v) << endl;
	int n;
	int count = 0;
	cin >> n;
	int x = ~n;
	while (x & 0x80000000){
		x <<= 1;
		++count;
	}
	cout << (x >> count) << endl;
	return 0;
}
#endif