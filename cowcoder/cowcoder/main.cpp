//
#include "common.h"
#if 1
//牛顿迭代法和二分法sqrt
double sqrt_my(int n, double init){
	double ret = (init*init + n) / (2.0 * init);
	while (abs(ret - init) > 0.0001){
		init = ret;
		ret = (init*init + n) / (2.0 * init);
	}
	return ret;
}
double sqrt_my(int n, double initx, double inity){
	double ret = 0;
	while (abs(initx - inity) > 0.0001){
		ret = (initx + inity) / 2;
		ret*ret > n ? inity = ret : initx = ret;
	}
	return ret;

}
//坐标点逆时针旋转alpha
pair<double, double> ratate_unclickwire(pair<double, double>x, pair<double, double> y, double alpha){

	pair<double, double> ret;
	
	ret.first = (x.first - y.first)*cos(alpha) - (x.second - y.second)*sin(alpha) + y.first;
	ret.second = (x.first - y.first)*sin(alpha) + (x.second - y.second)*cos(alpha) + y.second;
	return ret;
}
//坐标点顺时针旋转alpha
pair<double, double> ratate_clickwire(pair<double, double>x, pair<double, double> y, double alpha){
	pair<double, double> ret;
	ret.first = (x.first - y.first)*cos(alpha) + (x.second - y.second)*sin(alpha) + y.first;
	ret.second = -(x.first - y.first)*sin(alpha) + (x.second - y.second)*cos(alpha) + y.second;
	return ret;
}
//将字符串以制定分隔符分割成string数组
/////////////也可以用scanf自动分割,用string构造格式串
vector<string> split_string_to_string(string& str, char delim){
	stringstream s(str);
	vector<string> ret;
	string temp;
	while (getline(s, temp, delim)){
		ret.push_back(temp);
	}return ret;
}
//将字符串以制定分隔符分割成int数组
vector<int> split_string_to_int(string& str, char delim){
	stringstream s(str);
	vector<int> ret;
	string temp;
	while (getline(s, temp, delim)){
		ret.push_back(stoi(temp));
	}
	return ret;
}
//买股票
//转圈打印矩阵
void print_cycle(vector<vector<int>>& matrix, int i, int j, int m, int n){
	for (int k = i; k <= n - 1 - i;++k){
		cout << matrix[i][k] << " ";
	}
	for (int k = i + 1; k < m - 1 - i; ++k){
		cout << matrix[k][n - 1 - i] << " ";
	}
	for (int k = n - 1 - i; m - 1 - i != i && k >= j; --k){
		cout << matrix[m - 1 - i][k] << " ";
	}
	for (int k = m - 1 - i - 1; i != j && k > i; --k){
		cout << matrix[k][i] << " ";
	}
}
void spiralmatrix(vector<vector<int>>& matrix){
	int m = (int)matrix.size();
	int n = (int)matrix[0].size();
	int index = (min(n, m) + 1) / 2;
	for (int i = 0; i < index; ++i){
		print_cycle(matrix, i, i, m, n);
	}
}

void ratate_point_unclockwise_90(vector<vector<int>>& matrix, int i){
	int tempy = matrix[i][1] - matrix[i][3];
	int tempx = matrix[i][0] - matrix[i][2];
	matrix[i][0] = -tempy + matrix[i][2];
	matrix[i][1] = tempx + matrix[i][3];
}
long distance2(vector<vector<int>>& matrix, int i, int j){
	return (matrix[i][0] - matrix[j][0]) * (matrix[i][0] - matrix[j][0])
		+ (matrix[i][1] - matrix[j][1]) * (matrix[i][1] - matrix[j][1]);
}
bool is_squre(vector<vector<int>>& matrix){
	long dist2[5] = { 0 };
	dist2[0] = distance2(matrix, 0, 1);
	dist2[1] = distance2(matrix, 1,2);
	dist2[2] = distance2(matrix, 2,3);
	dist2[3] = distance2(matrix, 0, 3);
	dist2[4] = distance2(matrix, 0, 2);
	sort(dist2, dist2 + 5);
	if (dist2[0] == 0){
		return false;
	}
	else if (dist2[0] == dist2[1]
		&& dist2[0] == dist2[2]
		&& dist2[0] == dist2[3]
		&& 2 * dist2[0] == dist2[4]){
		return true;
	}
	return false;
}
int min_ratate_num(vector<vector<int>>& matrix){
	int min_count = INT_MAX;
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 4; ++j){
			for (int k = 0; k < 4; ++k){
				for (int l = 0; l < 4; ++l){
					if (is_squre(matrix)){
						min_count = min(min_count, i + j + k + l);
					}
					ratate_point_unclockwise_90(matrix, 3);
				}
				ratate_point_unclockwise_90(matrix, 2);
			}
			ratate_point_unclockwise_90(matrix, 1);
		}
		ratate_point_unclockwise_90(matrix, 0);
	}
	return min_count == INT_MAX ? -1 : min_count;
}

