
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
 * PSR-7 Stream
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_Stream)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Message, Stream, phalcon, http_message_stream, phalcon_http_message_stream_method_entry, 0);

	/**
	 * @var resource | null
	 */
	zend_declare_property_null(phalcon_http_message_stream_ce, SL("handle"), ZEND_ACC_PROTECTED);
	/**
	 * @var resource | string
	 */
	zend_declare_property_null(phalcon_http_message_stream_ce, SL("stream"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_http_message_stream_ce, 1, zephir_get_internal_ce(SL("psr\\http\\message\\streaminterface")));
	return SUCCESS;
}

/**
 * Stream constructor.
 *
 * @param mixed  $stream
 * @param string $mode
 */
PHP_METHOD(Phalcon_Http_Message_Stream, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval mode;
	zval *stream, stream_sub, *mode_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&mode);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(stream)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(mode)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &stream, &mode_param);
	if (!mode_param) {
		ZEPHIR_INIT_VAR(&mode);
		ZVAL_STRING(&mode, "rb");
	} else {
	if (UNEXPECTED(Z_TYPE_P(mode_param) != IS_STRING && Z_TYPE_P(mode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'mode' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(mode_param) == IS_STRING)) {
		zephir_get_strval(&mode, mode_param);
	} else {
		ZEPHIR_INIT_VAR(&mode);
	}
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstream", NULL, 0, stream, &mode);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Closes the stream when the destructed.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, __destruct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
PHP_METHOD(Phalcon_Http_Message_Stream, __toString)
{
	zval _0$$3, _1$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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

	zend_clear_exception();
	RETURN_MM_STRING("");
}

/**
 * Closes the stream and any underlying resources.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, close)
{
	zval handle, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handle);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("handle"), PH_NOISY_CC | PH_READONLY);
	if (EXPECTED(Z_TYPE_P(&_0) != IS_NULL)) {
		ZEPHIR_CALL_METHOD(&handle, this_ptr, "detach", NULL, 0);
		zephir_check_call_status();
		zephir_fclose(&handle);
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
PHP_METHOD(Phalcon_Http_Message_Stream, detach)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, handle, _0;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&handle);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&handle, &_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("handle"), &__$null);
	RETURN_CCTOR(&handle);
}

/**
 * Returns true if the stream is at the end of the stream.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, eof)
{
	zval _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("handle"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(zephir_is_true(&_0))) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("handle"), PH_NOISY_CC | PH_READONLY);
		RETURN_BOOL(zephir_feof(&_1$$3));
	}
	RETURN_BOOL(1);
}

/**
 * Returns the remaining contents in a string
 */
PHP_METHOD(Phalcon_Http_Message_Stream, getContents)
{
	zval data, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkhandle", NULL, 77);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkreadable", NULL, 78);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&data, "stream_get_contents", NULL, 79, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&data))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Could not read from the file/stream", "phalcon/Http/Message/Stream.zep", 140);
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
PHP_METHOD(Phalcon_Http_Message_Stream, getMetadata)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &key);
	if (!key) {
		key = &key_sub;
		key = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("handle"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(Z_TYPE_P(&_0) == IS_NULL)) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&metadata, "stream_get_meta_data", NULL, 80, &_1);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(key) == IS_NULL)) {
		RETURN_CCTOR(&metadata);
	}
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_helper_arr_ce, "get", &_2, 81, &metadata, key, &_3);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Get the size of the stream if known.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, getSize)
{
	zval stats, _0, _1$$3, _3$$4, _4$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stats);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("handle"), PH_NOISY_CC | PH_READONLY);
	if (EXPECTED(Z_TYPE_P(&_0) != IS_NULL)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("handle"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&stats, "fstat", NULL, 82, &_1$$3);
		zephir_check_call_status();
		if (EXPECTED(!ZEPHIR_IS_FALSE_IDENTICAL(&stats))) {
			ZEPHIR_INIT_VAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "size");
			ZVAL_NULL(&_4$$4);
			ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_helper_arr_ce, "get", &_2, 81, &stats, &_3$$4, &_4$$4);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	RETURN_MM_NULL();
}

