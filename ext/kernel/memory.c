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

#include "php.h"
#include "php_ext.h"
#include "kernel/memory.h"

#include <Zend/zend_alloc.h>

#include "kernel/fcall.h"
#include "kernel/backtrace.h"

/*
 * Memory Frames/Virtual Symbol Scopes
 *------------------------------------
 *
 * Zephir uses memory frames to track the variables used within a method
 * in order to free them or reduce their reference counting accordingly before
 * exit the method in execution.
 *
 * This adds a minimum overhead to execution but save us the work of
 * free memory in each method manually.
 *
 * The whole memory frame is an open double-linked list which start is an
 * allocated empty frame that points to the real first frame. The start
 * memory frame is globally accessed using ZEPHIR_GLOBAL(start_frame)
 *
 * Not all methods must grow/restore the zephir_memory_entry.
 */

static zend_always_inline zend_execute_data* find_symbol_table(zend_execute_data* ex)
{
    while (ex && (!ex->func || !ZEND_USER_CODE(ex->func->common.type))) {
        ex = ex->prev_execute_data;
    }

    return ex;
}

/**
 * Adds a memory frame in the current executed method
 */
void ZEPHIR_FASTCALL zephir_memory_grow_stack(zephir_method_globals *g, const char *func)
{
	if (g->active_memory == NULL) {
		zephir_memory_entry *active_memory;

		active_memory = (zephir_memory_entry *) pecalloc(1, sizeof(zephir_memory_entry), 0);

		active_memory->addresses = pecalloc(24, sizeof(zval*), 0);
		active_memory->capacity  = 24;

		g->active_memory = active_memory;
	}

	assert(g->active_memory != NULL);
	assert(g->active_memory->pointer == 0);

#ifndef ZEPHIR_RELEASE
	g->active_memory->func = func;
#endif
}

void ZEPHIR_FASTCALL zephir_memory_restore_stack(zephir_method_globals *g, const char *func)
{
	size_t i;
	zephir_memory_entry *active_memory;
	zephir_symbol_table *active_symbol_table;
	zval *ptr;
#ifndef ZEPHIR_RELEASE
	int show_backtrace = 0;
#endif

#ifndef ZEPHIR_RELEASE
	if (UNEXPECTED(g->active_memory == NULL)) {
		fprintf(stderr, "WARNING: calling zephir_memory_restore_stack() without an active memory frame!\n");
		fprintf(stderr, "The frame was created by %s\n", g->active_memory->func);
		fprintf(stderr, "Calling function: %s\n", func);
		zephir_print_backtrace();
		return;
	}

	if (UNEXPECTED(g->active_memory->func != func)) {
		fprintf(stderr, "Trying to free someone else's memory frame!\n");
		fprintf(stderr, "The frame was created by %s\n", g->active_memory->func);
		fprintf(stderr, "Calling function: %s\n", func);
		zephir_print_backtrace();
		return;
	}
#endif

	active_memory = g->active_memory;
	assert(active_memory != NULL);

	if (EXPECTED(!CG(unclean_shutdown))) {
		/* Clean active symbol table */
		if (g->active_symbol_table) {
			active_symbol_table = g->active_symbol_table;
			while (active_symbol_table && active_symbol_table->scope == active_memory) {
				zend_execute_data *ex = find_symbol_table(EG(current_execute_data));
#ifndef ZEPHIR_RELEASE
				if (UNEXPECTED(!ex)) {
					fprintf(stderr, "ERROR: unable to find a symbol table");
					zephir_print_backtrace();
					return;
				}
#endif
				zend_hash_destroy(ex->symbol_table);
				efree(ex->symbol_table);
				ex->symbol_table = active_symbol_table->symbol_table;
				zend_attach_symbol_table(ex);
				zend_rebuild_symbol_table();

				g->active_symbol_table = active_symbol_table->prev;
				efree(active_symbol_table);
				active_symbol_table = g->active_symbol_table;
			}
		}

#ifndef ZEPHIR_RELEASE
		for (i = 0; i < active_memory->pointer; ++i) {
			if (active_memory->addresses[i] != NULL) {
				zval *var = active_memory->addresses[i];
				if (Z_TYPE_P(var) > IS_CALLABLE) {
					fprintf(stderr, "%s: observed variable #%d (%p) has invalid type %u [%s]\n", __func__, (int)i, var, Z_TYPE_P(var), active_memory->func);
					show_backtrace = 1;
				}

				if (!Z_REFCOUNTED_P(var)) {
					continue;
				}

				if (Z_REFCOUNT_P(var) == 0) {
					fprintf(stderr, "%s: observed variable #%d (%p) has 0 references, type=%d [%s]\n", __func__, (int)i, var, Z_TYPE_P(var), active_memory->func);
					show_backtrace = 1;
				}
				else if (Z_REFCOUNT_P(var) >= 1000000) {
					fprintf(stderr, "%s: observed variable #%d (%p) has too many references (%u), type=%d  [%s]\n", __func__, (int)i, var, Z_REFCOUNT_P(var), Z_TYPE_P(var), active_memory->func);
					show_backtrace = 1;
				}
			}
		}
#endif

		/* Traverse all zvals allocated, reduce the reference counting or free them */
		for (i = 0; i < active_memory->pointer; ++i) {
			ptr = active_memory->addresses[i];
			if (EXPECTED(ptr != NULL)) {
				if (!Z_REFCOUNTED_P(ptr)) continue;
				if (Z_REFCOUNT_P(ptr) == 1) {
					zval_ptr_dtor(ptr);
				} else {
					Z_DELREF_P(ptr);
				}
			}
		}
	}

#ifndef ZEPHIR_RELEASE
	active_memory->func = NULL;
#endif

	if (active_memory->addresses != NULL) {
		pefree(active_memory->addresses, 0);
	}

	pefree(g->active_memory, 0);
	g->active_memory = NULL;

#ifndef ZEPHIR_RELEASE
	if (show_backtrace == 1) {
		zephir_print_backtrace();
	}
#endif
}

