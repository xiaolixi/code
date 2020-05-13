#include "common.h"

class Observer{
public:
	virtual void get_update(string& msg) = 0;
};

class Li : public Observer{
	string m_name;
public:
	Li(string s) :m_name(s){}
	string& get_name(){
		return m_name;
	}
	void get_update(string& msg) {
		cout << get_name() << "得到新的订阅消息 ";
		cout << msg << endl;
	}
};

class Fa : public Observer{
	string m_name;
public:
	Fa(string s) :m_name(s){}
	string& get_name(){
		return m_name;
	}
	void get_update(string& msg) {
		cout << get_name() << "得到新的订阅消息 ";
		cout << msg << endl;
	}
};

class Subject{
	vector<Observer*> m_v;
	string m_s;
	void notify(){
		for (auto& i : m_v){
			i->get_update(m_s);
		}
	}
public:
	void add(Observer* o){
		m_v.push_back(o);
	}
	void set_state(string& s){
		m_s = s;
		notify();
	}	
};
#include <set>
#include <sstream>

void print2Sum(vector<int>& v, int left,int right,int sum,set<string>& s){	
	int temp = left;
	left++;
	while (left < right){
		if (v[left] + v[right] == sum){
			stringstream sst;
			sst << v[temp] << ' ' << v[left] << ' ' << v[right] << ' ';
			string str(sst.str());
			if (s.find(str) == s.end()){
				s.insert(str);
				cout << v[temp] << ' ' << v[left] << ' ' << v[right] << endl;
			}
			while (left < right && v[left + 1] == v[left]){
				++left;
			}
			++left;
			while (left < right && v[right - 1] == v[right]){
				--right;
			}
			--right;
		}
		else if (v[left] + v[right] > sum){
			--right;
		}
		else{
			++left;
		}

	}
}
void print3Sum(vector<int>& v, int sum){
	set<string> s;
	for (int i = 0; i < (int)v.size()-2; ++i){
		if (v[i] != v[i + 1] || i == ((int)v.size() - 3) || v[i] != v[i+3] ){
			print2Sum(v, i, (int)(v.size() - 1), sum - v[i],s);
		}
	}
}

void print2Sum(vector<int>& v,int sum){
	int left = 0;
	int right = (int)v.size() - 1;
	while (left < right){
		if (v[left] + v[right] == sum){
			cout << v[left] << " " << v[right] << endl;
			while (left < right && v[left + 1] == v[left]){
				++left;
			}
			++left;
			while (left < right && v[right - 1] == v[right]){
				--right;
			}
			--right;
		}
		else if (v[left] + v[right] > sum){
			--right;
		}
		else{
			++left;
		}

	}
}
int main(){
	Observer* o1 = new Li(string("li"));
	Observer* o2 = new Fa(string("fa"));
	Subject s;
	s.add(o1);
	s.add(o2);

	s.set_state(string(".................."));

	vector<int> v{ 1, 2, 2, 2, 2, 2, 2, 3, 3, 4, 4, 4, 5 };
	//print2Sum(v, 7);
	print3Sum(v, 6);
}