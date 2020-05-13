#ifndef _1_H
#define _1_H

#include "common.h"

class Node{
public:
	int value;
	Node* next;

	Node(int v){
		value = v;
		next = nullptr;
	}
};
class MergeSortXiaoshudui{
public:
	int mergeSort(int* arr, int n){
		int res = 0;
		int* help = new int[n];
		for (int k = 1; k < n; k *= 2){
			for (int left = 0; left < n; left = left + 2 * k){
				int left_end = left + k - 1;
				int right_end = left + 2 * k - 1;
				if (left_end >= n){
					left_end = n - 1;
				}
				if (right_end >= n){
					right_end = n - 1;
				}
				res += marge(arr, left, left_end, right_end, help);
			}
		}
		delete[] help;
		return res;
	}
	int marge(int* arr, int left, int left_end, int right_end, int* help){
		int res = 0;
		int i = 0;
		int a_i = left;
		int len = right_end - left + 1;
		int right = left_end + 1;
		while (left <= left_end && right <= right_end){
			if (arr[left] < arr[right]){
				res += arr[left] * (right_end - right + 1);
				help[i++] = arr[left++];
			}
			else{
				help[i++] = arr[right++];
			}
		}
		while (left <= left_end){
			help[i++] = arr[left++];
		}
		while (right <= right_end){
			help[i++] = arr[right++];
		}
		for (i = 0; i < len;){
			arr[a_i++] = help[i++];
		}
		return res;
	}
};
class MergeSortNixudui{
public:
	void mergeSort(int* arr, int n){
		int* help = new int[n];
		for (int k = 1; k < n; k *= 2){
			for (int left = 0; left < n; left = left + 2 * k){
				int left_end = left + k - 1;
				int right_end = left + 2 * k - 1;
				if (left_end >= n){
					left_end = n - 1;
				}
				if (right_end >= n){
					right_end = n - 1;
				}
				marge(arr, left, left_end, right_end, help);
			}
		}
		delete[] help;
	}
	void marge(int* arr, int left, int left_end, int right_end, int* help){
		int i = 0;
		int a_i = left;
		int len = right_end - left + 1;
		int right = left_end + 1;
		while (left <= left_end && right <= right_end){
			if (arr[left] <= arr[right]){
				help[i++] = arr[left++];
			}
			else{
				for (int ou = left; ou <= left_end; ++ou){
					cout << arr[ou] << " " << arr[right] << endl;
				}
				help[i++] = arr[right++];
			}
		}
		while (left <= left_end){			
			help[i++] = arr[left++];
			/*if (left <= left_end){
				cout << arr[left] << " " << arr[right_end] << endl;
			}*/
		}
		while (right <= right_end){
			help[i++] = arr[right++];
		}
		for (i = 0; i < len;){
			arr[a_i++] = help[i++];
		}
	}
};
class MergeSort2{
public:
	void mergeSort(int* arr, int n){
		int* help = new int[n];
		for (int k = 1; k < n; k *= 2){
			for (int left = 0; left < n; left = left + 2 * k){
				int left_end = left + k - 1;
				int right_end = left + 2*k - 1;
				if (left_end >= n){
					left_end = n - 1;					
				}
				if (right_end >= n){
					right_end = n - 1;
				}
				marge(arr, left, left_end, right_end, help);
			}
		}
		delete[] help;
	}
	void marge(int* arr, int left, int left_end, int right_end, int* help){
		int i = 0;
		int a_i = left;
		int len = right_end - left + 1;
		int right = left_end + 1;
		while (left <= left_end && right <= right_end){
			if (arr[left] < arr[right]){
				help[i++] = arr[left++];
			}
			else{
				help[i++] = arr[right++];
			}
		}
		while (left <= left_end){
			help[i++] = arr[left++];
		}
		while (right <= right_end){
			help[i++] = arr[right++];
		}
		for (i = 0; i < len; ){
			arr[a_i++] = help[i++];
		}
	}
};
class MergeSort{
public:
	void mergeSort(int* arr, int left, int right){
		if (left == right){
			return;
		}
		int mid = left + ((right - left) >> 1);
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		marge(arr, left, mid, right);
	}
	void marge(int* arr, int left, int mid, int right){
		int len = right - left + 1;
		int* help = new int[len];
		int r = mid + 1;
		int l = left;
		int i = 0;
		for (; left <= mid && r <= right;){
			if (arr[left] < arr[r]){
				help[i++] = arr[left++];
			}
			else{
				help[i++] = arr[r++];
			}
		}
		while (left <= mid){
			help[i++] = arr[left++];
		}
		while (r <= right){
			help[i++] = arr[r++];
		}
		for (int i = 0; i < len; ++i){
			arr[l++] = help[i];
		}
		delete[] help;
	}
};
class QuickSort{
public:
	void quickSort(int* arr, int left, int right){
		if (left >= right){
			return;
		}
		int pivot = partion(arr, left, right);
		quickSort(arr, left, pivot-1);
		quickSort(arr, pivot+1, right);
	}
	int partion(int* arr, int left, int right){
		int temp = arr[right];
		while (left < right){			
			while (left < right && arr[left] <= temp){ ++left; }
			while (left < right && arr[right] > temp){ --right; }//错
			if (left < right){
				arr[left] ^= arr[right];
				arr[right] ^= arr[left];
				arr[left] ^= arr[right];
				++left;
				--right;
			}
		}
		return left;
	}

	int partition2(int* arr, int left, int right){
		int temp = arr[right];
		int less = left - 1;
		while (left <= right){
			if (arr[left] <= temp){
				swap(arr[++less], arr[left]);
			}
			++left;
		}
		return less;
	}

	int partition3(int* arr, int left, int right){//荷兰国旗
		int temp = arr[right];
		int less = left - 1;
		int more = right + 1;
		while (left < more){
			if (arr[left] < temp){
				swap(arr[left++], arr[++less]);
			}
			else if (arr[left] > temp){
				swap(arr[left], arr[--more]);
			}
			else{
				++left;
			}
		}
		return less+1;
	}
};
class HeapSort{
public:
	void heapSort(int*arr, int n){
		for (int i = 1; i < n; ++i){
			insertHeap(arr, 0, i);
		}
		swap(arr[0], arr[--n]);
		while (n > 1){
			adjustyHeap(arr, 0, n);
			swap(arr[0], arr[--n]);
		}
	}

	void insertHeap(int* arr, int L, int index){
		while (index > L && arr[index] > arr[(index - 1) / 2]){
			swap(arr[index], arr[(index - 1) / 2]);
			index = (index - 1) / 2;
		}
	}
	void adjustyHeap(int* arr, int L, int heapSize){
		int leftChild = 2 * L + 1;
		while (leftChild < heapSize){
			int greatestChild = leftChild + 1 < heapSize && arr[leftChild + 1] > arr[leftChild] ? leftChild + 1 : leftChild;
			if (arr[greatestChild] > arr[L]){
				swap(arr[greatestChild], arr[L]);
				L = greatestChild;
				leftChild = 2*greatestChild + 1;
			}
			else{
				break;
			}
		}
	}
};
class Find10MinElementFromHugeData{
public:
	vector<int> find10MinElementFromHugeData(int* arr, int n){
		int heapArray[10];
		for (int i = 0; i < 10; ++i){
			heapArray[i] = arr[i];
		}
		for (int i = 1; i < 10; ++i){
			insertHeap(heapArray, 0, i);
		}
		for (int i = 10; i < n; ++i){
			swap(heapArray[0], heapArray[9]);
			adjustyHeap(heapArray, 0, 10);
			heapArray[9] = arr[i];
			insertHeap(heapArray, 0, 9);
		}
		return vector<int>(heapArray, heapArray + 10);
	}

	void insertHeap(int* arr, int L, int index){
		while (index > L && arr[index] > arr[(index - 1) / 2]){
			swap(arr[index], arr[(index - 1) / 2]);
			index = (index - 1) / 2;
		}
	}

	void adjustyHeap(int* arr, int L, int heapSize){
		int leftChild = 2 * L + 1;
		while (leftChild < heapSize){
			int greatestChild = leftChild + 1 < heapSize && arr[leftChild + 1] > arr[leftChild] ? leftChild + 1 : leftChild;
			if (arr[greatestChild] > arr[L]){
				swap(arr[greatestChild], arr[L]);
				L = greatestChild;
				leftChild = 2 * greatestChild + 1;
			}
			else{
				break;
			}
		}
	}
};
class Josephus{
public:
	Node* head;
	Josephus(){
		head = new Node(1);
		head->next = new Node(2);
		head->next->next = new Node(3);
		head->next->next->next = new Node(4);
		head->next->next->next->next = new Node(5);
		head->next->next->next->next->next = new Node(6);
		head->next->next->next->next->next->next = head;
	}

	void loop(int m){
		while (head != head->next){
			int i = 1;
			while(i < m){
				++i;
				head = head->next;
			}
			Node* del = head->next;
			cout << "killed " << head->value << endl;
			head->value = head->next->value;
			head->next = head->next->next;
			delete del;
		}
	}
};
class AdjacentMax{
public:
	int adjacentMax(int* arr, int n){
		pair<int*, int*> max_min;
		max_min = minmax_element(arr, arr + n);
		int range = (*max_min.second - *max_min.first) / (n);
		vector<set<int>> v(n + 1);
		for (int i = 0; i < n; ++i){
			v[(arr[i] - *max_min.first) / range].insert(arr[i]);
		}
		int res = 0;
		int less = *v[0].rbegin();
		for (int i = 1; i < n+1;++i ){
			if (!v[i].empty()){
				res = res > (*v[i].begin() - less) ? res : (*v[i].begin() - less);
				less = *v[i].rbegin();
			}
		}
		return res;
	}
};
class CircleQueue{
public:
	CircleQueue(int size){
		arr = new int[size + 1];
		capacity = size;
		first = 0;
		last = 0;
	}
	void push(int d){
		if ((last + 1) % capacity == first){
			cout << "full" << endl;
			return;
		}
		else{
			arr[last] = d;
			last = (last + 1) % capacity;
		}
	}
	void pop(){
		if (last == first){
			cout << "empty" << endl;
			return;
		}
		else{
			first = (first + 1) % capacity;
		}
	}

	int front(){
		if (last != first){
			return arr[first];
		}
	}
private:
	int* arr;
	int capacity;
	int first;
	int last;
};
class TwoStackToQueue{
public:
	void push(int d){
		s1.push(d);
	}
	int back(){
		dao(s2, s1);
		return s1.top();
	}
	int front(){
		dao(s1, s2);
		return s2.top();
	}
	void pop(){
		dao(s1, s2);
		s2.pop();
	}

	void dao(stack<int>& s1, stack<int>& s2){
		if (s2.empty()){
			while (!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
		}
	}
private:
	stack<int> s1;
	stack<int> s2;
};
class TwoQueueToStack{
public:
	void push(int d){
		q1.push(d);
	}
	int top(){
		q1.back();
	}
	void pop(){
		while (q1.size() > 1){
			q2.push(q1.front()); q1.pop();
		}
		q1.pop();
		q1.swap(q2);
	}
private:
	queue<int> q1; queue<int> q2;
};
class Lower_Upper_Bound{
public:
	int lower_bound(int* arr, int n,int value){
		int left = 0;
		int right = n;
		while (left < right){
			int mid = left + ((right - left) >> 1);
			if (arr[mid] < value){
				left = mid + 1;
			}
			else{
				right = mid;
			}
			}
			return left;
	}

