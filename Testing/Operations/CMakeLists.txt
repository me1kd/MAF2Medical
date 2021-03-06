PROJECT (MedicalOperations_TEST)

IF(MED_BUILD_MEDDLL)
  LINK_LIBRARIES(medOperations)
ELSE(MED_BUILD_MEDDLL)
  LINK_LIBRARIES(medVME medCommon medOperations)
ENDIF (MED_BUILD_MEDDLL)

#-----------------------------------------------------------------------------
# tests using cppunit testing framework
#-----------------------------------------------------------------------------
IF (MAF_USE_ITK)
  ADD_EXECUTABLE(medOpExporterLandmarkTest medOpExporterLandmarkTest.h medOpExporterLandmarkTest.cpp)
  ADD_TEST(medOpExporterLandmarkTest ${EXECUTABLE_OUTPUT_PATH}/medOpExporterLandmarkTest)

  ADD_EXECUTABLE(medOpImporterLandmarkTest medOpImporterLandmarkTest.h medOpImporterLandmarkTest.cpp)
  ADD_TEST(medOpImporterLandmarkTest ${EXECUTABLE_OUTPUT_PATH}/medOpImporterLandmarkTest)
  
  ADD_EXECUTABLE(medOpImporterGRFWSTest medOpImporterGRFWSTest.h medOpImporterGRFWSTest.cpp)
  ADD_TEST(medOpImporterGRFWSTest ${EXECUTABLE_OUTPUT_PATH}/medOpImporterGRFWSTest) 
  
  ADD_EXECUTABLE(medOpImporterAnalogWSTest medOpImporterAnalogWSTest.h medOpImporterAnalogWSTest.cpp)
  ADD_TEST(medOpImporterAnalogWSTest ${EXECUTABLE_OUTPUT_PATH}/medOpImporterAnalogWSTest)
ENDIF (MAF_USE_ITK)

ADD_EXECUTABLE(medGeometryEditorPolylineGraphTest medGeometryEditorPolylineGraphTest.h medGeometryEditorPolylineGraphTest.cpp)
ADD_TEST(medGeometryEditorPolylineGraphTest  ${EXECUTABLE_OUTPUT_PATH}/medGeometryEditorPolylineGraphTest)

ADD_EXECUTABLE(medOpMatrixVectorMathTest medOpMatrixVectorMathTest.h medOpMatrixVectorMathTest.cpp)
ADD_TEST(medOpMatrixVectorMathTest ${EXECUTABLE_OUTPUT_PATH}/medOpMatrixVectorMathTest)

ADD_EXECUTABLE(medOpVolumeMeasureTest medOpVolumeMeasureTest.h medOpVolumeMeasureTest.cpp)
ADD_TEST(medOpVolumeMeasureTest ${EXECUTABLE_OUTPUT_PATH}/medOpVolumeMeasureTest)

ADD_EXECUTABLE(medOpImporterRAWImagesTest medOpImporterRAWImagesTest.h medOpImporterRAWImagesTest.cpp)
ADD_TEST(medOpImporterRAWImagesTest ${EXECUTABLE_OUTPUT_PATH}/medOpImporterRAWImagesTest)

ADD_EXECUTABLE(medOpImporterLandmarkTXTTest medOpImporterLandmarkTXTTest.h medOpImporterLandmarkTXTTest.cpp)
ADD_TEST(medOpImporterLandmarkTXTTest ${EXECUTABLE_OUTPUT_PATH}/medOpImporterLandmarkTXTTest)

ADD_EXECUTABLE(medOpImporterLandmarkWSTest medOpImporterLandmarkWSTest.h medOpImporterLandmarkWSTest.cpp)
ADD_TEST(medOpImporterLandmarkWSTest ${EXECUTABLE_OUTPUT_PATH}/medOpImporterLandmarkWSTest)
  
ADD_EXECUTABLE(medOpExtrusionHolesTest medOpExtrusionHolesTest.h medOpExtrusionHolesTest.cpp)
ADD_TEST(medOpExtrusionHolesTest ${EXECUTABLE_OUTPUT_PATH}/medOpExtrusionHolesTest)

ADD_EXECUTABLE(medOpExporterWrappedMeterTest medOpExporterWrappedMeterTest.h medOpExporterWrappedMeterTest.cpp)
ADD_TEST(medOpExporterWrappedMeterTest ${EXECUTABLE_OUTPUT_PATH}/medOpExporterWrappedMeterTest)

ADD_EXECUTABLE(medOpFreezeVMETest medOpFreezeVMETest.h medOpFreezeVMETest.cpp)
ADD_TEST(medOpFreezeVMETest ${EXECUTABLE_OUTPUT_PATH}/medOpFreezeVMETest)

