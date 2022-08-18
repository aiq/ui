################################################################################
# INC_FILES
################################################################################
set( INC_FILES
   ${INC_DIR}/uiinabox/apidecl.h

   ${INC_DIR}/uiinabox/content/uiContent.h

   ${INC_DIR}/uiinabox/draw.h
   ${INC_DIR}/uiinabox/uiBackground.h
   ${INC_DIR}/uiinabox/uiBorder.h
   ${INC_DIR}/uiinabox/uiBox.h
   ${INC_DIR}/uiinabox/uiFont.h
   ${INC_DIR}/uiinabox/uiFrame.h
   ${INC_DIR}/uiinabox/uiPoint.h
   ${INC_DIR}/uiinabox/uiRect.h
   ${INC_DIR}/uiinabox/uiSize.h
   ${INC_DIR}/uiinabox/uiStyle.h
)

################################################################################
# SRC_FILES
################################################################################
set( SRC_FILES
   ${SRC_DIR}/uiinabox/draw.c
   ${SRC_DIR}/uiinabox/uiBackground.c
   ${SRC_DIR}/uiinabox/uiBorder.c
   ${SRC_DIR}/uiinabox/uiBox.c
   ${SRC_DIR}/uiinabox/uiFont.c
   ${SRC_DIR}/uiinabox/uiRect.c
   ${SRC_DIR}/uiinabox/uiSize.c
   ${SRC_DIR}/uiinabox/uiStyle.c
)

################################################################################
# TEST_FILES
################################################################################
set( TEST_FILES
   # oCmcPage
)

################################################################################
# DEMO_FILES
################################################################################
set( DEMO_FILES
   ${DEMO_DIR}/draw-ring/draw-ring.c
)
