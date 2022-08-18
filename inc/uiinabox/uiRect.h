#ifndef UIINABOX_UIRECT_H
#define UIINABOX_UIRECT_H

#include "raylib.h"
#include "uiinabox/apidecl.h"
#include "uiinabox/uiPoint.h"
#include "uiinabox/uiSize.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

struct uiRect
{
   uiPoint topLeft;
   uiSize size;
};
typedef struct uiRect uiRect;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define make_rect_ui_( X, Y, W, H )                                            \
(                                                                              \
   (uiRect){ .topLeft=point_ui_( (X), (Y) ), .size=size_ui_( (W), (H) ) }      \
)

#define rect_ui_( TopLeft, Size )                                              \
(                                                                              \
   (uiRect){ .topLeft=(TopLeft), .size=(Size) }                                \
)

UIINABOX_API inline uiRect screen_rect_ui( void )
{
   return rect_ui_( top_left_corner_ui_(), screen_size_ui() );
}

/*******************************************************************************

*******************************************************************************/

UIINABOX_API void draw_rect_ui( uiRect rect, Color color );

#endif