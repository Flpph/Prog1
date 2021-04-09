/*
    g++ drill12.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill12 `fltk-config --ldflags --use-images`
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

    Circle c {Point{100,200},50};
    Ellipse e {Point{100,200},75,25};
    e.set_color(Color::red);
    Mark m {Point{100,200},'x'};

    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max()
        << "; window size: " << win.x_max() << "*" << win.y_max();
    Text sizes {Point{100,20},oss.str()};

    win.attach(ii);
	win.attach(xa);
	win.attach(ya);
	win.attach(sine);
	win.attach(poly);
	win.attach(r);
	win.attach(poly_rect);
	win.attach(t);
    win.attach(sizes);
    win.attach(c);
    win.attach(e);
    win.attach(m);
    win.wait_for_button();
}
