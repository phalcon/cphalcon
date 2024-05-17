
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_PHALCON_H
#define PHP_PHALCON_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

/**
 * This file is part of the Zephir.
 *
 * (c) Phalcon Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code. If you did not receive
 * a copy of the license it is available through the world-wide-web at the
 * following url: https://docs.zephir-lang.com/en/latest/license
 */

#ifndef ZEPHIR_KERNEL_GLOBALS_H
#define ZEPHIR_KERNEL_GLOBALS_H

#include <php.h>

#define ZEPHIR_MAX_CACHE_SLOTS 512

typedef struct _zephir_function_cache {
	zend_class_entry *ce;
	zend_function *func;
} zephir_function_cache;

typedef zend_function zephir_fcall_cache_entry;

#define ZEPHIR_INIT_FUNCS(class_functions) static const zend_function_entry class_functions[] =

/** Define FASTCALL */
#if defined(__GNUC__) && ZEND_GCC_VERSION >= 3004 && defined(__i386__)
# define ZEPHIR_FASTCALL __attribute__((fastcall))
#elif defined(_MSC_VER) && defined(_M_IX86)
# define ZEPHIR_FASTCALL __fastcall
#else
# define ZEPHIR_FASTCALL
#endif

#define ZEPHIR_INIT_CLASS(name) \
	int zephir_ ##name## _init(INIT_FUNC_ARGS)

#define ZEPHIR_INIT(name) \
	if (zephir_ ##name## _init(INIT_FUNC_ARGS_PASSTHRU) == FAILURE) { \
		return FAILURE; \
	}

#if defined(__GNUC__) && (defined(__clang__) || ((__GNUC__ * 100 + __GNUC_MINOR__) >= 405))
# define UNREACHABLE() __builtin_unreachable()
# define ASSUME(x) if (x) {} else __builtin_unreachable()
#else
# define UNREACHABLE() assert(0)
# define ASSUME(x) assert(!!(x));
#endif

#if defined(__GNUC__) || defined(__clang__)
# define ZEPHIR_ATTR_NONNULL __attribute__((nonnull))
# define ZEPHIR_ATTR_NONNULL1(x) __attribute__((nonnull (x)))
# define ZEPHIR_ATTR_NONNULL2(x, y) __attribute__((nonnull (x, y)))
# define ZEPHIR_ATTR_NONNULL3(x, y, z) __attribute__((nonnull (x, y, z)))
# define ZEPHIR_ATTR_PURE __attribute__((pure))
# define ZEPHIR_ATTR_CONST __attribute__((const))
# define ZEPHIR_ATTR_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define ZEPHIR_ATTR_NONNULL
# define ZEPHIR_ATTR_NONNULL1(x)
# define ZEPHIR_ATTR_NONNULL2(x, y)
# define ZEPHIR_ATTR_NONNULL3(x, y, z)
# define ZEPHIR_ATTR_PURE
# define ZEPHIR_ATTR_CONST
# define ZEPHIR_ATTR_WARN_UNUSED_RESULT
#endif

#if !defined(__GNUC__) && !(defined(__SUNPRO_C) && (__SUNPRO_C >= 0x590))
# define __builtin_constant_p(s) (0)
#endif

#ifndef __func__
# define __func__ __FUNCTION__
#endif

#if defined(__GNUC__)
# define ZEPHIR_NO_OPT __attribute__((optimize("O0")))
#else
# define ZEPHIR_NO_OPT
#endif

#define likely(x)   EXPECTED(x)
#define unlikely(x) UNEXPECTED(x)

#ifndef ZEND_ACC_DTOR
 #define ZEND_ACC_DTOR 0
#endif

#endif


#define PHP_PHALCON_NAME        "phalcon"
#define PHP_PHALCON_VERSION     "5.7.0"
#define PHP_PHALCON_EXTNAME     "phalcon"
#define PHP_PHALCON_AUTHOR      "Phalcon Team and contributors"
#define PHP_PHALCON_ZEPVERSION  "0.18.0-$Id$"
#define PHP_PHALCON_DESCRIPTION "Phalcon is a full stack PHP framework, delivered as a PHP extension, offering lower resource consumption and high performance."

typedef struct _zephir_struct_db { 
	zend_bool escape_identifiers;
	zend_bool force_casting;
} zephir_struct_db;

typedef struct _zephir_struct_form { 
	zend_bool strict_entity_property_check;
} zephir_struct_form;

typedef struct _zephir_struct_orm { 
	HashTable*  ast_cache;
	int cache_level;
	zend_bool case_insensitive_column_map;
	zend_bool cast_last_insert_id_to_int;
	zend_bool cast_on_hydrate;
	zend_bool column_renaming;
	zend_bool disable_assign_setters;
	zend_bool enable_implicit_joins;
	zend_bool enable_literals;
	zend_bool events;
	zend_bool exception_on_failed_save;
	zend_bool exception_on_failed_metadata_save;
	zend_bool ignore_unknown_columns;
	zend_bool late_state_binding;
	zend_bool not_null_validations;
	HashTable*  parser_cache;
	zend_string*  resultset_prefetch_records;
	int unique_cache_id;
	zend_bool update_snapshot_on_save;
	zend_bool virtual_foreign_keys;
	zend_bool dynamic_update;
} zephir_struct_orm;

typedef struct _zephir_struct_warning { 
	zend_bool enable;
} zephir_struct_warning;



ZEND_BEGIN_MODULE_GLOBALS(phalcon)

	int initialized;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
	zephir_struct_db db;
	zephir_struct_form form;
	zephir_struct_orm orm;
	zephir_struct_warning warning;

ZEND_END_MODULE_GLOBALS(phalcon)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(phalcon)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(phalcon, v)
#else
	#define ZEPHIR_GLOBAL(v) (phalcon_globals.v)
#endif

#ifdef ZTS
	ZEND_TSRMLS_CACHE_EXTERN()
	#define ZEPHIR_VGLOBAL ((zend_phalcon_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(phalcon_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(phalcon_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def phalcon_globals
#define zend_zephir_globals_def zend_phalcon_globals

extern zend_module_entry phalcon_module_entry;
#define phpext_phalcon_ptr &phalcon_module_entry

#endif
