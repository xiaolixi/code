#include "common.h"

class Greedy{
public:
	bool s_is_subserial_t(string& s, string& t){
		size_t i = 0, j = 0;
		while (i < s.size() && j < t.size()){
			s[i] == t[j] ? ++i: 0;
			++j;
		}
		return i == s.size();
	}
};
#if 0
int main(){
	//vector<int> v{ 1, 3, 2, 2, 1, 1 };
	Greedy G;
	string s("abc");
	string t("adhddgjbgsdgs");
	cout << G.s_is_subserial_t(s, t) << endl;
	return 0;
}
#endif