ADD_EXECUTABLE(medOpLabelizeSurfaceTest medOpLabelizeSurfaceTest.h medOpLabelizeSurfaceTest.cpp)
ADD_TEST(medOpLabelizeSurfaceTest ${EXECUTABLE_OUTPUT_PATH}/medOpLabelizeSurfaceTest)

ADD_EXECUTABLE(medOpCleanSurfaceTest medOpCleanSurfaceTest.h medOpCleanSurfaceTest.cpp)
ADD_TEST(medOpCleanSurfaceTest ${EXECUTABLE_OUTPUT_PATH}/medOpCleanSurfaceTest)

ADD_EXECUTABLE(medOpSmoothSurfaceTest medOpSmoothSurfaceTest.h medOpSmoothSurfaceTest.cpp)
ADD_TEST(medOpSmoothSurfaceTest ${EXECUTABLE_OUTPUT_PATH}/medOpSmoothSurfaceTest)

ADD_EXECUTABLE(medOpTriangulateSurfaceTest medOpTriangulateSurfaceTest.h medOpTriangulateSurfaceTest.cpp)
ADD_TEST(medOpTriangulateSurfaceTest ${EXECUTABLE_OUTPUT_PATH}/medOpTriangulateSurfaceTest)

ADD_EXECUTABLE(medOpSurfaceMirrorTest medOpSurfaceMirrorTest.h medOpSurfaceMirrorTest.cpp)
ADD_TEST(medOpSurfaceMirrorTest ${EXECUTABLE_OUTPUT_PATH}/medOpSurfaceMirrorTest)

ADD_EXECUTABLE(medOpImporterVTKTest medOpImporterVTKTest.h medOpImporterVTKTest.cpp)
ADD_TEST(medOpImporterVTKTest ${EXECUTABLE_OUTPUT_PATH}/medOpImporterVTKTest)

ADD_EXECUTABLE(medOpExporterMetersTest medOpExporterMetersTest.h medOpExporterMetersTest.cpp)
ADD_TEST(medOpExporterMetersTest ${EXECUTABLE_OUTPUT_PATH}/medOpExporterMetersTest)

ADD_EXECUTABLE(medOpSubdivideTest medOpSubdivideTest.h medOpSubdivideTest.cpp)
ADD_TEST(medOpSubdivideTest ${EXECUTABLE_OUTPUT_PATH}/medOpSubdivideTest)

ADD_EXECUTABLE(medOpCreateSurfaceTest medOpCreateSurfaceTest.h medOpCreateSurfaceTest.cpp)
ADD_TEST(medOpCreateSurfaceTest ${EXECUTABLE_OUTPUT_PATH}/medOpCreateSurfaceTest)

ADD_EXECUTABLE(medOpVolumeResampleTest medOpVolumeResampleTest.h medOpVolumeResampleTest.cpp)
ADD_TEST(medOpVolumeResampleTest ${EXECUTABLE_OUTPUT_PATH}/medOpVolumeResampleTest)

ADD_EXECUTABLE(medOpSegmentationRegionGrowingConnectedThresholdTest medOpSegmentationRegionGrowingConnectedThresholdTest.h medOpSegmentationRegionGrowingConnectedThresholdTest.cpp)
ADD_TEST(medOpSegmentationRegionGrowingConnectedThresholdTest ${EXECUTABLE_OUTPUT_PATH}/medOpSegmentationRegionGrowingConnectedThresholdTest)

ADD_EXECUTABLE(medOpScaleDatasetTest medOpScaleDatasetTest.h medOpScaleDatasetTest.cpp)
ADD_TEST(medOpScaleDatasetTest ${EXECUTABLE_OUTPUT_PATH}/medOpScaleDatasetTest)

ADD_EXECUTABLE(medOpCreateLabeledVolumeTest medOpCreateLabeledVolumeTest.h medOpCreateLabeledVolumeTest.cpp)
ADD_TEST(medOpCreateLabeledVolumeTest ${EXECUTABLE_OUTPUT_PATH}/medOpCreateLabeledVolumeTest)

ADD_EXECUTABLE(medOpComputeWrappingTest medOpComputeWrappingTest.h medOpComputeWrappingTest.cpp)
ADD_TEST(medOpComputeWrappingTest ${EXECUTABLE_OUTPUT_PATH}/medOpComputeWrappingTest)

ADD_EXECUTABLE(medOpComputeInertialTensorTest medOpComputeInertialTensorTest.h medOpComputeInertialTensorTest.cpp)
ADD_TEST(medOpComputeInertialTensorTest ${EXECUTABLE_OUTPUT_PATH}/medOpComputeInertialTensorTest)

ADD_EXECUTABLE(medOpSplitSurfaceTest medOpSplitSurfaceTest.h medOpSplitSurfaceTest.cpp)
ADD_TEST(medOpSplitSurfaceTest ${EXECUTABLE_OUTPUT_PATH}/medOpSplitSurfaceTest)

