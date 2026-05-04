/// C++ source code

#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> arr, int size, int target)
{
    int left = 0;int right = size - 1;
    while(left <= right){
        int mid = left + (right - left); 
        if (target == arr[mid])
            return mid;
        else if(target >= arr[mid])
            left = mid + 1;
        else 
            right = mid - 1;
    }

    return -1;
    
}

int main()
{
    int temp, m, size, tg;
    cout<<"how many elements"<<endl;
    cin>>m;
    vector<int> data;
    for(int i = 1;i<=m;i++)
    {
        cout<<"element "<<i<<" 's value: ";
        cin>>temp;
        data.push_back(temp);
    }
    for(int i = 0;i<data.size()-1;i++)
    {
        for(int k = i + 1;k<data.size();k++)
        {
            if(data[i] > data[k])
            {
                temp = data[k];data[k] = data[i];data[i] = temp;
            }
        }
    }

    cout<<"elements : ";
    for(int i = 0;i<data.size();i++)
    {
        cout<<data[i]<<(i < data.size()-1 ? ", " : "" );
    }
    
    size = data.size();

    cout<<"\ntarget data : ";
    cin>>tg;
    tg = search(data, size, tg);
    if (tg == -1)
    {
        cout<<"element not found"<<endl;
    }else{
        cout<<"-->"<<tg + 1<<endl;
    }

    return 0;
    
}
