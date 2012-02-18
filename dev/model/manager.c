
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

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/debug.h"
#include "kernel/assert.h"
#include "kernel/array.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

/**
 * Php_Model_Manager
 *
 * Manages creation of models inside application
 */

/**
 * Constructor for Php_Model_Manager
     * 
 */
PHP_METHOD(Phalcon_Model_Manager, __construct){

	zval *a0 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Model_Manager", "__construct", 0);
	phalcon_step_over("Phalcon_Model_Manager::__construct (FunctionCall) File=Library/Phalcon/Model/Manager.php Line=38");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	//$this
	{
		zval *orig_ptr = a0;
		if (Z_REFCOUNT_P(orig_ptr) > 1) {
			Z_DELREF_P(orig_ptr);
			ALLOC_ZVAL(a0);
			*a0 = *orig_ptr;
			zval_copy_ctor(a0);
			Z_SET_REFCOUNT_P(a0, 1);
			Z_UNSET_ISREF_P(a0);
		}
	}
	add_next_index_zval(a0, this_ptr);
	add_next_index_string(a0, "autoload", 1);
	Z_ADDREF_P(a0);
	p0[0] = a0;
	phalcon_debug_param(a0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_NORETURN("spl_autoload_register", 1, p0);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Manager::__construct (Method) File=Library/Phalcon/Model/Manager.php Line=41");
}

PHP_METHOD(Phalcon_Model_Manager, setMetaData){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Manager", "setMetaData", 0);
	phalcon_step_over("Phalcon_Model_Manager::setMetaData (Assignment) File=Library/Phalcon/Model/Manager.php Line=42");
	//$metadata
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_metadata", strlen("_metadata"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Manager::setMetaData (Method) File=Library/Phalcon/Model/Manager.php Line=45");
}

PHP_METHOD(Phalcon_Model_Manager, getMetaData){

	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;

	phalcon_step_into_entry("Phalcon_Model_Manager", "getMetaData", 0);
	phalcon_step_over("Phalcon_Model_Manager::getMetaData (If) File=Library/Phalcon/Model/Manager.php Line=46");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_metadata", sizeof("_metadata")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (!zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Model_Manager::getMetaData (Block) File=Library/Phalcon/Model/Manager.php Line=46");
		phalcon_step_over("Phalcon_Model_Manager::getMetaData (Assignment) File=Library/Phalcon/Model/Manager.php Line=47");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_model_metadata_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, i0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_metadata", strlen("_metadata"), copy TSRMLS_CC);
		}
	}
	//$this
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_metadata", sizeof("_metadata")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t1);
	phalcon_debug_vdump("Returning > ", t1 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t1) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t1);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t1);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Manager::getMetaData (Method) File=Library/Phalcon/Model/Manager.php Line=55");
}

/**
 * Sets/Changes the models directory
 */
PHP_METHOD(Phalcon_Model_Manager, setModelsDir){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Manager", "setModelsDir", 0);
	phalcon_step_over("Phalcon_Model_Manager::setModelsDir (Assignment) File=Library/Phalcon/Model/Manager.php Line=56");
	//$modelsDir
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_modelsDir", strlen("_modelsDir"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Manager::setModelsDir (Method) File=Library/Phalcon/Model/Manager.php Line=62");
}

/**
 * Gets active models directory
 */
PHP_METHOD(Phalcon_Model_Manager, getModelsDir){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Model_Manager", "getModelsDir", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_modelsDir", sizeof("_modelsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t0) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Manager::getModelsDir (Method) File=Library/Phalcon/Model/Manager.php Line=69");
}

