#pragma once 
#include <QtCharts>
QT_CHARTS_USE_NAMESPACE

#include <QtWidgets/QMainWindow>
#include "ui_Qtchart_kai.h"

#include <QChartView>
#include <QSplineSeries>
#include <QLineSeries>
#include <QGridLayout>
#include <QValueAxis>

#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QString>
#include <QFile>
#include <QMessageBox>

#include "stdlib.h"
#include <stdio.h>
#include <math.h>
#include <vector>

#include "mainMenu.h"

#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include "controller.h"
#include "Mythread.h"
#include "txtThread.h"

#include<qevent.h>

using namespace std;

#ifdef _MSC_VER
#pragma execution_character_set("utf-8")
#endif

namespace Ui {
	class Qtchart_kaiClass;
}
class Qtchart_kai : public QMainWindow
{
    Q_OBJECT

public:
	Qtchart_kai(QWidget *parent = Q_NULLPTR);
	~Qtchart_kai();
	
	//virtual void mouseMoveEvent(QMouseEvent *);
	//virtual void wheelEvent(QWheelEvent *);
	//virtual void keyPressEvent(QKeyEvent *);
	//��д�¼�����
	virtual bool eventFilter(QObject *, QEvent *);


private:
    Ui::Qtchart_kaiClass ui;
	QProcess  *m_Process;

	void chartDispaly();
	void initChartView();
	void drawPicture11();
	void drawPicture12();
	void drawPicture13();
	void drawPicture21();
	void drawPicture22();
	void drawPicture23();
	void drawScatter_11();
	void drawScatter_12();
	void drawScatter_21();
	void drawScatter_22();//��ͼ
	void readData(QString filePth);//��������
	void creatChart(QChartView *draw,QString title, QString Xtitle, QString Ytitle, QString subTitle);//����ͼ��
	void readScatterDate(QString filePath, int pos);
	void createScatter(QChartView *draw, QString title, QString Xtitle, QString Ytitle, QString subTitle);
	void guass(int n, vector<double>x, double &E, double &sigma);
	void showLog(QString status);
//	void wheelEvent(QWheelEvent *event);
	void test();
	double  D2e(QString str);
	void killProcess(QString exeName);
	void wheelScale(QChartView *graph, QEvent *e);
	

	QLineSeries **spline = Q_NULLPTR;
	QChart  *chart = Q_NULLPTR;//ͼ��
	QChart  *chart2 = Q_NULLPTR;//ͼ��
	QValueAxis *axisX = Q_NULLPTR, *axisY = Q_NULLPTR;
	mainMenu *Menu;
	QScatterSeries *scatter;  //ʵ����Ҫ��ȷ��
	QScatterSeries *scatterLine;
	QLineSeries **scaLine = Q_NULLPTR;
	vector<double>scatterData;

	double  xMax, xMin, yMax, yMin;
	int row = 0;
	double mean,sigma,CEP;
	void fullTable();
	int scale_m; //���ű���
	qint64 pid;
	

	//���߳�
	MyThread *thread1;
	txtThread *thread2;

	QLabel *m_valueLabel;
	
signals:
	void senderMsg(QString msg);

private slots:
	//xxw
	void InitItem();
	void clearPlainMessage();
	void checkInput();
	void writeTxt();
	void return2Menu();
	void runExe();

	void readLog();
	void slotUpdateDate(QString);
	//������ʾ��Ϣ
	//void showMyLog();
	void writePlain(QString);

	void onOutput();

	void slotPointHoverd(const QPointF &point, bool state);

	


};