#endif

//}
////
////class  UnionSet{
////public:
////	
////private:
////	map<int, int> fatherMap;
////	map<int, int> sizeMap;
////	int m_size;
////	int findFather(int str){
////		int father = fatherMap[str];
////		if (father == str){
////			return father;
////		}
////		else{
////			father = findFather(father);
////			fatherMap[str] = father;
////			return father;
////		}
////	}
////public:
////	UnionSet(){
////		fatherMap.clear();
////		sizeMap.clear();
////	}
////	void makeSets(int n){
////		for (int i = 1; i <= n;++i){
////			fatherMap[i] = i;
////			sizeMap[i] = 1;
////			m_size = n;
////		}
////	}
////	bool isSameSet(int str1, int str2){
////		return findFather(str1) == findFather(str2);
////	}
////	int unionSet(int str1, int str2){
////		int st1 = findFather(str1);
////		int st2 = findFather(str2);
////		if (st1 == st2){
////			return st1;
////		}
////		else{
////			int size1 = sizeMap[st1];
////			int size2 = sizeMap[st2];
////			if (size1 <= size2){
////				fatherMap[st1] = st2;
////				sizeMap[st2] = size1 + size2;
////				--m_size;
////				return st2;
////			}
////			else{
////				fatherMap[st2] = st1;
////				sizeMap[st1] = size1 + size2;
////				--m_size;
////				return st1;
////			}
////		}		
////	}
////	int mmmm(vector<pair<int, int>>& v){
////		for (auto& data : v){
////			unionSet(data.first, data.second);
////		}
////		return m_size;
////	}
////};
//
//class Ta{
//public:
//	void process(multimap<int,int>& multim, int k){
//		vector<pair<int, int>> v;
//		int mivalue = multim.rbegin()->first - multim.begin()->first;
//		int tempmivalue = 0;
//		int count = k;
//		while (count != 0 && mivalue != 0){
//			--count;
//			auto first = *multim.begin();
//			auto last = *multim.rbegin();
//			//cout << last.second << first.second << endl;
//			v.push_back(make_pair(last.second, first.second));
//			multim.erase(--multim.end());
//			multim.erase(multim.begin());
//			multim.insert(make_pair(first.first + 1, first.second));
//			multim.insert(make_pair(last.first - 1, last.second));
//			tempmivalue = mivalue;
//			mivalue = min(mivalue, multim.rbegin()->first - multim.begin()->first);			
//		}
//		cout << mivalue << " " << k - count << endl;
//		for (auto& data : v){
//			cout << data.first << " " << data.second << endl;
//		}
//	}
//};
//

#define PI 3.14159265

int getbit(int n, int i){
	return (((unsigned int) n) & (1 << i)) >> i;
}

void setbit(int& n, int i, int value){	
	if (value == 0){
		n &= ((int)(1 << i) ^ 0xffffffff);
	}
	else{
		n |= (value << i);
	}
}
void reversebit(int& n){
	int size = sizeof(int) * 8;
	int i = 0;
	int j = 31;
	while (i < j){
		int ibit = getbit(n, i);
		int jbit = getbit(n, j);
		setbit(n, 31-i, ibit);
		setbit(n, 31-j, jbit);
		++i;
		--j;
	}
}
double four_round_five_in(double d, int num){
	int n = 10;
	for (int i = 1; i < num; ++i){n *= 10;}
	d *= n;
	d += 0.5;
	d = floor(d);
	d /= n;
	return d;
}

