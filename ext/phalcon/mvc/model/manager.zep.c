
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
 * $di->set('modelsManager', function() {
 *      return new ModelsManager();
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

	zval *dependencyInjector, dependencyInjector_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&dependencyInjector_sub);

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), dependencyInjector);

}

/**
 * Returns the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getDI) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Sets a global events manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setEventsManager) {

	zval *eventsManager, eventsManager_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&eventsManager_sub);

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_zval(this_ptr, SL("_eventsManager"), eventsManager);
	RETURN_THISW();

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getEventsManager) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_eventsManager");

}

/**
 * Sets a custom events manager for a specific model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setCustomEventsManager) {

	zval *model, model_sub, *eventsManager, eventsManager_sub, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&eventsManager_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &eventsManager);



	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, model, 1 TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_customEventsManager"), &_0, eventsManager TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a custom events manager related to a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getCustomEventsManager) {

	zval *model, model_sub, customEventsManager, eventsManager, _0$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&customEventsManager);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	zephir_read_property(&customEventsManager, this_ptr, SL("_customEventsManager"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&customEventsManager) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_get_class(&_0$$3, model, 1 TSRMLS_CC);
		if (zephir_array_isset_fetch(&eventsManager, &customEventsManager, &_0$$3, 1 TSRMLS_CC)) {
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
	zval *model, model_sub, className, eventsManager, _0, _1, _2$$5;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, model, 1 TSRMLS_CC);
	zephir_read_property(&_0, this_ptr, SL("_initialized"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &className)) {
		RETURN_MM_BOOL(0);
	}
	zephir_update_property_array(this_ptr, SL("_initialized"), &className, model TSRMLS_CC);
	if ((zephir_method_exists_ex(model, SL("initialize") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, model, "initialize", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("_lastInitialized"), model);
	zephir_read_property(&_1, this_ptr, SL("_eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_1);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_2$$5);
		ZVAL_STRING(&_2$$5, "modelsManager:afterInitialize");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_2$$5, this_ptr, model);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);

}

/**
 * Check whether a model is already initialized
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, isInitialized) {

	zval *modelName_param = NULL, _0, _1;
	zval modelName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modelName_param);

	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}


	zephir_read_property(&_0, this_ptr, SL("_initialized"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strtolower(&_1, &modelName);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &_1));

}

/**
 * Get last initialized model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getLastInitialized) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_lastInitialized");

}

/**
 * Loads a model throwing an exception if it doesn't exist
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, load) {

	zend_class_entry *_7$$5, *_11$$6;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool newInstance;
	zval *modelName_param = NULL, *newInstance_param = NULL, model, colonPos, namespaceName, namespaceAlias, className, _0, _4, _5, _14, _1$$3, _2$$3, _3$$3, _6$$5, _8$$5, _9$$5, _10$$6, _12$$6, _13$$6;
	zval modelName, _15;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&colonPos);
	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&namespaceAlias);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &modelName_param, &newInstance_param);

	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}
	if (!newInstance_param) {
		newInstance = 0;
	} else {
		newInstance = zephir_get_boolval(newInstance_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, ":");
	ZEPHIR_INIT_VAR(&colonPos);
	zephir_fast_strpos(&colonPos, &modelName, &_0, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&colonPos)) {
		ZVAL_LONG(&_1$$3, (zephir_get_numberval(&colonPos) + 1));
		ZEPHIR_INIT_VAR(&className);
		zephir_substr(&className, &modelName, zephir_get_intval(&_1$$3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZVAL_LONG(&_2$$3, 0);
		ZEPHIR_INIT_VAR(&namespaceAlias);
		zephir_substr(&namespaceAlias, &modelName, 0 , zephir_get_intval(&colonPos), 0);
		ZEPHIR_CALL_METHOD(&namespaceName, this_ptr, "getnamespacealias", NULL, 0, &namespaceAlias);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_VSV(&_3$$3, &namespaceName, "\\", &className);
		zephir_get_strval(&modelName, &_3$$3);
	}
	ZEPHIR_OBS_VAR(&model);
	zephir_read_property(&_4, this_ptr, SL("_initialized"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_5);
	zephir_fast_strtolower(&_5, &modelName);
	if (zephir_array_isset_fetch(&model, &_4, &_5, 0 TSRMLS_CC)) {
		if (newInstance) {
			zephir_fetch_safe_class(&_6$$5, &modelName);
			_7$$5 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_6$$5), Z_STRLEN_P(&_6$$5), ZEND_FETCH_CLASS_AUTO);
			object_init_ex(return_value, _7$$5);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				zephir_read_property(&_8$$5, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
				ZVAL_NULL(&_9$$5);
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_9$$5, &_8$$5, this_ptr);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
		ZEPHIR_CALL_METHOD(NULL, &model, "reset", NULL, 0);
		zephir_check_call_status();
		RETURN_CCTOR(model);
	}
	if (zephir_class_exists(&modelName, 1 TSRMLS_CC)) {
		zephir_fetch_safe_class(&_10$$6, &modelName);
		_11$$6 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_10$$6), Z_STRLEN_P(&_10$$6), ZEND_FETCH_CLASS_AUTO);
		object_init_ex(return_value, _11$$6);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			zephir_read_property(&_12$$6, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
			ZVAL_NULL(&_13$$6);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_13$$6, &_12$$6, this_ptr);
			zephir_check_call_status();
		}
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_14);
	object_init_ex(&_14, phalcon_mvc_model_exception_ce);
	ZEPHIR_INIT_VAR(&_15);
	ZEPHIR_CONCAT_SVS(&_15, "Model '", &modelName, "' could not be loaded");
	ZEPHIR_CALL_METHOD(NULL, &_14, "__construct", NULL, 9, &_15);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_14, "phalcon/mvc/model/manager.zep", 309 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Sets the mapped source for a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setModelSource) {

	zval source;
	zval *model, model_sub, *source_param = NULL, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&source);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &source_param);

	if (unlikely(Z_TYPE_P(source_param) != IS_STRING && Z_TYPE_P(source_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'source' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(source_param) == IS_STRING)) {
		zephir_get_strval(&source, source_param);
	} else {
		ZEPHIR_INIT_VAR(&source);
		ZVAL_EMPTY_STRING(&source);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, model, 1 TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_sources"), &_0, &source TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the mapped source for a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getModelSource) {

	zval *model, model_sub, sources, entityName, source, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&sources);
	ZVAL_UNDEF(&entityName);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_INIT_VAR(&entityName);
	zephir_get_class(&entityName, model, 1 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&sources);
	zephir_read_property(&sources, this_ptr, SL("_sources"), PH_NOISY_CC);
	if (Z_TYPE_P(&sources) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&source);
		if (zephir_array_isset_fetch(&source, &sources, &entityName, 0 TSRMLS_CC)) {
			RETURN_CCTOR(source);
		}
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class_ns(&_0, model, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&source);
	zephir_uncamelize(&source, &_0, NULL  );
	zephir_update_property_array(this_ptr, SL("_sources"), &entityName, &source TSRMLS_CC);
	RETURN_CCTOR(source);

}

/**
 * Sets the mapped schema for a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setModelSchema) {

	zval schema;
	zval *model, model_sub, *schema_param = NULL, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&schema);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &schema_param);

	if (unlikely(Z_TYPE_P(schema_param) != IS_STRING && Z_TYPE_P(schema_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schema' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(schema_param) == IS_STRING)) {
		zephir_get_strval(&schema, schema_param);
	} else {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_EMPTY_STRING(&schema);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, model, 1 TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_schemas"), &_0, &schema TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the mapped schema for a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getModelSchema) {

	zval *model, model_sub, schemas, schema, _0$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&schemas);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	zephir_read_property(&schemas, this_ptr, SL("_schemas"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&schemas) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_get_class(&_0$$3, model, 1 TSRMLS_CC);
		if (zephir_array_isset_fetch(&schema, &schemas, &_0$$3, 1 TSRMLS_CC)) {
			RETURN_CTOR(schema);
		}
	}
	RETURN_MM_STRING("");

}

/**
 * Sets both write and read connection service for a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setConnectionService) {

	zval connectionService;
	zval *model, model_sub, *connectionService_param = NULL, entityName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&entityName);
	ZVAL_UNDEF(&connectionService);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &connectionService_param);

	if (unlikely(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(connectionService_param) == IS_STRING)) {
		zephir_get_strval(&connectionService, connectionService_param);
	} else {
		ZEPHIR_INIT_VAR(&connectionService);
		ZVAL_EMPTY_STRING(&connectionService);
	}


	ZEPHIR_INIT_VAR(&entityName);
	zephir_get_class(&entityName, model, 1 TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_readConnectionServices"), &entityName, &connectionService TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_writeConnectionServices"), &entityName, &connectionService TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets write connection service for a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setWriteConnectionService) {

	zval connectionService;
	zval *model, model_sub, *connectionService_param = NULL, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&connectionService);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &connectionService_param);

	if (unlikely(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(connectionService_param) == IS_STRING)) {
		zephir_get_strval(&connectionService, connectionService_param);
	} else {
		ZEPHIR_INIT_VAR(&connectionService);
		ZVAL_EMPTY_STRING(&connectionService);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, model, 1 TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_writeConnectionServices"), &_0, &connectionService TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets read connection service for a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setReadConnectionService) {

	zval connectionService;
	zval *model, model_sub, *connectionService_param = NULL, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&connectionService);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &connectionService_param);

	if (unlikely(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(connectionService_param) == IS_STRING)) {
		zephir_get_strval(&connectionService, connectionService_param);
	} else {
		ZEPHIR_INIT_VAR(&connectionService);
		ZVAL_EMPTY_STRING(&connectionService);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, model, 1 TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_readConnectionServices"), &_0, &connectionService TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the connection to read data related to a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getReadConnection) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	zephir_read_property(&_0, this_ptr, SL("_readConnectionServices"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getconnection", NULL, 0, model, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the connection to write data related to a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getWriteConnection) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	zephir_read_property(&_0, this_ptr, SL("_writeConnectionServices"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getconnection", NULL, 0, model, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the connection to read or write data related to a model depending on the connection services.
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, _getConnection) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, *connectionServices, connectionServices_sub, dependencyInjector, service, connection, _1, _0$$3, _2$$5, _3$$6, _4$$6;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&connectionServices_sub);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &connectionServices);



	ZEPHIR_INIT_VAR(&service);
	ZVAL_NULL(&service);
	if (Z_TYPE_P(connectionServices) == IS_ARRAY) {
		ZEPHIR_OBS_NVAR(&service);
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_get_class(&_0$$3, model, 1 TSRMLS_CC);
		zephir_array_isset_fetch(&service, connectionServices, &_0$$3, 0 TSRMLS_CC);
	}
	zephir_read_property(&_1, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dependencyInjector, &_1);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM", "phalcon/mvc/model/manager.zep", 423);
		return;
	}
	ZEPHIR_INIT_VAR(&connection);
	if (zephir_is_true(&service)) {
		ZEPHIR_CALL_METHOD(&_2$$5, &dependencyInjector, "getshared", NULL, 0, &service);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&connection, &_2$$5);
	} else {
		ZEPHIR_INIT_VAR(&_4$$6);
		ZVAL_STRING(&_4$$6, "db");
		ZEPHIR_CALL_METHOD(&_3$$6, &dependencyInjector, "getshared", NULL, 0, &_4$$6);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&connection, &_3$$6);
	}
	if (Z_TYPE_P(&connection) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid injected connection service", "phalcon/mvc/model/manager.zep", 436);
		return;
	}
	RETURN_CCTOR(connection);

}

/**
 * Returns the connection service name used to read data related to a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getReadConnectionService) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	zephir_read_property(&_0, this_ptr, SL("_readConnectionServices"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getconnectionservice", NULL, 0, model, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the connection service name used to write data related to a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getWriteConnectionService) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	zephir_read_property(&_0, this_ptr, SL("_writeConnectionServices"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getconnectionservice", NULL, 0, model, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the connection service name used to read or write data related to a model depending on the connection services
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, _getConnectionService) {

	zval *model, model_sub, *connectionServices, connectionServices_sub, connection, _0$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&connectionServices_sub);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &connectionServices);



	if (Z_TYPE_P(connectionServices) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_get_class(&_0$$3, model, 1 TSRMLS_CC);
		if (zephir_array_isset_fetch(&connection, connectionServices, &_0$$3, 1 TSRMLS_CC)) {
			RETURN_CTOR(connection);
		}
	}
	RETURN_MM_STRING("db");

}

/**
 * Receives events generated in the models and dispatches them to a events-manager if available
 * Notify the behaviors that are listening in the model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, notifyEvent) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *eventName_param = NULL, *model, model_sub, status, behavior, modelsBehaviors, eventsManager, customEventsManager, behaviors, _0$$3, *_1$$4, _3$$9;
	zval eventName, _2$$7, _4$$10;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_4$$10);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&behavior);
	ZVAL_UNDEF(&modelsBehaviors);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&customEventsManager);
	ZVAL_UNDEF(&behaviors);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &eventName_param, &model);

	if (unlikely(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(eventName_param) == IS_STRING)) {
		zephir_get_strval(&eventName, eventName_param);
	} else {
		ZEPHIR_INIT_VAR(&eventName);
		ZVAL_EMPTY_STRING(&eventName);
	}


	ZEPHIR_INIT_VAR(&status);
	ZVAL_NULL(&status);
	ZEPHIR_OBS_VAR(&behaviors);
	zephir_read_property(&behaviors, this_ptr, SL("_behaviors"), PH_NOISY_CC);
	if (Z_TYPE_P(&behaviors) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&modelsBehaviors);
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_get_class(&_0$$3, model, 1 TSRMLS_CC);
		if (zephir_array_isset_fetch(&modelsBehaviors, &behaviors, &_0$$3, 0 TSRMLS_CC)) {
			zephir_is_iterable(&modelsBehaviors, 0, "phalcon/mvc/model/manager.zep", 501);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&modelsBehaviors), _1$$4)
			{
				ZEPHIR_INIT_NVAR(&behavior);
				ZVAL_COPY(&behavior, _1$$4);
				ZEPHIR_CALL_METHOD(&status, &behavior, "notify", NULL, 0, &eventName, model);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
					RETURN_MM_BOOL(0);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&behavior);
		}
	}
	ZEPHIR_OBS_VAR(&eventsManager);
	zephir_read_property(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_2$$7);
		ZEPHIR_CONCAT_SV(&_2$$7, "model:", &eventName);
		ZEPHIR_CALL_METHOD(&status, &eventsManager, "fire", NULL, 0, &_2$$7, model);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
			RETURN_CCTOR(status);
		}
	}
	ZEPHIR_OBS_VAR(&customEventsManager);
	zephir_read_property(&customEventsManager, this_ptr, SL("_customEventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(&customEventsManager) == IS_ARRAY) {
		ZEPHIR_OBS_NVAR(&customEventsManager);
		ZEPHIR_INIT_VAR(&_3$$9);
		zephir_get_class(&_3$$9, model, 1 TSRMLS_CC);
		if (zephir_array_isset_fetch(&customEventsManager, &customEventsManager, &_3$$9, 0 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(&_4$$10);
			ZEPHIR_CONCAT_SV(&_4$$10, "model:", &eventName);
			ZEPHIR_CALL_METHOD(&status, &customEventsManager, "fire", NULL, 0, &_4$$10, model);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
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
	zval eventName, _2$$7;
	zval *model, model_sub, *eventName_param = NULL, *data, data_sub, behaviors, modelsBehaviors, result, eventsManager, behavior, _0$$3, *_1$$4;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&behaviors);
	ZVAL_UNDEF(&modelsBehaviors);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&behavior);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&_2$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &model, &eventName_param, &data);

	if (unlikely(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(eventName_param) == IS_STRING)) {
		zephir_get_strval(&eventName, eventName_param);
	} else {
		ZEPHIR_INIT_VAR(&eventName);
		ZVAL_EMPTY_STRING(&eventName);
	}


	ZEPHIR_OBS_VAR(&behaviors);
	zephir_read_property(&behaviors, this_ptr, SL("_behaviors"), PH_NOISY_CC);
	if (Z_TYPE_P(&behaviors) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&modelsBehaviors);
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_get_class(&_0$$3, model, 1 TSRMLS_CC);
		if (zephir_array_isset_fetch(&modelsBehaviors, &behaviors, &_0$$3, 0 TSRMLS_CC)) {
			zephir_is_iterable(&modelsBehaviors, 0, "phalcon/mvc/model/manager.zep", 557);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&modelsBehaviors), _1$$4)
			{
				ZEPHIR_INIT_NVAR(&behavior);
				ZVAL_COPY(&behavior, _1$$4);
				ZEPHIR_CALL_METHOD(&result, &behavior, "missingmethod", NULL, 0, model, &eventName, data);
				zephir_check_call_status();
				if (Z_TYPE_P(&result) != IS_NULL) {
					RETURN_CCTOR(result);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&behavior);
		}
	}
	ZEPHIR_OBS_VAR(&eventsManager);
	zephir_read_property(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_2$$7);
		ZEPHIR_CONCAT_SV(&_2$$7, "model:", &eventName);
		ZEPHIR_RETURN_CALL_METHOD(&eventsManager, "fire", NULL, 0, &_2$$7, model, data);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_NULL();

}

/**
 * Binds a behavior to a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, addBehavior) {

	zval *model, model_sub, *behavior, behavior_sub, entityName, modelsBehaviors, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&behavior_sub);
	ZVAL_UNDEF(&entityName);
	ZVAL_UNDEF(&modelsBehaviors);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &behavior);



	ZEPHIR_INIT_VAR(&entityName);
	zephir_get_class(&entityName, model, 1 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&modelsBehaviors);
	zephir_read_property(&_0, this_ptr, SL("_behaviors"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&modelsBehaviors, &_0, &entityName, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(&modelsBehaviors);
		array_init(&modelsBehaviors);
	}
	zephir_array_append(&modelsBehaviors, behavior, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 590);
	zephir_update_property_array(this_ptr, SL("_behaviors"), &entityName, &modelsBehaviors TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets if a model must keep snapshots
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, keepSnapshots) {

	zend_bool keepSnapshots;
	zval *model, model_sub, *keepSnapshots_param = NULL, _0, _1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &keepSnapshots_param);

	keepSnapshots = zephir_get_boolval(keepSnapshots_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, model, 1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_BOOL(&_1, keepSnapshots);
	zephir_update_property_array(this_ptr, SL("_keepSnapshots"), &_0, &_1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if a model is keeping snapshots for the queried records
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, isKeepingSnapshots) {

	zval *model, model_sub, keepSnapshots, isKeeping, _0$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&keepSnapshots);
	ZVAL_UNDEF(&isKeeping);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	zephir_read_property(&keepSnapshots, this_ptr, SL("_keepSnapshots"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&keepSnapshots) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_get_class(&_0$$3, model, 1 TSRMLS_CC);
		if (zephir_array_isset_fetch(&isKeeping, &keepSnapshots, &_0$$3, 1 TSRMLS_CC)) {
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
	zval *model, model_sub, *dynamicUpdate_param = NULL, entityName, _0, _1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&entityName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &dynamicUpdate_param);

	dynamicUpdate = zephir_get_boolval(dynamicUpdate_param);


	ZEPHIR_INIT_VAR(&entityName);
	zephir_get_class(&entityName, model, 1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_BOOL(&_0, dynamicUpdate);
	zephir_update_property_array(this_ptr, SL("_dynamicUpdate"), &entityName, &_0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_BOOL(&_1, dynamicUpdate);
	zephir_update_property_array(this_ptr, SL("_keepSnapshots"), &entityName, &_1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if a model is using dynamic update instead of all-field update
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, isUsingDynamicUpdate) {

	zval *model, model_sub, dynamicUpdate, isUsing, _0$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&dynamicUpdate);
	ZVAL_UNDEF(&isUsing);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	zephir_read_property(&dynamicUpdate, this_ptr, SL("_dynamicUpdate"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&dynamicUpdate) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_get_class(&_0$$3, model, 1 TSRMLS_CC);
		if (zephir_array_isset_fetch(&isUsing, &dynamicUpdate, &_0$$3, 1 TSRMLS_CC)) {
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
	zval referencedModel;
	zval *model, model_sub, *fields, fields_sub, *referencedModel_param = NULL, *referencedFields, referencedFields_sub, *options = NULL, options_sub, __$null, entityName, referencedEntity, relation, keyRelation, relations, alias, lowerAlias, singleRelations, _0, _1, _2;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&entityName);
	ZVAL_UNDEF(&referencedEntity);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&keyRelation);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&lowerAlias);
	ZVAL_UNDEF(&singleRelations);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&referencedModel);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &model, &fields, &referencedModel_param, &referencedFields, &options);

	if (unlikely(Z_TYPE_P(referencedModel_param) != IS_STRING && Z_TYPE_P(referencedModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referencedModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(referencedModel_param) == IS_STRING)) {
		zephir_get_strval(&referencedModel, referencedModel_param);
	} else {
		ZEPHIR_INIT_VAR(&referencedModel);
		ZVAL_EMPTY_STRING(&referencedModel);
	}
	if (!options) {
		options = &options_sub;
		options = &__$null;
	}


	ZEPHIR_INIT_VAR(&entityName);
	zephir_get_class(&entityName, model, 1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&referencedEntity);
	zephir_fast_strtolower(&referencedEntity, &referencedModel);
	ZEPHIR_INIT_VAR(&keyRelation);
	ZEPHIR_CONCAT_VSV(&keyRelation, &entityName, "$", &referencedEntity);
	ZEPHIR_OBS_VAR(&relations);
	zephir_read_property(&_0, this_ptr, SL("_hasOne"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&relations, &_0, &keyRelation, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(&relations);
		array_init(&relations);
	}
	if (Z_TYPE_P(referencedFields) == IS_ARRAY) {
		if (zephir_fast_count_int(fields TSRMLS_CC) != zephir_fast_count_int(referencedFields TSRMLS_CC)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same", "phalcon/mvc/model/manager.zep", 677);
			return;
		}
	}
	ZEPHIR_INIT_VAR(&relation);
	object_init_ex(&relation, phalcon_mvc_model_relation_ce);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_METHOD(NULL, &relation, "__construct", NULL, 327, &_1, &referencedModel, fields, referencedFields, options);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&alias);
	if (zephir_array_isset_string_fetch(&alias, options, SL("alias"), 0)) {
		if (Z_TYPE_P(&alias) != IS_STRING) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Relation alias must be a string", "phalcon/mvc/model/manager.zep", 697);
			return;
		}
		ZEPHIR_INIT_VAR(&lowerAlias);
		zephir_fast_strtolower(&lowerAlias, &alias);
	} else {
		ZEPHIR_CPY_WRT(&lowerAlias, &referencedEntity);
	}
	zephir_array_append(&relations, &relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 709);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VSV(&_2, &entityName, "$", &lowerAlias);
	zephir_update_property_array(this_ptr, SL("_aliases"), &_2, &relation TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_hasOne"), &keyRelation, &relations TSRMLS_CC);
	ZEPHIR_OBS_VAR(&singleRelations);
	zephir_read_property(&_1, this_ptr, SL("_hasOneSingle"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&singleRelations, &_1, &entityName, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(&singleRelations);
		array_init(&singleRelations);
	}
	zephir_array_append(&singleRelations, &relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 723);
	zephir_update_property_array(this_ptr, SL("_hasOneSingle"), &entityName, &singleRelations TSRMLS_CC);
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
	zval referencedModel;
	zval *model, model_sub, *fields, fields_sub, *referencedModel_param = NULL, *referencedFields, referencedFields_sub, *options = NULL, options_sub, __$null, entityName, referencedEntity, relation, keyRelation, relations, alias, lowerAlias, singleRelations, _0, _1, _2;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&entityName);
	ZVAL_UNDEF(&referencedEntity);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&keyRelation);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&lowerAlias);
	ZVAL_UNDEF(&singleRelations);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&referencedModel);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &model, &fields, &referencedModel_param, &referencedFields, &options);

	if (unlikely(Z_TYPE_P(referencedModel_param) != IS_STRING && Z_TYPE_P(referencedModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referencedModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(referencedModel_param) == IS_STRING)) {
		zephir_get_strval(&referencedModel, referencedModel_param);
	} else {
		ZEPHIR_INIT_VAR(&referencedModel);
		ZVAL_EMPTY_STRING(&referencedModel);
	}
	if (!options) {
		options = &options_sub;
		options = &__$null;
	}


	ZEPHIR_INIT_VAR(&entityName);
	zephir_get_class(&entityName, model, 1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&referencedEntity);
	zephir_fast_strtolower(&referencedEntity, &referencedModel);
	ZEPHIR_INIT_VAR(&keyRelation);
	ZEPHIR_CONCAT_VSV(&keyRelation, &entityName, "$", &referencedEntity);
	ZEPHIR_OBS_VAR(&relations);
	zephir_read_property(&_0, this_ptr, SL("_belongsTo"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&relations, &_0, &keyRelation, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(&relations);
		array_init(&relations);
	}
	if (Z_TYPE_P(referencedFields) == IS_ARRAY) {
		if (zephir_fast_count_int(fields TSRMLS_CC) != zephir_fast_count_int(referencedFields TSRMLS_CC)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same", "phalcon/mvc/model/manager.zep", 762);
			return;
		}
	}
	ZEPHIR_INIT_VAR(&relation);
	object_init_ex(&relation, phalcon_mvc_model_relation_ce);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_METHOD(NULL, &relation, "__construct", NULL, 327, &_1, &referencedModel, fields, referencedFields, options);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&alias);
	if (zephir_array_isset_string_fetch(&alias, options, SL("alias"), 0)) {
		if (Z_TYPE_P(&alias) != IS_STRING) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Relation alias must be a string", "phalcon/mvc/model/manager.zep", 782);
			return;
		}
		ZEPHIR_INIT_VAR(&lowerAlias);
		zephir_fast_strtolower(&lowerAlias, &alias);
	} else {
		ZEPHIR_CPY_WRT(&lowerAlias, &referencedEntity);
	}
	zephir_array_append(&relations, &relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 794);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VSV(&_2, &entityName, "$", &lowerAlias);
	zephir_update_property_array(this_ptr, SL("_aliases"), &_2, &relation TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_belongsTo"), &keyRelation, &relations TSRMLS_CC);
	ZEPHIR_OBS_VAR(&singleRelations);
	zephir_read_property(&_1, this_ptr, SL("_belongsToSingle"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&singleRelations, &_1, &entityName, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(&singleRelations);
		array_init(&singleRelations);
	}
	zephir_array_append(&singleRelations, &relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 808);
	zephir_update_property_array(this_ptr, SL("_belongsToSingle"), &entityName, &singleRelations TSRMLS_CC);
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
	zval referencedModel;
	zval *model, model_sub, *fields, fields_sub, *referencedModel_param = NULL, *referencedFields, referencedFields_sub, *options = NULL, options_sub, __$null, entityName, referencedEntity, hasMany, relation, keyRelation, relations, alias, lowerAlias, singleRelations, _0, _1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&entityName);
	ZVAL_UNDEF(&referencedEntity);
	ZVAL_UNDEF(&hasMany);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&keyRelation);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&lowerAlias);
	ZVAL_UNDEF(&singleRelations);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&referencedModel);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &model, &fields, &referencedModel_param, &referencedFields, &options);

	if (unlikely(Z_TYPE_P(referencedModel_param) != IS_STRING && Z_TYPE_P(referencedModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referencedModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(referencedModel_param) == IS_STRING)) {
		zephir_get_strval(&referencedModel, referencedModel_param);
	} else {
		ZEPHIR_INIT_VAR(&referencedModel);
		ZVAL_EMPTY_STRING(&referencedModel);
	}
	if (!options) {
		options = &options_sub;
		options = &__$null;
	}


	ZEPHIR_INIT_VAR(&entityName);
	zephir_get_class(&entityName, model, 1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&referencedEntity);
	zephir_fast_strtolower(&referencedEntity, &referencedModel);
	ZEPHIR_INIT_VAR(&keyRelation);
	ZEPHIR_CONCAT_VSV(&keyRelation, &entityName, "$", &referencedEntity);
	ZEPHIR_OBS_VAR(&hasMany);
	zephir_read_property(&hasMany, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&relations);
	if (!(zephir_array_isset_fetch(&relations, &hasMany, &keyRelation, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(&relations);
		array_init(&relations);
	}
	if (Z_TYPE_P(referencedFields) == IS_ARRAY) {
		if (zephir_fast_count_int(fields TSRMLS_CC) != zephir_fast_count_int(referencedFields TSRMLS_CC)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same", "phalcon/mvc/model/manager.zep", 847);
			return;
		}
	}
	ZEPHIR_INIT_VAR(&relation);
	object_init_ex(&relation, phalcon_mvc_model_relation_ce);
	ZVAL_LONG(&_0, 2);
	ZEPHIR_CALL_METHOD(NULL, &relation, "__construct", NULL, 327, &_0, &referencedModel, fields, referencedFields, options);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&alias);
	if (zephir_array_isset_string_fetch(&alias, options, SL("alias"), 0)) {
		if (Z_TYPE_P(&alias) != IS_STRING) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Relation alias must be a string", "phalcon/mvc/model/manager.zep", 867);
			return;
		}
		ZEPHIR_INIT_VAR(&lowerAlias);
		zephir_fast_strtolower(&lowerAlias, &alias);
	} else {
		ZEPHIR_CPY_WRT(&lowerAlias, &referencedEntity);
	}
	zephir_array_append(&relations, &relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 879);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VSV(&_1, &entityName, "$", &lowerAlias);
	zephir_update_property_array(this_ptr, SL("_aliases"), &_1, &relation TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_hasMany"), &keyRelation, &relations TSRMLS_CC);
	ZEPHIR_OBS_VAR(&singleRelations);
	zephir_read_property(&_0, this_ptr, SL("_hasManySingle"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&singleRelations, &_0, &entityName, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(&singleRelations);
		array_init(&singleRelations);
	}
	zephir_array_append(&singleRelations, &relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 893);
	zephir_update_property_array(this_ptr, SL("_hasManySingle"), &entityName, &singleRelations TSRMLS_CC);
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
	zval intermediateModel, referencedModel;
	zval *model, model_sub, *fields, fields_sub, *intermediateModel_param = NULL, *intermediateFields, intermediateFields_sub, *intermediateReferencedFields, intermediateReferencedFields_sub, *referencedModel_param = NULL, *referencedFields, referencedFields_sub, *options = NULL, options_sub, __$null, entityName, referencedEntity, hasManyToMany, relation, keyRelation, relations, alias, lowerAlias, singleRelations, intermediateEntity, _0, _1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&intermediateFields_sub);
	ZVAL_UNDEF(&intermediateReferencedFields_sub);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&entityName);
	ZVAL_UNDEF(&referencedEntity);
	ZVAL_UNDEF(&hasManyToMany);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&keyRelation);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&lowerAlias);
	ZVAL_UNDEF(&singleRelations);
	ZVAL_UNDEF(&intermediateEntity);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&intermediateModel);
	ZVAL_UNDEF(&referencedModel);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 7, 1, &model, &fields, &intermediateModel_param, &intermediateFields, &intermediateReferencedFields, &referencedModel_param, &referencedFields, &options);

	if (unlikely(Z_TYPE_P(intermediateModel_param) != IS_STRING && Z_TYPE_P(intermediateModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'intermediateModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(intermediateModel_param) == IS_STRING)) {
		zephir_get_strval(&intermediateModel, intermediateModel_param);
	} else {
		ZEPHIR_INIT_VAR(&intermediateModel);
		ZVAL_EMPTY_STRING(&intermediateModel);
	}
	if (unlikely(Z_TYPE_P(referencedModel_param) != IS_STRING && Z_TYPE_P(referencedModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referencedModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(referencedModel_param) == IS_STRING)) {
		zephir_get_strval(&referencedModel, referencedModel_param);
	} else {
		ZEPHIR_INIT_VAR(&referencedModel);
		ZVAL_EMPTY_STRING(&referencedModel);
	}
	if (!options) {
		options = &options_sub;
		options = &__$null;
	}


	ZEPHIR_INIT_VAR(&entityName);
	zephir_get_class(&entityName, model, 1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&intermediateEntity);
	zephir_fast_strtolower(&intermediateEntity, &intermediateModel);
	ZEPHIR_INIT_VAR(&referencedEntity);
	zephir_fast_strtolower(&referencedEntity, &referencedModel);
	ZEPHIR_INIT_VAR(&keyRelation);
	ZEPHIR_CONCAT_VSV(&keyRelation, &entityName, "$", &referencedEntity);
	ZEPHIR_OBS_VAR(&hasManyToMany);
	zephir_read_property(&hasManyToMany, this_ptr, SL("_hasManyToMany"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&relations);
	if (!(zephir_array_isset_fetch(&relations, &hasManyToMany, &keyRelation, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(&relations);
		array_init(&relations);
	}
	if (Z_TYPE_P(intermediateFields) == IS_ARRAY) {
		if (zephir_fast_count_int(fields TSRMLS_CC) != zephir_fast_count_int(intermediateFields TSRMLS_CC)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same", "phalcon/mvc/model/manager.zep", 937);
			return;
		}
	}
	if (Z_TYPE_P(intermediateReferencedFields) == IS_ARRAY) {
		if (zephir_fast_count_int(fields TSRMLS_CC) != zephir_fast_count_int(intermediateFields TSRMLS_CC)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same", "phalcon/mvc/model/manager.zep", 946);
			return;
		}
	}
	ZEPHIR_INIT_VAR(&relation);
	object_init_ex(&relation, phalcon_mvc_model_relation_ce);
	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_METHOD(NULL, &relation, "__construct", NULL, 327, &_0, &referencedModel, fields, referencedFields, options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &relation, "setintermediaterelation", NULL, 328, intermediateFields, &intermediateModel, intermediateReferencedFields);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&alias);
	if (zephir_array_isset_string_fetch(&alias, options, SL("alias"), 0)) {
		if (Z_TYPE_P(&alias) != IS_STRING) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Relation alias must be a string", "phalcon/mvc/model/manager.zep", 971);
			return;
		}
		ZEPHIR_INIT_VAR(&lowerAlias);
		zephir_fast_strtolower(&lowerAlias, &alias);
	} else {
		ZEPHIR_CPY_WRT(&lowerAlias, &referencedEntity);
	}
	zephir_array_append(&relations, &relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 981);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VSV(&_1, &entityName, "$", &lowerAlias);
	zephir_update_property_array(this_ptr, SL("_aliases"), &_1, &relation TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_hasManyToMany"), &keyRelation, &relations TSRMLS_CC);
	ZEPHIR_OBS_VAR(&singleRelations);
	zephir_read_property(&_0, this_ptr, SL("_hasManyToManySingle"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&singleRelations, &_0, &entityName, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(&singleRelations);
		array_init(&singleRelations);
	}
	zephir_array_append(&singleRelations, &relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1003);
	zephir_update_property_array(this_ptr, SL("_hasManyToManySingle"), &entityName, &singleRelations TSRMLS_CC);
	RETURN_CCTOR(relation);

}

/**
 * Checks whether a model has a belongsTo relation with another model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsBelongsTo) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *modelName_param = NULL, *modelRelation_param = NULL, entityName, keyRelation, _0, _1, _2;
	zval modelName, modelRelation;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&modelRelation);
	ZVAL_UNDEF(&entityName);
	ZVAL_UNDEF(&keyRelation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &modelRelation_param);

	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}
	if (unlikely(Z_TYPE_P(modelRelation_param) != IS_STRING && Z_TYPE_P(modelRelation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelRelation' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(modelRelation_param) == IS_STRING)) {
		zephir_get_strval(&modelRelation, modelRelation_param);
	} else {
		ZEPHIR_INIT_VAR(&modelRelation);
		ZVAL_EMPTY_STRING(&modelRelation);
	}


	ZEPHIR_INIT_VAR(&entityName);
	zephir_fast_strtolower(&entityName, &modelName);
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, &modelRelation);
	ZEPHIR_INIT_VAR(&keyRelation);
	ZEPHIR_CONCAT_VSV(&keyRelation, &entityName, "$", &_0);
	zephir_read_property(&_1, this_ptr, SL("_initialized"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_1, &entityName))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 0, &modelName);
		zephir_check_call_status();
	}
	zephir_read_property(&_2, this_ptr, SL("_belongsTo"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_2, &keyRelation));

}

/**
 * Checks whether a model has a hasMany relation with another model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasMany) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *modelName_param = NULL, *modelRelation_param = NULL, entityName, keyRelation, _0, _1, _2;
	zval modelName, modelRelation;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&modelRelation);
	ZVAL_UNDEF(&entityName);
	ZVAL_UNDEF(&keyRelation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &modelRelation_param);

	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}
	if (unlikely(Z_TYPE_P(modelRelation_param) != IS_STRING && Z_TYPE_P(modelRelation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelRelation' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(modelRelation_param) == IS_STRING)) {
		zephir_get_strval(&modelRelation, modelRelation_param);
	} else {
		ZEPHIR_INIT_VAR(&modelRelation);
		ZVAL_EMPTY_STRING(&modelRelation);
	}


	ZEPHIR_INIT_VAR(&entityName);
	zephir_fast_strtolower(&entityName, &modelName);
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, &modelRelation);
	ZEPHIR_INIT_VAR(&keyRelation);
	ZEPHIR_CONCAT_VSV(&keyRelation, &entityName, "$", &_0);
	zephir_read_property(&_1, this_ptr, SL("_initialized"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_1, &entityName))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 0, &modelName);
		zephir_check_call_status();
	}
	zephir_read_property(&_2, this_ptr, SL("_hasMany"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_2, &keyRelation));

}

/**
 * Checks whether a model has a hasOne relation with another model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasOne) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *modelName_param = NULL, *modelRelation_param = NULL, entityName, keyRelation, _0, _1, _2;
	zval modelName, modelRelation;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&modelRelation);
	ZVAL_UNDEF(&entityName);
	ZVAL_UNDEF(&keyRelation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &modelRelation_param);

	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}
	if (unlikely(Z_TYPE_P(modelRelation_param) != IS_STRING && Z_TYPE_P(modelRelation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelRelation' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(modelRelation_param) == IS_STRING)) {
		zephir_get_strval(&modelRelation, modelRelation_param);
	} else {
		ZEPHIR_INIT_VAR(&modelRelation);
		ZVAL_EMPTY_STRING(&modelRelation);
	}


	ZEPHIR_INIT_VAR(&entityName);
	zephir_fast_strtolower(&entityName, &modelName);
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, &modelRelation);
	ZEPHIR_INIT_VAR(&keyRelation);
	ZEPHIR_CONCAT_VSV(&keyRelation, &entityName, "$", &_0);
	zephir_read_property(&_1, this_ptr, SL("_initialized"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_1, &entityName))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 0, &modelName);
		zephir_check_call_status();
	}
	zephir_read_property(&_2, this_ptr, SL("_hasOne"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_2, &keyRelation));

}

/**
 * Checks whether a model has a hasManyToMany relation with another model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasManyToMany) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *modelName_param = NULL, *modelRelation_param = NULL, entityName, keyRelation, _0, _1, _2;
	zval modelName, modelRelation;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&modelRelation);
	ZVAL_UNDEF(&entityName);
	ZVAL_UNDEF(&keyRelation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &modelRelation_param);

	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}
	if (unlikely(Z_TYPE_P(modelRelation_param) != IS_STRING && Z_TYPE_P(modelRelation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelRelation' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(modelRelation_param) == IS_STRING)) {
		zephir_get_strval(&modelRelation, modelRelation_param);
	} else {
		ZEPHIR_INIT_VAR(&modelRelation);
		ZVAL_EMPTY_STRING(&modelRelation);
	}


	ZEPHIR_INIT_VAR(&entityName);
	zephir_fast_strtolower(&entityName, &modelName);
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, &modelRelation);
	ZEPHIR_INIT_VAR(&keyRelation);
	ZEPHIR_CONCAT_VSV(&keyRelation, &entityName, "$", &_0);
	zephir_read_property(&_1, this_ptr, SL("_initialized"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_1, &entityName))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 0, &modelName);
		zephir_check_call_status();
	}
	zephir_read_property(&_2, this_ptr, SL("_hasManyToMany"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_2, &keyRelation));

}

/**
 * Returns a relation by its alias
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationByAlias) {

	zval *modelName_param = NULL, *alias_param = NULL, aliases, relation, _0$$3;
	zval modelName, alias, _1$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&aliases);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &alias_param);

	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}
	if (unlikely(Z_TYPE_P(alias_param) != IS_STRING && Z_TYPE_P(alias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(alias_param) == IS_STRING)) {
		zephir_get_strval(&alias, alias_param);
	} else {
		ZEPHIR_INIT_VAR(&alias);
		ZVAL_EMPTY_STRING(&alias);
	}


	zephir_read_property(&aliases, this_ptr, SL("_aliases"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&aliases) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_VSV(&_1$$3, &modelName, "$", &alias);
		zephir_fast_strtolower(&_0$$3, &_1$$3);
		if (zephir_array_isset_fetch(&relation, &aliases, &_0$$3, 1 TSRMLS_CC)) {
			RETURN_CTOR(relation);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Merge two arrays of find parameters
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, _mergeFindParameters) {

	zend_string *_4$$4, *_10$$11;
	zend_ulong _3$$4, _9$$11;
	zend_bool _0, _5$$5, _11$$12, _14$$12;
	zval *findParamsOne, findParamsOne_sub, *findParamsTwo, findParamsTwo_sub, key, value, findParams, _1$$3, *_2$$4, _6$$8, _7$$8, *_8$$11, _12$$15, _13$$15, _15$$20, _16$$20, _17$$24, _18$$24;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&findParamsOne_sub);
	ZVAL_UNDEF(&findParamsTwo_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&findParams);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_12$$15);
	ZVAL_UNDEF(&_13$$15);
	ZVAL_UNDEF(&_15$$20);
	ZVAL_UNDEF(&_16$$20);
	ZVAL_UNDEF(&_17$$24);
	ZVAL_UNDEF(&_18$$24);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &findParamsOne, &findParamsTwo);



	_0 = Z_TYPE_P(findParamsOne) == IS_STRING;
	if (_0) {
		_0 = Z_TYPE_P(findParamsTwo) == IS_STRING;
	}
	if (_0) {
		zephir_create_array(return_value, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_SVSV(&_1$$3, "(", findParamsOne, ") AND ", findParamsTwo);
		zephir_array_fast_append(return_value, &_1$$3);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&findParams);
	array_init(&findParams);
	if (Z_TYPE_P(findParamsOne) == IS_ARRAY) {
		zephir_is_iterable(findParamsOne, 0, "phalcon/mvc/model/manager.zep", 1151);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(findParamsOne), _3$$4, _4$$4, _2$$4)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4$$4 != NULL) { 
				ZVAL_STR_COPY(&key, _4$$4);
			} else {
				ZVAL_LONG(&key, _3$$4);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _2$$4);
			_5$$5 = ZEPHIR_IS_LONG_IDENTICAL(&key, 0);
			if (!(_5$$5)) {
				_5$$5 = ZEPHIR_IS_STRING_IDENTICAL(&key, "conditions");
			}
			if (_5$$5) {
				if (!(zephir_array_isset_long(&findParams, 0))) {
					zephir_array_update_long(&findParams, 0, &value, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
				} else {
					zephir_array_fetch_long(&_6$$8, &findParams, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1144 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_7$$8);
					ZEPHIR_CONCAT_SVSV(&_7$$8, "(", &_6$$8, ") AND ", &value);
					zephir_array_update_long(&findParams, 0, &_7$$8, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
				}
				continue;
			}
			zephir_array_update_zval(&findParams, &key, &value, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		if (Z_TYPE_P(findParamsOne) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&findParams);
			zephir_create_array(&findParams, 1, 0 TSRMLS_CC);
			zephir_array_update_string(&findParams, SL("conditions"), findParamsOne, PH_COPY | PH_SEPARATE);
		}
	}
	if (Z_TYPE_P(findParamsTwo) == IS_ARRAY) {
		zephir_is_iterable(findParamsTwo, 0, "phalcon/mvc/model/manager.zep", 1185);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(findParamsTwo), _9$$11, _10$$11, _8$$11)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_10$$11 != NULL) { 
				ZVAL_STR_COPY(&key, _10$$11);
			} else {
				ZVAL_LONG(&key, _9$$11);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _8$$11);
			_11$$12 = ZEPHIR_IS_LONG_IDENTICAL(&key, 0);
			if (!(_11$$12)) {
				_11$$12 = ZEPHIR_IS_STRING_IDENTICAL(&key, "conditions");
			}
			if (_11$$12) {
				if (!(zephir_array_isset_long(&findParams, 0))) {
					zephir_array_update_long(&findParams, 0, &value, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
				} else {
					zephir_array_fetch_long(&_12$$15, &findParams, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1165 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_13$$15);
					ZEPHIR_CONCAT_SVSV(&_13$$15, "(", &_12$$15, ") AND ", &value);
					zephir_array_update_long(&findParams, 0, &_13$$15, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
				}
				continue;
			}
			_14$$12 = ZEPHIR_IS_STRING_IDENTICAL(&key, "bind");
			if (!(_14$$12)) {
				_14$$12 = ZEPHIR_IS_STRING_IDENTICAL(&key, "bindTypes");
			}
			if (_14$$12) {
				if (!(zephir_array_isset(&findParams, &key))) {
					if (Z_TYPE_P(&value) == IS_ARRAY) {
						zephir_array_update_zval(&findParams, &key, &value, PH_COPY | PH_SEPARATE);
					}
				} else {
					if (Z_TYPE_P(&value) == IS_ARRAY) {
						ZEPHIR_INIT_NVAR(&_15$$20);
						zephir_array_fetch(&_16$$20, &findParams, &key, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1177 TSRMLS_CC);
						zephir_fast_array_merge(&_15$$20, &_16$$20, &value TSRMLS_CC);
						zephir_array_update_zval(&findParams, &key, &_15$$20, PH_COPY | PH_SEPARATE);
					}
				}
				continue;
			}
			zephir_array_update_zval(&findParams, &key, &value, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		if (Z_TYPE_P(findParamsTwo) == IS_STRING) {
			if (!(zephir_array_isset_long(&findParams, 0))) {
				zephir_array_update_long(&findParams, 0, findParamsTwo, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
			} else {
				zephir_array_fetch_long(&_17$$24, &findParams, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1190 TSRMLS_CC);
				ZEPHIR_INIT_VAR(&_18$$24);
				ZEPHIR_CONCAT_SVSV(&_18$$24, "(", &_17$$24, ") AND ", findParamsTwo);
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

	zend_string *_19$$10;
	zend_ulong _18$$10;
	zval _29;
	zend_bool reusable = 0, _28$$19;
	zephir_fcall_cache_entry *_6 = NULL, *_23 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval method;
	zval *relation, relation_sub, *method_param = NULL, *record, record_sub, *parameters = NULL, parameters_sub, __$null, placeholders, referencedModel, intermediateModel, intermediateFields, joinConditions, fields, builder, extraParameters, conditions, refPosition, field, referencedFields, findParams, findArguments, retrieveMethod, uniqueKey, records, arguments, rows, firstRow, _0, _25, _26, _1$$4, _2$$4, _3$$6, _4$$6, _5$$3, _7$$3, _8$$3, _12$$3, _9$$8, _10$$8, _11$$8, _13$$9, _14$$9, _15$$9, _16$$10, *_17$$10, _20$$11, _21$$11, _22$$11, _24$$11, _27$$14;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&relation_sub);
	ZVAL_UNDEF(&record_sub);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&placeholders);
	ZVAL_UNDEF(&referencedModel);
	ZVAL_UNDEF(&intermediateModel);
	ZVAL_UNDEF(&intermediateFields);
	ZVAL_UNDEF(&joinConditions);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&builder);
	ZVAL_UNDEF(&extraParameters);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&refPosition);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&referencedFields);
	ZVAL_UNDEF(&findParams);
	ZVAL_UNDEF(&findArguments);
	ZVAL_UNDEF(&retrieveMethod);
	ZVAL_UNDEF(&uniqueKey);
	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&rows);
	ZVAL_UNDEF(&firstRow);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_27$$14);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_29);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &relation, &method_param, &record, &parameters);

	if (unlikely(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(&method, method_param);
	} else {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_EMPTY_STRING(&method);
	}
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_INIT_VAR(&placeholders);
	array_init(&placeholders);
	ZEPHIR_CALL_METHOD(&extraParameters, relation, "getparams", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&referencedModel, relation, "getreferencedmodel", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, relation, "isthrough", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&conditions);
		array_init(&conditions);
		ZEPHIR_CALL_METHOD(&intermediateModel, relation, "getintermediatemodel", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&intermediateFields, relation, "getintermediatefields", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&fields, relation, "getfields", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&fields) != IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_1$$4);
			ZEPHIR_CONCAT_SVSVS(&_1$$4, "[", &intermediateModel, "].[", &intermediateFields, "] = :APR0:");
			zephir_array_append(&conditions, &_1$$4, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1241);
			ZEPHIR_CALL_METHOD(&_2$$4, record, "readattribute", NULL, 0, &fields);
			zephir_check_call_status();
			zephir_array_update_string(&placeholders, SL("APR0"), &_2$$4, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not supported", "phalcon/mvc/model/manager.zep", 1244);
			return;
		}
		ZEPHIR_INIT_VAR(&joinConditions);
		array_init(&joinConditions);
		ZEPHIR_CALL_METHOD(&intermediateFields, relation, "getintermediatereferencedfields", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&intermediateFields) != IS_ARRAY) {
			ZEPHIR_CALL_METHOD(&_3$$6, relation, "getreferencedfields", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_4$$6);
			ZEPHIR_CONCAT_SVSVSVSVS(&_4$$6, "[", &intermediateModel, "].[", &intermediateFields, "] = [", &referencedModel, "].[", &_3$$6, "]");
			zephir_array_append(&joinConditions, &_4$$6, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1254);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not supported", "phalcon/mvc/model/manager.zep", 1256);
			return;
		}
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "_mergefindparameters", &_6, 329, &extraParameters, parameters);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&builder, this_ptr, "createbuilder", NULL, 0, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &builder, "from", NULL, 0, &referencedModel);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_7$$3);
		zephir_fast_join_str(&_7$$3, SL(" AND "), &joinConditions TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &builder, "innerjoin", NULL, 0, &intermediateModel, &_7$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$3);
		zephir_fast_join_str(&_8$$3, SL(" AND "), &conditions TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &builder, "andwhere", NULL, 0, &_8$$3, &placeholders);
		zephir_check_call_status();
		if (ZEPHIR_IS_STRING(&method, "count")) {
			ZEPHIR_INIT_VAR(&_9$$8);
			ZVAL_STRING(&_9$$8, "COUNT(*) AS rowcount");
			ZEPHIR_CALL_METHOD(NULL, &builder, "columns", NULL, 0, &_9$$8);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_10$$8, &builder, "getquery", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&rows, &_10$$8, "execute", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&firstRow, &rows, "getfirst", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_9$$8);
			ZVAL_STRING(&_9$$8, "rowcount");
			ZEPHIR_CALL_METHOD(&_11$$8, &firstRow, "readattribute", NULL, 0, &_9$$8);
			zephir_check_call_status();
			RETURN_MM_LONG(zephir_get_intval(&_11$$8));
		}
		ZEPHIR_CALL_METHOD(&_12$$3, &builder, "getquery", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(&_12$$3, "execute", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(&conditions);
	array_init(&conditions);
	ZEPHIR_CALL_METHOD(&fields, relation, "getfields", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&fields) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_13$$9, relation, "getreferencedfields", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_14$$9);
		ZEPHIR_CONCAT_SVS(&_14$$9, "[", &_13$$9, "] = :APR0:");
		zephir_array_append(&conditions, &_14$$9, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1293);
		ZEPHIR_CALL_METHOD(&_15$$9, record, "readattribute", NULL, 0, &fields);
		zephir_check_call_status();
		zephir_array_update_string(&placeholders, SL("APR0"), &_15$$9, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_CALL_METHOD(&referencedFields, relation, "getreferencedfields", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_16$$10, relation, "getreferencedfields", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(&_16$$10, 0, "phalcon/mvc/model/manager.zep", 1305);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_16$$10), _18$$10, _19$$10, _17$$10)
		{
			ZEPHIR_INIT_NVAR(&refPosition);
			if (_19$$10 != NULL) { 
				ZVAL_STR_COPY(&refPosition, _19$$10);
			} else {
				ZVAL_LONG(&refPosition, _18$$10);
			}
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _17$$10);
			zephir_array_fetch(&_20$$11, &referencedFields, &refPosition, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1302 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_21$$11);
			ZEPHIR_CONCAT_SVSVS(&_21$$11, "[", &_20$$11, "] = :APR", &refPosition, ":");
			zephir_array_append(&conditions, &_21$$11, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1302);
			ZEPHIR_CALL_METHOD(&_22$$11, record, "readattribute", &_23, 0, &field);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_24$$11);
			ZEPHIR_CONCAT_SV(&_24$$11, "APR", &refPosition);
			zephir_array_update_zval(&placeholders, &_24$$11, &_22$$11, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&field);
		ZEPHIR_INIT_NVAR(&refPosition);
	}
	ZEPHIR_INIT_VAR(&findParams);
	zephir_create_array(&findParams, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_25);
	zephir_fast_join_str(&_25, SL(" AND "), &conditions TSRMLS_CC);
	zephir_array_fast_append(&findParams, &_25);
	zephir_array_update_string(&findParams, SL("bind"), &placeholders, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_26, record, "getdi", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&findParams, SL("di"), &_26, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&findArguments, this_ptr, "_mergefindparameters", &_6, 329, &findParams, parameters);
	zephir_check_call_status();
	if (Z_TYPE_P(&extraParameters) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&findParams, this_ptr, "_mergefindparameters", &_6, 329, &findArguments, &extraParameters);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&findParams, &findArguments);
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&method, "")) {
		ZEPHIR_CALL_METHOD(&_27$$14, relation, "gettype", NULL, 0);
		zephir_check_call_status();
		do {
			if (ZEPHIR_IS_LONG(&_27$$14, 0) || ZEPHIR_IS_LONG(&_27$$14, 1)) {
				ZEPHIR_INIT_VAR(&retrieveMethod);
				ZVAL_STRING(&retrieveMethod, "findFirst");
				break;
			}
			if (ZEPHIR_IS_LONG(&_27$$14, 2)) {
				ZEPHIR_INIT_NVAR(&retrieveMethod);
				ZVAL_STRING(&retrieveMethod, "find");
				break;
			}
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Unknown relation type", "phalcon/mvc/model/manager.zep", 1341);
			return;
		} while(0);

	} else {
		ZEPHIR_CPY_WRT(&retrieveMethod, &method);
	}
	ZEPHIR_INIT_VAR(&arguments);
	zephir_create_array(&arguments, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&arguments, &findParams);
	ZEPHIR_CALL_METHOD(&_26, relation, "isreusable", NULL, 0);
	zephir_check_call_status();
	reusable = zephir_get_boolval(&_26);
	if (reusable) {
		ZEPHIR_INIT_VAR(&uniqueKey);
		zephir_unique_key(&uniqueKey, &referencedModel, &arguments TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&records, this_ptr, "getreusablerecords", NULL, 0, &referencedModel, &uniqueKey);
		zephir_check_call_status();
		_28$$19 = Z_TYPE_P(&records) == IS_ARRAY;
		if (!(_28$$19)) {
			_28$$19 = Z_TYPE_P(&records) == IS_OBJECT;
		}
		if (_28$$19) {
			RETURN_CCTOR(records);
		}
	}
	ZEPHIR_INIT_VAR(&_29);
	zephir_create_array(&_29, 2, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_26, this_ptr, "load", NULL, 0, &referencedModel);
	zephir_check_call_status();
	zephir_array_fast_append(&_29, &_26);
	zephir_array_fast_append(&_29, &retrieveMethod);
	ZEPHIR_INIT_NVAR(&records);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&records, &_29, &arguments);
	zephir_check_call_status();
	if (reusable) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setreusablerecords", NULL, 0, &referencedModel, &uniqueKey, &records);
		zephir_check_call_status();
	}
	RETURN_CCTOR(records);

}

/**
 * Returns a reusable object from the internal list
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getReusableRecords) {

	zval *modelName_param = NULL, *key_param = NULL, records, _0;
	zval modelName, key;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &key_param);

	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}
	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	zephir_read_property(&_0, this_ptr, SL("_reusable"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&records, &_0, &key, 1 TSRMLS_CC)) {
		RETURN_CTOR(records);
	}
	RETURN_MM_NULL();

}

/**
 * Stores a reusable record in the internal list
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setReusableRecords) {

	zval *modelName_param = NULL, *key_param = NULL, *records, records_sub;
	zval modelName, key;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&records_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &modelName_param, &key_param, &records);

	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}
	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	zephir_update_property_array(this_ptr, SL("_reusable"), &key, records TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Clears the internal reusable list
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, clearReusableObjects) {

	zval __$null;
	ZEPHIR_INIT_THIS();

	ZVAL_NULL(&__$null);


	zephir_update_property_zval(this_ptr, SL("_reusable"), &__$null);

}

/**
 * Gets belongsTo related records from a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getBelongsToRecords) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *modelName_param = NULL, *modelRelation, modelRelation_sub, *record, record_sub, *parameters = NULL, parameters_sub, __$null, belongsTo, keyRelation, relations, _0$$3, _1$$3, _2$$3;
	zval method, modelName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&modelRelation_sub);
	ZVAL_UNDEF(&record_sub);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&belongsTo);
	ZVAL_UNDEF(&keyRelation);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &method_param, &modelName_param, &modelRelation, &record, &parameters);

	if (unlikely(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(&method, method_param);
	} else {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_EMPTY_STRING(&method);
	}
	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_OBS_VAR(&belongsTo);
	zephir_read_property(&belongsTo, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	if (Z_TYPE_P(&belongsTo) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_fast_strtolower(&_0$$3, &modelName);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_fast_strtolower(&_1$$3, modelRelation);
		ZEPHIR_INIT_VAR(&keyRelation);
		ZEPHIR_CONCAT_VSV(&keyRelation, &_0$$3, "$", &_1$$3);
		if (!(zephir_array_isset(&belongsTo, &keyRelation))) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_OBS_VAR(&relations);
		zephir_array_fetch(&relations, &belongsTo, &keyRelation, PH_NOISY, "phalcon/mvc/model/manager.zep", 1428 TSRMLS_CC);
		zephir_array_fetch_long(&_2$$3, &relations, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1429 TSRMLS_CC);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrelationrecords", NULL, 0, &_2$$3, &method, record, parameters);
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
	zval *method_param = NULL, *modelName_param = NULL, *modelRelation, modelRelation_sub, *record, record_sub, *parameters = NULL, parameters_sub, __$null, hasMany, keyRelation, relations, _0$$3, _1$$3, _2$$3;
	zval method, modelName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&modelRelation_sub);
	ZVAL_UNDEF(&record_sub);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&hasMany);
	ZVAL_UNDEF(&keyRelation);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &method_param, &modelName_param, &modelRelation, &record, &parameters);

	if (unlikely(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(&method, method_param);
	} else {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_EMPTY_STRING(&method);
	}
	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_OBS_VAR(&hasMany);
	zephir_read_property(&hasMany, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	if (Z_TYPE_P(&hasMany) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_fast_strtolower(&_0$$3, &modelName);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_fast_strtolower(&_1$$3, modelRelation);
		ZEPHIR_INIT_VAR(&keyRelation);
		ZEPHIR_CONCAT_VSV(&keyRelation, &_0$$3, "$", &_1$$3);
		if (!(zephir_array_isset(&hasMany, &keyRelation))) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_OBS_VAR(&relations);
		zephir_array_fetch(&relations, &hasMany, &keyRelation, PH_NOISY, "phalcon/mvc/model/manager.zep", 1458 TSRMLS_CC);
		zephir_array_fetch_long(&_2$$3, &relations, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1459 TSRMLS_CC);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrelationrecords", NULL, 0, &_2$$3, &method, record, parameters);
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
	zval *method_param = NULL, *modelName_param = NULL, *modelRelation, modelRelation_sub, *record, record_sub, *parameters = NULL, parameters_sub, __$null, hasOne, keyRelation, relations, _0$$3, _1$$3, _2$$3;
	zval method, modelName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&modelRelation_sub);
	ZVAL_UNDEF(&record_sub);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&hasOne);
	ZVAL_UNDEF(&keyRelation);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &method_param, &modelName_param, &modelRelation, &record, &parameters);

	if (unlikely(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(&method, method_param);
	} else {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_EMPTY_STRING(&method);
	}
	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_OBS_VAR(&hasOne);
	zephir_read_property(&hasOne, this_ptr, SL("_hasOne"), PH_NOISY_CC);
	if (Z_TYPE_P(&hasOne) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_fast_strtolower(&_0$$3, &modelName);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_fast_strtolower(&_1$$3, modelRelation);
		ZEPHIR_INIT_VAR(&keyRelation);
		ZEPHIR_CONCAT_VSV(&keyRelation, &_0$$3, "$", &_1$$3);
		if (!(zephir_array_isset(&hasOne, &keyRelation))) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_OBS_VAR(&relations);
		zephir_array_fetch(&relations, &hasOne, &keyRelation, PH_NOISY, "phalcon/mvc/model/manager.zep", 1488 TSRMLS_CC);
		zephir_array_fetch_long(&_2$$3, &relations, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1489 TSRMLS_CC);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrelationrecords", NULL, 0, &_2$$3, &method, record, parameters);
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

	zval *model, model_sub, belongsToSingle, relations, _0$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&belongsToSingle);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	zephir_read_property(&belongsToSingle, this_ptr, SL("_belongsToSingle"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&belongsToSingle) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_get_class(&_0$$3, model, 1 TSRMLS_CC);
		if (zephir_array_isset_fetch(&relations, &belongsToSingle, &_0$$3, 1 TSRMLS_CC)) {
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

	zval *model, model_sub, hasManySingle, relations, _0$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&hasManySingle);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	zephir_read_property(&hasManySingle, this_ptr, SL("_hasManySingle"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&hasManySingle) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_get_class(&_0$$3, model, 1 TSRMLS_CC);
		if (zephir_array_isset_fetch(&relations, &hasManySingle, &_0$$3, 1 TSRMLS_CC)) {
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

	zval *model, model_sub, hasOneSingle, relations, _0$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&hasOneSingle);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	zephir_read_property(&hasOneSingle, this_ptr, SL("_hasOneSingle"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&hasOneSingle) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_get_class(&_0$$3, model, 1 TSRMLS_CC);
		if (zephir_array_isset_fetch(&relations, &hasOneSingle, &_0$$3, 1 TSRMLS_CC)) {
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

	zval *model, model_sub, hasManyToManySingle, relations, _0$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&hasManyToManySingle);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	zephir_read_property(&hasManyToManySingle, this_ptr, SL("_hasManyToManySingle"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&hasManyToManySingle) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_get_class(&_0$$3, model, 1 TSRMLS_CC);
		if (zephir_array_isset_fetch(&relations, &hasManyToManySingle, &_0$$3, 1 TSRMLS_CC)) {
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
	zval *model, model_sub, _0, _1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gethasone", NULL, 0, model);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "gethasmany", NULL, 0, model);
	zephir_check_call_status();
	zephir_fast_array_merge(return_value, &_0, &_1 TSRMLS_CC);
	RETURN_MM();

}

/**
 * Query all the relationships defined on a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelations) {

	zval *modelName_param = NULL, entityName, allRelations, relations, belongsTo, relation, hasOne, hasMany, *_0$$4, *_1$$7, *_2$$10;
	zval modelName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&entityName);
	ZVAL_UNDEF(&allRelations);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&belongsTo);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&hasOne);
	ZVAL_UNDEF(&hasMany);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modelName_param);

	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}


	ZEPHIR_INIT_VAR(&entityName);
	zephir_fast_strtolower(&entityName, &modelName);
	ZEPHIR_INIT_VAR(&allRelations);
	array_init(&allRelations);
	zephir_read_property(&belongsTo, this_ptr, SL("_belongsToSingle"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&belongsTo) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&relations);
		if (zephir_array_isset_fetch(&relations, &belongsTo, &entityName, 0 TSRMLS_CC)) {
			zephir_is_iterable(&relations, 0, "phalcon/mvc/model/manager.zep", 1588);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relations), _0$$4)
			{
				ZEPHIR_INIT_NVAR(&relation);
				ZVAL_COPY(&relation, _0$$4);
				zephir_array_append(&allRelations, &relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1586);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&relation);
		}
	}
	zephir_read_property(&hasMany, this_ptr, SL("_hasManySingle"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&hasMany) == IS_ARRAY) {
		ZEPHIR_OBS_NVAR(&relations);
		if (zephir_array_isset_fetch(&relations, &hasMany, &entityName, 0 TSRMLS_CC)) {
			zephir_is_iterable(&relations, 0, "phalcon/mvc/model/manager.zep", 1600);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relations), _1$$7)
			{
				ZEPHIR_INIT_NVAR(&relation);
				ZVAL_COPY(&relation, _1$$7);
				zephir_array_append(&allRelations, &relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1598);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&relation);
		}
	}
	zephir_read_property(&hasOne, this_ptr, SL("_hasOneSingle"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&hasOne) == IS_ARRAY) {
		ZEPHIR_OBS_NVAR(&relations);
		if (zephir_array_isset_fetch(&relations, &hasOne, &entityName, 0 TSRMLS_CC)) {
			zephir_is_iterable(&relations, 0, "phalcon/mvc/model/manager.zep", 1612);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relations), _2$$10)
			{
				ZEPHIR_INIT_NVAR(&relation);
				ZVAL_COPY(&relation, _2$$10);
				zephir_array_append(&allRelations, &relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1610);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&relation);
		}
	}
	RETURN_CCTOR(allRelations);

}

/**
 * Query the first relationship defined between two models
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationsBetween) {

	zval *first_param = NULL, *second_param = NULL, keyRelation, belongsTo, hasMany, hasOne, relations, _0, _1;
	zval first, second;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&first);
	ZVAL_UNDEF(&second);
	ZVAL_UNDEF(&keyRelation);
	ZVAL_UNDEF(&belongsTo);
	ZVAL_UNDEF(&hasMany);
	ZVAL_UNDEF(&hasOne);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &first_param, &second_param);

	if (unlikely(Z_TYPE_P(first_param) != IS_STRING && Z_TYPE_P(first_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'first' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(first_param) == IS_STRING)) {
		zephir_get_strval(&first, first_param);
	} else {
		ZEPHIR_INIT_VAR(&first);
		ZVAL_EMPTY_STRING(&first);
	}
	if (unlikely(Z_TYPE_P(second_param) != IS_STRING && Z_TYPE_P(second_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'second' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(second_param) == IS_STRING)) {
		zephir_get_strval(&second, second_param);
	} else {
		ZEPHIR_INIT_VAR(&second);
		ZVAL_EMPTY_STRING(&second);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, &first);
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strtolower(&_1, &second);
	ZEPHIR_INIT_VAR(&keyRelation);
	ZEPHIR_CONCAT_VSV(&keyRelation, &_0, "$", &_1);
	zephir_read_property(&belongsTo, this_ptr, SL("_belongsTo"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&belongsTo) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&relations);
		if (zephir_array_isset_fetch(&relations, &belongsTo, &keyRelation, 0 TSRMLS_CC)) {
			RETURN_CCTOR(relations);
		}
	}
	zephir_read_property(&hasMany, this_ptr, SL("_hasMany"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&hasMany) == IS_ARRAY) {
		ZEPHIR_OBS_NVAR(&relations);
		if (zephir_array_isset_fetch(&relations, &hasMany, &keyRelation, 0 TSRMLS_CC)) {
			RETURN_CCTOR(relations);
		}
	}
	zephir_read_property(&hasOne, this_ptr, SL("_hasOne"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&hasOne) == IS_ARRAY) {
		ZEPHIR_OBS_NVAR(&relations);
		if (zephir_array_isset_fetch(&relations, &hasOne, &keyRelation, 0 TSRMLS_CC)) {
			RETURN_CCTOR(relations);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Creates a Phalcon\Mvc\Model\Query without execute it
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, createQuery) {

	zval _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *phql_param = NULL, dependencyInjector, query, _0, _2;
	zval phql;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&phql);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &phql_param);

	if (unlikely(Z_TYPE_P(phql_param) != IS_STRING && Z_TYPE_P(phql_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'phql' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(phql_param) == IS_STRING)) {
		zephir_get_strval(&phql, phql_param);
	} else {
		ZEPHIR_INIT_VAR(&phql);
		ZVAL_EMPTY_STRING(&phql);
	}


	ZEPHIR_OBS_VAR(&dependencyInjector);
	zephir_read_property(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injection object is required to access ORM services", "phalcon/mvc/model/manager.zep", 1669);
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_1, &phql);
	zephir_array_fast_append(&_1, &dependencyInjector);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Mvc\\Model\\Query");
	ZEPHIR_CALL_METHOD(&_0, &dependencyInjector, "get", NULL, 0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&query, &_0);
	zephir_update_property_zval(this_ptr, SL("_lastQuery"), &query);
	RETURN_CCTOR(query);

}

/**
 * Creates a Phalcon\Mvc\Model\Query and execute it
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, executeQuery) {

	zval _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *phql_param = NULL, *placeholders = NULL, placeholders_sub, *types = NULL, types_sub, __$null, dependencyInjector, query, _0, _1, _3;
	zval phql;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&phql);
	ZVAL_UNDEF(&placeholders_sub);
	ZVAL_UNDEF(&types_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &phql_param, &placeholders, &types);

	if (unlikely(Z_TYPE_P(phql_param) != IS_STRING && Z_TYPE_P(phql_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'phql' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(phql_param) == IS_STRING)) {
		zephir_get_strval(&phql, phql_param);
	} else {
		ZEPHIR_INIT_VAR(&phql);
		ZVAL_EMPTY_STRING(&phql);
	}
	if (!placeholders) {
		placeholders = &placeholders_sub;
		placeholders = &__$null;
	}
	if (!types) {
		types = &types_sub;
		types = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dependencyInjector, &_0);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injection object is required to access ORM services", "phalcon/mvc/model/manager.zep", 1689);
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_2, &phql);
	zephir_array_fast_append(&_2, &dependencyInjector);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\Mvc\\Model\\Query");
	ZEPHIR_CALL_METHOD(&_1, &dependencyInjector, "get", NULL, 0, &_3, &_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&query, &_1);
	zephir_update_property_zval(this_ptr, SL("_lastQuery"), &query);
	if (Z_TYPE_P(placeholders) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, &query, "setbindparams", NULL, 0, placeholders);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(types) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, &query, "setbindtypes", NULL, 0, types);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_METHOD(&query, "execute", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Creates a Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, createBuilder) {

	zval _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL, params_sub, __$null, dependencyInjector, _0, _1, _3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&params_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &params);

	if (!params) {
		params = &params_sub;
		params = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dependencyInjector, &_0);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injection object is required to access ORM services", "phalcon/mvc/model/manager.zep", 1721);
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_2, params);
	zephir_array_fast_append(&_2, &dependencyInjector);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\Mvc\\Model\\Query\\Builder");
	ZEPHIR_CALL_METHOD(&_1, &dependencyInjector, "get", NULL, 0, &_3, &_2);
	zephir_check_call_status();
	RETURN_CCTOR(_1);

}

/**
 * Returns the last query created or executed in the models manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getLastQuery) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_lastQuery");

}

/**
 * Registers shorter aliases for namespaces in PHQL statements
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, registerNamespaceAlias) {

	zval *alias_param = NULL, *namespaceName_param = NULL;
	zval alias, namespaceName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&namespaceName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &alias_param, &namespaceName_param);

	zephir_get_strval(&alias, alias_param);
	zephir_get_strval(&namespaceName, namespaceName_param);


	zephir_update_property_array(this_ptr, SL("_namespaceAliases"), &alias, &namespaceName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a real namespace from its alias
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getNamespaceAlias) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *alias_param = NULL, namespaceName, _0, _1;
	zval alias, _2;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &alias_param);

	if (unlikely(Z_TYPE_P(alias_param) != IS_STRING && Z_TYPE_P(alias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(alias_param) == IS_STRING)) {
		zephir_get_strval(&alias, alias_param);
	} else {
		ZEPHIR_INIT_VAR(&alias);
		ZVAL_EMPTY_STRING(&alias);
	}


	ZEPHIR_OBS_VAR(&namespaceName);
	zephir_read_property(&_0, this_ptr, SL("_namespaceAliases"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&namespaceName, &_0, &alias, 0 TSRMLS_CC)) {
		RETURN_CCTOR(namespaceName);
	}
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalcon_mvc_model_exception_ce);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVS(&_2, "Namespace alias '", &alias, "' is not registered");
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 9, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_1, "phalcon/mvc/model/manager.zep", 1756 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Returns all the registered namespace aliases
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getNamespaceAliases) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_namespaceAliases");

}

/**
 * Destroys the current PHQL cache
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, __destruct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	ZEPHIR_INIT_THIS();


	ZEPHIR_MM_GROW();

	phalcon_orm_destroy_cache(TSRMLS_C);
	ZEPHIR_CALL_CE_STATIC(NULL, phalcon_mvc_model_query_ce, "clean", &_0, 330);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

