#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

//STRUCTURES

struct Criminal {
    int id;
    char name[30];
    int crimes;
    int totalSentence;
    int remainingYears;
    int risk;
};

struct Node {
    Criminal data;
    Node* next;
};

//GLOBAL DATA

Node* head = NULL;

//Priority Queue (Most Wanted) 
Criminal pq[MAX];
int pqSize = 0;

//Graph (Adjacency Matrix)
int graph[MAX][MAX] = {0};

// Array for Sorting & Searching
Criminal arr[MAX];
int arrSize = 0;

// UTILITY 

void line() {
    cout << "\n====================================================\n";
}

//PRIORITY QUEUE

void insertPriorityQueue(Criminal c) {
    int i = pqSize - 1;
    while (i >= 0 && pq[i].risk < c.risk) {
        pq[i + 1] = pq[i];
        i--;
    }
    pq[i + 1] = c;
    pqSize++;
}

//LINKED LIST

void addCriminal() {
    Node* n = new Node;

    cout << "Enter ID: ";
    cin >> n->data.id;
    cout << "Enter Name: ";
    cin >> n->data.name;
    cout << "Crimes Committed: ";
    cin >> n->data.crimes;
    cout << "Total Sentence (years): ";
    cin >> n->data.totalSentence;
    cout << "Remaining Sentence (years): ";
    cin >> n->data.remainingYears;
    cout << "Risk Level (1-10): ";
    cin >> n->data.risk;

    n->next = head;
    head = n;

    insertPriorityQueue(n->data);

    cout << "\nCriminal record added.\n";
}

void displayCriminals() {
    if (!head) {
        cout << "\nNo records available.\n";
        return;
    }

    line();
    cout << "ID   NAME     CRIMES   REMAIN   RISK\n";
    line();

    Node* t = head;
    while (t) {
        cout << t->data.id << "   "
             << t->data.name << "     "
             << t->data.crimes << "        "
             << t->data.remainingYears << "        "
             << t->data.risk << endl;
        t = t->next;
    }
}

void deleteCriminal() {
    int id;
    cout << "Enter Criminal ID to delete: ";
    cin >> id;

    Node* t = head;
    Node* p = NULL;

    while (t) {
        if (t->data.id == id) {
            if (p)
                p->next = t->next;
            else
                head = t->next;

            delete t;
            cout << "\nCriminal record deleted.\n";
            return;
        }
        p = t;
        t = t->next;
    }
    cout << "\nCriminal not found.\n";
}

// SORTING

void copyToArray() {
    Node* t = head;
    arrSize = 0;
    while (t) {
        arr[arrSize++] = t->data;
        t = t->next;
    }
}

// Bubble Sort – Remaining Sentence 
void sortByRemaining() {
    copyToArray();
    for (int i = 0; i < arrSize - 1; i++)
        for (int j = 0; j < arrSize - i - 1; j++)
            if (arr[j].remainingYears > arr[j + 1].remainingYears) {
                Criminal temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

    cout << "\nSorted by Remaining Sentence:\n";
    for (int i = 0; i < arrSize; i++)
        cout << arr[i].id << " " << arr[i].name << " "
             << arr[i].remainingYears << endl;
}

//Selection Sort – Crimes 
void sortByCrimes() {
    copyToArray();
    for (int i = 0; i < arrSize - 1; i++) {
        int min = i;
        for (int j = i + 1; j < arrSize; j++)
            if (arr[j].crimes < arr[min].crimes)
                min = j;

        Criminal temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    cout << "\nSorted by Crime Count:\n";
    for (int i = 0; i < arrSize; i++)
        cout << arr[i].id << " " << arr[i].name << " "
             << arr[i].crimes << endl;
}

// SEARCH 

void searchByID() {
    copyToArray();

    int id;
    cout << "Enter Criminal ID to search: ";
    cin >> id;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i].id == id) {
            cout << "\nCriminal Found:\n";
            cout << "Name: " << arr[i].name << endl;
            cout << "Crimes: " << arr[i].crimes << endl;
            cout << "Remaining Sentence: " << arr[i].remainingYears << endl;
            return;
        }
    }
    cout << "\nCriminal not found.\n";
}

// GRAPH 

void addRelation() {
    int a, b;
    cout << "Enter Criminal ID 1: ";
    cin >> a;
    cout << "Enter Criminal ID 2: ";
    cin >> b;

    graph[a][b] = graph[b][a] = 1;
    cout << "\nRelationship added.\n";
}

