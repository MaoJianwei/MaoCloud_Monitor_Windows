#include "maocloud.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MaoCloud w;
	w.show();
	return a.exec();
}
