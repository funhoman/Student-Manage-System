// 学生管理系统
// -----10--------20--------30--------40--------50--------60--------70--------80

// C:\download\a.txt
// 学号  姓名  性别  宿舍号码  电话号码
// 01  依古比古  男  501  87732111
// 02  唔西迪西  女  101  87723112
// 03  玛卡巴卡  男  502  87732113
//

// C:\download\b.txt
// 学号  课程编号  课程名称  学分  平时成绩  实验成绩 考试成绩
// 01  A02  大学物理  3  92  72  82
// 01  A01  大学数学  5  91  71  81
// 01  A03  大学英语  3  93  73  83
// 02  A02  大学物理  3  82  62  72
// 02  A01  大学数学  5  81  61  71
// 02  A03  大学英语  3  83  63  73
// 03  A02  大学物理  3  93  96  91
// 03  A01  大学数学  5  94  97  92
// 03  A03  大学英语  3  92  96  92
//

// 头文件
#include <conio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>

// 忽略字符问题
#pragma warning(disable: 4996)

// 命名空间
using namespace std;

// 学生类
class Student
{
public:
  // 友元函数
  friend istream& operator>>(istream&, Student&);
  friend ostream& operator<<(ostream&, const Student&);
  Student& operator=(const Student&);
  // 读函数
  string getssid() { return ssid; }
  string getsname() { return sname; }
  string getssex() { return ssex; }
  string getsdorm() { return sdorm; }
  string getstel() { return stel; }
  // 写函数
  void setssid(string t) { ssid = t; }
  void setsname(string t) { sname = t; }
  void setssex(string t) { ssex = t; }
  void setsdorm(string t) { sdorm = t; }
  void setstel(string t) { stel = t; }
private:
  string ssid;
  string sname;
  string ssex;
  string sdorm;
  string stel;
};
istream& operator>>(istream& is1, Student& s)
{
  cout << "输入：学号、姓名、性别、宿舍号、电话号码，并用空格隔开\n";
  is1 >> s.ssid >> s.sname >> s.ssex >> s.sdorm >> s.stel;
  return is1;
}
ostream& operator<<(ostream& os1, const Student& s)
{
  os1 << s.ssid << "  " << s.sname << "  " << s.ssex << "  " << s.sdorm << "  ";
  os1 << s.stel;
  return os1;
}
Student& Student::operator=(const Student& s_)
{
  this->ssid = s_.ssid;
  this->sname = s_.sname;
  this->ssex = s_.ssex;
  this->sdorm = s_.sdorm;
  this->stel = s_.stel;
  return *this;
}

// 课程类
class Course
{
public:
  // 友元
  friend istream& operator>>(istream&, Course&);
  friend ostream& operator<<(ostream&, const Course&);
  Course& operator=(const Course&);
  // 读函数
  string getcsid() { return csid; }
  string getccid() { return ccid; }
  string getcname() { return cname; }
  int getccredit() { return ccredit; }
  int getcus() { return cus; }
  int getcexp() { return cexp; }
  int getctest() { return ctest; }
  int getcsum() { return csum; }
  int getcpoint() { return cpoint; }
  // 写函数
  void setcsid(string t) { csid = t; }
  void setccid(string t) { ccid = t; }
  void setcname(string t) { cname = t; }
  void setccredit(int t) { ccredit = t; }
  void setcus(int t) { cus = t; }
  void setcexp(int t) { cexp = t; }
  void setctest(int t) { ctest = t; }
  void setcsum(int t) { csum = t; }
  void setcpoint(int t) { cpoint = t; }
private:
  string csid;
  string ccid;
  string cname;
  int ccredit;
  int cus;
  int cexp;
  int ctest;
  int csum;
  int cpoint;
};
istream& operator>>(istream& is2, Course& c)
{
  cout << "输入：学生学号、课程编号、课程名、学分、平时成绩、实验成绩、考试成绩，";
  cout << "并用空格隔开\n";
  is2 >> c.csid >> c.ccid >> c.cname >> c.ccredit >> c.cus >> c.cexp >> c.ctest;
  if (c.cexp == -1)
    c.csum = 0.3 * c.cus + 0.7 * c.ctest;
  else
    c.csum = 0.15 * c.cus + 0.15 * c.cexp + 0.7 * c.ctest;
  if (c.csum >= 60)
    c.cpoint = c.ccredit;
  else
    c.cpoint = 0;
  return is2;
}
ostream& operator<<(ostream& os2, const Course& c)
{
  os2 << c.csid << "  " << c.ccid << "  " << c.cname << "  " << c.ccredit;
  os2 << "  " << c.cus << "  " << c.cexp << "  " << c.ctest << "  " << c.csum;
  os2 << "  " << c.cpoint;
  return os2;
}
Course& Course::operator=(const Course& c)
{
  this->csid = c.csid;
  ccid = c.ccid;
  cname = c.cname;
  ccredit = c.ccredit;
  cus = c.cus;
  cexp = c.cexp;
  ctest = c.ctest;
  csum = c.csum;
  cpoint = c.cpoint;
  return *this;
}

