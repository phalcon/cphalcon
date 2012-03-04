
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
 * Phalcon_Model_Manager
 *
 * Manages the creation of models inside application and their relationships.
 * Phacon_Model_Manager helps to control the creation of models across a request execution.
 *
 * 
 */

/**
 * Constructor for Phalcon_Model_Manager
     *
 */
PHP_METHOD(Phalcon_Model_Manager, __construct){

	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Model_Manager", "::__construct", 0);
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	zend_update_property(phalcon_model_manager_class_entry, this_ptr, "_models", strlen("_models"), a0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	zend_update_property(phalcon_model_manager_class_entry, this_ptr, "_hasMany", strlen("_hasMany"), a1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(a2);
	array_init(a2);
	zend_update_property(phalcon_model_manager_class_entry, this_ptr, "_hasOne", strlen("_hasOne"), a2 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(a3);
	array_init(a3);
	zend_update_property(phalcon_model_manager_class_entry, this_ptr, "_belongsTo", strlen("_belongsTo"), a3 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Manager", "__construct", 0);
	phalcon_step_over("Phalcon_Model_Manager::__construct (FunctionCall) File=/Model/Manager Line=60");
	PHALCON_ALLOC_ZVAL(a4);
	array_init(a4);
	{
		zval *orig_ptr = a4;
		if (Z_REFCOUNT_P(orig_ptr) > 1) {
			Z_DELREF_P(orig_ptr);
			ALLOC_ZVAL(a4);
			*a4 = *orig_ptr;
			zval_copy_ctor(a4);
			Z_SET_REFCOUNT_P(a4, 1);
			Z_UNSET_ISREF_P(a4);
		}
	}
	add_next_index_zval(a4, this_ptr);
	add_next_index_string(a4, "autoload", 1);
	Z_ADDREF_P(a4);
	p0[0] = a4;
	phalcon_debug_param(a4 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_NORETURN("spl_autoload_register", strlen("spl_autoload_register"), 1, p0);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Manager::__construct (Method) File=/Model/Manager Line=68");
}

/**
 * Overwrittes default meta-data manager
 *
 * @param Phalcon_Model_Metadata $metadata
 */
PHP_METHOD(Phalcon_Model_Manager, setMetaData){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Manager", "setMetaData", 0);
	phalcon_step_over("Phalcon_Model_Manager::setMetaData (Assignment) File=/Model/Manager Line=69");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_metadata", strlen("_metadata"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Manager::setMetaData (Method) File=/Model/Manager Line=77");
}

/**
 * Returns active meta-data manager. If not exists any will be created one
 *
 * @return Phalcon_Model_Metadata
 */
PHP_METHOD(Phalcon_Model_Manager, getMetaData){

	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;

	phalcon_step_into_entry("Phalcon_Model_Manager", "getMetaData", 0);
	phalcon_step_over("Phalcon_Model_Manager::getMetaData (If) File=/Model/Manager Line=78");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_metadata", sizeof("_metadata")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Model_Manager::getMetaData (Block) File=/Model/Manager Line=78");
		phalcon_step_over("Phalcon_Model_Manager::getMetaData (Assignment) File=/Model/Manager Line=79");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_model_metadata_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, i0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_metadata", strlen("_metadata"), copy TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_metadata", sizeof("_metadata")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Model_Manager::getMetaData (Method) File=/Model/Manager Line=89");
}

/**
 * Sets the models directory
 *
 * @param string $modelsDir
 */
PHP_METHOD(Phalcon_Model_Manager, setModelsDir){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Manager", "setModelsDir", 0);
	phalcon_step_over("Phalcon_Model_Manager::setModelsDir (Assignment) File=/Model/Manager Line=90");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_modelsDir", strlen("_modelsDir"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Manager::setModelsDir (Method) File=/Model/Manager Line=98");
}

/**
 * Gets active models directory
 *
 * @return string
 */
PHP_METHOD(Phalcon_Model_Manager, getModelsDir){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Model_Manager", "getModelsDir", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_modelsDir", sizeof("_modelsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Model_Manager::getModelsDir (Method) File=/Model/Manager Line=113");
}

/**
 * Checks wheater given name is a existent model
 *
 * 
 *
 * @param string $modelName
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Manager, isModel){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Manager", "isModel", 0);
	phalcon_step_over("Phalcon_Model_Manager::isModel (If) File=/Model/Manager Line=114");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	if (eval_int) {
		phalcon_step_over("Phalcon_Model_Manager::isModel (Block) File=/Model/Manager Line=114");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Model_Manager::isModel (Block) File=/Model/Manager Line=116");
		phalcon_step_over("Phalcon_Model_Manager::isModel (If) File=/Model/Manager Line=117");
		PHALCON_ALLOC_ZVAL(r0);
		Z_ADDREF_P(v0);
		p0[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		PHALCON_PARAM_BOOL(p0[1], 0);
		PHALCON_CALL_FUNC_PARAMS(r0, "class_exists", strlen("class_exists"), 2, p0);
		phalcon_debug_vdump("class_exists > ", r0 TSRMLS_CC);
		if (!zend_is_true(r0)) {
			phalcon_step_over("Phalcon_Model_Manager::isModel (Block) File=/Model/Manager Line=117");
			phalcon_step_over("Phalcon_Model_Manager::isModel (Assignment) File=/Model/Manager Line=118");
			PHALCON_ALLOC_ZVAL(t1);
			phalcon_read_property(t1, this_ptr, "_modelsDir", sizeof("_modelsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r1);
			concat_function(r1, t1, v0 TSRMLS_CC);
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
			phalcon_step_over("Phalcon_Model_Manager::isModel (If) File=/Model/Manager Line=119");
			phalcon_debug_vdump("FileExists? > ", v1 TSRMLS_CC);
			if (phalcon_file_exists(v1 TSRMLS_CC) == SUCCESS) {
				phalcon_step_over("Phalcon_Model_Manager::isModel (Block) File=/Model/Manager Line=119");
				PHALCON_ALLOC_ZVAL(r3);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
				phalcon_debug_method_call(this_ptr, "load" TSRMLS_CC);
				Z_ADDREF_P(v0);
				p1[0] = v0;
				phalcon_debug_param(v0 TSRMLS_CC);
				PHALCON_CALL_METHOD_PARAMS(r3, this_ptr, "load", 1, p1, PHALCON_CALL_DEFAULT);
				phalcon_debug_vdump("MethodReturn > ", r3 TSRMLS_CC);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
				phalcon_debug_vdump("Returning > ", r3 TSRMLS_CC);
				phalcon_step_out_entry();
				RETURN_ZVAL(r3, 1, 0);
			} else {
				phalcon_step_over("Phalcon_Model_Manager::isModel (Block) File=/Model/Manager Line=121");
				phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
				phalcon_step_out_entry();
				RETURN_FALSE;
			}
		} else {
			phalcon_step_over("Phalcon_Model_Manager::isModel (Block) File=/Model/Manager Line=124");
			phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_TRUE;
		}
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Manager::isModel (Method) File=/Model/Manager Line=136");
}

/**
 * Loads a model looking for its file and initializing them
 *
 * @param string $modelName
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Manager, load){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL };
	int eval_int;
	zend_class_entry *ce0;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Manager", "load", 0);
	phalcon_step_over("Phalcon_Model_Manager::load (If) File=/Model/Manager Line=137");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	if (eval_int) {
		phalcon_step_over("Phalcon_Model_Manager::load (Block) File=/Model/Manager Line=137");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Model_Manager::load (Block) File=/Model/Manager Line=139");
		phalcon_step_over("Phalcon_Model_Manager::load (Assignment) File=/Model/Manager Line=140");
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_modelsDir", sizeof("_modelsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r0);
		concat_function(r0, t1, v0 TSRMLS_CC);
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
		phalcon_step_over("Phalcon_Model_Manager::load (If) File=/Model/Manager Line=141");
		phalcon_debug_vdump("FileExists? > ", v1 TSRMLS_CC);
		if (phalcon_file_exists(v1 TSRMLS_CC) == SUCCESS) {
			phalcon_step_over("Phalcon_Model_Manager::load (Block) File=/Model/Manager Line=141");
			phalcon_step_over("Phalcon_Model_Manager::load (Require) File=/Model/Manager Line=142");
			phalcon_debug_vdump("Requiring File > ", v1 TSRMLS_CC);
			phalcon_require(v1 TSRMLS_CC);
			if (EG(exception) || EG(exit_status) == 255) {
				return;
			}
			phalcon_step_over("Phalcon_Model_Manager::load (If) File=/Model/Manager Line=143");
			PHALCON_ALLOC_ZVAL(r2);
			Z_ADDREF_P(v0);
			p0[0] = v0;
			phalcon_debug_param(v0 TSRMLS_CC);
			PHALCON_PARAM_BOOL(p0[1], 0);
			PHALCON_CALL_FUNC_PARAMS(r2, "class_exists", strlen("class_exists"), 2, p0);
			phalcon_debug_vdump("class_exists > ", r2 TSRMLS_CC);
			if (!zend_is_true(r2)) {
				phalcon_step_over("Phalcon_Model_Manager::load (Block) File=/Model/Manager Line=143");
				phalcon_step_over("Phalcon_Model_Manager::load (Throw) File=/Model/Manager Line=144");
				PHALCON_ALLOC_ZVAL(i0);
				object_init_ex(i0, phalcon_model_exception_class_entry);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
				phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
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
			phalcon_step_over("Phalcon_Model_Manager::load (Assignment) File=/Model/Manager Line=146");
			ce0 = zend_fetch_class(Z_STRVAL_P(v0), Z_STRLEN_P(v0), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(i1);
			object_init_ex(i1, ce0);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
			phalcon_debug_method_call(i1, "__construct" TSRMLS_CC);
			Z_ADDREF_P(this_ptr);
			p2[0] = this_ptr;
			phalcon_debug_param(this_ptr TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p2, PHALCON_CALL_CHECK);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(t2);
			phalcon_read_property(t2, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			{
				zval *orig_ptr = t2;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(t2);
					*t2 = *orig_ptr;
					zval_copy_ctor(t2);
					Z_SET_REFCOUNT_P(t2, 1);
					Z_UNSET_ISREF_P(t2);
				}
			}
			phalcon_array_update(t2, v0, i1 TSRMLS_CC);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, t2, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_models", strlen("_models"), copy TSRMLS_CC);
			}
			phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_TRUE;
		} else {
			phalcon_step_over("Phalcon_Model_Manager::load (Block) File=/Model/Manager Line=148");
			phalcon_step_over("Phalcon_Model_Manager::load (Throw) File=/Model/Manager Line=149");
			PHALCON_ALLOC_ZVAL(i2);
			object_init_ex(i2, phalcon_model_exception_class_entry);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
			phalcon_debug_method_call(i2, "__construct" TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Model_Manager::load (Method) File=/Model/Manager Line=165");
}

/**
 * Gets/Instantiates model from directory
 *
 * 
 *
 * @param string $modelName
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Manager, getModel){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Manager", "getModel", 0);
	phalcon_step_over("Phalcon_Model_Manager::getModel (If) File=/Model/Manager Line=166");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Model_Manager::getModel (Block) File=/Model/Manager Line=166");
		phalcon_step_over("Phalcon_Model_Manager::getModel (MethodCall) File=/Model/Manager Line=167");
		phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "load" TSRMLS_CC);
		Z_ADDREF_P(v0);
		p0[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "load", 1, p0, PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_array_fetch(r0, t1, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(r0) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(r0);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(r0);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Manager::getModel (Method) File=/Model/Manager Line=178");
}

/**
 * Gets the posibly source model name from its class name
 *
 * @param string $modelName
 * @return boolean
 */
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
	phalcon_step_over("Phalcon_Model_Manager::getSource (If) File=/Model/Manager Line=179");
	t0 = zend_read_static_property(phalcon_model_manager_class_entry, "_sourceNames", sizeof("_sourceNames")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_array_fetch(t1, t0, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
	if (!zend_is_true(t1)) {
		phalcon_step_over("Phalcon_Model_Manager::getSource (Block) File=/Model/Manager Line=179");
		phalcon_step_over("Phalcon_Model_Manager::getSource (Assignment) File=/Model/Manager Line=180");
		PHALCON_ALLOC_ZVAL(r0);
		Z_ADDREF_P(v0);
		p0[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_utils", "uncamelize", 1, p0);
		phalcon_debug_vdump("StaticReturn > ", r0 TSRMLS_CC);
		t2 = zend_read_static_property(phalcon_model_manager_class_entry, "_sourceNames", sizeof("_sourceNames")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if (Z_TYPE_P(t2) != IS_ARRAY) {
			convert_to_array(t2);
		}
		phalcon_array_update(t2, v0, r0 TSRMLS_CC);
		zend_update_static_property(phalcon_model_manager_class_entry, "_sourceNames", sizeof("_sourceNames")-1, t2 TSRMLS_CC);
		
	}
	t3 = zend_read_static_property(phalcon_model_manager_class_entry, "_sourceNames", sizeof("_sourceNames")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Model_Manager::getSource (Method) File=/Model/Manager Line=190");
}

/**
 * Gets default connection to database. All models by default will use connection returned by this method
 *
 * @return Phalcon_Db
 */
PHP_METHOD(Phalcon_Model_Manager, getConnection){

	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *i0 = NULL;
	zval *p1[] = { NULL };

	phalcon_step_into_entry("Phalcon_Model_Manager", "getConnection", 0);
	phalcon_step_over("Phalcon_Model_Manager::getConnection (If) File=/Model/Manager Line=191");
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_STATIC(r0, "phalcon_db_pool", "hasdefaultdescriptor");
	phalcon_debug_vdump("StaticReturn > ", r0 TSRMLS_CC);
	if (!zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Model_Manager::getConnection (Block) File=/Model/Manager Line=191");
		phalcon_step_over("Phalcon_Model_Manager::getConnection (Throw) File=/Model/Manager Line=192");
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
	phalcon_step_over("Phalcon_Model_Manager::getConnection (If) File=/Model/Manager Line=194");
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_CALL_STATIC(r1, "phalcon_transaction_manager", "isautomatic");
	phalcon_debug_vdump("StaticReturn > ", r1 TSRMLS_CC);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Model_Manager::getConnection (Block) File=/Model/Manager Line=194");
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
		phalcon_step_over("Phalcon_Model_Manager::getConnection (Block) File=/Model/Manager Line=196");
		PHALCON_ALLOC_ZVAL(r4);
		PHALCON_CALL_STATIC(r4, "phalcon_db_pool", "getconnection");
		phalcon_debug_vdump("StaticReturn > ", r4 TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r4 TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_ZVAL(r4, 1, 0);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Manager::getConnection (Method) File=/Model/Manager Line=209");
}

/**
 * Setup a 1-1 relation between two models
 * 
 * @param Phalcon_Model_Base $model
 * @parammixed $fields
 * @paramstring $referenceModel
 * @parammixed $referencedFields 
 */
PHP_METHOD(Phalcon_Model_Manager, addHasOne){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v2 > ", v2 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v3 > ", v3 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Manager", "addHasOne", 0);
	phalcon_step_over("Phalcon_Model_Manager::addHasOne (Assignment) File=/Model/Manager Line=210");
	PHALCON_ALLOC_ZVAL(r0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "get_class", strlen("get_class"), 1, p0);
	phalcon_debug_vdump("get_class > ", r0 TSRMLS_CC);
	if (v4) {
		Z_DELREF_P(v4);
		if (!Z_REFCOUNT_P(v4)) {
			FREE_ZVAL(v4);
		}
	}
	Z_ADDREF_P(r0);
	v4 = r0;
	phalcon_debug_assign("$entityName", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Manager::addHasOne (If) File=/Model/Manager Line=211");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v4);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Model_Manager::addHasOne (Block) File=/Model/Manager Line=211");
		phalcon_step_over("Phalcon_Model_Manager::addHasOne (Assignment) File=/Model/Manager Line=212");
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		{
			zval *orig_ptr = t1;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				Z_DELREF_P(orig_ptr);
				ALLOC_ZVAL(t1);
				*t1 = *orig_ptr;
				zval_copy_ctor(t1);
				Z_SET_REFCOUNT_P(t1, 1);
				Z_UNSET_ISREF_P(t1);
			}
		}
		phalcon_array_update(t1, v4, a0 TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, t1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_hasOne", strlen("_hasOne"), copy TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Model_Manager::addHasOne (If) File=/Model/Manager Line=214");
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
	phalcon_array_fetch(r1, t2, v4, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(r1, v2);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Model_Manager::addHasOne (Block) File=/Model/Manager Line=214");
		phalcon_step_over("Phalcon_Model_Manager::addHasOne (If) File=/Model/Manager Line=215");
		if (Z_TYPE_P(v3) == IS_ARRAY) { 
			phalcon_step_over("Phalcon_Model_Manager::addHasOne (Block) File=/Model/Manager Line=215");
			phalcon_step_over("Phalcon_Model_Manager::addHasOne (If) File=/Model/Manager Line=216");
			PHALCON_ALLOC_ZVAL(r2);
			p1[0] = v1;
			phalcon_debug_param(v1 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r2, "count", strlen("count"), 1, p1);
			phalcon_debug_vdump("count > ", r2 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r3);
			p2[0] = v3;
			phalcon_debug_param(v3 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r3, "count", strlen("count"), 1, p2);
			phalcon_debug_vdump("count > ", r3 TSRMLS_CC);
			PHALCON_NOT_EQUAL_FUNCTION(r4, r2, r3);
			if (zend_is_true(r4)) {
				phalcon_step_over("Phalcon_Model_Manager::addHasOne (Block) File=/Model/Manager Line=216");
				phalcon_step_over("Phalcon_Model_Manager::addHasOne (Throw) File=/Model/Manager Line=217");
				PHALCON_ALLOC_ZVAL(i0);
				object_init_ex(i0, phalcon_model_exception_class_entry);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
				phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(p3[0]);
				ZVAL_STRING(p3[0], "Number of referenced fields are not the same", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p3, PHALCON_CALL_CHECK);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
				zend_throw_exception_object(i0 TSRMLS_CC);
				Z_ADDREF_P(i0);
				return;
			}
		}
		phalcon_step_over("Phalcon_Model_Manager::addHasOne (Assignment) File=/Model/Manager Line=220");
		PHALCON_ALLOC_ZVAL(a1);
		array_init(a1);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			{
				zval *orig_ptr = a1;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a1);
					*a1 = *orig_ptr;
					zval_copy_ctor(a1);
					Z_SET_REFCOUNT_P(a1, 1);
					Z_UNSET_ISREF_P(a1);
				}
			}
			add_assoc_zval(a1, "fi", copy);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v2, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			{
				zval *orig_ptr = a1;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a1);
					*a1 = *orig_ptr;
					zval_copy_ctor(a1);
					Z_SET_REFCOUNT_P(a1, 1);
					Z_UNSET_ISREF_P(a1);
				}
			}
			add_assoc_zval(a1, "rt", copy);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v3, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			{
				zval *orig_ptr = a1;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a1);
					*a1 = *orig_ptr;
					zval_copy_ctor(a1);
					Z_SET_REFCOUNT_P(a1, 1);
					Z_UNSET_ISREF_P(a1);
				}
			}
			add_assoc_zval(a1, "rf", copy);
		}
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_read_property(t3, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(t3) == IS_ARRAY) {
			PHALCON_ALLOC_ZVAL(t4);
			phalcon_array_fetch(t4, t3, v4, PHALCON_SILENT_FETCH TSRMLS_CC);
		}
		if (Z_TYPE_P(t4) != IS_ARRAY) {
			convert_to_array(t4);
			phalcon_array_update(t3, v4, t4 TSRMLS_CC);
			Z_ADDREF_P(t4);
		}
		phalcon_array_update(t4, v2, a1 TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, t3, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_hasOne", strlen("_hasOne"), copy TSRMLS_CC);
		}
	} else {
		phalcon_step_over("Phalcon_Model_Manager::addHasOne (Block) File=/Model/Manager Line=225");
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Manager::addHasOne (Method) File=/Model/Manager Line=238");
}

/**
 * Setup a relation reverse 1-1  between two models
 * 
 * @param Phalcon_Model_Base $model
 * @parammixed $fields
 * @paramstring $referenceModel
 * @parammixed $referencedFields 
 */
PHP_METHOD(Phalcon_Model_Manager, addBelongsTo){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v2 > ", v2 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v3 > ", v3 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Manager", "addBelongsTo", 0);
	phalcon_step_over("Phalcon_Model_Manager::addBelongsTo (Assignment) File=/Model/Manager Line=239");
	PHALCON_ALLOC_ZVAL(r0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "get_class", strlen("get_class"), 1, p0);
	phalcon_debug_vdump("get_class > ", r0 TSRMLS_CC);
	if (v4) {
		Z_DELREF_P(v4);
		if (!Z_REFCOUNT_P(v4)) {
			FREE_ZVAL(v4);
		}
	}
	Z_ADDREF_P(r0);
	v4 = r0;
	phalcon_debug_assign("$modelName", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Manager::addBelongsTo (If) File=/Model/Manager Line=240");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v4);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Model_Manager::addBelongsTo (Block) File=/Model/Manager Line=240");
		phalcon_step_over("Phalcon_Model_Manager::addBelongsTo (Assignment) File=/Model/Manager Line=241");
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		{
			zval *orig_ptr = t1;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				Z_DELREF_P(orig_ptr);
				ALLOC_ZVAL(t1);
				*t1 = *orig_ptr;
				zval_copy_ctor(t1);
				Z_SET_REFCOUNT_P(t1, 1);
				Z_UNSET_ISREF_P(t1);
			}
		}
		phalcon_array_update(t1, v4, a0 TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, t1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_belongsTo", strlen("_belongsTo"), copy TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Model_Manager::addBelongsTo (If) File=/Model/Manager Line=243");
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
	phalcon_array_fetch(r1, t2, v4, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(r1, v2);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Model_Manager::addBelongsTo (Block) File=/Model/Manager Line=243");
		phalcon_step_over("Phalcon_Model_Manager::addBelongsTo (If) File=/Model/Manager Line=244");
		if (Z_TYPE_P(v3) == IS_ARRAY) { 
			phalcon_step_over("Phalcon_Model_Manager::addBelongsTo (Block) File=/Model/Manager Line=244");
			phalcon_step_over("Phalcon_Model_Manager::addBelongsTo (If) File=/Model/Manager Line=245");
			PHALCON_ALLOC_ZVAL(r2);
			p1[0] = v1;
			phalcon_debug_param(v1 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r2, "count", strlen("count"), 1, p1);
			phalcon_debug_vdump("count > ", r2 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r3);
			p2[0] = v3;
			phalcon_debug_param(v3 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r3, "count", strlen("count"), 1, p2);
			phalcon_debug_vdump("count > ", r3 TSRMLS_CC);
			PHALCON_NOT_EQUAL_FUNCTION(r4, r2, r3);
			if (zend_is_true(r4)) {
				phalcon_step_over("Phalcon_Model_Manager::addBelongsTo (Block) File=/Model/Manager Line=245");
				phalcon_step_over("Phalcon_Model_Manager::addBelongsTo (Throw) File=/Model/Manager Line=246");
				PHALCON_ALLOC_ZVAL(i0);
				object_init_ex(i0, phalcon_model_exception_class_entry);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
				phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(p3[0]);
				ZVAL_STRING(p3[0], "Number of referenced fields are not the same", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p3, PHALCON_CALL_CHECK);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
				zend_throw_exception_object(i0 TSRMLS_CC);
				Z_ADDREF_P(i0);
				return;
			}
		}
		phalcon_step_over("Phalcon_Model_Manager::addBelongsTo (Assignment) File=/Model/Manager Line=249");
		PHALCON_ALLOC_ZVAL(a1);
		array_init(a1);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			{
				zval *orig_ptr = a1;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a1);
					*a1 = *orig_ptr;
					zval_copy_ctor(a1);
					Z_SET_REFCOUNT_P(a1, 1);
					Z_UNSET_ISREF_P(a1);
				}
			}
			add_assoc_zval(a1, "fi", copy);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v2, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			{
				zval *orig_ptr = a1;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a1);
					*a1 = *orig_ptr;
					zval_copy_ctor(a1);
					Z_SET_REFCOUNT_P(a1, 1);
					Z_UNSET_ISREF_P(a1);
				}
			}
			add_assoc_zval(a1, "rt", copy);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v3, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			{
				zval *orig_ptr = a1;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a1);
					*a1 = *orig_ptr;
					zval_copy_ctor(a1);
					Z_SET_REFCOUNT_P(a1, 1);
					Z_UNSET_ISREF_P(a1);
				}
			}
			add_assoc_zval(a1, "rf", copy);
		}
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_read_property(t3, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(t3) == IS_ARRAY) {
			PHALCON_ALLOC_ZVAL(t4);
			phalcon_array_fetch(t4, t3, v4, PHALCON_SILENT_FETCH TSRMLS_CC);
		}
		if (Z_TYPE_P(t4) != IS_ARRAY) {
			convert_to_array(t4);
			phalcon_array_update(t3, v4, t4 TSRMLS_CC);
			Z_ADDREF_P(t4);
		}
		phalcon_array_update(t4, v2, a1 TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, t3, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_belongsTo", strlen("_belongsTo"), copy TSRMLS_CC);
		}
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Model_Manager::addBelongsTo (Block) File=/Model/Manager Line=255");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Manager::addBelongsTo (Method) File=/Model/Manager Line=268");
}

