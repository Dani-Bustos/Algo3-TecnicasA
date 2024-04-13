#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i<b;i++)
typedef long long ll;
using namespace std;
const long long INDEF = -1;

#include <bits/stdc++.h>
using namespace std;
// una solución recursiva válida es: max(f(izq), f(der), altura(der) + altura(izq) +1)
// checkear en cada caso la posibilidad de ir a la izq o der.
// caso base ni izq ni der => 1
//La complejidad depende de si usamos o no memoización para las alturas , con DP Sale en O(n)
class Node {
public:
	int data;
	Node* left;
	Node* right;
	// Val is the key or the value that
	// has to be added to the data part
	Node(int val)
	{
		data = val;
		// Left and right child for node
		// will be initialized to null
		left = NULL;
		right = NULL;
	}
};
int solve(Node *actual);
int main()
{
	/*create root*/
	Node* root = new Node(1);

	/* following is the tree after above statement
	1
	/ \
	NULL NULL
	*/
	root->left = new Node(2);
	root->right = new Node(3);

	/* 2 and 3 become left and right children of 1
	1
	/ \
	2 3
	/ \ / \
	NULL NULL NULL NULL
	*/
	root->left->left = new Node(4);
	/* 4 becomes left child of 2
		 1
	   /   \
	  2	     3
	/  \    /    \
	4   NULL  NULL  NULL
	/  \
	NULL NULL
	*/
	cout << solve(root);
}




int solve(Node *actual){
    
    if(actual->left == NULL && actual->right == NULL){
        return 0;
    }else if(actual->left == NULL){
        return solve(actual->right) + 1;
    }else if(actual->right == NULL){
        return solve(actual->left) + 1;
    }else {
        return max(solve(actual->left) + 1,solve(actual->right) + 1);
    }
}

