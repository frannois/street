#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct node {
	vector<int> children;
	int nbZombies;
	};
          

void solve() {
	double *table,*tmp;
	node *nodes;
	int a,b,i,j,n = 0,m,k;
	cin >> n >> m >> k;
	table = new double[n*n];
	nodes = new node[n];
        vector<double> answers;
	
	vector<int>::iterator it;
	
	for(i=0 ; i < n*n ; i++) {
		table[i] = 0;
	}
	
	for ( i = 0 ; i < m ; i++) {
		cin >> a >> b;
		nodes[a].children.push_back(b);
		nodes[b].children.push_back(a);
	}
	
	for ( i = 0 ; i < n; i++) {
            cin >> j;
            nodes[i].nbZombies = j;
		it = nodes[i].children.begin();
		while ( it != nodes[i].children.end()) {
			table[i*n+*it] = double(1.0) / double(nodes[i].children.size());
			it++;
		}
	}
	
    
    for(j= 0 ; j < 3 ; j++ ) {
	tmp = new double [n*n];
        for(i=0 ; i < n*n ; i++) {
		tmp[i] = 0;
	}
	
	for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            for (int inner = 0; inner < n; inner++) {
                tmp[row*n+col] += table[row*n+inner] * table[inner*n+col];
            }
        }
        }
    
        for(i=0 ; i < n*n ; i++) {
		table[i] = tmp[i];
	}
	delete [] tmp;
    }

    
    for (int row = 0; row < n; row++) {
        tmp = new double;
        *tmp = 0;
        for (int col = 0; col < n; col++) {
             *tmp += table[col*n+row] * double(nodes[col].nbZombies);
        }
        answers.push_back(*tmp);
        delete tmp;
        }
		sort(answers.begin(),answers.end());
		reverse(answers.begin(),answers.end());
for (i = 0 ; i < 5 ; i++) {
    cout << int(answers[i]+0.5) << " ";
}
cout << endl;
delete [] table;
	delete [] nodes;

}
	
int main() {
    int i, n;
    cin >> n;
    for (i=0; i < n; i++) {
        solve();
    }
    return 0;
}