vector<int> lessequalnum(vector<int>& v){
	vector<int> ret;
	ret.push_back(0);
	for (int i = 1; i < (int)v.size(); ++i){
		int temp = v[i];
		int j = i - 1;
		for (; j > -1 && v[j] > temp; --j){
			v[j + 1] = v[j];
		}
		v[j + 1] = temp;
		ret.push_back(j + 1);
	}
	for (auto& d : ret){ cout << d << endl; }
	return ret;
}
class Singlation{
public:
	static Singlation* get_instance(){
		if (m_s == nullptr){
			m_s = new Singlation;
		}
		return m_s;
	}
	static void free_instance(){
		if (m_s != nullptr){
			delete m_s;
			m_s = nullptr;
		}
	}
private:
	static Singlation* m_s;
	Singlation(){}
	Singlation(const Singlation&);
};

Singlation* Singlation::m_s=nullptr;
//class A{
//public:
//	A(){
//		v = 100;
//		b1 = 0x10;
//	}
//	virtual void f1(){
//		cout << "virtual void f1()" << endl;
//	}
//private:
//	int v;
//	char b1;
//};
//
//class B :virtual public A{
//public:
//	B(){
//		b2 = 0x10;
//	}
//	virtual void f2(){
//		cout << "virtual void f2()" << endl;
//	}
//private:
//	char b2;
//};
//class C :virtual public A{
//public:
//	C(){
//		c1 = 0x10;
//	}
//	virtual void fc(){
//		cout << "virtual void fc()" << endl;
//	}
//private:
//	char c1;
//};
//
//class D:public B,public C{
//public:
//	D(){
//		n = 0x00;
//	}
//	virtual void fd(){
//		cout << "virtual void fd()" << endl;
//	}
//private:
//	int n;
//};
//typedef union {
//	unsigned int ip;
//	unsigned char ch[4];
//}IntChar;


//class Cop{
//public:
//	virtual void operation() = 0;
//	~Cop(){}
//};
//class BeCopeople : public Cop{
//public:
//	virtual void operation(){
//		cout << " 黄皮肤 " << endl;
//	}
//};
//class Decorator :public Cop{
//public:
//	Decorator(Cop* p) :m_p(p){}
//	virtual void operation() = 0;
//protected:
//	Cop* m_p;
//};
//class Zhuang1 : public Decorator{
//public:
//	Zhuang1(Cop* p) :Decorator(p){}
//	virtual void operation(){
//		cout << " 白色T恤 " << endl;
//		m_p->operation();
//	}
//};
//class Zhuang2 : public  Decorator{
//public:
//	Zhuang2(Cop* p) :Decorator(p){}
//	virtual void operation(){
//		cout << " 黑色外套 " << endl;
//		m_p->operation();
//	}
//};
//class ifile{
//public:
//	unordered_set<ifile*> m_set;
//	string m_name;
//public:
//	ifile(string str) :m_name(str){}
//	virtual void show() = 0;
//	virtual void add(ifile* f) = 0;
//	virtual void del() = 0;
//};
//class file :public ifile{
//	
//public:
//	file(string str) :ifile(str){}
//	virtual void show(){
//		cout << m_name << endl;
//	}
//	virtual void add(ifile* f){}
//	virtual void del(){}
//};
//class dfile :public ifile{
//public:
//	dfile(string str) :ifile(str){}
//	virtual void show(){
//		cout << m_name << endl;
//	}
//	virtual void add(ifile* f){
//		m_set.insert(f);
//	}
//	virtual void del(){//未完成delete
//		for (auto& d : m_set){
//			if (d->m_set.empty()){
//				delete d;
//				m_set.erase(d);
//			}
//			else{
//				d->del();
//			}
//		}
//	}
//};


int f(int x, int k){
	int y = 0;
	for (int j = 0; j < k; ){
		++y; 
		if ((y & x) == 0){
			++j;
		}
	}
	cout << y << endl;
	cout << (x + y == (x | y)) << endl;
	return y;
}

