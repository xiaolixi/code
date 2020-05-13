#include "common.h"


class Sort{
public:
	//随机产生数据
	vector<int> generateVector(size_t n){
		vector<int> ret(n, 0);
		srand((unsigned(time(NULL))));
		for (size_t i = 0; i < n; ++i){
			ret[i] = rand() % 1000;
		}
		return ret;
	}
	//获取正确的排序
	vector<int> getRealOrder(vector<int>& v){
		vector<int> ret = v;
		sort(ret.begin(), ret.end(), less<int>());
		return ret;
	}
	//比较是否相同
	bool isSame(vector<int>& real, vector<int>& test){
		if (test.size() != real.size()){
			return false;
		}
		for (size_t i = 0; i < real.size(); ++i){
			if (real[i] != test[i]){
				return false;
			}
		}
		return true;;
	}
	//打印序列
	void printVector(vector<int>& v){
		for (auto& d : v){
			cout << d << " ";
		}
		cout << endl;
	}

public:
	//插入排序
	void insertSort(vector<int>& v){
		for (size_t i = 1; i < v.size(); ++i){
			int temp = v[i];
			int j = (int)(i - 1);//把小的往前移动
			for (; j > -1 && v[j] > temp; --j){
				v[j + 1] = v[j];
			}
			v[j + 1] = temp;
		}
	}
	//希尔排序
	void shellSort(vector<int> & v){

	}
	//选择排序
	void selectSort(vector<int>& v){
		int n = (int)v.size();
		for (int i = 0; i < n - 1; ++i){
			int smallest = i;//找最小的
			for (int j = i + 1; j < n; ++j){
				if (v[j] < v[smallest]){
					smallest = j;
				}
			}
			swap(v[smallest], v[i]);
		}
	}
	//堆排序
	void heapSort(vector<int>& v){		
		for (int i = 1; i < (int)(v.size()); ++i){
			build_heap(v, 0, i);
		}
		for (int i = (int)(v.size()) - 1; i > 0; --i){
			swap(v[0], v[i]);
			adjust_heap(v, 0, i);
		}
	}
	void build_heap(vector<int>& v, int heap_top, int i){
		while (i > heap_top && v[(i - 1) / 2] < v[i]){
			swap(v[(i - 1) / 2], v[i]);
			i = (i - 1) / 2;
		}
	}
	void adjust_heap(vector<int>& v, int heap_top, int heap_size){
		int child = heap_top * 2 + 1;
		while (child < heap_size){
			child = (child + 1 < heap_size && v[child + 1] > v[child]) ? child + 1 : child;
			if (v[child] > v[heap_top]){
				swap(v[heap_top], v[child]);
				heap_top = child;
				child = child * 2 + 1;
			}
			else{
				break;
			}
		}
	}
	void bubleSort(vector<int>& v){
		int n = (int)(v.size());
		for (int i = n - 1; i > 0; --i){
			for (int j = 0; j < i; ++j){
				if (v[j] > v[j + 1]){
					swap(v[j], v[j + 1]);
				}
			}
		}
	}
	void quickSort(vector<int> & v, int left, int right){
		if (left >= right){
			return;
		}
		pair<int, int> pivot = partition(v, left, right);
		quickSort(v, left, pivot.first - 1);
		quickSort(v, pivot.second + 1, right);
	}
	pair<int, int> partition(vector<int> & arr, int left, int right){//荷兰国旗
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
		return make_pair(less + 1, more - 1);
	}
	void mergeSort(vector<int>&  arr, int left, int right){
		if (left >= right){
			return;
		}
		int mid = left + ((right - left) >> 1);
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
	void merge(vector<int>& arr, int left, int left_end, int right_end){
		int len = right_end - left + 1;
		vector<int> help(len, 0);
		int right = left_end + 1;
		int left_copy = left;
		int i = 0;
		while (left <= left_end && right <= right_end){
			help[i++] = arr[left] < arr[right] ? arr[left++] : arr[right++];
		}
		while (left <= left_end){
			help[i++] = arr[left++];
		}
		while (right <= right_end){
			help[i++] = arr[right++];
		}
		for (int i = 0; i < len; ++i){
			arr[left_copy++] = help[i];
		}
	}
	void mergeSort(vector<int>& v){
		int n = (int)(v.size());		
		for (int k = 1; k < n; k *= 2){
			for (int left = 0; left < n; left = left + 2 * k){
				int left_end = (left + k - 1 > n - 1) ? n - 1 : left + k - 1;
				int right_end = (left + 2 * k - 1 > n - 1) ? n - 1 : left + 2 * k - 1;			
				merge(v, left, left_end, right_end);
			}
		}
	}	
	//age排序
	void countingSort(vector<int>& v){
		//将元素放入排好序的木桶中，记录次数，在收集木桶元素即可
		int max_ele = *max_element(v.begin(), v.end());
		vector<int> bucket(max_ele + 1, 0);
		for (int i = 0; i < (int)(v.size()); ++i){
			bucket[v[i]]++;
		}
		int left = 0;
		for (int i = 0; i < (int)(bucket.size()); ++i){
			for (int count = 0; count < bucket[i]; ++count){
				v[left++] = i;
			}
		}
	}
	void bucketSort(vector<int>& v){
		const int bucket_num = 10;
		vector<vector<int>> bucket(bucket_num, vector<int>());
		auto ma_mi = minmax_element(v.begin(), v.end());
		int mi = *ma_mi.first;
		int ma = *ma_mi.second;
		int ge = (ma - mi) / (bucket_num - 1);
		for (int i = 0; i < (int)(v.size()); ++i){
			bucket[(v[i] - mi) / ge].push_back(v[i]);
		}
		int left = 0;
		for (int i = 0; i < bucket_num; ++i){
			insertSort(bucket[i]);
			for (auto& d : bucket[i]){
				v[left++] = d;
			}
		}
	}
	void radixSort(vector<int>& v){
		int max_ele = *max_element(v.begin(), v.end());
		int MSBone = 1;
		while (max_ele / MSBone >= 10){
			MSBone *= 10;
		}

		int n = (int)(v.size());
		vector<vector<int>> bucket(10, vector<int>());
		int help = 1;
		while (1){
			for (int i = 0; i < n; ++i){
				bucket[v[i] / help % 10].push_back(v[i]);
			}
			int i = 0;
			for (auto& data : bucket){
				for (auto& d : data){
					v[i++] = d;
				}
				data.clear();
			}
			if (help == MSBone){
				break;
			}
			help *= 10;
		}
	}
};



class SortProblem{
public:
	//出现次数最高的K个数
	vector<int> get_timeK_shu(vector<int>& v, int k){
		map<int, int> m;
		for (auto data : v){
			if (m.find(data) == m.end()){
				m[data] = 1;
			}
			else{
				++m[data];
			}
		}
		multimap<int, int> mm;
		for (auto& data : m){
			mm.insert(make_pair(data.second, data.first));
		}
		vector<int> ret;
		auto it = mm.crbegin();
		while (k-- != 0 && it != mm.crend()){
			ret.push_back(it->second);
			++it;
		}
		for (auto data : ret){ cout << data << " "; }
		return ret;
	}
	//字符串以字符出现的次数排序
	string get_new_string(string& str){
		map<char, int> m;
		for (auto& data : str){
			m.find(data) == m.end() ? m[data] = 1 : ++m[data];
		}
		multimap<int, char> m_ic;
		for (auto& data : m){
			m_ic.insert(make_pair(data.second, data.first));
		}
		string ret;
		for (auto it = m_ic.crbegin(); it != m_ic.crend(); ++it){
			ret.append(it->first, it->second);
		}
		return ret;
	}
};
#if 0
int main(){
	//vector<int> v{ 1, 3, 2, 2, 1, 1 };
	SortProblem SP;
	//SP.get_timeK_shu(v, 2);
	string str("tree");
	cout << SP.get_new_string(str) << endl;

	return 0;
}
#endif


//int main(){
//	if (0){
		//cout << "____________ SORT _________" << endl;
		//Sort SS;
		//vector<int> raw = SS.generateVector(20);
		//vector<int> order = SS.getRealOrder(raw);
		//SS.printVector(raw);
		//SS.printVector(order);
		//cout << SS.isSame(order, raw) << endl;

