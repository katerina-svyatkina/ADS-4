// Copyright 2021 NNTU-CS
int Fbinsearch(int* arr, int len, int value) {
    int right = len - 1, left = 0, sum = 0;
    int half_size = (right + left) / 2;
    if (len == 0) {
        return 0;
    }
    if (arr[half_size] == value) {
        int end = half_size, start = half_size;
        while (start >= 0 && arr[--start] == value) {}
        while (end < len && arr[++end] == value) {}
        return end - start - 1;
    } else if (arr[half_size] > value) {
        right = half_size;
        return Fbinsearch(arr, half_size - left, value);
    } else {
        left = half_size;
        return Fbinsearch(&(arr[half_size + 1]), right - half_size, value);
    } 
}
int countPairs1(int* arr, int len, int value) {
    int sum = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                sum++;
            }
        }
    }
    return sum;
}
int countPairs2(int* arr, int len, int value) {
    int sum = 0;
    for (int i = 0; i < len - 1; i++) {
        if (arr[i] <= value) {
            for (int j = i + 1; j < len; j++) {
                if (arr[i] + arr[j] == value) {
                    sum++;
                }
            }
        }
    }
    return sum;
}
int countPairs3(int* arr, int len, int value) {
   int sum = 0, temp = 0;
   for (int i = 0; i < len - 1; i++) {
       if (arr[i] > value / 2) {
           break;
       }
       sum += Fbinsearch(&(arr[i+1]), len-i-1, value-arr[i]);
   }
   return sum;
}
