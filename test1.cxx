/*=========================================================================

  Program:   KWSys - Kitware System Library
  Module:    test1.cxx

  Copyright (c) Kitware, Inc., Insight Consortium.  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include <kwsys/Directory.hxx>
#include <kwsys/Process.h>
#include <kwsys/ios/iostream>

int main()
{
  kwsys::Directory();
  kwsysProcess* kp = kwsysProcess_New();
  const char* cmd[] = {"echo", "Hello, World!", 0};
  kwsysProcess_SetCommand(kp, cmd);
  kwsysProcess_Execute(kp);
  char* data = 0;
  int length = 0;
  while(kwsysProcess_WaitForData(kp, &data, &length, 0))
    {
    kwsys_ios::cout.write(data, length);
    }
  kwsysProcess_Delete(kp);
  kwsys_ios::cout << kwsys_ios::endl;
  return 0;
}
