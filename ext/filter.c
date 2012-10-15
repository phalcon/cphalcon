
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
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"

/**
 * Phalcon\Filter
 *
 * The Phalcon\Filter component provides a set of commonly needed data filters. It provides
 * object oriented wrappers to the php filter extension. Also allows the developer to
 * define his/her own filters
 *
 *<code>
 *$filter = new Phalcon\Filter();
 *$filter->sanitize("some(one)@exa\\mple.com", "email"); // returns "someone@example.com"
 *$filter->sanitize("hello<<", "string"); // returns "hello"
 *$filter->sanitize("!100a019", "int"); // returns "100019"
 *$filter->sanitize("!100a019.01a", "float"); // returns "100019.01"
 *</code>
 *
 */

PHP_METHOD(Phalcon_Filter, __construct){

	zval *a0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	zend_update_property(phalcon_filter_ce, this_ptr, SL("_filters"), a0 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Filter, add){

	zval *name = NULL, *handler = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &name, &handler) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_filter_exception_ce, "Filter name must be string");
		return;
	}
	if (Z_TYPE_P(handler) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_filter_exception_ce, "Filter must be an object");
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_filters"), PH_NOISY_CC);
	phalcon_array_update_zval(&t0, name, &handler, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_filters"), t0 TSRMLS_CC);
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Sanizites a value with a specified single or set of filters
 *
 * @param  mixed $value
 * @param  mixed $filters
 * @return mixed
 */
PHP_METHOD(Phalcon_Filter, sanitize){

	zval *value = NULL, *filters = NULL, *new_value = NULL, *filter = NULL, *filter_value = NULL;
	zval *sanizited_value = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &value, &filters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(filters) == IS_ARRAY) { 
		PHALCON_CPY_WRT(new_value, value);
		if (Z_TYPE_P(value) != IS_NULL) {
			if (!phalcon_valid_foreach(filters TSRMLS_CC)) {
				return;
			}
			
			ah0 = Z_ARRVAL_P(filters);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_e618_0:
				if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
					goto fee_e618_0;
				}
				
				PHALCON_INIT_VAR(filter);
				ZVAL_ZVAL(filter, *hd, 1, 0);
				PHALCON_INIT_VAR(filter_value);
				PHALCON_CALL_METHOD_PARAMS_2(filter_value, this_ptr, "_sanitize", new_value, filter, PH_NO_CHECK);
				PHALCON_CPY_WRT(new_value, filter_value);
				zend_hash_move_forward_ex(ah0, &hp0);
				goto fes_e618_0;
			fee_e618_0:
			if(0){}
			
		}
		
		
		RETURN_CCTOR(new_value);
	}
	
	PHALCON_INIT_VAR(sanizited_value);
	PHALCON_CALL_METHOD_PARAMS_2(sanizited_value, this_ptr, "_sanitize", value, filters, PH_NO_CHECK);
	
	RETURN_CCTOR(sanizited_value);
}

/**
 * Internal sanizite wrapper to filter_var
 *
 * @param  mixed $value
 * @param  string $filter
 * @return mixed
 */
