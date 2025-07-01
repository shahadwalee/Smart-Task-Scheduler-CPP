# Smart Task Scheduler - C++ Console Application

---

## Overview
This project is a simple, console-based Smart Task Scheduler developed using C++. It allows users to manage their daily tasks efficiently with functionalities like adding, viewing, marking as complete, and deleting tasks. The system uses a text file (tasks.txt) for persistent data storage, ensuring that task information is saved and loaded across sessions.

### نظرة عامة
هذا المشروع هو نظام بسيط لإدارة المهام الذكي، تم تطويره باستخدام لغة C++. يسمح للمستخدمين بإدارة مهامهم اليومية بكفاءة مع وظائف مثل إضافة المهام وعرضها وتحديد المكتمل منها وحذفها. يستخدم النظام ملفًا نصيًا (tasks.txt) لتخزين البيانات بشكل دائم، مما يضمن حفظ وتحميل معلومات المهام عبر الجلسات.

---

## Key Features
* **Comprehensive Task Management:**
    * **Add New Task:** Easily add new tasks with a description, due date, and priority level.
    * **Mark as Completed:** Update the status of tasks once they are finished.
    * **Delete Task:** Remove tasks from your list.
* **Intelligent Task Display:**
    * **Prioritized View:** Tasks are displayed sorted by priority (High, Medium, Low) and then by due date (earliest first).
    * **Status Indicators:** Tasks are clearly marked as Completed, Overdue, Urgent (due within 3 days), or Pending.
    * **Days Left:** See how many days are left until a task's due date.
* **Upcoming Task Visibility:**
    * Quickly view non-completed tasks that are due within the next 7 days.
* **Persistent Storage Solution:**
    * All task data is automatically saved to and loaded from a plain text file (tasks.txt), ensuring data integrity and persistence even after closing the application.
* **User-Friendly Console Interface:**
    * A simple, menu-driven interface guides users through various operations.
* **Automatic ID Generation:**
    * Each new task is assigned a unique ID automatically.

### الميزات الرئيسية
* **إدارة المهام الشاملة:**
    * **إضافة مهمة جديدة:** يمكنك بسهولة إضافة مهام جديدة بوصف وتاريخ استحقاق ومستوى أولوية.
    * **تحديد كمكتملة:** تحديث حالة المهام بمجرد الانتهاء منها.
    * **حذف مهمة:** إزالة المهام من قائمتك.
* **عرض المهام الذكي:**
    * **عرض حسب الأولوية:** يتم عرض المهام مرتبة حسب الأولوية (عالية، متوسطة، منخفضة) ثم حسب تاريخ الاستحقاق (الأقدم أولاً).
    * **مؤشرات الحالة:** يتم تمييز المهام بوضوح كـمكتملة، متأخرة، عاجلة (تستحق خلال 3 أيام)، أو معلقة.
    * **الأيام المتبقية:** اطلع على عدد الأيام المتبقية حتى تاريخ استحقاق المهمة.
* **رؤية المهام القادمة:**
    * عرض سريع للمهام غير المكتملة التي تستحق خلال الأيام السبعة القادمة.
* **حل التخزين الدائم:**
    * يتم حفظ جميع بيانات المهام تلقائيًا وتحميلها من ملف نصي عادي (tasks.txt)، مما يضمن سلامة البيانات واستمراريتها حتى بعد إغلاق التطبيق.
* **واجهة تحكم سهلة الاستخدام:**
    * واجهة قائمة بسيطة توجه المستخدمين عبر العمليات المختلفة.
* **توليد المعرف التلقائي:**
    * يتم تعيين معرف فريد لكل مهمة جديدة تلقائيًا.

---

## Technologies & Concepts Used
* **Programming Language:** C++
* **Data Structuring:** `struct` to define `Task` objects for organizing task attributes.
* **Dynamic Collections:** `std::vector` for dynamic storage and management of `Task` objects in memory.
* **File I/O:** `fstream` for reading from and writing to text files (`tasks.txt`) to maintain persistent data.
* **String Manipulation & Parsing:** `std::getline`, `std::istringstream`, and `std::get_time` for robust input handling and parsing date strings.
* **Date and Time Management:** `ctime` library functions (`time_t`, `tm`, `mktime`, `difftime`) for calculating differences between dates and identifying overdue or urgent tasks.
* **Core Operations:** Implementation of CRUD (Create, Read, Update, Delete) operations.
* **Sorting Algorithms:** `std::sort` with a custom comparison function for efficient task ordering.
* **User Experience:** Use of `iomanip` for formatted table output.

