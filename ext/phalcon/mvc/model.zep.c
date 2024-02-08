
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/object.h"
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
	 * @var array
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
 * Phalcon\Mvc\Model constructor
 */
PHP_METHOD(Phalcon_Mvc_Model, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, *container = NULL, container_sub, *modelsManager = NULL, modelsManager_sub, __$null, _0$$4, _1$$4, _2$$4, _3$$5, _4$$5, _5$$6, _6$$6, _7$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&modelsManager_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(container, phalcon_di_diinterface_ce)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(modelsManager, phalcon_mvc_model_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	if (Z_TYPE_P(container) == IS_NULL) {
		ZEPHIR_CALL_CE_STATIC(container, phalcon_di_di_ce, "getdefault", NULL, 0);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$4);
		object_init_ex(&_0$$4, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_get_class(&_1$$4, this_ptr, 0);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SVS(&_2$$4, "A dependency injection container is required to access the services related to the ODM in '", &_1$$4, "'");
		ZEPHIR_CALL_METHOD(NULL, &_0$$4, "__construct", NULL, 33, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$4, "phalcon/Mvc/Model.zep", 184);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), container);
	if (Z_TYPE_P(modelsManager) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_4$$5);
		ZVAL_STRING(&_4$$5, "modelsManager");
		ZEPHIR_CALL_METHOD(&_3$$5, container, "getshared", NULL, 0, &_4$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(modelsManager, &_3$$5);
		if (Z_TYPE_P(modelsManager) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$6);
			object_init_ex(&_5$$6, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_VAR(&_6$$6);
			zephir_get_class(&_6$$6, this_ptr, 0);
			ZEPHIR_INIT_VAR(&_7$$6);
			ZEPHIR_CONCAT_SVS(&_7$$6, "The injected service 'modelsManager' is not valid in '", &_6$$6, "'");
			ZEPHIR_CALL_METHOD(NULL, &_5$$6, "__construct", NULL, 33, &_7$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$6, "phalcon/Mvc/Model.zep", 197);
			ZEPHIR_MM_RESTORE();
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
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(method)
		Z_PARAM_ARRAY(arguments)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &method_param, &arguments_param);
	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&arguments, arguments_param);
	ZEPHIR_CALL_SELF(&records, "invokefinder", &_0, 418, &method, &arguments);
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
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 33, &_3);
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

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&arguments);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(method)
		Z_PARAM_ARRAY(arguments)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &method_param, &arguments_param);
	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&arguments, arguments_param);
	ZEPHIR_CALL_SELF(&records, "invokefinder", &_0, 418, &method, &arguments);
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
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 33, &_2);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(property)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_camelize(&_4, &property, NULL );
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(property)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
		zephir_camelize(&_1$$4, &property, NULL );
		ZEPHIR_INIT_VAR(&method);
		ZEPHIR_CONCAT_SV(&method, "get", &_1$$4);
		ZEPHIR_INIT_NVAR(&result);
		ZVAL_BOOL(&result, (zephir_method_exists(this_ptr, &method)  == SUCCESS));
	}
	RETURN_CCTOR(&result);
}

/**
 * Serializes a model
 */
PHP_METHOD(Phalcon_Mvc_Model, __serialize)
{
	zend_bool _3, _4;
	zval attributes, manager, dirtyState, snapshot, _0, _1, _2, _5$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&dirtyState);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&snapshot);
	ZVAL_NULL(&snapshot);
	ZVAL_NULL(&_0);
	ZVAL_BOOL(&_1, 0);
	ZEPHIR_CALL_METHOD(&attributes, this_ptr, "toarray", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("dirtyState"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dirtyState, &_0);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_2);
	ZEPHIR_CALL_METHOD(&_2, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
	zephir_check_call_status();
	_3 = zephir_is_true(&_2);
	if (_3) {
		zephir_read_property(&_0, this_ptr, ZEND_STRL("snapshot"), PH_NOISY_CC | PH_READONLY);
		_3 = Z_TYPE_P(&_0) != IS_NULL;
	}
	_4 = _3;
	if (_4) {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("snapshot"), PH_NOISY_CC | PH_READONLY);
		_4 = !ZEPHIR_IS_EQUAL(&attributes, &_1);
	}
	if (_4) {
		zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("snapshot"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&snapshot, &_5$$3);
	}
	zephir_create_array(return_value, 3, 0);
	zephir_array_update_string(return_value, SL("attributes"), &attributes, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("snapshot"), &snapshot, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("dirtyState"), &dirtyState, PH_COPY | PH_SEPARATE);
	RETURN_MM();
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
	zval *property_param = NULL, *value, value_sub, lowerProperty, modelName, manager, relation, referencedModel, item, dirtyState, _14, _15, _1$$3, _2$$4, _3$$4, _4$$6, _5$$7, _6$$8, _7$$9, _8$$9, *_9$$10, _10$$10, _11$$10, _12$$17, _13$$18, _16$$20, _17$$21, _18$$21, _19$$21;
	zval property;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property);
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
	ZVAL_UNDEF(&_18$$21);
	ZVAL_UNDEF(&_19$$21);
	ZVAL_UNDEF(&related);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(property)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
						ZVAL_UNDEF(&_8$$9);
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
					zephir_is_iterable(value, 0, "phalcon/Mvc/Model.zep", 495);
					if (Z_TYPE_P(value) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(value), _9$$10)
						{
							ZEPHIR_INIT_NVAR(&item);
							ZVAL_COPY(&item, _9$$10);
							if (Z_TYPE_P(&item) == IS_OBJECT) {
								if (zephir_instance_of_ev(&item, phalcon_mvc_modelinterface_ce)) {
									zephir_array_append(&related, &item, PH_SEPARATE, "phalcon/Mvc/Model.zep", 490);
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
										zephir_array_append(&related, &item, PH_SEPARATE, "phalcon/Mvc/Model.zep", 490);
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
						ZVAL_UNDEF(&_12$$17);
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
	ZEPHIR_CALL_METHOD(&_14, this_ptr, "possiblesetter", NULL, 419, &property, value);
	zephir_check_call_status();
	if (zephir_is_true(&_14)) {
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_15, "property_exists", NULL, 290, this_ptr, &property);
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
			zephir_get_class(&_18$$21, this_ptr, 0);
			ZEPHIR_INIT_VAR(&_19$$21);
			ZEPHIR_CONCAT_SVSVS(&_19$$21, "Cannot access property '", &property, "' (not public) in '", &_18$$21, "'");
			ZEPHIR_CALL_METHOD(NULL, &_17$$21, "__construct", NULL, 33, &_19$$21);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_17$$21, "phalcon/Mvc/Model.zep", 524);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_update_property_zval_zval(this_ptr, &property, value);
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();
}

/**
 * Unserializes an array to the model
 */
PHP_METHOD(Phalcon_Mvc_Model, __unserialize)
{
	zend_string *_12$$6;
	zend_ulong _11$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, container, manager, key, value, snapshot, properties, dirtyState, _4, _5, _0$$3, _1$$4, _2$$4, _3$$4, _6$$5, _7$$5, _8$$5, *_9$$6, _10$$6;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&properties);
	ZVAL_UNDEF(&dirtyState);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &data_param);
	zephir_get_arrval(&data, data_param);
	if (!(zephir_array_isset_string(&data, SL("attributes")))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 1, 0);
		zephir_array_update_string(&_0$$3, SL("attributes"), &data, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&data, &_0$$3);
	}
	ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_di_ce, "getdefault", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_get_class(&_2$$4, this_ptr, 0);
		ZEPHIR_INIT_VAR(&_3$$4);
		ZEPHIR_CONCAT_SVS(&_3$$4, "A dependency injection container is required to access the services related to the ODM in '", &_2$$4, "'");
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 33, &_3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/Model.zep", 553);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), &container);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "modelsManager");
	ZEPHIR_CALL_METHOD(&_4, &container, "getshared", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_4);
	if (Z_TYPE_P(&manager) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_6$$5);
		object_init_ex(&_6$$5, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_7$$5);
		zephir_get_class(&_7$$5, this_ptr, 0);
		ZEPHIR_INIT_VAR(&_8$$5);
		ZEPHIR_CONCAT_SVS(&_8$$5, "The injected service 'modelsManager' is not valid in '", &_7$$5, "'");
		ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", NULL, 33, &_8$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$5, "phalcon/Mvc/Model.zep", 568);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("modelsManager"), &manager);
	ZEPHIR_CALL_METHOD(NULL, &manager, "initialize", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_memory_observe(&properties);
	if (zephir_array_isset_string_fetch(&properties, &data, SL("attributes"), 0)) {
		zephir_is_iterable(&properties, 0, "phalcon/Mvc/Model.zep", 591);
		if (Z_TYPE_P(&properties) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&properties), _11$$6, _12$$6, _9$$6)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_12$$6 != NULL) { 
					ZVAL_STR_COPY(&key, _12$$6);
				} else {
					ZVAL_LONG(&key, _11$$6);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _9$$6);
				zephir_update_property_zval_zval(this_ptr, &key, &value);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &properties, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_10$$6, &properties, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_10$$6)) {
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
	zephir_memory_observe(&dirtyState);
	if (zephir_array_isset_string_fetch(&dirtyState, &data, SL("dirtyState"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("dirtyState"), &dirtyState);
	}
	ZEPHIR_CALL_METHOD(&_4, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (zephir_is_true(&_4)) {
		if (zephir_array_isset_string_fetch(&snapshot, &data, SL("snapshot"), 1)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("snapshot"), &snapshot);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("snapshot"), &properties);
		}
	}
	ZEPHIR_MM_RESTORE();
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(behavior, phalcon_mvc_model_behaviorinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_messages_messageinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
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
	zend_bool _7$$12, _14$$18, _17$$22, _22$$28;
	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_13 = NULL, *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *whiteList = NULL, whiteList_sub, *dataColumnMap = NULL, dataColumnMap_sub, __$null, key, keyMapped, value, attribute, attributeField, metaData, columnMap, disableAssignSetters, _4, *_5, _6, *_0$$3, _1$$3, _8$$13, _10$$16, _11$$16, _12$$16, _15$$18, _18$$23, _19$$26, _20$$26, _21$$26, _23$$28;
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
	ZVAL_UNDEF(&_12$$16);
	ZVAL_UNDEF(&_15$$18);
	ZVAL_UNDEF(&_18$$23);
	ZVAL_UNDEF(&_19$$26);
	ZVAL_UNDEF(&_20$$26);
	ZVAL_UNDEF(&_21$$26);
	ZVAL_UNDEF(&_23$$28);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ARRAY(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(whiteList)
		Z_PARAM_ZVAL_OR_NULL(dataColumnMap)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
		zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 751);
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
	zephir_is_iterable(&_4, 0, "phalcon/Mvc/Model.zep", 808);
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
				ZEPHIR_CALL_SELF(&_8$$13, "caseinsensitivecolumnmap", &_9, 420, &columnMap, &attribute);
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
						zephir_get_class(&_11$$16, this_ptr, 0);
						ZEPHIR_INIT_NVAR(&_12$$16);
						ZEPHIR_CONCAT_SVSVS(&_12$$16, "Column '", &attribute, "' doesn't make part of the column map in '", &_11$$16, "'");
						ZEPHIR_CALL_METHOD(NULL, &_10$$16, "__construct", &_13, 33, &_12$$16);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_10$$16, "phalcon/Mvc/Model.zep", 782);
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
				_14$$18 = zephir_is_true(&disableAssignSetters);
				if (!(_14$$18)) {
					ZEPHIR_CALL_METHOD(&_15$$18, this_ptr, "possiblesetter", &_16, 419, &attributeField, &value);
					zephir_check_call_status();
					_14$$18 = !zephir_is_true(&_15$$18);
				}
				if (_14$$18) {
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
				_17$$22 = !(zephir_array_isset(&columnMap, &attribute));
				if (_17$$22) {
					_17$$22 = ZEPHIR_GLOBAL(orm).case_insensitive_column_map;
				}
				if (_17$$22) {
					ZEPHIR_CALL_SELF(&_18$$23, "caseinsensitivecolumnmap", &_9, 420, &columnMap, &attribute);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&attribute, &_18$$23);
				}
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0))) {
						if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
							ZEPHIR_INIT_NVAR(&_19$$26);
							object_init_ex(&_19$$26, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_20$$26);
							zephir_get_class(&_20$$26, this_ptr, 0);
							ZEPHIR_INIT_NVAR(&_21$$26);
							ZEPHIR_CONCAT_SVSVS(&_21$$26, "Column '", &attribute, "' doesn't make part of the column map in '", &_20$$26, "'");
							ZEPHIR_CALL_METHOD(NULL, &_19$$26, "__construct", &_13, 33, &_21$$26);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_19$$26, "phalcon/Mvc/Model.zep", 782);
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
					_22$$28 = zephir_is_true(&disableAssignSetters);
					if (!(_22$$28)) {
						ZEPHIR_CALL_METHOD(&_23$$28, this_ptr, "possiblesetter", &_16, 419, &attributeField, &value);
						zephir_check_call_status();
						_22$$28 = !zephir_is_true(&_23$$28);
					}
					if (_22$$28) {
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

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long dirtyState, ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *base, base_sub, *data_param = NULL, *dirtyState_param = NULL, instance, key, value, _0, *_1, _2, _12, _5$$4, _6$$4, _7$$4, _9$$6, _10$$6, _11$$6;

	ZVAL_UNDEF(&base_sub);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&data);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_OBJECT_OF_CLASS(base, phalcon_mvc_modelinterface_ce)
		Z_PARAM_ARRAY(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(dirtyState)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 1, &base, &data_param, &dirtyState_param);
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	if (!dirtyState_param) {
		dirtyState = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&instance);
	if (zephir_clone(&instance, base) == FAILURE) {
		RETURN_MM();
	}
	ZVAL_LONG(&_0, dirtyState);
	ZEPHIR_CALL_METHOD(NULL, &instance, "setdirtystate", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 898);
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
				ZEPHIR_INIT_NVAR(&_5$$4);
				object_init_ex(&_5$$4, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_NVAR(&_6$$4);
				zephir_get_class(&_6$$4, base, 0);
				ZEPHIR_INIT_NVAR(&_7$$4);
				ZEPHIR_CONCAT_SVS(&_7$$4, "Invalid key in array data provided to dumpResult() in '", &_6$$4, "'");
				ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", &_8, 33, &_7$$4);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_5$$4, "phalcon/Mvc/Model.zep", 888);
				ZEPHIR_MM_RESTORE();
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
					ZEPHIR_INIT_NVAR(&_9$$6);
					object_init_ex(&_9$$6, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_NVAR(&_10$$6);
					zephir_get_class(&_10$$6, base, 0);
					ZEPHIR_INIT_NVAR(&_11$$6);
					ZEPHIR_CONCAT_SVS(&_11$$6, "Invalid key in array data provided to dumpResult() in '", &_10$$6, "'");
					ZEPHIR_CALL_METHOD(NULL, &_9$$6, "__construct", &_8, 33, &_11$$6);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_9$$6, "phalcon/Mvc/Model.zep", 888);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_update_property_zval_zval(&instance, &key, &value);
			ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_VAR(&_12);
	ZVAL_STRING(&_12, "afterFetch");
	ZEPHIR_CALL_METHOD(NULL, &instance, "fireevent", NULL, 0, &_12);
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
	zephir_fcall_cache_entry *_9 = NULL, *_16 = NULL;
	zend_bool keepSnapshots, _5$$6, _13$$3, _18$$24, _25$$21;
	zend_long dirtyState, ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *base, base_sub, *data_param = NULL, *columnMap, columnMap_sub, *dirtyState_param = NULL, *keepSnapshots_param = NULL, instance, attribute, key, value, castValue, attributeName, metaData, reverseMap, _0, *_1, _2, _6$$9, _7$$9, _8$$9, _10$$11, _11$$11, _12$$11, _14$$13, _15$$14, _17$$18, _19$$27, _20$$27, _21$$27, _22$$29, _23$$29, _24$$29, _26$$31, _27$$32, _28$$36, _29$$40;

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
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_17$$18);
	ZVAL_UNDEF(&_19$$27);
	ZVAL_UNDEF(&_20$$27);
	ZVAL_UNDEF(&_21$$27);
	ZVAL_UNDEF(&_22$$29);
	ZVAL_UNDEF(&_23$$29);
	ZVAL_UNDEF(&_24$$29);
	ZVAL_UNDEF(&_26$$31);
	ZVAL_UNDEF(&_27$$32);
	ZVAL_UNDEF(&_28$$36);
	ZVAL_UNDEF(&_29$$40);
	ZVAL_UNDEF(&data);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 5)
		Z_PARAM_ZVAL(base)
		Z_PARAM_ARRAY(data)
		Z_PARAM_ZVAL(columnMap)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(dirtyState)
		Z_PARAM_BOOL_OR_NULL(keepSnapshots, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 2, &base, &data_param, &columnMap, &dirtyState_param, &keepSnapshots_param);
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	if (!dirtyState_param) {
		dirtyState = 0;
	} else {
		}
	if (!keepSnapshots_param) {
		keepSnapshots = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&instance);
	if (zephir_clone(&instance, base) == FAILURE) {
		RETURN_MM();
	}
	ZVAL_LONG(&_0, dirtyState);
	ZEPHIR_CALL_METHOD(NULL, &instance, "setdirtystate", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_is_iterable(&data, 1, "phalcon/Mvc/Model.zep", 1031);
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
							zephir_get_class(&_7$$9, base, 0);
							ZEPHIR_INIT_NVAR(&_8$$9);
							ZEPHIR_CONCAT_SVSVS(&_8$$9, "Column '", &key, "' doesn't make part of the column map in '", &_7$$9, "'");
							ZEPHIR_CALL_METHOD(NULL, &_6$$9, "__construct", &_9, 33, &_8$$9);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_6$$9, "phalcon/Mvc/Model.zep", 958);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
				} else {
					if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
						ZEPHIR_INIT_NVAR(&_10$$11);
						object_init_ex(&_10$$11, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_11$$11);
						zephir_get_class(&_11$$11, base, 0);
						ZEPHIR_INIT_NVAR(&_12$$11);
						ZEPHIR_CONCAT_SVSVS(&_12$$11, "Column '", &key, "' doesn't make part of the column map in '", &_11$$11, "'");
						ZEPHIR_CALL_METHOD(NULL, &_10$$11, "__construct", &_9, 33, &_12$$11);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_10$$11, "phalcon/Mvc/Model.zep", 967);
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
			_13$$3 = !ZEPHIR_IS_STRING(&value, "");
			if (_13$$3) {
				_13$$3 = Z_TYPE_P(&value) != IS_NULL;
			}
			if (_13$$3) {
				zephir_array_fetch_long(&_14$$13, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 981);
				do {
					if (ZEPHIR_IS_LONG(&_14$$13, 0) || ZEPHIR_IS_LONG(&_14$$13, 21) || ZEPHIR_IS_LONG(&_14$$13, 22) || ZEPHIR_IS_LONG(&_14$$13, 26)) {
						ZVAL_LONG(&_15$$14, 10);
						ZEPHIR_CALL_FUNCTION(&castValue, "intval", &_16, 42, &value, &_15$$14);
						zephir_check_call_status();
						break;
					}
					if (ZEPHIR_IS_LONG(&_14$$13, 3) || ZEPHIR_IS_LONG(&_14$$13, 9) || ZEPHIR_IS_LONG(&_14$$13, 7)) {
						ZEPHIR_INIT_NVAR(&castValue);
						ZVAL_DOUBLE(&castValue, zephir_get_doubleval(&value));
						break;
					}
					if (ZEPHIR_IS_LONG(&_14$$13, 8)) {
						ZEPHIR_INIT_NVAR(&castValue);
						ZVAL_BOOL(&castValue, zephir_get_boolval(&value));
						break;
					}
					ZEPHIR_CPY_WRT(&castValue, &value);
					break;
				} while(0);

			} else {
				zephir_array_fetch_long(&_17$$18, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 1004);
				do {
					if (ZEPHIR_IS_LONG(&_17$$18, 14) || ZEPHIR_IS_LONG(&_17$$18, 8) || ZEPHIR_IS_LONG(&_17$$18, 3) || ZEPHIR_IS_LONG(&_17$$18, 9) || ZEPHIR_IS_LONG(&_17$$18, 7) || ZEPHIR_IS_LONG(&_17$$18, 0) || ZEPHIR_IS_LONG(&_17$$18, 21) || ZEPHIR_IS_LONG(&_17$$18, 22) || ZEPHIR_IS_LONG(&_17$$18, 26)) {
						ZEPHIR_INIT_NVAR(&castValue);
						ZVAL_NULL(&castValue);
						break;
					}
					ZEPHIR_CPY_WRT(&castValue, &value);
					break;
				} while(0);

			}
			ZEPHIR_OBS_NVAR(&attributeName);
			zephir_array_fetch_long(&attributeName, &attribute, 0, PH_NOISY, "phalcon/Mvc/Model.zep", 1023);
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
					_18$$24 = Z_TYPE_P(columnMap) == IS_ARRAY;
					if (_18$$24) {
						_18$$24 = !(ZEPHIR_IS_EMPTY(columnMap));
					}
					if (_18$$24) {
						ZEPHIR_CALL_METHOD(&metaData, &instance, "getmodelsmetadata", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&reverseMap, &metaData, "getreversecolumnmap", NULL, 0, &instance);
						zephir_check_call_status();
						ZEPHIR_OBS_NVAR(&attribute);
						if (!(zephir_array_isset_fetch(&attribute, &reverseMap, &key, 0))) {
							if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
								ZEPHIR_INIT_NVAR(&_19$$27);
								object_init_ex(&_19$$27, phalcon_mvc_model_exception_ce);
								ZEPHIR_INIT_NVAR(&_20$$27);
								zephir_get_class(&_20$$27, base, 0);
								ZEPHIR_INIT_NVAR(&_21$$27);
								ZEPHIR_CONCAT_SVSVS(&_21$$27, "Column '", &key, "' doesn't make part of the column map in '", &_20$$27, "'");
								ZEPHIR_CALL_METHOD(NULL, &_19$$27, "__construct", &_9, 33, &_21$$27);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_19$$27, "phalcon/Mvc/Model.zep", 958);
								ZEPHIR_MM_RESTORE();
								return;
							}
							continue;
						}
					} else {
						if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
							ZEPHIR_INIT_NVAR(&_22$$29);
							object_init_ex(&_22$$29, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_23$$29);
							zephir_get_class(&_23$$29, base, 0);
							ZEPHIR_INIT_NVAR(&_24$$29);
							ZEPHIR_CONCAT_SVSVS(&_24$$29, "Column '", &key, "' doesn't make part of the column map in '", &_23$$29, "'");
							ZEPHIR_CALL_METHOD(NULL, &_22$$29, "__construct", &_9, 33, &_24$$29);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_22$$29, "phalcon/Mvc/Model.zep", 967);
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
				_25$$21 = !ZEPHIR_IS_STRING(&value, "");
				if (_25$$21) {
					_25$$21 = Z_TYPE_P(&value) != IS_NULL;
				}
				if (_25$$21) {
					zephir_array_fetch_long(&_26$$31, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 981);
					do {
						if (ZEPHIR_IS_LONG(&_26$$31, 0) || ZEPHIR_IS_LONG(&_26$$31, 21) || ZEPHIR_IS_LONG(&_26$$31, 22) || ZEPHIR_IS_LONG(&_26$$31, 26)) {
							ZVAL_LONG(&_27$$32, 10);
							ZEPHIR_CALL_FUNCTION(&castValue, "intval", &_16, 42, &value, &_27$$32);
							zephir_check_call_status();
							break;
						}
						if (ZEPHIR_IS_LONG(&_26$$31, 3) || ZEPHIR_IS_LONG(&_26$$31, 9) || ZEPHIR_IS_LONG(&_26$$31, 7)) {
							ZEPHIR_INIT_NVAR(&castValue);
							ZVAL_DOUBLE(&castValue, zephir_get_doubleval(&value));
							break;
						}
						if (ZEPHIR_IS_LONG(&_26$$31, 8)) {
							ZEPHIR_INIT_NVAR(&castValue);
							ZVAL_BOOL(&castValue, zephir_get_boolval(&value));
							break;
						}
						ZEPHIR_CPY_WRT(&castValue, &value);
						break;
					} while(0);

				} else {
					zephir_array_fetch_long(&_28$$36, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 1004);
					do {
						if (ZEPHIR_IS_LONG(&_28$$36, 14) || ZEPHIR_IS_LONG(&_28$$36, 8) || ZEPHIR_IS_LONG(&_28$$36, 3) || ZEPHIR_IS_LONG(&_28$$36, 9) || ZEPHIR_IS_LONG(&_28$$36, 7) || ZEPHIR_IS_LONG(&_28$$36, 0) || ZEPHIR_IS_LONG(&_28$$36, 21) || ZEPHIR_IS_LONG(&_28$$36, 22) || ZEPHIR_IS_LONG(&_28$$36, 26)) {
							ZEPHIR_INIT_NVAR(&castValue);
							ZVAL_NULL(&castValue);
							break;
						}
						ZEPHIR_CPY_WRT(&castValue, &value);
						break;
					} while(0);

				}
				ZEPHIR_OBS_NVAR(&attributeName);
				zephir_array_fetch_long(&attributeName, &attribute, 0, PH_NOISY, "phalcon/Mvc/Model.zep", 1023);
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
		ZEPHIR_INIT_VAR(&_29$$40);
		ZVAL_STRING(&_29$$40, "afterFetch");
		ZEPHIR_CALL_METHOD(NULL, &instance, "fireevent", NULL, 0, &_29$$40);
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
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ARRAY(data)
		Z_PARAM_ZVAL(columnMap)
		Z_PARAM_LONG(hydrationMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &data_param, &columnMap, &hydrationMode_param);
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	if (Z_TYPE_P(columnMap) != IS_ARRAY) {
		if (hydrationMode == 1) {
			RETURN_CTOR(&data);
		}
	}
	ZEPHIR_INIT_VAR(&hydrateArray);
	array_init(&hydrateArray);
	zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 1118);
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
					ZEPHIR_CALL_SELF(&_5$$8, "caseinsensitivecolumnmap", &_6, 420, columnMap, &key);
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
						ZEPHIR_CALL_METHOD(NULL, &_7$$10, "__construct", &_9, 33, &_8$$10);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_7$$10, "phalcon/Mvc/Model.zep", 1097);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
				if (Z_TYPE_P(&attribute) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeName);
					zephir_array_fetch_long(&attributeName, &attribute, 0, PH_NOISY, "phalcon/Mvc/Model.zep", 1107);
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
						ZEPHIR_CALL_SELF(&_11$$17, "caseinsensitivecolumnmap", &_6, 420, columnMap, &key);
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
							ZEPHIR_CALL_METHOD(NULL, &_12$$19, "__construct", &_9, 33, &_13$$19);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_12$$19, "phalcon/Mvc/Model.zep", 1097);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
					if (Z_TYPE_P(&attribute) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeName);
						zephir_array_fetch_long(&attributeName, &attribute, 0, PH_NOISY, "phalcon/Mvc/Model.zep", 1107);
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
	zend_bool _6$$3, _8$$6;
	zend_string *_5;
	zend_ulong _4;
	zval related, dirtyRelated;
	zval name, record, _0, _1, *_2, _3, _7$$3, _9$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&related);
	ZVAL_UNDEF(&dirtyRelated);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("related"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&related, &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("dirtyRelated"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dirtyRelated, &_1);
	zephir_is_iterable(&related, 0, "phalcon/Mvc/Model.zep", 1159);
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
			ZVAL_LONG(&_7$$3, 1);
			ZEPHIR_CALL_METHOD(NULL, &record, "setdirtystate", NULL, 0, &_7$$3);
			zephir_check_call_status();
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
				_8$$6 = Z_TYPE_P(&record) != IS_OBJECT;
				if (!(_8$$6)) {
					_8$$6 = !((zephir_instance_of_ev(&record, phalcon_mvc_modelinterface_ce)));
				}
				if (_8$$6) {
					continue;
				}
				ZVAL_LONG(&_9$$6, 1);
				ZEPHIR_CALL_METHOD(NULL, &record, "setdirtystate", NULL, 0, &_9$$6);
				zephir_check_call_status();
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

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &parameters);
	if (!parameters) {
		parameters = &parameters_sub;
		ZEPHIR_CPY_WRT(parameters, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(parameters);
	}
	if (zephir_array_isset_string(parameters, SL("order"))) {
		zephir_array_unset_string(parameters, SL("order"), PH_SEPARATE);
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
	zval _2$$3, _4$$3;
	zval metaData, _0, _1, _3$$3, _5$$3, _6$$3, _7$$3, _8$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getwriteconnection", NULL, 421);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &metaData, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_create_array(&_2$$3, 1, 0);
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, phalcon_messages_message_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_create_array(&_4$$3, 1, 0);
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_get_class(&_5$$3, this_ptr, 0);
		zephir_array_update_string(&_4$$3, SL("model"), &_5$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "Record cannot be created because it already exists");
		ZVAL_NULL(&_6$$3);
		ZEPHIR_INIT_VAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "InvalidCreateAttempt");
		ZVAL_LONG(&_8$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 6, &_5$$3, &_6$$3, &_7$$3, &_8$$3, &_4$$3);
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
	zval __$true, __$false, metaData, writeConnection, primaryKeys, bindDataTypes, columnMap, attributeField, primaryKey, bindType, value, schema, source, table, success, _0, _1, *_6, _7, _35, _2$$3, _3$$7, _4$$7, _5$$7, _8$$9, _9$$9, _10$$9, _11$$11, _12$$11, _13$$11, _14$$13, _15$$13, _16$$13, _17$$8, _19$$8, _20$$15, _21$$15, _22$$15, _23$$17, _24$$17, _25$$17, _26$$19, _27$$19, _28$$19, _29$$14, _31$$14, _32$$20, _33$$20, _34$$20, _36$$25, _37$$28, _38$$29, _39$$29;
	zephir_fcall_cache_entry *_18 = NULL, *_30 = NULL;
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
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_23$$17);
	ZVAL_UNDEF(&_24$$17);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_26$$19);
	ZVAL_UNDEF(&_27$$19);
	ZVAL_UNDEF(&_28$$19);
	ZVAL_UNDEF(&_29$$14);
	ZVAL_UNDEF(&_31$$14);
	ZVAL_UNDEF(&_32$$20);
	ZVAL_UNDEF(&_33$$20);
	ZVAL_UNDEF(&_34$$20);
	ZVAL_UNDEF(&_36$$25);
	ZVAL_UNDEF(&_37$$28);
	ZVAL_UNDEF(&_38$$29);
	ZVAL_UNDEF(&_39$$29);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&conditions);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&writeConnection, this_ptr, "getwriteconnection", NULL, 421);
	zephir_check_call_status();
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, 3);
	zephir_update_property_zval(this_ptr, ZEND_STRL("operationMade"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, ZEND_STRL("errorMessages"), &_1);
	if (ZEPHIR_GLOBAL(orm).virtual_foreign_keys) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "checkforeignkeysreverserestrict", NULL, 422);
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
		ZEPHIR_INIT_VAR(&_3$$7);
		object_init_ex(&_3$$7, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$7);
		zephir_get_class(&_4$$7, this_ptr, 0);
		ZEPHIR_INIT_VAR(&_5$$7);
		ZEPHIR_CONCAT_SVS(&_5$$7, "A primary key must be defined in the model in order to perform the operation in '", &_4$$7, "'");
		ZEPHIR_CALL_METHOD(NULL, &_3$$7, "__construct", NULL, 33, &_5$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$7, "phalcon/Mvc/Model.zep", 1323);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_is_iterable(&primaryKeys, 0, "phalcon/Mvc/Model.zep", 1372);
	if (Z_TYPE_P(&primaryKeys) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&primaryKeys), _6)
		{
			ZEPHIR_INIT_NVAR(&primaryKey);
			ZVAL_COPY(&primaryKey, _6);
			ZEPHIR_OBS_NVAR(&bindType);
			if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &primaryKey, 0)))) {
				ZEPHIR_INIT_NVAR(&_8$$9);
				object_init_ex(&_8$$9, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_NVAR(&_9$$9);
				zephir_get_class(&_9$$9, this_ptr, 0);
				ZEPHIR_INIT_NVAR(&_10$$9);
				ZEPHIR_CONCAT_SVSVS(&_10$$9, "Column '", &primaryKey, "' have not defined a bind data type in '", &_9$$9, "'");
				ZEPHIR_CALL_METHOD(NULL, &_8$$9, "__construct", NULL, 33, &_10$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_8$$9, "phalcon/Mvc/Model.zep", 1337);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &primaryKey, 0)))) {
					ZEPHIR_INIT_NVAR(&_11$$11);
					object_init_ex(&_11$$11, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_NVAR(&_12$$11);
					zephir_get_class(&_12$$11, this_ptr, 0);
					ZEPHIR_INIT_NVAR(&_13$$11);
					ZEPHIR_CONCAT_SVSVS(&_13$$11, "Column '", &primaryKey, "' isn't part of the column map in '", &_12$$11, "'");
					ZEPHIR_CALL_METHOD(NULL, &_11$$11, "__construct", NULL, 33, &_13$$11);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_11$$11, "phalcon/Mvc/Model.zep", 1347);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &primaryKey);
			}
			ZEPHIR_OBS_NVAR(&value);
			if (UNEXPECTED(!(zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)))) {
				ZEPHIR_INIT_NVAR(&_14$$13);
				object_init_ex(&_14$$13, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_NVAR(&_15$$13);
				zephir_get_class(&_15$$13, this_ptr, 0);
				ZEPHIR_INIT_NVAR(&_16$$13);
				ZEPHIR_CONCAT_SVSVS(&_16$$13, "Cannot delete the record because the primary key attribute: '", &attributeField, "' was not set in '", &_15$$13, "'");
				ZEPHIR_CALL_METHOD(NULL, &_14$$13, "__construct", NULL, 33, &_16$$13);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_14$$13, "phalcon/Mvc/Model.zep", 1361);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1367);
			ZEPHIR_CALL_METHOD(&_17$$8, &writeConnection, "escapeidentifier", &_18, 0, &primaryKey);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_19$$8);
			ZEPHIR_CONCAT_VS(&_19$$8, &_17$$8, " = ?");
			zephir_array_append(&conditions, &_19$$8, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1368);
			zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1369);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &primaryKeys, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_7, &primaryKeys, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&primaryKey, &primaryKeys, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&bindType);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &primaryKey, 0)))) {
					ZEPHIR_INIT_NVAR(&_20$$15);
					object_init_ex(&_20$$15, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_NVAR(&_21$$15);
					zephir_get_class(&_21$$15, this_ptr, 0);
					ZEPHIR_INIT_NVAR(&_22$$15);
					ZEPHIR_CONCAT_SVSVS(&_22$$15, "Column '", &primaryKey, "' have not defined a bind data type in '", &_21$$15, "'");
					ZEPHIR_CALL_METHOD(NULL, &_20$$15, "__construct", NULL, 33, &_22$$15);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_20$$15, "phalcon/Mvc/Model.zep", 1337);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &primaryKey, 0)))) {
						ZEPHIR_INIT_NVAR(&_23$$17);
						object_init_ex(&_23$$17, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_24$$17);
						zephir_get_class(&_24$$17, this_ptr, 0);
						ZEPHIR_INIT_NVAR(&_25$$17);
						ZEPHIR_CONCAT_SVSVS(&_25$$17, "Column '", &primaryKey, "' isn't part of the column map in '", &_24$$17, "'");
						ZEPHIR_CALL_METHOD(NULL, &_23$$17, "__construct", NULL, 33, &_25$$17);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_23$$17, "phalcon/Mvc/Model.zep", 1347);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &primaryKey);
				}
				ZEPHIR_OBS_NVAR(&value);
				if (UNEXPECTED(!(zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)))) {
					ZEPHIR_INIT_NVAR(&_26$$19);
					object_init_ex(&_26$$19, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_NVAR(&_27$$19);
					zephir_get_class(&_27$$19, this_ptr, 0);
					ZEPHIR_INIT_NVAR(&_28$$19);
					ZEPHIR_CONCAT_SVSVS(&_28$$19, "Cannot delete the record because the primary key attribute: '", &attributeField, "' was not set in '", &_27$$19, "'");
					ZEPHIR_CALL_METHOD(NULL, &_26$$19, "__construct", NULL, 33, &_28$$19);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_26$$19, "phalcon/Mvc/Model.zep", 1361);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1367);
				ZEPHIR_CALL_METHOD(&_29$$14, &writeConnection, "escapeidentifier", &_30, 0, &primaryKey);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_31$$14);
				ZEPHIR_CONCAT_VS(&_31$$14, &_29$$14, " = ?");
				zephir_array_append(&conditions, &_31$$14, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1368);
				zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1369);
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
		ZEPHIR_INIT_VAR(&_33$$20);
		ZVAL_STRING(&_33$$20, "beforeDelete");
		ZEPHIR_CALL_METHOD(&_32$$20, this_ptr, "fireeventcancel", NULL, 0, &_33$$20);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_32$$20)) {
			RETURN_MM_BOOL(0);
		}
		zephir_read_property(&_34$$20, this_ptr, ZEND_STRL("skipped"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_34$$20)) {
			RETURN_MM_BOOL(1);
		}
	}
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 423);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 424);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	ZEPHIR_INIT_VAR(&_35);
	zephir_fast_join_str(&_35, SL(" AND "), &conditions);
	ZEPHIR_CALL_METHOD(&success, &writeConnection, "delete", NULL, 0, &table, &_35, &values, &bindTypes);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).virtual_foreign_keys) {
		ZEPHIR_CALL_METHOD(&_36$$25, this_ptr, "checkforeignkeysreversecascade", NULL, 425);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_36$$25)) {
			RETURN_MM_BOOL(0);
		}
	}
	if (ZEPHIR_GLOBAL(orm).events) {
		if (zephir_is_true(&success)) {
			ZEPHIR_INIT_VAR(&_37$$28);
			ZVAL_STRING(&_37$$28, "afterDelete");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_37$$28);
			zephir_check_call_status();
		}
	}
	if (zephir_is_true(&success)) {
		ZEPHIR_INIT_VAR(&_38$$29);
		array_init(&_38$$29);
		zephir_update_property_zval(this_ptr, ZEND_STRL("related"), &_38$$29);
		zephir_read_property(&_39$$29, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_39$$29, "clearreusableobjects", NULL, 0);
		zephir_check_call_status();
	}
	ZVAL_UNDEF(&_0);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_RETURN_CALL_FUNCTION("get_object_vars", NULL, 426, this_ptr);
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
 * $myTransaction = new Transaction(\Phalcon\Di\Di::getDefault());
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
 * $myTransaction1 = new Transaction(\Phalcon\Di\Di::getDefault());
 * $myTransaction1->begin();
 * $myTransaction2 = new Transaction(\Phalcon\Di\Di::getDefault());
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
 *     'conditions' => '',
 *     'columns' => '',
 *     'bind' => [],
 *     'bindTypes' => [],
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

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&resultset);
	ZVAL_UNDEF(&hydration);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &parameters);
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}
	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
		if (Z_TYPE_P(parameters) != IS_NULL) {
			zephir_array_append(&params, parameters, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1642);
		}
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	ZEPHIR_CALL_STATIC(&query, "getpreparedquery", &_0, 427, &params);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&resultset, &query, "execute", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&resultset) == IS_OBJECT) {
		zephir_memory_observe(&hydration);
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
 * $myTransaction = new Transaction(\Phalcon\Di\Di::getDefault());
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
 *     'conditions' => '',
 *     'columns' => '',
 *     'bind' => [],
 *     'bindTypes' => [],
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
 *
 * @return \Phalcon\Mvc\ModelInterface|\Phalcon\Mvc\Model\Row|null
 */
PHP_METHOD(Phalcon_Mvc_Model, findFirst)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, parameters_sub, __$null, params, query, _6, _1$$5, _2$$6, _3$$6, _4$$6;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
		ZEPHIR_INIT_VAR(&_2$$6);
		object_init_ex(&_2$$6, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$6);
		zephir_get_called_class(&_3$$6);
		ZEPHIR_INIT_VAR(&_4$$6);
		ZEPHIR_CONCAT_SVS(&_4$$6, "Parameters passed must be of type array, string, numeric or null in '", &_3$$6, "'");
		ZEPHIR_CALL_METHOD(NULL, &_2$$6, "__construct", NULL, 33, &_4$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$6, "phalcon/Mvc/Model.zep", 1766);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZVAL_LONG(&_6, 1);
	ZEPHIR_CALL_STATIC(&query, "getpreparedquery", &_5, 427, &params, &_6);
	zephir_check_call_status();
	ZVAL_BOOL(&_6, 1);
	ZEPHIR_CALL_METHOD(NULL, &query, "setuniquerow", NULL, 0, &_6);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(eventName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(eventName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zend_string *_8;
	zend_ulong _7;
	zval changed;
	zval metaData, name, snapshot, columnMap, allAttributes, value, _0, _4, *_5, _6, _1$$3, _2$$3, _3$$3, _9$$6, _10$$10;
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
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&changed);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("snapshot"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&snapshot, &_0);
	if (UNEXPECTED(Z_TYPE_P(&snapshot) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_get_class(&_2$$3, this_ptr, 0);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SVS(&_3$$3, "The 'keepSnapshots' option must be enabled to track changes in '", &_2$$3, "'");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 33, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model.zep", 1852);
		ZEPHIR_MM_RESTORE();
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
	ZEPHIR_INIT_VAR(&_4);
	zephir_is_iterable(&allAttributes, 0, "phalcon/Mvc/Model.zep", 1910);
	if (Z_TYPE_P(&allAttributes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&allAttributes), _7, _8, _5)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&name, _8);
			} else {
				ZVAL_LONG(&name, _7);
			}
			ZEPHIR_INIT_NVAR(&_4);
			ZVAL_COPY(&_4, _5);
			if (!(zephir_array_isset(&snapshot, &name))) {
				zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1885);
				continue;
			}
			ZEPHIR_OBS_NVAR(&value);
			if (!(zephir_fetch_property_zval(&value, this_ptr, &name, PH_SILENT_CC))) {
				zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1895);
				continue;
			}
			zephir_array_fetch(&_9$$6, &snapshot, &name, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 1903);
			if (!ZEPHIR_IS_IDENTICAL(&value, &_9$$6)) {
				zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1904);
				continue;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &allAttributes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_6, &allAttributes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &allAttributes, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_4, &allAttributes, "current", NULL, 0);
			zephir_check_call_status();
				if (!(zephir_array_isset(&snapshot, &name))) {
					zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1885);
					continue;
				}
				ZEPHIR_OBS_NVAR(&value);
				if (!(zephir_fetch_property_zval(&value, this_ptr, &name, PH_SILENT_CC))) {
					zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1895);
					continue;
				}
				zephir_array_fetch(&_10$$10, &snapshot, &name, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 1903);
				if (!ZEPHIR_IS_IDENTICAL(&value, &_10$$10)) {
					zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1904);
					continue;
				}
			ZEPHIR_CALL_METHOD(NULL, &allAttributes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&_4);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CTOR(&changed);
}

