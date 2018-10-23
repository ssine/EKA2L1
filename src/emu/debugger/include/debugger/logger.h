#pragma once

#include <common/log.h>

#include <imgui.h>
#include <mutex>

namespace eka2l1 {
    struct imgui_logger {
        ImGuiTextBuffer     buf;
        ImGuiTextFilter     filter;
        ImVector<int>       line_offsets;        // Index to lines offset
        bool                scroll_to_bottom;

        std::mutex log_mut;

        void clear();
        void log(const char* fmt, ...);
        void draw(const char *title, bool* p_opened = nullptr);
    };
}