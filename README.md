# Mastering Pointers in C++: A Complete Guide

## 📌 About This Series
This series is a deep dive into **pointers in C++**, covering everything from **raw pointers** to **smart pointers**, including memory management pitfalls and best practices. 

By the end of this series, you'll have a **full understanding of pointers**, how they work under the hood, and when to use them effectively.

## Watch the Series
**YouTube Playlist:** [Mastering Pointers in C++](https://www.youtube.com/playlist?list=PLo5QxxWWNpBhhi0zke-O5QKYJnMUNxsDE)

---

## 📂 Series Breakdown
### **1️⃣ Understanding Memory and Raw Pointers**
📌 **Overview:**  
- Introduction to **memory regions**: Stack and Heap.  
- What are **pointers** and how they work?  
- When to use and when **not to use** raw pointers.  

---

### **2️⃣ Implementing Raw Pointers**
📌 **Overview:**  
- Practical use cases of raw pointers.  
- Working with **stack, heap, function, and array pointers**.  

📌 **Files in `part_2_raw_pointers/src/`**
- `i1_stack.cpp` → Pointers to stack variables. 
- `i2_heap.cpp` → Dynamic memory allocation (`new` & `delete`) .
- `i3_function.cpp` → Function pointers & callback functions. 
- `i4_array.cpp` → Pointer arithmetic & arrays.
- `i5_npc_example.cpp` → An example involving an NPC character.
- `i6_real_world_simulate.cpp` → A real world simulation example involving hardware registers.

---

### **3️⃣ Common Pitfalls and Exceptions**
📌 **Overview:**  
- Common **errors and pitfalls** when using raw pointers.  
- Examples of **undefined behavior**, **memory leaks**, and **segmentation faults**.  

📌 **Files in `part_3_pitfalls/src/`**
- `i1_uninitialized_pointer.cpp`
- `i2_nullptr_dereference.cpp`
- `i3_returning_stack_pointer.cpp`
- `i4_memory_leak.cpp`
- `i5_dangling_pointer.cpp`
- `i6_double_delete.cpp`
- `i7_stack_pointer_delete.cpp`
- `i8_mismatched_delete.cpp`
- `i9_pointer_arithmetic.cpp`

---

### **4️⃣ Smart Pointers, RAII and Implementing Smart Pointers**
📌 **Overview:**  
- Why **raw pointers should be avoided** in modern C++.  
- Understanding **RAII (Resource Acquisition Is Initialization)**.  
- Deep dive into **`std::unique_ptr`, `std::shared_ptr`, and `std::weak_ptr`**. 
- Implementation examples. 

---

## License

Ghost The Engineer - [license](/LICENSE)
