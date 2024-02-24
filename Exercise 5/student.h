#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <vector>
#include <string>

using namespace std;

struct Student {
  public:
  Student();
    Student (int id, string name, int midterm, int final_exam, vector<int> & hw_grades);
    int get_id() { return id; };
    string get_name() { return name; };
    int get_final_exam() { return final_exam; }
    int get_midterm() { return midterm; }
    vector<int> & get_hw_grades() {return hw_grades; }

    double get_total_class_score() const {
        return 0.3 * midterm + 0.3 * final_exam + 0.4 * calculate_average_hw();
    }

  private:  
    int id;
    string name;
    int final_exam;
    int midterm;
    vector<int> hw_grades;

    double calculate_average_hw() const {
        if (hw_grades.empty()) {
            return 0.0; 
        }

        double sum_hw = 0.0;
        for (int hw : hw_grades) {
            sum_hw += hw;
        }

        return sum_hw / hw_grades.size();
    }
};

Student get_a_student();
void print_student(Student s);

#endif