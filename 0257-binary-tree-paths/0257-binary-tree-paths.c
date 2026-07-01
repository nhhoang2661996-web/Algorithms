/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void getChar(struct TreeNode* root,char* paths,char** result,int* returnSize){
    if(root == NULL)return;
    struct TreeNode *left = root->left;
    struct TreeNode *right = root->right;
    int len = strlen(paths);
    char newPath[len+10];
    if(len == 0){
        sprintf(newPath, "%d", root->val);
    }else{
        sprintf(newPath, "%s->%d", paths, root->val);
    }
    if(root->left == NULL && root->right == NULL){
        result[*returnSize] = malloc(strlen(newPath) + 1);
        strcpy(result[*returnSize], newPath);
        (*returnSize)++;
        return;
    }
    getChar(left,newPath, result,returnSize);
    getChar(right,newPath, result,returnSize);
}
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    char** result = malloc(100*sizeof(char*));
    *returnSize = 0;
    getChar(root,"", result,returnSize);
    return result;
}