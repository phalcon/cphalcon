
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"


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
			ZEPHIR_MM_RESTORE();
			RETURN_ZVAL(eventsManager, 1, 0);
		}
	}
	RETURN_MM_NULL();

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

		zephir_get_strval(modelName, modelName_param);


	initialized = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "strtolower", modelName);
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
	zval *modelName_param = NULL, *newInstance_param = NULL, *initialized, *model, *_0, *_1, *_3, *_4, *_5;
	zval *modelName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &modelName_param, &newInstance_param);

		zephir_get_strval(modelName, modelName_param);
	if (!newInstance_param) {
		newInstance = 0;
	} else {
		newInstance = zephir_get_boolval(newInstance_param);
	}


	initialized = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "strtolower", modelName);
	if (zephir_array_isset_fetch(&model, initialized, _0, 1 TSRMLS_CC)) {
		if (newInstance) {
			RETURN_MM_NULL();
		}
		ZEPHIR_MM_RESTORE();
		RETURN_ZVAL(model, 1, 0);
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
	ZEPHIR_CONCAT_SV(_4, "Model '", modelName);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_VS(_5, _4, "' could not be loaded");
	zephir_call_method_p1_noret(_3, "__construct", _5);
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

		zephir_get_strval(source, source_param);


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
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setModelSchema) {

	zval *schema = NULL;
	zval *model, *schema_param = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &schema_param);

		zephir_get_strval(schema, schema_param);


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
			ZEPHIR_MM_RESTORE();
			RETURN_ZVAL(schema, 1, 0);
		}
	}
	RETURN_MM_NULL();

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

		zephir_get_strval(connectionService, connectionService_param);


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

		zephir_get_strval(connectionService, connectionService_param);


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

		zephir_get_strval(connectionService, connectionService_param);


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
			ZEPHIR_MM_RESTORE();
			RETURN_ZVAL(connection, 1, 0);
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
			ZEPHIR_MM_RESTORE();
			RETURN_ZVAL(connection, 1, 0);
		}
	}
	RETURN_MM_STRING("db", 1);

}

/**
 * Returns a relation by its alias
 *
 * @param string modelName
 * @param string alias
 * @return Phalcon\Mvc\Model\Relation
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationByAlias) {

	zval *modelName_param = NULL, *alias_param = NULL, *aliases, *relation, *_0, *_1, *_2;
	zval *modelName = NULL, *alias = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &alias_param);

		zephir_get_strval(modelName, modelName_param);
		zephir_get_strval(alias, alias_param);


	aliases = zephir_fetch_nproperty_this(this_ptr, SL("_aliases"), PH_NOISY_CC);
	if ((Z_TYPE_P(aliases) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_VS(_0, modelName, "$");
		ZEPHIR_INIT_VAR(_1);
		concat_function(_1, _0, alias TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2);
		zephir_call_func_p1(_2, "strtolower", _1);
		if (zephir_array_isset_fetch(&relation, aliases, _2, 1 TSRMLS_CC)) {
			ZEPHIR_MM_RESTORE();
			RETURN_ZVAL(relation, 1, 0);
		}
	}
	RETURN_MM_BOOL(0);

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

		zephir_get_strval(eventName, eventName_param);


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

		zephir_get_strval(eventName, eventName_param);


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
	RETURN_MM_NULL();

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
			ZEPHIR_MM_RESTORE();
			RETURN_ZVAL(isKeeping, 1, 0);
		}
	}
	RETURN_MM_BOOL(0);

}

