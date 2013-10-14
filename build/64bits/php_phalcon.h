
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
*/

#ifndef PHP_PHALCON_H
#define PHP_PHALCON_H 1

#define PHP_PHALCON_VERSION "1.3.0"
#define PHP_PHALCON_EXTNAME "phalcon"

#include "main/php.h"

/** Memory frame */
typedef struct _phalcon_memory_entry {
	size_t pointer;
	size_t capacity;
	zval ***addresses;
	size_t hash_pointer;
	size_t hash_capacity;
	zval ***hash_addresses;
	struct _phalcon_memory_entry *prev;
	struct _phalcon_memory_entry *next;
#ifndef PHALCON_RELEASE
	const char *func;
#endif
} phalcon_memory_entry;

/** Virtual Symbol Table */
typedef struct _phalcon_symbol_table {
	struct _phalcon_memory_entry *scope;
	HashTable *symbol_table;
	struct _phalcon_symbol_table *prev;
} phalcon_symbol_table;

/** ORM options */
typedef struct _phalcon_orm_options {
	HashTable *parser_cache;
	HashTable *ast_cache;
	int cache_level;
	int unique_cache_id;
	zend_bool events;
	zend_bool virtual_foreign_keys;
	zend_bool column_renaming;
	zend_bool not_null_validations;
	zend_bool exception_on_failed_save;
	zend_bool enable_literals;
} phalcon_orm_options;

/** DB options */
typedef struct _phalcon_db_options {
	zend_bool escape_identifiers;
} phalcon_db_options;

/** DI options */
typedef struct _phalcon_di_options {
	zval **injector;
	HashTable *shared_services_cache;
	zend_bool cache_enabled;
} phalcon_di_options;

ZEND_BEGIN_MODULE_GLOBALS(phalcon)

	/** Memory */
	phalcon_memory_entry *start_memory;
	phalcon_memory_entry *active_memory;

	/** Virtual Symbol Tables */
	phalcon_symbol_table *active_symbol_table;

	/** Frequently used zvals */
	zval *z_null;
	zval *z_true;
	zval *z_false;
	zval *z_zero;
	zval *z_one;

	/** Function cache */
	HashTable *function_cache;

	/** ORM */
	phalcon_orm_options orm;

	/** Max recursion control */
	unsigned int recursive_lock;

	/** DB */
	phalcon_db_options db;

ZEND_END_MODULE_GLOBALS(phalcon)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(phalcon)

#ifdef ZTS
	#define PHALCON_GLOBAL(v) TSRMG(phalcon_globals_id, zend_phalcon_globals *, v)
#else
	#define PHALCON_GLOBAL(v) (phalcon_globals.v)
#endif

#ifdef ZTS
	#define PHALCON_VGLOBAL ((zend_phalcon_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(phalcon_globals_id)])
#else
	#define PHALCON_VGLOBAL &(phalcon_globals)
#endif

extern zend_module_entry phalcon_module_entry;
#define phpext_phalcon_ptr &phalcon_module_entry

#endif

#if PHP_VERSION_ID >= 50400
	#define PHALCON_INIT_FUNCS(class_functions) static const zend_function_entry class_functions[] =
#else
	#define PHALCON_INIT_FUNCS(class_functions) static const function_entry class_functions[] =
#endif

#ifndef PHP_FE_END
	#define PHP_FE_END { NULL, NULL, NULL, 0, 0 }
#endif

/** Define FASTCALL */
#define PHALCON_FASTCALL ZEND_FASTCALL

#define PHALCON_INIT_CLASS(name) \
	int phalcon_ ##name## _init(INIT_FUNC_ARGS)

#define PHALCON_INIT(name) \
	if (phalcon_ ##name## _init(INIT_FUNC_ARGS_PASSTHRU) == FAILURE) { \
		return FAILURE; \
	}

/** Macros for branch prediction */
#define likely(x)       EXPECTED(x)
#define unlikely(x)     UNEXPECTED(x)

#if defined(__GNUC__) && (defined(__clang__) || ((__GNUC__ * 100 + __GNUC_MINOR__) >= 405))
#define UNREACHABLE() __builtin_unreachable()
#define ASSUME(x)     if (x) {} else __builtin_unreachable()
#else
#define UNREACHABLE() assert(0)
#define ASSUME(x)     assert(!!(x));
#endif

#if defined(__GNUC__) || defined(__clang__)
#define PHALCON_ATTR_NONNULL            __attribute__((nonnull))
#define PHALCON_ATTR_NONNULL1(x)        __attribute__((nonnull (x)))
#define PHALCON_ATTR_NONNULL2(x, y)     __attribute__((nonnull (x, y)))
#define PHALCON_ATTR_NONNULL3(x, y, z)  __attribute__((nonnull (x, y, z)))
#else
#define PHALCON_ATTR_NONNULL
#define PHALCON_ATTR_NONNULL1(x)
#define PHALCON_ATTR_NONNULL2(x, y)
#define PHALCON_ATTR_NONNULL3(x, y, z)
#endif

#ifndef ZEND_MOD_END
#define ZEND_MOD_END { NULL, NULL, NULL, 0 }
#endif

#ifndef __func__
#define __func__ __FUNCTION__
#endif

#if PHP_VERSION_ID > 50399
#	define ZLK_DC , const struct _zend_literal* key
#	define ZLK_CC , key
#	define ZLK_NULL_CC , NULL
#else
#	define ZLK_DC
#	define ZLK_CC
#	define ZLK_NULL_CC
#endif

#define PHALCON_STATIC

/* This is a temporary fix until config.w32 is updated */
#if !defined(__CYGWIN__) && defined(WIN32) && defined(HAVE_CONFIG_H)

#	if defined(HAVE_JSON) && !defined(PHALCON_USE_PHP_JSON)
#		define PHALCON_USE_PHP_JSON 1
#	endif

#	if defined(HAVE_BUNDLED_PCRE) && !defined(PHALCON_USE_PHP_PCRE)
#		define PHALCON_USE_PHP_PCRE 1
#	endif

#	if defined(HAVE_PHP_SESSION) && !defined(PHALCON_USE_PHP_SESSION)
#		define PHALCON_USE_PHP_SESSION 1
#	endif

#	if defined(HAVE_HASH_EXT) && !defined(PHALCON_USE_PHP_HASH)
#		define PHALCON_USE_PHP_HASH 1
#	endif

#endif /* !defined(__CYGWIN__) && !defined(WIN32) && defined(HAVE_CONFIG_H) */
