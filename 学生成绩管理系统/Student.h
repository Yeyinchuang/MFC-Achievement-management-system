#pragma once
#include"stdafx.h"
#include<string>
using namespace std;
class Student
{
private: 
	string m_id, m_name; 
	int m_math, m_english, m_physics;
public:
	Student() {};
	Student(string ID, string Name, int Math, int Physical, int English) {
		m_id = ID;
		m_name = Name;
		m_physics = Physical;
		m_math = Math;
		m_english = English;
	};
	int getnum();
	int getmath();
	int getenglish();
	int getphysics();
	string getid();
	string getname();
	void refine(string id, string name,int m_math,int m_english,int m_physics);
	friend bool operator<(Student stu1, Student stu2) {
		if (stu1.getnum() < stu2.getnum())//总分小
			return true;
		else if (stu1.getnum() == stu2.getnum()) {
			if (stu1.m_math < stu2.m_math) return true;//数学小
			else if (stu1.m_math == stu2.m_math) {
				if (stu1.m_physics < stu2.m_physics) return true;//物理小
				else if (stu1.m_physics == stu2.m_physics) {
					if (stu1.m_id < stu2.m_id) return true;//学号小
				}
			}
		}
		return false;
	}
	friend bool greater(Student &stu1, Student &stu2) {
		if (stu1.getnum() > stu2.getnum())//总分大
			return true;
		else if (stu1.getnum() == stu2.getnum()) {
			if (stu1.m_math > stu2.m_math) return true;//数学大
			else if (stu1.m_math == stu2.m_math) {
				if (stu1.m_physics > stu2.m_physics) return true;//物理大
				else if (stu1.m_physics == stu2.m_physics) {
					if (stu1.m_id > stu2.m_id) return true;//学号大
				}
			}
		}
		return false;
	}
};

inline int Student::getnum()
{
	return m_math + m_physics + m_english;
}

inline int Student::getmath()
{
	return m_math;
}

inline int Student::getenglish()
{
	return m_english;
}

inline int Student::getphysics()
{
	return m_physics;
}

inline string Student::getid()
{
	return m_id;
}

inline string Student::getname()
{
	return m_name;
}

inline void Student::refine(string id,string name,int m_math, int m_english, int m_physics)
{
	m_id = id;
	m_name = name;
	this->m_math= m_math;
	this->m_english = m_english;
	this->m_physics = m_physics;
}
