
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_PHALCON_H
#define PHP_PHALCON_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_PHALCON_NAME        "phalcon"
#define PHP_PHALCON_VERSION     "2.0.3"
#define PHP_PHALCON_EXTNAME     "phalcon"
#define PHP_PHALCON_AUTHOR      "Phalcon Team and contributors"
#define PHP_PHALCON_ZEPVERSION  "0.6.3a"
#define PHP_PHALCON_DESCRIPTION "Web framework delivered as a C-extension for PHP"

typedef struct _zephir_struct_db { 
	zend_bool escape_identifiers;
} zephir_struct_db;

typedef struct _zephir_struct_orm { 
	HashTable*  parser_cache;
	HashTable*  ast_cache;
	int cache_level;
	int unique_cache_id;
	zend_bool events;
	zend_bool virtual_foreign_keys;
	zend_bool column_renaming;
	zend_bool not_null_validations;
	zend_bool exception_on_failed_save;
	zend_bool enable_literals;
	zend_bool late_state_binding;
} zephir_struct_orm;



ZEND_BEGIN_MODULE_GLOBALS(phalcon)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
	zephir_struct_db db;

	zephir_struct_orm orm;


ZEND_END_MODULE_GLOBALS(phalcon)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(phalcon)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(phalcon_globals_id, zend_phalcon_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (phalcon_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_phalcon_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(phalcon_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(phalcon_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def phalcon_globals
#define zend_zephir_globals_def zend_phalcon_globals

extern zend_module_entry phalcon_module_entry;
#define phpext_phalcon_ptr &phalcon_module_entry

#endif
