/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 10th March 2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <iomanip>
#include <string>
#include "Student.h"

using namespace std;

namespace seneca {

    Student::Student(std::istream& in) {
        string str{};
        getline(in, str, ',');
        m_name = trim(str, " ");
        getline(in, str, ',');
        m_age = trim(str, " ");
        try {
            stoi(m_age);
        } catch (std::invalid_argument&) {
            in.ignore(1000, '\n');
            throw(m_name + "++Invalid record!");
        }
        getline(in, str, ',');
        m_id = trim(str, " ");
        if (m_id[0] != 'S') {
            in.ignore(1000, '\n');
            throw(m_name + "++Invalid record!");
        }
        getline(in, str, ',');
        m_count = stoi(str);
        if (m_count) {
            m_courses = new string[m_count];
            for (int i = 0; i < m_count - 1; ++i) {
                getline(in, str, ',');
                m_courses[i] = trim(str, " ");
            }
            getline(in, str, '\n');
            m_courses[m_count - 1] = trim(str, " ");
        }
    }

    std::string Student::status() const {
        return "Student";
    }
    std::string Student::name() const {
        return m_name;
    }
    std::string Student::age() const {
        return m_age;
    }
    std::string Student::id() const {
        return m_id;
    }

    void Student::display(std::ostream& out) const {
        out << "| " << setw(10) << status() << "| " << setw(10) << m_id << "| " << setw(20) << m_name << " | " << setw(3) << m_age << " |";
        for (int i = 0; i < m_count; ++i) {
            out << m_courses[i];
            if (i != m_count - 1) out << ", ";
        }
    }

    Student::~Student() {
        delete[] m_courses;
    }
}