	int upper_bound(int* arr, int n, int value){
		int left = 0;
		int right = n;
		while (left < right){
			int mid = left + ((right - left) >> 1);
			if (arr[mid] <= value){
				left = mid + 1;
			}
			else{
				right = mid;
			}
		}
		return left;
	}
};
class MidianHolder{
public:
	//MidianHolder()
	void push(int d){
		if (qgreat.empty()){
			qgreat.push(d);
		}
		else{
			if (qgreat.top() < d){
				qsmall.push(d);
				if (qsmall.size() - qgreat.size() > 1){
					qgreat.push(qsmall.top()); qsmall.pop();
				}
			}
			else{
				qgreat.push(d);
				if (qgreat.size() - qsmall.size() > 1){
					qsmall.push(qgreat.top()); qgreat.pop();
				}
			}
		}
	}
	double getMidian(){
		if (qsmall.size() == qgreat.size()){
			return (qgreat.top() + qsmall.top()) / 2.0;
		}
		else if (qsmall.size() > qgreat.size()){
			return qsmall.top();
		}
		else{
			return qgreat.top();
		}
	}
private:
	priority_queue<int, vector<int>, greater<int >> qsmall;
	priority_queue<int> qgreat;
};
class IsSum{

public:
	bool isSum(vector<int>& v, int i, int aim, int res){
		if (res == aim){
			return 1;
		}
		if (i == v.size()){
			return 0;
		}
		/*res = (res + v[i] > aim) ? res:res + v[i];*/
		return isSum(v, i + 1, aim, res) || isSum(v, i + 1, aim, res + v[i]);
	}
};
class MyList{
public:
	Node* listForwordKpath(Node* head,int n){
		for (int i = 0; i < n && head != nullptr; ++i){
			head = head->next;
		}
	}
	Node* reverseList(Node* head){
		Node* pre = 0;
		Node* next = 0;
		while (head != nullptr){
			next = head->next;
			head->next = pre;
			pre = head;
			head = next;
		}
	}

	Node* loop(Node* head){
		if (head == nullptr){
			return nullptr;
		}
		Node* fast = head;
		Node* slow = head;
		while (fast->next != nullptr && fast->next->next != nullptr){
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast){
				break;
			}
		}
		if (fast->next != nullptr && fast->next->next != nullptr){
			fast = head;
			while (slow != fast){
				fast = fast->next;
				slow = slow->next;
			}
			return slow;
		}
		else{
			return nullptr;
		}
	}
};
class PaperFoler{
public:
	void paerFlod(int i,int n, string str){
		if (i > n){
			return;
		}
		else{
			paerFlod(i + 1, n, "down");
			cout << str << endl;
			paerFlod(i + 1, n, "up");
		}
	}
};
class BinaryTree{
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
	BinaryTree(){
			//		1
			//	2		3
			//4		5 6		7
		root = new Tree(1);
		root->left = new Tree(2);
		root->left->left = new Tree(4);
		root->left->right = new Tree(5);
		root->right = new Tree(3);
		root->right->left = new Tree(6);
		root->right->right = new Tree(7);
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

	Tree* reserialTreePre(string& str){
		vector<string> splitret;
		splitString(str, '!', splitret);
		return reserialTreePre_core(splitret);
	}
	Tree* reserialTreePre_core(vector<string>& splitret){
		string data = splitret[0];
		splitret.erase(splitret.begin());
		if (data == "#"){
			return nullptr;
		}
		Tree* root = new Tree(stoi(data));
		
		root->left = reserialTreePre_core(splitret);
		root->right = reserialTreePre_core(splitret);
		return root;
	}

	string serialTreePre(){
		stack<Tree*> s;
		s.push(root);
		stringstream st;
		while (!s.empty()){
			Tree* temp = s.top(); s.pop();
			if (temp != nullptr){
				st << temp->data << "!";
			}
			else{
				st << "#!";
			}
			if (temp){
				s.push(temp->right);
				s.push(temp->left);
			}
		}
		return st.str();
	}

	Tree* unserialTreePre(string& str){
		queue<string> q;
		size_t splitFlag = 0;
		for (size_t i = 0; 
			(splitFlag = str.find_first_of('!', i)) != string::npos; i = splitFlag + 1){
			string s2(str.substr(i, splitFlag-i));
			q.push(s2);
		}
		return unserialTreePre_core(q);
	}
	Tree* unserialTreePre_core(queue<string>& q){
		string str = q.front(); q.pop();
		if (str == "#"){
			return nullptr;
		}
		Tree* node = new Tree(stoi(str));
		node->left = unserialTreePre_core(q);
		node->right = unserialTreePre_core(q);
		return node;
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
			return -1;
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
			moreLeft = moreLeft == end ? i: moreLeft;
		}
		
		node->left = rebulidTreeByPostArray_core(v, start, lessRight);
		node->right = rebulidTreeByPostArray_core(v, moreLeft, end - 1);
		return node;
	}

	Tree* rebulidTreeByPostArray(vector<int>& v){
		return rebulidTreeByPostArray_core(v, 0, v.size() - 1);
	}


