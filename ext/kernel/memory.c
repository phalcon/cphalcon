
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
<<<<<<< HEAD
  | Copyright (c) 2011-2015 Zephir Team (http://www.zephir-lang.com)       |
=======
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
>>>>>>> master
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

<<<<<<< HEAD
#include "php.h"
#include "php_ext.h"
=======
>>>>>>> master
#include "kernel/memory.h"

#include <Zend/zend_alloc.h>

#include "kernel/fcall.h"
#include "kernel/backtrace.h"
#include "kernel/framework/orm.h"

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
 * memory frame is globally accesed using ZEPHIR_GLOBAL(start_frame)
 *
<<<<<<< HEAD
 * Not all methods must grow/restore the zephir_memory_entry.
 */

static zephir_memory_entry* zephir_memory_grow_stack_common(zend_zephir_globals_def *g)
=======
 * Not all methods must grow/restore the phalcon_memory_entry.
 */

void phalcon_initialize_memory(zend_phalcon_globals *phalcon_globals_ptr TSRMLS_DC)
{
	phalcon_memory_entry *start;
	size_t i;

	start = (phalcon_memory_entry *) pecalloc(PHALCON_NUM_PREALLOCATED_FRAMES, sizeof(phalcon_memory_entry), 1);
/* pecalloc() will take care of these members for every frame
	start->pointer      = 0;
	start->hash_pointer = 0;
	start->prev = NULL;
	start->next = NULL;
*/
	for (i = 0; i < PHALCON_NUM_PREALLOCATED_FRAMES; ++i) {
		start[i].addresses       = pecalloc(24, sizeof(zval*), 1);
		start[i].capacity        = 24;
		start[i].hash_addresses  = pecalloc(8, sizeof(zval*), 1);
		start[i].hash_capacity   = 8;

#ifndef PHALCON_RELEASE
		start[i].permanent = 1;
#endif
	}

	start[0].next = &start[1];
	start[PHALCON_NUM_PREALLOCATED_FRAMES - 1].prev = &start[PHALCON_NUM_PREALLOCATED_FRAMES - 2];

	for (i = 1; i < PHALCON_NUM_PREALLOCATED_FRAMES - 1; ++i) {
		start[i].next = &start[i + 1];
		start[i].prev = &start[i - 1];
	}

	phalcon_globals_ptr->start_memory = start;
	phalcon_globals_ptr->end_memory   = start + PHALCON_NUM_PREALLOCATED_FRAMES;

	phalcon_globals_ptr->fcache = emalloc(sizeof(HashTable));
#ifndef PHALCON_RELEASE
	zend_hash_init(phalcon_globals_ptr->fcache, 128, NULL, phalcon_fcall_cache_dtor, 0);
#else
	zend_hash_init(phalcon_globals_ptr->fcache, 128, NULL, NULL, 0);
#endif

	/* 'Allocator sizeof operand mismatch' warning can be safely ignored */
	ALLOC_INIT_ZVAL(phalcon_globals_ptr->z_null);
	Z_SET_REFCOUNT_P(phalcon_globals_ptr->z_null, 2);

	/* 'Allocator sizeof operand mismatch' warning can be safely ignored */
	ALLOC_INIT_ZVAL(phalcon_globals_ptr->z_false);
	Z_SET_REFCOUNT_P(phalcon_globals_ptr->z_false, 2);
	ZVAL_FALSE(phalcon_globals_ptr->z_false);

	/* 'Allocator sizeof operand mismatch' warning can be safely ignored */
	ALLOC_INIT_ZVAL(phalcon_globals_ptr->z_true);
	Z_SET_REFCOUNT_P(phalcon_globals_ptr->z_true, 2);
	ZVAL_TRUE(phalcon_globals_ptr->z_true);

	/* 'Allocator sizeof operand mismatch' warning can be safely ignored */
	ALLOC_INIT_ZVAL(phalcon_globals_ptr->z_zero);
	Z_SET_REFCOUNT_P(phalcon_globals_ptr->z_zero, 2);
	ZVAL_LONG(phalcon_globals_ptr->z_zero, 0);

	/* 'Allocator sizeof operand mismatch' warning can be safely ignored */
	ALLOC_INIT_ZVAL(phalcon_globals_ptr->z_one);
	Z_SET_REFCOUNT_P(phalcon_globals_ptr->z_one, 2);
	ZVAL_LONG(phalcon_globals_ptr->z_one, 1);

	phalcon_globals_ptr->initialized = 1;
}

void phalcon_deinitialize_memory(TSRMLS_D)
{
	size_t i;
	zend_phalcon_globals *phalcon_globals_ptr = PHALCON_VGLOBAL;

	if (phalcon_globals_ptr->initialized != 1) {
		phalcon_globals_ptr->initialized = 0;
		return;
	}

	if (phalcon_globals_ptr->start_memory != NULL) {
		phalcon_clean_restore_stack(TSRMLS_C);
	}

	phalcon_orm_destroy_cache(TSRMLS_C);

	zend_hash_apply_with_arguments(phalcon_globals_ptr->fcache TSRMLS_CC, phalcon_cleanup_fcache, 0);

#ifndef PHALCON_RELEASE
	assert(phalcon_globals_ptr->start_memory != NULL);
#endif

	for (i = 0; i < PHALCON_NUM_PREALLOCATED_FRAMES; ++i) {
		pefree(phalcon_globals_ptr->start_memory[i].hash_addresses, 1);
		pefree(phalcon_globals_ptr->start_memory[i].addresses, 1);
	}

	pefree(phalcon_globals_ptr->start_memory, 1);
	phalcon_globals_ptr->start_memory = NULL;

	zend_hash_destroy(phalcon_globals_ptr->fcache);
	efree(phalcon_globals_ptr->fcache);
	phalcon_globals_ptr->fcache = NULL;

	for (i = 0; i < 2; i++) {
		zval_ptr_dtor(&phalcon_globals_ptr->z_null);
		zval_ptr_dtor(&phalcon_globals_ptr->z_false);
		zval_ptr_dtor(&phalcon_globals_ptr->z_true);
		zval_ptr_dtor(&phalcon_globals_ptr->z_zero);
		zval_ptr_dtor(&phalcon_globals_ptr->z_one);
	}

	phalcon_globals_ptr->initialized = 0;
}

static phalcon_memory_entry* phalcon_memory_grow_stack_common(zend_phalcon_globals *g)
>>>>>>> master
{
	assert(g->start_memory != NULL);
	if (!g->active_memory) {
		g->active_memory = g->start_memory;
<<<<<<< HEAD
#ifndef ZEPHIR_RELEASE
=======
#ifndef PHALCON_RELEASE
>>>>>>> master
		assert(g->active_memory->permanent == 1);
#endif
	}
	else if (!g->active_memory->next) {
<<<<<<< HEAD
#ifndef PHP_WIN32
		assert(g->active_memory >= g->end_memory - 1 || g->active_memory < g->start_memory);
#endif
		zephir_memory_entry *entry = (zephir_memory_entry *) ecalloc(1, sizeof(zephir_memory_entry));
=======
		phalcon_memory_entry *entry;

		assert(g->active_memory >= g->end_memory - 1 || g->active_memory < g->start_memory);
		entry = (phalcon_memory_entry *) ecalloc(1, sizeof(phalcon_memory_entry));
>>>>>>> master
	/* ecalloc() will take care of these members
		entry->pointer   = 0;
		entry->capacity  = 0;
		entry->addresses = NULL;
		entry->hash_pointer   = 0;
		entry->hash_capacity  = 0;
		entry->hash_addresses = NULL;
		entry->next = NULL;
	*/
<<<<<<< HEAD
#ifndef ZEPHIR_RELEASE
=======
#ifndef PHALCON_RELEASE
>>>>>>> master
		entry->permanent  = 0;
		entry->func       = NULL;
#endif
		entry->prev       = g->active_memory;
		entry->prev->next = entry;
		g->active_memory  = entry;
<<<<<<< HEAD
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
static void zephir_memory_restore_stack_common(zend_zephir_globals_def *g TSRMLS_DC)
=======
	}
	else {
#ifndef PHALCON_RELEASE
		assert(g->active_memory->permanent == 1);
#endif
		assert(g->active_memory < g->end_memory && g->active_memory >= g->start_memory);
		g->active_memory = g->active_memory->next;
	}

	assert(g->active_memory->pointer == 0);
	assert(g->active_memory->hash_pointer == 0);

	return g->active_memory;
}

static void phalcon_memory_restore_stack_common(zend_phalcon_globals *g TSRMLS_DC)
>>>>>>> master
{
	size_t i;
	zephir_memory_entry *prev, *active_memory;
	zephir_symbol_table *active_symbol_table;
	zval **ptr;

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

<<<<<<< HEAD
#ifndef ZEPHIR_RELEASE
=======
#ifndef PHALCON_RELEASE
>>>>>>> master
		for (i = 0; i < active_memory->pointer; ++i) {
			if (active_memory->addresses[i] != NULL && *(active_memory->addresses[i]) != NULL) {
				zval **var = active_memory->addresses[i];
#if PHP_VERSION_ID < 50400
				if (Z_TYPE_PP(var) > IS_CONSTANT_ARRAY) {
					fprintf(stderr, "%s: observed variable #%d (%p) has invalid type %u [%s]\n", __func__, (int)i, *var, Z_TYPE_PP(var), active_memory->func);
				}
#else
				if (Z_TYPE_PP(var) > IS_CALLABLE) {
					fprintf(stderr, "%s: observed variable #%d (%p) has invalid type %u [%s]\n", __func__, (int)i, *var, Z_TYPE_PP(var), active_memory->func);
				}
#endif

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
<<<<<<< HEAD
			ptr = active_memory->addresses[i];
			if (EXPECTED(ptr != NULL && *(ptr) != NULL)) {
				if (Z_REFCOUNT_PP(ptr) == 1) {
					if (!Z_ISREF_PP(ptr) || Z_TYPE_PP(ptr) == IS_OBJECT) {
						zval_ptr_dtor(ptr);
					} else {
						efree(*ptr);
					}
				} else {
					Z_DELREF_PP(ptr);
=======
			if (EXPECTED(active_memory->addresses[i] != NULL && *(active_memory->addresses[i]) != NULL)) {
				if (Z_REFCOUNT_PP(active_memory->addresses[i]) == 1) {
					zval_ptr_dtor(active_memory->addresses[i]);
				} else {
					Z_DELREF_PP(active_memory->addresses[i]);
>>>>>>> master
				}
			}
		}
	}

<<<<<<< HEAD
#ifndef ZEPHIR_RELEASE
=======
#ifndef PHALCON_RELEASE
>>>>>>> master
	active_memory->func = NULL;
#endif

	prev = active_memory->prev;

	if (active_memory >= g->end_memory || active_memory < g->start_memory) {
<<<<<<< HEAD
#ifndef ZEPHIR_RELEASE
=======
#ifndef PHALCON_RELEASE
>>>>>>> master
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
<<<<<<< HEAD
	} else {
#ifndef ZEPHIR_RELEASE
		assert(g->active_memory->permanent == 1);
#endif
=======
	}
	else {
#ifndef PHALCON_RELEASE
		assert(g->active_memory->permanent == 1);
#endif

>>>>>>> master
		active_memory->pointer      = 0;
		active_memory->hash_pointer = 0;
		g->active_memory = prev;
	}

<<<<<<< HEAD
#ifndef ZEPHIR_RELEASE
	if (g->active_memory) {
		zephir_memory_entry *f = g->active_memory;
=======
#ifndef PHALCON_RELEASE
	if (g->active_memory) {
		phalcon_memory_entry *f = g->active_memory;
>>>>>>> master
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

<<<<<<< HEAD
#ifndef ZEPHIR_RELEASE

/**
 * Dumps a memory frame for debug purposes
 */
void zephir_dump_memory_frame(zephir_memory_entry *active_memory TSRMLS_DC)
=======
#ifndef PHALCON_RELEASE

void phalcon_dump_memory_frame(phalcon_memory_entry *active_memory TSRMLS_DC)
>>>>>>> master
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
<<<<<<< HEAD
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

=======
	}

	fprintf(stderr, "End of the dump of the memory frame %p\n", active_memory);
}

void phalcon_dump_current_frame(TSRMLS_D)
{
	zend_phalcon_globals *phalcon_globals_ptr = PHALCON_VGLOBAL;

	if (UNEXPECTED(phalcon_globals_ptr->active_memory == NULL)) {
		fprintf(stderr, "WARNING: calling %s() without an active memory frame!\n", __func__);
		phalcon_print_backtrace();
		return;
	}

	phalcon_dump_memory_frame(phalcon_globals_ptr->active_memory TSRMLS_CC);
}

void phalcon_dump_all_frames(TSRMLS_D)
{
	zend_phalcon_globals *phalcon_globals_ptr = PHALCON_VGLOBAL;
	phalcon_memory_entry *active_memory       = phalcon_globals_ptr->active_memory;

	fprintf(stderr, "*** DUMP START ***\n");
	while (active_memory != NULL) {
		phalcon_dump_memory_frame(active_memory TSRMLS_CC);
		active_memory = active_memory->prev;
	}

>>>>>>> master
	fprintf(stderr, "*** DUMP END ***\n");
}

/**
 * Finishes the current memory stack by releasing allocated memory
 */
<<<<<<< HEAD
int ZEND_FASTCALL zephir_memory_restore_stack(const char *func TSRMLS_DC)
=======
int phalcon_memory_restore_stack(const char *func TSRMLS_DC)
>>>>>>> master
{
	zend_zephir_globals_def *zephir_globals_ptr = ZEPHIR_VGLOBAL;

<<<<<<< HEAD
	if (UNEXPECTED(zephir_globals_ptr->active_memory == NULL)) {
		fprintf(stderr, "WARNING: calling zephir_memory_restore_stack() without an active memory frame!\n");
		zephir_print_backtrace();
		return FAILURE;
	}

	if (UNEXPECTED(zephir_globals_ptr->active_memory->func != func)) {
=======
	if (UNEXPECTED(phalcon_globals_ptr->active_memory == NULL)) {
		fprintf(stderr, "WARNING: calling phalcon_memory_restore_stack() without an active memory frame!\n");
		phalcon_print_backtrace();
		return FAILURE;
	}

	if (UNEXPECTED(phalcon_globals_ptr->active_memory->func != func)) {
>>>>>>> master
		fprintf(stderr, "Trying to free someone else's memory frame!\n");
		fprintf(stderr, "The frame was created by %s\n", zephir_globals_ptr->active_memory->func);
		fprintf(stderr, "Calling function: %s\n", func);
		zephir_print_backtrace();
	}

<<<<<<< HEAD
	zephir_memory_restore_stack_common(zephir_globals_ptr TSRMLS_CC);
=======
	phalcon_memory_restore_stack_common(phalcon_globals_ptr TSRMLS_CC);
>>>>>>> master
	return SUCCESS;
}

/**
 * Adds a memory frame in the current executed method
 */
<<<<<<< HEAD
void ZEND_FASTCALL zephir_memory_grow_stack(const char *func TSRMLS_DC)
{
	zephir_memory_entry *entry;
	zend_zephir_globals_def *g = ZEPHIR_VGLOBAL;
	if (g->start_memory == NULL) {
		zephir_initialize_memory(g TSRMLS_CC);
	}
	entry = zephir_memory_grow_stack_common(g);
=======
void phalcon_memory_grow_stack(const char *func TSRMLS_DC)
{
	zend_phalcon_globals *g = PHALCON_VGLOBAL;
	if (g->start_memory == NULL) {
		phalcon_initialize_memory(g TSRMLS_CC);
	}
	phalcon_memory_entry *entry = phalcon_memory_grow_stack_common(g);
>>>>>>> master
	entry->func = func;
}

#else

/**
 * Adds a memory frame in the current executed method
 */
<<<<<<< HEAD
void ZEND_FASTCALL zephir_memory_grow_stack(TSRMLS_D)
{
	zend_zephir_globals_def *g = ZEPHIR_VGLOBAL;
	if (g->start_memory == NULL) {
		zephir_initialize_memory(g TSRMLS_CC);
	}
	zephir_memory_grow_stack_common(g);
=======
void phalcon_memory_grow_stack(TSRMLS_D)
{
	zend_phalcon_globals *g = PHALCON_VGLOBAL;
	if (g->start_memory == NULL) {
		zend_error(E_ERROR, "Cannot use the memory manager when the request is shutting down");
		return;
	}
	phalcon_memory_grow_stack_common(g);
>>>>>>> master
}

/**
 * Finishes the current memory stack by releasing allocated memory
 */
<<<<<<< HEAD
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

#if PHP_VERSION_ID >= 50400
	if (scope && scope->type == ZEND_INTERNAL_CLASS && scope->info.internal.module->type != MODULE_PERSISTENT) {
		return ZEND_HASH_APPLY_REMOVE;
	}
#else
	if (scope && scope->type == ZEND_INTERNAL_CLASS && scope->module->type != MODULE_PERSISTENT) {
		return ZEND_HASH_APPLY_REMOVE;
	}
#endif

	return ZEND_HASH_APPLY_KEEP;
=======
int phalcon_memory_restore_stack(TSRMLS_D)
{
	phalcon_memory_restore_stack_common(PHALCON_VGLOBAL TSRMLS_CC);
	return SUCCESS;
>>>>>>> master
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

<<<<<<< HEAD
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
=======
PHALCON_ATTR_NONNULL static void phalcon_reallocate_memory(const zend_phalcon_globals *g)
{
	phalcon_memory_entry *frame = g->active_memory;
>>>>>>> master
	int persistent = (frame >= g->start_memory && frame < g->end_memory);
	void *buf = perealloc(frame->addresses, sizeof(zval **) * (frame->capacity + 16), persistent);
	if (EXPECTED(buf != NULL)) {
		frame->capacity += 16;
		frame->addresses = buf;
	}
	else {
		zend_error(E_CORE_ERROR, "Memory allocation failed");
	}

<<<<<<< HEAD
#ifndef ZEPHIR_RELEASE
=======
#ifndef PHALCON_RELEASE
>>>>>>> master
	assert(frame->permanent == persistent);
#endif
}

<<<<<<< HEAD
ZEPHIR_ATTR_NONNULL static void zephir_reallocate_hmemory(const zend_zephir_globals_def *g)
{
	zephir_memory_entry *frame = g->active_memory;
=======
PHALCON_ATTR_NONNULL static void phalcon_reallocate_hmemory(const zend_phalcon_globals *g)
{
	phalcon_memory_entry *frame = g->active_memory;
>>>>>>> master
	int persistent = (frame >= g->start_memory && frame < g->end_memory);
	void *buf = perealloc(frame->hash_addresses, sizeof(zval **) * (frame->hash_capacity + 4), persistent);
	if (EXPECTED(buf != NULL)) {
		frame->hash_capacity += 4;
		frame->hash_addresses = buf;
	}
	else {
		zend_error(E_CORE_ERROR, "Memory allocation failed");
	}

<<<<<<< HEAD
#ifndef ZEPHIR_RELEASE
=======
#ifndef PHALCON_RELEASE
>>>>>>> master
	assert(frame->permanent == persistent);
#endif
}

<<<<<<< HEAD
ZEPHIR_ATTR_NONNULL1(2) static inline void zephir_do_memory_observe(zval **var, const zend_zephir_globals_def *g)
{
	zephir_memory_entry *frame = g->active_memory;
#ifndef ZEPHIR_RELEASE
	if (UNEXPECTED(frame == NULL)) {
		fprintf(stderr, "ZEPHIR_MM_GROW() must be called before using any of MM functions or macros!");
		zephir_print_backtrace();
=======
PHALCON_ATTR_NONNULL1(2) static inline void phalcon_do_memory_observe(zval **var, const zend_phalcon_globals *g)
{
	phalcon_memory_entry *frame = g->active_memory;

	if (UNEXPECTED(frame->pointer == frame->capacity)) {
		phalcon_reallocate_memory(g);
	}

	frame->addresses[frame->pointer] = var;
	++frame->pointer;
}

#ifndef PHALCON_RELEASE

static void phalcon_verify_frame(const phalcon_memory_entry *frame, const char *func, zval **var)
{
	size_t i;

	if (UNEXPECTED(frame == NULL)) {
		fprintf(stderr, "PHALCON_MM_GROW() must be called before using any of MM functions or macros!");
		phalcon_print_backtrace();
>>>>>>> master
		abort();
	}

<<<<<<< HEAD
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
=======
	if (strcmp(frame->func, func)) {
		fprintf(stderr, "Memory frames do not match: function: %s, frame creator: %s\n", func, frame->func);
		phalcon_print_backtrace();
		abort();
	}

	for (i=0; i<frame->pointer; ++i) {
		if (frame->addresses[i] == var) {
			fprintf(stderr, "Variable %p is already observed", var);
			phalcon_print_backtrace();
			abort();
		}
	}
>>>>>>> master
}

/**
 * Observes a memory pointer to release its memory at the end of the request
 */
<<<<<<< HEAD
void ZEND_FASTCALL zephir_memory_observe(zval **var TSRMLS_DC)
{
	zend_zephir_globals_def *g = ZEPHIR_VGLOBAL;
	zephir_do_memory_observe(var, g);
=======
void phalcon_memory_observe(zval **var, const char *func TSRMLS_DC)
{
	zend_phalcon_globals *g     = PHALCON_VGLOBAL;
	phalcon_memory_entry *frame = g->active_memory;

	phalcon_verify_frame(frame, func, var);

	phalcon_do_memory_observe(var, g);
>>>>>>> master
	*var = NULL; /* In case an exception or error happens BEFORE the observed variable gets initialized */
}

/**
 * Observes a variable and allocates memory for it
 */
<<<<<<< HEAD
void ZEND_FASTCALL zephir_memory_alloc(zval **var TSRMLS_DC)
{
	zend_zephir_globals_def *g = ZEPHIR_VGLOBAL;
	zephir_do_memory_observe(var, g);
=======
void phalcon_memory_alloc(zval **var, const char *func TSRMLS_DC)
{
	zend_phalcon_globals *g     = PHALCON_VGLOBAL;
	phalcon_memory_entry *frame = g->active_memory;

	phalcon_verify_frame(frame, func, var);

	phalcon_do_memory_observe(var, g);
>>>>>>> master
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
 * Releases memory for an allocated zval
 */
void ZEND_FASTCALL zephir_dtor(zval *var)
{
	if (!Z_ISREF_P(var)) {
		zval_dtor(var);
	}
}

/**
 * Observes a variable and allocates memory for it
 * Marks hash key zvals to be nulled before freeing
 */
<<<<<<< HEAD
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
=======
void phalcon_memory_alloc_pnull(zval **var, const char *func TSRMLS_DC)
{
	zend_phalcon_globals *g     = PHALCON_VGLOBAL;
	phalcon_memory_entry *frame = g->active_memory;

	phalcon_verify_frame(frame, func, var);

	phalcon_do_memory_observe(var, g);
	ALLOC_INIT_ZVAL(*var);

	if (frame->hash_pointer == frame->hash_capacity) {
		phalcon_reallocate_hmemory(g);
	}

	frame->hash_addresses[frame->hash_pointer] = var;
	++frame->hash_pointer;
}

#else

/**
 * Observes a memory pointer to release its memory at the end of the request
 */
void phalcon_memory_observe(zval **var TSRMLS_DC)
{
	zend_phalcon_globals *g = PHALCON_VGLOBAL;
	phalcon_do_memory_observe(var, g);
	*var = NULL; /* In case an exception or error happens BEFORE the observed variable gets initialized */
}

/**
 * Observes a variable and allocates memory for it
 */
void phalcon_memory_alloc(zval **var TSRMLS_DC)
{
	zend_phalcon_globals *g = PHALCON_VGLOBAL;
	phalcon_do_memory_observe(var, g);
	ALLOC_INIT_ZVAL(*var);
}

/**
 * Observes a variable and allocates memory for it
 * Marks hash key zvals to be nulled before freeing
 */
void phalcon_memory_alloc_pnull(zval **var TSRMLS_DC)
{
	zend_phalcon_globals *g = PHALCON_VGLOBAL;
	phalcon_memory_entry *active_memory = g->active_memory;

	phalcon_do_memory_observe(var, g);
	ALLOC_INIT_ZVAL(*var);

	if (active_memory->hash_pointer == active_memory->hash_capacity) {
		phalcon_reallocate_hmemory(g);
>>>>>>> master
	}

	active_memory->hash_addresses[active_memory->hash_pointer] = var;
	++active_memory->hash_pointer;
}
#endif

/**
 * Removes a memory pointer from the active memory pool
 */
<<<<<<< HEAD
void ZEND_FASTCALL zephir_memory_remove(zval **var TSRMLS_DC) {
=======
void phalcon_memory_remove(zval **var TSRMLS_DC) {
>>>>>>> master
	zval_ptr_dtor(var);
	*var = NULL;
}

/**
 * Cleans the zephir memory stack recursivery
 */
<<<<<<< HEAD
int ZEND_FASTCALL zephir_clean_restore_stack(TSRMLS_D) {
=======
int phalcon_clean_restore_stack(TSRMLS_D) {
>>>>>>> master

	zend_zephir_globals_def *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	while (zephir_globals_ptr->active_memory != NULL) {
		zephir_memory_restore_stack_common(zephir_globals_ptr TSRMLS_CC);
	}

	return SUCCESS;
}

/**
 * Copies a variable only if its refcount is greater than 1
 */
<<<<<<< HEAD
void ZEND_FASTCALL zephir_copy_ctor(zval *destination, zval *origin) {
=======
void phalcon_copy_ctor(zval *destination, zval *origin) {
>>>>>>> master
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

<<<<<<< HEAD
#ifndef ZEPHIR_RELEASE
	if (!zephir_globals_ptr->active_memory) {
=======
#ifndef PHALCON_RELEASE
	if (!phalcon_globals_ptr->active_memory) {
>>>>>>> master
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

static inline void zephir_dtor_func(zval *zvalue ZEND_FILE_LINE_DC)
{
	switch (Z_TYPE_P(zvalue) & IS_CONSTANT_TYPE_MASK) {
		case IS_STRING:
		case IS_CONSTANT:
			CHECK_ZVAL_STRING_REL(zvalue);
			STR_FREE_REL(zvalue->value.str.val);
			break;
#if PHP_VERSION_ID < 50600
		case IS_CONSTANT_ARRAY:
#endif
		case IS_ARRAY:  {
				TSRMLS_FETCH();
				if (zvalue->value.ht && (zvalue->value.ht != &EG(symbol_table))) {
					/* break possible cycles */
					Z_TYPE_P(zvalue) = IS_NULL;
					zend_hash_destroy(zvalue->value.ht);
					FREE_HASHTABLE(zvalue->value.ht);
				}
			}
			break;
		case IS_OBJECT:
			{
				TSRMLS_FETCH();
				Z_OBJ_HT_P(zvalue)->del_ref(zvalue TSRMLS_CC);
			}
			break;
		case IS_RESOURCE:
			{
				TSRMLS_FETCH();
				zend_list_delete(zvalue->value.lval);
			}
			break;
		case IS_LONG:
		case IS_DOUBLE:
		case IS_BOOL:
		case IS_NULL:
		default:
			return;
			break;
	}
}

void zephir_value_dtor(zval *zvalue ZEND_FILE_LINE_DC)
{
	if (zvalue->type <= IS_BOOL) {
		return;
	}
	zephir_dtor_func(zvalue ZEND_FILE_LINE_RELAY_CC);
}
