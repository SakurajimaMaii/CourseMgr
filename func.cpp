#include"func.h"

#include <utility>

vector<Data> Student;

bool AscendingComparison::compByAverage(const Data &a, const Data &b) {
    return a.average < b.average;
}

bool AscendingComparison::compByMath(const Data &a, const Data &b) {
    return a.Math < b.Math;
}

bool AscendingComparison::compByEnglish(const Data &a, const Data &b) {
    return a.English < b.English;
}

bool AscendingComparison::compByPE(const Data &a, const Data &b) {
    return a.PE < b.PE;
}

bool DescendingComparison::compByAverage(const Data &a, const Data &b) {
    return a.average > b.average;
}

bool DescendingComparison::compByMath(const Data &a, const Data &b) {
    return a.Math > b.Math;
}

bool DescendingComparison::compByEnglish(const Data &a, const Data &b) {
    return a.English > b.English;
}

bool DescendingComparison::compByPE(const Data &a, const Data &b) {
    return a.PE > b.PE;
}

void txt_To_Vector() {
    Student.clear();
    fstream input;
    input.open("../StudentInformation.csv", ios::in);
    Data object;
    string strLine;
    stringstream temp;
    while (getline(input, strLine)) {
        stringstream ss(strLine);
        string str;
        getline(ss, str, ',');
        object.num = str;
        getline(ss, str, ',');
        object.cla = str;
        getline(ss, str, ',');
        object.name = str;
        getline(ss, str, ',');
        object.sex = str;
        getline(ss, str, ',');
        object.major = str;
        getline(ss, str, ',');
        temp << str;
        temp >> object.Math;
        temp.clear();
        getline(ss, str, ',');
        temp << str;
        temp >> object.English;
        temp.clear();
        getline(ss, str, ',');
        temp << str;
        temp >> object.PE;
        temp.clear();
        getline(ss, str, ',');
        temp << str;
        temp >> object.average;
        temp.clear();
        Student.push_back(object);
    }
    input.close();
}

void Vector_To_txt() {
    fstream input;
    input.open("StudentInformation.csv", ios::out | ios::trunc);
    for (auto &i: Student) {
        input << i.num << ',' << i.cla << ',' << i.name << ',' << i.sex << ',' << i.major
              << ',' << i.Math << ',' << i.English << ',' << i.PE << ',' << i.average << endl;
    }
    input.close();
}

void CreateData() {
    int temp;
    cout << "请输入要添加的学生人数" << endl;
    cin >> temp;
    for (int i = 0; i < temp; i++) {
        Data object;
        object = InputStudentInformation(object);
        Student.push_back(object);
    }
}

Data InputStudentInformation(Data &c) {
    cout << "请依次输入学生的学号，班级，姓名，性别，专业" << endl;
    cin >> c.num >> c.cla >> c.name >> c.sex >> c.major;
    cout << "请依次输入" << c.name << "同学的数学、英语、体育成绩" << endl;
    cin >> c.Math >> c.English >> c.PE;
    c.average = (c.Math + c.English + c.PE) / 3.0;
    return c;
}

void DisplayStudentInformation(const vector<Data> &c) {
    system("cls");
    if (c.empty())
        cout << "目前暂无相关学生信息,请重新录入" << endl;
    else {
        cout << setw(10) << left << "学号" << setw(10) << left << "班级" << setw(10) << left << "姓名" << setw(5)
             << left << "性别" << setw(15) << left << "专业"
             << setw(10) << left << "数学成绩" << setw(10) << left << "英语成绩" << setw(10) << left << "体育成绩"
             << setw(10) << left << "平均分" << endl;
        for (const auto &i: c) {
            cout << setw(10) << left << i.num << setw(10) << left << i.cla << setw(10) << left << i.name << setw(5)
                 << left << i.sex << setw(15) << left << i.major
                 << setw(10) << left << i.Math << setw(10) << left << i.English << setw(10) << left << i.PE << setw(10)
                 << left << i.average << endl;
        }
    }
}

void DisplayStudentInformation(const Data &c) {
    cout << setw(10) << left << "学号" << setw(10) << left << "班级" << setw(10) << left << "姓名" << setw(5) << left
         << "性别" << setw(15) << left << "专业"
         << setw(10) << left << "数学成绩" << setw(10) << left << "英语成绩" << setw(10) << left << "体育成绩"
         << setw(10) << left << "平均分" << endl;
    cout << setw(10) << left << c.num << setw(10) << left << c.cla << setw(10) << left << c.name << setw(5) << left
         << c.sex << setw(15) << left << c.major
         << setw(10) << left << c.Math << setw(10) << left << c.English << setw(10) << left << c.PE << setw(10) << left
         << c.average << endl;
}

