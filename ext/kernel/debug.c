
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
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include "php_ext.h"
#include "kernel/debug.h"
#include "kernel/main.h"
#include "kernel/string.h"

#ifndef ZEPHIR_RELEASE

FILE *zephir_log = NULL;
int zephir_debug_trace = 0;
static zephir_debug_entry *start = NULL;
static zephir_debug_entry *active = NULL;

/**
 * Stars debug on file pipe
 */
int zephir_start_debug(){
	if(!zephir_log){
		/*//zephir_log = fopen("/home/gutierrezandresfelipe/phalcon-debug.a", "w");
		zephir_log = fopen("/tmp/phalcon-debug.a", "w");
		if(!zephir_log){
			fprintf(stderr, "Can't open debug log\n");
		}*/
		zephir_log = stderr;
	}
	return SUCCESS;
}

/**
 * Stops debug process
 */
int zephir_stop_debug(){
	zephir_debug_entry *ptr = active;
	zephir_debug_entry *this_entry = NULL;
	while(ptr){
		this_entry = ptr;
		ptr = ptr->prev;
		efree(this_entry);
	}
	//fclose(zephir_log);
	zephir_log = NULL;
	return SUCCESS;
}

/**
 * Executes a print_r on an interal zval
 */
int zephir_print_r(zval *userval TSRMLS_DC){
	zend_print_zval_r(userval, 0 TSRMLS_CC);
	return SUCCESS;
}

/**
 * Internal fast zval dump
 */
int zephir_vdump(zval *uservar TSRMLS_DC){
	zephir_start_debug();
    if(!uservar){
		fprintf(zephir_log, "Null pointer\n");
		return SUCCESS;
	}
    switch(Z_TYPE_P(uservar)){
        case IS_NULL:
            fprintf(zephir_log, "NULL \n");
            break;
        case IS_BOOL:
            fprintf(zephir_log, "Boolean: %s\n", Z_LVAL_P(uservar) ? "TRUE" : "FALSE");
            break;
        case IS_LONG:
            fprintf(zephir_log, "Long: %ld at %p, refcount=%d\n", Z_LVAL_P(uservar), uservar, Z_REFCOUNT_P(uservar));
            break;
        case IS_DOUBLE:
            fprintf(zephir_log, "Double: %f\n", Z_DVAL_P(uservar));
            break;
        case IS_STRING:
			fprintf(zephir_log, "String: %s(%d) at %p, refcount=%d\n", Z_STRVAL_P(uservar), Z_STRLEN_P(uservar), uservar, Z_REFCOUNT_P(uservar));
            break;
        case IS_RESOURCE:
            fprintf(zephir_log, "Resource\n");
            break;
        case IS_ARRAY:
            fprintf(zephir_log, "Array at %p, refcount=%d\n", uservar, Z_REFCOUNT_P(uservar));
            break;
        case IS_OBJECT:
            fprintf(zephir_log, "Object <%s> at %p\n", Z_OBJCE_P(uservar)->name, uservar);
            break;
        default:
            fprintf(zephir_log, "Unknown\n");
    }
    return SUCCESS;
}

int zephir_dump_ce(zend_class_entry *ce TSRMLS_DC){
	char *message = emalloc(sizeof(char *)*120);
	if(ce){
		sprintf(message, "- ClassType => %d", ce->type);
		zephir_step_over(message);
		if(ce->name){
			sprintf(message, "- ClassName => %s", ce->name);
			zephir_step_over(message);
		} else {
			zephir_step_over("- ClassName => NULL");
		}
	} else {
		zephir_step_over("- NULL class entry :(");
	}
	return SUCCESS;
}

int zephir_class_debug(zval *val TSRMLS_DC){
	char *message = emalloc(sizeof(char *)*120);
	zend_class_entry *ce;
	if(val){
		ce = Z_OBJCE_P(val);
		if(ce){
			sprintf(message, "- MemoryAddress => %p", val);
			zephir_step_over(message);
			zephir_dump_ce(ce TSRMLS_CC);
		} else {
			zephir_step_over("- No class entry :(");
		}
	} else {
		zephir_step_over("- this_ptr is null :(");
	}
	return SUCCESS;
}

/**
 * Append debug information to file
 */
int zephir_debug_str(char *what, char *message){
	fprintf(zephir_log, "%s", what);
	fprintf(zephir_log, "%s", message);
	fprintf(zephir_log, "\n");
	return SUCCESS;
}

