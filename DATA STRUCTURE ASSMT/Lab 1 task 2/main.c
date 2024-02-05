#include <iostream>
#include <string>

const int MAX_STUDENTS = 40;

// Define the Course structure
struct Course {
    std::string course_code;
    std::string course_name;
};

// Define the Grade structure
struct Grade {
    int mark;
    char the_grade;
};

// Define the Student structure
struct Student {
    std::string registration_number;
    std::string name;
    int age;
    Course course;
    Grade grade;
};

// Function to calculate grade based on mark
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

int main() {
    // Array to store students
    Student students[MAX_STUDENTS];

    int studentCount = 0;

    // i) Add at most 40 students
    for (int i = 0; i < MAX_STUDENTS; i++) {
        // Assuming the user provides input for each field
        std::cout << "Enter details for student #" << i + 1 << ":\n";

        std::cout << "Registration Number: ";
        std::cin >> students[i].registration_number;

        std::cout << "Name: ";
        std::cin.ignore();
        std::getline(std::cin, students[i].name);

        std::cout << "Age: ";
        std::cin >> students[i].age;

        std::cout << "Course Code: ";
        std::cin >> students[i].course.course_code;

        std::cout << "Course Name: ";
        std::cin.ignore();
        std::getline(std::cin, students[i].course.course_name);

        // Initialize grade to mark of -1 to indicate not calculated yet
        students[i].grade.mark = -1;

        // Increment the student count
        studentCount++;

        char choice;
        std::cout << "Do you want to add more students? (y/n): ";
        std::cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    // ii) Edit a student’s details
    // For simplicity, you can prompt the user for the index to edit
    int indexToEdit;
    std::cout << "Enter the index of the student to edit (0 to " << studentCount - 1 << "): ";
    std::cin >> indexToEdit;

    if (indexToEdit >= 0 && indexToEdit < studentCount) {
        std::cout << "Enter updated details for student #" << indexToEdit + 1 << ":\n";

        std::cout << "Registration Number: ";
        std::cin >> students[indexToEdit].registration_number;

        std::cout << "Name: ";
        std::cin.ignore();
        std::getline(std::cin, students[indexToEdit].name);

        std::cout << "Age: ";
        std::cin >> students[indexToEdit].age;

        std::cout << "Course Code: ";
        std::cin >> students[indexToEdit].course.course_code;

        std::cout << "Course Name: ";
        std::cin.ignore();
        std::getline(std::cin, students[indexToEdit].course.course_name);
    } else {
        std::cout << "Invalid index.\n";
    }

    // iii) Add marks and calculate grades
    int markToAdd;
    std::cout << "Enter mark for a student to calculate grade: ";
    std::cin >> markToAdd;

    // Assuming you have a function to calculate the grade
    char calculatedGrade = calculateGrade(markToAdd);

    // Update the student's grade
    students[indexToEdit].grade.mark = markToAdd;
    students[indexToEdit].grade.the_grade = calculatedGrade;

    // iv) Ensure the grades, once calculated, cannot be altered
    // (You can add additional checks as needed)

    // Display information for all students
    std::cout << "\nStudent Details:\n";
    for (int i = 0; i < studentCount; i++) {
        std::cout << "Student #" << i + 1 << ":\n";
        std::cout << "Registration Number: " << students[i].registration_number << "\n";
        std::cout << "Name: " << students[i].name << "\n";
        std::cout << "Age: " << students[i].age << "\n";
        std::cout << "Course Code: " << students[i].course.course_code << "\n";
        std::cout << "Course Name: " << students[i].course.course_name << "\n";

        // Display the grade if calculated
        if (students[i].grade.mark != -1) {
            std::cout << "Grade: " << students[i].grade.the_grade << "\n";
        }

        std::cout << "\n";
    }

    return 0;
}