/**
 * Returns one of the DIRTY_STATE_* constants telling if the record exists
 * in the database or not
 */
PHP_METHOD(Phalcon_Mvc_Model, getDirtyState)
{

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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

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
	zend_bool _0, _1;
	zval filtered;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filter = NULL, filter_sub, __$null, message, _2$$4, _3$$3, *_4$$3, _5$$3, _6$$5, _7$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&filtered);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(filter)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &filter);
	if (!filter) {
		filter = &filter_sub;
		ZEPHIR_CPY_WRT(filter, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(filter);
	}
	_0 = Z_TYPE_P(filter) == IS_STRING;
	if (!(_0)) {
		_0 = Z_TYPE_P(filter) == IS_ARRAY;
	}
	_1 = _0;
	if (_1) {
		_1 = !(ZEPHIR_IS_EMPTY(filter));
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&filtered);
		array_init(&filtered);
		if (Z_TYPE_P(filter) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_2$$4);
			zephir_create_array(&_2$$4, 1, 0);
			zephir_array_fast_append(&_2$$4, filter);
			ZEPHIR_CPY_WRT(filter, &_2$$4);
		}
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("errorMessages"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_3$$3, 0, "phalcon/Mvc/Model.zep", 1974);
		if (Z_TYPE_P(&_3$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_3$$3), _4$$3)
			{
				ZEPHIR_INIT_NVAR(&message);
				ZVAL_COPY(&message, _4$$3);
				ZEPHIR_CALL_METHOD(&_6$$5, &message, "getfield", NULL, 0);
				zephir_check_call_status();
				if (zephir_fast_in_array(&_6$$5, filter)) {
					zephir_array_append(&filtered, &message, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1970);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_3$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_5$$3, &_3$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&message, &_3$$3, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_7$$7, &message, "getfield", NULL, 0);
					zephir_check_call_status();
					if (zephir_fast_in_array(&_7$$7, filter)) {
						zephir_array_append(&filtered, &message, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1970);
					}
				ZEPHIR_CALL_METHOD(NULL, &_3$$3, "next", NULL, 0);
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

	RETURN_MEMBER(getThis(), "modelsManager");
}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Mvc_Model, getModelsMetaData)
{
	zval metaData, container, _0$$3, _1$$3, _2$$3, _3$$4, _4$$4, _5$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&metaData);
	zephir_read_property(&metaData, this_ptr, ZEND_STRL("modelsMetaData"), PH_NOISY_CC);
	if (Z_TYPE_P(&metaData) == IS_NULL) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&container, &_0$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "modelsMetadata");
		ZEPHIR_CALL_METHOD(&_1$$3, &container, "getshared", NULL, 0, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&metaData, &_1$$3);
		if (UNEXPECTED(Z_TYPE_P(&metaData) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_3$$4);
			object_init_ex(&_3$$4, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_VAR(&_4$$4);
			zephir_get_class(&_4$$4, this_ptr, 0);
			ZEPHIR_INIT_VAR(&_5$$4);
			ZEPHIR_CONCAT_SVS(&_5$$4, "The injected service 'modelsMetadata' is not valid in '", &_4$$4, "'");
			ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", NULL, 33, &_5$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$4, "phalcon/Mvc/Model.zep", 2008);
			ZEPHIR_MM_RESTORE();
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

	RETURN_MEMBER(getThis(), "operationMade");
}

/**
 * Returns the internal old snapshot data
 */
PHP_METHOD(Phalcon_Mvc_Model, getOldSnapshotData)
{

	RETURN_MEMBER(getThis(), "oldSnapshot");
}

/**
 * Gets the connection used to read data for the model
 */
PHP_METHOD(Phalcon_Mvc_Model, getReadConnection)
{
	zval _0, _2, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("transaction"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("transaction"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_1$$3, "getconnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_2, "getreadconnection", NULL, 0, this_ptr);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

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
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(alias)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(arguments)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 33, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Mvc/Model.zep", 2084);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(relationshipAlias)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

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
	zend_bool _11$$6, _13$$8;
	zend_string *_10;
	zend_ulong _9;
	zval updated;
	zval name, snapshot, oldSnapshot, value, _0, *_7, _8, _1$$3, _2$$3, _3$$3, _4$$5, _5$$5, _6$$5, _12$$6, _14$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&oldSnapshot);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&updated);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("snapshot"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&snapshot, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("oldSnapshot"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&oldSnapshot, &_0);
	if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).update_snapshot_on_save))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_get_class(&_2$$3, this_ptr, 0);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SVS(&_3$$3, "The 'updateSnapshotOnSave' option must be enabled for this method to work properly in '", &_2$$3, "'");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 33, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model.zep", 2208);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(Z_TYPE_P(&snapshot) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The 'keepSnapshots' option must be enabled to track changes", "phalcon/Mvc/Model.zep", 2214);
		return;
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("dirtyState"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!ZEPHIR_IS_LONG(&_0, 0))) {
		ZEPHIR_INIT_VAR(&_4$$5);
		object_init_ex(&_4$$5, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$5);
		zephir_get_class(&_5$$5, this_ptr, 0);
		ZEPHIR_INIT_VAR(&_6$$5);
		ZEPHIR_CONCAT_SVS(&_6$$5, "Change checking cannot be performed because the object has not been persisted or is deleted in '", &_5$$5, "'");
		ZEPHIR_CALL_METHOD(NULL, &_4$$5, "__construct", NULL, 33, &_6$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$5, "phalcon/Mvc/Model.zep", 2223);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&updated);
	array_init(&updated);
	zephir_is_iterable(&snapshot, 0, "phalcon/Mvc/Model.zep", 2238);
	if (Z_TYPE_P(&snapshot) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&snapshot), _9, _10, _7)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_10 != NULL) { 
				ZVAL_STR_COPY(&name, _10);
			} else {
				ZVAL_LONG(&name, _9);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _7);
			_11$$6 = !(zephir_array_isset(&oldSnapshot, &name));
			if (!(_11$$6)) {
				zephir_array_fetch(&_12$$6, &oldSnapshot, &name, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 2233);
				_11$$6 = !ZEPHIR_IS_IDENTICAL(&value, &_12$$6);
			}
			if (_11$$6) {
				zephir_array_append(&updated, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2234);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &snapshot, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_8, &snapshot, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &snapshot, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &snapshot, "current", NULL, 0);
			zephir_check_call_status();
				_13$$8 = !(zephir_array_isset(&oldSnapshot, &name));
				if (!(_13$$8)) {
					zephir_array_fetch(&_14$$8, &oldSnapshot, &name, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 2233);
					_13$$8 = !ZEPHIR_IS_IDENTICAL(&value, &_14$$8);
				}
				if (_13$$8) {
					zephir_array_append(&updated, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2234);
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
	zval _0, _2, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("transaction"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("transaction"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_1$$3, "getconnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_2, "getwriteconnection", NULL, 0, this_ptr);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

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
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(fieldName)
		Z_PARAM_BOOL(allFields)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &fieldName, &allFields_param);
	if (!fieldName) {
		fieldName = &fieldName_sub;
		fieldName = &__$null;
	}
	if (!allFields_param) {
		allFields = 0;
	} else {
		}
	ZEPHIR_CALL_METHOD(&changedFields, this_ptr, "getchangedfields", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(fieldName) == IS_STRING) {
		RETURN_MM_BOOL(zephir_fast_in_array(fieldName, &changedFields));
	}
	if (Z_TYPE_P(fieldName) == IS_ARRAY) {
		ZEPHIR_CALL_FUNCTION(&intersect, "array_intersect", NULL, 428, fieldName, &changedFields);
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
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(fieldName)
		Z_PARAM_BOOL(allFields)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &fieldName, &allFields_param);
	if (!fieldName) {
		fieldName = &fieldName_sub;
		fieldName = &__$null;
	}
	if (!allFields_param) {
		allFields = 0;
	} else {
		}
	ZEPHIR_CALL_METHOD(&updatedFields, this_ptr, "getupdatedfields", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(fieldName) == IS_STRING) {
		RETURN_MM_BOOL(zephir_fast_in_array(fieldName, &updatedFields));
	}
	if (Z_TYPE_P(fieldName) == IS_ARRAY) {
		ZEPHIR_CALL_FUNCTION(&intersect, "array_intersect", NULL, 428, fieldName, &updatedFields);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

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

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zval *container = NULL, container_sub, __$null, criteria, _2, _0$$4, _1$$4;

	ZVAL_UNDEF(&container_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&criteria);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &container);
	if (!container) {
		container = &container_sub;
		ZEPHIR_CPY_WRT(container, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(container);
	}
	if (Z_TYPE_P(container) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(container, phalcon_di_di_ce, "getdefault", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&criteria);
	if (zephir_instance_of_ev(container, phalcon_di_diinterface_ce)) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "Phalcon\\Mvc\\Model\\Criteria");
		ZEPHIR_CALL_METHOD(&_0$$4, container, "get", NULL, 0, &_1$$4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&criteria, &_0$$4);
	} else {
		object_init_ex(&criteria, phalcon_mvc_model_criteria_ce);
		if (zephir_has_constructor(&criteria)) {
			ZEPHIR_CALL_METHOD(NULL, &criteria, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		ZEPHIR_CALL_METHOD(NULL, &criteria, "setdi", NULL, 429, container);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_get_called_class(&_2);
	ZEPHIR_CALL_METHOD(NULL, &criteria, "setmodelname", NULL, 430, &_2);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(attribute)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_memory_observe(&_0);
	zephir_read_property_zval(&_0, this_ptr, &attribute, PH_NOISY_CC);
	RETURN_CCTOR(&_0);
}

/**
 * Refreshes the model attributes re-querying the record from the database
 */
PHP_METHOD(Phalcon_Mvc_Model, refresh)
{
	zval fields, _18, _16$$9, _17$$10;
	zval metaData, readConnection, schema, source, table, uniqueKey, tables, uniqueParams, dialect, row, attribute, manager, columnMap, _0, _4, _13, *_14, _15, _19, _20, _23, _1$$3, _2$$3, _3$$3, _5$$6, _9$$6, _6$$7, _7$$7, _8$$7, _10$$8, _11$$8, _12$$8, _21$$11, _22$$11;
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
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$10);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("dirtyState"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!ZEPHIR_IS_LONG(&_0, 0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_get_class(&_2$$3, this_ptr, 0);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SVS(&_3$$3, "The record cannot be refreshed because it does not exist or is deleted in '", &_2$$3, "'");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 33, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model.zep", 2489);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&readConnection, this_ptr, "getreadconnection", NULL, 431);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_4);
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 423);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 424);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("uniqueKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueKey, &_4);
	if (!(zephir_is_true(&uniqueKey))) {
		ZEPHIR_CALL_METHOD(&_5$$6, this_ptr, "has", NULL, 0, &metaData, &readConnection);
		zephir_check_call_status();
		if (UNEXPECTED(!zephir_is_true(&_5$$6))) {
			ZEPHIR_INIT_VAR(&_6$$7);
			object_init_ex(&_6$$7, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_VAR(&_7$$7);
			zephir_get_class(&_7$$7, this_ptr, 0);
			ZEPHIR_INIT_VAR(&_8$$7);
			ZEPHIR_CONCAT_SVS(&_8$$7, "The record cannot be refreshed because it does not exist or is deleted in '", &_7$$7, "'");
			ZEPHIR_CALL_METHOD(NULL, &_6$$7, "__construct", NULL, 33, &_8$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$7, "phalcon/Mvc/Model.zep", 2514);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property(&_9$$6, this_ptr, ZEND_STRL("uniqueKey"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&uniqueKey, &_9$$6);
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("uniqueParams"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueParams, &_4);
	if (UNEXPECTED(Z_TYPE_P(&uniqueParams) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_10$$8);
		object_init_ex(&_10$$8, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_11$$8);
		zephir_get_class(&_11$$8, this_ptr, 0);
		ZEPHIR_INIT_VAR(&_12$$8);
		ZEPHIR_CONCAT_SVS(&_12$$8, "The record cannot be refreshed because it does not exist or is deleted in '", &_11$$8, "'");
		ZEPHIR_CALL_METHOD(NULL, &_10$$8, "__construct", NULL, 33, &_12$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_10$$8, "phalcon/Mvc/Model.zep", 2525);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&fields);
	array_init(&fields);
	ZEPHIR_CALL_METHOD(&_13, &metaData, "getattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(&_13, 0, "phalcon/Mvc/Model.zep", 2540);
	if (Z_TYPE_P(&_13) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_13), _14)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _14);
			ZEPHIR_INIT_NVAR(&_16$$9);
			zephir_create_array(&_16$$9, 1, 0);
			zephir_array_fast_append(&_16$$9, &attribute);
			zephir_array_append(&fields, &_16$$9, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2534);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_13, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_15, &_13, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attribute, &_13, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_17$$10);
				zephir_create_array(&_17$$10, 1, 0);
				zephir_array_fast_append(&_17$$10, &attribute);
				zephir_array_append(&fields, &_17$$10, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2534);
			ZEPHIR_CALL_METHOD(NULL, &_13, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&attribute);
	ZEPHIR_CALL_METHOD(&dialect, &readConnection, "getdialect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_18);
	zephir_create_array(&_18, 3, 0);
	zephir_array_update_string(&_18, SL("columns"), &fields, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_19, &readConnection, "escapeidentifier", NULL, 0, &table);
	zephir_check_call_status();
	zephir_array_update_string(&_18, SL("tables"), &_19, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_18, SL("where"), &uniqueKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&tables, &dialect, "select", NULL, 0, &_18);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, ZEND_STRL("uniqueTypes"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_20, 2);
	ZEPHIR_CALL_METHOD(&row, &readConnection, "fetchone", NULL, 0, &tables, &_20, &uniqueParams, &_4);
	zephir_check_call_status();
	if (Z_TYPE_P(&row) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, this_ptr);
		zephir_check_call_status();
		ZVAL_NULL(&_21$$11);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "assign", NULL, 0, &row, &_21$$11, &columnMap);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_22$$11, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (zephir_is_true(&_22$$11)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setsnapshotdata", NULL, 0, &row, &columnMap);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoldsnapshotdata", NULL, 0, &row, &columnMap);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_VAR(&_23);
	ZVAL_STRING(&_23, "afterFetch");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_23);
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
	zval visited;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&visited);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&visited);
	object_init_ex(&visited, phalcon_support_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, &visited, "__construct", NULL, 23);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "dosave", NULL, 0, &visited);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Inserted or updates model instance, expects a visited list of objects.
 *
 * @param CollectionInterface $visited
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Mvc_Model, doSave)
{
	zend_bool hasRelatedToSave = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *visited, visited_sub, metaData, schema, writeConnection, readConnection, source, table, identityField, exists, success, relatedToSave, objId, _0, _1, _5, _2$$4, _3$$8, _4$$9, _6$$11, _7$$12, _8$$12, _9$$15, _10$$17, _11$$19, _12$$22, _13$$21;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&visited_sub);
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
	ZVAL_UNDEF(&objId);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_6$$11);
	ZVAL_UNDEF(&_7$$12);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_9$$15);
	ZVAL_UNDEF(&_10$$17);
	ZVAL_UNDEF(&_11$$19);
	ZVAL_UNDEF(&_12$$22);
	ZVAL_UNDEF(&_13$$21);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(visited, phalcon_support_collection_collectioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &visited);
	ZEPHIR_CALL_FUNCTION(&objId, "spl_object_id", NULL, 432, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, visited, "has", NULL, 0, &objId);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_METHOD(NULL, visited, "set", NULL, 0, &objId, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&writeConnection, this_ptr, "getwriteconnection", NULL, 421);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "prepareSave");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&relatedToSave, this_ptr, "collectrelatedtosave", NULL, 0);
	zephir_check_call_status();
	hasRelatedToSave = zephir_fast_count_int(&relatedToSave) > 0;
	if (hasRelatedToSave) {
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "presaverelatedrecords", NULL, 0, &writeConnection, &relatedToSave, visited);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_2$$4)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 423);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 424);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	ZEPHIR_CALL_METHOD(&readConnection, this_ptr, "getreadconnection", NULL, 431);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&exists, this_ptr, "has", NULL, 0, &metaData, &readConnection);
	zephir_check_call_status();
	if (zephir_is_true(&exists)) {
		ZVAL_UNDEF(&_3$$8);
		ZVAL_LONG(&_3$$8, 2);
		zephir_update_property_zval(this_ptr, ZEND_STRL("operationMade"), &_3$$8);
	} else {
		ZVAL_UNDEF(&_4$$9);
		ZVAL_LONG(&_4$$9, 1);
		zephir_update_property_zval(this_ptr, ZEND_STRL("operationMade"), &_4$$9);
	}
	ZEPHIR_INIT_NVAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, ZEND_STRL("errorMessages"), &_1);
	ZEPHIR_CALL_METHOD(&identityField, &metaData, "getidentityfield", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "presave", NULL, 0, &metaData, &exists, &identityField);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_5)) {
		if (hasRelatedToSave) {
			ZVAL_BOOL(&_6$$11, 0);
			ZEPHIR_CALL_METHOD(NULL, &writeConnection, "rollback", NULL, 0, &_6$$11);
			zephir_check_call_status();
		}
		if (UNEXPECTED(ZEPHIR_GLOBAL(orm).exception_on_failed_save)) {
			ZEPHIR_INIT_VAR(&_7$$12);
			object_init_ex(&_7$$12, phalcon_mvc_model_validationfailed_ce);
			ZEPHIR_CALL_METHOD(&_8$$12, this_ptr, "getmessages", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_7$$12, "__construct", NULL, 433, this_ptr, &_8$$12);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_7$$12, "phalcon/Mvc/Model.zep", 2714);
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
	if (ZEPHIR_IS_TRUE_IDENTICAL(&success)) {
		ZVAL_UNDEF(&_9$$15);
		ZVAL_LONG(&_9$$15, 0);
		zephir_update_property_zval(this_ptr, ZEND_STRL("dirtyState"), &_9$$15);
	}
	if (hasRelatedToSave) {
		if (ZEPHIR_IS_FALSE_IDENTICAL(&success)) {
			ZVAL_BOOL(&_10$$17, 0);
			ZEPHIR_CALL_METHOD(NULL, &writeConnection, "rollback", NULL, 0, &_10$$17);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&success, this_ptr, "postsaverelatedrecords", NULL, 0, &writeConnection, &relatedToSave, visited);
			zephir_check_call_status();
		}
	}
	if (ZEPHIR_GLOBAL(orm).events) {
		ZEPHIR_CALL_METHOD(&_11$$19, this_ptr, "postsave", NULL, 0, &success, &exists);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&success, &_11$$19);
	}
	if (ZEPHIR_IS_FALSE_IDENTICAL(&success)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "canceloperation", NULL, 0);
		zephir_check_call_status();
	} else {
		if (hasRelatedToSave) {
			ZEPHIR_INIT_VAR(&_12$$22);
			array_init(&_12$$22);
			zephir_update_property_zval(this_ptr, ZEND_STRL("dirtyRelated"), &_12$$22);
		}
		ZEPHIR_INIT_VAR(&_13$$21);
		ZVAL_STRING(&_13$$21, "afterSave");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_13$$21);
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
	zend_bool _3, _4;
	zval attributes, manager, dirtyState, snapshot, _0, _1, _2, _5$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&dirtyState);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&snapshot);
	ZVAL_NULL(&snapshot);
	ZVAL_NULL(&_0);
	ZVAL_BOOL(&_1, 0);
	ZEPHIR_CALL_METHOD(&attributes, this_ptr, "toarray", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("dirtyState"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dirtyState, &_0);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_2);
	ZEPHIR_CALL_METHOD(&_2, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
	zephir_check_call_status();
	_3 = zephir_is_true(&_2);
	if (_3) {
		zephir_read_property(&_0, this_ptr, ZEND_STRL("snapshot"), PH_NOISY_CC | PH_READONLY);
		_3 = Z_TYPE_P(&_0) != IS_NULL;
	}
	_4 = _3;
	if (_4) {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("snapshot"), PH_NOISY_CC | PH_READONLY);
		_4 = !ZEPHIR_IS_EQUAL(&attributes, &_1);
	}
	if (_4) {
		zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("snapshot"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&snapshot, &_5$$3);
	}
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 3, 0);
	zephir_array_update_string(&_6, SL("attributes"), &attributes, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_6, SL("snapshot"), &snapshot, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_6, SL("dirtyState"), &dirtyState, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 15, &_6);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Unserializes the object from a serialized string
 */
