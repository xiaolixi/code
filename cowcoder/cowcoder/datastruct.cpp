#include "common.h"
template<class T>
class  UnionSet{
public:
	typedef typename T type;
private:
	map<type, type> fatherMap;
	map<type, int> sizeMap;
	type& findFather(type& str){
		type& father = fatherMap[str];
		if (father == str){
			return father;
		}
		else{
			father = findFather(father);
			fatherMap[str] = father;
			return father;
		}
	}
public:
	UnionSet(){
		fatherMap.clear();
		sizeMap.clear();
	}
	void makeSets(vector<type>& v){
		for (auto& data : v){
			fatherMap[data] = data;
			sizeMap[data] = 1;
		}
	}
	bool isSameSet(type& str1, type& str2){
		return findFather(str1) == findFather(str2);
	}
	type& unionSet(type& str1, type& str2){
		type& st1 = findFather(str1);
		type& st2 = findFather(str2);
		if (st1 == st2){
			return st1;
		}
		else{
			int size1 = sizeMap[st1];
			int size2 = sizeMap[st2];
			if (size1 <= size2){
				fatherMap[st1] = st2;
				sizeMap[st2] = size1 + size2;
				return st2;
			}
			else{
				fatherMap[st2] = st1;
				sizeMap[st1] = size1 + size2;
				return st1;
			}
		}
	}
};
class LRU{
public:
	LRU(int s) :size(0), capacity(s){}
	~LRU(){
		for (auto& node : doublelist){
			delete node;
		}
	}
	void set(string s, int d){
		if (hashtable.count(s) == 0){
			if (count() == capcacity()){
				earse(--doublelist.end());
			}
			_Node* temp = new _Node(s, d);
			doublelist.push_front(temp);
			hashtable.insert(make_pair(s, doublelist.begin()));
			++size;
		}
		else{
			(*hashtable[s])->value = d;		
			doublelist.splice(doublelist.begin(), doublelist, hashtable[s]);
		}
	}
	int get(string s){
		if (hashtable.count(s) != 0){
			doublelist.splice(doublelist.begin(), doublelist, hashtable[s]);
			return doublelist.front()->value;
		}
		return INT_MIN;
	}
	void print(){
		for (auto& node : doublelist){
			cout << "key " << node->key << " value " << node->value << endl;
		}
	}
	int count(){
		return size;
	}
	int capcacity(){
		return capacity;
	}
	bool isExistence(string key){
		return (hashtable.count(key) != 0);
	}
private:
	class _Node{
	public:
		string key;
		int value;
		_Node(string s, int d) :key(s), value(d){}
		~_Node(){ cout << " deconstor _node " << endl; }
	};
	unordered_map<string, list<_Node*>::iterator> hashtable;
	list<_Node*> doublelist;
	int size;
	int capacity;
	void earse(list<_Node*>::iterator iter){
		if (iter != doublelist.end()){
			string key = (*iter)->key;
			_Node* del = (*iter);
			doublelist.erase(iter);
			hashtable.erase(key);
			delete del;
			--size;
		}
	}
};
class Tire{
	class TireNode{
	public:
		TireNode(){
			passed = 0;
			ended = 0;
			memset(map, 0, sizeof(TireNode*) * 26);
		}
		int passed;
		int ended;
		TireNode* map[26];
	};
private:
	TireNode root;
public:
	Tire() :root(){}
	~Tire(){
		for (int i = 0; i < 26; ++i){
			dfsdelete(root.map[i]);
		}
	}
	void dfsdelete(TireNode* node) {
		if (node == 0){
			return;
		}
		for (int i = 0; i < 26; ++i){
			if (node->map[i] != 0){
				dfsdelete(node->map[i]);
			}
		}
		delete node;
	}
	void insert(string str){
		TireNode* node = &root;
		for (size_t i = 0; i < str.size(); ++i){
			int index = str[i] - 'a';
			if (node->map[index] == 0){
				node->map[index] = new TireNode();
			}
			node = node->map[index];
			node->passed++;
		}
		node->ended++;
	}
	bool search(string str){
		TireNode* node = &root;
		for (int i = 0; i < str.size(); ++i){
			int index = str[i] - 'a';
			if (node->map[index] == 0){
				return 0;
			}
			node = node->map[index];
		}
		return 1;
	}
	void deleteString(string str){
		TireNode* node = &root;
		if (search(str)){
			for (int i = 0; i < str.size(); ++i){
				int index = str[i] - 'a';
				if (node->map[index]->passed-- == 1){
					TireNode* del = node->map[index];
					node->map[index] = 0;
					for (int j = i + 1; j < str.size(); ++j){
						TireNode* temp = del->map[str[j] - 'a'];
						memset(del, 0, sizeof(TireNode));
						delete del;
						del = temp;
						//del->passed--;
					}
					del->ended = 0;
					delete del;
					return;
				}
				node = node->map[index];
			}
			node->ended--;
		}
	}
	int prefixNumber(string str){
		TireNode* node = &root;
		for (int i = 0; i < str.size(); ++i){
			int index = str[i] - 'a';
			if (node->map[index] == 0){
				return 0;
			}
			node = node->map[index];
		}
		return node->passed;
	}
};
class Graph{
private:
	class Node;
	class Edge{
	public:
		int widght;
		Node* from;
		Node* to;
		Edge(int w, Node* f, Node* t){
			widght = w;
			from = f;
			to = t;
		}
	};
	class Node{
	public:
		int value;
		int out;
		int in;
		vector<Node*> nexts;
		vector<Edge*> edges;
		Node(int v){
			value = v;
			out = 0;
			in = 0;
			nexts.clear();
			edges.clear();
		}
	};
	unordered_map<int, Node*> nodes;
	unordered_set<Edge*> edges;
public:
	template< typename T >
	class EdgeComp{
	public:
		typedef typename T type;
		bool operator()(const type* e1, const type* e2){
			return e1->widght > e2->widght;
		}
	};
	set<Edge* > prim(){
		set<Node*> s;
		priority_queue<Edge*, vector<Edge*>, EdgeComp<Edge> > pq;
		Node* node = nodes.begin()->second;
		s.insert(node);
		for (auto e : node->edges){
			pq.push(e);
		}
		set<Edge* > ret;
		while (!pq.empty()){
			Edge* e = pq.top(); pq.pop();
			if (s.find(e->to) == s.end()){
				ret.insert(e);
				s.insert(e->to);
				for (auto nexte : e->to->edges){
					pq.push(nexte);
				}
			}
		}
		return ret;
	}
	//选择边中最小的放入ret中（用unionset保证没有形成环)
	set<Edge*> kruskal(){
		UnionSet<Node*> US;
		vector<Node* > v;//节点加入到US
		for (auto& n : nodes){
			v.push_back(n.second);
		}
		US.makeSets(v);

		priority_queue < Edge*, vector<Edge*>, EdgeComp<Edge>> pq;
		for (auto edge : edges){
			pq.push(edge);
		}
		set<Edge*> ret;
		while (!pq.empty()){
			Edge* e = pq.top(); pq.pop();
			if (!US.isSameSet(e->from, e->to)){
				ret.insert(e);
				US.unionSet(e->from, e->to);
			}
		}
		return ret;
	}
	void DFS(Node* n){
		stack<Node* > s;
		set<Node* > se;
		s.push(n);
		se.insert(n);
		cout << n->value << endl;
		while (!s.empty()){
			Node* cur = s.top(); s.pop();
			for (auto it : cur->nexts){
				if (se.find(it) == se.end()){
					s.push(cur);
					s.push(it);
					se.insert(it);
					cout << it->value << endl;
					break;
				}
			}
		}
	}
	void BFS(Node* node){
		set<Node*> s;
		queue<Node*> q;
		q.push(node);
		s.insert(node);
		while (!q.empty()){
			Node* t = q.front(); q.pop();
			cout << t->value << endl;
			for (auto it : t->nexts){
				if (s.find(it) == s.end()){
					q.push(it);
					s.insert(it);
				}
			}
		}
	}
	void createGraph(vector<vector<int>>& matrix){
		for (int i = 0; i < matrix.size(); ++i){
			int from = matrix[i][0];
			int to = matrix[i][1];
			int weight = matrix[i][2];
			if (nodes.find(from) == nodes.end()){
				nodes.insert(make_pair(from, new Node(from)));
			}
			if (nodes.find(to) == nodes.end()){
				nodes.insert(make_pair(to, new Node(to)));
			}
			Node* fromNode = nodes[from];
			Node* toNode = nodes[to];
			Edge* newEdge = new Edge(weight, fromNode, toNode);
			edges.insert(newEdge);

			fromNode->out++;
			toNode->in++;
			fromNode->nexts.push_back(toNode);
			fromNode->edges.push_back(newEdge);
		}
	}
	vector<Node*> topologysort(){
		unordered_map<Node*, int> inmap;
		queue<Node*> q;
		for (auto& node : nodes){
			if ((inmap[node.second] = node.second->in) == 0){
				q.push(node.second);
			}
		}
		vector<Node*> result;
		while (!q.empty()){
			Node* cur = q.front(); q.pop();
			result.push_back(cur);
			for (auto& node : cur->nexts){
				if (--inmap[node] == 0){
					q.push(node);
				}
			}
		}
		return result;
	}
	struct Distrance {		
		int value;
		bool visit;
		string path;
		Distrance() {
			visit = false;
			value = INT_MAX;
			path = "";
		}
	};
	void Dijkstra(int begin){
		size_t nodenum = nodes.size();
		vector<Distrance> dis(nodenum + 1, Distrance());
		for (auto& next : nodes[begin]->edges){
			dis[next->to->value].value = next->widght;
			dis[next->to->value].path = to_string(begin) + "-->" + to_string(next->to->value);
		}
		dis[begin].value = 0;
		dis[begin].path = "self";
		dis[begin].visit = true;
		
		size_t count = 1;
		while (count != nodenum) {			
			size_t temp = 0;
			int min = INT_MAX;
			for (size_t i = 1; i <= dis.size();i++) {
				if (!dis[i].visit && dis[i].value < min) {
					min = dis[i].value;
					temp = i;
				}
			}
			dis[temp].visit = true;
			++count;
			vector<Edge*> ne = nodes[temp]->edges;
			for (auto& it : ne){
				int tonum = it->to->value;
				if (dis[tonum].visit == false
					&& dis[temp].value + it->widght < dis[tonum].value){
					dis[tonum].value = dis[temp].value + it->widght;
					dis[tonum].path = dis[temp].path + "-->" + to_string(tonum);
				}
			}			
		}		
	}
	bool ishaveCircle(){
		map<int, int> inMap;
		queue<int> zeroInQueue;
		for (auto& d : nodes){
			inMap[d.first] = d.second->in;
			if (inMap[d.first] == 0){
				zeroInQueue.push(d.first);
				inMap.erase(d.first);
			}
		}
		while (!zeroInQueue.empty()){
			int c = zeroInQueue.front(); zeroInQueue.pop();
			for (auto node : nodes[c]->nexts){
				inMap[node->value]--;
				if (inMap[node->value] == 0){
					zeroInQueue.push(node->value);
					inMap.erase(node->value);
				}
			}
		}
		return inMap.size() == 0;
	}
};


