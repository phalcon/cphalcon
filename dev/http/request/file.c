
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Http\Request\File
 *
 * Provides OO wrappers to the $_FILES superglobal
 *
 *<code>
 *	class PostsController extends \Phalcon\Mvc\Controller
 *	{
 *
 *	public function uploadAction()
 *	{
 *		//Check if the user has uploaded files
 *		if ($this->request->hasFiles() == true) {
 *			//Print the real file names and their sizes
 *			foreach ($this->request->getUploadedFiles() as $file){
 *				echo $file->getName(), " ", $file->getSize(), "\n";
 *			}
 *		}
 *	}
 *
 *}
 *</code>
 */

/**
 * Phalcon\Http\Request\File constructor
 *
 * @param array $file
 */
PHP_METHOD(Phalcon_Http_Request_File, __construct){

	zval *file = NULL, *name = NULL, *temp_name = NULL, *size = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &file) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(file) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_http_request_exception_ce, "Phalcon\\Http\\Request\\File requires a valid uploaded file");
		return;
	}
	eval_int = phalcon_array_isset_string(file, SL("name")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(name);
		phalcon_array_fetch_string(&name, file, SL("name"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_name"), name TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(file, SL("tmp_name")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(temp_name);
		phalcon_array_fetch_string(&temp_name, file, SL("tmp_name"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_tmp"), temp_name TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(file, SL("size")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(size);
		phalcon_array_fetch_string(&size, file, SL("size"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_size"), size TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the file size of the uploaded file
 *
 * @return int
 */
PHP_METHOD(Phalcon_Http_Request_File, getSize){

	zval *size = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(size);
	phalcon_read_property(&size, this_ptr, SL("_size"), PH_NOISY_CC);
	
	RETURN_CCTOR(size);
}

/**
 * Returns the real name of the uploaded file
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request_File, getName){

	zval *name = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(name);
	phalcon_read_property(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	
	RETURN_CCTOR(name);
}

/**
 * Returns the temporal name of the uploaded file
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request_File, getTempName){

	zval *temp_file = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(temp_file);
	phalcon_read_property(&temp_file, this_ptr, SL("_tmp"), PH_NOISY_CC);
	
	RETURN_CCTOR(temp_file);
}

/**
 * Move the temporary file to a destination
 *
 * @param string $destination
 */
PHP_METHOD(Phalcon_Http_Request_File, moveTo){

	zval *destination = NULL, *temp_file = NULL, *success = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &destination) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(temp_file);
	phalcon_read_property(&temp_file, this_ptr, SL("_tmp"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_FUNC_PARAMS_2(success, "move_uploaded_file", temp_file, destination);
	
	RETURN_CCTOR(success);
}

