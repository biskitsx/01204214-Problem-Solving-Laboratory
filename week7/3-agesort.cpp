#include<iostream>
#include<vector>

using namespace std;

int n = 1  , i, j, x ;

vector <int> arr ;
vector <vector<int> > output ; 

void merge(int left ,int mid, int right) {
    vector <int> temp(right-left+1) ; 

    int i = left ;
    int j = mid+1 ;
    int k = 0 ;

    //เทียบฝั่งซ้ายและขวา หาตัวที่น้อยกว่า แทนลง temp
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i] ; 
            i++ ; 
        }
        else {
            temp[k] = arr[j] ; 
            j++ ;
        }
        k++ ;
    }

    //ถ้าฝั่งซ้ายเหลือให้แทนลง temp หมดเลย
    while (i <= mid) {
        temp[k] = arr[i] ; 
        i++ ;
        k++;
    }

    //ถ้าฝั่งขวาเหลือให้แทนลง temp หมดเลย
    while (j <= right) {
        temp[k] = arr[j] ;
        j++ ;
        k++;
    }

    for (i = left, k=0 ; i <= right ; i++,k++) {
        arr[i] = temp[k] ; 
        // cout << arr[i] << ' ' ; 
    }
    // cout << '\n' ; 
    
}

void mergeSort(int left, int right) {
    if (left < right) {
        int mid = (left + right)/2 ;
        mergeSort(left,mid) ; 
        mergeSort(mid+1,right) ; 
        merge(left,mid,right) ; 
    }
}

void printArr() {
    
    int i ;
    for (i = 0; i<n-1; i++) {
        cout << arr[i] << ' ' ; 
    }
    cout << arr[n-1] << endl;
}

int main() {
    while(n!=0) {
        cin >> n ;
        if (n==0) {
            break;
        }
        arr.clear() ; 
    
        for (i=0;i<n;i++) {
            cin >> x ;
            arr.push_back(x) ;
    
        }
        mergeSort(0,n-1) ; 
        printArr() ;   
    }
}