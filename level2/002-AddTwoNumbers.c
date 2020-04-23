/*
* @Author: Cheng.Wang
* @Date:   2020-04-27 14:05:57
* @Last Modified by:   Cheng.Wang
* @Last Modified time: 2020-04-27 17:31:30
* @Email:   cheng.wang@amlogic.com
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
	int val;
	struct ListNode *next;
};


// struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

// 	int t, c;
// 	struct ListNode *p =  (struct ListNode *)malloc(sizeof(struct ListNode));
// 	struct ListNode *re = (struct ListNode *)malloc(sizeof(struct ListNode));
// 	re = p;
// 	c = t = 0;
// 	while (1) {
// 		c = l1->val + l2->val + t;
// 		if (c > 9) {
// 			t = c / 10;
// 			p->val = c % 10;
// 		} else {
// 			p->val = c;
// 			t = 0;
// 		}

// 		if (l1->next == NULL && l2->next == NULL) {
// 			if (t == 0)
// 				p->next = NULL;
// 			else {
// 				p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
// 				p = p->next;
// 				p->val = t;
// 				p->next = NULL;
// 			}
// 			break;
// 		}

// 		if (l1->next != NULL) // l1 next
// 			l1 = l1->next;
// 		else
// 			l1->val = 0;
// 		if (l2->next != NULL) // l2 next
// 			l2 = l2->next;
// 		else
// 			l2->val = 0;

// 		p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
// 		p = p->next;
// 	}

// 	return re;

// }
//

int c = 0;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    if(l1==NULL && l2==NULL && c==0) return NULL;
    l1 = l1!=NULL ? (c += l1->val, l1->next) : l1;
    l2 = l2!=NULL ? (c += l2->val, l2->next) : l2;
    struct ListNode *re = (struct ListNode *)malloc(sizeof(struct ListNode));
    re->val = c % 10;
    c /= 10;
    re->next = addTwoNumbers(l1, l2);
    return re;
}

int main(int argc, char const *argv[])
{
	/* code */
	struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *p  = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *re = (struct ListNode *)malloc(sizeof(struct ListNode));
	// p = l1;
	// for (int i = 0; i < 1; ++i) {
	// 	/* code */
	// 	l1->val = 5;
	// 	if (i == 1) {
	// 		l1->next = NULL;
	// 		l1 = p;
	// 		break;
	// 	}
	// 	l1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	// 	l1 = l1->next;
	// }
	// p = l2;
	// for (int i = 0; i < 1; ++i) {
	// 	/* code */
	// 	l2->val = 5;
	// 	if (i == 1) {
	// 		l2->next = NULL;
	// 		l2 = p;
	// 		break;
	// 	}
	// 	l2->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	// 	l2 = l2->next;
	// }
	l1->val = 5;
	l2->val = 5;
	l1->next = NULL;
	l2->next = NULL;
	for (p = l1; p != NULL; p = p->next)
		printf("%d ", p->val);
	printf("\n");
	for (p = l2; p != NULL; p = p->next)
		printf("%d ", p->val);
	printf("\n");

	re = addTwoNumbers(l1, l2);

	for (p = re; p != NULL; p = p->next)
		printf("%d ", p->val);
	printf("\n");

	return 0;
}