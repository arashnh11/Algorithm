/* This program will find the input in an unsorted list
using hybrid vector pair structure
Arash Nemati Hayati
30 March 2018 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findval(vector<int> & list, int input){
	int n = list.size();
	vector< pair<int, int> > slist;
	pair<int, int> temp;

	for (int i = 0; i < n; ++i){
		temp.first = list[i];
		temp.second = i;
		slist.push_back(temp);
	}
	sort(slist.begin(), slist.end());

int low = 0;
int high = n - 1;
int mid;
while (low <= high){
	mid = low + (high - low) / 2;
	if (input == slist[mid].first){
		cout << "Input " << input << " was found at index " << slist[mid].second << endl;
		return slist[mid].second;
	}
	else {
		if (input < slist[mid].first){
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
}
	cout << "Input " << input << " not found \n";
	return -1;
}

int main(){
	vector<int> list;
	int n = 10;
	int input = 4;
	for (int i = n - 1; i > 0; --i){
		list.push_back(2 * i);
		cout << list[(n - 1) - i] << " ";
	}
	cout << "\n";
	findval(list, input);
}
