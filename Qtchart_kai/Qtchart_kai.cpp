#include "Qtchart_kai.h"

#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <QPointF>
#include <QFont>
#include <QIODevice>
#include <Qpoint>
#include <QWheelEvent>
#include "qpoint.h"
#include <string>
#include "qt_windows.h"



Qtchart_kai::Qtchart_kai(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	scale_m = 1;//图形原始比例
	//setStyleSheet("padding: 0px; border: 0px;");//无边框

	ui.graphicsView_11->setDragMode(QGraphicsView::RubberBandDrag);//(QGraphicsView::NoDrag);//(QGraphicsView::RubberBandDrag);//QGraphicsView::ScrollHandDrag
	ui.graphicsView_12->setDragMode(QGraphicsView::RubberBandDrag);
	ui.graphicsView_13->setDragMode(QGraphicsView::RubberBandDrag);

	ui.graphicsView_21->setDragMode(QGraphicsView::RubberBandDrag);
	ui.graphicsView_22->setDragMode(QGraphicsView::RubberBandDrag);
	ui.graphicsView_23->setDragMode(QGraphicsView::RubberBandDrag);

	ui.graphicsView_11->setTransformationAnchor(QGraphicsView::AnchorUnderMouse); //是否鼠标中心
	ui.graphicsView_11->setResizeAnchor(QGraphicsView::AnchorUnderMouse);        //
	
	ui.graphicsView_12->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
	ui.graphicsView_12->setResizeAnchor(QGraphicsView::AnchorUnderMouse);

	ui.graphicsView_13->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
	ui.graphicsView_13->setResizeAnchor(QGraphicsView::AnchorUnderMouse);

	ui.graphicsView_21->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
	ui.graphicsView_21->setResizeAnchor(QGraphicsView::AnchorUnderMouse);

	ui.graphicsView_21->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
	ui.graphicsView_21->setResizeAnchor(QGraphicsView::AnchorUnderMouse);

	ui.graphicsView_22->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
	ui.graphicsView_22->setResizeAnchor(QGraphicsView::AnchorUnderMouse);

	ui.graphicsView_23->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
	ui.graphicsView_23->setResizeAnchor(QGraphicsView::AnchorUnderMouse);

	ui.paraTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.paraTable->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);


	ui.graphicsView_11->installEventFilter(this);
	ui.graphicsView_12->installEventFilter(this);
	ui.graphicsView_13->installEventFilter(this);
	ui.graphicsView_21->installEventFilter(this);
	ui.graphicsView_22->installEventFilter(this);
	ui.graphicsView_23->installEventFilter(this);

	setMouseTracking(true);//跟踪鼠标位置
//ui.graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏水平条
//ui.graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏竖条
	ui.graphicsView_11->setMouseTracking(true);
	ui.graphicsView_12->setMouseTracking(true);
	ui.graphicsView_13->setMouseTracking(true);
	ui.graphicsView_21->setMouseTracking(true);
	ui.graphicsView_22->setMouseTracking(true);
	ui.graphicsView_23->setMouseTracking(true);

	thread1 = new MyThread();
	thread2 = new txtThread();
	thread2->start();

	connect(thread1, SIGNAL(MysignalUpdateData(QString)), this, SLOT(slotUpdateDate(QString))); // 事件同步传递
	connect(thread2, SIGNAL(sendLogMsg(QString)), this, SLOT(writePlain(QString))); // 事件同步传递
	connect(this, SIGNAL(senderMsg(QString)), thread2, SLOT(threadMsg(QString))); // 事件同步传递

	pid = GetCurrentProcessId();

	//设置这一步才能子窗口进入析构函数
	setAttribute(Qt::WA_DeleteOnClose);

	//输出到plain
	m_Process = new QProcess; /*没有这个new会产生访问冲突*/
	m_Process->setProcessChannelMode(QProcess::MergedChannels);   //目前不清楚这句话有什么用
	connect(m_Process, SIGNAL(readyReadStandardOutput()), this, SLOT(onOutput()));

	//用于鼠标移动到点上显示数值
	//scatter = new QScatterSeries;
	m_valueLabel = new QLabel(this);
	m_valueLabel->setStyleSheet(QString("QLabel{color:red; font-family:\"Microsoft Yahei\"; font-size:18px; font-weight:bold;"
		" background-color:rgba(21, 100, 255, 51); border-radius:4px; text-align:center;}"));
	m_valueLabel->setFixedSize(100, 50);
	m_valueLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	m_valueLabel->hide();


}

void Qtchart_kai::writePlain(QString cmdLog_line)
{	
	
	ui.plainTextEdit->appendPlainText(cmdLog_line);
}

void Qtchart_kai::onOutput()
{
	QByteArray qbt = m_Process->readAllStandardOutput();
	QString msg = QString::fromLocal8Bit(qbt);
	ui.plainTextEdit->appendPlainText(msg);
	ui.plainTextEdit->update();
}

void Qtchart_kai::slotUpdateDate(QString txt)
{	
	qDebug() << "my pid is :" << txt;
	//ui.plainTextEdit->appendPlainText(txt);
	pid = txt.toInt();
}

void Qtchart_kai::test()
{
	writePlain("没关闭程序");
	QProcess myprocess;
	myprocess.start("notepad.exe");
	myprocess.waitForFinished();
	writePlain("程序已经关闭");

}

double Qtchart_kai::D2e(QString str)
{
	//QString str = "0.216362173D-1";
	//qDebug() << str;

	str.replace('D', 'e');
	
	//qDebug() << str.toDouble();

	return str.toDouble();

}

void Qtchart_kai::chartDispaly()
{
	QSplineSeries *series = new QSplineSeries();
	for (float i = 0; i < 100; i++)
	{
		series->append(i, sin(0.5*i));
	}
	QChart *chart = new QChart();
	chart->addSeries(series);
	chart->legend()->hide();
	chart->createDefaultAxes();
	chart->setTheme(QChart::ChartThemeDark);
//	QChartView *chartView = new QChartView(chart);
	
	ui.graphicsView_11->setChart(chart);
	ui.graphicsView_11->setRenderHint(QPainter::Antialiasing);
	//chartView->setRenderHint(QPainter::Antialiasing);
	
/*	int w = chartView->geometry().width();
	int h = chartView->geometry().height();
	chartView->setFixedSize(w / 2, h / 2);
	this->setCentralWidget(chartView);
*/


}

