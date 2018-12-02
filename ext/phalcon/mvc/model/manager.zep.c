
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
#include "phalcon/mvc/model/orm.h"


/**
 * Phalcon\Mvc\Model\Manager
 *
 * This components controls the initialization of models, keeping record of relations
 * between the different models of the application.
 *
 * A ModelsManager is injected to a model via a Dependency Injector/Services Container such as Phalcon\Di.
 *
 * <code>
 * use Phalcon\Di;
 * use Phalcon\Mvc\Model\Manager as ModelsManager;
 *
 * $di = new Di();
 *
 * $di->set(
 *     "modelsManager",
 *     function() {
 *         return new ModelsManager();
 *     }
 * );
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

	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_modelVisibility"), ZEND_ACC_PROTECTED TSRMLS_CC);

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

	zend_declare_property_string(phalcon_mvc_model_manager_ce, SL("_prefix"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

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

	phalcon_mvc_model_manager_ce->create_object = zephir_init_properties_Phalcon_Mvc_Model_Manager;

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



	zephir_update_property_this(getThis(), SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getDI) {

	

	RETURN_MEMBER(getThis(), "_dependencyInjector");

}

/**
 * Sets a global events manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setEventsManager) {

	zval *eventsManager;

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_this(getThis(), SL("_eventsManager"), eventsManager TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getEventsManager) {

	

	RETURN_MEMBER(getThis(), "_eventsManager");

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

	zval *model, *eventsManager = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_customEventsManager"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_get_class(_1, model, 1 TSRMLS_CC);
	if (!(zephir_array_isset_fetch(&eventsManager, _0, _1, 1 TSRMLS_CC))) {
		RETURN_MM_BOOL(0);
	}
	RETURN_CTOR(eventsManager);

}

/**
 * Initializes a model in the model manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, initialize) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, *className = NULL, *eventsManager = NULL, *_0, *_1, *_2$$5;

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
	zephir_update_property_this(getThis(), SL("_lastInitialized"), model TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _1);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_2$$5);
		ZVAL_STRING(_2$$5, "modelsManager:afterInitialize", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _2$$5, this_ptr, model);
		zephir_check_temp_parameter(_2$$5);
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

	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
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

	

	RETURN_MEMBER(getThis(), "_lastInitialized");

}

/**
 * Loads a model throwing an exception if it doesn't exist
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, load) {

	zend_class_entry *_9;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool newInstance;
	zval *modelName_param = NULL, *newInstance_param = NULL, *model = NULL, *colonPos = NULL, *namespaceName = NULL, *namespaceAlias = NULL, *className = NULL, _0, *_8 = NULL, *_10, *_11, _1$$3, _2$$3, *_3$$3, *_4$$4, *_6$$5, *_7$$5;
	zval *modelName = NULL, *_5$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &modelName_param, &newInstance_param);

	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
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


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, ":", 0);
	ZEPHIR_INIT_VAR(colonPos);
	zephir_fast_strpos(colonPos, modelName, &_0, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(colonPos)) {
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_LONG(&_1$$3, (zephir_get_numberval(colonPos) + 1));
		ZEPHIR_INIT_VAR(className);
		zephir_substr(className, modelName, zephir_get_intval(&_1$$3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_LONG(&_2$$3, 0);
		ZEPHIR_INIT_VAR(namespaceAlias);
		zephir_substr(namespaceAlias, modelName, 0 , zephir_get_intval(colonPos), 0);
		ZEPHIR_CALL_METHOD(&namespaceName, this_ptr, "getnamespacealias", NULL, 0, namespaceAlias);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_VSV(_3$$3, namespaceName, "\\", className);
		zephir_get_strval(modelName, _3$$3);
	}
	if (!(zephir_class_exists(modelName, 1 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_4$$4);
		object_init_ex(_4$$4, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(_5$$4);
		ZEPHIR_CONCAT_SVS(_5$$4, "Model '", modelName, "' could not be loaded");
		ZEPHIR_CALL_METHOD(NULL, _4$$4, "__construct", NULL, 9, _5$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4$$4, "phalcon/mvc/model/manager.zep", 298 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(newInstance)) {
		ZEPHIR_OBS_VAR(model);
		_6$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_7$$5);
		zephir_fast_strtolower(_7$$5, modelName);
		if (zephir_array_isset_fetch(&model, _6$$5, _7$$5, 0 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, model, "reset", NULL, 0);
			zephir_check_call_status();
			RETURN_CCTOR(model);
		}
	}
	zephir_fetch_safe_class(_8, modelName);
		_9 = zend_fetch_class(Z_STRVAL_P(_8), Z_STRLEN_P(_8), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(return_value, _9);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_11);
		ZVAL_NULL(_11);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, _11, _10, this_ptr);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * Sets the prefix for all model sources.
 *
 * <code>
 * use Phalcon\Mvc\Model\Manager;
 *
 * $di->set("modelsManager", function () {
 *     $modelsManager = new Manager();
 *     $modelsManager->setModelPrefix("wp_");
 *
 *     return $modelsManager;
 * });
 *
 * $robots = new Robots();
 * echo $robots->getSource(); // wp_robots
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setModelPrefix) {

	zval *prefix_param = NULL;
	zval *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prefix_param);

	if (UNEXPECTED(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(prefix_param) == IS_STRING)) {
		zephir_get_strval(prefix, prefix_param);
	} else {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_EMPTY_STRING(prefix);
	}


	zephir_update_property_this(getThis(), SL("_prefix"), prefix TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the prefix for all model sources.
 *
 * <code>
 * use Phalcon\Mvc\Model\Manager;
 *
 * $di->set("modelsManager", function () {
 *     $modelsManager = new Manager();
 *     $modelsManager->setModelPrefix("wp_");
 *
 *     return $modelsManager;
 * });
 *
 * $robots = new Robots();
 * echo $robots->getSource(); // wp_robots
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getModelPrefix) {

	

	RETURN_MEMBER(getThis(), "_prefix");

}

/**
 * Sets the mapped source for a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setModelSource) {

	zval *source = NULL;
	zval *model, *source_param = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &source_param);

	if (UNEXPECTED(Z_TYPE_P(source_param) != IS_STRING && Z_TYPE_P(source_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'source' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(source_param) == IS_STRING)) {
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
 * Check whether a model property is declared as public.
 *
 * <code>
 * $isPublic = $manager->isVisibleModelProperty(
 *     new Robots(),
 *     "name"
 * );
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, isVisibleModelProperty) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property = NULL;
	zval *model, *property_param = NULL, *properties = NULL, *className = NULL, *_0, *_2, *_1$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &property_param);

	zephir_get_strval(property, property_param);


	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, model, 0 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelVisibility"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, className))) {
		ZEPHIR_CALL_FUNCTION(&_1$$3, "get_object_vars", NULL, 22, model);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("_modelVisibility"), className, _1$$3 TSRMLS_CC);
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_modelVisibility"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(properties);
	zephir_array_fetch(&properties, _2, className, PH_NOISY, "phalcon/mvc/model/manager.zep", 389 TSRMLS_CC);
	RETURN_MM_BOOL(zephir_array_key_exists(properties, property TSRMLS_CC));

}

/**
 * Returns the mapped source for a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getModelSource) {

	zval *model, *entityName = NULL, *_0, *_3, *_4, *_5, *_1$$3, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_INIT_VAR(entityName);
	zephir_get_class(entityName, model, 1 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_sources"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, entityName))) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_INIT_VAR(_2$$3);
		zephir_get_class_ns(_2$$3, model, 0 TSRMLS_CC);
		zephir_uncamelize(_1$$3, _2$$3, NULL  );
		zephir_update_property_array(this_ptr, SL("_sources"), entityName, _1$$3 TSRMLS_CC);
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_sources"), PH_NOISY_CC);
	zephir_array_fetch(&_5, _4, entityName, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 407 TSRMLS_CC);
	ZEPHIR_CONCAT_VV(return_value, _3, _5);
	RETURN_MM();

}

/**
 * Sets the mapped schema for a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setModelSchema) {

	zval *schema = NULL;
	zval *model, *schema_param = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(schema_param) != IS_STRING && Z_TYPE_P(schema_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schema' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schema_param) == IS_STRING)) {
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

	zval *model, *schema = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_schemas"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_get_class(_1, model, 1 TSRMLS_CC);
	if (!(zephir_array_isset_fetch(&schema, _0, _1, 1 TSRMLS_CC))) {
		RETURN_MM_STRING("", 1);
	}
	RETURN_CTOR(schema);

}

/**
 * Sets both write and read connection service for a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setConnectionService) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connectionService = NULL;
	zval *model, *connectionService_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &connectionService_param);

	if (UNEXPECTED(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(connectionService_param) == IS_STRING)) {
		zephir_get_strval(connectionService, connectionService_param);
	} else {
		ZEPHIR_INIT_VAR(connectionService);
		ZVAL_EMPTY_STRING(connectionService);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setreadconnectionservice", NULL, 0, model, connectionService);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setwriteconnectionservice", NULL, 0, model, connectionService);
	zephir_check_call_status();
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

	if (UNEXPECTED(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(connectionService_param) == IS_STRING)) {
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

	if (UNEXPECTED(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(connectionService_param) == IS_STRING)) {
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, *connectionServices, *dependencyInjector = NULL, *service = NULL, *connection = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &connectionServices);



	ZEPHIR_CALL_METHOD(&service, this_ptr, "_getconnectionservice", NULL, 0, model, connectionServices);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM", "phalcon/mvc/model/manager.zep", 484);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, 0, service);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(connection, _1);
	if (Z_TYPE_P(connection) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid injected connection service", "phalcon/mvc/model/manager.zep", 493);
		return;
	}
	RETURN_CCTOR(connection);

}

/**
 * Returns the connection service name used to read data related to a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getReadConnectionService) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_writeConnectionServices"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getconnectionservice", NULL, 0, model, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the connection service name used to read or write data related to
 * a model depending on the connection services
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, _getConnectionService) {

	zval *model, *connectionServices, *connection = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &connectionServices);



	ZEPHIR_INIT_VAR(_0);
	zephir_get_class(_0, model, 1 TSRMLS_CC);
	if (!(zephir_array_isset_fetch(&connection, connectionServices, _0, 1 TSRMLS_CC))) {
		RETURN_MM_STRING("db", 1);
	}
	RETURN_CTOR(connection);

}

/**
 * Receives events generated in the models and dispatches them to an events-manager if available
 * Notify the behaviors that are listening in the model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, notifyEvent) {

	HashTable *_3$$3;
	HashPosition _2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventName_param = NULL, *model, *status = NULL, *behavior = NULL, *modelsBehaviors = NULL, *eventsManager = NULL, *customEventsManager = NULL, *_0, *_1, *_6, *_7, **_4$$3;
	zval *eventName = NULL, *_5$$6, *_8$$8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &eventName_param, &model);

	if (UNEXPECTED(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(eventName_param) == IS_STRING)) {
		zephir_get_strval(eventName, eventName_param);
	} else {
		ZEPHIR_INIT_VAR(eventName);
		ZVAL_EMPTY_STRING(eventName);
	}


	ZEPHIR_INIT_VAR(status);
	ZVAL_NULL(status);
	ZEPHIR_OBS_VAR(modelsBehaviors);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_behaviors"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_get_class(_1, model, 1 TSRMLS_CC);
	if (zephir_array_isset_fetch(&modelsBehaviors, _0, _1, 0 TSRMLS_CC)) {
		zephir_is_iterable(modelsBehaviors, &_3$$3, &_2$$3, 0, 0, "phalcon/mvc/model/manager.zep", 554);
		for (
		  ; zend_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_3$$3, &_2$$3)
		) {
			ZEPHIR_GET_HVALUE(behavior, _4$$3);
			ZEPHIR_CALL_METHOD(&status, behavior, "notify", NULL, 0, eventName, model);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(status)) {
				RETURN_MM_BOOL(0);
			}
		}
	}
	ZEPHIR_OBS_VAR(eventsManager);
	zephir_read_property_this(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_5$$6);
		ZEPHIR_CONCAT_SV(_5$$6, "model:", eventName);
		ZEPHIR_CALL_METHOD(&status, eventsManager, "fire", NULL, 0, _5$$6, model);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(status)) {
			RETURN_CCTOR(status);
		}
	}
	ZEPHIR_OBS_VAR(customEventsManager);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_customEventsManager"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_7);
	zephir_get_class(_7, model, 1 TSRMLS_CC);
	if (zephir_array_isset_fetch(&customEventsManager, _6, _7, 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_8$$8);
		ZEPHIR_CONCAT_SV(_8$$8, "model:", eventName);
		ZEPHIR_CALL_METHOD(&status, customEventsManager, "fire", NULL, 0, _8$$8, model);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(status)) {
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_CCTOR(status);

}

/**
 * Dispatch an event to the listeners and behaviors
 * This method expects that the endpoint listeners/behaviors returns true
 * meaning that a least one was implemented
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, missingMethod) {

	HashTable *_3$$3;
	HashPosition _2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventName = NULL, *_5$$6;
	zval *model, *eventName_param = NULL, *data, *modelsBehaviors = NULL, *result = NULL, *eventsManager = NULL, *behavior = NULL, *_0, *_1, **_4$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &model, &eventName_param, &data);

	if (UNEXPECTED(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(eventName_param) == IS_STRING)) {
		zephir_get_strval(eventName, eventName_param);
	} else {
		ZEPHIR_INIT_VAR(eventName);
		ZVAL_EMPTY_STRING(eventName);
	}


	ZEPHIR_OBS_VAR(modelsBehaviors);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_behaviors"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_get_class(_1, model, 1 TSRMLS_CC);
	if (zephir_array_isset_fetch(&modelsBehaviors, _0, _1, 0 TSRMLS_CC)) {
		zephir_is_iterable(modelsBehaviors, &_3$$3, &_2$$3, 0, 0, "phalcon/mvc/model/manager.zep", 603);
		for (
		  ; zend_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_3$$3, &_2$$3)
		) {
			ZEPHIR_GET_HVALUE(behavior, _4$$3);
			ZEPHIR_CALL_METHOD(&result, behavior, "missingmethod", NULL, 0, model, eventName, data);
			zephir_check_call_status();
			if (Z_TYPE_P(result) != IS_NULL) {
				RETURN_CCTOR(result);
			}
		}
	}
	ZEPHIR_OBS_VAR(eventsManager);
	zephir_read_property_this(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_5$$6);
		ZEPHIR_CONCAT_SV(_5$$6, "model:", eventName);
		ZEPHIR_RETURN_CALL_METHOD(eventsManager, "fire", NULL, 0, _5$$6, model, data);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_NULL();

}

/**
 * Binds a behavior to a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, addBehavior) {

	zval *model, *behavior, *entityName = NULL, *modelsBehaviors = NULL, *_0;

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
	zephir_array_append(&modelsBehaviors, behavior, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 635);
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

	zval *model, *keepSnapshots = NULL, *isKeeping = NULL, *_0$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	keepSnapshots = zephir_fetch_nproperty_this(this_ptr, SL("_keepSnapshots"), PH_NOISY_CC);
	if (Z_TYPE_P(keepSnapshots) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0$$3);
		zephir_get_class(_0$$3, model, 1 TSRMLS_CC);
		if (zephir_array_isset_fetch(&isKeeping, keepSnapshots, _0$$3, 1 TSRMLS_CC)) {
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
	zval *model, *dynamicUpdate_param = NULL, *entityName = NULL, *_0, *_1;

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

	zval *model, *dynamicUpdate = NULL, *isUsing = NULL, *_0$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	dynamicUpdate = zephir_fetch_nproperty_this(this_ptr, SL("_dynamicUpdate"), PH_NOISY_CC);
	if (Z_TYPE_P(dynamicUpdate) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0$$3);
		zephir_get_class(_0$$3, model, 1 TSRMLS_CC);
		if (zephir_array_isset_fetch(&isUsing, dynamicUpdate, _0$$3, 1 TSRMLS_CC)) {
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *referencedModel = NULL;
	zval *model, *fields, *referencedModel_param = NULL, *referencedFields, *options = NULL, *entityName = NULL, *referencedEntity = NULL, *relation = NULL, *keyRelation = NULL, *relations = NULL, *alias = NULL, *lowerAlias = NULL, *singleRelations = NULL, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &model, &fields, &referencedModel_param, &referencedFields, &options);

	if (UNEXPECTED(Z_TYPE_P(referencedModel_param) != IS_STRING && Z_TYPE_P(referencedModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referencedModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referencedModel_param) == IS_STRING)) {
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
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same", "phalcon/mvc/model/manager.zep", 722);
			return;
		}
	}
	ZEPHIR_INIT_VAR(relation);
	object_init_ex(relation, phalcon_mvc_model_relation_ce);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 1);
	ZEPHIR_CALL_METHOD(NULL, relation, "__construct", NULL, 346, _1, referencedModel, fields, referencedFields, options);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(alias);
	if (zephir_array_isset_string_fetch(&alias, options, SS("alias"), 0 TSRMLS_CC)) {
		if (Z_TYPE_P(alias) != IS_STRING) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Relation alias must be a string", "phalcon/mvc/model/manager.zep", 742);
			return;
		}
		ZEPHIR_INIT_VAR(lowerAlias);
		zephir_fast_strtolower(lowerAlias, alias);
	} else {
		ZEPHIR_CPY_WRT(lowerAlias, referencedEntity);
	}
	zephir_array_append(&relations, relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 754);
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
	zephir_array_append(&singleRelations, relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 768);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *referencedModel = NULL;
	zval *model, *fields, *referencedModel_param = NULL, *referencedFields, *options = NULL, *entityName = NULL, *referencedEntity = NULL, *relation = NULL, *keyRelation = NULL, *relations = NULL, *alias = NULL, *lowerAlias = NULL, *singleRelations = NULL, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &model, &fields, &referencedModel_param, &referencedFields, &options);

	if (UNEXPECTED(Z_TYPE_P(referencedModel_param) != IS_STRING && Z_TYPE_P(referencedModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referencedModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referencedModel_param) == IS_STRING)) {
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
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same", "phalcon/mvc/model/manager.zep", 807);
			return;
		}
	}
	ZEPHIR_INIT_VAR(relation);
	object_init_ex(relation, phalcon_mvc_model_relation_ce);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	ZEPHIR_CALL_METHOD(NULL, relation, "__construct", NULL, 346, _1, referencedModel, fields, referencedFields, options);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(alias);
	if (zephir_array_isset_string_fetch(&alias, options, SS("alias"), 0 TSRMLS_CC)) {
		if (Z_TYPE_P(alias) != IS_STRING) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Relation alias must be a string", "phalcon/mvc/model/manager.zep", 827);
			return;
		}
		ZEPHIR_INIT_VAR(lowerAlias);
		zephir_fast_strtolower(lowerAlias, alias);
	} else {
		ZEPHIR_CPY_WRT(lowerAlias, referencedEntity);
	}
	zephir_array_append(&relations, relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 839);
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
	zephir_array_append(&singleRelations, relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 853);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *referencedModel = NULL;
	zval *model, *fields, *referencedModel_param = NULL, *referencedFields, *options = NULL, *entityName = NULL, *referencedEntity = NULL, *hasMany = NULL, *relation = NULL, *keyRelation = NULL, *relations = NULL, *alias = NULL, *lowerAlias = NULL, *singleRelations = NULL, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &model, &fields, &referencedModel_param, &referencedFields, &options);

	if (UNEXPECTED(Z_TYPE_P(referencedModel_param) != IS_STRING && Z_TYPE_P(referencedModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referencedModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referencedModel_param) == IS_STRING)) {
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
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same", "phalcon/mvc/model/manager.zep", 892);
			return;
		}
	}
	ZEPHIR_INIT_VAR(relation);
	object_init_ex(relation, phalcon_mvc_model_relation_ce);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 2);
	ZEPHIR_CALL_METHOD(NULL, relation, "__construct", NULL, 346, _0, referencedModel, fields, referencedFields, options);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(alias);
	if (zephir_array_isset_string_fetch(&alias, options, SS("alias"), 0 TSRMLS_CC)) {
		if (Z_TYPE_P(alias) != IS_STRING) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Relation alias must be a string", "phalcon/mvc/model/manager.zep", 912);
			return;
		}
		ZEPHIR_INIT_VAR(lowerAlias);
		zephir_fast_strtolower(lowerAlias, alias);
	} else {
		ZEPHIR_CPY_WRT(lowerAlias, referencedEntity);
	}
	zephir_array_append(&relations, relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 924);
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
	zephir_array_append(&singleRelations, relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 938);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *intermediateModel = NULL, *referencedModel = NULL;
	zval *model, *fields, *intermediateModel_param = NULL, *intermediateFields, *intermediateReferencedFields, *referencedModel_param = NULL, *referencedFields, *options = NULL, *entityName = NULL, *referencedEntity = NULL, *hasManyToMany = NULL, *relation = NULL, *keyRelation = NULL, *relations = NULL, *alias = NULL, *lowerAlias = NULL, *singleRelations = NULL, *intermediateEntity = NULL, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 7, 1, &model, &fields, &intermediateModel_param, &intermediateFields, &intermediateReferencedFields, &referencedModel_param, &referencedFields, &options);

	if (UNEXPECTED(Z_TYPE_P(intermediateModel_param) != IS_STRING && Z_TYPE_P(intermediateModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'intermediateModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(intermediateModel_param) == IS_STRING)) {
		zephir_get_strval(intermediateModel, intermediateModel_param);
	} else {
		ZEPHIR_INIT_VAR(intermediateModel);
		ZVAL_EMPTY_STRING(intermediateModel);
	}
	if (UNEXPECTED(Z_TYPE_P(referencedModel_param) != IS_STRING && Z_TYPE_P(referencedModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referencedModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referencedModel_param) == IS_STRING)) {
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
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same", "phalcon/mvc/model/manager.zep", 982);
			return;
		}
	}
	if (Z_TYPE_P(intermediateReferencedFields) == IS_ARRAY) {
		if (zephir_fast_count_int(fields TSRMLS_CC) != zephir_fast_count_int(intermediateFields TSRMLS_CC)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same", "phalcon/mvc/model/manager.zep", 991);
			return;
		}
	}
	ZEPHIR_INIT_VAR(relation);
	object_init_ex(relation, phalcon_mvc_model_relation_ce);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 4);
	ZEPHIR_CALL_METHOD(NULL, relation, "__construct", NULL, 346, _0, referencedModel, fields, referencedFields, options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, relation, "setintermediaterelation", NULL, 347, intermediateFields, intermediateModel, intermediateReferencedFields);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(alias);
	if (zephir_array_isset_string_fetch(&alias, options, SS("alias"), 0 TSRMLS_CC)) {
		if (Z_TYPE_P(alias) != IS_STRING) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Relation alias must be a string", "phalcon/mvc/model/manager.zep", 1016);
			return;
		}
		ZEPHIR_INIT_VAR(lowerAlias);
		zephir_fast_strtolower(lowerAlias, alias);
	} else {
		ZEPHIR_CPY_WRT(lowerAlias, referencedEntity);
	}
	zephir_array_append(&relations, relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1026);
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
	zephir_array_append(&singleRelations, relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1048);
	zephir_update_property_array(this_ptr, SL("_hasManyToManySingle"), entityName, singleRelations TSRMLS_CC);
	RETURN_CCTOR(relation);

}

/**
 * Checks whether a model has a belongsTo relation with another model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsBelongsTo) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *modelName_param = NULL, *modelRelation_param = NULL, *entityName = NULL, *keyRelation = NULL, *_0, *_1, *_2;
	zval *modelName = NULL, *modelRelation = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &modelRelation_param);

	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}
	if (UNEXPECTED(Z_TYPE_P(modelRelation_param) != IS_STRING && Z_TYPE_P(modelRelation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelRelation' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelRelation_param) == IS_STRING)) {
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *modelName_param = NULL, *modelRelation_param = NULL, *entityName = NULL, *keyRelation = NULL, *_0, *_1, *_2;
	zval *modelName = NULL, *modelRelation = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &modelRelation_param);

	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}
	if (UNEXPECTED(Z_TYPE_P(modelRelation_param) != IS_STRING && Z_TYPE_P(modelRelation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelRelation' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelRelation_param) == IS_STRING)) {
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *modelName_param = NULL, *modelRelation_param = NULL, *entityName = NULL, *keyRelation = NULL, *_0, *_1, *_2;
	zval *modelName = NULL, *modelRelation = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &modelRelation_param);

	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}
	if (UNEXPECTED(Z_TYPE_P(modelRelation_param) != IS_STRING && Z_TYPE_P(modelRelation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelRelation' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelRelation_param) == IS_STRING)) {
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *modelName_param = NULL, *modelRelation_param = NULL, *entityName = NULL, *keyRelation = NULL, *_0, *_1, *_2;
	zval *modelName = NULL, *modelRelation = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &modelRelation_param);

	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}
	if (UNEXPECTED(Z_TYPE_P(modelRelation_param) != IS_STRING && Z_TYPE_P(modelRelation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelRelation' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelRelation_param) == IS_STRING)) {
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

	zval *modelName_param = NULL, *alias_param = NULL, *relation = NULL, *_0, *_1;
	zval *modelName = NULL, *alias = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &alias_param);

	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}
	if (UNEXPECTED(Z_TYPE_P(alias_param) != IS_STRING && Z_TYPE_P(alias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(alias_param) == IS_STRING)) {
		zephir_get_strval(alias, alias_param);
	} else {
		ZEPHIR_INIT_VAR(alias);
		ZVAL_EMPTY_STRING(alias);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_aliases"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VSV(_2, modelName, "$", alias);
	zephir_fast_strtolower(_1, _2);
	if (!(zephir_array_isset_fetch(&relation, _0, _1, 1 TSRMLS_CC))) {
		RETURN_MM_BOOL(0);
	}
	RETURN_CTOR(relation);

}

/**
 * Merge two arrays of find parameters
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, _mergeFindParameters) {

	HashTable *_3$$4, *_9$$11;
	HashPosition _2$$4, _8$$11;
	zend_bool _0, _5$$5, _11$$12, _14$$12;
	zval *findParamsOne, *findParamsTwo, *key = NULL, *value = NULL, *findParams = NULL, *_1$$3, **_4$$4, *_6$$8, *_7$$8 = NULL, **_10$$11, *_12$$15, *_13$$15 = NULL, *_15$$20 = NULL, *_16$$20, *_17$$24, *_18$$24;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &findParamsOne, &findParamsTwo);



	_0 = Z_TYPE_P(findParamsOne) == IS_STRING;
	if (_0) {
		_0 = Z_TYPE_P(findParamsTwo) == IS_STRING;
	}
	if (_0) {
		zephir_create_array(return_value, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_CONCAT_SVSVS(_1$$3, "(", findParamsOne, ") AND (", findParamsTwo, ")");
		zephir_array_fast_append(return_value, _1$$3);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(findParams);
	array_init(findParams);
	if (Z_TYPE_P(findParamsOne) == IS_ARRAY) {
		zephir_is_iterable(findParamsOne, &_3$$4, &_2$$4, 0, 0, "phalcon/mvc/model/manager.zep", 1195);
		for (
		  ; zend_hash_get_current_data_ex(_3$$4, (void**) &_4$$4, &_2$$4) == SUCCESS
		  ; zend_hash_move_forward_ex(_3$$4, &_2$$4)
		) {
			ZEPHIR_GET_HMKEY(key, _3$$4, _2$$4);
			ZEPHIR_GET_HVALUE(value, _4$$4);
			_5$$5 = ZEPHIR_IS_LONG_IDENTICAL(key, 0);
			if (!(_5$$5)) {
				_5$$5 = ZEPHIR_IS_STRING_IDENTICAL(key, "conditions");
			}
			if (_5$$5) {
				if (!(zephir_array_isset_long(findParams, 0))) {
					zephir_array_update_long(&findParams, 0, &value, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
				} else {
					zephir_array_fetch_long(&_6$$8, findParams, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1188 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_7$$8);
					ZEPHIR_CONCAT_SVSVS(_7$$8, "(", _6$$8, ") AND (", value, ")");
					zephir_array_update_long(&findParams, 0, &_7$$8, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
				}
				continue;
			}
			zephir_array_update_zval(&findParams, key, &value, PH_COPY | PH_SEPARATE);
		}
	} else {
		if (Z_TYPE_P(findParamsOne) == IS_STRING) {
			ZEPHIR_INIT_NVAR(findParams);
			zephir_create_array(findParams, 1, 0 TSRMLS_CC);
			zephir_array_update_string(&findParams, SL("conditions"), &findParamsOne, PH_COPY | PH_SEPARATE);
		}
	}
	if (Z_TYPE_P(findParamsTwo) == IS_ARRAY) {
		zephir_is_iterable(findParamsTwo, &_9$$11, &_8$$11, 0, 0, "phalcon/mvc/model/manager.zep", 1229);
		for (
		  ; zend_hash_get_current_data_ex(_9$$11, (void**) &_10$$11, &_8$$11) == SUCCESS
		  ; zend_hash_move_forward_ex(_9$$11, &_8$$11)
		) {
			ZEPHIR_GET_HMKEY(key, _9$$11, _8$$11);
			ZEPHIR_GET_HVALUE(value, _10$$11);
			_11$$12 = ZEPHIR_IS_LONG_IDENTICAL(key, 0);
			if (!(_11$$12)) {
				_11$$12 = ZEPHIR_IS_STRING_IDENTICAL(key, "conditions");
			}
			if (_11$$12) {
				if (!(zephir_array_isset_long(findParams, 0))) {
					zephir_array_update_long(&findParams, 0, &value, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
				} else {
					zephir_array_fetch_long(&_12$$15, findParams, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1209 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_13$$15);
					ZEPHIR_CONCAT_SVSVS(_13$$15, "(", _12$$15, ") AND (", value, ")");
					zephir_array_update_long(&findParams, 0, &_13$$15, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
				}
				continue;
			}
			_14$$12 = ZEPHIR_IS_STRING_IDENTICAL(key, "bind");
			if (!(_14$$12)) {
				_14$$12 = ZEPHIR_IS_STRING_IDENTICAL(key, "bindTypes");
			}
			if (_14$$12) {
				if (!(zephir_array_isset(findParams, key))) {
					if (Z_TYPE_P(value) == IS_ARRAY) {
						zephir_array_update_zval(&findParams, key, &value, PH_COPY | PH_SEPARATE);
					}
				} else {
					if (Z_TYPE_P(value) == IS_ARRAY) {
						ZEPHIR_INIT_NVAR(_15$$20);
						zephir_array_fetch(&_16$$20, findParams, key, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1221 TSRMLS_CC);
						zephir_fast_array_merge(_15$$20, &(_16$$20), &(value) TSRMLS_CC);
						zephir_array_update_zval(&findParams, key, &_15$$20, PH_COPY | PH_SEPARATE);
					}
				}
				continue;
			}
			zephir_array_update_zval(&findParams, key, &value, PH_COPY | PH_SEPARATE);
		}
	} else {
		if (Z_TYPE_P(findParamsTwo) == IS_STRING) {
			if (!(zephir_array_isset_long(findParams, 0))) {
				zephir_array_update_long(&findParams, 0, &findParamsTwo, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
			} else {
				zephir_array_fetch_long(&_17$$24, findParams, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1234 TSRMLS_CC);
				ZEPHIR_INIT_VAR(_18$$24);
				ZEPHIR_CONCAT_SVSVS(_18$$24, "(", _17$$24, ") AND (", findParamsTwo, ")");
				zephir_array_update_long(&findParams, 0, &_18$$24, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
			}
		}
	}
	RETURN_CCTOR(findParams);

}

/**
 * Helper method to query records based on a relation definition
 *
 * @return \Phalcon\Mvc\Model\Resultset\Simple|Phalcon\Mvc\Model\Resultset\Simple|int|false
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationRecords) {

	HashTable *_17$$10;
	HashPosition _16$$10;
	zval *_28;
	zend_bool reusable = 0, _27$$19;
	zephir_fcall_cache_entry *_22 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method = NULL;
	zval *relation, *method_param = NULL, *record, *parameters = NULL, *placeholders = NULL, *referencedModel = NULL, *intermediateModel = NULL, *intermediateFields = NULL, *joinConditions = NULL, *fields = NULL, *builder = NULL, *extraParameters = NULL, *conditions = NULL, *refPosition = NULL, *field = NULL, *referencedFields = NULL, *findParams = NULL, *findArguments = NULL, *retrieveMethod = NULL, *uniqueKey = NULL, *records = NULL, *arguments = NULL, *rows = NULL, *firstRow = NULL, *_0 = NULL, *_24, *_25 = NULL, *_1$$4, *_2$$4 = NULL, *_3$$6 = NULL, *_4$$6, *_5$$3 = NULL, *_6$$3, *_7$$3, *_11$$3 = NULL, *_8$$8 = NULL, *_9$$8 = NULL, *_10$$8 = NULL, *_12$$9 = NULL, *_13$$9, *_14$$9 = NULL, *_15$$10 = NULL, **_18$$10, *_19$$11, *_20$$11 = NULL, *_21$$11 = NULL, *_23$$11 = NULL, *_26$$14 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &relation, &method_param, &record, &parameters);

	if (UNEXPECTED(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(method, method_param);
	} else {
		ZEPHIR_INIT_VAR(method);
		ZVAL_EMPTY_STRING(method);
	}
	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(placeholders);
	array_init(placeholders);
	ZEPHIR_CALL_METHOD(&extraParameters, relation, "getparams", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&referencedModel, relation, "getreferencedmodel", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, relation, "isthrough", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(conditions);
		array_init(conditions);
		ZEPHIR_CALL_METHOD(&intermediateModel, relation, "getintermediatemodel", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&intermediateFields, relation, "getintermediatefields", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&fields, relation, "getfields", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(fields) != IS_ARRAY) {
			ZEPHIR_INIT_VAR(_1$$4);
			ZEPHIR_CONCAT_SVSVS(_1$$4, "[", intermediateModel, "].[", intermediateFields, "] = :APR0:");
			zephir_array_append(&conditions, _1$$4, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1285);
			ZEPHIR_CALL_METHOD(&_2$$4, record, "readattribute", NULL, 0, fields);
			zephir_check_call_status();
			zephir_array_update_string(&placeholders, SL("APR0"), &_2$$4, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not supported", "phalcon/mvc/model/manager.zep", 1288);
			return;
		}
		ZEPHIR_INIT_VAR(joinConditions);
		array_init(joinConditions);
		ZEPHIR_CALL_METHOD(&intermediateFields, relation, "getintermediatereferencedfields", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(intermediateFields) != IS_ARRAY) {
			ZEPHIR_CALL_METHOD(&_3$$6, relation, "getreferencedfields", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_4$$6);
			ZEPHIR_CONCAT_SVSVSVSVS(_4$$6, "[", intermediateModel, "].[", intermediateFields, "] = [", referencedModel, "].[", _3$$6, "]");
			zephir_array_append(&joinConditions, _4$$6, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1298);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not supported", "phalcon/mvc/model/manager.zep", 1300);
			return;
		}
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "_mergefindparameters", NULL, 348, extraParameters, parameters);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&builder, this_ptr, "createbuilder", NULL, 0, _5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, builder, "from", NULL, 0, referencedModel);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_6$$3);
		zephir_fast_join_str(_6$$3, SL(" AND "), joinConditions TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, builder, "innerjoin", NULL, 0, intermediateModel, _6$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_7$$3);
		zephir_fast_join_str(_7$$3, SL(" AND "), conditions TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, builder, "andwhere", NULL, 0, _7$$3, placeholders);
		zephir_check_call_status();
		if (ZEPHIR_IS_STRING(method, "count")) {
			ZEPHIR_INIT_VAR(_8$$8);
			ZVAL_STRING(_8$$8, "COUNT(*) AS rowcount", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, builder, "columns", NULL, 0, _8$$8);
			zephir_check_temp_parameter(_8$$8);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_9$$8, builder, "getquery", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&rows, _9$$8, "execute", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&firstRow, rows, "getfirst", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_8$$8);
			ZVAL_STRING(_8$$8, "rowcount", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_10$$8, firstRow, "readattribute", NULL, 0, _8$$8);
			zephir_check_temp_parameter(_8$$8);
			zephir_check_call_status();
			RETURN_MM_LONG(zephir_get_intval(_10$$8));
		}
		ZEPHIR_CALL_METHOD(&_11$$3, builder, "getquery", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(_11$$3, "execute", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(conditions);
	array_init(conditions);
	ZEPHIR_CALL_METHOD(&fields, relation, "getfields", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(fields) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_12$$9, relation, "getreferencedfields", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_13$$9);
		ZEPHIR_CONCAT_SVS(_13$$9, "[", _12$$9, "] = :APR0:");
		zephir_array_append(&conditions, _13$$9, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1337);
		ZEPHIR_CALL_METHOD(&_14$$9, record, "readattribute", NULL, 0, fields);
		zephir_check_call_status();
		zephir_array_update_string(&placeholders, SL("APR0"), &_14$$9, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_CALL_METHOD(&referencedFields, relation, "getreferencedfields", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_15$$10, relation, "getfields", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(_15$$10, &_17$$10, &_16$$10, 0, 0, "phalcon/mvc/model/manager.zep", 1349);
		for (
		  ; zend_hash_get_current_data_ex(_17$$10, (void**) &_18$$10, &_16$$10) == SUCCESS
		  ; zend_hash_move_forward_ex(_17$$10, &_16$$10)
		) {
			ZEPHIR_GET_HMKEY(refPosition, _17$$10, _16$$10);
			ZEPHIR_GET_HVALUE(field, _18$$10);
			zephir_array_fetch(&_19$$11, referencedFields, refPosition, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1346 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_20$$11);
			ZEPHIR_CONCAT_SVSVS(_20$$11, "[", _19$$11, "] = :APR", refPosition, ":");
			zephir_array_append(&conditions, _20$$11, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1346);
			ZEPHIR_CALL_METHOD(&_21$$11, record, "readattribute", &_22, 0, field);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_23$$11);
			ZEPHIR_CONCAT_SV(_23$$11, "APR", refPosition);
			zephir_array_update_zval(&placeholders, _23$$11, &_21$$11, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_VAR(findParams);
	zephir_create_array(findParams, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_24);
	zephir_fast_join_str(_24, SL(" AND "), conditions TSRMLS_CC);
	zephir_array_fast_append(findParams, _24);
	zephir_array_update_string(&findParams, SL("bind"), &placeholders, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_25, record, "getdi", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&findParams, SL("di"), &_25, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&findArguments, this_ptr, "_mergefindparameters", NULL, 348, findParams, parameters);
	zephir_check_call_status();
	if (Z_TYPE_P(extraParameters) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&findParams, this_ptr, "_mergefindparameters", NULL, 348, extraParameters, findArguments);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(findParams, findArguments);
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(method, "")) {
		ZEPHIR_CALL_METHOD(&_26$$14, relation, "gettype", NULL, 0);
		zephir_check_call_status();
		do {
			if (ZEPHIR_IS_LONG(_26$$14, 0) || ZEPHIR_IS_LONG(_26$$14, 1)) {
				ZEPHIR_INIT_VAR(retrieveMethod);
				ZVAL_STRING(retrieveMethod, "findFirst", 1);
				break;
			}
			if (ZEPHIR_IS_LONG(_26$$14, 2)) {
				ZEPHIR_INIT_NVAR(retrieveMethod);
				ZVAL_STRING(retrieveMethod, "find", 1);
				break;
			}
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Unknown relation type", "phalcon/mvc/model/manager.zep", 1385);
			return;
		} while(0);

	} else {
		ZEPHIR_CPY_WRT(retrieveMethod, method);
	}
	ZEPHIR_INIT_VAR(arguments);
	zephir_create_array(arguments, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(arguments, findParams);
	ZEPHIR_CALL_METHOD(&_25, relation, "isreusable", NULL, 0);
	zephir_check_call_status();
	reusable = zephir_get_boolval(_25);
	if (reusable) {
		ZEPHIR_INIT_VAR(uniqueKey);
		zephir_unique_key(uniqueKey, referencedModel, arguments TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&records, this_ptr, "getreusablerecords", NULL, 0, referencedModel, uniqueKey);
		zephir_check_call_status();
		_27$$19 = Z_TYPE_P(records) == IS_ARRAY;
		if (!(_27$$19)) {
			_27$$19 = Z_TYPE_P(records) == IS_OBJECT;
		}
		if (_27$$19) {
			RETURN_CCTOR(records);
		}
	}
	ZEPHIR_INIT_VAR(_28);
	zephir_create_array(_28, 2, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_25, this_ptr, "load", NULL, 0, referencedModel);
	zephir_check_call_status();
	zephir_array_fast_append(_28, _25);
	zephir_array_fast_append(_28, retrieveMethod);
	ZEPHIR_INIT_NVAR(records);
	ZEPHIR_CALL_USER_FUNC_ARRAY(records, _28, arguments);
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

	zval *modelName_param = NULL, *key_param = NULL, *records = NULL, *_0;
	zval *modelName = NULL, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &key_param);

	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}
	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
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

	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}
	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
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

	

	zephir_update_property_this(getThis(), SL("_reusable"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);

}

/**
 * Gets belongsTo related records from a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getBelongsToRecords) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *modelName_param = NULL, *modelRelation, *record, *parameters = NULL, *keyRelation = NULL, *relations = NULL, *_0, *_1, *_2, *_3;
	zval *method = NULL, *modelName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &method_param, &modelName_param, &modelRelation, &record, &parameters);

	if (UNEXPECTED(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(method, method_param);
	} else {
		ZEPHIR_INIT_VAR(method);
		ZVAL_EMPTY_STRING(method);
	}
	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}
	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, modelName);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, modelRelation);
	ZEPHIR_INIT_VAR(keyRelation);
	ZEPHIR_CONCAT_VSV(keyRelation, _0, "$", _1);
	ZEPHIR_OBS_VAR(relations);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_hasMany"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&relations, _2, keyRelation, 0 TSRMLS_CC))) {
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_long(&_3, relations, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1469 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrelationrecords", NULL, 0, _3, method, record, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets hasMany related records from a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasManyRecords) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *modelName_param = NULL, *modelRelation, *record, *parameters = NULL, *keyRelation = NULL, *relations = NULL, *_0, *_1, *_2, *_3;
	zval *method = NULL, *modelName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &method_param, &modelName_param, &modelRelation, &record, &parameters);

	if (UNEXPECTED(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(method, method_param);
	} else {
		ZEPHIR_INIT_VAR(method);
		ZVAL_EMPTY_STRING(method);
	}
	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}
	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, modelName);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, modelRelation);
	ZEPHIR_INIT_VAR(keyRelation);
	ZEPHIR_CONCAT_VSV(keyRelation, _0, "$", _1);
	ZEPHIR_OBS_VAR(relations);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_hasMany"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&relations, _2, keyRelation, 0 TSRMLS_CC))) {
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_long(&_3, relations, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1492 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrelationrecords", NULL, 0, _3, method, record, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets belongsTo related records from a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOneRecords) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *modelName_param = NULL, *modelRelation, *record, *parameters = NULL, *keyRelation = NULL, *relations = NULL, *_0, *_1, *_2, *_3;
	zval *method = NULL, *modelName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &method_param, &modelName_param, &modelRelation, &record, &parameters);

	if (UNEXPECTED(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(method, method_param);
	} else {
		ZEPHIR_INIT_VAR(method);
		ZVAL_EMPTY_STRING(method);
	}
	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}
	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, modelName);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, modelRelation);
	ZEPHIR_INIT_VAR(keyRelation);
	ZEPHIR_CONCAT_VSV(keyRelation, _0, "$", _1);
	ZEPHIR_OBS_VAR(relations);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_hasOne"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&relations, _2, keyRelation, 0 TSRMLS_CC))) {
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_long(&_3, relations, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1515 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrelationrecords", NULL, 0, _3, method, record, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets all the belongsTo relations defined in a model
 *
 *<code>
 * $relations = $modelsManager->getBelongsTo(
 *     new Robots()
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getBelongsTo) {

	zval *model, *relations = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_belongsToSingle"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_get_class(_1, model, 1 TSRMLS_CC);
	if (!(zephir_array_isset_fetch(&relations, _0, _1, 1 TSRMLS_CC))) {
		array_init(return_value);
		RETURN_MM();
	}
	RETURN_CTOR(relations);

}

/**
 * Gets hasMany relations defined on a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasMany) {

	zval *model, *relations = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_hasManySingle"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_get_class(_1, model, 1 TSRMLS_CC);
	if (!(zephir_array_isset_fetch(&relations, _0, _1, 1 TSRMLS_CC))) {
		array_init(return_value);
		RETURN_MM();
	}
	RETURN_CTOR(relations);

}

/**
 * Gets hasOne relations defined on a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOne) {

	zval *model, *relations = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_hasOneSingle"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_get_class(_1, model, 1 TSRMLS_CC);
	if (!(zephir_array_isset_fetch(&relations, _0, _1, 1 TSRMLS_CC))) {
		array_init(return_value);
		RETURN_MM();
	}
	RETURN_CTOR(relations);

}

/**
 * Gets hasManyToMany relations defined on a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasManyToMany) {

	zval *model, *relations = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_hasManyToManySingle"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_get_class(_1, model, 1 TSRMLS_CC);
	if (!(zephir_array_isset_fetch(&relations, _0, _1, 1 TSRMLS_CC))) {
		array_init(return_value);
		RETURN_MM();
	}
	RETURN_CTOR(relations);

}

/**
 * Gets hasOne relations defined on a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOneAndHasMany) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
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

	HashTable *_2$$3, *_6$$5, *_10$$7;
	HashPosition _1$$3, _5$$5, _9$$7;
	zval *modelName_param = NULL, *entityName = NULL, *allRelations = NULL, *relations = NULL, *relation = NULL, *_0, *_4, *_8, **_3$$3, **_7$$5, **_11$$7;
	zval *modelName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modelName_param);

	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}


	ZEPHIR_INIT_VAR(entityName);
	zephir_fast_strtolower(entityName, modelName);
	ZEPHIR_INIT_VAR(allRelations);
	array_init(allRelations);
	ZEPHIR_OBS_VAR(relations);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_belongsToSingle"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&relations, _0, entityName, 0 TSRMLS_CC)) {
		zephir_is_iterable(relations, &_2$$3, &_1$$3, 0, 0, "phalcon/mvc/model/manager.zep", 1605);
		for (
		  ; zend_hash_get_current_data_ex(_2$$3, (void**) &_3$$3, &_1$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_2$$3, &_1$$3)
		) {
			ZEPHIR_GET_HVALUE(relation, _3$$3);
			zephir_array_append(&allRelations, relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1603);
		}
	}
	ZEPHIR_OBS_NVAR(relations);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_hasManySingle"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&relations, _4, entityName, 0 TSRMLS_CC)) {
		zephir_is_iterable(relations, &_6$$5, &_5$$5, 0, 0, "phalcon/mvc/model/manager.zep", 1614);
		for (
		  ; zend_hash_get_current_data_ex(_6$$5, (void**) &_7$$5, &_5$$5) == SUCCESS
		  ; zend_hash_move_forward_ex(_6$$5, &_5$$5)
		) {
			ZEPHIR_GET_HVALUE(relation, _7$$5);
			zephir_array_append(&allRelations, relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1612);
		}
	}
	ZEPHIR_OBS_NVAR(relations);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_hasOneSingle"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&relations, _8, entityName, 0 TSRMLS_CC)) {
		zephir_is_iterable(relations, &_10$$7, &_9$$7, 0, 0, "phalcon/mvc/model/manager.zep", 1623);
		for (
		  ; zend_hash_get_current_data_ex(_10$$7, (void**) &_11$$7, &_9$$7) == SUCCESS
		  ; zend_hash_move_forward_ex(_10$$7, &_9$$7)
		) {
			ZEPHIR_GET_HVALUE(relation, _11$$7);
			zephir_array_append(&allRelations, relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1621);
		}
	}
	RETURN_CCTOR(allRelations);

}

/**
 * Query the first relationship defined between two models
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationsBetween) {

	zval *first_param = NULL, *second_param = NULL, *keyRelation = NULL, *relations = NULL, *_0, *_1, *_2, *_3, *_4;
	zval *first = NULL, *second = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &first_param, &second_param);

	if (UNEXPECTED(Z_TYPE_P(first_param) != IS_STRING && Z_TYPE_P(first_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'first' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(first_param) == IS_STRING)) {
		zephir_get_strval(first, first_param);
	} else {
		ZEPHIR_INIT_VAR(first);
		ZVAL_EMPTY_STRING(first);
	}
	if (UNEXPECTED(Z_TYPE_P(second_param) != IS_STRING && Z_TYPE_P(second_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'second' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(second_param) == IS_STRING)) {
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
	ZEPHIR_OBS_VAR(relations);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&relations, _2, keyRelation, 0 TSRMLS_CC)) {
		RETURN_CCTOR(relations);
	}
	ZEPHIR_OBS_NVAR(relations);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_hasMany"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&relations, _3, keyRelation, 0 TSRMLS_CC)) {
		RETURN_CCTOR(relations);
	}
	ZEPHIR_OBS_NVAR(relations);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_hasOne"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&relations, _4, keyRelation, 0 TSRMLS_CC)) {
		RETURN_CCTOR(relations);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Creates a Phalcon\Mvc\Model\Query without execute it
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, createQuery) {

	zval *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *phql_param = NULL, *dependencyInjector = NULL, *query = NULL, *_0 = NULL, *_2;
	zval *phql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &phql_param);

	if (UNEXPECTED(Z_TYPE_P(phql_param) != IS_STRING && Z_TYPE_P(phql_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'phql' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(phql_param) == IS_STRING)) {
		zephir_get_strval(phql, phql_param);
	} else {
		ZEPHIR_INIT_VAR(phql);
		ZVAL_EMPTY_STRING(phql);
	}


	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injection object is required to access ORM services", "phalcon/mvc/model/manager.zep", 1670);
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
	zephir_update_property_this(getThis(), SL("_lastQuery"), query TSRMLS_CC);
	RETURN_CCTOR(query);

}

/**
 * Creates a Phalcon\Mvc\Model\Query and execute it
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, executeQuery) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *phql_param = NULL, *placeholders = NULL, *types = NULL, *query = NULL;
	zval *phql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &phql_param, &placeholders, &types);

	if (UNEXPECTED(Z_TYPE_P(phql_param) != IS_STRING && Z_TYPE_P(phql_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'phql' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(phql_param) == IS_STRING)) {
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


	ZEPHIR_CALL_METHOD(&query, this_ptr, "createquery", NULL, 0, phql);
	zephir_check_call_status();
	if (Z_TYPE_P(placeholders) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, query, "setbindparams", NULL, 0, placeholders);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(types) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, query, "setbindtypes", NULL, 0, types);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_METHOD(query, "execute", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Creates a Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, createBuilder) {

	zval *_2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL, *dependencyInjector = NULL, *_0, *_1 = NULL, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &params);

	if (!params) {
		params = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injection object is required to access ORM services", "phalcon/mvc/model/manager.zep", 1713);
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
 * Returns the last query created or executed in the models manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getLastQuery) {

	

	RETURN_MEMBER(getThis(), "_lastQuery");

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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *alias_param = NULL, *namespaceName = NULL, *_0, *_1;
	zval *alias = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &alias_param);

	if (UNEXPECTED(Z_TYPE_P(alias_param) != IS_STRING && Z_TYPE_P(alias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(alias_param) == IS_STRING)) {
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
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 9, _2);
	zephir_check_call_status();
	zephir_throw_exception_debug(_1, "phalcon/mvc/model/manager.zep", 1754 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Returns all the registered namespace aliases
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getNamespaceAliases) {

	

	RETURN_MEMBER(getThis(), "_namespaceAliases");

}

/**
 * Destroys the current PHQL cache
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, __destruct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	phalcon_orm_destroy_cache(TSRMLS_C);
	ZEPHIR_CALL_CE_STATIC(NULL, phalcon_mvc_model_query_ce, "clean", &_0, 349);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

zend_object_value zephir_init_properties_Phalcon_Mvc_Model_Manager(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelVisibility"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("_modelVisibility"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

