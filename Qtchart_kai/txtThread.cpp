#include "txtThread.h"
#include <QDebug>
#include <QMutex>
#include <qprocess.h>
#include "Qtchart_kai.h"
#include <QFile>
#include <QTextStream>
#include <QString>

//判断进程是否存在
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
	//	做你的事情
	//}

	while (0/*FindProcess()*/)
	{
		QString cmdLog_line;
		QString logFile = "./cmdLog.txt";
		QFile LogFlie(logFile);
		if (!LogFlie.open(QFile::ReadOnly | QFile::Text))
		{
			qDebug() << (("读取status.log文件失败"));
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
//判断进程是否存在
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
		//printf(" 进程名称：%s \n", pe32.szExeFile);//这一块写进程名
		if (wcscmp(L"warhead.exe", pe32.szExeFile) == 0)
		{
			//printf("进程运行中");
			i += 1;
		}
		bMore = ::Process32Next(hProcessSnap, &pe32);
	}
	if (i >= 1) {           //大于1，排除自身
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