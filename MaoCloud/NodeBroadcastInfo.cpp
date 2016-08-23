#include "NodeBroadcastInfo.h"


NodeBroadcastInfo::NodeBroadcastInfo()
{
}


NodeBroadcastInfo::~NodeBroadcastInfo()
{
}

bool NodeBroadcastInfo::Equal(NodeBroadcastInfo & other){
	return name == other.name;
}