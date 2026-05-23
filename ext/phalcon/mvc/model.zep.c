
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
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"
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
 * @template T of static
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
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_ce, SL("rawValues"), ZEND_ACC_PROTECTED);
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
	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("DIRTY_STATE_DETACHED"), 2);

	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("DIRTY_STATE_PERSISTENT"), 0);

	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("DIRTY_STATE_TRANSIENT"), 1);

	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_CREATE"), 1);

	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_DELETE"), 3);

	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_NONE"), 0);

	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_UPDATE"), 2);

	/**
	 * @var string
	 */
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
	zval *data = NULL, data_sub, *container = NULL, container_sub, *modelsManager = NULL, modelsManager_sub, __$null, _0$$4, _1$$4, _2$$5, _3$$5, _4$$6, _5$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&modelsManager_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
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
		object_init_ex(&_0$$4, phalcon_mvc_model_exceptions_modelormservicesunavailable_ce);
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_get_class(&_1$$4, this_ptr, 0);
		ZEPHIR_CALL_METHOD(NULL, &_0$$4, "__construct", NULL, 0, &_1$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$4, "phalcon/Mvc/Model.zep", 238);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), container);
	if (Z_TYPE_P(modelsManager) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_3$$5);
		ZVAL_STRING(&_3$$5, "modelsManager");
		ZEPHIR_CALL_METHOD(&_2$$5, container, "getshared", NULL, 0, &_3$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(modelsManager, &_2$$5);
		if (Z_TYPE_P(modelsManager) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_4$$6);
			object_init_ex(&_4$$6, phalcon_mvc_model_exceptions_invalidmodelsmanagerservice_ce);
			ZEPHIR_INIT_VAR(&_5$$6);
			zephir_get_class(&_5$$6, this_ptr, 0);
			ZEPHIR_CALL_METHOD(NULL, &_4$$6, "__construct", NULL, 0, &_5$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_4$$6, "phalcon/Mvc/Model.zep", 249);
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
 * @throws \Phalcon\Mvc\Model\Exception If the method does not exist
 */
PHP_METHOD(Phalcon_Mvc_Model, __call)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval arguments;
	zval method_zv, *arguments_param = NULL, modelName, status, records, _1, _2;
	zend_string *method = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&arguments);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(method)
		ZEPHIR_Z_PARAM_ARRAY(arguments, arguments_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	arguments_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&method_zv);
	ZVAL_STR_COPY(&method_zv, method);
	zephir_get_arrval(&arguments, arguments_param);
	ZEPHIR_CALL_SELF(&records, "invokefinder", &_0, 0, &method_zv, &arguments);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&records)) {
		RETURN_CCTOR(&records);
	}
	ZEPHIR_INIT_VAR(&modelName);
	zephir_get_class(&modelName, this_ptr, 0);
	ZEPHIR_CALL_METHOD(&records, this_ptr, "getrelatedrecords", NULL, 0, &modelName, &method_zv, &arguments);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&records)) {
		RETURN_CCTOR(&records);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&status, &_1, "missingmethod", NULL, 0, this_ptr, &method_zv, &arguments);
	zephir_check_call_status();
	if (Z_TYPE_P(&status) != IS_NULL) {
		RETURN_CCTOR(&status);
	}
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, phalcon_mvc_model_exceptions_methodnotfound_ce);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 0, &method_zv, &modelName);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_2, "phalcon/Mvc/Model.zep", 316);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Handles method calls when a static method is not implemented
 *
 * @return mixed
 * @throws \Phalcon\Mvc\Model\Exception If the method does not exist
 */
PHP_METHOD(Phalcon_Mvc_Model, __callStatic)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval arguments;
	zval method_zv, *arguments_param = NULL, modelName, records, _1;
	zend_string *method = NULL;

	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&arguments);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(method)
		ZEPHIR_Z_PARAM_ARRAY(arguments, arguments_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	arguments_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&method_zv);
	ZVAL_STR_COPY(&method_zv, method);
	zephir_get_arrval(&arguments, arguments_param);
	ZEPHIR_CALL_SELF(&records, "invokefinder", &_0, 0, &method_zv, &arguments);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&records)) {
		RETURN_CCTOR(&records);
	}
	ZEPHIR_INIT_VAR(&modelName);
	zephir_get_called_class(&modelName);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalcon_mvc_model_exceptions_methodnotfound_ce);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0, &method_zv, &modelName);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_1, "phalcon/Mvc/Model.zep", 340);
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
	zend_bool _5$$3, _9$$5;
	zval method;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval property_zv, modelName, manager, lowerProperty, relation, _0, _14, _15, _16, _1$$3, _4$$3, _6$$3, _2$$4, _3$$4, _7$$5, _8$$5, _10$$5, _11$$5, _12$$6, _13$$6;
	zend_string *property = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property_zv);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&lowerProperty);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&method);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(property)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&property_zv);
	ZVAL_STR_COPY(&property_zv, property);
	ZEPHIR_INIT_VAR(&modelName);
	zephir_get_class(&modelName, this_ptr, 0);
	ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&lowerProperty);
	zephir_fast_strtolower(&lowerProperty, &property_zv);
	ZEPHIR_CALL_METHOD(&_0, &manager, "getrelationbyalias", NULL, 0, &modelName, &lowerProperty);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&relation, &_0);
	if (Z_TYPE_P(&relation) == IS_OBJECT) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("dirtyRelated"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_value(&_1$$3, &lowerProperty)) {
			zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("dirtyRelated"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_3$$4, &_2$$4, &lowerProperty, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 372);
			RETURN_CTOR(&_3$$4);
		}
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("related"), PH_NOISY_CC | PH_READONLY);
		_5$$3 = zephir_array_isset_value(&_4$$3, &lowerProperty);
		if (_5$$3) {
			ZEPHIR_CALL_METHOD(&_6$$3, &relation, "isreusable", NULL, 0);
			zephir_check_call_status();
			_5$$3 = !zephir_is_true(&_6$$3);
		}
		if (_5$$3) {
			zephir_read_property(&_7$$5, this_ptr, ZEND_STRL("related"), PH_NOISY_CC | PH_READONLY);
			zephir_memory_observe(&_8$$5);
			zephir_array_fetch(&_8$$5, &_7$$5, &lowerProperty, PH_NOISY, "phalcon/Mvc/Model.zep", 383);
			_9$$5 = Z_TYPE_P(&_8$$5) == IS_OBJECT;
			if (_9$$5) {
				zephir_read_property(&_10$$5, this_ptr, ZEND_STRL("related"), PH_NOISY_CC | PH_READONLY);
				zephir_memory_observe(&_11$$5);
				zephir_array_fetch(&_11$$5, &_10$$5, &lowerProperty, PH_NOISY, "phalcon/Mvc/Model.zep", 383);
				_9$$5 = zephir_instance_of_ev(&_11$$5, phalcon_mvc_modelinterface_ce);
			}
			if (_9$$5) {
				zephir_read_property(&_12$$6, this_ptr, ZEND_STRL("related"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_13$$6, &_12$$6, &lowerProperty, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 384);
				RETURN_CTOR(&_13$$6);
			}
		}
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrelated", NULL, 0, &lowerProperty);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_14);
	zephir_camelize(&_14, &property_zv, NULL );
	ZEPHIR_INIT_VAR(&_15);
	ZEPHIR_CONCAT_SV(&_15, "get", &_14);
	zephir_get_strval(&method, &_15);
	if ((zephir_method_exists(this_ptr, &method)  == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &method, NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_16);
	ZEPHIR_CONCAT_SVSV(&_16, "Access to undefined property ", &modelName, "::", &property_zv);
	ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 14, &_16);
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
	zval property_zv, manager, method, modelName, relation, result, _0, _1$$4;
	zend_string *property = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property_zv);
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
	zephir_memory_observe(&property_zv);
	ZVAL_STR_COPY(&property_zv, property);
	ZEPHIR_INIT_VAR(&modelName);
	zephir_get_class(&modelName, this_ptr, 0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&_0, &manager, "getrelationbyalias", NULL, 0, &modelName, &property_zv);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&relation, &_0);
	if (Z_TYPE_P(&relation) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&result);
		ZVAL_BOOL(&result, 1);
	} else {
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_camelize(&_1$$4, &property_zv, NULL );
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
	zval property_zv, *value, value_sub, __$null, lowerProperty, modelName, manager, relation, referencedModel, item, dirtyState, _17, _18, _1$$3, _2$$4, _3$$4, _4$$6, _5$$7, _6$$8, _7$$9, _8$$9, *_9$$10, _10$$10, _11$$10, _12$$17, _13$$18, _14$$19, _15$$20, _16$$20, _19$$22, _20$$23, _21$$23;
	zend_string *property = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property_zv);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&lowerProperty);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&referencedModel);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&dirtyState);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
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
	ZVAL_UNDEF(&_14$$19);
	ZVAL_UNDEF(&_15$$20);
	ZVAL_UNDEF(&_16$$20);
	ZVAL_UNDEF(&_19$$22);
	ZVAL_UNDEF(&_20$$23);
	ZVAL_UNDEF(&_21$$23);
	ZVAL_UNDEF(&related);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(property)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	value = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&property_zv);
	ZVAL_STR_COPY(&property_zv, property);
	_0 = Z_TYPE_P(value) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(value, phalcon_mvc_modelinterface_ce);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&lowerProperty);
		zephir_fast_strtolower(&lowerProperty, &property_zv);
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
		zephir_fast_strtolower(&lowerProperty, &property_zv);
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
					zephir_is_iterable(value, 0, "phalcon/Mvc/Model.zep", 556);
					if (Z_TYPE_P(value) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(value), _9$$10)
						{
							ZEPHIR_INIT_NVAR(&item);
							ZVAL_COPY(&item, _9$$10);
							if (Z_TYPE_P(&item) == IS_OBJECT) {
								if (zephir_instance_of_ev(&item, phalcon_mvc_modelinterface_ce)) {
									zephir_array_append(&related, &item, PH_SEPARATE, "phalcon/Mvc/Model.zep", 551);
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
										zephir_array_append(&related, &item, PH_SEPARATE, "phalcon/Mvc/Model.zep", 551);
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
	} else if (Z_TYPE_P(value) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&lowerProperty);
		zephir_fast_strtolower(&lowerProperty, &property_zv);
		ZEPHIR_INIT_NVAR(&modelName);
		zephir_get_class(&modelName, this_ptr, 0);
		ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_14$$19, &manager, "getrelationbyalias", NULL, 0, &modelName, &lowerProperty);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_14$$19);
		if (Z_TYPE_P(&relation) == IS_OBJECT) {
			zephir_unset_property_array(this_ptr, ZEND_STRL("related"), &lowerProperty);
			zephir_read_property(&_15$$20, this_ptr, ZEND_STRL("related"), PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_15$$20, &lowerProperty, PH_SEPARATE);
			zephir_unset_property_array(this_ptr, ZEND_STRL("dirtyRelated"), &lowerProperty);
			zephir_read_property(&_16$$20, this_ptr, ZEND_STRL("dirtyRelated"), PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_16$$20, &lowerProperty, PH_SEPARATE);
			zephir_update_property_zval_zval(this_ptr, &property_zv, &__$null);
		}
	}
	ZEPHIR_CALL_METHOD(&_17, this_ptr, "possiblesetter", NULL, 0, &property_zv, value);
	zephir_check_call_status();
	if (zephir_is_true(&_17)) {
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_18, "property_exists", NULL, 28, this_ptr, &property_zv);
	zephir_check_call_status();
	if (zephir_is_true(&_18)) {
		ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_19$$22, &manager, "isvisiblemodelproperty", NULL, 0, this_ptr, &property_zv);
		zephir_check_call_status();
		if (UNEXPECTED(!zephir_is_true(&_19$$22))) {
			ZEPHIR_INIT_VAR(&_20$$23);
			object_init_ex(&_20$$23, phalcon_mvc_model_exceptions_propertynotaccessible_ce);
			ZEPHIR_INIT_VAR(&_21$$23);
			zephir_get_class(&_21$$23, this_ptr, 0);
			ZEPHIR_CALL_METHOD(NULL, &_20$$23, "__construct", NULL, 0, &property_zv, &_21$$23);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_20$$23, "phalcon/Mvc/Model.zep", 610);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_update_property_zval_zval(this_ptr, &property_zv, value);
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();
}

/**
 * Unserializes an array to the model
 */
