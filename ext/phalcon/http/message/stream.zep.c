
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
#include "kernel/file.h"
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
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_Stream) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Message, Stream, phalcon, http_message_stream, phalcon_http_message_stream_method_entry, 0);

	/**
	 * @var resource
	 */
	zend_declare_property_null(phalcon_http_message_stream_ce, SL("handle"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var resource | string
	 */
	zend_declare_property_null(phalcon_http_message_stream_ce, SL("stream"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_http_message_stream_ce, SL("metadata"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_http_message_stream_ce->create_object = zephir_init_properties_Phalcon_Http_Message_Stream;

	zend_class_implements(phalcon_http_message_stream_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("psr\\http\\message\\streaminterface")));
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
 */
PHP_METHOD(Phalcon_Http_Message_Stream, __toString) {

	zval *this_ptr = getThis();



}

/**
 * Closes the stream and any underlying resources.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, close) {

	zval handle, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handle);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&handle, this_ptr, "detach", NULL, 0);
		zephir_check_call_status();
		zephir_fclose(&handle TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Separates any underlying resources from the stream.
 *
 * After the stream has been detached, the stream is in an unusable state.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, detach) {

	zval __$null, handle, _0;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&handle);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&handle, &_0);
	zephir_update_property_zval(this_ptr, SL("handle"), &__$null);
	RETURN_CCTOR(&handle);

}

/**
 * Returns true if the stream is at the end of the stream.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, eof) {

	zval _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);


	zephir_read_property(&_0, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_1$$3, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
		RETURN_BOOL(zephir_feof(&_1$$3 TSRMLS_CC));
	}
	RETURN_BOOL(1);

}

/**
 * Returns the remaining contents in a string
 */
PHP_METHOD(Phalcon_Http_Message_Stream, getContents) {

	zval *this_ptr = getThis();



}

/**
 * Get stream metadata as an associative array or retrieve a specific key.
 *
 * The keys returned are identical to the keys returned from PHP's
 * stream_get_meta_data() function.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, getMetadata) {

	zval *key = NULL, key_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_NULL(&__$null);

	zephir_fetch_params(0, 0, 1, &key);

	if (!key) {
		key = &key_sub;
		key = &__$null;
	}



}

/**
 * Get the size of the stream if known.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, getSize) {

	zval stats, _0, _1$$3, _3$$4, _4$$4;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stats);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_1$$3, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&stats, "fstat", NULL, 69, &_1$$3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&stats)) {
			ZEPHIR_INIT_VAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "size");
			ZVAL_NULL(&_4$$4);
			ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_utility_ce, "arraygetdefault", &_2, 0, &_3$$4, &stats, &_4$$4);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	RETURN_MM_NULL();

}

/**
 * Returns whether or not the stream is readable.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, isReadable) {

	zval *this_ptr = getThis();



}

/**
 * Returns whether or not the stream is seekable.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, isSeekable) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "seekable");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmetadata", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("boolval", NULL, 70, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns whether or not the stream is writable.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, isWritable) {

	zval *this_ptr = getThis();



}

/**
 * Read data from the stream.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, read) {

	zval *length, length_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&length_sub);

	zephir_fetch_params(0, 1, 0, &length);




}

/**
 * Seek to the beginning of the stream.
 *
 * If the stream is not seekable, this method will raise an exception;
 * otherwise, it will perform a seek(0).
 */
PHP_METHOD(Phalcon_Http_Message_Stream, rewind) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Seek to a position in the stream.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, seek) {

	zval *offset, offset_sub, *whence = NULL, whence_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&whence_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &offset, &whence);

	if (!whence) {
		whence = &whence_sub;
		ZEPHIR_INIT_VAR(whence);
		ZVAL_LONG(whence, 0);
	}



}

/**
 * Returns the current position of the file read/write pointer
 */
PHP_METHOD(Phalcon_Http_Message_Stream, tell) {

	zval *this_ptr = getThis();



}

/**
 * Write data to the stream.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, write) {

	zval *data, data_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);

	zephir_fetch_params(0, 1, 0, &data);




}

zend_object *zephir_init_properties_Phalcon_Http_Message_Stream(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("metadata"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("metadata"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

