
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/file.h"
#include "kernel/exception.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
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
	 * @var resource | null
	 */
	zend_declare_property_null(phalcon_http_message_stream_ce, SL("handle"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var resource | string
	 */
	zend_declare_property_null(phalcon_http_message_stream_ce, SL("stream"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_http_message_stream_ce, SL("warning"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_http_message_stream_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("psr\\http\\message\\streaminterface")));
	return SUCCESS;

}

/**
 * Constructor
 */
PHP_METHOD(Phalcon_Http_Message_Stream, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *stream, stream_sub, *mode = NULL, mode_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&mode_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &stream, &mode);

	if (!mode) {
		mode = &mode_sub;
		ZEPHIR_INIT_VAR(mode);
		ZVAL_STRING(mode, "rb");
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstream", NULL, 0, stream, mode);
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
PHP_METHOD(Phalcon_Http_Message_Stream, __toString) {

	zval _0$$3, _1$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();


	/* try_start_1: */

		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "isreadable", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_0$$3)) {
			ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "isseekable", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			if (ZEPHIR_IS_TRUE_IDENTICAL(&_1$$4)) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "rewind", NULL, 0);
				zephir_check_call_status_or_jump(try_end_1);
			}
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getcontents", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			RETURN_MM();
		}

	try_end_1:

	zend_clear_exception(TSRMLS_C);
	RETURN_MM_STRING("");

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
	if (Z_TYPE_P(&_0) != IS_NULL) {
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

	zval data, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkhandle", NULL, 48);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkreadable", NULL, 49);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&data, "stream_get_contents", NULL, 50, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&data)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_ce, "Could not read from the file/stream", "phalcon/Http/Message/Stream.zep", 135);
		return;
	}
	RETURN_CCTOR(&data);

}

/**
 * Get stream metadata as an associative array or retrieve a specific key.
 *
 * The keys returned are identical to the keys returned from PHP's
 * stream_get_meta_data() function.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, getMetadata) {

	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, key_sub, __$null, metadata, _0, _1, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&metadata);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &key);

	if (!key) {
		key = &key_sub;
		key = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_1, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&metadata, "stream_get_meta_data", NULL, 51, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(key) == IS_NULL) {
		RETURN_CCTOR(&metadata);
	}
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_helper_arr_ce, "get", &_2, 52, &metadata, key, &_3);
	zephir_check_call_status();
	RETURN_MM();

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
	if (Z_TYPE_P(&_0) != IS_NULL) {
		zephir_read_property(&_1$$3, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&stats, "fstat", NULL, 53, &_1$$3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&stats)) {
			ZEPHIR_INIT_VAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "size");
			ZVAL_NULL(&_4$$4);
			ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_helper_arr_ce, "get", &_2, 52, &stats, &_3$$4, &_4$$4);
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

	zend_bool _2;
	zval mode, _0, _1, _3, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "mode");
	ZEPHIR_CALL_METHOD(&mode, this_ptr, "getmetadata", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "r");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, &mode, &_0, 0 );
	_2 = !ZEPHIR_IS_FALSE_IDENTICAL(&_1);
	if (!(_2)) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_STRING(&_3, "+");
		ZEPHIR_INIT_VAR(&_4);
		zephir_fast_strpos(&_4, &mode, &_3, 0 );
		_2 = !ZEPHIR_IS_FALSE_IDENTICAL(&_4);
	}
	RETURN_MM_BOOL(_2);

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
	RETURN_MM_BOOL(zephir_get_boolval(&_0));

}

/**
 * Returns whether or not the stream is writable.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, isWritable) {

	zend_bool _2, _5, _8, _11;
	zval mode, _0, _1, _3, _4, _6, _7, _9, _10, _12, _13;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "mode");
	ZEPHIR_CALL_METHOD(&mode, this_ptr, "getmetadata", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "x");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, &mode, &_0, 0 );
	_2 = !ZEPHIR_IS_FALSE_IDENTICAL(&_1);
	if (!(_2)) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_STRING(&_3, "w");
		ZEPHIR_INIT_VAR(&_4);
		zephir_fast_strpos(&_4, &mode, &_3, 0 );
		_2 = !ZEPHIR_IS_FALSE_IDENTICAL(&_4);
	}
	_5 = _2;
	if (!(_5)) {
		ZEPHIR_INIT_VAR(&_6);
		ZVAL_STRING(&_6, "c");
		ZEPHIR_INIT_VAR(&_7);
		zephir_fast_strpos(&_7, &mode, &_6, 0 );
		_5 = !ZEPHIR_IS_FALSE_IDENTICAL(&_7);
	}
	_8 = _5;
	if (!(_8)) {
		ZEPHIR_INIT_VAR(&_9);
		ZVAL_STRING(&_9, "a");
		ZEPHIR_INIT_VAR(&_10);
		zephir_fast_strpos(&_10, &mode, &_9, 0 );
		_8 = !ZEPHIR_IS_FALSE_IDENTICAL(&_10);
	}
	_11 = _8;
	if (!(_11)) {
		ZEPHIR_INIT_VAR(&_12);
		ZVAL_STRING(&_12, "+");
		ZEPHIR_INIT_VAR(&_13);
		zephir_fast_strpos(&_13, &mode, &_12, 0 );
		_11 = !ZEPHIR_IS_FALSE_IDENTICAL(&_13);
	}
	RETURN_MM_BOOL(_11);

}

/**
 * Read data from the stream.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, read) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *length, length_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&length_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &length);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkhandle", NULL, 48);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkreadable", NULL, 49);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&data, "fread", NULL, 54, &_0, length);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&data)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_ce, "Could not read from the file/stream", "phalcon/Http/Message/Stream.zep", 234);
		return;
	}
	RETURN_CCTOR(&data);

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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset, offset_sub, *whence = NULL, whence_sub, seeker, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&whence_sub);
	ZVAL_UNDEF(&seeker);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &offset, &whence);

	if (!whence) {
		whence = &whence_sub;
		ZEPHIR_INIT_VAR(whence);
		ZVAL_LONG(whence, 0);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkhandle", NULL, 48);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkseekable", NULL, 55);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&seeker, "fseek", NULL, 56, &_0, offset, whence);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG_IDENTICAL(&seeker, 0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_ce, "Cound not seek on the file pointer", "phalcon/Http/Message/Stream.zep", 264);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the stream - existing instance
 */