void Qtchart_kai::readData(QString filePth)//读入数据
{	
	scatterLine = new QScatterSeries;
	connect(scatterLine, &QScatterSeries::hovered, this, &Qtchart_kai::slotPointHoverd);//用于鼠标移动到点上显示数值
	xMax = 1;
	xMin = 0;
	yMax = 1;
	yMin = 0;
	//spline = new QSplineSeries*[4];
	spline = new QLineSeries*[1];
/*	for (int i = 0; i < 2; i++)
	{
		//spline[i] = new  QSplineSeries;
		
	}*/
	spline[0] = new QLineSeries;

	QFile file(filePth);

	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug() << QString("Open file failed!");
		return;
	}
	else qDebug() << QString("Open file success!");

	file.seek(0);
	QTextStream input(&file);
	QStringList strlist;
	QString line, string[2];
	double data[2];

	while (!input.atEnd())
	{
		line = input.readLine();
		line = line.trimmed();
		line = line.simplified(); //清除多余空格;
		strlist = line.split(" ");
/*		string[0] = strlist.at(0);
		data[0] = string[0].toDouble();

		string[1] = strlist.at(1);
		data[1] = string[1].toDouble();*/



		if (strlist.length() == 2)
		{
			//qDebug() << "i'm in 2";
			string[0] = strlist.at(0);
			data[0] = D2e(string[0]);

			string[1] = strlist.at(1);
			data[1] = D2e(string[1]);

			//x范围
			if (data[0] > xMax) xMax = data[0];
			if (data[0] < xMin) xMin = data[0];

			//y范围
			if (data[1] > yMax) yMax = data[1];
			if (data[1] < yMin) yMin = data[1];


			spline[0]->append(data[0], data[1]);
			scatterLine->append(data[0], data[1]);
		}

	}

	file.close();

}

void Qtchart_kai::creatChart(QChartView *draw, QString title, QString Xtitle, QString Ytitle, QString subTitle)//创建图表
{
	chart = new QChart();
	axisX = new QValueAxis;
	axisY = new QValueAxis;

	QFont font;//设置文字字体
	font.setFamily("SimSun");
	font.setPointSize(13);

	chart->setTitleFont(font);
	chart->setTitle(title);//标题
	//axisX->setRange(0,row);

	chart->addSeries(scatterLine);
	chart->setAxisX(axisX, scatterLine);
	chart->setAxisY(axisY, scatterLine);
	scatterLine->hide();

	axisX->setTitleText(Xtitle);   //X、Y轴标题
	axisY->setTitleText(Ytitle);
	axisX->setMax(xMax + 0.1*abs(xMax));//设置坐标轴范围
	axisX->setMin(xMin - 0.0*abs(xMin));
	axisY->setMax(yMax + 0.1*abs(yMax));//设置坐标轴范围
	axisY->setMin(yMin - 0.1*abs(yMin));
	qDebug() << xMax;
	qDebug() << yMax;

	spline[0]->setName(subTitle);//图例
	//spline[i]->setColor(Qt::red);
	spline[0]->setColor(QString("color:#13fff8"));
	chart->addSeries(spline[0]);
	chart->setAxisX(axisX, spline[0]);
	chart->setAxisY(axisY, spline[0]);
		
		
//	ui.graphicsView->setChart(chart);
//	ui.graphicsView->setRenderHint(QPainter::Antialiasing);//抗锯齿

	draw->setChart(chart);
	//draw = new qchartview(chart);  //会得到空白的chart
	draw->setRenderHint(QPainter::Antialiasing);

	QScatterSeries scatterSeries;
	//    scatterSeries.setMarkerSize(25);//设置点的大小（单位：像素数）
	scatterSeries.setMarkerShape(QScatterSeries::MarkerShapeCircle);//点的形状：方形/圆形
	scatterSeries.setPen(QPen(Qt::transparent));
}

void Qtchart_kai::createScatter(QChartView *draw, QString title, QString Xtitle, QString Ytitle, QString subTitle)
{
	chart = new QChart();
	axisX = new QValueAxis;
	axisY = new QValueAxis;
	//QLabel *cepLable = new QLabel;


	QFont font;//设置文字字体
	font.setFamily("SimSun");
	font.setPointSize(13);
	chart->setTitleFont(font);
	chart->setTitle(title);//标题
	//axisX->setRange(0,row);

	axisX->setTitleText(Xtitle);   //X、Y轴标题
	axisY->setTitleText(Ytitle);
	axisX->setMax(xMax + 0*abs(xMax));//设置坐标轴范围
	axisX->setMin(xMin - 0*abs(xMin));
	axisY->setMax(yMax + 0.1*abs(yMax));//设置坐标轴范围
	axisY->setMin(yMin - 0.1*abs(yMin));
	qDebug() << xMax;
	qDebug() << yMax;

	//spline[i]->setColor(Qt::red);
	chart->addSeries(scatter);
	scatter->setName(subTitle.arg(CEP));
	chart->setAxisX(axisX, scatter);
	chart->setAxisY(axisY, scatter);

	chart->addSeries(scaLine[0]);
	scaLine[0]->setName(QString("平均值为:%1").arg(mean));
	chart->setAxisX(axisX, scaLine[0]);
	chart->setAxisY(axisY, scaLine[0]);

	chart->addSeries(scaLine[1]);
	scaLine[1]->setName(QString("3σ:%1").arg(3*sigma));
	chart->setAxisX(axisX, scaLine[1]);
	chart->setAxisY(axisY, scaLine[1]);

	chart->addSeries(scaLine[2]);
	scaLine[2]->setName(QString("-3σ:%1").arg(-3*sigma));
	chart->setAxisX(axisX, scaLine[2]);
	chart->setAxisY(axisY, scaLine[2]);

	//	ui.graphicsView->setChart(chart);
	//	ui.graphicsView->setRenderHint(QPainter::Antialiasing);//抗锯齿

	draw->setChart(chart);
	draw->setRenderHint(QPainter::Antialiasing);

	QScatterSeries scatterSeries;
	//    scatterSeries.setMarkerSize(25);//设置点的大小（单位：像素数）
	scatterSeries.setMarkerShape(QScatterSeries::MarkerShapeCircle);//点的形状：方形/圆形
	scatterSeries.setPen(QPen(Qt::transparent));



	//cepLable->setText(QString("CEP = :%1").arg(CEP));
	//cepLable->setStyleSheet(QString("background:transparent;font-family:\"Mircsoft Yahei\";"

	//						"font-size:20px; color:#1564FF; font-weight:bold;"));
	//
	//cepLable->move((draw->width() - draw->width()) / 2,(draw->height() - draw->height()) / 2 - 5);
	//cepLable ->show();
}

