
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
#include "kernel/main.h"
#include "kernel/iterator.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
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
 *
 * @phpstan-import-type mvc_model_attributes from MvcTypes
 * @phpstan-import-type mvc_model_bind_params from MvcTypes
 * @phpstan-import-type mvc_model_bind_types from MvcTypes
 * @phpstan-import-type mvc_model_cache_options from MvcTypes
 * @phpstan-import-type mvc_model_data from MvcTypes
 * @phpstan-import-type mvc_model_foreign_key from MvcTypes
 * @phpstan-import-type mvc_model_messages from MvcTypes
 * @phpstan-import-type mvc_model_parameters from MvcTypes
 * @phpstan-import-type mvc_model_related from MvcTypes
 * @phpstan-import-type mvc_model_serialized from MvcTypes
 * @phpstan-import-type mvc_model_snapshot from MvcTypes
 * @phpstan-import-type mvc_model_sync_related from MvcTypes
 * @phpstan-import-type mvc_metadata_column_map from MvcTypes
 * @phpstan-import-type mvc_hydration_column_map from MvcTypes
 * @phpstan-import-type mvc_relation_fields from MvcTypes
 * @phpstan-import-type mvc_relation_options from MvcTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc, Model, phalcon, mvc_model, phalcon_di_abstractinjectionaware_ce, phalcon_mvc_model_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @phpstan-var mvc_model_related
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_model_ce, SL("dirtyRelated"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_model_ce, SL("dirtyState"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	/**
	 * @phpstan-var mvc_model_messages
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_model_ce, SL("errorMessages"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_mvc_model_ce, SL("modelsManager"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Mvc\\Model\\ManagerInterface"));
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_mvc_model_ce, SL("modelsMetaData"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Mvc\\Model\\MetaDataInterface"));
	}

	/**
	 * @phpstan-var mvc_model_snapshot
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_model_ce, SL("oldSnapshot"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 0);
		zephir_declare_typed_property(phalcon_mvc_model_ce, SL("operationMade"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	/**
	 * @phpstan-var array<string, mixed>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_model_ce, SL("rawValues"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var mvc_model_related
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_model_ce, SL("related"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_mvc_model_ce, SL("skipped"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	/**
	 * @phpstan-var mvc_model_snapshot
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_model_ce, SL("snapshot"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Per-save many-to-many sync overrides, keyed by lowercased relation
	 * alias (or "*" wildcard) => bool. Cleared after each save().
	 *
	 * @phpstan-var mvc_model_sync_related
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_model_ce, SL("syncRelated"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

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
	 *
	 * @phpstan-var mvc_model_bind_params
	 */
	zend_declare_property_null(phalcon_mvc_model_ce, SL("uniqueParams"), ZEND_ACC_PROTECTED);
	/**
	 * @phpstan-var mvc_model_bind_types
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_model_ce, SL("uniqueTypes"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

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
		ZEPHIR_CALL_CE_STATIC(container, phalcon_di_di_ce, "getDefault", NULL, 0);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$4);
		object_init_ex(&_0$$4, phalcon_mvc_model_exceptions_modelormservicesunavailable_ce);
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_get_class(&_1$$4, this_ptr, 0);
		ZEPHIR_CALL_METHOD(NULL, &_0$$4, "__construct", NULL, 0, &_1$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$4, "phalcon/Mvc/Model.zep", 277);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1013, container);
	if (Z_TYPE_P(modelsManager) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_3$$5);
		ZVAL_STRING(&_3$$5, "modelsManager");
		ZEPHIR_CALL_METHOD(&_2$$5, container, "getShared", NULL, 0, &_3$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(modelsManager, &_2$$5);
		if (Z_TYPE_P(modelsManager) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_4$$6);
			object_init_ex(&_4$$6, phalcon_mvc_model_exceptions_invalidmodelsmanagerservice_ce);
			ZEPHIR_INIT_VAR(&_5$$6);
			zephir_get_class(&_5$$6, this_ptr, 0);
			ZEPHIR_CALL_METHOD(NULL, &_4$$6, "__construct", NULL, 0, &_5$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_4$$6, "phalcon/Mvc/Model.zep", 288);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1014, modelsManager);
	ZEPHIR_CALL_METHOD(NULL, modelsManager, "initialize", NULL, 0, this_ptr);
	zephir_check_call_status();
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("onconstruct")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "onConstruct", NULL, 0, data);
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
 *
 * @phpstan-param list<mixed> $arguments
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
	ZEPHIR_CALL_SELF(&records, "invokeFinder", &_0, 0, &method_zv, &arguments);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&records)) {
		RETURN_CCTOR(&records);
	}
	ZEPHIR_INIT_VAR(&modelName);
	zephir_get_class(&modelName, this_ptr, 0);
	ZEPHIR_CALL_METHOD(&records, this_ptr, "getRelatedRecords", NULL, 0, &modelName, &method_zv, &arguments);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&records)) {
		RETURN_CCTOR(&records);
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&status, &_1, "missingMethod", NULL, 0, this_ptr, &method_zv, &arguments);
	zephir_check_call_status();
	if (Z_TYPE_P(&status) != IS_NULL) {
		RETURN_CCTOR(&status);
	}
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, phalcon_mvc_model_exceptions_methodnotfound_ce);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 0, &method_zv, &modelName);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_2, "phalcon/Mvc/Model.zep", 357);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Handles method calls when a static method is not implemented
 *
 * @return mixed
 * @throws \Phalcon\Mvc\Model\Exception If the method does not exist
 *
 * @phpstan-param list<mixed> $arguments
 * @phpstan-return int|ResultsetInterface|Row|static|null
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
	ZEPHIR_CALL_SELF(&records, "invokeFinder", &_0, 0, &method_zv, &arguments);
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
	zephir_throw_exception_debug(&_1, "phalcon/Mvc/Model.zep", 384);
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
	zend_bool _2$$3, _6$$3, _7$$3, _9$$3, _12$$3;
	zval method;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval property_zv, modelName, manager, lowerProperty, relation, _0, _17, _18, _19, _1$$3, _5$$3, _8$$3, _10$$3, _11$$3, _13$$3, _14$$3, _3$$4, _4$$4, _15$$5, _16$$5;
	zend_string *property = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property_zv);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&lowerProperty);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
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
	ZEPHIR_CALL_METHOD(&manager, this_ptr, "getModelsManager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&lowerProperty);
	zephir_fast_strtolower(&lowerProperty, &property_zv);
	ZEPHIR_CALL_METHOD(&_0, &manager, "getRelationByAlias", NULL, 0, &modelName, &lowerProperty);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&relation, &_0);
	if (Z_TYPE_P(&relation) == IS_OBJECT) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 1015, PH_NOISY_CC | PH_READONLY);
		_2$$3 = zephir_array_isset_value(&_1$$3, &lowerProperty);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_2$$3) {
			zephir_read_property_cached(&_3$$4, this_ptr, _zephir_prop_0, 1015, PH_NOISY_CC | PH_READONLY);
			zephir_memory_observe(&_4$$4);
			zephir_array_fetch(&_4$$4, &_3$$4, &lowerProperty, PH_NOISY, "phalcon/Mvc/Model.zep", 415);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_CCTOR(&_4$$4);
		}
		zephir_read_property_cached(&_5$$3, this_ptr, _zephir_prop_1, 1016, PH_NOISY_CC | PH_READONLY);
		_6$$3 = zephir_array_isset_value(&_5$$3, &lowerProperty);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_7$$3 = _6$$3;
		if (_7$$3) {
			ZEPHIR_CALL_METHOD(&_8$$3, &relation, "isReusable", NULL, 0);
			zephir_check_call_status();
			_7$$3 = !zephir_is_true(&_8$$3);
		}
		_9$$3 = _7$$3;
		if (_9$$3) {
			zephir_read_property_cached(&_10$$3, this_ptr, _zephir_prop_1, 1016, PH_NOISY_CC | PH_READONLY);
			zephir_memory_observe(&_11$$3);
			zephir_array_fetch(&_11$$3, &_10$$3, &lowerProperty, PH_NOISY, "phalcon/Mvc/Model.zep", 426);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_9$$3 = Z_TYPE_P(&_11$$3) == IS_OBJECT;
		}
		_12$$3 = _9$$3;
		if (_12$$3) {
			zephir_read_property_cached(&_13$$3, this_ptr, _zephir_prop_1, 1016, PH_NOISY_CC | PH_READONLY);
			zephir_memory_observe(&_14$$3);
			zephir_array_fetch(&_14$$3, &_13$$3, &lowerProperty, PH_NOISY, "phalcon/Mvc/Model.zep", 427);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_12$$3 = (zephir_instance_of_ev(&_14$$3, phalcon_mvc_modelinterface_ce));
		}
		if (_12$$3) {
			zephir_read_property_cached(&_15$$5, this_ptr, _zephir_prop_1, 1016, PH_NOISY_CC | PH_READONLY);
			zephir_memory_observe(&_16$$5);
			zephir_array_fetch(&_16$$5, &_15$$5, &lowerProperty, PH_NOISY, "phalcon/Mvc/Model.zep", 428);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_CCTOR(&_16$$5);
		}
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getRelated", NULL, 0, &lowerProperty);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_17);
	zephir_camelize(&_17, &property_zv, NULL );
	ZEPHIR_INIT_VAR(&_18);
	ZEPHIR_CONCAT_SV(&_18, "get", &_17);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_get_strval(&method, &_18);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if ((zephir_method_exists(this_ptr, &method)  == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &method, NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_19);
	ZEPHIR_CONCAT_SVSV(&_19, "Access to undefined property ", &modelName, "::", &property_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 11, &_19);
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getModelsManager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&_0, &manager, "getRelationByAlias", NULL, 0, &modelName, &property_zv);
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
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&result);
		ZVAL_BOOL(&result, (zephir_method_exists(this_ptr, &method)  == SUCCESS));
	}
	RETURN_CCTOR(&result);
}

/**
 * Serializes a model
 *
 * @phpstan-return mvc_model_serialized
 */
PHP_METHOD(Phalcon_Mvc_Model, __serialize)
{
	zend_bool _3, _4, _5;
	zval attributes, manager, dirtyState, snapshot, _0, _1, _2, _6$$3;
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
	ZVAL_UNDEF(&_6$$3);
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
	ZEPHIR_CALL_METHOD(&attributes, this_ptr, "toArray", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1017, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dirtyState, &_0);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getModelsManager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_2);
	ZEPHIR_CALL_METHOD(&_2, &manager, "isKeepingSnapshots", NULL, 0, this_ptr);
	zephir_check_call_status();
	_3 = zephir_is_true(&_2);
	if (_3) {
		zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1018, PH_NOISY_CC | PH_READONLY);
		_3 = Z_TYPE_P(&_0) != IS_NULL;
	}
	_4 = _3;
	if (_4) {
		zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 1018, PH_NOISY_CC | PH_READONLY);
		_5 = !ZEPHIR_IS_EQUAL(&attributes, &_1);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_4 = _5;
	}
	if (_4) {
		zephir_read_property_cached(&_6$$3, this_ptr, _zephir_prop_1, 1018, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&snapshot, &_6$$3);
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
	zend_bool _0, _5$$4, _14$$10, _15$$10;
	zval related;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval property_zv, *value, value_sub, __$null, lowerProperty, modelName, manager, relation, referencedModel, item, dirtyState, _20, _21, _2$$3, _3$$4, _4$$4, _6$$6, _7$$7, _8$$8, _9$$9, *_10$$10, _11$$10, *_12$$10, _13$$10, _16$$10, _17$$17, _18$$19, _19$$20, _22$$22, _23$$23, _24$$23;
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
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$17);
	ZVAL_UNDEF(&_18$$19);
	ZVAL_UNDEF(&_19$$20);
	ZVAL_UNDEF(&_22$$22);
	ZVAL_UNDEF(&_23$$23);
	ZVAL_UNDEF(&_24$$23);
	ZVAL_UNDEF(&related);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dirtyState", 10, 1);
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
		ZEPHIR_CALL_METHOD(&manager, this_ptr, "getModelsManager", &_1, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2$$3, &manager, "getRelationByAlias", NULL, 0, &modelName, &lowerProperty);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_2$$3);
		if (Z_TYPE_P(&relation) == IS_OBJECT) {
			zephir_read_property_cached(&_3$$4, this_ptr, _zephir_prop_0, 1017, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&dirtyState, &_3$$4);
			ZEPHIR_CALL_METHOD(&_4$$4, value, "getDirtyState", NULL, 0);
			zephir_check_call_status();
			_5$$4 = !ZEPHIR_IS_EQUAL(&_4$$4, &dirtyState);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_5$$4) {
				ZEPHIR_INIT_NVAR(&dirtyState);
				ZVAL_LONG(&dirtyState, 1);
			}
			zephir_unset_property_array(this_ptr, ZEND_STRL("related"), &lowerProperty);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_update_property_array(this_ptr, SL("dirtyRelated"), &lowerProperty, value);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1017, &dirtyState);
			RETVAL_ZVAL(value, 1, 0);
			RETURN_MM();
		}
	} else if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&lowerProperty);
		zephir_fast_strtolower(&lowerProperty, &property_zv);
		ZEPHIR_INIT_NVAR(&modelName);
		zephir_get_class(&modelName, this_ptr, 0);
		ZEPHIR_CALL_METHOD(&manager, this_ptr, "getModelsManager", &_1, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_6$$6, &manager, "getRelationByAlias", NULL, 0, &modelName, &lowerProperty);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_6$$6);
		if (Z_TYPE_P(&relation) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&_7$$7, &relation, "getType", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG(&_7$$7, 0)) { goto zephir_switch_0_clause_0; }
			if (ZEPHIR_IS_LONG(&_7$$7, 1)) { goto zephir_switch_0_clause_1; }
			if (ZEPHIR_IS_LONG(&_7$$7, 2)) { goto zephir_switch_0_clause_2; }
			if (ZEPHIR_IS_LONG(&_7$$7, 4)) { goto zephir_switch_0_clause_3; }
			goto zephir_switch_0_end;
			zephir_switch_0_clause_0: ;
			zephir_switch_0_clause_1: ;
				ZEPHIR_CALL_METHOD(&_8$$8, &relation, "getReferencedModel", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedModel, &manager, "load", NULL, 0, &_8$$8);
				zephir_check_call_status();
				if (Z_TYPE_P(&referencedModel) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD(NULL, &referencedModel, "assign", NULL, 0, value);
					zephir_check_call_status();
					zephir_unset_property_array(this_ptr, ZEND_STRL("related"), &lowerProperty);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_update_property_array(this_ptr, SL("dirtyRelated"), &lowerProperty, &referencedModel);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZVAL_UNDEF(&_9$$9);
					ZVAL_LONG(&_9$$9, 1);
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1017, &_9$$9);
					RETVAL_ZVAL(value, 1, 0);
					RETURN_MM();
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_2: ;
			zephir_switch_0_clause_3: ;
				ZEPHIR_INIT_VAR(&related);
				array_init(&related);
				if (Z_TYPE_P(value) == IS_STRING) {
					ZEPHIR_INIT_VAR(&_11$$10);
					zephir_string_to_char_array(&_11$$10, value);
					_10$$10 = &_11$$10;
				} else {
					_10$$10 = value;
				}
				zephir_is_iterable(_10$$10, 0, "phalcon/Mvc/Model.zep", 601);
				if (Z_TYPE_P(_10$$10) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_10$$10), _12$$10)
					{
						ZEPHIR_INIT_NVAR(&item);
						ZVAL_COPY(&item, _12$$10);
						if (Z_TYPE_P(&item) == IS_OBJECT) {
							if (zephir_instance_of_ev(&item, phalcon_mvc_modelinterface_ce)) {
								zephir_array_append(&related, &item, PH_SEPARATE, "phalcon/Mvc/Model.zep", 596);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _10$$10, "rewind", NULL, 0);
					zephir_check_call_status();
					_14$$10 = 1;
					while (1) {
						if (_14$$10) {
							_14$$10 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _10$$10, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_13$$10, _10$$10, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_13$$10)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&item, _10$$10, "current", NULL, 0);
						zephir_check_call_status();
							if (Z_TYPE_P(&item) == IS_OBJECT) {
								if (zephir_instance_of_ev(&item, phalcon_mvc_modelinterface_ce)) {
									zephir_array_append(&related, &item, PH_SEPARATE, "phalcon/Mvc/Model.zep", 596);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
							}
					}
				}
				ZEPHIR_INIT_NVAR(&item);
				zephir_unset_property_array(this_ptr, ZEND_STRL("related"), &lowerProperty);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_15$$10 = !(ZEPHIR_IS_EMPTY(&related));
				if (!(_15$$10)) {
					ZEPHIR_CALL_METHOD(&_16$$10, &relation, "getType", NULL, 0);
					zephir_check_call_status();
					_15$$10 = ZEPHIR_IS_LONG_IDENTICAL(&_16$$10, 4);
				}
				if (_15$$10) {
					zephir_update_property_array(this_ptr, SL("dirtyRelated"), &lowerProperty, &related);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZVAL_UNDEF(&_17$$17);
					ZVAL_LONG(&_17$$17, 1);
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1017, &_17$$17);
				} else {
					zephir_unset_property_array(this_ptr, ZEND_STRL("dirtyRelated"), &lowerProperty);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
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
		ZEPHIR_CALL_METHOD(&manager, this_ptr, "getModelsManager", &_1, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_18$$19, &manager, "getRelationByAlias", NULL, 0, &modelName, &lowerProperty);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_18$$19);
		if (Z_TYPE_P(&relation) == IS_OBJECT) {
			zephir_unset_property_array(this_ptr, ZEND_STRL("related"), &lowerProperty);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_unset_property_array(this_ptr, ZEND_STRL("dirtyRelated"), &lowerProperty);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_update_property_zval_zval(this_ptr, &property_zv, &__$null);
			ZVAL_NULL(&_19$$20);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "possibleSetter", NULL, 0, &property_zv, &_19$$20);
			zephir_check_call_status();
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_CALL_METHOD(&_20, this_ptr, "possibleSetter", NULL, 0, &property_zv, value);
	zephir_check_call_status();
	if (zephir_is_true(&_20)) {
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_21, "property_exists", NULL, 10, this_ptr, &property_zv);
	zephir_check_call_status();
	if (zephir_is_true(&_21)) {
		ZEPHIR_CALL_METHOD(&manager, this_ptr, "getModelsManager", &_1, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_22$$22, &manager, "isVisibleModelProperty", NULL, 0, this_ptr, &property_zv);
		zephir_check_call_status();
		if (UNEXPECTED(!zephir_is_true(&_22$$22))) {
			ZEPHIR_INIT_VAR(&_23$$23);
			object_init_ex(&_23$$23, phalcon_mvc_model_exceptions_propertynotaccessible_ce);
			ZEPHIR_INIT_VAR(&_24$$23);
			zephir_get_class(&_24$$23, this_ptr, 0);
			ZEPHIR_CALL_METHOD(NULL, &_23$$23, "__construct", NULL, 0, &property_zv, &_24$$23);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_23$$23, "phalcon/Mvc/Model.zep", 666);
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
 *
 * @phpstan-param array<string, mixed> $data
 */
PHP_METHOD(Phalcon_Mvc_Model, __unserialize)
{
	zend_string *_13$$7;
	zend_ulong _12$$7;
	zend_bool _0, _8, _16, _15$$7, _17$$12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, container, manager, key, value, snapshot, properties, dirtyState, _4, _5, _1$$3, _2$$4, _3$$4, _6$$5, _7$$5, *_9$$7, _10$$7, *_11$$7, _14$$7, _18$$13;
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
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_18$$13);
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
	_0 = zephir_array_isset_value_string(&data, SL("attributes"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 1, 0);
		zephir_array_update_string(&_1$$3, SL("attributes"), &data, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&data, &_1$$3);
	}
	ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_di_ce, "getDefault", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_mvc_model_exceptions_modelormservicesunavailable_ce);
		ZEPHIR_INIT_VAR(&_3$$4);
		zephir_get_class(&_3$$4, this_ptr, 0);
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 0, &_3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalcon/Mvc/Model.zep", 695);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1013, &container);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "modelsManager");
	ZEPHIR_CALL_METHOD(&_4, &container, "getShared", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_4);
	if (Z_TYPE_P(&manager) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_6$$5);
		object_init_ex(&_6$$5, phalcon_mvc_model_exceptions_invalidmodelsmanagerservice_ce);
		ZEPHIR_INIT_VAR(&_7$$5);
		zephir_get_class(&_7$$5, this_ptr, 0);
		ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", NULL, 0, &_7$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$5, "phalcon/Mvc/Model.zep", 708);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1014, &manager);
	ZEPHIR_CALL_METHOD(NULL, &manager, "initialize", NULL, 0, this_ptr);
	zephir_check_call_status();
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("onconstruct")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "onConstruct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_memory_observe(&properties);
	_8 = zephir_array_isset_string_fetch(&properties, &data, SL("attributes"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_8) {
		if (Z_TYPE_P(&properties) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_10$$7);
			zephir_string_to_char_array(&_10$$7, &properties);
			_9$$7 = &_10$$7;
		} else {
			_9$$7 = &properties;
		}
		zephir_is_iterable(_9$$7, 0, "phalcon/Mvc/Model.zep", 739);
		if (Z_TYPE_P(_9$$7) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_9$$7), _12$$7, _13$$7, _11$$7)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_13$$7 != NULL) { 
					ZVAL_STR_COPY(&key, _13$$7);
				} else {
					ZVAL_LONG(&key, _12$$7);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _11$$7);
				zephir_update_property_zval_zval(this_ptr, &key, &value);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _9$$7, "rewind", NULL, 0);
			zephir_check_call_status();
			_15$$7 = 1;
			while (1) {
				if (_15$$7) {
					_15$$7 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _9$$7, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_14$$7, _9$$7, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_14$$7)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, _9$$7, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, _9$$7, "current", NULL, 0);
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
	_16 = zephir_array_isset_string_fetch(&dirtyState, &data, SL("dirtyState"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_16) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1017, &dirtyState);
	}
	ZEPHIR_CALL_METHOD(&_4, &manager, "isKeepingSnapshots", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (zephir_is_true(&_4)) {
		zephir_memory_observe(&snapshot);
		_17$$12 = zephir_array_isset_string_fetch(&snapshot, &data, SL("snapshot"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_17$$12) {
			ZEPHIR_INIT_VAR(&_18$$13);
			if (Z_TYPE_P(&snapshot) != IS_NULL) {
				ZEPHIR_CPY_WRT(&_18$$13, &snapshot);
			} else {
				ZEPHIR_CPY_WRT(&_18$$13, &properties);
			}
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1018, &_18$$13);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1018, &properties);
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Enables/disables options in the ORM.
 *
 * The options are written to process-global `Phalcon\Support\Settings`
 * (`orm.*` flags) and therefore affect every model in the process at once.
 * Call this once during bootstrap; it is not per-model or per-container
 * configuration, and one application's `setup()` reconfigures the ORM for
 * every other user in the same process.
 *
 * @phpstan-param array<string, mixed> $options
 */
PHP_METHOD(Phalcon_Mvc_Model, setup)
{
	zend_bool _0, _3, _6, _9, _12, _15, _18, _21, _24, _27, _30, _33, _36, _39, _42;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, disableEvents, columnRenaming, notNullValidations, exceptionOnFailedSave, exceptionOnFailedMetaDataSave, phqlLiterals, virtualForeignKeys, lateStateBinding, castOnHydrate, ignoreUnknownColumns, updateSnapshotOnSave, disableAssignSetters, caseInsensitiveColumnMap, prefetchRecords, lastInsertId, _1$$3, _2$$3, _4$$4, _5$$4, _7$$5, _8$$5, _10$$6, _11$$6, _13$$7, _14$$7, _16$$8, _17$$8, _19$$9, _20$$9, _22$$10, _23$$10, _25$$11, _26$$11, _28$$12, _29$$12, _31$$13, _32$$13, _34$$14, _35$$14, _37$$15, _38$$15, _40$$16, _41$$16, _43$$17, _44$$17;
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
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_26$$11);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_29$$12);
	ZVAL_UNDEF(&_31$$13);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_34$$14);
	ZVAL_UNDEF(&_35$$14);
	ZVAL_UNDEF(&_37$$15);
	ZVAL_UNDEF(&_38$$15);
	ZVAL_UNDEF(&_40$$16);
	ZVAL_UNDEF(&_41$$16);
	ZVAL_UNDEF(&_43$$17);
	ZVAL_UNDEF(&_44$$17);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &options_param);
	zephir_get_arrval(&options, options_param);
	zephir_memory_observe(&disableEvents);
	_0 = zephir_array_isset_string_fetch(&disableEvents, &options, SL("events"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "orm.events");
		ZVAL_BOOL(&_2$$3, zephir_get_boolval(&disableEvents));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_1$$3, &_2$$3);
		zephir_check_call_status();
	}
	zephir_memory_observe(&virtualForeignKeys);
	_3 = zephir_array_isset_string_fetch(&virtualForeignKeys, &options, SL("virtualForeignKeys"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_3) {
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "orm.virtual_foreign_keys");
		ZVAL_BOOL(&_5$$4, zephir_get_boolval(&virtualForeignKeys));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_4$$4, &_5$$4);
		zephir_check_call_status();
	}
	zephir_memory_observe(&columnRenaming);
	_6 = zephir_array_isset_string_fetch(&columnRenaming, &options, SL("columnRenaming"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_6) {
		ZEPHIR_INIT_VAR(&_7$$5);
		ZVAL_STRING(&_7$$5, "orm.column_renaming");
		ZVAL_BOOL(&_8$$5, zephir_get_boolval(&columnRenaming));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_7$$5, &_8$$5);
		zephir_check_call_status();
	}
	zephir_memory_observe(&notNullValidations);
	_9 = zephir_array_isset_string_fetch(&notNullValidations, &options, SL("notNullValidations"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_9) {
		ZEPHIR_INIT_VAR(&_10$$6);
		ZVAL_STRING(&_10$$6, "orm.not_null_validations");
		ZVAL_BOOL(&_11$$6, zephir_get_boolval(&notNullValidations));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_10$$6, &_11$$6);
		zephir_check_call_status();
	}
	zephir_memory_observe(&exceptionOnFailedSave);
	_12 = zephir_array_isset_string_fetch(&exceptionOnFailedSave, &options, SL("exceptionOnFailedSave"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_12) {
		ZEPHIR_INIT_VAR(&_13$$7);
		ZVAL_STRING(&_13$$7, "orm.exception_on_failed_save");
		ZVAL_BOOL(&_14$$7, zephir_get_boolval(&exceptionOnFailedSave));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_13$$7, &_14$$7);
		zephir_check_call_status();
	}
	zephir_memory_observe(&exceptionOnFailedMetaDataSave);
	_15 = zephir_array_isset_string_fetch(&exceptionOnFailedMetaDataSave, &options, SL("exceptionOnFailedMetaDataSave"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_15) {
		ZEPHIR_INIT_VAR(&_16$$8);
		ZVAL_STRING(&_16$$8, "orm.exception_on_failed_metadata_save");
		ZVAL_BOOL(&_17$$8, zephir_get_boolval(&exceptionOnFailedMetaDataSave));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_16$$8, &_17$$8);
		zephir_check_call_status();
	}
	zephir_memory_observe(&phqlLiterals);
	_18 = zephir_array_isset_string_fetch(&phqlLiterals, &options, SL("phqlLiterals"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_18) {
		ZEPHIR_INIT_VAR(&_19$$9);
		ZVAL_STRING(&_19$$9, "orm.enable_literals");
		ZVAL_BOOL(&_20$$9, zephir_get_boolval(&phqlLiterals));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_19$$9, &_20$$9);
		zephir_check_call_status();
	}
	zephir_memory_observe(&lateStateBinding);
	_21 = zephir_array_isset_string_fetch(&lateStateBinding, &options, SL("lateStateBinding"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_21) {
		ZEPHIR_INIT_VAR(&_22$$10);
		ZVAL_STRING(&_22$$10, "orm.late_state_binding");
		ZVAL_BOOL(&_23$$10, zephir_get_boolval(&lateStateBinding));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_22$$10, &_23$$10);
		zephir_check_call_status();
	}
	zephir_memory_observe(&castOnHydrate);
	_24 = zephir_array_isset_string_fetch(&castOnHydrate, &options, SL("castOnHydrate"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_24) {
		ZEPHIR_INIT_VAR(&_25$$11);
		ZVAL_STRING(&_25$$11, "orm.cast_on_hydrate");
		ZVAL_BOOL(&_26$$11, zephir_get_boolval(&castOnHydrate));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_25$$11, &_26$$11);
		zephir_check_call_status();
	}
	zephir_memory_observe(&ignoreUnknownColumns);
	_27 = zephir_array_isset_string_fetch(&ignoreUnknownColumns, &options, SL("ignoreUnknownColumns"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_27) {
		ZEPHIR_INIT_VAR(&_28$$12);
		ZVAL_STRING(&_28$$12, "orm.ignore_unknown_columns");
		ZVAL_BOOL(&_29$$12, zephir_get_boolval(&ignoreUnknownColumns));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_28$$12, &_29$$12);
		zephir_check_call_status();
	}
	zephir_memory_observe(&caseInsensitiveColumnMap);
	_30 = zephir_array_isset_string_fetch(&caseInsensitiveColumnMap, &options, SL("caseInsensitiveColumnMap"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_30) {
		ZEPHIR_INIT_VAR(&_31$$13);
		ZVAL_STRING(&_31$$13, "orm.case_insensitive_column_map");
		ZVAL_BOOL(&_32$$13, zephir_get_boolval(&caseInsensitiveColumnMap));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_31$$13, &_32$$13);
		zephir_check_call_status();
	}
	zephir_memory_observe(&updateSnapshotOnSave);
	_33 = zephir_array_isset_string_fetch(&updateSnapshotOnSave, &options, SL("updateSnapshotOnSave"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_33) {
		ZEPHIR_INIT_VAR(&_34$$14);
		ZVAL_STRING(&_34$$14, "orm.update_snapshot_on_save");
		ZVAL_BOOL(&_35$$14, zephir_get_boolval(&updateSnapshotOnSave));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_34$$14, &_35$$14);
		zephir_check_call_status();
	}
	zephir_memory_observe(&disableAssignSetters);
	_36 = zephir_array_isset_string_fetch(&disableAssignSetters, &options, SL("disableAssignSetters"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_36) {
		ZEPHIR_INIT_VAR(&_37$$15);
		ZVAL_STRING(&_37$$15, "orm.disable_assign_setters");
		ZVAL_BOOL(&_38$$15, zephir_get_boolval(&disableAssignSetters));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_37$$15, &_38$$15);
		zephir_check_call_status();
	}
	zephir_memory_observe(&prefetchRecords);
	_39 = zephir_array_isset_string_fetch(&prefetchRecords, &options, SL("prefetchRecords"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_39) {
		ZEPHIR_INIT_VAR(&_40$$16);
		ZVAL_STRING(&_40$$16, "orm.resultset_prefetch_records");
		ZVAL_LONG(&_41$$16, zephir_get_intval(&prefetchRecords));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_40$$16, &_41$$16);
		zephir_check_call_status();
	}
	zephir_memory_observe(&lastInsertId);
	_42 = zephir_array_isset_string_fetch(&lastInsertId, &options, SL("castLastInsertIdToInt"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_42) {
		ZEPHIR_INIT_VAR(&_43$$17);
		ZVAL_STRING(&_43$$17, "orm.cast_last_insert_id_to_int");
		ZVAL_BOOL(&_44$$17, zephir_get_boolval(&lastInsertId));
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_43$$17, &_44$$17);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
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
 * @phpstan-param mvc_model_parameters $parameters
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
	ZEPHIR_CALL_SELF(&result, "groupResult", NULL, 0, &_0, &_1, &parameters);
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
 *
 * @phpstan-param mvc_model_data $data
 */
PHP_METHOD(Phalcon_Mvc_Model, cloneResult)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long dirtyState, ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *base, base_sub, *data_param = NULL, *dirtyState_param = NULL, _0;

	ZVAL_UNDEF(&base_sub);
	ZVAL_UNDEF(&_0);
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
	ZVAL_LONG(&_0, dirtyState);
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_mvc_model_hydration_cloneresult_ce, "cloneResult", NULL, 0, base, &data, &_0);
	zephir_check_call_status();
	RETURN_MM();
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
 *
 * @phpstan-param mvc_model_data $data
 */
PHP_METHOD(Phalcon_Mvc_Model, cloneResultMap)
{
	zend_string *_7;
	zend_ulong _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_21 = NULL, *_25 = NULL, *_30 = NULL, *_41 = NULL, *_42 = NULL, *_44 = NULL, *_72 = NULL, *_77 = NULL, *_89 = NULL;
	zend_bool keepSnapshots, callSetters = 0, _56, _9$$6, _11$$13, _12$$13, _15$$16, _16$$12, _17$$4, _38$$4, _54$$4, _18$$22, _19$$23, _32$$30, _33$$30, _36$$33, _37$$29, _49$$51, _50$$51, _53$$54, _57$$62, _59$$69, _60$$69, _63$$72, _64$$68, _65$$60, _85$$60, _99$$60, _66$$78, _67$$79, _79$$86, _80$$86, _83$$89, _84$$85, _94$$107, _95$$107, _98$$110;
	zend_long dirtyState, ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *base, base_sub, *data_param = NULL, *columnMap, columnMap_sub, *dirtyState_param = NULL, *keepSnapshots_param = NULL, instance, attribute, key, value, castValue, attributeName, metaData, reverseMap, notNullAttributes, privateProperties, reflectionProperty, setter, localMethods, _0, _1, _2, _3, *_5, _55, _4$$3, _10$$13, _13$$14, _14$$14, _20$$25, _22$$25, _23$$26, _24$$26, _26$$27, _27$$27, _28$$28, _29$$28, _31$$30, _34$$31, _35$$31, _39$$39, _40$$40, _43$$44, _45$$43, _46$$43, _47$$48, _48$$51, _51$$52, _52$$52, _58$$69, _61$$70, _62$$70, _68$$81, _69$$81, _70$$82, _71$$82, _73$$83, _74$$83, _75$$84, _76$$84, _78$$86, _81$$87, _82$$87, _86$$95, _87$$96, _88$$100, _90$$99, _91$$99, _92$$104, _93$$107, _96$$108, _97$$108, _100$$116, _101$$117;

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
	ZVAL_UNDEF(&localMethods);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_55);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_10$$13);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_20$$25);
	ZVAL_UNDEF(&_22$$25);
	ZVAL_UNDEF(&_23$$26);
	ZVAL_UNDEF(&_24$$26);
	ZVAL_UNDEF(&_26$$27);
	ZVAL_UNDEF(&_27$$27);
	ZVAL_UNDEF(&_28$$28);
	ZVAL_UNDEF(&_29$$28);
	ZVAL_UNDEF(&_31$$30);
	ZVAL_UNDEF(&_34$$31);
	ZVAL_UNDEF(&_35$$31);
	ZVAL_UNDEF(&_39$$39);
	ZVAL_UNDEF(&_40$$40);
	ZVAL_UNDEF(&_43$$44);
	ZVAL_UNDEF(&_45$$43);
	ZVAL_UNDEF(&_46$$43);
	ZVAL_UNDEF(&_47$$48);
	ZVAL_UNDEF(&_48$$51);
	ZVAL_UNDEF(&_51$$52);
	ZVAL_UNDEF(&_52$$52);
	ZVAL_UNDEF(&_58$$69);
	ZVAL_UNDEF(&_61$$70);
	ZVAL_UNDEF(&_62$$70);
	ZVAL_UNDEF(&_68$$81);
	ZVAL_UNDEF(&_69$$81);
	ZVAL_UNDEF(&_70$$82);
	ZVAL_UNDEF(&_71$$82);
	ZVAL_UNDEF(&_73$$83);
	ZVAL_UNDEF(&_74$$83);
	ZVAL_UNDEF(&_75$$84);
	ZVAL_UNDEF(&_76$$84);
	ZVAL_UNDEF(&_78$$86);
	ZVAL_UNDEF(&_81$$87);
	ZVAL_UNDEF(&_82$$87);
	ZVAL_UNDEF(&_86$$95);
	ZVAL_UNDEF(&_87$$96);
	ZVAL_UNDEF(&_88$$100);
	ZVAL_UNDEF(&_90$$99);
	ZVAL_UNDEF(&_91$$99);
	ZVAL_UNDEF(&_92$$104);
	ZVAL_UNDEF(&_93$$107);
	ZVAL_UNDEF(&_96$$108);
	ZVAL_UNDEF(&_97$$108);
	ZVAL_UNDEF(&_100$$116);
	ZVAL_UNDEF(&_101$$117);
	ZVAL_UNDEF(&data);
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
	ZEPHIR_INIT_VAR(&localMethods);
	ZVAL_NULL(&localMethods);
	ZEPHIR_INIT_VAR(&instance);
	if (zephir_clone(&instance, base) == FAILURE) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, &instance, 0);
	ZEPHIR_CALL_CE_STATIC(&privateProperties, phalcon_mvc_model_hydration_getprivateproperties_ce, "getPrivateProperties", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&metaData);
	ZVAL_NULL(&metaData);
	ZEPHIR_INIT_VAR(&notNullAttributes);
	ZVAL_NULL(&notNullAttributes);
	ZVAL_LONG(&_1, dirtyState);
	ZEPHIR_CALL_METHOD(NULL, &instance, "setDirtyState", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "orm.call_setters_on_hydration");
	ZEPHIR_CALL_CE_STATIC(&_2, phalcon_support_settings_ce, "get", NULL, 0, &_3);
	zephir_check_call_status();
	callSetters = zephir_get_boolval(&_2);
	if (callSetters) {
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_create_array(&_4$$3, 10, 0);
		add_assoc_long_ex(&_4$$3, SL("setConnectionService"), 1);
		add_assoc_long_ex(&_4$$3, SL("setDirtyState"), 1);
		add_assoc_long_ex(&_4$$3, SL("setEventsManager"), 1);
		add_assoc_long_ex(&_4$$3, SL("setReadConnectionService"), 1);
		add_assoc_long_ex(&_4$$3, SL("setOldSnapshotData"), 1);
		add_assoc_long_ex(&_4$$3, SL("setSchema"), 1);
		add_assoc_long_ex(&_4$$3, SL("setSnapshotData"), 1);
		add_assoc_long_ex(&_4$$3, SL("setSource"), 1);
		add_assoc_long_ex(&_4$$3, SL("setTransaction"), 1);
		add_assoc_long_ex(&_4$$3, SL("setWriteConnectionService"), 1);
		ZEPHIR_CPY_WRT(&localMethods, &_4$$3);
	}
	zephir_is_iterable(&data, 1, "phalcon/Mvc/Model.zep", 1225);
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
			if (Z_TYPE_P(&value) == IS_NULL) {
				if (Z_TYPE_P(&notNullAttributes) == IS_NULL) {
					if (zephir_instance_of_ev(&instance, phalcon_mvc_model_ce)) {
						if (Z_TYPE_P(&metaData) == IS_NULL) {
							ZEPHIR_CALL_METHOD(&metaData, &instance, "getModelsMetaData", &_8, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&notNullAttributes, &metaData, "getNotNullAttributes", NULL, 0, &instance);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(&notNullAttributes);
						array_init(&notNullAttributes);
					}
				}
				_9$$6 = zephir_fast_in_array(&key, &notNullAttributes);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_9$$6) {
					continue;
				}
			}
			if (Z_TYPE_P(columnMap) != IS_ARRAY) {
				if (callSetters) {
					ZEPHIR_INIT_NVAR(&_10$$13);
					zephir_camelize(&_10$$13, &key, NULL );
					ZEPHIR_INIT_NVAR(&setter);
					ZEPHIR_CONCAT_SV(&setter, "set", &_10$$13);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_11$$13 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
					if (_11$$13) {
						_12$$13 = zephir_array_isset_value(&localMethods, &setter);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_11$$13 = !(_12$$13);
					}
					if (_11$$13) {

						/* try_start_1: */

							ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &value);
							zephir_check_call_status_or_jump(try_end_1);

						try_end_1:

						if (EG(exception)) {
							ZEPHIR_INIT_NVAR(&_13$$14);
							ZVAL_OBJ(&_13$$14, EG(exception));
							Z_ADDREF_P(&_13$$14);
							ZEPHIR_INIT_NVAR(&_14$$14);
							if (zephir_is_instance_of(&_13$$14, SL("TypeError"))) {
								zend_clear_exception();
								ZEPHIR_CPY_WRT(&_14$$14, &_13$$14);
								_15$$16 = zephir_array_isset_value(&privateProperties, &key);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (UNEXPECTED(_15$$16)) {
									ZEPHIR_OBS_NVAR(&reflectionProperty);
									zephir_array_fetch(&reflectionProperty, &privateProperties, &key, PH_NOISY, "phalcon/Mvc/Model.zep", 1055);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setValue", NULL, 0, &instance, &value);
									zephir_check_call_status();
								} else {
									zephir_update_property_zval_zval(&instance, &key, &value);
								}
							} else {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
						continue;
					}
				}
				_16$$12 = zephir_array_isset_value(&privateProperties, &key);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(_16$$12)) {
					ZEPHIR_OBS_NVAR(&reflectionProperty);
					zephir_array_fetch(&reflectionProperty, &privateProperties, &key, PH_NOISY, "phalcon/Mvc/Model.zep", 1067);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setValue", NULL, 0, &instance, &value);
					zephir_check_call_status();
				} else {
					zephir_update_property_zval_zval(&instance, &key, &value);
				}
				continue;
			}
			ZEPHIR_OBS_NVAR(&attribute);
			_17$$4 = zephir_array_isset_fetch(&attribute, columnMap, &key, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_17$$4)) {
				_18$$22 = Z_TYPE_P(columnMap) == IS_ARRAY;
				if (_18$$22) {
					_18$$22 = !(ZEPHIR_IS_EMPTY(columnMap));
				}
				if (_18$$22) {
					if (Z_TYPE_P(&metaData) == IS_NULL) {
						ZEPHIR_CALL_METHOD(&metaData, &instance, "getModelsMetaData", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&reverseMap, &metaData, "getReverseColumnMap", NULL, 0, &instance);
					zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&attribute);
					_19$$23 = zephir_array_isset_fetch(&attribute, &reverseMap, &key, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_19$$23)) {
						ZEPHIR_INIT_NVAR(&_22$$25);
						ZVAL_STRING(&_22$$25, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_20$$25, phalcon_support_settings_ce, "get", &_21, 0, &_22$$25);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_20$$25))) {
							ZEPHIR_INIT_NVAR(&_23$$26);
							object_init_ex(&_23$$26, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							ZEPHIR_INIT_NVAR(&_24$$26);
							zephir_get_class(&_24$$26, base, 0);
							ZEPHIR_CALL_METHOD(NULL, &_23$$26, "__construct", &_25, 0, &key, &_24$$26);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_23$$26, "phalcon/Mvc/Model.zep", 1086);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
				} else {
					ZEPHIR_INIT_NVAR(&_27$$27);
					ZVAL_STRING(&_27$$27, "orm.ignore_unknown_columns");
					ZEPHIR_CALL_CE_STATIC(&_26$$27, phalcon_support_settings_ce, "get", &_21, 0, &_27$$27);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&_26$$27))) {
						ZEPHIR_INIT_NVAR(&_28$$28);
						object_init_ex(&_28$$28, phalcon_mvc_model_exceptions_columnnotinmap_ce);
						ZEPHIR_INIT_NVAR(&_29$$28);
						zephir_get_class(&_29$$28, base, 0);
						ZEPHIR_CALL_METHOD(NULL, &_28$$28, "__construct", &_30, 0, &key, &_29$$28);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_28$$28, "phalcon/Mvc/Model.zep", 1093);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
			}
			if (Z_TYPE_P(&attribute) != IS_ARRAY) {
				if (callSetters) {
					ZEPHIR_INIT_NVAR(&_31$$30);
					zephir_camelize(&_31$$30, &attribute, NULL );
					ZEPHIR_INIT_NVAR(&setter);
					ZEPHIR_CONCAT_SV(&setter, "set", &_31$$30);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_32$$30 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
					if (_32$$30) {
						_33$$30 = zephir_array_isset_value(&localMethods, &setter);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_32$$30 = !(_33$$30);
					}
					if (_32$$30) {

						/* try_start_2: */

							ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &value);
							zephir_check_call_status_or_jump(try_end_2);

						try_end_2:

						if (EG(exception)) {
							ZEPHIR_INIT_NVAR(&_34$$31);
							ZVAL_OBJ(&_34$$31, EG(exception));
							Z_ADDREF_P(&_34$$31);
							ZEPHIR_INIT_NVAR(&_35$$31);
							if (zephir_is_instance_of(&_34$$31, SL("TypeError"))) {
								zend_clear_exception();
								ZEPHIR_CPY_WRT(&_35$$31, &_34$$31);
								_36$$33 = zephir_array_isset_value(&privateProperties, &attribute);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (UNEXPECTED(_36$$33)) {
									ZEPHIR_OBS_NVAR(&reflectionProperty);
									zephir_array_fetch(&reflectionProperty, &privateProperties, &attribute, PH_NOISY, "phalcon/Mvc/Model.zep", 1108);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setValue", NULL, 0, &instance, &value);
									zephir_check_call_status();
								} else {
									zephir_update_property_zval_zval(&instance, &attribute, &value);
								}
							} else {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
						continue;
					}
				}
				_37$$29 = zephir_array_isset_value(&privateProperties, &attribute);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(_37$$29)) {
					ZEPHIR_OBS_NVAR(&reflectionProperty);
					zephir_array_fetch(&reflectionProperty, &privateProperties, &attribute, PH_NOISY, "phalcon/Mvc/Model.zep", 1120);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setValue", NULL, 0, &instance, &value);
					zephir_check_call_status();
				} else {
					zephir_update_property_zval_zval(&instance, &attribute, &value);
				}
				continue;
			}
			_38$$4 = !ZEPHIR_IS_STRING(&value, "");
			if (_38$$4) {
				_38$$4 = Z_TYPE_P(&value) != IS_NULL;
			}
			if (_38$$4) {
				ZEPHIR_OBS_NVAR(&_39$$39);
				zephir_array_fetch_long(&_39$$39, &attribute, 1, PH_NOISY, "phalcon/Mvc/Model.zep", 1130);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_LONG(&_39$$39, 0)) { goto zephir_switch_0_clause_0; }
				if (ZEPHIR_IS_LONG(&_39$$39, 21)) { goto zephir_switch_0_clause_1; }
				if (ZEPHIR_IS_LONG(&_39$$39, 22)) { goto zephir_switch_0_clause_2; }
				if (ZEPHIR_IS_LONG(&_39$$39, 26)) { goto zephir_switch_0_clause_3; }
				if (ZEPHIR_IS_LONG(&_39$$39, 3)) { goto zephir_switch_0_clause_4; }
				if (ZEPHIR_IS_LONG(&_39$$39, 9)) { goto zephir_switch_0_clause_5; }
				if (ZEPHIR_IS_LONG(&_39$$39, 7)) { goto zephir_switch_0_clause_6; }
				if (ZEPHIR_IS_LONG(&_39$$39, 8)) { goto zephir_switch_0_clause_7; }
				if (ZEPHIR_IS_LONG(&_39$$39, 40)) { goto zephir_switch_0_clause_8; }
				if (ZEPHIR_IS_LONG(&_39$$39, 41)) { goto zephir_switch_0_clause_9; }
				if (ZEPHIR_IS_LONG(&_39$$39, 42)) { goto zephir_switch_0_clause_10; }
				if (ZEPHIR_IS_LONG(&_39$$39, 43)) { goto zephir_switch_0_clause_11; }
				if (ZEPHIR_IS_LONG(&_39$$39, 44)) { goto zephir_switch_0_clause_12; }
				if (ZEPHIR_IS_LONG(&_39$$39, 45)) { goto zephir_switch_0_clause_13; }
				if (ZEPHIR_IS_LONG(&_39$$39, 46)) { goto zephir_switch_0_clause_14; }
				if (ZEPHIR_IS_LONG(&_39$$39, 47)) { goto zephir_switch_0_clause_15; }
				goto zephir_switch_0_clause_16;
				zephir_switch_0_clause_0: ;
				zephir_switch_0_clause_1: ;
				zephir_switch_0_clause_2: ;
				zephir_switch_0_clause_3: ;
					ZVAL_LONG(&_40$$40, 10);
					ZEPHIR_CALL_FUNCTION(&castValue, "intval", &_41, 95, &value, &_40$$40);
					zephir_check_call_status();
					goto zephir_switch_0_end;
				zephir_switch_0_clause_4: ;
				zephir_switch_0_clause_5: ;
				zephir_switch_0_clause_6: ;
					ZEPHIR_CALL_FUNCTION(&castValue, "floatval", &_42, 32, &value);
					zephir_check_call_status();
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

						ZEPHIR_INIT_NVAR(&_43$$44);
						object_init_ex(&_43$$44, phalcon_db_geometry_wkbparser_ce);
						if (zephir_has_constructor(&_43$$44)) {
							ZEPHIR_CALL_METHOD(NULL, &_43$$44, "__construct", NULL, 0);
							zephir_check_call_status_or_jump(try_end_3);
						}

						ZEPHIR_CALL_METHOD(&castValue, &_43$$44, "parse", &_44, 0, &value);
						zephir_check_call_status_or_jump(try_end_3);

					try_end_3:

					if (EG(exception)) {
						ZEPHIR_INIT_NVAR(&_45$$43);
						ZVAL_OBJ(&_45$$43, EG(exception));
						Z_ADDREF_P(&_45$$43);
						ZEPHIR_INIT_NVAR(&_46$$43);
						if (zephir_instance_of_ev(&_45$$43, phalcon_db_exceptions_invalidwkb_ce)) {
							zend_clear_exception();
							ZEPHIR_CPY_WRT(&_46$$43, &_45$$43);
							ZEPHIR_CPY_WRT(&castValue, &value);
						} else {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					goto zephir_switch_0_end;
				zephir_switch_0_clause_16: ;
					ZEPHIR_CPY_WRT(&castValue, &value);
					goto zephir_switch_0_end;
				zephir_switch_0_end: ;

			} else {
				ZEPHIR_OBS_NVAR(&_47$$48);
				zephir_array_fetch_long(&_47$$48, &attribute, 1, PH_NOISY, "phalcon/Mvc/Model.zep", 1169);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_LONG(&_47$$48, 14)) { goto zephir_switch_1_clause_0; }
				if (ZEPHIR_IS_LONG(&_47$$48, 8)) { goto zephir_switch_1_clause_1; }
				if (ZEPHIR_IS_LONG(&_47$$48, 3)) { goto zephir_switch_1_clause_2; }
				if (ZEPHIR_IS_LONG(&_47$$48, 9)) { goto zephir_switch_1_clause_3; }
				if (ZEPHIR_IS_LONG(&_47$$48, 7)) { goto zephir_switch_1_clause_4; }
				if (ZEPHIR_IS_LONG(&_47$$48, 0)) { goto zephir_switch_1_clause_5; }
				if (ZEPHIR_IS_LONG(&_47$$48, 21)) { goto zephir_switch_1_clause_6; }
				if (ZEPHIR_IS_LONG(&_47$$48, 22)) { goto zephir_switch_1_clause_7; }
				if (ZEPHIR_IS_LONG(&_47$$48, 26)) { goto zephir_switch_1_clause_8; }
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
			zephir_array_fetch_long(&attributeName, &attribute, 0, PH_NOISY, "phalcon/Mvc/Model.zep", 1188);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&data, &key, &castValue, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (callSetters) {
				ZEPHIR_INIT_NVAR(&_48$$51);
				zephir_camelize(&_48$$51, &attributeName, NULL );
				ZEPHIR_INIT_NVAR(&setter);
				ZEPHIR_CONCAT_SV(&setter, "set", &_48$$51);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_49$$51 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
				if (_49$$51) {
					_50$$51 = zephir_array_isset_value(&localMethods, &setter);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_49$$51 = !(_50$$51);
				}
				if (_49$$51) {

					/* try_start_4: */

						ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &castValue);
						zephir_check_call_status_or_jump(try_end_4);

					try_end_4:

					if (EG(exception)) {
						ZEPHIR_INIT_NVAR(&_51$$52);
						ZVAL_OBJ(&_51$$52, EG(exception));
						Z_ADDREF_P(&_51$$52);
						ZEPHIR_INIT_NVAR(&_52$$52);
						if (zephir_is_instance_of(&_51$$52, SL("TypeError"))) {
							zend_clear_exception();
							ZEPHIR_CPY_WRT(&_52$$52, &_51$$52);
							_53$$54 = zephir_array_isset_value(&privateProperties, &attributeName);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (UNEXPECTED(_53$$54)) {
								ZEPHIR_OBS_NVAR(&reflectionProperty);
								zephir_array_fetch(&reflectionProperty, &privateProperties, &attributeName, PH_NOISY, "phalcon/Mvc/Model.zep", 1198);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setValue", NULL, 0, &instance, &castValue);
								zephir_check_call_status();
							} else {
								zephir_update_property_zval_zval(&instance, &attributeName, &castValue);
							}
						} else {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					continue;
				}
			}
			_54$$4 = zephir_array_isset_value(&privateProperties, &attributeName);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (UNEXPECTED(_54$$4)) {
				ZEPHIR_OBS_NVAR(&reflectionProperty);
				zephir_array_fetch(&reflectionProperty, &privateProperties, &attributeName, PH_NOISY, "phalcon/Mvc/Model.zep", 1210);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setValue", NULL, 0, &instance, &castValue);
				zephir_check_call_status();
			} else {
				zephir_update_property_zval_zval(&instance, &attributeName, &castValue);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		_56 = 1;
		while (1) {
			if (_56) {
				_56 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_55, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_55)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&key) != IS_STRING) {
					continue;
				}
				if (Z_TYPE_P(&value) == IS_NULL) {
					if (Z_TYPE_P(&notNullAttributes) == IS_NULL) {
						if (zephir_instance_of_ev(&instance, phalcon_mvc_model_ce)) {
							if (Z_TYPE_P(&metaData) == IS_NULL) {
								ZEPHIR_CALL_METHOD(&metaData, &instance, "getModelsMetaData", &_8, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&notNullAttributes, &metaData, "getNotNullAttributes", NULL, 0, &instance);
							zephir_check_call_status();
						} else {
							ZEPHIR_INIT_NVAR(&notNullAttributes);
							array_init(&notNullAttributes);
						}
					}
					_57$$62 = zephir_fast_in_array(&key, &notNullAttributes);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_57$$62) {
						continue;
					}
				}
				if (Z_TYPE_P(columnMap) != IS_ARRAY) {
					if (callSetters) {
						ZEPHIR_INIT_NVAR(&_58$$69);
						zephir_camelize(&_58$$69, &key, NULL );
						ZEPHIR_INIT_NVAR(&setter);
						ZEPHIR_CONCAT_SV(&setter, "set", &_58$$69);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_59$$69 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
						if (_59$$69) {
							_60$$69 = zephir_array_isset_value(&localMethods, &setter);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							_59$$69 = !(_60$$69);
						}
						if (_59$$69) {

							/* try_start_5: */

								ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &value);
								zephir_check_call_status_or_jump(try_end_5);

							try_end_5:

							if (EG(exception)) {
								ZEPHIR_INIT_NVAR(&_61$$70);
								ZVAL_OBJ(&_61$$70, EG(exception));
								Z_ADDREF_P(&_61$$70);
								ZEPHIR_INIT_NVAR(&_62$$70);
								if (zephir_is_instance_of(&_61$$70, SL("TypeError"))) {
									zend_clear_exception();
									ZEPHIR_CPY_WRT(&_62$$70, &_61$$70);
									_63$$72 = zephir_array_isset_value(&privateProperties, &key);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (UNEXPECTED(_63$$72)) {
										ZEPHIR_OBS_NVAR(&reflectionProperty);
										zephir_array_fetch(&reflectionProperty, &privateProperties, &key, PH_NOISY, "phalcon/Mvc/Model.zep", 1055);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setValue", NULL, 0, &instance, &value);
										zephir_check_call_status();
									} else {
										zephir_update_property_zval_zval(&instance, &key, &value);
									}
								} else {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
							continue;
						}
					}
					_64$$68 = zephir_array_isset_value(&privateProperties, &key);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(_64$$68)) {
						ZEPHIR_OBS_NVAR(&reflectionProperty);
						zephir_array_fetch(&reflectionProperty, &privateProperties, &key, PH_NOISY, "phalcon/Mvc/Model.zep", 1067);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setValue", NULL, 0, &instance, &value);
						zephir_check_call_status();
					} else {
						zephir_update_property_zval_zval(&instance, &key, &value);
					}
					continue;
				}
				ZEPHIR_OBS_NVAR(&attribute);
				_65$$60 = zephir_array_isset_fetch(&attribute, columnMap, &key, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_65$$60)) {
					_66$$78 = Z_TYPE_P(columnMap) == IS_ARRAY;
					if (_66$$78) {
						_66$$78 = !(ZEPHIR_IS_EMPTY(columnMap));
					}
					if (_66$$78) {
						if (Z_TYPE_P(&metaData) == IS_NULL) {
							ZEPHIR_CALL_METHOD(&metaData, &instance, "getModelsMetaData", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&reverseMap, &metaData, "getReverseColumnMap", NULL, 0, &instance);
						zephir_check_call_status();
						ZEPHIR_OBS_NVAR(&attribute);
						_67$$79 = zephir_array_isset_fetch(&attribute, &reverseMap, &key, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (!(_67$$79)) {
							ZEPHIR_INIT_NVAR(&_69$$81);
							ZVAL_STRING(&_69$$81, "orm.ignore_unknown_columns");
							ZEPHIR_CALL_CE_STATIC(&_68$$81, phalcon_support_settings_ce, "get", &_21, 0, &_69$$81);
							zephir_check_call_status();
							if (UNEXPECTED(!zephir_is_true(&_68$$81))) {
								ZEPHIR_INIT_NVAR(&_70$$82);
								object_init_ex(&_70$$82, phalcon_mvc_model_exceptions_columnnotinmap_ce);
								ZEPHIR_INIT_NVAR(&_71$$82);
								zephir_get_class(&_71$$82, base, 0);
								ZEPHIR_CALL_METHOD(NULL, &_70$$82, "__construct", &_72, 0, &key, &_71$$82);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_70$$82, "phalcon/Mvc/Model.zep", 1086);
								ZEPHIR_MM_RESTORE();
								return;
							}
							continue;
						}
					} else {
						ZEPHIR_INIT_NVAR(&_74$$83);
						ZVAL_STRING(&_74$$83, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_73$$83, phalcon_support_settings_ce, "get", &_21, 0, &_74$$83);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_73$$83))) {
							ZEPHIR_INIT_NVAR(&_75$$84);
							object_init_ex(&_75$$84, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							ZEPHIR_INIT_NVAR(&_76$$84);
							zephir_get_class(&_76$$84, base, 0);
							ZEPHIR_CALL_METHOD(NULL, &_75$$84, "__construct", &_77, 0, &key, &_76$$84);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_75$$84, "phalcon/Mvc/Model.zep", 1093);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
				}
				if (Z_TYPE_P(&attribute) != IS_ARRAY) {
					if (callSetters) {
						ZEPHIR_INIT_NVAR(&_78$$86);
						zephir_camelize(&_78$$86, &attribute, NULL );
						ZEPHIR_INIT_NVAR(&setter);
						ZEPHIR_CONCAT_SV(&setter, "set", &_78$$86);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_79$$86 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
						if (_79$$86) {
							_80$$86 = zephir_array_isset_value(&localMethods, &setter);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							_79$$86 = !(_80$$86);
						}
						if (_79$$86) {

							/* try_start_6: */

								ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &value);
								zephir_check_call_status_or_jump(try_end_6);

							try_end_6:

							if (EG(exception)) {
								ZEPHIR_INIT_NVAR(&_81$$87);
								ZVAL_OBJ(&_81$$87, EG(exception));
								Z_ADDREF_P(&_81$$87);
								ZEPHIR_INIT_NVAR(&_82$$87);
								if (zephir_is_instance_of(&_81$$87, SL("TypeError"))) {
									zend_clear_exception();
									ZEPHIR_CPY_WRT(&_82$$87, &_81$$87);
									_83$$89 = zephir_array_isset_value(&privateProperties, &attribute);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (UNEXPECTED(_83$$89)) {
										ZEPHIR_OBS_NVAR(&reflectionProperty);
										zephir_array_fetch(&reflectionProperty, &privateProperties, &attribute, PH_NOISY, "phalcon/Mvc/Model.zep", 1108);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setValue", NULL, 0, &instance, &value);
										zephir_check_call_status();
									} else {
										zephir_update_property_zval_zval(&instance, &attribute, &value);
									}
								} else {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
							continue;
						}
					}
					_84$$85 = zephir_array_isset_value(&privateProperties, &attribute);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(_84$$85)) {
						ZEPHIR_OBS_NVAR(&reflectionProperty);
						zephir_array_fetch(&reflectionProperty, &privateProperties, &attribute, PH_NOISY, "phalcon/Mvc/Model.zep", 1120);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setValue", NULL, 0, &instance, &value);
						zephir_check_call_status();
					} else {
						zephir_update_property_zval_zval(&instance, &attribute, &value);
					}
					continue;
				}
				_85$$60 = !ZEPHIR_IS_STRING(&value, "");
				if (_85$$60) {
					_85$$60 = Z_TYPE_P(&value) != IS_NULL;
				}
				if (_85$$60) {
					ZEPHIR_OBS_NVAR(&_86$$95);
					zephir_array_fetch_long(&_86$$95, &attribute, 1, PH_NOISY, "phalcon/Mvc/Model.zep", 1130);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (ZEPHIR_IS_LONG(&_86$$95, 0)) { goto zephir_switch_2_clause_0; }
					if (ZEPHIR_IS_LONG(&_86$$95, 21)) { goto zephir_switch_2_clause_1; }
					if (ZEPHIR_IS_LONG(&_86$$95, 22)) { goto zephir_switch_2_clause_2; }
					if (ZEPHIR_IS_LONG(&_86$$95, 26)) { goto zephir_switch_2_clause_3; }
					if (ZEPHIR_IS_LONG(&_86$$95, 3)) { goto zephir_switch_2_clause_4; }
					if (ZEPHIR_IS_LONG(&_86$$95, 9)) { goto zephir_switch_2_clause_5; }
					if (ZEPHIR_IS_LONG(&_86$$95, 7)) { goto zephir_switch_2_clause_6; }
					if (ZEPHIR_IS_LONG(&_86$$95, 8)) { goto zephir_switch_2_clause_7; }
					if (ZEPHIR_IS_LONG(&_86$$95, 40)) { goto zephir_switch_2_clause_8; }
					if (ZEPHIR_IS_LONG(&_86$$95, 41)) { goto zephir_switch_2_clause_9; }
					if (ZEPHIR_IS_LONG(&_86$$95, 42)) { goto zephir_switch_2_clause_10; }
					if (ZEPHIR_IS_LONG(&_86$$95, 43)) { goto zephir_switch_2_clause_11; }
					if (ZEPHIR_IS_LONG(&_86$$95, 44)) { goto zephir_switch_2_clause_12; }
					if (ZEPHIR_IS_LONG(&_86$$95, 45)) { goto zephir_switch_2_clause_13; }
					if (ZEPHIR_IS_LONG(&_86$$95, 46)) { goto zephir_switch_2_clause_14; }
					if (ZEPHIR_IS_LONG(&_86$$95, 47)) { goto zephir_switch_2_clause_15; }
					goto zephir_switch_2_clause_16;
					zephir_switch_2_clause_0: ;
					zephir_switch_2_clause_1: ;
					zephir_switch_2_clause_2: ;
					zephir_switch_2_clause_3: ;
						ZVAL_LONG(&_87$$96, 10);
						ZEPHIR_CALL_FUNCTION(&castValue, "intval", &_41, 95, &value, &_87$$96);
						zephir_check_call_status();
						goto zephir_switch_2_end;
					zephir_switch_2_clause_4: ;
					zephir_switch_2_clause_5: ;
					zephir_switch_2_clause_6: ;
						ZEPHIR_CALL_FUNCTION(&castValue, "floatval", &_42, 32, &value);
						zephir_check_call_status();
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

							ZEPHIR_INIT_NVAR(&_88$$100);
							object_init_ex(&_88$$100, phalcon_db_geometry_wkbparser_ce);
							if (zephir_has_constructor(&_88$$100)) {
								ZEPHIR_CALL_METHOD(NULL, &_88$$100, "__construct", NULL, 0);
								zephir_check_call_status_or_jump(try_end_7);
							}

							ZEPHIR_CALL_METHOD(&castValue, &_88$$100, "parse", &_89, 0, &value);
							zephir_check_call_status_or_jump(try_end_7);

						try_end_7:

						if (EG(exception)) {
							ZEPHIR_INIT_NVAR(&_90$$99);
							ZVAL_OBJ(&_90$$99, EG(exception));
							Z_ADDREF_P(&_90$$99);
							ZEPHIR_INIT_NVAR(&_91$$99);
							if (zephir_instance_of_ev(&_90$$99, phalcon_db_exceptions_invalidwkb_ce)) {
								zend_clear_exception();
								ZEPHIR_CPY_WRT(&_91$$99, &_90$$99);
								ZEPHIR_CPY_WRT(&castValue, &value);
							} else {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
						goto zephir_switch_2_end;
					zephir_switch_2_clause_16: ;
						ZEPHIR_CPY_WRT(&castValue, &value);
						goto zephir_switch_2_end;
					zephir_switch_2_end: ;

				} else {
					ZEPHIR_OBS_NVAR(&_92$$104);
					zephir_array_fetch_long(&_92$$104, &attribute, 1, PH_NOISY, "phalcon/Mvc/Model.zep", 1169);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (ZEPHIR_IS_LONG(&_92$$104, 14)) { goto zephir_switch_3_clause_0; }
					if (ZEPHIR_IS_LONG(&_92$$104, 8)) { goto zephir_switch_3_clause_1; }
					if (ZEPHIR_IS_LONG(&_92$$104, 3)) { goto zephir_switch_3_clause_2; }
					if (ZEPHIR_IS_LONG(&_92$$104, 9)) { goto zephir_switch_3_clause_3; }
					if (ZEPHIR_IS_LONG(&_92$$104, 7)) { goto zephir_switch_3_clause_4; }
					if (ZEPHIR_IS_LONG(&_92$$104, 0)) { goto zephir_switch_3_clause_5; }
					if (ZEPHIR_IS_LONG(&_92$$104, 21)) { goto zephir_switch_3_clause_6; }
					if (ZEPHIR_IS_LONG(&_92$$104, 22)) { goto zephir_switch_3_clause_7; }
					if (ZEPHIR_IS_LONG(&_92$$104, 26)) { goto zephir_switch_3_clause_8; }
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
				zephir_array_fetch_long(&attributeName, &attribute, 0, PH_NOISY, "phalcon/Mvc/Model.zep", 1188);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&data, &key, &castValue, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (callSetters) {
					ZEPHIR_INIT_NVAR(&_93$$107);
					zephir_camelize(&_93$$107, &attributeName, NULL );
					ZEPHIR_INIT_NVAR(&setter);
					ZEPHIR_CONCAT_SV(&setter, "set", &_93$$107);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_94$$107 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
					if (_94$$107) {
						_95$$107 = zephir_array_isset_value(&localMethods, &setter);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_94$$107 = !(_95$$107);
					}
					if (_94$$107) {

						/* try_start_8: */

							ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &castValue);
							zephir_check_call_status_or_jump(try_end_8);

						try_end_8:

						if (EG(exception)) {
							ZEPHIR_INIT_NVAR(&_96$$108);
							ZVAL_OBJ(&_96$$108, EG(exception));
							Z_ADDREF_P(&_96$$108);
							ZEPHIR_INIT_NVAR(&_97$$108);
							if (zephir_is_instance_of(&_96$$108, SL("TypeError"))) {
								zend_clear_exception();
								ZEPHIR_CPY_WRT(&_97$$108, &_96$$108);
								_98$$110 = zephir_array_isset_value(&privateProperties, &attributeName);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (UNEXPECTED(_98$$110)) {
									ZEPHIR_OBS_NVAR(&reflectionProperty);
									zephir_array_fetch(&reflectionProperty, &privateProperties, &attributeName, PH_NOISY, "phalcon/Mvc/Model.zep", 1198);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setValue", NULL, 0, &instance, &castValue);
									zephir_check_call_status();
								} else {
									zephir_update_property_zval_zval(&instance, &attributeName, &castValue);
								}
							} else {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
						continue;
					}
				}
				_99$$60 = zephir_array_isset_value(&privateProperties, &attributeName);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(_99$$60)) {
					ZEPHIR_OBS_NVAR(&reflectionProperty);
					zephir_array_fetch(&reflectionProperty, &privateProperties, &attributeName, PH_NOISY, "phalcon/Mvc/Model.zep", 1210);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setValue", NULL, 0, &instance, &castValue);
					zephir_check_call_status();
				} else {
					zephir_update_property_zval_zval(&instance, &attributeName, &castValue);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	if (keepSnapshots) {
		ZEPHIR_CALL_METHOD(NULL, &instance, "setSnapshotData", NULL, 0, &data, columnMap);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_100$$116, &instance, "getSnapshotData", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &instance, "setOldSnapshotData", NULL, 0, &_100$$116);
		zephir_check_call_status();
	}
	if ((zephir_method_exists_ex(&instance, ZEND_STRL("fireevent")) == SUCCESS)) {
		ZEPHIR_INIT_VAR(&_101$$117);
		ZVAL_STRING(&_101$$117, "afterFetch");
		ZEPHIR_CALL_METHOD(NULL, &instance, "fireEvent", NULL, 0, &_101$$117);
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
 *
 * @phpstan-param mvc_model_data $data
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
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_mvc_model_hydration_cloneresultmaphydrate_ce, "cloneResultMapHydrate", NULL, 0, &data, columnMap, &_1, &_0);
	zephir_check_call_status();
	RETURN_MM();
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
 * @param array|string|null $parameters
 *
 * @phpstan-param mvc_model_parameters|string|null $parameters
 */
PHP_METHOD(Phalcon_Mvc_Model, count)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, parameters_sub, __$null, result, _1, _2;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
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
	_0 = zephir_array_isset_value_string(parameters, SL("order"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_0) {
		zephir_array_unset_string(parameters, SL("order"), PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "COUNT");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "rowcount");
	ZEPHIR_CALL_SELF(&result, "groupResult", NULL, 0, &_1, &_2, parameters);
	zephir_check_call_status();
	if (Z_TYPE_P(&result) == IS_STRING) {
		RETURN_MM_LONG(zephir_get_intval(&result));
	}
	RETURN_CCTOR(&result);
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
 *
 * @phpstan-param mvc_model_parameters|int|string|null $parameters
 */
PHP_METHOD(Phalcon_Mvc_Model, find)
{
	zend_bool _1$$6, _2$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_3 = NULL;
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
			zephir_array_append(&params, parameters, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1488);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	ZEPHIR_CALL_SELF(&query, "getPreparedQuery", &_0, 0, &params);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&resultset, &query, "execute", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&resultset) == IS_OBJECT) {
		zephir_memory_observe(&hydration);
		_1$$6 = zephir_array_isset_string_fetch(&hydration, &params, SL("hydration"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_1$$6) {
			ZEPHIR_CALL_METHOD(NULL, &resultset, "setHydrateMode", NULL, 0, &hydration);
			zephir_check_call_status();
		}
		zephir_memory_observe(&eager);
		_2$$6 = zephir_array_isset_string_fetch(&eager, &params, SL("eager"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_2$$6) {
			ZEPHIR_CALL_SELF(NULL, "loadEager", &_3, 0, &resultset, &eager, &params);
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
 *
 * @phpstan-param mvc_model_parameters|scalar|null $parameters
 */
PHP_METHOD(Phalcon_Mvc_Model, findFirst)
{
	zend_bool _0, _6;
	zval params;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL;
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
		if (UNEXPECTED(Z_TYPE_P(parameters) != IS_ARRAY)) {
			zephir_throw_variable_type_error(parameters, "params", "array");
			ZEPHIR_MM_RESTORE();
			return;
		}
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
			zephir_throw_exception_debug(&_2$$6, "phalcon/Mvc/Model.zep", 1622);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZVAL_LONG(&_5, 1);
	ZEPHIR_CALL_SELF(&query, "getPreparedQuery", &_4, 0, &params, &_5);
	zephir_check_call_status();
	zephir_memory_observe(&eager);
	_6 = zephir_array_isset_string_fetch(&eager, &params, SL("eager"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_6) {
		ZEPHIR_CALL_METHOD(&resultset, &query, "execute", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&resultset) == IS_OBJECT) {
			ZEPHIR_CALL_SELF(NULL, "loadEager", &_7, 0, &resultset, &eager, &params);
			zephir_check_call_status();
			ZEPHIR_RETURN_CALL_METHOD(&resultset, "getFirst", NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETURN_CCTOR(&resultset);
	}
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &query, "setUniqueRow", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&query, "execute", NULL, 0);
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
 *
 * @phpstan-param mvc_model_parameters|string|null $parameters
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
	ZEPHIR_RETURN_CALL_SELF("groupResult", NULL, 0, &_0, &_1, parameters);
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
 *
 * @phpstan-param mvc_model_parameters|string|null $parameters
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
	ZEPHIR_RETURN_CALL_SELF("groupResult", NULL, 0, &_0, &_1, parameters);
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
		ZEPHIR_CALL_CE_STATIC(container, phalcon_di_di_ce, "getDefault", NULL, 0);
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

		ZEPHIR_CALL_METHOD(NULL, &criteria, "setDI", NULL, 0, container);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_get_called_class(&_2);
	ZEPHIR_CALL_METHOD(NULL, &criteria, "setModelName", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_CCTOR(&criteria);
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
 *
 * @phpstan-param mvc_model_parameters|string|null $parameters
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
	ZEPHIR_CALL_SELF(&result, "groupResult", NULL, 0, &_0, &_1, parameters);
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
	zend_bool _2, _3, _5, _6, _8, _9, _4$$8, _7$$13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval functionName_zv, alias_zv, *parameters = NULL, parameters_sub, __$null, params, distinctColumn, groupColumn, columns, resultset, cache, firstRow, groupColumns, builder, query, container, manager, transaction, bindParams, bindTypes, _0, _1, _10;
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
	ZVAL_UNDEF(&_10);
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
	ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_di_ce, "getDefault", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "modelsManager");
	ZEPHIR_CALL_METHOD(&_0, &container, "getShared", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_0);
	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
		if (Z_TYPE_P(parameters) != IS_NULL) {
			zephir_array_append(&params, parameters, PH_SEPARATE, "phalcon/Mvc/Model.zep", 1828);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	zephir_memory_observe(&groupColumn);
	_2 = zephir_array_isset_string_fetch(&groupColumn, &params, SL("column"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_2)) {
		ZEPHIR_INIT_NVAR(&groupColumn);
		ZVAL_STRING(&groupColumn, "*");
	}
	zephir_memory_observe(&distinctColumn);
	_3 = zephir_array_isset_string_fetch(&distinctColumn, &params, SL("distinct"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_3) {
		ZEPHIR_INIT_VAR(&columns);
		ZEPHIR_CONCAT_VSVSV(&columns, &functionName_zv, "(DISTINCT ", &distinctColumn, ") AS ", &alias_zv);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		zephir_memory_observe(&groupColumns);
		_4$$8 = zephir_array_isset_string_fetch(&groupColumns, &params, SL("group"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&columns);
		if (_4$$8) {
			ZEPHIR_CONCAT_VSVSVSV(&columns, &groupColumns, ", ", &functionName_zv, "(", &groupColumn, ") AS ", &alias_zv);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CONCAT_VSVSV(&columns, &functionName_zv, "(", &groupColumn, ") AS ", &alias_zv);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	ZEPHIR_CALL_METHOD(&_0, &manager, "createBuilder", NULL, 0, &params);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&builder, &_0);
	ZEPHIR_CALL_METHOD(NULL, &builder, "columns", NULL, 0, &columns);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	zephir_get_called_class(&_1);
	ZEPHIR_CALL_METHOD(NULL, &builder, "from", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &builder, "getQuery", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&query, &_0);
	zephir_memory_observe(&transaction);
	_5 = zephir_array_isset_string_fetch(&transaction, &params, SL("transaction"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_5) {
		if (zephir_instance_of_ev(&transaction, phalcon_mvc_model_transactioninterface_ce)) {
			ZEPHIR_CALL_METHOD(NULL, &query, "setTransaction", NULL, 0, &transaction);
			zephir_check_call_status();
		}
	}
	_6 = zephir_array_isset_value_string(&params, SL("bind"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_6) {
		ZEPHIR_OBS_NVAR(&bindParams);
		zephir_array_fetch_string(&bindParams, &params, SL("bind"), PH_NOISY, "phalcon/Mvc/Model.zep", 1871);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_7$$13 = zephir_array_isset_value_string(&params, SL("bindTypes"));
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_7$$13) {
			ZEPHIR_OBS_NVAR(&bindTypes);
			zephir_array_fetch_string(&bindTypes, &params, SL("bindTypes"), PH_NOISY, "phalcon/Mvc/Model.zep", 1874);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	zephir_memory_observe(&cache);
	_8 = zephir_array_isset_string_fetch(&cache, &params, SL("cache"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_8) {
		ZEPHIR_CALL_METHOD(NULL, &query, "cache", NULL, 0, &cache);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&resultset, &query, "execute", NULL, 0, &bindParams, &bindTypes);
	zephir_check_call_status();
	_9 = zephir_array_isset_value_string(&params, SL("group"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_9) {
		RETURN_CCTOR(&resultset);
	}
	ZEPHIR_CALL_METHOD(&firstRow, &resultset, "getFirst", NULL, 0);
	zephir_check_call_status();
	zephir_memory_observe(&_10);
	zephir_read_property_zval(&_10, &firstRow, &alias_zv, PH_NOISY_CC);
	RETURN_CCTOR(&_10);
}

/**
 * Try to check if the query must invoke a finder
 *
 * @return ModelInterface[]|ModelInterface|bool
 *
 * @phpstan-param array<array-key, mixed> $arguments
 * @phpstan-return false|int|ResultsetInterface|Row|static|null
 */
PHP_METHOD(Phalcon_Mvc_Model, invokeFinder)
{
	zend_class_entry *_19;
	zend_bool _4, _7, _12, _8$$10, _9$$12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments, _15$$14;
	zval method_zv, *arguments_param = NULL, extraMethod, type, modelName, value, model, attributes, field, extraMethodFirst, metaData, params, _3, _18, _0$$3, _1$$4, _2$$5, _5$$7, _6$$7, _10$$13, _11$$13, _13$$14, _14$$14, _16$$15, _17$$15;
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
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_10$$13);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_16$$15);
	ZVAL_UNDEF(&_17$$15);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&_15$$14);
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
	_4 = zephir_array_key_exists(&arguments, &_3);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_4))) {
		ZEPHIR_INIT_VAR(&_5$$7);
		object_init_ex(&_5$$7, phalcon_mvc_model_exceptions_staticmethodrequiresoneargument_ce);
		ZEPHIR_INIT_VAR(&_6$$7);
		zephir_get_called_class(&_6$$7);
		ZEPHIR_CALL_METHOD(NULL, &_5$$7, "__construct", NULL, 0, &method_zv, &_6$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$7, "phalcon/Mvc/Model.zep", 1954);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&model);
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&model, &modelName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&metaData, &model, "getModelsMetaData", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&attributes, &metaData, "getReverseColumnMap", NULL, 0, &model);
	zephir_check_call_status();
	if (Z_TYPE_P(&attributes) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&attributes, &metaData, "getDataTypes", NULL, 0, &model);
		zephir_check_call_status();
	}
	_7 = zephir_array_isset_value(&attributes, &extraMethod);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_7) {
		ZEPHIR_CPY_WRT(&field, &extraMethod);
	} else {
		ZEPHIR_CALL_FUNCTION(&extraMethodFirst, "lcfirst", NULL, 180, &extraMethod);
		zephir_check_call_status();
		_8$$10 = zephir_array_isset_value(&attributes, &extraMethodFirst);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_8$$10) {
			ZEPHIR_CPY_WRT(&field, &extraMethodFirst);
		} else {
			ZEPHIR_INIT_NVAR(&field);
			zephir_uncamelize(&field, &extraMethod, NULL );
			_9$$12 = zephir_array_isset_value(&attributes, &field);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (UNEXPECTED(!(_9$$12))) {
				ZEPHIR_INIT_VAR(&_10$$13);
				object_init_ex(&_10$$13, phalcon_mvc_model_exceptions_cannotresolveattribute_ce);
				ZEPHIR_INIT_VAR(&_11$$13);
				zephir_get_called_class(&_11$$13);
				ZEPHIR_CALL_METHOD(NULL, &_10$$13, "__construct", NULL, 0, &extraMethod, &_11$$13);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_10$$13, "phalcon/Mvc/Model.zep", 1989);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	zephir_memory_observe(&value);
	_12 = zephir_array_isset_long_fetch(&value, &arguments, 0, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_12;
	ZEPHIR_INIT_VAR(&params);
	if (Z_TYPE_P(&value) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_13$$14);
		zephir_create_array(&_13$$14, 2, 0);
		ZEPHIR_INIT_VAR(&_14$$14);
		ZEPHIR_CONCAT_SVS(&_14$$14, "[", &field, "] = ?0");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_13$$14, SL("conditions"), &_14$$14, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_15$$14);
		zephir_create_array(&_15$$14, 1, 0);
		zephir_array_fast_append(&_15$$14, &value);
		zephir_array_update_string(&_13$$14, SL("bind"), &_15$$14, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&params, &_13$$14);
	} else {
		ZEPHIR_INIT_VAR(&_16$$15);
		zephir_create_array(&_16$$15, 1, 0);
		ZEPHIR_INIT_VAR(&_17$$15);
		ZEPHIR_CONCAT_SVS(&_17$$15, "[", &field, "] IS NULL");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_16$$15, SL("conditions"), &_17$$15, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&params, &_16$$15);
	}
	zephir_array_unset_long(&arguments, 0, PH_SEPARATE);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_unset_string(&arguments, SL("conditions"), PH_SEPARATE);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_unset_string(&arguments, SL("bind"), PH_SEPARATE);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_18);
	zephir_fast_array_merge(&_18, &params, &arguments);
	ZEPHIR_CPY_WRT(&params, &_18);
	_19 = zephir_fetch_class(&modelName);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_CE_STATIC_ZVAL(_19, &type, NULL, 0, &params);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * shared prepare query logic for find and findFirst method
 *
 * @phpstan-param int|null $limit
 */
PHP_METHOD(Phalcon_Mvc_Model, getPreparedQuery)
{
	zend_bool _2, _6, _7, _4$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params, params_sub, *limit = NULL, limit_sub, __$null, builder, bindParams, bindTypes, transaction, cache, manager, query, container, _0, _1, _3$$5, _5$$7;

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
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$7);
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
	ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_di_ce, "getDefault", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "modelsManager");
	ZEPHIR_CALL_METHOD(&_0, &container, "getShared", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&_0, &manager, "createBuilder", NULL, 0, params);
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
	ZEPHIR_CALL_METHOD(&_0, &builder, "getQuery", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&query, &_0);
	zephir_memory_observe(&bindParams);
	_2 = zephir_array_isset_string_fetch(&bindParams, params, SL("bind"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_2) {
		if (Z_TYPE_P(&bindParams) == IS_ARRAY) {
			ZVAL_BOOL(&_3$$5, 1);
			ZEPHIR_CALL_METHOD(NULL, &query, "setBindParams", NULL, 0, &bindParams, &_3$$5);
			zephir_check_call_status();
		}
		zephir_memory_observe(&bindTypes);
		_4$$4 = zephir_array_isset_string_fetch(&bindTypes, params, SL("bindTypes"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_4$$4) {
			if (Z_TYPE_P(&bindTypes) == IS_ARRAY) {
				ZVAL_BOOL(&_5$$7, 1);
				ZEPHIR_CALL_METHOD(NULL, &query, "setBindTypes", NULL, 0, &bindTypes, &_5$$7);
				zephir_check_call_status();
			}
		}
	}
	zephir_memory_observe(&transaction);
	_6 = zephir_array_isset_string_fetch(&transaction, params, SL("transaction"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_6) {
		if (zephir_instance_of_ev(&transaction, phalcon_mvc_model_transactioninterface_ce)) {
			ZEPHIR_CALL_METHOD(NULL, &query, "setTransaction", NULL, 0, &transaction);
			zephir_check_call_status();
		}
	}
	zephir_memory_observe(&cache);
	_7 = zephir_array_isset_string_fetch(&cache, params, SL("cache"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_7) {
		ZEPHIR_CALL_METHOD(NULL, &query, "cache", NULL, 0, &cache);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&query);
}

/**
 * shared prepare query logic for find and findFirst method
 *
 * @phpstan-param object $resultset
 * @phpstan-param mvc_model_parameters $params
 */
PHP_METHOD(Phalcon_Mvc_Model, loadEager)
{
	zend_bool _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params;
	zval *resultset, resultset_sub, *eager, eager_sub, *params_param = NULL, container, hydration, loader, manager, _5, _6, _0$$3, _1$$4, _2$$4, _4$$6;

	ZVAL_UNDEF(&resultset_sub);
	ZVAL_UNDEF(&eager_sub);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&hydration);
	ZVAL_UNDEF(&loader);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$6);
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
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model.zep", 2098);
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
		zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/Model.zep", 2102);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&hydration);
	_3 = zephir_array_isset_string_fetch(&hydration, &params, SL("hydration"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_3) {
		if (UNEXPECTED(!ZEPHIR_IS_LONG_IDENTICAL(&hydration, 0))) {
			ZEPHIR_INIT_VAR(&_4$$6);
			object_init_ex(&_4$$6, phalcon_mvc_model_exceptions_unsupportedeagerhydration_ce);
			ZEPHIR_CALL_METHOD(NULL, &_4$$6, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_4$$6, "phalcon/Mvc/Model.zep", 2107);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_di_ce, "getDefault", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "modelsManager");
	ZEPHIR_CALL_METHOD(&_5, &container, "getShared", NULL, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_5);
	ZEPHIR_INIT_VAR(&loader);
	object_init_ex(&loader, phalcon_mvc_model_eager_loader_ce);
	ZEPHIR_CALL_METHOD(NULL, &loader, "__construct", NULL, 0, &manager);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_6);
	zephir_get_called_class(&_6);
	ZEPHIR_CALL_CE_STATIC(&_5, phalcon_mvc_model_eager_pathtree_ce, "parse", NULL, 0, eager);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &loader, "loadResultset", NULL, 0, resultset, &_6, &_5);
	zephir_check_call_status();
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "addBehavior", NULL, 0, this_ptr, behavior);
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
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_THISW();
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
	ZEPHIR_CALL_METHOD(&messages, model, "getMessages", NULL, 0);
	zephir_check_call_status();
	if (0 == ZEPHIR_IS_EMPTY(&messages)) {
		if (Z_TYPE_P(&messages) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_string_to_char_array(&_1$$3, &messages);
			_0$$3 = &_1$$3;
		} else {
			_0$$3 = &messages;
		}
		zephir_is_iterable(_0$$3, 0, "phalcon/Mvc/Model.zep", 2213);
		if (Z_TYPE_P(_0$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_0$$3), _2$$3)
			{
				ZEPHIR_INIT_NVAR(&message);
				ZVAL_COPY(&message, _2$$3);
				if (Z_TYPE_P(&message) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_3$$5);
					zephir_create_array(&_3$$5, 1, 0);
					zephir_array_update_string(&_3$$5, SL("model"), model, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &message, "setMetaData", NULL, 0, &_3$$5);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessage", &_4, 0, &message);
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
						ZEPHIR_CALL_METHOD(NULL, &message, "setMetaData", NULL, 0, &_7$$7);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessage", &_4, 0, &message);
					zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&message);
	}
	ZEPHIR_MM_RESTORE();
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
 *
 * @phpstan-param mvc_model_data $data
 */
PHP_METHOD(Phalcon_Mvc_Model, assign)
{
	zend_string *_3$$3;
	zend_ulong _2$$3;
	zend_bool _34, _6$$3, _4$$4, _7$$6, _12$$12, _13$$12, _14$$12, _26$$12, _20$$14, _27$$18, _28$$18, _29$$18, _30$$18, _35$$22, _36$$22, _37$$22, _47$$22, _41$$24, _48$$28, _49$$28, _50$$28, _51$$28;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_16 = NULL, *_19 = NULL, *_25 = NULL, *_32 = NULL, *_46 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *whiteList = NULL, whiteList_sub, *dataColumnMap = NULL, dataColumnMap_sub, __$null, key, keyMapped, value, attribute, attributeField, metaData, columnMap, disableAssignSetters, rawValues, _0, _8, _9, *_10, *_11, _33, *_1$$3, _5$$3, _15$$12, _17$$12, _18$$13, _21$$15, _22$$15, _23$$16, _24$$16, _31$$18, _38$$22, _39$$22, _40$$23, _42$$25, _43$$25, _44$$26, _45$$26, _52$$28;
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
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_23$$16);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_31$$18);
	ZVAL_UNDEF(&_38$$22);
	ZVAL_UNDEF(&_39$$22);
	ZVAL_UNDEF(&_40$$23);
	ZVAL_UNDEF(&_42$$25);
	ZVAL_UNDEF(&_43$$25);
	ZVAL_UNDEF(&_44$$26);
	ZVAL_UNDEF(&_45$$26);
	ZVAL_UNDEF(&_52$$28);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1019, &rawValues);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "orm.disable_assign_setters");
	ZEPHIR_CALL_CE_STATIC(&disableAssignSetters, phalcon_support_settings_ce, "get", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(dataColumnMap) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&dataMapped);
		array_init(&dataMapped);
		zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 2288);
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
				_4$$4 = zephir_array_isset_fetch(&keyMapped, dataColumnMap, &key, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_4$$4) {
					zephir_array_update_zval(&dataMapped, &keyMapped, &value, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
			zephir_check_call_status();
			_6$$3 = 1;
			while (1) {
				if (_6$$3) {
					_6$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_5$$3, &data, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&keyMapped);
					_7$$6 = zephir_array_isset_fetch(&keyMapped, dataColumnMap, &key, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_7$$6) {
						zephir_array_update_zval(&dataMapped, &keyMapped, &value, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
			zephir_throw_variable_type_error(&data, "dataMapped", "array");
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&dataMapped, &data);
	}
	if (ZEPHIR_IS_EMPTY(&dataMapped)) {
		RETURN_THIS();
	}
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getModelsMetaData", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "orm.column_renaming");
	ZEPHIR_CALL_CE_STATIC(&_8, phalcon_support_settings_ce, "get", NULL, 0, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_8)) {
		ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getColumnMap", NULL, 0, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&columnMap);
		ZVAL_NULL(&columnMap);
	}
	ZEPHIR_CALL_METHOD(&_9, &metaData, "getAttributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (Z_TYPE_P(&_9) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_0);
		zephir_string_to_char_array(&_0, &_9);
		_10 = &_0;
	} else {
		_10 = &_9;
	}
	zephir_is_iterable(_10, 0, "phalcon/Mvc/Model.zep", 2345);
	if (Z_TYPE_P(_10) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_10), _11)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _11);
			_12$$12 = Z_TYPE_P(&columnMap) == IS_ARRAY;
			if (_12$$12) {
				_13$$12 = zephir_array_isset_value(&columnMap, &attribute);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_12$$12 = !(_13$$12);
			}
			_14$$12 = _12$$12;
			if (_14$$12) {
				ZEPHIR_INIT_NVAR(&_17$$12);
				ZVAL_STRING(&_17$$12, "orm.case_insensitive_column_map");
				ZEPHIR_CALL_CE_STATIC(&_15$$12, phalcon_support_settings_ce, "get", &_16, 0, &_17$$12);
				zephir_check_call_status();
				_14$$12 = zephir_is_true(&_15$$12);
			}
			if (_14$$12) {
				ZEPHIR_CALL_CE_STATIC(&_18$$13, phalcon_mvc_model_hydration_caseinsensitivecolumnmap_ce, "caseInsensitiveColumnMap", &_19, 0, &columnMap, &attribute);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&attribute, &_18$$13);
			}
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				_20$$14 = zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_20$$14)) {
					ZEPHIR_INIT_NVAR(&_22$$15);
					ZVAL_STRING(&_22$$15, "orm.ignore_unknown_columns");
					ZEPHIR_CALL_CE_STATIC(&_21$$15, phalcon_support_settings_ce, "get", &_16, 0, &_22$$15);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&_21$$15))) {
						ZEPHIR_INIT_NVAR(&_23$$16);
						object_init_ex(&_23$$16, phalcon_mvc_model_exceptions_columnnotinmap_ce);
						ZEPHIR_INIT_NVAR(&_24$$16);
						zephir_get_class(&_24$$16, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_23$$16, "__construct", &_25, 0, &attribute, &_24$$16);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_23$$16, "phalcon/Mvc/Model.zep", 2319);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &attribute);
			}
			ZEPHIR_OBS_NVAR(&value);
			_26$$12 = zephir_array_isset_fetch(&value, &dataMapped, &attributeField, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_26$$12) {
				_27$$18 = Z_TYPE_P(whiteList) == IS_ARRAY;
				if (_27$$18) {
					_28$$18 = zephir_fast_in_array(&attributeField, whiteList);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_27$$18 = !(_28$$18);
				}
				if (_27$$18) {
					continue;
				}
				_29$$18 = Z_TYPE_P(&value) == IS_OBJECT;
				if (_29$$18) {
					_29$$18 = zephir_instance_of_ev(&value, phalcon_db_rawvalue_ce);
				}
				if (_29$$18) {
					zephir_array_update_zval(&rawValues, &attributeField, &value, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					_30$$18 = zephir_is_true(&disableAssignSetters);
					if (!(_30$$18)) {
						ZEPHIR_CALL_METHOD(&_31$$18, this_ptr, "possibleSetter", &_32, 0, &attributeField, &value);
						zephir_check_call_status();
						_30$$18 = !zephir_is_true(&_31$$18);
					}
					if (_30$$18) {
						zephir_update_property_zval_zval(this_ptr, &attributeField, &value);
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _10, "rewind", NULL, 0);
		zephir_check_call_status();
		_34 = 1;
		while (1) {
			if (_34) {
				_34 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _10, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_33, _10, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_33)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attribute, _10, "current", NULL, 0);
			zephir_check_call_status();
				_35$$22 = Z_TYPE_P(&columnMap) == IS_ARRAY;
				if (_35$$22) {
					_36$$22 = zephir_array_isset_value(&columnMap, &attribute);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_35$$22 = !(_36$$22);
				}
				_37$$22 = _35$$22;
				if (_37$$22) {
					ZEPHIR_INIT_NVAR(&_39$$22);
					ZVAL_STRING(&_39$$22, "orm.case_insensitive_column_map");
					ZEPHIR_CALL_CE_STATIC(&_38$$22, phalcon_support_settings_ce, "get", &_16, 0, &_39$$22);
					zephir_check_call_status();
					_37$$22 = zephir_is_true(&_38$$22);
				}
				if (_37$$22) {
					ZEPHIR_CALL_CE_STATIC(&_40$$23, phalcon_mvc_model_hydration_caseinsensitivecolumnmap_ce, "caseInsensitiveColumnMap", &_19, 0, &columnMap, &attribute);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&attribute, &_40$$23);
				}
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					_41$$24 = zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_41$$24)) {
						ZEPHIR_INIT_NVAR(&_43$$25);
						ZVAL_STRING(&_43$$25, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_42$$25, phalcon_support_settings_ce, "get", &_16, 0, &_43$$25);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_42$$25))) {
							ZEPHIR_INIT_NVAR(&_44$$26);
							object_init_ex(&_44$$26, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							ZEPHIR_INIT_NVAR(&_45$$26);
							zephir_get_class(&_45$$26, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_44$$26, "__construct", &_46, 0, &attribute, &_45$$26);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_44$$26, "phalcon/Mvc/Model.zep", 2319);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &attribute);
				}
				ZEPHIR_OBS_NVAR(&value);
				_47$$22 = zephir_array_isset_fetch(&value, &dataMapped, &attributeField, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_47$$22) {
					_48$$28 = Z_TYPE_P(whiteList) == IS_ARRAY;
					if (_48$$28) {
						_49$$28 = zephir_fast_in_array(&attributeField, whiteList);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_48$$28 = !(_49$$28);
					}
					if (_48$$28) {
						continue;
					}
					_50$$28 = Z_TYPE_P(&value) == IS_OBJECT;
					if (_50$$28) {
						_50$$28 = zephir_instance_of_ev(&value, phalcon_db_rawvalue_ce);
					}
					if (_50$$28) {
						zephir_array_update_zval(&rawValues, &attributeField, &value, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						_51$$28 = zephir_is_true(&disableAssignSetters);
						if (!(_51$$28)) {
							ZEPHIR_CALL_METHOD(&_52$$28, this_ptr, "possibleSetter", &_32, 0, &attributeField, &value);
							zephir_check_call_status();
							_51$$28 = !zephir_is_true(&_52$$28);
						}
						if (_51$$28) {
							zephir_update_property_zval_zval(this_ptr, &attributeField, &value);
						}
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&attribute);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1019, &rawValues);
	RETURN_THIS();
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

	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getModelsMetaData", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getWriteConnection", NULL, 0);
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
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 3, &_5$$3, &_6$$3, &_7$$3, &_8$$3, &_4$$3);
		zephir_check_call_status();
		zephir_array_fast_append(&_2$$3, &_3$$3);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1020, &_2$$3);
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
	zend_bool _25, _10$$8, _14$$10, _26$$14, _30$$16;
	zval values, bindTypes, conditions;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, metaData, writeConnection, primaryKeys, bindDataTypes, columnMap, attributeField, primaryKey, bindType, value, schema, source, table, success, _0, _1, _2, _3, _5, *_8, *_9, _24, _40, _41, _45, _46, _48, _4$$3, _6$$7, _7$$7, _21$$8, _23$$8, _11$$9, _12$$9, _15$$11, _16$$11, _18$$13, _19$$13, _37$$14, _39$$14, _27$$15, _28$$15, _31$$17, _32$$17, _34$$19, _35$$19, _42$$20, _43$$20, _44$$20, _47$$25, _49$$28, _50$$29, _51$$29, _52$$29, _53$$29;
	zephir_fcall_cache_entry *_13 = NULL, *_17 = NULL, *_20 = NULL, *_22 = NULL, *_29 = NULL, *_33 = NULL, *_36 = NULL, *_38 = NULL;
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
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_45);
	ZVAL_UNDEF(&_46);
	ZVAL_UNDEF(&_48);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_37$$14);
	ZVAL_UNDEF(&_39$$14);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_28$$15);
	ZVAL_UNDEF(&_31$$17);
	ZVAL_UNDEF(&_32$$17);
	ZVAL_UNDEF(&_34$$19);
	ZVAL_UNDEF(&_35$$19);
	ZVAL_UNDEF(&_42$$20);
	ZVAL_UNDEF(&_43$$20);
	ZVAL_UNDEF(&_44$$20);
	ZVAL_UNDEF(&_47$$25);
	ZVAL_UNDEF(&_49$$28);
	ZVAL_UNDEF(&_50$$29);
	ZVAL_UNDEF(&_51$$29);
	ZVAL_UNDEF(&_52$$29);
	ZVAL_UNDEF(&_53$$29);
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

	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getModelsMetaData", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&writeConnection, this_ptr, "getWriteConnection", NULL, 0);
	zephir_check_call_status();
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, 3);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1021, &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1020, &_1);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "orm.virtual_foreign_keys");
	ZEPHIR_CALL_CE_STATIC(&_2, phalcon_support_settings_ce, "get", NULL, 0, &_3);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "checkForeignKeysReverseRestrict", NULL, 0);
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
	ZEPHIR_CALL_METHOD(&primaryKeys, &metaData, "getPrimaryKeyAttributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&bindDataTypes, &metaData, "getBindTypes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "orm.column_renaming");
	ZEPHIR_CALL_CE_STATIC(&_5, phalcon_support_settings_ce, "get", NULL, 0, &_3);
	zephir_check_call_status();
	if (zephir_is_true(&_5)) {
		ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getColumnMap", NULL, 0, this_ptr);
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
		zephir_throw_exception_debug(&_6$$7, "phalcon/Mvc/Model.zep", 2468);
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
	zephir_is_iterable(_8, 0, "phalcon/Mvc/Model.zep", 2510);
	if (Z_TYPE_P(_8) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_8), _9)
		{
			ZEPHIR_INIT_NVAR(&primaryKey);
			ZVAL_COPY(&primaryKey, _9);
			ZEPHIR_OBS_NVAR(&bindType);
			_10$$8 = zephir_array_isset_fetch(&bindType, &bindDataTypes, &primaryKey, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (UNEXPECTED(!(_10$$8))) {
				ZEPHIR_INIT_NVAR(&_11$$9);
				object_init_ex(&_11$$9, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
				ZEPHIR_INIT_NVAR(&_12$$9);
				zephir_get_class(&_12$$9, this_ptr, 0);
				ZEPHIR_CALL_METHOD(NULL, &_11$$9, "__construct", &_13, 0, &primaryKey, &_12$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_11$$9, "phalcon/Mvc/Model.zep", 2480);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				_14$$10 = zephir_array_isset_fetch(&attributeField, &columnMap, &primaryKey, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_14$$10))) {
					ZEPHIR_INIT_NVAR(&_15$$11);
					object_init_ex(&_15$$11, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
					ZEPHIR_INIT_NVAR(&_16$$11);
					zephir_get_class(&_16$$11, this_ptr, 0);
					ZEPHIR_CALL_METHOD(NULL, &_15$$11, "__construct", &_17, 0, &primaryKey, &_16$$11);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_15$$11, "phalcon/Mvc/Model.zep", 2488);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &primaryKey);
			}
			ZEPHIR_OBS_NVAR(&value);
			if (UNEXPECTED(!(zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)))) {
				ZEPHIR_INIT_NVAR(&_18$$13);
				object_init_ex(&_18$$13, phalcon_mvc_model_exceptions_primarykeyattributenotset_ce);
				ZEPHIR_INIT_NVAR(&_19$$13);
				zephir_get_class(&_19$$13, this_ptr, 0);
				ZEPHIR_CALL_METHOD(NULL, &_18$$13, "__construct", &_20, 0, &attributeField, &_19$$13);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_18$$13, "phalcon/Mvc/Model.zep", 2499);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2505);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&_21$$8, &writeConnection, "escapeIdentifier", &_22, 0, &primaryKey);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_23$$8);
			ZEPHIR_CONCAT_VS(&_23$$8, &_21$$8, " = ?");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&conditions, &_23$$8, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2506);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2507);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _8, "rewind", NULL, 0);
		zephir_check_call_status();
		_25 = 1;
		while (1) {
			if (_25) {
				_25 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _8, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_24, _8, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_24)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&primaryKey, _8, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&bindType);
				_26$$14 = zephir_array_isset_fetch(&bindType, &bindDataTypes, &primaryKey, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_26$$14))) {
					ZEPHIR_INIT_NVAR(&_27$$15);
					object_init_ex(&_27$$15, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
					ZEPHIR_INIT_NVAR(&_28$$15);
					zephir_get_class(&_28$$15, this_ptr, 0);
					ZEPHIR_CALL_METHOD(NULL, &_27$$15, "__construct", &_29, 0, &primaryKey, &_28$$15);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_27$$15, "phalcon/Mvc/Model.zep", 2480);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					_30$$16 = zephir_array_isset_fetch(&attributeField, &columnMap, &primaryKey, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_30$$16))) {
						ZEPHIR_INIT_NVAR(&_31$$17);
						object_init_ex(&_31$$17, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
						ZEPHIR_INIT_NVAR(&_32$$17);
						zephir_get_class(&_32$$17, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_31$$17, "__construct", &_33, 0, &primaryKey, &_32$$17);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_31$$17, "phalcon/Mvc/Model.zep", 2488);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &primaryKey);
				}
				ZEPHIR_OBS_NVAR(&value);
				if (UNEXPECTED(!(zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)))) {
					ZEPHIR_INIT_NVAR(&_34$$19);
					object_init_ex(&_34$$19, phalcon_mvc_model_exceptions_primarykeyattributenotset_ce);
					ZEPHIR_INIT_NVAR(&_35$$19);
					zephir_get_class(&_35$$19, this_ptr, 0);
					ZEPHIR_CALL_METHOD(NULL, &_34$$19, "__construct", &_36, 0, &attributeField, &_35$$19);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_34$$19, "phalcon/Mvc/Model.zep", 2499);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2505);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&_37$$14, &writeConnection, "escapeIdentifier", &_38, 0, &primaryKey);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_39$$14);
				ZEPHIR_CONCAT_VS(&_39$$14, &_37$$14, " = ?");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&conditions, &_39$$14, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2506);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2507);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&primaryKey);
	ZEPHIR_INIT_VAR(&_41);
	ZVAL_STRING(&_41, "orm.events");
	ZEPHIR_CALL_CE_STATIC(&_40, phalcon_support_settings_ce, "get", NULL, 0, &_41);
	zephir_check_call_status();
	if (zephir_is_true(&_40)) {
		if (0) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1022, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1022, &__$false);
		}
		ZEPHIR_INIT_VAR(&_43$$20);
		ZVAL_STRING(&_43$$20, "beforeDelete");
		ZEPHIR_CALL_METHOD(&_42$$20, this_ptr, "fireEventCancel", NULL, 0, &_43$$20);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_42$$20)) {
			RETURN_MM_BOOL(0);
		}
		zephir_read_property_cached(&_44$$20, this_ptr, _zephir_prop_2, 1022, PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_44$$20)) {
			RETURN_MM_BOOL(1);
		}
	}
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getSchema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getSource", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	ZEPHIR_INIT_NVAR(&_41);
	zephir_fast_join_str(&_41, SL(" AND "), &conditions);
	ZEPHIR_CALL_METHOD(&success, &writeConnection, "delete", NULL, 0, &table, &_41, &values, &bindTypes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_46);
	ZVAL_STRING(&_46, "orm.virtual_foreign_keys");
	ZEPHIR_CALL_CE_STATIC(&_45, phalcon_support_settings_ce, "get", NULL, 0, &_46);
	zephir_check_call_status();
	if (zephir_is_true(&_45)) {
		ZEPHIR_CALL_METHOD(&_47$$25, this_ptr, "checkForeignKeysReverseCascade", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_47$$25)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(&_46);
	ZVAL_STRING(&_46, "orm.events");
	ZEPHIR_CALL_CE_STATIC(&_48, phalcon_support_settings_ce, "get", NULL, 0, &_46);
	zephir_check_call_status();
	if (zephir_is_true(&_48)) {
		if (zephir_is_true(&success)) {
			ZEPHIR_INIT_VAR(&_49$$28);
			ZVAL_STRING(&_49$$28, "afterDelete");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireEvent", NULL, 0, &_49$$28);
			zephir_check_call_status();
		}
	}
	if (zephir_is_true(&success)) {
		zephir_read_property_cached(&_50$$29, this_ptr, _zephir_prop_3, 1014, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_50$$29, "registerWrite", NULL, 0, this_ptr);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_51$$29);
		array_init(&_51$$29);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1016, &_51$$29);
		ZEPHIR_INIT_VAR(&_52$$29);
		array_init(&_52$$29);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1015, &_52$$29);
		zephir_read_property_cached(&_53$$29, this_ptr, _zephir_prop_3, 1014, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_53$$29, "clearReusableObjects", NULL, 0);
		zephir_check_call_status();
	}
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, 2);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 1017, &_0);
	RETURN_CCTOR(&success);
}

/**
 * Inserted or updates model instance, expects a visited list of objects.
 *
 * @param CollectionInterface $visited
 *
 * @return bool
 *
 * @phpstan-param CollectionInterface<mixed> $visited
 */
PHP_METHOD(Phalcon_Mvc_Model, doSave)
{
	zend_bool hasRelatedToSave = 0, _15, _23$$21;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *visited, visited_sub, exists, identityField, manager, metaData, objId, relatedToSave, schema, source, success, table, writeConnection, savedSnapshot, savedOldSnapshot, _0, _1, _7, _14, _16, _17, _20, _3$$4, _4$$5, _5$$8, _6$$9, _8$$11, _9$$10, _10$$10, _11$$10, _12$$12, _13$$12, _18$$16, _19$$18, _21$$20, _22$$21, _24$$21, _25$$21, _26$$24, _27$$23, _28$$23, _29$$23;
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
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_18$$16);
	ZVAL_UNDEF(&_19$$18);
	ZVAL_UNDEF(&_21$$20);
	ZVAL_UNDEF(&_22$$21);
	ZVAL_UNDEF(&_24$$21);
	ZVAL_UNDEF(&_25$$21);
	ZVAL_UNDEF(&_26$$24);
	ZVAL_UNDEF(&_27$$23);
	ZVAL_UNDEF(&_28$$23);
	ZVAL_UNDEF(&_29$$23);
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
	ZEPHIR_CALL_FUNCTION(&objId, "spl_object_id", NULL, 51, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, visited, "has", NULL, 0, &objId);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_METHOD(NULL, visited, "set", NULL, 0, &objId, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getModelsMetaData", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&writeConnection, this_ptr, "getWriteConnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "prepareSave");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireEvent", &_2, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&relatedToSave, this_ptr, "collectRelatedToSave", NULL, 0);
	zephir_check_call_status();
	hasRelatedToSave = !(ZEPHIR_IS_EMPTY(&relatedToSave));
	if (hasRelatedToSave) {
		ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "preSaveRelatedRecords", NULL, 0, &writeConnection, &relatedToSave, visited);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_3$$4)) {
			ZEPHIR_INIT_VAR(&_4$$5);
			array_init(&_4$$5);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1023, &_4$$5);
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getSchema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getSource", NULL, 0);
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
		ZVAL_UNDEF(&_5$$8);
		ZVAL_LONG(&_5$$8, 2);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1021, &_5$$8);
	} else {
		ZVAL_UNDEF(&_6$$9);
		ZVAL_LONG(&_6$$9, 1);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1021, &_6$$9);
	}
	ZEPHIR_INIT_NVAR(&_1);
	array_init(&_1);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1020, &_1);
	ZEPHIR_CALL_METHOD(&identityField, &metaData, "getIdentityField", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "preSave", NULL, 0, &metaData, &exists, &identityField);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_7)) {
		if (hasRelatedToSave) {
			ZVAL_BOOL(&_8$$11, 0);
			ZEPHIR_CALL_METHOD(NULL, &writeConnection, "rollback", NULL, 0, &_8$$11);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(&_9$$10);
		array_init(&_9$$10);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1023, &_9$$10);
		ZEPHIR_INIT_VAR(&_11$$10);
		ZVAL_STRING(&_11$$10, "orm.exception_on_failed_save");
		ZEPHIR_CALL_CE_STATIC(&_10$$10, phalcon_support_settings_ce, "get", NULL, 0, &_11$$10);
		zephir_check_call_status();
		if (UNEXPECTED(zephir_is_true(&_10$$10))) {
			ZEPHIR_INIT_VAR(&_12$$12);
			object_init_ex(&_12$$12, phalcon_mvc_model_validationfailed_ce);
			ZEPHIR_CALL_METHOD(&_13$$12, this_ptr, "getMessages", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_12$$12, "__construct", NULL, 0, this_ptr, &_13$$12);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_12$$12, "phalcon/Mvc/Model.zep", 2699);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&manager, this_ptr, "getModelsManager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_14, &manager, "isKeepingSnapshots", NULL, 0, this_ptr);
	zephir_check_call_status();
	_15 = zephir_is_true(&_14);
	if (_15) {
		ZEPHIR_INIT_VAR(&_17);
		ZVAL_STRING(&_17, "orm.update_snapshot_on_save");
		ZEPHIR_CALL_CE_STATIC(&_16, phalcon_support_settings_ce, "get", NULL, 0, &_17);
		zephir_check_call_status();
		_15 = zephir_is_true(&_16);
	}
	if (_15) {
		ZEPHIR_OBS_NVAR(&savedSnapshot);
		zephir_read_property_cached(&savedSnapshot, this_ptr, _zephir_prop_3, 1018, PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(&savedOldSnapshot);
		zephir_read_property_cached(&savedOldSnapshot, this_ptr, _zephir_prop_4, 1024, PH_NOISY_CC);
	}
	if (zephir_is_true(&exists)) {
		ZEPHIR_CALL_METHOD(&success, this_ptr, "doLowUpdate", NULL, 0, &metaData, &writeConnection, &table);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&success, this_ptr, "doLowInsert", NULL, 0, &metaData, &writeConnection, &table, &identityField);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_TRUE_IDENTICAL(&success)) {
		ZVAL_UNDEF(&_18$$16);
		ZVAL_LONG(&_18$$16, 0);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1017, &_18$$16);
	}
	if (hasRelatedToSave) {
		if (ZEPHIR_IS_FALSE_IDENTICAL(&success)) {
			ZVAL_BOOL(&_19$$18, 0);
			ZEPHIR_CALL_METHOD(NULL, &writeConnection, "rollback", NULL, 0, &_19$$18);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&success, this_ptr, "postSaveRelatedRecords", NULL, 0, &writeConnection, &relatedToSave, visited);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&_17);
	ZVAL_STRING(&_17, "orm.events");
	ZEPHIR_CALL_CE_STATIC(&_20, phalcon_support_settings_ce, "get", NULL, 0, &_17);
	zephir_check_call_status();
	if (zephir_is_true(&_20)) {
		ZEPHIR_CALL_METHOD(&_21$$20, this_ptr, "postSave", NULL, 0, &success, &exists);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&success, &_21$$20);
	}
	if (ZEPHIR_IS_FALSE_IDENTICAL(&success)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "cancelOperation", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_22$$21, &manager, "isKeepingSnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		_23$$21 = zephir_is_true(&_22$$21);
		if (_23$$21) {
			ZEPHIR_INIT_VAR(&_25$$21);
			ZVAL_STRING(&_25$$21, "orm.update_snapshot_on_save");
			ZEPHIR_CALL_CE_STATIC(&_24$$21, phalcon_support_settings_ce, "get", NULL, 0, &_25$$21);
			zephir_check_call_status();
			_23$$21 = zephir_is_true(&_24$$21);
		}
		if (_23$$21) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1018, &savedSnapshot);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1024, &savedOldSnapshot);
		}
	} else {
		if (hasRelatedToSave) {
			ZEPHIR_INIT_VAR(&_26$$24);
			array_init(&_26$$24);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 1015, &_26$$24);
		}
		ZEPHIR_INIT_VAR(&_27$$23);
		array_init(&_27$$23);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 1016, &_27$$23);
		zephir_read_property_cached(&_28$$23, this_ptr, _zephir_prop_8, 1014, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_28$$23, "clearReusableObjects", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_29$$23);
		ZVAL_STRING(&_29$$23, "afterSave");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireEvent", &_2, 0, &_29$$23);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_17);
	array_init(&_17);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1023, &_17);
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
 *
 * @phpstan-return array<string, mixed>
 */
PHP_METHOD(Phalcon_Mvc_Model, dump)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_RETURN_CALL_FUNCTION("get_object_vars", NULL, 358, this_ptr);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "notifyEvent", NULL, 0, &eventName_zv, this_ptr);
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
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_1, "notifyEvent", NULL, 0, &eventName_zv, this_ptr);
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
 *
 * @phpstan-return list<string>
 */
PHP_METHOD(Phalcon_Mvc_Model, getChangedFields)
{
	zend_bool _12, _9$$6, _13$$10;
	zend_string *_8;
	zend_ulong _7;
	zval changed;
	zval metaData, name, snapshot, columnMap, allAttributes, value, _0, *_3, _4, _5, *_6, _11, _1$$3, _2$$3, _10$$6, _14$$10;
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
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&changed);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("snapshot", 8, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1018, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&snapshot, &_0);
	if (UNEXPECTED(Z_TYPE_P(&snapshot) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_exceptions_snapshotsdisabled_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_get_class(&_2$$3, this_ptr, 0);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model.zep", 2878);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getModelsMetaData", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getReverseColumnMap", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (Z_TYPE_P(&columnMap) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&allAttributes, &metaData, "getDataTypes", NULL, 0, this_ptr);
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
	zephir_is_iterable(_3, 0, "phalcon/Mvc/Model.zep", 2939);
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
			_9$$6 = zephir_array_key_exists(&snapshot, &name);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_9$$6)) {
				zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2914);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				continue;
			}
			ZEPHIR_OBS_NVAR(&value);
			if (!(zephir_fetch_property_zval(&value, this_ptr, &name, PH_SILENT_CC))) {
				zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2924);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				continue;
			}
			ZEPHIR_OBS_NVAR(&_10$$6);
			zephir_array_fetch(&_10$$6, &snapshot, &name, PH_NOISY, "phalcon/Mvc/Model.zep", 2932);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!ZEPHIR_IS_IDENTICAL(&value, &_10$$6)) {
				zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2933);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				continue;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _3, "rewind", NULL, 0);
		zephir_check_call_status();
		_12 = 1;
		while (1) {
			if (_12) {
				_12 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _3, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_11, _3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, _3, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_5, _3, "current", NULL, 0);
			zephir_check_call_status();
				_13$$10 = zephir_array_key_exists(&snapshot, &name);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_13$$10)) {
					zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2914);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
				ZEPHIR_OBS_NVAR(&value);
				if (!(zephir_fetch_property_zval(&value, this_ptr, &name, PH_SILENT_CC))) {
					zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2924);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
				ZEPHIR_OBS_NVAR(&_14$$10);
				zephir_array_fetch(&_14$$10, &snapshot, &name, PH_NOISY, "phalcon/Mvc/Model.zep", 2932);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!ZEPHIR_IS_IDENTICAL(&value, &_14$$10)) {
					zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2933);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getCustomEventsManager", NULL, 0, this_ptr);
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
 *
 * @phpstan-return mvc_model_messages
 */
PHP_METHOD(Phalcon_Mvc_Model, getMessages)
{
	zend_bool _0, _1, _10$$3, _8$$5, _12$$7;
	zval filtered;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filter = NULL, filter_sub, __$null, message, _2$$4, _3$$3, *_4$$3, _5$$3, *_6$$3, _9$$3, _7$$5, _11$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_11$$7);
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
		zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_0, 1020, PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_3$$3) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_5$$3);
			zephir_string_to_char_array(&_5$$3, &_3$$3);
			_4$$3 = &_5$$3;
		} else {
			_4$$3 = &_3$$3;
		}
		zephir_is_iterable(_4$$3, 0, "phalcon/Mvc/Model.zep", 3005);
		if (Z_TYPE_P(_4$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_4$$3), _6$$3)
			{
				ZEPHIR_INIT_NVAR(&message);
				ZVAL_COPY(&message, _6$$3);
				ZEPHIR_CALL_METHOD(&_7$$5, &message, "getField", NULL, 0);
				zephir_check_call_status();
				_8$$5 = zephir_fast_in_array(&_7$$5, filter);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_8$$5) {
					zephir_array_append(&filtered, &message, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3001);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _4$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			_10$$3 = 1;
			while (1) {
				if (_10$$3) {
					_10$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _4$$3, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_9$$3, _4$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_9$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&message, _4$$3, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_11$$7, &message, "getField", NULL, 0);
					zephir_check_call_status();
					_12$$7 = zephir_fast_in_array(&_11$$7, filter);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_12$$7) {
						zephir_array_append(&filtered, &message, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3001);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
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
	zephir_read_property_cached(&metaData, this_ptr, _zephir_prop_0, 1025, PH_NOISY_CC);
	if (Z_TYPE_P(&metaData) == IS_NULL) {
		zephir_read_property_cached(&_0$$3, this_ptr, _zephir_prop_1, 1013, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&container, &_0$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "modelsMetadata");
		ZEPHIR_CALL_METHOD(&_1$$3, &container, "getShared", NULL, 0, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&metaData, &_1$$3);
		if (UNEXPECTED(Z_TYPE_P(&metaData) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_3$$4);
			object_init_ex(&_3$$4, phalcon_mvc_model_exceptions_invalidmodelsmetadataservice_ce);
			ZEPHIR_INIT_VAR(&_4$$4);
			zephir_get_class(&_4$$4, this_ptr, 0);
			ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", NULL, 0, &_4$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$4, "phalcon/Mvc/Model.zep", 3037);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1025, &metaData);
	}
	RETURN_CCTOR(&metaData);
}

/**
 * Returns the internal old snapshot data
 *
 * @phpstan-return mvc_model_snapshot
 */
PHP_METHOD(Phalcon_Mvc_Model, getOldSnapshotData)
{

	RETURN_MEMBER_TYPED(getThis(), "oldSnapshot", IS_ARRAY);
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1026, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 1026, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_1$$3, "getConnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_2, "getReadConnection", NULL, 0, this_ptr);
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getReadConnectionService", NULL, 0, this_ptr);
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
	zend_bool _4$$4, _8$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval alias_zv, *arguments = NULL, arguments_sub, __$null, relation, className, manager, result, lowerAlias, _0, _1, _2$$3, _3$$4, _7$$4, _5$$5, _6$$5, _9$$6, _10$$6;
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
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_INIT_VAR(&lowerAlias);
	zephir_fast_strtolower(&lowerAlias, &alias_zv);
	ZEPHIR_CALL_METHOD(&_1, &manager, "getRelationByAlias", NULL, 0, &className, &lowerAlias);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&relation, &_1);
	if (UNEXPECTED(Z_TYPE_P(&relation) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_mvc_model_exceptions_relationnotdefined_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 0, &className, &alias_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Mvc/Model.zep", 3112);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(arguments) == IS_NULL) {
		zephir_read_property_cached(&_3$$4, this_ptr, _zephir_prop_1, 1015, PH_NOISY_CC | PH_READONLY);
		_4$$4 = zephir_array_isset_value(&_3$$4, &lowerAlias);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_4$$4) {
			zephir_read_property_cached(&_5$$5, this_ptr, _zephir_prop_1, 1015, PH_NOISY_CC | PH_READONLY);
			zephir_memory_observe(&_6$$5);
			zephir_array_fetch(&_6$$5, &_5$$5, &lowerAlias, PH_NOISY, "phalcon/Mvc/Model.zep", 3137);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_CCTOR(&_6$$5);
		}
		zephir_read_property_cached(&_7$$4, this_ptr, _zephir_prop_2, 1016, PH_NOISY_CC | PH_READONLY);
		_8$$4 = zephir_array_key_exists(&_7$$4, &lowerAlias);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_8$$4) {
			zephir_read_property_cached(&_9$$6, this_ptr, _zephir_prop_2, 1016, PH_NOISY_CC | PH_READONLY);
			zephir_memory_observe(&_10$$6);
			zephir_array_fetch(&_10$$6, &_9$$6, &lowerAlias, PH_NOISY, "phalcon/Mvc/Model.zep", 3148);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_CCTOR(&_10$$6);
		}
		ZEPHIR_CALL_METHOD(&result, &manager, "getRelationRecords", NULL, 0, &relation, this_ptr, arguments);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("related"), &lowerAlias, &result);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_CALL_METHOD(&result, &manager, "getRelationRecords", NULL, 0, &relation, this_ptr, arguments);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&result);
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getModelSchema", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the internal snapshot data
 *
 * @phpstan-return mvc_model_snapshot
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getModelSource", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Mvc_Model, getTransaction)
{

	RETURN_MEMBER(getThis(), "transaction");
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
 *
 * @phpstan-return list<string>
 */
PHP_METHOD(Phalcon_Mvc_Model, getUpdatedFields)
{
	zend_bool _17, _13$$6, _14$$6, _18$$8, _19$$8;
	zend_string *_12;
	zend_ulong _11;
	zval updated;
	zval name, snapshot, oldSnapshot, value, _0, _1, _2, *_9, *_10, _16, _3$$3, _4$$3, _5$$4, _6$$4, _7$$5, _8$$5, _15$$6, _20$$8;
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
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_20$$8);
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1018, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&snapshot, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1024, PH_NOISY_CC | PH_READONLY);
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
		zephir_throw_exception_debug(&_3$$3, "phalcon/Mvc/Model.zep", 3233);
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
		zephir_throw_exception_debug(&_5$$4, "phalcon/Mvc/Model.zep", 3237);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 1017, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!ZEPHIR_IS_LONG(&_0, 0))) {
		ZEPHIR_INIT_VAR(&_7$$5);
		object_init_ex(&_7$$5, phalcon_mvc_model_exceptions_recordnotpersisted_ce);
		ZEPHIR_INIT_VAR(&_8$$5);
		zephir_get_class(&_8$$5, this_ptr, 0);
		ZEPHIR_CALL_METHOD(NULL, &_7$$5, "__construct", NULL, 0, &_8$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$5, "phalcon/Mvc/Model.zep", 3244);
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
	zephir_is_iterable(_9, 0, "phalcon/Mvc/Model.zep", 3262);
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
			_13$$6 = zephir_array_key_exists(&oldSnapshot, &name);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_14$$6 = !(_13$$6);
			if (!(_14$$6)) {
				ZEPHIR_OBS_NVAR(&_15$$6);
				zephir_array_fetch(&_15$$6, &oldSnapshot, &name, PH_NOISY, "phalcon/Mvc/Model.zep", 3257);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_14$$6 = !ZEPHIR_IS_IDENTICAL(&value, &_15$$6);
			}
			if (_14$$6) {
				zephir_array_append(&updated, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3258);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _9, "rewind", NULL, 0);
		zephir_check_call_status();
		_17 = 1;
		while (1) {
			if (_17) {
				_17 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _9, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_16, _9, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_16)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, _9, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, _9, "current", NULL, 0);
			zephir_check_call_status();
				_18$$8 = zephir_array_key_exists(&oldSnapshot, &name);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_19$$8 = !(_18$$8);
				if (!(_19$$8)) {
					ZEPHIR_OBS_NVAR(&_20$$8);
					zephir_array_fetch(&_20$$8, &oldSnapshot, &name, PH_NOISY, "phalcon/Mvc/Model.zep", 3257);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_19$$8 = !ZEPHIR_IS_IDENTICAL(&value, &_20$$8);
				}
				if (_19$$8) {
					zephir_array_append(&updated, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3258);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1026, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 1026, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_1$$3, "getConnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_2, "getWriteConnection", NULL, 0, this_ptr);
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getWriteConnectionService", NULL, 0, this_ptr);
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
 *
 * @phpstan-param list<string>|string|null $fieldName
 */
PHP_METHOD(Phalcon_Mvc_Model, hasChanged)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool allFields, _0$$3, _1$$5;
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
	ZEPHIR_CALL_METHOD(&changedFields, this_ptr, "getChangedFields", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(fieldName) == IS_STRING) {
		_0$$3 = zephir_fast_in_array(fieldName, &changedFields);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_BOOL(_0$$3);
	}
	if (Z_TYPE_P(fieldName) == IS_ARRAY) {
		ZEPHIR_CALL_FUNCTION(&intersect, "array_intersect", NULL, 0, fieldName, &changedFields);
		zephir_check_call_status();
		if (allFields) {
			_1$$5 = ZEPHIR_IS_EQUAL(&intersect, fieldName);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_MM_BOOL(_1$$5);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1018, PH_NOISY_CC | PH_READONLY);
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
	zend_bool allFields, _0$$3, _1$$5;
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
	ZEPHIR_CALL_METHOD(&updatedFields, this_ptr, "getUpdatedFields", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(fieldName) == IS_STRING) {
		_0$$3 = zephir_fast_in_array(fieldName, &updatedFields);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_BOOL(_0$$3);
	}
	if (Z_TYPE_P(fieldName) == IS_ARRAY) {
		ZEPHIR_CALL_FUNCTION(&intersect, "array_intersect", NULL, 0, fieldName, &updatedFields);
		zephir_check_call_status();
		if (allFields) {
			_1$$5 = ZEPHIR_IS_EQUAL(&intersect, fieldName);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_MM_BOOL(_1$$5);
		}
		RETURN_MM_BOOL(!(ZEPHIR_IS_EMPTY(&intersect)));
	}
	RETURN_MM_BOOL(!(ZEPHIR_IS_EMPTY(&updatedFields)));
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
	zend_bool _2;
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
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 1016, PH_NOISY_CC | PH_READONLY);
	_2 = zephir_array_key_exists(&_1, &_0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(_2);
}

/**
 * Serializes the object for json_encode
 *
 *```php
 * echo json_encode($invoice);
 *```
 *
 * @phpstan-return array<string, mixed>
 */
PHP_METHOD(Phalcon_Mvc_Model, jsonSerialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "toArray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
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
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval attribute_zv, _1;
	zend_string *attribute = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attribute_zv);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(attribute)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&attribute_zv);
	ZVAL_STR_COPY(&attribute_zv, attribute);
	_0 = zephir_isset_property_value_zval(this_ptr, &attribute_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_0)) {
		RETURN_MM_NULL();
	}
	zephir_memory_observe(&_1);
	zephir_read_property_zval(&_1, this_ptr, &attribute_zv, PH_NOISY_CC);
	RETURN_CCTOR(&_1);
}

/**
 * Refreshes the model attributes re-querying the record from the database
 */
PHP_METHOD(Phalcon_Mvc_Model, refresh)
{
	zend_bool _19;
	zval fields, _21, _17$$9, _20$$10;
	zval metaData, readConnection, schema, source, table, uniqueKey, tables, uniqueParams, dialect, row, attribute, manager, columnMap, _0, _4, _13, *_14, _15, *_16, _18, _22, _23, _26, _1$$3, _2$$3, _5$$6, _9$$6, _6$$7, _7$$7, _10$$8, _11$$8, _24$$11, _25$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_8 = NULL, *_12 = NULL;
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
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_20$$10);
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1017, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!ZEPHIR_IS_LONG(&_0, 0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_exceptions_recordcannotrefresh_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_get_class(&_2$$3, this_ptr, 0);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", &_3, 0, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model.zep", 3441);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getModelsMetaData", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&readConnection, this_ptr, "getReadConnection", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_1, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_4);
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getSchema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getSource", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_2, 1027, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueKey, &_4);
	if (!(zephir_is_true(&uniqueKey))) {
		ZEPHIR_CALL_METHOD(&_5$$6, this_ptr, "has", NULL, 0, &metaData, &readConnection);
		zephir_check_call_status();
		if (UNEXPECTED(!zephir_is_true(&_5$$6))) {
			ZEPHIR_INIT_VAR(&_6$$7);
			object_init_ex(&_6$$7, phalcon_mvc_model_exceptions_recordcannotrefresh_ce);
			ZEPHIR_INIT_VAR(&_7$$7);
			zephir_get_class(&_7$$7, this_ptr, 0);
			ZEPHIR_CALL_METHOD(NULL, &_6$$7, "__construct", &_8, 0, &_7$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$7, "phalcon/Mvc/Model.zep", 3464);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_9$$6, this_ptr, _zephir_prop_2, 1027, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&uniqueKey, &_9$$6);
	}
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_3, 1028, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueParams, &_4);
	if (UNEXPECTED(Z_TYPE_P(&uniqueParams) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_10$$8);
		object_init_ex(&_10$$8, phalcon_mvc_model_exceptions_recordcannotrefresh_ce);
		ZEPHIR_INIT_VAR(&_11$$8);
		zephir_get_class(&_11$$8, this_ptr, 0);
		ZEPHIR_CALL_METHOD(NULL, &_10$$8, "__construct", &_12, 0, &_11$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_10$$8, "phalcon/Mvc/Model.zep", 3473);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&fields);
	array_init(&fields);
	ZEPHIR_CALL_METHOD(&_13, &metaData, "getAttributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (Z_TYPE_P(&_13) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_15);
		zephir_string_to_char_array(&_15, &_13);
		_14 = &_15;
	} else {
		_14 = &_13;
	}
	zephir_is_iterable(_14, 0, "phalcon/Mvc/Model.zep", 3488);
	if (Z_TYPE_P(_14) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_14), _16)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _16);
			ZEPHIR_INIT_NVAR(&_17$$9);
			zephir_create_array(&_17$$9, 1, 0);
			zephir_array_fast_append(&_17$$9, &attribute);
			zephir_array_append(&fields, &_17$$9, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3482);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _14, "rewind", NULL, 0);
		zephir_check_call_status();
		_19 = 1;
		while (1) {
			if (_19) {
				_19 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _14, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_18, _14, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_18)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attribute, _14, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_20$$10);
				zephir_create_array(&_20$$10, 1, 0);
				zephir_array_fast_append(&_20$$10, &attribute);
				zephir_array_append(&fields, &_20$$10, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3482);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&attribute);
	ZEPHIR_CALL_METHOD(&dialect, &readConnection, "getDialect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_21);
	zephir_create_array(&_21, 3, 0);
	zephir_array_update_string(&_21, SL("columns"), &fields, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_22, &readConnection, "escapeIdentifier", NULL, 0, &table);
	zephir_check_call_status();
	zephir_array_update_string(&_21, SL("tables"), &_22, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_21, SL("where"), &uniqueKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&tables, &dialect, "select", NULL, 0, &_21);
	zephir_check_call_status();
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_4, 1029, PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_23, 2);
	ZEPHIR_CALL_METHOD(&row, &readConnection, "fetchOne", NULL, 0, &tables, &_23, &uniqueParams, &_4);
	zephir_check_call_status();
	if (Z_TYPE_P(&row) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getColumnMap", NULL, 0, this_ptr);
		zephir_check_call_status();
		ZVAL_NULL(&_24$$11);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "assign", NULL, 0, &row, &_24$$11, &columnMap);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_25$$11, &manager, "isKeepingSnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (zephir_is_true(&_25$$11)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setSnapshotData", NULL, 0, &row, &columnMap);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setOldSnapshotData", NULL, 0, &row, &columnMap);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_VAR(&_26);
	ZVAL_STRING(&_26, "afterFetch");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireEvent", NULL, 0, &_26);
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
	ZEPHIR_CALL_METHOD(NULL, &visited, "__construct", NULL, 40);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "doSave", NULL, 0, &visited);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Serializes the object ignoring connections, services, related objects or
 * static properties
 */
PHP_METHOD(Phalcon_Mvc_Model, serialize)
{
	zval _7;
	zend_bool _3, _4, _5;
	zval attributes, manager, dirtyState, snapshot, _0, _1, _2, _6$$3;
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
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7);
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
	ZEPHIR_CALL_METHOD(&attributes, this_ptr, "toArray", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1017, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dirtyState, &_0);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getModelsManager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_2);
	ZEPHIR_CALL_METHOD(&_2, &manager, "isKeepingSnapshots", NULL, 0, this_ptr);
	zephir_check_call_status();
	_3 = zephir_is_true(&_2);
	if (_3) {
		zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1018, PH_NOISY_CC | PH_READONLY);
		_3 = Z_TYPE_P(&_0) != IS_NULL;
	}
	_4 = _3;
	if (_4) {
		zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 1018, PH_NOISY_CC | PH_READONLY);
		_5 = !ZEPHIR_IS_EQUAL(&attributes, &_1);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_4 = _5;
	}
	if (_4) {
		zephir_read_property_cached(&_6$$3, this_ptr, _zephir_prop_1, 1018, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&snapshot, &_6$$3);
	}
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 3, 0);
	zephir_array_update_string(&_7, SL("attributes"), &attributes, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_7, SL("snapshot"), &snapshot, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_7, SL("dirtyState"), &dirtyState, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 21, &_7);
	zephir_check_call_status();
	RETURN_MM();
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setConnectionService", NULL, 0, this_ptr, &connectionService_zv);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1017, &_0);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setCustomEventsManager", NULL, 0, this_ptr, eventsManager);
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
 *
 * @phpstan-param array<string, mixed> $data
 * @phpstan-param mvc_hydration_column_map|null $columnMap
 */
PHP_METHOD(Phalcon_Mvc_Model, setOldSnapshotData)
{
	zend_bool _17$$3, _3$$4, _10$$8, _18$$11, _24$$15;
	zend_string *_2$$3;
	zend_ulong _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_9 = NULL, *_15 = NULL, *_23 = NULL, *_29 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *columnMap = NULL, columnMap_sub, __$null, key, value, attribute, *_0$$3, _16$$3, _4$$6, _6$$6, _7$$7, _8$$7, _11$$9, _12$$9, _13$$10, _14$$10, _19$$13, _20$$13, _21$$14, _22$$14, _25$$16, _26$$16, _27$$17, _28$$17;
	zval data, snapshot;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_26$$16);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_28$$17);
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
		zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 3663);
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
				_3$$4 = zephir_array_isset_fetch(&attribute, columnMap, &key, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_3$$4)) {
					ZEPHIR_INIT_NVAR(&_6$$6);
					ZVAL_STRING(&_6$$6, "orm.ignore_unknown_columns");
					ZEPHIR_CALL_CE_STATIC(&_4$$6, phalcon_support_settings_ce, "get", &_5, 0, &_6$$6);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&_4$$6))) {
						ZEPHIR_INIT_NVAR(&_7$$7);
						object_init_ex(&_7$$7, phalcon_mvc_model_exceptions_columnnotinmap_ce);
						ZEPHIR_INIT_NVAR(&_8$$7);
						zephir_get_class(&_8$$7, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_7$$7, "__construct", &_9, 0, &key, &_8$$7);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_7$$7, "phalcon/Mvc/Model.zep", 3645);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
				if (Z_TYPE_P(&attribute) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attribute);
					_10$$8 = zephir_array_isset_long_fetch(&attribute, &attribute, 0, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_10$$8)) {
						ZEPHIR_INIT_NVAR(&_12$$9);
						ZVAL_STRING(&_12$$9, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_11$$9, phalcon_support_settings_ce, "get", &_5, 0, &_12$$9);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_11$$9))) {
							ZEPHIR_INIT_NVAR(&_13$$10);
							object_init_ex(&_13$$10, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							ZEPHIR_INIT_NVAR(&_14$$10);
							zephir_get_class(&_14$$10, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_13$$10, "__construct", &_15, 0, &key, &_14$$10);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_13$$10, "phalcon/Mvc/Model.zep", 3654);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
				}
				zephir_array_update_zval(&snapshot, &attribute, &value, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
			zephir_check_call_status();
			_17$$3 = 1;
			while (1) {
				if (_17$$3) {
					_17$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_16$$3, &data, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_16$$3)) {
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
					_18$$11 = zephir_array_isset_fetch(&attribute, columnMap, &key, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_18$$11)) {
						ZEPHIR_INIT_NVAR(&_20$$13);
						ZVAL_STRING(&_20$$13, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_19$$13, phalcon_support_settings_ce, "get", &_5, 0, &_20$$13);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_19$$13))) {
							ZEPHIR_INIT_NVAR(&_21$$14);
							object_init_ex(&_21$$14, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							ZEPHIR_INIT_NVAR(&_22$$14);
							zephir_get_class(&_22$$14, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_21$$14, "__construct", &_23, 0, &key, &_22$$14);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_21$$14, "phalcon/Mvc/Model.zep", 3645);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
					if (Z_TYPE_P(&attribute) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attribute);
						_24$$15 = zephir_array_isset_long_fetch(&attribute, &attribute, 0, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (!(_24$$15)) {
							ZEPHIR_INIT_NVAR(&_26$$16);
							ZVAL_STRING(&_26$$16, "orm.ignore_unknown_columns");
							ZEPHIR_CALL_CE_STATIC(&_25$$16, phalcon_support_settings_ce, "get", &_5, 0, &_26$$16);
							zephir_check_call_status();
							if (UNEXPECTED(!zephir_is_true(&_25$$16))) {
								ZEPHIR_INIT_NVAR(&_27$$17);
								object_init_ex(&_27$$17, phalcon_mvc_model_exceptions_columnnotinmap_ce);
								ZEPHIR_INIT_NVAR(&_28$$17);
								zephir_get_class(&_28$$17, this_ptr, 0);
								ZEPHIR_CALL_METHOD(NULL, &_27$$17, "__construct", &_29, 0, &key, &_28$$17);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_27$$17, "phalcon/Mvc/Model.zep", 3654);
								ZEPHIR_MM_RESTORE();
								return;
							}
							continue;
						}
					}
					zephir_array_update_zval(&snapshot, &attribute, &value, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
			zephir_throw_variable_type_error(&data, "snapshot", "array");
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&snapshot, &data);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1024, &snapshot);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setReadConnectionService", NULL, 0, this_ptr, &connectionService_zv);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Stores related records in the relation cache, so that a subsequent
 * getRelated() or property access returns them without querying.
 *
 * This is the write side of the cache getRelated() already reads. The value
 * lands in `related`, never in `dirtyRelated`.
 *
 * That is not the same as leaving save() untouched. collectRelatedToSave()
 * promotes a `related` entry into `dirtyRelated` when the entry is a single
 * ModelInterface that is new or has changed, so passing such a record here
 * does cascade on the next save(). Arrays, resultsets, and unchanged
 * records carrying snapshot data are skipped - which is why eager loading,
 * the caller this exists for, never triggers a cascade.
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Sets the record's snapshot data.
 * This method is used internally to set snapshot data when the model was
 * set up to keep snapshot data
 *
 * @param array columnMap
 *
 * @phpstan-param mvc_model_data $data
 */
PHP_METHOD(Phalcon_Mvc_Model, setSnapshotData)
{
	zend_bool _24$$3, _3$$4, _4$$4, _5$$4, _11$$4, _17$$9, _25$$12, _26$$12, _27$$12, _31$$12, _37$$17;
	zend_string *_2$$3;
	zend_ulong _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_10 = NULL, *_16 = NULL, *_22 = NULL, *_36 = NULL, *_42 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *columnMap = NULL, columnMap_sub, __$null, key, value, attribute, *_0$$3, _23$$3, _6$$4, _8$$4, _9$$6, _12$$7, _13$$7, _14$$8, _15$$8, _18$$10, _19$$10, _20$$11, _21$$11, _28$$12, _29$$12, _30$$14, _32$$15, _33$$15, _34$$16, _35$$16, _38$$18, _39$$18, _40$$19, _41$$19;
	zval data, snapshot;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_23$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_29$$12);
	ZVAL_UNDEF(&_30$$14);
	ZVAL_UNDEF(&_32$$15);
	ZVAL_UNDEF(&_33$$15);
	ZVAL_UNDEF(&_34$$16);
	ZVAL_UNDEF(&_35$$16);
	ZVAL_UNDEF(&_38$$18);
	ZVAL_UNDEF(&_39$$18);
	ZVAL_UNDEF(&_40$$19);
	ZVAL_UNDEF(&_41$$19);
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
		zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 3762);
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
					_4$$4 = zephir_array_isset_value(columnMap, &key);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_3$$4 = !(_4$$4);
				}
				_5$$4 = _3$$4;
				if (_5$$4) {
					ZEPHIR_INIT_NVAR(&_8$$4);
					ZVAL_STRING(&_8$$4, "orm.case_insensitive_column_map");
					ZEPHIR_CALL_CE_STATIC(&_6$$4, phalcon_support_settings_ce, "get", &_7, 0, &_8$$4);
					zephir_check_call_status();
					_5$$4 = zephir_is_true(&_6$$4);
				}
				if (_5$$4) {
					ZEPHIR_CALL_CE_STATIC(&_9$$6, phalcon_mvc_model_hydration_caseinsensitivecolumnmap_ce, "caseInsensitiveColumnMap", &_10, 0, columnMap, &key);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&key, &_9$$6);
				}
				ZEPHIR_OBS_NVAR(&attribute);
				_11$$4 = zephir_array_isset_fetch(&attribute, columnMap, &key, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_11$$4)) {
					ZEPHIR_INIT_NVAR(&_13$$7);
					ZVAL_STRING(&_13$$7, "orm.ignore_unknown_columns");
					ZEPHIR_CALL_CE_STATIC(&_12$$7, phalcon_support_settings_ce, "get", &_7, 0, &_13$$7);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&_12$$7))) {
						ZEPHIR_INIT_NVAR(&_14$$8);
						object_init_ex(&_14$$8, phalcon_mvc_model_exceptions_columnnotinmap_ce);
						ZEPHIR_INIT_NVAR(&_15$$8);
						zephir_get_class(&_15$$8, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_14$$8, "__construct", &_16, 0, &key, &_15$$8);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_14$$8, "phalcon/Mvc/Model.zep", 3744);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
				if (Z_TYPE_P(&attribute) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attribute);
					_17$$9 = zephir_array_isset_long_fetch(&attribute, &attribute, 0, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_17$$9)) {
						ZEPHIR_INIT_NVAR(&_19$$10);
						ZVAL_STRING(&_19$$10, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_18$$10, phalcon_support_settings_ce, "get", &_7, 0, &_19$$10);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_18$$10))) {
							ZEPHIR_INIT_NVAR(&_20$$11);
							object_init_ex(&_20$$11, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							ZEPHIR_INIT_NVAR(&_21$$11);
							zephir_get_class(&_21$$11, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_20$$11, "__construct", &_22, 0, &key, &_21$$11);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_20$$11, "phalcon/Mvc/Model.zep", 3753);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
				}
				zephir_array_update_zval(&snapshot, &attribute, &value, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
			zephir_check_call_status();
			_24$$3 = 1;
			while (1) {
				if (_24$$3) {
					_24$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_23$$3, &data, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_23$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&key) != IS_STRING) {
						continue;
					}
					_25$$12 = Z_TYPE_P(columnMap) == IS_ARRAY;
					if (_25$$12) {
						_26$$12 = zephir_array_isset_value(columnMap, &key);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_25$$12 = !(_26$$12);
					}
					_27$$12 = _25$$12;
					if (_27$$12) {
						ZEPHIR_INIT_NVAR(&_29$$12);
						ZVAL_STRING(&_29$$12, "orm.case_insensitive_column_map");
						ZEPHIR_CALL_CE_STATIC(&_28$$12, phalcon_support_settings_ce, "get", &_7, 0, &_29$$12);
						zephir_check_call_status();
						_27$$12 = zephir_is_true(&_28$$12);
					}
					if (_27$$12) {
						ZEPHIR_CALL_CE_STATIC(&_30$$14, phalcon_mvc_model_hydration_caseinsensitivecolumnmap_ce, "caseInsensitiveColumnMap", &_10, 0, columnMap, &key);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&key, &_30$$14);
					}
					ZEPHIR_OBS_NVAR(&attribute);
					_31$$12 = zephir_array_isset_fetch(&attribute, columnMap, &key, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_31$$12)) {
						ZEPHIR_INIT_NVAR(&_33$$15);
						ZVAL_STRING(&_33$$15, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_32$$15, phalcon_support_settings_ce, "get", &_7, 0, &_33$$15);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_32$$15))) {
							ZEPHIR_INIT_NVAR(&_34$$16);
							object_init_ex(&_34$$16, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							ZEPHIR_INIT_NVAR(&_35$$16);
							zephir_get_class(&_35$$16, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_34$$16, "__construct", &_36, 0, &key, &_35$$16);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_34$$16, "phalcon/Mvc/Model.zep", 3744);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
					if (Z_TYPE_P(&attribute) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attribute);
						_37$$17 = zephir_array_isset_long_fetch(&attribute, &attribute, 0, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (!(_37$$17)) {
							ZEPHIR_INIT_NVAR(&_39$$18);
							ZVAL_STRING(&_39$$18, "orm.ignore_unknown_columns");
							ZEPHIR_CALL_CE_STATIC(&_38$$18, phalcon_support_settings_ce, "get", &_7, 0, &_39$$18);
							zephir_check_call_status();
							if (UNEXPECTED(!zephir_is_true(&_38$$18))) {
								ZEPHIR_INIT_NVAR(&_40$$19);
								object_init_ex(&_40$$19, phalcon_mvc_model_exceptions_columnnotinmap_ce);
								ZEPHIR_INIT_NVAR(&_41$$19);
								zephir_get_class(&_41$$19, this_ptr, 0);
								ZEPHIR_CALL_METHOD(NULL, &_40$$19, "__construct", &_42, 0, &key, &_41$$19);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_40$$19, "phalcon/Mvc/Model.zep", 3753);
								ZEPHIR_MM_RESTORE();
								return;
							}
							continue;
						}
					}
					zephir_array_update_zval(&snapshot, &attribute, &value, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
			zephir_throw_variable_type_error(&data, "snapshot", "array");
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&snapshot, &data);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1018, &snapshot);
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
 * @param array|string|null $elements
 *
 * @phpstan-param array<array-key, mixed> $elements
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
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
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
		zephir_is_iterable(_3$$4, 0, "phalcon/Mvc/Model.zep", 3811);
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
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
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
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1026, transaction);
	RETURN_THISW();
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setWriteConnectionService", NULL, 0, this_ptr, &connectionService_zv);
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1022, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1022, &__$false);
	}
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
 *
 * @phpstan-return array<string, mixed>
 */
PHP_METHOD(Phalcon_Mvc_Model, toArray)
{
	zend_bool _28, _4$$4, _5$$4, _11$$4, _17$$9, _19$$3, _21$$3, _22$$3, _29$$18, _30$$18, _34$$18, _40$$23, _42$$17, _44$$17, _45$$17;
	zval data;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_10 = NULL, *_16 = NULL, *_39 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *columns = NULL, columns_sub, *useGetter = NULL, useGetter_sub, __$null, __$true, attribute, attributeField, columnMap, metaData, method, _0, *_1, _2, *_3, _27, _6$$4, _8$$4, _9$$5, _12$$6, _13$$6, _14$$7, _15$$7, _18$$3, _20$$3, _23$$12, _24$$11, _25$$11, _26$$15, _31$$18, _32$$18, _33$$19, _35$$20, _36$$20, _37$$21, _38$$21, _41$$17, _43$$17, _46$$26, _47$$25, _48$$25, _49$$29;
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
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_20$$3);
	ZVAL_UNDEF(&_23$$12);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_26$$15);
	ZVAL_UNDEF(&_31$$18);
	ZVAL_UNDEF(&_32$$18);
	ZVAL_UNDEF(&_33$$19);
	ZVAL_UNDEF(&_35$$20);
	ZVAL_UNDEF(&_36$$20);
	ZVAL_UNDEF(&_37$$21);
	ZVAL_UNDEF(&_38$$21);
	ZVAL_UNDEF(&_41$$17);
	ZVAL_UNDEF(&_43$$17);
	ZVAL_UNDEF(&_46$$26);
	ZVAL_UNDEF(&_47$$25);
	ZVAL_UNDEF(&_48$$25);
	ZVAL_UNDEF(&_49$$29);
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
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getModelsMetaData", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getColumnMap", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &metaData, "getAttributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &_0);
		_1 = &_2;
	} else {
		_1 = &_0;
	}
	zephir_is_iterable(_1, 0, "phalcon/Mvc/Model.zep", 3963);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _3);
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				_4$$4 = zephir_array_isset_value(&columnMap, &attribute);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_5$$4 = !(_4$$4);
				if (_5$$4) {
					ZEPHIR_INIT_NVAR(&_8$$4);
					ZVAL_STRING(&_8$$4, "orm.case_insensitive_column_map");
					ZEPHIR_CALL_CE_STATIC(&_6$$4, phalcon_support_settings_ce, "get", &_7, 0, &_8$$4);
					zephir_check_call_status();
					_5$$4 = zephir_is_true(&_6$$4);
				}
				if (_5$$4) {
					ZEPHIR_CALL_CE_STATIC(&_9$$5, phalcon_mvc_model_hydration_caseinsensitivecolumnmap_ce, "caseInsensitiveColumnMap", &_10, 0, &columnMap, &attribute);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&attribute, &_9$$5);
				}
				ZEPHIR_OBS_NVAR(&attributeField);
				_11$$4 = zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_11$$4)) {
					ZEPHIR_INIT_NVAR(&_13$$6);
					ZVAL_STRING(&_13$$6, "orm.ignore_unknown_columns");
					ZEPHIR_CALL_CE_STATIC(&_12$$6, phalcon_support_settings_ce, "get", &_7, 0, &_13$$6);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&_12$$6))) {
						ZEPHIR_INIT_NVAR(&_14$$7);
						object_init_ex(&_14$$7, phalcon_mvc_model_exceptions_columnnotinmap_ce);
						ZEPHIR_INIT_NVAR(&_15$$7);
						zephir_get_class(&_15$$7, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_14$$7, "__construct", &_16, 0, &attribute, &_15$$7);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_14$$7, "phalcon/Mvc/Model.zep", 3921);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &attribute);
			}
			if (Z_TYPE_P(columns) == IS_ARRAY) {
				_17$$9 = zephir_fast_in_array(&attributeField, columns);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_17$$9)) {
					continue;
				}
			}
			ZEPHIR_INIT_NVAR(&_18$$3);
			zephir_camelize(&_18$$3, &attributeField, NULL );
			ZEPHIR_INIT_NVAR(&method);
			ZEPHIR_CONCAT_SV(&method, "get", &_18$$3);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_19$$3 = ZEPHIR_IS_TRUE_IDENTICAL(useGetter);
			if (_19$$3) {
				ZEPHIR_INIT_NVAR(&_20$$3);
				ZVAL_STRING(&_20$$3, "getSource");
				_19$$3 = !ZEPHIR_IS_IDENTICAL(&_20$$3, &method);
			}
			_21$$3 = _19$$3;
			if (_21$$3) {
				_21$$3 = (zephir_method_exists(this_ptr, &method)  == SUCCESS);
			}
			if (_21$$3) {

				/* try_start_1: */

					ZEPHIR_CALL_METHOD_ZVAL(&_23$$12, this_ptr, &method, NULL, 0);
					zephir_check_call_status_or_jump(try_end_1);
					zephir_array_update_zval(&data, &attributeField, &_23$$12, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						goto try_end_1;
					}

				try_end_1:

				if (EG(exception)) {
					ZEPHIR_INIT_NVAR(&_24$$11);
					ZVAL_OBJ(&_24$$11, EG(exception));
					Z_ADDREF_P(&_24$$11);
					ZEPHIR_INIT_NVAR(&_25$$11);
					if (zephir_is_instance_of(&_24$$11, SL("Error"))) {
						zend_clear_exception();
						ZEPHIR_CPY_WRT(&_25$$11, &_24$$11);
						zephir_array_update_zval(&data, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} else {
				_22$$3 = zephir_isset_property_value_zval(this_ptr, &attributeField);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_22$$3) {
					ZEPHIR_OBS_NVAR(&_26$$15);
					zephir_read_property_zval(&_26$$15, this_ptr, &attributeField, PH_NOISY_CC);
					zephir_array_update_zval(&data, &attributeField, &_26$$15, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					zephir_array_update_zval(&data, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_28 = 1;
		while (1) {
			if (_28) {
				_28 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_27, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_27)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attribute, _1, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					_29$$18 = zephir_array_isset_value(&columnMap, &attribute);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_30$$18 = !(_29$$18);
					if (_30$$18) {
						ZEPHIR_INIT_NVAR(&_32$$18);
						ZVAL_STRING(&_32$$18, "orm.case_insensitive_column_map");
						ZEPHIR_CALL_CE_STATIC(&_31$$18, phalcon_support_settings_ce, "get", &_7, 0, &_32$$18);
						zephir_check_call_status();
						_30$$18 = zephir_is_true(&_31$$18);
					}
					if (_30$$18) {
						ZEPHIR_CALL_CE_STATIC(&_33$$19, phalcon_mvc_model_hydration_caseinsensitivecolumnmap_ce, "caseInsensitiveColumnMap", &_10, 0, &columnMap, &attribute);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&attribute, &_33$$19);
					}
					ZEPHIR_OBS_NVAR(&attributeField);
					_34$$18 = zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_34$$18)) {
						ZEPHIR_INIT_NVAR(&_36$$20);
						ZVAL_STRING(&_36$$20, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_35$$20, phalcon_support_settings_ce, "get", &_7, 0, &_36$$20);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_35$$20))) {
							ZEPHIR_INIT_NVAR(&_37$$21);
							object_init_ex(&_37$$21, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							ZEPHIR_INIT_NVAR(&_38$$21);
							zephir_get_class(&_38$$21, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_37$$21, "__construct", &_39, 0, &attribute, &_38$$21);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_37$$21, "phalcon/Mvc/Model.zep", 3921);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &attribute);
				}
				if (Z_TYPE_P(columns) == IS_ARRAY) {
					_40$$23 = zephir_fast_in_array(&attributeField, columns);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_40$$23)) {
						continue;
					}
				}
				ZEPHIR_INIT_NVAR(&_41$$17);
				zephir_camelize(&_41$$17, &attributeField, NULL );
				ZEPHIR_INIT_NVAR(&method);
				ZEPHIR_CONCAT_SV(&method, "get", &_41$$17);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_42$$17 = ZEPHIR_IS_TRUE_IDENTICAL(useGetter);
				if (_42$$17) {
					ZEPHIR_INIT_NVAR(&_43$$17);
					ZVAL_STRING(&_43$$17, "getSource");
					_42$$17 = !ZEPHIR_IS_IDENTICAL(&_43$$17, &method);
				}
				_44$$17 = _42$$17;
				if (_44$$17) {
					_44$$17 = (zephir_method_exists(this_ptr, &method)  == SUCCESS);
				}
				if (_44$$17) {

					/* try_start_2: */

						ZEPHIR_CALL_METHOD_ZVAL(&_46$$26, this_ptr, &method, NULL, 0);
						zephir_check_call_status_or_jump(try_end_2);
						zephir_array_update_zval(&data, &attributeField, &_46$$26, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							goto try_end_2;
						}

					try_end_2:

					if (EG(exception)) {
						ZEPHIR_INIT_NVAR(&_47$$25);
						ZVAL_OBJ(&_47$$25, EG(exception));
						Z_ADDREF_P(&_47$$25);
						ZEPHIR_INIT_NVAR(&_48$$25);
						if (zephir_is_instance_of(&_47$$25, SL("Error"))) {
							zend_clear_exception();
							ZEPHIR_CPY_WRT(&_48$$25, &_47$$25);
							zephir_array_update_zval(&data, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} else {
					_45$$17 = zephir_isset_property_value_zval(this_ptr, &attributeField);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_45$$17) {
						ZEPHIR_OBS_NVAR(&_49$$29);
						zephir_read_property_zval(&_49$$29, this_ptr, &attributeField, PH_NOISY_CC);
						zephir_array_update_zval(&data, &attributeField, &_49$$29, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						zephir_array_update_zval(&data, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&attribute);
	RETURN_CTOR(&data);
}

/**
 * Unserializes the object from a serialized string
 */
PHP_METHOD(Phalcon_Mvc_Model, unserialize)
{
	zend_ulong _12$$8;
	zend_bool _0$$3, _8$$3, _20$$3, _17$$8, _21$$19;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data_zv, attributes, container, manager, key, value, snapshot, properties, dirtyState, _4$$3, _5$$3, _1$$4, _2$$5, _3$$5, _6$$6, _7$$6, *_9$$8, _10$$8, *_11$$8, _16$$8, _14$$9, _15$$9, _18$$13, _19$$13, _22$$20;
	zend_string *data = NULL, *_13$$8;
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
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_22$$20);
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
	ZEPHIR_CALL_FUNCTION(&attributes, "unserialize", NULL, 26, &data_zv);
	zephir_check_call_status();
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		_0$$3 = zephir_array_isset_value_string(&attributes, SL("attributes"));
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (!(_0$$3)) {
			ZEPHIR_INIT_VAR(&_1$$4);
			zephir_create_array(&_1$$4, 1, 0);
			zephir_array_update_string(&_1$$4, SL("attributes"), &attributes, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&attributes, &_1$$4);
		}
		ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_di_ce, "getDefault", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&container) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_2$$5);
			object_init_ex(&_2$$5, phalcon_mvc_model_exceptions_modelormservicesunavailable_ce);
			ZEPHIR_INIT_VAR(&_3$$5);
			zephir_get_class(&_3$$5, this_ptr, 0);
			ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 0, &_3$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$5, "phalcon/Mvc/Model.zep", 3987);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1013, &container);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "modelsManager");
		ZEPHIR_CALL_METHOD(&_4$$3, &container, "getShared", NULL, 0, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&manager, &_4$$3);
		if (UNEXPECTED(Z_TYPE_P(&manager) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_6$$6);
			object_init_ex(&_6$$6, phalcon_mvc_model_exceptions_invalidmodelsmanagerservice_ce);
			ZEPHIR_INIT_VAR(&_7$$6);
			zephir_get_class(&_7$$6, this_ptr, 0);
			ZEPHIR_CALL_METHOD(NULL, &_6$$6, "__construct", NULL, 0, &_7$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$6, "phalcon/Mvc/Model.zep", 4001);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1014, &manager);
		ZEPHIR_CALL_METHOD(NULL, &manager, "initialize", NULL, 0, this_ptr);
		zephir_check_call_status();
		if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("onconstruct")) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "onConstruct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_memory_observe(&properties);
		_8$$3 = zephir_array_isset_string_fetch(&properties, &attributes, SL("attributes"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_8$$3) {
			if (Z_TYPE_P(&properties) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_10$$8);
				zephir_string_to_char_array(&_10$$8, &properties);
				_9$$8 = &_10$$8;
			} else {
				_9$$8 = &properties;
			}
			zephir_is_iterable(_9$$8, 0, "phalcon/Mvc/Model.zep", 4040);
			if (Z_TYPE_P(_9$$8) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_9$$8), _12$$8, _13$$8, _11$$8)
				{
					ZEPHIR_INIT_NVAR(&key);
					if (_13$$8 != NULL) { 
						ZVAL_STR_COPY(&key, _13$$8);
					} else {
						ZVAL_LONG(&key, _12$$8);
					}
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_COPY(&value, _11$$8);

					/* try_start_1: */

						zephir_update_property_zval_zval(this_ptr, &key, &value);

					try_end_1:

					if (EG(exception)) {
						ZEPHIR_INIT_NVAR(&_14$$9);
						ZVAL_OBJ(&_14$$9, EG(exception));
						Z_ADDREF_P(&_14$$9);
						ZEPHIR_INIT_NVAR(&_15$$9);
						if (zephir_is_instance_of(&_14$$9, SL("TypeError"))) {
							zend_clear_exception();
							ZEPHIR_CPY_WRT(&_15$$9, &_14$$9);
						} else {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _9$$8, "rewind", NULL, 0);
				zephir_check_call_status();
				_17$$8 = 1;
				while (1) {
					if (_17$$8) {
						_17$$8 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _9$$8, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_16$$8, _9$$8, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_16$$8)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&key, _9$$8, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&value, _9$$8, "current", NULL, 0);
					zephir_check_call_status();

						/* try_start_2: */

							zephir_update_property_zval_zval(this_ptr, &key, &value);

						try_end_2:

						if (EG(exception)) {
							ZEPHIR_INIT_NVAR(&_18$$13);
							ZVAL_OBJ(&_18$$13, EG(exception));
							Z_ADDREF_P(&_18$$13);
							ZEPHIR_INIT_NVAR(&_19$$13);
							if (zephir_is_instance_of(&_18$$13, SL("TypeError"))) {
								zend_clear_exception();
								ZEPHIR_CPY_WRT(&_19$$13, &_18$$13);
							} else {
								ZEPHIR_MM_RESTORE();
								return;
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
		_20$$3 = zephir_array_isset_string_fetch(&dirtyState, &attributes, SL("dirtyState"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_20$$3) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1017, &dirtyState);
		}
		ZEPHIR_CALL_METHOD(&_4$$3, &manager, "isKeepingSnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (zephir_is_true(&_4$$3)) {
			zephir_memory_observe(&snapshot);
			_21$$19 = zephir_array_isset_string_fetch(&snapshot, &attributes, SL("snapshot"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_21$$19) {
				ZEPHIR_INIT_VAR(&_22$$20);
				if (Z_TYPE_P(&snapshot) != IS_NULL) {
					ZEPHIR_CPY_WRT(&_22$$20, &snapshot);
				} else {
					ZEPHIR_CPY_WRT(&_22$$20, &properties);
				}
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1018, &_22$$20);
			} else {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1018, &properties);
			}
		}
	}
	ZEPHIR_MM_RESTORE();
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1017, PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getModelsMetaData", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "getWriteConnection", NULL, 0);
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
			ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 3, &_6$$4, &_7$$4, &_8$$4, &_9$$4, &_5$$4);
			zephir_check_call_status();
			zephir_array_fast_append(&_3$$4, &_4$$4);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1020, &_3$$4);
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "save", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1020, PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(!(ZEPHIR_IS_EMPTY(&_0)));
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
 *
 * @phpstan-param mvc_model_attributes $attributes
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
	zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model.zep", 4200);
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _0)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _0);
			zephir_array_update_zval(&keysAttributes, &attribute, &__$true, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
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
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&attribute);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getModelsMetaData", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_3, "setEmptyStringAttributes", NULL, 0, this_ptr, &keysAttributes);
	zephir_check_call_status();
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
 *
 * @phpstan-param mvc_relation_options $options
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addBelongsTo", NULL, 0, this_ptr, fields, &referenceModel_zv, referencedFields, &options);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Cancel the current operation
 */
PHP_METHOD(Phalcon_Mvc_Model, cancelOperation)
{
	zval _0, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("operationMade", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1021, PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG(&_0, 3)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "notDeleted");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireEvent", &_2, 0, &_1$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "notSaved");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireEvent", &_2, 0, &_3$$4);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Reads "belongs to" relations and check the virtual foreign keys when
 * inserting or updating records to verify that inserted/updated values are
 * present in the related entity
 */
PHP_METHOD(Phalcon_Mvc_Model, checkForeignKeysRestrict)
{
	zend_string *_12$$7, *_45$$28;
	zend_ulong _11$$7, _44$$28;
	zend_bool error = 0, validateWithNulls = 0, _36, _4$$3, _20$$3, _22$$3, _16$$7, _21$$15, _26$$18, _37$$24, _53$$24, _55$$24, _49$$28, _54$$36, _59$$39;
	zval conditions, _24$$3, _29$$18, _57$$24, _62$$39;
	zval manager, belongsTo, foreignKey, relation, position, bindParams, extraConditions, message, messageField, fields, referencedFields, field, referencedModel, value, allowNulls, _0, *_1, _2, *_3, _35, _6$$3, _23$$3, _25$$3, _5$$5, *_8$$7, _9$$7, *_10$$7, _15$$7, _13$$8, _14$$8, _17$$10, _18$$10, _19$$12, _28$$18, _30$$18, _31$$18, _32$$18, _27$$20, _39$$24, _56$$24, _58$$24, _38$$26, *_41$$28, _42$$28, *_43$$28, _48$$28, _46$$29, _47$$29, _50$$31, _51$$31, _52$$33, _61$$39, _63$$39, _64$$39, _65$$39, _60$$41, _67$$45, _68$$45, _69$$46;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_33 = NULL, *_34 = NULL, *_40 = NULL, *_66 = NULL;
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
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_23$$3);
	ZVAL_UNDEF(&_25$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_28$$18);
	ZVAL_UNDEF(&_30$$18);
	ZVAL_UNDEF(&_31$$18);
	ZVAL_UNDEF(&_32$$18);
	ZVAL_UNDEF(&_27$$20);
	ZVAL_UNDEF(&_39$$24);
	ZVAL_UNDEF(&_56$$24);
	ZVAL_UNDEF(&_58$$24);
	ZVAL_UNDEF(&_38$$26);
	ZVAL_UNDEF(&_42$$28);
	ZVAL_UNDEF(&_48$$28);
	ZVAL_UNDEF(&_46$$29);
	ZVAL_UNDEF(&_47$$29);
	ZVAL_UNDEF(&_50$$31);
	ZVAL_UNDEF(&_51$$31);
	ZVAL_UNDEF(&_52$$33);
	ZVAL_UNDEF(&_61$$39);
	ZVAL_UNDEF(&_63$$39);
	ZVAL_UNDEF(&_64$$39);
	ZVAL_UNDEF(&_65$$39);
	ZVAL_UNDEF(&_60$$41);
	ZVAL_UNDEF(&_67$$45);
	ZVAL_UNDEF(&_68$$45);
	ZVAL_UNDEF(&_69$$46);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&_24$$3);
	ZVAL_UNDEF(&_29$$18);
	ZVAL_UNDEF(&_57$$24);
	ZVAL_UNDEF(&_62$$39);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&belongsTo, &manager, "getBelongsTo", NULL, 0, this_ptr);
	zephir_check_call_status();
	error = 0;
	if (Z_TYPE_P(&belongsTo) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &belongsTo);
		_1 = &_2;
	} else {
		_1 = &belongsTo;
	}
	zephir_is_iterable(_1, 0, "phalcon/Mvc/Model.zep", 4442);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&relation);
			ZVAL_COPY(&relation, _3);
			validateWithNulls = 0;
			ZEPHIR_CALL_METHOD(&foreignKey, &relation, "getForeignKey", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
				continue;
			}
			action = 1;
			_4$$3 = zephir_array_isset_value_string(&foreignKey, SL("action"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_4$$3) {
				ZEPHIR_OBS_NVAR(&_5$$5);
				zephir_array_fetch_string(&_5$$5, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 4319);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				action = zephir_get_intval(&_5$$5);
			}
			if (action != 1) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&_6$$3, &relation, "getReferencedModel", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&referencedModel, &manager, "load", &_7, 0, &_6$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&conditions);
			array_init(&conditions);
			ZEPHIR_INIT_NVAR(&bindParams);
			array_init(&bindParams);
			numberNull = 0;
			ZEPHIR_CALL_METHOD(&fields, &relation, "getFields", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getReferencedFields", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&fields) == IS_ARRAY) {
				if (Z_TYPE_P(&fields) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_9$$7);
					zephir_string_to_char_array(&_9$$7, &fields);
					_8$$7 = &_9$$7;
				} else {
					_8$$7 = &fields;
				}
				zephir_is_iterable(_8$$7, 0, "phalcon/Mvc/Model.zep", 4362);
				if (Z_TYPE_P(_8$$7) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_8$$7), _11$$7, _12$$7, _10$$7)
					{
						ZEPHIR_INIT_NVAR(&position);
						if (_12$$7 != NULL) { 
							ZVAL_STR_COPY(&position, _12$$7);
						} else {
							ZVAL_LONG(&position, _11$$7);
						}
						ZEPHIR_INIT_NVAR(&field);
						ZVAL_COPY(&field, _10$$7);
						ZEPHIR_OBS_NVAR(&value);
						zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
						ZEPHIR_OBS_NVAR(&_13$$8);
						zephir_array_fetch(&_13$$8, &referencedFields, &position, PH_NOISY, "phalcon/Mvc/Model.zep", 4354);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&_14$$8);
						ZEPHIR_CONCAT_SVSV(&_14$$8, "[", &_13$$8, "] = ?", &position);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&conditions, &_14$$8, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4354);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4355);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (Z_TYPE_P(&value) == IS_NULL) {
							numberNull++;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _8$$7, "rewind", NULL, 0);
					zephir_check_call_status();
					_16$$7 = 1;
					while (1) {
						if (_16$$7) {
							_16$$7 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _8$$7, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_15$$7, _8$$7, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_15$$7)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&position, _8$$7, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&field, _8$$7, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_OBS_NVAR(&value);
							zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
							ZEPHIR_OBS_NVAR(&_17$$10);
							zephir_array_fetch(&_17$$10, &referencedFields, &position, PH_NOISY, "phalcon/Mvc/Model.zep", 4354);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&_18$$10);
							ZEPHIR_CONCAT_SVSV(&_18$$10, "[", &_17$$10, "] = ?", &position);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&conditions, &_18$$10, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4354);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4355);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
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
				ZEPHIR_INIT_NVAR(&_19$$12);
				ZEPHIR_CONCAT_SVS(&_19$$12, "[", &referencedFields, "] = ?0");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&conditions, &_19$$12, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4366);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4367);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&value) == IS_NULL) {
					validateWithNulls = 1;
				}
			}
			ZEPHIR_OBS_NVAR(&extraConditions);
			_20$$3 = zephir_array_isset_string_fetch(&extraConditions, &foreignKey, SL("conditions"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_20$$3) {
				zephir_array_append(&conditions, &extraConditions, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4378);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			if (validateWithNulls) {
				ZEPHIR_OBS_NVAR(&allowNulls);
				_21$$15 = zephir_array_isset_string_fetch(&allowNulls, &foreignKey, SL("allowNulls"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_21$$15) {
					validateWithNulls = zephir_get_boolval(&allowNulls);
				} else {
					validateWithNulls = 0;
				}
			}
			_22$$3 = !validateWithNulls;
			if (_22$$3) {
				ZEPHIR_INIT_NVAR(&_24$$3);
				zephir_create_array(&_24$$3, 2, 0);
				ZEPHIR_INIT_NVAR(&_25$$3);
				zephir_fast_join_str(&_25$$3, SL(" AND "), &conditions);
				zephir_array_fast_append(&_24$$3, &_25$$3);
				zephir_array_update_string(&_24$$3, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_23$$3, &referencedModel, "count", NULL, 0, &_24$$3);
				zephir_check_call_status();
				_22$$3 = !zephir_is_true(&_23$$3);
			}
			if (_22$$3) {
				ZEPHIR_OBS_NVAR(&message);
				_26$$18 = zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_26$$18)) {
					ZEPHIR_INIT_NVAR(&message);
					if (Z_TYPE_P(&fields) == IS_ARRAY) {
						ZEPHIR_INIT_NVAR(&_27$$20);
						zephir_fast_join_str(&_27$$20, SL(", "), &fields);
						ZEPHIR_CONCAT_SVS(&message, "Value of fields \"", &_27$$20, "\" does not exist on referenced table");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_CONCAT_SVS(&message, "Value of field \"", &fields, "\" does not exist on referenced table");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
				if (Z_TYPE_P(&fields) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&messageField);
					zephir_fast_join_str(&messageField, SL(", "), &fields);
				} else {
					ZEPHIR_CPY_WRT(&messageField, &fields);
				}
				ZEPHIR_INIT_NVAR(&_28$$18);
				object_init_ex(&_28$$18, phalcon_messages_message_ce);
				ZEPHIR_INIT_NVAR(&_29$$18);
				zephir_create_array(&_29$$18, 2, 0);
				ZEPHIR_INIT_NVAR(&_30$$18);
				zephir_get_class(&_30$$18, this_ptr, 0);
				zephir_array_update_string(&_29$$18, SL("model"), &_30$$18, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_31$$18, &relation, "getReferencedModel", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_29$$18, SL("referenceModel"), &_31$$18, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_30$$18);
				ZVAL_STRING(&_30$$18, "ConstraintViolation");
				ZVAL_LONG(&_32$$18, 0);
				ZEPHIR_CALL_METHOD(NULL, &_28$$18, "__construct", &_33, 3, &message, &messageField, &_30$$18, &_32$$18, &_29$$18);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessage", &_34, 0, &_28$$18);
				zephir_check_call_status();
				error = 1;
				break;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_36 = 1;
		while (1) {
			if (_36) {
				_36 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_35, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_35)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&relation, _1, "current", NULL, 0);
			zephir_check_call_status();
				validateWithNulls = 0;
				ZEPHIR_CALL_METHOD(&foreignKey, &relation, "getForeignKey", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
					continue;
				}
				action = 1;
				_37$$24 = zephir_array_isset_value_string(&foreignKey, SL("action"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_37$$24) {
					ZEPHIR_OBS_NVAR(&_38$$26);
					zephir_array_fetch_string(&_38$$26, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 4319);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					action = zephir_get_intval(&_38$$26);
				}
				if (action != 1) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&_39$$24, &relation, "getReferencedModel", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedModel, &manager, "load", &_40, 0, &_39$$24);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&conditions);
				array_init(&conditions);
				ZEPHIR_INIT_NVAR(&bindParams);
				array_init(&bindParams);
				numberNull = 0;
				ZEPHIR_CALL_METHOD(&fields, &relation, "getFields", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getReferencedFields", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&fields) == IS_ARRAY) {
					if (Z_TYPE_P(&fields) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_42$$28);
						zephir_string_to_char_array(&_42$$28, &fields);
						_41$$28 = &_42$$28;
					} else {
						_41$$28 = &fields;
					}
					zephir_is_iterable(_41$$28, 0, "phalcon/Mvc/Model.zep", 4362);
					if (Z_TYPE_P(_41$$28) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_41$$28), _44$$28, _45$$28, _43$$28)
						{
							ZEPHIR_INIT_NVAR(&position);
							if (_45$$28 != NULL) { 
								ZVAL_STR_COPY(&position, _45$$28);
							} else {
								ZVAL_LONG(&position, _44$$28);
							}
							ZEPHIR_INIT_NVAR(&field);
							ZVAL_COPY(&field, _43$$28);
							ZEPHIR_OBS_NVAR(&value);
							zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
							ZEPHIR_OBS_NVAR(&_46$$29);
							zephir_array_fetch(&_46$$29, &referencedFields, &position, PH_NOISY, "phalcon/Mvc/Model.zep", 4354);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&_47$$29);
							ZEPHIR_CONCAT_SVSV(&_47$$29, "[", &_46$$29, "] = ?", &position);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&conditions, &_47$$29, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4354);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4355);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (Z_TYPE_P(&value) == IS_NULL) {
								numberNull++;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _41$$28, "rewind", NULL, 0);
						zephir_check_call_status();
						_49$$28 = 1;
						while (1) {
							if (_49$$28) {
								_49$$28 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _41$$28, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_48$$28, _41$$28, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_48$$28)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&position, _41$$28, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&field, _41$$28, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_OBS_NVAR(&value);
								zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
								ZEPHIR_OBS_NVAR(&_50$$31);
								zephir_array_fetch(&_50$$31, &referencedFields, &position, PH_NOISY, "phalcon/Mvc/Model.zep", 4354);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_INIT_NVAR(&_51$$31);
								ZEPHIR_CONCAT_SVSV(&_51$$31, "[", &_50$$31, "] = ?", &position);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&conditions, &_51$$31, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4354);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4355);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
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
					ZEPHIR_INIT_NVAR(&_52$$33);
					ZEPHIR_CONCAT_SVS(&_52$$33, "[", &referencedFields, "] = ?0");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&conditions, &_52$$33, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4366);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4367);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (Z_TYPE_P(&value) == IS_NULL) {
						validateWithNulls = 1;
					}
				}
				ZEPHIR_OBS_NVAR(&extraConditions);
				_53$$24 = zephir_array_isset_string_fetch(&extraConditions, &foreignKey, SL("conditions"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_53$$24) {
					zephir_array_append(&conditions, &extraConditions, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4378);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				if (validateWithNulls) {
					ZEPHIR_OBS_NVAR(&allowNulls);
					_54$$36 = zephir_array_isset_string_fetch(&allowNulls, &foreignKey, SL("allowNulls"), 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_54$$36) {
						validateWithNulls = zephir_get_boolval(&allowNulls);
					} else {
						validateWithNulls = 0;
					}
				}
				_55$$24 = !validateWithNulls;
				if (_55$$24) {
					ZEPHIR_INIT_NVAR(&_57$$24);
					zephir_create_array(&_57$$24, 2, 0);
					ZEPHIR_INIT_NVAR(&_58$$24);
					zephir_fast_join_str(&_58$$24, SL(" AND "), &conditions);
					zephir_array_fast_append(&_57$$24, &_58$$24);
					zephir_array_update_string(&_57$$24, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_56$$24, &referencedModel, "count", NULL, 0, &_57$$24);
					zephir_check_call_status();
					_55$$24 = !zephir_is_true(&_56$$24);
				}
				if (_55$$24) {
					ZEPHIR_OBS_NVAR(&message);
					_59$$39 = zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_59$$39)) {
						ZEPHIR_INIT_NVAR(&message);
						if (Z_TYPE_P(&fields) == IS_ARRAY) {
							ZEPHIR_INIT_NVAR(&_60$$41);
							zephir_fast_join_str(&_60$$41, SL(", "), &fields);
							ZEPHIR_CONCAT_SVS(&message, "Value of fields \"", &_60$$41, "\" does not exist on referenced table");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							ZEPHIR_CONCAT_SVS(&message, "Value of field \"", &fields, "\" does not exist on referenced table");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					}
					if (Z_TYPE_P(&fields) == IS_ARRAY) {
						ZEPHIR_INIT_NVAR(&messageField);
						zephir_fast_join_str(&messageField, SL(", "), &fields);
					} else {
						ZEPHIR_CPY_WRT(&messageField, &fields);
					}
					ZEPHIR_INIT_NVAR(&_61$$39);
					object_init_ex(&_61$$39, phalcon_messages_message_ce);
					ZEPHIR_INIT_NVAR(&_62$$39);
					zephir_create_array(&_62$$39, 2, 0);
					ZEPHIR_INIT_NVAR(&_63$$39);
					zephir_get_class(&_63$$39, this_ptr, 0);
					zephir_array_update_string(&_62$$39, SL("model"), &_63$$39, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_64$$39, &relation, "getReferencedModel", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_string(&_62$$39, SL("referenceModel"), &_64$$39, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_63$$39);
					ZVAL_STRING(&_63$$39, "ConstraintViolation");
					ZVAL_LONG(&_65$$39, 0);
					ZEPHIR_CALL_METHOD(NULL, &_61$$39, "__construct", &_66, 3, &message, &messageField, &_63$$39, &_65$$39, &_62$$39);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessage", &_34, 0, &_61$$39);
					zephir_check_call_status();
					error = 1;
					break;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&relation);
	if (error) {
		ZEPHIR_INIT_VAR(&_68$$45);
		ZVAL_STRING(&_68$$45, "orm.events");
		ZEPHIR_CALL_CE_STATIC(&_67$$45, phalcon_support_settings_ce, "get", NULL, 0, &_68$$45);
		zephir_check_call_status();
		if (zephir_is_true(&_67$$45)) {
			ZEPHIR_INIT_VAR(&_69$$46);
			ZVAL_STRING(&_69$$46, "onValidationFails");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireEvent", NULL, 0, &_69$$46);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "cancelOperation", NULL, 0);
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
	zend_bool _11, _4$$3, _5$$3, _8$$3, _12$$8, _13$$8, _16$$8;
	zval manager, relations, relation, foreignKey, related, _0, *_1, _2, *_3, _10, _9$$3, _6$$5, _17$$8, _14$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, action = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&foreignKey);
	ZVAL_UNDEF(&related);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_14$$10);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&relations, &manager, "getHasOneAndHasMany", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (Z_TYPE_P(&relations) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &relations);
		_1 = &_2;
	} else {
		_1 = &relations;
	}
	zephir_is_iterable(_1, 0, "phalcon/Mvc/Model.zep", 4516);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&relation);
			ZVAL_COPY(&relation, _3);
			ZEPHIR_CALL_METHOD(&foreignKey, &relation, "getForeignKey", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
				continue;
			}
			action = 0;
			_4$$3 = Z_TYPE_P(&foreignKey) == IS_ARRAY;
			if (_4$$3) {
				_5$$3 = zephir_array_isset_value_string(&foreignKey, SL("action"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_4$$3 = _5$$3;
			}
			if (_4$$3) {
				ZEPHIR_OBS_NVAR(&_6$$5);
				zephir_array_fetch_string(&_6$$5, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 4492);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				action = zephir_get_intval(&_6$$5);
			}
			if (action != 2) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&related, &manager, "getRelationRecords", &_7, 0, &relation, this_ptr);
			zephir_check_call_status();
			_8$$3 = zephir_is_true(&related);
			if (_8$$3) {
				ZEPHIR_CALL_METHOD(&_9$$3, &related, "delete", NULL, 0);
				zephir_check_call_status();
				_8$$3 = ZEPHIR_IS_FALSE_IDENTICAL(&_9$$3);
			}
			if (_8$$3) {
				RETURN_MM_BOOL(0);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_11 = 1;
		while (1) {
			if (_11) {
				_11 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_10, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_10)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&relation, _1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&foreignKey, &relation, "getForeignKey", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
					continue;
				}
				action = 0;
				_12$$8 = Z_TYPE_P(&foreignKey) == IS_ARRAY;
				if (_12$$8) {
					_13$$8 = zephir_array_isset_value_string(&foreignKey, SL("action"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_12$$8 = _13$$8;
				}
				if (_12$$8) {
					ZEPHIR_OBS_NVAR(&_14$$10);
					zephir_array_fetch_string(&_14$$10, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 4492);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					action = zephir_get_intval(&_14$$10);
				}
				if (action != 2) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&related, &manager, "getRelationRecords", &_15, 0, &relation, this_ptr);
				zephir_check_call_status();
				_16$$8 = zephir_is_true(&related);
				if (_16$$8) {
					ZEPHIR_CALL_METHOD(&_17$$8, &related, "delete", NULL, 0);
					zephir_check_call_status();
					_16$$8 = ZEPHIR_IS_FALSE_IDENTICAL(&_17$$8);
				}
				if (_16$$8) {
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
	zval _13$$7, _29$$15;
	zval manager, relations, foreignKey, relation, relationClass, fields, message, messageField, _0, *_1, _2, *_3, _18, _7$$3, _8$$3, _9$$3, _6$$5, _12$$7, _14$$7, _15$$7, _23$$11, _24$$11, _25$$11, _22$$13, _28$$15, _30$$15, _31$$15, _33$$19, _34$$19, _35$$20;
	zend_bool error = 0, _19, _4$$3, _5$$3, _11$$7, _20$$11, _21$$11, _27$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_16 = NULL, *_17 = NULL, *_26 = NULL, *_32 = NULL;
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
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_28$$15);
	ZVAL_UNDEF(&_30$$15);
	ZVAL_UNDEF(&_31$$15);
	ZVAL_UNDEF(&_33$$19);
	ZVAL_UNDEF(&_34$$19);
	ZVAL_UNDEF(&_35$$20);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_29$$15);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&relations, &manager, "getHasOneAndHasMany", NULL, 0, this_ptr);
	zephir_check_call_status();
	error = 0;
	if (Z_TYPE_P(&relations) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &relations);
		_1 = &_2;
	} else {
		_1 = &relations;
	}
	zephir_is_iterable(_1, 0, "phalcon/Mvc/Model.zep", 4616);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&relation);
			ZVAL_COPY(&relation, _3);
			ZEPHIR_CALL_METHOD(&foreignKey, &relation, "getForeignKey", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
				continue;
			}
			action = 1;
			_4$$3 = Z_TYPE_P(&foreignKey) == IS_ARRAY;
			if (_4$$3) {
				_5$$3 = zephir_array_isset_value_string(&foreignKey, SL("action"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_4$$3 = _5$$3;
			}
			if (_4$$3) {
				ZEPHIR_OBS_NVAR(&_6$$5);
				zephir_array_fetch_string(&_6$$5, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 4561);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				action = zephir_get_intval(&_6$$5);
			}
			if (action != 1) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&relationClass, &relation, "getReferencedModel", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&fields, &relation, "getFields", NULL, 0);
			zephir_check_call_status();
			ZVAL_NULL(&_8$$3);
			ZEPHIR_INIT_NVAR(&_9$$3);
			ZVAL_STRING(&_9$$3, "count");
			ZEPHIR_CALL_METHOD(&_7$$3, &manager, "getRelationRecords", &_10, 0, &relation, this_ptr, &_8$$3, &_9$$3);
			zephir_check_call_status();
			if (zephir_is_true(&_7$$3)) {
				ZEPHIR_OBS_NVAR(&message);
				_11$$7 = zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_11$$7)) {
					ZEPHIR_INIT_NVAR(&message);
					ZEPHIR_CONCAT_SV(&message, "Record is referenced by model ", &relationClass);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				if (Z_TYPE_P(&fields) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&messageField);
					zephir_fast_join_str(&messageField, SL(", "), &fields);
				} else {
					ZEPHIR_CPY_WRT(&messageField, &fields);
				}
				ZEPHIR_INIT_NVAR(&_12$$7);
				object_init_ex(&_12$$7, phalcon_messages_message_ce);
				ZEPHIR_INIT_NVAR(&_13$$7);
				zephir_create_array(&_13$$7, 2, 0);
				ZEPHIR_INIT_NVAR(&_14$$7);
				zephir_get_class(&_14$$7, this_ptr, 0);
				zephir_array_update_string(&_13$$7, SL("model"), &_14$$7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_13$$7, SL("referenceModel"), &relationClass, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_14$$7);
				ZVAL_STRING(&_14$$7, "ConstraintViolation");
				ZVAL_LONG(&_15$$7, 0);
				ZEPHIR_CALL_METHOD(NULL, &_12$$7, "__construct", &_16, 3, &message, &messageField, &_14$$7, &_15$$7, &_13$$7);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessage", &_17, 0, &_12$$7);
				zephir_check_call_status();
				error = 1;
				break;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_19 = 1;
		while (1) {
			if (_19) {
				_19 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_18, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_18)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&relation, _1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&foreignKey, &relation, "getForeignKey", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
					continue;
				}
				action = 1;
				_20$$11 = Z_TYPE_P(&foreignKey) == IS_ARRAY;
				if (_20$$11) {
					_21$$11 = zephir_array_isset_value_string(&foreignKey, SL("action"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_20$$11 = _21$$11;
				}
				if (_20$$11) {
					ZEPHIR_OBS_NVAR(&_22$$13);
					zephir_array_fetch_string(&_22$$13, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 4561);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					action = zephir_get_intval(&_22$$13);
				}
				if (action != 1) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&relationClass, &relation, "getReferencedModel", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&fields, &relation, "getFields", NULL, 0);
				zephir_check_call_status();
				ZVAL_NULL(&_24$$11);
				ZEPHIR_INIT_NVAR(&_25$$11);
				ZVAL_STRING(&_25$$11, "count");
				ZEPHIR_CALL_METHOD(&_23$$11, &manager, "getRelationRecords", &_26, 0, &relation, this_ptr, &_24$$11, &_25$$11);
				zephir_check_call_status();
				if (zephir_is_true(&_23$$11)) {
					ZEPHIR_OBS_NVAR(&message);
					_27$$15 = zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_27$$15)) {
						ZEPHIR_INIT_NVAR(&message);
						ZEPHIR_CONCAT_SV(&message, "Record is referenced by model ", &relationClass);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					if (Z_TYPE_P(&fields) == IS_ARRAY) {
						ZEPHIR_INIT_NVAR(&messageField);
						zephir_fast_join_str(&messageField, SL(", "), &fields);
					} else {
						ZEPHIR_CPY_WRT(&messageField, &fields);
					}
					ZEPHIR_INIT_NVAR(&_28$$15);
					object_init_ex(&_28$$15, phalcon_messages_message_ce);
					ZEPHIR_INIT_NVAR(&_29$$15);
					zephir_create_array(&_29$$15, 2, 0);
					ZEPHIR_INIT_NVAR(&_30$$15);
					zephir_get_class(&_30$$15, this_ptr, 0);
					zephir_array_update_string(&_29$$15, SL("model"), &_30$$15, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_29$$15, SL("referenceModel"), &relationClass, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_30$$15);
					ZVAL_STRING(&_30$$15, "ConstraintViolation");
					ZVAL_LONG(&_31$$15, 0);
					ZEPHIR_CALL_METHOD(NULL, &_28$$15, "__construct", &_32, 3, &message, &messageField, &_30$$15, &_31$$15, &_29$$15);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessage", &_17, 0, &_28$$15);
					zephir_check_call_status();
					error = 1;
					break;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&relation);
	if (error) {
		ZEPHIR_INIT_VAR(&_34$$19);
		ZVAL_STRING(&_34$$19, "orm.events");
		ZEPHIR_CALL_CE_STATIC(&_33$$19, phalcon_support_settings_ce, "get", NULL, 0, &_34$$19);
		zephir_check_call_status();
		if (zephir_is_true(&_33$$19)) {
			ZEPHIR_INIT_VAR(&_35$$20);
			ZVAL_STRING(&_35$$20, "onValidationFails");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireEvent", NULL, 0, &_35$$20);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "cancelOperation", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

/**
 * Collects previously queried (belongs-to, has-one and has-one-through)
 * related records along with freshly added one
 *
 * @return array Related records that should be saved
 *
 * @phpstan-return mvc_model_related
 */
PHP_METHOD(Phalcon_Mvc_Model, collectRelatedToSave)
{
	zend_bool _5$$3, _6$$3, _8$$3;
	zend_string *_4;
	zend_ulong _3;
	zval related, dirtyRelated;
	zval name, record, _0, _1, *_2, _7$$3, _9$$3, _10$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1016, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(Z_TYPE_P(&_0) != IS_ARRAY)) {
		zephir_throw_variable_type_error(&_0, "related", "array");
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&related, &_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 1015, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(Z_TYPE_P(&_1) != IS_ARRAY)) {
		zephir_throw_variable_type_error(&_1, "dirtyRelated", "array");
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&dirtyRelated, &_1);
	zephir_is_iterable(&related, 0, "phalcon/Mvc/Model.zep", 4668);
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
		_5$$3 = zephir_array_isset_value(&dirtyRelated, &name);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_5$$3) {
			continue;
		}
		_6$$3 = Z_TYPE_P(&record) != IS_OBJECT;
		if (!(_6$$3)) {
			_6$$3 = !((zephir_instance_of_ev(&record, phalcon_mvc_modelinterface_ce)));
		}
		if (_6$$3) {
			continue;
		}
		ZEPHIR_CALL_METHOD(&_7$$3, &record, "hasSnapshotData", NULL, 0);
		zephir_check_call_status();
		_8$$3 = zephir_is_true(&_7$$3);
		if (_8$$3) {
			ZEPHIR_CALL_METHOD(&_9$$3, &record, "hasChanged", NULL, 0);
			zephir_check_call_status();
			_8$$3 = !zephir_is_true(&_9$$3);
		}
		if (_8$$3) {
			continue;
		}
		ZVAL_LONG(&_10$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, &record, "setDirtyState", NULL, 0, &_10$$3);
		zephir_check_call_status();
		zephir_array_update_zval(&dirtyRelated, &name, &record, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&record);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CTOR(&dirtyRelated);
}

/**
 * Sends a pre-build INSERT SQL statement to the relational database system
 *
 * @param string|array table
 * @param bool|string identityField
 */
PHP_METHOD(Phalcon_Mvc_Model, doLowInsert)
{
	zend_string *_90$$62;
	zend_ulong _89$$62;
	zend_bool useExplicitIdentity = 0, useSequences = 0, _36, _78, _5$$6, _9$$5, _10$$5, _11$$5, _12$$9, _13$$10, _17$$12, _18$$12, _24$$12, _28$$17, _37$$22, _41$$21, _42$$21, _43$$21, _44$$25, _45$$26, _49$$28, _50$$28, _56$$28, _60$$33, _68$$39, _71$$42, _72$$46, _80$$53, _81$$53, _82$$53, _92$$62;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_16 = NULL, *_22 = NULL, *_23 = NULL, *_27 = NULL, *_32 = NULL, *_34 = NULL, *_40 = NULL, *_48 = NULL, *_54 = NULL, *_55 = NULL, *_59 = NULL, *_64 = NULL, *_66 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *metaData, metaData_sub, *connection, connection_sub, *table = NULL, table_sub, *identityField, identityField_sub, __$null, attributes, automaticAttributes, bindDataTypes, bindSkip, bindType, columnMap, defaultValue, defaultValues, field, lastInsertedId, manager, rawValue, rawValues, sequenceName, schema, source, success, attributeField, bindTypes, fields, snapshot, unsetDefaultValues, value, values, _0, _1, _2, *_3, *_4, _35, _6$$7, _7$$7, _14$$11, _15$$11, _19$$13, _20$$13, _21$$13, _25$$16, _26$$16, _29$$18, _30$$18, _31$$18, _33$$18, _38$$23, _39$$23, _46$$27, _47$$27, _51$$29, _52$$29, _53$$29, _57$$32, _58$$32, _61$$34, _62$$34, _63$$34, _65$$34, _67$$37, _69$$40, _70$$40, _73$$48, _74$$48, _75$$52, _76$$52, _77$$52, _79$$53, _83$$53, _84$$61, _85$$61, *_86$$62, _87$$62, *_88$$62, _91$$62, _93$$62, _94$$62;
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
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_26$$16);
	ZVAL_UNDEF(&_29$$18);
	ZVAL_UNDEF(&_30$$18);
	ZVAL_UNDEF(&_31$$18);
	ZVAL_UNDEF(&_33$$18);
	ZVAL_UNDEF(&_38$$23);
	ZVAL_UNDEF(&_39$$23);
	ZVAL_UNDEF(&_46$$27);
	ZVAL_UNDEF(&_47$$27);
	ZVAL_UNDEF(&_51$$29);
	ZVAL_UNDEF(&_52$$29);
	ZVAL_UNDEF(&_53$$29);
	ZVAL_UNDEF(&_57$$32);
	ZVAL_UNDEF(&_58$$32);
	ZVAL_UNDEF(&_61$$34);
	ZVAL_UNDEF(&_62$$34);
	ZVAL_UNDEF(&_63$$34);
	ZVAL_UNDEF(&_65$$34);
	ZVAL_UNDEF(&_67$$37);
	ZVAL_UNDEF(&_69$$40);
	ZVAL_UNDEF(&_70$$40);
	ZVAL_UNDEF(&_73$$48);
	ZVAL_UNDEF(&_74$$48);
	ZVAL_UNDEF(&_75$$52);
	ZVAL_UNDEF(&_76$$52);
	ZVAL_UNDEF(&_77$$52);
	ZVAL_UNDEF(&_79$$53);
	ZVAL_UNDEF(&_83$$53);
	ZVAL_UNDEF(&_84$$61);
	ZVAL_UNDEF(&_85$$61);
	ZVAL_UNDEF(&_87$$62);
	ZVAL_UNDEF(&_91$$62);
	ZVAL_UNDEF(&_93$$62);
	ZVAL_UNDEF(&_94$$62);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1019, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&rawValues, &_0);
	ZEPHIR_CALL_METHOD(&attributes, metaData, "getAttributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&bindDataTypes, metaData, "getBindTypes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&automaticAttributes, metaData, "getAutomaticCreateAttributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&defaultValues, metaData, "getDefaultValues", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "orm.column_renaming");
	ZEPHIR_CALL_CE_STATIC(&_1, phalcon_support_settings_ce, "get", NULL, 0, &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_CALL_METHOD(&columnMap, metaData, "getColumnMap", NULL, 0, this_ptr);
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
	zephir_is_iterable(_3, 0, "phalcon/Mvc/Model.zep", 4790);
	if (Z_TYPE_P(_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3), _4)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _4);
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				_5$$6 = zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_5$$6))) {
					ZEPHIR_INIT_NVAR(&_6$$7);
					object_init_ex(&_6$$7, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
					ZEPHIR_INIT_NVAR(&_7$$7);
					zephir_get_class(&_7$$7, this_ptr, 0);
					ZEPHIR_CALL_METHOD(NULL, &_6$$7, "__construct", &_8, 0, &field, &_7$$7);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_6$$7, "phalcon/Mvc/Model.zep", 4718);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &field);
			}
			_9$$5 = zephir_array_key_exists(&automaticAttributes, &attributeField);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_10$$5 = !(_9$$5);
			if (_10$$5) {
				_11$$5 = !ZEPHIR_IS_EQUAL(&field, identityField);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_10$$5 = _11$$5;
			}
			if (_10$$5) {
				ZEPHIR_OBS_NVAR(&rawValue);
				_12$$9 = zephir_array_isset_fetch(&rawValue, &rawValues, &attributeField, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_12$$9) {
					ZEPHIR_OBS_NVAR(&bindType);
					_13$$10 = zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_13$$10))) {
						ZEPHIR_INIT_NVAR(&_14$$11);
						object_init_ex(&_14$$11, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
						ZEPHIR_INIT_NVAR(&_15$$11);
						zephir_get_class(&_15$$11, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_14$$11, "__construct", &_16, 0, &field, &_15$$11);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_14$$11, "phalcon/Mvc/Model.zep", 4735);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4738);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&values, &rawValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4739);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4740);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&snapshot, &attributeField, &rawValue, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_OBS_NVAR(&value);
					if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
						_17$$12 = Z_TYPE_P(&value) == IS_NULL;
						if (_17$$12) {
							_18$$12 = zephir_array_key_exists(&defaultValues, &field);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							_17$$12 = _18$$12;
						}
						if (_17$$12) {
							ZEPHIR_OBS_NVAR(&_19$$13);
							zephir_array_fetch(&_19$$13, &defaultValues, &field, PH_NOISY, "phalcon/Mvc/Model.zep", 4744);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&snapshot, &attributeField, &_19$$13, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&_20$$13);
							zephir_array_fetch(&_20$$13, &defaultValues, &field, PH_NOISY, "phalcon/Mvc/Model.zep", 4745);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&unsetDefaultValues, &attributeField, &_20$$13, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_METHOD(&_21$$13, connection, "supportsDefaultValue", &_22, 0);
							zephir_check_call_status();
							if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_21$$13))) {
								continue;
							}
							ZEPHIR_CALL_METHOD(&value, connection, "getDefaultValue", &_23, 0);
							zephir_check_call_status();
						} else {
							zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
						ZEPHIR_OBS_NVAR(&bindType);
						_24$$12 = zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (UNEXPECTED(!(_24$$12))) {
							ZEPHIR_INIT_NVAR(&_25$$16);
							object_init_ex(&_25$$16, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
							ZEPHIR_INIT_NVAR(&_26$$16);
							zephir_get_class(&_26$$16, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_25$$16, "__construct", &_27, 0, &field, &_26$$16);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_25$$16, "phalcon/Mvc/Model.zep", 4760);
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4763);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4764);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4765);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						_28$$17 = zephir_array_key_exists(&defaultValues, &field);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_28$$17) {
							ZEPHIR_OBS_NVAR(&_29$$18);
							zephir_array_fetch(&_29$$18, &defaultValues, &field, PH_NOISY, "phalcon/Mvc/Model.zep", 4768);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&snapshot, &attributeField, &_29$$18, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&_30$$18);
							zephir_array_fetch(&_30$$18, &defaultValues, &field, PH_NOISY, "phalcon/Mvc/Model.zep", 4769);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&unsetDefaultValues, &attributeField, &_30$$18, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_METHOD(&_31$$18, connection, "supportsDefaultValue", &_32, 0);
							zephir_check_call_status();
							if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_31$$18))) {
								continue;
							}
							ZEPHIR_CALL_METHOD(&_33$$18, connection, "getDefaultValue", &_34, 0);
							zephir_check_call_status();
							zephir_array_append(&values, &_33$$18, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4775);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4777);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4781);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4782);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _3, "rewind", NULL, 0);
		zephir_check_call_status();
		_36 = 1;
		while (1) {
			if (_36) {
				_36 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _3, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_35, _3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_35)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, _3, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					_37$$22 = zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_37$$22))) {
						ZEPHIR_INIT_NVAR(&_38$$23);
						object_init_ex(&_38$$23, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
						ZEPHIR_INIT_NVAR(&_39$$23);
						zephir_get_class(&_39$$23, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_38$$23, "__construct", &_40, 0, &field, &_39$$23);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_38$$23, "phalcon/Mvc/Model.zep", 4718);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &field);
				}
				_41$$21 = zephir_array_key_exists(&automaticAttributes, &attributeField);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_42$$21 = !(_41$$21);
				if (_42$$21) {
					_43$$21 = !ZEPHIR_IS_EQUAL(&field, identityField);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_42$$21 = _43$$21;
				}
				if (_42$$21) {
					ZEPHIR_OBS_NVAR(&rawValue);
					_44$$25 = zephir_array_isset_fetch(&rawValue, &rawValues, &attributeField, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_44$$25) {
						ZEPHIR_OBS_NVAR(&bindType);
						_45$$26 = zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (UNEXPECTED(!(_45$$26))) {
							ZEPHIR_INIT_NVAR(&_46$$27);
							object_init_ex(&_46$$27, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
							ZEPHIR_INIT_NVAR(&_47$$27);
							zephir_get_class(&_47$$27, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_46$$27, "__construct", &_48, 0, &field, &_47$$27);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_46$$27, "phalcon/Mvc/Model.zep", 4735);
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4738);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&values, &rawValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4739);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4740);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_zval(&snapshot, &attributeField, &rawValue, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_OBS_NVAR(&value);
						if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
							_49$$28 = Z_TYPE_P(&value) == IS_NULL;
							if (_49$$28) {
								_50$$28 = zephir_array_key_exists(&defaultValues, &field);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								_49$$28 = _50$$28;
							}
							if (_49$$28) {
								ZEPHIR_OBS_NVAR(&_51$$29);
								zephir_array_fetch(&_51$$29, &defaultValues, &field, PH_NOISY, "phalcon/Mvc/Model.zep", 4744);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_zval(&snapshot, &attributeField, &_51$$29, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&_52$$29);
								zephir_array_fetch(&_52$$29, &defaultValues, &field, PH_NOISY, "phalcon/Mvc/Model.zep", 4745);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_zval(&unsetDefaultValues, &attributeField, &_52$$29, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CALL_METHOD(&_53$$29, connection, "supportsDefaultValue", &_54, 0);
								zephir_check_call_status();
								if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_53$$29))) {
									continue;
								}
								ZEPHIR_CALL_METHOD(&value, connection, "getDefaultValue", &_55, 0);
								zephir_check_call_status();
							} else {
								zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
							ZEPHIR_OBS_NVAR(&bindType);
							_56$$28 = zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (UNEXPECTED(!(_56$$28))) {
								ZEPHIR_INIT_NVAR(&_57$$32);
								object_init_ex(&_57$$32, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
								ZEPHIR_INIT_NVAR(&_58$$32);
								zephir_get_class(&_58$$32, this_ptr, 0);
								ZEPHIR_CALL_METHOD(NULL, &_57$$32, "__construct", &_59, 0, &field, &_58$$32);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_57$$32, "phalcon/Mvc/Model.zep", 4760);
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4763);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4764);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4765);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							_60$$33 = zephir_array_key_exists(&defaultValues, &field);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (_60$$33) {
								ZEPHIR_OBS_NVAR(&_61$$34);
								zephir_array_fetch(&_61$$34, &defaultValues, &field, PH_NOISY, "phalcon/Mvc/Model.zep", 4768);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_zval(&snapshot, &attributeField, &_61$$34, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&_62$$34);
								zephir_array_fetch(&_62$$34, &defaultValues, &field, PH_NOISY, "phalcon/Mvc/Model.zep", 4769);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_zval(&unsetDefaultValues, &attributeField, &_62$$34, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CALL_METHOD(&_63$$34, connection, "supportsDefaultValue", &_64, 0);
								zephir_check_call_status();
								if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_63$$34))) {
									continue;
								}
								ZEPHIR_CALL_METHOD(&_65$$34, connection, "getDefaultValue", &_66, 0);
								zephir_check_call_status();
								zephir_array_append(&values, &_65$$34, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4775);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} else {
								zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4777);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4781);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4782);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&field);
	if (!ZEPHIR_IS_FALSE_IDENTICAL(identityField)) {
		ZEPHIR_CALL_METHOD(&defaultValue, connection, "getDefaultIdValue", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_67$$37, connection, "useExplicitIdValue", NULL, 0);
		zephir_check_call_status();
		useExplicitIdentity = zephir_get_boolval(&_67$$37);
		if (useExplicitIdentity) {
			zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4800);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&attributeField);
			_68$$39 = zephir_array_isset_fetch(&attributeField, &columnMap, identityField, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (UNEXPECTED(!(_68$$39))) {
				ZEPHIR_INIT_VAR(&_69$$40);
				object_init_ex(&_69$$40, phalcon_mvc_model_exceptions_identitynotincolumnmap_ce);
				ZEPHIR_INIT_VAR(&_70$$40);
				zephir_get_class(&_70$$40, this_ptr, 0);
				ZEPHIR_CALL_METHOD(NULL, &_69$$40, "__construct", NULL, 0, identityField, &_70$$40);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_69$$40, "phalcon/Mvc/Model.zep", 4808);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(&attributeField, identityField);
		}
		ZEPHIR_OBS_NVAR(&value);
		if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
			_71$$42 = Z_TYPE_P(&value) == IS_NULL;
			if (!(_71$$42)) {
				_71$$42 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
			}
			if (_71$$42) {
				if (useExplicitIdentity) {
					zephir_array_append(&values, &defaultValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4820);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4820);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else if (ZEPHIR_IS_EMPTY(&values)) {
					zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4827);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&values, &defaultValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4828);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4829);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} else {
				if (!(useExplicitIdentity)) {
					zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4837);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_OBS_NVAR(&bindType);
				_72$$46 = zephir_array_isset_fetch(&bindType, &bindDataTypes, identityField, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_72$$46))) {
					ZEPHIR_INIT_VAR(&_73$$48);
					object_init_ex(&_73$$48, phalcon_mvc_model_exceptions_identitynotintablecolumns_ce);
					ZEPHIR_INIT_VAR(&_74$$48);
					zephir_get_class(&_74$$48, this_ptr, 0);
					ZEPHIR_CALL_METHOD(NULL, &_73$$48, "__construct", NULL, 0, identityField, &_74$$48);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_73$$48, "phalcon/Mvc/Model.zep", 4844);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4847);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4848);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} else {
			if (useExplicitIdentity) {
				zephir_array_append(&values, &defaultValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4852);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4853);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else if (ZEPHIR_IS_EMPTY(&values)) {
				zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4860);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&values, &defaultValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4861);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4862);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	if (Z_TYPE_P(table) == IS_ARRAY) {
		zephir_memory_observe(&_75$$52);
		zephir_array_fetch_long(&_75$$52, table, 0, PH_NOISY, "phalcon/Mvc/Model.zep", 4871);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&_76$$52);
		zephir_array_fetch_long(&_76$$52, table, 1, PH_NOISY, "phalcon/Mvc/Model.zep", 4871);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_77$$52);
		ZEPHIR_CONCAT_VSV(&_77$$52, &_75$$52, ".", &_76$$52);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(table, &_77$$52);
	}
	ZEPHIR_CALL_METHOD(&success, connection, "insert", NULL, 0, table, &values, &fields, &bindTypes);
	zephir_check_call_status();
	_78 = zephir_is_true(&success);
	if (_78) {
		_78 = !ZEPHIR_IS_FALSE_IDENTICAL(identityField);
	}
	if (_78) {
		ZEPHIR_INIT_VAR(&sequenceName);
		ZVAL_NULL(&sequenceName);
		ZEPHIR_CALL_METHOD(&_79$$53, connection, "supportSequences", NULL, 0);
		zephir_check_call_status();
		useSequences = zephir_get_boolval(&_79$$53);
		if (useSequences) {
			if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("getsequencename")) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(&sequenceName, this_ptr, "getSequenceName", NULL, 0);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&source, this_ptr, "getSource", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&schema, this_ptr, "getSchema", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&sequenceName);
				if (ZEPHIR_IS_EMPTY(&schema)) {
					ZEPHIR_CONCAT_VSVS(&sequenceName, &source, "_", identityField, "_seq");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CONCAT_VSVSVS(&sequenceName, &schema, ".", &source, "_", identityField, "_seq");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		}
		ZEPHIR_OBS_NVAR(&value);
		zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC);
		_80$$53 = Z_TYPE_P(&value) != IS_NULL;
		if (_80$$53) {
			_80$$53 = !ZEPHIR_IS_STRING_IDENTICAL(&value, "");
		}
		_81$$53 = _80$$53;
		if (_81$$53) {
			_82$$53 = useSequences;
			if (!(_82$$53)) {
				_82$$53 = !ZEPHIR_IS_LONG(&value, 0);
			}
			_81$$53 = _82$$53;
		}
		if (_81$$53) {
			ZEPHIR_CPY_WRT(&lastInsertedId, &value);
		} else {
			ZEPHIR_CALL_METHOD(&lastInsertedId, connection, "lastInsertId", NULL, 0, &sequenceName);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(&_83$$53);
		ZVAL_STRING(&_83$$53, "orm.cast_last_insert_id_to_int");
		ZEPHIR_CALL_CE_STATIC(&_79$$53, phalcon_support_settings_ce, "get", NULL, 0, &_83$$53);
		zephir_check_call_status();
		if (UNEXPECTED(zephir_is_true(&_79$$53))) {
			ZVAL_LONG(&_84$$61, 10);
			ZEPHIR_CALL_FUNCTION(&_85$$61, "intval", NULL, 95, &lastInsertedId, &_84$$61);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&lastInsertedId, &_85$$61);
		}
		zephir_update_property_zval_zval(this_ptr, &attributeField, &lastInsertedId);
		zephir_array_update_zval(&snapshot, &attributeField, &lastInsertedId, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1027, &__$null);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1028, &__$null);
	}
	if (zephir_is_true(&success)) {
		ZEPHIR_CALL_METHOD(NULL, &manager, "registerWrite", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (Z_TYPE_P(&unsetDefaultValues) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_87$$62);
			zephir_string_to_char_array(&_87$$62, &unsetDefaultValues);
			_86$$62 = &_87$$62;
		} else {
			_86$$62 = &unsetDefaultValues;
		}
		zephir_is_iterable(_86$$62, 0, "phalcon/Mvc/Model.zep", 4953);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_86$$62), _89$$62, _90$$62, _88$$62)
		{
			ZEPHIR_INIT_NVAR(&attributeField);
			if (_90$$62 != NULL) { 
				ZVAL_STR_COPY(&attributeField, _90$$62);
			} else {
				ZVAL_LONG(&attributeField, _89$$62);
			}
			ZEPHIR_INIT_NVAR(&defaultValue);
			ZVAL_COPY(&defaultValue, _88$$62);
			zephir_update_property_zval_zval(this_ptr, &attributeField, &defaultValue);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&defaultValue);
		ZEPHIR_INIT_NVAR(&attributeField);
		ZEPHIR_CALL_METHOD(&_91$$62, &manager, "isKeepingSnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		_92$$62 = zephir_is_true(&_91$$62);
		if (_92$$62) {
			ZEPHIR_INIT_VAR(&_94$$62);
			ZVAL_STRING(&_94$$62, "orm.update_snapshot_on_save");
			ZEPHIR_CALL_CE_STATIC(&_93$$62, phalcon_support_settings_ce, "get", NULL, 0, &_94$$62);
			zephir_check_call_status();
			_92$$62 = zephir_is_true(&_93$$62);
		}
		if (_92$$62) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1018, &snapshot);
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
	zval _31$$26, _32$$26, _58$$50, _59$$50;
	zval _118;
	zend_bool changed = 0, useDynamicUpdate = 0, _3, _120, _122, _35$$5, _7$$7, _14$$6, _15$$11, _19$$11, _20$$14, _21$$20, _25$$20, _27$$20, _33$$27, _36$$31, _42$$30, _43$$35, _47$$35, _48$$38, _49$$44, _53$$44, _55$$44, _60$$51, _82$$55, _64$$57, _70$$56, _71$$61, _75$$61, _76$$64, _77$$64, _78$$64, _80$$64, _83$$68, _89$$67, _90$$72, _94$$72, _95$$75, _96$$75, _97$$75, _99$$75, _110$$79, _105$$82, _111$$88;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_13 = NULL, *_18 = NULL, *_24 = NULL, *_29 = NULL, *_41 = NULL, *_46 = NULL, *_52 = NULL, *_69 = NULL, *_74 = NULL, *_88 = NULL, *_93 = NULL, *_108 = NULL, *_114 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *metaData, metaData_sub, *connection, connection_sub, *table = NULL, table_sub, __$null, automaticAttributes, attributeField, bindSkip, bindDataTypes, bindType, bindTypes, columnMap, dataType, dataTypes, defaultValues, field, fields, manager, nonPrimary, newSnapshot, rawValue, rawValues, success, primaryKeys, snapshot, snapshotValue, uniqueKey, uniqueParams, value, values, updateValue, _0, _1, _2, _119, _121, _123, *_4$$5, _5$$5, *_6$$5, _34$$5, _8$$8, _10$$8, _11$$9, _12$$9, _16$$12, _17$$12, _22$$21, _23$$21, _26$$22, _28$$25, _30$$25, _37$$32, _38$$32, _39$$33, _40$$33, _44$$36, _45$$36, _50$$45, _51$$45, _54$$46, _56$$49, _57$$49, *_61$$55, _62$$55, *_63$$55, _81$$55, _65$$58, _66$$58, _67$$59, _68$$59, _72$$62, _73$$62, _79$$64, _84$$69, _85$$69, _86$$70, _87$$70, _91$$73, _92$$73, _98$$75, _100$$80, _101$$80, *_102$$79, _103$$79, *_104$$79, _109$$79, _106$$83, _107$$83, _112$$89, _113$$89, _115$$93, _116$$93, _117$$93, _124$$96, _125$$97;
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
	ZVAL_UNDEF(&_119);
	ZVAL_UNDEF(&_121);
	ZVAL_UNDEF(&_123);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_34$$5);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_22$$21);
	ZVAL_UNDEF(&_23$$21);
	ZVAL_UNDEF(&_26$$22);
	ZVAL_UNDEF(&_28$$25);
	ZVAL_UNDEF(&_30$$25);
	ZVAL_UNDEF(&_37$$32);
	ZVAL_UNDEF(&_38$$32);
	ZVAL_UNDEF(&_39$$33);
	ZVAL_UNDEF(&_40$$33);
	ZVAL_UNDEF(&_44$$36);
	ZVAL_UNDEF(&_45$$36);
	ZVAL_UNDEF(&_50$$45);
	ZVAL_UNDEF(&_51$$45);
	ZVAL_UNDEF(&_54$$46);
	ZVAL_UNDEF(&_56$$49);
	ZVAL_UNDEF(&_57$$49);
	ZVAL_UNDEF(&_62$$55);
	ZVAL_UNDEF(&_81$$55);
	ZVAL_UNDEF(&_65$$58);
	ZVAL_UNDEF(&_66$$58);
	ZVAL_UNDEF(&_67$$59);
	ZVAL_UNDEF(&_68$$59);
	ZVAL_UNDEF(&_72$$62);
	ZVAL_UNDEF(&_73$$62);
	ZVAL_UNDEF(&_79$$64);
	ZVAL_UNDEF(&_84$$69);
	ZVAL_UNDEF(&_85$$69);
	ZVAL_UNDEF(&_86$$70);
	ZVAL_UNDEF(&_87$$70);
	ZVAL_UNDEF(&_91$$73);
	ZVAL_UNDEF(&_92$$73);
	ZVAL_UNDEF(&_98$$75);
	ZVAL_UNDEF(&_100$$80);
	ZVAL_UNDEF(&_101$$80);
	ZVAL_UNDEF(&_103$$79);
	ZVAL_UNDEF(&_109$$79);
	ZVAL_UNDEF(&_106$$83);
	ZVAL_UNDEF(&_107$$83);
	ZVAL_UNDEF(&_112$$89);
	ZVAL_UNDEF(&_113$$89);
	ZVAL_UNDEF(&_115$$93);
	ZVAL_UNDEF(&_116$$93);
	ZVAL_UNDEF(&_117$$93);
	ZVAL_UNDEF(&_124$$96);
	ZVAL_UNDEF(&_125$$97);
	ZVAL_UNDEF(&_118);
	ZVAL_UNDEF(&_31$$26);
	ZVAL_UNDEF(&_32$$26);
	ZVAL_UNDEF(&_58$$50);
	ZVAL_UNDEF(&_59$$50);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1019, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&rawValues, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&_1, &manager, "isUsingDynamicUpdate", NULL, 0, this_ptr);
	zephir_check_call_status();
	useDynamicUpdate = zephir_get_boolval(&_1);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 1018, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&snapshot, &_0);
	ZEPHIR_CALL_METHOD(&dataTypes, metaData, "getDataTypes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&bindDataTypes, metaData, "getBindTypes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&defaultValues, metaData, "getDefaultValues", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&nonPrimary, metaData, "getNonPrimaryKeyAttributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&automaticAttributes, metaData, "getAutomaticUpdateAttributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "orm.column_renaming");
	ZEPHIR_CALL_CE_STATIC(&_1, phalcon_support_settings_ce, "get", NULL, 0, &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_CALL_METHOD(&columnMap, metaData, "getColumnMap", NULL, 0, this_ptr);
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
		zephir_is_iterable(_4$$5, 0, "phalcon/Mvc/Model.zep", 5113);
		if (Z_TYPE_P(_4$$5) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_4$$5), _6$$5)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _6$$5);
				changed = 0;
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					_7$$7 = zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_7$$7))) {
						ZEPHIR_INIT_NVAR(&_10$$8);
						ZVAL_STRING(&_10$$8, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_8$$8, phalcon_support_settings_ce, "get", &_9, 0, &_10$$8);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_8$$8))) {
							ZEPHIR_INIT_NVAR(&_11$$9);
							object_init_ex(&_11$$9, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
							ZEPHIR_INIT_NVAR(&_12$$9);
							zephir_get_class(&_12$$9, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_11$$9, "__construct", &_13, 0, &field, &_12$$9);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_11$$9, "phalcon/Mvc/Model.zep", 5007);
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &field);
				}
				_14$$6 = zephir_array_key_exists(&automaticAttributes, &attributeField);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_14$$6)) {
					ZEPHIR_OBS_NVAR(&bindType);
					_15$$11 = zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_15$$11))) {
						ZEPHIR_INIT_NVAR(&_16$$12);
						object_init_ex(&_16$$12, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
						ZEPHIR_INIT_NVAR(&_17$$12);
						zephir_get_class(&_17$$12, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_16$$12, "__construct", &_18, 0, &field, &_17$$12);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_16$$12, "phalcon/Mvc/Model.zep", 5018);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&rawValue);
					_19$$11 = zephir_array_isset_fetch(&rawValue, &rawValues, &attributeField, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_19$$11) {
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5025);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&values, &rawValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5026);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5027);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_zval(&newSnapshot, &attributeField, &rawValue, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_OBS_NVAR(&value);
						if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
							ZEPHIR_OBS_NVAR(&snapshotValue);
							_20$$14 = zephir_array_isset_fetch(&snapshotValue, &snapshot, &attributeField, 0);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (!(_20$$14)) {
								changed = 1;
							} else {
								if (Z_TYPE_P(&value) == IS_NULL) {
									changed = Z_TYPE_P(&snapshotValue) != IS_NULL;
								} else {
									if (Z_TYPE_P(&snapshotValue) == IS_NULL) {
										changed = 1;
									} else {
										ZEPHIR_OBS_NVAR(&dataType);
										_21$$20 = zephir_array_isset_fetch(&dataType, &dataTypes, &field, 0);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										if (UNEXPECTED(!(_21$$20))) {
											ZEPHIR_INIT_NVAR(&_22$$21);
											object_init_ex(&_22$$21, phalcon_mvc_model_exceptions_datatypenotdefined_ce);
											ZEPHIR_INIT_NVAR(&_23$$21);
											zephir_get_class(&_23$$21, this_ptr, 0);
											ZEPHIR_CALL_METHOD(NULL, &_22$$21, "__construct", &_24, 0, &field, &_23$$21);
											zephir_check_call_status();
											zephir_throw_exception_debug(&_22$$21, "phalcon/Mvc/Model.zep", 5051);
											ZEPHIR_MM_RESTORE();
											return;
										}
										_25$$20 = (Z_TYPE_P(&snapshotValue) == IS_OBJECT);
										if (_25$$20) {
											_25$$20 = zephir_instance_of_ev(&snapshotValue, phalcon_db_rawvalue_ce);
										}
										if (_25$$20) {
											ZEPHIR_CALL_METHOD(&_26$$22, &snapshotValue, "getValue", NULL, 0);
											zephir_check_call_status();
											ZEPHIR_CPY_WRT(&snapshotValue, &_26$$22);
										}
										ZEPHIR_CPY_WRT(&updateValue, &value);
										_27$$20 = (Z_TYPE_P(&value) == IS_OBJECT);
										if (_27$$20) {
											_27$$20 = zephir_instance_of_ev(&value, phalcon_db_rawvalue_ce);
										}
										if (_27$$20) {
											ZEPHIR_CALL_METHOD(&updateValue, &value, "getValue", NULL, 0);
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
											ZEPHIR_CALL_FUNCTION(&_28$$25, "floatval", &_29, 32, &snapshotValue);
											zephir_check_call_status();
											ZEPHIR_CALL_FUNCTION(&_30$$25, "floatval", &_29, 32, &updateValue);
											zephir_check_call_status();
											changed = !ZEPHIR_IS_IDENTICAL(&_28$$25, &_30$$25);
											goto zephir_switch_0_end;
										zephir_switch_0_clause_3: ;
										zephir_switch_0_clause_4: ;
										zephir_switch_0_clause_5: ;
										zephir_switch_0_clause_6: ;
										zephir_switch_0_clause_7: ;
										zephir_switch_0_clause_8: ;
										zephir_switch_0_clause_9: ;
											zephir_cast_to_string(&_31$$26, &snapshotValue);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_cast_to_string(&_32$$26, &updateValue);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											changed = !ZEPHIR_IS_IDENTICAL(&_31$$26, &_32$$26);
											goto zephir_switch_0_end;
										zephir_switch_0_clause_10: ;
											_33$$27 = !ZEPHIR_IS_EQUAL(&updateValue, &snapshotValue);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											changed = _33$$27;
										zephir_switch_0_end: ;

									}
								}
							}
							if (changed) {
								zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5100);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5101);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5102);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
							zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _4$$5, "rewind", NULL, 0);
			zephir_check_call_status();
			_35$$5 = 1;
			while (1) {
				if (_35$$5) {
					_35$$5 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _4$$5, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_34$$5, _4$$5, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_34$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, _4$$5, "current", NULL, 0);
				zephir_check_call_status();
					changed = 0;
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						_36$$31 = zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (UNEXPECTED(!(_36$$31))) {
							ZEPHIR_INIT_NVAR(&_38$$32);
							ZVAL_STRING(&_38$$32, "orm.ignore_unknown_columns");
							ZEPHIR_CALL_CE_STATIC(&_37$$32, phalcon_support_settings_ce, "get", &_9, 0, &_38$$32);
							zephir_check_call_status();
							if (UNEXPECTED(!zephir_is_true(&_37$$32))) {
								ZEPHIR_INIT_NVAR(&_39$$33);
								object_init_ex(&_39$$33, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
								ZEPHIR_INIT_NVAR(&_40$$33);
								zephir_get_class(&_40$$33, this_ptr, 0);
								ZEPHIR_CALL_METHOD(NULL, &_39$$33, "__construct", &_41, 0, &field, &_40$$33);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_39$$33, "phalcon/Mvc/Model.zep", 5007);
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} else {
						ZEPHIR_CPY_WRT(&attributeField, &field);
					}
					_42$$30 = zephir_array_key_exists(&automaticAttributes, &attributeField);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_42$$30)) {
						ZEPHIR_OBS_NVAR(&bindType);
						_43$$35 = zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (UNEXPECTED(!(_43$$35))) {
							ZEPHIR_INIT_NVAR(&_44$$36);
							object_init_ex(&_44$$36, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
							ZEPHIR_INIT_NVAR(&_45$$36);
							zephir_get_class(&_45$$36, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_44$$36, "__construct", &_46, 0, &field, &_45$$36);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_44$$36, "phalcon/Mvc/Model.zep", 5018);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_OBS_NVAR(&rawValue);
						_47$$35 = zephir_array_isset_fetch(&rawValue, &rawValues, &attributeField, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_47$$35) {
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5025);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&values, &rawValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5026);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5027);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&newSnapshot, &attributeField, &rawValue, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							ZEPHIR_OBS_NVAR(&value);
							if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
								ZEPHIR_OBS_NVAR(&snapshotValue);
								_48$$38 = zephir_array_isset_fetch(&snapshotValue, &snapshot, &attributeField, 0);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (!(_48$$38)) {
									changed = 1;
								} else {
									if (Z_TYPE_P(&value) == IS_NULL) {
										changed = Z_TYPE_P(&snapshotValue) != IS_NULL;
									} else {
										if (Z_TYPE_P(&snapshotValue) == IS_NULL) {
											changed = 1;
										} else {
											ZEPHIR_OBS_NVAR(&dataType);
											_49$$44 = zephir_array_isset_fetch(&dataType, &dataTypes, &field, 0);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											if (UNEXPECTED(!(_49$$44))) {
												ZEPHIR_INIT_NVAR(&_50$$45);
												object_init_ex(&_50$$45, phalcon_mvc_model_exceptions_datatypenotdefined_ce);
												ZEPHIR_INIT_NVAR(&_51$$45);
												zephir_get_class(&_51$$45, this_ptr, 0);
												ZEPHIR_CALL_METHOD(NULL, &_50$$45, "__construct", &_52, 0, &field, &_51$$45);
												zephir_check_call_status();
												zephir_throw_exception_debug(&_50$$45, "phalcon/Mvc/Model.zep", 5051);
												ZEPHIR_MM_RESTORE();
												return;
											}
											_53$$44 = (Z_TYPE_P(&snapshotValue) == IS_OBJECT);
											if (_53$$44) {
												_53$$44 = zephir_instance_of_ev(&snapshotValue, phalcon_db_rawvalue_ce);
											}
											if (_53$$44) {
												ZEPHIR_CALL_METHOD(&_54$$46, &snapshotValue, "getValue", NULL, 0);
												zephir_check_call_status();
												ZEPHIR_CPY_WRT(&snapshotValue, &_54$$46);
											}
											ZEPHIR_CPY_WRT(&updateValue, &value);
											_55$$44 = (Z_TYPE_P(&value) == IS_OBJECT);
											if (_55$$44) {
												_55$$44 = zephir_instance_of_ev(&value, phalcon_db_rawvalue_ce);
											}
											if (_55$$44) {
												ZEPHIR_CALL_METHOD(&updateValue, &value, "getValue", NULL, 0);
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
												ZEPHIR_CALL_FUNCTION(&_56$$49, "floatval", &_29, 32, &snapshotValue);
												zephir_check_call_status();
												ZEPHIR_CALL_FUNCTION(&_57$$49, "floatval", &_29, 32, &updateValue);
												zephir_check_call_status();
												changed = !ZEPHIR_IS_IDENTICAL(&_56$$49, &_57$$49);
												goto zephir_switch_1_end;
											zephir_switch_1_clause_3: ;
											zephir_switch_1_clause_4: ;
											zephir_switch_1_clause_5: ;
											zephir_switch_1_clause_6: ;
											zephir_switch_1_clause_7: ;
											zephir_switch_1_clause_8: ;
											zephir_switch_1_clause_9: ;
												zephir_cast_to_string(&_58$$50, &snapshotValue);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_cast_to_string(&_59$$50, &updateValue);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												changed = !ZEPHIR_IS_IDENTICAL(&_58$$50, &_59$$50);
												goto zephir_switch_1_end;
											zephir_switch_1_clause_10: ;
												_60$$51 = !ZEPHIR_IS_EQUAL(&updateValue, &snapshotValue);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												changed = _60$$51;
											zephir_switch_1_end: ;

										}
									}
								}
								if (changed) {
									zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5100);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5101);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5102);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
								zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} else {
								zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
						}
					}
			}
		}
		ZEPHIR_INIT_NVAR(&field);
		if (ZEPHIR_IS_EMPTY(&fields)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1024, &snapshot);
			RETURN_MM_BOOL(1);
		}
	} else {
		if (Z_TYPE_P(&nonPrimary) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_62$$55);
			zephir_string_to_char_array(&_62$$55, &nonPrimary);
			_61$$55 = &_62$$55;
		} else {
			_61$$55 = &nonPrimary;
		}
		zephir_is_iterable(_61$$55, 0, "phalcon/Mvc/Model.zep", 5178);
		if (Z_TYPE_P(_61$$55) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_61$$55), _63$$55)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _63$$55);
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					_64$$57 = zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_64$$57))) {
						ZEPHIR_INIT_NVAR(&_66$$58);
						ZVAL_STRING(&_66$$58, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_65$$58, phalcon_support_settings_ce, "get", &_9, 0, &_66$$58);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_65$$58))) {
							ZEPHIR_INIT_NVAR(&_67$$59);
							object_init_ex(&_67$$59, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
							ZEPHIR_INIT_NVAR(&_68$$59);
							zephir_get_class(&_68$$59, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_67$$59, "__construct", &_69, 0, &field, &_68$$59);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_67$$59, "phalcon/Mvc/Model.zep", 5129);
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &field);
				}
				_70$$56 = zephir_array_key_exists(&automaticAttributes, &attributeField);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_70$$56)) {
					ZEPHIR_OBS_NVAR(&bindType);
					_71$$61 = zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_71$$61))) {
						ZEPHIR_INIT_NVAR(&_72$$62);
						object_init_ex(&_72$$62, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
						ZEPHIR_INIT_NVAR(&_73$$62);
						zephir_get_class(&_73$$62, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_72$$62, "__construct", &_74, 0, &field, &_73$$62);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_72$$62, "phalcon/Mvc/Model.zep", 5141);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&rawValue);
					_75$$61 = zephir_array_isset_fetch(&rawValue, &rawValues, &attributeField, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_75$$61) {
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5149);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&values, &rawValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5150);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5151);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_zval(&newSnapshot, &attributeField, &rawValue, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_OBS_NVAR(&value);
						if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
							_76$$64 = Z_TYPE_P(&value) == IS_STRING;
							if (_76$$64) {
								_77$$64 = zephir_array_isset_value(&defaultValues, &field);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								_76$$64 = _77$$64;
							}
							_78$$64 = _76$$64;
							if (_78$$64) {
								ZEPHIR_OBS_NVAR(&_79$$64);
								zephir_array_fetch(&_79$$64, &defaultValues, &field, PH_NOISY, "phalcon/Mvc/Model.zep", 5160);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								_78$$64 = ZEPHIR_IS_IDENTICAL(&value, &_79$$64);
							}
							_80$$64 = _78$$64;
							if (_80$$64) {
								_80$$64 = zephir_memnstr_str(&value, SL("("), "phalcon/Mvc/Model.zep", 5160);
							}
							if (_80$$64) {
								zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								continue;
							}
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5166);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5167);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5168);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5172);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&values, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5173);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5174);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _61$$55, "rewind", NULL, 0);
			zephir_check_call_status();
			_82$$55 = 1;
			while (1) {
				if (_82$$55) {
					_82$$55 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _61$$55, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_81$$55, _61$$55, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_81$$55)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, _61$$55, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						_83$$68 = zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (UNEXPECTED(!(_83$$68))) {
							ZEPHIR_INIT_NVAR(&_85$$69);
							ZVAL_STRING(&_85$$69, "orm.ignore_unknown_columns");
							ZEPHIR_CALL_CE_STATIC(&_84$$69, phalcon_support_settings_ce, "get", &_9, 0, &_85$$69);
							zephir_check_call_status();
							if (UNEXPECTED(!zephir_is_true(&_84$$69))) {
								ZEPHIR_INIT_NVAR(&_86$$70);
								object_init_ex(&_86$$70, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
								ZEPHIR_INIT_NVAR(&_87$$70);
								zephir_get_class(&_87$$70, this_ptr, 0);
								ZEPHIR_CALL_METHOD(NULL, &_86$$70, "__construct", &_88, 0, &field, &_87$$70);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_86$$70, "phalcon/Mvc/Model.zep", 5129);
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} else {
						ZEPHIR_CPY_WRT(&attributeField, &field);
					}
					_89$$67 = zephir_array_key_exists(&automaticAttributes, &attributeField);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_89$$67)) {
						ZEPHIR_OBS_NVAR(&bindType);
						_90$$72 = zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (UNEXPECTED(!(_90$$72))) {
							ZEPHIR_INIT_NVAR(&_91$$73);
							object_init_ex(&_91$$73, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
							ZEPHIR_INIT_NVAR(&_92$$73);
							zephir_get_class(&_92$$73, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_91$$73, "__construct", &_93, 0, &field, &_92$$73);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_91$$73, "phalcon/Mvc/Model.zep", 5141);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_OBS_NVAR(&rawValue);
						_94$$72 = zephir_array_isset_fetch(&rawValue, &rawValues, &attributeField, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_94$$72) {
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5149);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&values, &rawValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5150);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5151);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&newSnapshot, &attributeField, &rawValue, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							ZEPHIR_OBS_NVAR(&value);
							if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
								_95$$75 = Z_TYPE_P(&value) == IS_STRING;
								if (_95$$75) {
									_96$$75 = zephir_array_isset_value(&defaultValues, &field);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									_95$$75 = _96$$75;
								}
								_97$$75 = _95$$75;
								if (_97$$75) {
									ZEPHIR_OBS_NVAR(&_98$$75);
									zephir_array_fetch(&_98$$75, &defaultValues, &field, PH_NOISY, "phalcon/Mvc/Model.zep", 5160);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									_97$$75 = ZEPHIR_IS_IDENTICAL(&value, &_98$$75);
								}
								_99$$75 = _97$$75;
								if (_99$$75) {
									_99$$75 = zephir_memnstr_str(&value, SL("("), "phalcon/Mvc/Model.zep", 5160);
								}
								if (_99$$75) {
									zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									continue;
								}
								zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5166);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5167);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5168);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} else {
								zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5172);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&values, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5173);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5174);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_4, 1027, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueKey, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_5, 1028, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueParams, &_0);
	if (Z_TYPE_P(&uniqueParams) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&primaryKeys, metaData, "getPrimaryKeyAttributes", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (UNEXPECTED(ZEPHIR_IS_EMPTY(&primaryKeys))) {
			ZEPHIR_INIT_VAR(&_100$$80);
			object_init_ex(&_100$$80, phalcon_mvc_model_exceptions_primarykeyrequired_ce);
			ZEPHIR_INIT_VAR(&_101$$80);
			zephir_get_class(&_101$$80, this_ptr, 0);
			ZEPHIR_CALL_METHOD(NULL, &_100$$80, "__construct", NULL, 0, &_101$$80);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_100$$80, "phalcon/Mvc/Model.zep", 5199);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&uniqueParams);
		array_init(&uniqueParams);
		if (Z_TYPE_P(&primaryKeys) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_103$$79);
			zephir_string_to_char_array(&_103$$79, &primaryKeys);
			_102$$79 = &_103$$79;
		} else {
			_102$$79 = &primaryKeys;
		}
		zephir_is_iterable(_102$$79, 0, "phalcon/Mvc/Model.zep", 5224);
		if (Z_TYPE_P(_102$$79) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_102$$79), _104$$79)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _104$$79);
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					_105$$82 = zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_105$$82))) {
						ZEPHIR_INIT_NVAR(&_106$$83);
						object_init_ex(&_106$$83, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
						ZEPHIR_INIT_NVAR(&_107$$83);
						zephir_get_class(&_107$$83, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_106$$83, "__construct", &_108, 0, &field, &_107$$83);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_106$$83, "phalcon/Mvc/Model.zep", 5210);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &field);
				}
				ZEPHIR_OBS_NVAR(&value);
				if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
					zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5218);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5221);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _102$$79, "rewind", NULL, 0);
			zephir_check_call_status();
			_110$$79 = 1;
			while (1) {
				if (_110$$79) {
					_110$$79 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _102$$79, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_109$$79, _102$$79, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_109$$79)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, _102$$79, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						_111$$88 = zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (UNEXPECTED(!(_111$$88))) {
							ZEPHIR_INIT_NVAR(&_112$$89);
							object_init_ex(&_112$$89, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
							ZEPHIR_INIT_NVAR(&_113$$89);
							zephir_get_class(&_113$$89, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_112$$89, "__construct", &_114, 0, &field, &_113$$89);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_112$$89, "phalcon/Mvc/Model.zep", 5210);
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_CPY_WRT(&attributeField, &field);
					}
					ZEPHIR_OBS_NVAR(&value);
					if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
						zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5218);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						zephir_array_update_zval(&newSnapshot, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5221);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
			}
		}
		ZEPHIR_INIT_NVAR(&field);
	}
	if (Z_TYPE_P(table) == IS_ARRAY) {
		zephir_memory_observe(&_115$$93);
		zephir_array_fetch_long(&_115$$93, table, 0, PH_NOISY, "phalcon/Mvc/Model.zep", 5230);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&_116$$93);
		zephir_array_fetch_long(&_116$$93, table, 1, PH_NOISY, "phalcon/Mvc/Model.zep", 5230);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_117$$93);
		ZEPHIR_CONCAT_VSV(&_117$$93, &_115$$93, ".", &_116$$93);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(table, &_117$$93);
	}
	ZEPHIR_INIT_VAR(&_118);
	zephir_create_array(&_118, 3, 0);
	zephir_array_update_string(&_118, SL("conditions"), &uniqueKey, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_118, SL("bind"), &uniqueParams, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&_119);
	zephir_read_property_cached(&_119, this_ptr, _zephir_prop_6, 1029, PH_NOISY_CC);
	zephir_array_update_string(&_118, SL("bindTypes"), &_119, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&success, connection, "update", NULL, 0, table, &fields, &values, &_118, &bindTypes);
	zephir_check_call_status();
	if (zephir_is_true(&success)) {
		ZEPHIR_CALL_METHOD(NULL, &manager, "registerWrite", NULL, 0, this_ptr);
		zephir_check_call_status();
	}
	_120 = zephir_is_true(&success);
	if (_120) {
		ZEPHIR_CALL_METHOD(&_121, &manager, "isKeepingSnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		_120 = zephir_is_true(&_121);
	}
	_122 = _120;
	if (_122) {
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_STRING(&_2, "orm.update_snapshot_on_save");
		ZEPHIR_CALL_CE_STATIC(&_123, phalcon_support_settings_ce, "get", &_9, 0, &_2);
		zephir_check_call_status();
		_122 = zephir_is_true(&_123);
	}
	if (_122) {
		if (Z_TYPE_P(&snapshot) == IS_ARRAY) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1024, &snapshot);
			ZEPHIR_INIT_VAR(&_124$$96);
			zephir_fast_array_merge(&_124$$96, &snapshot, &newSnapshot);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1018, &_124$$96);
		} else {
			ZEPHIR_INIT_VAR(&_125$$97);
			array_init(&_125$$97);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1024, &_125$$97);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1018, &newSnapshot);
		}
	}
	RETURN_CCTOR(&success);
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
 *
 * @phpstan-param list<mixed> $arguments
 */
PHP_METHOD(Phalcon_Mvc_Model, getRelatedRecords)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments;
	zval modelName_zv, method_zv, *arguments_param = NULL, manager, relation, queryMethod, extraArgs, alias, _0, _2$$3, _3$$3, _4$$5, _5$$5, _6$$5;
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
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_INIT_VAR(&relation);
	ZVAL_BOOL(&relation, 0);
	ZEPHIR_INIT_VAR(&queryMethod);
	ZVAL_NULL(&queryMethod);
	zephir_memory_observe(&extraArgs);
	_1 = zephir_array_isset_long_fetch(&extraArgs, &arguments, 0, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1;
	if (zephir_start_with_str(&method_zv, SL("get"))) {
		ZVAL_LONG(&_2$$3, 3);
		ZEPHIR_INIT_VAR(&alias);
		zephir_substr(&alias, &method_zv, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_METHOD(&_3$$3, &manager, "getRelationByAlias", NULL, 0, &modelName_zv, &alias);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_3$$3);
		if (Z_TYPE_P(&relation) != IS_OBJECT) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getRelated", NULL, 0, &alias, &extraArgs);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_start_with_str(&method_zv, SL("count"))) {
		ZEPHIR_INIT_NVAR(&queryMethod);
		ZVAL_STRING(&queryMethod, "count");
		ZVAL_LONG(&_5$$5, 5);
		ZEPHIR_INIT_VAR(&_6$$5);
		zephir_substr(&_6$$5, &method_zv, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_METHOD(&_4$$5, &manager, "getRelationByAlias", NULL, 0, &modelName_zv, &_6$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_4$$5);
		if (Z_TYPE_P(&relation) != IS_OBJECT) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_RETURN_CALL_METHOD(&manager, "getRelationRecords", NULL, 0, &relation, this_ptr, &extraArgs, &queryMethod);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);
}

/**
 * Checks whether the current record already exists
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Mvc_Model, has)
{
	zend_bool _18$$3, _5$$8, _9$$11, _10$$7, _19$$16, _23$$19, _24$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_13 = NULL, *_15 = NULL, *_22 = NULL, *_27 = NULL, *_29 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberEmpty = 0, numberPrimary = 0;
	zval *metaData, metaData_sub, *connection, connection_sub, __$null, attributeField, bindDataTypes, columnMap, field, joinWhere, num, primaryKeys, schema, source, table, type, uniqueKey, uniqueParams, uniqueTypes, value, wherePk, _0, _34, _35, _36, _37, _1$$3, _2$$3, *_3$$3, *_4$$3, _17$$3, _6$$9, _7$$9, _14$$7, _16$$7, _11$$14, _12$$14, _20$$17, _21$$17, _28$$15, _30$$15, _25$$22, _26$$22, _31$$25, _32$$26, _33$$27, _38$$30, _39$$31;
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
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_11$$14);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_20$$17);
	ZVAL_UNDEF(&_21$$17);
	ZVAL_UNDEF(&_28$$15);
	ZVAL_UNDEF(&_30$$15);
	ZVAL_UNDEF(&_25$$22);
	ZVAL_UNDEF(&_26$$22);
	ZVAL_UNDEF(&_31$$25);
	ZVAL_UNDEF(&_32$$26);
	ZVAL_UNDEF(&_33$$27);
	ZVAL_UNDEF(&_38$$30);
	ZVAL_UNDEF(&_39$$31);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1027, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueKey, &_0);
	if (Z_TYPE_P(&uniqueKey) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&primaryKeys, metaData, "getPrimaryKeyAttributes", NULL, 0, this_ptr);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&bindDataTypes, metaData, "getBindTypes", NULL, 0, this_ptr);
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
			ZEPHIR_CALL_METHOD(&columnMap, metaData, "getColumnMap", NULL, 0, this_ptr);
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
		zephir_is_iterable(_3$$3, 0, "phalcon/Mvc/Model.zep", 5431);
		if (Z_TYPE_P(_3$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3$$3), _4$$3)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _4$$3);
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					_5$$8 = zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_5$$8))) {
						ZEPHIR_INIT_NVAR(&_6$$9);
						object_init_ex(&_6$$9, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
						ZEPHIR_INIT_NVAR(&_7$$9);
						zephir_get_class(&_7$$9, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_6$$9, "__construct", &_8, 0, &field, &_7$$9);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_6$$9, "phalcon/Mvc/Model.zep", 5392);
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
					_9$$11 = Z_TYPE_P(&value) == IS_NULL;
					if (!(_9$$11)) {
						_9$$11 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
					}
					if (_9$$11) {
						numberEmpty++;
					}
					zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5413);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5415);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					numberEmpty++;
				}
				ZEPHIR_OBS_NVAR(&type);
				_10$$7 = zephir_array_isset_fetch(&type, &bindDataTypes, &field, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_10$$7))) {
					ZEPHIR_INIT_NVAR(&_11$$14);
					object_init_ex(&_11$$14, phalcon_mvc_model_exceptions_columnnotintablecolumns_ce);
					ZEPHIR_INIT_NVAR(&_12$$14);
					zephir_get_class(&_12$$14, this_ptr, 0);
					ZEPHIR_CALL_METHOD(NULL, &_11$$14, "__construct", &_13, 0, &field, &_12$$14);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_11$$14, "phalcon/Mvc/Model.zep", 5420);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&uniqueTypes, &type, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5423);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&_14$$7, connection, "escapeIdentifier", &_15, 0, &field);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_16$$7);
				ZEPHIR_CONCAT_VS(&_16$$7, &_14$$7, " = ?");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&wherePk, &_16$$7, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5424);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _3$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			_18$$3 = 1;
			while (1) {
				if (_18$$3) {
					_18$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _3$$3, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_17$$3, _3$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_17$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, _3$$3, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						_19$$16 = zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (UNEXPECTED(!(_19$$16))) {
							ZEPHIR_INIT_NVAR(&_20$$17);
							object_init_ex(&_20$$17, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
							ZEPHIR_INIT_NVAR(&_21$$17);
							zephir_get_class(&_21$$17, this_ptr, 0);
							ZEPHIR_CALL_METHOD(NULL, &_20$$17, "__construct", &_22, 0, &field, &_21$$17);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_20$$17, "phalcon/Mvc/Model.zep", 5392);
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
						_23$$19 = Z_TYPE_P(&value) == IS_NULL;
						if (!(_23$$19)) {
							_23$$19 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
						}
						if (_23$$19) {
							numberEmpty++;
						}
						zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5413);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5415);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						numberEmpty++;
					}
					ZEPHIR_OBS_NVAR(&type);
					_24$$15 = zephir_array_isset_fetch(&type, &bindDataTypes, &field, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_24$$15))) {
						ZEPHIR_INIT_NVAR(&_25$$22);
						object_init_ex(&_25$$22, phalcon_mvc_model_exceptions_columnnotintablecolumns_ce);
						ZEPHIR_INIT_NVAR(&_26$$22);
						zephir_get_class(&_26$$22, this_ptr, 0);
						ZEPHIR_CALL_METHOD(NULL, &_25$$22, "__construct", &_27, 0, &field, &_26$$22);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_25$$22, "phalcon/Mvc/Model.zep", 5420);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&uniqueTypes, &type, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5423);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_28$$15, connection, "escapeIdentifier", &_29, 0, &field);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_30$$15);
					ZEPHIR_CONCAT_VS(&_30$$15, &_28$$15, " = ?");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&wherePk, &_30$$15, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5424);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&field);
		if (numberPrimary == numberEmpty) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(&joinWhere);
		zephir_fast_join_str(&joinWhere, SL(" AND "), &wherePk);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1027, &joinWhere);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1028, &uniqueParams);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1029, &uniqueTypes);
		ZEPHIR_CPY_WRT(&uniqueKey, &joinWhere);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_3, 1017, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_BOOL(1);
	}
	if (Z_TYPE_P(&uniqueKey) == IS_NULL) {
		zephir_read_property_cached(&_31$$25, this_ptr, _zephir_prop_0, 1027, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&uniqueKey, &_31$$25);
	}
	if (Z_TYPE_P(&uniqueParams) == IS_NULL) {
		zephir_read_property_cached(&_32$$26, this_ptr, _zephir_prop_1, 1028, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&uniqueParams, &_32$$26);
	}
	if (Z_TYPE_P(&uniqueTypes) == IS_NULL) {
		zephir_read_property_cached(&_33$$27, this_ptr, _zephir_prop_2, 1029, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&uniqueTypes, &_33$$27);
	}
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getSchema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getSource", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	ZEPHIR_CALL_METHOD(&_34, connection, "escapeIdentifier", NULL, 0, &table);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_35);
	ZEPHIR_CONCAT_SVSV(&_35, "SELECT COUNT(*) \"rowcount\" FROM ", &_34, " WHERE ", &uniqueKey);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZVAL_NULL(&_36);
	ZEPHIR_CALL_METHOD(&num, connection, "fetchOne", NULL, 0, &_35, &_36, &uniqueParams, &uniqueTypes);
	zephir_check_call_status();
	zephir_memory_observe(&_37);
	zephir_array_fetch_string(&_37, &num, SL("rowcount"), PH_NOISY, "phalcon/Mvc/Model.zep", 5485);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_is_true(&_37)) {
		ZVAL_UNDEF(&_38$$30);
		ZVAL_LONG(&_38$$30, 0);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1017, &_38$$30);
		RETURN_MM_BOOL(1);
	} else {
		ZVAL_UNDEF(&_39$$31);
		ZVAL_LONG(&_39$$31, 1);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1017, &_39$$31);
	}
	RETURN_MM_BOOL(0);
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
 *
 * @phpstan-param mvc_relation_options $options
 * @phpstan-param mvc_relation_fields $referencedFields
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addHasMany", NULL, 0, this_ptr, fields, &referenceModel_zv, referencedFields, &options);
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
 *
 * @phpstan-param mvc_relation_options $options
 * @phpstan-param mvc_relation_fields $intermediateFields
 * @phpstan-param mvc_relation_fields $intermediateReferencedFields
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addHasManyToMany", NULL, 0, this_ptr, fields, &intermediateModel_zv, intermediateFields, intermediateReferencedFields, &referenceModel_zv, referencedFields, &options);
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
 *
 * @phpstan-param mvc_relation_options $options
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addHasOne", NULL, 0, this_ptr, fields, &referenceModel_zv, referencedFields, &options);
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
 *
 * @phpstan-param mvc_relation_options $options
 * @phpstan-param mvc_relation_fields $intermediateFields
 * @phpstan-param mvc_relation_fields $intermediateReferencedFields
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addHasOneThrough", NULL, 0, this_ptr, fields, &intermediateModel_zv, intermediateFields, intermediateReferencedFields, &referenceModel_zv, referencedFields, &options);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	if (keepSnapshot) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "keepSnapshots", NULL, 0, this_ptr, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Check for, and attempt to use, possible setter.
 */
PHP_METHOD(Phalcon_Mvc_Model, possibleSetter)
{
	zend_bool _1;
	zval localMethods;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval property_zv, *value, value_sub, possibleSetter, _0, _2, _3;
	zend_string *property = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property_zv);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&possibleSetter);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!((zephir_method_exists(this_ptr, &possibleSetter)  == SUCCESS))) {
		RETURN_MM_BOOL(0);
	}
	_1 = zephir_array_isset_value(&localMethods, &possibleSetter);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		RETURN_MM_BOOL(0);
	}

	/* try_start_1: */

		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &possibleSetter, NULL, 0, value);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_OBJ(&_2, EG(exception));
		Z_ADDREF_P(&_2);
		ZEPHIR_INIT_VAR(&_3);
		if (zephir_is_instance_of(&_2, SL("TypeError"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&_3, &_2);
			zephir_update_property_zval_zval(this_ptr, &property_zv, value);
		} else {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
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
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *success_param = NULL, *exists_param = NULL, _0$$4, _2$$5;
	zend_bool success, exists;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2$$5);
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
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireEvent", &_1, 0, &_0$$4);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_2$$5);
			ZVAL_STRING(&_2$$5, "afterCreate");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireEvent", &_1, 0, &_2$$5);
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
 *
 * @phpstan-param CollectionInterface<mixed> $visited
 */
PHP_METHOD(Phalcon_Mvc_Model, postSaveRelatedRecords)
{
	zval _28$$13, _47$$19, _52$$20, _83$$34, _98$$39, _103$$40, _134$$54, _152$$60, _170$$66, _237$$93, _255$$99, _260$$100, _291$$114, _306$$119, _311$$120, _342$$134, _360$$140, _378$$146;
	zend_string *_5;
	zend_ulong _4;
	zval conditions, placeholders, loopConditions, loopPlaceholders, keptKeys, _56$$15, _107$$35, _138$$55, _264$$95, _315$$115, _346$$135;
	zend_bool nesting = 0, isThrough = 0, doSync = 0, _213, _9$$4, _18$$9, _20$$9, _85$$9, _135$$9, _21$$12, _58$$15, _40$$18, _60$$23, _65$$26, _79$$31, _109$$35, _91$$38, _111$$43, _116$$46, _130$$51, _159$$55, _148$$57, _153$$56, _154$$56, _166$$63, _171$$62, _172$$62, _187$$69, _179$$70, _188$$73, _203$$76, _217$$84, _227$$89, _229$$89, _293$$89, _343$$89, _230$$92, _266$$95, _248$$98, _268$$103, _273$$106, _287$$111, _317$$115, _299$$118, _319$$123, _324$$126, _338$$131, _367$$135, _356$$137, _361$$136, _362$$136, _374$$143, _379$$142, _380$$142, _395$$149, _387$$150, _396$$153, _411$$156;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_11 = NULL, *_13 = NULL, *_35 = NULL, *_37 = NULL, *_39 = NULL, *_55 = NULL, *_59 = NULL, *_72 = NULL, *_88 = NULL, *_90 = NULL, *_106 = NULL, *_110 = NULL, *_123 = NULL, *_137 = NULL, *_157 = NULL, *_175 = NULL, *_185 = NULL, *_194 = NULL, *_201 = NULL, *_207 = NULL, *_209 = NULL, *_211 = NULL, *_215 = NULL, *_219 = NULL, *_221 = NULL, *_245 = NULL, *_247 = NULL, *_263 = NULL, *_267 = NULL, *_280 = NULL, *_296 = NULL, *_298 = NULL, *_314 = NULL, *_318 = NULL, *_331 = NULL, *_345 = NULL, *_365 = NULL, *_383 = NULL, *_393 = NULL, *_402 = NULL, *_409 = NULL, *_415 = NULL, *_417 = NULL, *_419 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, referencedFieldsCount = 0, i = 0, j = 0, t = 0, h = 0, columnCount, _22$$12, _23$$12, _41$$18, _42$$18, _61$$23, _62$$23, _66$$26, _67$$26, _92$$38, _93$$38, _112$$43, _113$$43, _117$$46, _118$$46, _180$$70, _181$$70, _189$$73, _190$$73, _231$$92, _232$$92, _249$$98, _250$$98, _269$$103, _270$$103, _274$$106, _275$$106, _300$$118, _301$$118, _320$$123, _321$$123, _325$$126, _326$$126, _388$$150, _389$$150, _397$$153, _398$$153;
	zval *connection, connection_sub, *related, related_sub, *visited, visited_sub, __$true, className, manager, relation, name, record, columns, referencedModel, referencedFields, relatedRecords, recordAfter, intermediateModel, intermediateFields, intermediateModelName, intermediateReferencedFields, existingIntermediateModel, columnA, columnB, existingRecords, existingRecord, keepKey, override, _0, *_1, _2, *_3, _212, _420, _6$$3, _8$$4, _14$$4, _10$$6, _12$$6, _15$$9, _16$$9, _17$$9, _19$$9, *_32$$9, *_33$$9, _84$$9, _24$$13, _25$$13, _26$$13, _27$$13, _29$$13, _30$$14, _31$$14, _34$$15, _38$$15, _54$$15, _57$$15, _70$$15, _36$$16, _43$$19, _44$$19, _45$$19, _46$$19, _48$$19, _49$$20, _50$$20, _51$$20, _53$$20, _63$$24, _64$$25, _68$$27, _69$$28, _71$$29, *_73$$31, _74$$31, *_75$$31, _78$$31, _76$$32, _77$$32, _80$$33, _81$$33, _82$$34, _86$$35, _89$$35, _105$$35, _108$$35, _121$$35, _87$$36, _94$$39, _95$$39, _96$$39, _97$$39, _99$$39, _100$$40, _101$$40, _102$$40, _104$$40, _114$$44, _115$$45, _119$$47, _120$$48, _122$$49, *_124$$51, _125$$51, *_126$$51, _129$$51, _127$$52, _128$$52, _131$$53, _132$$53, _133$$54, _136$$55, _139$$55, *_140$$55, *_141$$55, _158$$55, *_142$$57, _143$$57, *_144$$57, _147$$57, _145$$58, _146$$58, _149$$59, _150$$59, _151$$60, _155$$56, _156$$61, *_160$$63, _161$$63, *_162$$63, _165$$63, _163$$64, _164$$64, _167$$65, _168$$65, _169$$66, _173$$62, _174$$67, *_176$$69, _177$$69, *_178$$69, _186$$69, _183$$70, _182$$71, _184$$72, _192$$73, _191$$74, _193$$75, *_195$$76, _196$$76, *_197$$76, _202$$76, _198$$77, _199$$77, _200$$78, _204$$79, _205$$79, _206$$80, _208$$82, _210$$82, _214$$83, _216$$84, _223$$84, _218$$86, _220$$86, _222$$87, _224$$89, _225$$89, _226$$89, _228$$89, *_241$$89, *_242$$89, _292$$89, _233$$93, _234$$93, _235$$93, _236$$93, _238$$93, _239$$94, _240$$94, _243$$95, _246$$95, _262$$95, _265$$95, _278$$95, _244$$96, _251$$99, _252$$99, _253$$99, _254$$99, _256$$99, _257$$100, _258$$100, _259$$100, _261$$100, _271$$104, _272$$105, _276$$107, _277$$108, _279$$109, *_281$$111, _282$$111, *_283$$111, _286$$111, _284$$112, _285$$112, _288$$113, _289$$113, _290$$114, _294$$115, _297$$115, _313$$115, _316$$115, _329$$115, _295$$116, _302$$119, _303$$119, _304$$119, _305$$119, _307$$119, _308$$120, _309$$120, _310$$120, _312$$120, _322$$124, _323$$125, _327$$127, _328$$128, _330$$129, *_332$$131, _333$$131, *_334$$131, _337$$131, _335$$132, _336$$132, _339$$133, _340$$133, _341$$134, _344$$135, _347$$135, *_348$$135, *_349$$135, _366$$135, *_350$$137, _351$$137, *_352$$137, _355$$137, _353$$138, _354$$138, _357$$139, _358$$139, _359$$140, _363$$136, _364$$141, *_368$$143, _369$$143, *_370$$143, _373$$143, _371$$144, _372$$144, _375$$145, _376$$145, _377$$146, _381$$142, _382$$147, *_384$$149, _385$$149, *_386$$149, _394$$149, _391$$150, _390$$151, _392$$152, _400$$153, _399$$154, _401$$155, *_403$$156, _404$$156, *_405$$156, _410$$156, _406$$157, _407$$157, _408$$158, _412$$159, _413$$159, _414$$160, _416$$162, _418$$162;
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
	ZVAL_UNDEF(&_212);
	ZVAL_UNDEF(&_420);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_84$$9);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_26$$13);
	ZVAL_UNDEF(&_27$$13);
	ZVAL_UNDEF(&_29$$13);
	ZVAL_UNDEF(&_30$$14);
	ZVAL_UNDEF(&_31$$14);
	ZVAL_UNDEF(&_34$$15);
	ZVAL_UNDEF(&_38$$15);
	ZVAL_UNDEF(&_54$$15);
	ZVAL_UNDEF(&_57$$15);
	ZVAL_UNDEF(&_70$$15);
	ZVAL_UNDEF(&_36$$16);
	ZVAL_UNDEF(&_43$$19);
	ZVAL_UNDEF(&_44$$19);
	ZVAL_UNDEF(&_45$$19);
	ZVAL_UNDEF(&_46$$19);
	ZVAL_UNDEF(&_48$$19);
	ZVAL_UNDEF(&_49$$20);
	ZVAL_UNDEF(&_50$$20);
	ZVAL_UNDEF(&_51$$20);
	ZVAL_UNDEF(&_53$$20);
	ZVAL_UNDEF(&_63$$24);
	ZVAL_UNDEF(&_64$$25);
	ZVAL_UNDEF(&_68$$27);
	ZVAL_UNDEF(&_69$$28);
	ZVAL_UNDEF(&_71$$29);
	ZVAL_UNDEF(&_74$$31);
	ZVAL_UNDEF(&_78$$31);
	ZVAL_UNDEF(&_76$$32);
	ZVAL_UNDEF(&_77$$32);
	ZVAL_UNDEF(&_80$$33);
	ZVAL_UNDEF(&_81$$33);
	ZVAL_UNDEF(&_82$$34);
	ZVAL_UNDEF(&_86$$35);
	ZVAL_UNDEF(&_89$$35);
	ZVAL_UNDEF(&_105$$35);
	ZVAL_UNDEF(&_108$$35);
	ZVAL_UNDEF(&_121$$35);
	ZVAL_UNDEF(&_87$$36);
	ZVAL_UNDEF(&_94$$39);
	ZVAL_UNDEF(&_95$$39);
	ZVAL_UNDEF(&_96$$39);
	ZVAL_UNDEF(&_97$$39);
	ZVAL_UNDEF(&_99$$39);
	ZVAL_UNDEF(&_100$$40);
	ZVAL_UNDEF(&_101$$40);
	ZVAL_UNDEF(&_102$$40);
	ZVAL_UNDEF(&_104$$40);
	ZVAL_UNDEF(&_114$$44);
	ZVAL_UNDEF(&_115$$45);
	ZVAL_UNDEF(&_119$$47);
	ZVAL_UNDEF(&_120$$48);
	ZVAL_UNDEF(&_122$$49);
	ZVAL_UNDEF(&_125$$51);
	ZVAL_UNDEF(&_129$$51);
	ZVAL_UNDEF(&_127$$52);
	ZVAL_UNDEF(&_128$$52);
	ZVAL_UNDEF(&_131$$53);
	ZVAL_UNDEF(&_132$$53);
	ZVAL_UNDEF(&_133$$54);
	ZVAL_UNDEF(&_136$$55);
	ZVAL_UNDEF(&_139$$55);
	ZVAL_UNDEF(&_158$$55);
	ZVAL_UNDEF(&_143$$57);
	ZVAL_UNDEF(&_147$$57);
	ZVAL_UNDEF(&_145$$58);
	ZVAL_UNDEF(&_146$$58);
	ZVAL_UNDEF(&_149$$59);
	ZVAL_UNDEF(&_150$$59);
	ZVAL_UNDEF(&_151$$60);
	ZVAL_UNDEF(&_155$$56);
	ZVAL_UNDEF(&_156$$61);
	ZVAL_UNDEF(&_161$$63);
	ZVAL_UNDEF(&_165$$63);
	ZVAL_UNDEF(&_163$$64);
	ZVAL_UNDEF(&_164$$64);
	ZVAL_UNDEF(&_167$$65);
	ZVAL_UNDEF(&_168$$65);
	ZVAL_UNDEF(&_169$$66);
	ZVAL_UNDEF(&_173$$62);
	ZVAL_UNDEF(&_174$$67);
	ZVAL_UNDEF(&_177$$69);
	ZVAL_UNDEF(&_186$$69);
	ZVAL_UNDEF(&_183$$70);
	ZVAL_UNDEF(&_182$$71);
	ZVAL_UNDEF(&_184$$72);
	ZVAL_UNDEF(&_192$$73);
	ZVAL_UNDEF(&_191$$74);
	ZVAL_UNDEF(&_193$$75);
	ZVAL_UNDEF(&_196$$76);
	ZVAL_UNDEF(&_202$$76);
	ZVAL_UNDEF(&_198$$77);
	ZVAL_UNDEF(&_199$$77);
	ZVAL_UNDEF(&_200$$78);
	ZVAL_UNDEF(&_204$$79);
	ZVAL_UNDEF(&_205$$79);
	ZVAL_UNDEF(&_206$$80);
	ZVAL_UNDEF(&_208$$82);
	ZVAL_UNDEF(&_210$$82);
	ZVAL_UNDEF(&_214$$83);
	ZVAL_UNDEF(&_216$$84);
	ZVAL_UNDEF(&_223$$84);
	ZVAL_UNDEF(&_218$$86);
	ZVAL_UNDEF(&_220$$86);
	ZVAL_UNDEF(&_222$$87);
	ZVAL_UNDEF(&_224$$89);
	ZVAL_UNDEF(&_225$$89);
	ZVAL_UNDEF(&_226$$89);
	ZVAL_UNDEF(&_228$$89);
	ZVAL_UNDEF(&_292$$89);
	ZVAL_UNDEF(&_233$$93);
	ZVAL_UNDEF(&_234$$93);
	ZVAL_UNDEF(&_235$$93);
	ZVAL_UNDEF(&_236$$93);
	ZVAL_UNDEF(&_238$$93);
	ZVAL_UNDEF(&_239$$94);
	ZVAL_UNDEF(&_240$$94);
	ZVAL_UNDEF(&_243$$95);
	ZVAL_UNDEF(&_246$$95);
	ZVAL_UNDEF(&_262$$95);
	ZVAL_UNDEF(&_265$$95);
	ZVAL_UNDEF(&_278$$95);
	ZVAL_UNDEF(&_244$$96);
	ZVAL_UNDEF(&_251$$99);
	ZVAL_UNDEF(&_252$$99);
	ZVAL_UNDEF(&_253$$99);
	ZVAL_UNDEF(&_254$$99);
	ZVAL_UNDEF(&_256$$99);
	ZVAL_UNDEF(&_257$$100);
	ZVAL_UNDEF(&_258$$100);
	ZVAL_UNDEF(&_259$$100);
	ZVAL_UNDEF(&_261$$100);
	ZVAL_UNDEF(&_271$$104);
	ZVAL_UNDEF(&_272$$105);
	ZVAL_UNDEF(&_276$$107);
	ZVAL_UNDEF(&_277$$108);
	ZVAL_UNDEF(&_279$$109);
	ZVAL_UNDEF(&_282$$111);
	ZVAL_UNDEF(&_286$$111);
	ZVAL_UNDEF(&_284$$112);
	ZVAL_UNDEF(&_285$$112);
	ZVAL_UNDEF(&_288$$113);
	ZVAL_UNDEF(&_289$$113);
	ZVAL_UNDEF(&_290$$114);
	ZVAL_UNDEF(&_294$$115);
	ZVAL_UNDEF(&_297$$115);
	ZVAL_UNDEF(&_313$$115);
	ZVAL_UNDEF(&_316$$115);
	ZVAL_UNDEF(&_329$$115);
	ZVAL_UNDEF(&_295$$116);
	ZVAL_UNDEF(&_302$$119);
	ZVAL_UNDEF(&_303$$119);
	ZVAL_UNDEF(&_304$$119);
	ZVAL_UNDEF(&_305$$119);
	ZVAL_UNDEF(&_307$$119);
	ZVAL_UNDEF(&_308$$120);
	ZVAL_UNDEF(&_309$$120);
	ZVAL_UNDEF(&_310$$120);
	ZVAL_UNDEF(&_312$$120);
	ZVAL_UNDEF(&_322$$124);
	ZVAL_UNDEF(&_323$$125);
	ZVAL_UNDEF(&_327$$127);
	ZVAL_UNDEF(&_328$$128);
	ZVAL_UNDEF(&_330$$129);
	ZVAL_UNDEF(&_333$$131);
	ZVAL_UNDEF(&_337$$131);
	ZVAL_UNDEF(&_335$$132);
	ZVAL_UNDEF(&_336$$132);
	ZVAL_UNDEF(&_339$$133);
	ZVAL_UNDEF(&_340$$133);
	ZVAL_UNDEF(&_341$$134);
	ZVAL_UNDEF(&_344$$135);
	ZVAL_UNDEF(&_347$$135);
	ZVAL_UNDEF(&_366$$135);
	ZVAL_UNDEF(&_351$$137);
	ZVAL_UNDEF(&_355$$137);
	ZVAL_UNDEF(&_353$$138);
	ZVAL_UNDEF(&_354$$138);
	ZVAL_UNDEF(&_357$$139);
	ZVAL_UNDEF(&_358$$139);
	ZVAL_UNDEF(&_359$$140);
	ZVAL_UNDEF(&_363$$136);
	ZVAL_UNDEF(&_364$$141);
	ZVAL_UNDEF(&_369$$143);
	ZVAL_UNDEF(&_373$$143);
	ZVAL_UNDEF(&_371$$144);
	ZVAL_UNDEF(&_372$$144);
	ZVAL_UNDEF(&_375$$145);
	ZVAL_UNDEF(&_376$$145);
	ZVAL_UNDEF(&_377$$146);
	ZVAL_UNDEF(&_381$$142);
	ZVAL_UNDEF(&_382$$147);
	ZVAL_UNDEF(&_385$$149);
	ZVAL_UNDEF(&_394$$149);
	ZVAL_UNDEF(&_391$$150);
	ZVAL_UNDEF(&_390$$151);
	ZVAL_UNDEF(&_392$$152);
	ZVAL_UNDEF(&_400$$153);
	ZVAL_UNDEF(&_399$$154);
	ZVAL_UNDEF(&_401$$155);
	ZVAL_UNDEF(&_404$$156);
	ZVAL_UNDEF(&_410$$156);
	ZVAL_UNDEF(&_406$$157);
	ZVAL_UNDEF(&_407$$157);
	ZVAL_UNDEF(&_408$$158);
	ZVAL_UNDEF(&_412$$159);
	ZVAL_UNDEF(&_413$$159);
	ZVAL_UNDEF(&_414$$160);
	ZVAL_UNDEF(&_416$$162);
	ZVAL_UNDEF(&_418$$162);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&placeholders);
	ZVAL_UNDEF(&loopConditions);
	ZVAL_UNDEF(&loopPlaceholders);
	ZVAL_UNDEF(&keptKeys);
	ZVAL_UNDEF(&_56$$15);
	ZVAL_UNDEF(&_107$$35);
	ZVAL_UNDEF(&_138$$55);
	ZVAL_UNDEF(&_264$$95);
	ZVAL_UNDEF(&_315$$115);
	ZVAL_UNDEF(&_346$$135);
	ZVAL_UNDEF(&_28$$13);
	ZVAL_UNDEF(&_47$$19);
	ZVAL_UNDEF(&_52$$20);
	ZVAL_UNDEF(&_83$$34);
	ZVAL_UNDEF(&_98$$39);
	ZVAL_UNDEF(&_103$$40);
	ZVAL_UNDEF(&_134$$54);
	ZVAL_UNDEF(&_152$$60);
	ZVAL_UNDEF(&_170$$66);
	ZVAL_UNDEF(&_237$$93);
	ZVAL_UNDEF(&_255$$99);
	ZVAL_UNDEF(&_260$$100);
	ZVAL_UNDEF(&_291$$114);
	ZVAL_UNDEF(&_306$$119);
	ZVAL_UNDEF(&_311$$120);
	ZVAL_UNDEF(&_342$$134);
	ZVAL_UNDEF(&_360$$140);
	ZVAL_UNDEF(&_378$$146);
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getModelsManager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_0);
	if (Z_TYPE_P(related) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, related);
		_1 = &_2;
	} else {
		_1 = related;
	}
	zephir_is_iterable(_1, 0, "phalcon/Mvc/Model.zep", 6146);
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
			ZEPHIR_CALL_METHOD(&_6$$3, &manager, "getRelationByAlias", &_7, 0, &className, &name);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&relation, &_6$$3);
			if (Z_TYPE_P(&relation) == IS_OBJECT) {
				ZEPHIR_CALL_METHOD(&_8$$4, &relation, "getType", NULL, 0);
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
					zephir_throw_exception_debug(&_12$$6, "phalcon/Mvc/Model.zep", 5866);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&columns, &relation, "getFields", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedModel, &relation, "getReferencedModel", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getReferencedFields", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&record) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&relatedRecords);
					zephir_create_array(&relatedRecords, 1, 0);
					zephir_array_fast_append(&relatedRecords, &record);
				} else {
					ZEPHIR_CPY_WRT(&relatedRecords, &record);
				}
				ZEPHIR_CALL_METHOD(&_14$$4, &relation, "isThrough", NULL, 0);
				zephir_check_call_status();
				isThrough = zephir_get_boolval(&_14$$4);
				if (isThrough) {
					ZEPHIR_CALL_METHOD(&intermediateModelName, &relation, "getIntermediateModel", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&intermediateFields, &relation, "getIntermediateFields", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&intermediateReferencedFields, &relation, "getIntermediateReferencedFields", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&placeholders);
					array_init(&placeholders);
					ZEPHIR_INIT_NVAR(&conditions);
					array_init(&conditions);
					ZEPHIR_INIT_NVAR(&keptKeys);
					array_init(&keptKeys);
					ZEPHIR_INIT_NVAR(&_16$$9);
					ZVAL_STRING(&_16$$9, "sync");
					ZEPHIR_CALL_METHOD(&_15$$9, &relation, "getOption", NULL, 0, &_16$$9);
					zephir_check_call_status();
					doSync = zephir_get_boolval(&_15$$9);
					ZEPHIR_OBS_NVAR(&override);
					zephir_read_property_cached(&_17$$9, this_ptr, _zephir_prop_0, 1023, PH_NOISY_CC | PH_READONLY);
					_18$$9 = zephir_array_isset_fetch(&override, &_17$$9, &name, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_18$$9) {
						doSync = zephir_get_boolval(&override);
					} else {
						ZEPHIR_OBS_NVAR(&override);
						zephir_read_property_cached(&_19$$9, this_ptr, _zephir_prop_0, 1023, PH_NOISY_CC | PH_READONLY);
						_20$$9 = zephir_array_isset_string_fetch(&override, &_19$$9, SL("*"), 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_20$$9) {
							doSync = zephir_get_boolval(&override);
						}
					}
					if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
						columnCount = (zephir_fast_count_int(&columns) - 1);
						_23$$12 = columnCount;
						_22$$12 = 0;
						_21$$12 = 0;
						if (_22$$12 <= _23$$12) {
							while (1) {
								if (_21$$12) {
									_22$$12++;
									if (!(_22$$12 <= _23$$12)) {
										break;
									}
								} else {
									_21$$12 = 1;
								}
								i = _22$$12;
								ZEPHIR_OBS_NVAR(&columnA);
								zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5913);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&_24$$13);
								zephir_array_fetch_long(&_24$$13, &intermediateFields, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5914);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_INIT_NVAR(&_25$$13);
								ZVAL_LONG(&_25$$13, i);
								ZEPHIR_INIT_NVAR(&_26$$13);
								ZEPHIR_CONCAT_SVSVS(&_26$$13, "[", &_24$$13, "] = :APR", &_25$$13, ":");
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&conditions, &_26$$13, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5914);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_INIT_NVAR(&_27$$13);
								ZVAL_LONG(&_27$$13, i);
								ZEPHIR_INIT_NVAR(&_28$$13);
								ZEPHIR_CONCAT_SV(&_28$$13, "APR", &_27$$13);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&_29$$13);
								zephir_read_property_zval(&_29$$13, this_ptr, &columnA, PH_NOISY_CC);
								zephir_array_update_zval(&placeholders, &_28$$13, &_29$$13, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
						}
						i = (columnCount + 1);
					} else {
						ZEPHIR_INIT_NVAR(&_30$$14);
						ZEPHIR_CONCAT_SVS(&_30$$14, "[", &intermediateFields, "] = :APR0:");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&conditions, &_30$$14, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5919);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_OBS_NVAR(&_31$$14);
						zephir_read_property_zval(&_31$$14, this_ptr, &columns, PH_NOISY_CC);
						zephir_array_update_string(&placeholders, SL("APR0"), &_31$$14, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						i = 1;
					}
					if (Z_TYPE_P(&relatedRecords) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_16$$9);
						zephir_string_to_char_array(&_16$$9, &relatedRecords);
						_32$$9 = &_16$$9;
					} else {
						_32$$9 = &relatedRecords;
					}
					zephir_is_iterable(_32$$9, 0, "phalcon/Mvc/Model.zep", 6049);
					if (Z_TYPE_P(_32$$9) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_32$$9), _33$$9)
						{
							ZEPHIR_INIT_NVAR(&recordAfter);
							ZVAL_COPY(&recordAfter, _33$$9);
							ZEPHIR_CALL_METHOD(&_34$$15, &recordAfter, "doSave", NULL, 0, visited);
							zephir_check_call_status();
							if (!(zephir_is_true(&_34$$15))) {
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessagesFrom", &_35, 0, &recordAfter);
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
							if (UNEXPECTED(Z_TYPE_P(&conditions) != IS_ARRAY)) {
								zephir_throw_variable_type_error(&conditions, "loopConditions", "array");
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CPY_WRT(&loopConditions, &conditions);
							if (UNEXPECTED(Z_TYPE_P(&placeholders) != IS_ARRAY)) {
								zephir_throw_variable_type_error(&placeholders, "loopPlaceholders", "array");
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CPY_WRT(&loopPlaceholders, &placeholders);
							ZEPHIR_CALL_METHOD(&_38$$15, &relation, "getType", &_39, 0);
							zephir_check_call_status();
							if (ZEPHIR_IS_LONG_IDENTICAL(&_38$$15, 4)) {
								if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
									referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
									_42$$18 = referencedFieldsCount;
									_41$$18 = 0;
									_40$$18 = 0;
									if (_41$$18 <= _42$$18) {
										while (1) {
											if (_40$$18) {
												_41$$18++;
												if (!(_41$$18 <= _42$$18)) {
													break;
												}
											} else {
												_40$$18 = 1;
											}
											j = _41$$18;
											ZEPHIR_OBS_NVAR(&columnA);
											zephir_array_fetch_long(&columnA, &referencedFields, j, PH_NOISY, "phalcon/Mvc/Model.zep", 5954);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											t = (j + i);
											ZEPHIR_OBS_NVAR(&_43$$19);
											zephir_array_fetch_long(&_43$$19, &intermediateReferencedFields, j, PH_NOISY, "phalcon/Mvc/Model.zep", 5956);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_INIT_NVAR(&_44$$19);
											ZVAL_LONG(&_44$$19, t);
											ZEPHIR_INIT_NVAR(&_45$$19);
											ZEPHIR_CONCAT_SVSVS(&_45$$19, "[", &_43$$19, "] = :APR", &_44$$19, ":");
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_append(&loopConditions, &_45$$19, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5956);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_INIT_NVAR(&_46$$19);
											ZVAL_LONG(&_46$$19, t);
											ZEPHIR_INIT_NVAR(&_47$$19);
											ZEPHIR_CONCAT_SV(&_47$$19, "APR", &_46$$19);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_OBS_NVAR(&_48$$19);
											zephir_read_property_zval(&_48$$19, &recordAfter, &columnA, PH_NOISY_CC);
											zephir_array_update_zval(&loopPlaceholders, &_47$$19, &_48$$19, PH_COPY | PH_SEPARATE);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
										}
									}
								} else {
									ZEPHIR_INIT_NVAR(&_49$$20);
									ZVAL_LONG(&_49$$20, i);
									ZEPHIR_INIT_NVAR(&_50$$20);
									ZEPHIR_CONCAT_SVSVS(&_50$$20, "[", &intermediateReferencedFields, "] = :APR", &_49$$20, ":");
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&loopConditions, &_50$$20, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5960);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_INIT_NVAR(&_51$$20);
									ZVAL_LONG(&_51$$20, i);
									ZEPHIR_INIT_NVAR(&_52$$20);
									ZEPHIR_CONCAT_SV(&_52$$20, "APR", &_51$$20);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_OBS_NVAR(&_53$$20);
									zephir_read_property_zval(&_53$$20, &recordAfter, &referencedFields, PH_NOISY_CC);
									zephir_array_update_zval(&loopPlaceholders, &_52$$20, &_53$$20, PH_COPY | PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
							}
							ZEPHIR_CALL_METHOD(&_54$$15, &manager, "load", &_55, 0, &intermediateModelName);
							zephir_check_call_status();
							ZEPHIR_CPY_WRT(&intermediateModel, &_54$$15);
							ZEPHIR_INIT_NVAR(&_56$$15);
							zephir_create_array(&_56$$15, 2, 0);
							ZEPHIR_INIT_NVAR(&_57$$15);
							zephir_fast_join_str(&_57$$15, SL(" AND "), &loopConditions);
							zephir_array_fast_append(&_56$$15, &_57$$15);
							zephir_array_update_string(&_56$$15, SL("bind"), &loopPlaceholders, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(&existingIntermediateModel, &intermediateModel, "findFirst", NULL, 0, &_56$$15);
							zephir_check_call_status();
							if (zephir_is_true(&existingIntermediateModel)) {
								ZEPHIR_CPY_WRT(&intermediateModel, &existingIntermediateModel);
							}
							_58$$15 = !zephir_is_true(&existingIntermediateModel);
							if (!(_58$$15)) {
								ZEPHIR_CALL_METHOD(&_54$$15, &relation, "getType", &_59, 0);
								zephir_check_call_status();
								_58$$15 = ZEPHIR_IS_LONG_IDENTICAL(&_54$$15, 3);
							}
							if (_58$$15) {
								if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
									_62$$23 = columnCount;
									_61$$23 = 0;
									_60$$23 = 0;
									if (_61$$23 <= _62$$23) {
										while (1) {
											if (_60$$23) {
												_61$$23++;
												if (!(_61$$23 <= _62$$23)) {
													break;
												}
											} else {
												_60$$23 = 1;
											}
											h = _61$$23;
											ZEPHIR_OBS_NVAR(&columnA);
											zephir_array_fetch_long(&columnA, &columns, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5991);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_OBS_NVAR(&columnB);
											zephir_array_fetch_long(&columnB, &intermediateFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5992);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_OBS_NVAR(&_63$$24);
											zephir_read_property_zval(&_63$$24, this_ptr, &columnA, PH_NOISY_CC);
											zephir_update_property_zval_zval(&intermediateModel, &columnB, &_63$$24);
										}
									}
								} else {
									ZEPHIR_OBS_NVAR(&_64$$25);
									zephir_read_property_zval(&_64$$25, this_ptr, &columns, PH_NOISY_CC);
									zephir_update_property_zval_zval(&intermediateModel, &intermediateFields, &_64$$25);
								}
								if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
									referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
									_67$$26 = referencedFieldsCount;
									_66$$26 = 0;
									_65$$26 = 0;
									if (_66$$26 <= _67$$26) {
										while (1) {
											if (_65$$26) {
												_66$$26++;
												if (!(_66$$26 <= _67$$26)) {
													break;
												}
											} else {
												_65$$26 = 1;
											}
											h = _66$$26;
											ZEPHIR_OBS_NVAR(&columnA);
											zephir_array_fetch_long(&columnA, &referencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 6001);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_OBS_NVAR(&columnB);
											zephir_array_fetch_long(&columnB, &intermediateReferencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 6002);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_OBS_NVAR(&_68$$27);
											zephir_read_property_zval(&_68$$27, &recordAfter, &columnA, PH_NOISY_CC);
											zephir_update_property_zval_zval(&intermediateModel, &columnB, &_68$$27);
										}
									}
								} else {
									ZEPHIR_OBS_NVAR(&_69$$28);
									zephir_read_property_zval(&_69$$28, &recordAfter, &referencedFields, PH_NOISY_CC);
									zephir_update_property_zval_zval(&intermediateModel, &intermediateReferencedFields, &_69$$28);
								}
							}
							ZEPHIR_CALL_METHOD(&_70$$15, &intermediateModel, "doSave", NULL, 0, visited);
							zephir_check_call_status();
							if (!(zephir_is_true(&_70$$15))) {
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessagesFrom", &_35, 0, &intermediateModel);
								zephir_check_call_status();
								if (nesting) {
									ZVAL_BOOL(&_71$$29, 1);
								} else {
									ZVAL_BOOL(&_71$$29, 0);
								}
								ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_72, 0, &_71$$29);
								zephir_check_call_status();
								RETURN_MM_BOOL(0);
							}
							if (doSync) {
								ZEPHIR_INIT_NVAR(&keepKey);
								if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
									ZVAL_STRING(&keepKey, "");
									if (Z_TYPE_P(&referencedFields) == IS_STRING) {
										ZEPHIR_INIT_NVAR(&_74$$31);
										zephir_string_to_char_array(&_74$$31, &referencedFields);
										_73$$31 = &_74$$31;
									} else {
										_73$$31 = &referencedFields;
									}
									zephir_is_iterable(_73$$31, 0, "phalcon/Mvc/Model.zep", 6037);
									if (Z_TYPE_P(_73$$31) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_73$$31), _75$$31)
										{
											ZEPHIR_INIT_NVAR(&columnA);
											ZVAL_COPY(&columnA, _75$$31);
											ZEPHIR_OBS_NVAR(&_76$$32);
											zephir_read_property_zval(&_76$$32, &recordAfter, &columnA, PH_NOISY_CC);
											ZEPHIR_INIT_NVAR(&_77$$32);
											ZEPHIR_CONCAT_VS(&_77$$32, &_76$$32, "|");
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_concat_self(&keepKey, &_77$$32);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, _73$$31, "rewind", NULL, 0);
										zephir_check_call_status();
										_79$$31 = 1;
										while (1) {
											if (_79$$31) {
												_79$$31 = 0;
											} else {
												ZEPHIR_CALL_METHOD(NULL, _73$$31, "next", NULL, 0);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(&_78$$31, _73$$31, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_78$$31)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&columnA, _73$$31, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_OBS_NVAR(&_80$$33);
												zephir_read_property_zval(&_80$$33, &recordAfter, &columnA, PH_NOISY_CC);
												ZEPHIR_INIT_NVAR(&_81$$33);
												ZEPHIR_CONCAT_VS(&_81$$33, &_80$$33, "|");
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_concat_self(&keepKey, &_81$$33);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
										}
									}
									ZEPHIR_INIT_NVAR(&columnA);
								} else {
									ZEPHIR_OBS_NVAR(&_82$$34);
									zephir_read_property_zval(&_82$$34, &recordAfter, &referencedFields, PH_NOISY_CC);
									zephir_cast_to_string(&_83$$34, &_82$$34);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CPY_WRT(&keepKey, &_83$$34);
								}
								zephir_array_update_zval(&keptKeys, &keepKey, &__$true, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _32$$9, "rewind", NULL, 0);
						zephir_check_call_status();
						_85$$9 = 1;
						while (1) {
							if (_85$$9) {
								_85$$9 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _32$$9, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_84$$9, _32$$9, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_84$$9)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&recordAfter, _32$$9, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&_86$$35, &recordAfter, "doSave", NULL, 0, visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_86$$35))) {
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessagesFrom", &_35, 0, &recordAfter);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_87$$36, 1);
									} else {
										ZVAL_BOOL(&_87$$36, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_88, 0, &_87$$36);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
								if (UNEXPECTED(Z_TYPE_P(&conditions) != IS_ARRAY)) {
									zephir_throw_variable_type_error(&conditions, "loopConditions", "array");
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CPY_WRT(&loopConditions, &conditions);
								if (UNEXPECTED(Z_TYPE_P(&placeholders) != IS_ARRAY)) {
									zephir_throw_variable_type_error(&placeholders, "loopPlaceholders", "array");
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CPY_WRT(&loopPlaceholders, &placeholders);
								ZEPHIR_CALL_METHOD(&_89$$35, &relation, "getType", &_90, 0);
								zephir_check_call_status();
								if (ZEPHIR_IS_LONG_IDENTICAL(&_89$$35, 4)) {
									if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
										referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
										_93$$38 = referencedFieldsCount;
										_92$$38 = 0;
										_91$$38 = 0;
										if (_92$$38 <= _93$$38) {
											while (1) {
												if (_91$$38) {
													_92$$38++;
													if (!(_92$$38 <= _93$$38)) {
														break;
													}
												} else {
													_91$$38 = 1;
												}
												j = _92$$38;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &referencedFields, j, PH_NOISY, "phalcon/Mvc/Model.zep", 5954);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												t = (j + i);
												ZEPHIR_OBS_NVAR(&_94$$39);
												zephir_array_fetch_long(&_94$$39, &intermediateReferencedFields, j, PH_NOISY, "phalcon/Mvc/Model.zep", 5956);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_INIT_NVAR(&_95$$39);
												ZVAL_LONG(&_95$$39, t);
												ZEPHIR_INIT_NVAR(&_96$$39);
												ZEPHIR_CONCAT_SVSVS(&_96$$39, "[", &_94$$39, "] = :APR", &_95$$39, ":");
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_append(&loopConditions, &_96$$39, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5956);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_INIT_NVAR(&_97$$39);
												ZVAL_LONG(&_97$$39, t);
												ZEPHIR_INIT_NVAR(&_98$$39);
												ZEPHIR_CONCAT_SV(&_98$$39, "APR", &_97$$39);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_OBS_NVAR(&_99$$39);
												zephir_read_property_zval(&_99$$39, &recordAfter, &columnA, PH_NOISY_CC);
												zephir_array_update_zval(&loopPlaceholders, &_98$$39, &_99$$39, PH_COPY | PH_SEPARATE);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
											}
										}
									} else {
										ZEPHIR_INIT_NVAR(&_100$$40);
										ZVAL_LONG(&_100$$40, i);
										ZEPHIR_INIT_NVAR(&_101$$40);
										ZEPHIR_CONCAT_SVSVS(&_101$$40, "[", &intermediateReferencedFields, "] = :APR", &_100$$40, ":");
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_append(&loopConditions, &_101$$40, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5960);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_INIT_NVAR(&_102$$40);
										ZVAL_LONG(&_102$$40, i);
										ZEPHIR_INIT_NVAR(&_103$$40);
										ZEPHIR_CONCAT_SV(&_103$$40, "APR", &_102$$40);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_OBS_NVAR(&_104$$40);
										zephir_read_property_zval(&_104$$40, &recordAfter, &referencedFields, PH_NOISY_CC);
										zephir_array_update_zval(&loopPlaceholders, &_103$$40, &_104$$40, PH_COPY | PH_SEPARATE);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									}
								}
								ZEPHIR_CALL_METHOD(&_105$$35, &manager, "load", &_106, 0, &intermediateModelName);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&intermediateModel, &_105$$35);
								ZEPHIR_INIT_NVAR(&_107$$35);
								zephir_create_array(&_107$$35, 2, 0);
								ZEPHIR_INIT_NVAR(&_108$$35);
								zephir_fast_join_str(&_108$$35, SL(" AND "), &loopConditions);
								zephir_array_fast_append(&_107$$35, &_108$$35);
								zephir_array_update_string(&_107$$35, SL("bind"), &loopPlaceholders, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(&existingIntermediateModel, &intermediateModel, "findFirst", NULL, 0, &_107$$35);
								zephir_check_call_status();
								if (zephir_is_true(&existingIntermediateModel)) {
									ZEPHIR_CPY_WRT(&intermediateModel, &existingIntermediateModel);
								}
								_109$$35 = !zephir_is_true(&existingIntermediateModel);
								if (!(_109$$35)) {
									ZEPHIR_CALL_METHOD(&_105$$35, &relation, "getType", &_110, 0);
									zephir_check_call_status();
									_109$$35 = ZEPHIR_IS_LONG_IDENTICAL(&_105$$35, 3);
								}
								if (_109$$35) {
									if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
										_113$$43 = columnCount;
										_112$$43 = 0;
										_111$$43 = 0;
										if (_112$$43 <= _113$$43) {
											while (1) {
												if (_111$$43) {
													_112$$43++;
													if (!(_112$$43 <= _113$$43)) {
														break;
													}
												} else {
													_111$$43 = 1;
												}
												h = _112$$43;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &columns, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5991);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_OBS_NVAR(&columnB);
												zephir_array_fetch_long(&columnB, &intermediateFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5992);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_OBS_NVAR(&_114$$44);
												zephir_read_property_zval(&_114$$44, this_ptr, &columnA, PH_NOISY_CC);
												zephir_update_property_zval_zval(&intermediateModel, &columnB, &_114$$44);
											}
										}
									} else {
										ZEPHIR_OBS_NVAR(&_115$$45);
										zephir_read_property_zval(&_115$$45, this_ptr, &columns, PH_NOISY_CC);
										zephir_update_property_zval_zval(&intermediateModel, &intermediateFields, &_115$$45);
									}
									if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
										referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
										_118$$46 = referencedFieldsCount;
										_117$$46 = 0;
										_116$$46 = 0;
										if (_117$$46 <= _118$$46) {
											while (1) {
												if (_116$$46) {
													_117$$46++;
													if (!(_117$$46 <= _118$$46)) {
														break;
													}
												} else {
													_116$$46 = 1;
												}
												h = _117$$46;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &referencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 6001);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_OBS_NVAR(&columnB);
												zephir_array_fetch_long(&columnB, &intermediateReferencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 6002);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_OBS_NVAR(&_119$$47);
												zephir_read_property_zval(&_119$$47, &recordAfter, &columnA, PH_NOISY_CC);
												zephir_update_property_zval_zval(&intermediateModel, &columnB, &_119$$47);
											}
										}
									} else {
										ZEPHIR_OBS_NVAR(&_120$$48);
										zephir_read_property_zval(&_120$$48, &recordAfter, &referencedFields, PH_NOISY_CC);
										zephir_update_property_zval_zval(&intermediateModel, &intermediateReferencedFields, &_120$$48);
									}
								}
								ZEPHIR_CALL_METHOD(&_121$$35, &intermediateModel, "doSave", NULL, 0, visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_121$$35))) {
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessagesFrom", &_35, 0, &intermediateModel);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_122$$49, 1);
									} else {
										ZVAL_BOOL(&_122$$49, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_123, 0, &_122$$49);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
								if (doSync) {
									if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
										ZVAL_STRING(&keepKey, "");
										if (Z_TYPE_P(&referencedFields) == IS_STRING) {
											ZEPHIR_INIT_NVAR(&_125$$51);
											zephir_string_to_char_array(&_125$$51, &referencedFields);
											_124$$51 = &_125$$51;
										} else {
											_124$$51 = &referencedFields;
										}
										zephir_is_iterable(_124$$51, 0, "phalcon/Mvc/Model.zep", 6037);
										if (Z_TYPE_P(_124$$51) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_124$$51), _126$$51)
											{
												ZEPHIR_INIT_NVAR(&columnA);
												ZVAL_COPY(&columnA, _126$$51);
												ZEPHIR_OBS_NVAR(&_127$$52);
												zephir_read_property_zval(&_127$$52, &recordAfter, &columnA, PH_NOISY_CC);
												ZEPHIR_INIT_NVAR(&_128$$52);
												ZEPHIR_CONCAT_VS(&_128$$52, &_127$$52, "|");
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_concat_self(&keepKey, &_128$$52);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, _124$$51, "rewind", NULL, 0);
											zephir_check_call_status();
											_130$$51 = 1;
											while (1) {
												if (_130$$51) {
													_130$$51 = 0;
												} else {
													ZEPHIR_CALL_METHOD(NULL, _124$$51, "next", NULL, 0);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD(&_129$$51, _124$$51, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_129$$51)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&columnA, _124$$51, "current", NULL, 0);
												zephir_check_call_status();
													ZEPHIR_OBS_NVAR(&_131$$53);
													zephir_read_property_zval(&_131$$53, &recordAfter, &columnA, PH_NOISY_CC);
													ZEPHIR_INIT_NVAR(&_132$$53);
													ZEPHIR_CONCAT_VS(&_132$$53, &_131$$53, "|");
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													zephir_concat_self(&keepKey, &_132$$53);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
											}
										}
										ZEPHIR_INIT_NVAR(&columnA);
									} else {
										ZEPHIR_OBS_NVAR(&_133$$54);
										zephir_read_property_zval(&_133$$54, &recordAfter, &referencedFields, PH_NOISY_CC);
										zephir_cast_to_string(&_134$$54, &_133$$54);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CPY_WRT(&keepKey, &_134$$54);
									}
									zephir_array_update_zval(&keptKeys, &keepKey, &__$true, PH_COPY | PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
						}
					}
					ZEPHIR_INIT_NVAR(&recordAfter);
					_135$$9 = doSync;
					if (_135$$9) {
						ZEPHIR_CALL_METHOD(&_15$$9, &relation, "getType", NULL, 0);
						zephir_check_call_status();
						_135$$9 = ZEPHIR_IS_LONG_IDENTICAL(&_15$$9, 4);
					}
					if (_135$$9) {
						ZEPHIR_CALL_METHOD(&_136$$55, &manager, "load", &_137, 0, &intermediateModelName);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&intermediateModel, &_136$$55);
						ZEPHIR_INIT_NVAR(&_138$$55);
						zephir_create_array(&_138$$55, 2, 0);
						ZEPHIR_INIT_NVAR(&_139$$55);
						zephir_fast_join_str(&_139$$55, SL(" AND "), &conditions);
						zephir_array_fast_append(&_138$$55, &_139$$55);
						zephir_array_update_string(&_138$$55, SL("bind"), &placeholders, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD(&existingRecords, &intermediateModel, "find", NULL, 0, &_138$$55);
						zephir_check_call_status();
						if (Z_TYPE_P(&existingRecords) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_139$$55);
							zephir_string_to_char_array(&_139$$55, &existingRecords);
							_140$$55 = &_139$$55;
						} else {
							_140$$55 = &existingRecords;
						}
						zephir_is_iterable(_140$$55, 0, "phalcon/Mvc/Model.zep", 6079);
						if (Z_TYPE_P(_140$$55) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_140$$55), _141$$55)
							{
								ZEPHIR_INIT_NVAR(&existingRecord);
								ZVAL_COPY(&existingRecord, _141$$55);
								if (UNEXPECTED(Z_TYPE_P(&intermediateReferencedFields) == IS_ARRAY)) {
									ZVAL_STRING(&keepKey, "");
									if (Z_TYPE_P(&intermediateReferencedFields) == IS_STRING) {
										ZEPHIR_INIT_NVAR(&_143$$57);
										zephir_string_to_char_array(&_143$$57, &intermediateReferencedFields);
										_142$$57 = &_143$$57;
									} else {
										_142$$57 = &intermediateReferencedFields;
									}
									zephir_is_iterable(_142$$57, 0, "phalcon/Mvc/Model.zep", 6067);
									if (Z_TYPE_P(_142$$57) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_142$$57), _144$$57)
										{
											ZEPHIR_INIT_NVAR(&columnB);
											ZVAL_COPY(&columnB, _144$$57);
											ZEPHIR_OBS_NVAR(&_145$$58);
											zephir_read_property_zval(&_145$$58, &existingRecord, &columnB, PH_NOISY_CC);
											ZEPHIR_INIT_NVAR(&_146$$58);
											ZEPHIR_CONCAT_VS(&_146$$58, &_145$$58, "|");
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_concat_self(&keepKey, &_146$$58);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, _142$$57, "rewind", NULL, 0);
										zephir_check_call_status();
										_148$$57 = 1;
										while (1) {
											if (_148$$57) {
												_148$$57 = 0;
											} else {
												ZEPHIR_CALL_METHOD(NULL, _142$$57, "next", NULL, 0);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(&_147$$57, _142$$57, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_147$$57)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&columnB, _142$$57, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_OBS_NVAR(&_149$$59);
												zephir_read_property_zval(&_149$$59, &existingRecord, &columnB, PH_NOISY_CC);
												ZEPHIR_INIT_NVAR(&_150$$59);
												ZEPHIR_CONCAT_VS(&_150$$59, &_149$$59, "|");
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_concat_self(&keepKey, &_150$$59);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
										}
									}
									ZEPHIR_INIT_NVAR(&columnB);
								} else {
									ZEPHIR_OBS_NVAR(&_151$$60);
									zephir_read_property_zval(&_151$$60, &existingRecord, &intermediateReferencedFields, PH_NOISY_CC);
									zephir_cast_to_string(&_152$$60, &_151$$60);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CPY_WRT(&keepKey, &_152$$60);
								}
								_153$$56 = zephir_array_isset_value(&keptKeys, &keepKey);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								_154$$56 = !(_153$$56);
								if (_154$$56) {
									ZEPHIR_CALL_METHOD(&_155$$56, &existingRecord, "delete", NULL, 0);
									zephir_check_call_status();
									_154$$56 = !zephir_is_true(&_155$$56);
								}
								if (_154$$56) {
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessagesFrom", &_35, 0, &existingRecord);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_156$$61, 1);
									} else {
										ZVAL_BOOL(&_156$$61, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_157, 0, &_156$$61);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _140$$55, "rewind", NULL, 0);
							zephir_check_call_status();
							_159$$55 = 1;
							while (1) {
								if (_159$$55) {
									_159$$55 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _140$$55, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_158$$55, _140$$55, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_158$$55)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&existingRecord, _140$$55, "current", NULL, 0);
								zephir_check_call_status();
									if (UNEXPECTED(Z_TYPE_P(&intermediateReferencedFields) == IS_ARRAY)) {
										ZVAL_STRING(&keepKey, "");
										if (Z_TYPE_P(&intermediateReferencedFields) == IS_STRING) {
											ZEPHIR_INIT_NVAR(&_161$$63);
											zephir_string_to_char_array(&_161$$63, &intermediateReferencedFields);
											_160$$63 = &_161$$63;
										} else {
											_160$$63 = &intermediateReferencedFields;
										}
										zephir_is_iterable(_160$$63, 0, "phalcon/Mvc/Model.zep", 6067);
										if (Z_TYPE_P(_160$$63) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_160$$63), _162$$63)
											{
												ZEPHIR_INIT_NVAR(&columnB);
												ZVAL_COPY(&columnB, _162$$63);
												ZEPHIR_OBS_NVAR(&_163$$64);
												zephir_read_property_zval(&_163$$64, &existingRecord, &columnB, PH_NOISY_CC);
												ZEPHIR_INIT_NVAR(&_164$$64);
												ZEPHIR_CONCAT_VS(&_164$$64, &_163$$64, "|");
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_concat_self(&keepKey, &_164$$64);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, _160$$63, "rewind", NULL, 0);
											zephir_check_call_status();
											_166$$63 = 1;
											while (1) {
												if (_166$$63) {
													_166$$63 = 0;
												} else {
													ZEPHIR_CALL_METHOD(NULL, _160$$63, "next", NULL, 0);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD(&_165$$63, _160$$63, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_165$$63)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&columnB, _160$$63, "current", NULL, 0);
												zephir_check_call_status();
													ZEPHIR_OBS_NVAR(&_167$$65);
													zephir_read_property_zval(&_167$$65, &existingRecord, &columnB, PH_NOISY_CC);
													ZEPHIR_INIT_NVAR(&_168$$65);
													ZEPHIR_CONCAT_VS(&_168$$65, &_167$$65, "|");
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													zephir_concat_self(&keepKey, &_168$$65);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
											}
										}
										ZEPHIR_INIT_NVAR(&columnB);
									} else {
										ZEPHIR_OBS_NVAR(&_169$$66);
										zephir_read_property_zval(&_169$$66, &existingRecord, &intermediateReferencedFields, PH_NOISY_CC);
										zephir_cast_to_string(&_170$$66, &_169$$66);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CPY_WRT(&keepKey, &_170$$66);
									}
									_171$$62 = zephir_array_isset_value(&keptKeys, &keepKey);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									_172$$62 = !(_171$$62);
									if (_172$$62) {
										ZEPHIR_CALL_METHOD(&_173$$62, &existingRecord, "delete", NULL, 0);
										zephir_check_call_status();
										_172$$62 = !zephir_is_true(&_173$$62);
									}
									if (_172$$62) {
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessagesFrom", &_35, 0, &existingRecord);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_174$$67, 1);
										} else {
											ZVAL_BOOL(&_174$$67, 0);
										}
										ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_175, 0, &_174$$67);
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
							ZEPHIR_INIT_NVAR(&_177$$69);
							zephir_string_to_char_array(&_177$$69, &relatedRecords);
							_176$$69 = &_177$$69;
						} else {
							_176$$69 = &relatedRecords;
						}
						zephir_is_iterable(_176$$69, 0, "phalcon/Mvc/Model.zep", 6107);
						if (Z_TYPE_P(_176$$69) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_176$$69), _178$$69)
							{
								ZEPHIR_INIT_NVAR(&recordAfter);
								ZVAL_COPY(&recordAfter, _178$$69);
								_181$$70 = columnCount;
								_180$$70 = 0;
								_179$$70 = 0;
								if (_180$$70 <= _181$$70) {
									while (1) {
										if (_179$$70) {
											_180$$70++;
											if (!(_180$$70 <= _181$$70)) {
												break;
											}
										} else {
											_179$$70 = 1;
										}
										i = _180$$70;
										ZEPHIR_OBS_NVAR(&columnA);
										zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 6085);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_OBS_NVAR(&columnB);
										zephir_array_fetch_long(&columnB, &referencedFields, i, PH_NOISY, "phalcon/Mvc/Model.zep", 6086);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_OBS_NVAR(&_182$$71);
										zephir_read_property_zval(&_182$$71, this_ptr, &columnA, PH_NOISY_CC);
										zephir_update_property_zval_zval(&recordAfter, &columnB, &_182$$71);
									}
								}
								ZEPHIR_CALL_METHOD(&_183$$70, &recordAfter, "doSave", NULL, 0, visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_183$$70))) {
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessagesFrom", &_35, 0, &recordAfter);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_184$$72, 1);
									} else {
										ZVAL_BOOL(&_184$$72, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_185, 0, &_184$$72);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _176$$69, "rewind", NULL, 0);
							zephir_check_call_status();
							_187$$69 = 1;
							while (1) {
								if (_187$$69) {
									_187$$69 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _176$$69, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_186$$69, _176$$69, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_186$$69)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&recordAfter, _176$$69, "current", NULL, 0);
								zephir_check_call_status();
									_190$$73 = columnCount;
									_189$$73 = 0;
									_188$$73 = 0;
									if (_189$$73 <= _190$$73) {
										while (1) {
											if (_188$$73) {
												_189$$73++;
												if (!(_189$$73 <= _190$$73)) {
													break;
												}
											} else {
												_188$$73 = 1;
											}
											i = _189$$73;
											ZEPHIR_OBS_NVAR(&columnA);
											zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 6085);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_OBS_NVAR(&columnB);
											zephir_array_fetch_long(&columnB, &referencedFields, i, PH_NOISY, "phalcon/Mvc/Model.zep", 6086);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_OBS_NVAR(&_191$$74);
											zephir_read_property_zval(&_191$$74, this_ptr, &columnA, PH_NOISY_CC);
											zephir_update_property_zval_zval(&recordAfter, &columnB, &_191$$74);
										}
									}
									ZEPHIR_CALL_METHOD(&_192$$73, &recordAfter, "doSave", NULL, 0, visited);
									zephir_check_call_status();
									if (!(zephir_is_true(&_192$$73))) {
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessagesFrom", &_35, 0, &recordAfter);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_193$$75, 1);
										} else {
											ZVAL_BOOL(&_193$$75, 0);
										}
										ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_194, 0, &_193$$75);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
							}
						}
						ZEPHIR_INIT_NVAR(&recordAfter);
					} else {
						if (Z_TYPE_P(&relatedRecords) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_196$$76);
							zephir_string_to_char_array(&_196$$76, &relatedRecords);
							_195$$76 = &_196$$76;
						} else {
							_195$$76 = &relatedRecords;
						}
						zephir_is_iterable(_195$$76, 0, "phalcon/Mvc/Model.zep", 6132);
						if (Z_TYPE_P(_195$$76) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_195$$76), _197$$76)
							{
								ZEPHIR_INIT_NVAR(&recordAfter);
								ZVAL_COPY(&recordAfter, _197$$76);
								ZEPHIR_OBS_NVAR(&_198$$77);
								zephir_read_property_zval(&_198$$77, this_ptr, &columns, PH_NOISY_CC);
								zephir_update_property_zval_zval(&recordAfter, &referencedFields, &_198$$77);
								ZEPHIR_CALL_METHOD(&_199$$77, &recordAfter, "doSave", NULL, 0, visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_199$$77))) {
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessagesFrom", &_35, 0, &recordAfter);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_200$$78, 1);
									} else {
										ZVAL_BOOL(&_200$$78, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_201, 0, &_200$$78);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _195$$76, "rewind", NULL, 0);
							zephir_check_call_status();
							_203$$76 = 1;
							while (1) {
								if (_203$$76) {
									_203$$76 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _195$$76, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_202$$76, _195$$76, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_202$$76)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&recordAfter, _195$$76, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_OBS_NVAR(&_204$$79);
									zephir_read_property_zval(&_204$$79, this_ptr, &columns, PH_NOISY_CC);
									zephir_update_property_zval_zval(&recordAfter, &referencedFields, &_204$$79);
									ZEPHIR_CALL_METHOD(&_205$$79, &recordAfter, "doSave", NULL, 0, visited);
									zephir_check_call_status();
									if (!(zephir_is_true(&_205$$79))) {
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessagesFrom", &_35, 0, &recordAfter);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_206$$80, 1);
										} else {
											ZVAL_BOOL(&_206$$80, 0);
										}
										ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_207, 0, &_206$$80);
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
						ZVAL_BOOL(&_208$$82, 1);
					} else {
						ZVAL_BOOL(&_208$$82, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_209, 0, &_208$$82);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_210$$82);
					object_init_ex(&_210$$82, phalcon_mvc_model_exceptions_relationnotdefined_ce);
					ZEPHIR_CALL_METHOD(NULL, &_210$$82, "__construct", &_211, 0, &className, &name);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_210$$82, "phalcon/Mvc/Model.zep", 6138);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_213 = 1;
		while (1) {
			if (_213) {
				_213 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_212, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_212)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, _1, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&record, _1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_214$$83, &manager, "getRelationByAlias", &_215, 0, &className, &name);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&relation, &_214$$83);
				if (Z_TYPE_P(&relation) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&_216$$84, &relation, "getType", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG(&_216$$84, 0)) {
						continue;
					}
					_217$$84 = Z_TYPE_P(&record) != IS_OBJECT;
					if (_217$$84) {
						_217$$84 = Z_TYPE_P(&record) != IS_ARRAY;
					}
					if (UNEXPECTED(_217$$84)) {
						if (nesting) {
							ZVAL_BOOL(&_218$$86, 1);
						} else {
							ZVAL_BOOL(&_218$$86, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_219, 0, &_218$$86);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_220$$86);
						object_init_ex(&_220$$86, phalcon_mvc_model_exceptions_relationrequiresobjectorarray_ce);
						ZEPHIR_CALL_METHOD(NULL, &_220$$86, "__construct", &_221, 0, &className, &name);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_220$$86, "phalcon/Mvc/Model.zep", 5866);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&columns, &relation, "getFields", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedModel, &relation, "getReferencedModel", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getReferencedFields", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&record) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_222$$87);
						zephir_create_array(&_222$$87, 1, 0);
						zephir_array_fast_append(&_222$$87, &record);
						ZEPHIR_CPY_WRT(&relatedRecords, &_222$$87);
					} else {
						ZEPHIR_CPY_WRT(&relatedRecords, &record);
					}
					ZEPHIR_CALL_METHOD(&_223$$84, &relation, "isThrough", NULL, 0);
					zephir_check_call_status();
					isThrough = zephir_get_boolval(&_223$$84);
					if (isThrough) {
						ZEPHIR_CALL_METHOD(&intermediateModelName, &relation, "getIntermediateModel", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&intermediateFields, &relation, "getIntermediateFields", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&intermediateReferencedFields, &relation, "getIntermediateReferencedFields", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&placeholders);
						array_init(&placeholders);
						ZEPHIR_INIT_NVAR(&conditions);
						array_init(&conditions);
						ZEPHIR_INIT_NVAR(&keptKeys);
						array_init(&keptKeys);
						ZEPHIR_INIT_NVAR(&_225$$89);
						ZVAL_STRING(&_225$$89, "sync");
						ZEPHIR_CALL_METHOD(&_224$$89, &relation, "getOption", NULL, 0, &_225$$89);
						zephir_check_call_status();
						doSync = zephir_get_boolval(&_224$$89);
						ZEPHIR_OBS_NVAR(&override);
						zephir_read_property_cached(&_226$$89, this_ptr, _zephir_prop_0, 1023, PH_NOISY_CC | PH_READONLY);
						_227$$89 = zephir_array_isset_fetch(&override, &_226$$89, &name, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_227$$89) {
							doSync = zephir_get_boolval(&override);
						} else {
							ZEPHIR_OBS_NVAR(&override);
							zephir_read_property_cached(&_228$$89, this_ptr, _zephir_prop_0, 1023, PH_NOISY_CC | PH_READONLY);
							_229$$89 = zephir_array_isset_string_fetch(&override, &_228$$89, SL("*"), 0);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (_229$$89) {
								doSync = zephir_get_boolval(&override);
							}
						}
						if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
							columnCount = (zephir_fast_count_int(&columns) - 1);
							_232$$92 = columnCount;
							_231$$92 = 0;
							_230$$92 = 0;
							if (_231$$92 <= _232$$92) {
								while (1) {
									if (_230$$92) {
										_231$$92++;
										if (!(_231$$92 <= _232$$92)) {
											break;
										}
									} else {
										_230$$92 = 1;
									}
									i = _231$$92;
									ZEPHIR_OBS_NVAR(&columnA);
									zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5913);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_OBS_NVAR(&_233$$93);
									zephir_array_fetch_long(&_233$$93, &intermediateFields, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5914);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_INIT_NVAR(&_234$$93);
									ZVAL_LONG(&_234$$93, i);
									ZEPHIR_INIT_NVAR(&_235$$93);
									ZEPHIR_CONCAT_SVSVS(&_235$$93, "[", &_233$$93, "] = :APR", &_234$$93, ":");
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&conditions, &_235$$93, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5914);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_INIT_NVAR(&_236$$93);
									ZVAL_LONG(&_236$$93, i);
									ZEPHIR_INIT_NVAR(&_237$$93);
									ZEPHIR_CONCAT_SV(&_237$$93, "APR", &_236$$93);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_OBS_NVAR(&_238$$93);
									zephir_read_property_zval(&_238$$93, this_ptr, &columnA, PH_NOISY_CC);
									zephir_array_update_zval(&placeholders, &_237$$93, &_238$$93, PH_COPY | PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
							}
							i = (columnCount + 1);
						} else {
							ZEPHIR_INIT_NVAR(&_239$$94);
							ZEPHIR_CONCAT_SVS(&_239$$94, "[", &intermediateFields, "] = :APR0:");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&conditions, &_239$$94, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5919);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&_240$$94);
							zephir_read_property_zval(&_240$$94, this_ptr, &columns, PH_NOISY_CC);
							zephir_array_update_string(&placeholders, SL("APR0"), &_240$$94, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							i = 1;
						}
						if (Z_TYPE_P(&relatedRecords) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_225$$89);
							zephir_string_to_char_array(&_225$$89, &relatedRecords);
							_241$$89 = &_225$$89;
						} else {
							_241$$89 = &relatedRecords;
						}
						zephir_is_iterable(_241$$89, 0, "phalcon/Mvc/Model.zep", 6049);
						if (Z_TYPE_P(_241$$89) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_241$$89), _242$$89)
							{
								ZEPHIR_INIT_NVAR(&recordAfter);
								ZVAL_COPY(&recordAfter, _242$$89);
								ZEPHIR_CALL_METHOD(&_243$$95, &recordAfter, "doSave", NULL, 0, visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_243$$95))) {
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessagesFrom", &_35, 0, &recordAfter);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_244$$96, 1);
									} else {
										ZVAL_BOOL(&_244$$96, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_245, 0, &_244$$96);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
								if (UNEXPECTED(Z_TYPE_P(&conditions) != IS_ARRAY)) {
									zephir_throw_variable_type_error(&conditions, "loopConditions", "array");
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CPY_WRT(&loopConditions, &conditions);
								if (UNEXPECTED(Z_TYPE_P(&placeholders) != IS_ARRAY)) {
									zephir_throw_variable_type_error(&placeholders, "loopPlaceholders", "array");
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CPY_WRT(&loopPlaceholders, &placeholders);
								ZEPHIR_CALL_METHOD(&_246$$95, &relation, "getType", &_247, 0);
								zephir_check_call_status();
								if (ZEPHIR_IS_LONG_IDENTICAL(&_246$$95, 4)) {
									if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
										referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
										_250$$98 = referencedFieldsCount;
										_249$$98 = 0;
										_248$$98 = 0;
										if (_249$$98 <= _250$$98) {
											while (1) {
												if (_248$$98) {
													_249$$98++;
													if (!(_249$$98 <= _250$$98)) {
														break;
													}
												} else {
													_248$$98 = 1;
												}
												j = _249$$98;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &referencedFields, j, PH_NOISY, "phalcon/Mvc/Model.zep", 5954);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												t = (j + i);
												ZEPHIR_OBS_NVAR(&_251$$99);
												zephir_array_fetch_long(&_251$$99, &intermediateReferencedFields, j, PH_NOISY, "phalcon/Mvc/Model.zep", 5956);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_INIT_NVAR(&_252$$99);
												ZVAL_LONG(&_252$$99, t);
												ZEPHIR_INIT_NVAR(&_253$$99);
												ZEPHIR_CONCAT_SVSVS(&_253$$99, "[", &_251$$99, "] = :APR", &_252$$99, ":");
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_append(&loopConditions, &_253$$99, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5956);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_INIT_NVAR(&_254$$99);
												ZVAL_LONG(&_254$$99, t);
												ZEPHIR_INIT_NVAR(&_255$$99);
												ZEPHIR_CONCAT_SV(&_255$$99, "APR", &_254$$99);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_OBS_NVAR(&_256$$99);
												zephir_read_property_zval(&_256$$99, &recordAfter, &columnA, PH_NOISY_CC);
												zephir_array_update_zval(&loopPlaceholders, &_255$$99, &_256$$99, PH_COPY | PH_SEPARATE);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
											}
										}
									} else {
										ZEPHIR_INIT_NVAR(&_257$$100);
										ZVAL_LONG(&_257$$100, i);
										ZEPHIR_INIT_NVAR(&_258$$100);
										ZEPHIR_CONCAT_SVSVS(&_258$$100, "[", &intermediateReferencedFields, "] = :APR", &_257$$100, ":");
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_append(&loopConditions, &_258$$100, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5960);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_INIT_NVAR(&_259$$100);
										ZVAL_LONG(&_259$$100, i);
										ZEPHIR_INIT_NVAR(&_260$$100);
										ZEPHIR_CONCAT_SV(&_260$$100, "APR", &_259$$100);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_OBS_NVAR(&_261$$100);
										zephir_read_property_zval(&_261$$100, &recordAfter, &referencedFields, PH_NOISY_CC);
										zephir_array_update_zval(&loopPlaceholders, &_260$$100, &_261$$100, PH_COPY | PH_SEPARATE);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									}
								}
								ZEPHIR_CALL_METHOD(&_262$$95, &manager, "load", &_263, 0, &intermediateModelName);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&intermediateModel, &_262$$95);
								ZEPHIR_INIT_NVAR(&_264$$95);
								zephir_create_array(&_264$$95, 2, 0);
								ZEPHIR_INIT_NVAR(&_265$$95);
								zephir_fast_join_str(&_265$$95, SL(" AND "), &loopConditions);
								zephir_array_fast_append(&_264$$95, &_265$$95);
								zephir_array_update_string(&_264$$95, SL("bind"), &loopPlaceholders, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(&existingIntermediateModel, &intermediateModel, "findFirst", NULL, 0, &_264$$95);
								zephir_check_call_status();
								if (zephir_is_true(&existingIntermediateModel)) {
									ZEPHIR_CPY_WRT(&intermediateModel, &existingIntermediateModel);
								}
								_266$$95 = !zephir_is_true(&existingIntermediateModel);
								if (!(_266$$95)) {
									ZEPHIR_CALL_METHOD(&_262$$95, &relation, "getType", &_267, 0);
									zephir_check_call_status();
									_266$$95 = ZEPHIR_IS_LONG_IDENTICAL(&_262$$95, 3);
								}
								if (_266$$95) {
									if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
										_270$$103 = columnCount;
										_269$$103 = 0;
										_268$$103 = 0;
										if (_269$$103 <= _270$$103) {
											while (1) {
												if (_268$$103) {
													_269$$103++;
													if (!(_269$$103 <= _270$$103)) {
														break;
													}
												} else {
													_268$$103 = 1;
												}
												h = _269$$103;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &columns, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5991);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_OBS_NVAR(&columnB);
												zephir_array_fetch_long(&columnB, &intermediateFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5992);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_OBS_NVAR(&_271$$104);
												zephir_read_property_zval(&_271$$104, this_ptr, &columnA, PH_NOISY_CC);
												zephir_update_property_zval_zval(&intermediateModel, &columnB, &_271$$104);
											}
										}
									} else {
										ZEPHIR_OBS_NVAR(&_272$$105);
										zephir_read_property_zval(&_272$$105, this_ptr, &columns, PH_NOISY_CC);
										zephir_update_property_zval_zval(&intermediateModel, &intermediateFields, &_272$$105);
									}
									if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
										referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
										_275$$106 = referencedFieldsCount;
										_274$$106 = 0;
										_273$$106 = 0;
										if (_274$$106 <= _275$$106) {
											while (1) {
												if (_273$$106) {
													_274$$106++;
													if (!(_274$$106 <= _275$$106)) {
														break;
													}
												} else {
													_273$$106 = 1;
												}
												h = _274$$106;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &referencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 6001);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_OBS_NVAR(&columnB);
												zephir_array_fetch_long(&columnB, &intermediateReferencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 6002);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_OBS_NVAR(&_276$$107);
												zephir_read_property_zval(&_276$$107, &recordAfter, &columnA, PH_NOISY_CC);
												zephir_update_property_zval_zval(&intermediateModel, &columnB, &_276$$107);
											}
										}
									} else {
										ZEPHIR_OBS_NVAR(&_277$$108);
										zephir_read_property_zval(&_277$$108, &recordAfter, &referencedFields, PH_NOISY_CC);
										zephir_update_property_zval_zval(&intermediateModel, &intermediateReferencedFields, &_277$$108);
									}
								}
								ZEPHIR_CALL_METHOD(&_278$$95, &intermediateModel, "doSave", NULL, 0, visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_278$$95))) {
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessagesFrom", &_35, 0, &intermediateModel);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_279$$109, 1);
									} else {
										ZVAL_BOOL(&_279$$109, 0);
									}
									ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_280, 0, &_279$$109);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
								if (doSync) {
									if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
										ZVAL_STRING(&keepKey, "");
										if (Z_TYPE_P(&referencedFields) == IS_STRING) {
											ZEPHIR_INIT_NVAR(&_282$$111);
											zephir_string_to_char_array(&_282$$111, &referencedFields);
											_281$$111 = &_282$$111;
										} else {
											_281$$111 = &referencedFields;
										}
										zephir_is_iterable(_281$$111, 0, "phalcon/Mvc/Model.zep", 6037);
										if (Z_TYPE_P(_281$$111) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_281$$111), _283$$111)
											{
												ZEPHIR_INIT_NVAR(&columnA);
												ZVAL_COPY(&columnA, _283$$111);
												ZEPHIR_OBS_NVAR(&_284$$112);
												zephir_read_property_zval(&_284$$112, &recordAfter, &columnA, PH_NOISY_CC);
												ZEPHIR_INIT_NVAR(&_285$$112);
												ZEPHIR_CONCAT_VS(&_285$$112, &_284$$112, "|");
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_concat_self(&keepKey, &_285$$112);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, _281$$111, "rewind", NULL, 0);
											zephir_check_call_status();
											_287$$111 = 1;
											while (1) {
												if (_287$$111) {
													_287$$111 = 0;
												} else {
													ZEPHIR_CALL_METHOD(NULL, _281$$111, "next", NULL, 0);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD(&_286$$111, _281$$111, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_286$$111)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&columnA, _281$$111, "current", NULL, 0);
												zephir_check_call_status();
													ZEPHIR_OBS_NVAR(&_288$$113);
													zephir_read_property_zval(&_288$$113, &recordAfter, &columnA, PH_NOISY_CC);
													ZEPHIR_INIT_NVAR(&_289$$113);
													ZEPHIR_CONCAT_VS(&_289$$113, &_288$$113, "|");
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													zephir_concat_self(&keepKey, &_289$$113);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
											}
										}
										ZEPHIR_INIT_NVAR(&columnA);
									} else {
										ZEPHIR_OBS_NVAR(&_290$$114);
										zephir_read_property_zval(&_290$$114, &recordAfter, &referencedFields, PH_NOISY_CC);
										zephir_cast_to_string(&_291$$114, &_290$$114);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CPY_WRT(&keepKey, &_291$$114);
									}
									zephir_array_update_zval(&keptKeys, &keepKey, &__$true, PH_COPY | PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _241$$89, "rewind", NULL, 0);
							zephir_check_call_status();
							_293$$89 = 1;
							while (1) {
								if (_293$$89) {
									_293$$89 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _241$$89, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_292$$89, _241$$89, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_292$$89)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&recordAfter, _241$$89, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&_294$$115, &recordAfter, "doSave", NULL, 0, visited);
									zephir_check_call_status();
									if (!(zephir_is_true(&_294$$115))) {
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessagesFrom", &_35, 0, &recordAfter);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_295$$116, 1);
										} else {
											ZVAL_BOOL(&_295$$116, 0);
										}
										ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_296, 0, &_295$$116);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
									if (UNEXPECTED(Z_TYPE_P(&conditions) != IS_ARRAY)) {
										zephir_throw_variable_type_error(&conditions, "loopConditions", "array");
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CPY_WRT(&loopConditions, &conditions);
									if (UNEXPECTED(Z_TYPE_P(&placeholders) != IS_ARRAY)) {
										zephir_throw_variable_type_error(&placeholders, "loopPlaceholders", "array");
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CPY_WRT(&loopPlaceholders, &placeholders);
									ZEPHIR_CALL_METHOD(&_297$$115, &relation, "getType", &_298, 0);
									zephir_check_call_status();
									if (ZEPHIR_IS_LONG_IDENTICAL(&_297$$115, 4)) {
										if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
											referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
											_301$$118 = referencedFieldsCount;
											_300$$118 = 0;
											_299$$118 = 0;
											if (_300$$118 <= _301$$118) {
												while (1) {
													if (_299$$118) {
														_300$$118++;
														if (!(_300$$118 <= _301$$118)) {
															break;
														}
													} else {
														_299$$118 = 1;
													}
													j = _300$$118;
													ZEPHIR_OBS_NVAR(&columnA);
													zephir_array_fetch_long(&columnA, &referencedFields, j, PH_NOISY, "phalcon/Mvc/Model.zep", 5954);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													t = (j + i);
													ZEPHIR_OBS_NVAR(&_302$$119);
													zephir_array_fetch_long(&_302$$119, &intermediateReferencedFields, j, PH_NOISY, "phalcon/Mvc/Model.zep", 5956);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													ZEPHIR_INIT_NVAR(&_303$$119);
													ZVAL_LONG(&_303$$119, t);
													ZEPHIR_INIT_NVAR(&_304$$119);
													ZEPHIR_CONCAT_SVSVS(&_304$$119, "[", &_302$$119, "] = :APR", &_303$$119, ":");
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													zephir_array_append(&loopConditions, &_304$$119, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5956);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													ZEPHIR_INIT_NVAR(&_305$$119);
													ZVAL_LONG(&_305$$119, t);
													ZEPHIR_INIT_NVAR(&_306$$119);
													ZEPHIR_CONCAT_SV(&_306$$119, "APR", &_305$$119);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													ZEPHIR_OBS_NVAR(&_307$$119);
													zephir_read_property_zval(&_307$$119, &recordAfter, &columnA, PH_NOISY_CC);
													zephir_array_update_zval(&loopPlaceholders, &_306$$119, &_307$$119, PH_COPY | PH_SEPARATE);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
												}
											}
										} else {
											ZEPHIR_INIT_NVAR(&_308$$120);
											ZVAL_LONG(&_308$$120, i);
											ZEPHIR_INIT_NVAR(&_309$$120);
											ZEPHIR_CONCAT_SVSVS(&_309$$120, "[", &intermediateReferencedFields, "] = :APR", &_308$$120, ":");
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_append(&loopConditions, &_309$$120, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5960);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_INIT_NVAR(&_310$$120);
											ZVAL_LONG(&_310$$120, i);
											ZEPHIR_INIT_NVAR(&_311$$120);
											ZEPHIR_CONCAT_SV(&_311$$120, "APR", &_310$$120);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_OBS_NVAR(&_312$$120);
											zephir_read_property_zval(&_312$$120, &recordAfter, &referencedFields, PH_NOISY_CC);
											zephir_array_update_zval(&loopPlaceholders, &_311$$120, &_312$$120, PH_COPY | PH_SEPARATE);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
										}
									}
									ZEPHIR_CALL_METHOD(&_313$$115, &manager, "load", &_314, 0, &intermediateModelName);
									zephir_check_call_status();
									ZEPHIR_CPY_WRT(&intermediateModel, &_313$$115);
									ZEPHIR_INIT_NVAR(&_315$$115);
									zephir_create_array(&_315$$115, 2, 0);
									ZEPHIR_INIT_NVAR(&_316$$115);
									zephir_fast_join_str(&_316$$115, SL(" AND "), &loopConditions);
									zephir_array_fast_append(&_315$$115, &_316$$115);
									zephir_array_update_string(&_315$$115, SL("bind"), &loopPlaceholders, PH_COPY | PH_SEPARATE);
									ZEPHIR_CALL_METHOD(&existingIntermediateModel, &intermediateModel, "findFirst", NULL, 0, &_315$$115);
									zephir_check_call_status();
									if (zephir_is_true(&existingIntermediateModel)) {
										ZEPHIR_CPY_WRT(&intermediateModel, &existingIntermediateModel);
									}
									_317$$115 = !zephir_is_true(&existingIntermediateModel);
									if (!(_317$$115)) {
										ZEPHIR_CALL_METHOD(&_313$$115, &relation, "getType", &_318, 0);
										zephir_check_call_status();
										_317$$115 = ZEPHIR_IS_LONG_IDENTICAL(&_313$$115, 3);
									}
									if (_317$$115) {
										if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
											_321$$123 = columnCount;
											_320$$123 = 0;
											_319$$123 = 0;
											if (_320$$123 <= _321$$123) {
												while (1) {
													if (_319$$123) {
														_320$$123++;
														if (!(_320$$123 <= _321$$123)) {
															break;
														}
													} else {
														_319$$123 = 1;
													}
													h = _320$$123;
													ZEPHIR_OBS_NVAR(&columnA);
													zephir_array_fetch_long(&columnA, &columns, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5991);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													ZEPHIR_OBS_NVAR(&columnB);
													zephir_array_fetch_long(&columnB, &intermediateFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 5992);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													ZEPHIR_OBS_NVAR(&_322$$124);
													zephir_read_property_zval(&_322$$124, this_ptr, &columnA, PH_NOISY_CC);
													zephir_update_property_zval_zval(&intermediateModel, &columnB, &_322$$124);
												}
											}
										} else {
											ZEPHIR_OBS_NVAR(&_323$$125);
											zephir_read_property_zval(&_323$$125, this_ptr, &columns, PH_NOISY_CC);
											zephir_update_property_zval_zval(&intermediateModel, &intermediateFields, &_323$$125);
										}
										if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
											referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
											_326$$126 = referencedFieldsCount;
											_325$$126 = 0;
											_324$$126 = 0;
											if (_325$$126 <= _326$$126) {
												while (1) {
													if (_324$$126) {
														_325$$126++;
														if (!(_325$$126 <= _326$$126)) {
															break;
														}
													} else {
														_324$$126 = 1;
													}
													h = _325$$126;
													ZEPHIR_OBS_NVAR(&columnA);
													zephir_array_fetch_long(&columnA, &referencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 6001);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													ZEPHIR_OBS_NVAR(&columnB);
													zephir_array_fetch_long(&columnB, &intermediateReferencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 6002);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													ZEPHIR_OBS_NVAR(&_327$$127);
													zephir_read_property_zval(&_327$$127, &recordAfter, &columnA, PH_NOISY_CC);
													zephir_update_property_zval_zval(&intermediateModel, &columnB, &_327$$127);
												}
											}
										} else {
											ZEPHIR_OBS_NVAR(&_328$$128);
											zephir_read_property_zval(&_328$$128, &recordAfter, &referencedFields, PH_NOISY_CC);
											zephir_update_property_zval_zval(&intermediateModel, &intermediateReferencedFields, &_328$$128);
										}
									}
									ZEPHIR_CALL_METHOD(&_329$$115, &intermediateModel, "doSave", NULL, 0, visited);
									zephir_check_call_status();
									if (!(zephir_is_true(&_329$$115))) {
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessagesFrom", &_35, 0, &intermediateModel);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_330$$129, 1);
										} else {
											ZVAL_BOOL(&_330$$129, 0);
										}
										ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_331, 0, &_330$$129);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
									if (doSync) {
										if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
											ZVAL_STRING(&keepKey, "");
											if (Z_TYPE_P(&referencedFields) == IS_STRING) {
												ZEPHIR_INIT_NVAR(&_333$$131);
												zephir_string_to_char_array(&_333$$131, &referencedFields);
												_332$$131 = &_333$$131;
											} else {
												_332$$131 = &referencedFields;
											}
											zephir_is_iterable(_332$$131, 0, "phalcon/Mvc/Model.zep", 6037);
											if (Z_TYPE_P(_332$$131) == IS_ARRAY) {
												ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_332$$131), _334$$131)
												{
													ZEPHIR_INIT_NVAR(&columnA);
													ZVAL_COPY(&columnA, _334$$131);
													ZEPHIR_OBS_NVAR(&_335$$132);
													zephir_read_property_zval(&_335$$132, &recordAfter, &columnA, PH_NOISY_CC);
													ZEPHIR_INIT_NVAR(&_336$$132);
													ZEPHIR_CONCAT_VS(&_336$$132, &_335$$132, "|");
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													zephir_concat_self(&keepKey, &_336$$132);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
												} ZEND_HASH_FOREACH_END();
											} else {
												ZEPHIR_CALL_METHOD(NULL, _332$$131, "rewind", NULL, 0);
												zephir_check_call_status();
												_338$$131 = 1;
												while (1) {
													if (_338$$131) {
														_338$$131 = 0;
													} else {
														ZEPHIR_CALL_METHOD(NULL, _332$$131, "next", NULL, 0);
														zephir_check_call_status();
													}
													ZEPHIR_CALL_METHOD(&_337$$131, _332$$131, "valid", NULL, 0);
													zephir_check_call_status();
													if (!zend_is_true(&_337$$131)) {
														break;
													}
													ZEPHIR_CALL_METHOD(&columnA, _332$$131, "current", NULL, 0);
													zephir_check_call_status();
														ZEPHIR_OBS_NVAR(&_339$$133);
														zephir_read_property_zval(&_339$$133, &recordAfter, &columnA, PH_NOISY_CC);
														ZEPHIR_INIT_NVAR(&_340$$133);
														ZEPHIR_CONCAT_VS(&_340$$133, &_339$$133, "|");
														if (UNEXPECTED(EG(exception))) {
															ZEPHIR_MM_RESTORE();
															return;
														}
														zephir_concat_self(&keepKey, &_340$$133);
														if (UNEXPECTED(EG(exception))) {
															ZEPHIR_MM_RESTORE();
															return;
														}
												}
											}
											ZEPHIR_INIT_NVAR(&columnA);
										} else {
											ZEPHIR_OBS_NVAR(&_341$$134);
											zephir_read_property_zval(&_341$$134, &recordAfter, &referencedFields, PH_NOISY_CC);
											zephir_cast_to_string(&_342$$134, &_341$$134);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_CPY_WRT(&keepKey, &_342$$134);
										}
										zephir_array_update_zval(&keptKeys, &keepKey, &__$true, PH_COPY | PH_SEPARATE);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									}
							}
						}
						ZEPHIR_INIT_NVAR(&recordAfter);
						_343$$89 = doSync;
						if (_343$$89) {
							ZEPHIR_CALL_METHOD(&_224$$89, &relation, "getType", NULL, 0);
							zephir_check_call_status();
							_343$$89 = ZEPHIR_IS_LONG_IDENTICAL(&_224$$89, 4);
						}
						if (_343$$89) {
							ZEPHIR_CALL_METHOD(&_344$$135, &manager, "load", &_345, 0, &intermediateModelName);
							zephir_check_call_status();
							ZEPHIR_CPY_WRT(&intermediateModel, &_344$$135);
							ZEPHIR_INIT_NVAR(&_346$$135);
							zephir_create_array(&_346$$135, 2, 0);
							ZEPHIR_INIT_NVAR(&_347$$135);
							zephir_fast_join_str(&_347$$135, SL(" AND "), &conditions);
							zephir_array_fast_append(&_346$$135, &_347$$135);
							zephir_array_update_string(&_346$$135, SL("bind"), &placeholders, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(&existingRecords, &intermediateModel, "find", NULL, 0, &_346$$135);
							zephir_check_call_status();
							if (Z_TYPE_P(&existingRecords) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_347$$135);
								zephir_string_to_char_array(&_347$$135, &existingRecords);
								_348$$135 = &_347$$135;
							} else {
								_348$$135 = &existingRecords;
							}
							zephir_is_iterable(_348$$135, 0, "phalcon/Mvc/Model.zep", 6079);
							if (Z_TYPE_P(_348$$135) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_348$$135), _349$$135)
								{
									ZEPHIR_INIT_NVAR(&existingRecord);
									ZVAL_COPY(&existingRecord, _349$$135);
									if (UNEXPECTED(Z_TYPE_P(&intermediateReferencedFields) == IS_ARRAY)) {
										ZVAL_STRING(&keepKey, "");
										if (Z_TYPE_P(&intermediateReferencedFields) == IS_STRING) {
											ZEPHIR_INIT_NVAR(&_351$$137);
											zephir_string_to_char_array(&_351$$137, &intermediateReferencedFields);
											_350$$137 = &_351$$137;
										} else {
											_350$$137 = &intermediateReferencedFields;
										}
										zephir_is_iterable(_350$$137, 0, "phalcon/Mvc/Model.zep", 6067);
										if (Z_TYPE_P(_350$$137) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_350$$137), _352$$137)
											{
												ZEPHIR_INIT_NVAR(&columnB);
												ZVAL_COPY(&columnB, _352$$137);
												ZEPHIR_OBS_NVAR(&_353$$138);
												zephir_read_property_zval(&_353$$138, &existingRecord, &columnB, PH_NOISY_CC);
												ZEPHIR_INIT_NVAR(&_354$$138);
												ZEPHIR_CONCAT_VS(&_354$$138, &_353$$138, "|");
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_concat_self(&keepKey, &_354$$138);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, _350$$137, "rewind", NULL, 0);
											zephir_check_call_status();
											_356$$137 = 1;
											while (1) {
												if (_356$$137) {
													_356$$137 = 0;
												} else {
													ZEPHIR_CALL_METHOD(NULL, _350$$137, "next", NULL, 0);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD(&_355$$137, _350$$137, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_355$$137)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&columnB, _350$$137, "current", NULL, 0);
												zephir_check_call_status();
													ZEPHIR_OBS_NVAR(&_357$$139);
													zephir_read_property_zval(&_357$$139, &existingRecord, &columnB, PH_NOISY_CC);
													ZEPHIR_INIT_NVAR(&_358$$139);
													ZEPHIR_CONCAT_VS(&_358$$139, &_357$$139, "|");
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													zephir_concat_self(&keepKey, &_358$$139);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
											}
										}
										ZEPHIR_INIT_NVAR(&columnB);
									} else {
										ZEPHIR_OBS_NVAR(&_359$$140);
										zephir_read_property_zval(&_359$$140, &existingRecord, &intermediateReferencedFields, PH_NOISY_CC);
										zephir_cast_to_string(&_360$$140, &_359$$140);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CPY_WRT(&keepKey, &_360$$140);
									}
									_361$$136 = zephir_array_isset_value(&keptKeys, &keepKey);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									_362$$136 = !(_361$$136);
									if (_362$$136) {
										ZEPHIR_CALL_METHOD(&_363$$136, &existingRecord, "delete", NULL, 0);
										zephir_check_call_status();
										_362$$136 = !zephir_is_true(&_363$$136);
									}
									if (_362$$136) {
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessagesFrom", &_35, 0, &existingRecord);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_364$$141, 1);
										} else {
											ZVAL_BOOL(&_364$$141, 0);
										}
										ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_365, 0, &_364$$141);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, _348$$135, "rewind", NULL, 0);
								zephir_check_call_status();
								_367$$135 = 1;
								while (1) {
									if (_367$$135) {
										_367$$135 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, _348$$135, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_366$$135, _348$$135, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_366$$135)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&existingRecord, _348$$135, "current", NULL, 0);
									zephir_check_call_status();
										if (UNEXPECTED(Z_TYPE_P(&intermediateReferencedFields) == IS_ARRAY)) {
											ZVAL_STRING(&keepKey, "");
											if (Z_TYPE_P(&intermediateReferencedFields) == IS_STRING) {
												ZEPHIR_INIT_NVAR(&_369$$143);
												zephir_string_to_char_array(&_369$$143, &intermediateReferencedFields);
												_368$$143 = &_369$$143;
											} else {
												_368$$143 = &intermediateReferencedFields;
											}
											zephir_is_iterable(_368$$143, 0, "phalcon/Mvc/Model.zep", 6067);
											if (Z_TYPE_P(_368$$143) == IS_ARRAY) {
												ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_368$$143), _370$$143)
												{
													ZEPHIR_INIT_NVAR(&columnB);
													ZVAL_COPY(&columnB, _370$$143);
													ZEPHIR_OBS_NVAR(&_371$$144);
													zephir_read_property_zval(&_371$$144, &existingRecord, &columnB, PH_NOISY_CC);
													ZEPHIR_INIT_NVAR(&_372$$144);
													ZEPHIR_CONCAT_VS(&_372$$144, &_371$$144, "|");
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													zephir_concat_self(&keepKey, &_372$$144);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
												} ZEND_HASH_FOREACH_END();
											} else {
												ZEPHIR_CALL_METHOD(NULL, _368$$143, "rewind", NULL, 0);
												zephir_check_call_status();
												_374$$143 = 1;
												while (1) {
													if (_374$$143) {
														_374$$143 = 0;
													} else {
														ZEPHIR_CALL_METHOD(NULL, _368$$143, "next", NULL, 0);
														zephir_check_call_status();
													}
													ZEPHIR_CALL_METHOD(&_373$$143, _368$$143, "valid", NULL, 0);
													zephir_check_call_status();
													if (!zend_is_true(&_373$$143)) {
														break;
													}
													ZEPHIR_CALL_METHOD(&columnB, _368$$143, "current", NULL, 0);
													zephir_check_call_status();
														ZEPHIR_OBS_NVAR(&_375$$145);
														zephir_read_property_zval(&_375$$145, &existingRecord, &columnB, PH_NOISY_CC);
														ZEPHIR_INIT_NVAR(&_376$$145);
														ZEPHIR_CONCAT_VS(&_376$$145, &_375$$145, "|");
														if (UNEXPECTED(EG(exception))) {
															ZEPHIR_MM_RESTORE();
															return;
														}
														zephir_concat_self(&keepKey, &_376$$145);
														if (UNEXPECTED(EG(exception))) {
															ZEPHIR_MM_RESTORE();
															return;
														}
												}
											}
											ZEPHIR_INIT_NVAR(&columnB);
										} else {
											ZEPHIR_OBS_NVAR(&_377$$146);
											zephir_read_property_zval(&_377$$146, &existingRecord, &intermediateReferencedFields, PH_NOISY_CC);
											zephir_cast_to_string(&_378$$146, &_377$$146);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_CPY_WRT(&keepKey, &_378$$146);
										}
										_379$$142 = zephir_array_isset_value(&keptKeys, &keepKey);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										_380$$142 = !(_379$$142);
										if (_380$$142) {
											ZEPHIR_CALL_METHOD(&_381$$142, &existingRecord, "delete", NULL, 0);
											zephir_check_call_status();
											_380$$142 = !zephir_is_true(&_381$$142);
										}
										if (_380$$142) {
											ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessagesFrom", &_35, 0, &existingRecord);
											zephir_check_call_status();
											if (nesting) {
												ZVAL_BOOL(&_382$$147, 1);
											} else {
												ZVAL_BOOL(&_382$$147, 0);
											}
											ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_383, 0, &_382$$147);
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
								ZEPHIR_INIT_NVAR(&_385$$149);
								zephir_string_to_char_array(&_385$$149, &relatedRecords);
								_384$$149 = &_385$$149;
							} else {
								_384$$149 = &relatedRecords;
							}
							zephir_is_iterable(_384$$149, 0, "phalcon/Mvc/Model.zep", 6107);
							if (Z_TYPE_P(_384$$149) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_384$$149), _386$$149)
								{
									ZEPHIR_INIT_NVAR(&recordAfter);
									ZVAL_COPY(&recordAfter, _386$$149);
									_389$$150 = columnCount;
									_388$$150 = 0;
									_387$$150 = 0;
									if (_388$$150 <= _389$$150) {
										while (1) {
											if (_387$$150) {
												_388$$150++;
												if (!(_388$$150 <= _389$$150)) {
													break;
												}
											} else {
												_387$$150 = 1;
											}
											i = _388$$150;
											ZEPHIR_OBS_NVAR(&columnA);
											zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 6085);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_OBS_NVAR(&columnB);
											zephir_array_fetch_long(&columnB, &referencedFields, i, PH_NOISY, "phalcon/Mvc/Model.zep", 6086);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_OBS_NVAR(&_390$$151);
											zephir_read_property_zval(&_390$$151, this_ptr, &columnA, PH_NOISY_CC);
											zephir_update_property_zval_zval(&recordAfter, &columnB, &_390$$151);
										}
									}
									ZEPHIR_CALL_METHOD(&_391$$150, &recordAfter, "doSave", NULL, 0, visited);
									zephir_check_call_status();
									if (!(zephir_is_true(&_391$$150))) {
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessagesFrom", &_35, 0, &recordAfter);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_392$$152, 1);
										} else {
											ZVAL_BOOL(&_392$$152, 0);
										}
										ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_393, 0, &_392$$152);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, _384$$149, "rewind", NULL, 0);
								zephir_check_call_status();
								_395$$149 = 1;
								while (1) {
									if (_395$$149) {
										_395$$149 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, _384$$149, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_394$$149, _384$$149, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_394$$149)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&recordAfter, _384$$149, "current", NULL, 0);
									zephir_check_call_status();
										_398$$153 = columnCount;
										_397$$153 = 0;
										_396$$153 = 0;
										if (_397$$153 <= _398$$153) {
											while (1) {
												if (_396$$153) {
													_397$$153++;
													if (!(_397$$153 <= _398$$153)) {
														break;
													}
												} else {
													_396$$153 = 1;
												}
												i = _397$$153;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 6085);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_OBS_NVAR(&columnB);
												zephir_array_fetch_long(&columnB, &referencedFields, i, PH_NOISY, "phalcon/Mvc/Model.zep", 6086);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_OBS_NVAR(&_399$$154);
												zephir_read_property_zval(&_399$$154, this_ptr, &columnA, PH_NOISY_CC);
												zephir_update_property_zval_zval(&recordAfter, &columnB, &_399$$154);
											}
										}
										ZEPHIR_CALL_METHOD(&_400$$153, &recordAfter, "doSave", NULL, 0, visited);
										zephir_check_call_status();
										if (!(zephir_is_true(&_400$$153))) {
											ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessagesFrom", &_35, 0, &recordAfter);
											zephir_check_call_status();
											if (nesting) {
												ZVAL_BOOL(&_401$$155, 1);
											} else {
												ZVAL_BOOL(&_401$$155, 0);
											}
											ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_402, 0, &_401$$155);
											zephir_check_call_status();
											RETURN_MM_BOOL(0);
										}
								}
							}
							ZEPHIR_INIT_NVAR(&recordAfter);
						} else {
							if (Z_TYPE_P(&relatedRecords) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_404$$156);
								zephir_string_to_char_array(&_404$$156, &relatedRecords);
								_403$$156 = &_404$$156;
							} else {
								_403$$156 = &relatedRecords;
							}
							zephir_is_iterable(_403$$156, 0, "phalcon/Mvc/Model.zep", 6132);
							if (Z_TYPE_P(_403$$156) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_403$$156), _405$$156)
								{
									ZEPHIR_INIT_NVAR(&recordAfter);
									ZVAL_COPY(&recordAfter, _405$$156);
									ZEPHIR_OBS_NVAR(&_406$$157);
									zephir_read_property_zval(&_406$$157, this_ptr, &columns, PH_NOISY_CC);
									zephir_update_property_zval_zval(&recordAfter, &referencedFields, &_406$$157);
									ZEPHIR_CALL_METHOD(&_407$$157, &recordAfter, "doSave", NULL, 0, visited);
									zephir_check_call_status();
									if (!(zephir_is_true(&_407$$157))) {
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessagesFrom", &_35, 0, &recordAfter);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_408$$158, 1);
										} else {
											ZVAL_BOOL(&_408$$158, 0);
										}
										ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_409, 0, &_408$$158);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, _403$$156, "rewind", NULL, 0);
								zephir_check_call_status();
								_411$$156 = 1;
								while (1) {
									if (_411$$156) {
										_411$$156 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, _403$$156, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_410$$156, _403$$156, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_410$$156)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&recordAfter, _403$$156, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_OBS_NVAR(&_412$$159);
										zephir_read_property_zval(&_412$$159, this_ptr, &columns, PH_NOISY_CC);
										zephir_update_property_zval_zval(&recordAfter, &referencedFields, &_412$$159);
										ZEPHIR_CALL_METHOD(&_413$$159, &recordAfter, "doSave", NULL, 0, visited);
										zephir_check_call_status();
										if (!(zephir_is_true(&_413$$159))) {
											ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessagesFrom", &_35, 0, &recordAfter);
											zephir_check_call_status();
											if (nesting) {
												ZVAL_BOOL(&_414$$160, 1);
											} else {
												ZVAL_BOOL(&_414$$160, 0);
											}
											ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_415, 0, &_414$$160);
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
							ZVAL_BOOL(&_416$$162, 1);
						} else {
							ZVAL_BOOL(&_416$$162, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_417, 0, &_416$$162);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_418$$162);
						object_init_ex(&_418$$162, phalcon_mvc_model_exceptions_relationnotdefined_ce);
						ZEPHIR_CALL_METHOD(NULL, &_418$$162, "__construct", &_419, 0, &className, &name);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_418$$162, "phalcon/Mvc/Model.zep", 6138);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&record);
	ZEPHIR_INIT_NVAR(&name);
	if (nesting) {
		ZVAL_BOOL(&_420, 1);
	} else {
		ZVAL_BOOL(&_420, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, connection, "commit", NULL, 0, &_420);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);
}

/**
 * Executes internal hooks before save a record
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Mvc_Model, preSave)
{
	zval _32$$32, _56$$52;
	zval eventName;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_15 = NULL, *_19 = NULL, *_35 = NULL, *_43 = NULL, *_59 = NULL, *_63 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool exists, error = 0, isNull = 0, _37$$11, _13$$17, _20$$16, _21$$23, _22$$24, _23$$27, _24$$27, _25$$27, _26$$27, _28$$33, _29$$33, _38$$37, _44$$36, _45$$43, _46$$44, _47$$47, _48$$47, _49$$47, _50$$47, _52$$53, _53$$53;
	zval *metaData, metaData_sub, *exists_param = NULL, *identityField, identityField_sub, __$true, __$false, notNull, columnMap, dataTypeNumeric, automaticAttributes, defaultValues, field, attributeField, value, emptyStringValues, _0, _1, _6, _8, _64, _68, _2$$3, _3$$3, _5$$3, _7$$8, _9$$11, _10$$11, *_11$$11, *_12$$11, _36$$11, _14$$18, _16$$18, _17$$19, _18$$19, _27$$27, _30$$32, _31$$32, _33$$32, _34$$32, _39$$38, _40$$38, _41$$39, _42$$39, _51$$47, _54$$52, _55$$52, _57$$52, _58$$52, _60$$56, _61$$56, _62$$57, _65$$58, _66$$58, _67$$59, _69$$60, _70$$60, _71$$60, _72$$60, _73$$60, _74$$60;
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
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_64);
	ZVAL_UNDEF(&_68);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_36$$11);
	ZVAL_UNDEF(&_14$$18);
	ZVAL_UNDEF(&_16$$18);
	ZVAL_UNDEF(&_17$$19);
	ZVAL_UNDEF(&_18$$19);
	ZVAL_UNDEF(&_27$$27);
	ZVAL_UNDEF(&_30$$32);
	ZVAL_UNDEF(&_31$$32);
	ZVAL_UNDEF(&_33$$32);
	ZVAL_UNDEF(&_34$$32);
	ZVAL_UNDEF(&_39$$38);
	ZVAL_UNDEF(&_40$$38);
	ZVAL_UNDEF(&_41$$39);
	ZVAL_UNDEF(&_42$$39);
	ZVAL_UNDEF(&_51$$47);
	ZVAL_UNDEF(&_54$$52);
	ZVAL_UNDEF(&_55$$52);
	ZVAL_UNDEF(&_57$$52);
	ZVAL_UNDEF(&_58$$52);
	ZVAL_UNDEF(&_60$$56);
	ZVAL_UNDEF(&_61$$56);
	ZVAL_UNDEF(&_62$$57);
	ZVAL_UNDEF(&_65$$58);
	ZVAL_UNDEF(&_66$$58);
	ZVAL_UNDEF(&_67$$59);
	ZVAL_UNDEF(&_69$$60);
	ZVAL_UNDEF(&_70$$60);
	ZVAL_UNDEF(&_71$$60);
	ZVAL_UNDEF(&_72$$60);
	ZVAL_UNDEF(&_73$$60);
	ZVAL_UNDEF(&_74$$60);
	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&_32$$32);
	ZVAL_UNDEF(&_56$$52);
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
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "fireEventCancel", &_4, 0, &_3$$3);
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
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "fireEventCancel", &_4, 0, &eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_5$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "orm.virtual_foreign_keys");
	ZEPHIR_CALL_CE_STATIC(&_6, phalcon_support_settings_ce, "get", NULL, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_6)) {
		ZEPHIR_CALL_METHOD(&_7$$8, this_ptr, "checkForeignKeysRestrict", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_7$$8)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "orm.not_null_validations");
	ZEPHIR_CALL_CE_STATIC(&_8, phalcon_support_settings_ce, "get", NULL, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_8)) {
		ZEPHIR_CALL_METHOD(&notNull, metaData, "getNotNullAttributes", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (Z_TYPE_P(&notNull) == IS_ARRAY) {
			ZEPHIR_CALL_METHOD(&dataTypeNumeric, metaData, "getDataTypesNumeric", NULL, 0, this_ptr);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_10$$11);
			ZVAL_STRING(&_10$$11, "orm.column_renaming");
			ZEPHIR_CALL_CE_STATIC(&_9$$11, phalcon_support_settings_ce, "get", NULL, 0, &_10$$11);
			zephir_check_call_status();
			if (zephir_is_true(&_9$$11)) {
				ZEPHIR_CALL_METHOD(&columnMap, metaData, "getColumnMap", NULL, 0, this_ptr);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&columnMap);
				ZVAL_NULL(&columnMap);
			}
			if (exists) {
				ZEPHIR_CALL_METHOD(&automaticAttributes, metaData, "getAutomaticUpdateAttributes", NULL, 0, this_ptr);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&automaticAttributes, metaData, "getAutomaticCreateAttributes", NULL, 0, this_ptr);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&defaultValues, metaData, "getDefaultValues", NULL, 0, this_ptr);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&emptyStringValues, metaData, "getEmptyStringAttributes", NULL, 0, this_ptr);
			zephir_check_call_status();
			error = 0;
			if (Z_TYPE_P(&notNull) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_10$$11);
				zephir_string_to_char_array(&_10$$11, &notNull);
				_11$$11 = &_10$$11;
			} else {
				_11$$11 = &notNull;
			}
			zephir_is_iterable(_11$$11, 0, "phalcon/Mvc/Model.zep", 6318);
			if (Z_TYPE_P(_11$$11) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_11$$11), _12$$11)
				{
					ZEPHIR_INIT_NVAR(&field);
					ZVAL_COPY(&field, _12$$11);
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						_13$$17 = zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (UNEXPECTED(!(_13$$17))) {
							ZEPHIR_INIT_NVAR(&_16$$18);
							ZVAL_STRING(&_16$$18, "orm.ignore_unknown_columns");
							ZEPHIR_CALL_CE_STATIC(&_14$$18, phalcon_support_settings_ce, "get", &_15, 0, &_16$$18);
							zephir_check_call_status();
							if (UNEXPECTED(!zephir_is_true(&_14$$18))) {
								ZEPHIR_INIT_NVAR(&_17$$19);
								object_init_ex(&_17$$19, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
								ZEPHIR_INIT_NVAR(&_18$$19);
								zephir_get_class(&_18$$19, this_ptr, 0);
								ZEPHIR_CALL_METHOD(NULL, &_17$$19, "__construct", &_19, 0, &field, &_18$$19);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_17$$19, "phalcon/Mvc/Model.zep", 6238);
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} else {
						ZEPHIR_CPY_WRT(&attributeField, &field);
					}
					_20$$16 = zephir_array_key_exists(&automaticAttributes, &attributeField);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_20$$16)) {
						isNull = 0;
						ZEPHIR_OBS_NVAR(&value);
						if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
							if (Z_TYPE_P(&value) != IS_OBJECT) {
								_21$$23 = zephir_array_isset_value(&dataTypeNumeric, &field);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (!(_21$$23)) {
									_22$$24 = zephir_array_isset_value(&emptyStringValues, &field);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (_22$$24) {
										if (Z_TYPE_P(&value) == IS_NULL) {
											isNull = 1;
										}
									} else {
										_23$$27 = Z_TYPE_P(&value) == IS_NULL;
										if (!(_23$$27)) {
											_24$$27 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
											if (_24$$27) {
												_25$$27 = zephir_array_isset_value(&defaultValues, &field);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												_26$$27 = !(_25$$27);
												if (!(_26$$27)) {
													ZEPHIR_OBS_NVAR(&_27$$27);
													zephir_array_fetch(&_27$$27, &defaultValues, &field, PH_NOISY, "phalcon/Mvc/Model.zep", 6268);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													_26$$27 = !ZEPHIR_IS_IDENTICAL(&value, &_27$$27);
												}
												_24$$27 = _26$$27;
											}
											_23$$27 = _24$$27;
										}
										if (_23$$27) {
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
								_28$$33 = ZEPHIR_IS_EQUAL(&field, identityField);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (_28$$33) {
									continue;
								}
								_29$$33 = zephir_array_isset_value(&defaultValues, &field);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (_29$$33) {
									continue;
								}
							}
							ZEPHIR_INIT_NVAR(&_30$$32);
							object_init_ex(&_30$$32, phalcon_messages_message_ce);
							ZEPHIR_INIT_NVAR(&_31$$32);
							ZEPHIR_CONCAT_VS(&_31$$32, &attributeField, " is required");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&_32$$32);
							zephir_create_array(&_32$$32, 1, 0);
							ZEPHIR_INIT_NVAR(&_33$$32);
							zephir_get_class(&_33$$32, this_ptr, 0);
							zephir_array_update_string(&_32$$32, SL("model"), &_33$$32, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_33$$32);
							ZVAL_STRING(&_33$$32, "PresenceOf");
							ZVAL_LONG(&_34$$32, 0);
							ZEPHIR_CALL_METHOD(NULL, &_30$$32, "__construct", &_35, 3, &_31$$32, &attributeField, &_33$$32, &_34$$32, &_32$$32);
							zephir_check_call_status();
							zephir_update_property_array_append(this_ptr, SL("errorMessages"), &_30$$32);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							error = 1;
						}
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _11$$11, "rewind", NULL, 0);
				zephir_check_call_status();
				_37$$11 = 1;
				while (1) {
					if (_37$$11) {
						_37$$11 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _11$$11, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_36$$11, _11$$11, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_36$$11)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&field, _11$$11, "current", NULL, 0);
					zephir_check_call_status();
						if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
							ZEPHIR_OBS_NVAR(&attributeField);
							_38$$37 = zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (UNEXPECTED(!(_38$$37))) {
								ZEPHIR_INIT_NVAR(&_40$$38);
								ZVAL_STRING(&_40$$38, "orm.ignore_unknown_columns");
								ZEPHIR_CALL_CE_STATIC(&_39$$38, phalcon_support_settings_ce, "get", &_15, 0, &_40$$38);
								zephir_check_call_status();
								if (UNEXPECTED(!zephir_is_true(&_39$$38))) {
									ZEPHIR_INIT_NVAR(&_41$$39);
									object_init_ex(&_41$$39, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
									ZEPHIR_INIT_NVAR(&_42$$39);
									zephir_get_class(&_42$$39, this_ptr, 0);
									ZEPHIR_CALL_METHOD(NULL, &_41$$39, "__construct", &_43, 0, &field, &_42$$39);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_41$$39, "phalcon/Mvc/Model.zep", 6238);
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
						} else {
							ZEPHIR_CPY_WRT(&attributeField, &field);
						}
						_44$$36 = zephir_array_key_exists(&automaticAttributes, &attributeField);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (!(_44$$36)) {
							isNull = 0;
							ZEPHIR_OBS_NVAR(&value);
							if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
								if (Z_TYPE_P(&value) != IS_OBJECT) {
									_45$$43 = zephir_array_isset_value(&dataTypeNumeric, &field);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (!(_45$$43)) {
										_46$$44 = zephir_array_isset_value(&emptyStringValues, &field);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										if (_46$$44) {
											if (Z_TYPE_P(&value) == IS_NULL) {
												isNull = 1;
											}
										} else {
											_47$$47 = Z_TYPE_P(&value) == IS_NULL;
											if (!(_47$$47)) {
												_48$$47 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
												if (_48$$47) {
													_49$$47 = zephir_array_isset_value(&defaultValues, &field);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													_50$$47 = !(_49$$47);
													if (!(_50$$47)) {
														ZEPHIR_OBS_NVAR(&_51$$47);
														zephir_array_fetch(&_51$$47, &defaultValues, &field, PH_NOISY, "phalcon/Mvc/Model.zep", 6268);
														if (UNEXPECTED(EG(exception))) {
															ZEPHIR_MM_RESTORE();
															return;
														}
														_50$$47 = !ZEPHIR_IS_IDENTICAL(&value, &_51$$47);
													}
													_48$$47 = _50$$47;
												}
												_47$$47 = _48$$47;
											}
											if (_47$$47) {
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
									_52$$53 = ZEPHIR_IS_EQUAL(&field, identityField);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (_52$$53) {
										continue;
									}
									_53$$53 = zephir_array_isset_value(&defaultValues, &field);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (_53$$53) {
										continue;
									}
								}
								ZEPHIR_INIT_NVAR(&_54$$52);
								object_init_ex(&_54$$52, phalcon_messages_message_ce);
								ZEPHIR_INIT_NVAR(&_55$$52);
								ZEPHIR_CONCAT_VS(&_55$$52, &attributeField, " is required");
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_INIT_NVAR(&_56$$52);
								zephir_create_array(&_56$$52, 1, 0);
								ZEPHIR_INIT_NVAR(&_57$$52);
								zephir_get_class(&_57$$52, this_ptr, 0);
								zephir_array_update_string(&_56$$52, SL("model"), &_57$$52, PH_COPY | PH_SEPARATE);
								ZEPHIR_INIT_NVAR(&_57$$52);
								ZVAL_STRING(&_57$$52, "PresenceOf");
								ZVAL_LONG(&_58$$52, 0);
								ZEPHIR_CALL_METHOD(NULL, &_54$$52, "__construct", &_59, 3, &_55$$52, &attributeField, &_57$$52, &_58$$52, &_56$$52);
								zephir_check_call_status();
								zephir_update_property_array_append(this_ptr, SL("errorMessages"), &_54$$52);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								error = 1;
							}
						}
				}
			}
			ZEPHIR_INIT_NVAR(&field);
			if (error) {
				ZEPHIR_INIT_VAR(&_61$$56);
				ZVAL_STRING(&_61$$56, "orm.events");
				ZEPHIR_CALL_CE_STATIC(&_60$$56, phalcon_support_settings_ce, "get", &_15, 0, &_61$$56);
				zephir_check_call_status();
				if (zephir_is_true(&_60$$56)) {
					ZEPHIR_INIT_VAR(&_62$$57);
					ZVAL_STRING(&_62$$57, "onValidationFails");
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireEvent", &_63, 0, &_62$$57);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "cancelOperation", NULL, 0);
					zephir_check_call_status();
				}
				RETURN_MM_BOOL(0);
			}
		}
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "validation");
	ZEPHIR_CALL_METHOD(&_64, this_ptr, "fireEventCancel", &_4, 0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_64)) {
		ZEPHIR_INIT_VAR(&_66$$58);
		ZVAL_STRING(&_66$$58, "orm.events");
		ZEPHIR_CALL_CE_STATIC(&_65$$58, phalcon_support_settings_ce, "get", &_15, 0, &_66$$58);
		zephir_check_call_status();
		if (zephir_is_true(&_65$$58)) {
			ZEPHIR_INIT_VAR(&_67$$59);
			ZVAL_STRING(&_67$$59, "onValidationFails");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireEvent", &_63, 0, &_67$$59);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "orm.events");
	ZEPHIR_CALL_CE_STATIC(&_68, phalcon_support_settings_ce, "get", &_15, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_68)) {
		if (exists) {
			ZEPHIR_INIT_NVAR(&eventName);
			ZVAL_STRING(&eventName, "afterValidationOnUpdate");
		} else {
			ZEPHIR_INIT_NVAR(&eventName);
			ZVAL_STRING(&eventName, "afterValidationOnCreate");
		}
		ZEPHIR_CALL_METHOD(&_69$$60, this_ptr, "fireEventCancel", &_4, 0, &eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_69$$60)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(&_71$$60);
		ZVAL_STRING(&_71$$60, "afterValidation");
		ZEPHIR_CALL_METHOD(&_70$$60, this_ptr, "fireEventCancel", &_4, 0, &_71$$60);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_70$$60)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(&_71$$60);
		ZVAL_STRING(&_71$$60, "beforeSave");
		ZEPHIR_CALL_METHOD(&_72$$60, this_ptr, "fireEventCancel", &_4, 0, &_71$$60);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_72$$60)) {
			RETURN_MM_BOOL(0);
		}
		if (0) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1022, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1022, &__$false);
		}
		if (exists) {
			ZEPHIR_INIT_NVAR(&eventName);
			ZVAL_STRING(&eventName, "beforeUpdate");
		} else {
			ZEPHIR_INIT_NVAR(&eventName);
			ZVAL_STRING(&eventName, "beforeCreate");
		}
		ZEPHIR_CALL_METHOD(&_73$$60, this_ptr, "fireEventCancel", &_4, 0, &eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_73$$60)) {
			RETURN_MM_BOOL(0);
		}
		zephir_read_property_cached(&_74$$60, this_ptr, _zephir_prop_0, 1022, PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_74$$60)) {
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
 *
 * @phpstan-param CollectionInterface<mixed> $visited
 */
PHP_METHOD(Phalcon_Mvc_Model, preSaveRelatedRecords)
{
	zend_string *_6;
	zend_ulong _5;
	zend_bool nesting = 0, _24, _18$$8, _35$$16;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_10 = NULL, *_13 = NULL, *_15 = NULL, *_17 = NULL, *_26 = NULL, *_28 = NULL, *_31 = NULL, *_34 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, columnCount = 0, i = 0, _19$$8, _20$$8, _36$$16, _37$$16;
	zval *connection, connection_sub, *related, related_sub, *visited, visited_sub, className, manager, type, relation, columns, referencedFields, name, record, columnA, columnB, _0, _1, *_2, _3, *_4, _23, _7$$3, _9$$6, _11$$6, _12$$6, _14$$5, _16$$7, _21$$9, _22$$10, _25$$11, _27$$14, _29$$14, _30$$14, _32$$13, _33$$15, _38$$17, _39$$18;
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
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_33$$15);
	ZVAL_UNDEF(&_38$$17);
	ZVAL_UNDEF(&_39$$18);
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
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getModelsManager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_1);
	if (Z_TYPE_P(related) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_3);
		zephir_string_to_char_array(&_3, related);
		_2 = &_3;
	} else {
		_2 = related;
	}
	zephir_is_iterable(_2, 0, "phalcon/Mvc/Model.zep", 6483);
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
			ZEPHIR_CALL_METHOD(&_7$$3, &manager, "getRelationByAlias", &_8, 0, &className, &name);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&relation, &_7$$3);
			if (Z_TYPE_P(&relation) == IS_OBJECT) {
				ZEPHIR_CALL_METHOD(&type, &relation, "getType", NULL, 0);
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
						zephir_throw_exception_debug(&_11$$6, "phalcon/Mvc/Model.zep", 6440);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_14$$5, &record, "doSave", NULL, 0, visited);
					zephir_check_call_status();
					if (!(zephir_is_true(&_14$$5))) {
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessagesFrom", &_15, 0, &record);
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
					ZEPHIR_CALL_METHOD(&columns, &relation, "getFields", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getReferencedFields", NULL, 0);
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
								ZEPHIR_OBS_NVAR(&columnA);
								zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 6472);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&columnB);
								zephir_array_fetch_long(&columnB, &referencedFields, i, PH_NOISY, "phalcon/Mvc/Model.zep", 6473);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
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
				ZEPHIR_CALL_METHOD(&_25$$11, &manager, "getRelationByAlias", &_26, 0, &className, &name);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&relation, &_25$$11);
				if (Z_TYPE_P(&relation) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&type, &relation, "getType", NULL, 0);
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
							ZEPHIR_CALL_METHOD(NULL, &_29$$14, "__construct", &_31, 0, &_30$$14, &name);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_29$$14, "phalcon/Mvc/Model.zep", 6440);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD(&_32$$13, &record, "doSave", NULL, 0, visited);
						zephir_check_call_status();
						if (!(zephir_is_true(&_32$$13))) {
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessagesFrom", &_15, 0, &record);
							zephir_check_call_status();
							if (nesting) {
								ZVAL_BOOL(&_33$$15, 1);
							} else {
								ZVAL_BOOL(&_33$$15, 0);
							}
							ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_34, 0, &_33$$15);
							zephir_check_call_status();
							RETURN_MM_BOOL(0);
						}
						ZEPHIR_CALL_METHOD(&columns, &relation, "getFields", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getReferencedFields", NULL, 0);
						zephir_check_call_status();
						if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
							columnCount = (zephir_fast_count_int(&columns) - 1);
							_37$$16 = columnCount;
							_36$$16 = 0;
							_35$$16 = 0;
							if (_36$$16 <= _37$$16) {
								while (1) {
									if (_35$$16) {
										_36$$16++;
										if (!(_36$$16 <= _37$$16)) {
											break;
										}
									} else {
										_35$$16 = 1;
									}
									i = _36$$16;
									ZEPHIR_OBS_NVAR(&columnA);
									zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 6472);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_OBS_NVAR(&columnB);
									zephir_array_fetch_long(&columnB, &referencedFields, i, PH_NOISY, "phalcon/Mvc/Model.zep", 6473);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_OBS_NVAR(&_38$$17);
									zephir_read_property_zval(&_38$$17, &record, &columnB, PH_NOISY_CC);
									zephir_update_property_zval_zval(this_ptr, &columnA, &_38$$17);
								}
							}
						} else {
							ZEPHIR_OBS_NVAR(&_39$$18);
							zephir_read_property_zval(&_39$$18, &record, &referencedFields, PH_NOISY_CC);
							zephir_update_property_zval_zval(this_ptr, &columns, &_39$$18);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setModelSchema", NULL, 0, this_ptr, &schema_zv);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setModelSource", NULL, 0, this_ptr, &source_zv);
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
 *
 * @phpstan-param mvc_model_attributes $attributes
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "skipAttributesOnCreate", NULL, 0, &attributes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "skipAttributesOnUpdate", NULL, 0, &attributes);
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
 *
 * @phpstan-param mvc_model_attributes $attributes
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
	zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model.zep", 6566);
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _0)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _0);
			zephir_array_update_zval(&keysAttributes, &attribute, &__$null, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
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
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&attribute);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getModelsMetaData", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_3, "setAutomaticCreateAttributes", NULL, 0, this_ptr, &keysAttributes);
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
 *
 * @phpstan-param mvc_model_attributes $attributes
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
	zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model.zep", 6603);
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _0)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _0);
			zephir_array_update_zval(&keysAttributes, &attribute, &__$null, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
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
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&attribute);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getModelsMetaData", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_3, "setAutomaticUpdateAttributes", NULL, 0, this_ptr, &keysAttributes);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	if (dynamicUpdate) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "useDynamicUpdate", NULL, 0, this_ptr, &_1);
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
		ZEPHIR_CALL_METHOD(&_3$$4, &message, "getMessage", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$4, &message, "getField", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5$$4, &message, "getType", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_6$$4, &message, "getCode", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_7$$4, &message, "getMetaData", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", &_8, 3, &_3$$4, &_4$$4, &_5$$4, &_6$$4, &_7$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendMessage", &_9, 0, &_2$$4);
		zephir_check_call_status();
	}
	zend_iterator_dtor(_1);
	}
	RETURN_MM_BOOL(!(zephir_fast_count_int(&messages)));
}

zend_object *zephir_init_properties_Phalcon_Mvc_Model(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("uniqueParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("uniqueParams"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

