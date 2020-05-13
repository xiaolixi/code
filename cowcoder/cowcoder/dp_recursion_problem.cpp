#include "common.h"
//递归 vs DP
class DiGui{
public:
	int qishigongzhu_core(vector<vector<int>>& m, int i, int j){
		if (i == m.size() - 1 && j == m[0].size() - 1){
			return m[i][j];
		}
		int down = INT_MAX;
		int right = INT_MAX;
		if (i < m.size() - 1){
			down = qishigongzhu_core(m, i + 1, j);
		}
		if (j < m[0].size() - 1){
			right = qishigongzhu_core(m, i, j + 1);
		}
		return min(down, right) + m[i][j];
	}
	int qishigongzhu(vector<vector<int>>& m){
		return 1 - qishigongzhu_core(m, 0, 0);
	}
	int zifuzhuanhuan(string& str, int i){
		if (i == str.size()){
			return 1;
		}
		if (str[i] == '0'){
			return 0;
		}
		int re1 = zifuzhuanhuan(str, i + 1);
		int re2 = 0;
		if (i + 1 < str.size()){
			string s(1, str[i]);
			s += str[i + 1];
			if (stoi(s) < 27){
				re2 = zifuzhuanhuan(str, i + 2);
			}
		}
		return re1 + re2;
	}
	int zifuzhuanhuan_dp(string& str){
		vector<int> dp(str.size() + 1, 0);
		dp[str.size()] = 1;
		dp[str.size() - 1] = str[str.size() - 1] != '0' ? 1 : 0;
		for (int i = str.size() - 2; i >= 0; --i){
			int ret1 = 0;
			int ret2 = 0;
			if (str[i] != 0){
				ret1 = dp[i + 1];
				if (10 * (str[i] - '0') + (str[i + 1] - '0') < 27){
					ret2 = dp[i + 2];
				}
			}
			dp[i] = ret1 + ret2;
		}
		return dp[0];
	}
	struct ZhiPai_node{
		int A;
		int B;
	};
	ZhiPai_node zhipaiboyi(vector<int > & v, int st, int en, bool isA){
		if (st == en){
			if (isA){
				return ZhiPai_node{ v[st], 0 };
			}
			else{
				return ZhiPai_node{ 0, v[st] };
			}
		}
		ZhiPai_node xuanzuo = zhipaiboyi(v, st + 1, en, !isA);
		ZhiPai_node xuanyou = zhipaiboyi(v, st, en - 1, !isA);
		if (isA){
			int ma = max(xuanzuo.A + v[st], xuanyou.A + v[en]);
			if (ma == xuanzuo.A + v[st]){
				return ZhiPai_node{ ma, xuanzuo.B };
			}
			else{
				return ZhiPai_node{ ma, xuanyou.B };
			}
		}
		else{
			int ma = max(xuanzuo.B + v[st], xuanyou.B + v[en]);
			if (ma == xuanzuo.B + v[st]){
				return ZhiPai_node{ xuanzuo.A, ma };
			}
			else{
				return ZhiPai_node{ xuanyou.A, ma };
			}
		}
	}
	int zhipaiboyi_1(vector<int>& v){
		ZhiPai_node ret = zhipaiboyi(v, 0, v.size() - 1, 1);
		return max(ret.A, ret.B);
	}
	ZhiPai_node zhipaiboyi_digui(vector<int > & v, int st, int en, int isA){
		if (st == en){
			if ((isA & 1) == 0){
				return ZhiPai_node{ v[st], 0 };
			}
			else{
				return ZhiPai_node{ 0, v[st] };
			}
		}
		ZhiPai_node L = zhipaiboyi_digui(v, st + 1, en, isA + 1);
		ZhiPai_node R = zhipaiboyi_digui(v, st, en - 1, isA + 1);
		if ((isA & 1) == 0){
			return L.A + v[st] > R.A + v[en] ? ZhiPai_node{ L.A + v[st], L.B }
			: ZhiPai_node{ R.A + v[en], R.B };
		}
		else{
			return L.B + v[st] > R.B + v[en] ? ZhiPai_node{ L.A, L.B + v[st] }
			: ZhiPai_node{ R.A, R.B + v[en] };
		}
	}
	int zhipaiboyi_2(vector<int>& v){
		ZhiPai_node ret = zhipaiboyi(v, 0, v.size() - 1, 0);
		return max(ret.A, ret.B);
	}
	//三角形的最小路径
	int triangle(vector<vector<int>>& matrix, int i, int j){
		if (i == matrix.size() - 1){
			return matrix[i][j];
		}
		int down = triangle(matrix, i + 1, j);
		int down_right = triangle(matrix, i + 1, j + 1);
		return min(down, down_right) + matrix[i][j];
	}
	//word break
	bool wordreak(string& str, unordered_set<string> li){
		vector<bool> dp(str.size(), false);
		for (int i = 0; i < str.size(); ++i){
			if (li.find(str.substr(0, i + 1)) != li.end()){
				dp[i] = true;
			}
			else{
				for (int k = 0; k < i; ++k){
					if (dp[k] && li.find(str.substr(k + 1, i - k)) != li.end()){
						dp[i] = true;
						break;
					}
				}
			}
		}
		return dp.back();
	}
	//画匠
	int sumArr(vector<int>& v, int i, int j){
		if (i == j){
			return v[i];
		}
		return v[i] + sumArr(v, i + 1, j);
	}
	int sumArr_dp(vector<int>& v, int i, int j){
		vector<vector<int>> dp(v.size(), vector<int>(v.size(), 0));
		for (int i = 0; i < v.size(); ++i){
			for (int j = i; j > -1; --j){
				dp[i][j] = j == i ? v[i] : dp[j + 1][j] + v[j];
			}
		}
	}
	int huajinag(vector<int>&v, int num){
		vector<vector<int>> w(v.size(), vector<int>(v.size(), 0));
		for (size_t i = 0; i < v.size(); ++i){
			w[i][i] = v[i];
			for (size_t j = i + 1; j < v.size(); ++j){
				w[i][j] = w[i][j - 1] + v[j];
			}
		}

		vector<vector<int>> dp(num, vector<int>(v.size(), 0));
		dp[0] = w[0];
		for (size_t i = 1; i < num; ++i){
			for (size_t j = 0; j < v.size(); ++j){
				dp[i][j] = dp[i - 1][j];
				for (size_t k = 0; k < j; ++k){
					dp[i][j] = min(dp[i][j], max(dp[i - 1][k], w[k + 1][j]));
				}
			}
		}
		return dp[num - 1][v.size() - 1];
	}
	//邮局
	int youju(vector<int>& path, int youju){
		vector<vector<int>> w(path.size(), vector<int>(path.size(), 0));
		for (size_t i = 0; i < path.size(); ++i){
			for (size_t j = i + 1; j < path.size(); ++j){
				w[i][j] = w[i][j - 1] + path[j] - path[(i + j) / 2];
			}
		}
		vector<vector<int>> dp(youju, vector<int>(path.size(), 0));
		for (size_t j = 1; j < path.size(); ++j){
			dp[0][j] = w[0][j];
		}
		for (size_t i = 1; i < youju; ++i){
			for (size_t j = i + 1; j < path.size(); ++j){
				dp[i][j] = dp[i - 1][j];
				for (size_t k = 0; k < j; ++k){
					dp[i][j] = min(dp[i][j], dp[i - 1][k] + w[k + 1][j]);
				}
			}
		}
		return dp[youju - 1][path.size() - 1];
	}
	//歌单组合数
	int gequshu(vector<int>& v, int i, int k){
		if (i == (int)v.size()){
			return k == 0 ? 1 : 0;
		}
		return gequshu(v, i + 1, k) + gequshu(v, i + 1, k - v[i]);
	}
	int zuheshu(int i, int n){
		int ret = 1;
		for (int j = n - i + 1; j <= n; ++j){
			ret *= j;
		}
		int num = 1;
		for (int j = 1; j <= i; ++j){
			num *= j;
		}
		return ret / num;
	}
	int zuheshu(int x, int A, int y, int B, int k){
		int ret = 0;
		for (int i = 0; i <= x && i <= k / A; ++i){
			if ((k - A*i) % B == 0 && (k - A*i) / B <= y){
				ret += zuheshu(i, x) * zuheshu((k - A*i) / B, y);
			}
		}
		return ret;
	}
	//str是否是str1和str2的交叉组成
	bool iszucheng(string& str1, string str2, string& str){
		vector<vector<bool>> dp(str1.size() + 1, vector<bool>(str2.size() + 1, false));

		for (int i = 1; i < (int)(str2.size()); ++i){
			dp[0][i] = str[i] == str2[i] ? true : false;
		}
		for (int i = 1; i < (int)(str1.size()); ++i){
			dp[0][i] = str[i] == str2[i] ? true : false;
		}

		for (int i = 1; i < (int)(str1.size()); ++i){
			for (int j = 1; j < (int)(str2.size()); ++j){
				if ((dp[i][j - 1] == true && str2[j] == str[i + j])
					|| (dp[i - 1][j] == true && str1[i] == str[i + j])){
					dp[i][j] = true;
				}
			}
		}
		return dp[str1.size()][str2.size()];
	}
	//party的最大活跃度
	struct StaffNode{
		StaffNode(){}
		int value;//活跃度
		set<int> nexts;//下级
	};
	struct MaxHappyReturnData{
		MaxHappyReturnData(int l, int b) :laiMax(l), buMax(b){}
		int laiMax;//来引起的最大活跃度
		int buMax;//不来引起的最大活跃度
	};
	MaxHappyReturnData max_happy(vector<StaffNode>& v, int i){
		if (v[i].nexts.empty()){
			return MaxHappyReturnData{ v[i].value, 0 };
		}
		vector<MaxHappyReturnData> ne;
		for (auto next : v[i].nexts){
			ne.push_back(max_happy(v, next));
		}
		MaxHappyReturnData ret{ v[i].value, 0 };
		for (auto& data : ne){
			ret.laiMax += data.buMax;
			ret.buMax += max(data.buMax, data.laiMax);
		}
		return ret;
	};
	int getmax_happy(){
		int n;
		cin >> n;
		int head = 0;
		vector<StaffNode> v(n, StaffNode());
		for (int i = 0; i < n; ++i){
			int value;
			int up;
			cin >> up >> value;
			v[i].value = value;
			if (i == up){
				head = i;
			}
			else{
				v[up].nexts.insert(i);
			}
		}
		MaxHappyReturnData ret = max_happy(v, head);
		cout << max(ret.laiMax, ret.buMax) << endl;
		return  max(ret.laiMax, ret.buMax);
	}
	//最大搜索二叉树的节点数
	struct Tree{
		int value;
		Tree* left;
		Tree* right;
	};
	struct MaxSerachBinaryTreeNode{
		bool is_search;
		int count;
		int left_min;
		int right_max;
		//MaxSerachBinaryTreeNode(){}
	};
	MaxSerachBinaryTreeNode get_max_serach_binary_tree_node_sum(Tree* head){
		if (head == nullptr){
			MaxSerachBinaryTreeNode{ true, 0, INT_MAX, INT_MIN };
		}
		MaxSerachBinaryTreeNode left = get_max_serach_binary_tree_node_sum(head->left);
		MaxSerachBinaryTreeNode right = get_max_serach_binary_tree_node_sum(head->right);
		if (left.is_search == true && right.is_search == true
			&& head->value > left.right_max && head->value < right.left_min){
			return MaxSerachBinaryTreeNode{ true, 1 + left.count + right.count,
				min(left.left_min, head->value), max(left.right_max, head->value) };
		}
		else{
			return MaxSerachBinaryTreeNode{ false, max(left.count, right.count),
				INT_MIN, INT_MAX };
		}
	}
	//判断二叉树是否是平衡二叉树
	struct BalanceReturnData{
		bool is_balance;
		int height;
	};
	BalanceReturnData is_balance_tree(Tree* head){
		if (head == nullptr){
			return BalanceReturnData{ true, 0 };
		}
		BalanceReturnData left = is_balance_tree(head->left);
		BalanceReturnData right = is_balance_tree(head->right);
		if (left.is_balance && right.is_balance && abs(left.height - right.height) <= 1){
			return BalanceReturnData{ true, max(left.height, right.height) + 1 };
		}
		else{
			return BalanceReturnData{ false, 0 };
		}
	}
	//树节点的最大距离
	struct MaxDistanceReturnData{
		int height;
		int distance;
	};
	MaxDistanceReturnData get_max_distance(Tree* head){
		if (head == nullptr){
			return MaxDistanceReturnData{ 0, 0 };
		}
		MaxDistanceReturnData left = get_max_distance(head->left);
		MaxDistanceReturnData right = get_max_distance(head->right);
		MaxDistanceReturnData ret{ max(left.height, right.height) + 1, left.height + right.height + 1, };
		if (ret.distance < left.distance){
			ret.distance = left.distance;
		}
		else if (ret.distance < right.distance){
			ret.distance = right.distance;
		}
		return ret;
	}
	//换钱的方法数
	int get_manoy_count(vector<int>& v, int i, int aim){
		if (aim == 0){
			return 1;
		}
		if (i == (int)v.size()){
			return 0;
		}
		int ret = 0;
		for (int zhang = 0; zhang <= aim / v[i]; ++zhang){
			ret += get_manoy_count(v, i + 1, aim - zhang*v[i]);
		}
		return ret;
	}
	int get_manoy_combination(vector<int>& v, int i, int aim, vector<int>& path){
		if (aim == 0){
			for (auto& data : path){
				cout << data << " ";
			}
			cout << endl;
			return 1;
		}
		if (i == (int)v.size()){
			return 0;
		}
		int ret = 0;
		for (int zhang = 0; zhang <= aim / v[i]; ++zhang){
			for (int j = 0; j < zhang; ++j){ path.push_back(v[i]); }
			ret += get_manoy_combination(v, i + 1, aim - zhang*v[i], path);
			for (int j = 0; j < zhang; ++j){ path.pop_back(); }
		}
		return ret;
	}
	int get_manoy_combination_once(vector<int>& v, int i, int aim, vector<int>& path){
		if (aim == 0){
			for (auto& data : path){
				cout << data << " ";
			}
			cout << endl;
			return 1;
		}
		if (i == (int)v.size()){
			return 0;
		}
		int ret = 0;
		ret += get_manoy_combination_once(v, i + 1, aim, path);
		path.push_back(v[i]);
		ret += get_manoy_combination_once(v, i + 1, aim - v[i], path);
		path.pop_back();
		return ret;
	}
	//字符串IP地址数
	int get_string_IP_count(string& str, int i, int k){
		if (k == 4){
			if ((str[i] == '0' && i != (int)str.size() - 1)
				|| stoi(str.substr(i)) > 255){
				return 0;
			}
			else{
				return 1;
			}
		}
		if (str[i] == '0'){
			return get_string_IP_count(str, i + 1, k + 1);
		}
		else{
			int sum = 0;
			int ret = 0;
			for (int index = i; index < (int)str.size() - 1; ++index){
				sum = sum * 10 + str[i] - '0';
				if (sum <= 255){
					ret += get_string_IP_count(str, index + 1, k + 1);
				}
				else{
					break;
				}
			}
			return ret;
		}
	}
	//字符串IP地址
	void get_string_IP(string& str, int i, int k, vector<int>& path){
		if (k == 3){
			if ((str[i] == '0'&& i != (int)str.size() - 1) || (stoi(str.substr(i)) > 255)){
				return;
			}
			else{
				stringstream s;
				s << path[0] << '.' << path[1] << '.' << path[2] << '.' << str.substr(i);
				cout << s.str() << endl;
				return;
			}
		}
		else if (str[i] == '0'){
			path.push_back(0);
			get_string_IP(str, i + 1, k + 1, path);
			path.pop_back();
		}
		else{
			int num = 0;
			for (int j = i; j < i + 3 && j < (int)str.size(); ++j){
				num = num * 10 + str[j] - '0';
				if (num < 256){
					path.push_back(num);
					get_string_IP(str, j + 1, k + 1, path);
					path.pop_back();
				}
			}
		}
	}
	//产生正确的匹配括号
	//int genenate_parenthess(int n, int l,int r, string& str){
	//
	//	return 0;
	//}
	//数组的子数组最大值-最小值<=aim的个数
	int get_aim_sum(vector<int>& v, int aim){
		vector<vector<int>> dpMax(v.size(), vector<int>(v.size(), 0));
		vector<vector<int>> dpMin(v.size(), vector<int>(v.size(), 0));
		int res = 0;
		for (size_t i = 0; i < v.size(); ++i){
			for (size_t j = i; j < v.size(); ++j){
				if (j == i){
					dpMax[i][j] = v[j];
					dpMin[i][j] = v[j];
				}
				else{
					dpMax[i][j] = max(dpMax[i][j - 1], v[j]);
					dpMin[i][j] = min(dpMin[i][j - 1], v[j]);
				}
				res = dpMax[i][j] - dpMin[i][j] <= aim ? res + 1 : res;
			}
		}
		return res;
	}
	//子序列和为aim
	void sub_serial_sum_is_aim(vector<int>& v, int i, int sum, int aim, vector<int>& path){
		if (i == v.size()){
			if (sum == aim){
				for (auto data : path){
					cout << data << " ";
				}
				cout << endl;
			}
			return;
		}
		sub_serial_sum_is_aim(v, i + 1, sum, aim, path);
		path.push_back(v[i]);
		sub_serial_sum_is_aim(v, i + 1, sum + v[i], aim, path);
		path.pop_back();
	}
	//n二进制中1的个数
	int count_one(int i){
		unsigned n = (unsigned)i;
		n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
		n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
		n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
		n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
		n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
		return (int)n;
	}
	int binary_one_count(int n){
		int count = 0;
		for (int i = 1; i <= n; ++i){
			count += count_one(i);
		}
		cout << count << endl;
		count = 0;
		vector<int> v(n + 1, 0);
		for (int i = 1; i <= n; ++i){
			v[i] = v[i&(i - 1)] + 1;
			count += v[i];
		}
		cout << count << endl;
		return count;
	}

};

