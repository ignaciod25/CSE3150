#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "student.h"

TEST_CASE("Student") {
    SUBCASE("Edge cases") {
        Student student;
        CHECK(0 == student.get_hw_grades().size());

        Student student_1 = get_a_student();
        string name = student_1.get_name();
        CHECK(4 == student_1.get_hw_grades().size());
        CHECK(name == student_1.get_name());
    };

    SUBCASE("Small cases") {
        string name = "Grace Hopper";
        vector<int> hws = { 99, 98, 100, 100 };
        Student student(99999, name, 100, 99, hws);

        CHECK(student.get_name() == name);
        int i = 0;
        for (auto hw : student.get_hw_grades()) {
            CHECK(hws[i++] == hw);
        }
    };
}

TEST_CASE("Total Class Score Calculation") {
    string name = "Alan Turing";
    vector<int> hws = { 95, 90, 92, 88 };
    Student student(12345, name, 88, 90, hws);

    double expected_total_score = 0.3 * 88 + 0.3 * 90 + 0.4 * (95 + 90 + 92 + 88) / 4;

    CHECK(student.get_total_class_score() == doctest::Approx(expected_total_score));
}

TEST_CASE("Empty Homeworks") {
    string name = "Ada Lovelace";
    vector<int> hws;  
    Student student(54321, name, 85, 92, hws);

    double expected_total_score = 0.3 * 85 + 0.3 * 92;

    CHECK(student.get_total_class_score() == doctest::Approx(expected_total_score));
}

TEST_CASE("All Zeros Homeworks") {
    string name = "Nikola Tesla";
    vector<int> hws(5, 0);  
    Student student(67890, name, 95, 88, hws);

    double expected_total_score = 0.3 * 95 + 0.3 * 88;

    CHECK(student.get_total_class_score() == doctest::Approx(expected_total_score));
}

TEST_CASE("Mixed Homeworks") {
    string name = "Marie Curie";
    vector<int> hws = { 85, 90, 95, 100 }; 
    Student student(13579, name, 92, 88, hws);

    double expected_total_score = 0.3 * 92 + 0.3 * 88 + 0.4 * (85 + 90 + 95 + 100) / 4;

    CHECK(student.get_total_class_score() == doctest::Approx(expected_total_score));
}

TEST_CASE("High Scores") {
    string name = "Albert Einstein";
    vector<int> hws = { 100, 100, 100, 100 };  
    Student student(24680, name, 95, 98, hws);

    double expected_total_score = 0.3 * 95 + 0.3 * 98 + 0.4 * (100 + 100 + 100 + 100) / 4;

    CHECK(student.get_total_class_score() == doctest::Approx(expected_total_score));
}

TEST_CASE("Low Scores") {
    string name = "Isaac Newton";
    vector<int> hws = { 60, 65, 70, 75 };  
    Student student(36912, name, 80, 75, hws);

    double expected_total_score = 0.3 * 80 + 0.3 * 75 + 0.4 * (60 + 65 + 70 + 75) / 4;

    CHECK(student.get_total_class_score() == doctest::Approx(expected_total_score));
}

TEST_CASE("Varying Scores") {
    string name = "Galileo Galilei";
    vector<int> hws = { 88, 92, 78, 85 };  
    Student student(98765, name, 85, 90, hws);

    double expected_total_score = 0.3 * 85 + 0.3 * 90 + 0.4 * (88 + 92 + 78 + 85) / 4;

    CHECK(student.get_total_class_score() == doctest::Approx(expected_total_score));
}
