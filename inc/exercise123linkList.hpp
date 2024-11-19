#include <iostream>
using namespace std;
/*  
Khởi tạo 1 Struct Node 
Tạo biến data để lưu giá trị của Node
Tạo biến con trỏ của chính nó, trỏ đến Node tiếp theo
*/
struct Node {
    int data;
    Node* next;
};

/*
Khởi tạo 1 struct SLL để chứa danh sách liên kết 
Tạo biến con trỏ của chính nó, trỏ đến phần tử đầu tiên của danh sách liên kết
*/ 
struct SLL {
    Node *head;
};

// Khởi tạo danh sách liên kết
void init(SLL*);

// Thêm 1 phần tử mới vào đầu danh sách liên kết
void addHead(SLL*, int);

// Thêm 1 phần tử mới vào cuối danh sách liên kết
void addTail(SLL*, int);

/*
Thêm 1 phần tử vào danh sách liên kết
Có chọn vị trí cần thêm vào danh sách liên kết do người dùng đặt
*/ 
void insertNode(SLL*, int, int);

/*
Xóa 1 phần tử có giá trị do người dùng đặt
Giữ nguyên nếugiá trị của phần tử cần xóa không có trong danh sách liên kết
*/ 
void deleteNode(SLL*, int);

// In ra danh sách liên kết
void printList(SLL*);

// Tạo biến con trỏ của chính nó, trỏ đến Node có giá trị lớn nhất
Node* findMax(SLL*);

// Tạo biến con trỏ của chính nó, trỏ đến Node có giá trị nhỏ nhất
Node* findMin(SLL*);

// Biến boolean, hàm kiểm tra danh sách liên kết có vòng lặp hay không
bool containsLoop(SLL*);

// Biến integer, tìm độ dài (tổng số node) của danh sách liên kết
int calculateLen(SLL *);