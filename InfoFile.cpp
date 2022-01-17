#include "pch.h"
#include "InfoFile.h"


CInfoFile::CInfoFile()
{
}


CInfoFile::~CInfoFile()
{
}
//注册
bool CInfoFile::Resider(CString& id,CString& name, CString& pwd)
{
	message mes;
	ifstream ifs;
	ifs.open(_F_LOGIN, ios::in);
	if (!ifs.is_open())
	{
		ofstream p_ofs;
		p_ofs.open(_F_LOGIN, ios::out);
		p_ofs.close();
	}
	char buf[1024] = { 0 };
	char* ptr = NULL;
	while (!ifs.eof())
	{
		ifs.getline(buf, sizeof(buf));
		char* sst = strtok_s(buf, " ", &ptr);
		if (sst != NULL)
		{
			mes.id = sst;
		}
		else
		{
			break;
		}
		sst = strtok_s(NULL, " ", &ptr);
		mes.m_user = sst;
		sst = strtok_s(NULL, " ", &ptr);
		mes.m_pwd = sst;
		if ((CString)mes.m_user.c_str() == name)
		{
			return FALSE;
		}
	}
	ofstream ofs;
	ofs.open(_F_LOGIN, ios::out | ios::app);
	std::string STDStr1(CW2A(id.GetString()));
	std::string STDStr2(CW2A(name.GetString()));
	std::string STDStr3(CW2A(pwd.GetString()));//CString 转 string
	ofs << STDStr1 << " " << STDStr2 << " " << STDStr3 << endl;
	ofs.close();
	return TRUE;
}

//匹配登陆信息
bool CInfoFile::ReadLogin(CString &name, CString &pwd)
{
	ifstream ifs; //创建文件输入对象
	ifs.open(_F_LOGIN,ios::in); //打开文件

	char buf[1024] = { 0 };
	char* ptr = NULL;
	while (!ifs.eof())
	{
		
		ifs.getline(buf, sizeof(buf));
		char* sst = strtok_s(buf, " ", &ptr);
		message mes;
		if (sst != NULL)
		{
			mes.id = sst;//身份
		}
		else
		{
			break;
		}
		
		sst = strtok_s(NULL, " ", &ptr);
		mes.m_user = sst;
		sst = strtok_s(NULL, " ", &ptr);
		mes.m_pwd = sst;
		vms.push_back(mes);
	}
	ifs.close();
	for (list<message>::iterator it = vms.begin();it != vms.end();it++)
	{
		if (name == (CString)it->m_user.c_str() && pwd == (CString)it->m_pwd.c_str())
		{
			ifs.close();
			ofstream ofs;
			ofs.open(_F_MESSA, ios::out | ios::trunc);
			ofs << it->id << " " << it->m_user << " " << it->m_pwd << endl;
			ofs.close();
			return TRUE;
		}
	}
	ifs.close();
	return FALSE;
}

//读取登录信息
message CInfoFile::ReadMessage()
{
	message mes;
	ifstream ifs;
	ifs.open(_F_MESSA, ios::in);
	char buf[1024] = { 0 };
	char* ptr = NULL;
	ifs.getline(buf, sizeof(buf));
	char* sst = strtok_s(buf," ", &ptr);
	mes.id = sst;
	sst = strtok_s(NULL, " ", &ptr);
	mes.m_user = sst;
	sst = strtok_s(NULL, " ", &ptr);
	mes.m_pwd = sst;
	ifs.close();
	return mes;
}

//修改密码
void CInfoFile::WritePwd(string& id, string& user, string& pwd)
{
	for (list<message>::iterator it = vms.begin(); it != vms.end(); it++)
	{
		if (it->id == id && it->m_user == user)
		{
			vms.erase(it);
			break;
		}
	}
	message mes;
	mes.id = id;
	mes.m_user = user;
	mes.m_pwd = pwd;
	vms.push_back(mes);
	ofstream ofs;	 //创建文件输出对象
	ofs.open(_F_LOGIN,ios::out | ios::trunc); //打开文件
	for (list<message>::iterator it = vms.begin(); it != vms.end(); it++)
	{
		ofs << it->id << " ";
		ofs << it->m_user << " ";
		ofs << it->m_pwd << " " << endl;
	}
	ofs.close();	//关闭文件
	ofstream ofs1;
	ofs1.open(_F_MESSA, ios::out | ios::trunc);
	ofs1 << id << " " << user << " " << pwd << endl;
	ofs1.close();
}