PHP_METHOD(Phalcon_Mvc_Model, __unserialize)
{
	zend_string *_9$$7;
	zend_ulong _8$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, container, manager, key, value, snapshot, properties, dirtyState, _3, _4, _0$$3, _1$$4, _2$$4, _5$$5, _6$$5, *_7$$7, _10$$7, _11$$13;
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
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$13);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &data_param);
	zephir_get_arrval(&data, data_param);
	if (!(zephir_array_isset_value_string(&data, SL("attributes")))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 1, 0);
		zephir_array_update_string(&_0$$3, SL("attributes"), &data, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&data, &_0$$3);
	}
	ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_di_ce, "getdefault", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_mvc_model_exceptions_modelormservicesunavailable_ce);
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_get_class(&_2$$4, this_ptr, 0);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 0, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/Model.zep", 637);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), &container);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "modelsManager");
	ZEPHIR_CALL_METHOD(&_3, &container, "getshared", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_3);
	if (Z_TYPE_P(&manager) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_5$$5);
		object_init_ex(&_5$$5, phalcon_mvc_model_exceptions_invalidmodelsmanagerservice_ce);
		ZEPHIR_INIT_VAR(&_6$$5);
		zephir_get_class(&_6$$5, this_ptr, 0);
		ZEPHIR_CALL_METHOD(NULL, &_5$$5, "__construct", NULL, 0, &_6$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$5, "phalcon/Mvc/Model.zep", 650);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("modelsManager"), &manager);
	ZEPHIR_CALL_METHOD(NULL, &manager, "initialize", NULL, 0, this_ptr);
	zephir_check_call_status();
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("onconstruct")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "onconstruct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_memory_observe(&properties);
	if (zephir_array_isset_string_fetch(&properties, &data, SL("attributes"), 0)) {
		zephir_is_iterable(&properties, 0, "phalcon/Mvc/Model.zep", 681);
		if (Z_TYPE_P(&properties) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&properties), _8$$7, _9$$7, _7$$7)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_9$$7 != NULL) { 
					ZVAL_STR_COPY(&key, _9$$7);
				} else {
					ZVAL_LONG(&key, _8$$7);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _7$$7);
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
	if (zephir_array_isset_string_fetch(&dirtyState, &data, SL("dirtyState"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("dirtyState"), &dirtyState);
	}
	ZEPHIR_CALL_METHOD(&_3, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		if (zephir_array_isset_string_fetch(&snapshot, &data, SL("snapshot"), 1)) {
			ZEPHIR_INIT_VAR(&_11$$13);
			if (Z_TYPE_P(&snapshot) != IS_NULL) {
				ZEPHIR_CPY_WRT(&_11$$13, &snapshot);
			} else {
				ZEPHIR_CPY_WRT(&_11$$13, &properties);
			}
			zephir_update_property_zval(this_ptr, ZEND_STRL("snapshot"), &_11$$13);
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
	zend_bool _8$$12, _19$$18, _20$$18, _24$$23, _32$$29, _33$$29;
	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_13 = NULL, *_18 = NULL, *_22 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *whiteList = NULL, whiteList_sub, *dataColumnMap = NULL, dataColumnMap_sub, __$null, key, keyMapped, value, attribute, attributeField, metaData, columnMap, disableAssignSetters, rawValues, _0, _5, _6, *_7, _23, *_1$$3, _4$$3, _9$$12, _11$$12, _12$$13, _14$$15, _15$$15, _16$$16, _17$$16, _21$$18, _25$$23, _26$$23, _27$$24, _28$$26, _29$$26, _30$$27, _31$$27, _34$$29;
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
	ZVAL_UNDEF(&rawValues);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_9$$12);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_14$$15);
	ZVAL_UNDEF(&_15$$15);
	ZVAL_UNDEF(&_16$$16);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&_21$$18);
	ZVAL_UNDEF(&_25$$23);
	ZVAL_UNDEF(&_26$$23);
	ZVAL_UNDEF(&_27$$24);
	ZVAL_UNDEF(&_28$$26);
	ZVAL_UNDEF(&_29$$26);
	ZVAL_UNDEF(&_30$$27);
	ZVAL_UNDEF(&_31$$27);
	ZVAL_UNDEF(&_34$$29);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
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
	ZEPHIR_INIT_VAR(&rawValues);
	array_init(&rawValues);
	zephir_update_property_zval(this_ptr, ZEND_STRL("rawValues"), &rawValues);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "orm.disable_assign_setters");
	ZEPHIR_CALL_CE_STATIC(&disableAssignSetters, phalcon_support_settings_ce, "get", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(dataColumnMap) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&dataMapped);
		array_init(&dataMapped);
		zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 846);
		if (Z_TYPE_P(&data) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _2$$3, _3$$3, _1$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _3$$3);
				} else {
					ZVAL_LONG(&key, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _1$$3);
				ZEPHIR_OBS_NVAR(&keyMapped);
				if (zephir_array_isset_fetch(&keyMapped, dataColumnMap, &key, 0)) {
					zephir_array_update_zval(&dataMapped, &keyMapped, &value, PH_COPY | PH_SEPARATE);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_4$$3, &data, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$3)) {
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
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "orm.column_renaming");
	ZEPHIR_CALL_CE_STATIC(&_5, phalcon_support_settings_ce, "get", NULL, 0, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_5)) {
		ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&columnMap);
		ZVAL_NULL(&columnMap);
	}
	ZEPHIR_CALL_METHOD(&_6, &metaData, "getattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(&_6, 0, "phalcon/Mvc/Model.zep", 903);
	if (Z_TYPE_P(&_6) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_6), _7)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _7);
			_8$$12 = !(zephir_array_isset_value(&columnMap, &attribute));
			if (_8$$12) {
				ZEPHIR_INIT_NVAR(&_11$$12);
				ZVAL_STRING(&_11$$12, "orm.case_insensitive_column_map");
				ZEPHIR_CALL_CE_STATIC(&_9$$12, phalcon_support_settings_ce, "get", &_10, 0, &_11$$12);
				zephir_check_call_status();
				_8$$12 = zephir_is_true(&_9$$12);
			}
			if (_8$$12) {
				ZEPHIR_CALL_SELF(&_12$$13, "caseinsensitivecolumnmap", &_13, 0, &columnMap, &attribute);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&attribute, &_12$$13);
			}
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0))) {
					ZEPHIR_INIT_NVAR(&_15$$15);
					ZVAL_STRING(&_15$$15, "orm.ignore_unknown_columns");
					ZEPHIR_CALL_CE_STATIC(&_14$$15, phalcon_support_settings_ce, "get", &_10, 0, &_15$$15);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&_14$$15))) {
						ZEPHIR_INIT_NVAR(&_16$$16);
						object_init_ex(&_16$$16, phalcon_mvc_model_exceptions_columnnotinmap_ce);
						ZEPHIR_INIT_NVAR(&_17$$16);
						zephir_get_class(&_17$$16, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_16$$16, "__construct", &_18, 0, &attribute, &_17$$16);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_16$$16, "phalcon/Mvc/Model.zep", 875);
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
				_19$$18 = Z_TYPE_P(&value) == IS_OBJECT;
				if (_19$$18) {
					_19$$18 = zephir_instance_of_ev(&value, phalcon_db_rawvalue_ce);
				}
				_20$$18 = zephir_is_true(&disableAssignSetters);
				if (!(_20$$18)) {
					ZEPHIR_CALL_METHOD(&_21$$18, this_ptr, "possiblesetter", &_22, 0, &attributeField, &value);
					zephir_check_call_status();
					_20$$18 = !zephir_is_true(&_21$$18);
				}
				if (_19$$18) {
					zephir_array_update_zval(&rawValues, &attributeField, &value, PH_COPY | PH_SEPARATE);
				} else if (_20$$18) {
					zephir_update_property_zval_zval(this_ptr, &attributeField, &value);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_6, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_23, &_6, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_23)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attribute, &_6, "current", NULL, 0);
			zephir_check_call_status();
				_24$$23 = !(zephir_array_isset_value(&columnMap, &attribute));
				if (_24$$23) {
					ZEPHIR_INIT_NVAR(&_26$$23);
					ZVAL_STRING(&_26$$23, "orm.case_insensitive_column_map");
					ZEPHIR_CALL_CE_STATIC(&_25$$23, phalcon_support_settings_ce, "get", &_10, 0, &_26$$23);
					zephir_check_call_status();
					_24$$23 = zephir_is_true(&_25$$23);
				}
				if (_24$$23) {
					ZEPHIR_CALL_SELF(&_27$$24, "caseinsensitivecolumnmap", &_13, 0, &columnMap, &attribute);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&attribute, &_27$$24);
				}
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0))) {
						ZEPHIR_INIT_NVAR(&_29$$26);
						ZVAL_STRING(&_29$$26, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_28$$26, phalcon_support_settings_ce, "get", &_10, 0, &_29$$26);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_28$$26))) {
							ZEPHIR_INIT_NVAR(&_30$$27);
							object_init_ex(&_30$$27, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							ZEPHIR_INIT_NVAR(&_31$$27);
							zephir_get_class(&_31$$27, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_30$$27, "__construct", &_18, 0, &attribute, &_31$$27);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_30$$27, "phalcon/Mvc/Model.zep", 875);
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
					_32$$29 = Z_TYPE_P(&value) == IS_OBJECT;
					if (_32$$29) {
						_32$$29 = zephir_instance_of_ev(&value, phalcon_db_rawvalue_ce);
					}
					_33$$29 = zephir_is_true(&disableAssignSetters);
					if (!(_33$$29)) {
						ZEPHIR_CALL_METHOD(&_34$$29, this_ptr, "possiblesetter", &_22, 0, &attributeField, &value);
						zephir_check_call_status();
						_33$$29 = !zephir_is_true(&_34$$29);
					}
					if (_32$$29) {
						zephir_array_update_zval(&rawValues, &attributeField, &value, PH_COPY | PH_SEPARATE);
					} else if (_33$$29) {
						zephir_update_property_zval_zval(this_ptr, &attributeField, &value);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &_6, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&attribute);
	zephir_update_property_zval(this_ptr, ZEND_STRL("rawValues"), &rawValues);
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
		ZEPHIR_Z_PARAM_ARRAY(parameters, parameters_param)
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
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long dirtyState, ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *base, base_sub, *data_param = NULL, *dirtyState_param = NULL, instance, key, value, _0, *_1, _7, _10, _4$$4, _5$$4, _8$$6, _9$$6;

	ZVAL_UNDEF(&base_sub);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&data);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_OBJECT_OF_CLASS(base, phalcon_mvc_modelinterface_ce)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
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
	zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 993);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _2, _3, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			if (UNEXPECTED(Z_TYPE_P(&key) != IS_STRING)) {
				ZEPHIR_INIT_NVAR(&_4$$4);
				object_init_ex(&_4$$4, phalcon_mvc_model_exceptions_invaliddumpresultkey_ce);
				ZEPHIR_INIT_NVAR(&_5$$4);
				zephir_get_class(&_5$$4, base, 0);
				ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", &_6, 0, &_5$$4);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_4$$4, "phalcon/Mvc/Model.zep", 983);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_update_property_zval_zval(&instance, &key, &value);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_7, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&key) != IS_STRING)) {
					ZEPHIR_INIT_NVAR(&_8$$6);
					object_init_ex(&_8$$6, phalcon_mvc_model_exceptions_invaliddumpresultkey_ce);
					ZEPHIR_INIT_NVAR(&_9$$6);
					zephir_get_class(&_9$$6, base, 0);
					ZEPHIR_CALL_METHOD(NULL, &_8$$6, "__construct", &_6, 0, &_9$$6);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_8$$6, "phalcon/Mvc/Model.zep", 983);
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
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_STRING(&_10, "afterFetch");
	ZEPHIR_CALL_METHOD(NULL, &instance, "fireevent", NULL, 0, &_10);
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
	zend_string *_5;
	zend_ulong _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL, *_17 = NULL, *_29 = NULL;
	zend_bool keepSnapshots, disableSetters = 0, _6$$5, _26$$5, _8$$9, _11$$13, _23$$21, _32$$33, _36$$37, _54$$37, _38$$41, _41$$45, _51$$53, _59$$65;
	zend_long dirtyState, ZEPHIR_LAST_CALL_STATUS;
	zval data, localMethods;
	zval *base, base_sub, *data_param = NULL, *columnMap, columnMap_sub, *dirtyState_param = NULL, *keepSnapshots_param = NULL, instance, attribute, key, value, castValue, attributeName, metaData, reverseMap, notNullAttributes, setter, _0, _1, _2, *_3, _35, _7$$9, _9$$10, _10$$10, _12$$16, _14$$16, _15$$17, _16$$17, _18$$18, _19$$18, _20$$19, _21$$19, _22$$21, _24$$22, _25$$22, _27$$25, _28$$26, _30$$30, _31$$33, _33$$34, _34$$34, _37$$41, _39$$42, _40$$42, _42$$48, _43$$48, _44$$49, _45$$49, _46$$50, _47$$50, _48$$51, _49$$51, _50$$53, _52$$54, _53$$54, _55$$57, _56$$58, _57$$62, _58$$65, _60$$66, _61$$66, _62$$70;

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
	ZVAL_UNDEF(&notNullAttributes);
	ZVAL_UNDEF(&setter);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_12$$16);
	ZVAL_UNDEF(&_14$$16);
	ZVAL_UNDEF(&_15$$17);
	ZVAL_UNDEF(&_16$$17);
	ZVAL_UNDEF(&_18$$18);
	ZVAL_UNDEF(&_19$$18);
	ZVAL_UNDEF(&_20$$19);
	ZVAL_UNDEF(&_21$$19);
	ZVAL_UNDEF(&_22$$21);
	ZVAL_UNDEF(&_24$$22);
	ZVAL_UNDEF(&_25$$22);
	ZVAL_UNDEF(&_27$$25);
	ZVAL_UNDEF(&_28$$26);
	ZVAL_UNDEF(&_30$$30);
	ZVAL_UNDEF(&_31$$33);
	ZVAL_UNDEF(&_33$$34);
	ZVAL_UNDEF(&_34$$34);
	ZVAL_UNDEF(&_37$$41);
	ZVAL_UNDEF(&_39$$42);
	ZVAL_UNDEF(&_40$$42);
	ZVAL_UNDEF(&_42$$48);
	ZVAL_UNDEF(&_43$$48);
	ZVAL_UNDEF(&_44$$49);
	ZVAL_UNDEF(&_45$$49);
	ZVAL_UNDEF(&_46$$50);
	ZVAL_UNDEF(&_47$$50);
	ZVAL_UNDEF(&_48$$51);
	ZVAL_UNDEF(&_49$$51);
	ZVAL_UNDEF(&_50$$53);
	ZVAL_UNDEF(&_52$$54);
	ZVAL_UNDEF(&_53$$54);
	ZVAL_UNDEF(&_55$$57);
	ZVAL_UNDEF(&_56$$58);
	ZVAL_UNDEF(&_57$$62);
	ZVAL_UNDEF(&_58$$65);
	ZVAL_UNDEF(&_60$$66);
	ZVAL_UNDEF(&_61$$66);
	ZVAL_UNDEF(&_62$$70);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&localMethods);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 5)
		Z_PARAM_ZVAL(base)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
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
	if (zephir_instance_of_ev(&instance, phalcon_mvc_model_ce)) {
		ZEPHIR_CALL_METHOD(&metaData, &instance, "getmodelsmetadata", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&notNullAttributes, &metaData, "getnotnullattributes", NULL, 0, &instance);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&metaData);
		ZVAL_NULL(&metaData);
		ZEPHIR_INIT_NVAR(&notNullAttributes);
		array_init(&notNullAttributes);
	}
	ZVAL_LONG(&_0, dirtyState);
	ZEPHIR_CALL_METHOD(NULL, &instance, "setdirtystate", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "orm.disable_assign_setters");
	ZEPHIR_CALL_CE_STATIC(&_1, phalcon_support_settings_ce, "get", NULL, 0, &_2);
	zephir_check_call_status();
	disableSetters = zephir_get_boolval(&_1);
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
	zephir_is_iterable(&data, 1, "phalcon/Mvc/Model.zep", 1189);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _4, _5, _3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&key, _5);
			} else {
				ZVAL_LONG(&key, _4);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _3);
			if (Z_TYPE_P(&key) != IS_STRING) {
				continue;
			}
			_6$$5 = Z_TYPE_P(&value) == IS_NULL;
			if (_6$$5) {
				_6$$5 = zephir_fast_in_array(&key, &notNullAttributes);
			}
			if (_6$$5) {
				continue;
			}
			if (Z_TYPE_P(columnMap) != IS_ARRAY) {
				if (!(disableSetters)) {
					ZEPHIR_INIT_NVAR(&_7$$9);
					zephir_camelize(&_7$$9, &key, NULL );
					ZEPHIR_INIT_NVAR(&setter);
					ZEPHIR_CONCAT_SV(&setter, "set", &_7$$9);
					_8$$9 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
					if (_8$$9) {
						_8$$9 = !(zephir_array_isset_value(&localMethods, &setter));
					}
					if (_8$$9) {

						/* try_start_1: */

							ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &value);
							zephir_check_call_status_or_jump(try_end_1);

						try_end_1:

						if (EG(exception)) {
							ZEPHIR_INIT_NVAR(&_9$$10);
							ZVAL_OBJ(&_9$$10, EG(exception));
							Z_ADDREF_P(&_9$$10);
							ZEPHIR_INIT_NVAR(&_10$$10);
							if (zephir_is_instance_of(&_9$$10, SL("TypeError"))) {
								zend_clear_exception();
								ZEPHIR_CPY_WRT(&_10$$10, &_9$$10);
								zephir_update_property_zval_zval(&instance, &key, &value);
							}
						}
						continue;
					}
				}
				zephir_update_property_zval_zval(&instance, &key, &value);
				continue;
			}
			ZEPHIR_OBS_NVAR(&attribute);
			if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0))) {
				_11$$13 = Z_TYPE_P(columnMap) == IS_ARRAY;
				if (_11$$13) {
					_11$$13 = !(ZEPHIR_IS_EMPTY(columnMap));
				}
				if (_11$$13) {
					if (Z_TYPE_P(&metaData) == IS_NULL) {
						ZEPHIR_CALL_METHOD(&metaData, &instance, "getmodelsmetadata", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&reverseMap, &metaData, "getreversecolumnmap", NULL, 0, &instance);
					zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&attribute);
					if (!(zephir_array_isset_fetch(&attribute, &reverseMap, &key, 0))) {
						ZEPHIR_INIT_NVAR(&_14$$16);
						ZVAL_STRING(&_14$$16, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_12$$16, phalcon_support_settings_ce, "get", &_13, 0, &_14$$16);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_12$$16))) {
							ZEPHIR_INIT_NVAR(&_15$$17);
							object_init_ex(&_15$$17, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							ZEPHIR_INIT_NVAR(&_16$$17);
							zephir_get_class(&_16$$17, base, 0);
							ZEPHIR_CALL_METHOD(NULL, &_15$$17, "__construct", &_17, 0, &key, &_16$$17);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_15$$17, "phalcon/Mvc/Model.zep", 1093);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
				} else {
					ZEPHIR_INIT_NVAR(&_19$$18);
					ZVAL_STRING(&_19$$18, "orm.ignore_unknown_columns");
					ZEPHIR_CALL_CE_STATIC(&_18$$18, phalcon_support_settings_ce, "get", &_13, 0, &_19$$18);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&_18$$18))) {
						ZEPHIR_INIT_NVAR(&_20$$19);
						object_init_ex(&_20$$19, phalcon_mvc_model_exceptions_columnnotinmap_ce);
						ZEPHIR_INIT_NVAR(&_21$$19);
						zephir_get_class(&_21$$19, base, 0);
						ZEPHIR_CALL_METHOD(NULL, &_20$$19, "__construct", &_17, 0, &key, &_21$$19);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_20$$19, "phalcon/Mvc/Model.zep", 1100);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
			}
			if (Z_TYPE_P(&attribute) != IS_ARRAY) {
				if (!(disableSetters)) {
					ZEPHIR_INIT_NVAR(&_22$$21);
					zephir_camelize(&_22$$21, &attribute, NULL );
					ZEPHIR_INIT_NVAR(&setter);
					ZEPHIR_CONCAT_SV(&setter, "set", &_22$$21);
					_23$$21 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
					if (_23$$21) {
						_23$$21 = !(zephir_array_isset_value(&localMethods, &setter));
					}
					if (_23$$21) {

						/* try_start_2: */

							ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &value);
							zephir_check_call_status_or_jump(try_end_2);

						try_end_2:

						if (EG(exception)) {
							ZEPHIR_INIT_NVAR(&_24$$22);
							ZVAL_OBJ(&_24$$22, EG(exception));
							Z_ADDREF_P(&_24$$22);
							ZEPHIR_INIT_NVAR(&_25$$22);
							if (zephir_is_instance_of(&_24$$22, SL("TypeError"))) {
								zend_clear_exception();
								ZEPHIR_CPY_WRT(&_25$$22, &_24$$22);
								zephir_update_property_zval_zval(&instance, &attribute, &value);
							}
						}
						continue;
					}
				}
				zephir_update_property_zval_zval(&instance, &attribute, &value);
				continue;
			}
			_26$$5 = !ZEPHIR_IS_STRING(&value, "");
			if (_26$$5) {
				_26$$5 = Z_TYPE_P(&value) != IS_NULL;
			}
			if (_26$$5) {
				zephir_array_fetch_long(&_27$$25, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 1126);
				do {
					if (ZEPHIR_IS_LONG(&_27$$25, 0) || ZEPHIR_IS_LONG(&_27$$25, 21) || ZEPHIR_IS_LONG(&_27$$25, 22) || ZEPHIR_IS_LONG(&_27$$25, 26)) {
						ZVAL_LONG(&_28$$26, 10);
						ZEPHIR_CALL_FUNCTION(&castValue, "intval", &_29, 77, &value, &_28$$26);
						zephir_check_call_status();
						break;
					}
					if (ZEPHIR_IS_LONG(&_27$$25, 3) || ZEPHIR_IS_LONG(&_27$$25, 9) || ZEPHIR_IS_LONG(&_27$$25, 7)) {
						ZEPHIR_INIT_NVAR(&castValue);
						ZVAL_DOUBLE(&castValue, zephir_get_doubleval(&value));
						break;
					}
					if (ZEPHIR_IS_LONG(&_27$$25, 8)) {
						ZEPHIR_INIT_NVAR(&castValue);
						ZVAL_BOOL(&castValue, zephir_get_boolval(&value));
						break;
					}
					ZEPHIR_CPY_WRT(&castValue, &value);
					break;
				} while(0);

			} else {
				zephir_array_fetch_long(&_30$$30, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 1149);
				do {
					if (ZEPHIR_IS_LONG(&_30$$30, 14) || ZEPHIR_IS_LONG(&_30$$30, 8) || ZEPHIR_IS_LONG(&_30$$30, 3) || ZEPHIR_IS_LONG(&_30$$30, 9) || ZEPHIR_IS_LONG(&_30$$30, 7) || ZEPHIR_IS_LONG(&_30$$30, 0) || ZEPHIR_IS_LONG(&_30$$30, 21) || ZEPHIR_IS_LONG(&_30$$30, 22) || ZEPHIR_IS_LONG(&_30$$30, 26)) {
						ZEPHIR_INIT_NVAR(&castValue);
						ZVAL_NULL(&castValue);
						break;
					}
					ZEPHIR_CPY_WRT(&castValue, &value);
					break;
				} while(0);

			}
			ZEPHIR_OBS_NVAR(&attributeName);
			zephir_array_fetch_long(&attributeName, &attribute, 0, PH_NOISY, "phalcon/Mvc/Model.zep", 1168);
			zephir_array_update_zval(&data, &key, &castValue, PH_COPY | PH_SEPARATE);
			if (!(disableSetters)) {
				ZEPHIR_INIT_NVAR(&_31$$33);
				zephir_camelize(&_31$$33, &attributeName, NULL );
				ZEPHIR_INIT_NVAR(&setter);
				ZEPHIR_CONCAT_SV(&setter, "set", &_31$$33);
				_32$$33 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
				if (_32$$33) {
					_32$$33 = !(zephir_array_isset_value(&localMethods, &setter));
				}
				if (_32$$33) {

					/* try_start_3: */

						ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &castValue);
						zephir_check_call_status_or_jump(try_end_3);

					try_end_3:

					if (EG(exception)) {
						ZEPHIR_INIT_NVAR(&_33$$34);
						ZVAL_OBJ(&_33$$34, EG(exception));
						Z_ADDREF_P(&_33$$34);
						ZEPHIR_INIT_NVAR(&_34$$34);
						if (zephir_is_instance_of(&_33$$34, SL("TypeError"))) {
							zend_clear_exception();
							ZEPHIR_CPY_WRT(&_34$$34, &_33$$34);
							zephir_update_property_zval_zval(&instance, &attributeName, &castValue);
						}
					}
					continue;
				}
			}
			zephir_update_property_zval_zval(&instance, &attributeName, &castValue);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_35, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_35)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&key) != IS_STRING) {
					continue;
				}
				_36$$37 = Z_TYPE_P(&value) == IS_NULL;
				if (_36$$37) {
					_36$$37 = zephir_fast_in_array(&key, &notNullAttributes);
				}
				if (_36$$37) {
					continue;
				}
				if (Z_TYPE_P(columnMap) != IS_ARRAY) {
					if (!(disableSetters)) {
						ZEPHIR_INIT_NVAR(&_37$$41);
						zephir_camelize(&_37$$41, &key, NULL );
						ZEPHIR_INIT_NVAR(&setter);
						ZEPHIR_CONCAT_SV(&setter, "set", &_37$$41);
						_38$$41 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
						if (_38$$41) {
							_38$$41 = !(zephir_array_isset_value(&localMethods, &setter));
						}
						if (_38$$41) {

							/* try_start_4: */

								ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &value);
								zephir_check_call_status_or_jump(try_end_4);

							try_end_4:

							if (EG(exception)) {
								ZEPHIR_INIT_NVAR(&_39$$42);
								ZVAL_OBJ(&_39$$42, EG(exception));
								Z_ADDREF_P(&_39$$42);
								ZEPHIR_INIT_NVAR(&_40$$42);
								if (zephir_is_instance_of(&_39$$42, SL("TypeError"))) {
									zend_clear_exception();
									ZEPHIR_CPY_WRT(&_40$$42, &_39$$42);
									zephir_update_property_zval_zval(&instance, &key, &value);
								}
							}
							continue;
						}
					}
					zephir_update_property_zval_zval(&instance, &key, &value);
					continue;
				}
				ZEPHIR_OBS_NVAR(&attribute);
				if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0))) {
					_41$$45 = Z_TYPE_P(columnMap) == IS_ARRAY;
					if (_41$$45) {
						_41$$45 = !(ZEPHIR_IS_EMPTY(columnMap));
					}
					if (_41$$45) {
						if (Z_TYPE_P(&metaData) == IS_NULL) {
							ZEPHIR_CALL_METHOD(&metaData, &instance, "getmodelsmetadata", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&reverseMap, &metaData, "getreversecolumnmap", NULL, 0, &instance);
						zephir_check_call_status();
						ZEPHIR_OBS_NVAR(&attribute);
						if (!(zephir_array_isset_fetch(&attribute, &reverseMap, &key, 0))) {
							ZEPHIR_INIT_NVAR(&_43$$48);
							ZVAL_STRING(&_43$$48, "orm.ignore_unknown_columns");
							ZEPHIR_CALL_CE_STATIC(&_42$$48, phalcon_support_settings_ce, "get", &_13, 0, &_43$$48);
							zephir_check_call_status();
							if (UNEXPECTED(!zephir_is_true(&_42$$48))) {
								ZEPHIR_INIT_NVAR(&_44$$49);
								object_init_ex(&_44$$49, phalcon_mvc_model_exceptions_columnnotinmap_ce);
								ZEPHIR_INIT_NVAR(&_45$$49);
								zephir_get_class(&_45$$49, base, 0);
								ZEPHIR_CALL_METHOD(NULL, &_44$$49, "__construct", &_17, 0, &key, &_45$$49);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_44$$49, "phalcon/Mvc/Model.zep", 1093);
								ZEPHIR_MM_RESTORE();
								return;
							}
							continue;
						}
					} else {
						ZEPHIR_INIT_NVAR(&_47$$50);
						ZVAL_STRING(&_47$$50, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_46$$50, phalcon_support_settings_ce, "get", &_13, 0, &_47$$50);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_46$$50))) {
							ZEPHIR_INIT_NVAR(&_48$$51);
							object_init_ex(&_48$$51, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							ZEPHIR_INIT_NVAR(&_49$$51);
							zephir_get_class(&_49$$51, base, 0);
							ZEPHIR_CALL_METHOD(NULL, &_48$$51, "__construct", &_17, 0, &key, &_49$$51);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_48$$51, "phalcon/Mvc/Model.zep", 1100);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
				}
				if (Z_TYPE_P(&attribute) != IS_ARRAY) {
					if (!(disableSetters)) {
						ZEPHIR_INIT_NVAR(&_50$$53);
						zephir_camelize(&_50$$53, &attribute, NULL );
						ZEPHIR_INIT_NVAR(&setter);
						ZEPHIR_CONCAT_SV(&setter, "set", &_50$$53);
						_51$$53 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
						if (_51$$53) {
							_51$$53 = !(zephir_array_isset_value(&localMethods, &setter));
						}
						if (_51$$53) {

							/* try_start_5: */

								ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &value);
								zephir_check_call_status_or_jump(try_end_5);

							try_end_5:

							if (EG(exception)) {
								ZEPHIR_INIT_NVAR(&_52$$54);
								ZVAL_OBJ(&_52$$54, EG(exception));
								Z_ADDREF_P(&_52$$54);
								ZEPHIR_INIT_NVAR(&_53$$54);
								if (zephir_is_instance_of(&_52$$54, SL("TypeError"))) {
									zend_clear_exception();
									ZEPHIR_CPY_WRT(&_53$$54, &_52$$54);
									zephir_update_property_zval_zval(&instance, &attribute, &value);
								}
							}
							continue;
						}
					}
					zephir_update_property_zval_zval(&instance, &attribute, &value);
					continue;
				}
				_54$$37 = !ZEPHIR_IS_STRING(&value, "");
				if (_54$$37) {
					_54$$37 = Z_TYPE_P(&value) != IS_NULL;
				}
				if (_54$$37) {
					zephir_array_fetch_long(&_55$$57, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 1126);
					do {
						if (ZEPHIR_IS_LONG(&_55$$57, 0) || ZEPHIR_IS_LONG(&_55$$57, 21) || ZEPHIR_IS_LONG(&_55$$57, 22) || ZEPHIR_IS_LONG(&_55$$57, 26)) {
							ZVAL_LONG(&_56$$58, 10);
							ZEPHIR_CALL_FUNCTION(&castValue, "intval", &_29, 77, &value, &_56$$58);
							zephir_check_call_status();
							break;
						}
						if (ZEPHIR_IS_LONG(&_55$$57, 3) || ZEPHIR_IS_LONG(&_55$$57, 9) || ZEPHIR_IS_LONG(&_55$$57, 7)) {
							ZEPHIR_INIT_NVAR(&castValue);
							ZVAL_DOUBLE(&castValue, zephir_get_doubleval(&value));
							break;
						}
						if (ZEPHIR_IS_LONG(&_55$$57, 8)) {
							ZEPHIR_INIT_NVAR(&castValue);
							ZVAL_BOOL(&castValue, zephir_get_boolval(&value));
							break;
						}
						ZEPHIR_CPY_WRT(&castValue, &value);
						break;
					} while(0);

				} else {
					zephir_array_fetch_long(&_57$$62, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 1149);
					do {
						if (ZEPHIR_IS_LONG(&_57$$62, 14) || ZEPHIR_IS_LONG(&_57$$62, 8) || ZEPHIR_IS_LONG(&_57$$62, 3) || ZEPHIR_IS_LONG(&_57$$62, 9) || ZEPHIR_IS_LONG(&_57$$62, 7) || ZEPHIR_IS_LONG(&_57$$62, 0) || ZEPHIR_IS_LONG(&_57$$62, 21) || ZEPHIR_IS_LONG(&_57$$62, 22) || ZEPHIR_IS_LONG(&_57$$62, 26)) {
							ZEPHIR_INIT_NVAR(&castValue);
							ZVAL_NULL(&castValue);
							break;
						}
						ZEPHIR_CPY_WRT(&castValue, &value);
						break;
					} while(0);

				}
				ZEPHIR_OBS_NVAR(&attributeName);
				zephir_array_fetch_long(&attributeName, &attribute, 0, PH_NOISY, "phalcon/Mvc/Model.zep", 1168);
				zephir_array_update_zval(&data, &key, &castValue, PH_COPY | PH_SEPARATE);
				if (!(disableSetters)) {
					ZEPHIR_INIT_NVAR(&_58$$65);
					zephir_camelize(&_58$$65, &attributeName, NULL );
					ZEPHIR_INIT_NVAR(&setter);
					ZEPHIR_CONCAT_SV(&setter, "set", &_58$$65);
					_59$$65 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
					if (_59$$65) {
						_59$$65 = !(zephir_array_isset_value(&localMethods, &setter));
					}
					if (_59$$65) {

						/* try_start_6: */

							ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &castValue);
							zephir_check_call_status_or_jump(try_end_6);

						try_end_6:

						if (EG(exception)) {
							ZEPHIR_INIT_NVAR(&_60$$66);
							ZVAL_OBJ(&_60$$66, EG(exception));
							Z_ADDREF_P(&_60$$66);
							ZEPHIR_INIT_NVAR(&_61$$66);
							if (zephir_is_instance_of(&_60$$66, SL("TypeError"))) {
								zend_clear_exception();
								ZEPHIR_CPY_WRT(&_61$$66, &_60$$66);
								zephir_update_property_zval_zval(&instance, &attributeName, &castValue);
							}
						}
						continue;
					}
				}
				zephir_update_property_zval_zval(&instance, &attributeName, &castValue);
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
		ZEPHIR_INIT_VAR(&_62$$70);
		ZVAL_STRING(&_62$$70, "afterFetch");
		ZEPHIR_CALL_METHOD(NULL, &instance, "fireevent", NULL, 0, &_62$$70);
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
	zend_bool _3$$7, _15$$16;
	zend_string *_2;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL, *_13 = NULL;
	zend_long hydrationMode, ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *columnMap, columnMap_sub, *hydrationMode_param = NULL, key, value, attribute, attributeName, *_0, _14, _4$$7, _6$$7, _7$$8, _9$$9, _10$$9, _11$$10, _12$$10, _16$$16, _17$$16, _18$$17, _19$$18, _20$$18, _21$$19, _22$$19;
	zval data, hydrateArray;

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&hydrateArray);
	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&attributeName);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_16$$16);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&_18$$17);
	ZVAL_UNDEF(&_19$$18);
	ZVAL_UNDEF(&_20$$18);
	ZVAL_UNDEF(&_21$$19);
	ZVAL_UNDEF(&_22$$19);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
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
	zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 1271);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&key, _2);
			} else {
				ZVAL_LONG(&key, _1);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			if (Z_TYPE_P(&key) != IS_STRING) {
				continue;
			}
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				_3$$7 = !(zephir_array_isset_value(columnMap, &key));
				if (_3$$7) {
					ZEPHIR_INIT_NVAR(&_6$$7);
					ZVAL_STRING(&_6$$7, "orm.case_insensitive_column_map");
					ZEPHIR_CALL_CE_STATIC(&_4$$7, phalcon_support_settings_ce, "get", &_5, 0, &_6$$7);
					zephir_check_call_status();
					_3$$7 = zephir_is_true(&_4$$7);
				}
				if (_3$$7) {
					ZEPHIR_CALL_SELF(&_7$$8, "caseinsensitivecolumnmap", &_8, 0, columnMap, &key);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&key, &_7$$8);
				}
				ZEPHIR_OBS_NVAR(&attribute);
				if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0))) {
					ZEPHIR_INIT_NVAR(&_10$$9);
					ZVAL_STRING(&_10$$9, "orm.ignore_unknown_columns");
					ZEPHIR_CALL_CE_STATIC(&_9$$9, phalcon_support_settings_ce, "get", &_5, 0, &_10$$9);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&_9$$9))) {
						ZEPHIR_INIT_NVAR(&_11$$10);
						object_init_ex(&_11$$10, phalcon_mvc_model_exceptions_columnnotinmap_ce);
						ZEPHIR_INIT_NVAR(&_12$$10);
						zephir_get_called_class(&_12$$10);
						ZEPHIR_CALL_METHOD(NULL, &_11$$10, "__construct", &_13, 0, &key, &_12$$10);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_11$$10, "phalcon/Mvc/Model.zep", 1250);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
				if (Z_TYPE_P(&attribute) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeName);
					zephir_array_fetch_long(&attributeName, &attribute, 0, PH_NOISY, "phalcon/Mvc/Model.zep", 1260);
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
			ZEPHIR_CALL_METHOD(&_14, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_14)) {
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
					_15$$16 = !(zephir_array_isset_value(columnMap, &key));
					if (_15$$16) {
						ZEPHIR_INIT_NVAR(&_17$$16);
						ZVAL_STRING(&_17$$16, "orm.case_insensitive_column_map");
						ZEPHIR_CALL_CE_STATIC(&_16$$16, phalcon_support_settings_ce, "get", &_5, 0, &_17$$16);
						zephir_check_call_status();
						_15$$16 = zephir_is_true(&_16$$16);
					}
					if (_15$$16) {
						ZEPHIR_CALL_SELF(&_18$$17, "caseinsensitivecolumnmap", &_8, 0, columnMap, &key);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&key, &_18$$17);
					}
					ZEPHIR_OBS_NVAR(&attribute);
					if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0))) {
						ZEPHIR_INIT_NVAR(&_20$$18);
						ZVAL_STRING(&_20$$18, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_19$$18, phalcon_support_settings_ce, "get", &_5, 0, &_20$$18);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_19$$18))) {
							ZEPHIR_INIT_NVAR(&_21$$19);
							object_init_ex(&_21$$19, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							ZEPHIR_INIT_NVAR(&_22$$19);
							zephir_get_called_class(&_22$$19);
							ZEPHIR_CALL_METHOD(NULL, &_21$$19, "__construct", &_13, 0, &key, &_22$$19);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_21$$19, "phalcon/Mvc/Model.zep", 1250);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
					if (Z_TYPE_P(&attribute) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeName);
						zephir_array_fetch_long(&attributeName, &attribute, 0, PH_NOISY, "phalcon/Mvc/Model.zep", 1260);
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
	zend_bool _5$$3, _7$$3;
	zend_string *_4;
	zend_ulong _3;
	zval related, dirtyRelated;
	zval name, record, _0, _1, *_2, _6$$3, _8$$3, _9$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&related);
	ZVAL_UNDEF(&dirtyRelated);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("related"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&related, &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("dirtyRelated"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dirtyRelated, &_1);
	zephir_is_iterable(&related, 0, "phalcon/Mvc/Model.zep", 1316);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&related), _3, _4, _2)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_4 != NULL) { 
			ZVAL_STR_COPY(&name, _4);
		} else {
			ZVAL_LONG(&name, _3);
		}
		ZEPHIR_INIT_NVAR(&record);
		ZVAL_COPY(&record, _2);
		if (zephir_array_isset_value(&dirtyRelated, &name)) {
			continue;
		}
		_5$$3 = Z_TYPE_P(&record) != IS_OBJECT;
		if (!(_5$$3)) {
			_5$$3 = !((zephir_instance_of_ev(&record, phalcon_mvc_modelinterface_ce)));
		}
		if (_5$$3) {
			continue;
		}
		ZEPHIR_CALL_METHOD(&_6$$3, &record, "hassnapshotdata", NULL, 0);
		zephir_check_call_status();
		_7$$3 = zephir_is_true(&_6$$3);
		if (_7$$3) {
			ZEPHIR_CALL_METHOD(&_8$$3, &record, "haschanged", NULL, 0);
			zephir_check_call_status();
			_7$$3 = !zephir_is_true(&_8$$3);
		}
		if (_7$$3) {
			continue;
		}
		ZVAL_LONG(&_9$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, &record, "setdirtystate", NULL, 0, &_9$$3);
		zephir_check_call_status();
		zephir_array_update_zval(&dirtyRelated, &name, &record, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
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
	if (zephir_array_isset_value_string(parameters, SL("order"))) {
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
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getwriteconnection", NULL, 0);
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
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 7, &_5$$3, &_6$$3, &_7$$3, &_8$$3, &_4$$3);
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
	zval __$true, __$false, metaData, writeConnection, primaryKeys, bindDataTypes, columnMap, attributeField, primaryKey, bindType, value, schema, source, table, success, _0, _1, _2, _3, _5, *_8, _21, _31, _35, _36, _38, _4$$3, _6$$7, _7$$7, _9$$9, _10$$9, _12$$11, _13$$11, _15$$13, _16$$13, _18$$8, _20$$8, _22$$15, _23$$15, _24$$17, _25$$17, _26$$19, _27$$19, _28$$14, _30$$14, _32$$20, _33$$20, _34$$20, _37$$25, _39$$28, _40$$29, _41$$29, _42$$29;
	zephir_fcall_cache_entry *_11 = NULL, *_14 = NULL, *_17 = NULL, *_19 = NULL, *_29 = NULL;
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
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_24$$17);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_26$$19);
	ZVAL_UNDEF(&_27$$19);
	ZVAL_UNDEF(&_28$$14);
	ZVAL_UNDEF(&_30$$14);
	ZVAL_UNDEF(&_32$$20);
	ZVAL_UNDEF(&_33$$20);
	ZVAL_UNDEF(&_34$$20);
	ZVAL_UNDEF(&_37$$25);
	ZVAL_UNDEF(&_39$$28);
	ZVAL_UNDEF(&_40$$29);
	ZVAL_UNDEF(&_41$$29);
	ZVAL_UNDEF(&_42$$29);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&conditions);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&writeConnection, this_ptr, "getwriteconnection", NULL, 0);
	zephir_check_call_status();
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, 3);
	zephir_update_property_zval(this_ptr, ZEND_STRL("operationMade"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, ZEND_STRL("errorMessages"), &_1);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "orm.virtual_foreign_keys");
	ZEPHIR_CALL_CE_STATIC(&_2, phalcon_support_settings_ce, "get", NULL, 0, &_3);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "checkforeignkeysreverserestrict", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_4$$3)) {
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
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "orm.column_renaming");
	ZEPHIR_CALL_CE_STATIC(&_5, phalcon_support_settings_ce, "get", NULL, 0, &_3);
	zephir_check_call_status();
	if (zephir_is_true(&_5)) {
		ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&columnMap);
		ZVAL_NULL(&columnMap);
	}
	if (UNEXPECTED(!(zephir_fast_count_int(&primaryKeys)))) {
		ZEPHIR_INIT_VAR(&_6$$7);
		object_init_ex(&_6$$7, phalcon_mvc_model_exceptions_primarykeyrequired_ce);
		ZEPHIR_INIT_VAR(&_7$$7);
		zephir_get_class(&_7$$7, this_ptr, 0);
		ZEPHIR_CALL_METHOD(NULL, &_6$$7, "__construct", NULL, 0, &_7$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$7, "phalcon/Mvc/Model.zep", 1478);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_is_iterable(&primaryKeys, 0, "phalcon/Mvc/Model.zep", 1520);
	if (Z_TYPE_P(&primaryKeys) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&primaryKeys), _8)
		{
			ZEPHIR_INIT_NVAR(&primaryKey);
			ZVAL_COPY(&primaryKey, _8);
			ZEPHIR_OBS_NVAR(&bindType);
			if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &primaryKey, 0)))) {
				ZEPHIR_INIT_NVAR(&_9$$9);
				object_init_ex(&_9$$9, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
				ZEPHIR_INIT_NVAR(&_10$$9);
				zephir_get_class(&_10$$9, this_ptr, 0);
				ZEPHIR_CALL_METHOD(NULL, &_9$$9, "__construct", &_11, 0, &primaryKey, &_10$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_9$$9, "phalcon/Mvc/Model.zep", 1490);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &primaryKey, 0)))) {
					ZEPHIR_INIT_NVAR(&_12$$11);
					object_init_ex(&_12$$11, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
					ZEPHIR_INIT_NVAR(&_13$$11);
					zephir_get_class(&_13$$11, this_ptr, 0);
					ZEPHIR_CALL_METHOD(NULL, &_12$$11, "__construct", &_14, 0, &primaryKey, &_13$$11);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_12$$11, "phalcon/Mvc/Model.zep", 1498);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &primaryKey);
			}
			ZEPHIR_OBS_NVAR(&value);
			if (UNEXPECTED(!(zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)))) {
				ZEPHIR_INIT_NVAR(&_15$$13);
				object_init_ex(&_15$$13, phalcon_mvc_model_exceptions_primarykeyattributenotset_ce);
				ZEPHIR_INIT_NVAR(&_16$$13);
				zephir_get_class(&_16$$13, this_ptr, 0);
				ZEPHIR_CALL_METHOD(NULL, &_15$$13, "__construct", &_17, 0, &attributeField, &_16$$13);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_15$$13, "phalcon/Mvc/Model.zep", 1509);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1515);
			ZEPHIR_CALL_METHOD(&_18$$8, &writeConnection, "escapeidentifier", &_19, 0, &primaryKey);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_20$$8);
			ZEPHIR_CONCAT_VS(&_20$$8, &_18$$8, " = ?");
			zephir_array_append(&conditions, &_20$$8, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1516);
			zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1517);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &primaryKeys, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_21, &primaryKeys, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_21)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&primaryKey, &primaryKeys, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&bindType);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &primaryKey, 0)))) {
					ZEPHIR_INIT_NVAR(&_22$$15);
					object_init_ex(&_22$$15, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
					ZEPHIR_INIT_NVAR(&_23$$15);
					zephir_get_class(&_23$$15, this_ptr, 0);
					ZEPHIR_CALL_METHOD(NULL, &_22$$15, "__construct", &_11, 0, &primaryKey, &_23$$15);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_22$$15, "phalcon/Mvc/Model.zep", 1490);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &primaryKey, 0)))) {
						ZEPHIR_INIT_NVAR(&_24$$17);
						object_init_ex(&_24$$17, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
						ZEPHIR_INIT_NVAR(&_25$$17);
						zephir_get_class(&_25$$17, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_24$$17, "__construct", &_14, 0, &primaryKey, &_25$$17);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_24$$17, "phalcon/Mvc/Model.zep", 1498);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &primaryKey);
				}
				ZEPHIR_OBS_NVAR(&value);
				if (UNEXPECTED(!(zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)))) {
					ZEPHIR_INIT_NVAR(&_26$$19);
					object_init_ex(&_26$$19, phalcon_mvc_model_exceptions_primarykeyattributenotset_ce);
					ZEPHIR_INIT_NVAR(&_27$$19);
					zephir_get_class(&_27$$19, this_ptr, 0);
					ZEPHIR_CALL_METHOD(NULL, &_26$$19, "__construct", &_17, 0, &attributeField, &_27$$19);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_26$$19, "phalcon/Mvc/Model.zep", 1509);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1515);
				ZEPHIR_CALL_METHOD(&_28$$14, &writeConnection, "escapeidentifier", &_29, 0, &primaryKey);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_30$$14);
				ZEPHIR_CONCAT_VS(&_30$$14, &_28$$14, " = ?");
				zephir_array_append(&conditions, &_30$$14, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1516);
				zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1517);
			ZEPHIR_CALL_METHOD(NULL, &primaryKeys, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&primaryKey);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "orm.events");
	ZEPHIR_CALL_CE_STATIC(&_31, phalcon_support_settings_ce, "get", NULL, 0, &_3);
	zephir_check_call_status();
	if (zephir_is_true(&_31)) {
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
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	ZEPHIR_INIT_NVAR(&_3);
	zephir_fast_join_str(&_3, SL(" AND "), &conditions);
	ZEPHIR_CALL_METHOD(&success, &writeConnection, "delete", NULL, 0, &table, &_3, &values, &bindTypes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_36);
	ZVAL_STRING(&_36, "orm.virtual_foreign_keys");
	ZEPHIR_CALL_CE_STATIC(&_35, phalcon_support_settings_ce, "get", NULL, 0, &_36);
	zephir_check_call_status();
	if (zephir_is_true(&_35)) {
		ZEPHIR_CALL_METHOD(&_37$$25, this_ptr, "checkforeignkeysreversecascade", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_37$$25)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(&_36);
	ZVAL_STRING(&_36, "orm.events");
	ZEPHIR_CALL_CE_STATIC(&_38, phalcon_support_settings_ce, "get", NULL, 0, &_36);
	zephir_check_call_status();
	if (zephir_is_true(&_38)) {
		if (zephir_is_true(&success)) {
			ZEPHIR_INIT_VAR(&_39$$28);
			ZVAL_STRING(&_39$$28, "afterDelete");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_39$$28);
			zephir_check_call_status();
		}
	}
	if (zephir_is_true(&success)) {
		ZEPHIR_INIT_VAR(&_40$$29);
		array_init(&_40$$29);
		zephir_update_property_zval(this_ptr, ZEND_STRL("related"), &_40$$29);
		ZEPHIR_INIT_VAR(&_41$$29);
		array_init(&_41$$29);
		zephir_update_property_zval(this_ptr, ZEND_STRL("dirtyRelated"), &_41$$29);
		zephir_read_property(&_42$$29, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_42$$29, "clearreusableobjects", NULL, 0);
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

	ZEPHIR_RETURN_CALL_FUNCTION("get_object_vars", NULL, 0, this_ptr);
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
 *     'for_update' => false,
 *     'shared_lock' => false,
 *     'cache' => [
 *         'lifetime' => 3600,
 *         'key' => 'my-find-key'
 *     ],
 *     'hydration' => null
 * ]
 * @return \Phalcon\Mvc\Model\Resultset<int, T>
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
			zephir_array_append(&params, parameters, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1792);
		}
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	ZEPHIR_CALL_STATIC(&query, "getpreparedquery", &_0, 0, &params);
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
 *     'for_update' => false,
 *     'shared_lock' => false,
 *     'cache' => [
 *         'lifetime' => 3600,
 *         'key' => 'my-find-key'
 *     ],
 *     'hydration' => null
 * ]
 *
 * @return T|\Phalcon\Mvc\Model\Row|null
 */
PHP_METHOD(Phalcon_Mvc_Model, findFirst)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, parameters_sub, __$null, params, query, _5, _1$$5, _2$$6, _3$$6;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);
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
		object_init_ex(&_2$$6, phalcon_mvc_model_exceptions_invalidfindparameters_ce);
		ZEPHIR_INIT_VAR(&_3$$6);
		zephir_get_called_class(&_3$$6);
		ZEPHIR_CALL_METHOD(NULL, &_2$$6, "__construct", NULL, 0, &_3$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$6, "phalcon/Mvc/Model.zep", 1914);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZVAL_LONG(&_5, 1);
	ZEPHIR_CALL_STATIC(&query, "getpreparedquery", &_4, 0, &params, &_5);
	zephir_check_call_status();
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &query, "setuniquerow", NULL, 0, &_5);
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
	zval eventName_zv, _0;
	zend_string *eventName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventName_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(eventName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&eventName_zv);
	ZVAL_STR_COPY(&eventName_zv, eventName);
	if ((zephir_method_exists(this_ptr, &eventName_zv)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &eventName_zv, NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "notifyevent", NULL, 0, &eventName_zv, this_ptr);
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
	zval eventName_zv, _0$$3, _1;
	zend_string *eventName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventName_zv);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(eventName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&eventName_zv);
	ZVAL_STR_COPY(&eventName_zv, eventName);
	if ((zephir_method_exists(this_ptr, &eventName_zv)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD_ZVAL(&_0$$3, this_ptr, &eventName_zv, NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_0$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_1, "notifyevent", NULL, 0, &eventName_zv, this_ptr);
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
	zend_string *_6;
	zend_ulong _5;
	zval changed;
	zval metaData, name, snapshot, columnMap, allAttributes, value, _0, _3, *_4, _8, _1$$3, _2$$3, _7$$6, _9$$10;
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
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&changed);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("snapshot"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&snapshot, &_0);
	if (UNEXPECTED(Z_TYPE_P(&snapshot) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_exceptions_snapshotsdisabled_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_get_class(&_2$$3, this_ptr, 0);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model.zep", 1998);
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
	ZEPHIR_INIT_VAR(&_3);
	zephir_is_iterable(&allAttributes, 0, "phalcon/Mvc/Model.zep", 2059);
	if (Z_TYPE_P(&allAttributes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&allAttributes), _5, _6, _4)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_6 != NULL) { 
				ZVAL_STR_COPY(&name, _6);
			} else {
				ZVAL_LONG(&name, _5);
			}
			ZEPHIR_INIT_NVAR(&_3);
			ZVAL_COPY(&_3, _4);
			if (!(zephir_array_key_exists(&snapshot, &name))) {
				zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2034);
				continue;
			}
			ZEPHIR_OBS_NVAR(&value);
			if (!(zephir_fetch_property_zval(&value, this_ptr, &name, PH_SILENT_CC))) {
				zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2044);
				continue;
			}
			zephir_array_fetch(&_7$$6, &snapshot, &name, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 2052);
			if (!ZEPHIR_IS_IDENTICAL(&value, &_7$$6)) {
				zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2053);
				continue;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &allAttributes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_8, &allAttributes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &allAttributes, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_3, &allAttributes, "current", NULL, 0);
			zephir_check_call_status();
				if (!(zephir_array_key_exists(&snapshot, &name))) {
					zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2034);
					continue;
				}
				ZEPHIR_OBS_NVAR(&value);
				if (!(zephir_fetch_property_zval(&value, this_ptr, &name, PH_SILENT_CC))) {
					zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2044);
					continue;
				}
				zephir_array_fetch(&_9$$10, &snapshot, &name, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 2052);
				if (!ZEPHIR_IS_IDENTICAL(&value, &_9$$10)) {
					zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2053);
					continue;
				}
			ZEPHIR_CALL_METHOD(NULL, &allAttributes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&_3);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CTOR(&changed);
}

/**
 * Returns one of the DIRTY_STATE_* constants telling if the record exists
 * in the database or not
 */
PHP_METHOD(Phalcon_Mvc_Model, getDirtyState)
{

	RETURN_MEMBER_TYPED(getThis(), "dirtyState", IS_LONG);
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
	zval *filter = NULL, filter_sub, __$null, message, _2$$4, _3$$3, *_4$$3, _6$$3, _5$$5, _7$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_5$$5);
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
		zephir_is_iterable(&_3$$3, 0, "phalcon/Mvc/Model.zep", 2123);
		if (Z_TYPE_P(&_3$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_3$$3), _4$$3)
			{
				ZEPHIR_INIT_NVAR(&message);
				ZVAL_COPY(&message, _4$$3);
				ZEPHIR_CALL_METHOD(&_5$$5, &message, "getfield", NULL, 0);
				zephir_check_call_status();
				if (zephir_fast_in_array(&_5$$5, filter)) {
					zephir_array_append(&filtered, &message, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2119);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_3$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_6$$3, &_3$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_6$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&message, &_3$$3, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_7$$7, &message, "getfield", NULL, 0);
					zephir_check_call_status();
					if (zephir_fast_in_array(&_7$$7, filter)) {
						zephir_array_append(&filtered, &message, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2119);
					}
				ZEPHIR_CALL_METHOD(NULL, &_3$$3, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&message);
		RETURN_CTOR(&filtered);
	}
	RETURN_MM_MEMBER_TYPED(getThis(), "errorMessages", IS_ARRAY);
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
	zval metaData, container, _0$$3, _1$$3, _2$$3, _3$$4, _4$$4;
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
			object_init_ex(&_3$$4, phalcon_mvc_model_exceptions_invalidmodelsmetadataservice_ce);
			ZEPHIR_INIT_VAR(&_4$$4);
			zephir_get_class(&_4$$4, this_ptr, 0);
			ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", NULL, 0, &_4$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$4, "phalcon/Mvc/Model.zep", 2155);
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

	RETURN_MEMBER_TYPED(getThis(), "operationMade", IS_LONG);
}

/**
 * Returns the internal old snapshot data
 */
