#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Job{
    int id;
    int dead;
    int profit;
};

bool comparision(Job a, Job b){
    return (a.profit > b.profit);
}

void JobSequencing(Job arr[], int n){
    sort(arr, arr + n, comparision);

    int result[n];
    bool slot[n];

    for(int i=0; i<n; i++){
        slot[i] = false;
    }

    for(int i=0; i<n; i++){
        for(int j=min(n, arr[i].dead) - 1; j>=0; j--){
             if (slot[j] == false){
                result[j] = i;
                slot[j] = true;
                break;
             }
        }

    }
    printf("Result: ");
    for(int i=0; i<n; i++){
        if(slot[i]){
            cout<<arr[result[i]].id<<" ";
        }
    }

}


int main(){
    int n;
    cout<<"Enter the number of jobs: "<<endl;
    cin>>n;
    int dead[n];
    int profit[n];

    cout<<"Enter the Profits: "<<endl;
    for(int i=0; i<n; i++){
        cin>>profit[i];
    }

    cout<<"Enter the Deadlines: "<<endl;
    for(int i=0; i<n; i++){
        cin>>dead[i];
    }

    Job arr[n];
    for(int i=0; i<n; i++){
        arr[i] = {i + 1, dead[i], profit[i]};
    }

    JobSequencing(arr, n);

    return 0;

}
