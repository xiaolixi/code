#include "common.h"
class TreeProblem{
public:
	class Tree{
	public:
		int data;
		Tree* left;
		Tree* right;
		Tree(int d){
			data = d;
			left = 0;
			right = 0;
		}
	};
	Tree* root;
public:
	bool havePathSumisAim(Tree* head, int aim, int sum){
		if (head == nullptr){
			if (aim == sum){
				return true;
			}
			return false;
		}
		return havePathSumisAim(head->left, aim, sum + head->data)
			|| havePathSumisAim(head->right, aim, sum + head->data);
	}
	void havePathSumisAim(Tree* head, int aim, int sum, vector<int>& v){
		sum += head->data;
		v.push_back(head->data);
		if (aim == sum && head->left == nullptr && head->right == nullptr){
			for (auto& i : v){
				cout << i << " ";
			}
			cout << endl;
			v.pop_back();
			return;
		}
		if (head->left != nullptr){
			havePathSumisAim(head->left, aim, sum, v);
		}
		if (head->right != nullptr){
			havePathSumisAim(head->right, aim, sum, v);
		}
		v.pop_back();
	}
	void print_all_root_to_leaf_path(Tree* root, vector<int>& path){
		path.push_back(root->data);
		if (root->left == nullptr && root->right == nullptr){
			for (auto& data : path){ cout << data << " "; }
			cout << endl;
			path.pop_back();
			return;
		}
		if (root->left != nullptr){
			print_all_root_to_leaf_path(root->left, path);
		}if (root->right != nullptr){
			print_all_root_to_leaf_path(root->right, path);
		}
		path.pop_back();
	}
	TreeProblem(){
		//		6
		//	4		8
		//3		5 7		9
		root = new Tree(6);
		root->left = new Tree(4);
		root->left->left = new Tree(3);
		root->left->right = new Tree(5);
		root->right = new Tree(8);
		root->right->left = new Tree(7);
		root->right->right = new Tree(9);
	}
	void preOrder(){
		stack<Tree*> s;
		s.push(root);
		while (!s.empty()){
			Tree* cur = s.top(); s.pop();
			cout << cur->data << endl;
			if (cur->right){
				s.push(cur->right);
			}if (cur->left){
				s.push(cur->left);
			}
		}
	}
	void inOrder(){
		stack<Tree*> s;
		Tree* h = root;
		while (!s.empty() || h != nullptr){
			while (h != nullptr){
				s.push(h);
				h = h->left;
			}
			if (!s.empty()){
				h = s.top(), s.pop();
				cout << h->data << endl;
				h = h->right;
			}
		}
	}
	void postOrder(){
		stack<Tree* > s;
		stack<Tree* > s2;
		s.push(root);
		while (!s.empty()){
			Tree* t = s.top();
			s2.push(t); s.pop();
			if (t->left){
				s.push(t->left);
			}
			if (t->right){
				s.push(t->right);
			}
		}
		while (!s2.empty()){
			cout << s2.top()->data << endl;
			s2.pop();
		}
	}
	void postOrder2(){
		stack<Tree*> s;
		s.push(root);
		Tree* h = root;
		while (!s.empty()){
			Tree*  c = s.top();
			if (c->left != nullptr && h != c->left && h != c->right){
				s.push(c->left);
			}
			else if (c->right != nullptr && h != c->right){
				s.push(c->right);
			}
			else{
				cout << c->data << " ";
				s.pop();
				h = c;
			}
		}
	}
	void levelPrint(){
		queue<Tree*> q;
		q.push(root);
		int tobeprinted = 1;
		int tobeprinting = 0;
		while (!q.empty()){
			Tree* c = q.front(); q.pop();
			if (c->left != nullptr){
				q.push(c->left);
				++tobeprinting;
			}if (c->right != nullptr){
				q.push(c->right);
				++tobeprinting;
			}
			--tobeprinted;
			cout << c->data << " ";
			if (tobeprinted == 0){
				tobeprinted = tobeprinting;
				tobeprinting = 0;
				cout << endl;
			}
		}
	}
	void morrisIn(){
		Tree* cur1 = root;
		Tree* cur2 = nullptr;
		while (cur1 != nullptr){
			cur2 = cur1->left;//左孩子
			if (cur2 != nullptr){
				while (cur2->right != nullptr && cur2->right != cur1){
					cur2 = cur2->right;//左孩子的最右边孩子
				}
				if (cur2->right == nullptr){//连接
					cur2->right = cur1;
					cur1 = cur1->left;//++++++++++
					continue;
				}
				else{//删除连接
					cur2->right = nullptr;
				}
			}
			cout << cur1->data << " ";
			cur1 = cur1->right;
		}
	}
	void morrisPre(){
		Tree* cur1 = root;
		Tree* cur2 = nullptr;
		while (cur1 != nullptr){
			cur2 = cur1->left;
			if (cur2 != nullptr){
				while (cur2->right != nullptr && cur2->right != cur1){
					cur2 = cur2->right;
				}
				if (cur2->right == nullptr){
					cur2->right = cur1;
					cout << cur1->data << " ";
					cur1 = cur1->left;
					continue;
				}
				else{
					cur2->right = nullptr;
				}
			}
			cur1 = cur1->right;
		}
	}
	void printEdge(Tree* root){
		if (root == nullptr){
			return;
		}
		printEdge(root->right);
		cout << root->data << endl;
	}
	void morrisPost(){
		Tree* cur1 = root;
		Tree* cur2 = nullptr;
		while (cur1 != nullptr){
			cur2 = cur1->left;
			if (cur2 != nullptr){
				while (cur2->right != nullptr && cur2->right != cur1){
					cur2 = cur2->right;
				}
				if (cur2->right != nullptr){
					cur2->right = cur2;
					cur1 = cur1->left;
					continue;
				}
				else{
					cur2->right = nullptr;
					printEdge(cur1->left);//链表逆序
				}
			}
			cur1 = cur1->right;
		}
		printEdge(root);
	}
	void zigzagPrint(){
		deque<Tree*> d;
		int curLevel = 1;int nextLevel = 0;
		bool front_out_back_in__first_right_second_left = true;
		while (!d.empty()){
			if (front_out_back_in__first_right_second_left == true){
				Tree* temp = d.front(); d.pop_front();
				cout << temp->data << endl;
				if (temp->right!=nullptr){
					d.push_back(temp->right);++nextLevel;
				}
				if (temp->left != nullptr){
					d.push_back(temp->left);++nextLevel;
				}
			}
			else{
				Tree* temp = d.back(); d.pop_back();
				cout << temp->data << endl;
				if (temp->left != nullptr){
					d.push_back(temp->left);++nextLevel;
				}
				if (temp->right != nullptr){
					d.push_back(temp->right);++nextLevel;
				}
			}
			if (--curLevel == 0){
				front_out_back_in__first_right_second_left = !front_out_back_in__first_right_second_left;
				curLevel = nextLevel;nextLevel = 0;
			}
		}
	}
	void BSTtoDoubleLinkedList(){
		stack<Tree*> s;
		Tree* pre = nullptr;
		Tree* head = nullptr;
		Tree* h = root;
		while (!s.empty() || h != nullptr){
			while (h != nullptr){
				s.push(h);
				h = h->left;
			}
			if (!s.empty()){
				h = s.top(), s.pop();

				if (pre == nullptr){
					pre = h;
					head = h;
				}
				else{
					pre->right = h;
					h->left = pre;
					pre = h;
				}

				//cout << h->data << endl;
				h = h->right;
			}
		}
		while (head != nullptr){
			cout << head->data << " ";
			head = head->right;
		}
		cout << endl;
	}
	string serialTreePre(){
		stack<Tree*> s;
		s.push(root);
		stringstream st;
		while (!s.empty()){
			Tree* temp = s.top(); s.pop();
			temp != nullptr ? st << temp->data << "!" : st << "#!";
			if (temp){
				s.push(temp->right);
				s.push(temp->left);
			}
		}
		return st.str();
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
	Tree* reserialTreePre(string& str){
		vector<string> splitret = split_string_to_string(str, '!');
		int i = 0;
		return reserialTreePre_core(splitret,i);
	}
	Tree* reserialTreePre_core(vector<string>& splitret,int& i){
		if (splitret[i] == "#"){
			return nullptr;
		}
		Tree* root = new Tree(stoi(splitret[i]));
		root->left = reserialTreePre_core(splitret,++i);
		root->right = reserialTreePre_core(splitret,++i);
		return root;
	}

	bool isPostArray_core(vector<int>& v, int start, int end){
		if (start == end){
			return true;
		}
		int lessRight = -1;
		int moreLeft = end;
		for (int i = start; i < end; ++i){
			if (v[i] < v[end]){
				lessRight = i;
			}
			else{
				moreLeft = moreLeft == end ? i : moreLeft;
			}
		}
		if (lessRight == -1 || moreLeft == end){
			return isPostArray_core(v, start, end - 1);
		}
		if (lessRight != moreLeft - 1){
			return 0;
		}
		return isPostArray_core(v, start, lessRight) && isPostArray_core(v, moreLeft, end - 1);
	}
	bool isPostArray(vector<int>& v){
		return isPostArray_core(v, 0, v.size() - 1);
	}
	Tree* rebulidTreeByPostArray_core(vector<int>& v, int start, int end){
		if (start > end){
			return nullptr;
		}
		Tree* node = new Tree(v[end]);

		int lessRight = -1;
		int moreLeft = end;
		for (int i = start; i < end; ++i){
			if (v[end] > v[i]){
				lessRight = i;
			}
			moreLeft = moreLeft == end ? i : moreLeft;
		}

		node->left = rebulidTreeByPostArray_core(v, start, lessRight);
		node->right = rebulidTreeByPostArray_core(v, moreLeft, end - 1);
		return node;
	}
	Tree* rebulidTreeByPostArray(vector<int>& v){
		return rebulidTreeByPostArray_core(v, 0, v.size() - 1);
	}
	int longestPath(Tree* head, int sum){
		if (head->left == nullptr && head->right == nullptr){
			if (sum - head->data == 0){
				return 1;
			}
			else{
				return 0;
			}
		}
		int L = 0, R = 0;
		if (head->left){
			L = longestPath(head->left, sum - head->data);
		}
		if (head->right){
			R = longestPath(head->right, sum - head->data);
		}
		if (max(L, R) != 0){
			return max(L, R) + 1;
		}
		else{
			return 0;
		}
	}
	struct ISBST{
		int left_min;
		int right_max;
		bool is_bst;
	};
	ISBST isBST(Tree* head){
		if (head == nullptr){
			return ISBST{ INT_MAX, INT_MIN, 1 };
		}
		ISBST L = isBST(head->left);
		if (L.is_bst == false){
			return ISBST{ INT_MIN, INT_MAX, 0 };
		}
		ISBST R = isBST(head->right);
		if (R.is_bst == false || L.right_max > head->data || R.left_min < head->data){
			return ISBST{ INT_MIN, INT_MAX, 0 };
		}
		return ISBST{ min(L.left_min, head->data), max(R.right_max, head->data), 1 };
	}
	int minDepth(Tree* head){
		if (head == nullptr){
			return 0;
		}
		return min(minDepth(head->left), minDepth(head->right)) + 1;
	}
	bool isCST(){
		queue<Tree*> q;
		q.push(root);
		bool isleaf = false;
		while (!q.empty()){
			Tree* c = q.front(); q.pop();
			if ((c->right != nullptr&&c->left == nullptr)
				|| (isleaf && (c->left != nullptr || c->right != nullptr))){
				return false;
			}
			if (c->left != nullptr){
				q.push(c->left);
			}if (c->right != nullptr){
				q.push(c->right);
			}
			else{
				isleaf = true;
			}
		}
	}
	int maxDepth(Tree* head){
		if (head == nullptr){
			return 0;
		}
		return max(maxDepth(head->left), maxDepth(head->right)) + 1;
	}
	int sumNumbers(Tree* head, int sum){
		if (head == nullptr){
			return 0;
		}
		if (head->left == nullptr && head->right == nullptr){
			return sum * 10 + head->data;
		}
		return sumNumbers(head->left, 10 * sum + head->data)
			+ sumNumbers(head->right, 10 * sum + head->data);
	}
	Tree* buildTreePreIn(vector<int>& pre, int f1, int l1, vector<int>& in, int f2, int l2){
		if (f1 > l1 || f2 > l2){
			return nullptr;
		}
		Tree* h = new Tree(pre[f1]);
		int i = f2;
		for (; i <= l2; ++i){
			if (in[i] == pre[f1]){
				break;
			}
		}
		int len = i - f2;
		h->left = buildTreePreIn(pre, f1 + 1, f1 + len, in, f2, i - 1);
		h->right = buildTreePreIn(pre, f1 + len + 1, l1, in, i + 1, l2);
		return h;
	}
	Tree* buildTreePosIn(vector<int>& pos, int f1, int l1, vector<int>& in, int f2, int l2){
		if (f1 > l1 || f2 > l2){
			return nullptr;
		}
		Tree* h = new Tree(pos[l1]);
		int i = f2;
		for (; i <= l2; ++i){
			if (in[i] == pos[l1]){
				break;
			}
		}
		int len = i - f2;
		h->left = buildTreePreIn(pos, f1, f1 + len - 1, in, f2, i - 1);
		h->right = buildTreePreIn(pos, f1 + len, l1 - 1, in, i + 1, l2);
		return h;
	}
	Tree* buildTreePrePos(vector<int>& pre, int f1, int l1, vector<int>& pos, int f2, int l2){
		/*if (f1 > l1 || f2 > l2){
		return nullptr;
		}*/
		Tree* h = new Tree(pre[f1]);
		if (f1 == l1){
			return h;
		}
		int i = f2;
		for (; i <= l2; ++i){
			if (pos[i] == pre[f1 + 1]){
				break;
			}
		}
		int len = i - f2 + 1;
		h->left = buildTreePrePos(pre, f1 + 1, f1 + len, pos, f2, i);
		h->right = buildTreePrePos(pre, f1 + len + 1, l1, pos, i + 1, l2 - 1);
		return h;
	}
	int maxPathSum(Tree* head){
		if (head == nullptr){
			return 0;
		}
		int L = maxPathSum(head->left);
		int R = maxPathSum(head->right);
		return max(max(L + R + head->data, head->data), max(L + head->data, R + head->data));
	}
	bool wordBreak_recursion(string str, unordered_set<string>& s){
		if (str.empty()){
			return true;
		}
		for (size_t i = 1; i < str.size(); ++i){
			if (s.find(str.substr(0, i)) != s.end()
				&& wordBreak_recursion(str.substr(i), s)){
				return true;
			}
		}
		return false;
	}
	//构造哈弗曼树
	Tree* hafuman_tree(vector<int>& v){
		multimap<int, Tree*> m;
		for (auto data : v){
			Tree* temp = new Tree(data);
			m.insert(make_pair(data, temp));
		}
		Tree* head = nullptr;
		while (m.size() != 1){
			auto temp1 = *m.begin();
			auto temp2 = *(++m.begin());
			head = new Tree(temp1.first + temp2.first);
			head->left = temp1.second;
			head->right = temp2.second;
			m.erase(m.begin());
			m.erase(m.begin());
			m.insert(make_pair(temp1.first + temp2.first, head));
		}
		return head;
	}
	
};

#if 0
int main(){
	//vector<int> v{ 1, 3, 2, 2, 1, 1 };
	TreeProblem G;
	
	return 0;
}
#endif