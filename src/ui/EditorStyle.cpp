//
// Created by Candy on 12/17/2025.
//

#include "EditorStyle.hpp"
#include "imgui.h"

void EditorStyle::Apply()
{
    ImGui::StyleColorsDark();
    ImGuiStyle& style = ImGui::GetStyle();

    // Shape / spacing
    style.WindowRounding = 10.0f;
    style.FrameRounding  = 7.0f;
    style.ChildRounding  = 10.0f;
    style.PopupRounding  = 10.0f;
    style.GrabRounding   = 10.0f;
    style.ScrollbarRounding = 10.0f;

    style.WindowPadding = ImVec2(10, 10);
    style.FramePadding  = ImVec2(10, 6);
    style.ItemSpacing   = ImVec2(10, 8);

    style.WindowBorderSize = 1.0f;
    style.FrameBorderSize  = 1.0f;
    style.ScrollbarSize    = 14.0f;

    // Website lava palette (strong)
    const ImVec4 lava1 = ImVec4(0.957f, 0.486f, 0.282f, 1.00f); // #F47C48
    const ImVec4 lava2 = ImVec4(0.882f, 0.337f, 0.200f, 1.00f); // #E15633
    const ImVec4 lava3 = ImVec4(0.706f, 0.325f, 0.133f, 1.00f); // #B45322
    const ImVec4 hot1  = ImVec4(1.000f, 0.580f, 0.400f, 1.00f); // #FF9466
    const ImVec4 hot2  = ImVec4(0.961f, 0.384f, 0.239f, 1.00f); // #F5623D

    // Base
    const ImVec4 bg    = ImVec4(0.060f, 0.060f, 0.070f, 1.00f);
    const ImVec4 panel = ImVec4(0.120f, 0.120f, 0.130f, 1.00f); // no transparency (clean/pro)
    const ImVec4 text  = ImVec4(0.950f, 0.950f, 0.950f, 1.00f);
    const ImVec4 muted = ImVec4(0.700f, 0.700f, 0.720f, 1.00f);

    auto& styledColor = style.Colors;

    styledColor[ImGuiCol_Text]         = text;
    styledColor[ImGuiCol_TextDisabled] = ImVec4(muted.x, muted.y, muted.z, 0.65f);

    styledColor[ImGuiCol_WindowBg]  = bg;
    styledColor[ImGuiCol_ChildBg]   = panel;
    styledColor[ImGuiCol_PopupBg]   = ImVec4(0.140f, 0.140f, 0.150f, 0.98f);

    styledColor[ImGuiCol_Border]       = ImVec4(1,1,1,0.10f);
    styledColor[ImGuiCol_BorderShadow] = ImVec4(0,0,0,0.35f);

    // Make tab bar backgrounds black-ish (kills the "blue" feel)
    styledColor[ImGuiCol_TitleBg]           = ImVec4(0.06f, 0.06f, 0.07f, 1.00f);
    styledColor[ImGuiCol_TitleBgActive]     = ImVec4(0.06f, 0.06f, 0.07f, 1.00f);
    styledColor[ImGuiCol_TitleBgCollapsed]  = ImVec4(0.06f, 0.06f, 0.07f, 1.00f);
    styledColor[ImGuiCol_MenuBarBg]         = ImVec4(0.08f, 0.08f, 0.09f, 1.00f);

    // Frames / inputs
    styledColor[ImGuiCol_FrameBg]        = ImVec4(0.090f, 0.090f, 0.100f, 1.00f);
    styledColor[ImGuiCol_FrameBgHovered] = ImVec4(lava1.x, lava1.y, lava1.z, 0.32f); // stronger
    styledColor[ImGuiCol_FrameBgActive]  = ImVec4(lava2.x, lava2.y, lava2.z, 0.42f); // stronger

    // Buttons
    styledColor[ImGuiCol_Button]        = ImVec4(1,1,1,0.06f);
    styledColor[ImGuiCol_ButtonHovered] = ImVec4(lava1.x, lava1.y, lava1.z, 0.28f);
    styledColor[ImGuiCol_ButtonActive]  = ImVec4(lava2.x, lava2.y, lava2.z, 0.46f);

    // Headers (tree/list selections)
    styledColor[ImGuiCol_Header]        = ImVec4(1,1,1,0.06f);
    styledColor[ImGuiCol_HeaderHovered] = ImVec4(lava1.x, lava1.y, lava1.z, 0.26f);
    styledColor[ImGuiCol_HeaderActive]  = ImVec4(lava2.x, lava2.y, lava2.z, 0.40f);

    // Tabs
    // Tabs themselves (these are what you SEE in docking)
    styledColor[ImGuiCol_Tab]               = ImVec4(0.08f, 0.08f, 0.09f, 1.00f);  // idle tab
    styledColor[ImGuiCol_TabUnfocused]      = ImVec4(0.07f, 0.07f, 0.08f, 1.00f);  // unfocused dock
    styledColor[ImGuiCol_TabUnfocusedActive]= ImVec4(0.09f, 0.09f, 0.10f, 1.00f);  // active but unfocused
    // Lava on hover/active (strong, not transparent)
    styledColor[ImGuiCol_TabHovered]        = ImVec4(lava1.x, lava1.y, lava1.z, 0.65f); // TWEAK A
    styledColor[ImGuiCol_TabActive]         = ImVec4(lava2.x, lava2.y, lava2.z, 0.55f); // TWEAK B

    // Slider: WHITE grab
    styledColor[ImGuiCol_SliderGrab]       = ImVec4(1,1,1,0.95f);
    styledColor[ImGuiCol_SliderGrabActive] = ImVec4(1,1,1,1.00f);

    // Checks
    styledColor[ImGuiCol_CheckMark] = hot1;

    // Separators / resize grip (tiny but makes it feel coherent)
    styledColor[ImGuiCol_Separator]        = ImVec4(1,1,1,0.10f);
    styledColor[ImGuiCol_SeparatorHovered] = ImVec4(lava1.x, lava1.y, lava1.z, 0.28f);
    styledColor[ImGuiCol_SeparatorActive]  = ImVec4(lava2.x, lava2.y, lava2.z, 0.42f);

    styledColor[ImGuiCol_ResizeGrip]        = ImVec4(lava3.x, lava3.y, lava3.z, 0.18f);
    styledColor[ImGuiCol_ResizeGripHovered] = ImVec4(lava1.x, lava1.y, lava1.z, 0.26f);
    styledColor[ImGuiCol_ResizeGripActive]  = ImVec4(lava2.x, lava2.y, lava2.z, 0.40f);

    // Selection / nav
    styledColor[ImGuiCol_TextSelectedBg] = ImVec4(lava1.x, lava1.y, lava1.z, 0.32f);
    styledColor[ImGuiCol_NavHighlight]   = ImVec4(hot2.x,  hot2.y,  hot2.z,  0.38f);

    // --- Kill remaining default blue-ish overlays (docking + nav) ---
    styledColor[ImGuiCol_DockingPreview]        = ImVec4(lava2.x, lava2.y, lava2.z, 0.45f); // tweak 0.25..0.70
    styledColor[ImGuiCol_DragDropTarget]        = ImVec4(hot1.x,  hot1.y,  hot1.z,  0.95f);

    styledColor[ImGuiCol_NavWindowingHighlight] = ImVec4(lava1.x, lava1.y, lava1.z, 0.75f); // tweak 0.45..0.90
    styledColor[ImGuiCol_NavWindowingDimBg]     = ImVec4(0,0,0,0.60f);


    // Docking background
    styledColor[ImGuiCol_DockingEmptyBg] = bg;


}
