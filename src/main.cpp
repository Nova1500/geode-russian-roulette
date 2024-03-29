#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/binding/GameManager.hpp>
#include <Geode/binding/PlayLayer.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <random>

using namespace geode::prelude;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dis(1, 1000);

class $modify(PlayerObject) {
    public:
        TodoReturn pushButton(PlayerButton p0) {
            PlayerObject::pushButton(p0);
            if (p0 != PlayerButton::Jump) {
                return;
            }
            // check if random number is 69, from 1 to 1000
            // use c++11 random number generator
            // Generated by GitHub Copilot
            if (dis(gen) == 69) {
                PlayLayer *playLayer = PlayLayer::get();
                if (!playLayer) {
                    return;
                }
                playLayer->resetLevelFromStart();
            }
        }
};


