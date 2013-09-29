
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
	ZEPHIR_OBS_VAR(initialized);
	zephir_read_property_this(&initialized, this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (zephir_array_isset(initialized, className)) {
		RETURN_MM_BOOL(0);
	}
	zephir_update_property_array(this_ptr, SL("_initialized"), className, model TSRMLS_CC);
	if ((zephir_method_exists_str(model, SS("initialize") TSRMLS_CC) == SUCCESS)) {
		zephir_call_method_noret(model, "initialize");
	}
	zephir_update_property_this(this_ptr, SL("_lastInitialized"), model TSRMLS_CC);
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
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

	zval *modelName, *initialized, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modelName);



	ZEPHIR_OBS_VAR(initialized);
	zephir_read_property_this(&initialized, this_ptr, SL("_initialized"), PH_NOISY_CC);
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

	zend_bool newInstance;
	zval *modelName_param = NULL, *newInstance_param = NULL, *initialized, *model, *_0, *_1, *_2, *_3, *_4;
	zval *modelName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &modelName_param, &newInstance_param);

		zephir_get_strval(modelName, modelName_param);
	if (!newInstance_param) {
		newInstance = 0;
	} else {
		newInstance = zephir_get_boolval(newInstance_param);
	}


	ZEPHIR_OBS_VAR(initialized);
	zephir_read_property_this(&initialized, this_ptr, SL("_initialized"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(model);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "strtolower", modelName);
	if (zephir_array_isset_fetch(&model, initialized, _0 TSRMLS_CC)) {
		if (newInstance) {
			RETURN_MM_NULL();
		}
		RETURN_CCTOR(model);
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func_p1(_1, "class_exists", modelName);
	if (zephir_is_true(_1)) {
	}
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, phalcon_mvc_model_exception_ce);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SV(_3, "Model '", modelName);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VS(_4, _3, "' could not be loaded");
	zephir_call_method_p1_noret(_2, "__construct", _4);
	zephir_throw_exception(_2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

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
	ZEPHIR_OBS_VAR(sources);
	zephir_read_property_this(&sources, this_ptr, SL("_sources"), PH_NOISY_CC);
	if ((Z_TYPE_P(sources) == IS_ARRAY)) {
		ZEPHIR_OBS_VAR(source);
		if (zephir_array_isset_fetch(&source, sources, entityName TSRMLS_CC)) {
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



	ZEPHIR_OBS_VAR(schemas);
	zephir_read_property_this(&schemas, this_ptr, SL("_schemas"), PH_NOISY_CC);
	if ((Z_TYPE_P(schemas) == IS_ARRAY)) {
		ZEPHIR_OBS_VAR(schema);
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "get_class_lower", model);
		if (zephir_array_isset_fetch(&schema, schemas, _0 TSRMLS_CC)) {
			RETURN_CCTOR(schema);
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

	zval *model, *connectionService, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &connectionService);



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



	ZEPHIR_OBS_VAR(connectionServices);
	zephir_read_property_this(&connectionServices, this_ptr, SL("_readConnectionServices"), PH_NOISY_CC);
	if ((Z_TYPE_P(connectionServices) == IS_ARRAY)) {
		ZEPHIR_OBS_VAR(service);
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "get_class_lower", model);
	}
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
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



	ZEPHIR_OBS_VAR(connectionServices);
	zephir_read_property_this(&connectionServices, this_ptr, SL("_writeConnectionServices"), PH_NOISY_CC);
	if ((Z_TYPE_P(connectionServices) == IS_ARRAY)) {
		ZEPHIR_OBS_VAR(service);
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "get_class_lower", model);
	}
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
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



	ZEPHIR_OBS_VAR(connectionServices);
	zephir_read_property_this(&connectionServices, this_ptr, SL("_readConnectionServices"), PH_NOISY_CC);
	if ((Z_TYPE_P(connectionServices) == IS_ARRAY)) {
		ZEPHIR_OBS_VAR(connection);
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "get_class_lower", model);
		if (zephir_array_isset_fetch(&connection, connectionServices, _0 TSRMLS_CC)) {
			RETURN_CCTOR(connection);
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



	ZEPHIR_OBS_VAR(connectionServices);
	zephir_read_property_this(&connectionServices, this_ptr, SL("_writeConnectionServices"), PH_NOISY_CC);
	if ((Z_TYPE_P(connectionServices) == IS_ARRAY)) {
		ZEPHIR_OBS_VAR(connection);
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "get_class_lower", model);
		if (zephir_array_isset_fetch(&connection, connectionServices, _0 TSRMLS_CC)) {
			RETURN_CCTOR(connection);
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


	ZEPHIR_OBS_VAR(aliases);
	zephir_read_property_this(&aliases, this_ptr, SL("_aliases"), PH_NOISY_CC);
	if ((Z_TYPE_P(aliases) == IS_ARRAY)) {
		ZEPHIR_OBS_VAR(relation);
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_VS(_0, modelName, "$");
		ZEPHIR_INIT_VAR(_1);
		concat_function(_1, _0, alias TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2);
		zephir_call_func_p1(_2, "strtolower", _1);
		if (zephir_array_isset_fetch(&relation, aliases, _2 TSRMLS_CC)) {
			RETURN_CCTOR(relation);
		}
	}
	RETURN_MM_BOOL(0);

}

