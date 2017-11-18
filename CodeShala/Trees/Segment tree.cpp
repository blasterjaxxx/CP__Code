// implementation of segment tree
#include <bits/stdc++.h>
using namespace std;
int tree[10000];
int arr[10000];

// function to update the segment tree by updating the value at a specific index
void update_tree(int node, int index, int st, int en, int val){
    if(st==en && index==st){
        tree[node]=val;
        return;
    }
    int mid=(st+en)/2;
    if(index<=mid)
        update_tree(2*node, index, st, mid,val);
    else
        update_tree(2*node+1, index, mid+1, en,val);

    tree[node]=tree[2*node]+tree[2*node+1];
}

// function to calculate the sum from index st to index en
int query_tree(int node,int qst,int qen,int st,int en){
    if(qst<=st && qen>=en)
        return tree[node];

    if(qen<st || qst>en)
        return 0;

    int mid=(st+en)/2;
    int l_arr=query_tree(2*node,qst,qen,st,mid);
    int r_arr=query_tree(2*node+1,qst,qen,mid+1,en);
    return l_arr+r_arr;
}


// build segment tree
int build_tree(int node, int st, int en){
    //terminating condition
    if(st==en){
        tree[node]=arr[st];
        return tree[node];
    }
    int mid=(st+en)/2;
    int l_sum=build_tree(2*node,st,mid);
    int r_sum=build_tree(2*node+1,mid+1,en);
    tree[node] = l_sum + r_sum;
    return tree[node];
}

int main(){
    int n,i,value,index, q,l,r,qst,qen;
    cin>>n;
    for(i=1; i<=n; i++)
    cin>>arr[i];
    build_tree(1,1,n);

    for(i=1;i<2*n;i++)
        cout<<tree[i]<<" ";
    cin>>index>>value;
    update_tree(1,index,1,n,value);

    for(i=1;i<2*n;i++)
        cout<<tree[i]<<" ";

    cin>>q;
    while(q--){
        cin>>qst>>qen;
        cout<<query_tree(1,qst,qen,1,n);
    }

    return 0;
}
