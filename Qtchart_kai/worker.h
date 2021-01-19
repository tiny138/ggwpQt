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
	void resultReady(const QString &str); // ����緢�ͽ��

public slots:
	void on_doSomething(); // ��ʱ����
};
#endif // WORKER_H
