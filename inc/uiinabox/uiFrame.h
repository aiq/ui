#ifndef UIINABOX_UIFRAME_H
#define UIINABOX_UIFRAME_H

#include "clingo/type/int32.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************

*******************************************************************************/

struct uiFrame
{
   int32_t top;
   int32_t right;
   int32_t bottom;
   int32_t left;
};
typedef struct uiFrame uiFrame;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define frame_ui_( Val )                                                       \
(                                                                              \
   (uiFrame){ .top=(Val), .right=(Val), .bottom=(Val), .left=(Val) }           \
)

#define frame_xy_ui_( X, Y )                                                   \
(                                                                              \
   (uiFrame){ .top=(Y), .right=(X), .bottom=(Y), .left=(X) }                   \
)

#define full_frame_ui_( Top, Right, Bottom, Left )                             \
(                                                                              \
   (uiFrame){ .top=(Top), .right=(Right), .bottom=(Bottom), .left=(Left) }     \
)

#define no_frame_ui_()                                                         \
(                                                                              \
   (uiFrame){ .top=0, .right=0, .bottom=0, .left=0 }                           \
)

#endif