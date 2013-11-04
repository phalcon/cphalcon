
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "main/SAPI.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/string.h"

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


/**
 * Phalcon\Http\Request\File initializer
 */
PHALCON_INIT_CLASS(Phalcon_Http_Request_File){

	PHALCON_REGISTER_CLASS(Phalcon\\Http\\Request, File, http_request_file, phalcon_http_request_file_method_entry, 0);

	zend_declare_property_null(phalcon_http_request_file_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_request_file_ce, SL("_tmp"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_request_file_ce, SL("_size"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_request_file_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_request_file_ce, SL("_real_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_request_file_ce, SL("_error"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_request_file_ce, SL("_key"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_http_request_file_ce TSRMLS_CC, 1, phalcon_http_request_fileinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Http\Request\File constructor
 *
 * @param array $file
 */
PHP_METHOD(Phalcon_Http_Request_File, __construct){

	zval *file, *name, *temp_name, *size, *type, *error, *key = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &file, &key);
	
	if (Z_TYPE_P(file) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_http_request_exception_ce, "Phalcon\\Http\\Request\\File requires a valid uploaded file");
		return;
	}
	if (phalcon_array_isset_string(file, SS("name"))) {
		PHALCON_OBS_VAR(name);
		phalcon_array_fetch_string(&name, file, SL("name"), PH_NOISY);
		phalcon_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
	}
	
	if (phalcon_array_isset_string(file, SS("tmp_name"))) {
		PHALCON_OBS_VAR(temp_name);
		phalcon_array_fetch_string(&temp_name, file, SL("tmp_name"), PH_NOISY);
		phalcon_update_property_this(this_ptr, SL("_tmp"), temp_name TSRMLS_CC);
	}
	
	if (phalcon_array_isset_string(file, SS("size"))) {
		PHALCON_OBS_VAR(size);
		phalcon_array_fetch_string(&size, file, SL("size"), PH_NOISY);
		phalcon_update_property_this(this_ptr, SL("_size"), size TSRMLS_CC);
	}
	
	if (phalcon_array_isset_string(file, SS("type"))) {
		PHALCON_OBS_VAR(type);
		phalcon_array_fetch_string(&type, file, SL("type"), PH_NOISY);
		phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	}

	if (phalcon_array_isset_string(file, SS("error"))) {
		PHALCON_OBS_VAR(error);
		phalcon_array_fetch_string(&error, file, SL("error"), PH_NOISY);
		phalcon_update_property_this(this_ptr, SL("_error"), error TSRMLS_CC);
	}

	if (key) {
		phalcon_update_property_this(this_ptr, SL("_key"), key TSRMLS_CC);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Returns the file size of the uploaded file
 *
 * @return int
 */
PHP_METHOD(Phalcon_Http_Request_File, getSize){


	RETURN_MEMBER(this_ptr, "_size");
}

/**
 * Returns the real name of the uploaded file
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request_File, getName){


	RETURN_MEMBER(this_ptr, "_name");
}

/**
 * Returns the temporal name of the uploaded file
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request_File, getTempName){


	RETURN_MEMBER(this_ptr, "_tmp");
}

/**
 * Returns the mime type reported by the browser
 * This mime type is not completely secure, use getRealType() instead
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request_File, getType){


	RETURN_MEMBER(this_ptr, "_type");
}

/**
 * Gets the real mime type of the upload file using finfo
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request_File, getRealType){

	zval *constant, *finfo, *temp_file, *mime;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(mime);
	phalcon_read_property_this(&mime, this_ptr, SL("_real_type"), PH_NOISY_CC);

	if (Z_TYPE_P(mime) == IS_STRING) {
		RETURN_CTOR(mime);
	}

	PHALCON_INIT_VAR(constant);
	if (!zend_get_constant(SL("FILEINFO_MIME_TYPE"), constant TSRMLS_CC)) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(finfo);
	phalcon_call_func_p1(finfo, "finfo_open", constant);

	if (Z_TYPE_P(finfo) != IS_RESOURCE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(temp_file);
	phalcon_read_property_this(&temp_file, this_ptr, SL("_tmp"), PH_NOISY_CC);

	PHALCON_INIT_NVAR(mime);
	phalcon_call_func_p2(mime, "finfo_file", finfo, temp_file);
	phalcon_call_func_p1_noret("finfo_close", finfo);

	RETURN_CTOR(mime);
}

/**
 * Returns the error code
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request_File, getError){


	RETURN_MEMBER(this_ptr, "_error");
}

/**
 * Returns the file key
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request_File, getKey){

	RETURN_MEMBER(this_ptr, "_key");
}

PHP_METHOD(Phalcon_Http_Request_File, isUploadedFile) {

	zval *tmp_name = NULL;

	if (!SG(rfc1867_uploaded_files)) {
		RETURN_FALSE;
	}

	if (phalcon_call_method_params(tmp_name, &tmp_name, getThis(), SL("gettempname"), zend_inline_hash_func(SS("gettempname")) TSRMLS_CC, 0) == SUCCESS) {
		if (Z_TYPE_P(tmp_name) == IS_STRING && zend_hash_exists(SG(rfc1867_uploaded_files), Z_STRVAL_P(tmp_name), Z_STRLEN_P(tmp_name) + 1)) {
			RETVAL_TRUE;
		}
		else {
			RETVAL_FALSE;
		}
	}

	zval_ptr_dtor(&tmp_name);
}

/**
 * Moves the temporary file to a destination within the application
 *
 * @param string $destination
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Request_File, moveTo){

	zval *destination, *temp_file;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &destination);
	
	PHALCON_OBS_VAR(temp_file);
	phalcon_read_property_this(&temp_file, this_ptr, SL("_tmp"), PH_NOISY_CC);
	phalcon_call_func_p2(return_value, "move_uploaded_file", temp_file, destination);
	RETURN_MM();
}

PHP_METHOD(Phalcon_Http_Request_File, __set_state) {

	zval *data;

	phalcon_fetch_params(0, 1, 0, &data);

	object_init_ex(return_value, phalcon_http_request_file_ce);

	PHALCON_MM_GROW();
	phalcon_call_method_p1_noret(return_value, "__construct", data);
	PHALCON_MM_RESTORE();
}
