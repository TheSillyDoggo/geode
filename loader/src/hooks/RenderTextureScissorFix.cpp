#include <Geode/DefaultInclude.hpp>
#include <Geode/modify/CCEGLView.hpp>

using namespace geode::prelude;

class $modify (CCEGLView)
{
    virtual void setScissorInPoints(float x , float y , float w , float h)
    {
        if (CCKeyboardDispatcher::get()->getShiftKeyPressed())
        {
            GLint viewport[4];
            glGetIntegerv(GL_VIEWPORT, viewport);

            #ifdef GEODE_IS_WINDOWS
            float zoomFactor = m_fFrameZoomFactor;
            #endif

            #ifdef GEODE_IS_MAC
            float zoomFactor = CCEAGLView::sharedEGLView()->frameZoomFactor_;
            #endif

            float multWidth = viewport[2] / (m_obScreenSize.width * zoomFactor);
            float multHeight = viewport[3] / (m_obScreenSize.height * zoomFactor);

            x *= multWidth;
            y *= multHeight;
            w *= multWidth;
            h *= multHeight;
        }

        CCEGLView::setScissorInPoints(x, y, w, h);
    }
};