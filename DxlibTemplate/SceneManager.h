#pragma once
#pragma once
#include <memory>
#include "SceneBase.h"
#include "Ids.h"

// ここで各具体シーンのヘッダをinclude
#include "TitleScene.h"

inline std::unique_ptr<SceneBase> CreateScene(SceneID id) {
    switch (id) {
    case SceneID::Title:  return std::make_unique<TitleScene>();
    default:              return nullptr;
    }
}
