
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "ext/json/php_json.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/iterator.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model
 *
 * Phalcon\Mvc\Model connects business objects and database tables to create a
 * persistable domain model where logic and data are presented in one wrapping.
 * It‘s an implementation of the object-relational mapping (ORM).
 *
 * A model represents the information (data) of the application and the rules to
 * manipulate that data. Models are primarily used for managing the rules of
 * interaction with a corresponding database table. In most cases, each table in
 * your database will correspond to one model in your application. The bulk of
 * your application's business logic will be concentrated in the models.
 *
 * Phalcon\Mvc\Model is the first ORM written in Zephir/C languages for PHP,
 * giving to developers high performance when interacting with databases while
 * is also easy to use.
 *
 * ```php
 * $robot = new Robots();
 *
 * $robot->type = "mechanical";
 * $robot->name = "Astro Boy";
 * $robot->year = 1952;
 *
 * if ($robot->save() === false) {
 *     echo "Umh, We can store robots: ";
 *
 *     $messages = $robot->getMessages();
 *
 *     foreach ($messages as $message) {
 *         echo $message;
 *     }
 * } else {
 *     echo "Great, a new robot was saved successfully!";
 * }
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc, Model, phalcon, mvc_model, phalcon_di_abstractinjectionaware_ce, phalcon_mvc_model_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_mvc_model_ce, SL("dirtyState"), 1, ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_ce, SL("dirtyRelated"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_ce, SL("errorMessages"), ZEND_ACC_PROTECTED);
	/**
	 * @var ManagerInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_model_ce, SL("modelsManager"), ZEND_ACC_PROTECTED);
	/**
	 * @var MetaDataInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_model_ce, SL("modelsMetaData"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_ce, SL("related"), ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_mvc_model_ce, SL("operationMade"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_ce, SL("oldSnapshot"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_model_ce, SL("skipped"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_ce, SL("snapshot"), ZEND_ACC_PROTECTED);
	/**
	 * @var TransactionInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_model_ce, SL("transaction"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_mvc_model_ce, SL("uniqueKey"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_ce, SL("uniqueParams"), ZEND_ACC_PROTECTED);
	/**
	 * @var array|null
	 * TODO: Make it always array in code
	 */
	zend_declare_property_null(phalcon_mvc_model_ce, SL("uniqueTypes"), ZEND_ACC_PROTECTED);
	phalcon_mvc_model_ce->create_object = zephir_init_properties_Phalcon_Mvc_Model;
	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("DIRTY_STATE_DETACHED"), 2);

	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("DIRTY_STATE_PERSISTENT"), 0);

	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("DIRTY_STATE_TRANSIENT"), 1);

	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_CREATE"), 1);

	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_DELETE"), 3);

	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_NONE"), 0);

	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_UPDATE"), 2);

	zephir_declare_class_constant_string(phalcon_mvc_model_ce, SL("TRANSACTION_INDEX"), "transaction");

	zend_class_implements(phalcon_mvc_model_ce, 1, phalcon_mvc_entityinterface_ce);
	zend_class_implements(phalcon_mvc_model_ce, 1, phalcon_mvc_modelinterface_ce);
	zend_class_implements(phalcon_mvc_model_ce, 1, phalcon_mvc_model_resultinterface_ce);
	zend_class_implements(phalcon_mvc_model_ce, 1, zend_ce_serializable);
	zend_class_implements(phalcon_mvc_model_ce, 1, php_json_serializable_ce);
	return SUCCESS;
}

/**
 */
PHP_METHOD(Phalcon_Mvc_Model, getTransaction)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "transaction");
}

/**
 * Phalcon\Mvc\Model constructor
 */
PHP_METHOD(Phalcon_Mvc_Model, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *data = NULL, data_sub, *container = NULL, container_sub, *modelsManager = NULL, modelsManager_sub, __$null, _1$$5, _2$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&modelsManager_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(container, phalcon_di_diinterface_ce)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(modelsManager, phalcon_mvc_model_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &data, &container, &modelsManager);
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!container) {
		container = &container_sub;
		ZEPHIR_CPY_WRT(container, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(container);
	}
	if (!modelsManager) {
		modelsManager = &modelsManager_sub;
		ZEPHIR_CPY_WRT(modelsManager, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(modelsManager);
	}


	if (Z_TYPE_P(container) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(container, phalcon_di_ce, "getdefault", &_0, 0);
		zephir_check_call_status();
	}
	if (UNEXPECTED(Z_TYPE_P(container) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injection container is required to access the services related to the ODM", "phalcon/Mvc/Model.zep", 183);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), container);
	if (Z_TYPE_P(modelsManager) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_2$$5);
		ZVAL_STRING(&_2$$5, "modelsManager");
		ZEPHIR_CALL_METHOD(&_1$$5, container, "getshared", NULL, 0, &_2$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(modelsManager, &_1$$5);
		if (UNEXPECTED(Z_TYPE_P(modelsManager) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsManager' is not valid", "phalcon/Mvc/Model.zep", 197);
			return;
		}
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("modelsManager"), modelsManager);
	ZEPHIR_CALL_METHOD(NULL, modelsManager, "initialize", NULL, 0, this_ptr);
	zephir_check_call_status();
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("onconstruct")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "onconstruct", NULL, 0, data);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(data) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "assign", NULL, 0, data);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Handles method calls when a method is not implemented
 *
 * @return mixed
 * @throws \Phalcon\Mvc\Model\Exception If the method doesn't exist
 */
PHP_METHOD(Phalcon_Mvc_Model, __call)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval arguments;
	zval *method_param = NULL, *arguments_param = NULL, modelName, status, records, _1, _2, _3;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&arguments);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(method)
		Z_PARAM_ARRAY(arguments)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &arguments_param);
	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&arguments, arguments_param);


	ZEPHIR_CALL_SELF(&records, "invokefinder", &_0, 468, &method, &arguments);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&records)) {
		RETURN_CCTOR(&records);
	}
	ZEPHIR_INIT_VAR(&modelName);
	zephir_get_class(&modelName, this_ptr, 0);
	ZEPHIR_CALL_METHOD(&records, this_ptr, "getrelatedrecords", NULL, 0, &modelName, &method, &arguments);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&records)) {
		RETURN_CCTOR(&records);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&status, &_1, "missingmethod", NULL, 0, this_ptr, &method, &arguments);
	zephir_check_call_status();
	if (Z_TYPE_P(&status) != IS_NULL) {
		RETURN_CCTOR(&status);
	}
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, phalcon_mvc_model_exception_ce);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SVSVS(&_3, "The method '", &method, "' doesn't exist on model '", &modelName, "'");
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 30, &_3);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_2, "phalcon/Mvc/Model.zep", 266);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Handles method calls when a static method is not implemented
 *
 * @return mixed
 * @throws \Phalcon\Mvc\Model\Exception If the method doesn't exist
 */
PHP_METHOD(Phalcon_Mvc_Model, __callStatic)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval arguments;
	zval *method_param = NULL, *arguments_param = NULL, modelName, records, _1, _2;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&arguments);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(method)
		Z_PARAM_ARRAY(arguments)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &arguments_param);
	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&arguments, arguments_param);


	ZEPHIR_CALL_SELF(&records, "invokefinder", &_0, 468, &method, &arguments);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&records)) {
		RETURN_CCTOR(&records);
	}
	ZEPHIR_INIT_VAR(&modelName);
	zephir_get_called_class(&modelName);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalcon_mvc_model_exception_ce);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVSVS(&_2, "The method '", &method, "' doesn't exist on model '", &modelName, "'");
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 30, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_1, "phalcon/Mvc/Model.zep", 292);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Magic method to get related records using the relation alias as a
 * property
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, __get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, modelName, manager, lowerProperty, relation, _0, _4, _5, _6, _1$$3, _2$$4, _3$$4;
	zval property, method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&lowerProperty);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(property)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property_param);
	if (UNEXPECTED(Z_TYPE_P(property_param) != IS_STRING && Z_TYPE_P(property_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'property' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(property_param) == IS_STRING)) {
		zephir_get_strval(&property, property_param);
	} else {
		ZEPHIR_INIT_VAR(&property);
	}


	ZEPHIR_INIT_VAR(&modelName);
	zephir_get_class(&modelName, this_ptr, 0);
	ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&lowerProperty);
	zephir_fast_strtolower(&lowerProperty, &property);
	ZEPHIR_CALL_METHOD(&_0, &manager, "getrelationbyalias", NULL, 0, &modelName, &lowerProperty);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&relation, &_0);
	if (Z_TYPE_P(&relation) == IS_OBJECT) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("dirtyRelated"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset(&_1$$3, &lowerProperty)) {
			zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("dirtyRelated"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_3$$4, &_2$$4, &lowerProperty, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 324);
			RETURN_CTOR(&_3$$4);
		}
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrelated", NULL, 0, &lowerProperty);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_4);
	zephir_camelize(&_4, &property, NULL  );
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_SV(&_5, "get", &_4);
	zephir_get_strval(&method, &_5);
	if ((zephir_method_exists(this_ptr, &method)  == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &method, NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CONCAT_SVSV(&_6, "Access to undefined property ", &modelName, "::", &property);
	ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 7, &_6);
	zephir_check_call_status();
	RETURN_MM_NULL();
}

/**
 * Magic method to check if a property is a valid relation
 */
PHP_METHOD(Phalcon_Mvc_Model, __isset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, manager, method, modelName, relation, result, _0, _1$$4;
	zval property;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(property)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property_param);
	if (UNEXPECTED(Z_TYPE_P(property_param) != IS_STRING && Z_TYPE_P(property_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'property' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(property_param) == IS_STRING)) {
		zephir_get_strval(&property, property_param);
	} else {
		ZEPHIR_INIT_VAR(&property);
	}


	ZEPHIR_INIT_VAR(&modelName);
	zephir_get_class(&modelName, this_ptr, 0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&_0, &manager, "getrelationbyalias", NULL, 0, &modelName, &property);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&relation, &_0);
	if (Z_TYPE_P(&relation) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&result);
		ZVAL_BOOL(&result, 1);
	} else {
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_camelize(&_1$$4, &property, NULL  );
		ZEPHIR_INIT_VAR(&method);
		ZEPHIR_CONCAT_SV(&method, "get", &_1$$4);
		ZEPHIR_INIT_NVAR(&result);
		ZVAL_BOOL(&result, (zephir_method_exists(this_ptr, &method)  == SUCCESS));
	}
	RETURN_CCTOR(&result);
}

/**
 * Magic method to assign values to the the model
 *
 * @param mixed value
 */
PHP_METHOD(Phalcon_Mvc_Model, __set)
{
	zend_bool _0;
	zval related;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, *value, value_sub, lowerProperty, modelName, manager, relation, referencedModel, item, dirtyState, _14, _15, _1$$3, _2$$4, _3$$4, _4$$6, _5$$7, _6$$8, _7$$9, _8$$9, *_9$$10, _10$$10, _11$$10, _12$$17, _13$$18, _16$$20, _17$$21;
	zval property, _18$$21;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&_18$$21);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&lowerProperty);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&referencedModel);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&dirtyState);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$17);
	ZVAL_UNDEF(&_13$$18);
	ZVAL_UNDEF(&_16$$20);
	ZVAL_UNDEF(&_17$$21);
	ZVAL_UNDEF(&related);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(property)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &property_param, &value);
	zephir_get_strval(&property, property_param);


	_0 = Z_TYPE_P(value) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(value, phalcon_mvc_modelinterface_ce);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&lowerProperty);
		zephir_fast_strtolower(&lowerProperty, &property);
		ZEPHIR_INIT_VAR(&modelName);
		zephir_get_class(&modelName, this_ptr, 0);
		ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1$$3, &manager, "getrelationbyalias", NULL, 0, &modelName, &lowerProperty);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_1$$3);
		if (Z_TYPE_P(&relation) == IS_OBJECT) {
			zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("dirtyState"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&dirtyState, &_2$$4);
			ZEPHIR_CALL_METHOD(&_3$$4, value, "getdirtystate", NULL, 0);
			zephir_check_call_status();
			if (!ZEPHIR_IS_EQUAL(&_3$$4, &dirtyState)) {
				ZEPHIR_INIT_NVAR(&dirtyState);
				ZVAL_LONG(&dirtyState, 1);
			}
			zephir_unset_property_array(this_ptr, ZEND_STRL("related"), &lowerProperty);
			zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("related"), PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_2$$4, &lowerProperty, PH_SEPARATE);
			zephir_update_property_array(this_ptr, SL("dirtyRelated"), &lowerProperty, value);
			zephir_update_property_zval(this_ptr, ZEND_STRL("dirtyState"), &dirtyState);
			RETVAL_ZVAL(value, 1, 0);
			RETURN_MM();
		}
	} else if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&lowerProperty);
		zephir_fast_strtolower(&lowerProperty, &property);
		ZEPHIR_INIT_NVAR(&modelName);
		zephir_get_class(&modelName, this_ptr, 0);
		ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$6, &manager, "getrelationbyalias", NULL, 0, &modelName, &lowerProperty);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_4$$6);
		if (Z_TYPE_P(&relation) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&_5$$7, &relation, "gettype", NULL, 0);
			zephir_check_call_status();
			do {
				if (ZEPHIR_IS_LONG(&_5$$7, 0) || ZEPHIR_IS_LONG(&_5$$7, 1)) {
					ZEPHIR_CALL_METHOD(&_6$$8, &relation, "getreferencedmodel", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedModel, &manager, "load", NULL, 0, &_6$$8);
					zephir_check_call_status();
					if (Z_TYPE_P(&referencedModel) == IS_OBJECT) {
						ZEPHIR_CALL_METHOD(NULL, &referencedModel, "assign", NULL, 0, value);
						zephir_check_call_status();
						zephir_unset_property_array(this_ptr, ZEND_STRL("related"), &lowerProperty);
						zephir_read_property(&_7$$9, this_ptr, ZEND_STRL("related"), PH_NOISY_CC | PH_READONLY);
						zephir_array_unset(&_7$$9, &lowerProperty, PH_SEPARATE);
						zephir_update_property_array(this_ptr, SL("dirtyRelated"), &lowerProperty, &referencedModel);
						ZEPHIR_INIT_ZVAL_NREF(_8$$9);
						ZVAL_LONG(&_8$$9, 1);
						zephir_update_property_zval(this_ptr, ZEND_STRL("dirtyState"), &_8$$9);
						RETVAL_ZVAL(value, 1, 0);
						RETURN_MM();
					}
					break;
				}
				if (ZEPHIR_IS_LONG(&_5$$7, 2) || ZEPHIR_IS_LONG(&_5$$7, 4)) {
					ZEPHIR_INIT_VAR(&related);
					array_init(&related);
					zephir_is_iterable(value, 0, "phalcon/Mvc/Model.zep", 470);
					if (Z_TYPE_P(value) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(value), _9$$10)
						{
							ZEPHIR_INIT_NVAR(&item);
							ZVAL_COPY(&item, _9$$10);
							if (Z_TYPE_P(&item) == IS_OBJECT) {
								if (zephir_instance_of_ev(&item, phalcon_mvc_modelinterface_ce)) {
									zephir_array_append(&related, &item, PH_SEPARATE, "phalcon/Mvc/Model.zep", 465);
								}
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, value, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_10$$10, value, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_10$$10)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&item, value, "current", NULL, 0);
							zephir_check_call_status();
								if (Z_TYPE_P(&item) == IS_OBJECT) {
									if (zephir_instance_of_ev(&item, phalcon_mvc_modelinterface_ce)) {
										zephir_array_append(&related, &item, PH_SEPARATE, "phalcon/Mvc/Model.zep", 465);
									}
								}
							ZEPHIR_CALL_METHOD(NULL, value, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&item);
					zephir_unset_property_array(this_ptr, ZEND_STRL("related"), &lowerProperty);
					zephir_read_property(&_11$$10, this_ptr, ZEND_STRL("related"), PH_NOISY_CC | PH_READONLY);
					zephir_array_unset(&_11$$10, &lowerProperty, PH_SEPARATE);
					if (zephir_fast_count_int(&related) > 0) {
						zephir_update_property_array(this_ptr, SL("dirtyRelated"), &lowerProperty, &related);
						ZEPHIR_INIT_ZVAL_NREF(_12$$17);
						ZVAL_LONG(&_12$$17, 1);
						zephir_update_property_zval(this_ptr, ZEND_STRL("dirtyState"), &_12$$17);
					} else {
						zephir_unset_property_array(this_ptr, ZEND_STRL("dirtyRelated"), &lowerProperty);
						zephir_read_property(&_13$$18, this_ptr, ZEND_STRL("dirtyRelated"), PH_NOISY_CC | PH_READONLY);
						zephir_array_unset(&_13$$18, &lowerProperty, PH_SEPARATE);
					}
					RETVAL_ZVAL(value, 1, 0);
					RETURN_MM();
				}
			} while(0);

		}
	}
	ZEPHIR_CALL_METHOD(&_14, this_ptr, "possiblesetter", NULL, 469, &property, value);
	zephir_check_call_status();
	if (zephir_is_true(&_14)) {
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_15, "property_exists", NULL, 470, this_ptr, &property);
	zephir_check_call_status();
	if (zephir_is_true(&_15)) {
		ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_16$$20, &manager, "isvisiblemodelproperty", NULL, 0, this_ptr, &property);
		zephir_check_call_status();
		if (UNEXPECTED(!zephir_is_true(&_16$$20))) {
			ZEPHIR_INIT_VAR(&_17$$21);
			object_init_ex(&_17$$21, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_VAR(&_18$$21);
			ZEPHIR_CONCAT_SVS(&_18$$21, "Cannot access property '", &property, "' (not public).");
			ZEPHIR_CALL_METHOD(NULL, &_17$$21, "__construct", NULL, 30, &_18$$21);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_17$$21, "phalcon/Mvc/Model.zep", 499);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_update_property_zval_zval(this_ptr, &property, value);
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();
}

/**
 * Setups a behavior in a model
 *
 *```php
 * use Phalcon\Mvc\Model;
 * use Phalcon\Mvc\Model\Behavior\Timestampable;
 *
 * class Robots extends Model
 * {
 *     public function initialize()
 *     {
 *         $this->addBehavior(
 *             new Timestampable(
 *                 [
 *                     "beforeCreate" => [
 *                         "field"  => "created_at",
 *                         "format" => "Y-m-d",
 *                     ],
 *                 ]
 *             )
 *         );
 *
 *         $this->addBehavior(
 *             new Timestampable(
 *                 [
 *                     "beforeUpdate" => [
 *                         "field"  => "updated_at",
 *                         "format" => "Y-m-d",
 *                     ],
 *                 ]
 *             )
 *         );
 *     }
 * }
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model, addBehavior)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *behavior, behavior_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&behavior_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(behavior, phalcon_mvc_model_behaviorinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &behavior);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "addbehavior", NULL, 0, this_ptr, behavior);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Appends a customized message on the validation process
 *
 * ```php
 * use Phalcon\Mvc\Model;
 * use Phalcon\Messages\Message as Message;
 *
 * class Robots extends Model
 * {
 *     public function beforeSave()
 *     {
 *         if ($this->name === "Peter") {
 *             $message = new Message(
 *                 "Sorry, but a robot cannot be named Peter"
 *             );
 *
 *             $this->appendMessage($message);
 *         }
 *     }
 * }
 * ```
 */
PHP_METHOD(Phalcon_Mvc_Model, appendMessage)
{
	zval *message, message_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_messages_messageinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &message);


	zephir_update_property_array_append(this_ptr, SL("errorMessages"), message);
	RETURN_THISW();
}

/**
 * Assigns values to a model from an array
 *
 * ```php
 * $robot->assign(
 *     [
 *         "type" => "mechanical",
 *         "name" => "Astro Boy",
 *         "year" => 1952,
 *     ]
 * );
 *
 * // Assign by db row, column map needed
 * $robot->assign(
 *     $dbRow,
 *     [
 *         "db_type" => "type",
 *         "db_name" => "name",
 *         "db_year" => "year",
 *     ]
 * );
 *
 * // Allow assign only name and year
 * $robot->assign(
 *     $_POST,
 *     [
 *         "name",
 *         "year",
 *     ]
 * );
 *
 * // By default assign method will use setters if exist, you can disable it by using ini_set to directly use properties
 *
 * ini_set("phalcon.orm.disable_assign_setters", true);
 *
 * $robot->assign(
 *     $_POST,
 *     [
 *         "name",
 *         "year",
 *     ]
 * );
 * ```
 *
 * @param array data
 * @param mixed whiteList
 * @param mixed dataColumnMap Array to transform keys of data to another
 *
 * @return ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, assign)
{
	zend_bool _7$$12, _13$$18, _16$$22, _20$$28;
	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_12 = NULL, *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *whiteList = NULL, whiteList_sub, *dataColumnMap = NULL, dataColumnMap_sub, __$null, key, keyMapped, value, attribute, attributeField, metaData, columnMap, disableAssignSetters, _4, *_5, _6, *_0$$3, _1$$3, _8$$13, _10$$16, _11$$16, _14$$18, _17$$23, _18$$26, _19$$26, _21$$28;
	zval data, dataMapped;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&dataMapped);
	ZVAL_UNDEF(&whiteList_sub);
	ZVAL_UNDEF(&dataColumnMap_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&keyMapped);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&disableAssignSetters);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_8$$13);
	ZVAL_UNDEF(&_10$$16);
	ZVAL_UNDEF(&_11$$16);
	ZVAL_UNDEF(&_14$$18);
	ZVAL_UNDEF(&_17$$23);
	ZVAL_UNDEF(&_18$$26);
	ZVAL_UNDEF(&_19$$26);
	ZVAL_UNDEF(&_21$$28);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ARRAY(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(whiteList)
		Z_PARAM_ZVAL_OR_NULL(dataColumnMap)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &data_param, &whiteList, &dataColumnMap);
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	if (!whiteList) {
		whiteList = &whiteList_sub;
		whiteList = &__$null;
	}
	if (!dataColumnMap) {
		dataColumnMap = &dataColumnMap_sub;
		dataColumnMap = &__$null;
	}


	ZEPHIR_INIT_VAR(&disableAssignSetters);
	ZVAL_BOOL(&disableAssignSetters, ZEPHIR_GLOBAL(orm).disable_assign_setters);
	if (Z_TYPE_P(dataColumnMap) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&dataMapped);
		array_init(&dataMapped);
		zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 645);
		if (Z_TYPE_P(&data) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _3$$3);
				} else {
					ZVAL_LONG(&key, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _0$$3);
				ZEPHIR_OBS_NVAR(&keyMapped);
				if (zephir_array_isset_fetch(&keyMapped, dataColumnMap, &key, 0)) {
					zephir_array_update_zval(&dataMapped, &keyMapped, &value, PH_COPY | PH_SEPARATE);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &data, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&keyMapped);
					if (zephir_array_isset_fetch(&keyMapped, dataColumnMap, &key, 0)) {
						zephir_array_update_zval(&dataMapped, &keyMapped, &value, PH_COPY | PH_SEPARATE);
					}
				ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		ZEPHIR_CPY_WRT(&dataMapped, &data);
	}
	if (zephir_fast_count_int(&dataMapped) == 0) {
		RETURN_THIS();
	}
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).column_renaming) {
		ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&columnMap);
		ZVAL_NULL(&columnMap);
	}
	ZEPHIR_CALL_METHOD(&_4, &metaData, "getattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(&_4, 0, "phalcon/Mvc/Model.zep", 702);
	if (Z_TYPE_P(&_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_4), _5)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _5);
			_7$$12 = !(zephir_array_isset(&columnMap, &attribute));
			if (_7$$12) {
				_7$$12 = ZEPHIR_GLOBAL(orm).case_insensitive_column_map;
			}
			if (_7$$12) {
				ZEPHIR_CALL_SELF(&_8$$13, "caseinsensitivecolumnmap", &_9, 471, &columnMap, &attribute);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&attribute, &_8$$13);
			}
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0))) {
					if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
						ZEPHIR_INIT_NVAR(&_10$$16);
						object_init_ex(&_10$$16, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_11$$16);
						ZEPHIR_CONCAT_SVS(&_11$$16, "Column '", &attribute, "' doesn't make part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_10$$16, "__construct", &_12, 30, &_11$$16);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_10$$16, "phalcon/Mvc/Model.zep", 676);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &attribute);
			}
			ZEPHIR_OBS_NVAR(&value);
			if (zephir_array_isset_fetch(&value, &dataMapped, &attributeField, 0)) {
				if (Z_TYPE_P(whiteList) == IS_ARRAY) {
					if (!(zephir_fast_in_array(&attributeField, whiteList))) {
						continue;
					}
				}
				_13$$18 = zephir_is_true(&disableAssignSetters);
				if (!(_13$$18)) {
					ZEPHIR_CALL_METHOD(&_14$$18, this_ptr, "possiblesetter", &_15, 469, &attributeField, &value);
					zephir_check_call_status();
					_13$$18 = !zephir_is_true(&_14$$18);
				}
				if (_13$$18) {
					zephir_update_property_zval_zval(this_ptr, &attributeField, &value);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_4, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_6, &_4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attribute, &_4, "current", NULL, 0);
			zephir_check_call_status();
				_16$$22 = !(zephir_array_isset(&columnMap, &attribute));
				if (_16$$22) {
					_16$$22 = ZEPHIR_GLOBAL(orm).case_insensitive_column_map;
				}
				if (_16$$22) {
					ZEPHIR_CALL_SELF(&_17$$23, "caseinsensitivecolumnmap", &_9, 471, &columnMap, &attribute);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&attribute, &_17$$23);
				}
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0))) {
						if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
							ZEPHIR_INIT_NVAR(&_18$$26);
							object_init_ex(&_18$$26, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_19$$26);
							ZEPHIR_CONCAT_SVS(&_19$$26, "Column '", &attribute, "' doesn't make part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_18$$26, "__construct", &_12, 30, &_19$$26);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_18$$26, "phalcon/Mvc/Model.zep", 676);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &attribute);
				}
				ZEPHIR_OBS_NVAR(&value);
				if (zephir_array_isset_fetch(&value, &dataMapped, &attributeField, 0)) {
					if (Z_TYPE_P(whiteList) == IS_ARRAY) {
						if (!(zephir_fast_in_array(&attributeField, whiteList))) {
							continue;
						}
					}
					_20$$28 = zephir_is_true(&disableAssignSetters);
					if (!(_20$$28)) {
						ZEPHIR_CALL_METHOD(&_21$$28, this_ptr, "possiblesetter", &_15, 469, &attributeField, &value);
						zephir_check_call_status();
						_20$$28 = !zephir_is_true(&_21$$28);
					}
					if (_20$$28) {
						zephir_update_property_zval_zval(this_ptr, &attributeField, &value);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &_4, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&attribute);
	RETURN_THIS();
}

/**
 * Returns the average value on a column for a result-set of rows matching
 * the specified conditions.
 *
 * Returned value will be a float for simple queries or a ResultsetInterface
 * instance for when the GROUP condition is used. The results will
 * contain the average of each group.
 *
 * ```php
 * // What's the average price of robots?
 * $average = Robots::average(
 *     [
 *         "column" => "price",
 *     ]
 * );
 *
 * echo "The average price is ", $average, "\n";
 *
 * // What's the average price of mechanical robots?
 * $average = Robots::average(
 *     [
 *         "type = 'mechanical'",
 *         "column" => "price",
 *     ]
 * );
 *
 * echo "The average price of mechanical robots is ", $average, "\n";
 * ```
 *
 * @param array parameters
 * @return float | ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, average)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, result, _0, _1;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(parameters)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters_param);
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "AVG");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "average");
	ZEPHIR_CALL_SELF(&result, "groupresult", NULL, 0, &_0, &_1, &parameters);
	zephir_check_call_status();
	if (Z_TYPE_P(&result) == IS_STRING) {
		RETURN_MM_DOUBLE(zephir_get_doubleval(&result));
	}
	RETURN_CCTOR(&result);
}

/**
 * Assigns values to a model from an array returning a new model
 *
 *```php
 * $robot = Phalcon\Mvc\Model::cloneResult(
 *     new Robots(),
 *     [
 *         "type" => "mechanical",
 *         "name" => "Astro Boy",
 *         "year" => 1952,
 *     ]
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model, cloneResult)
{
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long dirtyState, ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *base, base_sub, *data_param = NULL, *dirtyState_param = NULL, instance, key, value, _0, *_1, _2, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&base_sub);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&data);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_OBJECT_OF_CLASS(base, phalcon_mvc_modelinterface_ce)
		Z_PARAM_ARRAY(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(dirtyState)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &base, &data_param, &dirtyState_param);
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	if (!dirtyState_param) {
		dirtyState = 0;
	} else {
		dirtyState = zephir_get_intval(dirtyState_param);
	}


	ZEPHIR_INIT_VAR(&instance);
	if (zephir_clone(&instance, base) == FAILURE) {
		RETURN_MM();
	}
	ZVAL_LONG(&_0, dirtyState);
	ZEPHIR_CALL_METHOD(NULL, &instance, "setdirtystate", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 792);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			if (UNEXPECTED(Z_TYPE_P(&key) != IS_STRING)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid key in array data provided to dumpResult()", "phalcon/Mvc/Model.zep", 782);
				return;
			}
			zephir_update_property_zval_zval(&instance, &key, &value);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&key) != IS_STRING)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid key in array data provided to dumpResult()", "phalcon/Mvc/Model.zep", 782);
					return;
				}
				zephir_update_property_zval_zval(&instance, &key, &value);
			ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "afterFetch");
	ZEPHIR_CALL_METHOD(NULL, &instance, "fireevent", NULL, 0, &_5);
	zephir_check_call_status();
	RETURN_CCTOR(&instance);
}

/**
 * Assigns values to a model from an array, returning a new model.
 *
 *```php
 * $robot = \Phalcon\Mvc\Model::cloneResultMap(
 *     new Robots(),
 *     [
 *         "type" => "mechanical",
 *         "name" => "Astro Boy",
 *         "year" => 1952,
 *     ]
 * );
 *```
 *
 * @param ModelInterface|\Phalcon\Mvc\Model\Row base
 * @param mixed columnMap
 * @param int dirtyState
 * @param bool keepSnapshots
 *
 * @return ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, cloneResultMap)
{
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_14 = NULL;
	zend_bool keepSnapshots, _5$$6, _11$$3, _16$$24, _21$$21;
	zend_long dirtyState, ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *base, base_sub, *data_param = NULL, *columnMap, columnMap_sub, *dirtyState_param = NULL, *keepSnapshots_param = NULL, instance, attribute, key, value, castValue, attributeName, metaData, reverseMap, _0, *_1, _2, _6$$9, _7$$9, _9$$11, _10$$11, _12$$13, _13$$14, _15$$18, _17$$27, _18$$27, _19$$29, _20$$29, _22$$31, _23$$32, _24$$36, _25$$40;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&base_sub);
	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&castValue);
	ZVAL_UNDEF(&attributeName);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&reverseMap);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_15$$18);
	ZVAL_UNDEF(&_17$$27);
	ZVAL_UNDEF(&_18$$27);
	ZVAL_UNDEF(&_19$$29);
	ZVAL_UNDEF(&_20$$29);
	ZVAL_UNDEF(&_22$$31);
	ZVAL_UNDEF(&_23$$32);
	ZVAL_UNDEF(&_24$$36);
	ZVAL_UNDEF(&_25$$40);
	ZVAL_UNDEF(&data);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 5)
		Z_PARAM_ZVAL(base)
		Z_PARAM_ARRAY(data)
		Z_PARAM_ZVAL(columnMap)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(dirtyState)
		Z_PARAM_BOOL_OR_NULL(keepSnapshots, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &base, &data_param, &columnMap, &dirtyState_param, &keepSnapshots_param);
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	if (!dirtyState_param) {
		dirtyState = 0;
	} else {
		dirtyState = zephir_get_intval(dirtyState_param);
	}
	if (!keepSnapshots_param) {
		keepSnapshots = 0;
	} else {
		keepSnapshots = zephir_get_boolval(keepSnapshots_param);
	}


	ZEPHIR_INIT_VAR(&instance);
	if (zephir_clone(&instance, base) == FAILURE) {
		RETURN_MM();
	}
	ZVAL_LONG(&_0, dirtyState);
	ZEPHIR_CALL_METHOD(NULL, &instance, "setdirtystate", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_is_iterable(&data, 1, "phalcon/Mvc/Model.zep", 925);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			if (Z_TYPE_P(&key) != IS_STRING) {
				continue;
			}
			if (Z_TYPE_P(columnMap) != IS_ARRAY) {
				zephir_update_property_zval_zval(&instance, &key, &value);
				continue;
			}
			ZEPHIR_OBS_NVAR(&attribute);
			if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0))) {
				_5$$6 = Z_TYPE_P(columnMap) == IS_ARRAY;
				if (_5$$6) {
					_5$$6 = !(ZEPHIR_IS_EMPTY(columnMap));
				}
				if (_5$$6) {
					ZEPHIR_CALL_METHOD(&metaData, &instance, "getmodelsmetadata", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&reverseMap, &metaData, "getreversecolumnmap", NULL, 0, &instance);
					zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&attribute);
					if (!(zephir_array_isset_fetch(&attribute, &reverseMap, &key, 0))) {
						if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
							ZEPHIR_INIT_NVAR(&_6$$9);
							object_init_ex(&_6$$9, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_7$$9);
							ZEPHIR_CONCAT_SVS(&_7$$9, "Column '", &key, "' doesn't make part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_6$$9, "__construct", &_8, 30, &_7$$9);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_6$$9, "phalcon/Mvc/Model.zep", 852);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
				} else {
					if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
						ZEPHIR_INIT_NVAR(&_9$$11);
						object_init_ex(&_9$$11, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_10$$11);
						ZEPHIR_CONCAT_SVS(&_10$$11, "Column '", &key, "' doesn't make part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_9$$11, "__construct", &_8, 30, &_10$$11);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_9$$11, "phalcon/Mvc/Model.zep", 861);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
			}
			if (Z_TYPE_P(&attribute) != IS_ARRAY) {
				zephir_update_property_zval_zval(&instance, &attribute, &value);
				continue;
			}
			_11$$3 = !ZEPHIR_IS_STRING(&value, "");
			if (_11$$3) {
				_11$$3 = Z_TYPE_P(&value) != IS_NULL;
			}
			if (_11$$3) {
				zephir_array_fetch_long(&_12$$13, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 875);
				do {
					if (ZEPHIR_IS_LONG(&_12$$13, 0) || ZEPHIR_IS_LONG(&_12$$13, 21) || ZEPHIR_IS_LONG(&_12$$13, 22) || ZEPHIR_IS_LONG(&_12$$13, 26)) {
						ZVAL_LONG(&_13$$14, 10);
						ZEPHIR_CALL_FUNCTION(&castValue, "intval", &_14, 50, &value, &_13$$14);
						zephir_check_call_status();
						break;
					}
					if (ZEPHIR_IS_LONG(&_12$$13, 3) || ZEPHIR_IS_LONG(&_12$$13, 9) || ZEPHIR_IS_LONG(&_12$$13, 7)) {
						ZEPHIR_INIT_NVAR(&castValue);
						ZVAL_DOUBLE(&castValue, zephir_get_doubleval(&value));
						break;
					}
					if (ZEPHIR_IS_LONG(&_12$$13, 8)) {
						ZEPHIR_INIT_NVAR(&castValue);
						ZVAL_BOOL(&castValue, zephir_get_boolval(&value));
						break;
					}
					ZEPHIR_CPY_WRT(&castValue, &value);
					break;
				} while(0);

			} else {
				zephir_array_fetch_long(&_15$$18, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 898);
				do {
					if (ZEPHIR_IS_LONG(&_15$$18, 14) || ZEPHIR_IS_LONG(&_15$$18, 8) || ZEPHIR_IS_LONG(&_15$$18, 3) || ZEPHIR_IS_LONG(&_15$$18, 9) || ZEPHIR_IS_LONG(&_15$$18, 7) || ZEPHIR_IS_LONG(&_15$$18, 0) || ZEPHIR_IS_LONG(&_15$$18, 21) || ZEPHIR_IS_LONG(&_15$$18, 22) || ZEPHIR_IS_LONG(&_15$$18, 26)) {
						ZEPHIR_INIT_NVAR(&castValue);
						ZVAL_NULL(&castValue);
						break;
					}
					ZEPHIR_CPY_WRT(&castValue, &value);
					break;
				} while(0);

			}
			ZEPHIR_OBS_NVAR(&attributeName);
			zephir_array_fetch_long(&attributeName, &attribute, 0, PH_NOISY, "phalcon/Mvc/Model.zep", 917);
			zephir_update_property_zval_zval(&instance, &attributeName, &castValue);
			zephir_array_update_zval(&data, &key, &castValue, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&key) != IS_STRING) {
					continue;
				}
				if (Z_TYPE_P(columnMap) != IS_ARRAY) {
					zephir_update_property_zval_zval(&instance, &key, &value);
					continue;
				}
				ZEPHIR_OBS_NVAR(&attribute);
				if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0))) {
					_16$$24 = Z_TYPE_P(columnMap) == IS_ARRAY;
					if (_16$$24) {
						_16$$24 = !(ZEPHIR_IS_EMPTY(columnMap));
					}
					if (_16$$24) {
						ZEPHIR_CALL_METHOD(&metaData, &instance, "getmodelsmetadata", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&reverseMap, &metaData, "getreversecolumnmap", NULL, 0, &instance);
						zephir_check_call_status();
						ZEPHIR_OBS_NVAR(&attribute);
						if (!(zephir_array_isset_fetch(&attribute, &reverseMap, &key, 0))) {
							if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
								ZEPHIR_INIT_NVAR(&_17$$27);
								object_init_ex(&_17$$27, phalcon_mvc_model_exception_ce);
								ZEPHIR_INIT_NVAR(&_18$$27);
								ZEPHIR_CONCAT_SVS(&_18$$27, "Column '", &key, "' doesn't make part of the column map");
								ZEPHIR_CALL_METHOD(NULL, &_17$$27, "__construct", &_8, 30, &_18$$27);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_17$$27, "phalcon/Mvc/Model.zep", 852);
								ZEPHIR_MM_RESTORE();
								return;
							}
							continue;
						}
					} else {
						if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
							ZEPHIR_INIT_NVAR(&_19$$29);
							object_init_ex(&_19$$29, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_20$$29);
							ZEPHIR_CONCAT_SVS(&_20$$29, "Column '", &key, "' doesn't make part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_19$$29, "__construct", &_8, 30, &_20$$29);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_19$$29, "phalcon/Mvc/Model.zep", 861);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
				}
				if (Z_TYPE_P(&attribute) != IS_ARRAY) {
					zephir_update_property_zval_zval(&instance, &attribute, &value);
					continue;
				}
				_21$$21 = !ZEPHIR_IS_STRING(&value, "");
				if (_21$$21) {
					_21$$21 = Z_TYPE_P(&value) != IS_NULL;
				}
				if (_21$$21) {
					zephir_array_fetch_long(&_22$$31, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 875);
					do {
						if (ZEPHIR_IS_LONG(&_22$$31, 0) || ZEPHIR_IS_LONG(&_22$$31, 21) || ZEPHIR_IS_LONG(&_22$$31, 22) || ZEPHIR_IS_LONG(&_22$$31, 26)) {
							ZVAL_LONG(&_23$$32, 10);
							ZEPHIR_CALL_FUNCTION(&castValue, "intval", &_14, 50, &value, &_23$$32);
							zephir_check_call_status();
							break;
						}
						if (ZEPHIR_IS_LONG(&_22$$31, 3) || ZEPHIR_IS_LONG(&_22$$31, 9) || ZEPHIR_IS_LONG(&_22$$31, 7)) {
							ZEPHIR_INIT_NVAR(&castValue);
							ZVAL_DOUBLE(&castValue, zephir_get_doubleval(&value));
							break;
						}
						if (ZEPHIR_IS_LONG(&_22$$31, 8)) {
							ZEPHIR_INIT_NVAR(&castValue);
							ZVAL_BOOL(&castValue, zephir_get_boolval(&value));
							break;
						}
						ZEPHIR_CPY_WRT(&castValue, &value);
						break;
					} while(0);

				} else {
					zephir_array_fetch_long(&_24$$36, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 898);
					do {
						if (ZEPHIR_IS_LONG(&_24$$36, 14) || ZEPHIR_IS_LONG(&_24$$36, 8) || ZEPHIR_IS_LONG(&_24$$36, 3) || ZEPHIR_IS_LONG(&_24$$36, 9) || ZEPHIR_IS_LONG(&_24$$36, 7) || ZEPHIR_IS_LONG(&_24$$36, 0) || ZEPHIR_IS_LONG(&_24$$36, 21) || ZEPHIR_IS_LONG(&_24$$36, 22) || ZEPHIR_IS_LONG(&_24$$36, 26)) {
							ZEPHIR_INIT_NVAR(&castValue);
							ZVAL_NULL(&castValue);
							break;
						}
						ZEPHIR_CPY_WRT(&castValue, &value);
						break;
					} while(0);

				}
				ZEPHIR_OBS_NVAR(&attributeName);
				zephir_array_fetch_long(&attributeName, &attribute, 0, PH_NOISY, "phalcon/Mvc/Model.zep", 917);
				zephir_update_property_zval_zval(&instance, &attributeName, &castValue);
				zephir_array_update_zval(&data, &key, &castValue, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	if (keepSnapshots) {
		ZEPHIR_CALL_METHOD(NULL, &instance, "setsnapshotdata", NULL, 0, &data, columnMap);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &instance, "setoldsnapshotdata", NULL, 0, &data, columnMap);
		zephir_check_call_status();
	}
	if ((zephir_method_exists_ex(&instance, ZEND_STRL("fireevent")) == SUCCESS)) {
		ZEPHIR_INIT_VAR(&_25$$40);
		ZVAL_STRING(&_25$$40, "afterFetch");
		ZEPHIR_CALL_METHOD(NULL, &instance, "fireevent", NULL, 0, &_25$$40);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&instance);
}

/**
 * Returns an hydrated result based on the data and the column map
 *
 * @param array data
 * @param mixed columnMap
 * @param int hydrationMode
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, cloneResultMapHydrate)
{
	zend_bool _4$$7, _10$$16;
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL;
	zend_long hydrationMode, ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *columnMap, columnMap_sub, *hydrationMode_param = NULL, key, value, attribute, attributeName, *_0, _1, _5$$8, _7$$10, _8$$10, _11$$17, _12$$19, _13$$19;
	zval data, hydrateArray;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&hydrateArray);
	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&attributeName);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_11$$17);
	ZVAL_UNDEF(&_12$$19);
	ZVAL_UNDEF(&_13$$19);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ARRAY(data)
		Z_PARAM_ZVAL(columnMap)
		Z_PARAM_LONG(hydrationMode)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &data_param, &columnMap, &hydrationMode_param);
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	hydrationMode = zephir_get_intval(hydrationMode_param);


	if (Z_TYPE_P(columnMap) != IS_ARRAY) {
		if (hydrationMode == 1) {
			RETURN_CTOR(&data);
		}
	}
	ZEPHIR_INIT_VAR(&hydrateArray);
	array_init(&hydrateArray);
	zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 1009);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			if (Z_TYPE_P(&key) != IS_STRING) {
				continue;
			}
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				_4$$7 = !(zephir_array_isset(columnMap, &key));
				if (_4$$7) {
					_4$$7 = ZEPHIR_GLOBAL(orm).case_insensitive_column_map;
				}
				if (_4$$7) {
					ZEPHIR_CALL_SELF(&_5$$8, "caseinsensitivecolumnmap", &_6, 471, columnMap, &key);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&key, &_5$$8);
				}
				ZEPHIR_OBS_NVAR(&attribute);
				if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0))) {
					if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
						ZEPHIR_INIT_NVAR(&_7$$10);
						object_init_ex(&_7$$10, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_8$$10);
						ZEPHIR_CONCAT_SVS(&_8$$10, "Column '", &key, "' doesn't make part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_7$$10, "__construct", &_9, 30, &_8$$10);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_7$$10, "phalcon/Mvc/Model.zep", 988);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
				if (Z_TYPE_P(&attribute) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeName);
					zephir_array_fetch_long(&attributeName, &attribute, 0, PH_NOISY, "phalcon/Mvc/Model.zep", 998);
				} else {
					ZEPHIR_CPY_WRT(&attributeName, &attribute);
				}
				zephir_array_update_zval(&hydrateArray, &attributeName, &value, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&hydrateArray, &key, &value, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&key) != IS_STRING) {
					continue;
				}
				if (Z_TYPE_P(columnMap) == IS_ARRAY) {
					_10$$16 = !(zephir_array_isset(columnMap, &key));
					if (_10$$16) {
						_10$$16 = ZEPHIR_GLOBAL(orm).case_insensitive_column_map;
					}
					if (_10$$16) {
						ZEPHIR_CALL_SELF(&_11$$17, "caseinsensitivecolumnmap", &_6, 471, columnMap, &key);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&key, &_11$$17);
					}
					ZEPHIR_OBS_NVAR(&attribute);
					if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0))) {
						if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
							ZEPHIR_INIT_NVAR(&_12$$19);
							object_init_ex(&_12$$19, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_13$$19);
							ZEPHIR_CONCAT_SVS(&_13$$19, "Column '", &key, "' doesn't make part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_12$$19, "__construct", &_9, 30, &_13$$19);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_12$$19, "phalcon/Mvc/Model.zep", 988);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
					if (Z_TYPE_P(&attribute) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeName);
						zephir_array_fetch_long(&attributeName, &attribute, 0, PH_NOISY, "phalcon/Mvc/Model.zep", 998);
					} else {
						ZEPHIR_CPY_WRT(&attributeName, &attribute);
					}
					zephir_array_update_zval(&hydrateArray, &attributeName, &value, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&hydrateArray, &key, &value, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	if (hydrationMode != 1) {
		zephir_convert_to_object(&hydrateArray);
		RETURN_CTOR(&hydrateArray);
	}
	RETURN_CTOR(&hydrateArray);
}

/**
 * Collects previously queried (belongs-to, has-one and has-one-through)
 * related records along with freshly added one
 *
 * @return array Related records that should be saved
 */