int zephir_debug_long(char *what, uint vlong){
	fprintf(zephir_log, "%s", what);
	fprintf(zephir_log, "%u", vlong);
	fprintf(zephir_log, "\n");
	return SUCCESS;
}

int zephir_debug_screen(char *message){
	zephir_debug_space();
	fprintf(zephir_log, "%s\n", message);
	return SUCCESS;
}

int zephir_debug_method_call(zval *obj, char *method_name TSRMLS_DC){
	if(Z_TYPE_P(obj)==IS_OBJECT){
		zephir_debug_space();
	} else {
		zephir_error_space();
	}
	if(Z_TYPE_P(obj)==IS_OBJECT){
		fprintf(zephir_log, "Calling method %s::%s on Object at %p\n", Z_OBJCE_P(obj)->name, method_name, obj);
	} else {
		fprintf(zephir_log, "Calling method %s on non object :(\n", method_name);
	}
	return SUCCESS;
}

int zephir_error_space(){
	int i;
	fprintf(zephir_log, "[ERROR] ");
	for(i=0;i<zephir_debug_trace;i++){
		fprintf(zephir_log, " ");
	}
	return SUCCESS;
}

int zephir_debug_space(){
	int i;
	fprintf(zephir_log, "[DEBUG] ");
	for(i=0;i<zephir_debug_trace;i++){
		fprintf(zephir_log, " ");
	}
	return SUCCESS;
}

int zephir_debug_param(zval *param TSRMLS_DC){
	zephir_debug_space();
	fprintf(zephir_log, "Push method Param > ");
	zephir_vdump(param TSRMLS_CC);
	return SUCCESS;
}

int zephir_debug_vdump(char *preffix, zval *value TSRMLS_DC){
	zephir_debug_space();
	fprintf(zephir_log, "%s", preffix);
	zephir_vdump(value TSRMLS_CC);
	return SUCCESS;
}

int zephir_debug_assign(char *name, zval *value TSRMLS_DC){
	zephir_debug_space();
	fprintf(zephir_log, "Assign on %s with ", name);
	zephir_vdump(value TSRMLS_CC);
	return SUCCESS;
}

int zephir_step_over(char *message){
	zephir_debug_screen(message);
	return SUCCESS;
}

int zephir_step_into(char *message){
	zephir_debug_trace++;
	zephir_debug_screen(message);
	return SUCCESS;
}

int zephir_step_out(char *message){
	zephir_debug_screen(message);
	zephir_debug_trace--;
	return SUCCESS;
}

/**
 * Prints internal debug backtrace
 */
int zephir_debug_backtrace_internal(){
	int step = 0;
	char *message;
	zephir_debug_entry *ptr = active;
	while(ptr){
		zephir_spprintf(&message, 0, "#%d %s::%s", step, ptr->class_name, ptr->method_name);
		zephir_debug_screen(message);
		efree(message);
		ptr = ptr->prev;
		step++;
	}
	return SUCCESS;
}

/**
 * Appends a debug entry to internal execution scope
 */
int zephir_step_into_entry(char *class_name, char *method_name, int lineno){

	char *message;
	zephir_debug_entry *entry;

	if (!start) {
		start = (zephir_debug_entry *) emalloc(sizeof(zephir_debug_entry));
		start->class_name = "__main__";
		start->method_name = "__init__";
		start->lineno = 0;
		start->prev = NULL;
		start->next = NULL;
		active = start;
	}

	zephir_spprintf(&message, 0, "Step Into %s::%s", class_name, method_name);
	zephir_debug_screen(message);
	efree(message);

	entry = emalloc(sizeof(zephir_debug_entry));
	entry->class_name = class_name;
	entry->method_name = method_name;
	entry->lineno = lineno;
	entry->prev = active;
	active->next = entry;
	active = entry;
	zephir_debug_trace++;

	return SUCCESS;
}

/**
 * Steps out current stack
 */
int zephir_step_out_entry(){

	char *message;
	zephir_debug_entry *prev;
	if(active){

		zephir_debug_trace--;

		zephir_spprintf(&message, 0, "Step out %s::%s", active->class_name, active->method_name);
		zephir_debug_screen(message);
		efree(message);

		prev = active->prev;
		efree(active);
		active = prev;

	} else {
		fprintf(zephir_log, "Problem, stack?");
		return FAILURE;
	}
	return SUCCESS;
}

#endif