PHP_METHOD(Phalcon_Model_Manager, isModel){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Manager", "isModel", 0);
	phalcon_step_over("Phalcon_Model_Manager::isModel (If) File=Library/Phalcon/Model/Manager.php Line=70");
	t0 = zend_read_static_property(phalcon_model_manager_class_entry, "_models", sizeof("_models")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	//$modelName
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_array_fetch(t1, t0, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
	if (zend_is_true(t1)) {
		phalcon_step_over("Phalcon_Model_Manager::isModel (Block) File=Library/Phalcon/Model/Manager.php Line=70");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Model_Manager::isModel (Block) File=Library/Phalcon/Model/Manager.php Line=72");
		phalcon_step_over("Phalcon_Model_Manager::isModel (If) File=Library/Phalcon/Model/Manager.php Line=73");
		PHALCON_ALLOC_ZVAL(r0);
		//$modelName
		Z_ADDREF_P(v0);
		p0[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		PHALCON_PARAM_BOOL(p0[1], 0);
		PHALCON_CALL_FUNC_PARAMS(r0, "class_exists", 2, p0);
		phalcon_debug_vdump("class_exists > ", r0 TSRMLS_CC);
		if (!zend_is_true(r0)) {
			phalcon_step_over("Phalcon_Model_Manager::isModel (Block) File=Library/Phalcon/Model/Manager.php Line=73");
			phalcon_step_over("Phalcon_Model_Manager::isModel (Assignment) File=Library/Phalcon/Model/Manager.php Line=74");
			//$modelPath
			//$this
			PHALCON_ALLOC_ZVAL(t2);
			phalcon_read_property(t2, this_ptr, "_modelsDir", sizeof("_modelsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t2);
			//$modelName
			PHALCON_ALLOC_ZVAL(r1);
			concat_function(r1, t2, v0 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r2);
			phalcon_concat_right(r2, r1, ".php" TSRMLS_CC);
			if (v1) {
				Z_DELREF_P(v1);
				if (!Z_REFCOUNT_P(v1)) {
					FREE_ZVAL(v1);
				}
			}
			Z_ADDREF_P(r2);
			v1 = r2;
			phalcon_debug_assign("$modelPath", r2 TSRMLS_CC);
			phalcon_step_over("Phalcon_Model_Manager::isModel (If) File=Library/Phalcon/Model/Manager.php Line=75");
			//$modelPath
			phalcon_debug_vdump("FileExists? > ", v1 TSRMLS_CC);
			if (phalcon_file_exists(v1 TSRMLS_CC) == SUCCESS) {
				phalcon_step_over("Phalcon_Model_Manager::isModel (Block) File=Library/Phalcon/Model/Manager.php Line=75");
				PHALCON_ALLOC_ZVAL(r3);
				//$this
				phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
				phalcon_debug_method_call(this_ptr, "initializemodel" TSRMLS_CC);
				//$modelName
				Z_ADDREF_P(v0);
				p1[0] = v0;
				phalcon_debug_param(v0 TSRMLS_CC);
				PHALCON_CALL_METHOD_PARAMS(r3, this_ptr, "initializemodel", 1, p1, PHALCON_CALL_DEFAULT);
				phalcon_debug_vdump("MethodReturn > ", r3 TSRMLS_CC);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
				phalcon_debug_vdump("Returning > ", r3 TSRMLS_CC);
				phalcon_step_out_entry();
				RETURN_ZVAL(r3, 1, 0);
			} else {
				phalcon_step_over("Phalcon_Model_Manager::isModel (Block) File=Library/Phalcon/Model/Manager.php Line=77");
				phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
				phalcon_step_out_entry();
				RETURN_FALSE;
			}
		} else {
			phalcon_step_over("Phalcon_Model_Manager::isModel (Block) File=Library/Phalcon/Model/Manager.php Line=80");
			phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_TRUE;
		}
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Manager::isModel (Method) File=Library/Phalcon/Model/Manager.php Line=89");
}

/**
 * Initializes model doing instantiation and requiring
 */
PHP_METHOD(Phalcon_Model_Manager, initializeModel){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL };
	zend_class_entry *ce0;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Manager", "initializeModel", 0);
	phalcon_step_over("Phalcon_Model_Manager::initializeModel (If) File=Library/Phalcon/Model/Manager.php Line=90");
	t0 = zend_read_static_property(phalcon_model_manager_class_entry, "_models", sizeof("_models")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	//$modelName
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_array_fetch(t1, t0, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
	if (zend_is_true(t1)) {
		phalcon_step_over("Phalcon_Model_Manager::initializeModel (Block) File=Library/Phalcon/Model/Manager.php Line=90");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Model_Manager::initializeModel (Block) File=Library/Phalcon/Model/Manager.php Line=92");
		phalcon_step_over("Phalcon_Model_Manager::initializeModel (Assignment) File=Library/Phalcon/Model/Manager.php Line=93");
		//$modelPath
		//$this
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, this_ptr, "_modelsDir", sizeof("_modelsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t2);
		//$modelName
		PHALCON_ALLOC_ZVAL(r0);
		concat_function(r0, t2, v0 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_concat_right(r1, r0, ".php" TSRMLS_CC);
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(r1);
		v1 = r1;
		phalcon_debug_assign("$modelPath", r1 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Manager::initializeModel (If) File=Library/Phalcon/Model/Manager.php Line=94");
		//$modelPath
		phalcon_debug_vdump("FileExists? > ", v1 TSRMLS_CC);
		if (phalcon_file_exists(v1 TSRMLS_CC) == SUCCESS) {
			phalcon_step_over("Phalcon_Model_Manager::initializeModel (Block) File=Library/Phalcon/Model/Manager.php Line=94");
			phalcon_step_over("Phalcon_Model_Manager::initializeModel (Require) File=Library/Phalcon/Model/Manager.php Line=95");
			//$modelPath
			phalcon_debug_vdump("Requiring File > ", v1 TSRMLS_CC);
			phalcon_require(v1 TSRMLS_CC);
			if (EG(exception) || EG(exit_status) == 255) {
				return;
			}
			phalcon_step_over("Phalcon_Model_Manager::initializeModel (If) File=Library/Phalcon/Model/Manager.php Line=96");
			PHALCON_ALLOC_ZVAL(r2);
			//$modelName
			Z_ADDREF_P(v0);
			p0[0] = v0;
			phalcon_debug_param(v0 TSRMLS_CC);
			PHALCON_PARAM_BOOL(p0[1], 0);
			PHALCON_CALL_FUNC_PARAMS(r2, "class_exists", 2, p0);
			phalcon_debug_vdump("class_exists > ", r2 TSRMLS_CC);
			if (!zend_is_true(r2)) {
				phalcon_step_over("Phalcon_Model_Manager::initializeModel (Block) File=Library/Phalcon/Model/Manager.php Line=96");
				phalcon_step_over("Phalcon_Model_Manager::initializeModel (Throw) File=Library/Phalcon/Model/Manager.php Line=97");
				PHALCON_ALLOC_ZVAL(i0);
				object_init_ex(i0, phalcon_model_exception_class_entry);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
				phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
				//$modelName
				PHALCON_ALLOC_ZVAL(r3);
				phalcon_concat_both(r3,  "Class \"", v0, "\" was not found on model file" TSRMLS_CC);
				Z_ADDREF_P(r3);
				p1[0] = r3;
				phalcon_debug_param(r3 TSRMLS_CC);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
				zend_throw_exception_object(i0 TSRMLS_CC);
				Z_ADDREF_P(i0);
				return;
			}
			phalcon_step_over("Phalcon_Model_Manager::initializeModel (Assignment) File=Library/Phalcon/Model/Manager.php Line=99");
			//$modelName
			ce0 = zend_fetch_class(Z_STRVAL_P(v0), Z_STRLEN_P(v0), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(i1);
			object_init_ex(i1, ce0);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
			phalcon_debug_method_call(i1, "__construct" TSRMLS_CC);
			//$this
			Z_ADDREF_P(this_ptr);
			p2[0] = this_ptr;
			phalcon_debug_param(this_ptr TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p2, PHALCON_CALL_CHECK);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
			t3 = zend_read_static_property(phalcon_model_manager_class_entry, "_models", sizeof("_models")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			if (Z_TYPE_P(t3) != IS_ARRAY) {
				convert_to_array(t3);
			}
			//$modelName
			phalcon_array_update(t3, v0, i1 TSRMLS_CC);
			zend_update_static_property(phalcon_model_manager_class_entry, "_models", sizeof("_models")-1, t3 TSRMLS_CC);
			
			phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_TRUE;
		} else {
			phalcon_step_over("Phalcon_Model_Manager::initializeModel (Block) File=Library/Phalcon/Model/Manager.php Line=101");
			phalcon_step_over("Phalcon_Model_Manager::initializeModel (Throw) File=Library/Phalcon/Model/Manager.php Line=102");
			PHALCON_ALLOC_ZVAL(i2);
			object_init_ex(i2, phalcon_model_exception_class_entry);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
			phalcon_debug_method_call(i2, "__construct" TSRMLS_CC);
			//$modelName
			PHALCON_ALLOC_ZVAL(r4);
			phalcon_concat_both(r4,  "Class file path for model \"", v0, "\" was not found" TSRMLS_CC);
			Z_ADDREF_P(r4);
			p3[0] = r4;
			phalcon_debug_param(r4 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 1, p3, PHALCON_CALL_CHECK);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
			zend_throw_exception_object(i2 TSRMLS_CC);
			Z_ADDREF_P(i2);
			return;
		}
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Manager::initializeModel (Method) File=Library/Phalcon/Model/Manager.php Line=110");
}

/**
 * Gets/Instantiates model from directory
 */
PHP_METHOD(Phalcon_Model_Manager, getModel){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *p0[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Manager", "getModel", 0);
	phalcon_step_over("Phalcon_Model_Manager::getModel (If) File=Library/Phalcon/Model/Manager.php Line=111");
	t0 = zend_read_static_property(phalcon_model_manager_class_entry, "_models", sizeof("_models")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	//$modelName
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_array_fetch(t1, t0, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
	if (!zend_is_true(t1)) {
		phalcon_step_over("Phalcon_Model_Manager::getModel (Block) File=Library/Phalcon/Model/Manager.php Line=111");
		phalcon_step_over("Phalcon_Model_Manager::getModel (MethodCall) File=Library/Phalcon/Model/Manager.php Line=112");
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "initializemodel" TSRMLS_CC);
		//$modelName
		Z_ADDREF_P(v0);
		p0[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "initializemodel", 1, p0, PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
	}
	t2 = zend_read_static_property(phalcon_model_manager_class_entry, "_models", sizeof("_models")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	//$modelName
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_array_fetch(t3, t2, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t3 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t3) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t3);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t3);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Manager::getModel (Method) File=Library/Phalcon/Model/Manager.php Line=117");
}

PHP_METHOD(Phalcon_Model_Manager, getSource){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Manager", "getSource", 0);
	phalcon_step_over("Phalcon_Model_Manager::getSource (If) File=Library/Phalcon/Model/Manager.php Line=118");
	t0 = zend_read_static_property(phalcon_model_manager_class_entry, "_sourceNames", sizeof("_sourceNames")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	//$modelName
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_array_fetch(t1, t0, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
	if (!zend_is_true(t1)) {
		phalcon_step_over("Phalcon_Model_Manager::getSource (Block) File=Library/Phalcon/Model/Manager.php Line=118");
		phalcon_step_over("Phalcon_Model_Manager::getSource (Assignment) File=Library/Phalcon/Model/Manager.php Line=119");
		PHALCON_ALLOC_ZVAL(r0);
		//$modelName
		Z_ADDREF_P(v0);
		p0[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_utils", "uncamelize", 1, p0);
		phalcon_debug_vdump("StaticReturn > ", r0 TSRMLS_CC);
		t2 = zend_read_static_property(phalcon_model_manager_class_entry, "_sourceNames", sizeof("_sourceNames")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if (Z_TYPE_P(t2) != IS_ARRAY) {
			convert_to_array(t2);
		}
		//$modelName
		phalcon_array_update(t2, v0, r0 TSRMLS_CC);
		zend_update_static_property(phalcon_model_manager_class_entry, "_sourceNames", sizeof("_sourceNames")-1, t2 TSRMLS_CC);
		
	}
	t3 = zend_read_static_property(phalcon_model_manager_class_entry, "_sourceNames", sizeof("_sourceNames")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	//$modelName
	PHALCON_ALLOC_ZVAL(t4);
	phalcon_array_fetch(t4, t3, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t4 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t4) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t4);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t4);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Manager::getSource (Method) File=Library/Phalcon/Model/Manager.php Line=127");
}

/**
 * Gets default connection to database
 */
PHP_METHOD(Phalcon_Model_Manager, getConnection){

	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *i0 = NULL;
	zval *p1[] = { NULL };

	phalcon_step_into_entry("Phalcon_Model_Manager", "getConnection", 0);
	phalcon_step_over("Phalcon_Model_Manager::getConnection (If) File=Library/Phalcon/Model/Manager.php Line=128");
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_STATIC(r0, "phalcon_db_pool", "hasdefaultdescriptor");
	phalcon_debug_vdump("StaticReturn > ", r0 TSRMLS_CC);
	if (!zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Model_Manager::getConnection (Block) File=Library/Phalcon/Model/Manager.php Line=128");
		phalcon_step_over("Phalcon_Model_Manager::getConnection (Throw) File=Library/Phalcon/Model/Manager.php Line=129");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(p1[0]);
		ZVAL_STRING(p1[0], "There is not defined database connection parameters", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	phalcon_step_over("Phalcon_Model_Manager::getConnection (If) File=Library/Phalcon/Model/Manager.php Line=131");
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_CALL_STATIC(r1, "phalcon_transaction_manager", "isautomatic");
	phalcon_debug_vdump("StaticReturn > ", r1 TSRMLS_CC);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Model_Manager::getConnection (Block) File=Library/Phalcon/Model/Manager.php Line=131");
		PHALCON_ALLOC_ZVAL(r2);
		PHALCON_ALLOC_ZVAL(r3);
		PHALCON_CALL_STATIC(r3, "phalcon_transaction_manager", "get");
		phalcon_debug_vdump("StaticReturn > ", r3 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
		phalcon_debug_method_call(r3, "getconnection" TSRMLS_CC);
		PHALCON_CALL_METHOD(r2, r3, "getconnection", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r2 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r2 TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_ZVAL(r2, 1, 0);
	} else {
		phalcon_step_over("Phalcon_Model_Manager::getConnection (Block) File=Library/Phalcon/Model/Manager.php Line=133");
		PHALCON_ALLOC_ZVAL(r4);
		PHALCON_CALL_STATIC(r4, "phalcon_db_pool", "getconnection");
		phalcon_debug_vdump("StaticReturn > ", r4 TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r4 TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_ZVAL(r4, 1, 0);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Manager::getConnection (Method) File=Library/Phalcon/Model/Manager.php Line=143");
}

/**
 * Autoload function for model lazy loading
 *
 * @param string $className
 */
PHP_METHOD(Phalcon_Model_Manager, autoload){

	zval *v0 = NULL;
	zval *p0[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Manager", "autoload", 0);
	phalcon_step_over("Phalcon_Model_Manager::autoload (MethodCall) File=Library/Phalcon/Model/Manager.php Line=144");
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "ismodel" TSRMLS_CC);
	//$className
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "ismodel", 1, p0, PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
}

