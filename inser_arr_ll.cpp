// creating and printing a circular linked list
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
using namespace std;

class Node{
    public:
    int data ;
    Node* next;
}*first=NULL,*last=NULL;

void create(int a[],int n)
{
    first=new Node();
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        Node*t=new Node();
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    last->next=first; //for loop or circular linked list 
}

void insert_arr(int a[],int n){
  for(int i=0;i<n;i++){
    if(i==0){
      // in this case first is pointing to null and list is empty
      // we create a node and make first point to it
      first=new Node();
      first->data=a[0];
      // make first point to itself
      first->next=first;
      // as first is the only node in linked list
      last=first;
    }
    else{
      // we need to create a new node
      Node* t=new Node();
      t->data=a[i];
      // make last point to t
      last->next=t;
      // make t point to first
      t->next=first;
      // assign t as last
      last=t;
    }
  }
}


void print_in_style(Node *p){
  if(p==NULL){
    cout<<"no element in list"<<nextline;
  }
  else if (p->next==p){
    // cout<<"only one element in list which is : ";
    cout<<p->data;
  }
  else{
    // cout<<"more than one element is present in list"<<nextline;
    // print the first node explicitly
    cout<<p->data<<space;
    p=p->next;
    // use while loop to print all the nodes untill we reach the first node
    while(p!=first){
      cout<<p->data<<space;
      p=p->next;
    }
  }
  cout<<nextline;
}

void reverse_ll(Node *p){
  // here p is the head of the linked list
  // now we have to reverse the linked list
  cout<<"inside reverse"<<nextline;
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
  // // case 3
  // // list has more than 1 element
  // Node* prev=p;
  // Node* curr=p->next;

  // later=curr->next;
  // while(later!=NULL){
  //   // reverse the connection
  //   curr->next=prev;
  //   // move curr,prev,later forward
  //   prev=curr;
  //   curr=later;
  //   later=later->next;
  // }
  // curr->next=prev;
  // first=curr;
}


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    cout<<"working"<<nextline;
    int A[] ={1,2,3,4};
    insert_arr(A,4);
    print_in_style(first);
    reverse_ll(first);
    print_in_style(first);
    return 0;
}