#include <Geode/Geode.hpp>
#include <Geode/modify/CCDirector.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/GameObject.hpp>

using namespace geode::prelude;

double getRefreshRate() {
    static const double refreshRate = [] {
        DEVMODEA dm{};
        dm.dmSize = sizeof(dm);
        if (EnumDisplaySettingsA(nullptr, ENUM_CURRENT_SETTINGS, &dm)) {
            auto freq = dm.dmDisplayFrequency;
            if (dm.dmDisplayFlags & DM_INTERLACED) freq *= 2;
            return static_cast<double>(freq);
        }
        return 60.0;
    }();
    return refreshRate;
}

double gDeltaAccumulator = 0.0;
bool gModEnabled = true;
bool gOverrideFps = false;
int gTargetFps = 60;

class $modify(CCDirector) {
    void drawScene() {
        if (!gModEnabled || this->getTotalFrames() < 150)
            return CCDirector::drawScene();

        const double targetFps = gOverrideFps ? gTargetFps : getRefreshRate();
        const double targetDelta = 1.0 / targetFps;

        gDeltaAccumulator += this->getActualDeltaTime();

        if (gDeltaAccumulator >= targetDelta) {
            gDeltaAccumulator -= targetDelta;
            return CCDirector::drawScene();
        }

        if (!this->isPaused())
            this->getScheduler()->update(this->getDeltaTime());

        if (this->getNextScene())
            this->setNextScene();
    }
};

bool gNoParticles = false;

class $modify(GJBaseGameLayer) {
    cocos2d::CCParticleSystemQuad* spawnParticle(const char* plist, int z, cocos2d::tCCPositionType type, cocos2d::CCPoint pos) {
        if (gNoParticles) return nullptr;
        return GJBaseGameLayer::spawnParticle(plist, z, type, pos);
    }

#ifndef GEODE_IS_WINDOWS
    void playSpeedParticle(float speed) {
        if (gNoParticles) return;
        GJBaseGameLayer::playSpeedParticle(speed);
    }
#endif
};

class $modify(GameObject) {
    void playDestroyEffect() {
        if (gNoParticles) return;
        GameObject::playDestroyEffect();
    }

    cocos2d::CCParticleSystemQuad* createParticle() {
        if (gNoParticles) return nullptr;
        return GameObject::createParticle();
    }
};

bool gNoGlow = false;

class $modify(PlayLayer) {
    void addObject(GameObject* obj) {
        if (gNoGlow)
            obj->m_hasNoGlow = true;
        PlayLayer::addObject(obj);
    }
};

$on_mod(Loaded) {
    listenForSettingChanges("enable-mod", [](bool v) { gModEnabled = v; });
    listenForSettingChanges("override-visual-fps", [](bool v) { gOverrideFps = v; });
    listenForSettingChanges("visual-fps", [](int v) { gTargetFps = v; });
    listenForSettingChanges("no-particles", [](bool v) { gNoParticles = v; });
    listenForSettingChanges("no-glow", [](bool v) { gNoGlow = v; });
}
