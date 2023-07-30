#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Student {
    long long id;
    std::string name;
    std::string department;
    std::string email;
    char gender;
    int age;
    float cgpa;
};

std::vector<Student> students;

void addStudent() {
    Student newStudent;
    std::cout << "Enter student ID: ";
    std::cin >> newStudent.id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter student name: ";
    std::getline(std::cin, newStudent.name);

    std::cout << "Enter student department: ";
    std::getline(std::cin, newStudent.department);

    std::cout << "Enter student email ID: ";
    std::getline(std::cin, newStudent.email);

    std::cout << "Enter student gender (M/F): ";
    std::cin >> newStudent.gender;

    std::cout << "Enter student age: ";
    std::cin >> newStudent.age;

    std::cout << "Enter student CGPA: ";
    std::cin >> newStudent.cgpa;
    
    students.push_back(newStudent);
    std::cout << "\nStudent added successfully!\n" << std::endl;
}

void displayStudent(const Student& student) {
    std::cout << "ID: " << student.id << std::endl;
    std::cout << "Name: " << student.name << std::endl;
    std::cout << "Department: " << student.department << std::endl;
    std::cout << "Email: " << student.email << std::endl;
    std::cout << "Gender: " << student.gender << std::endl;
    std::cout << "Age: " << student.age << std::endl;
    std::cout << "CGPA: " << student.cgpa << std::endl;
    std::cout << "--------------------------------" << std::endl;
}

void displayAllStudents() {
    if (students.empty()) {
        std::cout << "\nNo students found.\n" << std::endl;
        return;
    }

    std::cout << "\nDisplaying Student Records!!\n" << std::endl;
    for (const Student& student : students) {
        displayStudent(student);
    }
}

void deleteStudent(long long id) {
    auto it = std::find_if(students.begin(), students.end(), [id](const Student& student) {
        return student.id == id;
    });

    if (it != students.end()) {
        students.erase(it);
        std::cout << "\nStudent with ID " << id << " deleted successfully!\n" << std::endl;
    } else {
        std::cout << "\nStudent with ID " << id << " not found.\n" << std::endl;
    }
}

void searchStudent(long long id) {
    auto it = std::find_if(students.begin(), students.end(), [id](const Student& student) {
        return student.id == id;
    });

    if (it != students.end()) {
        std::cout << "\nStudent Found\n" << std::endl;
        displayStudent(*it);
    } else {
        std::cout << "\nStudent with ID " << id << " not found.\n" << std::endl;
    }
}

int main() {
    int choice;
	std::cout << "\n\t\t\t***STUDENT RECORD MANAGEMENT SYSTEM***\n\n" << std::endl;

    do {
        std::cout << "1. Add Student\n"
                  << "2. Display All Students\n"
                  << "3. Delete Student\n"
                  << "4. Search Student\n"
                  << "5. Exit\n"
                  << "\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayAllStudents();
                break;
            case 3:
                long long deleteId;
                std::cout << "\nEnter student ID to delete: ";
                std::cin >> deleteId;
                deleteStudent(deleteId);
                break;
            case 4:
                long long searchId;
                std::cout << "\nEnter student ID to search: ";
                std::cin >> searchId;
                searchStudent(searchId);
                break;
            case 5:
                std::cout << "\nExiting program..." << std::endl;
                break;
            default:
                std::cout << "\nInvalid choice. Please try again." << std::endl;
        }

    } while (choice != 5);

    return 0;
}
