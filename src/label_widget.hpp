#ifndef LABEL_WIDGET_HPP
#define LABEL_WIDGET_HPP

#include "string.hpp"
#include "label.hpp"
#include "glm.hpp"
#include "gui.hpp"

class LabelWidget {
public:
    LabelWidget(Gui *gui, int gui_index);
    ~LabelWidget() {}
    LabelWidget(const LabelWidget &copy) = delete;
    LabelWidget &operator=(const LabelWidget &copy) = delete;

    void set_text(const String &text) {
        _label.set_text(text);
        _label.update();
    }

    void set_font_size(int size) {
        _label.set_font_size(size);
        _label.update();
    }

    void set_pos(int new_left, int new_top) {
        _left = new_left;
        _top = new_top;
        update_model();
    }

    int left() const {
        return _left;
    }

    int top() const {
        return _top;
    }

    int width() const;
    int height() const;

    void set_width(int new_width);

    void set_auto_size(bool value);

    void draw(const glm::mat4 &projection);

    bool is_visible() const {
        return _is_visible;
    }

    void set_selection(int start, int end);

    bool have_focus() {
        return _have_focus;
    }

    void select_all();
    void cut();
    void copy();
    void paste();

    void on_mouse_over(const MouseEvent &event);
    void on_mouse_out(const MouseEvent &event);
    void on_mouse_move(const MouseEvent &event);
    void on_gain_focus();
    void on_lose_focus();
    void on_text_input(const TextInputEvent &event);
    void on_key_event(const KeyEvent &event);

    int _gui_index;

private:
    Label _label;
    int _left;
    int _top;
    glm::mat4 _label_model;
    glm::mat4 _bg_model;

    bool _is_visible;
    int _padding_left;
    int _padding_right;
    int _padding_top;
    int _padding_bottom;
    glm::vec4 _text_color;
    glm::vec4 _sel_text_color;
    glm::vec4 _background_color;
    glm::vec4 _selection_color;
    glm::vec4 _cursor_color;
    bool _auto_size;

    Gui *_gui;

    int _cursor_start;
    int _cursor_end;
    bool _select_down;

    glm::mat4 _sel_model;
    glm::mat4 _cursor_model;
    glm::mat4 _sel_text_model;

    bool _have_focus;

    // used when _auto_size is false
    int _width;

    bool _cursor_visible;

    void update_model();

    int cursor_at_pos(int x, int y) const;
    void pos_at_cursor(int index, int &x, int &y) const;
    void get_cursor_slice(int &start, int &end) const;
    void update_selection_model();
    void replace_text(int start, int end, const String &text, int cursor_modifier);
    int backward_word();
    int forward_word();
    int advance_word(int dir);
};

#endif