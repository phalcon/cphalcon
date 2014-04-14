
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "kernel/debug.h"
#include "kernel/string.h"

#ifndef PHALCON_RELEASE

FILE *phalcon_log = NULL;
int phalcon_debug_trace = 0;
phalcon_debug_entry *start = NULL;
phalcon_debug_entry *active = NULL;

/**
 * Stars debug on file pipe
 */
int phalcon_start_debug(){
	if(!phalcon_log){
		phalcon_log = stderr;
	}
	return SUCCESS;
}

/**
 * Stops debug process
 */
int phalcon_stop_debug(){
	phalcon_debug_entry *ptr = active;
	phalcon_debug_entry *this_entry = NULL;
	while(ptr){
		this_entry = ptr;
		ptr = ptr->prev;
		efree(this_entry);
	}
	//fclose(phalcon_log);
	phalcon_log = NULL;
	return SUCCESS;
}

/**
 * Executes a print_r on an interal zval
 */
int phalcon_print_r(zval *userval TSRMLS_DC){
	zend_print_zval_r(userval, 0 TSRMLS_CC);
	return SUCCESS;
}

/**
 * Internal fast zval dump
 */
int phalcon_vdump(zval *uservar TSRMLS_DC){
	phalcon_start_debug();
    if(!uservar){
		fprintf(phalcon_log, "Null pointer\n");
		return SUCCESS;
	}
    switch(Z_TYPE_P(uservar)){
        case IS_NULL:
            fprintf(phalcon_log, "NULL \n");
            break;
        case IS_BOOL:
            fprintf(phalcon_log, "Boolean: %s\n", Z_LVAL_P(uservar) ? "TRUE" : "FALSE");
            break;
        case IS_LONG:
            fprintf(phalcon_log, "Long: %ld at %p, refcount=%d\n", Z_LVAL_P(uservar), uservar, Z_REFCOUNT_P(uservar));
            break;
        case IS_DOUBLE:
            fprintf(phalcon_log, "Double: %f\n", Z_DVAL_P(uservar));
            break;
        case IS_STRING:
			fprintf(phalcon_log, "String: %s(%d) at %p, refcount=%d\n", Z_STRVAL_P(uservar), Z_STRLEN_P(uservar), uservar, Z_REFCOUNT_P(uservar));
            break;
        case IS_RESOURCE:
            fprintf(phalcon_log, "Resource\n");
            break;
        case IS_ARRAY:
            fprintf(phalcon_log, "Array at %p, refcount=%d\n", uservar, Z_REFCOUNT_P(uservar));
            break;
        case IS_OBJECT:
            fprintf(phalcon_log, "Object <%s> at %p\n", Z_OBJCE_P(uservar)->name, uservar);
            break;
        default:
            fprintf(phalcon_log, "Unknown\n");
    }
    return SUCCESS;
}

int phalcon_dump_ce(zend_class_entry *ce TSRMLS_DC){
	char *message = emalloc(sizeof(char *) * 120);
	if(ce){
		snprintf(message, 120, "- ClassType => %d", ce->type);
		phalcon_step_over(message);
		if(ce->name){
			snprintf(message, 120, "- ClassName => %s", ce->name);
			phalcon_step_over(message);
		} else {
			phalcon_step_over("- ClassName => NULL");
		}
	} else {
		phalcon_step_over("- NULL class entry :(");
	}
	return SUCCESS;
}

int phalcon_class_debug(zval *val TSRMLS_DC){
	char *message = emalloc(sizeof(char *) * 120);
	zend_class_entry *ce;
	if (val) {
		ce = Z_OBJCE_P(val);
		if(ce){
			snprintf(message, 120, "- MemoryAddress => %p", val);
			phalcon_step_over(message);
			phalcon_dump_ce(ce TSRMLS_CC);
		} else {
			phalcon_step_over("- No class entry :(");
		}
	} else {
		phalcon_step_over("- this_ptr is null :(");
	}
	return SUCCESS;
}

/**
 * Append debug information to file
 */
int phalcon_debug_str(char *what, char *message){
	fprintf(phalcon_log, "%s", what);
	fprintf(phalcon_log, "%s", message);
	fprintf(phalcon_log, "\n");
	return SUCCESS;
}

int phalcon_debug_long(char *what, uint vlong){
	fprintf(phalcon_log, "%s", what);
	fprintf(phalcon_log, "%u", vlong);
	fprintf(phalcon_log, "\n");
	return SUCCESS;
}

