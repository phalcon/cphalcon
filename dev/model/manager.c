
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
#include "kernel/operators.h"
#include "kernel/memory.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

/**
 * Phalcon_Model_Manager
 *
 * Manages the creation of models into applications and their relationships.
 * Phacon_Model_Manager helps to control the creation of models across a request execution.
 *
 * 
 */

/**
 * Constructor for Phalcon_Model_Manager
     *
     * @param array $metaDataOptions
 */
PHP_METHOD(Phalcon_Model_Manager, __construct){

	zval *meta_data_options = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL, *a6 = NULL;
	zval *a7 = NULL;

	PHALCON_MM_GROW();
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_model_manager_ce, this_ptr, "_models", strlen("_models"), a0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	zend_update_property(phalcon_model_manager_ce, this_ptr, "_hasMany", strlen("_hasMany"), a1 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	zend_update_property(phalcon_model_manager_ce, this_ptr, "_hasOne", strlen("_hasOne"), a2 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a3);
	array_init(a3);
	zend_update_property(phalcon_model_manager_ce, this_ptr, "_belongsTo", strlen("_belongsTo"), a3 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a4);
	array_init(a4);
	zend_update_property(phalcon_model_manager_ce, this_ptr, "_metadataOptions", strlen("_metadataOptions"), a4 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a5);
	array_init(a5);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &meta_data_options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!meta_data_options) {
		
		PHALCON_INIT_VAR(a6);
		array_init(a6);
		PHALCON_CPY_WRT(meta_data_options, a6);
	}
	
	PHALCON_INIT_VAR(a7);
	array_init(a7);
	phalcon_array_append(&a7, this_ptr, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	add_next_index_stringl(a7, "autoload", strlen("autoload"), 1);
	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("spl_autoload_register", a7, 0x000);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets base path. Depending of your platform, always add a trailing slash or backslash
 */
PHP_METHOD(Phalcon_Model_Manager, setBasePath){

	zval *base_path = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &base_path) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, "_basePath", strlen("_basePath"), base_path TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Overwrites default meta-data manager
 *
 * @param Phalcon_Model_Metadata $metadata
 */
PHP_METHOD(Phalcon_Model_Manager, setMetaData){

	zval *metadata = NULL;
	zval *i0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &metadata) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(metadata) != IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "Meta-data must be an object instance of Phalcon_Model_Metadata", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	phalcon_update_property_zval(this_ptr, "_metadata", strlen("_metadata"), metadata TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns active meta-data manager. If not exist then one will be created
 *
 * @return Phalcon_Model_Metadata
 */
PHP_METHOD(Phalcon_Model_Manager, getMetaData){

	zval *options = NULL, *adapter = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL;
	zval *i0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_metadata", sizeof("_metadata")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_metadataOptions", sizeof("_metadataOptions")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(options, t1);
		eval_int = phalcon_array_isset_string(options, "adapter", strlen("adapter")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			phalcon_array_fetch_string(&r0, options, "adapter", strlen("adapter"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(adapter, r0);
		} else {
			PHALCON_INIT_VAR(adapter);
			ZVAL_STRING(adapter, "Memory", 1);
		}
		
		
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_metadata_ce);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i0, "__construct", adapter, options, PHALCON_CHECK);
		phalcon_update_property_zval(this_ptr, "_metadata", strlen("_metadata"), i0 TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_metadata", sizeof("_metadata")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t2);
}

/**
 * Sets the models directory. Depending of your platform, always add a trailing slash or backslash
 *
 * @param string $modelsDir
 */
PHP_METHOD(Phalcon_Model_Manager, setModelsDir){

	zval *models_dir = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &models_dir) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, "_modelsDir", strlen("_modelsDir"), models_dir TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets active models directory
 *
 * @return string
 */
PHP_METHOD(Phalcon_Model_Manager, getModelsDir){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_modelsDir", sizeof("_modelsDir")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Checks whether the given name is an existing model
 *
 * 
 *
 * @param string $modelName
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Manager, isModel){

	zval *model_name = NULL, *model_path = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *c0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, model_name);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_INIT_VAR(c0);
		ZVAL_BOOL(c0, 0);
		PHALCON_CALL_FUNC_PARAMS_2(r0, "class_exists", model_name, c0, 0x012);
		if (!zend_is_true(r0)) {
			PHALCON_ALLOC_ZVAL_MM(t1);
			phalcon_read_property(&t1, this_ptr, "_basePath", sizeof("_basePath")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(t2);
			phalcon_read_property(&t2, this_ptr, "_modelsDir", sizeof("_modelsDir")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r1);
			concat_function(r1, t1, t2 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r2);
			concat_function(r2, r1, model_name TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_CONCAT_RIGHT(r3, r2, ".php");
			PHALCON_CPY_WRT(model_path, r3);
			if (phalcon_file_exists(model_path TSRMLS_CC) == SUCCESS) {
				PHALCON_ALLOC_ZVAL_MM(r4);
				PHALCON_CALL_METHOD_PARAMS_1(r4, this_ptr, "load", model_name, PHALCON_NO_CHECK);
				PHALCON_RETURN_DZVAL(r4);
			} else {
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

/**
 * Loads a model looking for its file and initializing them
 *
 * @param string $modelName
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Manager, load){

	zval *model_name = NULL, *model_path = NULL, *model = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL;
	int eval_int;
	zend_class_entry *ce0, *ce1;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, model_name);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_INIT_VAR(c0);
		ZVAL_BOOL(c0, 0);
		PHALCON_CALL_FUNC_PARAMS_2(r0, "class_exists", model_name, c0, 0x012);
		if (!zend_is_true(r0)) {
			PHALCON_ALLOC_ZVAL_MM(t1);
			phalcon_read_property(&t1, this_ptr, "_basePath", sizeof("_basePath")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(t2);
			phalcon_read_property(&t2, this_ptr, "_modelsDir", sizeof("_modelsDir")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r1);
			concat_function(r1, t1, t2 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r2);
			concat_function(r2, r1, model_name TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_CONCAT_RIGHT(r3, r2, ".php");
			PHALCON_CPY_WRT(model_path, r3);
			if (phalcon_file_exists(model_path TSRMLS_CC) == SUCCESS) {
				if (phalcon_require(model_path TSRMLS_CC) == FAILURE) {
					return;
				}
				
				PHALCON_ALLOC_ZVAL_MM(r4);
				
				PHALCON_INIT_VAR(c1);
				ZVAL_BOOL(c1, 0);
				PHALCON_CALL_FUNC_PARAMS_2(r4, "class_exists", model_name, c1, 0x012);
				if (!zend_is_true(r4)) {
					PHALCON_ALLOC_ZVAL_MM(i0);
					object_init_ex(i0, phalcon_model_exception_ce);
					PHALCON_ALLOC_ZVAL_MM(r5);
					PHALCON_CONCAT_BOTH(r5,  "Class \"", model_name, "\"  not be found in the model file");
					PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r5, PHALCON_CHECK);
					phalcon_throw_exception(i0 TSRMLS_CC);
					return;
				}
				
				ce0 = phalcon_fetch_class(model_name TSRMLS_CC);
				
				PHALCON_ALLOC_ZVAL_MM(i1);
				object_init_ex(i1, ce0);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", this_ptr, PHALCON_CHECK);
				PHALCON_CPY_WRT(model, i1);
				
				PHALCON_ALLOC_ZVAL_MM(r6);
				PHALCON_CALL_METHOD(r6, this_ptr, "getconnection", PHALCON_NO_CHECK);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(model, "setconnection", r6, PHALCON_NO_CHECK);
				
				PHALCON_ALLOC_ZVAL_MM(t3);
				phalcon_read_property(&t3, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY TSRMLS_CC);
				phalcon_array_update(&t3, model_name, &model, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, "_models", strlen("_models"), t3 TSRMLS_CC);
			} else {
				PHALCON_ALLOC_ZVAL_MM(i2);
				object_init_ex(i2, phalcon_model_exception_ce);
				PHALCON_ALLOC_ZVAL_MM(r7);
				PHALCON_CONCAT_BOTH(r7,  "Class file path for model \"", model_name, "\" could not be found");
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i2, "__construct", r7, PHALCON_CHECK);
				phalcon_throw_exception(i2 TSRMLS_CC);
				return;
			}
		} else {
			ce1 = phalcon_fetch_class(model_name TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(i3);
			object_init_ex(i3, ce1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i3, "__construct", this_ptr, PHALCON_CHECK);
			PHALCON_CPY_WRT(model, i3);
			
			PHALCON_ALLOC_ZVAL_MM(r8);
			PHALCON_CALL_METHOD(r8, this_ptr, "getconnection", PHALCON_NO_CHECK);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(model, "setconnection", r8, PHALCON_NO_CHECK);
			
			PHALCON_ALLOC_ZVAL_MM(t4);
			phalcon_read_property(&t4, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY TSRMLS_CC);
			phalcon_array_update(&t4, model_name, &model, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, "_models", strlen("_models"), t4 TSRMLS_CC);
		}
	}
	PHALCON_MM_RESTORE();
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

	zval *model_name = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, model_name);
	if (!eval_int) {
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "load", model_name, PHALCON_NO_CHECK);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch(&r0, t1, model_name, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(r0);
}

/**
 * Gets the possible source model name from its class name
 *
 * @param string $modelName
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Manager, getSource){

	zval *model_name = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, phalcon_model_manager_ce, "_sourceNames", sizeof("_sourceNames")-1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_array_fetch(&t1, t0, model_name, PHALCON_SILENT TSRMLS_CC);
	if (!zend_is_true(t1)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_STATIC_PARAMS_1(r0, "phalcon_text", "uncamelize", model_name);
		t2 = zend_read_static_property(phalcon_model_manager_ce, "_sourceNames", sizeof("_sourceNames")-1, PHALCON_FETCH_CLASS_SILENT);
		if (Z_TYPE_P(t2) != IS_ARRAY) {
			convert_to_array(t2);
		}
		phalcon_array_update(&t2, model_name, &r0, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		zend_update_static_property(phalcon_model_manager_ce, "_sourceNames", sizeof("_sourceNames")-1, t2 TSRMLS_CC);
		
	}
	PHALCON_OBSERVE_VAR(t3);
	phalcon_read_static_property(&t3, phalcon_model_manager_ce, "_sourceNames", sizeof("_sourceNames")-1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_array_fetch(&t4, t3, model_name, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t4);
}

/**
 * Gets default connection to the database. All models by default will use connection returned by this method
 *
 * @return Phalcon_Db
 */
PHP_METHOD(Phalcon_Model_Manager, getConnection){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *i0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_STATIC(r0, "phalcon_transaction_manager", "isautomatic");
		if (zend_is_true(r0)) {
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_CALL_STATIC(r2, "phalcon_transaction_manager", "get");
			PHALCON_CALL_METHOD(r1, r2, "getconnection", PHALCON_NO_CHECK);
			PHALCON_RETURN_DZVAL(r1);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_CALL_STATIC(r3, "phalcon_db_pool", "hasdefaultdescriptor");
			if (!zend_is_true(r3)) {
				PHALCON_ALLOC_ZVAL_MM(i0);
				object_init_ex(i0, phalcon_exception_ce);
				PHALCON_INIT_VAR(c0);
				ZVAL_STRING(c0, "There is not defined database connection parameters", 1);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
				phalcon_throw_exception(i0 TSRMLS_CC);
				return;
			}
			
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CALL_STATIC(r4, "phalcon_db_pool", "getconnection");
			phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), r4 TSRMLS_CC);
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t1);
}

/**
 * Setup a 1-1 relation between two models
 *
 * @param Phalcon_Model_Base $model
 * @param mixed $fields
 * @param string $referenceModel
 * @param mixed $referencedFields
 * @param array $options
 */
PHP_METHOD(Phalcon_Model_Manager, addHasOne){

	zval *model = NULL, *fields = NULL, *reference_model = NULL, *referenced_fields = NULL;
	zval *options = NULL, *entity_name = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *i0 = NULL;
	zval *c0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &model, &fields, &reference_model, &referenced_fields, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(options, a0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_get_class(r0, model TSRMLS_CC);
	PHALCON_CPY_WRT(entity_name, r0);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, entity_name);
	if (!eval_int) {
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY TSRMLS_CC);
		phalcon_array_update(&t1, entity_name, &a1, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_hasOne", strlen("_hasOne"), t1 TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch(&r1, t2, entity_name, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(r1, reference_model);
	if (!eval_int) {
		if (Z_TYPE_P(referenced_fields) == IS_ARRAY) { 
			PHALCON_ALLOC_ZVAL_MM(r2);
			phalcon_fast_count(r2, fields TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_fast_count(r3, referenced_fields TSRMLS_CC);
			PHALCON_INIT_VAR(r4);
			is_not_equal_function(r4, r2, r3 TSRMLS_CC);
			if (zend_is_true(r4)) {
				PHALCON_ALLOC_ZVAL_MM(i0);
				object_init_ex(i0, phalcon_model_exception_ce);
				PHALCON_INIT_VAR(c0);
				ZVAL_STRING(c0, "Number of referenced fields are not the same", 1);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
				phalcon_throw_exception(i0 TSRMLS_CC);
				return;
			}
		}
		
		PHALCON_INIT_VAR(a2);
		array_init(a2);
		phalcon_array_update_string(&a2, "fi", strlen("fi"), &fields, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		phalcon_array_update_string(&a2, "rt", strlen("rt"), &reference_model, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		phalcon_array_update_string(&a2, "rf", strlen("rf"), &referenced_fields, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		phalcon_array_update_string(&a2, "op", strlen("op"), &options, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY TSRMLS_CC);
		phalcon_array_update_multi_2(&t3, entity_name, reference_model, &a2, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_hasOne", strlen("_hasOne"), t3 TSRMLS_CC);
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Setup a relation reverse 1-1  between two models
 *
 * @param Phalcon_Model_Base $model
 * @param mixed $fields
 * @param string $referenceModel
 * @param mixed $referencedFields
 * @param array $options
 */
PHP_METHOD(Phalcon_Model_Manager, addBelongsTo){

	zval *model = NULL, *fields = NULL, *reference_model = NULL, *referenced_fields = NULL;
	zval *options = NULL, *model_name = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *i0 = NULL;
	zval *c0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &model, &fields, &reference_model, &referenced_fields, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(options, a0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_get_class(r0, model TSRMLS_CC);
	PHALCON_CPY_WRT(model_name, r0);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, model_name);
	if (!eval_int) {
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY TSRMLS_CC);
		phalcon_array_update(&t1, model_name, &a1, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_belongsTo", strlen("_belongsTo"), t1 TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch(&r1, t2, model_name, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(r1, reference_model);
	if (!eval_int) {
		if (Z_TYPE_P(referenced_fields) == IS_ARRAY) { 
			PHALCON_ALLOC_ZVAL_MM(r2);
			phalcon_fast_count(r2, fields TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_fast_count(r3, referenced_fields TSRMLS_CC);
			PHALCON_INIT_VAR(r4);
			is_not_equal_function(r4, r2, r3 TSRMLS_CC);
			if (zend_is_true(r4)) {
				PHALCON_ALLOC_ZVAL_MM(i0);
				object_init_ex(i0, phalcon_model_exception_ce);
				PHALCON_INIT_VAR(c0);
				ZVAL_STRING(c0, "Number of referenced fields are not the same", 1);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
				phalcon_throw_exception(i0 TSRMLS_CC);
				return;
			}
		}
		
		PHALCON_INIT_VAR(a2);
		array_init(a2);
		phalcon_array_update_string(&a2, "fi", strlen("fi"), &fields, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		phalcon_array_update_string(&a2, "rt", strlen("rt"), &reference_model, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		phalcon_array_update_string(&a2, "rf", strlen("rf"), &referenced_fields, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		phalcon_array_update_string(&a2, "op", strlen("op"), &options, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY TSRMLS_CC);
		phalcon_array_update_multi_2(&t3, model_name, reference_model, &a2, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_belongsTo", strlen("_belongsTo"), t3 TSRMLS_CC);
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Setup a relation 1-n between two models
 *
 * @param Phalcon_Model_Base $model
 * @param mixed $fields
 * @param string $referenceModel
 * @param mixed $referencedFields
 * @param array $options
 */
PHP_METHOD(Phalcon_Model_Manager, addHasMany){

	zval *model = NULL, *fields = NULL, *reference_model = NULL, *referenced_fields = NULL;
	zval *options = NULL, *entity_name = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *i0 = NULL;
	zval *c0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &model, &fields, &reference_model, &referenced_fields, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(options, a0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_get_class(r0, model TSRMLS_CC);
	PHALCON_CPY_WRT(entity_name, r0);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, entity_name);
	if (!eval_int) {
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY TSRMLS_CC);
		phalcon_array_update(&t1, entity_name, &a1, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_hasMany", strlen("_hasMany"), t1 TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch(&r1, t2, entity_name, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(r1, reference_model);
	if (!eval_int) {
		if (Z_TYPE_P(referenced_fields) == IS_ARRAY) { 
			PHALCON_ALLOC_ZVAL_MM(r2);
			phalcon_fast_count(r2, fields TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_fast_count(r3, referenced_fields TSRMLS_CC);
			PHALCON_INIT_VAR(r4);
			is_not_equal_function(r4, r2, r3 TSRMLS_CC);
			if (zend_is_true(r4)) {
				PHALCON_ALLOC_ZVAL_MM(i0);
				object_init_ex(i0, phalcon_model_exception_ce);
				PHALCON_INIT_VAR(c0);
				ZVAL_STRING(c0, "Number of referenced fields are not the same", 1);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
				phalcon_throw_exception(i0 TSRMLS_CC);
				return;
			}
		}
		
		PHALCON_INIT_VAR(a2);
		array_init(a2);
		phalcon_array_update_string(&a2, "fi", strlen("fi"), &fields, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		phalcon_array_update_string(&a2, "rt", strlen("rt"), &reference_model, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		phalcon_array_update_string(&a2, "rf", strlen("rf"), &referenced_fields, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		phalcon_array_update_string(&a2, "op", strlen("op"), &options, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY TSRMLS_CC);
		phalcon_array_update_multi_2(&t3, entity_name, reference_model, &a2, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_hasMany", strlen("_hasMany"), t3 TSRMLS_CC);
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Checks whether a model has a belongsTo relation with another model
 *
 * @access public
 * @param string $modelName
 * @param string $modelRelation
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Manager, existsBelongsTo){

	zval *model_name = NULL, *model_relation = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &model_name, &model_relation) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, model_name);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, t1, model_name, PHALCON_NOISY TSRMLS_CC);
		eval_int = phalcon_array_isset(r0, model_relation);
		if (eval_int) {
			PHALCON_MM_RESTORE();
			RETURN_TRUE;
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Checks whether a model has a hasMany relation with another model
 *
 * @param string $modelName
 * @param string $modelRelation
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Manager, existsHasMany){

	zval *model_name = NULL, *model_relation = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &model_name, &model_relation) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, model_name);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, t1, model_name, PHALCON_NOISY TSRMLS_CC);
		eval_int = phalcon_array_isset(r0, model_relation);
		if (eval_int) {
			PHALCON_MM_RESTORE();
			RETURN_TRUE;
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Checks whether a model has a hasOne relation with another model
 *
 * @param string $modelName
 * @param string $modelRelation
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Manager, existsHasOne){

	zval *model_name = NULL, *model_relation = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &model_name, &model_relation) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, model_name);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, t1, model_name, PHALCON_NOISY TSRMLS_CC);
		eval_int = phalcon_array_isset(r0, model_relation);
		if (eval_int) {
			PHALCON_MM_RESTORE();
			RETURN_TRUE;
		}
	}
	PHALCON_MM_RESTORE();
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

	zval *relation = NULL, *method = NULL, *record = NULL, *conditions = NULL, *value = NULL;
	zval *i = NULL, *referenced_field = NULL, *number_args = NULL, *key = NULL;
	zval *find_params = NULL, *reference_table = NULL, *referenced_entity = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *c0 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &relation, &method, &record) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(conditions, a0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, relation, "fi", strlen("fi"), PHALCON_NOISY TSRMLS_CC);
	if (Z_TYPE_P(r0) != IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_string(&r2, relation, "fi", strlen("fi"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_1(r1, record, "readattribute", r2, PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(value, r1);
		
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, relation, "rf", strlen("rf"), PHALCON_NOISY TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_VBOTH(r3, r4, " = '", value);
		
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_RIGHT(r5, r3, "'");
		phalcon_array_update_long(&conditions, 0, &r5, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(i);
		ZVAL_LONG(i, 0);
		
		PHALCON_ALLOC_ZVAL_MM(r6);
		phalcon_array_fetch_string(&r6, relation, "fi", strlen("fi"), PHALCON_NOISY TSRMLS_CC);
		if (phalcon_valid_foreach(r6 TSRMLS_CC)) {
			ah0 = Z_ARRVAL_P(r6);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_7231_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_7231_0;
			}
			
			PHALCON_INIT_VAR(referenced_field);
			ZVAL_ZVAL(referenced_field, *hd, 1, 0);
			PHALCON_INIT_VAR(r7);
			PHALCON_INIT_VAR(r8);
			phalcon_array_fetch_string(&r8, relation, "fi", strlen("fi"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_INIT_VAR(r9);
			phalcon_array_fetch(&r9, r8, i, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_1(r7, record, "readattribute", r9, PHALCON_NO_CHECK);
			PHALCON_CPY_WRT(value, r7);
			
			PHALCON_INIT_VAR(r11);
			phalcon_array_fetch_string(&r11, relation, "rf", strlen("rf"), PHALCON_NOISY TSRMLS_CC);
			
			PHALCON_INIT_VAR(r12);
			phalcon_array_fetch(&r12, r11, i, PHALCON_NOISY TSRMLS_CC);
			
			PHALCON_INIT_VAR(r10);
			PHALCON_CONCAT_VBOTH(r10, r12, " = '", value);
			
			PHALCON_INIT_VAR(r13);
			PHALCON_CONCAT_RIGHT(r13, r10, "'");
			phalcon_array_append(&conditions, r13, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			PHALCON_SEPARATE(i);
			increment_function(i);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_7231_0;
			fee_7231_0:
			if(0){}
		} else {
			return;
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(r14);
	PHALCON_CALL_FUNC(r14, "func_num_args", 0x052);
	PHALCON_CPY_WRT(number_args, r14);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 4);
	
	PHALCON_INIT_VAR(r15);
	is_smaller_function(r15, t0, number_args TSRMLS_CC);
	if (zend_is_true(r15)) {
		PHALCON_ALLOC_ZVAL_MM(r16);
		PHALCON_CALL_FUNC(r16, "func_get_args", 0x053);
		if (phalcon_valid_foreach(r16 TSRMLS_CC)) {
			ah1 = Z_ARRVAL_P(r16);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes_7231_1:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_7231_1;
			} else {
				PHALCON_INIT_VAR(key);
				PHALCON_GET_FOREACH_KEY(key, ah1, hp1);
			}
			PHALCON_INIT_VAR(value);
			ZVAL_ZVAL(value, *hd, 1, 0);
			PHALCON_INIT_VAR(t1);
			ZVAL_LONG(t1, 0);
			PHALCON_INIT_VAR(r17);
			is_equal_function(r17, key, t1 TSRMLS_CC);
			PHALCON_INIT_VAR(t2);
			ZVAL_STRING(t2, "conditions", 1);
			PHALCON_INIT_VAR(r18);
			is_equal_function(r18, key, t2 TSRMLS_CC);
			PHALCON_INIT_VAR(r19);
			ZVAL_BOOL(r19, zend_is_true(r17) || zend_is_true(r18));
			if (zend_is_true(r19)) {
				phalcon_array_append(&conditions, value, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_7231_1;
			fee_7231_1:
			if(0){}
		} else {
			return;
		}
	}
	
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, " AND ", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r20);
	phalcon_fast_join(r20, c0, conditions TSRMLS_CC);
	phalcon_array_append(&a1, r20, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	PHALCON_CPY_WRT(find_params, a1);
	
	PHALCON_ALLOC_ZVAL_MM(r21);
	phalcon_array_fetch_string(&r21, relation, "rt", strlen("rt"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(reference_table, r21);
	
	PHALCON_ALLOC_ZVAL_MM(r22);
	PHALCON_CALL_METHOD_PARAMS_1(r22, this_ptr, "getmodel", reference_table, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(referenced_entity, r22);
	
	PHALCON_ALLOC_ZVAL_MM(r23);
	PHALCON_CALL_METHOD(r23, record, "getconnection", PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(referenced_entity, "setconnection", r23, PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r24);
	
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	phalcon_array_append(&a2, referenced_entity, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	phalcon_array_append(&a2, method, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_2(r24, "call_user_func_array", a2, find_params, 0x013);
	PHALCON_RETURN_DZVAL(r24);
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

	zval *method = NULL, *model_name = NULL, *model_relation = NULL, *record = NULL;
	zval *relation = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &method, &model_name, &model_relation, &record) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, model_name);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, t1, model_name, PHALCON_NOISY TSRMLS_CC);
		eval_int = phalcon_array_isset(r0, model_relation);
		if (!eval_int) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch(&r1, t2, model_name, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch(&r2, r1, model_relation, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(relation, r2);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_METHOD_PARAMS_3(r3, this_ptr, "_getrelationrecords", relation, method, record, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r3);
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

	zval *method = NULL, *model_name = NULL, *model_relation = NULL, *record = NULL;
	zval *relation = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &method, &model_name, &model_relation, &record) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, model_name);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, t1, model_name, PHALCON_NOISY TSRMLS_CC);
		eval_int = phalcon_array_isset(r0, model_relation);
		if (!eval_int) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch(&r1, t2, model_name, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch(&r2, r1, model_relation, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(relation, r2);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_METHOD_PARAMS_3(r3, this_ptr, "_getrelationrecords", relation, method, record, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r3);
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

	zval *method = NULL, *model_name = NULL, *model_relation = NULL, *record = NULL;
	zval *relation = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &method, &model_name, &model_relation, &record) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, model_name);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, t1, model_name, PHALCON_NOISY TSRMLS_CC);
		eval_int = phalcon_array_isset(r0, model_relation);
		if (!eval_int) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch(&r1, t2, model_name, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch(&r2, r1, model_relation, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(relation, r2);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_METHOD_PARAMS_3(r3, this_ptr, "_getrelationrecords", relation, method, record, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r3);
}

/**
 * Gets belongsTo relations defined on a model
 *
 * @param  Phalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_Manager, getBelongsTo){

	zval *model = NULL, *model_name = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *a0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_get_class(r0, model TSRMLS_CC);
	PHALCON_CPY_WRT(model_name, r0);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, model_name);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_belongsTo", sizeof("_belongsTo")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch(&r1, t1, model_name, PHALCON_NOISY TSRMLS_CC);
		
		PHALCON_RETURN_CHECK_CTOR(r1);
	}
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	
	PHALCON_RETURN_CTOR(a0);
}

/**
 * Gets hasMany relations defined on a model
 *
 * @param  Phalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_Manager, getHasMany){

	zval *model = NULL, *model_name = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *a0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_get_class(r0, model TSRMLS_CC);
	PHALCON_CPY_WRT(model_name, r0);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, model_name);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_hasMany", sizeof("_hasMany")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch(&r1, t1, model_name, PHALCON_NOISY TSRMLS_CC);
		
		PHALCON_RETURN_CHECK_CTOR(r1);
	}
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	
	PHALCON_RETURN_CTOR(a0);
}

/**
 * Gets hasOne relations defined on a model
 *
 * @param  Phalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_Manager, getHasOne){

	zval *model = NULL, *model_name = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *a0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_get_class(r0, model TSRMLS_CC);
	PHALCON_CPY_WRT(model_name, r0);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, model_name);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_hasOne", sizeof("_hasOne")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch(&r1, t1, model_name, PHALCON_NOISY TSRMLS_CC);
		
		PHALCON_RETURN_CHECK_CTOR(r1);
	}
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	
	PHALCON_RETURN_CTOR(a0);
}

/**
 * Gets hasOne relations defined on a model
 *
 * @param  Phalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_Manager, getHasOneAndHasMany){

	zval *model = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "gethasone", model, PHALCON_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD_PARAMS_1(r2, this_ptr, "gethasmany", model, PHALCON_NO_CHECK);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "array_merge", r1, r2, 0x043);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Autoload function for model lazy loading
 *
 * @param string $className
 */
PHP_METHOD(Phalcon_Model_Manager, autoload){

	zval *class_name = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &class_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "ismodel", class_name, PHALCON_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

