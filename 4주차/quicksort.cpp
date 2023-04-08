quickSort(A[],p,r)
{
    if (p<r) then {
        q = partition(A,p,r); //분할
        quickSort(A,p,q-1); //왼쪽 정렬
        quickSort(A,p+1,r); //오른쪽 정렬
    }
}

partition(A[],p,r){
    if A[j]>=x
        j<-j+1;
    else   
        i<-i+1;
        exchange A[i] and A[j];
        j<-j+1;       
}