// 管理类
class Manager
{
public:
  // 构造析构函数
  Manager(int s = 0, int c = 0);
  ~Manager();
  // 用户函数
  void getStu();
  void addStu();
  void delStu();
  void getCou();
  void addCou();
  void delCou();
  // 系统函数
  void index();
  void login();
  void back();
  void over();
  void getFile();
  void toFile();
  int search(string id);
private:
  int scount;
  int ccount;
  Student *msa;
  Course *mca;
  Student msa0;
  Course mca0;
  int opf;
  char DIR_A[100] = "C:\\download\\a.txt";
  char DIR_B[100] = "C:\\download\\b.txt";
};
// 用户函数
void Manager::getStu()
{
  string tmp;
  cout << "　　# 查 询 学 生 信 息 #" << endl;
  while (1)
  {
    cout << "输入要查询的学生学号：";
    cin >> tmp;
    if (search(tmp) != -1024)
      cout << msa[search(tmp)] << endl;
    else
      cout << "ERROR: 错误的学号！" << endl;
    cout << "要继续查询吗？(Y/N)";
    char ipt;
    cin >> ipt;
    if (toupper(ipt) == 'N')
      back();
  }
}
void Manager::addStu()
{
  char ipt;
  Student stmp;
  cout << "　　# 添 加 学 生 信 息 #" << endl;
  while (1)
  {
    cout << "现有学生 " << scount << " 名，增加一条新学生信息吗？(按 y 继续)";
    cin >> ipt;
    if (toupper(ipt) == 'Y')
    {
      cin >> stmp;
      if (search(stmp.getssid()) != -1024)
        cout << "ERROR: 重复的学号！" << endl;
      else
      {
        msa[scount] = stmp;
        scount++;
      }
    }
    else
      back();
  }
}
void Manager::delStu()
{
  string tmp;
  cout << "　　# 删 除 学 生 #" << endl;
  cout << "输入要 删 除 的学生学号：";
  cin >> tmp;
  if (search(tmp) != -1024)
  {
    char ipt;
    cout << "  " << msa[search(tmp)] << endl;
    cout << " 警 告：删除学生同时删除对应的成绩！\n 确认删除吗？";
    cin >> ipt;
    if (toupper(ipt) == 'Y')
    {
      // 删除基本信息
      msa[search(tmp)] = msa0;
      scount--;
      // 删除成绩信息
      for (int i = 0; i < ccount; i++)
        if (mca[i].getcsid() == tmp)
        {
          mca[i] = mca0;
          ccount--;
        }
    }
    else
    {
      delStu();
    }
    cout << "删除成功！还有 " << scount << " 名学生";
  }
  else
  {
    cout << "ERROR: 找不到 " << tmp << " 对应的信息！";
  }
  back();
}
void Manager::getCou()
{
  // 空间换时间
  Course ctmpa[100];
  Course ctmpb[100];
  Course ctmp;
  string tmp;
  int i = 0;
  int ctcount = 0;
  int ptcount = 0;
  cout << "　　# 查 询 学 生 成 绩 #" << endl;
  cout << "输入要查询的学生学号：";
  cin >> tmp;
  if (search(tmp) == -1024)
  {
    cout << "ERROR: 错误的学号！";
    back();
  }
  else
  {
    cout << endl;
    cout << "  姓名：" << msa[search(tmp)].getsname() << "  学号：" << tmp;
    cout << "\n-------------------------\n";
    for (; i < ccount; i++)
      if (mca[i].getcsid() == tmp)
      {
        ctmpb[ctcount] = ctmpa[ctcount] = mca[i];
        cout << "课程编号：" << mca[i].getccid() << "  ";
        cout << "课程名称：" << mca[i].getcname() << "  ";
        cout << "综合成绩：" << mca[i].getcsum() << "  ";
        cout << "实得学分：" << mca[i].getcpoint() << "  ";
        cout << endl;
        ptcount += mca[i].getcpoint();
        ctcount++;
      }
    cout << "\n-------------------------\n";
    cout << "共修：" << ctcount << "科，实得总学分：" << ptcount << "\n\n";
    // 排序功能
    char ipt;
    cout << "(1) 按综合成绩升序";
    cout << "(2) 按综合成绩降序";
    cout << "(3) 按学分升序";
    cout << "(4) 按学分降序";
    cout << "\n请选择功能：";
    cin >> ipt;
    for (int i = 0; i < ctcount; i++)
      for (int j = i + 1; j < ctcount; j++)
      {
        if (ctmpa[i].getcsum() > ctmpa[j].getcsum())
        {
          ctmp = ctmpa[i];
          ctmpa[i] = ctmpa[j];
          ctmpa[j] = ctmp;
        }
        if (ctmpb[i].getcpoint() > ctmpb[j].getcpoint())
        {
          ctmp = ctmpb[i];
          ctmpb[i] = ctmpb[j];
          ctmpb[j] = ctmp;
        }
      }
    switch (ipt - '0')
    {
    case 1:
    {
      cout << "学生学号  课程编号  课程名  学分  平时成绩  实验成绩  考试成绩  总成绩  实得学分" << endl;
      for (i = 0; i < ctcount; i++)
        cout << ctmpa[i] << endl;
      back();
    }
    break;
    case 2:
    {
      cout << "学生学号  课程编号  课程名  学分  平时成绩  实验成绩  考试成绩  总成绩  实得学分" << endl;
      for (i = ctcount - 1; i >= 0; i--)
        cout << ctmpa[i] << endl;
      back();
    }
    break;
    case 3:
    {
      cout << "学生学号  课程编号  课程名  学分  平时成绩  实验成绩  考试成绩  总成绩  实得学分" << endl;
      for (i = 0; i < ctcount; i++)
        cout << ctmpb[i] << endl;
      back();
    }
    break;
    case 4:
    {
      cout << "学生学号  课程编号  课程名  学分  平时成绩  实验成绩  考试成绩  总成绩  实得学分" << endl;
      for (i = ctcount - 1; i >= 0; i--)
        cout << ctmpb[i] << endl;
      back();
    }
    break;
    default:
    {
      back();
    }
    }
  }
}
void Manager::addCou()
{
  char ipt;
  Course ctmp;
  cout << "　　# 添 加 学 生 成 绩 #" << endl;
  while (1)
  {
    cout << "现有成绩 " << ccount << " 条，增加一条新成绩吗？(按 y 继续)";
    cin >> ipt;
    if (toupper(ipt) == 'Y')
    {
      cin >> ctmp;
      if (search(ctmp.getcsid()) == -1024)
        cout << "ERROR: 未知的学号！" << endl;
      else
      {
        mca[ccount] = ctmp;
        ccount++;
      }
    }
    else
      back();
  }
}
void Manager::delCou()
{
  string tmp1;
  string tmp2;
  cout << "　　# 删 除 成 绩 #" << endl;
  cout << "输入要删除成绩的学生学号：";
  cin >> tmp1;
  cout << "输入要删除成绩的课程编号：";
  cin >> tmp2;
  if (search(tmp1) != -1024)
  {
    int i = 0;
    for (; i < ccount; i++)
      if (mca[i].getcsid() == tmp1 && mca[i].getccid() == tmp2)
      {
        cout << mca[i] << "  已删除！";
        mca[i] = mca0;
        ccount--;
        back();
      }
    if (i > ccount)
    {
      cout << "ERROR: 没有符合条件的数据！";
      back();
    }
  }
  else
  {
    cout << "ERROR: 错误的学号！";
    back();
  }
}

