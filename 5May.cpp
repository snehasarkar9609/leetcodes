class Solution{
	public:
		long long sunXor(vector<int>& arr){
			int n=arr.size();
			long long result=0;
			for(int bit=0;bit<32;bit++){
				long long count1=0;
				for(int x:arr){
					if(x&(1<<bit)){
						count1++;
					}
				}
				long long count0=n-count1;
				result+=count0*count1*(1LL<<bit);
			}
			return result;
		}
};



class Solution{
	public:
		ListNode* findNthNode(Node* temp, int k){
			int count=1;
			while(temp!=NULL){
				if(count==k) return temp;
				count++;
				temp=temp->next;
			}
			return temp;
		}
		ListNode* rotateRight(Node* head,int k){
			if(head==NULL || k==0) return head;
			Node* tail=head;
			int len=1;
			while(tail->next!=NULL){
				tail=tail->next;
				len+=1;
			}
			if(k%len==0) return head;
			k=k%len;
			tail->next=head;
			ListNode* newLastNode=findNthNode(head,len-k);
			head=newLastNode->next;
			newLastNode->next=NULL;
			return head;
		}
};



int sortArr(vector<int>& arr){
	int n=arr.size();
	int max=arr[0];
	for(int i=0;i<n;i++){
		if(max<arr[i]) max=arr[i];
	}
	return max;
}


int secondLargest(vector<int>& arr){
//	int n=arr.size();
//	if(n==0 || n==1) return -1;
//	int secL=arr[n-1];
//	sort(arr.begin(),arr.end());
//	for(int i=n-2;i>=0;i--){
//		if(arr[i]!=secL) return arr[i];
//	}
//	return -1;

	int n=arr.size();
	int max=arr[0];
	for(int i=0;i<n;i++){
		if(max<arr[i]) max=arr[i];
	}
	int secondL=INT_MIN;
	for(int i=0;i<n;i++){
		if(arr[i]>secondL && arr[i]!=largest) secondL=arr[i];
	}
	return secondL;
}


int secondLargest(vector<int>& a, int n){
	int largest=a[0];
	int slargest=INT_MIN;
	for(int i=1;i<n;i++){
		if(a[i]>largest){
			slargest=largest;
			largest=a[i];
		}
		else if(a[i]<largest && a[i]>slargest){
			slargest=a[i];
		}
	}
	return slargest;
	
}
int secondSmallest(vector<int>& a,int n){
	int smallest=a[0];
	int ssmallest=INT_MAX;
	for(int i=0;i<n;i++){
		if(a[i]<smallest){
			ssmallest=smallest;
			smallest=a[i];
		}
		else if(a[i]!=smallest && a[i]<ssmalest) ssmallest=a[i];
	}
	return ssmallest;
}
vector<int> getSecondOrderElement(int n,vector<int> a){
	int slargest=secondLargest(a,n);
	int ssmallest=secondSmallest(a,n);
	return {slargest,ssmallest};
}


int isSorted(int n,vector<int> a){
	for(int i=0;i<n-1;i++){
		if(a[i]>a[i+1]) 
			return false;
	}
	return true;
}


int removeDuplicates(vector<int>& nums){
//	unordered_set<int>seen;
//	int index=0;
//	for(int num:arr){
//		if(seen.find(num)==seen.end()){
//			seen.insert(num);
//			nums[index]=num;
//			index++;
//		}
//	}
//	return index;
	if(arr.empty()) return 0;
	int i=0;
	int n=nums.size();
	for(int j=1;j<n;j++){
		if(nums[j]!=nums[i]){
			
			nums[i+1]=nums[j];
			i++;
		} 
	}
	return i+1;
}