	void splitString(string& str,char ch, vector<string>& ret){
		size_t start = 0;
		size_t end = 0;
		while ((end = str.find_first_of(ch, start)) != string::npos){
			ret.push_back(str.substr(start, end - start));
			start = end + 1;
		}
		if (str.substr(start, end - start) != ""){
			ret.push_back(str.substr(start, end - start));
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
				if (cur2->right != nullptr){//连接
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
				if (cur2->right != nullptr){
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
};
class GetLongestLength{
public:
	//已序数组
	int getLongestLength(vector<int>& v,int aim){
		sort(v.begin(), v.end());
		int L = 0;
		int R = 0;
		int len = 0; 
		int sum = v[L];
		while (R < v.size()){
			if (sum == aim){
				len = R - L + 1;
				break;
			}
			else if (sum > aim){
				sum -= v[L];
				++L;
			}
			else{
				++R;
				if (R == v.size()){
					break;
				}
				sum += v[R];				
			}
		}
		return len;
	}

	int getLongestLength1(vector<int>& v, int aim){
		int L = 0;
		int R = 0;
		int len = 0;
		int sum = v[L];
		while (R < v.size()){
			if (sum == aim){
				len = max(len, R - L + 1);
				sum -= v[L++];
			}
			else if (sum > aim){
				sum -= v[L++];
			}
			else{
				++R;
				if (R == v.size()){
					break;
				}
				sum += v[R];
			}
		}
		return len;
	}

	int getLongestLength2(vector<int>& v, int aim){
		int sum = 0;
		map<int, int> m;
		m.insert(make_pair(0, -1));
		int i = 0;
		int len = 0;
		while (i < v.size()){
			sum += v[i];
			if (m.find(sum - aim) != m.end()){
				len = max(len, i - m[sum - aim]);
			}
			if (m.find(sum) == m.end()){
				m.insert(make_pair(sum, i));
			}
			++i;
		}
		return len;
	}
};
class LocalMin{
public:
	int localMin(vector<int> v){
		if (v.size() ==0){
			return -1;
		}
		if (v.size() == 1 || v[0] < v[1]){
			return 0;
		}
		int last = v.size() - 1;
		if (v[last - 1]>v[last]){
			return last;
		}
		int left = 0;
		while (left < last){
			int mid = left + ((last - left) >> 1);
			if (v[mid - 1] <= v[mid]){
				last = mid;
			}
			else if (v[mid] >= v[mid + 1]){
				left = mid;
			}
			else{
				return mid;
			}
		}
		return -1;
	}
};

class TwoSum{
public:
	pair<int, int> twoSum(int* arr, int n,int aim){
		map<int, int> m;
		for (int i = 0; i < n; ++i){
			m.insert(make_pair(arr[i], i));
		}
		auto l = m.begin();
		auto r = --m.end();
		while (l != r){
			if (l->first + r->first > aim){
				--r;
			}
			else if (l->first + r->first < aim){
				++l;
			}
			else{
				return make_pair(l->second , r->second);
			}
		}
		return make_pair(-1, -1);
	}

	void sort(int* arr, int* indexs, int n){
		for (int i = 1; i < n; ++i){
			int j = i - 1;
			int temp = arr[i];
			int temp_index = indexs[i];
			for (; j >= 0 && arr[j] > temp; --j){
				arr[j + 1] = arr[j];
				indexs[j + 1] = indexs[j];
			}
			arr[j + 1] = temp;
			indexs[j + 1] = temp_index;
		}
	}
};
class WordLadder{
public:
	//["eat", "tea", "tan", "ate", "nat", "bat"]
	vector<vector<string>> group_Anagrams(vector<string> v){
		map<string, vector<string>> m;
		for (auto str : v){
			vector<int> sum(26,0);
			for (auto ch : str){
				sum[ch - 'a']++;
			}
			stringstream ss;
			for (auto count : sum){
				ss << count;
			}
			string s = ss.str();
			m[s].push_back(str);
		}
		vector<vector<string>> res;
		for (auto i : m){
			res.push_back(i.second);
		}
		return res;
	}
};
class LongestIncPath{
public:
	int maxPath(vector<vector<int>>& m){
		int imax = 0;
		vector<vector<int>> h{
			{ 0, 0, 0 },
			{ 0, 0, 0 },
			{ 0, 0, 0 }
		};
		for (int i = 0; i < m.size(); ++i){
			for (int j = 0; j < m[0].size(); ++j){
				imax = max(imax, maxInc(m, h, i + 1, j, m[i][j]) + 1);
				imax = max(imax, maxInc(m, h, i - 1, j, m[i][j]) + 1);
				imax = max(imax, maxInc(m, h, i, j + 1, m[i][j]) + 1);
				imax = max(imax, maxInc(m, h, i, j - 1, m[i][j]) + 1);
			}
		}
		return imax;
	}
	int maxInc(vector<vector<int>>& m, vector<vector<int>>& h, int i, int j, int value){
		if (i < 0 || i > m.size() - 1 || j < 0 ||
			j > m[0].size() - 1 || m[i][j] <= value){
			return 0;
		}
		if (h[i][j] == 0){
			h[i][j] = maxInc(m, h, i + 1, j, m[i][j]) + 1;
			h[i][j] = max(h[i][j],maxInc(m, h, i - 1, j, m[i][j]) + 1);
			h[i][j] = max(h[i][j], maxInc(m, h, i, j + 1, m[i][j]) + 1);
			h[i][j] = max(h[i][j], maxInc(m, h, i, j - 1, m[i][j]) + 1);
		}
		return h[i][j];
	}


	int maxPath2(vector<vector<int>>& m){
		int imax = 0;

		for (int i = 0; i < m.size(); ++i){
			for (int j = 0; j < m[0].size(); ++j){
				imax = max(imax, maxInc2(m, i, j, m[i][j]));			
			}
		}
		return imax;
	}
	int maxInc2(vector<vector<int>>& m,int i, int j, int value){
		int path = 1;

		if (i > 0 && m[i - 1][j] > value){
			path = max(path, maxInc2(m, i - 1, j, m[i - 1][j])+1);
		}
		if (i < m.size() - 1 && m[i + 1][j] > value){
			path = max(path, maxInc2(m, i + 1, j, m[i + 1][j]) + 1);
		}
		if (j > 0 && m[i][j - 1] > value){
			path = max(path, maxInc2(m, i, j - 1, m[i][j - 1]) + 1);
		}
		if (j < m[0].size() -1 && m[i][j + 1] > value){
			path = max(path, maxInc2(m, i, j + 1, m[i][j + 1]) + 1);
		}

		return path;
	}

	int maxPath3(vector<vector<int>>& m){
		int imax = 0;
		vector<vector<int>> h{
			{ 0, 0, 0 },
			{ 0, 0, 0 },
			{ 0, 0, 0 }
		};
		for (int i = 0; i < m.size(); ++i){
			for (int j = 0; j < m[0].size(); ++j){
				imax = max(imax, maxInc3(m, h, i, j, m[i][j]));
			}
		}
		return imax;
	}
	int maxInc3(vector<vector<int>>& m, vector<vector<int>>& h, int i, int j, int value){
		if (h[i][j] == 0){
			h[i][j] = 1;

			if (i > 0 && m[i - 1][j] > value){
				h[i][j] = max(h[i][j], maxInc3(m, h, i - 1, j, m[i - 1][j]) + 1);
			}
			if (i < m.size() - 1 && m[i + 1][j] > value){
				h[i][j] = max(h[i][j], maxInc3(m, h, i + 1, j, m[i + 1][j]) + 1);
			}
			if (j > 0 && m[i][j - 1] > value){
				h[i][j] = max(h[i][j], maxInc3(m, h, i, j - 1, m[i][j - 1]) + 1);
			}
			if (j < m[0].size() - 1 && m[i][j + 1] > value){
				h[i][j] = max(h[i][j], maxInc3(m, h, i, j + 1, m[i][j + 1]) + 1);
			}

		}
		return h[i][j];
	}
};


class PrintTopKandRank{
public:
	class Node{
	public:
		string str;
		int i;
		Node(string s, int data) :str(s), i(data){}
		
	};
	class Comp{
	public:
		bool operator()(const Node& x, const Node& y)const{
			return x.i > y.i;
		}
	};
	void printTopKandRank2(vector<string>& vs, int k){
		if (k > vs.size()){
			return;
		}
		unordered_map<string, int> hashmap;
		for (auto str : vs){
			if (hashmap.find(str) == hashmap.end()){
				hashmap.insert(make_pair(str, 1));
			}
			else{
				hashmap[str]++;
			}
		}
		vector<Node> v;
		auto it = hashmap.begin();
		for (int i = 0; i < k; ++i){
			if (it != hashmap.end()){
				v.push_back(Node(it->first, it->second));
			}
			else{
				break;
			}
		}
		make_heap(v.begin(), v.end(), Comp());
		for (; it != hashmap.end(); ++it){
			if (it->second > v.front().i){
				pop_heap(v.begin(), v.end(), Comp());
				v.pop_back();
				v.push_back(Node(it->first, it->second));
				push_heap(v.begin(), v.end(), Comp());
			}
		}
		sort_heap(v.begin(), v.end(), Comp());
		for (int i = 1; i <= v.size();++i){
			cout << "No." << i << ":" << it->first << ",times:" << it->second << endl;
		}
	}


	void printTopKandRank(vector<string>& vs, int k){
		if (k > vs.size()){
			return;
		}
		unordered_map<string, int> hashmap;
		for (auto str : vs){
			if (hashmap.find(str) == hashmap.end()){
				hashmap.insert(make_pair(str, 1));
			}
			else{
				hashmap[str]++;
			}
		}
		map<int, string> m;
		for (auto iter = hashmap.begin(); iter != hashmap.end(); ++iter){
			m.insert(make_pair(iter->second, iter->first));
		}
		auto it = m.begin();
		for (int i = 1; i <= k; ++i){
			if (it != m.end()){
				cout << "No." << i << ":" << it->first << ",times:" << it->second << endl;
				++it;
			}
			else{
				break;
			}
		}
	}
};

class SetAllHashtable{
private:
	class Node{
	public:
		int data;
		long time;
		Node(int d, long t) :data(d), time(t){}
		Node(){
			data = INT_MIN;
			time = LONG_MIN;
		}
	};
public:
	SetAllHashtable() :time(0), setAllNode(INT_MIN, LONG_MIN){}
	void put(string key, int value){
		if (containsKey(key)){
			hashmap[key].time = ++time;
		}
		else{
			hashmap.insert(make_pair(key, Node(value, ++time)));
		}
	}
	void setAll(int value){
		setAllNode.data = value;
		setAllNode.time = ++time;
	}
	int get(string key){
		if (!containsKey(key)){
			return INT_MIN;
		}
		else{
			if (hashmap[key].time > setAllNode.time){
				return hashmap[key].data;
			}
			else{
				return setAllNode.data;
			}
		}
	}

	bool containsKey(string key){
		if (hashmap.find(key) != hashmap.end()){
			return true;
		}
		else{
			return false;
		}
	}
private:
	unordered_map<string, Node> hashmap;
	long time;
	Node setAllNode;
};
class TopKFromNArray{
public:
	/*void topKFromNArray(vector<vector<int>>& mat,int k){
		if (k > mat[0].size()*mat.size()){
			return;
		}
		vector<int> v;
		int count = 0;
		
		int j = 0;
		for (int i = 0; i < mat.size(); ++i){
			if (count == k){
				
				while (j++ < mat[i].size()){
					if (v.front() < mat[i][j]){
						pop_heap(v.begin(), v.end(), greater<int>());
						v.pop_back();
						v.push_back(mat[i][j]);
						push_heap(v.begin(), v.end(), greater<int>());
					}
				}
			}
			else{
				for (; j < mat[i].size() && count++ < k; ++j){
						v.push_back(mat[i][j]);
				}
				if (count == k){
					make_heap(v.begin(), v.end(), greater<int>());
				}
			}
		}
		
	}*/
};


class StrNumSum{
public:
	int strNumSum(string  str){
		int flag = true;
		int tempSum = 0;
		int sum = 0;
		int i = 0;
		while (i < str.size()){
			if (isdigit(str[i])){
				tempSum = 0;
				while (i < str.size() && isdigit(str[i])){
					tempSum = tempSum * 10 + str[i] - '0';
					++i;
				}
				tempSum = flag ? tempSum : -1 * tempSum;
				sum += tempSum;
				flag = true;
			}
			else if (str[i] == '-'){
				flag = !flag;
				++i;
			}
			else{
				flag = true; ++i;
			}
		}
		return sum;
	}
};


class PrintEdge{
public:
	void printCicle(vector<vector<int> >& mat, int i, int j, int m, int n){
		for (int col = j; col < m; ++col){
			cout << mat[i][col] << " ";
		}
		for (int row = i; row < n; ++row){
			cout << mat[row][m] << " ";
		}
		for (int col = m; col > j; --col){
			cout << mat[n][col] << " ";
		}
		for (int row = n; row > j; --row){
			cout << mat[row][j] << " ";
		}
		cout << endl;
	}
	void printEdge(vector<vector<int> >& mat){
		int row = mat.size() - 1;
		int col = mat[0].size() - 1;
		for (int i = 0; i <= min(row, col) / 2; ++i){
			printCicle(mat, i, i, col - i, row - i);
		}

	}
};
class RotateMat{
public:
	void ratateCicle(vector<vector<int> >& mat, int i, int j, int m, int n){
		vector<int> v;
		for (int k = i; k <= m; ++k){
			v.push_back(mat[i][k]);
		}

		for (int row = i, col = j; row <= n; ++row){
			mat[i][col++] = mat[row][j];
		}
		for (int col = j, row = i; col <= m; ++col){
			mat[row++][j] = mat[n][col];
		}
		for (int row = n,col = j; row >= i; --row){
			mat[n][col++] = mat[row][m];
		}
		for (int row = i, k = 0; row <= n; ++row){
			mat[row][n] = v[k++];
		}
	}
	void ratateMat(vector<vector<int>>& mat){
		int row = mat.size() - 1;
		int col = mat[0].size() - 1;
		for (int i = 0; i <= min(row, col) / 2; ++i){
			ratateCicle(mat, i, i, col - i, row - i);
		}
	}

	void zigzigPrint(vector<vector<int>>& matrix){
		int rows = matrix.size();
		int cols = matrix[0].size();
		int i = 0; 
		int j = 0;
		bool rightUp = true;
		while (i != rows - 1 || j != cols - 1){
			cout << matrix[i][j] << " ";
			if (rightUp){
				i = i - 1;
				j = j + 1;
				if (i == -1 && j < cols){
					i = i + 1;
					rightUp = !rightUp;
					cout << endl;
				}
				else if(i >= -1 && j == cols){
					i = i + 2;
					j = j - 1;
					rightUp = !rightUp;
					cout << endl;
				}
			}
			else{
				i = i + 1;
				j = j - 1;
				if (i == rows){
					i = i - 1;
					j = j + 2;
					rightUp = !rightUp;
					cout << endl;
				}
				else if (j == -1){
					j = j + 1;
					rightUp = !rightUp;
					cout << endl;
				}
			}
		}
		cout << matrix[rows-1][cols-1] << endl;
	}
};
class PowerN{

public:

	int matrixMulti(vector<vector<int>>& m1, vector<vector<int>>& m2, vector<vector<int>>& m3){
		if (m1[0].size() != m2.size()){
			return -1;
		}
		int m = m1.size();
		int n1 = m1[0].size();
		int n2 = m2[0].size();
		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n2; ++j){
				for (int k = 0; k < n1; ++k){
					m3[i][j] += m1[i][k] * m2[k][j];
				}
			}
		}
	}

	//vector<vector<int>>
	int powerN(int base, int n){
		if (n == 0){
			return 1;
		}
		else if (n == 1){
			return base;
		}
		int res = powerN(base, n / 2);
		res *= res;
		return n % 2 == 0 ? res : res*base;
	}

};
class AddSubMutliDivde{
public:
	int add(int a, int b){
		int arr = a&b;
		while (arr != 0){
			arr = arr << 1;
			b = a^b;
			a = arr;
			arr = a&b;
		}
		return a^b;
	}
	int nagetion(int b){
		return add(~b, 1);
	}
	int sub(int a, int b){
		return add(a, nagetion(b));
	}


	int mutli(int a, int b){
		int res = 0;
		bool flag = true;
		if (a < 0){
			flag = !flag;
			a = nagetion(a);
		}
		if (b < 0){
			flag = !flag;
			b = nagetion(b);
		}
		for (int i = 0; b != 0; ++i){
			if ((b & 1) != 0){
				res = add(res, a << i);
			}
			b = b >> 1;
		}
		return flag == true ? res : nagetion(res);
	}

	int div(int a, int b){

		int res = 0;
		for (int i = 31; i > -1; --i){
			if ((a>>i) >= b){
				res |= (1 << i);
				a = sub(a, b << i);
			}
		}
		return res;
	}
};

class ReoderOddEven{
public:
	//稳定版
	void reoderOddEven3(vector<int>& v){
		int pOdd = 0;
		vector<int> help;
		for(int i = 0; i < v.size(); ++i){
			if (v[i] % 2 != 0){
				if (pOdd != i){
					v[pOdd] = v[i];
				}
				++pOdd;
			}else{
				help.push_back(v[i]);
			}
			
		}
		for (int i = 0; i < help.size(); ++i){
			v[pOdd++] = help[i];
		}
	}
	void reoderOddEven2(vector<int>& v){
		int more = v.size();
		int L = 0;
		while (L < more-1){
			if (v[L] % 2 != 0){
				
				++L;
			}
			else{
				swap(v[L], v[--more]);
			}
		}
	}

	void reoderOddEven(vector<int>& v){
		int L = 0;
		int  R = v.size() - 1;
		while (L < R){
			while (L < R && v[L]%2 != 0){
				++L;
			}
			while (L < R && v[R] % 2 == 0){
				--R;
			}
			if (L < R){
				swap(v[L], v[R]);
				++L;
				--R;
			}
		}
	}
};
class ArrayPermutation{
public:
	void arraySub(vector<int>& v, int i, vector<int> h){
		if (i == v.size()){
			for (auto& data : h){
				cout << data << " ";
			}
			cout << endl;
		}
		else{
			arraySub(v, i + 1, h);
			h.push_back(v[i]);
			arraySub(v, i + 1, h);
		}
	}
	void arrayPermutation(vector<int>& v, int i){
		if (i == v.size()){
			for (auto& data : v){
				cout << data << " ";
			}
			cout << endl;
			return;
		}
		for (int j = i; j < v.size(); ++j){
			swap(v[i], v[j]);
			arrayPermutation(v, i + 1);
			swap(v[i], v[j]);
		}
	}
};
class SubArrayMax{
public:
	int subArrayMax2(vector<int>& v){
		if (v.empty()){
			return INT_MIN;
		}
		int res = INT_MIN;
		int cur = 0;
		vector<int> subarray;
		vector<int> curarray;
		for (int i = 0; i < v.size(); ++i){
			cur += v[i];
			curarray.push_back(v[i]);
			if (cur < v[i]){
				cur = v[i];
				curarray.clear();
				curarray.push_back(v[i]);
			}
			if (cur > res){
				subarray = curarray;
				res = cur;
			}
		}
		for (auto& i : subarray){
			cout << i << " ";
		}
		cout << endl;
		return res;
	}

	int subArrayMax(vector<int>& v){
		if (v.empty()){
			return INT_MIN;
		}
		int res = v[0];
		int cur = res;
		for (int i = 1; i < v.size(); ++i){
			cur += v[i];
			if (cur < v[i]){
				cur = v[i];
			}
			if (cur > res){
				res = cur;
			}
		}
		return res;
	}
};
class Fun{
public:
	bool operator()(int a, int b){
		stringstream s1;
		s1 << a << b;
		stringstream s2;
		s2 << b << a;
		string str1;
		return s1.str() < s2.str();
	}
};
class SumIsAim{
public:
	vector<vector<int>> sumIsAim2(vector<int>& v, int aim){
		vector<vector<int>> res;
		if (v[0] > aim){
			return res;
		}
		else if (v[0] == aim){
			res.push_back(vector<int>{aim});
		}
		auto small = v.begin();
		int sum = 0;
		auto big = small;
		++big;
		sum = *small + *big;
		while (small <= big && big != v.end()){
			if (sum < aim){
				++big;
				sum += *big;
			}
			else if (sum > aim){
				sum -= *small;
				++small;				
			}
			else{
				res.push_back(vector<int>(small, ++big));
				sum += *big;
			}
		}
		return res;
	}


	pair<int, int> sumIsAim(vector<int>& v, int aim){
		int small = 0;
		int big = v.size() - 1;
		while (small < big){
			if (v[small] + v[big] > aim){
				--big;
			}
			else if (v[small] + v[big] < aim){
				++small;
			}
			else{
				return make_pair(v[small], v[big]);
			}
		}
		return make_pair(-1,-1);
	}

};
class DuplicatonInArray{
public:
	int duplicatonInArray(vector<int>& v){
		vector<int> help(v.size(), -1);
		for (int i = 0; i < v.size(); ++i){
			if (help[v[i]] == -1){
				help[v[i]] = i;
			}
			else{
				return v[i];
			}
		}
		return INT_MIN;
	}
};
class BinaryTree2{
public:
	class TreeNode{
	public:
		int data;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int d) :data(d){
			left = nullptr;
			right = nullptr;
		}
	};
//private:
	TreeNode* root;
public:
	BinaryTree2(){
		root = new TreeNode(10);
		root->left = new TreeNode(8);
		root->left->left = new TreeNode(6);
		root->left->right = new TreeNode(7);
		root->right = new TreeNode(16);
		root->right->left = new TreeNode(13);
		//root->right->right = new TreeNode(7);
	}
	TreeNode* rebuildTree(TreeNode* head){
		if (head == nullptr){
			return nullptr;
		}
		TreeNode* root = new TreeNode(head->data);
		root->left = rebuildTree(head->left);
		root->right = rebuildTree(head->right);
		return root;
	}
	void levelPrint(){
		int printed = 1;
		int tobePrinted = 0;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()){
			TreeNode* temp = q.front(); q.pop();
			if (temp->left){
				q.push(temp->left);
				++tobePrinted;
			}if (temp->right){
				q.push(temp->right);
				++tobePrinted;
			}
			cout << temp->data << " ";
			--printed;
			if (printed == 0){
				cout << endl;
				printed = tobePrinted;
				tobePrinted = 0;
			}
		}
	}
	void EachNodeII(){
		int printed = 1;
		int tobePrinted = 0;
		queue<TreeNode*> q;
		q.push(root);
		TreeNode* pre = nullptr;
		while (!q.empty()){
			TreeNode* temp = q.front(); q.pop();
			if (temp->right){
				q.push(temp->right);
				++tobePrinted;
			}if (temp->left){
				q.push(temp->left);
				++tobePrinted;
			}			
			temp->right = pre;
			pre = temp;
			--printed;
			if (printed == 0){
				pre = nullptr;				
				printed = tobePrinted;
				tobePrinted = 0;
			}
		}
	}

