
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/hash.h"


/**
 * Phalcon\Mvc\Model\Manager
 *
 * This components controls the initialization of models, keeping record of relations
 * between the different models of the application.
 *
 * A ModelsManager is injected to a model via a Dependency Injector/Services Container such as Phalcon\DI.
 *
 * <code>
 * $di = new \Phalcon\DI();
 *
 * $di->set('modelsManager', function() {
 *      return new \Phalcon\Mvc\Model\Manager();
 * });
 *
 * $robot = new Robots($di);
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Manager) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, Manager, phalcon, mvc_model_manager, phalcon_mvc_model_manager_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_customEventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_readConnectionServices"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_writeConnectionServices"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_aliases"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Has many relations
	 */
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_hasMany"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Has many relations by model
	 */
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_hasManySingle"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Has one relations
	 */
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_hasOne"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Has one relations by model
	 */
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_hasOneSingle"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Belongs to relations
	 */
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_belongsTo"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * All the relationships by model
	 */
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_belongsToSingle"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Has many-Through relations
	 */
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_hasManyToMany"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Has many-Through relations by model
	 */
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_hasManyToManySingle"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Mark initialized models
	 */
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_initialized"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_sources"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_schemas"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Models' behaviors
	 */
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_behaviors"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Last model initialized
	 */
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_lastInitialized"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Last query created/executed
	 */
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_lastQuery"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Stores a list of reusable instances
	 */
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_reusable"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_keepSnapshots"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Does the model use dynamic update, instead of updating all rows?
	 */
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_dynamicUpdate"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_namespaceAliases"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_manager_ce TSRMLS_CC, 1, phalcon_mvc_model_managerinterface_ce);
	zend_class_implements(phalcon_mvc_model_manager_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_mvc_model_manager_ce TSRMLS_CC, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;

}

