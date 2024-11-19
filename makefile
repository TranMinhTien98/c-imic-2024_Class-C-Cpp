CXX = g++
CXXFLAGS = -Wall -g
INCDIR = -I./inc

SRC = src/exercise123linkList.cpp \
	  src/exercise4singletonPattern.cpp \
	  main.cpp

OBJ = obj/exercise123linkList.o \
	  obj/exercise4singletonPattern.o \
	  obj/main.o

TARGET = Run

# Quy tắc build tất cả
all: obj $(TARGET)

# Biên dịch các file .cpp thành .o
obj/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) $(INCDIR) -c $< -o $@

obj/main.o: main.cpp
	$(CXX) $(CXXFLAGS) $(INCDIR) -c $< -o $@

# Liên kết các file .o thành file thực thi
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Clean up: Xóa các file đối tượng và file thực thi
clean:
	rm -f $(OBJ) $(TARGET)

# Tạo thư mục obj nếu chưa có
obj:
	mkdir obj

# Phục hồi các thư mục con (nếu cần)
.PHONY: clean all