//#include <iostream>
//#include <string>
//#include <crtdbg.h>
//#include <stdarg.h>
//using namespace std;
//
//
//typedef struct Node {
//	int x;
//	struct Node* next;
//} Node;
//
//
//
//void AppendNode(Node** root, int value) {
//	Node* new_node = (Node*)malloc(sizeof(Node));
//
//	if (new_node == NULL) {
//		exit(1);
//	};
//
//	new_node->x = value;
//	new_node->next = NULL;
//
//	Node* curr = *root;
//	if (curr == NULL) {
//		*root = new_node;
//		return;
//	}
//
//	while (curr->next != NULL) {
//		curr = curr->next;
//	}
//	curr->next = new_node;
//}
//
//
//void Show(Node** root) {
//	Node* cur = *root;
//
//	printf("[ ");
//	while (cur != NULL) {
//		printf(" %d ", cur->x);
//		cur = cur->next;
//	}
//	printf(" ]");
//}
//
//
//void FreeMemory(Node** root) {
//	Node* curr = *root;
//
//	if (curr == NULL) {
//		return;
//	}
//
//	else if (curr->next == NULL) {
//		free(curr);
//		return;
//	}
//
//
//	while (curr->next != NULL) {
//		Node* aux = curr;
//		curr = curr->next;
//		free(aux);
//	};
//	free(curr);
//};
//
//
//void InsertBeginning(Node** root, int value) {
//	Node* new_node = (Node*)malloc(sizeof(Node));
//	if (new_node == NULL) {
//		exit(2);
//	}
//	new_node->x = value;
//	new_node->next = (*root);
//	(*root) = new_node;
//}
//
//void insertAfter(Node** root, int value) {
//	Node* new_node = (Node*)malloc(sizeof(Node));
//	if (new_node == NULL) {
//		exit(3);
//	}
//	new_node->x = value;
//	new_node->next = (*root)->next;
//	(*root)->next = new_node;
//
//}
//
//void Reverse(Node** root) {
//	Node* curr = (*root);
//
//	if (curr == NULL || curr->next == NULL) {
//		return;
//	};
//
//	
//	Node* left = (*root);
//	Node* right = (left->next);
//	bool loop  = true;
//	while (loop){
//		Node* z = right->next;
//		if (z == NULL) {
//			right->next = left;
//			(*root)->next = NULL;
//			*root = right;
//			return;
//		}
//		right->next = left;
//		left = right;
//		right = z;
//		
//	}	
//}
//
//
//void RemoveElement(Node** root, int value) {
//	Node* cur = (*root);
//	Node* prev = NULL;
//
//
//	while (cur != NULL) {
//		if (cur->x == value) {
//			if (prev == NULL) {
//				(*root) = cur->next;
//			}
//			else {
//				prev->next = cur->next;
//			}
//			free(cur);
//			return;
//		}
//		prev = cur;
//		cur = cur->next;
//	}
//}
//
//void SortedAppend(Node** root, int value) {
//	if ((*root) == NULL || (*root)->x >= value) {
//		InsertBeginning(root, value);
//		return;
//	}
//
//	Node* curr = (*root);
//
//	while (curr->next != NULL) {
//		if (curr->next->x >= value) {
//			insertAfter(&curr, value);
//			return;
//		}
//		curr = curr->next;
//	}
//	insertAfter(&curr, value);
//}
//
//
//
//int main(int argc, char* argv[]) {
//	Node* root = NULL;
//	AppendNode(&root, 0);
//	AppendNode(&root, 1);
//	AppendNode(&root, 2);
//	AppendNode(&root, 3);
//	Reverse(&root);
//	AppendNode(&root, 4);
//	SortedAppend(&root, 4);
//	Show(&root);
//	FreeMemory(&root);
//	_CrtDumpMemoryLeaks();
//	return 0;
//} 