int phalcon_debug_screen(char *message){
	phalcon_debug_space();
	fprintf(phalcon_log, "%s\n", message);
	return SUCCESS;
}

int phalcon_debug_method_call(zval *obj, char *method_name TSRMLS_DC){
	if(Z_TYPE_P(obj)==IS_OBJECT){
		phalcon_debug_space();
	} else {
		phalcon_error_space();
	}
	if(Z_TYPE_P(obj)==IS_OBJECT){
		fprintf(phalcon_log, "Calling method %s::%s on Object at %p\n", Z_OBJCE_P(obj)->name, method_name, obj);
	} else {
		fprintf(phalcon_log, "Calling method %s on non object :(\n", method_name);
	}
	return SUCCESS;
}

int phalcon_error_space(){
	int i;
	fprintf(phalcon_log, "[ERROR] ");
	for(i=0;i<phalcon_debug_trace;i++){
		fprintf(phalcon_log, " ");
	}
	return SUCCESS;
}

int phalcon_debug_space(){
	int i;
	fprintf(phalcon_log, "[DEBUG] ");
	for(i=0;i<phalcon_debug_trace;i++){
		fprintf(phalcon_log, " ");
	}
	return SUCCESS;
}

int phalcon_debug_param(zval *param TSRMLS_DC){
	phalcon_debug_space();
	fprintf(phalcon_log, "Push method Param > ");
	phalcon_vdump(param TSRMLS_CC);
	return SUCCESS;
}

int phalcon_debug_vdump(char *preffix, zval *value TSRMLS_DC){
	phalcon_debug_space();
	fprintf(phalcon_log, "%s", preffix);
	phalcon_vdump(value TSRMLS_CC);
	return SUCCESS;
}

int phalcon_debug_assign(char *name, zval *value TSRMLS_DC){
	phalcon_debug_space();
	fprintf(phalcon_log, "Assign on %s with ", name);
	phalcon_vdump(value TSRMLS_CC);
	return SUCCESS;
}

int phalcon_step_over(char *message){
	phalcon_debug_screen(message);
	return SUCCESS;
}

int phalcon_step_into(char *message){
	phalcon_debug_trace++;
	phalcon_debug_screen(message);
	return SUCCESS;
}

int phalcon_step_out(char *message){
	phalcon_debug_screen(message);
	phalcon_debug_trace--;
	return SUCCESS;
}

/**
 * Prints internal debug backtrace
 */
int phalcon_debug_backtrace_internal(){
	int step = 0;
	char *message;
	phalcon_debug_entry *ptr = active;
	while(ptr){
		phalcon_spprintf(&message, 0, "#%d %s::%s", step, ptr->class_name, ptr->method_name);
		phalcon_debug_screen(message);
		efree(message);
		ptr = ptr->prev;
		step++;
	}
	return SUCCESS;
}

/**
 * Appends a debug entry to internal execution scope
 */
int phalcon_step_into_entry(char *class_name, char *method_name, int lineno){

	char *message;
	phalcon_debug_entry *entry;

	if (!start) {
		start = (phalcon_debug_entry *) emalloc(sizeof(phalcon_debug_entry));
		start->class_name = "__main__";
		start->method_name = "__init__";
		start->lineno = 0;
		start->prev = NULL;
		start->next = NULL;
		active = start;
	}

	phalcon_spprintf(&message, 0, "Step Into %s::%s", class_name, method_name);
	phalcon_debug_screen(message);
	efree(message);

	entry = emalloc(sizeof(phalcon_debug_entry));
	entry->class_name = class_name;
	entry->method_name = method_name;
	entry->lineno = lineno;
	entry->prev = active;
	active->next = entry;
	active = entry;
	phalcon_debug_trace++;

	return SUCCESS;
}

/**
 * Steps out current stack
 */
int phalcon_step_out_entry(){

	char *message;
	phalcon_debug_entry *prev;
	if(active){

		phalcon_debug_trace--;

		phalcon_spprintf(&message, 0, "Step out %s::%s", active->class_name, active->method_name);
		phalcon_debug_screen(message);
		efree(message);

		prev = active->prev;
		efree(active);
		active = prev;

	} else {
		fprintf(phalcon_log, "Problem, stack?");
		return FAILURE;
	}
	return SUCCESS;
}

#endif
