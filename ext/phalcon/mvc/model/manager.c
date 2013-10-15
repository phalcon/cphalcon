
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/hash.h"


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
 * Phalcon\Mvc\Model\Manager
 *
 * This components controls the initialization of models, keeping record of relations
 * between the different models of the application.
 *
 * A ModelsManager is injected to a model via a Dependency Injector/Services Container such as Phalcon\DI.
 *
 * <code>
 * $di = new Phalcon\DI();
 *
 * $di->set('modelsManager', function() {
 *      return new Phalcon\Mvc\Model\Manager();
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
	 *
	 */
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_dynamicUpdate"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_namespaceAliases"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the DependencyInjector container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Sets a global events manager
 *
 * @param Phalcon\Events\ManagerInterface eventsManager
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setEventsManager) {

	zval *eventsManager;

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_this(this_ptr, SL("_eventsManager"), eventsManager TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getEventsManager) {


	RETURN_MEMBER(this_ptr, "_eventsManager");

}

/**
 * Sets a custom events manager for a specific model
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param Phalcon\Events\ManagerInterface eventsManager
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setCustomEventsManager) {

	zval *model, *eventsManager, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &eventsManager);



	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "get_class_lower", model);
	zephir_update_property_array(this_ptr, SL("_customEventsManager"), _0, eventsManager TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a custom events manager related to a model
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getCustomEventsManager) {

	zval *model, *customEventsManager, *eventsManager, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	customEventsManager = zephir_fetch_nproperty_this(this_ptr, SL("_customEventsManager"), PH_NOISY_CC);
	if ((Z_TYPE_P(customEventsManager) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "get_class_lower", model);
		if (zephir_array_isset_fetch(&eventsManager, customEventsManager, _0, 1 TSRMLS_CC)) {
			RETURN_CTOR(eventsManager);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Initializes a model in the model manager
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, initialize) {

	zval *model, *className, *initialized, *eventsManager = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_INIT_VAR(className);
	zephir_call_func_p1(className, "get_class_lower", model);
	initialized = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (zephir_array_isset(initialized, className)) {
		RETURN_MM_BOOL(0);
	}
	zephir_update_property_array(this_ptr, SL("_initialized"), className, model TSRMLS_CC);
	if ((zephir_method_exists_str(model, SS("initialize") TSRMLS_CC) == SUCCESS)) {
		zephir_call_method_noret(model, "initialize");
	}
	zephir_update_property_this(this_ptr, SL("_lastInitialized"), model TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _0);
	if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "modelsManager:afterInitialize", 1);
		zephir_call_method_p3_noret(eventsManager, "fire", _1, this_ptr, model);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Check whether a model is already initialized
 *
 * @param string modelName
 * @return bool
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, isInitialized) {

	zval *modelName_param = NULL, *initialized, *_0;
	zval *modelName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modelName_param);

		if (Z_TYPE_P(modelName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		modelName = modelName_param;


	initialized = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, modelName);
	RETURN_MM_BOOL(zephir_array_isset(initialized, _0));

}

/**
 * Get last initialized model
 *
 * @return Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getLastInitialized) {


	RETURN_MEMBER(this_ptr, "_lastInitialized");

}

/**
 * Loads a model throwing an exception if it doesn't exist
 *
 * @param  string modelName
 * @param  boolean newInstance
 * @return Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, load) {

	zend_class_entry *_2;
	zend_bool newInstance;
	zval *modelName_param = NULL, *newInstance_param = NULL, *initialized, *model, *_0, *_1, *_3, *_4;
	zval *modelName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &modelName_param, &newInstance_param);

		if (Z_TYPE_P(modelName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		modelName = modelName_param;
	if (!newInstance_param) {
		newInstance = 0;
	} else {
		newInstance = zephir_get_boolval(newInstance_param);
	}


	initialized = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, modelName);
	if (zephir_array_isset_fetch(&model, initialized, _0, 1 TSRMLS_CC)) {
		if (newInstance) {
		}
		RETURN_CTOR(model);
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func_p1(_1, "class_exists", modelName);
	if (zephir_is_true(_1)) {
		_2 = zend_fetch_class(SL("modelName"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(return_value, _2);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_3);
	object_init_ex(_3, phalcon_mvc_model_exception_ce);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SVS(_4, "Model '", modelName, "' could not be loaded");
	zephir_call_method_p1_noret(_3, "__construct", _4);
	zephir_throw_exception(_3 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Sets the mapped source for a model
 *
 * @param Phalcon\Mvc\Model model
 * @param string source
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setModelSource) {

	zval *source = NULL;
	zval *model, *source_param = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &source_param);

		if (Z_TYPE_P(source_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'source' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		source = source_param;


	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "get_class_lower", model);
	zephir_update_property_array(this_ptr, SL("_sources"), _0, source TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the mapped source for a model
 *
 * @param Phalcon\Mvc\Model model
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getModelSource) {

	zval *model, *sources, *entityName, *source = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_INIT_VAR(entityName);
	zephir_call_func_p1(entityName, "get_class_lower", model);
	sources = zephir_fetch_nproperty_this(this_ptr, SL("_sources"), PH_NOISY_CC);
	if ((Z_TYPE_P(sources) == IS_ARRAY)) {
		ZEPHIR_OBS_VAR(source);
		if (zephir_array_isset_fetch(&source, sources, entityName, 0 TSRMLS_CC)) {
			RETURN_CCTOR(source);
		}
	}
	ZEPHIR_INIT_NVAR(source);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "get_class_ns", model);
	zephir_uncamelize(source, _0);
	zephir_update_property_array(this_ptr, SL("_sources"), entityName, source TSRMLS_CC);
	RETURN_CCTOR(source);

}

/**
 * Sets the mapped schema for a model
 *
 * @param Phalcon\Mvc\Model model
 * @param string schema
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setModelSchema) {

	zval *schema = NULL;
	zval *model, *schema_param = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &schema_param);

		if (Z_TYPE_P(schema_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schema' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		schema = schema_param;


	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "get_class_lower", model);
	zephir_update_property_array(this_ptr, SL("_schemas"), _0, schema TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the mapped schema for a model
 *
 * @param Phalcon\Mvc\Model model
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getModelSchema) {

	zval *model, *schemas, *schema, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	schemas = zephir_fetch_nproperty_this(this_ptr, SL("_schemas"), PH_NOISY_CC);
	if ((Z_TYPE_P(schemas) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "get_class_lower", model);
		if (zephir_array_isset_fetch(&schema, schemas, _0, 1 TSRMLS_CC)) {
			RETURN_CTOR(schema);
		}
	}
	RETURN_MM_STRING("", 1);

}

/**
 * Sets both write and read connection service for a model
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param string connectionService
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setConnectionService) {

	zval *connectionService = NULL;
	zval *model, *connectionService_param = NULL, *entityName;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &connectionService_param);

		if (Z_TYPE_P(connectionService_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		connectionService = connectionService_param;


	ZEPHIR_INIT_VAR(entityName);
	zephir_call_func_p1(entityName, "get_class_lower", model);
	zephir_update_property_array(this_ptr, SL("_readConnectionServices"), entityName, connectionService TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_writeConnectionServices"), entityName, connectionService TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets write connection service for a model
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param string connectionService
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setWriteConnectionService) {

	zval *connectionService = NULL;
	zval *model, *connectionService_param = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &connectionService_param);

		if (Z_TYPE_P(connectionService_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		connectionService = connectionService_param;


	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "get_class_lower", model);
	zephir_update_property_array(this_ptr, SL("_writeConnectionServices"), _0, connectionService TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets read connection service for a model
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param string connectionService
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setReadConnectionService) {

	zval *connectionService = NULL;
	zval *model, *connectionService_param = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &connectionService_param);

		if (Z_TYPE_P(connectionService_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		connectionService = connectionService_param;


	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "get_class_lower", model);
	zephir_update_property_array(this_ptr, SL("_readConnectionServices"), _0, connectionService TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the connection to read data related to a model
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @return Phalcon\Db\AdapterInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getReadConnection) {

	zval *model, *connectionServices, *dependencyInjector = NULL, *service, *connection = NULL, *_0 = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	connectionServices = zephir_fetch_nproperty_this(this_ptr, SL("_readConnectionServices"), PH_NOISY_CC);
	if ((Z_TYPE_P(connectionServices) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "get_class_lower", model);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _1);
	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	ZEPHIR_INIT_VAR(connection);
	if (zephir_is_true(service)) {
		ZEPHIR_INIT_NVAR(_0);
		zephir_call_method_p1(_0, dependencyInjector, "getshared", service);
		ZEPHIR_CPY_WRT(connection, _0);
	} else {
		ZEPHIR_INIT_NVAR(_0);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "db", 1);
		zephir_call_method_p1(_0, dependencyInjector, "getshared", _2);
		ZEPHIR_CPY_WRT(connection, _0);
	}
	if ((Z_TYPE_P(connection) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid injected connection service");
		return;
	}
	RETURN_CCTOR(connection);

}

/**
 * Returns the connection to write data related to a model
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @return Phalcon\Db\AdapterInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getWriteConnection) {

	zval *model, *connectionServices, *dependencyInjector = NULL, *service, *connection = NULL, *_0 = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	connectionServices = zephir_fetch_nproperty_this(this_ptr, SL("_writeConnectionServices"), PH_NOISY_CC);
	if ((Z_TYPE_P(connectionServices) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "get_class_lower", model);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _1);
	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	ZEPHIR_INIT_VAR(connection);
	if (zephir_is_true(service)) {
		ZEPHIR_INIT_NVAR(_0);
		zephir_call_method_p1(_0, dependencyInjector, "getshared", service);
		ZEPHIR_CPY_WRT(connection, _0);
	} else {
		ZEPHIR_INIT_NVAR(_0);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "db", 1);
		zephir_call_method_p1(_0, dependencyInjector, "getshared", _2);
		ZEPHIR_CPY_WRT(connection, _0);
	}
	if ((Z_TYPE_P(connection) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid injected connection service");
		return;
	}
	RETURN_CCTOR(connection);

}

/**
 * Returns the connection service name used to read data related to a model
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param string
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getReadConnectionService) {

	zval *model, *connectionServices, *connection, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	connectionServices = zephir_fetch_nproperty_this(this_ptr, SL("_readConnectionServices"), PH_NOISY_CC);
	if ((Z_TYPE_P(connectionServices) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "get_class_lower", model);
		if (zephir_array_isset_fetch(&connection, connectionServices, _0, 1 TSRMLS_CC)) {
			RETURN_CTOR(connection);
		}
	}
	RETURN_MM_STRING("db", 1);

}

/**
 * Returns the connection service name used to write data related to a model
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param string
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getWriteConnectionService) {

	zval *model, *connectionServices, *connection, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	connectionServices = zephir_fetch_nproperty_this(this_ptr, SL("_writeConnectionServices"), PH_NOISY_CC);
	if ((Z_TYPE_P(connectionServices) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "get_class_lower", model);
		if (zephir_array_isset_fetch(&connection, connectionServices, _0, 1 TSRMLS_CC)) {
			RETURN_CTOR(connection);
		}
	}
	RETURN_MM_STRING("db", 1);

}

/**
 * Receives events generated in the models and dispatches them to a events-manager if available
 * Notify the behaviors that are listening in the model
 *
 * @param string eventName
 * @param Phalcon\Mvc\ModelInterface model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, notifyEvent) {

	zend_function *_4 = NULL;
	HashTable *_2;
	HashPosition _1;
	zval *eventName_param = NULL, *model, *status = NULL, *behavior = NULL, *modelsBehaviors, *eventsManager, *customEventsManager = NULL, *behaviors, *_0 = NULL, **_3, *_5 = NULL;
	zval *eventName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &eventName_param, &model);

		if (Z_TYPE_P(eventName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		eventName = eventName_param;


	ZEPHIR_INIT_VAR(status);
	ZVAL_NULL(status);
	behaviors = zephir_fetch_nproperty_this(this_ptr, SL("_behaviors"), PH_NOISY_CC);
	if ((Z_TYPE_P(behaviors) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "get_class_lower", model);
		if (zephir_array_isset_fetch(&modelsBehaviors, behaviors, _0, 1 TSRMLS_CC)) {
			zephir_is_iterable(modelsBehaviors, &_2, &_1, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
				; zend_hash_move_forward_ex(_2, &_1)
			) {
				ZEPHIR_GET_HVALUE(behavior, _3);
				ZEPHIR_INIT_NVAR(status);
				zephir_call_method_p2_cache(status, behavior, "notify", &_4, eventName, model);
				if (ZEPHIR_IS_FALSE(status)) {
					RETURN_MM_BOOL(0);
				}
			}
		}
	}
	eventsManager = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
		ZEPHIR_INIT_VAR(_5);
		ZEPHIR_CONCAT_SV(_5, "model:", eventName);
		ZEPHIR_INIT_BNVAR(status);
		zephir_call_method_p2(status, eventsManager, "fire", _5, model);
		if (ZEPHIR_IS_FALSE(status)) {
			RETURN_CCTOR(status);
		}
	}
	ZEPHIR_OBS_VAR(customEventsManager);
	zephir_read_property_this(&customEventsManager, this_ptr, SL("_customEventsManager"), PH_NOISY_CC);
	if ((Z_TYPE_P(customEventsManager) == IS_ARRAY)) {
		ZEPHIR_OBS_NVAR(customEventsManager);
		ZEPHIR_INIT_NVAR(_0);
		zephir_call_func_p1(_0, "get_class_lower", model);
		if (zephir_array_isset_fetch(&customEventsManager, customEventsManager, _0, 0 TSRMLS_CC)) {
			ZEPHIR_INIT_LNVAR(_5);
			ZEPHIR_CONCAT_SV(_5, "model:", eventName);
			ZEPHIR_INIT_BNVAR(status);
			zephir_call_method_p2(status, customEventsManager, "fire", _5, model);
			if (ZEPHIR_IS_FALSE(status)) {
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
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param string eventName
 * @param array data
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, missingMethod) {

	zend_function *_4 = NULL;
	HashTable *_2;
	HashPosition _1;
	zval *eventName = NULL;
	zval *model, *eventName_param = NULL, *data, *behaviors, *modelsBehaviors, *result = NULL, *eventsManager, *behavior = NULL, *_0, **_3, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &model, &eventName_param, &data);

		if (Z_TYPE_P(eventName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		eventName = eventName_param;


	behaviors = zephir_fetch_nproperty_this(this_ptr, SL("_behaviors"), PH_NOISY_CC);
	if ((Z_TYPE_P(behaviors) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "get_class_lower", model);
		if (zephir_array_isset_fetch(&modelsBehaviors, behaviors, _0, 1 TSRMLS_CC)) {
			zephir_is_iterable(modelsBehaviors, &_2, &_1, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
				; zend_hash_move_forward_ex(_2, &_1)
			) {
				ZEPHIR_GET_HVALUE(behavior, _3);
				ZEPHIR_INIT_NVAR(result);
				zephir_call_method_p3_cache(result, behavior, "missingmethod", &_4, model, eventName, data);
				if ((Z_TYPE_P(result) != IS_NULL)) {
					RETURN_CCTOR(result);
				}
			}
		}
	}
	eventsManager = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
		ZEPHIR_INIT_VAR(_5);
		ZEPHIR_CONCAT_SV(_5, "model:", eventName);
		zephir_call_method_p3(return_value, eventsManager, "fire", _5, model, data);
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Binds a behavior to a model
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param Phalcon\Mvc\Model\BehaviorInterface behavior
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, addBehavior) {

	zval *model, *behavior, *entityName, *behaviors, *modelsBehaviors;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &behavior);



	ZEPHIR_INIT_VAR(entityName);
	zephir_call_func_p1(entityName, "get_class_lower", model);
	behaviors = zephir_fetch_nproperty_this(this_ptr, SL("_behaviors"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(modelsBehaviors);
	if (!(zephir_array_isset_fetch(&modelsBehaviors, behaviors, entityName, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_BNVAR(modelsBehaviors);
		array_init(modelsBehaviors);
	}
	zephir_array_append(&modelsBehaviors, behavior, PH_SEPARATE);
	zephir_update_property_array(this_ptr, SL("_behaviors"), entityName, modelsBehaviors TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets if a model must keep snapshots
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param boolean keepSnapshots
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, keepSnapshots) {

	zend_bool keepSnapshots;
	zval *model, *keepSnapshots_param = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &keepSnapshots_param);

		keepSnapshots = zephir_get_boolval(keepSnapshots_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "get_class_lower", model);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_BOOL(_1, keepSnapshots);
	zephir_update_property_array(this_ptr, SL("_keepSnapshots"), _0, _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if a model is keeping snapshots for the queried records
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, isKeepingSnapshots) {

	zval *model, *keepSnapshots, *isKeeping, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	keepSnapshots = zephir_fetch_nproperty_this(this_ptr, SL("_keepSnapshots"), PH_NOISY_CC);
	if ((Z_TYPE_P(keepSnapshots) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "get_class_lower", model);
		if (zephir_array_isset_fetch(&isKeeping, keepSnapshots, _0, 1 TSRMLS_CC)) {
			RETURN_CTOR(isKeeping);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Sets if a model must use dynamic update instead of the all-field update
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param boolean dynamicUpdate
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, useDynamicUpdate) {

	zend_bool dynamicUpdate;
	zval *model, *dynamicUpdate_param = NULL, *entityName, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &dynamicUpdate_param);

		dynamicUpdate = zephir_get_boolval(dynamicUpdate_param);


	ZEPHIR_INIT_VAR(entityName);
	zephir_call_func_p1(entityName, "get_class_lower", model);
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
 *
 * @param Phalcon\Mvc\Model model
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, isUsingDynamicUpdate) {

	zval *model, *dynamicUpdate, *isUsing, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	dynamicUpdate = zephir_fetch_nproperty_this(this_ptr, SL("_dynamicUpdate"), PH_NOISY_CC);
	if ((Z_TYPE_P(dynamicUpdate) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "get_class_lower", model);
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

	zval *referencedModel = NULL;
	zval *model, *fields, *referencedModel_param = NULL, *referencedFields, *options = NULL, *entityName, *referencedEntity, *hasOne, *relation, *keyRelation, *relations, *alias, *lowerAlias = NULL, *hasOneSingle, *singleRelations, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &model, &fields, &referencedModel_param, &referencedFields, &options);

		if (Z_TYPE_P(referencedModel_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referencedModel' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		referencedModel = referencedModel_param;
	if (!options) {
		ZEPHIR_CPY_WRT(options, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_INIT_VAR(entityName);
	zephir_call_func_p1(entityName, "get_class_lower", model);
	ZEPHIR_INIT_VAR(referencedEntity);
	zephir_fast_strtolower(referencedEntity, referencedModel);
	ZEPHIR_INIT_VAR(keyRelation);
	ZEPHIR_CONCAT_VSV(keyRelation, entityName, "$", referencedEntity);
	hasOne = zephir_fetch_nproperty_this(this_ptr, SL("_hasOne"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(relations);
	if (!(zephir_array_isset_fetch(&relations, hasOne, keyRelation, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_BNVAR(relations);
		array_init(relations);
	}
	if ((Z_TYPE_P(referencedFields) == IS_ARRAY)) {
		if ((zephir_fast_count_int(fields TSRMLS_CC) != zephir_fast_count_int(referencedFields TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same");
			return;
		}
	}
	ZEPHIR_INIT_VAR(relation);
	object_init_ex(relation, phalcon_mvc_model_relation_ce);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 1);
	zephir_call_method_p5_noret(relation, "__construct", _0, referencedModel, fields, referencedFields, options);
	if (zephir_array_isset_string_fetch(&alias, options, SS("alias"), 1 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(lowerAlias);
		zephir_fast_strtolower(lowerAlias, alias);
	} else {
		ZEPHIR_CPY_WRT(lowerAlias, referencedEntity);
	}
	zephir_array_append(&relations, relation, PH_SEPARATE);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VSV(_1, entityName, "$", lowerAlias);
	zephir_update_property_array(this_ptr, SL("_aliases"), _1, relation TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_hasOne"), keyRelation, relations TSRMLS_CC);
	hasOneSingle = zephir_fetch_nproperty_this(this_ptr, SL("_hasOneSingle"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(singleRelations);
	if (!(zephir_array_isset_fetch(&singleRelations, hasOneSingle, entityName, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_BNVAR(singleRelations);
		array_init(singleRelations);
	}
	zephir_array_append(&singleRelations, relation, PH_SEPARATE);
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

	zval *referencedModel = NULL;
	zval *model, *fields, *referencedModel_param = NULL, *referencedFields, *options = NULL, *entityName, *referencedEntity, *belongsTo, *relation, *keyRelation, *relations, *alias, *lowerAlias = NULL, *belongsToSingle, *singleRelations, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &model, &fields, &referencedModel_param, &referencedFields, &options);

		if (Z_TYPE_P(referencedModel_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referencedModel' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		referencedModel = referencedModel_param;
	if (!options) {
		ZEPHIR_CPY_WRT(options, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_INIT_VAR(entityName);
	zephir_call_func_p1(entityName, "get_class_lower", model);
	ZEPHIR_INIT_VAR(referencedEntity);
	zephir_fast_strtolower(referencedEntity, referencedModel);
	ZEPHIR_INIT_VAR(keyRelation);
	ZEPHIR_CONCAT_VSV(keyRelation, entityName, "$", referencedEntity);
	belongsTo = zephir_fetch_nproperty_this(this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(relations);
	if (!(zephir_array_isset_fetch(&relations, belongsTo, keyRelation, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_BNVAR(relations);
		array_init(relations);
	}
	if ((Z_TYPE_P(referencedFields) == IS_ARRAY)) {
		if ((zephir_fast_count_int(fields TSRMLS_CC) != zephir_fast_count_int(referencedFields TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same");
			return;
		}
	}
	ZEPHIR_INIT_VAR(relation);
	object_init_ex(relation, phalcon_mvc_model_relation_ce);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0);
	zephir_call_method_p5_noret(relation, "__construct", _0, referencedModel, fields, referencedFields, options);
	if (zephir_array_isset_string_fetch(&alias, options, SS("alias"), 1 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(lowerAlias);
		zephir_fast_strtolower(lowerAlias, alias);
	} else {
		ZEPHIR_CPY_WRT(lowerAlias, referencedEntity);
	}
	zephir_array_append(&relations, relation, PH_SEPARATE);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VSV(_1, entityName, "$", lowerAlias);
	zephir_update_property_array(this_ptr, SL("_aliases"), _1, relation TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_belongsTo"), keyRelation, relations TSRMLS_CC);
	belongsToSingle = zephir_fetch_nproperty_this(this_ptr, SL("_belongsToSingle"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(singleRelations);
	if (!(zephir_array_isset_fetch(&singleRelations, belongsToSingle, entityName, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_BNVAR(singleRelations);
		array_init(singleRelations);
	}
	zephir_array_append(&singleRelations, relation, PH_SEPARATE);
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

	zval *referencedModel = NULL;
	zval *model, *fields, *referencedModel_param = NULL, *referencedFields, *options = NULL, *entityName, *referencedEntity, *hasMany, *relation, *keyRelation, *relations, *alias, *lowerAlias = NULL, *hasManySingle, *singleRelations, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &model, &fields, &referencedModel_param, &referencedFields, &options);

		if (Z_TYPE_P(referencedModel_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referencedModel' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		referencedModel = referencedModel_param;
	if (!options) {
		ZEPHIR_CPY_WRT(options, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_INIT_VAR(entityName);
	zephir_call_func_p1(entityName, "get_class_lower", model);
	ZEPHIR_INIT_VAR(referencedEntity);
	zephir_fast_strtolower(referencedEntity, referencedModel);
	ZEPHIR_INIT_VAR(keyRelation);
	ZEPHIR_CONCAT_VSV(keyRelation, entityName, "$", referencedEntity);
	hasMany = zephir_fetch_nproperty_this(this_ptr, SL("_hasMany"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(relations);
	if (!(zephir_array_isset_fetch(&relations, hasMany, keyRelation, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_BNVAR(relations);
		array_init(relations);
	}
	if ((Z_TYPE_P(referencedFields) == IS_ARRAY)) {
		if ((zephir_fast_count_int(fields TSRMLS_CC) != zephir_fast_count_int(referencedFields TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same");
			return;
		}
	}
	ZEPHIR_INIT_VAR(relation);
	object_init_ex(relation, phalcon_mvc_model_relation_ce);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0);
	zephir_call_method_p5_noret(relation, "__construct", _0, referencedModel, fields, referencedFields, options);
	if (zephir_array_isset_string_fetch(&alias, options, SS("alias"), 1 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(lowerAlias);
		zephir_fast_strtolower(lowerAlias, alias);
	} else {
		ZEPHIR_CPY_WRT(lowerAlias, referencedEntity);
	}
	zephir_array_append(&relations, relation, PH_SEPARATE);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VSV(_1, entityName, "$", lowerAlias);
	zephir_update_property_array(this_ptr, SL("_aliases"), _1, relation TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_hasMany"), keyRelation, relations TSRMLS_CC);
	hasManySingle = zephir_fetch_nproperty_this(this_ptr, SL("_hasManySingle"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(singleRelations);
	if (!(zephir_array_isset_fetch(&singleRelations, hasManySingle, entityName, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_BNVAR(singleRelations);
		array_init(singleRelations);
	}
	zephir_array_append(&singleRelations, relation, PH_SEPARATE);
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

	zval *intermediateModel = NULL, *referencedModel = NULL;
	zval *model, *fields, *intermediateModel_param = NULL, *intermediateFields, *intermediateReferencedFields, *referencedModel_param = NULL, *referencedFields, *options = NULL, *entityName, *referencedEntity, *hasManyToMany, *relation, *keyRelation, *relations, *alias, *lowerAlias = NULL, *hasManyToManySingle, *singleRelations, *intermediateEntity, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 7, 1, &model, &fields, &intermediateModel_param, &intermediateFields, &intermediateReferencedFields, &referencedModel_param, &referencedFields, &options);

		if (Z_TYPE_P(intermediateModel_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'intermediateModel' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		intermediateModel = intermediateModel_param;
		if (Z_TYPE_P(referencedModel_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referencedModel' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		referencedModel = referencedModel_param;
	if (!options) {
		ZEPHIR_CPY_WRT(options, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_INIT_VAR(entityName);
	zephir_call_func_p1(entityName, "get_class_lower", model);
	ZEPHIR_INIT_VAR(intermediateEntity);
	zephir_fast_strtolower(intermediateEntity, intermediateModel);
	ZEPHIR_INIT_VAR(referencedEntity);
	zephir_fast_strtolower(referencedEntity, referencedModel);
	ZEPHIR_INIT_VAR(keyRelation);
	ZEPHIR_CONCAT_VSV(keyRelation, entityName, "$", referencedEntity);
	hasManyToMany = zephir_fetch_nproperty_this(this_ptr, SL("_hasManyToMany"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(relations);
	if (!(zephir_array_isset_fetch(&relations, hasManyToMany, keyRelation, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_BNVAR(relations);
		array_init(relations);
	}
	if ((Z_TYPE_P(intermediateFields) == IS_ARRAY)) {
		if ((zephir_fast_count_int(fields TSRMLS_CC) != zephir_fast_count_int(intermediateFields TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same");
			return;
		}
	}
	if ((Z_TYPE_P(intermediateReferencedFields) == IS_ARRAY)) {
		if ((zephir_fast_count_int(fields TSRMLS_CC) != zephir_fast_count_int(intermediateFields TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same");
			return;
		}
	}
	ZEPHIR_INIT_VAR(relation);
	object_init_ex(relation, phalcon_mvc_model_relation_ce);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 4);
	zephir_call_method_p5_noret(relation, "__construct", _0, referencedModel, fields, referencedFields, options);
	zephir_call_method_p3_noret(relation, "setintermediaterelation", intermediateFields, intermediateModel, intermediateReferencedFields);
	if (zephir_array_isset_string_fetch(&alias, options, SS("alias"), 1 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(lowerAlias);
		zephir_fast_strtolower(lowerAlias, alias);
	} else {
		ZEPHIR_CPY_WRT(lowerAlias, referencedEntity);
	}
	zephir_array_append(&relations, relation, PH_SEPARATE);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VSV(_1, entityName, "$", lowerAlias);
	zephir_update_property_array(this_ptr, SL("_aliases"), _1, relation TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_hasManyToMany"), keyRelation, relations TSRMLS_CC);
	hasManyToManySingle = zephir_fetch_nproperty_this(this_ptr, SL("_hasManyToManySingle"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(singleRelations);
	if (zephir_array_isset_fetch(&singleRelations, hasManyToManySingle, entityName, 0 TSRMLS_CC)) {
		ZEPHIR_INIT_BNVAR(singleRelations);
		array_init(singleRelations);
	}
	zephir_array_append(&singleRelations, relation, PH_SEPARATE);
	zephir_update_property_array(this_ptr, SL("_hasManyToManySingle"), entityName, singleRelations TSRMLS_CC);
	RETURN_CCTOR(relation);

}

/**
 * Checks whether a model has a belongsTo relation with another model
 *
 * @param 	string modelName
 * @param 	string modelRelation
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsBelongsTo) {

	zval *modelName_param = NULL, *modelRelation_param = NULL, *initialized, *entityName, *keyRelation, *belongsTo, *_0;
	zval *modelName = NULL, *modelRelation = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &modelRelation_param);

		if (Z_TYPE_P(modelName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		modelName = modelName_param;
		if (Z_TYPE_P(modelRelation_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelRelation' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		modelRelation = modelRelation_param;


	initialized = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(entityName);
	zephir_fast_strtolower(entityName, modelName);
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, modelRelation);
	ZEPHIR_INIT_VAR(keyRelation);
	ZEPHIR_CONCAT_VSV(keyRelation, entityName, "$", _0);
	if (!(zephir_array_isset(initialized, entityName))) {
		zephir_call_method_p1_noret(this_ptr, "load", modelName);
	}
	belongsTo = zephir_fetch_nproperty_this(this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(belongsTo, keyRelation));

}

/**
 * Checks whether a model has a hasMany relation with another model
 *
 * @param 	string modelName
 * @param 	string modelRelation
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasMany) {

	zval *modelName_param = NULL, *modelRelation_param = NULL, *initialized, *entityName, *keyRelation, *hasMany, *_0;
	zval *modelName = NULL, *modelRelation = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &modelRelation_param);

		if (Z_TYPE_P(modelName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		modelName = modelName_param;
		if (Z_TYPE_P(modelRelation_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelRelation' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		modelRelation = modelRelation_param;


	initialized = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(entityName);
	zephir_fast_strtolower(entityName, modelName);
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, modelRelation);
	ZEPHIR_INIT_VAR(keyRelation);
	ZEPHIR_CONCAT_VSV(keyRelation, entityName, "$", _0);
	if (!(zephir_array_isset(initialized, entityName))) {
		zephir_call_method_p1_noret(this_ptr, "load", modelName);
	}
	hasMany = zephir_fetch_nproperty_this(this_ptr, SL("_hasMany"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(hasMany, keyRelation));

}

/**
 * Checks whether a model has a hasOne relation with another model
 *
 * @param 	string modelName
 * @param 	string modelRelation
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasOne) {

	zval *modelName_param = NULL, *modelRelation_param = NULL, *initialized, *entityName, *keyRelation, *hasOne, *_0;
	zval *modelName = NULL, *modelRelation = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &modelRelation_param);

		if (Z_TYPE_P(modelName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		modelName = modelName_param;
		if (Z_TYPE_P(modelRelation_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelRelation' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		modelRelation = modelRelation_param;


	initialized = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(entityName);
	zephir_fast_strtolower(entityName, modelName);
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, modelRelation);
	ZEPHIR_INIT_VAR(keyRelation);
	ZEPHIR_CONCAT_VSV(keyRelation, entityName, "$", _0);
	if (!(zephir_array_isset(initialized, entityName))) {
		zephir_call_method_p1_noret(this_ptr, "load", modelName);
	}
	hasOne = zephir_fetch_nproperty_this(this_ptr, SL("_hasOne"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(hasOne, keyRelation));

}

/**
 * Checks whether a model has a hasManyToMany relation with another model
 *
 * @param 	string modelName
 * @param 	string modelRelation
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasManyToMany) {

	zval *modelName_param = NULL, *modelRelation_param = NULL, *initialized, *entityName, *keyRelation, *hasManyToMany, *_0;
	zval *modelName = NULL, *modelRelation = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &modelRelation_param);

		if (Z_TYPE_P(modelName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		modelName = modelName_param;
		if (Z_TYPE_P(modelRelation_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelRelation' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		modelRelation = modelRelation_param;


	initialized = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(entityName);
	zephir_fast_strtolower(entityName, modelName);
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, modelRelation);
	ZEPHIR_INIT_VAR(keyRelation);
	ZEPHIR_CONCAT_VSV(keyRelation, entityName, "$", _0);
	if (!(zephir_array_isset(initialized, entityName))) {
		zephir_call_method_p1_noret(this_ptr, "load", modelName);
	}
	hasManyToMany = zephir_fetch_nproperty_this(this_ptr, SL("_hasManyToMany"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(hasManyToMany, keyRelation));

}

/**
 * Returns a relation by its alias
 *
 * @param string modelName
 * @param string alias
 * @return Phalcon\Mvc\Model\Relation|false
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationByAlias) {

	zval *modelName_param = NULL, *alias_param = NULL, *aliases, *relation, *_0, *_1;
	zval *modelName = NULL, *alias = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &alias_param);

		if (Z_TYPE_P(modelName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		modelName = modelName_param;
		if (Z_TYPE_P(alias_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		alias = alias_param;


	aliases = zephir_fetch_nproperty_this(this_ptr, SL("_aliases"), PH_NOISY_CC);
	if ((Z_TYPE_P(aliases) == IS_ARRAY)) {
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
 * @param Phalcon\Mvc\Model\RelationInterface relation
 * @param string $method
 * @param Phalcon\Mvc\ModelInterface record
 * @param array parameters
 * @return Phalcon\Mvc\Model\Resultset\Simple|Phalcon\Mvc\Model\Resultset\Simple|false
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationRecords) {

	zend_function *_10 = NULL;
	HashTable *_6;
	HashPosition _5;
	zend_bool reusable;
	zval *method = NULL;
	zval *relation, *method_param = NULL, *record, *parameters = NULL, *preConditions = NULL, *placeholders = NULL, *referencedModel, *intermediateModel, *intermediateFields = NULL, *joinConditions, *query, *fields = NULL, *builder, *conditions = NULL, *refPosition = NULL, *field = NULL, *referencedFields, *findParams, *findArguments = NULL, *retrieveMethod = NULL, *uniqueKey, *records = NULL, *arguments, *_0, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, **_7, *_8, *_9 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &relation, &method_param, &record, &parameters);

		if (Z_TYPE_P(method_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		method = method_param;
	if (!parameters) {
		ZEPHIR_CPY_WRT(parameters, ZEPHIR_GLOBAL(global_null));
	}
	ZEPHIR_SEPARATE_PARAM(parameters);


	ZEPHIR_INIT_VAR(preConditions);
	ZVAL_NULL(preConditions);
	if ((Z_TYPE_P(parameters) == IS_ARRAY)) {
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
		if ((Z_TYPE_P(parameters) == IS_STRING)) {
			ZEPHIR_CPY_WRT(preConditions, parameters);
		}
	}
	if ((Z_TYPE_P(parameters) == IS_ARRAY)) {
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
	ZEPHIR_INIT_VAR(referencedModel);
	zephir_call_method(referencedModel, relation, "getreferencedmodel");
	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, relation, "isthrough");
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(conditions);
		array_init(conditions);
		ZEPHIR_INIT_VAR(intermediateModel);
		zephir_call_method(intermediateModel, relation, "getintermediatemodel");
		ZEPHIR_INIT_VAR(intermediateFields);
		zephir_call_method(intermediateFields, relation, "getintermediatefields");
		ZEPHIR_INIT_VAR(fields);
		zephir_call_method(fields, relation, "getfields");
		if ((Z_TYPE_P(fields) == IS_ARRAY)) {
			ZEPHIR_INIT_VAR(_1);
			ZEPHIR_CONCAT_SVSVS(_1, "[", intermediateModel, "].[", intermediateFields, "] = ?0");
			zephir_array_append(&conditions, _1, PH_SEPARATE);
			ZEPHIR_INIT_VAR(_2);
			zephir_call_method_p1(_2, record, "readattribute", fields);
			zephir_array_append(&placeholders, _2, PH_SEPARATE);
		} else {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Not supported");
			return;
		}
		ZEPHIR_INIT_VAR(joinConditions);
		array_init(joinConditions);
		ZEPHIR_INIT_NVAR(intermediateFields);
		zephir_call_method(intermediateFields, relation, "getintermediatereferencedfields");
		if ((Z_TYPE_P(intermediateFields) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_2);
			zephir_call_method(_2, relation, "getreferencedfields");
			ZEPHIR_INIT_LNVAR(_1);
			ZEPHIR_CONCAT_SVSVSVSVS(_1, "[", intermediateModel, "].[", intermediateFields, "] = [", referencedModel, "].[", _2, "]");
			zephir_array_append(&joinConditions, _1, PH_SEPARATE);
		} else {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Not supported");
			return;
		}
		if (!((0 == 0))) {
			zephir_array_append(&conditions, preConditions, PH_SEPARATE);
		}
		ZEPHIR_INIT_VAR(builder);
		zephir_call_method_p1(builder, this_ptr, "createbuilder", parameters);
		zephir_call_method_p1_noret(builder, "from", referencedModel);
		ZEPHIR_INIT_NVAR(_2);
		zephir_fast_join_str(_2, SL(" AND "), joinConditions TSRMLS_CC);
		zephir_call_method_p2_noret(builder, "innerjoin", intermediateModel, _2);
		ZEPHIR_INIT_VAR(_3);
		zephir_fast_join_str(_3, SL(" AND "), conditions TSRMLS_CC);
		zephir_call_method_p2_noret(builder, "andwhere", _3, placeholders);
		ZEPHIR_INIT_VAR(query);
		zephir_call_method(query, builder, "getquery");
		zephir_call_method(return_value, query, "execute");
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(conditions);
	if ((Z_TYPE_P(preConditions) != IS_NULL)) {
		array_init(conditions);
		zephir_array_fast_append(conditions, preConditions);
	} else {
		array_init(conditions);
	}
	ZEPHIR_INIT_NVAR(fields);
	zephir_call_method(fields, relation, "getfields");
	if ((Z_TYPE_P(fields) != IS_ARRAY)) {
		ZEPHIR_INIT_NVAR(_3);
		zephir_call_method(_3, relation, "getreferencedfields");
		ZEPHIR_INIT_LNVAR(_1);
		ZEPHIR_CONCAT_SVS(_1, "[", _3, "] = ?0");
		zephir_array_append(&conditions, _1, PH_SEPARATE);
		ZEPHIR_INIT_VAR(_4);
		zephir_call_method_p1(_4, record, "readattribute", fields);
		zephir_array_append(&placeholders, _4, PH_SEPARATE);
	} else {
		ZEPHIR_INIT_VAR(referencedFields);
		zephir_call_method(referencedFields, relation, "getreferencedfields");
		ZEPHIR_INIT_NVAR(_3);
		zephir_call_method(_3, relation, "getreferencedfields");
		zephir_is_iterable(_3, &_6, &_5, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
			; zend_hash_move_forward_ex(_6, &_5)
		) {
			ZEPHIR_GET_HMKEY(refPosition, _6, _5);
			ZEPHIR_GET_HVALUE(field, _7);
			zephir_array_fetch(&_8, referencedFields, refPosition, PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_9);
			ZEPHIR_CONCAT_SVSV(_9, "[", _8, "] = ?", refPosition);
			zephir_array_append(&conditions, _9, PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_4);
			zephir_call_method_p1_cache(_4, record, "readattribute", &_10, field);
			zephir_array_append(&placeholders, _4, PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_VAR(findParams);
	array_init(findParams);
	ZEPHIR_INIT_NVAR(_2);
	zephir_fast_join_str(_2, SL(" AND "), conditions TSRMLS_CC);
	zephir_array_fast_append(findParams, _2);
	zephir_array_update_string(&findParams, SL("bind"), &placeholders, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	zephir_call_method(_2, record, "getdi");
	zephir_array_update_string(&findParams, SL("di"), &_2, PH_COPY | PH_SEPARATE);
	if ((Z_TYPE_P(parameters) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(findArguments);
		array_init(findArguments);
		zephir_array_fast_append(findArguments, findParams);
		zephir_array_fast_append(findArguments, parameters);
	} else {
		ZEPHIR_CPY_WRT(findArguments, findParams);
	}
	if (ZEPHIR_IS_STRING(method, "")) {
		ZEPHIR_INIT_NVAR(_2);
		zephir_call_method(_2, relation, "gettype");
		do {
			if (ZEPHIR_IS_LONG(_2, 0) || ZEPHIR_IS_LONG(_2, 1)) {
				ZEPHIR_INIT_VAR(retrieveMethod);
				ZVAL_STRING(retrieveMethod, "findFirst", 1);
				break;
			}
			if (ZEPHIR_IS_LONG(_2, 2)) {
				ZEPHIR_INIT_NVAR(retrieveMethod);
				ZVAL_STRING(retrieveMethod, "find", 1);
				break;
			}
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Unkown relation type");
			return;
		} while(0);

	} else {
		ZEPHIR_CPY_WRT(retrieveMethod, method);
	}
	ZEPHIR_INIT_VAR(arguments);
	array_init(arguments);
	zephir_array_fast_append(arguments, findArguments);
	ZEPHIR_INIT_NVAR(_2);
	zephir_call_method(_2, relation, "isreusable");
	reusable = (zephir_get_boolval(_2)) ? 1 : 0;
	if (reusable) {
		ZEPHIR_INIT_VAR(uniqueKey);
		zephir_call_func_p2(uniqueKey, "unique_key", referencedModel, arguments);
		ZEPHIR_INIT_VAR(records);
		zephir_call_method_p2(records, this_ptr, "getreusablerecords", referencedModel, uniqueKey);
		if (((Z_TYPE_P(records) == IS_ARRAY) || (Z_TYPE_P(records) == IS_OBJECT))) {
			RETURN_CCTOR(records);
		}
	}
	ZEPHIR_INIT_NVAR(_2);
	array_init(_2);
	ZEPHIR_INIT_NVAR(_3);
	zephir_call_method_p1(_3, this_ptr, "load", referencedModel);
	zephir_array_fast_append(_2, _3);
	zephir_array_fast_append(_2, retrieveMethod);
	ZEPHIR_INIT_NVAR(records);
	zephir_call_func_p2(records, "call_user_func_array", _2, arguments);
	if (reusable) {
		zephir_call_method_p3_noret(this_ptr, "setreusablerecords", referencedModel, uniqueKey, records);
	}
	RETURN_CCTOR(records);

}

/**
 * Returns a reusable object from the internal list
 *
 * @param string modelName
 * @param string key
 * @return object
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getReusableRecords) {

	zval *modelName_param = NULL, *key_param = NULL, *reusable, *records;
	zval *modelName = NULL, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &key_param);

		if (Z_TYPE_P(modelName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		modelName = modelName_param;
		if (Z_TYPE_P(key_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		key = key_param;


	reusable = zephir_fetch_nproperty_this(this_ptr, SL("_reusable"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&records, reusable, key, 1 TSRMLS_CC)) {
		RETURN_CTOR(records);
	}
	RETURN_MM_NULL();

}

/**
 * Stores a reusable record in the internal list
 *
 * @param string modelName
 * @param string key
 * @param mixed records
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setReusableRecords) {

	zval *modelName_param = NULL, *key_param = NULL, *records;
	zval *modelName = NULL, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &modelName_param, &key_param, &records);

		if (Z_TYPE_P(modelName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		modelName = modelName_param;
		if (Z_TYPE_P(key_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		key = key_param;


	zephir_update_property_array(this_ptr, SL("_reusable"), key, records TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Clears the internal reusable list
 *
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, clearReusableObjects) {


	zephir_update_property_this(this_ptr, SL("_reusable"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);

}

/**
 * Gets belongsTo related records from a model
 *
 * @param string method
 * @param string modelName
 * @param string modelRelation
 * @param Phalcon\Mvc\ModelInterface record
 * @param array parameters
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getBelongsToRecords) {

	zval *method_param = NULL, *modelName_param = NULL, *modelRelation, *record, *parameters = NULL, *belongsTo, *keyRelation, *relations, *_0, *_1, *_2;
	zval *method = NULL, *modelName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &method_param, &modelName_param, &modelRelation, &record, &parameters);

		if (Z_TYPE_P(method_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		method = method_param;
		if (Z_TYPE_P(modelName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		modelName = modelName_param;
	if (!parameters) {
		ZEPHIR_CPY_WRT(parameters, ZEPHIR_GLOBAL(global_null));
	}


	belongsTo = zephir_fetch_nproperty_this(this_ptr, SL("_hasMany"), PH_NOISY_CC);
	if ((Z_TYPE_P(belongsTo) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_fast_strtolower(_0, modelName);
		ZEPHIR_INIT_VAR(_1);
		zephir_fast_strtolower(_1, modelRelation);
		ZEPHIR_INIT_VAR(keyRelation);
		ZEPHIR_CONCAT_VSV(keyRelation, _0, "$", _1);
		if (!(zephir_array_isset(belongsTo, keyRelation))) {
			RETURN_MM_BOOL(0);
		}
		zephir_array_fetch(&relations, belongsTo, keyRelation, PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_array_fetch_long(&_2, relations, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_call_method_p4(return_value, this_ptr, "getrelationrecords", _2, method, record, parameters);
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Gets hasMany related records from a model
 *
 * @param string method
 * @param string modelName
 * @param string modelRelation
 * @param Phalcon\Mvc\ModelInterface record
 * @param array parameters
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasManyRecords) {

	zval *method_param = NULL, *modelName_param = NULL, *modelRelation, *record, *parameters = NULL, *hasMany, *keyRelation, *relations, *_0, *_1, *_2;
	zval *method = NULL, *modelName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &method_param, &modelName_param, &modelRelation, &record, &parameters);

		if (Z_TYPE_P(method_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		method = method_param;
		if (Z_TYPE_P(modelName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		modelName = modelName_param;
	if (!parameters) {
		ZEPHIR_CPY_WRT(parameters, ZEPHIR_GLOBAL(global_null));
	}


	hasMany = zephir_fetch_nproperty_this(this_ptr, SL("_hasMany"), PH_NOISY_CC);
	if ((Z_TYPE_P(hasMany) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_fast_strtolower(_0, modelName);
		ZEPHIR_INIT_VAR(_1);
		zephir_fast_strtolower(_1, modelRelation);
		ZEPHIR_INIT_VAR(keyRelation);
		ZEPHIR_CONCAT_VSV(keyRelation, _0, "$", _1);
		if (!(zephir_array_isset(hasMany, keyRelation))) {
			RETURN_MM_BOOL(0);
		}
		zephir_array_fetch(&relations, hasMany, keyRelation, PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_array_fetch_long(&_2, relations, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_call_method_p4(return_value, this_ptr, "getrelationrecords", _2, method, record, parameters);
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Gets belongsTo related records from a model
 *
 * @param string method
 * @param string modelName
 * @param string modelRelation
 * @param Phalcon\Mvc\ModelInterface record
 * @param array parameters
 * @return Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOneRecords) {

	zval *method_param = NULL, *modelName_param = NULL, *modelRelation, *record, *parameters = NULL, *hasOne, *keyRelation, *relations, *_0, *_1, *_2;
	zval *method = NULL, *modelName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &method_param, &modelName_param, &modelRelation, &record, &parameters);

		if (Z_TYPE_P(method_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		method = method_param;
		if (Z_TYPE_P(modelName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		modelName = modelName_param;
	if (!parameters) {
		ZEPHIR_CPY_WRT(parameters, ZEPHIR_GLOBAL(global_null));
	}


	hasOne = zephir_fetch_nproperty_this(this_ptr, SL("_hasOne"), PH_NOISY_CC);
	if ((Z_TYPE_P(hasOne) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_fast_strtolower(_0, modelName);
		ZEPHIR_INIT_VAR(_1);
		zephir_fast_strtolower(_1, modelRelation);
		ZEPHIR_INIT_VAR(keyRelation);
		ZEPHIR_CONCAT_VSV(keyRelation, _0, "$", _1);
		if (!(zephir_array_isset(hasOne, keyRelation))) {
			RETURN_MM_BOOL(0);
		}
		zephir_array_fetch(&relations, hasOne, keyRelation, PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_array_fetch_long(&_2, relations, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_call_method_p4(return_value, this_ptr, "getrelationrecords", _2, method, record, parameters);
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
 *
 * @param  Phalcon\Mvc\ModelInterface model
 * @return Phalcon\Mvc\Model\RelationInterface[]
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getBelongsTo) {

	zval *model, *belongsToSingle, *relations, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	belongsToSingle = zephir_fetch_nproperty_this(this_ptr, SL("_belongsToSingle"), PH_NOISY_CC);
	if ((Z_TYPE_P(belongsToSingle) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "get_class_lower", model);
		if (zephir_array_isset_fetch(&relations, belongsToSingle, _0, 1 TSRMLS_CC)) {
			RETURN_CTOR(relations);
		}
	}
	array_init(return_value);
	RETURN_MM();

}

/**
 * Gets hasMany relations defined on a model
 *
 * @param  Phalcon\Mvc\ModelInterface model
 * @return Phalcon\Mvc\Model\RelationInterface[]
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasMany) {

	zval *model, *hasManySingle, *relations, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	hasManySingle = zephir_fetch_nproperty_this(this_ptr, SL("_hasManySingle"), PH_NOISY_CC);
	if ((Z_TYPE_P(hasManySingle) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "get_class_lower", model);
		if (zephir_array_isset_fetch(&relations, hasManySingle, _0, 1 TSRMLS_CC)) {
			RETURN_CTOR(relations);
		}
	}
	array_init(return_value);
	RETURN_MM();

}

/**
 * Gets hasOne relations defined on a model
 *
 * @param  Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOne) {

	zval *model, *hasOneSingle, *relations, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	hasOneSingle = zephir_fetch_nproperty_this(this_ptr, SL("_hasOneSingle"), PH_NOISY_CC);
	if ((Z_TYPE_P(hasOneSingle) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "get_class_lower", model);
		if (zephir_array_isset_fetch(&relations, hasOneSingle, _0, 1 TSRMLS_CC)) {
			RETURN_CTOR(relations);
		}
	}
	array_init(return_value);
	RETURN_MM();

}

/**
 * Gets hasManyToMany relations defined on a model
 *
 * @param  Phalcon\Mvc\ModelInterface model
 * @return Phalcon\Mvc\Model\RelationInterface[]
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasManyToMany) {

	zval *model, *hasManyToManySingle, *relations, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	hasManyToManySingle = zephir_fetch_nproperty_this(this_ptr, SL("_hasManyToManySingle"), PH_NOISY_CC);
	if ((Z_TYPE_P(hasManyToManySingle) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "get_class_lower", model);
		if (zephir_array_isset_fetch(&relations, hasManyToManySingle, _0, 1 TSRMLS_CC)) {
			RETURN_CTOR(relations);
		}
	}
	array_init(return_value);
	RETURN_MM();

}

/**
 * Gets hasOne relations defined on a model
 *
 * @param  Phalcon\Mvc\ModelInterface model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOneAndHasMany) {

	zval *model, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_INIT_VAR(_0);
	zephir_call_method_p1(_0, this_ptr, "gethasone", model);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_method_p1(_1, this_ptr, "gethasmany", model);
	zephir_fast_array_merge(return_value, &(_0), &(_1) TSRMLS_CC);
	RETURN_MM();

}

/**
 * Query all the relationships defined on a model
 *
 * @param string $modelName
 * @return Phalcon\Mvc\Model\RelationInterface[]
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelations) {

	HashTable *_1, *_4, *_7;
	HashPosition _0, _3, _6;
	zval *modelName_param = NULL, *entityName, *allRelations, *relations = NULL, *belongsTo, *relation = NULL, *hasOne, *hasMany, **_2, **_5, **_8;
	zval *modelName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modelName_param);

		if (Z_TYPE_P(modelName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		modelName = modelName_param;


	ZEPHIR_INIT_VAR(entityName);
	zephir_fast_strtolower(entityName, modelName);
	ZEPHIR_INIT_VAR(allRelations);
	array_init(allRelations);
	belongsTo = zephir_fetch_nproperty_this(this_ptr, SL("_hasManySingle"), PH_NOISY_CC);
	if ((Z_TYPE_P(belongsTo) == IS_ARRAY)) {
		ZEPHIR_OBS_VAR(relations);
		if (zephir_array_isset_fetch(&relations, belongsTo, entityName, 0 TSRMLS_CC)) {
			zephir_is_iterable(relations, &_1, &_0, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
				; zend_hash_move_forward_ex(_1, &_0)
			) {
				ZEPHIR_GET_HVALUE(relation, _2);
				zephir_array_append(&allRelations, relation, PH_SEPARATE);
			}
		}
	}
	hasMany = zephir_fetch_nproperty_this(this_ptr, SL("_hasManySingle"), PH_NOISY_CC);
	if ((Z_TYPE_P(hasMany) == IS_ARRAY)) {
		ZEPHIR_OBS_NVAR(relations);
		if (zephir_array_isset_fetch(&relations, hasMany, entityName, 0 TSRMLS_CC)) {
			zephir_is_iterable(relations, &_4, &_3, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
				; zend_hash_move_forward_ex(_4, &_3)
			) {
				ZEPHIR_GET_HVALUE(relation, _5);
				zephir_array_append(&allRelations, relation, PH_SEPARATE);
			}
		}
	}
	hasOne = zephir_fetch_nproperty_this(this_ptr, SL("_hasOneSingle"), PH_NOISY_CC);
	if ((Z_TYPE_P(hasOne) == IS_ARRAY)) {
		ZEPHIR_OBS_NVAR(relations);
		if (zephir_array_isset_fetch(&relations, hasOne, entityName, 0 TSRMLS_CC)) {
			zephir_is_iterable(relations, &_7, &_6, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
				; zend_hash_move_forward_ex(_7, &_6)
			) {
				ZEPHIR_GET_HVALUE(relation, _8);
				zephir_array_append(&allRelations, relation, PH_SEPARATE);
			}
		}
	}
	RETURN_CCTOR(allRelations);

}

/**
 * Query the first relationship defined between two models
 *
 * @param string first
 * @param string second
 * @return Phalcon\Mvc\Model\RelationInterface[]
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationsBetween) {

	zval *first_param = NULL, *second_param = NULL, *keyRelation, *belongsTo, *hasMany, *hasOne, *relations = NULL, *_0, *_1;
	zval *first = NULL, *second = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &first_param, &second_param);

		if (Z_TYPE_P(first_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'first' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		first = first_param;
		if (Z_TYPE_P(second_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'second' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		second = second_param;


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, first);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, second);
	ZEPHIR_INIT_VAR(keyRelation);
	ZEPHIR_CONCAT_VSV(keyRelation, _0, "$", _1);
	belongsTo = zephir_fetch_nproperty_this(this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	if ((Z_TYPE_P(belongsTo) == IS_ARRAY)) {
		ZEPHIR_OBS_VAR(relations);
		if (zephir_array_isset_fetch(&relations, belongsTo, keyRelation, 0 TSRMLS_CC)) {
			RETURN_CCTOR(relations);
		}
	}
	hasMany = zephir_fetch_nproperty_this(this_ptr, SL("_hasMany"), PH_NOISY_CC);
	if ((Z_TYPE_P(hasMany) == IS_ARRAY)) {
		ZEPHIR_OBS_NVAR(relations);
		if (zephir_array_isset_fetch(&relations, hasMany, keyRelation, 0 TSRMLS_CC)) {
			RETURN_CCTOR(relations);
		}
	}
	hasOne = zephir_fetch_nproperty_this(this_ptr, SL("_hasOne"), PH_NOISY_CC);
	if ((Z_TYPE_P(hasOne) == IS_ARRAY)) {
		ZEPHIR_OBS_NVAR(relations);
		if (zephir_array_isset_fetch(&relations, hasOne, keyRelation, 0 TSRMLS_CC)) {
			RETURN_CCTOR(relations);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Creates a Phalcon\Mvc\Model\Query without execute it
 *
 * @param string phql
 * @return Phalcon\Mvc\Model\QueryInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, createQuery) {

	zval *phql_param = NULL, *dependencyInjector, *query;
	zval *phql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &phql_param);

		if (Z_TYPE_P(phql_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'phql' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		phql = phql_param;


	dependencyInjector = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injection object is required to access ORM services");
		return;
	}
	ZEPHIR_INIT_VAR(query);
	object_init_ex(query, phalcon_mvc_model_query_ce);
	zephir_call_method_p1_noret(query, "setdi", dependencyInjector);
	zephir_update_property_this(this_ptr, SL("_lastQuery"), query TSRMLS_CC);
	RETURN_CCTOR(query);

}

/**
 * Creates a Phalcon\Mvc\Model\Query and execute it
 *
 * @param string phql
 * @param array placeholders
 * @return Phalcon\Mvc\Model\QueryInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, executeQuery) {

	zval *phql_param = NULL, *placeholders = NULL, *dependencyInjector = NULL, *query, *_0;
	zval *phql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &phql_param, &placeholders);

		if (Z_TYPE_P(phql_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'phql' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		phql = phql_param;
	if (!placeholders) {
		ZEPHIR_CPY_WRT(placeholders, ZEPHIR_GLOBAL(global_null));
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injection object is required to access ORM services");
		return;
	}
	ZEPHIR_INIT_VAR(query);
	object_init_ex(query, phalcon_mvc_model_query_ce);
	zephir_call_method_p1_noret(query, "setdi", dependencyInjector);
	zephir_update_property_this(this_ptr, SL("_lastQuery"), query TSRMLS_CC);
	zephir_call_method_p1(return_value, query, "execute", placeholders);
	RETURN_MM();

}

/**
 * Creates a Phalcon\Mvc\Model\Query\Builder
 *
 * @param string|array params
 * @return Phalcon\Mvc\Model\Query\BuilderInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, createBuilder) {

	zval *params = NULL, *dependencyInjector = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &params);

	if (!params) {
		ZEPHIR_CPY_WRT(params, ZEPHIR_GLOBAL(global_null));
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injection object is required to access ORM services");
		return;
	}
	object_init_ex(return_value, phalcon_mvc_model_query_builder_ce);
	RETURN_MM();

}

/**
 * Returns the lastest query created or executed in the models manager
 *
 * @return Phalcon\Mvc\Model\QueryInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getLastQuery) {


	RETURN_MEMBER(this_ptr, "_lastQuery");

}

/**
 * Registers shorter aliases for namespaces in PHQL statements
 *
 * @param string alias
 * @param string namespace
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
 *
 * @param string alias
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getNamespaceAlias) {

	zval *alias_param = NULL, *namespaceAliases, *namespaceName, *_0, *_1;
	zval *alias = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &alias_param);

		if (Z_TYPE_P(alias_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		alias = alias_param;


	namespaceAliases = zephir_fetch_nproperty_this(this_ptr, SL("_namespaceAliases"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&namespaceName, namespaceAliases, alias, 1 TSRMLS_CC)) {
		RETURN_CTOR(namespaceName);
	}
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, phalcon_mvc_model_exception_ce);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVS(_1, "Namespace alias '", alias, "' is not registered");
	zephir_call_method_p1_noret(_0, "__construct", _1);
	zephir_throw_exception(_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Returns all the registered namespace aliases
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getNamespaceAliases) {


	RETURN_MEMBER(this_ptr, "_namespaceAliases");

}