PHP_METHOD(Phalcon_Mvc_Model, collectRelatedToSave)
{
	zend_bool _6$$3, _7$$6;
	zend_string *_5;
	zend_ulong _4;
	zval related, dirtyRelated;
	zval name, record, _0, _1, *_2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&related);
	ZVAL_UNDEF(&dirtyRelated);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("related"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&related, &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("dirtyRelated"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dirtyRelated, &_1);
	zephir_is_iterable(&related, 0, "phalcon/Mvc/Model.zep", 1049);
	if (Z_TYPE_P(&related) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&related), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&name, _5);
			} else {
				ZVAL_LONG(&name, _4);
			}
			ZEPHIR_INIT_NVAR(&record);
			ZVAL_COPY(&record, _2);
			if (zephir_array_isset(&dirtyRelated, &name)) {
				continue;
			}
			_6$$3 = Z_TYPE_P(&record) != IS_OBJECT;
			if (!(_6$$3)) {
				_6$$3 = !((zephir_instance_of_ev(&record, phalcon_mvc_modelinterface_ce)));
			}
			if (_6$$3) {
				continue;
			}
			zephir_array_update_zval(&dirtyRelated, &name, &record, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &related, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &related, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &related, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&record, &related, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_array_isset(&dirtyRelated, &name)) {
					continue;
				}
				_7$$6 = Z_TYPE_P(&record) != IS_OBJECT;
				if (!(_7$$6)) {
					_7$$6 = !((zephir_instance_of_ev(&record, phalcon_mvc_modelinterface_ce)));
				}
				if (_7$$6) {
					continue;
				}
				zephir_array_update_zval(&dirtyRelated, &name, &record, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &related, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&record);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CTOR(&dirtyRelated);
}

/**
 * Counts how many records match the specified conditions.
 *
 * Returns an integer for simple queries or a ResultsetInterface
 * instance for when the GROUP condition is used. The results will
 * contain the count of each group.
 *
 * ```php
 * // How many robots are there?
 * $number = Robots::count();
 *
 * echo "There are ", $number, "\n";
 *
 * // How many mechanical robots are there?
 * $number = Robots::count("type = 'mechanical'");
 *
 * echo "There are ", $number, " mechanical robots\n";
 * ```
 *
 * @param array|string|null parameters
 */
PHP_METHOD(Phalcon_Mvc_Model, count)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, parameters_sub, __$null, result, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(parameters)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "COUNT");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "rowcount");
	ZEPHIR_CALL_SELF(&result, "groupresult", NULL, 0, &_0, &_1, parameters);
	zephir_check_call_status();
	if (Z_TYPE_P(&result) == IS_STRING) {
		RETURN_MM_LONG(zephir_get_intval(&result));
	}
	RETURN_CCTOR(&result);
}

/**
 * Inserts a model instance. If the instance already exists in the
 * persistence it will throw an exception
 * Returning true on success or false otherwise.
 *
 *```php
 * // Creating a new robot
 * $robot = new Robots();
 *
 * $robot->type = "mechanical";
 * $robot->name = "Astro Boy";
 * $robot->year = 1952;
 *
 * $robot->create();
 *
 * // Passing an array to create
 * $robot = new Robots();
 *
 * $robot->assign(
 *     [
 *         "type" => "mechanical",
 *         "name" => "Astro Boy",
 *         "year" => 1952,
 *     ]
 * );
 *
 * $robot->create();
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model, create)
{
	zval _2$$3;
	zval metaData, _0, _1, _3$$3, _4$$3, _5$$3, _6$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_2$$3);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getwriteconnection", NULL, 472);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &metaData, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_create_array(&_2$$3, 1, 0);
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, phalcon_messages_message_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "Record cannot be created because it already exists");
		ZVAL_NULL(&_5$$3);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "InvalidCreateAttempt");
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 6, &_4$$3, &_5$$3, &_6$$3);
		zephir_check_call_status();
		zephir_array_fast_append(&_2$$3, &_3$$3);
		zephir_update_property_zval(this_ptr, ZEND_STRL("errorMessages"), &_2$$3);
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "save", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Deletes a model instance. Returning true on success or false otherwise.
 *
 * ```php
 * $robot = Robots::findFirst("id=100");
 *
 * $robot->delete();
 *
 * $robots = Robots::find("type = 'mechanical'");
 *
 * foreach ($robots as $robot) {
 *     $robot->delete();
 * }
 * ```
 */
PHP_METHOD(Phalcon_Mvc_Model, delete)
{
	zval values, bindTypes, conditions;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, metaData, writeConnection, primaryKeys, bindDataTypes, columnMap, attributeField, primaryKey, bindType, value, schema, source, table, success, _0, _1, *_3, _4, _27, _2$$3, _5$$9, _6$$9, _8$$11, _9$$11, _10$$13, _11$$13, _12$$8, _14$$8, _15$$15, _16$$15, _17$$17, _18$$17, _19$$19, _20$$19, _21$$14, _23$$14, _24$$20, _25$$20, _26$$20, _28$$25, _29$$28;
	zephir_fcall_cache_entry *_7 = NULL, *_13 = NULL, *_22 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&writeConnection);
	ZVAL_UNDEF(&primaryKeys);
	ZVAL_UNDEF(&bindDataTypes);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&primaryKey);
	ZVAL_UNDEF(&bindType);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$13);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$15);
	ZVAL_UNDEF(&_16$$15);
	ZVAL_UNDEF(&_17$$17);
	ZVAL_UNDEF(&_18$$17);
	ZVAL_UNDEF(&_19$$19);
	ZVAL_UNDEF(&_20$$19);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_24$$20);
	ZVAL_UNDEF(&_25$$20);
	ZVAL_UNDEF(&_26$$20);
	ZVAL_UNDEF(&_28$$25);
	ZVAL_UNDEF(&_29$$28);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&conditions);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&writeConnection, this_ptr, "getwriteconnection", NULL, 472);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 3);
	zephir_update_property_zval(this_ptr, ZEND_STRL("operationMade"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, ZEND_STRL("errorMessages"), &_1);
	if (ZEPHIR_GLOBAL(orm).virtual_foreign_keys) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "checkforeignkeysreverserestrict", NULL, 473);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_2$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	ZEPHIR_INIT_VAR(&bindTypes);
	array_init(&bindTypes);
	ZEPHIR_INIT_VAR(&conditions);
	array_init(&conditions);
	ZEPHIR_CALL_METHOD(&primaryKeys, &metaData, "getprimarykeyattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&bindDataTypes, &metaData, "getbindtypes", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).column_renaming) {
		ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&columnMap);
		ZVAL_NULL(&columnMap);
	}
	if (UNEXPECTED(!(zephir_fast_count_int(&primaryKeys)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A primary key must be defined in the model in order to perform the operation", "phalcon/Mvc/Model.zep", 1202);
		return;
	}
	zephir_is_iterable(&primaryKeys, 0, "phalcon/Mvc/Model.zep", 1250);
	if (Z_TYPE_P(&primaryKeys) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&primaryKeys), _3)
		{
			ZEPHIR_INIT_NVAR(&primaryKey);
			ZVAL_COPY(&primaryKey, _3);
			ZEPHIR_OBS_NVAR(&bindType);
			if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &primaryKey, 0)))) {
				ZEPHIR_INIT_NVAR(&_5$$9);
				object_init_ex(&_5$$9, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_NVAR(&_6$$9);
				ZEPHIR_CONCAT_SVS(&_6$$9, "Column '", &primaryKey, "' have not defined a bind data type");
				ZEPHIR_CALL_METHOD(NULL, &_5$$9, "__construct", &_7, 30, &_6$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_5$$9, "phalcon/Mvc/Model.zep", 1216);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &primaryKey, 0)))) {
					ZEPHIR_INIT_NVAR(&_8$$11);
					object_init_ex(&_8$$11, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_NVAR(&_9$$11);
					ZEPHIR_CONCAT_SVS(&_9$$11, "Column '", &primaryKey, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, &_8$$11, "__construct", &_7, 30, &_9$$11);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_8$$11, "phalcon/Mvc/Model.zep", 1226);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &primaryKey);
			}
			ZEPHIR_OBS_NVAR(&value);
			if (UNEXPECTED(!(zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)))) {
				ZEPHIR_INIT_NVAR(&_10$$13);
				object_init_ex(&_10$$13, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_NVAR(&_11$$13);
				ZEPHIR_CONCAT_SVS(&_11$$13, "Cannot delete the record because the primary key attribute: '", &attributeField, "' wasn't set");
				ZEPHIR_CALL_METHOD(NULL, &_10$$13, "__construct", &_7, 30, &_11$$13);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_10$$13, "phalcon/Mvc/Model.zep", 1239);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1245);
			ZEPHIR_CALL_METHOD(&_12$$8, &writeConnection, "escapeidentifier", &_13, 0, &primaryKey);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_14$$8);
			ZEPHIR_CONCAT_VS(&_14$$8, &_12$$8, " = ?");
			zephir_array_append(&conditions, &_14$$8, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1246);
			zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1247);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &primaryKeys, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, &primaryKeys, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&primaryKey, &primaryKeys, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&bindType);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &primaryKey, 0)))) {
					ZEPHIR_INIT_NVAR(&_15$$15);
					object_init_ex(&_15$$15, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_NVAR(&_16$$15);
					ZEPHIR_CONCAT_SVS(&_16$$15, "Column '", &primaryKey, "' have not defined a bind data type");
					ZEPHIR_CALL_METHOD(NULL, &_15$$15, "__construct", &_7, 30, &_16$$15);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_15$$15, "phalcon/Mvc/Model.zep", 1216);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &primaryKey, 0)))) {
						ZEPHIR_INIT_NVAR(&_17$$17);
						object_init_ex(&_17$$17, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_18$$17);
						ZEPHIR_CONCAT_SVS(&_18$$17, "Column '", &primaryKey, "' isn't part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_17$$17, "__construct", &_7, 30, &_18$$17);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_17$$17, "phalcon/Mvc/Model.zep", 1226);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &primaryKey);
				}
				ZEPHIR_OBS_NVAR(&value);
				if (UNEXPECTED(!(zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)))) {
					ZEPHIR_INIT_NVAR(&_19$$19);
					object_init_ex(&_19$$19, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_NVAR(&_20$$19);
					ZEPHIR_CONCAT_SVS(&_20$$19, "Cannot delete the record because the primary key attribute: '", &attributeField, "' wasn't set");
					ZEPHIR_CALL_METHOD(NULL, &_19$$19, "__construct", &_7, 30, &_20$$19);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_19$$19, "phalcon/Mvc/Model.zep", 1239);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1245);
				ZEPHIR_CALL_METHOD(&_21$$14, &writeConnection, "escapeidentifier", &_22, 0, &primaryKey);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_23$$14);
				ZEPHIR_CONCAT_VS(&_23$$14, &_21$$14, " = ?");
				zephir_array_append(&conditions, &_23$$14, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1246);
				zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1247);
			ZEPHIR_CALL_METHOD(NULL, &primaryKeys, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&primaryKey);
	if (ZEPHIR_GLOBAL(orm).events) {
		if (0) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("skipped"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("skipped"), &__$false);
		}
		ZEPHIR_INIT_VAR(&_25$$20);
		ZVAL_STRING(&_25$$20, "beforeDelete");
		ZEPHIR_CALL_METHOD(&_24$$20, this_ptr, "fireeventcancel", NULL, 0, &_25$$20);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_24$$20)) {
			RETURN_MM_BOOL(0);
		}
		zephir_read_property(&_26$$20, this_ptr, ZEND_STRL("skipped"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_26$$20)) {
			RETURN_MM_BOOL(1);
		}
	}
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 474);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 475);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	ZEPHIR_INIT_VAR(&_27);
	zephir_fast_join_str(&_27, SL(" AND "), &conditions);
	ZEPHIR_CALL_METHOD(&success, &writeConnection, "delete", NULL, 0, &table, &_27, &values, &bindTypes);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).virtual_foreign_keys) {
		ZEPHIR_CALL_METHOD(&_28$$25, this_ptr, "checkforeignkeysreversecascade", NULL, 476);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_28$$25)) {
			RETURN_MM_BOOL(0);
		}
	}
	if (ZEPHIR_GLOBAL(orm).events) {
		if (zephir_is_true(&success)) {
			ZEPHIR_INIT_VAR(&_29$$28);
			ZVAL_STRING(&_29$$28, "afterDelete");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_29$$28);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 2);
	zephir_update_property_zval(this_ptr, ZEND_STRL("dirtyState"), &_0);
	RETURN_CCTOR(&success);
}

/**
 * Returns a simple representation of the object that can be used with
 * `var_dump()`
 *
 *```php
 * var_dump(
 *     $robot->dump()
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model, dump)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("get_object_vars", NULL, 477, this_ptr);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Query for a set of records that match the specified conditions
 *
 * ```php
 * // How many robots are there?
 * $robots = Robots::find();
 *
 * echo "There are ", count($robots), "\n";
 *
 * // How many mechanical robots are there?
 * $robots = Robots::find(
 *     "type = 'mechanical'"
 * );
 *
 * echo "There are ", count($robots), "\n";
 *
 * // Get and print virtual robots ordered by name
 * $robots = Robots::find(
 *     [
 *         "type = 'virtual'",
 *         "order" => "name",
 *     ]
 * );
 *
 * foreach ($robots as $robot) {
 *     echo $robot->name, "\n";
 * }
 *
 * // Get first 100 virtual robots ordered by name
 * $robots = Robots::find(
 *     [
 *         "type = 'virtual'",
 *         "order" => "name",
 *         "limit" => 100,
 *     ]
 * );
 *
 * foreach ($robots as $robot) {
 *     echo $robot->name, "\n";
 * }
 *
 * // encapsulate find it into an running transaction esp. useful for application unit-tests
 * // or complex business logic where we wanna control which transactions are used.
 *
 * $myTransaction = new Transaction(\Phalcon\Di::getDefault());
 * $myTransaction->begin();
 *
 * $newRobot = new Robot();
 * $newRobot->setTransaction($myTransaction);
 *
 * $newRobot->assign(
 *     [
 *         'name' => 'test',
 *         'type' => 'mechanical',
 *         'year' => 1944,
 *     ]
 * );
 *
 * $newRobot->save();
 *
 * $resultInsideTransaction = Robot::find(
 *     [
 *         'name' => 'test',
 *         Model::TRANSACTION_INDEX => $myTransaction,
 *     ]
 * );
 *
 * $resultOutsideTransaction = Robot::find(['name' => 'test']);
 *
 * foreach ($setInsideTransaction as $robot) {
 *     echo $robot->name, "\n";
 * }
 *
 * foreach ($setOutsideTransaction as $robot) {
 *     echo $robot->name, "\n";
 * }
 *
 * // reverts all not commited changes
 * $myTransaction->rollback();
 *
 * // creating two different transactions
 * $myTransaction1 = new Transaction(\Phalcon\Di::getDefault());
 * $myTransaction1->begin();
 * $myTransaction2 = new Transaction(\Phalcon\Di::getDefault());
 * $myTransaction2->begin();
 *
 *  // add a new robots
 * $firstNewRobot = new Robot();
 * $firstNewRobot->setTransaction($myTransaction1);
 * $firstNewRobot->assign(
 *     [
 *         'name' => 'first-transaction-robot',
 *         'type' => 'mechanical',
 *         'year' => 1944,
 *     ]
 * );
 * $firstNewRobot->save();
 *
 * $secondNewRobot = new Robot();
 * $secondNewRobot->setTransaction($myTransaction2);
 * $secondNewRobot->assign(
 *     [
 *         'name' => 'second-transaction-robot',
 *         'type' => 'fictional',
 *         'year' => 1984,
 *     ]
 * );
 * $secondNewRobot->save();
 *
 * // this transaction will find the robot.
 * $resultInFirstTransaction = Robot::find(
 *     [
 *         'name'                   => 'first-transaction-robot',
 *         Model::TRANSACTION_INDEX => $myTransaction1,
 *     ]
 * );
 *
 * // this transaction won't find the robot.
 * $resultInSecondTransaction = Robot::find(
 *     [
 *         'name'                   => 'first-transaction-robot',
 *         Model::TRANSACTION_INDEX => $myTransaction2,
 *     ]
 * );
 *
 * // this transaction won't find the robot.
 * $resultOutsideAnyExplicitTransaction = Robot::find(
 *     [
 *         'name' => 'first-transaction-robot',
 *     ]
 * );
 *
 * // this transaction won't find the robot.
 * $resultInFirstTransaction = Robot::find(
 *     [
 *         'name'                   => 'second-transaction-robot',
 *         Model::TRANSACTION_INDEX => $myTransaction2,
 *     ]
 * );
 *
 * // this transaction will find the robot.
 * $resultInSecondTransaction = Robot::find(
 *     [
 *         'name'                   => 'second-transaction-robot',
 *         Model::TRANSACTION_INDEX => $myTransaction1,
 *     ]
 * );
 *
 * // this transaction won't find the robot.
 * $resultOutsideAnyExplicitTransaction = Robot::find(
 *     [
 *         'name' => 'second-transaction-robot',
 *     ]
 * );
 *
 * $transaction1->rollback();
 * $transaction2->rollback();
 * ```
 *
 * @param array|string|int|null parameters = [
 *     'conditions' => ''
 *     'columns' => '',
 *     'bind' => [],
 *     'bindTypes => [],
 *     'order' => '',
 *     'limit' => 10,
 *     'offset' => 5,
 *     'group' => 'name, status',
 *     'for_updated' => false,
 *     'shared_lock' => false,
 *     'cache' => [
 *         'lifetime' => 3600,
 *         'key' => 'my-find-key'
 *     ],
 *     'hydration' => null
 * ]
 */
PHP_METHOD(Phalcon_Mvc_Model, find)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters = NULL, parameters_sub, __$null, params, query, resultset, hydration;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&resultset);
	ZVAL_UNDEF(&hydration);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(parameters)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
		if (Z_TYPE_P(parameters) != IS_NULL) {
			zephir_array_append(&params, parameters, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1511);
		}
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	ZEPHIR_CALL_STATIC(&query, "getpreparedquery", &_0, 478, &params);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&resultset, &query, "execute", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&resultset) == IS_OBJECT) {
		ZEPHIR_OBS_VAR(&hydration);
		if (zephir_array_isset_string_fetch(&hydration, &params, SL("hydration"), 0)) {
			ZEPHIR_CALL_METHOD(NULL, &resultset, "sethydratemode", NULL, 0, &hydration);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(&resultset);
}

/**
 * Query the first record that matches the specified conditions
 *
 * ```php
 * // What's the first robot in robots table?
 * $robot = Robots::findFirst();
 *
 * echo "The robot name is ", $robot->name;
 *
 * // What's the first mechanical robot in robots table?
 * $robot = Robots::findFirst(
 *     "type = 'mechanical'"
 * );
 *
 * echo "The first mechanical robot name is ", $robot->name;
 *
 * // Get first virtual robot ordered by name
 * $robot = Robots::findFirst(
 *     [
 *         "type = 'virtual'",
 *         "order" => "name",
 *     ]
 * );
 *
 * echo "The first virtual robot name is ", $robot->name;
 *
 * // behaviour with transaction
 * $myTransaction = new Transaction(\Phalcon\Di::getDefault());
 * $myTransaction->begin();
 *
 * $newRobot = new Robot();
 * $newRobot->setTransaction($myTransaction);
 * $newRobot->assign(
 *     [
 *         'name' => 'test',
 *         'type' => 'mechanical',
 *         'year' => 1944,
 *     ]
 * );
 * $newRobot->save();
 *
 * $findsARobot = Robot::findFirst(
 *     [
 *         'name'                   => 'test',
 *         Model::TRANSACTION_INDEX => $myTransaction,
 *     ]
 * );
 *
 * $doesNotFindARobot = Robot::findFirst(
 *     [
 *         'name' => 'test',
 *     ]
 * );
 *
 * var_dump($findARobot);
 * var_dump($doesNotFindARobot);
 *
 * $transaction->commit();
 *
 * $doesFindTheRobotNow = Robot::findFirst(
 *     [
 *         'name' => 'test',
 *     ]
 * );
 * ```
 *
 * @param array|string|int|null parameters = [
 *     'conditions' => ''
 *     'columns' => '',
 *     'bind' => [],
 *     'bindTypes => [],
 *     'order' => '',
 *     'limit' => 10,
 *     'offset' => 5,
 *     'group' => 'name, status',
 *     'for_updated' => false,
 *     'shared_lock' => false,
 *     'cache' => [
 *         'lifetime' => 3600,
 *         'key' => 'my-find-key'
 *     ],
 *     'hydration' => null
 * ]
 */
PHP_METHOD(Phalcon_Mvc_Model, findFirst)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *parameters = NULL, parameters_sub, __$null, params, query, _3, _1$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(parameters)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	_0 = Z_TYPE_P(parameters) == IS_STRING;
	if (!(_0)) {
		_0 = zephir_is_numeric(parameters);
	}
	if (Z_TYPE_P(parameters) == IS_NULL) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else if (Z_TYPE_P(parameters) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&params, parameters);
	} else if (_0) {
		ZEPHIR_INIT_VAR(&_1$$5);
		zephir_create_array(&_1$$5, 1, 0);
		zephir_array_fast_append(&_1$$5, parameters);
		ZEPHIR_CPY_WRT(&params, &_1$$5);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Parameters passed must be of type array, string, numeric or null", "phalcon/Mvc/Model.zep", 1633);
		return;
	}
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_STATIC(&query, "getpreparedquery", &_2, 478, &params, &_3);
	zephir_check_call_status();
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_METHOD(NULL, &query, "setuniquerow", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&query, "execute", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Fires an event, implicitly calls behaviors and listeners in the events
 * manager are notified
 */
PHP_METHOD(Phalcon_Mvc_Model, fireEvent)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventName_param = NULL, _0;
	zval eventName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(eventName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventName_param);
	if (UNEXPECTED(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(eventName_param) == IS_STRING)) {
		zephir_get_strval(&eventName, eventName_param);
	} else {
		ZEPHIR_INIT_VAR(&eventName);
	}


	if ((zephir_method_exists(this_ptr, &eventName)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &eventName, NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "notifyevent", NULL, 0, &eventName, this_ptr);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Fires an event, implicitly calls behaviors and listeners in the events
 * manager are notified
 * This method stops if one of the callbacks/listeners returns bool false
 */
PHP_METHOD(Phalcon_Mvc_Model, fireEventCancel)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventName_param = NULL, _0$$3, _1;
	zval eventName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(eventName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventName_param);
	if (UNEXPECTED(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(eventName_param) == IS_STRING)) {
		zephir_get_strval(&eventName, eventName_param);
	} else {
		ZEPHIR_INIT_VAR(&eventName);
	}


	if ((zephir_method_exists(this_ptr, &eventName)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD_ZVAL(&_0$$3, this_ptr, &eventName, NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_0$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_1, "notifyevent", NULL, 0, &eventName, this_ptr);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns a list of changed values.
 *
 * ```php
 * $robots = Robots::findFirst();
 * print_r($robots->getChangedFields()); // []
 *
 * $robots->deleted = 'Y';
 *
 * $robots->getChangedFields();
 * print_r($robots->getChangedFields()); // ["deleted"]
 * ```
 */
PHP_METHOD(Phalcon_Mvc_Model, getChangedFields)
{
	zend_string *_5;
	zend_ulong _4;
	zval changed;
	zval metaData, name, snapshot, columnMap, allAttributes, value, _0, _1, *_2, _3, _6$$6, _7$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&allAttributes);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&changed);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("snapshot"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&snapshot, &_0);
	if (UNEXPECTED(Z_TYPE_P(&snapshot) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The 'keepSnapshots' option must be enabled to track changes", "phalcon/Mvc/Model.zep", 1719);
		return;
	}
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getreversecolumnmap", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (Z_TYPE_P(&columnMap) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&allAttributes, &metaData, "getdatatypes", NULL, 0, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&allAttributes, &columnMap);
	}
	ZEPHIR_INIT_VAR(&changed);
	array_init(&changed);
	ZEPHIR_INIT_VAR(&_1);
	zephir_is_iterable(&allAttributes, 0, "phalcon/Mvc/Model.zep", 1777);
	if (Z_TYPE_P(&allAttributes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&allAttributes), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&name, _5);
			} else {
				ZVAL_LONG(&name, _4);
			}
			ZEPHIR_INIT_NVAR(&_1);
			ZVAL_COPY(&_1, _2);
			if (!(zephir_array_isset(&snapshot, &name))) {
				zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1752);
				continue;
			}
			ZEPHIR_OBS_NVAR(&value);
			if (!(zephir_fetch_property_zval(&value, this_ptr, &name, PH_SILENT_CC))) {
				zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1762);
				continue;
			}
			zephir_array_fetch(&_6$$6, &snapshot, &name, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 1770);
			if (!ZEPHIR_IS_IDENTICAL(&value, &_6$$6)) {
				zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1771);
				continue;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &allAttributes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &allAttributes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &allAttributes, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_1, &allAttributes, "current", NULL, 0);
			zephir_check_call_status();
				if (!(zephir_array_isset(&snapshot, &name))) {
					zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1752);
					continue;
				}
				ZEPHIR_OBS_NVAR(&value);
				if (!(zephir_fetch_property_zval(&value, this_ptr, &name, PH_SILENT_CC))) {
					zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1762);
					continue;
				}
				zephir_array_fetch(&_7$$10, &snapshot, &name, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 1770);
				if (!ZEPHIR_IS_IDENTICAL(&value, &_7$$10)) {
					zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1771);
					continue;
				}
			ZEPHIR_CALL_METHOD(NULL, &allAttributes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CTOR(&changed);
}

/**
 * Returns one of the DIRTY_STATE_* constants telling if the record exists
 * in the database or not
 */
PHP_METHOD(Phalcon_Mvc_Model, getDirtyState)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "dirtyState");
}

/**
 * Returns the custom events manager or null if there is no custom events manager
 */
PHP_METHOD(Phalcon_Mvc_Model, getEventsManager)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getcustomeventsmanager", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns array of validation messages
 *
 *```php
 * $robot = new Robots();
 *
 * $robot->type = "mechanical";
 * $robot->name = "Astro Boy";
 * $robot->year = 1952;
 *
 * if ($robot->save() === false) {
 *     echo "Umh, We can't store robots right now ";
 *
 *     $messages = $robot->getMessages();
 *
 *     foreach ($messages as $message) {
 *         echo $message;
 *     }
 * } else {
 *     echo "Great, a new robot was saved successfully!";
 * }
 * ```
 */
PHP_METHOD(Phalcon_Mvc_Model, getMessages)
{
	zend_bool _0;
	zval filtered;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filter = NULL, filter_sub, __$null, message, _1$$3, *_2$$3, _3$$3, _4$$4, _5$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&filtered);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(filter)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &filter);
	if (!filter) {
		filter = &filter_sub;
		filter = &__$null;
	}


	_0 = Z_TYPE_P(filter) == IS_STRING;
	if (_0) {
		_0 = !(ZEPHIR_IS_EMPTY(filter));
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&filtered);
		array_init(&filtered);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("errorMessages"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_1$$3, 0, "phalcon/Mvc/Model.zep", 1834);
		if (Z_TYPE_P(&_1$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1$$3), _2$$3)
			{
				ZEPHIR_INIT_NVAR(&message);
				ZVAL_COPY(&message, _2$$3);
				ZEPHIR_CALL_METHOD(&_4$$4, &message, "getfield", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_EQUAL(&_4$$4, filter)) {
					zephir_array_append(&filtered, &message, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1830);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_1$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_3$$3, &_1$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&message, &_1$$3, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_5$$6, &message, "getfield", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_EQUAL(&_5$$6, filter)) {
						zephir_array_append(&filtered, &message, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1830);
					}
				ZEPHIR_CALL_METHOD(NULL, &_1$$3, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&message);
		RETURN_CTOR(&filtered);
	}
	RETURN_MM_MEMBER(getThis(), "errorMessages");
}

