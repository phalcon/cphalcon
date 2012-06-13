
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
#include "kernel/concat.h"
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
     * @param Phalcon_Config|stdClass $options
 */
PHP_METHOD(Phalcon_Model_Manager, __construct){

	zval *options = NULL, *model_options = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL;
	zval *t0 = NULL;
	zval *i0 = NULL;

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
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(options);
		ZVAL_NULL(options);
	}
	
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, phalcon_model_manager_ce, "_default", sizeof("_default")-1 TSRMLS_CC);
	if (!zend_is_true(t0)) {
		zend_update_static_property(phalcon_model_manager_ce, "_default", sizeof("_default")-1, this_ptr TSRMLS_CC);
	}
	if (zend_is_true(options)) {
		PHALCON_CPY_WRT(model_options, options);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init(i0);
		PHALCON_CPY_WRT(model_options, i0);
	}
	
	phalcon_update_property_zval(this_ptr, "_options", strlen("_options"), model_options TSRMLS_CC);
	
	PHALCON_INIT_VAR(a5);
	array_init(a5);
	phalcon_array_append(&a5, this_ptr, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	add_next_index_stringl(a5, "autoload", strlen("autoload"), 1);
	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("spl_autoload_register", a5, 0x000);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets base path. Depending of your platform, always add a trailing slash or backslash
 *
 * @param string $basePath
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
 * @param object $metadata
 */
PHP_METHOD(Phalcon_Model_Manager, setMetaData){

	zval *metadata = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &metadata) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(metadata) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_model_exception_ce, "Meta-data must be an object instance similar to Phalcon_Model_Metadata");
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

	zval *metadata = NULL, *adapter = NULL, *options = NULL, *options_metadata = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *a0 = NULL;
	zval *i0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_metadata", sizeof("_metadata")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(metadata, t0);
	if (!zend_is_true(metadata)) {
		PHALCON_INIT_VAR(adapter);
		ZVAL_NULL(adapter);
		
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_options", sizeof("_options")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(options, t1);
		eval_int = phalcon_isset_property(options, "metadata", strlen("metadata") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t2);
			phalcon_read_property(&t2, options, "metadata", sizeof("metadata")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(options_metadata, t2);
			eval_int = phalcon_isset_property(options_metadata, "adapter", strlen("adapter") TSRMLS_CC);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(t3);
				phalcon_read_property(&t3, options_metadata, "adapter", sizeof("adapter")-1, PHALCON_NOISY TSRMLS_CC);
				PHALCON_CPY_WRT(adapter, t3);
			}
		}
		
		if (!zend_is_true(adapter)) {
			PHALCON_INIT_VAR(adapter);
			ZVAL_STRING(adapter, "Memory", 1);
			
			PHALCON_INIT_VAR(a0);
			array_init(a0);
			PHALCON_CPY_WRT(options_metadata, a0);
		}
		
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_metadata_ce);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i0, "__construct", adapter, options_metadata, PHALCON_CHECK);
		PHALCON_CPY_WRT(metadata, i0);
		phalcon_update_property_zval(this_ptr, "_metadata", strlen("_metadata"), metadata TSRMLS_CC);
	}
	
	
	PHALCON_RETURN_CHECK_CTOR(metadata);
}

/**
 * Overwrites default meta-data manager
 *
 * @param object $cache
 */
