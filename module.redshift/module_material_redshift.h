//
// Copyright 2020 - present Isotropix SAS. See License.txt for license information
//

#ifndef MODULE_MATERIAL_REDSHIFT_H
#define MODULE_MATERIAL_REDSHIFT_H

#include <module_material.h>

class RSMaterial;

class OfObject;

/*! \class ModuleMaterialRedshift
    \brief This class implements the Redshift Material abstract class in Clarisse. */
class ModuleMaterialRedshift : public ModuleMaterial {
public:

    ModuleMaterialRedshift();
    virtual ~ModuleMaterialRedshift() override;

    /*! \brief return the Redshift material attached to the Clarisse material item.
     * \note The material is automatically synched. */
    inline RSMaterial *get_material() { return m_material; }

    /* \brief set the Redshift material attached to the Clarisse material item.
     * \note It is not intended to be used except for particular case, 
     * if you want to use this method, the result won't match the attributes values of the Clarisse material item. */
	inline void set_material(RSMaterial *material) { m_material = material; }

    /*! \brief return a Clarisse UI style name from the specified Redshift shader class name.
     * \param class_name Redshift shader class name. */
    static CoreString mangle_class(const CoreString& class_name);

protected:

    /*! \brief Perform some connections to event when the instance is created to track rename event notably
     * \param object Clarisse material instance. */
    void module_constructor(OfObject& object) override;
    /*! \brief Synchronizing Redshift material shader to the new Clarisse attribute value when changed */
    void on_attribute_change(const OfAttr& attr, int& dirtiness, const int& dirtiness_flags) override;
    /*! \brief Synchronizing Redshift material shader name when the item in Clarisse is renamed
     *  \note This could be important for cryptomatte for example */
    void on_material_rename(OfObject& object, const EventInfo& evtid, void *data);

private:

    ModuleMaterialRedshift(const ModuleMaterialRedshift&) = delete;
    ModuleMaterialRedshift& operator=(const ModuleMaterialRedshift&) = delete;

    CoreString m_shader_class_name;
    RSMaterial *m_material;
    DECLARE_CLASS
};

#endif
