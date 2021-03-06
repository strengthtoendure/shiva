//
// Created by roman Sztergbaum on 30/08/2018.
//

#include <shiva/world/world_common_initializer.hpp>
#include "editor.hpp"

namespace shiva::editor
{
    editor::editor() noexcept
    {
        bool res = shiva::common::sfml_initializer(this->system_manager_);
        assert(res);
        system_manager_.load_systems<shiva::editor::widget_top_bar>(window_cfg_,
                                                                    system_manager_.get_system<shiva::scripting::lua_system>().get_state());
        system_manager_.prioritize_system(shiva::editor::widget_top_bar::class_name(), "render_system",
                                          shiva::ecs::system_type::post_update);
        system_manager_.prioritize_system("imgui_system", shiva::editor::widget_top_bar::class_name(),
                                          shiva::ecs::system_type::post_update);
    }
}
