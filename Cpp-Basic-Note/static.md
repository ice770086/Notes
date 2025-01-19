# static

## 1.在类中声明（类外初始化）——静态成员

- static成员变量/函数——属于类，可以通过类直接调用

   ```c++
   //类名直接调用
   MyClass::Func();
   ```

- static成员函数只能访问static成员变量——共享出来的管不了私有的

   ```c++
   class MyClass{
       public:
       static int a;//声明未定义
       int b;
       static void Fun1(){
           a++;
           b++;//error
       }
       static void Fun2(MyClass& obj1,MyClass* obj2){//与示例关联后可以访问
           a++;
           obj1.b++;
           obj2->b++;
       }
   };
   
   int MyClass::a=999;//static成员变量必须在类外初始化，分配空间
   ```

   

- 必须在类外初始化，除非是==const定义的整型常量或枚举常量==

   ```c++
   class MyClass {
   public:
       static const int myConstIntStaticVar = 10; // 可以在类内初始化
       enum SomeEnum { VALUE1, VALUE2 };
       static const SomeEnum myConstEnumStaticVar = VALUE1; // 可以在类内初始化
   };
   ```

   ```c++
   class MyClass {
   public:
       static const std::string myConstStringStaticVar; // 声明
   };
   // 类外初始化
   const std::string MyClass::myConstStringStaticVar = "Hello, World!";
   
   ```

   

- static成员变量在程序开始执行前（main之前）就初始化（按类外初始化顺序），生命周期为整个程序（不局限于类）

- 可跨文件使用，只要包含了相应的类声明文件





## 2.在类外声明（并初始化）——全局静态

- 声明定义在全局，把全局变量（可跨文件）==转为内部链接（仅当前文件可用）==

   ```c++
   //cpp1
   int globalVar=0;//存在静态存储区域（生命周期为整个程序）
   //cpp2
   extern int globalVar; // 声明全局变量，表明该变量在其他文件中已经定义
   ```

   

   ```c++
   ***
   static int globalStaticVar = 0;  // 全局静态变量，内部链接，无法跨文件，存在静态存储区域（生命周期为整个程序）
   ***
   ```

- 限制在当前声明它的文件中（避免命名冲突），即使在其他文件中使用 `extern` 关键字也无法访问





## 3.函数内声明——局部静态

- 作用域仅为当前函数
- 不随函数调用结束而销毁，生命周期依然是整个程序
- 由于静态变量仅在程序开始时初始化一次，后续调用函数时，静态变量会保留之前的值（静态存储区域）