//读取散点数据，每次只读两列
void Qtchart_kai::readScatterDate(QString filePath, int pos)
{	
	scatter = new QScatterSeries;
	connect(scatter, &QScatterSeries::hovered, this, &Qtchart_kai::slotPointHoverd);//用于鼠标移动到点上显示数值
	int Row = 0;
	xMax = 1;
	xMin = 0;
	yMax = 1;
	yMin = 0;

	vector<double>scatterData;
	mean = 0;
	sigma = 0;
	CEP = 0;

	scaLine = new QLineSeries*[3];
	scaLine[0] = new QLineSeries;  //这个也要实例化
	scaLine[1] = new QLineSeries;  //这个也要实例化
	scaLine[2] = new QLineSeries;  //这个也要实例化
	//spline = new QSplineSeries*[4];

	/*	for (int i = 0; i < 2; i++)
		{
			//spline[i] = new  QSplineSeries;

		}*/
	spline[0] = new QLineSeries;

	QFile file(filePath);

	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug() << QString("Open file failed!");
		return;
	}
	else qDebug() << QString("Open file success!");

	file.seek(0);
	QTextStream input(&file);
	QStringList strlist;
	QString line, string[4];
	double data[4];

	while (!input.atEnd())
	{	
		
		line = input.readLine();
		line = line.trimmed();
		line = line.simplified(); //清除多余空格;
		strlist = line.split(" ");
		/*		string[0] = strlist.at(0);
				data[0] = string[0].toDouble();

				string[1] = strlist.at(1);
				data[1] = string[1].toDouble();*/

		for (int i = 0; i < 4; i++)
		{	
			string[i] = strlist.at(i);
			data[i] = D2e(string[i]);

		}

		if (data[pos] > yMax) yMax = data[pos];
		if (data[pos] < yMin) yMin = data[pos];

		scatterData.push_back(data[pos]);

		scatter->append(Row ,data[pos]);

		Row = Row + 1;


	}
	xMax = Row;

	guass(Row, scatterData, mean, sigma);
	qDebug() << "mean";
	qDebug() << mean;
	qDebug() << "sigma_3po";
	qDebug() << sigma;

	CEP = 1.177 * sigma;

	file.seek(0);
	for (int point = 0; point < Row; point++)
	{
		scaLine[0]->append(point, mean);
		scaLine[1]->append(point, mean+3* sigma);
		scaLine[2]->append(point, mean-3* sigma);
	}

	if ((mean + 3 * sigma) > yMax) yMax = (mean + 3 * sigma);
	if ((mean - 3 * sigma) < yMin) yMin = (mean - 3 * sigma);

	file.close();
}

void Qtchart_kai::guass(int n, vector<double>x, double &E, double &sigma)
{
	int i = 0;
	double sum1 = 0, sum2 = 0, xa;
	for (i = 0; i < n; i++)
	{
		sum1 = sum1 + x[i];
	}
	xa = sum1 / (n-1);
	E = sum1 / (n-1);
	for (i = 0; i < n; i++)
	{
		sum2 = sum2 + (x[i] - xa) * (x[i] - xa);
	}
	sigma = sum2 / (n - 1);
	sigma = pow(sigma, 0.5);
}

//画出11的图
void Qtchart_kai::drawPicture11()
{	
	QString filePth = "./output/H-t.dat";
	readData(filePth);
	creatChart(ui.graphicsView_11,"高度时间曲线","t/s","H/km","H-T");

}

//画出12的图
void Qtchart_kai::drawPicture12()
{
	QString filePth = "./output/H-L.dat";
	readData(filePth);
	creatChart(ui.graphicsView_12, "高度射程曲线", "L/km", "H/km", "H-L");

}

//画出13的图
void Qtchart_kai::drawPicture13()
{
	QString filePth = "./output/V-t.dat";
	readData(filePth);
	creatChart(ui.graphicsView_13, "速度时间曲线", "t/s", "V/（m/s）", "V-t");

}

//画出21的图
void Qtchart_kai::drawPicture21()
{
	QString filePth = "./output/Ny1-t.dat";
	readData(filePth);
	creatChart(ui.graphicsView_21, "法向时间曲线", "t/s", "Ny1/g", "Ny1-t");

}

//画出22的图
void Qtchart_kai::drawPicture22()
{
	QString filePth = "./output/Alpha-t.dat";
	readData(filePth);
	creatChart(ui.graphicsView_22, "攻角时间曲线", "t/s", "Alpha/deg", "Alpha-t");

}

//画出23的图
void Qtchart_kai::drawPicture23()
{
	QString filePth = "./output/q-t.dat";
	readData(filePth);
	creatChart(ui.graphicsView_23, "动压时间曲线", "t/s", "q/Pa", "q-t");

}

void Qtchart_kai::drawScatter_11()
{	
	QString filePth = "./output/TargettingPic.dat";
	readScatterDate(filePth,0);
	createScatter(ui.sccaterView_11, "打靶运算结果", "打靶次数", "脱靶量", "数据点CEP:%1");
	//
	
	/*test*/
	//axisX = new QValueAxis;
	//axisY = new QValueAxis;
	//axisX->setMax(1);//设置坐标轴范围
	//axisX->setMin(-1);
	//axisY->setMax(5);//设置坐标轴范围
	//axisY->setMin(0);

	//scatter = new QScatterSeries;
	//scatter->setMarkerShape(QScatterSeries::MarkerShapeRectangle);//点的形状：方形/圆形
	//scatter->setPen(QPen(Qt::transparent));
	//scatter->append(0, 0);
	//scatter->append(0, 1);
	//scatter->append(0, 2);
	//scatter->setName(QString("biaoti"));
	//chart2->addSeries(scatter);
	//// 关联数据和坐标轴
	//chart2->setAxisX(axisX, scatter);
	//chart2->setAxisY(axisY, scatter);
	//ui.sccaterView_11->setChart(chart2);



}

void Qtchart_kai::drawScatter_12()
{
	QString filePth = "./output/TargettingPic.dat";
	readScatterDate(filePth, 1);
	createScatter(ui.sccaterView_12, "打靶运算结果", "打靶次数", "落速", "数据点");
}

void Qtchart_kai::drawScatter_21()
{
	QString filePth = "./output/TargettingPic.dat";
	readScatterDate(filePth, 2);
	createScatter(ui.sccaterView_21, "打靶运算结果", "打靶次数", "最大动压", "数据点");
}

