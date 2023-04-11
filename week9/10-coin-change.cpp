#include <iostream>
#include <vector>
using namespace std;

int s[8192];
vector <int> coins ;
int money;

void init() {
    coins.push_back(50);
    coins.push_back(25);
    coins.push_back(10);
    coins.push_back(5);
    coins.push_back(1);
    s[0] = 1;
}


int main(){
    init();
    for (int i = 0; i < 5; ++i)
        for (int j = coins[i]; j < 8192; ++j)
            s[j] += s[j - coins[i]];

    while (cin >> money) {
        cout << s[money] << endl;        
    }
    return 0;
}