#ifndef HELPER_H
#define HELPER_H

#include <iostream>

#define IS_STRING(_i) (args[_i]->IsString())
#define IS_INT32(_i) (args[_i]->IsInt32())
#define IS_NUMBER(_i) (args[_i]->IsNumber())
#define IS_BOOLEAN(_i) (args[_i]->IsBoolean())
#define IS_OBJECT(_i, _type) (args[_i]->IsObject() && ObjectWrap::Unwrap<_type>(args[_i]->ToObject()) != NULL)

#endif
