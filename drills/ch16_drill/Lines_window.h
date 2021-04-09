#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Window {
	Lines_window(Point xy, int w, int h, const string& title );
private:
	Open_polyline lines;

	Button next_button;
	Button quit_button;

	In_box next_x;
	In_box next_y;

	Out_box xy_out;

	Menu color_menu;
	Button color_button;

	Menu style_menu;
	Button style_button;

	void change(Color c){lines.set_color(c);}
	void change_s(Line_style s) { lines.set_style(s); }
	void hide_menu() {color_menu.hide();color_button.show();}
	void hide_style() { style_menu.hide(); style_button.show(); }

	void red_pressed() {change(Color::red); hide_menu();}
	void blue_pressed() {change(Color::blue); hide_menu();}
	void black_pressed() {change(Color::black); hide_menu();}
	void color_pressed() { color_button.hide(); color_menu.show(); }
	void style_pressed(){ style_button.hide(); style_menu.show(); }

	void dot_pressed() { change_s(Line_style::dot), hide_style(); }
	void dash_pressed() { change_s(Line_style::dash), hide_style(); }
	void solid_pressed() { change_s(Line_style::solid), hide_style(); }

	void next();
	void quit();

	/*
	static void cb_red(Address, Address);
	static void cb_blue(Address, Address);
	static void cb_black(Address, Address);
	static void cb_menu(Address, Address);
	static void cb_next(Address, Address);
	static void cb_quit(Address, Address);
	*/
};