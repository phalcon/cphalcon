
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#include "php.h"
#include "php_phalcon.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"

/**
 * Initializes/Reinitializes a variable
 */
inline void phalcon_init_var(zval **var TSRMLS_DC){
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
inline void phalcon_cpy_wrt(zval **dest, zval *var TSRMLS_DC){
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
 * Initializes memory stack for the active function
 */
int PHALCON_FASTCALL phalcon_memory_grow_stack(TSRMLS_D){

	phalcon_memory_entry *entry;

	if(!PHALCON_GLOBAL(start_memory)){
		PHALCON_GLOBAL(start_memory) = (phalcon_memory_entry *) emalloc(sizeof(phalcon_memory_entry));
		PHALCON_GLOBAL(start_memory)->pointer = -1;
		PHALCON_GLOBAL(start_memory)->prev = NULL;
		PHALCON_GLOBAL(start_memory)->next = NULL;
		PHALCON_GLOBAL(active_memory) = PHALCON_GLOBAL(start_memory);
	}

	entry = (phalcon_memory_entry *) emalloc(sizeof(phalcon_memory_entry));
	entry->addresses[0] = NULL;
	entry->pointer = -1;
	entry->prev = PHALCON_GLOBAL(active_memory);
	PHALCON_GLOBAL(active_memory)->next = entry;
	PHALCON_GLOBAL(active_memory) = entry;

	return SUCCESS;
}

/**
 * Finishes memory stack by releasing allocated memory
 */
int PHALCON_FASTCALL phalcon_memory_restore_stack(TSRMLS_D){

	register int i;
	phalcon_memory_entry *prev;
	phalcon_memory_entry *active_memory = PHALCON_GLOBAL(active_memory);

	if(active_memory != NULL){

		/*#ifndef PHALCON_RELEASE
		if(!PHALCON_GLOBAL(phalcon_stack_stats)){
			PHALCON_GLOBAL(phalcon_stack_stats) = active_memory->pointer;
		} else {
			if (active_memory->pointer > PHALCON_GLOBAL(phalcon_stack_stats)) {
				PHALCON_GLOBAL(phalcon_stack_stats) = active_memory->pointer;
			}
		}
		#endif*/

		if (active_memory->pointer > -1) {
			for (i = active_memory->pointer; i>=0; i--) {
				if(active_memory->addresses[i] != NULL){
					if(*active_memory->addresses[i] != NULL ){
						if (Z_REFCOUNT_PP(active_memory->addresses[i])-1 == 0) {
							zval_ptr_dtor(active_memory->addresses[i]);
							*active_memory->addresses[i] = NULL;
							active_memory->addresses[i] = NULL;
						} else {
							Z_DELREF_PP(active_memory->addresses[i]);
							if (Z_REFCOUNT_PP(active_memory->addresses[i]) == 1) {
								active_memory->addresses[i] = NULL;
							}
						}
					}
				}
			}
		}

		prev = active_memory->prev;
		efree(PHALCON_GLOBAL(active_memory));
		PHALCON_GLOBAL(active_memory) = prev;
		if (prev != NULL) {
			PHALCON_GLOBAL(active_memory)->next = NULL;
			if (PHALCON_GLOBAL(active_memory) == PHALCON_GLOBAL(start_memory)) {
				efree(PHALCON_GLOBAL(active_memory));
				PHALCON_GLOBAL(start_memory) = NULL;
				PHALCON_GLOBAL(active_memory) = NULL;
			}
		} else {
			PHALCON_GLOBAL(start_memory) = NULL;
			PHALCON_GLOBAL(active_memory) = NULL;
		}

	} else {
		return FAILURE;
	}

	return SUCCESS;
}

/**
 * Finishes memory stack when PHP throws a fatal error
 */
int PHALCON_FASTCALL phalcon_clean_shutdown_stack(TSRMLS_D){

	#if !ZEND_DEBUG

	phalcon_memory_entry *prev, *active_memory = PHALCON_GLOBAL(active_memory);

	while (active_memory != NULL) {

		prev = active_memory->prev;
		efree(active_memory);
		active_memory = prev;
		if (prev != NULL) {
			active_memory->next = NULL;
			if (active_memory == PHALCON_GLOBAL(start_memory)) {
				efree(active_memory);
				PHALCON_GLOBAL(start_memory) = NULL;
				active_memory = NULL;
			}
		} else {
			PHALCON_GLOBAL(start_memory) = NULL;
			active_memory = NULL;
		}

	}

	#endif

	return SUCCESS;

}

/**
 * Observes a memory pointer to release its memory at the end of the request
 */
int PHALCON_FASTCALL phalcon_memory_observe(zval **var TSRMLS_DC){
	phalcon_memory_entry *active_memory = PHALCON_GLOBAL(active_memory);
	active_memory->pointer++;
	#ifndef PHALCON_RELEASE
	if (active_memory->pointer >= (PHALCON_MAX_MEMORY_STACK-1)) {
		fprintf(stderr, "ERROR: Phalcon memory stack is too small %d\n", PHALCON_MAX_MEMORY_STACK);
		return FAILURE;
	}
	#endif
	active_memory->addresses[active_memory->pointer] = var;
	active_memory->addresses[active_memory->pointer+1] = NULL;
	return SUCCESS;
}

/**
 * Observe a variable and allocates memory for it
 */
int PHALCON_FASTCALL phalcon_memory_alloc(zval **var TSRMLS_DC){
	phalcon_memory_entry *active_memory = PHALCON_GLOBAL(active_memory);
	active_memory->pointer++;
	#ifndef PHALCON_RELEASE
	if (active_memory->pointer >= (PHALCON_MAX_MEMORY_STACK-1)) {
		fprintf(stderr, "ERROR: Phalcon memory stack is too small %d\n", PHALCON_MAX_MEMORY_STACK);
		return FAILURE;
	}
	#endif
	active_memory->addresses[active_memory->pointer] = var;
	active_memory->addresses[active_memory->pointer+1] = NULL;
	ALLOC_ZVAL(*var);
	INIT_PZVAL(*var);
	ZVAL_NULL(*var);
	return SUCCESS;
}

/**
 * Removes a memory pointer from the active memory pool
 */
int PHALCON_FASTCALL phalcon_memory_remove(zval **var TSRMLS_DC){
	zval_ptr_dtor(var);
	*var = NULL;
	return SUCCESS;
}

/**
 * Cleans the phalcon memory stack recursivery
 */
int PHALCON_FASTCALL phalcon_clean_restore_stack(TSRMLS_D){
	while (PHALCON_GLOBAL(active_memory) != NULL) {
		phalcon_memory_restore_stack(TSRMLS_C);
	}
	return SUCCESS;
}