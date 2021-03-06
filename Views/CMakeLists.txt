#
# Copyright and description to be placed here
#

PROJECT(medViews)

# Set your list of sources here.
SET(PROJECT_SRCS
  
  mafViewArbitrarySlice.cpp
  mafViewArbitrarySlice.h
  mafViewOrthoSlice.cpp
  mafViewOrthoSlice.h
  mafViewRX.cpp
  mafViewRX.h
  mafViewRXCT.cpp
  mafViewRXCT.h
  mafViewSlice.cpp
  mafViewSlice.h
  mafViewGlobalSlice.cpp
  mafViewGlobalSlice.h
  mafViewGlobalSliceCompound.cpp
  mafViewGlobalSliceCompound.h
  mafViewImage.cpp
  mafViewImage.h
  mafViewSingleSlice.cpp
  mafViewSingleSlice.h
  mafViewSingleSliceCompound.cpp
  mafViewSingleSliceCompound.h
  mafViewRXCompound.cpp
  mafViewRXCompound.h
  mafView3D.cpp
  mafView3D.h
  mafViewImageCompound.cpp
  mafViewImageCompound.h
  mafViewCT.cpp
  mafViewCT.h
  medViewCompoundWindowing.cpp
  medViewCompoundWindowing.h
  medViewVTKCompound.cpp
  medViewVTKCompound.h
  #medViewEmgGraph.cpp
  #medViewEmgGraph.h
  medViewSlicer.cpp
  medViewSlicer.h
  medViewSliceOnCurve.cpp
  medViewSliceOnCurve.h
  medViewSliceOnCurveCompound.cpp
  medViewSliceOnCurveCompound.h
  medViewSliceGlobal.cpp
  medViewSliceGlobal.h
  medViewArbitraryOrthoSlice.cpp
  medViewArbitraryOrthoSlice.h
  medViewSliceBlendRX.cpp
  medViewSliceBlendRX.h
  medViewSliceBlend.cpp
  medViewSliceBlend.h
  medViewSliceNotInterpolated.cpp
  medViewSliceNotInterpolated.h
  medViewSliceNotInterpolatedCompound.cpp
  medViewSliceNotInterpolatedCompound.h
)

# List libraries that are needed by this project.
SET(PROJECT_LIBS mafVME mafInteraction mafCore)

SET(PROJECT_LIBS ${PROJECT_LIBS} vtkMED)

IF(MED_BUILD_MEDDLL)
  SET(BUILD_SHARED_LIBS 1)
  ADD_DEFINITIONS(-DMED_VIEWS_EXPORTS)
  # Create the library.
  ADD_LIBRARY(${PROJECT_NAME} ${PROJECT_SRCS})
  TARGET_LINK_LIBRARIES(${PROJECT_NAME} mafDLL vtkMED medCommon medVME medInteraction)
ELSE(MED_BUILD_MEDDLL)
  # Create the library.
  ADD_LIBRARY(${PROJECT_NAME} ${PROJECT_SRCS})
  TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${PROJECT_LIBS})
ENDIF (MED_BUILD_MEDDLL)

ADD_DEPENDENCIES(${PROJECT_NAME} medCommon medVME medInteraction)
