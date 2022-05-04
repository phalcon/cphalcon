
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/file.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/object.h"


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
 * PSR-17 StreamFactory
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_StreamFactory)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Message, StreamFactory, phalcon, http_message_streamfactory, phalcon_http_message_streamfactory_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_class_implements(phalcon_http_message_streamfactory_ce, 1, zephir_get_internal_ce(SL("psrext\\http\\message\\streamfactoryinterface")));
	return SUCCESS;
}

/**
 * Create a new stream from a string.
 *
 * The stream SHOULD be created with a temporary resource.
 *
 * @param string $content String content with which to populate the stream.
 *
 * @return StreamInterface
 */
PHP_METHOD(Phalcon_Http_Message_StreamFactory, createStream)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content_param = NULL, handle, _0, _1;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&handle);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(content)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &content_param);
	if (!content_param) {
		ZEPHIR_INIT_VAR(&content);
		ZVAL_STRING(&content, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(content_param) != IS_STRING && Z_TYPE_P(content_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'content' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(content_param) == IS_STRING)) {
		zephir_get_strval(&content, content_param);
	} else {
		ZEPHIR_INIT_VAR(&content);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "php://temp");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "r+b");
	ZEPHIR_CALL_FUNCTION(&handle, "fopen", NULL, 90, &_0, &_1);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&handle))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_invalidargumentexception_ce, "Cannot write to file.", "phalcon/Http/Message/StreamFactory.zep", 41);
		return;
	}
	zephir_fwrite(NULL, &handle, &content);
	ZEPHIR_CALL_FUNCTION(NULL, "rewind", NULL, 396, &handle);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "createstreamfromresource", NULL, 397, &handle);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Create a stream from an existing file.
 *
 * The file MUST be opened using the given mode, which may be any mode
 * supported by the `fopen` function.
 *
 * The `$filename` MAY be any string supported by `fopen()`.
 *
 * @param string $filename The filename or stream URI to use as basis of
 *                         stream.
 * @param string $mode     The mode with which to open the underlying
 *                         filename/stream.
 *
 * @return StreamInterface
 */
PHP_METHOD(Phalcon_Http_Message_StreamFactory, createStreamFromFile)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filename_param = NULL, *mode_param = NULL;
	zval filename, mode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filename);
	ZVAL_UNDEF(&mode);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(mode)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &filename_param, &mode_param);
	if (UNEXPECTED(Z_TYPE_P(filename_param) != IS_STRING && Z_TYPE_P(filename_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filename' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(filename_param) == IS_STRING)) {
		zephir_get_strval(&filename, filename_param);
	} else {
		ZEPHIR_INIT_VAR(&filename);
	}
	if (!mode_param) {
		ZEPHIR_INIT_VAR(&mode);
		ZVAL_STRING(&mode, "r+b");
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


	object_init_ex(return_value, phalcon_http_message_stream_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 43, &filename, &mode);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Create a new stream from an existing resource.
 *
 * The stream MUST be readable and may be writable.
 */
PHP_METHOD(Phalcon_Http_Message_StreamFactory, createStreamFromResource)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *phpResource, phpResource_sub, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&phpResource_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(phpResource)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &phpResource);


	_0 = Z_TYPE_P(phpResource) != IS_RESOURCE;
	if (!(_0)) {
		ZEPHIR_CALL_FUNCTION(&_1, "get_resource_type", NULL, 92, phpResource);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_STRING(&_2, "stream");
		_0 = !ZEPHIR_IS_IDENTICAL(&_2, &_1);
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_invalidargumentexception_ce, "Invalid stream provided", "phalcon/Http/Message/StreamFactory.zep", 79);
		return;
	}
	object_init_ex(return_value, phalcon_http_message_stream_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 43, phpResource);
	zephir_check_call_status();
	RETURN_MM();
}

