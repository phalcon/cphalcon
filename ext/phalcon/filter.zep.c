
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "Zend/zend_closures.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * Phalcon\Filter
 *
 * The Phalcon\Filter component provides a set of commonly needed data filters. It provides
 * object oriented wrappers to the php filter extension. Also allows the developer to
 * define his/her own filters
 *
 *<code>
 * $filter = new \Phalcon\Filter();
 *
 * $filter->sanitize("some(one)@exa\\mple.com", "email"); // returns "someone@example.com"
 * $filter->sanitize("hello<<", "string"); // returns "hello"
 * $filter->sanitize("!100a019", "int"); // returns "100019"
 * $filter->sanitize("!100a019.01a", "float"); // returns "100019.01"
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Filter, phalcon, filter, phalcon_filter_method_entry, 0);

	zend_declare_property_null(phalcon_filter_ce, SL("_filters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_EMAIL"), "email" TSRMLS_CC);

	zend_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_ABSINT"), "absint" TSRMLS_CC);

	zend_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_INT"), "int" TSRMLS_CC);

	zend_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_INT_CAST"), "int!" TSRMLS_CC);

	zend_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_STRING"), "string" TSRMLS_CC);

	zend_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_FLOAT"), "float" TSRMLS_CC);

	zend_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_FLOAT_CAST"), "float!" TSRMLS_CC);

	zend_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_ALPHANUM"), "alphanum" TSRMLS_CC);

	zend_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_TRIM"), "trim" TSRMLS_CC);

	zend_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_STRIPTAGS"), "striptags" TSRMLS_CC);

	zend_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_LOWER"), "lower" TSRMLS_CC);

	zend_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_UPPER"), "upper" TSRMLS_CC);

	zend_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_URL"), "url" TSRMLS_CC);

	zend_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_SPECIAL_CHARS"), "special_chars" TSRMLS_CC);

	zend_class_implements(phalcon_filter_ce TSRMLS_CC, 1, phalcon_filterinterface_ce);
	return SUCCESS;

}

/**
 * Adds a user-defined filter
 */
