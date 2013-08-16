
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "main/php.h"
#include "php_phalcon.h"

#include "Zend/zend_alloc.h"

#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/backtrace.h"

/*
 * Memory Frames/Virtual Symbol Scopes
 *------------------------------------
 *
 * Phalcon uses memory frames to track the variables used within a method
 * in order to free them or reduce their reference counting accordingly before
 * exit the method in execution.
 *
 * This adds a minimum overhead to execution but save us the work of
 * free memory in each method.
 *
 * The whole memory frame is an open double-linked list which start is an
 * allocated empty frame that points to the real first frame. The start
 * memory frame is globally accesed using PHALCON_GLOBAL(start_frame)
 *
 * Not all methods must grown/restore the phalcon_memory_entry.
 */

/**
 * Initializes/Reinitializes a variable
 */
inline void phalcon_init_nvar(zval **var TSRMLS_DC) {
	if (*var) {
		if (Z_REFCOUNT_PP(var) > 1) {
			Z_DELREF_PP(var);
			ALLOC_ZVAL(*var);
			Z_SET_REFCOUNT_PP(var, 1);
			Z_UNSET_ISREF_PP(var);
		} else {
			zval_ptr_dtor(var);
			PHALCON_ALLOC_ZVAL(*var);
		}
	} else {
		phalcon_memory_alloc(var TSRMLS_CC);
	}
}

/**
 * Copy/Write variables caring of reference counting
 */
inline void phalcon_cpy_wrt(zval **dest, zval *var TSRMLS_DC) {

	if (*dest) {
		if (Z_REFCOUNT_PP(dest) > 0) {
			zval_ptr_dtor(dest);
		}
	} else {
		phalcon_memory_observe(dest TSRMLS_CC);
	}

	Z_ADDREF_P(var);
	*dest = var;
}

/**
 * Copy/Write variables caring of reference counting also duplicating the origin ctor
 */
inline void phalcon_cpy_wrt_ctor(zval **dest, zval *var TSRMLS_DC) {

	if (*dest) {
		if (Z_REFCOUNT_PP(dest) > 0) {
			zval_ptr_dtor(dest);
		}
	} else {
		phalcon_memory_observe(dest TSRMLS_CC);
	}

	Z_ADDREF_P(var);
	*dest = var;
	zval_copy_ctor(*dest);
	Z_SET_REFCOUNT_PP(dest, 1);
	Z_UNSET_ISREF_PP(dest);
}

static phalcon_memory_entry* phalcon_memory_grow_stack_common(zend_phalcon_globals *phalcon_globals_ptr)
{
	assert(phalcon_globals_ptr->start_memory != NULL);
	if (!phalcon_globals_ptr->active_memory) {
		phalcon_globals_ptr->active_memory = phalcon_globals_ptr->start_memory;
		return phalcon_globals_ptr->start_memory;
	}

	{
		phalcon_memory_entry *entry = (phalcon_memory_entry *) ecalloc(1, sizeof(phalcon_memory_entry));
	/* ecalloc() will take care of these members
		entry->pointer   = 0;
		entry->capacity  = 0;
		entry->addresses = NULL;
		entry->hash_pointer   = 0;
		entry->hash_capacity  = 0;
		entry->hash_addresses = NULL;
		entry->next = NULL;
	*/
		entry->prev       = phalcon_globals_ptr->active_memory;
		entry->prev->next = entry;
		phalcon_globals_ptr->active_memory = entry;
		return entry;
	}
}

