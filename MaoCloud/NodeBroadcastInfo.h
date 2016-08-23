#pragma once

#include <QString>

class NodeBroadcastInfo
{
public:
	NodeBroadcastInfo();
	~NodeBroadcastInfo();
	bool Equal(NodeBroadcastInfo & other);

public:
	QString name;
	QString ip;
	double cpuTemp;
	double gpuTemp;
	int msgCount;
	QString nodeTime;
};

