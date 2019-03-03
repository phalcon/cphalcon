
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Http\Request\File
 *
 * Provides OO wrappers to the $_FILES superglobal
 *
 *<code>
 * use Phalcon\Mvc\Controller;
 *
 * class PostsController extends Controller
 * {
 *     public function uploadAction()
 *     {
 *         // Check if the user has uploaded files
 *         if ($this->request->hasFiles() == true) {
 *             // Print the real file names and their sizes
 *             foreach ($this->request->getUploadedFiles() as $file) {
 *                 echo $file->getName(), " ", $file->getSize(), "\n";
 *             }
 *	       }
 *     }
 * }
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Request_File) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Request, File, phalcon, http_request_file, phalcon_http_request_file_method_entry, 0);

	zend_declare_property_null(phalcon_http_request_file_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_http_request_file_ce, SL("_tmp"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_http_request_file_ce, SL("_size"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_http_request_file_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_http_request_file_ce, SL("_realType"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_http_request_file_ce, SL("_error"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_http_request_file_ce, SL("_key"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_http_request_file_ce, SL("_extension"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_http_request_file_ce TSRMLS_CC, 1, phalcon_http_request_fileinterface_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Phalcon_Http_Request_File, getError) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_error");

}

/**
 */
PHP_METHOD(Phalcon_Http_Request_File, getKey) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_key");

}

/**
 */
PHP_METHOD(Phalcon_Http_Request_File, getExtension) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_extension");

}

/**
 * Phalcon\Http\Request\File constructor
 */
PHP_METHOD(Phalcon_Http_Request_File, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *key = NULL, key_sub, __$null, name, tempName, size, type, error, _0$$3, _1$$3, _2$$4, _3$$4;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&key_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&tempName);
	ZVAL_UNDEF(&size);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &file_param, &key);

	ZEPHIR_OBS_COPY_OR_DUP(&file, file_param);
	if (!key) {
		key = &key_sub;
		key = &__$null;
	}


	ZEPHIR_OBS_VAR(&name);
	if (zephir_array_isset_string_fetch(&name, &file, SL("name"), 0)) {
		zephir_update_property_zval(this_ptr, SL("_name"), &name);
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "PATHINFO_EXTENSION");
		ZEPHIR_CALL_FUNCTION(&_1$$3, "defined", NULL, 228, &_0$$3);
		zephir_check_call_status();
		if (zephir_is_true(&_1$$3)) {
			ZVAL_LONG(&_2$$4, 4);
			ZEPHIR_CALL_FUNCTION(&_3$$4, "pathinfo", NULL, 64, &name, &_2$$4);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("_extension"), &_3$$4);
		}
	}
	if (zephir_array_isset_string_fetch(&tempName, &file, SL("tmp_name"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_tmp"), &tempName);
	}
	if (zephir_array_isset_string_fetch(&size, &file, SL("size"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_size"), &size);
	}
	if (zephir_array_isset_string_fetch(&type, &file, SL("type"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_type"), &type);
	}
	if (zephir_array_isset_string_fetch(&error, &file, SL("error"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_error"), &error);
	}
	if (zephir_is_true(key)) {
		zephir_update_property_zval(this_ptr, SL("_key"), key);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the file size of the uploaded file
 */
PHP_METHOD(Phalcon_Http_Request_File, getSize) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_size");

}

/**
 * Returns the real name of the uploaded file
 */
PHP_METHOD(Phalcon_Http_Request_File, getName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_name");

}

/**
 * Returns the temporary name of the uploaded file
 */
PHP_METHOD(Phalcon_Http_Request_File, getTempName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_tmp");

}

/**
 * Returns the mime type reported by the browser
 * This mime type is not completely secure, use getRealType() instead
 */
PHP_METHOD(Phalcon_Http_Request_File, getType) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_type");

}

/**
 * Gets the real mime type of the upload file using finfo
 */
PHP_METHOD(Phalcon_Http_Request_File, getRealType) {

	zval finfo, mime, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&finfo);
	ZVAL_UNDEF(&mime);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_0, 16);
	ZEPHIR_CALL_FUNCTION(&finfo, "finfo_open", NULL, 229, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&finfo) != IS_RESOURCE) {
		RETURN_MM_STRING("");
	}
	zephir_read_property(&_0, this_ptr, SL("_tmp"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&mime, "finfo_file", NULL, 230, &finfo, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "finfo_close", NULL, 231, &finfo);
	zephir_check_call_status();
	RETURN_CCTOR(&mime);

}

/**
 * Checks whether the file has been uploaded via Post.
 */
PHP_METHOD(Phalcon_Http_Request_File, isUploadedFile) {

	zend_bool _0;
	zval tmp, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&tmp, this_ptr, "gettempname", NULL, 0);
	zephir_check_call_status();
	_0 = Z_TYPE_P(&tmp) == IS_STRING;
	if (_0) {
		ZEPHIR_CALL_FUNCTION(&_1, "is_uploaded_file", NULL, 232, &tmp);
		zephir_check_call_status();
		_0 = zephir_is_true(&_1);
	}
	RETURN_MM_BOOL(_0);

}

/**
 * Moves the temporary file to a destination within the application
 */
PHP_METHOD(Phalcon_Http_Request_File, moveTo) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *destination_param = NULL, _0;
	zval destination;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&destination);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &destination_param);

	if (UNEXPECTED(Z_TYPE_P(destination_param) != IS_STRING && Z_TYPE_P(destination_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'destination' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(destination_param) == IS_STRING)) {
		zephir_get_strval(&destination, destination_param);
	} else {
		ZEPHIR_INIT_VAR(&destination);
		ZVAL_EMPTY_STRING(&destination);
	}


	zephir_read_property(&_0, this_ptr, SL("_tmp"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("move_uploaded_file", NULL, 233, &_0, &destination);
	zephir_check_call_status();
	RETURN_MM();

}