	void aigaigPrint(){
		int printed = 1;
		int tobePrinted = 0;
		bool frontPop = true;
		deque<TreeNode*> q;
		q.push_back(root);
		while (!q.empty()){
			TreeNode* temp = nullptr;
			if (frontPop){
				temp = q.front(); q.pop_front();
				cout << temp->data << " ";
				if (temp->left){
					q.push_back(temp->left);
					++tobePrinted;
				}if (temp->right){
					q.push_back(temp->right);
					++tobePrinted;
				}
			}
			else{
				temp = q.back(); q.pop_back();
				cout << temp->data << " ";
				if (temp->right){
					q.push_front(temp->right);
					++tobePrinted;
				}if (temp->left){
					q.push_front(temp->left);
					++tobePrinted;
				}
			}			
			--printed;
			if (printed == 0){
				cout << endl;
				printed = tobePrinted;
				tobePrinted = 0;
				frontPop = !frontPop;
			}
		}
	}

	bool pathIsAim(TreeNode* head,int aim,int sum){
		if (head->left == nullptr && head->right == nullptr){
			if (sum + head->data == aim){
				return true;
			}
			return false;
		}
		sum += head->data;
		bool res1 = false;
			if (head->left){
				res1 = pathIsAim(head->left, aim, sum);
			}
			bool res2 = false;
			if (head->right){
				res2 = pathIsAim(head->right, aim, sum);
			}
			return res1 || res2;
	}
	bool pathIsAim(TreeNode* head, int aim, int sum,vector<int>& v){
		if (head->left == nullptr && head->right == nullptr){
			v.push_back(head->data);
			if (sum + head->data == aim){
				for (auto& i : v){
					cout << i << " ";
				}
				cout << endl;
				return true;
			}
			return false;
		}
		v.push_back(head->data);
		sum += head->data;
		bool res1 = false;
		if (head->left){
			res1 = pathIsAim(head->left, aim, sum,v);
			v.pop_back();
		}
		bool res2 = false;
		if (head->right){
			res2 = pathIsAim(head->right, aim, sum,v);
			v.pop_back();
		}
		return res1 || res2;
	}

	struct ReturnData{
		int height;
		int mostBigLength;
	};
	int maxDistance(){

		return maxDistance_core(root).mostBigLength;
	}

	ReturnData maxDistance_core(TreeNode* head){
		if (head == nullptr){
			return ReturnData{ 0, 0 };
		}
		ReturnData L = maxDistance_core(head->left);
		ReturnData R = maxDistance_core(head->right);
		return ReturnData{ max(L.height, R.height) + 1,
			max(max(L.mostBigLength, R.mostBigLength), L.height+R.height + 1) };
	}
	int getLeftHeight(TreeNode* head){
		if (head == nullptr){
			return 0;
		}
		return getLeftHeight(head->left) + 1;
	}
	int bs(TreeNode* head, int level, int height){
		if (level == height){
			return 1;
		}
		int rightChildHeight = getLeftHeight(head->right);
		if (rightChildHeight == height - 1){
			return (1 << (height - 1)) + bs(head->right, 1, rightChildHeight);
		}
		else{
			return (1 << rightChildHeight) + bs(head->left, 1, height - 1 );
		}
	}
	int nodeNum(){
		if (root == nullptr){
			return 0;
		}
		return bs(root, 1, getLeftHeight(root));
	}
};

class JumpGame{
public:
	int jumpGame(vector<int>& v){
		int jump = 0;
		int cur = 0;
		int next = 0;
		for (int i = 0; i < v.size(); ++i){
			if (cur < i){
				cur = next;
				++jump;
			}
			next = max(next, i + v[i]);
		}
		return jump;
	}
};

class PrintMaxTopK{
public:
	class topNode{
	public:
		int data;
		int num;
		int index;
		topNode(int d, int n, int i) :data(d), num(n),index(i){}
		topNode() :data(0), num(0), index(0){}
	};

	class Comp_topNode{
	public:
		bool operator()(const topNode& x, const topNode& y){
			return x.data < y.data;
		}
	};
	void printMaxTopK(vector<vector<int>>& matrix,int topK){
		if (topK < 1 || matrix.empty()){
			return;
		}
		vector<topNode> heapArray;
		//(matrix.size(), topNode());
		for (int i = 0; i < matrix.size(); ++i){
			heapArray.push_back(topNode(matrix[i].back(), i, matrix[i].size() - 1));
		}
		make_heap(heapArray.begin(), heapArray.end(), Comp_topNode());

		for (int i = 0; i < topK; ++i){
			if (heapArray.empty()){
				break;
			}
			pop_heap(heapArray.begin(), heapArray.end(), Comp_topNode());		

			topNode ref = *heapArray.end();
			cout << ref.data << " ";
			heapArray.pop_back();
			if (ref.index != 0){
				--ref.index;
				heapArray.push_back(topNode(matrix[ref.num][ref.index],ref.num,ref.index));			
				push_heap(heapArray.begin(), heapArray.end(), Comp_topNode());
			}
		}
	}
};
class SmallestMissNum{
public:
	int smallestMissNum(vector<int> v){
		int L = 0;
		int R = v.size();

		while (L < R){
			if (v[L] == L + 1){
				L++;
			}
			else if (v[L] <= L || v[L] > R || v[L] == v[v[L] - 1]){
				v[L] = v[--R];
			}
			else{
				swap(v[L], v[v[L] - 1]);
			}
		}
		return L + 1;
	}
};
class MaxOneBorderSize{
public:
	void getDownRightMatrix(vector<vector<int>>& matrix, vector<vector<int>>& down, vector<vector<int>>& right){
		int rows = matrix.size();
		int cols = matrix[0].size();
		for (int j = 0; j < cols; ++j){
			down[rows - 1][j] = matrix[rows - 1][j];
		}
		for (int i = rows - 2; i > -1; --i){
			for (int j = 0; j < cols; ++j){
				down[i][j] = matrix[i][j] + down[i+1][j];
			}
		}
		for (int i = 0; i < rows; ++i){
			right[i][cols - 1] = matrix[i][cols - 1];
		}
		for (int j = cols-2; j > -1; --j){
			for (int i = 0; i < rows; ++i){
				right[i][j] = matrix[i][j] + right[i][j + 1];
			}
		}
	}
	int maxOneBorderSize(vector<vector<int>>& matrix){

		vector<vector<int>> down = matrix;
		vector<vector<int>> right = matrix;

		getDownRightMatrix(matrix, down, right);

		for (int size = min(matrix.size(), matrix[0].size()); size > 0; --size){
			for (int i = 0; i < matrix.size() - size + 1; ++i){
				for (int j = 0; j < matrix[0].size() - size + 1; ++j){
					if (down[i][j] >= size && right[i][j] >= size
						&& right[i + size - 1][j] >= size && down[i][j + size - 1] >= size){
						return size;
					}
				}
			}
		}
		return 0;
	}
};
class MaxFromZeroToI{
public:
	vector<int> maxFromZeroToI(vector<int>& v){
		vector<int> rs(v.size(),0);
		rs[0] = v[0];
		for (int i = 1; i < v.size(); ++i){
			rs[i] = v[i] > rs[i - 1] ? v[i] : rs[i - 1];
		}
		return rs;
	}
};
class SumIsAimSub{
public:
	void sumIsAimSub_core(vector<int>& v, int aim, vector<int> array,int i, int sum){
		if (i == v.size()){
			if (sum == aim){
				for (auto& i : array){
					cout << i << " ";
				}
				cout << endl;
			}
			return;
		}
		sumIsAimSub_core(v, aim, array, i + 1, sum);
		array.push_back(v[i]);
		sum += v[i];
		sumIsAimSub_core(v, aim, array, i + 1, sum);
	}

	void sumIsAimSub(vector<int>& v,int aim){
		vector<int> res;
		sumIsAimSub_core(v, aim, res, 0, 0);
	}

	int sumIsAimSub_core2(vector<int>& v, int i, int aim){
		if (aim == 0){
			return 1;
		}
		if (aim < 0){
			return 0;
		}
		if (i == v.size()){
			return 0;
		}
		int notIncluded = sumIsAimSub_core2(v, i + 1, aim);
		int included = sumIsAimSub_core2(v, i + 1, aim - v[i])*v[i];
		return max(included, notIncluded);
	}

