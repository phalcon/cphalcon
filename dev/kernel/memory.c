
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

int phalcon_memory_stack = 0;

phalcon_memory_entry *start_memory = NULL;
phalcon_memory_entry *active_memory = NULL;

int phalcon_memory_grow_stack(){

	phalcon_memory_entry *entry;

	if(!start_memory){
		start_memory = (phalcon_memory_entry *) emalloc(sizeof(phalcon_memory_entry));
		start_memory->pointer = -1;
		start_memory->prev = NULL;
		start_memory->next = NULL;
		active_memory = start_memory;
	}

	entry = (phalcon_memory_entry *) emalloc(sizeof(phalcon_memory_entry));
	int i;
	for(i=0;i<PHALCON_MAX_MEMORY_STACK;i++){
		entry->addresses[i] = NULL;
	}
	entry->pointer = -1;
	entry->prev = active_memory;
	active_memory->next = entry;
	active_memory = entry;

	return SUCCESS;
}

int phalcon_memory_restore_stack(){

	register int i;
	phalcon_memory_entry *prev;

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
		efree(active_memory);
		active_memory = prev;
		if(prev != NULL){
			active_memory->next = NULL;
			if(active_memory==start_memory){
				efree(active_memory);
				start_memory = NULL;
				active_memory = NULL;
			}
		} else {
			start_memory = NULL;
			active_memory = NULL;
		}

	} else {
		return FAILURE;
	}

	return SUCCESS;
}

int phalcon_memory_observe(zval **var){
	active_memory->pointer++;
	active_memory->addresses[active_memory->pointer] = var;
	return SUCCESS;
}

int phalcon_memory_remove(zval **var){
	zval_ptr_dtor(var);
	*var = NULL;
	return SUCCESS;
}