void BFS(int start) {
    int visited[MAX] = {0};
    int q[MAX], f = 0, r = 0;

    visited[start] = 1;
    q[r++] = start;

    cout << "Network (BFS): ";
    while (f < r) {
        int v = q[f++];
        cout << v << " ";
        for (int i = 0; i < MAX; i++)
            if (graph[v][i] && !visited[i]) {
                visited[i] = 1;
                q[r++] = i;
            }
    }
    cout << endl;
}

void DFS(int v, int visited[]) {
    visited[v] = 1;
    cout << v << " ";
    for (int i = 0; i < MAX; i++)
        if (graph[v][i] && !visited[i])
            DFS(i, visited);
}

// REPORTS

void statistics() {
    int count = 0, crimes = 0, rem = 0;
    Node* t = head;

    while (t) {
        count++;
        crimes += t->data.crimes;
        rem += t->data.remainingYears;
        t = t->next;
    }

    line();
    cout << "Total Criminals: " << count << endl;
    cout << "Total Crimes: " << crimes << endl;
    if (count)
        cout << "Average Remaining Sentence: " << rem / count << endl;
}

//MOST WANTED 

void mostWanted() {
    if (pqSize == 0) {
        cout << "\nNo data available.\n";
        return;
    }

    line();
    cout << "Most Wanted Criminal:\n";
    cout << "ID: " << pq[0].id << endl;
    cout << "Name: " << pq[0].name << endl;
    cout << "Risk Level: " << pq[0].risk << endl;
}

// PERFORMANCE

void performance() {
    line();
    cout << "Search (Linked List): O(n)\n";
    cout << "Search (Array): O(n)\n";
    cout << "Sorting Algorithms: O(n^2)\n";
}

// SAMPLE DATA 

void loadSampleData() {
    Criminal c1 = {101, "Ahmed", 5, 12, 7, 8};
    Criminal c2 = {102, "Bilal", 3, 8, 4, 6};
    Criminal c3 = {103, "Usman", 7, 15, 10, 9};
    Criminal c4 = {104, "Aliya", 2, 5, 3, 4};
    Criminal c5 = {105, "Faiza", 6, 10, 6, 7};

    Node* n;
    n = new Node{c1, head}; head = n;
    n = new Node{c2, head}; head = n;
    n = new Node{c3, head}; head = n;
    n = new Node{c4, head}; head = n;
    n = new Node{c5, head}; head = n;

    insertPriorityQueue(c1);
    insertPriorityQueue(c2);
    insertPriorityQueue(c3);
    insertPriorityQueue(c4);
    insertPriorityQueue(c5);

    graph[101][102] = graph[102][101] = 1;
    graph[102][103] = graph[103][102] = 1;
    graph[103][105] = graph[105][103] = 1;
}



void menu() {
    line();
    cout << "        CRIMINAL MANAGEMENT SYSTEM\n";
    line();
    cout << "1. Add New Criminal\n";
    cout << "2. Delete Criminal Record\n";
    cout << "3. Show All Criminal Records\n";
    cout << "4. Find Criminal by ID\n";
    cout << "5. Sort by Remaining Sentence\n";
    cout << "6. Sort by Crime Count\n";
    cout << "7. View High-Risk Criminal\n";
    cout << "8. Add Criminal Connection\n";
    cout << "9. View Criminal Network\n";
    cout << "10. Crime Statistics\n";
    cout << "11. System Performance\n";
    cout << "0. Exit\n";
    cout << "Enter choice: ";
}



int main() {
    loadSampleData();

    int choice, start;
    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1: addCriminal(); break;
            case 2: deleteCriminal(); break;
            case 3: displayCriminals(); break;
            case 4: searchByID(); break;
            case 5: sortByRemaining(); break;
            case 6: sortByCrimes(); break;
            case 7: mostWanted(); break;
            case 8: addRelation(); break;
            case 9: {
                cout << "Enter starting ID: ";
                cin >> start;
                BFS(start);
                cout << "DFS: ";
                int visited[MAX] = {0};
                DFS(start, visited);
                cout << endl;
                break;
            }
            case 10: statistics(); break;
            case 11: performance(); break;
        }
    } while (choice != 0);

    return 0;
}
