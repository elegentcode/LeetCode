/*
* @Author: Cheng.Wang
* @Date:   2020-04-23 10:43:44
* @Last Modified by:   Cheng.Wang
* @Last Modified time: 2020-04-27 14:11:45
* @Email:   cheng.wang@amlogic.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int* twoSum(int* nums, int numsSize, int target, int* returnSize){
// 	/*暴力算法*/
// 	/*执行用时 :184 ms, 在所有 C 提交中击败了60.39%的用户*/
// 	/*内存消耗 :6.1 MB, 在所有 C 提交中击败了100.00%的用户*/
// 	int *re = (int *)malloc(sizeof(int) * 2);
// 	for (int i = 0; i < numsSize - 1; ++i)
// 		for (int j = i + 1; j < numsSize; ++j)
// 			if (nums[i] + nums[j] == target) {
// 				re[0] = i + 1;
// 				re[1] = j + 1;
// 				*returnSize = 2;
// 				return re;
// 			}
// 	return re;
// }

struct hash_data{
    int key;
    int data;
    struct hash_data *next;
};

struct hash_table
{
    struct hash_data **head; //数组
    int hash_width;
};

///初始化
int hash_init(struct hash_table * table, int width){
    if(width <= 0)
        return -1;
    struct hash_data ** tmp = (struct hash_data **)malloc(sizeof(struct hash_data) * width);
    table->head = tmp;
    memset(table->head, 0, width * sizeof(struct hash_data *));
    if(table->head == NULL)
        return -1;
    table->hash_width = width;
    return 0;
}

///释放
void hash_free(struct hash_table table){
    if(table.head!=NULL){
        for (int i=0; i<table.hash_width; i++) {
            struct hash_data* element_head= table.head[i];
            while (element_head !=NULL) {
                struct hash_data* temp =element_head;
                element_head = element_head->next;
                free(temp);
            }
        }
        free(table.head);
        table.head = NULL;
    }
    table.hash_width = 0;
}

int hash_addr(struct hash_table table,int key){
    int addr =abs(key) % table.hash_width;
    return addr;
}

///增加
int hash_insert(struct hash_table table, int key, int value){
    struct hash_data *tmp = (struct hash_data *)malloc(sizeof(struct hash_data));
    // if(tmp == NULL)
    //     return -1;
    tmp->key = key;
    tmp->data = value;
    int k = hash_addr(table, key);
    tmp->next = table.head[k];
    table.head[k] = tmp;
    return 0;
}

///查找
struct hash_data* hash_find(struct hash_table table, int key){
    int k = hash_addr(table,key);
    struct hash_data *element_head = table.head[k];
    while (element_head != NULL) {
        if ( element_head->key == key) {
            return element_head;
        }
        element_head = element_head->next;
    }
    return NULL;
}
///依赖map实现
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	printf("%s\n", __func__);
    int *res = (int *)malloc(sizeof(int) * 2);
    printf("---\n");
    // *returnSize = 0;
    struct hash_table table;
    hash_init(&table, 100);

    for (int i = 0; i < numsSize; i++) {
        hash_insert(table, nums[i], i);
    }

    for(int i = 0; i < numsSize; i++)
    {
        int value = target - nums[i];
        struct hash_data *data =  hash_find(table, value);
        if (data !=NULL && data->data != i) {
            res[1] = i;
            res[0] = data->data;
            * returnSize = 2;
        }
    }
    hash_free(table);
    return res;
}

int main() {

	printf("[%s %s] %s: %s: %d\n", __DATE__, __TIME__, __FILE__, __func__, __LINE__);
	int nums[] = {2, 4, 5, 7, 11, 15};
	int *n = NULL;
	int *re = (int *)malloc(sizeof(int) * 2);

	re = twoSum(nums, 6, 9, n);
	printf("------\n");
	printf("%d %d\n", re[0], re[1]);

}

