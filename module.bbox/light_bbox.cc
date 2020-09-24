//
// Copyright 2020 - present Isotropix SAS. See License.txt for license information
//
#include <of_object.h>
#include "module_light_bbox.h"

#include "light_bbox.cma"

#if ISOTROPIX_VERSION_NUMBER >= IX_BUILD_VERSION_NUMBER(4, 0, 2, 0, 0, 0)
#define MODULE_CLASS OfModule
#else
#define MODULE_CLASS ModuleObject
#endif

class ModuleLightBboxCallbackOverrides : public ModuleLightBboxCallbacks {
public:
    static GMathVec3f evaluate(OfObject& object)
    {
        return GMathVec3f(object.get_attribute("color")->get_vec3d());
    }
};

// WARNING: do not remove this typedef, it is needed by the macro IX_CREATE_MODULE_CLBK
typedef ModuleLightBboxCallbackOverrides IX_MODULE_CLBK;

namespace LightBbox
{
    void on_register(OfApp& app, CoreVector<OfClass *>& new_classes)
    {
        OfClass *new_class = IX_DECLARE_MODULE_CLASS(ModuleLightBbox);
        new_classes.add(new_class);

        IX_MODULE_CLBK *module_callbacks;
        IX_CREATE_MODULE_CLBK(new_class, module_callbacks)

        module_callbacks->cb_evaluate = IX_MODULE_CLBK::evaluate;
    }
}