/**
 * Pre-allocates memory for further use in execution
 */
void zephir_initialize_memory(zend_zephir_globals_def *zephir_globals_ptr)
{
	zephir_globals_ptr->fcache = pemalloc(sizeof(HashTable), 1);
	zend_hash_init(zephir_globals_ptr->fcache, 128, NULL, NULL, 1); // zephir_fcall_cache_dtor

	zephir_globals_ptr->initialized = 1;
}

/**
 * Deinitializes all the memory allocated by Zephir
 */
void zephir_deinitialize_memory()
{
	zend_zephir_globals_def *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	if (zephir_globals_ptr->initialized != 1) {
		zephir_globals_ptr->initialized = 0;
		return;
	}

	zend_hash_destroy(zephir_globals_ptr->fcache);
	pefree(zephir_globals_ptr->fcache, 1);
	zephir_globals_ptr->fcache = NULL;

	zephir_globals_ptr->initialized = 0;
}

/**
 * Creates a virtual symbol tables dynamically
 */
void zephir_create_symbol_table(zephir_method_globals *gptr)
{
	zephir_symbol_table *entry;
	zend_array *symbol_table;

#ifndef ZEPHIR_RELEASE
	if (!gptr->active_memory) {
		fprintf(stderr, "ERROR: Trying to create a virtual symbol table without a memory frame");
		zephir_print_backtrace();
		return;
	}
#endif

	zend_execute_data* ex = find_symbol_table(EG(current_execute_data));
#ifndef ZEPHIR_RELEASE
    if (UNEXPECTED(!ex)) {
        fprintf(stderr, "ERROR: unable to find a symbol table");
        zephir_print_backtrace();
        return;
    }
#endif

	zend_rebuild_symbol_table();
	zend_detach_symbol_table(ex);

	entry               = (zephir_symbol_table*)emalloc(sizeof(zephir_symbol_table));
	entry->scope        = gptr->active_memory;
	entry->symbol_table = ex->symbol_table;
	entry->prev         = gptr->active_symbol_table;

	symbol_table = (zend_array*)emalloc(sizeof(zend_array));
	zend_hash_init(symbol_table, 0, NULL, ZVAL_PTR_DTOR, 0);
	zend_hash_real_init(symbol_table, 0);

	ex->symbol_table          = symbol_table;
	gptr->active_symbol_table = entry;
}

