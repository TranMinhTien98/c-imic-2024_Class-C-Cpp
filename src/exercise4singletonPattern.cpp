//Bai 4
#include "exercise4singletonPattern.hpp"

// Đảm bảo chỉ có 1 instance của class được tạo ra trong suốt chương trình
Singleton* Singleton::_singleton = NULL; // Khởi tạo biến tĩnh

Singleton *Singleton::getInstance(const string& value) /* phương thức tĩnh (static),
                                                 trả về con trỏ đến instance duy nhất của lớp Singleton */
{
    if(_singleton == NULL){ /* Nếu _singleton = NULL: Chưa có instance nào của lớp Singleton được tạo ra, 
                            và chương trình sẽ tạo một thể hiện mới */
        _singleton = new Singleton(value);
    }
    return _singleton; // Ngược lại thì phương thức sẽ trả về instance đó mà không tạo thêm instance mới.
}

string Singleton::getValue() const { /* Phương thức công khai (public) của lớp Singleton, 
                                        dùng để truy cập giá trị của biến _value */
    return this->_value;
}