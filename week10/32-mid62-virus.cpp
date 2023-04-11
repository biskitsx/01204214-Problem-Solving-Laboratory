// #include<iostream>
// #include<vector>

// using namespace std; 

// int n, m, x, t;
// vector <int> dna ;
// int virusIndex = 0;

// void readInput() {
//     cin >> n >> m ;
//     dna.reserve(n);
//     for (int i=0 ;i<n;i++) {
//         cin >> x;
//         dna.push_back(x) ;
//     }
// }


// int main() {
//     readInput();

//     for (int i=0 ; i<m ;i++) {
//         cin >> t ;
//         switch (t){
//             //reset virusIndex
//             case 1:
//                 virusIndex = 0;
//                 break;
//             //next virusIndex
//             case 2:
//                 virusIndex++ ;
//                 if (virusIndex == dna.size()) {
//                     virusIndex = 0;
//                 }
//                 break;
//             //insert x before virusIndex
//             case 3:
//                 cin >> x  ;
//                 dna.insert(dna.begin()+virusIndex,x);
//                 virusIndex++ ;
//                 if (virusIndex == dna.size()) {
//                     virusIndex = 0;
//                 }
//                 break;
//             //insert x after virusIndex
//             case 4:
//                 cin >> x;
//                 dna.insert(dna.begin()+virusIndex+1,x);
//                 break;
//         }
//         // cout << t << " - virus - " << virusIndex << " : " ;
//         // cout << endl;
//     }
//     for (auto e : dna) {
//         cout << e << endl ;
//     }
// }

#include<iostream>
#include<vector>

using namespace std; 

int n, m, x, t;
vector<int> dna ;
int virusIndex = 0;

void readInput() {
    cin >> n >> m;
    dna.reserve(n);
    for (int i=0 ;i<n;i++) {
        cin >> x;
        dna.push_back(x) ;
    }
}

int main() {
    readInput();

    for (int i=0 ; i<m ;i++) {
        cin >> t;
        switch (t){
            case 1:
                virusIndex = 0;
                break;
            case 2:
                virusIndex = (virusIndex+1) % n;
                break;
            case 3:
                cin >> x;
                dna.insert(std::next(dna.begin(), virusIndex), x);
                virusIndex = (virusIndex+1) % (n+1);
                break;
            case 4:
                cin >> x;
                dna.insert(std::next(dna.begin(), virusIndex+1), x);
                break;
        }
    }
    for (auto e : dna) {
        cout << e << endl;
    }
}