void DisplayStudentRanking(vector<Data> &c, char a) {
    switch (a) {
        case '1':
            sort(c.begin(), c.end(), DescendingComparison::compByAverage);
            cout << setw(10) << left << "学号" << setw(10) << left << "班级" << setw(10) << left << "姓名" << setw(5)
                 << left << "性别" << setw(15) << left << "专业"
                 << setw(10) << left << "数学成绩" << setw(10) << left << "英语成绩" << setw(10) << left << "体育成绩"
                 << setw(10) << left << "平均分" << endl;
            for (auto &i: c) {
                cout << setw(10) << left << i.num << setw(10) << left << i.cla << setw(10) << left << i.name << setw(5)
                     << left << i.sex << setw(15) << left << i.major
                     << setw(10) << left << i.Math << setw(10) << left << i.English << setw(10) << left << i.PE
                     << setw(10) << left << i.average << endl;
            }
            break;

        case '2':
            sort(c.begin(), c.end(), DescendingComparison::compByMath);
            cout << setw(10) << left << "学号" << setw(10) << left << "班级" << setw(10) << left << "姓名" << setw(5)
                 << left << "性别" << setw(15) << left << "专业"
                 << setw(10) << left << "数学成绩" << setw(10) << left << "英语成绩" << setw(10) << left << "体育成绩"
                 << setw(10) << left << "平均分" << endl;
            for (auto &i: c) {
                cout << setw(10) << left << i.num << setw(10) << left << i.cla << setw(10) << left << i.name << setw(5)
                     << left << i.sex << setw(15) << left << i.major
                     << setw(10) << left << i.Math << setw(10) << left << i.English << setw(10) << left << i.PE
                     << setw(10) << left << i.average << endl;
            }
            break;

        case '3':
            sort(c.begin(), c.end(), DescendingComparison::compByEnglish);
            cout << setw(10) << left << "学号" << setw(10) << left << "班级" << setw(10) << left << "姓名" << setw(5)
                 << left << "性别" << setw(15) << left << "专业"
                 << setw(10) << left << "数学成绩" << setw(10) << left << "英语成绩" << setw(10) << left << "体育成绩"
                 << setw(10) << left << "平均分" << endl;
            for (auto &i: c) {
                cout << setw(10) << left << i.num << setw(10) << left << i.cla << setw(10) << left << i.name << setw(5)
                     << left << i.sex << setw(15) << left << i.major
                     << setw(10) << left << i.Math << setw(10) << left << i.English << setw(10) << left << i.PE
                     << setw(10) << left << i.average << endl;
            }
            break;

        case '4':
            sort(c.begin(), c.end(), DescendingComparison::compByPE);
            cout << setw(10) << left << "学号" << setw(10) << left << "班级" << setw(10) << left << "姓名" << setw(5)
                 << left << "性别" << setw(15) << left << "专业"
                 << setw(10) << left << "数学成绩" << setw(10) << left << "英语成绩" << setw(10) << left << "体育成绩"
                 << setw(10) << left << "平均分" << endl;
            for (auto &i: c) {
                cout << setw(10) << left << i.num << setw(10) << left << i.cla << setw(10) << left << i.name << setw(5)
                     << left << i.sex << setw(15) << left << i.major
                     << setw(10) << left << i.Math << setw(10) << left << i.English << setw(10) << left << i.PE
                     << setw(10) << left << i.average << endl;
            }
            break;

        case '5':
            sort(c.begin(), c.end(), DescendingComparison::compByAverage);
            cout << setw(10) << left << "学号" << setw(10) << left << "班级" << setw(10) << left << "姓名" << setw(5)
                 << left << "性别" << setw(15) << left << "专业"
                 << setw(10) << left << "数学成绩" << setw(10) << left << "英语成绩" << setw(10) << left << "体育成绩"
                 << setw(10) << left << "平均分" << endl;
            for (auto &i: c) {
                cout << setw(10) << left << i.num << setw(10) << left << i.cla << setw(10) << left << i.name << setw(5)
                     << left << i.sex << setw(15) << left << i.major
                     << setw(10) << left << i.Math << setw(10) << left << i.English << setw(10) << left << i.PE
                     << setw(10) << left << i.average << endl;
            }
            break;

        case '6':
            sort(c.begin(), c.end(), AscendingComparison::compByMath);
            cout << setw(10) << left << "学号" << setw(10) << left << "班级" << setw(10) << left << "姓名" << setw(5)
                 << left << "性别" << setw(15) << left << "专业"
                 << setw(10) << left << "数学成绩" << setw(10) << left << "英语成绩" << setw(10) << left << "体育成绩"
                 << setw(10) << left << "平均分" << endl;
            for (auto &i: c) {
                cout << setw(10) << left << i.num << setw(10) << left << i.cla << setw(10) << left << i.name << setw(5)
                     << left << i.sex << setw(15) << left << i.major
                     << setw(10) << left << i.Math << setw(10) << left << i.English << setw(10) << left << i.PE
                     << setw(10) << left << i.average << endl;
            }
            break;

        case '7':
            sort(c.begin(), c.end(), AscendingComparison::compByEnglish);
            cout << setw(10) << left << "学号" << setw(10) << left << "班级" << setw(10) << left << "姓名" << setw(5)
                 << left << "性别" << setw(15) << left << "专业"
                 << setw(10) << left << "数学成绩" << setw(10) << left << "英语成绩" << setw(10) << left << "体育成绩"
                 << setw(10) << left << "平均分" << endl;
            for (auto &i: c) {
                cout << setw(10) << left << i.num << setw(10) << left << i.cla << setw(10) << left << i.name << setw(5)
                     << left << i.sex << setw(15) << left << i.major
                     << setw(10) << left << i.Math << setw(10) << left << i.English << setw(10) << left << i.PE
                     << setw(10) << left << i.average << endl;
            }
            break;

        case '8':
            sort(c.begin(), c.end(), DescendingComparison::compByPE);
            cout << setw(10) << left << "学号" << setw(10) << left << "班级" << setw(10) << left << "姓名" << setw(5)
                 << left << "性别" << setw(15) << left << "专业"
                 << setw(10) << left << "数学成绩" << setw(10) << left << "英语成绩" << setw(10) << left << "体育成绩"
                 << setw(10) << left << "平均分" << endl;
            for (auto &i: c) {
                cout << setw(10) << left << i.num << setw(10) << left << i.cla << setw(10) << left << i.name << setw(5)
                     << left << i.sex << setw(15) << left << i.major
                     << setw(10) << left << i.Math << setw(10) << left << i.English << setw(10) << left << i.PE
                     << setw(10) << left << i.average << endl;
            }
            break;

        default:
            break;
    }
}

