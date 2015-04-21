#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "glm.hpp"
#include "mouse_event.hpp"
#include "key_event.hpp"

class GuiWindow;
class Gui;

class Widget {
public:
    Widget(GuiWindow *gui_window);
    virtual ~Widget();
    virtual void draw(const glm::mat4 &projection) = 0;

    // default no minimum, no maximum
    virtual int min_width() const { return 0; }
    virtual int max_width() const { return -1; }
    virtual int min_height() const { return 0; }
    virtual int max_height() const { return -1; }

    // call when one of the above 4 functions values will be different
    void on_size_hints_changed();

    virtual void on_mouse_move(const MouseEvent *) {}
    virtual void on_mouse_out(const MouseEvent *) {}
    virtual void on_mouse_over(const MouseEvent *) {}
    virtual void on_gain_focus() {}
    virtual void on_lose_focus() {}
    virtual void on_text_input(const TextInputEvent *event) {}
    virtual void on_key_event(const KeyEvent *) {}
    virtual void on_mouse_wheel(const MouseWheelEvent *) {}
    virtual void on_resize() {}
    virtual void remove_widget(Widget *widget);


    GuiWindow *gui_window;
    Widget *parent_widget;
    Gui *gui;

    int left;
    int top;
    int width;
    int height;

    // index into gui_window's set of widgets
    int set_index;
    // index into grid layout widget parent, if any
    int layout_row;
    int layout_col;
    bool is_visible;
};

#endif