//数组的子序列问题
class ArraysubSrial{
public:
	//最长公共子序列
	string longestCommSubserial(string& str1, string& str2){
		vector<vector<int>> dp(str1.size(), vector<int>(str2.size(), 0));
		dp[0][0] = str1[0] == str2[0] ? 1 : 0;
		for (int i = 1; i < (int)str2.size(); ++i){
			 dp[0][i] = max(dp[0][i - 1], str1[0] == str2[i] ? 1 : 0);
		}
		for (int i = 1; i < (int)str1.size(); ++i){
			dp[i][0] = max(dp[i-1][0], str1[i] == str2[0] ? 1 : 0);
		}
		int m = (int)str1.size() - 1;
		int n = (int)str2.size() - 1;
		int len = dp[m][n]-1;
		string ret(len + 1, ' '); 
		while (len >= 0){
			if (m > 0 && dp[m][n] == dp[m - 1][n]){
				m -= 1;
			}
			else if (n > 0 && dp[m][n] == dp[m][n - 1]){
				n -= 1;
			}
			else{
				ret[len--] = str1[m];
				--m;
				--n;
			}
		}
		return ret;

	}
	//最长公共子数组
	string longestCommSubarray(string& str1, string str2){
		vector<vector<int>> dp(str1.size(), vector<int>(str2.size(), 0));
		for (int i = 0; i < (int)str1.size(); ++i){
			if (str1[i] == str2[0]){
				dp[i][0] = 1;
			}
		}
		for (int j = 0; j < (int)str2.size(); ++j){
			if (str1[0] == str2[j]){
				dp[0][j] = 1;
			}
		}
		for (int i = 0; i < (int)str1.size(); ++i){
			for (int j = 0; j < (int)str2.size(); ++j){
				if (str1[i] == str2[j]){
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
			}
		}
		int index = 0;
		int ma = 0;
		for (int i = 0; i < (int)str1.size(); ++i){
			for (int j = 0; j < (int)str2.size(); ++j){
				if (dp[i][j] > ma){
					index = j;
					ma = dp[i][j];
				}
			}
		}
		return str2.substr(index - ma + 1, ma);
	}
	//最长递增子序列
	void longesstPlussubSrial(vector<int>& v){
		vector<int> dp(v.size(), 1);
		int index = 0;
		int len = 0;
		for (int i = 0; i < (int)v.size(); ++i){
			for (int j = i - 1; j > -1; --j){
				if (v[j] < v[i] && dp[i] < dp[j] + 1){
					dp[i] = dp[j] + 1;
				}
			}
			if (dp[i] > len){
				len = dp[i];
				index = i;
			}
		}
		vector<int> ret(len, 0);
		ret[--len] = v[index];
		for (int i = index - 1; i > -1 && len > -1; --i){
			if (dp[i] == dp[index] - 1 && v[i] < v[index]){
				ret[--len] = v[i];
				index = i;
			}
		}
		for (auto& d : ret){ cout << d << ends; }
	}
	//数组的所有递增序列
	int allPlusSubserial(vector<int>& v, int i, vector<int>& h){
		if (i >= (int)v.size()){
			int sum = 0;
			if (!h.empty()){				
				for (auto& d : h){ sum += d; cout << d << ends; }
				cout << endl;
			}
			return sum;
		}
		else{
			int ret = 0;
			ret = max(ret, allPlusSubserial(v, i + 1, h));
			if (h.empty() || h.back() < v[i]){
				h.push_back(v[i]);
				ret = max(ret, allPlusSubserial(v, i + 1, h));
				h.pop_back();
			}
			return ret;
		}
	}
	//最长连续序列
	int longestConsective1(vector<int>& v){
		sort(v.begin(), v.end());
		int first = v[0];
		int len = 1;
		int ret = 1;
		for (int i = 1; i < (int)v.size(); ++i){
			if (first != v[i] - 1){
				ret = max(ret, len);
				len = 1;
				first = v[i];
			}
			else{
				++len;
				++first;
			}
		}
		ret = max(ret, len);
		return ret;
	}
	int longestConsective2(vector<int>& v){
		set<int> s;
		for (auto d : v){
			s.insert(d);
		}
		auto it = s.begin();
		int len = 1;
		int first = *it;
		int ret = 1;
		for (++it; it != s.end(); ++it){
			if (*it == first + 1){
				++first;
				++len;
			}
			else{
				ret = max(ret, len);
				len = 1;
				first = *it;
			}
		}
		ret = max(ret, len);
		return ret;
	}
	int longestConsective3(vector<int>& v){
		unordered_map<int, int> m;
		int len = 0;
		for (int i = 0; i < (int)v.size(); ++i){
			if (m.find(v[i]) == m.end()){
				int left = m.count(v[i] - 1) == 0 ? 0 : m[v[i] - 1];
				int right = m.count(v[i] + 1) == 0 ? 0 : m[v[i] + 1];
				m[v[i]] = left + right + 1;
				m[v[i]-left] = left + right + 1;
				m[v[i]+right] = left + right + 1;
			}
			len=max(len, m[v[i]]);
		}
		return len;
	}
};

#if 0
int main(){
	//ArraysubSrial AS;
	//vector<int> v{ 2, 100, 5, 3, 6, 4, 8, 9, 7 };
	////AS.longesstPlussubSrial(v);
	//vector<int> h;
	//cout << AS.longestConsective3(v) << endl;
	
	return 0;
}
#endif











#if 0

int main(){	
	//vector<int> v{ -3, -2, 9, 7, 6, 8 };
	////cout << longestConsective2(v) << endl;

	//unordered_map<int, int> m;
	//cout << m[4];
	//cout << m.size();


	//Cop* p = new BeCopeople;
	//Decorator* d1 = new Zhuang1(p);
	//Decorator* d2 = new Zhuang2(d1);
	//d1->operation();
	//d2->operation();
//IntChar ic;
//	ofstream outfile("ip.txt");
//	//unsigned char ccc[2 * 4] = { '\0' };
//	//for (int i = 0; i < 3; ++i){
//	//	ccc[(1 << i) + 1] = '.';
//	//}
//#define SIZEN 200000
//	 //>> i/o operations here <<
//	for (int i = 0; i < SIZEN; ++i){
//		ic.ip = (unsigned int)0xFFFFFFFF * ((double)rand() / RAND_MAX);
//		outfile << (int)ic.ch[0] << '.' << (int)ic.ch[1] << '.' << (int)ic.ch[2] << '.' << (int)ic.ch[3] << '\n';
//	}
//	outfile.close();
	//cout << temp << ends;
	//ic.ip = 1;
	//unsigned char ch = ic.ch[0];
	//for (int i = 0; i < 4; ++i){
	//	cout << (int)ic.ch[i] << ends;
	//}
	//cout << (int)ic.ip << ends;
	//cout << (unsigned int) (~0) << endl;


	//Singlation* p1 = Singlation::get_instance();
	//Singlation* p2 = Singlation::get_instance();
	//Singlation d(*p2);
	//d.get_instance();
	//cout << (p1 == p2) << endl;
	//vector<int> v{ 1, 3, 5, 2, 3, 7, 9, 0 };
	//lessequalnum(v);
	//A* pa = new A();
	//delete pa;
	//A a;
	//B b;
	//C c;
	//D d;
	//a.f1();
	//void(* f)() = (void( * )()) (((int*)(*(int*)&a))[0]);
	//f();
	//cout << sizeof(A) << endl;
	//cout << sizeof(B) << endl;
	//cout << sizeof(C) << endl;
	//cout << sizeof(D) << endl;	//funt(3);
	//printa(1, 2.3, 'c', string("sd"));
	//string str("  a            b        cc        ddd         e     ");
	//cout << f_delete_blank(str) << endl;
	//cout << four_round_five_in(23.4547, 2) << endl;
	//cout << __cplusplus << endl;
	//int n = 0x80000085;
	//cout << hex << n << endl;
	//reversebit(n);
	//cout << hex << n << endl;
	//bitset<32> b(n);
	//string str = b.to_string();
	//reverse(str.begin(), str.end());
	//bitset<32> c(str);
	//int ccc = (int)c.to_ulong();
	//cout << hex << ccc << endl;
	//vector<int> v;
	//v.reserve(20);
	//cout << v.size();
	//v.resize(20);
	//cout << v.size();
	//auto it = v.begin();
	////++it;
	//auto iii = v.end();
	//--iii;
	//auto f = v.insert(++v.begin(),100);
	//cout << *f << " " << *it << " "/* << *iii << endl*/;
	//v.swap(v);
	//vector<vector<int>> matrix{ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 4, 5, 6 }, { 7, 8, 9 } };
	//spiralmatrix(matrix);
	//int n, m;
	//string str(";%d,%d");
	//scanf_s("%d,%d", &n, &m);
	//vector<int> ret;
	//ret.push_back(n); ret.push_back(m);
	//scanf_s(str.c_str(), &n, &m);
	//ret.push_back(n); ret.push_back(m);
	//scanf_s(str.c_str(), &n, &m);
	//ret.push_back(n); ret.push_back(m);
	//for (auto& data : ret){
	//	cout << data << " ";
	//}
	//vector<int> v{ 1, 2, 1, 3 };
	//vector<int> s;
	//unordered_multimap<int, vector<int>> m;
	//subserialsum(v, 0, 0, s, m);
	//for (auto& sub : m){
	//	for (auto data : sub.second){
	//		cout << data << " ";
	//	}
	//	cout << endl;
	//}

	//string str;	
	//std::getline(cin, str);
	//vector<string> ret = split_string_to_string(str, ',');
	//for (auto& data : ret){
	//	cout << data << endl;
	//}
	//vector<int> ret1 = split_string_to_int(str, ',');
	//for (auto& data : ret1){
	//	cout << data << endl;
	//}
	//vector<int> v{ 1, 2, 2, 3 };
	//for (int i = 0; i < 10; ++i){
	//	nextpermutation_cycle(v);
	//}

	//cout << endl;
	//for (int i = 0; i < 10; ++i){
	//	prevpermutation_cycle(v);
	//}
	//vector<int> v{ 1, 2, 3, 4 };
	//vector<int> ret;
	//combinatons(v, 2, 0, ret);
	//vector<int> v{ 1, 2, 3, 4, 5 };
	//my_random_shffle(v, 0, (int)v.size() - 1);
	//pair<double, double> ret = ratate_unclickwire(make_pair(1, 1), make_pair(0, 0), 90 * PI / 180);
	//cout << ret.first << " " << ret.second << endl;
	//cout << 5000000 % 4999 << endl;
	//string str("5000000");
	//cout << myMod(str, 4999);
	//int n;
	//int k;
	//cin >> n >> k;
	//multimap<int,int> multim;//堆大小、堆的编号
	//int temp = 0;
	//for (int i = 1; i <= n; ++i){
	//	cin >> temp;
	//	multim.insert(make_pair(temp, i));
	//}

	//Ta ta;
	//ta.process(multim, k);
	return 0;
}
#endif

//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <unordered_set>
//#include <fstream>
//using namespace std;
#define FILENUM 3
///* run this program using the console pauser or add your own getch, system("pause") or input loop */
class BigDataSolution {
public:
	// BKDR Hash Function
	unsigned int BKDRHash(const char *str){
		unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
		unsigned int hash = 0;
		while (*str){
			hash = hash * seed + (*str++);
		}
		return (hash & 0x7FFFFFFF);
	}

