#ifndef MAOCLOUD_H
#define MAOCLOUD_H

#include <QtWidgets/QMainWindow>
#include "ui_maocloud.h"


#include <QTextCodec>
#include <QUdpSocket>

#include "NodeBroadcastInfo.h"

class MaoCloud : public QMainWindow
{
	Q_OBJECT

	signals:
	void signalUpdateNodeTableView(NodeBroadcastInfo*);

public:
	MaoCloud(QWidget *parent = 0);
	~MaoCloud();
	QString zh(const char* str);
	

	public slots:
	void OpenUdp();
	void RecvUdp();
	void updateNodeTableView(NodeBroadcastInfo* nodeInfo);

private:
	void initNodeBroadcastTableView();
	void initNodeBroadcastTableViewUI();
	NodeBroadcastInfo* ParseDatagram(QByteArray datagram);
	
	int getNodeInfoRow(NodeBroadcastInfo* nodeInfo);
private:
	Ui::MaoCloudClass ui;
	QTextCodec* china;

	QUdpSocket nodeBroadcast;
};

#endif // MAOCLOUD_H
