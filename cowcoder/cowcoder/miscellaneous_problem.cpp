#define _CRT_SECURE_NO_WARNINGS

#include "3.h"


class MyComp{
public:
	bool operator()(const pair<char, int>& x, const pair<char, int>& y){
		if (x.first > y.first){
			return true;
		}
		else if (x.first == y.first){
			return x.second < y.second;
		}
		else{
			return false;
		}
	}
};


string fun(string& str){
	string ret;
	vector<pair<char, int>> v;
	for (size_t i = 0; i < str.size(); ++i){
		v.push_back(make_pair(str[i], i));
	}
	sort(v.begin(), v.end(), MyComp());
	ret.push_back(v[0].first);
	for (size_t i = 1; i < str.size(); ++i){
		if (v[i].second > v[i - 1].second){
			ret.push_back(v[i].first);
		}
	}
	return ret;
}
int gcd(int x, int y){
	return y == 0 ? x : gcd(y, x%y);
}

int len(string& str){
	map<char, vector<int>> m;
	size_t f = 0;
	for (size_t i = 0; i < str.size(); ++i){
		if (str[i] != str[f]){
			m[str[f]].push_back(i - f);
			f = i;
		}
	}
	m[str[f]].push_back(str.size() - f);
	int count = 0;
	for (auto& data : m){
		int sigsum = 0;
		int g = 0;
		for (int length : data.second){
			sigsum += length;
			g = (g == 0 )? length : gcd(g, length);
		}
		count += sigsum / g;
	}
	printf("%.2f", str.size()*1.0 / count);
	return 0;
}

class MyCompPoPo{
public:
	bool operator()(const tuple<int, int, string>& x, const tuple<int, int, string>& y){
		if (std::get<0>(x) < std::get<0>(y)){
			return false;
		}
		else if (std::get<0>(x) > std::get<0>(y)){
			return true;
		}
		else{//==
			if (std::get<1>(x) > std::get<1>(y)){
				return true;
			}
			else if (std::get<1>(x) == std::get<1>(y)){
				return std::get<2>(x) < std::get<2>(y);
			}
			else{
				return false;
			}
		}
	}
};

void popo(){
	unordered_map<string,pair<int, int>> m;//在线、身份
	m[string("123")] = make_pair(0, 1);
	m[string("223")] = make_pair(0, 0);
	m[string("3")] = make_pair(1, 1);
	m[string("23")] = make_pair(1, 2);
	vector<tuple<int, int, string>> v;// status, rank, name
	for (auto& data : m){
		v.push_back(make_tuple(data.second.second, data.second.first, data.first));
	}
	sort(v.begin(), v.end(), MyCompPoPo());
	cout << endl;
}



int getneedtishu(vector<int>& v){
	if (v.empty()){ return 3; }
	sort(v.begin(), v.end());
	int haved = 1;
	int ret = 0;
	for (int i = 1; i < (int)v.size(); ++i){
		if (v[i] - v[i - 1] <= 10){
			if (++haved == 3){
				if (++i >= v.size()){
					break;
				}
				haved = 1;
			}
		}
		else{
			ret += 3 - haved;
			haved = 1;
		}
	}
	return ret + 3 - haved;
}
//int main(){
	//mainAP();
	//main1();
	//main2();
	//main_90();
	//main_1();
	//main3();
	//main3h();
	//mainCCPP();
	//cout << fun(string("bzgcdb")) << endl;
	//cout << fun(string("test")) << endl;
	//cout << len(string("aaabbaaac")) << endl;
	//printf("%.2f\n", 0.1256);
	//printf("%.2f\n", 0.1256);
	//popo();
	//vector<int> v{ 1,2,3 };
	//cout << getmaxvalue(v) << endl;
	//cout << getmaxvalue2(v) << endl;
//	return 0;
//}

// range heap example
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int main() {
//	int myints[] = { 10, 20, 30, 5, 15 };
//	vector<int> v(myints, myints + 5);
//	cout << "before sorted range :";
//	for (unsigned i = 0; i<v.size(); i++) cout << " " << v[i];
//	cout << endl;
//	vector<int>::iterator it;
//
//	make_heap(v.begin(), v.end());
//	cout << "initial max heap   : " << v.front() << endl;
//
//	pop_heap(v.begin(), v.end()); v.pop_back();
//	cout << "max heap after pop : " << v.front() << endl;
//
//	v.push_back(99); push_heap(v.begin(), v.end());
//	cout << "max heap after push: " << v.front() << endl;
//
//	sort_heap(v.begin(), v.end());
//
//	cout << "final sorted range :";
//	for (unsigned i = 0; i<v.size(); i++) cout << " " << v[i];
//
//
//
//	return 0;
//}