static void phalcon_memory_restore_stack_common(zend_phalcon_globals *phalcon_globals_ptr TSRMLS_DC) {

	size_t i;
	phalcon_memory_entry *prev, *active_memory;
	phalcon_symbol_table *active_symbol_table;
#if ZEND_DEBUG
	char* __zend_filename = __FILE__;
	char* __zend_orig_filename = __FILE__;
	int __zend_lineno = 0;
	int __zend_orig_lineno = 0;
#endif

	active_memory = phalcon_globals_ptr->active_memory;
	assert(active_memory != NULL);

	if (phalcon_globals_ptr->active_symbol_table) {
		active_symbol_table = phalcon_globals_ptr->active_symbol_table;
		if (active_symbol_table->scope == active_memory) {
			zend_hash_destroy(EG(active_symbol_table));
			FREE_HASHTABLE(EG(active_symbol_table));
			EG(active_symbol_table) = active_symbol_table->symbol_table;
			phalcon_globals_ptr->active_symbol_table = active_symbol_table->prev;
			efree(active_symbol_table);
		}
	}

	/**
	 * Check for non freed hash key zvals, mark as null to avoid string freeing
	 */
	for (i = 0; i < active_memory->hash_pointer; ++i) {
		assert(active_memory->hash_addresses[i] != NULL && *(active_memory->hash_addresses[i]) != NULL);

#if ZEND_DEBUG
		_mem_block_check(*active_memory->hash_addresses[i], 1 ZEND_FILE_LINE_RELAY_CC ZEND_FILE_LINE_ORIG_RELAY_CC);
#endif

		if (Z_REFCOUNT_PP(active_memory->hash_addresses[i]) <= 1) {
			ZVAL_NULL(*active_memory->hash_addresses[i]);
		} else {
			zval_copy_ctor(*active_memory->hash_addresses[i]);
		}
	}

#ifndef PHALCON_RELEASE
	for (i = 0; i < active_memory->pointer; ++i) {
		if (likely(active_memory->addresses[i] != NULL && *(active_memory->addresses[i]) != NULL)) {
			zval **var = active_memory->addresses[i];

#if ZEND_DEBUG
			_mem_block_check(*var, 1 ZEND_FILE_LINE_RELAY_CC ZEND_FILE_LINE_ORIG_RELAY_CC);
#endif

#if PHP_VERSION_ID < 50400
			if (Z_TYPE_PP(var) > IS_CONSTANT_ARRAY) {
				fprintf(stderr, "%s: observed variable #%d (%p) has invalid type %u\n", __func__, (int)i, *var, Z_TYPE_PP(var));
			}
#else
			if (Z_TYPE_PP(var) > IS_CALLABLE) {
				fprintf(stderr, "%s: observed variable #%d (%p) has invalid type %u\n", __func__, (int)i, *var, Z_TYPE_PP(var));
			}
#endif

			if (Z_REFCOUNT_PP(var) == 0) {
				fprintf(stderr, "%s: observed variable #%d (%p) has 0 references\n", __func__, (int)i, *var);
			}
			else if (Z_REFCOUNT_PP(var) >= 1000000) {
				fprintf(stderr, "%s: observed variable #%d (%p) has too many references (%u)\n", __func__, (int)i, *var, Z_REFCOUNT_PP(var));
			}
			else if (Z_REFCOUNT_PP(var) == 1 && Z_ISREF_PP(var)) {
				fprintf(stderr, "%s: observed variable #%d (%p) is a reference with reference count = 1\n", __func__, (int)i, *var);
			}
		}
	}
#endif

	/**
	 * Traverse all zvals allocated, reduce the reference counting or free them
	 */
	for (i = 0; i < active_memory->pointer; ++i) {
		if (likely(active_memory->addresses[i] != NULL && *(active_memory->addresses[i]) != NULL)) {
			if (Z_REFCOUNT_PP(active_memory->addresses[i]) == 1) {
				zval_ptr_dtor(active_memory->addresses[i]);
			} else {
				Z_DELREF_PP(active_memory->addresses[i]);
			}
		}
	}

	prev = active_memory->prev;

	if (prev != NULL) {
		if (active_memory->hash_addresses != NULL) {
			efree(active_memory->hash_addresses);
		}

		if (likely(active_memory->addresses != NULL)) {
			efree(active_memory->addresses);
		}

		efree(phalcon_globals_ptr->active_memory);
		phalcon_globals_ptr->active_memory = prev;
		prev->next = NULL;
	} else {
		assert(phalcon_globals_ptr->start_memory == active_memory);
		assert(active_memory->next == NULL);
		active_memory->pointer      = 0;
		active_memory->hash_pointer = 0;
		phalcon_globals_ptr->active_memory = NULL;
	}
}

/**
 * Finishes the current memory stack by releasing allocated memory
 */
