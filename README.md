
# **Management System for Orders, Products, and Clients**

**Author:** Nedelcu Bianca-Nicoleta  
**Group:** 323AB  
**Operating System Used:** Windows 10  
**IDE Used:** Visual Studio Code 

---

## **Project Overview**

This project is designed to implement a management application for handling orders, products, and clients using fundamental concepts of **Object-Oriented Programming (OOP)** in C++. The system includes the following classes:

- **`Product`**: Represents the products available for purchase.
- **`Client`**: Represents the customers of the store.
- **`Order`**: Manages customer orders, including product details, order date, and additional information.

The goal of the project is to demonstrate the interaction between these classes and provide an efficient solution for managing data in a store context.

---

## **File Structure**

### **1. Header Files**
The project includes separate header files for each class:
- `Product.h`
- `Client.h`
- `Order.h`

These files contain the class definitions and method declarations.

### **2. main.cpp**
The `main.cpp` file serves as the entry point for the application. It demonstrates how the classes interact by:
- Creating instances of the classes.
- Initializing objects with relevant data.
- Manipulating orders by adding products and linking them to clients.
- Displaying information about products, clients, and orders.
- Ensuring proper memory management by freeing dynamically allocated resources.

---

## **Key Functionalities**

### **1. Product Management**
- Add and manage product details such as name and price.
- Display product information.

### **2. Client Management**
- Store client details (e.g., name, contact information).
- Manage client-specific orders.

### **3. Order Management**
- Create and manage orders for clients.
- Link products to specific orders.
- Display details about orders, including the total cost and order date.

### **4. Memory Management**
- Proper handling of dynamically allocated memory to prevent leaks and ensure program stability.

---

## **How to Run**

1. **Setup Environment**: Ensure that you have the following installed on your system:
   - Windows 10 (or compatible OS).
   - Visual Studio Code IDE with a configured GCC compiler.

2. **Build the Project**:
   - Open the project in Code::Blocks.
   - Add all `.cpp` and `.h` files to the project.
   - Build and compile the project.

3. **Run the Application**:
   - Execute the compiled program.
   - Follow the prompts to interact with the system.

---

## **Future Improvements**

- Add file I/O for saving and loading data.
- Implement a graphical user interface (GUI) for better user interaction.
- Add more advanced features such as product categories, discounts, and inventory management.

---

## **Acknowledgments**

This project was developed as part of an academic assignment for the **Object-Oriented Programming** course. Special thanks to my instructors  for their guidance and support.