void Qtchart_kai::drawScatter_22()
{
	QString filePth = "./output/TargettingPic.dat";
	readScatterDate(filePth, 3);
	createScatter(ui.sccaterView_22, "打靶运算结果", "打靶次数", "最大过载", "数据点");
}

void Qtchart_kai::InitItem()
{
	
	/*	限制lineedit输入
		//限制-180，180，并限定小数点后4位
		QRegExp rx("^-?(180|1?[0-7]?\\d(\\.\\d{1,4})?)$");
		QRegExpValidator *pReg = new QRegExpValidator(rx, this);
		ui.alpha_MAX->setValidator(pReg);

		//不限制输入的范围和限制小数点位数
		ui.alpha_MAX->setValidator(new QDoubleValidator(0,680,2,this));
	*/
	//lineedit输入限制设置
	//角度-180~180
	QRegExp angle_180("^-?(180|1?[0-9]?\\d(\\.\\d{1,4})?)$");
	QRegExpValidator *pReg_180 = new QRegExpValidator(angle_180, this);

	//角度-90~90
	QRegExp angle_90("^-?(90|[1-8]?\\d(\\.\\d{1,4})?)$");
	QRegExpValidator *pReg_90 = new QRegExpValidator(angle_90, this);

	//lineedit输入限制只能非负数
	QRegExp nonegative("[0-9]{0,9}['.']{0,1}[0-9]{0,4}");
	QRegExpValidator *pReg_nonegative = new QRegExpValidator(nonegative, this);

	//lineedit输入限制为实数
	QRegExp real("[-]{0,1}[0-9]{0,9}['.']{0,1}[0-9]{0,4}");
	QRegExpValidator *pReg_real = new QRegExpValidator(real, this);

	//初始化第1项:地球旋转
	//QMap自动根据 key排序
	QMap<QString, int> earth_rotate;
	earth_rotate.insert(("不旋转"), 0);
	earth_rotate.insert(("旋转"), 1);
	ui.comboBox_1->clear();
	foreach(const QString &str, earth_rotate.keys())
		ui.comboBox_1->addItem(str, earth_rotate.value(str));


	//初始化第2项:地球扁率
	//QMap自动根据 key排序
	QMap<QString, int> earth_oblanten;
	earth_oblanten.insert(("圆球"), 0);
	earth_oblanten.insert(("椭球"), 1);
	ui.comboBox_2->clear();
	foreach(const QString &str, earth_oblanten.keys())
		ui.comboBox_2->addItem(str, earth_oblanten.value(str));

	//初始化第3项:弹头机动
	//QMap自动根据 key排序
	QMap<QString, int> dantou_jidong;
	dantou_jidong.insert(("惯性再入"), 0);
	dantou_jidong.insert(("再入机动"), 1);
	ui.comboBox_3->clear();
	foreach(const QString &str, dantou_jidong.keys())
		ui.comboBox_3->addItem(str, dantou_jidong.value(str));

	//初始化第4项:弹道功能
	//QMap自动根据 key排序
	QMap<QString, int> dandao_function;
	dandao_function.insert(("标准弹道"), 0);
	dandao_function.insert(("上偏差弹道"), 1);
	dandao_function.insert(("下偏差弹道"), 2);
	dandao_function.insert(("特殊偏差弹道"), 3);
	dandao_function.insert(("打靶运算"), 4);
	ui.comboBox_4->clear();
	foreach(const QString &str, dandao_function.keys())
		ui.comboBox_4->addItem(str, dandao_function.value(str));

	//初始化第5项:弹道机动形式
	//QMap自动根据 key排序
	QMap<QString, int> dandao_jidong_type;
	dandao_jidong_type.insert(("直接末制导"), 0);
	dandao_jidong_type.insert(("滑翔机动"), 1);
	dandao_jidong_type.insert(("跳跃机动"), 2);
	dandao_jidong_type.insert(("定高飞行"), 3);
	ui.comboBox_5->clear();
	foreach(const QString &str, dandao_jidong_type.keys())
		ui.comboBox_5->addItem(str, dandao_jidong_type.value(str));

	//初始化第6项:角度信息判断
	//QMap自动根据 key排序
	QMap<QString, int> angle_judge;
	angle_judge.insert(("角度"), 1);
	angle_judge.insert(("度/分/秒"), 2);
	angle_judge.insert(("弧度"), 3);
	ui.comboBox_6->clear();
	foreach(const QString &str, angle_judge.keys())
		ui.comboBox_6->addItem(str, angle_judge.value(str));

	//初始化第7项：射向角
	//限制输入范围和设置默认值
	ui.dirc_angle->setValidator(pReg_180);
	ui.dirc_angle->setText("0");

	//初始化第8项：发射点纬度
	//限制输入范围和设置默认值
	ui.launchPoint_Lati->setValidator(pReg_90);
	ui.launchPoint_Lati->setText("0");

	//初始化第9项：发射点经度
	//限制输入范围和设置默认值
	ui.launchPoint_Long->setValidator(pReg_180);
	ui.launchPoint_Long->setText("0");

	//初始化第10项：发射点高程
	//限制输入范围和设置默认值
	ui.launchPoint_H->setValidator(pReg_real);
	ui.launchPoint_H->setText("0");

	//初始化第11项：目标点高程
	//限制输入范围和设置默认值
	ui.targetH->setValidator(pReg_real);
	ui.targetH->setText("0");

	//初始化第12项：分离点时间
	//限制输入范围和设置默认值
	ui.separatePoint_Time->setValidator(pReg_nonegative);
	ui.separatePoint_Time->setText("0");


	//初始化第13项：发射系位置x
	//限制输入范围和设置默认值
	ui.coorLaunch_X->setValidator(pReg_real);
	ui.coorLaunch_X->setText("0");

	//初始化第14项：发射系位置y
	//限制输入范围和设置默认值
	ui.coorLaunch_Y->setValidator(pReg_real);
	ui.coorLaunch_Y->setText("0");

	//初始化第15项：发射系位置y
	//限制输入范围和设置默认值
	ui.coorLaunch_Z->setValidator(pReg_real);
	ui.coorLaunch_Z->setText("0");

	//初始化第16项：发射系速度x
	//限制输入范围和设置默认值
	ui.coorLaunch_Vx->setValidator(pReg_real);
	ui.coorLaunch_Vx->setText("0");

	//初始化第17项：发射系速度y
	//限制输入范围和设置默认值
	ui.coorLaunch_Vy->setValidator(pReg_real);
	ui.coorLaunch_Vy->setText("0");

	//初始化第18项：发射系速度z
	//限制输入范围和设置默认值
	ui.coorLaunch_Vz->setValidator(pReg_real);
	ui.coorLaunch_Vz->setText("0");

	//初始化第19项：弹头质量
	//限制输入范围和设置默认值
	ui.dantou_mass->setValidator(pReg_nonegative);
	ui.dantou_mass->setText("1000");

	//初始化第20项：弹头参考面积
	//限制输入范围和设置默认值
	ui.dantou_area->setValidator(pReg_nonegative);
	ui.dantou_area->setText("0.6");

	//初始化第21项：最大限制攻角
	//限制输入范围和设置默认值
	ui.alpha_MAX->setValidator(pReg_90);
	ui.alpha_MAX->setText("25");

	//初始化第22项：最大限制侧滑角
	//限制输入范围和设置默认值
	ui.gama_MAX->setValidator(pReg_180);
	ui.gama_MAX->setText("5");

	//初始化第23项：落地倾角
	//限制输入范围和设置默认值
	ui.dipAngel->setValidator(pReg_90);
	ui.dipAngel->setText("-70");

	//初始化第24项：允许最大过载
	//限制输入范围和设置默认值
	ui.load_MAX->setValidator(pReg_nonegative);
	ui.load_MAX->setText("35");

	//初始化第25项：末制导视线距
	//限制输入范围和设置默认值
	ui.teminalGuiad_Visual->setValidator(pReg_nonegative);
	ui.teminalGuiad_Visual->setText("60000");

	//初始化第26项：平飞高度
	//限制输入范围和设置默认值
	ui.horizonFlight_H->setValidator(pReg_nonegative);
	ui.horizonFlight_H->setText("10000");

	//初始化第27项：滑翔角设置攻角
	//限制输入范围和设置默认值
	ui.angle_Glide->setValidator(pReg_90);
	ui.angle_Glide->setText("0");


	//初始化第28项：目标射程
	//限制输入范围和设置默认值
	ui.targetR->setValidator(pReg_nonegative);
	ui.targetR->setText("10000");


	//初始化第29项：仿真步长
	//限制输入范围和设置默认值
	ui.simuStep->setValidator(pReg_nonegative);
	ui.simuStep->setText("1");

	//初始化第30项：速度偏差
	//限制输入范围和设置默认值
	ui.velocityErro->setValidator(pReg_real);
	ui.velocityErro->setText("0");

	//初始化第31项：倾角偏差
	//限制输入范围和设置默认值
	ui.dipAngleErro->setValidator(pReg_real);
	ui.dipAngleErro->setText("0");

	//初始化第32项：轴向力相对偏差
	//限制输入范围和设置默认值
	ui.axialForceErro->setValidator(pReg_real);
	ui.axialForceErro->setText("0");

	//初始化第33项：法向力相对偏差
	//限制输入范围和设置默认值
	ui.normalForceErro->setValidator(pReg_real);
	ui.normalForceErro->setText("0");

	//初始化第34项：密度相对偏差
	//限制输入范围和设置默认值
	ui.denseErro->setValidator(pReg_real);
	ui.denseErro->setText("0");

}

