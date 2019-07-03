
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/file.h"


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
 * PSR-7 Stream
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
 * Stream constructor.
 *
 * @param mixed  $stream
 * @param string $mode
 */
PHP_METHOD(Phalcon_Http_Message_Stream, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval mode;
	zval *stream, stream_sub, *mode_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&mode);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &stream, &mode_param);

	if (!mode_param) {
		ZEPHIR_INIT_VAR(&mode);
		ZVAL_STRING(&mode, "rb");
	} else {
	if (UNEXPECTED(Z_TYPE_P(mode_param) != IS_STRING && Z_TYPE_P(mode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'mode' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(mode_param) == IS_STRING)) {
		zephir_get_strval(&mode, mode_param);
	} else {
		ZEPHIR_INIT_VAR(&mode);
		ZVAL_EMPTY_STRING(&mode);
	}
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstream", NULL, 0, stream, &mode);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Closes the stream when the destructed.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, __destruct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "close", NULL, 0);
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
		if (UNEXPECTED(zephir_is_true(&_0$$3))) {
			ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "isseekable", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			if (UNEXPECTED(zephir_is_true(&_1$$4))) {
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
	if (EXPECTED(Z_TYPE_P(&_0) != IS_NULL)) {
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
 *
 * @return resource | null
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
	if (UNEXPECTED(zephir_is_true(&_0))) {
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

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkhandle", NULL, 65);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkreadable", NULL, 66);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&data, "stream_get_contents", NULL, 67, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&data))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Could not read from the file/stream", "phalcon/Http/Message/Stream.zep", 145);
		return;
	}
	RETURN_CCTOR(&data);

}

/**
 * Get stream metadata as an associative array or retrieve a specific key.
 *
 * The keys returned are identical to the keys returned from PHP's
 * stream_get_meta_data() function.
 *
 * @param mixed|null $key
 *
 * @return array|mixed|null
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
	if (UNEXPECTED(Z_TYPE_P(&_0) == IS_NULL)) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_1, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&metadata, "stream_get_meta_data", NULL, 68, &_1);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(key) == IS_NULL)) {
		RETURN_CCTOR(&metadata);
	}
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_helper_arr_ce, "get", &_2, 8, &metadata, key, &_3);
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
	if (EXPECTED(Z_TYPE_P(&_0) != IS_NULL)) {
		zephir_read_property(&_1$$3, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&stats, "fstat", NULL, 69, &_1$$3);
		zephir_check_call_status();
		if (EXPECTED(!ZEPHIR_IS_FALSE_IDENTICAL(&stats))) {
			ZEPHIR_INIT_VAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "size");
			ZVAL_NULL(&_4$$4);
			ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_helper_arr_ce, "get", &_2, 8, &stats, &_3$$4, &_4$$4);
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

	zval _2;
	zval mode, _0, _1, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "mode");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmetadata", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_get_strval(&_2, &_0);
	ZEPHIR_CPY_WRT(&mode, &_2);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "r+");
	ZEPHIR_CALL_FUNCTION(&_3, "strpbrk", NULL, 70, &mode, &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(&_3));

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

	zval _2;
	zval mode, _0, _1, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "mode");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmetadata", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_get_strval(&_2, &_0);
	ZEPHIR_CPY_WRT(&mode, &_2);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "xwca+");
	ZEPHIR_CALL_FUNCTION(&_3, "strpbrk", NULL, 70, &mode, &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(&_3));

}

/**
 * Read data from the stream.
 *
 * @param int $length
 *
 * @return string
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



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkhandle", NULL, 65);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkreadable", NULL, 66);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&data, "fread", NULL, 71, &_0, length);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&data))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Could not read from the file/stream", "phalcon/Http/Message/Stream.zep", 245);
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
 *
 * @param int $offset
 * @param int $whence
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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkhandle", NULL, 65);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkseekable", NULL, 72);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&seeker, "fseek", NULL, 73, &_0, offset, whence);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_LONG_IDENTICAL(&seeker, 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Could not seek on the file pointer", "phalcon/Http/Message/Stream.zep", 278);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the stream - existing instance
 *
 * @param mixed  $stream
 * @param string $mode
 */
PHP_METHOD(Phalcon_Http_Message_Stream, setStream) {

	zend_bool _2, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval mode;
	zval *stream, stream_sub, *mode_param = NULL, handle, _1, _4, _5, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&handle);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&mode);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &stream, &mode_param);

	if (!mode_param) {
		ZEPHIR_INIT_VAR(&mode);
		ZVAL_STRING(&mode, "rb");
	} else {
	if (UNEXPECTED(Z_TYPE_P(mode_param) != IS_STRING && Z_TYPE_P(mode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'mode' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(mode_param) == IS_STRING)) {
		zephir_get_strval(&mode, mode_param);
	} else {
		ZEPHIR_INIT_VAR(&mode);
		ZVAL_EMPTY_STRING(&mode);
	}
	}


	ZEPHIR_CPY_WRT(&handle, stream);
	if (EXPECTED(Z_TYPE_P(stream) == IS_STRING)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_INIT_NVAR(&_0$$3);
		zephir_create_closure_ex(&_0$$3, NULL, phalcon_0__closure_ce, SL("__invoke"));
		ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 74, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&handle, "fopen", NULL, 75, stream, &mode);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 76);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("warning"), PH_NOISY_CC);
	_2 = zephir_is_true(&_1);
	if (!(_2)) {
		_2 = Z_TYPE_P(&handle) != IS_RESOURCE;
	}
	_3 = _2;
	if (!(_3)) {
		ZEPHIR_CALL_FUNCTION(&_4, "get_resource_type", NULL, 77, &handle);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_5);
		ZVAL_STRING(&_5, "stream");
		_3 = !ZEPHIR_IS_IDENTICAL(&_5, &_4);
	}
	if (UNEXPECTED(_3)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "The stream provided is not valid (string/resource) or could not be opened.", "phalcon/Http/Message/Stream.zep", 308);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("handle"), &handle);
	zephir_update_property_zval(this_ptr, SL("stream"), stream);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the current position of the file read/write pointer
 *
 * @return int
 */
PHP_METHOD(Phalcon_Http_Message_Stream, tell) {

	zval position, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkhandle", NULL, 65);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&position, "ftell", NULL, 78, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&position) != IS_LONG)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Could not retrieve the pointer position", "phalcon/Http/Message/Stream.zep", 329);
		return;
	}
	RETURN_CCTOR(&position);

}

/**
 * Write data to the stream.
 *
 * @param string $data
 *
 * @return int
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



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkhandle", NULL, 65);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkwritable", NULL, 79);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&bytes);
	zephir_fwrite(&bytes, &_0, data TSRMLS_CC);
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&bytes))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Could not write to the file/stream", "phalcon/Http/Message/Stream.zep", 352);
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
	if (UNEXPECTED(Z_TYPE_P(&_0) == IS_NULL)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_RuntimeException, "A valid resource is required.", "phalcon/Http/Message/Stream.zep", 364);
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
	if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "The resource is not readable.", "phalcon/Http/Message/Stream.zep", 374);
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
	if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "The resource is not seekable.", "phalcon/Http/Message/Stream.zep", 384);
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
	if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "The resource is not writable.", "phalcon/Http/Message/Stream.zep", 394);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

