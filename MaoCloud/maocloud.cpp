#include "maocloud.h"

#include "MaoConst.h"

MaoCloud::MaoCloud(QWidget *parent)
	: QMainWindow(parent)
{
	china = QTextCodec::codecForLocale();

	ui.setupUi(this);

	initNodeBroadcastTableView();
	initNodeBroadcastTableViewUI();
}

MaoCloud::~MaoCloud()
{

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
	//ui.MaoFlightList->setModel(&flightListModel);
	//ui.MaoFlightList->horizontalHeader()->setMinimumWidth(40);
}

	//ui.MaoSOCflightList->setAcceptDrops(false);
	//ui.MaoSOCflightList->setAlternatingRowColors(true);
	//ui.MaoSOCflightList->setEditTriggers(QAbstractItemView::NoEditTriggers);
	//ui.MaoSOCflightList->setShowGrid(true);
	////ui.MaoSOCflightList->setSortingEnabled(true);
	////ui.MaoSOCflightList->sortByColumn(0, Qt::AscendingOrder);
	//ui.MaoSOCflightList->setSelectionBehavior(QAbstractItemView::SelectRows);
	//ui.MaoSOCflightList->setSelectionMode(QAbstractItemView::SingleSelection);
	//ui.MaoSOCflightList->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	////ui.MaoSOCflightList->setModel(&flightListModel);
	////ui.MaoSOCflightList->horizontalHeader()->setMinimumWidth(40);


	/*
	ui.MaoOneFlightDetial->setAcceptDrops(false);
	ui.MaoOneFlightDetial->setAlternatingRowColors(true);
	ui.MaoOneFlightDetial->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.MaoOneFlightDetial->setShowGrid(true);
	//ui.MaoOneFlightDetial->setSortingEnabled(true);
	//ui.MaoOneFlightDetial->sortByColumn(0, Qt::AscendingOrder);
	ui.MaoOneFlightDetial->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.MaoOneFlightDetial->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.MaoOneFlightDetial->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	//ui.MaoOneFlightDetial->setModel(&flightListModel);
	//ui.MaoOneFlightDetial->horizontalHeader()->setMinimumWidth(40);


	ui.MaoOneFlightData->setAcceptDrops(false);
	ui.MaoOneFlightData->setAlternatingRowColors(true);
	ui.MaoOneFlightData->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.MaoOneFlightData->setShowGrid(true);
	//ui.MaoOneFlightData->setSortingEnabled(true);
	//ui.MaoOneFlightData->sortByColumn(0, Qt::AscendingOrder);
	ui.MaoOneFlightData->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.MaoOneFlightData->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.MaoOneFlightData->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	//ui.MaoOneFlightData->setModel(&flightListModel);
	//ui.MaoOneFlightData->horizontalHeader()->setMinimumWidth(40);
	*/


QString MaoCloud::zh(const char* str)
{
	return china->toUnicode(str);
}