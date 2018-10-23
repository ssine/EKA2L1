/*
 * Copyright (c) 2018 EKA2L1 Team.
 * 
 * This file is part of EKA2L1 project 
 * (see bentokun.github.com/EKA2L1).
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <cstdint>
#include <memory>

struct MemoryEditor;

namespace eka2l1 {
    class system;

    class debugger {
        system *sys;

        bool should_show_threads;
        bool should_show_mutexs;
        bool should_show_chunks;
        
        bool should_pause;
        bool should_stop;
        bool should_load_state;
        bool should_save_state;
        bool should_install_package;
        bool should_show_memory;

        bool should_show_logger;

        void show_threads();
        void show_mutexs();
        void show_chunks();
        void show_timers();
        void show_disassembler();
        void show_menu();
        void show_memory();

        std::shared_ptr<MemoryEditor> mem_editor;

    public:
        explicit debugger(eka2l1::system *sys);

        void show_debugger(std::uint32_t width, std::uint32_t height
            , std::uint32_t fb_width, std::uint32_t fb_height);
    };
}