/**
 * Returns the models manager related to the entity instance
 */
PHP_METHOD(Phalcon_Mvc_Model, getModelsManager)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "modelsManager");
}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Mvc_Model, getModelsMetaData)
{
	zval metaData, container, _0$$3, _1$$3, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&metaData);
	zephir_read_property(&metaData, this_ptr, ZEND_STRL("modelsMetaData"), PH_NOISY_CC);
	if (Z_TYPE_P(&metaData) != IS_OBJECT) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&container, &_0$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "modelsMetadata");
		ZEPHIR_CALL_METHOD(&_1$$3, &container, "getshared", NULL, 0, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&metaData, &_1$$3);
		if (UNEXPECTED(Z_TYPE_P(&metaData) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsMetadata' is not valid", "phalcon/Mvc/Model.zep", 1868);
			return;
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("modelsMetaData"), &metaData);
	}
	RETURN_CCTOR(&metaData);
}

/**
 * Returns the type of the latest operation performed by the ORM
 * Returns one of the OP_* class constants
 */
PHP_METHOD(Phalcon_Mvc_Model, getOperationMade)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "operationMade");
}

/**
 * Returns the internal old snapshot data
 */
PHP_METHOD(Phalcon_Mvc_Model, getOldSnapshotData)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "oldSnapshot");
}

/**
 * Gets the connection used to read data for the model
 */
PHP_METHOD(Phalcon_Mvc_Model, getReadConnection)
{
	zval transaction, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&transaction);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("transaction"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&transaction, &_0);
	if (Z_TYPE_P(&transaction) == IS_OBJECT) {
		ZEPHIR_RETURN_CALL_METHOD(&transaction, "getconnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getreadconnection", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the DependencyInjection connection service name used to read data
 * related the model
 */
PHP_METHOD(Phalcon_Mvc_Model, getReadConnectionService)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getreadconnectionservice", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns related records based on defined relations
 *
 * @param array arguments
 * @return \Phalcon\Mvc\Model\Resultset\Simple|false
 */
PHP_METHOD(Phalcon_Mvc_Model, getRelated)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *alias_param = NULL, *arguments = NULL, arguments_sub, __$null, relation, className, manager, result, lowerAlias, _0, _1, _2$$3, _3$$3;
	zval alias;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&arguments_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&lowerAlias);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(alias)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(arguments)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &alias_param, &arguments);
	zephir_get_strval(&alias, alias_param);
	if (!arguments) {
		arguments = &arguments_sub;
		arguments = &__$null;
	}


	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, this_ptr, 0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_INIT_VAR(&lowerAlias);
	zephir_fast_strtolower(&lowerAlias, &alias);
	ZEPHIR_CALL_METHOD(&_1, &manager, "getrelationbyalias", NULL, 0, &className, &lowerAlias);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&relation, &_1);
	if (UNEXPECTED(Z_TYPE_P(&relation) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SVSVS(&_3$$3, "There is no defined relations for the model '", &className, "' using alias '", &alias, "'");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 30, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Mvc/Model.zep", 1947);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(arguments) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&result, &manager, "getrelationrecords", NULL, 0, &relation, this_ptr, arguments);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("related"), &lowerAlias, &result);
	} else {
		ZEPHIR_CALL_METHOD(&result, &manager, "getrelationrecords", NULL, 0, &relation, this_ptr, arguments);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&result);
}

/**
 * Checks if saved related records have already been loaded.
 *
 * Only returns true if the records were previously fetched
 * through the model without any additional parameters.
 *
 * ```php
 * $robot = Robots::findFirst();
 * var_dump($robot->isRelationshipLoaded('robotsParts')); // false
 *
 * $robotsParts = $robot->getRobotsParts(['id > 0']);
 * var_dump($robot->isRelationshipLoaded('robotsParts')); // false
 *
 * $robotsParts = $robot->getRobotsParts(); // or $robot->robotsParts
 * var_dump($robot->isRelationshipLoaded('robotsParts')); // true
 *
 * $robot->robotsParts = [new RobotsParts()];
 * var_dump($robot->isRelationshipLoaded('robotsParts')); // false
 * ```
 */
PHP_METHOD(Phalcon_Mvc_Model, isRelationshipLoaded)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *relationshipAlias_param = NULL, _0, _1;
	zval relationshipAlias;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&relationshipAlias);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(relationshipAlias)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &relationshipAlias_param);
	zephir_get_strval(&relationshipAlias, relationshipAlias_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("related"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strtolower(&_1, &relationshipAlias);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &_1));
}

/**
 * Returns schema name where the mapped table is located
 */
PHP_METHOD(Phalcon_Mvc_Model, getSchema)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getmodelschema", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the internal snapshot data
 */
PHP_METHOD(Phalcon_Mvc_Model, getSnapshotData)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "snapshot");
}

/**
 * Returns the table name mapped in the model
 */
PHP_METHOD(Phalcon_Mvc_Model, getSource)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getmodelsource", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns a list of updated values.
 *
 * ```php
 * $robots = Robots::findFirst();
 * print_r($robots->getChangedFields()); // []
 *
 * $robots->deleted = 'Y';
 *
 * $robots->getChangedFields();
 * print_r($robots->getChangedFields()); // ["deleted"]
 * $robots->save();
 * print_r($robots->getChangedFields()); // []
 * print_r($robots->getUpdatedFields()); // ["deleted"]
 * ```
 */
PHP_METHOD(Phalcon_Mvc_Model, getUpdatedFields)
{
	zend_bool _5$$6, _7$$8;
	zend_string *_4;
	zend_ulong _3;
	zval updated;
	zval name, snapshot, oldSnapshot, value, _0, *_1, _2, _6$$6, _8$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&oldSnapshot);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&updated);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("snapshot"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&snapshot, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("oldSnapshot"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&oldSnapshot, &_0);
	if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).update_snapshot_on_save))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The 'updateSnapshotOnSave' option must be enabled for this method to work properly", "phalcon/Mvc/Model.zep", 2071);
		return;
	}
	if (UNEXPECTED(Z_TYPE_P(&snapshot) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The 'keepSnapshots' option must be enabled to track changes", "phalcon/Mvc/Model.zep", 2077);
		return;
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("dirtyState"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!ZEPHIR_IS_LONG(&_0, 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Change checking cannot be performed because the object has not been persisted or is deleted", "phalcon/Mvc/Model.zep", 2086);
		return;
	}
	ZEPHIR_INIT_VAR(&updated);
	array_init(&updated);
	zephir_is_iterable(&snapshot, 0, "phalcon/Mvc/Model.zep", 2101);
	if (Z_TYPE_P(&snapshot) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&snapshot), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&name, _4);
			} else {
				ZVAL_LONG(&name, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			_5$$6 = !(zephir_array_isset(&oldSnapshot, &name));
			if (!(_5$$6)) {
				zephir_array_fetch(&_6$$6, &oldSnapshot, &name, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 2096);
				_5$$6 = !ZEPHIR_IS_IDENTICAL(&value, &_6$$6);
			}
			if (_5$$6) {
				zephir_array_append(&updated, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2097);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &snapshot, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &snapshot, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &snapshot, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &snapshot, "current", NULL, 0);
			zephir_check_call_status();
				_7$$8 = !(zephir_array_isset(&oldSnapshot, &name));
				if (!(_7$$8)) {
					zephir_array_fetch(&_8$$8, &oldSnapshot, &name, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 2096);
					_7$$8 = !ZEPHIR_IS_IDENTICAL(&value, &_8$$8);
				}
				if (_7$$8) {
					zephir_array_append(&updated, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2097);
				}
			ZEPHIR_CALL_METHOD(NULL, &snapshot, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CTOR(&updated);
}

/**
 * Gets the connection used to write data to the model
 */
PHP_METHOD(Phalcon_Mvc_Model, getWriteConnection)
{
	zval transaction, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&transaction);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("transaction"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&transaction, &_0);
	if (Z_TYPE_P(&transaction) == IS_OBJECT) {
		ZEPHIR_RETURN_CALL_METHOD(&transaction, "getconnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getwriteconnection", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the DependencyInjection connection service name used to write
 * data related to the model
 */
PHP_METHOD(Phalcon_Mvc_Model, getWriteConnectionService)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getwriteconnectionservice", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Check if a specific attribute has changed
 * This only works if the model is keeping data snapshots
 *
 *```php
 * $robot = new Robots();
 *
 * $robot->type = "mechanical";
 * $robot->name = "Astro Boy";
 * $robot->year = 1952;
 *
 * $robot->create();
 *
 * $robot->type = "hydraulic";
 *
 * $hasChanged = $robot->hasChanged("type"); // returns true
 * $hasChanged = $robot->hasChanged(["type", "name"]); // returns true
 * $hasChanged = $robot->hasChanged(["type", "name"], true); // returns false
 *```
 *
 * @param string|array fieldName
 * @param boolean allFields
 */
PHP_METHOD(Phalcon_Mvc_Model, hasChanged)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool allFields;
	zval *fieldName = NULL, fieldName_sub, *allFields_param = NULL, __$null, changedFields, intersect;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fieldName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&changedFields);
	ZVAL_UNDEF(&intersect);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(fieldName)
		Z_PARAM_BOOL(allFields)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &fieldName, &allFields_param);
	if (!fieldName) {
		fieldName = &fieldName_sub;
		fieldName = &__$null;
	}
	if (!allFields_param) {
		allFields = 0;
	} else {
		allFields = zephir_get_boolval(allFields_param);
	}


	ZEPHIR_CALL_METHOD(&changedFields, this_ptr, "getchangedfields", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(fieldName) == IS_STRING) {
		RETURN_MM_BOOL(zephir_fast_in_array(fieldName, &changedFields));
	}
	if (Z_TYPE_P(fieldName) == IS_ARRAY) {
		ZEPHIR_CALL_FUNCTION(&intersect, "array_intersect", NULL, 479, fieldName, &changedFields);
		zephir_check_call_status();
		if (allFields) {
			RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(&intersect, fieldName));
		}
		RETURN_MM_BOOL(zephir_fast_count_int(&intersect) > 0);
	}
	RETURN_MM_BOOL(zephir_fast_count_int(&changedFields) > 0);
}

/**
 * Checks if the object has internal snapshot data
 */
PHP_METHOD(Phalcon_Mvc_Model, hasSnapshotData)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("snapshot"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(!(ZEPHIR_IS_EMPTY(&_0)));
}

/**
 * Check if a specific attribute was updated
 * This only works if the model is keeping data snapshots
 *
 * @param string|array fieldName
 */
PHP_METHOD(Phalcon_Mvc_Model, hasUpdated)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool allFields;
	zval *fieldName = NULL, fieldName_sub, *allFields_param = NULL, __$null, updatedFields, intersect;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fieldName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&updatedFields);
	ZVAL_UNDEF(&intersect);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(fieldName)
		Z_PARAM_BOOL(allFields)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &fieldName, &allFields_param);
	if (!fieldName) {
		fieldName = &fieldName_sub;
		fieldName = &__$null;
	}
	if (!allFields_param) {
		allFields = 0;
	} else {
		allFields = zephir_get_boolval(allFields_param);
	}


	ZEPHIR_CALL_METHOD(&updatedFields, this_ptr, "getupdatedfields", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(fieldName) == IS_STRING) {
		RETURN_MM_BOOL(zephir_fast_in_array(fieldName, &updatedFields));
	}
	if (Z_TYPE_P(fieldName) == IS_ARRAY) {
		ZEPHIR_CALL_FUNCTION(&intersect, "array_intersect", NULL, 479, fieldName, &updatedFields);
		zephir_check_call_status();
		if (allFields) {
			RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(&intersect, fieldName));
		}
		RETURN_MM_BOOL(zephir_fast_count_int(&intersect) > 0);
	}
	RETURN_MM_BOOL(zephir_fast_count_int(&updatedFields) > 0);
}

/**
 * Serializes the object for json_encode
 *
 *```php
 * echo json_encode($robot);
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model, jsonSerialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the maximum value of a column for a result-set of rows that match
 * the specified conditions
 *
 * ```php
 * // What is the maximum robot id?
 * $id = Robots::maximum(
 *     [
 *         "column" => "id",
 *     ]
 * );
 *
 * echo "The maximum robot id is: ", $id, "\n";
 *
 * // What is the maximum id of mechanical robots?
 * $sum = Robots::maximum(
 *     [
 *         "type = 'mechanical'",
 *         "column" => "id",
 *     ]
 * );
 *
 * echo "The maximum robot id of mechanical robots is ", $id, "\n";
 * ```
 *
 * @param array parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, maximum)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, parameters_sub, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(parameters)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "MAX");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "maximum");
	ZEPHIR_RETURN_CALL_SELF("groupresult", NULL, 0, &_0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the minimum value of a column for a result-set of rows that match
 * the specified conditions
 *
 * ```php
 * // What is the minimum robot id?
 * $id = Robots::minimum(
 *     [
 *         "column" => "id",
 *     ]
 * );
 *
 * echo "The minimum robot id is: ", $id;
 *
 * // What is the minimum id of mechanical robots?
 * $sum = Robots::minimum(
 *     [
 *         "type = 'mechanical'",
 *         "column" => "id",
 *     ]
 * );
 *
 * echo "The minimum robot id of mechanical robots is ", $id;
 * ```
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Mvc_Model, minimum)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, parameters_sub, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(parameters)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "MIN");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "minimum");
	ZEPHIR_RETURN_CALL_SELF("groupresult", NULL, 0, &_0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Create a criteria for a specific model
 */
PHP_METHOD(Phalcon_Mvc_Model, query)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *container = NULL, container_sub, __$null, criteria, _3, _1$$4, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&criteria);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &container);
	if (!container) {
		container = &container_sub;
		ZEPHIR_CPY_WRT(container, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(container);
	}


	if (Z_TYPE_P(container) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(container, phalcon_di_ce, "getdefault", &_0, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&criteria);
	if (zephir_instance_of_ev(container, phalcon_di_diinterface_ce)) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "Phalcon\\Mvc\\Model\\Criteria");
		ZEPHIR_CALL_METHOD(&_1$$4, container, "get", NULL, 0, &_2$$4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&criteria, &_1$$4);
	} else {
		object_init_ex(&criteria, phalcon_mvc_model_criteria_ce);
		if (zephir_has_constructor(&criteria)) {
			ZEPHIR_CALL_METHOD(NULL, &criteria, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		ZEPHIR_CALL_METHOD(NULL, &criteria, "setdi", NULL, 480, container);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_3);
	zephir_get_called_class(&_3);
	ZEPHIR_CALL_METHOD(NULL, &criteria, "setmodelname", NULL, 481, &_3);
	zephir_check_call_status();
	RETURN_CCTOR(&criteria);
}

/**
 * Reads an attribute value by its name
 *
 * ```php
 * echo $robot->readAttribute("name");
 * ```
 */
PHP_METHOD(Phalcon_Mvc_Model, readAttribute)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *attribute_param = NULL, _0;
	zval attribute;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(attribute)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attribute_param);
	if (UNEXPECTED(Z_TYPE_P(attribute_param) != IS_STRING && Z_TYPE_P(attribute_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'attribute' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(attribute_param) == IS_STRING)) {
		zephir_get_strval(&attribute, attribute_param);
	} else {
		ZEPHIR_INIT_VAR(&attribute);
	}


	if (!(zephir_isset_property_zval(this_ptr, &attribute))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property_zval(&_0, this_ptr, &attribute, PH_NOISY_CC);
	RETURN_CCTOR(&_0);
}

/**
 * Refreshes the model attributes re-querying the record from the database
 */
PHP_METHOD(Phalcon_Mvc_Model, refresh)
{
	zval fields, _9, _7$$9, _8$$10;
	zval metaData, readConnection, schema, source, table, uniqueKey, tables, uniqueParams, dialect, row, attribute, manager, columnMap, _0, _1, _4, *_5, _6, _10, _11, _14, _2$$6, _3$$6, _12$$11, _13$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&readConnection);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&uniqueKey);
	ZVAL_UNDEF(&tables);
	ZVAL_UNDEF(&uniqueParams);
	ZVAL_UNDEF(&dialect);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$10);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("dirtyState"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!ZEPHIR_IS_LONG(&_0, 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record cannot be refreshed because it does not exist or is deleted", "phalcon/Mvc/Model.zep", 2356);
		return;
	}
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&readConnection, this_ptr, "getreadconnection", NULL, 482);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_1);
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 474);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 475);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("uniqueKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueKey, &_1);
	if (!(zephir_is_true(&uniqueKey))) {
		ZEPHIR_CALL_METHOD(&_2$$6, this_ptr, "has", NULL, 0, &metaData, &readConnection);
		zephir_check_call_status();
		if (UNEXPECTED(!zephir_is_true(&_2$$6))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record cannot be refreshed because it does not exist or is deleted", "phalcon/Mvc/Model.zep", 2381);
			return;
		}
		zephir_read_property(&_3$$6, this_ptr, ZEND_STRL("uniqueKey"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&uniqueKey, &_3$$6);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("uniqueParams"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueParams, &_1);
	if (UNEXPECTED(Z_TYPE_P(&uniqueParams) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record cannot be refreshed because it does not exist or is deleted", "phalcon/Mvc/Model.zep", 2392);
		return;
	}
	ZEPHIR_INIT_VAR(&fields);
	array_init(&fields);
	ZEPHIR_CALL_METHOD(&_4, &metaData, "getattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(&_4, 0, "phalcon/Mvc/Model.zep", 2407);
	if (Z_TYPE_P(&_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_4), _5)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _5);
			ZEPHIR_INIT_NVAR(&_7$$9);
			zephir_create_array(&_7$$9, 1, 0);
			zephir_array_fast_append(&_7$$9, &attribute);
			zephir_array_append(&fields, &_7$$9, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2401);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_4, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_6, &_4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attribute, &_4, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_8$$10);
				zephir_create_array(&_8$$10, 1, 0);
				zephir_array_fast_append(&_8$$10, &attribute);
				zephir_array_append(&fields, &_8$$10, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2401);
			ZEPHIR_CALL_METHOD(NULL, &_4, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&attribute);
	ZEPHIR_CALL_METHOD(&dialect, &readConnection, "getdialect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_9);
	zephir_create_array(&_9, 3, 0);
	zephir_array_update_string(&_9, SL("columns"), &fields, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_10, &readConnection, "escapeidentifier", NULL, 0, &table);
	zephir_check_call_status();
	zephir_array_update_string(&_9, SL("tables"), &_10, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_9, SL("where"), &uniqueKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&tables, &dialect, "select", NULL, 0, &_9);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("uniqueTypes"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_11, 2);
	ZEPHIR_CALL_METHOD(&row, &readConnection, "fetchone", NULL, 0, &tables, &_11, &uniqueParams, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(&row) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, this_ptr);
		zephir_check_call_status();
		ZVAL_NULL(&_12$$11);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "assign", NULL, 0, &row, &_12$$11, &columnMap);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_13$$11, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (zephir_is_true(&_13$$11)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setsnapshotdata", NULL, 0, &row, &columnMap);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoldsnapshotdata", NULL, 0, &row, &columnMap);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_VAR(&_14);
	ZVAL_STRING(&_14, "afterFetch");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_14);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Inserts or updates a model instance. Returning true on success or false
 * otherwise.
 *
 *```php
 * // Creating a new robot
 * $robot = new Robots();
 *
 * $robot->type = "mechanical";
 * $robot->name = "Astro Boy";
 * $robot->year = 1952;
 *
 * $robot->save();
 *
 * // Updating a robot name
 * $robot = Robots::findFirst("id = 100");
 *
 * $robot->name = "Biomass";
 *
 * $robot->save();
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model, save)
{
	zend_bool hasRelatedToSave = 0;
	zval metaData, schema, writeConnection, readConnection, source, table, identityField, exists, success, relatedToSave, _0, _4, _1$$3, _2$$7, _3$$8, _5$$10, _6$$11, _7$$11, _8$$14, _9$$16, _10$$18, _11$$21, _12$$20;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&writeConnection);
	ZVAL_UNDEF(&readConnection);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&identityField);
	ZVAL_UNDEF(&exists);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&relatedToSave);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_5$$10);
	ZVAL_UNDEF(&_6$$11);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_8$$14);
	ZVAL_UNDEF(&_9$$16);
	ZVAL_UNDEF(&_10$$18);
	ZVAL_UNDEF(&_11$$21);
	ZVAL_UNDEF(&_12$$20);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&writeConnection, this_ptr, "getwriteconnection", NULL, 472);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "prepareSave");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&relatedToSave, this_ptr, "collectrelatedtosave", NULL, 0);
	zephir_check_call_status();
	hasRelatedToSave = zephir_fast_count_int(&relatedToSave) > 0;
	if (hasRelatedToSave) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "presaverelatedrecords", NULL, 0, &writeConnection, &relatedToSave);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_1$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 474);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 475);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	ZEPHIR_CALL_METHOD(&readConnection, this_ptr, "getreadconnection", NULL, 482);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&exists, this_ptr, "has", NULL, 0, &metaData, &readConnection);
	zephir_check_call_status();
	if (zephir_is_true(&exists)) {
		ZEPHIR_INIT_ZVAL_NREF(_2$$7);
		ZVAL_LONG(&_2$$7, 2);
		zephir_update_property_zval(this_ptr, ZEND_STRL("operationMade"), &_2$$7);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_3$$8);
		ZVAL_LONG(&_3$$8, 1);
		zephir_update_property_zval(this_ptr, ZEND_STRL("operationMade"), &_3$$8);
	}
	ZEPHIR_INIT_NVAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("errorMessages"), &_0);
	ZEPHIR_CALL_METHOD(&identityField, &metaData, "getidentityfield", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "presave", NULL, 0, &metaData, &exists, &identityField);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_4)) {
		if (hasRelatedToSave) {
			ZVAL_BOOL(&_5$$10, 0);
			ZEPHIR_CALL_METHOD(NULL, &writeConnection, "rollback", NULL, 0, &_5$$10);
			zephir_check_call_status();
		}
		if (UNEXPECTED(ZEPHIR_GLOBAL(orm).exception_on_failed_save)) {
			ZEPHIR_INIT_VAR(&_6$$11);
			object_init_ex(&_6$$11, phalcon_mvc_model_validationfailed_ce);
			ZEPHIR_CALL_METHOD(&_7$$11, this_ptr, "getmessages", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_6$$11, "__construct", NULL, 483, this_ptr, &_7$$11);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$11, "phalcon/Mvc/Model.zep", 2558);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_BOOL(0);
	}
	if (zephir_is_true(&exists)) {
		ZEPHIR_CALL_METHOD(&success, this_ptr, "dolowupdate", NULL, 0, &metaData, &writeConnection, &table);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&success, this_ptr, "dolowinsert", NULL, 0, &metaData, &writeConnection, &table, &identityField);
		zephir_check_call_status();
	}
	if (zephir_is_true(&success)) {
		ZEPHIR_INIT_ZVAL_NREF(_8$$14);
		ZVAL_LONG(&_8$$14, 0);
		zephir_update_property_zval(this_ptr, ZEND_STRL("dirtyState"), &_8$$14);
	}
	if (hasRelatedToSave) {
		if (ZEPHIR_IS_FALSE_IDENTICAL(&success)) {
			ZVAL_BOOL(&_9$$16, 0);
			ZEPHIR_CALL_METHOD(NULL, &writeConnection, "rollback", NULL, 0, &_9$$16);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&success, this_ptr, "postsaverelatedrecords", NULL, 0, &writeConnection, &relatedToSave);
			zephir_check_call_status();
		}
	}
	if (ZEPHIR_GLOBAL(orm).events) {
		ZEPHIR_CALL_METHOD(&_10$$18, this_ptr, "postsave", NULL, 0, &success, &exists);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&success, &_10$$18);
	}
	if (ZEPHIR_IS_FALSE_IDENTICAL(&success)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "canceloperation", NULL, 0);
		zephir_check_call_status();
	} else {
		if (hasRelatedToSave) {
			ZEPHIR_INIT_VAR(&_11$$21);
			array_init(&_11$$21);
			zephir_update_property_zval(this_ptr, ZEND_STRL("dirtyRelated"), &_11$$21);
		}
		ZEPHIR_INIT_VAR(&_12$$20);
		ZVAL_STRING(&_12$$20, "afterSave");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_12$$20);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&success);
}

/**
 * Serializes the object ignoring connections, services, related objects or
 * static properties
 */
PHP_METHOD(Phalcon_Mvc_Model, serialize)
{
	zval _6;
	zend_bool _2, _3;
	zval attributes, manager, dirtyState, snapshot, _0, _1, _4, _5$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&dirtyState);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&snapshot);
	ZVAL_NULL(&snapshot);
	ZEPHIR_CALL_METHOD(&attributes, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("dirtyState"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dirtyState, &_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_1);
	ZEPHIR_CALL_METHOD(&_1, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
	zephir_check_call_status();
	_2 = zephir_is_true(&_1);
	if (_2) {
		zephir_read_property(&_0, this_ptr, ZEND_STRL("snapshot"), PH_NOISY_CC | PH_READONLY);
		_2 = Z_TYPE_P(&_0) != IS_NULL;
	}
	_3 = _2;
	if (_3) {
		zephir_read_property(&_4, this_ptr, ZEND_STRL("snapshot"), PH_NOISY_CC | PH_READONLY);
		_3 = !ZEPHIR_IS_EQUAL(&attributes, &_4);
	}
	if (_3) {
		zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("snapshot"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&snapshot, &_5$$3);
	}
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 3, 0);
	zephir_array_update_string(&_6, SL("attributes"), &attributes, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_6, SL("snapshot"), &snapshot, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_6, SL("dirtyState"), &dirtyState, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 14, &_6);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Unserializes the object from a serialized string
 */
PHP_METHOD(Phalcon_Mvc_Model, unserialize)
{
	zend_string *_7$$7;
	zend_ulong _6$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, attributes, container, manager, key, value, snapshot, properties, dirtyState, _0$$4, _2$$3, _3$$3, *_4$$7, _5$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&properties);
	ZVAL_UNDEF(&dirtyState);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);


	ZEPHIR_CALL_FUNCTION(&attributes, "unserialize", NULL, 15, data);
	zephir_check_call_status();
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		if (!(zephir_array_isset_string(&attributes, SL("attributes")))) {
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_create_array(&_0$$4, 1, 0);
			zephir_array_update_string(&_0$$4, SL("attributes"), &attributes, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&attributes, &_0$$4);
		}
		ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_ce, "getdefault", &_1, 0);
		zephir_check_call_status();
		if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injection container is required to access the services related to the ODM", "phalcon/Mvc/Model.zep", 2678);
			return;
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("container"), &container);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "modelsManager");
		ZEPHIR_CALL_METHOD(&_2$$3, &container, "getshared", NULL, 0, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&manager, &_2$$3);
		if (UNEXPECTED(Z_TYPE_P(&manager) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsManager' is not valid", "phalcon/Mvc/Model.zep", 2694);
			return;
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("modelsManager"), &manager);
		ZEPHIR_CALL_METHOD(NULL, &manager, "initialize", NULL, 0, this_ptr);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&properties);
		if (zephir_array_isset_string_fetch(&properties, &attributes, SL("attributes"), 0)) {
			zephir_is_iterable(&properties, 0, "phalcon/Mvc/Model.zep", 2717);
			if (Z_TYPE_P(&properties) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&properties), _6$$7, _7$$7, _4$$7)
				{
					ZEPHIR_INIT_NVAR(&key);
					if (_7$$7 != NULL) { 
						ZVAL_STR_COPY(&key, _7$$7);
					} else {
						ZVAL_LONG(&key, _6$$7);
					}
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_COPY(&value, _4$$7);
					zephir_update_property_zval_zval(this_ptr, &key, &value);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &properties, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_5$$7, &properties, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_5$$7)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&key, &properties, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&value, &properties, "current", NULL, 0);
					zephir_check_call_status();
						zephir_update_property_zval_zval(this_ptr, &key, &value);
					ZEPHIR_CALL_METHOD(NULL, &properties, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_INIT_NVAR(&key);
		} else {
			ZEPHIR_INIT_NVAR(&properties);
			array_init(&properties);
		}
		ZEPHIR_OBS_VAR(&dirtyState);
		if (zephir_array_isset_string_fetch(&dirtyState, &attributes, SL("dirtyState"), 0)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("dirtyState"), &dirtyState);
		}
		ZEPHIR_CALL_METHOD(&_2$$3, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (zephir_is_true(&_2$$3)) {
			if (zephir_array_isset_string_fetch(&snapshot, &attributes, SL("snapshot"), 1)) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("snapshot"), &snapshot);
			} else {
				zephir_update_property_zval(this_ptr, ZEND_STRL("snapshot"), &properties);
			}
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the DependencyInjection connection service name
 */
PHP_METHOD(Phalcon_Mvc_Model, setConnectionService)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connectionService_param = NULL, _0;
	zval connectionService;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connectionService);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(connectionService)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connectionService_param);
	if (UNEXPECTED(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(connectionService_param) == IS_STRING)) {
		zephir_get_strval(&connectionService, connectionService_param);
	} else {
		ZEPHIR_INIT_VAR(&connectionService);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setconnectionservice", NULL, 0, this_ptr, &connectionService);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the dirty state of the object using one of the DIRTY_STATE_* constants
 */
PHP_METHOD(Phalcon_Mvc_Model, setDirtyState)
{
	zval *dirtyState_param = NULL, _0;
	zend_long dirtyState;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(dirtyState)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &dirtyState_param);
	dirtyState = zephir_get_intval(dirtyState_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, dirtyState);
	zephir_update_property_zval(this_ptr, ZEND_STRL("dirtyState"), &_0);
	RETURN_THISW();
}

/**
 * Sets a custom events manager
 */
PHP_METHOD(Phalcon_Mvc_Model, setEventsManager)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventsManager, eventsManager_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, phalcon_events_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventsManager);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setcustomeventsmanager", NULL, 0, this_ptr, eventsManager);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the DependencyInjection connection service name used to read data
 */
PHP_METHOD(Phalcon_Mvc_Model, setReadConnectionService)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connectionService_param = NULL, _0;
	zval connectionService;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connectionService);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(connectionService)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connectionService_param);
	if (UNEXPECTED(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(connectionService_param) == IS_STRING)) {
		zephir_get_strval(&connectionService, connectionService_param);
	} else {
		ZEPHIR_INIT_VAR(&connectionService);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setreadconnectionservice", NULL, 0, this_ptr, &connectionService);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the record's old snapshot data.
 * This method is used internally to set old snapshot data when the model
 * was set up to keep snapshot data
 *
 * @param array data
 * @param array columnMap
 */
PHP_METHOD(Phalcon_Mvc_Model, setOldSnapshotData)
{
	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *columnMap = NULL, columnMap_sub, __$null, key, value, attribute, *_0$$3, _1$$3, _4$$7, _5$$7, _7$$10, _8$$10, _9$$14, _10$$14, _11$$17, _12$$17;
	zval data, snapshot;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$14);
	ZVAL_UNDEF(&_10$$14);
	ZVAL_UNDEF(&_11$$17);
	ZVAL_UNDEF(&_12$$17);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(columnMap)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data_param, &columnMap);
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	if (!columnMap) {
		columnMap = &columnMap_sub;
		columnMap = &__$null;
	}


	if (Z_TYPE_P(columnMap) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&snapshot);
		array_init(&snapshot);
		zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 2835);
		if (Z_TYPE_P(&data) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _3$$3);
				} else {
					ZVAL_LONG(&key, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _0$$3);
				if (Z_TYPE_P(&key) != IS_STRING) {
					continue;
				}
				ZEPHIR_OBS_NVAR(&attribute);
				if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0))) {
					if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
						ZEPHIR_INIT_NVAR(&_4$$7);
						object_init_ex(&_4$$7, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_5$$7);
						ZEPHIR_CONCAT_SVS(&_5$$7, "Column '", &key, "' doesn't make part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_4$$7, "__construct", &_6, 30, &_5$$7);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_4$$7, "phalcon/Mvc/Model.zep", 2815);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
				if (Z_TYPE_P(&attribute) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attribute);
					if (!(zephir_array_isset_long_fetch(&attribute, &attribute, 0, 0))) {
						if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
							ZEPHIR_INIT_NVAR(&_7$$10);
							object_init_ex(&_7$$10, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_8$$10);
							ZEPHIR_CONCAT_SVS(&_8$$10, "Column '", &key, "' doesn't make part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_7$$10, "__construct", &_6, 30, &_8$$10);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_7$$10, "phalcon/Mvc/Model.zep", 2826);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
				}
				zephir_array_update_zval(&snapshot, &attribute, &value, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &data, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&key) != IS_STRING) {
						continue;
					}
					ZEPHIR_OBS_NVAR(&attribute);
					if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0))) {
						if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
							ZEPHIR_INIT_NVAR(&_9$$14);
							object_init_ex(&_9$$14, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_10$$14);
							ZEPHIR_CONCAT_SVS(&_10$$14, "Column '", &key, "' doesn't make part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_9$$14, "__construct", &_6, 30, &_10$$14);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_9$$14, "phalcon/Mvc/Model.zep", 2815);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
					if (Z_TYPE_P(&attribute) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attribute);
						if (!(zephir_array_isset_long_fetch(&attribute, &attribute, 0, 0))) {
							if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
								ZEPHIR_INIT_NVAR(&_11$$17);
								object_init_ex(&_11$$17, phalcon_mvc_model_exception_ce);
								ZEPHIR_INIT_NVAR(&_12$$17);
								ZEPHIR_CONCAT_SVS(&_12$$17, "Column '", &key, "' doesn't make part of the column map");
								ZEPHIR_CALL_METHOD(NULL, &_11$$17, "__construct", &_6, 30, &_12$$17);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_11$$17, "phalcon/Mvc/Model.zep", 2826);
								ZEPHIR_MM_RESTORE();
								return;
							}
							continue;
						}
					}
					zephir_array_update_zval(&snapshot, &attribute, &value, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		ZEPHIR_CPY_WRT(&snapshot, &data);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("oldSnapshot"), &snapshot);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the record's snapshot data.
 * This method is used internally to set snapshot data when the model was
 * set up to keep snapshot data
 *
 * @param array columnMap
 */
PHP_METHOD(Phalcon_Mvc_Model, setSnapshotData)
{
	zend_bool _4$$4, _12$$12;
	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *columnMap = NULL, columnMap_sub, __$null, key, value, attribute, *_0$$3, _1$$3, _5$$6, _7$$8, _8$$8, _10$$11, _11$$11, _13$$14, _14$$16, _15$$16, _16$$19, _17$$19;
	zval data, snapshot;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_14$$16);
	ZVAL_UNDEF(&_15$$16);
	ZVAL_UNDEF(&_16$$19);
	ZVAL_UNDEF(&_17$$19);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(columnMap)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data_param, &columnMap);
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	if (!columnMap) {
		columnMap = &columnMap_sub;
		columnMap = &__$null;
	}


	if (Z_TYPE_P(columnMap) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&snapshot);
		array_init(&snapshot);
		zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 2900);
		if (Z_TYPE_P(&data) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _3$$3);
				} else {
					ZVAL_LONG(&key, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _0$$3);
				if (Z_TYPE_P(&key) != IS_STRING) {
					continue;
				}
				_4$$4 = !(zephir_array_isset(columnMap, &key));
				if (_4$$4) {
					_4$$4 = ZEPHIR_GLOBAL(orm).case_insensitive_column_map;
				}
				if (_4$$4) {
					ZEPHIR_CALL_SELF(&_5$$6, "caseinsensitivecolumnmap", &_6, 471, columnMap, &key);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&key, &_5$$6);
				}
				ZEPHIR_OBS_NVAR(&attribute);
				if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0))) {
					if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
						ZEPHIR_INIT_NVAR(&_7$$8);
						object_init_ex(&_7$$8, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_8$$8);
						ZEPHIR_CONCAT_SVS(&_8$$8, "Column '", &key, "' doesn't make part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_7$$8, "__construct", &_9, 30, &_8$$8);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_7$$8, "phalcon/Mvc/Model.zep", 2880);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
				if (Z_TYPE_P(&attribute) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attribute);
					if (!(zephir_array_isset_long_fetch(&attribute, &attribute, 0, 0))) {
						if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
							ZEPHIR_INIT_NVAR(&_10$$11);
							object_init_ex(&_10$$11, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_11$$11);
							ZEPHIR_CONCAT_SVS(&_11$$11, "Column '", &key, "' doesn't make part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_10$$11, "__construct", &_9, 30, &_11$$11);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_10$$11, "phalcon/Mvc/Model.zep", 2891);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
				}
				zephir_array_update_zval(&snapshot, &attribute, &value, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &data, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&key) != IS_STRING) {
						continue;
					}
					_12$$12 = !(zephir_array_isset(columnMap, &key));
					if (_12$$12) {
						_12$$12 = ZEPHIR_GLOBAL(orm).case_insensitive_column_map;
					}
					if (_12$$12) {
						ZEPHIR_CALL_SELF(&_13$$14, "caseinsensitivecolumnmap", &_6, 471, columnMap, &key);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&key, &_13$$14);
					}
					ZEPHIR_OBS_NVAR(&attribute);
					if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0))) {
						if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
							ZEPHIR_INIT_NVAR(&_14$$16);
							object_init_ex(&_14$$16, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_15$$16);
							ZEPHIR_CONCAT_SVS(&_15$$16, "Column '", &key, "' doesn't make part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_14$$16, "__construct", &_9, 30, &_15$$16);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_14$$16, "phalcon/Mvc/Model.zep", 2880);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
					if (Z_TYPE_P(&attribute) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attribute);
						if (!(zephir_array_isset_long_fetch(&attribute, &attribute, 0, 0))) {
							if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
								ZEPHIR_INIT_NVAR(&_16$$19);
								object_init_ex(&_16$$19, phalcon_mvc_model_exception_ce);
								ZEPHIR_INIT_NVAR(&_17$$19);
								ZEPHIR_CONCAT_SVS(&_17$$19, "Column '", &key, "' doesn't make part of the column map");
								ZEPHIR_CALL_METHOD(NULL, &_16$$19, "__construct", &_9, 30, &_17$$19);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_16$$19, "phalcon/Mvc/Model.zep", 2891);
								ZEPHIR_MM_RESTORE();
								return;
							}
							continue;
						}
					}
					zephir_array_update_zval(&snapshot, &attribute, &value, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		ZEPHIR_CPY_WRT(&snapshot, &data);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("snapshot"), &snapshot);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets a transaction related to the Model instance
 *
 *```php
 * use Phalcon\Mvc\Model\Transaction\Manager as TxManager;
 * use Phalcon\Mvc\Model\Transaction\Failed as TxFailed;
 *
 * try {
 *     $txManager = new TxManager();
 *
 *     $transaction = $txManager->get();
 *
 *     $robot = new Robots();
 *
 *     $robot->setTransaction($transaction);
 *
 *     $robot->name       = "WALL·E";
 *     $robot->created_at = date("Y-m-d");
 *
 *     if ($robot->save() === false) {
 *         $transaction->rollback("Can't save robot");
 *     }
 *
 *     $robotPart = new RobotParts();
 *
 *     $robotPart->setTransaction($transaction);
 *
 *     $robotPart->type = "head";
 *
 *     if ($robotPart->save() === false) {
 *         $transaction->rollback("Robot part cannot be saved");
 *     }
 *
 *     $transaction->commit();
 * } catch (TxFailed $e) {
 *     echo "Failed, reason: ", $e->getMessage();
 * }
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model, setTransaction)
{
	zval *transaction, transaction_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&transaction_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(transaction, phalcon_mvc_model_transactioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &transaction);


	zephir_update_property_zval(this_ptr, ZEND_STRL("transaction"), transaction);
	RETURN_THISW();
}

/**
 * Enables/disables options in the ORM
 */
PHP_METHOD(Phalcon_Mvc_Model, setup)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL, disableEvents, columnRenaming, notNullValidations, exceptionOnFailedSave, exceptionOnFailedMetaDataSave, phqlLiterals, virtualForeignKeys, lateStateBinding, castOnHydrate, ignoreUnknownColumns, updateSnapshotOnSave, disableAssignSetters, caseInsensitiveColumnMap, prefetchRecords, lastInsertId;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&disableEvents);
	ZVAL_UNDEF(&columnRenaming);
	ZVAL_UNDEF(&notNullValidations);
	ZVAL_UNDEF(&exceptionOnFailedSave);
	ZVAL_UNDEF(&exceptionOnFailedMetaDataSave);
	ZVAL_UNDEF(&phqlLiterals);
	ZVAL_UNDEF(&virtualForeignKeys);
	ZVAL_UNDEF(&lateStateBinding);
	ZVAL_UNDEF(&castOnHydrate);
	ZVAL_UNDEF(&ignoreUnknownColumns);
	ZVAL_UNDEF(&updateSnapshotOnSave);
	ZVAL_UNDEF(&disableAssignSetters);
	ZVAL_UNDEF(&caseInsensitiveColumnMap);
	ZVAL_UNDEF(&prefetchRecords);
	ZVAL_UNDEF(&lastInsertId);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);


	ZEPHIR_OBS_VAR(&disableEvents);
	if (zephir_array_isset_string_fetch(&disableEvents, &options, SL("events"), 0)) {
		ZEPHIR_GLOBAL(orm).events = zend_is_true(&disableEvents);
	}
	ZEPHIR_OBS_VAR(&virtualForeignKeys);
	if (zephir_array_isset_string_fetch(&virtualForeignKeys, &options, SL("virtualForeignKeys"), 0)) {
		ZEPHIR_GLOBAL(orm).virtual_foreign_keys = zend_is_true(&virtualForeignKeys);
	}
	ZEPHIR_OBS_VAR(&columnRenaming);
	if (zephir_array_isset_string_fetch(&columnRenaming, &options, SL("columnRenaming"), 0)) {
		ZEPHIR_GLOBAL(orm).column_renaming = zend_is_true(&columnRenaming);
	}
	ZEPHIR_OBS_VAR(&notNullValidations);
	if (zephir_array_isset_string_fetch(&notNullValidations, &options, SL("notNullValidations"), 0)) {
		ZEPHIR_GLOBAL(orm).not_null_validations = zend_is_true(&notNullValidations);
	}
	ZEPHIR_OBS_VAR(&exceptionOnFailedSave);
	if (zephir_array_isset_string_fetch(&exceptionOnFailedSave, &options, SL("exceptionOnFailedSave"), 0)) {
		ZEPHIR_GLOBAL(orm).exception_on_failed_save = zend_is_true(&exceptionOnFailedSave);
	}
	ZEPHIR_OBS_VAR(&exceptionOnFailedMetaDataSave);
	if (zephir_array_isset_string_fetch(&exceptionOnFailedMetaDataSave, &options, SL("exceptionOnFailedMetaDataSave"), 0)) {
		ZEPHIR_GLOBAL(orm).exception_on_failed_metadata_save = zend_is_true(&exceptionOnFailedMetaDataSave);
	}
	ZEPHIR_OBS_VAR(&phqlLiterals);
	if (zephir_array_isset_string_fetch(&phqlLiterals, &options, SL("phqlLiterals"), 0)) {
		ZEPHIR_GLOBAL(orm).enable_literals = zend_is_true(&phqlLiterals);
	}
	ZEPHIR_OBS_VAR(&lateStateBinding);
	if (zephir_array_isset_string_fetch(&lateStateBinding, &options, SL("lateStateBinding"), 0)) {
		ZEPHIR_GLOBAL(orm).late_state_binding = zend_is_true(&lateStateBinding);
	}
	ZEPHIR_OBS_VAR(&castOnHydrate);
	if (zephir_array_isset_string_fetch(&castOnHydrate, &options, SL("castOnHydrate"), 0)) {
		ZEPHIR_GLOBAL(orm).cast_on_hydrate = zend_is_true(&castOnHydrate);
	}
	ZEPHIR_OBS_VAR(&ignoreUnknownColumns);
	if (zephir_array_isset_string_fetch(&ignoreUnknownColumns, &options, SL("ignoreUnknownColumns"), 0)) {
		ZEPHIR_GLOBAL(orm).ignore_unknown_columns = zend_is_true(&ignoreUnknownColumns);
	}
	ZEPHIR_OBS_VAR(&caseInsensitiveColumnMap);
	if (zephir_array_isset_string_fetch(&caseInsensitiveColumnMap, &options, SL("caseInsensitiveColumnMap"), 0)) {
		ZEPHIR_GLOBAL(orm).case_insensitive_column_map = zend_is_true(&caseInsensitiveColumnMap);
	}
	ZEPHIR_OBS_VAR(&updateSnapshotOnSave);
	if (zephir_array_isset_string_fetch(&updateSnapshotOnSave, &options, SL("updateSnapshotOnSave"), 0)) {
		ZEPHIR_GLOBAL(orm).update_snapshot_on_save = zend_is_true(&updateSnapshotOnSave);
	}
	ZEPHIR_OBS_VAR(&disableAssignSetters);
	if (zephir_array_isset_string_fetch(&disableAssignSetters, &options, SL("disableAssignSetters"), 0)) {
		ZEPHIR_GLOBAL(orm).disable_assign_setters = zend_is_true(&disableAssignSetters);
	}
	ZEPHIR_OBS_VAR(&prefetchRecords);
	if (zephir_array_isset_string_fetch(&prefetchRecords, &options, SL("prefetchRecords"), 0)) {
		ZEPHIR_GLOBAL(orm).resultset_prefetch_records = ZSTR_VAL(zval_get_string(&prefetchRecords));
	}
	ZEPHIR_OBS_VAR(&lastInsertId);
	if (zephir_array_isset_string_fetch(&lastInsertId, &options, SL("castLastInsertIdToInt"), 0)) {
		ZEPHIR_GLOBAL(orm).cast_last_insert_id_to_int = zend_is_true(&lastInsertId);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the DependencyInjection connection service name used to write data
 */
PHP_METHOD(Phalcon_Mvc_Model, setWriteConnectionService)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connectionService_param = NULL, _0;
	zval connectionService;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connectionService);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(connectionService)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connectionService_param);
	if (UNEXPECTED(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(connectionService_param) == IS_STRING)) {
		zephir_get_strval(&connectionService, connectionService_param);
	} else {
		ZEPHIR_INIT_VAR(&connectionService);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setwriteconnectionservice", NULL, 0, this_ptr, &connectionService);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Skips the current operation forcing a success state
 */
PHP_METHOD(Phalcon_Mvc_Model, skipOperation)
{
	zval *skip_param = NULL, __$true, __$false;
	zend_bool skip;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(skip)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &skip_param);
	skip = zephir_get_boolval(skip_param);


	if (skip) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("skipped"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("skipped"), &__$false);
	}
}

