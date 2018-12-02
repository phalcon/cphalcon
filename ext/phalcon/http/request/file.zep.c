
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

	

	RETURN_MEMBER(getThis(), "_error");

}

/**
 */
PHP_METHOD(Phalcon_Http_Request_File, getKey) {

	

	RETURN_MEMBER(getThis(), "_key");

}

/**
 */
PHP_METHOD(Phalcon_Http_Request_File, getExtension) {

	

	RETURN_MEMBER(getThis(), "_extension");

}

/**
 * Phalcon\Http\Request\File constructor
 */
PHP_METHOD(Phalcon_Http_Request_File, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *key = NULL, *name = NULL, *tempName = NULL, *size = NULL, *type = NULL, *error = NULL, _0$$3, *_1$$3 = NULL, _2$$4, *_3$$4 = NULL;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &file_param, &key);

	file = file_param;
	if (!key) {
		key = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(name);
	if (zephir_array_isset_string_fetch(&name, file, SS("name"), 0 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_name"), name TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_STRING(&_0$$3, "PATHINFO_EXTENSION", 0);
		ZEPHIR_CALL_FUNCTION(&_1$$3, "defined", NULL, 37, &_0$$3);
		zephir_check_call_status();
		if (zephir_is_true(_1$$3)) {
			ZEPHIR_SINIT_VAR(_2$$4);
			ZVAL_LONG(&_2$$4, 4);
			ZEPHIR_CALL_FUNCTION(&_3$$4, "pathinfo", NULL, 78, name, &_2$$4);
			zephir_check_call_status();
			zephir_update_property_this(getThis(), SL("_extension"), _3$$4 TSRMLS_CC);
		}
	}
	if (zephir_array_isset_string_fetch(&tempName, file, SS("tmp_name"), 1 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_tmp"), tempName TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&size, file, SS("size"), 1 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_size"), size TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&type, file, SS("type"), 1 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_type"), type TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&error, file, SS("error"), 1 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_error"), error TSRMLS_CC);
	}
	if (zephir_is_true(key)) {
		zephir_update_property_this(getThis(), SL("_key"), key TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the file size of the uploaded file
 */
PHP_METHOD(Phalcon_Http_Request_File, getSize) {

	

	RETURN_MEMBER(getThis(), "_size");

}

/**
 * Returns the real name of the uploaded file
 */
PHP_METHOD(Phalcon_Http_Request_File, getName) {

	

	RETURN_MEMBER(getThis(), "_name");

}

/**
 * Returns the temporary name of the uploaded file
 */
PHP_METHOD(Phalcon_Http_Request_File, getTempName) {

	

	RETURN_MEMBER(getThis(), "_tmp");

}

/**
 * Returns the mime type reported by the browser
 * This mime type is not completely secure, use getRealType() instead
 */
PHP_METHOD(Phalcon_Http_Request_File, getType) {

	

	RETURN_MEMBER(getThis(), "_type");

}

/**
 * Gets the real mime type of the upload file using finfo
 */
PHP_METHOD(Phalcon_Http_Request_File, getRealType) {

	zval *finfo = NULL, *mime = NULL, _0, *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 16);
	ZEPHIR_CALL_FUNCTION(&finfo, "finfo_open", NULL, 255, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(finfo) != IS_RESOURCE) {
		RETURN_MM_STRING("", 1);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_tmp"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&mime, "finfo_file", NULL, 256, finfo, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "finfo_close", NULL, 257, finfo);
	zephir_check_call_status();
	RETURN_CCTOR(mime);

}

/**
 * Checks whether the file has been uploaded via Post.
 */
PHP_METHOD(Phalcon_Http_Request_File, isUploadedFile) {

	zend_bool _0;
	zval *tmp = NULL, *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&tmp, this_ptr, "gettempname", NULL, 0);
	zephir_check_call_status();
	_0 = Z_TYPE_P(tmp) == IS_STRING;
	if (_0) {
		ZEPHIR_CALL_FUNCTION(&_1, "is_uploaded_file", NULL, 258, tmp);
		zephir_check_call_status();
		_0 = zephir_is_true(_1);
	}
	RETURN_MM_BOOL(_0);

}

/**
 * Moves the temporary file to a destination within the application
 */
PHP_METHOD(Phalcon_Http_Request_File, moveTo) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *destination_param = NULL, *_0;
	zval *destination = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &destination_param);

	if (UNEXPECTED(Z_TYPE_P(destination_param) != IS_STRING && Z_TYPE_P(destination_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'destination' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(destination_param) == IS_STRING)) {
		zephir_get_strval(destination, destination_param);
	} else {
		ZEPHIR_INIT_VAR(destination);
		ZVAL_EMPTY_STRING(destination);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_tmp"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("move_uploaded_file", NULL, 259, _0, destination);
	zephir_check_call_status();
	RETURN_MM();

}

