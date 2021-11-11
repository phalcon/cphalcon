
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
#include "kernel/operators.h"
#include "kernel/memory.h"
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
 * PSR-17 UploadedFileFactory
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_UploadedFileFactory)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Message, UploadedFileFactory, phalcon, http_message_uploadedfilefactory, phalcon_http_message_uploadedfilefactory_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_class_implements(phalcon_http_message_uploadedfilefactory_ce, 1, zephir_get_internal_ce(SL("psr\\http\\message\\uploadedfilefactoryinterface")));
	return SUCCESS;
}

/**
 * Create a new uploaded file.
 *
 * If a size is not provided it will be determined by checking the size of
 * the stream.
 *
 * @link http://php.net/manual/features.file-upload.post-method.php
 * @link http://php.net/manual/features.file-upload.errors.php
 *
 * @param StreamInterface $stream          The underlying stream representing the
 *                                         uploaded file content.
 * @param int             $size            The size of the file in bytes.
 * @param int             $error           The PHP file upload error.
 * @param string          $clientFilename  The filename as provided by the client, if any.
 * @param string          $clientMediaType The media type as provided by the client, if any.
 *
 * @throws \InvalidArgumentException If the file resource is not readable.
 */
PHP_METHOD(Phalcon_Http_Message_UploadedFileFactory, createUploadedFile)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval clientFilename, clientMediaType;
	zend_long size, error, ZEPHIR_LAST_CALL_STATUS;
	zval *stream, stream_sub, *size_param = NULL, *error_param = NULL, *clientFilename_param = NULL, *clientMediaType_param = NULL, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&clientFilename);
	ZVAL_UNDEF(&clientMediaType);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_OBJECT_OF_CLASS(stream, zephir_get_internal_ce(SL("psr\\http\\message\\streaminterface")))
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(size, is_null_true)
		Z_PARAM_LONG(error)
		Z_PARAM_STR_OR_NULL(clientFilename)
		Z_PARAM_STR_OR_NULL(clientMediaType)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 4, &stream, &size_param, &error_param, &clientFilename_param, &clientMediaType_param);
	if (!size_param) {
		size = 0;
	} else {
		size = zephir_get_intval(size_param);
	}
	if (!error_param) {
		error = 0;
	} else {
		error = zephir_get_intval(error_param);
	}
	if (!clientFilename_param) {
		ZEPHIR_INIT_VAR(&clientFilename);
	} else {
		zephir_get_strval(&clientFilename, clientFilename_param);
	}
	if (!clientMediaType_param) {
		ZEPHIR_INIT_VAR(&clientMediaType);
	} else {
		zephir_get_strval(&clientMediaType, clientMediaType_param);
	}


	object_init_ex(return_value, phalcon_http_message_uploadedfile_ce);
	ZVAL_LONG(&_0, size);
	ZVAL_LONG(&_1, error);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 330, stream, &_0, &_1, &clientFilename, &clientMediaType);
	zephir_check_call_status();
	RETURN_MM();
}