/**
 * Calculates the sum on a column for a result-set of rows that match the
 * specified conditions
 *
 * ```php
 * // How much are all robots?
 * $sum = Robots::sum(
 *     [
 *         "column" => "price",
 *     ]
 * );
 *
 * echo "The total price of robots is ", $sum, "\n";
 *
 * // How much are mechanical robots?
 * $sum = Robots::sum(
 *     [
 *         "type = 'mechanical'",
 *         "column" => "price",
 *     ]
 * );
 *
 * echo "The total price of mechanical robots is  ", $sum, "\n";
 * ```
 *
 * @param array parameters
 * @return double | ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, sum)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, parameters_sub, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(parameters)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "SUM");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "sumatory");
	ZEPHIR_RETURN_CALL_SELF("groupresult", NULL, 0, &_0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the instance as an array representation
 *
 *```php
 * print_r(
 *     $robot->toArray()
 * );
 *```
 *
 * @param array $columns
 */
PHP_METHOD(Phalcon_Mvc_Model, toArray)
{
	zend_bool _3$$4, _9$$14;
	zval data;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *columns = NULL, columns_sub, __$null, metaData, columnMap, attribute, attributeField, value, _0, *_1, _2, _4$$5, _6$$7, _7$$7, _10$$15, _11$$17, _12$$17;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columns_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_10$$15);
	ZVAL_UNDEF(&_11$$17);
	ZVAL_UNDEF(&_12$$17);
	ZVAL_UNDEF(&data);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(columns)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &columns);
	if (!columns) {
		columns = &columns_sub;
		columns = &__$null;
	}


	ZEPHIR_INIT_VAR(&data);
	array_init(&data);
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &metaData, "getattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/Mvc/Model.zep", 3172);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _1);
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				_3$$4 = !(zephir_array_isset(&columnMap, &attribute));
				if (_3$$4) {
					_3$$4 = ZEPHIR_GLOBAL(orm).case_insensitive_column_map;
				}
				if (_3$$4) {
					ZEPHIR_CALL_SELF(&_4$$5, "caseinsensitivecolumnmap", &_5, 471, &columnMap, &attribute);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&attribute, &_4$$5);
				}
				ZEPHIR_OBS_NVAR(&attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0))) {
					if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
						ZEPHIR_INIT_NVAR(&_6$$7);
						object_init_ex(&_6$$7, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_7$$7);
						ZEPHIR_CONCAT_SVS(&_7$$7, "Column '", &attribute, "' doesn't make part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_6$$7, "__construct", &_8, 30, &_7$$7);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_6$$7, "phalcon/Mvc/Model.zep", 3150);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &attribute);
			}
			if (Z_TYPE_P(columns) == IS_ARRAY) {
				if (!(zephir_fast_in_array(&attributeField, columns))) {
					continue;
				}
			}
			ZEPHIR_OBS_NVAR(&value);
			if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
				zephir_array_update_zval(&data, &attributeField, &value, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&data, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attribute, &_0, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					_9$$14 = !(zephir_array_isset(&columnMap, &attribute));
					if (_9$$14) {
						_9$$14 = ZEPHIR_GLOBAL(orm).case_insensitive_column_map;
					}
					if (_9$$14) {
						ZEPHIR_CALL_SELF(&_10$$15, "caseinsensitivecolumnmap", &_5, 471, &columnMap, &attribute);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&attribute, &_10$$15);
					}
					ZEPHIR_OBS_NVAR(&attributeField);
					if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0))) {
						if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
							ZEPHIR_INIT_NVAR(&_11$$17);
							object_init_ex(&_11$$17, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_12$$17);
							ZEPHIR_CONCAT_SVS(&_12$$17, "Column '", &attribute, "' doesn't make part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_11$$17, "__construct", &_8, 30, &_12$$17);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_11$$17, "phalcon/Mvc/Model.zep", 3150);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &attribute);
				}
				if (Z_TYPE_P(columns) == IS_ARRAY) {
					if (!(zephir_fast_in_array(&attributeField, columns))) {
						continue;
					}
				}
				ZEPHIR_OBS_NVAR(&value);
				if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
					zephir_array_update_zval(&data, &attributeField, &value, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&data, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&attribute);
	RETURN_CTOR(&data);
}

/**
 * Updates a model instance. If the instance doesn't exist in the
 * persistence it will throw an exception. Returning true on success or
 * false otherwise.
 *
 *```php
 * // Updating a robot name
 * $robot = Robots::findFirst("id = 100");
 *
 * $robot->name = "Biomass";
 *
 * $robot->update();
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model, update)
{
	zval _3$$4;
	zval metaData, _0, _1$$3, _2$$3, _4$$4, _5$$4, _6$$4, _7$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_3$$4);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("dirtyState"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "getreadconnection", NULL, 482);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "has", NULL, 0, &metaData, &_2$$3);
		zephir_check_call_status();
		if (!(zephir_is_true(&_1$$3))) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_create_array(&_3$$4, 1, 0);
			ZEPHIR_INIT_VAR(&_4$$4);
			object_init_ex(&_4$$4, phalcon_messages_message_ce);
			ZEPHIR_INIT_VAR(&_5$$4);
			ZVAL_STRING(&_5$$4, "Record cannot be updated because it does not exist");
			ZVAL_NULL(&_6$$4);
			ZEPHIR_INIT_VAR(&_7$$4);
			ZVAL_STRING(&_7$$4, "InvalidUpdateAttempt");
			ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 6, &_5$$4, &_6$$4, &_7$$4);
			zephir_check_call_status();
			zephir_array_fast_append(&_3$$4, &_4$$4);
			zephir_update_property_zval(this_ptr, ZEND_STRL("errorMessages"), &_3$$4);
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "save", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Writes an attribute value by its name
 *
 *```php
 * $robot->writeAttribute("name", "Rosey");
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model, writeAttribute)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *attribute_param = NULL, *value, value_sub;
	zval attribute;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(attribute)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &attribute_param, &value);
	if (UNEXPECTED(Z_TYPE_P(attribute_param) != IS_STRING && Z_TYPE_P(attribute_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'attribute' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(attribute_param) == IS_STRING)) {
		zephir_get_strval(&attribute, attribute_param);
	} else {
		ZEPHIR_INIT_VAR(&attribute);
	}


	zephir_update_property_zval_zval(this_ptr, &attribute, value);
	ZEPHIR_MM_RESTORE();
}

/**
 * Reads "belongs to" relations and check the virtual foreign keys when
 * inserting or updating records to verify that inserted/updated values are
 * present in the related entity
 */
PHP_METHOD(Phalcon_Mvc_Model, checkForeignKeysRestrict)
{
	zend_string *_9$$7, *_30$$26;
	zend_ulong _8$$7, _29$$26;
	zend_bool error = 0, validateWithNulls = 0, _15$$3, _36$$22;
	zval conditions, _17$$3, _38$$22;
	zval manager, belongsTo, foreignKey, relation, position, bindParams, extraConditions, message, fields, referencedFields, field, referencedModel, value, allowNulls, _0, *_1, _2, _3$$5, _4$$3, _16$$3, _18$$3, *_6$$7, _7$$7, _10$$8, _11$$8, _12$$10, _13$$10, _14$$12, _19$$20, _20$$18, _21$$18, _24$$24, _25$$22, _37$$22, _39$$22, *_27$$26, _28$$26, _31$$27, _32$$27, _33$$29, _34$$29, _35$$31, _40$$39, _41$$37, _42$$37, _43$$42;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_22 = NULL, *_23 = NULL, *_26 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, action = 0, numberNull = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&belongsTo);
	ZVAL_UNDEF(&foreignKey);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&extraConditions);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&referencedFields);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&referencedModel);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&allowNulls);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_19$$20);
	ZVAL_UNDEF(&_20$$18);
	ZVAL_UNDEF(&_21$$18);
	ZVAL_UNDEF(&_24$$24);
	ZVAL_UNDEF(&_25$$22);
	ZVAL_UNDEF(&_37$$22);
	ZVAL_UNDEF(&_39$$22);
	ZVAL_UNDEF(&_28$$26);
	ZVAL_UNDEF(&_31$$27);
	ZVAL_UNDEF(&_32$$27);
	ZVAL_UNDEF(&_33$$29);
	ZVAL_UNDEF(&_34$$29);
	ZVAL_UNDEF(&_35$$31);
	ZVAL_UNDEF(&_40$$39);
	ZVAL_UNDEF(&_41$$37);
	ZVAL_UNDEF(&_42$$37);
	ZVAL_UNDEF(&_43$$42);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_38$$22);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&belongsTo, &manager, "getbelongsto", NULL, 0, this_ptr);
	zephir_check_call_status();
	error = 0;
	zephir_is_iterable(&belongsTo, 0, "phalcon/Mvc/Model.zep", 3383);
	if (Z_TYPE_P(&belongsTo) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&belongsTo), _1)
		{
			ZEPHIR_INIT_NVAR(&relation);
			ZVAL_COPY(&relation, _1);
			validateWithNulls = 0;
			ZEPHIR_CALL_METHOD(&foreignKey, &relation, "getforeignkey", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
				continue;
			}
			action = 1;
			if (zephir_array_isset_string(&foreignKey, SL("action"))) {
				ZEPHIR_OBS_NVAR(&_3$$5);
				zephir_array_fetch_string(&_3$$5, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 3274);
				action = zephir_get_intval(&_3$$5);
			}
			if (action != 1) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&_4$$3, &relation, "getreferencedmodel", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&referencedModel, &manager, "load", &_5, 0, &_4$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&conditions);
			array_init(&conditions);
			ZEPHIR_INIT_NVAR(&bindParams);
			array_init(&bindParams);
			numberNull = 0;
			ZEPHIR_CALL_METHOD(&fields, &relation, "getfields", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&fields) == IS_ARRAY) {
				zephir_is_iterable(&fields, 0, "phalcon/Mvc/Model.zep", 3317);
				if (Z_TYPE_P(&fields) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _8$$7, _9$$7, _6$$7)
					{
						ZEPHIR_INIT_NVAR(&position);
						if (_9$$7 != NULL) { 
							ZVAL_STR_COPY(&position, _9$$7);
						} else {
							ZVAL_LONG(&position, _8$$7);
						}
						ZEPHIR_INIT_NVAR(&field);
						ZVAL_COPY(&field, _6$$7);
						ZEPHIR_OBS_NVAR(&value);
						zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
						zephir_array_fetch(&_10$$8, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3309);
						ZEPHIR_INIT_NVAR(&_11$$8);
						ZEPHIR_CONCAT_SVSV(&_11$$8, "[", &_10$$8, "] = ?", &position);
						zephir_array_append(&conditions, &_11$$8, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3309);
						zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3310);
						if (Z_TYPE_P(&value) == IS_NULL) {
							numberNull++;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_7$$7, &fields, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_7$$7)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&position, &fields, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&field, &fields, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_OBS_NVAR(&value);
							zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
							zephir_array_fetch(&_12$$10, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3309);
							ZEPHIR_INIT_NVAR(&_13$$10);
							ZEPHIR_CONCAT_SVSV(&_13$$10, "[", &_12$$10, "] = ?", &position);
							zephir_array_append(&conditions, &_13$$10, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3309);
							zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3310);
							if (Z_TYPE_P(&value) == IS_NULL) {
								numberNull++;
							}
						ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&field);
				ZEPHIR_INIT_NVAR(&position);
				validateWithNulls = numberNull == zephir_fast_count_int(&fields);
			} else {
				ZEPHIR_OBS_NVAR(&value);
				zephir_fetch_property_zval(&value, this_ptr, &fields, PH_SILENT_CC);
				ZEPHIR_INIT_NVAR(&_14$$12);
				ZEPHIR_CONCAT_SVS(&_14$$12, "[", &referencedFields, "] = ?0");
				zephir_array_append(&conditions, &_14$$12, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3321);
				zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3322);
				if (Z_TYPE_P(&value) == IS_NULL) {
					validateWithNulls = 1;
				}
			}
			ZEPHIR_OBS_NVAR(&extraConditions);
			if (zephir_array_isset_string_fetch(&extraConditions, &foreignKey, SL("conditions"), 0)) {
				zephir_array_append(&conditions, &extraConditions, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3333);
			}
			if (validateWithNulls) {
				ZEPHIR_OBS_NVAR(&allowNulls);
				if (zephir_array_isset_string_fetch(&allowNulls, &foreignKey, SL("allowNulls"), 0)) {
					validateWithNulls = zephir_get_boolval(&allowNulls);
				} else {
					validateWithNulls = 0;
				}
			}
			_15$$3 = !validateWithNulls;
			if (_15$$3) {
				ZEPHIR_INIT_NVAR(&_17$$3);
				zephir_create_array(&_17$$3, 2, 0);
				ZEPHIR_INIT_NVAR(&_18$$3);
				zephir_fast_join_str(&_18$$3, SL(" AND "), &conditions);
				zephir_array_fast_append(&_17$$3, &_18$$3);
				zephir_array_update_string(&_17$$3, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_16$$3, &referencedModel, "count", NULL, 0, &_17$$3);
				zephir_check_call_status();
				_15$$3 = !zephir_is_true(&_16$$3);
			}
			if (_15$$3) {
				ZEPHIR_OBS_NVAR(&message);
				if (!(zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0))) {
					ZEPHIR_INIT_NVAR(&message);
					if (Z_TYPE_P(&fields) == IS_ARRAY) {
						ZEPHIR_INIT_NVAR(&_19$$20);
						zephir_fast_join_str(&_19$$20, SL(", "), &fields);
						ZEPHIR_CONCAT_SVS(&message, "Value of fields \"", &_19$$20, "\" does not exist on referenced table");
					} else {
						ZEPHIR_CONCAT_SVS(&message, "Value of field \"", &fields, "\" does not exist on referenced table");
					}
				}
				ZEPHIR_INIT_NVAR(&_20$$18);
				object_init_ex(&_20$$18, phalcon_messages_message_ce);
				ZEPHIR_INIT_NVAR(&_21$$18);
				ZVAL_STRING(&_21$$18, "ConstraintViolation");
				ZEPHIR_CALL_METHOD(NULL, &_20$$18, "__construct", &_22, 6, &message, &fields, &_21$$18);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_23, 0, &_20$$18);
				zephir_check_call_status();
				error = 1;
				break;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &belongsTo, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &belongsTo, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&relation, &belongsTo, "current", NULL, 0);
			zephir_check_call_status();
				validateWithNulls = 0;
				ZEPHIR_CALL_METHOD(&foreignKey, &relation, "getforeignkey", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
					continue;
				}
				action = 1;
				if (zephir_array_isset_string(&foreignKey, SL("action"))) {
					ZEPHIR_OBS_NVAR(&_24$$24);
					zephir_array_fetch_string(&_24$$24, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 3274);
					action = zephir_get_intval(&_24$$24);
				}
				if (action != 1) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&_25$$22, &relation, "getreferencedmodel", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedModel, &manager, "load", &_26, 0, &_25$$22);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&conditions);
				array_init(&conditions);
				ZEPHIR_INIT_NVAR(&bindParams);
				array_init(&bindParams);
				numberNull = 0;
				ZEPHIR_CALL_METHOD(&fields, &relation, "getfields", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&fields) == IS_ARRAY) {
					zephir_is_iterable(&fields, 0, "phalcon/Mvc/Model.zep", 3317);
					if (Z_TYPE_P(&fields) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _29$$26, _30$$26, _27$$26)
						{
							ZEPHIR_INIT_NVAR(&position);
							if (_30$$26 != NULL) { 
								ZVAL_STR_COPY(&position, _30$$26);
							} else {
								ZVAL_LONG(&position, _29$$26);
							}
							ZEPHIR_INIT_NVAR(&field);
							ZVAL_COPY(&field, _27$$26);
							ZEPHIR_OBS_NVAR(&value);
							zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
							zephir_array_fetch(&_31$$27, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3309);
							ZEPHIR_INIT_NVAR(&_32$$27);
							ZEPHIR_CONCAT_SVSV(&_32$$27, "[", &_31$$27, "] = ?", &position);
							zephir_array_append(&conditions, &_32$$27, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3309);
							zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3310);
							if (Z_TYPE_P(&value) == IS_NULL) {
								numberNull++;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_28$$26, &fields, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_28$$26)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&position, &fields, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&field, &fields, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_OBS_NVAR(&value);
								zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
								zephir_array_fetch(&_33$$29, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3309);
								ZEPHIR_INIT_NVAR(&_34$$29);
								ZEPHIR_CONCAT_SVSV(&_34$$29, "[", &_33$$29, "] = ?", &position);
								zephir_array_append(&conditions, &_34$$29, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3309);
								zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3310);
								if (Z_TYPE_P(&value) == IS_NULL) {
									numberNull++;
								}
							ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&field);
					ZEPHIR_INIT_NVAR(&position);
					validateWithNulls = numberNull == zephir_fast_count_int(&fields);
				} else {
					ZEPHIR_OBS_NVAR(&value);
					zephir_fetch_property_zval(&value, this_ptr, &fields, PH_SILENT_CC);
					ZEPHIR_INIT_NVAR(&_35$$31);
					ZEPHIR_CONCAT_SVS(&_35$$31, "[", &referencedFields, "] = ?0");
					zephir_array_append(&conditions, &_35$$31, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3321);
					zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3322);
					if (Z_TYPE_P(&value) == IS_NULL) {
						validateWithNulls = 1;
					}
				}
				ZEPHIR_OBS_NVAR(&extraConditions);
				if (zephir_array_isset_string_fetch(&extraConditions, &foreignKey, SL("conditions"), 0)) {
					zephir_array_append(&conditions, &extraConditions, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3333);
				}
				if (validateWithNulls) {
					ZEPHIR_OBS_NVAR(&allowNulls);
					if (zephir_array_isset_string_fetch(&allowNulls, &foreignKey, SL("allowNulls"), 0)) {
						validateWithNulls = zephir_get_boolval(&allowNulls);
					} else {
						validateWithNulls = 0;
					}
				}
				_36$$22 = !validateWithNulls;
				if (_36$$22) {
					ZEPHIR_INIT_NVAR(&_38$$22);
					zephir_create_array(&_38$$22, 2, 0);
					ZEPHIR_INIT_NVAR(&_39$$22);
					zephir_fast_join_str(&_39$$22, SL(" AND "), &conditions);
					zephir_array_fast_append(&_38$$22, &_39$$22);
					zephir_array_update_string(&_38$$22, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_37$$22, &referencedModel, "count", NULL, 0, &_38$$22);
					zephir_check_call_status();
					_36$$22 = !zephir_is_true(&_37$$22);
				}
				if (_36$$22) {
					ZEPHIR_OBS_NVAR(&message);
					if (!(zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0))) {
						ZEPHIR_INIT_NVAR(&message);
						if (Z_TYPE_P(&fields) == IS_ARRAY) {
							ZEPHIR_INIT_NVAR(&_40$$39);
							zephir_fast_join_str(&_40$$39, SL(", "), &fields);
							ZEPHIR_CONCAT_SVS(&message, "Value of fields \"", &_40$$39, "\" does not exist on referenced table");
						} else {
							ZEPHIR_CONCAT_SVS(&message, "Value of field \"", &fields, "\" does not exist on referenced table");
						}
					}
					ZEPHIR_INIT_NVAR(&_41$$37);
					object_init_ex(&_41$$37, phalcon_messages_message_ce);
					ZEPHIR_INIT_NVAR(&_42$$37);
					ZVAL_STRING(&_42$$37, "ConstraintViolation");
					ZEPHIR_CALL_METHOD(NULL, &_41$$37, "__construct", &_22, 6, &message, &fields, &_42$$37);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_23, 0, &_41$$37);
					zephir_check_call_status();
					error = 1;
					break;
				}
			ZEPHIR_CALL_METHOD(NULL, &belongsTo, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&relation);
	if (error) {
		if (ZEPHIR_GLOBAL(orm).events) {
			ZEPHIR_INIT_VAR(&_43$$42);
			ZVAL_STRING(&_43$$42, "onValidationFails");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_43$$42);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "canceloperation", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

/**
 * Reads both "hasMany" and "hasOne" relations and checks the virtual
 * foreign keys (cascade) when deleting records
 */
PHP_METHOD(Phalcon_Mvc_Model, checkForeignKeysReverseCascade)
{
	zend_bool _3$$3, _7$$9;
	zval manager, relations, relation, foreignKey, related, _0, *_1, _2, _4$$5, _6$$7, _8$$11, _10$$13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, action = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&foreignKey);
	ZVAL_UNDEF(&related);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_10$$13);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&relations, &manager, "gethasoneandhasmany", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(&relations, 0, "phalcon/Mvc/Model.zep", 3459);
	if (Z_TYPE_P(&relations) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relations), _1)
		{
			ZEPHIR_INIT_NVAR(&relation);
			ZVAL_COPY(&relation, _1);
			ZEPHIR_CALL_METHOD(&foreignKey, &relation, "getforeignkey", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
				continue;
			}
			action = 0;
			_3$$3 = Z_TYPE_P(&foreignKey) == IS_ARRAY;
			if (_3$$3) {
				_3$$3 = zephir_array_isset_string(&foreignKey, SL("action"));
			}
			if (_3$$3) {
				ZEPHIR_OBS_NVAR(&_4$$5);
				zephir_array_fetch_string(&_4$$5, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 3433);
				action = zephir_get_intval(&_4$$5);
			}
			if (action != 2) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&related, &manager, "getrelationrecords", &_5, 0, &relation, this_ptr);
			zephir_check_call_status();
			if (zephir_is_true(&related)) {
				ZEPHIR_CALL_METHOD(&_6$$7, &related, "delete", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_6$$7)) {
					RETURN_MM_BOOL(0);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &relations, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &relations, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&relation, &relations, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&foreignKey, &relation, "getforeignkey", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
					continue;
				}
				action = 0;
				_7$$9 = Z_TYPE_P(&foreignKey) == IS_ARRAY;
				if (_7$$9) {
					_7$$9 = zephir_array_isset_string(&foreignKey, SL("action"));
				}
				if (_7$$9) {
					ZEPHIR_OBS_NVAR(&_8$$11);
					zephir_array_fetch_string(&_8$$11, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 3433);
					action = zephir_get_intval(&_8$$11);
				}
				if (action != 2) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&related, &manager, "getrelationrecords", &_9, 0, &relation, this_ptr);
				zephir_check_call_status();
				if (zephir_is_true(&related)) {
					ZEPHIR_CALL_METHOD(&_10$$13, &related, "delete", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_FALSE_IDENTICAL(&_10$$13)) {
						RETURN_MM_BOOL(0);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &relations, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&relation);
	RETURN_MM_BOOL(1);
}

/**
 * Reads both "hasMany" and "hasOne" relations and checks the virtual
 * foreign keys (restrict) when deleting records
 */
