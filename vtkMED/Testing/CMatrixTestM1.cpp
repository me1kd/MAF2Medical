/*=========================================================================

 Program: MAF2Medical
 Module: CMatrixTestM1
 Authors: Matteo Giacomoni
 
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

#include <cppunit/config/SourcePrefix.h>
#include "CMatrixTestM1.h"

#include "vtkMEDPolyDataDeformation_M1.cpp"

//-------------------------------------------------------------------------
void CMatrixTestM1::TestDynamicAllocation()
//-------------------------------------------------------------------------
{
  vtkMEDPolyDataDeformation_M1::CMatrix<double> *M1 = new vtkMEDPolyDataDeformation_M1::CMatrix<double>(2,2);
  delete M1;
  vtkMEDPolyDataDeformation_M1::CMatrix<int> *M2 = new vtkMEDPolyDataDeformation_M1::CMatrix<int>(2,2);
  delete M2;
}
//-------------------------------------------------------------------------
void CMatrixTestM1::TestStaticAllocation()
//-------------------------------------------------------------------------
{
  vtkMEDPolyDataDeformation_M1::CMatrix<double> M1(2,2);
  vtkMEDPolyDataDeformation_M1::CMatrix<int> M2(2,2);
}
//-------------------------------------------------------------------------
void CMatrixTestM1::TestGetNumberOfColumns()
//-------------------------------------------------------------------------
{
  vtkMEDPolyDataDeformation_M1::CMatrix<double> *M1 = new vtkMEDPolyDataDeformation_M1::CMatrix<double>(15,22);
  CPPUNIT_ASSERT(M1->GetNumberOfColumns() == 22);
  delete M1;

  vtkMEDPolyDataDeformation_M1::CMatrix<int> *M2 = new vtkMEDPolyDataDeformation_M1::CMatrix<int>(18,7);
  CPPUNIT_ASSERT(M2->GetNumberOfColumns() == 7);
  delete M2;
}
//-------------------------------------------------------------------------
void CMatrixTestM1::TestGetNumberOfRows()
//-------------------------------------------------------------------------
{
  vtkMEDPolyDataDeformation_M1::CMatrix<double> *M1 = new vtkMEDPolyDataDeformation_M1::CMatrix<double>(15,22);
  CPPUNIT_ASSERT(M1->GetNumberOfRows() == 15);
  delete M1;

  vtkMEDPolyDataDeformation_M1::CMatrix<int> *M2 = new vtkMEDPolyDataDeformation_M1::CMatrix<int>(18,7);
  CPPUNIT_ASSERT(M2->GetNumberOfRows() == 18);
  delete M2;
}
//-------------------------------------------------------------------------
void CMatrixTestM1::TestGetMinSize()
//-------------------------------------------------------------------------
{
  vtkMEDPolyDataDeformation_M1::CMatrix<double> *M1 = new vtkMEDPolyDataDeformation_M1::CMatrix<double>(15,22);
  CPPUNIT_ASSERT(M1->GetMinSize() == 15);
  delete M1;

  vtkMEDPolyDataDeformation_M1::CMatrix<int> *M2 = new vtkMEDPolyDataDeformation_M1::CMatrix<int>(18,7);
  CPPUNIT_ASSERT(M2->GetMinSize() == 7);
  delete M2;
}
//-------------------------------------------------------------------------
void CMatrixTestM1::TestOperator()
//-------------------------------------------------------------------------
{
  vtkMEDPolyDataDeformation_M1::CMatrix<double> *M1 = new vtkMEDPolyDataDeformation_M1::CMatrix<double>(15,22);
  (*M1)(0,1) = 5.0;
  CPPUNIT_ASSERT( (*M1)(0,1) == 5.0 );
  delete M1;
}