PHP_METHOD(Phalcon_Http_Message_Stream, setStream) {

	zend_bool _2, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *stream, stream_sub, *mode = NULL, mode_sub, handle, _1, _4, _5, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&mode_sub);
	ZVAL_UNDEF(&handle);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &stream, &mode);

	if (!mode) {
		mode = &mode_sub;
		ZEPHIR_INIT_VAR(mode);
		ZVAL_STRING(mode, "r");
	}


	ZEPHIR_CPY_WRT(&handle, stream);
	if (Z_TYPE_P(stream) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_INIT_NVAR(&_0$$3);
		zephir_create_closure_ex(&_0$$3, NULL, phalcon_0__closure_ce, SL("__invoke"));
		ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 57, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&handle, "fopen", NULL, 58, stream, mode);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 59);
		zephir_check_call_status();
	}
	zephir_read_property(&_1, this_ptr, SL("warning"), PH_NOISY_CC | PH_READONLY);
	_2 = ZEPHIR_IS_TRUE_IDENTICAL(&_1);
	if (!(_2)) {
		_2 = Z_TYPE_P(&handle) != IS_RESOURCE;
	}
	_3 = _2;
	if (!(_3)) {
		ZEPHIR_CALL_FUNCTION(&_4, "get_resource_type", NULL, 60, &handle);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_5);
		ZVAL_STRING(&_5, "stream");
		_3 = !ZEPHIR_IS_IDENTICAL(&_5, &_4);
	}
	if (_3) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_ce, "The stream provided is not valid (string/resource) or could not be opened.", "phalcon/Http/Message/Stream.zep", 292);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("handle"), &handle);
	zephir_update_property_zval(this_ptr, SL("stream"), stream);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the current position of the file read/write pointer
 */
PHP_METHOD(Phalcon_Http_Message_Stream, tell) {

	zval position, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkhandle", NULL, 48);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&position, "ftell", NULL, 61, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&position) != IS_LONG) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_ce, "Could not retrieve the pointer position", "phalcon/Http/Message/Stream.zep", 311);
		return;
	}
	RETURN_CCTOR(&position);

}

/**
 * Write data to the stream.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, write) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, bytes, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&bytes);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkhandle", NULL, 48);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkwritable", NULL, 62);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&bytes);
	zephir_fwrite(&bytes, &_0, data TSRMLS_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&bytes)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_ce, "Could not write to the file/stream", "phalcon/Http/Message/Stream.zep", 330);
		return;
	}
	RETURN_CCTOR(&bytes);

}

/**
 * Checks if a handle is available and throws an exception otherwise
 */
PHP_METHOD(Phalcon_Http_Message_Stream, checkHandle) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_http_message_exception_ce, "A valid resource is required.", "phalcon/Http/Message/Stream.zep", 342);
		return;
	}

}

/**
 * Checks if a handle is readable and throws an exception otherwise
 */
PHP_METHOD(Phalcon_Http_Message_Stream, checkReadable) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isreadable", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_ce, "The resource is not readable.", "phalcon/Http/Message/Stream.zep", 352);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if a handle is seekable and throws an exception otherwise
 */
PHP_METHOD(Phalcon_Http_Message_Stream, checkSeekable) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isseekable", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_ce, "The resource is not seekable.", "phalcon/Http/Message/Stream.zep", 362);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if a handle is writeable and throws an exception otherwise
 */
PHP_METHOD(Phalcon_Http_Message_Stream, checkWritable) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "iswritable", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_ce, "The resource is not writable.", "phalcon/Http/Message/Stream.zep", 372);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