//清除软件信息窗口
void Qtchart_kai::clearPlainMessage()
{
	ui.plainTextEdit->clear();
}

int checkFlag = 0;
//检查输入参数是否正确
void Qtchart_kai::checkInput()
{

	if (
		ui.dirc_angle->text().isEmpty() || ui.launchPoint_Lati->text().isEmpty() || ui.launchPoint_Long->text().isEmpty() ||
		ui.launchPoint_H->text().isEmpty() || ui.targetH->text().isEmpty() || ui.separatePoint_Time->text().isEmpty() ||
		ui.coorLaunch_X->text().isEmpty() || ui.coorLaunch_Y->text().isEmpty() || ui.coorLaunch_Z->text().isEmpty() ||
		ui.coorLaunch_Vx->text().isEmpty() || ui.coorLaunch_Vy->text().isEmpty() || ui.coorLaunch_Vz->text().isEmpty() ||
		ui.dantou_mass->text().isEmpty() || ui.dantou_area->text().isEmpty() || ui.alpha_MAX->text().isEmpty() ||
		ui.gama_MAX->text().isEmpty() || ui.dipAngel->text().isEmpty() || ui.load_MAX->text().isEmpty() ||
		ui.teminalGuiad_Visual->text().isEmpty() || ui.horizonFlight_H->text().isEmpty() || ui.angle_Glide->text().isEmpty() ||
		ui.targetR->text().isEmpty() || ui.simuStep->text().isEmpty() || ui.velocityErro->text().isEmpty() ||
		ui.dipAngleErro->text().isEmpty() || ui.axialForceErro->text().isEmpty() || ui.normalForceErro->text().isEmpty() ||
		ui.denseErro->text().isEmpty()
		)
	{
		ui.plainTextEdit->appendPlainText(("输入中存在空值"));
		checkFlag = 0;
	}
	else
	{
		ui.plainTextEdit->appendPlainText(("检查通过"));
		checkFlag = 1;
	}
}

