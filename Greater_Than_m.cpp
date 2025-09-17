#include <iostream>
using namespace std;

// Tự cài đặt danh sách liên
struct node {
    int info;  // Nếu như có nhiều info tức là ví dụ sinh viên thì struct sv
    node* next;
};

struct List {
    // thêm đầu và cuối để dễ quản lý danh sách liên kết
    node* head;
    node* tail;
    List() {
        head = tail = nullptr;
    }
};

void init(List &L) {
    // Khởi tạo dslk
    L.head = L.tail = nullptr;
}

node* createNode(int x) {
    node* p = new node;
    p->info = x;
    p->next = nullptr;
    return p;
}

void addHead(List &L, int x) {
    node* p = createNode(x);
    if (L.head == nullptr) {
        L.head = L.tail = p;
    } else {
        p->next = L.head;
        L.head = p;
    }
}

void addTail(List &L, int x) {
    node* p = createNode(x);
    if (L.head == nullptr) {
        L.head = L.tail = p;
    } else {
        L.tail->next = p;
        L.tail = p;
    }
}

void outputGreaterThan(List &L, int m) {
    bool found = false;
    if (L.head == nullptr) {
        cout << "List is empty" << endl;
    } else {
        node* p = L.head;
        while (p != nullptr) {
            if (p->info > m) {
                cout << p->info << " ";
                found = true;
            }
            p = p->next;
        }
        if (!found) {
            cout << "None" << endl;
        } else {
            cout << endl;
        }
    }
}

void printList(List &L) {
    if (L.head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    node* p = L.head;
    while (p != nullptr) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

void InputList(List &L, int n) {
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        addTail(L, x);
    }
}

int main() {
    List L;  // Khai báo 1 danh sách
    init(L); // Khởi tạo danh sách

    int n;
    cout << "Enter a number: ";
    cin >> n;  // Nhập số lượng phần tử của ds
    cout << "\nEnter a sequence of " << n << " numbers: ";
    InputList(L, n); // Nhập 1 dãy gồm n số và lưu vào ds. Phần tử mới được thêm vào cuối ds.
    cout << "\nThe created Linked List: ";
    printList(L); // Xuất ds. Nếu ds rỗng thì xuất thông báo "List is empty"

    cout << "\nEnter a number: ";
    int m;
    cin >> m;

    cout << "\nValues greater than " << m << ": ";
    outputGreaterThan(L, m);
    /*Xuất tất cả các giá trị được lưu trong ds lớn hơn m.
      Nếu ds rỗng thì xuất thông báo "List is empty".
      Nếu ds không rỗng nhưng không có giá trị thỏa yêu cầu thì xuất "None".*/

    return 0;
}