PHP_METHOD(Phalcon_Mvc_Model, unserialize)
{
	zend_string *_12$$7;
	zend_ulong _11$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, attributes, container, manager, key, value, snapshot, properties, dirtyState, _0$$4, _1$$5, _2$$5, _3$$5, _4$$3, _5$$3, _6$$6, _7$$6, _8$$6, *_9$$7, _10$$7;
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
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$7);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &data);
	ZEPHIR_CALL_FUNCTION(&attributes, "unserialize", NULL, 16, data);
	zephir_check_call_status();
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		if (!(zephir_array_isset_string(&attributes, SL("attributes")))) {
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_create_array(&_0$$4, 1, 0);
			zephir_array_update_string(&_0$$4, SL("attributes"), &attributes, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&attributes, &_0$$4);
		}
		ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_di_ce, "getdefault", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&container) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$5);
			object_init_ex(&_1$$5, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_VAR(&_2$$5);
			zephir_get_class(&_2$$5, this_ptr, 0);
			ZEPHIR_INIT_VAR(&_3$$5);
			ZEPHIR_CONCAT_SVS(&_3$$5, "A dependency injection container is required to access the services related to the ODM in '", &_2$$5, "'");
			ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", NULL, 33, &_3$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$5, "phalcon/Mvc/Model.zep", 2834);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("container"), &container);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "modelsManager");
		ZEPHIR_CALL_METHOD(&_4$$3, &container, "getshared", NULL, 0, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&manager, &_4$$3);
		if (UNEXPECTED(Z_TYPE_P(&manager) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_6$$6);
			object_init_ex(&_6$$6, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_VAR(&_7$$6);
			zephir_get_class(&_7$$6, this_ptr, 0);
			ZEPHIR_INIT_VAR(&_8$$6);
			ZEPHIR_CONCAT_SVS(&_8$$6, "The injected service 'modelsManager' is not valid in '", &_7$$6, "'");
			ZEPHIR_CALL_METHOD(NULL, &_6$$6, "__construct", NULL, 33, &_8$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$6, "phalcon/Mvc/Model.zep", 2850);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("modelsManager"), &manager);
		ZEPHIR_CALL_METHOD(NULL, &manager, "initialize", NULL, 0, this_ptr);
		zephir_check_call_status();
		zephir_memory_observe(&properties);
		if (zephir_array_isset_string_fetch(&properties, &attributes, SL("attributes"), 0)) {
			zephir_is_iterable(&properties, 0, "phalcon/Mvc/Model.zep", 2873);
			if (Z_TYPE_P(&properties) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&properties), _11$$7, _12$$7, _9$$7)
				{
					ZEPHIR_INIT_NVAR(&key);
					if (_12$$7 != NULL) { 
						ZVAL_STR_COPY(&key, _12$$7);
					} else {
						ZVAL_LONG(&key, _11$$7);
					}
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_COPY(&value, _9$$7);
					zephir_update_property_zval_zval(this_ptr, &key, &value);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &properties, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_10$$7, &properties, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_10$$7)) {
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
		zephir_memory_observe(&dirtyState);
		if (zephir_array_isset_string_fetch(&dirtyState, &attributes, SL("dirtyState"), 0)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("dirtyState"), &dirtyState);
		}
		ZEPHIR_CALL_METHOD(&_4$$3, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (zephir_is_true(&_4$$3)) {
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(connectionService)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(dirtyState)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &dirtyState_param);
	ZVAL_UNDEF(&_0);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, phalcon_events_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(connectionService)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *columnMap = NULL, columnMap_sub, __$null, key, value, attribute, *_0$$3, _1$$3, _4$$7, _5$$7, _6$$7, _8$$10, _9$$10, _10$$10, _11$$14, _12$$14, _13$$14, _14$$17, _15$$17, _16$$17;
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
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_11$$14);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_14$$17);
	ZVAL_UNDEF(&_15$$17);
	ZVAL_UNDEF(&_16$$17);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(columnMap)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &data_param, &columnMap);
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	if (!columnMap) {
		columnMap = &columnMap_sub;
		columnMap = &__$null;
	}
	if (Z_TYPE_P(columnMap) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&snapshot);
		array_init(&snapshot);
		zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 2991);
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
						zephir_get_class(&_5$$7, this_ptr, 0);
						ZEPHIR_INIT_NVAR(&_6$$7);
						ZEPHIR_CONCAT_SVSVS(&_6$$7, "Column '", &key, "' doesn't make part of the column map in '", &_5$$7, "'");
						ZEPHIR_CALL_METHOD(NULL, &_4$$7, "__construct", &_7, 33, &_6$$7);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_4$$7, "phalcon/Mvc/Model.zep", 2971);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
				if (Z_TYPE_P(&attribute) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attribute);
					if (!(zephir_array_isset_long_fetch(&attribute, &attribute, 0, 0))) {
						if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
							ZEPHIR_INIT_NVAR(&_8$$10);
							object_init_ex(&_8$$10, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_9$$10);
							zephir_get_class(&_9$$10, this_ptr, 0);
							ZEPHIR_INIT_NVAR(&_10$$10);
							ZEPHIR_CONCAT_SVSVS(&_10$$10, "Column '", &key, "' doesn't make part of the column map in '", &_9$$10, "'");
							ZEPHIR_CALL_METHOD(NULL, &_8$$10, "__construct", &_7, 33, &_10$$10);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_8$$10, "phalcon/Mvc/Model.zep", 2982);
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
							ZEPHIR_INIT_NVAR(&_11$$14);
							object_init_ex(&_11$$14, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_12$$14);
							zephir_get_class(&_12$$14, this_ptr, 0);
							ZEPHIR_INIT_NVAR(&_13$$14);
							ZEPHIR_CONCAT_SVSVS(&_13$$14, "Column '", &key, "' doesn't make part of the column map in '", &_12$$14, "'");
							ZEPHIR_CALL_METHOD(NULL, &_11$$14, "__construct", &_7, 33, &_13$$14);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_11$$14, "phalcon/Mvc/Model.zep", 2971);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
					if (Z_TYPE_P(&attribute) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attribute);
						if (!(zephir_array_isset_long_fetch(&attribute, &attribute, 0, 0))) {
							if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
								ZEPHIR_INIT_NVAR(&_14$$17);
								object_init_ex(&_14$$17, phalcon_mvc_model_exception_ce);
								ZEPHIR_INIT_NVAR(&_15$$17);
								zephir_get_class(&_15$$17, this_ptr, 0);
								ZEPHIR_INIT_NVAR(&_16$$17);
								ZEPHIR_CONCAT_SVSVS(&_16$$17, "Column '", &key, "' doesn't make part of the column map in '", &_15$$17, "'");
								ZEPHIR_CALL_METHOD(NULL, &_14$$17, "__construct", &_7, 33, &_16$$17);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_14$$17, "phalcon/Mvc/Model.zep", 2982);
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
	zend_bool _4$$4, _14$$12;
	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *columnMap = NULL, columnMap_sub, __$null, key, value, attribute, *_0$$3, _1$$3, _5$$6, _7$$8, _8$$8, _9$$8, _11$$11, _12$$11, _13$$11, _15$$14, _16$$16, _17$$16, _18$$16, _19$$19, _20$$19, _21$$19;
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
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_16$$16);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&_18$$16);
	ZVAL_UNDEF(&_19$$19);
	ZVAL_UNDEF(&_20$$19);
	ZVAL_UNDEF(&_21$$19);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(columnMap)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &data_param, &columnMap);
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	if (!columnMap) {
		columnMap = &columnMap_sub;
		columnMap = &__$null;
	}
	if (Z_TYPE_P(columnMap) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&snapshot);
		array_init(&snapshot);
		zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 3056);
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
					ZEPHIR_CALL_SELF(&_5$$6, "caseinsensitivecolumnmap", &_6, 420, columnMap, &key);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&key, &_5$$6);
				}
				ZEPHIR_OBS_NVAR(&attribute);
				if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0))) {
					if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
						ZEPHIR_INIT_NVAR(&_7$$8);
						object_init_ex(&_7$$8, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_8$$8);
						zephir_get_class(&_8$$8, this_ptr, 0);
						ZEPHIR_INIT_NVAR(&_9$$8);
						ZEPHIR_CONCAT_SVSVS(&_9$$8, "Column '", &key, "' doesn't make part of the column map in '", &_8$$8, "'");
						ZEPHIR_CALL_METHOD(NULL, &_7$$8, "__construct", &_10, 33, &_9$$8);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_7$$8, "phalcon/Mvc/Model.zep", 3036);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
				if (Z_TYPE_P(&attribute) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attribute);
					if (!(zephir_array_isset_long_fetch(&attribute, &attribute, 0, 0))) {
						if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
							ZEPHIR_INIT_NVAR(&_11$$11);
							object_init_ex(&_11$$11, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_12$$11);
							zephir_get_class(&_12$$11, this_ptr, 0);
							ZEPHIR_INIT_NVAR(&_13$$11);
							ZEPHIR_CONCAT_SVSVS(&_13$$11, "Column '", &key, "' doesn't make part of the column map in '", &_12$$11, "'");
							ZEPHIR_CALL_METHOD(NULL, &_11$$11, "__construct", &_10, 33, &_13$$11);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_11$$11, "phalcon/Mvc/Model.zep", 3047);
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
					_14$$12 = !(zephir_array_isset(columnMap, &key));
					if (_14$$12) {
						_14$$12 = ZEPHIR_GLOBAL(orm).case_insensitive_column_map;
					}
					if (_14$$12) {
						ZEPHIR_CALL_SELF(&_15$$14, "caseinsensitivecolumnmap", &_6, 420, columnMap, &key);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&key, &_15$$14);
					}
					ZEPHIR_OBS_NVAR(&attribute);
					if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0))) {
						if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
							ZEPHIR_INIT_NVAR(&_16$$16);
							object_init_ex(&_16$$16, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_17$$16);
							zephir_get_class(&_17$$16, this_ptr, 0);
							ZEPHIR_INIT_NVAR(&_18$$16);
							ZEPHIR_CONCAT_SVSVS(&_18$$16, "Column '", &key, "' doesn't make part of the column map in '", &_17$$16, "'");
							ZEPHIR_CALL_METHOD(NULL, &_16$$16, "__construct", &_10, 33, &_18$$16);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_16$$16, "phalcon/Mvc/Model.zep", 3036);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
					if (Z_TYPE_P(&attribute) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attribute);
						if (!(zephir_array_isset_long_fetch(&attribute, &attribute, 0, 0))) {
							if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
								ZEPHIR_INIT_NVAR(&_19$$19);
								object_init_ex(&_19$$19, phalcon_mvc_model_exception_ce);
								ZEPHIR_INIT_NVAR(&_20$$19);
								zephir_get_class(&_20$$19, this_ptr, 0);
								ZEPHIR_INIT_NVAR(&_21$$19);
								ZEPHIR_CONCAT_SVSVS(&_21$$19, "Column '", &key, "' doesn't make part of the column map in '", &_20$$19, "'");
								ZEPHIR_CALL_METHOD(NULL, &_19$$19, "__construct", &_10, 33, &_21$$19);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_19$$19, "phalcon/Mvc/Model.zep", 3047);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(transaction, phalcon_mvc_model_transactioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &transaction);
	zephir_update_property_zval(this_ptr, ZEND_STRL("transaction"), transaction);
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Mvc_Model, getTransaction)
{

	RETURN_MEMBER(getThis(), "transaction");
}

/**
 * Enables/disables options in the ORM
 */