void Qtchart_kai::writeTxt()
{

	if (checkFlag)
	{
		QString inputName = "./input/input.dat";
		QFile inputfile(inputName);


		if (!inputfile.open(QFile::WriteOnly | QFile::Text))
		{
			ui.plainTextEdit->appendPlainText(("写入input.dat文件错误"));

		}
		else
		{
			//定义输入文件的量
			QVariant comboBox_1 = ui.comboBox_1->currentData();
			QVariant comboBox_2 = ui.comboBox_2->currentData();
			QVariant comboBox_3 = ui.comboBox_3->currentData();
			QVariant comboBox_4 = ui.comboBox_4->currentData();
			QVariant comboBox_5 = ui.comboBox_5->currentData();
			QVariant comboBox_6 = ui.comboBox_6->currentData();

			QString dirc_angle = ui.dirc_angle->text();
			QString launchPoint_Lati = ui.launchPoint_Lati->text();
			QString launchPoint_Long = ui.launchPoint_Long->text();
			QString launchPoint_H = ui.launchPoint_H->text();
			QString targetH = ui.targetH->text();
			QString separatePoint_Time = ui.separatePoint_Time->text();
			QString coorLaunch_X = ui.coorLaunch_X->text();
			QString coorLaunch_Y = ui.coorLaunch_Y->text();
			QString coorLaunch_Z = ui.coorLaunch_Z->text();
			QString coorLaunch_Vx = ui.coorLaunch_Vx->text();
			QString coorLaunch_Vy = ui.coorLaunch_Vy->text();
			QString coorLaunch_Vz = ui.coorLaunch_Vz->text();
			QString dantou_mass = ui.dantou_mass->text();
			QString dantou_area = ui.dantou_area->text();
			QString alpha_MAX = ui.alpha_MAX->text();
			QString gama_MAX = ui.gama_MAX->text();
			QString dipAngel = ui.dipAngel->text();
			QString load_MAX = ui.load_MAX->text();
			QString teminalGuiad_Visual = ui.teminalGuiad_Visual->text();
			QString horizonFlight_H = ui.horizonFlight_H->text();
			QString angle_Glide = ui.angle_Glide->text();
			QString targetR = ui.targetR->text();
			QString simuStep = ui.simuStep->text();
			QString velocityErro = ui.velocityErro->text();
			QString dipAngleErro = ui.dipAngleErro->text();
			QString axialForceErro = ui.axialForceErro->text();
			QString normalForceErro = ui.normalForceErro->text();
			QString denseErro = ui.denseErro->text();

			QTextStream out(&inputfile);

			//写入文件中
			out << comboBox_1.toInt() << endl;
			out << comboBox_2.toInt() << endl;
			out << comboBox_3.toInt() << endl;
			out << comboBox_4.toInt() << endl;
			out << comboBox_5.toInt() << endl;
			out << comboBox_6.toInt() << endl;

			out << dirc_angle << endl;
			out << launchPoint_Lati << endl;
			out << launchPoint_Long << endl;
			out << launchPoint_H << endl;
			out << targetH << endl;
			out << separatePoint_Time << endl;
			out << coorLaunch_X << endl;
			out << coorLaunch_Y << endl;
			out << coorLaunch_Z << endl;
			out << coorLaunch_Vx << endl;
			out << coorLaunch_Vy << endl;
			out << coorLaunch_Vz << endl;
			out << dantou_mass << endl;
			out << dantou_area << endl;
			out << alpha_MAX << endl;
			out << gama_MAX << endl;
			out << dipAngel << endl;
			out << load_MAX << endl;
			out << teminalGuiad_Visual << endl;
			out << horizonFlight_H << endl;
			out << angle_Glide << endl;
			out << targetR << endl;
			out << simuStep << endl;
			out << velocityErro << endl;
			out << dipAngleErro << endl;
			out << axialForceErro << endl;
			out << normalForceErro << endl;
			out << denseErro << endl;

			inputfile.flush();
			inputfile.close();

			ui.plainTextEdit->appendPlainText(("input.dat生成成功"));


		}
	}
	else
	{
		ui.plainTextEdit->appendPlainText(("检查未通过，无法生成文件"));
	}

}

//运行exe文件
void Qtchart_kai::runExe()
{	
	//另一种方式产生读取输出，这个会新开启一个进程
	m_Process->start("warhead.exe");  

	//thread1->start();
	//ui.plainTextEdit->appendPlainText(("开始运行warhead.exe文件"));

	//Sleep(1000);
	//thread2->start();

	//QProcess myProcess(this);
	//QString program = "./warhead.exe";
	//QStringList arguments;
	//myProcess.start(program, arguments);
	////myProcess.start("notepad.exe");
	//while (myProcess.waitForFinished(-1))
	//{
	//	QByteArray qByteRead = myProcess.readAllStandardOutput();
	//	if (!qByteRead.isEmpty()) {
	//		ui.textBrowser->append(QString::fromLocal8Bit(qByteRead));
	//		repaint();
	//	}
	//	

	//}
	//qDebug() << "warhead.exe done!";

	//bool exeFlag = false;
	//qDebug() << (("start"));
	//ui.plainTextEdit->appendPlainText(("开始运行warhead.exe文件"));
	//qDebug() << (("wait"));
	//QProcess myProcess(this);
	//QString program = "./warhead.exe";
	//QStringList arguments;
	//arguments << "-style" << "fusion";

	//myProcess.start(program, arguments);
	//while (myProcess.waitForFinished())
	//{
	//	exeFlag = true;
	//	qDebug() << (("still running"));
	//	ui.plainTextEdit->appendPlainText(("程序运行中"));
	//	Sleep(1000);
	//}

	//if (exeFlag)
	//{
	//	qDebug() << (("tested"));
	//	ui.plainTextEdit->appendPlainText(("程序运行完毕，生成status.log文件"));
	//	QString flag = readLog();
	//	if (flag == '0')
	//	{

	//		ui.plainTextEdit->appendPlainText(("dat文件生成成功，正在生成图表"));
	//		drawPicture11();
	//		drawPicture12();
	//		drawPicture13();
	//		drawPicture21();
	//		drawPicture22();
	//		drawPicture23();
	//		fullTable();

	//		qDebug() << "当前索引值";
	//		qDebug() << ui.comboBox_4->currentIndex();
	//		if (ui.comboBox_4->currentIndex() == 2)
	//		{
	//			ui.plainTextEdit->appendPlainText(("打靶运算dat文件生成成功，正在画图"));
	//			drawScatter_11();
	//			drawScatter_12();
	//			drawScatter_21();
	//			drawScatter_22();//画图
	//		}

	//		ui.plainTextEdit->appendPlainText(("画图结束"));
	//	}
	//	else {
	//		ui.plainTextEdit->appendPlainText(("程序运行失败，请查看status.log文件"));
	//	}

	//}
	//else
	//{
	//	ui.plainTextEdit->appendPlainText(("没有找到warhead.exe文件"));
	//}

}

