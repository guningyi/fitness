#ifndef _DISPLAYOBJECT_H_
#define _DISPLAYOBJECT_H_

#include "cocos2d.h"

USING_NS_CC;

class DisplayObject{
public:
virtual void setWidth(float value) = NULL;
virtual void setHeight(float value) = NULL;
virtual float getWidth() = NULL;
virtual float getHeight() = NULL;

virtual void setX(float value) = NULL;
virtual void setY(float value) = NULL;
virtual float getX() = NULL;
virtual float getY() = NULL;
};

#endif 
