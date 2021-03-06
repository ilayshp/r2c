#
# Copyright 2020 - present Isotropix SAS. See License.txt for license information
#

set (SOURCES
    main.cc
    layer_r2c_scene.cc
)

set (CID_FILES
    layer_r2c_scene.cid
)

set (CID_DEPENDS
    layer_scene
)

add_clarisse_module (layer_r2c_scene
    "${SOURCES}"
    ""
    "${CID_FILES}"
    "${CID_DEPENDS}"
)

ix_setup_properties (layer_r2c_scene)

target_include_directories (layer_r2c_scene
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries (layer_r2c_scene
    PRIVATE
        # helper library
        ix_r2c

        # Clarisse SDK
        ${CLARISSE_IX_CORE_LIBRARY}
        ${CLARISSE_IX_IMAGE_LIBRARY}
        ${CLARISSE_IX_MODULE_LIBRARY}
        ${CLARISSE_IX_OF_LIBRARY}
        ${CLARISSE_IX_RESOURCE_LIBRARY}
)
