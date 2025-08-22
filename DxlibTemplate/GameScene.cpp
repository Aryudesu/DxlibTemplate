// GameScene.h
#pragma once
#include "SceneBase.h"
#include "GameScene.h"
#include "Ids.h"
#include "DxLib.h"

void GameScene::Start() {
}

void GameScene::End() {
}

void GameScene::Update() {
    if (CheckHitKey(KEY_INPUT_ESCAPE)) next_ = SceneID::Quit;
    if (CheckHitKey(KEY_INPUT_RETURN)) next_ = SceneID::Title;
}

void GameScene::Draw() {
    DrawString(32, 32, "Gamee: ENTER->Title, ESC->Quit", GetColor(255, 255, 255));
}

bool GameScene::IsEnd() const { return next_ != SceneID::Game; }
SceneID GameScene::NextScene() { return next_; }
