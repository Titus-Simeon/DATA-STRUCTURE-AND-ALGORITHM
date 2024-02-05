#include <iostream>
#include <string>

class Course {
public:
    std::string course_code;
    std::string course_name;
};

class Grade {
public:
    int mark;
    char the_grade;

    // Constructor to initialize Grade object
    Grade(int m) : mark(m), the_grade(calculateGrade(mark)) {}

private:
    char calculateGrade(int mark) {
        if (mark > 69) {
            return 'A';
        } else if (mark > 59) {
            return 'B';
        } else if (mark > 49) {
            return 'C';
        } else if (mark > 39) {
            return 'D';
        } else {
            return 'E';
        }
    }
};

class Student {
public:
    std::string registration_number;
    std::string name;
    int age;
    Course course;
    Grade grade;

    // Constructor to initialize Student object
    Student(const std::string& reg_num, const std::string& student_name, int student_age,
            const std::string& course_code, const std::string& course_name)
        : registration_number(reg_num), name(student_name), age(student_age),
          course({course_code, course_name}), grade(-1) {}

    // Function to edit student details
    void editDetails(const std::string& new_reg_num, const std::string& new_name, int new_age,
                     const std::string& new_course_code, const std::string& new_course_name) {
        registration_number = new_reg_num;
        name = new_name;
        age = new_age;
        course.course_code = new_course_code;
        course.course_name = new_course_name;
    }

    // Function to add mark and calculate grade
    void addMark(int mark) {
        grade = Grade(mark);
    }

    // Function to display student details
    void displayDetails() const {
        std::cout << "Registration Number: " << registration_number << "\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Age: " << age << "\n";
        std::cout << "Course Code: " << course.course_code << "\n";
        std::cout << "Course Name: " << course.course_name << "\n";

        // Display the grade if calculated
        if (grade.mark != -1) {
            std::cout << "Grade: " << grade.the_grade << "\n";
        }

        std::cout << "\n";
    }
};

int main() {
    const int MAX_STUDENTS = 40;
    Student students[MAX_STUDENTS];
    int studentCount = 0;

    // Add students
    for (int i = 0; i < MAX_STUDENTS; i++) {
        std::string reg_num, student_name, course_code, course_name;
        int age;

        std::cout << "Enter details for student #" << i + 1 << ":\n";
        std::cout << "Registration Number: ";
        std::cin >> reg_num;

        std::cout << "Name: ";
        std::cin.ignore();
        std::getline(std::cin, student_name);

        std::cout << "Age: ";
        std::cin >> age;

        std::cout << "Course Code: ";
        std::cin >> course_code;

        std::cout << "Course Name: ";
        std::cin.ignore();
        std::getline(std::cin, course_name);

        students[i] = Student(reg_num, student_name, age, course_code, course_name);

        // Increment the student count
        studentCount++;

        char choice;
        std::cout << "Do you want to add more students? (y/n): ";
        std::cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    // Edit a student's details
    int indexToEdit;
    std::cout << "Enter the index of the student to edit (0 to " << studentCount - 1 << "): ";
    std::cin >> indexToEdit;

    if (indexToEdit >= 0 && indexToEdit < studentCount) {
        std::string new_reg_num, new_name, new_course_code, new_course_name;
        int new_age;

        std::cout << "Enter updated details for student #" << indexToEdit + 1 << ":\n";
        std::cout << "Registration Number: ";
        std::cin >> new_reg_num;

        std::cout << "Name: ";
        std::cin.ignore();
        std::getline(std::cin, new_name);

        std::cout << "Age: ";
        std::cin >> new_age;

        std::cout << "Course Code: ";
        std::cin >> new_course_code;

        std::cout << "Course Name: ";
        std::cin.ignore();
        std::getline(std::cin, new_course_name);

        students[indexToEdit].editDetails(new_reg_num, new_name, new_age, new_course_code, new_course_name);
    } else {
        std::cout << "Invalid index.\n";
    }

    // Add marks and calculate grades
    int markToAdd;
    std::cout << "Enter mark for a student to calculate grade: ";
    std::cin >> markToAdd;

    students[indexToEdit].addMark(markToAdd);

    // Display information for all students
    std::cout << "\nStudent Details:\n";
    for (int i = 0; i < studentCount; i++) {
        std::cout << "Student #" << i + 1 << ":\n";
        students[i].displayDetails();
    }

    return 0;
}
