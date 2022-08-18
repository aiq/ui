#ifndef UIINABOX_UISTYLE_H
#define UIINABOX_UISTYLE_H

#include "uiinabox/apidecl.h"
#include "uiinabox/uiBackground.h"
#include "uiinabox/uiBorder.h"
#include "uiinabox/uiFont.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************

*******************************************************************************/

enum ui_AlignmentX
{
   ui_DefaultX,
   ui_AlignLeft,
   ui_CenterX,
   ui_AlignRight
};
typedef enum ui_AlignmentX ui_AlignmentX;

enum ui_AlignmentY
{
   ui_DefaultY,
   ui_AlignTop,
   ui_CenterY,
   ui_AlignBottom
};
typedef enum ui_AlignmentY ui_AlignmentY;

struct uiStyle
{
   ui_AlignmentX alignmentX;
   ui_AlignmentY alignmentY;
   uiBackground background;
   uiBorder border;
   int spacing;
   int padding;
   int length;
   uiFont font;
};
typedef struct uiStyle uiStyle;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#endif