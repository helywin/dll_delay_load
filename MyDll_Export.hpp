//
// Created by helywin on 2020/7/1.
//

#ifndef DLL_DELAY_LOAD_MYDLL_EXPORT_HPP
#define DLL_DELAY_LOAD_MYDLL_EXPORT_HPP

#ifdef MYDLL_BUILT_AS_STATIC
#  define MYDLL_API
#  define MYDLL_NO_EXPORT
#else
#  ifndef MYDLL_API
#    ifdef MYDLL_EXPORTS
/* We are building this library */
#      define MYDLL_API __declspec(dllexport)
#    else
/* We are using this library */
#      define MYDLL_API __declspec(dllimport)
#    endif
#  endif

#  ifndef MYDLL_NO_EXPORT
#    define MYDLL_NO_EXPORT
#  endif
#endif

#ifndef MYDLL_DEPRECATED
#  define MYDLL_DEPRECATED __declspec(deprecated)
#endif

#ifndef MYDLL_DEPRECATED_EXPORT
#  define MYDLL_DEPRECATED_EXPORT MYDLL_API MYDLL_DEPRECATED
#endif

#ifndef MYDLL_DEPRECATED_NO_EXPORT
#  define MYDLL_DEPRECATED_NO_EXPORT MYDLL_NO_EXPORT MYDLL_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef MYDLL_NO_DEPRECATED
#    define MYDLL_NO_DEPRECATED
#  endif
#endif

#endif //DLL_DELAY_LOAD_MYDLL_EXPORT_HPP
