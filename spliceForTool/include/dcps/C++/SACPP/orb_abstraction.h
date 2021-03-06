/*
 *                         Vortex OpenSplice
 *
 *   This software and documentation are Copyright 2006 to  ADLINK
 *   Technology Limited, its affiliated companies and licensors. All rights
 *   reserved.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 */
#ifndef CCPP_ORB_ABSTRACTION_H
#define CCPP_ORB_ABSTRACTION_H

#include "sacpp_LocalObject.h"
#include "sacpp_UserException.h"
#include "sacpp_DefaultValueRefCountBase.h"

  namespace DDS
  {
    #define LOCAL_REFCOUNTED_OBJECT virtual DDS::LocalObject
    #define LOCAL_REFCOUNTED_VALUEBASE DDS::DefaultValueRefCountBase

    #define THROW_ORB_EXCEPTIONS
    #define THROW_ORB_AND_USER_EXCEPTIONS(...)

    #define THROW_VALUETYPE_ORB_EXCEPTIONS
    #define THROW_VALUETYPE_ORB_AND_USER_EXCEPTIONS(...)
  }


#endif /* ORB_ABSTRACTION */
