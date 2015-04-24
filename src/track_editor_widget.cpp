#include "track_editor_widget.hpp"
#include "project.hpp"
#include "color.hpp"
#include "gui_window.hpp"
#include "label.hpp"

TrackEditorWidget::TrackEditorWidget(GuiWindow *gui_window, Project *project) :
    Widget(gui_window),
    project(project),
    padding_top(0),
    padding_bottom(0),
    padding_left(0),
    padding_right(0),
    timeline_height(24),
    track_head_width(90),
    track_height(60),
    track_name_label_padding_left(4),
    track_name_label_padding_top(4),
    track_name_color(color_dark_text()),
    track_head_bg_color(color_light_bg()),
    track_main_bg_color(color_dark_bg()),
    timeline_bg_color(color_dark_bg_alt())
{
    update_model();
}

TrackEditorWidget::~TrackEditorWidget() {
    for (int i = 0; i < tracks.length(); i += 1) {
        destroy(tracks.at(i), 1);
        destroy_gui_track(tracks.at(i));
    }
}

void TrackEditorWidget::draw(const glm::mat4 &projection) {
    gui_window->fill_rect(timeline_bg_color, projection * timeline_model);

    for (int i = 0; i < tracks.length(); i += 1) {
        GuiTrack *gui_track = tracks.at(i);
        gui_window->fill_rect(track_head_bg_color, projection * gui_track->head_model);
        gui_window->fill_rect(track_main_bg_color, projection * gui_track->body_model);
        gui_track->track_name_label->draw(
                gui_window, projection * gui_track->track_name_label_model, track_name_color);
    }
}

void TrackEditorWidget::update_model() {
    int timeline_top = padding_top;
    timeline_model = transform2d(padding_left, padding_top,
            width - padding_left - padding_right, timeline_height);

    int next_top = timeline_top + timeline_height;
    for (int i = 0; i < project->track_list.length(); i += 1) {
        Track *track = project->track_list.at(i);
        GuiTrack *gui_track;
        if (i < tracks.length()) {
            gui_track = tracks.at(i);
        } else {
            gui_track = create_gui_track(track);
            ok_or_panic(tracks.append(gui_track));
        }

        // update the track data
        int head_left = padding_left;
        int head_top = next_top;
        next_top += track_height;
        gui_track->head_model = transform2d(padding_left, head_top, track_head_width, track_height);

        int body_left = head_left + track_head_width;
        int body_width = width - padding_right - body_left;
        gui_track->body_model = transform2d(body_left, head_top, body_width, track_height);

        gui_track->track_name_label->set_text(track->name);
        gui_track->track_name_label->update();
        int label_left = head_left + track_name_label_padding_left;
        int label_top = head_top + track_name_label_padding_top;
        gui_track->track_name_label_model = transform2d(label_left, label_top);
    }
}

TrackEditorWidget::GuiTrack * TrackEditorWidget::create_gui_track(Track *track) {
    GuiTrack *gui_track = create<GuiTrack>();
    gui_track->track = track;
    gui_track->track_name_label = create<Label>(gui_window->_gui);
    return gui_track;
}

void TrackEditorWidget::destroy_gui_track(GuiTrack *gui_track) {
    if (gui_track) {
        destroy(gui_track->track_name_label, 1);
        destroy(gui_track, 1);
    }
}