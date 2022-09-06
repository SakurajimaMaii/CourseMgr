// Copyright 2022 Vast Gui
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#include<functional>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<Windows.h> //包含SetFileAttributes
#include<graphics.h>
#include<conio.h>
#include<Windows.h>
#include<easyx.h>
using namespace std;

struct Data {
    string num, cla, name, sex, major;
    int Math, English, PE;
    double average = (double)(Math + English + PE) / 3;
};

//创建结构体容器
extern vector<Data>Student;

struct DataFindByNum : public std::binary_function<Data, Data, bool>
{
    bool operator () (const Data& obj1, const Data& obj2) const
    {
        return obj1.num == obj2.num;
    }

};

struct DataFindByName : public std::binary_function<Data, Data, bool>
{
    bool operator () (const Data& obj1, const Data& obj2) const
    {
        return obj1.name == obj2.name;
    }
};

struct DataFindByCla : public std::binary_function<Data, Data, bool>
{
    bool operator () (const Data& obj1, const Data& obj2) const
    {
        return obj1.cla == obj2.cla;
    }

};

namespace AscendingComparison {
    bool compByAverage(const Data& a, const Data& b);
    bool compByMath(const Data& a, const Data& b);
    bool compByEnglish(const Data& a, const Data& b);
    bool compByPE(const Data& a, const Data& b);
};

namespace DescendingComparison {
    bool compByAverage(const Data& a, const Data& b);
    bool compByMath(const Data& a, const Data& b);
    bool compByEnglish(const Data& a, const Data& b);
    bool compByPE(const Data& a, const Data& b);
};

//操作函数声明
void control();
void txt_To_Vector();
void Vector_To_txt();
void CreateData();
Data InputStudentInformation(Data& c);
void DisplayStudentInformation(const vector<Data>& c);
void DisplayStudentInformation(const Data& c);
void DisplayStudentRanking(vector<Data>& c, char a);
Data findBySchoolNo(string num);
vector<Data> findByName(string name);
vector<Data> findByCla(string cla);
void ModifyStudentGPA(string num);
void DeleteStudentInformation(string num);

//页面显示函数声明
void Main_interface();
char* GetOptions();
void Ranking_interface();
void Find_interface();