class Solution{
	public:
		bool isVowel(char &ch){
			return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
		}
		int maxVowel(string s,int k){
			int n=s.length();
			int i=0,j=0;
			int maxV=0;
			int count=0;
			while(j<n){
				if(isVowel[s[j]]) count++;
				if(j-i+1==k){
					maxV=max(maxV,count);
					if(isVowel(s[i])) count--;
					i++;
				}
				j++;
			}
			return maxV;
		}
};

class Solution{
	public:
		TreeNode* searchBST(TreeNode* root, int val){
			while(root!=NULL && root->val!=val){
				if(val<root->val){
					root=root->left;
				}
				else root=root->right;
			}
			return root;
		}
};

class Solution{
	public:
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p,TreeNode* q){
			if(root==NULL) return NULL;
			if(root->val==p->val||root->val==q->val) return root;
			TreeNode* leftLCA=lowestCommonAncestor(root->left,p,q);
			TreeNode* rightLCA=lowestCommonAncestor(root->right,p,q);
			if(leftLCA && rightLCA){
				return root;
			}
			else if(leftLCA!=NULL) return leftLCA;
			else return rightLCA;
		}
};


class Solution{
	public:
		TreeNode* deleteNode(TreeNode* root, int key){
			if(root==NULL) return NULL;
			if(root->val==key) return helper(root);
			TreeNode* dummy=root;
			while(root!=NULL){
				if(root->val>key){
					if(root->left!=NULL && root->left->val==key){
						root->left=helper(root->left);
						break;
					}
					else{
						root=root->left;
					}
				}
				else{
					if(root->right!=NULL && root->right->val==key){
						root->right=helper(root->right);
						break;
						
					}
					else{
						root=root->right;
					}
				}
			}
			return dummy;
		}
		TreeNode* helper(TreeNode* root){
			if(root->left==NULL) return root->right;
			else if(root->right==NULL) return root->left;
			TreeNode* rightChild=root->right;
			TreeNode* lastRight=findLastRight(root->left);
			lostRight->right=rightChild;
			return root->left;
		}
		TreeNode* findLastRight(TreeNode* root){
			if(root->right==NULL) return root;
			return findLastRight(root->right);
		}
};

class Solution{
	public:
		bool isHelper(TreeNode* root, TreeNode* min, TreeNode* max){
			if(root==NULL){
				return true;
			}
			if(min!=NULL && root->val<=min->val){
				return false;
			}
			if(max!=NULL && root->val>=max->val) return false;
			return helper(root->left, min, root)
				&& helper(rppt->right, root, max);
		}
		bool isValidBST(TreeNode* root){
			return helper(root,NULL, NULL);
			
		}
};

class Solution{
	public:
		int preOrder=0;
		int kthSmallest(TreeNode* root, int k){
			if(root==NULL){
				return -1;
			}
			if(root->left!=NULL){
				int leftAns=kthSmallest(root->left,k);
				if(leftAns!=-1) return leftAns;
			}
			if(preOrder+1==k){
				return root->val;
			}
			preOrder=preOrder+1;
			if(root->right!=NULL){
				int rigthAns=kthSmallest(root->right,k);
				if(rightAns!=-1) return rightAns;
			}
			if(preOrder+1==k){
				return root->val;
			}
			return -1;
		}
};