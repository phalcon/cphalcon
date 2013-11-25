
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
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

	zend_class_implements(phalcon_http_request_file_ce TSRMLS_CC, 1, phalcon_http_request_fileinterface_ce);

	return SUCCESS;

}

/**
 * Phalcon\Http\Request\File constructor
 *
 * @param array file
 */
PHP_METHOD(Phalcon_Http_Request_File, __construct) {

	zval *file, *name, *tempName, *size, *type;

	zephir_fetch_params(0, 1, 0, &file);



	if ((Z_TYPE_P(file) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_http_request_exception_ce, "Phalcon\\Http\\Request\\File requires a valid uploaded file");
		return;
	}
	if (zephir_array_isset_string_fetch(&name, file, SS("name"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
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

	zval *finfo, *mime, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(finfo);
	zephir_call_func_p1(finfo, "finfo_open", ZEPHIR_GLOBAL(global_null));
	if ((Z_TYPE_P(finfo) != IS_RESOURCE)) {
		RETURN_MM_STRING("", 1);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_tmp"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(mime);
	zephir_call_func_p2(mime, "finfo_file", finfo, _0);
	zephir_call_func_p1_noret("fclose", finfo);
	RETURN_CCTOR(mime);

}

/**
 * Moves the temporary file to a destination within the application
 *
 * @param string destination
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request_File, moveTo) {

	zval *destination_param = NULL, *_0;
	zval *destination = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &destination_param);

		if (Z_TYPE_P(destination_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'destination' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		destination = destination_param;



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_tmp"), PH_NOISY_CC);
	zephir_call_func_p2(return_value, "move_uploaded_file", _0, destination);
	RETURN_MM();

}

