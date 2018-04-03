//============================================================================
// Name        : Assignment1.cpp
// Author      : 2447
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <bits/stdc++.h>
using namespace std;

class node {

	char data;
	node *lchild, *rchild;
public:
	node() {
		data = 0;
		lchild = NULL;
		rchild = NULL;
	}
	friend class tree;
};

class tree {
	node *root;
public:
	tree() {
		root = NULL;
		}

	node* retroot() {
		return root;
	}
void setr(node* T){
root=T;}
	void create();
	void addroot();
	void postorder(node*);
	void preorder(node*);
	void inorder(node*);
	void npostorder();
	void npreorder();
	void ninorder();
	void traversal(node*);
	node* mirrorimage(node*);
	int height(node*);
	int leafnode(node*);
	int inode(node*);
	node* cpy(node*);
	void del(node*);
	void ndel();

};

void tree::ninorder() {
	 if(root==NULL){
        cout<<"TREE IS EMPTY";
        return;
    }

	stack<node*> s;
	node* T = root;
	while (true) {
		while (T != NULL) {
			s.push(T);
			T = T->lchild;
		}
		if (s.empty())
			break;

		T = s.top();
		s.pop();
		cout << "\t" << T->data;
		T = T->rchild;
	}
}

void tree::npreorder() {
	 if(root==NULL){
        cout<<"TREE IS EMPTY";
        return;
    }

	stack<node*> s;
	node* T = root;
	while (true) {
		while (T != NULL) {
			cout << "\t" << T->data;
			s.push(T);
			T = T->lchild;
		}
		if (s.empty())
			break;
		T = s.top();
		s.pop();
		T = T->rchild;
	}

}

void tree::npostorder() {
    if(root==NULL){
        cout<<"TREE IS EMPTY";
        return;
    }
	stack<node*> s;
	node* temp = new node;
	temp->data = '#';
	node* T = root;
	s.push(temp);
	while (true) {
		while (T != NULL) {
			s.push(T);
			if (T->rchild != NULL) {
				s.push(T->rchild);
				s.push(temp);
			}
			T = T->lchild;
		}
		if (s.empty())
			break;
		node*p = s.top();
		s.pop();
		while (p->data != temp->data && !s.empty()) {
			cout << "\t" << p->data;
			p = s.top();
			s.pop();
		}
		if (!s.empty()) {
			T = s.top();
			s.pop();
		}
	}

}

void tree::ndel() {
if(root==NULL){
cout<<"\nEmpty Tree";
return;
}
	stack<node*> s;
	node* temp = new node;
	temp->data = '#';
	node*T = root;
	while (true) {
		while (T != NULL) {
			s.push(T);
			if (T->rchild != NULL) {
				s.push(T->rchild);
				s.push(temp);
			}
			T = T->lchild;
		}
		if (s.empty())
			break;
		node*p = s.top();
		s.pop();
		while (p->data != temp->data && !s.empty()) {
			cout << "\nDeleting node with data=" << p->data;
			delete p;
			p = s.top();
			s.pop();

		}
		if (!s.empty()) {
			T = s.top();
			s.pop();
		}
	}
	cout << "\nDeleting node with data=" << root->data;
	delete root;
}

void tree::del(node* t) {
	if (t != NULL) {
		del(t->lchild);
		del(t->rchild);
		cout << "\nDeleting node with data=" << t->data;
		delete t;
	}
	else
	return;
}

int tree::inode(node* t) {
    int i;
	if (t == NULL)
		return 0;
	else if (t->lchild == NULL && t->rchild == NULL)
		return 0;
	else if (t->lchild != NULL || t->rchild != NULL)
		{i=1+inode(t->lchild)+inode(t->rchild);
		return i;
		}
		i=inode(t->lchild)+inode(t->rchild);
        return i;
}

int tree::leafnode(node* t) {
    int i;
	if (t == NULL)
		return 0;
	if (t->lchild == NULL && t->rchild == NULL)
            return 1;
	i=leafnode(t->lchild)+leafnode(t->rchild);
        return i;
}

int tree::height(node* t) {
	if (t == NULL)
		return 0;
	if (t->lchild == NULL && t->rchild == NULL)
		return 0;
	int h1 = height(t->lchild);
	int h2 = height(t->rchild);
	if (h1 > h2)
		return h1 + 1;
	else
		return h2 + 1;
}

node* tree::mirrorimage(node* t) {
	if (t == NULL)
		return NULL;
	else {
		node* mr = new node();
		mr->data = t->data;
		mr->lchild = mirrorimage(t->rchild);
		mr->rchild = mirrorimage(t->lchild);
		return mr;
	}
}

node* tree::cpy(node* t) {
	if (t == NULL)
		return NULL;
	else {
		node* mr = new node();
		mr->data = t->data;
		mr->lchild = cpy(t->lchild);
		mr->rchild = cpy(t->rchild);
		return mr;
	}
}

void tree::traversal(node* T) {
	cout << "\nTREE TRAVERSAL(RECURSIVE)";
	if(T==NULL){
        cout<<"\n TREE IS EMPTY";
        return ;
        }
        else{
	cout << "\nPRE-ORDER";
	preorder(T);
	cout << "\nIN-ORDER";
	inorder(T);
	cout << "\nPOST-ORDER";
	postorder(T);
        }
}

