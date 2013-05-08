#ifndef _SCROLL_BAR_H_
#define _SCROLL_BAR_H_

#include "cocos2d.h"
#include "DisplayObject.h"
#include "BgSprite.h"
USING_NS_CC;

class FjScrollBar : public CCNode, public DisplayObject {
public:
static const int TagSlideBar = 1;
static const int TagbgBar = 2;

void setWidth(float value);
void setHeight(float value);
float getWidth();
float getHeight();

void setX(float value);
void setY(float value);
float getX();
float getY();

FjScrollBar();
//void init(DisplayObject* bg, DisplayObject* bar);
void init(DisplayObject* _bg, DisplayObject* _bar) 
{
    CCNode* aaa = (CCNode*)(&_bg);
    this->addChild(aaa);
} 

private:

~FjScrollBar(void);

DisplayObject* bg;
DisplayObject* bar;
int value;
int dragHeight;
float width;
float height;
void setBarHeight(float val1, float val2);
void setValue(float value);
float getValue();

};
#endif 
