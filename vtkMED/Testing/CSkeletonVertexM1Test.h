/*=========================================================================
Program:   Multimod Application Framework
Module:    $RCSfile: CSkeletonVertexM1Test.h,v $
Language:  C++
Date:      $Date: 2011-05-18 12:04:48 $
Version:   $Revision: 1.1.2.1 $
Authors:   Eleonora Mambrini
==========================================================================
Copyright (c) 2002/2004 
CINECA - Interuniversity Consortium (www.cineca.it)
=========================================================================*/

#ifndef __CPP_UNIT_CSkeletonVertexM1TEST_H__
#define __CPP_UNIT_CSkeletonVertexM1TEST_H__

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>



class CSkeletonVertexM1Test : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( CSkeletonVertexM1Test );
  CPPUNIT_TEST( TestDynamicAllocation );
  CPPUNIT_TEST( TestIsInPositiveHalfspace );
  CPPUNIT_TEST( TestGetDegree );
  CPPUNIT_TEST_SUITE_END();

protected:
  /** Test Dinamyc allocation of CSkeletonVertex class.*/
  void TestDynamicAllocation();
  /** Test IsInPositiveHalfSpace() method. */
  void TestIsInPositiveHalfspace();
  /** Test GetDegree() method. */
  void TestGetDegree();
};


int
main( int argc, char* argv[] )
{
  // Create the event manager and test controller
  CPPUNIT_NS::TestResult controller;

  // Add a listener that collects test result
  CPPUNIT_NS::TestResultCollector result;
  controller.addListener( &result );        

  // Add a listener that print dots as test run.
  CPPUNIT_NS::BriefTestProgressListener progress;
  controller.addListener( &progress );      

  // Add the top suite to the test runner
  CPPUNIT_NS::TestRunner runner;
  runner.addTest( CSkeletonVertexM1Test::suite());
  runner.run( controller );

  // Print test in a compiler compatible format.
  CPPUNIT_NS::CompilerOutputter outputter( &result, CPPUNIT_NS::stdCOut() );
  outputter.write(); 

  return result.wasSuccessful() ? 0 : 1;
}

#endif