
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "ext/spl/spl_array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * This class is a bag to manage the response headers
 *
 * @phpstan-import-type http_response_headers from HttpTypes
 *
 * @implements IteratorAggregate<string, string|null>
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Response_Headers)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Response, Headers, phalcon, http_response_headers, phalcon_http_response_headers_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_http_response_headers_ce, SL("headers"), ZEND_ACC_PROTECTED);
	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_http_response_headers_ce, SL("isSent"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	phalcon_http_response_headers_ce->create_object = zephir_init_properties_Phalcon_Http_Response_Headers;

	zend_class_implements(phalcon_http_response_headers_ce, 1, phalcon_http_response_headersinterface_ce);
	zend_class_implements(phalcon_http_response_headers_ce, 1, zend_ce_aggregate);
	return SUCCESS;
}

/**
 * Gets a header value from the internal bag
 *
 * @return bool|string|null
 * @todo change the raw headers not to return null
 */
PHP_METHOD(Phalcon_Http_Response_Headers, get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name_zv, headers, headerValue, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&headerValue);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("headers", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 915, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&headers, &_0);
	zephir_memory_observe(&headerValue);
	if (!(zephir_array_isset_fetch(&headerValue, &headers, &name_zv, 0))) {
		RETURN_MM_BOOL(0);
	}
	RETURN_CCTOR(&headerValue);
}

/**
 * @return Traversable<string, string|null>
 */
PHP_METHOD(Phalcon_Http_Response_Headers, getIterator)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("headers", 7, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, spl_ce_ArrayIterator);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 915, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 19, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Checks if a header exists
 */
PHP_METHOD(Phalcon_Http_Response_Headers, has)
{
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("headers", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 915, PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_key_exists(&_0, &name_zv));
}

/**
 * Returns if the headers have already been sent
 */
PHP_METHOD(Phalcon_Http_Response_Headers, isSent)
{

	RETURN_MEMBER(getThis(), "isSent");
}

/**
 * Removes a header by its name
 */
PHP_METHOD(Phalcon_Http_Response_Headers, remove)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval header_zv, headers, _0;
	zend_string *header = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&header_zv);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("headers", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(header)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&header_zv);
	ZVAL_STR_COPY(&header_zv, header);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 915, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&headers, &_0);
	zephir_array_unset(&headers, &header_zv, PH_SEPARATE);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 915, &headers);
	RETURN_THIS();
}

/**
 * Reset set headers
 */
PHP_METHOD(Phalcon_Http_Response_Headers, reset)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("headers", 7, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 915, &_0);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sends the headers to the client
 */