PHP_METHOD(Phalcon_Mvc_Model, getOldSnapshotData)
{

	RETURN_MEMBER_TYPED(getThis(), "oldSnapshot", IS_ARRAY);
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
	zval alias_zv, *arguments = NULL, arguments_sub, __$null, relation, className, manager, result, lowerAlias, _0, _1, _2$$3, _3$$4, _6$$4, _4$$5, _5$$5, _7$$6, _8$$6;
	zend_string *alias = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias_zv);
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
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(alias)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(arguments)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		arguments = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&alias_zv);
	ZVAL_STR_COPY(&alias_zv, alias);
	if (!arguments) {
		arguments = &arguments_sub;
		arguments = &__$null;
	}
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, this_ptr, 0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_INIT_VAR(&lowerAlias);
	zephir_fast_strtolower(&lowerAlias, &alias_zv);
	ZEPHIR_CALL_METHOD(&_1, &manager, "getrelationbyalias", NULL, 0, &className, &lowerAlias);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&relation, &_1);
	if (UNEXPECTED(Z_TYPE_P(&relation) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_mvc_model_exceptions_relationnotdefined_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 0, &className, &alias_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Mvc/Model.zep", 2228);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(arguments) == IS_NULL) {
		zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("dirtyRelated"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_value(&_3$$4, &lowerAlias)) {
			zephir_read_property(&_4$$5, this_ptr, ZEND_STRL("dirtyRelated"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_5$$5, &_4$$5, &lowerAlias, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 2253);
			RETURN_CTOR(&_5$$5);
		}
		zephir_read_property(&_6$$4, this_ptr, ZEND_STRL("related"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_value(&_6$$4, &lowerAlias)) {
			zephir_read_property(&_7$$6, this_ptr, ZEND_STRL("related"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_8$$6, &_7$$6, &lowerAlias, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 2256);
			RETURN_CTOR(&_8$$6);
		}
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
	zval relationshipAlias_zv, _0, _1;
	zend_string *relationshipAlias = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&relationshipAlias_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(relationshipAlias)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&relationshipAlias_zv);
	ZVAL_STR_COPY(&relationshipAlias_zv, relationshipAlias);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("related"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strtolower(&_1, &relationshipAlias_zv);
	RETURN_MM_BOOL(zephir_array_isset_value(&_0, &_1));
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

	RETURN_MEMBER_TYPED(getThis(), "snapshot", IS_ARRAY);
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
	zend_bool _12$$6, _15$$8;
	zend_string *_11;
	zend_ulong _10;
	zval updated;
	zval name, snapshot, oldSnapshot, value, _0, _1, _2, *_9, _14, _3$$3, _4$$3, _5$$4, _6$$4, _7$$5, _8$$5, _13$$6, _16$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&oldSnapshot);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&updated);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("snapshot"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&snapshot, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("oldSnapshot"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&oldSnapshot, &_0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "orm.update_snapshot_on_save");
	ZEPHIR_CALL_CE_STATIC(&_1, phalcon_support_settings_ce, "get", NULL, 0, &_2);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_1))) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, phalcon_mvc_model_exceptions_updatesnapshotdisabled_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_get_class(&_4$$3, this_ptr, 0);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 0, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "phalcon/Mvc/Model.zep", 2357);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(Z_TYPE_P(&snapshot) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_5$$4);
		object_init_ex(&_5$$4, phalcon_mvc_model_exceptions_snapshotsdisabled_ce);
		ZEPHIR_INIT_VAR(&_6$$4);
		zephir_get_class(&_6$$4, this_ptr, 0);
		ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", NULL, 0, &_6$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$4, "phalcon/Mvc/Model.zep", 2361);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("dirtyState"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!ZEPHIR_IS_LONG(&_0, 0))) {
		ZEPHIR_INIT_VAR(&_7$$5);
		object_init_ex(&_7$$5, phalcon_mvc_model_exceptions_recordnotpersisted_ce);
		ZEPHIR_INIT_VAR(&_8$$5);
		zephir_get_class(&_8$$5, this_ptr, 0);
		ZEPHIR_CALL_METHOD(NULL, &_7$$5, "__construct", NULL, 0, &_8$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$5, "phalcon/Mvc/Model.zep", 2368);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&updated);
	array_init(&updated);
	zephir_is_iterable(&snapshot, 0, "phalcon/Mvc/Model.zep", 2386);
	if (Z_TYPE_P(&snapshot) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&snapshot), _10, _11, _9)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_11 != NULL) { 
				ZVAL_STR_COPY(&name, _11);
			} else {
				ZVAL_LONG(&name, _10);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _9);
			_12$$6 = !(zephir_array_key_exists(&oldSnapshot, &name));
			if (!(_12$$6)) {
				zephir_array_fetch(&_13$$6, &oldSnapshot, &name, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 2381);
				_12$$6 = !ZEPHIR_IS_IDENTICAL(&value, &_13$$6);
			}
			if (_12$$6) {
				zephir_array_append(&updated, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2382);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &snapshot, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_14, &snapshot, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_14)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &snapshot, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &snapshot, "current", NULL, 0);
			zephir_check_call_status();
				_15$$8 = !(zephir_array_key_exists(&oldSnapshot, &name));
				if (!(_15$$8)) {
					zephir_array_fetch(&_16$$8, &oldSnapshot, &name, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 2381);
					_15$$8 = !ZEPHIR_IS_IDENTICAL(&value, &_16$$8);
				}
				if (_15$$8) {
					zephir_array_append(&updated, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2382);
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
		ZEPHIR_CALL_FUNCTION(&intersect, "array_intersect", NULL, 0, fieldName, &changedFields);
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
		ZEPHIR_CALL_FUNCTION(&intersect, "array_intersect", NULL, 0, fieldName, &updatedFields);
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

		ZEPHIR_CALL_METHOD(NULL, &criteria, "setdi", NULL, 0, container);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_get_called_class(&_2);
	ZEPHIR_CALL_METHOD(NULL, &criteria, "setmodelname", NULL, 0, &_2);
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
	zval attribute_zv, _0;
	zend_string *attribute = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attribute_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(attribute)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&attribute_zv);
	ZVAL_STR_COPY(&attribute_zv, attribute);
	if (!(zephir_isset_property_value_zval(this_ptr, &attribute_zv))) {
		RETURN_MM_NULL();
	}
	zephir_memory_observe(&_0);
	zephir_read_property_zval(&_0, this_ptr, &attribute_zv, PH_NOISY_CC);
	RETURN_CCTOR(&_0);
}

/**
 * Refreshes the model attributes re-querying the record from the database
 */
PHP_METHOD(Phalcon_Mvc_Model, refresh)
{
	zval fields, _15, _12$$9, _14$$10;
	zval metaData, readConnection, schema, source, table, uniqueKey, tables, uniqueParams, dialect, row, attribute, manager, columnMap, _0, _3, _10, *_11, _13, _16, _17, _20, _1$$3, _2$$3, _4$$6, _7$$6, _5$$7, _6$$7, _8$$8, _9$$8, _18$$11, _19$$11;
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
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_14$$10);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("dirtyState"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!ZEPHIR_IS_LONG(&_0, 0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_exceptions_recordcannotrefresh_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_get_class(&_2$$3, this_ptr, 0);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model.zep", 2635);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&readConnection, this_ptr, "getreadconnection", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_3);
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("uniqueKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueKey, &_3);
	if (!(zephir_is_true(&uniqueKey))) {
		ZEPHIR_CALL_METHOD(&_4$$6, this_ptr, "has", NULL, 0, &metaData, &readConnection);
		zephir_check_call_status();
		if (UNEXPECTED(!zephir_is_true(&_4$$6))) {
			ZEPHIR_INIT_VAR(&_5$$7);
			object_init_ex(&_5$$7, phalcon_mvc_model_exceptions_recordcannotrefresh_ce);
			ZEPHIR_INIT_VAR(&_6$$7);
			zephir_get_class(&_6$$7, this_ptr, 0);
			ZEPHIR_CALL_METHOD(NULL, &_5$$7, "__construct", NULL, 0, &_6$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$7, "phalcon/Mvc/Model.zep", 2658);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property(&_7$$6, this_ptr, ZEND_STRL("uniqueKey"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&uniqueKey, &_7$$6);
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("uniqueParams"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueParams, &_3);
	if (UNEXPECTED(Z_TYPE_P(&uniqueParams) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_8$$8);
		object_init_ex(&_8$$8, phalcon_mvc_model_exceptions_recordcannotrefresh_ce);
		ZEPHIR_INIT_VAR(&_9$$8);
		zephir_get_class(&_9$$8, this_ptr, 0);
		ZEPHIR_CALL_METHOD(NULL, &_8$$8, "__construct", NULL, 0, &_9$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$8, "phalcon/Mvc/Model.zep", 2667);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&fields);
	array_init(&fields);
	ZEPHIR_CALL_METHOD(&_10, &metaData, "getattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(&_10, 0, "phalcon/Mvc/Model.zep", 2682);
	if (Z_TYPE_P(&_10) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_10), _11)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _11);
			ZEPHIR_INIT_NVAR(&_12$$9);
			zephir_create_array(&_12$$9, 1, 0);
			zephir_array_fast_append(&_12$$9, &attribute);
			zephir_array_append(&fields, &_12$$9, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2676);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_10, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_13, &_10, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_13)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attribute, &_10, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_14$$10);
				zephir_create_array(&_14$$10, 1, 0);
				zephir_array_fast_append(&_14$$10, &attribute);
				zephir_array_append(&fields, &_14$$10, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2676);
			ZEPHIR_CALL_METHOD(NULL, &_10, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&attribute);
	ZEPHIR_CALL_METHOD(&dialect, &readConnection, "getdialect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_15);
	zephir_create_array(&_15, 3, 0);
	zephir_array_update_string(&_15, SL("columns"), &fields, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_16, &readConnection, "escapeidentifier", NULL, 0, &table);
	zephir_check_call_status();
	zephir_array_update_string(&_15, SL("tables"), &_16, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_15, SL("where"), &uniqueKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&tables, &dialect, "select", NULL, 0, &_15);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("uniqueTypes"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_17, 2);
	ZEPHIR_CALL_METHOD(&row, &readConnection, "fetchone", NULL, 0, &tables, &_17, &uniqueParams, &_3);
	zephir_check_call_status();
	if (Z_TYPE_P(&row) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, this_ptr);
		zephir_check_call_status();
		ZVAL_NULL(&_18$$11);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "assign", NULL, 0, &row, &_18$$11, &columnMap);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_19$$11, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (zephir_is_true(&_19$$11)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setsnapshotdata", NULL, 0, &row, &columnMap);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoldsnapshotdata", NULL, 0, &row, &columnMap);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_VAR(&_20);
	ZVAL_STRING(&_20, "afterFetch");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_20);
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
	ZEPHIR_CALL_METHOD(NULL, &visited, "__construct", NULL, 41);
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
	zend_bool hasRelatedToSave = 0, _12, _20$$21;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *visited, visited_sub, metaData, schema, writeConnection, readConnection, source, table, identityField, exists, success, relatedToSave, objId, manager, savedSnapshot, savedOldSnapshot, _0, _1, _5, _11, _13, _14, _17, _2$$4, _3$$8, _4$$9, _6$$11, _7$$10, _8$$10, _9$$12, _10$$12, _15$$16, _16$$18, _18$$20, _19$$21, _21$$21, _22$$21, _23$$24, _24$$23, _25$$23, _26$$23;
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
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&savedSnapshot);
	ZVAL_UNDEF(&savedOldSnapshot);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_6$$11);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$12);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_15$$16);
	ZVAL_UNDEF(&_16$$18);
	ZVAL_UNDEF(&_18$$20);
	ZVAL_UNDEF(&_19$$21);
	ZVAL_UNDEF(&_21$$21);
	ZVAL_UNDEF(&_22$$21);
	ZVAL_UNDEF(&_23$$24);
	ZVAL_UNDEF(&_24$$23);
	ZVAL_UNDEF(&_25$$23);
	ZVAL_UNDEF(&_26$$23);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(visited, phalcon_support_collection_collectioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &visited);
	ZEPHIR_CALL_FUNCTION(&objId, "spl_object_id", NULL, 184, this_ptr);
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
	ZEPHIR_CALL_METHOD(&writeConnection, this_ptr, "getwriteconnection", NULL, 0);
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
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	ZEPHIR_CALL_METHOD(&readConnection, this_ptr, "getreadconnection", NULL, 0);
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
		ZEPHIR_INIT_VAR(&_8$$10);
		ZVAL_STRING(&_8$$10, "orm.exception_on_failed_save");
		ZEPHIR_CALL_CE_STATIC(&_7$$10, phalcon_support_settings_ce, "get", NULL, 0, &_8$$10);
		zephir_check_call_status();
		if (UNEXPECTED(zephir_is_true(&_7$$10))) {
			ZEPHIR_INIT_VAR(&_9$$12);
			object_init_ex(&_9$$12, phalcon_mvc_model_validationfailed_ce);
			ZEPHIR_CALL_METHOD(&_10$$12, this_ptr, "getmessages", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_9$$12, "__construct", NULL, 0, this_ptr, &_10$$12);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_9$$12, "phalcon/Mvc/Model.zep", 2857);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_11, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
	zephir_check_call_status();
	_12 = zephir_is_true(&_11);
	if (_12) {
		ZEPHIR_INIT_VAR(&_14);
		ZVAL_STRING(&_14, "orm.update_snapshot_on_save");
		ZEPHIR_CALL_CE_STATIC(&_13, phalcon_support_settings_ce, "get", NULL, 0, &_14);
		zephir_check_call_status();
		_12 = zephir_is_true(&_13);
	}
	if (_12) {
		zephir_memory_observe(&savedSnapshot);
		zephir_read_property(&savedSnapshot, this_ptr, ZEND_STRL("snapshot"), PH_NOISY_CC);
		zephir_memory_observe(&savedOldSnapshot);
		zephir_read_property(&savedOldSnapshot, this_ptr, ZEND_STRL("oldSnapshot"), PH_NOISY_CC);
	}
	if (zephir_is_true(&exists)) {
		ZEPHIR_CALL_METHOD(&success, this_ptr, "dolowupdate", NULL, 0, &metaData, &writeConnection, &table);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&success, this_ptr, "dolowinsert", NULL, 0, &metaData, &writeConnection, &table, &identityField);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_TRUE_IDENTICAL(&success)) {
		ZVAL_UNDEF(&_15$$16);
		ZVAL_LONG(&_15$$16, 0);
		zephir_update_property_zval(this_ptr, ZEND_STRL("dirtyState"), &_15$$16);
	}
	if (hasRelatedToSave) {
		if (ZEPHIR_IS_FALSE_IDENTICAL(&success)) {
			ZVAL_BOOL(&_16$$18, 0);
			ZEPHIR_CALL_METHOD(NULL, &writeConnection, "rollback", NULL, 0, &_16$$18);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&success, this_ptr, "postsaverelatedrecords", NULL, 0, &writeConnection, &relatedToSave, visited);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&_14);
	ZVAL_STRING(&_14, "orm.events");
	ZEPHIR_CALL_CE_STATIC(&_17, phalcon_support_settings_ce, "get", NULL, 0, &_14);
	zephir_check_call_status();
	if (zephir_is_true(&_17)) {
		ZEPHIR_CALL_METHOD(&_18$$20, this_ptr, "postsave", NULL, 0, &success, &exists);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&success, &_18$$20);
	}
	if (ZEPHIR_IS_FALSE_IDENTICAL(&success)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "canceloperation", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_19$$21, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		_20$$21 = zephir_is_true(&_19$$21);
		if (_20$$21) {
			ZEPHIR_INIT_VAR(&_22$$21);
			ZVAL_STRING(&_22$$21, "orm.update_snapshot_on_save");
			ZEPHIR_CALL_CE_STATIC(&_21$$21, phalcon_support_settings_ce, "get", NULL, 0, &_22$$21);
			zephir_check_call_status();
			_20$$21 = zephir_is_true(&_21$$21);
		}
		if (_20$$21) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("snapshot"), &savedSnapshot);
			zephir_update_property_zval(this_ptr, ZEND_STRL("oldSnapshot"), &savedOldSnapshot);
		}
	} else {
		if (hasRelatedToSave) {
			ZEPHIR_INIT_VAR(&_23$$24);
			array_init(&_23$$24);
			zephir_update_property_zval(this_ptr, ZEND_STRL("dirtyRelated"), &_23$$24);
		}
		ZEPHIR_INIT_VAR(&_24$$23);
		array_init(&_24$$23);
		zephir_update_property_zval(this_ptr, ZEND_STRL("related"), &_24$$23);
		zephir_read_property(&_25$$23, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_25$$23, "clearreusableobjects", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_26$$23);
		ZVAL_STRING(&_26$$23, "afterSave");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_26$$23);
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
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 21, &_6);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Unserializes the object from a serialized string
 */
PHP_METHOD(Phalcon_Mvc_Model, unserialize)
{
	zend_ulong _8$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data_zv, attributes, container, manager, key, value, snapshot, properties, dirtyState, _0$$4, _1$$5, _2$$5, _3$$3, _4$$3, _5$$6, _6$$6, *_7$$8, _12$$8, _10$$9, _11$$9, _13$$12, _14$$12, _15$$18;
	zend_string *data = NULL, *_9$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_zv);
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
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_15$$18);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	ZEPHIR_CALL_FUNCTION(&attributes, "unserialize", NULL, 26, &data_zv);
	zephir_check_call_status();
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		if (!(zephir_array_isset_value_string(&attributes, SL("attributes")))) {
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_create_array(&_0$$4, 1, 0);
			zephir_array_update_string(&_0$$4, SL("attributes"), &attributes, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&attributes, &_0$$4);
		}
		ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_di_ce, "getdefault", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&container) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$5);
			object_init_ex(&_1$$5, phalcon_mvc_model_exceptions_modelormservicesunavailable_ce);
			ZEPHIR_INIT_VAR(&_2$$5);
			zephir_get_class(&_2$$5, this_ptr, 0);
			ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", NULL, 0, &_2$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$5, "phalcon/Mvc/Model.zep", 2997);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("container"), &container);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "modelsManager");
		ZEPHIR_CALL_METHOD(&_3$$3, &container, "getshared", NULL, 0, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&manager, &_3$$3);
		if (UNEXPECTED(Z_TYPE_P(&manager) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_5$$6);
			object_init_ex(&_5$$6, phalcon_mvc_model_exceptions_invalidmodelsmanagerservice_ce);
			ZEPHIR_INIT_VAR(&_6$$6);
			zephir_get_class(&_6$$6, this_ptr, 0);
			ZEPHIR_CALL_METHOD(NULL, &_5$$6, "__construct", NULL, 0, &_6$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$6, "phalcon/Mvc/Model.zep", 3011);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("modelsManager"), &manager);
		ZEPHIR_CALL_METHOD(NULL, &manager, "initialize", NULL, 0, this_ptr);
		zephir_check_call_status();
		if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("onconstruct")) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "onconstruct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_memory_observe(&properties);
		if (zephir_array_isset_string_fetch(&properties, &attributes, SL("attributes"), 0)) {
			zephir_is_iterable(&properties, 0, "phalcon/Mvc/Model.zep", 3050);
			if (Z_TYPE_P(&properties) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&properties), _8$$8, _9$$8, _7$$8)
				{
					ZEPHIR_INIT_NVAR(&key);
					if (_9$$8 != NULL) { 
						ZVAL_STR_COPY(&key, _9$$8);
					} else {
						ZVAL_LONG(&key, _8$$8);
					}
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_COPY(&value, _7$$8);

					/* try_start_1: */

						zephir_update_property_zval_zval(this_ptr, &key, &value);

					try_end_1:

					if (EG(exception)) {
						ZEPHIR_INIT_NVAR(&_10$$9);
						ZVAL_OBJ(&_10$$9, EG(exception));
						Z_ADDREF_P(&_10$$9);
						ZEPHIR_INIT_NVAR(&_11$$9);
						if (zephir_is_instance_of(&_10$$9, SL("TypeError"))) {
							zend_clear_exception();
							ZEPHIR_CPY_WRT(&_11$$9, &_10$$9);
						}
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &properties, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_12$$8, &properties, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_12$$8)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&key, &properties, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&value, &properties, "current", NULL, 0);
					zephir_check_call_status();

						/* try_start_2: */

							zephir_update_property_zval_zval(this_ptr, &key, &value);

						try_end_2:

						if (EG(exception)) {
							ZEPHIR_INIT_NVAR(&_13$$12);
							ZVAL_OBJ(&_13$$12, EG(exception));
							Z_ADDREF_P(&_13$$12);
							ZEPHIR_INIT_NVAR(&_14$$12);
							if (zephir_is_instance_of(&_13$$12, SL("TypeError"))) {
								zend_clear_exception();
								ZEPHIR_CPY_WRT(&_14$$12, &_13$$12);
							}
						}
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
		ZEPHIR_CALL_METHOD(&_3$$3, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (zephir_is_true(&_3$$3)) {
			if (zephir_array_isset_string_fetch(&snapshot, &attributes, SL("snapshot"), 1)) {
				ZEPHIR_INIT_VAR(&_15$$18);
				if (Z_TYPE_P(&snapshot) != IS_NULL) {
					ZEPHIR_CPY_WRT(&_15$$18, &snapshot);
				} else {
					ZEPHIR_CPY_WRT(&_15$$18, &properties);
				}
				zephir_update_property_zval(this_ptr, ZEND_STRL("snapshot"), &_15$$18);
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
	zval connectionService_zv, _0;
	zend_string *connectionService = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connectionService_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(connectionService)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&connectionService_zv);
	ZVAL_STR_COPY(&connectionService_zv, connectionService);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setconnectionservice", NULL, 0, this_ptr, &connectionService_zv);
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
	zval connectionService_zv, _0;
	zend_string *connectionService = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connectionService_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(connectionService)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&connectionService_zv);
	ZVAL_STR_COPY(&connectionService_zv, connectionService);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setreadconnectionservice", NULL, 0, this_ptr, &connectionService_zv);
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
	zend_string *_2$$3;
	zend_ulong _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *columnMap = NULL, columnMap_sub, __$null, key, value, attribute, *_0$$3, _13$$3, _3$$6, _5$$6, _6$$7, _7$$7, _9$$9, _10$$9, _11$$10, _12$$10, _14$$13, _15$$13, _16$$14, _17$$14, _18$$16, _19$$16, _20$$17, _21$$17;
	zval data, snapshot;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_16$$14);
	ZVAL_UNDEF(&_17$$14);
	ZVAL_UNDEF(&_18$$16);
	ZVAL_UNDEF(&_19$$16);
	ZVAL_UNDEF(&_20$$17);
	ZVAL_UNDEF(&_21$$17);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
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
		zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 3166);
		if (Z_TYPE_P(&data) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _1$$3, _2$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_2$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _2$$3);
				} else {
					ZVAL_LONG(&key, _1$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _0$$3);
				if (Z_TYPE_P(&key) != IS_STRING) {
					continue;
				}
				ZEPHIR_OBS_NVAR(&attribute);
				if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0))) {
					ZEPHIR_INIT_NVAR(&_5$$6);
					ZVAL_STRING(&_5$$6, "orm.ignore_unknown_columns");
					ZEPHIR_CALL_CE_STATIC(&_3$$6, phalcon_support_settings_ce, "get", &_4, 0, &_5$$6);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&_3$$6))) {
						ZEPHIR_INIT_NVAR(&_6$$7);
						object_init_ex(&_6$$7, phalcon_mvc_model_exceptions_columnnotinmap_ce);
						ZEPHIR_INIT_NVAR(&_7$$7);
						zephir_get_class(&_7$$7, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_6$$7, "__construct", &_8, 0, &key, &_7$$7);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_6$$7, "phalcon/Mvc/Model.zep", 3148);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
				if (Z_TYPE_P(&attribute) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attribute);
					if (!(zephir_array_isset_long_fetch(&attribute, &attribute, 0, 0))) {
						ZEPHIR_INIT_NVAR(&_10$$9);
						ZVAL_STRING(&_10$$9, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_9$$9, phalcon_support_settings_ce, "get", &_4, 0, &_10$$9);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_9$$9))) {
							ZEPHIR_INIT_NVAR(&_11$$10);
							object_init_ex(&_11$$10, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							ZEPHIR_INIT_NVAR(&_12$$10);
							zephir_get_class(&_12$$10, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_11$$10, "__construct", &_8, 0, &key, &_12$$10);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_11$$10, "phalcon/Mvc/Model.zep", 3157);
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
				ZEPHIR_CALL_METHOD(&_13$$3, &data, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_13$$3)) {
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
						ZEPHIR_INIT_NVAR(&_15$$13);
						ZVAL_STRING(&_15$$13, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_14$$13, phalcon_support_settings_ce, "get", &_4, 0, &_15$$13);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_14$$13))) {
							ZEPHIR_INIT_NVAR(&_16$$14);
							object_init_ex(&_16$$14, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							ZEPHIR_INIT_NVAR(&_17$$14);
							zephir_get_class(&_17$$14, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_16$$14, "__construct", &_8, 0, &key, &_17$$14);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_16$$14, "phalcon/Mvc/Model.zep", 3148);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
					if (Z_TYPE_P(&attribute) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attribute);
						if (!(zephir_array_isset_long_fetch(&attribute, &attribute, 0, 0))) {
							ZEPHIR_INIT_NVAR(&_19$$16);
							ZVAL_STRING(&_19$$16, "orm.ignore_unknown_columns");
							ZEPHIR_CALL_CE_STATIC(&_18$$16, phalcon_support_settings_ce, "get", &_4, 0, &_19$$16);
							zephir_check_call_status();
							if (UNEXPECTED(!zephir_is_true(&_18$$16))) {
								ZEPHIR_INIT_NVAR(&_20$$17);
								object_init_ex(&_20$$17, phalcon_mvc_model_exceptions_columnnotinmap_ce);
								ZEPHIR_INIT_NVAR(&_21$$17);
								zephir_get_class(&_21$$17, this_ptr, 0);
								ZEPHIR_CALL_METHOD(NULL, &_20$$17, "__construct", &_8, 0, &key, &_21$$17);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_20$$17, "phalcon/Mvc/Model.zep", 3157);
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
	zend_bool _3$$4, _19$$12;
	zend_string *_2$$3;
	zend_ulong _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *columnMap = NULL, columnMap_sub, __$null, key, value, attribute, *_0$$3, _18$$3, _4$$4, _6$$4, _7$$6, _9$$7, _10$$7, _11$$8, _12$$8, _14$$10, _15$$10, _16$$11, _17$$11, _20$$12, _21$$12, _22$$14, _23$$15, _24$$15, _25$$16, _26$$16, _27$$18, _28$$18, _29$$19, _30$$19;
	zval data, snapshot;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_26$$16);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_28$$18);
	ZVAL_UNDEF(&_29$$19);
	ZVAL_UNDEF(&_30$$19);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
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
		zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 3227);
		if (Z_TYPE_P(&data) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _1$$3, _2$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_2$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _2$$3);
				} else {
					ZVAL_LONG(&key, _1$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _0$$3);
				if (Z_TYPE_P(&key) != IS_STRING) {
					continue;
				}
				_3$$4 = !(zephir_array_isset_value(columnMap, &key));
				if (_3$$4) {
					ZEPHIR_INIT_NVAR(&_6$$4);
					ZVAL_STRING(&_6$$4, "orm.case_insensitive_column_map");
					ZEPHIR_CALL_CE_STATIC(&_4$$4, phalcon_support_settings_ce, "get", &_5, 0, &_6$$4);
					zephir_check_call_status();
					_3$$4 = zephir_is_true(&_4$$4);
				}
				if (_3$$4) {
					ZEPHIR_CALL_SELF(&_7$$6, "caseinsensitivecolumnmap", &_8, 0, columnMap, &key);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&key, &_7$$6);
				}
				ZEPHIR_OBS_NVAR(&attribute);
				if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0))) {
					ZEPHIR_INIT_NVAR(&_10$$7);
					ZVAL_STRING(&_10$$7, "orm.ignore_unknown_columns");
					ZEPHIR_CALL_CE_STATIC(&_9$$7, phalcon_support_settings_ce, "get", &_5, 0, &_10$$7);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&_9$$7))) {
						ZEPHIR_INIT_NVAR(&_11$$8);
						object_init_ex(&_11$$8, phalcon_mvc_model_exceptions_columnnotinmap_ce);
						ZEPHIR_INIT_NVAR(&_12$$8);
						zephir_get_class(&_12$$8, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_11$$8, "__construct", &_13, 0, &key, &_12$$8);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_11$$8, "phalcon/Mvc/Model.zep", 3209);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
				if (Z_TYPE_P(&attribute) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attribute);
					if (!(zephir_array_isset_long_fetch(&attribute, &attribute, 0, 0))) {
						ZEPHIR_INIT_NVAR(&_15$$10);
						ZVAL_STRING(&_15$$10, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_14$$10, phalcon_support_settings_ce, "get", &_5, 0, &_15$$10);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_14$$10))) {
							ZEPHIR_INIT_NVAR(&_16$$11);
							object_init_ex(&_16$$11, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							ZEPHIR_INIT_NVAR(&_17$$11);
							zephir_get_class(&_17$$11, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_16$$11, "__construct", &_13, 0, &key, &_17$$11);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_16$$11, "phalcon/Mvc/Model.zep", 3218);
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
				ZEPHIR_CALL_METHOD(&_18$$3, &data, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_18$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&key) != IS_STRING) {
						continue;
					}
					_19$$12 = !(zephir_array_isset_value(columnMap, &key));
					if (_19$$12) {
						ZEPHIR_INIT_NVAR(&_21$$12);
						ZVAL_STRING(&_21$$12, "orm.case_insensitive_column_map");
						ZEPHIR_CALL_CE_STATIC(&_20$$12, phalcon_support_settings_ce, "get", &_5, 0, &_21$$12);
						zephir_check_call_status();
						_19$$12 = zephir_is_true(&_20$$12);
					}
					if (_19$$12) {
						ZEPHIR_CALL_SELF(&_22$$14, "caseinsensitivecolumnmap", &_8, 0, columnMap, &key);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&key, &_22$$14);
					}
					ZEPHIR_OBS_NVAR(&attribute);
					if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0))) {
						ZEPHIR_INIT_NVAR(&_24$$15);
						ZVAL_STRING(&_24$$15, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_23$$15, phalcon_support_settings_ce, "get", &_5, 0, &_24$$15);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_23$$15))) {
							ZEPHIR_INIT_NVAR(&_25$$16);
							object_init_ex(&_25$$16, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							ZEPHIR_INIT_NVAR(&_26$$16);
							zephir_get_class(&_26$$16, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_25$$16, "__construct", &_13, 0, &key, &_26$$16);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_25$$16, "phalcon/Mvc/Model.zep", 3209);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
					if (Z_TYPE_P(&attribute) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attribute);
						if (!(zephir_array_isset_long_fetch(&attribute, &attribute, 0, 0))) {
							ZEPHIR_INIT_NVAR(&_28$$18);
							ZVAL_STRING(&_28$$18, "orm.ignore_unknown_columns");
							ZEPHIR_CALL_CE_STATIC(&_27$$18, phalcon_support_settings_ce, "get", &_5, 0, &_28$$18);
							zephir_check_call_status();
							if (UNEXPECTED(!zephir_is_true(&_27$$18))) {
								ZEPHIR_INIT_NVAR(&_29$$19);
								object_init_ex(&_29$$19, phalcon_mvc_model_exceptions_columnnotinmap_ce);
								ZEPHIR_INIT_NVAR(&_30$$19);
								zephir_get_class(&_30$$19, this_ptr, 0);
								ZEPHIR_CALL_METHOD(NULL, &_29$$19, "__construct", &_13, 0, &key, &_30$$19);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_29$$19, "phalcon/Mvc/Model.zep", 3218);
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, disableEvents, columnRenaming, notNullValidations, exceptionOnFailedSave, exceptionOnFailedMetaDataSave, phqlLiterals, virtualForeignKeys, lateStateBinding, castOnHydrate, ignoreUnknownColumns, updateSnapshotOnSave, disableAssignSetters, caseInsensitiveColumnMap, prefetchRecords, lastInsertId, _0$$3, _1$$4, _2$$5, _3$$6, _4$$7, _5$$8, _6$$9, _7$$10, _8$$11, _9$$12, _10$$13, _11$$14, _12$$15, _13$$16, _14$$17;
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
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$12);
	ZVAL_UNDEF(&_10$$13);
	ZVAL_UNDEF(&_11$$14);
	ZVAL_UNDEF(&_12$$15);
	ZVAL_UNDEF(&_13$$16);
	ZVAL_UNDEF(&_14$$17);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &options_param);
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	zephir_memory_observe(&disableEvents);
	if (zephir_array_isset_string_fetch(&disableEvents, &options, SL("events"), 0)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "orm.events");
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_0$$3, &disableEvents);
		zephir_check_call_status();
	}
	zephir_memory_observe(&virtualForeignKeys);
	if (zephir_array_isset_string_fetch(&virtualForeignKeys, &options, SL("virtualForeignKeys"), 0)) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "orm.virtual_foreign_keys");
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_1$$4, &virtualForeignKeys);
		zephir_check_call_status();
	}
	zephir_memory_observe(&columnRenaming);
	if (zephir_array_isset_string_fetch(&columnRenaming, &options, SL("columnRenaming"), 0)) {
		ZEPHIR_INIT_VAR(&_2$$5);
		ZVAL_STRING(&_2$$5, "orm.column_renaming");
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_2$$5, &columnRenaming);
		zephir_check_call_status();
	}
	zephir_memory_observe(&notNullValidations);
	if (zephir_array_isset_string_fetch(&notNullValidations, &options, SL("notNullValidations"), 0)) {
		ZEPHIR_INIT_VAR(&_3$$6);
		ZVAL_STRING(&_3$$6, "orm.not_null_validations");
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_3$$6, &notNullValidations);
		zephir_check_call_status();
	}
	zephir_memory_observe(&exceptionOnFailedSave);
	if (zephir_array_isset_string_fetch(&exceptionOnFailedSave, &options, SL("exceptionOnFailedSave"), 0)) {
		ZEPHIR_INIT_VAR(&_4$$7);
		ZVAL_STRING(&_4$$7, "orm.exception_on_failed_save");
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_4$$7, &exceptionOnFailedSave);
		zephir_check_call_status();
	}
	zephir_memory_observe(&exceptionOnFailedMetaDataSave);
	if (zephir_array_isset_string_fetch(&exceptionOnFailedMetaDataSave, &options, SL("exceptionOnFailedMetaDataSave"), 0)) {
		ZEPHIR_INIT_VAR(&_5$$8);
		ZVAL_STRING(&_5$$8, "orm.exception_on_failed_metadata_save");
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_5$$8, &exceptionOnFailedMetaDataSave);
		zephir_check_call_status();
	}
	zephir_memory_observe(&phqlLiterals);
	if (zephir_array_isset_string_fetch(&phqlLiterals, &options, SL("phqlLiterals"), 0)) {
		ZEPHIR_INIT_VAR(&_6$$9);
		ZVAL_STRING(&_6$$9, "orm.enable_literals");
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_6$$9, &phqlLiterals);
		zephir_check_call_status();
	}
	zephir_memory_observe(&lateStateBinding);
	if (zephir_array_isset_string_fetch(&lateStateBinding, &options, SL("lateStateBinding"), 0)) {
		ZEPHIR_INIT_VAR(&_7$$10);
		ZVAL_STRING(&_7$$10, "orm.late_state_binding");
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_7$$10, &lateStateBinding);
		zephir_check_call_status();
	}
	zephir_memory_observe(&castOnHydrate);
	if (zephir_array_isset_string_fetch(&castOnHydrate, &options, SL("castOnHydrate"), 0)) {
		ZEPHIR_INIT_VAR(&_8$$11);
		ZVAL_STRING(&_8$$11, "orm.cast_on_hydrate");
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_8$$11, &castOnHydrate);
		zephir_check_call_status();
	}
	zephir_memory_observe(&ignoreUnknownColumns);
	if (zephir_array_isset_string_fetch(&ignoreUnknownColumns, &options, SL("ignoreUnknownColumns"), 0)) {
		ZEPHIR_INIT_VAR(&_9$$12);
		ZVAL_STRING(&_9$$12, "orm.ignore_unknown_columns");
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_9$$12, &ignoreUnknownColumns);
		zephir_check_call_status();
	}
	zephir_memory_observe(&caseInsensitiveColumnMap);
	if (zephir_array_isset_string_fetch(&caseInsensitiveColumnMap, &options, SL("caseInsensitiveColumnMap"), 0)) {
		ZEPHIR_INIT_VAR(&_10$$13);
		ZVAL_STRING(&_10$$13, "orm.case_insensitive_column_map");
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_10$$13, &caseInsensitiveColumnMap);
		zephir_check_call_status();
	}
	zephir_memory_observe(&updateSnapshotOnSave);
	if (zephir_array_isset_string_fetch(&updateSnapshotOnSave, &options, SL("updateSnapshotOnSave"), 0)) {
		ZEPHIR_INIT_VAR(&_11$$14);
		ZVAL_STRING(&_11$$14, "orm.update_snapshot_on_save");
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_11$$14, &updateSnapshotOnSave);
		zephir_check_call_status();
	}
	zephir_memory_observe(&disableAssignSetters);
	if (zephir_array_isset_string_fetch(&disableAssignSetters, &options, SL("disableAssignSetters"), 0)) {
		ZEPHIR_INIT_VAR(&_12$$15);
		ZVAL_STRING(&_12$$15, "orm.disable_assign_setters");
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_12$$15, &disableAssignSetters);
		zephir_check_call_status();
	}
	zephir_memory_observe(&prefetchRecords);
	if (zephir_array_isset_string_fetch(&prefetchRecords, &options, SL("prefetchRecords"), 0)) {
		ZEPHIR_INIT_VAR(&_13$$16);
		ZVAL_STRING(&_13$$16, "orm.resultset_prefetch_records");
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_13$$16, &prefetchRecords);
		zephir_check_call_status();
	}
	zephir_memory_observe(&lastInsertId);
	if (zephir_array_isset_string_fetch(&lastInsertId, &options, SL("castLastInsertIdToInt"), 0)) {
		ZEPHIR_INIT_VAR(&_14$$17);
		ZVAL_STRING(&_14$$17, "orm.cast_last_insert_id_to_int");
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_14$$17, &lastInsertId);
		zephir_check_call_status();
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
	zval connectionService_zv, _0;
	zend_string *connectionService = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connectionService_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(connectionService)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&connectionService_zv);
	ZVAL_STR_COPY(&connectionService_zv, connectionService);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setwriteconnectionservice", NULL, 0, this_ptr, &connectionService_zv);
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
	zend_bool _2$$4, _14$$3, _16$$3, _22$$17, _31$$16, _33$$16;
	zval data;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *columns = NULL, columns_sub, *useGetter = NULL, useGetter_sub, __$null, __$true, attribute, attributeField, columnMap, metaData, method, _0, *_1, _21, _3$$4, _5$$4, _6$$5, _8$$6, _9$$6, _10$$7, _11$$7, _13$$3, _15$$3, _17$$12, _18$$11, _19$$11, _20$$14, _23$$17, _24$$17, _25$$18, _26$$19, _27$$19, _28$$20, _29$$20, _30$$16, _32$$16, _34$$25, _35$$24, _36$$24, _37$$27;
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
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_23$$17);
	ZVAL_UNDEF(&_24$$17);
	ZVAL_UNDEF(&_25$$18);
	ZVAL_UNDEF(&_26$$19);
	ZVAL_UNDEF(&_27$$19);
	ZVAL_UNDEF(&_28$$20);
	ZVAL_UNDEF(&_29$$20);
	ZVAL_UNDEF(&_30$$16);
	ZVAL_UNDEF(&_32$$16);
	ZVAL_UNDEF(&_34$$25);
	ZVAL_UNDEF(&_35$$24);
	ZVAL_UNDEF(&_36$$24);
	ZVAL_UNDEF(&_37$$27);
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
	zephir_is_iterable(&_0, 0, "phalcon/Mvc/Model.zep", 3522);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _1);
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				_2$$4 = !(zephir_array_isset_value(&columnMap, &attribute));
				if (_2$$4) {
					ZEPHIR_INIT_NVAR(&_5$$4);
					ZVAL_STRING(&_5$$4, "orm.case_insensitive_column_map");
					ZEPHIR_CALL_CE_STATIC(&_3$$4, phalcon_support_settings_ce, "get", &_4, 0, &_5$$4);
					zephir_check_call_status();
					_2$$4 = zephir_is_true(&_3$$4);
				}
				if (_2$$4) {
					ZEPHIR_CALL_SELF(&_6$$5, "caseinsensitivecolumnmap", &_7, 0, &columnMap, &attribute);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&attribute, &_6$$5);
				}
				ZEPHIR_OBS_NVAR(&attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0))) {
					ZEPHIR_INIT_NVAR(&_9$$6);
					ZVAL_STRING(&_9$$6, "orm.ignore_unknown_columns");
					ZEPHIR_CALL_CE_STATIC(&_8$$6, phalcon_support_settings_ce, "get", &_4, 0, &_9$$6);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&_8$$6))) {
						ZEPHIR_INIT_NVAR(&_10$$7);
						object_init_ex(&_10$$7, phalcon_mvc_model_exceptions_columnnotinmap_ce);
						ZEPHIR_INIT_NVAR(&_11$$7);
						zephir_get_class(&_11$$7, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_10$$7, "__construct", &_12, 0, &attribute, &_11$$7);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_10$$7, "phalcon/Mvc/Model.zep", 3480);
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
			ZEPHIR_INIT_NVAR(&_13$$3);
			zephir_camelize(&_13$$3, &attributeField, NULL );
			ZEPHIR_INIT_NVAR(&method);
			ZEPHIR_CONCAT_SV(&method, "get", &_13$$3);
			_14$$3 = ZEPHIR_IS_TRUE_IDENTICAL(useGetter);
			if (_14$$3) {
				ZEPHIR_INIT_NVAR(&_15$$3);
				ZVAL_STRING(&_15$$3, "getSource");
				_14$$3 = !ZEPHIR_IS_IDENTICAL(&_15$$3, &method);
			}
			_16$$3 = _14$$3;
			if (_16$$3) {
				_16$$3 = (zephir_method_exists(this_ptr, &method)  == SUCCESS);
			}
			if (_16$$3) {

				/* try_start_1: */

					ZEPHIR_CALL_METHOD_ZVAL(&_17$$12, this_ptr, &method, NULL, 0);
					zephir_check_call_status_or_jump(try_end_1);
					zephir_array_update_zval(&data, &attributeField, &_17$$12, PH_COPY | PH_SEPARATE);

				try_end_1:

				if (EG(exception)) {
					ZEPHIR_INIT_NVAR(&_18$$11);
					ZVAL_OBJ(&_18$$11, EG(exception));
					Z_ADDREF_P(&_18$$11);
					ZEPHIR_INIT_NVAR(&_19$$11);
					if (zephir_is_instance_of(&_18$$11, SL("Error"))) {
						zend_clear_exception();
						ZEPHIR_CPY_WRT(&_19$$11, &_18$$11);
						zephir_array_update_zval(&data, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
					}
				}
			} else if (zephir_isset_property_value_zval(this_ptr, &attributeField)) {
				ZEPHIR_OBS_NVAR(&_20$$14);
				zephir_read_property_zval(&_20$$14, this_ptr, &attributeField, PH_NOISY_CC);
				zephir_array_update_zval(&data, &attributeField, &_20$$14, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&data, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_21, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_21)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attribute, &_0, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					_22$$17 = !(zephir_array_isset_value(&columnMap, &attribute));
					if (_22$$17) {
						ZEPHIR_INIT_NVAR(&_24$$17);
						ZVAL_STRING(&_24$$17, "orm.case_insensitive_column_map");
						ZEPHIR_CALL_CE_STATIC(&_23$$17, phalcon_support_settings_ce, "get", &_4, 0, &_24$$17);
						zephir_check_call_status();
						_22$$17 = zephir_is_true(&_23$$17);
					}
					if (_22$$17) {
						ZEPHIR_CALL_SELF(&_25$$18, "caseinsensitivecolumnmap", &_7, 0, &columnMap, &attribute);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&attribute, &_25$$18);
					}
					ZEPHIR_OBS_NVAR(&attributeField);
					if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0))) {
						ZEPHIR_INIT_NVAR(&_27$$19);
						ZVAL_STRING(&_27$$19, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_26$$19, phalcon_support_settings_ce, "get", &_4, 0, &_27$$19);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_26$$19))) {
							ZEPHIR_INIT_NVAR(&_28$$20);
							object_init_ex(&_28$$20, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							ZEPHIR_INIT_NVAR(&_29$$20);
							zephir_get_class(&_29$$20, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_28$$20, "__construct", &_12, 0, &attribute, &_29$$20);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_28$$20, "phalcon/Mvc/Model.zep", 3480);
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
				ZEPHIR_INIT_NVAR(&_30$$16);
				zephir_camelize(&_30$$16, &attributeField, NULL );
				ZEPHIR_INIT_NVAR(&method);
				ZEPHIR_CONCAT_SV(&method, "get", &_30$$16);
				_31$$16 = ZEPHIR_IS_TRUE_IDENTICAL(useGetter);
				if (_31$$16) {
					ZEPHIR_INIT_NVAR(&_32$$16);
					ZVAL_STRING(&_32$$16, "getSource");
					_31$$16 = !ZEPHIR_IS_IDENTICAL(&_32$$16, &method);
				}
				_33$$16 = _31$$16;
				if (_33$$16) {
					_33$$16 = (zephir_method_exists(this_ptr, &method)  == SUCCESS);
				}
				if (_33$$16) {

					/* try_start_2: */

						ZEPHIR_CALL_METHOD_ZVAL(&_34$$25, this_ptr, &method, NULL, 0);
						zephir_check_call_status_or_jump(try_end_2);
						zephir_array_update_zval(&data, &attributeField, &_34$$25, PH_COPY | PH_SEPARATE);

					try_end_2:

					if (EG(exception)) {
						ZEPHIR_INIT_NVAR(&_35$$24);
						ZVAL_OBJ(&_35$$24, EG(exception));
						Z_ADDREF_P(&_35$$24);
						ZEPHIR_INIT_NVAR(&_36$$24);
						if (zephir_is_instance_of(&_35$$24, SL("Error"))) {
							zend_clear_exception();
							ZEPHIR_CPY_WRT(&_36$$24, &_35$$24);
							zephir_array_update_zval(&data, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
						}
					}
				} else if (zephir_isset_property_value_zval(this_ptr, &attributeField)) {
					ZEPHIR_OBS_NVAR(&_37$$27);
					zephir_read_property_zval(&_37$$27, this_ptr, &attributeField, PH_NOISY_CC);
					zephir_array_update_zval(&data, &attributeField, &_37$$27, PH_COPY | PH_SEPARATE);
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
 * Updates a model instance. If the instance does not exist in the
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
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "getreadconnection", NULL, 0);
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
			ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 7, &_6$$4, &_7$$4, &_8$$4, &_9$$4, &_5$$4);
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
	zval attribute_zv, *value, value_sub;
	zend_string *attribute = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attribute_zv);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(attribute)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	value = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&attribute_zv, attribute);
	zephir_update_property_zval_zval(this_ptr, &attribute_zv, value);
}

