#include <Geode/Geode.hpp>

#include <Geode/modify/EditButtonBar.hpp>
#include <Geode/modify/EditorUI.hpp>

using namespace geode::prelude;


EditorUI* editorUI = nullptr;

class $modify(EditorUI) {
	bool init(LevelEditorLayer* layer) {
		editorUI = this;
		geode::log::info("EditorUI init");
		if (!EditorUI::init(layer)) return false;
		return true;
	}
};

class $modify(EditButtonBar) {
	bool init(cocos2d::CCArray* objects, cocos2d::CCPoint p1, int id, bool p3, int p4, int p5) {
		if (editorUI) 
		{	
			if (id == 1) {
				auto obj = editorUI->getCreateBtn(40, 3);
				objects->addObject(obj);
			}
		}

		if (!EditButtonBar::init(objects, p1, id, p3, p4, p5)) return false;
		return true;
	};
};
