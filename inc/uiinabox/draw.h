#ifndef UIINABOX_DRAW_H
#define UIINABOX_DRAW_H

#include "clingo/type/cChars.h"
#include "clingo/type/cRune.h"
#include "clingo/type/int32.h"
#include "uiinabox/apidecl.h"
#include "uiinabox/uiFont.h"
#include "uiinabox/uiPoint.h"

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

UIINABOX_API void draw_text_ui( cChars text, uiPoint topLeft, uiFont const* font );

UIINABOX_API void draw_rune_ui( cRune rune, uiPoint topLeft, uiFont const* font );

#endif