void Qtchart_kai::readLog()
{	
	//杀死warhead.exe，运行中断
	killProcess("warhead.exe");

	//退出进程
	thread1->quit();
	//thread2->terminate();   //强行终止，没有保存那种，quit并没有马上终止
	////回收资源
	thread1->wait();
	//thread2->wait();

	QString status_line;
	QString logName = "./status.dat";
	QFile LogFlie(logName);
	if (!LogFlie.open(QFile::ReadOnly | QFile::Text))
	{
		ui.plainTextEdit->appendPlainText(("读取status.log文件失败"));
	}

	QTextStream in(&LogFlie);
	while (!in.atEnd())
	{
		status_line = in.readLine();
		//ui.plainTextEdit->appendPlainText(status_line);
	}

	LogFlie.flush();
	LogFlie.close();

	qDebug() << status_line;
	if (status_line == '0')
	{	
		Sleep(500);
		qDebug() << (("tested"));
		//ui.plainTextEdit->appendPlainText(("程序运行完毕，生成status.log文件"));
		emit senderMsg("程序运行完毕，生成status.log文件");

		Sleep(1000);
		//ui.plainTextEdit->appendPlainText(("dat文件生成成功，正在生成图表"));
		ui.plainTextEdit->update();
		emit senderMsg("dat文件生成成功，正在生成图表");
		drawPicture11();
		drawPicture12();
		drawPicture13();
		drawPicture21();
		drawPicture22();
		drawPicture23();
		fullTable();

		qDebug() << "当前索引值";
		qDebug() << ui.comboBox_4->currentIndex();
		if (ui.comboBox_4->currentIndex() == 2)
		{
			ui.plainTextEdit->appendPlainText(("打靶运算dat文件生成成功，正在画图"));
			drawScatter_11();
			drawScatter_12();
			drawScatter_21();
			drawScatter_22();//画图
			ui.plainTextEdit->appendPlainText(("打靶运算dat文件生成成功，画图完成"));
		}

		//ui.plainTextEdit->appendPlainText(("画图结束"));
		emit senderMsg("画图结束");
	 }
	else
	{
		//ui.plainTextEdit->appendPlainText(("程序运行失败，请查看status文件"));
		emit senderMsg("程序运行失败，请查看status文件");
	}
		
	//ui.plainTextEdit->appendPlainText(("读取status.dat文件，信息为："));
	emit senderMsg("读取status.dat文件，信息为：");
	showLog(status_line);

}

//生成表格
void Qtchart_kai::fullTable()
{

	int Col = 0;
	int Row = 0;
	int Row_temp = 0;
	
	QString filePath = "./output/CharPara.dat";
	QFile file(filePath);
	QStringList strlist;
	QString line;

	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug() << QString("Open file failed!");
		return;
	}
	else qDebug() << QString("Open file success!");

	QTextStream in(&file);
	while (!in.atEnd())
	{	
		line = in.readLine();
		line = line.trimmed();
		line = line.simplified();
		Row = Row + 1;
		strlist = line.split(" ");
		Col = strlist.length();   //简单做法，列数取决于最后一行
		
	}

	ui.paraTable->setColumnCount(Col);
	ui.paraTable->setRowCount(Row);
	
	int j = 0;
	int i = 0;
	QString str;

	in.seek(0);
	while (!in.atEnd())
	{	
		//qDebug () << (i);
		line = in.readLine();
		line = line.trimmed();
		line = line.simplified();
		strlist = line.split(" ");

		for (j = 0; j < strlist.length(); j++)
		{	
			//qDebug() << (j);
			if (i == 0 )
			{	
				QString empty = "  ";
				ui.paraTable->setItem(0, 0, new QTableWidgetItem(empty));
				str = strlist[j];
				ui.paraTable->setItem(i, j + 1, new QTableWidgetItem(str));
			}else
			{
				str = strlist[j];
				ui.paraTable->setItem(i, j , new QTableWidgetItem(str));
			}

		}

		i++;
	}

}

//读取文件信息
void Qtchart_kai::showLog(QString status)
{
	switch (status.toInt())
	{
	case 0:
		ui.plainTextEdit->appendPlainText(("运行结束"));
		break;
	case 1:
		ui.plainTextEdit->appendPlainText(("角度信息输入错误"));
		break;
	case 2:
		ui.plainTextEdit->appendPlainText(("射向角输入错误"));
		break;
	case 3:
		ui.plainTextEdit->appendPlainText(("发射点纬度输入错误"));
		break;
	case 4:
		ui.plainTextEdit->appendPlainText(("发射点高程设置错误"));
		break;
	case 5:
		ui.plainTextEdit->appendPlainText(("目标点高程设置错误"));
		break;
	case 6:
		ui.plainTextEdit->appendPlainText(("发射系x位置错误"));
		break;
	case 7:
		ui.plainTextEdit->appendPlainText(("发射系y位置错误"));
		break;
	case 8:
		ui.plainTextEdit->appendPlainText(("发射系z位置错误"));
		break;
	case 9:
		ui.plainTextEdit->appendPlainText(("发射系vx速度错误"));
		break;
	case 10:
		ui.plainTextEdit->appendPlainText(("发射系vy速度错误"));
		break;
	case 11:
		ui.plainTextEdit->appendPlainText(("发射系vz速度错误"));
		break;
	case 12:
		ui.plainTextEdit->appendPlainText(("质量输入错误"));
		break;
	case 13:
		ui.plainTextEdit->appendPlainText(("最大限制攻角输入错误"));
		break;
	case 14:
		ui.plainTextEdit->appendPlainText(("最大限制侧滑角输入错误"));
		break;
	case 15:
		ui.plainTextEdit->appendPlainText(("落地着角输入错误"));
		break;
	case 16:
		ui.plainTextEdit->appendPlainText(("最大过载输入错误"));
		break;
	case 17:
		ui.plainTextEdit->appendPlainText(("弹目视线距输入错误"));
		break;
	case 18:
		ui.plainTextEdit->appendPlainText(("平飞高度输入错误"));
		break;
	case 19:
		ui.plainTextEdit->appendPlainText(("滑翔攻角输入错误"));
		break;
	case 20:
		ui.plainTextEdit->appendPlainText(("射程设置错误"));
		break;


	}

}

void mainMenu::start()
{
	Qtchart_kai *father = new Qtchart_kai;
	father->show();
	this->hide();
}

void Qtchart_kai::return2Menu()
{
	Menu = new mainMenu;
	Menu->show();
	this->hide();
}

void Qtchart_kai::killProcess(QString exeName)
{
	//QProcess p;
	//QString c = "taskkill /im" + processname + " /f";
	//p.execute(c);
	//p.close();

	//QString PID = ui.testPid->text();
	//p.kill();
	//QString cmd = QString("TASKKILL /PID %1 /F").arg(pid);
	//p.execute(cmd);
	//thread1->terminate();
	//thread1->wait();

	//std::string temp = std::string("taskkill /im ") + exeName + " /f";
	//qDebug() << temp.c_str();

	QString str = "taskkill /im " + exeName + " /f";
	//system方法
	//system(temp.c_str());

	//process方法
	QProcess p(thread1);
	p.execute(str);

}

Qtchart_kai::~Qtchart_kai()
{
	killProcess("warhead.exe");

	//退出进程
	thread1->quit();
	//回收资源
	thread1->wait();
}


