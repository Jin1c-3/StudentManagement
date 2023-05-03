#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<list>
#include<ctime>
<<<<<<< HEAD
#include <fstream>
#include <iostream>
#include <sstream>
=======
#include "tabulate/table.hpp"
>>>>>>> master

using namespace tabulate;
using namespace std;

//forward declarations
class Student;
class User;

class User
{
private:
<<<<<<< HEAD
    string account;//唯一标识
    string password;
    short role;//学生0，老师1
public:
    //constructors
    User() {};
    User(string account, string password, short role)
        :account(account), password(password), role(role) {};
    User(User& user)
        :account(user.account), password(user.password), role(user.role) {};
    //getters and setters
    string getAccount() { return account; }
    string getPassword() { return password; }
    short getRole() { return role; }
    void setAccount(string account) { this->account = account; }
    void setPassword(string password) { this->password = password; }
    void setRole(short role) { this->role = role; }
    //methods
    bool login();
    //和User相关的
    bool addOneUser(User user);//增加一个用户，需要检验account的唯一性
    bool deleteOneUser(string account);//删除一个用户
    bool showOneUser(string account);//查看一个用户信息
    bool showAllUser();//查看所有用户信息
    bool updateOneUser(User user);//修改用户信息

    //和Student相关的
    // 公共权限
    bool updateOneStudent(Student student);//学生只能修改自己的电话和生日，老师可以任意修改
    //学生的权限
    bool showOneStudent(string id);//学生只能查看自己的学生信息
    //老师的权限
    bool showAllStudent();//老师可以查看所有学生信息
    bool addOneStudent(Student student);//老师可以增加一个学生
    bool deleteOneStudent(string id);//老师可以删除一个学生
    bool signUp();//只有拥有管理员账号和密码的老师可以注册新老师
=======
	string account;//唯一锟斤拷识
	string password;
	short role;//学锟斤拷0锟斤拷锟斤拷师1
public:
	//constructors
	User() {};
	User(string account, string password, short role)
		:account(account), password(password), role(role) {};
	User(User& user)
		:account(user.account), password(user.password), role(user.role) {};
	//getters and setters
	string getAccount() { return account; }
	string getPassword() { return password; }
	short getRole() { return role; }
	void setAccount(string account) { this->account = account; }
	void setPassword(string password) { this->password = password; }
	void setRole(short role) { this->role = role; }
	//methods
	bool login(User user);
	//锟斤拷User锟斤拷氐锟�
	bool addOneUser(User user);//锟斤拷锟斤拷一锟斤拷锟矫伙拷锟斤拷锟斤拷要锟斤拷锟斤拷account锟斤拷唯一锟斤拷
	bool deleteOneUser(string account);//删锟斤拷一锟斤拷锟矫伙拷
	bool showOneUser(string account);//锟介看一锟斤拷锟矫伙拷锟斤拷息
	bool showAllUser();//锟介看锟斤拷锟斤拷锟矫伙拷锟斤拷息
	bool updateOneUser(User user);//锟睫革拷锟矫伙拷锟斤拷息

	//锟斤拷Student锟斤拷氐锟�
	// 锟斤拷锟斤拷权锟斤拷
	bool updateOneStudent(Student student);//学锟斤拷只锟斤拷锟睫革拷锟皆硷拷锟侥电话锟斤拷锟斤拷锟秸ｏ拷锟斤拷师锟斤拷锟斤拷锟斤拷锟斤拷锟睫革拷
	//学锟斤拷锟斤拷权锟斤拷
	bool showOneStudent(string id);//学锟斤拷只锟杰查看锟皆硷拷锟斤拷学锟斤拷锟斤拷息
	//锟斤拷师锟斤拷权锟斤拷
	bool showAllStudent();//锟斤拷师锟斤拷锟皆查看锟斤拷锟斤拷学锟斤拷锟斤拷息
	bool addOneStudent(Student student);//锟斤拷师锟斤拷锟斤拷锟斤拷锟斤拷一锟斤拷学锟斤拷
	bool deleteOneStudent(string id);//锟斤拷师锟斤拷锟斤拷删锟斤拷一锟斤拷学锟斤拷
	list<Student> loadStudent();//锟斤拷锟斤拷锟斤拷锟斤拷学锟斤拷
	bool signUp(User user);//只锟斤拷拥锟叫癸拷锟斤拷员锟剿号猴拷锟斤拷锟斤拷锟斤拷锟绞︼拷锟斤拷锟阶拷锟斤拷锟斤拷锟绞�
>>>>>>> master
};