/**
 * Reads "belongs to" relations and check the virtual foreign keys when
 * inserting or updating records to verify that inserted/updated values are
 * present in the related entity
 */
PHP_METHOD(Phalcon_Mvc_Model, checkForeignKeysRestrict)
{
	zend_string *_7$$7, *_32$$26;
	zend_ulong _6$$7, _31$$26;
	zend_bool error = 0, validateWithNulls = 0, _14$$3, _39$$22;
	zval conditions, _16$$3, _20$$18, _41$$22, _45$$37;
	zval manager, belongsTo, foreignKey, relation, position, bindParams, extraConditions, message, fields, referencedFields, field, referencedModel, value, allowNulls, _0, *_1, _26, _2$$5, _3$$3, _15$$3, _17$$3, *_5$$7, _10$$7, _8$$8, _9$$8, _11$$10, _12$$10, _13$$12, _18$$20, _19$$18, _21$$18, _22$$18, _23$$18, _27$$24, _28$$22, _40$$22, _42$$22, *_30$$26, _35$$26, _33$$27, _34$$27, _36$$29, _37$$29, _38$$31, _43$$39, _44$$37, _46$$37, _47$$37, _48$$37, _49$$41, _50$$41, _51$$42;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_24 = NULL, *_25 = NULL, *_29 = NULL;
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
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_18$$20);
	ZVAL_UNDEF(&_19$$18);
	ZVAL_UNDEF(&_21$$18);
	ZVAL_UNDEF(&_22$$18);
	ZVAL_UNDEF(&_23$$18);
	ZVAL_UNDEF(&_27$$24);
	ZVAL_UNDEF(&_28$$22);
	ZVAL_UNDEF(&_40$$22);
	ZVAL_UNDEF(&_42$$22);
	ZVAL_UNDEF(&_35$$26);
	ZVAL_UNDEF(&_33$$27);
	ZVAL_UNDEF(&_34$$27);
	ZVAL_UNDEF(&_36$$29);
	ZVAL_UNDEF(&_37$$29);
	ZVAL_UNDEF(&_38$$31);
	ZVAL_UNDEF(&_43$$39);
	ZVAL_UNDEF(&_44$$37);
	ZVAL_UNDEF(&_46$$37);
	ZVAL_UNDEF(&_47$$37);
	ZVAL_UNDEF(&_48$$37);
	ZVAL_UNDEF(&_49$$41);
	ZVAL_UNDEF(&_50$$41);
	ZVAL_UNDEF(&_51$$42);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_20$$18);
	ZVAL_UNDEF(&_41$$22);
	ZVAL_UNDEF(&_45$$37);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&belongsTo, &manager, "getbelongsto", NULL, 0, this_ptr);
	zephir_check_call_status();
	error = 0;
	zephir_is_iterable(&belongsTo, 0, "phalcon/Mvc/Model.zep", 3751);
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
			if (zephir_array_isset_value_string(&foreignKey, SL("action"))) {
				ZEPHIR_OBS_NVAR(&_2$$5);
				zephir_array_fetch_string(&_2$$5, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 3637);
				action = zephir_get_intval(&_2$$5);
			}
			if (action != 1) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&_3$$3, &relation, "getreferencedmodel", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&referencedModel, &manager, "load", &_4, 0, &_3$$3);
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
				zephir_is_iterable(&fields, 0, "phalcon/Mvc/Model.zep", 3680);
				if (Z_TYPE_P(&fields) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _6$$7, _7$$7, _5$$7)
					{
						ZEPHIR_INIT_NVAR(&position);
						if (_7$$7 != NULL) { 
							ZVAL_STR_COPY(&position, _7$$7);
						} else {
							ZVAL_LONG(&position, _6$$7);
						}
						ZEPHIR_INIT_NVAR(&field);
						ZVAL_COPY(&field, _5$$7);
						ZEPHIR_OBS_NVAR(&value);
						zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
						zephir_array_fetch(&_8$$8, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3672);
						ZEPHIR_INIT_NVAR(&_9$$8);
						ZEPHIR_CONCAT_SVSV(&_9$$8, "[", &_8$$8, "] = ?", &position);
						zephir_array_append(&conditions, &_9$$8, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3672);
						zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3673);
						if (Z_TYPE_P(&value) == IS_NULL) {
							numberNull++;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_10$$7, &fields, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_10$$7)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&position, &fields, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&field, &fields, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_OBS_NVAR(&value);
							zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
							zephir_array_fetch(&_11$$10, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3672);
							ZEPHIR_INIT_NVAR(&_12$$10);
							ZEPHIR_CONCAT_SVSV(&_12$$10, "[", &_11$$10, "] = ?", &position);
							zephir_array_append(&conditions, &_12$$10, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3672);
							zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3673);
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
				ZEPHIR_INIT_NVAR(&_13$$12);
				ZEPHIR_CONCAT_SVS(&_13$$12, "[", &referencedFields, "] = ?0");
				zephir_array_append(&conditions, &_13$$12, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3684);
				zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3685);
				if (Z_TYPE_P(&value) == IS_NULL) {
					validateWithNulls = 1;
				}
			}
			ZEPHIR_OBS_NVAR(&extraConditions);
			if (zephir_array_isset_string_fetch(&extraConditions, &foreignKey, SL("conditions"), 0)) {
				zephir_array_append(&conditions, &extraConditions, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3696);
			}
			if (validateWithNulls) {
				ZEPHIR_OBS_NVAR(&allowNulls);
				if (zephir_array_isset_string_fetch(&allowNulls, &foreignKey, SL("allowNulls"), 0)) {
					validateWithNulls = zephir_get_boolval(&allowNulls);
				} else {
					validateWithNulls = 0;
				}
			}
			_14$$3 = !validateWithNulls;
			if (_14$$3) {
				ZEPHIR_INIT_NVAR(&_16$$3);
				zephir_create_array(&_16$$3, 2, 0);
				ZEPHIR_INIT_NVAR(&_17$$3);
				zephir_fast_join_str(&_17$$3, SL(" AND "), &conditions);
				zephir_array_fast_append(&_16$$3, &_17$$3);
				zephir_array_update_string(&_16$$3, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_15$$3, &referencedModel, "count", NULL, 0, &_16$$3);
				zephir_check_call_status();
				_14$$3 = !zephir_is_true(&_15$$3);
			}
			if (_14$$3) {
				ZEPHIR_OBS_NVAR(&message);
				if (!(zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0))) {
					ZEPHIR_INIT_NVAR(&message);
					if (Z_TYPE_P(&fields) == IS_ARRAY) {
						ZEPHIR_INIT_NVAR(&_18$$20);
						zephir_fast_join_str(&_18$$20, SL(", "), &fields);
						ZEPHIR_CONCAT_SVS(&message, "Value of fields \"", &_18$$20, "\" does not exist on referenced table");
					} else {
						ZEPHIR_CONCAT_SVS(&message, "Value of field \"", &fields, "\" does not exist on referenced table");
					}
				}
				ZEPHIR_INIT_NVAR(&_19$$18);
				object_init_ex(&_19$$18, phalcon_messages_message_ce);
				ZEPHIR_INIT_NVAR(&_20$$18);
				zephir_create_array(&_20$$18, 2, 0);
				ZEPHIR_INIT_NVAR(&_21$$18);
				zephir_get_class(&_21$$18, this_ptr, 0);
				zephir_array_update_string(&_20$$18, SL("model"), &_21$$18, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_22$$18, &relation, "getreferencedmodel", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_20$$18, SL("referenceModel"), &_22$$18, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_21$$18);
				ZVAL_STRING(&_21$$18, "ConstraintViolation");
				ZVAL_LONG(&_23$$18, 0);
				ZEPHIR_CALL_METHOD(NULL, &_19$$18, "__construct", &_24, 7, &message, &fields, &_21$$18, &_23$$18, &_20$$18);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_25, 0, &_19$$18);
				zephir_check_call_status();
				error = 1;
				break;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &belongsTo, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_26, &belongsTo, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_26)) {
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
				if (zephir_array_isset_value_string(&foreignKey, SL("action"))) {
					ZEPHIR_OBS_NVAR(&_27$$24);
					zephir_array_fetch_string(&_27$$24, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 3637);
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
					zephir_is_iterable(&fields, 0, "phalcon/Mvc/Model.zep", 3680);
					if (Z_TYPE_P(&fields) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _31$$26, _32$$26, _30$$26)
						{
							ZEPHIR_INIT_NVAR(&position);
							if (_32$$26 != NULL) { 
								ZVAL_STR_COPY(&position, _32$$26);
							} else {
								ZVAL_LONG(&position, _31$$26);
							}
							ZEPHIR_INIT_NVAR(&field);
							ZVAL_COPY(&field, _30$$26);
							ZEPHIR_OBS_NVAR(&value);
							zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
							zephir_array_fetch(&_33$$27, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3672);
							ZEPHIR_INIT_NVAR(&_34$$27);
							ZEPHIR_CONCAT_SVSV(&_34$$27, "[", &_33$$27, "] = ?", &position);
							zephir_array_append(&conditions, &_34$$27, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3672);
							zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3673);
							if (Z_TYPE_P(&value) == IS_NULL) {
								numberNull++;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_35$$26, &fields, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_35$$26)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&position, &fields, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&field, &fields, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_OBS_NVAR(&value);
								zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
								zephir_array_fetch(&_36$$29, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3672);
								ZEPHIR_INIT_NVAR(&_37$$29);
								ZEPHIR_CONCAT_SVSV(&_37$$29, "[", &_36$$29, "] = ?", &position);
								zephir_array_append(&conditions, &_37$$29, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3672);
								zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3673);
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
					zephir_array_append(&conditions, &_38$$31, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3684);
					zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3685);
					if (Z_TYPE_P(&value) == IS_NULL) {
						validateWithNulls = 1;
					}
				}
				ZEPHIR_OBS_NVAR(&extraConditions);
				if (zephir_array_isset_string_fetch(&extraConditions, &foreignKey, SL("conditions"), 0)) {
					zephir_array_append(&conditions, &extraConditions, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3696);
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
					ZEPHIR_CALL_METHOD(NULL, &_44$$37, "__construct", &_24, 7, &message, &fields, &_46$$37, &_48$$37, &_45$$37);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_25, 0, &_44$$37);
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
		ZEPHIR_INIT_VAR(&_50$$41);
		ZVAL_STRING(&_50$$41, "orm.events");
		ZEPHIR_CALL_CE_STATIC(&_49$$41, phalcon_support_settings_ce, "get", NULL, 0, &_50$$41);
		zephir_check_call_status();
		if (zephir_is_true(&_49$$41)) {
			ZEPHIR_INIT_VAR(&_51$$42);
			ZVAL_STRING(&_51$$42, "onValidationFails");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_51$$42);
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
	zend_bool _2$$3, _7$$9;
	zval manager, relations, relation, foreignKey, related, _0, *_1, _6, _3$$5, _5$$7, _8$$11, _10$$13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, action = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&foreignKey);
	ZVAL_UNDEF(&related);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_10$$13);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&relations, &manager, "gethasoneandhasmany", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(&relations, 0, "phalcon/Mvc/Model.zep", 3827);
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
			_2$$3 = Z_TYPE_P(&foreignKey) == IS_ARRAY;
			if (_2$$3) {
				_2$$3 = zephir_array_isset_value_string(&foreignKey, SL("action"));
			}
			if (_2$$3) {
				ZEPHIR_OBS_NVAR(&_3$$5);
				zephir_array_fetch_string(&_3$$5, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 3801);
				action = zephir_get_intval(&_3$$5);
			}
			if (action != 2) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&related, &manager, "getrelationrecords", &_4, 0, &relation, this_ptr);
			zephir_check_call_status();
			if (zephir_is_true(&related)) {
				ZEPHIR_CALL_METHOD(&_5$$7, &related, "delete", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_5$$7)) {
					RETURN_MM_BOOL(0);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &relations, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_6, &relations, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
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
					_7$$9 = zephir_array_isset_value_string(&foreignKey, SL("action"));
				}
				if (_7$$9) {
					ZEPHIR_OBS_NVAR(&_8$$11);
					zephir_array_fetch_string(&_8$$11, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 3801);
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
	zval _9$$7, _22$$13;
	zval manager, relations, foreignKey, relation, relationClass, fields, message, _0, *_1, _14, _4$$3, _5$$3, _6$$3, _3$$5, _8$$7, _10$$7, _11$$7, _17$$9, _18$$9, _19$$9, _16$$11, _21$$13, _23$$13, _24$$13, _25$$15, _26$$15, _27$$16;
	zend_bool error = 0, _2$$3, _15$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_12 = NULL, *_13 = NULL, *_20 = NULL;
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
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_25$$15);
	ZVAL_UNDEF(&_26$$15);
	ZVAL_UNDEF(&_27$$16);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_22$$13);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&relations, &manager, "gethasoneandhasmany", NULL, 0, this_ptr);
	zephir_check_call_status();
	error = 0;
	zephir_is_iterable(&relations, 0, "phalcon/Mvc/Model.zep", 3918);
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
			_2$$3 = Z_TYPE_P(&foreignKey) == IS_ARRAY;
			if (_2$$3) {
				_2$$3 = zephir_array_isset_value_string(&foreignKey, SL("action"));
			}
			if (_2$$3) {
				ZEPHIR_OBS_NVAR(&_3$$5);
				zephir_array_fetch_string(&_3$$5, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 3872);
				action = zephir_get_intval(&_3$$5);
			}
			if (action != 1) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&relationClass, &relation, "getreferencedmodel", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&fields, &relation, "getfields", NULL, 0);
			zephir_check_call_status();
			ZVAL_NULL(&_5$$3);
			ZEPHIR_INIT_NVAR(&_6$$3);
			ZVAL_STRING(&_6$$3, "count");
			ZEPHIR_CALL_METHOD(&_4$$3, &manager, "getrelationrecords", &_7, 0, &relation, this_ptr, &_5$$3, &_6$$3);
			zephir_check_call_status();
			if (zephir_is_true(&_4$$3)) {
				ZEPHIR_OBS_NVAR(&message);
				if (!(zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0))) {
					ZEPHIR_INIT_NVAR(&message);
					ZEPHIR_CONCAT_SV(&message, "Record is referenced by model ", &relationClass);
				}
				ZEPHIR_INIT_NVAR(&_8$$7);
				object_init_ex(&_8$$7, phalcon_messages_message_ce);
				ZEPHIR_INIT_NVAR(&_9$$7);
				zephir_create_array(&_9$$7, 2, 0);
				ZEPHIR_INIT_NVAR(&_10$$7);
				zephir_get_class(&_10$$7, this_ptr, 0);
				zephir_array_update_string(&_9$$7, SL("model"), &_10$$7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_9$$7, SL("referenceModel"), &relationClass, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_10$$7);
				ZVAL_STRING(&_10$$7, "ConstraintViolation");
				ZVAL_LONG(&_11$$7, 0);
				ZEPHIR_CALL_METHOD(NULL, &_8$$7, "__construct", &_12, 7, &message, &fields, &_10$$7, &_11$$7, &_9$$7);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_13, 0, &_8$$7);
				zephir_check_call_status();
				error = 1;
				break;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &relations, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_14, &relations, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_14)) {
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
					_15$$9 = zephir_array_isset_value_string(&foreignKey, SL("action"));
				}
				if (_15$$9) {
					ZEPHIR_OBS_NVAR(&_16$$11);
					zephir_array_fetch_string(&_16$$11, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 3872);
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
					ZEPHIR_CALL_METHOD(NULL, &_21$$13, "__construct", &_12, 7, &message, &fields, &_23$$13, &_24$$13, &_22$$13);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_13, 0, &_21$$13);
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
		ZEPHIR_INIT_VAR(&_26$$15);
		ZVAL_STRING(&_26$$15, "orm.events");
		ZEPHIR_CALL_CE_STATIC(&_25$$15, phalcon_support_settings_ce, "get", NULL, 0, &_26$$15);
		zephir_check_call_status();
		if (zephir_is_true(&_25$$15)) {
			ZEPHIR_INIT_VAR(&_27$$16);
			ZVAL_STRING(&_27$$16, "onValidationFails");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_27$$16);
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
	zend_string *_61$$64;
	zend_ulong _60$$64;
	zend_bool useExplicitIdentity = 0, _52, _10$$13, _29$$30, _46$$44, _54$$55, _63$$64;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL, *_14 = NULL, *_15 = NULL, *_21 = NULL, *_23 = NULL, *_33 = NULL, *_34 = NULL, *_40 = NULL, *_42 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *metaData, metaData_sub, *connection, connection_sub, *table = NULL, table_sub, *identityField, identityField_sub, __$null, attributeField, attributes, automaticAttributes, bindDataTypes, bindSkip, bindType, bindTypes, columnMap, defaultValue, defaultValues, field, fields, lastInsertedId, manager, rawValue, rawValues, sequenceName, schema, snapshot, source, success, unsetDefaultValues, value, values, _0, _1, _2, *_3, _24, _4$$7, _5$$7, _7$$12, _8$$12, _11$$14, _12$$14, _13$$14, _16$$17, _17$$17, _18$$19, _19$$19, _20$$19, _22$$19, _25$$24, _26$$24, _27$$29, _28$$29, _30$$31, _31$$31, _32$$31, _35$$34, _36$$34, _37$$36, _38$$36, _39$$36, _41$$36, _43$$39, _44$$42, _45$$42, _47$$50, _48$$50, _49$$54, _50$$54, _51$$54, _53$$55, _55$$55, _56$$55, _57$$63, _58$$63, *_59$$64, _62$$64, _64$$64, _65$$64;
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
	ZVAL_UNDEF(&rawValue);
	ZVAL_UNDEF(&rawValues);
	ZVAL_UNDEF(&sequenceName);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&unsetDefaultValues);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_7$$12);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_11$$14);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_16$$17);
	ZVAL_UNDEF(&_17$$17);
	ZVAL_UNDEF(&_18$$19);
	ZVAL_UNDEF(&_19$$19);
	ZVAL_UNDEF(&_20$$19);
	ZVAL_UNDEF(&_22$$19);
	ZVAL_UNDEF(&_25$$24);
	ZVAL_UNDEF(&_26$$24);
	ZVAL_UNDEF(&_27$$29);
	ZVAL_UNDEF(&_28$$29);
	ZVAL_UNDEF(&_30$$31);
	ZVAL_UNDEF(&_31$$31);
	ZVAL_UNDEF(&_32$$31);
	ZVAL_UNDEF(&_35$$34);
	ZVAL_UNDEF(&_36$$34);
	ZVAL_UNDEF(&_37$$36);
	ZVAL_UNDEF(&_38$$36);
	ZVAL_UNDEF(&_39$$36);
	ZVAL_UNDEF(&_41$$36);
	ZVAL_UNDEF(&_43$$39);
	ZVAL_UNDEF(&_44$$42);
	ZVAL_UNDEF(&_45$$42);
	ZVAL_UNDEF(&_47$$50);
	ZVAL_UNDEF(&_48$$50);
	ZVAL_UNDEF(&_49$$54);
	ZVAL_UNDEF(&_50$$54);
	ZVAL_UNDEF(&_51$$54);
	ZVAL_UNDEF(&_53$$55);
	ZVAL_UNDEF(&_55$$55);
	ZVAL_UNDEF(&_56$$55);
	ZVAL_UNDEF(&_57$$63);
	ZVAL_UNDEF(&_58$$63);
	ZVAL_UNDEF(&_62$$64);
	ZVAL_UNDEF(&_64$$64);
	ZVAL_UNDEF(&_65$$64);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("rawValues"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&rawValues, &_0);
	ZEPHIR_CALL_METHOD(&attributes, metaData, "getattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&bindDataTypes, metaData, "getbindtypes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&automaticAttributes, metaData, "getautomaticcreateattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&defaultValues, metaData, "getdefaultvalues", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "orm.column_renaming");
	ZEPHIR_CALL_CE_STATIC(&_1, phalcon_support_settings_ce, "get", NULL, 0, &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, 0, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&columnMap);
		ZVAL_NULL(&columnMap);
	}
	zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model.zep", 4046);
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _3)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _3);
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
					ZEPHIR_INIT_NVAR(&_4$$7);
					object_init_ex(&_4$$7, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
					ZEPHIR_INIT_NVAR(&_5$$7);
					zephir_get_class(&_5$$7, this_ptr, 0);
					ZEPHIR_CALL_METHOD(NULL, &_4$$7, "__construct", &_6, 0, &field, &_5$$7);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_4$$7, "phalcon/Mvc/Model.zep", 3973);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &field);
			}
			if (!(zephir_array_isset_value(&automaticAttributes, &attributeField))) {
				if (!ZEPHIR_IS_EQUAL(&field, identityField)) {
					ZEPHIR_OBS_NVAR(&rawValue);
					ZEPHIR_OBS_NVAR(&value);
					if (zephir_array_isset_fetch(&rawValue, &rawValues, &attributeField, 0)) {
						ZEPHIR_OBS_NVAR(&bindType);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0)))) {
							ZEPHIR_INIT_NVAR(&_7$$12);
							object_init_ex(&_7$$12, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
							ZEPHIR_INIT_NVAR(&_8$$12);
							zephir_get_class(&_8$$12, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_7$$12, "__construct", &_9, 0, &field, &_8$$12);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_7$$12, "phalcon/Mvc/Model.zep", 3990);
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3993);
						zephir_array_append(&values, &rawValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3994);
						zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3995);
						zephir_array_update_zval(&snapshot, &attributeField, &rawValue, PH_COPY | PH_SEPARATE);
					} else if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
						_10$$13 = Z_TYPE_P(&value) == IS_NULL;
						if (_10$$13) {
							_10$$13 = zephir_array_isset_value(&defaultValues, &field);
						}
						if (_10$$13) {
							zephir_array_fetch(&_11$$14, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3999);
							zephir_array_update_zval(&snapshot, &attributeField, &_11$$14, PH_COPY | PH_SEPARATE);
							zephir_array_fetch(&_12$$14, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4000);
							zephir_array_update_zval(&unsetDefaultValues, &attributeField, &_12$$14, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(&_13$$14, connection, "supportsdefaultvalue", &_14, 0);
							zephir_check_call_status();
							if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_13$$14))) {
								continue;
							}
							ZEPHIR_CALL_METHOD(&value, connection, "getdefaultvalue", &_15, 0);
							zephir_check_call_status();
						} else {
							zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
						}
						ZEPHIR_OBS_NVAR(&bindType);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0)))) {
							ZEPHIR_INIT_NVAR(&_16$$17);
							object_init_ex(&_16$$17, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
							ZEPHIR_INIT_NVAR(&_17$$17);
							zephir_get_class(&_17$$17, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_16$$17, "__construct", &_9, 0, &field, &_17$$17);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_16$$17, "phalcon/Mvc/Model.zep", 4015);
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4018);
						zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4019);
						zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4020);
					} else {
						if (zephir_array_isset_value(&defaultValues, &field)) {
							zephir_array_fetch(&_18$$19, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4023);
							zephir_array_update_zval(&snapshot, &attributeField, &_18$$19, PH_COPY | PH_SEPARATE);
							zephir_array_fetch(&_19$$19, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4024);
							zephir_array_update_zval(&unsetDefaultValues, &attributeField, &_19$$19, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(&_20$$19, connection, "supportsdefaultvalue", &_21, 0);
							zephir_check_call_status();
							if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_20$$19))) {
								continue;
							}
							ZEPHIR_CALL_METHOD(&_22$$19, connection, "getdefaultvalue", &_23, 0);
							zephir_check_call_status();
							zephir_array_append(&values, &_22$$19, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4030);
						} else {
							zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4032);
							zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
						}
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4036);
						zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4037);
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_24, &attributes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_24)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, &attributes, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
						ZEPHIR_INIT_NVAR(&_25$$24);
						object_init_ex(&_25$$24, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
						ZEPHIR_INIT_NVAR(&_26$$24);
						zephir_get_class(&_26$$24, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_25$$24, "__construct", &_6, 0, &field, &_26$$24);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_25$$24, "phalcon/Mvc/Model.zep", 3973);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &field);
				}
				if (!(zephir_array_isset_value(&automaticAttributes, &attributeField))) {
					if (!ZEPHIR_IS_EQUAL(&field, identityField)) {
						ZEPHIR_OBS_NVAR(&rawValue);
						ZEPHIR_OBS_NVAR(&value);
						if (zephir_array_isset_fetch(&rawValue, &rawValues, &attributeField, 0)) {
							ZEPHIR_OBS_NVAR(&bindType);
							if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0)))) {
								ZEPHIR_INIT_NVAR(&_27$$29);
								object_init_ex(&_27$$29, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
								ZEPHIR_INIT_NVAR(&_28$$29);
								zephir_get_class(&_28$$29, this_ptr, 0);
								ZEPHIR_CALL_METHOD(NULL, &_27$$29, "__construct", &_9, 0, &field, &_28$$29);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_27$$29, "phalcon/Mvc/Model.zep", 3990);
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3993);
							zephir_array_append(&values, &rawValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3994);
							zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3995);
							zephir_array_update_zval(&snapshot, &attributeField, &rawValue, PH_COPY | PH_SEPARATE);
						} else if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
							_29$$30 = Z_TYPE_P(&value) == IS_NULL;
							if (_29$$30) {
								_29$$30 = zephir_array_isset_value(&defaultValues, &field);
							}
							if (_29$$30) {
								zephir_array_fetch(&_30$$31, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3999);
								zephir_array_update_zval(&snapshot, &attributeField, &_30$$31, PH_COPY | PH_SEPARATE);
								zephir_array_fetch(&_31$$31, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4000);
								zephir_array_update_zval(&unsetDefaultValues, &attributeField, &_31$$31, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(&_32$$31, connection, "supportsdefaultvalue", &_33, 0);
								zephir_check_call_status();
								if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_32$$31))) {
									continue;
								}
								ZEPHIR_CALL_METHOD(&value, connection, "getdefaultvalue", &_34, 0);
								zephir_check_call_status();
							} else {
								zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
							}
							ZEPHIR_OBS_NVAR(&bindType);
							if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0)))) {
								ZEPHIR_INIT_NVAR(&_35$$34);
								object_init_ex(&_35$$34, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
								ZEPHIR_INIT_NVAR(&_36$$34);
								zephir_get_class(&_36$$34, this_ptr, 0);
								ZEPHIR_CALL_METHOD(NULL, &_35$$34, "__construct", &_9, 0, &field, &_36$$34);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_35$$34, "phalcon/Mvc/Model.zep", 4015);
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4018);
							zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4019);
							zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4020);
						} else {
							if (zephir_array_isset_value(&defaultValues, &field)) {
								zephir_array_fetch(&_37$$36, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4023);
								zephir_array_update_zval(&snapshot, &attributeField, &_37$$36, PH_COPY | PH_SEPARATE);
								zephir_array_fetch(&_38$$36, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4024);
								zephir_array_update_zval(&unsetDefaultValues, &attributeField, &_38$$36, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(&_39$$36, connection, "supportsdefaultvalue", &_40, 0);
								zephir_check_call_status();
								if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_39$$36))) {
									continue;
								}
								ZEPHIR_CALL_METHOD(&_41$$36, connection, "getdefaultvalue", &_42, 0);
								zephir_check_call_status();
								zephir_array_append(&values, &_41$$36, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4030);
							} else {
								zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4032);
								zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
							}
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4036);
							zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4037);
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
		ZEPHIR_CALL_METHOD(&_43$$39, connection, "useexplicitidvalue", NULL, 0);
		zephir_check_call_status();
		useExplicitIdentity = zephir_get_boolval(&_43$$39);
		if (useExplicitIdentity) {
			zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4056);
		}
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&attributeField);
			if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, identityField, 0)))) {
				ZEPHIR_INIT_VAR(&_44$$42);
				object_init_ex(&_44$$42, phalcon_mvc_model_exceptions_identitynotincolumnmap_ce);
				ZEPHIR_INIT_VAR(&_45$$42);
				zephir_get_class(&_45$$42, this_ptr, 0);
				ZEPHIR_CALL_METHOD(NULL, &_44$$42, "__construct", NULL, 0, identityField, &_45$$42);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_44$$42, "phalcon/Mvc/Model.zep", 4064);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(&attributeField, identityField);
		}
		ZEPHIR_OBS_NVAR(&value);
		if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
			_46$$44 = Z_TYPE_P(&value) == IS_NULL;
			if (!(_46$$44)) {
				_46$$44 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
			}
			if (_46$$44) {
				if (useExplicitIdentity) {
					zephir_array_append(&values, &defaultValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4076);
					zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4076);
				} else if (!(zephir_fast_count_int(&values))) {
					zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4083);
					zephir_array_append(&values, &defaultValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4084);
					zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4085);
				}
			} else {
				if (!(useExplicitIdentity)) {
					zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4093);
				}
				ZEPHIR_OBS_NVAR(&bindType);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, identityField, 0)))) {
					ZEPHIR_INIT_VAR(&_47$$50);
					object_init_ex(&_47$$50, phalcon_mvc_model_exceptions_identitynotintablecolumns_ce);
					ZEPHIR_INIT_VAR(&_48$$50);
					zephir_get_class(&_48$$50, this_ptr, 0);
					ZEPHIR_CALL_METHOD(NULL, &_47$$50, "__construct", NULL, 0, identityField, &_48$$50);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_47$$50, "phalcon/Mvc/Model.zep", 4100);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4103);
				zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4104);
			}
		} else {
			if (useExplicitIdentity) {
				zephir_array_append(&values, &defaultValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4108);
				zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4109);
			} else if (!(zephir_fast_count_int(&values))) {
				zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4116);
				zephir_array_append(&values, &defaultValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4117);
				zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4118);
			}
		}
	}
	if (Z_TYPE_P(table) == IS_ARRAY) {
		zephir_array_fetch_long(&_49$$54, table, 0, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4127);
		zephir_array_fetch_long(&_50$$54, table, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4127);
		ZEPHIR_INIT_VAR(&_51$$54);
		ZEPHIR_CONCAT_VSV(&_51$$54, &_49$$54, ".", &_50$$54);
		ZEPHIR_CPY_WRT(table, &_51$$54);
	}
	ZEPHIR_CALL_METHOD(&success, connection, "insert", NULL, 0, table, &values, &fields, &bindTypes);
	zephir_check_call_status();
	_52 = zephir_is_true(&success);
	if (_52) {
		_52 = !ZEPHIR_IS_FALSE_IDENTICAL(identityField);
	}
	if (_52) {
		ZEPHIR_INIT_VAR(&sequenceName);
		ZVAL_NULL(&sequenceName);
		ZEPHIR_CALL_METHOD(&_53$$55, connection, "supportsequences", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_53$$55)) {
			if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("getsequencename")) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(&sequenceName, this_ptr, "getsequencename", NULL, 0);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&sequenceName);
				if (ZEPHIR_IS_EMPTY(&schema)) {
					ZEPHIR_CONCAT_VSVS(&sequenceName, &source, "_", identityField, "_seq");
				} else {
					ZEPHIR_CONCAT_VSVSVS(&sequenceName, &schema, ".", &source, "_", identityField, "_seq");
				}
			}
		}
		ZEPHIR_OBS_NVAR(&value);
		zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC);
		_54$$55 = Z_TYPE_P(&value) != IS_NULL;
		if (_54$$55) {
			_54$$55 = !ZEPHIR_IS_STRING_IDENTICAL(&value, "");
		}
		if (_54$$55) {
			ZEPHIR_CPY_WRT(&lastInsertedId, &value);
		} else {
			ZEPHIR_CALL_METHOD(&lastInsertedId, connection, "lastinsertid", NULL, 0, &sequenceName);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(&_56$$55);
		ZVAL_STRING(&_56$$55, "orm.cast_last_insert_id_to_int");
		ZEPHIR_CALL_CE_STATIC(&_55$$55, phalcon_support_settings_ce, "get", NULL, 0, &_56$$55);
		zephir_check_call_status();
		if (UNEXPECTED(zephir_is_true(&_55$$55))) {
			ZVAL_LONG(&_57$$63, 10);
			ZEPHIR_CALL_FUNCTION(&_58$$63, "intval", NULL, 77, &lastInsertedId, &_57$$63);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&lastInsertedId, &_58$$63);
		}
		zephir_update_property_zval_zval(this_ptr, &attributeField, &lastInsertedId);
		zephir_array_update_zval(&snapshot, &attributeField, &lastInsertedId, PH_COPY | PH_SEPARATE);
		zephir_update_property_zval(this_ptr, ZEND_STRL("uniqueKey"), &__$null);
		zephir_update_property_zval(this_ptr, ZEND_STRL("uniqueParams"), &__$null);
	}
	if (zephir_is_true(&success)) {
		zephir_is_iterable(&unsetDefaultValues, 0, "phalcon/Mvc/Model.zep", 4200);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&unsetDefaultValues), _60$$64, _61$$64, _59$$64)
		{
			ZEPHIR_INIT_NVAR(&attributeField);
			if (_61$$64 != NULL) { 
				ZVAL_STR_COPY(&attributeField, _61$$64);
			} else {
				ZVAL_LONG(&attributeField, _60$$64);
			}
			ZEPHIR_INIT_NVAR(&defaultValue);
			ZVAL_COPY(&defaultValue, _59$$64);
			zephir_update_property_zval_zval(this_ptr, &attributeField, &defaultValue);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&defaultValue);
		ZEPHIR_INIT_NVAR(&attributeField);
		ZEPHIR_CALL_METHOD(&_62$$64, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		_63$$64 = zephir_is_true(&_62$$64);
		if (_63$$64) {
			ZEPHIR_INIT_VAR(&_65$$64);
			ZVAL_STRING(&_65$$64, "orm.update_snapshot_on_save");
			ZEPHIR_CALL_CE_STATIC(&_64$$64, phalcon_support_settings_ce, "get", NULL, 0, &_65$$64);
			zephir_check_call_status();
			_63$$64 = zephir_is_true(&_64$$64);
		}
		if (_63$$64) {
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
	zval _23$$26, _24$$26, _39$$50, _40$$50;
	zval _74;
	zend_bool changed = 0, useDynamicUpdate = 0, _3, _76, _78, _17$$20, _19$$20, _34$$44, _36$$44, _48$$64, _49$$64, _51$$64, _59$$75, _60$$75, _62$$75;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_10 = NULL, *_13 = NULL, *_16 = NULL, *_21 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *metaData, metaData_sub, *connection, connection_sub, *table = NULL, table_sub, __$null, automaticAttributes, attributeField, bindSkip, bindDataTypes, bindType, bindTypes, columnMap, dataType, dataTypes, defaultValues, field, fields, manager, nonPrimary, newSnapshot, rawValue, rawValues, success, primaryKeys, snapshot, snapshotValue, uniqueKey, uniqueParams, value, values, updateValue, _0, _1, _2, _75, _77, _79, *_4$$5, _25$$5, _5$$8, _7$$8, _8$$9, _9$$9, _11$$12, _12$$12, _14$$21, _15$$21, _18$$22, _20$$25, _22$$25, _26$$32, _27$$32, _28$$33, _29$$33, _30$$36, _31$$36, _32$$45, _33$$45, _35$$46, _37$$49, _38$$49, *_41$$55, _52$$55, _42$$58, _43$$58, _44$$59, _45$$59, _46$$62, _47$$62, _50$$64, _53$$69, _54$$69, _55$$70, _56$$70, _57$$73, _58$$73, _61$$75, _63$$80, _64$$80, *_65$$79, _68$$79, _66$$83, _67$$83, _69$$89, _70$$89, _71$$93, _72$$93, _73$$93, _80$$95, _81$$96;
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
	ZVAL_UNDEF(&defaultValues);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&nonPrimary);
	ZVAL_UNDEF(&newSnapshot);
	ZVAL_UNDEF(&rawValue);
	ZVAL_UNDEF(&rawValues);
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
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_75);
	ZVAL_UNDEF(&_77);
	ZVAL_UNDEF(&_79);
	ZVAL_UNDEF(&_25$$5);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_14$$21);
	ZVAL_UNDEF(&_15$$21);
	ZVAL_UNDEF(&_18$$22);
	ZVAL_UNDEF(&_20$$25);
	ZVAL_UNDEF(&_22$$25);
	ZVAL_UNDEF(&_26$$32);
	ZVAL_UNDEF(&_27$$32);
	ZVAL_UNDEF(&_28$$33);
	ZVAL_UNDEF(&_29$$33);
	ZVAL_UNDEF(&_30$$36);
	ZVAL_UNDEF(&_31$$36);
	ZVAL_UNDEF(&_32$$45);
	ZVAL_UNDEF(&_33$$45);
	ZVAL_UNDEF(&_35$$46);
	ZVAL_UNDEF(&_37$$49);
	ZVAL_UNDEF(&_38$$49);
	ZVAL_UNDEF(&_52$$55);
	ZVAL_UNDEF(&_42$$58);
	ZVAL_UNDEF(&_43$$58);
	ZVAL_UNDEF(&_44$$59);
	ZVAL_UNDEF(&_45$$59);
	ZVAL_UNDEF(&_46$$62);
	ZVAL_UNDEF(&_47$$62);
	ZVAL_UNDEF(&_50$$64);
	ZVAL_UNDEF(&_53$$69);
	ZVAL_UNDEF(&_54$$69);
	ZVAL_UNDEF(&_55$$70);
	ZVAL_UNDEF(&_56$$70);
	ZVAL_UNDEF(&_57$$73);
	ZVAL_UNDEF(&_58$$73);
	ZVAL_UNDEF(&_61$$75);
	ZVAL_UNDEF(&_63$$80);
	ZVAL_UNDEF(&_64$$80);
	ZVAL_UNDEF(&_68$$79);
	ZVAL_UNDEF(&_66$$83);
	ZVAL_UNDEF(&_67$$83);
	ZVAL_UNDEF(&_69$$89);
	ZVAL_UNDEF(&_70$$89);
	ZVAL_UNDEF(&_71$$93);
	ZVAL_UNDEF(&_72$$93);
	ZVAL_UNDEF(&_73$$93);
	ZVAL_UNDEF(&_80$$95);
	ZVAL_UNDEF(&_81$$96);
	ZVAL_UNDEF(&_74);
	ZVAL_UNDEF(&_23$$26);
	ZVAL_UNDEF(&_24$$26);
	ZVAL_UNDEF(&_39$$50);
	ZVAL_UNDEF(&_40$$50);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("rawValues"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&rawValues, &_0);
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
	ZEPHIR_CALL_METHOD(&defaultValues, metaData, "getdefaultvalues", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&nonPrimary, metaData, "getnonprimarykeyattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&automaticAttributes, metaData, "getautomaticupdateattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "orm.column_renaming");
	ZEPHIR_CALL_CE_STATIC(&_1, phalcon_support_settings_ce, "get", NULL, 0, &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, 0, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&columnMap);
		ZVAL_NULL(&columnMap);
	}
	_3 = useDynamicUpdate;
	if (_3) {
		_3 = Z_TYPE_P(&snapshot) == IS_ARRAY;
	}
	if (EXPECTED(_3)) {
		zephir_is_iterable(&nonPrimary, 0, "phalcon/Mvc/Model.zep", 4361);
		if (Z_TYPE_P(&nonPrimary) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&nonPrimary), _4$$5)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _4$$5);
				changed = 0;
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
						ZEPHIR_INIT_NVAR(&_7$$8);
						ZVAL_STRING(&_7$$8, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_5$$8, phalcon_support_settings_ce, "get", &_6, 0, &_7$$8);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_5$$8))) {
							ZEPHIR_INIT_NVAR(&_8$$9);
							object_init_ex(&_8$$9, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
							ZEPHIR_INIT_NVAR(&_9$$9);
							zephir_get_class(&_9$$9, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_8$$9, "__construct", &_10, 0, &field, &_9$$9);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_8$$9, "phalcon/Mvc/Model.zep", 4254);
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &field);
				}
				if (!(zephir_array_isset_value(&automaticAttributes, &attributeField))) {
					ZEPHIR_OBS_NVAR(&bindType);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0)))) {
						ZEPHIR_INIT_NVAR(&_11$$12);
						object_init_ex(&_11$$12, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
						ZEPHIR_INIT_NVAR(&_12$$12);
						zephir_get_class(&_12$$12, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_11$$12, "__construct", &_13, 0, &field, &_12$$12);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_11$$12, "phalcon/Mvc/Model.zep", 4265);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&rawValue);
					ZEPHIR_OBS_NVAR(&value);
					if (zephir_array_isset_fetch(&rawValue, &rawValues, &attributeField, 0)) {
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4272);
						zephir_array_append(&values, &rawValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4273);
						zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4274);
						zephir_array_update_zval(&newSnapshot, &attributeField, &rawValue, PH_COPY | PH_SEPARATE);
					} else if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
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
										ZEPHIR_INIT_NVAR(&_14$$21);
										object_init_ex(&_14$$21, phalcon_mvc_model_exceptions_datatypenotdefined_ce);
										ZEPHIR_INIT_NVAR(&_15$$21);
										zephir_get_class(&_15$$21, this_ptr, 0);
										ZEPHIR_CALL_METHOD(NULL, &_14$$21, "__construct", &_16, 0, &field, &_15$$21);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_14$$21, "phalcon/Mvc/Model.zep", 4298);
										ZEPHIR_MM_RESTORE();
										return;
									}
									_17$$20 = Z_TYPE_P(&snapshotValue) == IS_OBJECT;
									if (_17$$20) {
										_17$$20 = zephir_instance_of_ev(&snapshotValue, phalcon_db_rawvalue_ce);
									}
									if (_17$$20) {
										ZEPHIR_CALL_METHOD(&_18$$22, &snapshotValue, "getvalue", NULL, 0);
										zephir_check_call_status();
										ZEPHIR_CPY_WRT(&snapshotValue, &_18$$22);
									}
									ZEPHIR_CPY_WRT(&updateValue, &value);
									_19$$20 = Z_TYPE_P(&value) == IS_OBJECT;
									if (_19$$20) {
										_19$$20 = zephir_instance_of_ev(&value, phalcon_db_rawvalue_ce);
									}
									if (_19$$20) {
										ZEPHIR_CALL_METHOD(&updateValue, &value, "getvalue", NULL, 0);
										zephir_check_call_status();
									}
									do {
										if (ZEPHIR_IS_LONG(&dataType, 8)) {
											changed = zephir_get_boolval(&snapshotValue) != zephir_get_boolval(&updateValue);
											break;
										}
										if (ZEPHIR_IS_LONG(&dataType, 3) || ZEPHIR_IS_LONG(&dataType, 7)) {
											ZEPHIR_CALL_FUNCTION(&_20$$25, "floatval", &_21, 32, &snapshotValue);
											zephir_check_call_status();
											ZEPHIR_CALL_FUNCTION(&_22$$25, "floatval", &_21, 32, &updateValue);
											zephir_check_call_status();
											changed = !ZEPHIR_IS_IDENTICAL(&_20$$25, &_22$$25);
											break;
										}
										if (ZEPHIR_IS_LONG(&dataType, 0) || ZEPHIR_IS_LONG(&dataType, 1) || ZEPHIR_IS_LONG(&dataType, 2) || ZEPHIR_IS_LONG(&dataType, 4) || ZEPHIR_IS_LONG(&dataType, 5) || ZEPHIR_IS_LONG(&dataType, 6) || ZEPHIR_IS_LONG(&dataType, 2) || ZEPHIR_IS_LONG(&dataType, 14)) {
											zephir_cast_to_string(&_23$$26, &snapshotValue);
											zephir_cast_to_string(&_24$$26, &updateValue);
											changed = !ZEPHIR_IS_IDENTICAL(&_23$$26, &_24$$26);
											break;
										}
										changed = !ZEPHIR_IS_EQUAL(&updateValue, &snapshotValue);
									} while(0);

								}
							}
						}
						if (changed) {
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4348);
							zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4349);
							zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4350);
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
				ZEPHIR_CALL_METHOD(&_25$$5, &nonPrimary, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_25$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, &nonPrimary, "current", NULL, 0);
				zephir_check_call_status();
					changed = 0;
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
							ZEPHIR_INIT_NVAR(&_27$$32);
							ZVAL_STRING(&_27$$32, "orm.ignore_unknown_columns");
							ZEPHIR_CALL_CE_STATIC(&_26$$32, phalcon_support_settings_ce, "get", &_6, 0, &_27$$32);
							zephir_check_call_status();
							if (UNEXPECTED(!zephir_is_true(&_26$$32))) {
								ZEPHIR_INIT_NVAR(&_28$$33);
								object_init_ex(&_28$$33, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
								ZEPHIR_INIT_NVAR(&_29$$33);
								zephir_get_class(&_29$$33, this_ptr, 0);
								ZEPHIR_CALL_METHOD(NULL, &_28$$33, "__construct", &_10, 0, &field, &_29$$33);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_28$$33, "phalcon/Mvc/Model.zep", 4254);
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} else {
						ZEPHIR_CPY_WRT(&attributeField, &field);
					}
					if (!(zephir_array_isset_value(&automaticAttributes, &attributeField))) {
						ZEPHIR_OBS_NVAR(&bindType);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0)))) {
							ZEPHIR_INIT_NVAR(&_30$$36);
							object_init_ex(&_30$$36, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
							ZEPHIR_INIT_NVAR(&_31$$36);
							zephir_get_class(&_31$$36, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_30$$36, "__construct", &_13, 0, &field, &_31$$36);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_30$$36, "phalcon/Mvc/Model.zep", 4265);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_OBS_NVAR(&rawValue);
						ZEPHIR_OBS_NVAR(&value);
						if (zephir_array_isset_fetch(&rawValue, &rawValues, &attributeField, 0)) {
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4272);
							zephir_array_append(&values, &rawValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4273);
							zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4274);
							zephir_array_update_zval(&newSnapshot, &attributeField, &rawValue, PH_COPY | PH_SEPARATE);
						} else if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
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
											ZEPHIR_INIT_NVAR(&_32$$45);
											object_init_ex(&_32$$45, phalcon_mvc_model_exceptions_datatypenotdefined_ce);
											ZEPHIR_INIT_NVAR(&_33$$45);
											zephir_get_class(&_33$$45, this_ptr, 0);
											ZEPHIR_CALL_METHOD(NULL, &_32$$45, "__construct", &_16, 0, &field, &_33$$45);
											zephir_check_call_status();
											zephir_throw_exception_debug(&_32$$45, "phalcon/Mvc/Model.zep", 4298);
											ZEPHIR_MM_RESTORE();
											return;
										}
										_34$$44 = Z_TYPE_P(&snapshotValue) == IS_OBJECT;
										if (_34$$44) {
											_34$$44 = zephir_instance_of_ev(&snapshotValue, phalcon_db_rawvalue_ce);
										}
										if (_34$$44) {
											ZEPHIR_CALL_METHOD(&_35$$46, &snapshotValue, "getvalue", NULL, 0);
											zephir_check_call_status();
											ZEPHIR_CPY_WRT(&snapshotValue, &_35$$46);
										}
										ZEPHIR_CPY_WRT(&updateValue, &value);
										_36$$44 = Z_TYPE_P(&value) == IS_OBJECT;
										if (_36$$44) {
											_36$$44 = zephir_instance_of_ev(&value, phalcon_db_rawvalue_ce);
										}
										if (_36$$44) {
											ZEPHIR_CALL_METHOD(&updateValue, &value, "getvalue", NULL, 0);
											zephir_check_call_status();
										}
										do {
											if (ZEPHIR_IS_LONG(&dataType, 8)) {
												changed = zephir_get_boolval(&snapshotValue) != zephir_get_boolval(&updateValue);
												break;
											}
											if (ZEPHIR_IS_LONG(&dataType, 3) || ZEPHIR_IS_LONG(&dataType, 7)) {
												ZEPHIR_CALL_FUNCTION(&_37$$49, "floatval", &_21, 32, &snapshotValue);
												zephir_check_call_status();
												ZEPHIR_CALL_FUNCTION(&_38$$49, "floatval", &_21, 32, &updateValue);
												zephir_check_call_status();
												changed = !ZEPHIR_IS_IDENTICAL(&_37$$49, &_38$$49);
												break;
											}
											if (ZEPHIR_IS_LONG(&dataType, 0) || ZEPHIR_IS_LONG(&dataType, 1) || ZEPHIR_IS_LONG(&dataType, 2) || ZEPHIR_IS_LONG(&dataType, 4) || ZEPHIR_IS_LONG(&dataType, 5) || ZEPHIR_IS_LONG(&dataType, 6) || ZEPHIR_IS_LONG(&dataType, 2) || ZEPHIR_IS_LONG(&dataType, 14)) {
												zephir_cast_to_string(&_39$$50, &snapshotValue);
												zephir_cast_to_string(&_40$$50, &updateValue);
												changed = !ZEPHIR_IS_IDENTICAL(&_39$$50, &_40$$50);
												break;
											}
											changed = !ZEPHIR_IS_EQUAL(&updateValue, &snapshotValue);
										} while(0);

									}
								}
							}
							if (changed) {
								zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4348);
								zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4349);
								zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4350);
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
		zephir_is_iterable(&nonPrimary, 0, "phalcon/Mvc/Model.zep", 4426);
		if (Z_TYPE_P(&nonPrimary) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&nonPrimary), _41$$55)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _41$$55);
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
						ZEPHIR_INIT_NVAR(&_43$$58);
						ZVAL_STRING(&_43$$58, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_42$$58, phalcon_support_settings_ce, "get", &_6, 0, &_43$$58);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_42$$58))) {
							ZEPHIR_INIT_NVAR(&_44$$59);
							object_init_ex(&_44$$59, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
							ZEPHIR_INIT_NVAR(&_45$$59);
							zephir_get_class(&_45$$59, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_44$$59, "__construct", &_10, 0, &field, &_45$$59);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_44$$59, "phalcon/Mvc/Model.zep", 4377);
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &field);
				}
				if (!(zephir_array_isset_value(&automaticAttributes, &attributeField))) {
					ZEPHIR_OBS_NVAR(&bindType);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0)))) {
						ZEPHIR_INIT_NVAR(&_46$$62);
						object_init_ex(&_46$$62, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
						ZEPHIR_INIT_NVAR(&_47$$62);
						zephir_get_class(&_47$$62, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_46$$62, "__construct", &_13, 0, &field, &_47$$62);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_46$$62, "phalcon/Mvc/Model.zep", 4389);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&rawValue);
					ZEPHIR_OBS_NVAR(&value);
					if (zephir_array_isset_fetch(&rawValue, &rawValues, &attributeField, 0)) {
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4397);
						zephir_array_append(&values, &rawValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4398);
						zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4399);
						zephir_array_update_zval(&newSnapshot, &attributeField, &rawValue, PH_COPY | PH_SEPARATE);
					} else if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
						_48$$64 = Z_TYPE_P(&value) == IS_STRING;
						if (_48$$64) {
							_48$$64 = zephir_array_isset_value(&defaultValues, &field);
						}
						_49$$64 = _48$$64;
						if (_49$$64) {
							zephir_array_fetch(&_50$$64, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4408);
							_49$$64 = ZEPHIR_IS_IDENTICAL(&value, &_50$$64);
						}
						_51$$64 = _49$$64;
						if (_51$$64) {
							_51$$64 = zephir_memnstr_str(&value, SL("("), "phalcon/Mvc/Model.zep", 4408);
						}
						if (_51$$64) {
							zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
							continue;
						}
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4414);
						zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4415);
						zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4416);
						zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4420);
						zephir_array_append(&values, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4421);
						zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4422);
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &nonPrimary, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_52$$55, &nonPrimary, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_52$$55)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, &nonPrimary, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
							ZEPHIR_INIT_NVAR(&_54$$69);
							ZVAL_STRING(&_54$$69, "orm.ignore_unknown_columns");
							ZEPHIR_CALL_CE_STATIC(&_53$$69, phalcon_support_settings_ce, "get", &_6, 0, &_54$$69);
							zephir_check_call_status();
							if (UNEXPECTED(!zephir_is_true(&_53$$69))) {
								ZEPHIR_INIT_NVAR(&_55$$70);
								object_init_ex(&_55$$70, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
								ZEPHIR_INIT_NVAR(&_56$$70);
								zephir_get_class(&_56$$70, this_ptr, 0);
								ZEPHIR_CALL_METHOD(NULL, &_55$$70, "__construct", &_10, 0, &field, &_56$$70);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_55$$70, "phalcon/Mvc/Model.zep", 4377);
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} else {
						ZEPHIR_CPY_WRT(&attributeField, &field);
					}
					if (!(zephir_array_isset_value(&automaticAttributes, &attributeField))) {
						ZEPHIR_OBS_NVAR(&bindType);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0)))) {
							ZEPHIR_INIT_NVAR(&_57$$73);
							object_init_ex(&_57$$73, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
							ZEPHIR_INIT_NVAR(&_58$$73);
							zephir_get_class(&_58$$73, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_57$$73, "__construct", &_13, 0, &field, &_58$$73);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_57$$73, "phalcon/Mvc/Model.zep", 4389);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_OBS_NVAR(&rawValue);
						ZEPHIR_OBS_NVAR(&value);
						if (zephir_array_isset_fetch(&rawValue, &rawValues, &attributeField, 0)) {
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4397);
							zephir_array_append(&values, &rawValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4398);
							zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4399);
							zephir_array_update_zval(&newSnapshot, &attributeField, &rawValue, PH_COPY | PH_SEPARATE);
						} else if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
							_59$$75 = Z_TYPE_P(&value) == IS_STRING;
							if (_59$$75) {
								_59$$75 = zephir_array_isset_value(&defaultValues, &field);
							}
							_60$$75 = _59$$75;
							if (_60$$75) {
								zephir_array_fetch(&_61$$75, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4408);
								_60$$75 = ZEPHIR_IS_IDENTICAL(&value, &_61$$75);
							}
							_62$$75 = _60$$75;
							if (_62$$75) {
								_62$$75 = zephir_memnstr_str(&value, SL("("), "phalcon/Mvc/Model.zep", 4408);
							}
							if (_62$$75) {
								zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
								continue;
							}
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4414);
							zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4415);
							zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4416);
							zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
						} else {
							zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4420);
							zephir_array_append(&values, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4421);
							zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4422);
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
			ZEPHIR_INIT_VAR(&_63$$80);
			object_init_ex(&_63$$80, phalcon_mvc_model_exceptions_primarykeyrequired_ce);
			ZEPHIR_INIT_VAR(&_64$$80);
			zephir_get_class(&_64$$80, this_ptr, 0);
			ZEPHIR_CALL_METHOD(NULL, &_63$$80, "__construct", NULL, 0, &_64$$80);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_63$$80, "phalcon/Mvc/Model.zep", 4447);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&uniqueParams);
		array_init(&uniqueParams);
		zephir_is_iterable(&primaryKeys, 0, "phalcon/Mvc/Model.zep", 4472);
		if (Z_TYPE_P(&primaryKeys) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&primaryKeys), _65$$79)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _65$$79);
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
						ZEPHIR_INIT_NVAR(&_66$$83);
						object_init_ex(&_66$$83, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
						ZEPHIR_INIT_NVAR(&_67$$83);
						zephir_get_class(&_67$$83, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_66$$83, "__construct", &_10, 0, &field, &_67$$83);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_66$$83, "phalcon/Mvc/Model.zep", 4458);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &field);
				}
				ZEPHIR_OBS_NVAR(&value);
				if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
					zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
					zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4466);
				} else {
					zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
					zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4469);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &primaryKeys, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_68$$79, &primaryKeys, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_68$$79)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, &primaryKeys, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
							ZEPHIR_INIT_NVAR(&_69$$89);
							object_init_ex(&_69$$89, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
							ZEPHIR_INIT_NVAR(&_70$$89);
							zephir_get_class(&_70$$89, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_69$$89, "__construct", &_10, 0, &field, &_70$$89);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_69$$89, "phalcon/Mvc/Model.zep", 4458);
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_CPY_WRT(&attributeField, &field);
					}
					ZEPHIR_OBS_NVAR(&value);
					if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
						zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
						zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4466);
					} else {
						zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
						zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4469);
					}
				ZEPHIR_CALL_METHOD(NULL, &primaryKeys, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&field);
	}
	if (Z_TYPE_P(table) == IS_ARRAY) {
		zephir_array_fetch_long(&_71$$93, table, 0, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4478);
		zephir_array_fetch_long(&_72$$93, table, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4478);
		ZEPHIR_INIT_VAR(&_73$$93);
		ZEPHIR_CONCAT_VSV(&_73$$93, &_71$$93, ".", &_72$$93);
		ZEPHIR_CPY_WRT(table, &_73$$93);
	}
	ZEPHIR_INIT_VAR(&_74);
	zephir_create_array(&_74, 3, 0);
	zephir_array_update_string(&_74, SL("conditions"), &uniqueKey, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_74, SL("bind"), &uniqueParams, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&_75);
	zephir_read_property(&_75, this_ptr, ZEND_STRL("uniqueTypes"), PH_NOISY_CC);
	zephir_array_update_string(&_74, SL("bindTypes"), &_75, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&success, connection, "update", NULL, 0, table, &fields, &values, &_74, &bindTypes);
	zephir_check_call_status();
	_76 = zephir_is_true(&success);
	if (_76) {
		ZEPHIR_CALL_METHOD(&_77, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		_76 = zephir_is_true(&_77);
	}
	_78 = _76;
	if (_78) {
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_STRING(&_2, "orm.update_snapshot_on_save");
		ZEPHIR_CALL_CE_STATIC(&_79, phalcon_support_settings_ce, "get", &_6, 0, &_2);
		zephir_check_call_status();
		_78 = zephir_is_true(&_79);
	}
	if (_78) {
		if (Z_TYPE_P(&snapshot) == IS_ARRAY) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("oldSnapshot"), &snapshot);
			ZEPHIR_INIT_VAR(&_80$$95);
			zephir_fast_array_merge(&_80$$95, &snapshot, &newSnapshot);
			zephir_update_property_zval(this_ptr, ZEND_STRL("snapshot"), &_80$$95);
		} else {
			ZEPHIR_INIT_VAR(&_81$$96);
			array_init(&_81$$96);
			zephir_update_property_zval(this_ptr, ZEND_STRL("oldSnapshot"), &_81$$96);
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
	zephir_fcall_cache_entry *_6 = NULL, *_10 = NULL, *_12 = NULL, *_21 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberEmpty = 0, numberPrimary = 0;
	zval *metaData, metaData_sub, *connection, connection_sub, __$null, attributeField, bindDataTypes, columnMap, field, joinWhere, num, primaryKeys, schema, source, table, type, uniqueKey, uniqueParams, uniqueTypes, value, wherePk, _0, _26, _27, _28, _29, _1$$3, _2$$3, *_3$$3, _14$$3, _4$$9, _5$$9, _8$$14, _9$$14, _11$$7, _13$$7, _15$$17, _16$$17, _18$$22, _19$$22, _20$$15, _22$$15, _23$$25, _24$$26, _25$$27, _30$$30, _31$$31;
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
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_8$$14);
	ZVAL_UNDEF(&_9$$14);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_15$$17);
	ZVAL_UNDEF(&_16$$17);
	ZVAL_UNDEF(&_18$$22);
	ZVAL_UNDEF(&_19$$22);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_23$$25);
	ZVAL_UNDEF(&_24$$26);
	ZVAL_UNDEF(&_25$$27);
	ZVAL_UNDEF(&_30$$30);
	ZVAL_UNDEF(&_31$$31);
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
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "orm.column_renaming");
		ZEPHIR_CALL_CE_STATIC(&_1$$3, phalcon_support_settings_ce, "get", NULL, 0, &_2$$3);
		zephir_check_call_status();
		if (zephir_is_true(&_1$$3)) {
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
		zephir_is_iterable(&primaryKeys, 0, "phalcon/Mvc/Model.zep", 4598);
		if (Z_TYPE_P(&primaryKeys) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&primaryKeys), _3$$3)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _3$$3);
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
						ZEPHIR_INIT_NVAR(&_4$$9);
						object_init_ex(&_4$$9, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
						ZEPHIR_INIT_NVAR(&_5$$9);
						zephir_get_class(&_5$$9, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_4$$9, "__construct", &_6, 0, &field, &_5$$9);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_4$$9, "phalcon/Mvc/Model.zep", 4559);
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
					zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4580);
				} else {
					zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4582);
					numberEmpty++;
				}
				ZEPHIR_OBS_NVAR(&type);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&type, &bindDataTypes, &field, 0)))) {
					ZEPHIR_INIT_NVAR(&_8$$14);
					object_init_ex(&_8$$14, phalcon_mvc_model_exceptions_columnnotintablecolumns_ce);
					ZEPHIR_INIT_NVAR(&_9$$14);
					zephir_get_class(&_9$$14, this_ptr, 0);
					ZEPHIR_CALL_METHOD(NULL, &_8$$14, "__construct", &_10, 0, &field, &_9$$14);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_8$$14, "phalcon/Mvc/Model.zep", 4587);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&uniqueTypes, &type, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4590);
				ZEPHIR_CALL_METHOD(&_11$$7, connection, "escapeidentifier", &_12, 0, &field);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$7);
				ZEPHIR_CONCAT_VS(&_13$$7, &_11$$7, " = ?");
				zephir_array_append(&wherePk, &_13$$7, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4591);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &primaryKeys, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_14$$3, &primaryKeys, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_14$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, &primaryKeys, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
							ZEPHIR_INIT_NVAR(&_15$$17);
							object_init_ex(&_15$$17, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
							ZEPHIR_INIT_NVAR(&_16$$17);
							zephir_get_class(&_16$$17, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_15$$17, "__construct", &_6, 0, &field, &_16$$17);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_15$$17, "phalcon/Mvc/Model.zep", 4559);
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
						zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4580);
					} else {
						zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4582);
						numberEmpty++;
					}
					ZEPHIR_OBS_NVAR(&type);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&type, &bindDataTypes, &field, 0)))) {
						ZEPHIR_INIT_NVAR(&_18$$22);
						object_init_ex(&_18$$22, phalcon_mvc_model_exceptions_columnnotintablecolumns_ce);
						ZEPHIR_INIT_NVAR(&_19$$22);
						zephir_get_class(&_19$$22, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_18$$22, "__construct", &_10, 0, &field, &_19$$22);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_18$$22, "phalcon/Mvc/Model.zep", 4587);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&uniqueTypes, &type, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4590);
					ZEPHIR_CALL_METHOD(&_20$$15, connection, "escapeidentifier", &_21, 0, &field);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_22$$15);
					ZEPHIR_CONCAT_VS(&_22$$15, &_20$$15, " = ?");
					zephir_array_append(&wherePk, &_22$$15, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4591);
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
		zephir_read_property(&_23$$25, this_ptr, ZEND_STRL("uniqueKey"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&uniqueKey, &_23$$25);
	}
	if (Z_TYPE_P(&uniqueParams) == IS_NULL) {
		zephir_read_property(&_24$$26, this_ptr, ZEND_STRL("uniqueParams"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&uniqueParams, &_24$$26);
	}
	if (Z_TYPE_P(&uniqueTypes) == IS_NULL) {
		zephir_read_property(&_25$$27, this_ptr, ZEND_STRL("uniqueTypes"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&uniqueTypes, &_25$$27);
	}
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	ZEPHIR_CALL_METHOD(&_26, connection, "escapeidentifier", NULL, 0, &table);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_27);
	ZEPHIR_CONCAT_SVSV(&_27, "SELECT COUNT(*) \"rowcount\" FROM ", &_26, " WHERE ", &uniqueKey);
	ZVAL_NULL(&_28);
	ZEPHIR_CALL_METHOD(&num, connection, "fetchone", NULL, 0, &_27, &_28, &uniqueParams, &uniqueTypes);
	zephir_check_call_status();
	zephir_array_fetch_string(&_29, &num, SL("rowcount"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4652);
	if (zephir_is_true(&_29)) {
		ZVAL_UNDEF(&_30$$30);
		ZVAL_LONG(&_30$$30, 0);
		zephir_update_property_zval(this_ptr, ZEND_STRL("dirtyState"), &_30$$30);
		RETURN_MM_BOOL(1);
	} else {
		ZVAL_UNDEF(&_31$$31);
		ZVAL_LONG(&_31$$31, 1);
		zephir_update_property_zval(this_ptr, ZEND_STRL("dirtyState"), &_31$$31);
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
	zval modelName_zv, method_zv, *arguments_param = NULL, manager, relation, queryMethod, extraArgs, alias, _0, _1$$3, _2$$3, _3$$5, _4$$5, _5$$5;
	zend_string *modelName = NULL, *method = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelName_zv);
	ZVAL_UNDEF(&method_zv);
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
		ZEPHIR_Z_PARAM_ARRAY(arguments, arguments_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	arguments_param = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&modelName_zv);
	ZVAL_STR_COPY(&modelName_zv, modelName);
	zephir_memory_observe(&method_zv);
	ZVAL_STR_COPY(&method_zv, method);
	ZEPHIR_OBS_COPY_OR_DUP(&arguments, arguments_param);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_INIT_VAR(&relation);
	ZVAL_BOOL(&relation, 0);
	ZEPHIR_INIT_VAR(&queryMethod);
	ZVAL_NULL(&queryMethod);
	zephir_memory_observe(&extraArgs);
	zephir_array_isset_long_fetch(&extraArgs, &arguments, 0, 0);
	if (zephir_start_with_str(&method_zv, SL("get"))) {
		ZVAL_LONG(&_1$$3, 3);
		ZEPHIR_INIT_VAR(&alias);
		zephir_substr(&alias, &method_zv, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_METHOD(&_2$$3, &manager, "getrelationbyalias", NULL, 0, &modelName_zv, &alias);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_2$$3);
		if (Z_TYPE_P(&relation) != IS_OBJECT) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrelated", NULL, 0, &alias, &extraArgs);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_start_with_str(&method_zv, SL("count"))) {
		ZEPHIR_INIT_NVAR(&queryMethod);
		ZVAL_STRING(&queryMethod, "count");
		ZVAL_LONG(&_4$$5, 5);
		ZEPHIR_INIT_VAR(&_5$$5);
		zephir_substr(&_5$$5, &method_zv, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_METHOD(&_3$$5, &manager, "getrelationbyalias", NULL, 0, &modelName_zv, &_5$$5);
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
	zval functionName_zv, alias_zv, *parameters = NULL, parameters_sub, __$null, params, distinctColumn, groupColumn, columns, resultset, cache, firstRow, groupColumns, builder, query, container, manager, transaction, bindParams, bindTypes, _0, _1, _2;
	zend_string *functionName = NULL, *alias = NULL;

	ZVAL_UNDEF(&functionName_zv);
	ZVAL_UNDEF(&alias_zv);
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
	if (ZEND_NUM_ARGS() > 2) {
		parameters = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&functionName_zv);
	ZVAL_STR_COPY(&functionName_zv, functionName);
	zephir_memory_observe(&alias_zv);
	ZVAL_STR_COPY(&alias_zv, alias);
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
			zephir_array_append(&params, parameters, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4757);
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
		ZEPHIR_CONCAT_VSVSV(&columns, &functionName_zv, "(DISTINCT ", &distinctColumn, ") AS ", &alias_zv);
	} else {
		zephir_memory_observe(&groupColumns);
		ZEPHIR_INIT_NVAR(&columns);
		if (zephir_array_isset_string_fetch(&groupColumns, &params, SL("group"), 0)) {
			ZEPHIR_CONCAT_VSVSVSV(&columns, &groupColumns, ", ", &functionName_zv, "(", &groupColumn, ") AS ", &alias_zv);
		} else {
			ZEPHIR_CONCAT_VSVSV(&columns, &functionName_zv, "(", &groupColumn, ") AS ", &alias_zv);
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
	if (zephir_array_isset_value_string(&params, SL("bind"))) {
		ZEPHIR_OBS_NVAR(&bindParams);
		zephir_array_fetch_string(&bindParams, &params, SL("bind"), PH_NOISY, "phalcon/Mvc/Model.zep", 4800);
		if (zephir_array_isset_value_string(&params, SL("bindTypes"))) {
			ZEPHIR_OBS_NVAR(&bindTypes);
			zephir_array_fetch_string(&bindTypes, &params, SL("bindTypes"), PH_NOISY, "phalcon/Mvc/Model.zep", 4803);
		}
	}
	zephir_memory_observe(&cache);
	if (zephir_array_isset_string_fetch(&cache, &params, SL("cache"), 0)) {
		ZEPHIR_CALL_METHOD(NULL, &query, "cache", NULL, 0, &cache);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&resultset, &query, "execute", NULL, 0, &bindParams, &bindTypes);
	zephir_check_call_status();
	if (zephir_array_isset_value_string(&params, SL("group"))) {
		RETURN_CCTOR(&resultset);
	}
	ZEPHIR_CALL_METHOD(&firstRow, &resultset, "getfirst", NULL, 0);
	zephir_check_call_status();
	zephir_memory_observe(&_2);
	zephir_read_property_zval(&_2, &firstRow, &alias_zv, PH_NOISY_CC);
	RETURN_CCTOR(&_2);
}

/**
 * Try to check if the query must invoke a finder
 *
 * @return ModelInterface[]|ModelInterface|bool
 */
PHP_METHOD(Phalcon_Mvc_Model, invokeFinder)
{
	zend_class_entry *_14;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments, _10$$14;
	zval method_zv, *arguments_param = NULL, extraMethod, type, modelName, value, model, attributes, field, extraMethodFirst, metaData, params, _3, _13, _0$$3, _1$$4, _2$$5, _4$$7, _5$$7, _6$$13, _7$$13, _8$$14, _9$$14, _11$$15, _12$$15;
	zend_string *method = NULL;

	ZVAL_UNDEF(&method_zv);
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
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$13);
	ZVAL_UNDEF(&_7$$13);
	ZVAL_UNDEF(&_8$$14);
	ZVAL_UNDEF(&_9$$14);
	ZVAL_UNDEF(&_11$$15);
	ZVAL_UNDEF(&_12$$15);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&_10$$14);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(method)
		ZEPHIR_Z_PARAM_ARRAY(arguments, arguments_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	arguments_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&method_zv);
	ZVAL_STR_COPY(&method_zv, method);
	zephir_get_arrval(&arguments, arguments_param);
	ZEPHIR_INIT_VAR(&extraMethod);
	ZVAL_NULL(&extraMethod);
	if (zephir_start_with_str(&method_zv, SL("findFirstBy"))) {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_STRING(&type, "findFirst");
		ZVAL_LONG(&_0$$3, 11);
		ZEPHIR_INIT_NVAR(&extraMethod);
		zephir_substr(&extraMethod, &method_zv, 11 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	} else if (zephir_start_with_str(&method_zv, SL("findBy"))) {
		ZEPHIR_INIT_NVAR(&type);
		ZVAL_STRING(&type, "find");
		ZVAL_LONG(&_1$$4, 6);
		ZEPHIR_INIT_NVAR(&extraMethod);
		zephir_substr(&extraMethod, &method_zv, 6 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	} else if (zephir_start_with_str(&method_zv, SL("countBy"))) {
		ZEPHIR_INIT_NVAR(&type);
		ZVAL_STRING(&type, "count");
		ZVAL_LONG(&_2$$5, 7);
		ZEPHIR_INIT_NVAR(&extraMethod);
		zephir_substr(&extraMethod, &method_zv, 7 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	}
	ZEPHIR_INIT_VAR(&modelName);
	zephir_get_called_class(&modelName);
	if (!(zephir_is_true(&extraMethod))) {
		RETURN_MM_BOOL(0);
	}
	ZVAL_LONG(&_3, 0);
	if (UNEXPECTED(!(zephir_array_key_exists(&arguments, &_3)))) {
		ZEPHIR_INIT_VAR(&_4$$7);
		object_init_ex(&_4$$7, phalcon_mvc_model_exceptions_staticmethodrequiresoneargument_ce);
		ZEPHIR_INIT_VAR(&_5$$7);
		zephir_get_called_class(&_5$$7);
		ZEPHIR_CALL_METHOD(NULL, &_4$$7, "__construct", NULL, 0, &method_zv, &_5$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$7, "phalcon/Mvc/Model.zep", 4880);
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
	if (zephir_array_isset_value(&attributes, &extraMethod)) {
		ZEPHIR_CPY_WRT(&field, &extraMethod);
	} else {
		ZEPHIR_CALL_FUNCTION(&extraMethodFirst, "lcfirst", NULL, 138, &extraMethod);
		zephir_check_call_status();
		if (zephir_array_isset_value(&attributes, &extraMethodFirst)) {
			ZEPHIR_CPY_WRT(&field, &extraMethodFirst);
		} else {
			ZEPHIR_INIT_NVAR(&field);
			zephir_uncamelize(&field, &extraMethod, NULL );
			if (UNEXPECTED(!(zephir_array_isset_value(&attributes, &field)))) {
				ZEPHIR_INIT_VAR(&_6$$13);
				object_init_ex(&_6$$13, phalcon_mvc_model_exceptions_cannotresolveattribute_ce);
				ZEPHIR_INIT_VAR(&_7$$13);
				zephir_get_called_class(&_7$$13);
				ZEPHIR_CALL_METHOD(NULL, &_6$$13, "__construct", NULL, 0, &extraMethod, &_7$$13);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_6$$13, "phalcon/Mvc/Model.zep", 4915);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	zephir_memory_observe(&value);
	zephir_array_isset_long_fetch(&value, &arguments, 0, 0);
	ZEPHIR_INIT_VAR(&params);
	if (Z_TYPE_P(&value) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_8$$14);
		zephir_create_array(&_8$$14, 2, 0);
		ZEPHIR_INIT_VAR(&_9$$14);
		ZEPHIR_CONCAT_SVS(&_9$$14, "[", &field, "] = ?0");
		zephir_array_update_string(&_8$$14, SL("conditions"), &_9$$14, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_10$$14);
		zephir_create_array(&_10$$14, 1, 0);
		zephir_array_fast_append(&_10$$14, &value);
		zephir_array_update_string(&_8$$14, SL("bind"), &_10$$14, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&params, &_8$$14);
	} else {
		ZEPHIR_INIT_VAR(&_11$$15);
		zephir_create_array(&_11$$15, 1, 0);
		ZEPHIR_INIT_VAR(&_12$$15);
		ZEPHIR_CONCAT_SVS(&_12$$15, "[", &field, "] IS NULL");
		zephir_array_update_string(&_11$$15, SL("conditions"), &_12$$15, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&params, &_11$$15);
	}
	zephir_array_unset_long(&arguments, 0, PH_SEPARATE);
	zephir_array_unset_string(&arguments, SL("conditions"), PH_SEPARATE);
	zephir_array_unset_string(&arguments, SL("bind"), PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_13);
	zephir_fast_array_merge(&_13, &params, &arguments);
	ZEPHIR_CPY_WRT(&params, &_13);
	_14 = zephir_fetch_class(&modelName);
	ZEPHIR_RETURN_CALL_CE_STATIC_ZVAL(_14, type, NULL, 0, &params);
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
	zval property_zv, *value, value_sub, possibleSetter, _0, _1, _2;
	zend_string *property = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property_zv);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&possibleSetter);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&localMethods);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(property)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	value = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&property_zv);
	ZVAL_STR_COPY(&property_zv, property);
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
	zephir_camelize(&_0, &property_zv, NULL );
	ZEPHIR_INIT_VAR(&possibleSetter);
	ZEPHIR_CONCAT_SV(&possibleSetter, "set", &_0);
	if (!((zephir_method_exists(this_ptr, &possibleSetter)  == SUCCESS))) {
		RETURN_MM_BOOL(0);
	}
	if (zephir_array_isset_value(&localMethods, &possibleSetter)) {
		RETURN_MM_BOOL(0);
	}

	/* try_start_1: */

		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &possibleSetter, NULL, 0, value);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_1);
		ZVAL_OBJ(&_1, EG(exception));
		Z_ADDREF_P(&_1);
		ZEPHIR_INIT_VAR(&_2);
		if (zephir_is_instance_of(&_1, SL("TypeError"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&_2, &_1);
			zephir_update_property_zval_zval(this_ptr, &property_zv, value);
		}
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
	zval _23$$32, _38$$52;
	zval eventName;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL, *_16 = NULL, *_26 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool exists, error = 0, isNull = 0, _17$$27, _18$$27, _19$$27, _32$$47, _33$$47, _34$$47;
	zval *metaData, metaData_sub, *exists_param = NULL, *identityField, identityField_sub, __$true, __$false, notNull, columnMap, dataTypeNumeric, automaticAttributes, defaultValues, field, attributeField, value, emptyStringValues, _0, _1, _5, _7, _44, _48, _2$$3, _3$$3, _4$$3, _6$$8, _8$$11, _9$$11, *_10$$11, _27$$11, _11$$18, _13$$18, _14$$19, _15$$19, _20$$27, _21$$32, _22$$32, _24$$32, _25$$32, _28$$38, _29$$38, _30$$39, _31$$39, _35$$47, _36$$52, _37$$52, _39$$52, _40$$52, _41$$56, _42$$56, _43$$57, _45$$58, _46$$58, _47$$59, _49$$60, _50$$60, _51$$60, _52$$60, _53$$60, _54$$60;
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
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_44);
	ZVAL_UNDEF(&_48);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_27$$11);
	ZVAL_UNDEF(&_11$$18);
	ZVAL_UNDEF(&_13$$18);
	ZVAL_UNDEF(&_14$$19);
	ZVAL_UNDEF(&_15$$19);
	ZVAL_UNDEF(&_20$$27);
	ZVAL_UNDEF(&_21$$32);
	ZVAL_UNDEF(&_22$$32);
	ZVAL_UNDEF(&_24$$32);
	ZVAL_UNDEF(&_25$$32);
	ZVAL_UNDEF(&_28$$38);
	ZVAL_UNDEF(&_29$$38);
	ZVAL_UNDEF(&_30$$39);
	ZVAL_UNDEF(&_31$$39);
	ZVAL_UNDEF(&_35$$47);
	ZVAL_UNDEF(&_36$$52);
	ZVAL_UNDEF(&_37$$52);
	ZVAL_UNDEF(&_39$$52);
	ZVAL_UNDEF(&_40$$52);
	ZVAL_UNDEF(&_41$$56);
	ZVAL_UNDEF(&_42$$56);
	ZVAL_UNDEF(&_43$$57);
	ZVAL_UNDEF(&_45$$58);
	ZVAL_UNDEF(&_46$$58);
	ZVAL_UNDEF(&_47$$59);
	ZVAL_UNDEF(&_49$$60);
	ZVAL_UNDEF(&_50$$60);
	ZVAL_UNDEF(&_51$$60);
	ZVAL_UNDEF(&_52$$60);
	ZVAL_UNDEF(&_53$$60);
	ZVAL_UNDEF(&_54$$60);
	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&_23$$32);
	ZVAL_UNDEF(&_38$$52);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(metaData, phalcon_mvc_model_metadatainterface_ce)
		Z_PARAM_BOOL(exists)
		Z_PARAM_ZVAL(identityField)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &metaData, &exists_param, &identityField);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "orm.events");
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_support_settings_ce, "get", NULL, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "beforeValidation");
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "fireeventcancel", NULL, 0, &_3$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_2$$3)) {
			RETURN_MM_BOOL(0);
		}
		if (exists) {
			ZEPHIR_INIT_VAR(&eventName);
			ZVAL_STRING(&eventName, "beforeValidationOnUpdate");
		} else {
			ZEPHIR_INIT_NVAR(&eventName);
			ZVAL_STRING(&eventName, "beforeValidationOnCreate");
		}
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "fireeventcancel", NULL, 0, &eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_4$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "orm.virtual_foreign_keys");
	ZEPHIR_CALL_CE_STATIC(&_5, phalcon_support_settings_ce, "get", NULL, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_5)) {
		ZEPHIR_CALL_METHOD(&_6$$8, this_ptr, "checkforeignkeysrestrict", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_6$$8)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "orm.not_null_validations");
	ZEPHIR_CALL_CE_STATIC(&_7, phalcon_support_settings_ce, "get", NULL, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_7)) {
		ZEPHIR_CALL_METHOD(&notNull, metaData, "getnotnullattributes", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (Z_TYPE_P(&notNull) == IS_ARRAY) {
			ZEPHIR_CALL_METHOD(&dataTypeNumeric, metaData, "getdatatypesnumeric", NULL, 0, this_ptr);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_9$$11);
			ZVAL_STRING(&_9$$11, "orm.column_renaming");
			ZEPHIR_CALL_CE_STATIC(&_8$$11, phalcon_support_settings_ce, "get", NULL, 0, &_9$$11);
			zephir_check_call_status();
			if (zephir_is_true(&_8$$11)) {
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
			zephir_is_iterable(&notNull, 0, "phalcon/Mvc/Model.zep", 5160);
			if (Z_TYPE_P(&notNull) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&notNull), _10$$11)
				{
					ZEPHIR_INIT_NVAR(&field);
					ZVAL_COPY(&field, _10$$11);
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
							ZEPHIR_INIT_NVAR(&_13$$18);
							ZVAL_STRING(&_13$$18, "orm.ignore_unknown_columns");
							ZEPHIR_CALL_CE_STATIC(&_11$$18, phalcon_support_settings_ce, "get", &_12, 0, &_13$$18);
							zephir_check_call_status();
							if (UNEXPECTED(!zephir_is_true(&_11$$18))) {
								ZEPHIR_INIT_NVAR(&_14$$19);
								object_init_ex(&_14$$19, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
								ZEPHIR_INIT_NVAR(&_15$$19);
								zephir_get_class(&_15$$19, this_ptr, 0);
								ZEPHIR_CALL_METHOD(NULL, &_14$$19, "__construct", &_16, 0, &field, &_15$$19);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_14$$19, "phalcon/Mvc/Model.zep", 5080);
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} else {
						ZEPHIR_CPY_WRT(&attributeField, &field);
					}
					if (!(zephir_array_isset_value(&automaticAttributes, &attributeField))) {
						isNull = 0;
						ZEPHIR_OBS_NVAR(&value);
						if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
							if (Z_TYPE_P(&value) != IS_OBJECT) {
								if (!(zephir_array_isset_value(&dataTypeNumeric, &field))) {
									if (zephir_array_isset_value(&emptyStringValues, &field)) {
										if (Z_TYPE_P(&value) == IS_NULL) {
											isNull = 1;
										}
									} else {
										_17$$27 = Z_TYPE_P(&value) == IS_NULL;
										if (!(_17$$27)) {
											_18$$27 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
											if (_18$$27) {
												_19$$27 = !(zephir_array_isset_value(&defaultValues, &field));
												if (!(_19$$27)) {
													zephir_array_fetch(&_20$$27, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 5110);
													_19$$27 = !ZEPHIR_IS_IDENTICAL(&value, &_20$$27);
												}
												_18$$27 = _19$$27;
											}
											_17$$27 = _18$$27;
										}
										if (_17$$27) {
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
								if (zephir_array_isset_value(&defaultValues, &field)) {
									continue;
								}
							}
							ZEPHIR_INIT_NVAR(&_21$$32);
							object_init_ex(&_21$$32, phalcon_messages_message_ce);
							ZEPHIR_INIT_NVAR(&_22$$32);
							ZEPHIR_CONCAT_VS(&_22$$32, &attributeField, " is required");
							ZEPHIR_INIT_NVAR(&_23$$32);
							zephir_create_array(&_23$$32, 1, 0);
							ZEPHIR_INIT_NVAR(&_24$$32);
							zephir_get_class(&_24$$32, this_ptr, 0);
							zephir_array_update_string(&_23$$32, SL("model"), &_24$$32, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_24$$32);
							ZVAL_STRING(&_24$$32, "PresenceOf");
							ZVAL_LONG(&_25$$32, 0);
							ZEPHIR_CALL_METHOD(NULL, &_21$$32, "__construct", &_26, 7, &_22$$32, &attributeField, &_24$$32, &_25$$32, &_23$$32);
							zephir_check_call_status();
							zephir_update_property_array_append(this_ptr, SL("errorMessages"), &_21$$32);
							error = 1;
						}
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &notNull, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_27$$11, &notNull, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_27$$11)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&field, &notNull, "current", NULL, 0);
					zephir_check_call_status();
						if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
							ZEPHIR_OBS_NVAR(&attributeField);
							if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
								ZEPHIR_INIT_NVAR(&_29$$38);
								ZVAL_STRING(&_29$$38, "orm.ignore_unknown_columns");
								ZEPHIR_CALL_CE_STATIC(&_28$$38, phalcon_support_settings_ce, "get", &_12, 0, &_29$$38);
								zephir_check_call_status();
								if (UNEXPECTED(!zephir_is_true(&_28$$38))) {
									ZEPHIR_INIT_NVAR(&_30$$39);
									object_init_ex(&_30$$39, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
									ZEPHIR_INIT_NVAR(&_31$$39);
									zephir_get_class(&_31$$39, this_ptr, 0);
									ZEPHIR_CALL_METHOD(NULL, &_30$$39, "__construct", &_16, 0, &field, &_31$$39);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_30$$39, "phalcon/Mvc/Model.zep", 5080);
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
						} else {
							ZEPHIR_CPY_WRT(&attributeField, &field);
						}
						if (!(zephir_array_isset_value(&automaticAttributes, &attributeField))) {
							isNull = 0;
							ZEPHIR_OBS_NVAR(&value);
							if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
								if (Z_TYPE_P(&value) != IS_OBJECT) {
									if (!(zephir_array_isset_value(&dataTypeNumeric, &field))) {
										if (zephir_array_isset_value(&emptyStringValues, &field)) {
											if (Z_TYPE_P(&value) == IS_NULL) {
												isNull = 1;
											}
										} else {
											_32$$47 = Z_TYPE_P(&value) == IS_NULL;
											if (!(_32$$47)) {
												_33$$47 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
												if (_33$$47) {
													_34$$47 = !(zephir_array_isset_value(&defaultValues, &field));
													if (!(_34$$47)) {
														zephir_array_fetch(&_35$$47, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 5110);
														_34$$47 = !ZEPHIR_IS_IDENTICAL(&value, &_35$$47);
													}
													_33$$47 = _34$$47;
												}
												_32$$47 = _33$$47;
											}
											if (_32$$47) {
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
									if (zephir_array_isset_value(&defaultValues, &field)) {
										continue;
									}
								}
								ZEPHIR_INIT_NVAR(&_36$$52);
								object_init_ex(&_36$$52, phalcon_messages_message_ce);
								ZEPHIR_INIT_NVAR(&_37$$52);
								ZEPHIR_CONCAT_VS(&_37$$52, &attributeField, " is required");
								ZEPHIR_INIT_NVAR(&_38$$52);
								zephir_create_array(&_38$$52, 1, 0);
								ZEPHIR_INIT_NVAR(&_39$$52);
								zephir_get_class(&_39$$52, this_ptr, 0);
								zephir_array_update_string(&_38$$52, SL("model"), &_39$$52, PH_COPY | PH_SEPARATE);
								ZEPHIR_INIT_NVAR(&_39$$52);
								ZVAL_STRING(&_39$$52, "PresenceOf");
								ZVAL_LONG(&_40$$52, 0);
								ZEPHIR_CALL_METHOD(NULL, &_36$$52, "__construct", &_26, 7, &_37$$52, &attributeField, &_39$$52, &_40$$52, &_38$$52);
								zephir_check_call_status();
								zephir_update_property_array_append(this_ptr, SL("errorMessages"), &_36$$52);
								error = 1;
							}
						}
					ZEPHIR_CALL_METHOD(NULL, &notNull, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&field);
			if (error) {
				ZEPHIR_INIT_VAR(&_42$$56);
				ZVAL_STRING(&_42$$56, "orm.events");
				ZEPHIR_CALL_CE_STATIC(&_41$$56, phalcon_support_settings_ce, "get", &_12, 0, &_42$$56);
				zephir_check_call_status();
				if (zephir_is_true(&_41$$56)) {
					ZEPHIR_INIT_VAR(&_43$$57);
					ZVAL_STRING(&_43$$57, "onValidationFails");
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_43$$57);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "canceloperation", NULL, 0);
					zephir_check_call_status();
				}
				RETURN_MM_BOOL(0);
			}
		}
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "validation");
	ZEPHIR_CALL_METHOD(&_44, this_ptr, "fireeventcancel", NULL, 0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_44)) {
		ZEPHIR_INIT_VAR(&_46$$58);
		ZVAL_STRING(&_46$$58, "orm.events");
		ZEPHIR_CALL_CE_STATIC(&_45$$58, phalcon_support_settings_ce, "get", &_12, 0, &_46$$58);
		zephir_check_call_status();
		if (zephir_is_true(&_45$$58)) {
			ZEPHIR_INIT_VAR(&_47$$59);
			ZVAL_STRING(&_47$$59, "onValidationFails");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_47$$59);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "orm.events");
	ZEPHIR_CALL_CE_STATIC(&_48, phalcon_support_settings_ce, "get", &_12, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_48)) {
		if (exists) {
			ZEPHIR_INIT_NVAR(&eventName);
			ZVAL_STRING(&eventName, "afterValidationOnUpdate");
		} else {
			ZEPHIR_INIT_NVAR(&eventName);
			ZVAL_STRING(&eventName, "afterValidationOnCreate");
		}
		ZEPHIR_CALL_METHOD(&_49$$60, this_ptr, "fireeventcancel", NULL, 0, &eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_49$$60)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(&_51$$60);
		ZVAL_STRING(&_51$$60, "afterValidation");
		ZEPHIR_CALL_METHOD(&_50$$60, this_ptr, "fireeventcancel", NULL, 0, &_51$$60);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_50$$60)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(&_51$$60);
		ZVAL_STRING(&_51$$60, "beforeSave");
		ZEPHIR_CALL_METHOD(&_52$$60, this_ptr, "fireeventcancel", NULL, 0, &_51$$60);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_52$$60)) {
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
		ZEPHIR_CALL_METHOD(&_53$$60, this_ptr, "fireeventcancel", NULL, 0, &eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_53$$60)) {
			RETURN_MM_BOOL(0);
		}
		zephir_read_property(&_54$$60, this_ptr, ZEND_STRL("skipped"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_54$$60)) {
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
	zend_string *_4;
	zend_ulong _3;
	zend_bool nesting = 0, _16$$8, _31$$16;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_11 = NULL, *_13 = NULL, *_15 = NULL, *_23 = NULL, *_25 = NULL, *_30 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, columnCount = 0, i = 0, _17$$8, _18$$8, _32$$16, _33$$16;
	zval *connection, connection_sub, *related, related_sub, *visited, visited_sub, className, manager, type, relation, columns, referencedFields, name, record, columnA, columnB, _0, _1, *_2, _21, _5$$3, _7$$6, _9$$6, _10$$6, _12$$5, _14$$7, _19$$9, _20$$10, _22$$11, _24$$14, _26$$14, _27$$14, _28$$13, _29$$15, _34$$17, _35$$18;
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
	ZVAL_UNDEF(&columnA);
	ZVAL_UNDEF(&columnB);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_24$$14);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_27$$14);
	ZVAL_UNDEF(&_28$$13);
	ZVAL_UNDEF(&_29$$15);
	ZVAL_UNDEF(&_34$$17);
	ZVAL_UNDEF(&_35$$18);
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
	zephir_is_iterable(related, 0, "phalcon/Mvc/Model.zep", 5323);
	if (Z_TYPE_P(related) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(related), _3, _4, _2)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&name, _4);
			} else {
				ZVAL_LONG(&name, _3);
			}
			ZEPHIR_INIT_NVAR(&record);
			ZVAL_COPY(&record, _2);
			ZEPHIR_CALL_METHOD(&_5$$3, &manager, "getrelationbyalias", &_6, 0, &className, &name);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&relation, &_5$$3);
			if (Z_TYPE_P(&relation) == IS_OBJECT) {
				ZEPHIR_CALL_METHOD(&type, &relation, "gettype", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(&type, 0)) {
					if (UNEXPECTED(Z_TYPE_P(&record) != IS_OBJECT)) {
						if (nesting) {
							ZVAL_BOOL(&_7$$6, 1);
						} else {
							ZVAL_BOOL(&_7$$6, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_8, 0, &_7$$6);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_9$$6);
						object_init_ex(&_9$$6, phalcon_mvc_model_exceptions_belongstorequiresobject_ce);
						ZEPHIR_INIT_NVAR(&_10$$6);
						zephir_get_class(&_10$$6, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_9$$6, "__construct", &_11, 0, &_10$$6, &name);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_9$$6, "phalcon/Mvc/Model.zep", 5280);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_12$$5, &record, "dosave", NULL, 0, visited);
					zephir_check_call_status();
					if (!(zephir_is_true(&_12$$5))) {
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_13, 0, &record);
						zephir_check_call_status();
						if (nesting) {
							ZVAL_BOOL(&_14$$7, 1);
						} else {
							ZVAL_BOOL(&_14$$7, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_15, 0, &_14$$7);
						zephir_check_call_status();
						RETURN_MM_BOOL(0);
					}
					ZEPHIR_CALL_METHOD(&columns, &relation, "getfields", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", NULL, 0);
					zephir_check_call_status();
					if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
						columnCount = (zephir_fast_count_int(&columns) - 1);
						_18$$8 = columnCount;
						_17$$8 = 0;
						_16$$8 = 0;
						if (_17$$8 <= _18$$8) {
							while (1) {
								if (_16$$8) {
									_17$$8++;
									if (!(_17$$8 <= _18$$8)) {
										break;
									}
								} else {
									_16$$8 = 1;
								}
								i = _17$$8;
								zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 5312);
								zephir_array_fetch_long(&columnB, &referencedFields, i, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 5313);
								ZEPHIR_OBS_NVAR(&_19$$9);
								zephir_read_property_zval(&_19$$9, &record, &columnB, PH_NOISY_CC);
								zephir_update_property_zval_zval(this_ptr, &columnA, &_19$$9);
							}
						}
					} else {
						ZEPHIR_OBS_NVAR(&_20$$10);
						zephir_read_property_zval(&_20$$10, &record, &referencedFields, PH_NOISY_CC);
						zephir_update_property_zval_zval(this_ptr, &columns, &_20$$10);
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, related, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_21, related, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_21)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, related, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&record, related, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_22$$11, &manager, "getrelationbyalias", &_23, 0, &className, &name);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&relation, &_22$$11);
				if (Z_TYPE_P(&relation) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&type, &relation, "gettype", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG(&type, 0)) {
						if (UNEXPECTED(Z_TYPE_P(&record) != IS_OBJECT)) {
							if (nesting) {
								ZVAL_BOOL(&_24$$14, 1);
							} else {
								ZVAL_BOOL(&_24$$14, 0);
							}
							ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_25, 0, &_24$$14);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_26$$14);
							object_init_ex(&_26$$14, phalcon_mvc_model_exceptions_belongstorequiresobject_ce);
							ZEPHIR_INIT_NVAR(&_27$$14);
							zephir_get_class(&_27$$14, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_26$$14, "__construct", &_11, 0, &_27$$14, &name);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_26$$14, "phalcon/Mvc/Model.zep", 5280);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD(&_28$$13, &record, "dosave", NULL, 0, visited);
						zephir_check_call_status();
						if (!(zephir_is_true(&_28$$13))) {
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_13, 0, &record);
							zephir_check_call_status();
							if (nesting) {
								ZVAL_BOOL(&_29$$15, 1);
							} else {
								ZVAL_BOOL(&_29$$15, 0);
							}
							ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_30, 0, &_29$$15);
							zephir_check_call_status();
							RETURN_MM_BOOL(0);
						}
						ZEPHIR_CALL_METHOD(&columns, &relation, "getfields", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", NULL, 0);
						zephir_check_call_status();
						if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
							columnCount = (zephir_fast_count_int(&columns) - 1);
							_33$$16 = columnCount;
							_32$$16 = 0;
							_31$$16 = 0;
							if (_32$$16 <= _33$$16) {
								while (1) {
									if (_31$$16) {
										_32$$16++;
										if (!(_32$$16 <= _33$$16)) {
											break;
										}
									} else {
										_31$$16 = 1;
									}
									i = _32$$16;
									ZEPHIR_OBS_NVAR(&columnA);
									zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5312);
									ZEPHIR_OBS_NVAR(&columnB);
									zephir_array_fetch_long(&columnB, &referencedFields, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5313);
									ZEPHIR_OBS_NVAR(&_34$$17);
									zephir_read_property_zval(&_34$$17, &record, &columnB, PH_NOISY_CC);
									zephir_update_property_zval_zval(this_ptr, &columnA, &_34$$17);
								}
							}
						} else {
							ZEPHIR_OBS_NVAR(&_35$$18);
							zephir_read_property_zval(&_35$$18, &record, &referencedFields, PH_NOISY_CC);
							zephir_update_property_zval_zval(this_ptr, &columns, &_35$$18);
						}
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
	zval _21$$11, _39$$17, _44$$18, _78$$32, _83$$33, _151$$66, _168$$72, _173$$73, _207$$87, _212$$88;
	zend_string *_3;
	zend_ulong _2;
	zval conditions, placeholders, loopConditions, loopPlaceholders, _47$$13, _86$$28, _176$$68, _215$$83;
	zend_bool nesting = 0, isThrough = 0, _7$$4, _13$$10, _49$$13, _31$$16, _51$$21, _56$$24, _88$$28, _70$$31, _90$$36, _95$$39, _104$$45, _112$$48, _137$$59, _143$$65, _178$$68, _160$$71, _180$$76, _185$$79, _217$$83, _199$$86, _219$$91, _224$$94, _233$$100, _241$$103;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_9 = NULL, *_11 = NULL, *_26 = NULL, *_28 = NULL, *_30 = NULL, *_46 = NULL, *_50 = NULL, *_63 = NULL, *_67 = NULL, *_69 = NULL, *_85 = NULL, *_89 = NULL, *_102 = NULL, *_110 = NULL, *_118 = NULL, *_123 = NULL, *_128 = NULL, *_130 = NULL, *_132 = NULL, *_135 = NULL, *_139 = NULL, *_157 = NULL, *_159 = NULL, *_175 = NULL, *_179 = NULL, *_192 = NULL, *_196 = NULL, *_198 = NULL, *_214 = NULL, *_218 = NULL, *_231 = NULL, *_239 = NULL, *_247 = NULL, *_252 = NULL, *_257 = NULL, *_259 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, columnCount = 0, referencedFieldsCount = 0, i = 0, j = 0, t = 0, h = 0, _14$$10, _15$$10, _32$$16, _33$$16, _52$$21, _53$$21, _57$$24, _58$$24, _71$$31, _72$$31, _91$$36, _92$$36, _96$$39, _97$$39, _105$$45, _106$$45, _113$$48, _114$$48, _144$$65, _145$$65, _161$$71, _162$$71, _181$$76, _182$$76, _186$$79, _187$$79, _200$$86, _201$$86, _220$$91, _221$$91, _225$$94, _226$$94, _234$$100, _235$$100, _242$$103, _243$$103;
	zval *connection, connection_sub, *related, related_sub, *visited, visited_sub, className, manager, relation, name, record, columns, referencedModel, referencedFields, relatedRecords, recordAfter, intermediateModel, intermediateFields, intermediateModelName, intermediateReferencedFields, existingIntermediateModel, columnA, columnB, _0, *_1, _133, _261, _4$$3, _6$$4, _12$$4, _8$$6, _10$$6, _16$$11, _17$$11, _18$$11, _19$$11, _20$$11, _22$$12, _23$$12, *_24$$9, _64$$9, _25$$13, _29$$13, _45$$13, _48$$13, _61$$13, _27$$14, _34$$17, _35$$17, _36$$17, _37$$17, _38$$17, _40$$18, _41$$18, _42$$18, _43$$18, _54$$22, _55$$23, _59$$25, _60$$26, _62$$27, _65$$28, _68$$28, _84$$28, _87$$28, _100$$28, _66$$29, _73$$32, _74$$32, _75$$32, _76$$32, _77$$32, _79$$33, _80$$33, _81$$33, _82$$33, _93$$37, _94$$38, _98$$40, _99$$41, _101$$42, *_103$$44, _111$$44, _108$$45, _107$$46, _109$$47, _116$$48, _115$$49, _117$$50, *_119$$51, _124$$51, _120$$52, _121$$52, _122$$53, _125$$54, _126$$54, _127$$55, _129$$57, _131$$57, _134$$58, _136$$59, _142$$59, _138$$61, _140$$61, _141$$62, _146$$66, _147$$66, _148$$66, _149$$66, _150$$66, _152$$67, _153$$67, *_154$$64, _193$$64, _155$$68, _158$$68, _174$$68, _177$$68, _190$$68, _156$$69, _163$$72, _164$$72, _165$$72, _166$$72, _167$$72, _169$$73, _170$$73, _171$$73, _172$$73, _183$$77, _184$$78, _188$$80, _189$$81, _191$$82, _194$$83, _197$$83, _213$$83, _216$$83, _229$$83, _195$$84, _202$$87, _203$$87, _204$$87, _205$$87, _206$$87, _208$$88, _209$$88, _210$$88, _211$$88, _222$$92, _223$$93, _227$$95, _228$$96, _230$$97, *_232$$99, _240$$99, _237$$100, _236$$101, _238$$102, _245$$103, _244$$104, _246$$105, *_248$$106, _253$$106, _249$$107, _250$$107, _251$$108, _254$$109, _255$$109, _256$$110, _258$$112, _260$$112;
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
	ZVAL_UNDEF(&recordAfter);
	ZVAL_UNDEF(&intermediateModel);
	ZVAL_UNDEF(&intermediateFields);
	ZVAL_UNDEF(&intermediateModelName);
	ZVAL_UNDEF(&intermediateReferencedFields);
	ZVAL_UNDEF(&existingIntermediateModel);
	ZVAL_UNDEF(&columnA);
	ZVAL_UNDEF(&columnB);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_133);
	ZVAL_UNDEF(&_261);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_22$$12);
	ZVAL_UNDEF(&_23$$12);
	ZVAL_UNDEF(&_64$$9);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_29$$13);
	ZVAL_UNDEF(&_45$$13);
	ZVAL_UNDEF(&_48$$13);
	ZVAL_UNDEF(&_61$$13);
	ZVAL_UNDEF(&_27$$14);
	ZVAL_UNDEF(&_34$$17);
	ZVAL_UNDEF(&_35$$17);
	ZVAL_UNDEF(&_36$$17);
	ZVAL_UNDEF(&_37$$17);
	ZVAL_UNDEF(&_38$$17);
	ZVAL_UNDEF(&_40$$18);
	ZVAL_UNDEF(&_41$$18);
	ZVAL_UNDEF(&_42$$18);
	ZVAL_UNDEF(&_43$$18);
	ZVAL_UNDEF(&_54$$22);
	ZVAL_UNDEF(&_55$$23);
	ZVAL_UNDEF(&_59$$25);
	ZVAL_UNDEF(&_60$$26);
	ZVAL_UNDEF(&_62$$27);
	ZVAL_UNDEF(&_65$$28);
	ZVAL_UNDEF(&_68$$28);
	ZVAL_UNDEF(&_84$$28);
	ZVAL_UNDEF(&_87$$28);
	ZVAL_UNDEF(&_100$$28);
	ZVAL_UNDEF(&_66$$29);
	ZVAL_UNDEF(&_73$$32);
	ZVAL_UNDEF(&_74$$32);
	ZVAL_UNDEF(&_75$$32);
	ZVAL_UNDEF(&_76$$32);
	ZVAL_UNDEF(&_77$$32);
	ZVAL_UNDEF(&_79$$33);
	ZVAL_UNDEF(&_80$$33);
	ZVAL_UNDEF(&_81$$33);
	ZVAL_UNDEF(&_82$$33);
	ZVAL_UNDEF(&_93$$37);
	ZVAL_UNDEF(&_94$$38);
	ZVAL_UNDEF(&_98$$40);
	ZVAL_UNDEF(&_99$$41);
	ZVAL_UNDEF(&_101$$42);
	ZVAL_UNDEF(&_111$$44);
	ZVAL_UNDEF(&_108$$45);
	ZVAL_UNDEF(&_107$$46);
	ZVAL_UNDEF(&_109$$47);
	ZVAL_UNDEF(&_116$$48);
	ZVAL_UNDEF(&_115$$49);
	ZVAL_UNDEF(&_117$$50);
	ZVAL_UNDEF(&_124$$51);
	ZVAL_UNDEF(&_120$$52);
	ZVAL_UNDEF(&_121$$52);
	ZVAL_UNDEF(&_122$$53);
	ZVAL_UNDEF(&_125$$54);
	ZVAL_UNDEF(&_126$$54);
	ZVAL_UNDEF(&_127$$55);
	ZVAL_UNDEF(&_129$$57);
	ZVAL_UNDEF(&_131$$57);
	ZVAL_UNDEF(&_134$$58);
	ZVAL_UNDEF(&_136$$59);
	ZVAL_UNDEF(&_142$$59);
	ZVAL_UNDEF(&_138$$61);
	ZVAL_UNDEF(&_140$$61);
	ZVAL_UNDEF(&_141$$62);
	ZVAL_UNDEF(&_146$$66);
	ZVAL_UNDEF(&_147$$66);
	ZVAL_UNDEF(&_148$$66);
	ZVAL_UNDEF(&_149$$66);
	ZVAL_UNDEF(&_150$$66);
	ZVAL_UNDEF(&_152$$67);
	ZVAL_UNDEF(&_153$$67);
	ZVAL_UNDEF(&_193$$64);
	ZVAL_UNDEF(&_155$$68);
	ZVAL_UNDEF(&_158$$68);
	ZVAL_UNDEF(&_174$$68);
	ZVAL_UNDEF(&_177$$68);
	ZVAL_UNDEF(&_190$$68);
	ZVAL_UNDEF(&_156$$69);
	ZVAL_UNDEF(&_163$$72);
	ZVAL_UNDEF(&_164$$72);
	ZVAL_UNDEF(&_165$$72);
	ZVAL_UNDEF(&_166$$72);
	ZVAL_UNDEF(&_167$$72);
	ZVAL_UNDEF(&_169$$73);
	ZVAL_UNDEF(&_170$$73);
	ZVAL_UNDEF(&_171$$73);
	ZVAL_UNDEF(&_172$$73);
	ZVAL_UNDEF(&_183$$77);
	ZVAL_UNDEF(&_184$$78);
	ZVAL_UNDEF(&_188$$80);
	ZVAL_UNDEF(&_189$$81);
	ZVAL_UNDEF(&_191$$82);
	ZVAL_UNDEF(&_194$$83);
	ZVAL_UNDEF(&_197$$83);
	ZVAL_UNDEF(&_213$$83);
	ZVAL_UNDEF(&_216$$83);
	ZVAL_UNDEF(&_229$$83);
	ZVAL_UNDEF(&_195$$84);
	ZVAL_UNDEF(&_202$$87);
	ZVAL_UNDEF(&_203$$87);
	ZVAL_UNDEF(&_204$$87);
	ZVAL_UNDEF(&_205$$87);
	ZVAL_UNDEF(&_206$$87);
	ZVAL_UNDEF(&_208$$88);
	ZVAL_UNDEF(&_209$$88);
	ZVAL_UNDEF(&_210$$88);
	ZVAL_UNDEF(&_211$$88);
	ZVAL_UNDEF(&_222$$92);
	ZVAL_UNDEF(&_223$$93);
	ZVAL_UNDEF(&_227$$95);
	ZVAL_UNDEF(&_228$$96);
	ZVAL_UNDEF(&_230$$97);
	ZVAL_UNDEF(&_240$$99);
	ZVAL_UNDEF(&_237$$100);
	ZVAL_UNDEF(&_236$$101);
	ZVAL_UNDEF(&_238$$102);
	ZVAL_UNDEF(&_245$$103);
	ZVAL_UNDEF(&_244$$104);
	ZVAL_UNDEF(&_246$$105);
	ZVAL_UNDEF(&_253$$106);
	ZVAL_UNDEF(&_249$$107);
	ZVAL_UNDEF(&_250$$107);
	ZVAL_UNDEF(&_251$$108);
	ZVAL_UNDEF(&_254$$109);
	ZVAL_UNDEF(&_255$$109);
	ZVAL_UNDEF(&_256$$110);
	ZVAL_UNDEF(&_258$$112);
	ZVAL_UNDEF(&_260$$112);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&placeholders);
	ZVAL_UNDEF(&loopConditions);
	ZVAL_UNDEF(&loopPlaceholders);
	ZVAL_UNDEF(&_47$$13);
	ZVAL_UNDEF(&_86$$28);
	ZVAL_UNDEF(&_176$$68);
	ZVAL_UNDEF(&_215$$83);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_39$$17);
	ZVAL_UNDEF(&_44$$18);
	ZVAL_UNDEF(&_78$$32);
	ZVAL_UNDEF(&_83$$33);
	ZVAL_UNDEF(&_151$$66);
	ZVAL_UNDEF(&_168$$72);
	ZVAL_UNDEF(&_173$$73);
	ZVAL_UNDEF(&_207$$87);
	ZVAL_UNDEF(&_212$$88);
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
	zephir_is_iterable(related, 0, "phalcon/Mvc/Model.zep", 5601);
	if (Z_TYPE_P(related) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(related), _2, _3, _1)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&name, _3);
			} else {
				ZVAL_LONG(&name, _2);
			}
			ZEPHIR_INIT_NVAR(&record);
			ZVAL_COPY(&record, _1);
			ZEPHIR_CALL_METHOD(&_4$$3, &manager, "getrelationbyalias", &_5, 0, &className, &name);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&relation, &_4$$3);
			if (Z_TYPE_P(&relation) == IS_OBJECT) {
				ZEPHIR_CALL_METHOD(&_6$$4, &relation, "gettype", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(&_6$$4, 0)) {
					continue;
				}
				_7$$4 = Z_TYPE_P(&record) != IS_OBJECT;
				if (_7$$4) {
					_7$$4 = Z_TYPE_P(&record) != IS_ARRAY;
				}
				if (UNEXPECTED(_7$$4)) {
					if (nesting) {
						ZVAL_BOOL(&_8$$6, 1);
					} else {
						ZVAL_BOOL(&_8$$6, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_9, 0, &_8$$6);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_10$$6);
					object_init_ex(&_10$$6, phalcon_mvc_model_exceptions_relationrequiresobjectorarray_ce);
					ZEPHIR_CALL_METHOD(NULL, &_10$$6, "__construct", &_11, 0, &className, &name);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_10$$6, "phalcon/Mvc/Model.zep", 5386);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&columns, &relation, "getfields", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedModel, &relation, "getreferencedmodel", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&record) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&relatedRecords);
					zephir_create_array(&relatedRecords, 1, 0);
					zephir_array_fast_append(&relatedRecords, &record);
				} else {
					ZEPHIR_CPY_WRT(&relatedRecords, &record);
				}
				ZEPHIR_CALL_METHOD(&_12$$4, &relation, "isthrough", NULL, 0);
				zephir_check_call_status();
				isThrough = zephir_get_boolval(&_12$$4);
				if (isThrough) {
					ZEPHIR_CALL_METHOD(&intermediateModelName, &relation, "getintermediatemodel", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&intermediateFields, &relation, "getintermediatefields", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&intermediateReferencedFields, &relation, "getintermediatereferencedfields", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&placeholders);
					array_init(&placeholders);
					ZEPHIR_INIT_NVAR(&conditions);
					array_init(&conditions);
					if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
						columnCount = (zephir_fast_count_int(&columns) - 1);
						_15$$10 = columnCount;
						_14$$10 = 0;
						_13$$10 = 0;
						if (_14$$10 <= _15$$10) {
							while (1) {
								if (_13$$10) {
									_14$$10++;
									if (!(_14$$10 <= _15$$10)) {
										break;
									}
								} else {
									_13$$10 = 1;
								}
								i = _14$$10;
								ZEPHIR_OBS_NVAR(&columnA);
								zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5421);
								zephir_array_fetch_long(&_16$$11, &intermediateFields, i, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 5422);
								ZEPHIR_INIT_NVAR(&_17$$11);
								ZVAL_LONG(&_17$$11, i);
								ZEPHIR_INIT_NVAR(&_18$$11);
								ZEPHIR_CONCAT_SVSVS(&_18$$11, "[", &_16$$11, "] = :APR", &_17$$11, ":");
								zephir_array_append(&conditions, &_18$$11, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5422);
								ZEPHIR_OBS_NVAR(&_19$$11);
								zephir_read_property_zval(&_19$$11, this_ptr, &columnA, PH_NOISY_CC);
								ZEPHIR_INIT_NVAR(&_20$$11);
								ZVAL_LONG(&_20$$11, i);
								ZEPHIR_INIT_NVAR(&_21$$11);
								ZEPHIR_CONCAT_SV(&_21$$11, "APR", &_20$$11);
								zephir_array_update_zval(&placeholders, &_21$$11, &_19$$11, PH_COPY | PH_SEPARATE);
							}
						}
						i = (columnCount + 1);
					} else {
						ZEPHIR_INIT_NVAR(&_22$$12);
						ZEPHIR_CONCAT_SVS(&_22$$12, "[", &intermediateFields, "] = :APR0:");
						zephir_array_append(&conditions, &_22$$12, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5427);
						ZEPHIR_OBS_NVAR(&_23$$12);
						zephir_read_property_zval(&_23$$12, this_ptr, &columns, PH_NOISY_CC);
						zephir_array_update_string(&placeholders, SL("APR0"), &_23$$12, PH_COPY | PH_SEPARATE);
						i = 1;
					}
					zephir_is_iterable(&relatedRecords, 0, "phalcon/Mvc/Model.zep", 5535);
					if (Z_TYPE_P(&relatedRecords) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relatedRecords), _24$$9)
						{
							ZEPHIR_INIT_NVAR(&recordAfter);
							ZVAL_COPY(&recordAfter, _24$$9);
							ZEPHIR_CALL_METHOD(&_25$$13, &recordAfter, "dosave", NULL, 0, visited);
							zephir_check_call_status();
							if (!(zephir_is_true(&_25$$13))) {
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &recordAfter);
								zephir_check_call_status();
								if (nesting) {
									ZVAL_BOOL(&_27$$14, 1);
								} else {
									ZVAL_BOOL(&_27$$14, 0);
								}
								ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_28, 0, &_27$$14);
								zephir_check_call_status();
								RETURN_MM_BOOL(0);
							}
							ZEPHIR_CPY_WRT(&loopConditions, &conditions);
							ZEPHIR_CPY_WRT(&loopPlaceholders, &placeholders);
							ZEPHIR_CALL_METHOD(&_29$$13, &relation, "gettype", &_30, 0);
							zephir_check_call_status();
							if (ZEPHIR_IS_LONG_IDENTICAL(&_29$$13, 4)) {
								if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
									referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
									_33$$16 = referencedFieldsCount;
									_32$$16 = 0;
									_31$$16 = 0;
									if (_32$$16 <= _33$$16) {
										while (1) {
											if (_31$$16) {
												_32$$16++;
												if (!(_32$$16 <= _33$$16)) {
													break;
												}
											} else {
												_31$$16 = 1;
											}
											j = _32$$16;
											ZEPHIR_OBS_NVAR(&columnA);
											zephir_array_fetch_long(&columnA, &referencedFields, j, PH_NOISY, "phalcon/Mvc/Model.zep", 5462);
											t = (j + i);
											zephir_array_fetch_long(&_34$$17, &intermediateReferencedFields, j, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 5464);
											ZEPHIR_INIT_NVAR(&_35$$17);
											ZVAL_LONG(&_35$$17, t);
											ZEPHIR_INIT_NVAR(&_36$$17);
											ZEPHIR_CONCAT_SVSVS(&_36$$17, "[", &_34$$17, "] = :APR", &_35$$17, ":");
											zephir_array_append(&loopConditions, &_36$$17, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5464);
											ZEPHIR_OBS_NVAR(&_37$$17);
											zephir_read_property_zval(&_37$$17, &recordAfter, &columnA, PH_NOISY_CC);
											ZEPHIR_INIT_NVAR(&_38$$17);
											ZVAL_LONG(&_38$$17, t);
											ZEPHIR_INIT_NVAR(&_39$$17);
											ZEPHIR_CONCAT_SV(&_39$$17, "APR", &_38$$17);
											zephir_array_update_zval(&loopPlaceholders, &_39$$17, &_37$$17, PH_COPY | PH_SEPARATE);
										}
									}
								} else {
									ZEPHIR_INIT_NVAR(&_40$$18);
									ZVAL_LONG(&_40$$18, i);
									ZEPHIR_INIT_NVAR(&_41$$18);
									ZEPHIR_CONCAT_SVSVS(&_41$$18, "[", &intermediateReferencedFields, "] = :APR", &_40$$18, ":");
									zephir_array_append(&loopConditions, &_41$$18, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5468);
									ZEPHIR_OBS_NVAR(&_42$$18);
									zephir_read_property_zval(&_42$$18, &recordAfter, &referencedFields, PH_NOISY_CC);
									ZEPHIR_INIT_NVAR(&_43$$18);
									ZVAL_LONG(&_43$$18, i);
									ZEPHIR_INIT_NVAR(&_44$$18);
									ZEPHIR_CONCAT_SV(&_44$$18, "APR", &_43$$18);
									zephir_array_update_zval(&loopPlaceholders, &_44$$18, &_42$$18, PH_COPY | PH_SEPARATE);
								}
							}
							ZEPHIR_CALL_METHOD(&_45$$13, &manager, "load", &_46, 0, &intermediateModelName);
							zephir_check_call_status();
							ZEPHIR_CPY_WRT(&intermediateModel, &_45$$13);
							ZEPHIR_INIT_NVAR(&_47$$13);
							zephir_create_array(&_47$$13, 2, 0);
							ZEPHIR_INIT_NVAR(&_48$$13);
							zephir_fast_join_str(&_48$$13, SL(" AND "), &loopConditions);
							zephir_array_fast_append(&_47$$13, &_48$$13);
							zephir_array_update_string(&_47$$13, SL("bind"), &loopPlaceholders, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(&existingIntermediateModel, &intermediateModel, "findfirst", NULL, 0, &_47$$13);
							zephir_check_call_status();
							if (zephir_is_true(&existingIntermediateModel)) {
								ZEPHIR_CPY_WRT(&intermediateModel, &existingIntermediateModel);
							}
							_49$$13 = !zephir_is_true(&existingIntermediateModel);
							if (!(_49$$13)) {
								ZEPHIR_CALL_METHOD(&_45$$13, &relation, "gettype", &_50, 0);
								zephir_check_call_status();
								_49$$13 = ZEPHIR_IS_LONG_IDENTICAL(&_45$$13, 3);
							}
							if (_49$$13) {
								if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
									_53$$21 = columnCount;
									_52$$21 = 0;
									_51$$21 = 0;
									if (_52$$21 <= _53$$21) {
										while (1) {
											if (_51$$21) {
												_52$$21++;
												if (!(_52$$21 <= _53$$21)) {
													break;
												}
											} else {
												_51$$21 = 1;
											}
											h = _52$$21;
											ZEPHIR_OBS_NVAR(&columnA);
											zephir_array_fetch_long(&columnA, &columns, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5499);
											ZEPHIR_OBS_NVAR(&columnB);
											zephir_array_fetch_long(&columnB, &intermediateFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5500);
											ZEPHIR_OBS_NVAR(&_54$$22);
											zephir_read_property_zval(&_54$$22, this_ptr, &columnA, PH_NOISY_CC);
											zephir_update_property_zval_zval(&intermediateModel, &columnB, &_54$$22);
										}
									}
								} else {
									ZEPHIR_OBS_NVAR(&_55$$23);
									zephir_read_property_zval(&_55$$23, this_ptr, &columns, PH_NOISY_CC);
									zephir_update_property_zval_zval(&intermediateModel, &intermediateFields, &_55$$23);
								}
								if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
									referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
									_58$$24 = referencedFieldsCount;
									_57$$24 = 0;
									_56$$24 = 0;
									if (_57$$24 <= _58$$24) {
										while (1) {
											if (_56$$24) {
												_57$$24++;
												if (!(_57$$24 <= _58$$24)) {
													break;
												}
											} else {
												_56$$24 = 1;
											}
											h = _57$$24;
											ZEPHIR_OBS_NVAR(&columnA);
											zephir_array_fetch_long(&columnA, &referencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5509);
											ZEPHIR_OBS_NVAR(&columnB);
											zephir_array_fetch_long(&columnB, &intermediateReferencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5510);
											ZEPHIR_OBS_NVAR(&_59$$25);
											zephir_read_property_zval(&_59$$25, &recordAfter, &columnA, PH_NOISY_CC);
											zephir_update_property_zval_zval(&intermediateModel, &columnB, &_59$$25);
										}
									}
								} else {
									ZEPHIR_OBS_NVAR(&_60$$26);
									zephir_read_property_zval(&_60$$26, &recordAfter, &referencedFields, PH_NOISY_CC);
									zephir_update_property_zval_zval(&intermediateModel, &intermediateReferencedFields, &_60$$26);
								}
							}
							ZEPHIR_CALL_METHOD(&_61$$13, &intermediateModel, "dosave", NULL, 0, visited);
							zephir_check_call_status();
							if (!(zephir_is_true(&_61$$13))) {
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &intermediateModel);
								zephir_check_call_status();
								if (nesting) {
									ZVAL_BOOL(&_62$$27, 1);
								} else {
									ZVAL_BOOL(&_62$$27, 0);
								}
								ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_63, 0, &_62$$27);
								zephir_check_call_status();
								RETURN_MM_BOOL(0);
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_64$$9, &relatedRecords, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_64$$9)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&recordAfter, &relatedRecords, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&_65$$28, &recordAfter, "dosave", NULL, 0, visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_65$$28))) {
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &recordAfter);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_66$$29, 1);
									} else {
										ZVAL_BOOL(&_66$$29, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_67, 0, &_66$$29);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
								ZEPHIR_CPY_WRT(&loopConditions, &conditions);
								ZEPHIR_CPY_WRT(&loopPlaceholders, &placeholders);
								ZEPHIR_CALL_METHOD(&_68$$28, &relation, "gettype", &_69, 0);
								zephir_check_call_status();
								if (ZEPHIR_IS_LONG_IDENTICAL(&_68$$28, 4)) {
									if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
										referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
										_72$$31 = referencedFieldsCount;
										_71$$31 = 0;
										_70$$31 = 0;
										if (_71$$31 <= _72$$31) {
											while (1) {
												if (_70$$31) {
													_71$$31++;
													if (!(_71$$31 <= _72$$31)) {
														break;
													}
												} else {
													_70$$31 = 1;
												}
												j = _71$$31;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &referencedFields, j, PH_NOISY, "phalcon/Mvc/Model.zep", 5462);
												t = (j + i);
												zephir_array_fetch_long(&_73$$32, &intermediateReferencedFields, j, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 5464);
												ZEPHIR_INIT_NVAR(&_74$$32);
												ZVAL_LONG(&_74$$32, t);
												ZEPHIR_INIT_NVAR(&_75$$32);
												ZEPHIR_CONCAT_SVSVS(&_75$$32, "[", &_73$$32, "] = :APR", &_74$$32, ":");
												zephir_array_append(&loopConditions, &_75$$32, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5464);
												ZEPHIR_OBS_NVAR(&_76$$32);
												zephir_read_property_zval(&_76$$32, &recordAfter, &columnA, PH_NOISY_CC);
												ZEPHIR_INIT_NVAR(&_77$$32);
												ZVAL_LONG(&_77$$32, t);
												ZEPHIR_INIT_NVAR(&_78$$32);
												ZEPHIR_CONCAT_SV(&_78$$32, "APR", &_77$$32);
												zephir_array_update_zval(&loopPlaceholders, &_78$$32, &_76$$32, PH_COPY | PH_SEPARATE);
											}
										}
									} else {
										ZEPHIR_INIT_NVAR(&_79$$33);
										ZVAL_LONG(&_79$$33, i);
										ZEPHIR_INIT_NVAR(&_80$$33);
										ZEPHIR_CONCAT_SVSVS(&_80$$33, "[", &intermediateReferencedFields, "] = :APR", &_79$$33, ":");
										zephir_array_append(&loopConditions, &_80$$33, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5468);
										ZEPHIR_OBS_NVAR(&_81$$33);
										zephir_read_property_zval(&_81$$33, &recordAfter, &referencedFields, PH_NOISY_CC);
										ZEPHIR_INIT_NVAR(&_82$$33);
										ZVAL_LONG(&_82$$33, i);
										ZEPHIR_INIT_NVAR(&_83$$33);
										ZEPHIR_CONCAT_SV(&_83$$33, "APR", &_82$$33);
										zephir_array_update_zval(&loopPlaceholders, &_83$$33, &_81$$33, PH_COPY | PH_SEPARATE);
									}
								}
								ZEPHIR_CALL_METHOD(&_84$$28, &manager, "load", &_85, 0, &intermediateModelName);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&intermediateModel, &_84$$28);
								ZEPHIR_INIT_NVAR(&_86$$28);
								zephir_create_array(&_86$$28, 2, 0);
								ZEPHIR_INIT_NVAR(&_87$$28);
								zephir_fast_join_str(&_87$$28, SL(" AND "), &loopConditions);
								zephir_array_fast_append(&_86$$28, &_87$$28);
								zephir_array_update_string(&_86$$28, SL("bind"), &loopPlaceholders, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(&existingIntermediateModel, &intermediateModel, "findfirst", NULL, 0, &_86$$28);
								zephir_check_call_status();
								if (zephir_is_true(&existingIntermediateModel)) {
									ZEPHIR_CPY_WRT(&intermediateModel, &existingIntermediateModel);
								}
								_88$$28 = !zephir_is_true(&existingIntermediateModel);
								if (!(_88$$28)) {
									ZEPHIR_CALL_METHOD(&_84$$28, &relation, "gettype", &_89, 0);
									zephir_check_call_status();
									_88$$28 = ZEPHIR_IS_LONG_IDENTICAL(&_84$$28, 3);
								}
								if (_88$$28) {
									if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
										_92$$36 = columnCount;
										_91$$36 = 0;
										_90$$36 = 0;
										if (_91$$36 <= _92$$36) {
											while (1) {
												if (_90$$36) {
													_91$$36++;
													if (!(_91$$36 <= _92$$36)) {
														break;
													}
												} else {
													_90$$36 = 1;
												}
												h = _91$$36;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &columns, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5499);
												ZEPHIR_OBS_NVAR(&columnB);
												zephir_array_fetch_long(&columnB, &intermediateFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5500);
												ZEPHIR_OBS_NVAR(&_93$$37);
												zephir_read_property_zval(&_93$$37, this_ptr, &columnA, PH_NOISY_CC);
												zephir_update_property_zval_zval(&intermediateModel, &columnB, &_93$$37);
											}
										}
									} else {
										ZEPHIR_OBS_NVAR(&_94$$38);
										zephir_read_property_zval(&_94$$38, this_ptr, &columns, PH_NOISY_CC);
										zephir_update_property_zval_zval(&intermediateModel, &intermediateFields, &_94$$38);
									}
									if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
										referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
										_97$$39 = referencedFieldsCount;
										_96$$39 = 0;
										_95$$39 = 0;
										if (_96$$39 <= _97$$39) {
											while (1) {
												if (_95$$39) {
													_96$$39++;
													if (!(_96$$39 <= _97$$39)) {
														break;
													}
												} else {
													_95$$39 = 1;
												}
												h = _96$$39;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &referencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5509);
												ZEPHIR_OBS_NVAR(&columnB);
												zephir_array_fetch_long(&columnB, &intermediateReferencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5510);
												ZEPHIR_OBS_NVAR(&_98$$40);
												zephir_read_property_zval(&_98$$40, &recordAfter, &columnA, PH_NOISY_CC);
												zephir_update_property_zval_zval(&intermediateModel, &columnB, &_98$$40);
											}
										}
									} else {
										ZEPHIR_OBS_NVAR(&_99$$41);
										zephir_read_property_zval(&_99$$41, &recordAfter, &referencedFields, PH_NOISY_CC);
										zephir_update_property_zval_zval(&intermediateModel, &intermediateReferencedFields, &_99$$41);
									}
								}
								ZEPHIR_CALL_METHOD(&_100$$28, &intermediateModel, "dosave", NULL, 0, visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_100$$28))) {
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &intermediateModel);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_101$$42, 1);
									} else {
										ZVAL_BOOL(&_101$$42, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_102, 0, &_101$$42);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
							ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&recordAfter);
				} else {
					if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
						columnCount = (zephir_fast_count_int(&columns) - 1);
						zephir_is_iterable(&relatedRecords, 0, "phalcon/Mvc/Model.zep", 5562);
						if (Z_TYPE_P(&relatedRecords) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relatedRecords), _103$$44)
							{
								ZEPHIR_INIT_NVAR(&recordAfter);
								ZVAL_COPY(&recordAfter, _103$$44);
								_106$$45 = columnCount;
								_105$$45 = 0;
								_104$$45 = 0;
								if (_105$$45 <= _106$$45) {
									while (1) {
										if (_104$$45) {
											_105$$45++;
											if (!(_105$$45 <= _106$$45)) {
												break;
											}
										} else {
											_104$$45 = 1;
										}
										i = _105$$45;
										ZEPHIR_OBS_NVAR(&columnA);
										zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5540);
										ZEPHIR_OBS_NVAR(&columnB);
										zephir_array_fetch_long(&columnB, &referencedFields, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5541);
										ZEPHIR_OBS_NVAR(&_107$$46);
										zephir_read_property_zval(&_107$$46, this_ptr, &columnA, PH_NOISY_CC);
										zephir_update_property_zval_zval(&recordAfter, &columnB, &_107$$46);
									}
								}
								ZEPHIR_CALL_METHOD(&_108$$45, &recordAfter, "dosave", NULL, 0, visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_108$$45))) {
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &recordAfter);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_109$$47, 1);
									} else {
										ZVAL_BOOL(&_109$$47, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_110, 0, &_109$$47);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_111$$44, &relatedRecords, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_111$$44)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&recordAfter, &relatedRecords, "current", NULL, 0);
								zephir_check_call_status();
									_114$$48 = columnCount;
									_113$$48 = 0;
									_112$$48 = 0;
									if (_113$$48 <= _114$$48) {
										while (1) {
											if (_112$$48) {
												_113$$48++;
												if (!(_113$$48 <= _114$$48)) {
													break;
												}
											} else {
												_112$$48 = 1;
											}
											i = _113$$48;
											ZEPHIR_OBS_NVAR(&columnA);
											zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5540);
											ZEPHIR_OBS_NVAR(&columnB);
											zephir_array_fetch_long(&columnB, &referencedFields, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5541);
											ZEPHIR_OBS_NVAR(&_115$$49);
											zephir_read_property_zval(&_115$$49, this_ptr, &columnA, PH_NOISY_CC);
											zephir_update_property_zval_zval(&recordAfter, &columnB, &_115$$49);
										}
									}
									ZEPHIR_CALL_METHOD(&_116$$48, &recordAfter, "dosave", NULL, 0, visited);
									zephir_check_call_status();
									if (!(zephir_is_true(&_116$$48))) {
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &recordAfter);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_117$$50, 1);
										} else {
											ZVAL_BOOL(&_117$$50, 0);
										}
										ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_118, 0, &_117$$50);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
								ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&recordAfter);
					} else {
						zephir_is_iterable(&relatedRecords, 0, "phalcon/Mvc/Model.zep", 5587);
						if (Z_TYPE_P(&relatedRecords) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relatedRecords), _119$$51)
							{
								ZEPHIR_INIT_NVAR(&recordAfter);
								ZVAL_COPY(&recordAfter, _119$$51);
								ZEPHIR_OBS_NVAR(&_120$$52);
								zephir_read_property_zval(&_120$$52, this_ptr, &columns, PH_NOISY_CC);
								zephir_update_property_zval_zval(&recordAfter, &referencedFields, &_120$$52);
								ZEPHIR_CALL_METHOD(&_121$$52, &recordAfter, "dosave", NULL, 0, visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_121$$52))) {
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &recordAfter);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_122$$53, 1);
									} else {
										ZVAL_BOOL(&_122$$53, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_123, 0, &_122$$53);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_124$$51, &relatedRecords, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_124$$51)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&recordAfter, &relatedRecords, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_OBS_NVAR(&_125$$54);
									zephir_read_property_zval(&_125$$54, this_ptr, &columns, PH_NOISY_CC);
									zephir_update_property_zval_zval(&recordAfter, &referencedFields, &_125$$54);
									ZEPHIR_CALL_METHOD(&_126$$54, &recordAfter, "dosave", NULL, 0, visited);
									zephir_check_call_status();
									if (!(zephir_is_true(&_126$$54))) {
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &recordAfter);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_127$$55, 1);
										} else {
											ZVAL_BOOL(&_127$$55, 0);
										}
										ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_128, 0, &_127$$55);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
								ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&recordAfter);
					}
				}
			} else {
				if (UNEXPECTED(Z_TYPE_P(&record) != IS_ARRAY)) {
					if (nesting) {
						ZVAL_BOOL(&_129$$57, 1);
					} else {
						ZVAL_BOOL(&_129$$57, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_130, 0, &_129$$57);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_131$$57);
					object_init_ex(&_131$$57, phalcon_mvc_model_exceptions_relationnotdefined_ce);
					ZEPHIR_CALL_METHOD(NULL, &_131$$57, "__construct", &_132, 0, &className, &name);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_131$$57, "phalcon/Mvc/Model.zep", 5593);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, related, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_133, related, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_133)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, related, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&record, related, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_134$$58, &manager, "getrelationbyalias", &_135, 0, &className, &name);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&relation, &_134$$58);
				if (Z_TYPE_P(&relation) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&_136$$59, &relation, "gettype", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG(&_136$$59, 0)) {
						continue;
					}
					_137$$59 = Z_TYPE_P(&record) != IS_OBJECT;
					if (_137$$59) {
						_137$$59 = Z_TYPE_P(&record) != IS_ARRAY;
					}
					if (UNEXPECTED(_137$$59)) {
						if (nesting) {
							ZVAL_BOOL(&_138$$61, 1);
						} else {
							ZVAL_BOOL(&_138$$61, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_139, 0, &_138$$61);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_140$$61);
						object_init_ex(&_140$$61, phalcon_mvc_model_exceptions_relationrequiresobjectorarray_ce);
						ZEPHIR_CALL_METHOD(NULL, &_140$$61, "__construct", &_11, 0, &className, &name);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_140$$61, "phalcon/Mvc/Model.zep", 5386);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&columns, &relation, "getfields", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedModel, &relation, "getreferencedmodel", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&record) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_141$$62);
						zephir_create_array(&_141$$62, 1, 0);
						zephir_array_fast_append(&_141$$62, &record);
						ZEPHIR_CPY_WRT(&relatedRecords, &_141$$62);
					} else {
						ZEPHIR_CPY_WRT(&relatedRecords, &record);
					}
					ZEPHIR_CALL_METHOD(&_142$$59, &relation, "isthrough", NULL, 0);
					zephir_check_call_status();
					isThrough = zephir_get_boolval(&_142$$59);
					if (isThrough) {
						ZEPHIR_CALL_METHOD(&intermediateModelName, &relation, "getintermediatemodel", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&intermediateFields, &relation, "getintermediatefields", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&intermediateReferencedFields, &relation, "getintermediatereferencedfields", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&placeholders);
						array_init(&placeholders);
						ZEPHIR_INIT_NVAR(&conditions);
						array_init(&conditions);
						if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
							columnCount = (zephir_fast_count_int(&columns) - 1);
							_145$$65 = columnCount;
							_144$$65 = 0;
							_143$$65 = 0;
							if (_144$$65 <= _145$$65) {
								while (1) {
									if (_143$$65) {
										_144$$65++;
										if (!(_144$$65 <= _145$$65)) {
											break;
										}
									} else {
										_143$$65 = 1;
									}
									i = _144$$65;
									ZEPHIR_OBS_NVAR(&columnA);
									zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5421);
									zephir_array_fetch_long(&_146$$66, &intermediateFields, i, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 5422);
									ZEPHIR_INIT_NVAR(&_147$$66);
									ZVAL_LONG(&_147$$66, i);
									ZEPHIR_INIT_NVAR(&_148$$66);
									ZEPHIR_CONCAT_SVSVS(&_148$$66, "[", &_146$$66, "] = :APR", &_147$$66, ":");
									zephir_array_append(&conditions, &_148$$66, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5422);
									ZEPHIR_OBS_NVAR(&_149$$66);
									zephir_read_property_zval(&_149$$66, this_ptr, &columnA, PH_NOISY_CC);
									ZEPHIR_INIT_NVAR(&_150$$66);
									ZVAL_LONG(&_150$$66, i);
									ZEPHIR_INIT_NVAR(&_151$$66);
									ZEPHIR_CONCAT_SV(&_151$$66, "APR", &_150$$66);
									zephir_array_update_zval(&placeholders, &_151$$66, &_149$$66, PH_COPY | PH_SEPARATE);
								}
							}
							i = (columnCount + 1);
						} else {
							ZEPHIR_INIT_NVAR(&_152$$67);
							ZEPHIR_CONCAT_SVS(&_152$$67, "[", &intermediateFields, "] = :APR0:");
							zephir_array_append(&conditions, &_152$$67, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5427);
							ZEPHIR_OBS_NVAR(&_153$$67);
							zephir_read_property_zval(&_153$$67, this_ptr, &columns, PH_NOISY_CC);
							zephir_array_update_string(&placeholders, SL("APR0"), &_153$$67, PH_COPY | PH_SEPARATE);
							i = 1;
						}
						zephir_is_iterable(&relatedRecords, 0, "phalcon/Mvc/Model.zep", 5535);
						if (Z_TYPE_P(&relatedRecords) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relatedRecords), _154$$64)
							{
								ZEPHIR_INIT_NVAR(&recordAfter);
								ZVAL_COPY(&recordAfter, _154$$64);
								ZEPHIR_CALL_METHOD(&_155$$68, &recordAfter, "dosave", NULL, 0, visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_155$$68))) {
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &recordAfter);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_156$$69, 1);
									} else {
										ZVAL_BOOL(&_156$$69, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_157, 0, &_156$$69);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
								ZEPHIR_CPY_WRT(&loopConditions, &conditions);
								ZEPHIR_CPY_WRT(&loopPlaceholders, &placeholders);
								ZEPHIR_CALL_METHOD(&_158$$68, &relation, "gettype", &_159, 0);
								zephir_check_call_status();
								if (ZEPHIR_IS_LONG_IDENTICAL(&_158$$68, 4)) {
									if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
										referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
										_162$$71 = referencedFieldsCount;
										_161$$71 = 0;
										_160$$71 = 0;
										if (_161$$71 <= _162$$71) {
											while (1) {
												if (_160$$71) {
													_161$$71++;
													if (!(_161$$71 <= _162$$71)) {
														break;
													}
												} else {
													_160$$71 = 1;
												}
												j = _161$$71;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &referencedFields, j, PH_NOISY, "phalcon/Mvc/Model.zep", 5462);
												t = (j + i);
												zephir_array_fetch_long(&_163$$72, &intermediateReferencedFields, j, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 5464);
												ZEPHIR_INIT_NVAR(&_164$$72);
												ZVAL_LONG(&_164$$72, t);
												ZEPHIR_INIT_NVAR(&_165$$72);
												ZEPHIR_CONCAT_SVSVS(&_165$$72, "[", &_163$$72, "] = :APR", &_164$$72, ":");
												zephir_array_append(&loopConditions, &_165$$72, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5464);
												ZEPHIR_OBS_NVAR(&_166$$72);
												zephir_read_property_zval(&_166$$72, &recordAfter, &columnA, PH_NOISY_CC);
												ZEPHIR_INIT_NVAR(&_167$$72);
												ZVAL_LONG(&_167$$72, t);
												ZEPHIR_INIT_NVAR(&_168$$72);
												ZEPHIR_CONCAT_SV(&_168$$72, "APR", &_167$$72);
												zephir_array_update_zval(&loopPlaceholders, &_168$$72, &_166$$72, PH_COPY | PH_SEPARATE);
											}
										}
									} else {
										ZEPHIR_INIT_NVAR(&_169$$73);
										ZVAL_LONG(&_169$$73, i);
										ZEPHIR_INIT_NVAR(&_170$$73);
										ZEPHIR_CONCAT_SVSVS(&_170$$73, "[", &intermediateReferencedFields, "] = :APR", &_169$$73, ":");
										zephir_array_append(&loopConditions, &_170$$73, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5468);
										ZEPHIR_OBS_NVAR(&_171$$73);
										zephir_read_property_zval(&_171$$73, &recordAfter, &referencedFields, PH_NOISY_CC);
										ZEPHIR_INIT_NVAR(&_172$$73);
										ZVAL_LONG(&_172$$73, i);
										ZEPHIR_INIT_NVAR(&_173$$73);
										ZEPHIR_CONCAT_SV(&_173$$73, "APR", &_172$$73);
										zephir_array_update_zval(&loopPlaceholders, &_173$$73, &_171$$73, PH_COPY | PH_SEPARATE);
									}
								}
								ZEPHIR_CALL_METHOD(&_174$$68, &manager, "load", &_175, 0, &intermediateModelName);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&intermediateModel, &_174$$68);
								ZEPHIR_INIT_NVAR(&_176$$68);
								zephir_create_array(&_176$$68, 2, 0);
								ZEPHIR_INIT_NVAR(&_177$$68);
								zephir_fast_join_str(&_177$$68, SL(" AND "), &loopConditions);
								zephir_array_fast_append(&_176$$68, &_177$$68);
								zephir_array_update_string(&_176$$68, SL("bind"), &loopPlaceholders, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(&existingIntermediateModel, &intermediateModel, "findfirst", NULL, 0, &_176$$68);
								zephir_check_call_status();
								if (zephir_is_true(&existingIntermediateModel)) {
									ZEPHIR_CPY_WRT(&intermediateModel, &existingIntermediateModel);
								}
								_178$$68 = !zephir_is_true(&existingIntermediateModel);
								if (!(_178$$68)) {
									ZEPHIR_CALL_METHOD(&_174$$68, &relation, "gettype", &_179, 0);
									zephir_check_call_status();
									_178$$68 = ZEPHIR_IS_LONG_IDENTICAL(&_174$$68, 3);
								}
								if (_178$$68) {
									if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
										_182$$76 = columnCount;
										_181$$76 = 0;
										_180$$76 = 0;
										if (_181$$76 <= _182$$76) {
											while (1) {
												if (_180$$76) {
													_181$$76++;
													if (!(_181$$76 <= _182$$76)) {
														break;
													}
												} else {
													_180$$76 = 1;
												}
												h = _181$$76;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &columns, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5499);
												ZEPHIR_OBS_NVAR(&columnB);
												zephir_array_fetch_long(&columnB, &intermediateFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5500);
												ZEPHIR_OBS_NVAR(&_183$$77);
												zephir_read_property_zval(&_183$$77, this_ptr, &columnA, PH_NOISY_CC);
												zephir_update_property_zval_zval(&intermediateModel, &columnB, &_183$$77);
											}
										}
									} else {
										ZEPHIR_OBS_NVAR(&_184$$78);
										zephir_read_property_zval(&_184$$78, this_ptr, &columns, PH_NOISY_CC);
										zephir_update_property_zval_zval(&intermediateModel, &intermediateFields, &_184$$78);
									}
									if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
										referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
										_187$$79 = referencedFieldsCount;
										_186$$79 = 0;
										_185$$79 = 0;
										if (_186$$79 <= _187$$79) {
											while (1) {
												if (_185$$79) {
													_186$$79++;
													if (!(_186$$79 <= _187$$79)) {
														break;
													}
												} else {
													_185$$79 = 1;
												}
												h = _186$$79;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &referencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5509);
												ZEPHIR_OBS_NVAR(&columnB);
												zephir_array_fetch_long(&columnB, &intermediateReferencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5510);
												ZEPHIR_OBS_NVAR(&_188$$80);
												zephir_read_property_zval(&_188$$80, &recordAfter, &columnA, PH_NOISY_CC);
												zephir_update_property_zval_zval(&intermediateModel, &columnB, &_188$$80);
											}
										}
									} else {
										ZEPHIR_OBS_NVAR(&_189$$81);
										zephir_read_property_zval(&_189$$81, &recordAfter, &referencedFields, PH_NOISY_CC);
										zephir_update_property_zval_zval(&intermediateModel, &intermediateReferencedFields, &_189$$81);
									}
								}
								ZEPHIR_CALL_METHOD(&_190$$68, &intermediateModel, "dosave", NULL, 0, visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_190$$68))) {
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &intermediateModel);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_191$$82, 1);
									} else {
										ZVAL_BOOL(&_191$$82, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_192, 0, &_191$$82);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_193$$64, &relatedRecords, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_193$$64)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&recordAfter, &relatedRecords, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&_194$$83, &recordAfter, "dosave", NULL, 0, visited);
									zephir_check_call_status();
									if (!(zephir_is_true(&_194$$83))) {
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &recordAfter);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_195$$84, 1);
										} else {
											ZVAL_BOOL(&_195$$84, 0);
										}
										ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_196, 0, &_195$$84);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
									ZEPHIR_CPY_WRT(&loopConditions, &conditions);
									ZEPHIR_CPY_WRT(&loopPlaceholders, &placeholders);
									ZEPHIR_CALL_METHOD(&_197$$83, &relation, "gettype", &_198, 0);
									zephir_check_call_status();
									if (ZEPHIR_IS_LONG_IDENTICAL(&_197$$83, 4)) {
										if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
											referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
											_201$$86 = referencedFieldsCount;
											_200$$86 = 0;
											_199$$86 = 0;
											if (_200$$86 <= _201$$86) {
												while (1) {
													if (_199$$86) {
														_200$$86++;
														if (!(_200$$86 <= _201$$86)) {
															break;
														}
													} else {
														_199$$86 = 1;
													}
													j = _200$$86;
													ZEPHIR_OBS_NVAR(&columnA);
													zephir_array_fetch_long(&columnA, &referencedFields, j, PH_NOISY, "phalcon/Mvc/Model.zep", 5462);
													t = (j + i);
													zephir_array_fetch_long(&_202$$87, &intermediateReferencedFields, j, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 5464);
													ZEPHIR_INIT_NVAR(&_203$$87);
													ZVAL_LONG(&_203$$87, t);
													ZEPHIR_INIT_NVAR(&_204$$87);
													ZEPHIR_CONCAT_SVSVS(&_204$$87, "[", &_202$$87, "] = :APR", &_203$$87, ":");
													zephir_array_append(&loopConditions, &_204$$87, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5464);
													ZEPHIR_OBS_NVAR(&_205$$87);
													zephir_read_property_zval(&_205$$87, &recordAfter, &columnA, PH_NOISY_CC);
													ZEPHIR_INIT_NVAR(&_206$$87);
													ZVAL_LONG(&_206$$87, t);
													ZEPHIR_INIT_NVAR(&_207$$87);
													ZEPHIR_CONCAT_SV(&_207$$87, "APR", &_206$$87);
													zephir_array_update_zval(&loopPlaceholders, &_207$$87, &_205$$87, PH_COPY | PH_SEPARATE);
												}
											}
										} else {
											ZEPHIR_INIT_NVAR(&_208$$88);
											ZVAL_LONG(&_208$$88, i);
											ZEPHIR_INIT_NVAR(&_209$$88);
											ZEPHIR_CONCAT_SVSVS(&_209$$88, "[", &intermediateReferencedFields, "] = :APR", &_208$$88, ":");
											zephir_array_append(&loopConditions, &_209$$88, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5468);
											ZEPHIR_OBS_NVAR(&_210$$88);
											zephir_read_property_zval(&_210$$88, &recordAfter, &referencedFields, PH_NOISY_CC);
											ZEPHIR_INIT_NVAR(&_211$$88);
											ZVAL_LONG(&_211$$88, i);
											ZEPHIR_INIT_NVAR(&_212$$88);
											ZEPHIR_CONCAT_SV(&_212$$88, "APR", &_211$$88);
											zephir_array_update_zval(&loopPlaceholders, &_212$$88, &_210$$88, PH_COPY | PH_SEPARATE);
										}
									}
									ZEPHIR_CALL_METHOD(&_213$$83, &manager, "load", &_214, 0, &intermediateModelName);
									zephir_check_call_status();
									ZEPHIR_CPY_WRT(&intermediateModel, &_213$$83);
									ZEPHIR_INIT_NVAR(&_215$$83);
									zephir_create_array(&_215$$83, 2, 0);
									ZEPHIR_INIT_NVAR(&_216$$83);
									zephir_fast_join_str(&_216$$83, SL(" AND "), &loopConditions);
									zephir_array_fast_append(&_215$$83, &_216$$83);
									zephir_array_update_string(&_215$$83, SL("bind"), &loopPlaceholders, PH_COPY | PH_SEPARATE);
									ZEPHIR_CALL_METHOD(&existingIntermediateModel, &intermediateModel, "findfirst", NULL, 0, &_215$$83);
									zephir_check_call_status();
									if (zephir_is_true(&existingIntermediateModel)) {
										ZEPHIR_CPY_WRT(&intermediateModel, &existingIntermediateModel);
									}
									_217$$83 = !zephir_is_true(&existingIntermediateModel);
									if (!(_217$$83)) {
										ZEPHIR_CALL_METHOD(&_213$$83, &relation, "gettype", &_218, 0);
										zephir_check_call_status();
										_217$$83 = ZEPHIR_IS_LONG_IDENTICAL(&_213$$83, 3);
									}
									if (_217$$83) {
										if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
											_221$$91 = columnCount;
											_220$$91 = 0;
											_219$$91 = 0;
											if (_220$$91 <= _221$$91) {
												while (1) {
													if (_219$$91) {
														_220$$91++;
														if (!(_220$$91 <= _221$$91)) {
															break;
														}
													} else {
														_219$$91 = 1;
													}
													h = _220$$91;
													ZEPHIR_OBS_NVAR(&columnA);
													zephir_array_fetch_long(&columnA, &columns, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5499);
													ZEPHIR_OBS_NVAR(&columnB);
													zephir_array_fetch_long(&columnB, &intermediateFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5500);
													ZEPHIR_OBS_NVAR(&_222$$92);
													zephir_read_property_zval(&_222$$92, this_ptr, &columnA, PH_NOISY_CC);
													zephir_update_property_zval_zval(&intermediateModel, &columnB, &_222$$92);
												}
											}
										} else {
											ZEPHIR_OBS_NVAR(&_223$$93);
											zephir_read_property_zval(&_223$$93, this_ptr, &columns, PH_NOISY_CC);
											zephir_update_property_zval_zval(&intermediateModel, &intermediateFields, &_223$$93);
										}
										if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
											referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
											_226$$94 = referencedFieldsCount;
											_225$$94 = 0;
											_224$$94 = 0;
											if (_225$$94 <= _226$$94) {
												while (1) {
													if (_224$$94) {
														_225$$94++;
														if (!(_225$$94 <= _226$$94)) {
															break;
														}
													} else {
														_224$$94 = 1;
													}
													h = _225$$94;
													ZEPHIR_OBS_NVAR(&columnA);
													zephir_array_fetch_long(&columnA, &referencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5509);
													ZEPHIR_OBS_NVAR(&columnB);
													zephir_array_fetch_long(&columnB, &intermediateReferencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5510);
													ZEPHIR_OBS_NVAR(&_227$$95);
													zephir_read_property_zval(&_227$$95, &recordAfter, &columnA, PH_NOISY_CC);
													zephir_update_property_zval_zval(&intermediateModel, &columnB, &_227$$95);
												}
											}
										} else {
											ZEPHIR_OBS_NVAR(&_228$$96);
											zephir_read_property_zval(&_228$$96, &recordAfter, &referencedFields, PH_NOISY_CC);
											zephir_update_property_zval_zval(&intermediateModel, &intermediateReferencedFields, &_228$$96);
										}
									}
									ZEPHIR_CALL_METHOD(&_229$$83, &intermediateModel, "dosave", NULL, 0, visited);
									zephir_check_call_status();
									if (!(zephir_is_true(&_229$$83))) {
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &intermediateModel);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_230$$97, 1);
										} else {
											ZVAL_BOOL(&_230$$97, 0);
										}
										ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_231, 0, &_230$$97);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
								ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&recordAfter);
					} else {
						if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
							columnCount = (zephir_fast_count_int(&columns) - 1);
							zephir_is_iterable(&relatedRecords, 0, "phalcon/Mvc/Model.zep", 5562);
							if (Z_TYPE_P(&relatedRecords) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relatedRecords), _232$$99)
								{
									ZEPHIR_INIT_NVAR(&recordAfter);
									ZVAL_COPY(&recordAfter, _232$$99);
									_235$$100 = columnCount;
									_234$$100 = 0;
									_233$$100 = 0;
									if (_234$$100 <= _235$$100) {
										while (1) {
											if (_233$$100) {
												_234$$100++;
												if (!(_234$$100 <= _235$$100)) {
													break;
												}
											} else {
												_233$$100 = 1;
											}
											i = _234$$100;
											ZEPHIR_OBS_NVAR(&columnA);
											zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5540);
											ZEPHIR_OBS_NVAR(&columnB);
											zephir_array_fetch_long(&columnB, &referencedFields, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5541);
											ZEPHIR_OBS_NVAR(&_236$$101);
											zephir_read_property_zval(&_236$$101, this_ptr, &columnA, PH_NOISY_CC);
											zephir_update_property_zval_zval(&recordAfter, &columnB, &_236$$101);
										}
									}
									ZEPHIR_CALL_METHOD(&_237$$100, &recordAfter, "dosave", NULL, 0, visited);
									zephir_check_call_status();
									if (!(zephir_is_true(&_237$$100))) {
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &recordAfter);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_238$$102, 1);
										} else {
											ZVAL_BOOL(&_238$$102, 0);
										}
										ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_239, 0, &_238$$102);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_240$$99, &relatedRecords, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_240$$99)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&recordAfter, &relatedRecords, "current", NULL, 0);
									zephir_check_call_status();
										_243$$103 = columnCount;
										_242$$103 = 0;
										_241$$103 = 0;
										if (_242$$103 <= _243$$103) {
											while (1) {
												if (_241$$103) {
													_242$$103++;
													if (!(_242$$103 <= _243$$103)) {
														break;
													}
												} else {
													_241$$103 = 1;
												}
												i = _242$$103;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5540);
												ZEPHIR_OBS_NVAR(&columnB);
												zephir_array_fetch_long(&columnB, &referencedFields, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5541);
												ZEPHIR_OBS_NVAR(&_244$$104);
												zephir_read_property_zval(&_244$$104, this_ptr, &columnA, PH_NOISY_CC);
												zephir_update_property_zval_zval(&recordAfter, &columnB, &_244$$104);
											}
										}
										ZEPHIR_CALL_METHOD(&_245$$103, &recordAfter, "dosave", NULL, 0, visited);
										zephir_check_call_status();
										if (!(zephir_is_true(&_245$$103))) {
											ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &recordAfter);
											zephir_check_call_status();
											if (nesting) {
												ZVAL_BOOL(&_246$$105, 1);
											} else {
												ZVAL_BOOL(&_246$$105, 0);
											}
											ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_247, 0, &_246$$105);
											zephir_check_call_status();
											RETURN_MM_BOOL(0);
										}
									ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "next", NULL, 0);
									zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&recordAfter);
						} else {
							zephir_is_iterable(&relatedRecords, 0, "phalcon/Mvc/Model.zep", 5587);
							if (Z_TYPE_P(&relatedRecords) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relatedRecords), _248$$106)
								{
									ZEPHIR_INIT_NVAR(&recordAfter);
									ZVAL_COPY(&recordAfter, _248$$106);
									ZEPHIR_OBS_NVAR(&_249$$107);
									zephir_read_property_zval(&_249$$107, this_ptr, &columns, PH_NOISY_CC);
									zephir_update_property_zval_zval(&recordAfter, &referencedFields, &_249$$107);
									ZEPHIR_CALL_METHOD(&_250$$107, &recordAfter, "dosave", NULL, 0, visited);
									zephir_check_call_status();
									if (!(zephir_is_true(&_250$$107))) {
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &recordAfter);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_251$$108, 1);
										} else {
											ZVAL_BOOL(&_251$$108, 0);
										}
										ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_252, 0, &_251$$108);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_253$$106, &relatedRecords, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_253$$106)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&recordAfter, &relatedRecords, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_OBS_NVAR(&_254$$109);
										zephir_read_property_zval(&_254$$109, this_ptr, &columns, PH_NOISY_CC);
										zephir_update_property_zval_zval(&recordAfter, &referencedFields, &_254$$109);
										ZEPHIR_CALL_METHOD(&_255$$109, &recordAfter, "dosave", NULL, 0, visited);
										zephir_check_call_status();
										if (!(zephir_is_true(&_255$$109))) {
											ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_26, 0, &recordAfter);
											zephir_check_call_status();
											if (nesting) {
												ZVAL_BOOL(&_256$$110, 1);
											} else {
												ZVAL_BOOL(&_256$$110, 0);
											}
											ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_257, 0, &_256$$110);
											zephir_check_call_status();
											RETURN_MM_BOOL(0);
										}
									ZEPHIR_CALL_METHOD(NULL, &relatedRecords, "next", NULL, 0);
									zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&recordAfter);
						}
					}
				} else {
					if (UNEXPECTED(Z_TYPE_P(&record) != IS_ARRAY)) {
						if (nesting) {
							ZVAL_BOOL(&_258$$112, 1);
						} else {
							ZVAL_BOOL(&_258$$112, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_259, 0, &_258$$112);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_260$$112);
						object_init_ex(&_260$$112, phalcon_mvc_model_exceptions_relationnotdefined_ce);
						ZEPHIR_CALL_METHOD(NULL, &_260$$112, "__construct", &_132, 0, &className, &name);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_260$$112, "phalcon/Mvc/Model.zep", 5593);
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
		ZVAL_BOOL(&_261, 1);
	} else {
		ZVAL_BOOL(&_261, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, connection, "commit", NULL, 0, &_261);
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
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &attributes_param);
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);
	ZEPHIR_INIT_VAR(&keysAttributes);
	array_init(&keysAttributes);
	zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model.zep", 5634);
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
 *         'for_update' => false,
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
	zend_string *referenceModel = NULL;
	zval *fields, fields_sub, referenceModel_zv, *referencedFields, referencedFields_sub, *options_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&referenceModel_zv);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_ZVAL(fields)
		Z_PARAM_STR(referenceModel)
		Z_PARAM_ZVAL(referencedFields)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	fields = ZEND_CALL_ARG(execute_data, 1);
	referencedFields = ZEND_CALL_ARG(execute_data, 3);
	if (ZEND_NUM_ARGS() > 3) {
		options_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&referenceModel_zv);
	ZVAL_STR_COPY(&referenceModel_zv, referenceModel);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addbelongsto", NULL, 0, this_ptr, fields, &referenceModel_zv, referencedFields, &options);
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
 *         'for_update' => false,
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
	zend_string *referenceModel = NULL;
	zval *fields, fields_sub, referenceModel_zv, *referencedFields, referencedFields_sub, *options_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&referenceModel_zv);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_ZVAL(fields)
		Z_PARAM_STR(referenceModel)
		Z_PARAM_ZVAL(referencedFields)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	fields = ZEND_CALL_ARG(execute_data, 1);
	referencedFields = ZEND_CALL_ARG(execute_data, 3);
	if (ZEND_NUM_ARGS() > 3) {
		options_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&referenceModel_zv);
	ZVAL_STR_COPY(&referenceModel_zv, referenceModel);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addhasmany", NULL, 0, this_ptr, fields, &referenceModel_zv, referencedFields, &options);
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
 *         'for_update' => false,
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
	zend_string *intermediateModel = NULL, *referenceModel = NULL;
	zval *fields, fields_sub, intermediateModel_zv, *intermediateFields, intermediateFields_sub, *intermediateReferencedFields, intermediateReferencedFields_sub, referenceModel_zv, *referencedFields, referencedFields_sub, *options_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&intermediateModel_zv);
	ZVAL_UNDEF(&intermediateFields_sub);
	ZVAL_UNDEF(&intermediateReferencedFields_sub);
	ZVAL_UNDEF(&referenceModel_zv);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(6, 7)
		Z_PARAM_ZVAL(fields)
		Z_PARAM_STR(intermediateModel)
		Z_PARAM_ZVAL(intermediateFields)
		Z_PARAM_ZVAL(intermediateReferencedFields)
		Z_PARAM_STR(referenceModel)
		Z_PARAM_ZVAL(referencedFields)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	fields = ZEND_CALL_ARG(execute_data, 1);
	intermediateFields = ZEND_CALL_ARG(execute_data, 3);
	intermediateReferencedFields = ZEND_CALL_ARG(execute_data, 4);
	referencedFields = ZEND_CALL_ARG(execute_data, 6);
	if (ZEND_NUM_ARGS() > 6) {
		options_param = ZEND_CALL_ARG(execute_data, 7);
	}
	zephir_memory_observe(&intermediateModel_zv);
	ZVAL_STR_COPY(&intermediateModel_zv, intermediateModel);
	zephir_memory_observe(&referenceModel_zv);
	ZVAL_STR_COPY(&referenceModel_zv, referenceModel);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addhasmanytomany", NULL, 0, this_ptr, fields, &intermediateModel_zv, intermediateFields, intermediateReferencedFields, &referenceModel_zv, referencedFields, &options);
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
 *         'for_update' => false,
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
	zend_string *referenceModel = NULL;
	zval *fields, fields_sub, referenceModel_zv, *referencedFields, referencedFields_sub, *options_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&referenceModel_zv);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_ZVAL(fields)
		Z_PARAM_STR(referenceModel)
		Z_PARAM_ZVAL(referencedFields)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	fields = ZEND_CALL_ARG(execute_data, 1);
	referencedFields = ZEND_CALL_ARG(execute_data, 3);
	if (ZEND_NUM_ARGS() > 3) {
		options_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&referenceModel_zv);
	ZVAL_STR_COPY(&referenceModel_zv, referenceModel);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addhasone", NULL, 0, this_ptr, fields, &referenceModel_zv, referencedFields, &options);
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
	zend_string *intermediateModel = NULL, *referenceModel = NULL;
	zval *fields, fields_sub, intermediateModel_zv, *intermediateFields, intermediateFields_sub, *intermediateReferencedFields, intermediateReferencedFields_sub, referenceModel_zv, *referencedFields, referencedFields_sub, *options_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&intermediateModel_zv);
	ZVAL_UNDEF(&intermediateFields_sub);
	ZVAL_UNDEF(&intermediateReferencedFields_sub);
	ZVAL_UNDEF(&referenceModel_zv);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(6, 7)
		Z_PARAM_ZVAL(fields)
		Z_PARAM_STR(intermediateModel)
		Z_PARAM_ZVAL(intermediateFields)
		Z_PARAM_ZVAL(intermediateReferencedFields)
		Z_PARAM_STR(referenceModel)
		Z_PARAM_ZVAL(referencedFields)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	fields = ZEND_CALL_ARG(execute_data, 1);
	intermediateFields = ZEND_CALL_ARG(execute_data, 3);
	intermediateReferencedFields = ZEND_CALL_ARG(execute_data, 4);
	referencedFields = ZEND_CALL_ARG(execute_data, 6);
	if (ZEND_NUM_ARGS() > 6) {
		options_param = ZEND_CALL_ARG(execute_data, 7);
	}
	zephir_memory_observe(&intermediateModel_zv);
	ZVAL_STR_COPY(&intermediateModel_zv, intermediateModel);
	zephir_memory_observe(&referenceModel_zv);
	ZVAL_STR_COPY(&referenceModel_zv, referenceModel);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addhasonethrough", NULL, 0, this_ptr, fields, &intermediateModel_zv, intermediateFields, intermediateReferencedFields, &referenceModel_zv, referencedFields, &options);
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
	zval schema_zv, _0;
	zend_string *schema = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&schema_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(schema)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&schema_zv);
	ZVAL_STR_COPY(&schema_zv, schema);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setmodelschema", NULL, 0, this_ptr, &schema_zv);
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
	zval source_zv, _0;
	zend_string *source = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&source_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(source)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&source_zv);
	ZVAL_STR_COPY(&source_zv, source);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setmodelsource", NULL, 0, this_ptr, &source_zv);
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
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
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
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &attributes_param);
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);
	ZEPHIR_INIT_VAR(&keysAttributes);
	array_init(&keysAttributes);
	zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model.zep", 6093);
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
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &attributes_param);
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);
	ZEPHIR_INIT_VAR(&keysAttributes);
	array_init(&keysAttributes);
	zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model.zep", 6128);
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
	if (EXPECTED(_1 != NULL)) {
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
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", &_8, 7, &_3$$4, &_4$$4, &_5$$4, &_6$$4, &_7$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_9, 0, &_2$$4);
		zephir_check_call_status();
	}
	zend_iterator_dtor(_1);
	}
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
	zval *columnMap, columnMap_sub, *key, key_sub, cmKey, _0, *_1, _2$$3, _3$$3;

	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&cmKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(columnMap)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &columnMap, &key);
	ZEPHIR_INIT_VAR(&_0);
	zephir_array_keys(&_0, columnMap);
	zephir_is_iterable(&_0, 0, "phalcon/Mvc/Model.zep", 6265);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
	{
		ZEPHIR_INIT_NVAR(&cmKey);
		ZVAL_COPY(&cmKey, _1);
		ZEPHIR_INIT_NVAR(&_2$$3);
		zephir_fast_strtolower(&_2$$3, &cmKey);
		ZEPHIR_INIT_NVAR(&_3$$3);
		zephir_fast_strtolower(&_3$$3, key);
		if (ZEPHIR_IS_EQUAL(&_2$$3, &_3$$3)) {
			RETURN_CCTOR(&cmKey);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&cmKey);
	RETVAL_ZVAL(key, 1, 0);
	RETURN_MM();
}

