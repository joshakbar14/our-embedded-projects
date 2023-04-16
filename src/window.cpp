#include "window.h"
#include "parkingLot.h"

class aWindowCallback : public parkCallback {
public:
	// get callbacks from parkinglot spots
	// and return: 
	// user uid
	// spot available, spot occupied
	// and designated parking space

	// if spot available = 0
	// return label "I am sorry the parking is full, would you please try again later?"

	int* aspotlabeltext;
	int* aspotavailabletext;
	int* aspotoccupiedtext;
	string* auidlabeltext;
	
	Window* windows;

	virtual void change_window(parkSample sample){
		if (windows == nullptr) return;
		*aspotlabeltext = sample.lot_no;
		*aspotavailabletext = sample.emptyspace;
		*aspotoccupiedtext = sample.occupiedspace;
		*auidlabeltext = sample.uid;

  	}

	void registerText(int* lot_no, int* emptyspace, int* occupiedspace, string* uid){
		aspotlabeltext = lot_no;
		aspotavailabletext = emptyspace;
		aspotoccupiedtext = occupiedspace;
		auidlabeltext = uid;
	}

	void registerClass(Window* window){
		windows = window;
	}

};

Window::Window()
{

	QFont font("Arial", 25);

	label = new QLabel("Test");
	QPixmap pixmap("Capture.png");

	// GUI Stuff
	label->setPixmap(pixmap);
	label->setAlignment(Qt::AlignCenter);

	header = new QLabel("Welcome to SpaceIT!");
	header->setFont(font);
	header->setAlignment(Qt::AlignCenter);

	welcomemessage = new QLabel("Scan your card");
	welcomemessage->setFont(font);
	welcomemessage->setAlignment(Qt::AlignCenter);

	spotlabel = new QLabel("Designated Spot");
	spotlabel->setFont(font);
	spotlabel->setAlignment(Qt::AlignCenter);

	uidlabel = new QLabel("UID");
    uidlabel->setFont(font);
	uidlabel->setAlignment(Qt::AlignCenter);

	spotavailable = new QLabel("Available Spot");
    spotavailable->setFont(font);
	spotavailable->setAlignment(Qt::AlignCenter);

	spotoccupied = new QLabel("Occupied Spot");
	spotoccupied->setFont(font);
	spotoccupied->setAlignment(Qt::AlignCenter);

	// Register callbacks
	aWindowCallback callback;	
	callback.registerText(&spotlabeltext, &spotavailabletext, &spotoccupiedtext, &uidlabeltext);
	callback.registerClass((Window*)this);
	parkingLot spot1(2);
	spot1.registerWindowCallback(&callback);
	
	// set up the layout
	vLayout = new QVBoxLayout();
	vLayout->addWidget(label);
	vLayout->addWidget(header);
	vLayout->addWidget(welcomemessage);
	vLayout->addWidget(spotlabel);
	vLayout->addWidget(uidlabel);
	vLayout->addWidget(spotavailable);
	vLayout->addWidget(spotoccupied);

	// plot to the left
	hLayout = new QHBoxLayout();
	hLayout->addLayout(vLayout);

	setLayout(hLayout);
}

void Window::timerEvent( QTimerEvent * )
{
	// Pass in to the GUI
	// spotlabel->setText(std::to_string(spotlabeltext));
	// spotavailable->setText(std::to_string(spotavailabletext));
	// spotoccupied->setText(std::to_string(spotoccupiedtext));
	// uidlabel->setText(uidlabeltext);
}
