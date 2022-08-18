#ifndef UIINABOX_UIBORDER_H
#define UIINABOX_UIBORDER_H

#include "raylib.h"
#include "uiinabox/uiFrame.h"
#include "uiinabox/uiRect.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************

*******************************************************************************/

enum ui_BorderStyle
{
   ui_NoBorder,
   ui_SolidBorder,
   ui_DashedBorder,
   ui_DottedBorder
};
typedef enum ui_BorderStyle ui_BorderStyle;

struct uiBorder
{
   Color color;
   ui_BorderStyle style;
   uiFrame frame;
};
typedef struct uiBorder uiBorder;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define border_ui_( Col, Style, Val )                                          \
(                                                                              \
   (uiBorder){ .color=(Col), .style=(Style), .frame=frame_ui_( Val ) }         \
)

#define border_xy_ui_( Col, Style, X, Y )                                      \
(                                                                              \
   (uiBorder){ .color=(Col), .style=(Style), .frame=frame_xy_ui_( (X), (Y) ) } \
)

#define full_border_ui_( Col, Style, Top, Right, Bottom, Left )                \
(                                                                              \
   (uiBorder){                                                                 \
      .color=(Col),                                                            \
      .style=(Style),                                                          \
      .frame=full_frame_ui_( (Top), (Right), (Bottom), (Left) )                \
   }                                                                           \
)

#define no_border_ui_()                                                        \
(                                                                              \
   (uiBorder){ .color=BLANK, .style=ui_NoBorder, .frame=no_frame_ui_() }       \
)

/*******************************************************************************

*******************************************************************************/

UIINABOX_API void draw_border_ui( uiRect rect, uiBorder border );

#endif