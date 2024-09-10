#include <auby.hh>

// GEODE UTILS

// Cocos2d utils
namespace cocos_utils {
    /**
     * Get child at index. Checks bounds. A negative
     * index will get the child starting from the end
     * @returns Child at index cast to the given type,
     * or nullptr if index exceeds bounds
     */
    template <class T = CCNode>
    static T* getChild(CCNode* x, int i) {
        // start from end for negative index
        if (i < 0) i = x->getChildrenCount() + i;
        // check if backwards index is out of bounds
        if (i < 0) return nullptr;
        // check if forwards index is out of bounds
        if (static_cast<int>(x->getChildrenCount()) <= i) return nullptr;
        return static_cast<T*>(x->getChildren()->objectAtIndex(i));
    }

    /**
     * Get nth child that is a given type. Checks bounds.
     * @returns Child at index cast to the given type,
     * or nullptr if index exceeds bounds
     */
    template <class Type = CCNode>
    static Type* getChildOfType(CCNode* node, int index) {
        size_t indexCounter = 0;
        if (node->getChildrenCount() == 0) return nullptr;
        // start from end for negative index
        if (index < 0) {
            index = -index - 1;
            for (size_t i = node->getChildrenCount() - 1; i >= 0; i--) {
                auto obj = cast::typeinfo_cast<Type*>(node->getChildren()->objectAtIndex(i));
                if (obj != nullptr) {
                    if (indexCounter == index) {
                        return obj;
                    }
                    ++indexCounter;
                }
                if (i == 0) break;
            }
        }
        else {
            for (size_t i = 0; i < node->getChildrenCount(); i++) {
                auto obj = cast::typeinfo_cast<Type*>(node->getChildren()->objectAtIndex(i));
                if (obj != nullptr) {
                    if (indexCounter == index) {
                        return obj;
                    }
                    ++indexCounter;
                }
            }
        }

        return nullptr;
    }
}