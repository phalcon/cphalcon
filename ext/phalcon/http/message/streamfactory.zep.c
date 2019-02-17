
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
#include "kernel/file.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_StreamFactory) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Message, StreamFactory, phalcon, http_message_streamfactory, phalcon_http_message_streamfactory_method_entry, 0);

	zend_class_implements(phalcon_http_message_streamfactory_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("psr\\http\\message\\streamfactoryinterface")));
	return SUCCESS;

}

/**
 * Create a new stream from a string.
 *
 * The stream SHOULD be created with a temporary resource.
 *
 * @param string $content String content with which to populate the stream.
 */
PHP_METHOD(Phalcon_Http_Message_StreamFactory, createStream) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content_param = NULL, tempResource, _0, _1;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&tempResource);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &content_param);

	if (!content_param) {
		ZEPHIR_INIT_VAR(&content);
		ZVAL_STRING(&content, "");
	} else {
		zephir_get_strval(&content, content_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "php://temp");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "r+");
	ZEPHIR_CALL_FUNCTION(&tempResource, "fopen", NULL, 79, &_0, &_1);
	zephir_check_call_status();
	zephir_fwrite(NULL, &tempResource, &content TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "rewind", NULL, 241, &tempResource);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "createstreamfromresource", NULL, 0, &tempResource);
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
 * @param string $filename The filename or stream URI to use as basis of stream.
 * @param string $mode The mode with which to open the underlying filename/stream.
 *
 * @throws \RuntimeException If the file cannot be opened.
 * @throws \InvalidArgumentException If the mode is invalid.
 */
PHP_METHOD(Phalcon_Http_Message_StreamFactory, createStreamFromFile) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filename_param = NULL, *mode_param = NULL, stream;
	zval filename, mode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filename);
	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&stream);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &filename_param, &mode_param);

	zephir_get_strval(&filename, filename_param);
	if (!mode_param) {
		ZEPHIR_INIT_VAR(&mode);
		ZVAL_STRING(&mode, "r");
	} else {
		zephir_get_strval(&mode, mode_param);
	}


	ZEPHIR_INIT_VAR(&stream);
	object_init_ex(&stream, phalcon_http_message_stream_ce);
	ZEPHIR_CALL_METHOD(NULL, &stream, "__construct", NULL, 236, &filename, &mode);
	zephir_check_call_status();
	RETURN_CCTOR(&stream);

}

/**
 * Create a new stream from an existing resource.
 *
 * The stream MUST be readable and may be writable.
 */
PHP_METHOD(Phalcon_Http_Message_StreamFactory, createStreamFromResource) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *phpResource, phpResource_sub, stream, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&phpResource_sub);
	ZVAL_UNDEF(&stream);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &phpResource);



	_0 = 1 != Z_TYPE_P(phpResource) == IS_RESOURCE;
	if (!(_0)) {
		ZEPHIR_CALL_FUNCTION(&_1, "get_resource_type", NULL, 80, phpResource);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_STRING(&_2, "stream");
		_0 = !ZEPHIR_IS_IDENTICAL(&_2, &_1);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "StreamFactory:createStreamFromResource() - invalid stream provbided", "phalcon/http/message/streamfactory.zep", 78);
		return;
	}
	ZEPHIR_INIT_VAR(&stream);
	object_init_ex(&stream, phalcon_http_message_stream_ce);
	ZEPHIR_CALL_METHOD(NULL, &stream, "__construct", NULL, 236, phpResource);
	zephir_check_call_status();
	RETURN_CCTOR(&stream);

}

