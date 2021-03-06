/*=========================================================================

 Program: MAF2Medical
 Module: medOpClassicICPRegistrationTest
 Authors: Simone Brazzale
 
 Copyright (c) B3C
 All rights reserved. See Copyright.txt or
 http://www.scsitaly.com/Copyright.htm for details.

 This software is distributed WITHOUT ANY WARRANTY; without even
 the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#include "medDefines.h"
//----------------------------------------------------------------------------
// NOTE: Every CPP file in the MAF must include "mafDefines.h" as first.
// This force to include Window,wxWidgets and VTK exactly in this order.
// Failing in doing this will result in a run-time error saying:
// "Failure#0: The value of ESP was not properly saved across a function call"
//----------------------------------------------------------------------------

#include "medOpClassicICPRegistrationTest.h"
#include "medOpClassicICPRegistration.h"

#include "mafVME.h"
#include "mafVMESurface.h"
#include "mafVMESurfaceParametric.h"
#include "mafVMELandmarkCloud.h"
#include "mafSmartPointer.h"
#include "mafAbsMatrixPipe.h"
#include "vtkMAFSmartPointer.h"
#include "medOpImporterVTK.h"

#include <string>
#include <assert.h>

//-----------------------------------------------------------
void medOpClassicICPRegistrationTest::TestDynamicAllocation() 
//-----------------------------------------------------------
{
  medOpClassicICPRegistration *create = new medOpClassicICPRegistration("icp");
  mafDEL(create);
}
//-----------------------------------------------------------
void medOpClassicICPRegistrationTest::TestCopy() 
//-----------------------------------------------------------
{
  medOpClassicICPRegistration *create = new medOpClassicICPRegistration("icp");
  medOpClassicICPRegistration *create2 = (medOpClassicICPRegistration*)(create->Copy());

  CPPUNIT_ASSERT(create2 != NULL);

  mafDEL(create2);
  mafDEL(create);
}
//-----------------------------------------------------------
void medOpClassicICPRegistrationTest::TestAccept() 
//-----------------------------------------------------------
{
  mafSmartPointer<mafVMESurface> surface;
  mafSmartPointer<mafVMESurfaceParametric> psurface;  
  mafSmartPointer<mafVMELandmarkCloud> lc;
  
  medOpClassicICPRegistration *create=new medOpClassicICPRegistration("icp");
  
  CPPUNIT_ASSERT(create->Accept(surface));
  CPPUNIT_ASSERT(create->Accept(psurface));

  // not rigid lc
  CPPUNIT_ASSERT(!create->Accept(lc));

  CPPUNIT_ASSERT(!create->Accept(NULL));

  mafDEL(create);
}
//-----------------------------------------------------------
void medOpClassicICPRegistrationTest::TestOpDo() 
//-----------------------------------------------------------
{
  // import VTK  
  medOpImporterVTK *importer=new medOpImporterVTK("importerVTK");
  importer->TestModeOn();
  mafString fileName=MED_DATA_ROOT;
  fileName<<"/Surface/sphere.vtk";
  importer->SetFileName(fileName);
  importer->ImportVTK();
  
  mafVMESurface *surface = mafVMESurface::SafeDownCast(importer->GetOutput());
  
  CPPUNIT_ASSERT(surface!=NULL);
  CPPUNIT_ASSERT(surface->GetOutput()->GetVTKData()!=NULL);

  medOpImporterVTK *importer2=new medOpImporterVTK("importerVTK");
  importer2->TestModeOn();
  mafString fileName2=MED_DATA_ROOT;
  fileName2<<"/VTK_Volumes/volume.vtk";
  importer2->SetFileName(fileName2);
  importer2->ImportVTK();
  
  mafVME *vme = mafVME::SafeDownCast(importer2->GetOutput());
  
  CPPUNIT_ASSERT(vme!=NULL);
  CPPUNIT_ASSERT(vme->GetOutput()->GetVTKData()!=NULL);

  medOpClassicICPRegistration *op=new medOpClassicICPRegistration("icp");
  op->TestModeOn();
  op->SetInput(surface);
  op->SetTarget(vme);
  op->OpDo();

  // test attributes
  CPPUNIT_ASSERT(surface->GetNumberOfChildren()==1);
  mafVME* registered = mafVME::SafeDownCast(surface->GetChild(0));
  CPPUNIT_ASSERT(registered->GetAbsMatrixPipe()->GetMatrix().GetVTKMatrix()!=NULL);

  mafDEL(op);
  mafDEL(importer);
  mafDEL(importer2);

  delete wxLog::SetActiveTarget(NULL);
}