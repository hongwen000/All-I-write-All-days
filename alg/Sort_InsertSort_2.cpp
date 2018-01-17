void insertSort(int* R, int n){
    for(int i = 2; i < n; ++i){
        if(R[i] < R[i-1]){
            R[n] = R[i];
            int j = i - 1;
            for(; R[n] < R[j]; --j)
                R[j+1] = R[j];
            R[j+1] = R[n];
        }
    }
}
