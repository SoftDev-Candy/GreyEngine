//
// Created by Candy on 12/17/2025.
//

#ifndef B_WENGINE_ENGINEWIDGETS_HPP
#define B_WENGINE_ENGINEWIDGETS_HPP
#include <iostream>

namespace UI {
    void BeginDockspaceAndTopBar();           // glass frame on top
    bool SliderFloatMolten(const char* label, float* v, float v_min, float v_max);
    void BeginMoltenInput();                  // black bg + molten text
    void EndMoltenInput();
    void BeginTransformStyle();
    void EndTransformStyle();
    bool InputTextLava(const char* id, char* buf, size_t bufSize);
    // Optional but best for "text turns orange when active"
    bool DragFloat3Lava(const char* label, float* v, float speed = 0.01f);

}

class EditorWidgets
{
};


#endif //B_WENGINE_ENGINEWIDGETS_HPP