PHP_METHOD(Phalcon_Mvc_Model, checkForeignKeysReverseRestrict)
{
	zval manager, relations, foreignKey, relation, relationClass, fields, message, _0, *_1, _2, _5$$3, _6$$3, _7$$3, _4$$5, _9$$7, _10$$7, _15$$9, _16$$9, _17$$9, _14$$11, _19$$13, _20$$13, _21$$16;
	zend_bool error = 0, _3$$3, _13$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_11 = NULL, *_12 = NULL, *_18 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, action = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&foreignKey);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&relationClass);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$16);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&relations, &manager, "gethasoneandhasmany", NULL, 0, this_ptr);
	zephir_check_call_status();
	error = 0;
	zephir_is_iterable(&relations, 0, "phalcon/Mvc/Model.zep", 3545);
	if (Z_TYPE_P(&relations) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relations), _1)
		{
			ZEPHIR_INIT_NVAR(&relation);
			ZVAL_COPY(&relation, _1);
			ZEPHIR_CALL_METHOD(&foreignKey, &relation, "getforeignkey", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
				continue;
			}
			action = 1;
			_3$$3 = Z_TYPE_P(&foreignKey) == IS_ARRAY;
			if (_3$$3) {
				_3$$3 = zephir_array_isset_string(&foreignKey, SL("action"));
			}
			if (_3$$3) {
				ZEPHIR_OBS_NVAR(&_4$$5);
				zephir_array_fetch_string(&_4$$5, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 3504);
				action = zephir_get_intval(&_4$$5);
			}
			if (action != 1) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&relationClass, &relation, "getreferencedmodel", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&fields, &relation, "getfields", NULL, 0);
			zephir_check_call_status();
			ZVAL_NULL(&_6$$3);
			ZEPHIR_INIT_NVAR(&_7$$3);
			ZVAL_STRING(&_7$$3, "count");
			ZEPHIR_CALL_METHOD(&_5$$3, &manager, "getrelationrecords", &_8, 0, &relation, this_ptr, &_6$$3, &_7$$3);
			zephir_check_call_status();
			if (zephir_is_true(&_5$$3)) {
				ZEPHIR_OBS_NVAR(&message);
				if (!(zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0))) {
					ZEPHIR_INIT_NVAR(&message);
					ZEPHIR_CONCAT_SV(&message, "Record is referenced by model ", &relationClass);
				}
				ZEPHIR_INIT_NVAR(&_9$$7);
				object_init_ex(&_9$$7, phalcon_messages_message_ce);
				ZEPHIR_INIT_NVAR(&_10$$7);
				ZVAL_STRING(&_10$$7, "ConstraintViolation");
				ZEPHIR_CALL_METHOD(NULL, &_9$$7, "__construct", &_11, 6, &message, &fields, &_10$$7);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_12, 0, &_9$$7);
				zephir_check_call_status();
				error = 1;
				break;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &relations, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &relations, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&relation, &relations, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&foreignKey, &relation, "getforeignkey", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
					continue;
				}
				action = 1;
				_13$$9 = Z_TYPE_P(&foreignKey) == IS_ARRAY;
				if (_13$$9) {
					_13$$9 = zephir_array_isset_string(&foreignKey, SL("action"));
				}
				if (_13$$9) {
					ZEPHIR_OBS_NVAR(&_14$$11);
					zephir_array_fetch_string(&_14$$11, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 3504);
					action = zephir_get_intval(&_14$$11);
				}
				if (action != 1) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&relationClass, &relation, "getreferencedmodel", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&fields, &relation, "getfields", NULL, 0);
				zephir_check_call_status();
				ZVAL_NULL(&_16$$9);
				ZEPHIR_INIT_NVAR(&_17$$9);
				ZVAL_STRING(&_17$$9, "count");
				ZEPHIR_CALL_METHOD(&_15$$9, &manager, "getrelationrecords", &_18, 0, &relation, this_ptr, &_16$$9, &_17$$9);
				zephir_check_call_status();
				if (zephir_is_true(&_15$$9)) {
					ZEPHIR_OBS_NVAR(&message);
					if (!(zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0))) {
						ZEPHIR_INIT_NVAR(&message);
						ZEPHIR_CONCAT_SV(&message, "Record is referenced by model ", &relationClass);
					}
					ZEPHIR_INIT_NVAR(&_19$$13);
					object_init_ex(&_19$$13, phalcon_messages_message_ce);
					ZEPHIR_INIT_NVAR(&_20$$13);
					ZVAL_STRING(&_20$$13, "ConstraintViolation");
					ZEPHIR_CALL_METHOD(NULL, &_19$$13, "__construct", &_11, 6, &message, &fields, &_20$$13);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_12, 0, &_19$$13);
					zephir_check_call_status();
					error = 1;
					break;
				}
			ZEPHIR_CALL_METHOD(NULL, &relations, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&relation);
	if (error) {
		if (ZEPHIR_GLOBAL(orm).events) {
			ZEPHIR_INIT_VAR(&_21$$16);
			ZVAL_STRING(&_21$$16, "onValidationFails");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_21$$16);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "canceloperation", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

/**
 * Sends a pre-build INSERT SQL statement to the relational database system
 *
 * @param string|array table
 * @param bool|string identityField
 */
PHP_METHOD(Phalcon_Mvc_Model, doLowInsert)
{
	zend_string *_52$$56;
	zend_ulong _51$$56;
	zend_bool useExplicitIdentity = 0, _45, _6$$11, _22$$26, _39$$40, _54$$56;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_10 = NULL, *_11 = NULL, *_17 = NULL, *_19 = NULL, *_26 = NULL, *_27 = NULL, *_33 = NULL, *_35 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *metaData, metaData_sub, *connection, connection_sub, *table = NULL, table_sub, *identityField, identityField_sub, __$null, attributeField, attributes, automaticAttributes, bindDataTypes, bindSkip, bindType, bindTypes, columnMap, defaultValue, defaultValues, field, fields, lastInsertedId, manager, sequenceName, schema, snapshot, source, success, unsetDefaultValues, value, values, _0, *_1, _2, _3$$7, _4$$7, _7$$12, _8$$12, _9$$12, _12$$15, _13$$15, _14$$17, _15$$17, _16$$17, _18$$17, _20$$22, _21$$22, _23$$27, _24$$27, _25$$27, _28$$30, _29$$30, _30$$32, _31$$32, _32$$32, _34$$32, _36$$35, _37$$38, _38$$38, _40$$45, _41$$45, _42$$48, _43$$48, _44$$48, _46$$49, _47$$55, _48$$55, *_49$$56, _50$$56, _53$$56;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData_sub);
	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&identityField_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&automaticAttributes);
	ZVAL_UNDEF(&bindDataTypes);
	ZVAL_UNDEF(&bindSkip);
	ZVAL_UNDEF(&bindType);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&defaultValues);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&lastInsertedId);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&sequenceName);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&unsetDefaultValues);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_7$$12);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_9$$12);
	ZVAL_UNDEF(&_12$$15);
	ZVAL_UNDEF(&_13$$15);
	ZVAL_UNDEF(&_14$$17);
	ZVAL_UNDEF(&_15$$17);
	ZVAL_UNDEF(&_16$$17);
	ZVAL_UNDEF(&_18$$17);
	ZVAL_UNDEF(&_20$$22);
	ZVAL_UNDEF(&_21$$22);
	ZVAL_UNDEF(&_23$$27);
	ZVAL_UNDEF(&_24$$27);
	ZVAL_UNDEF(&_25$$27);
	ZVAL_UNDEF(&_28$$30);
	ZVAL_UNDEF(&_29$$30);
	ZVAL_UNDEF(&_30$$32);
	ZVAL_UNDEF(&_31$$32);
	ZVAL_UNDEF(&_32$$32);
	ZVAL_UNDEF(&_34$$32);
	ZVAL_UNDEF(&_36$$35);
	ZVAL_UNDEF(&_37$$38);
	ZVAL_UNDEF(&_38$$38);
	ZVAL_UNDEF(&_40$$45);
	ZVAL_UNDEF(&_41$$45);
	ZVAL_UNDEF(&_42$$48);
	ZVAL_UNDEF(&_43$$48);
	ZVAL_UNDEF(&_44$$48);
	ZVAL_UNDEF(&_46$$49);
	ZVAL_UNDEF(&_47$$55);
	ZVAL_UNDEF(&_48$$55);
	ZVAL_UNDEF(&_50$$56);
	ZVAL_UNDEF(&_53$$56);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(metaData, phalcon_mvc_model_metadatainterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(connection, phalcon_db_adapter_adapterinterface_ce)
		Z_PARAM_ZVAL(table)
		Z_PARAM_ZVAL(identityField)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &metaData, &connection, &table, &identityField);
	ZEPHIR_SEPARATE_PARAM(table);


	ZEPHIR_INIT_VAR(&bindSkip);
	ZVAL_LONG(&bindSkip, 1024);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_INIT_VAR(&fields);
	array_init(&fields);
	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	ZEPHIR_INIT_VAR(&snapshot);
	array_init(&snapshot);
	ZEPHIR_INIT_VAR(&bindTypes);
	array_init(&bindTypes);
	ZEPHIR_INIT_VAR(&unsetDefaultValues);
	array_init(&unsetDefaultValues);
	ZEPHIR_CALL_METHOD(&attributes, metaData, "getattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&bindDataTypes, metaData, "getbindtypes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&automaticAttributes, metaData, "getautomaticcreateattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&defaultValues, metaData, "getdefaultvalues", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).column_renaming) {
		ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, 0, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&columnMap);
		ZVAL_NULL(&columnMap);
	}
	zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model.zep", 3667);
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _1)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _1);
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
					ZEPHIR_INIT_NVAR(&_3$$7);
					object_init_ex(&_3$$7, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_NVAR(&_4$$7);
					ZEPHIR_CONCAT_SVS(&_4$$7, "Column '", &field, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, &_3$$7, "__construct", &_5, 30, &_4$$7);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_3$$7, "phalcon/Mvc/Model.zep", 3601);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &field);
			}
			if (!(zephir_array_isset(&automaticAttributes, &attributeField))) {
				if (!ZEPHIR_IS_EQUAL(&field, identityField)) {
					ZEPHIR_OBS_NVAR(&value);
					if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
						_6$$11 = Z_TYPE_P(&value) == IS_NULL;
						if (_6$$11) {
							_6$$11 = zephir_array_isset(&defaultValues, &field);
						}
						if (_6$$11) {
							zephir_array_fetch(&_7$$12, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3618);
							zephir_array_update_zval(&snapshot, &attributeField, &_7$$12, PH_COPY | PH_SEPARATE);
							zephir_array_fetch(&_8$$12, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3619);
							zephir_array_update_zval(&unsetDefaultValues, &attributeField, &_8$$12, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(&_9$$12, connection, "supportsdefaultvalue", &_10, 0);
							zephir_check_call_status();
							if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_9$$12))) {
								continue;
							}
							ZEPHIR_CALL_METHOD(&value, connection, "getdefaultvalue", &_11, 0);
							zephir_check_call_status();
						} else {
							zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
						}
						ZEPHIR_OBS_NVAR(&bindType);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0)))) {
							ZEPHIR_INIT_NVAR(&_12$$15);
							object_init_ex(&_12$$15, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_13$$15);
							ZEPHIR_CONCAT_SVS(&_13$$15, "Column '", &field, "' have not defined a bind data type");
							ZEPHIR_CALL_METHOD(NULL, &_12$$15, "__construct", &_5, 30, &_13$$15);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_12$$15, "phalcon/Mvc/Model.zep", 3636);
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3639);
						zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3640);
						zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3641);
					} else {
						if (zephir_array_isset(&defaultValues, &field)) {
							zephir_array_fetch(&_14$$17, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3644);
							zephir_array_update_zval(&snapshot, &attributeField, &_14$$17, PH_COPY | PH_SEPARATE);
							zephir_array_fetch(&_15$$17, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3645);
							zephir_array_update_zval(&unsetDefaultValues, &attributeField, &_15$$17, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(&_16$$17, connection, "supportsdefaultvalue", &_17, 0);
							zephir_check_call_status();
							if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_16$$17))) {
								continue;
							}
							ZEPHIR_CALL_METHOD(&_18$$17, connection, "getdefaultvalue", &_19, 0);
							zephir_check_call_status();
							zephir_array_append(&values, &_18$$17, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3651);
						} else {
							zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3653);
							zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
						}
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3657);
						zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3658);
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &attributes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, &attributes, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
						ZEPHIR_INIT_NVAR(&_20$$22);
						object_init_ex(&_20$$22, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_21$$22);
						ZEPHIR_CONCAT_SVS(&_21$$22, "Column '", &field, "' isn't part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_20$$22, "__construct", &_5, 30, &_21$$22);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_20$$22, "phalcon/Mvc/Model.zep", 3601);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &field);
				}
				if (!(zephir_array_isset(&automaticAttributes, &attributeField))) {
					if (!ZEPHIR_IS_EQUAL(&field, identityField)) {
						ZEPHIR_OBS_NVAR(&value);
						if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
							_22$$26 = Z_TYPE_P(&value) == IS_NULL;
							if (_22$$26) {
								_22$$26 = zephir_array_isset(&defaultValues, &field);
							}
							if (_22$$26) {
								zephir_array_fetch(&_23$$27, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3618);
								zephir_array_update_zval(&snapshot, &attributeField, &_23$$27, PH_COPY | PH_SEPARATE);
								zephir_array_fetch(&_24$$27, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3619);
								zephir_array_update_zval(&unsetDefaultValues, &attributeField, &_24$$27, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(&_25$$27, connection, "supportsdefaultvalue", &_26, 0);
								zephir_check_call_status();
								if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_25$$27))) {
									continue;
								}
								ZEPHIR_CALL_METHOD(&value, connection, "getdefaultvalue", &_27, 0);
								zephir_check_call_status();
							} else {
								zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
							}
							ZEPHIR_OBS_NVAR(&bindType);
							if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0)))) {
								ZEPHIR_INIT_NVAR(&_28$$30);
								object_init_ex(&_28$$30, phalcon_mvc_model_exception_ce);
								ZEPHIR_INIT_NVAR(&_29$$30);
								ZEPHIR_CONCAT_SVS(&_29$$30, "Column '", &field, "' have not defined a bind data type");
								ZEPHIR_CALL_METHOD(NULL, &_28$$30, "__construct", &_5, 30, &_29$$30);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_28$$30, "phalcon/Mvc/Model.zep", 3636);
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3639);
							zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3640);
							zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3641);
						} else {
							if (zephir_array_isset(&defaultValues, &field)) {
								zephir_array_fetch(&_30$$32, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3644);
								zephir_array_update_zval(&snapshot, &attributeField, &_30$$32, PH_COPY | PH_SEPARATE);
								zephir_array_fetch(&_31$$32, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3645);
								zephir_array_update_zval(&unsetDefaultValues, &attributeField, &_31$$32, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(&_32$$32, connection, "supportsdefaultvalue", &_33, 0);
								zephir_check_call_status();
								if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_32$$32))) {
									continue;
								}
								ZEPHIR_CALL_METHOD(&_34$$32, connection, "getdefaultvalue", &_35, 0);
								zephir_check_call_status();
								zephir_array_append(&values, &_34$$32, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3651);
							} else {
								zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3653);
								zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
							}
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3657);
							zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3658);
						}
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&field);
	if (!ZEPHIR_IS_FALSE_IDENTICAL(identityField)) {
		ZEPHIR_CALL_METHOD(&defaultValue, connection, "getdefaultidvalue", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_36$$35, connection, "useexplicitidvalue", NULL, 0);
		zephir_check_call_status();
		useExplicitIdentity = zephir_get_boolval(&_36$$35);
		if (useExplicitIdentity) {
			zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3677);
		}
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&attributeField);
			if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, identityField, 0)))) {
				ZEPHIR_INIT_VAR(&_37$$38);
				object_init_ex(&_37$$38, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(&_38$$38);
				ZEPHIR_CONCAT_SVS(&_38$$38, "Identity column '", identityField, "' isn't part of the column map");
				ZEPHIR_CALL_METHOD(NULL, &_37$$38, "__construct", &_5, 30, &_38$$38);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_37$$38, "phalcon/Mvc/Model.zep", 3687);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(&attributeField, identityField);
		}
		ZEPHIR_OBS_NVAR(&value);
		if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
			_39$$40 = Z_TYPE_P(&value) == IS_NULL;
			if (!(_39$$40)) {
				_39$$40 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
			}
			if (_39$$40) {
				if (useExplicitIdentity) {
					zephir_array_append(&values, &defaultValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3699);
					zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3699);
				}
			} else {
				if (!(useExplicitIdentity)) {
					zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3707);
				}
				ZEPHIR_OBS_NVAR(&bindType);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, identityField, 0)))) {
					ZEPHIR_INIT_VAR(&_40$$45);
					object_init_ex(&_40$$45, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_VAR(&_41$$45);
					ZEPHIR_CONCAT_SVS(&_41$$45, "Identity column '", identityField, "' isn\'t part of the table columns");
					ZEPHIR_CALL_METHOD(NULL, &_40$$45, "__construct", &_5, 30, &_41$$45);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_40$$45, "phalcon/Mvc/Model.zep", 3716);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3719);
				zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3720);
			}
		} else {
			if (useExplicitIdentity) {
				zephir_array_append(&values, &defaultValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3724);
				zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3725);
			}
		}
	}
	if (Z_TYPE_P(table) == IS_ARRAY) {
		zephir_array_fetch_long(&_42$$48, table, 0, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3734);
		zephir_array_fetch_long(&_43$$48, table, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3734);
		ZEPHIR_INIT_VAR(&_44$$48);
		ZEPHIR_CONCAT_VSV(&_44$$48, &_42$$48, ".", &_43$$48);
		ZEPHIR_CPY_WRT(table, &_44$$48);
	}
	ZEPHIR_CALL_METHOD(&success, connection, "insert", NULL, 0, table, &values, &fields, &bindTypes);
	zephir_check_call_status();
	_45 = zephir_is_true(&success);
	if (_45) {
		_45 = !ZEPHIR_IS_FALSE_IDENTICAL(identityField);
	}
	if (_45) {
		ZEPHIR_INIT_VAR(&sequenceName);
		ZVAL_NULL(&sequenceName);
		ZEPHIR_CALL_METHOD(&_46$$49, connection, "supportsequences", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_46$$49)) {
			if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("getsequencename")) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(&sequenceName, this_ptr, "getsequencename", NULL, 0);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 475);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 474);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&sequenceName);
				if (ZEPHIR_IS_EMPTY(&schema)) {
					ZEPHIR_CONCAT_VSVS(&sequenceName, &source, "_", identityField, "_seq");
				} else {
					ZEPHIR_CONCAT_VSVSVS(&sequenceName, &schema, ".", &source, "_", identityField, "_seq");
				}
			}
		}
		ZEPHIR_CALL_METHOD(&lastInsertedId, connection, "lastinsertid", NULL, 0, &sequenceName);
		zephir_check_call_status();
		if (UNEXPECTED(ZEPHIR_GLOBAL(orm).cast_last_insert_id_to_int)) {
			ZVAL_LONG(&_47$$55, 10);
			ZEPHIR_CALL_FUNCTION(&_48$$55, "intval", NULL, 50, &lastInsertedId, &_47$$55);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&lastInsertedId, &_48$$55);
		}
		zephir_update_property_zval_zval(this_ptr, &attributeField, &lastInsertedId);
		zephir_array_update_zval(&snapshot, &attributeField, &lastInsertedId, PH_COPY | PH_SEPARATE);
		zephir_update_property_zval(this_ptr, ZEND_STRL("uniqueParams"), &__$null);
	}
	if (zephir_is_true(&success)) {
		zephir_is_iterable(&unsetDefaultValues, 0, "phalcon/Mvc/Model.zep", 3795);
		if (Z_TYPE_P(&unsetDefaultValues) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&unsetDefaultValues), _51$$56, _52$$56, _49$$56)
			{
				ZEPHIR_INIT_NVAR(&attributeField);
				if (_52$$56 != NULL) { 
					ZVAL_STR_COPY(&attributeField, _52$$56);
				} else {
					ZVAL_LONG(&attributeField, _51$$56);
				}
				ZEPHIR_INIT_NVAR(&defaultValue);
				ZVAL_COPY(&defaultValue, _49$$56);
				zephir_update_property_zval_zval(this_ptr, &attributeField, &defaultValue);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &unsetDefaultValues, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_50$$56, &unsetDefaultValues, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_50$$56)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&attributeField, &unsetDefaultValues, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&defaultValue, &unsetDefaultValues, "current", NULL, 0);
				zephir_check_call_status();
					zephir_update_property_zval_zval(this_ptr, &attributeField, &defaultValue);
				ZEPHIR_CALL_METHOD(NULL, &unsetDefaultValues, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&defaultValue);
		ZEPHIR_INIT_NVAR(&attributeField);
		ZEPHIR_CALL_METHOD(&_53$$56, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		_54$$56 = zephir_is_true(&_53$$56);
		if (_54$$56) {
			_54$$56 = ZEPHIR_GLOBAL(orm).update_snapshot_on_save;
		}
		if (_54$$56) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("snapshot"), &snapshot);
		}
	}
	RETURN_CCTOR(&success);
}

/**
 * Sends a pre-build UPDATE SQL statement to the relational database system
 *
 * @param string|array table
 */
PHP_METHOD(Phalcon_Mvc_Model, doLowUpdate)
{
	zval _18$$28, _19$$28, _32$$53, _33$$53;
	zval _43;
	zend_bool changed = 0, useDynamicUpdate = 0, _44, _45, _11$$22, _13$$22, _26$$47, _28$$47;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *metaData, metaData_sub, *connection, connection_sub, *table = NULL, table_sub, __$null, automaticAttributes, attributeField, bindSkip, bindDataTypes, bindType, bindTypes, columnMap, dataType, dataTypes, field, fields, manager, nonPrimary, newSnapshot, success, primaryKeys, snapshot, snapshotValue, uniqueKey, uniqueParams, uniqueTypes, value, values, _0, _1, *_2, _3, _4$$10, _5$$10, _7$$13, _8$$13, _9$$23, _10$$23, _12$$24, _14$$25, _15$$27, _17$$27, _20$$35, _21$$35, _22$$38, _23$$38, _24$$48, _25$$48, _27$$49, _29$$50, _30$$52, _31$$52, *_34$$59, _35$$59, _36$$63, _37$$63, _38$$69, _39$$69, _40$$73, _41$$73, _42$$73, _46$$75, _47$$76;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData_sub);
	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&table_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&automaticAttributes);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&bindSkip);
	ZVAL_UNDEF(&bindDataTypes);
	ZVAL_UNDEF(&bindType);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&dataType);
	ZVAL_UNDEF(&dataTypes);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&nonPrimary);
	ZVAL_UNDEF(&newSnapshot);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&primaryKeys);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&snapshotValue);
	ZVAL_UNDEF(&uniqueKey);
	ZVAL_UNDEF(&uniqueParams);
	ZVAL_UNDEF(&uniqueTypes);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$10);
	ZVAL_UNDEF(&_5$$10);
	ZVAL_UNDEF(&_7$$13);
	ZVAL_UNDEF(&_8$$13);
	ZVAL_UNDEF(&_9$$23);
	ZVAL_UNDEF(&_10$$23);
	ZVAL_UNDEF(&_12$$24);
	ZVAL_UNDEF(&_14$$25);
	ZVAL_UNDEF(&_15$$27);
	ZVAL_UNDEF(&_17$$27);
	ZVAL_UNDEF(&_20$$35);
	ZVAL_UNDEF(&_21$$35);
	ZVAL_UNDEF(&_22$$38);
	ZVAL_UNDEF(&_23$$38);
	ZVAL_UNDEF(&_24$$48);
	ZVAL_UNDEF(&_25$$48);
	ZVAL_UNDEF(&_27$$49);
	ZVAL_UNDEF(&_29$$50);
	ZVAL_UNDEF(&_30$$52);
	ZVAL_UNDEF(&_31$$52);
	ZVAL_UNDEF(&_35$$59);
	ZVAL_UNDEF(&_36$$63);
	ZVAL_UNDEF(&_37$$63);
	ZVAL_UNDEF(&_38$$69);
	ZVAL_UNDEF(&_39$$69);
	ZVAL_UNDEF(&_40$$73);
	ZVAL_UNDEF(&_41$$73);
	ZVAL_UNDEF(&_42$$73);
	ZVAL_UNDEF(&_46$$75);
	ZVAL_UNDEF(&_47$$76);
	ZVAL_UNDEF(&_43);
	ZVAL_UNDEF(&_18$$28);
	ZVAL_UNDEF(&_19$$28);
	ZVAL_UNDEF(&_32$$53);
	ZVAL_UNDEF(&_33$$53);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(metaData, phalcon_mvc_model_metadatainterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(connection, phalcon_db_adapter_adapterinterface_ce)
		Z_PARAM_ZVAL(table)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &metaData, &connection, &table);
	ZEPHIR_SEPARATE_PARAM(table);


	ZEPHIR_INIT_VAR(&bindSkip);
	ZVAL_LONG(&bindSkip, 1024);
	ZEPHIR_INIT_VAR(&fields);
	array_init(&fields);
	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	ZEPHIR_INIT_VAR(&bindTypes);
	array_init(&bindTypes);
	ZEPHIR_INIT_VAR(&newSnapshot);
	array_init(&newSnapshot);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&_1, &manager, "isusingdynamicupdate", NULL, 0, this_ptr);
	zephir_check_call_status();
	useDynamicUpdate = zephir_get_boolval(&_1);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("snapshot"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&snapshot, &_0);
	if (useDynamicUpdate) {
		if (Z_TYPE_P(&snapshot) != IS_ARRAY) {
			useDynamicUpdate = 0;
		}
	}
	ZEPHIR_CALL_METHOD(&dataTypes, metaData, "getdatatypes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&bindDataTypes, metaData, "getbindtypes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&nonPrimary, metaData, "getnonprimarykeyattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&automaticAttributes, metaData, "getautomaticupdateattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).column_renaming) {
		ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, 0, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&columnMap);
		ZVAL_NULL(&columnMap);
	}
	zephir_is_iterable(&nonPrimary, 0, "phalcon/Mvc/Model.zep", 3981);
	if (Z_TYPE_P(&nonPrimary) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&nonPrimary), _2)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _2);
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
					if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
						ZEPHIR_INIT_NVAR(&_4$$10);
						object_init_ex(&_4$$10, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_5$$10);
						ZEPHIR_CONCAT_SVS(&_5$$10, "Column '", &field, "' isn't part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_4$$10, "__construct", &_6, 30, &_5$$10);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_4$$10, "phalcon/Mvc/Model.zep", 3859);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &field);
			}
			if (!(zephir_array_isset(&automaticAttributes, &attributeField))) {
				ZEPHIR_OBS_NVAR(&bindType);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0)))) {
					ZEPHIR_INIT_NVAR(&_7$$13);
					object_init_ex(&_7$$13, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_NVAR(&_8$$13);
					ZEPHIR_CONCAT_SVS(&_8$$13, "Column '", &field, "' have not defined a bind data type");
					ZEPHIR_CALL_METHOD(NULL, &_7$$13, "__construct", &_6, 30, &_8$$13);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_7$$13, "phalcon/Mvc/Model.zep", 3873);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&value);
				if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
					if (!(useDynamicUpdate)) {
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3885);
						zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3886);
						zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3887);
					} else {
						ZEPHIR_OBS_NVAR(&snapshotValue);
						if (!(zephir_array_isset_fetch(&snapshotValue, &snapshot, &attributeField, 0))) {
							changed = 1;
						} else {
							if (Z_TYPE_P(&value) == IS_NULL) {
								changed = Z_TYPE_P(&snapshotValue) != IS_NULL;
							} else {
								if (Z_TYPE_P(&snapshotValue) == IS_NULL) {
									changed = 1;
								} else {
									ZEPHIR_OBS_NVAR(&dataType);
									if (UNEXPECTED(!(zephir_array_isset_fetch(&dataType, &dataTypes, &field, 0)))) {
										ZEPHIR_INIT_NVAR(&_9$$23);
										object_init_ex(&_9$$23, phalcon_mvc_model_exception_ce);
										ZEPHIR_INIT_NVAR(&_10$$23);
										ZEPHIR_CONCAT_SVS(&_10$$23, "Column '", &field, "' have not defined a data type");
										ZEPHIR_CALL_METHOD(NULL, &_9$$23, "__construct", &_6, 30, &_10$$23);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_9$$23, "phalcon/Mvc/Model.zep", 3912);
										ZEPHIR_MM_RESTORE();
										return;
									}
									_11$$22 = Z_TYPE_P(&snapshotValue) == IS_OBJECT;
									if (_11$$22) {
										_11$$22 = zephir_instance_of_ev(&snapshotValue, phalcon_db_rawvalue_ce);
									}
									if (_11$$22) {
										ZEPHIR_CALL_METHOD(&_12$$24, &snapshotValue, "getvalue", NULL, 0);
										zephir_check_call_status();
										ZEPHIR_CPY_WRT(&snapshotValue, &_12$$24);
									}
									_13$$22 = Z_TYPE_P(&value) == IS_OBJECT;
									if (_13$$22) {
										_13$$22 = zephir_instance_of_ev(&value, phalcon_db_rawvalue_ce);
									}
									if (_13$$22) {
										ZEPHIR_CALL_METHOD(&_14$$25, &value, "getvalue", NULL, 0);
										zephir_check_call_status();
										ZEPHIR_CPY_WRT(&value, &_14$$25);
									}
									do {
										if (ZEPHIR_IS_LONG(&dataType, 8)) {
											changed = zephir_get_boolval(&snapshotValue) != zephir_get_boolval(&value);
											break;
										}
										if (ZEPHIR_IS_LONG(&dataType, 3) || ZEPHIR_IS_LONG(&dataType, 7)) {
											ZEPHIR_CALL_FUNCTION(&_15$$27, "floatval", &_16, 17, &snapshotValue);
											zephir_check_call_status();
											ZEPHIR_CALL_FUNCTION(&_17$$27, "floatval", &_16, 17, &value);
											zephir_check_call_status();
											changed = !ZEPHIR_IS_IDENTICAL(&_15$$27, &_17$$27);
											break;
										}
										if (ZEPHIR_IS_LONG(&dataType, 0) || ZEPHIR_IS_LONG(&dataType, 1) || ZEPHIR_IS_LONG(&dataType, 2) || ZEPHIR_IS_LONG(&dataType, 4) || ZEPHIR_IS_LONG(&dataType, 5) || ZEPHIR_IS_LONG(&dataType, 6) || ZEPHIR_IS_LONG(&dataType, 2) || ZEPHIR_IS_LONG(&dataType, 14)) {
											zephir_cast_to_string(&_18$$28, &snapshotValue);
											zephir_cast_to_string(&_19$$28, &value);
											changed = !ZEPHIR_IS_IDENTICAL(&_18$$28, &_19$$28);
											break;
										}
										changed = !ZEPHIR_IS_EQUAL(&value, &snapshotValue);
									} while(0);

								}
							}
						}
						if (changed) {
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3961);
							zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3962);
							zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3963);
						}
					}
					zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
					zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3971);
					zephir_array_append(&values, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3972);
					zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3973);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &nonPrimary, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &nonPrimary, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, &nonPrimary, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
						if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
							ZEPHIR_INIT_NVAR(&_20$$35);
							object_init_ex(&_20$$35, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_21$$35);
							ZEPHIR_CONCAT_SVS(&_21$$35, "Column '", &field, "' isn't part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_20$$35, "__construct", &_6, 30, &_21$$35);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_20$$35, "phalcon/Mvc/Model.zep", 3859);
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &field);
				}
				if (!(zephir_array_isset(&automaticAttributes, &attributeField))) {
					ZEPHIR_OBS_NVAR(&bindType);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0)))) {
						ZEPHIR_INIT_NVAR(&_22$$38);
						object_init_ex(&_22$$38, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_23$$38);
						ZEPHIR_CONCAT_SVS(&_23$$38, "Column '", &field, "' have not defined a bind data type");
						ZEPHIR_CALL_METHOD(NULL, &_22$$38, "__construct", &_6, 30, &_23$$38);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_22$$38, "phalcon/Mvc/Model.zep", 3873);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&value);
					if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
						if (!(useDynamicUpdate)) {
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3885);
							zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3886);
							zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3887);
						} else {
							ZEPHIR_OBS_NVAR(&snapshotValue);
							if (!(zephir_array_isset_fetch(&snapshotValue, &snapshot, &attributeField, 0))) {
								changed = 1;
							} else {
								if (Z_TYPE_P(&value) == IS_NULL) {
									changed = Z_TYPE_P(&snapshotValue) != IS_NULL;
								} else {
									if (Z_TYPE_P(&snapshotValue) == IS_NULL) {
										changed = 1;
									} else {
										ZEPHIR_OBS_NVAR(&dataType);
										if (UNEXPECTED(!(zephir_array_isset_fetch(&dataType, &dataTypes, &field, 0)))) {
											ZEPHIR_INIT_NVAR(&_24$$48);
											object_init_ex(&_24$$48, phalcon_mvc_model_exception_ce);
											ZEPHIR_INIT_NVAR(&_25$$48);
											ZEPHIR_CONCAT_SVS(&_25$$48, "Column '", &field, "' have not defined a data type");
											ZEPHIR_CALL_METHOD(NULL, &_24$$48, "__construct", &_6, 30, &_25$$48);
											zephir_check_call_status();
											zephir_throw_exception_debug(&_24$$48, "phalcon/Mvc/Model.zep", 3912);
											ZEPHIR_MM_RESTORE();
											return;
										}
										_26$$47 = Z_TYPE_P(&snapshotValue) == IS_OBJECT;
										if (_26$$47) {
											_26$$47 = zephir_instance_of_ev(&snapshotValue, phalcon_db_rawvalue_ce);
										}
										if (_26$$47) {
											ZEPHIR_CALL_METHOD(&_27$$49, &snapshotValue, "getvalue", NULL, 0);
											zephir_check_call_status();
											ZEPHIR_CPY_WRT(&snapshotValue, &_27$$49);
										}
										_28$$47 = Z_TYPE_P(&value) == IS_OBJECT;
										if (_28$$47) {
											_28$$47 = zephir_instance_of_ev(&value, phalcon_db_rawvalue_ce);
										}
										if (_28$$47) {
											ZEPHIR_CALL_METHOD(&_29$$50, &value, "getvalue", NULL, 0);
											zephir_check_call_status();
											ZEPHIR_CPY_WRT(&value, &_29$$50);
										}
										do {
											if (ZEPHIR_IS_LONG(&dataType, 8)) {
												changed = zephir_get_boolval(&snapshotValue) != zephir_get_boolval(&value);
												break;
											}
											if (ZEPHIR_IS_LONG(&dataType, 3) || ZEPHIR_IS_LONG(&dataType, 7)) {
												ZEPHIR_CALL_FUNCTION(&_30$$52, "floatval", &_16, 17, &snapshotValue);
												zephir_check_call_status();
												ZEPHIR_CALL_FUNCTION(&_31$$52, "floatval", &_16, 17, &value);
												zephir_check_call_status();
												changed = !ZEPHIR_IS_IDENTICAL(&_30$$52, &_31$$52);
												break;
											}
											if (ZEPHIR_IS_LONG(&dataType, 0) || ZEPHIR_IS_LONG(&dataType, 1) || ZEPHIR_IS_LONG(&dataType, 2) || ZEPHIR_IS_LONG(&dataType, 4) || ZEPHIR_IS_LONG(&dataType, 5) || ZEPHIR_IS_LONG(&dataType, 6) || ZEPHIR_IS_LONG(&dataType, 2) || ZEPHIR_IS_LONG(&dataType, 14)) {
												zephir_cast_to_string(&_32$$53, &snapshotValue);
												zephir_cast_to_string(&_33$$53, &value);
												changed = !ZEPHIR_IS_IDENTICAL(&_32$$53, &_33$$53);
												break;
											}
											changed = !ZEPHIR_IS_EQUAL(&value, &snapshotValue);
										} while(0);

									}
								}
							}
							if (changed) {
								zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3961);
								zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3962);
								zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3963);
							}
						}
						zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3971);
						zephir_array_append(&values, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3972);
						zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3973);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &nonPrimary, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&field);
	if (!(zephir_fast_count_int(&fields))) {
		if (useDynamicUpdate) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("oldSnapshot"), &snapshot);
		}
		RETURN_MM_BOOL(1);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("uniqueKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueKey, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("uniqueParams"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueParams, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("uniqueTypes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueTypes, &_0);
	if (Z_TYPE_P(&uniqueParams) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&primaryKeys, metaData, "getprimarykeyattributes", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (UNEXPECTED(!(zephir_fast_count_int(&primaryKeys)))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A primary key must be defined in the model in order to perform the operation", "phalcon/Mvc/Model.zep", 4005);
			return;
		}
		ZEPHIR_INIT_NVAR(&uniqueParams);
		array_init(&uniqueParams);
		zephir_is_iterable(&primaryKeys, 0, "phalcon/Mvc/Model.zep", 4032);
		if (Z_TYPE_P(&primaryKeys) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&primaryKeys), _34$$59)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _34$$59);
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
						ZEPHIR_INIT_NVAR(&_36$$63);
						object_init_ex(&_36$$63, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_37$$63);
						ZEPHIR_CONCAT_SVS(&_37$$63, "Column '", &field, "' isn't part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_36$$63, "__construct", &_6, 30, &_37$$63);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_36$$63, "phalcon/Mvc/Model.zep", 4018);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &field);
				}
				ZEPHIR_OBS_NVAR(&value);
				if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
					zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
					zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4026);
				} else {
					zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
					zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4029);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &primaryKeys, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_35$$59, &primaryKeys, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_35$$59)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, &primaryKeys, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
							ZEPHIR_INIT_NVAR(&_38$$69);
							object_init_ex(&_38$$69, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_39$$69);
							ZEPHIR_CONCAT_SVS(&_39$$69, "Column '", &field, "' isn't part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_38$$69, "__construct", &_6, 30, &_39$$69);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_38$$69, "phalcon/Mvc/Model.zep", 4018);
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_CPY_WRT(&attributeField, &field);
					}
					ZEPHIR_OBS_NVAR(&value);
					if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
						zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
						zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4026);
					} else {
						zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
						zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4029);
					}
				ZEPHIR_CALL_METHOD(NULL, &primaryKeys, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&field);
	}
	if (Z_TYPE_P(table) == IS_ARRAY) {
		zephir_array_fetch_long(&_40$$73, table, 0, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4038);
		zephir_array_fetch_long(&_41$$73, table, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4038);
		ZEPHIR_INIT_VAR(&_42$$73);
		ZEPHIR_CONCAT_VSV(&_42$$73, &_40$$73, ".", &_41$$73);
		ZEPHIR_CPY_WRT(table, &_42$$73);
	}
	ZEPHIR_INIT_VAR(&_43);
	zephir_create_array(&_43, 3, 0);
	zephir_array_update_string(&_43, SL("conditions"), &uniqueKey, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_43, SL("bind"), &uniqueParams, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_43, SL("bindTypes"), &uniqueTypes, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&success, connection, "update", NULL, 0, table, &fields, &values, &_43, &bindTypes);
	zephir_check_call_status();
	_44 = zephir_is_true(&success);
	if (_44) {
		ZEPHIR_CALL_METHOD(&_1, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		_44 = zephir_is_true(&_1);
	}
	_45 = _44;
	if (_45) {
		_45 = ZEPHIR_GLOBAL(orm).update_snapshot_on_save;
	}
	if (_45) {
		if (Z_TYPE_P(&snapshot) == IS_ARRAY) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("oldSnapshot"), &snapshot);
			ZEPHIR_INIT_VAR(&_46$$75);
			zephir_fast_array_merge(&_46$$75, &snapshot, &newSnapshot);
			zephir_update_property_zval(this_ptr, ZEND_STRL("snapshot"), &_46$$75);
		} else {
			ZEPHIR_INIT_VAR(&_47$$76);
			array_init(&_47$$76);
			zephir_update_property_zval(this_ptr, ZEND_STRL("oldSnapshot"), &_47$$76);
			zephir_update_property_zval(this_ptr, ZEND_STRL("snapshot"), &newSnapshot);
		}
	}
	RETURN_CCTOR(&success);
}

