/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */
 struct Node * makeClone(struct Node *s){
    struct Node* clone = malloc(sizeof(struct Node));
    clone->val = s->val;
    clone->numNeighbors = s->numNeighbors;
    clone->neighbors = malloc(clone->numNeighbors*sizeof(struct Node*));
    return clone;
 }

struct Node *cloneGraph(struct Node *s) {
    if (s == NULL) return NULL;
	struct Node* array[101] = {NULL};
    struct Node* queue[101];
    int front = 0;
    int rear = 0;
    struct Node* clone = makeClone(s);
    array[s->val] = clone;
    queue[rear++] = s;
    while(front< rear){
        struct Node* cur = queue[front++];
        int size = cur->numNeighbors;
        for(int i = 0; i<size; i++){
             struct Node* ner = cur->neighbors[i];
             int idx = ner->val;
             if (array[idx] == NULL){
                struct Node* clone = makeClone(ner);
                array[idx] = clone;
                queue[rear++] = ner;
             }
             array[cur->val]->neighbors[i] = array[idx];
        }
        
    }
    return clone;
}