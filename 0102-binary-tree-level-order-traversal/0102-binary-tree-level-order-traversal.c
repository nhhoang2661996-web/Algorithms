/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL){
        *returnSize = 0;
        return NULL;
    } 
    int** result = malloc(sizeof(int*) * 2000);
    struct TreeNode* queue[2000];
    *returnColumnSizes = malloc(sizeof(int) * 2000);
    int front = 0 ;
    int rear = 0;
    int level = 0;
    queue[rear++] = root;
    while(front < rear){
        int size = rear - front;
        (*returnColumnSizes)[level] = size;
        result[level] = malloc(sizeof(int) * size);
        for (int i = 0 ; i < size; i++){
            struct TreeNode* cur = queue[front++];
            result[level][i] = cur->val;
            if(cur->left != NULL) queue[rear++] = cur->left;
            if(cur->right != NULL) queue[rear++] = cur->right;
        }
        level++;
    }
    *returnSize = level;
    return result;
}