	int sumIsAimSub2(vector<int>& v, int aim){
		return sumIsAimSub_core2(v, 0, aim);
	}
};
class SearchBin{
public:
	int binSearch(vector<int>& v, int aim){
		int left = 0;
		int right = v.size() - 1;
		while (left <= right){
			int mid = left + ((right - left) >> 1);
			if (v[mid] == aim){
				return mid;
			}
			else if (v[mid] < aim){
				left = mid + 1;
			}
			else{
				right = mid - 1;
			}
		}
		return -1;
	}

	int binSearch_lower(vector<int>& v, int aim){
		int left = 0;
		int right = v.size() - 1;
		int ret = -1;
		while (left <= right){
			int mid = left + ((right - left) >> 1);
			if (v[mid] < aim){
				left = mid + 1;
			}
			else{
				ret = mid;
				right = mid - 1;
			}
		}
		return ret;
	}
	int binSearch_upper(vector<int>& v, int aim){
		int left = 0;
		int right = v.size() - 1;
		int ret = -1;
		while (left <= right){
			int mid = left + ((right - left) >> 1);
			if (v[mid] <= aim){
				left = mid + 1;
			}
			else{
				ret = mid;
				right = mid - 1;
			}
		}
		return ret;
	}
};
class SumIsAim2{
public:
	void sumIsAim(vector<int>& v,int aim){
		//array<array<bool, aim + 1>, v.size()>
		//bool dp[v.size()][aim + 1];
		bool** dp = new bool*[v.size()];
		for (int i = 0; i < v.size(); ++i){
			dp[i] = new bool[aim + 1];
			memset(dp[i], 0, sizeof(bool)*(aim + 1));
		}
		dp[0][0] = true;
		dp[0][v[0]] = true;
		for (int i = 1; i < v.size(); ++i){
			for (int j = 0; j <= aim; ++j){
				if (dp[i - 1][j] == true 
					|| (j - v[i] > -1 && dp[i - 1][j - v[i]] == true)){
					dp[i][j] = true;
				}
			}
		}
		cout << "dp" << endl;
		for (int i = 0; i < v.size(); ++i){
			for (int j = 0; j <= aim; ++j){
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}

		int* dp2 = new int[aim + 1];
		for (int i = 0; i < aim + 1; ++i){
			dp2[i] = -1;
		}
		dp2[0] = 0;
		dp2[v[0]] = v[0];
		for (int i = 1; i < v.size(); ++i){
			for (int j = aim; j >- 1 ; --j){
			//for (int j = 0; j <= aim; ++j){错误的
				if ((dp2[j] == -1) && (j - v[i] > -1) && (dp2[j-v[i]] != -1)){
					dp2[j] = j;
				}
			}
		}
		cout <<"dp2"<< endl;
		for (int j = 0; j <= aim; ++j){
			cout << dp2[j] << " ";
		}
		cout << endl;
		int tianchong = -1;
		for (int j = aim; j > -1; --j){
			if (dp2[j] != -1){
				tianchong = dp2[j];
			}
			else{
				dp2[j] = tianchong;
			}
		}
		cout << "dp2" << endl;
		for (int j = 0; j <= aim; ++j){
			cout << dp2[j] << " ";
		}
		cout << endl;
	}
};
class ExpressSimple{
public:
	int calcExpress(string& str){

	}
	int expressSimple_core(string& str,int i, string s){
		/*while (i < str.size() && str[i] != ')'){
			if (str[i] == '('){
				string str;
				int index = expressSimple_core(str, i + 1, str);

			}
			else{
				s.push_back(str[i]);
			}
		}*/
	}
	string expressSimple(string& str){
		string ret;
		expressSimple_core(str,0, ret);
		return ret;
	}
};
class SubArrayIsAim{
public:
	int sub2ArrayIsAim(vector<int> v){
		vector<int> arrL;
		int cur = 0;
		int ret = INT_MIN;
		for (int i = 0; i < v.size(); ++i){
			cur += v[i];
			ret = max(cur, ret);
			arrL.push_back(ret);
			cur = cur < 0 ? 0 : cur;
		}
		for (auto& i : arrL){
			cout << i << " ";
		}
		cout << endl;

		vector<int> arrR;
		cur = 0;
		ret = INT_MIN;
		for (int i = v.size() - 1; i > -1; --i){
			cur += v[i];
			ret = max(cur, ret);
			arrR.push_back(ret);
			cur = cur < 0 ? 0 : cur;
		}
		for (auto& i : arrR){
			cout << i << " ";
		}
		cout << endl;

		ret = 0;
		for (int i = 0; i < v.size()-1; ++i){
			ret = max(ret, arrL[i] + arrR[v.size() - i - 2]);
		}


		return ret;
	}

	int subArrayIsAim(vector<int> v){
		int cur = v[0];
		int ret = cur;
		for (int i = 1; i < v.size(); ++i){
			cur += v[i];
			if (cur < v[i]){
				cur = v[i];
			}
			if (ret < cur){
				ret = cur;
			}
		}
		return ret;
	}
	int subArrayIsAim2(vector<int> v){
		int cur = 0;
		int ret = INT_MIN;
		vector<int> temp; vector<int> res;
		for (int i = 0; i < v.size(); ++i){
			cur += v[i];
			temp.push_back(i);
			if (cur < v[i]){
				cur = v[i];
				temp.clear();
				temp.push_back(i);
			}//返回最大的连续子数组且长度最常
			if (ret < cur || (ret == cur && res.size() < temp.size())){
				res = temp;
				ret = cur;
			}
		}
		for (auto& i : res){
			cout << v[i] << " ";
		}
		return ret;
	}
};
class IsPalinInLR{
public:
	bool isPalinInLR(string& str, int L, int R){
		if (L == R || (L+1 == R && str[L+1] == str[R])){
			return true;
		}
		else if (str[L] != str[R] || L > R){
			return false;
		}
		else{
			return isPalinInLR(str, L + 1, R - 1);
		}
	}
	bool isPalinInLR_dp(string& str, int L, int R){
		vector<vector<bool>> dp(str.size(),vector<bool>(str.size(),false));

		//for (int i = 0; i < dp.size(); ++i){
		//	dp[i][i] = true;
		//}
		//for (int i = 0; i < dp.size() - 1; ++i){
		//	if (str[i] == str[i + 1]){
		//		dp[i][i + 1] = true;
		//	}
		//}
		dp[0][0] = true;
		for (int i = 1; i < dp.size(); ++i){
			dp[i][i] = true;
			if (str[i] == str[i - 1]){
				dp[i - 1][i] = true;
			}
		}
		for (int len = 2; len < str.size(); ++len){
			for (int i = 0; i < str.size() - len; ++i){
				if (str[i] != str[i + len]){
					dp[i][i + len] = false;
				}
				else{
					dp[i][i + len] = dp[i+1][i + len-1];
				}
			}
		}
		return dp[L][R];
	}

};
class BiggestSubBSTInTree{
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

	class ReturnData{
	public:
		ReturnData(int mi, int  ma, int  s, bool i){
			min_v = mi;
			max_v = ma;
			size = s;
			isSearch = i;
		}
		int min_v;
		int max_v;
		int size;
		bool isSearch;
	};
	ReturnData biggestSubBSTInTree(Tree* head){
		if (head == 0){
			return ReturnData(INT_MAX, INT_MIN, 0, true);
		}
		ReturnData L = biggestSubBSTInTree(head->left);
		ReturnData R = biggestSubBSTInTree(head->right);

		if (L.isSearch && R.isSearch && L.max_v < head->data && R.min_v > head->data){
			return ReturnData(min(min(L.min_v,R.min_v),head->data), 
				max(max(L.max_v,R.max_v),head->data),
				1 + max(L.size, R.size), 
				true);
		}
		else{
			return ReturnData(INT_MAX, INT_MIN, max(L.size, R.size), false);
		}
	}
};
class OddCountNum{
public:
	int oddCountNum(vector<int>& v){
		int ret = 0;
		for (auto& i : v){
			ret ^= i;
		}
		return ret;
	}

	int oddCountNum2(vector<int>& v){
		int ret = 0;
		for (auto& i : v){
			ret ^= i;
		}

		int xor = ret &(~ret + 1);
		int ret2 = 0;
		for (auto& i : v){
			if (i & xor){
				ret2 ^= i;
			}
		}
		cout << (ret^ret2) << " " << ret2 << endl;
		return ret;
	}


	int oddCountNum3(vector<int>& v,int k){



		map<int, int> mmm;
		for (auto dd : v){
			if (mmm.find(dd) == mmm.end()){
				mmm[dd] = 1;
			}
			else{
				++mmm[dd];
			}
		}
		for (auto& i : mmm){
			if (i.second == 1){
				return i.first;
			}
		}
		return INT_MIN;





		vector<int> ret(32, 0);
		for (auto data : v){
			if (data < 0){ data = -data; }
			int i = 0;
			while (data != 0){
				ret[i] += (data)%k;
				data /= k;
				++i;
			}
			for (auto vvv : ret){ cout << vvv << " "; }cout << endl;
		}
		int res = 0;
		for (int i = 31; i > -1; --i){
			res = res * k + ret[i]%k;
		}
		int count = 0;
		for (auto data : v){
			if (-res == data){
				++count;
			}
		}
		return count != 1 ? res :-res;
	}
};
class LongestIncSub{
public:
	//O(nlogn)
	int longestIncSUb2(vector<int>& v){
		vector<int> dp(v.size(), 0);
		vector<int> ends;
		dp[0] = 1;
		ends.push_back(v[0]);
		int ends_end = 0;
		for (int i = 1; i < v.size(); ++i){
			auto fi = upper_bound(ends.begin(), ends.end(), v[i]);
			if (fi == ends.end()){
				ends.push_back(v[i]);
				dp[i] = ends.size();
			}
			else{
				*fi = v[i];
				dp[i] = fi - ends.begin() + 1;
			}
		}
		return *max_element(dp.begin(), dp.end());
	}

	int longestIncSUb(vector<int>& v){
		vector<int> dp(v.size(), 0);
		//dp[0] = 1;
		for (int i = 1; i < v.size(); ++i){
			for (int j = i - 1; j > -1; --j){
				if (v[j] < v[i]){
					dp[i] = dp[j] + 1;
					break;
				}
			}
			dp[i] = dp[i] == 0 ? 1 : dp[i];
		}
		//return *max_element(dp.begin(), dp.end());

		//子数组
		vector<int> dp2(v.size(), 0);
		dp = dp2;
		dp[0] = 1;
		for (int i = 1; i < v.size(); ++i){
			if (v[i - 1] < v[i]){
				dp[i] = dp[i - 1] + 1;
			}
			else{
				dp[i] = 1;
			}
		}
		return *max_element(dp.begin(), dp.end());

	}
	class ClaData{
	public:
		ClaData(int l, int w){
			length = l;
			width = w;
		}
		int length;
		int width;
	};
	class Comp{
	public:
		bool operator()(const ClaData& x, const ClaData& y){
			return x.length < y.length || (x.length == y.length && x.width > y.width);
		}
	};
	int longestIncSUb3(vector<ClaData>& v){
		sort(v.begin(), v.end(), Comp());
		vector<int> ret;
		for (auto& data : v){
			cout << data.length << " " << data.width << endl;
			ret.push_back(data.width);
		}
		cout << endl;

		return longestIncSUb2(ret);

	}
};
class AllLessNumSubArray{
public:
	int allLessNumSubArray(vector<int>& v, int sum){
		int i = 0; int j = 0;
		deque<int> qmin;
		deque<int> qmax;
		int res = 0;
		while (i < v.size()){
			while (j < v.size()){
				while (!qmin.empty() && v[qmin.back()] >= v[j]){
					qmin.pop_back();
				}
				qmin.push_back(j);

				while (!qmax.empty() && v[qmax.back()] <= v[j]){
					qmax.pop_back();
				}
				qmax.push_back(j);
				if (v[qmax.front()] - v[qmin.front()] > sum){
					break;
				}
				++j;
			}
			if (i == qmin.front()){
				qmin.pop_front();
			}
			if (i == qmax.front()){
				qmax.pop_front();
			}
			res += j - i;
			++i;
		}
		return res;
	}

