#pragma once

#include <list>
#include <fstream>
#include <iostream>
#include <string>

#define _F_LOGIN "./login.ini"
#define _F_STOCK "./stock.txt"
#define _F_MESSA "./messa.ini"
using namespace std;

struct msg
{
	string id;		//学生学号
	string name;	//学生姓名
	string sex;		//学生性别
	int score1;
	int score2;
	int score3;      //学生的三门成绩
	int score_sum;	//学生总成绩
};
struct message
{
	string id;		//身份
	string m_user;	//用户名
	string m_pwd;	//密码
};
class CInfoFile
{
public:
	CInfoFile();
	~CInfoFile();
	//注册
	bool Resider(CString& id,CString& name, CString& pwd);

	//匹配登陆信息
	bool ReadLogin(CString &name, CString &pwd);

	//读取登录信息
	message ReadMessage();
	
	//修改密码
	void WritePwd(string& id, string& user, string& pwd);

	// 读取学生信息
	void ReadDocline();

	//学生信息写入文件
	void WirteDocline();

	//添加学生信息
	void Addline(CString id,CString name, CString sex, int score1, int score2, int score3);

	//保留信息导入文档
	void Save_Import(CString path);

	//不保留信息导入文档
	void New_Import(CString path);
	//清空文档
	void Clear_file();
	list<message> vms; //存储账户密码
	list<msg> ls;	//存储学生信息容器
	int num;			//用来记录学生数目
};

