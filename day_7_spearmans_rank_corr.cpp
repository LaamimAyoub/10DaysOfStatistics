#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Inputs {
    int n;
    vector<float> vec_x;
    vector<float> vec_y;
};

vector<float> read_vec(int n){
    vector<float> vec;
    float val;
    for (int i = 0; i < n ; i++){
        cin >> val;
        vec.push_back(val);
    };
    return vec;
}

Inputs read_inputs(){
    Inputs inputs;
    cin >> inputs.n;
    
    inputs.vec_x = read_vec(inputs.n);
    inputs.vec_y = read_vec(inputs.n);
    
    return inputs;
    
    
}

int* get_ranks(int n, vector<float> values){
    int* ranks = new int[n];
    // init arr by ones
    for (int i =0; i < n; i++){
        ranks[i] = 1;
    };
    // To get the rank of each elements : loop over all the elements 
    // twice and in the first loop incriment the rank by 1 for each element that our elemnt is superior of
    
    for (int i =0; i< n; i++){
        for (int j =0; j<n; j++){
            if (values[i] > values[j]){
                ranks[i] += 1;
            };
        };
    };
    
    return ranks;
    
}


float get_sum_di_squared(int* rank_x, int* rank_y, int n){
    float sum = 0;
    float d;
    for (int i =0; i < n; i++){
        d = (float) rank_x[i] - (float) rank_y[i];
        sum += d*d;
    }
    return sum;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    Inputs inputs = read_inputs();

    
    int* rank_x = get_ranks(inputs.n, inputs.vec_x);
    int* rank_y = get_ranks(inputs.n,inputs.vec_y);
    
    float sum_di_squared = get_sum_di_squared(rank_x, rank_y, inputs.n);
    
    float n = (float) inputs.n;
    float r = 1 - 6 * sum_di_squared / ( n * ( (n*n) - 1));
    
    printf("%.3f", r);
    
    
    delete [] rank_x;
    delete [] rank_y;
     
    return 0;
}