		//cout << "____________ insertSort _________" << endl;
		//SS.insertSort(raw);


		//SS.printVector(raw);
		//SS.printVector(order);
		//cout << SS.isSame(order, raw) << endl;

		//cout << "____________ selectSort _________" << endl;
		//SS.selectSort(raw);

		//SS.printVector(raw);
		//SS.printVector(order);
		//cout << SS.isSame(order, raw) << endl;
		//cout << "____________ bubleSort _________" << endl;
		//SS.bubleSort(raw);

		//SS.printVector(raw);
		//SS.printVector(order);
		//cout << SS.isSame(order, raw) << endl;

		//cout << "____________ mergeSort _________" << endl;
		//SS.mergeSort(raw);

		//SS.printVector(raw);
		//SS.printVector(order);
		//cout << SS.isSame(order, raw) << endl;


		//cout << "____________ quickSort _________" << endl;
		//SS.quickSort(raw,0,raw.size()-1);

		//SS.printVector(raw);
		//SS.printVector(order);
		//cout << SS.isSame(order, raw) << endl;


		//cout << "____________ heapSort _________" << endl;
		//SS.heapSort(raw);

		//SS.printVector(raw);
		//SS.printVector(order);
		//cout << SS.isSame(order, raw) << endl;


		//cout << "____________ countingSort _________" << endl;
		//SS.countingSort(raw);

		//SS.printVector(raw);
		//SS.printVector(order);
		//cout << SS.isSame(order, raw) << endl;

		//cout << "____________ radixSort _________" << endl;
		//SS.radixSort(raw);

		//SS.printVector(raw);
		//SS.printVector(order);
		//cout << SS.isSame(order, raw) << endl;

		//cout << "____________ bucketSort _________" << endl;
		//SS.bucketSort(raw);

		//SS.printVector(raw);
		//SS.printVector(order);
		//cout << SS.isSame(order, raw) << endl;
//	}
//	return 0;
//}