class Perumtation{
public:
	//排列
	void arrangement(string s, int i){
		if (i == s.size()){
			cout << s << endl;
			return;
		}
		for (int j = i; j < s.size(); ++j){
			swap(s[i], s[j]);
			arrangement(s, i + 1);
			swap(s[i], s[j]);
		}
	}
	//组合
	void combination(string str, int i, string res){
		if (i == str.size()){
			cout << res << endl;
			return;
		}
		combination(str, i + 1, res + str[i]);
		combination(str, i + 1, res);
	}
	//随机重排列
	void my_random_shffle(vector<int>& v, int first, int last){
		if (last - first <= 0){
			return;
		}
		for (int i = first + 1; i <= last; ++i){
			swap(v[i], v[rand() % (i - first + 1)]);
		}
	}
	//n个元素取k个的组合
	void combinatons(vector<int>& v, int k, int i, vector<int>& result){
		if (result.size() == k){
			for (auto& data : result){ cout << data << " "; }
			cout << endl;
			return;
		}
		if (i == v.size()){
			return;
		}
		combinatons(v, k, i + 1, result);
		result.push_back(v[i]);
		combinatons(v, k, i + 1, result);
		result.pop_back();
	}
	//下一个排列（字典序变大）
	void nextpermutation_cycle(vector<int>& v){
		int n = (int)v.size();
		if (n < 2){
			return;
		}
		int left = n - 2;
		int right = n - 1;
		while (1){
			if (v[left] < v[right]){
				int j = n - 1;
				while (!(v[left] < v[j])){ --j; }
				swap(v[left], v[j]);
				reverse(v.begin() + right, v.end());
				break;
			}
			if (left == 0){
				reverse(v.begin(), v.end());
				break;
			}
			--left, --right;
		}
		for (auto& data : v){
			cout << data << " ";
		}
		cout << endl;
	}
	//上一个排列（字典序变小）
	void prevpermutation_cycle(vector<int>& v){
		int n = (int)v.size();
		if (n < 2){
			return;
		}
		int left = n - 2;
		int right = n - 1;
		while (1){
			if (v[left] > v[right]){
				int j = n - 1;
				while (!(v[left] > v[j])){ --j; }
				swap(v[left], v[j]);
				reverse(v.begin() + right, v.end());

				break;
			}
			if (left == 0){
				reverse(v.begin(), v.end());
				break;
			}
			--left, --right;
		}
		for (auto& data : v){
			cout << data << " ";
		}
		cout << endl;
	}
	//子序列和的下标集合
	void subserialsum(vector<int>& v, size_t i, int sum, vector<int>& subserial, unordered_multimap<int, vector<int>>& hmmap){
		if (i == v.size()){
			hmmap.insert(make_pair(sum, subserial));
			return;
		}
		subserialsum(v, i + 1, sum, subserial, hmmap);
		subserial.push_back(i);
		subserialsum(v, i + 1, sum + v[i], subserial, hmmap);
		subserial.pop_back();
	}
	//和为aim的子序列
	void sub_serial_sum_is_aim(vector<int>& v, size_t i, int aim, vector<int>& subserial){
		if (aim == 0 && subserial.size() != 0){
			for (auto& index : subserial){ cout << v[index] << " "; }
			cout << endl;
			return;
		}
		if (i == v.size() || aim < 0){
			return;
		}
		sub_serial_sum_is_aim(v, i + 1, aim, subserial);
		subserial.push_back(i);
		sub_serial_sum_is_aim(v, i + 1, aim-v[i], subserial);
		subserial.pop_back();
	}
	////有相同元素的排列(v需要先排序）	
};
#if 0
int main(){
	
	Perumtation P;
	vector<int> ret;
	//P.combinatons(v, 2, 0, ret);
	//vector<int> v{ 10,1,2,7,6,1,5};
	//P.sub_serial_sum_is_aim(v, 0, 8, ret);
	return 0;
}
#endif
#if 0
int main(){
	DiGui DG;
	DG.binary_one_count(10);
	//string str("25525511135");
	//vector<int> path;
	//DG.get_string_IP(str, 0, 0, path);
	//DG.getmax_happy();
	//vector<int> v{10,1,2,7,6,1,5 };
	//vector<int> path;
	//cout << DG.get_manoy_combination(v, 0, 15,path) << endl;
	//cout << DG.get_manoy_combination_once(v, 0, 8, path) << endl;
	//string str("25525511135");
	//cout << DG.get_string_IP_count(str, 0, 1) << endl;
	//string str;
	//cout << DG.genenate_parenthess(3, 0, 0,str) << endl;
	//vector<int> v{ 1, 2, 3, 5, 94, 97, 98, 99, 100 };
	//vector<int> path;
	//DG.sub_serial_sum_is_aim(v, 0, 0, 100, path);
	//int i = -1;
	//unsigned b = i;
	//cout << i << " " << b << endl;
	//cout << DG.count_one(i) << endl;
	return 0;
}
#endif

