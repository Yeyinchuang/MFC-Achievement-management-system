
// ѧ���ɼ�����ϵͳ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cѧ���ɼ�����ϵͳApp: 
// �йش����ʵ�֣������ ѧ���ɼ�����ϵͳ.cpp
//

class Cѧ���ɼ�����ϵͳApp : public CWinApp
{
public:
	Cѧ���ɼ�����ϵͳApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cѧ���ɼ�����ϵͳApp theApp;