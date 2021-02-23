/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    //Ez a kettő az ablak méretét állítja.
    //	Szélesség	Magasság
    int xmax = 600, ymax = 400;
    

    Simple_window win {Point{100,100}, xmax, ymax, "My window"};

    Axis xa {Axis::x, Point{30,300}, 280, 10, "x axis"};
    Axis ya {Axis::y, Point{30,300}, 280, 10, "y axis"};

    Function sine {sin,0,100,Point{20,150},1000,50,50};

    Polygon poly;
    poly.add(Point{300,200});
    poly.add(Point{350,100});
    poly.add(Point{400,200});
    poly.set_color(Color::blue);
    poly.set_style(Line_style::dash);

    Rectangle r {Point{200,200}, 100, 50};
    r.set_fill_color(Color::yellow);

    Closed_polyline poly_rect;
    poly_rect.add(Point{100,50});
    poly_rect.add(Point{200,50});
    poly_rect.add(Point{100,100});
    poly_rect.add(Point{200,100});
    poly_rect.set_style(Line_style(Line_style::dash,2));
    poly_rect.set_fill_color(Color::blue);

    Text t {Point{150,150}, "Szel Attila!"};
    t.set_font(Font::times_bold);
    t.set_font_size(20);

    Image ii {Point{100,50},"Image.jpg"};

    win.attach(ii);
	win.attach(xa);
	win.attach(ya);
	win.attach(sine);
	win.attach(poly);
	win.attach(r);
	win.attach(poly_rect);
	win.attach(t);
    win.wait_for_button();
}
