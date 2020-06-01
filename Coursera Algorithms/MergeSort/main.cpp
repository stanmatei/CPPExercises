#include <iostream>

using namespace std;
void  MergeSort(int n, int &l){
   if(n != 1){
       int *l1[n - (n / 2)];
       int *l2[n/2];

       for(int i = 0; i < n - (n / 2); i++){
            l1[i] = l[i];
       }
       for(int i = n - (n / 2); i < n; i++){
            l2[i] = l[i];
       }
       MergeSort(l1, n - (n / 2));
       MergeSort(l2, n/2);

       int i = 0;
       int j = 0;
       int result[n];
       for(int k = 0; k < n; k++){
            if(j < n/2 && i < n - (n / 2)){
                   if(l1[i] < l2[j]){

                        result[k] = l1[i];
                        i++;

                   }
                   else{
                        result[k] = l2[j];
                        j++;
                   }
            }
            else if(j >= n/2 && i < n - (n / 2)){
                result[k] = l1[i];
                i++;
            }
            else if(j < n/2 && i >= n - (n / 2)){
                result[k] = l2[j];
                j++;
            }
       }

       for(int x; x < n; x++){
            l[x] = result[x];
       }

   }
}

int main()
{
    int li[] = {9, 4, 6, 1, 3, 8, 7, 5, 2};
    MergeSort(li, 9);
    for(int i = 0; i < 9; i++){
        cout<<li[i]<< " ";
    }

    return 0;
}
