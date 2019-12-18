
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
ZEPHIR_INIT_CLASS(Phalcon_Http_Response_Headers) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Response, Headers, phalcon, http_response_headers, phalcon_http_response_headers_method_entry, 0);

	zend_declare_property_null(phalcon_http_response_headers_ce, SL("headers"), ZEND_ACC_PROTECTED);

	phalcon_http_response_headers_ce->create_object = zephir_init_properties_Phalcon_Http_Response_Headers;

	zend_class_implements(phalcon_http_response_headers_ce, 1, phalcon_http_response_headersinterface_ce);
	return SUCCESS;

}

/**
 * Gets a header value from the internal bag
 */
PHP_METHOD(Phalcon_Http_Response_Headers, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, headers, headerValue, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&headerValue);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&headers, &_0);
	if (!(zephir_array_isset_fetch(&headerValue, &headers, &name, 1))) {
		RETURN_MM_BOOL(0);
	}
	RETURN_CTOR(&headerValue);

}

/**
 * Sets a header to be sent at the end of the request
 */
PHP_METHOD(Phalcon_Http_Response_Headers, has) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &name));

}

/**
 * Removes a header to be sent at the end of the request
 */
PHP_METHOD(Phalcon_Http_Response_Headers, remove) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *header_param = NULL, headers, _0;
	zval header;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &header_param);

	zephir_get_strval(&header, header_param);


	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&headers, &_0);
	zephir_array_unset(&headers, &header, PH_SEPARATE);
	zephir_update_property_zval(this_ptr, SL("headers"), &headers);
	RETURN_THIS();

}

/**
 * Reset set headers
 */
PHP_METHOD(Phalcon_Http_Response_Headers, reset) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("headers"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends the headers to the client
 */
PHP_METHOD(Phalcon_Http_Response_Headers, send) {

	zend_bool _8$$6, _14$$11;
	zend_string *_5;
	zend_ulong _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zval __$true, header, value, _0, _1, *_2, _3, _6$$5, _9$$6, _10$$6, _11$$6, _12$$8, _13$$10, _15$$11, _16$$11, _17$$11, _18$$13;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$13);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", NULL, 360);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_1, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_1, 0, "phalcon/Http/Response/Headers.zep", 100);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_1), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&header);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&header, _5);
			} else {
				ZVAL_LONG(&header, _4);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _2);
			if (Z_TYPE_P(&value) != IS_NULL) {
				ZEPHIR_INIT_NVAR(&_6$$5);
				ZEPHIR_CONCAT_VSV(&_6$$5, &header, ": ", &value);
				ZEPHIR_CALL_FUNCTION(NULL, "header", &_7, 361, &_6$$5, &__$true);
				zephir_check_call_status();
			} else {
				_8$$6 = zephir_memnstr_str(&header, SL(":"), "phalcon/Http/Response/Headers.zep", 86);
				if (!(_8$$6)) {
					ZVAL_LONG(&_9$$6, 0);
					ZVAL_LONG(&_10$$6, 5);
					ZEPHIR_INIT_NVAR(&_11$$6);
					zephir_substr(&_11$$6, &header, 0 , 5 , 0);
					_8$$6 = ZEPHIR_IS_STRING(&_11$$6, "HTTP/");
				}
				if (_8$$6) {
					ZEPHIR_CALL_FUNCTION(NULL, "header", &_7, 361, &header, &__$true);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&_12$$8);
					ZEPHIR_CONCAT_VS(&_12$$8, &header, ": ");
					ZEPHIR_CALL_FUNCTION(NULL, "header", &_7, 361, &_12$$8, &__$true);
					zephir_check_call_status();
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_1, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &_1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&header, &_1, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &_1, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&value) != IS_NULL) {
					ZEPHIR_INIT_NVAR(&_13$$10);
					ZEPHIR_CONCAT_VSV(&_13$$10, &header, ": ", &value);
					ZEPHIR_CALL_FUNCTION(NULL, "header", &_7, 361, &_13$$10, &__$true);
					zephir_check_call_status();
				} else {
					_14$$11 = zephir_memnstr_str(&header, SL(":"), "phalcon/Http/Response/Headers.zep", 86);
					if (!(_14$$11)) {
						ZVAL_LONG(&_15$$11, 0);
						ZVAL_LONG(&_16$$11, 5);
						ZEPHIR_INIT_NVAR(&_17$$11);
						zephir_substr(&_17$$11, &header, 0 , 5 , 0);
						_14$$11 = ZEPHIR_IS_STRING(&_17$$11, "HTTP/");
					}
					if (_14$$11) {
						ZEPHIR_CALL_FUNCTION(NULL, "header", &_7, 361, &header, &__$true);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(&_18$$13);
						ZEPHIR_CONCAT_VS(&_18$$13, &header, ": ");
						ZEPHIR_CALL_FUNCTION(NULL, "header", &_7, 361, &_18$$13, &__$true);
						zephir_check_call_status();
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &_1, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&header);
	RETURN_MM_BOOL(1);

}

/**
 * Sets a header to be sent at the end of the request
 */
PHP_METHOD(Phalcon_Http_Response_Headers, set) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, *value_param = NULL;
	zval name, value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);

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
PHP_METHOD(Phalcon_Http_Response_Headers, setRaw) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *header_param = NULL, __$null;
	zval header;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&header);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &header_param);

	zephir_get_strval(&header, header_param);


	zephir_update_property_array(this_ptr, SL("headers"), &header, &__$null);
	RETURN_THIS();

}

/**
 * Returns the current headers as an array
 */
PHP_METHOD(Phalcon_Http_Response_Headers, toArray) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "headers");

}

zend_object *zephir_init_properties_Phalcon_Http_Response_Headers(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("headers"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