/**
 * Checks whether the current record already exists
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Mvc_Model, has)
{
	zend_bool _6$$11, _14$$19;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_10 = NULL, *_18 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberEmpty = 0, numberPrimary = 0;
	zval *metaData, metaData_sub, *connection, connection_sub, __$null, attributeField, bindDataTypes, columnMap, field, joinWhere, num, primaryKeys, schema, source, table, type, uniqueKey, uniqueParams, uniqueTypes, value, wherePk, _0, _23, _24, _25, _26, *_1$$3, _2$$3, _3$$9, _4$$9, _7$$14, _8$$14, _9$$7, _11$$7, _12$$17, _13$$17, _15$$22, _16$$22, _17$$15, _19$$15, _20$$25, _21$$26, _22$$27, _27$$30, _28$$31;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData_sub);
	ZVAL_UNDEF(&connection_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&bindDataTypes);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&joinWhere);
	ZVAL_UNDEF(&num);
	ZVAL_UNDEF(&primaryKeys);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&uniqueKey);
	ZVAL_UNDEF(&uniqueParams);
	ZVAL_UNDEF(&uniqueTypes);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&wherePk);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_7$$14);
	ZVAL_UNDEF(&_8$$14);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$17);
	ZVAL_UNDEF(&_13$$17);
	ZVAL_UNDEF(&_15$$22);
	ZVAL_UNDEF(&_16$$22);
	ZVAL_UNDEF(&_17$$15);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_20$$25);
	ZVAL_UNDEF(&_21$$26);
	ZVAL_UNDEF(&_22$$27);
	ZVAL_UNDEF(&_27$$30);
	ZVAL_UNDEF(&_28$$31);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(metaData, phalcon_mvc_model_metadatainterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(connection, phalcon_db_adapter_adapterinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &metaData, &connection);


	ZEPHIR_INIT_VAR(&uniqueParams);
	ZVAL_NULL(&uniqueParams);
	ZEPHIR_INIT_VAR(&uniqueTypes);
	ZVAL_NULL(&uniqueTypes);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("uniqueKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueKey, &_0);
	if (Z_TYPE_P(&uniqueKey) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&primaryKeys, metaData, "getprimarykeyattributes", NULL, 0, this_ptr);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&bindDataTypes, metaData, "getbindtypes", NULL, 0, this_ptr);
		zephir_check_call_status();
		numberPrimary = zephir_fast_count_int(&primaryKeys);
		if (!(numberPrimary)) {
			RETURN_MM_BOOL(0);
		}
		if (ZEPHIR_GLOBAL(orm).column_renaming) {
			ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, 0, this_ptr);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&columnMap);
			ZVAL_NULL(&columnMap);
		}
		numberEmpty = 0;
		ZEPHIR_INIT_VAR(&wherePk);
		array_init(&wherePk);
		ZEPHIR_INIT_NVAR(&uniqueParams);
		array_init(&uniqueParams);
		ZEPHIR_INIT_NVAR(&uniqueTypes);
		array_init(&uniqueTypes);
		zephir_is_iterable(&primaryKeys, 0, "phalcon/Mvc/Model.zep", 4162);
		if (Z_TYPE_P(&primaryKeys) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&primaryKeys), _1$$3)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _1$$3);
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
						ZEPHIR_INIT_NVAR(&_3$$9);
						object_init_ex(&_3$$9, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_4$$9);
						ZEPHIR_CONCAT_SVS(&_4$$9, "Column '", &field, "' isn't part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_3$$9, "__construct", &_5, 30, &_4$$9);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_3$$9, "phalcon/Mvc/Model.zep", 4121);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &field);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_NULL(&value);
				ZEPHIR_OBS_NVAR(&value);
				if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
					_6$$11 = Z_TYPE_P(&value) == IS_NULL;
					if (!(_6$$11)) {
						_6$$11 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
					}
					if (_6$$11) {
						numberEmpty++;
					}
					zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4142);
				} else {
					zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4144);
					numberEmpty++;
				}
				ZEPHIR_OBS_NVAR(&type);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&type, &bindDataTypes, &field, 0)))) {
					ZEPHIR_INIT_NVAR(&_7$$14);
					object_init_ex(&_7$$14, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_NVAR(&_8$$14);
					ZEPHIR_CONCAT_SVS(&_8$$14, "Column '", &field, "' isn't part of the table columns");
					ZEPHIR_CALL_METHOD(NULL, &_7$$14, "__construct", &_5, 30, &_8$$14);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_7$$14, "phalcon/Mvc/Model.zep", 4151);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&uniqueTypes, &type, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4154);
				ZEPHIR_CALL_METHOD(&_9$$7, connection, "escapeidentifier", &_10, 0, &field);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_11$$7);
				ZEPHIR_CONCAT_VS(&_11$$7, &_9$$7, " = ?");
				zephir_array_append(&wherePk, &_11$$7, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4155);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &primaryKeys, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_2$$3, &primaryKeys, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_2$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, &primaryKeys, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
							ZEPHIR_INIT_NVAR(&_12$$17);
							object_init_ex(&_12$$17, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_13$$17);
							ZEPHIR_CONCAT_SVS(&_13$$17, "Column '", &field, "' isn't part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_12$$17, "__construct", &_5, 30, &_13$$17);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_12$$17, "phalcon/Mvc/Model.zep", 4121);
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_CPY_WRT(&attributeField, &field);
					}
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_NULL(&value);
					ZEPHIR_OBS_NVAR(&value);
					if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
						_14$$19 = Z_TYPE_P(&value) == IS_NULL;
						if (!(_14$$19)) {
							_14$$19 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
						}
						if (_14$$19) {
							numberEmpty++;
						}
						zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4142);
					} else {
						zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4144);
						numberEmpty++;
					}
					ZEPHIR_OBS_NVAR(&type);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&type, &bindDataTypes, &field, 0)))) {
						ZEPHIR_INIT_NVAR(&_15$$22);
						object_init_ex(&_15$$22, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_16$$22);
						ZEPHIR_CONCAT_SVS(&_16$$22, "Column '", &field, "' isn't part of the table columns");
						ZEPHIR_CALL_METHOD(NULL, &_15$$22, "__construct", &_5, 30, &_16$$22);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_15$$22, "phalcon/Mvc/Model.zep", 4151);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&uniqueTypes, &type, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4154);
					ZEPHIR_CALL_METHOD(&_17$$15, connection, "escapeidentifier", &_18, 0, &field);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_19$$15);
					ZEPHIR_CONCAT_VS(&_19$$15, &_17$$15, " = ?");
					zephir_array_append(&wherePk, &_19$$15, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4155);
				ZEPHIR_CALL_METHOD(NULL, &primaryKeys, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&field);
		if (numberPrimary == numberEmpty) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(&joinWhere);
		zephir_fast_join_str(&joinWhere, SL(" AND "), &wherePk);
		zephir_update_property_zval(this_ptr, ZEND_STRL("uniqueKey"), &joinWhere);
		zephir_update_property_zval(this_ptr, ZEND_STRL("uniqueParams"), &uniqueParams);
		zephir_update_property_zval(this_ptr, ZEND_STRL("uniqueTypes"), &uniqueTypes);
		ZEPHIR_CPY_WRT(&uniqueKey, &joinWhere);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("dirtyState"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_BOOL(1);
	}
	if (Z_TYPE_P(&uniqueKey) == IS_NULL) {
		zephir_read_property(&_20$$25, this_ptr, ZEND_STRL("uniqueKey"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&uniqueKey, &_20$$25);
	}
	if (Z_TYPE_P(&uniqueParams) == IS_NULL) {
		zephir_read_property(&_21$$26, this_ptr, ZEND_STRL("uniqueParams"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&uniqueParams, &_21$$26);
	}
	if (Z_TYPE_P(&uniqueTypes) == IS_NULL) {
		zephir_read_property(&_22$$27, this_ptr, ZEND_STRL("uniqueTypes"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&uniqueTypes, &_22$$27);
	}
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 474);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 475);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	ZEPHIR_CALL_METHOD(&_23, connection, "escapeidentifier", NULL, 0, &table);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_24);
	ZEPHIR_CONCAT_SVSV(&_24, "SELECT COUNT(*) \"rowcount\" FROM ", &_23, " WHERE ", &uniqueKey);
	ZVAL_NULL(&_25);
	ZEPHIR_CALL_METHOD(&num, connection, "fetchone", NULL, 0, &_24, &_25, &uniqueParams, &uniqueTypes);
	zephir_check_call_status();
	zephir_array_fetch_string(&_26, &num, SL("rowcount"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4216);
	if (zephir_is_true(&_26)) {
		ZEPHIR_INIT_ZVAL_NREF(_27$$30);
		ZVAL_LONG(&_27$$30, 0);
		zephir_update_property_zval(this_ptr, ZEND_STRL("dirtyState"), &_27$$30);
		RETURN_MM_BOOL(1);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_28$$31);
		ZVAL_LONG(&_28$$31, 1);
		zephir_update_property_zval(this_ptr, ZEND_STRL("dirtyState"), &_28$$31);
	}
	RETURN_MM_BOOL(0);
}

/**
 * Returns related records defined relations depending on the method name.
 * Returns false if the relation is non-existent.
 *
 * @param string modelName
 * @param string method
 * @param array  arguments
 *
 * @return ResultsetInterface|ModelInterface|bool|null
 */
PHP_METHOD(Phalcon_Mvc_Model, getRelatedRecords)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments;
	zval *modelName_param = NULL, *method_param = NULL, *arguments_param = NULL, manager, relation, queryMethod, extraArgs, alias, _0, _1$$3, _2$$3, _3$$5, _4$$5, _5$$5;
	zval modelName, method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&queryMethod);
	ZVAL_UNDEF(&extraArgs);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&arguments);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(modelName)
		Z_PARAM_STR(method)
		Z_PARAM_ARRAY(arguments)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &modelName_param, &method_param, &arguments_param);
	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
	}
	if (UNEXPECTED(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(&method, method_param);
	} else {
		ZEPHIR_INIT_VAR(&method);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&arguments, arguments_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_INIT_VAR(&relation);
	ZVAL_BOOL(&relation, 0);
	ZEPHIR_INIT_VAR(&queryMethod);
	ZVAL_NULL(&queryMethod);
	ZEPHIR_OBS_VAR(&extraArgs);
	zephir_array_isset_long_fetch(&extraArgs, &arguments, 0, 0);
	if (zephir_start_with_str(&method, SL("get"))) {
		ZVAL_LONG(&_1$$3, 3);
		ZEPHIR_INIT_VAR(&alias);
		zephir_substr(&alias, &method, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_METHOD(&_2$$3, &manager, "getrelationbyalias", NULL, 0, &modelName, &alias);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_2$$3);
		if (Z_TYPE_P(&relation) != IS_OBJECT) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrelated", NULL, 0, &alias, &extraArgs);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_start_with_str(&method, SL("count"))) {
		ZEPHIR_INIT_NVAR(&queryMethod);
		ZVAL_STRING(&queryMethod, "count");
		ZVAL_LONG(&_4$$5, 5);
		ZEPHIR_INIT_VAR(&_5$$5);
		zephir_substr(&_5$$5, &method, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_METHOD(&_3$$5, &manager, "getrelationbyalias", NULL, 0, &modelName, &_5$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_3$$5);
		if (Z_TYPE_P(&relation) != IS_OBJECT) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_RETURN_CALL_METHOD(&manager, "getrelationrecords", NULL, 0, &relation, this_ptr, &extraArgs, &queryMethod);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);
}

/**
 * Generate a PHQL SELECT statement for an aggregate
 *
 * @param string functionName
 * @param string alias
 * @param array|string|null parameters
 *
 * @return ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, groupResult)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *functionName_param = NULL, *alias_param = NULL, *parameters = NULL, parameters_sub, __$null, params, distinctColumn, groupColumn, columns, resultset, cache, firstRow, groupColumns, builder, query, container, manager, transaction, bindParams, bindTypes, _1, _2, _3;
	zval functionName, alias;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&functionName);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&distinctColumn);
	ZVAL_UNDEF(&groupColumn);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&resultset);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&firstRow);
	ZVAL_UNDEF(&groupColumns);
	ZVAL_UNDEF(&builder);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&transaction);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(functionName)
		Z_PARAM_STR(alias)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(parameters)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &functionName_param, &alias_param, &parameters);
	if (UNEXPECTED(Z_TYPE_P(functionName_param) != IS_STRING && Z_TYPE_P(functionName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'functionName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(functionName_param) == IS_STRING)) {
		zephir_get_strval(&functionName, functionName_param);
	} else {
		ZEPHIR_INIT_VAR(&functionName);
	}
	if (UNEXPECTED(Z_TYPE_P(alias_param) != IS_STRING && Z_TYPE_P(alias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(alias_param) == IS_STRING)) {
		zephir_get_strval(&alias, alias_param);
	} else {
		ZEPHIR_INIT_VAR(&alias);
	}
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_INIT_VAR(&bindParams);
	array_init(&bindParams);
	ZEPHIR_INIT_VAR(&bindTypes);
	array_init(&bindTypes);
	ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_ce, "getdefault", &_0, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "modelsManager");
	ZEPHIR_CALL_METHOD(&_1, &container, "getshared", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_1);
	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
		if (Z_TYPE_P(parameters) != IS_NULL) {
			zephir_array_append(&params, parameters, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4321);
		}
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	ZEPHIR_OBS_VAR(&groupColumn);
	if (!(zephir_array_isset_string_fetch(&groupColumn, &params, SL("column"), 0))) {
		ZEPHIR_INIT_NVAR(&groupColumn);
		ZVAL_STRING(&groupColumn, "*");
	}
	ZEPHIR_OBS_VAR(&distinctColumn);
	if (zephir_array_isset_string_fetch(&distinctColumn, &params, SL("distinct"), 0)) {
		ZEPHIR_INIT_VAR(&columns);
		ZEPHIR_CONCAT_VSVSV(&columns, &functionName, "(DISTINCT ", &distinctColumn, ") AS ", &alias);
	} else {
		ZEPHIR_OBS_VAR(&groupColumns);
		ZEPHIR_INIT_NVAR(&columns);
		if (zephir_array_isset_string_fetch(&groupColumns, &params, SL("group"), 0)) {
			ZEPHIR_CONCAT_VSVSVSV(&columns, &groupColumns, ", ", &functionName, "(", &groupColumn, ") AS ", &alias);
		} else {
			ZEPHIR_CONCAT_VSVSV(&columns, &functionName, "(", &groupColumn, ") AS ", &alias);
		}
	}
	ZEPHIR_CALL_METHOD(&_1, &manager, "createbuilder", NULL, 0, &params);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&builder, &_1);
	ZEPHIR_CALL_METHOD(NULL, &builder, "columns", NULL, 0, &columns);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	zephir_get_called_class(&_2);
	ZEPHIR_CALL_METHOD(NULL, &builder, "from", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &builder, "getquery", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&query, &_1);
	ZEPHIR_OBS_VAR(&transaction);
	if (zephir_array_isset_string_fetch(&transaction, &params, SL("transaction"), 0)) {
		if (zephir_instance_of_ev(&transaction, phalcon_mvc_model_transactioninterface_ce)) {
			ZEPHIR_CALL_METHOD(NULL, &query, "settransaction", NULL, 0, &transaction);
			zephir_check_call_status();
		}
	}
	if (zephir_array_isset_string(&params, SL("bind"))) {
		ZEPHIR_OBS_NVAR(&bindParams);
		zephir_array_fetch_string(&bindParams, &params, SL("bind"), PH_NOISY, "phalcon/Mvc/Model.zep", 4364);
		if (zephir_array_isset_string(&params, SL("bindTypes"))) {
			ZEPHIR_OBS_NVAR(&bindTypes);
			zephir_array_fetch_string(&bindTypes, &params, SL("bindTypes"), PH_NOISY, "phalcon/Mvc/Model.zep", 4367);
		}
	}
	ZEPHIR_OBS_VAR(&cache);
	if (zephir_array_isset_string_fetch(&cache, &params, SL("cache"), 0)) {
		ZEPHIR_CALL_METHOD(NULL, &query, "cache", NULL, 0, &cache);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&resultset, &query, "execute", NULL, 0, &bindParams, &bindTypes);
	zephir_check_call_status();
	if (zephir_array_isset_string(&params, SL("group"))) {
		RETURN_CCTOR(&resultset);
	}
	ZEPHIR_CALL_METHOD(&firstRow, &resultset, "getfirst", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&_3);
	zephir_read_property_zval(&_3, &firstRow, &alias, PH_NOISY_CC);
	RETURN_CCTOR(&_3);
}

/**
 * Try to check if the query must invoke a finder
 *
 * @return ModelInterface[]|ModelInterface|bool
 */
PHP_METHOD(Phalcon_Mvc_Model, invokeFinder)
{
	zend_class_entry *_13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments, _9$$14;
	zval *method_param = NULL, *arguments_param = NULL, extraMethod, type, modelName, value, model, attributes, field, extraMethodFirst, metaData, params, _12, _0$$3, _1$$4, _2$$5, _3$$7, _5$$13, _6$$13, _7$$14, _8$$14, _10$$15, _11$$15;
	zval method, _4$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&extraMethod);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&extraMethodFirst);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_5$$13);
	ZVAL_UNDEF(&_6$$13);
	ZVAL_UNDEF(&_7$$14);
	ZVAL_UNDEF(&_8$$14);
	ZVAL_UNDEF(&_10$$15);
	ZVAL_UNDEF(&_11$$15);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&_9$$14);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(method)
		Z_PARAM_ARRAY(arguments)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &arguments_param);
	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&arguments, arguments_param);


	ZEPHIR_INIT_VAR(&extraMethod);
	ZVAL_NULL(&extraMethod);
	if (zephir_start_with_str(&method, SL("findFirstBy"))) {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_STRING(&type, "findFirst");
		ZVAL_LONG(&_0$$3, 11);
		ZEPHIR_INIT_NVAR(&extraMethod);
		zephir_substr(&extraMethod, &method, 11 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	} else if (zephir_start_with_str(&method, SL("findBy"))) {
		ZEPHIR_INIT_NVAR(&type);
		ZVAL_STRING(&type, "find");
		ZVAL_LONG(&_1$$4, 6);
		ZEPHIR_INIT_NVAR(&extraMethod);
		zephir_substr(&extraMethod, &method, 6 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	} else if (zephir_start_with_str(&method, SL("countBy"))) {
		ZEPHIR_INIT_NVAR(&type);
		ZVAL_STRING(&type, "count");
		ZVAL_LONG(&_2$$5, 7);
		ZEPHIR_INIT_NVAR(&extraMethod);
		zephir_substr(&extraMethod, &method, 7 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	}
	ZEPHIR_INIT_VAR(&modelName);
	zephir_get_called_class(&modelName);
	if (!(zephir_is_true(&extraMethod))) {
		RETURN_MM_BOOL(0);
	}
	if (UNEXPECTED(!(zephir_array_isset_long(&arguments, 0)))) {
		ZEPHIR_INIT_VAR(&_3$$7);
		object_init_ex(&_3$$7, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$7);
		ZEPHIR_CONCAT_SVS(&_4$$7, "The static method '", &method, "' requires one argument");
		ZEPHIR_CALL_METHOD(NULL, &_3$$7, "__construct", NULL, 30, &_4$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$7, "phalcon/Mvc/Model.zep", 4446);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&model);
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&model, &modelName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&metaData, &model, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&attributes, &metaData, "getreversecolumnmap", NULL, 0, &model);
	zephir_check_call_status();
	if (Z_TYPE_P(&attributes) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&attributes, &metaData, "getdatatypes", NULL, 0, &model);
		zephir_check_call_status();
	}
	if (zephir_array_isset(&attributes, &extraMethod)) {
		ZEPHIR_CPY_WRT(&field, &extraMethod);
	} else {
		ZEPHIR_CALL_FUNCTION(&extraMethodFirst, "lcfirst", NULL, 101, &extraMethod);
		zephir_check_call_status();
		if (zephir_array_isset(&attributes, &extraMethodFirst)) {
			ZEPHIR_CPY_WRT(&field, &extraMethodFirst);
		} else {
			ZEPHIR_INIT_NVAR(&field);
			zephir_uncamelize(&field, &extraMethod, NULL  );
			if (UNEXPECTED(!(zephir_array_isset(&attributes, &field)))) {
				ZEPHIR_INIT_VAR(&_5$$13);
				object_init_ex(&_5$$13, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(&_6$$13);
				ZEPHIR_CONCAT_SVS(&_6$$13, "Cannot resolve attribute '", &extraMethod, "' in the model");
				ZEPHIR_CALL_METHOD(NULL, &_5$$13, "__construct", NULL, 30, &_6$$13);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_5$$13, "phalcon/Mvc/Model.zep", 4483);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	ZEPHIR_OBS_VAR(&value);
	zephir_array_isset_long_fetch(&value, &arguments, 0, 0);
	ZEPHIR_INIT_VAR(&params);
	if (Z_TYPE_P(&value) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_7$$14);
		zephir_create_array(&_7$$14, 2, 0);
		ZEPHIR_INIT_VAR(&_8$$14);
		ZEPHIR_CONCAT_SVS(&_8$$14, "[", &field, "] = ?0");
		zephir_array_update_string(&_7$$14, SL("conditions"), &_8$$14, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_9$$14);
		zephir_create_array(&_9$$14, 1, 0);
		zephir_array_fast_append(&_9$$14, &value);
		zephir_array_update_string(&_7$$14, SL("bind"), &_9$$14, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&params, &_7$$14);
	} else {
		ZEPHIR_INIT_VAR(&_10$$15);
		zephir_create_array(&_10$$15, 1, 0);
		ZEPHIR_INIT_VAR(&_11$$15);
		ZEPHIR_CONCAT_SVS(&_11$$15, "[", &field, "] IS NULL");
		zephir_array_update_string(&_10$$15, SL("conditions"), &_11$$15, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&params, &_10$$15);
	}
	zephir_array_unset_long(&arguments, 0, PH_SEPARATE);
	zephir_array_unset_string(&arguments, SL("conditions"), PH_SEPARATE);
	zephir_array_unset_string(&arguments, SL("bind"), PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_12);
	zephir_fast_array_merge(&_12, &params, &arguments);
	ZEPHIR_CPY_WRT(&params, &_12);
	_13 = zephir_fetch_class(&modelName);
	ZEPHIR_RETURN_CALL_CE_STATIC_ZVAL(_13, type, NULL, 0, &params);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Check for, and attempt to use, possible setter.
 */
PHP_METHOD(Phalcon_Mvc_Model, possibleSetter)
{
	zval localMethods;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, *value, value_sub, possibleSetter, _0;
	zval property;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&possibleSetter);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&localMethods);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(property)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &property_param, &value);
	zephir_get_strval(&property, property_param);


	ZEPHIR_INIT_VAR(&localMethods);
	zephir_create_array(&localMethods, 10, 0);
	add_assoc_long_ex(&localMethods, SL("setConnectionService"), 1);
	add_assoc_long_ex(&localMethods, SL("setDirtyState"), 1);
	add_assoc_long_ex(&localMethods, SL("setEventsManager"), 1);
	add_assoc_long_ex(&localMethods, SL("setReadConnectionService"), 1);
	add_assoc_long_ex(&localMethods, SL("setOldSnapshotData"), 1);
	add_assoc_long_ex(&localMethods, SL("setSchema"), 1);
	add_assoc_long_ex(&localMethods, SL("setSnapshotData"), 1);
	add_assoc_long_ex(&localMethods, SL("setSource"), 1);
	add_assoc_long_ex(&localMethods, SL("setTransaction"), 1);
	add_assoc_long_ex(&localMethods, SL("setWriteConnectionService"), 1);
	ZEPHIR_INIT_VAR(&_0);
	zephir_camelize(&_0, &property, NULL  );
	ZEPHIR_INIT_VAR(&possibleSetter);
	ZEPHIR_CONCAT_SV(&possibleSetter, "set", &_0);
	if (!((zephir_method_exists(this_ptr, &possibleSetter)  == SUCCESS))) {
		RETURN_MM_BOOL(0);
	}
	if (!(zephir_array_isset(&localMethods, &possibleSetter))) {
		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &possibleSetter, NULL, 0, value);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);
}

/**
 * Executes internal hooks before save a record
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Mvc_Model, preSave)
{
	zval eventName;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool exists, error = 0, isNull = 0, _9$$27, _10$$27, _11$$27, _19$$47, _20$$47, _21$$47;
	zval *metaData, metaData_sub, *exists_param = NULL, *identityField, identityField_sub, __$true, __$false, notNull, columnMap, dataTypeNumeric, automaticAttributes, defaultValues, field, attributeField, value, emptyStringValues, _27, _28, _0$$3, _1$$3, _2$$3, _3$$8, *_4$$11, _5$$11, _6$$19, _7$$19, _12$$27, _13$$32, _14$$32, _15$$32, _17$$39, _18$$39, _22$$47, _23$$52, _24$$52, _25$$52, _26$$57, _29$$59, _30$$60, _31$$60, _32$$60, _33$$60, _34$$60, _35$$60;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData_sub);
	ZVAL_UNDEF(&identityField_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&notNull);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&dataTypeNumeric);
	ZVAL_UNDEF(&automaticAttributes);
	ZVAL_UNDEF(&defaultValues);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&emptyStringValues);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_5$$11);
	ZVAL_UNDEF(&_6$$19);
	ZVAL_UNDEF(&_7$$19);
	ZVAL_UNDEF(&_12$$27);
	ZVAL_UNDEF(&_13$$32);
	ZVAL_UNDEF(&_14$$32);
	ZVAL_UNDEF(&_15$$32);
	ZVAL_UNDEF(&_17$$39);
	ZVAL_UNDEF(&_18$$39);
	ZVAL_UNDEF(&_22$$47);
	ZVAL_UNDEF(&_23$$52);
	ZVAL_UNDEF(&_24$$52);
	ZVAL_UNDEF(&_25$$52);
	ZVAL_UNDEF(&_26$$57);
	ZVAL_UNDEF(&_29$$59);
	ZVAL_UNDEF(&_30$$60);
	ZVAL_UNDEF(&_31$$60);
	ZVAL_UNDEF(&_32$$60);
	ZVAL_UNDEF(&_33$$60);
	ZVAL_UNDEF(&_34$$60);
	ZVAL_UNDEF(&_35$$60);
	ZVAL_UNDEF(&eventName);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(metaData, phalcon_mvc_model_metadatainterface_ce)
		Z_PARAM_BOOL(exists)
		Z_PARAM_ZVAL(identityField)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &metaData, &exists_param, &identityField);
	exists = zephir_get_boolval(exists_param);


	if (ZEPHIR_GLOBAL(orm).events) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "beforeValidation");
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "fireeventcancel", NULL, 0, &_1$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_0$$3)) {
			RETURN_MM_BOOL(0);
		}
		if (exists) {
			ZEPHIR_INIT_VAR(&eventName);
			ZVAL_STRING(&eventName, "beforeValidationOnUpdate");
		} else {
			ZEPHIR_INIT_NVAR(&eventName);
			ZVAL_STRING(&eventName, "beforeValidationOnCreate");
		}
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "fireeventcancel", NULL, 0, &eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_2$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	if (ZEPHIR_GLOBAL(orm).virtual_foreign_keys) {
		ZEPHIR_CALL_METHOD(&_3$$8, this_ptr, "checkforeignkeysrestrict", NULL, 484);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_3$$8)) {
			RETURN_MM_BOOL(0);
		}
	}
	if (ZEPHIR_GLOBAL(orm).not_null_validations) {
		ZEPHIR_CALL_METHOD(&notNull, metaData, "getnotnullattributes", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (Z_TYPE_P(&notNull) == IS_ARRAY) {
			ZEPHIR_CALL_METHOD(&dataTypeNumeric, metaData, "getdatatypesnumeric", NULL, 0, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_GLOBAL(orm).column_renaming) {
				ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, 0, this_ptr);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&columnMap);
				ZVAL_NULL(&columnMap);
			}
			if (exists) {
				ZEPHIR_CALL_METHOD(&automaticAttributes, metaData, "getautomaticupdateattributes", NULL, 0, this_ptr);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&automaticAttributes, metaData, "getautomaticcreateattributes", NULL, 0, this_ptr);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&defaultValues, metaData, "getdefaultvalues", NULL, 0, this_ptr);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&emptyStringValues, metaData, "getemptystringattributes", NULL, 0, this_ptr);
			zephir_check_call_status();
			error = 0;
			zephir_is_iterable(&notNull, 0, "phalcon/Mvc/Model.zep", 4720);
			if (Z_TYPE_P(&notNull) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&notNull), _4$$11)
				{
					ZEPHIR_INIT_NVAR(&field);
					ZVAL_COPY(&field, _4$$11);
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
							if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
								ZEPHIR_INIT_NVAR(&_6$$19);
								object_init_ex(&_6$$19, phalcon_mvc_model_exception_ce);
								ZEPHIR_INIT_NVAR(&_7$$19);
								ZEPHIR_CONCAT_SVS(&_7$$19, "Column '", &field, "' isn't part of the column map");
								ZEPHIR_CALL_METHOD(NULL, &_6$$19, "__construct", &_8, 30, &_7$$19);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_6$$19, "phalcon/Mvc/Model.zep", 4644);
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} else {
						ZEPHIR_CPY_WRT(&attributeField, &field);
					}
					if (!(zephir_array_isset(&automaticAttributes, &attributeField))) {
						isNull = 0;
						ZEPHIR_OBS_NVAR(&value);
						if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
							if (Z_TYPE_P(&value) != IS_OBJECT) {
								if (!(zephir_array_isset(&dataTypeNumeric, &field))) {
									if (zephir_array_isset(&emptyStringValues, &field)) {
										if (Z_TYPE_P(&value) == IS_NULL) {
											isNull = 1;
										}
									} else {
										_9$$27 = Z_TYPE_P(&value) == IS_NULL;
										if (!(_9$$27)) {
											_10$$27 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
											if (_10$$27) {
												_11$$27 = !(zephir_array_isset(&defaultValues, &field));
												if (!(_11$$27)) {
													zephir_array_fetch(&_12$$27, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4674);
													_11$$27 = !ZEPHIR_IS_IDENTICAL(&value, &_12$$27);
												}
												_10$$27 = _11$$27;
											}
											_9$$27 = _10$$27;
										}
										if (_9$$27) {
											isNull = 1;
										}
									}
								} else {
									if (!(zephir_is_numeric(&value))) {
										isNull = 1;
									}
								}
							}
						} else {
							isNull = 1;
						}
						if (isNull) {
							if (!(exists)) {
								if (ZEPHIR_IS_EQUAL(&field, identityField)) {
									continue;
								}
								if (zephir_array_isset(&defaultValues, &field)) {
									continue;
								}
							}
							ZEPHIR_INIT_NVAR(&_13$$32);
							object_init_ex(&_13$$32, phalcon_messages_message_ce);
							ZEPHIR_INIT_NVAR(&_14$$32);
							ZEPHIR_CONCAT_VS(&_14$$32, &attributeField, " is required");
							ZEPHIR_INIT_NVAR(&_15$$32);
							ZVAL_STRING(&_15$$32, "PresenceOf");
							ZEPHIR_CALL_METHOD(NULL, &_13$$32, "__construct", &_16, 6, &_14$$32, &attributeField, &_15$$32);
							zephir_check_call_status();
							zephir_update_property_array_append(this_ptr, SL("errorMessages"), &_13$$32);
							error = 1;
						}
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &notNull, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_5$$11, &notNull, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_5$$11)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&field, &notNull, "current", NULL, 0);
					zephir_check_call_status();
						if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
							ZEPHIR_OBS_NVAR(&attributeField);
							if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
								if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
									ZEPHIR_INIT_NVAR(&_17$$39);
									object_init_ex(&_17$$39, phalcon_mvc_model_exception_ce);
									ZEPHIR_INIT_NVAR(&_18$$39);
									ZEPHIR_CONCAT_SVS(&_18$$39, "Column '", &field, "' isn't part of the column map");
									ZEPHIR_CALL_METHOD(NULL, &_17$$39, "__construct", &_8, 30, &_18$$39);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_17$$39, "phalcon/Mvc/Model.zep", 4644);
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
						} else {
							ZEPHIR_CPY_WRT(&attributeField, &field);
						}
						if (!(zephir_array_isset(&automaticAttributes, &attributeField))) {
							isNull = 0;
							ZEPHIR_OBS_NVAR(&value);
							if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
								if (Z_TYPE_P(&value) != IS_OBJECT) {
									if (!(zephir_array_isset(&dataTypeNumeric, &field))) {
										if (zephir_array_isset(&emptyStringValues, &field)) {
											if (Z_TYPE_P(&value) == IS_NULL) {
												isNull = 1;
											}
										} else {
											_19$$47 = Z_TYPE_P(&value) == IS_NULL;
											if (!(_19$$47)) {
												_20$$47 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
												if (_20$$47) {
													_21$$47 = !(zephir_array_isset(&defaultValues, &field));
													if (!(_21$$47)) {
														zephir_array_fetch(&_22$$47, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4674);
														_21$$47 = !ZEPHIR_IS_IDENTICAL(&value, &_22$$47);
													}
													_20$$47 = _21$$47;
												}
												_19$$47 = _20$$47;
											}
											if (_19$$47) {
												isNull = 1;
											}
										}
									} else {
										if (!(zephir_is_numeric(&value))) {
											isNull = 1;
										}
									}
								}
							} else {
								isNull = 1;
							}
							if (isNull) {
								if (!(exists)) {
									if (ZEPHIR_IS_EQUAL(&field, identityField)) {
										continue;
									}
									if (zephir_array_isset(&defaultValues, &field)) {
										continue;
									}
								}
								ZEPHIR_INIT_NVAR(&_23$$52);
								object_init_ex(&_23$$52, phalcon_messages_message_ce);
								ZEPHIR_INIT_NVAR(&_24$$52);
								ZEPHIR_CONCAT_VS(&_24$$52, &attributeField, " is required");
								ZEPHIR_INIT_NVAR(&_25$$52);
								ZVAL_STRING(&_25$$52, "PresenceOf");
								ZEPHIR_CALL_METHOD(NULL, &_23$$52, "__construct", &_16, 6, &_24$$52, &attributeField, &_25$$52);
								zephir_check_call_status();
								zephir_update_property_array_append(this_ptr, SL("errorMessages"), &_23$$52);
								error = 1;
							}
						}
					ZEPHIR_CALL_METHOD(NULL, &notNull, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&field);
			if (error) {
				if (ZEPHIR_GLOBAL(orm).events) {
					ZEPHIR_INIT_VAR(&_26$$57);
					ZVAL_STRING(&_26$$57, "onValidationFails");
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_26$$57);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "canceloperation", NULL, 0);
					zephir_check_call_status();
				}
				RETURN_MM_BOOL(0);
			}
		}
	}
	ZEPHIR_INIT_VAR(&_28);
	ZVAL_STRING(&_28, "validation");
	ZEPHIR_CALL_METHOD(&_27, this_ptr, "fireeventcancel", NULL, 0, &_28);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_27)) {
		if (ZEPHIR_GLOBAL(orm).events) {
			ZEPHIR_INIT_VAR(&_29$$59);
			ZVAL_STRING(&_29$$59, "onValidationFails");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_29$$59);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(0);
	}
	if (ZEPHIR_GLOBAL(orm).events) {
		if (exists) {
			ZEPHIR_INIT_NVAR(&eventName);
			ZVAL_STRING(&eventName, "afterValidationOnUpdate");
		} else {
			ZEPHIR_INIT_NVAR(&eventName);
			ZVAL_STRING(&eventName, "afterValidationOnCreate");
		}
		ZEPHIR_CALL_METHOD(&_30$$60, this_ptr, "fireeventcancel", NULL, 0, &eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_30$$60)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(&_32$$60);
		ZVAL_STRING(&_32$$60, "afterValidation");
		ZEPHIR_CALL_METHOD(&_31$$60, this_ptr, "fireeventcancel", NULL, 0, &_32$$60);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_31$$60)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(&_32$$60);
		ZVAL_STRING(&_32$$60, "beforeSave");
		ZEPHIR_CALL_METHOD(&_33$$60, this_ptr, "fireeventcancel", NULL, 0, &_32$$60);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_33$$60)) {
			RETURN_MM_BOOL(0);
		}
		if (0) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("skipped"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("skipped"), &__$false);
		}
		if (exists) {
			ZEPHIR_INIT_NVAR(&eventName);
			ZVAL_STRING(&eventName, "beforeUpdate");
		} else {
			ZEPHIR_INIT_NVAR(&eventName);
			ZVAL_STRING(&eventName, "beforeCreate");
		}
		ZEPHIR_CALL_METHOD(&_34$$60, this_ptr, "fireeventcancel", NULL, 0, &eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_34$$60)) {
			RETURN_MM_BOOL(0);
		}
		zephir_read_property(&_35$$60, this_ptr, ZEND_STRL("skipped"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_35$$60)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(1);
}

/**
 * Saves related records that must be stored prior to save the master record
 *
 * @param ModelInterface[] related
 * @return bool
 */
