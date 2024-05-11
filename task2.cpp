#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

string inverse(string S){
    for (char c : S){
        if (c == '0'){
            c = '1';
        } else {
            c = '0';
        }
    }
    return S;
}

string reverse(string S){
    reverse(S.begin(), S.end());
    return S;
}

string recursion(int n){
    if (n == 1){
        return "0";
    }
    string prevSeq = recursion(n-1);
    return prevSeq + '1' + reverse(inverse(prevSeq));
}

int main(){
    system("chcp 65001");
    int n, k;
    cout << "Введите число n, 1 <= n <= 20: ";
    cin >> n;
    while (n <= 0 or n > 20){
        cout << "\nВведено неверное число n, попробуйте еще раз: ";
        cin >> n;
    }
    cout << "\nВведите число k, 1 <= k <= 2^n - 1: ";
    cin >> k;
    while (k <= 0 or k > (pow(2, n) - 1)){
        cout << "\nВведено неверное число k, попробуйте еще раз: ";
        cin >> k;
    }
    string result = recursion(n);
    cout << result[k];
}