PHP_METHOD(Phalcon_Filter, add) {

	zend_bool _0;
	zval *name_param = NULL, *handler;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	_0 = Z_TYPE_P(handler) != IS_OBJECT;
	if (_0) {
		_0 = !(zephir_is_callable(handler TSRMLS_CC));
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_filter_exception_ce, "Filter must be an object or callable", "phalcon/filter.zep", 79);
		return;
	}
	zephir_update_property_array(this_ptr, SL("_filters"), name, handler TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sanitizes a value with a specified single or set of filters
 */
PHP_METHOD(Phalcon_Filter, sanitize) {

	HashTable *_1$$4, *_5$$6, *_12$$9;
	HashPosition _0$$4, _4$$6, _11$$9;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool noRecursive, _10, _3$$5;
	zval *value = NULL, *filters, *noRecursive_param = NULL, *filter = NULL, *arrayValue = NULL, *itemKey = NULL, *itemValue = NULL, *sanitizedValue = NULL, **_2$$4, **_6$$6, *_7$$7 = NULL, *_9$$8 = NULL, **_13$$9, *_14$$10 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &value, &filters, &noRecursive_param);

	ZEPHIR_SEPARATE_PARAM(value);
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		noRecursive = zephir_get_boolval(noRecursive_param);
	}


	if (Z_TYPE_P(filters) == IS_ARRAY) {
		if (Z_TYPE_P(value) != IS_NULL) {
			zephir_is_iterable(filters, &_1$$4, &_0$$4, 0, 0, "phalcon/filter.zep", 112);
			for (
			  ; zend_hash_get_current_data_ex(_1$$4, (void**) &_2$$4, &_0$$4) == SUCCESS
			  ; zend_hash_move_forward_ex(_1$$4, &_0$$4)
			) {
				ZEPHIR_GET_HVALUE(filter, _2$$4);
				_3$$5 = Z_TYPE_P(value) == IS_ARRAY;
				if (_3$$5) {
					_3$$5 = !noRecursive;
				}
				if (_3$$5) {
					ZEPHIR_INIT_NVAR(arrayValue);
					array_init(arrayValue);
					zephir_is_iterable(value, &_5$$6, &_4$$6, 0, 0, "phalcon/filter.zep", 107);
					for (
					  ; zend_hash_get_current_data_ex(_5$$6, (void**) &_6$$6, &_4$$6) == SUCCESS
					  ; zend_hash_move_forward_ex(_5$$6, &_4$$6)
					) {
						ZEPHIR_GET_HMKEY(itemKey, _5$$6, _4$$6);
						ZEPHIR_GET_HVALUE(itemValue, _6$$6);
						ZEPHIR_CALL_METHOD(&_7$$7, this_ptr, "_sanitize", &_8, 0, itemValue, filter);
						zephir_check_call_status();
						zephir_array_update_zval(&arrayValue, itemKey, &_7$$7, PH_COPY | PH_SEPARATE);
					}
					ZEPHIR_CPY_WRT(value, arrayValue);
				} else {
					ZEPHIR_CALL_METHOD(&_9$$8, this_ptr, "_sanitize", &_8, 0, value, filter);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(value, _9$$8);
				}
			}
		}
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	_10 = Z_TYPE_P(value) == IS_ARRAY;
	if (_10) {
		_10 = !noRecursive;
	}
	if (_10) {
		ZEPHIR_INIT_VAR(sanitizedValue);
		array_init(sanitizedValue);
		zephir_is_iterable(value, &_12$$9, &_11$$9, 0, 0, "phalcon/filter.zep", 124);
		for (
		  ; zend_hash_get_current_data_ex(_12$$9, (void**) &_13$$9, &_11$$9) == SUCCESS
		  ; zend_hash_move_forward_ex(_12$$9, &_11$$9)
		) {
			ZEPHIR_GET_HMKEY(itemKey, _12$$9, _11$$9);
			ZEPHIR_GET_HVALUE(itemValue, _13$$9);
			ZEPHIR_CALL_METHOD(&_14$$10, this_ptr, "_sanitize", &_8, 0, itemValue, filters);
			zephir_check_call_status();
			zephir_array_update_zval(&sanitizedValue, itemKey, &_14$$10, PH_COPY | PH_SEPARATE);
		}
		RETURN_CCTOR(sanitizedValue);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_sanitize", &_8, 0, value, filters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Internal sanitize wrapper to filter_var
 */
PHP_METHOD(Phalcon_Filter, _sanitize) {

	zval *_3$$4, *_9$$10;
	zend_bool _1$$3, _2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filter = NULL, *_16$$21;
	zval *value, *filter_param = NULL, *filterObject = NULL, *_0, _4$$5, *_5$$5 = NULL, _6$$6, _7$$8, _8$$9, _10$$10, *_11$$12, *_12$$12, _13$$19, _14$$20, *_15$$21;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &value, &filter_param);

	if (UNEXPECTED(Z_TYPE_P(filter_param) != IS_STRING && Z_TYPE_P(filter_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filter' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(filter_param) == IS_STRING)) {
		zephir_get_strval(filter, filter_param);
	} else {
		ZEPHIR_INIT_VAR(filter);
		ZVAL_EMPTY_STRING(filter);
	}


	ZEPHIR_OBS_VAR(filterObject);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_filters"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&filterObject, _0, filter, 0 TSRMLS_CC)) {
		_1$$3 = Z_TYPE_P(filterObject) == IS_OBJECT;
		if (_1$$3) {
			_1$$3 = zephir_instance_of_ev(filterObject, zend_ce_closure TSRMLS_CC);
		}
		_2$$3 = _1$$3;
		if (!(_2$$3)) {
			_2$$3 = zephir_is_callable(filterObject TSRMLS_CC);
		}
		if (_2$$3) {
			ZEPHIR_INIT_VAR(_3$$4);
			zephir_create_array(_3$$4, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(_3$$4, value);
			ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, filterObject, _3$$4);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_RETURN_CALL_METHOD(filterObject, "filter", NULL, 0, value);
		zephir_check_call_status();
		RETURN_MM();
	}
	do {
		if (ZEPHIR_IS_STRING(filter, "email")) {
			ZEPHIR_SINIT_VAR(_4$$5);
			ZVAL_STRING(&_4$$5, "FILTER_SANITIZE_EMAIL", 0);
			ZEPHIR_CALL_FUNCTION(&_5$$5, "constant", NULL, 38, &_4$$5);
			zephir_check_call_status();
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", NULL, 212, value, _5$$5);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "int")) {
			ZEPHIR_SINIT_VAR(_6$$6);
			ZVAL_LONG(&_6$$6, 519);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", NULL, 212, value, &_6$$6);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "int!")) {
			RETURN_MM_LONG(zephir_get_intval(value));
		}
		if (ZEPHIR_IS_STRING(filter, "absint")) {
			ZEPHIR_SINIT_VAR(_7$$8);
			ZVAL_LONG(&_7$$8, zephir_get_intval(value));
			ZEPHIR_RETURN_CALL_FUNCTION("abs", NULL, 213, &_7$$8);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "string")) {
			ZEPHIR_SINIT_VAR(_8$$9);
			ZVAL_LONG(&_8$$9, 513);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", NULL, 212, value, &_8$$9);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "float")) {
			ZEPHIR_INIT_VAR(_9$$10);
			zephir_create_array(_9$$10, 1, 0 TSRMLS_CC);
			add_assoc_long_ex(_9$$10, SS("flags"), 4096);
			ZEPHIR_SINIT_VAR(_10$$10);
			ZVAL_LONG(&_10$$10, 520);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", NULL, 212, value, &_10$$10, _9$$10);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "float!")) {
			RETURN_MM_DOUBLE(zephir_get_doubleval(value));
		}
		if (ZEPHIR_IS_STRING(filter, "alphanum")) {
			ZEPHIR_INIT_VAR(_11$$12);
			ZVAL_STRING(_11$$12, "/[^A-Za-z0-9]/", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_12$$12);
			ZVAL_STRING(_12$$12, "", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 42, _11$$12, _12$$12, value);
			zephir_check_temp_parameter(_11$$12);
			zephir_check_temp_parameter(_12$$12);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "trim")) {
			zephir_fast_trim(return_value, value, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "striptags")) {
			ZEPHIR_RETURN_CALL_FUNCTION("strip_tags", NULL, 214, value);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "lower")) {
			if ((zephir_function_exists_ex(SS("mb_strtolower") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_RETURN_CALL_FUNCTION("mb_strtolower", NULL, 215, value);
				zephir_check_call_status();
				RETURN_MM();
			}
			zephir_fast_strtolower(return_value, value);
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "upper")) {
			if ((zephir_function_exists_ex(SS("mb_strtoupper") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_RETURN_CALL_FUNCTION("mb_strtoupper", NULL, 216, value);
				zephir_check_call_status();
				RETURN_MM();
			}
			zephir_fast_strtoupper(return_value, value);
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "url")) {
			ZEPHIR_SINIT_VAR(_13$$19);
			ZVAL_LONG(&_13$$19, 518);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", NULL, 212, value, &_13$$19);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "special_chars")) {
			ZEPHIR_SINIT_VAR(_14$$20);
			ZVAL_LONG(&_14$$20, 515);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", NULL, 212, value, &_14$$20);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(_15$$21);
		object_init_ex(_15$$21, phalcon_filter_exception_ce);
		ZEPHIR_INIT_VAR(_16$$21);
		ZEPHIR_CONCAT_SVS(_16$$21, "Sanitize filter '", filter, "' is not supported");
		ZEPHIR_CALL_METHOD(NULL, _15$$21, "__construct", NULL, 9, _16$$21);
		zephir_check_call_status();
		zephir_throw_exception_debug(_15$$21, "phalcon/filter.zep", 226 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

/**
 * Return the user-defined filters in the instance
 */
PHP_METHOD(Phalcon_Filter, getFilters) {

	

	RETURN_MEMBER(getThis(), "_filters");

}

