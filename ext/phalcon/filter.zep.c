
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

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_EMAIL"), "email");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_ABSINT"), "absint");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_INT"), "int");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_INT_CAST"), "int!");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_STRING"), "string");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_FLOAT"), "float");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_FLOAT_CAST"), "float!");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_ALPHANUM"), "alphanum");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_TRIM"), "trim");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_STRIPTAGS"), "striptags");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_LOWER"), "lower");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_UPPER"), "upper");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_URL"), "url");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_SPECIAL_CHARS"), "special_chars");

	zend_class_implements(phalcon_filter_ce TSRMLS_CC, 1, phalcon_filterinterface_ce);
	return SUCCESS;

}

/**
 * Adds a user-defined filter
 */
PHP_METHOD(Phalcon_Filter, add) {

	zend_bool _0;
	zval *name_param = NULL, *handler, handler_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&handler_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	_0 = Z_TYPE_P(handler) != IS_OBJECT;
	if (_0) {
		_0 = !(zephir_is_callable(handler TSRMLS_CC));
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_filter_exception_ce, "Filter must be an object or callable", "phalcon/filter.zep", 79);
		return;
	}
	zephir_update_property_array(this_ptr, SL("_filters"), &name, handler TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sanitizes a value with a specified single or set of filters
 */
PHP_METHOD(Phalcon_Filter, sanitize) {

	zend_string *_4$$6, *_11$$9;
	zend_ulong _3$$6, _10$$9;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool noRecursive, _8, _1$$5;
	zval *value = NULL, value_sub, *filters, filters_sub, *noRecursive_param = NULL, filter, arrayValue, itemKey, itemValue, sanitizedValue, *_0$$4, *_2$$6, _5$$7, _7$$8, *_9$$9, _12$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&arrayValue);
	ZVAL_UNDEF(&itemKey);
	ZVAL_UNDEF(&itemValue);
	ZVAL_UNDEF(&sanitizedValue);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_12$$10);

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
			zephir_is_iterable(filters, 0, "phalcon/filter.zep", 112);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(filters), _0$$4)
			{
				ZEPHIR_INIT_NVAR(&filter);
				ZVAL_COPY(&filter, _0$$4);
				_1$$5 = Z_TYPE_P(value) == IS_ARRAY;
				if (_1$$5) {
					_1$$5 = !noRecursive;
				}
				if (_1$$5) {
					ZEPHIR_INIT_NVAR(&arrayValue);
					array_init(&arrayValue);
					zephir_is_iterable(value, 0, "phalcon/filter.zep", 107);
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(value), _3$$6, _4$$6, _2$$6)
					{
						ZEPHIR_INIT_NVAR(&itemKey);
						if (_4$$6 != NULL) { 
							ZVAL_STR_COPY(&itemKey, _4$$6);
						} else {
							ZVAL_LONG(&itemKey, _3$$6);
						}
						ZEPHIR_INIT_NVAR(&itemValue);
						ZVAL_COPY(&itemValue, _2$$6);
						ZEPHIR_CALL_METHOD(&_5$$7, this_ptr, "_sanitize", &_6, 0, &itemValue, &filter);
						zephir_check_call_status();
						zephir_array_update_zval(&arrayValue, &itemKey, &_5$$7, PH_COPY | PH_SEPARATE);
					} ZEND_HASH_FOREACH_END();
					ZEPHIR_INIT_NVAR(&itemValue);
					ZEPHIR_INIT_NVAR(&itemKey);
					ZEPHIR_CPY_WRT(value, &arrayValue);
				} else {
					ZEPHIR_CALL_METHOD(&_7$$8, this_ptr, "_sanitize", &_6, 0, value, &filter);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(value, &_7$$8);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&filter);
		}
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	_8 = Z_TYPE_P(value) == IS_ARRAY;
	if (_8) {
		_8 = !noRecursive;
	}
	if (_8) {
		ZEPHIR_INIT_VAR(&sanitizedValue);
		array_init(&sanitizedValue);
		zephir_is_iterable(value, 0, "phalcon/filter.zep", 124);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(value), _10$$9, _11$$9, _9$$9)
		{
			ZEPHIR_INIT_NVAR(&itemKey);
			if (_11$$9 != NULL) { 
				ZVAL_STR_COPY(&itemKey, _11$$9);
			} else {
				ZVAL_LONG(&itemKey, _10$$9);
			}
			ZEPHIR_INIT_NVAR(&itemValue);
			ZVAL_COPY(&itemValue, _9$$9);
			ZEPHIR_CALL_METHOD(&_12$$10, this_ptr, "_sanitize", &_6, 0, &itemValue, filters);
			zephir_check_call_status();
			zephir_array_update_zval(&sanitizedValue, &itemKey, &_12$$10, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&itemValue);
		ZEPHIR_INIT_NVAR(&itemKey);
		RETURN_CCTOR(&sanitizedValue);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_sanitize", &_6, 0, value, filters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Internal sanitize wrapper to filter_var
 */
PHP_METHOD(Phalcon_Filter, _sanitize) {

	zval _3$$4, _10$$10;
	zend_bool _1$$3, _2$$3;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filter, _17$$21;
	zval *value, value_sub, *filter_param = NULL, filterObject, _0, _4$$5, _5$$5, _7$$6, _8$$8, _9$$9, _11$$10, _12$$12, _13$$12, _14$$19, _15$$20, _16$$21;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&filterObject);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_14$$19);
	ZVAL_UNDEF(&_15$$20);
	ZVAL_UNDEF(&_16$$21);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&_17$$21);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_10$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &value, &filter_param);

	if (UNEXPECTED(Z_TYPE_P(filter_param) != IS_STRING && Z_TYPE_P(filter_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filter' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(filter_param) == IS_STRING)) {
		zephir_get_strval(&filter, filter_param);
	} else {
		ZEPHIR_INIT_VAR(&filter);
		ZVAL_EMPTY_STRING(&filter);
	}


	ZEPHIR_OBS_VAR(&filterObject);
	zephir_read_property(&_0, this_ptr, SL("_filters"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&filterObject, &_0, &filter, 0 TSRMLS_CC)) {
		_1$$3 = Z_TYPE_P(&filterObject) == IS_OBJECT;
		if (_1$$3) {
			_1$$3 = zephir_instance_of_ev(&filterObject, zend_ce_closure TSRMLS_CC);
		}
		_2$$3 = _1$$3;
		if (!(_2$$3)) {
			_2$$3 = zephir_is_callable(&filterObject TSRMLS_CC);
		}
		if (_2$$3) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_create_array(&_3$$4, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&_3$$4, value);
			ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &filterObject, &_3$$4);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_RETURN_CALL_METHOD(&filterObject, "filter", NULL, 0, value);
		zephir_check_call_status();
		RETURN_MM();
	}
	do {
		if (ZEPHIR_IS_STRING(&filter, "email")) {
			ZEPHIR_INIT_VAR(&_4$$5);
			ZVAL_STRING(&_4$$5, "FILTER_SANITIZE_EMAIL");
			ZEPHIR_CALL_FUNCTION(&_5$$5, "constant", NULL, 188, &_4$$5);
			zephir_check_call_status();
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", &_6, 189, value, &_5$$5);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "int")) {
			ZVAL_LONG(&_7$$6, 519);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", &_6, 189, value, &_7$$6);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "int!")) {
			RETURN_MM_LONG(zephir_get_intval(value));
		}
		if (ZEPHIR_IS_STRING(&filter, "absint")) {
			ZVAL_LONG(&_8$$8, zephir_get_intval(value));
			ZEPHIR_RETURN_CALL_FUNCTION("abs", NULL, 190, &_8$$8);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "string")) {
			ZVAL_LONG(&_9$$9, 513);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", &_6, 189, value, &_9$$9);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "float")) {
			ZEPHIR_INIT_VAR(&_10$$10);
			zephir_create_array(&_10$$10, 1, 0 TSRMLS_CC);
			add_assoc_long_ex(&_10$$10, SL("flags"), 4096);
			ZVAL_LONG(&_11$$10, 520);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", &_6, 189, value, &_11$$10, &_10$$10);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "float!")) {
			RETURN_MM_DOUBLE(zephir_get_doubleval(value));
		}
		if (ZEPHIR_IS_STRING(&filter, "alphanum")) {
			ZEPHIR_INIT_VAR(&_12$$12);
			ZVAL_STRING(&_12$$12, "/[^A-Za-z0-9]/");
			ZEPHIR_INIT_VAR(&_13$$12);
			ZVAL_STRING(&_13$$12, "");
			ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 34, &_12$$12, &_13$$12, value);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "trim")) {
			zephir_fast_trim(return_value, value, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "striptags")) {
			ZEPHIR_RETURN_CALL_FUNCTION("strip_tags", NULL, 191, value);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "lower")) {
			if ((zephir_function_exists_ex(SL("mb_strtolower") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_RETURN_CALL_FUNCTION("mb_strtolower", NULL, 192, value);
				zephir_check_call_status();
				RETURN_MM();
			}
			zephir_fast_strtolower(return_value, value);
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "upper")) {
			if ((zephir_function_exists_ex(SL("mb_strtoupper") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_RETURN_CALL_FUNCTION("mb_strtoupper", NULL, 193, value);
				zephir_check_call_status();
				RETURN_MM();
			}
			zephir_fast_strtoupper(return_value, value);
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "url")) {
			ZVAL_LONG(&_14$$19, 518);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", &_6, 189, value, &_14$$19);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "special_chars")) {
			ZVAL_LONG(&_15$$20, 515);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", &_6, 189, value, &_15$$20);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&_16$$21);
		object_init_ex(&_16$$21, phalcon_filter_exception_ce);
		ZEPHIR_INIT_VAR(&_17$$21);
		ZEPHIR_CONCAT_SVS(&_17$$21, "Sanitize filter '", &filter, "' is not supported");
		ZEPHIR_CALL_METHOD(NULL, &_16$$21, "__construct", NULL, 4, &_17$$21);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_16$$21, "phalcon/filter.zep", 226 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

/**
 * Return the user-defined filters in the instance
 */
PHP_METHOD(Phalcon_Filter, getFilters) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_filters");

}

