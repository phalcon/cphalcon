
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/string.h"
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
	 * If the file has already been moved, we hold that status here
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_http_message_uploadedfile_ce, SL("alreadyMoved"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

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
	 * If the stream is a string (file name) we store it here
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_message_uploadedfile_ce, SL("fileName"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

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

	/**
	 * Holds the stream/string for the uploaded file
	 *
	 * @var <StreamInterface> | string | null
	 */
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
	zend_long size, error, ZEPHIR_LAST_CALL_STATUS;
	zval *stream, stream_sub, *size_param = NULL, *error_param = NULL, *clientFilename_param = NULL, *clientMediaType_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&clientFilename);
	ZVAL_UNDEF(&clientMediaType);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &stream, &size_param, &error_param, &clientFilename_param, &clientMediaType_param);

	size = zephir_get_intval(size_param);
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


	ZVAL_LONG(&_0, error);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstream", NULL, 253, stream, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, error);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkerror", NULL, 254, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, size);
	zephir_update_property_zval(this_ptr, SL("size"), &_0);
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

	zval _0, _1, _2, _6, _7, _3$$3, _4$$3, _5$$3, _8$$5, _9$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("error"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "UPLOAD_ERR_OK");
	ZEPHIR_CALL_FUNCTION(&_2, "constant", NULL, 255, &_1);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(&_0, &_2)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, phalcon_http_message_exception_ce);
		zephir_read_property(&_5$$3, this_ptr, SL("error"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "geterrordescription", NULL, 256, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 1, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "phalcon/Http/Message/UploadedFile.zep", 156 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_6, this_ptr, SL("alreadyMoved"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_6)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_ce, "The file has already been moved to the target location", "phalcon/Http/Message/UploadedFile.zep", 162);
		return;
	}
	ZEPHIR_OBS_VAR(&_7);
	zephir_read_property(&_7, this_ptr, SL("stream"), PH_NOISY_CC);
	if (!(zephir_is_instance_of(&_7, SL("Psr\\Http\\Message\\StreamInterface") TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_8$$5);
		object_init_ex(&_8$$5, phalcon_http_message_stream_ce);
		zephir_read_property(&_9$$5, this_ptr, SL("fileName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_8$$5, "__construct", NULL, 222, &_9$$5);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("stream"), &_8$$5);
	}
	RETURN_MM_MEMBER(getThis(), "stream");

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

	zend_bool _7, _8, _10, _12, _14;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *targetPath, targetPath_sub, __$true, __$false, sapi, dirname, _0, _1, _2, _3, _9, _11, _13, _4$$4, _5$$4, _6$$4, _15$$7, _16$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&targetPath_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&sapi);
	ZVAL_UNDEF(&dirname);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &targetPath);



	zephir_read_property(&_0, this_ptr, SL("alreadyMoved"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_ce, "File has already been moved", "phalcon/Http/Message/UploadedFile.zep", 209);
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "UPLOAD_ERR_OK");
	ZEPHIR_CALL_FUNCTION(&_2, "constant", NULL, 255, &_1);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("error"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_IDENTICAL(&_2, &_3)) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, phalcon_http_message_exception_ce);
		zephir_read_property(&_6$$4, this_ptr, SL("error"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "geterrordescription", NULL, 256, &_6$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 1, &_5$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalcon/Http/Message/UploadedFile.zep", 213 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&dirname, "dirname", NULL, 257, targetPath);
	zephir_check_call_status();
	_7 = Z_TYPE_P(targetPath) == IS_STRING;
	if (_7) {
		_7 = !(ZEPHIR_IS_EMPTY(targetPath));
	}
	_8 = _7;
	if (_8) {
		ZEPHIR_CALL_FUNCTION(&_9, "is_dir", NULL, 111, &dirname);
		zephir_check_call_status();
		_8 = zephir_is_true(&_9);
	}
	_10 = _8;
	if (_10) {
		ZEPHIR_CALL_FUNCTION(&_11, "is_writable", NULL, 258, &dirname);
		zephir_check_call_status();
		_10 = zephir_is_true(&_11);
	}
	if (!(_10)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_ce, "Target folder is empty string, not a folder or not writable", "phalcon/Http/Message/UploadedFile.zep", 224);
		return;
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "PHP_SAPI");
	ZEPHIR_CALL_FUNCTION(&sapi, "constant", NULL, 255, &_1);
	zephir_check_call_status();
	_12 = ZEPHIR_IS_EMPTY(&sapi);
	if (!(_12)) {
		ZEPHIR_OBS_VAR(&_13);
		zephir_read_property(&_13, this_ptr, SL("fileName"), PH_NOISY_CC);
		_12 = ZEPHIR_IS_EMPTY(&_13);
	}
	_14 = _12;
	if (!(_14)) {
		_14 = zephir_start_with_str(&sapi, SL("cli"));
	}
	if (_14) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "storefile", NULL, 259, targetPath);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_15$$7, this_ptr, SL("fileName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_16$$7, "move_uploaded_file", NULL, 260, &_15$$7, targetPath);
		zephir_check_call_status();
		if (!(zephir_is_true(&_16$$7))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_ce, "The file cannot be moved to the target folder", "phalcon/Http/Message/UploadedFile.zep", 238);
			return;
		}
	}
	if (1) {
		zephir_update_property_zval(this_ptr, SL("alreadyMoved"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("alreadyMoved"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks the passed error code and if not in the range throws an exception
 */
PHP_METHOD(Phalcon_Http_Message_UploadedFile, checkError) {

	zephir_fcall_cache_entry *_1 = NULL;
	zval *error_param = NULL, _0, _2, _3, _4, _5;
	zend_long error, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &error_param);

	error = zephir_get_intval(error_param);


	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "UPLOAD_ERR_OK");
	ZEPHIR_CALL_FUNCTION(&_3, "constant", NULL, 255, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "UPLOAD_ERR_EXTENSION");
	ZEPHIR_CALL_FUNCTION(&_4, "constant", NULL, 255, &_2);
	zephir_check_call_status();
	ZVAL_LONG(&_5, error);
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_helper_number_ce, "between", &_1, 261, &_5, &_3, &_4);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_ce, "Invalid 'error'. Must be one of the UPLOAD_ERR_* constants", "phalcon/Http/Message/UploadedFile.zep", 253);
		return;
	}
	ZEPHIR_INIT_ZVAL_NREF(_5);
	ZVAL_LONG(&_5, error);
	zephir_update_property_zval(this_ptr, SL("error"), &_5);
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks the passed error code and if not in the range throws an exception
 */
