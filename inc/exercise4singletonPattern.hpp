#include <iostream>
using namespace std;

/*
Khai báo lớp Singleton. Mục đích đảm bảo chỉ có một thể hiện (instance) 
của lớp này được tạo ra và nó có thể được truy cập toàn cục
*/
class Singleton {
    protected:
        string _value; // _value: Biến kiểu string dùng để lưu giá trị của đối tượng singleton
        static Singleton *_singleton; /* _singleton: Một con trỏ tĩnh (static pointer) kiểu Singleton, 
                                        dùng để lưu trữ đối tượng duy nhất của lớp Singleton */
                                      
        Singleton(const string value) { // Constructor này nhận một tham số kiểu string
            _value = value; // gán giá trị này cho biến _value
        }

    public:
        Singleton(Singleton &other) = delete; // Xoá bỏ copy constructor

        void operator=(const Singleton &) = delete; // Xoá bỏ copy assignment operator

        static Singleton *getInstance(const string& value); /* Phương thức tĩnh (static) trả về con trỏ 
                                                            đến thể hiện duy nhất của lớp Singleton */

        string getValue() const; // Phương thức công khai trả về giá trị của biến _value
};
/*
Ý nghĩa:
- Singleton: Chỉ có một thể hiện duy nhất của lớp.
- Constructor riêng (private constructor): Ngăn không cho đối tượng được tạo từ bên ngoài lớp.
- Static Instance Pointer: Giữ thể hiện duy nhất của lớp.
- Xoá bỏ copy constructor/assignment operator: Ngăn không cho sao chép thể hiện.
*/