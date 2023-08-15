#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n=0;cin>>n;
    vector<int> v(n);
    for (int i=0; i<n; ++i) {
        cin>>v[i];
    }
    int p1=0, p2=0; cin>>p1>>p2;
    p1-=1;
    p2-=1;
    
    vector<int> prefix(n+1);
    for (int i=1; i<n+1; ++i) {
        prefix[i]=prefix[i-1]+v[i-1];
    }
    
    // 0 1 2 3   4   5  i
    // 1 2 3 4   5     v[i]
    // 0 1 3 6   10  15 prefix[i]
    //       12  9   5
    
    // 0 1 2 3   4
    // p1      p2
    // count=5
    // m = 2
  
    // 0 1 2 3
    // p1    p2
    // count = 4
    // m = 2

    int ans_1=0, ans_2=0;
    if (p1 == p2) {
	// 0 1 2
	// 1 2 0
	// 0 1 3 3
	//
	// 1 1
	// 
	if (prefix[p1+1] < prefix[n]-prefix[p1]) {
	    ans_1 = prefix[n]-prefix[p1];
	    ans_2 = prefix[p1];
	} else {
	    ans_1 = prefix[p1+1];
	    ans_2 = prefix[n]-prefix[p1+1];
	}
    } else {
	if (p1 < p2) {
		// 0 1 2 3
		// 1 2 3 4
		// 0 1 3 6 10
		// p1=0, p2=3
		// count = 4
		// m = 1
		int count = p2-p1+1;
		int m = p1 + (count/2 - (count%2?0:1)); // [p1, m], [m+1, p2]
		ans_1 = prefix[m+1];
		ans_2 = prefix[n]-prefix[m+1];
	} else {
		// p2    m    p1
		//
		// 0 1 2 3 4  5      i
		// 1 2 3 4 5  6      v[i]
		// 0 1 3 6 10 15 21  prefix[i]
		// count = 6
		// m = 3

		int count = p1-p2+1;
		int m = p1 - (count/2 - (count%2?0:1)); // [p2,m-1], [m, p1]
		ans_1 = prefix[n]-prefix[m];
		ans_2 = prefix[m];
	}	
    }
	
    cout << ans_1 << " " << ans_2 << '\n';

    return 0;
}
