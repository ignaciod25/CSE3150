#include <iostream>
#include <fstream>

using namespace std;

#include "student.h"

Student::Student() {};

Student::Student (int id, string name, int midterm, int final_exam, vector<int> & hw_grades) 
    : id(id), name(name), midterm(midterm), final_exam(final_exam), hw_grades(hw_grades) {

};


Student get_a_student() {
    string name = "John Doe";
    vector<int> hws = {90,100,80,100};
    Student student( 1010, name, 89, 90, hws );

    return student;
}

void print_student(Student student) {

    cout << "ID: "
         << student.get_id() << endl;
    cout << "Name: "
         << student.get_name() << endl;
    cout << "Midtern: "
         << student.get_midterm() 
         << endl;
    cout << "Final: "
         <<student.get_final_exam() << endl;
    cout << "Homeworks: " << endl;

    for (auto hw : student.get_hw_grades() ) {
        cout << hw << " ";
    }
    cout << endl;

    // class total score calculation:
    double total_score = 0.3 * student.get_midterm() + 0.3 * student.get_final_exam();


    double sum_hw = 0.0;
    for (auto hw : student.get_hw_grades()) {
        sum_hw += hw;
    }

    total_score += 0.4 * (sum_hw / student.get_hw_grades().size());

    cout << "Total Class Score: " << total_score << endl;

}