PHP_METHOD(Phalcon_Mvc_Model, setup)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL, disableEvents, columnRenaming, notNullValidations, exceptionOnFailedSave, exceptionOnFailedMetaDataSave, phqlLiterals, virtualForeignKeys, lateStateBinding, castOnHydrate, ignoreUnknownColumns, updateSnapshotOnSave, disableAssignSetters, caseInsensitiveColumnMap, prefetchRecords, lastInsertId;
	zval options;

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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &options_param);
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	zephir_memory_observe(&disableEvents);
	if (zephir_array_isset_string_fetch(&disableEvents, &options, SL("events"), 0)) {
		ZEPHIR_GLOBAL(orm).events = zend_is_true(&disableEvents);
	}
	zephir_memory_observe(&virtualForeignKeys);
	if (zephir_array_isset_string_fetch(&virtualForeignKeys, &options, SL("virtualForeignKeys"), 0)) {
		ZEPHIR_GLOBAL(orm).virtual_foreign_keys = zend_is_true(&virtualForeignKeys);
	}
	zephir_memory_observe(&columnRenaming);
	if (zephir_array_isset_string_fetch(&columnRenaming, &options, SL("columnRenaming"), 0)) {
		ZEPHIR_GLOBAL(orm).column_renaming = zend_is_true(&columnRenaming);
	}
	zephir_memory_observe(&notNullValidations);
	if (zephir_array_isset_string_fetch(&notNullValidations, &options, SL("notNullValidations"), 0)) {
		ZEPHIR_GLOBAL(orm).not_null_validations = zend_is_true(&notNullValidations);
	}
	zephir_memory_observe(&exceptionOnFailedSave);
	if (zephir_array_isset_string_fetch(&exceptionOnFailedSave, &options, SL("exceptionOnFailedSave"), 0)) {
		ZEPHIR_GLOBAL(orm).exception_on_failed_save = zend_is_true(&exceptionOnFailedSave);
	}
	zephir_memory_observe(&exceptionOnFailedMetaDataSave);
	if (zephir_array_isset_string_fetch(&exceptionOnFailedMetaDataSave, &options, SL("exceptionOnFailedMetaDataSave"), 0)) {
		ZEPHIR_GLOBAL(orm).exception_on_failed_metadata_save = zend_is_true(&exceptionOnFailedMetaDataSave);
	}
	zephir_memory_observe(&phqlLiterals);
	if (zephir_array_isset_string_fetch(&phqlLiterals, &options, SL("phqlLiterals"), 0)) {
		ZEPHIR_GLOBAL(orm).enable_literals = zend_is_true(&phqlLiterals);
	}
	zephir_memory_observe(&lateStateBinding);
	if (zephir_array_isset_string_fetch(&lateStateBinding, &options, SL("lateStateBinding"), 0)) {
		ZEPHIR_GLOBAL(orm).late_state_binding = zend_is_true(&lateStateBinding);
	}
	zephir_memory_observe(&castOnHydrate);
	if (zephir_array_isset_string_fetch(&castOnHydrate, &options, SL("castOnHydrate"), 0)) {
		ZEPHIR_GLOBAL(orm).cast_on_hydrate = zend_is_true(&castOnHydrate);
	}
	zephir_memory_observe(&ignoreUnknownColumns);
	if (zephir_array_isset_string_fetch(&ignoreUnknownColumns, &options, SL("ignoreUnknownColumns"), 0)) {
		ZEPHIR_GLOBAL(orm).ignore_unknown_columns = zend_is_true(&ignoreUnknownColumns);
	}
	zephir_memory_observe(&caseInsensitiveColumnMap);
	if (zephir_array_isset_string_fetch(&caseInsensitiveColumnMap, &options, SL("caseInsensitiveColumnMap"), 0)) {
		ZEPHIR_GLOBAL(orm).case_insensitive_column_map = zend_is_true(&caseInsensitiveColumnMap);
	}
	zephir_memory_observe(&updateSnapshotOnSave);
	if (zephir_array_isset_string_fetch(&updateSnapshotOnSave, &options, SL("updateSnapshotOnSave"), 0)) {
		ZEPHIR_GLOBAL(orm).update_snapshot_on_save = zend_is_true(&updateSnapshotOnSave);
	}
	zephir_memory_observe(&disableAssignSetters);
	if (zephir_array_isset_string_fetch(&disableAssignSetters, &options, SL("disableAssignSetters"), 0)) {
		ZEPHIR_GLOBAL(orm).disable_assign_setters = zend_is_true(&disableAssignSetters);
	}
	zephir_memory_observe(&prefetchRecords);
	if (zephir_array_isset_string_fetch(&prefetchRecords, &options, SL("prefetchRecords"), 0)) {
		ZEPHIR_GLOBAL(orm).resultset_prefetch_records = ZSTR_VAL(zval_get_string(&prefetchRecords));
	}
	zephir_memory_observe(&lastInsertId);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(connectionService)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(skip)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &skip_param);
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

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zend_bool _3$$4, _11$$3, _13$$3, _16$$15, _22$$14, _24$$14;
	zval data;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *columns = NULL, columns_sub, *useGetter = NULL, useGetter_sub, __$null, __$true, attribute, attributeField, columnMap, metaData, method, _0, *_1, _2, _4$$5, _6$$7, _7$$7, _8$$7, _10$$3, _12$$3, _14$$11, _15$$12, _17$$16, _18$$18, _19$$18, _20$$18, _21$$14, _23$$14, _25$$22, _26$$23;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columns_sub);
	ZVAL_UNDEF(&useGetter_sub);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&_18$$18);
	ZVAL_UNDEF(&_19$$18);
	ZVAL_UNDEF(&_20$$18);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_25$$22);
	ZVAL_UNDEF(&_26$$23);
	ZVAL_UNDEF(&data);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(columns)
		Z_PARAM_ZVAL(useGetter)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &columns, &useGetter);
	if (!columns) {
		columns = &columns_sub;
		columns = &__$null;
	}
	if (!useGetter) {
		useGetter = &useGetter_sub;
		useGetter = &__$true;
	}
	ZEPHIR_INIT_VAR(&data);
	array_init(&data);
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &metaData, "getattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/Mvc/Model.zep", 3343);
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
					ZEPHIR_CALL_SELF(&_4$$5, "caseinsensitivecolumnmap", &_5, 420, &columnMap, &attribute);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&attribute, &_4$$5);
				}
				ZEPHIR_OBS_NVAR(&attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0))) {
					if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
						ZEPHIR_INIT_NVAR(&_6$$7);
						object_init_ex(&_6$$7, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_7$$7);
						zephir_get_class(&_7$$7, this_ptr, 0);
						ZEPHIR_INIT_NVAR(&_8$$7);
						ZEPHIR_CONCAT_SVSVS(&_8$$7, "Column '", &attribute, "' doesn't make part of the column map in '", &_7$$7, "'");
						ZEPHIR_CALL_METHOD(NULL, &_6$$7, "__construct", &_9, 33, &_8$$7);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_6$$7, "phalcon/Mvc/Model.zep", 3311);
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
			ZEPHIR_INIT_NVAR(&_10$$3);
			zephir_camelize(&_10$$3, &attributeField, NULL );
			ZEPHIR_INIT_NVAR(&method);
			ZEPHIR_CONCAT_SV(&method, "get", &_10$$3);
			_11$$3 = ZEPHIR_IS_TRUE_IDENTICAL(useGetter);
			if (_11$$3) {
				ZEPHIR_INIT_NVAR(&_12$$3);
				ZVAL_STRING(&_12$$3, "getSource");
				_11$$3 = !ZEPHIR_IS_IDENTICAL(&_12$$3, &method);
			}
			_13$$3 = _11$$3;
			if (_13$$3) {
				_13$$3 = (zephir_method_exists(this_ptr, &method)  == SUCCESS);
			}
			if (_13$$3) {
				ZEPHIR_CALL_METHOD_ZVAL(&_14$$11, this_ptr, &method, NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&data, &attributeField, &_14$$11, PH_COPY | PH_SEPARATE);
			} else if (zephir_isset_property_zval(this_ptr, &attributeField)) {
				ZEPHIR_OBS_NVAR(&_15$$12);
				zephir_read_property_zval(&_15$$12, this_ptr, &attributeField, PH_NOISY_CC);
				zephir_array_update_zval(&data, &attributeField, &_15$$12, PH_COPY | PH_SEPARATE);
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
					_16$$15 = !(zephir_array_isset(&columnMap, &attribute));
					if (_16$$15) {
						_16$$15 = ZEPHIR_GLOBAL(orm).case_insensitive_column_map;
					}
					if (_16$$15) {
						ZEPHIR_CALL_SELF(&_17$$16, "caseinsensitivecolumnmap", &_5, 420, &columnMap, &attribute);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&attribute, &_17$$16);
					}
					ZEPHIR_OBS_NVAR(&attributeField);
					if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0))) {
						if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
							ZEPHIR_INIT_NVAR(&_18$$18);
							object_init_ex(&_18$$18, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_19$$18);
							zephir_get_class(&_19$$18, this_ptr, 0);
							ZEPHIR_INIT_NVAR(&_20$$18);
							ZEPHIR_CONCAT_SVSVS(&_20$$18, "Column '", &attribute, "' doesn't make part of the column map in '", &_19$$18, "'");
							ZEPHIR_CALL_METHOD(NULL, &_18$$18, "__construct", &_9, 33, &_20$$18);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_18$$18, "phalcon/Mvc/Model.zep", 3311);
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
				ZEPHIR_INIT_NVAR(&_21$$14);
				zephir_camelize(&_21$$14, &attributeField, NULL );
				ZEPHIR_INIT_NVAR(&method);
				ZEPHIR_CONCAT_SV(&method, "get", &_21$$14);
				_22$$14 = ZEPHIR_IS_TRUE_IDENTICAL(useGetter);
				if (_22$$14) {
					ZEPHIR_INIT_NVAR(&_23$$14);
					ZVAL_STRING(&_23$$14, "getSource");
					_22$$14 = !ZEPHIR_IS_IDENTICAL(&_23$$14, &method);
				}
				_24$$14 = _22$$14;
				if (_24$$14) {
					_24$$14 = (zephir_method_exists(this_ptr, &method)  == SUCCESS);
				}
				if (_24$$14) {
					ZEPHIR_CALL_METHOD_ZVAL(&_25$$22, this_ptr, &method, NULL, 0);
					zephir_check_call_status();
					zephir_array_update_zval(&data, &attributeField, &_25$$22, PH_COPY | PH_SEPARATE);
				} else if (zephir_isset_property_zval(this_ptr, &attributeField)) {
					ZEPHIR_OBS_NVAR(&_26$$23);
					zephir_read_property_zval(&_26$$23, this_ptr, &attributeField, PH_NOISY_CC);
					zephir_array_update_zval(&data, &attributeField, &_26$$23, PH_COPY | PH_SEPARATE);
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
 * persistence it will throw an exception. Returning `true` on success or
 * `false` otherwise.
 *
 * ```php
 * <?php
 *
 * use MyApp\Models\Invoices;
 *
 * $invoice = Invoices::findFirst('inv_id = 4');
 *
 * $invoice->inv_total = 120;
 *
 * $invoice->update();
 * ```
 *
 * !!! warning "NOTE"
 *
 *     When retrieving the record with `findFirst()`, you need to get the full
 *     object back (no `columns` definition) but also retrieve it using the
 *     primary key. If not, the ORM will issue an `INSERT` instead of `UPDATE`.
 */
PHP_METHOD(Phalcon_Mvc_Model, update)
{
	zval _3$$4, _5$$4;
	zval metaData, _0, _1$$3, _2$$3, _4$$4, _6$$4, _7$$4, _8$$4, _9$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("dirtyState"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "getreadconnection", NULL, 431);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "has", NULL, 0, &metaData, &_2$$3);
		zephir_check_call_status();
		if (!(zephir_is_true(&_1$$3))) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_create_array(&_3$$4, 1, 0);
			ZEPHIR_INIT_VAR(&_4$$4);
			object_init_ex(&_4$$4, phalcon_messages_message_ce);
			ZEPHIR_INIT_VAR(&_5$$4);
			zephir_create_array(&_5$$4, 1, 0);
			ZEPHIR_INIT_VAR(&_6$$4);
			zephir_get_class(&_6$$4, this_ptr, 0);
			zephir_array_update_string(&_5$$4, SL("model"), &_6$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_6$$4);
			ZVAL_STRING(&_6$$4, "Record cannot be updated because it does not exist");
			ZVAL_NULL(&_7$$4);
			ZEPHIR_INIT_VAR(&_8$$4);
			ZVAL_STRING(&_8$$4, "InvalidUpdateAttempt");
			ZVAL_LONG(&_9$$4, 0);
			ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 6, &_6$$4, &_7$$4, &_8$$4, &_9$$4, &_5$$4);
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
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(attribute)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zend_string *_9$$7, *_33$$26;
	zend_ulong _8$$7, _32$$26;
	zend_bool error = 0, validateWithNulls = 0, _15$$3, _39$$22;
	zval conditions, _17$$3, _21$$18, _41$$22, _45$$37;
	zval manager, belongsTo, foreignKey, relation, position, bindParams, extraConditions, message, fields, referencedFields, field, referencedModel, value, allowNulls, _0, *_1, _2, _3$$5, _4$$3, _16$$3, _18$$3, *_6$$7, _7$$7, _10$$8, _11$$8, _12$$10, _13$$10, _14$$12, _19$$20, _20$$18, _22$$18, _23$$18, _24$$18, _27$$24, _28$$22, _40$$22, _42$$22, *_30$$26, _31$$26, _34$$27, _35$$27, _36$$29, _37$$29, _38$$31, _43$$39, _44$$37, _46$$37, _47$$37, _48$$37, _49$$42;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_25 = NULL, *_26 = NULL, *_29 = NULL;
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
	ZVAL_UNDEF(&_22$$18);
	ZVAL_UNDEF(&_23$$18);
	ZVAL_UNDEF(&_24$$18);
	ZVAL_UNDEF(&_27$$24);
	ZVAL_UNDEF(&_28$$22);
	ZVAL_UNDEF(&_40$$22);
	ZVAL_UNDEF(&_42$$22);
	ZVAL_UNDEF(&_31$$26);
	ZVAL_UNDEF(&_34$$27);
	ZVAL_UNDEF(&_35$$27);
	ZVAL_UNDEF(&_36$$29);
	ZVAL_UNDEF(&_37$$29);
	ZVAL_UNDEF(&_38$$31);
	ZVAL_UNDEF(&_43$$39);
	ZVAL_UNDEF(&_44$$37);
	ZVAL_UNDEF(&_46$$37);
	ZVAL_UNDEF(&_47$$37);
	ZVAL_UNDEF(&_48$$37);
	ZVAL_UNDEF(&_49$$42);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_21$$18);
	ZVAL_UNDEF(&_41$$22);
	ZVAL_UNDEF(&_45$$37);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&belongsTo, &manager, "getbelongsto", NULL, 0, this_ptr);
	zephir_check_call_status();
	error = 0;
	zephir_is_iterable(&belongsTo, 0, "phalcon/Mvc/Model.zep", 3572);
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
				zephir_array_fetch_string(&_3$$5, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 3458);
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
				zephir_is_iterable(&fields, 0, "phalcon/Mvc/Model.zep", 3501);
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
						zephir_array_fetch(&_10$$8, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3493);
						ZEPHIR_INIT_NVAR(&_11$$8);
						ZEPHIR_CONCAT_SVSV(&_11$$8, "[", &_10$$8, "] = ?", &position);
						zephir_array_append(&conditions, &_11$$8, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3493);
						zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3494);
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
							zephir_array_fetch(&_12$$10, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3493);
							ZEPHIR_INIT_NVAR(&_13$$10);
							ZEPHIR_CONCAT_SVSV(&_13$$10, "[", &_12$$10, "] = ?", &position);
							zephir_array_append(&conditions, &_13$$10, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3493);
							zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3494);
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
				zephir_array_append(&conditions, &_14$$12, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3505);
				zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3506);
				if (Z_TYPE_P(&value) == IS_NULL) {
					validateWithNulls = 1;
				}
			}
			ZEPHIR_OBS_NVAR(&extraConditions);
			if (zephir_array_isset_string_fetch(&extraConditions, &foreignKey, SL("conditions"), 0)) {
				zephir_array_append(&conditions, &extraConditions, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3517);
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
				zephir_create_array(&_21$$18, 2, 0);
				ZEPHIR_INIT_NVAR(&_22$$18);
				zephir_get_class(&_22$$18, this_ptr, 0);
				zephir_array_update_string(&_21$$18, SL("model"), &_22$$18, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_23$$18, &relation, "getreferencedmodel", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_21$$18, SL("referenceModel"), &_23$$18, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_22$$18);
				ZVAL_STRING(&_22$$18, "ConstraintViolation");
				ZVAL_LONG(&_24$$18, 0);
				ZEPHIR_CALL_METHOD(NULL, &_20$$18, "__construct", &_25, 6, &message, &fields, &_22$$18, &_24$$18, &_21$$18);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_26, 0, &_20$$18);
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
					ZEPHIR_OBS_NVAR(&_27$$24);
					zephir_array_fetch_string(&_27$$24, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 3458);
					action = zephir_get_intval(&_27$$24);
				}
				if (action != 1) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&_28$$22, &relation, "getreferencedmodel", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedModel, &manager, "load", &_29, 0, &_28$$22);
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
					zephir_is_iterable(&fields, 0, "phalcon/Mvc/Model.zep", 3501);
					if (Z_TYPE_P(&fields) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _32$$26, _33$$26, _30$$26)
						{
							ZEPHIR_INIT_NVAR(&position);
							if (_33$$26 != NULL) { 
								ZVAL_STR_COPY(&position, _33$$26);
							} else {
								ZVAL_LONG(&position, _32$$26);
							}
							ZEPHIR_INIT_NVAR(&field);
							ZVAL_COPY(&field, _30$$26);
							ZEPHIR_OBS_NVAR(&value);
							zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
							zephir_array_fetch(&_34$$27, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3493);
							ZEPHIR_INIT_NVAR(&_35$$27);
							ZEPHIR_CONCAT_SVSV(&_35$$27, "[", &_34$$27, "] = ?", &position);
							zephir_array_append(&conditions, &_35$$27, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3493);
							zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3494);
							if (Z_TYPE_P(&value) == IS_NULL) {
								numberNull++;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_31$$26, &fields, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_31$$26)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&position, &fields, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&field, &fields, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_OBS_NVAR(&value);
								zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
								zephir_array_fetch(&_36$$29, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3493);
								ZEPHIR_INIT_NVAR(&_37$$29);
								ZEPHIR_CONCAT_SVSV(&_37$$29, "[", &_36$$29, "] = ?", &position);
								zephir_array_append(&conditions, &_37$$29, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3493);
								zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3494);
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
					ZEPHIR_INIT_NVAR(&_38$$31);
					ZEPHIR_CONCAT_SVS(&_38$$31, "[", &referencedFields, "] = ?0");
					zephir_array_append(&conditions, &_38$$31, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3505);
					zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3506);
					if (Z_TYPE_P(&value) == IS_NULL) {
						validateWithNulls = 1;
					}
				}
				ZEPHIR_OBS_NVAR(&extraConditions);
				if (zephir_array_isset_string_fetch(&extraConditions, &foreignKey, SL("conditions"), 0)) {
					zephir_array_append(&conditions, &extraConditions, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3517);
				}
				if (validateWithNulls) {
					ZEPHIR_OBS_NVAR(&allowNulls);
					if (zephir_array_isset_string_fetch(&allowNulls, &foreignKey, SL("allowNulls"), 0)) {
						validateWithNulls = zephir_get_boolval(&allowNulls);
					} else {
						validateWithNulls = 0;
					}
				}
				_39$$22 = !validateWithNulls;
				if (_39$$22) {
					ZEPHIR_INIT_NVAR(&_41$$22);
					zephir_create_array(&_41$$22, 2, 0);
					ZEPHIR_INIT_NVAR(&_42$$22);
					zephir_fast_join_str(&_42$$22, SL(" AND "), &conditions);
					zephir_array_fast_append(&_41$$22, &_42$$22);
					zephir_array_update_string(&_41$$22, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_40$$22, &referencedModel, "count", NULL, 0, &_41$$22);
					zephir_check_call_status();
					_39$$22 = !zephir_is_true(&_40$$22);
				}
				if (_39$$22) {
					ZEPHIR_OBS_NVAR(&message);
					if (!(zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0))) {
						ZEPHIR_INIT_NVAR(&message);
						if (Z_TYPE_P(&fields) == IS_ARRAY) {
							ZEPHIR_INIT_NVAR(&_43$$39);
							zephir_fast_join_str(&_43$$39, SL(", "), &fields);
							ZEPHIR_CONCAT_SVS(&message, "Value of fields \"", &_43$$39, "\" does not exist on referenced table");
						} else {
							ZEPHIR_CONCAT_SVS(&message, "Value of field \"", &fields, "\" does not exist on referenced table");
						}
					}
					ZEPHIR_INIT_NVAR(&_44$$37);
					object_init_ex(&_44$$37, phalcon_messages_message_ce);
					ZEPHIR_INIT_NVAR(&_45$$37);
					zephir_create_array(&_45$$37, 2, 0);
					ZEPHIR_INIT_NVAR(&_46$$37);
					zephir_get_class(&_46$$37, this_ptr, 0);
					zephir_array_update_string(&_45$$37, SL("model"), &_46$$37, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_47$$37, &relation, "getreferencedmodel", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_string(&_45$$37, SL("referenceModel"), &_47$$37, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_46$$37);
					ZVAL_STRING(&_46$$37, "ConstraintViolation");
					ZVAL_LONG(&_48$$37, 0);
					ZEPHIR_CALL_METHOD(NULL, &_44$$37, "__construct", &_25, 6, &message, &fields, &_46$$37, &_48$$37, &_45$$37);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_26, 0, &_44$$37);
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
			ZEPHIR_INIT_VAR(&_49$$42);
			ZVAL_STRING(&_49$$42, "onValidationFails");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_49$$42);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&relations, &manager, "gethasoneandhasmany", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(&relations, 0, "phalcon/Mvc/Model.zep", 3648);
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
				zephir_array_fetch_string(&_4$$5, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 3622);
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
					zephir_array_fetch_string(&_8$$11, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 3622);
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
	zval _10$$7, _22$$13;
	zval manager, relations, foreignKey, relation, relationClass, fields, message, _0, *_1, _2, _5$$3, _6$$3, _7$$3, _4$$5, _9$$7, _11$$7, _12$$7, _17$$9, _18$$9, _19$$9, _16$$11, _21$$13, _23$$13, _24$$13, _25$$16;
	zend_bool error = 0, _3$$3, _15$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_13 = NULL, *_14 = NULL, *_20 = NULL;
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
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_22$$13);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&relations, &manager, "gethasoneandhasmany", NULL, 0, this_ptr);
	zephir_check_call_status();
	error = 0;
	zephir_is_iterable(&relations, 0, "phalcon/Mvc/Model.zep", 3739);
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
				zephir_array_fetch_string(&_4$$5, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 3693);
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
				zephir_create_array(&_10$$7, 2, 0);
				ZEPHIR_INIT_NVAR(&_11$$7);
				zephir_get_class(&_11$$7, this_ptr, 0);
				zephir_array_update_string(&_10$$7, SL("model"), &_11$$7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_10$$7, SL("referenceModel"), &relationClass, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_11$$7);
				ZVAL_STRING(&_11$$7, "ConstraintViolation");
				ZVAL_LONG(&_12$$7, 0);
				ZEPHIR_CALL_METHOD(NULL, &_9$$7, "__construct", &_13, 6, &message, &fields, &_11$$7, &_12$$7, &_10$$7);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_14, 0, &_9$$7);
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
				_15$$9 = Z_TYPE_P(&foreignKey) == IS_ARRAY;
				if (_15$$9) {
					_15$$9 = zephir_array_isset_string(&foreignKey, SL("action"));
				}
				if (_15$$9) {
					ZEPHIR_OBS_NVAR(&_16$$11);
					zephir_array_fetch_string(&_16$$11, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 3693);
					action = zephir_get_intval(&_16$$11);
				}
				if (action != 1) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&relationClass, &relation, "getreferencedmodel", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&fields, &relation, "getfields", NULL, 0);
				zephir_check_call_status();
				ZVAL_NULL(&_18$$9);
				ZEPHIR_INIT_NVAR(&_19$$9);
				ZVAL_STRING(&_19$$9, "count");
				ZEPHIR_CALL_METHOD(&_17$$9, &manager, "getrelationrecords", &_20, 0, &relation, this_ptr, &_18$$9, &_19$$9);
				zephir_check_call_status();
				if (zephir_is_true(&_17$$9)) {
					ZEPHIR_OBS_NVAR(&message);
					if (!(zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0))) {
						ZEPHIR_INIT_NVAR(&message);
						ZEPHIR_CONCAT_SV(&message, "Record is referenced by model ", &relationClass);
					}
					ZEPHIR_INIT_NVAR(&_21$$13);
					object_init_ex(&_21$$13, phalcon_messages_message_ce);
					ZEPHIR_INIT_NVAR(&_22$$13);
					zephir_create_array(&_22$$13, 2, 0);
					ZEPHIR_INIT_NVAR(&_23$$13);
					zephir_get_class(&_23$$13, this_ptr, 0);
					zephir_array_update_string(&_22$$13, SL("model"), &_23$$13, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_22$$13, SL("referenceModel"), &relationClass, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_23$$13);
					ZVAL_STRING(&_23$$13, "ConstraintViolation");
					ZVAL_LONG(&_24$$13, 0);
					ZEPHIR_CALL_METHOD(NULL, &_21$$13, "__construct", &_13, 6, &message, &fields, &_23$$13, &_24$$13, &_22$$13);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_14, 0, &_21$$13);
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
			ZEPHIR_INIT_VAR(&_25$$16);
			ZVAL_STRING(&_25$$16, "onValidationFails");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_25$$16);
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
	zend_string *_58$$56;
	zend_ulong _57$$56;
	zend_bool useExplicitIdentity = 0, _51, _7$$11, _25$$26, _44$$40, _60$$56;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_11 = NULL, *_12 = NULL, *_19 = NULL, *_21 = NULL, *_29 = NULL, *_30 = NULL, *_37 = NULL, *_39 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *metaData, metaData_sub, *connection, connection_sub, *table = NULL, table_sub, *identityField, identityField_sub, __$null, attributeField, attributes, automaticAttributes, bindDataTypes, bindSkip, bindType, bindTypes, columnMap, defaultValue, defaultValues, field, fields, lastInsertedId, manager, sequenceName, schema, snapshot, source, success, unsetDefaultValues, value, values, _0, *_1, _2, _3$$7, _4$$7, _5$$7, _8$$12, _9$$12, _10$$12, _13$$15, _14$$15, _15$$15, _16$$17, _17$$17, _18$$17, _20$$17, _22$$22, _23$$22, _24$$22, _26$$27, _27$$27, _28$$27, _31$$30, _32$$30, _33$$30, _34$$32, _35$$32, _36$$32, _38$$32, _40$$35, _41$$38, _42$$38, _43$$38, _45$$45, _46$$45, _47$$45, _48$$48, _49$$48, _50$$48, _52$$49, _53$$55, _54$$55, *_55$$56, _56$$56, _59$$56;
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
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_9$$12);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_13$$15);
	ZVAL_UNDEF(&_14$$15);
	ZVAL_UNDEF(&_15$$15);
	ZVAL_UNDEF(&_16$$17);
	ZVAL_UNDEF(&_17$$17);
	ZVAL_UNDEF(&_18$$17);
	ZVAL_UNDEF(&_20$$17);
	ZVAL_UNDEF(&_22$$22);
	ZVAL_UNDEF(&_23$$22);
	ZVAL_UNDEF(&_24$$22);
	ZVAL_UNDEF(&_26$$27);
	ZVAL_UNDEF(&_27$$27);
	ZVAL_UNDEF(&_28$$27);
	ZVAL_UNDEF(&_31$$30);
	ZVAL_UNDEF(&_32$$30);
	ZVAL_UNDEF(&_33$$30);
	ZVAL_UNDEF(&_34$$32);
	ZVAL_UNDEF(&_35$$32);
	ZVAL_UNDEF(&_36$$32);
	ZVAL_UNDEF(&_38$$32);
	ZVAL_UNDEF(&_40$$35);
	ZVAL_UNDEF(&_41$$38);
	ZVAL_UNDEF(&_42$$38);
	ZVAL_UNDEF(&_43$$38);
	ZVAL_UNDEF(&_45$$45);
	ZVAL_UNDEF(&_46$$45);
	ZVAL_UNDEF(&_47$$45);
	ZVAL_UNDEF(&_48$$48);
	ZVAL_UNDEF(&_49$$48);
	ZVAL_UNDEF(&_50$$48);
	ZVAL_UNDEF(&_52$$49);
	ZVAL_UNDEF(&_53$$55);
	ZVAL_UNDEF(&_54$$55);
	ZVAL_UNDEF(&_56$$56);
	ZVAL_UNDEF(&_59$$56);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(metaData, phalcon_mvc_model_metadatainterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(connection, phalcon_db_adapter_adapterinterface_ce)
		Z_PARAM_ZVAL(table)
		Z_PARAM_ZVAL(identityField)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model.zep", 3861);
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
					zephir_get_class(&_4$$7, this_ptr, 0);
					ZEPHIR_INIT_NVAR(&_5$$7);
					ZEPHIR_CONCAT_SVSVS(&_5$$7, "Column '", &field, "' in '", &_4$$7, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, &_3$$7, "__construct", &_6, 33, &_5$$7);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_3$$7, "phalcon/Mvc/Model.zep", 3795);
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
						_7$$11 = Z_TYPE_P(&value) == IS_NULL;
						if (_7$$11) {
							_7$$11 = zephir_array_isset(&defaultValues, &field);
						}
						if (_7$$11) {
							zephir_array_fetch(&_8$$12, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3812);
							zephir_array_update_zval(&snapshot, &attributeField, &_8$$12, PH_COPY | PH_SEPARATE);
							zephir_array_fetch(&_9$$12, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3813);
							zephir_array_update_zval(&unsetDefaultValues, &attributeField, &_9$$12, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(&_10$$12, connection, "supportsdefaultvalue", &_11, 0);
							zephir_check_call_status();
							if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_10$$12))) {
								continue;
							}
							ZEPHIR_CALL_METHOD(&value, connection, "getdefaultvalue", &_12, 0);
							zephir_check_call_status();
						} else {
							zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
						}
						ZEPHIR_OBS_NVAR(&bindType);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0)))) {
							ZEPHIR_INIT_NVAR(&_13$$15);
							object_init_ex(&_13$$15, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_14$$15);
							zephir_get_class(&_14$$15, this_ptr, 0);
							ZEPHIR_INIT_NVAR(&_15$$15);
							ZEPHIR_CONCAT_SVSVS(&_15$$15, "Column '", &field, "' in '", &_14$$15, "' have not defined a bind data type");
							ZEPHIR_CALL_METHOD(NULL, &_13$$15, "__construct", &_6, 33, &_15$$15);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_13$$15, "phalcon/Mvc/Model.zep", 3830);
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3833);
						zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3834);
						zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3835);
					} else {
						if (zephir_array_isset(&defaultValues, &field)) {
							zephir_array_fetch(&_16$$17, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3838);
							zephir_array_update_zval(&snapshot, &attributeField, &_16$$17, PH_COPY | PH_SEPARATE);
							zephir_array_fetch(&_17$$17, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3839);
							zephir_array_update_zval(&unsetDefaultValues, &attributeField, &_17$$17, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(&_18$$17, connection, "supportsdefaultvalue", &_19, 0);
							zephir_check_call_status();
							if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_18$$17))) {
								continue;
							}
							ZEPHIR_CALL_METHOD(&_20$$17, connection, "getdefaultvalue", &_21, 0);
							zephir_check_call_status();
							zephir_array_append(&values, &_20$$17, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3845);
						} else {
							zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3847);
							zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
						}
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3851);
						zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3852);
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
						ZEPHIR_INIT_NVAR(&_22$$22);
						object_init_ex(&_22$$22, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_23$$22);
						zephir_get_class(&_23$$22, this_ptr, 0);
						ZEPHIR_INIT_NVAR(&_24$$22);
						ZEPHIR_CONCAT_SVSVS(&_24$$22, "Column '", &field, "' in '", &_23$$22, "' isn't part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_22$$22, "__construct", &_6, 33, &_24$$22);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_22$$22, "phalcon/Mvc/Model.zep", 3795);
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
							_25$$26 = Z_TYPE_P(&value) == IS_NULL;
							if (_25$$26) {
								_25$$26 = zephir_array_isset(&defaultValues, &field);
							}
							if (_25$$26) {
								zephir_array_fetch(&_26$$27, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3812);
								zephir_array_update_zval(&snapshot, &attributeField, &_26$$27, PH_COPY | PH_SEPARATE);
								zephir_array_fetch(&_27$$27, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3813);
								zephir_array_update_zval(&unsetDefaultValues, &attributeField, &_27$$27, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(&_28$$27, connection, "supportsdefaultvalue", &_29, 0);
								zephir_check_call_status();
								if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_28$$27))) {
									continue;
								}
								ZEPHIR_CALL_METHOD(&value, connection, "getdefaultvalue", &_30, 0);
								zephir_check_call_status();
							} else {
								zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
							}
							ZEPHIR_OBS_NVAR(&bindType);
							if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0)))) {
								ZEPHIR_INIT_NVAR(&_31$$30);
								object_init_ex(&_31$$30, phalcon_mvc_model_exception_ce);
								ZEPHIR_INIT_NVAR(&_32$$30);
								zephir_get_class(&_32$$30, this_ptr, 0);
								ZEPHIR_INIT_NVAR(&_33$$30);
								ZEPHIR_CONCAT_SVSVS(&_33$$30, "Column '", &field, "' in '", &_32$$30, "' have not defined a bind data type");
								ZEPHIR_CALL_METHOD(NULL, &_31$$30, "__construct", &_6, 33, &_33$$30);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_31$$30, "phalcon/Mvc/Model.zep", 3830);
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3833);
							zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3834);
							zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3835);
						} else {
							if (zephir_array_isset(&defaultValues, &field)) {
								zephir_array_fetch(&_34$$32, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3838);
								zephir_array_update_zval(&snapshot, &attributeField, &_34$$32, PH_COPY | PH_SEPARATE);
								zephir_array_fetch(&_35$$32, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3839);
								zephir_array_update_zval(&unsetDefaultValues, &attributeField, &_35$$32, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(&_36$$32, connection, "supportsdefaultvalue", &_37, 0);
								zephir_check_call_status();
								if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_36$$32))) {
									continue;
								}
								ZEPHIR_CALL_METHOD(&_38$$32, connection, "getdefaultvalue", &_39, 0);
								zephir_check_call_status();
								zephir_array_append(&values, &_38$$32, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3845);
							} else {
								zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3847);
								zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
							}
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3851);
							zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3852);
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
		ZEPHIR_CALL_METHOD(&_40$$35, connection, "useexplicitidvalue", NULL, 0);
		zephir_check_call_status();
		useExplicitIdentity = zephir_get_boolval(&_40$$35);
		if (useExplicitIdentity) {
			zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3871);
		}
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&attributeField);
			if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, identityField, 0)))) {
				ZEPHIR_INIT_VAR(&_41$$38);
				object_init_ex(&_41$$38, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(&_42$$38);
				zephir_get_class(&_42$$38, this_ptr, 0);
				ZEPHIR_INIT_VAR(&_43$$38);
				ZEPHIR_CONCAT_SVSVS(&_43$$38, "Identity column '", identityField, "' isn't part of the column map in '", &_42$$38, "'");
				ZEPHIR_CALL_METHOD(NULL, &_41$$38, "__construct", &_6, 33, &_43$$38);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_41$$38, "phalcon/Mvc/Model.zep", 3881);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(&attributeField, identityField);
		}
		ZEPHIR_OBS_NVAR(&value);
		if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
			_44$$40 = Z_TYPE_P(&value) == IS_NULL;
			if (!(_44$$40)) {
				_44$$40 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
			}
			if (_44$$40) {
				if (useExplicitIdentity) {
					zephir_array_append(&values, &defaultValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3893);
					zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3893);
				}
			} else {
				if (!(useExplicitIdentity)) {
					zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3901);
				}
				ZEPHIR_OBS_NVAR(&bindType);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, identityField, 0)))) {
					ZEPHIR_INIT_VAR(&_45$$45);
					object_init_ex(&_45$$45, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_VAR(&_46$$45);
					zephir_get_class(&_46$$45, this_ptr, 0);
					ZEPHIR_INIT_VAR(&_47$$45);
					ZEPHIR_CONCAT_SVSVS(&_47$$45, "Identity column '", identityField, "' isn\'t part of the table columns in '", &_46$$45, "'");
					ZEPHIR_CALL_METHOD(NULL, &_45$$45, "__construct", &_6, 33, &_47$$45);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_45$$45, "phalcon/Mvc/Model.zep", 3910);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3913);
				zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3914);
			}
		} else {
			if (useExplicitIdentity) {
				zephir_array_append(&values, &defaultValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3918);
				zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3919);
			}
		}
	}
	if (Z_TYPE_P(table) == IS_ARRAY) {
		zephir_array_fetch_long(&_48$$48, table, 0, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3928);
		zephir_array_fetch_long(&_49$$48, table, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3928);
		ZEPHIR_INIT_VAR(&_50$$48);
		ZEPHIR_CONCAT_VSV(&_50$$48, &_48$$48, ".", &_49$$48);
		ZEPHIR_CPY_WRT(table, &_50$$48);
	}
	ZEPHIR_CALL_METHOD(&success, connection, "insert", NULL, 0, table, &values, &fields, &bindTypes);
	zephir_check_call_status();
	_51 = zephir_is_true(&success);
	if (_51) {
		_51 = !ZEPHIR_IS_FALSE_IDENTICAL(identityField);
	}
	if (_51) {
		ZEPHIR_INIT_VAR(&sequenceName);
		ZVAL_NULL(&sequenceName);
		ZEPHIR_CALL_METHOD(&_52$$49, connection, "supportsequences", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_52$$49)) {
			if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("getsequencename")) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(&sequenceName, this_ptr, "getsequencename", NULL, 0);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 424);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 423);
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
			ZVAL_LONG(&_53$$55, 10);
			ZEPHIR_CALL_FUNCTION(&_54$$55, "intval", NULL, 42, &lastInsertedId, &_53$$55);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&lastInsertedId, &_54$$55);
		}
		zephir_update_property_zval_zval(this_ptr, &attributeField, &lastInsertedId);
		zephir_array_update_zval(&snapshot, &attributeField, &lastInsertedId, PH_COPY | PH_SEPARATE);
		zephir_update_property_zval(this_ptr, ZEND_STRL("uniqueParams"), &__$null);
	}
	if (zephir_is_true(&success)) {
		zephir_is_iterable(&unsetDefaultValues, 0, "phalcon/Mvc/Model.zep", 3989);
		if (Z_TYPE_P(&unsetDefaultValues) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&unsetDefaultValues), _57$$56, _58$$56, _55$$56)
			{
				ZEPHIR_INIT_NVAR(&attributeField);
				if (_58$$56 != NULL) { 
					ZVAL_STR_COPY(&attributeField, _58$$56);
				} else {
					ZVAL_LONG(&attributeField, _57$$56);
				}
				ZEPHIR_INIT_NVAR(&defaultValue);
				ZVAL_COPY(&defaultValue, _55$$56);
				zephir_update_property_zval_zval(this_ptr, &attributeField, &defaultValue);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &unsetDefaultValues, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_56$$56, &unsetDefaultValues, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_56$$56)) {
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
		ZEPHIR_CALL_METHOD(&_59$$56, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		_60$$56 = zephir_is_true(&_59$$56);
		if (_60$$56) {
			_60$$56 = ZEPHIR_GLOBAL(orm).update_snapshot_on_save;
		}
		if (_60$$56) {
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
	zval _21$$25, _22$$25, _37$$48, _38$$48;
	zval _67;
	zend_bool changed = 0, useDynamicUpdate = 0, _2, _69, _70, _15$$19, _17$$19, _32$$42, _34$$42;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_19 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *metaData, metaData_sub, *connection, connection_sub, *table = NULL, table_sub, __$null, automaticAttributes, attributeField, bindSkip, bindDataTypes, bindType, bindTypes, columnMap, dataType, dataTypes, field, fields, manager, nonPrimary, newSnapshot, success, primaryKeys, snapshot, snapshotValue, uniqueKey, uniqueParams, value, values, updateValue, _0, _1, _68, *_3$$5, _4$$5, _5$$9, _6$$9, _7$$9, _9$$12, _10$$12, _11$$12, _12$$20, _13$$20, _14$$20, _16$$21, _18$$24, _20$$24, _23$$32, _24$$32, _25$$32, _26$$35, _27$$35, _28$$35, _29$$43, _30$$43, _31$$43, _33$$44, _35$$47, _36$$47, *_39$$53, _40$$53, _41$$57, _42$$57, _43$$57, _44$$60, _45$$60, _46$$60, _47$$66, _48$$66, _49$$66, _50$$69, _51$$69, _52$$69, _53$$74, _54$$74, _55$$74, *_56$$73, _57$$73, _58$$77, _59$$77, _60$$77, _61$$83, _62$$83, _63$$83, _64$$87, _65$$87, _66$$87, _71$$89, _72$$90;
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
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&updateValue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_68);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_9$$12);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_12$$20);
	ZVAL_UNDEF(&_13$$20);
	ZVAL_UNDEF(&_14$$20);
	ZVAL_UNDEF(&_16$$21);
	ZVAL_UNDEF(&_18$$24);
	ZVAL_UNDEF(&_20$$24);
	ZVAL_UNDEF(&_23$$32);
	ZVAL_UNDEF(&_24$$32);
	ZVAL_UNDEF(&_25$$32);
	ZVAL_UNDEF(&_26$$35);
	ZVAL_UNDEF(&_27$$35);
	ZVAL_UNDEF(&_28$$35);
	ZVAL_UNDEF(&_29$$43);
	ZVAL_UNDEF(&_30$$43);
	ZVAL_UNDEF(&_31$$43);
	ZVAL_UNDEF(&_33$$44);
	ZVAL_UNDEF(&_35$$47);
	ZVAL_UNDEF(&_36$$47);
	ZVAL_UNDEF(&_40$$53);
	ZVAL_UNDEF(&_41$$57);
	ZVAL_UNDEF(&_42$$57);
	ZVAL_UNDEF(&_43$$57);
	ZVAL_UNDEF(&_44$$60);
	ZVAL_UNDEF(&_45$$60);
	ZVAL_UNDEF(&_46$$60);
	ZVAL_UNDEF(&_47$$66);
	ZVAL_UNDEF(&_48$$66);
	ZVAL_UNDEF(&_49$$66);
	ZVAL_UNDEF(&_50$$69);
	ZVAL_UNDEF(&_51$$69);
	ZVAL_UNDEF(&_52$$69);
	ZVAL_UNDEF(&_53$$74);
	ZVAL_UNDEF(&_54$$74);
	ZVAL_UNDEF(&_55$$74);
	ZVAL_UNDEF(&_57$$73);
	ZVAL_UNDEF(&_58$$77);
	ZVAL_UNDEF(&_59$$77);
	ZVAL_UNDEF(&_60$$77);
	ZVAL_UNDEF(&_61$$83);
	ZVAL_UNDEF(&_62$$83);
	ZVAL_UNDEF(&_63$$83);
	ZVAL_UNDEF(&_64$$87);
	ZVAL_UNDEF(&_65$$87);
	ZVAL_UNDEF(&_66$$87);
	ZVAL_UNDEF(&_71$$89);
	ZVAL_UNDEF(&_72$$90);
	ZVAL_UNDEF(&_67);
	ZVAL_UNDEF(&_21$$25);
	ZVAL_UNDEF(&_22$$25);
	ZVAL_UNDEF(&_37$$48);
	ZVAL_UNDEF(&_38$$48);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(metaData, phalcon_mvc_model_metadatainterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(connection, phalcon_db_adapter_adapterinterface_ce)
		Z_PARAM_ZVAL(table)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	_2 = useDynamicUpdate;
	if (_2) {
		_2 = Z_TYPE_P(&snapshot) == IS_ARRAY;
	}
	if (EXPECTED(_2)) {
		zephir_is_iterable(&nonPrimary, 0, "phalcon/Mvc/Model.zep", 4149);
		if (Z_TYPE_P(&nonPrimary) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&nonPrimary), _3$$5)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _3$$5);
				changed = 0;
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
						if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
							ZEPHIR_INIT_NVAR(&_5$$9);
							object_init_ex(&_5$$9, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_6$$9);
							zephir_get_class(&_6$$9, this_ptr, 0);
							ZEPHIR_INIT_NVAR(&_7$$9);
							ZEPHIR_CONCAT_SVSVS(&_7$$9, "Column '", &field, "' in '", &_6$$9, "' isn't part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_5$$9, "__construct", &_8, 33, &_7$$9);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_5$$9, "phalcon/Mvc/Model.zep", 4043);
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
						ZEPHIR_INIT_NVAR(&_9$$12);
						object_init_ex(&_9$$12, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_10$$12);
						zephir_get_class(&_10$$12, this_ptr, 0);
						ZEPHIR_INIT_NVAR(&_11$$12);
						ZEPHIR_CONCAT_SVSVS(&_11$$12, "Column '", &field, "' in '", &_10$$12, "' have not defined a bind data type");
						ZEPHIR_CALL_METHOD(NULL, &_9$$12, "__construct", &_8, 33, &_11$$12);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_9$$12, "phalcon/Mvc/Model.zep", 4056);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&value);
					if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
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
										ZEPHIR_INIT_NVAR(&_12$$20);
										object_init_ex(&_12$$20, phalcon_mvc_model_exception_ce);
										ZEPHIR_INIT_NVAR(&_13$$20);
										zephir_get_class(&_13$$20, this_ptr, 0);
										ZEPHIR_INIT_NVAR(&_14$$20);
										ZEPHIR_CONCAT_SVSVS(&_14$$20, "Column '", &field, "' in '", &_13$$20, "' have not defined a data type");
										ZEPHIR_CALL_METHOD(NULL, &_12$$20, "__construct", &_8, 33, &_14$$20);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_12$$20, "phalcon/Mvc/Model.zep", 4086);
										ZEPHIR_MM_RESTORE();
										return;
									}
									_15$$19 = Z_TYPE_P(&snapshotValue) == IS_OBJECT;
									if (_15$$19) {
										_15$$19 = zephir_instance_of_ev(&snapshotValue, phalcon_db_rawvalue_ce);
									}
									if (_15$$19) {
										ZEPHIR_CALL_METHOD(&_16$$21, &snapshotValue, "getvalue", NULL, 0);
										zephir_check_call_status();
										ZEPHIR_CPY_WRT(&snapshotValue, &_16$$21);
									}
									ZEPHIR_CPY_WRT(&updateValue, &value);
									_17$$19 = Z_TYPE_P(&value) == IS_OBJECT;
									if (_17$$19) {
										_17$$19 = zephir_instance_of_ev(&value, phalcon_db_rawvalue_ce);
									}
									if (_17$$19) {
										ZEPHIR_CALL_METHOD(&updateValue, &value, "getvalue", NULL, 0);
										zephir_check_call_status();
									}
									do {
										if (ZEPHIR_IS_LONG(&dataType, 8)) {
											changed = zephir_get_boolval(&snapshotValue) != zephir_get_boolval(&updateValue);
											break;
										}
										if (ZEPHIR_IS_LONG(&dataType, 3) || ZEPHIR_IS_LONG(&dataType, 7)) {
											ZEPHIR_CALL_FUNCTION(&_18$$24, "floatval", &_19, 18, &snapshotValue);
											zephir_check_call_status();
											ZEPHIR_CALL_FUNCTION(&_20$$24, "floatval", &_19, 18, &updateValue);
											zephir_check_call_status();
											changed = !ZEPHIR_IS_IDENTICAL(&_18$$24, &_20$$24);
											break;
										}
										if (ZEPHIR_IS_LONG(&dataType, 0) || ZEPHIR_IS_LONG(&dataType, 1) || ZEPHIR_IS_LONG(&dataType, 2) || ZEPHIR_IS_LONG(&dataType, 4) || ZEPHIR_IS_LONG(&dataType, 5) || ZEPHIR_IS_LONG(&dataType, 6) || ZEPHIR_IS_LONG(&dataType, 2) || ZEPHIR_IS_LONG(&dataType, 14)) {
											zephir_cast_to_string(&_21$$25, &snapshotValue);
											zephir_cast_to_string(&_22$$25, &updateValue);
											changed = !ZEPHIR_IS_IDENTICAL(&_21$$25, &_22$$25);
											break;
										}
										changed = !ZEPHIR_IS_EQUAL(&updateValue, &snapshotValue);
									} while(0);

								}
							}
						}
						if (changed) {
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4136);
							zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4137);
							zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4138);
						}
						zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &nonPrimary, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_4$$5, &nonPrimary, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, &nonPrimary, "current", NULL, 0);
				zephir_check_call_status();
					changed = 0;
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
							if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
								ZEPHIR_INIT_NVAR(&_23$$32);
								object_init_ex(&_23$$32, phalcon_mvc_model_exception_ce);
								ZEPHIR_INIT_NVAR(&_24$$32);
								zephir_get_class(&_24$$32, this_ptr, 0);
								ZEPHIR_INIT_NVAR(&_25$$32);
								ZEPHIR_CONCAT_SVSVS(&_25$$32, "Column '", &field, "' in '", &_24$$32, "' isn't part of the column map");
								ZEPHIR_CALL_METHOD(NULL, &_23$$32, "__construct", &_8, 33, &_25$$32);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_23$$32, "phalcon/Mvc/Model.zep", 4043);
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
							ZEPHIR_INIT_NVAR(&_26$$35);
							object_init_ex(&_26$$35, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_27$$35);
							zephir_get_class(&_27$$35, this_ptr, 0);
							ZEPHIR_INIT_NVAR(&_28$$35);
							ZEPHIR_CONCAT_SVSVS(&_28$$35, "Column '", &field, "' in '", &_27$$35, "' have not defined a bind data type");
							ZEPHIR_CALL_METHOD(NULL, &_26$$35, "__construct", &_8, 33, &_28$$35);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_26$$35, "phalcon/Mvc/Model.zep", 4056);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_OBS_NVAR(&value);
						if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
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
											ZEPHIR_INIT_NVAR(&_29$$43);
											object_init_ex(&_29$$43, phalcon_mvc_model_exception_ce);
											ZEPHIR_INIT_NVAR(&_30$$43);
											zephir_get_class(&_30$$43, this_ptr, 0);
											ZEPHIR_INIT_NVAR(&_31$$43);
											ZEPHIR_CONCAT_SVSVS(&_31$$43, "Column '", &field, "' in '", &_30$$43, "' have not defined a data type");
											ZEPHIR_CALL_METHOD(NULL, &_29$$43, "__construct", &_8, 33, &_31$$43);
											zephir_check_call_status();
											zephir_throw_exception_debug(&_29$$43, "phalcon/Mvc/Model.zep", 4086);
											ZEPHIR_MM_RESTORE();
											return;
										}
										_32$$42 = Z_TYPE_P(&snapshotValue) == IS_OBJECT;
										if (_32$$42) {
											_32$$42 = zephir_instance_of_ev(&snapshotValue, phalcon_db_rawvalue_ce);
										}
										if (_32$$42) {
											ZEPHIR_CALL_METHOD(&_33$$44, &snapshotValue, "getvalue", NULL, 0);
											zephir_check_call_status();
											ZEPHIR_CPY_WRT(&snapshotValue, &_33$$44);
										}
										ZEPHIR_CPY_WRT(&updateValue, &value);
										_34$$42 = Z_TYPE_P(&value) == IS_OBJECT;
										if (_34$$42) {
											_34$$42 = zephir_instance_of_ev(&value, phalcon_db_rawvalue_ce);
										}
										if (_34$$42) {
											ZEPHIR_CALL_METHOD(&updateValue, &value, "getvalue", NULL, 0);
											zephir_check_call_status();
										}
										do {
											if (ZEPHIR_IS_LONG(&dataType, 8)) {
												changed = zephir_get_boolval(&snapshotValue) != zephir_get_boolval(&updateValue);
												break;
											}
											if (ZEPHIR_IS_LONG(&dataType, 3) || ZEPHIR_IS_LONG(&dataType, 7)) {
												ZEPHIR_CALL_FUNCTION(&_35$$47, "floatval", &_19, 18, &snapshotValue);
												zephir_check_call_status();
												ZEPHIR_CALL_FUNCTION(&_36$$47, "floatval", &_19, 18, &updateValue);
												zephir_check_call_status();
												changed = !ZEPHIR_IS_IDENTICAL(&_35$$47, &_36$$47);
												break;
											}
											if (ZEPHIR_IS_LONG(&dataType, 0) || ZEPHIR_IS_LONG(&dataType, 1) || ZEPHIR_IS_LONG(&dataType, 2) || ZEPHIR_IS_LONG(&dataType, 4) || ZEPHIR_IS_LONG(&dataType, 5) || ZEPHIR_IS_LONG(&dataType, 6) || ZEPHIR_IS_LONG(&dataType, 2) || ZEPHIR_IS_LONG(&dataType, 14)) {
												zephir_cast_to_string(&_37$$48, &snapshotValue);
												zephir_cast_to_string(&_38$$48, &updateValue);
												changed = !ZEPHIR_IS_IDENTICAL(&_37$$48, &_38$$48);
												break;
											}
											changed = !ZEPHIR_IS_EQUAL(&updateValue, &snapshotValue);
										} while(0);

									}
								}
							}
							if (changed) {
								zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4136);
								zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4137);
								zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4138);
							}
							zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
						} else {
							zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
						}
					}
				ZEPHIR_CALL_METHOD(NULL, &nonPrimary, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&field);
		if (!(zephir_fast_count_int(&fields))) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("oldSnapshot"), &snapshot);
			RETURN_MM_BOOL(1);
		}
	} else {
		zephir_is_iterable(&nonPrimary, 0, "phalcon/Mvc/Model.zep", 4204);
		if (Z_TYPE_P(&nonPrimary) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&nonPrimary), _39$$53)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _39$$53);
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
						if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
							ZEPHIR_INIT_NVAR(&_41$$57);
							object_init_ex(&_41$$57, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_42$$57);
							zephir_get_class(&_42$$57, this_ptr, 0);
							ZEPHIR_INIT_NVAR(&_43$$57);
							ZEPHIR_CONCAT_SVSVS(&_43$$57, "Column '", &field, "' in '", &_42$$57, "' isn't part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_41$$57, "__construct", &_8, 33, &_43$$57);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_41$$57, "phalcon/Mvc/Model.zep", 4167);
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
						ZEPHIR_INIT_NVAR(&_44$$60);
						object_init_ex(&_44$$60, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_45$$60);
						zephir_get_class(&_45$$60, this_ptr, 0);
						ZEPHIR_INIT_NVAR(&_46$$60);
						ZEPHIR_CONCAT_SVSVS(&_46$$60, "Column '", &field, "' in '", &_45$$60, "' have not defined a bind data type");
						ZEPHIR_CALL_METHOD(NULL, &_44$$60, "__construct", &_8, 33, &_46$$60);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_44$$60, "phalcon/Mvc/Model.zep", 4181);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&value);
					if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4192);
						zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4193);
						zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4194);
						zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4198);
						zephir_array_append(&values, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4199);
						zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4200);
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &nonPrimary, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_40$$53, &nonPrimary, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_40$$53)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, &nonPrimary, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
							if (UNEXPECTED(!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns))) {
								ZEPHIR_INIT_NVAR(&_47$$66);
								object_init_ex(&_47$$66, phalcon_mvc_model_exception_ce);
								ZEPHIR_INIT_NVAR(&_48$$66);
								zephir_get_class(&_48$$66, this_ptr, 0);
								ZEPHIR_INIT_NVAR(&_49$$66);
								ZEPHIR_CONCAT_SVSVS(&_49$$66, "Column '", &field, "' in '", &_48$$66, "' isn't part of the column map");
								ZEPHIR_CALL_METHOD(NULL, &_47$$66, "__construct", &_8, 33, &_49$$66);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_47$$66, "phalcon/Mvc/Model.zep", 4167);
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
							ZEPHIR_INIT_NVAR(&_50$$69);
							object_init_ex(&_50$$69, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_51$$69);
							zephir_get_class(&_51$$69, this_ptr, 0);
							ZEPHIR_INIT_NVAR(&_52$$69);
							ZEPHIR_CONCAT_SVSVS(&_52$$69, "Column '", &field, "' in '", &_51$$69, "' have not defined a bind data type");
							ZEPHIR_CALL_METHOD(NULL, &_50$$69, "__construct", &_8, 33, &_52$$69);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_50$$69, "phalcon/Mvc/Model.zep", 4181);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_OBS_NVAR(&value);
						if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4192);
							zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4193);
							zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4194);
							zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
						} else {
							zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4198);
							zephir_array_append(&values, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4199);
							zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4200);
						}
					}
				ZEPHIR_CALL_METHOD(NULL, &nonPrimary, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&field);
	}
	if (!(zephir_fast_count_int(&fields))) {
		RETURN_MM_BOOL(1);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("uniqueKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueKey, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("uniqueParams"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueParams, &_0);
	if (Z_TYPE_P(&uniqueParams) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&primaryKeys, metaData, "getprimarykeyattributes", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (UNEXPECTED(!(zephir_fast_count_int(&primaryKeys)))) {
			ZEPHIR_INIT_VAR(&_53$$74);
			object_init_ex(&_53$$74, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_VAR(&_54$$74);
			zephir_get_class(&_54$$74, this_ptr, 0);
			ZEPHIR_INIT_VAR(&_55$$74);
			ZEPHIR_CONCAT_SVS(&_55$$74, "A primary key must be defined in the model in order to perform the operation in '", &_54$$74, "'");
			ZEPHIR_CALL_METHOD(NULL, &_53$$74, "__construct", &_8, 33, &_55$$74);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_53$$74, "phalcon/Mvc/Model.zep", 4227);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&uniqueParams);
		array_init(&uniqueParams);
		zephir_is_iterable(&primaryKeys, 0, "phalcon/Mvc/Model.zep", 4254);
		if (Z_TYPE_P(&primaryKeys) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&primaryKeys), _56$$73)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _56$$73);
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
						ZEPHIR_INIT_NVAR(&_58$$77);
						object_init_ex(&_58$$77, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_59$$77);
						zephir_get_class(&_59$$77, this_ptr, 0);
						ZEPHIR_INIT_NVAR(&_60$$77);
						ZEPHIR_CONCAT_SVSVS(&_60$$77, "Column '", &field, "' in '", &_59$$77, "' isn't part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_58$$77, "__construct", &_8, 33, &_60$$77);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_58$$77, "phalcon/Mvc/Model.zep", 4240);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &field);
				}
				ZEPHIR_OBS_NVAR(&value);
				if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
					zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
					zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4248);
				} else {
					zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
					zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4251);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &primaryKeys, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_57$$73, &primaryKeys, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_57$$73)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, &primaryKeys, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
							ZEPHIR_INIT_NVAR(&_61$$83);
							object_init_ex(&_61$$83, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_62$$83);
							zephir_get_class(&_62$$83, this_ptr, 0);
							ZEPHIR_INIT_NVAR(&_63$$83);
							ZEPHIR_CONCAT_SVSVS(&_63$$83, "Column '", &field, "' in '", &_62$$83, "' isn't part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_61$$83, "__construct", &_8, 33, &_63$$83);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_61$$83, "phalcon/Mvc/Model.zep", 4240);
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_CPY_WRT(&attributeField, &field);
					}
					ZEPHIR_OBS_NVAR(&value);
					if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
						zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
						zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4248);
					} else {
						zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
						zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4251);
					}
				ZEPHIR_CALL_METHOD(NULL, &primaryKeys, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&field);
	}
	if (Z_TYPE_P(table) == IS_ARRAY) {
		zephir_array_fetch_long(&_64$$87, table, 0, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4260);
		zephir_array_fetch_long(&_65$$87, table, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4260);
		ZEPHIR_INIT_VAR(&_66$$87);
		ZEPHIR_CONCAT_VSV(&_66$$87, &_64$$87, ".", &_65$$87);
		ZEPHIR_CPY_WRT(table, &_66$$87);
	}
	ZEPHIR_INIT_VAR(&_67);
	zephir_create_array(&_67, 3, 0);
	zephir_array_update_string(&_67, SL("conditions"), &uniqueKey, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_67, SL("bind"), &uniqueParams, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&_68);
	zephir_read_property(&_68, this_ptr, ZEND_STRL("uniqueTypes"), PH_NOISY_CC);
	zephir_array_update_string(&_67, SL("bindTypes"), &_68, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&success, connection, "update", NULL, 0, table, &fields, &values, &_67, &bindTypes);
	zephir_check_call_status();
	_69 = zephir_is_true(&success);
	if (_69) {
		ZEPHIR_CALL_METHOD(&_1, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		_69 = zephir_is_true(&_1);
	}
	_70 = _69;
	if (_70) {
		_70 = ZEPHIR_GLOBAL(orm).update_snapshot_on_save;
	}
	if (_70) {
		if (Z_TYPE_P(&snapshot) == IS_ARRAY) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("oldSnapshot"), &snapshot);
			ZEPHIR_INIT_VAR(&_71$$89);
			zephir_fast_array_merge(&_71$$89, &snapshot, &newSnapshot);
			zephir_update_property_zval(this_ptr, ZEND_STRL("snapshot"), &_71$$89);
		} else {
			ZEPHIR_INIT_VAR(&_72$$90);
			array_init(&_72$$90);
			zephir_update_property_zval(this_ptr, ZEND_STRL("oldSnapshot"), &_72$$90);
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
	zend_bool _7$$11, _17$$19;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_12 = NULL, *_22 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberEmpty = 0, numberPrimary = 0;
	zval *metaData, metaData_sub, *connection, connection_sub, __$null, attributeField, bindDataTypes, columnMap, field, joinWhere, num, primaryKeys, schema, source, table, type, uniqueKey, uniqueParams, uniqueTypes, value, wherePk, _0, _27, _28, _29, _30, *_1$$3, _2$$3, _3$$9, _4$$9, _5$$9, _8$$14, _9$$14, _10$$14, _11$$7, _13$$7, _14$$17, _15$$17, _16$$17, _18$$22, _19$$22, _20$$22, _21$$15, _23$$15, _24$$25, _25$$26, _26$$27, _31$$30, _32$$31;
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
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_8$$14);
	ZVAL_UNDEF(&_9$$14);
	ZVAL_UNDEF(&_10$$14);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$17);
	ZVAL_UNDEF(&_15$$17);
	ZVAL_UNDEF(&_16$$17);
	ZVAL_UNDEF(&_18$$22);
	ZVAL_UNDEF(&_19$$22);
	ZVAL_UNDEF(&_20$$22);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_24$$25);
	ZVAL_UNDEF(&_25$$26);
	ZVAL_UNDEF(&_26$$27);
	ZVAL_UNDEF(&_31$$30);
	ZVAL_UNDEF(&_32$$31);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(metaData, phalcon_mvc_model_metadatainterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(connection, phalcon_db_adapter_adapterinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
		zephir_is_iterable(&primaryKeys, 0, "phalcon/Mvc/Model.zep", 4384);
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
						zephir_get_class(&_4$$9, this_ptr, 0);
						ZEPHIR_INIT_NVAR(&_5$$9);
						ZEPHIR_CONCAT_SVSVS(&_5$$9, "Column '", &field, "' in '", &_4$$9, "' isn't part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_3$$9, "__construct", &_6, 33, &_5$$9);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_3$$9, "phalcon/Mvc/Model.zep", 4343);
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
					_7$$11 = Z_TYPE_P(&value) == IS_NULL;
					if (!(_7$$11)) {
						_7$$11 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
					}
					if (_7$$11) {
						numberEmpty++;
					}
					zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4364);
				} else {
					zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4366);
					numberEmpty++;
				}
				ZEPHIR_OBS_NVAR(&type);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&type, &bindDataTypes, &field, 0)))) {
					ZEPHIR_INIT_NVAR(&_8$$14);
					object_init_ex(&_8$$14, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_NVAR(&_9$$14);
					zephir_get_class(&_9$$14, this_ptr, 0);
					ZEPHIR_INIT_NVAR(&_10$$14);
					ZEPHIR_CONCAT_SVSVS(&_10$$14, "Column '", &field, "' in '", &_9$$14, "' isn't part of the table columns");
					ZEPHIR_CALL_METHOD(NULL, &_8$$14, "__construct", &_6, 33, &_10$$14);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_8$$14, "phalcon/Mvc/Model.zep", 4373);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&uniqueTypes, &type, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4376);
				ZEPHIR_CALL_METHOD(&_11$$7, connection, "escapeidentifier", &_12, 0, &field);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$7);
				ZEPHIR_CONCAT_VS(&_13$$7, &_11$$7, " = ?");
				zephir_array_append(&wherePk, &_13$$7, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4377);
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
							ZEPHIR_INIT_NVAR(&_14$$17);
							object_init_ex(&_14$$17, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_15$$17);
							zephir_get_class(&_15$$17, this_ptr, 0);
							ZEPHIR_INIT_NVAR(&_16$$17);
							ZEPHIR_CONCAT_SVSVS(&_16$$17, "Column '", &field, "' in '", &_15$$17, "' isn't part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_14$$17, "__construct", &_6, 33, &_16$$17);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_14$$17, "phalcon/Mvc/Model.zep", 4343);
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
						_17$$19 = Z_TYPE_P(&value) == IS_NULL;
						if (!(_17$$19)) {
							_17$$19 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
						}
						if (_17$$19) {
							numberEmpty++;
						}
						zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4364);
					} else {
						zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4366);
						numberEmpty++;
					}
					ZEPHIR_OBS_NVAR(&type);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&type, &bindDataTypes, &field, 0)))) {
						ZEPHIR_INIT_NVAR(&_18$$22);
						object_init_ex(&_18$$22, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_19$$22);
						zephir_get_class(&_19$$22, this_ptr, 0);
						ZEPHIR_INIT_NVAR(&_20$$22);
						ZEPHIR_CONCAT_SVSVS(&_20$$22, "Column '", &field, "' in '", &_19$$22, "' isn't part of the table columns");
						ZEPHIR_CALL_METHOD(NULL, &_18$$22, "__construct", &_6, 33, &_20$$22);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_18$$22, "phalcon/Mvc/Model.zep", 4373);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&uniqueTypes, &type, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4376);
					ZEPHIR_CALL_METHOD(&_21$$15, connection, "escapeidentifier", &_22, 0, &field);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_23$$15);
					ZEPHIR_CONCAT_VS(&_23$$15, &_21$$15, " = ?");
					zephir_array_append(&wherePk, &_23$$15, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4377);
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
		zephir_read_property(&_24$$25, this_ptr, ZEND_STRL("uniqueKey"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&uniqueKey, &_24$$25);
	}
	if (Z_TYPE_P(&uniqueParams) == IS_NULL) {
		zephir_read_property(&_25$$26, this_ptr, ZEND_STRL("uniqueParams"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&uniqueParams, &_25$$26);
	}
	if (Z_TYPE_P(&uniqueTypes) == IS_NULL) {
		zephir_read_property(&_26$$27, this_ptr, ZEND_STRL("uniqueTypes"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&uniqueTypes, &_26$$27);
	}
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 423);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 424);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	ZEPHIR_CALL_METHOD(&_27, connection, "escapeidentifier", NULL, 0, &table);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_28);
	ZEPHIR_CONCAT_SVSV(&_28, "SELECT COUNT(*) \"rowcount\" FROM ", &_27, " WHERE ", &uniqueKey);
	ZVAL_NULL(&_29);
	ZEPHIR_CALL_METHOD(&num, connection, "fetchone", NULL, 0, &_28, &_29, &uniqueParams, &uniqueTypes);
	zephir_check_call_status();
	zephir_array_fetch_string(&_30, &num, SL("rowcount"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4438);
	if (zephir_is_true(&_30)) {
		ZVAL_UNDEF(&_31$$30);
		ZVAL_LONG(&_31$$30, 0);
		zephir_update_property_zval(this_ptr, ZEND_STRL("dirtyState"), &_31$$30);
		RETURN_MM_BOOL(1);
	} else {
		ZVAL_UNDEF(&_32$$31);
		ZVAL_LONG(&_32$$31, 1);
		zephir_update_property_zval(this_ptr, ZEND_STRL("dirtyState"), &_32$$31);
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
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(modelName)
		Z_PARAM_STR(method)
		Z_PARAM_ARRAY(arguments)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_memory_observe(&extraArgs);
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
	zval *functionName_param = NULL, *alias_param = NULL, *parameters = NULL, parameters_sub, __$null, params, distinctColumn, groupColumn, columns, resultset, cache, firstRow, groupColumns, builder, query, container, manager, transaction, bindParams, bindTypes, _0, _1, _2;
	zval functionName, alias;

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
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(functionName)
		Z_PARAM_STR(alias)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_di_ce, "getdefault", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "modelsManager");
	ZEPHIR_CALL_METHOD(&_0, &container, "getshared", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_0);
	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
		if (Z_TYPE_P(parameters) != IS_NULL) {
			zephir_array_append(&params, parameters, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4543);
		}
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	zephir_memory_observe(&groupColumn);
	if (!(zephir_array_isset_string_fetch(&groupColumn, &params, SL("column"), 0))) {
		ZEPHIR_INIT_NVAR(&groupColumn);
		ZVAL_STRING(&groupColumn, "*");
	}
	zephir_memory_observe(&distinctColumn);
	if (zephir_array_isset_string_fetch(&distinctColumn, &params, SL("distinct"), 0)) {
		ZEPHIR_INIT_VAR(&columns);
		ZEPHIR_CONCAT_VSVSV(&columns, &functionName, "(DISTINCT ", &distinctColumn, ") AS ", &alias);
	} else {
		zephir_memory_observe(&groupColumns);
		ZEPHIR_INIT_NVAR(&columns);
		if (zephir_array_isset_string_fetch(&groupColumns, &params, SL("group"), 0)) {
			ZEPHIR_CONCAT_VSVSVSV(&columns, &groupColumns, ", ", &functionName, "(", &groupColumn, ") AS ", &alias);
		} else {
			ZEPHIR_CONCAT_VSVSV(&columns, &functionName, "(", &groupColumn, ") AS ", &alias);
		}
	}
	ZEPHIR_CALL_METHOD(&_0, &manager, "createbuilder", NULL, 0, &params);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&builder, &_0);
	ZEPHIR_CALL_METHOD(NULL, &builder, "columns", NULL, 0, &columns);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	zephir_get_called_class(&_1);
	ZEPHIR_CALL_METHOD(NULL, &builder, "from", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &builder, "getquery", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&query, &_0);
	zephir_memory_observe(&transaction);
	if (zephir_array_isset_string_fetch(&transaction, &params, SL("transaction"), 0)) {
		if (zephir_instance_of_ev(&transaction, phalcon_mvc_model_transactioninterface_ce)) {
			ZEPHIR_CALL_METHOD(NULL, &query, "settransaction", NULL, 0, &transaction);
			zephir_check_call_status();
		}
	}
	if (zephir_array_isset_string(&params, SL("bind"))) {
		ZEPHIR_OBS_NVAR(&bindParams);
		zephir_array_fetch_string(&bindParams, &params, SL("bind"), PH_NOISY, "phalcon/Mvc/Model.zep", 4586);
		if (zephir_array_isset_string(&params, SL("bindTypes"))) {
			ZEPHIR_OBS_NVAR(&bindTypes);
			zephir_array_fetch_string(&bindTypes, &params, SL("bindTypes"), PH_NOISY, "phalcon/Mvc/Model.zep", 4589);
		}
	}
	zephir_memory_observe(&cache);
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
	zephir_memory_observe(&_2);
	zephir_read_property_zval(&_2, &firstRow, &alias, PH_NOISY_CC);
	RETURN_CCTOR(&_2);
}

