
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Http\Response\Headers
 *
 * This class is a bag to manage the response headers
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Response_Headers)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Response, Headers, phalcon, http_response_headers, phalcon_http_response_headers_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_http_response_headers_ce, SL("headers"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_http_response_headers_ce, SL("isSent"), 0, ZEND_ACC_PROTECTED);
	phalcon_http_response_headers_ce->create_object = zephir_init_properties_Phalcon_Http_Response_Headers;

	zend_class_implements(phalcon_http_response_headers_ce, 1, phalcon_http_response_headersinterface_ce);
	return SUCCESS;
}

/**
 * Gets a header value from the internal bag
 */
PHP_METHOD(Phalcon_Http_Response_Headers, get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, headers, headerValue, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&headerValue);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&headers, &_0);
	if (!(zephir_array_isset_fetch(&headerValue, &headers, &name, 1))) {
		RETURN_MM_BOOL(0);
	}
	RETURN_CTOR(&headerValue);
}

/**
 * Checks if a header exists
 */
PHP_METHOD(Phalcon_Http_Response_Headers, has)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &name));
}

/**
 * Returns if the headers have already been sent
 */
PHP_METHOD(Phalcon_Http_Response_Headers, isSent)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "isSent");
}

/**
 * Removes a header by its name
 */
PHP_METHOD(Phalcon_Http_Response_Headers, remove)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *header_param = NULL, headers, _0;
	zval header;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(header)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &header_param);
	zephir_get_strval(&header, header_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&headers, &_0);
	zephir_array_unset(&headers, &header, PH_SEPARATE);
	zephir_update_property_zval(this_ptr, ZEND_STRL("headers"), &headers);
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


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("headers"), &_0);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sends the headers to the client
 */
PHP_METHOD(Phalcon_Http_Response_Headers, send)
{
	zend_string *_7;
	zend_ulong _6;
	zend_bool _1, _10$$6, _16$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zval __$true, __$false, header, value, _0, _2, _3, *_4, _5, _8$$5, _11$$6, _12$$6, _13$$6, _14$$8, _15$$10, _17$$11, _18$$11, _19$$11, _20$$13;
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
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_20$$13);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", NULL, 363);
	zephir_check_call_status();
	_1 = ZEPHIR_IS_TRUE_IDENTICAL(&_0);
	if (!(_1)) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "issent", NULL, 0);
		zephir_check_call_status();
		_1 = ZEPHIR_IS_TRUE_IDENTICAL(&_2);
	}
	if (_1) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_3, 0, "phalcon/Http/Response/Headers.zep", 116);
	if (Z_TYPE_P(&_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_3), _6, _7, _4)
		{
			ZEPHIR_INIT_NVAR(&header);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&header, _7);
			} else {
				ZVAL_LONG(&header, _6);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _4);
			if (Z_TYPE_P(&value) != IS_NULL) {
				ZEPHIR_INIT_NVAR(&_8$$5);
				ZEPHIR_CONCAT_VSV(&_8$$5, &header, ": ", &value);
				ZEPHIR_CALL_FUNCTION(NULL, "header", &_9, 364, &_8$$5, &__$true);
				zephir_check_call_status();
			} else {
				_10$$6 = zephir_memnstr_str(&header, SL(":"), "phalcon/Http/Response/Headers.zep", 102);
				if (!(_10$$6)) {
					ZVAL_LONG(&_11$$6, 0);
					ZVAL_LONG(&_12$$6, 5);
					ZEPHIR_INIT_NVAR(&_13$$6);
					zephir_substr(&_13$$6, &header, 0 , 5 , 0);
					_10$$6 = ZEPHIR_IS_STRING(&_13$$6, "HTTP/");
				}
				if (_10$$6) {
					ZEPHIR_CALL_FUNCTION(NULL, "header", &_9, 364, &header, &__$true);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&_14$$8);
					ZEPHIR_CONCAT_VS(&_14$$8, &header, ": ");
					ZEPHIR_CALL_FUNCTION(NULL, "header", &_9, 364, &_14$$8, &__$true);
					zephir_check_call_status();
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_3, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &_3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&header, &_3, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &_3, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&value) != IS_NULL) {
					ZEPHIR_INIT_NVAR(&_15$$10);
					ZEPHIR_CONCAT_VSV(&_15$$10, &header, ": ", &value);
					ZEPHIR_CALL_FUNCTION(NULL, "header", &_9, 364, &_15$$10, &__$true);
					zephir_check_call_status();
				} else {
					_16$$11 = zephir_memnstr_str(&header, SL(":"), "phalcon/Http/Response/Headers.zep", 102);
					if (!(_16$$11)) {
						ZVAL_LONG(&_17$$11, 0);
						ZVAL_LONG(&_18$$11, 5);
						ZEPHIR_INIT_NVAR(&_19$$11);
						zephir_substr(&_19$$11, &header, 0 , 5 , 0);
						_16$$11 = ZEPHIR_IS_STRING(&_19$$11, "HTTP/");
					}
					if (_16$$11) {
						ZEPHIR_CALL_FUNCTION(NULL, "header", &_9, 364, &header, &__$true);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(&_20$$13);
						ZEPHIR_CONCAT_VS(&_20$$13, &header, ": ");
						ZEPHIR_CALL_FUNCTION(NULL, "header", &_9, 364, &_20$$13, &__$true);
						zephir_check_call_status();
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &_3, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&header);
	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("isSent"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("isSent"), &__$false);
	}
	RETURN_MM_BOOL(1);
}

/**
 * Sets a header to be sent at the end of the request
 */
PHP_METHOD(Phalcon_Http_Response_Headers, set)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, *value_param = NULL;
	zval name, value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_STR(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value_param);
	zephir_get_strval(&name, name_param);
	zephir_get_strval(&value, value_param);


	zephir_update_property_array(this_ptr, SL("headers"), &name, &value);
	RETURN_THIS();
}

/**
 * Sets a raw header to be sent at the end of the request
 */
PHP_METHOD(Phalcon_Http_Response_Headers, setRaw)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *header_param = NULL, __$null;
	zval header;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&header);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(header)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &header_param);
	zephir_get_strval(&header, header_param);


	zephir_update_property_array(this_ptr, SL("headers"), &header, &__$null);
	RETURN_THIS();
}

/**
 * Returns the current headers as an array
 */
PHP_METHOD(Phalcon_Http_Response_Headers, toArray)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "headers");
}

zend_object *zephir_init_properties_Phalcon_Http_Response_Headers(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
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