ADD_EXECUTABLE(medOpMML3Test medOpMML3Test.h medOpMML3Test.cpp)
ADD_TEST(medOpMML3Test ${EXECUTABLE_OUTPUT_PATH}/medOpMML3Test)

ADD_EXECUTABLE(medOpExtractGeometryTest medOpExtractGeometryTest.h medOpExtractGeometryTest.cpp)
ADD_TEST(medOpExtractGeometryTest ${EXECUTABLE_OUTPUT_PATH}/medOpExtractGeometryTest)


IF (MED_USE_Offis)

ADD_EXECUTABLE(medOpImporterDicomOffisTest medOpImporterDicomOffisTest.h medOpImporterDicomOffisTest.cpp)
ADD_TEST(medOpImporterDicomOffisTest ${EXECUTABLE_OUTPUT_PATH}/medOpImporterDicomOffisTest)


ADD_EXECUTABLE(medDicomCardiacMRIHelperTest medDicomCardiacMRIHelperTest.h medDicomCardiacMRIHelperTest.cpp)
ADD_TEST(medDicomCardiacMRIHelperTest ${EXECUTABLE_OUTPUT_PATH}/medDicomCardiacMRIHelperTest)

ENDIF (MED_USE_Offis)

ADD_EXECUTABLE(itkRawMotionImporterUtilityTest itkRawMotionImporterUtilityTest.h itkRawMotionImporterUtilityTest.cpp)
ADD_TEST(itkRawMotionImporterUtilityTest ${EXECUTABLE_OUTPUT_PATH}/itkRawMotionImporterUtilityTest)

ADD_EXECUTABLE(medOpMakeVMETimevaryingTest medOpMakeVMETimevaryingTest.h medOpMakeVMETimevaryingTest.cpp)
ADD_TEST(medOpMakeVMETimevaryingTest ${EXECUTABLE_OUTPUT_PATH}/medOpMakeVMETimevaryingTest)

ADD_EXECUTABLE(medOpEqualizeHistogramTest medOpEqualizeHistogramTest.h medOpEqualizeHistogramTest.cpp)
ADD_TEST(medOpEqualizeHistogramTest ${EXECUTABLE_OUTPUT_PATH}/medOpEqualizeHistogramTest)

ADD_EXECUTABLE(medOpCreateWrappedMeterTest medOpCreateWrappedMeterTest.h medOpCreateWrappedMeterTest.cpp)
ADD_TEST(medOpCreateWrappedMeterTest ${EXECUTABLE_OUTPUT_PATH}/medOpCreateWrappedMeterTest)

ADD_EXECUTABLE(medOpFlipNormalsTest medOpFlipNormalsTest.h medOpFlipNormalsTest.cpp)
ADD_TEST(medOpFlipNormalsTest ${EXECUTABLE_OUTPUT_PATH}/medOpFlipNormalsTest)

ADD_EXECUTABLE(medOpSmoothSurfaceCellsTest medOpSmoothSurfaceCellsTest.h medOpSmoothSurfaceCellsTest.cpp)
ADD_TEST(medOpSmoothSurfaceCellsTest ${EXECUTABLE_OUTPUT_PATH}/medOpSmoothSurfaceCellsTest)

ADD_EXECUTABLE(medOpMeshQualityTest medOpMeshQualityTest.h medOpMeshQualityTest.cpp)
ADD_TEST(medOpMeshQualityTest ${EXECUTABLE_OUTPUT_PATH}/medOpMeshQualityTest)

ADD_EXECUTABLE(mafOpImporterBBFTest mafOpImporterBBFTest.h mafOpImporterBBFTest.cpp)
ADD_TEST(mafOpImporterBBFTest ${EXECUTABLE_OUTPUT_PATH}/mafOpImporterBBFTest)

ADD_EXECUTABLE(medOpCropDeformableROITest medOpCropDeformableROITest.h medOpCropDeformableROITest.cpp)
ADD_TEST(medOpCropDeformableROITest ${EXECUTABLE_OUTPUT_PATH}/medOpCropDeformableROITest)

ADD_EXECUTABLE(mafOpImporterRAWVolume_BESTest mafOpImporterRAWVolume_BESTest.h mafOpImporterRAWVolume_BESTest.cpp)
ADD_TEST(mafOpImporterRAWVolume_BESTest ${EXECUTABLE_OUTPUT_PATH}/mafOpImporterRAWVolume_BESTest)

ADD_EXECUTABLE(medOpMoveTest medOpMoveTest.h medOpMoveTest.cpp)
ADD_TEST(medOpMoveTest ${EXECUTABLE_OUTPUT_PATH}/medOpMoveTest)

ADD_EXECUTABLE(medOpExporterAnalogWSTest medOpExporterAnalogWSTest.h medOpExporterAnalogWSTest.cpp)
ADD_TEST(medOpExporterAnalogWSTest ${EXECUTABLE_OUTPUT_PATH}/medOpExporterAnalogWSTest)

