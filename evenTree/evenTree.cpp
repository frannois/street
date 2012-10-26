/* Enter your code here. Read input from STDIN. Print output to STDOUT */

#include <iostream>
#include <vector>

using namespace std;

int l;
int cuts;

struct node {
    int mother;
    vector<int> children;
    bool visited;
};
    
    int nbChildren(node nodes[], int pos) {
        int i;
        int answer = nodes[pos].children.size();
        int tmp;
        for (i= 0 ; i < l ; i++) { 
            if(nodes[i].mother == pos) {
               tmp =  nbChildren(nodes, i);
                
               if(tmp%2 != 0 && tmp != 0) {cuts ++;
                                           //cout << "cuts ++ node " << i<< endl;
                                          }
               answer += tmp;
            }
        }
    
      //  cout << "node " << pos << "has " << answer << "children" << endl;
        return answer;
    }

int main() {
    int i, n,m,c,ans = 0;
    cuts = 0;
    cin >> n >> l;
    node nodes[l];
    int head;
    for (i=0; i<l; i++) {
        nodes[i].mother = -1;
        nodes[i].visited = false;
    }
    for (i=0; i<l; i++) {
        cin >> c >> m;
        nodes[m-1].children.push_back(c-1);
        nodes[c-1].mother = m-1;
    }
    for (i=0; i<l; i++) {
         if( nodes[i].mother == -1) {
             head = i;
         }
     }

    nbChildren(nodes,head);
        cout << cuts << endl;
    return 0;
}
