#include <stdio.h>
#include <stdlib.h>


int total_weight;
int weight[100];
int price[100];
int plus[100];
int N;
int MAX = 0;

void read_file();
void measurement(int k);

int main(){
    read_file();
    measurement(0);
    printf("%d", MAX);
    return 0;
}

void measurement(int k){
    int maxw = 0, maxp = 0;
    if (k==N){
        for (int i=0; i<N; i++){
            if(plus[i] == 1){
                maxw += weight[i];
                maxp += price[i];
            }
        }
        if (maxw <= total_weight){
            if (MAX <= maxp){
                MAX = maxp;
            }
        } 
    }
    else{
        plus[k] = 1;
        measurement(k+1);
        plus[k] = 0;
        measurement(k+1);
    }

}

void read_file(){
	FILE* fp = fopen("input.txt", "r");
    fscanf(fp, "%d", &N);
    fscanf(fp, "%d", &total_weight);
    for(int i=0; i<N; i++){
        fscanf(fp, "%d", &weight[i]);
    }
    for(int i=0; i<N; i++){
        fscanf(fp, "%d", &price[i]);
    }
    fclose(fp);
}