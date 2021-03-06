/* parser.h                                 -*- C++ -*-
   Rémi Attab (remi.attab@gmail.com), 19 Apr 2014
   FreeBSD-style copyright and disclaimer apply

   Json parser
*/

#pragma once

#include "reflect.h"

namespace reflect {
namespace json {


/******************************************************************************/
/* PARSE INTO                                                                 */
/******************************************************************************/

void parseInto(Value& value, std::istream& json);
void parseInto(Value& value, const std::string& json);

template<typename T>
void parseInto(T& value, std::istream& json)
{
    Value v(value);
    parseInto(v, json);
}

template<typename T>
void parseInto(T& value, const std::string& json)
{
    Value v(value);
    parseInto(v, json);
}


/******************************************************************************/
/* PARSE                                                                      */
/******************************************************************************/

Value parse(const Type* type, std::istream& json);
Value parse(const Type* type, const std::string& json);

template<typename T>
T parse(std::istream& json)
{
    Value v = parse(type<T>(), json);
    return v.get<T>();
}

template<typename T>
T parse(const std::string& json)
{
    Value v = parse(type<T>(), json);
    return v.get<T>();
}


} // namespace json
} // reflect
