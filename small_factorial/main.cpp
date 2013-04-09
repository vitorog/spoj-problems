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
    B operator+(B&);
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
B B::operator+(B& b){
    l *a_op, *b_op;
    if(n_.size()>=b.n_.size()){a_op=&n_;b_op=&b.n_;
    }else{a_op=&b.n_;b_op=&n_;}
    l::reverse_iterator a_it=a_op->rbegin(),b_it;
    l rn;
    int cc=0,nc=0,r;
    for(b_it=b_op->rbegin();b_it!=b_op->rend();b_it++){
        r=(*a_it)+(*b_it)+cc;
        if(r>=10){
            nc=r/10;
            r=r%10; }
        rn.push_front(r);
        cc=nc;
        nc=0;
        a_it++;}
    if(a_it !=a_op->rend()){
        for(;a_it !=a_op->rend(); a_it++){
            if(cc!=0){
                r=(*a_it)+cc;
                if(r>=10){
                    nc=r/10;
                    r=r%10;}
                rn.push_front(r);
                cc=nc;
                nc=0;
            }else{rn.push_front((*a_it));}
        }
        if(cc!=0){rn.push_front(cc);}
    }else if(cc!=0){rn.push_front(cc);}
    return B(rn);
}
B& B::operator=(const B& b){ n_=b.n_;i_=b.i_;return *this;}
B B::operator*(int n){
    B r(0),o(n_);
    int c=0;
    while(c<n){r=r+o;c++;}
    return r;
}
void F(int n){
    if(fh.find(n)!=fh.end()){fh[n].P();}
    else{
        B f(1);
        int i,j=1;
        if(n>2) for(j=n-1;j>=2;j--){if(fh.find(j)!=fh.end()){f=fh[j];break;}}
        for(i=j+1;i<=n;i++){f=f*i;}
        f.i_=n;fh[n]=f;
        cout<<f<<endl;}}
void S(int n){
    long double f=1;
    for(int i=2;i<=n;i++){f*=i;}
    std::cout<<fixed<<setprecision(0)<<f<<std::endl;
    B fb=B(f);fb.i_=n;fh[n]=fb;}
int main(){
    int t,n,i;
    cin>>t;
    for(i=0;i<t;i++){cin>>n;n<=25?S(n):F(n);}
    return 0;}
