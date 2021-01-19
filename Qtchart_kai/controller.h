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
	void startRunning(); // 用于触发新线程中的耗时操作函数

public slots:
	void on_receivResult(const QString &str); // 接收新线程中的结果

private:
	QThread m_workThread;
	Worker *m_worker;
};
#endif // CONTROLLER_H