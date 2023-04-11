#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> price;
vector<int> h;
vector<int> z;
int x, y;
int n, q;

void readInput()
{
    cin >> n >> q;
    price.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    sort(price.begin(), price.end());
}


int getClosest(int left,int right){
    int val1 = z[left]  ;
    int val2 = z[right] ;

    if (x - val1 >= val2 - x)
        return right;
    else
        return left;
}

int findClosest(int n) {
    if (x < z[0])
        return -1;

    if (x >= z[n - 1])
        return n-1;

    // Doing binary search
    int i = 0, j = n, mid = 0;
    while (i < j)
    {
        mid = (i + j) / 2;

        if (z[mid] == x)
            return mid;

        /* If target is less than array element,
            then search in left */
        if (x < z[mid])
        {

            // If target is greater than previous
            // to mid, return closest of two
            if (mid > 0 && x > z[mid - 1])
                return getClosest(mid-1,mid);
            j = mid ;
        }
        else
        {
            if (mid < n - 1 && x < z[mid + 1])
                return getClosest(mid,mid+1);
            // update i
            i = mid + 1;
        }
    }

    return mid;
}


int main()
{
    readInput();

    for (int i = 0; i < q; i++)
    {
        cin >> x >> y;
        h.clear();
        z.clear() ;
        for (auto p = price.begin(); p < price.end(); p++)
        {
            if (*p >= y)
            {
                h.assign(p, price.end());
                break;
            }
        }
        int Summer = 0;
        for (int i = 0; i < h.size(); i++)
        {
            Summer += h[i];
            z.push_back(Summer);
            // cout << Summer << ' ' ;
        }
        // cout << '|' << x << ' ' << y  <<endl;

        cout << findClosest(h.size())+1<< endl;
    }
}