	int allLessNumSubArrayN2(vector<int>& v, int sum){

		int res = 0;
		for (int i = 0; i < v.size(); ++i){
			int j = i + 1;
			int mi = v[i];
			int ma = v[i];
			for (; j < v.size(); ++j){
				ma = v[j] > ma ? v[j] : ma;
				mi = v[j] < mi ? v[j] : mi;
				if (ma - mi > sum){
					break;
				}
			}
			res += j - i;
		}
		return res;
	}

	int getWindowsMax(vector<int>& v, int k){
		deque<int> dq;
		vector<int> ret;
		int i = 0;
		while (i < v.size()){
			while (!dq.empty() && v[dq.back()] <= v[i]){
				dq.pop_back();
			}
			dq.push_back(i);
			if (dq.front() <= i - k){
				dq.pop_front();
			}

			if (i >= k - 1){
				ret.push_back(v[dq.front()]);
			}
			
		}
	}
};
class SortedArrayToBalancedBST{
public:
	class TreeNode{
	public:
		int data;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int d) :data(d){
			left = nullptr;
			right = nullptr;
		}
	};

	void preOrder(TreeNode* root){
		if (root == nullptr){
			return;
		}
		
		preOrder(root->left);
		cout << root->data << " ";
		preOrder(root->right);
	}

	TreeNode* sortedArrayToBalancedBST(vector<int>& v, int L, int R){
		if (L > R){
			return nullptr;
		}
		int mid = L + ((R - L) >> 1);
		TreeNode* root = new TreeNode(v[mid]);
		root->left = sortedArrayToBalancedBST(v, L, mid - 1);
		root->right = sortedArrayToBalancedBST(v, mid + 1,R);

		preOrder(root);
		return root;
	}
};
class MinPathSum{
public:
	int minPathSum(vector<vector<int>>& matrix, int i, int j){
		if (i == matrix.size() - 1 && j == matrix[0].size() - 1){
			return matrix[i][j];
		}
		int down = INT_MAX;
		int right = INT_MAX;
		if (j < matrix[0].size() - 1 && i < matrix.size() - 1){
			right = minPathSum(matrix, i, j + 1) + matrix[i][j];
			down = minPathSum(matrix, i + 1, j) + matrix[i][j];
		}
		else if (i < matrix.size()-1){
			down = minPathSum(matrix, i + 1, j) + matrix[i][j];
		}
		else{
			right = minPathSum(matrix, i, j + 1) + matrix[i][j];
		}
		return min(down, right);
	}
	int minPathSum4(vector<vector<int>>& matrix, int i, int j){
		if (i == matrix.size() - 1 && j == matrix[0].size() - 1){
			return matrix[i][j];
		}
		int down = INT_MAX;
		int right = INT_MAX;
		if (i < (matrix.size() - 1)){
			down = minPathSum4(matrix, i + 1, j) + matrix[i][j];
		}if (j < (matrix[0].size() - 1)){
			right = minPathSum4(matrix, i, j + 1) + matrix[i][j];
		}
		return min(down, right);
	}
	int minPathSum2(vector<vector<int>>& matrix){
		int rows = matrix.size();
		int cols = matrix[0].size();
		vector<vector<int>>dp(rows, vector<int>(cols, 0));
		dp[rows - 1][cols - 1] = matrix[rows - 1][cols - 1];

		for (int i = rows - 2; i > -1; --i){
			dp[i][cols - 1] = dp[i + 1][cols - 1] + matrix[i][cols - 1];
		}

		for (int j = cols - 2; j > -1; --j){
			dp[rows - 1][j] = dp[rows - 1][j+1] + matrix[rows - 1][j];
		}

		for (int i = rows - 2; i > -1; --i){
			for (int j = cols - 2; j > -1; --j){
				dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + matrix[i][j];
			}
		}



		int i = 0; 
		int j = 0;
		cout << "path : " << endl;
		int minpath = dp[0][0];
		while (minpath != 0){
			cout << i << " " << j << endl;
			minpath -= matrix[i][j];
			if ( (i + 1) < rows && (dp[i + 1][j] == minpath)){
				i = i + 1;
			}
			else{
				j = j + 1;
			}
		}
		return dp[0][0];
	}

	int minPathSum3(vector<vector<int>>& matrix){
		vector<int> dp(matrix[0]);
		for (int i = 1; i < dp.size(); ++i){
			dp[i] += dp[i - 1];
		}
		for (int i = 1; i < matrix.size(); ++i){
			dp[0] += matrix[i][0];
			for (int j = 1; j < matrix[0].size(); ++j){
				dp[j] = min(dp[j - 1], dp[j]) + matrix[i][j];
			}
		}
		return dp.back();
	}

};
class StringSubsquences{
public:
	void stringSubsquences(string& str,int i,string ret){
		if (i == str.length()){
			cout << ret << endl;
			return;
		}
		stringSubsquences(str, 1 + i, ret);
		stringSubsquences(str, 1 + i, ret + str[i]);		
	}

	void stringSubsquences2(string& str, int i){
		if (i == str.length()){
			cout << str << endl;
			return;
		}
		stringSubsquences2(str, 1 + i);
		char temp = str[i];
		str[i] = ' ';
		stringSubsquences2(str, 1 + i);
		str[i] = temp;
	}

	void stringPermutations(string& str, int i){
		if (i == str.length()){
			cout << str << endl;
			return;
		}
		for (int j = i; j < str.size(); ++j){
			swap(str[i], str[j]);
			stringPermutations(str, i+1);
			swap(str[i], str[j]);
		}
	}
};
class Dao{
public:

	int count(vector<vector<int>>& matrix){
		int num = 0;
		int rows = matrix.size();
		int cols = matrix[0].size();
		for (int i = 0; i < rows; ++i){
			for (int j = 0; j < cols; ++j){
				if (matrix[i][j] == 1){
					++num;
					ganran(matrix, i, j);
				}
			}
		}
		return num;
	}


