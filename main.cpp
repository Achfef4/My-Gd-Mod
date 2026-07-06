#include <Geode/Geode.hpp>
#include <Geode/modify/LevelListLayer.hpp>

using namespace geode::prelude;

class $modify(LevelListLayer) {
    bool init(GJLevelList* list) {
        if (!LevelListLayer::init(list)) return false;

        // 1. إخفاء وحذف زر SELECT القديم تماماً لكي يختفي من الشاشة
        auto menu = this->getChildByID("select-menu");
        if (menu) {
            auto oldSelectBtn = menu->getChildByID("select-button");
            if (oldSelectBtn) {
                oldSelectBtn->setVisible(false); 
            }

            // 2. صناعة زر VIEW جديد بالكامل باللون الزهري الفخم بدلاً منه بدون تعديل على الصور
            auto viewLabel = CCLabelBMFont::create("VIEW", "bigFont.fnt");
            if (viewLabel) {
                viewLabel->setScale(0.6f);
                viewLabel->setColor({255, 105, 180}); // لون زهري فخم

                auto viewBtn = CCMenuItemSpriteExtra::create(
                    viewLabel, this, menu_selector(LevelListLayer::onPlay)
                );
                viewBtn->setID("achfef-view-button");
                menu->addChild(viewBtn);
                menu->updateLayout();
            }
        }

        // 3. إضافة زر اللعب الدائري (المثلث داخل الدائرة) داخل شاشة الـ VIEW
        auto playMenu = CCMenu::create();
        if (playMenu) {
            auto playSpr = CCSprite::createWithSpriteFrameName("GJ_playBtn_001.png");
            if (playSpr) {
                auto playBtn = CCMenuItemSpriteExtra::create(
                    playSpr, this, menu_selector(LevelListLayer::onPlay)
                );
                playBtn->setID("achfef-play-button");
                playMenu->addChild(playBtn);
                playMenu->setPosition({450, 160});
                playMenu->setID("achfef-play-menu");
                this->addChild(playMenu);
            }
        }

        // 4. تعديل النص الأبيض عند عدم وجود قوائم (lists) نهائياً
        auto noListsLabel = cocos2d::dynamic_cast<CCLabelBMFont*>(this->getChildByID("no-lists-label"));
        if (noListsLabel) {
            noListsLabel->setString("ما عندك levels داخل الlist");
        }

        // 5. تعديل النص داخل القائمة إذا كانت فارغة بالإنجليزية وبدون إيموجي
        auto noLevelsLabel = cocos2d::dynamic_cast<CCLabelBMFont*>(this->getChildByID("no-levels-label"));
        if (noLevelsLabel) {
            noLevelsLabel->setString("This list is empty. Add some levels to get started.");
        }

        return true;
    }
};