Data findBySchoolNo(string num) {
    Data oj;
    oj.num = std::move(num);
    auto result = find_if(Student.begin(), Student.end(), std::bind2nd(DataFindByNum(), oj));
    int temp = distance(Student.begin(), result);
    oj = Student[temp];
    return oj;
}

vector<Data> findByName(string name) {
    Data oj;
    oj.name = std::move(name);
    vector<Data> res;
    unsigned int i = 0, temp = 0;
    for (; i < Student.size(); i++) {
        auto result = find_if(Student.begin() + temp, Student.end(), std::bind2nd(DataFindByName(), oj));
        if (result == Student.end())
            break;
        temp = distance(Student.begin(), result);
        res.push_back(Student[temp]);
        temp++; //保证从下一位开始查找
    }
    return res;
}

vector<Data> findByCla(string cla) {
    Data oj;
    oj.cla = std::move(cla);
    vector<Data> res;
    unsigned int i = 0, temp = 0;
    for (; i < Student.size(); i++) {
        auto result = find_if(Student.begin() + temp, Student.end(), std::bind2nd(DataFindByCla(), oj));
        if (result == Student.end())
            break;
        temp = distance(Student.begin(), result);
        res.push_back(Student[temp]);
        temp++; //保证从下一位开始查找
    }
    return res;
}