PHP_METHOD(Phalcon_Model_Manager, setCache){

	zval *cache = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &cache) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(cache) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_model_exception_ce, "Cache must be an object instance");
		return;
	}
	phalcon_update_property_zval(this_ptr, "_cache", strlen("_cache"), cache TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns default cache backend. This cache will be used to store resultsets and generated SQL
 *
 * @return Phalcon_Cache_Backend
 */
PHP_METHOD(Phalcon_Model_Manager, getCache){

	zval *cache = NULL, *options = NULL, *options_cache = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL };
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_cache", sizeof("_cache")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(cache, t0);
	if (!zend_is_true(cache)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_options", sizeof("_options")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(options, t1);
		eval_int = phalcon_isset_property(options, "cache", strlen("cache") TSRMLS_CC);
		if (!eval_int) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_model_exception_ce, "Cache options aren't set");
			return;
		}
		
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, options, "cache", sizeof("cache")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_SEPARATE_NMO(t2);
		convert_to_array(t2);
		PHALCON_CPY_WRT(options_cache, t2);
		eval_int = phalcon_array_isset_string(options_cache, "adapter", strlen("adapter")+1);
		if (!eval_int) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_model_exception_ce, "Backend cache adapter aren't defined in options");
			return;
		}
		
		PHALCON_ALLOC_ZVAL_MM(r0);
		
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Data", 1);
		
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, options_cache, "adapter", strlen("adapter"), PHALCON_NOISY TSRMLS_CC);
		p0[1] = r1;
		p0[2] = options_cache;
		p0[3] = options_cache;
		PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_cache", "factory", 4, p0);
		PHALCON_CPY_WRT(cache, r0);
		phalcon_update_property_zval(this_ptr, "_cache", strlen("_cache"), cache TSRMLS_CC);
	}
	
	
	PHALCON_RETURN_CHECK_CTOR(cache);
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
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
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
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_ALLOC_ZVAL_MM(t1);
			phalcon_read_property(&t1, this_ptr, "_basePath", sizeof("_basePath")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(t2);
			phalcon_read_property(&t2, this_ptr, "_modelsDir", sizeof("_modelsDir")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CONCAT_VVVS(r1, t1, t2, model_name, ".php");
			PHALCON_CPY_WRT(model_path, r1);
			if (phalcon_file_exists(model_path TSRMLS_CC) == SUCCESS) {
				PHALCON_ALLOC_ZVAL_MM(r2);
				PHALCON_CALL_METHOD_PARAMS_1(r2, this_ptr, "load", model_name, PHALCON_NO_CHECK);
				PHALCON_RETURN_DZVAL(r2);
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
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_ALLOC_ZVAL_MM(t1);
			phalcon_read_property(&t1, this_ptr, "_basePath", sizeof("_basePath")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(t2);
			phalcon_read_property(&t2, this_ptr, "_modelsDir", sizeof("_modelsDir")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CONCAT_VVVS(r1, t1, t2, model_name, ".php");
			PHALCON_CPY_WRT(model_path, r1);
			if (phalcon_file_exists(model_path TSRMLS_CC) == SUCCESS) {
				if (phalcon_require(model_path TSRMLS_CC) == FAILURE) {
					return;
				}
				
				PHALCON_ALLOC_ZVAL_MM(r2);
				
				PHALCON_INIT_VAR(c1);
				ZVAL_BOOL(c1, 0);
				PHALCON_CALL_FUNC_PARAMS_2(r2, "class_exists", model_name, c1, 0x012);
				if (!zend_is_true(r2)) {
					PHALCON_ALLOC_ZVAL_MM(i0);
					object_init_ex(i0, phalcon_model_exception_ce);
					PHALCON_ALLOC_ZVAL_MM(r3);
					PHALCON_CONCAT_SVS(r3, "Class \"", model_name, "\"  not be found in the model file");
					PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r3, PHALCON_CHECK);
					phalcon_throw_exception(i0 TSRMLS_CC);
					return;
				}
				
				ce0 = phalcon_fetch_class(model_name TSRMLS_CC);
				
				PHALCON_ALLOC_ZVAL_MM(i1);
				object_init_ex(i1, ce0);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", this_ptr, PHALCON_CHECK);
				PHALCON_CPY_WRT(model, i1);
				
				PHALCON_ALLOC_ZVAL_MM(r4);
				PHALCON_CALL_METHOD(r4, this_ptr, "getconnection", PHALCON_NO_CHECK);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(model, "setconnection", r4, PHALCON_NO_CHECK);
				
				PHALCON_ALLOC_ZVAL_MM(t3);
				phalcon_read_property(&t3, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY TSRMLS_CC);
				phalcon_array_update(&t3, model_name, &model, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, "_models", strlen("_models"), t3 TSRMLS_CC);
			} else {
				PHALCON_ALLOC_ZVAL_MM(i2);
				object_init_ex(i2, phalcon_model_exception_ce);
				PHALCON_ALLOC_ZVAL_MM(r5);
				PHALCON_CONCAT_SVS(r5, "Class file path for model \"", model_name, "\" could not be found");
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i2, "__construct", r5, PHALCON_CHECK);
				phalcon_throw_exception(i2 TSRMLS_CC);
				return;
			}
		} else {
			ce1 = phalcon_fetch_class(model_name TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(i3);
			object_init_ex(i3, ce1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i3, "__construct", this_ptr, PHALCON_CHECK);
			PHALCON_CPY_WRT(model, i3);
			
			PHALCON_ALLOC_ZVAL_MM(r6);
			PHALCON_CALL_METHOD(r6, this_ptr, "getconnection", PHALCON_NO_CHECK);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(model, "setconnection", r6, PHALCON_NO_CHECK);
			
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
				PHALCON_THROW_EXCEPTION_STR(phalcon_exception_ce, "There is not defined database connection parameters");
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
				PHALCON_THROW_EXCEPTION_STR(phalcon_model_exception_ce, "Number of referenced fields are not the same");
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
				PHALCON_THROW_EXCEPTION_STR(phalcon_model_exception_ce, "Number of referenced fields are not the same");
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
				PHALCON_THROW_EXCEPTION_STR(phalcon_model_exception_ce, "Number of referenced fields are not the same");
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
	zval *r21 = NULL, *r22 = NULL;
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
		
		PHALCON_ALLOC_ZVAL_MM(r3);
		
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, relation, "rf", strlen("rf"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CONCAT_VSVS(r3, r4, " = '", value, "'");
		phalcon_array_update_long(&conditions, 0, &r3, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(i);
		ZVAL_LONG(i, 0);
		
		PHALCON_ALLOC_ZVAL_MM(r5);
		phalcon_array_fetch_string(&r5, relation, "fi", strlen("fi"), PHALCON_NOISY TSRMLS_CC);
		if (phalcon_valid_foreach(r5 TSRMLS_CC)) {
			ah0 = Z_ARRVAL_P(r5);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_7231_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_7231_0;
			}
			
			PHALCON_INIT_VAR(referenced_field);
			ZVAL_ZVAL(referenced_field, *hd, 1, 0);
			PHALCON_INIT_VAR(r6);
			PHALCON_INIT_VAR(r7);
			phalcon_array_fetch_string(&r7, relation, "fi", strlen("fi"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_INIT_VAR(r8);
			phalcon_array_fetch(&r8, r7, i, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_1(r6, record, "readattribute", r8, PHALCON_NO_CHECK);
			PHALCON_CPY_WRT(value, r6);
			
			PHALCON_INIT_VAR(r9);
			
			PHALCON_INIT_VAR(r10);
			phalcon_array_fetch_string(&r10, relation, "rf", strlen("rf"), PHALCON_NOISY TSRMLS_CC);
			
			PHALCON_INIT_VAR(r11);
			phalcon_array_fetch(&r11, r10, i, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CONCAT_VSVS(r9, r11, " = '", value, "'");
			phalcon_array_append(&conditions, r9, PHALCON_SEPARATE_PLZ TSRMLS_CC);
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
	
	PHALCON_ALLOC_ZVAL_MM(r12);
	PHALCON_CALL_FUNC(r12, "func_num_args", 0x052);
	PHALCON_CPY_WRT(number_args, r12);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 4);
	
	PHALCON_INIT_VAR(r13);
	is_smaller_function(r13, t0, number_args TSRMLS_CC);
	if (zend_is_true(r13)) {
		PHALCON_ALLOC_ZVAL_MM(r14);
		PHALCON_CALL_FUNC(r14, "func_get_args", 0x053);
		if (phalcon_valid_foreach(r14 TSRMLS_CC)) {
			ah1 = Z_ARRVAL_P(r14);
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
			PHALCON_INIT_VAR(r15);
			is_equal_function(r15, key, t1 TSRMLS_CC);
			PHALCON_INIT_VAR(t2);
			ZVAL_STRING(t2, "conditions", 1);
			PHALCON_INIT_VAR(r16);
			is_equal_function(r16, key, t2 TSRMLS_CC);
			PHALCON_INIT_VAR(r17);
			ZVAL_BOOL(r17, zend_is_true(r15) || zend_is_true(r16));
			if (zend_is_true(r17)) {
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
	
	PHALCON_ALLOC_ZVAL_MM(r18);
	phalcon_fast_join(r18, c0, conditions TSRMLS_CC);
	phalcon_array_append(&a1, r18, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	PHALCON_CPY_WRT(find_params, a1);
	
	PHALCON_ALLOC_ZVAL_MM(r19);
	phalcon_array_fetch_string(&r19, relation, "rt", strlen("rt"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(reference_table, r19);
	
	PHALCON_ALLOC_ZVAL_MM(r20);
	PHALCON_CALL_METHOD_PARAMS_1(r20, this_ptr, "getmodel", reference_table, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(referenced_entity, r20);
	
	PHALCON_ALLOC_ZVAL_MM(r21);
	PHALCON_CALL_METHOD(r21, record, "getconnection", PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(referenced_entity, "setconnection", r21, PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r22);
	
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	phalcon_array_append(&a2, referenced_entity, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	phalcon_array_append(&a2, method, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_2(r22, "call_user_func_array", a2, find_params, 0x013);
	PHALCON_RETURN_DZVAL(r22);
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
 * Returns the complete on which manager is looking for models
 *
 * @return string
 */
PHP_METHOD(Phalcon_Model_Manager, getCompleteModelsPath){

	zval *r0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_basePath", sizeof("_basePath")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_modelsDir", sizeof("_modelsDir")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CONCAT_VV(r0, t0, t1);
	
	PHALCON_RETURN_CTOR(r0);
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

/**
 * Get the default Phalcon_Model_Manager (usually this first instantiated)
 *
 * @return Phalcon_Model_Manager
 */
PHP_METHOD(Phalcon_Model_Manager, getDefault){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, phalcon_model_manager_ce, "_default", sizeof("_default")-1 TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Resets internal default manager
 */
PHP_METHOD(Phalcon_Model_Manager, reset){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_NULL(t0);
	zend_update_static_property(phalcon_model_manager_ce, "_default", sizeof("_default")-1, t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

