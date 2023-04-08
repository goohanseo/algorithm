#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Bubble();
void Selection();
void Insertion();
void Merge();
void Quicksort_last();
void Quicksort_median();
void Quicksort_ramdom();
void Heap();
void C_library();
void test(int k);

int test_data[3] = {1000,10000,100000};
int test_array[10];
clock_t start, finish;
double duration;
int main(){
    printf("             N=1000            N=10000           N=100000\n");
    Bubble();
    Selection();
    Insertion();
    Merge();
    Quicksort_last();
    Quicksort_median();
    Quicksort_ramdom();
    Heap();
    C_library();
    return 0;
}
void test(int k){

    srand(time(NULL));
    for(int j=0; j<10; j++){
        test_array[j] = rand()%k +1;
    }
}
void Bubble(){
    printf("Bubble       ");
    for(int data_num=0; data_num<3; data_num++){
        test(test_data[data_num]);
        int i, j, temp=0;
        start = clock();
        for (i = 0; i < 10; i++){
            for (j = 0; j < 10-i; j++){
                if (test_array[j] > test_array[j+1]){
                    temp = test_array[j];
                    test_array[j] = test_array[j+1];
                    test_array[j+1] = temp;
                    }
                }
            }
        finish = clock();
        printf("%f          ",  (double)(finish - start) / CLOCKS_PER_SEC);
     
}
    printf("\n");

}
void Selection(){
    printf("Selection    ");
    for(int data_num=0; data_num<3; data_num++){
        test(test_data[data_num]);
        int i, temp, max =0;
        int j =10;
        start = clock();
        while(j>0){
        for(i=0; i<j; i++){
            max = 0;
            if (test_array[i]>test_array[max]){
                max = i;
            }
        }
        temp = test_array[j-1];
        test_array[j-1] = test_array[max];
        test_array[max] = temp;
        j--;
        }
        finish = clock();
        printf("%f          ",  (double)(finish - start) / CLOCKS_PER_SEC);
     
        }
            printf("\n");

}
void Insertion(){
    printf("Insertion       ");
    for(int data_num=0; data_num<3; data_num++){
        test(test_data[data_num]);
        int i, temp, max =0;
        int j =10;
        start = clock();
}
}
void Merge(){}
void Quicksort_last(){}
void Quicksort_median(){}
void Quicksort_ramdom(){}
void Heap(){}
void C_library(){}