PHP_METHOD(Phalcon_Http_Response_Headers, send)
{
	zend_string *_8;
	zend_ulong _7;
	zend_bool _1, _17, _11$$6, _19$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL;
	zval __$true, __$false, header, value, _0, _2, _3, *_4, _5, *_6, _16, _9$$5, _12$$6, _13$$6, _14$$6, _15$$8, _18$$10, _20$$11, _21$$11, _22$$11, _23$$13;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_23$$13);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("isSent", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("headers", 7, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", NULL, 225);
	zephir_check_call_status();
	_1 = ZEPHIR_IS_TRUE_IDENTICAL(&_0);
	if (!(_1)) {
		zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 916, PH_NOISY_CC | PH_READONLY);
		_1 = ZEPHIR_IS_TRUE_IDENTICAL(&_2);
	}
	if (_1) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 915, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_3) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_5);
		zephir_string_to_char_array(&_5, &_3);
		_4 = &_5;
	} else {
		_4 = &_3;
	}
	zephir_is_iterable(_4, 0, "phalcon/Http/Response/Headers.zep", 120);
	if (Z_TYPE_P(_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_4), _7, _8, _6)
		{
			ZEPHIR_INIT_NVAR(&header);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&header, _8);
			} else {
				ZVAL_LONG(&header, _7);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _6);
			if (Z_TYPE_P(&value) != IS_NULL) {
				ZEPHIR_INIT_NVAR(&_9$$5);
				ZEPHIR_CONCAT_VSV(&_9$$5, &header, ": ", &value);
				ZEPHIR_CALL_FUNCTION(NULL, "header", &_10, 227, &_9$$5, &__$true);
				zephir_check_call_status();
			} else {
				_11$$6 = zephir_memnstr_str(&header, SL(":"), "phalcon/Http/Response/Headers.zep", 112);
				if (!(_11$$6)) {
					ZVAL_LONG(&_12$$6, 0);
					ZVAL_LONG(&_13$$6, 5);
					ZEPHIR_INIT_NVAR(&_14$$6);
					zephir_substr(&_14$$6, &header, 0 , 5 , 0);
					_11$$6 = ZEPHIR_IS_STRING(&_14$$6, "HTTP/");
				}
				if (_11$$6) {
					ZEPHIR_CALL_FUNCTION(NULL, "header", &_10, 227, &header, &__$true);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&_15$$8);
					ZEPHIR_CONCAT_VS(&_15$$8, &header, ": ");
					ZEPHIR_CALL_FUNCTION(NULL, "header", &_10, 227, &_15$$8, &__$true);
					zephir_check_call_status();
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _4, "rewind", NULL, 0);
		zephir_check_call_status();
		_17 = 1;
		while (1) {
			if (_17) {
				_17 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _4, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_16, _4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_16)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&header, _4, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, _4, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&value) != IS_NULL) {
					ZEPHIR_INIT_NVAR(&_18$$10);
					ZEPHIR_CONCAT_VSV(&_18$$10, &header, ": ", &value);
					ZEPHIR_CALL_FUNCTION(NULL, "header", &_10, 227, &_18$$10, &__$true);
					zephir_check_call_status();
				} else {
					_19$$11 = zephir_memnstr_str(&header, SL(":"), "phalcon/Http/Response/Headers.zep", 112);
					if (!(_19$$11)) {
						ZVAL_LONG(&_20$$11, 0);
						ZVAL_LONG(&_21$$11, 5);
						ZEPHIR_INIT_NVAR(&_22$$11);
						zephir_substr(&_22$$11, &header, 0 , 5 , 0);
						_19$$11 = ZEPHIR_IS_STRING(&_22$$11, "HTTP/");
					}
					if (_19$$11) {
						ZEPHIR_CALL_FUNCTION(NULL, "header", &_10, 227, &header, &__$true);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(&_23$$13);
						ZEPHIR_CONCAT_VS(&_23$$13, &header, ": ");
						ZEPHIR_CALL_FUNCTION(NULL, "header", &_10, 227, &_23$$13, &__$true);
						zephir_check_call_status();
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&header);
	if (1) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 916, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 916, &__$false);
	}
	RETURN_MM_BOOL(1);
}

/**
 * Sets a header to be sent at the end of the request
 */
PHP_METHOD(Phalcon_Http_Response_Headers, set)
{
	zval name_zv, value_zv;
	zend_string *name = NULL, *value = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&value_zv);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_STR(value)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	ZVAL_STR(&value_zv, value);
	zephir_update_property_array(this_ptr, SL("headers"), &name_zv, &value_zv);
	RETURN_THISW();
}

/**
 * Sets a raw header to be sent at the end of the request
 */
PHP_METHOD(Phalcon_Http_Response_Headers, setRaw)
{
	zval header_zv, __$null;
	zend_string *header = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&header_zv);
	ZVAL_NULL(&__$null);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(header)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&header_zv, header);
	zephir_update_property_array(this_ptr, SL("headers"), &header_zv, &__$null);
	RETURN_THISW();
}

/**
 * Returns the current headers as an array
 *
 * @phpstan-return http_response_headers
 */
PHP_METHOD(Phalcon_Http_Response_Headers, toArray)
{

	RETURN_MEMBER_TYPED(getThis(), "headers", IS_ARRAY);
}

zend_object *zephir_init_properties_Phalcon_Http_Response_Headers(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("headers"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

