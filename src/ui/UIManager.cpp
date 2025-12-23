//
// Created by Candy on 12/18/2025.
//

#include "UIManager.hpp"

#include "EditorWidgets.hpp"
#include "imgui_impl_opengl3.h"

void UIManager::Draw(Scene &scene, Camera &camera, int& selectedIndex,
                     std::function<Entity(const std::string &)> createCube)
{

ImGui::Begin("Scene Hierarchy");

    auto& objects = scene.GetObjects();
    for (int i =0;i<objects.size();i++)
    {
    bool clicked = ImGui::Selectable(objects[i].name.c_str(),selectedIndex == i);

        if (clicked)
        {
            selectedIndex = i;
        }

    }
    ImGui::End();
    ImGui::Begin("Camera FOV");
    UI::SliderFloatMolten("FOV", &camera.fov, 30.0f, 120.0f);
    ImGui::End();

    if (selectedIndex != -1)
    {
        auto& obj = scene.GetObjects()[selectedIndex];

        //Grab my object and add it to the UI, so I can manipulate it //
        ImGui::Begin("Inspector Panel");

if (ImGui::BeginTable("##InspectorForm", 2,
    ImGuiTableFlags_SizingFixedFit | ImGuiTableFlags_PadOuterX ))
{
    ImGui::TableSetupColumn("##Label", ImGuiTableColumnFlags_WidthFixed, 90.0f);
    ImGui::TableSetupColumn("##Value", ImGuiTableColumnFlags_WidthStretch);

    // ---------------------------
    // Name (Molten input)
    // ---------------------------
    UI::BeginMoltenInput();

    //Fixme: Changing name Context here need to change this later to something else//
    char changedBuffer[62] = "";
    strcpy(changedBuffer , obj.name.c_str());

    ImGui::TableNextRow();
    ImGui::TableSetColumnIndex(0);
    ImGui::AlignTextToFramePadding();
    ImGui::TextUnformatted("Name");

    ImGui::TableSetColumnIndex(1);
    ImGui::SetNextItemWidth(-FLT_MIN);

    bool changedName = ImGui::InputText("##Name", changedBuffer, sizeof(changedBuffer));
    if(changedName)
    {
        obj.name = changedBuffer;
    }

    UI::EndMoltenInput();

    // ---------------------------
    // Transform (Website-style boxes)
    // ---------------------------
    UI::BeginTransformStyle();

    //This is how we change the position
    ImGui::TableNextRow();
    ImGui::TableSetColumnIndex(0);
    ImGui::AlignTextToFramePadding();
    ImGui::TextUnformatted("Position");
    ImGui::TableSetColumnIndex(1);
    ImGui::SetNextItemWidth(-FLT_MIN);
    ImGui::DragFloat3("##Position", &obj.transform.position.x, 0.01f);

    //This is how we change the Rotation
    ImGui::TableNextRow();
    ImGui::TableSetColumnIndex(0);
    ImGui::AlignTextToFramePadding();
    ImGui::TextUnformatted("Rotation");
    ImGui::TableSetColumnIndex(1);
    ImGui::SetNextItemWidth(-FLT_MIN);
    ImGui::DragFloat3("##Rotation", &obj.transform.rotation.x, 0.01f);

    //This is how we scale it yo//
    ImGui::TableNextRow();
    ImGui::TableSetColumnIndex(0);
    ImGui::AlignTextToFramePadding();
    ImGui::TextUnformatted("Scale");
    ImGui::TableSetColumnIndex(1);
    ImGui::SetNextItemWidth(-FLT_MIN);
    ImGui::DragFloat3("##Scale", &obj.transform.scale.x, 0.01f);

    UI::EndTransformStyle();

    ImGui::EndTable();
}

ImGui::End();

    }

}