/**
 * Try to check if the query must invoke a finder
 *
 * @return ModelInterface[]|ModelInterface|bool
 */
PHP_METHOD(Phalcon_Mvc_Model, invokeFinder)
{
	zend_class_entry *_15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments, _11$$14;
	zval *method_param = NULL, *arguments_param = NULL, extraMethod, type, modelName, value, model, attributes, field, extraMethodFirst, metaData, params, _14, _0$$3, _1$$4, _2$$5, _3$$7, _4$$7, _5$$7, _6$$13, _7$$13, _8$$13, _9$$14, _10$$14, _12$$15, _13$$15;
	zval method;

	ZVAL_UNDEF(&method);
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
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$13);
	ZVAL_UNDEF(&_7$$13);
	ZVAL_UNDEF(&_8$$13);
	ZVAL_UNDEF(&_9$$14);
	ZVAL_UNDEF(&_10$$14);
	ZVAL_UNDEF(&_12$$15);
	ZVAL_UNDEF(&_13$$15);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&_11$$14);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(method)
		Z_PARAM_ARRAY(arguments)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
		zephir_get_called_class(&_4$$7);
		ZEPHIR_INIT_VAR(&_5$$7);
		ZEPHIR_CONCAT_SVSVS(&_5$$7, "The static method '", &method, "' in '", &_4$$7, "' requires one argument");
		ZEPHIR_CALL_METHOD(NULL, &_3$$7, "__construct", NULL, 33, &_5$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$7, "phalcon/Mvc/Model.zep", 4668);
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
		ZEPHIR_CALL_FUNCTION(&extraMethodFirst, "lcfirst", NULL, 77, &extraMethod);
		zephir_check_call_status();
		if (zephir_array_isset(&attributes, &extraMethodFirst)) {
			ZEPHIR_CPY_WRT(&field, &extraMethodFirst);
		} else {
			ZEPHIR_INIT_NVAR(&field);
			zephir_uncamelize(&field, &extraMethod, NULL );
			if (UNEXPECTED(!(zephir_array_isset(&attributes, &field)))) {
				ZEPHIR_INIT_VAR(&_6$$13);
				object_init_ex(&_6$$13, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(&_7$$13);
				zephir_get_called_class(&_7$$13);
				ZEPHIR_INIT_VAR(&_8$$13);
				ZEPHIR_CONCAT_SVSVS(&_8$$13, "Cannot resolve attribute '", &extraMethod, "' in the model '", &_7$$13, "'");
				ZEPHIR_CALL_METHOD(NULL, &_6$$13, "__construct", NULL, 33, &_8$$13);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_6$$13, "phalcon/Mvc/Model.zep", 4705);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	zephir_memory_observe(&value);
	zephir_array_isset_long_fetch(&value, &arguments, 0, 0);
	ZEPHIR_INIT_VAR(&params);
	if (Z_TYPE_P(&value) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_9$$14);
		zephir_create_array(&_9$$14, 2, 0);
		ZEPHIR_INIT_VAR(&_10$$14);
		ZEPHIR_CONCAT_SVS(&_10$$14, "[", &field, "] = ?0");
		zephir_array_update_string(&_9$$14, SL("conditions"), &_10$$14, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_11$$14);
		zephir_create_array(&_11$$14, 1, 0);
		zephir_array_fast_append(&_11$$14, &value);
		zephir_array_update_string(&_9$$14, SL("bind"), &_11$$14, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&params, &_9$$14);
	} else {
		ZEPHIR_INIT_VAR(&_12$$15);
		zephir_create_array(&_12$$15, 1, 0);
		ZEPHIR_INIT_VAR(&_13$$15);
		ZEPHIR_CONCAT_SVS(&_13$$15, "[", &field, "] IS NULL");
		zephir_array_update_string(&_12$$15, SL("conditions"), &_13$$15, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&params, &_12$$15);
	}
	zephir_array_unset_long(&arguments, 0, PH_SEPARATE);
	zephir_array_unset_string(&arguments, SL("conditions"), PH_SEPARATE);
	zephir_array_unset_string(&arguments, SL("bind"), PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_14);
	zephir_fast_array_merge(&_14, &params, &arguments);
	ZEPHIR_CPY_WRT(&params, &_14);
	_15 = zephir_fetch_class(&modelName);
	ZEPHIR_RETURN_CALL_CE_STATIC_ZVAL(_15, type, NULL, 0, &params);
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
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(property)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_camelize(&_0, &property, NULL );
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
	zval _16$$32, _29$$52;
	zval eventName;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_19 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool exists, error = 0, isNull = 0, _10$$27, _11$$27, _12$$27, _23$$47, _24$$47, _25$$47;
	zval *metaData, metaData_sub, *exists_param = NULL, *identityField, identityField_sub, __$true, __$false, notNull, columnMap, dataTypeNumeric, automaticAttributes, defaultValues, field, attributeField, value, emptyStringValues, _33, _34, _0$$3, _1$$3, _2$$3, _3$$8, *_4$$11, _5$$11, _6$$19, _7$$19, _8$$19, _13$$27, _14$$32, _15$$32, _17$$32, _18$$32, _20$$39, _21$$39, _22$$39, _26$$47, _27$$52, _28$$52, _30$$52, _31$$52, _32$$57, _35$$59, _36$$60, _37$$60, _38$$60, _39$$60, _40$$60, _41$$60;
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
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_5$$11);
	ZVAL_UNDEF(&_6$$19);
	ZVAL_UNDEF(&_7$$19);
	ZVAL_UNDEF(&_8$$19);
	ZVAL_UNDEF(&_13$$27);
	ZVAL_UNDEF(&_14$$32);
	ZVAL_UNDEF(&_15$$32);
	ZVAL_UNDEF(&_17$$32);
	ZVAL_UNDEF(&_18$$32);
	ZVAL_UNDEF(&_20$$39);
	ZVAL_UNDEF(&_21$$39);
	ZVAL_UNDEF(&_22$$39);
	ZVAL_UNDEF(&_26$$47);
	ZVAL_UNDEF(&_27$$52);
	ZVAL_UNDEF(&_28$$52);
	ZVAL_UNDEF(&_30$$52);
	ZVAL_UNDEF(&_31$$52);
	ZVAL_UNDEF(&_32$$57);
	ZVAL_UNDEF(&_35$$59);
	ZVAL_UNDEF(&_36$$60);
	ZVAL_UNDEF(&_37$$60);
	ZVAL_UNDEF(&_38$$60);
	ZVAL_UNDEF(&_39$$60);
	ZVAL_UNDEF(&_40$$60);
	ZVAL_UNDEF(&_41$$60);
	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&_16$$32);
	ZVAL_UNDEF(&_29$$52);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(metaData, phalcon_mvc_model_metadatainterface_ce)
		Z_PARAM_BOOL(exists)
		Z_PARAM_ZVAL(identityField)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &metaData, &exists_param, &identityField);
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
		ZEPHIR_CALL_METHOD(&_3$$8, this_ptr, "checkforeignkeysrestrict", NULL, 434);
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
			zephir_is_iterable(&notNull, 0, "phalcon/Mvc/Model.zep", 4946);
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
								zephir_get_class(&_7$$19, this_ptr, 0);
								ZEPHIR_INIT_NVAR(&_8$$19);
								ZEPHIR_CONCAT_SVSVS(&_8$$19, "Column '", &field, "' in '", &_7$$19, "' isn't part of the column map");
								ZEPHIR_CALL_METHOD(NULL, &_6$$19, "__construct", &_9, 33, &_8$$19);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_6$$19, "phalcon/Mvc/Model.zep", 4866);
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
										_10$$27 = Z_TYPE_P(&value) == IS_NULL;
										if (!(_10$$27)) {
											_11$$27 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
											if (_11$$27) {
												_12$$27 = !(zephir_array_isset(&defaultValues, &field));
												if (!(_12$$27)) {
													zephir_array_fetch(&_13$$27, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4896);
													_12$$27 = !ZEPHIR_IS_IDENTICAL(&value, &_13$$27);
												}
												_11$$27 = _12$$27;
											}
											_10$$27 = _11$$27;
										}
										if (_10$$27) {
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
							ZEPHIR_INIT_NVAR(&_14$$32);
							object_init_ex(&_14$$32, phalcon_messages_message_ce);
							ZEPHIR_INIT_NVAR(&_15$$32);
							ZEPHIR_CONCAT_VS(&_15$$32, &attributeField, " is required");
							ZEPHIR_INIT_NVAR(&_16$$32);
							zephir_create_array(&_16$$32, 1, 0);
							ZEPHIR_INIT_NVAR(&_17$$32);
							zephir_get_class(&_17$$32, this_ptr, 0);
							zephir_array_update_string(&_16$$32, SL("model"), &_17$$32, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_17$$32);
							ZVAL_STRING(&_17$$32, "PresenceOf");
							ZVAL_LONG(&_18$$32, 0);
							ZEPHIR_CALL_METHOD(NULL, &_14$$32, "__construct", &_19, 6, &_15$$32, &attributeField, &_17$$32, &_18$$32, &_16$$32);
							zephir_check_call_status();
							zephir_update_property_array_append(this_ptr, SL("errorMessages"), &_14$$32);
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
									ZEPHIR_INIT_NVAR(&_20$$39);
									object_init_ex(&_20$$39, phalcon_mvc_model_exception_ce);
									ZEPHIR_INIT_NVAR(&_21$$39);
									zephir_get_class(&_21$$39, this_ptr, 0);
									ZEPHIR_INIT_NVAR(&_22$$39);
									ZEPHIR_CONCAT_SVSVS(&_22$$39, "Column '", &field, "' in '", &_21$$39, "' isn't part of the column map");
									ZEPHIR_CALL_METHOD(NULL, &_20$$39, "__construct", &_9, 33, &_22$$39);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_20$$39, "phalcon/Mvc/Model.zep", 4866);
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
											_23$$47 = Z_TYPE_P(&value) == IS_NULL;
											if (!(_23$$47)) {
												_24$$47 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
												if (_24$$47) {
													_25$$47 = !(zephir_array_isset(&defaultValues, &field));
													if (!(_25$$47)) {
														zephir_array_fetch(&_26$$47, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4896);
														_25$$47 = !ZEPHIR_IS_IDENTICAL(&value, &_26$$47);
													}
													_24$$47 = _25$$47;
												}
												_23$$47 = _24$$47;
											}
											if (_23$$47) {
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
								ZEPHIR_INIT_NVAR(&_27$$52);
								object_init_ex(&_27$$52, phalcon_messages_message_ce);
								ZEPHIR_INIT_NVAR(&_28$$52);
								ZEPHIR_CONCAT_VS(&_28$$52, &attributeField, " is required");
								ZEPHIR_INIT_NVAR(&_29$$52);
								zephir_create_array(&_29$$52, 1, 0);
								ZEPHIR_INIT_NVAR(&_30$$52);
								zephir_get_class(&_30$$52, this_ptr, 0);
								zephir_array_update_string(&_29$$52, SL("model"), &_30$$52, PH_COPY | PH_SEPARATE);
								ZEPHIR_INIT_NVAR(&_30$$52);
								ZVAL_STRING(&_30$$52, "PresenceOf");
								ZVAL_LONG(&_31$$52, 0);
								ZEPHIR_CALL_METHOD(NULL, &_27$$52, "__construct", &_19, 6, &_28$$52, &attributeField, &_30$$52, &_31$$52, &_29$$52);
								zephir_check_call_status();
								zephir_update_property_array_append(this_ptr, SL("errorMessages"), &_27$$52);
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
					ZEPHIR_INIT_VAR(&_32$$57);
					ZVAL_STRING(&_32$$57, "onValidationFails");
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_32$$57);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "canceloperation", NULL, 0);
					zephir_check_call_status();
				}
				RETURN_MM_BOOL(0);
			}
		}
	}
	ZEPHIR_INIT_VAR(&_34);
	ZVAL_STRING(&_34, "validation");
	ZEPHIR_CALL_METHOD(&_33, this_ptr, "fireeventcancel", NULL, 0, &_34);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_33)) {
		if (ZEPHIR_GLOBAL(orm).events) {
			ZEPHIR_INIT_VAR(&_35$$59);
			ZVAL_STRING(&_35$$59, "onValidationFails");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_35$$59);
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
		ZEPHIR_CALL_METHOD(&_36$$60, this_ptr, "fireeventcancel", NULL, 0, &eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_36$$60)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(&_38$$60);
		ZVAL_STRING(&_38$$60, "afterValidation");
		ZEPHIR_CALL_METHOD(&_37$$60, this_ptr, "fireeventcancel", NULL, 0, &_38$$60);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_37$$60)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(&_38$$60);
		ZVAL_STRING(&_38$$60, "beforeSave");
		ZEPHIR_CALL_METHOD(&_39$$60, this_ptr, "fireeventcancel", NULL, 0, &_38$$60);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_39$$60)) {
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
		ZEPHIR_CALL_METHOD(&_40$$60, this_ptr, "fireeventcancel", NULL, 0, &eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_40$$60)) {
			RETURN_MM_BOOL(0);
		}
		zephir_read_property(&_41$$60, this_ptr, ZEND_STRL("skipped"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_41$$60)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(1);
}

