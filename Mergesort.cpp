#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string name;
    int deadline;
};

void merge(vector<Task>& tasks, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Task> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = tasks[left + i];
    for (int i = 0; i < n2; ++i) R[i] = tasks[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].deadline <= R[j].deadline) {
            tasks[k++] = L[i++];
        } else {
            tasks[k++] = R[j++];
        }
    }

    while (i < n1) tasks[k++] = L[i++];
    while (j < n2) tasks[k++] = R[j++];
}

void mergeSort(vector<Task>& tasks, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(tasks, left, mid);
        mergeSort(tasks, mid + 1, right);
        merge(tasks, left, mid, right);
    }
}

int main() {
    vector<Task> tasks = {
        {"Rescue Team A", 3},
        {"Rescue Team B", 1},
        {"Rescue Team C", 2}
    };

    mergeSort(tasks, 0, tasks.size() - 1);

    for (const auto& task : tasks) {
        cout << task.name << " - Deadline: " << task.deadline << endl;
    }
    return 0;
}
