/// C++ source code

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void quicksort(vector<int>& data, int left, int right) {
    if (left >= right) return;

    int pivot = data[right];
    int i = left - 1;
    
    for(int j = left; j < right; j++){
        if (data[j] < pivot){
            i++;
            swap(data[i], data[j]);
        }
    }

    swap(data[i+1], data[right]);
    int pivotIndex = i + 1;

    quicksort(data, pivotIndex + 1, right);
    quicksort(data, left, pivotIndex - 1);
}

int main()
{
    vector<int> data;
    string input, temp;
    cout << "enter datas (sperated by commas) : ";
    getline(cin, input);
    stringstream ss(input);

    while(getline(ss, temp, ',')){
        data.push_back(stoi(temp));
    }

    quicksort(data, 0, data.size() - 1);

    for(int n : data){
        cout << n << " ";
    }

    cout << endl;
    return 0;
}