class Student
{
private:
    string id;
    string name;
    string identityId;
    string sex;
    string phone;
    string birthday;
    short age;
public:
<<<<<<< HEAD
    //construtors
    Student() {};
    inline Student(string id, string name, string identityId, string sex, string birthday)
        :id(id), name(name), identityId(identityId), sex(sex), birthday(birthday) {
        //计算年龄并赋值
        int birthYear = atoi(birthday.substr(0, 4).c_str());
        int birthMonth = atoi(birthday.substr(5, 2).c_str());
        time_t now;
        time(&now);
        tm* nowTime = localtime(&now);
        int nowYear = 1900 + nowTime->tm_year;
        int nowMonth = 1 + nowTime->tm_mon;
        age = nowYear - birthYear;
        if (nowMonth < birthMonth) {
            age--;
        }
    };
    Student(const Student& student)//这里得是常引用，不然会报错
        :id(student.id), name(student.name), identityId(student.identityId), sex(student.sex), phone(student.phone), birthday(student.birthday), age(student.age) {};
    //getters and setters
    string getStudentString()
    {
        return id + " " + name + " " + sex + +" " + phone + " " + birthday + " " + to_string(age);
    }
    string getId() { return id; }
    string getName() { return name; }
    string getSex() { return sex; }
    string getPhone() { return phone; }
    string getBirthday() { return birthday; }
    short getAge() { return age; }
    string getIdentityId() { return identityId; }
    void setId(string id) { this->id = id; }
    void setName(string name) { this->name = name; }
    void setSex(string sex) { this->sex = sex; }
    void setPhone(string phone) { this->phone = phone; }
    void setBirthday(string birthday) { this->birthday = birthday; }
    void setAge(short age) { this->age = age; }
    //methods
=======
	//construtors
	Student() {};
	inline Student(string id, string name, string identityId, string sex, string birthday)
		:id(id), name(name), identityId(identityId), sex(sex), birthday(birthday) {
		//锟斤拷锟斤拷锟斤拷锟戒并锟斤拷值
		int birthYear = atoi(birthday.substr(0, 4).c_str());
		int birthMonth = atoi(birthday.substr(5, 2).c_str());
		time_t now;
		time(&now);
		tm* nowTime = localtime(&now);
		int nowYear = 1900 + nowTime->tm_year;
		int nowMonth = 1 + nowTime->tm_mon;
		age = nowYear - birthYear;
		if (nowMonth < birthMonth) {
			age--;
		}
	};
	Student(Student& student)
		:id(student.id), name(student.name), identityId(student.identityId), sex(student.sex), phone(student.phone), birthday(student.birthday), age(student.age) {};
	//getters and setters
	string getId() { return id; }
	string getName() { return name; }
	string getSex() { return sex; }
	string getPhone() { return phone; }
	string getBirthday() { return birthday; }
	short getAge() { return age; }
	void setId(string id) { this->id = id; }
	void setName(string name) { this->name = name; }
	void setSex(string sex) { this->sex = sex; }
	void setPhone(string phone) { this->phone = phone; }
	void setBirthday(string birthday) { this->birthday = birthday; }
	void setAge(short age) { this->age = age; }
	//methods
>>>>>>> master
};

