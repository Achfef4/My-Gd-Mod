#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
using namespace geode::prelude;
class $modify(PauseLayer) {
    void customSetup() {
        PauseLayer::customSetup();
        auto menu = this->getChildByID("left-button-menu");
        if (!menu) return;
        auto btn = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_plusBtn_001.png"), 
            this, menu_selector(PauseLayer::onSettings)
        );
        menu->addChild(btn);
        menu->updateLayout();
    }
};
