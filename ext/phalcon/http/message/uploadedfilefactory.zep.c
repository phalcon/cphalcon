
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
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_UploadedFileFactory) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Message, UploadedFileFactory, phalcon, http_message_uploadedfilefactory, phalcon_http_message_uploadedfilefactory_method_entry, 0);

	zend_class_implements(phalcon_http_message_uploadedfilefactory_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("psr\\http\\message\\uploadedfilefactoryinterface")));
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
 * @param StreamInterface $stream The underlying stream representing the
 *     uploaded file content.
 * @param int $size The size of the file in bytes.
 * @param int $error The PHP file upload error.
 * @param string $clientFilename The filename as provided by the client, if any.
 * @param string $clientMediaType The media type as provided by the client, if any.
 *
 * @throws \InvalidArgumentException If the file resource is not readable.
 */
PHP_METHOD(Phalcon_Http_Message_UploadedFileFactory, createUploadedFile) {

	zval clientFilename, clientMediaType;
	zend_long size, error;
	zval *stream, stream_sub, *size_param = NULL, *error_param = NULL, *clientFilename_param = NULL, *clientMediaType_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&clientFilename);
	ZVAL_UNDEF(&clientMediaType);

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
		ZVAL_STRING(&clientFilename, "");
	} else {
		zephir_get_strval(&clientFilename, clientFilename_param);
	}
	if (!clientMediaType_param) {
		ZEPHIR_INIT_VAR(&clientMediaType);
		ZVAL_STRING(&clientMediaType, "");
	} else {
		zephir_get_strval(&clientMediaType, clientMediaType_param);
	}



}