	void ganran(vector<vector<int>>& matrix, int i, int j){
		matrix[i][j] = 2;
		if (i > 0 && matrix[i - 1][j] == 1){
			ganran(matrix, i - 1, j);
		}
		if (i < (matrix.size() - 1) && matrix[i + 1][j] == 1){
			ganran(matrix, i + 1, j);
		}
		if (j > 0 && matrix[i][j - 1] == 1){
			ganran(matrix, i, j - 1);
		}
		if (j < (matrix[0].size() - 1) && matrix[i][j + 1] == 1){
			ganran(matrix, i, j + 1);
		}
	}
};
class PrintWordInStr{
public:
	PrintWordInStr(string str){
		int i = 0;
		int j = 0;
		int len = (int)str.size();
		while (i < len){
			j = i;
			while (j != len && str[j] != ' '){
				++j;
			}
			cout << str.substr(i, j - i) << endl;
			while (j != len && str[j] == ' '){ ++j; }
			i = j;

		}
	}
};
//和为K的最大乘积
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

	int maxMutli_dp(vector<int>& v,int K){
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

class NestedKaohao{//嵌套括号
public:
	bool nestedKaohao(string& str){
		stack<char> s;
		for (int i = 0; i < str.size(); ++i){
			if (str[i] == '(' || str[i] == '{' || str[i] == '['){
				s.push(str[i]);
			}
			else if (str[i] == ')' || str[i] == '}' || str[i] == ']'){
				if (s.empty()
					|| (str[i] == ')' && s.top() != '(')
					|| (str[i] == '}' && s.top() != '{')
					|| (str[i] == ']' && s.top() != '[')){
					return false;
				}
				s.pop();
			}			
		}
		return true;
	}
};
//解压缩
class JieYaSuo{
public:
	string jieYaSuo(string& str,int& i){
		string ret = "";
		int len = (int)(str.size());
		while (i < len){
			if (isdigit(str[i])){
				int num = 0;
				while (i < len && isdigit(str[i])){
					num += num * 10 + str[i++] - '0';
				}
				++i;
				string temp = jieYaSuo(str, i);
				while (num != 0){
					ret += temp;
					--num;
				}
			}
			else if (str[i] == '}'){
				++i;
				return ret;
			}
			else{
				ret += str[i++];
			}
		}
		return ret;
	}
};
int main2(){
	//JieYaSuo m;
	//string str1("3{d}2{bc}");
	//string str("3{a2{d}}");
	//int i = 0;
	//cout << m.jieYaSuo(str,i) << endl;
	//NestedKaohao m;
	//string str("(]");
	//cout << m.nestedKaohao(str);


	/*string stri("I   love    You   ");
	PrintWordInStr m(stri);*/
	//vector<int> v{ 2, 1, 3, 4, 5 };
	//MaxMutli m;
	//cout << m.maxMutli(v) << endl;
	//cout << m.maxMutli_dp(v, 10) << endl;
	//vector<int> v1{ 1,0,0,1 };
	//vector<int> v2{ 1,1,0,1 };
	//vector<int> v3{ 0,0,1,0};
	//vector<vector<int>> matrix{ v1, v2, v3 };
	//Dao m;
	//cout << m.count(matrix) << endl;
	//StringSubsquences m;
	//string str("123");
	//string ret;
	//m.stringSubsquences(str, 0, ret);
	//m.stringSubsquences2(str, 0);
	//vector<int> v1{ 1,3,5,7 };
	//vector<int> v2{ 2,3,4,1 };
	//vector<int> v3{ 5,5,0,5};
	//vector<vector<int>> v{ v1, v2, v3 };
	//MinPathSum m;
	//cout << m.minPathSum(v, 0, 0) << endl;
	//cout << m.minPathSum2(v) << endl;
	//cout << m.minPathSum3(v) << endl;
	//cout << m.minPathSum4(v, 0, 0) << endl;
	//BinaryTree2 m;
	//cout << m.maxDistance() << endl;
	//cout << m.nodeNum() << endl;
	/*BinaryTree m;
	m.preOrder();
	cout << endl;

	cout << m.serialTreePre() << endl;
	BinaryTree::Tree* ret = m.reserialTreePre(m.serialTreePre());

	m.root = ret;
	m.preOrder();
	cout << m.serialTreePre() << endl;
	ret = m.unserialTreePre(m.serialTreePre());
	m.root = ret;
	m.preOrder();*/
	//string str("1_2_3_#_#_4_4_");
	//char ch('_');
	//vector<string> v;
	//BinaryTree m;
	//m.splitString(str, ch, v);
	//vector<int> v{ 1,2,3,4 };
	//SortedArrayToBalancedBST m;
	//m.sortedArrayToBalancedBST(v, 0, v.size() - 1);
	//vector<int> v{ 3, 2, 9, 5, 1 };
	//AllLessNumSubArray m;
	//cout << m.allLessNumSubArray(v, 3) << endl;;
	//cout << m.allLessNumSubArrayN2(v, 3) << endl;;
	//BinaryTree m;
	//m.BSTtoDoubleLinkedList();
	//vector<vector<int>> m{
	//{1, 2, 3},
	//{4,2,5},
	//{3,7,9}
	//};
	//LongestIncPath mm;
	//cout << mm.maxPath(m) << endl;
	//cout << mm.maxPath2(m) << endl;
	//cout << mm.maxPath3(m) << endl;
	//vector<int> v{ 7, -10, 1, 0, 4, 5, -8, -8 };
	//LongestIncSub m;
	////cout << m.longestIncSUb2(v);
	//
	//vector<LongestIncSub::ClaData> v2{ LongestIncSub::ClaData(1, 4), LongestIncSub::ClaData(4, 6), LongestIncSub::ClaData(1, 5) };
	//cout << m.longestIncSUb3(v2);	
	//vector<int> v{ 7, 0, 1, 0, 4, 4, -8, -8 };
	//OddCountNum m;
	//cout << m.oddCountNum2(v) << endl;
	//vector<int> v2{ -17, -8,-8, -8,7,7,7};
	//cout << m.oddCountNum3(v2,3) << endl;	
	//IsPalinInLR m;
	//string str("112332");
	//cout << m.isPalinInLR(str, 2, 5) << endl;
	//cout << m.isPalinInLR_dp(str, 2, 5) << endl;
	//vector<int> v{ 7,0,0,0,4,3,-8,4,2,1,-9 };
	//SubArrayIsAim m;
	////cout << m.subArrayIsAim2(v);
	//cout << m.sub2ArrayIsAim(v);
	//vector<int> v{ 2, 10, 5};
	//SumIsAim2 m;
	//m.sumIsAim(v, 17);
	//vector<int> v{ 1, 2, 3, 4, 5 };
	//SearchBin m;
	//cout << m.binSearch(v, 2) << endl;
	//cout << m.binSearch_lower(v, 2) << endl;
	//cout << m.binSearch_upper(v, 2) << endl;
	//vector<int> v{ 1, 2, 3, 4, 5 };
	//SumIsAimSub m;
	//m.sumIsAimSub(v, 10);
	//cout << m.sumIsAimSub2(v, 10);
	//vector<int> v{ 1, 3, 0, 2, 0, 9 };
	//MaxFromZeroToI m;
	//vector<int> ret = m.maxFromZeroToI(v);
		//AddSubMutliDivde m;
	//cout << m.add(10, -13)<<endl;
	//cout << m.sub(10, -13) << endl;
	//cout << m.mutli(10, -13) << endl;
	//cout << m.div(7, 17) << endl;
	//BinaryTree m;
	//string str = m.serialTreePre();
	//cout << str << endl;
	//BinaryTree::Tree* node = m.unserialTreePre(str);
	//cout << power(10, 3);
	//vector<int> v1{ 1, 2, 3 };
	//vector<int> v2{ 1, 2, 3 };
	//vector<int> v3{ 1, 2, 3 };
	//vector<vector<int> > mat{ v1, v2, v3 };
	//RotateMat m;
	//m.zigzigPrint(mat);
	//string str = "#!123!#!";
	//cout << stoi(str);
	//vector<int> v{ 2, 1, 3, 1, 0, 2, 5, 3 };
	//JumpGame m;
	//cout << m.jumpGame(v);
	//BinaryTree2 m;
	//m.aigaigPrint();
	//int sum = 0;
	//vector<int> v;
	//cout << m.pathIsAim(m.root, 205, sum,v);
	//vector<int> v{ 2,1,3,1,0,2,5,3 };
	//DuplicatonInArray m;
	//cout << m.duplicatonInArray(v);
	return 0;
}
int main1(){

	//AddSubMutliDivde m;
	//cout << m.add(10, -13)<<endl;

	//cout << m.sub(10, -13) << endl;

	//cout << m.mutli(10, -13) << endl;
	//cout << fun(234, 32);


	//vector<int> v{ 1, 2, 3, 5,8,9,10, 89 };
	//SumIsAim m;
	//pair<int, int> ret = m.sumIsAim(v, 8);
	//vector<vector<int>> ret2 = m.sumIsAim2(v, 3);
	//cout << endl;


	//vector<int> v{ 1, 10, 3, 2, 3, 89 };
	//sort(v.begin(), v.end(), Fun());
	//cout << endl;
	//vector<int> v{ 1, 0, -3, 2, 3 ,-89};
	//SubArrayMax m;
	//cout << m.subArrayMax2(v);



	//vector<int> v1{ 1, 2, 3 }; vector<int> v;
	//ArrayPermutation m;
	//m.arrayPermutation(v1, 0);
	//cout << endl;
	//m.arraySub(v1, 0,v);


	//vector<int> v1{ 1, 2, 3, 0 ,9};
	//ReoderOddEven m;
	//m.reoderOddEven3(v1);
	//cout << endl;

	//vector<int> v1{ 1, 2, 3 ,0};
	//MinNumberInRatatedArray m;
	//cout << m.minNumberInRatatedArray(v1);
	//PowerN m;
	//cout << m.powerN(10, 7);




	//PrintEdge m;
	//vector<int> v1{ 1, 2, 3 };
	//vector<int> v2{ 1, 2, 3 };
	//vector<int> v3{ 1, 2, 3 };
	//vector<int> v4{ 1, 2, 3 };
	//vector<int> v5{ 1, 2, 3 };

	//vector<vector<int> > mat{ v1, v2, v3 };
	////m.printEdge(mat);

	//RotateMat mt;
	//mt.ratateMat(mat);
	//StrNumSum m;
	//cout << m.strNumSum(string("a-1bc--12"));


	//IsDeformation m;
	//cout << m.isDeformation(string("12345"), string("43621"));
	//calcPI m;
	//cout << rand() / RAND_MAX;
	//cout << m.pi(10000);
	//string str1 = "abcaIIabbcab";
	//Longetsethuiwen m;
	//cout << m.longesthuiwen(str1);


	/*string str2 = "45";
	SubString m;
	cout << m.duan2(str1);*/

	/*vector<vector<int>> m{
		{1, 2, 3},
		{4,3,5},
		{3,7,9}
	};
	
	LongestIncPath mm;
	cout << mm.maxPath(m);*/
	/*vector<string> v{ "eat", "tea", "tan", "ate", "nat", "bat" };
	WordLadder m;
	vector<vector<string>> res = m.group_Anagrams(v);*/

	/*int a[257] = { 0 };
	stringstream ss;
	for (int i = 1; i < 257; ++ i){
		a[i] += i;
		ss << a[i] << " ";
	}
	cout << ss.str();*/
	//int a[5] = { 3, 2, 4, 9, 5 };
	//int index[5] = { 0,1,2,3,4 };
	//TwoSum m;
	////pair<int, int> n = m.twoSum(a, 5, 8);
	//m.sort(a, index, 5);
	////cout << n.first << " " << n.second << endl;

	return 0;
}
int main1111(){
	Josephus j;
	j.loop(3);
	//cout << d();
	//vector<int> v{ 4,1, 2, 3, 4 };
	//LocalMin lm;
	//cout << lm.localMin(v)<<endl;
	/*BinaryTree t;
	t.postOrder();*/
	/*PaperFoler f;
	f.paerFlod(1, 3, "down");*/
	/*priority_queue<int, vector<int>, greater<int >> qsmall;
	qsmall.push(4);
	qsmall.push(3);
	qsmall.push(6);

	while (!qsmall.empty()){
		cout << qsmall.top() << endl;
		qsmall.pop();
	}*/
	//int res = 0;
	//IsSum sm;
	//vector<int> v2{ 7, 6, 9, 1 };
	//cout << sm.isSum(v2, 0, 16, res);

	/*MinPath M;
	vector<int> v1{ 3, 2, 1, 0 };
	vector<int> v2{ 7,6,0,1 };
	vector<int> v3{ 9,7,8,2 };
	vector<vector<int>> v{ v1,v2,v3 };
	cout << M.minPath2(v, 0, 0)<<endl;*/
	/*Quanpailie as;
	string s("abc"),s2;
	as.quanpailie(s, 0);
	as.qsub(s, 0,s2);*/

	/*Tire t;
	t.insert("abc");
	t.insert("abd");
	t.insert("acf");
	t.insert("afg");
	t.prefixNumber("ab");
	t.deleteString("abd");*/
	/*int a[10] = { 1, 2, 3, 5, 6, 6, 9, 89, 99, 100 };
	MidianHolder m;
	for (int i = 0; i < 10; ++i){
		m.push(a[i]);
		cout << m.getMidian() << endl;
	}*/
	/*int a[10] = { 1, 2, 3, 5, 6, 6, 9, 89, 99, 100 };
	Lower_Upper_Bound m;
	cout << m.lower_bound(a, 10, 6) <<endl;
	cout << m.lower_bound(a, 10, 60) << endl;
	cout << m.upper_bound(a, 10, 6) << endl;
	cout << m.upper_bound(a, 10, 60) << endl;*/

	/*int ii[] = { 1, 8, 3, 4, 9, 2, 8, 4, 0, -6, 300, 9, 77, -90 };
	Find10MinElementFromHugeData m;
		m.find10MinElementFromHugeData(ii, 14);*/
		//cout << m.partition3(ii, 14);

	/*queue<int> q1; queue<int> q3;
	q1.swap(q3);
	int i[] = { 0, -6 ,300, 9, 77, -90};
	AdjacentMax m;
	cout << m.adjacentMax(i, 6);*/

//	int ii[] = { 1, 8, 3, 4, 9, 2 ,8, 4 };
//	//m.partition2(ii, 0, 4);
//	cout << m.partition3(ii, 0, 7);
//
//
	/*

	
	MergeSortXiaoshudui mm;
	cout << mm.mergeSort(ii, 5);*/
  	return 0;
}

class Problem{
public:
	int Perfect_Rectangle(vector<vector<int>>& m){
		if (m.size() < 1 || m[0].size() != 4){
			return -1;
		}
		int x1 = INT_MAX;
		int y1 = INT_MAX;
		int x2 = INT_MIN;
		int y2 = INT_MIN;
		string x1y1, x1y2, x2y2, x2y1;
		set<string> s;
		for (size_t i = 0; i < m.size(); ++i){
			x1 = min(x1, m[i][0]);
			y1 = min(y1, m[i][1]);
			x2 = max(x2, m[i][2]);
			y2 = max(y2, m[i][3]);

			x1y1 = to_string(x1) + "_" + to_string(y1);
			x1y2 = to_string(x1) + "_" + to_string(y2);
			x2y2 = to_string(x2) + "_" + to_string(y2);
			x2y1 = to_string(x2) + "_" + to_string(y1);

			if (s.find(x1y1) == s.end()){
				s.insert(x1y1);
			}
			else{
				s.erase(x1y1);
			}
			if (s.find(x1y2) == s.end()){
				s.insert(x1y2);
			}
			else{
				s.erase(x1y2);
			}

			if (s.find(x2y2) == s.end()){
				s.insert(x2y2);
			}
			else{
				s.erase(x2y2);
			}
			if (s.find(x2y1) == s.end()){
				s.insert(x2y1);
			}
			else{
				s.erase(x2y1);
			}
		}
		x1y1 = to_string(x1) + "_" + to_string(y1);
		x1y2 = to_string(x1) + "_" + to_string(y2);
		x2y2 = to_string(x2) + "_" + to_string(y2);
		x2y1 = to_string(x2) + "_" + to_string(y1);
		if (s.size() != 4
			|| s.find(x1y1) == s.end()
			|| s.find(x1y2) == s.end()
			|| s.find(x2y2) == s.end()
			|| s.find(x2y1) == s.end()){
			return -1;
		}
		return (x2 - x1)*(y2 - y1);
	}

	//数组子序列累加和>=K的最小值
	int subAccK(vector<int>& v, int i, int sum, int K){
		if (i == v.size()){
			return sum >= K ? sum : INT_MAX;
		}
		return min(subAccK(v, i + 1, sum, K), subAccK(v, i + 1, sum + v[i], K));
	}
	int subAcc(vector<int>& v){
		int sum = 0;
		for (auto data : v){
			sum += data;
		}
		vector<vector<int>> dp(v.size(), vector<int>(sum + 1, -1));
		dp[0][0] = 0;
		dp[0][v[0]] = v[0];
		for (int i = 1; i < v.size(); ++i){
			for (int j = 0; j <= sum; ++j){
				dp[i][j] = dp[i - 1][j];
				if (j - v[i] > -1 && dp[i - 1][j - v[i]] != -1){
					dp[i][j] = j;
				}
			}
		}

		for (int j = sum; j > -1; --j){
			cout << dp[v.size() - 1][j] << " ";
		}
		cout << endl;
		int temp = 0;
		for (int j = sum; j > -1; --j){
			if (dp[v.size() - 1][j] != -1){
				temp = dp[v.size() - 1][j];
			}
			else{
				dp[v.size() - 1][j] = temp;
			}
		}
		for (int j = sum; j > -1; --j){
			cout << dp[v.size() - 1][j] << " ";
		}
		cout << endl;
		return 0;
	}
	//回文最小分割数（学会如何试答案，让计算机计算）
	int cut(string& str, int i){
		if (i >= str.size() - 1){
			return 0;
		}
		int mi = INT_MAX;
		for (int k = i; i < str.size(); ++i){
			if (isP(str, i, k)){
				mi = min(mi, cut(str, k + 1));
			}
		}
		return mi + 1;
	}
	int isP(string& str, int i, int k){
		while (i < k){
			if (str[i] != str[k]){
				return 0;
			}
			++i; --k;
		}
		return 1;
	}
	int isP_dp(string& str ){
		vector<vector<int>> dp(str.size(), vector<int>(str.size(),0));
		for (int i = 1; i < str.size(); ++i){
			if (str[i - 1] == str[i]){
				dp[i - 1][i] = 1;
			}
			dp[i][i] = 1;
		}
		dp[0][0] = 1;
	
		for (int j = 2; j < str.size(); ++j){
			for (int i = 0; i <= j - 2; ++i){
				if (str[i] == str[j] && dp[i + 1][j - 1] == 1){
					dp[i][i] = 1;
				}
			}
		}
	}
};
//class IsBalance{
//public:
//	struct RetuenData{
//		int height;
//		bool isB;
//	};
//	RetuenData isBalance(Tree* head){
//		if (head == nullptr){
//			RetuenData{ 0, 1 };
//		}
//		RetuenData L = isBalance(head->left);
//		RetuenData R = isBalance(head->right);
//		if (L.isB && R.isB && abs(L.height - R.height) <= 1){
//			return RetuenData{ max(L.height, R.height) + 1, 1 };
//		}
//		return RetuenData{ max(L.height, R.height) + 1, 0 };
//	}
//};
class PrintMaxTopK2{
public:
	struct Node_Top{
		int num;
		int bocket;
		int index;
	};
	class Comp{
	public:
		bool operator()(const Node_Top& x, const Node_Top& y){
			return x.num < y.num;
		}
	};
	int printMaxTopK(vector<vector<int>>& m,int K){
		priority_queue<Node_Top, vector<Node_Top>, Comp> pq;
		for (int i = 0; i < m.size(); ++i){
			pq.push(Node_Top{ m[i].back(), i, m[i].size() - 1 });
		}
		for (int i = 0; i < K; ++i){
			if (pq.empty()){
				break;
			}
			Node_Top temp = pq.top();
			pq.pop();
			cout << temp.num << " from " << temp.bocket << " group and index is " << temp.index << endl;
			if (temp.index != 0){
				pq.push(Node_Top{ m[temp.bocket][temp.index - 1], temp.bocket, temp.index - 1 });
			}
		}
	}
};
//表达式计算
class StringCalc{
public:
	int stringCalc(string& str, int& i){
		int ret = 0;
		stack<string> s;
		for (; i < str.size(); ++i){
			if (str[i] == '('){
				++i;
				int res = stringCalc(str, i);
				s.push(to_string(res));
			}
			else if (str[i] == '-'){
				++i;
				string strtemp;
				while (i < str.size() && isdigit(str[i])){
					strtemp += str[i];
				}
				s.push(strtemp);
			}
			else if(str[i] == ')'){
				string str1;
				string flag;
				string str2;
				while (s.size() != 1){
					str1 = s.top(); s.pop();
					flag = s.top(); s.pop();
					str2 = s.top(); s.pop();
					if (flag == "-"){
						s.push(to_string(stoi(str1) - stoi(str2)));
					}
					else{
						s.push(to_string(stoi(str1) + stoi(str2)));
					}
				}
				str1 = s.top(); s.pop();
				return stoi(str1);
			}
			else {
				int ingter = 0;
				while (i < str.size() && str[i] != '(' && str[i] != ')'){
					if (str[i] == '-' || str[i] == '+' || str[i] == '/' || str[i] == '*'){
						if (s.top() == "*"){
							s.pop();
							int tempint = stoi(s.top()); s.pop();
							s.push(to_string(tempint * ingter));
						}else if(s.top() == "/"){
							s.pop();
							int tempint = stoi(s.top()); s.pop();
							s.push(to_string(tempint / ingter));
						}
						s.push(string(1,str[i]));
						ingter = 0;
					}
					else{
						ingter = ingter * 10 + str[i] - '0';
					}
				}
			}
		}
		string str1;
		string flag;
		string str2;
		while (s.size() != 1){
			str1 = s.top(); s.pop();
			flag = s.top(); s.pop();
			str2 = s.top(); s.pop();
			if (flag == "-"){
				s.push(to_string(stoi(str1) - stoi(str2)));
			}
			else{
				s.push(to_string(stoi(str1) + stoi(str2)));
			}
		}
		str1 = s.top(); s.pop();
		return stoi(str1);
	}
};
//换钱的方法数
class FangFaShu{
public:

	int fangfashu(vector<int>& v, int i,int K){
		int ret = 0;
		if (K == 0){
			return 1;
		}
		sort(v.begin(), v.end(),greater<int>());
		int index = 0;
		for (; i < v.size(); ++i){
			if (v[i] <= K){
				index = i;
				break;
			}
		}
		if (i == v.size()){
			return 0;
		}
		int count = K / v[index];
		for (int j = count; j > -1; --j){
			int temp = fangfashu(v, index + 1, K - v[index] * j);
			if (temp != 0){
				ret += temp;
			}
		}
		return ret;
	}
	int fangfashu2(vector<int>& v,int K){		
		if (K <= 0){
			return 1;
		}
		sort(v.begin(), v.end(), greater<int>());
		if (v.back() > K){
			return 0;
		}
		return fangfashu2_core(v, 0, K);
	}
	int fangfashu2_core(vector<int>& v, int i, int K){
		int ret = 0;
		if (K == 0){
			return 1;
		}
		auto index = lower_bound(i + v.begin(), v.end(), K, greater<int>());
		if (index == v.end()){
			return 0;
		}
		for (int zhang = K / (*index); zhang > -1; --zhang){
			ret += fangfashu2_core(v, index - v.begin() + 1, K - zhang*(*index));
		}
		return ret;
	}
	int minzhangshu(vector<int>& v, int i, int K){
		if (K == 0){
			return 0;
		}
		if ( (0 > K) || (i == v.size())){
			return INT_MAX;
		}
		int res = INT_MAX;
		for (int zhang = 0; zhang*v[i] <= K; ++zhang){	
			int ret = minzhangshu(v, i + 1, K - zhang*v[i]);
			if (ret != INT_MAX){
				res = min(ret+zhang, res);
			}
		}
		return res;
	}
	int minzhangshu_dp(vector<int>& v ,int K){

		vector<vector<int>> dp(v.size() + 1, vector<int>(K + 1, INT_MAX));
		for (int i = 0; i < dp.size(); ++i){
			dp[i][0] = 0;
		}
		for (int i = dp.size() - 2; i > -1; --i){
			for (int j = 0; j < dp[0].size(); ++j){
				for (int zhang = 0; zhang*v[i] <= j;++zhang){
					if (dp[i + 1][j - zhang*v[i]] != INT_MAX){
						dp[i][j] = min(dp[i][j], dp[i + 1][j - zhang*v[i]] + zhang);
					}
				}
			}
		}
		for (int i = 0; i < dp.size();++i){
			for (int j = 0; j < dp[0].size(); ++j){
				if (dp[i][j] == INT_MAX){
					cout << setw(2) << -1 << " ";
				}
				else{
					cout << setw(2) << dp[i][j] << " ";
				}
			}
			cout << endl;
		}
		return dp[0][K] == INT_MAX ? -1 : dp[0][K];
	}
	//最少张数
	int minzhangshuonlyonce(vector<int>& v, int i, int K){
		if (K == 0){
			return 0;
		}
		if (i == v.size()){
			return -1;
		}
		int r1 = -1;
		r1 = minzhangshuonlyonce(v, i + 1, K - v[i]);
		int r2 = -1;
		r2 = minzhangshuonlyonce(v, i + 1, K);

		if (r1 == -1 && r2 == -1){
			return -1;
		}
		else if (r1 != -1 && r2 != -1){
			return min(r1 + 1, r2);
		}
		else if (r1 == -1){
			return r2;
		}
		else{
			return r1 + 1;
		}
	}
	int minzhangshuonlyonce_dp(vector<int>& v, int K){
		vector<vector<int>> dp(v.size() + 1, vector<int>(K + 1, -1));
		for (int i = 0; i < dp.size(); ++i){
			dp[i][0] = 0;
		}
		for (int i = dp.size() - 2; i > -1; --i){
			for (int j = 1; j <= K; ++j){
				if (j - v[i] >= 0){
					if (dp[i + 1][j] != -1 && dp[i + 1][j - v[i]] != -1){
						dp[i][j] = min(dp[i + 1][j], dp[i + 1][j - v[i]] + 1);
					}
					else if (dp[i + 1][j] == -1 && dp[i + 1][j - v[i]] == -1){
						dp[i][j] = -1;
					}
					else if (dp[i + 1][j] == -1){
						dp[i][j] = dp[i + 1][j - v[i]] + 1;
					}
					else{
						dp[i][j] = dp[i + 1][j];
					}
				}
				else{
					dp[i][j] = dp[i + 1][j];
				}
			}
		}
		return dp[0][K];
	}

	//
};
//纸牌博弈
//
//class ZhiPaiBoYi{
//public:
//	struct Node_ZhiPai{
//		int A;
//		int B;
//	};
//	Node_ZhiPai zhiPaiBoYi(vector<int>& v, int st, int en, bool isA){
//		if (st == en){
//			if (isA){
//				return Node_ZhiPai{ v[st], 0 };
//			}
//			else{
//				return Node_ZhiPai{ 0, v[st] };
//			}
//		}
//		Node_ZhiPai
//	}
//};
class  NewType{
public:
	string newType(string& str,int k){
		string ret;
		size_t i = 0;
		while (i < str.size()){
			if (str[i] <= 'z' && str[i] >= 'a'){
				ret = str[i];
			}
			else{
				ret = str[i++];
				ret += str[i];
			}
			if (k <= i){
				return ret;
			}
			++i;
		}
	}
};
int main3(){
	//Problem m;
	//vector<int> v{ 2, 10, 5 };
	//cout << m.subAccK(v, 0, 0, 3) << endl;
	//cout << m.subAcc(v) << endl;

	//vector<int> v{ 3,5 };
	//vector<int> v{ 5, 10, 25, 1 };
	//FangFaShu m;
	//cout << m.fangfashu2(v, 15);
	//string str("aaABCDEcBCg");
	//NewType m;
	//cout << m.newType(str, 10) << endl;
	
	//UnionSet mm;
	//vector<string> v{ "123", "456", "789" };
	//mm.makeSets(v);
	//cout << mm.isSameSet(v[0], v[1]) << endl;
	//mm.unionSet(v[0], v[1]);
	//cout << mm.isSameSet(v[0], v[1]) << endl;

	//cout << mm.isSameSet(v[2], v[1]) << endl;
	/*FangFaShu FFS;
	vector<int> v{ 5, 2, 3 ,4};
	cout << FFS.minzhangshu(v, 0, 20) << endl;
	cout << FFS.minzhangshu_dp(v, 20) << endl;*/

	FangFaShu FFS;
	vector<int> v{ 1,5,10,20,50,100 };
	//cout << FFS.minzhangshuonlyonce(v, 0, 10) << endl;
	//cout << FFS.minzhangshuonlyonce_dp(v, 10) << endl;
	/*
	cout << FFS.fangfashu2(v, 8845) << endl;*/

	//sort(v.begin(), v.end());
	return 0;
}
#endif