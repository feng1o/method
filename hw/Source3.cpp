#if 0
#include<stdio.h>
#include<stdlib.h>
#define maxsize 100
typedef struct node
{
	char *data;
	struct node *first_child, *next_sibling;//fc�ǵ�һ������,nb��fc���ٽڵ�
} tree;

/**
a
/ \ \
b c d
/\ \
e f g
�������������ṹ����
*/

tree *insertTree(char *ch, tree *parent, tree *pre_sibling) {
	tree *child = (tree *)malloc(sizeof(tree));
	child->data = ch;

	if (parent != NULL) parent->first_child = child;
	if (pre_sibling != NULL) pre_sibling->next_sibling = child;

	child->first_child = NULL;
	child->next_sibling = NULL;

	return child;
}

/**������������*/
tree *create() {
	//����root�ڵ�
	tree *root = (tree *)malloc(sizeof(tree));
	root->data = "A";
	root->first_child = NULL;
	root->next_sibling = NULL;

	/**
	* ��������ӽڵ�
	**/
	tree *b = insertTree("B", root, NULL);

	tree *c = insertTree("C", NULL, b);
	tree *g = insertTree("G", c, NULL);
	//tree *h = insertTree("H", g, NULL);
	tree *d = insertTree("D", NULL, c);
	tree *e = insertTree("E", b, NULL);
	tree *f = insertTree("F", NULL, e);

	return root;
}

void preOrder(tree *root) {
	printf("%c ", *root->data);
	if (root->first_child != NULL) {
		preOrder(root->first_child);
	}
	if (root->next_sibling != NULL) {
		preOrder(root->next_sibling);
	}
}



int main()
{
	
	tree *root = create();
	printf("�������:");
	preOrder(root);
	
}
#endif