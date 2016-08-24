#pragma once

#include <QString>

class NodeBroadcastInfo
{
public:
	NodeBroadcastInfo(){};
	~NodeBroadcastInfo(){};
	bool Equal(NodeBroadcastInfo & other){
		return name == other.name;
	}

public:
	QString name;
	QString ip;
	double cpuTemp;
	double gpuTemp;
	int msgCount;
	QString nodeTime;
};

