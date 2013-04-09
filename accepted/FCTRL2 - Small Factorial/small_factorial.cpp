#include <iostream>
#include <list>
#include <iomanip>
#include <map>
using namespace std;
typedef list<char> l;
class B{
public:
    B(){n_.push_front(0);}
    B(l n){n_=n;}
    B(int n){
        if(n>=10){
            int d=0;
            do{d=n%10;n_.push_front(d);n=n/10;}while(n);
        }else{n_.push_front(n);}}
    B& operator=(const B&);
    B operator*(int);
    friend ostream& operator<<(ostream&,B&);
    void P();
    l n_;
    int i_;
};
map<int,B> fh;
ostream& operator<<(ostream& s,B& n){n.P();return s;}
void B::P(){for(l::iterator it=n_.begin();it!=n_.end();it++){cout<<(int)(*it);}}
B& B::operator=(const B& b){ n_=b.n_;i_=b.i_;return *this;}
B B::operator*(int n){
    int r,cc=0,nc=0;
    l re;
    for(l::reverse_iterator it=n_.rbegin();it!=n_.rend();it++){
        r=((*it)*n)+cc;
        if(r>=10){
            nc=r/10;
            r%=10;
        }
        re.push_front(r);cc=nc;nc=0;
    }
    while(cc!=0){
        re.push_front(cc%10);
        cc/=10;
    }
    return B(re);
}
void F(int n){
    if(fh.find(n)!=fh.end()){fh[n].P();}
    else{
        B f(1);
        int i,j=1;
        if(n>2) for(j=n-1;j>=2;j--){if(fh.find(j)!=fh.end()){f=fh[j];break;}}
        for(i=j+1;i<=n;i++){
            f=f*i;
            if(fh.find(i)!=fh.end()){
                f.i_=i;fh[i]=f;
            }
        }
        cout<<f<<endl;}}
void S(int n){
    long double f=1;
    for(int i=2;i<=n;i++){
        f*=i;
        if(fh.find(i)!=fh.end()){
            B fb(f);
            fb.i_=i;
            fh[i]=fb;
        }
    }
    std::cout<<fixed<<setprecision(0)<<f<<std::endl;
}
int main(){
    int t,n,i;
    cin>>t;
    for(i=0;i<t;i++){cin>>n;n<=25?S(n):F(n);}
    return 0;}
