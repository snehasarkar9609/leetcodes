#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution{
	public:
		void solve(int n,string& curr, vector<string>& result){
			if(curr.length()==n){
				result.push_back(curr);
				return;
			}
			for(char ch='a';ch<='c';ch++){
				if(curr.empty() && curr.back()==ch) continue;
				curr.push_back(ch);
				solve(n,curr, result);
				curr.pop_back();
			}
		}
		string getHappyString(int n, int k){
			string curr="";
			vector<string> result;
			solve(n,curr,result);
			if(result.size()<k) return "";
			return result[k-1];
		}
};
int main(){
	int n,k;
	cin>>n>>k;
	Solution obj;
	string ans=obj.getHappyString(n,k);
	if(ans=="") cout<<"No such happy string"<<endl;
	else cout<<"Happy String"<<endl;
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
struct ListNode{
			int val;
			ListNode *next;
			ListNode(int x){
				val=x;
				next=NULL;
			}
			
		};
class Solution{
	public:
		
		bool hasCycle(ListNode* head){
			ListNode* slow=head;
			ListNode* fast=head;
			while(fast!=NULL && fast->next!=NULL){
				slow=slow->next;
				fast=fast->next->next;
				if(slow==fast) return true;
			}
			return false;
		}
};

int main(){
	int n;
	cout<<"Enter the nodes: "<<endl;
	cin>>n;
	int x;
	cout<<"Enter the values: "<<endl;
	cin>>x;
	ListNode* head=new ListNode(x);
	ListNode* temp=head;
	for(int i=1;i<n;i++){
		cin>>x;
		temp->next=new ListNode(x);
		temp=temp->next;
	}
	int pos;
	cout<<"enter position: "<<endl;
	cin>>pos;
	if(pos!=-1){
		ListNode* cycleNode=head;
		for(int i=0;i<pos;i++){
			cycleNode=cycleNode->next;
		}
		temp->next=cycleNode;
	}
	Solution obj;
	if(obj.hasCycle(head)) cout<<"Cycle detected"<<endl;
	else cout<<"No cycle"<<endl;
	return 0;
	
}