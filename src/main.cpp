// Menu Sin Piso - por 5hut
// Oculta el piso del menu principal y baja/estira el fondo para que cubra
// toda la pantalla (sin la franja negra de abajo).
#include <Geode/Geode.hpp>
#include <Geode/modify/MenuGameLayer.hpp>

using namespace geode::prelude;

class $modify(SinPisoMenuGameLayer, MenuGameLayer) {
    // Oculta el piso (y opcionalmente la linea del horizonte).
    void ocultarPiso() {
        auto piso = m_groundLayer;
        if (!piso) return;

        auto mod = Mod::get();
        if (mod->getSettingValue<bool>("hide-ground")) {
            if (piso->m_ground1Sprite) piso->m_ground1Sprite->setVisible(false);
            if (piso->m_ground2Sprite) piso->m_ground2Sprite->setVisible(false);
            piso->hideShadows();
        }
        if (mod->getSettingValue<bool>("hide-line") && piso->m_lineSprite) {
            piso->m_lineSprite->setVisible(false);
        }
    }

    // Baja el borde inferior del fondo hasta y=0 y, si hace falta, lo estira
    // en vertical para que llegue hasta arriba.
    void extenderFondo() {
        if (!Mod::get()->getSettingValue<bool>("hide-ground")) return;
        auto fondo = m_backgroundSprite;
        if (!fondo) return;

        auto altoPantalla = CCDirector::get()->getWinSize().height;

        auto bordeInferior = [fondo]() {
            return fondo->getPositionY()
                - fondo->getAnchorPoint().y * fondo->getContentSize().height * fondo->getScaleY();
        };

        // 1) Estirar en vertical si el fondo no alcanza a cubrir la pantalla.
        float alto = fondo->getContentSize().height * fondo->getScaleY();
        if (alto > 1.f && alto < altoPantalla) {
            fondo->setScaleY(fondo->getScaleY() * (altoPantalla / alto));
        }

        // 2) Bajar el borde inferior hasta el fondo de la pantalla.
        float b = bordeInferior();
        if (b > 0.5f || b < -0.5f) {
            fondo->setPositionY(fondo->getPositionY() - b);
        }
    }

    bool init() {
        if (!MenuGameLayer::init()) return false;
        this->ocultarPiso();
        this->extenderFondo();
        return true;
    }

    // El juego reposiciona el fondo y el piso en cada cuadro, asi que se
    // reaplica despues de su actualizacion.
    void update(float dt) {
        MenuGameLayer::update(dt);
        this->ocultarPiso();
        this->extenderFondo();
    }
};