void ModifyStudentGPA(string num) {
    Data oj;
    oj.num = std::move(num);
    auto result = find_if(Student.begin(), Student.end(), std::bind2nd(DataFindByNum(), oj));
    int temp = distance(Student.begin(), result);
    int tmp = 0, score = 0;
    cout << "1.修改数学成绩 2.修改英语成绩 3.修改体育成绩" << endl;
    cin >> tmp;
    switch (tmp) {
        case 1:
            cout << "修改的分数为:" << endl;
            cin >> score;
            Student[temp].Math = score;
            Student[temp].average = (Student[temp].Math + Student[temp].English + Student[temp].PE) / 3.0;
            break;

        case 2:
            cout << "修改的分数为:" << endl;
            cin >> score;
            Student[temp].English = score;
            Student[temp].average = (Student[temp].Math + Student[temp].English + Student[temp].PE) / 3.0;
            break;

        case 3:
            cout << "修改的分数为:" << endl;
            cin >> score;
            Student[temp].PE = score;
            Student[temp].average = (Student[temp].Math + Student[temp].English + Student[temp].PE) / 3.0;
            break;

        default:
            break;
    }
}

void DeleteStudentInformation(string num) {
    Data oj;
    oj.num = std::move(num);
    auto result = find_if(Student.begin(), Student.end(), std::bind2nd(DataFindByNum(), oj));
    int temp = distance(Student.begin(), result);
    Student.erase(Student.begin() + temp);
}

void control() {
    Main_interface();
    char m;
    char n;
    fflush(stdin);
    n = getch();//GetOptions();
    switch (n) {
        case '1': {
            closegraph();
            system("cls");
            CreateData();
            fflush(stdin);
            m = getch();
            while (true) {
                if (m == '7') {
                    closegraph();
                    control();
                } else {
                    break;
                }
            }
        }
            break;

        case '2': {
            closegraph();
            DisplayStudentInformation(Student);
            fflush(stdin);
            m = getch();
            while (true) {
                if (m == '7') {
                    closegraph();
                    control();
                } else {
                    break;
                }
            }
        }

        case '3': {
            closegraph();
            Ranking_interface();
            fflush(stdin);
            n = getch();
            closegraph();
            system("cls");
            DisplayStudentRanking(Student, n);
            fflush(stdin);
            m = getch();
            while (true) {
                if (m == '7') {
                    closegraph();
                    control();
                } else {
                    break;
                }
            }
        }
            break;

        case '4': {
            closegraph();
            Find_interface();
            fflush(stdin);
            n = _getch();
            switch (n) {
                case '1': {
                    closegraph();
                    system("cls");
                    cout << "请输入你要查找的学号" << endl;
                    string num;
                    cin >> num;
                    DisplayStudentInformation(findBySchoolNo(num));
                }
                    break;

                case '2': {
                    closegraph();
                    system("cls");
                    cout << "请输入你要查找的姓名" << endl;
                    string name;
                    cin >> name;
                    DisplayStudentInformation(findByName(name));
                }
                    break;

                case '3': {
                    closegraph();
                    system("cls");
                    cout << "请输入你要查找的班级" << endl;
                    string cla;
                    cin >> cla;
                    DisplayStudentInformation(findByCla(cla));
                }
                    break;

                case '7': {
                    closegraph();
                    control();
                }
                    break;

                default:
                    break;
            }
            fflush(stdin);
            m = getch();
            while (true) {
                if (m == '7') {
                    closegraph();
                    control();
                } else {
                    break;
                }
            }
        }
            break;

        case '5': {
            closegraph();
            system("cls");
            cout << "请输入需要修改成绩的学生的学号" << endl;
            string num;
            cin >> num;
            cout << "该学生当前信息为：" << endl;
            DisplayStudentInformation(findBySchoolNo(num));
            cout << endl;
            ModifyStudentGPA(num);
            cout << endl;
            cout << "该学生修改后的信息为：" << endl;
            DisplayStudentInformation(findBySchoolNo(num));
            fflush(stdin);
            m = _getch();
            while (true) {
                if (m == '7') {
                    closegraph();
                    control();
                } else {
                    break;
                }
            }
        }
            break;

        case '6': {
            closegraph();
            system("cls");
            cout << "请输入需要删除信息的学生的学号" << endl;
            string num;
            cin >> num;
            DeleteStudentInformation(num);
            cout << "该学生信息已删除" << endl;
            fflush(stdin);
            m = getch();
            while (true) {
                if (m == '7') {
                    closegraph();
                    control();
                } else {
                    break;
                }
            }
        }
            break;

        case '8':
            Vector_To_txt();
            exit(0);
            break;

        default: {
            fflush(stdin);
            closegraph();
            control();
        }
            break;
    }
}