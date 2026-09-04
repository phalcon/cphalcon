
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
 * $invoice = new Invoices();
 *
 * $invoice->inv_status_flag = "mechanical";
 * $invoice->inv_title = "Test Invoice";
 * $invoice->inv_total = 1952;
 *
 * if ($invoice->save() === false) {
 *     echo "Umh, We can store invoices: ";
 *
 *     $messages = $invoice->getMessages();
 *
 *     foreach ($messages as $message) {
 *         echo $message;
 *     }
 * } else {
 *     echo "Great, a new invoice was saved successfully!";
 * }
 * ```
 *
 * Magic property and method resolution:
 *
 * `__get($property)` resolves in order: a relation alias (returning unsaved
 * `dirtyRelated` records first, then a non-reusable single related model held
 * in the `related` cache - resultsets and reusable relations are never served
 * from that cache - otherwise the freshly fetched related records); then a
 * `get<Property>()` getter when one exists; otherwise it raises an
 * "undefined property" notice and returns null.
 *
 * `__call()` / `__callStatic($method, $arguments)` resolve the `findBy<Field>`,
 * `findFirstBy<Field>`, and `countBy<Field>` magic finders through
 * `invokeFinder()`. The instance `__call()` additionally tries relation getters
 * and a behavior/listener `missingMethod()` hook. An unresolved method throws
 * `Phalcon\Mvc\Model\Exceptions\MethodNotFound`.
 *
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
	 * Per-save many-to-many sync overrides, keyed by lowercased relation
	 * alias (or "*" wildcard) => bool. Cleared after each save().
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_ce, SL("syncRelated"), ZEND_ACC_PROTECTED);
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
	/**
	 * Per-process cache of declared private model properties as
	 * [class name => [property name => ReflectionProperty]], used during
	 * hydration - see getPrivateProperties()
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_ce, SL("privatePropertiesCache"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("modelsManager", 13, 1);
	}

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
		zephir_throw_exception_debug(&_0$$4, "phalcon/Mvc/Model.zep", 280);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 995, container);
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
			zephir_throw_exception_debug(&_4$$6, "phalcon/Mvc/Model.zep", 291);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 996, modelsManager);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}

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
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&status, &_1, "missingmethod", NULL, 0, this_ptr, &method_zv, &arguments);
	zephir_check_call_status();
	if (Z_TYPE_P(&status) != IS_NULL) {
		RETURN_CCTOR(&status);
	}
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, phalcon_mvc_model_exceptions_methodnotfound_ce);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 0, &method_zv, &modelName);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_2, "phalcon/Mvc/Model.zep", 358);
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
	zephir_throw_exception_debug(&_1, "phalcon/Mvc/Model.zep", 382);
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
	zend_bool _5$$3, _7$$3, _10$$3;
	zval method;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval property_zv, modelName, manager, lowerProperty, relation, _0, _15, _16, _17, _1$$3, _4$$3, _6$$3, _8$$3, _9$$3, _11$$3, _12$$3, _2$$4, _3$$4, _13$$5, _14$$5;
	zend_string *property = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property_zv);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&lowerProperty);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&method);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dirtyRelated", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("related", 7, 1);
	}

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
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 997, PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_value(&_1$$3, &lowerProperty)) {
			zephir_read_property_cached(&_2$$4, this_ptr, _zephir_prop_0, 997, PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_3$$4, &_2$$4, &lowerProperty, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 414);
			RETURN_CTOR(&_3$$4);
		}
		zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_1, 998, PH_NOISY_CC | PH_READONLY);
		_5$$3 = zephir_array_isset_value(&_4$$3, &lowerProperty);
		if (_5$$3) {
			ZEPHIR_CALL_METHOD(&_6$$3, &relation, "isreusable", NULL, 0);
			zephir_check_call_status();
			_5$$3 = !zephir_is_true(&_6$$3);
		}
		_7$$3 = _5$$3;
		if (_7$$3) {
			zephir_read_property_cached(&_8$$3, this_ptr, _zephir_prop_1, 998, PH_NOISY_CC | PH_READONLY);
			zephir_memory_observe(&_9$$3);
			zephir_array_fetch(&_9$$3, &_8$$3, &lowerProperty, PH_NOISY, "phalcon/Mvc/Model.zep", 425);
			_7$$3 = Z_TYPE_P(&_9$$3) == IS_OBJECT;
		}
		_10$$3 = _7$$3;
		if (_10$$3) {
			zephir_read_property_cached(&_11$$3, this_ptr, _zephir_prop_1, 998, PH_NOISY_CC | PH_READONLY);
			zephir_memory_observe(&_12$$3);
			zephir_array_fetch(&_12$$3, &_11$$3, &lowerProperty, PH_NOISY, "phalcon/Mvc/Model.zep", 426);
			_10$$3 = zephir_instance_of_ev(&_12$$3, phalcon_mvc_modelinterface_ce);
		}
		if (_10$$3) {
			zephir_read_property_cached(&_13$$5, this_ptr, _zephir_prop_1, 998, PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_14$$5, &_13$$5, &lowerProperty, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 427);
			RETURN_CTOR(&_14$$5);
		}
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrelated", NULL, 0, &lowerProperty);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_15);
	zephir_camelize(&_15, &property_zv, NULL );
	ZEPHIR_INIT_VAR(&_16);
	ZEPHIR_CONCAT_SV(&_16, "get", &_15);
	zephir_get_strval(&method, &_16);
	if ((zephir_method_exists(this_ptr, &method)  == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &method, NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_17);
	ZEPHIR_CONCAT_SVSV(&_17, "Access to undefined property ", &modelName, "::", &property_zv);
	ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 11, &_17);
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dirtyState", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("snapshot", 8, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&snapshot);
	ZVAL_NULL(&snapshot);
	ZVAL_NULL(&_0);
	ZVAL_BOOL(&_1, 0);
	ZEPHIR_CALL_METHOD(&attributes, this_ptr, "toarray", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 999, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dirtyState, &_0);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_2);
	ZEPHIR_CALL_METHOD(&_2, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
	zephir_check_call_status();
	_3 = zephir_is_true(&_2);
	if (_3) {
		zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1000, PH_NOISY_CC | PH_READONLY);
		_3 = Z_TYPE_P(&_0) != IS_NULL;
	}
	_4 = _3;
	if (_4) {
		zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 1000, PH_NOISY_CC | PH_READONLY);
		_4 = !ZEPHIR_IS_EQUAL(&attributes, &_1);
	}
	if (_4) {
		zephir_read_property_cached(&_5$$3, this_ptr, _zephir_prop_1, 1000, PH_NOISY_CC | PH_READONLY);
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
	zend_bool _0, _13$$10, _15$$10;
	zval related;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval property_zv, *value, value_sub, __$null, lowerProperty, modelName, manager, relation, referencedModel, item, dirtyState, _22, _23, _1$$3, _2$$4, _3$$4, _4$$6, _5$$7, _6$$8, _7$$9, _8$$9, *_9$$10, _10$$10, *_11$$10, _12$$10, _14$$10, _16$$10, _17$$17, _18$$18, _19$$19, _20$$20, _21$$20, _24$$22, _25$$23, _26$$23;
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
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$17);
	ZVAL_UNDEF(&_18$$18);
	ZVAL_UNDEF(&_19$$19);
	ZVAL_UNDEF(&_20$$20);
	ZVAL_UNDEF(&_21$$20);
	ZVAL_UNDEF(&_24$$22);
	ZVAL_UNDEF(&_25$$23);
	ZVAL_UNDEF(&_26$$23);
	ZVAL_UNDEF(&related);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dirtyState", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("related", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("dirtyRelated", 12, 1);
	}

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
			zephir_read_property_cached(&_2$$4, this_ptr, _zephir_prop_0, 999, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&dirtyState, &_2$$4);
			ZEPHIR_CALL_METHOD(&_3$$4, value, "getdirtystate", NULL, 0);
			zephir_check_call_status();
			if (!ZEPHIR_IS_EQUAL(&_3$$4, &dirtyState)) {
				ZEPHIR_INIT_NVAR(&dirtyState);
				ZVAL_LONG(&dirtyState, 1);
			}
			zephir_unset_property_array(this_ptr, ZEND_STRL("related"), &lowerProperty);
			zephir_read_property_cached(&_2$$4, this_ptr, _zephir_prop_1, 998, PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_2$$4, &lowerProperty, PH_SEPARATE);
			zephir_update_property_array(this_ptr, SL("dirtyRelated"), &lowerProperty, value);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 999, &dirtyState);
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
			if (ZEPHIR_IS_LONG(&_5$$7, 0)) { goto zephir_switch_0_clause_0; }
			if (ZEPHIR_IS_LONG(&_5$$7, 1)) { goto zephir_switch_0_clause_1; }
			if (ZEPHIR_IS_LONG(&_5$$7, 2)) { goto zephir_switch_0_clause_2; }
			if (ZEPHIR_IS_LONG(&_5$$7, 4)) { goto zephir_switch_0_clause_3; }
			goto zephir_switch_0_end;
			zephir_switch_0_clause_0: ;
			zephir_switch_0_clause_1: ;
				ZEPHIR_CALL_METHOD(&_6$$8, &relation, "getreferencedmodel", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedModel, &manager, "load", NULL, 0, &_6$$8);
				zephir_check_call_status();
				if (Z_TYPE_P(&referencedModel) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD(NULL, &referencedModel, "assign", NULL, 0, value);
					zephir_check_call_status();
					zephir_unset_property_array(this_ptr, ZEND_STRL("related"), &lowerProperty);
					zephir_read_property_cached(&_7$$9, this_ptr, _zephir_prop_1, 998, PH_NOISY_CC | PH_READONLY);
					zephir_array_unset(&_7$$9, &lowerProperty, PH_SEPARATE);
					zephir_update_property_array(this_ptr, SL("dirtyRelated"), &lowerProperty, &referencedModel);
					ZVAL_UNDEF(&_8$$9);
					ZVAL_LONG(&_8$$9, 1);
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 999, &_8$$9);
					RETVAL_ZVAL(value, 1, 0);
					RETURN_MM();
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_2: ;
			zephir_switch_0_clause_3: ;
				ZEPHIR_INIT_VAR(&related);
				array_init(&related);
				if (Z_TYPE_P(value) == IS_STRING) {
					ZEPHIR_INIT_VAR(&_10$$10);
					zephir_string_to_char_array(&_10$$10, value);
					_9$$10 = &_10$$10;
				} else {
					_9$$10 = value;
				}
				zephir_is_iterable(_9$$10, 0, "phalcon/Mvc/Model.zep", 598);
				if (Z_TYPE_P(_9$$10) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_9$$10), _11$$10)
					{
						ZEPHIR_INIT_NVAR(&item);
						ZVAL_COPY(&item, _11$$10);
						if (Z_TYPE_P(&item) == IS_OBJECT) {
							if (zephir_instance_of_ev(&item, phalcon_mvc_modelinterface_ce)) {
								zephir_array_append(&related, &item, PH_SEPARATE, "phalcon/Mvc/Model.zep", 593);
							}
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _9$$10, "rewind", NULL, 0);
					zephir_check_call_status();
					_13$$10 = 1;
					while (1) {
						if (_13$$10) {
							_13$$10 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _9$$10, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_12$$10, _9$$10, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_12$$10)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&item, _9$$10, "current", NULL, 0);
						zephir_check_call_status();
							if (Z_TYPE_P(&item) == IS_OBJECT) {
								if (zephir_instance_of_ev(&item, phalcon_mvc_modelinterface_ce)) {
									zephir_array_append(&related, &item, PH_SEPARATE, "phalcon/Mvc/Model.zep", 593);
								}
							}
					}
				}
				ZEPHIR_INIT_NVAR(&item);
				zephir_unset_property_array(this_ptr, ZEND_STRL("related"), &lowerProperty);
				zephir_read_property_cached(&_14$$10, this_ptr, _zephir_prop_1, 998, PH_NOISY_CC | PH_READONLY);
				zephir_array_unset(&_14$$10, &lowerProperty, PH_SEPARATE);
				_15$$10 = !(ZEPHIR_IS_EMPTY(&related));
				if (!(_15$$10)) {
					ZEPHIR_CALL_METHOD(&_16$$10, &relation, "gettype", NULL, 0);
					zephir_check_call_status();
					_15$$10 = ZEPHIR_IS_LONG_IDENTICAL(&_16$$10, 4);
				}
				if (_15$$10) {
					zephir_update_property_array(this_ptr, SL("dirtyRelated"), &lowerProperty, &related);
					ZVAL_UNDEF(&_17$$17);
					ZVAL_LONG(&_17$$17, 1);
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 999, &_17$$17);
				} else {
					zephir_unset_property_array(this_ptr, ZEND_STRL("dirtyRelated"), &lowerProperty);
					zephir_read_property_cached(&_18$$18, this_ptr, _zephir_prop_2, 997, PH_NOISY_CC | PH_READONLY);
					zephir_array_unset(&_18$$18, &lowerProperty, PH_SEPARATE);
				}
				RETVAL_ZVAL(value, 1, 0);
				RETURN_MM();
			zephir_switch_0_end: ;

		}
	} else if (Z_TYPE_P(value) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&lowerProperty);
		zephir_fast_strtolower(&lowerProperty, &property_zv);
		ZEPHIR_INIT_NVAR(&modelName);
		zephir_get_class(&modelName, this_ptr, 0);
		ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_19$$19, &manager, "getrelationbyalias", NULL, 0, &modelName, &lowerProperty);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_19$$19);
		if (Z_TYPE_P(&relation) == IS_OBJECT) {
			zephir_unset_property_array(this_ptr, ZEND_STRL("related"), &lowerProperty);
			zephir_read_property_cached(&_20$$20, this_ptr, _zephir_prop_1, 998, PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_20$$20, &lowerProperty, PH_SEPARATE);
			zephir_unset_property_array(this_ptr, ZEND_STRL("dirtyRelated"), &lowerProperty);
			zephir_read_property_cached(&_21$$20, this_ptr, _zephir_prop_2, 997, PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_21$$20, &lowerProperty, PH_SEPARATE);
			zephir_update_property_zval_zval(this_ptr, &property_zv, &__$null);
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_CALL_METHOD(&_22, this_ptr, "possiblesetter", NULL, 0, &property_zv, value);
	zephir_check_call_status();
	if (zephir_is_true(&_22)) {
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_23, "property_exists", NULL, 10, this_ptr, &property_zv);
	zephir_check_call_status();
	if (zephir_is_true(&_23)) {
		ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_24$$22, &manager, "isvisiblemodelproperty", NULL, 0, this_ptr, &property_zv);
		zephir_check_call_status();
		if (UNEXPECTED(!zephir_is_true(&_24$$22))) {
			ZEPHIR_INIT_VAR(&_25$$23);
			object_init_ex(&_25$$23, phalcon_mvc_model_exceptions_propertynotaccessible_ce);
			ZEPHIR_INIT_VAR(&_26$$23);
			zephir_get_class(&_26$$23, this_ptr, 0);
			ZEPHIR_CALL_METHOD(NULL, &_25$$23, "__construct", NULL, 0, &property_zv, &_26$$23);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_25$$23, "phalcon/Mvc/Model.zep", 660);
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
	zend_bool _13$$7;
	zend_string *_11$$7;
	zend_ulong _10$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, container, manager, key, value, snapshot, properties, dirtyState, _3, _4, _0$$3, _1$$4, _2$$4, _5$$5, _6$$5, *_7$$7, _8$$7, *_9$$7, _12$$7, _14$$13;
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
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_14$$13);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("modelsManager", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("dirtyState", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("snapshot", 8, 1);
	}

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
		zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/Model.zep", 687);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 995, &container);
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
		zephir_throw_exception_debug(&_5$$5, "phalcon/Mvc/Model.zep", 700);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 996, &manager);
	ZEPHIR_CALL_METHOD(NULL, &manager, "initialize", NULL, 0, this_ptr);
	zephir_check_call_status();
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("onconstruct")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "onconstruct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_memory_observe(&properties);
	if (zephir_array_isset_string_fetch(&properties, &data, SL("attributes"), 0)) {
		if (Z_TYPE_P(&properties) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_8$$7);
			zephir_string_to_char_array(&_8$$7, &properties);
			_7$$7 = &_8$$7;
		} else {
			_7$$7 = &properties;
		}
		zephir_is_iterable(_7$$7, 0, "phalcon/Mvc/Model.zep", 731);
		if (Z_TYPE_P(_7$$7) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_7$$7), _10$$7, _11$$7, _9$$7)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_11$$7 != NULL) { 
					ZVAL_STR_COPY(&key, _11$$7);
				} else {
					ZVAL_LONG(&key, _10$$7);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _9$$7);
				zephir_update_property_zval_zval(this_ptr, &key, &value);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _7$$7, "rewind", NULL, 0);
			zephir_check_call_status();
			_13$$7 = 1;
			while (1) {
				if (_13$$7) {
					_13$$7 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _7$$7, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_12$$7, _7$$7, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_12$$7)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, _7$$7, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, _7$$7, "current", NULL, 0);
				zephir_check_call_status();
					zephir_update_property_zval_zval(this_ptr, &key, &value);
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 999, &dirtyState);
	}
	ZEPHIR_CALL_METHOD(&_3, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		if (zephir_array_isset_string_fetch(&snapshot, &data, SL("snapshot"), 1)) {
			ZEPHIR_INIT_VAR(&_14$$13);
			if (Z_TYPE_P(&snapshot) != IS_NULL) {
				ZEPHIR_CPY_WRT(&_14$$13, &snapshot);
			} else {
				ZEPHIR_CPY_WRT(&_14$$13, &properties);
			}
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1000, &_14$$13);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1000, &properties);
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
 * class Invoices extends Model
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(behavior, phalcon_mvc_model_behaviorinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &behavior);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
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
 * class Invoices extends Model
 * {
 *     public function beforeSave()
 *     {
 *         if ($this->name === "Peter") {
 *             $message = new Message(
 *                 "Sorry, but an invoice cannot be named Peter"
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
 * $invoice->assign(
 *     [
 *         "type" => "mechanical",
 *         "name" => "Test Invoice",
 *         "year" => 1952,
 *     ]
 * );
 *
 * // Assign by db row, column map needed
 * $invoice->assign(
 *     $dbRow,
 *     [
 *         "db_type" => "type",
 *         "db_name" => "name",
 *         "db_year" => "year",
 *     ]
 * );
 *
 * // Allow assign only name and year
 * $invoice->assign(
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
 * $invoice->assign(
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
	zend_string *_3$$3;
	zend_ulong _2$$3;
	zend_bool _28, _5$$3, _10$$12, _11$$12, _22$$18, _23$$18, _24$$18, _29$$22, _30$$22, _38$$28, _39$$28, _40$$28;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL, *_16 = NULL, *_21 = NULL, *_26 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *whiteList = NULL, whiteList_sub, *dataColumnMap = NULL, dataColumnMap_sub, __$null, key, keyMapped, value, attribute, attributeField, metaData, columnMap, disableAssignSetters, rawValues, _0, _6, _7, *_8, *_9, _27, *_1$$3, _4$$3, _12$$12, _14$$12, _15$$13, _17$$15, _18$$15, _19$$16, _20$$16, _25$$18, _31$$22, _32$$22, _33$$23, _34$$25, _35$$25, _36$$26, _37$$26, _41$$28;
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
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_17$$15);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_19$$16);
	ZVAL_UNDEF(&_20$$16);
	ZVAL_UNDEF(&_25$$18);
	ZVAL_UNDEF(&_31$$22);
	ZVAL_UNDEF(&_32$$22);
	ZVAL_UNDEF(&_33$$23);
	ZVAL_UNDEF(&_34$$25);
	ZVAL_UNDEF(&_35$$25);
	ZVAL_UNDEF(&_36$$26);
	ZVAL_UNDEF(&_37$$26);
	ZVAL_UNDEF(&_41$$28);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("rawValues", 9, 1);
	}

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
	zephir_get_arrval(&data, data_param);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1001, &rawValues);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "orm.disable_assign_setters");
	ZEPHIR_CALL_CE_STATIC(&disableAssignSetters, phalcon_support_settings_ce, "get", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(dataColumnMap) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&dataMapped);
		array_init(&dataMapped);
		zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 896);
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
			_5$$3 = 1;
			while (1) {
				if (_5$$3) {
					_5$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
					zephir_check_call_status();
				}
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
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		ZEPHIR_CPY_WRT(&dataMapped, &data);
	}
	if (ZEPHIR_IS_EMPTY(&dataMapped)) {
		RETURN_THIS();
	}
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "orm.column_renaming");
	ZEPHIR_CALL_CE_STATIC(&_6, phalcon_support_settings_ce, "get", NULL, 0, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_6)) {
		ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&columnMap);
		ZVAL_NULL(&columnMap);
	}
	ZEPHIR_CALL_METHOD(&_7, &metaData, "getattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (Z_TYPE_P(&_7) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_0);
		zephir_string_to_char_array(&_0, &_7);
		_8 = &_0;
	} else {
		_8 = &_7;
	}
	zephir_is_iterable(_8, 0, "phalcon/Mvc/Model.zep", 953);
	if (Z_TYPE_P(_8) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_8), _9)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _9);
			_10$$12 = Z_TYPE_P(&columnMap) == IS_ARRAY;
			if (_10$$12) {
				_10$$12 = !(zephir_array_isset_value(&columnMap, &attribute));
			}
			_11$$12 = _10$$12;
			if (_11$$12) {
				ZEPHIR_INIT_NVAR(&_14$$12);
				ZVAL_STRING(&_14$$12, "orm.case_insensitive_column_map");
				ZEPHIR_CALL_CE_STATIC(&_12$$12, phalcon_support_settings_ce, "get", &_13, 0, &_14$$12);
				zephir_check_call_status();
				_11$$12 = zephir_is_true(&_12$$12);
			}
			if (_11$$12) {
				ZEPHIR_CALL_SELF(&_15$$13, "caseinsensitivecolumnmap", &_16, 0, &columnMap, &attribute);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&attribute, &_15$$13);
			}
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0))) {
					ZEPHIR_INIT_NVAR(&_18$$15);
					ZVAL_STRING(&_18$$15, "orm.ignore_unknown_columns");
					ZEPHIR_CALL_CE_STATIC(&_17$$15, phalcon_support_settings_ce, "get", &_13, 0, &_18$$15);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&_17$$15))) {
						ZEPHIR_INIT_NVAR(&_19$$16);
						object_init_ex(&_19$$16, phalcon_mvc_model_exceptions_columnnotinmap_ce);
						ZEPHIR_INIT_NVAR(&_20$$16);
						zephir_get_class(&_20$$16, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_19$$16, "__construct", &_21, 0, &attribute, &_20$$16);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_19$$16, "phalcon/Mvc/Model.zep", 927);
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
				_22$$18 = Z_TYPE_P(whiteList) == IS_ARRAY;
				if (_22$$18) {
					_22$$18 = !(zephir_fast_in_array(&attributeField, whiteList));
				}
				if (_22$$18) {
					continue;
				}
				_23$$18 = Z_TYPE_P(&value) == IS_OBJECT;
				if (_23$$18) {
					_23$$18 = zephir_instance_of_ev(&value, phalcon_db_rawvalue_ce);
				}
				if (_23$$18) {
					zephir_array_update_zval(&rawValues, &attributeField, &value, PH_COPY | PH_SEPARATE);
				} else {
					_24$$18 = zephir_is_true(&disableAssignSetters);
					if (!(_24$$18)) {
						ZEPHIR_CALL_METHOD(&_25$$18, this_ptr, "possiblesetter", &_26, 0, &attributeField, &value);
						zephir_check_call_status();
						_24$$18 = !zephir_is_true(&_25$$18);
					}
					if (_24$$18) {
						zephir_update_property_zval_zval(this_ptr, &attributeField, &value);
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _8, "rewind", NULL, 0);
		zephir_check_call_status();
		_28 = 1;
		while (1) {
			if (_28) {
				_28 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _8, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_27, _8, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_27)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attribute, _8, "current", NULL, 0);
			zephir_check_call_status();
				_29$$22 = Z_TYPE_P(&columnMap) == IS_ARRAY;
				if (_29$$22) {
					_29$$22 = !(zephir_array_isset_value(&columnMap, &attribute));
				}
				_30$$22 = _29$$22;
				if (_30$$22) {
					ZEPHIR_INIT_NVAR(&_32$$22);
					ZVAL_STRING(&_32$$22, "orm.case_insensitive_column_map");
					ZEPHIR_CALL_CE_STATIC(&_31$$22, phalcon_support_settings_ce, "get", &_13, 0, &_32$$22);
					zephir_check_call_status();
					_30$$22 = zephir_is_true(&_31$$22);
				}
				if (_30$$22) {
					ZEPHIR_CALL_SELF(&_33$$23, "caseinsensitivecolumnmap", &_16, 0, &columnMap, &attribute);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&attribute, &_33$$23);
				}
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0))) {
						ZEPHIR_INIT_NVAR(&_35$$25);
						ZVAL_STRING(&_35$$25, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_34$$25, phalcon_support_settings_ce, "get", &_13, 0, &_35$$25);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_34$$25))) {
							ZEPHIR_INIT_NVAR(&_36$$26);
							object_init_ex(&_36$$26, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							ZEPHIR_INIT_NVAR(&_37$$26);
							zephir_get_class(&_37$$26, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_36$$26, "__construct", &_21, 0, &attribute, &_37$$26);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_36$$26, "phalcon/Mvc/Model.zep", 927);
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
					_38$$28 = Z_TYPE_P(whiteList) == IS_ARRAY;
					if (_38$$28) {
						_38$$28 = !(zephir_fast_in_array(&attributeField, whiteList));
					}
					if (_38$$28) {
						continue;
					}
					_39$$28 = Z_TYPE_P(&value) == IS_OBJECT;
					if (_39$$28) {
						_39$$28 = zephir_instance_of_ev(&value, phalcon_db_rawvalue_ce);
					}
					if (_39$$28) {
						zephir_array_update_zval(&rawValues, &attributeField, &value, PH_COPY | PH_SEPARATE);
					} else {
						_40$$28 = zephir_is_true(&disableAssignSetters);
						if (!(_40$$28)) {
							ZEPHIR_CALL_METHOD(&_41$$28, this_ptr, "possiblesetter", &_26, 0, &attributeField, &value);
							zephir_check_call_status();
							_40$$28 = !zephir_is_true(&_41$$28);
						}
						if (_40$$28) {
							zephir_update_property_zval_zval(this_ptr, &attributeField, &value);
						}
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&attribute);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1001, &rawValues);
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
 * // What's the average price of invoices?
 * $average = Invoices::average(
 *     [
 *         "column" => "inv_total",
 *     ]
 * );
 *
 * echo "The average price is ", $average, "\n";
 *
 * // What's the average price of paid invoices?
 * $average = Invoices::average(
 *     [
 *         "inv_status_flag = 1",
 *         "column" => "inv_total",
 *     ]
 * );
 *
 * echo "The average price of paid invoices is ", $average, "\n";
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
	if (Z_TYPE_P(&result) == IS_NULL) {
		RETURN_MM_DOUBLE(0.0);
	}
	RETURN_CCTOR(&result);
}

/**
 * Assigns values to a model from an array returning a new model
 *
 *```php
 * $invoice = Phalcon\Mvc\Model::cloneResult(
 *     new Invoices(),
 *     [
 *         "type" => "mechanical",
 *         "name" => "Test Invoice",
 *         "year" => 1952,
 *     ]
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model, cloneResult)
{
	zend_bool _10;
	zend_string *_5;
	zend_ulong _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_0 = NULL, *_8 = NULL;
	zend_long dirtyState, ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *base, base_sub, *data_param = NULL, *dirtyState_param = NULL, instance, key, privateProperties, reflectionProperty, value, _1, _2, *_3, _9, _13, _6$$4, _7$$4, _11$$8, _12$$8;

	ZVAL_UNDEF(&base_sub);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&privateProperties);
	ZVAL_UNDEF(&reflectionProperty);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);
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
	zephir_get_arrval(&data, data_param);
	if (!dirtyState_param) {
		dirtyState = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&instance);
	if (zephir_clone(&instance, base) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_get_class(&_1, &instance, 0);
	ZEPHIR_CALL_SELF(&privateProperties, "getprivateproperties", &_0, 0, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_2, dirtyState);
	ZEPHIR_CALL_METHOD(NULL, &instance, "setdirtystate", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 1058);
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
			if (UNEXPECTED(Z_TYPE_P(&key) != IS_STRING)) {
				ZEPHIR_INIT_NVAR(&_6$$4);
				object_init_ex(&_6$$4, phalcon_mvc_model_exceptions_invaliddumpresultkey_ce);
				ZEPHIR_INIT_NVAR(&_7$$4);
				zephir_get_class(&_7$$4, base, 0);
				ZEPHIR_CALL_METHOD(NULL, &_6$$4, "__construct", &_8, 0, &_7$$4);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_6$$4, "phalcon/Mvc/Model.zep", 1043);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (UNEXPECTED(zephir_array_isset_value(&privateProperties, &key))) {
				ZEPHIR_OBS_NVAR(&reflectionProperty);
				zephir_array_fetch(&reflectionProperty, &privateProperties, &key, PH_NOISY, "phalcon/Mvc/Model.zep", 1047);
				ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setvalue", NULL, 0, &instance, &value);
				zephir_check_call_status();
			} else {
				zephir_update_property_zval_zval(&instance, &key, &value);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		_10 = 1;
		while (1) {
			if (_10) {
				_10 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_9, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&key) != IS_STRING)) {
					ZEPHIR_INIT_NVAR(&_11$$8);
					object_init_ex(&_11$$8, phalcon_mvc_model_exceptions_invaliddumpresultkey_ce);
					ZEPHIR_INIT_NVAR(&_12$$8);
					zephir_get_class(&_12$$8, base, 0);
					ZEPHIR_CALL_METHOD(NULL, &_11$$8, "__construct", &_8, 0, &_12$$8);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_11$$8, "phalcon/Mvc/Model.zep", 1043);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(zephir_array_isset_value(&privateProperties, &key))) {
					ZEPHIR_OBS_NVAR(&reflectionProperty);
					zephir_array_fetch(&reflectionProperty, &privateProperties, &key, PH_NOISY, "phalcon/Mvc/Model.zep", 1047);
					ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setvalue", NULL, 0, &instance, &value);
					zephir_check_call_status();
				} else {
					zephir_update_property_zval_zval(&instance, &key, &value);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_STRING(&_13, "afterFetch");
	ZEPHIR_CALL_METHOD(NULL, &instance, "fireevent", NULL, 0, &_13);
	zephir_check_call_status();
	RETURN_CCTOR(&instance);
}

/**
 * Assigns values to a model from an array, returning a new model.
 *
 *```php
 * $invoice = \Phalcon\Mvc\Model::cloneResultMap(
 *     new Invoices(),
 *     [
 *         "type" => "mechanical",
 *         "name" => "Test Invoice",
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
	zend_string *_7;
	zend_ulong _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_0 = NULL, *_15 = NULL, *_19 = NULL, *_31 = NULL, *_33 = NULL;
	zend_bool keepSnapshots, callSetters = 0, _42, _8$$5, _28$$5, _10$$9, _13$$17, _25$$25, _38$$44, _43$$52, _61$$52, _45$$56, _48$$64, _58$$72, _69$$91;
	zend_long dirtyState, ZEPHIR_LAST_CALL_STATUS;
	zval data, localMethods;
	zval *base, base_sub, *data_param = NULL, *columnMap, columnMap_sub, *dirtyState_param = NULL, *keepSnapshots_param = NULL, instance, attribute, key, value, castValue, attributeName, metaData, reverseMap, notNullAttributes, privateProperties, reflectionProperty, setter, _1, _2, _3, _4, *_5, _41, _9$$9, _11$$10, _12$$10, _14$$20, _16$$20, _17$$21, _18$$21, _20$$22, _21$$22, _22$$23, _23$$23, _24$$25, _26$$26, _27$$26, _29$$33, _30$$34, _32$$38, _34$$37, _35$$37, _36$$41, _37$$44, _39$$45, _40$$45, _44$$56, _46$$57, _47$$57, _49$$67, _50$$67, _51$$68, _52$$68, _53$$69, _54$$69, _55$$70, _56$$70, _57$$72, _59$$73, _60$$73, _62$$80, _63$$81, _64$$85, _65$$84, _66$$84, _67$$88, _68$$91, _70$$92, _71$$92, _72$$99, _73$$100;

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
	ZVAL_UNDEF(&privateProperties);
	ZVAL_UNDEF(&reflectionProperty);
	ZVAL_UNDEF(&setter);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_14$$20);
	ZVAL_UNDEF(&_16$$20);
	ZVAL_UNDEF(&_17$$21);
	ZVAL_UNDEF(&_18$$21);
	ZVAL_UNDEF(&_20$$22);
	ZVAL_UNDEF(&_21$$22);
	ZVAL_UNDEF(&_22$$23);
	ZVAL_UNDEF(&_23$$23);
	ZVAL_UNDEF(&_24$$25);
	ZVAL_UNDEF(&_26$$26);
	ZVAL_UNDEF(&_27$$26);
	ZVAL_UNDEF(&_29$$33);
	ZVAL_UNDEF(&_30$$34);
	ZVAL_UNDEF(&_32$$38);
	ZVAL_UNDEF(&_34$$37);
	ZVAL_UNDEF(&_35$$37);
	ZVAL_UNDEF(&_36$$41);
	ZVAL_UNDEF(&_37$$44);
	ZVAL_UNDEF(&_39$$45);
	ZVAL_UNDEF(&_40$$45);
	ZVAL_UNDEF(&_44$$56);
	ZVAL_UNDEF(&_46$$57);
	ZVAL_UNDEF(&_47$$57);
	ZVAL_UNDEF(&_49$$67);
	ZVAL_UNDEF(&_50$$67);
	ZVAL_UNDEF(&_51$$68);
	ZVAL_UNDEF(&_52$$68);
	ZVAL_UNDEF(&_53$$69);
	ZVAL_UNDEF(&_54$$69);
	ZVAL_UNDEF(&_55$$70);
	ZVAL_UNDEF(&_56$$70);
	ZVAL_UNDEF(&_57$$72);
	ZVAL_UNDEF(&_59$$73);
	ZVAL_UNDEF(&_60$$73);
	ZVAL_UNDEF(&_62$$80);
	ZVAL_UNDEF(&_63$$81);
	ZVAL_UNDEF(&_64$$85);
	ZVAL_UNDEF(&_65$$84);
	ZVAL_UNDEF(&_66$$84);
	ZVAL_UNDEF(&_67$$88);
	ZVAL_UNDEF(&_68$$91);
	ZVAL_UNDEF(&_70$$92);
	ZVAL_UNDEF(&_71$$92);
	ZVAL_UNDEF(&_72$$99);
	ZVAL_UNDEF(&_73$$100);
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
	zephir_get_arrval(&data, data_param);
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
	ZEPHIR_INIT_VAR(&_1);
	zephir_get_class(&_1, &instance, 0);
	ZEPHIR_CALL_SELF(&privateProperties, "getprivateproperties", &_0, 0, &_1);
	zephir_check_call_status();
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
	ZVAL_LONG(&_2, dirtyState);
	ZEPHIR_CALL_METHOD(NULL, &instance, "setdirtystate", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "orm.call_setters_on_hydration");
	ZEPHIR_CALL_CE_STATIC(&_3, phalcon_support_settings_ce, "get", NULL, 0, &_4);
	zephir_check_call_status();
	callSetters = zephir_get_boolval(&_3);
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
	zephir_is_iterable(&data, 1, "phalcon/Mvc/Model.zep", 1317);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _6, _7, _5)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&key, _7);
			} else {
				ZVAL_LONG(&key, _6);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _5);
			if (Z_TYPE_P(&key) != IS_STRING) {
				continue;
			}
			_8$$5 = Z_TYPE_P(&value) == IS_NULL;
			if (_8$$5) {
				_8$$5 = zephir_fast_in_array(&key, &notNullAttributes);
			}
			if (_8$$5) {
				continue;
			}
			if (Z_TYPE_P(columnMap) != IS_ARRAY) {
				if (callSetters) {
					ZEPHIR_INIT_NVAR(&_9$$9);
					zephir_camelize(&_9$$9, &key, NULL );
					ZEPHIR_INIT_NVAR(&setter);
					ZEPHIR_CONCAT_SV(&setter, "set", &_9$$9);
					_10$$9 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
					if (_10$$9) {
						_10$$9 = !(zephir_array_isset_value(&localMethods, &setter));
					}
					if (_10$$9) {

						/* try_start_1: */

							ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &value);
							zephir_check_call_status_or_jump(try_end_1);

						try_end_1:

						if (EG(exception)) {
							ZEPHIR_INIT_NVAR(&_11$$10);
							ZVAL_OBJ(&_11$$10, EG(exception));
							Z_ADDREF_P(&_11$$10);
							ZEPHIR_INIT_NVAR(&_12$$10);
							if (zephir_is_instance_of(&_11$$10, SL("TypeError"))) {
								zend_clear_exception();
								ZEPHIR_CPY_WRT(&_12$$10, &_11$$10);
								if (UNEXPECTED(zephir_array_isset_value(&privateProperties, &key))) {
									ZEPHIR_OBS_NVAR(&reflectionProperty);
									zephir_array_fetch(&reflectionProperty, &privateProperties, &key, PH_NOISY, "phalcon/Mvc/Model.zep", 1150);
									ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setvalue", NULL, 0, &instance, &value);
									zephir_check_call_status();
								} else {
									zephir_update_property_zval_zval(&instance, &key, &value);
								}
							}
						}
						continue;
					}
				}
				if (UNEXPECTED(zephir_array_isset_value(&privateProperties, &key))) {
					ZEPHIR_OBS_NVAR(&reflectionProperty);
					zephir_array_fetch(&reflectionProperty, &privateProperties, &key, PH_NOISY, "phalcon/Mvc/Model.zep", 1161);
					ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setvalue", NULL, 0, &instance, &value);
					zephir_check_call_status();
				} else {
					zephir_update_property_zval_zval(&instance, &key, &value);
				}
				continue;
			}
			ZEPHIR_OBS_NVAR(&attribute);
			if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0))) {
				_13$$17 = Z_TYPE_P(columnMap) == IS_ARRAY;
				if (_13$$17) {
					_13$$17 = !(ZEPHIR_IS_EMPTY(columnMap));
				}
				if (_13$$17) {
					if (Z_TYPE_P(&metaData) == IS_NULL) {
						ZEPHIR_CALL_METHOD(&metaData, &instance, "getmodelsmetadata", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&reverseMap, &metaData, "getreversecolumnmap", NULL, 0, &instance);
					zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&attribute);
					if (!(zephir_array_isset_fetch(&attribute, &reverseMap, &key, 0))) {
						ZEPHIR_INIT_NVAR(&_16$$20);
						ZVAL_STRING(&_16$$20, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_14$$20, phalcon_support_settings_ce, "get", &_15, 0, &_16$$20);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_14$$20))) {
							ZEPHIR_INIT_NVAR(&_17$$21);
							object_init_ex(&_17$$21, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							ZEPHIR_INIT_NVAR(&_18$$21);
							zephir_get_class(&_18$$21, base, 0);
							ZEPHIR_CALL_METHOD(NULL, &_17$$21, "__construct", &_19, 0, &key, &_18$$21);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_17$$21, "phalcon/Mvc/Model.zep", 1180);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
				} else {
					ZEPHIR_INIT_NVAR(&_21$$22);
					ZVAL_STRING(&_21$$22, "orm.ignore_unknown_columns");
					ZEPHIR_CALL_CE_STATIC(&_20$$22, phalcon_support_settings_ce, "get", &_15, 0, &_21$$22);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&_20$$22))) {
						ZEPHIR_INIT_NVAR(&_22$$23);
						object_init_ex(&_22$$23, phalcon_mvc_model_exceptions_columnnotinmap_ce);
						ZEPHIR_INIT_NVAR(&_23$$23);
						zephir_get_class(&_23$$23, base, 0);
						ZEPHIR_CALL_METHOD(NULL, &_22$$23, "__construct", &_19, 0, &key, &_23$$23);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_22$$23, "phalcon/Mvc/Model.zep", 1187);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
			}
			if (Z_TYPE_P(&attribute) != IS_ARRAY) {
				if (callSetters) {
					ZEPHIR_INIT_NVAR(&_24$$25);
					zephir_camelize(&_24$$25, &attribute, NULL );
					ZEPHIR_INIT_NVAR(&setter);
					ZEPHIR_CONCAT_SV(&setter, "set", &_24$$25);
					_25$$25 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
					if (_25$$25) {
						_25$$25 = !(zephir_array_isset_value(&localMethods, &setter));
					}
					if (_25$$25) {

						/* try_start_2: */

							ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &value);
							zephir_check_call_status_or_jump(try_end_2);

						try_end_2:

						if (EG(exception)) {
							ZEPHIR_INIT_NVAR(&_26$$26);
							ZVAL_OBJ(&_26$$26, EG(exception));
							Z_ADDREF_P(&_26$$26);
							ZEPHIR_INIT_NVAR(&_27$$26);
							if (zephir_is_instance_of(&_26$$26, SL("TypeError"))) {
								zend_clear_exception();
								ZEPHIR_CPY_WRT(&_27$$26, &_26$$26);
								if (UNEXPECTED(zephir_array_isset_value(&privateProperties, &attribute))) {
									ZEPHIR_OBS_NVAR(&reflectionProperty);
									zephir_array_fetch(&reflectionProperty, &privateProperties, &attribute, PH_NOISY, "phalcon/Mvc/Model.zep", 1202);
									ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setvalue", NULL, 0, &instance, &value);
									zephir_check_call_status();
								} else {
									zephir_update_property_zval_zval(&instance, &attribute, &value);
								}
							}
						}
						continue;
					}
				}
				if (UNEXPECTED(zephir_array_isset_value(&privateProperties, &attribute))) {
					ZEPHIR_OBS_NVAR(&reflectionProperty);
					zephir_array_fetch(&reflectionProperty, &privateProperties, &attribute, PH_NOISY, "phalcon/Mvc/Model.zep", 1213);
					ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setvalue", NULL, 0, &instance, &value);
					zephir_check_call_status();
				} else {
					zephir_update_property_zval_zval(&instance, &attribute, &value);
				}
				continue;
			}
			_28$$5 = !ZEPHIR_IS_STRING(&value, "");
			if (_28$$5) {
				_28$$5 = Z_TYPE_P(&value) != IS_NULL;
			}
			if (_28$$5) {
				zephir_array_fetch_long(&_29$$33, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 1223);
				if (ZEPHIR_IS_LONG(&_29$$33, 0)) { goto zephir_switch_0_clause_0; }
				if (ZEPHIR_IS_LONG(&_29$$33, 21)) { goto zephir_switch_0_clause_1; }
				if (ZEPHIR_IS_LONG(&_29$$33, 22)) { goto zephir_switch_0_clause_2; }
				if (ZEPHIR_IS_LONG(&_29$$33, 26)) { goto zephir_switch_0_clause_3; }
				if (ZEPHIR_IS_LONG(&_29$$33, 3)) { goto zephir_switch_0_clause_4; }
				if (ZEPHIR_IS_LONG(&_29$$33, 9)) { goto zephir_switch_0_clause_5; }
				if (ZEPHIR_IS_LONG(&_29$$33, 7)) { goto zephir_switch_0_clause_6; }
				if (ZEPHIR_IS_LONG(&_29$$33, 8)) { goto zephir_switch_0_clause_7; }
				if (ZEPHIR_IS_LONG(&_29$$33, 40)) { goto zephir_switch_0_clause_8; }
				if (ZEPHIR_IS_LONG(&_29$$33, 41)) { goto zephir_switch_0_clause_9; }
				if (ZEPHIR_IS_LONG(&_29$$33, 42)) { goto zephir_switch_0_clause_10; }
				if (ZEPHIR_IS_LONG(&_29$$33, 43)) { goto zephir_switch_0_clause_11; }
				if (ZEPHIR_IS_LONG(&_29$$33, 44)) { goto zephir_switch_0_clause_12; }
				if (ZEPHIR_IS_LONG(&_29$$33, 45)) { goto zephir_switch_0_clause_13; }
				if (ZEPHIR_IS_LONG(&_29$$33, 46)) { goto zephir_switch_0_clause_14; }
				if (ZEPHIR_IS_LONG(&_29$$33, 47)) { goto zephir_switch_0_clause_15; }
				goto zephir_switch_0_clause_16;
				zephir_switch_0_clause_0: ;
				zephir_switch_0_clause_1: ;
				zephir_switch_0_clause_2: ;
				zephir_switch_0_clause_3: ;
					ZVAL_LONG(&_30$$34, 10);
					ZEPHIR_CALL_FUNCTION(&castValue, "intval", &_31, 96, &value, &_30$$34);
					zephir_check_call_status();
					goto zephir_switch_0_end;
				zephir_switch_0_clause_4: ;
				zephir_switch_0_clause_5: ;
				zephir_switch_0_clause_6: ;
					ZEPHIR_INIT_NVAR(&castValue);
					ZVAL_DOUBLE(&castValue, zephir_get_doubleval(&value));
					goto zephir_switch_0_end;
				zephir_switch_0_clause_7: ;
					ZEPHIR_INIT_NVAR(&castValue);
					ZVAL_BOOL(&castValue, zephir_get_boolval(&value));
					goto zephir_switch_0_end;
				zephir_switch_0_clause_8: ;
				zephir_switch_0_clause_9: ;
				zephir_switch_0_clause_10: ;
				zephir_switch_0_clause_11: ;
				zephir_switch_0_clause_12: ;
				zephir_switch_0_clause_13: ;
				zephir_switch_0_clause_14: ;
				zephir_switch_0_clause_15: ;

					/* try_start_3: */

						ZEPHIR_INIT_NVAR(&_32$$38);
						object_init_ex(&_32$$38, phalcon_db_geometry_wkbparser_ce);
						if (zephir_has_constructor(&_32$$38)) {
							ZEPHIR_CALL_METHOD(NULL, &_32$$38, "__construct", NULL, 0);
							zephir_check_call_status_or_jump(try_end_3);
						}

						ZEPHIR_CALL_METHOD(&castValue, &_32$$38, "parse", &_33, 0, &value);
						zephir_check_call_status_or_jump(try_end_3);

					try_end_3:

					if (EG(exception)) {
						ZEPHIR_INIT_NVAR(&_34$$37);
						ZVAL_OBJ(&_34$$37, EG(exception));
						Z_ADDREF_P(&_34$$37);
						ZEPHIR_INIT_NVAR(&_35$$37);
						if (zephir_instance_of_ev(&_34$$37, phalcon_db_exceptions_invalidwkb_ce)) {
							zend_clear_exception();
							ZEPHIR_CPY_WRT(&_35$$37, &_34$$37);
							ZEPHIR_CPY_WRT(&castValue, &value);
						}
					}
					goto zephir_switch_0_end;
				zephir_switch_0_clause_16: ;
					ZEPHIR_CPY_WRT(&castValue, &value);
					goto zephir_switch_0_end;
				zephir_switch_0_end: ;

			} else {
				zephir_array_fetch_long(&_36$$41, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 1262);
				if (ZEPHIR_IS_LONG(&_36$$41, 14)) { goto zephir_switch_1_clause_0; }
				if (ZEPHIR_IS_LONG(&_36$$41, 8)) { goto zephir_switch_1_clause_1; }
				if (ZEPHIR_IS_LONG(&_36$$41, 3)) { goto zephir_switch_1_clause_2; }
				if (ZEPHIR_IS_LONG(&_36$$41, 9)) { goto zephir_switch_1_clause_3; }
				if (ZEPHIR_IS_LONG(&_36$$41, 7)) { goto zephir_switch_1_clause_4; }
				if (ZEPHIR_IS_LONG(&_36$$41, 0)) { goto zephir_switch_1_clause_5; }
				if (ZEPHIR_IS_LONG(&_36$$41, 21)) { goto zephir_switch_1_clause_6; }
				if (ZEPHIR_IS_LONG(&_36$$41, 22)) { goto zephir_switch_1_clause_7; }
				if (ZEPHIR_IS_LONG(&_36$$41, 26)) { goto zephir_switch_1_clause_8; }
				goto zephir_switch_1_clause_9;
				zephir_switch_1_clause_0: ;
				zephir_switch_1_clause_1: ;
				zephir_switch_1_clause_2: ;
				zephir_switch_1_clause_3: ;
				zephir_switch_1_clause_4: ;
				zephir_switch_1_clause_5: ;
				zephir_switch_1_clause_6: ;
				zephir_switch_1_clause_7: ;
				zephir_switch_1_clause_8: ;
					ZEPHIR_INIT_NVAR(&castValue);
					ZVAL_NULL(&castValue);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_9: ;
					ZEPHIR_CPY_WRT(&castValue, &value);
					goto zephir_switch_1_end;
				zephir_switch_1_end: ;

			}
			ZEPHIR_OBS_NVAR(&attributeName);
			zephir_array_fetch_long(&attributeName, &attribute, 0, PH_NOISY, "phalcon/Mvc/Model.zep", 1281);
			zephir_array_update_zval(&data, &key, &castValue, PH_COPY | PH_SEPARATE);
			if (callSetters) {
				ZEPHIR_INIT_NVAR(&_37$$44);
				zephir_camelize(&_37$$44, &attributeName, NULL );
				ZEPHIR_INIT_NVAR(&setter);
				ZEPHIR_CONCAT_SV(&setter, "set", &_37$$44);
				_38$$44 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
				if (_38$$44) {
					_38$$44 = !(zephir_array_isset_value(&localMethods, &setter));
				}
				if (_38$$44) {

					/* try_start_4: */

						ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &castValue);
						zephir_check_call_status_or_jump(try_end_4);

					try_end_4:

					if (EG(exception)) {
						ZEPHIR_INIT_NVAR(&_39$$45);
						ZVAL_OBJ(&_39$$45, EG(exception));
						Z_ADDREF_P(&_39$$45);
						ZEPHIR_INIT_NVAR(&_40$$45);
						if (zephir_is_instance_of(&_39$$45, SL("TypeError"))) {
							zend_clear_exception();
							ZEPHIR_CPY_WRT(&_40$$45, &_39$$45);
							if (UNEXPECTED(zephir_array_isset_value(&privateProperties, &attributeName))) {
								ZEPHIR_OBS_NVAR(&reflectionProperty);
								zephir_array_fetch(&reflectionProperty, &privateProperties, &attributeName, PH_NOISY, "phalcon/Mvc/Model.zep", 1291);
								ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setvalue", NULL, 0, &instance, &castValue);
								zephir_check_call_status();
							} else {
								zephir_update_property_zval_zval(&instance, &attributeName, &castValue);
							}
						}
					}
					continue;
				}
			}
			if (UNEXPECTED(zephir_array_isset_value(&privateProperties, &attributeName))) {
				ZEPHIR_OBS_NVAR(&reflectionProperty);
				zephir_array_fetch(&reflectionProperty, &privateProperties, &attributeName, PH_NOISY, "phalcon/Mvc/Model.zep", 1302);
				ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setvalue", NULL, 0, &instance, &castValue);
				zephir_check_call_status();
			} else {
				zephir_update_property_zval_zval(&instance, &attributeName, &castValue);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		_42 = 1;
		while (1) {
			if (_42) {
				_42 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_41, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_41)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&key) != IS_STRING) {
					continue;
				}
				_43$$52 = Z_TYPE_P(&value) == IS_NULL;
				if (_43$$52) {
					_43$$52 = zephir_fast_in_array(&key, &notNullAttributes);
				}
				if (_43$$52) {
					continue;
				}
				if (Z_TYPE_P(columnMap) != IS_ARRAY) {
					if (callSetters) {
						ZEPHIR_INIT_NVAR(&_44$$56);
						zephir_camelize(&_44$$56, &key, NULL );
						ZEPHIR_INIT_NVAR(&setter);
						ZEPHIR_CONCAT_SV(&setter, "set", &_44$$56);
						_45$$56 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
						if (_45$$56) {
							_45$$56 = !(zephir_array_isset_value(&localMethods, &setter));
						}
						if (_45$$56) {

							/* try_start_5: */

								ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &value);
								zephir_check_call_status_or_jump(try_end_5);

							try_end_5:

							if (EG(exception)) {
								ZEPHIR_INIT_NVAR(&_46$$57);
								ZVAL_OBJ(&_46$$57, EG(exception));
								Z_ADDREF_P(&_46$$57);
								ZEPHIR_INIT_NVAR(&_47$$57);
								if (zephir_is_instance_of(&_46$$57, SL("TypeError"))) {
									zend_clear_exception();
									ZEPHIR_CPY_WRT(&_47$$57, &_46$$57);
									if (UNEXPECTED(zephir_array_isset_value(&privateProperties, &key))) {
										ZEPHIR_OBS_NVAR(&reflectionProperty);
										zephir_array_fetch(&reflectionProperty, &privateProperties, &key, PH_NOISY, "phalcon/Mvc/Model.zep", 1150);
										ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setvalue", NULL, 0, &instance, &value);
										zephir_check_call_status();
									} else {
										zephir_update_property_zval_zval(&instance, &key, &value);
									}
								}
							}
							continue;
						}
					}
					if (UNEXPECTED(zephir_array_isset_value(&privateProperties, &key))) {
						ZEPHIR_OBS_NVAR(&reflectionProperty);
						zephir_array_fetch(&reflectionProperty, &privateProperties, &key, PH_NOISY, "phalcon/Mvc/Model.zep", 1161);
						ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setvalue", NULL, 0, &instance, &value);
						zephir_check_call_status();
					} else {
						zephir_update_property_zval_zval(&instance, &key, &value);
					}
					continue;
				}
				ZEPHIR_OBS_NVAR(&attribute);
				if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0))) {
					_48$$64 = Z_TYPE_P(columnMap) == IS_ARRAY;
					if (_48$$64) {
						_48$$64 = !(ZEPHIR_IS_EMPTY(columnMap));
					}
					if (_48$$64) {
						if (Z_TYPE_P(&metaData) == IS_NULL) {
							ZEPHIR_CALL_METHOD(&metaData, &instance, "getmodelsmetadata", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&reverseMap, &metaData, "getreversecolumnmap", NULL, 0, &instance);
						zephir_check_call_status();
						ZEPHIR_OBS_NVAR(&attribute);
						if (!(zephir_array_isset_fetch(&attribute, &reverseMap, &key, 0))) {
							ZEPHIR_INIT_NVAR(&_50$$67);
							ZVAL_STRING(&_50$$67, "orm.ignore_unknown_columns");
							ZEPHIR_CALL_CE_STATIC(&_49$$67, phalcon_support_settings_ce, "get", &_15, 0, &_50$$67);
							zephir_check_call_status();
							if (UNEXPECTED(!zephir_is_true(&_49$$67))) {
								ZEPHIR_INIT_NVAR(&_51$$68);
								object_init_ex(&_51$$68, phalcon_mvc_model_exceptions_columnnotinmap_ce);
								ZEPHIR_INIT_NVAR(&_52$$68);
								zephir_get_class(&_52$$68, base, 0);
								ZEPHIR_CALL_METHOD(NULL, &_51$$68, "__construct", &_19, 0, &key, &_52$$68);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_51$$68, "phalcon/Mvc/Model.zep", 1180);
								ZEPHIR_MM_RESTORE();
								return;
							}
							continue;
						}
					} else {
						ZEPHIR_INIT_NVAR(&_54$$69);
						ZVAL_STRING(&_54$$69, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_53$$69, phalcon_support_settings_ce, "get", &_15, 0, &_54$$69);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_53$$69))) {
							ZEPHIR_INIT_NVAR(&_55$$70);
							object_init_ex(&_55$$70, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							ZEPHIR_INIT_NVAR(&_56$$70);
							zephir_get_class(&_56$$70, base, 0);
							ZEPHIR_CALL_METHOD(NULL, &_55$$70, "__construct", &_19, 0, &key, &_56$$70);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_55$$70, "phalcon/Mvc/Model.zep", 1187);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
				}
				if (Z_TYPE_P(&attribute) != IS_ARRAY) {
					if (callSetters) {
						ZEPHIR_INIT_NVAR(&_57$$72);
						zephir_camelize(&_57$$72, &attribute, NULL );
						ZEPHIR_INIT_NVAR(&setter);
						ZEPHIR_CONCAT_SV(&setter, "set", &_57$$72);
						_58$$72 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
						if (_58$$72) {
							_58$$72 = !(zephir_array_isset_value(&localMethods, &setter));
						}
						if (_58$$72) {

							/* try_start_6: */

								ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &value);
								zephir_check_call_status_or_jump(try_end_6);

							try_end_6:

							if (EG(exception)) {
								ZEPHIR_INIT_NVAR(&_59$$73);
								ZVAL_OBJ(&_59$$73, EG(exception));
								Z_ADDREF_P(&_59$$73);
								ZEPHIR_INIT_NVAR(&_60$$73);
								if (zephir_is_instance_of(&_59$$73, SL("TypeError"))) {
									zend_clear_exception();
									ZEPHIR_CPY_WRT(&_60$$73, &_59$$73);
									if (UNEXPECTED(zephir_array_isset_value(&privateProperties, &attribute))) {
										ZEPHIR_OBS_NVAR(&reflectionProperty);
										zephir_array_fetch(&reflectionProperty, &privateProperties, &attribute, PH_NOISY, "phalcon/Mvc/Model.zep", 1202);
										ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setvalue", NULL, 0, &instance, &value);
										zephir_check_call_status();
									} else {
										zephir_update_property_zval_zval(&instance, &attribute, &value);
									}
								}
							}
							continue;
						}
					}
					if (UNEXPECTED(zephir_array_isset_value(&privateProperties, &attribute))) {
						ZEPHIR_OBS_NVAR(&reflectionProperty);
						zephir_array_fetch(&reflectionProperty, &privateProperties, &attribute, PH_NOISY, "phalcon/Mvc/Model.zep", 1213);
						ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setvalue", NULL, 0, &instance, &value);
						zephir_check_call_status();
					} else {
						zephir_update_property_zval_zval(&instance, &attribute, &value);
					}
					continue;
				}
				_61$$52 = !ZEPHIR_IS_STRING(&value, "");
				if (_61$$52) {
					_61$$52 = Z_TYPE_P(&value) != IS_NULL;
				}
				if (_61$$52) {
					zephir_array_fetch_long(&_62$$80, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 1223);
					if (ZEPHIR_IS_LONG(&_62$$80, 0)) { goto zephir_switch_2_clause_0; }
					if (ZEPHIR_IS_LONG(&_62$$80, 21)) { goto zephir_switch_2_clause_1; }
					if (ZEPHIR_IS_LONG(&_62$$80, 22)) { goto zephir_switch_2_clause_2; }
					if (ZEPHIR_IS_LONG(&_62$$80, 26)) { goto zephir_switch_2_clause_3; }
					if (ZEPHIR_IS_LONG(&_62$$80, 3)) { goto zephir_switch_2_clause_4; }
					if (ZEPHIR_IS_LONG(&_62$$80, 9)) { goto zephir_switch_2_clause_5; }
					if (ZEPHIR_IS_LONG(&_62$$80, 7)) { goto zephir_switch_2_clause_6; }
					if (ZEPHIR_IS_LONG(&_62$$80, 8)) { goto zephir_switch_2_clause_7; }
					if (ZEPHIR_IS_LONG(&_62$$80, 40)) { goto zephir_switch_2_clause_8; }
					if (ZEPHIR_IS_LONG(&_62$$80, 41)) { goto zephir_switch_2_clause_9; }
					if (ZEPHIR_IS_LONG(&_62$$80, 42)) { goto zephir_switch_2_clause_10; }
					if (ZEPHIR_IS_LONG(&_62$$80, 43)) { goto zephir_switch_2_clause_11; }
					if (ZEPHIR_IS_LONG(&_62$$80, 44)) { goto zephir_switch_2_clause_12; }
					if (ZEPHIR_IS_LONG(&_62$$80, 45)) { goto zephir_switch_2_clause_13; }
					if (ZEPHIR_IS_LONG(&_62$$80, 46)) { goto zephir_switch_2_clause_14; }
					if (ZEPHIR_IS_LONG(&_62$$80, 47)) { goto zephir_switch_2_clause_15; }
					goto zephir_switch_2_clause_16;
					zephir_switch_2_clause_0: ;
					zephir_switch_2_clause_1: ;
					zephir_switch_2_clause_2: ;
					zephir_switch_2_clause_3: ;
						ZVAL_LONG(&_63$$81, 10);
						ZEPHIR_CALL_FUNCTION(&castValue, "intval", &_31, 96, &value, &_63$$81);
						zephir_check_call_status();
						goto zephir_switch_2_end;
					zephir_switch_2_clause_4: ;
					zephir_switch_2_clause_5: ;
					zephir_switch_2_clause_6: ;
						ZEPHIR_INIT_NVAR(&castValue);
						ZVAL_DOUBLE(&castValue, zephir_get_doubleval(&value));
						goto zephir_switch_2_end;
					zephir_switch_2_clause_7: ;
						ZEPHIR_INIT_NVAR(&castValue);
						ZVAL_BOOL(&castValue, zephir_get_boolval(&value));
						goto zephir_switch_2_end;
					zephir_switch_2_clause_8: ;
					zephir_switch_2_clause_9: ;
					zephir_switch_2_clause_10: ;
					zephir_switch_2_clause_11: ;
					zephir_switch_2_clause_12: ;
					zephir_switch_2_clause_13: ;
					zephir_switch_2_clause_14: ;
					zephir_switch_2_clause_15: ;

						/* try_start_7: */

							ZEPHIR_INIT_NVAR(&_64$$85);
							object_init_ex(&_64$$85, phalcon_db_geometry_wkbparser_ce);
							if (zephir_has_constructor(&_64$$85)) {
								ZEPHIR_CALL_METHOD(NULL, &_64$$85, "__construct", NULL, 0);
								zephir_check_call_status_or_jump(try_end_7);
							}

							ZEPHIR_CALL_METHOD(&castValue, &_64$$85, "parse", &_33, 0, &value);
							zephir_check_call_status_or_jump(try_end_7);

						try_end_7:

						if (EG(exception)) {
							ZEPHIR_INIT_NVAR(&_65$$84);
							ZVAL_OBJ(&_65$$84, EG(exception));
							Z_ADDREF_P(&_65$$84);
							ZEPHIR_INIT_NVAR(&_66$$84);
							if (zephir_instance_of_ev(&_65$$84, phalcon_db_exceptions_invalidwkb_ce)) {
								zend_clear_exception();
								ZEPHIR_CPY_WRT(&_66$$84, &_65$$84);
								ZEPHIR_CPY_WRT(&castValue, &value);
							}
						}
						goto zephir_switch_2_end;
					zephir_switch_2_clause_16: ;
						ZEPHIR_CPY_WRT(&castValue, &value);
						goto zephir_switch_2_end;
					zephir_switch_2_end: ;

				} else {
					zephir_array_fetch_long(&_67$$88, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 1262);
					if (ZEPHIR_IS_LONG(&_67$$88, 14)) { goto zephir_switch_3_clause_0; }
					if (ZEPHIR_IS_LONG(&_67$$88, 8)) { goto zephir_switch_3_clause_1; }
					if (ZEPHIR_IS_LONG(&_67$$88, 3)) { goto zephir_switch_3_clause_2; }
					if (ZEPHIR_IS_LONG(&_67$$88, 9)) { goto zephir_switch_3_clause_3; }
					if (ZEPHIR_IS_LONG(&_67$$88, 7)) { goto zephir_switch_3_clause_4; }
					if (ZEPHIR_IS_LONG(&_67$$88, 0)) { goto zephir_switch_3_clause_5; }
					if (ZEPHIR_IS_LONG(&_67$$88, 21)) { goto zephir_switch_3_clause_6; }
					if (ZEPHIR_IS_LONG(&_67$$88, 22)) { goto zephir_switch_3_clause_7; }
					if (ZEPHIR_IS_LONG(&_67$$88, 26)) { goto zephir_switch_3_clause_8; }
					goto zephir_switch_3_clause_9;
					zephir_switch_3_clause_0: ;
					zephir_switch_3_clause_1: ;
					zephir_switch_3_clause_2: ;
					zephir_switch_3_clause_3: ;
					zephir_switch_3_clause_4: ;
					zephir_switch_3_clause_5: ;
					zephir_switch_3_clause_6: ;
					zephir_switch_3_clause_7: ;
					zephir_switch_3_clause_8: ;
						ZEPHIR_INIT_NVAR(&castValue);
						ZVAL_NULL(&castValue);
						goto zephir_switch_3_end;
					zephir_switch_3_clause_9: ;
						ZEPHIR_CPY_WRT(&castValue, &value);
						goto zephir_switch_3_end;
					zephir_switch_3_end: ;

				}
				ZEPHIR_OBS_NVAR(&attributeName);
				zephir_array_fetch_long(&attributeName, &attribute, 0, PH_NOISY, "phalcon/Mvc/Model.zep", 1281);
				zephir_array_update_zval(&data, &key, &castValue, PH_COPY | PH_SEPARATE);
				if (callSetters) {
					ZEPHIR_INIT_NVAR(&_68$$91);
					zephir_camelize(&_68$$91, &attributeName, NULL );
					ZEPHIR_INIT_NVAR(&setter);
					ZEPHIR_CONCAT_SV(&setter, "set", &_68$$91);
					_69$$91 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
					if (_69$$91) {
						_69$$91 = !(zephir_array_isset_value(&localMethods, &setter));
					}
					if (_69$$91) {

						/* try_start_8: */

							ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &castValue);
							zephir_check_call_status_or_jump(try_end_8);

						try_end_8:

						if (EG(exception)) {
							ZEPHIR_INIT_NVAR(&_70$$92);
							ZVAL_OBJ(&_70$$92, EG(exception));
							Z_ADDREF_P(&_70$$92);
							ZEPHIR_INIT_NVAR(&_71$$92);
							if (zephir_is_instance_of(&_70$$92, SL("TypeError"))) {
								zend_clear_exception();
								ZEPHIR_CPY_WRT(&_71$$92, &_70$$92);
								if (UNEXPECTED(zephir_array_isset_value(&privateProperties, &attributeName))) {
									ZEPHIR_OBS_NVAR(&reflectionProperty);
									zephir_array_fetch(&reflectionProperty, &privateProperties, &attributeName, PH_NOISY, "phalcon/Mvc/Model.zep", 1291);
									ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setvalue", NULL, 0, &instance, &castValue);
									zephir_check_call_status();
								} else {
									zephir_update_property_zval_zval(&instance, &attributeName, &castValue);
								}
							}
						}
						continue;
					}
				}
				if (UNEXPECTED(zephir_array_isset_value(&privateProperties, &attributeName))) {
					ZEPHIR_OBS_NVAR(&reflectionProperty);
					zephir_array_fetch(&reflectionProperty, &privateProperties, &attributeName, PH_NOISY, "phalcon/Mvc/Model.zep", 1302);
					ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setvalue", NULL, 0, &instance, &castValue);
					zephir_check_call_status();
				} else {
					zephir_update_property_zval_zval(&instance, &attributeName, &castValue);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	if (keepSnapshots) {
		ZEPHIR_CALL_METHOD(NULL, &instance, "setsnapshotdata", NULL, 0, &data, columnMap);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_72$$99, &instance, "getsnapshotdata", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &instance, "setoldsnapshotdata", NULL, 0, &_72$$99);
		zephir_check_call_status();
	}
	if ((zephir_method_exists_ex(&instance, ZEND_STRL("fireevent")) == SUCCESS)) {
		ZEPHIR_INIT_VAR(&_73$$100);
		ZVAL_STRING(&_73$$100, "afterFetch");
		ZEPHIR_CALL_METHOD(NULL, &instance, "fireevent", NULL, 0, &_73$$100);
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long hydrationMode, ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *columnMap, columnMap_sub, *hydrationMode_param = NULL, _0, _1;
	zval data;

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
		Z_PARAM_ZVAL(columnMap)
		Z_PARAM_LONG(hydrationMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &data_param, &columnMap, &hydrationMode_param);
	zephir_get_arrval(&data, data_param);
	ZEPHIR_INIT_VAR(&_0);
	zephir_get_called_class(&_0);
	ZVAL_LONG(&_1, hydrationMode);
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_mvc_model_hydration_cloneresultmaphydrate_ce, "cloneresultmaphydrate", NULL, 0, &data, columnMap, &_1, &_0);
	zephir_check_call_status();
	RETURN_MM();
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("related", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("dirtyRelated", 12, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 998, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&related, &_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 997, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dirtyRelated, &_1);
	zephir_is_iterable(&related, 0, "phalcon/Mvc/Model.zep", 1385);
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
 * // How many invoices are there?
 * $number = Invoices::count();
 *
 * echo "There are ", $number, "\n";
 *
 * // How many paid invoices are there?
 * $number = Invoices::count("inv_status_flag = 1");
 *
 * echo "There are ", $number, " paid invoices\n";
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
 * // Creating a new invoice
 * $invoice = new Invoices();
 *
 * $invoice->inv_status_flag = "mechanical";
 * $invoice->inv_title = "Test Invoice";
 * $invoice->inv_total = 1952;
 *
 * $invoice->create();
 *
 * // Passing an array to create
 * $invoice = new Invoices();
 *
 * $invoice->assign(
 *     [
 *         "type" => "mechanical",
 *         "name" => "Test Invoice",
 *         "year" => 1952,
 *     ]
 * );
 *
 * $invoice->create();
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("errorMessages", 13, 1);
	}
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
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "");
		ZEPHIR_INIT_VAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "InvalidCreateAttempt");
		ZVAL_LONG(&_8$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 5, &_5$$3, &_6$$3, &_7$$3, &_8$$3, &_4$$3);
		zephir_check_call_status();
		zephir_array_fast_append(&_2$$3, &_3$$3);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1002, &_2$$3);
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
 * $invoice = Invoices::findFirst("id=100");
 *
 * $invoice->delete();
 *
 * $invoices = Invoices::find("inv_status_flag = 1");
 *
 * foreach ($invoices as $invoice) {
 *     $invoice->delete();
 * }
 * ```
 */
PHP_METHOD(Phalcon_Mvc_Model, delete)
{
	zend_bool _23;
	zval values, bindTypes, conditions;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, metaData, writeConnection, primaryKeys, bindDataTypes, columnMap, attributeField, primaryKey, bindType, value, schema, source, table, success, _0, _1, _2, _3, _5, *_8, *_9, _22, _33, _34, _38, _39, _41, _4$$3, _6$$7, _7$$7, _10$$9, _11$$9, _13$$11, _14$$11, _16$$13, _17$$13, _19$$8, _21$$8, _24$$15, _25$$15, _26$$17, _27$$17, _28$$19, _29$$19, _30$$14, _32$$14, _35$$20, _36$$20, _37$$20, _40$$25, _42$$28, _43$$29, _44$$29, _45$$29, _46$$29;
	zephir_fcall_cache_entry *_12 = NULL, *_15 = NULL, *_18 = NULL, *_20 = NULL, *_31 = NULL;
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
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_25$$15);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_28$$19);
	ZVAL_UNDEF(&_29$$19);
	ZVAL_UNDEF(&_30$$14);
	ZVAL_UNDEF(&_32$$14);
	ZVAL_UNDEF(&_35$$20);
	ZVAL_UNDEF(&_36$$20);
	ZVAL_UNDEF(&_37$$20);
	ZVAL_UNDEF(&_40$$25);
	ZVAL_UNDEF(&_42$$28);
	ZVAL_UNDEF(&_43$$29);
	ZVAL_UNDEF(&_44$$29);
	ZVAL_UNDEF(&_45$$29);
	ZVAL_UNDEF(&_46$$29);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&conditions);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("operationMade", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("errorMessages", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("skipped", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("modelsManager", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("related", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("dirtyRelated", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("dirtyState", 10, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&writeConnection, this_ptr, "getwriteconnection", NULL, 0);
	zephir_check_call_status();
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, 3);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1003, &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1002, &_1);
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
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&primaryKeys))) {
		ZEPHIR_INIT_VAR(&_6$$7);
		object_init_ex(&_6$$7, phalcon_mvc_model_exceptions_primarykeyrequired_ce);
		ZEPHIR_INIT_VAR(&_7$$7);
		zephir_get_class(&_7$$7, this_ptr, 0);
		ZEPHIR_CALL_METHOD(NULL, &_6$$7, "__construct", NULL, 0, &_7$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$7, "phalcon/Mvc/Model.zep", 1547);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&primaryKeys) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_3);
		zephir_string_to_char_array(&_3, &primaryKeys);
		_8 = &_3;
	} else {
		_8 = &primaryKeys;
	}
	zephir_is_iterable(_8, 0, "phalcon/Mvc/Model.zep", 1589);
	if (Z_TYPE_P(_8) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_8), _9)
		{
			ZEPHIR_INIT_NVAR(&primaryKey);
			ZVAL_COPY(&primaryKey, _9);
			ZEPHIR_OBS_NVAR(&bindType);
			if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &primaryKey, 0)))) {
				ZEPHIR_INIT_NVAR(&_10$$9);
				object_init_ex(&_10$$9, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
				ZEPHIR_INIT_NVAR(&_11$$9);
				zephir_get_class(&_11$$9, this_ptr, 0);
				ZEPHIR_CALL_METHOD(NULL, &_10$$9, "__construct", &_12, 0, &primaryKey, &_11$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_10$$9, "phalcon/Mvc/Model.zep", 1559);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &primaryKey, 0)))) {
					ZEPHIR_INIT_NVAR(&_13$$11);
					object_init_ex(&_13$$11, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
					ZEPHIR_INIT_NVAR(&_14$$11);
					zephir_get_class(&_14$$11, this_ptr, 0);
					ZEPHIR_CALL_METHOD(NULL, &_13$$11, "__construct", &_15, 0, &primaryKey, &_14$$11);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_13$$11, "phalcon/Mvc/Model.zep", 1567);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &primaryKey);
			}
			ZEPHIR_OBS_NVAR(&value);
			if (UNEXPECTED(!(zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)))) {
				ZEPHIR_INIT_NVAR(&_16$$13);
				object_init_ex(&_16$$13, phalcon_mvc_model_exceptions_primarykeyattributenotset_ce);
				ZEPHIR_INIT_NVAR(&_17$$13);
				zephir_get_class(&_17$$13, this_ptr, 0);
				ZEPHIR_CALL_METHOD(NULL, &_16$$13, "__construct", &_18, 0, &attributeField, &_17$$13);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_16$$13, "phalcon/Mvc/Model.zep", 1578);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1584);
			ZEPHIR_CALL_METHOD(&_19$$8, &writeConnection, "escapeidentifier", &_20, 0, &primaryKey);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_21$$8);
			ZEPHIR_CONCAT_VS(&_21$$8, &_19$$8, " = ?");
			zephir_array_append(&conditions, &_21$$8, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1585);
			zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1586);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _8, "rewind", NULL, 0);
		zephir_check_call_status();
		_23 = 1;
		while (1) {
			if (_23) {
				_23 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _8, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_22, _8, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_22)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&primaryKey, _8, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&bindType);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &primaryKey, 0)))) {
					ZEPHIR_INIT_NVAR(&_24$$15);
					object_init_ex(&_24$$15, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
					ZEPHIR_INIT_NVAR(&_25$$15);
					zephir_get_class(&_25$$15, this_ptr, 0);
					ZEPHIR_CALL_METHOD(NULL, &_24$$15, "__construct", &_12, 0, &primaryKey, &_25$$15);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_24$$15, "phalcon/Mvc/Model.zep", 1559);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &primaryKey, 0)))) {
						ZEPHIR_INIT_NVAR(&_26$$17);
						object_init_ex(&_26$$17, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
						ZEPHIR_INIT_NVAR(&_27$$17);
						zephir_get_class(&_27$$17, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_26$$17, "__construct", &_15, 0, &primaryKey, &_27$$17);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_26$$17, "phalcon/Mvc/Model.zep", 1567);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &primaryKey);
				}
				ZEPHIR_OBS_NVAR(&value);
				if (UNEXPECTED(!(zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)))) {
					ZEPHIR_INIT_NVAR(&_28$$19);
					object_init_ex(&_28$$19, phalcon_mvc_model_exceptions_primarykeyattributenotset_ce);
					ZEPHIR_INIT_NVAR(&_29$$19);
					zephir_get_class(&_29$$19, this_ptr, 0);
					ZEPHIR_CALL_METHOD(NULL, &_28$$19, "__construct", &_18, 0, &attributeField, &_29$$19);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_28$$19, "phalcon/Mvc/Model.zep", 1578);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1584);
				ZEPHIR_CALL_METHOD(&_30$$14, &writeConnection, "escapeidentifier", &_31, 0, &primaryKey);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_32$$14);
				ZEPHIR_CONCAT_VS(&_32$$14, &_30$$14, " = ?");
				zephir_array_append(&conditions, &_32$$14, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1585);
				zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1586);
		}
	}
	ZEPHIR_INIT_NVAR(&primaryKey);
	ZEPHIR_INIT_VAR(&_34);
	ZVAL_STRING(&_34, "orm.events");
	ZEPHIR_CALL_CE_STATIC(&_33, phalcon_support_settings_ce, "get", NULL, 0, &_34);
	zephir_check_call_status();
	if (zephir_is_true(&_33)) {
		if (0) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1004, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1004, &__$false);
		}
		ZEPHIR_INIT_VAR(&_36$$20);
		ZVAL_STRING(&_36$$20, "beforeDelete");
		ZEPHIR_CALL_METHOD(&_35$$20, this_ptr, "fireeventcancel", NULL, 0, &_36$$20);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_35$$20)) {
			RETURN_MM_BOOL(0);
		}
		zephir_read_property_cached(&_37$$20, this_ptr, _zephir_prop_2, 1004, PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_37$$20)) {
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
	ZEPHIR_INIT_NVAR(&_34);
	zephir_fast_join_str(&_34, SL(" AND "), &conditions);
	ZEPHIR_CALL_METHOD(&success, &writeConnection, "delete", NULL, 0, &table, &_34, &values, &bindTypes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_39);
	ZVAL_STRING(&_39, "orm.virtual_foreign_keys");
	ZEPHIR_CALL_CE_STATIC(&_38, phalcon_support_settings_ce, "get", NULL, 0, &_39);
	zephir_check_call_status();
	if (zephir_is_true(&_38)) {
		ZEPHIR_CALL_METHOD(&_40$$25, this_ptr, "checkforeignkeysreversecascade", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_40$$25)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(&_39);
	ZVAL_STRING(&_39, "orm.events");
	ZEPHIR_CALL_CE_STATIC(&_41, phalcon_support_settings_ce, "get", NULL, 0, &_39);
	zephir_check_call_status();
	if (zephir_is_true(&_41)) {
		if (zephir_is_true(&success)) {
			ZEPHIR_INIT_VAR(&_42$$28);
			ZVAL_STRING(&_42$$28, "afterDelete");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_42$$28);
			zephir_check_call_status();
		}
	}
	if (zephir_is_true(&success)) {
		zephir_read_property_cached(&_43$$29, this_ptr, _zephir_prop_3, 996, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_43$$29, "registerwrite", NULL, 0, this_ptr);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_44$$29);
		array_init(&_44$$29);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 998, &_44$$29);
		ZEPHIR_INIT_VAR(&_45$$29);
		array_init(&_45$$29);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 997, &_45$$29);
		zephir_read_property_cached(&_46$$29, this_ptr, _zephir_prop_3, 996, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_46$$29, "clearreusableobjects", NULL, 0);
		zephir_check_call_status();
	}
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, 2);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 999, &_0);
	RETURN_CCTOR(&success);
}

/**
 * Returns a simple representation of the object that can be used with
 * `var_dump()`
 *
 *```php
 * var_dump(
 *     $invoice->dump()
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

	ZEPHIR_RETURN_CALL_FUNCTION("get_object_vars", NULL, 359, this_ptr);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Query for a set of records that match the specified conditions
 *
 * ```php
 * // How many invoices are there?
 * $invoices = Invoices::find();
 *
 * echo "There are ", count($invoices), "\n";
 *
 * // How many paid invoices are there?
 * $invoices = Invoices::find(
 *     "inv_status_flag = 1"
 * );
 *
 * echo "There are ", count($invoices), "\n";
 *
 * // Get and print virtual invoices ordered by name
 * $invoices = Invoices::find(
 *     [
 *         "type = 'virtual'",
 *         "order" => "name",
 *     ]
 * );
 *
 * foreach ($invoices as $invoice) {
 *     echo $invoice->inv_title, "\n";
 * }
 *
 * // Get first 100 virtual invoices ordered by name
 * $invoices = Invoices::find(
 *     [
 *         "type = 'virtual'",
 *         "order" => "name",
 *         "limit" => 100,
 *     ]
 * );
 *
 * foreach ($invoices as $invoice) {
 *     echo $invoice->inv_title, "\n";
 * }
 *
 * // encapsulate find it into an running transaction esp. useful for application unit-tests
 * // or complex business logic where we wanna control which transactions are used.
 *
 * $myTransaction = new Transaction(\Phalcon\Di\Di::getDefault());
 * $myTransaction->begin();
 *
 * $newInvoices = new Invoices();
 * $newInvoices->setTransaction($myTransaction);
 *
 * $newInvoices->assign(
 *     [
 *         'name' => 'test',
 *         'type' => 'mechanical',
 *         'year' => 1944,
 *     ]
 * );
 *
 * $newInvoices->save();
 *
 * $resultInsideTransaction = Invoices::find(
 *     [
 *         'name' => 'test',
 *         Model::TRANSACTION_INDEX => $myTransaction,
 *     ]
 * );
 *
 * $resultOutsideTransaction = Invoices::find(['name' => 'test']);
 *
 * foreach ($setInsideTransaction as $invoice) {
 *     echo $invoice->inv_title, "\n";
 * }
 *
 * foreach ($setOutsideTransaction as $invoice) {
 *     echo $invoice->inv_title, "\n";
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
 *  // add a new invoices
 * $firstNewInvoices = new Invoices();
 * $firstNewInvoices->setTransaction($myTransaction1);
 * $firstNewInvoices->assign(
 *     [
 *         'name' => 'first-transaction-invoice',
 *         'type' => 'mechanical',
 *         'year' => 1944,
 *     ]
 * );
 * $firstNewInvoices->save();
 *
 * $secondNewInvoices = new Invoices();
 * $secondNewInvoices->setTransaction($myTransaction2);
 * $secondNewInvoices->assign(
 *     [
 *         'name' => 'second-transaction-invoice',
 *         'type' => 'fictional',
 *         'year' => 1984,
 *     ]
 * );
 * $secondNewInvoices->save();
 *
 * // this transaction will find the invoice.
 * $resultInFirstTransaction = Invoices::find(
 *     [
 *         'name'                   => 'first-transaction-invoice',
 *         Model::TRANSACTION_INDEX => $myTransaction1,
 *     ]
 * );
 *
 * // this transaction won't find the invoice.
 * $resultInSecondTransaction = Invoices::find(
 *     [
 *         'name'                   => 'first-transaction-invoice',
 *         Model::TRANSACTION_INDEX => $myTransaction2,
 *     ]
 * );
 *
 * // this transaction won't find the invoice.
 * $resultOutsideAnyExplicitTransaction = Invoices::find(
 *     [
 *         'name' => 'first-transaction-invoice',
 *     ]
 * );
 *
 * // this transaction won't find the invoice.
 * $resultInFirstTransaction = Invoices::find(
 *     [
 *         'name'                   => 'second-transaction-invoice',
 *         Model::TRANSACTION_INDEX => $myTransaction2,
 *     ]
 * );
 *
 * // this transaction will find the invoice.
 * $resultInSecondTransaction = Invoices::find(
 *     [
 *         'name'                   => 'second-transaction-invoice',
 *         Model::TRANSACTION_INDEX => $myTransaction1,
 *     ]
 * );
 *
 * // this transaction won't find the invoice.
 * $resultOutsideAnyExplicitTransaction = Invoices::find(
 *     [
 *         'name' => 'second-transaction-invoice',
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
	zephir_fcall_cache_entry *_0 = NULL, *_1 = NULL;
	zval *parameters = NULL, parameters_sub, __$null, eager, params, query, resultset, hydration;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&eager);
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
			zephir_array_append(&params, parameters, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1867);
		}
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	ZEPHIR_CALL_SELF(&query, "getpreparedquery", &_0, 0, &params);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&resultset, &query, "execute", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&resultset) == IS_OBJECT) {
		zephir_memory_observe(&hydration);
		if (zephir_array_isset_string_fetch(&hydration, &params, SL("hydration"), 0)) {
			ZEPHIR_CALL_METHOD(NULL, &resultset, "sethydratemode", NULL, 0, &hydration);
			zephir_check_call_status();
		}
		zephir_memory_observe(&eager);
		if (zephir_array_isset_string_fetch(&eager, &params, SL("eager"), 0)) {
			ZEPHIR_CALL_SELF(NULL, "loadeager", &_1, 0, &resultset, &eager, &params);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(&resultset);
}

/**
 * Query the first record that matches the specified conditions
 *
 * ```php
 * // What's the first invoice in invoices table?
 * $invoice = Invoices::findFirst();
 *
 * echo "The invoice name is ", $invoice->inv_title;
 *
 * // What's the first paid invoice in invoices table?
 * $invoice = Invoices::findFirst(
 *     "inv_status_flag = 1"
 * );
 *
 * echo "The first paid invoice name is ", $invoice->inv_title;
 *
 * // Get first virtual invoice ordered by name
 * $invoice = Invoices::findFirst(
 *     [
 *         "type = 'virtual'",
 *         "order" => "name",
 *     ]
 * );
 *
 * echo "The first virtual invoice name is ", $invoice->inv_title;
 *
 * // behavior with transaction
 * $myTransaction = new Transaction(\Phalcon\Di\Di::getDefault());
 * $myTransaction->begin();
 *
 * $newInvoices = new Invoices();
 * $newInvoices->setTransaction($myTransaction);
 * $newInvoices->assign(
 *     [
 *         'name' => 'test',
 *         'type' => 'mechanical',
 *         'year' => 1944,
 *     ]
 * );
 * $newInvoices->save();
 *
 * $findsAInvoices = Invoices::findFirst(
 *     [
 *         'name'                   => 'test',
 *         Model::TRANSACTION_INDEX => $myTransaction,
 *     ]
 * );
 *
 * $doesNotFindAInvoices = Invoices::findFirst(
 *     [
 *         'name' => 'test',
 *     ]
 * );
 *
 * var_dump($findAInvoices);
 * var_dump($doesNotFindAInvoices);
 *
 * $transaction->commit();
 *
 * $doesFindTheInvoicesNow = Invoices::findFirst(
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
	zval params;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, parameters_sub, __$null, eager, query, resultset, _5, _1$$5, _2$$6, _3$$6;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&eager);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&resultset);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&params);
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
	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	if (Z_TYPE_P(parameters) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&params);
		array_init(&params);
	} else if (Z_TYPE_P(parameters) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&params, parameters);
	} else {
		_0 = Z_TYPE_P(parameters) == IS_STRING;
		if (!(_0)) {
			_0 = zephir_is_numeric(parameters);
		}
		if (_0) {
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
			zephir_throw_exception_debug(&_2$$6, "phalcon/Mvc/Model.zep", 1999);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZVAL_LONG(&_5, 1);
	ZEPHIR_CALL_SELF(&query, "getpreparedquery", &_4, 0, &params, &_5);
	zephir_check_call_status();
	zephir_memory_observe(&eager);
	if (zephir_array_isset_string_fetch(&eager, &params, SL("eager"), 0)) {
		ZEPHIR_CALL_METHOD(&resultset, &query, "execute", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&resultset) == IS_OBJECT) {
			ZEPHIR_CALL_SELF(NULL, "loadeager", &_6, 0, &resultset, &eager, &params);
			zephir_check_call_status();
			ZEPHIR_RETURN_CALL_METHOD(&resultset, "getfirst", NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETURN_CCTOR(&resultset);
	}
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}

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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}

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
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_1, "notifyevent", NULL, 0, &eventName_zv, this_ptr);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns a list of changed values.
 *
 * ```php
 * $invoices = Invoices::findFirst();
 * print_r($invoices->getChangedFields()); // []
 *
 * $invoices->deleted = 'Y';
 *
 * $invoices->getChangedFields();
 * print_r($invoices->getChangedFields()); // ["deleted"]
 * ```
 */
PHP_METHOD(Phalcon_Mvc_Model, getChangedFields)
{
	zend_bool _11;
	zend_string *_8;
	zend_ulong _7;
	zval changed;
	zval metaData, name, snapshot, columnMap, allAttributes, value, _0, *_3, _4, _5, *_6, _10, _1$$3, _2$$3, _9$$6, _12$$10;
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
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&changed);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("snapshot", 8, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1000, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&snapshot, &_0);
	if (UNEXPECTED(Z_TYPE_P(&snapshot) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_exceptions_snapshotsdisabled_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_get_class(&_2$$3, this_ptr, 0);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model.zep", 2100);
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
	if (Z_TYPE_P(&allAttributes) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_4);
		zephir_string_to_char_array(&_4, &allAttributes);
		_3 = &_4;
	} else {
		_3 = &allAttributes;
	}
	ZEPHIR_INIT_VAR(&_5);
	zephir_is_iterable(_3, 0, "phalcon/Mvc/Model.zep", 2161);
	if (Z_TYPE_P(_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_3), _7, _8, _6)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&name, _8);
			} else {
				ZVAL_LONG(&name, _7);
			}
			ZEPHIR_INIT_NVAR(&_5);
			ZVAL_COPY(&_5, _6);
			if (!(zephir_array_key_exists(&snapshot, &name))) {
				zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2136);
				continue;
			}
			ZEPHIR_OBS_NVAR(&value);
			if (!(zephir_fetch_property_zval(&value, this_ptr, &name, PH_SILENT_CC))) {
				zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2146);
				continue;
			}
			zephir_array_fetch(&_9$$6, &snapshot, &name, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 2154);
			if (!ZEPHIR_IS_IDENTICAL(&value, &_9$$6)) {
				zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2155);
				continue;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _3, "rewind", NULL, 0);
		zephir_check_call_status();
		_11 = 1;
		while (1) {
			if (_11) {
				_11 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _3, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_10, _3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_10)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, _3, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_5, _3, "current", NULL, 0);
			zephir_check_call_status();
				if (!(zephir_array_key_exists(&snapshot, &name))) {
					zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2136);
					continue;
				}
				ZEPHIR_OBS_NVAR(&value);
				if (!(zephir_fetch_property_zval(&value, this_ptr, &name, PH_SILENT_CC))) {
					zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2146);
					continue;
				}
				zephir_array_fetch(&_12$$10, &snapshot, &name, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 2154);
				if (!ZEPHIR_IS_IDENTICAL(&value, &_12$$10)) {
					zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2155);
					continue;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&_5);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getcustomeventsmanager", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns array of validation messages
 *
 *```php
 * $invoice = new Invoices();
 *
 * $invoice->inv_status_flag = "mechanical";
 * $invoice->inv_title = "Test Invoice";
 * $invoice->inv_total = 1952;
 *
 * if ($invoice->save() === false) {
 *     echo "Umh, We can't store invoices right now ";
 *
 *     $messages = $invoice->getMessages();
 *
 *     foreach ($messages as $message) {
 *         echo $message;
 *     }
 * } else {
 *     echo "Great, a new invoice was saved successfully!";
 * }
 * ```
 */
PHP_METHOD(Phalcon_Mvc_Model, getMessages)
{
	zend_bool _0, _1, _9$$3;
	zval filtered;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filter = NULL, filter_sub, __$null, message, _2$$4, _3$$3, *_4$$3, _5$$3, *_6$$3, _8$$3, _7$$5, _10$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&filtered);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("errorMessages", 13, 1);
	}

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
		zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_0, 1002, PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_3$$3) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_5$$3);
			zephir_string_to_char_array(&_5$$3, &_3$$3);
			_4$$3 = &_5$$3;
		} else {
			_4$$3 = &_3$$3;
		}
		zephir_is_iterable(_4$$3, 0, "phalcon/Mvc/Model.zep", 2225);
		if (Z_TYPE_P(_4$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_4$$3), _6$$3)
			{
				ZEPHIR_INIT_NVAR(&message);
				ZVAL_COPY(&message, _6$$3);
				ZEPHIR_CALL_METHOD(&_7$$5, &message, "getfield", NULL, 0);
				zephir_check_call_status();
				if (zephir_fast_in_array(&_7$$5, filter)) {
					zephir_array_append(&filtered, &message, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2221);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _4$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			_9$$3 = 1;
			while (1) {
				if (_9$$3) {
					_9$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _4$$3, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_8$$3, _4$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_8$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&message, _4$$3, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_10$$7, &message, "getfield", NULL, 0);
					zephir_check_call_status();
					if (zephir_fast_in_array(&_10$$7, filter)) {
						zephir_array_append(&filtered, &message, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2221);
					}
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsMetaData", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("container", 9, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&metaData);
	zephir_read_property_cached(&metaData, this_ptr, _zephir_prop_0, 1005, PH_NOISY_CC);
	if (Z_TYPE_P(&metaData) == IS_NULL) {
		zephir_read_property_cached(&_0$$3, this_ptr, _zephir_prop_1, 995, PH_NOISY_CC | PH_READONLY);
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
			zephir_throw_exception_debug(&_3$$4, "phalcon/Mvc/Model.zep", 2257);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1005, &metaData);
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("transaction", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("modelsManager", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1006, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 1006, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_1$$3, "getconnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 996, PH_NOISY_CC | PH_READONLY);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("dirtyRelated", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("related", 7, 1);
	}

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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
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
		zephir_throw_exception_debug(&_2$$3, "phalcon/Mvc/Model.zep", 2330);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(arguments) == IS_NULL) {
		zephir_read_property_cached(&_3$$4, this_ptr, _zephir_prop_1, 997, PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_value(&_3$$4, &lowerAlias)) {
			zephir_read_property_cached(&_4$$5, this_ptr, _zephir_prop_1, 997, PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_5$$5, &_4$$5, &lowerAlias, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 2355);
			RETURN_CTOR(&_5$$5);
		}
		zephir_read_property_cached(&_6$$4, this_ptr, _zephir_prop_2, 998, PH_NOISY_CC | PH_READONLY);
		if (zephir_array_key_exists(&_6$$4, &lowerAlias)) {
			zephir_read_property_cached(&_7$$6, this_ptr, _zephir_prop_2, 998, PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_8$$6, &_7$$6, &lowerAlias, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 2366);
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
 * $invoice = Invoices::findFirst();
 * var_dump($invoice->isRelationshipLoaded('ordersProducts')); // false
 *
 * $invoicesParts = $invoice->getOrdersProducts(['id > 0']);
 * var_dump($invoice->isRelationshipLoaded('ordersProducts')); // false
 *
 * $invoicesParts = $invoice->getOrdersProducts(); // or $invoice->ordersProducts
 * var_dump($invoice->isRelationshipLoaded('ordersProducts')); // true
 *
 * $invoice->ordersProducts = [new OrdersProducts()];
 * var_dump($invoice->isRelationshipLoaded('ordersProducts')); // false
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("related", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(relationshipAlias)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&relationshipAlias_zv);
	ZVAL_STR_COPY(&relationshipAlias_zv, relationshipAlias);
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, &relationshipAlias_zv);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 998, PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_key_exists(&_1, &_0));
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getmodelsource", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns a list of updated values.
 *
 * ```php
 * $invoices = Invoices::findFirst();
 * print_r($invoices->getChangedFields()); // []
 *
 * $invoices->deleted = 'Y';
 *
 * $invoices->getChangedFields();
 * print_r($invoices->getChangedFields()); // ["deleted"]
 * $invoices->save();
 * print_r($invoices->getChangedFields()); // []
 * print_r($invoices->getUpdatedFields()); // ["deleted"]
 * ```
 */
PHP_METHOD(Phalcon_Mvc_Model, getUpdatedFields)
{
	zend_bool _16, _13$$6, _17$$8;
	zend_string *_12;
	zend_ulong _11;
	zval updated;
	zval name, snapshot, oldSnapshot, value, _0, _1, _2, *_9, *_10, _15, _3$$3, _4$$3, _5$$4, _6$$4, _7$$5, _8$$5, _14$$6, _18$$8;
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
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&updated);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("snapshot", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("oldSnapshot", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("dirtyState", 10, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1000, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&snapshot, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1007, PH_NOISY_CC | PH_READONLY);
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
		zephir_throw_exception_debug(&_3$$3, "phalcon/Mvc/Model.zep", 2467);
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
		zephir_throw_exception_debug(&_5$$4, "phalcon/Mvc/Model.zep", 2471);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 999, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!ZEPHIR_IS_LONG(&_0, 0))) {
		ZEPHIR_INIT_VAR(&_7$$5);
		object_init_ex(&_7$$5, phalcon_mvc_model_exceptions_recordnotpersisted_ce);
		ZEPHIR_INIT_VAR(&_8$$5);
		zephir_get_class(&_8$$5, this_ptr, 0);
		ZEPHIR_CALL_METHOD(NULL, &_7$$5, "__construct", NULL, 0, &_8$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$5, "phalcon/Mvc/Model.zep", 2478);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&updated);
	array_init(&updated);
	if (Z_TYPE_P(&snapshot) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_2);
		zephir_string_to_char_array(&_2, &snapshot);
		_9 = &_2;
	} else {
		_9 = &snapshot;
	}
	zephir_is_iterable(_9, 0, "phalcon/Mvc/Model.zep", 2496);
	if (Z_TYPE_P(_9) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_9), _11, _12, _10)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_12 != NULL) { 
				ZVAL_STR_COPY(&name, _12);
			} else {
				ZVAL_LONG(&name, _11);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _10);
			_13$$6 = !(zephir_array_key_exists(&oldSnapshot, &name));
			if (!(_13$$6)) {
				zephir_array_fetch(&_14$$6, &oldSnapshot, &name, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 2491);
				_13$$6 = !ZEPHIR_IS_IDENTICAL(&value, &_14$$6);
			}
			if (_13$$6) {
				zephir_array_append(&updated, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2492);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _9, "rewind", NULL, 0);
		zephir_check_call_status();
		_16 = 1;
		while (1) {
			if (_16) {
				_16 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _9, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_15, _9, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, _9, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, _9, "current", NULL, 0);
			zephir_check_call_status();
				_17$$8 = !(zephir_array_key_exists(&oldSnapshot, &name));
				if (!(_17$$8)) {
					zephir_array_fetch(&_18$$8, &oldSnapshot, &name, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 2491);
					_17$$8 = !ZEPHIR_IS_IDENTICAL(&value, &_18$$8);
				}
				if (_17$$8) {
					zephir_array_append(&updated, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2492);
				}
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("transaction", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("modelsManager", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1006, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 1006, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_1$$3, "getconnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 996, PH_NOISY_CC | PH_READONLY);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getwriteconnectionservice", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Check if a specific attribute has changed
 * This only works if the model is keeping data snapshots
 *
 *```php
 * $invoice = new Invoices();
 *
 * $invoice->inv_status_flag = "mechanical";
 * $invoice->inv_title = "Test Invoice";
 * $invoice->inv_total = 1952;
 *
 * $invoice->create();
 *
 * $invoice->inv_status_flag = "hydraulic";
 *
 * $hasChanged = $invoice->hasChanged("type"); // returns true
 * $hasChanged = $invoice->hasChanged(["type", "name"]); // returns true
 * $hasChanged = $invoice->hasChanged(["type", "name"], true); // returns false
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
		RETURN_MM_BOOL(!(ZEPHIR_IS_EMPTY(&intersect)));
	}
	RETURN_MM_BOOL(!(ZEPHIR_IS_EMPTY(&changedFields)));
}

/**
 * Checks if the object has internal snapshot data
 */
PHP_METHOD(Phalcon_Mvc_Model, hasSnapshotData)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("snapshot", 8, 1);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1000, PH_NOISY_CC | PH_READONLY);
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
		RETURN_MM_BOOL(!(ZEPHIR_IS_EMPTY(&intersect)));
	}
	RETURN_MM_BOOL(!(ZEPHIR_IS_EMPTY(&updatedFields)));
}

/**
 * Serializes the object for json_encode
 *
 *```php
 * echo json_encode($invoice);
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
 * // What is the maximum invoice id?
 * $id = Invoices::maximum(
 *     [
 *         "column" => "id",
 *     ]
 * );
 *
 * echo "The maximum invoice id is: ", $id, "\n";
 *
 * // What is the maximum id of paid invoices?
 * $sum = Invoices::maximum(
 *     [
 *         "inv_status_flag = 1",
 *         "column" => "id",
 *     ]
 * );
 *
 * echo "The maximum invoice id of paid invoices is ", $id, "\n";
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
 * // What is the minimum invoice id?
 * $id = Invoices::minimum(
 *     [
 *         "column" => "id",
 *     ]
 * );
 *
 * echo "The minimum invoice id is: ", $id;
 *
 * // What is the minimum id of paid invoices?
 * $sum = Invoices::minimum(
 *     [
 *         "inv_status_flag = 1",
 *         "column" => "id",
 *     ]
 * );
 *
 * echo "The minimum invoice id of paid invoices is ", $id;
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
 * echo $invoice->readAttribute("name");
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
	zend_bool _16;
	zval fields, _18, _14$$9, _17$$10;
	zval metaData, readConnection, schema, source, table, uniqueKey, tables, uniqueParams, dialect, row, attribute, manager, columnMap, _0, _3, _10, *_11, _12, *_13, _15, _19, _20, _23, _1$$3, _2$$3, _4$$6, _7$$6, _5$$7, _6$$7, _8$$8, _9$$8, _21$$11, _22$$11;
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
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_17$$10);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dirtyState", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("modelsManager", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("uniqueKey", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("uniqueParams", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("uniqueTypes", 11, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 999, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!ZEPHIR_IS_LONG(&_0, 0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_exceptions_recordcannotrefresh_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_get_class(&_2$$3, this_ptr, 0);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model.zep", 2745);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&readConnection, this_ptr, "getreadconnection", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 996, PH_NOISY_CC | PH_READONLY);
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
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_2, 1008, PH_NOISY_CC | PH_READONLY);
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
			zephir_throw_exception_debug(&_5$$7, "phalcon/Mvc/Model.zep", 2768);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_7$$6, this_ptr, _zephir_prop_2, 1008, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&uniqueKey, &_7$$6);
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_3, 1009, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueParams, &_3);
	if (UNEXPECTED(Z_TYPE_P(&uniqueParams) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_8$$8);
		object_init_ex(&_8$$8, phalcon_mvc_model_exceptions_recordcannotrefresh_ce);
		ZEPHIR_INIT_VAR(&_9$$8);
		zephir_get_class(&_9$$8, this_ptr, 0);
		ZEPHIR_CALL_METHOD(NULL, &_8$$8, "__construct", NULL, 0, &_9$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$8, "phalcon/Mvc/Model.zep", 2777);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&fields);
	array_init(&fields);
	ZEPHIR_CALL_METHOD(&_10, &metaData, "getattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (Z_TYPE_P(&_10) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_12);
		zephir_string_to_char_array(&_12, &_10);
		_11 = &_12;
	} else {
		_11 = &_10;
	}
	zephir_is_iterable(_11, 0, "phalcon/Mvc/Model.zep", 2792);
	if (Z_TYPE_P(_11) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_11), _13)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _13);
			ZEPHIR_INIT_NVAR(&_14$$9);
			zephir_create_array(&_14$$9, 1, 0);
			zephir_array_fast_append(&_14$$9, &attribute);
			zephir_array_append(&fields, &_14$$9, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2786);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _11, "rewind", NULL, 0);
		zephir_check_call_status();
		_16 = 1;
		while (1) {
			if (_16) {
				_16 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _11, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_15, _11, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attribute, _11, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_17$$10);
				zephir_create_array(&_17$$10, 1, 0);
				zephir_array_fast_append(&_17$$10, &attribute);
				zephir_array_append(&fields, &_17$$10, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2786);
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
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_4, 1010, PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_20, 2);
	ZEPHIR_CALL_METHOD(&row, &readConnection, "fetchone", NULL, 0, &tables, &_20, &uniqueParams, &_3);
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
 * // Creating a new invoice
 * $invoice = new Invoices();
 *
 * $invoice->inv_status_flag = "mechanical";
 * $invoice->inv_title = "Test Invoice";
 * $invoice->inv_total = 1952;
 *
 * $invoice->save();
 *
 * // Updating an invoice name
 * $invoice = Invoices::findFirst("id = 100");
 *
 * $invoice->inv_title = "Biomass";
 *
 * $invoice->save();
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
	ZEPHIR_CALL_METHOD(NULL, &visited, "__construct", NULL, 42);
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
	zend_bool hasRelatedToSave = 0, _14, _22$$21;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *visited, visited_sub, exists, identityField, manager, metaData, objId, relatedToSave, schema, source, success, table, writeConnection, savedSnapshot, savedOldSnapshot, _0, _1, _6, _13, _15, _16, _19, _2$$4, _3$$5, _4$$8, _5$$9, _7$$11, _8$$10, _9$$10, _10$$10, _11$$12, _12$$12, _17$$16, _18$$18, _20$$20, _21$$21, _23$$21, _24$$21, _25$$24, _26$$23, _27$$23, _28$$23;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&visited_sub);
	ZVAL_UNDEF(&exists);
	ZVAL_UNDEF(&identityField);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&objId);
	ZVAL_UNDEF(&relatedToSave);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&writeConnection);
	ZVAL_UNDEF(&savedSnapshot);
	ZVAL_UNDEF(&savedOldSnapshot);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&_18$$18);
	ZVAL_UNDEF(&_20$$20);
	ZVAL_UNDEF(&_21$$21);
	ZVAL_UNDEF(&_23$$21);
	ZVAL_UNDEF(&_24$$21);
	ZVAL_UNDEF(&_25$$24);
	ZVAL_UNDEF(&_26$$23);
	ZVAL_UNDEF(&_27$$23);
	ZVAL_UNDEF(&_28$$23);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	static zend_string *_zephir_prop_7 = NULL;
	static zend_string *_zephir_prop_8 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("syncRelated", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("operationMade", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("errorMessages", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("snapshot", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("oldSnapshot", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("dirtyState", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("dirtyRelated", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("related", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_8)) {
		_zephir_prop_8 = zend_string_init("modelsManager", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(visited, phalcon_support_collection_collectioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &visited);
	ZEPHIR_INIT_VAR(&savedSnapshot);
	array_init(&savedSnapshot);
	ZEPHIR_INIT_VAR(&savedOldSnapshot);
	array_init(&savedOldSnapshot);
	ZEPHIR_CALL_FUNCTION(&objId, "spl_object_id", NULL, 53, this_ptr);
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
	hasRelatedToSave = !(ZEPHIR_IS_EMPTY(&relatedToSave));
	if (hasRelatedToSave) {
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "presaverelatedrecords", NULL, 0, &writeConnection, &relatedToSave, visited);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_2$$4)) {
			ZEPHIR_INIT_VAR(&_3$$5);
			array_init(&_3$$5);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1011, &_3$$5);
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
	ZEPHIR_CALL_METHOD(&exists, this_ptr, "has", NULL, 0, &metaData, &writeConnection);
	zephir_check_call_status();
	if (zephir_is_true(&exists)) {
		ZVAL_UNDEF(&_4$$8);
		ZVAL_LONG(&_4$$8, 2);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1003, &_4$$8);
	} else {
		ZVAL_UNDEF(&_5$$9);
		ZVAL_LONG(&_5$$9, 1);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1003, &_5$$9);
	}
	ZEPHIR_INIT_NVAR(&_1);
	array_init(&_1);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1002, &_1);
	ZEPHIR_CALL_METHOD(&identityField, &metaData, "getidentityfield", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "presave", NULL, 0, &metaData, &exists, &identityField);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_6)) {
		if (hasRelatedToSave) {
			ZVAL_BOOL(&_7$$11, 0);
			ZEPHIR_CALL_METHOD(NULL, &writeConnection, "rollback", NULL, 0, &_7$$11);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(&_8$$10);
		array_init(&_8$$10);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1011, &_8$$10);
		ZEPHIR_INIT_VAR(&_10$$10);
		ZVAL_STRING(&_10$$10, "orm.exception_on_failed_save");
		ZEPHIR_CALL_CE_STATIC(&_9$$10, phalcon_support_settings_ce, "get", NULL, 0, &_10$$10);
		zephir_check_call_status();
		if (UNEXPECTED(zephir_is_true(&_9$$10))) {
			ZEPHIR_INIT_VAR(&_11$$12);
			object_init_ex(&_11$$12, phalcon_mvc_model_validationfailed_ce);
			ZEPHIR_CALL_METHOD(&_12$$12, this_ptr, "getmessages", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_11$$12, "__construct", NULL, 0, this_ptr, &_12$$12);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_11$$12, "phalcon/Mvc/Model.zep", 2968);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_13, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
	zephir_check_call_status();
	_14 = zephir_is_true(&_13);
	if (_14) {
		ZEPHIR_INIT_VAR(&_16);
		ZVAL_STRING(&_16, "orm.update_snapshot_on_save");
		ZEPHIR_CALL_CE_STATIC(&_15, phalcon_support_settings_ce, "get", NULL, 0, &_16);
		zephir_check_call_status();
		_14 = zephir_is_true(&_15);
	}
	if (_14) {
		ZEPHIR_OBS_NVAR(&savedSnapshot);
		zephir_read_property_cached(&savedSnapshot, this_ptr, _zephir_prop_3, 1000, PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(&savedOldSnapshot);
		zephir_read_property_cached(&savedOldSnapshot, this_ptr, _zephir_prop_4, 1007, PH_NOISY_CC);
	}
	if (zephir_is_true(&exists)) {
		ZEPHIR_CALL_METHOD(&success, this_ptr, "dolowupdate", NULL, 0, &metaData, &writeConnection, &table);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&success, this_ptr, "dolowinsert", NULL, 0, &metaData, &writeConnection, &table, &identityField);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_TRUE_IDENTICAL(&success)) {
		ZVAL_UNDEF(&_17$$16);
		ZVAL_LONG(&_17$$16, 0);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 999, &_17$$16);
	}
	if (hasRelatedToSave) {
		if (ZEPHIR_IS_FALSE_IDENTICAL(&success)) {
			ZVAL_BOOL(&_18$$18, 0);
			ZEPHIR_CALL_METHOD(NULL, &writeConnection, "rollback", NULL, 0, &_18$$18);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&success, this_ptr, "postsaverelatedrecords", NULL, 0, &writeConnection, &relatedToSave, visited);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&_16);
	ZVAL_STRING(&_16, "orm.events");
	ZEPHIR_CALL_CE_STATIC(&_19, phalcon_support_settings_ce, "get", NULL, 0, &_16);
	zephir_check_call_status();
	if (zephir_is_true(&_19)) {
		ZEPHIR_CALL_METHOD(&_20$$20, this_ptr, "postsave", NULL, 0, &success, &exists);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&success, &_20$$20);
	}
	if (ZEPHIR_IS_FALSE_IDENTICAL(&success)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "canceloperation", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_21$$21, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		_22$$21 = zephir_is_true(&_21$$21);
		if (_22$$21) {
			ZEPHIR_INIT_VAR(&_24$$21);
			ZVAL_STRING(&_24$$21, "orm.update_snapshot_on_save");
			ZEPHIR_CALL_CE_STATIC(&_23$$21, phalcon_support_settings_ce, "get", NULL, 0, &_24$$21);
			zephir_check_call_status();
			_22$$21 = zephir_is_true(&_23$$21);
		}
		if (_22$$21) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1000, &savedSnapshot);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1007, &savedOldSnapshot);
		}
	} else {
		if (hasRelatedToSave) {
			ZEPHIR_INIT_VAR(&_25$$24);
			array_init(&_25$$24);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 997, &_25$$24);
		}
		ZEPHIR_INIT_VAR(&_26$$23);
		array_init(&_26$$23);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 998, &_26$$23);
		zephir_read_property_cached(&_27$$23, this_ptr, _zephir_prop_8, 996, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_27$$23, "clearreusableobjects", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_28$$23);
		ZVAL_STRING(&_28$$23, "afterSave");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_28$$23);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_16);
	array_init(&_16);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1011, &_16);
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dirtyState", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("snapshot", 8, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&snapshot);
	ZVAL_NULL(&snapshot);
	ZVAL_NULL(&_0);
	ZVAL_BOOL(&_1, 0);
	ZEPHIR_CALL_METHOD(&attributes, this_ptr, "toarray", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 999, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dirtyState, &_0);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_2);
	ZEPHIR_CALL_METHOD(&_2, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
	zephir_check_call_status();
	_3 = zephir_is_true(&_2);
	if (_3) {
		zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1000, PH_NOISY_CC | PH_READONLY);
		_3 = Z_TYPE_P(&_0) != IS_NULL;
	}
	_4 = _3;
	if (_4) {
		zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 1000, PH_NOISY_CC | PH_READONLY);
		_4 = !ZEPHIR_IS_EQUAL(&attributes, &_1);
	}
	if (_4) {
		zephir_read_property_cached(&_5$$3, this_ptr, _zephir_prop_1, 1000, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&snapshot, &_5$$3);
	}
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 3, 0);
	zephir_array_update_string(&_6, SL("attributes"), &attributes, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_6, SL("snapshot"), &snapshot, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_6, SL("dirtyState"), &dirtyState, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 22, &_6);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Unserializes the object from a serialized string
 */
PHP_METHOD(Phalcon_Mvc_Model, unserialize)
{
	zend_bool _15$$8;
	zend_ulong _10$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data_zv, attributes, container, manager, key, value, snapshot, properties, dirtyState, _0$$4, _1$$5, _2$$5, _3$$3, _4$$3, _5$$6, _6$$6, *_7$$8, _8$$8, *_9$$8, _14$$8, _12$$9, _13$$9, _16$$12, _17$$12, _18$$18;
	zend_string *data = NULL, *_11$$8;
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
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$18);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("modelsManager", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("dirtyState", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("snapshot", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	ZEPHIR_CALL_FUNCTION(&attributes, "unserialize", NULL, 27, &data_zv);
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
			zephir_throw_exception_debug(&_1$$5, "phalcon/Mvc/Model.zep", 3110);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 995, &container);
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
			zephir_throw_exception_debug(&_5$$6, "phalcon/Mvc/Model.zep", 3124);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 996, &manager);
		ZEPHIR_CALL_METHOD(NULL, &manager, "initialize", NULL, 0, this_ptr);
		zephir_check_call_status();
		if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("onconstruct")) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "onconstruct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_memory_observe(&properties);
		if (zephir_array_isset_string_fetch(&properties, &attributes, SL("attributes"), 0)) {
			if (Z_TYPE_P(&properties) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_8$$8);
				zephir_string_to_char_array(&_8$$8, &properties);
				_7$$8 = &_8$$8;
			} else {
				_7$$8 = &properties;
			}
			zephir_is_iterable(_7$$8, 0, "phalcon/Mvc/Model.zep", 3163);
			if (Z_TYPE_P(_7$$8) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_7$$8), _10$$8, _11$$8, _9$$8)
				{
					ZEPHIR_INIT_NVAR(&key);
					if (_11$$8 != NULL) { 
						ZVAL_STR_COPY(&key, _11$$8);
					} else {
						ZVAL_LONG(&key, _10$$8);
					}
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_COPY(&value, _9$$8);

					/* try_start_1: */

						zephir_update_property_zval_zval(this_ptr, &key, &value);

					try_end_1:

					if (EG(exception)) {
						ZEPHIR_INIT_NVAR(&_12$$9);
						ZVAL_OBJ(&_12$$9, EG(exception));
						Z_ADDREF_P(&_12$$9);
						ZEPHIR_INIT_NVAR(&_13$$9);
						if (zephir_is_instance_of(&_12$$9, SL("TypeError"))) {
							zend_clear_exception();
							ZEPHIR_CPY_WRT(&_13$$9, &_12$$9);
						}
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _7$$8, "rewind", NULL, 0);
				zephir_check_call_status();
				_15$$8 = 1;
				while (1) {
					if (_15$$8) {
						_15$$8 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _7$$8, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_14$$8, _7$$8, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_14$$8)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&key, _7$$8, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&value, _7$$8, "current", NULL, 0);
					zephir_check_call_status();

						/* try_start_2: */

							zephir_update_property_zval_zval(this_ptr, &key, &value);

						try_end_2:

						if (EG(exception)) {
							ZEPHIR_INIT_NVAR(&_16$$12);
							ZVAL_OBJ(&_16$$12, EG(exception));
							Z_ADDREF_P(&_16$$12);
							ZEPHIR_INIT_NVAR(&_17$$12);
							if (zephir_is_instance_of(&_16$$12, SL("TypeError"))) {
								zend_clear_exception();
								ZEPHIR_CPY_WRT(&_17$$12, &_16$$12);
							}
						}
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
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 999, &dirtyState);
		}
		ZEPHIR_CALL_METHOD(&_3$$3, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (zephir_is_true(&_3$$3)) {
			if (zephir_array_isset_string_fetch(&snapshot, &attributes, SL("snapshot"), 1)) {
				ZEPHIR_INIT_VAR(&_18$$18);
				if (Z_TYPE_P(&snapshot) != IS_NULL) {
					ZEPHIR_CPY_WRT(&_18$$18, &snapshot);
				} else {
					ZEPHIR_CPY_WRT(&_18$$18, &properties);
				}
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1000, &_18$$18);
			} else {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1000, &properties);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(connectionService)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&connectionService_zv);
	ZVAL_STR_COPY(&connectionService_zv, connectionService);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dirtyState", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(dirtyState)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &dirtyState_param);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, dirtyState);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 999, &_0);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, phalcon_events_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &eventsManager);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(connectionService)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&connectionService_zv);
	ZVAL_STR_COPY(&connectionService_zv, connectionService);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
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
	zend_bool _14$$3;
	zend_string *_2$$3;
	zend_ulong _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *columnMap = NULL, columnMap_sub, __$null, key, value, attribute, *_0$$3, _13$$3, _3$$6, _5$$6, _6$$7, _7$$7, _9$$9, _10$$9, _11$$10, _12$$10, _15$$13, _16$$13, _17$$14, _18$$14, _19$$16, _20$$16, _21$$17, _22$$17;
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
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_17$$14);
	ZVAL_UNDEF(&_18$$14);
	ZVAL_UNDEF(&_19$$16);
	ZVAL_UNDEF(&_20$$16);
	ZVAL_UNDEF(&_21$$17);
	ZVAL_UNDEF(&_22$$17);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("oldSnapshot", 11, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(columnMap)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &data_param, &columnMap);
	zephir_get_arrval(&data, data_param);
	if (!columnMap) {
		columnMap = &columnMap_sub;
		columnMap = &__$null;
	}
	if (Z_TYPE_P(columnMap) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&snapshot);
		array_init(&snapshot);
		zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 3279);
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
						zephir_throw_exception_debug(&_6$$7, "phalcon/Mvc/Model.zep", 3261);
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
							zephir_throw_exception_debug(&_11$$10, "phalcon/Mvc/Model.zep", 3270);
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
			_14$$3 = 1;
			while (1) {
				if (_14$$3) {
					_14$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
					zephir_check_call_status();
				}
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
						ZEPHIR_INIT_NVAR(&_16$$13);
						ZVAL_STRING(&_16$$13, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_15$$13, phalcon_support_settings_ce, "get", &_4, 0, &_16$$13);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_15$$13))) {
							ZEPHIR_INIT_NVAR(&_17$$14);
							object_init_ex(&_17$$14, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							ZEPHIR_INIT_NVAR(&_18$$14);
							zephir_get_class(&_18$$14, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_17$$14, "__construct", &_8, 0, &key, &_18$$14);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_17$$14, "phalcon/Mvc/Model.zep", 3261);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
					if (Z_TYPE_P(&attribute) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attribute);
						if (!(zephir_array_isset_long_fetch(&attribute, &attribute, 0, 0))) {
							ZEPHIR_INIT_NVAR(&_20$$16);
							ZVAL_STRING(&_20$$16, "orm.ignore_unknown_columns");
							ZEPHIR_CALL_CE_STATIC(&_19$$16, phalcon_support_settings_ce, "get", &_4, 0, &_20$$16);
							zephir_check_call_status();
							if (UNEXPECTED(!zephir_is_true(&_19$$16))) {
								ZEPHIR_INIT_NVAR(&_21$$17);
								object_init_ex(&_21$$17, phalcon_mvc_model_exceptions_columnnotinmap_ce);
								ZEPHIR_INIT_NVAR(&_22$$17);
								zephir_get_class(&_22$$17, this_ptr, 0);
								ZEPHIR_CALL_METHOD(NULL, &_21$$17, "__construct", &_8, 0, &key, &_22$$17);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_21$$17, "phalcon/Mvc/Model.zep", 3270);
								ZEPHIR_MM_RESTORE();
								return;
							}
							continue;
						}
					}
					zephir_array_update_zval(&snapshot, &attribute, &value, PH_COPY | PH_SEPARATE);
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		ZEPHIR_CPY_WRT(&snapshot, &data);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1007, &snapshot);
	ZEPHIR_MM_RESTORE();
}

/**
 * Stores related records in the relation cache, so that a subsequent
 * getRelated() or property access returns them without querying.
 *
 * This is the write side of the cache getRelated() already reads. It does
 * not mark the record dirty: the value lands in `related`, never in
 * `dirtyRelated`, so save() is unaffected.
 *
 * @param mixed $records ModelInterface, Row, ResultsetInterface or null
 */
PHP_METHOD(Phalcon_Mvc_Model, setRelated)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval alias_zv, *records, records_sub, _0;
	zend_string *alias = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias_zv);
	ZVAL_UNDEF(&records_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(alias)
		Z_PARAM_ZVAL(records)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	records = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&alias_zv);
	ZVAL_STR_COPY(&alias_zv, alias);
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, &alias_zv);
	zephir_update_property_array(this_ptr, SL("related"), &_0, records);
	RETURN_THIS();
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
	zend_bool _20$$3, _3$$4, _4$$4, _21$$12, _22$$12;
	zend_string *_2$$3;
	zend_ulong _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *columnMap = NULL, columnMap_sub, __$null, key, value, attribute, *_0$$3, _19$$3, _5$$4, _7$$4, _8$$6, _10$$7, _11$$7, _12$$8, _13$$8, _15$$10, _16$$10, _17$$11, _18$$11, _23$$12, _24$$12, _25$$14, _26$$15, _27$$15, _28$$16, _29$$16, _30$$18, _31$$18, _32$$19, _33$$19;
	zval data, snapshot;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_23$$12);
	ZVAL_UNDEF(&_24$$12);
	ZVAL_UNDEF(&_25$$14);
	ZVAL_UNDEF(&_26$$15);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_28$$16);
	ZVAL_UNDEF(&_29$$16);
	ZVAL_UNDEF(&_30$$18);
	ZVAL_UNDEF(&_31$$18);
	ZVAL_UNDEF(&_32$$19);
	ZVAL_UNDEF(&_33$$19);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("snapshot", 8, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(columnMap)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &data_param, &columnMap);
	zephir_get_arrval(&data, data_param);
	if (!columnMap) {
		columnMap = &columnMap_sub;
		columnMap = &__$null;
	}
	if (Z_TYPE_P(columnMap) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&snapshot);
		array_init(&snapshot);
		zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 3359);
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
				_3$$4 = Z_TYPE_P(columnMap) == IS_ARRAY;
				if (_3$$4) {
					_3$$4 = !(zephir_array_isset_value(columnMap, &key));
				}
				_4$$4 = _3$$4;
				if (_4$$4) {
					ZEPHIR_INIT_NVAR(&_7$$4);
					ZVAL_STRING(&_7$$4, "orm.case_insensitive_column_map");
					ZEPHIR_CALL_CE_STATIC(&_5$$4, phalcon_support_settings_ce, "get", &_6, 0, &_7$$4);
					zephir_check_call_status();
					_4$$4 = zephir_is_true(&_5$$4);
				}
				if (_4$$4) {
					ZEPHIR_CALL_SELF(&_8$$6, "caseinsensitivecolumnmap", &_9, 0, columnMap, &key);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&key, &_8$$6);
				}
				ZEPHIR_OBS_NVAR(&attribute);
				if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0))) {
					ZEPHIR_INIT_NVAR(&_11$$7);
					ZVAL_STRING(&_11$$7, "orm.ignore_unknown_columns");
					ZEPHIR_CALL_CE_STATIC(&_10$$7, phalcon_support_settings_ce, "get", &_6, 0, &_11$$7);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&_10$$7))) {
						ZEPHIR_INIT_NVAR(&_12$$8);
						object_init_ex(&_12$$8, phalcon_mvc_model_exceptions_columnnotinmap_ce);
						ZEPHIR_INIT_NVAR(&_13$$8);
						zephir_get_class(&_13$$8, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_12$$8, "__construct", &_14, 0, &key, &_13$$8);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_12$$8, "phalcon/Mvc/Model.zep", 3341);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
				if (Z_TYPE_P(&attribute) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attribute);
					if (!(zephir_array_isset_long_fetch(&attribute, &attribute, 0, 0))) {
						ZEPHIR_INIT_NVAR(&_16$$10);
						ZVAL_STRING(&_16$$10, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_15$$10, phalcon_support_settings_ce, "get", &_6, 0, &_16$$10);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_15$$10))) {
							ZEPHIR_INIT_NVAR(&_17$$11);
							object_init_ex(&_17$$11, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							ZEPHIR_INIT_NVAR(&_18$$11);
							zephir_get_class(&_18$$11, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_17$$11, "__construct", &_14, 0, &key, &_18$$11);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_17$$11, "phalcon/Mvc/Model.zep", 3350);
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
			_20$$3 = 1;
			while (1) {
				if (_20$$3) {
					_20$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_19$$3, &data, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_19$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&key) != IS_STRING) {
						continue;
					}
					_21$$12 = Z_TYPE_P(columnMap) == IS_ARRAY;
					if (_21$$12) {
						_21$$12 = !(zephir_array_isset_value(columnMap, &key));
					}
					_22$$12 = _21$$12;
					if (_22$$12) {
						ZEPHIR_INIT_NVAR(&_24$$12);
						ZVAL_STRING(&_24$$12, "orm.case_insensitive_column_map");
						ZEPHIR_CALL_CE_STATIC(&_23$$12, phalcon_support_settings_ce, "get", &_6, 0, &_24$$12);
						zephir_check_call_status();
						_22$$12 = zephir_is_true(&_23$$12);
					}
					if (_22$$12) {
						ZEPHIR_CALL_SELF(&_25$$14, "caseinsensitivecolumnmap", &_9, 0, columnMap, &key);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&key, &_25$$14);
					}
					ZEPHIR_OBS_NVAR(&attribute);
					if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0))) {
						ZEPHIR_INIT_NVAR(&_27$$15);
						ZVAL_STRING(&_27$$15, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_26$$15, phalcon_support_settings_ce, "get", &_6, 0, &_27$$15);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_26$$15))) {
							ZEPHIR_INIT_NVAR(&_28$$16);
							object_init_ex(&_28$$16, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							ZEPHIR_INIT_NVAR(&_29$$16);
							zephir_get_class(&_29$$16, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_28$$16, "__construct", &_14, 0, &key, &_29$$16);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_28$$16, "phalcon/Mvc/Model.zep", 3341);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
					if (Z_TYPE_P(&attribute) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attribute);
						if (!(zephir_array_isset_long_fetch(&attribute, &attribute, 0, 0))) {
							ZEPHIR_INIT_NVAR(&_31$$18);
							ZVAL_STRING(&_31$$18, "orm.ignore_unknown_columns");
							ZEPHIR_CALL_CE_STATIC(&_30$$18, phalcon_support_settings_ce, "get", &_6, 0, &_31$$18);
							zephir_check_call_status();
							if (UNEXPECTED(!zephir_is_true(&_30$$18))) {
								ZEPHIR_INIT_NVAR(&_32$$19);
								object_init_ex(&_32$$19, phalcon_mvc_model_exceptions_columnnotinmap_ce);
								ZEPHIR_INIT_NVAR(&_33$$19);
								zephir_get_class(&_33$$19, this_ptr, 0);
								ZEPHIR_CALL_METHOD(NULL, &_32$$19, "__construct", &_14, 0, &key, &_33$$19);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_32$$19, "phalcon/Mvc/Model.zep", 3350);
								ZEPHIR_MM_RESTORE();
								return;
							}
							continue;
						}
					}
					zephir_array_update_zval(&snapshot, &attribute, &value, PH_COPY | PH_SEPARATE);
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		ZEPHIR_CPY_WRT(&snapshot, &data);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1000, &snapshot);
	ZEPHIR_MM_RESTORE();
}

/**
 * Marks one or more many-to-many relationships to be synchronized (or not)
 * on the next save() call, overriding the relation's `sync` option for that
 * save only. The flag is cleared after save().
 *
 * When syncing is enabled, intermediate rows for related records no longer
 * present in the assigned array are deleted.
 *
 *```php
 * // Sync only the "tags" relationship on this save
 * $post->setSync("tags")->save();
 *
 * // Sync every many-to-many relationship on this save
 * $post->setSync()->save();
 *
 * // Disable syncing for every relationship on this save
 * $post->setSync("*", false)->save();
 *
 * // Disable syncing for specific relationships on this save
 * $post->setSync(["tags", "categories"], false)->save();
 *```
 *
 * @param string|array|null elements
 */
PHP_METHOD(Phalcon_Mvc_Model, setSync)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool enabled, _0, _9$$4;
	zval *elements = NULL, elements_sub, *enabled_param = NULL, __$null, alias, _12, _13, _1$$3, _2$$3, *_3$$4, _4$$4, *_5$$4, _8$$4, _6$$5, _7$$5, _10$$6, _11$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&elements_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(elements)
		Z_PARAM_BOOL(enabled)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &elements, &enabled_param);
	if (!elements) {
		elements = &elements_sub;
		elements = &__$null;
	}
	if (!enabled_param) {
		enabled = 1;
	} else {
		}
	_0 = Z_TYPE_P(elements) == IS_NULL;
	if (!(_0)) {
		_0 = ZEPHIR_IS_STRING_IDENTICAL(elements, "*");
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "*");
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_BOOL(&_2$$3, enabled);
		zephir_update_property_array(this_ptr, SL("syncRelated"), &_1$$3, &_2$$3);
		RETURN_THIS();
	}
	if (Z_TYPE_P(elements) == IS_ARRAY) {
		if (Z_TYPE_P(elements) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_4$$4);
			zephir_string_to_char_array(&_4$$4, elements);
			_3$$4 = &_4$$4;
		} else {
			_3$$4 = elements;
		}
		zephir_is_iterable(_3$$4, 0, "phalcon/Mvc/Model.zep", 3406);
		if (Z_TYPE_P(_3$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3$$4), _5$$4)
			{
				ZEPHIR_INIT_NVAR(&alias);
				ZVAL_COPY(&alias, _5$$4);
				ZEPHIR_INIT_NVAR(&_6$$5);
				zephir_fast_strtolower(&_6$$5, &alias);
				ZEPHIR_INIT_NVAR(&_7$$5);
				ZVAL_BOOL(&_7$$5, enabled);
				zephir_update_property_array(this_ptr, SL("syncRelated"), &_6$$5, &_7$$5);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _3$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			_9$$4 = 1;
			while (1) {
				if (_9$$4) {
					_9$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _3$$4, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_8$$4, _3$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_8$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&alias, _3$$4, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_10$$6);
					zephir_fast_strtolower(&_10$$6, &alias);
					ZEPHIR_INIT_NVAR(&_11$$6);
					ZVAL_BOOL(&_11$$6, enabled);
					zephir_update_property_array(this_ptr, SL("syncRelated"), &_10$$6, &_11$$6);
			}
		}
		ZEPHIR_INIT_NVAR(&alias);
		RETURN_THIS();
	}
	ZEPHIR_INIT_VAR(&_12);
	zephir_fast_strtolower(&_12, elements);
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_BOOL(&_13, enabled);
	zephir_update_property_array(this_ptr, SL("syncRelated"), &_12, &_13);
	RETURN_THIS();
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
 *     $invoice = new Invoices();
 *
 *     $invoice->setTransaction($transaction);
 *
 *     $invoice->inv_title       = "WALL·E";
 *     $invoice->created_at = date("Y-m-d");
 *
 *     if ($invoice->save() === false) {
 *         $transaction->rollback("Can't save invoice");
 *     }
 *
 *     $invoicePart = new OrdersProducts();
 *
 *     $invoicePart->setTransaction($transaction);
 *
 *     $invoicePart->type = "head";
 *
 *     if ($invoicePart->save() === false) {
 *         $transaction->rollback("Invoices part cannot be saved");
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("transaction", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(transaction, phalcon_mvc_model_transactioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &transaction);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1006, transaction);
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Mvc_Model, getTransaction)
{

	RETURN_MEMBER(getThis(), "transaction");
}

/**
 * Enables/disables options in the ORM.
 *
 * The options are written to process-global `Phalcon\Support\Settings`
 * (`orm.*` flags) and therefore affect every model in the process at once.
 * Call this once during bootstrap; it is not per-model or per-container
 * configuration, and one application's `setup()` reconfigures the ORM for
 * every other user in the same process.
 */
PHP_METHOD(Phalcon_Mvc_Model, setup)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, disableEvents, columnRenaming, notNullValidations, exceptionOnFailedSave, exceptionOnFailedMetaDataSave, phqlLiterals, virtualForeignKeys, lateStateBinding, castOnHydrate, ignoreUnknownColumns, updateSnapshotOnSave, disableAssignSetters, caseInsensitiveColumnMap, prefetchRecords, lastInsertId, _0$$3, _1$$3, _2$$4, _3$$4, _4$$5, _5$$5, _6$$6, _7$$6, _8$$7, _9$$7, _10$$8, _11$$8, _12$$9, _13$$9, _14$$10, _15$$10, _16$$11, _17$$11, _18$$12, _19$$12, _20$$13, _21$$13, _22$$14, _23$$14, _24$$15, _25$$15, _26$$16, _27$$16, _28$$17, _29$$17;
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
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_25$$15);
	ZVAL_UNDEF(&_26$$16);
	ZVAL_UNDEF(&_27$$16);
	ZVAL_UNDEF(&_28$$17);
	ZVAL_UNDEF(&_29$$17);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &options_param);
	zephir_get_arrval(&options, options_param);
	zephir_memory_observe(&disableEvents);
	if (zephir_array_isset_string_fetch(&disableEvents, &options, SL("events"), 0)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "orm.events");
		ZVAL_BOOL(&_1$$3, zephir_get_boolval(&disableEvents));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_0$$3, &_1$$3);
		zephir_check_call_status();
	}
	zephir_memory_observe(&virtualForeignKeys);
	if (zephir_array_isset_string_fetch(&virtualForeignKeys, &options, SL("virtualForeignKeys"), 0)) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "orm.virtual_foreign_keys");
		ZVAL_BOOL(&_3$$4, zephir_get_boolval(&virtualForeignKeys));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_2$$4, &_3$$4);
		zephir_check_call_status();
	}
	zephir_memory_observe(&columnRenaming);
	if (zephir_array_isset_string_fetch(&columnRenaming, &options, SL("columnRenaming"), 0)) {
		ZEPHIR_INIT_VAR(&_4$$5);
		ZVAL_STRING(&_4$$5, "orm.column_renaming");
		ZVAL_BOOL(&_5$$5, zephir_get_boolval(&columnRenaming));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_4$$5, &_5$$5);
		zephir_check_call_status();
	}
	zephir_memory_observe(&notNullValidations);
	if (zephir_array_isset_string_fetch(&notNullValidations, &options, SL("notNullValidations"), 0)) {
		ZEPHIR_INIT_VAR(&_6$$6);
		ZVAL_STRING(&_6$$6, "orm.not_null_validations");
		ZVAL_BOOL(&_7$$6, zephir_get_boolval(&notNullValidations));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_6$$6, &_7$$6);
		zephir_check_call_status();
	}
	zephir_memory_observe(&exceptionOnFailedSave);
	if (zephir_array_isset_string_fetch(&exceptionOnFailedSave, &options, SL("exceptionOnFailedSave"), 0)) {
		ZEPHIR_INIT_VAR(&_8$$7);
		ZVAL_STRING(&_8$$7, "orm.exception_on_failed_save");
		ZVAL_BOOL(&_9$$7, zephir_get_boolval(&exceptionOnFailedSave));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_8$$7, &_9$$7);
		zephir_check_call_status();
	}
	zephir_memory_observe(&exceptionOnFailedMetaDataSave);
	if (zephir_array_isset_string_fetch(&exceptionOnFailedMetaDataSave, &options, SL("exceptionOnFailedMetaDataSave"), 0)) {
		ZEPHIR_INIT_VAR(&_10$$8);
		ZVAL_STRING(&_10$$8, "orm.exception_on_failed_metadata_save");
		ZVAL_BOOL(&_11$$8, zephir_get_boolval(&exceptionOnFailedMetaDataSave));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_10$$8, &_11$$8);
		zephir_check_call_status();
	}
	zephir_memory_observe(&phqlLiterals);
	if (zephir_array_isset_string_fetch(&phqlLiterals, &options, SL("phqlLiterals"), 0)) {
		ZEPHIR_INIT_VAR(&_12$$9);
		ZVAL_STRING(&_12$$9, "orm.enable_literals");
		ZVAL_BOOL(&_13$$9, zephir_get_boolval(&phqlLiterals));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_12$$9, &_13$$9);
		zephir_check_call_status();
	}
	zephir_memory_observe(&lateStateBinding);
	if (zephir_array_isset_string_fetch(&lateStateBinding, &options, SL("lateStateBinding"), 0)) {
		ZEPHIR_INIT_VAR(&_14$$10);
		ZVAL_STRING(&_14$$10, "orm.late_state_binding");
		ZVAL_BOOL(&_15$$10, zephir_get_boolval(&lateStateBinding));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_14$$10, &_15$$10);
		zephir_check_call_status();
	}
	zephir_memory_observe(&castOnHydrate);
	if (zephir_array_isset_string_fetch(&castOnHydrate, &options, SL("castOnHydrate"), 0)) {
		ZEPHIR_INIT_VAR(&_16$$11);
		ZVAL_STRING(&_16$$11, "orm.cast_on_hydrate");
		ZVAL_BOOL(&_17$$11, zephir_get_boolval(&castOnHydrate));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_16$$11, &_17$$11);
		zephir_check_call_status();
	}
	zephir_memory_observe(&ignoreUnknownColumns);
	if (zephir_array_isset_string_fetch(&ignoreUnknownColumns, &options, SL("ignoreUnknownColumns"), 0)) {
		ZEPHIR_INIT_VAR(&_18$$12);
		ZVAL_STRING(&_18$$12, "orm.ignore_unknown_columns");
		ZVAL_BOOL(&_19$$12, zephir_get_boolval(&ignoreUnknownColumns));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_18$$12, &_19$$12);
		zephir_check_call_status();
	}
	zephir_memory_observe(&caseInsensitiveColumnMap);
	if (zephir_array_isset_string_fetch(&caseInsensitiveColumnMap, &options, SL("caseInsensitiveColumnMap"), 0)) {
		ZEPHIR_INIT_VAR(&_20$$13);
		ZVAL_STRING(&_20$$13, "orm.case_insensitive_column_map");
		ZVAL_BOOL(&_21$$13, zephir_get_boolval(&caseInsensitiveColumnMap));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_20$$13, &_21$$13);
		zephir_check_call_status();
	}
	zephir_memory_observe(&updateSnapshotOnSave);
	if (zephir_array_isset_string_fetch(&updateSnapshotOnSave, &options, SL("updateSnapshotOnSave"), 0)) {
		ZEPHIR_INIT_VAR(&_22$$14);
		ZVAL_STRING(&_22$$14, "orm.update_snapshot_on_save");
		ZVAL_BOOL(&_23$$14, zephir_get_boolval(&updateSnapshotOnSave));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_22$$14, &_23$$14);
		zephir_check_call_status();
	}
	zephir_memory_observe(&disableAssignSetters);
	if (zephir_array_isset_string_fetch(&disableAssignSetters, &options, SL("disableAssignSetters"), 0)) {
		ZEPHIR_INIT_VAR(&_24$$15);
		ZVAL_STRING(&_24$$15, "orm.disable_assign_setters");
		ZVAL_BOOL(&_25$$15, zephir_get_boolval(&disableAssignSetters));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_24$$15, &_25$$15);
		zephir_check_call_status();
	}
	zephir_memory_observe(&prefetchRecords);
	if (zephir_array_isset_string_fetch(&prefetchRecords, &options, SL("prefetchRecords"), 0)) {
		ZEPHIR_INIT_VAR(&_26$$16);
		ZVAL_STRING(&_26$$16, "orm.resultset_prefetch_records");
		ZVAL_LONG(&_27$$16, zephir_get_intval(&prefetchRecords));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_26$$16, &_27$$16);
		zephir_check_call_status();
	}
	zephir_memory_observe(&lastInsertId);
	if (zephir_array_isset_string_fetch(&lastInsertId, &options, SL("castLastInsertIdToInt"), 0)) {
		ZEPHIR_INIT_VAR(&_28$$17);
		ZVAL_STRING(&_28$$17, "orm.cast_last_insert_id_to_int");
		ZVAL_BOOL(&_29$$17, zephir_get_boolval(&lastInsertId));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_28$$17, &_29$$17);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(connectionService)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&connectionService_zv);
	ZVAL_STR_COPY(&connectionService_zv, connectionService);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("skipped", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(skip)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &skip_param);
	if (skip) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1004, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1004, &__$false);
	}
}

/**
 * Calculates the sum on a column for a result-set of rows that match the
 * specified conditions
 *
 * ```php
 * // How much are all invoices?
 * $sum = Invoices::sum(
 *     [
 *         "column" => "inv_total",
 *     ]
 * );
 *
 * echo "The total price of invoices is ", $sum, "\n";
 *
 * // How much are paid invoices?
 * $sum = Invoices::sum(
 *     [
 *         "inv_status_flag = 1",
 *         "column" => "inv_total",
 *     ]
 * );
 *
 * echo "The total price of paid invoices is  ", $sum, "\n";
 * ```
 *
 * @param array parameters
 * @return double | ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, sum)
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
		parameters = &__$null;
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "SUM");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "sumatory");
	ZEPHIR_CALL_SELF(&result, "groupresult", NULL, 0, &_0, &_1, parameters);
	zephir_check_call_status();
	if (Z_TYPE_P(&result) == IS_STRING) {
		RETURN_MM_DOUBLE(zephir_get_doubleval(&result));
	}
	if (Z_TYPE_P(&result) == IS_NULL) {
		RETURN_MM_DOUBLE(0.0);
	}
	RETURN_CCTOR(&result);
}

/**
 * Returns the instance as an array representation
 *
 *```php
 * print_r(
 *     $invoice->toArray()
 * );
 *```
 *
 * @param array $columns
 */
PHP_METHOD(Phalcon_Mvc_Model, toArray)
{
	zend_bool _24, _4$$4, _16$$3, _18$$3, _25$$17, _34$$16, _36$$16;
	zval data;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *columns = NULL, columns_sub, *useGetter = NULL, useGetter_sub, __$null, __$true, attribute, attributeField, columnMap, metaData, method, _0, *_1, _2, *_3, _23, _5$$4, _7$$4, _8$$5, _10$$6, _11$$6, _12$$7, _13$$7, _15$$3, _17$$3, _19$$12, _20$$11, _21$$11, _22$$14, _26$$17, _27$$17, _28$$18, _29$$19, _30$$19, _31$$20, _32$$20, _33$$16, _35$$16, _37$$25, _38$$24, _39$$24, _40$$27;
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
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_28$$18);
	ZVAL_UNDEF(&_29$$19);
	ZVAL_UNDEF(&_30$$19);
	ZVAL_UNDEF(&_31$$20);
	ZVAL_UNDEF(&_32$$20);
	ZVAL_UNDEF(&_33$$16);
	ZVAL_UNDEF(&_35$$16);
	ZVAL_UNDEF(&_37$$25);
	ZVAL_UNDEF(&_38$$24);
	ZVAL_UNDEF(&_39$$24);
	ZVAL_UNDEF(&_40$$27);
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
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &_0);
		_1 = &_2;
	} else {
		_1 = &_0;
	}
	zephir_is_iterable(_1, 0, "phalcon/Mvc/Model.zep", 3719);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _3);
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				_4$$4 = !(zephir_array_isset_value(&columnMap, &attribute));
				if (_4$$4) {
					ZEPHIR_INIT_NVAR(&_7$$4);
					ZVAL_STRING(&_7$$4, "orm.case_insensitive_column_map");
					ZEPHIR_CALL_CE_STATIC(&_5$$4, phalcon_support_settings_ce, "get", &_6, 0, &_7$$4);
					zephir_check_call_status();
					_4$$4 = zephir_is_true(&_5$$4);
				}
				if (_4$$4) {
					ZEPHIR_CALL_SELF(&_8$$5, "caseinsensitivecolumnmap", &_9, 0, &columnMap, &attribute);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&attribute, &_8$$5);
				}
				ZEPHIR_OBS_NVAR(&attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0))) {
					ZEPHIR_INIT_NVAR(&_11$$6);
					ZVAL_STRING(&_11$$6, "orm.ignore_unknown_columns");
					ZEPHIR_CALL_CE_STATIC(&_10$$6, phalcon_support_settings_ce, "get", &_6, 0, &_11$$6);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&_10$$6))) {
						ZEPHIR_INIT_NVAR(&_12$$7);
						object_init_ex(&_12$$7, phalcon_mvc_model_exceptions_columnnotinmap_ce);
						ZEPHIR_INIT_NVAR(&_13$$7);
						zephir_get_class(&_13$$7, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_12$$7, "__construct", &_14, 0, &attribute, &_13$$7);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_12$$7, "phalcon/Mvc/Model.zep", 3677);
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
			ZEPHIR_INIT_NVAR(&_15$$3);
			zephir_camelize(&_15$$3, &attributeField, NULL );
			ZEPHIR_INIT_NVAR(&method);
			ZEPHIR_CONCAT_SV(&method, "get", &_15$$3);
			_16$$3 = ZEPHIR_IS_TRUE_IDENTICAL(useGetter);
			if (_16$$3) {
				ZEPHIR_INIT_NVAR(&_17$$3);
				ZVAL_STRING(&_17$$3, "getSource");
				_16$$3 = !ZEPHIR_IS_IDENTICAL(&_17$$3, &method);
			}
			_18$$3 = _16$$3;
			if (_18$$3) {
				_18$$3 = (zephir_method_exists(this_ptr, &method)  == SUCCESS);
			}
			if (_18$$3) {

				/* try_start_1: */

					ZEPHIR_CALL_METHOD_ZVAL(&_19$$12, this_ptr, &method, NULL, 0);
					zephir_check_call_status_or_jump(try_end_1);
					zephir_array_update_zval(&data, &attributeField, &_19$$12, PH_COPY | PH_SEPARATE);

				try_end_1:

				if (EG(exception)) {
					ZEPHIR_INIT_NVAR(&_20$$11);
					ZVAL_OBJ(&_20$$11, EG(exception));
					Z_ADDREF_P(&_20$$11);
					ZEPHIR_INIT_NVAR(&_21$$11);
					if (zephir_is_instance_of(&_20$$11, SL("Error"))) {
						zend_clear_exception();
						ZEPHIR_CPY_WRT(&_21$$11, &_20$$11);
						zephir_array_update_zval(&data, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
					}
				}
			} else if (zephir_isset_property_value_zval(this_ptr, &attributeField)) {
				ZEPHIR_OBS_NVAR(&_22$$14);
				zephir_read_property_zval(&_22$$14, this_ptr, &attributeField, PH_NOISY_CC);
				zephir_array_update_zval(&data, &attributeField, &_22$$14, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&data, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_24 = 1;
		while (1) {
			if (_24) {
				_24 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_23, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_23)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attribute, _1, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					_25$$17 = !(zephir_array_isset_value(&columnMap, &attribute));
					if (_25$$17) {
						ZEPHIR_INIT_NVAR(&_27$$17);
						ZVAL_STRING(&_27$$17, "orm.case_insensitive_column_map");
						ZEPHIR_CALL_CE_STATIC(&_26$$17, phalcon_support_settings_ce, "get", &_6, 0, &_27$$17);
						zephir_check_call_status();
						_25$$17 = zephir_is_true(&_26$$17);
					}
					if (_25$$17) {
						ZEPHIR_CALL_SELF(&_28$$18, "caseinsensitivecolumnmap", &_9, 0, &columnMap, &attribute);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&attribute, &_28$$18);
					}
					ZEPHIR_OBS_NVAR(&attributeField);
					if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0))) {
						ZEPHIR_INIT_NVAR(&_30$$19);
						ZVAL_STRING(&_30$$19, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_29$$19, phalcon_support_settings_ce, "get", &_6, 0, &_30$$19);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_29$$19))) {
							ZEPHIR_INIT_NVAR(&_31$$20);
							object_init_ex(&_31$$20, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							ZEPHIR_INIT_NVAR(&_32$$20);
							zephir_get_class(&_32$$20, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_31$$20, "__construct", &_14, 0, &attribute, &_32$$20);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_31$$20, "phalcon/Mvc/Model.zep", 3677);
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
				ZEPHIR_INIT_NVAR(&_33$$16);
				zephir_camelize(&_33$$16, &attributeField, NULL );
				ZEPHIR_INIT_NVAR(&method);
				ZEPHIR_CONCAT_SV(&method, "get", &_33$$16);
				_34$$16 = ZEPHIR_IS_TRUE_IDENTICAL(useGetter);
				if (_34$$16) {
					ZEPHIR_INIT_NVAR(&_35$$16);
					ZVAL_STRING(&_35$$16, "getSource");
					_34$$16 = !ZEPHIR_IS_IDENTICAL(&_35$$16, &method);
				}
				_36$$16 = _34$$16;
				if (_36$$16) {
					_36$$16 = (zephir_method_exists(this_ptr, &method)  == SUCCESS);
				}
				if (_36$$16) {

					/* try_start_2: */

						ZEPHIR_CALL_METHOD_ZVAL(&_37$$25, this_ptr, &method, NULL, 0);
						zephir_check_call_status_or_jump(try_end_2);
						zephir_array_update_zval(&data, &attributeField, &_37$$25, PH_COPY | PH_SEPARATE);

					try_end_2:

					if (EG(exception)) {
						ZEPHIR_INIT_NVAR(&_38$$24);
						ZVAL_OBJ(&_38$$24, EG(exception));
						Z_ADDREF_P(&_38$$24);
						ZEPHIR_INIT_NVAR(&_39$$24);
						if (zephir_is_instance_of(&_38$$24, SL("Error"))) {
							zend_clear_exception();
							ZEPHIR_CPY_WRT(&_39$$24, &_38$$24);
							zephir_array_update_zval(&data, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
						}
					}
				} else if (zephir_isset_property_value_zval(this_ptr, &attributeField)) {
					ZEPHIR_OBS_NVAR(&_40$$27);
					zephir_read_property_zval(&_40$$27, this_ptr, &attributeField, PH_NOISY_CC);
					zephir_array_update_zval(&data, &attributeField, &_40$$27, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&data, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
				}
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dirtyState", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("errorMessages", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 999, PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "getwriteconnection", NULL, 0);
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
			ZEPHIR_INIT_VAR(&_7$$4);
			ZVAL_STRING(&_7$$4, "");
			ZEPHIR_INIT_VAR(&_8$$4);
			ZVAL_STRING(&_8$$4, "InvalidUpdateAttempt");
			ZVAL_LONG(&_9$$4, 0);
			ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 5, &_6$$4, &_7$$4, &_8$$4, &_9$$4, &_5$$4);
			zephir_check_call_status();
			zephir_array_fast_append(&_3$$4, &_4$$4);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1002, &_3$$4);
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
 * $invoice->writeAttribute("name", "Rosey");
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
	zend_string *_11$$7, *_40$$28;
	zend_ulong _10$$7, _39$$28;
	zend_bool error = 0, validateWithNulls = 0, _32, _19$$3, _15$$7, _48$$24, _44$$28;
	zval conditions, _21$$3, _25$$18, _50$$24, _54$$39;
	zval manager, belongsTo, foreignKey, relation, position, bindParams, extraConditions, message, messageField, fields, referencedFields, field, referencedModel, value, allowNulls, _0, *_1, _2, *_3, _31, _4$$5, _5$$3, _20$$3, _22$$3, *_7$$7, _8$$7, *_9$$7, _14$$7, _12$$8, _13$$8, _16$$10, _17$$10, _18$$12, _23$$20, _24$$18, _26$$18, _27$$18, _28$$18, _33$$26, _34$$24, _49$$24, _51$$24, *_36$$28, _37$$28, *_38$$28, _43$$28, _41$$29, _42$$29, _45$$31, _46$$31, _47$$33, _52$$41, _53$$39, _55$$39, _56$$39, _57$$39, _58$$45, _59$$45, _60$$46;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_29 = NULL, *_30 = NULL, *_35 = NULL;
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
	ZVAL_UNDEF(&messageField);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&referencedFields);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&referencedModel);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&allowNulls);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_20$$3);
	ZVAL_UNDEF(&_22$$3);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_23$$20);
	ZVAL_UNDEF(&_24$$18);
	ZVAL_UNDEF(&_26$$18);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_28$$18);
	ZVAL_UNDEF(&_33$$26);
	ZVAL_UNDEF(&_34$$24);
	ZVAL_UNDEF(&_49$$24);
	ZVAL_UNDEF(&_51$$24);
	ZVAL_UNDEF(&_37$$28);
	ZVAL_UNDEF(&_43$$28);
	ZVAL_UNDEF(&_41$$29);
	ZVAL_UNDEF(&_42$$29);
	ZVAL_UNDEF(&_45$$31);
	ZVAL_UNDEF(&_46$$31);
	ZVAL_UNDEF(&_47$$33);
	ZVAL_UNDEF(&_52$$41);
	ZVAL_UNDEF(&_53$$39);
	ZVAL_UNDEF(&_55$$39);
	ZVAL_UNDEF(&_56$$39);
	ZVAL_UNDEF(&_57$$39);
	ZVAL_UNDEF(&_58$$45);
	ZVAL_UNDEF(&_59$$45);
	ZVAL_UNDEF(&_60$$46);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&_21$$3);
	ZVAL_UNDEF(&_25$$18);
	ZVAL_UNDEF(&_50$$24);
	ZVAL_UNDEF(&_54$$39);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&belongsTo, &manager, "getbelongsto", NULL, 0, this_ptr);
	zephir_check_call_status();
	error = 0;
	if (Z_TYPE_P(&belongsTo) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &belongsTo);
		_1 = &_2;
	} else {
		_1 = &belongsTo;
	}
	zephir_is_iterable(_1, 0, "phalcon/Mvc/Model.zep", 3957);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&relation);
			ZVAL_COPY(&relation, _3);
			validateWithNulls = 0;
			ZEPHIR_CALL_METHOD(&foreignKey, &relation, "getforeignkey", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
				continue;
			}
			action = 1;
			if (zephir_array_isset_value_string(&foreignKey, SL("action"))) {
				ZEPHIR_OBS_NVAR(&_4$$5);
				zephir_array_fetch_string(&_4$$5, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 3834);
				action = zephir_get_intval(&_4$$5);
			}
			if (action != 1) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&_5$$3, &relation, "getreferencedmodel", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&referencedModel, &manager, "load", &_6, 0, &_5$$3);
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
				if (Z_TYPE_P(&fields) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_8$$7);
					zephir_string_to_char_array(&_8$$7, &fields);
					_7$$7 = &_8$$7;
				} else {
					_7$$7 = &fields;
				}
				zephir_is_iterable(_7$$7, 0, "phalcon/Mvc/Model.zep", 3877);
				if (Z_TYPE_P(_7$$7) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_7$$7), _10$$7, _11$$7, _9$$7)
					{
						ZEPHIR_INIT_NVAR(&position);
						if (_11$$7 != NULL) { 
							ZVAL_STR_COPY(&position, _11$$7);
						} else {
							ZVAL_LONG(&position, _10$$7);
						}
						ZEPHIR_INIT_NVAR(&field);
						ZVAL_COPY(&field, _9$$7);
						ZEPHIR_OBS_NVAR(&value);
						zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
						zephir_array_fetch(&_12$$8, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3869);
						ZEPHIR_INIT_NVAR(&_13$$8);
						ZEPHIR_CONCAT_SVSV(&_13$$8, "[", &_12$$8, "] = ?", &position);
						zephir_array_append(&conditions, &_13$$8, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3869);
						zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3870);
						if (Z_TYPE_P(&value) == IS_NULL) {
							numberNull++;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _7$$7, "rewind", NULL, 0);
					zephir_check_call_status();
					_15$$7 = 1;
					while (1) {
						if (_15$$7) {
							_15$$7 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _7$$7, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_14$$7, _7$$7, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_14$$7)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&position, _7$$7, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&field, _7$$7, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_OBS_NVAR(&value);
							zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
							zephir_array_fetch(&_16$$10, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3869);
							ZEPHIR_INIT_NVAR(&_17$$10);
							ZEPHIR_CONCAT_SVSV(&_17$$10, "[", &_16$$10, "] = ?", &position);
							zephir_array_append(&conditions, &_17$$10, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3869);
							zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3870);
							if (Z_TYPE_P(&value) == IS_NULL) {
								numberNull++;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&field);
				ZEPHIR_INIT_NVAR(&position);
				validateWithNulls = numberNull == zephir_fast_count_int(&fields);
			} else {
				ZEPHIR_OBS_NVAR(&value);
				zephir_fetch_property_zval(&value, this_ptr, &fields, PH_SILENT_CC);
				ZEPHIR_INIT_NVAR(&_18$$12);
				ZEPHIR_CONCAT_SVS(&_18$$12, "[", &referencedFields, "] = ?0");
				zephir_array_append(&conditions, &_18$$12, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3881);
				zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3882);
				if (Z_TYPE_P(&value) == IS_NULL) {
					validateWithNulls = 1;
				}
			}
			ZEPHIR_OBS_NVAR(&extraConditions);
			if (zephir_array_isset_string_fetch(&extraConditions, &foreignKey, SL("conditions"), 0)) {
				zephir_array_append(&conditions, &extraConditions, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3893);
			}
			if (validateWithNulls) {
				ZEPHIR_OBS_NVAR(&allowNulls);
				if (zephir_array_isset_string_fetch(&allowNulls, &foreignKey, SL("allowNulls"), 0)) {
					validateWithNulls = zephir_get_boolval(&allowNulls);
				} else {
					validateWithNulls = 0;
				}
			}
			_19$$3 = !validateWithNulls;
			if (_19$$3) {
				ZEPHIR_INIT_NVAR(&_21$$3);
				zephir_create_array(&_21$$3, 2, 0);
				ZEPHIR_INIT_NVAR(&_22$$3);
				zephir_fast_join_str(&_22$$3, SL(" AND "), &conditions);
				zephir_array_fast_append(&_21$$3, &_22$$3);
				zephir_array_update_string(&_21$$3, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_20$$3, &referencedModel, "count", NULL, 0, &_21$$3);
				zephir_check_call_status();
				_19$$3 = !zephir_is_true(&_20$$3);
			}
			if (_19$$3) {
				ZEPHIR_OBS_NVAR(&message);
				if (!(zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0))) {
					ZEPHIR_INIT_NVAR(&message);
					if (Z_TYPE_P(&fields) == IS_ARRAY) {
						ZEPHIR_INIT_NVAR(&_23$$20);
						zephir_fast_join_str(&_23$$20, SL(", "), &fields);
						ZEPHIR_CONCAT_SVS(&message, "Value of fields \"", &_23$$20, "\" does not exist on referenced table");
					} else {
						ZEPHIR_CONCAT_SVS(&message, "Value of field \"", &fields, "\" does not exist on referenced table");
					}
				}
				if (Z_TYPE_P(&fields) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&messageField);
					zephir_fast_join_str(&messageField, SL(", "), &fields);
				} else {
					ZEPHIR_CPY_WRT(&messageField, &fields);
				}
				ZEPHIR_INIT_NVAR(&_24$$18);
				object_init_ex(&_24$$18, phalcon_messages_message_ce);
				ZEPHIR_INIT_NVAR(&_25$$18);
				zephir_create_array(&_25$$18, 2, 0);
				ZEPHIR_INIT_NVAR(&_26$$18);
				zephir_get_class(&_26$$18, this_ptr, 0);
				zephir_array_update_string(&_25$$18, SL("model"), &_26$$18, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_27$$18, &relation, "getreferencedmodel", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_25$$18, SL("referenceModel"), &_27$$18, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_26$$18);
				ZVAL_STRING(&_26$$18, "ConstraintViolation");
				ZVAL_LONG(&_28$$18, 0);
				ZEPHIR_CALL_METHOD(NULL, &_24$$18, "__construct", &_29, 5, &message, &messageField, &_26$$18, &_28$$18, &_25$$18);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_30, 0, &_24$$18);
				zephir_check_call_status();
				error = 1;
				break;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_32 = 1;
		while (1) {
			if (_32) {
				_32 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_31, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_31)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&relation, _1, "current", NULL, 0);
			zephir_check_call_status();
				validateWithNulls = 0;
				ZEPHIR_CALL_METHOD(&foreignKey, &relation, "getforeignkey", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
					continue;
				}
				action = 1;
				if (zephir_array_isset_value_string(&foreignKey, SL("action"))) {
					ZEPHIR_OBS_NVAR(&_33$$26);
					zephir_array_fetch_string(&_33$$26, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 3834);
					action = zephir_get_intval(&_33$$26);
				}
				if (action != 1) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&_34$$24, &relation, "getreferencedmodel", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedModel, &manager, "load", &_35, 0, &_34$$24);
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
					if (Z_TYPE_P(&fields) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_37$$28);
						zephir_string_to_char_array(&_37$$28, &fields);
						_36$$28 = &_37$$28;
					} else {
						_36$$28 = &fields;
					}
					zephir_is_iterable(_36$$28, 0, "phalcon/Mvc/Model.zep", 3877);
					if (Z_TYPE_P(_36$$28) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_36$$28), _39$$28, _40$$28, _38$$28)
						{
							ZEPHIR_INIT_NVAR(&position);
							if (_40$$28 != NULL) { 
								ZVAL_STR_COPY(&position, _40$$28);
							} else {
								ZVAL_LONG(&position, _39$$28);
							}
							ZEPHIR_INIT_NVAR(&field);
							ZVAL_COPY(&field, _38$$28);
							ZEPHIR_OBS_NVAR(&value);
							zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
							zephir_array_fetch(&_41$$29, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3869);
							ZEPHIR_INIT_NVAR(&_42$$29);
							ZEPHIR_CONCAT_SVSV(&_42$$29, "[", &_41$$29, "] = ?", &position);
							zephir_array_append(&conditions, &_42$$29, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3869);
							zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3870);
							if (Z_TYPE_P(&value) == IS_NULL) {
								numberNull++;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _36$$28, "rewind", NULL, 0);
						zephir_check_call_status();
						_44$$28 = 1;
						while (1) {
							if (_44$$28) {
								_44$$28 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _36$$28, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_43$$28, _36$$28, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_43$$28)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&position, _36$$28, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&field, _36$$28, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_OBS_NVAR(&value);
								zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
								zephir_array_fetch(&_45$$31, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 3869);
								ZEPHIR_INIT_NVAR(&_46$$31);
								ZEPHIR_CONCAT_SVSV(&_46$$31, "[", &_45$$31, "] = ?", &position);
								zephir_array_append(&conditions, &_46$$31, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3869);
								zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3870);
								if (Z_TYPE_P(&value) == IS_NULL) {
									numberNull++;
								}
						}
					}
					ZEPHIR_INIT_NVAR(&field);
					ZEPHIR_INIT_NVAR(&position);
					validateWithNulls = numberNull == zephir_fast_count_int(&fields);
				} else {
					ZEPHIR_OBS_NVAR(&value);
					zephir_fetch_property_zval(&value, this_ptr, &fields, PH_SILENT_CC);
					ZEPHIR_INIT_NVAR(&_47$$33);
					ZEPHIR_CONCAT_SVS(&_47$$33, "[", &referencedFields, "] = ?0");
					zephir_array_append(&conditions, &_47$$33, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3881);
					zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3882);
					if (Z_TYPE_P(&value) == IS_NULL) {
						validateWithNulls = 1;
					}
				}
				ZEPHIR_OBS_NVAR(&extraConditions);
				if (zephir_array_isset_string_fetch(&extraConditions, &foreignKey, SL("conditions"), 0)) {
					zephir_array_append(&conditions, &extraConditions, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3893);
				}
				if (validateWithNulls) {
					ZEPHIR_OBS_NVAR(&allowNulls);
					if (zephir_array_isset_string_fetch(&allowNulls, &foreignKey, SL("allowNulls"), 0)) {
						validateWithNulls = zephir_get_boolval(&allowNulls);
					} else {
						validateWithNulls = 0;
					}
				}
				_48$$24 = !validateWithNulls;
				if (_48$$24) {
					ZEPHIR_INIT_NVAR(&_50$$24);
					zephir_create_array(&_50$$24, 2, 0);
					ZEPHIR_INIT_NVAR(&_51$$24);
					zephir_fast_join_str(&_51$$24, SL(" AND "), &conditions);
					zephir_array_fast_append(&_50$$24, &_51$$24);
					zephir_array_update_string(&_50$$24, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_49$$24, &referencedModel, "count", NULL, 0, &_50$$24);
					zephir_check_call_status();
					_48$$24 = !zephir_is_true(&_49$$24);
				}
				if (_48$$24) {
					ZEPHIR_OBS_NVAR(&message);
					if (!(zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0))) {
						ZEPHIR_INIT_NVAR(&message);
						if (Z_TYPE_P(&fields) == IS_ARRAY) {
							ZEPHIR_INIT_NVAR(&_52$$41);
							zephir_fast_join_str(&_52$$41, SL(", "), &fields);
							ZEPHIR_CONCAT_SVS(&message, "Value of fields \"", &_52$$41, "\" does not exist on referenced table");
						} else {
							ZEPHIR_CONCAT_SVS(&message, "Value of field \"", &fields, "\" does not exist on referenced table");
						}
					}
					if (Z_TYPE_P(&fields) == IS_ARRAY) {
						ZEPHIR_INIT_NVAR(&messageField);
						zephir_fast_join_str(&messageField, SL(", "), &fields);
					} else {
						ZEPHIR_CPY_WRT(&messageField, &fields);
					}
					ZEPHIR_INIT_NVAR(&_53$$39);
					object_init_ex(&_53$$39, phalcon_messages_message_ce);
					ZEPHIR_INIT_NVAR(&_54$$39);
					zephir_create_array(&_54$$39, 2, 0);
					ZEPHIR_INIT_NVAR(&_55$$39);
					zephir_get_class(&_55$$39, this_ptr, 0);
					zephir_array_update_string(&_54$$39, SL("model"), &_55$$39, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_56$$39, &relation, "getreferencedmodel", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_string(&_54$$39, SL("referenceModel"), &_56$$39, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_55$$39);
					ZVAL_STRING(&_55$$39, "ConstraintViolation");
					ZVAL_LONG(&_57$$39, 0);
					ZEPHIR_CALL_METHOD(NULL, &_53$$39, "__construct", &_29, 5, &message, &messageField, &_55$$39, &_57$$39, &_54$$39);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_30, 0, &_53$$39);
					zephir_check_call_status();
					error = 1;
					break;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&relation);
	if (error) {
		ZEPHIR_INIT_VAR(&_59$$45);
		ZVAL_STRING(&_59$$45, "orm.events");
		ZEPHIR_CALL_CE_STATIC(&_58$$45, phalcon_support_settings_ce, "get", NULL, 0, &_59$$45);
		zephir_check_call_status();
		if (zephir_is_true(&_58$$45)) {
			ZEPHIR_INIT_VAR(&_60$$46);
			ZVAL_STRING(&_60$$46, "onValidationFails");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_60$$46);
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
	zend_bool _10, _4$$3, _7$$3, _11$$8, _14$$8;
	zval manager, relations, relation, foreignKey, related, _0, *_1, _2, *_3, _9, _8$$3, _5$$5, _15$$8, _12$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, action = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&foreignKey);
	ZVAL_UNDEF(&related);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_12$$10);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&relations, &manager, "gethasoneandhasmany", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (Z_TYPE_P(&relations) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &relations);
		_1 = &_2;
	} else {
		_1 = &relations;
	}
	zephir_is_iterable(_1, 0, "phalcon/Mvc/Model.zep", 4031);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&relation);
			ZVAL_COPY(&relation, _3);
			ZEPHIR_CALL_METHOD(&foreignKey, &relation, "getforeignkey", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
				continue;
			}
			action = 0;
			_4$$3 = Z_TYPE_P(&foreignKey) == IS_ARRAY;
			if (_4$$3) {
				_4$$3 = zephir_array_isset_value_string(&foreignKey, SL("action"));
			}
			if (_4$$3) {
				ZEPHIR_OBS_NVAR(&_5$$5);
				zephir_array_fetch_string(&_5$$5, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 4007);
				action = zephir_get_intval(&_5$$5);
			}
			if (action != 2) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&related, &manager, "getrelationrecords", &_6, 0, &relation, this_ptr);
			zephir_check_call_status();
			_7$$3 = zephir_is_true(&related);
			if (_7$$3) {
				ZEPHIR_CALL_METHOD(&_8$$3, &related, "delete", NULL, 0);
				zephir_check_call_status();
				_7$$3 = ZEPHIR_IS_FALSE_IDENTICAL(&_8$$3);
			}
			if (_7$$3) {
				RETURN_MM_BOOL(0);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_10 = 1;
		while (1) {
			if (_10) {
				_10 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_9, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&relation, _1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&foreignKey, &relation, "getforeignkey", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
					continue;
				}
				action = 0;
				_11$$8 = Z_TYPE_P(&foreignKey) == IS_ARRAY;
				if (_11$$8) {
					_11$$8 = zephir_array_isset_value_string(&foreignKey, SL("action"));
				}
				if (_11$$8) {
					ZEPHIR_OBS_NVAR(&_12$$10);
					zephir_array_fetch_string(&_12$$10, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 4007);
					action = zephir_get_intval(&_12$$10);
				}
				if (action != 2) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&related, &manager, "getrelationrecords", &_13, 0, &relation, this_ptr);
				zephir_check_call_status();
				_14$$8 = zephir_is_true(&related);
				if (_14$$8) {
					ZEPHIR_CALL_METHOD(&_15$$8, &related, "delete", NULL, 0);
					zephir_check_call_status();
					_14$$8 = ZEPHIR_IS_FALSE_IDENTICAL(&_15$$8);
				}
				if (_14$$8) {
					RETURN_MM_BOOL(0);
				}
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
	zval _11$$7, _25$$15;
	zval manager, relations, foreignKey, relation, relationClass, fields, message, messageField, _0, *_1, _2, *_3, _16, _6$$3, _7$$3, _8$$3, _5$$5, _10$$7, _12$$7, _13$$7, _20$$11, _21$$11, _22$$11, _19$$13, _24$$15, _26$$15, _27$$15, _28$$19, _29$$19, _30$$20;
	zend_bool error = 0, _17, _4$$3, _18$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_14 = NULL, *_15 = NULL, *_23 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, action = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&foreignKey);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&relationClass);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&messageField);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_26$$15);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_28$$19);
	ZVAL_UNDEF(&_29$$19);
	ZVAL_UNDEF(&_30$$20);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_25$$15);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&relations, &manager, "gethasoneandhasmany", NULL, 0, this_ptr);
	zephir_check_call_status();
	error = 0;
	if (Z_TYPE_P(&relations) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &relations);
		_1 = &_2;
	} else {
		_1 = &relations;
	}
	zephir_is_iterable(_1, 0, "phalcon/Mvc/Model.zep", 4131);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&relation);
			ZVAL_COPY(&relation, _3);
			ZEPHIR_CALL_METHOD(&foreignKey, &relation, "getforeignkey", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
				continue;
			}
			action = 1;
			_4$$3 = Z_TYPE_P(&foreignKey) == IS_ARRAY;
			if (_4$$3) {
				_4$$3 = zephir_array_isset_value_string(&foreignKey, SL("action"));
			}
			if (_4$$3) {
				ZEPHIR_OBS_NVAR(&_5$$5);
				zephir_array_fetch_string(&_5$$5, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 4076);
				action = zephir_get_intval(&_5$$5);
			}
			if (action != 1) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&relationClass, &relation, "getreferencedmodel", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&fields, &relation, "getfields", NULL, 0);
			zephir_check_call_status();
			ZVAL_NULL(&_7$$3);
			ZEPHIR_INIT_NVAR(&_8$$3);
			ZVAL_STRING(&_8$$3, "count");
			ZEPHIR_CALL_METHOD(&_6$$3, &manager, "getrelationrecords", &_9, 0, &relation, this_ptr, &_7$$3, &_8$$3);
			zephir_check_call_status();
			if (zephir_is_true(&_6$$3)) {
				ZEPHIR_OBS_NVAR(&message);
				if (!(zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0))) {
					ZEPHIR_INIT_NVAR(&message);
					ZEPHIR_CONCAT_SV(&message, "Record is referenced by model ", &relationClass);
				}
				if (Z_TYPE_P(&fields) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&messageField);
					zephir_fast_join_str(&messageField, SL(", "), &fields);
				} else {
					ZEPHIR_CPY_WRT(&messageField, &fields);
				}
				ZEPHIR_INIT_NVAR(&_10$$7);
				object_init_ex(&_10$$7, phalcon_messages_message_ce);
				ZEPHIR_INIT_NVAR(&_11$$7);
				zephir_create_array(&_11$$7, 2, 0);
				ZEPHIR_INIT_NVAR(&_12$$7);
				zephir_get_class(&_12$$7, this_ptr, 0);
				zephir_array_update_string(&_11$$7, SL("model"), &_12$$7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_11$$7, SL("referenceModel"), &relationClass, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_12$$7);
				ZVAL_STRING(&_12$$7, "ConstraintViolation");
				ZVAL_LONG(&_13$$7, 0);
				ZEPHIR_CALL_METHOD(NULL, &_10$$7, "__construct", &_14, 5, &message, &messageField, &_12$$7, &_13$$7, &_11$$7);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_15, 0, &_10$$7);
				zephir_check_call_status();
				error = 1;
				break;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_17 = 1;
		while (1) {
			if (_17) {
				_17 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_16, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_16)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&relation, _1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&foreignKey, &relation, "getforeignkey", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
					continue;
				}
				action = 1;
				_18$$11 = Z_TYPE_P(&foreignKey) == IS_ARRAY;
				if (_18$$11) {
					_18$$11 = zephir_array_isset_value_string(&foreignKey, SL("action"));
				}
				if (_18$$11) {
					ZEPHIR_OBS_NVAR(&_19$$13);
					zephir_array_fetch_string(&_19$$13, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 4076);
					action = zephir_get_intval(&_19$$13);
				}
				if (action != 1) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&relationClass, &relation, "getreferencedmodel", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&fields, &relation, "getfields", NULL, 0);
				zephir_check_call_status();
				ZVAL_NULL(&_21$$11);
				ZEPHIR_INIT_NVAR(&_22$$11);
				ZVAL_STRING(&_22$$11, "count");
				ZEPHIR_CALL_METHOD(&_20$$11, &manager, "getrelationrecords", &_23, 0, &relation, this_ptr, &_21$$11, &_22$$11);
				zephir_check_call_status();
				if (zephir_is_true(&_20$$11)) {
					ZEPHIR_OBS_NVAR(&message);
					if (!(zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0))) {
						ZEPHIR_INIT_NVAR(&message);
						ZEPHIR_CONCAT_SV(&message, "Record is referenced by model ", &relationClass);
					}
					if (Z_TYPE_P(&fields) == IS_ARRAY) {
						ZEPHIR_INIT_NVAR(&messageField);
						zephir_fast_join_str(&messageField, SL(", "), &fields);
					} else {
						ZEPHIR_CPY_WRT(&messageField, &fields);
					}
					ZEPHIR_INIT_NVAR(&_24$$15);
					object_init_ex(&_24$$15, phalcon_messages_message_ce);
					ZEPHIR_INIT_NVAR(&_25$$15);
					zephir_create_array(&_25$$15, 2, 0);
					ZEPHIR_INIT_NVAR(&_26$$15);
					zephir_get_class(&_26$$15, this_ptr, 0);
					zephir_array_update_string(&_25$$15, SL("model"), &_26$$15, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_25$$15, SL("referenceModel"), &relationClass, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_26$$15);
					ZVAL_STRING(&_26$$15, "ConstraintViolation");
					ZVAL_LONG(&_27$$15, 0);
					ZEPHIR_CALL_METHOD(NULL, &_24$$15, "__construct", &_14, 5, &message, &messageField, &_26$$15, &_27$$15, &_25$$15);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_15, 0, &_24$$15);
					zephir_check_call_status();
					error = 1;
					break;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&relation);
	if (error) {
		ZEPHIR_INIT_VAR(&_29$$19);
		ZVAL_STRING(&_29$$19, "orm.events");
		ZEPHIR_CALL_CE_STATIC(&_28$$19, phalcon_support_settings_ce, "get", NULL, 0, &_29$$19);
		zephir_check_call_status();
		if (zephir_is_true(&_28$$19)) {
			ZEPHIR_INIT_VAR(&_30$$20);
			ZVAL_STRING(&_30$$20, "onValidationFails");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_30$$20);
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
	zend_string *_67$$62;
	zend_ulong _66$$62;
	zend_bool useExplicitIdentity = 0, _27, _56, _8$$5, _12$$12, _30$$21, _33$$28, _50$$42, _58$$53, _69$$62;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_11 = NULL, *_16 = NULL, *_17 = NULL, *_23 = NULL, *_25 = NULL, *_37 = NULL, *_38 = NULL, *_44 = NULL, *_46 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *metaData, metaData_sub, *connection, connection_sub, *table = NULL, table_sub, *identityField, identityField_sub, __$null, attributes, automaticAttributes, bindDataTypes, bindSkip, bindType, columnMap, defaultValue, defaultValues, field, lastInsertedId, manager, rawValue, rawValues, sequenceName, schema, source, success, attributeField, bindTypes, fields, snapshot, unsetDefaultValues, value, values, _0, _1, _2, *_3, *_4, _26, _5$$7, _6$$7, _9$$11, _10$$11, _13$$13, _14$$13, _15$$13, _18$$16, _19$$16, _20$$18, _21$$18, _22$$18, _24$$18, _28$$23, _29$$23, _31$$27, _32$$27, _34$$29, _35$$29, _36$$29, _39$$32, _40$$32, _41$$34, _42$$34, _43$$34, _45$$34, _47$$37, _48$$40, _49$$40, _51$$48, _52$$48, _53$$52, _54$$52, _55$$52, _57$$53, _59$$53, _60$$53, _61$$61, _62$$61, *_63$$62, _64$$62, *_65$$62, _68$$62, _70$$62, _71$$62;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData_sub);
	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&identityField_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&automaticAttributes);
	ZVAL_UNDEF(&bindDataTypes);
	ZVAL_UNDEF(&bindSkip);
	ZVAL_UNDEF(&bindType);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&defaultValues);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&lastInsertedId);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&rawValue);
	ZVAL_UNDEF(&rawValues);
	ZVAL_UNDEF(&sequenceName);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&unsetDefaultValues);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_18$$16);
	ZVAL_UNDEF(&_19$$16);
	ZVAL_UNDEF(&_20$$18);
	ZVAL_UNDEF(&_21$$18);
	ZVAL_UNDEF(&_22$$18);
	ZVAL_UNDEF(&_24$$18);
	ZVAL_UNDEF(&_28$$23);
	ZVAL_UNDEF(&_29$$23);
	ZVAL_UNDEF(&_31$$27);
	ZVAL_UNDEF(&_32$$27);
	ZVAL_UNDEF(&_34$$29);
	ZVAL_UNDEF(&_35$$29);
	ZVAL_UNDEF(&_36$$29);
	ZVAL_UNDEF(&_39$$32);
	ZVAL_UNDEF(&_40$$32);
	ZVAL_UNDEF(&_41$$34);
	ZVAL_UNDEF(&_42$$34);
	ZVAL_UNDEF(&_43$$34);
	ZVAL_UNDEF(&_45$$34);
	ZVAL_UNDEF(&_47$$37);
	ZVAL_UNDEF(&_48$$40);
	ZVAL_UNDEF(&_49$$40);
	ZVAL_UNDEF(&_51$$48);
	ZVAL_UNDEF(&_52$$48);
	ZVAL_UNDEF(&_53$$52);
	ZVAL_UNDEF(&_54$$52);
	ZVAL_UNDEF(&_55$$52);
	ZVAL_UNDEF(&_57$$53);
	ZVAL_UNDEF(&_59$$53);
	ZVAL_UNDEF(&_60$$53);
	ZVAL_UNDEF(&_61$$61);
	ZVAL_UNDEF(&_62$$61);
	ZVAL_UNDEF(&_64$$62);
	ZVAL_UNDEF(&_68$$62);
	ZVAL_UNDEF(&_70$$62);
	ZVAL_UNDEF(&_71$$62);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("rawValues", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("uniqueKey", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("uniqueParams", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("snapshot", 8, 1);
	}

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
	ZEPHIR_INIT_VAR(&attributeField);
	ZVAL_NULL(&attributeField);
	ZEPHIR_INIT_VAR(&bindTypes);
	array_init(&bindTypes);
	ZEPHIR_INIT_VAR(&fields);
	array_init(&fields);
	ZEPHIR_INIT_VAR(&snapshot);
	array_init(&snapshot);
	ZEPHIR_INIT_VAR(&unsetDefaultValues);
	array_init(&unsetDefaultValues);
	ZEPHIR_INIT_VAR(&value);
	ZVAL_NULL(&value);
	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	ZEPHIR_INIT_VAR(&bindSkip);
	ZVAL_LONG(&bindSkip, 1024);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1001, PH_NOISY_CC | PH_READONLY);
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
	if (Z_TYPE_P(&attributes) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_2);
		zephir_string_to_char_array(&_2, &attributes);
		_3 = &_2;
	} else {
		_3 = &attributes;
	}
	zephir_is_iterable(_3, 0, "phalcon/Mvc/Model.zep", 4262);
	if (Z_TYPE_P(_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3), _4)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _4);
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
					ZEPHIR_INIT_NVAR(&_5$$7);
					object_init_ex(&_5$$7, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
					ZEPHIR_INIT_NVAR(&_6$$7);
					zephir_get_class(&_6$$7, this_ptr, 0);
					ZEPHIR_CALL_METHOD(NULL, &_5$$7, "__construct", &_7, 0, &field, &_6$$7);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_5$$7, "phalcon/Mvc/Model.zep", 4190);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &field);
			}
			_8$$5 = !(zephir_array_key_exists(&automaticAttributes, &attributeField));
			if (_8$$5) {
				_8$$5 = !ZEPHIR_IS_EQUAL(&field, identityField);
			}
			if (_8$$5) {
				ZEPHIR_OBS_NVAR(&rawValue);
				if (zephir_array_isset_fetch(&rawValue, &rawValues, &attributeField, 0)) {
					ZEPHIR_OBS_NVAR(&bindType);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0)))) {
						ZEPHIR_INIT_NVAR(&_9$$11);
						object_init_ex(&_9$$11, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
						ZEPHIR_INIT_NVAR(&_10$$11);
						zephir_get_class(&_10$$11, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_9$$11, "__construct", &_11, 0, &field, &_10$$11);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_9$$11, "phalcon/Mvc/Model.zep", 4207);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4210);
					zephir_array_append(&values, &rawValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4211);
					zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4212);
					zephir_array_update_zval(&snapshot, &attributeField, &rawValue, PH_COPY | PH_SEPARATE);
				} else {
					ZEPHIR_OBS_NVAR(&value);
					if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
						_12$$12 = Z_TYPE_P(&value) == IS_NULL;
						if (_12$$12) {
							_12$$12 = zephir_array_key_exists(&defaultValues, &field);
						}
						if (_12$$12) {
							zephir_array_fetch(&_13$$13, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4216);
							zephir_array_update_zval(&snapshot, &attributeField, &_13$$13, PH_COPY | PH_SEPARATE);
							zephir_array_fetch(&_14$$13, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4217);
							zephir_array_update_zval(&unsetDefaultValues, &attributeField, &_14$$13, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(&_15$$13, connection, "supportsdefaultvalue", &_16, 0);
							zephir_check_call_status();
							if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_15$$13))) {
								continue;
							}
							ZEPHIR_CALL_METHOD(&value, connection, "getdefaultvalue", &_17, 0);
							zephir_check_call_status();
						} else {
							zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
						}
						ZEPHIR_OBS_NVAR(&bindType);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0)))) {
							ZEPHIR_INIT_NVAR(&_18$$16);
							object_init_ex(&_18$$16, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
							ZEPHIR_INIT_NVAR(&_19$$16);
							zephir_get_class(&_19$$16, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_18$$16, "__construct", &_11, 0, &field, &_19$$16);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_18$$16, "phalcon/Mvc/Model.zep", 4232);
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4235);
						zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4236);
						zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4237);
					} else {
						if (zephir_array_key_exists(&defaultValues, &field)) {
							zephir_array_fetch(&_20$$18, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4240);
							zephir_array_update_zval(&snapshot, &attributeField, &_20$$18, PH_COPY | PH_SEPARATE);
							zephir_array_fetch(&_21$$18, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4241);
							zephir_array_update_zval(&unsetDefaultValues, &attributeField, &_21$$18, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(&_22$$18, connection, "supportsdefaultvalue", &_23, 0);
							zephir_check_call_status();
							if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_22$$18))) {
								continue;
							}
							ZEPHIR_CALL_METHOD(&_24$$18, connection, "getdefaultvalue", &_25, 0);
							zephir_check_call_status();
							zephir_array_append(&values, &_24$$18, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4247);
						} else {
							zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4249);
							zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
						}
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4253);
						zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4254);
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _3, "rewind", NULL, 0);
		zephir_check_call_status();
		_27 = 1;
		while (1) {
			if (_27) {
				_27 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _3, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_26, _3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_26)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, _3, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
						ZEPHIR_INIT_NVAR(&_28$$23);
						object_init_ex(&_28$$23, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
						ZEPHIR_INIT_NVAR(&_29$$23);
						zephir_get_class(&_29$$23, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_28$$23, "__construct", &_7, 0, &field, &_29$$23);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_28$$23, "phalcon/Mvc/Model.zep", 4190);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &field);
				}
				_30$$21 = !(zephir_array_key_exists(&automaticAttributes, &attributeField));
				if (_30$$21) {
					_30$$21 = !ZEPHIR_IS_EQUAL(&field, identityField);
				}
				if (_30$$21) {
					ZEPHIR_OBS_NVAR(&rawValue);
					if (zephir_array_isset_fetch(&rawValue, &rawValues, &attributeField, 0)) {
						ZEPHIR_OBS_NVAR(&bindType);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0)))) {
							ZEPHIR_INIT_NVAR(&_31$$27);
							object_init_ex(&_31$$27, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
							ZEPHIR_INIT_NVAR(&_32$$27);
							zephir_get_class(&_32$$27, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_31$$27, "__construct", &_11, 0, &field, &_32$$27);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_31$$27, "phalcon/Mvc/Model.zep", 4207);
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4210);
						zephir_array_append(&values, &rawValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4211);
						zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4212);
						zephir_array_update_zval(&snapshot, &attributeField, &rawValue, PH_COPY | PH_SEPARATE);
					} else {
						ZEPHIR_OBS_NVAR(&value);
						if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
							_33$$28 = Z_TYPE_P(&value) == IS_NULL;
							if (_33$$28) {
								_33$$28 = zephir_array_key_exists(&defaultValues, &field);
							}
							if (_33$$28) {
								zephir_array_fetch(&_34$$29, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4216);
								zephir_array_update_zval(&snapshot, &attributeField, &_34$$29, PH_COPY | PH_SEPARATE);
								zephir_array_fetch(&_35$$29, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4217);
								zephir_array_update_zval(&unsetDefaultValues, &attributeField, &_35$$29, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(&_36$$29, connection, "supportsdefaultvalue", &_37, 0);
								zephir_check_call_status();
								if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_36$$29))) {
									continue;
								}
								ZEPHIR_CALL_METHOD(&value, connection, "getdefaultvalue", &_38, 0);
								zephir_check_call_status();
							} else {
								zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
							}
							ZEPHIR_OBS_NVAR(&bindType);
							if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0)))) {
								ZEPHIR_INIT_NVAR(&_39$$32);
								object_init_ex(&_39$$32, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
								ZEPHIR_INIT_NVAR(&_40$$32);
								zephir_get_class(&_40$$32, this_ptr, 0);
								ZEPHIR_CALL_METHOD(NULL, &_39$$32, "__construct", &_11, 0, &field, &_40$$32);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_39$$32, "phalcon/Mvc/Model.zep", 4232);
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4235);
							zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4236);
							zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4237);
						} else {
							if (zephir_array_key_exists(&defaultValues, &field)) {
								zephir_array_fetch(&_41$$34, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4240);
								zephir_array_update_zval(&snapshot, &attributeField, &_41$$34, PH_COPY | PH_SEPARATE);
								zephir_array_fetch(&_42$$34, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4241);
								zephir_array_update_zval(&unsetDefaultValues, &attributeField, &_42$$34, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(&_43$$34, connection, "supportsdefaultvalue", &_44, 0);
								zephir_check_call_status();
								if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_43$$34))) {
									continue;
								}
								ZEPHIR_CALL_METHOD(&_45$$34, connection, "getdefaultvalue", &_46, 0);
								zephir_check_call_status();
								zephir_array_append(&values, &_45$$34, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4247);
							} else {
								zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4249);
								zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
							}
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4253);
							zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4254);
						}
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&field);
	if (!ZEPHIR_IS_FALSE_IDENTICAL(identityField)) {
		ZEPHIR_CALL_METHOD(&defaultValue, connection, "getdefaultidvalue", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_47$$37, connection, "useexplicitidvalue", NULL, 0);
		zephir_check_call_status();
		useExplicitIdentity = zephir_get_boolval(&_47$$37);
		if (useExplicitIdentity) {
			zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4272);
		}
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&attributeField);
			if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, identityField, 0)))) {
				ZEPHIR_INIT_VAR(&_48$$40);
				object_init_ex(&_48$$40, phalcon_mvc_model_exceptions_identitynotincolumnmap_ce);
				ZEPHIR_INIT_VAR(&_49$$40);
				zephir_get_class(&_49$$40, this_ptr, 0);
				ZEPHIR_CALL_METHOD(NULL, &_48$$40, "__construct", NULL, 0, identityField, &_49$$40);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_48$$40, "phalcon/Mvc/Model.zep", 4280);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(&attributeField, identityField);
		}
		ZEPHIR_OBS_NVAR(&value);
		if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
			_50$$42 = Z_TYPE_P(&value) == IS_NULL;
			if (!(_50$$42)) {
				_50$$42 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
			}
			if (_50$$42) {
				if (useExplicitIdentity) {
					zephir_array_append(&values, &defaultValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4292);
					zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4292);
				} else if (ZEPHIR_IS_EMPTY(&values)) {
					zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4299);
					zephir_array_append(&values, &defaultValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4300);
					zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4301);
				}
			} else {
				if (!(useExplicitIdentity)) {
					zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4309);
				}
				ZEPHIR_OBS_NVAR(&bindType);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, identityField, 0)))) {
					ZEPHIR_INIT_VAR(&_51$$48);
					object_init_ex(&_51$$48, phalcon_mvc_model_exceptions_identitynotintablecolumns_ce);
					ZEPHIR_INIT_VAR(&_52$$48);
					zephir_get_class(&_52$$48, this_ptr, 0);
					ZEPHIR_CALL_METHOD(NULL, &_51$$48, "__construct", NULL, 0, identityField, &_52$$48);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_51$$48, "phalcon/Mvc/Model.zep", 4316);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4319);
				zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4320);
			}
		} else {
			if (useExplicitIdentity) {
				zephir_array_append(&values, &defaultValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4324);
				zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4325);
			} else if (ZEPHIR_IS_EMPTY(&values)) {
				zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4332);
				zephir_array_append(&values, &defaultValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4333);
				zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4334);
			}
		}
	}
	if (Z_TYPE_P(table) == IS_ARRAY) {
		zephir_array_fetch_long(&_53$$52, table, 0, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4343);
		zephir_array_fetch_long(&_54$$52, table, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4343);
		ZEPHIR_INIT_VAR(&_55$$52);
		ZEPHIR_CONCAT_VSV(&_55$$52, &_53$$52, ".", &_54$$52);
		ZEPHIR_CPY_WRT(table, &_55$$52);
	}
	ZEPHIR_CALL_METHOD(&success, connection, "insert", NULL, 0, table, &values, &fields, &bindTypes);
	zephir_check_call_status();
	_56 = zephir_is_true(&success);
	if (_56) {
		_56 = !ZEPHIR_IS_FALSE_IDENTICAL(identityField);
	}
	if (_56) {
		ZEPHIR_INIT_VAR(&sequenceName);
		ZVAL_NULL(&sequenceName);
		ZEPHIR_CALL_METHOD(&_57$$53, connection, "supportsequences", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_57$$53)) {
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
		_58$$53 = Z_TYPE_P(&value) != IS_NULL;
		if (_58$$53) {
			_58$$53 = !ZEPHIR_IS_STRING_IDENTICAL(&value, "");
		}
		if (_58$$53) {
			ZEPHIR_CPY_WRT(&lastInsertedId, &value);
		} else {
			ZEPHIR_CALL_METHOD(&lastInsertedId, connection, "lastinsertid", NULL, 0, &sequenceName);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(&_60$$53);
		ZVAL_STRING(&_60$$53, "orm.cast_last_insert_id_to_int");
		ZEPHIR_CALL_CE_STATIC(&_59$$53, phalcon_support_settings_ce, "get", NULL, 0, &_60$$53);
		zephir_check_call_status();
		if (UNEXPECTED(zephir_is_true(&_59$$53))) {
			ZVAL_LONG(&_61$$61, 10);
			ZEPHIR_CALL_FUNCTION(&_62$$61, "intval", NULL, 96, &lastInsertedId, &_61$$61);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&lastInsertedId, &_62$$61);
		}
		zephir_update_property_zval_zval(this_ptr, &attributeField, &lastInsertedId);
		zephir_array_update_zval(&snapshot, &attributeField, &lastInsertedId, PH_COPY | PH_SEPARATE);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1008, &__$null);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1009, &__$null);
	}
	if (zephir_is_true(&success)) {
		ZEPHIR_CALL_METHOD(NULL, &manager, "registerwrite", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (Z_TYPE_P(&unsetDefaultValues) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_64$$62);
			zephir_string_to_char_array(&_64$$62, &unsetDefaultValues);
			_63$$62 = &_64$$62;
		} else {
			_63$$62 = &unsetDefaultValues;
		}
		zephir_is_iterable(_63$$62, 0, "phalcon/Mvc/Model.zep", 4422);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_63$$62), _66$$62, _67$$62, _65$$62)
		{
			ZEPHIR_INIT_NVAR(&attributeField);
			if (_67$$62 != NULL) { 
				ZVAL_STR_COPY(&attributeField, _67$$62);
			} else {
				ZVAL_LONG(&attributeField, _66$$62);
			}
			ZEPHIR_INIT_NVAR(&defaultValue);
			ZVAL_COPY(&defaultValue, _65$$62);
			zephir_update_property_zval_zval(this_ptr, &attributeField, &defaultValue);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&defaultValue);
		ZEPHIR_INIT_NVAR(&attributeField);
		ZEPHIR_CALL_METHOD(&_68$$62, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		_69$$62 = zephir_is_true(&_68$$62);
		if (_69$$62) {
			ZEPHIR_INIT_VAR(&_71$$62);
			ZVAL_STRING(&_71$$62, "orm.update_snapshot_on_save");
			ZEPHIR_CALL_CE_STATIC(&_70$$62, phalcon_support_settings_ce, "get", NULL, 0, &_71$$62);
			zephir_check_call_status();
			_69$$62 = zephir_is_true(&_70$$62);
		}
		if (_69$$62) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1000, &snapshot);
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
	zval _25$$26, _26$$26, _42$$50, _43$$50;
	zval _83;
	zend_bool changed = 0, useDynamicUpdate = 0, _3, _85, _87, _28$$5, _19$$20, _21$$20, _37$$44, _39$$44, _58$$55, _53$$64, _54$$64, _56$$64, _65$$75, _66$$75, _68$$75, _77$$79;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_12 = NULL, *_15 = NULL, *_18 = NULL, *_23 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *metaData, metaData_sub, *connection, connection_sub, *table = NULL, table_sub, __$null, automaticAttributes, attributeField, bindSkip, bindDataTypes, bindType, bindTypes, columnMap, dataType, dataTypes, defaultValues, field, fields, manager, nonPrimary, newSnapshot, rawValue, rawValues, success, primaryKeys, snapshot, snapshotValue, uniqueKey, uniqueParams, value, values, updateValue, _0, _1, _2, _84, _86, _88, *_4$$5, _5$$5, *_6$$5, _27$$5, _7$$8, _9$$8, _10$$9, _11$$9, _13$$12, _14$$12, _16$$21, _17$$21, _20$$22, _22$$25, _24$$25, _29$$32, _30$$32, _31$$33, _32$$33, _33$$36, _34$$36, _35$$45, _36$$45, _38$$46, _40$$49, _41$$49, *_44$$55, _45$$55, *_46$$55, _57$$55, _47$$58, _48$$58, _49$$59, _50$$59, _51$$62, _52$$62, _55$$64, _59$$69, _60$$69, _61$$70, _62$$70, _63$$73, _64$$73, _67$$75, _69$$80, _70$$80, *_71$$79, _72$$79, *_73$$79, _76$$79, _74$$83, _75$$83, _78$$89, _79$$89, _80$$93, _81$$93, _82$$93, _89$$96, _90$$97;
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
	ZVAL_UNDEF(&_84);
	ZVAL_UNDEF(&_86);
	ZVAL_UNDEF(&_88);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_27$$5);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_16$$21);
	ZVAL_UNDEF(&_17$$21);
	ZVAL_UNDEF(&_20$$22);
	ZVAL_UNDEF(&_22$$25);
	ZVAL_UNDEF(&_24$$25);
	ZVAL_UNDEF(&_29$$32);
	ZVAL_UNDEF(&_30$$32);
	ZVAL_UNDEF(&_31$$33);
	ZVAL_UNDEF(&_32$$33);
	ZVAL_UNDEF(&_33$$36);
	ZVAL_UNDEF(&_34$$36);
	ZVAL_UNDEF(&_35$$45);
	ZVAL_UNDEF(&_36$$45);
	ZVAL_UNDEF(&_38$$46);
	ZVAL_UNDEF(&_40$$49);
	ZVAL_UNDEF(&_41$$49);
	ZVAL_UNDEF(&_45$$55);
	ZVAL_UNDEF(&_57$$55);
	ZVAL_UNDEF(&_47$$58);
	ZVAL_UNDEF(&_48$$58);
	ZVAL_UNDEF(&_49$$59);
	ZVAL_UNDEF(&_50$$59);
	ZVAL_UNDEF(&_51$$62);
	ZVAL_UNDEF(&_52$$62);
	ZVAL_UNDEF(&_55$$64);
	ZVAL_UNDEF(&_59$$69);
	ZVAL_UNDEF(&_60$$69);
	ZVAL_UNDEF(&_61$$70);
	ZVAL_UNDEF(&_62$$70);
	ZVAL_UNDEF(&_63$$73);
	ZVAL_UNDEF(&_64$$73);
	ZVAL_UNDEF(&_67$$75);
	ZVAL_UNDEF(&_69$$80);
	ZVAL_UNDEF(&_70$$80);
	ZVAL_UNDEF(&_72$$79);
	ZVAL_UNDEF(&_76$$79);
	ZVAL_UNDEF(&_74$$83);
	ZVAL_UNDEF(&_75$$83);
	ZVAL_UNDEF(&_78$$89);
	ZVAL_UNDEF(&_79$$89);
	ZVAL_UNDEF(&_80$$93);
	ZVAL_UNDEF(&_81$$93);
	ZVAL_UNDEF(&_82$$93);
	ZVAL_UNDEF(&_89$$96);
	ZVAL_UNDEF(&_90$$97);
	ZVAL_UNDEF(&_83);
	ZVAL_UNDEF(&_25$$26);
	ZVAL_UNDEF(&_26$$26);
	ZVAL_UNDEF(&_42$$50);
	ZVAL_UNDEF(&_43$$50);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("rawValues", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("modelsManager", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("snapshot", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("oldSnapshot", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("uniqueKey", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("uniqueParams", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("uniqueTypes", 11, 1);
	}

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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1001, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&rawValues, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 996, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&_1, &manager, "isusingdynamicupdate", NULL, 0, this_ptr);
	zephir_check_call_status();
	useDynamicUpdate = zephir_get_boolval(&_1);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 1000, PH_NOISY_CC | PH_READONLY);
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
		if (Z_TYPE_P(&nonPrimary) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_5$$5);
			zephir_string_to_char_array(&_5$$5, &nonPrimary);
			_4$$5 = &_5$$5;
		} else {
			_4$$5 = &nonPrimary;
		}
		zephir_is_iterable(_4$$5, 0, "phalcon/Mvc/Model.zep", 4582);
		if (Z_TYPE_P(_4$$5) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_4$$5), _6$$5)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _6$$5);
				changed = 0;
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
						ZEPHIR_INIT_NVAR(&_9$$8);
						ZVAL_STRING(&_9$$8, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_7$$8, phalcon_support_settings_ce, "get", &_8, 0, &_9$$8);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_7$$8))) {
							ZEPHIR_INIT_NVAR(&_10$$9);
							object_init_ex(&_10$$9, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
							ZEPHIR_INIT_NVAR(&_11$$9);
							zephir_get_class(&_11$$9, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_10$$9, "__construct", &_12, 0, &field, &_11$$9);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_10$$9, "phalcon/Mvc/Model.zep", 4476);
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &field);
				}
				if (!(zephir_array_key_exists(&automaticAttributes, &attributeField))) {
					ZEPHIR_OBS_NVAR(&bindType);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0)))) {
						ZEPHIR_INIT_NVAR(&_13$$12);
						object_init_ex(&_13$$12, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
						ZEPHIR_INIT_NVAR(&_14$$12);
						zephir_get_class(&_14$$12, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_13$$12, "__construct", &_15, 0, &field, &_14$$12);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_13$$12, "phalcon/Mvc/Model.zep", 4487);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&rawValue);
					if (zephir_array_isset_fetch(&rawValue, &rawValues, &attributeField, 0)) {
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4494);
						zephir_array_append(&values, &rawValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4495);
						zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4496);
						zephir_array_update_zval(&newSnapshot, &attributeField, &rawValue, PH_COPY | PH_SEPARATE);
					} else {
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
											ZEPHIR_INIT_NVAR(&_16$$21);
											object_init_ex(&_16$$21, phalcon_mvc_model_exceptions_datatypenotdefined_ce);
											ZEPHIR_INIT_NVAR(&_17$$21);
											zephir_get_class(&_17$$21, this_ptr, 0);
											ZEPHIR_CALL_METHOD(NULL, &_16$$21, "__construct", &_18, 0, &field, &_17$$21);
											zephir_check_call_status();
											zephir_throw_exception_debug(&_16$$21, "phalcon/Mvc/Model.zep", 4520);
											ZEPHIR_MM_RESTORE();
											return;
										}
										_19$$20 = Z_TYPE_P(&snapshotValue) == IS_OBJECT;
										if (_19$$20) {
											_19$$20 = zephir_instance_of_ev(&snapshotValue, phalcon_db_rawvalue_ce);
										}
										if (_19$$20) {
											ZEPHIR_CALL_METHOD(&_20$$22, &snapshotValue, "getvalue", NULL, 0);
											zephir_check_call_status();
											ZEPHIR_CPY_WRT(&snapshotValue, &_20$$22);
										}
										ZEPHIR_CPY_WRT(&updateValue, &value);
										_21$$20 = Z_TYPE_P(&value) == IS_OBJECT;
										if (_21$$20) {
											_21$$20 = zephir_instance_of_ev(&value, phalcon_db_rawvalue_ce);
										}
										if (_21$$20) {
											ZEPHIR_CALL_METHOD(&updateValue, &value, "getvalue", NULL, 0);
											zephir_check_call_status();
										}
										if (ZEPHIR_IS_LONG(&dataType, 8)) { goto zephir_switch_0_clause_0; }
										if (ZEPHIR_IS_LONG(&dataType, 3)) { goto zephir_switch_0_clause_1; }
										if (ZEPHIR_IS_LONG(&dataType, 7)) { goto zephir_switch_0_clause_2; }
										if (ZEPHIR_IS_LONG(&dataType, 0)) { goto zephir_switch_0_clause_3; }
										if (ZEPHIR_IS_LONG(&dataType, 1)) { goto zephir_switch_0_clause_4; }
										if (ZEPHIR_IS_LONG(&dataType, 4)) { goto zephir_switch_0_clause_5; }
										if (ZEPHIR_IS_LONG(&dataType, 5)) { goto zephir_switch_0_clause_6; }
										if (ZEPHIR_IS_LONG(&dataType, 6)) { goto zephir_switch_0_clause_7; }
										if (ZEPHIR_IS_LONG(&dataType, 2)) { goto zephir_switch_0_clause_8; }
										if (ZEPHIR_IS_LONG(&dataType, 14)) { goto zephir_switch_0_clause_9; }
										goto zephir_switch_0_clause_10;
										zephir_switch_0_clause_0: ;
											changed = zephir_get_boolval(&snapshotValue) != zephir_get_boolval(&updateValue);
											goto zephir_switch_0_end;
										zephir_switch_0_clause_1: ;
										zephir_switch_0_clause_2: ;
											ZEPHIR_CALL_FUNCTION(&_22$$25, "floatval", &_23, 33, &snapshotValue);
											zephir_check_call_status();
											ZEPHIR_CALL_FUNCTION(&_24$$25, "floatval", &_23, 33, &updateValue);
											zephir_check_call_status();
											changed = !ZEPHIR_IS_IDENTICAL(&_22$$25, &_24$$25);
											goto zephir_switch_0_end;
										zephir_switch_0_clause_3: ;
										zephir_switch_0_clause_4: ;
										zephir_switch_0_clause_5: ;
										zephir_switch_0_clause_6: ;
										zephir_switch_0_clause_7: ;
										zephir_switch_0_clause_8: ;
										zephir_switch_0_clause_9: ;
											zephir_cast_to_string(&_25$$26, &snapshotValue);
											zephir_cast_to_string(&_26$$26, &updateValue);
											changed = !ZEPHIR_IS_IDENTICAL(&_25$$26, &_26$$26);
											goto zephir_switch_0_end;
										zephir_switch_0_clause_10: ;
											changed = !ZEPHIR_IS_EQUAL(&updateValue, &snapshotValue);
										zephir_switch_0_end: ;

									}
								}
							}
							if (changed) {
								zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4569);
								zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4570);
								zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4571);
							}
							zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
						} else {
							zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
						}
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _4$$5, "rewind", NULL, 0);
			zephir_check_call_status();
			_28$$5 = 1;
			while (1) {
				if (_28$$5) {
					_28$$5 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _4$$5, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_27$$5, _4$$5, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_27$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, _4$$5, "current", NULL, 0);
				zephir_check_call_status();
					changed = 0;
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
							ZEPHIR_INIT_NVAR(&_30$$32);
							ZVAL_STRING(&_30$$32, "orm.ignore_unknown_columns");
							ZEPHIR_CALL_CE_STATIC(&_29$$32, phalcon_support_settings_ce, "get", &_8, 0, &_30$$32);
							zephir_check_call_status();
							if (UNEXPECTED(!zephir_is_true(&_29$$32))) {
								ZEPHIR_INIT_NVAR(&_31$$33);
								object_init_ex(&_31$$33, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
								ZEPHIR_INIT_NVAR(&_32$$33);
								zephir_get_class(&_32$$33, this_ptr, 0);
								ZEPHIR_CALL_METHOD(NULL, &_31$$33, "__construct", &_12, 0, &field, &_32$$33);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_31$$33, "phalcon/Mvc/Model.zep", 4476);
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} else {
						ZEPHIR_CPY_WRT(&attributeField, &field);
					}
					if (!(zephir_array_key_exists(&automaticAttributes, &attributeField))) {
						ZEPHIR_OBS_NVAR(&bindType);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0)))) {
							ZEPHIR_INIT_NVAR(&_33$$36);
							object_init_ex(&_33$$36, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
							ZEPHIR_INIT_NVAR(&_34$$36);
							zephir_get_class(&_34$$36, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_33$$36, "__construct", &_15, 0, &field, &_34$$36);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_33$$36, "phalcon/Mvc/Model.zep", 4487);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_OBS_NVAR(&rawValue);
						if (zephir_array_isset_fetch(&rawValue, &rawValues, &attributeField, 0)) {
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4494);
							zephir_array_append(&values, &rawValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4495);
							zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4496);
							zephir_array_update_zval(&newSnapshot, &attributeField, &rawValue, PH_COPY | PH_SEPARATE);
						} else {
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
												ZEPHIR_INIT_NVAR(&_35$$45);
												object_init_ex(&_35$$45, phalcon_mvc_model_exceptions_datatypenotdefined_ce);
												ZEPHIR_INIT_NVAR(&_36$$45);
												zephir_get_class(&_36$$45, this_ptr, 0);
												ZEPHIR_CALL_METHOD(NULL, &_35$$45, "__construct", &_18, 0, &field, &_36$$45);
												zephir_check_call_status();
												zephir_throw_exception_debug(&_35$$45, "phalcon/Mvc/Model.zep", 4520);
												ZEPHIR_MM_RESTORE();
												return;
											}
											_37$$44 = Z_TYPE_P(&snapshotValue) == IS_OBJECT;
											if (_37$$44) {
												_37$$44 = zephir_instance_of_ev(&snapshotValue, phalcon_db_rawvalue_ce);
											}
											if (_37$$44) {
												ZEPHIR_CALL_METHOD(&_38$$46, &snapshotValue, "getvalue", NULL, 0);
												zephir_check_call_status();
												ZEPHIR_CPY_WRT(&snapshotValue, &_38$$46);
											}
											ZEPHIR_CPY_WRT(&updateValue, &value);
											_39$$44 = Z_TYPE_P(&value) == IS_OBJECT;
											if (_39$$44) {
												_39$$44 = zephir_instance_of_ev(&value, phalcon_db_rawvalue_ce);
											}
											if (_39$$44) {
												ZEPHIR_CALL_METHOD(&updateValue, &value, "getvalue", NULL, 0);
												zephir_check_call_status();
											}
											if (ZEPHIR_IS_LONG(&dataType, 8)) { goto zephir_switch_1_clause_0; }
											if (ZEPHIR_IS_LONG(&dataType, 3)) { goto zephir_switch_1_clause_1; }
											if (ZEPHIR_IS_LONG(&dataType, 7)) { goto zephir_switch_1_clause_2; }
											if (ZEPHIR_IS_LONG(&dataType, 0)) { goto zephir_switch_1_clause_3; }
											if (ZEPHIR_IS_LONG(&dataType, 1)) { goto zephir_switch_1_clause_4; }
											if (ZEPHIR_IS_LONG(&dataType, 4)) { goto zephir_switch_1_clause_5; }
											if (ZEPHIR_IS_LONG(&dataType, 5)) { goto zephir_switch_1_clause_6; }
											if (ZEPHIR_IS_LONG(&dataType, 6)) { goto zephir_switch_1_clause_7; }
											if (ZEPHIR_IS_LONG(&dataType, 2)) { goto zephir_switch_1_clause_8; }
											if (ZEPHIR_IS_LONG(&dataType, 14)) { goto zephir_switch_1_clause_9; }
											goto zephir_switch_1_clause_10;
											zephir_switch_1_clause_0: ;
												changed = zephir_get_boolval(&snapshotValue) != zephir_get_boolval(&updateValue);
												goto zephir_switch_1_end;
											zephir_switch_1_clause_1: ;
											zephir_switch_1_clause_2: ;
												ZEPHIR_CALL_FUNCTION(&_40$$49, "floatval", &_23, 33, &snapshotValue);
												zephir_check_call_status();
												ZEPHIR_CALL_FUNCTION(&_41$$49, "floatval", &_23, 33, &updateValue);
												zephir_check_call_status();
												changed = !ZEPHIR_IS_IDENTICAL(&_40$$49, &_41$$49);
												goto zephir_switch_1_end;
											zephir_switch_1_clause_3: ;
											zephir_switch_1_clause_4: ;
											zephir_switch_1_clause_5: ;
											zephir_switch_1_clause_6: ;
											zephir_switch_1_clause_7: ;
											zephir_switch_1_clause_8: ;
											zephir_switch_1_clause_9: ;
												zephir_cast_to_string(&_42$$50, &snapshotValue);
												zephir_cast_to_string(&_43$$50, &updateValue);
												changed = !ZEPHIR_IS_IDENTICAL(&_42$$50, &_43$$50);
												goto zephir_switch_1_end;
											zephir_switch_1_clause_10: ;
												changed = !ZEPHIR_IS_EQUAL(&updateValue, &snapshotValue);
											zephir_switch_1_end: ;

										}
									}
								}
								if (changed) {
									zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4569);
									zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4570);
									zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4571);
								}
								zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
							} else {
								zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
							}
						}
					}
			}
		}
		ZEPHIR_INIT_NVAR(&field);
		if (ZEPHIR_IS_EMPTY(&fields)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1007, &snapshot);
			RETURN_MM_BOOL(1);
		}
	} else {
		if (Z_TYPE_P(&nonPrimary) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_45$$55);
			zephir_string_to_char_array(&_45$$55, &nonPrimary);
			_44$$55 = &_45$$55;
		} else {
			_44$$55 = &nonPrimary;
		}
		zephir_is_iterable(_44$$55, 0, "phalcon/Mvc/Model.zep", 4647);
		if (Z_TYPE_P(_44$$55) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_44$$55), _46$$55)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _46$$55);
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
						ZEPHIR_INIT_NVAR(&_48$$58);
						ZVAL_STRING(&_48$$58, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_47$$58, phalcon_support_settings_ce, "get", &_8, 0, &_48$$58);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_47$$58))) {
							ZEPHIR_INIT_NVAR(&_49$$59);
							object_init_ex(&_49$$59, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
							ZEPHIR_INIT_NVAR(&_50$$59);
							zephir_get_class(&_50$$59, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_49$$59, "__construct", &_12, 0, &field, &_50$$59);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_49$$59, "phalcon/Mvc/Model.zep", 4598);
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &field);
				}
				if (!(zephir_array_key_exists(&automaticAttributes, &attributeField))) {
					ZEPHIR_OBS_NVAR(&bindType);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0)))) {
						ZEPHIR_INIT_NVAR(&_51$$62);
						object_init_ex(&_51$$62, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
						ZEPHIR_INIT_NVAR(&_52$$62);
						zephir_get_class(&_52$$62, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_51$$62, "__construct", &_15, 0, &field, &_52$$62);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_51$$62, "phalcon/Mvc/Model.zep", 4610);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&rawValue);
					if (zephir_array_isset_fetch(&rawValue, &rawValues, &attributeField, 0)) {
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4618);
						zephir_array_append(&values, &rawValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4619);
						zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4620);
						zephir_array_update_zval(&newSnapshot, &attributeField, &rawValue, PH_COPY | PH_SEPARATE);
					} else {
						ZEPHIR_OBS_NVAR(&value);
						if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
							_53$$64 = Z_TYPE_P(&value) == IS_STRING;
							if (_53$$64) {
								_53$$64 = zephir_array_isset_value(&defaultValues, &field);
							}
							_54$$64 = _53$$64;
							if (_54$$64) {
								zephir_array_fetch(&_55$$64, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4629);
								_54$$64 = ZEPHIR_IS_IDENTICAL(&value, &_55$$64);
							}
							_56$$64 = _54$$64;
							if (_56$$64) {
								_56$$64 = zephir_memnstr_str(&value, SL("("), "phalcon/Mvc/Model.zep", 4629);
							}
							if (_56$$64) {
								zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
								continue;
							}
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4635);
							zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4636);
							zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4637);
							zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
						} else {
							zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4641);
							zephir_array_append(&values, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4642);
							zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4643);
						}
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _44$$55, "rewind", NULL, 0);
			zephir_check_call_status();
			_58$$55 = 1;
			while (1) {
				if (_58$$55) {
					_58$$55 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _44$$55, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_57$$55, _44$$55, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_57$$55)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, _44$$55, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
							ZEPHIR_INIT_NVAR(&_60$$69);
							ZVAL_STRING(&_60$$69, "orm.ignore_unknown_columns");
							ZEPHIR_CALL_CE_STATIC(&_59$$69, phalcon_support_settings_ce, "get", &_8, 0, &_60$$69);
							zephir_check_call_status();
							if (UNEXPECTED(!zephir_is_true(&_59$$69))) {
								ZEPHIR_INIT_NVAR(&_61$$70);
								object_init_ex(&_61$$70, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
								ZEPHIR_INIT_NVAR(&_62$$70);
								zephir_get_class(&_62$$70, this_ptr, 0);
								ZEPHIR_CALL_METHOD(NULL, &_61$$70, "__construct", &_12, 0, &field, &_62$$70);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_61$$70, "phalcon/Mvc/Model.zep", 4598);
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} else {
						ZEPHIR_CPY_WRT(&attributeField, &field);
					}
					if (!(zephir_array_key_exists(&automaticAttributes, &attributeField))) {
						ZEPHIR_OBS_NVAR(&bindType);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0)))) {
							ZEPHIR_INIT_NVAR(&_63$$73);
							object_init_ex(&_63$$73, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
							ZEPHIR_INIT_NVAR(&_64$$73);
							zephir_get_class(&_64$$73, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_63$$73, "__construct", &_15, 0, &field, &_64$$73);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_63$$73, "phalcon/Mvc/Model.zep", 4610);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_OBS_NVAR(&rawValue);
						if (zephir_array_isset_fetch(&rawValue, &rawValues, &attributeField, 0)) {
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4618);
							zephir_array_append(&values, &rawValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4619);
							zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4620);
							zephir_array_update_zval(&newSnapshot, &attributeField, &rawValue, PH_COPY | PH_SEPARATE);
						} else {
							ZEPHIR_OBS_NVAR(&value);
							if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
								_65$$75 = Z_TYPE_P(&value) == IS_STRING;
								if (_65$$75) {
									_65$$75 = zephir_array_isset_value(&defaultValues, &field);
								}
								_66$$75 = _65$$75;
								if (_66$$75) {
									zephir_array_fetch(&_67$$75, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4629);
									_66$$75 = ZEPHIR_IS_IDENTICAL(&value, &_67$$75);
								}
								_68$$75 = _66$$75;
								if (_68$$75) {
									_68$$75 = zephir_memnstr_str(&value, SL("("), "phalcon/Mvc/Model.zep", 4629);
								}
								if (_68$$75) {
									zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
									continue;
								}
								zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4635);
								zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4636);
								zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4637);
								zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
							} else {
								zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
								zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4641);
								zephir_array_append(&values, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4642);
								zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4643);
							}
						}
					}
			}
		}
		ZEPHIR_INIT_NVAR(&field);
	}
	if (ZEPHIR_IS_EMPTY(&fields)) {
		RETURN_MM_BOOL(1);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_4, 1008, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueKey, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_5, 1009, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueParams, &_0);
	if (Z_TYPE_P(&uniqueParams) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&primaryKeys, metaData, "getprimarykeyattributes", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (UNEXPECTED(ZEPHIR_IS_EMPTY(&primaryKeys))) {
			ZEPHIR_INIT_VAR(&_69$$80);
			object_init_ex(&_69$$80, phalcon_mvc_model_exceptions_primarykeyrequired_ce);
			ZEPHIR_INIT_VAR(&_70$$80);
			zephir_get_class(&_70$$80, this_ptr, 0);
			ZEPHIR_CALL_METHOD(NULL, &_69$$80, "__construct", NULL, 0, &_70$$80);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_69$$80, "phalcon/Mvc/Model.zep", 4668);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&uniqueParams);
		array_init(&uniqueParams);
		if (Z_TYPE_P(&primaryKeys) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_72$$79);
			zephir_string_to_char_array(&_72$$79, &primaryKeys);
			_71$$79 = &_72$$79;
		} else {
			_71$$79 = &primaryKeys;
		}
		zephir_is_iterable(_71$$79, 0, "phalcon/Mvc/Model.zep", 4693);
		if (Z_TYPE_P(_71$$79) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_71$$79), _73$$79)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _73$$79);
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
						ZEPHIR_INIT_NVAR(&_74$$83);
						object_init_ex(&_74$$83, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
						ZEPHIR_INIT_NVAR(&_75$$83);
						zephir_get_class(&_75$$83, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_74$$83, "__construct", &_12, 0, &field, &_75$$83);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_74$$83, "phalcon/Mvc/Model.zep", 4679);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &field);
				}
				ZEPHIR_OBS_NVAR(&value);
				if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
					zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
					zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4687);
				} else {
					zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
					zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4690);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _71$$79, "rewind", NULL, 0);
			zephir_check_call_status();
			_77$$79 = 1;
			while (1) {
				if (_77$$79) {
					_77$$79 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _71$$79, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_76$$79, _71$$79, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_76$$79)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, _71$$79, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
							ZEPHIR_INIT_NVAR(&_78$$89);
							object_init_ex(&_78$$89, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
							ZEPHIR_INIT_NVAR(&_79$$89);
							zephir_get_class(&_79$$89, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_78$$89, "__construct", &_12, 0, &field, &_79$$89);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_78$$89, "phalcon/Mvc/Model.zep", 4679);
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_CPY_WRT(&attributeField, &field);
					}
					ZEPHIR_OBS_NVAR(&value);
					if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
						zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
						zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4687);
					} else {
						zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
						zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4690);
					}
			}
		}
		ZEPHIR_INIT_NVAR(&field);
	}
	if (Z_TYPE_P(table) == IS_ARRAY) {
		zephir_array_fetch_long(&_80$$93, table, 0, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4699);
		zephir_array_fetch_long(&_81$$93, table, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4699);
		ZEPHIR_INIT_VAR(&_82$$93);
		ZEPHIR_CONCAT_VSV(&_82$$93, &_80$$93, ".", &_81$$93);
		ZEPHIR_CPY_WRT(table, &_82$$93);
	}
	ZEPHIR_INIT_VAR(&_83);
	zephir_create_array(&_83, 3, 0);
	zephir_array_update_string(&_83, SL("conditions"), &uniqueKey, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_83, SL("bind"), &uniqueParams, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&_84);
	zephir_read_property_cached(&_84, this_ptr, _zephir_prop_6, 1010, PH_NOISY_CC);
	zephir_array_update_string(&_83, SL("bindTypes"), &_84, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&success, connection, "update", NULL, 0, table, &fields, &values, &_83, &bindTypes);
	zephir_check_call_status();
	if (zephir_is_true(&success)) {
		ZEPHIR_CALL_METHOD(NULL, &manager, "registerwrite", NULL, 0, this_ptr);
		zephir_check_call_status();
	}
	_85 = zephir_is_true(&success);
	if (_85) {
		ZEPHIR_CALL_METHOD(&_86, &manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		_85 = zephir_is_true(&_86);
	}
	_87 = _85;
	if (_87) {
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_STRING(&_2, "orm.update_snapshot_on_save");
		ZEPHIR_CALL_CE_STATIC(&_88, phalcon_support_settings_ce, "get", &_8, 0, &_2);
		zephir_check_call_status();
		_87 = zephir_is_true(&_88);
	}
	if (_87) {
		if (Z_TYPE_P(&snapshot) == IS_ARRAY) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1007, &snapshot);
			ZEPHIR_INIT_VAR(&_89$$96);
			zephir_fast_array_merge(&_89$$96, &snapshot, &newSnapshot);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1000, &_89$$96);
		} else {
			ZEPHIR_INIT_VAR(&_90$$97);
			array_init(&_90$$97);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1007, &_90$$97);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1000, &newSnapshot);
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
	zend_bool _16$$3, _8$$11, _19$$19;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_11 = NULL, *_13 = NULL, *_23 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberEmpty = 0, numberPrimary = 0;
	zval *metaData, metaData_sub, *connection, connection_sub, __$null, attributeField, bindDataTypes, columnMap, field, joinWhere, num, primaryKeys, schema, source, table, type, uniqueKey, uniqueParams, uniqueTypes, value, wherePk, _0, _28, _29, _30, _31, _1$$3, _2$$3, *_3$$3, *_4$$3, _15$$3, _5$$9, _6$$9, _9$$14, _10$$14, _12$$7, _14$$7, _17$$17, _18$$17, _20$$22, _21$$22, _22$$15, _24$$15, _25$$25, _26$$26, _27$$27, _32$$30, _33$$31;
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
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_9$$14);
	ZVAL_UNDEF(&_10$$14);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_17$$17);
	ZVAL_UNDEF(&_18$$17);
	ZVAL_UNDEF(&_20$$22);
	ZVAL_UNDEF(&_21$$22);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_25$$25);
	ZVAL_UNDEF(&_26$$26);
	ZVAL_UNDEF(&_27$$27);
	ZVAL_UNDEF(&_32$$30);
	ZVAL_UNDEF(&_33$$31);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("uniqueKey", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("uniqueParams", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("uniqueTypes", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("dirtyState", 10, 1);
	}

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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1008, PH_NOISY_CC | PH_READONLY);
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
		if (Z_TYPE_P(&primaryKeys) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&_2$$3);
			zephir_string_to_char_array(&_2$$3, &primaryKeys);
			_3$$3 = &_2$$3;
		} else {
			_3$$3 = &primaryKeys;
		}
		zephir_is_iterable(_3$$3, 0, "phalcon/Mvc/Model.zep", 4827);
		if (Z_TYPE_P(_3$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3$$3), _4$$3)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _4$$3);
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
						ZEPHIR_INIT_NVAR(&_5$$9);
						object_init_ex(&_5$$9, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
						ZEPHIR_INIT_NVAR(&_6$$9);
						zephir_get_class(&_6$$9, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_5$$9, "__construct", &_7, 0, &field, &_6$$9);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_5$$9, "phalcon/Mvc/Model.zep", 4788);
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
					_8$$11 = Z_TYPE_P(&value) == IS_NULL;
					if (!(_8$$11)) {
						_8$$11 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
					}
					if (_8$$11) {
						numberEmpty++;
					}
					zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4809);
				} else {
					zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4811);
					numberEmpty++;
				}
				ZEPHIR_OBS_NVAR(&type);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&type, &bindDataTypes, &field, 0)))) {
					ZEPHIR_INIT_NVAR(&_9$$14);
					object_init_ex(&_9$$14, phalcon_mvc_model_exceptions_columnnotintablecolumns_ce);
					ZEPHIR_INIT_NVAR(&_10$$14);
					zephir_get_class(&_10$$14, this_ptr, 0);
					ZEPHIR_CALL_METHOD(NULL, &_9$$14, "__construct", &_11, 0, &field, &_10$$14);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_9$$14, "phalcon/Mvc/Model.zep", 4816);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&uniqueTypes, &type, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4819);
				ZEPHIR_CALL_METHOD(&_12$$7, connection, "escapeidentifier", &_13, 0, &field);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_14$$7);
				ZEPHIR_CONCAT_VS(&_14$$7, &_12$$7, " = ?");
				zephir_array_append(&wherePk, &_14$$7, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4820);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _3$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			_16$$3 = 1;
			while (1) {
				if (_16$$3) {
					_16$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _3$$3, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_15$$3, _3$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_15$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, _3$$3, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
							ZEPHIR_INIT_NVAR(&_17$$17);
							object_init_ex(&_17$$17, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
							ZEPHIR_INIT_NVAR(&_18$$17);
							zephir_get_class(&_18$$17, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_17$$17, "__construct", &_7, 0, &field, &_18$$17);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_17$$17, "phalcon/Mvc/Model.zep", 4788);
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
						_19$$19 = Z_TYPE_P(&value) == IS_NULL;
						if (!(_19$$19)) {
							_19$$19 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
						}
						if (_19$$19) {
							numberEmpty++;
						}
						zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4809);
					} else {
						zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4811);
						numberEmpty++;
					}
					ZEPHIR_OBS_NVAR(&type);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&type, &bindDataTypes, &field, 0)))) {
						ZEPHIR_INIT_NVAR(&_20$$22);
						object_init_ex(&_20$$22, phalcon_mvc_model_exceptions_columnnotintablecolumns_ce);
						ZEPHIR_INIT_NVAR(&_21$$22);
						zephir_get_class(&_21$$22, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_20$$22, "__construct", &_11, 0, &field, &_21$$22);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_20$$22, "phalcon/Mvc/Model.zep", 4816);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&uniqueTypes, &type, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4819);
					ZEPHIR_CALL_METHOD(&_22$$15, connection, "escapeidentifier", &_23, 0, &field);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_24$$15);
					ZEPHIR_CONCAT_VS(&_24$$15, &_22$$15, " = ?");
					zephir_array_append(&wherePk, &_24$$15, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4820);
			}
		}
		ZEPHIR_INIT_NVAR(&field);
		if (numberPrimary == numberEmpty) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(&joinWhere);
		zephir_fast_join_str(&joinWhere, SL(" AND "), &wherePk);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1008, &joinWhere);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1009, &uniqueParams);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1010, &uniqueTypes);
		ZEPHIR_CPY_WRT(&uniqueKey, &joinWhere);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_3, 999, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_BOOL(1);
	}
	if (Z_TYPE_P(&uniqueKey) == IS_NULL) {
		zephir_read_property_cached(&_25$$25, this_ptr, _zephir_prop_0, 1008, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&uniqueKey, &_25$$25);
	}
	if (Z_TYPE_P(&uniqueParams) == IS_NULL) {
		zephir_read_property_cached(&_26$$26, this_ptr, _zephir_prop_1, 1009, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&uniqueParams, &_26$$26);
	}
	if (Z_TYPE_P(&uniqueTypes) == IS_NULL) {
		zephir_read_property_cached(&_27$$27, this_ptr, _zephir_prop_2, 1010, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&uniqueTypes, &_27$$27);
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
	ZEPHIR_CALL_METHOD(&_28, connection, "escapeidentifier", NULL, 0, &table);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_29);
	ZEPHIR_CONCAT_SVSV(&_29, "SELECT COUNT(*) \"rowcount\" FROM ", &_28, " WHERE ", &uniqueKey);
	ZVAL_NULL(&_30);
	ZEPHIR_CALL_METHOD(&num, connection, "fetchone", NULL, 0, &_29, &_30, &uniqueParams, &uniqueTypes);
	zephir_check_call_status();
	zephir_array_fetch_string(&_31, &num, SL("rowcount"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 4881);
	if (zephir_is_true(&_31)) {
		ZVAL_UNDEF(&_32$$30);
		ZVAL_LONG(&_32$$30, 0);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 999, &_32$$30);
		RETURN_MM_BOOL(1);
	} else {
		ZVAL_UNDEF(&_33$$31);
		ZVAL_LONG(&_33$$31, 1);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 999, &_33$$31);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}

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
	zephir_get_arrval(&arguments, arguments_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
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
 * @return int|float|string|null|ResultsetInterface
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
			zephir_array_append(&params, parameters, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4986);
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
		zephir_array_fetch_string(&bindParams, &params, SL("bind"), PH_NOISY, "phalcon/Mvc/Model.zep", 5029);
		if (zephir_array_isset_value_string(&params, SL("bindTypes"))) {
			ZEPHIR_OBS_NVAR(&bindTypes);
			zephir_array_fetch_string(&bindTypes, &params, SL("bindTypes"), PH_NOISY, "phalcon/Mvc/Model.zep", 5032);
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
		zephir_throw_exception_debug(&_4$$7, "phalcon/Mvc/Model.zep", 5109);
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
		ZEPHIR_CALL_FUNCTION(&extraMethodFirst, "lcfirst", NULL, 180, &extraMethod);
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
				zephir_throw_exception_debug(&_6$$13, "phalcon/Mvc/Model.zep", 5144);
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
	zval _24$$32, _40$$52;
	zval eventName;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL, *_17 = NULL, *_27 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool exists, error = 0, isNull = 0, _29$$11, _18$$27, _19$$27, _20$$27, _34$$47, _35$$47, _36$$47;
	zval *metaData, metaData_sub, *exists_param = NULL, *identityField, identityField_sub, __$true, __$false, notNull, columnMap, dataTypeNumeric, automaticAttributes, defaultValues, field, attributeField, value, emptyStringValues, _0, _1, _5, _7, _46, _50, _2$$3, _3$$3, _4$$3, _6$$8, _8$$11, _9$$11, *_10$$11, *_11$$11, _28$$11, _12$$18, _14$$18, _15$$19, _16$$19, _21$$27, _22$$32, _23$$32, _25$$32, _26$$32, _30$$38, _31$$38, _32$$39, _33$$39, _37$$47, _38$$52, _39$$52, _41$$52, _42$$52, _43$$56, _44$$56, _45$$57, _47$$58, _48$$58, _49$$59, _51$$60, _52$$60, _53$$60, _54$$60, _55$$60, _56$$60;
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
	ZVAL_UNDEF(&_46);
	ZVAL_UNDEF(&_50);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_28$$11);
	ZVAL_UNDEF(&_12$$18);
	ZVAL_UNDEF(&_14$$18);
	ZVAL_UNDEF(&_15$$19);
	ZVAL_UNDEF(&_16$$19);
	ZVAL_UNDEF(&_21$$27);
	ZVAL_UNDEF(&_22$$32);
	ZVAL_UNDEF(&_23$$32);
	ZVAL_UNDEF(&_25$$32);
	ZVAL_UNDEF(&_26$$32);
	ZVAL_UNDEF(&_30$$38);
	ZVAL_UNDEF(&_31$$38);
	ZVAL_UNDEF(&_32$$39);
	ZVAL_UNDEF(&_33$$39);
	ZVAL_UNDEF(&_37$$47);
	ZVAL_UNDEF(&_38$$52);
	ZVAL_UNDEF(&_39$$52);
	ZVAL_UNDEF(&_41$$52);
	ZVAL_UNDEF(&_42$$52);
	ZVAL_UNDEF(&_43$$56);
	ZVAL_UNDEF(&_44$$56);
	ZVAL_UNDEF(&_45$$57);
	ZVAL_UNDEF(&_47$$58);
	ZVAL_UNDEF(&_48$$58);
	ZVAL_UNDEF(&_49$$59);
	ZVAL_UNDEF(&_51$$60);
	ZVAL_UNDEF(&_52$$60);
	ZVAL_UNDEF(&_53$$60);
	ZVAL_UNDEF(&_54$$60);
	ZVAL_UNDEF(&_55$$60);
	ZVAL_UNDEF(&_56$$60);
	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&_24$$32);
	ZVAL_UNDEF(&_40$$52);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("skipped", 7, 1);
	}

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
			if (Z_TYPE_P(&notNull) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_9$$11);
				zephir_string_to_char_array(&_9$$11, &notNull);
				_10$$11 = &_9$$11;
			} else {
				_10$$11 = &notNull;
			}
			zephir_is_iterable(_10$$11, 0, "phalcon/Mvc/Model.zep", 5389);
			if (Z_TYPE_P(_10$$11) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_10$$11), _11$$11)
				{
					ZEPHIR_INIT_NVAR(&field);
					ZVAL_COPY(&field, _11$$11);
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
							ZEPHIR_INIT_NVAR(&_14$$18);
							ZVAL_STRING(&_14$$18, "orm.ignore_unknown_columns");
							ZEPHIR_CALL_CE_STATIC(&_12$$18, phalcon_support_settings_ce, "get", &_13, 0, &_14$$18);
							zephir_check_call_status();
							if (UNEXPECTED(!zephir_is_true(&_12$$18))) {
								ZEPHIR_INIT_NVAR(&_15$$19);
								object_init_ex(&_15$$19, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
								ZEPHIR_INIT_NVAR(&_16$$19);
								zephir_get_class(&_16$$19, this_ptr, 0);
								ZEPHIR_CALL_METHOD(NULL, &_15$$19, "__construct", &_17, 0, &field, &_16$$19);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_15$$19, "phalcon/Mvc/Model.zep", 5309);
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} else {
						ZEPHIR_CPY_WRT(&attributeField, &field);
					}
					if (!(zephir_array_key_exists(&automaticAttributes, &attributeField))) {
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
										_18$$27 = Z_TYPE_P(&value) == IS_NULL;
										if (!(_18$$27)) {
											_19$$27 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
											if (_19$$27) {
												_20$$27 = !(zephir_array_isset_value(&defaultValues, &field));
												if (!(_20$$27)) {
													zephir_array_fetch(&_21$$27, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 5339);
													_20$$27 = !ZEPHIR_IS_IDENTICAL(&value, &_21$$27);
												}
												_19$$27 = _20$$27;
											}
											_18$$27 = _19$$27;
										}
										if (_18$$27) {
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
							ZEPHIR_INIT_NVAR(&_22$$32);
							object_init_ex(&_22$$32, phalcon_messages_message_ce);
							ZEPHIR_INIT_NVAR(&_23$$32);
							ZEPHIR_CONCAT_VS(&_23$$32, &attributeField, " is required");
							ZEPHIR_INIT_NVAR(&_24$$32);
							zephir_create_array(&_24$$32, 1, 0);
							ZEPHIR_INIT_NVAR(&_25$$32);
							zephir_get_class(&_25$$32, this_ptr, 0);
							zephir_array_update_string(&_24$$32, SL("model"), &_25$$32, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_25$$32);
							ZVAL_STRING(&_25$$32, "PresenceOf");
							ZVAL_LONG(&_26$$32, 0);
							ZEPHIR_CALL_METHOD(NULL, &_22$$32, "__construct", &_27, 5, &_23$$32, &attributeField, &_25$$32, &_26$$32, &_24$$32);
							zephir_check_call_status();
							zephir_update_property_array_append(this_ptr, SL("errorMessages"), &_22$$32);
							error = 1;
						}
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _10$$11, "rewind", NULL, 0);
				zephir_check_call_status();
				_29$$11 = 1;
				while (1) {
					if (_29$$11) {
						_29$$11 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _10$$11, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_28$$11, _10$$11, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_28$$11)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&field, _10$$11, "current", NULL, 0);
					zephir_check_call_status();
						if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
							ZEPHIR_OBS_NVAR(&attributeField);
							if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0)))) {
								ZEPHIR_INIT_NVAR(&_31$$38);
								ZVAL_STRING(&_31$$38, "orm.ignore_unknown_columns");
								ZEPHIR_CALL_CE_STATIC(&_30$$38, phalcon_support_settings_ce, "get", &_13, 0, &_31$$38);
								zephir_check_call_status();
								if (UNEXPECTED(!zephir_is_true(&_30$$38))) {
									ZEPHIR_INIT_NVAR(&_32$$39);
									object_init_ex(&_32$$39, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
									ZEPHIR_INIT_NVAR(&_33$$39);
									zephir_get_class(&_33$$39, this_ptr, 0);
									ZEPHIR_CALL_METHOD(NULL, &_32$$39, "__construct", &_17, 0, &field, &_33$$39);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_32$$39, "phalcon/Mvc/Model.zep", 5309);
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
						} else {
							ZEPHIR_CPY_WRT(&attributeField, &field);
						}
						if (!(zephir_array_key_exists(&automaticAttributes, &attributeField))) {
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
											_34$$47 = Z_TYPE_P(&value) == IS_NULL;
											if (!(_34$$47)) {
												_35$$47 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
												if (_35$$47) {
													_36$$47 = !(zephir_array_isset_value(&defaultValues, &field));
													if (!(_36$$47)) {
														zephir_array_fetch(&_37$$47, &defaultValues, &field, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 5339);
														_36$$47 = !ZEPHIR_IS_IDENTICAL(&value, &_37$$47);
													}
													_35$$47 = _36$$47;
												}
												_34$$47 = _35$$47;
											}
											if (_34$$47) {
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
								ZEPHIR_INIT_NVAR(&_38$$52);
								object_init_ex(&_38$$52, phalcon_messages_message_ce);
								ZEPHIR_INIT_NVAR(&_39$$52);
								ZEPHIR_CONCAT_VS(&_39$$52, &attributeField, " is required");
								ZEPHIR_INIT_NVAR(&_40$$52);
								zephir_create_array(&_40$$52, 1, 0);
								ZEPHIR_INIT_NVAR(&_41$$52);
								zephir_get_class(&_41$$52, this_ptr, 0);
								zephir_array_update_string(&_40$$52, SL("model"), &_41$$52, PH_COPY | PH_SEPARATE);
								ZEPHIR_INIT_NVAR(&_41$$52);
								ZVAL_STRING(&_41$$52, "PresenceOf");
								ZVAL_LONG(&_42$$52, 0);
								ZEPHIR_CALL_METHOD(NULL, &_38$$52, "__construct", &_27, 5, &_39$$52, &attributeField, &_41$$52, &_42$$52, &_40$$52);
								zephir_check_call_status();
								zephir_update_property_array_append(this_ptr, SL("errorMessages"), &_38$$52);
								error = 1;
							}
						}
				}
			}
			ZEPHIR_INIT_NVAR(&field);
			if (error) {
				ZEPHIR_INIT_VAR(&_44$$56);
				ZVAL_STRING(&_44$$56, "orm.events");
				ZEPHIR_CALL_CE_STATIC(&_43$$56, phalcon_support_settings_ce, "get", &_13, 0, &_44$$56);
				zephir_check_call_status();
				if (zephir_is_true(&_43$$56)) {
					ZEPHIR_INIT_VAR(&_45$$57);
					ZVAL_STRING(&_45$$57, "onValidationFails");
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_45$$57);
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
	ZEPHIR_CALL_METHOD(&_46, this_ptr, "fireeventcancel", NULL, 0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_46)) {
		ZEPHIR_INIT_VAR(&_48$$58);
		ZVAL_STRING(&_48$$58, "orm.events");
		ZEPHIR_CALL_CE_STATIC(&_47$$58, phalcon_support_settings_ce, "get", &_13, 0, &_48$$58);
		zephir_check_call_status();
		if (zephir_is_true(&_47$$58)) {
			ZEPHIR_INIT_VAR(&_49$$59);
			ZVAL_STRING(&_49$$59, "onValidationFails");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_49$$59);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "orm.events");
	ZEPHIR_CALL_CE_STATIC(&_50, phalcon_support_settings_ce, "get", &_13, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_50)) {
		if (exists) {
			ZEPHIR_INIT_NVAR(&eventName);
			ZVAL_STRING(&eventName, "afterValidationOnUpdate");
		} else {
			ZEPHIR_INIT_NVAR(&eventName);
			ZVAL_STRING(&eventName, "afterValidationOnCreate");
		}
		ZEPHIR_CALL_METHOD(&_51$$60, this_ptr, "fireeventcancel", NULL, 0, &eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_51$$60)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(&_53$$60);
		ZVAL_STRING(&_53$$60, "afterValidation");
		ZEPHIR_CALL_METHOD(&_52$$60, this_ptr, "fireeventcancel", NULL, 0, &_53$$60);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_52$$60)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(&_53$$60);
		ZVAL_STRING(&_53$$60, "beforeSave");
		ZEPHIR_CALL_METHOD(&_54$$60, this_ptr, "fireeventcancel", NULL, 0, &_53$$60);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_54$$60)) {
			RETURN_MM_BOOL(0);
		}
		if (0) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1004, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1004, &__$false);
		}
		if (exists) {
			ZEPHIR_INIT_NVAR(&eventName);
			ZVAL_STRING(&eventName, "beforeUpdate");
		} else {
			ZEPHIR_INIT_NVAR(&eventName);
			ZVAL_STRING(&eventName, "beforeCreate");
		}
		ZEPHIR_CALL_METHOD(&_55$$60, this_ptr, "fireeventcancel", NULL, 0, &eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_55$$60)) {
			RETURN_MM_BOOL(0);
		}
		zephir_read_property_cached(&_56$$60, this_ptr, _zephir_prop_0, 1004, PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_56$$60)) {
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
	zend_string *_6;
	zend_ulong _5;
	zend_bool nesting = 0, _24, _18$$8, _34$$16;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_10 = NULL, *_13 = NULL, *_15 = NULL, *_17 = NULL, *_26 = NULL, *_28 = NULL, *_33 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, columnCount = 0, i = 0, _19$$8, _20$$8, _35$$16, _36$$16;
	zval *connection, connection_sub, *related, related_sub, *visited, visited_sub, className, manager, type, relation, columns, referencedFields, name, record, columnA, columnB, _0, _1, *_2, _3, *_4, _23, _7$$3, _9$$6, _11$$6, _12$$6, _14$$5, _16$$7, _21$$9, _22$$10, _25$$11, _27$$14, _29$$14, _30$$14, _31$$13, _32$$15, _37$$17, _38$$18;
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
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_27$$14);
	ZVAL_UNDEF(&_29$$14);
	ZVAL_UNDEF(&_30$$14);
	ZVAL_UNDEF(&_31$$13);
	ZVAL_UNDEF(&_32$$15);
	ZVAL_UNDEF(&_37$$17);
	ZVAL_UNDEF(&_38$$18);
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
	if (Z_TYPE_P(related) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_3);
		zephir_string_to_char_array(&_3, related);
		_2 = &_3;
	} else {
		_2 = related;
	}
	zephir_is_iterable(_2, 0, "phalcon/Mvc/Model.zep", 5552);
	if (Z_TYPE_P(_2) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_2), _5, _6, _4)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_6 != NULL) { 
				ZVAL_STR_COPY(&name, _6);
			} else {
				ZVAL_LONG(&name, _5);
			}
			ZEPHIR_INIT_NVAR(&record);
			ZVAL_COPY(&record, _4);
			ZEPHIR_CALL_METHOD(&_7$$3, &manager, "getrelationbyalias", &_8, 0, &className, &name);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&relation, &_7$$3);
			if (Z_TYPE_P(&relation) == IS_OBJECT) {
				ZEPHIR_CALL_METHOD(&type, &relation, "gettype", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(&type, 0)) {
					if (UNEXPECTED(Z_TYPE_P(&record) != IS_OBJECT)) {
						if (nesting) {
							ZVAL_BOOL(&_9$$6, 1);
						} else {
							ZVAL_BOOL(&_9$$6, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_10, 0, &_9$$6);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_11$$6);
						object_init_ex(&_11$$6, phalcon_mvc_model_exceptions_belongstorequiresobject_ce);
						ZEPHIR_INIT_NVAR(&_12$$6);
						zephir_get_class(&_12$$6, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_11$$6, "__construct", &_13, 0, &_12$$6, &name);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_11$$6, "phalcon/Mvc/Model.zep", 5509);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_14$$5, &record, "dosave", NULL, 0, visited);
					zephir_check_call_status();
					if (!(zephir_is_true(&_14$$5))) {
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_15, 0, &record);
						zephir_check_call_status();
						if (nesting) {
							ZVAL_BOOL(&_16$$7, 1);
						} else {
							ZVAL_BOOL(&_16$$7, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_17, 0, &_16$$7);
						zephir_check_call_status();
						RETURN_MM_BOOL(0);
					}
					ZEPHIR_CALL_METHOD(&columns, &relation, "getfields", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", NULL, 0);
					zephir_check_call_status();
					if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
						columnCount = (zephir_fast_count_int(&columns) - 1);
						_20$$8 = columnCount;
						_19$$8 = 0;
						_18$$8 = 0;
						if (_19$$8 <= _20$$8) {
							while (1) {
								if (_18$$8) {
									_19$$8++;
									if (!(_19$$8 <= _20$$8)) {
										break;
									}
								} else {
									_18$$8 = 1;
								}
								i = _19$$8;
								zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 5541);
								zephir_array_fetch_long(&columnB, &referencedFields, i, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 5542);
								ZEPHIR_OBS_NVAR(&_21$$9);
								zephir_read_property_zval(&_21$$9, &record, &columnB, PH_NOISY_CC);
								zephir_update_property_zval_zval(this_ptr, &columnA, &_21$$9);
							}
						}
					} else {
						ZEPHIR_OBS_NVAR(&_22$$10);
						zephir_read_property_zval(&_22$$10, &record, &referencedFields, PH_NOISY_CC);
						zephir_update_property_zval_zval(this_ptr, &columns, &_22$$10);
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _2, "rewind", NULL, 0);
		zephir_check_call_status();
		_24 = 1;
		while (1) {
			if (_24) {
				_24 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _2, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_23, _2, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_23)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, _2, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&record, _2, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_25$$11, &manager, "getrelationbyalias", &_26, 0, &className, &name);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&relation, &_25$$11);
				if (Z_TYPE_P(&relation) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&type, &relation, "gettype", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG(&type, 0)) {
						if (UNEXPECTED(Z_TYPE_P(&record) != IS_OBJECT)) {
							if (nesting) {
								ZVAL_BOOL(&_27$$14, 1);
							} else {
								ZVAL_BOOL(&_27$$14, 0);
							}
							ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_28, 0, &_27$$14);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_29$$14);
							object_init_ex(&_29$$14, phalcon_mvc_model_exceptions_belongstorequiresobject_ce);
							ZEPHIR_INIT_NVAR(&_30$$14);
							zephir_get_class(&_30$$14, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_29$$14, "__construct", &_13, 0, &_30$$14, &name);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_29$$14, "phalcon/Mvc/Model.zep", 5509);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD(&_31$$13, &record, "dosave", NULL, 0, visited);
						zephir_check_call_status();
						if (!(zephir_is_true(&_31$$13))) {
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_15, 0, &record);
							zephir_check_call_status();
							if (nesting) {
								ZVAL_BOOL(&_32$$15, 1);
							} else {
								ZVAL_BOOL(&_32$$15, 0);
							}
							ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_33, 0, &_32$$15);
							zephir_check_call_status();
							RETURN_MM_BOOL(0);
						}
						ZEPHIR_CALL_METHOD(&columns, &relation, "getfields", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", NULL, 0);
						zephir_check_call_status();
						if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
							columnCount = (zephir_fast_count_int(&columns) - 1);
							_36$$16 = columnCount;
							_35$$16 = 0;
							_34$$16 = 0;
							if (_35$$16 <= _36$$16) {
								while (1) {
									if (_34$$16) {
										_35$$16++;
										if (!(_35$$16 <= _36$$16)) {
											break;
										}
									} else {
										_34$$16 = 1;
									}
									i = _35$$16;
									ZEPHIR_OBS_NVAR(&columnA);
									zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5541);
									ZEPHIR_OBS_NVAR(&columnB);
									zephir_array_fetch_long(&columnB, &referencedFields, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5542);
									ZEPHIR_OBS_NVAR(&_37$$17);
									zephir_read_property_zval(&_37$$17, &record, &columnB, PH_NOISY_CC);
									zephir_update_property_zval_zval(this_ptr, &columnA, &_37$$17);
								}
							}
						} else {
							ZEPHIR_OBS_NVAR(&_38$$18);
							zephir_read_property_zval(&_38$$18, &record, &referencedFields, PH_NOISY_CC);
							zephir_update_property_zval_zval(this_ptr, &columns, &_38$$18);
						}
					}
				}
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
	zval _27$$13, _46$$19, _51$$20, _81$$34, _97$$39, _102$$40, _132$$54, _150$$60, _167$$66, _231$$93, _249$$99, _254$$100, _284$$114, _300$$119, _305$$120, _335$$134, _353$$140, _370$$146;
	zend_string *_5;
	zend_ulong _4;
	zval conditions, placeholders, loopConditions, loopPlaceholders, keptKeys, _54$$15, _105$$35, _136$$55, _257$$95, _308$$115, _339$$135;
	zend_bool nesting = 0, isThrough = 0, doSync = 0, _209, _9$$4, _83$$9, _133$$9, _19$$12, _56$$15, _38$$18, _58$$23, _63$$26, _77$$31, _107$$35, _89$$38, _109$$43, _114$$46, _128$$51, _156$$55, _146$$57, _151$$56, _163$$63, _168$$62, _183$$69, _175$$70, _184$$73, _199$$76, _213$$84, _286$$89, _336$$89, _223$$92, _259$$95, _241$$98, _261$$103, _266$$106, _280$$111, _310$$115, _292$$118, _312$$123, _317$$126, _331$$131, _359$$135, _349$$137, _354$$136, _366$$143, _371$$142, _386$$149, _378$$150, _387$$153, _402$$156;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_11 = NULL, *_13 = NULL, *_33 = NULL, *_35 = NULL, *_37 = NULL, *_53 = NULL, *_57 = NULL, *_70 = NULL, *_86 = NULL, *_88 = NULL, *_104 = NULL, *_108 = NULL, *_121 = NULL, *_135 = NULL, *_154 = NULL, *_171 = NULL, *_181 = NULL, *_190 = NULL, *_197 = NULL, *_203 = NULL, *_205 = NULL, *_207 = NULL, *_211 = NULL, *_215 = NULL, *_238 = NULL, *_240 = NULL, *_256 = NULL, *_260 = NULL, *_273 = NULL, *_289 = NULL, *_291 = NULL, *_307 = NULL, *_311 = NULL, *_324 = NULL, *_338 = NULL, *_357 = NULL, *_374 = NULL, *_384 = NULL, *_393 = NULL, *_400 = NULL, *_406 = NULL, *_408 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, referencedFieldsCount = 0, i = 0, j = 0, t = 0, h = 0, columnCount, _20$$12, _21$$12, _39$$18, _40$$18, _59$$23, _60$$23, _64$$26, _65$$26, _90$$38, _91$$38, _110$$43, _111$$43, _115$$46, _116$$46, _176$$70, _177$$70, _185$$73, _186$$73, _224$$92, _225$$92, _242$$98, _243$$98, _262$$103, _263$$103, _267$$106, _268$$106, _293$$118, _294$$118, _313$$123, _314$$123, _318$$126, _319$$126, _379$$150, _380$$150, _388$$153, _389$$153;
	zval *connection, connection_sub, *related, related_sub, *visited, visited_sub, __$true, className, manager, relation, name, record, columns, referencedModel, referencedFields, relatedRecords, recordAfter, intermediateModel, intermediateFields, intermediateModelName, intermediateReferencedFields, existingIntermediateModel, columnA, columnB, existingRecords, existingRecord, keepKey, override, _0, *_1, _2, *_3, _208, _410, _6$$3, _8$$4, _14$$4, _10$$6, _12$$6, _15$$9, _16$$9, _17$$9, _18$$9, *_30$$9, *_31$$9, _82$$9, _22$$13, _23$$13, _24$$13, _25$$13, _26$$13, _28$$14, _29$$14, _32$$15, _36$$15, _52$$15, _55$$15, _68$$15, _34$$16, _41$$19, _42$$19, _43$$19, _44$$19, _45$$19, _47$$20, _48$$20, _49$$20, _50$$20, _61$$24, _62$$25, _66$$27, _67$$28, _69$$29, *_71$$31, _72$$31, *_73$$31, _76$$31, _74$$32, _75$$32, _78$$33, _79$$33, _80$$34, _84$$35, _87$$35, _103$$35, _106$$35, _119$$35, _85$$36, _92$$39, _93$$39, _94$$39, _95$$39, _96$$39, _98$$40, _99$$40, _100$$40, _101$$40, _112$$44, _113$$45, _117$$47, _118$$48, _120$$49, *_122$$51, _123$$51, *_124$$51, _127$$51, _125$$52, _126$$52, _129$$53, _130$$53, _131$$54, _134$$55, _137$$55, *_138$$55, *_139$$55, _155$$55, *_140$$57, _141$$57, *_142$$57, _145$$57, _143$$58, _144$$58, _147$$59, _148$$59, _149$$60, _152$$56, _153$$61, *_157$$63, _158$$63, *_159$$63, _162$$63, _160$$64, _161$$64, _164$$65, _165$$65, _166$$66, _169$$62, _170$$67, *_172$$69, _173$$69, *_174$$69, _182$$69, _179$$70, _178$$71, _180$$72, _188$$73, _187$$74, _189$$75, *_191$$76, _192$$76, *_193$$76, _198$$76, _194$$77, _195$$77, _196$$78, _200$$79, _201$$79, _202$$80, _204$$82, _206$$82, _210$$83, _212$$84, _218$$84, _214$$86, _216$$86, _217$$87, _219$$89, _220$$89, _221$$89, _222$$89, *_234$$89, *_235$$89, _285$$89, _226$$93, _227$$93, _228$$93, _229$$93, _230$$93, _232$$94, _233$$94, _236$$95, _239$$95, _255$$95, _258$$95, _271$$95, _237$$96, _244$$99, _245$$99, _246$$99, _247$$99, _248$$99, _250$$100, _251$$100, _252$$100, _253$$100, _264$$104, _265$$105, _269$$107, _270$$108, _272$$109, *_274$$111, _275$$111, *_276$$111, _279$$111, _277$$112, _278$$112, _281$$113, _282$$113, _283$$114, _287$$115, _290$$115, _306$$115, _309$$115, _322$$115, _288$$116, _295$$119, _296$$119, _297$$119, _298$$119, _299$$119, _301$$120, _302$$120, _303$$120, _304$$120, _315$$124, _316$$125, _320$$127, _321$$128, _323$$129, *_325$$131, _326$$131, *_327$$131, _330$$131, _328$$132, _329$$132, _332$$133, _333$$133, _334$$134, _337$$135, _340$$135, *_341$$135, *_342$$135, _358$$135, *_343$$137, _344$$137, *_345$$137, _348$$137, _346$$138, _347$$138, _350$$139, _351$$139, _352$$140, _355$$136, _356$$141, *_360$$143, _361$$143, *_362$$143, _365$$143, _363$$144, _364$$144, _367$$145, _368$$145, _369$$146, _372$$142, _373$$147, *_375$$149, _376$$149, *_377$$149, _385$$149, _382$$150, _381$$151, _383$$152, _391$$153, _390$$154, _392$$155, *_394$$156, _395$$156, *_396$$156, _401$$156, _397$$157, _398$$157, _399$$158, _403$$159, _404$$159, _405$$160, _407$$162, _409$$162;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&related_sub);
	ZVAL_UNDEF(&visited_sub);
	ZVAL_BOOL(&__$true, 1);
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
	ZVAL_UNDEF(&existingRecords);
	ZVAL_UNDEF(&existingRecord);
	ZVAL_UNDEF(&keepKey);
	ZVAL_UNDEF(&override);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_208);
	ZVAL_UNDEF(&_410);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_82$$9);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_26$$13);
	ZVAL_UNDEF(&_28$$14);
	ZVAL_UNDEF(&_29$$14);
	ZVAL_UNDEF(&_32$$15);
	ZVAL_UNDEF(&_36$$15);
	ZVAL_UNDEF(&_52$$15);
	ZVAL_UNDEF(&_55$$15);
	ZVAL_UNDEF(&_68$$15);
	ZVAL_UNDEF(&_34$$16);
	ZVAL_UNDEF(&_41$$19);
	ZVAL_UNDEF(&_42$$19);
	ZVAL_UNDEF(&_43$$19);
	ZVAL_UNDEF(&_44$$19);
	ZVAL_UNDEF(&_45$$19);
	ZVAL_UNDEF(&_47$$20);
	ZVAL_UNDEF(&_48$$20);
	ZVAL_UNDEF(&_49$$20);
	ZVAL_UNDEF(&_50$$20);
	ZVAL_UNDEF(&_61$$24);
	ZVAL_UNDEF(&_62$$25);
	ZVAL_UNDEF(&_66$$27);
	ZVAL_UNDEF(&_67$$28);
	ZVAL_UNDEF(&_69$$29);
	ZVAL_UNDEF(&_72$$31);
	ZVAL_UNDEF(&_76$$31);
	ZVAL_UNDEF(&_74$$32);
	ZVAL_UNDEF(&_75$$32);
	ZVAL_UNDEF(&_78$$33);
	ZVAL_UNDEF(&_79$$33);
	ZVAL_UNDEF(&_80$$34);
	ZVAL_UNDEF(&_84$$35);
	ZVAL_UNDEF(&_87$$35);
	ZVAL_UNDEF(&_103$$35);
	ZVAL_UNDEF(&_106$$35);
	ZVAL_UNDEF(&_119$$35);
	ZVAL_UNDEF(&_85$$36);
	ZVAL_UNDEF(&_92$$39);
	ZVAL_UNDEF(&_93$$39);
	ZVAL_UNDEF(&_94$$39);
	ZVAL_UNDEF(&_95$$39);
	ZVAL_UNDEF(&_96$$39);
	ZVAL_UNDEF(&_98$$40);
	ZVAL_UNDEF(&_99$$40);
	ZVAL_UNDEF(&_100$$40);
	ZVAL_UNDEF(&_101$$40);
	ZVAL_UNDEF(&_112$$44);
	ZVAL_UNDEF(&_113$$45);
	ZVAL_UNDEF(&_117$$47);
	ZVAL_UNDEF(&_118$$48);
	ZVAL_UNDEF(&_120$$49);
	ZVAL_UNDEF(&_123$$51);
	ZVAL_UNDEF(&_127$$51);
	ZVAL_UNDEF(&_125$$52);
	ZVAL_UNDEF(&_126$$52);
	ZVAL_UNDEF(&_129$$53);
	ZVAL_UNDEF(&_130$$53);
	ZVAL_UNDEF(&_131$$54);
	ZVAL_UNDEF(&_134$$55);
	ZVAL_UNDEF(&_137$$55);
	ZVAL_UNDEF(&_155$$55);
	ZVAL_UNDEF(&_141$$57);
	ZVAL_UNDEF(&_145$$57);
	ZVAL_UNDEF(&_143$$58);
	ZVAL_UNDEF(&_144$$58);
	ZVAL_UNDEF(&_147$$59);
	ZVAL_UNDEF(&_148$$59);
	ZVAL_UNDEF(&_149$$60);
	ZVAL_UNDEF(&_152$$56);
	ZVAL_UNDEF(&_153$$61);
	ZVAL_UNDEF(&_158$$63);
	ZVAL_UNDEF(&_162$$63);
	ZVAL_UNDEF(&_160$$64);
	ZVAL_UNDEF(&_161$$64);
	ZVAL_UNDEF(&_164$$65);
	ZVAL_UNDEF(&_165$$65);
	ZVAL_UNDEF(&_166$$66);
	ZVAL_UNDEF(&_169$$62);
	ZVAL_UNDEF(&_170$$67);
	ZVAL_UNDEF(&_173$$69);
	ZVAL_UNDEF(&_182$$69);
	ZVAL_UNDEF(&_179$$70);
	ZVAL_UNDEF(&_178$$71);
	ZVAL_UNDEF(&_180$$72);
	ZVAL_UNDEF(&_188$$73);
	ZVAL_UNDEF(&_187$$74);
	ZVAL_UNDEF(&_189$$75);
	ZVAL_UNDEF(&_192$$76);
	ZVAL_UNDEF(&_198$$76);
	ZVAL_UNDEF(&_194$$77);
	ZVAL_UNDEF(&_195$$77);
	ZVAL_UNDEF(&_196$$78);
	ZVAL_UNDEF(&_200$$79);
	ZVAL_UNDEF(&_201$$79);
	ZVAL_UNDEF(&_202$$80);
	ZVAL_UNDEF(&_204$$82);
	ZVAL_UNDEF(&_206$$82);
	ZVAL_UNDEF(&_210$$83);
	ZVAL_UNDEF(&_212$$84);
	ZVAL_UNDEF(&_218$$84);
	ZVAL_UNDEF(&_214$$86);
	ZVAL_UNDEF(&_216$$86);
	ZVAL_UNDEF(&_217$$87);
	ZVAL_UNDEF(&_219$$89);
	ZVAL_UNDEF(&_220$$89);
	ZVAL_UNDEF(&_221$$89);
	ZVAL_UNDEF(&_222$$89);
	ZVAL_UNDEF(&_285$$89);
	ZVAL_UNDEF(&_226$$93);
	ZVAL_UNDEF(&_227$$93);
	ZVAL_UNDEF(&_228$$93);
	ZVAL_UNDEF(&_229$$93);
	ZVAL_UNDEF(&_230$$93);
	ZVAL_UNDEF(&_232$$94);
	ZVAL_UNDEF(&_233$$94);
	ZVAL_UNDEF(&_236$$95);
	ZVAL_UNDEF(&_239$$95);
	ZVAL_UNDEF(&_255$$95);
	ZVAL_UNDEF(&_258$$95);
	ZVAL_UNDEF(&_271$$95);
	ZVAL_UNDEF(&_237$$96);
	ZVAL_UNDEF(&_244$$99);
	ZVAL_UNDEF(&_245$$99);
	ZVAL_UNDEF(&_246$$99);
	ZVAL_UNDEF(&_247$$99);
	ZVAL_UNDEF(&_248$$99);
	ZVAL_UNDEF(&_250$$100);
	ZVAL_UNDEF(&_251$$100);
	ZVAL_UNDEF(&_252$$100);
	ZVAL_UNDEF(&_253$$100);
	ZVAL_UNDEF(&_264$$104);
	ZVAL_UNDEF(&_265$$105);
	ZVAL_UNDEF(&_269$$107);
	ZVAL_UNDEF(&_270$$108);
	ZVAL_UNDEF(&_272$$109);
	ZVAL_UNDEF(&_275$$111);
	ZVAL_UNDEF(&_279$$111);
	ZVAL_UNDEF(&_277$$112);
	ZVAL_UNDEF(&_278$$112);
	ZVAL_UNDEF(&_281$$113);
	ZVAL_UNDEF(&_282$$113);
	ZVAL_UNDEF(&_283$$114);
	ZVAL_UNDEF(&_287$$115);
	ZVAL_UNDEF(&_290$$115);
	ZVAL_UNDEF(&_306$$115);
	ZVAL_UNDEF(&_309$$115);
	ZVAL_UNDEF(&_322$$115);
	ZVAL_UNDEF(&_288$$116);
	ZVAL_UNDEF(&_295$$119);
	ZVAL_UNDEF(&_296$$119);
	ZVAL_UNDEF(&_297$$119);
	ZVAL_UNDEF(&_298$$119);
	ZVAL_UNDEF(&_299$$119);
	ZVAL_UNDEF(&_301$$120);
	ZVAL_UNDEF(&_302$$120);
	ZVAL_UNDEF(&_303$$120);
	ZVAL_UNDEF(&_304$$120);
	ZVAL_UNDEF(&_315$$124);
	ZVAL_UNDEF(&_316$$125);
	ZVAL_UNDEF(&_320$$127);
	ZVAL_UNDEF(&_321$$128);
	ZVAL_UNDEF(&_323$$129);
	ZVAL_UNDEF(&_326$$131);
	ZVAL_UNDEF(&_330$$131);
	ZVAL_UNDEF(&_328$$132);
	ZVAL_UNDEF(&_329$$132);
	ZVAL_UNDEF(&_332$$133);
	ZVAL_UNDEF(&_333$$133);
	ZVAL_UNDEF(&_334$$134);
	ZVAL_UNDEF(&_337$$135);
	ZVAL_UNDEF(&_340$$135);
	ZVAL_UNDEF(&_358$$135);
	ZVAL_UNDEF(&_344$$137);
	ZVAL_UNDEF(&_348$$137);
	ZVAL_UNDEF(&_346$$138);
	ZVAL_UNDEF(&_347$$138);
	ZVAL_UNDEF(&_350$$139);
	ZVAL_UNDEF(&_351$$139);
	ZVAL_UNDEF(&_352$$140);
	ZVAL_UNDEF(&_355$$136);
	ZVAL_UNDEF(&_356$$141);
	ZVAL_UNDEF(&_361$$143);
	ZVAL_UNDEF(&_365$$143);
	ZVAL_UNDEF(&_363$$144);
	ZVAL_UNDEF(&_364$$144);
	ZVAL_UNDEF(&_367$$145);
	ZVAL_UNDEF(&_368$$145);
	ZVAL_UNDEF(&_369$$146);
	ZVAL_UNDEF(&_372$$142);
	ZVAL_UNDEF(&_373$$147);
	ZVAL_UNDEF(&_376$$149);
	ZVAL_UNDEF(&_385$$149);
	ZVAL_UNDEF(&_382$$150);
	ZVAL_UNDEF(&_381$$151);
	ZVAL_UNDEF(&_383$$152);
	ZVAL_UNDEF(&_391$$153);
	ZVAL_UNDEF(&_390$$154);
	ZVAL_UNDEF(&_392$$155);
	ZVAL_UNDEF(&_395$$156);
	ZVAL_UNDEF(&_401$$156);
	ZVAL_UNDEF(&_397$$157);
	ZVAL_UNDEF(&_398$$157);
	ZVAL_UNDEF(&_399$$158);
	ZVAL_UNDEF(&_403$$159);
	ZVAL_UNDEF(&_404$$159);
	ZVAL_UNDEF(&_405$$160);
	ZVAL_UNDEF(&_407$$162);
	ZVAL_UNDEF(&_409$$162);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&placeholders);
	ZVAL_UNDEF(&loopConditions);
	ZVAL_UNDEF(&loopPlaceholders);
	ZVAL_UNDEF(&keptKeys);
	ZVAL_UNDEF(&_54$$15);
	ZVAL_UNDEF(&_105$$35);
	ZVAL_UNDEF(&_136$$55);
	ZVAL_UNDEF(&_257$$95);
	ZVAL_UNDEF(&_308$$115);
	ZVAL_UNDEF(&_339$$135);
	ZVAL_UNDEF(&_27$$13);
	ZVAL_UNDEF(&_46$$19);
	ZVAL_UNDEF(&_51$$20);
	ZVAL_UNDEF(&_81$$34);
	ZVAL_UNDEF(&_97$$39);
	ZVAL_UNDEF(&_102$$40);
	ZVAL_UNDEF(&_132$$54);
	ZVAL_UNDEF(&_150$$60);
	ZVAL_UNDEF(&_167$$66);
	ZVAL_UNDEF(&_231$$93);
	ZVAL_UNDEF(&_249$$99);
	ZVAL_UNDEF(&_254$$100);
	ZVAL_UNDEF(&_284$$114);
	ZVAL_UNDEF(&_300$$119);
	ZVAL_UNDEF(&_305$$120);
	ZVAL_UNDEF(&_335$$134);
	ZVAL_UNDEF(&_353$$140);
	ZVAL_UNDEF(&_370$$146);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("syncRelated", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(connection, phalcon_db_adapter_adapterinterface_ce)
		Z_PARAM_ZVAL(related)
		Z_PARAM_OBJECT_OF_CLASS(visited, phalcon_support_collection_collectioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &connection, &related, &visited);
	columnCount = 0;
	nesting = 0;
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, this_ptr, 0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_0);
	if (Z_TYPE_P(related) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, related);
		_1 = &_2;
	} else {
		_1 = related;
	}
	zephir_is_iterable(_1, 0, "phalcon/Mvc/Model.zep", 5897);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_1), _4, _5, _3)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&name, _5);
			} else {
				ZVAL_LONG(&name, _4);
			}
			ZEPHIR_INIT_NVAR(&record);
			ZVAL_COPY(&record, _3);
			ZEPHIR_CALL_METHOD(&_6$$3, &manager, "getrelationbyalias", &_7, 0, &className, &name);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&relation, &_6$$3);
			if (Z_TYPE_P(&relation) == IS_OBJECT) {
				ZEPHIR_CALL_METHOD(&_8$$4, &relation, "gettype", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(&_8$$4, 0)) {
					continue;
				}
				_9$$4 = Z_TYPE_P(&record) != IS_OBJECT;
				if (_9$$4) {
					_9$$4 = Z_TYPE_P(&record) != IS_ARRAY;
				}
				if (UNEXPECTED(_9$$4)) {
					if (nesting) {
						ZVAL_BOOL(&_10$$6, 1);
					} else {
						ZVAL_BOOL(&_10$$6, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_11, 0, &_10$$6);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_12$$6);
					object_init_ex(&_12$$6, phalcon_mvc_model_exceptions_relationrequiresobjectorarray_ce);
					ZEPHIR_CALL_METHOD(NULL, &_12$$6, "__construct", &_13, 0, &className, &name);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_12$$6, "phalcon/Mvc/Model.zep", 5617);
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
				ZEPHIR_CALL_METHOD(&_14$$4, &relation, "isthrough", NULL, 0);
				zephir_check_call_status();
				isThrough = zephir_get_boolval(&_14$$4);
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
					ZEPHIR_INIT_NVAR(&keptKeys);
					array_init(&keptKeys);
					ZEPHIR_INIT_NVAR(&_16$$9);
					ZVAL_STRING(&_16$$9, "sync");
					ZEPHIR_CALL_METHOD(&_15$$9, &relation, "getoption", NULL, 0, &_16$$9);
					zephir_check_call_status();
					doSync = zephir_get_boolval(&_15$$9);
					ZEPHIR_OBS_NVAR(&override);
					zephir_read_property_cached(&_17$$9, this_ptr, _zephir_prop_0, 1011, PH_NOISY_CC | PH_READONLY);
					if (zephir_array_isset_fetch(&override, &_17$$9, &name, 0)) {
						doSync = zephir_get_boolval(&override);
					} else {
						ZEPHIR_OBS_NVAR(&override);
						zephir_read_property_cached(&_18$$9, this_ptr, _zephir_prop_0, 1011, PH_NOISY_CC | PH_READONLY);
						if (zephir_array_isset_string_fetch(&override, &_18$$9, SL("*"), 0)) {
							doSync = zephir_get_boolval(&override);
						}
					}
					if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
						columnCount = (zephir_fast_count_int(&columns) - 1);
						_21$$12 = columnCount;
						_20$$12 = 0;
						_19$$12 = 0;
						if (_20$$12 <= _21$$12) {
							while (1) {
								if (_19$$12) {
									_20$$12++;
									if (!(_20$$12 <= _21$$12)) {
										break;
									}
								} else {
									_19$$12 = 1;
								}
								i = _20$$12;
								ZEPHIR_OBS_NVAR(&columnA);
								zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5664);
								zephir_array_fetch_long(&_22$$13, &intermediateFields, i, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 5665);
								ZEPHIR_INIT_NVAR(&_23$$13);
								ZVAL_LONG(&_23$$13, i);
								ZEPHIR_INIT_NVAR(&_24$$13);
								ZEPHIR_CONCAT_SVSVS(&_24$$13, "[", &_22$$13, "] = :APR", &_23$$13, ":");
								zephir_array_append(&conditions, &_24$$13, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5665);
								ZEPHIR_OBS_NVAR(&_25$$13);
								zephir_read_property_zval(&_25$$13, this_ptr, &columnA, PH_NOISY_CC);
								ZEPHIR_INIT_NVAR(&_26$$13);
								ZVAL_LONG(&_26$$13, i);
								ZEPHIR_INIT_NVAR(&_27$$13);
								ZEPHIR_CONCAT_SV(&_27$$13, "APR", &_26$$13);
								zephir_array_update_zval(&placeholders, &_27$$13, &_25$$13, PH_COPY | PH_SEPARATE);
							}
						}
						i = (columnCount + 1);
					} else {
						ZEPHIR_INIT_NVAR(&_28$$14);
						ZEPHIR_CONCAT_SVS(&_28$$14, "[", &intermediateFields, "] = :APR0:");
						zephir_array_append(&conditions, &_28$$14, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5670);
						ZEPHIR_OBS_NVAR(&_29$$14);
						zephir_read_property_zval(&_29$$14, this_ptr, &columns, PH_NOISY_CC);
						zephir_array_update_string(&placeholders, SL("APR0"), &_29$$14, PH_COPY | PH_SEPARATE);
						i = 1;
					}
					if (Z_TYPE_P(&relatedRecords) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_16$$9);
						zephir_string_to_char_array(&_16$$9, &relatedRecords);
						_30$$9 = &_16$$9;
					} else {
						_30$$9 = &relatedRecords;
					}
					zephir_is_iterable(_30$$9, 0, "phalcon/Mvc/Model.zep", 5800);
					if (Z_TYPE_P(_30$$9) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_30$$9), _31$$9)
						{
							ZEPHIR_INIT_NVAR(&recordAfter);
							ZVAL_COPY(&recordAfter, _31$$9);
							ZEPHIR_CALL_METHOD(&_32$$15, &recordAfter, "dosave", NULL, 0, visited);
							zephir_check_call_status();
							if (!(zephir_is_true(&_32$$15))) {
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_33, 0, &recordAfter);
								zephir_check_call_status();
								if (nesting) {
									ZVAL_BOOL(&_34$$16, 1);
								} else {
									ZVAL_BOOL(&_34$$16, 0);
								}
								ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_35, 0, &_34$$16);
								zephir_check_call_status();
								RETURN_MM_BOOL(0);
							}
							ZEPHIR_CPY_WRT(&loopConditions, &conditions);
							ZEPHIR_CPY_WRT(&loopPlaceholders, &placeholders);
							ZEPHIR_CALL_METHOD(&_36$$15, &relation, "gettype", &_37, 0);
							zephir_check_call_status();
							if (ZEPHIR_IS_LONG_IDENTICAL(&_36$$15, 4)) {
								if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
									referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
									_40$$18 = referencedFieldsCount;
									_39$$18 = 0;
									_38$$18 = 0;
									if (_39$$18 <= _40$$18) {
										while (1) {
											if (_38$$18) {
												_39$$18++;
												if (!(_39$$18 <= _40$$18)) {
													break;
												}
											} else {
												_38$$18 = 1;
											}
											j = _39$$18;
											ZEPHIR_OBS_NVAR(&columnA);
											zephir_array_fetch_long(&columnA, &referencedFields, j, PH_NOISY, "phalcon/Mvc/Model.zep", 5705);
											t = (j + i);
											zephir_array_fetch_long(&_41$$19, &intermediateReferencedFields, j, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 5707);
											ZEPHIR_INIT_NVAR(&_42$$19);
											ZVAL_LONG(&_42$$19, t);
											ZEPHIR_INIT_NVAR(&_43$$19);
											ZEPHIR_CONCAT_SVSVS(&_43$$19, "[", &_41$$19, "] = :APR", &_42$$19, ":");
											zephir_array_append(&loopConditions, &_43$$19, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5707);
											ZEPHIR_OBS_NVAR(&_44$$19);
											zephir_read_property_zval(&_44$$19, &recordAfter, &columnA, PH_NOISY_CC);
											ZEPHIR_INIT_NVAR(&_45$$19);
											ZVAL_LONG(&_45$$19, t);
											ZEPHIR_INIT_NVAR(&_46$$19);
											ZEPHIR_CONCAT_SV(&_46$$19, "APR", &_45$$19);
											zephir_array_update_zval(&loopPlaceholders, &_46$$19, &_44$$19, PH_COPY | PH_SEPARATE);
										}
									}
								} else {
									ZEPHIR_INIT_NVAR(&_47$$20);
									ZVAL_LONG(&_47$$20, i);
									ZEPHIR_INIT_NVAR(&_48$$20);
									ZEPHIR_CONCAT_SVSVS(&_48$$20, "[", &intermediateReferencedFields, "] = :APR", &_47$$20, ":");
									zephir_array_append(&loopConditions, &_48$$20, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5711);
									ZEPHIR_OBS_NVAR(&_49$$20);
									zephir_read_property_zval(&_49$$20, &recordAfter, &referencedFields, PH_NOISY_CC);
									ZEPHIR_INIT_NVAR(&_50$$20);
									ZVAL_LONG(&_50$$20, i);
									ZEPHIR_INIT_NVAR(&_51$$20);
									ZEPHIR_CONCAT_SV(&_51$$20, "APR", &_50$$20);
									zephir_array_update_zval(&loopPlaceholders, &_51$$20, &_49$$20, PH_COPY | PH_SEPARATE);
								}
							}
							ZEPHIR_CALL_METHOD(&_52$$15, &manager, "load", &_53, 0, &intermediateModelName);
							zephir_check_call_status();
							ZEPHIR_CPY_WRT(&intermediateModel, &_52$$15);
							ZEPHIR_INIT_NVAR(&_54$$15);
							zephir_create_array(&_54$$15, 2, 0);
							ZEPHIR_INIT_NVAR(&_55$$15);
							zephir_fast_join_str(&_55$$15, SL(" AND "), &loopConditions);
							zephir_array_fast_append(&_54$$15, &_55$$15);
							zephir_array_update_string(&_54$$15, SL("bind"), &loopPlaceholders, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(&existingIntermediateModel, &intermediateModel, "findfirst", NULL, 0, &_54$$15);
							zephir_check_call_status();
							if (zephir_is_true(&existingIntermediateModel)) {
								ZEPHIR_CPY_WRT(&intermediateModel, &existingIntermediateModel);
							}
							_56$$15 = !zephir_is_true(&existingIntermediateModel);
							if (!(_56$$15)) {
								ZEPHIR_CALL_METHOD(&_52$$15, &relation, "gettype", &_57, 0);
								zephir_check_call_status();
								_56$$15 = ZEPHIR_IS_LONG_IDENTICAL(&_52$$15, 3);
							}
							if (_56$$15) {
								if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
									_60$$23 = columnCount;
									_59$$23 = 0;
									_58$$23 = 0;
									if (_59$$23 <= _60$$23) {
										while (1) {
											if (_58$$23) {
												_59$$23++;
												if (!(_59$$23 <= _60$$23)) {
													break;
												}
											} else {
												_58$$23 = 1;
											}
											h = _59$$23;
											ZEPHIR_OBS_NVAR(&columnA);
											zephir_array_fetch_long(&columnA, &columns, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5742);
											ZEPHIR_OBS_NVAR(&columnB);
											zephir_array_fetch_long(&columnB, &intermediateFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5743);
											ZEPHIR_OBS_NVAR(&_61$$24);
											zephir_read_property_zval(&_61$$24, this_ptr, &columnA, PH_NOISY_CC);
											zephir_update_property_zval_zval(&intermediateModel, &columnB, &_61$$24);
										}
									}
								} else {
									ZEPHIR_OBS_NVAR(&_62$$25);
									zephir_read_property_zval(&_62$$25, this_ptr, &columns, PH_NOISY_CC);
									zephir_update_property_zval_zval(&intermediateModel, &intermediateFields, &_62$$25);
								}
								if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
									referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
									_65$$26 = referencedFieldsCount;
									_64$$26 = 0;
									_63$$26 = 0;
									if (_64$$26 <= _65$$26) {
										while (1) {
											if (_63$$26) {
												_64$$26++;
												if (!(_64$$26 <= _65$$26)) {
													break;
												}
											} else {
												_63$$26 = 1;
											}
											h = _64$$26;
											ZEPHIR_OBS_NVAR(&columnA);
											zephir_array_fetch_long(&columnA, &referencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5752);
											ZEPHIR_OBS_NVAR(&columnB);
											zephir_array_fetch_long(&columnB, &intermediateReferencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5753);
											ZEPHIR_OBS_NVAR(&_66$$27);
											zephir_read_property_zval(&_66$$27, &recordAfter, &columnA, PH_NOISY_CC);
											zephir_update_property_zval_zval(&intermediateModel, &columnB, &_66$$27);
										}
									}
								} else {
									ZEPHIR_OBS_NVAR(&_67$$28);
									zephir_read_property_zval(&_67$$28, &recordAfter, &referencedFields, PH_NOISY_CC);
									zephir_update_property_zval_zval(&intermediateModel, &intermediateReferencedFields, &_67$$28);
								}
							}
							ZEPHIR_CALL_METHOD(&_68$$15, &intermediateModel, "dosave", NULL, 0, visited);
							zephir_check_call_status();
							if (!(zephir_is_true(&_68$$15))) {
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_33, 0, &intermediateModel);
								zephir_check_call_status();
								if (nesting) {
									ZVAL_BOOL(&_69$$29, 1);
								} else {
									ZVAL_BOOL(&_69$$29, 0);
								}
								ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_70, 0, &_69$$29);
								zephir_check_call_status();
								RETURN_MM_BOOL(0);
							}
							if (doSync) {
								ZEPHIR_INIT_NVAR(&keepKey);
								if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
									ZVAL_STRING(&keepKey, "");
									if (Z_TYPE_P(&referencedFields) == IS_STRING) {
										ZEPHIR_INIT_NVAR(&_72$$31);
										zephir_string_to_char_array(&_72$$31, &referencedFields);
										_71$$31 = &_72$$31;
									} else {
										_71$$31 = &referencedFields;
									}
									zephir_is_iterable(_71$$31, 0, "phalcon/Mvc/Model.zep", 5788);
									if (Z_TYPE_P(_71$$31) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_71$$31), _73$$31)
										{
											ZEPHIR_INIT_NVAR(&columnA);
											ZVAL_COPY(&columnA, _73$$31);
											ZEPHIR_OBS_NVAR(&_74$$32);
											zephir_read_property_zval(&_74$$32, &recordAfter, &columnA, PH_NOISY_CC);
											ZEPHIR_INIT_NVAR(&_75$$32);
											ZEPHIR_CONCAT_VS(&_75$$32, &_74$$32, "|");
											zephir_concat_self(&keepKey, &_75$$32);
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, _71$$31, "rewind", NULL, 0);
										zephir_check_call_status();
										_77$$31 = 1;
										while (1) {
											if (_77$$31) {
												_77$$31 = 0;
											} else {
												ZEPHIR_CALL_METHOD(NULL, _71$$31, "next", NULL, 0);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(&_76$$31, _71$$31, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_76$$31)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&columnA, _71$$31, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_OBS_NVAR(&_78$$33);
												zephir_read_property_zval(&_78$$33, &recordAfter, &columnA, PH_NOISY_CC);
												ZEPHIR_INIT_NVAR(&_79$$33);
												ZEPHIR_CONCAT_VS(&_79$$33, &_78$$33, "|");
												zephir_concat_self(&keepKey, &_79$$33);
										}
									}
									ZEPHIR_INIT_NVAR(&columnA);
								} else {
									ZEPHIR_OBS_NVAR(&_80$$34);
									zephir_read_property_zval(&_80$$34, &recordAfter, &referencedFields, PH_NOISY_CC);
									zephir_cast_to_string(&_81$$34, &_80$$34);
									ZEPHIR_CPY_WRT(&keepKey, &_81$$34);
								}
								zephir_array_update_zval(&keptKeys, &keepKey, &__$true, PH_COPY | PH_SEPARATE);
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _30$$9, "rewind", NULL, 0);
						zephir_check_call_status();
						_83$$9 = 1;
						while (1) {
							if (_83$$9) {
								_83$$9 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _30$$9, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_82$$9, _30$$9, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_82$$9)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&recordAfter, _30$$9, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&_84$$35, &recordAfter, "dosave", NULL, 0, visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_84$$35))) {
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_33, 0, &recordAfter);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_85$$36, 1);
									} else {
										ZVAL_BOOL(&_85$$36, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_86, 0, &_85$$36);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
								ZEPHIR_CPY_WRT(&loopConditions, &conditions);
								ZEPHIR_CPY_WRT(&loopPlaceholders, &placeholders);
								ZEPHIR_CALL_METHOD(&_87$$35, &relation, "gettype", &_88, 0);
								zephir_check_call_status();
								if (ZEPHIR_IS_LONG_IDENTICAL(&_87$$35, 4)) {
									if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
										referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
										_91$$38 = referencedFieldsCount;
										_90$$38 = 0;
										_89$$38 = 0;
										if (_90$$38 <= _91$$38) {
											while (1) {
												if (_89$$38) {
													_90$$38++;
													if (!(_90$$38 <= _91$$38)) {
														break;
													}
												} else {
													_89$$38 = 1;
												}
												j = _90$$38;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &referencedFields, j, PH_NOISY, "phalcon/Mvc/Model.zep", 5705);
												t = (j + i);
												zephir_array_fetch_long(&_92$$39, &intermediateReferencedFields, j, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 5707);
												ZEPHIR_INIT_NVAR(&_93$$39);
												ZVAL_LONG(&_93$$39, t);
												ZEPHIR_INIT_NVAR(&_94$$39);
												ZEPHIR_CONCAT_SVSVS(&_94$$39, "[", &_92$$39, "] = :APR", &_93$$39, ":");
												zephir_array_append(&loopConditions, &_94$$39, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5707);
												ZEPHIR_OBS_NVAR(&_95$$39);
												zephir_read_property_zval(&_95$$39, &recordAfter, &columnA, PH_NOISY_CC);
												ZEPHIR_INIT_NVAR(&_96$$39);
												ZVAL_LONG(&_96$$39, t);
												ZEPHIR_INIT_NVAR(&_97$$39);
												ZEPHIR_CONCAT_SV(&_97$$39, "APR", &_96$$39);
												zephir_array_update_zval(&loopPlaceholders, &_97$$39, &_95$$39, PH_COPY | PH_SEPARATE);
											}
										}
									} else {
										ZEPHIR_INIT_NVAR(&_98$$40);
										ZVAL_LONG(&_98$$40, i);
										ZEPHIR_INIT_NVAR(&_99$$40);
										ZEPHIR_CONCAT_SVSVS(&_99$$40, "[", &intermediateReferencedFields, "] = :APR", &_98$$40, ":");
										zephir_array_append(&loopConditions, &_99$$40, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5711);
										ZEPHIR_OBS_NVAR(&_100$$40);
										zephir_read_property_zval(&_100$$40, &recordAfter, &referencedFields, PH_NOISY_CC);
										ZEPHIR_INIT_NVAR(&_101$$40);
										ZVAL_LONG(&_101$$40, i);
										ZEPHIR_INIT_NVAR(&_102$$40);
										ZEPHIR_CONCAT_SV(&_102$$40, "APR", &_101$$40);
										zephir_array_update_zval(&loopPlaceholders, &_102$$40, &_100$$40, PH_COPY | PH_SEPARATE);
									}
								}
								ZEPHIR_CALL_METHOD(&_103$$35, &manager, "load", &_104, 0, &intermediateModelName);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&intermediateModel, &_103$$35);
								ZEPHIR_INIT_NVAR(&_105$$35);
								zephir_create_array(&_105$$35, 2, 0);
								ZEPHIR_INIT_NVAR(&_106$$35);
								zephir_fast_join_str(&_106$$35, SL(" AND "), &loopConditions);
								zephir_array_fast_append(&_105$$35, &_106$$35);
								zephir_array_update_string(&_105$$35, SL("bind"), &loopPlaceholders, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(&existingIntermediateModel, &intermediateModel, "findfirst", NULL, 0, &_105$$35);
								zephir_check_call_status();
								if (zephir_is_true(&existingIntermediateModel)) {
									ZEPHIR_CPY_WRT(&intermediateModel, &existingIntermediateModel);
								}
								_107$$35 = !zephir_is_true(&existingIntermediateModel);
								if (!(_107$$35)) {
									ZEPHIR_CALL_METHOD(&_103$$35, &relation, "gettype", &_108, 0);
									zephir_check_call_status();
									_107$$35 = ZEPHIR_IS_LONG_IDENTICAL(&_103$$35, 3);
								}
								if (_107$$35) {
									if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
										_111$$43 = columnCount;
										_110$$43 = 0;
										_109$$43 = 0;
										if (_110$$43 <= _111$$43) {
											while (1) {
												if (_109$$43) {
													_110$$43++;
													if (!(_110$$43 <= _111$$43)) {
														break;
													}
												} else {
													_109$$43 = 1;
												}
												h = _110$$43;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &columns, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5742);
												ZEPHIR_OBS_NVAR(&columnB);
												zephir_array_fetch_long(&columnB, &intermediateFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5743);
												ZEPHIR_OBS_NVAR(&_112$$44);
												zephir_read_property_zval(&_112$$44, this_ptr, &columnA, PH_NOISY_CC);
												zephir_update_property_zval_zval(&intermediateModel, &columnB, &_112$$44);
											}
										}
									} else {
										ZEPHIR_OBS_NVAR(&_113$$45);
										zephir_read_property_zval(&_113$$45, this_ptr, &columns, PH_NOISY_CC);
										zephir_update_property_zval_zval(&intermediateModel, &intermediateFields, &_113$$45);
									}
									if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
										referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
										_116$$46 = referencedFieldsCount;
										_115$$46 = 0;
										_114$$46 = 0;
										if (_115$$46 <= _116$$46) {
											while (1) {
												if (_114$$46) {
													_115$$46++;
													if (!(_115$$46 <= _116$$46)) {
														break;
													}
												} else {
													_114$$46 = 1;
												}
												h = _115$$46;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &referencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5752);
												ZEPHIR_OBS_NVAR(&columnB);
												zephir_array_fetch_long(&columnB, &intermediateReferencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5753);
												ZEPHIR_OBS_NVAR(&_117$$47);
												zephir_read_property_zval(&_117$$47, &recordAfter, &columnA, PH_NOISY_CC);
												zephir_update_property_zval_zval(&intermediateModel, &columnB, &_117$$47);
											}
										}
									} else {
										ZEPHIR_OBS_NVAR(&_118$$48);
										zephir_read_property_zval(&_118$$48, &recordAfter, &referencedFields, PH_NOISY_CC);
										zephir_update_property_zval_zval(&intermediateModel, &intermediateReferencedFields, &_118$$48);
									}
								}
								ZEPHIR_CALL_METHOD(&_119$$35, &intermediateModel, "dosave", NULL, 0, visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_119$$35))) {
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_33, 0, &intermediateModel);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_120$$49, 1);
									} else {
										ZVAL_BOOL(&_120$$49, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_121, 0, &_120$$49);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
								if (doSync) {
									if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
										ZVAL_STRING(&keepKey, "");
										if (Z_TYPE_P(&referencedFields) == IS_STRING) {
											ZEPHIR_INIT_NVAR(&_123$$51);
											zephir_string_to_char_array(&_123$$51, &referencedFields);
											_122$$51 = &_123$$51;
										} else {
											_122$$51 = &referencedFields;
										}
										zephir_is_iterable(_122$$51, 0, "phalcon/Mvc/Model.zep", 5788);
										if (Z_TYPE_P(_122$$51) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_122$$51), _124$$51)
											{
												ZEPHIR_INIT_NVAR(&columnA);
												ZVAL_COPY(&columnA, _124$$51);
												ZEPHIR_OBS_NVAR(&_125$$52);
												zephir_read_property_zval(&_125$$52, &recordAfter, &columnA, PH_NOISY_CC);
												ZEPHIR_INIT_NVAR(&_126$$52);
												ZEPHIR_CONCAT_VS(&_126$$52, &_125$$52, "|");
												zephir_concat_self(&keepKey, &_126$$52);
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, _122$$51, "rewind", NULL, 0);
											zephir_check_call_status();
											_128$$51 = 1;
											while (1) {
												if (_128$$51) {
													_128$$51 = 0;
												} else {
													ZEPHIR_CALL_METHOD(NULL, _122$$51, "next", NULL, 0);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD(&_127$$51, _122$$51, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_127$$51)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&columnA, _122$$51, "current", NULL, 0);
												zephir_check_call_status();
													ZEPHIR_OBS_NVAR(&_129$$53);
													zephir_read_property_zval(&_129$$53, &recordAfter, &columnA, PH_NOISY_CC);
													ZEPHIR_INIT_NVAR(&_130$$53);
													ZEPHIR_CONCAT_VS(&_130$$53, &_129$$53, "|");
													zephir_concat_self(&keepKey, &_130$$53);
											}
										}
										ZEPHIR_INIT_NVAR(&columnA);
									} else {
										ZEPHIR_OBS_NVAR(&_131$$54);
										zephir_read_property_zval(&_131$$54, &recordAfter, &referencedFields, PH_NOISY_CC);
										zephir_cast_to_string(&_132$$54, &_131$$54);
										ZEPHIR_CPY_WRT(&keepKey, &_132$$54);
									}
									zephir_array_update_zval(&keptKeys, &keepKey, &__$true, PH_COPY | PH_SEPARATE);
								}
						}
					}
					ZEPHIR_INIT_NVAR(&recordAfter);
					_133$$9 = doSync;
					if (_133$$9) {
						ZEPHIR_CALL_METHOD(&_15$$9, &relation, "gettype", NULL, 0);
						zephir_check_call_status();
						_133$$9 = ZEPHIR_IS_LONG_IDENTICAL(&_15$$9, 4);
					}
					if (_133$$9) {
						ZEPHIR_CALL_METHOD(&_134$$55, &manager, "load", &_135, 0, &intermediateModelName);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&intermediateModel, &_134$$55);
						ZEPHIR_INIT_NVAR(&_136$$55);
						zephir_create_array(&_136$$55, 2, 0);
						ZEPHIR_INIT_NVAR(&_137$$55);
						zephir_fast_join_str(&_137$$55, SL(" AND "), &conditions);
						zephir_array_fast_append(&_136$$55, &_137$$55);
						zephir_array_update_string(&_136$$55, SL("bind"), &placeholders, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD(&existingRecords, &intermediateModel, "find", NULL, 0, &_136$$55);
						zephir_check_call_status();
						if (Z_TYPE_P(&existingRecords) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_137$$55);
							zephir_string_to_char_array(&_137$$55, &existingRecords);
							_138$$55 = &_137$$55;
						} else {
							_138$$55 = &existingRecords;
						}
						zephir_is_iterable(_138$$55, 0, "phalcon/Mvc/Model.zep", 5830);
						if (Z_TYPE_P(_138$$55) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_138$$55), _139$$55)
							{
								ZEPHIR_INIT_NVAR(&existingRecord);
								ZVAL_COPY(&existingRecord, _139$$55);
								if (UNEXPECTED(Z_TYPE_P(&intermediateReferencedFields) == IS_ARRAY)) {
									ZVAL_STRING(&keepKey, "");
									if (Z_TYPE_P(&intermediateReferencedFields) == IS_STRING) {
										ZEPHIR_INIT_NVAR(&_141$$57);
										zephir_string_to_char_array(&_141$$57, &intermediateReferencedFields);
										_140$$57 = &_141$$57;
									} else {
										_140$$57 = &intermediateReferencedFields;
									}
									zephir_is_iterable(_140$$57, 0, "phalcon/Mvc/Model.zep", 5818);
									if (Z_TYPE_P(_140$$57) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_140$$57), _142$$57)
										{
											ZEPHIR_INIT_NVAR(&columnB);
											ZVAL_COPY(&columnB, _142$$57);
											ZEPHIR_OBS_NVAR(&_143$$58);
											zephir_read_property_zval(&_143$$58, &existingRecord, &columnB, PH_NOISY_CC);
											ZEPHIR_INIT_NVAR(&_144$$58);
											ZEPHIR_CONCAT_VS(&_144$$58, &_143$$58, "|");
											zephir_concat_self(&keepKey, &_144$$58);
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, _140$$57, "rewind", NULL, 0);
										zephir_check_call_status();
										_146$$57 = 1;
										while (1) {
											if (_146$$57) {
												_146$$57 = 0;
											} else {
												ZEPHIR_CALL_METHOD(NULL, _140$$57, "next", NULL, 0);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(&_145$$57, _140$$57, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_145$$57)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&columnB, _140$$57, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_OBS_NVAR(&_147$$59);
												zephir_read_property_zval(&_147$$59, &existingRecord, &columnB, PH_NOISY_CC);
												ZEPHIR_INIT_NVAR(&_148$$59);
												ZEPHIR_CONCAT_VS(&_148$$59, &_147$$59, "|");
												zephir_concat_self(&keepKey, &_148$$59);
										}
									}
									ZEPHIR_INIT_NVAR(&columnB);
								} else {
									ZEPHIR_OBS_NVAR(&_149$$60);
									zephir_read_property_zval(&_149$$60, &existingRecord, &intermediateReferencedFields, PH_NOISY_CC);
									zephir_cast_to_string(&_150$$60, &_149$$60);
									ZEPHIR_CPY_WRT(&keepKey, &_150$$60);
								}
								_151$$56 = !(zephir_array_isset_value(&keptKeys, &keepKey));
								if (_151$$56) {
									ZEPHIR_CALL_METHOD(&_152$$56, &existingRecord, "delete", NULL, 0);
									zephir_check_call_status();
									_151$$56 = !zephir_is_true(&_152$$56);
								}
								if (_151$$56) {
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_33, 0, &existingRecord);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_153$$61, 1);
									} else {
										ZVAL_BOOL(&_153$$61, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_154, 0, &_153$$61);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _138$$55, "rewind", NULL, 0);
							zephir_check_call_status();
							_156$$55 = 1;
							while (1) {
								if (_156$$55) {
									_156$$55 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _138$$55, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_155$$55, _138$$55, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_155$$55)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&existingRecord, _138$$55, "current", NULL, 0);
								zephir_check_call_status();
									if (UNEXPECTED(Z_TYPE_P(&intermediateReferencedFields) == IS_ARRAY)) {
										ZVAL_STRING(&keepKey, "");
										if (Z_TYPE_P(&intermediateReferencedFields) == IS_STRING) {
											ZEPHIR_INIT_NVAR(&_158$$63);
											zephir_string_to_char_array(&_158$$63, &intermediateReferencedFields);
											_157$$63 = &_158$$63;
										} else {
											_157$$63 = &intermediateReferencedFields;
										}
										zephir_is_iterable(_157$$63, 0, "phalcon/Mvc/Model.zep", 5818);
										if (Z_TYPE_P(_157$$63) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_157$$63), _159$$63)
											{
												ZEPHIR_INIT_NVAR(&columnB);
												ZVAL_COPY(&columnB, _159$$63);
												ZEPHIR_OBS_NVAR(&_160$$64);
												zephir_read_property_zval(&_160$$64, &existingRecord, &columnB, PH_NOISY_CC);
												ZEPHIR_INIT_NVAR(&_161$$64);
												ZEPHIR_CONCAT_VS(&_161$$64, &_160$$64, "|");
												zephir_concat_self(&keepKey, &_161$$64);
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, _157$$63, "rewind", NULL, 0);
											zephir_check_call_status();
											_163$$63 = 1;
											while (1) {
												if (_163$$63) {
													_163$$63 = 0;
												} else {
													ZEPHIR_CALL_METHOD(NULL, _157$$63, "next", NULL, 0);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD(&_162$$63, _157$$63, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_162$$63)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&columnB, _157$$63, "current", NULL, 0);
												zephir_check_call_status();
													ZEPHIR_OBS_NVAR(&_164$$65);
													zephir_read_property_zval(&_164$$65, &existingRecord, &columnB, PH_NOISY_CC);
													ZEPHIR_INIT_NVAR(&_165$$65);
													ZEPHIR_CONCAT_VS(&_165$$65, &_164$$65, "|");
													zephir_concat_self(&keepKey, &_165$$65);
											}
										}
										ZEPHIR_INIT_NVAR(&columnB);
									} else {
										ZEPHIR_OBS_NVAR(&_166$$66);
										zephir_read_property_zval(&_166$$66, &existingRecord, &intermediateReferencedFields, PH_NOISY_CC);
										zephir_cast_to_string(&_167$$66, &_166$$66);
										ZEPHIR_CPY_WRT(&keepKey, &_167$$66);
									}
									_168$$62 = !(zephir_array_isset_value(&keptKeys, &keepKey));
									if (_168$$62) {
										ZEPHIR_CALL_METHOD(&_169$$62, &existingRecord, "delete", NULL, 0);
										zephir_check_call_status();
										_168$$62 = !zephir_is_true(&_169$$62);
									}
									if (_168$$62) {
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_33, 0, &existingRecord);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_170$$67, 1);
										} else {
											ZVAL_BOOL(&_170$$67, 0);
										}
										ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_171, 0, &_170$$67);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
							}
						}
						ZEPHIR_INIT_NVAR(&existingRecord);
					}
				} else {
					if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
						columnCount = (zephir_fast_count_int(&columns) - 1);
						if (Z_TYPE_P(&relatedRecords) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_173$$69);
							zephir_string_to_char_array(&_173$$69, &relatedRecords);
							_172$$69 = &_173$$69;
						} else {
							_172$$69 = &relatedRecords;
						}
						zephir_is_iterable(_172$$69, 0, "phalcon/Mvc/Model.zep", 5858);
						if (Z_TYPE_P(_172$$69) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_172$$69), _174$$69)
							{
								ZEPHIR_INIT_NVAR(&recordAfter);
								ZVAL_COPY(&recordAfter, _174$$69);
								_177$$70 = columnCount;
								_176$$70 = 0;
								_175$$70 = 0;
								if (_176$$70 <= _177$$70) {
									while (1) {
										if (_175$$70) {
											_176$$70++;
											if (!(_176$$70 <= _177$$70)) {
												break;
											}
										} else {
											_175$$70 = 1;
										}
										i = _176$$70;
										ZEPHIR_OBS_NVAR(&columnA);
										zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5836);
										ZEPHIR_OBS_NVAR(&columnB);
										zephir_array_fetch_long(&columnB, &referencedFields, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5837);
										ZEPHIR_OBS_NVAR(&_178$$71);
										zephir_read_property_zval(&_178$$71, this_ptr, &columnA, PH_NOISY_CC);
										zephir_update_property_zval_zval(&recordAfter, &columnB, &_178$$71);
									}
								}
								ZEPHIR_CALL_METHOD(&_179$$70, &recordAfter, "dosave", NULL, 0, visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_179$$70))) {
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_33, 0, &recordAfter);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_180$$72, 1);
									} else {
										ZVAL_BOOL(&_180$$72, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_181, 0, &_180$$72);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _172$$69, "rewind", NULL, 0);
							zephir_check_call_status();
							_183$$69 = 1;
							while (1) {
								if (_183$$69) {
									_183$$69 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _172$$69, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_182$$69, _172$$69, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_182$$69)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&recordAfter, _172$$69, "current", NULL, 0);
								zephir_check_call_status();
									_186$$73 = columnCount;
									_185$$73 = 0;
									_184$$73 = 0;
									if (_185$$73 <= _186$$73) {
										while (1) {
											if (_184$$73) {
												_185$$73++;
												if (!(_185$$73 <= _186$$73)) {
													break;
												}
											} else {
												_184$$73 = 1;
											}
											i = _185$$73;
											ZEPHIR_OBS_NVAR(&columnA);
											zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5836);
											ZEPHIR_OBS_NVAR(&columnB);
											zephir_array_fetch_long(&columnB, &referencedFields, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5837);
											ZEPHIR_OBS_NVAR(&_187$$74);
											zephir_read_property_zval(&_187$$74, this_ptr, &columnA, PH_NOISY_CC);
											zephir_update_property_zval_zval(&recordAfter, &columnB, &_187$$74);
										}
									}
									ZEPHIR_CALL_METHOD(&_188$$73, &recordAfter, "dosave", NULL, 0, visited);
									zephir_check_call_status();
									if (!(zephir_is_true(&_188$$73))) {
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_33, 0, &recordAfter);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_189$$75, 1);
										} else {
											ZVAL_BOOL(&_189$$75, 0);
										}
										ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_190, 0, &_189$$75);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
							}
						}
						ZEPHIR_INIT_NVAR(&recordAfter);
					} else {
						if (Z_TYPE_P(&relatedRecords) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_192$$76);
							zephir_string_to_char_array(&_192$$76, &relatedRecords);
							_191$$76 = &_192$$76;
						} else {
							_191$$76 = &relatedRecords;
						}
						zephir_is_iterable(_191$$76, 0, "phalcon/Mvc/Model.zep", 5883);
						if (Z_TYPE_P(_191$$76) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_191$$76), _193$$76)
							{
								ZEPHIR_INIT_NVAR(&recordAfter);
								ZVAL_COPY(&recordAfter, _193$$76);
								ZEPHIR_OBS_NVAR(&_194$$77);
								zephir_read_property_zval(&_194$$77, this_ptr, &columns, PH_NOISY_CC);
								zephir_update_property_zval_zval(&recordAfter, &referencedFields, &_194$$77);
								ZEPHIR_CALL_METHOD(&_195$$77, &recordAfter, "dosave", NULL, 0, visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_195$$77))) {
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_33, 0, &recordAfter);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_196$$78, 1);
									} else {
										ZVAL_BOOL(&_196$$78, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_197, 0, &_196$$78);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _191$$76, "rewind", NULL, 0);
							zephir_check_call_status();
							_199$$76 = 1;
							while (1) {
								if (_199$$76) {
									_199$$76 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _191$$76, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_198$$76, _191$$76, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_198$$76)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&recordAfter, _191$$76, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_OBS_NVAR(&_200$$79);
									zephir_read_property_zval(&_200$$79, this_ptr, &columns, PH_NOISY_CC);
									zephir_update_property_zval_zval(&recordAfter, &referencedFields, &_200$$79);
									ZEPHIR_CALL_METHOD(&_201$$79, &recordAfter, "dosave", NULL, 0, visited);
									zephir_check_call_status();
									if (!(zephir_is_true(&_201$$79))) {
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_33, 0, &recordAfter);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_202$$80, 1);
										} else {
											ZVAL_BOOL(&_202$$80, 0);
										}
										ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_203, 0, &_202$$80);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
							}
						}
						ZEPHIR_INIT_NVAR(&recordAfter);
					}
				}
			} else {
				if (UNEXPECTED(Z_TYPE_P(&record) != IS_ARRAY)) {
					if (nesting) {
						ZVAL_BOOL(&_204$$82, 1);
					} else {
						ZVAL_BOOL(&_204$$82, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_205, 0, &_204$$82);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_206$$82);
					object_init_ex(&_206$$82, phalcon_mvc_model_exceptions_relationnotdefined_ce);
					ZEPHIR_CALL_METHOD(NULL, &_206$$82, "__construct", &_207, 0, &className, &name);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_206$$82, "phalcon/Mvc/Model.zep", 5889);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_209 = 1;
		while (1) {
			if (_209) {
				_209 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_208, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_208)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, _1, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&record, _1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_210$$83, &manager, "getrelationbyalias", &_211, 0, &className, &name);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&relation, &_210$$83);
				if (Z_TYPE_P(&relation) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&_212$$84, &relation, "gettype", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG(&_212$$84, 0)) {
						continue;
					}
					_213$$84 = Z_TYPE_P(&record) != IS_OBJECT;
					if (_213$$84) {
						_213$$84 = Z_TYPE_P(&record) != IS_ARRAY;
					}
					if (UNEXPECTED(_213$$84)) {
						if (nesting) {
							ZVAL_BOOL(&_214$$86, 1);
						} else {
							ZVAL_BOOL(&_214$$86, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_215, 0, &_214$$86);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_216$$86);
						object_init_ex(&_216$$86, phalcon_mvc_model_exceptions_relationrequiresobjectorarray_ce);
						ZEPHIR_CALL_METHOD(NULL, &_216$$86, "__construct", &_13, 0, &className, &name);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_216$$86, "phalcon/Mvc/Model.zep", 5617);
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
						ZEPHIR_INIT_NVAR(&_217$$87);
						zephir_create_array(&_217$$87, 1, 0);
						zephir_array_fast_append(&_217$$87, &record);
						ZEPHIR_CPY_WRT(&relatedRecords, &_217$$87);
					} else {
						ZEPHIR_CPY_WRT(&relatedRecords, &record);
					}
					ZEPHIR_CALL_METHOD(&_218$$84, &relation, "isthrough", NULL, 0);
					zephir_check_call_status();
					isThrough = zephir_get_boolval(&_218$$84);
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
						ZEPHIR_INIT_NVAR(&keptKeys);
						array_init(&keptKeys);
						ZEPHIR_INIT_NVAR(&_220$$89);
						ZVAL_STRING(&_220$$89, "sync");
						ZEPHIR_CALL_METHOD(&_219$$89, &relation, "getoption", NULL, 0, &_220$$89);
						zephir_check_call_status();
						doSync = zephir_get_boolval(&_219$$89);
						ZEPHIR_OBS_NVAR(&override);
						zephir_read_property_cached(&_221$$89, this_ptr, _zephir_prop_0, 1011, PH_NOISY_CC | PH_READONLY);
						if (zephir_array_isset_fetch(&override, &_221$$89, &name, 0)) {
							doSync = zephir_get_boolval(&override);
						} else {
							ZEPHIR_OBS_NVAR(&override);
							zephir_read_property_cached(&_222$$89, this_ptr, _zephir_prop_0, 1011, PH_NOISY_CC | PH_READONLY);
							if (zephir_array_isset_string_fetch(&override, &_222$$89, SL("*"), 0)) {
								doSync = zephir_get_boolval(&override);
							}
						}
						if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
							columnCount = (zephir_fast_count_int(&columns) - 1);
							_225$$92 = columnCount;
							_224$$92 = 0;
							_223$$92 = 0;
							if (_224$$92 <= _225$$92) {
								while (1) {
									if (_223$$92) {
										_224$$92++;
										if (!(_224$$92 <= _225$$92)) {
											break;
										}
									} else {
										_223$$92 = 1;
									}
									i = _224$$92;
									ZEPHIR_OBS_NVAR(&columnA);
									zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5664);
									zephir_array_fetch_long(&_226$$93, &intermediateFields, i, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 5665);
									ZEPHIR_INIT_NVAR(&_227$$93);
									ZVAL_LONG(&_227$$93, i);
									ZEPHIR_INIT_NVAR(&_228$$93);
									ZEPHIR_CONCAT_SVSVS(&_228$$93, "[", &_226$$93, "] = :APR", &_227$$93, ":");
									zephir_array_append(&conditions, &_228$$93, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5665);
									ZEPHIR_OBS_NVAR(&_229$$93);
									zephir_read_property_zval(&_229$$93, this_ptr, &columnA, PH_NOISY_CC);
									ZEPHIR_INIT_NVAR(&_230$$93);
									ZVAL_LONG(&_230$$93, i);
									ZEPHIR_INIT_NVAR(&_231$$93);
									ZEPHIR_CONCAT_SV(&_231$$93, "APR", &_230$$93);
									zephir_array_update_zval(&placeholders, &_231$$93, &_229$$93, PH_COPY | PH_SEPARATE);
								}
							}
							i = (columnCount + 1);
						} else {
							ZEPHIR_INIT_NVAR(&_232$$94);
							ZEPHIR_CONCAT_SVS(&_232$$94, "[", &intermediateFields, "] = :APR0:");
							zephir_array_append(&conditions, &_232$$94, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5670);
							ZEPHIR_OBS_NVAR(&_233$$94);
							zephir_read_property_zval(&_233$$94, this_ptr, &columns, PH_NOISY_CC);
							zephir_array_update_string(&placeholders, SL("APR0"), &_233$$94, PH_COPY | PH_SEPARATE);
							i = 1;
						}
						if (Z_TYPE_P(&relatedRecords) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_220$$89);
							zephir_string_to_char_array(&_220$$89, &relatedRecords);
							_234$$89 = &_220$$89;
						} else {
							_234$$89 = &relatedRecords;
						}
						zephir_is_iterable(_234$$89, 0, "phalcon/Mvc/Model.zep", 5800);
						if (Z_TYPE_P(_234$$89) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_234$$89), _235$$89)
							{
								ZEPHIR_INIT_NVAR(&recordAfter);
								ZVAL_COPY(&recordAfter, _235$$89);
								ZEPHIR_CALL_METHOD(&_236$$95, &recordAfter, "dosave", NULL, 0, visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_236$$95))) {
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_33, 0, &recordAfter);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_237$$96, 1);
									} else {
										ZVAL_BOOL(&_237$$96, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_238, 0, &_237$$96);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
								ZEPHIR_CPY_WRT(&loopConditions, &conditions);
								ZEPHIR_CPY_WRT(&loopPlaceholders, &placeholders);
								ZEPHIR_CALL_METHOD(&_239$$95, &relation, "gettype", &_240, 0);
								zephir_check_call_status();
								if (ZEPHIR_IS_LONG_IDENTICAL(&_239$$95, 4)) {
									if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
										referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
										_243$$98 = referencedFieldsCount;
										_242$$98 = 0;
										_241$$98 = 0;
										if (_242$$98 <= _243$$98) {
											while (1) {
												if (_241$$98) {
													_242$$98++;
													if (!(_242$$98 <= _243$$98)) {
														break;
													}
												} else {
													_241$$98 = 1;
												}
												j = _242$$98;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &referencedFields, j, PH_NOISY, "phalcon/Mvc/Model.zep", 5705);
												t = (j + i);
												zephir_array_fetch_long(&_244$$99, &intermediateReferencedFields, j, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 5707);
												ZEPHIR_INIT_NVAR(&_245$$99);
												ZVAL_LONG(&_245$$99, t);
												ZEPHIR_INIT_NVAR(&_246$$99);
												ZEPHIR_CONCAT_SVSVS(&_246$$99, "[", &_244$$99, "] = :APR", &_245$$99, ":");
												zephir_array_append(&loopConditions, &_246$$99, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5707);
												ZEPHIR_OBS_NVAR(&_247$$99);
												zephir_read_property_zval(&_247$$99, &recordAfter, &columnA, PH_NOISY_CC);
												ZEPHIR_INIT_NVAR(&_248$$99);
												ZVAL_LONG(&_248$$99, t);
												ZEPHIR_INIT_NVAR(&_249$$99);
												ZEPHIR_CONCAT_SV(&_249$$99, "APR", &_248$$99);
												zephir_array_update_zval(&loopPlaceholders, &_249$$99, &_247$$99, PH_COPY | PH_SEPARATE);
											}
										}
									} else {
										ZEPHIR_INIT_NVAR(&_250$$100);
										ZVAL_LONG(&_250$$100, i);
										ZEPHIR_INIT_NVAR(&_251$$100);
										ZEPHIR_CONCAT_SVSVS(&_251$$100, "[", &intermediateReferencedFields, "] = :APR", &_250$$100, ":");
										zephir_array_append(&loopConditions, &_251$$100, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5711);
										ZEPHIR_OBS_NVAR(&_252$$100);
										zephir_read_property_zval(&_252$$100, &recordAfter, &referencedFields, PH_NOISY_CC);
										ZEPHIR_INIT_NVAR(&_253$$100);
										ZVAL_LONG(&_253$$100, i);
										ZEPHIR_INIT_NVAR(&_254$$100);
										ZEPHIR_CONCAT_SV(&_254$$100, "APR", &_253$$100);
										zephir_array_update_zval(&loopPlaceholders, &_254$$100, &_252$$100, PH_COPY | PH_SEPARATE);
									}
								}
								ZEPHIR_CALL_METHOD(&_255$$95, &manager, "load", &_256, 0, &intermediateModelName);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&intermediateModel, &_255$$95);
								ZEPHIR_INIT_NVAR(&_257$$95);
								zephir_create_array(&_257$$95, 2, 0);
								ZEPHIR_INIT_NVAR(&_258$$95);
								zephir_fast_join_str(&_258$$95, SL(" AND "), &loopConditions);
								zephir_array_fast_append(&_257$$95, &_258$$95);
								zephir_array_update_string(&_257$$95, SL("bind"), &loopPlaceholders, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(&existingIntermediateModel, &intermediateModel, "findfirst", NULL, 0, &_257$$95);
								zephir_check_call_status();
								if (zephir_is_true(&existingIntermediateModel)) {
									ZEPHIR_CPY_WRT(&intermediateModel, &existingIntermediateModel);
								}
								_259$$95 = !zephir_is_true(&existingIntermediateModel);
								if (!(_259$$95)) {
									ZEPHIR_CALL_METHOD(&_255$$95, &relation, "gettype", &_260, 0);
									zephir_check_call_status();
									_259$$95 = ZEPHIR_IS_LONG_IDENTICAL(&_255$$95, 3);
								}
								if (_259$$95) {
									if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
										_263$$103 = columnCount;
										_262$$103 = 0;
										_261$$103 = 0;
										if (_262$$103 <= _263$$103) {
											while (1) {
												if (_261$$103) {
													_262$$103++;
													if (!(_262$$103 <= _263$$103)) {
														break;
													}
												} else {
													_261$$103 = 1;
												}
												h = _262$$103;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &columns, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5742);
												ZEPHIR_OBS_NVAR(&columnB);
												zephir_array_fetch_long(&columnB, &intermediateFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5743);
												ZEPHIR_OBS_NVAR(&_264$$104);
												zephir_read_property_zval(&_264$$104, this_ptr, &columnA, PH_NOISY_CC);
												zephir_update_property_zval_zval(&intermediateModel, &columnB, &_264$$104);
											}
										}
									} else {
										ZEPHIR_OBS_NVAR(&_265$$105);
										zephir_read_property_zval(&_265$$105, this_ptr, &columns, PH_NOISY_CC);
										zephir_update_property_zval_zval(&intermediateModel, &intermediateFields, &_265$$105);
									}
									if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
										referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
										_268$$106 = referencedFieldsCount;
										_267$$106 = 0;
										_266$$106 = 0;
										if (_267$$106 <= _268$$106) {
											while (1) {
												if (_266$$106) {
													_267$$106++;
													if (!(_267$$106 <= _268$$106)) {
														break;
													}
												} else {
													_266$$106 = 1;
												}
												h = _267$$106;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &referencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5752);
												ZEPHIR_OBS_NVAR(&columnB);
												zephir_array_fetch_long(&columnB, &intermediateReferencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5753);
												ZEPHIR_OBS_NVAR(&_269$$107);
												zephir_read_property_zval(&_269$$107, &recordAfter, &columnA, PH_NOISY_CC);
												zephir_update_property_zval_zval(&intermediateModel, &columnB, &_269$$107);
											}
										}
									} else {
										ZEPHIR_OBS_NVAR(&_270$$108);
										zephir_read_property_zval(&_270$$108, &recordAfter, &referencedFields, PH_NOISY_CC);
										zephir_update_property_zval_zval(&intermediateModel, &intermediateReferencedFields, &_270$$108);
									}
								}
								ZEPHIR_CALL_METHOD(&_271$$95, &intermediateModel, "dosave", NULL, 0, visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_271$$95))) {
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_33, 0, &intermediateModel);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_272$$109, 1);
									} else {
										ZVAL_BOOL(&_272$$109, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_273, 0, &_272$$109);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
								if (doSync) {
									if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
										ZVAL_STRING(&keepKey, "");
										if (Z_TYPE_P(&referencedFields) == IS_STRING) {
											ZEPHIR_INIT_NVAR(&_275$$111);
											zephir_string_to_char_array(&_275$$111, &referencedFields);
											_274$$111 = &_275$$111;
										} else {
											_274$$111 = &referencedFields;
										}
										zephir_is_iterable(_274$$111, 0, "phalcon/Mvc/Model.zep", 5788);
										if (Z_TYPE_P(_274$$111) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_274$$111), _276$$111)
											{
												ZEPHIR_INIT_NVAR(&columnA);
												ZVAL_COPY(&columnA, _276$$111);
												ZEPHIR_OBS_NVAR(&_277$$112);
												zephir_read_property_zval(&_277$$112, &recordAfter, &columnA, PH_NOISY_CC);
												ZEPHIR_INIT_NVAR(&_278$$112);
												ZEPHIR_CONCAT_VS(&_278$$112, &_277$$112, "|");
												zephir_concat_self(&keepKey, &_278$$112);
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, _274$$111, "rewind", NULL, 0);
											zephir_check_call_status();
											_280$$111 = 1;
											while (1) {
												if (_280$$111) {
													_280$$111 = 0;
												} else {
													ZEPHIR_CALL_METHOD(NULL, _274$$111, "next", NULL, 0);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD(&_279$$111, _274$$111, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_279$$111)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&columnA, _274$$111, "current", NULL, 0);
												zephir_check_call_status();
													ZEPHIR_OBS_NVAR(&_281$$113);
													zephir_read_property_zval(&_281$$113, &recordAfter, &columnA, PH_NOISY_CC);
													ZEPHIR_INIT_NVAR(&_282$$113);
													ZEPHIR_CONCAT_VS(&_282$$113, &_281$$113, "|");
													zephir_concat_self(&keepKey, &_282$$113);
											}
										}
										ZEPHIR_INIT_NVAR(&columnA);
									} else {
										ZEPHIR_OBS_NVAR(&_283$$114);
										zephir_read_property_zval(&_283$$114, &recordAfter, &referencedFields, PH_NOISY_CC);
										zephir_cast_to_string(&_284$$114, &_283$$114);
										ZEPHIR_CPY_WRT(&keepKey, &_284$$114);
									}
									zephir_array_update_zval(&keptKeys, &keepKey, &__$true, PH_COPY | PH_SEPARATE);
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _234$$89, "rewind", NULL, 0);
							zephir_check_call_status();
							_286$$89 = 1;
							while (1) {
								if (_286$$89) {
									_286$$89 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _234$$89, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_285$$89, _234$$89, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_285$$89)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&recordAfter, _234$$89, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&_287$$115, &recordAfter, "dosave", NULL, 0, visited);
									zephir_check_call_status();
									if (!(zephir_is_true(&_287$$115))) {
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_33, 0, &recordAfter);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_288$$116, 1);
										} else {
											ZVAL_BOOL(&_288$$116, 0);
										}
										ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_289, 0, &_288$$116);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
									ZEPHIR_CPY_WRT(&loopConditions, &conditions);
									ZEPHIR_CPY_WRT(&loopPlaceholders, &placeholders);
									ZEPHIR_CALL_METHOD(&_290$$115, &relation, "gettype", &_291, 0);
									zephir_check_call_status();
									if (ZEPHIR_IS_LONG_IDENTICAL(&_290$$115, 4)) {
										if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
											referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
											_294$$118 = referencedFieldsCount;
											_293$$118 = 0;
											_292$$118 = 0;
											if (_293$$118 <= _294$$118) {
												while (1) {
													if (_292$$118) {
														_293$$118++;
														if (!(_293$$118 <= _294$$118)) {
															break;
														}
													} else {
														_292$$118 = 1;
													}
													j = _293$$118;
													ZEPHIR_OBS_NVAR(&columnA);
													zephir_array_fetch_long(&columnA, &referencedFields, j, PH_NOISY, "phalcon/Mvc/Model.zep", 5705);
													t = (j + i);
													zephir_array_fetch_long(&_295$$119, &intermediateReferencedFields, j, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 5707);
													ZEPHIR_INIT_NVAR(&_296$$119);
													ZVAL_LONG(&_296$$119, t);
													ZEPHIR_INIT_NVAR(&_297$$119);
													ZEPHIR_CONCAT_SVSVS(&_297$$119, "[", &_295$$119, "] = :APR", &_296$$119, ":");
													zephir_array_append(&loopConditions, &_297$$119, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5707);
													ZEPHIR_OBS_NVAR(&_298$$119);
													zephir_read_property_zval(&_298$$119, &recordAfter, &columnA, PH_NOISY_CC);
													ZEPHIR_INIT_NVAR(&_299$$119);
													ZVAL_LONG(&_299$$119, t);
													ZEPHIR_INIT_NVAR(&_300$$119);
													ZEPHIR_CONCAT_SV(&_300$$119, "APR", &_299$$119);
													zephir_array_update_zval(&loopPlaceholders, &_300$$119, &_298$$119, PH_COPY | PH_SEPARATE);
												}
											}
										} else {
											ZEPHIR_INIT_NVAR(&_301$$120);
											ZVAL_LONG(&_301$$120, i);
											ZEPHIR_INIT_NVAR(&_302$$120);
											ZEPHIR_CONCAT_SVSVS(&_302$$120, "[", &intermediateReferencedFields, "] = :APR", &_301$$120, ":");
											zephir_array_append(&loopConditions, &_302$$120, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5711);
											ZEPHIR_OBS_NVAR(&_303$$120);
											zephir_read_property_zval(&_303$$120, &recordAfter, &referencedFields, PH_NOISY_CC);
											ZEPHIR_INIT_NVAR(&_304$$120);
											ZVAL_LONG(&_304$$120, i);
											ZEPHIR_INIT_NVAR(&_305$$120);
											ZEPHIR_CONCAT_SV(&_305$$120, "APR", &_304$$120);
											zephir_array_update_zval(&loopPlaceholders, &_305$$120, &_303$$120, PH_COPY | PH_SEPARATE);
										}
									}
									ZEPHIR_CALL_METHOD(&_306$$115, &manager, "load", &_307, 0, &intermediateModelName);
									zephir_check_call_status();
									ZEPHIR_CPY_WRT(&intermediateModel, &_306$$115);
									ZEPHIR_INIT_NVAR(&_308$$115);
									zephir_create_array(&_308$$115, 2, 0);
									ZEPHIR_INIT_NVAR(&_309$$115);
									zephir_fast_join_str(&_309$$115, SL(" AND "), &loopConditions);
									zephir_array_fast_append(&_308$$115, &_309$$115);
									zephir_array_update_string(&_308$$115, SL("bind"), &loopPlaceholders, PH_COPY | PH_SEPARATE);
									ZEPHIR_CALL_METHOD(&existingIntermediateModel, &intermediateModel, "findfirst", NULL, 0, &_308$$115);
									zephir_check_call_status();
									if (zephir_is_true(&existingIntermediateModel)) {
										ZEPHIR_CPY_WRT(&intermediateModel, &existingIntermediateModel);
									}
									_310$$115 = !zephir_is_true(&existingIntermediateModel);
									if (!(_310$$115)) {
										ZEPHIR_CALL_METHOD(&_306$$115, &relation, "gettype", &_311, 0);
										zephir_check_call_status();
										_310$$115 = ZEPHIR_IS_LONG_IDENTICAL(&_306$$115, 3);
									}
									if (_310$$115) {
										if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
											_314$$123 = columnCount;
											_313$$123 = 0;
											_312$$123 = 0;
											if (_313$$123 <= _314$$123) {
												while (1) {
													if (_312$$123) {
														_313$$123++;
														if (!(_313$$123 <= _314$$123)) {
															break;
														}
													} else {
														_312$$123 = 1;
													}
													h = _313$$123;
													ZEPHIR_OBS_NVAR(&columnA);
													zephir_array_fetch_long(&columnA, &columns, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5742);
													ZEPHIR_OBS_NVAR(&columnB);
													zephir_array_fetch_long(&columnB, &intermediateFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5743);
													ZEPHIR_OBS_NVAR(&_315$$124);
													zephir_read_property_zval(&_315$$124, this_ptr, &columnA, PH_NOISY_CC);
													zephir_update_property_zval_zval(&intermediateModel, &columnB, &_315$$124);
												}
											}
										} else {
											ZEPHIR_OBS_NVAR(&_316$$125);
											zephir_read_property_zval(&_316$$125, this_ptr, &columns, PH_NOISY_CC);
											zephir_update_property_zval_zval(&intermediateModel, &intermediateFields, &_316$$125);
										}
										if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
											referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
											_319$$126 = referencedFieldsCount;
											_318$$126 = 0;
											_317$$126 = 0;
											if (_318$$126 <= _319$$126) {
												while (1) {
													if (_317$$126) {
														_318$$126++;
														if (!(_318$$126 <= _319$$126)) {
															break;
														}
													} else {
														_317$$126 = 1;
													}
													h = _318$$126;
													ZEPHIR_OBS_NVAR(&columnA);
													zephir_array_fetch_long(&columnA, &referencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5752);
													ZEPHIR_OBS_NVAR(&columnB);
													zephir_array_fetch_long(&columnB, &intermediateReferencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5753);
													ZEPHIR_OBS_NVAR(&_320$$127);
													zephir_read_property_zval(&_320$$127, &recordAfter, &columnA, PH_NOISY_CC);
													zephir_update_property_zval_zval(&intermediateModel, &columnB, &_320$$127);
												}
											}
										} else {
											ZEPHIR_OBS_NVAR(&_321$$128);
											zephir_read_property_zval(&_321$$128, &recordAfter, &referencedFields, PH_NOISY_CC);
											zephir_update_property_zval_zval(&intermediateModel, &intermediateReferencedFields, &_321$$128);
										}
									}
									ZEPHIR_CALL_METHOD(&_322$$115, &intermediateModel, "dosave", NULL, 0, visited);
									zephir_check_call_status();
									if (!(zephir_is_true(&_322$$115))) {
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_33, 0, &intermediateModel);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_323$$129, 1);
										} else {
											ZVAL_BOOL(&_323$$129, 0);
										}
										ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_324, 0, &_323$$129);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
									if (doSync) {
										if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
											ZVAL_STRING(&keepKey, "");
											if (Z_TYPE_P(&referencedFields) == IS_STRING) {
												ZEPHIR_INIT_NVAR(&_326$$131);
												zephir_string_to_char_array(&_326$$131, &referencedFields);
												_325$$131 = &_326$$131;
											} else {
												_325$$131 = &referencedFields;
											}
											zephir_is_iterable(_325$$131, 0, "phalcon/Mvc/Model.zep", 5788);
											if (Z_TYPE_P(_325$$131) == IS_ARRAY) {
												ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_325$$131), _327$$131)
												{
													ZEPHIR_INIT_NVAR(&columnA);
													ZVAL_COPY(&columnA, _327$$131);
													ZEPHIR_OBS_NVAR(&_328$$132);
													zephir_read_property_zval(&_328$$132, &recordAfter, &columnA, PH_NOISY_CC);
													ZEPHIR_INIT_NVAR(&_329$$132);
													ZEPHIR_CONCAT_VS(&_329$$132, &_328$$132, "|");
													zephir_concat_self(&keepKey, &_329$$132);
												} ZEND_HASH_FOREACH_END();
											} else {
												ZEPHIR_CALL_METHOD(NULL, _325$$131, "rewind", NULL, 0);
												zephir_check_call_status();
												_331$$131 = 1;
												while (1) {
													if (_331$$131) {
														_331$$131 = 0;
													} else {
														ZEPHIR_CALL_METHOD(NULL, _325$$131, "next", NULL, 0);
														zephir_check_call_status();
													}
													ZEPHIR_CALL_METHOD(&_330$$131, _325$$131, "valid", NULL, 0);
													zephir_check_call_status();
													if (!zend_is_true(&_330$$131)) {
														break;
													}
													ZEPHIR_CALL_METHOD(&columnA, _325$$131, "current", NULL, 0);
													zephir_check_call_status();
														ZEPHIR_OBS_NVAR(&_332$$133);
														zephir_read_property_zval(&_332$$133, &recordAfter, &columnA, PH_NOISY_CC);
														ZEPHIR_INIT_NVAR(&_333$$133);
														ZEPHIR_CONCAT_VS(&_333$$133, &_332$$133, "|");
														zephir_concat_self(&keepKey, &_333$$133);
												}
											}
											ZEPHIR_INIT_NVAR(&columnA);
										} else {
											ZEPHIR_OBS_NVAR(&_334$$134);
											zephir_read_property_zval(&_334$$134, &recordAfter, &referencedFields, PH_NOISY_CC);
											zephir_cast_to_string(&_335$$134, &_334$$134);
											ZEPHIR_CPY_WRT(&keepKey, &_335$$134);
										}
										zephir_array_update_zval(&keptKeys, &keepKey, &__$true, PH_COPY | PH_SEPARATE);
									}
							}
						}
						ZEPHIR_INIT_NVAR(&recordAfter);
						_336$$89 = doSync;
						if (_336$$89) {
							ZEPHIR_CALL_METHOD(&_219$$89, &relation, "gettype", NULL, 0);
							zephir_check_call_status();
							_336$$89 = ZEPHIR_IS_LONG_IDENTICAL(&_219$$89, 4);
						}
						if (_336$$89) {
							ZEPHIR_CALL_METHOD(&_337$$135, &manager, "load", &_338, 0, &intermediateModelName);
							zephir_check_call_status();
							ZEPHIR_CPY_WRT(&intermediateModel, &_337$$135);
							ZEPHIR_INIT_NVAR(&_339$$135);
							zephir_create_array(&_339$$135, 2, 0);
							ZEPHIR_INIT_NVAR(&_340$$135);
							zephir_fast_join_str(&_340$$135, SL(" AND "), &conditions);
							zephir_array_fast_append(&_339$$135, &_340$$135);
							zephir_array_update_string(&_339$$135, SL("bind"), &placeholders, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(&existingRecords, &intermediateModel, "find", NULL, 0, &_339$$135);
							zephir_check_call_status();
							if (Z_TYPE_P(&existingRecords) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_340$$135);
								zephir_string_to_char_array(&_340$$135, &existingRecords);
								_341$$135 = &_340$$135;
							} else {
								_341$$135 = &existingRecords;
							}
							zephir_is_iterable(_341$$135, 0, "phalcon/Mvc/Model.zep", 5830);
							if (Z_TYPE_P(_341$$135) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_341$$135), _342$$135)
								{
									ZEPHIR_INIT_NVAR(&existingRecord);
									ZVAL_COPY(&existingRecord, _342$$135);
									if (UNEXPECTED(Z_TYPE_P(&intermediateReferencedFields) == IS_ARRAY)) {
										ZVAL_STRING(&keepKey, "");
										if (Z_TYPE_P(&intermediateReferencedFields) == IS_STRING) {
											ZEPHIR_INIT_NVAR(&_344$$137);
											zephir_string_to_char_array(&_344$$137, &intermediateReferencedFields);
											_343$$137 = &_344$$137;
										} else {
											_343$$137 = &intermediateReferencedFields;
										}
										zephir_is_iterable(_343$$137, 0, "phalcon/Mvc/Model.zep", 5818);
										if (Z_TYPE_P(_343$$137) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_343$$137), _345$$137)
											{
												ZEPHIR_INIT_NVAR(&columnB);
												ZVAL_COPY(&columnB, _345$$137);
												ZEPHIR_OBS_NVAR(&_346$$138);
												zephir_read_property_zval(&_346$$138, &existingRecord, &columnB, PH_NOISY_CC);
												ZEPHIR_INIT_NVAR(&_347$$138);
												ZEPHIR_CONCAT_VS(&_347$$138, &_346$$138, "|");
												zephir_concat_self(&keepKey, &_347$$138);
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, _343$$137, "rewind", NULL, 0);
											zephir_check_call_status();
											_349$$137 = 1;
											while (1) {
												if (_349$$137) {
													_349$$137 = 0;
												} else {
													ZEPHIR_CALL_METHOD(NULL, _343$$137, "next", NULL, 0);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD(&_348$$137, _343$$137, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_348$$137)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&columnB, _343$$137, "current", NULL, 0);
												zephir_check_call_status();
													ZEPHIR_OBS_NVAR(&_350$$139);
													zephir_read_property_zval(&_350$$139, &existingRecord, &columnB, PH_NOISY_CC);
													ZEPHIR_INIT_NVAR(&_351$$139);
													ZEPHIR_CONCAT_VS(&_351$$139, &_350$$139, "|");
													zephir_concat_self(&keepKey, &_351$$139);
											}
										}
										ZEPHIR_INIT_NVAR(&columnB);
									} else {
										ZEPHIR_OBS_NVAR(&_352$$140);
										zephir_read_property_zval(&_352$$140, &existingRecord, &intermediateReferencedFields, PH_NOISY_CC);
										zephir_cast_to_string(&_353$$140, &_352$$140);
										ZEPHIR_CPY_WRT(&keepKey, &_353$$140);
									}
									_354$$136 = !(zephir_array_isset_value(&keptKeys, &keepKey));
									if (_354$$136) {
										ZEPHIR_CALL_METHOD(&_355$$136, &existingRecord, "delete", NULL, 0);
										zephir_check_call_status();
										_354$$136 = !zephir_is_true(&_355$$136);
									}
									if (_354$$136) {
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_33, 0, &existingRecord);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_356$$141, 1);
										} else {
											ZVAL_BOOL(&_356$$141, 0);
										}
										ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_357, 0, &_356$$141);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, _341$$135, "rewind", NULL, 0);
								zephir_check_call_status();
								_359$$135 = 1;
								while (1) {
									if (_359$$135) {
										_359$$135 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, _341$$135, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_358$$135, _341$$135, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_358$$135)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&existingRecord, _341$$135, "current", NULL, 0);
									zephir_check_call_status();
										if (UNEXPECTED(Z_TYPE_P(&intermediateReferencedFields) == IS_ARRAY)) {
											ZVAL_STRING(&keepKey, "");
											if (Z_TYPE_P(&intermediateReferencedFields) == IS_STRING) {
												ZEPHIR_INIT_NVAR(&_361$$143);
												zephir_string_to_char_array(&_361$$143, &intermediateReferencedFields);
												_360$$143 = &_361$$143;
											} else {
												_360$$143 = &intermediateReferencedFields;
											}
											zephir_is_iterable(_360$$143, 0, "phalcon/Mvc/Model.zep", 5818);
											if (Z_TYPE_P(_360$$143) == IS_ARRAY) {
												ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_360$$143), _362$$143)
												{
													ZEPHIR_INIT_NVAR(&columnB);
													ZVAL_COPY(&columnB, _362$$143);
													ZEPHIR_OBS_NVAR(&_363$$144);
													zephir_read_property_zval(&_363$$144, &existingRecord, &columnB, PH_NOISY_CC);
													ZEPHIR_INIT_NVAR(&_364$$144);
													ZEPHIR_CONCAT_VS(&_364$$144, &_363$$144, "|");
													zephir_concat_self(&keepKey, &_364$$144);
												} ZEND_HASH_FOREACH_END();
											} else {
												ZEPHIR_CALL_METHOD(NULL, _360$$143, "rewind", NULL, 0);
												zephir_check_call_status();
												_366$$143 = 1;
												while (1) {
													if (_366$$143) {
														_366$$143 = 0;
													} else {
														ZEPHIR_CALL_METHOD(NULL, _360$$143, "next", NULL, 0);
														zephir_check_call_status();
													}
													ZEPHIR_CALL_METHOD(&_365$$143, _360$$143, "valid", NULL, 0);
													zephir_check_call_status();
													if (!zend_is_true(&_365$$143)) {
														break;
													}
													ZEPHIR_CALL_METHOD(&columnB, _360$$143, "current", NULL, 0);
													zephir_check_call_status();
														ZEPHIR_OBS_NVAR(&_367$$145);
														zephir_read_property_zval(&_367$$145, &existingRecord, &columnB, PH_NOISY_CC);
														ZEPHIR_INIT_NVAR(&_368$$145);
														ZEPHIR_CONCAT_VS(&_368$$145, &_367$$145, "|");
														zephir_concat_self(&keepKey, &_368$$145);
												}
											}
											ZEPHIR_INIT_NVAR(&columnB);
										} else {
											ZEPHIR_OBS_NVAR(&_369$$146);
											zephir_read_property_zval(&_369$$146, &existingRecord, &intermediateReferencedFields, PH_NOISY_CC);
											zephir_cast_to_string(&_370$$146, &_369$$146);
											ZEPHIR_CPY_WRT(&keepKey, &_370$$146);
										}
										_371$$142 = !(zephir_array_isset_value(&keptKeys, &keepKey));
										if (_371$$142) {
											ZEPHIR_CALL_METHOD(&_372$$142, &existingRecord, "delete", NULL, 0);
											zephir_check_call_status();
											_371$$142 = !zephir_is_true(&_372$$142);
										}
										if (_371$$142) {
											ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_33, 0, &existingRecord);
											zephir_check_call_status();
											if (nesting) {
												ZVAL_BOOL(&_373$$147, 1);
											} else {
												ZVAL_BOOL(&_373$$147, 0);
											}
											ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_374, 0, &_373$$147);
											zephir_check_call_status();
											RETURN_MM_BOOL(0);
										}
								}
							}
							ZEPHIR_INIT_NVAR(&existingRecord);
						}
					} else {
						if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
							columnCount = (zephir_fast_count_int(&columns) - 1);
							if (Z_TYPE_P(&relatedRecords) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_376$$149);
								zephir_string_to_char_array(&_376$$149, &relatedRecords);
								_375$$149 = &_376$$149;
							} else {
								_375$$149 = &relatedRecords;
							}
							zephir_is_iterable(_375$$149, 0, "phalcon/Mvc/Model.zep", 5858);
							if (Z_TYPE_P(_375$$149) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_375$$149), _377$$149)
								{
									ZEPHIR_INIT_NVAR(&recordAfter);
									ZVAL_COPY(&recordAfter, _377$$149);
									_380$$150 = columnCount;
									_379$$150 = 0;
									_378$$150 = 0;
									if (_379$$150 <= _380$$150) {
										while (1) {
											if (_378$$150) {
												_379$$150++;
												if (!(_379$$150 <= _380$$150)) {
													break;
												}
											} else {
												_378$$150 = 1;
											}
											i = _379$$150;
											ZEPHIR_OBS_NVAR(&columnA);
											zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5836);
											ZEPHIR_OBS_NVAR(&columnB);
											zephir_array_fetch_long(&columnB, &referencedFields, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5837);
											ZEPHIR_OBS_NVAR(&_381$$151);
											zephir_read_property_zval(&_381$$151, this_ptr, &columnA, PH_NOISY_CC);
											zephir_update_property_zval_zval(&recordAfter, &columnB, &_381$$151);
										}
									}
									ZEPHIR_CALL_METHOD(&_382$$150, &recordAfter, "dosave", NULL, 0, visited);
									zephir_check_call_status();
									if (!(zephir_is_true(&_382$$150))) {
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_33, 0, &recordAfter);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_383$$152, 1);
										} else {
											ZVAL_BOOL(&_383$$152, 0);
										}
										ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_384, 0, &_383$$152);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, _375$$149, "rewind", NULL, 0);
								zephir_check_call_status();
								_386$$149 = 1;
								while (1) {
									if (_386$$149) {
										_386$$149 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, _375$$149, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_385$$149, _375$$149, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_385$$149)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&recordAfter, _375$$149, "current", NULL, 0);
									zephir_check_call_status();
										_389$$153 = columnCount;
										_388$$153 = 0;
										_387$$153 = 0;
										if (_388$$153 <= _389$$153) {
											while (1) {
												if (_387$$153) {
													_388$$153++;
													if (!(_388$$153 <= _389$$153)) {
														break;
													}
												} else {
													_387$$153 = 1;
												}
												i = _388$$153;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5836);
												ZEPHIR_OBS_NVAR(&columnB);
												zephir_array_fetch_long(&columnB, &referencedFields, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5837);
												ZEPHIR_OBS_NVAR(&_390$$154);
												zephir_read_property_zval(&_390$$154, this_ptr, &columnA, PH_NOISY_CC);
												zephir_update_property_zval_zval(&recordAfter, &columnB, &_390$$154);
											}
										}
										ZEPHIR_CALL_METHOD(&_391$$153, &recordAfter, "dosave", NULL, 0, visited);
										zephir_check_call_status();
										if (!(zephir_is_true(&_391$$153))) {
											ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_33, 0, &recordAfter);
											zephir_check_call_status();
											if (nesting) {
												ZVAL_BOOL(&_392$$155, 1);
											} else {
												ZVAL_BOOL(&_392$$155, 0);
											}
											ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_393, 0, &_392$$155);
											zephir_check_call_status();
											RETURN_MM_BOOL(0);
										}
								}
							}
							ZEPHIR_INIT_NVAR(&recordAfter);
						} else {
							if (Z_TYPE_P(&relatedRecords) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_395$$156);
								zephir_string_to_char_array(&_395$$156, &relatedRecords);
								_394$$156 = &_395$$156;
							} else {
								_394$$156 = &relatedRecords;
							}
							zephir_is_iterable(_394$$156, 0, "phalcon/Mvc/Model.zep", 5883);
							if (Z_TYPE_P(_394$$156) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_394$$156), _396$$156)
								{
									ZEPHIR_INIT_NVAR(&recordAfter);
									ZVAL_COPY(&recordAfter, _396$$156);
									ZEPHIR_OBS_NVAR(&_397$$157);
									zephir_read_property_zval(&_397$$157, this_ptr, &columns, PH_NOISY_CC);
									zephir_update_property_zval_zval(&recordAfter, &referencedFields, &_397$$157);
									ZEPHIR_CALL_METHOD(&_398$$157, &recordAfter, "dosave", NULL, 0, visited);
									zephir_check_call_status();
									if (!(zephir_is_true(&_398$$157))) {
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_33, 0, &recordAfter);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_399$$158, 1);
										} else {
											ZVAL_BOOL(&_399$$158, 0);
										}
										ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_400, 0, &_399$$158);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, _394$$156, "rewind", NULL, 0);
								zephir_check_call_status();
								_402$$156 = 1;
								while (1) {
									if (_402$$156) {
										_402$$156 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, _394$$156, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_401$$156, _394$$156, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_401$$156)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&recordAfter, _394$$156, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_OBS_NVAR(&_403$$159);
										zephir_read_property_zval(&_403$$159, this_ptr, &columns, PH_NOISY_CC);
										zephir_update_property_zval_zval(&recordAfter, &referencedFields, &_403$$159);
										ZEPHIR_CALL_METHOD(&_404$$159, &recordAfter, "dosave", NULL, 0, visited);
										zephir_check_call_status();
										if (!(zephir_is_true(&_404$$159))) {
											ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessagesfrom", &_33, 0, &recordAfter);
											zephir_check_call_status();
											if (nesting) {
												ZVAL_BOOL(&_405$$160, 1);
											} else {
												ZVAL_BOOL(&_405$$160, 0);
											}
											ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_406, 0, &_405$$160);
											zephir_check_call_status();
											RETURN_MM_BOOL(0);
										}
								}
							}
							ZEPHIR_INIT_NVAR(&recordAfter);
						}
					}
				} else {
					if (UNEXPECTED(Z_TYPE_P(&record) != IS_ARRAY)) {
						if (nesting) {
							ZVAL_BOOL(&_407$$162, 1);
						} else {
							ZVAL_BOOL(&_407$$162, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_408, 0, &_407$$162);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_409$$162);
						object_init_ex(&_409$$162, phalcon_mvc_model_exceptions_relationnotdefined_ce);
						ZEPHIR_CALL_METHOD(NULL, &_409$$162, "__construct", &_207, 0, &className, &name);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_409$$162, "phalcon/Mvc/Model.zep", 5889);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&record);
	ZEPHIR_INIT_NVAR(&name);
	if (nesting) {
		ZVAL_BOOL(&_410, 1);
	} else {
		ZVAL_BOOL(&_410, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, connection, "commit", NULL, 0, &_410);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);
}

/**
 * Sets a list of attributes that must be skipped from the
 * generated UPDATE statement
 *
 *```php
 * class Invoices extends \Phalcon\Mvc\Model
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
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, __$true, keysAttributes, attribute, *_0, _1, _3;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&keysAttributes);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &attributes_param);
	zephir_get_arrval(&attributes, attributes_param);
	ZEPHIR_INIT_VAR(&keysAttributes);
	array_init(&keysAttributes);
	zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model.zep", 5930);
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
		_2 = 1;
		while (1) {
			if (_2) {
				_2 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_1, &attributes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attribute, &attributes, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_update_zval(&keysAttributes, &attribute, &__$true, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&attribute);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_3, "setemptystringattributes", NULL, 0, this_ptr, &keysAttributes);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("operationMade", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1003, PH_NOISY_CC | PH_READONLY);
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
 * class OrdersProducts extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         $this->belongsTo(
 *             "oxp_ord_id",
 *             Invoices::class,
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}

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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addbelongsto", NULL, 0, this_ptr, fields, &referenceModel_zv, referencedFields, &options);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * shared prepare query logic for find and findFirst method
 */
PHP_METHOD(Phalcon_Mvc_Model, loadEager)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params;
	zval *resultset, resultset_sub, *eager, eager_sub, *params_param = NULL, container, hydration, loader, manager, _4, _5, _0$$3, _1$$4, _2$$4, _3$$6;

	ZVAL_UNDEF(&resultset_sub);
	ZVAL_UNDEF(&eager_sub);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&hydration);
	ZVAL_UNDEF(&loader);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&params);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ZVAL(resultset)
		Z_PARAM_ZVAL(eager)
		ZEPHIR_Z_PARAM_ARRAY(params, params_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &resultset, &eager, &params_param);
	zephir_get_arrval(&params, params_param);
	if (UNEXPECTED(Z_TYPE_P(eager) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_model_exceptions_invalideagerparameter_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model.zep", 6014);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!((zephir_instance_of_ev(resultset, phalcon_mvc_model_resultset_simple_ce))))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_mvc_model_exceptions_unsupportedeagerresultset_ce);
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_get_class(&_2$$4, resultset, 0);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 0, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/Model.zep", 6018);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&hydration);
	if (zephir_array_isset_string_fetch(&hydration, &params, SL("hydration"), 0)) {
		if (UNEXPECTED(!ZEPHIR_IS_LONG_IDENTICAL(&hydration, 0))) {
			ZEPHIR_INIT_VAR(&_3$$6);
			object_init_ex(&_3$$6, phalcon_mvc_model_exceptions_unsupportedeagerhydration_ce);
			ZEPHIR_CALL_METHOD(NULL, &_3$$6, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$6, "phalcon/Mvc/Model.zep", 6023);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_di_ce, "getdefault", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "modelsManager");
	ZEPHIR_CALL_METHOD(&_4, &container, "getshared", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_4);
	ZEPHIR_INIT_VAR(&loader);
	object_init_ex(&loader, phalcon_mvc_model_eager_loader_ce);
	ZEPHIR_CALL_METHOD(NULL, &loader, "__construct", NULL, 0, &manager);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_5);
	zephir_get_called_class(&_5);
	ZEPHIR_CALL_CE_STATIC(&_4, phalcon_mvc_model_eager_pathtree_ce, "parse", NULL, 0, eager);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &loader, "loadresultset", NULL, 0, resultset, &_5, &_4);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
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
 * class Invoices extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         $this->hasMany(
 *             "id",
 *             OrdersProducts::class,
 *             "oxp_ord_id"
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}

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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addhasmany", NULL, 0, this_ptr, fields, &referenceModel_zv, referencedFields, &options);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Setup an n-n relation between two models, through an intermediate
 * relation
 *
 *```php
 * class Invoices extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         // Setup a many-to-many relation to Parts through OrdersProducts
 *         $this->hasManyToMany(
 *             "id",
 *             OrdersProducts::class,
 *             "oxp_ord_id",
 *             "oxp_prd_id",
 *             Products::class,
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}

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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addhasmanytomany", NULL, 0, this_ptr, fields, &intermediateModel_zv, intermediateFields, intermediateReferencedFields, &referenceModel_zv, referencedFields, &options);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Setup a 1-1 relation between two models
 *
 *```php
 * class Invoices extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         $this->hasOne(
 *             "id",
 *             InvoicesDescription::class,
 *             "oxp_ord_id"
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}

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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addhasone", NULL, 0, this_ptr, fields, &referenceModel_zv, referencedFields, &options);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Setup a 1-1 relation between two models, through an intermediate
 * relation
 *
 *```php
 * class Invoices extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         // Setup a 1-1 relation to one item from Parts through OrdersProducts
 *         $this->hasOneThrough(
 *             "id",
 *             OrdersProducts::class,
 *             "oxp_ord_id",
 *             "oxp_prd_id",
 *             Products::class,
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}

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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
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
 * class Invoices extends Model
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(keepSnapshot)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &keepSnapshot_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(schema)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&schema_zv);
	ZVAL_STR_COPY(&schema_zv, schema);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(source)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&source_zv);
	ZVAL_STR_COPY(&source_zv, source);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setmodelsource", NULL, 0, this_ptr, &source_zv);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Sets a list of attributes that must be skipped from the
 * generated INSERT/UPDATE statement
 *
 *```php
 * class Invoices extends \Phalcon\Mvc\Model
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
	zephir_get_arrval(&attributes, attributes_param);
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
 * class Invoices extends \Phalcon\Mvc\Model
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
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, __$null, attribute, *_0, _1, _3;
	zval attributes, keysAttributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&keysAttributes);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &attributes_param);
	zephir_get_arrval(&attributes, attributes_param);
	ZEPHIR_INIT_VAR(&keysAttributes);
	array_init(&keysAttributes);
	zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model.zep", 6424);
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
		_2 = 1;
		while (1) {
			if (_2) {
				_2 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_1, &attributes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attribute, &attributes, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_update_zval(&keysAttributes, &attribute, &__$null, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&attribute);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_3, "setautomaticcreateattributes", NULL, 0, this_ptr, &keysAttributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets a list of attributes that must be skipped from the
 * generated UPDATE statement
 *
 *```php
 * class Invoices extends \Phalcon\Mvc\Model
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
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, __$null, attribute, *_0, _1, _3;
	zval attributes, keysAttributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&keysAttributes);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &attributes_param);
	zephir_get_arrval(&attributes, attributes_param);
	ZEPHIR_INIT_VAR(&keysAttributes);
	array_init(&keysAttributes);
	zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model.zep", 6459);
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
		_2 = 1;
		while (1) {
			if (_2) {
				_2 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_1, &attributes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attribute, &attributes, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_update_zval(&keysAttributes, &attribute, &__$null, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&attribute);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_3, "setautomaticupdateattributes", NULL, 0, this_ptr, &keysAttributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets if a model must use dynamic update instead of the all-field update
 *
 *```php
 * use Phalcon\Mvc\Model;
 *
 * class Invoices extends Model
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(dynamicUpdate)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &dynamicUpdate_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
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
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", &_8, 5, &_3$$4, &_4$$4, &_5$$4, &_6$$4, &_7$$4);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("errorMessages", 13, 1);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1002, PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(!(ZEPHIR_IS_EMPTY(&_0)));
}

/**
 * Attempts to find key case-insensitively
 */
PHP_METHOD(Phalcon_Mvc_Model, caseInsensitiveColumnMap)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *columnMap, columnMap_sub, *key, key_sub, cmKey, _0, *_1, _2, *_3, _4$$3, _5$$3;

	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&cmKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(columnMap)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &columnMap, &key);
	ZEPHIR_INIT_VAR(&_0);
	zephir_array_keys(&_0, columnMap);
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &_0);
		_1 = &_2;
	} else {
		_1 = &_0;
	}
	zephir_is_iterable(_1, 0, "phalcon/Mvc/Model.zep", 6596);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
	{
		ZEPHIR_INIT_NVAR(&cmKey);
		ZVAL_COPY(&cmKey, _3);
		ZEPHIR_INIT_NVAR(&_4$$3);
		zephir_fast_strtolower(&_4$$3, &cmKey);
		ZEPHIR_INIT_NVAR(&_5$$3);
		zephir_fast_strtolower(&_5$$3, key);
		if (ZEPHIR_IS_EQUAL(&_4$$3, &_5$$3)) {
			RETURN_CCTOR(&cmKey);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&cmKey);
	RETVAL_ZVAL(key, 1, 0);
	RETURN_MM();
}

/**
 * Returns the declared private properties of a class (including inherited
 * ones) as [property name => ReflectionProperty], cached per class.
 *
 * Hydration (cloneResult/cloneResultMap) cannot write private properties
 * directly: the engine write from Model scope falls back to __set(),
 * which invokes a possible setter - or throws for a non-public property
 * without one. Writing through ReflectionProperty stores the raw
 * database value instead.
 *
 * @see https://github.com/phalcon/cphalcon/issues/16454
 */
PHP_METHOD(Phalcon_Mvc_Model, getPrivateProperties)
{
	zend_bool _7$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv, cache, privateProperties, propertyName, reflection, reflectionProperties, reflectionProperty, _11, _0$$4, *_2$$4, _3$$4, *_4$$4, _6$$4, _9$$4, _5$$5, _8$$8;
	zend_string *className = NULL;

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&privateProperties);
	ZVAL_UNDEF(&propertyName);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&reflectionProperties);
	ZVAL_UNDEF(&reflectionProperty);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_8$$8);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	zephir_memory_observe(&cache);
	zephir_read_static_property_ce(&cache, phalcon_mvc_model_ce, SL("privatePropertiesCache"), PH_NOISY_CC);
	if (!(zephir_array_isset_value(&cache, &className_zv))) {
		ZEPHIR_INIT_VAR(&privateProperties);
		array_init(&privateProperties);
		ZEPHIR_INIT_VAR(&reflection);
		object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionclass")));
		ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 251, &className_zv);
		zephir_check_call_status();
		while (1) {
			if (!(Z_TYPE_P(&reflection) == IS_OBJECT)) {
				break;
			}
			ZVAL_LONG(&_0$$4, 4);
			ZEPHIR_CALL_METHOD(&reflectionProperties, &reflection, "getproperties", &_1, 372, &_0$$4);
			zephir_check_call_status();
			if (Z_TYPE_P(&reflectionProperties) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_3$$4);
				zephir_string_to_char_array(&_3$$4, &reflectionProperties);
				_2$$4 = &_3$$4;
			} else {
				_2$$4 = &reflectionProperties;
			}
			zephir_is_iterable(_2$$4, 0, "phalcon/Mvc/Model.zep", 6637);
			if (Z_TYPE_P(_2$$4) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_2$$4), _4$$4)
				{
					ZEPHIR_INIT_NVAR(&reflectionProperty);
					ZVAL_COPY(&reflectionProperty, _4$$4);
					ZEPHIR_CALL_METHOD(&_5$$5, &reflectionProperty, "isstatic", NULL, 0);
					zephir_check_call_status();
					if (zephir_is_true(&_5$$5)) {
						continue;
					}
					ZEPHIR_CALL_METHOD(&propertyName, &reflectionProperty, "getname", NULL, 0);
					zephir_check_call_status();
					if (!(zephir_array_isset_value(&privateProperties, &propertyName))) {
						zephir_array_update_zval(&privateProperties, &propertyName, &reflectionProperty, PH_COPY | PH_SEPARATE);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _2$$4, "rewind", NULL, 0);
				zephir_check_call_status();
				_7$$4 = 1;
				while (1) {
					if (_7$$4) {
						_7$$4 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _2$$4, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_6$$4, _2$$4, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_6$$4)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&reflectionProperty, _2$$4, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_8$$8, &reflectionProperty, "isstatic", NULL, 0);
						zephir_check_call_status();
						if (zephir_is_true(&_8$$8)) {
							continue;
						}
						ZEPHIR_CALL_METHOD(&propertyName, &reflectionProperty, "getname", NULL, 0);
						zephir_check_call_status();
						if (!(zephir_array_isset_value(&privateProperties, &propertyName))) {
							zephir_array_update_zval(&privateProperties, &propertyName, &reflectionProperty, PH_COPY | PH_SEPARATE);
						}
				}
			}
			ZEPHIR_INIT_NVAR(&reflectionProperty);
			ZEPHIR_CALL_METHOD(&_9$$4, &reflection, "getparentclass", &_10, 0);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&reflection, &_9$$4);
		}
		zephir_array_update_zval(&cache, &className_zv, &privateProperties, PH_COPY | PH_SEPARATE);
		zephir_update_static_property_ce(phalcon_mvc_model_ce, ZEND_STRL("privatePropertiesCache"), &cache);
	}
	zephir_array_fetch(&_11, &cache, &className_zv, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model.zep", 6644);
	RETURN_CTOR(&_11);
}

/**
 * Append messages to this model from another Model.
 */
PHP_METHOD(Phalcon_Mvc_Model, appendMessagesFrom)
{
	zval _3$$5, _7$$7;
	zend_bool _6$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, messages, message, *_0$$3, _1$$3, *_2$$3, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_7$$7);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(model)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &model);
	ZEPHIR_CALL_METHOD(&messages, model, "getmessages", NULL, 0);
	zephir_check_call_status();
	if (0 == ZEPHIR_IS_EMPTY(&messages)) {
		if (Z_TYPE_P(&messages) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_string_to_char_array(&_1$$3, &messages);
			_0$$3 = &_1$$3;
		} else {
			_0$$3 = &messages;
		}
		zephir_is_iterable(_0$$3, 0, "phalcon/Mvc/Model.zep", 6668);
		if (Z_TYPE_P(_0$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_0$$3), _2$$3)
			{
				ZEPHIR_INIT_NVAR(&message);
				ZVAL_COPY(&message, _2$$3);
				if (Z_TYPE_P(&message) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_3$$5);
					zephir_create_array(&_3$$5, 1, 0);
					zephir_array_update_string(&_3$$5, SL("model"), model, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_3$$5);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_4, 0, &message);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _0$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			_6$$3 = 1;
			while (1) {
				if (_6$$3) {
					_6$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _0$$3, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_5$$3, _0$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&message, _0$$3, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&message) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_7$$7);
						zephir_create_array(&_7$$7, 1, 0);
						zephir_array_update_string(&_7$$7, SL("model"), model, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD(NULL, &message, "setmetadata", NULL, 0, &_7$$7);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_4, 0, &message);
					zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&message);
	}
	ZEPHIR_MM_RESTORE();
}

zend_object *zephir_init_properties_Phalcon_Mvc_Model(zend_class_entry *class_type)
{
		zval _0, _2, _4, _6, _8, _10, _12, _14, _16, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7, _11$$8, _13$$9, _15$$10, _17$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_17$$11);
	

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
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("syncRelated"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("syncRelated"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("snapshot"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("snapshot"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("rawValues"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("rawValues"), &_9$$7);
		}
		zephir_read_property_ex(&_10, this_ptr, ZEND_STRL("oldSnapshot"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			array_init(&_11$$8);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("oldSnapshot"), &_11$$8);
		}
		zephir_read_property_ex(&_12, this_ptr, ZEND_STRL("related"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_12) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_13$$9);
			array_init(&_13$$9);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("related"), &_13$$9);
		}
		zephir_read_property_ex(&_14, this_ptr, ZEND_STRL("errorMessages"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_14) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_15$$10);
			array_init(&_15$$10);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("errorMessages"), &_15$$10);
		}
		zephir_read_property_ex(&_16, this_ptr, ZEND_STRL("dirtyRelated"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_16) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_17$$11);
			array_init(&_17$$11);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("dirtyRelated"), &_17$$11);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

void zephir_init_static_properties_Phalcon_Mvc_Model()
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_static_property_ce(phalcon_mvc_model_ce, ZEND_STRL("privatePropertiesCache"), &_0);
	ZEPHIR_MM_RESTORE();
}

