
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

#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/require.h"

/**
 * Phalcon\Model\Manager
 *
 * Manages the creation of models into applications and their relationships.
 * Phacon\Model\Manager helps to control the creation of models across a request execution.
 *
 * 
 */

/**
 * Constructor for Phalcon\Model\Manager
 *
 * @param Phalcon\Config|stdClass $options
 */
PHP_METHOD(Phalcon_Model_Manager, __construct){

	zval *options = NULL, *model_options = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL, *a6 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	zend_update_property(phalcon_model_manager_ce, this_ptr, SL("_models"), a0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a1);
	array_init(a1);
	zend_update_property(phalcon_model_manager_ce, this_ptr, SL("_hasMany"), a1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a2);
	array_init(a2);
	zend_update_property(phalcon_model_manager_ce, this_ptr, SL("_hasOne"), a2 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a3);
	array_init(a3);
	zend_update_property(phalcon_model_manager_ce, this_ptr, SL("_belongsTo"), a3 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a4);
	array_init(a4);
	zend_update_property(phalcon_model_manager_ce, this_ptr, SL("_sourceNames"), a4 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a5);
	array_init(a5);
	zend_update_property(phalcon_model_manager_ce, this_ptr, SL("_initialized"), a5 TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_ALLOC_ZVAL_MM(options);
		ZVAL_NULL(options);
	}
	
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("phalcon\\model\\manager"), SL("_default") TSRMLS_CC);
	if (!zend_is_true(t0)) {
		phalcon_update_static_property(SL("phalcon\\model\\manager"), SL("_default"), this_ptr TSRMLS_CC);
	}
	if (zend_is_true(options)) {
		if (Z_TYPE_P(options) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_model_exception_ce, "Options parameter must be an object");
			return;
		}
		PHALCON_CPY_WRT(model_options, options);
	} else {
		PHALCON_INIT_VAR(model_options);
		object_init(model_options);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_options"), model_options TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a6);
	array_init(a6);
	phalcon_array_append(&a6, this_ptr, PH_SEPARATE TSRMLS_CC);
	add_next_index_stringl(a6, SL("autoload"), 1);
	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("spl_autoload_register", a6);
	
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

	phalcon_update_property_zval(this_ptr, SL("_basePath"), base_path TSRMLS_CC);
	
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
	phalcon_update_property_zval(this_ptr, SL("_metadata"), metadata TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns active meta-data manager. If not exist then one will be created
 *
 * @return Phalcon\Model\Metadata
 */
PHP_METHOD(Phalcon_Model_Manager, getMetaData){

	zval *metadata = NULL, *adapter = NULL, *options = NULL, *options_metadata = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(metadata);
	phalcon_read_property(&metadata, this_ptr, SL("_metadata"), PH_NOISY_CC);
	if (!zend_is_true(metadata)) {
		PHALCON_INIT_VAR(adapter);
		ZVAL_NULL(adapter);
		
		PHALCON_INIT_VAR(options);
		phalcon_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
		eval_int = phalcon_isset_property(options, SL("metadata") TSRMLS_CC);
		if (eval_int) {
			PHALCON_INIT_VAR(options_metadata);
			phalcon_read_property(&options_metadata, options, SL("metadata"), PH_NOISY_CC);
			eval_int = phalcon_isset_property(options_metadata, SL("adapter") TSRMLS_CC);
			if (eval_int) {
				PHALCON_INIT_VAR(adapter);
				phalcon_read_property(&adapter, options_metadata, SL("adapter"), PH_NOISY_CC);
			}
		}
		
		if (!zend_is_true(adapter)) {
			PHALCON_INIT_VAR(adapter);
			ZVAL_STRING(adapter, "Memory", 1);
			
			PHALCON_INIT_VAR(options_metadata);
			array_init(options_metadata);
		}
		
		PHALCON_INIT_VAR(metadata);
		object_init_ex(metadata, phalcon_model_metadata_ce);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(metadata, "__construct", adapter, options_metadata, PH_CHECK);
		phalcon_update_property_zval(this_ptr, SL("_metadata"), metadata TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(metadata);
}

/**
 * Set the cache object or cache parameters to make the view caching
 *
 * @param Phalcon\Cache\Backend|object $cache
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
	phalcon_update_property_zval(this_ptr, SL("_cache"), cache TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns default cache backend. This cache will be used to store resultsets and generated SQL
 *
 * @return Phalcon\Cache\Backend
 */
PHP_METHOD(Phalcon_Model_Manager, getCache){

	zval *cache = NULL, *options = NULL, *options_cache = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL };
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(cache);
	phalcon_read_property(&cache, this_ptr, SL("_cache"), PH_NOISY_CC);
	if (!zend_is_true(cache)) {
		PHALCON_INIT_VAR(options);
		phalcon_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
		eval_int = phalcon_isset_property(options, SL("cache") TSRMLS_CC);
		if (!eval_int) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_model_exception_ce, "Cache options aren't set");
			return;
		}
		
		PHALCON_ALLOC_ZVAL_MM(r0);
		
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, options, SL("cache"), PH_NOISY_CC);
		phalcon_cast(r0, t0, IS_ARRAY);
		PHALCON_CPY_WRT(options_cache, r0);
		eval_int = phalcon_array_isset_string(options_cache, SL("adapter")+1);
		if (!eval_int) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_model_exception_ce, "Backend cache adapter aren't defined in options");
			return;
		}
		
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Data", 1);
		
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, options_cache, SL("adapter"), PH_NOISY_CC);
		p0[1] = r1;
		p0[2] = options_cache;
		p0[3] = options_cache;
		
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_STATIC_PARAMS(r2, "phalcon\\cache", "factory", 4, p0);
		PHALCON_CPY_WRT(cache, r2);
		phalcon_update_property_zval(this_ptr, SL("_cache"), cache TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(cache);
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

	phalcon_update_property_zval(this_ptr, SL("_modelsDir"), models_dir TSRMLS_CC);
	
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
	phalcon_read_property(&t0, this_ptr, SL("_modelsDir"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Checks whether the given name is an existing model
 *
 * @param string $modelName
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Manager, isModel){

	zval *model_name = NULL, *model_path = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_models"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, model_name);
	if (!eval_int) {
		PHALCON_INIT_VAR(c0);
		ZVAL_BOOL(c0, 0);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_FUNC_PARAMS_2(r0, "class_exists", model_name, c0);
		if (!zend_is_true(r0)) {
			PHALCON_ALLOC_ZVAL_MM(t1);
			phalcon_read_property(&t1, this_ptr, SL("_basePath"), PH_NOISY_CC);
			PHALCON_ALLOC_ZVAL_MM(t2);
			phalcon_read_property(&t2, this_ptr, SL("_modelsDir"), PH_NOISY_CC);
			PHALCON_INIT_VAR(model_path);
			PHALCON_CONCAT_VVVS(model_path, t1, t2, model_name, ".php");
			if (phalcon_file_exists(model_path TSRMLS_CC) == SUCCESS) {
				PHALCON_ALLOC_ZVAL_MM(r1);
				PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "load", model_name, PH_NO_CHECK);
				RETURN_CTOR(r1);
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

	zval *model_name = NULL, *auto_connection = NULL, *model_path = NULL;
	zval *model = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	int eval_int;
	zend_class_entry *ce0, *ce1;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_models"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, model_name);
	if (!eval_int) {
		PHALCON_INIT_VAR(auto_connection);
		phalcon_read_property(&auto_connection, this_ptr, SL("_autoConnection"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(c0);
		ZVAL_BOOL(c0, 0);
		
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_FUNC_PARAMS_2(r0, "class_exists", model_name, c0);
		if (!zend_is_true(r0)) {
			PHALCON_ALLOC_ZVAL_MM(t1);
			phalcon_read_property(&t1, this_ptr, SL("_basePath"), PH_NOISY_CC);
			PHALCON_ALLOC_ZVAL_MM(t2);
			phalcon_read_property(&t2, this_ptr, SL("_modelsDir"), PH_NOISY_CC);
			PHALCON_INIT_VAR(model_path);
			PHALCON_CONCAT_VVVS(model_path, t1, t2, model_name, ".php");
			if (phalcon_file_exists(model_path TSRMLS_CC) == SUCCESS) {
				if (phalcon_require(model_path TSRMLS_CC) == FAILURE) {
					return;
				}
				
				PHALCON_INIT_VAR(c1);
				ZVAL_BOOL(c1, 0);
				
				PHALCON_ALLOC_ZVAL_MM(r1);
				PHALCON_CALL_FUNC_PARAMS_2(r1, "class_exists", model_name, c1);
				if (!zend_is_true(r1)) {
					PHALCON_ALLOC_ZVAL_MM(i0);
					object_init_ex(i0, phalcon_model_exception_ce);
					PHALCON_ALLOC_ZVAL_MM(r2);
					PHALCON_CONCAT_SVS(r2, "Class \"", model_name, "\"  not be found in the model file");
					PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r2, PH_CHECK);
					phalcon_throw_exception(i0 TSRMLS_CC);
					return;
				}
				
				ce0 = phalcon_fetch_class(model_name TSRMLS_CC);
				
				PHALCON_INIT_VAR(model);
				object_init_ex(model, ce0);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(model, "__construct", this_ptr, PH_CHECK);
				if (zend_is_true(auto_connection)) {
					PHALCON_ALLOC_ZVAL_MM(r3);
					PHALCON_CALL_METHOD(r3, this_ptr, "getconnection", PH_NO_CHECK);
					PHALCON_CALL_METHOD_PARAMS_1_NORETURN(model, "setconnection", r3, PH_NO_CHECK);
				}
				
				PHALCON_ALLOC_ZVAL_MM(t3);
				phalcon_read_property(&t3, this_ptr, SL("_models"), PH_NOISY_CC);
				phalcon_array_update(&t3, model_name, &model, PH_COPY TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, SL("_models"), t3 TSRMLS_CC);
			} else {
				PHALCON_ALLOC_ZVAL_MM(i1);
				object_init_ex(i1, phalcon_model_exception_ce);
				PHALCON_ALLOC_ZVAL_MM(r4);
				PHALCON_CONCAT_SVS(r4, "Class file path for model \"", model_name, "\" could not be found");
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", r4, PH_CHECK);
				phalcon_throw_exception(i1 TSRMLS_CC);
				return;
			}
		} else {
			ce1 = phalcon_fetch_class(model_name TSRMLS_CC);
			PHALCON_INIT_VAR(model);
			object_init_ex(model, ce1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(model, "__construct", this_ptr, PH_CHECK);
			if (zend_is_true(auto_connection)) {
				PHALCON_ALLOC_ZVAL_MM(r5);
				PHALCON_CALL_METHOD(r5, this_ptr, "getconnection", PH_NO_CHECK);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(model, "setconnection", r5, PH_NO_CHECK);
			}
			
			PHALCON_ALLOC_ZVAL_MM(t4);
			phalcon_read_property(&t4, this_ptr, SL("_models"), PH_NOISY_CC);
			phalcon_array_update(&t4, model_name, &model, PH_COPY TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, SL("_models"), t4 TSRMLS_CC);
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

/**
 * Gets/Instantiates model from directory
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
	phalcon_read_property(&t0, this_ptr, SL("_models"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, model_name);
	if (!eval_int) {
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "load", model_name, PH_NO_CHECK);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_models"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch(&r0, t1, model_name, PH_NOISY_CC);
	
	RETURN_CCTOR(r0);
}

/**
 * Initializes a model in the model manager
 *
 * @param Phalcon\Model\Base $model
 */
PHP_METHOD(Phalcon_Model_Manager, initialize){

	zval *model = NULL, *class_name = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(class_name);
	phalcon_get_class(class_name, model TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_initialized"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, class_name);
	if (!eval_int) {
		if (phalcon_method_exists_ex(model, SL("initialize") TSRMLS_CC) == SUCCESS) {
			PHALCON_CALL_METHOD_NORETURN(model, "initialize", PH_NO_CHECK);
		}
		
		PHALCON_INIT_VAR(t1);
		ZVAL_BOOL(t1, 1);
		
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, SL("_initialized"), PH_NOISY_CC);
		phalcon_array_update(&t2, class_name, &t1, PH_COPY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_initialized"), t2 TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets the possible source model name from its class name
 *
 * @param string $modelName
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Manager, getSource){

	zval *model_name = NULL, *source_names = NULL, *source_name = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(source_names);
	phalcon_read_property(&source_names, this_ptr, SL("_sourceNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(source_names, model_name);
	if (!eval_int) {
		PHALCON_INIT_VAR(source_name);
		PHALCON_CALL_STATIC_PARAMS_1(source_name, "phalcon\\text", "uncamelize", model_name);
		
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, SL("_sourceNames"), PH_NOISY_CC);
		phalcon_array_update(&t0, model_name, &source_name, PH_COPY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_sourceNames"), t0 TSRMLS_CC);
		
		RETURN_CCTOR(source_name);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch(&r0, source_names, model_name, PH_NOISY_CC);
	
	RETURN_CCTOR(r0);
}

/**
 * Sets the main connection that automatically is binded to all created models
 *
 * @param Phalcon\Db $connection
 */
PHP_METHOD(Phalcon_Model_Manager, setConnection){

	zval *connection = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &connection) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(connection) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_model_exception_ce, "$connection must be an Object");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_connection"), connection TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets default connection to the database. All models by default will use connection returned by this method
 *
 * @return Phalcon\Db
 */
PHP_METHOD(Phalcon_Model_Manager, getConnection){

	zval *connection = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(connection);
	phalcon_read_property(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	if (!zend_is_true(connection)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_STATIC(r0, "phalcon\\transaction\\manager", "isautomatic");
		if (zend_is_true(r0)) {
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_CALL_STATIC(r1, "phalcon\\transaction\\manager", "get");
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_CALL_METHOD(r2, r1, "getconnection", PH_NO_CHECK);
			RETURN_CTOR(r2);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_CALL_STATIC(r3, "phalcon\\db\\pool", "hasdefaultdescriptor");
			if (!zend_is_true(r3)) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_model_exception_ce, "There is not defined database connection parameters");
				return;
			}
			
			PHALCON_INIT_VAR(connection);
			PHALCON_CALL_STATIC(connection, "phalcon\\db\\pool", "getconnection");
			phalcon_update_property_zval(this_ptr, SL("_connection"), connection TSRMLS_CC);
		}
	}
	
	
	RETURN_CCTOR(connection);
}

/**
 * Sets if the models manager should create a default connection automatically and bind it to the created models
 *
 * @param boolean $autoConnection
 */
PHP_METHOD(Phalcon_Model_Manager, setAutoConnection){

	zval *auto_connection = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &auto_connection) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_autoConnection"), auto_connection TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Check whether the manager binds a database connection automatically to the created models
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Manager, haveAutoConnection){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_autoConnection"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
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
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &model, &fields, &reference_model, &referenced_fields, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_ALLOC_ZVAL_MM(a0);
		array_init(a0);
		PHALCON_CPY_WRT(options, a0);
	}
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_hasOne"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, entity_name);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(a1);
		array_init(a1);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_hasOne"), PH_NOISY_CC);
		phalcon_array_update(&t1, entity_name, &a1, PH_COPY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_hasOne"), t1 TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_hasOne"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch(&r0, t2, entity_name, PH_NOISY_CC);
	eval_int = phalcon_array_isset(r0, reference_model);
	if (!eval_int) {
		if (Z_TYPE_P(referenced_fields) == IS_ARRAY) { 
			PHALCON_ALLOC_ZVAL_MM(r1);
			phalcon_fast_count(r1, fields TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r2);
			phalcon_fast_count(r2, referenced_fields TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r3);
			is_not_equal_function(r3, r1, r2 TSRMLS_CC);
			if (zend_is_true(r3)) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_model_exception_ce, "Number of referenced fields are not the same");
				return;
			}
		}
		
		PHALCON_ALLOC_ZVAL_MM(a2);
		array_init(a2);
		phalcon_array_update_string(&a2, SL("fi"), &fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&a2, SL("rt"), &reference_model, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&a2, SL("rf"), &referenced_fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&a2, SL("op"), &options, PH_COPY | PH_SEPARATE TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, SL("_hasOne"), PH_NOISY_CC);
		phalcon_array_update_multi_2(&t3, entity_name, reference_model, &a2, 0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_hasOne"), t3 TSRMLS_CC);
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
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &model, &fields, &reference_model, &referenced_fields, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_ALLOC_ZVAL_MM(a0);
		array_init(a0);
		PHALCON_CPY_WRT(options, a0);
	}
	
	PHALCON_INIT_VAR(model_name);
	phalcon_get_class(model_name, model TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, model_name);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(a1);
		array_init(a1);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
		phalcon_array_update(&t1, model_name, &a1, PH_COPY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_belongsTo"), t1 TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch(&r0, t2, model_name, PH_NOISY_CC);
	eval_int = phalcon_array_isset(r0, reference_model);
	if (!eval_int) {
		if (Z_TYPE_P(referenced_fields) == IS_ARRAY) { 
			PHALCON_ALLOC_ZVAL_MM(r1);
			phalcon_fast_count(r1, fields TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r2);
			phalcon_fast_count(r2, referenced_fields TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r3);
			is_not_equal_function(r3, r1, r2 TSRMLS_CC);
			if (zend_is_true(r3)) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_model_exception_ce, "Number of referenced fields are not the same");
				return;
			}
		}
		
		PHALCON_ALLOC_ZVAL_MM(a2);
		array_init(a2);
		phalcon_array_update_string(&a2, SL("fi"), &fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&a2, SL("rt"), &reference_model, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&a2, SL("rf"), &referenced_fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&a2, SL("op"), &options, PH_COPY | PH_SEPARATE TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
		phalcon_array_update_multi_2(&t3, model_name, reference_model, &a2, 0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_belongsTo"), t3 TSRMLS_CC);
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
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &model, &fields, &reference_model, &referenced_fields, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_ALLOC_ZVAL_MM(a0);
		array_init(a0);
		PHALCON_CPY_WRT(options, a0);
	}
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, entity_name);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(a1);
		array_init(a1);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_hasMany"), PH_NOISY_CC);
		phalcon_array_update(&t1, entity_name, &a1, PH_COPY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_hasMany"), t1 TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch(&r0, t2, entity_name, PH_NOISY_CC);
	eval_int = phalcon_array_isset(r0, reference_model);
	if (!eval_int) {
		if (Z_TYPE_P(referenced_fields) == IS_ARRAY) { 
			PHALCON_ALLOC_ZVAL_MM(r1);
			phalcon_fast_count(r1, fields TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r2);
			phalcon_fast_count(r2, referenced_fields TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r3);
			is_not_equal_function(r3, r1, r2 TSRMLS_CC);
			if (zend_is_true(r3)) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_model_exception_ce, "Number of referenced fields are not the same");
				return;
			}
		}
		
		PHALCON_ALLOC_ZVAL_MM(a2);
		array_init(a2);
		phalcon_array_update_string(&a2, SL("fi"), &fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&a2, SL("rt"), &reference_model, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&a2, SL("rf"), &referenced_fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&a2, SL("op"), &options, PH_COPY | PH_SEPARATE TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, SL("_hasMany"), PH_NOISY_CC);
		phalcon_array_update_multi_2(&t3, entity_name, reference_model, &a2, 0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_hasMany"), t3 TSRMLS_CC);
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Checks whether a model has a belongsTo relation with another model
 * 
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
	phalcon_read_property(&t0, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, model_name);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, t1, model_name, PH_NOISY_CC);
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
	phalcon_read_property(&t0, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, model_name);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_hasMany"), PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, t1, model_name, PH_NOISY_CC);
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
	phalcon_read_property(&t0, this_ptr, SL("_hasOne"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, model_name);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_hasOne"), PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, t1, model_name, PH_NOISY_CC);
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
 * @param Phalcon\Model\Base $record
 */
PHP_METHOD(Phalcon_Model_Manager, _getRelationRecords){

	zval *relation = NULL, *method = NULL, *record = NULL, *conditions = NULL, *value = NULL;
	zval *i = NULL, *referenced_field = NULL, *number_args = NULL, *key = NULL;
	zval *find_params = NULL, *reference_table = NULL, *referenced_entity = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *c0 = NULL;
	zval *a0 = NULL;
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

	PHALCON_INIT_VAR(conditions);
	array_init(conditions);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, relation, SL("fi"), PH_NOISY_CC);
	if (Z_TYPE_P(r0) != IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, relation, SL("fi"), PH_NOISY_CC);
		PHALCON_INIT_VAR(value);
		PHALCON_CALL_METHOD_PARAMS_1(value, record, "readattribute", r1, PH_NO_CHECK);
		
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_string(&r2, relation, SL("rf"), PH_NOISY_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_VSVS(r3, r2, " = '", value, "'");
		phalcon_array_update_long(&conditions, 0, &r3, PH_COPY | PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(i);
		ZVAL_LONG(i, 0);
		
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, relation, SL("fi"), PH_NOISY_CC);
		if (phalcon_valid_foreach(r4 TSRMLS_CC)) {
			ah0 = Z_ARRVAL_P(r4);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_7231_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_7231_0;
			}
			
			PHALCON_INIT_VAR(referenced_field);
			ZVAL_ZVAL(referenced_field, *hd, 1, 0);
			PHALCON_INIT_VAR(r5);
			phalcon_array_fetch_string(&r5, relation, SL("fi"), PH_NOISY_CC);
			PHALCON_INIT_VAR(r6);
			phalcon_array_fetch(&r6, r5, i, PH_NOISY_CC);
			PHALCON_INIT_VAR(value);
			PHALCON_CALL_METHOD_PARAMS_1(value, record, "readattribute", r6, PH_NO_CHECK);
			
			PHALCON_INIT_VAR(r7);
			phalcon_array_fetch_string(&r7, relation, SL("rf"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(r8);
			phalcon_array_fetch(&r8, r7, i, PH_NOISY_CC);
			
			PHALCON_INIT_VAR(r9);
			PHALCON_CONCAT_VSVS(r9, r8, " = '", value, "'");
			phalcon_array_append(&conditions, r9, PH_SEPARATE TSRMLS_CC);
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
	
	PHALCON_INIT_VAR(number_args);
	PHALCON_CALL_FUNC(number_args, "func_num_args");
	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 4);
	
	PHALCON_ALLOC_ZVAL_MM(r10);
	is_smaller_function(r10, t0, number_args TSRMLS_CC);
	if (zend_is_true(r10)) {
		PHALCON_ALLOC_ZVAL_MM(r11);
		PHALCON_CALL_FUNC(r11, "func_get_args");
		if (phalcon_valid_foreach(r11 TSRMLS_CC)) {
			ah1 = Z_ARRVAL_P(r11);
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
			PHALCON_INIT_VAR(r12);
			is_equal_function(r12, key, t1 TSRMLS_CC);
			PHALCON_INIT_VAR(t2);
			ZVAL_STRING(t2, "conditions", 1);
			PHALCON_INIT_VAR(r13);
			is_equal_function(r13, key, t2 TSRMLS_CC);
			PHALCON_INIT_VAR(r14);
			ZVAL_BOOL(r14, zend_is_true(r12) || zend_is_true(r13));
			if (zend_is_true(r14)) {
				phalcon_array_append(&conditions, value, PH_SEPARATE TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_7231_1;
			fee_7231_1:
			if(0){}
		} else {
			return;
		}
	}
	
	PHALCON_INIT_VAR(find_params);
	array_init(find_params);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, " AND ", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r15);
	phalcon_fast_join(r15, c0, conditions TSRMLS_CC);
	phalcon_array_append(&find_params, r15, PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(reference_table);
	phalcon_array_fetch_string(&reference_table, relation, SL("rt"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(referenced_entity);
	PHALCON_CALL_METHOD_PARAMS_1(referenced_entity, this_ptr, "getmodel", reference_table, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r16);
	PHALCON_CALL_METHOD(r16, record, "getconnection", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(referenced_entity, "setconnection", r16, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	phalcon_array_append(&a0, referenced_entity, PH_SEPARATE TSRMLS_CC);
	phalcon_array_append(&a0, method, PH_SEPARATE TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r17);
	PHALCON_CALL_FUNC_PARAMS_2(r17, "call_user_func_array", a0, find_params);
	RETURN_CTOR(r17);
}

/**
 * Gets belongsTo related records from a model
 *
 * @param string $method
 * @param string $modelName
 * @param string $modelRelation
 * @param Phalcon\Model\Base $record
 * @return Phalcon\Model\Resultset
 */
PHP_METHOD(Phalcon_Model_Manager, getBelongsToRecords){

	zval *method = NULL, *model_name = NULL, *model_relation = NULL, *record = NULL;
	zval *relation = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &method, &model_name, &model_relation, &record) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, model_name);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, t1, model_name, PH_NOISY_CC);
		eval_int = phalcon_array_isset(r0, model_relation);
		if (!eval_int) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch(&r1, t2, model_name, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(relation);
	phalcon_array_fetch(&relation, r1, model_relation, PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD_PARAMS_3(r2, this_ptr, "_getrelationrecords", relation, method, record, PH_NO_CHECK);
	RETURN_CTOR(r2);
}

/**
 * Gets hasMany related records from a model
 *
 * @param string $method
 * @param string $modelName
 * @param string $modelRelation
 * @param Phalcon\Model\Base $record
 * @return Phalcon\Model\Resultset
 */
PHP_METHOD(Phalcon_Model_Manager, getHasManyRecords){

	zval *method = NULL, *model_name = NULL, *model_relation = NULL, *record = NULL;
	zval *relation = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &method, &model_name, &model_relation, &record) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, model_name);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_hasMany"), PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, t1, model_name, PH_NOISY_CC);
		eval_int = phalcon_array_isset(r0, model_relation);
		if (!eval_int) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch(&r1, t2, model_name, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(relation);
	phalcon_array_fetch(&relation, r1, model_relation, PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD_PARAMS_3(r2, this_ptr, "_getrelationrecords", relation, method, record, PH_NO_CHECK);
	RETURN_CTOR(r2);
}

/**
 * Gets belongsTo related records from a model
 *
 * @param string $method
 * @param string $modelName
 * @param string $modelRelation
 * @param Phalcon\Model\Base $record
 * @return Phalcon\Model\Resultset
 */
PHP_METHOD(Phalcon_Model_Manager, getHasOneRecords){

	zval *method = NULL, *model_name = NULL, *model_relation = NULL, *record = NULL;
	zval *relation = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &method, &model_name, &model_relation, &record) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_hasOne"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, model_name);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_hasOne"), PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, t1, model_name, PH_NOISY_CC);
		eval_int = phalcon_array_isset(r0, model_relation);
		if (!eval_int) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_hasOne"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch(&r1, t2, model_name, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(relation);
	phalcon_array_fetch(&relation, r1, model_relation, PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD_PARAMS_3(r2, this_ptr, "_getrelationrecords", relation, method, record, PH_NO_CHECK);
	RETURN_CTOR(r2);
}

/**
 * Gets belongsTo relations defined on a model
 *
 * @param  Phalcon\Model\Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_Manager, getBelongsTo){

	zval *model = NULL, *model_name = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	zval *a0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(model_name);
	phalcon_get_class(model_name, model TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, model_name);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, t1, model_name, PH_NOISY_CC);
		
		RETURN_CCTOR(r0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	
	RETURN_CTOR(a0);
}

/**
 * Gets hasMany relations defined on a model
 *
 * @param  Phalcon\Model\Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_Manager, getHasMany){

	zval *model = NULL, *model_name = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	zval *a0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(model_name);
	phalcon_get_class(model_name, model TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, model_name);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_hasMany"), PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, t1, model_name, PH_NOISY_CC);
		
		RETURN_CCTOR(r0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	
	RETURN_CTOR(a0);
}

/**
 * Gets hasOne relations defined on a model
 *
 * @param  Phalcon\Model\Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_Manager, getHasOne){

	zval *model = NULL, *model_name = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	zval *a0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(model_name);
	phalcon_get_class(model_name, model TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_hasOne"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, model_name);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_hasOne"), PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, t1, model_name, PH_NOISY_CC);
		
		RETURN_CCTOR(r0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	
	RETURN_CTOR(a0);
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
	PHALCON_CALL_METHOD_PARAMS_1(r0, this_ptr, "gethasone", model, PH_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "gethasmany", model, PH_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_FUNC_PARAMS_2(r2, "array_merge", r0, r1);
	RETURN_CTOR(r2);
}

/**
 * Returns the complete on which manager is looking for models
 *
 * @return string
 */
PHP_METHOD(Phalcon_Model_Manager, getCompleteModelsPath){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_basePath"), PH_NOISY_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_modelsDir"), PH_NOISY_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_VV(r0, t0, t1);
	
	RETURN_CTOR(r0);
}

/**
 * Autoload function for model lazy loading
 *
 * @param string $className
 */
PHP_METHOD(Phalcon_Model_Manager, autoload){

	zval *class_name = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &class_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, this_ptr, "ismodel", class_name, PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Get the default Phalcon\Model\Manager (usually this first instantiated)
 *
 * @return Phalcon\Model\Manager
 */
PHP_METHOD(Phalcon_Model_Manager, getDefault){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("phalcon\\model\\manager"), SL("_default") TSRMLS_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Resets internal default manager
 */
PHP_METHOD(Phalcon_Model_Manager, reset){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_NULL(t0);
	phalcon_update_static_property(SL("phalcon\\model\\manager"), SL("_default"), t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

