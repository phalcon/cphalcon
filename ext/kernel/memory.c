
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
	/* ecalloc() will take care of these members
		entry->pointer        = 0;
		entry->capacity       = 0;
		entry->addresses      = NULL;
		entry->alt_pointer    = 0;
		entry->alt_capacity   = 0;
		entry->alt_addresses  = NULL;
		entry->hash_pointer   = 0;
		entry->hash_capacity  = 0;
		entry->hash_addresses = NULL;
		entry->next = NULL;
	*/
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
	assert(g->active_memory->alt_pointer == 0);
	assert(g->active_memory->hash_pointer == 0);

	return g->active_memory;
}

/**
 * Restore a memory stack applying GC to all observed variables
 */
static void zephir_memory_restore_stack_common(zend_zephir_globals_def *g TSRMLS_DC)
{
	size_t i;
	zephir_memory_entry *prev, *active_memory;
	zephir_symbol_table *active_symbol_table;

	active_memory = g->active_memory;
	assert(active_memory != NULL);

	if (EXPECTED(!CG(unclean_shutdown))) {
		/* Clean active symbol table */
		if (g->active_symbol_table) {
			active_symbol_table = g->active_symbol_table;
			if (active_symbol_table->scope == active_memory) {
				zend_hash_destroy(EG(active_symbol_table));
				FREE_HASHTABLE(EG(active_symbol_table));
				EG(active_symbol_table) = active_symbol_table->symbol_table;
				g->active_symbol_table = active_symbol_table->prev;
				efree(active_symbol_table);
			}
		}

		/* Check for non freed hash key zvals, mark as null to avoid string freeing */
		for (i = 0; i < active_memory->hash_pointer; ++i) {
			assert(active_memory->hash_addresses[i] != NULL && *(active_memory->hash_addresses[i]) != NULL);
			if (Z_REFCOUNT_PP(active_memory->hash_addresses[i]) <= 1) {
				ZVAL_NULL(*active_memory->hash_addresses[i]);
			} else {
				zval_copy_ctor(*active_memory->hash_addresses[i]);
			}
		}

#ifndef ZEPHIR_RELEASE
		for (i = 0; i < active_memory->pointer; ++i) {
			if (active_memory->addresses[i] != NULL && *(active_memory->addresses[i]) != NULL) {
				zval **var = active_memory->addresses[i];

				if (Z_TYPE_PP(var) > IS_CALLABLE) {
					fprintf(stderr, "%s: observed variable #%d (%p) has invalid type %u [%s]\n", __func__, (int)i, *var, Z_TYPE_PP(var), active_memory->func);
				}
				if (Z_REFCOUNT_PP(var) == 0) {
					fprintf(stderr, "%s: observed variable #%d (%p) has 0 references, type=%d [%s]\n", __func__, (int)i, *var, Z_TYPE_PP(var), active_memory->func);
				}
				else if (Z_REFCOUNT_PP(var) >= 1000000) {
					fprintf(stderr, "%s: observed variable #%d (%p) has too many references (%u), type=%d  [%s]\n", __func__, (int)i, *var, Z_REFCOUNT_PP(var), Z_TYPE_PP(var), active_memory->func);
				}
#if 0
				/* Skip this check, PDO does return variables with is_ref = 1 and refcount = 1*/
				else if (Z_REFCOUNT_PP(var) == 1 && Z_ISREF_PP(var)) {
					fprintf(stderr, "%s: observed variable #%d (%p) is a reference with reference count = 1, type=%d  [%s]\n", __func__, (int)i, *var, Z_TYPE_PP(var), active_memory->func);
				}
#endif
			}
		}
#endif

		/* Traverse all zvals allocated, reduce the reference counting or free them */
		for (i = 0; i < active_memory->pointer; ++i) {
			zval **ptr = active_memory->addresses[i];
			if (EXPECTED(ptr != NULL && *(ptr) != NULL)) {
				if (Z_REFCOUNT_PP(ptr) == 1) {
					if (!Z_ISREF_PP(ptr) || Z_TYPE_PP(ptr) == IS_OBJECT) {
						zval_ptr_dtor(ptr);
					} else {
						efree(*ptr);
					}
				} else {
					Z_DELREF_PP(ptr);
				}
			}
		}

		for (i = 0; i < active_memory->alt_pointer; ++i) {
			zval *ptr = active_memory->alt_addresses[i];
			assert(ptr != NULL);
			assert(Z_REFCOUNT_P(ptr) == 1);
			zval_dtor(ptr);
			ZVAL_NULL(ptr);
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

		if (active_memory->alt_addresses != NULL) {
			efree(active_memory->alt_addresses);
		}

		efree(g->active_memory);
		g->active_memory = prev;
		prev->next = NULL;
	} else {
#ifndef ZEPHIR_RELEASE
		assert(g->active_memory->permanent == 1);
#endif
		active_memory->pointer      = 0;
		active_memory->alt_pointer  = 0;
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
#endif
}

#ifndef ZEPHIR_RELEASE

/**
 * Dumps a memory frame for debug purposes
 */
void zephir_dump_memory_frame(zephir_memory_entry *active_memory TSRMLS_DC)
{
	size_t i;

	assert(active_memory != NULL);

	fprintf(stderr, "Dump of the memory frame %p (%s)\n", active_memory, active_memory->func);

	if (active_memory->hash_pointer) {
		for (i = 0; i < active_memory->hash_pointer; ++i) {
			assert(active_memory->hash_addresses[i] != NULL && *(active_memory->hash_addresses[i]) != NULL);
			fprintf(stderr, "Hash ptr %lu (%p => %p), type=%u, refcnt=%u\n", (ulong)i, active_memory->hash_addresses[i], *active_memory->hash_addresses[i], Z_TYPE_PP(active_memory->hash_addresses[i]), Z_REFCOUNT_PP(active_memory->hash_addresses[i]));
		}
	}

	for (i = 0; i < active_memory->pointer; ++i) {
		if (EXPECTED(active_memory->addresses[i] != NULL && *(active_memory->addresses[i]) != NULL)) {
			zval **var = active_memory->addresses[i];
			fprintf(stderr, "Obs var %lu (%p => %p), type=%u, refcnt=%u; ", (ulong)i, var, *var, Z_TYPE_PP(var), Z_REFCOUNT_PP(var));
			switch (Z_TYPE_PP(var)) {
				case IS_NULL:     fprintf(stderr, "value=NULL\n"); break;
				case IS_LONG:     fprintf(stderr, "value=%ld\n", Z_LVAL_PP(var)); break;
				case IS_DOUBLE:   fprintf(stderr, "value=%E\n", Z_DVAL_PP(var)); break;
				case IS_BOOL:     fprintf(stderr, "value=(bool)%d\n", Z_BVAL_PP(var)); break;
				case IS_ARRAY:    fprintf(stderr, "value=array(%p), %d elements\n", Z_ARRVAL_PP(var), zend_hash_num_elements(Z_ARRVAL_PP(var))); break;
				case IS_OBJECT:   fprintf(stderr, "value=object(%u), %s\n", Z_OBJ_HANDLE_PP(var), Z_OBJCE_PP(var)->name); break;
				case IS_STRING:   fprintf(stderr, "value=%*s (%p)\n", Z_STRLEN_PP(var), Z_STRVAL_PP(var), Z_STRVAL_PP(var)); break;
				case IS_RESOURCE: fprintf(stderr, "value=(resource)%ld\n", Z_LVAL_PP(var)); break;
				default:          fprintf(stderr, "\n"); break;
			}
		}
	}

	fprintf(stderr, "End of the dump of the memory frame %p\n", active_memory);
}

void zephir_dump_current_frame(TSRMLS_D)
{
	zend_zephir_globals_def *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	if (UNEXPECTED(zephir_globals_ptr->active_memory == NULL)) {
		fprintf(stderr, "WARNING: calling %s() without an active memory frame!\n", __func__);
		zephir_print_backtrace();
		return;
	}

	zephir_dump_memory_frame(zephir_globals_ptr->active_memory TSRMLS_CC);
}

void zephir_dump_all_frames(TSRMLS_D)
{
	zend_zephir_globals_def *zephir_globals_ptr = ZEPHIR_VGLOBAL;
	zephir_memory_entry *active_memory       = zephir_globals_ptr->active_memory;

	fprintf(stderr, "*** DUMP START ***\n");
	while (active_memory != NULL) {
		zephir_dump_memory_frame(active_memory TSRMLS_CC);
		active_memory = active_memory->prev;
	}

	fprintf(stderr, "*** DUMP END ***\n");
}

/**
 * Finishes the current memory stack by releasing allocated memory
 */
int ZEND_FASTCALL zephir_memory_restore_stack(const char *func TSRMLS_DC)
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

	zephir_memory_restore_stack_common(zephir_globals_ptr TSRMLS_CC);
	return SUCCESS;
}

/**
 * Adds a memory frame in the current executed method
 */
void ZEND_FASTCALL zephir_memory_grow_stack(const char *func TSRMLS_DC)
{
	zephir_memory_entry *entry;
	zend_zephir_globals_def *g = ZEPHIR_VGLOBAL;
	if (g->start_memory == NULL) {
		zephir_initialize_memory(g TSRMLS_CC);
	}
	entry = zephir_memory_grow_stack_common(g);
	entry->func = func;
}

#else

/**
 * Adds a memory frame in the current executed method
 */
void ZEND_FASTCALL zephir_memory_grow_stack(TSRMLS_D)
{
	zend_zephir_globals_def *g = ZEPHIR_VGLOBAL;
	if (g->start_memory == NULL) {
		zephir_initialize_memory(g TSRMLS_CC);
	}
	zephir_memory_grow_stack_common(g);
}

/**
 * Finishes the current memory stack by releasing allocated memory
 */
int ZEND_FASTCALL zephir_memory_restore_stack(TSRMLS_D)
{
	zephir_memory_restore_stack_common(ZEPHIR_VGLOBAL TSRMLS_CC);
	return SUCCESS;
}

#endif

/**
 * Pre-allocates memory for further use in execution
 */
void zephir_initialize_memory(zend_zephir_globals_def *zephir_globals_ptr TSRMLS_DC)
{
	zephir_memory_entry *start;
	size_t i;

	start = (zephir_memory_entry *) pecalloc(ZEPHIR_NUM_PREALLOCATED_FRAMES, sizeof(zephir_memory_entry), 1);
/* pecalloc() will take care of these members for every frame
	start->pointer      = 0;
	start->alt_pointer  = 0;
	start->hash_pointer = 0;
	start->prev = NULL;
	start->next = NULL;
*/
	for (i = 0; i < ZEPHIR_NUM_PREALLOCATED_FRAMES; ++i) {
		start[i].addresses       = pecalloc(24, sizeof(zval*), 1);
		start[i].capacity        = 24;
		start[i].hash_addresses  = pecalloc(8, sizeof(zval*), 1);
		start[i].hash_capacity   = 8;
		start[i].alt_addresses   = pecalloc(8, sizeof(zval*), 1);
		start[i].alt_capacity    = 8;

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

	/* 'Allocator sizeof operand mismatch' warning can be safely ignored */
	ALLOC_INIT_ZVAL(zephir_globals_ptr->global_null);
	Z_SET_REFCOUNT_P(zephir_globals_ptr->global_null, 2);

	/* 'Allocator sizeof operand mismatch' warning can be safely ignored */
	ALLOC_INIT_ZVAL(zephir_globals_ptr->global_false);
	Z_SET_REFCOUNT_P(zephir_globals_ptr->global_false, 2);
	ZVAL_FALSE(zephir_globals_ptr->global_false);

	/* 'Allocator sizeof operand mismatch' warning can be safely ignored */
	ALLOC_INIT_ZVAL(zephir_globals_ptr->global_true);
	Z_SET_REFCOUNT_P(zephir_globals_ptr->global_true, 2);
	ZVAL_TRUE(zephir_globals_ptr->global_true);

	zephir_globals_ptr->initialized = 1;
}

/**
 * Cleans the function/method cache up
 */
int zephir_cleanup_fcache(void *pDest TSRMLS_DC, int num_args, va_list args, zend_hash_key *hash_key)
{
	zephir_fcall_cache_entry **entry = (zephir_fcall_cache_entry**) pDest;
	zend_class_entry *scope;
	uint len = hash_key->nKeyLength;

	assert(hash_key->arKey != NULL);
	assert(hash_key->nKeyLength > 2 * sizeof(zend_class_entry**));

	memcpy(&scope, &hash_key->arKey[(len -1) - 2 * sizeof(zend_class_entry**)], sizeof(zend_class_entry*));

/*
#ifndef ZEPHIR_RELEASE
	{
		zend_class_entry *cls;
		memcpy(&cls, &hash_key->arKey[len - sizeof(zend_class_entry**)], sizeof(zend_class_entry*));

		fprintf(stderr, "func: %s, cls: %s, scope: %s [%u]\n", (*entry)->f->common.function_name, (cls ? cls->name : "N/A"), (scope ? scope->name : "N/A"), (uint)(*entry)->times);
	}
#endif
*/

#ifndef ZEPHIR_RELEASE
	if ((*entry)->f->type != ZEND_INTERNAL_FUNCTION || (scope && scope->type != ZEND_INTERNAL_CLASS)) {
		return ZEND_HASH_APPLY_REMOVE;
	}
#else
	if ((*entry)->type != ZEND_INTERNAL_FUNCTION || (scope && scope->type != ZEND_INTERNAL_CLASS)) {
		return ZEND_HASH_APPLY_REMOVE;
	}
#endif

	if (scope && scope->type == ZEND_INTERNAL_CLASS && scope->info.internal.module->type != MODULE_PERSISTENT) {
		return ZEND_HASH_APPLY_REMOVE;
	}

	return ZEND_HASH_APPLY_KEEP;
}

/**
 * Deinitializes all the memory allocated by Zephir
 */
void zephir_deinitialize_memory(TSRMLS_D)
{
	size_t i;
	zend_zephir_globals_def *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	if (zephir_globals_ptr->initialized != 1) {
		zephir_globals_ptr->initialized = 0;
		return;
	}

	if (zephir_globals_ptr->start_memory != NULL) {
		zephir_clean_restore_stack(TSRMLS_C);
	}

	zend_hash_apply_with_arguments(zephir_globals_ptr->fcache TSRMLS_CC, zephir_cleanup_fcache, 0);

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

	for (i = 0; i < 2; i++) {
		zval_ptr_dtor(&zephir_globals_ptr->global_null);
		zval_ptr_dtor(&zephir_globals_ptr->global_false);
		zval_ptr_dtor(&zephir_globals_ptr->global_true);
	}

	zephir_globals_ptr->initialized = 0;
}

ZEPHIR_ATTR_NONNULL static void zephir_reallocate_memory(const zend_zephir_globals_def *g)
{
	zephir_memory_entry *frame = g->active_memory;
	int persistent = (frame >= g->start_memory && frame < g->end_memory);
	void *buf = perealloc(frame->addresses, sizeof(zval **) * (frame->capacity + 16), persistent);
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

ZEPHIR_ATTR_NONNULL static void zephir_reallocate_memory_alt(const zend_zephir_globals_def *g)
{
	zephir_memory_entry *frame = g->active_memory;
	int persistent = (frame >= g->start_memory && frame < g->end_memory);
	void *buf = perealloc(frame->alt_addresses, sizeof(zval **) * (frame->alt_capacity + 4), persistent);
	if (EXPECTED(buf != NULL)) {
		frame->alt_capacity += 4;
		frame->alt_addresses = buf;
	}
	else {
		zend_error(E_CORE_ERROR, "Memory allocation failed");
	}

#ifndef ZEPHIR_RELEASE
	assert(frame->permanent == persistent);
#endif
}

ZEPHIR_ATTR_NONNULL static void zephir_reallocate_hmemory(const zend_zephir_globals_def *g)
{
	zephir_memory_entry *frame = g->active_memory;
	int persistent = (frame >= g->start_memory && frame < g->end_memory);
	void *buf = perealloc(frame->hash_addresses, sizeof(zval **) * (frame->hash_capacity + 4), persistent);
	if (EXPECTED(buf != NULL)) {
		frame->hash_capacity += 4;
		frame->hash_addresses = buf;
	}
	else {
		zend_error(E_CORE_ERROR, "Memory allocation failed");
	}

#ifndef ZEPHIR_RELEASE
	assert(frame->permanent == persistent);
#endif
}

ZEPHIR_ATTR_NONNULL1(2) static inline void zephir_do_memory_observe(zval **var, const zend_zephir_globals_def *g)
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

ZEPHIR_ATTR_NONNULL1(2) static inline void zephir_do_memory_observe_alt(zval *var, const zend_zephir_globals_def *g)
{
	zephir_memory_entry *frame = g->active_memory;
#ifndef ZEPHIR_RELEASE
	if (UNEXPECTED(frame == NULL)) {
		fprintf(stderr, "ZEPHIR_MM_GROW() must be called before using any of MM functions or macros!");
		zephir_print_backtrace();
		abort();
	}
#endif

	if (UNEXPECTED(frame->alt_pointer == frame->alt_capacity)) {
		zephir_reallocate_memory_alt(g);
	}

	frame->alt_addresses[frame->alt_pointer] = var;
	++frame->alt_pointer;
}

/**
 * Observes a memory pointer to release its memory at the end of the request
 */
void ZEND_FASTCALL zephir_memory_observe(zval **var TSRMLS_DC)
{
	zend_zephir_globals_def *g = ZEPHIR_VGLOBAL;
	zephir_do_memory_observe(var, g);
	*var = NULL; /* In case an exception or error happens BEFORE the observed variable gets initialized */
}

/**
 * Observes a memory pointer to release its memory at the end of the request
 *
 * zval observed with this function will be destroyed with zval_dtor() but not freed
 */
void ZEND_FASTCALL zephir_memory_observe_alt(zval *var TSRMLS_DC)
{
	zend_zephir_globals_def *g = ZEPHIR_VGLOBAL;
	zephir_do_memory_observe_alt(var, g);
}


/**
 * Observes a variable and allocates memory for it
 */
void ZEND_FASTCALL zephir_memory_alloc(zval **var TSRMLS_DC)
{
	zend_zephir_globals_def *g = ZEPHIR_VGLOBAL;
	zephir_do_memory_observe(var, g);
	ALLOC_INIT_ZVAL(*var);
}

/**
 * Releases memory for an allocated zval
 */
void ZEND_FASTCALL zephir_ptr_dtor(zval **var)
{
	if (!Z_ISREF_PP(var) || Z_TYPE_PP(var) == IS_OBJECT) {
		zval_ptr_dtor(var);
	} else {
		if (Z_REFCOUNT_PP(var) == 0) {
			efree(*var);
		} else {
			Z_DELREF_PP(var);
			if (Z_REFCOUNT_PP(var) == 0) {
				efree(*var);
			}
		}
	}
}

/**
 * Observes a variable and allocates memory for it
 * Marks hash key zvals to be nulled before freeing
 */
void ZEND_FASTCALL zephir_memory_alloc_pnull(zval **var TSRMLS_DC)
{
	zend_zephir_globals_def *g = ZEPHIR_VGLOBAL;
	zephir_memory_entry *active_memory = g->active_memory;

#ifndef ZEPHIR_RELEASE
	if (UNEXPECTED(active_memory == NULL)) {
		fprintf(stderr, "ZEPHIR_MM_GROW() must be called before using any of MM functions or macros!");
		zephir_print_backtrace();
		abort();
	}
#endif

	zephir_do_memory_observe(var, g);
	ALLOC_INIT_ZVAL(*var);

	if (active_memory->hash_pointer == active_memory->hash_capacity) {
		zephir_reallocate_hmemory(g);
	}

	active_memory->hash_addresses[active_memory->hash_pointer] = var;
	++active_memory->hash_pointer;
}

/**
 * Removes a memory pointer from the active memory pool
 */
void ZEND_FASTCALL zephir_memory_remove(zval **var TSRMLS_DC) {
	zval_ptr_dtor(var);
	*var = NULL;
}

/**
 * Cleans the zephir memory stack recursively
 */
int ZEND_FASTCALL zephir_clean_restore_stack(TSRMLS_D) {

	zend_zephir_globals_def *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	while (zephir_globals_ptr->active_memory != NULL) {
		zephir_memory_restore_stack_common(zephir_globals_ptr TSRMLS_CC);
	}

	return SUCCESS;
}

/**
 * Copies a variable only if its refcount is greater than 1
 */
void ZEND_FASTCALL zephir_copy_ctor(zval *destination, zval *origin) {
	if (Z_REFCOUNT_P(origin) > 1) {
		zval_copy_ctor(destination);
	} else {
		ZVAL_NULL(origin);
	}
}

/**
 * Creates virtual symbol tables dynamically
 */
void zephir_create_symbol_table(TSRMLS_D) {

	zephir_symbol_table *entry;
	zend_zephir_globals_def *zephir_globals_ptr = ZEPHIR_VGLOBAL;
	HashTable *symbol_table;

#ifndef ZEPHIR_RELEASE
	if (!zephir_globals_ptr->active_memory) {
		fprintf(stderr, "ERROR: Trying to create a virtual symbol table without a memory frame");
		zephir_print_backtrace();
		return;
	}
#endif

	entry = (zephir_symbol_table *) emalloc(sizeof(zephir_symbol_table));
	entry->scope = zephir_globals_ptr->active_memory;
	entry->symbol_table = EG(active_symbol_table);
	entry->prev = zephir_globals_ptr->active_symbol_table;
	zephir_globals_ptr->active_symbol_table = entry;

	ALLOC_HASHTABLE(symbol_table);
	zend_hash_init(symbol_table, 0, NULL, ZVAL_PTR_DTOR, 0);
	EG(active_symbol_table) = symbol_table;
}

/**
 * Restores all the virtual symbol tables
 */
void zephir_clean_symbol_tables(TSRMLS_D) {

	/*unsigned int i;

	if (ZEPHIR_GLOBAL(symbol_tables)) {
		for (i = ZEPHIR_GLOBAL(number_symbol_tables); i > 0; i--) {
			EG(active_symbol_table) = ZEPHIR_GLOBAL(symbol_tables)[i - 1];
		}
		efree(ZEPHIR_GLOBAL(symbol_tables));
		ZEPHIR_GLOBAL(symbol_tables) = NULL;
	}*/
}

/**
 * Exports symbols to the active symbol table
 */
int zephir_set_symbol(zval *key_name, zval *value TSRMLS_DC) {

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
int zephir_set_symbol_str(char *key_name, unsigned int key_length, zval *value TSRMLS_DC) {

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
