#ifndef UIINABOX_CONTENT_UICONTENT_H
#define UIINABOX_CONTENT_UICONTENT_H

#include "uiinabox/uiRect.h"
#include "uiinabox/uiStyle.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

struct uiContent;
typedef struct uiContent uiContent;

typedef uiSize ( *ui_content_size )( uiStyle const* style, uiContent const* cnt );

typedef void ( *ui_draw_content )( uiStyle const* style, uiContent const* cnt, uiRect where, uiRect what );

struct uiContentType
{
   char const* desc;
   ui_content_size size;
   ui_draw_content draw;
};
typedef struct uiContentType uiContentType;

typedef void uiContentData;

struct uiContent
{
   uiContentType const* type;
   uiContentData* data;
};

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/



#endif