
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
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
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

	zval *dependencyInjector, dependencyInjector_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector_sub);

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), dependencyInjector);

}

/**
 * Returns the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getDI) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_dependencyInjector");

}

/**
 * Sets a global events manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setEventsManager) {

	zval *eventsManager, eventsManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_zval(this_ptr, SL("_eventsManager"), eventsManager);
	RETURN_THISW();

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getEventsManager) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_eventsManager");

}

/**
 * Sets a custom events manager for a specific model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setCustomEventsManager) {

	zval *model, model_sub, *eventsManager, eventsManager_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&eventsManager_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &eventsManager);



	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, model, 1 TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_customEventsManager"), &_0, eventsManager);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a custom events manager related to a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getCustomEventsManager) {

	zval *model, model_sub, eventsManager, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	zephir_read_property(&_0, this_ptr, SL("_customEventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_get_class(&_1, model, 1 TSRMLS_CC);
	if (!(zephir_array_isset_fetch(&eventsManager, &_0, &_1, 1 TSRMLS_CC))) {
		RETURN_MM_BOOL(0);
	}
	RETURN_CTOR(&eventsManager);

}

/**
 * Initializes a model in the model manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, initialize) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, __$true, className, eventsManager, _0, _1, _2$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_BOOL(&__$true, 1);
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
	zephir_update_property_array(this_ptr, SL("_initialized"), &className, &__$true);
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
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modelName_param);

	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
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

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_lastInitialized");

}

/**
 * Loads a model throwing an exception if it doesn't exist
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, load) {

	zend_class_entry *_7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *modelName_param = NULL, model, colonPos, namespaceName, namespaceAlias, className, _0, _6, _8, _9, _1$$3, _2$$3, _3$$3, _4$$4;
	zval modelName, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&colonPos);
	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&namespaceAlias);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modelName_param);

	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
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
	if (!(zephir_class_exists(&modelName, 1 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_SVS(&_5$$4, "Model '", &modelName, "' could not be loaded");
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 4, &_5$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalcon/mvc/model/manager.zep", 289 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&model);
	zephir_fetch_safe_class(&_6, &modelName);
	_7 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_6), Z_STRLEN_P(&_6), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(&model, _7);
	if (zephir_has_constructor(&model TSRMLS_CC)) {
		zephir_read_property(&_8, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
		ZVAL_NULL(&_9);
		ZEPHIR_CALL_METHOD(NULL, &model, "__construct", NULL, 0, &_9, &_8, this_ptr);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&model);

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
	zval prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prefix_param);

	if (UNEXPECTED(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(prefix_param) == IS_STRING)) {
		zephir_get_strval(&prefix, prefix_param);
	} else {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_EMPTY_STRING(&prefix);
	}


	zephir_update_property_zval(this_ptr, SL("_prefix"), &prefix);
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

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_prefix");

}

/**
 * Sets the mapped source for a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setModelSource) {

	zval source;
	zval *model, model_sub, *source_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&source);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &source_param);

	if (UNEXPECTED(Z_TYPE_P(source_param) != IS_STRING && Z_TYPE_P(source_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'source' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(source_param) == IS_STRING)) {
		zephir_get_strval(&source, source_param);
	} else {
		ZEPHIR_INIT_VAR(&source);
		ZVAL_EMPTY_STRING(&source);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, model, 1 TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_sources"), &_0, &source);
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
	zval property;
	zval *model, model_sub, *property_param = NULL, properties, className, _0, _2, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&properties);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&property);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &property_param);

	zephir_get_strval(&property, property_param);


	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, model, 0 TSRMLS_CC);
	zephir_read_property(&_0, this_ptr, SL("_modelVisibility"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &className))) {
		ZEPHIR_CALL_FUNCTION(&_1$$3, "get_object_vars", NULL, 14, model);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("_modelVisibility"), &className, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
	}
	zephir_read_property(&_2, this_ptr, SL("_modelVisibility"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&properties);
	zephir_array_fetch(&properties, &_2, &className, PH_NOISY, "phalcon/mvc/model/manager.zep", 372 TSRMLS_CC);
	RETURN_MM_BOOL(zephir_array_key_exists(&properties, &property TSRMLS_CC));

}

/**
 * Returns the mapped source for a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getModelSource) {

	zval *model, model_sub, entityName, _0, _3, _4, _5, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&entityName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_INIT_VAR(&entityName);
	zephir_get_class(&entityName, model, 1 TSRMLS_CC);
	zephir_read_property(&_0, this_ptr, SL("_sources"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &entityName))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_get_class_ns(&_2$$3, model, 0 TSRMLS_CC);
		zephir_uncamelize(&_1$$3, &_2$$3, NULL  );
		zephir_update_property_array(this_ptr, SL("_sources"), &entityName, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
	}
	zephir_read_property(&_3, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, this_ptr, SL("_sources"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_5, &_4, &entityName, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 390 TSRMLS_CC);
	ZEPHIR_CONCAT_VV(return_value, &_3, &_5);
	RETURN_MM();

}

/**
 * Sets the mapped schema for a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setModelSchema) {

	zval schema;
	zval *model, model_sub, *schema_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&schema);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(schema_param) != IS_STRING && Z_TYPE_P(schema_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schema' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schema_param) == IS_STRING)) {
		zephir_get_strval(&schema, schema_param);
	} else {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_EMPTY_STRING(&schema);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, model, 1 TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_schemas"), &_0, &schema);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the mapped schema for a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getModelSchema) {

	zval *model, model_sub, schema, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	zephir_read_property(&_0, this_ptr, SL("_schemas"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_get_class(&_1, model, 1 TSRMLS_CC);
	if (!(zephir_array_isset_fetch(&schema, &_0, &_1, 1 TSRMLS_CC))) {
		RETURN_MM_STRING("");
	}
	RETURN_CTOR(&schema);

}

/**
 * Sets both write and read connection service for a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setConnectionService) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval connectionService;
	zval *model, model_sub, *connectionService_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&connectionService);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &connectionService_param);

	if (UNEXPECTED(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(connectionService_param) == IS_STRING)) {
		zephir_get_strval(&connectionService, connectionService_param);
	} else {
		ZEPHIR_INIT_VAR(&connectionService);
		ZVAL_EMPTY_STRING(&connectionService);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setreadconnectionservice", NULL, 0, model, &connectionService);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setwriteconnectionservice", NULL, 0, model, &connectionService);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets write connection service for a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setWriteConnectionService) {

	zval connectionService;
	zval *model, model_sub, *connectionService_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&connectionService);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &connectionService_param);

	if (UNEXPECTED(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(connectionService_param) == IS_STRING)) {
		zephir_get_strval(&connectionService, connectionService_param);
	} else {
		ZEPHIR_INIT_VAR(&connectionService);
		ZVAL_EMPTY_STRING(&connectionService);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, model, 1 TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_writeConnectionServices"), &_0, &connectionService);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets read connection service for a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setReadConnectionService) {

	zval connectionService;
	zval *model, model_sub, *connectionService_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&connectionService);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &connectionService_param);

	if (UNEXPECTED(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(connectionService_param) == IS_STRING)) {
		zephir_get_strval(&connectionService, connectionService_param);
	} else {
		ZEPHIR_INIT_VAR(&connectionService);
		ZVAL_EMPTY_STRING(&connectionService);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, model, 1 TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_readConnectionServices"), &_0, &connectionService);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the connection to read data related to a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getReadConnection) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, _0;
	zval *this_ptr = getThis();

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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, _0;
	zval *this_ptr = getThis();

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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, *connectionServices, connectionServices_sub, dependencyInjector, service, connection, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&connectionServices_sub);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &connectionServices);



	ZEPHIR_CALL_METHOD(&service, this_ptr, "_getconnectionservice", NULL, 0, model, connectionServices);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dependencyInjector, &_0);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM", "phalcon/mvc/model/manager.zep", 467);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, &dependencyInjector, "getshared", NULL, 0, &service);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&connection, &_1);
	if (Z_TYPE_P(&connection) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid injected connection service", "phalcon/mvc/model/manager.zep", 476);
		return;
	}
	RETURN_CCTOR(&connection);

}

/**
 * Returns the connection service name used to read data related to a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getReadConnectionService) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, _0;
	zval *this_ptr = getThis();

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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, _0;
	zval *this_ptr = getThis();

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
 * Returns the connection service name used to read or write data related to
 * a model depending on the connection services
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, _getConnectionService) {

	zval *model, model_sub, *connectionServices, connectionServices_sub, connection, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&connectionServices_sub);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &connectionServices);



	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, model, 1 TSRMLS_CC);
	if (!(zephir_array_isset_fetch(&connection, connectionServices, &_0, 1 TSRMLS_CC))) {
		RETURN_MM_STRING("db");
	}
	RETURN_CTOR(&connection);

}

/**
 * Receives events generated in the models and dispatches them to an events-manager if available
 * Notify the behaviors that are listening in the model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, notifyEvent) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventName_param = NULL, *model, model_sub, status, behavior, modelsBehaviors, eventsManager, customEventsManager, _0, _1, _5, _6, *_2$$3, _3$$3;
	zval eventName, _4$$8, _7$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&behavior);
	ZVAL_UNDEF(&modelsBehaviors);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&customEventsManager);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &eventName_param, &model);

	if (UNEXPECTED(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(eventName_param) == IS_STRING)) {
		zephir_get_strval(&eventName, eventName_param);
	} else {
		ZEPHIR_INIT_VAR(&eventName);
		ZVAL_EMPTY_STRING(&eventName);
	}


	ZEPHIR_INIT_VAR(&status);
	ZVAL_NULL(&status);
	ZEPHIR_OBS_VAR(&modelsBehaviors);
	zephir_read_property(&_0, this_ptr, SL("_behaviors"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_get_class(&_1, model, 1 TSRMLS_CC);
	if (zephir_array_isset_fetch(&modelsBehaviors, &_0, &_1, 0 TSRMLS_CC)) {
		zephir_is_iterable(&modelsBehaviors, 0, "phalcon/mvc/model/manager.zep", 537);
		if (Z_TYPE_P(&modelsBehaviors) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&modelsBehaviors), _2$$3)
			{
				ZEPHIR_INIT_NVAR(&behavior);
				ZVAL_COPY(&behavior, _2$$3);
				ZEPHIR_CALL_METHOD(&status, &behavior, "notify", NULL, 0, &eventName, model);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
					RETURN_MM_BOOL(0);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &modelsBehaviors, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_3$$3, &modelsBehaviors, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&behavior, &modelsBehaviors, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&status, &behavior, "notify", NULL, 0, &eventName, model);
					zephir_check_call_status();
					if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
						RETURN_MM_BOOL(0);
					}
				ZEPHIR_CALL_METHOD(NULL, &modelsBehaviors, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&behavior);
	}
	ZEPHIR_OBS_VAR(&eventsManager);
	zephir_read_property(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_4$$8);
		ZEPHIR_CONCAT_SV(&_4$$8, "model:", &eventName);
		ZEPHIR_CALL_METHOD(&status, &eventsManager, "fire", NULL, 0, &_4$$8, model);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
			RETURN_CCTOR(&status);
		}
	}
	ZEPHIR_OBS_VAR(&customEventsManager);
	zephir_read_property(&_5, this_ptr, SL("_customEventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_6);
	zephir_get_class(&_6, model, 1 TSRMLS_CC);
	if (zephir_array_isset_fetch(&customEventsManager, &_5, &_6, 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_7$$10);
		ZEPHIR_CONCAT_SV(&_7$$10, "model:", &eventName);
		ZEPHIR_CALL_METHOD(&status, &customEventsManager, "fire", NULL, 0, &_7$$10, model);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_CCTOR(&status);

}

/**
 * Dispatch an event to the listeners and behaviors
 * This method expects that the endpoint listeners/behaviors returns true
 * meaning that a least one was implemented
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, missingMethod) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval eventName, _4$$8;
	zval *model, model_sub, *eventName_param = NULL, *data, data_sub, modelsBehaviors, result, eventsManager, behavior, _0, _1, *_2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&modelsBehaviors);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&behavior);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&_4$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &model, &eventName_param, &data);

	if (UNEXPECTED(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(eventName_param) == IS_STRING)) {
		zephir_get_strval(&eventName, eventName_param);
	} else {
		ZEPHIR_INIT_VAR(&eventName);
		ZVAL_EMPTY_STRING(&eventName);
	}


	ZEPHIR_OBS_VAR(&modelsBehaviors);
	zephir_read_property(&_0, this_ptr, SL("_behaviors"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_get_class(&_1, model, 1 TSRMLS_CC);
	if (zephir_array_isset_fetch(&modelsBehaviors, &_0, &_1, 0 TSRMLS_CC)) {
		zephir_is_iterable(&modelsBehaviors, 0, "phalcon/mvc/model/manager.zep", 586);
		if (Z_TYPE_P(&modelsBehaviors) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&modelsBehaviors), _2$$3)
			{
				ZEPHIR_INIT_NVAR(&behavior);
				ZVAL_COPY(&behavior, _2$$3);
				ZEPHIR_CALL_METHOD(&result, &behavior, "missingmethod", NULL, 0, model, &eventName, data);
				zephir_check_call_status();
				if (Z_TYPE_P(&result) != IS_NULL) {
					RETURN_CCTOR(&result);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &modelsBehaviors, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_3$$3, &modelsBehaviors, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&behavior, &modelsBehaviors, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&result, &behavior, "missingmethod", NULL, 0, model, &eventName, data);
					zephir_check_call_status();
					if (Z_TYPE_P(&result) != IS_NULL) {
						RETURN_CCTOR(&result);
					}
				ZEPHIR_CALL_METHOD(NULL, &modelsBehaviors, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&behavior);
	}
	ZEPHIR_OBS_VAR(&eventsManager);
	zephir_read_property(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_4$$8);
		ZEPHIR_CONCAT_SV(&_4$$8, "model:", &eventName);
		ZEPHIR_RETURN_CALL_METHOD(&eventsManager, "fire", NULL, 0, &_4$$8, model, data);
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
	zval *this_ptr = getThis();

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
	zephir_array_append(&modelsBehaviors, behavior, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 618);
	zephir_update_property_array(this_ptr, SL("_behaviors"), &entityName, &modelsBehaviors);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets if a model must keep snapshots
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, keepSnapshots) {

	zend_bool keepSnapshots;
	zval *model, model_sub, *keepSnapshots_param = NULL, _0, _1;
	zval *this_ptr = getThis();

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
	zephir_update_property_array(this_ptr, SL("_keepSnapshots"), &_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if a model is keeping snapshots for the queried records
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, isKeepingSnapshots) {

	zval *model, model_sub, isKeeping, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&isKeeping);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	zephir_read_property(&_0, this_ptr, SL("_keepSnapshots"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_get_class(&_1, model, 1 TSRMLS_CC);
	if (!(zephir_array_isset_fetch(&isKeeping, &_0, &_1, 1 TSRMLS_CC))) {
		RETURN_MM_BOOL(0);
	}
	RETURN_CTOR(&isKeeping);

}

/**
 * Sets if a model must use dynamic update instead of the all-field update
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, useDynamicUpdate) {

	zend_bool dynamicUpdate;
	zval *model, model_sub, *dynamicUpdate_param = NULL, entityName, _0, _1;
	zval *this_ptr = getThis();

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
	zephir_update_property_array(this_ptr, SL("_dynamicUpdate"), &entityName, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_BOOL(&_1, dynamicUpdate);
	zephir_update_property_array(this_ptr, SL("_keepSnapshots"), &entityName, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if a model is using dynamic update instead of all-field update
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, isUsingDynamicUpdate) {

	zval *model, model_sub, isUsing, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&isUsing);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	zephir_read_property(&_0, this_ptr, SL("_dynamicUpdate"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_get_class(&_1, model, 1 TSRMLS_CC);
	if (!(zephir_array_isset_fetch(&isUsing, &_0, &_1, 1 TSRMLS_CC))) {
		RETURN_MM_BOOL(0);
	}
	RETURN_CTOR(&isUsing);

}

/**
 * Setup a 1-1 relation between two models
 *
 * @param	array options
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasOne) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval referencedModel;
	zval *model, model_sub, *fields, fields_sub, *referencedModel_param = NULL, *referencedFields, referencedFields_sub, *options = NULL, options_sub, __$null, entityName, referencedEntity, relation, keyRelation, relations, alias, lowerAlias, singleRelations, _0, _1, _2;
	zval *this_ptr = getThis();

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

	if (UNEXPECTED(Z_TYPE_P(referencedModel_param) != IS_STRING && Z_TYPE_P(referencedModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referencedModel' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referencedModel_param) == IS_STRING)) {
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
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same", "phalcon/mvc/model/manager.zep", 698);
			return;
		}
	}
	ZEPHIR_INIT_VAR(&relation);
	object_init_ex(&relation, phalcon_mvc_model_relation_ce);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_METHOD(NULL, &relation, "__construct", NULL, 330, &_1, &referencedModel, fields, referencedFields, options);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&alias);
	if (zephir_array_isset_string_fetch(&alias, options, SL("alias"), 0)) {
		if (Z_TYPE_P(&alias) != IS_STRING) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Relation alias must be a string", "phalcon/mvc/model/manager.zep", 718);
			return;
		}
		ZEPHIR_INIT_VAR(&lowerAlias);
		zephir_fast_strtolower(&lowerAlias, &alias);
	} else {
		ZEPHIR_CPY_WRT(&lowerAlias, &referencedEntity);
	}
	zephir_array_append(&relations, &relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 730);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VSV(&_2, &entityName, "$", &lowerAlias);
	zephir_update_property_array(this_ptr, SL("_aliases"), &_2, &relation);
	zephir_update_property_array(this_ptr, SL("_hasOne"), &keyRelation, &relations);
	ZEPHIR_OBS_VAR(&singleRelations);
	zephir_read_property(&_1, this_ptr, SL("_hasOneSingle"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&singleRelations, &_1, &entityName, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(&singleRelations);
		array_init(&singleRelations);
	}
	zephir_array_append(&singleRelations, &relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 744);
	zephir_update_property_array(this_ptr, SL("_hasOneSingle"), &entityName, &singleRelations);
	RETURN_CCTOR(&relation);

}

/**
 * Setup a relation reverse many to one between two models
 *
 * @param	array options
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, addBelongsTo) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval referencedModel;
	zval *model, model_sub, *fields, fields_sub, *referencedModel_param = NULL, *referencedFields, referencedFields_sub, *options = NULL, options_sub, __$null, entityName, referencedEntity, relation, keyRelation, relations, alias, lowerAlias, singleRelations, _0, _1, _2;
	zval *this_ptr = getThis();

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

	if (UNEXPECTED(Z_TYPE_P(referencedModel_param) != IS_STRING && Z_TYPE_P(referencedModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referencedModel' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referencedModel_param) == IS_STRING)) {
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
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same", "phalcon/mvc/model/manager.zep", 778);
			return;
		}
	}
	ZEPHIR_INIT_VAR(&relation);
	object_init_ex(&relation, phalcon_mvc_model_relation_ce);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_METHOD(NULL, &relation, "__construct", NULL, 330, &_1, &referencedModel, fields, referencedFields, options);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&alias);
	if (zephir_array_isset_string_fetch(&alias, options, SL("alias"), 0)) {
		if (Z_TYPE_P(&alias) != IS_STRING) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Relation alias must be a string", "phalcon/mvc/model/manager.zep", 798);
			return;
		}
		ZEPHIR_INIT_VAR(&lowerAlias);
		zephir_fast_strtolower(&lowerAlias, &alias);
	} else {
		ZEPHIR_CPY_WRT(&lowerAlias, &referencedEntity);
	}
	zephir_array_append(&relations, &relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 810);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VSV(&_2, &entityName, "$", &lowerAlias);
	zephir_update_property_array(this_ptr, SL("_aliases"), &_2, &relation);
	zephir_update_property_array(this_ptr, SL("_belongsTo"), &keyRelation, &relations);
	ZEPHIR_OBS_VAR(&singleRelations);
	zephir_read_property(&_1, this_ptr, SL("_belongsToSingle"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&singleRelations, &_1, &entityName, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(&singleRelations);
		array_init(&singleRelations);
	}
	zephir_array_append(&singleRelations, &relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 824);
	zephir_update_property_array(this_ptr, SL("_belongsToSingle"), &entityName, &singleRelations);
	RETURN_CCTOR(&relation);

}

/**
 * Setup a relation 1-n between two models
 *
 * @param	mixed referencedFields
 * @param	array options
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasMany) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval referencedModel;
	zval *model, model_sub, *fields, fields_sub, *referencedModel_param = NULL, *referencedFields, referencedFields_sub, *options = NULL, options_sub, __$null, entityName, referencedEntity, hasMany, relation, keyRelation, relations, alias, lowerAlias, singleRelations, _0, _1;
	zval *this_ptr = getThis();

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

	if (UNEXPECTED(Z_TYPE_P(referencedModel_param) != IS_STRING && Z_TYPE_P(referencedModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referencedModel' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referencedModel_param) == IS_STRING)) {
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
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same", "phalcon/mvc/model/manager.zep", 860);
			return;
		}
	}
	ZEPHIR_INIT_VAR(&relation);
	object_init_ex(&relation, phalcon_mvc_model_relation_ce);
	ZVAL_LONG(&_0, 2);
	ZEPHIR_CALL_METHOD(NULL, &relation, "__construct", NULL, 330, &_0, &referencedModel, fields, referencedFields, options);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&alias);
	if (zephir_array_isset_string_fetch(&alias, options, SL("alias"), 0)) {
		if (Z_TYPE_P(&alias) != IS_STRING) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Relation alias must be a string", "phalcon/mvc/model/manager.zep", 880);
			return;
		}
		ZEPHIR_INIT_VAR(&lowerAlias);
		zephir_fast_strtolower(&lowerAlias, &alias);
	} else {
		ZEPHIR_CPY_WRT(&lowerAlias, &referencedEntity);
	}
	zephir_array_append(&relations, &relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 892);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VSV(&_1, &entityName, "$", &lowerAlias);
	zephir_update_property_array(this_ptr, SL("_aliases"), &_1, &relation);
	zephir_update_property_array(this_ptr, SL("_hasMany"), &keyRelation, &relations);
	ZEPHIR_OBS_VAR(&singleRelations);
	zephir_read_property(&_0, this_ptr, SL("_hasManySingle"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&singleRelations, &_0, &entityName, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(&singleRelations);
		array_init(&singleRelations);
	}
	zephir_array_append(&singleRelations, &relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 906);
	zephir_update_property_array(this_ptr, SL("_hasManySingle"), &entityName, &singleRelations);
	RETURN_CCTOR(&relation);

}

/**
 * Setups a relation n-m between two models
 *
 * @param	string fields
 * @param	string intermediateFields
 * @param	string intermediateReferencedFields
 * @param	string referencedFields
 * @param   array options
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasManyToMany) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval intermediateModel, referencedModel;
	zval *model, model_sub, *fields, fields_sub, *intermediateModel_param = NULL, *intermediateFields, intermediateFields_sub, *intermediateReferencedFields, intermediateReferencedFields_sub, *referencedModel_param = NULL, *referencedFields, referencedFields_sub, *options = NULL, options_sub, __$null, entityName, referencedEntity, hasManyToMany, relation, keyRelation, relations, alias, lowerAlias, singleRelations, intermediateEntity, _0, _1;
	zval *this_ptr = getThis();

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

	if (UNEXPECTED(Z_TYPE_P(intermediateModel_param) != IS_STRING && Z_TYPE_P(intermediateModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'intermediateModel' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(intermediateModel_param) == IS_STRING)) {
		zephir_get_strval(&intermediateModel, intermediateModel_param);
	} else {
		ZEPHIR_INIT_VAR(&intermediateModel);
		ZVAL_EMPTY_STRING(&intermediateModel);
	}
	if (UNEXPECTED(Z_TYPE_P(referencedModel_param) != IS_STRING && Z_TYPE_P(referencedModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referencedModel' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referencedModel_param) == IS_STRING)) {
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
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same", "phalcon/mvc/model/manager.zep", 946);
			return;
		}
	}
	if (Z_TYPE_P(intermediateReferencedFields) == IS_ARRAY) {
		if (zephir_fast_count_int(fields TSRMLS_CC) != zephir_fast_count_int(intermediateFields TSRMLS_CC)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same", "phalcon/mvc/model/manager.zep", 955);
			return;
		}
	}
	ZEPHIR_INIT_VAR(&relation);
	object_init_ex(&relation, phalcon_mvc_model_relation_ce);
	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_METHOD(NULL, &relation, "__construct", NULL, 330, &_0, &referencedModel, fields, referencedFields, options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &relation, "setintermediaterelation", NULL, 331, intermediateFields, &intermediateModel, intermediateReferencedFields);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&alias);
	if (zephir_array_isset_string_fetch(&alias, options, SL("alias"), 0)) {
		if (Z_TYPE_P(&alias) != IS_STRING) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Relation alias must be a string", "phalcon/mvc/model/manager.zep", 980);
			return;
		}
		ZEPHIR_INIT_VAR(&lowerAlias);
		zephir_fast_strtolower(&lowerAlias, &alias);
	} else {
		ZEPHIR_CPY_WRT(&lowerAlias, &referencedEntity);
	}
	zephir_array_append(&relations, &relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 990);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VSV(&_1, &entityName, "$", &lowerAlias);
	zephir_update_property_array(this_ptr, SL("_aliases"), &_1, &relation);
	zephir_update_property_array(this_ptr, SL("_hasManyToMany"), &keyRelation, &relations);
	ZEPHIR_OBS_VAR(&singleRelations);
	zephir_read_property(&_0, this_ptr, SL("_hasManyToManySingle"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&singleRelations, &_0, &entityName, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(&singleRelations);
		array_init(&singleRelations);
	}
	zephir_array_append(&singleRelations, &relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1012);
	zephir_update_property_array(this_ptr, SL("_hasManyToManySingle"), &entityName, &singleRelations);
	RETURN_CCTOR(&relation);

}

/**
 * Checks whether a model has a belongsTo relation with another model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsBelongsTo) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *modelName_param = NULL, *modelRelation_param = NULL, entityName, keyRelation, _0, _1, _2;
	zval modelName, modelRelation;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&modelRelation);
	ZVAL_UNDEF(&entityName);
	ZVAL_UNDEF(&keyRelation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &modelRelation_param);

	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}
	if (UNEXPECTED(Z_TYPE_P(modelRelation_param) != IS_STRING && Z_TYPE_P(modelRelation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelRelation' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelRelation_param) == IS_STRING)) {
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *modelName_param = NULL, *modelRelation_param = NULL, entityName, keyRelation, _0, _1, _2;
	zval modelName, modelRelation;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&modelRelation);
	ZVAL_UNDEF(&entityName);
	ZVAL_UNDEF(&keyRelation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &modelRelation_param);

	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}
	if (UNEXPECTED(Z_TYPE_P(modelRelation_param) != IS_STRING && Z_TYPE_P(modelRelation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelRelation' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelRelation_param) == IS_STRING)) {
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *modelName_param = NULL, *modelRelation_param = NULL, entityName, keyRelation, _0, _1, _2;
	zval modelName, modelRelation;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&modelRelation);
	ZVAL_UNDEF(&entityName);
	ZVAL_UNDEF(&keyRelation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &modelRelation_param);

	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}
	if (UNEXPECTED(Z_TYPE_P(modelRelation_param) != IS_STRING && Z_TYPE_P(modelRelation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelRelation' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelRelation_param) == IS_STRING)) {
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *modelName_param = NULL, *modelRelation_param = NULL, entityName, keyRelation, _0, _1, _2;
	zval modelName, modelRelation;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&modelRelation);
	ZVAL_UNDEF(&entityName);
	ZVAL_UNDEF(&keyRelation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &modelRelation_param);

	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}
	if (UNEXPECTED(Z_TYPE_P(modelRelation_param) != IS_STRING && Z_TYPE_P(modelRelation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelRelation' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelRelation_param) == IS_STRING)) {
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

	zval *modelName_param = NULL, *alias_param = NULL, relation, _0, _1;
	zval modelName, alias, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &alias_param);

	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}
	if (UNEXPECTED(Z_TYPE_P(alias_param) != IS_STRING && Z_TYPE_P(alias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(alias_param) == IS_STRING)) {
		zephir_get_strval(&alias, alias_param);
	} else {
		ZEPHIR_INIT_VAR(&alias);
		ZVAL_EMPTY_STRING(&alias);
	}


	zephir_read_property(&_0, this_ptr, SL("_aliases"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VSV(&_2, &modelName, "$", &alias);
	zephir_fast_strtolower(&_1, &_2);
	if (!(zephir_array_isset_fetch(&relation, &_0, &_1, 1 TSRMLS_CC))) {
		RETURN_MM_BOOL(0);
	}
	RETURN_CTOR(&relation);

}

/**
 * Merge two arrays of find parameters
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, _mergeFindParameters) {

	zend_string *_5$$4, *_16$$15;
	zend_ulong _4$$4, _15$$15;
	zend_bool _0, _6$$5, _9$$9, _17$$16, _20$$16, _23$$25, _26$$25;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *findParamsOne, findParamsOne_sub, *findParamsTwo, findParamsTwo_sub, key, value, findParams, _1$$3, *_2$$4, _3$$4, _7$$8, _8$$8, _10$$12, _11$$12, _12$$14, *_13$$15, _14$$15, _18$$19, _19$$19, _21$$24, _22$$24, _24$$28, _25$$28, _27$$33, _28$$33, _29$$37, _30$$37;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&findParamsOne_sub);
	ZVAL_UNDEF(&findParamsTwo_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&findParams);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_14$$15);
	ZVAL_UNDEF(&_18$$19);
	ZVAL_UNDEF(&_19$$19);
	ZVAL_UNDEF(&_21$$24);
	ZVAL_UNDEF(&_22$$24);
	ZVAL_UNDEF(&_24$$28);
	ZVAL_UNDEF(&_25$$28);
	ZVAL_UNDEF(&_27$$33);
	ZVAL_UNDEF(&_28$$33);
	ZVAL_UNDEF(&_29$$37);
	ZVAL_UNDEF(&_30$$37);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &findParamsOne, &findParamsTwo);



	_0 = Z_TYPE_P(findParamsOne) == IS_STRING;
	if (_0) {
		_0 = Z_TYPE_P(findParamsTwo) == IS_STRING;
	}
	if (_0) {
		zephir_create_array(return_value, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_SVSVS(&_1$$3, "(", findParamsOne, ") AND (", findParamsTwo, ")");
		zephir_array_fast_append(return_value, &_1$$3);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&findParams);
	array_init(&findParams);
	if (Z_TYPE_P(findParamsOne) == IS_ARRAY) {
		zephir_is_iterable(findParamsOne, 0, "phalcon/mvc/model/manager.zep", 1159);
		if (Z_TYPE_P(findParamsOne) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(findParamsOne), _4$$4, _5$$4, _2$$4)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_5$$4 != NULL) { 
					ZVAL_STR_COPY(&key, _5$$4);
				} else {
					ZVAL_LONG(&key, _4$$4);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _2$$4);
				_6$$5 = ZEPHIR_IS_LONG_IDENTICAL(&key, 0);
				if (!(_6$$5)) {
					_6$$5 = ZEPHIR_IS_STRING_IDENTICAL(&key, "conditions");
				}
				if (_6$$5) {
					if (!(zephir_array_isset_long(&findParams, 0))) {
						zephir_array_update_long(&findParams, 0, &value, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
					} else {
						zephir_array_fetch_long(&_7$$8, &findParams, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1152 TSRMLS_CC);
						ZEPHIR_INIT_LNVAR(_8$$8);
						ZEPHIR_CONCAT_SVSVS(&_8$$8, "(", &_7$$8, ") AND (", &value, ")");
						zephir_array_update_long(&findParams, 0, &_8$$8, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
					}
					continue;
				}
				zephir_array_update_zval(&findParams, &key, &value, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, findParamsOne, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_3$$4, findParamsOne, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, findParamsOne, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, findParamsOne, "current", NULL, 0);
				zephir_check_call_status();
					_9$$9 = ZEPHIR_IS_LONG_IDENTICAL(&key, 0);
					if (!(_9$$9)) {
						_9$$9 = ZEPHIR_IS_STRING_IDENTICAL(&key, "conditions");
					}
					if (_9$$9) {
						if (!(zephir_array_isset_long(&findParams, 0))) {
							zephir_array_update_long(&findParams, 0, &value, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
						} else {
							zephir_array_fetch_long(&_10$$12, &findParams, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1152 TSRMLS_CC);
							ZEPHIR_INIT_LNVAR(_11$$12);
							ZEPHIR_CONCAT_SVSVS(&_11$$12, "(", &_10$$12, ") AND (", &value, ")");
							zephir_array_update_long(&findParams, 0, &_11$$12, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
						}
						continue;
					}
					zephir_array_update_zval(&findParams, &key, &value, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, findParamsOne, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		if (Z_TYPE_P(findParamsOne) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_12$$14);
			zephir_create_array(&_12$$14, 1, 0 TSRMLS_CC);
			zephir_array_update_string(&_12$$14, SL("conditions"), findParamsOne, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&findParams, &_12$$14);
		}
	}
	if (Z_TYPE_P(findParamsTwo) == IS_ARRAY) {
		zephir_is_iterable(findParamsTwo, 0, "phalcon/mvc/model/manager.zep", 1193);
		if (Z_TYPE_P(findParamsTwo) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(findParamsTwo), _15$$15, _16$$15, _13$$15)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_16$$15 != NULL) { 
					ZVAL_STR_COPY(&key, _16$$15);
				} else {
					ZVAL_LONG(&key, _15$$15);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _13$$15);
				_17$$16 = ZEPHIR_IS_LONG_IDENTICAL(&key, 0);
				if (!(_17$$16)) {
					_17$$16 = ZEPHIR_IS_STRING_IDENTICAL(&key, "conditions");
				}
				if (_17$$16) {
					if (!(zephir_array_isset_long(&findParams, 0))) {
						zephir_array_update_long(&findParams, 0, &value, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
					} else {
						zephir_array_fetch_long(&_18$$19, &findParams, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1173 TSRMLS_CC);
						ZEPHIR_INIT_LNVAR(_19$$19);
						ZEPHIR_CONCAT_SVSVS(&_19$$19, "(", &_18$$19, ") AND (", &value, ")");
						zephir_array_update_long(&findParams, 0, &_19$$19, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
					}
					continue;
				}
				_20$$16 = ZEPHIR_IS_STRING_IDENTICAL(&key, "bind");
				if (!(_20$$16)) {
					_20$$16 = ZEPHIR_IS_STRING_IDENTICAL(&key, "bindTypes");
				}
				if (_20$$16) {
					if (!(zephir_array_isset(&findParams, &key))) {
						if (Z_TYPE_P(&value) == IS_ARRAY) {
							zephir_array_update_zval(&findParams, &key, &value, PH_COPY | PH_SEPARATE);
						}
					} else {
						if (Z_TYPE_P(&value) == IS_ARRAY) {
							ZEPHIR_INIT_NVAR(&_21$$24);
							zephir_array_fetch(&_22$$24, &findParams, &key, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1185 TSRMLS_CC);
							zephir_fast_array_merge(&_21$$24, &_22$$24, &value TSRMLS_CC);
							zephir_array_update_zval(&findParams, &key, &_21$$24, PH_COPY | PH_SEPARATE);
						}
					}
					continue;
				}
				zephir_array_update_zval(&findParams, &key, &value, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, findParamsTwo, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_14$$15, findParamsTwo, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_14$$15)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, findParamsTwo, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, findParamsTwo, "current", NULL, 0);
				zephir_check_call_status();
					_23$$25 = ZEPHIR_IS_LONG_IDENTICAL(&key, 0);
					if (!(_23$$25)) {
						_23$$25 = ZEPHIR_IS_STRING_IDENTICAL(&key, "conditions");
					}
					if (_23$$25) {
						if (!(zephir_array_isset_long(&findParams, 0))) {
							zephir_array_update_long(&findParams, 0, &value, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
						} else {
							zephir_array_fetch_long(&_24$$28, &findParams, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1173 TSRMLS_CC);
							ZEPHIR_INIT_LNVAR(_25$$28);
							ZEPHIR_CONCAT_SVSVS(&_25$$28, "(", &_24$$28, ") AND (", &value, ")");
							zephir_array_update_long(&findParams, 0, &_25$$28, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
						}
						continue;
					}
					_26$$25 = ZEPHIR_IS_STRING_IDENTICAL(&key, "bind");
					if (!(_26$$25)) {
						_26$$25 = ZEPHIR_IS_STRING_IDENTICAL(&key, "bindTypes");
					}
					if (_26$$25) {
						if (!(zephir_array_isset(&findParams, &key))) {
							if (Z_TYPE_P(&value) == IS_ARRAY) {
								zephir_array_update_zval(&findParams, &key, &value, PH_COPY | PH_SEPARATE);
							}
						} else {
							if (Z_TYPE_P(&value) == IS_ARRAY) {
								ZEPHIR_INIT_NVAR(&_27$$33);
								zephir_array_fetch(&_28$$33, &findParams, &key, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1185 TSRMLS_CC);
								zephir_fast_array_merge(&_27$$33, &_28$$33, &value TSRMLS_CC);
								zephir_array_update_zval(&findParams, &key, &_27$$33, PH_COPY | PH_SEPARATE);
							}
						}
						continue;
					}
					zephir_array_update_zval(&findParams, &key, &value, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, findParamsTwo, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		if (Z_TYPE_P(findParamsTwo) == IS_STRING) {
			if (!(zephir_array_isset_long(&findParams, 0))) {
				zephir_array_update_long(&findParams, 0, findParamsTwo, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
			} else {
				zephir_array_fetch_long(&_29$$37, &findParams, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1198 TSRMLS_CC);
				ZEPHIR_INIT_VAR(&_30$$37);
				ZEPHIR_CONCAT_SVSVS(&_30$$37, "(", &_29$$37, ") AND (", findParamsTwo, ")");
				zephir_array_update_long(&findParams, 0, &_30$$37, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
			}
		}
	}
	RETURN_CCTOR(&findParams);

}

/**
 * Helper method to query records based on a relation definition
 *
 * @return \Phalcon\Mvc\Model\Resultset\Simple|Phalcon\Mvc\Model\Resultset\Simple|int|false
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationRecords) {

	zend_string *_19$$10;
	zend_ulong _18$$10;
	zval _34;
	zend_bool reusable = 0, _33$$20;
	zephir_fcall_cache_entry *_23 = NULL, *_28 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval method;
	zval *relation, relation_sub, *method_param = NULL, *record, record_sub, *parameters = NULL, parameters_sub, __$null, placeholders, referencedModel, intermediateModel, intermediateFields, joinConditions, fields, builder, extraParameters, conditions, refPosition, field, referencedFields, findParams, findArguments, retrieveMethod, uniqueKey, records, arguments, rows, firstRow, _0, _30, _31, _1$$4, _2$$4, _3$$6, _4$$6, _5$$3, _6$$3, _7$$3, _11$$3, _8$$8, _9$$8, _10$$8, _12$$9, _13$$9, _14$$9, _15$$10, *_16$$10, _17$$10, _20$$11, _21$$11, _22$$11, _24$$11, _25$$12, _26$$12, _27$$12, _29$$12, _32$$15;
	zval *this_ptr = getThis();

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
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_25$$12);
	ZVAL_UNDEF(&_26$$12);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_29$$12);
	ZVAL_UNDEF(&_32$$15);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_34);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &relation, &method_param, &record, &parameters);

	if (UNEXPECTED(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(method_param) == IS_STRING)) {
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
			zephir_array_append(&conditions, &_1$$4, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1249);
			ZEPHIR_CALL_METHOD(&_2$$4, record, "readattribute", NULL, 0, &fields);
			zephir_check_call_status();
			zephir_array_update_string(&placeholders, SL("APR0"), &_2$$4, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not supported", "phalcon/mvc/model/manager.zep", 1252);
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
			zephir_array_append(&joinConditions, &_4$$6, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1262);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not supported", "phalcon/mvc/model/manager.zep", 1264);
			return;
		}
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "_mergefindparameters", NULL, 332, &extraParameters, parameters);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&builder, this_ptr, "createbuilder", NULL, 0, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &builder, "from", NULL, 0, &referencedModel);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$3);
		zephir_fast_join_str(&_6$$3, SL(" AND "), &joinConditions TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &builder, "innerjoin", NULL, 0, &intermediateModel, &_6$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_7$$3);
		zephir_fast_join_str(&_7$$3, SL(" AND "), &conditions TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &builder, "andwhere", NULL, 0, &_7$$3, &placeholders);
		zephir_check_call_status();
		if (ZEPHIR_IS_STRING(&method, "count")) {
			ZEPHIR_INIT_VAR(&_8$$8);
			ZVAL_STRING(&_8$$8, "COUNT(*) AS rowcount");
			ZEPHIR_CALL_METHOD(NULL, &builder, "columns", NULL, 0, &_8$$8);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_9$$8, &builder, "getquery", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&rows, &_9$$8, "execute", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&firstRow, &rows, "getfirst", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_8$$8);
			ZVAL_STRING(&_8$$8, "rowcount");
			ZEPHIR_CALL_METHOD(&_10$$8, &firstRow, "readattribute", NULL, 0, &_8$$8);
			zephir_check_call_status();
			RETURN_MM_LONG(zephir_get_intval(&_10$$8));
		}
		ZEPHIR_CALL_METHOD(&_11$$3, &builder, "getquery", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(&_11$$3, "execute", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(&conditions);
	array_init(&conditions);
	ZEPHIR_CALL_METHOD(&fields, relation, "getfields", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&fields) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_12$$9, relation, "getreferencedfields", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_13$$9);
		ZEPHIR_CONCAT_SVS(&_13$$9, "[", &_12$$9, "] = :APR0:");
		zephir_array_append(&conditions, &_13$$9, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1301);
		ZEPHIR_CALL_METHOD(&_14$$9, record, "readattribute", NULL, 0, &fields);
		zephir_check_call_status();
		zephir_array_update_string(&placeholders, SL("APR0"), &_14$$9, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_CALL_METHOD(&referencedFields, relation, "getreferencedfields", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_15$$10, relation, "getfields", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(&_15$$10, 0, "phalcon/mvc/model/manager.zep", 1313);
		if (Z_TYPE_P(&_15$$10) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_15$$10), _18$$10, _19$$10, _16$$10)
			{
				ZEPHIR_INIT_NVAR(&refPosition);
				if (_19$$10 != NULL) { 
					ZVAL_STR_COPY(&refPosition, _19$$10);
				} else {
					ZVAL_LONG(&refPosition, _18$$10);
				}
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _16$$10);
				zephir_array_fetch(&_20$$11, &referencedFields, &refPosition, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1310 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_21$$11);
				ZEPHIR_CONCAT_SVSVS(&_21$$11, "[", &_20$$11, "] = :APR", &refPosition, ":");
				zephir_array_append(&conditions, &_21$$11, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1310);
				ZEPHIR_CALL_METHOD(&_22$$11, record, "readattribute", &_23, 0, &field);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_24$$11);
				ZEPHIR_CONCAT_SV(&_24$$11, "APR", &refPosition);
				zephir_array_update_zval(&placeholders, &_24$$11, &_22$$11, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_15$$10, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_17$$10, &_15$$10, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_17$$10)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&refPosition, &_15$$10, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&field, &_15$$10, "current", NULL, 0);
				zephir_check_call_status();
					zephir_array_fetch(&_25$$12, &referencedFields, &refPosition, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1310 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_26$$12);
					ZEPHIR_CONCAT_SVSVS(&_26$$12, "[", &_25$$12, "] = :APR", &refPosition, ":");
					zephir_array_append(&conditions, &_26$$12, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1310);
					ZEPHIR_CALL_METHOD(&_27$$12, record, "readattribute", &_28, 0, &field);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_29$$12);
					ZEPHIR_CONCAT_SV(&_29$$12, "APR", &refPosition);
					zephir_array_update_zval(&placeholders, &_29$$12, &_27$$12, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &_15$$10, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&field);
		ZEPHIR_INIT_NVAR(&refPosition);
	}
	ZEPHIR_INIT_VAR(&findParams);
	zephir_create_array(&findParams, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_30);
	zephir_fast_join_str(&_30, SL(" AND "), &conditions TSRMLS_CC);
	zephir_array_fast_append(&findParams, &_30);
	zephir_array_update_string(&findParams, SL("bind"), &placeholders, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_31, record, "getdi", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&findParams, SL("di"), &_31, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&findArguments, this_ptr, "_mergefindparameters", NULL, 332, &findParams, parameters);
	zephir_check_call_status();
	if (Z_TYPE_P(&extraParameters) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&findParams, this_ptr, "_mergefindparameters", NULL, 332, &extraParameters, &findArguments);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&findParams, &findArguments);
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&method, "")) {
		ZEPHIR_CALL_METHOD(&_32$$15, relation, "gettype", NULL, 0);
		zephir_check_call_status();
		do {
			if (ZEPHIR_IS_LONG(&_32$$15, 0) || ZEPHIR_IS_LONG(&_32$$15, 1)) {
				ZEPHIR_INIT_VAR(&retrieveMethod);
				ZVAL_STRING(&retrieveMethod, "findFirst");
				break;
			}
			if (ZEPHIR_IS_LONG(&_32$$15, 2)) {
				ZEPHIR_INIT_NVAR(&retrieveMethod);
				ZVAL_STRING(&retrieveMethod, "find");
				break;
			}
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Unknown relation type", "phalcon/mvc/model/manager.zep", 1349);
			return;
		} while(0);

	} else {
		ZEPHIR_CPY_WRT(&retrieveMethod, &method);
	}
	ZEPHIR_INIT_VAR(&arguments);
	zephir_create_array(&arguments, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&arguments, &findParams);
	ZEPHIR_CALL_METHOD(&_31, relation, "isreusable", NULL, 0);
	zephir_check_call_status();
	reusable = zephir_get_boolval(&_31);
	if (reusable) {
		ZEPHIR_INIT_VAR(&uniqueKey);
		zephir_unique_key(&uniqueKey, &referencedModel, &arguments TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&records, this_ptr, "getreusablerecords", NULL, 0, &referencedModel, &uniqueKey);
		zephir_check_call_status();
		_33$$20 = Z_TYPE_P(&records) == IS_ARRAY;
		if (!(_33$$20)) {
			_33$$20 = Z_TYPE_P(&records) == IS_OBJECT;
		}
		if (_33$$20) {
			RETURN_CCTOR(&records);
		}
	}
	ZEPHIR_INIT_VAR(&_34);
	zephir_create_array(&_34, 2, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_31, this_ptr, "load", NULL, 0, &referencedModel);
	zephir_check_call_status();
	zephir_array_fast_append(&_34, &_31);
	zephir_array_fast_append(&_34, &retrieveMethod);
	ZEPHIR_INIT_NVAR(&records);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&records, &_34, &arguments);
	zephir_check_call_status();
	if (reusable) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setreusablerecords", NULL, 0, &referencedModel, &uniqueKey, &records);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&records);

}

/**
 * Returns a reusable object from the internal list
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getReusableRecords) {

	zval *modelName_param = NULL, *key_param = NULL, records, _0;
	zval modelName, key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modelName_param, &key_param);

	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}
	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	zephir_read_property(&_0, this_ptr, SL("_reusable"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&records, &_0, &key, 1 TSRMLS_CC)) {
		RETURN_CTOR(&records);
	}
	RETURN_MM_NULL();

}

/**
 * Stores a reusable record in the internal list
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setReusableRecords) {

	zval *modelName_param = NULL, *key_param = NULL, *records, records_sub;
	zval modelName, key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&records_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &modelName_param, &key_param, &records);

	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}
	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	zephir_update_property_array(this_ptr, SL("_reusable"), &key, records);
	ZEPHIR_MM_RESTORE();

}

/**
 * Clears the internal reusable list
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, clearReusableObjects) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("_reusable"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets belongsTo related records from a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getBelongsToRecords) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *modelName_param = NULL, *modelRelation, modelRelation_sub, *record, record_sub, *parameters = NULL, parameters_sub, __$null, keyRelation, relations, _0, _1, _2, _3;
	zval method, modelName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&modelRelation_sub);
	ZVAL_UNDEF(&record_sub);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&keyRelation);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &method_param, &modelName_param, &modelRelation, &record, &parameters);

	if (UNEXPECTED(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(&method, method_param);
	} else {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_EMPTY_STRING(&method);
	}
	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, &modelName);
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strtolower(&_1, modelRelation);
	ZEPHIR_INIT_VAR(&keyRelation);
	ZEPHIR_CONCAT_VSV(&keyRelation, &_0, "$", &_1);
	ZEPHIR_OBS_VAR(&relations);
	zephir_read_property(&_2, this_ptr, SL("_hasMany"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&relations, &_2, &keyRelation, 0 TSRMLS_CC))) {
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_long(&_3, &relations, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1433 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrelationrecords", NULL, 0, &_3, &method, record, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets hasMany related records from a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasManyRecords) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *modelName_param = NULL, *modelRelation, modelRelation_sub, *record, record_sub, *parameters = NULL, parameters_sub, __$null, keyRelation, relations, _0, _1, _2, _3;
	zval method, modelName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&modelRelation_sub);
	ZVAL_UNDEF(&record_sub);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&keyRelation);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &method_param, &modelName_param, &modelRelation, &record, &parameters);

	if (UNEXPECTED(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(&method, method_param);
	} else {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_EMPTY_STRING(&method);
	}
	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, &modelName);
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strtolower(&_1, modelRelation);
	ZEPHIR_INIT_VAR(&keyRelation);
	ZEPHIR_CONCAT_VSV(&keyRelation, &_0, "$", &_1);
	ZEPHIR_OBS_VAR(&relations);
	zephir_read_property(&_2, this_ptr, SL("_hasMany"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&relations, &_2, &keyRelation, 0 TSRMLS_CC))) {
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_long(&_3, &relations, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1456 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrelationrecords", NULL, 0, &_3, &method, record, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets belongsTo related records from a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOneRecords) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *modelName_param = NULL, *modelRelation, modelRelation_sub, *record, record_sub, *parameters = NULL, parameters_sub, __$null, keyRelation, relations, _0, _1, _2, _3;
	zval method, modelName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&modelRelation_sub);
	ZVAL_UNDEF(&record_sub);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&keyRelation);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &method_param, &modelName_param, &modelRelation, &record, &parameters);

	if (UNEXPECTED(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(&method, method_param);
	} else {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_EMPTY_STRING(&method);
	}
	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, &modelName);
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strtolower(&_1, modelRelation);
	ZEPHIR_INIT_VAR(&keyRelation);
	ZEPHIR_CONCAT_VSV(&keyRelation, &_0, "$", &_1);
	ZEPHIR_OBS_VAR(&relations);
	zephir_read_property(&_2, this_ptr, SL("_hasOne"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&relations, &_2, &keyRelation, 0 TSRMLS_CC))) {
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_long(&_3, &relations, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/manager.zep", 1479 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrelationrecords", NULL, 0, &_3, &method, record, parameters);
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

	zval *model, model_sub, relations, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	zephir_read_property(&_0, this_ptr, SL("_belongsToSingle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_get_class(&_1, model, 1 TSRMLS_CC);
	if (!(zephir_array_isset_fetch(&relations, &_0, &_1, 1 TSRMLS_CC))) {
		array_init(return_value);
		RETURN_MM();
	}
	RETURN_CTOR(&relations);

}

/**
 * Gets hasMany relations defined on a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasMany) {

	zval *model, model_sub, relations, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	zephir_read_property(&_0, this_ptr, SL("_hasManySingle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_get_class(&_1, model, 1 TSRMLS_CC);
	if (!(zephir_array_isset_fetch(&relations, &_0, &_1, 1 TSRMLS_CC))) {
		array_init(return_value);
		RETURN_MM();
	}
	RETURN_CTOR(&relations);

}

/**
 * Gets hasOne relations defined on a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOne) {

	zval *model, model_sub, relations, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	zephir_read_property(&_0, this_ptr, SL("_hasOneSingle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_get_class(&_1, model, 1 TSRMLS_CC);
	if (!(zephir_array_isset_fetch(&relations, &_0, &_1, 1 TSRMLS_CC))) {
		array_init(return_value);
		RETURN_MM();
	}
	RETURN_CTOR(&relations);

}

/**
 * Gets hasManyToMany relations defined on a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasManyToMany) {

	zval *model, model_sub, relations, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	zephir_read_property(&_0, this_ptr, SL("_hasManyToManySingle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_get_class(&_1, model, 1 TSRMLS_CC);
	if (!(zephir_array_isset_fetch(&relations, &_0, &_1, 1 TSRMLS_CC))) {
		array_init(return_value);
		RETURN_MM();
	}
	RETURN_CTOR(&relations);

}

/**
 * Gets hasOne relations defined on a model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOneAndHasMany) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, _0, _1;
	zval *this_ptr = getThis();

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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *modelName_param = NULL, entityName, allRelations, relations, relation, _0, _3, _6, *_1$$3, _2$$3, *_4$$6, _5$$6, *_7$$9, _8$$9;
	zval modelName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&entityName);
	ZVAL_UNDEF(&allRelations);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_8$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modelName_param);

	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}


	ZEPHIR_INIT_VAR(&entityName);
	zephir_fast_strtolower(&entityName, &modelName);
	ZEPHIR_INIT_VAR(&allRelations);
	array_init(&allRelations);
	ZEPHIR_OBS_VAR(&relations);
	zephir_read_property(&_0, this_ptr, SL("_belongsToSingle"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&relations, &_0, &entityName, 0 TSRMLS_CC)) {
		zephir_is_iterable(&relations, 0, "phalcon/mvc/model/manager.zep", 1569);
		if (Z_TYPE_P(&relations) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relations), _1$$3)
			{
				ZEPHIR_INIT_NVAR(&relation);
				ZVAL_COPY(&relation, _1$$3);
				zephir_array_append(&allRelations, &relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1567);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &relations, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_2$$3, &relations, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_2$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&relation, &relations, "current", NULL, 0);
				zephir_check_call_status();
					zephir_array_append(&allRelations, &relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1567);
				ZEPHIR_CALL_METHOD(NULL, &relations, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&relation);
	}
	ZEPHIR_OBS_NVAR(&relations);
	zephir_read_property(&_3, this_ptr, SL("_hasManySingle"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&relations, &_3, &entityName, 0 TSRMLS_CC)) {
		zephir_is_iterable(&relations, 0, "phalcon/mvc/model/manager.zep", 1578);
		if (Z_TYPE_P(&relations) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relations), _4$$6)
			{
				ZEPHIR_INIT_NVAR(&relation);
				ZVAL_COPY(&relation, _4$$6);
				zephir_array_append(&allRelations, &relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1576);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &relations, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_5$$6, &relations, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$6)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&relation, &relations, "current", NULL, 0);
				zephir_check_call_status();
					zephir_array_append(&allRelations, &relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1576);
				ZEPHIR_CALL_METHOD(NULL, &relations, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&relation);
	}
	ZEPHIR_OBS_NVAR(&relations);
	zephir_read_property(&_6, this_ptr, SL("_hasOneSingle"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&relations, &_6, &entityName, 0 TSRMLS_CC)) {
		zephir_is_iterable(&relations, 0, "phalcon/mvc/model/manager.zep", 1587);
		if (Z_TYPE_P(&relations) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relations), _7$$9)
			{
				ZEPHIR_INIT_NVAR(&relation);
				ZVAL_COPY(&relation, _7$$9);
				zephir_array_append(&allRelations, &relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1585);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &relations, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_8$$9, &relations, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_8$$9)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&relation, &relations, "current", NULL, 0);
				zephir_check_call_status();
					zephir_array_append(&allRelations, &relation, PH_SEPARATE, "phalcon/mvc/model/manager.zep", 1585);
				ZEPHIR_CALL_METHOD(NULL, &relations, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&relation);
	}
	RETURN_CCTOR(&allRelations);

}

/**
 * Query the first relationship defined between two models
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationsBetween) {

	zval *first_param = NULL, *second_param = NULL, keyRelation, relations, _0, _1, _2, _3, _4;
	zval first, second;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&first);
	ZVAL_UNDEF(&second);
	ZVAL_UNDEF(&keyRelation);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &first_param, &second_param);

	if (UNEXPECTED(Z_TYPE_P(first_param) != IS_STRING && Z_TYPE_P(first_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'first' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(first_param) == IS_STRING)) {
		zephir_get_strval(&first, first_param);
	} else {
		ZEPHIR_INIT_VAR(&first);
		ZVAL_EMPTY_STRING(&first);
	}
	if (UNEXPECTED(Z_TYPE_P(second_param) != IS_STRING && Z_TYPE_P(second_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'second' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(second_param) == IS_STRING)) {
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
	ZEPHIR_OBS_VAR(&relations);
	zephir_read_property(&_2, this_ptr, SL("_belongsTo"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&relations, &_2, &keyRelation, 0 TSRMLS_CC)) {
		RETURN_CCTOR(&relations);
	}
	ZEPHIR_OBS_NVAR(&relations);
	zephir_read_property(&_3, this_ptr, SL("_hasMany"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&relations, &_3, &keyRelation, 0 TSRMLS_CC)) {
		RETURN_CCTOR(&relations);
	}
	ZEPHIR_OBS_NVAR(&relations);
	zephir_read_property(&_4, this_ptr, SL("_hasOne"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&relations, &_4, &keyRelation, 0 TSRMLS_CC)) {
		RETURN_CCTOR(&relations);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Creates a Phalcon\Mvc\Model\Query without execute it
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, createQuery) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *phql_param = NULL, dependencyInjector, query, _0, _2;
	zval phql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&phql);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &phql_param);

	if (UNEXPECTED(Z_TYPE_P(phql_param) != IS_STRING && Z_TYPE_P(phql_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'phql' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(phql_param) == IS_STRING)) {
		zephir_get_strval(&phql, phql_param);
	} else {
		ZEPHIR_INIT_VAR(&phql);
		ZVAL_EMPTY_STRING(&phql);
	}


	ZEPHIR_OBS_VAR(&dependencyInjector);
	zephir_read_property(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injection object is required to access ORM services", "phalcon/mvc/model/manager.zep", 1634);
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
	RETURN_CCTOR(&query);

}

/**
 * Creates a Phalcon\Mvc\Model\Query and execute it
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, executeQuery) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *phql_param = NULL, *placeholders = NULL, placeholders_sub, *types = NULL, types_sub, __$null, query;
	zval phql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&phql);
	ZVAL_UNDEF(&placeholders_sub);
	ZVAL_UNDEF(&types_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&query);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &phql_param, &placeholders, &types);

	if (UNEXPECTED(Z_TYPE_P(phql_param) != IS_STRING && Z_TYPE_P(phql_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'phql' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(phql_param) == IS_STRING)) {
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


	ZEPHIR_CALL_METHOD(&query, this_ptr, "createquery", NULL, 0, &phql);
	zephir_check_call_status();
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL, params_sub, __$null, dependencyInjector, _0, _1, _3;
	zval *this_ptr = getThis();

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injection object is required to access ORM services", "phalcon/mvc/model/manager.zep", 1677);
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
	RETURN_CCTOR(&_1);

}

/**
 * Returns the last query created or executed in the models manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getLastQuery) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_lastQuery");

}

/**
 * Registers shorter aliases for namespaces in PHQL statements
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, registerNamespaceAlias) {

	zval *alias_param = NULL, *namespaceName_param = NULL;
	zval alias, namespaceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&namespaceName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &alias_param, &namespaceName_param);

	zephir_get_strval(&alias, alias_param);
	zephir_get_strval(&namespaceName, namespaceName_param);


	zephir_update_property_array(this_ptr, SL("_namespaceAliases"), &alias, &namespaceName);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a real namespace from its alias
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getNamespaceAlias) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *alias_param = NULL, namespaceName, _0, _1;
	zval alias, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &alias_param);

	if (UNEXPECTED(Z_TYPE_P(alias_param) != IS_STRING && Z_TYPE_P(alias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(alias_param) == IS_STRING)) {
		zephir_get_strval(&alias, alias_param);
	} else {
		ZEPHIR_INIT_VAR(&alias);
		ZVAL_EMPTY_STRING(&alias);
	}


	ZEPHIR_OBS_VAR(&namespaceName);
	zephir_read_property(&_0, this_ptr, SL("_namespaceAliases"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&namespaceName, &_0, &alias, 0 TSRMLS_CC)) {
		RETURN_CCTOR(&namespaceName);
	}
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalcon_mvc_model_exception_ce);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVS(&_2, "Namespace alias '", &alias, "' is not registered");
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 4, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_1, "phalcon/mvc/model/manager.zep", 1718 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Returns all the registered namespace aliases
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getNamespaceAliases) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_namespaceAliases");

}

/**
 * Destroys the current PHQL cache
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, __destruct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	phalcon_orm_destroy_cache(TSRMLS_C);
	ZEPHIR_CALL_CE_STATIC(NULL, phalcon_mvc_model_query_ce, "clean", &_0, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Phalcon_Mvc_Model_Manager(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _6, _8, _10, _12, _14, _16, _18, _20, _22, _24, _26, _28, _30, _32, _34, _36, _38, _40, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7, _11$$8, _13$$9, _15$$10, _17$$11, _19$$12, _21$$13, _23$$14, _25$$15, _27$$16, _29$$17, _31$$18, _33$$19, _35$$20, _37$$21, _39$$22, _41$$23;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_25$$15);
	ZVAL_UNDEF(&_27$$16);
	ZVAL_UNDEF(&_29$$17);
	ZVAL_UNDEF(&_31$$18);
	ZVAL_UNDEF(&_33$$19);
	ZVAL_UNDEF(&_35$$20);
	ZVAL_UNDEF(&_37$$21);
	ZVAL_UNDEF(&_39$$22);
	ZVAL_UNDEF(&_41$$23);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_namespaceAliases"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_namespaceAliases"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("_dynamicUpdate"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("_dynamicUpdate"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("_keepSnapshots"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("_keepSnapshots"), &_5$$5);
		}
		zephir_read_property(&_6, this_ptr, SL("_reusable"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval(this_ptr, SL("_reusable"), &_7$$6);
		}
		zephir_read_property(&_8, this_ptr, SL("_behaviors"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval(this_ptr, SL("_behaviors"), &_9$$7);
		}
		zephir_read_property(&_10, this_ptr, SL("_schemas"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			array_init(&_11$$8);
			zephir_update_property_zval(this_ptr, SL("_schemas"), &_11$$8);
		}
		zephir_read_property(&_12, this_ptr, SL("_sources"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_12) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_13$$9);
			array_init(&_13$$9);
			zephir_update_property_zval(this_ptr, SL("_sources"), &_13$$9);
		}
		zephir_read_property(&_14, this_ptr, SL("_initialized"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_14) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_15$$10);
			array_init(&_15$$10);
			zephir_update_property_zval(this_ptr, SL("_initialized"), &_15$$10);
		}
		zephir_read_property(&_16, this_ptr, SL("_hasManyToManySingle"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_16) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_17$$11);
			array_init(&_17$$11);
			zephir_update_property_zval(this_ptr, SL("_hasManyToManySingle"), &_17$$11);
		}
		zephir_read_property(&_18, this_ptr, SL("_hasManyToMany"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_18) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_19$$12);
			array_init(&_19$$12);
			zephir_update_property_zval(this_ptr, SL("_hasManyToMany"), &_19$$12);
		}
		zephir_read_property(&_20, this_ptr, SL("_belongsToSingle"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_20) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_21$$13);
			array_init(&_21$$13);
			zephir_update_property_zval(this_ptr, SL("_belongsToSingle"), &_21$$13);
		}
		zephir_read_property(&_22, this_ptr, SL("_belongsTo"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_22) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_23$$14);
			array_init(&_23$$14);
			zephir_update_property_zval(this_ptr, SL("_belongsTo"), &_23$$14);
		}
		zephir_read_property(&_24, this_ptr, SL("_hasOneSingle"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_24) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_25$$15);
			array_init(&_25$$15);
			zephir_update_property_zval(this_ptr, SL("_hasOneSingle"), &_25$$15);
		}
		zephir_read_property(&_26, this_ptr, SL("_hasOne"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_26) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_27$$16);
			array_init(&_27$$16);
			zephir_update_property_zval(this_ptr, SL("_hasOne"), &_27$$16);
		}
		zephir_read_property(&_28, this_ptr, SL("_hasManySingle"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_28) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_29$$17);
			array_init(&_29$$17);
			zephir_update_property_zval(this_ptr, SL("_hasManySingle"), &_29$$17);
		}
		zephir_read_property(&_30, this_ptr, SL("_hasMany"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_30) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_31$$18);
			array_init(&_31$$18);
			zephir_update_property_zval(this_ptr, SL("_hasMany"), &_31$$18);
		}
		zephir_read_property(&_32, this_ptr, SL("_modelVisibility"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_32) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_33$$19);
			array_init(&_33$$19);
			zephir_update_property_zval(this_ptr, SL("_modelVisibility"), &_33$$19);
		}
		zephir_read_property(&_34, this_ptr, SL("_aliases"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_34) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_35$$20);
			array_init(&_35$$20);
			zephir_update_property_zval(this_ptr, SL("_aliases"), &_35$$20);
		}
		zephir_read_property(&_36, this_ptr, SL("_writeConnectionServices"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_36) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_37$$21);
			array_init(&_37$$21);
			zephir_update_property_zval(this_ptr, SL("_writeConnectionServices"), &_37$$21);
		}
		zephir_read_property(&_38, this_ptr, SL("_readConnectionServices"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_38) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_39$$22);
			array_init(&_39$$22);
			zephir_update_property_zval(this_ptr, SL("_readConnectionServices"), &_39$$22);
		}
		zephir_read_property(&_40, this_ptr, SL("_customEventsManager"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_40) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_41$$23);
			array_init(&_41$$23);
			zephir_update_property_zval(this_ptr, SL("_customEventsManager"), &_41$$23);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