/**
 * Exports symbols to the active symbol table
 */
int zephir_set_symbol(zval *key_name, zval *value)
{
	zend_array *symbol_table;

	symbol_table = zend_rebuild_symbol_table();
	if (!symbol_table) {
		php_error_docref(NULL, E_WARNING, "Cannot find a valid symbol_table");
		return FAILURE;
	}

	if (Z_TYPE_P(key_name) == IS_STRING) {
		Z_TRY_ADDREF_P(value);
		zend_hash_update(symbol_table, Z_STR_P(key_name), value);
	}

	return SUCCESS;
}

/**
 * Exports a string symbol to the active symbol table
 */
int zephir_set_symbol_str(char *key_name, unsigned int key_length, zval *value)
{
	zend_array *symbol_table = zend_rebuild_symbol_table();

	if (!symbol_table) {
		php_error_docref(NULL, E_WARNING, "Cannot find a valid symbol_table");
		return FAILURE;
	}

	Z_TRY_ADDREF_P(value);
	zend_hash_str_update(symbol_table, key_name, key_length, value);

	return SUCCESS;
}

/**
 * Cleans the function/method cache up
 */
int zephir_cleanup_fcache(void *pDest, int num_args, va_list args, zend_hash_key *hash_key)
{
	zephir_fcall_cache_entry **entry = (zephir_fcall_cache_entry**) pDest;
	zend_class_entry *scope;
	size_t len = ZSTR_LEN(hash_key->key);

	assert(hash_key->key != NULL);
	assert(len > 2 * sizeof(zend_class_entry**));

	memcpy(&scope, &ZSTR_VAL(hash_key->key)[(len -1) - 2 * sizeof(zend_class_entry**)], sizeof(zend_class_entry*));

/*
#ifndef ZEPHIR_RELEASE
	{
		zend_class_entry *cls;
		memcpy(&cls, &hash_key->arKey[len - sizeof(zend_class_entry**)], sizeof(zend_class_entry*));

		fprintf(stderr, "func: %s, cls: %s, scope: %s [%u]\n", (*entry)->f->common.function_name, (cls ? cls->name : "N/A"), (scope ? scope->name : "N/A"), (uint)(*entry)->times);
	}
#endif
*/

	if ((*entry)->type != ZEND_INTERNAL_FUNCTION || (scope && scope->type != ZEND_INTERNAL_CLASS)) {
		return ZEND_HASH_APPLY_REMOVE;
	}

	if (scope && scope->type == ZEND_INTERNAL_CLASS && scope->info.internal.module->type != MODULE_PERSISTENT) {
		return ZEND_HASH_APPLY_REMOVE;
	}

	return ZEND_HASH_APPLY_KEEP;
}

void ZEPHIR_FASTCALL zephir_do_memory_observe(zval *var, const zephir_method_globals *g)
{
	zephir_memory_entry *frame = g->active_memory;
#ifndef ZEPHIR_RELEASE
	if (UNEXPECTED(frame == NULL)) {
		fprintf(stderr, "ZEPHIR_MM_GROW() must be called before using any of MM functions or macros!");
		zephir_print_backtrace();
		abort();
	}
#endif

	if (UNEXPECTED(frame->pointer == frame->capacity)) {
		void *buf = perealloc(frame->addresses, sizeof(zval *) * (frame->capacity + 16), 0);
		if (EXPECTED(buf != NULL)) {
			frame->capacity += 16;
			frame->addresses = buf;
		} else {
			zend_error(E_CORE_ERROR, "Memory allocation failed");
			return;
		}
	}

#ifndef ZEPHIR_RELEASE
	{
		size_t i;
		for (i = 0; i < frame->pointer; ++i) {
			if (frame->addresses[i] == var) {
				fprintf(stderr, "Variable %p is already observed", var);
				zephir_print_backtrace();
				abort();
			}
		}
	}
#endif

	frame->addresses[frame->pointer] = var;
	++frame->pointer;
}