//捕捉鼠标键盘输入
//void Qtchart_kai::mouseMoveEvent(QMouseEvent * e)
//{
//	if (e->button() == Qt::LeftButton)
//		qDebug() << __FUNCTION__ << ": LeftButton";
//	else if (e->button() == Qt::RightButton)
//		qDebug() << __FUNCTION__ << ": RightButton";
//	if (e->modifiers() & Qt::ShiftModifier)
//		qDebug() << __FUNCTION__ << ": shift";
//	if (e->modifiers() & Qt::AltModifier)
//		qDebug() << __FUNCTION__ << ": alt";
//	if (e->modifiers() & Qt::ControlModifier)
//		qDebug() << __FUNCTION__ << ": ctrl";
//	qDebug() << __FUNCTION__ << ": pos = " << e->pos() << " ,globalPos" << e->globalPos();
//}

//void Qtchart_kai::keyPressEvent(QKeyEvent * e)
//{
//	if (e->modifiers() & Qt::ShiftModifier)
//		qDebug() << __FUNCTION__ << ": shift";
//	if (e->modifiers() & Qt::AltModifier)
//		qDebug() << __FUNCTION__ << ": alt";
//	if (e->modifiers() & Qt::ControlModifier)
//		qDebug() << __FUNCTION__ << ": ctrl";
//	qDebug() << __FUNCTION__ << ": id=" << e->key() << " ,text=" << e->text();
//}

//检测鼠标滚动
//void Qtchart_kai::wheelEvent(QWheelEvent *event)
//{
//	if (event->modifiers() == Qt::CTRL)
//	{//按住ctrl键 可以放大缩小
//		if ((event->delta() > 0) && (scale_m >= 50))//最大放大到原始图像的50倍
//		{
//			return;
//		}
//		else if ((event->delta() < 0) && (scale_m <= 0.01))//图像缩小到自适应大小之后就不继续缩小
//		{
//			return;//重置图片大小和位置，使之自适应控件窗口大小
//		}
//		else
//		{
//			// 当前放缩倍数;
//			qreal scaleFactor = ui.graphicsView_11->matrix().m11();
//			scale_m = scaleFactor;
//
//			int wheelDeltaValue = event->delta();
//			// 向上滚动，放大;
//			if (wheelDeltaValue > 0)
//			{
//				ui.graphicsView_11->scale(1.2, 1.2);
//				ui.graphicsView_12->scale(1.2, 1.2);
//				ui.graphicsView_13->scale(1.2, 1.2);
//				\
//					ui.graphicsView_21->scale(1.2, 1.2);
//				ui.graphicsView_22->scale(1.2, 1.2);
//				ui.graphicsView_23->scale(1.2, 1.2);
//
//			}
//			else
//			{// 向下滚动，缩小;
//				ui.graphicsView_11->scale(1.0 / 1.2, 1.0 / 1.2);
//				ui.graphicsView_12->scale(1.0 / 1.2, 1.0 / 1.2);
//				ui.graphicsView_13->scale(1.0 / 1.2, 1.0 / 1.2);
//
//				ui.graphicsView_21->scale(1.0 / 1.2, 1.0 / 1.2);
//				ui.graphicsView_22->scale(1.0 / 1.2, 1.0 / 1.2);
//				ui.graphicsView_23->scale(1.0 / 1.2, 1.0 / 1.2);
//			}
//			update();
//		}
//	}
//};

//这个bool不能瞎return,这个是有意义的，最好就不return
bool Qtchart_kai::eventFilter(QObject *o, QEvent *e)
{	
	//qDebug() << "event happen!"<<__FUNCTION__;
	if (o == ui.graphicsView_11 || o == ui.graphicsView_12 || o == ui.graphicsView_13
		|| o == ui.graphicsView_21 || o == ui.graphicsView_22 || o == ui.graphicsView_23
		)
	{	
		QChartView *graph = (QChartView*)o;
		wheelScale(graph,e);
		
		//wheelScale(ui.graphicsView_11,e);
		//qDebug() << "ui.graphview11: o is found!";
		//else if (e->type() == QEvent::MouseMove)
		//{
		//	// 			QCursor::pos();
		//	// 			QCursor::globalPos();
		//	//			QApplication::keyboardInputInterval();
		//	//			QApplication::keyboardModifiers();
		//				//sendEvent()
		//				//postEvent()
		//	QMouseEvent *me = static_cast<QMouseEvent*>(e);
		//	me->globalPos();
		//	me->pos();
		//	qDebug() << __FUNCTION__;
		//}
		/*return false;*/
	}
	return FALSE;
}


void Qtchart_kai::wheelScale(QChartView *graph, QEvent *e)
{
	if (e->type() == QEvent::Wheel)
		{
		//qDebug() << "event wheelhappen!"<<__FUNCTION__;
		QWheelEvent *wheel = (QWheelEvent*)e;
		if (wheel->modifiers() == Qt::CTRL)
		{//按住ctrl键 可以放大缩小
			if ((wheel->delta() > 0) && (scale_m >= 50))//最大放大到原始图像的50倍
			{
				return;
			}
			else if ((wheel->delta() < 0) && (scale_m <= 0.01))//图像缩小到自适应大小之后就不继续缩小
			{
				return;//重置图片大小和位置，使之自适应控件窗口大小
			}
			else
			{
				qDebug() << "event wheelhappen! and i am ctrl" << __FUNCTION__;
				// 当前放缩倍数;
				qreal scaleFactor = graph->matrix().m11();
				scale_m = scaleFactor;

				int wheelDeltaValue = wheel->delta();
				// 向上滚动，放大;
				if (wheelDeltaValue > 0)
				{
					graph->scale(1.2, 1.2);

				}
				else
				{// 向下滚动，缩小;
					graph->scale(1.0 / 1.2, 1.0 / 1.2);

				}
				update();
			}
		}


	}
}

void Qtchart_kai::slotPointHoverd(const QPointF &point, bool state)

{

	if (state) {

		m_valueLabel->setText(QString::asprintf("X：%4.0f;\nY：%4.4f;",point.x(), point.y()));

		QPoint curPos = mapFromGlobal(QCursor::pos());

		m_valueLabel->move(curPos.x() - m_valueLabel->width() / 2, curPos.y() - m_valueLabel->height() * 1.5);//移动数值

		m_valueLabel->show(); //显示出来

	}

	else
	{ 
		m_valueLabel->hide(); //进行隐藏
	}

		



}
