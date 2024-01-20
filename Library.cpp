#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

class Book {
public:
    std::string bookID;
    std::string bookName;

    Book(const std::string& id, const std::string& name) : bookID(id), bookName(name) {}
};
class Admin {
public:
    std::string adminID;
    std::string adminName;
    std::string password;

    Admin(const std::string& id, const std::string& name, const std::string& pwd)
        : adminID(id), adminName(name), password(pwd) {}
};
class Student {
public:
    std::string studentID;
    std::string studentName;
    std::string password;

    Student(const std::string& id, const std::string& name, const std::string& pwd)
        : studentID(id), studentName(name), password(pwd) {}
};
class BookIssue {
public:
    std::string studentID;
    std::string bookID;
    std::string issueDate;

    BookIssue(const std::string& studentID, const std::string& bookID, const std::string& date)
        : studentID(studentID), bookID(bookID), issueDate(date) {}
};
class LibrarySystem {
private:
    std::vector<Book> books;
    std::vector<Student> students;
    std::vector<Admin> admins;
    std::vector<BookIssue> bookIssues;
    const std::string booksFile = "books.txt";
    const std::string studentsFile = "students.txt";
    const std::string adminsFile = "admins.txt";

public:
    LibrarySystem() {
        loadBooks();
        loadStudents();
        loadAdmins();
        loadBookIssues(); 
    }

    void showMenu() {
        std::cout << "1. Student Side\n";
        std::cout << "2. Admin Side\n";
        std::cout << "3. Quit\n";
    }

