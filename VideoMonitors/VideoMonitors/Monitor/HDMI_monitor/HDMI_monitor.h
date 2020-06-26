#pragma once
#include "..\VGA_monitor\VGA_monitor.h"
#include "..\TV\TV.h"

class HDMI_monitor : public VGA_monitor, public TV
{
public:
	void pprint() override;
	void fprint(std::ofstream& f) override;
	void pread() override;
	void fread(std::stringstream& f, int i) override;

	HDMI_monitor();
	HDMI_monitor(int _id, int _width, int _height, char* _name, int _rate, int _db);
};