/**
 * Returns whether or not the stream is readable.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, isReadable)
{
	zval _2;
	zval mode, _0, _1, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	zephir_cast_to_string(&_2, &_0);
	ZEPHIR_CPY_WRT(&mode, &_2);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "r+");
	ZEPHIR_CALL_FUNCTION(&_3, "strpbrk", NULL, 83, &mode, &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(&_3));
}

/**
 * Returns whether or not the stream is seekable.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, isSeekable)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
PHP_METHOD(Phalcon_Http_Message_Stream, isWritable)
{
	zval _2;
	zval mode, _0, _1, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	zephir_cast_to_string(&_2, &_0);
	ZEPHIR_CPY_WRT(&mode, &_2);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "xwca+");
	ZEPHIR_CALL_FUNCTION(&_3, "strpbrk", NULL, 83, &mode, &_1);
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
PHP_METHOD(Phalcon_Http_Message_Stream, read)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *length, length_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&length_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(length)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &length);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkhandle", NULL, 77);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkreadable", NULL, 78);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&data, "fread", NULL, 84, &_0, length);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&data))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Could not read from the file/stream", "phalcon/Http/Message/Stream.zep", 240);
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
PHP_METHOD(Phalcon_Http_Message_Stream, rewind)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
PHP_METHOD(Phalcon_Http_Message_Stream, seek)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset, offset_sub, *whence = NULL, whence_sub, seeker, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&whence_sub);
	ZVAL_UNDEF(&seeker);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(offset)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(whence)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &offset, &whence);
	if (!whence) {
		whence = &whence_sub;
		ZEPHIR_INIT_VAR(whence);
		ZVAL_LONG(whence, 0);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkhandle", NULL, 77);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkseekable", NULL, 85);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&seeker, "fseek", NULL, 86, &_0, offset, whence);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_LONG_IDENTICAL(&seeker, 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Could not seek on the file pointer", "phalcon/Http/Message/Stream.zep", 273);
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
PHP_METHOD(Phalcon_Http_Message_Stream, setStream)
{
	zend_bool _7, _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval mode;
	zval *stream, stream_sub, *mode_param = NULL, __$false, handle, version, _9, _10, _0$$3, _1$$3, _2$$3, _3$$4, _4$$4, _5$$5, _6$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stream_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&handle);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&mode);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(stream)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(mode)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &stream, &mode_param);
	if (!mode_param) {
		ZEPHIR_INIT_VAR(&mode);
		ZVAL_STRING(&mode, "rb");
	} else {
	if (UNEXPECTED(Z_TYPE_P(mode_param) != IS_STRING && Z_TYPE_P(mode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'mode' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(mode_param) == IS_STRING)) {
		zephir_get_strval(&mode, mode_param);
	} else {
		ZEPHIR_INIT_VAR(&mode);
	}
	}


	ZEPHIR_CPY_WRT(&handle, stream);
	ZEPHIR_CALL_FUNCTION(&version, "phpversion", NULL, 87);
	zephir_check_call_status();
	ZEPHIR_GLOBAL(warning).enable = zend_is_true(&__$false);
	if (EXPECTED(Z_TYPE_P(stream) == IS_STRING)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "8.0");
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, ">=");
		ZEPHIR_CALL_FUNCTION(&_2$$3, "version_compare", NULL, 88, &version, &_0$$3, &_1$$3);
		zephir_check_call_status();
		if (zephir_is_true(&_2$$3)) {
			ZEPHIR_INIT_VAR(&_3$$4);
			ZEPHIR_INIT_NVAR(&_3$$4);
			zephir_create_closure_ex(&_3$$4, NULL, phalcon_0__closure_ce, SL("__invoke"));
			ZVAL_LONG(&_4$$4, 2);
			ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 89, &_3$$4, &_4$$4);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_5$$5);
			ZEPHIR_INIT_NVAR(&_5$$5);
			zephir_create_closure_ex(&_5$$5, NULL, phalcon_1__closure_ce, SL("__invoke"));
			ZVAL_LONG(&_6$$5, 2);
			ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 89, &_5$$5, &_6$$5);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_FUNCTION(&handle, "fopen", NULL, 90, stream, &mode);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 91);
		zephir_check_call_status();
	}
	_7 = ZEPHIR_GLOBAL(warning).enable;
	if (!(_7)) {
		_7 = Z_TYPE_P(&handle) != IS_RESOURCE;
	}
	_8 = _7;
	if (!(_8)) {
		ZEPHIR_CALL_FUNCTION(&_9, "get_resource_type", NULL, 92, &handle);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_10);
		ZVAL_STRING(&_10, "stream");
		_8 = !ZEPHIR_IS_IDENTICAL(&_10, &_9);
	}
	if (UNEXPECTED(_8)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "The stream provided is not valid (string/resource) or could not be opened.", "phalcon/Http/Message/Stream.zep", 321);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("handle"), &handle);
	zephir_update_property_zval(this_ptr, ZEND_STRL("stream"), stream);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the current position of the file read/write pointer
 *
 * @return int
 */
PHP_METHOD(Phalcon_Http_Message_Stream, tell)
{
	zval position, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkhandle", NULL, 77);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&position, "ftell", NULL, 93, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&position) != IS_LONG)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_ce_exception, "Could not retrieve the pointer position", "phalcon/Http/Message/Stream.zep", 342);
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
PHP_METHOD(Phalcon_Http_Message_Stream, write)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, bytes, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&bytes);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkhandle", NULL, 77);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkwritable", NULL, 94);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&bytes);
	zephir_fwrite(&bytes, &_0, data);
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&bytes))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Could not write to the file/stream", "phalcon/Http/Message/Stream.zep", 365);
		return;
	}
	RETURN_CCTOR(&bytes);
}

/**
 * Checks if a handle is available and throws an exception otherwise
 */
PHP_METHOD(Phalcon_Http_Message_Stream, checkHandle)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("handle"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(Z_TYPE_P(&_0) == IS_NULL)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_RuntimeException, "A valid resource is required.", "phalcon/Http/Message/Stream.zep", 377);
		return;
	}
}

/**
 * Checks if a handle is readable and throws an exception otherwise
 */
PHP_METHOD(Phalcon_Http_Message_Stream, checkReadable)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isreadable", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "The resource is not readable.", "phalcon/Http/Message/Stream.zep", 387);
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Checks if a handle is seekable and throws an exception otherwise
 */
PHP_METHOD(Phalcon_Http_Message_Stream, checkSeekable)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isseekable", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "The resource is not seekable.", "phalcon/Http/Message/Stream.zep", 397);
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Checks if a handle is writeable and throws an exception otherwise
 */
PHP_METHOD(Phalcon_Http_Message_Stream, checkWritable)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "iswritable", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "The resource is not writable.", "phalcon/Http/Message/Stream.zep", 407);
		return;
	}
	ZEPHIR_MM_RESTORE();
}

