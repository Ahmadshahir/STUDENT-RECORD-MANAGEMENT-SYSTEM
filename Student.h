#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
public:
    Student(const std::string& name, int grade)
        : _name(name), _grade(grade) {}

    const std::string& getName() const { return _name; }
    int getGrade() const { return _grade; }

    void setName(const std::string& name) { _name = name; }
    void setGrade(int grade) { _grade = grade; }

private:
    std::string _name;
    int _grade;
};

#endif // STUDENT_H
