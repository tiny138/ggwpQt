#pragma once
#ifndef WORKER_H
#define WORKER_H
#include <QObject>

class Worker : public QObject
{
	Q_OBJECT
public:
	explicit Worker(QObject *parent = nullptr);

signals:
	void resultReady(const QString &str); // 向外界发送结果

public slots:
	void on_doSomething(); // 耗时操作
};
#endif // WORKER_H