class SparseVector{
public:
	SparseVector(){}
	SparseVector(vector<double>& v){
		for (int i = 0; i < (int)v.size(); ++i){
			if (!(v[i] < EPS && v[i] > -EPS)){
				m_spare_vector.insert(make_pair(i, v[i]));
			}
		}
	}
	double get(int i)const{	
		return m_spare_vector.count(i) == 0 ? 0.0 : static_cast<unordered_map<int, double>>(m_spare_vector)[i];
	
	}
	double dot_mutliply(const SparseVector& v)const {
		double ret = 0.0;
		if (v.m_spare_vector.size() > m_spare_vector.size()){			
			for (auto& data : v.m_spare_vector){
				ret += data.second * get(data.first);
			}			
		}
		else{
			for (auto& data : m_spare_vector){
				ret += data.second * v.get(data.first);
			}
		}
		return ret;
	}
private:
	unordered_map<int, double> m_spare_vector;
	static double EPS;
};
double SparseVector::EPS = 1e-9;
class Huffman{
private:
	struct HuffmnNode{
		HuffmnNode(char ch, int value){
			this->ch = ch;
			this->value = value;
			left = nullptr;
			right = nullptr;
		}
		char ch;
		int value;
		struct HuffmnNode* left;
		struct HuffmnNode* right;
	};
public:
	struct Comp{
		bool operator()(const pair<int, HuffmnNode*>& x, const pair<int, HuffmnNode*>& y){
			return x.first > y.first;
		}
	};
	void generate_huffman(vector<pair<char, int>>& v){
		priority_queue<pair<int, HuffmnNode*>, vector<pair<int, HuffmnNode*>>, Comp> pq;
		for (auto& data : v){
			HuffmnNode* temp = new HuffmnNode(data.first, data.second);
			pq.push(make_pair(data.second, temp));
		}
		while (pq.size() != 1){
			auto tp1 = pq.top(); pq.pop();
			auto tp2 = pq.top(); pq.pop();
			HuffmnNode* temp = new HuffmnNode(' ', tp1.first+tp2.first);
			temp->left = tp1.second;
			temp->right = tp2.second;			
			pq.push(make_pair(tp1.first + tp2.first, temp));
		}
		m_root = pq.top().second;
		generate_encode(m_root,string(""));
	}
	void generate_encode(HuffmnNode* head,string& str){
		if (head->left == nullptr && head->right == nullptr){
			m_char_to_encode.insert(make_pair(head->ch, str));
			return;
		}
		if (head->left != nullptr){
			str.push_back('0');
			generate_encode(head->left, str);
			str.pop_back();
		}
		if (head->right != nullptr){
			str.push_back('1');
			generate_encode(head->right, str);
			str.pop_back();
		}
	}
	string encode(string& str){
		string ret;
		for (auto ch : str){
			ret += m_char_to_encode[ch];
		}
		return ret;
	}
	string decode(string& encode){
		string ret;
		for (size_t i = 0; i < encode.size(); /*++i*/){
			HuffmnNode* temp = m_root;
			while (temp->left != nullptr && temp->right != nullptr){
				temp = encode[i] == '0' ? temp->left : temp = temp->right;				
				++i;
			}
			ret.push_back(temp->ch);
		}
		return ret;
	}
private:
	HuffmnNode* m_root;
	unordered_map<char, string> m_char_to_encode;
	//unordered_map<string, char> m_encode_to_char;
};

