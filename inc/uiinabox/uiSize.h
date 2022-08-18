#ifndef UIINABOX_UISIZE_H
#define UIINABOX_UISIZE_H

#include "raylib.h"
#include "uiinabox/apidecl.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

struct uiSize
{
   float w;
   float h;
};
typedef struct uiSize uiSize;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define size_ui_( W, H )                                                       \
(                                                                              \
   (uiSize){ .w=(W), .h=(H) }                                                  \
)

UIINABOX_API inline uiSize screen_size_ui( void )
{
   int const w = GetScreenWidth();
   int const h = GetScreenHeight();
   return size_ui_( w, h );
}

#endif