/**
 * Sets the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Sets a global events manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setEventsManager) {

	zval *eventsManager;

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_this(this_ptr, SL("_eventsManager"), eventsManager TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getEventsManager) {


	RETURN_MEMBER(this_ptr, "_eventsManager");

}

/**
 * Sets a custom events manager for a specific model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setCustomEventsManager) {

	zval *model, *eventsManager, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &eventsManager);



	ZEPHIR_INIT_VAR(_0);
	zephir_get_class(_0, model, 1 TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_customEventsManager"), _0, eventsManager TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a custom events manager related to a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getCustomEventsManager) {

	zval *model, *customEventsManager, *eventsManager, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	customEventsManager = zephir_fetch_nproperty_this(this_ptr, SL("_customEventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(customEventsManager) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0);
		zephir_get_class(_0, model, 1 TSRMLS_CC);
		if (zephir_array_isset_fetch(&eventsManager, customEventsManager, _0, 1 TSRMLS_CC)) {
			RETURN_CTOR(eventsManager);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Initializes a model in the model manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, initialize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *className, *eventsManager = NULL, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, model, 1 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (zephir_array_isset(_0, className)) {
		RETURN_MM_BOOL(0);
	}
	zephir_update_property_array(this_ptr, SL("_initialized"), className, model TSRMLS_CC);
	if ((zephir_method_exists_ex(model, SS("initialize") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, model, "initialize", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("_lastInitialized"), model TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _1);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "modelsManager:afterInitialize", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _2, this_ptr, model);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);

}

/**
 * Check whether a model is already initialized
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, isInitialized) {

	zval *modelName_param = NULL, *_0, *_1;
	zval *modelName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modelName_param);

	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, modelName);
	RETURN_MM_BOOL(zephir_array_isset(_0, _1));

}

/**
 * Get last initialized model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getLastInitialized) {


	RETURN_MEMBER(this_ptr, "_lastInitialized");

}

/**
 * Loads a model throwing an exception if it doesn't exist
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, load) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_3, *_6;
	zend_bool newInstance;
	zval *modelName_param = NULL, *newInstance_param = NULL, *model, *_0, *_1, *_2 = NULL, *_4, *_5 = NULL, *_7;
	zval *modelName = NULL, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &modelName_param, &newInstance_param);

	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}
	if (!newInstance_param) {
		newInstance = 0;
	} else {
		newInstance = zephir_get_boolval(newInstance_param);
	}


	ZEPHIR_OBS_VAR(model);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, modelName);
	if (zephir_array_isset_fetch(&model, _0, _1, 0 TSRMLS_CC)) {
		if (newInstance) {
			zephir_fetch_safe_class(_2, modelName);
			_3 = zend_fetch_class(Z_STRVAL_P(_2), Z_STRLEN_P(_2), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(return_value, _3);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				_4 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, _4, this_ptr);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
		ZEPHIR_CALL_METHOD(NULL, model, "reset", NULL, 0);
		zephir_check_call_status();
		RETURN_CCTOR(model);
	}
	if (zephir_class_exists(modelName, 1 TSRMLS_CC)) {
		zephir_fetch_safe_class(_5, modelName);
		_6 = zend_fetch_class(Z_STRVAL_P(_5), Z_STRLEN_P(_5), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(return_value, _6);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, _4, this_ptr);
			zephir_check_call_status();
		}
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_7);
	object_init_ex(_7, phalcon_mvc_model_exception_ce);
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_SVS(_8, "Model '", modelName, "' could not be loaded");
	ZEPHIR_CALL_METHOD(NULL, _7, "__construct", NULL, 2, _8);
	zephir_check_call_status();
	zephir_throw_exception_debug(_7, "phalcon/mvc/model/manager.zep", 292 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Sets the mapped source for a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setModelSource) {

	zval *source = NULL;
	zval *model, *source_param = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &source_param);

	if (unlikely(Z_TYPE_P(source_param) != IS_STRING && Z_TYPE_P(source_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'source' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(source_param) == IS_STRING)) {
		zephir_get_strval(source, source_param);
	} else {
		ZEPHIR_INIT_VAR(source);
		ZVAL_EMPTY_STRING(source);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_get_class(_0, model, 1 TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_sources"), _0, source TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the mapped source for a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getModelSource) {

	zval *model, *sources, *entityName, *source = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_INIT_VAR(entityName);
	zephir_get_class(entityName, model, 1 TSRMLS_CC);
	ZEPHIR_OBS_VAR(sources);
	zephir_read_property_this(&sources, this_ptr, SL("_sources"), PH_NOISY_CC);
	if (Z_TYPE_P(sources) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(source);
		if (zephir_array_isset_fetch(&source, sources, entityName, 0 TSRMLS_CC)) {
			RETURN_CCTOR(source);
		}
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_get_class_ns(_0, model, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(source);
	zephir_uncamelize(source, _0);
	zephir_update_property_array(this_ptr, SL("_sources"), entityName, source TSRMLS_CC);
	RETURN_CCTOR(source);

}

/**
 * Sets the mapped schema for a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setModelSchema) {

	zval *schema = NULL;
	zval *model, *schema_param = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &schema_param);

	if (unlikely(Z_TYPE_P(schema_param) != IS_STRING && Z_TYPE_P(schema_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schema' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(schema_param) == IS_STRING)) {
		zephir_get_strval(schema, schema_param);
	} else {
		ZEPHIR_INIT_VAR(schema);
		ZVAL_EMPTY_STRING(schema);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_get_class(_0, model, 1 TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_schemas"), _0, schema TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the mapped schema for a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getModelSchema) {

	zval *model, *schemas, *schema, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	schemas = zephir_fetch_nproperty_this(this_ptr, SL("_schemas"), PH_NOISY_CC);
	if (Z_TYPE_P(schemas) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0);
		zephir_get_class(_0, model, 1 TSRMLS_CC);
		if (zephir_array_isset_fetch(&schema, schemas, _0, 1 TSRMLS_CC)) {
			RETURN_CTOR(schema);
		}
	}
	RETURN_MM_STRING("", 1);

}

/**
 * Sets both write and read connection service for a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setConnectionService) {

	zval *connectionService = NULL;
	zval *model, *connectionService_param = NULL, *entityName;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &connectionService_param);

	if (unlikely(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(connectionService_param) == IS_STRING)) {
		zephir_get_strval(connectionService, connectionService_param);
	} else {
		ZEPHIR_INIT_VAR(connectionService);
		ZVAL_EMPTY_STRING(connectionService);
	}


	ZEPHIR_INIT_VAR(entityName);
	zephir_get_class(entityName, model, 1 TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_readConnectionServices"), entityName, connectionService TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_writeConnectionServices"), entityName, connectionService TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets write connection service for a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setWriteConnectionService) {

	zval *connectionService = NULL;
	zval *model, *connectionService_param = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &connectionService_param);

	if (unlikely(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(connectionService_param) == IS_STRING)) {
		zephir_get_strval(connectionService, connectionService_param);
	} else {
		ZEPHIR_INIT_VAR(connectionService);
		ZVAL_EMPTY_STRING(connectionService);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_get_class(_0, model, 1 TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_writeConnectionServices"), _0, connectionService TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets read connection service for a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setReadConnectionService) {

	zval *connectionService = NULL;
	zval *model, *connectionService_param = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &connectionService_param);

	if (unlikely(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(connectionService_param) == IS_STRING)) {
		zephir_get_strval(connectionService, connectionService_param);
	} else {
		ZEPHIR_INIT_VAR(connectionService);
		ZVAL_EMPTY_STRING(connectionService);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_get_class(_0, model, 1 TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_readConnectionServices"), _0, connectionService TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the connection to read data related to a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getReadConnection) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_readConnectionServices"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getconnection", NULL, 0, model, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the connection to write data related to a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getWriteConnection) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_writeConnectionServices"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getconnection", NULL, 0, model, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the connection to read or write data related to a model depending on the connection services.
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, _getConnection) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *connectionServices, *dependencyInjector = NULL, *service = NULL, *connection = NULL, *_0 = NULL, *_1, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &connectionServices);

	ZEPHIR_INIT_VAR(service);
	ZVAL_NULL(service);


	if (Z_TYPE_P(connectionServices) == IS_ARRAY) {
		ZEPHIR_OBS_NVAR(service);
		ZEPHIR_INIT_VAR(_0);
		zephir_get_class(_0, model, 1 TSRMLS_CC);
		zephir_array_isset_fetch(&service, connectionServices, _0, 0 TSRMLS_CC);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _1);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM", "phalcon/mvc/model/manager.zep", 406);
		return;
	}
	ZEPHIR_INIT_VAR(connection);
	if (zephir_is_true(service)) {
		ZEPHIR_CALL_METHOD(&_2, dependencyInjector, "getshared", NULL, 0, service);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(connection, _2);
	} else {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "db", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2, dependencyInjector, "getshared", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(connection, _2);
	}
	if (Z_TYPE_P(connection) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid injected connection service", "phalcon/mvc/model/manager.zep", 419);
		return;
	}
	RETURN_CCTOR(connection);

}

/**
 * Returns the connection service name used to read data related to a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getReadConnectionService) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_readConnectionServices"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getconnectionservice", NULL, 0, model, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the connection service name used to write data related to a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getWriteConnectionService) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_writeConnectionServices"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getconnectionservice", NULL, 0, model, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the connection service name used to read or write data related to a model depending on the connection services
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, _getConnectionService) {

	zval *model, *connectionServices, *connection, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &connectionServices);



	if (Z_TYPE_P(connectionServices) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0);
		zephir_get_class(_0, model, 1 TSRMLS_CC);
		if (zephir_array_isset_fetch(&connection, connectionServices, _0, 1 TSRMLS_CC)) {
			RETURN_CTOR(connection);
		}
	}
	RETURN_MM_STRING("db", 1);

}

/**
 * Receives events generated in the models and dispatches them to a events-manager if available
 * Notify the behaviors that are listening in the model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, notifyEvent) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *eventName_param = NULL, *model, *status = NULL, *behavior = NULL, *modelsBehaviors, *eventsManager, *customEventsManager = NULL, *behaviors, *_0 = NULL, **_3;
	zval *eventName = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &eventName_param, &model);

	if (unlikely(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(eventName_param) == IS_STRING)) {
		zephir_get_strval(eventName, eventName_param);
	} else {
		ZEPHIR_INIT_VAR(eventName);
		ZVAL_EMPTY_STRING(eventName);
	}


	ZEPHIR_INIT_VAR(status);
	ZVAL_NULL(status);
	ZEPHIR_OBS_VAR(behaviors);
	zephir_read_property_this(&behaviors, this_ptr, SL("_behaviors"), PH_NOISY_CC);
	if (Z_TYPE_P(behaviors) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(modelsBehaviors);
		ZEPHIR_INIT_VAR(_0);
		zephir_get_class(_0, model, 1 TSRMLS_CC);
		if (zephir_array_isset_fetch(&modelsBehaviors, behaviors, _0, 0 TSRMLS_CC)) {
			zephir_is_iterable(modelsBehaviors, &_2, &_1, 0, 0, "phalcon/mvc/model/manager.zep", 484);
			for (
			  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
			  ; zephir_hash_move_forward_ex(_2, &_1)
			) {
				ZEPHIR_GET_HVALUE(behavior, _3);
				ZEPHIR_CALL_METHOD(&status, behavior, "notify", NULL, 0, eventName, model);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(status)) {
					RETURN_MM_BOOL(0);
				}
			}
		}
	}
	ZEPHIR_OBS_VAR(eventsManager);
	zephir_read_property_this(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_SV(_4, "model:", eventName);
		ZEPHIR_CALL_METHOD(&status, eventsManager, "fire", NULL, 0, _4, model);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(status)) {
			RETURN_CCTOR(status);
		}
	}
	ZEPHIR_OBS_VAR(customEventsManager);
	zephir_read_property_this(&customEventsManager, this_ptr, SL("_customEventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(customEventsManager) == IS_ARRAY) {
		ZEPHIR_OBS_NVAR(customEventsManager);
		ZEPHIR_INIT_NVAR(_0);
		zephir_get_class(_0, model, 1 TSRMLS_CC);
		if (zephir_array_isset_fetch(&customEventsManager, customEventsManager, _0, 0 TSRMLS_CC)) {
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SV(_4, "model:", eventName);
			ZEPHIR_CALL_METHOD(&status, customEventsManager, "fire", NULL, 0, _4, model);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(status)) {
				RETURN_MM_BOOL(0);
			}
		}
	}
	RETURN_CCTOR(status);

}

/**
 * Dispatch a event to the listeners and behaviors
 * This method expects that the endpoint listeners/behaviors returns true
 * meaning that a least one was implemented
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, missingMethod) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *eventName = NULL, *_4;
	zval *model, *eventName_param = NULL, *data, *behaviors, *modelsBehaviors, *result = NULL, *eventsManager, *behavior = NULL, *_0, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &model, &eventName_param, &data);

	if (unlikely(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(eventName_param) == IS_STRING)) {
		zephir_get_strval(eventName, eventName_param);
	} else {
		ZEPHIR_INIT_VAR(eventName);
		ZVAL_EMPTY_STRING(eventName);
	}


	ZEPHIR_OBS_VAR(behaviors);
	zephir_read_property_this(&behaviors, this_ptr, SL("_behaviors"), PH_NOISY_CC);
	if (Z_TYPE_P(behaviors) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(modelsBehaviors);
		ZEPHIR_INIT_VAR(_0);
		zephir_get_class(_0, model, 1 TSRMLS_CC);
		if (zephir_array_isset_fetch(&modelsBehaviors, behaviors, _0, 0 TSRMLS_CC)) {
			zephir_is_iterable(modelsBehaviors, &_2, &_1, 0, 0, "phalcon/mvc/model/manager.zep", 540);
			for (
			  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
			  ; zephir_hash_move_forward_ex(_2, &_1)
			) {
				ZEPHIR_GET_HVALUE(behavior, _3);
				ZEPHIR_CALL_METHOD(&result, behavior, "missingmethod", NULL, 0, model, eventName, data);
				zephir_check_call_status();
				if (Z_TYPE_P(result) != IS_NULL) {
					RETURN_CCTOR(result);
				}
			}
		}
	}
	ZEPHIR_OBS_VAR(eventsManager);
	zephir_read_property_this(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_SV(_4, "model:", eventName);
		ZEPHIR_RETURN_CALL_METHOD(eventsManager, "fire", NULL, 0, _4, model, data);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_NULL();

}

/**
 * Binds a behavior to a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, addBehavior) {

	zval *model, *behavior, *entityName, *modelsBehaviors = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &behavior);



	ZEPHIR_INIT_VAR(entityName);
	zephir_get_class(entityName, model, 1 TSRMLS_CC);
	ZEPHIR_OBS_VAR(modelsBehaviors);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_behaviors"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&modelsBehaviors, _0, entityName, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(modelsBehaviors);
		array_init(modelsBehaviors);
	}
	zephir_array_append(&modelsBehaviors, behavior, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 573);
	zephir_update_property_array(this_ptr, SL("_behaviors"), entityName, modelsBehaviors TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets if a model must keep snapshots
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, keepSnapshots) {

	zend_bool keepSnapshots;
	zval *model, *keepSnapshots_param = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &keepSnapshots_param);

	keepSnapshots = zephir_get_boolval(keepSnapshots_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_get_class(_0, model, 1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_BOOL(_1, keepSnapshots);
	zephir_update_property_array(this_ptr, SL("_keepSnapshots"), _0, _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if a model is keeping snapshots for the queried records
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, isKeepingSnapshots) {

	zval *model, *keepSnapshots, *isKeeping, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	keepSnapshots = zephir_fetch_nproperty_this(this_ptr, SL("_keepSnapshots"), PH_NOISY_CC);
	if (Z_TYPE_P(keepSnapshots) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0);
		zephir_get_class(_0, model, 1 TSRMLS_CC);
		if (zephir_array_isset_fetch(&isKeeping, keepSnapshots, _0, 1 TSRMLS_CC)) {
			RETURN_CTOR(isKeeping);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Sets if a model must use dynamic update instead of the all-field update
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, useDynamicUpdate) {

	zend_bool dynamicUpdate;
	zval *model, *dynamicUpdate_param = NULL, *entityName, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &dynamicUpdate_param);

	dynamicUpdate = zephir_get_boolval(dynamicUpdate_param);


	ZEPHIR_INIT_VAR(entityName);
	zephir_get_class(entityName, model, 1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_BOOL(_0, dynamicUpdate);
	zephir_update_property_array(this_ptr, SL("_dynamicUpdate"), entityName, _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_BOOL(_1, dynamicUpdate);
	zephir_update_property_array(this_ptr, SL("_keepSnapshots"), entityName, _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if a model is using dynamic update instead of all-field update
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, isUsingDynamicUpdate) {

	zval *model, *dynamicUpdate, *isUsing, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	dynamicUpdate = zephir_fetch_nproperty_this(this_ptr, SL("_dynamicUpdate"), PH_NOISY_CC);
	if (Z_TYPE_P(dynamicUpdate) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0);
		zephir_get_class(_0, model, 1 TSRMLS_CC);
		if (zephir_array_isset_fetch(&isUsing, dynamicUpdate, _0, 1 TSRMLS_CC)) {
			RETURN_CTOR(isUsing);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Setup a 1-1 relation between two models
 *
 * @param   Phalcon\Mvc\Model model
 * @param	mixed fields
 * @param	string referencedModel
 * @param	mixed referencedFields
 * @param	array options
 * @return  Phalcon\Mvc\Model\Relation
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasOne) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *referencedModel = NULL;
	zval *model, *fields, *referencedModel_param = NULL, *referencedFields, *options = NULL, *entityName, *referencedEntity, *relation, *keyRelation, *relations = NULL, *alias, *lowerAlias = NULL, *singleRelations = NULL, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &model, &fields, &referencedModel_param, &referencedFields, &options);

	if (unlikely(Z_TYPE_P(referencedModel_param) != IS_STRING && Z_TYPE_P(referencedModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referencedModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(referencedModel_param) == IS_STRING)) {
		zephir_get_strval(referencedModel, referencedModel_param);
	} else {
		ZEPHIR_INIT_VAR(referencedModel);
		ZVAL_EMPTY_STRING(referencedModel);
	}
	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(entityName);
	zephir_get_class(entityName, model, 1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(referencedEntity);
	zephir_fast_strtolower(referencedEntity, referencedModel);
	ZEPHIR_INIT_VAR(keyRelation);
	ZEPHIR_CONCAT_VSV(keyRelation, entityName, "$", referencedEntity);
	ZEPHIR_OBS_VAR(relations);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_hasOne"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&relations, _0, keyRelation, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(relations);
		array_init(relations);
	}
	if (Z_TYPE_P(referencedFields) == IS_ARRAY) {
		if (zephir_fast_count_int(fields TSRMLS_CC) != zephir_fast_count_int(referencedFields TSRMLS_CC)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same", "phalcon/mvc/model/manager.zep", 660);
			return;
		}
	}
	ZEPHIR_INIT_VAR(relation);
	object_init_ex(relation, phalcon_mvc_model_relation_ce);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 1);
	ZEPHIR_CALL_METHOD(NULL, relation, "__construct", NULL, 302, _1, referencedModel, fields, referencedFields, options);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(alias);
	if (zephir_array_isset_string_fetch(&alias, options, SS("alias"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(lowerAlias);
		zephir_fast_strtolower(lowerAlias, alias);
	} else {
		ZEPHIR_CPY_WRT(lowerAlias, referencedEntity);
	}
	zephir_array_append(&relations, relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 689);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VSV(_2, entityName, "$", lowerAlias);
	zephir_update_property_array(this_ptr, SL("_aliases"), _2, relation TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_hasOne"), keyRelation, relations TSRMLS_CC);
	ZEPHIR_OBS_VAR(singleRelations);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_hasOneSingle"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&singleRelations, _3, entityName, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(singleRelations);
		array_init(singleRelations);
	}
	zephir_array_append(&singleRelations, relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 703);
	zephir_update_property_array(this_ptr, SL("_hasOneSingle"), entityName, singleRelations TSRMLS_CC);
	RETURN_CCTOR(relation);

}

/**
 * Setup a relation reverse many to one between two models
 *
 * @param   Phalcon\Mvc\Model model
 * @param	mixed fields
 * @param	string referencedModel
 * @param	mixed referencedFields
 * @param	array options
 * @return  Phalcon\Mvc\Model\Relation
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, addBelongsTo) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *referencedModel = NULL;
	zval *model, *fields, *referencedModel_param = NULL, *referencedFields, *options = NULL, *entityName, *referencedEntity, *relation, *keyRelation, *relations = NULL, *alias, *lowerAlias = NULL, *singleRelations = NULL, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &model, &fields, &referencedModel_param, &referencedFields, &options);

	if (unlikely(Z_TYPE_P(referencedModel_param) != IS_STRING && Z_TYPE_P(referencedModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referencedModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(referencedModel_param) == IS_STRING)) {
		zephir_get_strval(referencedModel, referencedModel_param);
	} else {
		ZEPHIR_INIT_VAR(referencedModel);
		ZVAL_EMPTY_STRING(referencedModel);
	}
	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(entityName);
	zephir_get_class(entityName, model, 1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(referencedEntity);
	zephir_fast_strtolower(referencedEntity, referencedModel);
	ZEPHIR_INIT_VAR(keyRelation);
	ZEPHIR_CONCAT_VSV(keyRelation, entityName, "$", referencedEntity);
	ZEPHIR_OBS_VAR(relations);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&relations, _0, keyRelation, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(relations);
		array_init(relations);
	}
	if (Z_TYPE_P(referencedFields) == IS_ARRAY) {
		if (zephir_fast_count_int(fields TSRMLS_CC) != zephir_fast_count_int(referencedFields TSRMLS_CC)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same", "phalcon/mvc/model/manager.zep", 742);
			return;
		}
	}
	ZEPHIR_INIT_VAR(relation);
	object_init_ex(relation, phalcon_mvc_model_relation_ce);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	ZEPHIR_CALL_METHOD(NULL, relation, "__construct", NULL, 302, _1, referencedModel, fields, referencedFields, options);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(alias);
	if (zephir_array_isset_string_fetch(&alias, options, SS("alias"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(lowerAlias);
		zephir_fast_strtolower(lowerAlias, alias);
	} else {
		ZEPHIR_CPY_WRT(lowerAlias, referencedEntity);
	}
	zephir_array_append(&relations, relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 771);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VSV(_2, entityName, "$", lowerAlias);
	zephir_update_property_array(this_ptr, SL("_aliases"), _2, relation TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_belongsTo"), keyRelation, relations TSRMLS_CC);
	ZEPHIR_OBS_VAR(singleRelations);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_belongsToSingle"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&singleRelations, _3, entityName, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(singleRelations);
		array_init(singleRelations);
	}
	zephir_array_append(&singleRelations, relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 785);
	zephir_update_property_array(this_ptr, SL("_belongsToSingle"), entityName, singleRelations TSRMLS_CC);
	RETURN_CCTOR(relation);

}

/**
 * Setup a relation 1-n between two models
 *
 * @param 	Phalcon\Mvc\ModelInterface model
 * @param	mixed fields
 * @param	string referencedModel
 * @param	mixed referencedFields
 * @param	array options
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasMany) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *referencedModel = NULL;
	zval *model, *fields, *referencedModel_param = NULL, *referencedFields, *options = NULL, *entityName, *referencedEntity, *hasMany, *relation, *keyRelation, *relations = NULL, *alias, *lowerAlias = NULL, *singleRelations = NULL, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &model, &fields, &referencedModel_param, &referencedFields, &options);

	if (unlikely(Z_TYPE_P(referencedModel_param) != IS_STRING && Z_TYPE_P(referencedModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referencedModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(referencedModel_param) == IS_STRING)) {
		zephir_get_strval(referencedModel, referencedModel_param);
	} else {
		ZEPHIR_INIT_VAR(referencedModel);
		ZVAL_EMPTY_STRING(referencedModel);
	}
	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(entityName);
	zephir_get_class(entityName, model, 1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(referencedEntity);
	zephir_fast_strtolower(referencedEntity, referencedModel);
	ZEPHIR_INIT_VAR(keyRelation);
	ZEPHIR_CONCAT_VSV(keyRelation, entityName, "$", referencedEntity);
	ZEPHIR_OBS_VAR(hasMany);
	zephir_read_property_this(&hasMany, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(relations);
	if (!(zephir_array_isset_fetch(&relations, hasMany, keyRelation, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(relations);
		array_init(relations);
	}
	if (Z_TYPE_P(referencedFields) == IS_ARRAY) {
		if (zephir_fast_count_int(fields TSRMLS_CC) != zephir_fast_count_int(referencedFields TSRMLS_CC)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same", "phalcon/mvc/model/manager.zep", 824);
			return;
		}
	}
	ZEPHIR_INIT_VAR(relation);
	object_init_ex(relation, phalcon_mvc_model_relation_ce);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 2);
	ZEPHIR_CALL_METHOD(NULL, relation, "__construct", NULL, 302, _0, referencedModel, fields, referencedFields, options);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(alias);
	if (zephir_array_isset_string_fetch(&alias, options, SS("alias"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(lowerAlias);
		zephir_fast_strtolower(lowerAlias, alias);
	} else {
		ZEPHIR_CPY_WRT(lowerAlias, referencedEntity);
	}
	zephir_array_append(&relations, relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 853);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VSV(_1, entityName, "$", lowerAlias);
	zephir_update_property_array(this_ptr, SL("_aliases"), _1, relation TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_hasMany"), keyRelation, relations TSRMLS_CC);
	ZEPHIR_OBS_VAR(singleRelations);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_hasManySingle"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&singleRelations, _2, entityName, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(singleRelations);
		array_init(singleRelations);
	}
	zephir_array_append(&singleRelations, relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 867);
	zephir_update_property_array(this_ptr, SL("_hasManySingle"), entityName, singleRelations TSRMLS_CC);
	RETURN_CCTOR(relation);

}

/**
 * Setups a relation n-m between two models
 *
 * @param 	Phalcon\Mvc\ModelInterface model
 * @param	string fields
 * @param	string intermediateModel
 * @param	string intermediateFields
 * @param	string intermediateReferencedFields
 * @param	string referencedModel
 * @param	string referencedFields
 * @param   array options
 * @return  Phalcon\Mvc\Model\Relation
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasManyToMany) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *intermediateModel = NULL, *referencedModel = NULL;
	zval *model, *fields, *intermediateModel_param = NULL, *intermediateFields, *intermediateReferencedFields, *referencedModel_param = NULL, *referencedFields, *options = NULL, *entityName, *referencedEntity, *hasManyToMany, *relation, *keyRelation, *relations = NULL, *alias, *lowerAlias = NULL, *singleRelations = NULL, *intermediateEntity, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 7, 1, &model, &fields, &intermediateModel_param, &intermediateFields, &intermediateReferencedFields, &referencedModel_param, &referencedFields, &options);

	if (unlikely(Z_TYPE_P(intermediateModel_param) != IS_STRING && Z_TYPE_P(intermediateModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'intermediateModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(intermediateModel_param) == IS_STRING)) {
		zephir_get_strval(intermediateModel, intermediateModel_param);
	} else {
		ZEPHIR_INIT_VAR(intermediateModel);
		ZVAL_EMPTY_STRING(intermediateModel);
	}
	if (unlikely(Z_TYPE_P(referencedModel_param) != IS_STRING && Z_TYPE_P(referencedModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referencedModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(referencedModel_param) == IS_STRING)) {
		zephir_get_strval(referencedModel, referencedModel_param);
	} else {
		ZEPHIR_INIT_VAR(referencedModel);
		ZVAL_EMPTY_STRING(referencedModel);
	}
	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(entityName);
	zephir_get_class(entityName, model, 1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(intermediateEntity);
	zephir_fast_strtolower(intermediateEntity, intermediateModel);
	ZEPHIR_INIT_VAR(referencedEntity);
	zephir_fast_strtolower(referencedEntity, referencedModel);
	ZEPHIR_INIT_VAR(keyRelation);
	ZEPHIR_CONCAT_VSV(keyRelation, entityName, "$", referencedEntity);
	ZEPHIR_OBS_VAR(hasManyToMany);
	zephir_read_property_this(&hasManyToMany, this_ptr, SL("_hasManyToMany"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(relations);
	if (!(zephir_array_isset_fetch(&relations, hasManyToMany, keyRelation, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(relations);
		array_init(relations);
	}
	if (Z_TYPE_P(intermediateFields) == IS_ARRAY) {
		if (zephir_fast_count_int(fields TSRMLS_CC) != zephir_fast_count_int(intermediateFields TSRMLS_CC)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same", "phalcon/mvc/model/manager.zep", 911);
			return;
		}
	}
	if (Z_TYPE_P(intermediateReferencedFields) == IS_ARRAY) {
		if (zephir_fast_count_int(fields TSRMLS_CC) != zephir_fast_count_int(intermediateFields TSRMLS_CC)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same", "phalcon/mvc/model/manager.zep", 920);
			return;
		}
	}
	ZEPHIR_INIT_VAR(relation);
	object_init_ex(relation, phalcon_mvc_model_relation_ce);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 4);
	ZEPHIR_CALL_METHOD(NULL, relation, "__construct", NULL, 302, _0, referencedModel, fields, referencedFields, options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, relation, "setintermediaterelation", NULL, 303, intermediateFields, intermediateModel, intermediateReferencedFields);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(alias);
	if (zephir_array_isset_string_fetch(&alias, options, SS("alias"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(lowerAlias);
		zephir_fast_strtolower(lowerAlias, alias);
	} else {
		ZEPHIR_CPY_WRT(lowerAlias, referencedEntity);
	}
	zephir_array_append(&relations, relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 952);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VSV(_1, entityName, "$", lowerAlias);
	zephir_update_property_array(this_ptr, SL("_aliases"), _1, relation TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_hasManyToMany"), keyRelation, relations TSRMLS_CC);
	ZEPHIR_OBS_VAR(singleRelations);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_hasManyToManySingle"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&singleRelations, _2, entityName, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(singleRelations);
		array_init(singleRelations);
	}
	zephir_array_append(&singleRelations, relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 974);
	zephir_update_property_array(this_ptr, SL("_hasManyToManySingle"), entityName, singleRelations TSRMLS_CC);
	RETURN_CCTOR(relation);

}

/**
 * Checks whether a model has a belongsTo relation with another model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsBelongsTo) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *modelName_param = NULL, *modelRelation_param = NULL, *entityName, *keyRelation, *_0, *_1, *_2;
	zval *modelName = NULL, *modelRelation = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &modelRelation_param);

	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}
	if (unlikely(Z_TYPE_P(modelRelation_param) != IS_STRING && Z_TYPE_P(modelRelation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelRelation' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(modelRelation_param) == IS_STRING)) {
		zephir_get_strval(modelRelation, modelRelation_param);
	} else {
		ZEPHIR_INIT_VAR(modelRelation);
		ZVAL_EMPTY_STRING(modelRelation);
	}


	ZEPHIR_INIT_VAR(entityName);
	zephir_fast_strtolower(entityName, modelName);
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, modelRelation);
	ZEPHIR_INIT_VAR(keyRelation);
	ZEPHIR_CONCAT_VSV(keyRelation, entityName, "$", _0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (!(zephir_array_isset(_1, entityName))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 0, modelName);
		zephir_check_call_status();
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_2, keyRelation));

}

/**
 * Checks whether a model has a hasMany relation with another model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasMany) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *modelName_param = NULL, *modelRelation_param = NULL, *entityName, *keyRelation, *_0, *_1, *_2;
	zval *modelName = NULL, *modelRelation = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &modelRelation_param);

	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}
	if (unlikely(Z_TYPE_P(modelRelation_param) != IS_STRING && Z_TYPE_P(modelRelation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelRelation' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(modelRelation_param) == IS_STRING)) {
		zephir_get_strval(modelRelation, modelRelation_param);
	} else {
		ZEPHIR_INIT_VAR(modelRelation);
		ZVAL_EMPTY_STRING(modelRelation);
	}


	ZEPHIR_INIT_VAR(entityName);
	zephir_fast_strtolower(entityName, modelName);
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, modelRelation);
	ZEPHIR_INIT_VAR(keyRelation);
	ZEPHIR_CONCAT_VSV(keyRelation, entityName, "$", _0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (!(zephir_array_isset(_1, entityName))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 0, modelName);
		zephir_check_call_status();
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_hasMany"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_2, keyRelation));

}

/**
 * Checks whether a model has a hasOne relation with another model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasOne) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *modelName_param = NULL, *modelRelation_param = NULL, *entityName, *keyRelation, *_0, *_1, *_2;
	zval *modelName = NULL, *modelRelation = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &modelRelation_param);

	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}
	if (unlikely(Z_TYPE_P(modelRelation_param) != IS_STRING && Z_TYPE_P(modelRelation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelRelation' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(modelRelation_param) == IS_STRING)) {
		zephir_get_strval(modelRelation, modelRelation_param);
	} else {
		ZEPHIR_INIT_VAR(modelRelation);
		ZVAL_EMPTY_STRING(modelRelation);
	}


	ZEPHIR_INIT_VAR(entityName);
	zephir_fast_strtolower(entityName, modelName);
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, modelRelation);
	ZEPHIR_INIT_VAR(keyRelation);
	ZEPHIR_CONCAT_VSV(keyRelation, entityName, "$", _0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (!(zephir_array_isset(_1, entityName))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 0, modelName);
		zephir_check_call_status();
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_hasOne"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_2, keyRelation));

}

/**
 * Checks whether a model has a hasManyToMany relation with another model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasManyToMany) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *modelName_param = NULL, *modelRelation_param = NULL, *entityName, *keyRelation, *_0, *_1, *_2;
	zval *modelName = NULL, *modelRelation = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &modelRelation_param);

	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}
	if (unlikely(Z_TYPE_P(modelRelation_param) != IS_STRING && Z_TYPE_P(modelRelation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelRelation' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(modelRelation_param) == IS_STRING)) {
		zephir_get_strval(modelRelation, modelRelation_param);
	} else {
		ZEPHIR_INIT_VAR(modelRelation);
		ZVAL_EMPTY_STRING(modelRelation);
	}


	ZEPHIR_INIT_VAR(entityName);
	zephir_fast_strtolower(entityName, modelName);
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, modelRelation);
	ZEPHIR_INIT_VAR(keyRelation);
	ZEPHIR_CONCAT_VSV(keyRelation, entityName, "$", _0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (!(zephir_array_isset(_1, entityName))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 0, modelName);
		zephir_check_call_status();
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_hasManyToMany"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_2, keyRelation));

}

/**
 * Returns a relation by its alias
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationByAlias) {

	zval *modelName_param = NULL, *alias_param = NULL, *aliases, *relation, *_0;
	zval *modelName = NULL, *alias = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &alias_param);

	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}
	if (unlikely(Z_TYPE_P(alias_param) != IS_STRING && Z_TYPE_P(alias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(alias_param) == IS_STRING)) {
		zephir_get_strval(alias, alias_param);
	} else {
		ZEPHIR_INIT_VAR(alias);
		ZVAL_EMPTY_STRING(alias);
	}


	aliases = zephir_fetch_nproperty_this(this_ptr, SL("_aliases"), PH_NOISY_CC);
	if (Z_TYPE_P(aliases) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VSV(_1, modelName, "$", alias);
		zephir_fast_strtolower(_0, _1);
		if (zephir_array_isset_fetch(&relation, aliases, _0, 1 TSRMLS_CC)) {
			RETURN_CTOR(relation);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Helper method to query records based on a relation definition
 *
 * @return Phalcon\Mvc\Model\Resultset\Simple|Phalcon\Mvc\Model\Resultset\Simple|false
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationRecords) {

	zval *_16;
	zephir_fcall_cache_entry *_12 = NULL;
	HashTable *_8;
	HashPosition _7;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool reusable, _13, _15;
	zval *method = NULL;
	zval *relation, *method_param = NULL, *record, *parameters = NULL, *preConditions = NULL, *placeholders = NULL, *referencedModel = NULL, *intermediateModel = NULL, *intermediateFields = NULL, *joinConditions, *fields = NULL, *builder = NULL, *extraParameters = NULL, *conditions = NULL, *refPosition = NULL, *field = NULL, *referencedFields = NULL, *findParams, *findArguments = NULL, *retrieveMethod = NULL, *uniqueKey, *records = NULL, *arguments, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4, *_5 = NULL, *_6 = NULL, **_9, *_10, *_11 = NULL, *_14;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &relation, &method_param, &record, &parameters);

	if (unlikely(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(method, method_param);
	} else {
		ZEPHIR_INIT_VAR(method);
		ZVAL_EMPTY_STRING(method);
	}
	if (!parameters) {
		ZEPHIR_CPY_WRT(parameters, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(parameters);
	}


	ZEPHIR_INIT_VAR(preConditions);
	ZVAL_NULL(preConditions);
	if (Z_TYPE_P(parameters) == IS_ARRAY) {
		ZEPHIR_OBS_NVAR(preConditions);
		if (zephir_array_isset_long_fetch(&preConditions, parameters, 0, 0 TSRMLS_CC)) {
			zephir_array_unset_long(&parameters, 0, PH_SEPARATE);
		} else {
			ZEPHIR_OBS_NVAR(preConditions);
			if (zephir_array_isset_string_fetch(&preConditions, parameters, SS("conditions"), 0 TSRMLS_CC)) {
				zephir_array_unset_string(&parameters, SS("conditions"), PH_SEPARATE);
			}
		}
	} else {
		if (Z_TYPE_P(parameters) == IS_STRING) {
			ZEPHIR_CPY_WRT(preConditions, parameters);
		}
	}
	if (Z_TYPE_P(parameters) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(placeholders);
		if (zephir_array_isset_string_fetch(&placeholders, parameters, SS("bind"), 0 TSRMLS_CC)) {
			zephir_array_unset_string(&parameters, SS("bind"), PH_SEPARATE);
		} else {
			ZEPHIR_INIT_NVAR(placeholders);
			array_init(placeholders);
		}
	} else {
		ZEPHIR_INIT_NVAR(placeholders);
		array_init(placeholders);
	}
	ZEPHIR_CALL_METHOD(&extraParameters, relation, "getparams", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(extraParameters) == IS_ARRAY) {
		if (Z_TYPE_P(parameters) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(_0);
			zephir_fast_array_merge(_0, &(parameters), &(extraParameters) TSRMLS_CC);
			ZEPHIR_CPY_WRT(parameters, _0);
		} else {
			ZEPHIR_CPY_WRT(parameters, extraParameters);
		}
	}
	ZEPHIR_CALL_METHOD(&referencedModel, relation, "getreferencedmodel", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, relation, "isthrough", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_VAR(conditions);
		array_init(conditions);
		ZEPHIR_CALL_METHOD(&intermediateModel, relation, "getintermediatemodel", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&intermediateFields, relation, "getintermediatefields", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&fields, relation, "getfields", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(fields) != IS_ARRAY) {
			ZEPHIR_INIT_VAR(_2);
			ZEPHIR_CONCAT_SVSVS(_2, "[", intermediateModel, "].[", intermediateFields, "] = ?0");
			zephir_array_append(&conditions, _2, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1172);
			ZEPHIR_CALL_METHOD(&_3, record, "readattribute", NULL, 0, fields);
			zephir_check_call_status();
			zephir_array_append(&placeholders, _3, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1173);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not supported", "phalcon/mvc/model/manager.zep", 1175);
			return;
		}
		ZEPHIR_INIT_VAR(joinConditions);
		array_init(joinConditions);
		ZEPHIR_CALL_METHOD(&intermediateFields, relation, "getintermediatereferencedfields", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(intermediateFields) != IS_ARRAY) {
			ZEPHIR_CALL_METHOD(&_3, relation, "getreferencedfields", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_2);
			ZEPHIR_CONCAT_SVSVSVSVS(_2, "[", intermediateModel, "].[", intermediateFields, "] = [", referencedModel, "].[", _3, "]");
			zephir_array_append(&joinConditions, _2, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1185);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not supported", "phalcon/mvc/model/manager.zep", 1187);
			return;
		}
		if (!(ZEPHIR_IS_EMPTY(preConditions))) {
			zephir_array_append(&conditions, preConditions, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1194);
		}
		ZEPHIR_CALL_METHOD(&builder, this_ptr, "createbuilder", NULL, 0, parameters);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, builder, "from", NULL, 0, referencedModel);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_0);
		zephir_fast_join_str(_0, SL(" AND "), joinConditions TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, builder, "innerjoin", NULL, 0, intermediateModel, _0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_4);
		zephir_fast_join_str(_4, SL(" AND "), conditions TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, builder, "andwhere", NULL, 0, _4, placeholders);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3, builder, "getquery", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(_3, "execute", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(conditions);
	if (Z_TYPE_P(preConditions) != IS_NULL) {
		zephir_create_array(conditions, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(conditions, preConditions);
	} else {
		array_init(conditions);
	}
	ZEPHIR_CALL_METHOD(&fields, relation, "getfields", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(fields) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_5, relation, "getreferencedfields", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "[", _5, "] = ?0");
		zephir_array_append(&conditions, _2, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1225);
		ZEPHIR_CALL_METHOD(&_6, record, "readattribute", NULL, 0, fields);
		zephir_check_call_status();
		zephir_array_append(&placeholders, _6, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1226);
	} else {
		ZEPHIR_CALL_METHOD(&referencedFields, relation, "getreferencedfields", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5, relation, "getreferencedfields", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(_5, &_8, &_7, 0, 0, "phalcon/mvc/model/manager.zep", 1237);
		for (
		  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
		  ; zephir_hash_move_forward_ex(_8, &_7)
		) {
			ZEPHIR_GET_HMKEY(refPosition, _8, _7);
			ZEPHIR_GET_HVALUE(field, _9);
			zephir_array_fetch(&_10, referencedFields, refPosition, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1234 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_11);
			ZEPHIR_CONCAT_SVSV(_11, "[", _10, "] = ?", refPosition);
			zephir_array_append(&conditions, _11, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1234);
			ZEPHIR_CALL_METHOD(&_6, record, "readattribute", &_12, 0, field);
			zephir_check_call_status();
			zephir_array_append(&placeholders, _6, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1235);
		}
	}
	ZEPHIR_INIT_VAR(findParams);
	zephir_create_array(findParams, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_0);
	zephir_fast_join_str(_0, SL(" AND "), conditions TSRMLS_CC);
	zephir_array_fast_append(findParams, _0);
	zephir_array_update_string(&findParams, SL("bind"), &placeholders, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_3, record, "getdi", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&findParams, SL("di"), &_3, PH_COPY | PH_SEPARATE);
	if (Z_TYPE_P(parameters) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(findArguments);
		zephir_fast_array_merge(findArguments, &(findParams), &(parameters) TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(findArguments, findParams);
	}
	_13 = zephir_array_isset_long(findArguments, 0);
	if (_13) {
		_13 = zephir_array_isset_string(findArguments, SS("conditions"));
	}
	if (_13) {
		zephir_array_fetch_long(&_10, findArguments, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1259 TSRMLS_CC);
		zephir_array_fetch_string(&_14, findArguments, SL("conditions"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1259 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_2);
		ZEPHIR_CONCAT_SVSVS(_2, "(", _10, ") AND (", _14, ")");
		zephir_array_update_long(&findArguments, 0, &_2, PH_COPY | PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1259);
		zephir_array_unset_string(&findArguments, SS("conditions"), PH_SEPARATE);
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(method, "")) {
		ZEPHIR_CALL_METHOD(&_3, relation, "gettype", NULL, 0);
		zephir_check_call_status();
		do {
			if (ZEPHIR_IS_LONG(_3, 0) || ZEPHIR_IS_LONG(_3, 1)) {
				ZEPHIR_INIT_VAR(retrieveMethod);
				ZVAL_STRING(retrieveMethod, "findFirst", 1);
				break;
			}
			if (ZEPHIR_IS_LONG(_3, 2)) {
				ZEPHIR_INIT_NVAR(retrieveMethod);
				ZVAL_STRING(retrieveMethod, "find", 1);
				break;
			}
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Unknown relation type", "phalcon/mvc/model/manager.zep", 1279);
			return;
		} while(0);

	} else {
		ZEPHIR_CPY_WRT(retrieveMethod, method);
	}
	ZEPHIR_INIT_VAR(arguments);
	zephir_create_array(arguments, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(arguments, findArguments);
	ZEPHIR_CALL_METHOD(&_3, relation, "isreusable", NULL, 0);
	zephir_check_call_status();
	reusable = zephir_get_boolval(_3);
	if (reusable) {
		ZEPHIR_INIT_VAR(uniqueKey);
		zephir_unique_key(uniqueKey, referencedModel, arguments TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&records, this_ptr, "getreusablerecords", NULL, 0, referencedModel, uniqueKey);
		zephir_check_call_status();
		_15 = Z_TYPE_P(records) == IS_ARRAY;
		if (!(_15)) {
			_15 = Z_TYPE_P(records) == IS_OBJECT;
		}
		if (_15) {
			RETURN_CCTOR(records);
		}
	}
	ZEPHIR_INIT_VAR(_16);
	zephir_create_array(_16, 2, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "load", NULL, 0, referencedModel);
	zephir_check_call_status();
	zephir_array_fast_append(_16, _3);
	zephir_array_fast_append(_16, retrieveMethod);
	ZEPHIR_INIT_NVAR(records);
	ZEPHIR_CALL_USER_FUNC_ARRAY(records, _16, arguments);
	zephir_check_call_status();
	if (reusable) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setreusablerecords", NULL, 0, referencedModel, uniqueKey, records);
		zephir_check_call_status();
	}
	RETURN_CCTOR(records);

}

/**
 * Returns a reusable object from the internal list
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getReusableRecords) {

	zval *modelName_param = NULL, *key_param = NULL, *records, *_0;
	zval *modelName = NULL, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &key_param);

	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}
	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_reusable"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&records, _0, key, 1 TSRMLS_CC)) {
		RETURN_CTOR(records);
	}
	RETURN_MM_NULL();

}

/**
 * Stores a reusable record in the internal list
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setReusableRecords) {

	zval *modelName_param = NULL, *key_param = NULL, *records;
	zval *modelName = NULL, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &modelName_param, &key_param, &records);

	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}
	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	zephir_update_property_array(this_ptr, SL("_reusable"), key, records TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Clears the internal reusable list
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, clearReusableObjects) {


	zephir_update_property_this(this_ptr, SL("_reusable"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);

}

/**
 * Gets belongsTo related records from a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getBelongsToRecords) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *modelName_param = NULL, *modelRelation, *record, *parameters = NULL, *belongsTo, *keyRelation, *relations, *_0, *_1, *_2;
	zval *method = NULL, *modelName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &method_param, &modelName_param, &modelRelation, &record, &parameters);

	if (unlikely(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(method, method_param);
	} else {
		ZEPHIR_INIT_VAR(method);
		ZVAL_EMPTY_STRING(method);
	}
	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}
	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(belongsTo);
	zephir_read_property_this(&belongsTo, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	if (Z_TYPE_P(belongsTo) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0);
		zephir_fast_strtolower(_0, modelName);
		ZEPHIR_INIT_VAR(_1);
		zephir_fast_strtolower(_1, modelRelation);
		ZEPHIR_INIT_VAR(keyRelation);
		ZEPHIR_CONCAT_VSV(keyRelation, _0, "$", _1);
		if (!(zephir_array_isset(belongsTo, keyRelation))) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_OBS_VAR(relations);
		zephir_array_fetch(&relations, belongsTo, keyRelation, PH_NOISY, "phalcon/mvc/model/manager.zep", 1366 TSRMLS_CC);
		zephir_array_fetch_long(&_2, relations, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1367 TSRMLS_CC);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrelationrecords", NULL, 0, _2, method, record, parameters);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Gets hasMany related records from a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasManyRecords) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *modelName_param = NULL, *modelRelation, *record, *parameters = NULL, *hasMany, *keyRelation, *relations, *_0, *_1, *_2;
	zval *method = NULL, *modelName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &method_param, &modelName_param, &modelRelation, &record, &parameters);

	if (unlikely(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(method, method_param);
	} else {
		ZEPHIR_INIT_VAR(method);
		ZVAL_EMPTY_STRING(method);
	}
	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}
	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(hasMany);
	zephir_read_property_this(&hasMany, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	if (Z_TYPE_P(hasMany) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0);
		zephir_fast_strtolower(_0, modelName);
		ZEPHIR_INIT_VAR(_1);
		zephir_fast_strtolower(_1, modelRelation);
		ZEPHIR_INIT_VAR(keyRelation);
		ZEPHIR_CONCAT_VSV(keyRelation, _0, "$", _1);
		if (!(zephir_array_isset(hasMany, keyRelation))) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_OBS_VAR(relations);
		zephir_array_fetch(&relations, hasMany, keyRelation, PH_NOISY, "phalcon/mvc/model/manager.zep", 1396 TSRMLS_CC);
		zephir_array_fetch_long(&_2, relations, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1397 TSRMLS_CC);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrelationrecords", NULL, 0, _2, method, record, parameters);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Gets belongsTo related records from a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOneRecords) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *modelName_param = NULL, *modelRelation, *record, *parameters = NULL, *hasOne, *keyRelation, *relations, *_0, *_1, *_2;
	zval *method = NULL, *modelName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &method_param, &modelName_param, &modelRelation, &record, &parameters);

	if (unlikely(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(method, method_param);
	} else {
		ZEPHIR_INIT_VAR(method);
		ZVAL_EMPTY_STRING(method);
	}
	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}
	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(hasOne);
	zephir_read_property_this(&hasOne, this_ptr, SL("_hasOne"), PH_NOISY_CC);
	if (Z_TYPE_P(hasOne) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0);
		zephir_fast_strtolower(_0, modelName);
		ZEPHIR_INIT_VAR(_1);
		zephir_fast_strtolower(_1, modelRelation);
		ZEPHIR_INIT_VAR(keyRelation);
		ZEPHIR_CONCAT_VSV(keyRelation, _0, "$", _1);
		if (!(zephir_array_isset(hasOne, keyRelation))) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_OBS_VAR(relations);
		zephir_array_fetch(&relations, hasOne, keyRelation, PH_NOISY, "phalcon/mvc/model/manager.zep", 1426 TSRMLS_CC);
		zephir_array_fetch_long(&_2, relations, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1427 TSRMLS_CC);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrelationrecords", NULL, 0, _2, method, record, parameters);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Gets all the belongsTo relations defined in a model
 *
 *<code>
 *	$relations = $modelsManager->getBelongsTo(new Robots());
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getBelongsTo) {

	zval *model, *belongsToSingle, *relations, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	belongsToSingle = zephir_fetch_nproperty_this(this_ptr, SL("_belongsToSingle"), PH_NOISY_CC);
	if (Z_TYPE_P(belongsToSingle) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0);
		zephir_get_class(_0, model, 1 TSRMLS_CC);
		if (zephir_array_isset_fetch(&relations, belongsToSingle, _0, 1 TSRMLS_CC)) {
			RETURN_CTOR(relations);
		}
	}
	array_init(return_value);
	RETURN_MM();

}

/**
 * Gets hasMany relations defined on a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasMany) {

	zval *model, *hasManySingle, *relations, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	hasManySingle = zephir_fetch_nproperty_this(this_ptr, SL("_hasManySingle"), PH_NOISY_CC);
	if (Z_TYPE_P(hasManySingle) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0);
		zephir_get_class(_0, model, 1 TSRMLS_CC);
		if (zephir_array_isset_fetch(&relations, hasManySingle, _0, 1 TSRMLS_CC)) {
			RETURN_CTOR(relations);
		}
	}
	array_init(return_value);
	RETURN_MM();

}

/**
 * Gets hasOne relations defined on a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOne) {

	zval *model, *hasOneSingle, *relations, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	hasOneSingle = zephir_fetch_nproperty_this(this_ptr, SL("_hasOneSingle"), PH_NOISY_CC);
	if (Z_TYPE_P(hasOneSingle) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0);
		zephir_get_class(_0, model, 1 TSRMLS_CC);
		if (zephir_array_isset_fetch(&relations, hasOneSingle, _0, 1 TSRMLS_CC)) {
			RETURN_CTOR(relations);
		}
	}
	array_init(return_value);
	RETURN_MM();

}

/**
 * Gets hasManyToMany relations defined on a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasManyToMany) {

	zval *model, *hasManyToManySingle, *relations, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	hasManyToManySingle = zephir_fetch_nproperty_this(this_ptr, SL("_hasManyToManySingle"), PH_NOISY_CC);
	if (Z_TYPE_P(hasManyToManySingle) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0);
		zephir_get_class(_0, model, 1 TSRMLS_CC);
		if (zephir_array_isset_fetch(&relations, hasManyToManySingle, _0, 1 TSRMLS_CC)) {
			RETURN_CTOR(relations);
		}
	}
	array_init(return_value);
	RETURN_MM();

}

/**
 * Gets hasOne relations defined on a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOneAndHasMany) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gethasone", NULL, 0, model);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "gethasmany", NULL, 0, model);
	zephir_check_call_status();
	zephir_fast_array_merge(return_value, &(_0), &(_1) TSRMLS_CC);
	RETURN_MM();

}

/**
 * Query all the relationships defined on a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelations) {

	HashTable *_1, *_4, *_7;
	HashPosition _0, _3, _6;
	zval *modelName_param = NULL, *entityName, *allRelations, *relations = NULL, *belongsTo, *relation = NULL, *hasOne, *hasMany, **_2, **_5, **_8;
	zval *modelName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modelName_param);

	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}


	ZEPHIR_INIT_VAR(entityName);
	zephir_fast_strtolower(entityName, modelName);
	ZEPHIR_INIT_VAR(allRelations);
	array_init(allRelations);
	belongsTo = zephir_fetch_nproperty_this(this_ptr, SL("_belongsToSingle"), PH_NOISY_CC);
	if (Z_TYPE_P(belongsTo) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(relations);
		if (zephir_array_isset_fetch(&relations, belongsTo, entityName, 0 TSRMLS_CC)) {
			zephir_is_iterable(relations, &_1, &_0, 0, 0, "phalcon/mvc/model/manager.zep", 1526);
			for (
			  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			  ; zephir_hash_move_forward_ex(_1, &_0)
			) {
				ZEPHIR_GET_HVALUE(relation, _2);
				zephir_array_append(&allRelations, relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1524);
			}
		}
	}
	hasMany = zephir_fetch_nproperty_this(this_ptr, SL("_hasManySingle"), PH_NOISY_CC);
	if (Z_TYPE_P(hasMany) == IS_ARRAY) {
		ZEPHIR_OBS_NVAR(relations);
		if (zephir_array_isset_fetch(&relations, hasMany, entityName, 0 TSRMLS_CC)) {
			zephir_is_iterable(relations, &_4, &_3, 0, 0, "phalcon/mvc/model/manager.zep", 1538);
			for (
			  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
			  ; zephir_hash_move_forward_ex(_4, &_3)
			) {
				ZEPHIR_GET_HVALUE(relation, _5);
				zephir_array_append(&allRelations, relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1536);
			}
		}
	}
	hasOne = zephir_fetch_nproperty_this(this_ptr, SL("_hasOneSingle"), PH_NOISY_CC);
	if (Z_TYPE_P(hasOne) == IS_ARRAY) {
		ZEPHIR_OBS_NVAR(relations);
		if (zephir_array_isset_fetch(&relations, hasOne, entityName, 0 TSRMLS_CC)) {
			zephir_is_iterable(relations, &_7, &_6, 0, 0, "phalcon/mvc/model/manager.zep", 1550);
			for (
			  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
			  ; zephir_hash_move_forward_ex(_7, &_6)
			) {
				ZEPHIR_GET_HVALUE(relation, _8);
				zephir_array_append(&allRelations, relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1548);
			}
		}
	}
	RETURN_CCTOR(allRelations);

}

/**
 * Query the first relationship defined between two models
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationsBetween) {

	zval *first_param = NULL, *second_param = NULL, *keyRelation, *belongsTo, *hasMany, *hasOne, *relations = NULL, *_0, *_1;
	zval *first = NULL, *second = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &first_param, &second_param);

	if (unlikely(Z_TYPE_P(first_param) != IS_STRING && Z_TYPE_P(first_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'first' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(first_param) == IS_STRING)) {
		zephir_get_strval(first, first_param);
	} else {
		ZEPHIR_INIT_VAR(first);
		ZVAL_EMPTY_STRING(first);
	}
	if (unlikely(Z_TYPE_P(second_param) != IS_STRING && Z_TYPE_P(second_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'second' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(second_param) == IS_STRING)) {
		zephir_get_strval(second, second_param);
	} else {
		ZEPHIR_INIT_VAR(second);
		ZVAL_EMPTY_STRING(second);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, first);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, second);
	ZEPHIR_INIT_VAR(keyRelation);
	ZEPHIR_CONCAT_VSV(keyRelation, _0, "$", _1);
	belongsTo = zephir_fetch_nproperty_this(this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	if (Z_TYPE_P(belongsTo) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(relations);
		if (zephir_array_isset_fetch(&relations, belongsTo, keyRelation, 0 TSRMLS_CC)) {
			RETURN_CCTOR(relations);
		}
	}
	hasMany = zephir_fetch_nproperty_this(this_ptr, SL("_hasMany"), PH_NOISY_CC);
	if (Z_TYPE_P(hasMany) == IS_ARRAY) {
		ZEPHIR_OBS_NVAR(relations);
		if (zephir_array_isset_fetch(&relations, hasMany, keyRelation, 0 TSRMLS_CC)) {
			RETURN_CCTOR(relations);
		}
	}
	hasOne = zephir_fetch_nproperty_this(this_ptr, SL("_hasOne"), PH_NOISY_CC);
	if (Z_TYPE_P(hasOne) == IS_ARRAY) {
		ZEPHIR_OBS_NVAR(relations);
		if (zephir_array_isset_fetch(&relations, hasOne, keyRelation, 0 TSRMLS_CC)) {
			RETURN_CCTOR(relations);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Creates a Phalcon\Mvc\Model\Query without execute it
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, createQuery) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zval *phql_param = NULL, *dependencyInjector, *query = NULL, *_0 = NULL, *_2;
	zval *phql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &phql_param);

	if (unlikely(Z_TYPE_P(phql_param) != IS_STRING && Z_TYPE_P(phql_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'phql' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(phql_param) == IS_STRING)) {
		zephir_get_strval(phql, phql_param);
	} else {
		ZEPHIR_INIT_VAR(phql);
		ZVAL_EMPTY_STRING(phql);
	}


	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injection object is required to access ORM services", "phalcon/mvc/model/manager.zep", 1607);
		return;
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_1, phql);
	zephir_array_fast_append(_1, dependencyInjector);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "Phalcon\\Mvc\\Model\\Query", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, dependencyInjector, "get", NULL, 0, _2, _1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(query, _0);
	zephir_update_property_this(this_ptr, SL("_lastQuery"), query TSRMLS_CC);
	RETURN_CCTOR(query);

}

/**
 * Creates a Phalcon\Mvc\Model\Query and execute it
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, executeQuery) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_2;
	zval *phql_param = NULL, *placeholders = NULL, *types = NULL, *dependencyInjector = NULL, *query = NULL, *_0, *_1 = NULL, *_3;
	zval *phql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &phql_param, &placeholders, &types);

	if (unlikely(Z_TYPE_P(phql_param) != IS_STRING && Z_TYPE_P(phql_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'phql' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(phql_param) == IS_STRING)) {
		zephir_get_strval(phql, phql_param);
	} else {
		ZEPHIR_INIT_VAR(phql);
		ZVAL_EMPTY_STRING(phql);
	}
	if (!placeholders) {
		placeholders = ZEPHIR_GLOBAL(global_null);
	}
	if (!types) {
		types = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injection object is required to access ORM services", "phalcon/mvc/model/manager.zep", 1627);
		return;
	}
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_2, phql);
	zephir_array_fast_append(_2, dependencyInjector);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Mvc\\Model\\Query", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "get", NULL, 0, _3, _2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(query, _1);
	zephir_update_property_this(this_ptr, SL("_lastQuery"), query TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(query, "execute", NULL, 0, placeholders, types);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Creates a Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, createBuilder) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_2;
	zval *params = NULL, *dependencyInjector = NULL, *_0, *_1 = NULL, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &params);

	if (!params) {
		params = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injection object is required to access ORM services", "phalcon/mvc/model/manager.zep", 1651);
		return;
	}
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_2, params);
	zephir_array_fast_append(_2, dependencyInjector);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Mvc\\Model\\Query\\Builder", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "get", NULL, 0, _3, _2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	RETURN_CCTOR(_1);

}

/**
 * Returns the lastest query created or executed in the models manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getLastQuery) {


	RETURN_MEMBER(this_ptr, "_lastQuery");

}

/**
 * Registers shorter aliases for namespaces in PHQL statements
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, registerNamespaceAlias) {

	zval *alias_param = NULL, *namespaceName_param = NULL;
	zval *alias = NULL, *namespaceName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &alias_param, &namespaceName_param);

	zephir_get_strval(alias, alias_param);
	zephir_get_strval(namespaceName, namespaceName_param);


	zephir_update_property_array(this_ptr, SL("_namespaceAliases"), alias, namespaceName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a real namespace from its alias
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getNamespaceAlias) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *alias_param = NULL, *namespaceName, *_0, *_1;
	zval *alias = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &alias_param);

	if (unlikely(Z_TYPE_P(alias_param) != IS_STRING && Z_TYPE_P(alias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(alias_param) == IS_STRING)) {
		zephir_get_strval(alias, alias_param);
	} else {
		ZEPHIR_INIT_VAR(alias);
		ZVAL_EMPTY_STRING(alias);
	}


	ZEPHIR_OBS_VAR(namespaceName);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_namespaceAliases"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&namespaceName, _0, alias, 0 TSRMLS_CC)) {
		RETURN_CCTOR(namespaceName);
	}
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, phalcon_mvc_model_exception_ce);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SVS(_2, "Namespace alias '", alias, "' is not registered");
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _2);
	zephir_check_call_status();
	zephir_throw_exception_debug(_1, "phalcon/mvc/model/manager.zep", 1686 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Returns all the registered namespace aliases
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getNamespaceAliases) {


	RETURN_MEMBER(this_ptr, "_namespaceAliases");

}

