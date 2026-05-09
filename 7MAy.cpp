class Solution{
	public:
		bool isIdentical(Node* root1, Node* root2){
			if(root1==NULL && root2==NULL ) return true;
			if(root1==NULL || root2==NULL) return false;
			return (root1->data==root2->data) && isIdentical(root1->left,root2->left) && isIdentical(root1->right, root2->right);
		}
		bool isSubTree(Node* T, Node* S){
			if(s==NULL )return true;
			if(T==NULL) return false;
			if(isIdentical(T,S)) return true;
			return isSubTree(T->left,S)|| isSubTree(t->right,S);
		}
};