#include "maocloud.h"



#include "MaoConst.h"

MaoCloud::MaoCloud(QWidget *parent)
	: QMainWindow(parent)
{
	china = QTextCodec::codecForLocale();

	ui.setupUi(this);

	initNodeBroadcastTableView();
	initNodeBroadcastTableViewUI();

	connect(this, SIGNAL(signalUpdateNodeTableView(NodeBroadcastInfo*)), SLOT(updateNodeTableView(NodeBroadcastInfo*)));
}

MaoCloud::~MaoCloud()
{

}

void MaoCloud::OpenUdp()
{
	nodeBroadcast.bind(7181, QAbstractSocket::ShareAddress);
	connect(&nodeBroadcast, SIGNAL(readyRead()), this, SLOT(RecvUdp()));
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
	for each (QTableWidgetItem* t in temp){
		t = new QTableWidgetItem();
		t->setFlags((t->flags()) & (~Qt::ItemIsEditable));//只允许修正“机型”、“起飞机场”、“备降机场”
		t->setTextAlignment(Qt::AlignLeft);
	}

	for (int i = 0; i < Mao_Cloud_Node_Broadcast_Table_Column; i++){
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
}
/* for Updating nodeInfo */
int MaoCloud::getNodeInfoRow(NodeBroadcastInfo* nodeInfo){
	//ui.NodeBrocastTable->rowCount()
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
	ui.NodeBrocastTable->sortByColumn(0, Qt::AscendingOrder);
	ui.NodeBrocastTable->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.NodeBrocastTable->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.NodeBrocastTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

QString MaoCloud::zh(const char* str)
{
	return china->toUnicode(str);
}