PHP_METHOD(Phalcon_Filter, _sanitize){

	zval *value = NULL, *filter = NULL, *filters = NULL, *filter_object = NULL;
	zval *class_name = NULL, *arguments = NULL, *filtered = NULL, *type = NULL;
	zval *escaped = NULL, *allow_fraction = NULL, *options = NULL, *exception_message = NULL;
	zval *exception = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &value, &filter) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(filters);
	phalcon_read_property(&filters, this_ptr, SL("_filters"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(filters, filter);
	if (eval_int) {
		PHALCON_INIT_VAR(filter_object);
		phalcon_array_fetch(&filter_object, filters, filter, PH_NOISY_CC);
		
		PHALCON_INIT_VAR(class_name);
		phalcon_get_class(class_name, filter_object TSRMLS_CC);
		if (PHALCON_COMPARE_STRING(class_name, "Closure")) {
			PHALCON_INIT_VAR(arguments);
			array_init(arguments);
			phalcon_array_append(&arguments, value, PH_SEPARATE TSRMLS_CC);
			
			PHALCON_INIT_VAR(filtered);
			PHALCON_CALL_FUNC_PARAMS_2(filtered, "call_user_func_array", filter_object, arguments);
		} else {
			PHALCON_INIT_VAR(filtered);
			PHALCON_CALL_METHOD_PARAMS_1(filtered, filter_object, "filter", value, PH_NO_CHECK);
		}
		
		
		RETURN_CCTOR(filtered);
	}
	
	if (PHALCON_COMPARE_STRING(filter, "email")) {
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 517);
		PHALCON_CPY_WRT(type, t0);
		
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "'", 1);
		
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, "", 1);
		
		PHALCON_INIT_VAR(escaped);
		phalcon_fast_str_replace(escaped, c0, c1, value TSRMLS_CC);
		
		PHALCON_INIT_VAR(filtered);
		PHALCON_CALL_FUNC_PARAMS_2(filtered, "filter_var", escaped, type);
		goto se_e618_1;
	}
	if (PHALCON_COMPARE_STRING(filter, "int")) {
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 519);
		PHALCON_CPY_WRT(type, t1);
		
		PHALCON_INIT_VAR(filtered);
		PHALCON_CALL_FUNC_PARAMS_2(filtered, "filter_var", value, type);
		goto se_e618_1;
	}
	if (PHALCON_COMPARE_STRING(filter, "string")) {
		PHALCON_INIT_VAR(t2);
		ZVAL_LONG(t2, 513);
		PHALCON_CPY_WRT(type, t2);
		
		PHALCON_INIT_VAR(filtered);
		PHALCON_CALL_FUNC_PARAMS_2(filtered, "filter_var", value, type);
		goto se_e618_1;
	}
	if (PHALCON_COMPARE_STRING(filter, "float")) {
		PHALCON_INIT_VAR(t3);
		ZVAL_LONG(t3, 4096);
		PHALCON_CPY_WRT(allow_fraction, t3);
		
		PHALCON_INIT_VAR(options);
		array_init(options);
		phalcon_array_update_string(&options, SL("flags"), &allow_fraction, PH_COPY | PH_SEPARATE TSRMLS_CC);
		
		PHALCON_INIT_VAR(t4);
		ZVAL_LONG(t4, 520);
		PHALCON_CPY_WRT(type, t4);
		
		PHALCON_INIT_VAR(filtered);
		PHALCON_CALL_FUNC_PARAMS_3(filtered, "filter_var", value, type, options);
		goto se_e618_1;
	}
	if (PHALCON_COMPARE_STRING(filter, "alphanum")) {
		PHALCON_INIT_VAR(filtered);
		phalcon_filter_alphanum(filtered, value);
		goto se_e618_1;
	}
	if (PHALCON_COMPARE_STRING(filter, "trim")) {
		PHALCON_INIT_VAR(filtered);
		PHALCON_CALL_FUNC_PARAMS_1(filtered, "trim", value);
		goto se_e618_1;
	}
	if (PHALCON_COMPARE_STRING(filter, "striptags")) {
		PHALCON_INIT_VAR(filtered);
		PHALCON_CALL_FUNC_PARAMS_1(filtered, "strip_tags", value);
		goto se_e618_1;
	}
	if (PHALCON_COMPARE_STRING(filter, "lower")) {
		PHALCON_INIT_VAR(filtered);
		PHALCON_CALL_FUNC_PARAMS_1(filtered, "strtolower", value);
		goto se_e618_1;
	}
	if (PHALCON_COMPARE_STRING(filter, "upper")) {
		PHALCON_INIT_VAR(filtered);
		PHALCON_CALL_FUNC_PARAMS_1(filtered, "strtoupper", value);
		goto se_e618_1;
	}
	PHALCON_INIT_VAR(exception_message);
	PHALCON_CONCAT_SVS(exception_message, "Sanitize filter ", filter, " is not supported");
	
	PHALCON_INIT_VAR(exception);
	object_init_ex(exception, phalcon_filter_exception_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(exception, "__construct", exception_message, PH_CHECK);
	phalcon_throw_exception(exception TSRMLS_CC);
	return;
	se_e618_1:
	
	RETURN_CCTOR(filtered);
}

/**
 * Return the user-defined filters in the instance
 *
 * @return object[]
 */
PHP_METHOD(Phalcon_Filter, getFilters){

	zval *filters = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(filters);
	phalcon_read_property(&filters, this_ptr, SL("_filters"), PH_NOISY_CC);
	
	RETURN_CCTOR(filters);
}

