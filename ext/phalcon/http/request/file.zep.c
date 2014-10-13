
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


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Http\Request\File
 *
 * Provides OO wrappers to the $_FILES superglobal
 *
 *<code>
 *	class PostsController extends \Phalcon\Mvc\Controller
 *	{
 *
 *		public function uploadAction()
 *		{
 *			//Check if the user has uploaded files
 *			if ($this->request->hasFiles() == true) {
 *				//Print the real file names and their sizes
 *				foreach ($this->request->getUploadedFiles() as $file){
 *					echo $file->getName(), " ", $file->getSize(), "\n";
 *				}
 *			}
 *		}
 *
 *	}
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Request_File) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Request, File, phalcon, http_request_file, phalcon_http_request_file_method_entry, 0);

	zend_declare_property_null(phalcon_http_request_file_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_http_request_file_ce, SL("_tmp"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_http_request_file_ce, SL("_size"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_http_request_file_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_http_request_file_ce, SL("_realType"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_http_request_file_ce, SL("_error"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_http_request_file_ce, SL("_key"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_http_request_file_ce, SL("_extension"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_http_request_file_ce TSRMLS_CC, 1, phalcon_http_request_fileinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Http_Request_File, getError) {


	RETURN_MEMBER(this_ptr, "_error");

}

PHP_METHOD(Phalcon_Http_Request_File, getKey) {


	RETURN_MEMBER(this_ptr, "_key");

}

PHP_METHOD(Phalcon_Http_Request_File, getExtension) {


	RETURN_MEMBER(this_ptr, "_extension");

}

/**
 * Phalcon\Http\Request\File constructor
 *
 * @param array file
 */
PHP_METHOD(Phalcon_Http_Request_File, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL;
	zval *file_param = NULL, *key = NULL, *name, *tempName, *size, *type, *error, _0 = zval_used_for_init, *_1 = NULL, *_3 = NULL;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &file_param, &key);

	if (unlikely(Z_TYPE_P(file_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		file = file_param;

	if (!key) {
		key = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(name);
	if (zephir_array_isset_string_fetch(&name, file, SS("name"), 0 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_LONG(&_0, 4);
		ZEPHIR_CALL_FUNCTION(&_1, "defined", &_2, &_0);
		zephir_check_call_status();
		if (zephir_is_true(_1)) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, 4);
			ZEPHIR_CALL_FUNCTION(&_3, "pathinfo", &_4, name, &_0);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_extension"), _3 TSRMLS_CC);
		}
	}
	if (zephir_array_isset_string_fetch(&tempName, file, SS("tmp_name"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_tmp"), tempName TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&size, file, SS("size"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_size"), size TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&type, file, SS("type"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&error, file, SS("error"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_error"), error TSRMLS_CC);
	}
	if (zephir_is_true(key)) {
		zephir_update_property_this(this_ptr, SL("_key"), key TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the file size of the uploaded file
 *
 * @return int
 */
PHP_METHOD(Phalcon_Http_Request_File, getSize) {


	RETURN_MEMBER(this_ptr, "_size");

}

/**
 * Returns the real name of the uploaded file
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request_File, getName) {


	RETURN_MEMBER(this_ptr, "_name");

}

/**
 * Returns the temporal name of the uploaded file
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request_File, getTempName) {


	RETURN_MEMBER(this_ptr, "_tmp");

}

/**
 * Returns the mime type reported by the browser
 * This mime type is not completely secure, use getRealType() instead
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request_File, getType) {


	RETURN_MEMBER(this_ptr, "_type");

}

/**
 * Gets the real mime type of the upload file using finfo
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request_File, getRealType) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *finfo = NULL, *mime = NULL, _0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 16);
	ZEPHIR_CALL_FUNCTION(&finfo, "finfo_open", NULL, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(finfo) != IS_RESOURCE) {
		RETURN_MM_STRING("", 1);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_tmp"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&mime, "finfo_file", NULL, finfo, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "finfo_close", NULL, finfo);
	zephir_check_call_status();
	RETURN_CCTOR(mime);

}

/**
 * Checks whether the file has been uploaded via Post.
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request_File, isUploadedFile) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *tmp = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&tmp, this_ptr, "gettempname",  NULL);
	zephir_check_call_status();
	_0 = Z_TYPE_P(tmp) == IS_STRING;
	if (_0) {
		ZEPHIR_CALL_FUNCTION(&_1, "is_uploaded_file", &_2, tmp);
		zephir_check_call_status();
		_0 = zephir_is_true(_1);
	}
	if (_0) {
		RETURN_MM_BOOL(1);
	} else {
		RETURN_MM_BOOL(0);
	}

}

/**
 * Moves the temporary file to a destination within the application
 *
 * @param string destination
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request_File, moveTo) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *destination_param = NULL, *_0;
	zval *destination = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &destination_param);

	if (unlikely(Z_TYPE_P(destination_param) != IS_STRING && Z_TYPE_P(destination_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'destination' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(destination_param) == IS_STRING)) {
		destination = destination_param;
	} else {
		ZEPHIR_INIT_VAR(destination);
		ZVAL_EMPTY_STRING(destination);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_tmp"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("move_uploaded_file", &_1, _0, destination);
	zephir_check_call_status();
	RETURN_MM();

}