    void processChoice() {
        int choice;
        do {
            showMenu();
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    studentMenu();
                    break;
                case 2:
                    adminMenu();
                    break;
                case 3:
                    std::cout << "Goodbye!\n";
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 3);
    }

private:
    void studentMenu() {
        std::cout << "1. Register\n";
        std::cout << "2. Login\n";
        std::cout << "3. Issue Book\n";
        std::cout << "4. Return Book\n";
        std::cout << "5. Back to Main Menu\n";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                registerStudent();
                break;
            case 2:
                studentLogin();
                break;
            case 3:
                issueBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    void adminMenu() {
        std::cout << "1. Register\n";
        std::cout << "2. Login\n";
        std::cout << "3. See Books Data\n";
        std::cout << "4. Add New Book\n";
        std::cout << "5. Search Book\n";
        std::cout << "6. Back to Main Menu\n";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                registerAdmin();
                break;
            case 2:
                adminLogin();
                break;
            case 3:
                displayBooks();
                break;
            case 4:
                addNewBook();
                break;
            case 5:
                searchBook();
                break;
            case 6:
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    void registerStudent() {
        std::string id, name, password;
        std::cout << "Enter Student ID: ";
        std::cin >> id;
        std::cout << "Enter Student Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Enter Password: ";
        std::cin >> password;

        students.emplace_back(id, name, password);
        saveStudents();
        std::cout << "Registration successful!\n";
    }

    void studentLogin() {
        std::string id, password;
        std::cout << "Enter Student ID: ";
        std::cin >> id;
        std::cout << "Enter Password: ";
        std::cin >> password;

        auto it = std::find_if(students.begin(), students.end(), [&id, &password](const Student& s) {
            return s.studentID == id && s.password == password;
        });

        if (it != students.end()) {
            std::cout << "Login successful, " << it->studentName << "!\n";
        } else {
            std::cout << "Invalid Student ID or Password. Please try again.\n";
        }
    }



  void registerAdmin() {
        std::string id, name, password;
        std::cout << "Enter Admin ID: ";
        std::cin >> id;
        std::cout << "Enter Admin Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Enter Password: ";
        std::cin >> password;

        admins.emplace_back(id, name, password);
        saveAdmins();
        std::cout << "Admin registration successful!\n";
    }

 void adminLogin() {
    std::string id, password;
    std::cout << "Enter Admin ID: ";
    std::cin >> id;
    std::cout << "Enter Password: ";
    std::cin >> password;

    auto it = std::find_if(admins.begin(), admins.end(), [&id, &password](const Admin& a) {
        return a.adminID == id && a.password == password;
    });

    if (it != admins.end()) {
        std::cout << "Login successful, " << it->adminName << "!\n";
        adminMenu(); 
    } else {
        std::cout << "Invalid Admin ID or Password. Please try again.\n";
    }
}

    void displayBooks() {
        std::cout << "Books Data:\n";
        for (const auto& book : books) {
            std::cout << "Book ID: " << book.bookID << "\tBook Name: " << book.bookName << std::endl;
        }
    }

    void addNewBook() {
        std::string bookID, bookName;
        std::cout << "Enter Book ID: ";
        std::cin >> bookID;

      
        auto it = std::find_if(books.begin(), books.end(), [&bookID](const Book& b) {
            return b.bookID == bookID;
        });

        if (it != books.end()) {
            std::cout << "Book with ID " << bookID << " already exists. Please choose a different ID.\n";
            return;
        }

        std::cout << "Enter Book Name: ";
        std::cin.ignore();
        std::getline(std::cin, bookName);

        books.emplace_back(bookID, bookName);
        saveBooks();
        std::cout << "Book added successfully!\n";
    }

void searchBook() {
    std::string bookID;
    std::cout << "Enter Book ID: ";
    std::cin >> bookID;

    auto it = std::find_if(books.begin(), books.end(), [&bookID](const Book& b) {
        return b.bookID == bookID;
    });

    if (it != books.end()) {
        std::cout << "Book found!\n";
         displayBooks(*it); 
    } else {
        std::cout << "Book not found.\n";
    }
}

    void loadBooks() {
        std::ifstream file(booksFile);

        if (!file.is_open()) {
            return;
        }

        std::string bookID, bookName;
        while (file >> bookID >> bookName) {
            books.emplace_back(bookID, bookName);
        }

        file.close();
    }

    void saveBooks() {
        std::ofstream file(booksFile);

        if (!file.is_open()) {
            std::cerr << "Error opening file for writing: " << booksFile << std::endl;
            return;
        }

        for (const auto& book : books) {
            file << book.bookID << " " << book.bookName << std::endl;
        }

        file.close();
    }
	void saveAdmins() {
        std::ofstream file(adminsFile);

        if (!file.is_open()) {
            std::cerr << "Error opening file for writing: " << adminsFile << std::endl;
            return;
        }

        for (const auto& admin : admins) {
            file << admin.adminID << " " << admin.adminName << " " << admin.password << std::endl;
        }

        file.close();
    }

    void loadAdmins() {
        std::ifstream file(adminsFile);

        if (!file.is_open()) {
            return;
        }

        std::string adminID, adminName, password;
        while (file >> adminID >> adminName >> password) {
            admins.emplace_back(adminID, adminName, password);
        }

        file.close();
    }
    void loadStudents() {
        std::ifstream file(studentsFile);

        if (!file.is_open()) {
            return;
        }

        std::string studentID, studentName, password;
        while (file >> studentID >> studentName >> password) {
            students.emplace_back(studentID, studentName, password);
        }

        file.close();
    }

    void saveStudents() {
        std::ofstream file(studentsFile);

        if (!file.is_open()) {
            std::cerr << "Error opening file for writing: " << studentsFile << std::endl;
            return;
        }

        for (const auto& student : students) {
            file << student.studentID << " " << student.studentName << " " << student.password << std::endl;
        }

        file.close();
    }

void issueBook() {
        std::string studentID, bookID, date;
        std::cout << "Enter Student ID: ";
        std::cin >> studentID;
        std::cout << "Enter Book ID: ";
        std::cin >> bookID;
        std::cout << "Enter Issue Date: ";
        std::cin >> date;

        auto studentIt = std::find_if(students.begin(), students.end(), [&studentID](const Student& s) {
            return s.studentID == studentID;
        });

        auto bookIt = std::find_if(books.begin(), books.end(), [&bookID](const Book& b) {
            return b.bookID == bookID;
        });

        if (studentIt != students.end() && bookIt != books.end()) {
            bookIssues.emplace_back(studentID, bookID, date);
            std::cout << "Book '" << bookIt->bookName << "' issued to student '" << studentIt->studentName << "' on " << date << ".\n";
            saveBookIssues(); // Added to save book issuance information
        } else {
            std::cout << "Invalid student ID or book ID. Please try again.\n";
        }
    }

    void returnBook() {
        std::string studentID, bookID;
        std::cout << "Enter Student ID: ";
        std::cin >> studentID;
        std::cout << "Enter Book ID: ";
        std::cin >> bookID;

        auto studentIt = std::find_if(students.begin(), students.end(), [&studentID](const Student& s) {
            return s.studentID == studentID;
        });

        auto bookIt = std::find_if(books.begin(), books.end(), [&bookID](const Book& b) {
            return b.bookID == bookID;
        });

        if (studentIt != students.end() && bookIt != books.end()) {
            auto issuedBookIt = std::find_if(bookIssues.begin(), bookIssues.end(), [&bookID, &studentID](const BookIssue& issue) {
                return issue.bookID == bookID && issue.studentID == studentID;
            });

            if (issuedBookIt != bookIssues.end()) {
                std::cout << "Book '" << bookIt->bookName << "' returned by student '" << studentIt->studentName << "'.\n";
                bookIssues.erase(issuedBookIt);
                saveBookIssues(); // Added to save book issuance information
            } else {
                std::cout << "Book not currently issued to the specified student.\n";
            }
        } else {
            std::cout << "Invalid student ID or book ID. Please try again.\n";
        }
    }
    void saveBookIssues() {
        std::ofstream file("bookIssues.txt");

        if (!file.is_open()) {
            std::cerr << "Error opening file for writing: bookIssues.txt\n";
            return;
        }

        for (const auto& issue : bookIssues) {
            file << issue.studentID << " " << issue.bookID << " " << issue.issueDate << std::endl;
        }

        file.close();
    }

    void loadBookIssues() {
        std::ifstream file("bookIssues.txt");

        if (!file.is_open()) {
            return;
        }

        std::string studentID, bookID, issueDate;
        while (file >> studentID >> bookID >> issueDate) {
            bookIssues.emplace_back(studentID, bookID, issueDate);
        }

        file.close();
    }
   

void displayBooks(const Book& book) {
    std::cout << "Book ID: " << book.bookID << "\tBook Name: " << book.bookName << std::endl;
}



};

int main() {
    LibrarySystem librarySystem;
    librarySystem.processChoice();

    return 0;
}

