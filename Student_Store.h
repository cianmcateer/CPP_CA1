#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <cctype>
#include <math.h>

#include "Student.h"


class Student_Store {

private:

    std::map<std::string,std::vector<Student> > school_data; // Local storage
    std::map<std::string,std::vector<Student> > read_file();
    std::map<std::string,std::vector<Student> > back_up_data();
    void replace_characters(Student& s, char old_char, char new_char);
    void get_count(int& i);
    bool teacher_exists(std::string teacher);
    std::string lower_case(std::string word);
    std::map<std::string,float> get_means();

    template <typename T>
    float sum(std::vector<T>& vec);

    template <typename T>
    float mean(std::vector<T>& vec);

    template <typename T>
    float st_dev(std::vector<T>& vec);

    template <typename T>
    std::vector<T> vec_minus_mean(std::vector<T>& vec);


public:
    // Constructor / Destructor
    Student_Store(); // Done
    ~Student_Store(); // Done

    void display_averages();

    void add(std::string& teacher, const Student& s);  // Done
    void clear(); // Done

    void update(std::string& teacher,int index,std::string name, int age, int attendance, float gpa, std::string comment);

    void remove_group(std::string& teacher); // Done
    void remove_student(std::string& teacher, int& index);
    std::vector<Student> get_students(); // Done
    void print(std::vector<Student>& students);
    void print_index(std::string& teacher);
    void display_group(std::string& teacher); //
    void create_group(std::string& teacher);
    void save(); // Done
    void create_webpage();
    bool is_full(std::string& teacher); // Done not implemented yet in main
    void top_ten();
    void has_failed(std::vector<Student>& students);
    bool class_empty(std::string& teacher);
    bool in_range(std::string& teacher, int& index);

    void search_age(int& age);
    void search_text(std::string& text, int choice);
    void search_gpa(float& gpa);
    void save_school_records();
    std::set<Student> read_school_records();


    inline std::map<std::string, std::vector<Student> > get_map() const {
        return school_data;
    }

    friend std::ostream& operator<<(std::ostream& output_stream, Student_Store& st);
    float pearson(std::vector<int>& vec1, std::vector<float>& vec2);

    std::vector<int> get_all_attendance();
    std::vector<float> get_all_gpa();

};
