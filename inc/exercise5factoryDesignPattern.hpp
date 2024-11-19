/*
Phân tích Factory Design Pattern trong C++
1.	Factory Design Pattern là gì?
- Factory Pattern là một mẫu thiết kế thuộc nhóm Creational Patterns trong lập trình hướng đối tượng.
- Mẫu này giúp tạo ra các đối tượng mà không cần chỉ định lớp cụ thể cho từng đối tượng.
- Factory Pattern cho phép tạo ra các đối tượng dựa trên các điều kiện cụ thể, 
  đồng thời giúp mã dễ dàng mở rộng, bảo trì và thay đổi các lớp đối tượng 
  mà không ảnh hưởng đến mã hiện có.

2.	Khi nào nên dùng Factory Pattern?
- Khi có nhiều lớp cụ thể với các đặc điểm tương tự cần được tạo ra nhưng loại đối tượng cụ thể 
  sẽ được xác định vào thời gian chạy (runtime).
- Khi muốn giảm sự phụ thuộc giữa mã tạo đối tượng và mã thực thi logic của đối tượng đó.
- Khi muốn làm cho mã linh hoạt và có thể mở rộng mà không cần thay đổi mã gốc 
  mỗi khi thêm một loại đối tượng mới.

3.	Cấu trúc Factory Pattern
- Interface hoặc Abstract Class: Định nghĩa chung cho các lớp sản phẩm.
- Concrete Classes: Các lớp cụ thể thực thi interface, đại diện cho các sản phẩm có thể được tạo ra.
- Factory Class: Chứa logic để tạo ra các đối tượng cụ thể dựa trên tham số hoặc điều kiện đầu vào.
*/

#include <iostream>
#include <string>
#include <memory>
using namespace std;
/* 
- Logger: Là một interface (lớp cơ sở) định nghĩa một phương thức thuần ảo Log() để ghi log. 
- ConsoleLogger và FileLogger: Các lớp con của Logger thực hiện chức năng ghi log cụ thể. 
- LoggerFactory: Là lớp factory chịu trách nhiệm tạo ra các đối tượng Logger 
  dựa trên kiểu được yêu cầu (Console hoặc File). 
*/

/* 
Phân tích Lớp Logger: 
- virtual ~Logger(): Destructor ảo để đảm bảo giải phóng tài nguyên đúng cách khi sử dụng con trỏ
  đến lớp cơ sở. Log(const string& message) const = 0;
- Phương thức thuần ảo, yêu cầu các lớp con phải override và cung cấp các triển khai cụ thể. 
*/
class Logger {
    public:
        virtual ~Logger() {}

        virtual void Log(const string& message) const = 0;
};

// Phân tích Lớp ConsoleLogger: Triển khai phương thức Log() để ghi các thông báo vào console.
class ConsoleLogger : public Logger {
public:
    void Log(const string& message) const override {
        cout << "Console Logger: " << message << endl;
    }
};

// Phân tích Lớp FileLogger: Triển khai phương thức Log() để ghi các thông báo vào file (mô phỏng bằng cout)
class FileLogger : public Logger {
public:
    void Log(const string& message) const override {
        cout << "File Logger: " << message << endl;  // Ghi log vào file mô phỏng (sử dụng cout để mô phỏng)
    }
};


/* Phân tích lớp LoggerFactory:
- enum class LoggerType: Định nghĩa các kiểu logger mà factory có thể tạo ra (Console, File).
- CreateLogger(LoggerType type): Trả về con trỏ thông minh std::unique_ptr<Logger> 
  trỏ đến một đối tượng Logger.
- Tạo ra đối tượng ConsoleLogger hoặc FileLogger dựa trên kiểu logger được yêu cầu.
*/
class LoggerFactory {
public:
    enum class LoggerType {
        Console,
        File
    };

    static std::unique_ptr<Logger> CreateLogger(LoggerType type) {
        switch (type) {
            case LoggerType::Console:
                return std::make_unique<ConsoleLogger>();
            case LoggerType::File:
                return std::make_unique<FileLogger>();
            default:
                return nullptr;
        }
    }
};
/*
Phân tích ưu điểm:
1. Mở rộng dễ dàng:
Thêm kiểu logger mới (ví dụ: DatabaseLogger) chỉ cần:
Tạo lớp con DatabaseLogger kế thừa Logger.
Thêm trường hợp mới vào CreateLogger.

2. Sử dụng linh hoạt:
LoggerFactory giúp tạo đối tượng phù hợp mà không cần người dùng quan tâm đến logic khởi tạo cụ thể.

3. Quản lý tài nguyên hiệu quả:
Sử dụng std::unique_ptr đảm bảo việc giải phóng tài nguyên tự động
*/