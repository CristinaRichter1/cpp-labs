#include<iostream>
#include<list>
#include<vector>
#include<set>
#include<map>
#include<string>

using namespace std;

template <class T> class MyCustomList{
private:
	T* list;
	int index = 0;
public:
	MyCustomList(int length){
		this->list = new T[length];
	}

	void adauga(T item){
		this->list[index] = item;
		index++;
	}

	int getSize(){
		return  this->index;
	}

	T& operator[](int i){
		return this->list[i];
	}
	
	int adauga(T t1, T t2){
		return t1 + t2;
	}

};


int main(){
	MyCustomList<string> myCustomList(100);
	//cout << myCustomList.adauga(10.2, 20.9);

	myCustomList.adauga("a");
	myCustomList.adauga("b");
	myCustomList.adauga("c");

	for (int i = 0;
		i < myCustomList.getSize();
		i++){
		cout << myCustomList[i];
	}

	cout << endl;

	list<int> myList;

	myList.push_back(1);
	myList.push_back(2);
	myList.push_front(3);
	myList.push_front(4);
	myList.push_front(5);
	// 5 4 3 1 2\

	myList.remove(3);
	myList.sort();


	std::list<int>::iterator itrList;
	for (itrList = myList.begin();
		itrList != myList.end();
		itrList++){

		cout << *itrList;
	}

	vector<int> myVector;
	myVector.push_back(1);
	myVector.pop_back();
	myVector.push_back(2);
	myVector.push_back(3);
	myVector.push_back(4);

	cout << endl;
	
	std::vector<int>::reverse_iterator itrVector;

	for (itrVector = myVector.rbegin();
		itrVector != myVector.rend();
		itrVector++){
		cout << *itrVector;
	}

	set<int> mySet;
	mySet.insert(1);
	mySet.insert(2);
	mySet.insert(3);
	mySet.insert(4);
	mySet.insert(1);

	cout << endl;
	 
	std::set<int>::iterator itrSet;
	for (itrSet = mySet.begin();
		itrSet != mySet.end();
		itrSet++){
		cout << *itrSet;
	}

	map<int, string> myMap;
	myMap.insert(make_pair(1, "ion"));
	myMap.insert(make_pair(2, "vasile"));
	myMap.insert(make_pair(3, "razvan"));

	cout <<endl << "key 1 : value "<< myMap.find(1)->second;
	cout << endl;
	map<int, string>::iterator itrMap;
	for (itrMap = myMap.begin();
		itrMap != myMap.end();
		itrMap++){
		cout << itrMap->first 
			<< " " << itrMap->second;
	}
	return 0;
}