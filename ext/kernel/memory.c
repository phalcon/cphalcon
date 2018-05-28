
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2017 Zephir Team (http://www.zephir-lang.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@zephir-lang.com so we can send you a copy immediately.      |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@zephir-lang.com>                     |
  |          Eduar Carvajal <eduar@zephir-lang.com>                        |
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
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

static zephir_memory_entry* zephir_memory_grow_stack_common(zend_zephir_globals_def *g)
{
	assert(g->start_memory != NULL);
	if (!g->active_memory) {
		g->active_memory = g->start_memory;
#ifndef ZEPHIR_RELEASE
		assert(g->active_memory->permanent == 1);
#endif
	}
	else if (!g->active_memory->next) {
#ifndef PHP_WIN32
		assert(g->active_memory >= g->end_memory - 1 || g->active_memory < g->start_memory);
#endif
		zephir_memory_entry *entry = (zephir_memory_entry *) ecalloc(1, sizeof(zephir_memory_entry));
#ifndef ZEPHIR_RELEASE
		entry->permanent  = 0;
		entry->func       = NULL;
#endif
		entry->prev       = g->active_memory;
		entry->prev->next = entry;
		g->active_memory  = entry;
	}
	else {
#ifndef ZEPHIR_RELEASE
		assert(g->active_memory->permanent == 1);
#endif
		assert(g->active_memory < g->end_memory && g->active_memory >= g->start_memory);
		g->active_memory = g->active_memory->next;
	}

	assert(g->active_memory->pointer == 0);
	assert(g->active_memory->hash_pointer == 0);

	return g->active_memory;
}

/**
 * Restore a memory stack applying GC to all observed variables
 */
static void zephir_memory_restore_stack_common(zend_zephir_globals_def *g)
{
	size_t i;
	zephir_memory_entry *prev, *active_memory;
	zephir_symbol_table *active_symbol_table;
	zval *ptr;
#ifndef ZEPHIR_RELEASE
	int show_backtrace = 0;
#endif

	active_memory = g->active_memory;
	assert(active_memory != NULL);

	if (EXPECTED(!CG(unclean_shutdown))) {
		/* Clean active symbol table */
		if (g->active_symbol_table) {
			active_symbol_table = g->active_symbol_table;
			while (active_symbol_table && active_symbol_table->scope == active_memory) {
				zend_execute_data *ex = EG(current_execute_data);

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

		/* Check for non freed hash key zvals, mark as null to avoid string freeing */
		for (i = 0; i < active_memory->hash_pointer; ++i) {
			assert(active_memory->hash_addresses[i] != NULL);
			if (!Z_REFCOUNTED_P(active_memory->hash_addresses[i])) continue;
			if (Z_REFCOUNT_P(active_memory->hash_addresses[i]) <= 1) {
				ZVAL_NULL(active_memory->hash_addresses[i]);
			} else {
				zval_copy_ctor(active_memory->hash_addresses[i]);
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

	prev = active_memory->prev;

	if (active_memory >= g->end_memory || active_memory < g->start_memory) {
#ifndef ZEPHIR_RELEASE
		assert(g->active_memory->permanent == 0);
#endif
		assert(prev != NULL);

		if (active_memory->hash_addresses != NULL) {
			efree(active_memory->hash_addresses);
		}

		if (active_memory->addresses != NULL) {
			efree(active_memory->addresses);
		}

		efree(g->active_memory);
		g->active_memory = prev;
		prev->next = NULL;
	} else {
#ifndef ZEPHIR_RELEASE
		assert(g->active_memory->permanent == 1);
#endif
		active_memory->pointer      = 0;
		active_memory->hash_pointer = 0;
		g->active_memory = prev;
	}

#ifndef ZEPHIR_RELEASE
	if (g->active_memory) {
		zephir_memory_entry *f = g->active_memory;
		if (f >= g->start_memory && f < g->end_memory - 1) {
			assert(f->permanent == 1);
			assert(f->next != NULL);

			if (f > g->start_memory) {
				assert(f->prev != NULL);
			}
		}
	}

	if (show_backtrace == 1) {
		zephir_print_backtrace();
	}
#endif

}

#ifndef ZEPHIR_RELEASE
/**
 * Finishes the current memory stack by releasing allocated memory
 */
int ZEPHIR_FASTCALL zephir_memory_restore_stack(const char *func)
{
	zend_zephir_globals_def *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	if (UNEXPECTED(zephir_globals_ptr->active_memory == NULL)) {
		fprintf(stderr, "WARNING: calling zephir_memory_restore_stack() without an active memory frame!\n");
		zephir_print_backtrace();
		return FAILURE;
	}

	if (UNEXPECTED(zephir_globals_ptr->active_memory->func != func)) {
		fprintf(stderr, "Trying to free someone else's memory frame!\n");
		fprintf(stderr, "The frame was created by %s\n", zephir_globals_ptr->active_memory->func);
		fprintf(stderr, "Calling function: %s\n", func);
		zephir_print_backtrace();
	}

	zephir_memory_restore_stack_common(zephir_globals_ptr);
	return SUCCESS;
}

/**
 * Adds a memory frame in the current executed method
 */
void ZEPHIR_FASTCALL zephir_memory_grow_stack(const char *func)
{
	zephir_memory_entry *entry;
	zend_zephir_globals_def *g = ZEPHIR_VGLOBAL;
	if (g->start_memory == NULL) {
		zephir_initialize_memory(g);
	}
	entry = zephir_memory_grow_stack_common(g);
	entry->func = func;
}

#else

/**
 * Adds a memory frame in the current executed method
 */
void ZEPHIR_FASTCALL zephir_memory_grow_stack()
{
	zend_zephir_globals_def *g = ZEPHIR_VGLOBAL;
	if (g->start_memory == NULL) {
		zephir_initialize_memory(g);
	}
	zephir_memory_grow_stack_common(g);
}

/**
 * Finishes the current memory stack by releasing allocated memory
 */
int ZEPHIR_FASTCALL zephir_memory_restore_stack()
{
	zephir_memory_restore_stack_common(ZEPHIR_VGLOBAL);
	return SUCCESS;
}

#endif

/**
 * Pre-allocates memory for further use in execution
 */
void zephir_initialize_memory(zend_zephir_globals_def *zephir_globals_ptr)
{
	zephir_memory_entry *start;
	size_t i;

	start = (zephir_memory_entry *) pecalloc(ZEPHIR_NUM_PREALLOCATED_FRAMES, sizeof(zephir_memory_entry), 1);
/* pecalloc() will take care of these members for every frame
	start->pointer      = 0;
	start->hash_pointer = 0;
	start->prev = NULL;
	start->next = NULL;
*/
	for (i = 0; i < ZEPHIR_NUM_PREALLOCATED_FRAMES; ++i) {
		start[i].addresses       = pecalloc(24, sizeof(zval*), 1);
		start[i].capacity        = 24;
		start[i].hash_addresses  = pecalloc(8, sizeof(zval*), 1);
		start[i].hash_capacity   = 8;

#ifndef ZEPHIR_RELEASE
		start[i].permanent = 1;
#endif
	}

	start[0].next = &start[1];
	start[ZEPHIR_NUM_PREALLOCATED_FRAMES - 1].prev = &start[ZEPHIR_NUM_PREALLOCATED_FRAMES - 2];

	for (i = 1; i < ZEPHIR_NUM_PREALLOCATED_FRAMES - 1; ++i) {
		start[i].next = &start[i + 1];
		start[i].prev = &start[i - 1];
	}

	zephir_globals_ptr->start_memory = start;
	zephir_globals_ptr->end_memory   = start + ZEPHIR_NUM_PREALLOCATED_FRAMES;

	zephir_globals_ptr->fcache = pemalloc(sizeof(HashTable), 1);
	zend_hash_init(zephir_globals_ptr->fcache, 128, NULL, NULL, 1); // zephir_fcall_cache_dtor

	zephir_globals_ptr->initialized = 1;
}

/**
 * Deinitializes all the memory allocated by Zephir
 */
void zephir_deinitialize_memory()
{
	size_t i;
	zend_zephir_globals_def *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	if (zephir_globals_ptr->initialized != 1) {
		zephir_globals_ptr->initialized = 0;
		return;
	}

	if (zephir_globals_ptr->start_memory != NULL) {
		zephir_clean_restore_stack();
	}

//	{
//		size_t i;
//		for (i=0; i<ZEPHIR_MAX_CACHE_SLOTS; ++i) {
//			zephir_fcall_cache_entry* e = zephir_globals_ptr->scache[i];
//			if (e) {
//				free(e);
//			}
//		}
//		zephir_fcall_cache_entry *cache_entry_temp = NULL;
//		ZEND_HASH_FOREACH_PTR(zephir_globals_ptr->fcache, cache_entry_temp) {
//			free(cache_entry_temp);
//		} ZEND_HASH_FOREACH_END();
//	}

#if 0
	zend_hash_apply_with_arguments(zephir_globals_ptr->fcache, zephir_cleanup_fcache, 0);
#endif

#ifndef ZEPHIR_RELEASE
	assert(zephir_globals_ptr->start_memory != NULL);
#endif

	for (i = 0; i < ZEPHIR_NUM_PREALLOCATED_FRAMES; ++i) {
		pefree(zephir_globals_ptr->start_memory[i].hash_addresses, 1);
		pefree(zephir_globals_ptr->start_memory[i].addresses, 1);
	}

	pefree(zephir_globals_ptr->start_memory, 1);
	zephir_globals_ptr->start_memory = NULL;

	zend_hash_destroy(zephir_globals_ptr->fcache);
	pefree(zephir_globals_ptr->fcache, 1);
	zephir_globals_ptr->fcache = NULL;

	zephir_globals_ptr->initialized = 0;
}

/**
 * Creates a virtual symbol tables dynamically
 */
void zephir_create_symbol_table()
{
	zephir_symbol_table *entry;
	zend_zephir_globals_def *gptr = ZEPHIR_VGLOBAL;
	zend_execute_data *ex = EG(current_execute_data);
	zend_array *symbol_table;

#ifndef ZEPHIR_RELEASE
	if (!gptr->active_memory) {
		fprintf(stderr, "ERROR: Trying to create a virtual symbol table without a memory frame");
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
	uint len = ZSTR_LEN(hash_key->key);

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

ZEPHIR_ATTR_NONNULL static void zephir_reallocate_memory(const zend_zephir_globals_def *g)
{
	zephir_memory_entry *frame = g->active_memory;
	int persistent = (frame >= g->start_memory && frame < g->end_memory);
	void *buf = perealloc(frame->addresses, sizeof(zval *) * (frame->capacity + 16), persistent);
	if (EXPECTED(buf != NULL)) {
		frame->capacity += 16;
		frame->addresses = buf;
	}
	else {
		zend_error(E_CORE_ERROR, "Memory allocation failed");
	}

#ifndef ZEPHIR_RELEASE
	assert(frame->permanent == persistent);
#endif
}

ZEPHIR_ATTR_NONNULL1(2) static inline void zephir_do_memory_observe(zval *var, const zend_zephir_globals_def *g)
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
		zephir_reallocate_memory(g);
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

/**
 * Observes a memory pointer to release its memory at the end of the request
 */
void ZEPHIR_FASTCALL zephir_memory_observe(zval *var)
{
	zend_zephir_globals_def *g = ZEPHIR_VGLOBAL;
	zephir_do_memory_observe(var, g);
}

/**
 * Observes a variable and allocates memory for it
 */
void ZEPHIR_FASTCALL zephir_memory_alloc(zval *var)
{
	zend_zephir_globals_def *g = ZEPHIR_VGLOBAL;
	zephir_do_memory_observe(var, g);
	ZVAL_NULL(var);
}

/**
 * Cleans the zephir memory stack recursively
 */
int ZEPHIR_FASTCALL zephir_clean_restore_stack() {

	zend_zephir_globals_def *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	while (zephir_globals_ptr->active_memory != NULL) {
		zephir_memory_restore_stack_common(zephir_globals_ptr);
	}

	return SUCCESS;
}

/* Debugging */
#ifndef ZEPHIR_RELEASE

/**
 * Dumps a memory frame for debug purposes
 */
void zephir_dump_memory_frame(zephir_memory_entry *active_memory)
{
	size_t i;

	assert(active_memory != NULL);

	fprintf(stderr, "Dump of the memory frame %p (%s)\n", active_memory, active_memory->func);

	if (active_memory->hash_pointer) {
		for (i = 0; i < active_memory->hash_pointer; ++i) {
			assert(active_memory->hash_addresses[i] != NULL);
			fprintf(stderr, "Hash ptr %lu (%p), type=%u, refcnted=%d, refcnt=%u\n", (ulong)i, active_memory->hash_addresses[i], Z_TYPE_P(active_memory->hash_addresses[i]),
				Z_REFCOUNTED_P(active_memory->hash_addresses[i]),
				Z_REFCOUNTED_P(active_memory->hash_addresses[i]) ? Z_REFCOUNT_P(active_memory->hash_addresses[i]) : 0
			);
		}
	}

	for (i = 0; i < active_memory->pointer; ++i) {
		if (EXPECTED(active_memory->addresses[i] != NULL)) {
			zval *var = active_memory->addresses[i];
			fprintf(stderr, "Obs var %lu (%p), type=%u, refcnted=%d, refcnt=%u; ", (ulong)i, var, Z_TYPE_P(var), Z_REFCOUNTED_P(var), Z_REFCOUNTED_P(var) ? Z_REFCOUNT_P(var) : 0);
			switch (Z_TYPE_P(var)) {
				case IS_NULL:     fprintf(stderr, "value=NULL\n"); break;
#ifdef ZEPHIR_ENABLE_64BITS
				case IS_LONG:     fprintf(stderr, "value=%lld\n", (long long int)Z_LVAL_P(var)); break;
#else
				case IS_LONG:     fprintf(stderr, "value=%ld\n", Z_LVAL_P(var)); break;
#endif
				case IS_DOUBLE:   fprintf(stderr, "value=%E\n", Z_DVAL_P(var)); break;
				case IS_TRUE:     fprintf(stderr, "value=(bool)true\n"); break;
				case IS_FALSE:    fprintf(stderr, "value=(bool)false\n"); break;
				case IS_ARRAY:    fprintf(stderr, "value=array(%p), %d elements\n", Z_ARRVAL_P(var), zend_hash_num_elements(Z_ARRVAL_P(var))); break;
				case IS_OBJECT:   fprintf(stderr, "value=object(%u), %s\n", Z_OBJ_HANDLE_P(var), ZSTR_VAL(Z_OBJCE_P(var)->name)); break;
				case IS_STRING:   fprintf(stderr, "value=%s (%zu)\n", Z_STRVAL_P(var), Z_STRLEN_P(var)); break;
#ifdef ZEPHIR_ENABLE_64BITS
				case IS_RESOURCE: fprintf(stderr, "value=(resource)%lld\n", (long long int)Z_LVAL_P(var)); break;
#else
				case IS_RESOURCE: fprintf(stderr, "value=(resource)%ld\n", Z_LVAL_P(var)); break;
#endif
				default:          fprintf(stderr, "\n"); break;
			}
		}
	}

	fprintf(stderr, "End of the dump of the memory frame %p\n", active_memory);
}

void zephir_dump_current_frame()
{
	zend_zephir_globals_def *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	if (UNEXPECTED(zephir_globals_ptr->active_memory == NULL)) {
		fprintf(stderr, "WARNING: calling %s() without an active memory frame!\n", __func__);
		zephir_print_backtrace();
		return;
	}

	zephir_dump_memory_frame(zephir_globals_ptr->active_memory);
}
#endif
