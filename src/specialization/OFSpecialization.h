#pragma once

#include "choreograph/Sequence.hpp"
#include "ofQuaternion.h"
#include "ofColor.h"
///Specialization of lerpT for openFrameworks.
///ofQuaternion,ofColor,ofFloatColor and ofShortColor.
namespace  choreograph
{
    template<>
    inline ofQuaternion lerpT( const ofQuaternion &start, const ofQuaternion &end, float time )
    {
        ofQuaternion ret;
        ret.slerp(time, start, end);
        ret.normalize();
        return ret;
    }
#define LERP_COLOR(TYPE)\
template<>\
inline TYPE lerpT(const TYPE & start, const TYPE & end, float time){\
return start.getLerped(end, time);}
    LERP_COLOR(ofColor)
    LERP_COLOR(ofFloatColor)
    LERP_COLOR(ofShortColor)
#undef LERP_COLOR

#define LERP_COLOR_PROPERTY(TYPE)\
template<>\
inline TYPE lerpT(const TYPE & start, const TYPE & end, float time){\
return start.get().getLerped(end.get(), time);}
    LERP_COLOR_PROPERTY(ofParameter<ofColor>)
    LERP_COLOR_PROPERTY(ofParameter<ofFloatColor>)
    LERP_COLOR_PROPERTY(ofParameter<ofShortColor>)
#undef LERP_COLOR_PROPERTY

} // namespace choreograph
