#include <stdio.h>
#include <stdlib.h>
#define PATH 0
#define WALL 1
#define VISITED 2
#define BACKTRACKED 3

int N,T,X,Y;
int maze[10][10];

//dir 0 -> up dir 1 -> right dir 2 -> down dir 3 -> left
bool findpath(int x, int y, int dir);
bool solve();
bool visitied[][];
int main(){
    int tmp;
    FILE* fp = fopen("input.txt", "r");
    fscanf(fp, "%d", &T);
    for(int i=0; i<T; i++){
        fscanf(fp,"%d",&N);
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                fscanf(fp,"%d",&tmp);
                maze[i][j] = tmp;
            }
        }
        fscanf(fp,"%d %d",&X,&Y);
        if(solve()){
            printf("yes\n");
        }
        else
            printf("no\n");
    }

    return 0;
}

bool solve(){
    bool visited[N][N] = {false};
    return findpath(0,0,1,visited);
}

bool findpath(int x, int y, int dir, bool visited[][N]){
    if (x<0 || y<0 || x>=N || y>=N || maze[x][y] == WALL || visited[x][y]){
        return false;
    }
    else if (x == X && y == Y){
        return true;
    } 
    else{
        maze[x][y] = VISITED;
        if(dir == 0){
            if(findpath(x+1,y,1) || findpath(x,y-1,0) || findpath(x,y+1,2))
            return true;
        }
        else if(dir == 1){
            if( findpath(x,y+1,2)|| findpath(x+1,y,1) || findpath(x-1,y,3))
            return true;
        }
        else if(dir == 2){
            if( findpath(x-1,y,3) || findpath(x,y+1,2)|| findpath(x,y-1,0))
            return true;
        }
        else if(dir == 3){
            if(findpath(x,y+1,0) || findpath(x-1,y,3) || findpath(x+1,y,1))
            return true;
        }
        maze[x][y] = BACKTRACKED;
    }
    return false;
        
}