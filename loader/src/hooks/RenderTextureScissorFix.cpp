#include <Geode/DefaultInclude.hpp>
#include <Geode/modify/CCEGLView.hpp>

using namespace geode::prelude;

class $modify (CCEGLView)
{
    virtual void setScissorInPoints(float x, float y, float w, float h)
    {
        if (CCKeyboardDispatcher::get()->getShiftKeyPressed())
        {
            GLint viewport[4];
            glGetIntegerv(GL_VIEWPORT, viewport);

            float multWidth = viewport[2] / (m_obScreenSize.width * m_fFrameZoomFactor);
            float multHeight = viewport[3] / (m_obScreenSize.height * m_fFrameZoomFactor);

            x *= multWidth;
            y *= multHeight;
            w *= multWidth;
            h *= multHeight;
        }

        CCEGLView::setScissorInPoints(x, y, w, h);
    }
};