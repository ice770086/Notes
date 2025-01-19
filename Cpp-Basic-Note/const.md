# const



## 1.常量和引用

- 对常量的引用也必须为常量

  ```c++
  const int num = 10;
  const int& ref = num;
  ```



## 2.常量和指针

- 指针本身是个对象，可以是常量/变量

- 常量指针（指向常量的指针，指针内容是const，但指针是变量）

  ```c++
  const int a=1;
  const int* p=&a;//p指向a，但是不能通过p修改a
  
  int b=2;
  p=&b;//p可以指向其他
  ```

- 指针常量（指向不变，内容可变，指针内容是变量，指针是const）

  ```c++
  int a=1;
  int* const p=&a;//p只能指向a
  *p=2;//可以通过p修改a
  ```

- 指向常量的常量指针

  ```c++
  const int a=1;
  const int* const p=&a;
  ```



## 3.const形参

- 限定形参，保证整个参数不会再函数体内部被修改（仅仅使用，不做修改）

  ```c++
  #include <iostream>
  #include <string>
  
  // 函数使用 const 形参
  void printString(const std::string& str) {
      // 尝试修改 str 的值会导致编译错误
      // str = "Modified String"; 
  
      std::cout << str << std::endl;
  }
  
  // 另一个函数使用 const 形参
  void processArray(const int arr[], int size) {
      for (int i = 0; i < size; ++i) {
          // 尝试修改 arr[i] 的值会导致编译错误
          // arr[i] = i * 2; 
  
          std::cout << arr[i] << " ";
      }
      std::cout << std::endl;
  }
  
  int main() {
      std::string message = "Hello, World!";
      printString(message);
  
      int array[] = {1, 2, 3, 4, 5};
      int arraySize = sizeof(array) / sizeof(array[0]);
      processArray(array, arraySize);
      return 0;
  }
  ```




## 4.const类实例

- 实例的所有成员变量都被视为 `const`，不能被修改



## 5.前置const和后置const



- **前置 const**：对于成员变量，使其成为常量；对于函数返回值，使其返回的是常量。
- **后置 const**：用于成员函数，保证函数不会修改对象的状态，提供了对 `const` 对象的安全操作，同时可用于函数重载以区分 `const` 和非 `const` 对象的调用。