PHP_METHOD(Phalcon_Mvc_Model, preSaveRelatedRecords)
{
	zval _18$$10, _20$$12, _36$$20, _37$$22;
	zend_string *_5;
	zend_ulong _4;
	zend_bool nesting = 0, _13$$5, _31$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_9 = NULL, *_11 = NULL, *_19 = NULL, *_22 = NULL, *_25 = NULL, *_27 = NULL, *_29 = NULL, *_39 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, *related, related_sub, className, manager, type, relation, columns, referencedFields, referencedModel, message, name, record, _0, _1, *_2, _3, _6$$3, _8$$6, _10$$7, _12$$5, _14$$5, _23$$5, _15$$8, *_16$$8, _17$$8, _21$$8, _24$$13, _26$$16, _28$$17, _30$$15, _32$$15, _40$$15, _33$$18, *_34$$18, _35$$18, _38$$18;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&related_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&referencedFields);
	ZVAL_UNDEF(&referencedModel);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_26$$16);
	ZVAL_UNDEF(&_28$$17);
	ZVAL_UNDEF(&_30$$15);
	ZVAL_UNDEF(&_32$$15);
	ZVAL_UNDEF(&_40$$15);
	ZVAL_UNDEF(&_33$$18);
	ZVAL_UNDEF(&_35$$18);
	ZVAL_UNDEF(&_38$$18);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_36$$20);
	ZVAL_UNDEF(&_37$$22);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(connection, phalcon_db_adapter_adapterinterface_ce)
		Z_PARAM_ZVAL(related)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &connection, &related);


	nesting = 0;
	if (nesting) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, connection, "begin", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, this_ptr, 0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_1);
	zephir_is_iterable(related, 0, "phalcon/Mvc/Model.zep", 4898);
	if (Z_TYPE_P(related) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(related), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&name, _5);
			} else {
				ZVAL_LONG(&name, _4);
			}
			ZEPHIR_INIT_NVAR(&record);
			ZVAL_COPY(&record, _2);
			ZEPHIR_CALL_METHOD(&_6$$3, &manager, "getrelationbyalias", &_7, 0, &className, &name);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&relation, &_6$$3);
			if (Z_TYPE_P(&relation) == IS_OBJECT) {
				ZEPHIR_CALL_METHOD(&type, &relation, "gettype", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(&type, 0)) {
					if (UNEXPECTED(Z_TYPE_P(&record) != IS_OBJECT)) {
						if (nesting) {
							ZVAL_BOOL(&_8$$6, 1);
						} else {
							ZVAL_BOOL(&_8$$6, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_9, 0, &_8$$6);
						zephir_check_call_status();
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Only objects can be stored as part of belongs-to relations", "phalcon/Mvc/Model.zep", 4841);
						return;
					}
					ZEPHIR_CALL_METHOD(&columns, &relation, "getfields", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedModel, &relation, "getreferencedmodel", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", NULL, 0);
					zephir_check_call_status();
					if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
						if (nesting) {
							ZVAL_BOOL(&_10$$7, 1);
						} else {
							ZVAL_BOOL(&_10$$7, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_11, 0, &_10$$7);
						zephir_check_call_status();
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not implemented", "phalcon/Mvc/Model.zep", 4851);
						return;
					}
					zephir_read_property(&_12$$5, &record, ZEND_STRL("dirtyState"), PH_NOISY_CC | PH_READONLY);
					_13$$5 = !ZEPHIR_IS_LONG_IDENTICAL(&_12$$5, 0);
					if (_13$$5) {
						ZEPHIR_CALL_METHOD(&_14$$5, &record, "save", NULL, 0);
						zephir_check_call_status();
						_13$$5 = !zephir_is_true(&_14$$5);
					}
					if (_13$$5) {
						ZEPHIR_CALL_METHOD(&_15$$8, &record, "getmessages", NULL, 0);
						zephir_check_call_status();
						zephir_is_iterable(&_15$$8, 0, "phalcon/Mvc/Model.zep", 4884);
						if (Z_TYPE_P(&_15$$8) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_15$$8), _16$$8)
							{
								ZEPHIR_INIT_NVAR(&message);
								ZVAL_COPY(&message, _16$$8);
								if (Z_TYPE_P(&message) == IS_OBJECT) {
									ZEPHIR_INIT_NVAR(&_18$$10);
									zephir_create_array(&_18$$10, 1, 0);
									zephir_array_update_string(&_18$$10, SL("model"), &record, PH_COPY | PH_SEPARATE);
									ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_18$$10);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_19, 0, &message);
								zephir_check_call_status();
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &_15$$8, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_17$$8, &_15$$8, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_17$$8)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&message, &_15$$8, "current", NULL, 0);
								zephir_check_call_status();
									if (Z_TYPE_P(&message) == IS_OBJECT) {
										ZEPHIR_INIT_NVAR(&_20$$12);
										zephir_create_array(&_20$$12, 1, 0);
										zephir_array_update_string(&_20$$12, SL("model"), &record, PH_COPY | PH_SEPARATE);
										ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_20$$12);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_19, 0, &message);
									zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, &_15$$8, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&message);
						if (nesting) {
							ZVAL_BOOL(&_21$$8, 1);
						} else {
							ZVAL_BOOL(&_21$$8, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_22, 0, &_21$$8);
						zephir_check_call_status();
						RETURN_MM_BOOL(0);
					}
					ZEPHIR_CALL_METHOD(&_23$$5, &record, "readattribute", NULL, 0, &referencedFields);
					zephir_check_call_status();
					zephir_update_property_zval_zval(this_ptr, &columns, &_23$$5);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, related, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, related, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, related, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&record, related, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_24$$13, &manager, "getrelationbyalias", &_25, 0, &className, &name);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&relation, &_24$$13);
				if (Z_TYPE_P(&relation) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&type, &relation, "gettype", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG(&type, 0)) {
						if (UNEXPECTED(Z_TYPE_P(&record) != IS_OBJECT)) {
							if (nesting) {
								ZVAL_BOOL(&_26$$16, 1);
							} else {
								ZVAL_BOOL(&_26$$16, 0);
							}
							ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_27, 0, &_26$$16);
							zephir_check_call_status();
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Only objects can be stored as part of belongs-to relations", "phalcon/Mvc/Model.zep", 4841);
							return;
						}
						ZEPHIR_CALL_METHOD(&columns, &relation, "getfields", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&referencedModel, &relation, "getreferencedmodel", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", NULL, 0);
						zephir_check_call_status();
						if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
							if (nesting) {
								ZVAL_BOOL(&_28$$17, 1);
							} else {
								ZVAL_BOOL(&_28$$17, 0);
							}
							ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_29, 0, &_28$$17);
							zephir_check_call_status();
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not implemented", "phalcon/Mvc/Model.zep", 4851);
							return;
						}
						zephir_read_property(&_30$$15, &record, ZEND_STRL("dirtyState"), PH_NOISY_CC | PH_READONLY);
						_31$$15 = !ZEPHIR_IS_LONG_IDENTICAL(&_30$$15, 0);
						if (_31$$15) {
							ZEPHIR_CALL_METHOD(&_32$$15, &record, "save", NULL, 0);
							zephir_check_call_status();
							_31$$15 = !zephir_is_true(&_32$$15);
						}
						if (_31$$15) {
							ZEPHIR_CALL_METHOD(&_33$$18, &record, "getmessages", NULL, 0);
							zephir_check_call_status();
							zephir_is_iterable(&_33$$18, 0, "phalcon/Mvc/Model.zep", 4884);
							if (Z_TYPE_P(&_33$$18) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_33$$18), _34$$18)
								{
									ZEPHIR_INIT_NVAR(&message);
									ZVAL_COPY(&message, _34$$18);
									if (Z_TYPE_P(&message) == IS_OBJECT) {
										ZEPHIR_INIT_NVAR(&_36$$20);
										zephir_create_array(&_36$$20, 1, 0);
										zephir_array_update_string(&_36$$20, SL("model"), &record, PH_COPY | PH_SEPARATE);
										ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_36$$20);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_19, 0, &message);
									zephir_check_call_status();
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &_33$$18, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_35$$18, &_33$$18, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_35$$18)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&message, &_33$$18, "current", NULL, 0);
									zephir_check_call_status();
										if (Z_TYPE_P(&message) == IS_OBJECT) {
											ZEPHIR_INIT_NVAR(&_37$$22);
											zephir_create_array(&_37$$22, 1, 0);
											zephir_array_update_string(&_37$$22, SL("model"), &record, PH_COPY | PH_SEPARATE);
											ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_37$$22);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_19, 0, &message);
										zephir_check_call_status();
									ZEPHIR_CALL_METHOD(NULL, &_33$$18, "next", NULL, 0);
									zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&message);
							if (nesting) {
								ZVAL_BOOL(&_38$$18, 1);
							} else {
								ZVAL_BOOL(&_38$$18, 0);
							}
							ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_39, 0, &_38$$18);
							zephir_check_call_status();
							RETURN_MM_BOOL(0);
						}
						ZEPHIR_CALL_METHOD(&_40$$15, &record, "readattribute", NULL, 0, &referencedFields);
						zephir_check_call_status();
						zephir_update_property_zval_zval(this_ptr, &columns, &_40$$15);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, related, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&record);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_MM_BOOL(1);
}

/**
 * Executes internal events after save a record
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Mvc_Model, postSave)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *success_param = NULL, *exists_param = NULL, _0$$4, _1$$5;
	zend_bool success, exists;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_BOOL(success)
		Z_PARAM_BOOL(exists)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &success_param, &exists_param);
	success = zephir_get_boolval(success_param);
	exists = zephir_get_boolval(exists_param);


	if (success) {
		if (exists) {
			ZEPHIR_INIT_VAR(&_0$$4);
			ZVAL_STRING(&_0$$4, "afterUpdate");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_0$$4);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_1$$5);
			ZVAL_STRING(&_1$$5, "afterCreate");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_1$$5);
			zephir_check_call_status();
		}
	}
	RETURN_MM_BOOL(success);
}

/**
 * Save the related records assigned in the has-one/has-many relations
 *
 * @param ModelInterface[] related
 * @return bool
 */
PHP_METHOD(Phalcon_Mvc_Model, postSaveRelatedRecords)
{
	zval _25$$16, _27$$18, _33$$20, _35$$20, _40$$24, _41$$26, _48$$31, _49$$33, _55$$35, _57$$35, _62$$39, _63$$41, _90$$57, _91$$59, _97$$61, _99$$61, _104$$65, _105$$67, _112$$72, _113$$74, _119$$76, _121$$76, _126$$80, _127$$82;
	zend_string *_4;
	zend_ulong _3;
	zend_bool nesting = 0, isThrough = 0, _8$$4, _73$$45;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_10 = NULL, *_12 = NULL, *_14 = NULL, *_17 = NULL, *_26 = NULL, *_29 = NULL, *_31 = NULL, *_32 = NULL, *_43 = NULL, *_51 = NULL, *_53 = NULL, *_54 = NULL, *_65 = NULL, *_67 = NULL, *_71 = NULL, *_75 = NULL, *_77 = NULL, *_80 = NULL, *_93 = NULL, *_95 = NULL, *_96 = NULL, *_107 = NULL, *_115 = NULL, *_117 = NULL, *_118 = NULL, *_129 = NULL, *_131 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, *related, related_sub, className, manager, relation, name, record, message, columns, referencedModel, referencedFields, relatedRecords, value, recordAfter, intermediateModel, intermediateFields, intermediateValue, intermediateModelName, intermediateReferencedFields, existingIntermediateModel, _0, *_1, _2, _134, _5$$3, _7$$4, _18$$4, *_19$$4, _20$$4, _9$$6, _11$$7, _13$$10, _15$$10, _16$$10, _21$$12, _22$$14, *_23$$14, _24$$14, _28$$14, _30$$19, _36$$19, _34$$20, _37$$22, *_38$$22, _39$$22, _42$$22, _44$$27, _45$$29, *_46$$29, _47$$29, _50$$29, _52$$34, _58$$34, _56$$35, _59$$37, *_60$$37, _61$$37, _64$$37, _66$$43, _68$$43, _69$$43, _70$$44, _72$$45, _83$$45, *_84$$45, _85$$45, _74$$47, _76$$48, _78$$49, _79$$51, _81$$51, _82$$51, _86$$53, _87$$55, *_88$$55, _89$$55, _92$$55, _94$$60, _100$$60, _98$$61, _101$$63, *_102$$63, _103$$63, _106$$63, _108$$68, _109$$70, *_110$$70, _111$$70, _114$$70, _116$$75, _122$$75, _120$$76, _123$$78, *_124$$78, _125$$78, _128$$78, _130$$84, _132$$84, _133$$84;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&related_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&referencedModel);
	ZVAL_UNDEF(&referencedFields);
	ZVAL_UNDEF(&relatedRecords);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&recordAfter);
	ZVAL_UNDEF(&intermediateModel);
	ZVAL_UNDEF(&intermediateFields);
	ZVAL_UNDEF(&intermediateValue);
	ZVAL_UNDEF(&intermediateModelName);
	ZVAL_UNDEF(&intermediateReferencedFields);
	ZVAL_UNDEF(&existingIntermediateModel);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_134);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_24$$14);
	ZVAL_UNDEF(&_28$$14);
	ZVAL_UNDEF(&_30$$19);
	ZVAL_UNDEF(&_36$$19);
	ZVAL_UNDEF(&_34$$20);
	ZVAL_UNDEF(&_37$$22);
	ZVAL_UNDEF(&_39$$22);
	ZVAL_UNDEF(&_42$$22);
	ZVAL_UNDEF(&_44$$27);
	ZVAL_UNDEF(&_45$$29);
	ZVAL_UNDEF(&_47$$29);
	ZVAL_UNDEF(&_50$$29);
	ZVAL_UNDEF(&_52$$34);
	ZVAL_UNDEF(&_58$$34);
	ZVAL_UNDEF(&_56$$35);
	ZVAL_UNDEF(&_59$$37);
	ZVAL_UNDEF(&_61$$37);
	ZVAL_UNDEF(&_64$$37);
	ZVAL_UNDEF(&_66$$43);
	ZVAL_UNDEF(&_68$$43);
	ZVAL_UNDEF(&_69$$43);
	ZVAL_UNDEF(&_70$$44);
	ZVAL_UNDEF(&_72$$45);
	ZVAL_UNDEF(&_83$$45);
	ZVAL_UNDEF(&_85$$45);
	ZVAL_UNDEF(&_74$$47);
	ZVAL_UNDEF(&_76$$48);
	ZVAL_UNDEF(&_78$$49);
	ZVAL_UNDEF(&_79$$51);
	ZVAL_UNDEF(&_81$$51);
	ZVAL_UNDEF(&_82$$51);
	ZVAL_UNDEF(&_86$$53);
	ZVAL_UNDEF(&_87$$55);
	ZVAL_UNDEF(&_89$$55);
	ZVAL_UNDEF(&_92$$55);
	ZVAL_UNDEF(&_94$$60);
	ZVAL_UNDEF(&_100$$60);
	ZVAL_UNDEF(&_98$$61);
	ZVAL_UNDEF(&_101$$63);
	ZVAL_UNDEF(&_103$$63);
	ZVAL_UNDEF(&_106$$63);
	ZVAL_UNDEF(&_108$$68);
	ZVAL_UNDEF(&_109$$70);
	ZVAL_UNDEF(&_111$$70);
	ZVAL_UNDEF(&_114$$70);
	ZVAL_UNDEF(&_116$$75);
	ZVAL_UNDEF(&_122$$75);
	ZVAL_UNDEF(&_120$$76);
	ZVAL_UNDEF(&_123$$78);
	ZVAL_UNDEF(&_125$$78);
	ZVAL_UNDEF(&_128$$78);
	ZVAL_UNDEF(&_130$$84);
	ZVAL_UNDEF(&_132$$84);
	ZVAL_UNDEF(&_133$$84);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_33$$20);
	ZVAL_UNDEF(&_35$$20);
	ZVAL_UNDEF(&_40$$24);
	ZVAL_UNDEF(&_41$$26);
	ZVAL_UNDEF(&_48$$31);
	ZVAL_UNDEF(&_49$$33);
	ZVAL_UNDEF(&_55$$35);
	ZVAL_UNDEF(&_57$$35);
	ZVAL_UNDEF(&_62$$39);
	ZVAL_UNDEF(&_63$$41);
	ZVAL_UNDEF(&_90$$57);
	ZVAL_UNDEF(&_91$$59);
	ZVAL_UNDEF(&_97$$61);
	ZVAL_UNDEF(&_99$$61);
	ZVAL_UNDEF(&_104$$65);
	ZVAL_UNDEF(&_105$$67);
	ZVAL_UNDEF(&_112$$72);
	ZVAL_UNDEF(&_113$$74);
	ZVAL_UNDEF(&_119$$76);
	ZVAL_UNDEF(&_121$$76);
	ZVAL_UNDEF(&_126$$80);
	ZVAL_UNDEF(&_127$$82);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(connection, phalcon_db_adapter_adapterinterface_ce)
		Z_PARAM_ZVAL(related)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &connection, &related);


	nesting = 0;
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, this_ptr, 0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_0);
	zephir_is_iterable(related, 0, "phalcon/Mvc/Model.zep", 5147);
	if (Z_TYPE_P(related) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(related), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&name, _4);
			} else {
				ZVAL_LONG(&name, _3);
			}
			ZEPHIR_INIT_NVAR(&record);
			ZVAL_COPY(&record, _1);
			ZEPHIR_CALL_METHOD(&_5$$3, &manager, "getrelationbyalias", &_6, 0, &className, &name);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&relation, &_5$$3);
			if (Z_TYPE_P(&relation) == IS_OBJECT) {
				ZEPHIR_CALL_METHOD(&_7$$4, &relation, "gettype", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(&_7$$4, 0)) {
					continue;
				}
				_8$$4 = Z_TYPE_P(&record) != IS_OBJECT;
				if (_8$$4) {
					_8$$4 = Z_TYPE_P(&record) != IS_ARRAY;
				}
				if (UNEXPECTED(_8$$4)) {
					if (nesting) {
						ZVAL_BOOL(&_9$$6, 1);
					} else {
						ZVAL_BOOL(&_9$$6, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_10, 0, &_9$$6);
					zephir_check_call_status();
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Only objects/arrays can be stored as part of has-many/has-one/has-one-through/has-many-to-many relations", "phalcon/Mvc/Model.zep", 4960);
					return;
				}
				ZEPHIR_CALL_METHOD(&columns, &relation, "getfields", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedModel, &relation, "getreferencedmodel", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", NULL, 0);
				zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
					if (nesting) {
						ZVAL_BOOL(&_11$$7, 1);
					} else {
						ZVAL_BOOL(&_11$$7, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_12, 0, &_11$$7);
					zephir_check_call_status();
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not implemented", "phalcon/Mvc/Model.zep", 4970);
					return;
				}
				if (Z_TYPE_P(&record) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&relatedRecords);
					zephir_create_array(&relatedRecords, 1, 0);
					zephir_array_fast_append(&relatedRecords, &record);
				} else {
					ZEPHIR_CPY_WRT(&relatedRecords, &record);
				}
				ZEPHIR_OBS_NVAR(&value);
				if (UNEXPECTED(!(zephir_fetch_property_zval(&value, this_ptr, &columns, PH_SILENT_CC)))) {
					if (nesting) {
						ZVAL_BOOL(&_13$$10, 1);
					} else {
						ZVAL_BOOL(&_13$$10, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_14, 0, &_13$$10);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_15$$10);
					object_init_ex(&_15$$10, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_NVAR(&_16$$10);
					ZEPHIR_CONCAT_SVS(&_16$$10, "The column '", &columns, "' needs to be present in the model");
					ZEPHIR_CALL_METHOD(NULL, &_15$$10, "__construct", &_17, 30, &_16$$10);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_15$$10, "phalcon/Mvc/Model.zep", 4987);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&_18$$4, &relation, "isthrough", NULL, 0);
				zephir_check_call_status();
				isThrough = zephir_get_boolval(&_18$$4);
				if (isThrough) {
					ZEPHIR_CALL_METHOD(&intermediateModelName, &relation, "getintermediatemodel", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&intermediateFields, &relation, "getintermediatefields", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&intermediateReferencedFields, &relation, "getintermediatereferencedfields", NULL, 0);
					zephir_check_call_status();
				}
				zephir_is_iterable(&relatedRecords, 0, "phalcon/Mvc/Model.zep", 5133);
				if (Z_TYPE_P(&relatedRecords) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relatedRecords), _19$$4)
					{
						ZEPHIR_INIT_NVAR(&recordAfter);
						ZVAL_COPY(&recordAfter, _19$$4);
						if (!(isThrough)) {
							ZEPHIR_CALL_METHOD(NULL, &recordAfter, "writeattribute", NULL, 0, &referencedFields, &value);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_21$$12, &recordAfter, "save", NULL, 0);
						zephir_check_call_status();
						if (!(zephir_is_true(&_21$$12))) {
							ZEPHIR_CALL_METHOD(&_22$$14, &recordAfter, "getmessages", NULL, 0);
							zephir_check_call_status();
							zephir_is_iterable(&_22$$14, 0, "phalcon/Mvc/Model.zep", 5046);
							if (Z_TYPE_P(&_22$$14) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_22$$14), _23$$14)
								{
									ZEPHIR_INIT_NVAR(&message);
									ZVAL_COPY(&message, _23$$14);
									if (Z_TYPE_P(&message) == IS_OBJECT) {
										ZEPHIR_INIT_NVAR(&_25$$16);
										zephir_create_array(&_25$$16, 1, 0);
										zephir_array_update_string(&_25$$16, SL("model"), &recordAfter, PH_COPY | PH_SEPARATE);
										ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_25$$16);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_26, 0, &message);
									zephir_check_call_status();
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &_22$$14, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_24$$14, &_22$$14, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_24$$14)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&message, &_22$$14, "current", NULL, 0);
									zephir_check_call_status();
										if (Z_TYPE_P(&message) == IS_OBJECT) {
											ZEPHIR_INIT_NVAR(&_27$$18);
											zephir_create_array(&_27$$18, 1, 0);
											zephir_array_update_string(&_27$$18, SL("model"), &recordAfter, PH_COPY | PH_SEPARATE);
											ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_27$$18);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_26, 0, &message);
										zephir_check_call_status();
									ZEPHIR_CALL_METHOD(NULL, &_22$$14, "next", NULL, 0);
									zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&message);
							if (nesting) {
								ZVAL_BOOL(&_28$$14, 1);
							} else {
								ZVAL_BOOL(&_28$$14, 0);
							}
							ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_29, 0, &_28$$14);
							zephir_check_call_status();
							RETURN_MM_BOOL(0);
						}
						if (isThrough) {
							ZEPHIR_CALL_METHOD(&_30$$19, &manager, "load", &_31, 0, &intermediateModelName);
							zephir_check_call_status();
							ZEPHIR_CPY_WRT(&intermediateModel, &_30$$19);
							ZEPHIR_CALL_METHOD(&_30$$19, &relation, "gettype", &_32, 0);
							zephir_check_call_status();
							if (ZEPHIR_IS_LONG(&_30$$19, 3)) {
								ZEPHIR_INIT_NVAR(&_33$$20);
								zephir_create_array(&_33$$20, 2, 0);
								ZEPHIR_INIT_NVAR(&_34$$20);
								ZEPHIR_CONCAT_SVS(&_34$$20, "[", &intermediateFields, "] = ?0");
								zephir_array_fast_append(&_33$$20, &_34$$20);
								ZEPHIR_INIT_NVAR(&_35$$20);
								zephir_create_array(&_35$$20, 1, 0);
								zephir_array_fast_append(&_35$$20, &value);
								zephir_array_update_string(&_33$$20, SL("bind"), &_35$$20, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(&existingIntermediateModel, &intermediateModel, "findfirst", NULL, 0, &_33$$20);
								zephir_check_call_status();
								if (zephir_is_true(&existingIntermediateModel)) {
									ZEPHIR_CPY_WRT(&intermediateModel, &existingIntermediateModel);
								}
							}
							ZEPHIR_CALL_METHOD(NULL, &intermediateModel, "writeattribute", NULL, 0, &intermediateFields, &value);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&intermediateValue, &recordAfter, "readattribute", NULL, 0, &referencedFields);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &intermediateModel, "writeattribute", NULL, 0, &intermediateReferencedFields, &intermediateValue);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_36$$19, &intermediateModel, "save", NULL, 0);
							zephir_check_call_status();
							if (!(zephir_is_true(&_36$$19))) {
								ZEPHIR_CALL_METHOD(&_37$$22, &intermediateModel, "getmessages", NULL, 0);
								zephir_check_call_status();
								zephir_is_iterable(&_37$$22, 0, "phalcon/Mvc/Model.zep", 5127);
								if (Z_TYPE_P(&_37$$22) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_37$$22), _38$$22)
									{
										ZEPHIR_INIT_NVAR(&message);
										ZVAL_COPY(&message, _38$$22);
										if (Z_TYPE_P(&message) == IS_OBJECT) {
											ZEPHIR_INIT_NVAR(&_40$$24);
											zephir_create_array(&_40$$24, 1, 0);
											zephir_array_update_string(&_40$$24, SL("model"), &intermediateModel, PH_COPY | PH_SEPARATE);
											ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_40$$24);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_26, 0, &message);
										zephir_check_call_status();
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &_37$$22, "rewind", NULL, 0);
									zephir_check_call_status();
									while (1) {
										ZEPHIR_CALL_METHOD(&_39$$22, &_37$$22, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_39$$22)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&message, &_37$$22, "current", NULL, 0);
										zephir_check_call_status();
											if (Z_TYPE_P(&message) == IS_OBJECT) {
												ZEPHIR_INIT_NVAR(&_41$$26);
												zephir_create_array(&_41$$26, 1, 0);
												zephir_array_update_string(&_41$$26, SL("model"), &intermediateModel, PH_COPY | PH_SEPARATE);
												ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_41$$26);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_26, 0, &message);
											zephir_check_call_status();
										ZEPHIR_CALL_METHOD(NULL, &_37$$22, "next", NULL, 0);
										zephir_check_call_status();
									}
								}
								ZEPHIR_INIT_NVAR(&message);
								if (nesting) {
									ZVAL_BOOL(&_42$$22, 1);
								} else {
									ZVAL_BOOL(&_42$$22, 0);
								}
								ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_43, 0, &_42$$22);
								zephir_check_call_status();
								RETURN_MM_BOOL(0);
							}
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_20$$4, &relatedRecords, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_20$$4)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&recordAfter, &relatedRecords, "current", NULL, 0);
						zephir_check_call_status();
							if (!(isThrough)) {
								ZEPHIR_CALL_METHOD(NULL, &recordAfter, "writeattribute", NULL, 0, &referencedFields, &value);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_44$$27, &recordAfter, "save", NULL, 0);
							zephir_check_call_status();
							if (!(zephir_is_true(&_44$$27))) {
								ZEPHIR_CALL_METHOD(&_45$$29, &recordAfter, "getmessages", NULL, 0);
								zephir_check_call_status();
								zephir_is_iterable(&_45$$29, 0, "phalcon/Mvc/Model.zep", 5046);
								if (Z_TYPE_P(&_45$$29) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_45$$29), _46$$29)
									{
										ZEPHIR_INIT_NVAR(&message);
										ZVAL_COPY(&message, _46$$29);
										if (Z_TYPE_P(&message) == IS_OBJECT) {
											ZEPHIR_INIT_NVAR(&_48$$31);
											zephir_create_array(&_48$$31, 1, 0);
											zephir_array_update_string(&_48$$31, SL("model"), &recordAfter, PH_COPY | PH_SEPARATE);
											ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_48$$31);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_26, 0, &message);
										zephir_check_call_status();
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &_45$$29, "rewind", NULL, 0);
									zephir_check_call_status();
									while (1) {
										ZEPHIR_CALL_METHOD(&_47$$29, &_45$$29, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_47$$29)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&message, &_45$$29, "current", NULL, 0);
										zephir_check_call_status();
											if (Z_TYPE_P(&message) == IS_OBJECT) {
												ZEPHIR_INIT_NVAR(&_49$$33);
												zephir_create_array(&_49$$33, 1, 0);
												zephir_array_update_string(&_49$$33, SL("model"), &recordAfter, PH_COPY | PH_SEPARATE);
												ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_49$$33);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_26, 0, &message);
											zephir_check_call_status();
										ZEPHIR_CALL_METHOD(NULL, &_45$$29, "next", NULL, 0);
										zephir_check_call_status();
									}
								}
								ZEPHIR_INIT_NVAR(&message);
								if (nesting) {
									ZVAL_BOOL(&_50$$29, 1);
								} else {
									ZVAL_BOOL(&_50$$29, 0);
								}
								ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_51, 0, &_50$$29);
								zephir_check_call_status();
								RETURN_MM_BOOL(0);
							}
							if (isThrough) {
								ZEPHIR_CALL_METHOD(&_52$$34, &manager, "load", &_53, 0, &intermediateModelName);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&intermediateModel, &_52$$34);
								ZEPHIR_CALL_METHOD(&_52$$34, &relation, "gettype", &_54, 0);
								zephir_check_call_status();
								if (ZEPHIR_IS_LONG(&_52$$34, 3)) {
									ZEPHIR_INIT_NVAR(&_55$$35);
									zephir_create_array(&_55$$35, 2, 0);
									ZEPHIR_INIT_NVAR(&_56$$35);
									ZEPHIR_CONCAT_SVS(&_56$$35, "[", &intermediateFields, "] = ?0");
									zephir_array_fast_append(&_55$$35, &_56$$35);
									ZEPHIR_INIT_NVAR(&_57$$35);
									zephir_create_array(&_57$$35, 1, 0);
									zephir_array_fast_append(&_57$$35, &value);
									zephir_array_update_string(&_55$$35, SL("bind"), &_57$$35, PH_COPY | PH_SEPARATE);
									ZEPHIR_CALL_METHOD(&existingIntermediateModel, &intermediateModel, "findfirst", NULL, 0, &_55$$35);
									zephir_check_call_status();
									if (zephir_is_true(&existingIntermediateModel)) {
										ZEPHIR_CPY_WRT(&intermediateModel, &existingIntermediateModel);
									}
								}
								ZEPHIR_CALL_METHOD(NULL, &intermediateModel, "writeattribute", NULL, 0, &intermediateFields, &value);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&intermediateValue, &recordAfter, "readattribute", NULL, 0, &referencedFields);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, &intermediateModel, "writeattribute", NULL, 0, &intermediateReferencedFields, &intermediateValue);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&_58$$34, &intermediateModel, "save", NULL, 0);
								zephir_check_call_status();
								if (!(zephir_is_true(&_58$$34))) {
									ZEPHIR_CALL_METHOD(&_59$$37, &intermediateModel, "getmessages", NULL, 0);
									zephir_check_call_status();
									zephir_is_iterable(&_59$$37, 0, "phalcon/Mvc/Model.zep", 5127);
									if (Z_TYPE_P(&_59$$37) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_59$$37), _60$$37)
										{
											ZEPHIR_INIT_NVAR(&message);
											ZVAL_COPY(&message, _60$$37);
											if (Z_TYPE_P(&message) == IS_OBJECT) {
												ZEPHIR_INIT_NVAR(&_62$$39);
												zephir_create_array(&_62$$39, 1, 0);
												zephir_array_update_string(&_62$$39, SL("model"), &intermediateModel, PH_COPY | PH_SEPARATE);
												ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_62$$39);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_26, 0, &message);
											zephir_check_call_status();
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, &_59$$37, "rewind", NULL, 0);
										zephir_check_call_status();
										while (1) {
											ZEPHIR_CALL_METHOD(&_61$$37, &_59$$37, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_61$$37)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&message, &_59$$37, "current", NULL, 0);
											zephir_check_call_status();
												if (Z_TYPE_P(&message) == IS_OBJECT) {
													ZEPHIR_INIT_NVAR(&_63$$41);
													zephir_create_array(&_63$$41, 1, 0);
													zephir_array_update_string(&_63$$41, SL("model"), &intermediateModel, PH_COPY | PH_SEPARATE);
													ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_63$$41);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_26, 0, &message);
												zephir_check_call_status();
											ZEPHIR_CALL_METHOD(NULL, &_59$$37, "next", NULL, 0);
											zephir_check_call_status();
										}
									}
									ZEPHIR_INIT_NVAR(&message);
									if (nesting) {
										ZVAL_BOOL(&_64$$37, 1);
									} else {
										ZVAL_BOOL(&_64$$37, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_65, 0, &_64$$37);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
							}
						ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&recordAfter);
			} else {
				if (UNEXPECTED(Z_TYPE_P(&record) != IS_ARRAY)) {
					if (nesting) {
						ZVAL_BOOL(&_66$$43, 1);
					} else {
						ZVAL_BOOL(&_66$$43, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_67, 0, &_66$$43);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_68$$43);
					object_init_ex(&_68$$43, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_NVAR(&_69$$43);
					ZEPHIR_CONCAT_SVSVS(&_69$$43, "There are no defined relations for the model '", &className, "' using alias '", &name, "'");
					ZEPHIR_CALL_METHOD(NULL, &_68$$43, "__construct", &_17, 30, &_69$$43);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_68$$43, "phalcon/Mvc/Model.zep", 5139);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, related, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, related, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, related, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&record, related, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_70$$44, &manager, "getrelationbyalias", &_71, 0, &className, &name);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&relation, &_70$$44);
				if (Z_TYPE_P(&relation) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&_72$$45, &relation, "gettype", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG(&_72$$45, 0)) {
						continue;
					}
					_73$$45 = Z_TYPE_P(&record) != IS_OBJECT;
					if (_73$$45) {
						_73$$45 = Z_TYPE_P(&record) != IS_ARRAY;
					}
					if (UNEXPECTED(_73$$45)) {
						if (nesting) {
							ZVAL_BOOL(&_74$$47, 1);
						} else {
							ZVAL_BOOL(&_74$$47, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_75, 0, &_74$$47);
						zephir_check_call_status();
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Only objects/arrays can be stored as part of has-many/has-one/has-one-through/has-many-to-many relations", "phalcon/Mvc/Model.zep", 4960);
						return;
					}
					ZEPHIR_CALL_METHOD(&columns, &relation, "getfields", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedModel, &relation, "getreferencedmodel", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", NULL, 0);
					zephir_check_call_status();
					if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
						if (nesting) {
							ZVAL_BOOL(&_76$$48, 1);
						} else {
							ZVAL_BOOL(&_76$$48, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_77, 0, &_76$$48);
						zephir_check_call_status();
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not implemented", "phalcon/Mvc/Model.zep", 4970);
						return;
					}
					if (Z_TYPE_P(&record) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_78$$49);
						zephir_create_array(&_78$$49, 1, 0);
						zephir_array_fast_append(&_78$$49, &record);
						ZEPHIR_CPY_WRT(&relatedRecords, &_78$$49);
					} else {
						ZEPHIR_CPY_WRT(&relatedRecords, &record);
					}
					ZEPHIR_OBS_NVAR(&value);
					if (UNEXPECTED(!(zephir_fetch_property_zval(&value, this_ptr, &columns, PH_SILENT_CC)))) {
						if (nesting) {
							ZVAL_BOOL(&_79$$51, 1);
						} else {
							ZVAL_BOOL(&_79$$51, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_80, 0, &_79$$51);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_81$$51);
						object_init_ex(&_81$$51, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_82$$51);
						ZEPHIR_CONCAT_SVS(&_82$$51, "The column '", &columns, "' needs to be present in the model");
						ZEPHIR_CALL_METHOD(NULL, &_81$$51, "__construct", &_17, 30, &_82$$51);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_81$$51, "phalcon/Mvc/Model.zep", 4987);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_83$$45, &relation, "isthrough", NULL, 0);
					zephir_check_call_status();
					isThrough = zephir_get_boolval(&_83$$45);
					if (isThrough) {
						ZEPHIR_CALL_METHOD(&intermediateModelName, &relation, "getintermediatemodel", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&intermediateFields, &relation, "getintermediatefields", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&intermediateReferencedFields, &relation, "getintermediatereferencedfields", NULL, 0);
						zephir_check_call_status();
					}
					zephir_is_iterable(&relatedRecords, 0, "phalcon/Mvc/Model.zep", 5133);
					if (Z_TYPE_P(&relatedRecords) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relatedRecords), _84$$45)
						{
							ZEPHIR_INIT_NVAR(&recordAfter);
							ZVAL_COPY(&recordAfter, _84$$45);
							if (!(isThrough)) {
								ZEPHIR_CALL_METHOD(NULL, &recordAfter, "writeattribute", NULL, 0, &referencedFields, &value);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_86$$53, &recordAfter, "save", NULL, 0);
							zephir_check_call_status();
							if (!(zephir_is_true(&_86$$53))) {
								ZEPHIR_CALL_METHOD(&_87$$55, &recordAfter, "getmessages", NULL, 0);
								zephir_check_call_status();
								zephir_is_iterable(&_87$$55, 0, "phalcon/Mvc/Model.zep", 5046);
								if (Z_TYPE_P(&_87$$55) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_87$$55), _88$$55)
									{
										ZEPHIR_INIT_NVAR(&message);
										ZVAL_COPY(&message, _88$$55);
										if (Z_TYPE_P(&message) == IS_OBJECT) {
											ZEPHIR_INIT_NVAR(&_90$$57);
											zephir_create_array(&_90$$57, 1, 0);
											zephir_array_update_string(&_90$$57, SL("model"), &recordAfter, PH_COPY | PH_SEPARATE);
											ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_90$$57);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_26, 0, &message);
										zephir_check_call_status();
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &_87$$55, "rewind", NULL, 0);
									zephir_check_call_status();
									while (1) {
										ZEPHIR_CALL_METHOD(&_89$$55, &_87$$55, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_89$$55)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&message, &_87$$55, "current", NULL, 0);
										zephir_check_call_status();
											if (Z_TYPE_P(&message) == IS_OBJECT) {
												ZEPHIR_INIT_NVAR(&_91$$59);
												zephir_create_array(&_91$$59, 1, 0);
												zephir_array_update_string(&_91$$59, SL("model"), &recordAfter, PH_COPY | PH_SEPARATE);
												ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_91$$59);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_26, 0, &message);
											zephir_check_call_status();
										ZEPHIR_CALL_METHOD(NULL, &_87$$55, "next", NULL, 0);
										zephir_check_call_status();
									}
								}
								ZEPHIR_INIT_NVAR(&message);
								if (nesting) {
									ZVAL_BOOL(&_92$$55, 1);
								} else {
									ZVAL_BOOL(&_92$$55, 0);
								}
								ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_93, 0, &_92$$55);
								zephir_check_call_status();
								RETURN_MM_BOOL(0);
							}
							if (isThrough) {
								ZEPHIR_CALL_METHOD(&_94$$60, &manager, "load", &_95, 0, &intermediateModelName);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&intermediateModel, &_94$$60);
								ZEPHIR_CALL_METHOD(&_94$$60, &relation, "gettype", &_96, 0);
								zephir_check_call_status();
								if (ZEPHIR_IS_LONG(&_94$$60, 3)) {
									ZEPHIR_INIT_NVAR(&_97$$61);
									zephir_create_array(&_97$$61, 2, 0);
									ZEPHIR_INIT_NVAR(&_98$$61);
									ZEPHIR_CONCAT_SVS(&_98$$61, "[", &intermediateFields, "] = ?0");
									zephir_array_fast_append(&_97$$61, &_98$$61);
									ZEPHIR_INIT_NVAR(&_99$$61);
									zephir_create_array(&_99$$61, 1, 0);
									zephir_array_fast_append(&_99$$61, &value);
									zephir_array_update_string(&_97$$61, SL("bind"), &_99$$61, PH_COPY | PH_SEPARATE);
									ZEPHIR_CALL_METHOD(&existingIntermediateModel, &intermediateModel, "findfirst", NULL, 0, &_97$$61);
									zephir_check_call_status();
									if (zephir_is_true(&existingIntermediateModel)) {
										ZEPHIR_CPY_WRT(&intermediateModel, &existingIntermediateModel);
									}
								}
								ZEPHIR_CALL_METHOD(NULL, &intermediateModel, "writeattribute", NULL, 0, &intermediateFields, &value);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&intermediateValue, &recordAfter, "readattribute", NULL, 0, &referencedFields);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, &intermediateModel, "writeattribute", NULL, 0, &intermediateReferencedFields, &intermediateValue);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&_100$$60, &intermediateModel, "save", NULL, 0);
								zephir_check_call_status();
								if (!(zephir_is_true(&_100$$60))) {
									ZEPHIR_CALL_METHOD(&_101$$63, &intermediateModel, "getmessages", NULL, 0);
									zephir_check_call_status();
									zephir_is_iterable(&_101$$63, 0, "phalcon/Mvc/Model.zep", 5127);
									if (Z_TYPE_P(&_101$$63) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_101$$63), _102$$63)
										{
											ZEPHIR_INIT_NVAR(&message);
											ZVAL_COPY(&message, _102$$63);
											if (Z_TYPE_P(&message) == IS_OBJECT) {
												ZEPHIR_INIT_NVAR(&_104$$65);
												zephir_create_array(&_104$$65, 1, 0);
												zephir_array_update_string(&_104$$65, SL("model"), &intermediateModel, PH_COPY | PH_SEPARATE);
												ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_104$$65);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_26, 0, &message);
											zephir_check_call_status();
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, &_101$$63, "rewind", NULL, 0);
										zephir_check_call_status();
										while (1) {
											ZEPHIR_CALL_METHOD(&_103$$63, &_101$$63, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_103$$63)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&message, &_101$$63, "current", NULL, 0);
											zephir_check_call_status();
												if (Z_TYPE_P(&message) == IS_OBJECT) {
													ZEPHIR_INIT_NVAR(&_105$$67);
													zephir_create_array(&_105$$67, 1, 0);
													zephir_array_update_string(&_105$$67, SL("model"), &intermediateModel, PH_COPY | PH_SEPARATE);
													ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_105$$67);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_26, 0, &message);
												zephir_check_call_status();
											ZEPHIR_CALL_METHOD(NULL, &_101$$63, "next", NULL, 0);
											zephir_check_call_status();
										}
									}
									ZEPHIR_INIT_NVAR(&message);
									if (nesting) {
										ZVAL_BOOL(&_106$$63, 1);
									} else {
										ZVAL_BOOL(&_106$$63, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_107, 0, &_106$$63);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_85$$45, &relatedRecords, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_85$$45)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&recordAfter, &relatedRecords, "current", NULL, 0);
							zephir_check_call_status();
								if (!(isThrough)) {
									ZEPHIR_CALL_METHOD(NULL, &recordAfter, "writeattribute", NULL, 0, &referencedFields, &value);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_108$$68, &recordAfter, "save", NULL, 0);
								zephir_check_call_status();
								if (!(zephir_is_true(&_108$$68))) {
									ZEPHIR_CALL_METHOD(&_109$$70, &recordAfter, "getmessages", NULL, 0);
									zephir_check_call_status();
									zephir_is_iterable(&_109$$70, 0, "phalcon/Mvc/Model.zep", 5046);
									if (Z_TYPE_P(&_109$$70) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_109$$70), _110$$70)
										{
											ZEPHIR_INIT_NVAR(&message);
											ZVAL_COPY(&message, _110$$70);
											if (Z_TYPE_P(&message) == IS_OBJECT) {
												ZEPHIR_INIT_NVAR(&_112$$72);
												zephir_create_array(&_112$$72, 1, 0);
												zephir_array_update_string(&_112$$72, SL("model"), &recordAfter, PH_COPY | PH_SEPARATE);
												ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_112$$72);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_26, 0, &message);
											zephir_check_call_status();
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, &_109$$70, "rewind", NULL, 0);
										zephir_check_call_status();
										while (1) {
											ZEPHIR_CALL_METHOD(&_111$$70, &_109$$70, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_111$$70)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&message, &_109$$70, "current", NULL, 0);
											zephir_check_call_status();
												if (Z_TYPE_P(&message) == IS_OBJECT) {
													ZEPHIR_INIT_NVAR(&_113$$74);
													zephir_create_array(&_113$$74, 1, 0);
													zephir_array_update_string(&_113$$74, SL("model"), &recordAfter, PH_COPY | PH_SEPARATE);
													ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_113$$74);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_26, 0, &message);
												zephir_check_call_status();
											ZEPHIR_CALL_METHOD(NULL, &_109$$70, "next", NULL, 0);
											zephir_check_call_status();
										}
									}
									ZEPHIR_INIT_NVAR(&message);
									if (nesting) {
										ZVAL_BOOL(&_114$$70, 1);
									} else {
										ZVAL_BOOL(&_114$$70, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_115, 0, &_114$$70);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
								if (isThrough) {
									ZEPHIR_CALL_METHOD(&_116$$75, &manager, "load", &_117, 0, &intermediateModelName);
									zephir_check_call_status();
									ZEPHIR_CPY_WRT(&intermediateModel, &_116$$75);
									ZEPHIR_CALL_METHOD(&_116$$75, &relation, "gettype", &_118, 0);
									zephir_check_call_status();
									if (ZEPHIR_IS_LONG(&_116$$75, 3)) {
										ZEPHIR_INIT_NVAR(&_119$$76);
										zephir_create_array(&_119$$76, 2, 0);
										ZEPHIR_INIT_NVAR(&_120$$76);
										ZEPHIR_CONCAT_SVS(&_120$$76, "[", &intermediateFields, "] = ?0");
										zephir_array_fast_append(&_119$$76, &_120$$76);
										ZEPHIR_INIT_NVAR(&_121$$76);
										zephir_create_array(&_121$$76, 1, 0);
										zephir_array_fast_append(&_121$$76, &value);
										zephir_array_update_string(&_119$$76, SL("bind"), &_121$$76, PH_COPY | PH_SEPARATE);
										ZEPHIR_CALL_METHOD(&existingIntermediateModel, &intermediateModel, "findfirst", NULL, 0, &_119$$76);
										zephir_check_call_status();
										if (zephir_is_true(&existingIntermediateModel)) {
											ZEPHIR_CPY_WRT(&intermediateModel, &existingIntermediateModel);
										}
									}
									ZEPHIR_CALL_METHOD(NULL, &intermediateModel, "writeattribute", NULL, 0, &intermediateFields, &value);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&intermediateValue, &recordAfter, "readattribute", NULL, 0, &referencedFields);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(NULL, &intermediateModel, "writeattribute", NULL, 0, &intermediateReferencedFields, &intermediateValue);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&_122$$75, &intermediateModel, "save", NULL, 0);
									zephir_check_call_status();
									if (!(zephir_is_true(&_122$$75))) {
										ZEPHIR_CALL_METHOD(&_123$$78, &intermediateModel, "getmessages", NULL, 0);
										zephir_check_call_status();
										zephir_is_iterable(&_123$$78, 0, "phalcon/Mvc/Model.zep", 5127);
										if (Z_TYPE_P(&_123$$78) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_123$$78), _124$$78)
											{
												ZEPHIR_INIT_NVAR(&message);
												ZVAL_COPY(&message, _124$$78);
												if (Z_TYPE_P(&message) == IS_OBJECT) {
													ZEPHIR_INIT_NVAR(&_126$$80);
													zephir_create_array(&_126$$80, 1, 0);
													zephir_array_update_string(&_126$$80, SL("model"), &intermediateModel, PH_COPY | PH_SEPARATE);
													ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_126$$80);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_26, 0, &message);
												zephir_check_call_status();
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, &_123$$78, "rewind", NULL, 0);
											zephir_check_call_status();
											while (1) {
												ZEPHIR_CALL_METHOD(&_125$$78, &_123$$78, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_125$$78)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&message, &_123$$78, "current", NULL, 0);
												zephir_check_call_status();
													if (Z_TYPE_P(&message) == IS_OBJECT) {
														ZEPHIR_INIT_NVAR(&_127$$82);
														zephir_create_array(&_127$$82, 1, 0);
														zephir_array_update_string(&_127$$82, SL("model"), &intermediateModel, PH_COPY | PH_SEPARATE);
														ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_127$$82);
														zephir_check_call_status();
													}
													ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_26, 0, &message);
													zephir_check_call_status();
												ZEPHIR_CALL_METHOD(NULL, &_123$$78, "next", NULL, 0);
												zephir_check_call_status();
											}
										}
										ZEPHIR_INIT_NVAR(&message);
										if (nesting) {
											ZVAL_BOOL(&_128$$78, 1);
										} else {
											ZVAL_BOOL(&_128$$78, 0);
										}
										ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_129, 0, &_128$$78);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
								}
							ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&recordAfter);
				} else {
					if (UNEXPECTED(Z_TYPE_P(&record) != IS_ARRAY)) {
						if (nesting) {
							ZVAL_BOOL(&_130$$84, 1);
						} else {
							ZVAL_BOOL(&_130$$84, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_131, 0, &_130$$84);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_132$$84);
						object_init_ex(&_132$$84, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_133$$84);
						ZEPHIR_CONCAT_SVSVS(&_133$$84, "There are no defined relations for the model '", &className, "' using alias '", &name, "'");
						ZEPHIR_CALL_METHOD(NULL, &_132$$84, "__construct", &_17, 30, &_133$$84);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_132$$84, "phalcon/Mvc/Model.zep", 5139);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			ZEPHIR_CALL_METHOD(NULL, related, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&record);
	ZEPHIR_INIT_NVAR(&name);
	if (nesting) {
		ZVAL_BOOL(&_134, 1);
	} else {
		ZVAL_BOOL(&_134, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, connection, "commit", NULL, 0, &_134);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);
}