#if 0

int main(){

	LRU l(3);
	l.set(string("1"), 1);
	l.set(string("2"), 2);
	l.set(string("3"), 3);
	l.print();
	l.set(string("4"), 4);
	l.print();
	l.get(string("4"));
	l.print();
	l.set(string("4"), -4);
	l.print();
	//ShortURL m;
	//cout << m.encode(string("http://go.microsoft.com/fwlink")) << endl;
	//string str = m.encode(string("http://go.microsoft.com/fwlink"));
	//cout << str << endl;
	//cout << m.decode(string("http://gi.mi/gsggfgk")) << endl;
	//cout << m.decode(str) << endl;
	//vector<double> v{ 1, 2, 0, 0, 0, 1.1 };
	//SparseVector v1(v);

	//vector<double> vv{ 0, 0, 1.230, 4.40, 0, 1.1 };
	//SparseVector v2(vv);

	//cout << v1.dot_mutliply(v2) << endl;

	//unordered_map<int, double> v;
	//v.insert(make_pair(1, 2.2 ));
	//int i = 1;
	//cout << v[i];
	//Huffman m;
	//vector<pair<char, int>> v{ { 'a', 10 }, { 'b', 20 }, { 'c', 50 }, { 'd', 90 } };
	//m.generate_huffman(v);
	//string encode = m.encode(string("babccd"));
	//cout << encode << endl;
	//cout << m.decode(encode) << endl;
	return 0;
}

#endif