#ifndef UIINABOX_UIFONT_H
#define UIINABOX_UIFONT_H

#include "clingo/type/int32.h"
#include "raylib.h"
#include "uiinabox/apidecl.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************

*******************************************************************************/

enum ui_TextAlignment
{
   ui_DefaultText,
   ui_LeftText,
   ui_RightText,
   ui_CenterText,
   ui_JustifyText
};
typedef enum ui_TextAlignment ui_TextAlignment;

typedef Font uiTypeFace;

struct uiFont
{
   uiTypeFace typeFace;
   ui_TextAlignment alingment;
   int32_t letterSpacing;
   int32_t wordSpacing;
   int32_t size;
   Color color;
};
typedef struct uiFont uiFont;

UIINABOX_API extern uiFont const UI_DefaultFont;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#endif