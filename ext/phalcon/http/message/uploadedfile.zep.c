
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
#include "kernel/memory.h"
#include "kernel/operators.h"


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
 * Value object representing a file uploaded through an HTTP request.
 *
 * Instances of this interface are considered immutable; all methods that
 * might change state MUST be implemented such that they retain the internal
 * state of the current instance and return an instance that contains the
 * changed state.
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_UploadedFile) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Message, UploadedFile, phalcon, http_message_uploadedfile, phalcon_http_message_uploadedfile_method_entry, 0);

	/**
	 * Retrieve the filename sent by the client.
	 *
	 * Do not trust the value returned by this method. A client could send
	 * a malicious filename with the intention to corrupt or hack your
	 * application.
	 *
	 * Implementations SHOULD return the value stored in the "name" key of
	 * the file in the $_FILES array.
	 *
	 * @var string | null
	 */
	zend_declare_property_null(phalcon_http_message_uploadedfile_ce, SL("clientFilename"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Retrieve the media type sent by the client.
	 *
	 * Do not trust the value returned by this method. A client could send
	 * a malicious media type with the intention to corrupt or hack your
	 * application.
	 *
	 * Implementations SHOULD return the value stored in the "type" key of
	 * the file in the $_FILES array.
	 *
	 * @var string | null
	 */
	zend_declare_property_null(phalcon_http_message_uploadedfile_ce, SL("clientMediaType"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Retrieve the error associated with the uploaded file.
	 *
	 * The return value MUST be one of PHP's UPLOAD_ERR_XXX constants.
	 *
	 * If the file was uploaded successfully, this method MUST return
	 * UPLOAD_ERR_OK.
	 *
	 * Implementations SHOULD return the value stored in the "error" key of
	 * the file in the $_FILES array.
	 *
	 * @see http://php.net/manual/en/features.file-upload.errors.php
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_http_message_uploadedfile_ce, SL("error"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Retrieve the file size.
	 *
	 * Implementations SHOULD return the value stored in the "size" key of
	 * the file in the $_FILES array if available, as PHP calculates this based
	 * on the actual size transmitted.
	 *
	 * @var int | null
	 */
	zend_declare_property_null(phalcon_http_message_uploadedfile_ce, SL("size"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalcon_http_message_uploadedfile_ce, SL("stream"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(phalcon_http_message_uploadedfile_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("psr\\http\\message\\uploadedfileinterface")));
	return SUCCESS;

}

/**
 * Retrieve the filename sent by the client.
 *
 *
 * Do not trust the value returned by this method. A client could send
 * a malicious filename with the intention to corrupt or hack your
 * application.
 * 
 * Implementations SHOULD return the value stored in the "name" key of
 * the file in the $_FILES array.
 *
 */
PHP_METHOD(Phalcon_Http_Message_UploadedFile, getClientFilename) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "clientFilename");

}

/**
 * Retrieve the media type sent by the client.
 *
 *
 * Do not trust the value returned by this method. A client could send
 * a malicious media type with the intention to corrupt or hack your
 * application.
 * 
 * Implementations SHOULD return the value stored in the "type" key of
 * the file in the $_FILES array.
 *
 */
PHP_METHOD(Phalcon_Http_Message_UploadedFile, getClientMediaType) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "clientMediaType");

}

/**
 * Retrieve the error associated with the uploaded file.
 *
 *
 * The return value MUST be one of PHP's UPLOAD_ERR_XXX constants.
 * 
 * If the file was uploaded successfully, this method MUST return
 * UPLOAD_ERR_OK.
 * 
 * Implementations SHOULD return the value stored in the "error" key of
 * the file in the $_FILES array.
 *
 */
PHP_METHOD(Phalcon_Http_Message_UploadedFile, getError) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "error");

}

/**
 * Retrieve the file size.
 *
 *
 * Implementations SHOULD return the value stored in the "size" key of
 * the file in the $_FILES array if available, as PHP calculates this based
 * on the actual size transmitted.
 *
 */
PHP_METHOD(Phalcon_Http_Message_UploadedFile, getSize) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "size");

}

/**
 * Constructor
 */
PHP_METHOD(Phalcon_Http_Message_UploadedFile, __construct) {

	zval clientFilename, clientMediaType;
	zend_long size, error;
	zval *stream, stream_sub, *size_param = NULL, *error_param = NULL, *clientFilename_param = NULL, *clientMediaType_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&_0);
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


	zephir_update_property_zval(this_ptr, SL("stream"), stream);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, size);
	zephir_update_property_zval(this_ptr, SL("size"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, error);
	zephir_update_property_zval(this_ptr, SL("error"), &_0);
	zephir_update_property_zval(this_ptr, SL("clientFilename"), &clientFilename);
	zephir_update_property_zval(this_ptr, SL("clientMediaType"), &clientMediaType);
	ZEPHIR_MM_RESTORE();

}

/**
 * Retrieve a stream representing the uploaded file.
 *
 * This method MUST return a StreamInterface instance, representing the
 * uploaded file. The purpose of this method is to allow utilizing native PHP
 * stream functionality to manipulate the file upload, such as
 * stream_copy_to_stream() (though the result will need to be decorated in a
 * native PHP stream wrapper to work with such functions).
 *
 * If the moveTo() method has been called previously, this method MUST raise
 * an exception.
 *
 * @return StreamInterface Stream representation of the uploaded file.
 * @throws \RuntimeException in cases when no stream is available.
 * @throws \RuntimeException in cases when no stream can be created.
 */
PHP_METHOD(Phalcon_Http_Message_UploadedFile, getStream) {

	zval *this_ptr = getThis();



}

/**
 * Move the uploaded file to a new location.
 *
 * Use this method as an alternative to move_uploaded_file(). This method is
 * guaranteed to work in both SAPI and non-SAPI environments.
 * Implementations must determine which environment they are in, and use the
 * appropriate method (move_uploaded_file(), rename(), or a stream
 * operation) to perform the operation.
 *
 * $targetPath may be an absolute path, or a relative path. If it is a
 * relative path, resolution should be the same as used by PHP's rename()
 * function.
 *
 * The original file or stream MUST be removed on completion.
 *
 * If this method is called more than once, any subsequent calls MUST raise
 * an exception.
 *
 * When used in an SAPI environment where $_FILES is populated, when writing
 * files via moveTo(), is_uploaded_file() and move_uploaded_file() SHOULD be
 * used to ensure permissions and upload status are verified correctly.
 *
 * If you wish to move to a stream, use getStream(), as SAPI operations
 * cannot guarantee writing to stream destinations.
 *
 * @see http://php.net/is_uploaded_file
 * @see http://php.net/move_uploaded_file
 *
 * @throws \InvalidArgumentException if the $targetPath specified is invalid.
 * @throws \RuntimeException on any error during the move operation.
 * @throws \RuntimeException on the second or subsequent call to the method.
 */
PHP_METHOD(Phalcon_Http_Message_UploadedFile, moveTo) {

	zval *targetPath, targetPath_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&targetPath_sub);

	zephir_fetch_params(0, 1, 0, &targetPath);




}

