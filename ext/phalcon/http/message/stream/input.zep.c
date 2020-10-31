
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 */
/**
 * Describes a data stream from "php://input"
 *
 * Typically, an instance will wrap a PHP stream; this interface provides
 * a wrapper around the most common operations, including serialization of
 * the entire stream to a string.
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_Stream_Input) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Http\\Message\\Stream, Input, phalcon, http_message_stream_input, phalcon_http_message_stream_ce, phalcon_http_message_stream_input_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_message_stream_input_ce, SL("data"), "", ZEND_ACC_PRIVATE);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_http_message_stream_input_ce, SL("eof"), 0, ZEND_ACC_PRIVATE);

	return SUCCESS;

}

/**
 * Input constructor.
 */
PHP_METHOD(Phalcon_Http_Message_Stream_Input, __construct) {

	zval _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "php://input");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "rb");
	ZEPHIR_CALL_PARENT(NULL, phalcon_http_message_stream_input_ce, getThis(), "__construct", &_0, 0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Reads all data from the stream into a string, from the beginning to end.
 *
 * This method MUST attempt to seek to the beginning of the stream before
 * reading data and read the stream until the end is reached.
 *
 * Warning: This could attempt to load a large amount of data into memory.
 *
 * This method MUST NOT raise an exception in order to conform with PHP's
 * string casting operations.
 *
 * @see http://php.net/manual/en/language.oop5.magic.php#object.tostring
 */
PHP_METHOD(Phalcon_Http_Message_Stream_Input, __toString) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("eof"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(zephir_is_true(&_0))) {
		RETURN_MM_MEMBER(getThis(), "data");
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "getcontents", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_MEMBER(getThis(), "data");

}

/**
 * Returns the remaining contents in a string
 *
 * @throws RuntimeException if unable to read.
 * @throws RuntimeException if error occurs while reading.
 *
 * @param int $length
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Message_Stream_Input, getContents) {

	zend_bool _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *length_param = NULL, __$true, __$false, data, _0, _1, _2, _4;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &length_param);

	if (!length_param) {
		length = -1;
	} else {
		length = zephir_get_intval(length_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("eof"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(zephir_is_true(&_0))) {
		RETURN_MM_MEMBER(getThis(), "data");
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("handle"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, length);
	ZEPHIR_CALL_FUNCTION(&data, "stream_get_contents", NULL, 79, &_1, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &data);
	_3 = -1 == length;
	if (!(_3)) {
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "eof", NULL, 0);
		zephir_check_call_status();
		_3 = zephir_is_true(&_4);
	}
	if (UNEXPECTED(_3)) {
		if (1) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("eof"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("eof"), &__$false);
		}
	}
	RETURN_MM_MEMBER(getThis(), "data");

}

/**
 * Returns whether or not the stream is writeable.
 */
PHP_METHOD(Phalcon_Http_Message_Stream_Input, isWritable) {

	zval *this_ptr = getThis();


	RETURN_BOOL(0);

}

/**
 * Read data from the stream.
 *
 * @param int $length
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Message_Stream_Input, read) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *length, length_sub, __$true, __$false, data, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&length_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &length);



	ZEPHIR_CALL_PARENT(&data, phalcon_http_message_stream_input_ce, getThis(), "read", &_0, 0, length);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("eof"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_1))) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &data);
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "eof", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(zephir_is_true(&_2))) {
		if (1) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("eof"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("eof"), &__$false);
		}
	}
	RETURN_CCTOR(&data);

}

