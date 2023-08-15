#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N=0; cin>>N;

	// sort by x coord ?
	
	vector<pair<int, int>> v(N);
	for (int i=0; i<N; ++i) {
		int x=0, y=0;
		cin >> x >> y;
		v[i] = {x, y};
	}

	for (int i=0; i<N; ++i) { // A
		int x_a = v[i].first;
		int y_a = v[i].second;

		for (int j=i+1; j<N; ++j) { // B
			int count_down=0, count_up=0;

			int x_b = v[j].first;
			int y_b = v[j].second;
			double k = (x_a-x_b)==0?0:((y_a-y_b)/(x_a-x_b));
			double b = (x_a-x_b)==0?0:((y_a*x_a-y_a*x_b+x_a*y_b-x_a*y_a)/(x_a-x_b));
			// y = k*x+b
			for (int l=0; l<N; ++l) { // C
				if (l==i || l==j) continue;
				int x_c = v[l].first;
	                        int y_c = v[l].second;
				
				double r = -y_c + k*x_c + b;

				if (r > 0) {
					++count_down;	
				} else if (r < 0){
					++count_up;
				}
			}

			if (count_down == count_up) {
                        	cout << i+1 << " " << j+1 << "\n";
                        	return 0;
                	}
		}
	}

	return 0;
}
