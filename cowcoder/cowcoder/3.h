#include "common.h"

class StackProblem{
public:

	//好友关能否分成两个集合，集合中都不是好友
	bool parter(int n, multimap<int, int>& m, int i, set<int>& A, set<int>& B,int isSub = 0){
		for (int j = i; !m.empty() && j <= n; ++j){
			auto it = m.find(j);
			while (it != m.end()){
				int part = it->second;
				//新出现的关系
				if (A.find(j) == A.end() && B.find(j) == B.end()){
					A.find(part) == A.end() ? A.insert(j) : B.insert(j);
				}
				if ((A.find(j) != A.end() && A.find(part) != A.end())
					|| (B.find(j) != B.end() && B.find(part) != B.end())){
					return false;
				}
				else{
					A.find(j) != A.end() ? B.insert(part) : A.insert(part);
				} 
				m.erase(it);
				if (m.find(part) != m.end() && parter(n, m, part, A, B, 1) == false){
					return false;
				}
				it = m.find(j);
			}
			if (isSub == 1){
				break;
			}
		}
		return true;
	}
};
int main_90(){
	if (1){
		/*SortProblem m;
		vector<int> v{ 1, 2, 3, 4, 4, 5, 6, 7 };
		m.oddleftevenright(v);*/
		StackProblem sp;
		//cout << sp.longestVaildDui(string("((()())))))(())(()")) << endl;
		set<int> A;
		set<int> B;
		multimap<int, int> m;
		m.insert(make_pair(1, 2));
		m.insert(make_pair(1, 3));
		m.insert(make_pair(2, 5));
		m.insert(make_pair(3, 6));
		m.insert(make_pair(4, 6));
		m.insert(make_pair(5, 4));
		cout << sp.parter(6, m,1, A, B) << endl;

		for (auto a : A){
			cout << a << " ";
		}
		cout << " \n ";
		for (auto a : B){
			cout << a << " ";
		}
	}

	return 0;
	
}