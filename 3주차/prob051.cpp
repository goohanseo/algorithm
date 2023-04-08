#include <stdio.h>
#include <stdlib.h>

#define PATH 0
#define WALL 1
#define VISITED 2
#define BACKTRACKED 3

int N, T, X, Y;
int maze[10][10];

//dir 0 -> up dir 1 -> right dir 2 -> down dir 3 -> left
bool findpath(int x, int y, int dir, int turns);

int main() {
    int tmp;
    FILE* fp = fopen("input.txt", "r");
    fscanf(fp, "%d", &T);
    for (int i = 0; i < T; i++) {
        fscanf(fp, "%d", &N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                fscanf(fp, "%d", &tmp);
                maze[i][j] = tmp;
            }
        }
        fscanf(fp, "%d %d", &X, &Y);
        // Reset the maze array
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                maze[i][j] = tmp;
            }
        }
        if (findpath(0, 0, 1, 0)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}
bool findpath(int x, int y, int dir, int turns) {
    if (x < 0 || y < 0 || x >= N || y >= N || maze[x][y] != PATH) {
        return false;
    } else if (x == X && y == Y) {
        if (turns <= 2) {
            return true;
        } else {
            return false;
        }
    } else {
        maze[x][y] = VISITED;
        int newdir = (dir + 1) % 4;  // direction after turning right
        bool result = false;
        if (findpath(x, y - 1, (dir + 3) % 4, turns + 1) ||   // try to turn left
            findpath(x + 1, y, newdir, turns + 1) ||          // try to go straight
            findpath(x, y + 1, newdir, turns + 1) ||          // try to turn right
            findpath(x - 1, y, (dir + 2) % 4, turns + 1)) {   // make a U-turn
            result = true;
        }
        maze[x][y] = BACKTRACKED;
        return result;
    }
}