/**
 * Sets a list of attributes that must be skipped from the
 * generated UPDATE statement
 *
 *```php
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         $this->allowEmptyStringValues(
 *             [
 *                 "name",
 *             ]
 *         );
 *     }
 * }
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model, allowEmptyStringValues)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, __$true, keysAttributes, attribute, *_0, _1, _2;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&keysAttributes);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);


	ZEPHIR_INIT_VAR(&keysAttributes);
	array_init(&keysAttributes);
	zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model.zep", 5180);
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _0)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _0);
			zephir_array_update_zval(&keysAttributes, &attribute, &__$true, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &attributes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attribute, &attributes, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_update_zval(&keysAttributes, &attribute, &__$true, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&attribute);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_2, "setemptystringattributes", NULL, 0, this_ptr, &keysAttributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Cancel the current operation
 */
PHP_METHOD(Phalcon_Mvc_Model, cancelOperation)
{
	zval _0, _1$$3, _2$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("operationMade"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG(&_0, 3)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "notDeleted");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_1$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "notSaved");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_2$$4);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Setup a reverse 1-1 or n-1 relation between two models
 *
 *```php
 * class RobotsParts extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         $this->belongsTo(
 *             "robots_id",
 *             Robots::class,
 *             "id"
 *         );
 *     }
 * }
 *```
 *
 * @param array|null options = [
 *     'reusable' => false,
 *     'alias' => 'someAlias',
 *     'foreignKey' => [
 *         'message' => null,
 *         'allowNulls' => false,
 *         'action' => null
 *     ],
 *     'params' => [
 *         'conditions' => ''
 *         'columns' => '',
 *         'bind' => [],
 *         'bindTypes => [],
 *         'order' => '',
 *         'limit' => 10,
 *         'offset' => 5,
 *         'group' => 'name, status',
 *         'for_updated' => false,
 *         'shared_lock' => false,
 *         'cache' => [
 *             'lifetime' => 3600,
 *             'key' => 'my-find-key'
 *         ],
 *         'hydration' => null
 *     ]
 * ]
 */
PHP_METHOD(Phalcon_Mvc_Model, belongsTo)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval referenceModel;
	zval *fields, fields_sub, *referenceModel_param = NULL, *referencedFields, referencedFields_sub, *options = NULL, options_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&referenceModel);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_ZVAL(fields)
		Z_PARAM_STR(referenceModel)
		Z_PARAM_ZVAL(referencedFields)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &fields, &referenceModel_param, &referencedFields, &options);
	if (UNEXPECTED(Z_TYPE_P(referenceModel_param) != IS_STRING && Z_TYPE_P(referenceModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceModel' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referenceModel_param) == IS_STRING)) {
		zephir_get_strval(&referenceModel, referenceModel_param);
	} else {
		ZEPHIR_INIT_VAR(&referenceModel);
	}
	if (!options) {
		options = &options_sub;
		options = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addbelongsto", NULL, 0, this_ptr, fields, &referenceModel, referencedFields, options);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * shared prepare query logic for find and findFirst method
 */
PHP_METHOD(Phalcon_Mvc_Model, getPreparedQuery)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *params, params_sub, *limit = NULL, limit_sub, __$null, builder, bindParams, bindTypes, transaction, cache, manager, query, container, _1, _2, _3$$5, _4$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params_sub);
	ZVAL_UNDEF(&limit_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&builder);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&transaction);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(params)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(limit)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &params, &limit);
	if (!limit) {
		limit = &limit_sub;
		limit = &__$null;
	}


	ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_ce, "getdefault", &_0, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "modelsManager");
	ZEPHIR_CALL_METHOD(&_1, &container, "getshared", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_1);
	ZEPHIR_CALL_METHOD(&_1, &manager, "createbuilder", NULL, 0, params);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&builder, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_get_called_class(&_2);
	ZEPHIR_CALL_METHOD(NULL, &builder, "from", NULL, 0, &_2);
	zephir_check_call_status();
	if (Z_TYPE_P(limit) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, &builder, "limit", NULL, 0, limit);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_1, &builder, "getquery", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&query, &_1);
	ZEPHIR_OBS_VAR(&bindParams);
	if (zephir_array_isset_string_fetch(&bindParams, params, SL("bind"), 0)) {
		if (Z_TYPE_P(&bindParams) == IS_ARRAY) {
			ZVAL_BOOL(&_3$$5, 1);
			ZEPHIR_CALL_METHOD(NULL, &query, "setbindparams", NULL, 0, &bindParams, &_3$$5);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_VAR(&bindTypes);
		if (zephir_array_isset_string_fetch(&bindTypes, params, SL("bindTypes"), 0)) {
			if (Z_TYPE_P(&bindTypes) == IS_ARRAY) {
				ZVAL_BOOL(&_4$$7, 1);
				ZEPHIR_CALL_METHOD(NULL, &query, "setbindtypes", NULL, 0, &bindTypes, &_4$$7);
				zephir_check_call_status();
			}
		}
	}
	ZEPHIR_OBS_VAR(&transaction);
	if (zephir_array_isset_string_fetch(&transaction, params, SL("transaction"), 0)) {
		if (zephir_instance_of_ev(&transaction, phalcon_mvc_model_transactioninterface_ce)) {
			ZEPHIR_CALL_METHOD(NULL, &query, "settransaction", NULL, 0, &transaction);
			zephir_check_call_status();
		}
	}
	ZEPHIR_OBS_VAR(&cache);
	if (zephir_array_isset_string_fetch(&cache, params, SL("cache"), 0)) {
		ZEPHIR_CALL_METHOD(NULL, &query, "cache", NULL, 0, &cache);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&query);
}

/**
 * Setup a 1-n relation between two models
 *
 *```php
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         $this->hasMany(
 *             "id",
 *             RobotsParts::class,
 *             "robots_id"
 *         );
 *     }
 * }
 *```
 *
 * @param array|null options = [
 *     'reusable' => false,
 *     'alias' => 'someAlias',
 *     'foreignKey' => [
 *         'message' => null,
 *         'allowNulls' => false,
 *         'action' => null
 *     ],
 *     'params' => [
 *         'conditions' => ''
 *         'columns' => '',
 *         'bind' => [],
 *         'bindTypes => [],
 *         'order' => '',
 *         'limit' => 10,
 *         'offset' => 5,
 *         'group' => 'name, status',
 *         'for_updated' => false,
 *         'shared_lock' => false,
 *         'cache' => [
 *             'lifetime' => 3600,
 *             'key' => 'my-find-key'
 *         ],
 *         'hydration' => null
 *     ]
 * ]
 */
PHP_METHOD(Phalcon_Mvc_Model, hasMany)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval referenceModel;
	zval *fields, fields_sub, *referenceModel_param = NULL, *referencedFields, referencedFields_sub, *options = NULL, options_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&referenceModel);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_ZVAL(fields)
		Z_PARAM_STR(referenceModel)
		Z_PARAM_ZVAL(referencedFields)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &fields, &referenceModel_param, &referencedFields, &options);
	if (UNEXPECTED(Z_TYPE_P(referenceModel_param) != IS_STRING && Z_TYPE_P(referenceModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceModel' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referenceModel_param) == IS_STRING)) {
		zephir_get_strval(&referenceModel, referenceModel_param);
	} else {
		ZEPHIR_INIT_VAR(&referenceModel);
	}
	if (!options) {
		options = &options_sub;
		options = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addhasmany", NULL, 0, this_ptr, fields, &referenceModel, referencedFields, options);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Setup an n-n relation between two models, through an intermediate
 * relation
 *
 *```php
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         // Setup a many-to-many relation to Parts through RobotsParts
 *         $this->hasManyToMany(
 *             "id",
 *             RobotsParts::class,
 *             "robots_id",
 *             "parts_id",
 *             Parts::class,
 *             "id",
 *         );
 *     }
 * }
 *```
 *
 * @param string|array fields
 * @param string intermediateModel
 * @param string|array intermediateFields
 * @param string|array intermediateReferencedFields
 * @param string referenceModel
 * @param string|array referencedFields
 * @param array options = [
 *     'reusable' => false,
 *     'alias' => 'someAlias',
 *     'foreignKey' => [
 *         'message' => null,
 *         'allowNulls' => false,
 *         'action' => null
 *     ],
 *     'params' => [
 *         'conditions' => ''
 *         'columns' => '',
 *         'bind' => [],
 *         'bindTypes => [],
 *         'order' => '',
 *         'limit' => 10,
 *         'offset' => 5,
 *         'group' => 'name, status',
 *         'for_updated' => false,
 *         'shared_lock' => false,
 *         'cache' => [
 *             'lifetime' => 3600,
 *             'key' => 'my-find-key'
 *         ],
 *         'hydration' => null
 *     ]
 * ]
 */
PHP_METHOD(Phalcon_Mvc_Model, hasManyToMany)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval intermediateModel, referenceModel;
	zval *fields, fields_sub, *intermediateModel_param = NULL, *intermediateFields, intermediateFields_sub, *intermediateReferencedFields, intermediateReferencedFields_sub, *referenceModel_param = NULL, *referencedFields, referencedFields_sub, *options = NULL, options_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&intermediateFields_sub);
	ZVAL_UNDEF(&intermediateReferencedFields_sub);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&intermediateModel);
	ZVAL_UNDEF(&referenceModel);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(6, 7)
		Z_PARAM_ZVAL(fields)
		Z_PARAM_STR(intermediateModel)
		Z_PARAM_ZVAL(intermediateFields)
		Z_PARAM_ZVAL(intermediateReferencedFields)
		Z_PARAM_STR(referenceModel)
		Z_PARAM_ZVAL(referencedFields)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 6, 1, &fields, &intermediateModel_param, &intermediateFields, &intermediateReferencedFields, &referenceModel_param, &referencedFields, &options);
	if (UNEXPECTED(Z_TYPE_P(intermediateModel_param) != IS_STRING && Z_TYPE_P(intermediateModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'intermediateModel' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(intermediateModel_param) == IS_STRING)) {
		zephir_get_strval(&intermediateModel, intermediateModel_param);
	} else {
		ZEPHIR_INIT_VAR(&intermediateModel);
	}
	if (UNEXPECTED(Z_TYPE_P(referenceModel_param) != IS_STRING && Z_TYPE_P(referenceModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceModel' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referenceModel_param) == IS_STRING)) {
		zephir_get_strval(&referenceModel, referenceModel_param);
	} else {
		ZEPHIR_INIT_VAR(&referenceModel);
	}
	if (!options) {
		options = &options_sub;
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addhasmanytomany", NULL, 0, this_ptr, fields, &intermediateModel, intermediateFields, intermediateReferencedFields, &referenceModel, referencedFields, options);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Setup a 1-1 relation between two models
 *
 *```php
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         $this->hasOne(
 *             "id",
 *             RobotsDescription::class,
 *             "robots_id"
 *         );
 *     }
 * }
 *```
 *
 * @param array|null options = [
 *     'reusable' => false,
 *     'alias' => 'someAlias',
 *     'foreignKey' => [
 *         'message' => null,
 *         'allowNulls' => false,
 *         'action' => null
 *     ],
 *     'params' => [
 *         'conditions' => ''
 *         'columns' => '',
 *         'bind' => [],
 *         'bindTypes => [],
 *         'order' => '',
 *         'limit' => 10,
 *         'offset' => 5,
 *         'group' => 'name, status',
 *         'for_updated' => false,
 *         'shared_lock' => false,
 *         'cache' => [
 *             'lifetime' => 3600,
 *             'key' => 'my-find-key'
 *         ],
 *         'hydration' => null
 *     ]
 * ]
 */
PHP_METHOD(Phalcon_Mvc_Model, hasOne)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval referenceModel;
	zval *fields, fields_sub, *referenceModel_param = NULL, *referencedFields, referencedFields_sub, *options = NULL, options_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&referenceModel);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_ZVAL(fields)
		Z_PARAM_STR(referenceModel)
		Z_PARAM_ZVAL(referencedFields)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &fields, &referenceModel_param, &referencedFields, &options);
	if (UNEXPECTED(Z_TYPE_P(referenceModel_param) != IS_STRING && Z_TYPE_P(referenceModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceModel' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referenceModel_param) == IS_STRING)) {
		zephir_get_strval(&referenceModel, referenceModel_param);
	} else {
		ZEPHIR_INIT_VAR(&referenceModel);
	}
	if (!options) {
		options = &options_sub;
		options = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addhasone", NULL, 0, this_ptr, fields, &referenceModel, referencedFields, options);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Setup a 1-1 relation between two models, through an intermediate
 * relation
 *
 *```php
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         // Setup a 1-1 relation to one item from Parts through RobotsParts
 *         $this->hasOneThrough(
 *             "id",
 *             RobotsParts::class,
 *             "robots_id",
 *             "parts_id",
 *             Parts::class,
 *             "id",
 *         );
 *     }
 * }
 *```
 *
 * @param    string|array fields
 * @param    string|array intermediateFields
 * @param    string|array intermediateReferencedFields
 * @param    string|array referencedFields
 * @param    array options
 */
PHP_METHOD(Phalcon_Mvc_Model, hasOneThrough)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval intermediateModel, referenceModel;
	zval *fields, fields_sub, *intermediateModel_param = NULL, *intermediateFields, intermediateFields_sub, *intermediateReferencedFields, intermediateReferencedFields_sub, *referenceModel_param = NULL, *referencedFields, referencedFields_sub, *options = NULL, options_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&intermediateFields_sub);
	ZVAL_UNDEF(&intermediateReferencedFields_sub);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&intermediateModel);
	ZVAL_UNDEF(&referenceModel);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(6, 7)
		Z_PARAM_ZVAL(fields)
		Z_PARAM_STR(intermediateModel)
		Z_PARAM_ZVAL(intermediateFields)
		Z_PARAM_ZVAL(intermediateReferencedFields)
		Z_PARAM_STR(referenceModel)
		Z_PARAM_ZVAL(referencedFields)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 6, 1, &fields, &intermediateModel_param, &intermediateFields, &intermediateReferencedFields, &referenceModel_param, &referencedFields, &options);
	if (UNEXPECTED(Z_TYPE_P(intermediateModel_param) != IS_STRING && Z_TYPE_P(intermediateModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'intermediateModel' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(intermediateModel_param) == IS_STRING)) {
		zephir_get_strval(&intermediateModel, intermediateModel_param);
	} else {
		ZEPHIR_INIT_VAR(&intermediateModel);
	}
	if (UNEXPECTED(Z_TYPE_P(referenceModel_param) != IS_STRING && Z_TYPE_P(referenceModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceModel' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referenceModel_param) == IS_STRING)) {
		zephir_get_strval(&referenceModel, referenceModel_param);
	} else {
		ZEPHIR_INIT_VAR(&referenceModel);
	}
	if (!options) {
		options = &options_sub;
		options = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addhasonethrough", NULL, 0, this_ptr, fields, &intermediateModel, intermediateFields, intermediateReferencedFields, &referenceModel, referencedFields, options);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Sets if the model must keep the original record snapshot in memory
 *
 *```php
 * use Phalcon\Mvc\Model;
 *
 * class Robots extends Model
 * {
 *     public function initialize()
 *     {
 *         $this->keepSnapshots(true);
 *     }
 * }
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model, keepSnapshots)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keepSnapshot_param = NULL, _0, _1;
	zend_bool keepSnapshot;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(keepSnapshot)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keepSnapshot_param);
	keepSnapshot = zephir_get_boolval(keepSnapshot_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	if (keepSnapshot) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "keepsnapshots", NULL, 0, this_ptr, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets schema name where the mapped table is located
 */
PHP_METHOD(Phalcon_Mvc_Model, setSchema)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *schema_param = NULL, _0;
	zval schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(schema)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &schema_param);
	if (UNEXPECTED(Z_TYPE_P(schema_param) != IS_STRING && Z_TYPE_P(schema_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schema' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schema_param) == IS_STRING)) {
		zephir_get_strval(&schema, schema_param);
	} else {
		ZEPHIR_INIT_VAR(&schema);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setmodelschema", NULL, 0, this_ptr, &schema);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Sets the table name to which model should be mapped
 */
PHP_METHOD(Phalcon_Mvc_Model, setSource)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *source_param = NULL, _0;
	zval source;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(source)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &source_param);
	if (UNEXPECTED(Z_TYPE_P(source_param) != IS_STRING && Z_TYPE_P(source_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'source' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(source_param) == IS_STRING)) {
		zephir_get_strval(&source, source_param);
	} else {
		ZEPHIR_INIT_VAR(&source);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setmodelsource", NULL, 0, this_ptr, &source);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Sets a list of attributes that must be skipped from the
 * generated INSERT/UPDATE statement
 *
 *```php
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         $this->skipAttributes(
 *             [
 *                 "price",
 *             ]
 *         );
 *     }
 * }
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model, skipAttributes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "skipattributesoncreate", NULL, 0, &attributes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "skipattributesonupdate", NULL, 0, &attributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets a list of attributes that must be skipped from the
 * generated INSERT statement
 *
 *```php
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         $this->skipAttributesOnCreate(
 *             [
 *                 "created_at",
 *             ]
 *         );
 *     }
 * }
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model, skipAttributesOnCreate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, __$null, attribute, *_0, _1, _2;
	zval attributes, keysAttributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&keysAttributes);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);


	ZEPHIR_INIT_VAR(&keysAttributes);
	array_init(&keysAttributes);
	zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model.zep", 5639);
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _0)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _0);
			zephir_array_update_zval(&keysAttributes, &attribute, &__$null, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &attributes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attribute, &attributes, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_update_zval(&keysAttributes, &attribute, &__$null, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&attribute);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_2, "setautomaticcreateattributes", NULL, 0, this_ptr, &keysAttributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets a list of attributes that must be skipped from the
 * generated UPDATE statement
 *
 *```php
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         $this->skipAttributesOnUpdate(
 *             [
 *                 "modified_in",
 *             ]
 *         );
 *     }
 * }
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model, skipAttributesOnUpdate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, __$null, attribute, *_0, _1, _2;
	zval attributes, keysAttributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&keysAttributes);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);


	ZEPHIR_INIT_VAR(&keysAttributes);
	array_init(&keysAttributes);
	zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model.zep", 5674);
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _0)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _0);
			zephir_array_update_zval(&keysAttributes, &attribute, &__$null, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &attributes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attribute, &attributes, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_update_zval(&keysAttributes, &attribute, &__$null, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&attribute);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_2, "setautomaticupdateattributes", NULL, 0, this_ptr, &keysAttributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets if a model must use dynamic update instead of the all-field update
 *
 *```php
 * use Phalcon\Mvc\Model;
 *
 * class Robots extends Model
 * {
 *     public function initialize()
 *     {
 *         $this->useDynamicUpdate(true);
 *     }
 * }
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model, useDynamicUpdate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dynamicUpdate_param = NULL, _0, _1;
	zend_bool dynamicUpdate;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(dynamicUpdate)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dynamicUpdate_param);
	dynamicUpdate = zephir_get_boolval(dynamicUpdate_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	if (dynamicUpdate) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "usedynamicupdate", NULL, 0, this_ptr, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Executes validators on every validation call
 *
 *```php
 * use Phalcon\Mvc\Model;
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\ExclusionIn;
 *
 * class Subscriptors extends Model
 * {
 *     public function validation()
 *     {
 *         $validator = new Validation();
 *
 *         $validator->add(
 *             "status",
 *             new ExclusionIn(
 *                 [
 *                     "domain" => [
 *                         "A",
 *                         "I",
 *                     ],
 *                 ]
 *             )
 *         );
 *
 *         return $this->validate($validator);
 *     }
 * }
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model, validate)
{
	zend_object_iterator *_1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validator, validator_sub, messages, message, _0, _2$$4, _3$$4, _4$$4, _5$$4, _6$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validator_sub);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(validator, phalcon_validation_validationinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &validator);


	ZVAL_NULL(&_0);
	ZEPHIR_CALL_METHOD(&messages, validator, "validate", NULL, 0, &_0, this_ptr);
	zephir_check_call_status();
	if (((Z_TYPE_P(&messages) == IS_TRUE || Z_TYPE_P(&messages) == IS_FALSE) == 1)) {
		RETURN_CCTOR(&messages);
	}
	_1 = zephir_get_iterator(&messages);
	_1->funcs->rewind(_1);
	for (;_1->funcs->valid(_1) == SUCCESS && !EG(exception); _1->funcs->move_forward(_1)) {
		{
			ZEPHIR_ITERATOR_COPY(&message, _1);
		}
		ZEPHIR_INIT_NVAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_messages_message_ce);
		ZEPHIR_CALL_METHOD(&_3$$4, &message, "getmessage", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$4, &message, "getfield", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5$$4, &message, "gettype", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_6$$4, &message, "getcode", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", &_7, 6, &_3$$4, &_4$$4, &_5$$4, &_6$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_8, 0, &_2$$4);
		zephir_check_call_status();
	}
	zend_iterator_dtor(_1);
	RETURN_MM_BOOL(!(zephir_fast_count_int(&messages)));
}

/**
 * Check whether validation process has generated any messages
 *
 *```php
 * use Phalcon\Mvc\Model;
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\ExclusionIn;
 *
 * class Subscriptors extends Model
 * {
 *     public function validation()
 *     {
 *         $validator = new Validation();
 *
 *         $validator->validate(
 *             "status",
 *             new ExclusionIn(
 *                 [
 *                     "domain" => [
 *                         "A",
 *                         "I",
 *                     ],
 *                 ]
 *             )
 *         );
 *
 *         return $this->validate($validator);
 *     }
 * }
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model, validationHasFailed)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("errorMessages"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_fast_count_int(&_0) > 0);
}

/**
 * Attempts to find key case-insensitively
 */
PHP_METHOD(Phalcon_Mvc_Model, caseInsensitiveColumnMap)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *columnMap, columnMap_sub, *key, key_sub, cmKey, _0, *_1, _2, _3$$3, _4$$3, _5$$5, _6$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&cmKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(columnMap)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &columnMap, &key);


	ZEPHIR_INIT_VAR(&_0);
	zephir_array_keys(&_0, columnMap);
	zephir_is_iterable(&_0, 0, "phalcon/Mvc/Model.zep", 5810);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&cmKey);
			ZVAL_COPY(&cmKey, _1);
			ZEPHIR_INIT_NVAR(&_3$$3);
			zephir_fast_strtolower(&_3$$3, &cmKey);
			ZEPHIR_INIT_NVAR(&_4$$3);
			zephir_fast_strtolower(&_4$$3, key);
			if (ZEPHIR_IS_EQUAL(&_3$$3, &_4$$3)) {
				RETURN_CCTOR(&cmKey);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&cmKey, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_5$$5);
				zephir_fast_strtolower(&_5$$5, &cmKey);
				ZEPHIR_INIT_NVAR(&_6$$5);
				zephir_fast_strtolower(&_6$$5, key);
				if (ZEPHIR_IS_EQUAL(&_5$$5, &_6$$5)) {
					RETURN_CCTOR(&cmKey);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&cmKey);
	RETVAL_ZVAL(key, 1, 0);
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Mvc_Model(zend_class_entry *class_type)
{
		zval _0, _2, _4, _6, _8, _10, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7, _11$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("uniqueParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("uniqueParams"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("snapshot"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("snapshot"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("oldSnapshot"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("oldSnapshot"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("related"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("related"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("errorMessages"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("errorMessages"), &_9$$7);
		}
		zephir_read_property_ex(&_10, this_ptr, ZEND_STRL("dirtyRelated"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			array_init(&_11$$8);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("dirtyRelated"), &_11$$8);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

