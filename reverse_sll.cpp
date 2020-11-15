// template
#include <bits/stdc++.h>
 
# define C continue
# define R return
 
# define D double
# define I insert
# define ll long long
# define ld long double
 
# define ull unsigned long long
# define ui unsigned int
 
# define pb push_back
# define pf push_front
 
# define vi vector < int >
# define vc vector < char >
# define vs vector < string >
# define vb vector < bool >
# define vd vector < D >
# define vll vector < ll >
# define vull vector < ull >
# define vld vector < ld >
# define PQ priority_queue
 
# define vvi vector < vector < int > >
# define vvb vector < vector < bool > >
# define vvc vector < vector < char > >
# define vvll vector < vector < ll > >
# define vvd vector < vector < D > >
# define vvld vector < vector < ld > >
 
# define all(v) (v).begin() , (v).end()
# define allrev(v) (v).rbegin() , (v).rend()
# define allcomp(v) v.begin() , v.end() , comp
# define allrevcomp(v) v.rbegin() , v.rend() , comp
 
# define pii pair < int , int >
# define pll pair < ll , ll >
# define pld pair < ld , ld >
# define pDD pair < D , D >
# define pipii pair<int, pii >
# define pcpii pair<char,pii>
 
# define vpld vector < pld >
# define vpii vector < pii >
# define vpll vector < pll >
# define vpDD vector < pDD >
 
# define vvpii vector < vector < pii > >
# define vpipii vector< pipii >
 
# define F first
# define S second
# define mp make_pair
 
# define unm unordered_map
# define unmii unm< int , int >
# define unmll unm< ll , ll >
# define unms unm<string,int>
# define unmci unm<char,int>
 
# define sortvia sort(a.begin(),a.end());
# define sortvib sort(b.begin(),b.end());
# define revsorta sort(a.begin(), a.end(), greater <int>());
# define revsortb sort(b.begin(), b.end(), greater <>());
# define loop(q,n) for(int i=q;i<n;i++)
# define loop2(q,n) for(int j=q;j<n;j++)
# define test int t;cin >> t;while(t--)
# define nextline "\n"
# define tab "\t"
# define space " "
# define get_arr_size_n int n;cin>>n;int arr[n];loop(0,n)cin>>arr[i];
//vector<vector<int> > vec( n , vector<int> (m, 0));
//YES
//NO
//cout
//true
//false
//yes
//no
 
const ll mod9=1e9+7;
const ll maxsize=2e9+1;
// const ll mod =998244353;
const ll mod2=1073741824;
const ll INF=1e18L+5;
const int IINF=1e9+5;
const int two_pow_fiv=200008;
using namespace std;


class Node{
    public:
    int data ;
    Node* next;
}*first=NULL,*last=NULL;

void create(int arr[],int n){
    for(int i=0;i<n;i++){
        if(i==0){
            // this is the first element hence head has to be assigned here
            Node* temp=new Node();
            temp->data=arr[0];
            first=temp;
            last=first;
        }
        else {
            Node* tem=new Node();
            tem->data=arr[i];
            last->next=tem;
            last=tem;
        }
    }

}

void prin(Node* p){
    while(p->next!=NULL){
        cout<<p->data<<space;
        p=p->next;
    }
    cout<<p->data<<nextline;


}

void reverse_ll(Node *p){
  // here p is the head of the linked list
  // now we have to reverse the linked list
  // case 1 
  // the input list is empty
  if(p==NULL){
    cout<<"list is empty"<<nextline;
    return;
  }
  // case 2
  // the input list has only one node
  if(p->next==NULL){
    cout<<"reversed linked list has only one 1 element"<<nextline;
    // the list is already reversed
    // so we dont do anything
    return;
  }
  // case 3
  // list has more than 1 element
  Node* prev=p;
  Node* curr=p->next;

  Node* later=curr->next;
  // cout<<prev->data<<space<<curr->data<<space<<later->data<<nextline;
  prev->next=NULL;
  while(later!=NULL){
    // reverse the connection
    curr->next=prev;
    // move curr,prev,later forward
    prev=curr;
    curr=later;
    later=later->next;
  }
  curr->next=prev;
  first=curr;
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n;
    cin>>n;
    int arr[n];
    loop(0,n)cin>>arr[i];
    create(arr,n);
    cout<<"Initial linked list"<<nextline;
    prin(first);
    cout<<"Linked List after reversing"<<nextline;
    reverse_ll(first);
    prin(first);
return 0;
}