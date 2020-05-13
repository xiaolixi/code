#include "common.h"

//栈
class Stack{
public:
	void getLeftBigAndRightBig(vector<int>& v){
		map<int, pair<int, int>> m;
		stack < pair<int, vector<int>> > s;

		s.push(make_pair(v[0], vector<int>(1, 0)));

		for (int i = 1; i < v.size(); ++i){
			if (s.top().first == v[i]){
				s.top().second.push_back(i);
				continue;
			}
			else if (s.top().first < v[i]){
				while (!s.empty() && s.top().first < v[i]){
					pair<int, vector<int>> c = s.top();	s.pop();
					for (auto index : c.second){
						m[index] = s.empty() ? make_pair(INT_MIN, v[i]) : make_pair(s.top().first, v[i]);
					}
				}
			}
			s.push(make_pair(v[i], vector<int>(1, i)));
		}
		while (!s.empty()){
			pair<int, vector<int>> c = s.top();	s.pop();
			for (auto index : c.second){
				m[index] = s.empty() ? make_pair(INT_MIN, INT_MIN) : make_pair(s.top().first, INT_MIN);
			}
		}
		for (auto data : v){
			cout << data << " ";
		}
		cout << endl;
		for (int i = 0; i < v.size(); ++i){
			cout << "index " << i << " 左边最近的最大 " << m[i].first
				<< " 右边最近的最大 " << m[i].second << endl;
		}
		cout << endl;
	}
	//区间最小值和区间和成绩最大的值
	int range_min_mutiply_sum_max(vector<int>& v){
		stack<int> s;
		int ret = 0;
		for (size_t i = 0; i < v.size(); ++i){
			while (!s.empty() && v[i] <= v[s.top()]){
				int mi = v[s.top()]; s.pop();
				size_t first = s.empty() ? 0 : s.top() + 1;
				int sum = 0;
				for (; first < i; ++first){
					sum += v[first];
				}
				ret = max(ret, mi*sum);
			}
			s.push(i);
		}
		while (!s.empty()){
			int mi = v[s.top()]; s.pop();
			int first = s.empty() ? 0 : s.top() + 1;
			int sum = 0;
			for (; first < v.size(); ++first){
				sum += v[first];
			}
			ret = max(ret, mi*sum);
		}
		return ret;
	}
	int range_min_mutiply_sum_max2(vector<int>& v){
		int ret = 0;
		for (size_t i = 0; i < v.size(); ++i){
			int mi = INT_MAX;
			int sum = 0;
			for (size_t j = i; j < v.size(); ++j){
				mi = min(mi, v[j]);
				sum += v[j];
				ret = max(ret, mi*sum);
			}
		}
		return ret;
	}
	//最长有效对的长度
	int longestVaildDui(string& str){
		stack<int> s;
		int ret = 0;
		for (int i = 0; i < (int)str.size(); ++i){
			if (str[i] == '(' || s.empty() || str[s.top()] == ')'){
				s.push(i);
			}
			else{
				s.pop();
				ret = max(ret, s.empty() ? i + 1 : i - s.top());
			}
		}
		return ret;
	}
	//逆波兰式
	int evalRPN(vector<string>& v){
		stack<int> s;
		for (size_t i = 0; i < v.size(); ++i){
			if (v[i].size() == 1
				&& (v[i][0] == '*' || v[i][0] == '/' || v[i][0] == '-' || v[i][0] == '+')){
				int x = s.top(); s.pop();
				int y = s.top(); s.pop();
				if (v[i][0] == '*'){ s.push(x*y); }
				else if (v[i][0] == '/'){ s.push(y / x); }
				else if (v[i][0] == '-'){ s.push(y - x); }
				else{ s.push(y + x); }
			}
			else{
				s.push(stoi(v[i]));
			}
		}
		return s.top();
	}
	int evalRPN_recursion(vector<string>& v){
		if (v.empty()){
			return 0;
		}
		string temp = v.back(); v.pop_back();
		if (temp.size() == 1
			&& (temp[0] == '*' || temp[0] == '/' || temp[0] == '+' || temp[0] == '-')){
			int x = evalRPN_recursion(v);
			int y = evalRPN_recursion(v);
			if (temp[0] == '*'){ x *= y; }
			else if (temp[0] == '/'){ y /= x; }
			else if (temp[0] == '+'){ y += x; }
			else{ y -= x; }
			return x;
		}
		else{
			return stoi(temp);
		}
	}
	//计算表达式树
	typedef struct mycalcTree{
		string v;
		struct mycalcTree* left;
		struct mycalcTree* right;
	}calcTree;

};