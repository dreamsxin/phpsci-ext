/*
  +----------------------------------------------------------------------+
  | PHPSci CArray                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 2018 PHPSci Team                                       |
  +----------------------------------------------------------------------+
  | Licensed under the Apache License, Version 2.0 (the "License");      |
  | you may not use this file except in compliance with the License.     |
  | You may obtain a copy of the License at                              |
  |                                                                      |
  |     http://www.apache.org/licenses/LICENSE-2.0                       |
  |                                                                      |
  | Unless required by applicable law or agreed to in writing, software  |
  | distributed under the License is distributed on an "AS IS" BASIS,    |
  | WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or      |
  | implied.                                                             |
  | See the License for the specific language governing permissions and  |
  | limitations under the License.                                       |
  +----------------------------------------------------------------------+
  | Authors: Henrique Borba <henrique.borba.dev@gmail.com>               |
  +----------------------------------------------------------------------+
*/

#include "magic_properties.h"
#include "../phpsci.h"
#include "../kernel/carray/carray.h"
#include "transformations.h"
#include "php.h"

/**
 * 1-D Matrix flat iterator.
 *
 * @author Henrique Borba <henrique.borba.dev@gmail.com>
 */
void
magic_property_flat(zval * return_value, MemoryPointer * target_ptr, MemoryPointer * rtn_ptr) {
    flatten(rtn_ptr, target_ptr);
    CArray rtn_arr = ptr_to_carray(rtn_ptr);
    carray_to_array(rtn_arr, return_value, rtn_ptr->x, rtn_ptr->y);
}

/**
 * Handle "magic properties"
 *
 * @author Henrique Borba <henrique.borba.dev@gmail.com>
 */
void
run_property_or_die(char * prop, zval * return_value, MemoryPointer * target_ptr, MemoryPointer * rtn_ptr) {
    if(strcmp(prop, "flat") == 0) {
        magic_property_flat(return_value, target_ptr, rtn_ptr);
        return;
    }
}
