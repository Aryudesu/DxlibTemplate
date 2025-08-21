// GameScene.h
#pragma once
#include "SceneBase.h"
#include "TitleScene.h"
#include "Ids.h"
#include "DxLib.h"

void TitleScene::Start() {
}
void TitleScene::End() {
}
void TitleScene::Update() {
    if (CheckHitKey(KEY_INPUT_ESCAPE)) { end_ = true; next_ = SceneID::Quit; }
}
void TitleScene::Draw() {
    DrawString(32, 32, "Game...", GetColor(255, 255, 255));
}
bool TitleScene::IsEnd() const { return end_; }
SceneID TitleScene::NextScene() { return next_; }
