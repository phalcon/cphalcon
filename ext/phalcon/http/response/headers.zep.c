
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * Phalcon\Http\Response\Headers
 *
 * This class is a bag to manage the response headers
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Response_Headers) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Response, Headers, phalcon, http_response_headers, phalcon_http_response_headers_method_entry, 0);

	zend_declare_property_null(phalcon_http_response_headers_ce, SL("_headers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_http_response_headers_ce->create_object = zephir_init_properties_Phalcon_Http_Response_Headers;

	zend_class_implements(phalcon_http_response_headers_ce TSRMLS_CC, 1, phalcon_http_response_headersinterface_ce);
	return SUCCESS;

}

/**
 * Sets a header to be sent at the end of the request
 */
PHP_METHOD(Phalcon_Http_Response_Headers, set) {

	zval *name_param = NULL, *value_param = NULL;
	zval *name = NULL, *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value_param);

	zephir_get_strval(name, name_param);
	zephir_get_strval(value, value_param);


	zephir_update_property_array(this_ptr, SL("_headers"), name, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets a header value from the internal bag
 */
PHP_METHOD(Phalcon_Http_Response_Headers, get) {

	zval *name_param = NULL, *headers = NULL, *headerValue = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	headers = zephir_fetch_nproperty_this(this_ptr, SL("_headers"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&headerValue, headers, name, 1 TSRMLS_CC)) {
		RETURN_CTOR(headerValue);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Sets a raw header to be sent at the end of the request
 */
PHP_METHOD(Phalcon_Http_Response_Headers, setRaw) {

	zval *header_param = NULL;
	zval *header = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &header_param);

	zephir_get_strval(header, header_param);


	zephir_update_property_array(this_ptr, SL("_headers"), header, ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Removes a header to be sent at the end of the request
 */
PHP_METHOD(Phalcon_Http_Response_Headers, remove) {

	zval *header_param = NULL, *headers = NULL;
	zval *header = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &header_param);

	zephir_get_strval(header, header_param);


	ZEPHIR_OBS_VAR(headers);
	zephir_read_property_this(&headers, this_ptr, SL("_headers"), PH_NOISY_CC);
	zephir_array_unset(&headers, header, PH_SEPARATE);
	zephir_update_property_this(getThis(), SL("_headers"), headers TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends the headers to the client
 */
PHP_METHOD(Phalcon_Http_Response_Headers, send) {

	zend_bool _7$$6;
	HashTable *_3$$3;
	HashPosition _2$$3;
	zval *header = NULL, *value = NULL, *_0 = NULL, *_1$$3, **_4$$3, *_5$$5 = NULL, _8$$6 = zval_used_for_init, _9$$6 = zval_used_for_init, *_10$$6 = NULL, *_11$$8 = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", NULL, 28);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_headers"), PH_NOISY_CC);
		zephir_is_iterable(_1$$3, &_3$$3, &_2$$3, 0, 0, "phalcon/http/response/headers.zep", 94);
		for (
		  ; zend_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_3$$3, &_2$$3)
		) {
			ZEPHIR_GET_HMKEY(header, _3$$3, _2$$3);
			ZEPHIR_GET_HVALUE(value, _4$$3);
			if (Z_TYPE_P(value) != IS_NULL) {
				ZEPHIR_INIT_LNVAR(_5$$5);
				ZEPHIR_CONCAT_VSV(_5$$5, header, ": ", value);
				ZEPHIR_CALL_FUNCTION(NULL, "header", &_6, 262, _5$$5, ZEPHIR_GLOBAL(global_true));
				zephir_check_call_status();
			} else {
				_7$$6 = zephir_memnstr_str(header, SL(":"), "phalcon/http/response/headers.zep", 87);
				if (!(_7$$6)) {
					ZEPHIR_SINIT_NVAR(_8$$6);
					ZVAL_LONG(&_8$$6, 0);
					ZEPHIR_SINIT_NVAR(_9$$6);
					ZVAL_LONG(&_9$$6, 5);
					ZEPHIR_INIT_NVAR(_10$$6);
					zephir_substr(_10$$6, header, 0 , 5 , 0);
					_7$$6 = ZEPHIR_IS_STRING(_10$$6, "HTTP/");
				}
				if (_7$$6) {
					ZEPHIR_CALL_FUNCTION(NULL, "header", &_6, 262, header, ZEPHIR_GLOBAL(global_true));
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_LNVAR(_11$$8);
					ZEPHIR_CONCAT_VS(_11$$8, header, ": ");
					ZEPHIR_CALL_FUNCTION(NULL, "header", &_6, 262, _11$$8, ZEPHIR_GLOBAL(global_true));
					zephir_check_call_status();
				}
			}
		}
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Reset set headers
 */
PHP_METHOD(Phalcon_Http_Response_Headers, reset) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(getThis(), SL("_headers"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the current headers as an array
 */
PHP_METHOD(Phalcon_Http_Response_Headers, toArray) {

	

	RETURN_MEMBER(getThis(), "_headers");

}

/**
 * Restore a \Phalcon\Http\Response\Headers object
 */
PHP_METHOD(Phalcon_Http_Response_Headers, __set_state) {

	HashTable *_1$$3;
	HashPosition _0$$3;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *headers = NULL, *key = NULL, *value = NULL, *dataHeaders = NULL, **_2$$3;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	data = data_param;


	ZEPHIR_INIT_VAR(headers);
	object_init_ex(headers, phalcon_http_response_headers_ce);
	if (zephir_has_constructor(headers TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, headers, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(dataHeaders);
	if (zephir_array_isset_string_fetch(&dataHeaders, data, SS("_headers"), 0 TSRMLS_CC)) {
		zephir_is_iterable(dataHeaders, &_1$$3, &_0$$3, 0, 0, "phalcon/http/response/headers.zep", 126);
		for (
		  ; zend_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HMKEY(key, _1$$3, _0$$3);
			ZEPHIR_GET_HVALUE(value, _2$$3);
			ZEPHIR_CALL_METHOD(NULL, headers, "set", &_3, 263, key, value);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(headers);

}

zend_object_value zephir_init_properties_Phalcon_Http_Response_Headers(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_headers"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("_headers"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

