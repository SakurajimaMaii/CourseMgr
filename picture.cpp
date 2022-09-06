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

#include"func.h"

void Main_interface()
{
    initgraph(1000, 620);
    loadimage(nullptr, _T("../background.jpg"));
    LOGFONT f;
    gettextstyle(&f);                     // 获取当前字体设置
    f.lfHeight = 48;                      // 设置字体高度为 48
    _tcscpy_s(f.lfFaceName, _T("黑体"));    // 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
    f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿
    settextstyle(&f);                     // 设置字体样式
    setbkmode(TRANSPARENT);                //设置字体背景为透明
    settextcolor(BLACK);                   //设置字体颜色
    outtextxy(200, 100, _T("TUST成绩管理系统"));
    settextcolor(WHITE);
    settextstyle(32, 0, _T("宋体"));
    outtextxy(650, 160, _T("1.输入学生信息"));
    outtextxy(650, 200, _T("2.显示学生信息"));
    outtextxy(650, 240, _T("3.显示学生成绩排名"));
    outtextxy(650, 280, _T("4.查找学生"));
    outtextxy(650, 320, _T("5.修改学生成绩"));
    outtextxy(650, 360, _T("6.删除学生信息"));
    outtextxy(650, 400, _T("7.回退主界面"));
    outtextxy(650, 440, _T("8.退出系统"));
}

char* GetOptions() {
    char ch[100];
    int num = MultiByteToWideChar(0, 0, ch, -1, nullptr, 0);
    auto* wide = new wchar_t[num];
    MultiByteToWideChar(0, 0, ch, -1, wide, num);
    InputBox(reinterpret_cast<LPTSTR>(wide), 100, "请输入你要选择的功能：");
    int _num = WideCharToMultiByte(CP_OEMCP, 0, wide, -1, NULL, 0, NULL, FALSE);
    char* pchar = new char[_num];
    WideCharToMultiByte(CP_OEMCP, 0, wide, -1, pchar, _num, NULL, FALSE);
    return pchar;
}

void Ranking_interface()
{
    initgraph(1000, 620);
    loadimage(nullptr, _T("../background.jpg"));
    LOGFONT f;
    gettextstyle(&f);                     // 获取当前字体设置
    f.lfHeight = 48;                      // 设置字体高度为 48
    _tcscpy_s(f.lfFaceName, _T("黑体"));    // 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
    settextstyle(48, 0, _T("黑体"));
    f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿
    settextstyle(&f);                     // 设置字体样式
    setbkmode(TRANSPARENT);                //设置字体背景为透明
    settextcolor(BLACK);                   //设置字体颜色
    outtextxy(200, 100, _T("请选择你的排名方式"));
    settextcolor(WHITE);
    settextstyle(32, 0, _T("宋体"));
    outtextxy(650, 160, _T("1.平均分降序"));
    outtextxy(650, 200, _T("2.数学成绩降序"));
    outtextxy(650, 240, _T("3.英语成绩降序"));
    outtextxy(650, 280, _T("4.体育成绩降序"));
    outtextxy(650, 320, _T("5.平均分升序"));
    outtextxy(650, 360, _T("6.数学成绩升序"));
    outtextxy(650, 400, _T("7.英语成绩升序"));
    outtextxy(650, 440, _T("8.体育成绩升序"));
}

void Find_interface()
{
    initgraph(1000, 620,0);
    loadimage(nullptr, _T("../background.jpg"));
    LOGFONT f;
    gettextstyle(&f);                     // 获取当前字体设置
    f.lfHeight = 48;                      // 设置字体高度为 48
    _tcscpy_s(f.lfFaceName, _T("黑体"));    // 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
    settextstyle(48, 0, _T("黑体"));
    f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿
    settextstyle(&f);                     // 设置字体样式
    setbkmode(TRANSPARENT);                //设置字体背景为透明
    settextcolor(BLACK);                   //设置字体颜色
    outtextxy(200, 100, _T("请选择你的查找方式"));
    settextcolor(WHITE);
    settextstyle(32, 0, _T("宋体"));
    outtextxy(650, 160, _T("1.通过学号查询"));
    outtextxy(650, 200, _T("2.通过名字查询"));
    outtextxy(650, 240, _T("3.通过班级查询"));
    outtextxy(650, 280, _T("7.返回主界面"));
}