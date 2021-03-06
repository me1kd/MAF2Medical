/*=========================================================================

 Program: MAF2Medical
 Module: medOpInteractionOp
 Authors: Marco Petrone
 
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

#include "exWizardSample.h"
#include "medWizardBlockSelection.h"
#include "medWizardBlockOperation.h"
#include "medWizardBlockInformation.h"


//--------------------------------------------------------------------------------
exWizardSample::exWizardSample( const wxString &label ):medWizard(label)
//--------------------------------------------------------------------------------
{

  medWizardBlockInformation *infoBlock=new medWizardBlockInformation("START");
  infoBlock->SetBoxLabel("Info");
  infoBlock->SetDescription("Import Loop:\nYou can import and show a series of VTK files.");
  infoBlock->SetWindowTitle("information");
  infoBlock->SetNextBlock("Import");
  infoBlock->SetBlockProgress(10);
  
  //Start Block (import a VTK file)   
  medWizardBlockOperation *opBlock=new medWizardBlockOperation("Import");
  opBlock->SetRequiredView("");
  opBlock->VmeSelect("root");
  opBlock->SetRequiredOperation("mafOpImporterVTK");
  opBlock->SetNextBlock("opPause");
  opBlock->SetBlockProgress(25);

  //Move block (position the Block)
  medWizardBlockOperation *opBlock2=new medWizardBlockOperation("opPause");
  opBlock2->SetRequiredView("VTK view");
  opBlock2->VmeSelect("lastChild");
  opBlock2->SetRequiredOperation("PAUSE");
  opBlock2->SetNextBlock("Select");
  opBlock2->SetBlockProgress(75);
  
  //Select Block ask user if want to import another file
  medWizardBlockSelection *selectorBlock=new medWizardBlockSelection("Select");
  selectorBlock->SetWindowTitle("Test Selector");
  selectorBlock->SetDescription("Wizard Selector Test window");
  selectorBlock->AddChoice("Import another VTK","deleteBlock"); 
  selectorBlock->AddChoice("End Wizard", "END");
  selectorBlock->SetBlockProgress(100);

  //Move block (position the Block)
  medWizardBlockOperation *deleteBlock=new medWizardBlockOperation("deleteBlock");
  deleteBlock->SetRequiredOperation("DELETE");
  deleteBlock->SetNextBlock("Import");


  //add blocks to the wizard
  AddBlock(infoBlock);
  AddBlock(selectorBlock);
  AddBlock(opBlock);
  AddBlock(opBlock2);
  AddBlock(deleteBlock);

  ShowProgressBar();
}

//--------------------------------------------------------------------------------
bool exWizardSample::Accept(mafNode* vme)
//--------------------------------------------------------------------------------
{
  return true;
}

