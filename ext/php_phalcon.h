
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_PHALCON_H
#define PHP_PHALCON_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_PHALCON_NAME        "phalcon"
#define PHP_PHALCON_VERSION     "5.6.1"
#define PHP_PHALCON_EXTNAME     "phalcon"
#define PHP_PHALCON_AUTHOR      "Phalcon Team and contributors"
#define PHP_PHALCON_ZEPVERSION  "0.18.0-$Id$"
#define PHP_PHALCON_DESCRIPTION "Phalcon is a full stack PHP framework, delivered as a PHP extension, offering lower resource consumption and high performance."

typedef struct _zephir_struct_db { 
	zend_bool escape_identifiers;
	zend_bool force_casting;
} zephir_struct_db;

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
