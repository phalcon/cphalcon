
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
	PHALCON_CALL_FUNC_PARAMS_NORETURN("spl_autoload_register", strlen("spl_autoload_register"), 1, p0);
	RETURN_NULL();
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

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_metadata", strlen("_metadata"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

/**
 * Returns active meta-data manager. If not exists any will be created one
 *
 * @return Phalcon_Model_Metadata
 */
PHP_METHOD(Phalcon_Model_Manager, getMetaData){

	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_metadata", sizeof("_metadata")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_model_metadata_class_entry);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
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

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_modelsDir", strlen("_modelsDir"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

/**
 * Gets active models directory
 *
 * @return string
 */
PHP_METHOD(Phalcon_Model_Manager, getModelsDir){

	zval *t0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_modelsDir", sizeof("_modelsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	if (eval_int) {
		RETURN_TRUE;
	} else {
		PHALCON_ALLOC_ZVAL(r0);
		Z_ADDREF_P(v0);
		p0[0] = v0;
		PHALCON_PARAM_BOOL(p0[1], 0);
		PHALCON_CALL_FUNC_PARAMS(r0, "class_exists", strlen("class_exists"), 2, p0);
		if (!zend_is_true(r0)) {
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
			if (phalcon_file_exists(v1 TSRMLS_CC) == SUCCESS) {
				PHALCON_ALLOC_ZVAL(r3);
				Z_ADDREF_P(v0);
				p1[0] = v0;
				PHALCON_CALL_METHOD_PARAMS(r3, this_ptr, "load", 1, p1, PHALCON_CALL_DEFAULT);
				RETURN_ZVAL(r3, 1, 0);
			} else {
				RETURN_FALSE;
			}
		} else {
			RETURN_TRUE;
		}
	}
	RETURN_NULL();
}

/**
 * Loads a model looking for its file and initializing them
 *
 * @param string $modelName
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Manager, load){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL, NULL }, *p2[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL };
	int eval_int;
	zend_class_entry *ce0, *ce1;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL(r0);
		Z_ADDREF_P(v0);
		p0[0] = v0;
		PHALCON_PARAM_BOOL(p0[1], 0);
		PHALCON_CALL_FUNC_PARAMS(r0, "class_exists", strlen("class_exists"), 2, p0);
		if (!zend_is_true(r0)) {
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
			if (phalcon_file_exists(v1 TSRMLS_CC) == SUCCESS) {
				phalcon_require(v1 TSRMLS_CC);
				if (EG(exception) || EG(exit_status) == 255) {
					return;
				}
				PHALCON_ALLOC_ZVAL(r3);
				Z_ADDREF_P(v0);
				p1[0] = v0;
				PHALCON_PARAM_BOOL(p1[1], 0);
				PHALCON_CALL_FUNC_PARAMS(r3, "class_exists", strlen("class_exists"), 2, p1);
				if (!zend_is_true(r3)) {
					PHALCON_ALLOC_ZVAL(i0);
					object_init_ex(i0, phalcon_model_exception_class_entry);
					PHALCON_ALLOC_ZVAL(r4);
					phalcon_concat_both(r4,  "Class \"", v0, "\" could not found on model file" TSRMLS_CC);
					Z_ADDREF_P(r4);
					p2[0] = r4;
					PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p2, PHALCON_CALL_CHECK);
					zend_throw_exception_object(i0 TSRMLS_CC);
					Z_ADDREF_P(i0);
					return;
				}
				ce0 = zend_fetch_class(Z_STRVAL_P(v0), Z_STRLEN_P(v0), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(i1);
				object_init_ex(i1, ce0);
				Z_ADDREF_P(this_ptr);
				p3[0] = this_ptr;
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p3, PHALCON_CALL_CHECK);
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
			} else {
				PHALCON_ALLOC_ZVAL(i2);
				object_init_ex(i2, phalcon_model_exception_class_entry);
				PHALCON_ALLOC_ZVAL(r5);
				phalcon_concat_both(r5,  "Class file path for model \"", v0, "\"  could not found" TSRMLS_CC);
				Z_ADDREF_P(r5);
				p4[0] = r5;
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 1, p4, PHALCON_CALL_CHECK);
				zend_throw_exception_object(i2 TSRMLS_CC);
				Z_ADDREF_P(i2);
				return;
			}
		} else {
			ce1 = zend_fetch_class(Z_STRVAL_P(v0), Z_STRLEN_P(v0), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(i3);
			object_init_ex(i3, ce1);
			Z_ADDREF_P(this_ptr);
			p5[0] = this_ptr;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i3, "__construct", 1, p5, PHALCON_CALL_CHECK);
			PHALCON_ALLOC_ZVAL(t3);
			phalcon_read_property(t3, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			{
				zval *orig_ptr = t3;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(t3);
					*t3 = *orig_ptr;
					zval_copy_ctor(t3);
					Z_SET_REFCOUNT_P(t3, 1);
					Z_UNSET_ISREF_P(t3);
				}
			}
			phalcon_array_update(t3, v0, i3 TSRMLS_CC);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, t3, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_models", strlen("_models"), copy TSRMLS_CC);
			}
		}
	}
	RETURN_TRUE;
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

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	if (!eval_int) {
		Z_ADDREF_P(v0);
		p0[0] = v0;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "load", 1, p0, PHALCON_CALL_DEFAULT);
	}
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_array_fetch(r0, t1, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
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

	t0 = zend_read_static_property(phalcon_model_manager_class_entry, "_sourceNames", sizeof("_sourceNames")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_array_fetch(t1, t0, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
	if (!zend_is_true(t1)) {
		PHALCON_ALLOC_ZVAL(r0);
		Z_ADDREF_P(v0);
		p0[0] = v0;
		PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_utils", "uncamelize", 1, p0);
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

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_STATIC(r0, "phalcon_db_pool", "hasdefaultdescriptor");
	if (!zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_exception_class_entry);
		PHALCON_ALLOC_ZVAL(p1[0]);
		ZVAL_STRING(p1[0], "There is not defined database connection parameters", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_CALL_STATIC(r1, "phalcon_transaction_manager", "isautomatic");
	if (zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL(r2);
		PHALCON_ALLOC_ZVAL(r3);
		PHALCON_CALL_STATIC(r3, "phalcon_transaction_manager", "get");
		PHALCON_CALL_METHOD(r2, r3, "getconnection", PHALCON_CALL_DEFAULT);
		RETURN_ZVAL(r2, 1, 0);
	} else {
		PHALCON_ALLOC_ZVAL(r4);
		PHALCON_CALL_STATIC(r4, "phalcon_db_pool", "getconnection");
		RETURN_ZVAL(r4, 1, 0);
	}
	RETURN_NULL();
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

	PHALCON_ALLOC_ZVAL(r0);
	p0[0] = v0;
	PHALCON_CALL_FUNC_PARAMS(r0, "get_class", strlen("get_class"), 1, p0);
	if (v4) {
		Z_DELREF_P(v4);
		if (!Z_REFCOUNT_P(v4)) {
			FREE_ZVAL(v4);
		}
	}
	Z_ADDREF_P(r0);
	v4 = r0;
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v4);
	if (!eval_int) {
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
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
	phalcon_array_fetch(r1, t2, v4, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(r1, v2);
	if (!eval_int) {
		if (Z_TYPE_P(v3) == IS_ARRAY) { 
			PHALCON_ALLOC_ZVAL(r2);
			p1[0] = v1;
			PHALCON_CALL_FUNC_PARAMS(r2, "count", strlen("count"), 1, p1);
			PHALCON_ALLOC_ZVAL(r3);
			p2[0] = v3;
			PHALCON_CALL_FUNC_PARAMS(r3, "count", strlen("count"), 1, p2);
			PHALCON_NOT_EQUAL_FUNCTION(r4, r2, r3);
			if (zend_is_true(r4)) {
				PHALCON_ALLOC_ZVAL(i0);
				object_init_ex(i0, phalcon_model_exception_class_entry);
				PHALCON_ALLOC_ZVAL(p3[0]);
				ZVAL_STRING(p3[0], "Number of referenced fields are not the same", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p3, PHALCON_CALL_CHECK);
				zend_throw_exception_object(i0 TSRMLS_CC);
				Z_ADDREF_P(i0);
				return;
			}
		}
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
	}
	RETURN_NULL();
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

	PHALCON_ALLOC_ZVAL(r0);
	p0[0] = v0;
	PHALCON_CALL_FUNC_PARAMS(r0, "get_class", strlen("get_class"), 1, p0);
	if (v4) {
		Z_DELREF_P(v4);
		if (!Z_REFCOUNT_P(v4)) {
			FREE_ZVAL(v4);
		}
	}
	Z_ADDREF_P(r0);
	v4 = r0;
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v4);
	if (!eval_int) {
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
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
	phalcon_array_fetch(r1, t2, v4, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(r1, v2);
	if (!eval_int) {
		if (Z_TYPE_P(v3) == IS_ARRAY) { 
			PHALCON_ALLOC_ZVAL(r2);
			p1[0] = v1;
			PHALCON_CALL_FUNC_PARAMS(r2, "count", strlen("count"), 1, p1);
			PHALCON_ALLOC_ZVAL(r3);
			p2[0] = v3;
			PHALCON_CALL_FUNC_PARAMS(r3, "count", strlen("count"), 1, p2);
			PHALCON_NOT_EQUAL_FUNCTION(r4, r2, r3);
			if (zend_is_true(r4)) {
				PHALCON_ALLOC_ZVAL(i0);
				object_init_ex(i0, phalcon_model_exception_class_entry);
				PHALCON_ALLOC_ZVAL(p3[0]);
				ZVAL_STRING(p3[0], "Number of referenced fields are not the same", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p3, PHALCON_CALL_CHECK);
				zend_throw_exception_object(i0 TSRMLS_CC);
				Z_ADDREF_P(i0);
				return;
			}
		}
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
		RETURN_TRUE;
	} else {
		RETURN_FALSE;
	}
	RETURN_NULL();
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

	PHALCON_ALLOC_ZVAL(r0);
	p0[0] = v0;
	PHALCON_CALL_FUNC_PARAMS(r0, "get_class", strlen("get_class"), 1, p0);
	if (v4) {
		Z_DELREF_P(v4);
		if (!Z_REFCOUNT_P(v4)) {
			FREE_ZVAL(v4);
		}
	}
	Z_ADDREF_P(r0);
	v4 = r0;
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v4);
	if (!eval_int) {
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
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
	phalcon_array_fetch(r1, t2, v4, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(r1, v2);
	if (!eval_int) {
		if (Z_TYPE_P(v3) == IS_ARRAY) { 
			PHALCON_ALLOC_ZVAL(r2);
			p1[0] = v1;
			PHALCON_CALL_FUNC_PARAMS(r2, "count", strlen("count"), 1, p1);
			PHALCON_ALLOC_ZVAL(r3);
			p2[0] = v3;
			PHALCON_CALL_FUNC_PARAMS(r3, "count", strlen("count"), 1, p2);
			PHALCON_NOT_EQUAL_FUNCTION(r4, r2, r3);
			if (zend_is_true(r4)) {
				PHALCON_ALLOC_ZVAL(i0);
				object_init_ex(i0, phalcon_model_exception_class_entry);
				PHALCON_ALLOC_ZVAL(p3[0]);
				ZVAL_STRING(p3[0], "Number of referenced fields are not the same", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p3, PHALCON_CALL_CHECK);
				zend_throw_exception_object(i0 TSRMLS_CC);
				Z_ADDREF_P(i0);
				return;
			}
		}
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
		RETURN_TRUE;
	} else {
		RETURN_FALSE;
	}
	RETURN_NULL();
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

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch(r0, t1, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(r0, v1);
		if (eval_int) {
			RETURN_TRUE;
		}
	}
	RETURN_FALSE;
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

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch(r0, t1, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(r0, v1);
		if (eval_int) {
			RETURN_TRUE;
		}
	}
	RETURN_FALSE;
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

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v0);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch(r0, t1, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(r0, v1);
		if (eval_int) {
			RETURN_TRUE;
		}
	}
	RETURN_FALSE;
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

	PHALCON_ALLOC_ZVAL(r0);
	phalcon_array_fetch_string(r0, v0, "fi", strlen("fi"), PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(r0) != IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_array_fetch_string(r2, v0, "fi", strlen("fi"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r2);
		p0[0] = r2;
		PHALCON_CALL_METHOD_PARAMS(r1, v2, "readattribute", 1, p0, PHALCON_CALL_DEFAULT);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r1);
		v3 = r1;
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
	} else {
		PHALCON_ALLOC_ZVAL(v5);
		ZVAL_LONG(v5, 0);
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
		PHALCON_ALLOC_ZVAL(r6);
		phalcon_array_fetch_string(r6, v0, "fi", strlen("fi"), PHALCON_NOISY_FETCH TSRMLS_CC);
		FOREACH_V(r6, ac0, fes64, fee64, ah0, hp0, v7)
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
			PHALCON_CALL_METHOD_PARAMS(r7, v2, "readattribute", 1, p1, PHALCON_CALL_DEFAULT);
			if (v3) {
				Z_DELREF_P(v3);
				if (!Z_REFCOUNT_P(v3)) {
					FREE_ZVAL(v3);
				}
			}
			Z_ADDREF_P(r7);
			v3 = r7;
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
		END_FOREACH(ac0, fes64, fee64, ah0, hp0);
		PHALCON_ALLOC_ZVAL(r14);
		PHALCON_ALLOC_ZVAL(p2[0]);
		ZVAL_STRING(p2[0], " AND ", 1);
		p2[1] = v6;
		PHALCON_CALL_FUNC_PARAMS(r14, "join", strlen("join"), 2, p2);
		if (v4) {
			Z_DELREF_P(v4);
			if (!Z_REFCOUNT_P(v4)) {
				FREE_ZVAL(v4);
			}
		}
		Z_ADDREF_P(r14);
		v4 = r14;
	}
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
	PHALCON_ALLOC_ZVAL(r16);
	Z_ADDREF_P(v9);
	p3[0] = v9;
	PHALCON_CALL_METHOD_PARAMS(r16, this_ptr, "getmodel", 1, p3, PHALCON_CALL_DEFAULT);
	if (v10) {
		Z_DELREF_P(v10);
		if (!Z_REFCOUNT_P(v10)) {
			FREE_ZVAL(v10);
		}
	}
	Z_ADDREF_P(r16);
	v10 = r16;
	PHALCON_ALLOC_ZVAL(r17);
	PHALCON_CALL_METHOD(r17, v2, "getconnection", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(r17);
	p4[0] = r17;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v10, "setconnection", 1, p4, PHALCON_CALL_DEFAULT);
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
	Z_ADDREF_P(v8);
	p6[1] = v8;
	PHALCON_CALL_FUNC_PARAMS(r18, "call_user_func_array", strlen("call_user_func_array"), 2, p6);
	RETURN_ZVAL(r18, 1, 0);
}

/**
 * Gets belongsTo related records from a model
 *
 * @param string $method
 * @param string $modelName
 * @param string $modelRelation
 * @param Phalcon_Model_Base $record
 * @return Phalcon_Model_Resultset
 */
PHP_METHOD(Phalcon_Model_Manager, getBelongsToRecords){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *p0[] = { NULL, NULL, NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch(r0, t1, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(r0, v2);
		if (!eval_int) {
			RETURN_FALSE;
		}
	}
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
	PHALCON_ALLOC_ZVAL(r3);
	Z_ADDREF_P(v4);
	p0[0] = v4;
	Z_ADDREF_P(v0);
	p0[1] = v0;
	Z_ADDREF_P(v3);
	p0[2] = v3;
	PHALCON_CALL_METHOD_PARAMS(r3, this_ptr, "_getrelationrecords", 3, p0, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r3, 1, 0);
}

/**
 * Gets hasMany related records from a model
 *
 * @param string $method
 * @param string $modelName
 * @param string $modelRelation
 * @param Phalcon_Model_Base $record
 * @return Phalcon_Model_Resultset
 */
PHP_METHOD(Phalcon_Model_Manager, getHasManyRecords){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *p0[] = { NULL, NULL, NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch(r0, t1, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(r0, v2);
		if (!eval_int) {
			RETURN_FALSE;
		}
	}
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
	PHALCON_ALLOC_ZVAL(r3);
	Z_ADDREF_P(v4);
	p0[0] = v4;
	Z_ADDREF_P(v0);
	p0[1] = v0;
	Z_ADDREF_P(v3);
	p0[2] = v3;
	PHALCON_CALL_METHOD_PARAMS(r3, this_ptr, "_getrelationrecords", 3, p0, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r3, 1, 0);
}

/**
 * Gets belongsTo related records from a model
 *
 * @param string $method
 * @param string $modelName
 * @param string $modelRelation
 * @param Phalcon_Model_Base $record
 * @return Phalcon_Model_Resultset
 */
PHP_METHOD(Phalcon_Model_Manager, getHasOneRecords){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *p0[] = { NULL, NULL, NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch(r0, t1, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(r0, v2);
		if (!eval_int) {
			RETURN_FALSE;
		}
	}
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	PHALCON_ALLOC_ZVAL(r3);
	Z_ADDREF_P(v4);
	p0[0] = v4;
	Z_ADDREF_P(v0);
	p0[1] = v0;
	Z_ADDREF_P(v3);
	p0[2] = v3;
	PHALCON_CALL_METHOD_PARAMS(r3, this_ptr, "_getrelationrecords", 3, p0, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r3, 1, 0);
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

	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "ismodel", 1, p0, PHALCON_CALL_DEFAULT);
	RETURN_NULL();
}

