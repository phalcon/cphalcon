
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

#define PHP_PHALCON_VERSION "1.2.0"
#define PHP_PHALCON_EXTNAME "phalcon"

#define PHALCON_RELEASE 1

#define PHALCON_MAX_MEMORY_STACK 48

/** Memory frame */
typedef struct _phalcon_memory_entry {
	int pointer;
	zval ***addresses;
	int hash_pointer;
	zval ***hash_addresses;
	struct _phalcon_memory_entry *prev;
	struct _phalcon_memory_entry *next;
} phalcon_memory_entry;

/** Virtual Symbol Table */
typedef struct _phalcon_symbol_table {
	struct _phalcon_memory_entry *scope;
	HashTable *symbol_table;
	struct _phalcon_symbol_table *prev;
} phalcon_symbol_table;

/** ORM options */
typedef struct _phalcon_orm_options {
	zend_bool events;
	zend_bool virtual_foreign_keys;
	zend_bool column_renaming;
	zend_bool not_null_validations;
	zend_bool exception_on_failed_save;
	zend_bool enable_literals;
	int cache_level;
	int unique_cache_id;
	HashTable *parser_cache;
	HashTable *ast_cache;
} phalcon_orm_options;

/** DB options */
typedef struct _phalcon_db_options {
	zend_bool escape_identifiers;
} phalcon_db_options;

ZEND_BEGIN_MODULE_GLOBALS(phalcon)

	/** Memory */
	phalcon_memory_entry *start_memory;
	phalcon_memory_entry *active_memory;

	/** Virtual Symbol Tables */
	phalcon_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *function_cache;

	/** Max recursion control */
	unsigned int recursive_lock;

	/** Stats */
#ifndef PHALCON_RELEASE
	unsigned int phalcon_stack_stats;
	unsigned int phalcon_number_grows;
#endif

	/** ORM */
	phalcon_orm_options orm;

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
#if defined(__GNUC__) && ZEND_GCC_VERSION >= 3004 && defined(__i386__)
# define PHALCON_FASTCALL __attribute__((fastcall))
#elif defined(_MSC_VER) && defined(_M_IX86)
# define PHALCON_FASTCALL __fastcall
#else
# define PHALCON_FASTCALL
#endif

#ifndef PHALCON_RELEASE
#define PHALCON_INIT_CLASS(name) \
	int inline phalcon_ ##name## _init(INIT_FUNC_ARGS)
#else
#define PHALCON_INIT_CLASS(name) \
	static inline int phalcon_ ##name## _init(INIT_FUNC_ARGS)
#endif

#define PHALCON_INIT(name) \
	if (phalcon_ ##name## _init(INIT_FUNC_ARGS_PASSTHRU) == FAILURE) { \
		return FAILURE; \
	}

#if PHP_VERSION_ID >= 50400
#define PHALCON_EXPERIMENTAL_FCALL 0
#else
#define PHALCON_EXPERIMENTAL_FCALL 1
#endif

/** Macros for branch prediction */
#if defined(__GNUC__) && ZEND_GCC_VERSION >= 3004 && defined(__i386__)
#define likely(x)       __builtin_expect((x),1)
#define unlikely(x)     __builtin_expect((x),0)
#else
#define likely(x)       x
#define unlikely(x)     x
#endif
