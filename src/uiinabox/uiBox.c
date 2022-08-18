#include "uiinabox/uiBox.h"

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

uiBox* box_ui( uiStyle const* style, uiContent* cnt )
{
   return NULL;
}

uiBox* none_ui( void )
{
   return NULL;
}

uiBox* row_ui( uiStyle const* style, int n, ... )
{
   return NULL;
}

uiBox* column_ui( uiStyle const* style, int n, ... )
{
   return NULL;
}

uiBox* text_ui( uiStyle const* style, CString* str )
{
   return NULL;
}

/*******************************************************************************

*******************************************************************************/

bool custom_layout_ui( uiRect rect, uiBox* box )
{
   return false;
}

bool layout_ui( uiBox* box )
{
   return custom_layout_ui( screen_rect_ui(), box );
}

void draw_ui( uiBox const* box )
{
   draw_rect_ui( box->rect, box->style->background.color );
   //DrawRectangleV( box->topLeft.x, box->topLeft.y, box->size.w, box->size.h, GOLD );
}