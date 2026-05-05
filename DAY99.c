#include <stdio.h>
#include <stdlib.h>

// Struct to hold car info
typedef struct {
    int pos;
    int speed;
} Car;

// Comparator for sorting cars by position descending
int cmp(const void* a, const void* b) {
    Car* carA = (Car*)a;
    Car* carB = (Car*)b;
    return carB->pos - carA->pos; // descending
}

int carFleet(int target, int* position, int n, int* speed) {
    if (n == 0) return 0;

    Car* cars = (Car*)malloc(n * sizeof(Car));
    for (int i = 0; i < n; i++) {
        cars[i].pos = position[i];
        cars[i].speed = speed[i];
    }

    // Sort cars by position descending
    qsort(cars, n, sizeof(Car), cmp);

    int fleets = 0;
    double lastTime = -1.0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].pos) / cars[i].speed;
        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
        // else merges into current fleet
    }

    free(cars);
    return fleets;
}

int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int n = sizeof(position) / sizeof(position[0]);

    int result = carFleet(target, position, n, speed);
    printf("Number of car fleets: %d\n", result); // Output: 3

    return 0;
}