PHP_METHOD(Phalcon_Http_Message_UploadedFile, checkStream) {

	zend_bool _2$$3;
	zend_long error, ZEPHIR_LAST_CALL_STATUS;
	zval *stream, stream_sub, *error_param = NULL, _0, _1, _3$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &stream, &error_param);

	error = zephir_get_intval(error_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "UPLOAD_ERR_OK");
	ZEPHIR_CALL_FUNCTION(&_1, "constant", NULL, 255, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG_IDENTICAL(&_1, error)) {
		do {
			_2$$3 = 1;
			if (_2$$3 == (Z_TYPE_P(stream) == IS_STRING)) {
				zephir_update_property_zval(this_ptr, SL("fileName"), stream);
				break;
			}
			if (_2$$3 == (1 == Z_TYPE_P(stream) == IS_RESOURCE)) {
				ZEPHIR_INIT_VAR(&_3$$5);
				object_init_ex(&_3$$5, phalcon_http_message_stream_ce);
				ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 222, stream);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, SL("stream"), &_3$$5);
				break;
			}
			if (_2$$3 == (zephir_is_instance_of(stream, SL("Psr\\Http\\Message\\StreamInterface") TSRMLS_CC))) {
				zephir_update_property_zval(this_ptr, SL("stream"), stream);
				break;
			}
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_ce, "Invalid stream or file passed", "phalcon/Http/Message/UploadedFile.zep", 276);
			return;
		} while(0);

	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a description string depending on the upload error code passed
 */
