/*=========================================================================

 Program: MAF2Medical
 Module: medWizardBlock
 Authors: Gianluigi Crimi
 
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

#include "medDecl.h"
#include "medWizardBlock.h"




//----------------------------------------------------------------------------
medWizardBlock::medWizardBlock(const char *name)
//----------------------------------------------------------------------------
{

  //Setting default values
  m_Name = name;

  if (m_Name == "END")
    mafLogMessage("MafWizardBlock: 'END' was reserved");
  
  m_Success=true;
}

//----------------------------------------------------------------------------
medWizardBlock::~medWizardBlock()
//----------------------------------------------------------------------------
{
}

//----------------------------------------------------------------------------
int medWizardBlock::Success()
//----------------------------------------------------------------------------
{
  //return true if the execution of the block havent problems
  return m_Success;
}

//----------------------------------------------------------------------------
wxString medWizardBlock::GetName()
//----------------------------------------------------------------------------
{
  //return the block name
  return m_Name;
}


//----------------------------------------------------------------------------
wxString medWizardBlock::GetNextBlock()
//----------------------------------------------------------------------------
{
  //You need to add a specified block
  return wxString("Error, Base block added");
}

//----------------------------------------------------------------------------
void medWizardBlock::Abort()
//----------------------------------------------------------------------------
{
  //Set the success to false
  m_Success=false;
}

//----------------------------------------------------------------------------
void medWizardBlock::ExcutionBegin()
//----------------------------------------------------------------------------
{
  //Starting execution
  m_Running=true;
}

//----------------------------------------------------------------------------
void medWizardBlock::ExcutionEnd()
//----------------------------------------------------------------------------
{
  //Stopping execution
  m_Running=false;
}

//----------------------------------------------------------------------------
wxString medWizardBlock::GetRequiredOperation()
//----------------------------------------------------------------------------
{
  //No operation required by default 
  return wxString("");
}

//----------------------------------------------------------------------------
void medWizardBlock::SetSelectedVME( mafNode *node )
//----------------------------------------------------------------------------
{
  //setting the selected vme
  m_SelectedVME=node;
}

//----------------------------------------------------------------------------
void medWizardBlock::SetListener( mafObserver *Listener )
//----------------------------------------------------------------------------
{
  //setting the event listener
  m_Listener = Listener;
}

