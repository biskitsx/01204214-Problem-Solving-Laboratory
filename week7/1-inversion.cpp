#include<iostream>
#include<vector>
using namespace std;

int n, i ; 
vector <int> arr ; 

void readInput() {
    cin >> n ;
    arr.resize(n) ; 
    for (i=0;i<n;i++) {
        cin >> arr[i] ; 
    }
}

long long merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    long long inversionCount = 0;

    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } 
        else {
            temp[k++] = arr[j++];
            inversionCount += mid - i + 1;
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }

    return inversionCount;
}

long long mergeSort(vector<int>& arr, int left, int right) {
    long long inversionCount = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;
        inversionCount += mergeSort(arr, left, mid);
        inversionCount += mergeSort(arr, mid + 1, right);
        inversionCount += merge(arr, left, mid, right);
    }

    return inversionCount;
}


int main() {
    readInput() ; 
    cout << mergeSort(arr,0,n-1) ; 
}