/**
 * Saves related records that must be stored prior to save the master record
 *
 * @param ModelInterface[] related
 * @param CollectionInterface visited
 * @return bool
 */
PHP_METHOD(Phalcon_Mvc_Model, preSaveRelatedRecords)
{
	zend_string *_5;
	zend_ulong _4;
	zend_bool nesting = 0, _20$$5, _39$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_9 = NULL, *_13 = NULL, *_15 = NULL, *_22 = NULL, *_24 = NULL, *_27 = NULL, *_29 = NULL, *_34 = NULL, *_42 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, *related, related_sub, *visited, visited_sub, className, manager, type, relation, columns, referencedFields, name, record, _0, _1, *_2, _3, _6$$3, _8$$6, _10$$6, _11$$6, _12$$6, _14$$7, _16$$7, _17$$7, _18$$7, _19$$5, _21$$5, _25$$5, _23$$8, _26$$9, _28$$12, _30$$12, _31$$12, _32$$12, _33$$13, _35$$13, _36$$13, _37$$13, _38$$11, _40$$11, _43$$11, _41$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&related_sub);
	ZVAL_UNDEF(&visited_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&referencedFields);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_25$$5);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_26$$9);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_30$$12);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_35$$13);
	ZVAL_UNDEF(&_36$$13);
	ZVAL_UNDEF(&_37$$13);
	ZVAL_UNDEF(&_38$$11);
	ZVAL_UNDEF(&_40$$11);
	ZVAL_UNDEF(&_43$$11);
	ZVAL_UNDEF(&_41$$14);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(connection, phalcon_db_adapter_adapterinterface_ce)
		Z_PARAM_ZVAL(related)
		Z_PARAM_OBJECT_OF_CLASS(visited, phalcon_support_collection_collectioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &connection, &related, &visited);
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
	zephir_is_iterable(related, 0, "phalcon/Mvc/Model.zep", 5110);
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
						ZEPHIR_INIT_NVAR(&_10$$6);
						object_init_ex(&_10$$6, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_11$$6);
						zephir_get_class(&_11$$6, this_ptr, 0);
						ZEPHIR_INIT_NVAR(&_12$$6);
						ZEPHIR_CONCAT_SVSV(&_12$$6, "Only objects can be stored as part of belongs-to relations in '", &_11$$6, "' Relation ", &name);
						ZEPHIR_CALL_METHOD(NULL, &_10$$6, "__construct", &_13, 33, &_12$$6);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_10$$6, "phalcon/Mvc/Model.zep", 5068);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&columns, &relation, "getfields", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", NULL, 0);
					zephir_check_call_status();
					if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
						if (nesting) {
							ZVAL_BOOL(&_14$$7, 1);
						} else {
							ZVAL_BOOL(&_14$$7, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_15, 0, &_14$$7);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_16$$7);
						object_init_ex(&_16$$7, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_17$$7);
						zephir_get_class(&_17$$7, this_ptr, 0);
						ZEPHIR_INIT_NVAR(&_18$$7);
						ZEPHIR_CONCAT_SVSV(&_18$$7, "Not implemented in '", &_17$$7, "' Relation ", &name);
						ZEPHIR_CALL_METHOD(NULL, &_16$$7, "__construct", &_13, 33, &_18$$7);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_16$$7, "phalcon/Mvc/Model.zep", 5079);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_read_property(&_19$$5, &record, ZEND_STRL("dirtyState"), PH_NOISY_CC | PH_READONLY);
					_20$$5 = !ZEPHIR_IS_LONG_IDENTICAL(&_19$$5, 0);
					if (_20$$5) {
						ZEPHIR_CALL_METHOD(&_21$$5, &record, "dosave", NULL, 0, visited);
						zephir_check_call_status();
						_20$$5 = !zephir_is_true(&_21$$5);
					}
					if (_20$$5) {
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_22, 0, &record);
						zephir_check_call_status();
						if (nesting) {
							ZVAL_BOOL(&_23$$8, 1);
						} else {
							ZVAL_BOOL(&_23$$8, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_24, 0, &_23$$8);
						zephir_check_call_status();
						RETURN_MM_BOOL(0);
					}
					ZEPHIR_CALL_METHOD(&_25$$5, &record, "readattribute", NULL, 0, &referencedFields);
					zephir_check_call_status();
					zephir_update_property_zval_zval(this_ptr, &columns, &_25$$5);
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
				ZEPHIR_CALL_METHOD(&_26$$9, &manager, "getrelationbyalias", &_27, 0, &className, &name);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&relation, &_26$$9);
				if (Z_TYPE_P(&relation) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&type, &relation, "gettype", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG(&type, 0)) {
						if (UNEXPECTED(Z_TYPE_P(&record) != IS_OBJECT)) {
							if (nesting) {
								ZVAL_BOOL(&_28$$12, 1);
							} else {
								ZVAL_BOOL(&_28$$12, 0);
							}
							ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_29, 0, &_28$$12);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_30$$12);
							object_init_ex(&_30$$12, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_31$$12);
							zephir_get_class(&_31$$12, this_ptr, 0);
							ZEPHIR_INIT_NVAR(&_32$$12);
							ZEPHIR_CONCAT_SVSV(&_32$$12, "Only objects can be stored as part of belongs-to relations in '", &_31$$12, "' Relation ", &name);
							ZEPHIR_CALL_METHOD(NULL, &_30$$12, "__construct", &_13, 33, &_32$$12);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_30$$12, "phalcon/Mvc/Model.zep", 5068);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD(&columns, &relation, "getfields", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", NULL, 0);
						zephir_check_call_status();
						if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
							if (nesting) {
								ZVAL_BOOL(&_33$$13, 1);
							} else {
								ZVAL_BOOL(&_33$$13, 0);
							}
							ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_34, 0, &_33$$13);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_35$$13);
							object_init_ex(&_35$$13, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_36$$13);
							zephir_get_class(&_36$$13, this_ptr, 0);
							ZEPHIR_INIT_NVAR(&_37$$13);
							ZEPHIR_CONCAT_SVSV(&_37$$13, "Not implemented in '", &_36$$13, "' Relation ", &name);
							ZEPHIR_CALL_METHOD(NULL, &_35$$13, "__construct", &_13, 33, &_37$$13);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_35$$13, "phalcon/Mvc/Model.zep", 5079);
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_read_property(&_38$$11, &record, ZEND_STRL("dirtyState"), PH_NOISY_CC | PH_READONLY);
						_39$$11 = !ZEPHIR_IS_LONG_IDENTICAL(&_38$$11, 0);
						if (_39$$11) {
							ZEPHIR_CALL_METHOD(&_40$$11, &record, "dosave", NULL, 0, visited);
							zephir_check_call_status();
							_39$$11 = !zephir_is_true(&_40$$11);
						}
						if (_39$$11) {
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_22, 0, &record);
							zephir_check_call_status();
							if (nesting) {
								ZVAL_BOOL(&_41$$14, 1);
							} else {
								ZVAL_BOOL(&_41$$14, 0);
							}
							ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_42, 0, &_41$$14);
							zephir_check_call_status();
							RETURN_MM_BOOL(0);
						}
						ZEPHIR_CALL_METHOD(&_43$$11, &record, "readattribute", NULL, 0, &referencedFields);
						zephir_check_call_status();
						zephir_update_property_zval_zval(this_ptr, &columns, &_43$$11);
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
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_BOOL(success)
		Z_PARAM_BOOL(exists)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &success_param, &exists_param);
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
 * @param CollectionInterface visited
 * @return bool
 */
