#ifndef MAOCLOUD_H
#define MAOCLOUD_H

#include <QtWidgets/QMainWindow>
#include "ui_maocloud.h"


#include <QTextCodec>

class MaoCloud : public QMainWindow
{
	Q_OBJECT

public:
	MaoCloud(QWidget *parent = 0);
	~MaoCloud();

	QString zh(const char* str);
	QTextCodec* china;

private:
	void initNodeBroadcastTableView();
	void initNodeBroadcastTableViewUI();
private:
	Ui::MaoCloudClass ui;
	
};

#endif // MAOCLOUD_H
