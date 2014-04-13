/* test_types.cpp                                 -*- C++ -*-
   Rémi Attab (remi.attab@gmail.com), 12 Apr 2014
   FreeBSD-style copyright and disclaimer apply

   Implementation of the type reflections.
*/

#include "test_types.h"

#include "reflect/basics.h"
#include "reflect/constructor.h"
#include "reflect/field.h"
#include "reflect/operators.h"


/******************************************************************************/
/* OBJECT                                                                     */
/******************************************************************************/

reflectClassImpl(test::Object)
{
    reflectConsBasics();
    reflectCons(int);

    reflectField(value);
    reflectField(ref);
    reflectField(constRef);
    reflectField(rref);

    reflectOperators();
}


/******************************************************************************/
/* NOT COPIABLE                                                               */
/******************************************************************************/

reflectClassImpl(test::NotCopiable)
{
    reflectConsBasics();
}


/******************************************************************************/
/* NOT MOVABLE                                                                */
/******************************************************************************/

reflectClassImpl(test::NotMovable)
{
    reflectConsBasics();
}


/******************************************************************************/
/* NOT CONSTRUCTIBLE                                                          */
/******************************************************************************/

reflectClassImpl(test::NotConstructible)
{
    reflectConsBasics();
}


/******************************************************************************/
/* INTERFACE                                                                  */
/******************************************************************************/

reflectClassImpl(test::Interface)
{
    reflectFn(pureVirtual);
}

/******************************************************************************/
/* PARENT                                                                     */
/******************************************************************************/

reflectClassImpl(test::Parent)
{
    reflectParent(test::Interface);
    reflectConsBasics();
    reflectCons(test::Object, int);

    reflectField(value);
    reflectField(shadowed);

    reflectFn(normalVirtual);
}


/******************************************************************************/
/* CHILD                                                                      */
/******************************************************************************/

reflectClassImpl(test::Child)
{
    reflectParent(test::Parent);
    reflectConsBasics();
    reflectCons(test::Object, int);

    reflectField(childValue);
    reflectField(shadowed);

    reflectFn(normalVirtual);
}


/******************************************************************************/
/* CONVERTIBLE                                                                */
/******************************************************************************/

reflectClassImpl(test::Convertible)
{
    reflectConsBasics();
    reflectField(value);
    reflectOpCast(int);
    reflectOpCast(test::Parent);
}