void tree::postorder(node* temp) {
	if (temp != NULL) {
		postorder(temp->lchild);
		postorder(temp->rchild);
		cout << "\t" << temp->data;
	}
	else
        return;
}
void tree::preorder(node* temp) {
	if (temp != NULL) {
		cout << "\t" << temp->data;
		preorder(temp->lchild);
		preorder(temp->rchild);
	}
	else
	return;
}
void tree::inorder(node* temp) {
	if (temp != NULL) {
		inorder(temp->lchild);
		cout << "\t" << temp->data;
		inorder(temp->rchild);
	}
	else
        return;
}

void tree::addroot() {
	cout << "\nEnter data for root node: ";
	node *nn = new node();
	cin >> nn->data;
	root = nn;
	root->lchild = root->rchild = NULL;
}
void tree::create() {
	char dec = 'y';
	string code;
	do {
		//node *nn = new node();

		cout << "\nEnter Code: ";
		cin >> code;
		unsigned int x = count(code.begin(), code.end(), '0');
		unsigned int x1 = count(code.begin(), code.end(), '1');
		if ((x + x1) != code.length()) {
			cout << "Invalid Code";
			continue;
		}
		//cout << "\nEnter character data: ";
		//cin >> nn->data;
		node* temp;
		temp = root;
		unsigned int i = 0;
		while (i < code.length() - 1 && temp != NULL) {
			if (code[i] == '0')
				temp = temp->lchild;
			else
				temp = temp->rchild;
			i++;
		}

		if (temp == NULL) {
			cout << "Invalid Code";
			continue;
		} else {
			if (i >= code.length() - 1) {
				if (code[i] == '0') {
					if (temp->lchild == NULL){
						cout << "\nEnter character data: ";
						node *nn = new node();
								cin >> nn->data;
						temp->lchild = nn;

					}
					else {
						char ch;
						cout
								<< "Already Exists\n Do you want to replace?(y\\n)";
						cin >> ch;
						if (ch == 'y' || ch == 'Y') {
							temp = temp->lchild;
							cout << "\nEnter character data: ";
							cin>>temp->data;

						}
					}

				} else if (code[i] == '1') {
					if (temp->rchild == NULL){
						node *nn = new node();
						cout << "\nEnter character data: ";
								cin >> nn->data;
						temp->rchild = nn;
					}
					else {
						char ch;
						cout
								<< "Already Exists\n Do you want to replace?(y\\n)";
						cin >> ch;
						if (ch == 'y' || ch == 'Y') {

							temp = temp->rchild;
							cout << "\nEnter character data: ";
							cin >> temp->data;

						}

					}
				}

			}
		}
		cout << "\nDo you want to add another?(y\\n)";
		cin >> dec;
	} while (dec == 'y' || dec == 'Y');
}

int main() {
	char dec;
	int ch;
	cout << "Is the tree empty?(y\\n)";
	cin >> dec;
	if (dec =='Y' || dec == 'y')
		return 0;

	tree t;
	t.addroot();
	cout << "\nDo you want to add child node?(y\\n)";
	cin >> dec;
	if (dec == 'y' || dec == 'Y')
		t.create();

            cout<<"\n\t\t***OPERATIONS ON TREE***";

		do{
		    int choice;
                cout<<"\n1. TRAVERSAL(RECURSIVE)\n2. TRAVERSAL(NON RECURSIVE)\n3. MIRROR IMAGE\n4. COPY TREE\n5. COUNTING\n6.DELETE TREE";
                cin>>choice;

            if(choice==1)
                t.traversal(t.retroot());
            if(choice==2){
                cout << "\nTREE TRAVERSAL(NONRECURSIVE)";
                cout << "\nPRE-ORDER";
                t.npreorder();
                cout << "\nIN-ORDER";
                t.ninorder();
                cout << "\nPOST-ORDER";
                t.npostorder();
                }
            if(choice==3){
                cout << "\n\nMIRROR IMAGE\n";
                node* root = t.mirrorimage(t.retroot());
                t.traversal(root);
                }
            if(choice==4){
                node* root1 = t.cpy(t.retroot());
                cout << "\n\nCOPIED TREE\n";
                t.traversal(root1);

            }
            if(choice==5){
                cout << "\nHeight of tree is:" << t.height(t.retroot());
                cout << "\nNumber of leaf nodes is:" << t.leafnode(t.retroot());
                cout << "\nNumber of internal nodes is:" << t.inode(t.retroot());
            }
            if(choice==6){
                cout << "\nEnter Choice\n(1) Recursive Deletion (2) Non-Recursive Deletion";
                cin >> ch;
                if (ch == 2) {
                    cout << "\n\n";
                    t.ndel();
                    t.setr(NULL);

                } else if (ch == 1) {
                    cout << "\n\n";
                    t.del(t.retroot());
                    t.setr(NULL);
                }

        }
            cout<<"\nDO YOU WANT TO CONTINUE?(y\\n)";
            cin>>dec;
		}while(dec=='y'||dec=='Y');

	return 0;
}