### التقنيات والمفاهيم المستخدمة
* **لغة البرمجة:** C++
* **هيكلة البيانات:** `struct` لتعريف كائنات `Task` لتنظيم سمات المهمة.
* **المجموعات الديناميكية:** `std::vector` للتخزين الديناميكي وإدارة كائنات `Task` في الذاكرة.
* **إدخال/إخراج الملفات (File I/O):** `fstream` للقراءة والكتابة من وإلى الملفات النصية (`tasks.txt`) للحفاظ على البيانات الدائمة.
* **معالجة النصوص والتحليل (String Manipulation & Parsing):** `std::getline`، `std::istringstream`، و `std::get_time` للتعامل القوي مع المدخلات وتحليل سلاسل التاريخ.
* **إدارة التاريخ والوقت:** دوال مكتبة `ctime` (`time_t`, `tm`, `mktime`, `difftime`) لحساب الفروق بين التواريخ وتحديد المهام المتأخرة أو العاجلة.
* **العمليات الأساسية:** تطبيق عمليات CRUD (إنشاء، قراءة، تحديث، حذف).
* **خوارزميات الفرز:** `std::sort` مع دالة مقارنة مخصصة لترتيب المهام بكفاءة.
* **تجربة المستخدم:** استخدام `iomanip` لإخراج الجداول المنسقة.

---

## How It Works
The application operates through a main menu from which users can select various operations.
* **Data Loading:** Upon startup, the system attempts to load existing task records from `tasks.txt` into an `std::vector<Task>` in memory.
* **User Interaction:** Users interact with the system via console input, choosing options like adding, listing, marking as completed, or deleting tasks.
* **Data Management:** All operations are performed on the `Task` objects stored in the `std::vector`.
* **Persistent Saving:** After each significant change (add, mark completed, delete), the updated `std::vector` is saved back to `tasks.txt`, overwriting the previous content to ensure all changes are permanently stored.

### كيفية عمل البرنامج
يعمل التطبيق من خلال قائمة رئيسية يمكن للمستخدمين من خلالها اختيار عمليات مختلفة.
* **تحميل البيانات:** عند بدء التشغيل، يحاول النظام تحميل سجلات المهام الموجودة من `tasks.txt` إلى `std::vector<Task>` في الذاكرة.
* **تفاعل المستخدم:** يتفاعل المستخدمون مع النظام عبر إدخال الأوامر في شاشة الأوامر، واختيار خيارات مثل إضافة المهام، عرضها، تحديد المكتمل منها، أو حذفها.
* **إدارة البيانات:** يتم تنفيذ جميع العمليات على كائنات `Task` المخزنة في `std::vector`.
* **الحفظ الدائم:** بعد كل تغيير مهم (إضافة، تحديد كمكتملة، حذف)، يتم حفظ `std::vector` المحدّث مرة أخرى في `tasks.txt`، ليحل محل المحتوى السابق لضمان تخزين جميع التغييرات بشكل دائم.

---

## Setup and Run
To set up and run this project locally:

1.  **Save the code:** Save the provided C++ code into a file named `smart_task_scheduler.cpp`.
2.  **Compile the code:**
    * **Using g++ (MinGW/Linux):**
        Open your terminal or command prompt, navigate to the directory where you saved the file, and run:
        ```bash
        g++ smart_task_scheduler.cpp -o smart_task_scheduler
        ```
        (Make sure you have g++ installed on your system).
    * **Using Visual Studio:**
        Create a new C++ Console Application project in Visual Studio. Add the `smart_task_scheduler.cpp` file to your project. Then, build the solution.
3.  **Run the executable:**
    * **From Terminal (g++):**
        ```bash
        ./smart_task_scheduler # On Linux/macOS
        smart_task_scheduler.exe # On Windows
        ```
    * **From Visual Studio:**
        Run the compiled executable directly from the Debug/Release folder, or use Visual Studio's Run button (usually F5).

---

## Screenshots (لقطات شاشة)
Here are visual demonstrations of the Smart Task Scheduler in action:

### 1. Main Menu
![Main Menu](https://raw.githubusercontent.com/shahadwalee/Smart-Task-Scheduler-CPP/main/ALLScreenshots/Main_Menu.png)

### 2. Add Task
![Add Task](https://raw.githubusercontent.com/shahadwalee/Smart-Task-Scheduler-CPP/main/ALLScreenshots/Add_Task.png)

### 3. Show All Tasks
![Show All Tasks](https://raw.githubusercontent.com/shahadwalee/Smart-Task-Scheduler-CPP/main/ALLScreenshots/Show_All.png)

### 4. Show Upcoming Tasks
![Show Upcoming Tasks](https://raw.githubusercontent.com/shahadwalee/Smart-Task-Scheduler-CPP/main/ALLScreenshots/Show_Tasks.png)

### 5. Mark Task
![Mark Task](https://raw.githubusercontent.com/shahadwalee/Smart-Task-Scheduler-CPP/main/ALLScreenshots/Mark_Task.png)

### 6. Delete Task
![Delete Task](https://raw.githubusercontent.com/shahadwalee/Smart-Task-Scheduler-CPP/main/ALLScreenshots/Delete_Task.png)
