
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
#define PHP_PHALCON_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <main/php.h>
#ifdef ZTS
#include <TSRM/TSRM.h>
#endif

#define PHP_PHALCON_VERSION "1.3.4"
#define PHP_PHALCON_EXTNAME "phalcon"

#define PHALCON_NUM_PREALLOCATED_FRAMES 25

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
	zend_bool permanent;
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

/** Security options */
typedef struct _phalcon_security_options {
	zend_bool crypt_std_des_supported;
	zend_bool crypt_ext_des_supported;
	zend_bool crypt_md5_supported;
	zend_bool crypt_blowfish_supported;
	zend_bool crypt_blowfish_y_supported;
	zend_bool crypt_sha256_supported;
	zend_bool crypt_sha512_supported;
} phalcon_security_options;

ZEND_BEGIN_MODULE_GLOBALS(phalcon)

	/* Controls double initialization of memory frames */
	int initialized;

	/** Memory */
	phalcon_memory_entry *start_memory;    /**< The first preallocated frame */
	phalcon_memory_entry *end_memory;      /**< The last preallocate frame */
	phalcon_memory_entry *active_memory;   /**< The current memory frame */

	/** Virtual Symbol Tables */
	phalcon_symbol_table *active_symbol_table;

	/** Frequently used zvals */
	zval *z_null;
	zval *z_true;
	zval *z_false;
	zval *z_zero;
	zval *z_one;

	/** Function cache */
	HashTable *fcache;

	/** ORM */
	phalcon_orm_options orm;

	/** Max recursion control */
	unsigned int recursive_lock;

	zend_bool register_psr3_classes;

	/** Security */
	phalcon_security_options security;

	/** DB */
	phalcon_db_options db;

ZEND_END_MODULE_GLOBALS(phalcon)


ZEND_EXTERN_MODULE_GLOBALS(phalcon)

#ifdef ZTS
	#define PHALCON_GLOBAL(v) TSRMG(phalcon_globals_id, zend_phalcon_globals *, v)
	#define PHALCON_VGLOBAL   ((zend_phalcon_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(phalcon_globals_id)])
#else
	#define PHALCON_GLOBAL(v) (phalcon_globals.v)
	#define PHALCON_VGLOBAL &(phalcon_globals)
#endif

extern zend_module_entry phalcon_module_entry;
#define phpext_phalcon_ptr &phalcon_module_entry

extern int nusphere_dbg_present;

/* Compatibility macros for PHP 5.3 */
#ifndef PHP_FE_END
	#define PHP_FE_END { NULL, NULL, NULL, 0, 0 }
#endif

#ifndef INIT_PZVAL_COPY
#	define INIT_PZVAL_COPY(z, v) \
		ZVAL_COPY_VALUE(z, v); \
		Z_SET_REFCOUNT_P(z, 1); \
		Z_UNSET_ISREF_P(z);
#endif

#ifndef ZVAL_COPY_VALUE
#	define ZVAL_COPY_VALUE(z, v) \
		(z)->value  = (v)->value; \
		Z_TYPE_P(z) = Z_TYPE_P(v);
#endif

#ifndef HASH_KEY_NON_EXISTENT
#	define HASH_KEY_NON_EXISTENT    HASH_KEY_NON_EXISTANT
#endif


#define PHALCON_INIT_CLASS(name) \
	int phalcon_ ##name## _init(TSRMLS_D)

#define PHALCON_INIT(name) \
	if (phalcon_ ##name## _init(TSRMLS_C) == FAILURE) { \
		return FAILURE; \
	}

/** Macros for branch prediction */
#define likely(x)       EXPECTED(x)
#define unlikely(x)     UNEXPECTED(x)

#if defined(__GNUC__) && (defined(__clang__) || ((__GNUC__ * 100 + __GNUC_MINOR__) >= 405))
#	define UNREACHABLE() __builtin_unreachable()
#	define ASSUME(x)     if (x) {} else __builtin_unreachable()
#else
#	define UNREACHABLE() assert(0)
#	define ASSUME(x)     assert(!!(x));
#endif

#if defined(__GNUC__) || defined(__clang__)
#	define PHALCON_ATTR_NONNULL            __attribute__((nonnull))
#	define PHALCON_ATTR_NONNULL1(x)        __attribute__((nonnull (x)))
#	define PHALCON_ATTR_NONNULL2(x, y)     __attribute__((nonnull (x, y)))
#	define PHALCON_ATTR_NONNULL3(x, y, z)  __attribute__((nonnull (x, y, z)))
#	define PHALCON_ATTR_PURE               __attribute__((pure))
#	define PHALCON_ATTR_CONST              __attribute__((const))
#	define PHALCON_ATTR_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
#	define PHALCON_ATTR_NONNULL
#	define PHALCON_ATTR_NONNULL1(x)
#	define PHALCON_ATTR_NONNULL2(x, y)
#	define PHALCON_ATTR_NONNULL3(x, y, z)
#	define PHALCON_ATTR_PURE
#	define PHALCON_ATTR_CONST
#	define PHALCON_ATTR_WARN_UNUSED_RESULT
#endif

#if !defined(__GNUC__) && !(defined(__SUNPRO_C) && (__SUNPRO_C >= 0x590))
#	define __builtin_constant_p(s)    (0)
#endif

#ifndef ZEND_MOD_END
#	define ZEND_MOD_END { NULL, NULL, NULL, 0 }
#endif

#ifndef __func__
#	define __func__ __FUNCTION__
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

#endif /* PHP_PHALCON_H */