//int main_1(){
//
//	//cout << "------------ArrayProblem------------ " << endl;
//	//ArrayProblem AP;	
//	//vector<int> vap{ 1,2,3,4 };
//	//vector<int> vret;
//	////AP.subSerial(vap, 0, vret);
//	////AP.subCombinations(vap, 0, 2, vret);
//	//cout << "------------StringProblem------------ " << endl;
//	//StringProblem SP;
//	//string sret;
//	//SP.digistStringMeaing(string("2389"), 0, sret);
//	//cout << SP.count << endl;
//
//	//cout << SP.stringLongestHuiWenSub(string("adcbag"), 0, 5) << endl;
//
//	//cout << SP.stringLongestHuiWenSub_dp(string("dbag")) << endl;
//
//	//cout << "------------DiGuiProblem------------ " << endl;
//	//DiGui DG;
//	//vector<vector<int>> spmatrix{ { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } };
//	//cout << DG.triangle(spmatrix, 0, 0) << endl;
//	//string word("leetcode");
//	//unordered_set<string> li;
//	//li.insert("leet");
//	//li.insert("code");
//	//li.insert("cod");
//	//cout << DG.wordreak(word, li) << endl;
//
//	//vector<int> youjuv{ 1, 2, 3, 4, 5, 1000 };
//	//cout << DG.youju(youjuv, 2) << endl;
//
//	//vector<int> huajiangv{1,1,1,4,3};
//	//cout << DG.huajinag(huajiangv, 2) << endl;
//
//	//vector<int> zhipaiv{ 1, 100, 2 };
//	//cout << DG.zhipaiboyi_2(zhipaiv) << endl;
//
//	//cout << "------------TreeProblem------------ " << endl;
//	//TreeProblem TP;
//	//SearchBinary SB;
//	//vector<int> v{ 1, 3, 5, 6 };
//	//cout << SB.binSearch_lower(v, 0) << endl;
//	//cout << SB.binSearch_upper(v, 0) << endl;
//	//TP.preOrder();
//	//cout << TP.isBST(TP.root).is_bst<<endl;
//	//cout << TP.minDepth(TP.root) << endl;
//	//cout << TP.maxDepth(TP.root) << endl;
//	//cout << TP.sumNumbers(TP.root,0) << endl;
//	//vector<int> pre{ 6,4,3,5,8 };
//	//vector<int> in{ 3,4,5,6,8};
//	//vector<int> pos{ 3,5,4,8,6};
//	//TreeProblem::Tree* h = TP.buildTreePreIn(pre, 0, 4, in, 0, 4);
//	//TP.root = h;
//	//TP.preOrder();
//	/*TreeProblem::Tree* h = TP.buildTreePosIn(pos, 0, 4, in, 0, 4);
//	TP.root = h;
//	TP.preOrder();*/
//	//TreeProblem::Tree* h = TP.buildTreePrePos(pre, 0, 4, pos, 0, 4);
//	//TP.root = h;
//	//TP.preOrder();
//	//cout << "------------HeapProblm------------ " << endl;
//	//vector<int> v1{1, 2, 3, 4, 5};
//	//vector<int> v2{ 3, 5, 7, 9, 11 };
//	//HeapProblm HP;
//	//vector<int> v = HP.topKSum(v1, v2, 4);
//
//	//vector<int> v1{ 1, 1, 1, 0, 1 };
//	//vector<int> v2{ 1, 0, 1, 1, 1 };
//	//vector<int> v3{ 1, 0, 1, 1, 1 };
//	//vector<int> v4{ 1, 1, 1, 1, 1 };
//	//vector<vector<int>> m{ v1, v2, v3, v4 };
//	//cout << AP.minPathValue(m,0,0) << endl;
//	/*vector<int> v{1,1,2,3,5,3,2,2};
//	cout<< AP.tangguo(v) << endl;*/
//	//TreeProblem TP;
//	//vector<int> v;
//	//TP.havePathSumisAim(TP.root,8,0,v);
//	//vector<int> v{ 3, 1, 2 };
//	//sort(v.begin(), v.end());
//	//vector<int> v1{9,9,4};
//	//vector<int> v2{6,6,8};
//	//vector<int> v3{2,1,1};
//	//vector<vector<int>> m{ v1, v2, v3 };
//	//cout << AP.longestIncPath(m) << endl;
//	//cout << AP.longestIncPath_dp(m) << endl;
//	//StringProblem SP;
//	//string str("-3*5");
//	//cout << SP.calcExpress(str, 0).value << endl;
//	//TreeProblem m;
//	//cout << m.longestPath(m.root, 8) << endl;	
//	//vector<int> v{ 3, -2, 5 };
//	//vector<int> ret;
//	//ArrayProblem m;
//	//m.sumIsAim_path(v, 0, 0, 6, ret);
//	//vector<int> v{ 3, -2, 5, 0, 0 , 1 };
//	//DullAtack m;
//	//m.getLeftBigAndRightBig(v);
//	//ArrayProblem m;
//	//vector<char> v1{ 'a', 'b', 'c', 'e' };
//	//vector<char> v2{ 's', 'f', 'c', 's' };
//	//vector<char> v3{ 'a', 'd', 'e', 'e' };
//	//vector<vector<char>> v{ v1, v2, v3 };
//	//string str("bcced");
//	//string str2("abcb");
//	//cout << m.havePathInMatrix(v, str2);
//
//
//	//vector<int> v1{-2,3,3};
//	//vector<int> v2{-5,-10,1};
//	//vector<int> v3{0,30,-5};
//	//vector<vector<int>> v{ v1, v2, v3 };
//	//cout << m.qishigongzhu(v);
//	//string str("10");
//	//cout << m.zifuzhuanhuan(str, 0) << endl;
//	//cout << m.zifuzhuanhuan_dp(str) << endl;
//	//vector<int> v{ 1,2, 100, 4 };
//	//cout << m.zhipaiboyi_1(v) << endl;
//	//StringProblem SP;
//	//string str = "aaabbcddi";
//	//cout << SP.togjizifuchuan(str) << endl;
//
//	/*int num, lu;
//	cin >> num >> lu;
//	unordered_map<int, Node_Lu> map_ph;
//	for (int i = 1; i <= num; ++i){
//		int v;
//		cin >> v;
//		map_ph[i] = Node_Lu{ v, 0, 0, vector<int>() };
//	}
//	for (int i = 0; i < lu; ++i){
//		int chu;
//		int ru;
//		cin >> chu >> ru;
//		map_ph[chu].chudeg++;
//		map_ph[chu].nexts.push_back(ru);
//		map_ph[ru].rudeg++;
//	}
//	Return_Node max_path_sum{ 0, 0 };
//	for (auto head : map_ph){
//		deque<int> dq;
//		if (head.second.rudeg == 0){
//			Return_Node temp = find_lu(head.first, dq, map_ph);
//			max_path_sum.value = max(max_path_sum.value, temp.value);
//			max_path_sum.count += temp.count;
//		}
//	}
//	cout << max_path_sum.count << " " << max_path_sum.value << endl;
//
//
//*/
//
//	//map<int, int> m;
//	//m.insert(make_pair(1, 9));
//	//m.insert(make_pair(2, 9));
//	//m.insert(make_pair(1, 0));
//	//for (auto& d : m){
//	//	cout << d.first << " " << d.second << endl;
//	//}
//	return 0;
//}
////struct Node_Lu{
////	int value;
////	int rudeg;
////	int chudeg;
////	vector<int> nexts;
////};
//////struct int{	
//////	int key;
//////	int value;
//////};
////struct Return_Node{
////	int value;
////	int count;
////};
////Return_Node find_lu3(int key, deque<int>& d, unordered_map<int, Node_Lu>& m){	
////	d.push_back(m[key].value);
////	Return_Node max_path_sum{ 0, 0 };
////	if (m[key].nexts.empty()){
////		int curMax = 0;
////		auto it = d.begin();	
////		curMax += *it;
////		++it;
////		while (it != d.end()){
////			curMax += *it;			
////			++it;			
////		}
////		cout << endl;
////		max_path_sum.value = curMax;
////		max_path_sum.count = 1;
////	}
////	
////	for (auto nextkey : m[key].nexts){
////		Return_Node temp = find_lu3(nextkey, d, m);
////		max_path_sum.value = max(max_path_sum.value, temp.value);
////		max_path_sum.count += temp.count;
////	}
////	d.pop_back(); 
////	return max_path_sum;
////}
////Return_Node find_lu(int key, deque<int>& d, unordered_map<int, Node_Lu>& m){	
////	d.push_back(m[key].value);
////	if (m[key].nexts.empty()){
////		int curMax = 0;
////		auto it = d.begin();	
////		curMax += *it;
////		++it;
////		while (it != d.end()){
////			curMax += *it;
////			
////			++it;			
////		}
////		cout << endl;
////		d.pop_back();
////		return Return_Node{ curMax, 1 };
////
////	}
////	Return_Node max_path_sum{ 0, 0 };
////	for (auto nextkey : m[key].nexts){
////		Return_Node temp = find_lu(nextkey, d, m);
////		max_path_sum.value = max(max_path_sum.value, temp.value);
////		max_path_sum.count += temp.count;
////	}
////	d.pop_back(); 
////	return max_path_sum;
////}
//int mainAP(){
//	/*ArrayProblem AP;
//	vector<int> v{ 1, 3, 4, 5, 2, 6 };
//	cout << AP.lengestIncSubSerial(v);*/
//
//	/*LRU l(3);
//	l.set(string("first"), 1);
//	l.set(string("second"), 2);
//	l.set(string("three"), 3);
//	l.print();
//	cout << endl;
//	l.set(string("four"), 4);
//	l.print();
//
//	cout << endl;
//	l.get(string("three"));
//	l.print();*/
//
//	//DiGui m;
//	/*string str1("AB");
//	string str2("12");
//	string str("02AB");
//	cout << m.iszucheng(str1, str2, str) << endl;*/
//
//	/*vector<int> v{ 1, 1, 2, 2 };
//	cout << m.gequshu(v, 0, 3) << endl;
//	cout << m.zuheshu(2, 1, 2, 2, 3) << endl;*/
///*
//	StringProblem sp;
//	cout << sp.longestHuiwenSubStr(string("1233200899787")) << endl;
//*/
//	return 0;
//}