int PHALCON_FASTCALL phalcon_memory_restore_stack(const char *func TSRMLS_DC)
{
	zend_phalcon_globals *phalcon_globals_ptr = PHALCON_VGLOBAL;

	if (unlikely(phalcon_globals_ptr->active_memory == NULL)) {
		fprintf(stderr, "WARNING: calling phalcon_memory_restore_stack() without an active memory frame!\n");
		phalcon_print_backtrace();
		return FAILURE;
	}

	if (unlikely(phalcon_globals_ptr->active_memory->func != func)) {
		fprintf(stderr, "Trying to free someone else's memory frame!\n");
		fprintf(stderr, "The frame was created by %s\n", phalcon_globals_ptr->active_memory->func);
		fprintf(stderr, "Calling function: %s\n", func);
		phalcon_print_backtrace();
	}

	phalcon_globals_ptr->active_memory->func = NULL;

	phalcon_memory_restore_stack_common(phalcon_globals_ptr TSRMLS_CC);
	return SUCCESS;
}

#ifndef PHALCON_RELEASE
/**
 * Adds a memory frame in the current executed method
 */
void PHALCON_FASTCALL phalcon_memory_grow_stack(const char *func TSRMLS_DC) {

	phalcon_memory_entry *entry = phalcon_memory_grow_stack_common(PHALCON_VGLOBAL);
	entry->func = func;
}
#else
/**
 * Adds a memory frame in the current executed method
 */
void PHALCON_FASTCALL phalcon_memory_grow_stack(TSRMLS_D) {
	phalcon_memory_grow_stack_common(PHALCON_VGLOBAL);
}

/**
 * Finishes the current memory stack by releasing allocated memory
 */
int PHALCON_FASTCALL phalcon_memory_restore_stack(TSRMLS_D) {
	phalcon_memory_restore_stack_common(PHALCON_VGLOBAL TSRMLS_CC);
}
#endif

static void phalcon_reallocate_memory(phalcon_memory_entry *frame)
{
	void *buf = perealloc(frame->addresses, sizeof(zval **) * (frame->capacity + 16), unlikely(frame->prev == NULL));
	if (likely(buf != NULL)) {
		frame->capacity += 16;
		frame->addresses = buf;
	}
	else {
		zend_error(E_CORE_ERROR, "Memory allocation failed");
	}
}

static void phalcon_reallocate_hmemory(phalcon_memory_entry *frame)
{
	void *buf = perealloc(frame->hash_addresses, sizeof(zval **) * (frame->hash_capacity + 4), unlikely(frame->prev == NULL));
	if (likely(buf != NULL)) {
		frame->hash_capacity += 4;
		frame->hash_addresses = buf;
	}
	else {
		zend_error(E_CORE_ERROR, "Memory allocation failed");
	}
}

static inline void phalcon_do_memory_observe(zval **var, phalcon_memory_entry *frame)
{
#ifndef PHALCON_RELEASE
	if (unlikely(frame == NULL)) {
		TSRMLS_FETCH();
		fprintf(stderr, "PHALCON_MM_GROW() must be called before using any of MM functions or macros!");
		phalcon_memory_grow_stack("N/A" TSRMLS_CC);
	}
#endif

	if (unlikely(frame->pointer == frame->capacity)) {
		phalcon_reallocate_memory(frame);
	}

	frame->addresses[frame->pointer] = var;
	++frame->pointer;
}

/**
 * Observes a memory pointer to release its memory at the end of the request
 */
void PHALCON_FASTCALL phalcon_memory_observe(zval **var TSRMLS_DC) {

	phalcon_do_memory_observe(var, PHALCON_GLOBAL(active_memory));
	*var = NULL; /* In case an exception or error happens BEFORE the observed variable gets initialized */
}

/**
 * Observes a variable and allocates memory for it
 */
void PHALCON_FASTCALL phalcon_memory_alloc(zval **var TSRMLS_DC) {

	phalcon_do_memory_observe(var, PHALCON_GLOBAL(active_memory));
	ALLOC_INIT_ZVAL(*var);
}

/**
 * Observes a variable and allocates memory for it
 * Marks hash key zvals to be nulled before freeing
 */
void PHALCON_FASTCALL phalcon_memory_alloc_pnull(zval **var TSRMLS_DC) {

	phalcon_memory_entry *active_memory = PHALCON_GLOBAL(active_memory);

	phalcon_do_memory_observe(var, active_memory);
	ALLOC_INIT_ZVAL(*var);

	if (active_memory->hash_pointer == active_memory->hash_capacity) {
		phalcon_reallocate_hmemory(active_memory);
	}

	active_memory->hash_addresses[active_memory->hash_pointer] = var;
	++active_memory->hash_pointer;
}

