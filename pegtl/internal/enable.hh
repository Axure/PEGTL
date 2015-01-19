// Copyright (c) 2014-2015 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/ColinH/PEGTL/

#ifndef PEGTL_INTERNAL_ENABLE_HH
#define PEGTL_INTERNAL_ENABLE_HH

#include "seq.hh"

namespace pegtl
{
   namespace internal
   {
      template< template< typename ... > class Action, typename ... Rules >
      struct enable
      {
         using internal_t = seq< Rules ... >;

         template< error_mode E, template< typename ... > class, template< typename ... > class Control, typename Input, typename ... States >
         static bool match( Input & in, States && ... st )
         {
            return rule_match_call< seq< Rules ... >, E, Action, Control >::match( in, st ... );
         }
      };

   } // internal

} // pegtl

#endif