#ifndef WINDOW_H
#define WINDOW_H

#include <QApplication>
#include <QBoxLayout>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QPixmap>
#include <QFont>
#include <string>
#include "parkingLot.h"

using namespace std;

// class definition 'Window'
class Window : public QWidget
{
	// must include the Q_OBJECT macro for for the Qt signals/slots framework to work with this class
	Q_OBJECT

public:
	Window(); // default constructor - called when a Window is declared without arguments

	void timerEvent( QTimerEvent * );

// internal variables for the window class
private:
	static constexpr int plotDataSize = 100;
	static constexpr double gain = 7.5;

	QLabel       *label;
	QLabel		 *header;
	QLabel		 *welcomemessage;

	// layout elements from Qt itself http://qt-project.org/doc/qt-4.8/classes.html
	QVBoxLayout  *vLayout;  // vertical layout
	QHBoxLayout  *hLayout;  // horizontal layout

	// data arrays for the plot
	double xData[plotDataSize];
	double yData[plotDataSize];

	long count = 0;
	void reset();
	void welcomescreen();

	string spotlabeltext;
	string uidlabeltext;
	string spotavailabletext;
	string spotoccupiedtext;

public slots:
	void rfidscan();	
};

#endif // WINDOW_H
