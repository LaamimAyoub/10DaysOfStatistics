#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Inputs{
    int n;
    vector<float> vec1;
    vector <float> vec2;
    float mu_x;
    float mu_y;
    float sigma_x;
    float sigma_y;
};

vector<float> read_vec(int n){
    vector<float> vec;
    float val;
    for (int i = 0; i < n; i++ ){
        cin >> val;
        vec.push_back(val);
    }
    return vec;
}

void print_vec(vector<float> vec){
    int n = vec.size();
    for (int i; i < n; i++){
        cout << vec[i] << "|";
    };
    cout << endl;
}

float get_mean(vector<float> vec, int n){
    float sum = 0;
    for (int i =0; i < n; i++){
        sum+= vec[i];
    }
    
    return sum / (float) n;
}

float get_std(vector<float> vec, float mu, float n){
    float sum = 0;
    for (int i =0; i < n; i++){
      sum += (vec[i] - mu) * (vec[i] - mu);  
    };
    
    return sqrtf(sum)/ sqrtf((float) n);
}

Inputs read_inputs(){
    
    Inputs inputs;
    
    cin >> inputs.n;
    
    inputs.vec1 = read_vec(inputs.n);
    inputs.vec2 = read_vec(inputs.n);
    
    inputs.mu_x = get_mean(inputs.vec1, inputs.n);
    inputs.mu_y = get_mean(inputs.vec2, inputs.n);
    
    inputs.sigma_x = get_std(inputs.vec1, inputs.mu_x, inputs.n);
    inputs.sigma_y = get_std(inputs.vec2, inputs.mu_y, inputs.n);
    
    return inputs;
    
}

float calculate_num(Inputs inputs){
    float sum = 0;
    for (int i=0; i < inputs.n; i++){
        sum += (inputs.vec1[i] - inputs.mu_x) * (inputs.vec2[i] - inputs.mu_y); 
    };
    return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
   
    Inputs inputs = read_inputs();
    
    float num = calculate_num(inputs);
    float res = num/ (inputs.n * inputs.sigma_x * inputs.sigma_y);
    
    printf("%.3f", res);
    return 0;
}
