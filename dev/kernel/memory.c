
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

/**
 * Initializes memory stack for the active function
 */
int phalcon_memory_grow_stack(TSRMLS_D){

	register int i;
	phalcon_memory_entry *entry;

	if(!PHALCON_GLOBAL(start_memory)){
		PHALCON_GLOBAL(start_memory) = (phalcon_memory_entry *) emalloc(sizeof(phalcon_memory_entry));
		PHALCON_GLOBAL(start_memory)->pointer = -1;
		PHALCON_GLOBAL(start_memory)->prev = NULL;
		PHALCON_GLOBAL(start_memory)->next = NULL;
		PHALCON_GLOBAL(active_memory) = PHALCON_GLOBAL(start_memory);
	}

	entry = (phalcon_memory_entry *) emalloc(sizeof(phalcon_memory_entry));
	for(i=0;i<PHALCON_MAX_MEMORY_STACK;i++){
		entry->addresses[i] = NULL;
	}
	entry->pointer = -1;
	entry->prev = PHALCON_GLOBAL(active_memory);
	PHALCON_GLOBAL(active_memory)->next = entry;
	PHALCON_GLOBAL(active_memory) = entry;

	return SUCCESS;
}

/**
 * Finishes memory stack by releasing allocated memory
 */
int phalcon_memory_restore_stack(TSRMLS_D){

	register int i;
	phalcon_memory_entry *prev;
	phalcon_memory_entry *active_memory = PHALCON_GLOBAL(active_memory);

	if(active_memory){

		if (active_memory->pointer > -1) {
			for (i=active_memory->pointer;i>=0;i--) {
				if(active_memory->addresses[i] != NULL){
					if(*active_memory->addresses[i]){
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
		if(prev != NULL){
			PHALCON_GLOBAL(active_memory)->next = NULL;
			if(PHALCON_GLOBAL(active_memory)==PHALCON_GLOBAL(start_memory)){
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
 * Observes a memory pointer to release its memory at the end of the request
 */
int phalcon_memory_observe(zval **var TSRMLS_DC){
	phalcon_memory_entry *active_memory = PHALCON_GLOBAL(active_memory);
	active_memory->pointer++;
	active_memory->addresses[active_memory->pointer] = var;
	return SUCCESS;
}

/**
 * Removes a memory pointer from the active memory pool
 */
int phalcon_memory_remove(zval **var TSRMLS_DC){
	zval_ptr_dtor(var);
	*var = NULL;
	return SUCCESS;
}