//读取学生信息
void CInfoFile::ReadDocline()
{
	ifstream ifs(_F_STOCK, ios::in); //输入方式打开文件
	if (!ifs.is_open())
	{
		ofstream ofs(_F_STOCK, ios::out);
		ofs << "学生学号 学生姓名 性别 第一门成绩 第二门成绩 第三门成绩 总分" << endl; //写入表头
		ofs.close();
		return;
	}
	char ch;
	ifs >> ch;
	
	if (ifs.eof())
	{
		ofstream ofs(_F_STOCK,ios::out);
		ofs << "学生学号 学生姓名 性别 第一门成绩 第二门成绩 第三门成绩 总分" << endl; //写入表头
		ofs.close();
		num = 0;
		return;
	}
	char buf[1024] = { 0 };
	num = 0;	//初始化学生数目为0
	ls.clear();
	//取出表头
	ifs.getline(buf, sizeof(buf));
	char* ptr = NULL;
	while (!ifs.eof()) //没到文件结尾
	{
		msg tmp;

		ifs.getline(buf, sizeof(buf)); //读取一行
		num++;	//学生数目加一

		//AfxMessageBox(CString(buf));
		char *sst = strtok_s(buf, " ",&ptr); //以“|”切割
		if (sst != NULL)
		{
			tmp.id = sst; //学生学号
		}
		else
		{
			break;
		}

		sst = strtok_s(NULL, " ",&ptr);
		tmp.name = sst;	//学生姓名

		sst = strtok_s(NULL, " ",&ptr);
		tmp.sex = sst;	//学生性别

		sst = strtok_s(NULL, " ", &ptr);
		tmp.score1 = atoi(sst);	//学生三门成绩
		sst = strtok_s(NULL, " ", &ptr);
		tmp.score2 = atoi(sst);	//学生三门成绩
		sst = strtok_s(NULL, " ", &ptr);
		tmp.score3 = atoi(sst);	//学生三门成绩
		sst = strtok_s(NULL, " ", &ptr);
		tmp.score_sum = atoi(sst);	//学生三门成绩总分
		ls.push_back(tmp); //放在链表的后面
	}

	ifs.close(); //关闭文件
}

//学生信息录入文件
void CInfoFile::WirteDocline()
{
	ofstream ofs(_F_STOCK, ios::trunc);//输出方式打开文件
	ofs << "学生学号 学生姓名 性别 第一门成绩 第二门成绩 第三门成绩 总分" << endl; //写入表头

	//	//通过迭代器取出链表内容，写入文件，以“|”分隔，结尾加换行
	for (list<msg>::iterator it = ls.begin(); it != ls.end(); it++)
	{
		ofs << it->id << " ";
		ofs << it->name << " ";
		ofs << it->sex << " ";
		ofs << it->score1 << " ";
		ofs << it->score2 << " ";
		ofs << it->score3 << " ";
		ofs << it->score_sum << endl;
	}
	ofs.close();//关闭文件
	ls.clear();
}

//添加学生信息
//id:学生学号, name:学生姓名, sex:学生性别, arr[3]:学生三门科目成绩
void CInfoFile::Addline(CString id, CString name, CString sex, int score1, int score2, int score3)
{
	msg tmp;

		//学生信息有效
		if (!id.IsEmpty() || !name.IsEmpty() || !sex.IsEmpty())
		{
			CStringA str1;
			str1 = id;
			tmp.id = str1.GetBuffer();	//学号CStringA str2;
			CStringA str2;
			str2 = name;	//CString转CStirngA
			tmp.name = str2.GetBuffer(); //CStirngA转char *，商品名称
			CStringA str3;
			str3 = sex;	//CString转CStirngA
			tmp.sex = str3.GetBuffer();
			tmp.score1 = score1;
			tmp.score2 = score2;
			tmp.score3 = score3;
			tmp.score_sum = score1 + score2 + score3;
			ls.push_back(tmp);	//放在链表的后面
		}
}

void CInfoFile::Clear_file()
{
	this->ls.clear();
	ofstream ofs;
	ofs.open(_F_STOCK, ios::trunc);
	ofs.close();
}

