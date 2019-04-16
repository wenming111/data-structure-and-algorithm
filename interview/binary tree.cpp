#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int a) :val(a), left(nullptr), right(nullptr) {}
};

//œ»–Úµ›πÈ
void preOrder1(TreeNode* root) {
	if (root == nullptr) return;
	cout << root->val << " ";
	preOrder1(root->left);
	preOrder1(root->right);
}
//œ»–Ú∑«µ›πÈ
void preOrder2(TreeNode* root) {
	if (root == nullptr) return;
	TreeNode* p = root;
	stack<TreeNode*> myStack;
	while (p || !myStack.empty()) {
		while (p) {
			myStack.push(p);
			cout << p->val << " ";
			p = p->left;
		}
		if (!myStack.empty()) {
			p = myStack.top();
			myStack.pop();
			p = p->right;
		}
	}
}
//÷––Úµ›πÈ
void inOrder1(TreeNode* root) {
	if (root == nullptr) return;
	inOrder1(root->left);
	cout << root->val << " ";
	inOrder1(root->right);
}
//÷––Ú∑«µ›πÈ
void inOrder2(TreeNode* root) {
	TreeNode* p = root;
	stack<TreeNode*> myStack;
	while (p || !myStack.empty()) {
		while (p) {
			myStack.push(p);
			p = p->left;
		}
		if (!myStack.empty()) {
			p = myStack.top();
			myStack.pop();
			cout << p->val << " ";
			p = p->right;
		}
	}
}

//∫Û–Úµ›πÈ
void postOrder1(TreeNode* root) {
	if (root == nullptr) return;
	postOrder1(root->left);
	postOrder1(root->right);
	cout << root->val << " ";
}
//∫Û–Ú∑«µ›πÈ
void postOrder2(TreeNode* root) {
	TreeNode* p = root;
	TreeNode* pLast = nullptr;
	stack<TreeNode*> myStack;
	while (p) {
		myStack.push(p);
		p = p->left;
	}
	while (!myStack.empty()) {
		p = myStack.top();
		if (p->right == nullptr || p->right == pLast) {
			cout << p->val << " ";
			myStack.pop();
			pLast = p;
		}
		else {
			p = p->right;
			while (p) {
				myStack.push(p);
				p = p->left;
			}
		}
	}
}

//≤„–Ú±È¿˙
void bfs(TreeNode* root) {
	queue<TreeNode*> myQueue;
	TreeNode* p = root;
	myQueue.push(p);
	while (!myQueue.empty()) {
		p = myQueue.front();
		myQueue.pop();
		cout << p->val << " ";
		if (p->left)
			myQueue.push(p->left);
		if (p->right)
			myQueue.push(p->right);
	}
}


//—È÷§
int main() {
	TreeNode* t0 = new TreeNode(0);
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t5 = new TreeNode(5);
	TreeNode* t6 = new TreeNode(6);
	t0->left = t1;
	t0->right = t2;
	t1->left = t3;
	t1->right = t4;
	t2->left = t5;
	t2->right = t6;
	bfs(t0);
	while (1);
	return 0;
}