ADD_EXECUTABLE(medOpExporterGRFWSTest medOpExporterGRFWSTest.h medOpExporterGRFWSTest.cpp)
ADD_TEST(medOpExporterGRFWSTest ${EXECUTABLE_OUTPUT_PATH}/medOpExporterGRFWSTest)

ADD_EXECUTABLE(medOpExporterLandmarkWSTest medOpExporterLandmarkWSTest.h medOpExporterLandmarkWSTest.cpp)
ADD_TEST(medOpExporterLandmarkWSTest ${EXECUTABLE_OUTPUT_PATH}/medOpExporterLandmarkWSTest)

ADD_EXECUTABLE(medDicomSliceTest  medDicomSliceTest.h medDicomSliceTest.cpp)
ADD_TEST(medDicomSliceTest ${EXECUTABLE_OUTPUT_PATH}/medDicomSliceTest)

ADD_EXECUTABLE(medOpImporterC3DTest  medOpImporterC3DTest.h medOpImporterC3DTest.cpp)
ADD_TEST(medOpImporterC3DTest ${EXECUTABLE_OUTPUT_PATH}/medOpImporterC3DTest)

ADD_EXECUTABLE(medOpImporterMotionDataTest  medOpImporterMotionDataTest.h medOpImporterMotionDataTest.cpp)
ADD_TEST(medOpImporterMotionDataTest ${EXECUTABLE_OUTPUT_PATH}/medOpImporterMotionDataTest)

ADD_EXECUTABLE(medOpFillHolesTest  medOpFillHolesTest.h medOpFillHolesTest.cpp)
ADD_TEST(medOpFillHolesTest ${EXECUTABLE_OUTPUT_PATH}/medOpFillHolesTest)

ADD_EXECUTABLE(medOpImporterVTKXMLTest  medOpImporterVTKXMLTest.h medOpImporterVTKXMLTest.cpp)
ADD_TEST(medOpImporterVTKXMLTest ${EXECUTABLE_OUTPUT_PATH}/medOpImporterVTKXMLTest)

ADD_EXECUTABLE(medOpInteractiveClipSurfaceTest  medOpInteractiveClipSurfaceTest.h medOpInteractiveClipSurfaceTest.cpp)
ADD_TEST(medOpInteractiveClipSurfaceTest ${EXECUTABLE_OUTPUT_PATH}/medOpInteractiveClipSurfaceTest)

ADD_EXECUTABLE(medOpCreateEditSkeletonTest  medOpCreateEditSkeletonTest.h medOpCreateEditSkeletonTest.cpp)
ADD_TEST(medOpCreateEditSkeletonTest ${EXECUTABLE_OUTPUT_PATH}/medOpCreateEditSkeletonTest)

ADD_EXECUTABLE(medOpRegisterClustersTest  medOpRegisterClustersTest.h medOpRegisterClustersTest.cpp)
ADD_TEST(medOpRegisterClustersTest ${EXECUTABLE_OUTPUT_PATH}/medOpRegisterClustersTest)

ADD_EXECUTABLE(medOpClassicICPRegistrationTest  medOpClassicICPRegistrationTest.h medOpClassicICPRegistrationTest.cpp)
ADD_TEST(medOpClassicICPRegistrationTest ${EXECUTABLE_OUTPUT_PATH}/medOpClassicICPRegistrationTest)

ADD_EXECUTABLE(medOpMML3ParameterViewTest  medOpMML3ParameterViewTest.h medOpMML3ParameterViewTest.cpp)
ADD_TEST(medOpMML3ParameterViewTest ${EXECUTABLE_OUTPUT_PATH}/medOpMML3ParameterViewTest)

ADD_EXECUTABLE(medOpInteractionDebuggerTest  medOpInteractionDebuggerTest.h medOpInteractionDebuggerTest.cpp)
ADD_TEST(medOpInteractionDebuggerTest ${EXECUTABLE_OUTPUT_PATH}/medOpInteractionDebuggerTest)

ADD_EXECUTABLE(medOpIterativeRegistrationTest  medOpIterativeRegistrationTest.h medOpIterativeRegistrationTest.cpp)
ADD_TEST(medOpIterativeRegistrationTest ${EXECUTABLE_OUTPUT_PATH}/medOpIterativeRegistrationTest)

# wxWidgets specific classes
#IF (MAF_USE_WX)
#ENDIF (MAF_USE_WX)

# VTK specific classes
IF (MAF_USE_VTK)
ENDIF (MAF_USE_VTK)  

# classes using VTK+wxWidgets
#IF (MAF_USE_WX AND MAF_USE_VTK)
#ENDIF (MAF_USE_WX AND MAF_USE_VTK)