void CInfoFile::Save_Import(CString path)//保留文件导入文档
{
	string str;
	std::string STDStr1(CW2A(path.GetString()));//CString 转 string
	str = STDStr1;
	ifstream ifs;
	ifs.open(str, ios::in);
	char buf[1024] = { 0 };
	ifs.getline(buf, sizeof(buf));
	char* ptr = NULL;
	while (!ifs.eof()) //没到文件结尾
	{
		msg tmp;

		ifs.getline(buf, sizeof(buf)); //读取一行

		//AfxMessageBox(CString(buf));
		char* sst = strtok_s(buf, " ", &ptr); //以“ ”切割
		if (sst != NULL)
		{
			tmp.id = sst; //学生学号
		}
		else
		{
			break;
		}

		sst = strtok_s(NULL, " ", &ptr);
		tmp.name = sst;	//学生姓名

		sst = strtok_s(NULL, " ", &ptr);
		tmp.sex = sst;	//学生性别

		sst = strtok_s(NULL, " ", &ptr);
		tmp.score1 = atoi(sst);	//学生三门成绩
		sst = strtok_s(NULL, " ", &ptr);
		tmp.score2 = atoi(sst);	//学生三门成绩
		sst = strtok_s(NULL, " ", &ptr);
		tmp.score3 = atoi(sst);	//学生三门成绩
		sst = strtok_s(NULL, " ", &ptr);
		tmp.score_sum = atoi(sst);	//学生三门成绩总分
		ls.push_back(tmp); //放在链表的后面
	}
	ifs.close(); //关闭文件
	ofstream ofs(_F_STOCK, ios::trunc);//输出方式打开文件
	ofs << "学生学号 学生姓名 性别 第一门成绩 第二门成绩 第三门成绩 总分" << endl; //写入表头

	//	//通过迭代器取出链表内容，写入文件，以“|”分隔，结尾加换行
	for (list<msg>::iterator it = ls.begin(); it != ls.end(); it++)
	{
		ofs << it->id << " ";
		ofs << it->name << " ";
		ofs << it->sex << " ";
		ofs << it->score1 << " ";
		ofs << it->score2 << " ";
		ofs << it->score3 << " ";
		ofs << it->score_sum << endl;
	}
	ofs.close();//关闭文件
}

void CInfoFile::New_Import(CString path)
{
	string str;
	std::string STDStr1(CW2A(path.GetString()));//CString 转 string
	str = STDStr1;
	ifstream ifs;
	ifs.open(str, ios::in);
	char buf[1024] = { 0 };
	ifs.getline(buf, sizeof(buf));
	char* ptr = NULL;
	while (!ifs.eof()) //没到文件结尾
	{
		msg tmp;

		ifs.getline(buf, sizeof(buf)); //读取一行

		//AfxMessageBox(CString(buf));
		char* sst = strtok_s(buf, " ", &ptr); //以“ ”切割
		if (sst != NULL)
		{
			tmp.id = sst; //学生学号
		}
		else
		{
			break;
		}

		sst = strtok_s(NULL, " ", &ptr);
		tmp.name = sst;	//学生姓名

		sst = strtok_s(NULL, " ", &ptr);
		tmp.sex = sst;	//学生性别

		sst = strtok_s(NULL, " ", &ptr);
		tmp.score1 = atoi(sst);	//学生三门成绩
		sst = strtok_s(NULL, " ", &ptr);
		tmp.score2 = atoi(sst);	//学生三门成绩
		sst = strtok_s(NULL, " ", &ptr);
		tmp.score3 = atoi(sst);	//学生三门成绩
		sst = strtok_s(NULL, " ", &ptr);
		tmp.score_sum = atoi(sst);	//学生三门成绩总分
		ls.push_back(tmp); //放在链表的后面
	}
	ifs.close(); //关闭文件
	ofstream ofs(_F_STOCK, ios::trunc);//输出方式打开文件
	ofs << "学生学号 学生姓名 性别 第一门成绩 第二门成绩 第三门成绩 总分" << endl; //写入表头

	//	//通过迭代器取出链表内容，写入文件，以“|”分隔，结尾加换行
	for (list<msg>::iterator it = ls.begin(); it != ls.end(); it++)
	{
		ofs << it->id << " ";
		ofs << it->name << " ";
		ofs << it->sex << " ";
		ofs << it->score1 << " ";
		ofs << it->score2 << " ";
		ofs << it->score3 << " ";
		ofs << it->score_sum << endl;
	}
	ofs.close();//关闭文件
}
