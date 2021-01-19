#include "txtThread.h"
#include <QDebug>
#include <QMutex>
#include <qprocess.h>
#include "Qtchart_kai.h"
#include <QFile>
#include <QTextStream>
#include <QString>

//�жϽ����Ƿ����
#include <windows.h>  
#include "psapi.h"  
#include"stdio.h"
#include <tlhelp32.h>


txtThread::txtThread()
{
	isStop = false;


}

void txtThread::closeThread()
{
	isStop = true;
}

void txtThread::run()
{	
	//process->execute("tasklist", QStringList() << "-fi" << "imagename eq test.exe");
	//QString tmp = QString::fromLocal8Bit(process->readAllStandardOutput());
	//qDebug() << "www" << a;
	//if (!tmp.contains("test.exe", Qt::CaseInsensitive))
	//{
	//	���������
	//}

	while (0/*FindProcess()*/)
	{
		QString cmdLog_line;
		QString logFile = "./cmdLog.txt";
		QFile LogFlie(logFile);
		if (!LogFlie.open(QFile::ReadOnly | QFile::Text))
		{
			qDebug() << (("��ȡstatus.log�ļ�ʧ��"));
		}

		QTextStream in(&LogFlie);

		while (!in.atEnd())
		{	
			cmdLog_line = in.readLine();

		}
		
		//while (!in.atEnd())
		//{
		//	cmdLog_line = in.readLine();
		//	//ui.plainTextEdit->appendPlainText(status_line);
		//}
		LogFlie.flush();
		LogFlie.close();
		

		emit sendLogMsg(cmdLog_line);
		sleep(1);

	

	
	}
	
}

//
//�жϽ����Ƿ����
bool txtThread::FindProcess()
{
	int i = 0;
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(pe32);
	HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		i += 0;
	}
	BOOL bMore = ::Process32First(hProcessSnap, &pe32);
	while (bMore)
	{
		//printf(" �������ƣ�%s \n", pe32.szExeFile);//��һ��д������
		if (wcscmp(L"warhead.exe", pe32.szExeFile) == 0)
		{
			//printf("����������");
			i += 1;
		}
		bMore = ::Process32Next(hProcessSnap, &pe32);
	}
	if (i >= 1) {           //����1���ų�����
		return true;
	}
	else {
		return false;
	}
}

void txtThread::threadMsg(QString msg)
{
	emit sendLogMsg(msg);
}