/* Enter your code here. Read input from STDIN. Print output to STDOUT */

#include <iostream>
#include <vector>
using namespace std;
int n;

bool validPos(vector<int> pos,int t) {

    int i,j,tX,tY,posX,posY;
    tX = t % n;
    tY = t / n;
    float a,b;
    for ( i = 0 ; i < pos.size() ; i++ ) {
        posX = pos[i] % n ;
        posY = pos[i] / n;
        
        if(tX - posX == 0 || tY - posY == 0 || abs(tX - posX) == abs(tY - posY) ) return false;
        //cout << "tX " << tX << " tY " << tY << " posX " << posX << " posY " << posY << endl;
        for (j = i+1 ; j < pos.size() ; j++) {
           if(tX - (pos[j]%n) == 0 || tY - (pos[j] / n) == 0 || tX - (pos[j]%n) == tY - (pos[j] / n) ) return false;
            a = (float)(tY - posY)/(float)(tX -posX);
            //cout << "a " << a;
            
            b = tY  - a*tX;
            //cout << "\tb " << b;
           // cout <<"\t answer  " << pos[j] / n << " = " << a*(pos[j]%n) + b << endl;
           // cout << "i " << pos[i] <<  " t " << t << " j " << pos[j]  <<endl;
            if( pos[j] / n  == a*(pos[j]%n) + b)
            {
                 //cout << "return false;" << endl;
                return false;
            }
        }

    }
            return true;
  
}


int solve(vector<int> pos, int i) {
    int tmp;
    //cout << "i " << i << endl ;
    if(pos.size() == n) {
        cout << n << endl;
        for ( i = 0 ; i < pos.size() ; i++) 
        {
            cout << ((pos[i]%n)+1)<< " ";
        }
        cout << endl;
        return 1;
    }
    for(; i < n*n ; i++) {
        if(validPos(pos,i)) {
            pos.push_back(i);
            tmp = solve(pos,i+n-(i%n));
            if(tmp == 1) return 1;
            pos.pop_back();
        }
    }
    
    return 0 ;
}

int main() {
    vector<int> pos;
    int i;
    //for (i=1; i<1000; i+=2) {
        n = 11;
        solve(pos,0);
    //}
    return 0;
}