/**
 * Setup a relation 1-n between two models
 *
 * @param Phalcon_Model_Base $model
 * @parammixed $fields
 * @paramstring $referenceModel
 * @parammixed $referencedFields 
 */
PHP_METHOD(Phalcon_Model_Manager, addHasMany){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v2 > ", v2 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v3 > ", v3 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Manager", "addHasMany", 0);
	phalcon_step_over("Phalcon_Model_Manager::addHasMany (Assignment) File=/Model/Manager Line=269");
	PHALCON_ALLOC_ZVAL(r0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "get_class", strlen("get_class"), 1, p0);
	phalcon_debug_vdump("get_class > ", r0 TSRMLS_CC);
	if (v4) {
		Z_DELREF_P(v4);
		if (!Z_REFCOUNT_P(v4)) {
			FREE_ZVAL(v4);
		}
	}
	Z_ADDREF_P(r0);
	v4 = r0;
	phalcon_debug_assign("$entityName", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Manager::addHasMany (If) File=/Model/Manager Line=270");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v4);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Model_Manager::addHasMany (Block) File=/Model/Manager Line=270");
		phalcon_step_over("Phalcon_Model_Manager::addHasMany (Assignment) File=/Model/Manager Line=271");
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		{
			zval *orig_ptr = t1;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				Z_DELREF_P(orig_ptr);
				ALLOC_ZVAL(t1);
				*t1 = *orig_ptr;
				zval_copy_ctor(t1);
				Z_SET_REFCOUNT_P(t1, 1);
				Z_UNSET_ISREF_P(t1);
			}
		}
		phalcon_array_update(t1, v4, a0 TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, t1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_hasMany", strlen("_hasMany"), copy TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Model_Manager::addHasMany (If) File=/Model/Manager Line=273");
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
	phalcon_array_fetch(r1, t2, v4, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(r1, v2);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Model_Manager::addHasMany (Block) File=/Model/Manager Line=273");
		phalcon_step_over("Phalcon_Model_Manager::addHasMany (If) File=/Model/Manager Line=274");
		if (Z_TYPE_P(v3) == IS_ARRAY) { 
			phalcon_step_over("Phalcon_Model_Manager::addHasMany (Block) File=/Model/Manager Line=274");
			phalcon_step_over("Phalcon_Model_Manager::addHasMany (If) File=/Model/Manager Line=275");
			PHALCON_ALLOC_ZVAL(r2);
			p1[0] = v1;
			phalcon_debug_param(v1 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r2, "count", strlen("count"), 1, p1);
			phalcon_debug_vdump("count > ", r2 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r3);
			p2[0] = v3;
			phalcon_debug_param(v3 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r3, "count", strlen("count"), 1, p2);
			phalcon_debug_vdump("count > ", r3 TSRMLS_CC);
			PHALCON_NOT_EQUAL_FUNCTION(r4, r2, r3);
			if (zend_is_true(r4)) {
				phalcon_step_over("Phalcon_Model_Manager::addHasMany (Block) File=/Model/Manager Line=275");
				phalcon_step_over("Phalcon_Model_Manager::addHasMany (Throw) File=/Model/Manager Line=276");
				PHALCON_ALLOC_ZVAL(i0);
				object_init_ex(i0, phalcon_model_exception_class_entry);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
				phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(p3[0]);
				ZVAL_STRING(p3[0], "Number of referenced fields are not the same", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p3, PHALCON_CALL_CHECK);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
				zend_throw_exception_object(i0 TSRMLS_CC);
				Z_ADDREF_P(i0);
				return;
			}
		}
		phalcon_step_over("Phalcon_Model_Manager::addHasMany (Assignment) File=/Model/Manager Line=279");
		PHALCON_ALLOC_ZVAL(a1);
		array_init(a1);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			{
				zval *orig_ptr = a1;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a1);
					*a1 = *orig_ptr;
					zval_copy_ctor(a1);
					Z_SET_REFCOUNT_P(a1, 1);
					Z_UNSET_ISREF_P(a1);
				}
			}
			add_assoc_zval(a1, "fi", copy);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v2, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			{
				zval *orig_ptr = a1;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a1);
					*a1 = *orig_ptr;
					zval_copy_ctor(a1);
					Z_SET_REFCOUNT_P(a1, 1);
					Z_UNSET_ISREF_P(a1);
				}
			}
			add_assoc_zval(a1, "rt", copy);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v3, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			{
				zval *orig_ptr = a1;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a1);
					*a1 = *orig_ptr;
					zval_copy_ctor(a1);
					Z_SET_REFCOUNT_P(a1, 1);
					Z_UNSET_ISREF_P(a1);
				}
			}
			add_assoc_zval(a1, "rf", copy);
		}
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_read_property(t3, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(t3) == IS_ARRAY) {
			PHALCON_ALLOC_ZVAL(t4);
			phalcon_array_fetch(t4, t3, v4, PHALCON_SILENT_FETCH TSRMLS_CC);
		}
		if (Z_TYPE_P(t4) != IS_ARRAY) {
			convert_to_array(t4);
			phalcon_array_update(t3, v4, t4 TSRMLS_CC);
			Z_ADDREF_P(t4);
		}
		phalcon_array_update(t4, v2, a1 TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, t3, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_hasMany", strlen("_hasMany"), copy TSRMLS_CC);
		}
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Model_Manager::addHasMany (Block) File=/Model/Manager Line=285");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Manager::addHasMany (Method) File=/Model/Manager Line=298");
}