// 系统函数
Manager::Manager(int s, int c)
{
  opf = 0;
  scount = s;
  ccount = c;
  msa = new Student[100];
  mca = new Course[100];
}
Manager::~Manager()
{
  delete[] msa;
  delete[] mca;
}
void Manager::back()
{
  cout << endl;
  system("pause");
  index();
}
void Manager::getFile()
{
  int i;
  ifstream ifs;
  // 文件 A
  ifs.open(DIR_A, ios::out | ios::trunc);
  if (!ifs)
  {
    cout << "error: cannot open the file!" << endl;
    exit(0);
  }
  string ssid, sname, sex, dorm, tel;
  ifs >> ssid >> sname >> sex >> dorm >> tel;
  for (i = 0; !ifs.eof(); i++)
  {
    ifs >> ssid >> sname >> sex >> dorm >> tel;
    msa[i].setssid(ssid);
    msa[i].setsname(sname); 
    msa[i].setssex(sex);
    msa[i].setsdorm(dorm);
    msa[i].setstel(tel);
  }
  scount = i - 1; // 多读一个换行符
  ifs.close();
  // 文件 B
  ifs.open(DIR_B, ios::out | ios::trunc);
  if (!ifs)
  {
    cout << "error: cannot open the file!" << endl;
    back();
  }
  string csid, cid, name, credit, us, exp, test, sum, point;
  ifs >> csid >> cid >> name >> credit >> us >> exp >> test;
  for (i = 0; !ifs.eof(); i++)
  {
    ifs >> csid >> cid >> name >> credit >> us >> exp >> test;
    mca[i].setcsid(csid);
    mca[i].setccid(cid);
    mca[i].setcname(name);
    // stirng -> int
    mca[i].setccredit(atoi(credit.c_str()));
    mca[i].setcus(atoi(us.c_str()));
    mca[i].setcexp(atoi(exp.c_str()));
    mca[i].setctest(atoi(test.c_str()));
    // csum 和 cpoint 由程序计算
    if (mca[i].getcexp() == -1)
      mca[i].setcsum(0.3 * mca[i].getcus() + 0.7 * mca[i].getctest());
    else
      mca[i].setcsum(0.15 * mca[i].getcus() + 0.15 * mca[i].getcexp() + 0.7 * mca[i].getctest());
    if (mca[i].getcsum() >= 60)
      mca[i].setcpoint(mca[i].getccredit());
    else
      mca[i].setcpoint(0);
  }
  ccount = i - 1; // 多读一个换行符
  ifs.close();
  cout << "加载完成";
}
void Manager::toFile()
{
  ofstream ofs;
  // 文件 A
  ofs.open(DIR_A);
  if (!ofs)
  {
    cout << "error: cannot open the file!" << endl;
    exit(0);
  }
  ofs << "学号  姓名  性别  宿舍号码  电话号码" << endl;
  for (int i = 0; i <= scount; i++)
  {
    ofs << msa[i].getssid();
    ofs << "  ";
    ofs << msa[i].getsname();
    ofs << "  ";
    ofs << msa[i].getssex();
    ofs << "  ";
    ofs << msa[i].getsdorm();
    ofs << "  ";
    ofs << msa[i].getstel();
    ofs << endl;
  }
  ofs.close();
  // 文件 B
  ofs.open(DIR_B);
  if (!ofs)
  {
    cout << "error: cannot open the file!" << endl;
    back();
  }
  ofs << "学号  课程编号  课程名称  学分  平时成绩  实验成绩 考试成绩" << endl;
  for (int i = 0; i <= ccount; i++)
  {
    ofs << mca[i].getcsid();
    ofs << "  ";
    ofs << mca[i].getccid();
    ofs << "  ";
    ofs << mca[i].getcname();
    ofs << "  ";
    if (mca[i].getccredit() == 0 || mca[i].getccredit() == 0)
    {
      ofs << "  ";
      ofs << endl;
    }
    else
    {
      ofs << mca[i].getccredit();
      ofs << "  ";
      ofs << mca[i].getcus();
      ofs << "  ";
      ofs << mca[i].getcexp();
      ofs << "  ";
      ofs << mca[i].getctest();
      ofs << endl;
    }
  }
  ofs.close();
  cout << "退出成功";
}
void Manager::index()
{
  if (opf != 1)
  {
    cout << "  # 学生管理系统 #\n\a" << endl;
    cout << "　　# 登　录 #" << endl;
    login();
  }
  else
  {
    cout << endl;
    cout << "┌  学生管理系统 ┐" << endl;
    cout << "├──── 菜  单 ───┤" << endl;
    cout << "│ (0) 退　　出  │" << endl;
    cout << "│ (1) 查询学生  │" << endl;
    cout << "│ (2) 添加学生  │" << endl;
    cout << "│ (3) 删除学生  │" << endl;
    cout << "│ (4) 查询成绩  │" << endl;
    cout << "│ (5) 添加成绩  │" << endl;
    cout << "│ (6) 删除成绩  │" << endl;
    system("echo └─  %date:~0,10% ─┘");
    cout << endl;
    char ipt;
    cout << "请选择：";
    cin >> ipt;
    switch (ipt - '0')
    {
    case 0: over(); break;
    case 1: getStu(); break;
    case 2: addStu(); break;
    case 3: delStu(); break;
    case 4: getCou(); break;
    case 5: addCou(); break;
    case 6: delCou(); break;
    default: { cout << "请重新输入" << endl; index(); }
    }
  }
}
void Manager::login()
{
  char ch;
  char pw[3];
  cout << "您未登录请先登录，\n";
  for (int i = 3, j = 0; i > 0; i--)
  {
    cout << "请输入密码：";
    while ((ch = toupper(getch())) != '\r')
    {
      if (ch == 8)
      {
        cout << "\b \b"; // Back & space
        j--;
      }
      else
      {
        pw[j] = ch;
        cout << "*";
        j++;
      }
    }
    if (pw[0] == 'I' && pw[1] == 'P' && pw[2] == 'T')
    {
      opf = 1;
      cout << endl << "登录成功！" << endl;
      cout << "请输入文件 A 地址：";
      cin >> DIR_A;
      cout << "请输入文件 B 地址：";
      cin >> DIR_B;
      getFile();
      index();
    }
    else
    {
      cout << "密码错误" << endl;
      exit(0);
    }
  }
}
void Manager::over()
{
  toFile();
  exit(0);
}
int Manager::search(string id)
{
  // Sequential search with sentry
  int i = 0;
  msa[scount].setssid(id);
  while (msa[i].getssid() != id)
    i++;
  if (i == scount)
    return -1024;
  else
    return i;
}

// 主函数
int main()
{
  Manager m;
  m.index();
  return 0;
}