	void commURL(){
		//创建文件 
		fstream a[FILENUM];
		fstream b[FILENUM];
		for (int i = 0; i < FILENUM; ++i){
			char name[100];
			sprintf(name, "a%d.txt", i);
			a[i].open(name, std::fstream::out);
			sprintf(name, "b%d.txt", i);
			b[i].open(name, std::fstream::out);
		}
		//分散url到小文件中 
		fstream afile("a.txt", std::fstream::in);
		string str;
		while (getline(afile, str)){
			int temp = BKDRHash(str.c_str());
			a[temp%FILENUM] << str << endl;
		}
		afile.close();
		fstream bfile("b.txt", std::fstream::in);
		while (getline(bfile, str)){
			int temp = BKDRHash(str.c_str());
			b[temp%FILENUM] << str << endl;
		}
		bfile.close();
		for (int i = 0; i < FILENUM; ++i){			
			a[i].close();
			b[i].close();
		}
		for (int i = 0; i < FILENUM; ++i){
			char name[100];
			sprintf(name, "a%d.txt", i);
			a[i].open(name, std::fstream::in);
			sprintf(name, "b%d.txt", i);
			b[i].open(name, std::fstream::in);
		}

		//创建相同url的合集 
		fstream ab_comm_file("abcomm.txt", std::fstream::out);
		for (int i = 0; i < FILENUM; ++i){
			unordered_set<string> s;
			//读a[i]文件到set中 
			while (getline(a[i], str)){
				s.insert(str);
			}
			a[i].close();
			//判断b[i]文件中的url是不是在a[i]中出现过 
			while (getline(b[i], str)){
				if (s.find(str) != s.end()){
					ab_comm_file << str << endl;
				}
			}
			b[i].close();
		}
		ab_comm_file.close();
	}
};
//int main(int argc, char** argv) {
//	BigDataSolution s;
//	s.commURL();
//
//	return 0;
//}



//class Skiplist{
//public:
//	enum class SkiplistNodeType{SYS_MIN,COM,SYS_MAX};
//	struct SkiplistNode{
//		int m_value;
//		SkiplistNodeType m_type;
//		vector<SkiplistNode*> m_nexts;
//		SkiplistNode(){ m_value = INT_MIN, m_type = SkiplistNodeType::SYS_MIN, m_nexts.clear(); }
//		SkiplistNode(int v, SkiplistNodeType t){
//			m_value = v;
//			m_type = t;
//		}
//	};
//	Skiplist(){
//		m_size = 0;
//		m_maxlevel = 0;
//		srand((unsigned)(time(NULL)));
//		m_sys_min.m_nexts.push_back(new SkiplistNode(INT_MAX, SkiplistNodeType::SYS_MAX));
//	}
//	pair<SkiplistNode*, bool> find(int e){
//		SkiplistNode* iter = &m_sys_min;
//		int level = m_maxlevel;
//		while (iter->m_type != SkiplistNodeType::SYS_MAX){
//			SkiplistNode* next = iter->m_nexts[level];
//			while (next->m_type != SkiplistNodeType::SYS_MAX && next->m_value < e){
//				iter = next;
//				next = next->m_nexts[level];
//			}
//			if (next->m_type == SkiplistNodeType::SYS_MAX || next->m_value > e){
//				if (level == 0){
//					return make_pair(iter, false);
//				}
//				else{
//					--level;
//					break;
//				}
//			}
//			else{
//				return make_pair(iter, false);
//			}
//		}
//		return make_pair(iter, false);
//	}
//	pair<SkiplistNode*, bool> erase(int e){
//		pair<SkiplistNode*, bool> iter = find(e);
//		if (iter.second == false){
//			return make_pair(iter.first->m_nexts[0], false);
//		}
//		else{			
//			SkiplistNode* temp = iter.first;
//			int level = (int)(temp->m_nexts.size()) - 1;
//			SkiplistNode* del = temp->m_nexts[level];
//			while (level > -1){
//				temp->m_nexts[level] = temp->m_nexts[level]->m_nexts[level];
//				--level;
//				while (temp->m_nexts[level]->m_value != e){
//					temp = temp->m_nexts[level];
//				}
//			}
//			delete del;
//			--m_size;
//			return make_pair(temp->m_nexts[0], true);
//		}
//	}
//	pair<SkiplistNode*, bool> insert(int e){
//		pair<SkiplistNode*, bool> ret = find(e);
//		if (ret.second == true){
//			ret.second = false;
//			return ret;
//		}
//		int level = get_inesrt_level();
//		if (level <= m_maxlevel){
//			//未完成
//		}
//		else{
//			
//			SkiplistNode* newnode = new SkiplistNode(e, SkiplistNodeType::COM);
//			newnode->m_nexts.resize(level + 1);
//			++m_maxlevel; ++m_size;
//			m_sys_min.m_nexts.push_back(newnode);
//			//未完成
//		}
//		return ret;
//	}
//private:
//	int get_inesrt_level(){
//		return rand() % (m_maxlevel + 2);
//	}
//	
//	int m_size;
//	int m_maxlevel;
//	SkiplistNode m_sys_min;
//};