PHP_METHOD(Phalcon_Http_Message_UploadedFile, getErrorDescription) {

	zval *error_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7, _8;
	zend_long error, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &error_param);

	error = zephir_get_intval(error_param);


	do {
		ZEPHIR_INIT_VAR(&_0);
		ZVAL_STRING(&_0, "UPLOAD_ERR_OK");
		ZEPHIR_CALL_FUNCTION(&_1, "constant", NULL, 255, &_0);
		zephir_check_call_status();
		if (ZEPHIR_IS_LONG(&_1, error)) {
			RETURN_MM_STRING("There is no error, the file uploaded with success.");
		}
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "UPLOAD_ERR_INI_SIZE");
		ZEPHIR_CALL_FUNCTION(&_2, "constant", NULL, 255, &_0);
		zephir_check_call_status();
		if (ZEPHIR_IS_LONG(&_2, error)) {
			RETURN_MM_STRING("The uploaded file exceeds the upload_max_filesize directive in php.ini.");
		}
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "UPLOAD_ERR_FORM_SIZE");
		ZEPHIR_CALL_FUNCTION(&_3, "constant", NULL, 255, &_0);
		zephir_check_call_status();
		if (ZEPHIR_IS_LONG(&_3, error)) {
			RETURN_MM_STRING("The uploaded file exceeds the MAX_FILE_SIZE directive that was specified in the HTML form.");
		}
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "UPLOAD_ERR_PARTIAL");
		ZEPHIR_CALL_FUNCTION(&_4, "constant", NULL, 255, &_0);
		zephir_check_call_status();
		if (ZEPHIR_IS_LONG(&_4, error)) {
			RETURN_MM_STRING("The uploaded file was only partially uploaded.");
		}
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "UPLOAD_ERR_NO_FILE");
		ZEPHIR_CALL_FUNCTION(&_5, "constant", NULL, 255, &_0);
		zephir_check_call_status();
		if (ZEPHIR_IS_LONG(&_5, error)) {
			RETURN_MM_STRING("No file was uploaded.");
		}
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "UPLOAD_ERR_NO_TMP_DIR");
		ZEPHIR_CALL_FUNCTION(&_6, "constant", NULL, 255, &_0);
		zephir_check_call_status();
		if (ZEPHIR_IS_LONG(&_6, error)) {
			RETURN_MM_STRING("Missing a temporary folder.");
		}
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "UPLOAD_ERR_CANT_WRITE");
		ZEPHIR_CALL_FUNCTION(&_7, "constant", NULL, 255, &_0);
		zephir_check_call_status();
		if (ZEPHIR_IS_LONG(&_7, error)) {
			RETURN_MM_STRING("Failed to write file to disk.");
		}
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "UPLOAD_ERR_EXTENSION");
		ZEPHIR_CALL_FUNCTION(&_8, "constant", NULL, 255, &_0);
		zephir_check_call_status();
		if (ZEPHIR_IS_LONG(&_8, error)) {
			RETURN_MM_STRING("A PHP extension stopped the file upload.");
		}
	} while(0);

	RETURN_MM_STRING("Unknown upload error");

}

/**
 * Store a file in the new location (stream)
 */
PHP_METHOD(Phalcon_Http_Message_UploadedFile, storeFile) {

	zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *targetPath_param = NULL, data, handle, stream, _0, _1, _3$$3;
	zval targetPath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&targetPath);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&handle);
	ZVAL_UNDEF(&stream);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &targetPath_param);

	zephir_get_strval(&targetPath, targetPath_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "w+b");
	ZEPHIR_CALL_FUNCTION(&handle, "fopen", NULL, 58, &targetPath, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&stream, this_ptr, "getstream", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &stream, "rewind", NULL, 0);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_1, &stream, "eof", &_2, 0);
		zephir_check_call_status();
		if (!(!ZEPHIR_IS_TRUE_IDENTICAL(&_1))) {
			break;
		}
		ZVAL_LONG(&_3$$3, 2048);
		ZEPHIR_CALL_METHOD(&data, &stream, "read", &_4, 0, &_3$$3);
		zephir_check_call_status();
		zephir_fwrite(NULL, &handle, &data TSRMLS_CC);
	}
	zephir_fclose(&handle TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

