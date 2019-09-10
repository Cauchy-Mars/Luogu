#include <iostream>
using namespace std;

struct Student {
    string name;
    int final_grade;
    int class_grade;
    char leader_flag;
    char western_flag;
    int essay_num;
    int scholorship;
};


Student student[105];

void handle_input(Student *student, string name, int final_grade, int class_grade, char leader_flag, char western_flag, int essay_num) {
    student->name = name;
    student->final_grade = final_grade;
    student->class_grade = class_grade;
    student->leader_flag = leader_flag;
    student->western_flag = western_flag;
    student->essay_num = essay_num;
    student->scholorship = 0;

    //whether yuanshi
    if (final_grade > 80 && essay_num >= 1) student->scholorship += 8000;

    //whether wusi
    if (final_grade > 85 && class_grade > 80) student->scholorship += 4000;

    //whether chengjiyouxiu
    if (final_grade > 90) student->scholorship += 2000;

    //whether xibu
    if (final_grade > 85 && western_flag == 'Y') student->scholorship += 1000;

    //whether banjigongxian
    if (class_grade > 80 && leader_flag == 'Y') student->scholorship += 850; 
}

Student find_max(int N) {
    Student max = student[0];
    int i;
    for (i = 1; i < N; i++) {
        if (max.scholorship < student[i].scholorship) max = student[i];
    }

    return max;
}

int main() {
    int N = 0; int i = 0;
    cin >> N;
    for (i = 0; i < N; i++) {
        string name;
        int final_grade;
        int class_grade;
        char leader_flag;
        char western_flag;
        int essay_num;
        cin >> name; cin >> final_grade; cin >> class_grade; cin >> leader_flag; cin >> western_flag; cin >> essay_num;
        handle_input(&student[i], name, final_grade, class_grade, leader_flag, western_flag, essay_num);
    }

    Student max = find_max(N);

    int sum = 0;
    for (i = 0; i < N; i++) {
        sum += student[i].scholorship;
    }

    cout << max.name << endl << max.scholorship << endl << sum << endl;

    return 0;
}