/**
 * Removes a memory pointer from the active memory pool
 */
void PHALCON_FASTCALL phalcon_memory_remove(zval **var TSRMLS_DC) {
	zval_ptr_dtor(var);
	*var = NULL;
}

/**
 * Cleans the phalcon memory stack recursivery
 */
int PHALCON_FASTCALL phalcon_clean_restore_stack(TSRMLS_D) {

	zend_phalcon_globals *phalcon_globals_ptr = PHALCON_VGLOBAL;

	while (phalcon_globals_ptr->active_memory != NULL) {
		phalcon_memory_restore_stack_common(phalcon_globals_ptr TSRMLS_CC);
	}

	return SUCCESS;
}

/**
 * Copies a variable only if its refcount is greater than 1
 */
void PHALCON_FASTCALL phalcon_copy_ctor(zval *destination, zval *origin) {
	if (Z_REFCOUNT_P(origin) > 1) {
		zval_copy_ctor(destination);
	} else {
		ZVAL_NULL(origin);
	}
}

/**
 * Creates virtual symbol tables dynamically
 */
void phalcon_create_symbol_table(TSRMLS_D) {

	phalcon_symbol_table *entry;
	zend_phalcon_globals *phalcon_globals_ptr = PHALCON_VGLOBAL;
	HashTable *symbol_table;

	#ifndef PHALCON_RELEASE
	if (!phalcon_globals_ptr->active_memory) {
		fprintf(stderr, "ERROR: Trying to create a virtual symbol table without a memory frame");
		phalcon_print_backtrace();
		return;
	}
	#endif

	entry = (phalcon_symbol_table *) emalloc(sizeof(phalcon_symbol_table));
	entry->scope = phalcon_globals_ptr->active_memory;
	entry->symbol_table = EG(active_symbol_table);
	entry->prev = phalcon_globals_ptr->active_symbol_table;
	phalcon_globals_ptr->active_symbol_table = entry;

	ALLOC_HASHTABLE(symbol_table);
	zend_hash_init(symbol_table, 0, NULL, ZVAL_PTR_DTOR, 0);
	EG(active_symbol_table) = symbol_table;
}

/**
 * Restores all the virtual symbol tables
 */
void phalcon_clean_symbol_tables(TSRMLS_D) {

	/*unsigned int i;

	if (PHALCON_GLOBAL(symbol_tables)) {
		for (i = PHALCON_GLOBAL(number_symbol_tables); i > 0; i--) {
			EG(active_symbol_table) = PHALCON_GLOBAL(symbol_tables)[i - 1];
		}
		efree(PHALCON_GLOBAL(symbol_tables));
		PHALCON_GLOBAL(symbol_tables) = NULL;
	}*/
}

/**
 * Exports symbols to the active symbol table
 */
int phalcon_set_symbol(zval *key_name, zval *value TSRMLS_DC) {

	if (!EG(active_symbol_table)) {
		zend_rebuild_symbol_table(TSRMLS_C);
	}

	if (EG(active_symbol_table)) {
		if (Z_TYPE_P(key_name) == IS_STRING) {
			Z_ADDREF_P(value);
			zend_hash_update(EG(active_symbol_table), Z_STRVAL_P(key_name), Z_STRLEN_P(key_name) + 1, &value, sizeof(zval *), NULL);
			if (EG(exception)) {
				return FAILURE;
			}
		}
	}

	return SUCCESS;
}

/**
 * Exports a string symbol to the active symbol table
 */
int phalcon_set_symbol_str(char *key_name, unsigned int key_length, zval *value TSRMLS_DC) {

	if (!EG(active_symbol_table)) {
		zend_rebuild_symbol_table(TSRMLS_C);
	}

	if (&EG(symbol_table)) {
		Z_ADDREF_P(value);
		zend_hash_update(&EG(symbol_table), key_name, key_length, &value, sizeof(zval *), NULL);
		if (EG(exception)) {
			return FAILURE;
		}
	}

	return SUCCESS;
}
