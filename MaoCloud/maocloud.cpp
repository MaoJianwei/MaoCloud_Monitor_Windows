#include "maocloud.h"


#include <QMessageBox>

#include "MaoConst.h"

MaoCloud::MaoCloud(QWidget *parent)
	: QMainWindow(parent)
{
	china = QTextCodec::codecForLocale();

	ui.setupUi(this);

	initNodeBroadcastTableView();
	initNodeBroadcastTableViewUI();

	connect(ui.StartUDP, &QPushButton::clicked, this, &MaoCloud::OpenUdp);
	connect(this, &MaoCloud::signalUpdateNodeTableView, &MaoCloud::updateNodeTableView);
}

MaoCloud::~MaoCloud()
{

}

void MaoCloud::OpenUdp()
{
	nodeBroadcast.bind(7181, QAbstractSocket::ShareAddress);
	connect(&nodeBroadcast, SIGNAL(readyRead()), this, SLOT(RecvUdp()));
	QMessageBox::about(this,"UDP","Network - OK");
}
void MaoCloud::RecvUdp()
{
	while (nodeBroadcast.hasPendingDatagrams()){
		QByteArray datagram;
		datagram.resize(nodeBroadcast.pendingDatagramSize());

		qint64 recvLength = nodeBroadcast.readDatagram(datagram.data(), datagram.size());
		if (recvLength > 0){
			NodeBroadcastInfo* nodeInfo =  ParseDatagram(datagram);
			emit signalUpdateNodeTableView(nodeInfo);
		}
	}
}
NodeBroadcastInfo* MaoCloud::ParseDatagram(QByteArray datagram)
{
	NodeBroadcastInfo* info = new NodeBroadcastInfo();

	QList<QByteArray> dataPieces = datagram.split(';');
	for each (QByteArray dataP in dataPieces)
	{
		QList<QByteArray> dataPair = dataP.split('=');
		if (dataPair[0] == "IP"){
			info->ip = dataPair[1];
		}
		else if (dataPair[0] == "CPU_Temp"){
			info->cpuTemp = dataPair[1].toDouble();
		}
		else if (dataPair[0] == "GPU_Temp"){
			info->gpuTemp = dataPair[1].toDouble();
		}
		else if (dataPair[0] == "Count"){
			info->msgCount = dataPair[1].toInt();
		}
		else if (dataPair[0] == "Time"){
			info->nodeTime = dataPair[1];
		}
		else if (dataPair[0] == "NodeName"){
			info->name = dataPair[1];
		}
	}
	return info;
}
void MaoCloud::updateNodeTableView(NodeBroadcastInfo* nodeInfo)
{
	int row = getNodeInfoRow(nodeInfo);
	if (row == ui.NodeBrocastTable->rowCount()){
		ui.NodeBrocastTable->setRowCount(row + 1);
	}

	QTableWidgetItem* temp[Mao_Cloud_Node_Broadcast_Table_Column];
	for (int i = 0; i < Mao_Cloud_Node_Broadcast_Table_Column; i++){
		temp[i] = new QTableWidgetItem();
		temp[i]->setFlags((temp[i]->flags()) & (~Qt::ItemIsEditable));
		temp[i]->setTextAlignment(Qt::AlignVCenter);

		switch (i){
		case 0:
			temp[i]->setText(nodeInfo->name);
			break;
		case 1:
			temp[i]->setText(nodeInfo->ip);
			break;
		case 2:
			temp[i]->setText(QString::number(nodeInfo->cpuTemp));
			break;
		case 3:
			temp[i]->setText(QString::number(nodeInfo->gpuTemp));
			break;
		case 4:
			temp[i]->setText(QString::number(nodeInfo->msgCount));
			break;
		case 5:
			temp[i]->setText(nodeInfo->nodeTime);
			break;
		}
		ui.NodeBrocastTable->setItem(row, i, temp[i]);
	}
	delete nodeInfo;
}
/* for Updating nodeInfo and discovering new node */
int MaoCloud::getNodeInfoRow(NodeBroadcastInfo* nodeInfo){
	
	int row = -1;	
	for (int i = 0; i < ui.NodeBrocastTable->rowCount(); i++){
		if (ui.NodeBrocastTable->item(i, 0)->text() == nodeInfo->name){
			row = i;
			break;
		}
	}
	
	if (-1 == row){

		return ui.NodeBrocastTable->rowCount();//ui.NodeBrocastTable->rowCount() represent the number of a new row.
	}
	else{
		return row;
	}
}


void MaoCloud::initNodeBroadcastTableView()
{
	ui.NodeBrocastTable->clear();
	ui.NodeBrocastTable->setRowCount(0);

	ui.NodeBrocastTable->setColumnCount(Mao_Cloud_Node_Broadcast_Table_Column);

	for (int i = 0; i < Mao_Cloud_Node_Broadcast_Table_Column; i++)
	{
		ui.NodeBrocastTable->setHorizontalHeaderItem(i, new QTableWidgetItem(zh(NodeBroadcastHeader[i])));
	}
}
void MaoCloud::initNodeBroadcastTableViewUI()
{
	ui.NodeBrocastTable->setAcceptDrops(false);
	ui.NodeBrocastTable->setAlternatingRowColors(true);
	ui.NodeBrocastTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.NodeBrocastTable->setShowGrid(true);
	ui.NodeBrocastTable->setSortingEnabled(true);
	//ui.NodeBrocastTable->sortByColumn(0, Qt::AscendingOrder);
	ui.NodeBrocastTable->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.NodeBrocastTable->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.NodeBrocastTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

QString MaoCloud::zh(const char* str)
{
	return china->toUnicode(str);
}