/***
 * Append messages to this model from another Model.
 */
PHP_METHOD(Phalcon_Mvc_Model, appendMessagesFrom)
{
	zval _1$$5, _4$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, messages, message, *_0$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_1$$5);
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
		zephir_is_iterable(&messages, 0, "phalcon/Mvc/Model.zep", 6289);
		if (Z_TYPE_P(&messages) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&messages), _0$$3)
			{
				ZEPHIR_INIT_NVAR(&message);
				ZVAL_COPY(&message, _0$$3);
				if (Z_TYPE_P(&message) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_1$$5);
					zephir_create_array(&_1$$5, 1, 0);
					zephir_array_update_string(&_1$$5, SL("model"), model, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_1$$5);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_2, 0, &message);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &messages, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_3$$3, &messages, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$3)) {
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
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_2, 0, &message);
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
		zval _0, _2, _4, _6, _8, _10, _12, _14, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7, _11$$8, _13$$9, _15$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_15$$10);
	

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
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("rawValues"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("rawValues"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("oldSnapshot"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("oldSnapshot"), &_9$$7);
		}
		zephir_read_property_ex(&_10, this_ptr, ZEND_STRL("related"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			array_init(&_11$$8);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("related"), &_11$$8);
		}
		zephir_read_property_ex(&_12, this_ptr, ZEND_STRL("errorMessages"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_12) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_13$$9);
			array_init(&_13$$9);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("errorMessages"), &_13$$9);
		}
		zephir_read_property_ex(&_14, this_ptr, ZEND_STRL("dirtyRelated"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_14) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_15$$10);
			array_init(&_15$$10);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("dirtyRelated"), &_15$$10);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

