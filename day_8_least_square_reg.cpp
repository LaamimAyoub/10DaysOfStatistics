#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Inputs{
    vector<int> x;
    vector<int> y;
};

Inputs read_inputs(){
    int n = 5;
    int val;
    Inputs inputs;
    for (int i =0; i < n; i++){
        cin >> val;
        inputs.x.push_back(val);
        cin >> val;
        inputs.y.push_back(val);
    };
    return inputs;
}

float sum(vector<int> x){
    int n = x.size();
    float sum = 0.0;
    for (int i = 0; i < n; i++){
        sum += (float) x[i];
    };
    return sum;
}

float sum_squared(vector<int> x){
    int n  = x.size();
    float sum = 0.0;
    for (int i = 0; i < n ; i++){
        sum += (float) (x[i] * x[i]);
    };
    return sum;
}

float sum_prod(vector<int> x, vector<int> y){
    int n = x.size();
    float sum = 0.0;
    for (int i =0; i< n; i++){
        sum += (float) (x[i] * y[i]);
    };
    return sum;
}

float get_b(Inputs inputs){
    int n = 5;
    float sum_x = sum(inputs.x);
    float sum_y = sum(inputs.y);
    float sum_x_squared = sum_squared(inputs.x);
    float sum_prod_x_y = sum_prod(inputs.x, inputs.y);
    
    float b = (n * sum_prod_x_y - sum_x * sum_y)/(n * sum_x_squared - sum_x * sum_x);
    return b;
}

float calculate_mean(vector<int> x){
    int n = x.size();
    int sum  = 0;
    for (int i = 0; i < n; i++){
        sum+= x[i];
    };
    return (float) sum / (float) n ;
       
}

float get_a(Inputs inputs, float b){
        float mean_x = calculate_mean(inputs.x);
        float mean_y = calculate_mean(inputs.y);
        
        float a = mean_y - b * mean_x;
        
        return a;   
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    Inputs inputs = read_inputs();
    float b = get_b(inputs);
    float a = get_a(inputs, b);
    
    float x = 80.0;
    float y = a  + b *x;
    
    printf("%.3f", y);
    
    return 0;
}
