
# Library Management System

## Overview

The Library Management System is a C++ program designed to automate library operations, providing features for both students and administrators. The system allows users to register, log in, and perform various library-related tasks, including book issuing, returning, and administrative book management.

## Features

### Student Operations
1. **Registration:** Students can register with a unique ID, name, and password.
2. **Login:** Registered students can log in for personalized access to library services.
3. **Book Issuing and Returning:** Efficient book issuing and returning functionality for students.

### Admin Operations
1. **Registration:** Admins can register with a unique ID, name, and password.
2. **Login:** Admins can log in for access to administrative functionalities.
3. **Book Management:** Admins can view, add, and search for books, simplifying library inventory management.

## File Structure

- [`Library.cpp`](Library.cpp): Main C++ source code file for the Library Management System.
- [`books.txt`](books.txt): Text file storing book information.
- [`students.txt`](students.txt): Text file storing student information.
- [`admins.txt`](admins.txt): Text file storing admin information.
- [`bookIssues.txt`](bookIssues.txt): Text file storing book issuance information.

## Getting Started

1. Clone the repository:

    ```bash
    git clone https://github.com/ashishkr375/Library_management_system.git
    ```

2. Compile the program:

    ```bash
    g++ Library.cpp -o library_system
    ```

3. Run the executable:

    ```bash
    ./library_system
    ```

## Contributing

Contributions are welcome! Feel free to open issues, provide feedback, or submit pull requests to enhance the project.

## License

This project is licensed under the [MIT License](LICENSE).

