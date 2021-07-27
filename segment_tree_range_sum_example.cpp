#include <bits/stdc++.h>  
#define ll long long int
#define llu unsigned long long int
#define lld long double
#define endl '\n'
#define Endl '\n'


#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define pb push_back
#define SZ(x) ((int)x.size())
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define pii             pair<ll,ll>
#define mii             map<int,int>
#define pq             priority_queue<int>
#define inf             1e15
#define mod             1e9+7



#define all(a) a.begin(),a.end()  


using namespace std;




class segTree{      
                    /*  How to
                    //segTree st(0 , 5 , a); //initialise
                    //st.rangeSum(2 , 2) //range sum query
                    //st.pointUpdate(2 , 7); //point update
                    */

    public :
    int leftMost , rightMost;
    segTree *leftChild;
    segTree *rightChild;
    int sum;

    segTree(int lm , int rm , vector<ll> a){
        leftMost = lm;
        rightMost = rm;
        
        if(leftMost == rightMost){ //leaf condition
            sum = a[leftMost];
        }else{
            int mid = (leftMost + rightMost )/2;

            leftChild = new segTree(leftMost , mid , a);
            rightChild = new segTree(mid+1 , rightMost , a);
            recalc();
        }
    }

    void recalc(){
        if(leftMost == rightMost){
            return ;
        }
        sum = leftChild->sum + rightChild->sum;
    }


    void pointUpdate(int index , int newVal){
        if(leftMost == rightMost){ //leaf condition
            sum = newVal;
            return ;
        }
        // two childs
        if(index <= leftChild->rightMost )leftChild->pointUpdate(index , newVal);
        else rightChild->pointUpdate(index , newVal);
        recalc();
    }


    int rangeSum(int l , int r){
        // entirely disjoint
        if(l>rightMost || r<leftMost)return 0;

        //cover us
        if(l<=leftMost and r >=rightMost)return sum;

        //case 3 we don't know
        return leftChild->rangeSum(l,r) + rightChild->rangeSum(l,r);


    }

};







void solve(){
    int n;
    cin>>n;    
    
    vector<ll> a(n);

    loop(i,0,n)
    cin>>a[i];

    segTree st(0 , 5 , a);
    cout<<st.rangeSum(2 , 2)<<Endl;

    st.pointUpdate(2 , 7);
    cout<<st.rangeSum(2 , 2);

}




int32_t main()
{


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    loop(i,0,t)
    solve();
    

    return 0;
}
