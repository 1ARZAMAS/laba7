#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

using namespace std;

ostream& operator<< (ostream& os, const vector <int>& sequence) { // перегрузим вывод тоже чисто по приколу :)
    for (int i = 0; i < sequence.size(); ++i){
        os << sequence[i] << ' ';
    }
    return os;
}

vector<int> buildSequenceRecursive(const vector<int>& arr, int lastNumber = -1) { // int lastNumber = -1 означает, что начинаем с начала
    vector<int> longestSequence; // сюда будем записывать самую длинную последовательность
    for (int i = 0; i < arr.size(); i++) { // в поисках числа пройдемся по всему массиву
        if (lastNumber == -1 || to_string(lastNumber).back() == to_string(arr[i]).front()) { // проверяем начало ли это последовательности
            vector<int> remaining = arr; // создаем копию вектора 
            remaining.erase(remaining.begin() + i); // из которого будем удалять уже использованные числа
            vector<int> nextSequence = buildSequenceRecursive(remaining, arr[i]); // рекурсивно вызываем себя же
            if (nextSequence.size() > longestSequence.size()) { // проверям на максимальную длину последовательности
                longestSequence = nextSequence;
            }
        }
    }
    if (lastNumber != -1) { // проверяем было ли найдено хоть одно число в последовательности, если да, то
        longestSequence.insert(longestSequence.begin(), lastNumber); // вставляем число в самое начало, тк
    } // до этого мы его не учитывали
    return longestSequence;
}

int main() {
    system("chcp 65001");
    minstd_rand gen(std::random_device{}());
    uniform_int_distribution<> dis(1, 1000);

    int n = 25;
    
    vector<int> arr(n);
    
    for (int& num : arr) { // Генерируем простые числа и заполняем ими вектор чисто по приколу :)
        num = dis(gen);
    }
    vector<int> sequence = buildSequenceRecursive(arr); // Создаем вектор, куда будет записываться самая длинная последовательность
    cout << "\nСамая длинная последовательность:" << endl;
    cout << sequence; // выводим вектор
}
