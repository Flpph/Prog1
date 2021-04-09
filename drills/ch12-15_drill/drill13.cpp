/*
    g++ drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    //Ez a kettő az ablak méretét állítja.
    //	Szélesség	Magasság
    int xmax = 800, ymax = 1000;
    

    Simple_window win {Point{100,100}, xmax, ymax, "My window"};

    constexpr int grid_size = 100;
    constexpr int grid_max = 800;

    Lines grid;
    for (int x=grid_size; x<=grid_max; x+=grid_size)
    {
        grid.add(Point{x,0},Point{x,grid_max});
        grid.add(Point{0,x},Point{grid_max,x});
    }
    win.attach(grid);
    
    Vector_ref<Rectangle> vr;
    for (int i = 0; i < 8; ++i)
    {
        vr.push_back(new Rectangle(Point{i*grid_size, i*grid_size}, grid_size, grid_size));
        vr[vr.size()-1].set_fill_color(Color::red);
        win.attach(vr[vr.size()-1]);
    }
    
    Vector_ref<Image> vi;

    vi.push_back(new Image(Point{0,200}, "badge.jpg"));
    vi.push_back(new Image(Point{0,400}, "badge.jpg"));
    vi.push_back(new Image(Point{0,600}, "badge.jpg"));

    constexpr int image_size = 200;

    for (int i = 0; i < vi.size(); ++i)
    {
        vi[i].set_mask(Point{100,100}, image_size, image_size);
        win.attach(vi[i]);
    }

    Image logo(Point{0,0}, "logo.jpg");

    win.attach(logo);

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            win.wait_for_button();
            if (j < 7) logo.move(100,0);
            else logo.move(-700,100);
        }
    }
}