PHP_METHOD(Phalcon_Mvc_Model, postSaveRelatedRecords)
{
	zval _32$$14, _34$$14, _44$$19, _46$$19, _88$$40, _90$$40, _100$$45, _102$$45;
	zend_string *_4;
	zend_ulong _3;
	zend_bool nesting = 0, isThrough = 0, _8$$4, _65$$30;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_10 = NULL, *_13 = NULL, *_15 = NULL, *_19 = NULL, *_26 = NULL, *_28 = NULL, *_30 = NULL, *_31 = NULL, *_37 = NULL, *_40 = NULL, *_42 = NULL, *_43 = NULL, *_49 = NULL, *_54 = NULL, *_57 = NULL, *_59 = NULL, *_63 = NULL, *_67 = NULL, *_71 = NULL, *_76 = NULL, *_84 = NULL, *_86 = NULL, *_87 = NULL, *_93 = NULL, *_96 = NULL, *_98 = NULL, *_99 = NULL, *_105 = NULL, *_110 = NULL, *_113 = NULL, *_115 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, *related, related_sub, *visited, visited_sub, className, manager, relation, name, record, columns, referencedModel, referencedFields, relatedRecords, value, recordAfter, intermediateModel, intermediateFields, intermediateValue, intermediateModelName, intermediateReferencedFields, existingIntermediateModel, _0, *_1, _2, _118, _5$$3, _7$$4, _22$$4, _9$$6, _11$$6, _12$$6, _14$$7, _16$$7, _17$$7, _18$$10, _20$$10, _21$$10, *_23$$11, _24$$11, _25$$12, _29$$12, _35$$12, _27$$13, _33$$14, _36$$16, _38$$17, _41$$17, _47$$17, _39$$18, _45$$19, _48$$21, *_50$$22, _51$$22, _52$$23, _53$$24, _55$$25, _56$$26, _58$$28, _60$$28, _61$$28, _62$$29, _64$$30, _79$$30, _66$$32, _68$$32, _69$$32, _70$$33, _72$$33, _73$$33, _74$$34, _75$$36, _77$$36, _78$$36, *_80$$37, _81$$37, _82$$38, _85$$38, _91$$38, _83$$39, _89$$40, _92$$42, _94$$43, _97$$43, _103$$43, _95$$44, _101$$45, _104$$47, *_106$$48, _107$$48, _108$$49, _109$$50, _111$$51, _112$$52, _114$$54, _116$$54, _117$$54;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&related_sub);
	ZVAL_UNDEF(&visited_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&record);
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
	ZVAL_UNDEF(&_118);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_22$$4);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_25$$12);
	ZVAL_UNDEF(&_29$$12);
	ZVAL_UNDEF(&_35$$12);
	ZVAL_UNDEF(&_27$$13);
	ZVAL_UNDEF(&_33$$14);
	ZVAL_UNDEF(&_36$$16);
	ZVAL_UNDEF(&_38$$17);
	ZVAL_UNDEF(&_41$$17);
	ZVAL_UNDEF(&_47$$17);
	ZVAL_UNDEF(&_39$$18);
	ZVAL_UNDEF(&_45$$19);
	ZVAL_UNDEF(&_48$$21);
	ZVAL_UNDEF(&_51$$22);
	ZVAL_UNDEF(&_52$$23);
	ZVAL_UNDEF(&_53$$24);
	ZVAL_UNDEF(&_55$$25);
	ZVAL_UNDEF(&_56$$26);
	ZVAL_UNDEF(&_58$$28);
	ZVAL_UNDEF(&_60$$28);
	ZVAL_UNDEF(&_61$$28);
	ZVAL_UNDEF(&_62$$29);
	ZVAL_UNDEF(&_64$$30);
	ZVAL_UNDEF(&_79$$30);
	ZVAL_UNDEF(&_66$$32);
	ZVAL_UNDEF(&_68$$32);
	ZVAL_UNDEF(&_69$$32);
	ZVAL_UNDEF(&_70$$33);
	ZVAL_UNDEF(&_72$$33);
	ZVAL_UNDEF(&_73$$33);
	ZVAL_UNDEF(&_74$$34);
	ZVAL_UNDEF(&_75$$36);
	ZVAL_UNDEF(&_77$$36);
	ZVAL_UNDEF(&_78$$36);
	ZVAL_UNDEF(&_81$$37);
	ZVAL_UNDEF(&_82$$38);
	ZVAL_UNDEF(&_85$$38);
	ZVAL_UNDEF(&_91$$38);
	ZVAL_UNDEF(&_83$$39);
	ZVAL_UNDEF(&_89$$40);
	ZVAL_UNDEF(&_92$$42);
	ZVAL_UNDEF(&_94$$43);
	ZVAL_UNDEF(&_97$$43);
	ZVAL_UNDEF(&_103$$43);
	ZVAL_UNDEF(&_95$$44);
	ZVAL_UNDEF(&_101$$45);
	ZVAL_UNDEF(&_104$$47);
	ZVAL_UNDEF(&_107$$48);
	ZVAL_UNDEF(&_108$$49);
	ZVAL_UNDEF(&_109$$50);
	ZVAL_UNDEF(&_111$$51);
	ZVAL_UNDEF(&_112$$52);
	ZVAL_UNDEF(&_114$$54);
	ZVAL_UNDEF(&_116$$54);
	ZVAL_UNDEF(&_117$$54);
	ZVAL_UNDEF(&_32$$14);
	ZVAL_UNDEF(&_34$$14);
	ZVAL_UNDEF(&_44$$19);
	ZVAL_UNDEF(&_46$$19);
	ZVAL_UNDEF(&_88$$40);
	ZVAL_UNDEF(&_90$$40);
	ZVAL_UNDEF(&_100$$45);
	ZVAL_UNDEF(&_102$$45);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(connection, phalcon_db_adapter_adapterinterface_ce)
		Z_PARAM_ZVAL(related)
		Z_PARAM_OBJECT_OF_CLASS(visited, phalcon_support_collection_collectioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &connection, &related, &visited);
	nesting = 0;
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, this_ptr, 0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_0);
	zephir_is_iterable(related, 0, "phalcon/Mvc/Model.zep", 5338);
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
					ZEPHIR_INIT_NVAR(&_11$$6);
					object_init_ex(&_11$$6, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_NVAR(&_12$$6);
					ZEPHIR_CONCAT_SVSV(&_12$$6, "Only objects/arrays can be stored as part of has-many/has-one/has-one-through/has-many-to-many relations on model ", &className, " on Relation ", &name);
					ZEPHIR_CALL_METHOD(NULL, &_11$$6, "__construct", &_13, 33, &_12$$6);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_11$$6, "phalcon/Mvc/Model.zep", 5173);
					ZEPHIR_MM_RESTORE();
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
						ZVAL_BOOL(&_14$$7, 1);
					} else {
						ZVAL_BOOL(&_14$$7, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_15, 0, &_14$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_16$$7);
					object_init_ex(&_16$$7, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_NVAR(&_17$$7);
					ZEPHIR_CONCAT_SVSV(&_17$$7, "Not implemented in '", &className, "' on Relation ", &name);
					ZEPHIR_CALL_METHOD(NULL, &_16$$7, "__construct", &_13, 33, &_17$$7);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_16$$7, "phalcon/Mvc/Model.zep", 5183);
					ZEPHIR_MM_RESTORE();
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
						ZVAL_BOOL(&_18$$10, 1);
					} else {
						ZVAL_BOOL(&_18$$10, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_19, 0, &_18$$10);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_20$$10);
					object_init_ex(&_20$$10, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_NVAR(&_21$$10);
					ZEPHIR_CONCAT_SVSVS(&_21$$10, "The column '", &columns, "' needs to be present in the model '", &className, "'");
					ZEPHIR_CALL_METHOD(NULL, &_20$$10, "__construct", &_13, 33, &_21$$10);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_20$$10, "phalcon/Mvc/Model.zep", 5200);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&_22$$4, &relation, "isthrough", NULL, 0);
				zephir_check_call_status();
				isThrough = zephir_get_boolval(&_22$$4);
				if (isThrough) {
					ZEPHIR_CALL_METHOD(&intermediateModelName, &relation, "getintermediatemodel", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&intermediateFields, &relation, "getintermediatefields", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&intermediateReferencedFields, &relation, "getintermediatereferencedfields", NULL, 0);
					zephir_check_call_status();
					zephir_is_iterable(&relatedRecords, 0, "phalcon/Mvc/Model.zep", 5299);
					if (Z_TYPE_P(&relatedRecords) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relatedRecords), _23$$11)
						{
							ZEPHIR_INIT_NVAR(&recordAfter);
							ZVAL_COPY(&recordAfter, _23$$11);
							ZEPHIR_CALL_METHOD(&_25$$12, &recordAfter, "dosave", NULL, 0, visited);
							zephir_check_call_status();
							if (!(zephir_is_true(&_25$$12))) {
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &recordAfter);
								zephir_check_call_status();
								if (nesting) {
									ZVAL_BOOL(&_27$$13, 1);
								} else {
									ZVAL_BOOL(&_27$$13, 0);
								}
								ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_28, 0, &_27$$13);
								zephir_check_call_status();
								RETURN_MM_BOOL(0);
							}
							ZEPHIR_CALL_METHOD(&_29$$12, &manager, "load", &_30, 0, &intermediateModelName);
							zephir_check_call_status();
							ZEPHIR_CPY_WRT(&intermediateModel, &_29$$12);
							ZEPHIR_CALL_METHOD(&_29$$12, &relation, "gettype", &_31, 0);
							zephir_check_call_status();
							if (ZEPHIR_IS_LONG(&_29$$12, 3)) {
								ZEPHIR_INIT_NVAR(&_32$$14);
								zephir_create_array(&_32$$14, 2, 0);
								ZEPHIR_INIT_NVAR(&_33$$14);
								ZEPHIR_CONCAT_SVS(&_33$$14, "[", &intermediateFields, "] = ?0");
								zephir_array_fast_append(&_32$$14, &_33$$14);
								ZEPHIR_INIT_NVAR(&_34$$14);
								zephir_create_array(&_34$$14, 1, 0);
								zephir_array_fast_append(&_34$$14, &value);
								zephir_array_update_string(&_32$$14, SL("bind"), &_34$$14, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(&existingIntermediateModel, &intermediateModel, "findfirst", NULL, 0, &_32$$14);
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
							ZEPHIR_CALL_METHOD(&_35$$12, &intermediateModel, "dosave", NULL, 0, visited);
							zephir_check_call_status();
							if (!(zephir_is_true(&_35$$12))) {
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &intermediateModel);
								zephir_check_call_status();
								if (nesting) {
									ZVAL_BOOL(&_36$$16, 1);
								} else {
									ZVAL_BOOL(&_36$$16, 0);
								}
								ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_37, 0, &_36$$16);
								zephir_check_call_status();
								RETURN_MM_BOOL(0);
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_24$$11, &relatedRecords, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_24$$11)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&recordAfter, &relatedRecords, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&_38$$17, &recordAfter, "dosave", NULL, 0, visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_38$$17))) {
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &recordAfter);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_39$$18, 1);
									} else {
										ZVAL_BOOL(&_39$$18, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_40, 0, &_39$$18);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
								ZEPHIR_CALL_METHOD(&_41$$17, &manager, "load", &_42, 0, &intermediateModelName);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&intermediateModel, &_41$$17);
								ZEPHIR_CALL_METHOD(&_41$$17, &relation, "gettype", &_43, 0);
								zephir_check_call_status();
								if (ZEPHIR_IS_LONG(&_41$$17, 3)) {
									ZEPHIR_INIT_NVAR(&_44$$19);
									zephir_create_array(&_44$$19, 2, 0);
									ZEPHIR_INIT_NVAR(&_45$$19);
									ZEPHIR_CONCAT_SVS(&_45$$19, "[", &intermediateFields, "] = ?0");
									zephir_array_fast_append(&_44$$19, &_45$$19);
									ZEPHIR_INIT_NVAR(&_46$$19);
									zephir_create_array(&_46$$19, 1, 0);
									zephir_array_fast_append(&_46$$19, &value);
									zephir_array_update_string(&_44$$19, SL("bind"), &_46$$19, PH_COPY | PH_SEPARATE);
									ZEPHIR_CALL_METHOD(&existingIntermediateModel, &intermediateModel, "findfirst", NULL, 0, &_44$$19);
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
								ZEPHIR_CALL_METHOD(&_47$$17, &intermediateModel, "dosave", NULL, 0, visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_47$$17))) {
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &intermediateModel);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_48$$21, 1);
									} else {
										ZVAL_BOOL(&_48$$21, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_49, 0, &_48$$21);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
							ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&recordAfter);
				} else {
					zephir_is_iterable(&relatedRecords, 0, "phalcon/Mvc/Model.zep", 5323);
					if (Z_TYPE_P(&relatedRecords) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relatedRecords), _50$$22)
						{
							ZEPHIR_INIT_NVAR(&recordAfter);
							ZVAL_COPY(&recordAfter, _50$$22);
							ZEPHIR_CALL_METHOD(NULL, &recordAfter, "writeattribute", NULL, 0, &referencedFields, &value);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_52$$23, &recordAfter, "dosave", NULL, 0, visited);
							zephir_check_call_status();
							if (!(zephir_is_true(&_52$$23))) {
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &recordAfter);
								zephir_check_call_status();
								if (nesting) {
									ZVAL_BOOL(&_53$$24, 1);
								} else {
									ZVAL_BOOL(&_53$$24, 0);
								}
								ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_54, 0, &_53$$24);
								zephir_check_call_status();
								RETURN_MM_BOOL(0);
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_51$$22, &relatedRecords, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_51$$22)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&recordAfter, &relatedRecords, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, &recordAfter, "writeattribute", NULL, 0, &referencedFields, &value);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&_55$$25, &recordAfter, "dosave", NULL, 0, visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_55$$25))) {
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &recordAfter);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_56$$26, 1);
									} else {
										ZVAL_BOOL(&_56$$26, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_57, 0, &_56$$26);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
							ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&recordAfter);
				}
			} else {
				if (UNEXPECTED(Z_TYPE_P(&record) != IS_ARRAY)) {
					if (nesting) {
						ZVAL_BOOL(&_58$$28, 1);
					} else {
						ZVAL_BOOL(&_58$$28, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_59, 0, &_58$$28);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_60$$28);
					object_init_ex(&_60$$28, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_NVAR(&_61$$28);
					ZEPHIR_CONCAT_SVSVS(&_61$$28, "There are no defined relations for the model '", &className, "' using alias '", &name, "'");
					ZEPHIR_CALL_METHOD(NULL, &_60$$28, "__construct", &_13, 33, &_61$$28);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_60$$28, "phalcon/Mvc/Model.zep", 5330);
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
				ZEPHIR_CALL_METHOD(&_62$$29, &manager, "getrelationbyalias", &_63, 0, &className, &name);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&relation, &_62$$29);
				if (Z_TYPE_P(&relation) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&_64$$30, &relation, "gettype", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG(&_64$$30, 0)) {
						continue;
					}
					_65$$30 = Z_TYPE_P(&record) != IS_OBJECT;
					if (_65$$30) {
						_65$$30 = Z_TYPE_P(&record) != IS_ARRAY;
					}
					if (UNEXPECTED(_65$$30)) {
						if (nesting) {
							ZVAL_BOOL(&_66$$32, 1);
						} else {
							ZVAL_BOOL(&_66$$32, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_67, 0, &_66$$32);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_68$$32);
						object_init_ex(&_68$$32, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_69$$32);
						ZEPHIR_CONCAT_SVSV(&_69$$32, "Only objects/arrays can be stored as part of has-many/has-one/has-one-through/has-many-to-many relations on model ", &className, " on Relation ", &name);
						ZEPHIR_CALL_METHOD(NULL, &_68$$32, "__construct", &_13, 33, &_69$$32);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_68$$32, "phalcon/Mvc/Model.zep", 5173);
						ZEPHIR_MM_RESTORE();
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
							ZVAL_BOOL(&_70$$33, 1);
						} else {
							ZVAL_BOOL(&_70$$33, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_71, 0, &_70$$33);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_72$$33);
						object_init_ex(&_72$$33, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_73$$33);
						ZEPHIR_CONCAT_SVSV(&_73$$33, "Not implemented in '", &className, "' on Relation ", &name);
						ZEPHIR_CALL_METHOD(NULL, &_72$$33, "__construct", &_13, 33, &_73$$33);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_72$$33, "phalcon/Mvc/Model.zep", 5183);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (Z_TYPE_P(&record) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_74$$34);
						zephir_create_array(&_74$$34, 1, 0);
						zephir_array_fast_append(&_74$$34, &record);
						ZEPHIR_CPY_WRT(&relatedRecords, &_74$$34);
					} else {
						ZEPHIR_CPY_WRT(&relatedRecords, &record);
					}
					ZEPHIR_OBS_NVAR(&value);
					if (UNEXPECTED(!(zephir_fetch_property_zval(&value, this_ptr, &columns, PH_SILENT_CC)))) {
						if (nesting) {
							ZVAL_BOOL(&_75$$36, 1);
						} else {
							ZVAL_BOOL(&_75$$36, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_76, 0, &_75$$36);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_77$$36);
						object_init_ex(&_77$$36, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_78$$36);
						ZEPHIR_CONCAT_SVSVS(&_78$$36, "The column '", &columns, "' needs to be present in the model '", &className, "'");
						ZEPHIR_CALL_METHOD(NULL, &_77$$36, "__construct", &_13, 33, &_78$$36);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_77$$36, "phalcon/Mvc/Model.zep", 5200);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_79$$30, &relation, "isthrough", NULL, 0);
					zephir_check_call_status();
					isThrough = zephir_get_boolval(&_79$$30);
					if (isThrough) {
						ZEPHIR_CALL_METHOD(&intermediateModelName, &relation, "getintermediatemodel", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&intermediateFields, &relation, "getintermediatefields", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&intermediateReferencedFields, &relation, "getintermediatereferencedfields", NULL, 0);
						zephir_check_call_status();
						zephir_is_iterable(&relatedRecords, 0, "phalcon/Mvc/Model.zep", 5299);
						if (Z_TYPE_P(&relatedRecords) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relatedRecords), _80$$37)
							{
								ZEPHIR_INIT_NVAR(&recordAfter);
								ZVAL_COPY(&recordAfter, _80$$37);
								ZEPHIR_CALL_METHOD(&_82$$38, &recordAfter, "dosave", NULL, 0, visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_82$$38))) {
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &recordAfter);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_83$$39, 1);
									} else {
										ZVAL_BOOL(&_83$$39, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_84, 0, &_83$$39);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
								ZEPHIR_CALL_METHOD(&_85$$38, &manager, "load", &_86, 0, &intermediateModelName);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&intermediateModel, &_85$$38);
								ZEPHIR_CALL_METHOD(&_85$$38, &relation, "gettype", &_87, 0);
								zephir_check_call_status();
								if (ZEPHIR_IS_LONG(&_85$$38, 3)) {
									ZEPHIR_INIT_NVAR(&_88$$40);
									zephir_create_array(&_88$$40, 2, 0);
									ZEPHIR_INIT_NVAR(&_89$$40);
									ZEPHIR_CONCAT_SVS(&_89$$40, "[", &intermediateFields, "] = ?0");
									zephir_array_fast_append(&_88$$40, &_89$$40);
									ZEPHIR_INIT_NVAR(&_90$$40);
									zephir_create_array(&_90$$40, 1, 0);
									zephir_array_fast_append(&_90$$40, &value);
									zephir_array_update_string(&_88$$40, SL("bind"), &_90$$40, PH_COPY | PH_SEPARATE);
									ZEPHIR_CALL_METHOD(&existingIntermediateModel, &intermediateModel, "findfirst", NULL, 0, &_88$$40);
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
								ZEPHIR_CALL_METHOD(&_91$$38, &intermediateModel, "dosave", NULL, 0, visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_91$$38))) {
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &intermediateModel);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_92$$42, 1);
									} else {
										ZVAL_BOOL(&_92$$42, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_93, 0, &_92$$42);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_81$$37, &relatedRecords, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_81$$37)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&recordAfter, &relatedRecords, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&_94$$43, &recordAfter, "dosave", NULL, 0, visited);
									zephir_check_call_status();
									if (!(zephir_is_true(&_94$$43))) {
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &recordAfter);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_95$$44, 1);
										} else {
											ZVAL_BOOL(&_95$$44, 0);
										}
										ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_96, 0, &_95$$44);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
									ZEPHIR_CALL_METHOD(&_97$$43, &manager, "load", &_98, 0, &intermediateModelName);
									zephir_check_call_status();
									ZEPHIR_CPY_WRT(&intermediateModel, &_97$$43);
									ZEPHIR_CALL_METHOD(&_97$$43, &relation, "gettype", &_99, 0);
									zephir_check_call_status();
									if (ZEPHIR_IS_LONG(&_97$$43, 3)) {
										ZEPHIR_INIT_NVAR(&_100$$45);
										zephir_create_array(&_100$$45, 2, 0);
										ZEPHIR_INIT_NVAR(&_101$$45);
										ZEPHIR_CONCAT_SVS(&_101$$45, "[", &intermediateFields, "] = ?0");
										zephir_array_fast_append(&_100$$45, &_101$$45);
										ZEPHIR_INIT_NVAR(&_102$$45);
										zephir_create_array(&_102$$45, 1, 0);
										zephir_array_fast_append(&_102$$45, &value);
										zephir_array_update_string(&_100$$45, SL("bind"), &_102$$45, PH_COPY | PH_SEPARATE);
										ZEPHIR_CALL_METHOD(&existingIntermediateModel, &intermediateModel, "findfirst", NULL, 0, &_100$$45);
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
									ZEPHIR_CALL_METHOD(&_103$$43, &intermediateModel, "dosave", NULL, 0, visited);
									zephir_check_call_status();
									if (!(zephir_is_true(&_103$$43))) {
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &intermediateModel);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_104$$47, 1);
										} else {
											ZVAL_BOOL(&_104$$47, 0);
										}
										ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_105, 0, &_104$$47);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
								ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&recordAfter);
					} else {
						zephir_is_iterable(&relatedRecords, 0, "phalcon/Mvc/Model.zep", 5323);
						if (Z_TYPE_P(&relatedRecords) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relatedRecords), _106$$48)
							{
								ZEPHIR_INIT_NVAR(&recordAfter);
								ZVAL_COPY(&recordAfter, _106$$48);
								ZEPHIR_CALL_METHOD(NULL, &recordAfter, "writeattribute", NULL, 0, &referencedFields, &value);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&_108$$49, &recordAfter, "dosave", NULL, 0, visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_108$$49))) {
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &recordAfter);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_109$$50, 1);
									} else {
										ZVAL_BOOL(&_109$$50, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_110, 0, &_109$$50);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_107$$48, &relatedRecords, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_107$$48)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&recordAfter, &relatedRecords, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_CALL_METHOD(NULL, &recordAfter, "writeattribute", NULL, 0, &referencedFields, &value);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&_111$$51, &recordAfter, "dosave", NULL, 0, visited);
									zephir_check_call_status();
									if (!(zephir_is_true(&_111$$51))) {
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &recordAfter);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_112$$52, 1);
										} else {
											ZVAL_BOOL(&_112$$52, 0);
										}
										ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_113, 0, &_112$$52);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
								ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&recordAfter);
					}
				} else {
					if (UNEXPECTED(Z_TYPE_P(&record) != IS_ARRAY)) {
						if (nesting) {
							ZVAL_BOOL(&_114$$54, 1);
						} else {
							ZVAL_BOOL(&_114$$54, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_115, 0, &_114$$54);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_116$$54);
						object_init_ex(&_116$$54, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_117$$54);
						ZEPHIR_CONCAT_SVSVS(&_117$$54, "There are no defined relations for the model '", &className, "' using alias '", &name, "'");
						ZEPHIR_CALL_METHOD(NULL, &_116$$54, "__construct", &_13, 33, &_117$$54);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_116$$54, "phalcon/Mvc/Model.zep", 5330);
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
		ZVAL_BOOL(&_118, 1);
	} else {
		ZVAL_BOOL(&_118, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, connection, "commit", NULL, 0, &_118);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &attributes_param);
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);
	ZEPHIR_INIT_VAR(&keysAttributes);
	array_init(&keysAttributes);
	zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model.zep", 5371);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

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
 * @param array $options = [
 *     'reusable' => false,
 *     'alias' => 'someAlias',
 *     'foreignKey' => [
 *         'message' => null,
 *         'allowNulls' => false,
 *         'action' => null
 *     ],
 *     'params' => [
 *         'conditions' => '',
 *         'columns' => '',
 *         'bind' => [],
 *         'bindTypes' => [],
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
	zval options;
	zval referenceModel;
	zval *fields, fields_sub, *referenceModel_param = NULL, *referencedFields, referencedFields_sub, *options_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&referenceModel);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_ZVAL(fields)
		Z_PARAM_STR(referenceModel)
		Z_PARAM_ZVAL(referencedFields)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 1, &fields, &referenceModel_param, &referencedFields, &options_param);
	if (UNEXPECTED(Z_TYPE_P(referenceModel_param) != IS_STRING && Z_TYPE_P(referenceModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceModel' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referenceModel_param) == IS_STRING)) {
		zephir_get_strval(&referenceModel, referenceModel_param);
	} else {
		ZEPHIR_INIT_VAR(&referenceModel);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addbelongsto", NULL, 0, this_ptr, fields, &referenceModel, referencedFields, &options);
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
	zval *params, params_sub, *limit = NULL, limit_sub, __$null, builder, bindParams, bindTypes, transaction, cache, manager, query, container, _0, _1, _2$$5, _3$$7;

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
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$7);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(params)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(limit)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &params, &limit);
	if (!limit) {
		limit = &limit_sub;
		limit = &__$null;
	}
	ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_di_ce, "getdefault", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "modelsManager");
	ZEPHIR_CALL_METHOD(&_0, &container, "getshared", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&_0, &manager, "createbuilder", NULL, 0, params);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&builder, &_0);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_get_called_class(&_1);
	ZEPHIR_CALL_METHOD(NULL, &builder, "from", NULL, 0, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(limit) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, &builder, "limit", NULL, 0, limit);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_0, &builder, "getquery", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&query, &_0);
	zephir_memory_observe(&bindParams);
	if (zephir_array_isset_string_fetch(&bindParams, params, SL("bind"), 0)) {
		if (Z_TYPE_P(&bindParams) == IS_ARRAY) {
			ZVAL_BOOL(&_2$$5, 1);
			ZEPHIR_CALL_METHOD(NULL, &query, "setbindparams", NULL, 0, &bindParams, &_2$$5);
			zephir_check_call_status();
		}
		zephir_memory_observe(&bindTypes);
		if (zephir_array_isset_string_fetch(&bindTypes, params, SL("bindTypes"), 0)) {
			if (Z_TYPE_P(&bindTypes) == IS_ARRAY) {
				ZVAL_BOOL(&_3$$7, 1);
				ZEPHIR_CALL_METHOD(NULL, &query, "setbindtypes", NULL, 0, &bindTypes, &_3$$7);
				zephir_check_call_status();
			}
		}
	}
	zephir_memory_observe(&transaction);
	if (zephir_array_isset_string_fetch(&transaction, params, SL("transaction"), 0)) {
		if (zephir_instance_of_ev(&transaction, phalcon_mvc_model_transactioninterface_ce)) {
			ZEPHIR_CALL_METHOD(NULL, &query, "settransaction", NULL, 0, &transaction);
			zephir_check_call_status();
		}
	}
	zephir_memory_observe(&cache);
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
 * @param array $options = [
 *     'reusable' => false,
 *     'alias' => 'someAlias',
 *     'foreignKey' => [
 *         'message' => null,
 *         'allowNulls' => false,
 *         'action' => null
 *     ],
 *     'params' => [
 *         'conditions' => '',
 *         'columns' => '',
 *         'bind' => [],
 *         'bindTypes' => [],
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
	zval options;
	zval referenceModel;
	zval *fields, fields_sub, *referenceModel_param = NULL, *referencedFields, referencedFields_sub, *options_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&referenceModel);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_ZVAL(fields)
		Z_PARAM_STR(referenceModel)
		Z_PARAM_ZVAL(referencedFields)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 1, &fields, &referenceModel_param, &referencedFields, &options_param);
	if (UNEXPECTED(Z_TYPE_P(referenceModel_param) != IS_STRING && Z_TYPE_P(referenceModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceModel' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referenceModel_param) == IS_STRING)) {
		zephir_get_strval(&referenceModel, referenceModel_param);
	} else {
		ZEPHIR_INIT_VAR(&referenceModel);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addhasmany", NULL, 0, this_ptr, fields, &referenceModel, referencedFields, &options);
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
 * @param array $options = [
 *     'reusable' => false,
 *     'alias' => 'someAlias',
 *     'foreignKey' => [
 *         'message' => null,
 *         'allowNulls' => false,
 *         'action' => null
 *     ],
 *     'params' => [
 *         'conditions' => '',
 *         'columns' => '',
 *         'bind' => [],
 *         'bindTypes' => [],
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
	zval options;
	zval intermediateModel, referenceModel;
	zval *fields, fields_sub, *intermediateModel_param = NULL, *intermediateFields, intermediateFields_sub, *intermediateReferencedFields, intermediateReferencedFields_sub, *referenceModel_param = NULL, *referencedFields, referencedFields_sub, *options_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&intermediateFields_sub);
	ZVAL_UNDEF(&intermediateReferencedFields_sub);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&intermediateModel);
	ZVAL_UNDEF(&referenceModel);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(6, 7)
		Z_PARAM_ZVAL(fields)
		Z_PARAM_STR(intermediateModel)
		Z_PARAM_ZVAL(intermediateFields)
		Z_PARAM_ZVAL(intermediateReferencedFields)
		Z_PARAM_STR(referenceModel)
		Z_PARAM_ZVAL(referencedFields)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 6, 1, &fields, &intermediateModel_param, &intermediateFields, &intermediateReferencedFields, &referenceModel_param, &referencedFields, &options_param);
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
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addhasmanytomany", NULL, 0, this_ptr, fields, &intermediateModel, intermediateFields, intermediateReferencedFields, &referenceModel, referencedFields, &options);
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
 * @param array $options = [
 *     'reusable' => false,
 *     'alias' => 'someAlias',
 *     'foreignKey' => [
 *         'message' => null,
 *         'allowNulls' => false,
 *         'action' => null
 *     ],
 *     'params' => [
 *         'conditions' => '',
 *         'columns' => '',
 *         'bind' => [],
 *         'bindTypes' => [],
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
	zval options;
	zval referenceModel;
	zval *fields, fields_sub, *referenceModel_param = NULL, *referencedFields, referencedFields_sub, *options_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&referenceModel);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_ZVAL(fields)
		Z_PARAM_STR(referenceModel)
		Z_PARAM_ZVAL(referencedFields)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 1, &fields, &referenceModel_param, &referencedFields, &options_param);
	if (UNEXPECTED(Z_TYPE_P(referenceModel_param) != IS_STRING && Z_TYPE_P(referenceModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceModel' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referenceModel_param) == IS_STRING)) {
		zephir_get_strval(&referenceModel, referenceModel_param);
	} else {
		ZEPHIR_INIT_VAR(&referenceModel);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addhasone", NULL, 0, this_ptr, fields, &referenceModel, referencedFields, &options);
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
 * @param    string|array $fields
 * @param    string|array $intermediateFields
 * @param    string|array $intermediateReferencedFields
 * @param    string|array $referencedFields
 * @param    array $options
 */
PHP_METHOD(Phalcon_Mvc_Model, hasOneThrough)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval intermediateModel, referenceModel;
	zval *fields, fields_sub, *intermediateModel_param = NULL, *intermediateFields, intermediateFields_sub, *intermediateReferencedFields, intermediateReferencedFields_sub, *referenceModel_param = NULL, *referencedFields, referencedFields_sub, *options_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&intermediateFields_sub);
	ZVAL_UNDEF(&intermediateReferencedFields_sub);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&intermediateModel);
	ZVAL_UNDEF(&referenceModel);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(6, 7)
		Z_PARAM_ZVAL(fields)
		Z_PARAM_STR(intermediateModel)
		Z_PARAM_ZVAL(intermediateFields)
		Z_PARAM_ZVAL(intermediateReferencedFields)
		Z_PARAM_STR(referenceModel)
		Z_PARAM_ZVAL(referencedFields)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 6, 1, &fields, &intermediateModel_param, &intermediateFields, &intermediateReferencedFields, &referenceModel_param, &referencedFields, &options_param);
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
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addhasonethrough", NULL, 0, this_ptr, fields, &intermediateModel, intermediateFields, intermediateReferencedFields, &referenceModel, referencedFields, &options);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(keepSnapshot)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &keepSnapshot_param);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(schema)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(source)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &attributes_param);
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);
	ZEPHIR_INIT_VAR(&keysAttributes);
	array_init(&keysAttributes);
	zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model.zep", 5830);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &attributes_param);
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);
	ZEPHIR_INIT_VAR(&keysAttributes);
	array_init(&keysAttributes);
	zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model.zep", 5865);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(dynamicUpdate)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &dynamicUpdate_param);
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
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\ExclusionIn;
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
	zephir_fcall_cache_entry *_8 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validator, validator_sub, messages, message, _0, _2$$4, _3$$4, _4$$4, _5$$4, _6$$4, _7$$4;
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
	ZVAL_UNDEF(&_7$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(validator, phalcon_filter_validation_validationinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
		ZEPHIR_CALL_METHOD(&_7$$4, &message, "getmetadata", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", &_8, 6, &_3$$4, &_4$$4, &_5$$4, &_6$$4, &_7$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_9, 0, &_2$$4);
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
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\ExclusionIn;
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

	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&cmKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(columnMap)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &columnMap, &key);
	ZEPHIR_INIT_VAR(&_0);
	zephir_array_keys(&_0, columnMap);
	zephir_is_iterable(&_0, 0, "phalcon/Mvc/Model.zep", 6002);
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

/***
 * Append messages to this model from another Model.
 */
PHP_METHOD(Phalcon_Mvc_Model, appendMessagesFrom)
{
	zval _2$$5, _4$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, messages, message, *_0$$3, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$7);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(model)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &model);
	ZEPHIR_CALL_METHOD(&messages, model, "getmessages", NULL, 0);
	zephir_check_call_status();
	if (0 == ZEPHIR_IS_EMPTY(&messages)) {
		zephir_is_iterable(&messages, 0, "phalcon/Mvc/Model.zep", 6026);
		if (Z_TYPE_P(&messages) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&messages), _0$$3)
			{
				ZEPHIR_INIT_NVAR(&message);
				ZVAL_COPY(&message, _0$$3);
				if (Z_TYPE_P(&message) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_2$$5);
					zephir_create_array(&_2$$5, 1, 0);
					zephir_array_update_string(&_2$$5, SL("model"), model, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_2$$5);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_3, 0, &message);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &messages, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &messages, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&message, &messages, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&message) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_4$$7);
						zephir_create_array(&_4$$7, 1, 0);
						zephir_array_update_string(&_4$$7, SL("model"), model, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_4$$7);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_3, 0, &message);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &messages, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&message);
	}
	ZEPHIR_MM_RESTORE();
}

zend_object *zephir_init_properties_Phalcon_Mvc_Model(zend_class_entry *class_type)
{
		zval _0, _2, _4, _6, _8, _10, _12, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7, _11$$8, _13$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$9);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("uniqueTypes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("uniqueTypes"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("uniqueParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("uniqueParams"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("snapshot"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("snapshot"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("oldSnapshot"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("oldSnapshot"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("related"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("related"), &_9$$7);
		}
		zephir_read_property_ex(&_10, this_ptr, ZEND_STRL("errorMessages"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			array_init(&_11$$8);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("errorMessages"), &_11$$8);
		}
		zephir_read_property_ex(&_12, this_ptr, ZEND_STRL("dirtyRelated"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_12) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_13$$9);
			array_init(&_13$$9);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("dirtyRelated"), &_13$$9);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

