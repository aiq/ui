#include "uiinabox/draw.h"

#include "clingo/type/uint32.h"

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

void draw_text_ui( cChars text, uiPoint position, uiFont const* fontDef )
{
   if ( fontDef == NULL ) fontDef = &UI_DefaultFont;

   Font font = fontDef->typeFace;
   float fontSize = fontDef->size;
   float spacing = fontDef->letterSpacing;
   if (font.texture.id == 0) font = GetFontDefault();  // Security check in case of not valid font

    int textOffsetY = 0;            // Offset between lines (on line break '\n')
    float textOffsetX = 0.0f;       // Offset X to next character to draw

    float scaleFactor = fontSize/font.baseSize;         // Character quad scaling factor

    for (int i = 0; i < text.s;)
    {
        // Get next codepoint from byte string and glyph index in font
        int codepointByteCount = 0;
        int codepoint = GetCodepoint(&text.v[i], &codepointByteCount);
        int index = GetGlyphIndex(font, codepoint);

        // NOTE: Normally we exit the decoding sequence as soon as a bad byte is found (and return 0x3f)
        // but we need to draw all of the bad bytes using the '?' symbol moving one byte
        if (codepoint == 0x3f) codepointByteCount = 1;

        if (codepoint == '\n')
        {
            // NOTE: Fixed line spacing of 1.5 line-height
            // TODO: Support custom line spacing defined by user
            textOffsetY += (int)((font.baseSize + font.baseSize/2.0f)*scaleFactor);
            textOffsetX = 0.0f;
        }
        else
        {
            if ((codepoint != ' ') && (codepoint != '\t'))
            {
               draw_rune_ui( utf32_rune_c( uint32_c_(codepoint) ), (uiPoint){ position.x + textOffsetX, position.y + textOffsetY }, fontDef );
//               DrawTextCodepoint(font, codepoint, (Vector2){ position.x + textOffsetX, position.y + textOffsetY }, fontSize, tint);
            }

            if (font.glyphs[index].advanceX == 0) textOffsetX += ((float)font.recs[index].width*scaleFactor + spacing);
            else textOffsetX += ((float)font.glyphs[index].advanceX*scaleFactor + spacing);
        }

        i += codepointByteCount;   // Move text bytes counter to next codepoint
    }
}

//void draw_rune_ui(Font font, int codepoint, Vector2 position, float fontSize, Color tint)
void draw_rune_ui( cRune rune, uiPoint position, uiFont const* fontDef )
{
   uint32_t codepoint = rune_code_c( rune );
   Font font = fontDef->typeFace;
   float fontSize = fontDef->size;
   Color tint = fontDef->color;
    // Character index position in sprite font
    // NOTE: In case a codepoint is not available in the font, index returned points to '?'
    int index = GetGlyphIndex(font, int32_c_( codepoint ) );
    float scaleFactor = fontSize/font.baseSize;     // Character quad scaling factor

    // Character destination rectangle on screen
    // NOTE: We consider glyphPadding on drawing
    Rectangle dstRec = { position.x + font.glyphs[index].offsetX*scaleFactor - (float)font.glyphPadding*scaleFactor,
                      position.y + font.glyphs[index].offsetY*scaleFactor - (float)font.glyphPadding*scaleFactor,
                      (font.recs[index].width + 2.0f*font.glyphPadding)*scaleFactor,
                      (font.recs[index].height + 2.0f*font.glyphPadding)*scaleFactor };

    // Character source rectangle from font texture atlas
    // NOTE: We consider chars padding when drawing, it could be required for outline/glow shader effects
    Rectangle srcRec = { font.recs[index].x - (float)font.glyphPadding, font.recs[index].y - (float)font.glyphPadding,
                         font.recs[index].width + 2.0f*font.glyphPadding, font.recs[index].height + 2.0f*font.glyphPadding };

    // Draw the character texture on the screen
    DrawTexturePro(font.texture, srcRec, dstRec, (Vector2){ 0, 0 }, 0.0f, tint);
}