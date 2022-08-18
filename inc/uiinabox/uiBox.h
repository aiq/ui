#ifndef UIINABOX_UIBOX_H
#define UIINABOX_UIBOX_H

#include "clingo/container/vec.h"
#include "clingo/lang/CObject.h"
#include "clingo/string/CString.h"
#include "uiinabox/apidecl.h"
#include "uiinabox/content/uiContent.h"
#include "uiinabox/uiRect.h"
#include "uiinabox/uiStyle.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 type
*******************************************************************************/

struct uiBox
{
   uiRect rect;
   uiStyle* style;
//   UIBoxVec* children;
   uiContent* content;
};
typedef struct uiBox uiBox;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

UIINABOX_API uiBox* box_ui( uiStyle const* style, uiContent* cnt );

UIINABOX_API uiBox* none_ui( void );

#define row_ui_( Style, ... )                                                  \
   row_ui( (Style), nargs_c_( __VA_ARGS__ ), __VA_ARGS__ )
UIINABOX_API uiBox* row_ui( uiStyle const* style, int n, ... );

#define column_ui_( Style, ... )                                               \
   column_ui( (Style), nargs_c_( __VA_ARGS__ ), __VA_ARGS__ )
UIINABOX_API uiBox* column_ui( uiStyle const* style, int n, ... );

UIINABOX_API uiBox* text_ui( uiStyle const* style, CString* str );

/*******************************************************************************

*******************************************************************************/

UIINABOX_API bool custom_layout_ui( uiRect rect, uiBox* box );

UIINABOX_API bool layout_ui( uiBox* box );

UIINABOX_API void draw_ui( uiBox const* box );

#endif