class FileUtil
{
public:
<<<<<<< HEAD
    static list<Student> loadStudent();//加载所有学生
    static list<User> loadUser();//加载所有用户
    static bool saveAllUser(list<User> users);//保存所有用户，采用覆盖的方式实现，方便修改、删除操作的实现
    static bool saveAllStudent(list<Student> students);//保存所有学生，采用覆盖的方式实现，方便修改、删除操作的实现
=======
	static list<Student> loadStudent();//锟斤拷锟斤拷锟斤拷锟斤拷学锟斤拷
	static list<User> loadUser();//锟斤拷锟斤拷锟斤拷锟斤拷锟矫伙拷
	static bool saveAllUser(list<User> users);//锟斤拷锟斤拷锟斤拷锟斤拷锟矫伙拷锟斤拷锟斤拷锟矫革拷锟角的凤拷式实锟街ｏ拷锟斤拷锟斤拷锟睫改★拷删锟斤拷锟斤拷锟斤拷锟斤拷实锟斤拷
	static bool saveAllStudent(list<Student> students);//锟斤拷锟斤拷锟斤拷锟斤拷学锟斤拷锟斤拷锟斤拷锟矫革拷锟角的凤拷式实锟街ｏ拷锟斤拷锟斤拷锟睫改★拷删锟斤拷锟斤拷锟斤拷锟斤拷实锟斤拷
	static list<User> loadAllUser();//loadUser()锟斤拷实锟斤拷
	static list<Student> loadAllStudent();//loadStudent()锟斤拷实锟斤拷
};

class Panel
{
public:
	void login();//锟斤拷录锟斤拷锟�
>>>>>>> master
};

//global variables
list<Student> shown_students;//锟斤拷锟斤拷锟斤拷示锟斤拷学锟斤拷锟叫憋拷
User now_user;//锟斤拷前锟斤拷录锟斤拷锟矫伙拷

list<Student> FileUtil::loadStudent() {
    list<Student> students;
    ifstream infile("D:\\code\\student\\student.txt");
    if (!infile) {
        cerr << "Error opening file!" << endl;
        return students;
    }
    string line;
    while (getline(infile, line)) {
        istringstream iss(line);
        string id, name, identityId, sex, phone, birthday, ageStr;
        short age;
        getline(iss, id, ',');
        getline(iss, name, ',');
        getline(iss, identityId, ',');
        getline(iss, sex, ',');
        getline(iss, phone, ',');
        getline(iss, birthday, ',');
        getline(iss, ageStr, ',');
        age = stoi(ageStr);
        Student student(id, name, identityId, sex, birthday);
        student.setPhone(phone);
        student.setAge(age);
        students.push_back(student);
    }
    infile.close();
    return students;
}

// 定义 saveAllStudent 函数
bool FileUtil::saveAllStudent(list<Student> students) {
    ofstream outfile("D:\\code\\student\\student.txt");
    if (!outfile) {
        cerr << "Error opening file!" << endl;
        return false;
    }
    for (auto& student : students) {
        outfile << student.getId() << ','
            << student.getName() << ','
            << student.getIdentityId() << ','
            << student.getSex() << ','
            << student.getPhone() << ','
            << student.getBirthday() << ','
            << student.getAge() << endl;
    }
    outfile.close();
    return true;
}


int main() {
<<<<<<< HEAD
    Student student("202100810120", "于靖怿", "510105200203280019", "男", "2002-06");
    cout << student.getAge() << " " << student.getBirthday() << endl;
    FileUtil file;
    shown_students = FileUtil::loadStudent();
    for (auto it = shown_students.begin(); it != shown_students.end(); it++) {
        cout << it->getStudentString() << endl;
    }
    FileUtil::saveAllStudent(shown_students);

    return 0;
=======
	Student student("202100810120", "锟节撅拷锟斤拷", "510105200203280019", "锟斤拷", "2002-06");
	cout << student.getAge() << endl;

	Table hellogithub; // 锟斤拷锟斤拷一锟斤拷锟斤拷锟斤拷 hellogithub 锟斤拷 Table 锟斤拷锟斤拷

	hellogithub.add_row({ "HelloGitHub","HelloMotherfucker~" });
	hellogithub.add_row({ "hellogithub.com" });
	hellogithub[1][0].format()
		.font_style({ FontStyle::underline });
	hellogithub.add_row({ "github.com/521xueweihan/HelloGitHub" });
	hellogithub[2][0].format()
		.font_style({ FontStyle::underline })
		.font_background_color(Color::red)
		.font_style({ FontStyle::bold });
	hellogithub.add_row({ "xueweihan NB!!!" });

	cout << hellogithub << endl;

	system("pause");

	return 0;
>>>>>>> master
}