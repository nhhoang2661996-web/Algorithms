typedef struct {
    int position;
    int speed;
} Car;

int cmp(const void *a, const void *b) {
    Car *x = (Car*)a;
    Car *y = (Car*)b;
    return  y->position - x->position;
}
int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    Car cars[positionSize];

    for (int i = 0; i < positionSize; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }
    qsort(cars, positionSize, sizeof(Car), cmp);
    int count = 0;
    double timeLast = 0;
    for (int i = 0; i < positionSize; i++){
        double time = (double)(target - cars[i].position) / cars[i].speed;
        if (time> timeLast){
            count++;
            timeLast = time;
        }
    }
    return count;
}