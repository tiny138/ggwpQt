#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include <QThread>
#include "worker.h"

class Controller : public QObject
{
	Q_OBJECT
public:
	explicit Controller(QObject *parent = nullptr);
	~Controller();

	void start();

signals:
	void startRunning(); // ���ڴ������߳��еĺ�ʱ��������

public slots:
	void on_receivResult(const QString &str); // �������߳��еĽ��

private:
	QThread m_workThread;
	Worker *m_worker;
};
#endif // CONTROLLER_H