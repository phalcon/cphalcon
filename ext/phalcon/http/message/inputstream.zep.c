
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
#include "kernel/fcall.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Describes a data stream.
 *
 * Typically, an instance will wrap a PHP stream; this interface provides
 * a wrapper around the most common operations, including serialization of
 * the entire stream to a string.
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_InputStream) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Http\\Message, InputStream, phalcon, http_message_inputstream, phalcon_http_message_stream_ce, phalcon_http_message_inputstream_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_message_inputstream_ce, SL("data"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_http_message_inputstream_ce, SL("eof"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

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
 * @return string
 */
PHP_METHOD(Phalcon_Http_Message_InputStream, __toString) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("eof"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		RETURN_MM_MEMBER(getThis(), "data");
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "getcontents", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_MEMBER(getThis(), "data");

}

/**
 * Returns the remaining contents in a string
 *
 * @return string
 * @throws \RuntimeException if unable to read.
 * @throws \RuntimeException if error occurs while reading.
 */
PHP_METHOD(Phalcon_Http_Message_InputStream, getContents) {

	zend_bool _3;
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


	zephir_read_property(&_0, this_ptr, SL("eof"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		RETURN_CCTOR(&data);
	}
	zephir_read_property(&_1, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, length);
	ZEPHIR_CALL_FUNCTION(&data, "stream_get_contents", NULL, 216, &_1, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("data"), &data);
	_3 = -1 == length;
	if (!(_3)) {
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "eof", NULL, 0);
		zephir_check_call_status();
		_3 = zephir_is_true(&_4);
	}
	if (_3) {
		if (1) {
			zephir_update_property_zval(this_ptr, SL("eof"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("eof"), &__$false);
		}
	}
	RETURN_CCTOR(&data);

}

/**
 * Returns whether or not the stream is writable.
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Http_Message_InputStream, isWritable) {

	zval *this_ptr = getThis();


	RETURN_BOOL(0);

}

/**
 * Read data from the stream.
 *
 * @param int $length Read up to $length bytes from the object and return
 *     them. Fewer than $length bytes may be returned if underlying stream
 *     call returns fewer bytes.
 * @return string Returns the data read from the stream, or an empty string
 *     if no bytes are available.
 * @throws \RuntimeException if an error occurs.
 */
PHP_METHOD(Phalcon_Http_Message_InputStream, read) {

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



	ZEPHIR_CALL_PARENT(&data, phalcon_http_message_inputstream_ce, getThis(), "read", &_0, 0, length);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("eof"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_1)) {
		zephir_update_property_zval(this_ptr, SL("data"), &data);
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "eof", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_2)) {
		if (1) {
			zephir_update_property_zval(this_ptr, SL("eof"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("eof"), &__$false);
		}
	}
	RETURN_CCTOR(&data);

}