/**
 * Checks whether a model have a belongsTo relation with other model
 *
 * @access public
 * @param string $modelName
 * @param string $modelRelation
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Manager, existsBelongsTo){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Manager", "existsBelongsTo", 0);
	phalcon_step_over("Phalcon_Model_Manager::existsBelongsTo (If) File=/Model/Manager Line=299");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	if (eval_int) {
		phalcon_step_over("Phalcon_Model_Manager::existsBelongsTo (Block) File=/Model/Manager Line=299");
		phalcon_step_over("Phalcon_Model_Manager::existsBelongsTo (If) File=/Model/Manager Line=300");
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch(r0, t1, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(r0, v1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Model_Manager::existsBelongsTo (Block) File=/Model/Manager Line=300");
			phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_TRUE;
		}
	}
	phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_FALSE;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Manager::existsBelongsTo (Method) File=/Model/Manager Line=315");
}

/**
 * Checks whether a model have a hasMany relation with other model
 *
 * @access public
 * @param string $modelName
 * @param string $modelRelation
 * @return boolean 
 */
PHP_METHOD(Phalcon_Model_Manager, existsHasMany){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Manager", "existsHasMany", 0);
	phalcon_step_over("Phalcon_Model_Manager::existsHasMany (If) File=/Model/Manager Line=316");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	if (eval_int) {
		phalcon_step_over("Phalcon_Model_Manager::existsHasMany (Block) File=/Model/Manager Line=316");
		phalcon_step_over("Phalcon_Model_Manager::existsHasMany (If) File=/Model/Manager Line=317");
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch(r0, t1, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(r0, v1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Model_Manager::existsHasMany (Block) File=/Model/Manager Line=317");
			phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_TRUE;
		}
	}
	phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_FALSE;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Manager::existsHasMany (Method) File=/Model/Manager Line=332");
}

/**
 * Checks whether a model have a hasOne relation with other model
 *
 * @access public
 * @param string $modelName
 * @param string $modelRelation
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Manager, existsHasOne){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Manager", "existsHasOne", 0);
	phalcon_step_over("Phalcon_Model_Manager::existsHasOne (If) File=/Model/Manager Line=333");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	if (eval_int) {
		phalcon_step_over("Phalcon_Model_Manager::existsHasOne (Block) File=/Model/Manager Line=333");
		phalcon_step_over("Phalcon_Model_Manager::existsHasOne (If) File=/Model/Manager Line=334");
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch(r0, t1, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(r0, v1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Model_Manager::existsHasOne (Block) File=/Model/Manager Line=334");
			phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_TRUE;
		}
	}
	phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_FALSE;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Manager::existsHasOne (Method) File=/Model/Manager Line=348");
}

/**
 * Helper method to query records based on a relation definition
 *
 * @param array $relation
 * @param string $method
 * @param Phalcon_Model_Base $record
 */
PHP_METHOD(Phalcon_Model_Manager, _getRelationRecords){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL, NULL }, *p3[] = { NULL }, *p4[] = { NULL }, *p6[] = { NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v2 > ", v2 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Manager", "_getRelationRecords", 0);
	phalcon_step_over("Phalcon_Model_Manager::_getRelationRecords (If) File=/Model/Manager Line=350");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_array_fetch_string(r0, v0, "fi", strlen("fi"), PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(r0) != IS_ARRAY) { 
		phalcon_step_over("Phalcon_Model_Manager::_getRelationRecords (Block) File=/Model/Manager Line=350");
		phalcon_step_over("Phalcon_Model_Manager::_getRelationRecords (Assignment) File=/Model/Manager Line=351");
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
		phalcon_debug_method_call(v2, "readattribute" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_array_fetch_string(r2, v0, "fi", strlen("fi"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r2);
		p0[0] = r2;
		phalcon_debug_param(r2 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r1, v2, "readattribute", 1, p0, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r1);
		v3 = r1;
		phalcon_debug_assign("$value", r1 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Manager::_getRelationRecords (Assignment) File=/Model/Manager Line=352");
		PHALCON_ALLOC_ZVAL(r4);
		phalcon_array_fetch_string(r4, v0, "rf", strlen("rf"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r3);
		phalcon_concat_vboth(r3, r4, " = '", v3 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r5);
		phalcon_concat_right(r5, r3, "'" TSRMLS_CC);
		if (v4) {
			Z_DELREF_P(v4);
			if (!Z_REFCOUNT_P(v4)) {
				FREE_ZVAL(v4);
			}
		}
		Z_ADDREF_P(r5);
		v4 = r5;
		phalcon_debug_assign("$condition", r5 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Model_Manager::_getRelationRecords (Block) File=/Model/Manager Line=353");
		phalcon_step_over("Phalcon_Model_Manager::_getRelationRecords (Assignment) File=/Model/Manager Line=354");
		PHALCON_ALLOC_ZVAL(v5);
		ZVAL_LONG(v5, 0);
		phalcon_step_over("Phalcon_Model_Manager::_getRelationRecords (Assignment) File=/Model/Manager Line=355");
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		if (v6) {
			Z_DELREF_P(v6);
			if (!Z_REFCOUNT_P(v6)) {
				FREE_ZVAL(v6);
			}
		}
		Z_ADDREF_P(a0);
		v6 = a0;
		phalcon_debug_assign("$conditions", a0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Manager::_getRelationRecords (Foreach) File=/Model/Manager Line=356");
		PHALCON_ALLOC_ZVAL(r6);
		phalcon_array_fetch_string(r6, v0, "fi", strlen("fi"), PHALCON_NOISY_FETCH TSRMLS_CC);
		FOREACH_V(r6, ac0, fes64, fee64, ah0, hp0, v7)
			phalcon_step_over("Phalcon_Model_Manager::_getRelationRecords (Block) File=/Model/Manager Line=356");
			phalcon_step_over("Phalcon_Model_Manager::_getRelationRecords (Assignment) File=/Model/Manager Line=357");
			if (!r7) {
				PHALCON_ALLOC_ZVAL(r7);
			} else {
				if (Z_REFCOUNT_P(r7) > 1) {
					{
						zval *orig_ptr = r7;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r7);
							*r7 = *orig_ptr;
							zval_copy_ctor(r7);
							Z_SET_REFCOUNT_P(r7, 1);
							Z_UNSET_ISREF_P(r7);
						}
					}
				} else {
					FREE_ZVAL(r7);
					PHALCON_ALLOC_ZVAL(r7);
				}
			}
			phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
			phalcon_debug_method_call(v2, "readattribute" TSRMLS_CC);
			if (!r8) {
				PHALCON_ALLOC_ZVAL(r8);
			} else {
				if (Z_REFCOUNT_P(r8) > 1) {
					{
						zval *orig_ptr = r8;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r8);
							*r8 = *orig_ptr;
							zval_copy_ctor(r8);
							Z_SET_REFCOUNT_P(r8, 1);
							Z_UNSET_ISREF_P(r8);
						}
					}
				} else {
					FREE_ZVAL(r8);
					PHALCON_ALLOC_ZVAL(r8);
				}
			}
			phalcon_array_fetch_string(r8, v0, "fi", strlen("fi"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (!r9) {
				PHALCON_ALLOC_ZVAL(r9);
			} else {
				if (Z_REFCOUNT_P(r9) > 1) {
					{
						zval *orig_ptr = r9;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r9);
							*r9 = *orig_ptr;
							zval_copy_ctor(r9);
							Z_SET_REFCOUNT_P(r9, 1);
							Z_UNSET_ISREF_P(r9);
						}
					}
				} else {
					FREE_ZVAL(r9);
					PHALCON_ALLOC_ZVAL(r9);
				}
			}
			phalcon_array_fetch(r9, r8, v5, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r9);
			p1[0] = r9;
			phalcon_debug_param(r9 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS(r7, v2, "readattribute", 1, p1, PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r7 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
			if (v3) {
				Z_DELREF_P(v3);
				if (!Z_REFCOUNT_P(v3)) {
					FREE_ZVAL(v3);
				}
			}
			Z_ADDREF_P(r7);
			v3 = r7;
			phalcon_debug_assign("$value", r7 TSRMLS_CC);
			phalcon_step_over("Phalcon_Model_Manager::_getRelationRecords (Assignment) File=/Model/Manager Line=358");
			if (!r11) {
				PHALCON_ALLOC_ZVAL(r11);
			} else {
				if (Z_REFCOUNT_P(r11) > 1) {
					{
						zval *orig_ptr = r11;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r11);
							*r11 = *orig_ptr;
							zval_copy_ctor(r11);
							Z_SET_REFCOUNT_P(r11, 1);
							Z_UNSET_ISREF_P(r11);
						}
					}
				} else {
					FREE_ZVAL(r11);
					PHALCON_ALLOC_ZVAL(r11);
				}
			}
			phalcon_array_fetch_string(r11, v0, "rf", strlen("rf"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (!r12) {
				PHALCON_ALLOC_ZVAL(r12);
			} else {
				if (Z_REFCOUNT_P(r12) > 1) {
					{
						zval *orig_ptr = r12;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r12);
							*r12 = *orig_ptr;
							zval_copy_ctor(r12);
							Z_SET_REFCOUNT_P(r12, 1);
							Z_UNSET_ISREF_P(r12);
						}
					}
				} else {
					FREE_ZVAL(r12);
					PHALCON_ALLOC_ZVAL(r12);
				}
			}
			phalcon_array_fetch(r12, r11, v5, PHALCON_NOISY_FETCH TSRMLS_CC);
			if (!r10) {
				PHALCON_ALLOC_ZVAL(r10);
			} else {
				if (Z_REFCOUNT_P(r10) > 1) {
					{
						zval *orig_ptr = r10;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r10);
							*r10 = *orig_ptr;
							zval_copy_ctor(r10);
							Z_SET_REFCOUNT_P(r10, 1);
							Z_UNSET_ISREF_P(r10);
						}
					}
				} else {
					FREE_ZVAL(r10);
					PHALCON_ALLOC_ZVAL(r10);
				}
			}
			phalcon_concat_vboth(r10, r12, " = '", v3 TSRMLS_CC);
			if (!r13) {
				PHALCON_ALLOC_ZVAL(r13);
			} else {
				if (Z_REFCOUNT_P(r13) > 1) {
					{
						zval *orig_ptr = r13;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r13);
							*r13 = *orig_ptr;
							zval_copy_ctor(r13);
							Z_SET_REFCOUNT_P(r13, 1);
							Z_UNSET_ISREF_P(r13);
						}
					}
				} else {
					FREE_ZVAL(r13);
					PHALCON_ALLOC_ZVAL(r13);
				}
			}
			phalcon_concat_right(r13, r10, "'" TSRMLS_CC);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r13, 1, 0);
				Z_SET_REFCOUNT_P(copy, 1);
				{
					zval *orig_ptr = v6;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(v6);
						*v6 = *orig_ptr;
						zval_copy_ctor(v6);
						Z_SET_REFCOUNT_P(v6, 1);
						Z_UNSET_ISREF_P(v6);
					}
				}
				phalcon_array_append(v6, copy TSRMLS_CC);
			}
			phalcon_step_over("Phalcon_Model_Manager::_getRelationRecords (PreIncDecOp) File=/Model/Manager Line=359");
			{
				zval *orig_ptr = v5;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(v5);
					*v5 = *orig_ptr;
					zval_copy_ctor(v5);
					Z_SET_REFCOUNT_P(v5, 1);
					Z_UNSET_ISREF_P(v5);
				}
			}
			increment_function(v5);
			phalcon_debug_vdump("PreIncrementing $i", v5);
		END_FOREACH(ac0, fes64, fee64, ah0, hp0);
		phalcon_step_over("Phalcon_Model_Manager::_getRelationRecords (Assignment) File=/Model/Manager Line=361");
		PHALCON_ALLOC_ZVAL(r14);
		PHALCON_ALLOC_ZVAL(p2[0]);
		ZVAL_STRING(p2[0], " AND ", 1);
		p2[1] = v6;
		phalcon_debug_param(v6 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r14, "join", strlen("join"), 2, p2);
		phalcon_debug_vdump("join > ", r14 TSRMLS_CC);
		if (v4) {
			Z_DELREF_P(v4);
			if (!Z_REFCOUNT_P(v4)) {
				FREE_ZVAL(v4);
			}
		}
		Z_ADDREF_P(r14);
		v4 = r14;
		phalcon_debug_assign("$condition", r14 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Model_Manager::_getRelationRecords (Assignment) File=/Model/Manager Line=381");
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v4, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		{
			zval *orig_ptr = a1;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				Z_DELREF_P(orig_ptr);
				ALLOC_ZVAL(a1);
				*a1 = *orig_ptr;
				zval_copy_ctor(a1);
				Z_SET_REFCOUNT_P(a1, 1);
				Z_UNSET_ISREF_P(a1);
			}
		}
		add_next_index_zval(a1, copy);
	}
	if (v8) {
		Z_DELREF_P(v8);
		if (!Z_REFCOUNT_P(v8)) {
			FREE_ZVAL(v8);
		}
	}
	Z_ADDREF_P(a1);
	v8 = a1;
	phalcon_debug_assign("$findParams", a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Manager::_getRelationRecords (Assignment) File=/Model/Manager Line=384");
	PHALCON_ALLOC_ZVAL(r15);
	phalcon_array_fetch_string(r15, v0, "rt", strlen("rt"), PHALCON_NOISY_FETCH TSRMLS_CC);
	if (v9) {
		Z_DELREF_P(v9);
		if (!Z_REFCOUNT_P(v9)) {
			FREE_ZVAL(v9);
		}
	}
	Z_ADDREF_P(r15);
	v9 = r15;
	phalcon_debug_assign("$referenceTable", r15 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Manager::_getRelationRecords (Assignment) File=/Model/Manager Line=385");
	PHALCON_ALLOC_ZVAL(r16);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getmodel" TSRMLS_CC);
	Z_ADDREF_P(v9);
	p3[0] = v9;
	phalcon_debug_param(v9 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r16, this_ptr, "getmodel", 1, p3, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r16 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
	if (v10) {
		Z_DELREF_P(v10);
		if (!Z_REFCOUNT_P(v10)) {
			FREE_ZVAL(v10);
		}
	}
	Z_ADDREF_P(r16);
	v10 = r16;
	phalcon_debug_assign("$referencedEntity", r16 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Manager::_getRelationRecords (MethodCall) File=/Model/Manager Line=386");
	phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
	phalcon_debug_method_call(v10, "setconnection" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r17);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
	phalcon_debug_method_call(v2, "getconnection" TSRMLS_CC);
	PHALCON_CALL_METHOD(r17, v2, "getconnection", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r17 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
	Z_ADDREF_P(r17);
	p4[0] = r17;
	phalcon_debug_param(r17 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v10, "setconnection", 1, p4, PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r18);
	PHALCON_ALLOC_ZVAL(a2);
	array_init(a2);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v10, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		{
			zval *orig_ptr = a2;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				Z_DELREF_P(orig_ptr);
				ALLOC_ZVAL(a2);
				*a2 = *orig_ptr;
				zval_copy_ctor(a2);
				Z_SET_REFCOUNT_P(a2, 1);
				Z_UNSET_ISREF_P(a2);
			}
		}
		add_next_index_zval(a2, copy);
	}
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		{
			zval *orig_ptr = a2;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				Z_DELREF_P(orig_ptr);
				ALLOC_ZVAL(a2);
				*a2 = *orig_ptr;
				zval_copy_ctor(a2);
				Z_SET_REFCOUNT_P(a2, 1);
				Z_UNSET_ISREF_P(a2);
			}
		}
		add_next_index_zval(a2, copy);
	}
	Z_ADDREF_P(a2);
	p6[0] = a2;
	phalcon_debug_param(a2 TSRMLS_CC);
	Z_ADDREF_P(v8);
	p6[1] = v8;
	phalcon_debug_param(v8 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r18, "call_user_func_array", strlen("call_user_func_array"), 2, p6);
	phalcon_debug_vdump("call_user_func_array > ", r18 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r18 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r18, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Manager::_getRelationRecords (Method) File=/Model/Manager Line=390");
}

PHP_METHOD(Phalcon_Model_Manager, getBelongsToRecords){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *p0[] = { NULL, NULL, NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v2 > ", v2 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v3 > ", v3 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Manager", "getBelongsToRecords", 0);
	phalcon_step_over("Phalcon_Model_Manager::getBelongsToRecords (If) File=/Model/Manager Line=391");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Model_Manager::getBelongsToRecords (Block) File=/Model/Manager Line=391");
		phalcon_step_over("Phalcon_Model_Manager::getBelongsToRecords (If) File=/Model/Manager Line=392");
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch(r0, t1, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(r0, v2);
		if (!eval_int) {
			phalcon_step_over("Phalcon_Model_Manager::getBelongsToRecords (Block) File=/Model/Manager Line=392");
			phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_FALSE;
		}
	}
	phalcon_step_over("Phalcon_Model_Manager::getBelongsToRecords (Assignment) File=/Model/Manager Line=396");
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
	phalcon_array_fetch(r1, t2, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r2);
	phalcon_array_fetch(r2, r1, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (v4) {
		Z_DELREF_P(v4);
		if (!Z_REFCOUNT_P(v4)) {
			FREE_ZVAL(v4);
		}
	}
	Z_ADDREF_P(r2);
	v4 = r2;
	phalcon_debug_assign("$relation", r2 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r3);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_getrelationrecords" TSRMLS_CC);
	Z_ADDREF_P(v4);
	p0[0] = v4;
	phalcon_debug_param(v4 TSRMLS_CC);
	Z_ADDREF_P(v0);
	p0[1] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	Z_ADDREF_P(v3);
	p0[2] = v3;
	phalcon_debug_param(v3 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r3, this_ptr, "_getrelationrecords", 3, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r3 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r3 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r3, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Manager::getBelongsToRecords (Method) File=/Model/Manager Line=400");
}

PHP_METHOD(Phalcon_Model_Manager, getHasManyRecords){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *p0[] = { NULL, NULL, NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v2 > ", v2 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v3 > ", v3 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Manager", "getHasManyRecords", 0);
	phalcon_step_over("Phalcon_Model_Manager::getHasManyRecords (If) File=/Model/Manager Line=401");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Model_Manager::getHasManyRecords (Block) File=/Model/Manager Line=401");
		phalcon_step_over("Phalcon_Model_Manager::getHasManyRecords (If) File=/Model/Manager Line=402");
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch(r0, t1, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(r0, v2);
		if (!eval_int) {
			phalcon_step_over("Phalcon_Model_Manager::getHasManyRecords (Block) File=/Model/Manager Line=402");
			phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_FALSE;
		}
	}
	phalcon_step_over("Phalcon_Model_Manager::getHasManyRecords (Assignment) File=/Model/Manager Line=406");
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
	phalcon_array_fetch(r1, t2, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r2);
	phalcon_array_fetch(r2, r1, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (v4) {
		Z_DELREF_P(v4);
		if (!Z_REFCOUNT_P(v4)) {
			FREE_ZVAL(v4);
		}
	}
	Z_ADDREF_P(r2);
	v4 = r2;
	phalcon_debug_assign("$relation", r2 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r3);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_getrelationrecords" TSRMLS_CC);
	Z_ADDREF_P(v4);
	p0[0] = v4;
	phalcon_debug_param(v4 TSRMLS_CC);
	Z_ADDREF_P(v0);
	p0[1] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	Z_ADDREF_P(v3);
	p0[2] = v3;
	phalcon_debug_param(v3 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r3, this_ptr, "_getrelationrecords", 3, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r3 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r3 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r3, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Manager::getHasManyRecords (Method) File=/Model/Manager Line=410");
}

PHP_METHOD(Phalcon_Model_Manager, getHasOneRecords){


	phalcon_step_into_entry("Phalcon_Model_Manager", "getHasOneRecords", 0);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Manager::getHasOneRecords (Method) File=/Model/Manager Line=419");
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
	phalcon_step_over("Phalcon_Model_Manager::autoload (MethodCall) File=/Model/Manager Line=420");
	phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "ismodel" TSRMLS_CC);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "ismodel", 1, p0, PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Manager" TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
}

