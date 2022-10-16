#include <iostream>
using namespace std;
typedef long long ll;

void twoXtwo_naive_matrixmul(ll**a, ll** b, ll** c){
    c[0][0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    c[0][1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    c[1][0] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    c[1][1] = a[1][0]*b[0][1] + a[1][1]*b[1][1];
}

void twoXtwo_strassen(ll**a, ll**b, ll**c){
    ll t1 = (a[0][0] + a[1][1])*(b[0][0]+b[1][1]);
    ll t2 = (a[0][0] + a[1][1])*(b[0][0]);
    ll t3 = (a[0][0] )*(b[0][1]-b[1][1]);
    ll t4 = (a[1][1])*(b[0][1]-b[0][0]);
    ll t5 = (a[0][0] + a[0][1])*(b[1][1]);
    ll t6 = (a[1][0] - a[0][0])*(b[0][0]+b[0][1]);
    ll t7 = (a[0][1] - a[1][1])*(b[1][0]+b[1][1]);
    c[0][0] = t1+t4-t5+t7;
    c[0][1] = t3+t5;
    c[1][0] = t2+t4;
    c[1][1] = t1-t3-t2+t6;
}

int main(){
    ll **a = new ll*[2];
    for(int i =0; i<2; i++){
        a[i] = new ll[2];
    }
    ll **b = new ll*[2];
    for(int i =0; i<2; i++){
        b[i] = new ll[2];
    }
    a[0][0] = 4567;
    a[0][1] = 567;
    a[1][0] = 526;
    a[1][1] = 999;

    b[0][0] = 4567;
    b[0][1] = 65;
    b[1][0] = 17;
    b[1][1] = 345;

    ll **c = new ll*[2];
    for(int i =0; i<2; i++){
        c[i] = new ll[2];
    }
    twoXtwo_naive_matrixmul(a, b, c);
    for(int i =0; i<2; i++){
        for(int j =0; j<2; j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    twoXtwo_strassen(a, b, c);
    twoXtwo_naive_matrixmul(a, b, c);
    for(int i =0; i<2; i++){
        for(int j =0; j<2; j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}