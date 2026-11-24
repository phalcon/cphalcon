
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
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
		ZEPHIR_CALL_CE_STATIC_CACHED(container, phalcon_di_di_ce, "getDefault", &_zephir_call_cache[0]);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$4);
		object_init_ex(&_0$$4, phalcon_mvc_model_exceptions_modelormservicesunavailable_ce);
		zephir_constructor_start(&_0$$4);
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_get_class(&_1$$4, this_ptr, 0);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_0$$4, "__construct", &_zephir_call_cache[1], &_1$$4);
		zephir_check_call_status();
		zephir_constructor_finish(&_0$$4);
		zephir_throw_exception_debug(&_0$$4, "phalcon/Mvc/Model.zep", 277);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1013, container);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(modelsManager) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_3$$5);
		ZVAL_STRING(&_3$$5, "modelsManager");
		ZEPHIR_CALL_METHOD_CACHED(&_2$$5, container, "getShared", &_zephir_call_cache[2], &_3$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(modelsManager, &_2$$5);
		if (Z_TYPE_P(modelsManager) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_4$$6);
			object_init_ex(&_4$$6, phalcon_mvc_model_exceptions_invalidmodelsmanagerservice_ce);
			zephir_constructor_start(&_4$$6);
			ZEPHIR_INIT_VAR(&_5$$6);
			zephir_get_class(&_5$$6, this_ptr, 0);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_4$$6, "__construct", &_zephir_call_cache[3], &_5$$6);
			zephir_check_call_status();
			zephir_constructor_finish(&_4$$6);
			zephir_throw_exception_debug(&_4$$6, "phalcon/Mvc/Model.zep", 288);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1014, modelsManager);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, modelsManager, "initialize", &_zephir_call_cache[4], this_ptr);
	zephir_check_call_status();
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("onconstruct")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "onConstruct", &_zephir_call_cache[5], data);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(data) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "assign", &_zephir_call_cache[6], data);
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
	zval arguments;
	zval method_zv, *arguments_param = NULL, modelName, status, records, _0, _1;
	zend_string *method = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&arguments);
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
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
	ZEPHIR_CALL_SELF_CACHED(&records, "invokeFinder", &_zephir_call_cache[0], &method_zv, &arguments);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&records)) {
		RETURN_CCTOR(&records);
	}
	ZEPHIR_INIT_VAR(&modelName);
	zephir_get_class(&modelName, this_ptr, 0);
	ZEPHIR_CALL_METHOD_CACHED(&records, this_ptr, "getRelatedRecords", &_zephir_call_cache[1], &modelName, &method_zv, &arguments);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&records)) {
		RETURN_CCTOR(&records);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&status, &_0, "missingMethod", &_zephir_call_cache[2], this_ptr, &method_zv, &arguments);
	zephir_check_call_status();
	if (Z_TYPE_P(&status) != IS_NULL) {
		RETURN_CCTOR(&status);
	}
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalcon_mvc_model_exceptions_methodnotfound_ce);
	zephir_constructor_start(&_1);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_1, "__construct", &_zephir_call_cache[3], &method_zv, &modelName);
	zephir_check_call_status();
	zephir_constructor_finish(&_1);
	zephir_throw_exception_debug(&_1, "phalcon/Mvc/Model.zep", 357);
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
	zval arguments;
	zval method_zv, *arguments_param = NULL, modelName, records, _0;
	zend_string *method = NULL;

	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&arguments);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
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
	ZEPHIR_CALL_SELF_CACHED(&records, "invokeFinder", &_zephir_call_cache[0], &method_zv, &arguments);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&records)) {
		RETURN_CCTOR(&records);
	}
	ZEPHIR_INIT_VAR(&modelName);
	zephir_get_called_class(&modelName);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_mvc_model_exceptions_methodnotfound_ce);
	zephir_constructor_start(&_0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[1], &method_zv, &modelName);
	zephir_check_call_status();
	zephir_constructor_finish(&_0);
	zephir_throw_exception_debug(&_0, "phalcon/Mvc/Model.zep", 384);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
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
	ZEPHIR_CALL_METHOD_CACHED(&manager, this_ptr, "getModelsManager", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&lowerProperty);
	zephir_fast_strtolower(&lowerProperty, &property_zv);
	ZEPHIR_CALL_METHOD_CACHED(&_0, &manager, "getRelationByAlias", &_zephir_call_cache[1], &modelName, &lowerProperty);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&relation, &_0);
	if (Z_TYPE_P(&relation) == IS_OBJECT) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 1015, PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_2$$3 = zephir_array_isset_value(&_1$$3, &lowerProperty);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_2$$3) {
			zephir_read_property_cached(&_3$$4, this_ptr, _zephir_prop_0, 1015, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_memory_observe(&_4$$4);
			zephir_array_fetch(&_4$$4, &_3$$4, &lowerProperty, PH_NOISY, "phalcon/Mvc/Model.zep", 415);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_CCTOR(&_4$$4);
		}
		zephir_read_property_cached(&_5$$3, this_ptr, _zephir_prop_1, 1016, PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_6$$3 = zephir_array_isset_value(&_5$$3, &lowerProperty);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_7$$3 = _6$$3;
		if (_7$$3) {
			ZEPHIR_CALL_METHOD_CACHED(&_8$$3, &relation, "isReusable", &_zephir_call_cache[2]);
			zephir_check_call_status();
			_7$$3 = !zephir_is_true(&_8$$3);
		}
		_9$$3 = _7$$3;
		if (_9$$3) {
			zephir_read_property_cached(&_10$$3, this_ptr, _zephir_prop_1, 1016, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
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
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
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
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_memory_observe(&_16$$5);
			zephir_array_fetch(&_16$$5, &_15$$5, &lowerProperty, PH_NOISY, "phalcon/Mvc/Model.zep", 428);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_CCTOR(&_16$$5);
		}
		ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getRelated", &_zephir_call_cache[3], &lowerProperty);
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
	ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 8, &_19);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(property)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&property_zv);
	ZVAL_STR_COPY(&property_zv, property);
	ZEPHIR_INIT_VAR(&modelName);
	zephir_get_class(&modelName, this_ptr, 0);
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getModelsManager", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD_CACHED(&_0, &manager, "getRelationByAlias", &_zephir_call_cache[1], &modelName, &property_zv);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
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
	ZEPHIR_CALL_METHOD_CACHED(&attributes, this_ptr, "toArray", &_zephir_call_cache[0], &_0, &_1);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1017, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&dirtyState, &_0);
	ZEPHIR_CALL_METHOD_CACHED(&_2, this_ptr, "getModelsManager", &_zephir_call_cache[1]);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_2);
	ZEPHIR_CALL_METHOD_CACHED(&_2, &manager, "isKeepingSnapshots", &_zephir_call_cache[2], this_ptr);
	zephir_check_call_status();
	_3 = zephir_is_true(&_2);
	if (_3) {
		zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1018, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_3 = Z_TYPE_P(&_0) != IS_NULL;
	}
	_4 = _3;
	if (_4) {
		zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 1018, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_5 = !ZEPHIR_IS_EQUAL(&attributes, &_1);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_4 = _5;
	}
	if (_4) {
		zephir_read_property_cached(&_6$$3, this_ptr, _zephir_prop_1, 1018, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
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
	zend_bool _0, _4$$4, _13$$10, _14$$10;
	zval related;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval property_zv, *value, value_sub, __$null, lowerProperty, modelName, manager, relation, referencedModel, item, dirtyState, _19, _20, _1$$3, _2$$4, _3$$4, _5$$6, _6$$7, _7$$8, _8$$9, *_9$$10, _10$$10, *_11$$10, _12$$10, _15$$10, _16$$17, _17$$19, _18$$20, _21$$22, _22$$23, _23$$23;
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
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$17);
	ZVAL_UNDEF(&_17$$19);
	ZVAL_UNDEF(&_18$$20);
	ZVAL_UNDEF(&_21$$22);
	ZVAL_UNDEF(&_22$$23);
	ZVAL_UNDEF(&_23$$23);
	ZVAL_UNDEF(&related);
	ZEND_TLS zephir_method_cache _zephir_call_cache[21];
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
		ZEPHIR_CALL_METHOD_CACHED(&manager, this_ptr, "getModelsManager", &_zephir_call_cache[0]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_1$$3, &manager, "getRelationByAlias", &_zephir_call_cache[1], &modelName, &lowerProperty);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_1$$3);
		if (Z_TYPE_P(&relation) == IS_OBJECT) {
			zephir_read_property_cached(&_2$$4, this_ptr, _zephir_prop_0, 1017, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CPY_WRT(&dirtyState, &_2$$4);
			ZEPHIR_CALL_METHOD_CACHED(&_3$$4, value, "getDirtyState", &_zephir_call_cache[2]);
			zephir_check_call_status();
			_4$$4 = !ZEPHIR_IS_EQUAL(&_3$$4, &dirtyState);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_4$$4) {
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
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETVAL_ZVAL(value, 1, 0);
			RETURN_MM();
		}
	} else if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&lowerProperty);
		zephir_fast_strtolower(&lowerProperty, &property_zv);
		ZEPHIR_INIT_NVAR(&modelName);
		zephir_get_class(&modelName, this_ptr, 0);
		ZEPHIR_CALL_METHOD_CACHED(&manager, this_ptr, "getModelsManager", &_zephir_call_cache[3]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_5$$6, &manager, "getRelationByAlias", &_zephir_call_cache[4], &modelName, &lowerProperty);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_5$$6);
		if (Z_TYPE_P(&relation) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD_CACHED(&_6$$7, &relation, "getType", &_zephir_call_cache[5]);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG(&_6$$7, 0)) { goto zephir_switch_0_clause_0; }
			if (ZEPHIR_IS_LONG(&_6$$7, 1)) { goto zephir_switch_0_clause_1; }
			if (ZEPHIR_IS_LONG(&_6$$7, 2)) { goto zephir_switch_0_clause_2; }
			if (ZEPHIR_IS_LONG(&_6$$7, 4)) { goto zephir_switch_0_clause_3; }
			goto zephir_switch_0_end;
			zephir_switch_0_clause_0: ;
			zephir_switch_0_clause_1: ;
				ZEPHIR_CALL_METHOD_CACHED(&_7$$8, &relation, "getReferencedModel", &_zephir_call_cache[6]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&referencedModel, &manager, "load", &_zephir_call_cache[7], &_7$$8);
				zephir_check_call_status();
				if (Z_TYPE_P(&referencedModel) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD_CACHED(NULL, &referencedModel, "assign", &_zephir_call_cache[8], value);
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
					ZVAL_UNDEF(&_8$$9);
					ZVAL_LONG(&_8$$9, 1);
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1017, &_8$$9);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
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
				zephir_is_iterable(_9$$10, 0, "phalcon/Mvc/Model.zep", 601);
				if (Z_TYPE_P(_9$$10) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_9$$10), _11$$10)
					{
						ZEPHIR_INIT_NVAR(&item);
						ZVAL_COPY(&item, _11$$10);
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
					ZEPHIR_CALL_METHOD_CACHED(NULL, _9$$10, "rewind", &_zephir_call_cache[9]);
					zephir_check_call_status();
					_13$$10 = 1;
					while (1) {
						if (_13$$10) {
							_13$$10 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _9$$10, "next", &_zephir_call_cache[10]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_12$$10, _9$$10, "valid", &_zephir_call_cache[11]);
						zephir_check_call_status();
						if (!zend_is_true(&_12$$10)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&item, _9$$10, "current", &_zephir_call_cache[12]);
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
				zephir_unset_property_array(this_ptr, ZEND_STRL("related"), &lowerProperty);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_14$$10 = !(ZEPHIR_IS_EMPTY(&related));
				if (!(_14$$10)) {
					ZEPHIR_CALL_METHOD_CACHED(&_15$$10, &relation, "getType", &_zephir_call_cache[13]);
					zephir_check_call_status();
					_14$$10 = ZEPHIR_IS_LONG_IDENTICAL(&_15$$10, 4);
				}
				if (_14$$10) {
					zephir_update_property_array(this_ptr, SL("dirtyRelated"), &lowerProperty, &related);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZVAL_UNDEF(&_16$$17);
					ZVAL_LONG(&_16$$17, 1);
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1017, &_16$$17);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
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
		ZEPHIR_CALL_METHOD_CACHED(&manager, this_ptr, "getModelsManager", &_zephir_call_cache[14]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_17$$19, &manager, "getRelationByAlias", &_zephir_call_cache[15], &modelName, &lowerProperty);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_17$$19);
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
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZVAL_NULL(&_18$$20);
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "possibleSetter", &_zephir_call_cache[16], &property_zv, &_18$$20);
			zephir_check_call_status();
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&_19, this_ptr, "possibleSetter", &_zephir_call_cache[17], &property_zv, value);
	zephir_check_call_status();
	if (zephir_is_true(&_19)) {
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_20, "property_exists", NULL, 7, this_ptr, &property_zv);
	zephir_check_call_status();
	if (zephir_is_true(&_20)) {
		ZEPHIR_CALL_METHOD_CACHED(&manager, this_ptr, "getModelsManager", &_zephir_call_cache[18]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_21$$22, &manager, "isVisibleModelProperty", &_zephir_call_cache[19], this_ptr, &property_zv);
		zephir_check_call_status();
		if (UNEXPECTED(!zephir_is_true(&_21$$22))) {
			ZEPHIR_INIT_VAR(&_22$$23);
			object_init_ex(&_22$$23, phalcon_mvc_model_exceptions_propertynotaccessible_ce);
			zephir_constructor_start(&_22$$23);
			ZEPHIR_INIT_VAR(&_23$$23);
			zephir_get_class(&_23$$23, this_ptr, 0);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_22$$23, "__construct", &_zephir_call_cache[20], &property_zv, &_23$$23);
			zephir_check_call_status();
			zephir_constructor_finish(&_22$$23);
			zephir_throw_exception_debug(&_22$$23, "phalcon/Mvc/Model.zep", 666);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_update_property_zval_zval(this_ptr, &property_zv, value);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[12];
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
	ZEPHIR_CALL_CE_STATIC_CACHED(&container, phalcon_di_di_ce, "getDefault", &_zephir_call_cache[0]);
	zephir_check_call_status();
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_mvc_model_exceptions_modelormservicesunavailable_ce);
		zephir_constructor_start(&_2$$4);
		ZEPHIR_INIT_VAR(&_3$$4);
		zephir_get_class(&_3$$4, this_ptr, 0);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$4, "__construct", &_zephir_call_cache[1], &_3$$4);
		zephir_check_call_status();
		zephir_constructor_finish(&_2$$4);
		zephir_throw_exception_debug(&_2$$4, "phalcon/Mvc/Model.zep", 695);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1013, &container);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "modelsManager");
	ZEPHIR_CALL_METHOD_CACHED(&_4, &container, "getShared", &_zephir_call_cache[2], &_5);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_4);
	if (Z_TYPE_P(&manager) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_6$$5);
		object_init_ex(&_6$$5, phalcon_mvc_model_exceptions_invalidmodelsmanagerservice_ce);
		zephir_constructor_start(&_6$$5);
		ZEPHIR_INIT_VAR(&_7$$5);
		zephir_get_class(&_7$$5, this_ptr, 0);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_6$$5, "__construct", &_zephir_call_cache[3], &_7$$5);
		zephir_check_call_status();
		zephir_constructor_finish(&_6$$5);
		zephir_throw_exception_debug(&_6$$5, "phalcon/Mvc/Model.zep", 708);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1014, &manager);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &manager, "initialize", &_zephir_call_cache[4], this_ptr);
	zephir_check_call_status();
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("onconstruct")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "onConstruct", &_zephir_call_cache[5]);
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
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _9$$7, "rewind", &_zephir_call_cache[6]);
			zephir_check_call_status();
			_15$$7 = 1;
			while (1) {
				if (_15$$7) {
					_15$$7 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _9$$7, "next", &_zephir_call_cache[7]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_14$$7, _9$$7, "valid", &_zephir_call_cache[8]);
				zephir_check_call_status();
				if (!zend_is_true(&_14$$7)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&key, _9$$7, "key", &_zephir_call_cache[9]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&value, _9$$7, "current", &_zephir_call_cache[10]);
				zephir_check_call_status();
					zephir_update_property_zval_zval(this_ptr, &key, &value);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
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
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&_4, &manager, "isKeepingSnapshots", &_zephir_call_cache[11], this_ptr);
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
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1018, &properties);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[15];
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
		ZEPHIR_CALL_CE_STATIC_CACHED(NULL, phalcon_support_settings_ce, "set", &_zephir_call_cache[0], &_1$$3, &_2$$3);
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
		ZEPHIR_CALL_CE_STATIC_CACHED(NULL, phalcon_support_settings_ce, "set", &_zephir_call_cache[1], &_4$$4, &_5$$4);
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
		ZEPHIR_CALL_CE_STATIC_CACHED(NULL, phalcon_support_settings_ce, "set", &_zephir_call_cache[2], &_7$$5, &_8$$5);
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
		ZEPHIR_CALL_CE_STATIC_CACHED(NULL, phalcon_support_settings_ce, "set", &_zephir_call_cache[3], &_10$$6, &_11$$6);
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
		ZEPHIR_CALL_CE_STATIC_CACHED(NULL, phalcon_support_settings_ce, "set", &_zephir_call_cache[4], &_13$$7, &_14$$7);
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
		ZEPHIR_CALL_CE_STATIC_CACHED(NULL, phalcon_support_settings_ce, "set", &_zephir_call_cache[5], &_16$$8, &_17$$8);
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
		ZEPHIR_CALL_CE_STATIC_CACHED(NULL, phalcon_support_settings_ce, "set", &_zephir_call_cache[6], &_19$$9, &_20$$9);
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
		ZEPHIR_CALL_CE_STATIC_CACHED(NULL, phalcon_support_settings_ce, "set", &_zephir_call_cache[7], &_22$$10, &_23$$10);
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
		ZEPHIR_CALL_CE_STATIC_CACHED(NULL, phalcon_support_settings_ce, "set", &_zephir_call_cache[8], &_25$$11, &_26$$11);
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
		ZEPHIR_CALL_CE_STATIC_CACHED(NULL, phalcon_support_settings_ce, "set", &_zephir_call_cache[9], &_28$$12, &_29$$12);
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
		ZEPHIR_CALL_CE_STATIC_CACHED(NULL, phalcon_support_settings_ce, "set", &_zephir_call_cache[10], &_31$$13, &_32$$13);
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
		ZEPHIR_CALL_CE_STATIC_CACHED(NULL, phalcon_support_settings_ce, "set", &_zephir_call_cache[11], &_34$$14, &_35$$14);
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
		ZEPHIR_CALL_CE_STATIC_CACHED(NULL, phalcon_support_settings_ce, "set", &_zephir_call_cache[12], &_37$$15, &_38$$15);
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
		ZEPHIR_CALL_CE_STATIC_CACHED(NULL, phalcon_support_settings_ce, "set", &_zephir_call_cache[13], &_40$$16, &_41$$16);
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
		ZEPHIR_CALL_CE_STATIC_CACHED(NULL, phalcon_support_settings_ce, "set", &_zephir_call_cache[14], &_43$$17, &_44$$17);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_CALL_SELF_CACHED(&result, "groupResult", &_zephir_call_cache[0], &_0, &_1, &parameters);
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
	zend_long dirtyState = 0, ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *base, base_sub, *data_param = NULL, *dirtyState_param = NULL, _0;

	ZVAL_UNDEF(&base_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&data);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZVAL_LONG(&_0, dirtyState);
	ZEPHIR_RETURN_CALL_CE_STATIC_CACHED(phalcon_mvc_model_hydration_cloneresult_ce, "cloneResult", &_zephir_call_cache[0], base, &data, &_0);
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
	zephir_fcall_cache_entry *_37 = NULL, *_38 = NULL;
	zend_bool keepSnapshots = 0, callSetters = 0, _51, _8$$6, _10$$13, _11$$13, _14$$16, _15$$12, _16$$4, _34$$4, _49$$4, _17$$22, _18$$23, _28$$30, _29$$30, _32$$33, _33$$29, _44$$51, _45$$51, _48$$54, _52$$62, _54$$69, _55$$69, _58$$72, _59$$68, _60$$60, _78$$60, _91$$60, _61$$78, _62$$79, _72$$86, _73$$86, _76$$89, _77$$85, _86$$107, _87$$107, _90$$110;
	zend_long dirtyState = 0, ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *base, base_sub, *data_param = NULL, *columnMap, columnMap_sub, *dirtyState_param = NULL, *keepSnapshots_param = NULL, instance, attribute, key, value, castValue, attributeName, metaData, reverseMap, notNullAttributes, privateProperties, reflectionProperty, setter, localMethods, _0, _1, _2, _3, *_5, _50, _4$$3, _9$$13, _12$$14, _13$$14, _19$$25, _20$$25, _21$$26, _22$$26, _23$$27, _24$$27, _25$$28, _26$$28, _27$$30, _30$$31, _31$$31, _35$$39, _36$$40, _39$$44, _40$$43, _41$$43, _42$$48, _43$$51, _46$$52, _47$$52, _53$$69, _56$$70, _57$$70, _63$$81, _64$$81, _65$$82, _66$$82, _67$$83, _68$$83, _69$$84, _70$$84, _71$$86, _74$$87, _75$$87, _79$$95, _80$$96, _81$$100, _82$$99, _83$$99, _84$$104, _85$$107, _88$$108, _89$$108, _92$$116, _93$$117;

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
	ZVAL_UNDEF(&_50);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_9$$13);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_19$$25);
	ZVAL_UNDEF(&_20$$25);
	ZVAL_UNDEF(&_21$$26);
	ZVAL_UNDEF(&_22$$26);
	ZVAL_UNDEF(&_23$$27);
	ZVAL_UNDEF(&_24$$27);
	ZVAL_UNDEF(&_25$$28);
	ZVAL_UNDEF(&_26$$28);
	ZVAL_UNDEF(&_27$$30);
	ZVAL_UNDEF(&_30$$31);
	ZVAL_UNDEF(&_31$$31);
	ZVAL_UNDEF(&_35$$39);
	ZVAL_UNDEF(&_36$$40);
	ZVAL_UNDEF(&_39$$44);
	ZVAL_UNDEF(&_40$$43);
	ZVAL_UNDEF(&_41$$43);
	ZVAL_UNDEF(&_42$$48);
	ZVAL_UNDEF(&_43$$51);
	ZVAL_UNDEF(&_46$$52);
	ZVAL_UNDEF(&_47$$52);
	ZVAL_UNDEF(&_53$$69);
	ZVAL_UNDEF(&_56$$70);
	ZVAL_UNDEF(&_57$$70);
	ZVAL_UNDEF(&_63$$81);
	ZVAL_UNDEF(&_64$$81);
	ZVAL_UNDEF(&_65$$82);
	ZVAL_UNDEF(&_66$$82);
	ZVAL_UNDEF(&_67$$83);
	ZVAL_UNDEF(&_68$$83);
	ZVAL_UNDEF(&_69$$84);
	ZVAL_UNDEF(&_70$$84);
	ZVAL_UNDEF(&_71$$86);
	ZVAL_UNDEF(&_74$$87);
	ZVAL_UNDEF(&_75$$87);
	ZVAL_UNDEF(&_79$$95);
	ZVAL_UNDEF(&_80$$96);
	ZVAL_UNDEF(&_81$$100);
	ZVAL_UNDEF(&_82$$99);
	ZVAL_UNDEF(&_83$$99);
	ZVAL_UNDEF(&_84$$104);
	ZVAL_UNDEF(&_85$$107);
	ZVAL_UNDEF(&_88$$108);
	ZVAL_UNDEF(&_89$$108);
	ZVAL_UNDEF(&_92$$116);
	ZVAL_UNDEF(&_93$$117);
	ZVAL_UNDEF(&data);
	ZEND_TLS zephir_method_cache _zephir_call_cache[44];
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
	ZEPHIR_INIT_VAR(&localMethods);
	ZVAL_NULL(&localMethods);
	ZEPHIR_INIT_VAR(&instance);
	if (zephir_clone(&instance, base) == FAILURE) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, &instance, 0);
	ZEPHIR_CALL_CE_STATIC_CACHED(&privateProperties, phalcon_mvc_model_hydration_getprivateproperties_ce, "getPrivateProperties", &_zephir_call_cache[0], &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&metaData);
	ZVAL_NULL(&metaData);
	ZEPHIR_INIT_VAR(&notNullAttributes);
	ZVAL_NULL(&notNullAttributes);
	ZVAL_LONG(&_1, dirtyState);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &instance, "setDirtyState", &_zephir_call_cache[1], &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "orm.call_setters_on_hydration");
	ZEPHIR_CALL_CE_STATIC_CACHED(&_2, phalcon_support_settings_ce, "get", &_zephir_call_cache[2], &_3);
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
							ZEPHIR_CALL_METHOD_CACHED(&metaData, &instance, "getModelsMetaData", &_zephir_call_cache[3]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&notNullAttributes, &metaData, "getNotNullAttributes", &_zephir_call_cache[4], &instance);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(&notNullAttributes);
						array_init(&notNullAttributes);
					}
				}
				_8$$6 = zephir_fast_in_array(&key, &notNullAttributes);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_8$$6) {
					continue;
				}
			}
			if (Z_TYPE_P(columnMap) != IS_ARRAY) {
				if (callSetters) {
					ZEPHIR_INIT_NVAR(&_9$$13);
					zephir_camelize(&_9$$13, &key, NULL );
					ZEPHIR_INIT_NVAR(&setter);
					ZEPHIR_CONCAT_SV(&setter, "set", &_9$$13);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_10$$13 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
					if (_10$$13) {
						_11$$13 = zephir_array_isset_value(&localMethods, &setter);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_10$$13 = !(_11$$13);
					}
					if (_10$$13) {

						/* try_start_1: */

							ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &value);
							zephir_check_call_status_or_jump(try_end_1);

						try_end_1:

						if (EG(exception)) {
							ZEPHIR_INIT_NVAR(&_12$$14);
							ZVAL_OBJ(&_12$$14, EG(exception));
							Z_ADDREF_P(&_12$$14);
							ZEPHIR_INIT_NVAR(&_13$$14);
							if (zephir_is_instance_of(&_12$$14, SL("TypeError"))) {
								zend_clear_exception();
								ZEPHIR_CPY_WRT(&_13$$14, &_12$$14);
								_14$$16 = zephir_array_isset_value(&privateProperties, &key);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (UNEXPECTED(_14$$16)) {
									ZEPHIR_OBS_NVAR(&reflectionProperty);
									zephir_array_fetch(&reflectionProperty, &privateProperties, &key, PH_NOISY, "phalcon/Mvc/Model.zep", 1055);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_METHOD_CACHED(NULL, &reflectionProperty, "setValue", &_zephir_call_cache[5], &instance, &value);
									zephir_check_call_status();
								} else {
									zephir_update_property_zval_zval(&instance, &key, &value);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
							} else {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
						continue;
					}
				}
				_15$$12 = zephir_array_isset_value(&privateProperties, &key);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(_15$$12)) {
					ZEPHIR_OBS_NVAR(&reflectionProperty);
					zephir_array_fetch(&reflectionProperty, &privateProperties, &key, PH_NOISY, "phalcon/Mvc/Model.zep", 1067);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, &reflectionProperty, "setValue", &_zephir_call_cache[6], &instance, &value);
					zephir_check_call_status();
				} else {
					zephir_update_property_zval_zval(&instance, &key, &value);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				continue;
			}
			ZEPHIR_OBS_NVAR(&attribute);
			_16$$4 = zephir_array_isset_fetch(&attribute, columnMap, &key, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_16$$4)) {
				_17$$22 = Z_TYPE_P(columnMap) == IS_ARRAY;
				if (_17$$22) {
					_17$$22 = !(ZEPHIR_IS_EMPTY(columnMap));
				}
				if (_17$$22) {
					if (Z_TYPE_P(&metaData) == IS_NULL) {
						ZEPHIR_CALL_METHOD_CACHED(&metaData, &instance, "getModelsMetaData", &_zephir_call_cache[7]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&reverseMap, &metaData, "getReverseColumnMap", &_zephir_call_cache[8], &instance);
					zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&attribute);
					_18$$23 = zephir_array_isset_fetch(&attribute, &reverseMap, &key, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_18$$23)) {
						ZEPHIR_INIT_NVAR(&_20$$25);
						ZVAL_STRING(&_20$$25, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC_CACHED(&_19$$25, phalcon_support_settings_ce, "get", &_zephir_call_cache[9], &_20$$25);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_19$$25))) {
							ZEPHIR_INIT_NVAR(&_21$$26);
							object_init_ex(&_21$$26, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							zephir_constructor_start(&_21$$26);
							ZEPHIR_INIT_NVAR(&_22$$26);
							zephir_get_class(&_22$$26, base, 0);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_21$$26, "__construct", &_zephir_call_cache[10], &key, &_22$$26);
							zephir_check_call_status();
							zephir_constructor_finish(&_21$$26);
							zephir_throw_exception_debug(&_21$$26, "phalcon/Mvc/Model.zep", 1086);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
				} else {
					ZEPHIR_INIT_NVAR(&_24$$27);
					ZVAL_STRING(&_24$$27, "orm.ignore_unknown_columns");
					ZEPHIR_CALL_CE_STATIC_CACHED(&_23$$27, phalcon_support_settings_ce, "get", &_zephir_call_cache[11], &_24$$27);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&_23$$27))) {
						ZEPHIR_INIT_NVAR(&_25$$28);
						object_init_ex(&_25$$28, phalcon_mvc_model_exceptions_columnnotinmap_ce);
						zephir_constructor_start(&_25$$28);
						ZEPHIR_INIT_NVAR(&_26$$28);
						zephir_get_class(&_26$$28, base, 0);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_25$$28, "__construct", &_zephir_call_cache[12], &key, &_26$$28);
						zephir_check_call_status();
						zephir_constructor_finish(&_25$$28);
						zephir_throw_exception_debug(&_25$$28, "phalcon/Mvc/Model.zep", 1093);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
			}
			if (Z_TYPE_P(&attribute) != IS_ARRAY) {
				if (callSetters) {
					ZEPHIR_INIT_NVAR(&_27$$30);
					zephir_camelize(&_27$$30, &attribute, NULL );
					ZEPHIR_INIT_NVAR(&setter);
					ZEPHIR_CONCAT_SV(&setter, "set", &_27$$30);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_28$$30 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
					if (_28$$30) {
						_29$$30 = zephir_array_isset_value(&localMethods, &setter);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_28$$30 = !(_29$$30);
					}
					if (_28$$30) {

						/* try_start_2: */

							ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &value);
							zephir_check_call_status_or_jump(try_end_2);

						try_end_2:

						if (EG(exception)) {
							ZEPHIR_INIT_NVAR(&_30$$31);
							ZVAL_OBJ(&_30$$31, EG(exception));
							Z_ADDREF_P(&_30$$31);
							ZEPHIR_INIT_NVAR(&_31$$31);
							if (zephir_is_instance_of(&_30$$31, SL("TypeError"))) {
								zend_clear_exception();
								ZEPHIR_CPY_WRT(&_31$$31, &_30$$31);
								_32$$33 = zephir_array_isset_value(&privateProperties, &attribute);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (UNEXPECTED(_32$$33)) {
									ZEPHIR_OBS_NVAR(&reflectionProperty);
									zephir_array_fetch(&reflectionProperty, &privateProperties, &attribute, PH_NOISY, "phalcon/Mvc/Model.zep", 1108);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_METHOD_CACHED(NULL, &reflectionProperty, "setValue", &_zephir_call_cache[13], &instance, &value);
									zephir_check_call_status();
								} else {
									zephir_update_property_zval_zval(&instance, &attribute, &value);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
							} else {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
						continue;
					}
				}
				_33$$29 = zephir_array_isset_value(&privateProperties, &attribute);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(_33$$29)) {
					ZEPHIR_OBS_NVAR(&reflectionProperty);
					zephir_array_fetch(&reflectionProperty, &privateProperties, &attribute, PH_NOISY, "phalcon/Mvc/Model.zep", 1120);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, &reflectionProperty, "setValue", &_zephir_call_cache[14], &instance, &value);
					zephir_check_call_status();
				} else {
					zephir_update_property_zval_zval(&instance, &attribute, &value);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				continue;
			}
			_34$$4 = !ZEPHIR_IS_STRING(&value, "");
			if (_34$$4) {
				_34$$4 = Z_TYPE_P(&value) != IS_NULL;
			}
			if (_34$$4) {
				ZEPHIR_OBS_NVAR(&_35$$39);
				zephir_array_fetch_long(&_35$$39, &attribute, 1, PH_NOISY, "phalcon/Mvc/Model.zep", 1130);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_LONG(&_35$$39, 0)) { goto zephir_switch_0_clause_0; }
				if (ZEPHIR_IS_LONG(&_35$$39, 21)) { goto zephir_switch_0_clause_1; }
				if (ZEPHIR_IS_LONG(&_35$$39, 22)) { goto zephir_switch_0_clause_2; }
				if (ZEPHIR_IS_LONG(&_35$$39, 26)) { goto zephir_switch_0_clause_3; }
				if (ZEPHIR_IS_LONG(&_35$$39, 3)) { goto zephir_switch_0_clause_4; }
				if (ZEPHIR_IS_LONG(&_35$$39, 9)) { goto zephir_switch_0_clause_5; }
				if (ZEPHIR_IS_LONG(&_35$$39, 7)) { goto zephir_switch_0_clause_6; }
				if (ZEPHIR_IS_LONG(&_35$$39, 8)) { goto zephir_switch_0_clause_7; }
				if (ZEPHIR_IS_LONG(&_35$$39, 40)) { goto zephir_switch_0_clause_8; }
				if (ZEPHIR_IS_LONG(&_35$$39, 41)) { goto zephir_switch_0_clause_9; }
				if (ZEPHIR_IS_LONG(&_35$$39, 42)) { goto zephir_switch_0_clause_10; }
				if (ZEPHIR_IS_LONG(&_35$$39, 43)) { goto zephir_switch_0_clause_11; }
				if (ZEPHIR_IS_LONG(&_35$$39, 44)) { goto zephir_switch_0_clause_12; }
				if (ZEPHIR_IS_LONG(&_35$$39, 45)) { goto zephir_switch_0_clause_13; }
				if (ZEPHIR_IS_LONG(&_35$$39, 46)) { goto zephir_switch_0_clause_14; }
				if (ZEPHIR_IS_LONG(&_35$$39, 47)) { goto zephir_switch_0_clause_15; }
				goto zephir_switch_0_clause_16;
				zephir_switch_0_clause_0: ;
				zephir_switch_0_clause_1: ;
				zephir_switch_0_clause_2: ;
				zephir_switch_0_clause_3: ;
					ZVAL_LONG(&_36$$40, 10);
					ZEPHIR_CALL_FUNCTION(&castValue, "intval", &_37, 37, &value, &_36$$40);
					zephir_check_call_status();
					goto zephir_switch_0_end;
				zephir_switch_0_clause_4: ;
				zephir_switch_0_clause_5: ;
				zephir_switch_0_clause_6: ;
					ZEPHIR_CALL_FUNCTION(&castValue, "floatval", &_38, 22, &value);
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

						ZEPHIR_INIT_NVAR(&_39$$44);
						object_init_ex(&_39$$44, phalcon_db_geometry_wkbparser_ce);
						if (zephir_has_constructor(&_39$$44)) {
							zephir_constructor_start(&_39$$44);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_39$$44, "__construct", &_zephir_call_cache[15]);
							zephir_check_call_status_or_jump(try_end_3);
							zephir_constructor_finish(&_39$$44);
						}

						ZEPHIR_CALL_METHOD_CACHED(&castValue, &_39$$44, "parse", &_zephir_call_cache[16], &value);
						zephir_check_call_status_or_jump(try_end_3);

					try_end_3:

					if (EG(exception)) {
						ZEPHIR_INIT_NVAR(&_40$$43);
						ZVAL_OBJ(&_40$$43, EG(exception));
						Z_ADDREF_P(&_40$$43);
						ZEPHIR_INIT_NVAR(&_41$$43);
						if (zephir_instance_of_ev(&_40$$43, phalcon_db_exceptions_invalidwkb_ce)) {
							zend_clear_exception();
							ZEPHIR_CPY_WRT(&_41$$43, &_40$$43);
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
				ZEPHIR_OBS_NVAR(&_42$$48);
				zephir_array_fetch_long(&_42$$48, &attribute, 1, PH_NOISY, "phalcon/Mvc/Model.zep", 1169);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_LONG(&_42$$48, 14)) { goto zephir_switch_1_clause_0; }
				if (ZEPHIR_IS_LONG(&_42$$48, 8)) { goto zephir_switch_1_clause_1; }
				if (ZEPHIR_IS_LONG(&_42$$48, 3)) { goto zephir_switch_1_clause_2; }
				if (ZEPHIR_IS_LONG(&_42$$48, 9)) { goto zephir_switch_1_clause_3; }
				if (ZEPHIR_IS_LONG(&_42$$48, 7)) { goto zephir_switch_1_clause_4; }
				if (ZEPHIR_IS_LONG(&_42$$48, 0)) { goto zephir_switch_1_clause_5; }
				if (ZEPHIR_IS_LONG(&_42$$48, 21)) { goto zephir_switch_1_clause_6; }
				if (ZEPHIR_IS_LONG(&_42$$48, 22)) { goto zephir_switch_1_clause_7; }
				if (ZEPHIR_IS_LONG(&_42$$48, 26)) { goto zephir_switch_1_clause_8; }
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
				ZEPHIR_INIT_NVAR(&_43$$51);
				zephir_camelize(&_43$$51, &attributeName, NULL );
				ZEPHIR_INIT_NVAR(&setter);
				ZEPHIR_CONCAT_SV(&setter, "set", &_43$$51);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_44$$51 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
				if (_44$$51) {
					_45$$51 = zephir_array_isset_value(&localMethods, &setter);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_44$$51 = !(_45$$51);
				}
				if (_44$$51) {

					/* try_start_4: */

						ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &castValue);
						zephir_check_call_status_or_jump(try_end_4);

					try_end_4:

					if (EG(exception)) {
						ZEPHIR_INIT_NVAR(&_46$$52);
						ZVAL_OBJ(&_46$$52, EG(exception));
						Z_ADDREF_P(&_46$$52);
						ZEPHIR_INIT_NVAR(&_47$$52);
						if (zephir_is_instance_of(&_46$$52, SL("TypeError"))) {
							zend_clear_exception();
							ZEPHIR_CPY_WRT(&_47$$52, &_46$$52);
							_48$$54 = zephir_array_isset_value(&privateProperties, &attributeName);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (UNEXPECTED(_48$$54)) {
								ZEPHIR_OBS_NVAR(&reflectionProperty);
								zephir_array_fetch(&reflectionProperty, &privateProperties, &attributeName, PH_NOISY, "phalcon/Mvc/Model.zep", 1198);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CALL_METHOD_CACHED(NULL, &reflectionProperty, "setValue", &_zephir_call_cache[17], &instance, &castValue);
								zephir_check_call_status();
							} else {
								zephir_update_property_zval_zval(&instance, &attributeName, &castValue);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
						} else {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					continue;
				}
			}
			_49$$4 = zephir_array_isset_value(&privateProperties, &attributeName);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (UNEXPECTED(_49$$4)) {
				ZEPHIR_OBS_NVAR(&reflectionProperty);
				zephir_array_fetch(&reflectionProperty, &privateProperties, &attributeName, PH_NOISY, "phalcon/Mvc/Model.zep", 1210);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(NULL, &reflectionProperty, "setValue", &_zephir_call_cache[18], &instance, &castValue);
				zephir_check_call_status();
			} else {
				zephir_update_property_zval_zval(&instance, &attributeName, &castValue);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &data, "rewind", &_zephir_call_cache[19]);
		zephir_check_call_status();
		_51 = 1;
		while (1) {
			if (_51) {
				_51 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &data, "next", &_zephir_call_cache[20]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_50, &data, "valid", &_zephir_call_cache[21]);
			zephir_check_call_status();
			if (!zend_is_true(&_50)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&key, &data, "key", &_zephir_call_cache[22]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&value, &data, "current", &_zephir_call_cache[23]);
			zephir_check_call_status();
				if (Z_TYPE_P(&key) != IS_STRING) {
					continue;
				}
				if (Z_TYPE_P(&value) == IS_NULL) {
					if (Z_TYPE_P(&notNullAttributes) == IS_NULL) {
						if (zephir_instance_of_ev(&instance, phalcon_mvc_model_ce)) {
							if (Z_TYPE_P(&metaData) == IS_NULL) {
								ZEPHIR_CALL_METHOD_CACHED(&metaData, &instance, "getModelsMetaData", &_zephir_call_cache[24]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&notNullAttributes, &metaData, "getNotNullAttributes", &_zephir_call_cache[25], &instance);
							zephir_check_call_status();
						} else {
							ZEPHIR_INIT_NVAR(&notNullAttributes);
							array_init(&notNullAttributes);
						}
					}
					_52$$62 = zephir_fast_in_array(&key, &notNullAttributes);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_52$$62) {
						continue;
					}
				}
				if (Z_TYPE_P(columnMap) != IS_ARRAY) {
					if (callSetters) {
						ZEPHIR_INIT_NVAR(&_53$$69);
						zephir_camelize(&_53$$69, &key, NULL );
						ZEPHIR_INIT_NVAR(&setter);
						ZEPHIR_CONCAT_SV(&setter, "set", &_53$$69);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_54$$69 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
						if (_54$$69) {
							_55$$69 = zephir_array_isset_value(&localMethods, &setter);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							_54$$69 = !(_55$$69);
						}
						if (_54$$69) {

							/* try_start_5: */

								ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &value);
								zephir_check_call_status_or_jump(try_end_5);

							try_end_5:

							if (EG(exception)) {
								ZEPHIR_INIT_NVAR(&_56$$70);
								ZVAL_OBJ(&_56$$70, EG(exception));
								Z_ADDREF_P(&_56$$70);
								ZEPHIR_INIT_NVAR(&_57$$70);
								if (zephir_is_instance_of(&_56$$70, SL("TypeError"))) {
									zend_clear_exception();
									ZEPHIR_CPY_WRT(&_57$$70, &_56$$70);
									_58$$72 = zephir_array_isset_value(&privateProperties, &key);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (UNEXPECTED(_58$$72)) {
										ZEPHIR_OBS_NVAR(&reflectionProperty);
										zephir_array_fetch(&reflectionProperty, &privateProperties, &key, PH_NOISY, "phalcon/Mvc/Model.zep", 1055);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CALL_METHOD_CACHED(NULL, &reflectionProperty, "setValue", &_zephir_call_cache[26], &instance, &value);
										zephir_check_call_status();
									} else {
										zephir_update_property_zval_zval(&instance, &key, &value);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									}
								} else {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
							continue;
						}
					}
					_59$$68 = zephir_array_isset_value(&privateProperties, &key);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(_59$$68)) {
						ZEPHIR_OBS_NVAR(&reflectionProperty);
						zephir_array_fetch(&reflectionProperty, &privateProperties, &key, PH_NOISY, "phalcon/Mvc/Model.zep", 1067);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD_CACHED(NULL, &reflectionProperty, "setValue", &_zephir_call_cache[27], &instance, &value);
						zephir_check_call_status();
					} else {
						zephir_update_property_zval_zval(&instance, &key, &value);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					continue;
				}
				ZEPHIR_OBS_NVAR(&attribute);
				_60$$60 = zephir_array_isset_fetch(&attribute, columnMap, &key, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_60$$60)) {
					_61$$78 = Z_TYPE_P(columnMap) == IS_ARRAY;
					if (_61$$78) {
						_61$$78 = !(ZEPHIR_IS_EMPTY(columnMap));
					}
					if (_61$$78) {
						if (Z_TYPE_P(&metaData) == IS_NULL) {
							ZEPHIR_CALL_METHOD_CACHED(&metaData, &instance, "getModelsMetaData", &_zephir_call_cache[28]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&reverseMap, &metaData, "getReverseColumnMap", &_zephir_call_cache[29], &instance);
						zephir_check_call_status();
						ZEPHIR_OBS_NVAR(&attribute);
						_62$$79 = zephir_array_isset_fetch(&attribute, &reverseMap, &key, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (!(_62$$79)) {
							ZEPHIR_INIT_NVAR(&_64$$81);
							ZVAL_STRING(&_64$$81, "orm.ignore_unknown_columns");
							ZEPHIR_CALL_CE_STATIC_CACHED(&_63$$81, phalcon_support_settings_ce, "get", &_zephir_call_cache[30], &_64$$81);
							zephir_check_call_status();
							if (UNEXPECTED(!zephir_is_true(&_63$$81))) {
								ZEPHIR_INIT_NVAR(&_65$$82);
								object_init_ex(&_65$$82, phalcon_mvc_model_exceptions_columnnotinmap_ce);
								zephir_constructor_start(&_65$$82);
								ZEPHIR_INIT_NVAR(&_66$$82);
								zephir_get_class(&_66$$82, base, 0);
								ZEPHIR_CALL_METHOD_CACHED(NULL, &_65$$82, "__construct", &_zephir_call_cache[31], &key, &_66$$82);
								zephir_check_call_status();
								zephir_constructor_finish(&_65$$82);
								zephir_throw_exception_debug(&_65$$82, "phalcon/Mvc/Model.zep", 1086);
								ZEPHIR_MM_RESTORE();
								return;
							}
							continue;
						}
					} else {
						ZEPHIR_INIT_NVAR(&_68$$83);
						ZVAL_STRING(&_68$$83, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC_CACHED(&_67$$83, phalcon_support_settings_ce, "get", &_zephir_call_cache[32], &_68$$83);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_67$$83))) {
							ZEPHIR_INIT_NVAR(&_69$$84);
							object_init_ex(&_69$$84, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							zephir_constructor_start(&_69$$84);
							ZEPHIR_INIT_NVAR(&_70$$84);
							zephir_get_class(&_70$$84, base, 0);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_69$$84, "__construct", &_zephir_call_cache[33], &key, &_70$$84);
							zephir_check_call_status();
							zephir_constructor_finish(&_69$$84);
							zephir_throw_exception_debug(&_69$$84, "phalcon/Mvc/Model.zep", 1093);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
				}
				if (Z_TYPE_P(&attribute) != IS_ARRAY) {
					if (callSetters) {
						ZEPHIR_INIT_NVAR(&_71$$86);
						zephir_camelize(&_71$$86, &attribute, NULL );
						ZEPHIR_INIT_NVAR(&setter);
						ZEPHIR_CONCAT_SV(&setter, "set", &_71$$86);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_72$$86 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
						if (_72$$86) {
							_73$$86 = zephir_array_isset_value(&localMethods, &setter);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							_72$$86 = !(_73$$86);
						}
						if (_72$$86) {

							/* try_start_6: */

								ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &value);
								zephir_check_call_status_or_jump(try_end_6);

							try_end_6:

							if (EG(exception)) {
								ZEPHIR_INIT_NVAR(&_74$$87);
								ZVAL_OBJ(&_74$$87, EG(exception));
								Z_ADDREF_P(&_74$$87);
								ZEPHIR_INIT_NVAR(&_75$$87);
								if (zephir_is_instance_of(&_74$$87, SL("TypeError"))) {
									zend_clear_exception();
									ZEPHIR_CPY_WRT(&_75$$87, &_74$$87);
									_76$$89 = zephir_array_isset_value(&privateProperties, &attribute);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (UNEXPECTED(_76$$89)) {
										ZEPHIR_OBS_NVAR(&reflectionProperty);
										zephir_array_fetch(&reflectionProperty, &privateProperties, &attribute, PH_NOISY, "phalcon/Mvc/Model.zep", 1108);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CALL_METHOD_CACHED(NULL, &reflectionProperty, "setValue", &_zephir_call_cache[34], &instance, &value);
										zephir_check_call_status();
									} else {
										zephir_update_property_zval_zval(&instance, &attribute, &value);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									}
								} else {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
							continue;
						}
					}
					_77$$85 = zephir_array_isset_value(&privateProperties, &attribute);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(_77$$85)) {
						ZEPHIR_OBS_NVAR(&reflectionProperty);
						zephir_array_fetch(&reflectionProperty, &privateProperties, &attribute, PH_NOISY, "phalcon/Mvc/Model.zep", 1120);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD_CACHED(NULL, &reflectionProperty, "setValue", &_zephir_call_cache[35], &instance, &value);
						zephir_check_call_status();
					} else {
						zephir_update_property_zval_zval(&instance, &attribute, &value);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					continue;
				}
				_78$$60 = !ZEPHIR_IS_STRING(&value, "");
				if (_78$$60) {
					_78$$60 = Z_TYPE_P(&value) != IS_NULL;
				}
				if (_78$$60) {
					ZEPHIR_OBS_NVAR(&_79$$95);
					zephir_array_fetch_long(&_79$$95, &attribute, 1, PH_NOISY, "phalcon/Mvc/Model.zep", 1130);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (ZEPHIR_IS_LONG(&_79$$95, 0)) { goto zephir_switch_2_clause_0; }
					if (ZEPHIR_IS_LONG(&_79$$95, 21)) { goto zephir_switch_2_clause_1; }
					if (ZEPHIR_IS_LONG(&_79$$95, 22)) { goto zephir_switch_2_clause_2; }
					if (ZEPHIR_IS_LONG(&_79$$95, 26)) { goto zephir_switch_2_clause_3; }
					if (ZEPHIR_IS_LONG(&_79$$95, 3)) { goto zephir_switch_2_clause_4; }
					if (ZEPHIR_IS_LONG(&_79$$95, 9)) { goto zephir_switch_2_clause_5; }
					if (ZEPHIR_IS_LONG(&_79$$95, 7)) { goto zephir_switch_2_clause_6; }
					if (ZEPHIR_IS_LONG(&_79$$95, 8)) { goto zephir_switch_2_clause_7; }
					if (ZEPHIR_IS_LONG(&_79$$95, 40)) { goto zephir_switch_2_clause_8; }
					if (ZEPHIR_IS_LONG(&_79$$95, 41)) { goto zephir_switch_2_clause_9; }
					if (ZEPHIR_IS_LONG(&_79$$95, 42)) { goto zephir_switch_2_clause_10; }
					if (ZEPHIR_IS_LONG(&_79$$95, 43)) { goto zephir_switch_2_clause_11; }
					if (ZEPHIR_IS_LONG(&_79$$95, 44)) { goto zephir_switch_2_clause_12; }
					if (ZEPHIR_IS_LONG(&_79$$95, 45)) { goto zephir_switch_2_clause_13; }
					if (ZEPHIR_IS_LONG(&_79$$95, 46)) { goto zephir_switch_2_clause_14; }
					if (ZEPHIR_IS_LONG(&_79$$95, 47)) { goto zephir_switch_2_clause_15; }
					goto zephir_switch_2_clause_16;
					zephir_switch_2_clause_0: ;
					zephir_switch_2_clause_1: ;
					zephir_switch_2_clause_2: ;
					zephir_switch_2_clause_3: ;
						ZVAL_LONG(&_80$$96, 10);
						ZEPHIR_CALL_FUNCTION(&castValue, "intval", &_37, 37, &value, &_80$$96);
						zephir_check_call_status();
						goto zephir_switch_2_end;
					zephir_switch_2_clause_4: ;
					zephir_switch_2_clause_5: ;
					zephir_switch_2_clause_6: ;
						ZEPHIR_CALL_FUNCTION(&castValue, "floatval", &_38, 22, &value);
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

							ZEPHIR_INIT_NVAR(&_81$$100);
							object_init_ex(&_81$$100, phalcon_db_geometry_wkbparser_ce);
							if (zephir_has_constructor(&_81$$100)) {
								zephir_constructor_start(&_81$$100);
								ZEPHIR_CALL_METHOD_CACHED(NULL, &_81$$100, "__construct", &_zephir_call_cache[36]);
								zephir_check_call_status_or_jump(try_end_7);
								zephir_constructor_finish(&_81$$100);
							}

							ZEPHIR_CALL_METHOD_CACHED(&castValue, &_81$$100, "parse", &_zephir_call_cache[37], &value);
							zephir_check_call_status_or_jump(try_end_7);

						try_end_7:

						if (EG(exception)) {
							ZEPHIR_INIT_NVAR(&_82$$99);
							ZVAL_OBJ(&_82$$99, EG(exception));
							Z_ADDREF_P(&_82$$99);
							ZEPHIR_INIT_NVAR(&_83$$99);
							if (zephir_instance_of_ev(&_82$$99, phalcon_db_exceptions_invalidwkb_ce)) {
								zend_clear_exception();
								ZEPHIR_CPY_WRT(&_83$$99, &_82$$99);
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
					ZEPHIR_OBS_NVAR(&_84$$104);
					zephir_array_fetch_long(&_84$$104, &attribute, 1, PH_NOISY, "phalcon/Mvc/Model.zep", 1169);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (ZEPHIR_IS_LONG(&_84$$104, 14)) { goto zephir_switch_3_clause_0; }
					if (ZEPHIR_IS_LONG(&_84$$104, 8)) { goto zephir_switch_3_clause_1; }
					if (ZEPHIR_IS_LONG(&_84$$104, 3)) { goto zephir_switch_3_clause_2; }
					if (ZEPHIR_IS_LONG(&_84$$104, 9)) { goto zephir_switch_3_clause_3; }
					if (ZEPHIR_IS_LONG(&_84$$104, 7)) { goto zephir_switch_3_clause_4; }
					if (ZEPHIR_IS_LONG(&_84$$104, 0)) { goto zephir_switch_3_clause_5; }
					if (ZEPHIR_IS_LONG(&_84$$104, 21)) { goto zephir_switch_3_clause_6; }
					if (ZEPHIR_IS_LONG(&_84$$104, 22)) { goto zephir_switch_3_clause_7; }
					if (ZEPHIR_IS_LONG(&_84$$104, 26)) { goto zephir_switch_3_clause_8; }
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
					ZEPHIR_INIT_NVAR(&_85$$107);
					zephir_camelize(&_85$$107, &attributeName, NULL );
					ZEPHIR_INIT_NVAR(&setter);
					ZEPHIR_CONCAT_SV(&setter, "set", &_85$$107);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_86$$107 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
					if (_86$$107) {
						_87$$107 = zephir_array_isset_value(&localMethods, &setter);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_86$$107 = !(_87$$107);
					}
					if (_86$$107) {

						/* try_start_8: */

							ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &castValue);
							zephir_check_call_status_or_jump(try_end_8);

						try_end_8:

						if (EG(exception)) {
							ZEPHIR_INIT_NVAR(&_88$$108);
							ZVAL_OBJ(&_88$$108, EG(exception));
							Z_ADDREF_P(&_88$$108);
							ZEPHIR_INIT_NVAR(&_89$$108);
							if (zephir_is_instance_of(&_88$$108, SL("TypeError"))) {
								zend_clear_exception();
								ZEPHIR_CPY_WRT(&_89$$108, &_88$$108);
								_90$$110 = zephir_array_isset_value(&privateProperties, &attributeName);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (UNEXPECTED(_90$$110)) {
									ZEPHIR_OBS_NVAR(&reflectionProperty);
									zephir_array_fetch(&reflectionProperty, &privateProperties, &attributeName, PH_NOISY, "phalcon/Mvc/Model.zep", 1198);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_METHOD_CACHED(NULL, &reflectionProperty, "setValue", &_zephir_call_cache[38], &instance, &castValue);
									zephir_check_call_status();
								} else {
									zephir_update_property_zval_zval(&instance, &attributeName, &castValue);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
							} else {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
						continue;
					}
				}
				_91$$60 = zephir_array_isset_value(&privateProperties, &attributeName);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(_91$$60)) {
					ZEPHIR_OBS_NVAR(&reflectionProperty);
					zephir_array_fetch(&reflectionProperty, &privateProperties, &attributeName, PH_NOISY, "phalcon/Mvc/Model.zep", 1210);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, &reflectionProperty, "setValue", &_zephir_call_cache[39], &instance, &castValue);
					zephir_check_call_status();
				} else {
					zephir_update_property_zval_zval(&instance, &attributeName, &castValue);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
		}
	}
	if (keepSnapshots) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &instance, "setSnapshotData", &_zephir_call_cache[40], &data, columnMap);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_92$$116, &instance, "getSnapshotData", &_zephir_call_cache[41]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(NULL, &instance, "setOldSnapshotData", &_zephir_call_cache[42], &_92$$116);
		zephir_check_call_status();
	}
	if ((zephir_method_exists_ex(&instance, ZEND_STRL("fireevent")) == SUCCESS)) {
		ZEPHIR_INIT_VAR(&_93$$117);
		ZVAL_STRING(&_93$$117, "afterFetch");
		ZEPHIR_CALL_METHOD_CACHED(NULL, &instance, "fireEvent", &_zephir_call_cache[43], &_93$$117);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_RETURN_CALL_CE_STATIC_CACHED(phalcon_mvc_model_hydration_cloneresultmaphydrate_ce, "cloneResultMapHydrate", &_zephir_call_cache[0], &data, columnMap, &_1, &_0);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_CALL_SELF_CACHED(&result, "groupResult", &_zephir_call_cache[0], &_1, &_2, parameters);
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
	zend_bool _0$$6, _1$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, parameters_sub, __$null, eager, params, query, resultset, hydration;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&eager);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&resultset);
	ZVAL_UNDEF(&hydration);
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
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
	ZEPHIR_CALL_SELF_CACHED(&query, "getPreparedQuery", &_zephir_call_cache[0], &params);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&resultset, &query, "execute", &_zephir_call_cache[1]);
	zephir_check_call_status();
	if (Z_TYPE_P(&resultset) == IS_OBJECT) {
		zephir_memory_observe(&hydration);
		_0$$6 = zephir_array_isset_string_fetch(&hydration, &params, SL("hydration"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_0$$6) {
			ZEPHIR_CALL_METHOD_CACHED(NULL, &resultset, "setHydrateMode", &_zephir_call_cache[2], &hydration);
			zephir_check_call_status();
		}
		zephir_memory_observe(&eager);
		_1$$6 = zephir_array_isset_string_fetch(&eager, &params, SL("eager"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_1$$6) {
			ZEPHIR_CALL_SELF_CACHED(NULL, "loadEager", &_zephir_call_cache[3], &resultset, &eager, &params);
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
	zend_bool _0, _5;
	zval params;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, parameters_sub, __$null, eager, query, resultset, _4, _1$$5, _2$$6, _3$$6;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&eager);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&resultset);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&params);
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
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
			zephir_constructor_start(&_2$$6);
			ZEPHIR_INIT_VAR(&_3$$6);
			zephir_get_called_class(&_3$$6);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$6, "__construct", &_zephir_call_cache[0], &_3$$6);
			zephir_check_call_status();
			zephir_constructor_finish(&_2$$6);
			zephir_throw_exception_debug(&_2$$6, "phalcon/Mvc/Model.zep", 1622);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZVAL_LONG(&_4, 1);
	ZEPHIR_CALL_SELF_CACHED(&query, "getPreparedQuery", &_zephir_call_cache[1], &params, &_4);
	zephir_check_call_status();
	zephir_memory_observe(&eager);
	_5 = zephir_array_isset_string_fetch(&eager, &params, SL("eager"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_5) {
		ZEPHIR_CALL_METHOD_CACHED(&resultset, &query, "execute", &_zephir_call_cache[2]);
		zephir_check_call_status();
		if (Z_TYPE_P(&resultset) == IS_OBJECT) {
			ZEPHIR_CALL_SELF_CACHED(NULL, "loadEager", &_zephir_call_cache[3], &resultset, &eager, &params);
			zephir_check_call_status();
			ZEPHIR_RETURN_CALL_METHOD_CACHED(&resultset, "getFirst", &_zephir_call_cache[4]);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETURN_CCTOR(&resultset);
	}
	ZVAL_BOOL(&_4, 1);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &query, "setUniqueRow", &_zephir_call_cache[5], &_4);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&query, "execute", &_zephir_call_cache[6]);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_RETURN_CALL_SELF_CACHED("groupResult", &_zephir_call_cache[0], &_0, &_1, parameters);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_RETURN_CALL_SELF_CACHED("groupResult", &_zephir_call_cache[0], &_0, &_1, parameters);
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
	zval *container = NULL, container_sub, __$null, criteria, _3, _0$$4, _1$$4, _2$$5;

	ZVAL_UNDEF(&container_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&criteria);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZEND_TLS zephir_method_cache _zephir_call_cache[5];
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
		ZEPHIR_CALL_CE_STATIC_CACHED(container, phalcon_di_di_ce, "getDefault", &_zephir_call_cache[0]);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&criteria);
	if (zephir_instance_of_ev(container, phalcon_di_diinterface_ce)) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "Phalcon\\Mvc\\Model\\Criteria");
		ZEPHIR_CALL_METHOD_CACHED(&_0$$4, container, "get", &_zephir_call_cache[1], &_1$$4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&criteria, &_0$$4);
	} else {
		ZEPHIR_INIT_VAR(&_2$$5);
		object_init_ex(&_2$$5, phalcon_mvc_model_criteria_ce);
		if (zephir_has_constructor(&_2$$5)) {
			zephir_constructor_start(&_2$$5);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$5, "__construct", &_zephir_call_cache[2]);
			zephir_check_call_status();
			zephir_constructor_finish(&_2$$5);
		}

		ZEPHIR_CPY_WRT(&criteria, &_2$$5);
		ZEPHIR_INIT_NVAR(&_2$$5);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &criteria, "setDI", &_zephir_call_cache[3], container);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_3);
	zephir_get_called_class(&_3);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &criteria, "setModelName", &_zephir_call_cache[4], &_3);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_CALL_SELF_CACHED(&result, "groupResult", &_zephir_call_cache[0], &_0, &_1, parameters);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[10];
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
	ZEPHIR_CALL_CE_STATIC_CACHED(&container, phalcon_di_di_ce, "getDefault", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "modelsManager");
	ZEPHIR_CALL_METHOD_CACHED(&_0, &container, "getShared", &_zephir_call_cache[1], &_1);
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
	ZEPHIR_CALL_METHOD_CACHED(&_0, &manager, "createBuilder", &_zephir_call_cache[2], &params);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&builder, &_0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &builder, "columns", &_zephir_call_cache[3], &columns);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	zephir_get_called_class(&_1);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &builder, "from", &_zephir_call_cache[4], &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_0, &builder, "getQuery", &_zephir_call_cache[5]);
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
			ZEPHIR_CALL_METHOD_CACHED(NULL, &query, "setTransaction", &_zephir_call_cache[6], &transaction);
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &query, "cache", &_zephir_call_cache[7], &cache);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD_CACHED(&resultset, &query, "execute", &_zephir_call_cache[8], &bindParams, &bindTypes);
	zephir_check_call_status();
	_9 = zephir_array_isset_value_string(&params, SL("group"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_9) {
		RETURN_CCTOR(&resultset);
	}
	ZEPHIR_CALL_METHOD_CACHED(&firstRow, &resultset, "getFirst", &_zephir_call_cache[9]);
	zephir_check_call_status();
	zephir_memory_observe(&_10);
	zephir_read_property_zval(&_10, &firstRow, &alias_zv, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[5];
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
		zephir_constructor_start(&_5$$7);
		ZEPHIR_INIT_VAR(&_6$$7);
		zephir_get_called_class(&_6$$7);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_5$$7, "__construct", &_zephir_call_cache[0], &method_zv, &_6$$7);
		zephir_check_call_status();
		zephir_constructor_finish(&_5$$7);
		zephir_throw_exception_debug(&_5$$7, "phalcon/Mvc/Model.zep", 1954);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&model);
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&model, &modelName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&metaData, &model, "getModelsMetaData", &_zephir_call_cache[1]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&attributes, &metaData, "getReverseColumnMap", &_zephir_call_cache[2], &model);
	zephir_check_call_status();
	if (Z_TYPE_P(&attributes) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD_CACHED(&attributes, &metaData, "getDataTypes", &_zephir_call_cache[3], &model);
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
		ZEPHIR_CALL_FUNCTION(&extraMethodFirst, "lcfirst", NULL, 57, &extraMethod);
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
				zephir_constructor_start(&_10$$13);
				ZEPHIR_INIT_VAR(&_11$$13);
				zephir_get_called_class(&_11$$13);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_10$$13, "__construct", &_zephir_call_cache[4], &extraMethod, &_11$$13);
				zephir_check_call_status();
				zephir_constructor_finish(&_10$$13);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[10];
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
	ZEPHIR_CALL_CE_STATIC_CACHED(&container, phalcon_di_di_ce, "getDefault", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "modelsManager");
	ZEPHIR_CALL_METHOD_CACHED(&_0, &container, "getShared", &_zephir_call_cache[1], &_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD_CACHED(&_0, &manager, "createBuilder", &_zephir_call_cache[2], params);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&builder, &_0);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_get_called_class(&_1);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &builder, "from", &_zephir_call_cache[3], &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(limit) != IS_NULL) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &builder, "limit", &_zephir_call_cache[4], limit);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD_CACHED(&_0, &builder, "getQuery", &_zephir_call_cache[5]);
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
			ZEPHIR_CALL_METHOD_CACHED(NULL, &query, "setBindParams", &_zephir_call_cache[6], &bindParams, &_3$$5);
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
				ZEPHIR_CALL_METHOD_CACHED(NULL, &query, "setBindTypes", &_zephir_call_cache[7], &bindTypes, &_5$$7);
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
			ZEPHIR_CALL_METHOD_CACHED(NULL, &query, "setTransaction", &_zephir_call_cache[8], &transaction);
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &query, "cache", &_zephir_call_cache[9], &cache);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[8];
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
		zephir_constructor_start(&_0$$3);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_0$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_constructor_finish(&_0$$3);
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model.zep", 2098);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!((zephir_instance_of_ev(resultset, phalcon_mvc_model_resultset_simple_ce))))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_mvc_model_exceptions_unsupportedeagerresultset_ce);
		zephir_constructor_start(&_1$$4);
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_get_class(&_2$$4, resultset, 0);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$4, "__construct", &_zephir_call_cache[1], &_2$$4);
		zephir_check_call_status();
		zephir_constructor_finish(&_1$$4);
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
			zephir_constructor_start(&_4$$6);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_4$$6, "__construct", &_zephir_call_cache[2]);
			zephir_check_call_status();
			zephir_constructor_finish(&_4$$6);
			zephir_throw_exception_debug(&_4$$6, "phalcon/Mvc/Model.zep", 2107);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_CE_STATIC_CACHED(&container, phalcon_di_di_ce, "getDefault", &_zephir_call_cache[3]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "modelsManager");
	ZEPHIR_CALL_METHOD_CACHED(&_5, &container, "getShared", &_zephir_call_cache[4], &_6);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_5);
	ZEPHIR_INIT_NVAR(&_6);
	object_init_ex(&_6, phalcon_mvc_model_eager_loader_ce);
	zephir_constructor_start(&_6);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_6, "__construct", &_zephir_call_cache[5], &manager);
	zephir_check_call_status();
	zephir_constructor_finish(&_6);
	ZEPHIR_CPY_WRT(&loader, &_6);
	ZEPHIR_INIT_NVAR(&_6);
	ZEPHIR_INIT_NVAR(&_6);
	zephir_get_called_class(&_6);
	ZEPHIR_CALL_CE_STATIC_CACHED(&_5, phalcon_mvc_model_eager_pathtree_ce, "parse", &_zephir_call_cache[6], eager);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &loader, "loadResultset", &_zephir_call_cache[7], resultset, &_6, &_5);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "addBehavior", &_zephir_call_cache[0], this_ptr, behavior);
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
	zval _3$$5, _6$$7;
	zend_bool _5$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, messages, message, *_0$$3, _1$$3, *_2$$3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_6$$7);
	ZEND_TLS zephir_method_cache _zephir_call_cache[9];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(model)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &model);
	ZEPHIR_CALL_METHOD_CACHED(&messages, model, "getMessages", &_zephir_call_cache[0]);
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
					ZEPHIR_CALL_METHOD_CACHED(NULL, &message, "setMetaData", &_zephir_call_cache[1], &_3$$5);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessage", &_zephir_call_cache[2], &message);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _0$$3, "rewind", &_zephir_call_cache[3]);
			zephir_check_call_status();
			_5$$3 = 1;
			while (1) {
				if (_5$$3) {
					_5$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _0$$3, "next", &_zephir_call_cache[4]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_4$$3, _0$$3, "valid", &_zephir_call_cache[5]);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&message, _0$$3, "current", &_zephir_call_cache[6]);
				zephir_check_call_status();
					if (Z_TYPE_P(&message) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_6$$7);
						zephir_create_array(&_6$$7, 1, 0);
						zephir_array_update_string(&_6$$7, SL("model"), model, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &message, "setMetaData", &_zephir_call_cache[7], &_6$$7);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessage", &_zephir_call_cache[8], &message);
					zephir_check_call_status();
			}
		}
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
	zend_bool _30, _6$$3, _4$$4, _7$$6, _12$$12, _13$$12, _14$$12, _23$$12, _18$$14, _24$$18, _25$$18, _26$$18, _27$$18, _31$$22, _32$$22, _33$$22, _42$$22, _37$$24, _43$$28, _44$$28, _45$$28, _46$$28;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *whiteList = NULL, whiteList_sub, *dataColumnMap = NULL, dataColumnMap_sub, __$null, key, keyMapped, value, attribute, attributeField, metaData, columnMap, disableAssignSetters, rawValues, _0, _8, _9, *_10, *_11, _29, *_1$$3, _5$$3, _15$$12, _16$$12, _17$$13, _19$$15, _20$$15, _21$$16, _22$$16, _28$$18, _34$$22, _35$$22, _36$$23, _38$$25, _39$$25, _40$$26, _41$$26, _47$$28;
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
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_21$$16);
	ZVAL_UNDEF(&_22$$16);
	ZVAL_UNDEF(&_28$$18);
	ZVAL_UNDEF(&_34$$22);
	ZVAL_UNDEF(&_35$$22);
	ZVAL_UNDEF(&_36$$23);
	ZVAL_UNDEF(&_38$$25);
	ZVAL_UNDEF(&_39$$25);
	ZVAL_UNDEF(&_40$$26);
	ZVAL_UNDEF(&_41$$26);
	ZVAL_UNDEF(&_47$$28);
	ZEND_TLS zephir_method_cache _zephir_call_cache[24];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "orm.disable_assign_setters");
	ZEPHIR_CALL_CE_STATIC_CACHED(&disableAssignSetters, phalcon_support_settings_ce, "get", &_zephir_call_cache[0], &_0);
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
			ZEPHIR_CALL_METHOD_CACHED(NULL, &data, "rewind", &_zephir_call_cache[1]);
			zephir_check_call_status();
			_6$$3 = 1;
			while (1) {
				if (_6$$3) {
					_6$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, &data, "next", &_zephir_call_cache[2]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_5$$3, &data, "valid", &_zephir_call_cache[3]);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&key, &data, "key", &_zephir_call_cache[4]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&value, &data, "current", &_zephir_call_cache[5]);
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
	ZEPHIR_CALL_METHOD_CACHED(&metaData, this_ptr, "getModelsMetaData", &_zephir_call_cache[6]);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "orm.column_renaming");
	ZEPHIR_CALL_CE_STATIC_CACHED(&_8, phalcon_support_settings_ce, "get", &_zephir_call_cache[7], &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_8)) {
		ZEPHIR_CALL_METHOD_CACHED(&columnMap, &metaData, "getColumnMap", &_zephir_call_cache[8], this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&columnMap);
		ZVAL_NULL(&columnMap);
	}
	ZEPHIR_CALL_METHOD_CACHED(&_9, &metaData, "getAttributes", &_zephir_call_cache[9], this_ptr);
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
				ZEPHIR_INIT_NVAR(&_16$$12);
				ZVAL_STRING(&_16$$12, "orm.case_insensitive_column_map");
				ZEPHIR_CALL_CE_STATIC_CACHED(&_15$$12, phalcon_support_settings_ce, "get", &_zephir_call_cache[10], &_16$$12);
				zephir_check_call_status();
				_14$$12 = zephir_is_true(&_15$$12);
			}
			if (_14$$12) {
				ZEPHIR_CALL_CE_STATIC_CACHED(&_17$$13, phalcon_mvc_model_hydration_caseinsensitivecolumnmap_ce, "caseInsensitiveColumnMap", &_zephir_call_cache[11], &columnMap, &attribute);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&attribute, &_17$$13);
			}
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				_18$$14 = zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_18$$14)) {
					ZEPHIR_INIT_NVAR(&_20$$15);
					ZVAL_STRING(&_20$$15, "orm.ignore_unknown_columns");
					ZEPHIR_CALL_CE_STATIC_CACHED(&_19$$15, phalcon_support_settings_ce, "get", &_zephir_call_cache[12], &_20$$15);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&_19$$15))) {
						ZEPHIR_INIT_NVAR(&_21$$16);
						object_init_ex(&_21$$16, phalcon_mvc_model_exceptions_columnnotinmap_ce);
						zephir_constructor_start(&_21$$16);
						ZEPHIR_INIT_NVAR(&_22$$16);
						zephir_get_class(&_22$$16, this_ptr, 0);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_21$$16, "__construct", &_zephir_call_cache[13], &attribute, &_22$$16);
						zephir_check_call_status();
						zephir_constructor_finish(&_21$$16);
						zephir_throw_exception_debug(&_21$$16, "phalcon/Mvc/Model.zep", 2319);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &attribute);
			}
			ZEPHIR_OBS_NVAR(&value);
			_23$$12 = zephir_array_isset_fetch(&value, &dataMapped, &attributeField, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_23$$12) {
				_24$$18 = Z_TYPE_P(whiteList) == IS_ARRAY;
				if (_24$$18) {
					_25$$18 = zephir_fast_in_array(&attributeField, whiteList);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_24$$18 = !(_25$$18);
				}
				if (_24$$18) {
					continue;
				}
				_26$$18 = Z_TYPE_P(&value) == IS_OBJECT;
				if (_26$$18) {
					_26$$18 = zephir_instance_of_ev(&value, phalcon_db_rawvalue_ce);
				}
				if (_26$$18) {
					zephir_array_update_zval(&rawValues, &attributeField, &value, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					_27$$18 = zephir_is_true(&disableAssignSetters);
					if (!(_27$$18)) {
						ZEPHIR_CALL_METHOD_CACHED(&_28$$18, this_ptr, "possibleSetter", &_zephir_call_cache[14], &attributeField, &value);
						zephir_check_call_status();
						_27$$18 = !zephir_is_true(&_28$$18);
					}
					if (_27$$18) {
						zephir_update_property_zval_zval(this_ptr, &attributeField, &value);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _10, "rewind", &_zephir_call_cache[15]);
		zephir_check_call_status();
		_30 = 1;
		while (1) {
			if (_30) {
				_30 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _10, "next", &_zephir_call_cache[16]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_29, _10, "valid", &_zephir_call_cache[17]);
			zephir_check_call_status();
			if (!zend_is_true(&_29)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&attribute, _10, "current", &_zephir_call_cache[18]);
			zephir_check_call_status();
				_31$$22 = Z_TYPE_P(&columnMap) == IS_ARRAY;
				if (_31$$22) {
					_32$$22 = zephir_array_isset_value(&columnMap, &attribute);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_31$$22 = !(_32$$22);
				}
				_33$$22 = _31$$22;
				if (_33$$22) {
					ZEPHIR_INIT_NVAR(&_35$$22);
					ZVAL_STRING(&_35$$22, "orm.case_insensitive_column_map");
					ZEPHIR_CALL_CE_STATIC_CACHED(&_34$$22, phalcon_support_settings_ce, "get", &_zephir_call_cache[19], &_35$$22);
					zephir_check_call_status();
					_33$$22 = zephir_is_true(&_34$$22);
				}
				if (_33$$22) {
					ZEPHIR_CALL_CE_STATIC_CACHED(&_36$$23, phalcon_mvc_model_hydration_caseinsensitivecolumnmap_ce, "caseInsensitiveColumnMap", &_zephir_call_cache[20], &columnMap, &attribute);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&attribute, &_36$$23);
				}
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					_37$$24 = zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_37$$24)) {
						ZEPHIR_INIT_NVAR(&_39$$25);
						ZVAL_STRING(&_39$$25, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC_CACHED(&_38$$25, phalcon_support_settings_ce, "get", &_zephir_call_cache[21], &_39$$25);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_38$$25))) {
							ZEPHIR_INIT_NVAR(&_40$$26);
							object_init_ex(&_40$$26, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							zephir_constructor_start(&_40$$26);
							ZEPHIR_INIT_NVAR(&_41$$26);
							zephir_get_class(&_41$$26, this_ptr, 0);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_40$$26, "__construct", &_zephir_call_cache[22], &attribute, &_41$$26);
							zephir_check_call_status();
							zephir_constructor_finish(&_40$$26);
							zephir_throw_exception_debug(&_40$$26, "phalcon/Mvc/Model.zep", 2319);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &attribute);
				}
				ZEPHIR_OBS_NVAR(&value);
				_42$$22 = zephir_array_isset_fetch(&value, &dataMapped, &attributeField, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_42$$22) {
					_43$$28 = Z_TYPE_P(whiteList) == IS_ARRAY;
					if (_43$$28) {
						_44$$28 = zephir_fast_in_array(&attributeField, whiteList);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_43$$28 = !(_44$$28);
					}
					if (_43$$28) {
						continue;
					}
					_45$$28 = Z_TYPE_P(&value) == IS_OBJECT;
					if (_45$$28) {
						_45$$28 = zephir_instance_of_ev(&value, phalcon_db_rawvalue_ce);
					}
					if (_45$$28) {
						zephir_array_update_zval(&rawValues, &attributeField, &value, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						_46$$28 = zephir_is_true(&disableAssignSetters);
						if (!(_46$$28)) {
							ZEPHIR_CALL_METHOD_CACHED(&_47$$28, this_ptr, "possibleSetter", &_zephir_call_cache[23], &attributeField, &value);
							zephir_check_call_status();
							_46$$28 = !zephir_is_true(&_47$$28);
						}
						if (_46$$28) {
							zephir_update_property_zval_zval(this_ptr, &attributeField, &value);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					}
				}
		}
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1019, &rawValues);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[5];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("errorMessages", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD_CACHED(&metaData, this_ptr, "getModelsMetaData", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_1, this_ptr, "getWriteConnection", &_zephir_call_cache[1]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "has", &_zephir_call_cache[2], &metaData, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_create_array(&_2$$3, 1, 0);
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, phalcon_messages_message_ce);
		zephir_constructor_start(&_3$$3);
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_3$$3, "__construct", &_zephir_call_cache[3], &_5$$3, &_6$$3, &_7$$3, &_8$$3, &_4$$3);
		zephir_check_call_status();
		zephir_constructor_finish(&_3$$3);
		zephir_array_fast_append(&_2$$3, &_3$$3);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1020, &_2$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "save", &_zephir_call_cache[4]);
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
	zend_bool _22, _10$$8, _16$$8, _13$$10, _23$$14, _29$$14, _26$$16;
	zval values, bindTypes, conditions;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, metaData, writeConnection, primaryKeys, bindDataTypes, columnMap, attributeField, primaryKey, bindType, value, schema, source, table, success, _0, _1, _2, _3, _5, *_8, *_9, _21, _34, _35, _39, _40, _42, _4$$3, _6$$7, _7$$7, _19$$8, _20$$8, _11$$9, _12$$9, _14$$11, _15$$11, _17$$13, _18$$13, _32$$14, _33$$14, _24$$15, _25$$15, _27$$17, _28$$17, _30$$19, _31$$19, _36$$20, _37$$20, _38$$20, _41$$25, _43$$28, _44$$29, _45$$29, _46$$29, _47$$29;
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
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_42);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_32$$14);
	ZVAL_UNDEF(&_33$$14);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_25$$15);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_28$$17);
	ZVAL_UNDEF(&_30$$19);
	ZVAL_UNDEF(&_31$$19);
	ZVAL_UNDEF(&_36$$20);
	ZVAL_UNDEF(&_37$$20);
	ZVAL_UNDEF(&_38$$20);
	ZVAL_UNDEF(&_41$$25);
	ZVAL_UNDEF(&_43$$28);
	ZVAL_UNDEF(&_44$$29);
	ZVAL_UNDEF(&_45$$29);
	ZVAL_UNDEF(&_46$$29);
	ZVAL_UNDEF(&_47$$29);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&conditions);
	ZEND_TLS zephir_method_cache _zephir_call_cache[32];
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

	ZEPHIR_CALL_METHOD_CACHED(&metaData, this_ptr, "getModelsMetaData", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&writeConnection, this_ptr, "getWriteConnection", &_zephir_call_cache[1]);
	zephir_check_call_status();
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, 3);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1021, &_0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1020, &_1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "orm.virtual_foreign_keys");
	ZEPHIR_CALL_CE_STATIC_CACHED(&_2, phalcon_support_settings_ce, "get", &_zephir_call_cache[2], &_3);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_CALL_METHOD_CACHED(&_4$$3, this_ptr, "checkForeignKeysReverseRestrict", &_zephir_call_cache[3]);
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
	ZEPHIR_CALL_METHOD_CACHED(&primaryKeys, &metaData, "getPrimaryKeyAttributes", &_zephir_call_cache[4], this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&bindDataTypes, &metaData, "getBindTypes", &_zephir_call_cache[5], this_ptr);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "orm.column_renaming");
	ZEPHIR_CALL_CE_STATIC_CACHED(&_5, phalcon_support_settings_ce, "get", &_zephir_call_cache[6], &_3);
	zephir_check_call_status();
	if (zephir_is_true(&_5)) {
		ZEPHIR_CALL_METHOD_CACHED(&columnMap, &metaData, "getColumnMap", &_zephir_call_cache[7], this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&columnMap);
		ZVAL_NULL(&columnMap);
	}
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&primaryKeys))) {
		ZEPHIR_INIT_VAR(&_6$$7);
		object_init_ex(&_6$$7, phalcon_mvc_model_exceptions_primarykeyrequired_ce);
		zephir_constructor_start(&_6$$7);
		ZEPHIR_INIT_VAR(&_7$$7);
		zephir_get_class(&_7$$7, this_ptr, 0);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_6$$7, "__construct", &_zephir_call_cache[8], &_7$$7);
		zephir_check_call_status();
		zephir_constructor_finish(&_6$$7);
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
				zephir_constructor_start(&_11$$9);
				ZEPHIR_INIT_NVAR(&_12$$9);
				zephir_get_class(&_12$$9, this_ptr, 0);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_11$$9, "__construct", &_zephir_call_cache[9], &primaryKey, &_12$$9);
				zephir_check_call_status();
				zephir_constructor_finish(&_11$$9);
				zephir_throw_exception_debug(&_11$$9, "phalcon/Mvc/Model.zep", 2480);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				_13$$10 = zephir_array_isset_fetch(&attributeField, &columnMap, &primaryKey, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_13$$10))) {
					ZEPHIR_INIT_NVAR(&_14$$11);
					object_init_ex(&_14$$11, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
					zephir_constructor_start(&_14$$11);
					ZEPHIR_INIT_NVAR(&_15$$11);
					zephir_get_class(&_15$$11, this_ptr, 0);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_14$$11, "__construct", &_zephir_call_cache[10], &primaryKey, &_15$$11);
					zephir_check_call_status();
					zephir_constructor_finish(&_14$$11);
					zephir_throw_exception_debug(&_14$$11, "phalcon/Mvc/Model.zep", 2488);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &primaryKey);
			}
			ZEPHIR_OBS_NVAR(&value);
			_16$$8 = zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (UNEXPECTED(!(_16$$8))) {
				ZEPHIR_INIT_NVAR(&_17$$13);
				object_init_ex(&_17$$13, phalcon_mvc_model_exceptions_primarykeyattributenotset_ce);
				zephir_constructor_start(&_17$$13);
				ZEPHIR_INIT_NVAR(&_18$$13);
				zephir_get_class(&_18$$13, this_ptr, 0);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_17$$13, "__construct", &_zephir_call_cache[11], &attributeField, &_18$$13);
				zephir_check_call_status();
				zephir_constructor_finish(&_17$$13);
				zephir_throw_exception_debug(&_17$$13, "phalcon/Mvc/Model.zep", 2499);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2505);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&_19$$8, &writeConnection, "escapeIdentifier", &_zephir_call_cache[12], &primaryKey);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_20$$8);
			ZEPHIR_CONCAT_VS(&_20$$8, &_19$$8, " = ?");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&conditions, &_20$$8, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2506);
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, _8, "rewind", &_zephir_call_cache[13]);
		zephir_check_call_status();
		_22 = 1;
		while (1) {
			if (_22) {
				_22 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _8, "next", &_zephir_call_cache[14]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_21, _8, "valid", &_zephir_call_cache[15]);
			zephir_check_call_status();
			if (!zend_is_true(&_21)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&primaryKey, _8, "current", &_zephir_call_cache[16]);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&bindType);
				_23$$14 = zephir_array_isset_fetch(&bindType, &bindDataTypes, &primaryKey, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_23$$14))) {
					ZEPHIR_INIT_NVAR(&_24$$15);
					object_init_ex(&_24$$15, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
					zephir_constructor_start(&_24$$15);
					ZEPHIR_INIT_NVAR(&_25$$15);
					zephir_get_class(&_25$$15, this_ptr, 0);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_24$$15, "__construct", &_zephir_call_cache[17], &primaryKey, &_25$$15);
					zephir_check_call_status();
					zephir_constructor_finish(&_24$$15);
					zephir_throw_exception_debug(&_24$$15, "phalcon/Mvc/Model.zep", 2480);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					_26$$16 = zephir_array_isset_fetch(&attributeField, &columnMap, &primaryKey, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_26$$16))) {
						ZEPHIR_INIT_NVAR(&_27$$17);
						object_init_ex(&_27$$17, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
						zephir_constructor_start(&_27$$17);
						ZEPHIR_INIT_NVAR(&_28$$17);
						zephir_get_class(&_28$$17, this_ptr, 0);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_27$$17, "__construct", &_zephir_call_cache[18], &primaryKey, &_28$$17);
						zephir_check_call_status();
						zephir_constructor_finish(&_27$$17);
						zephir_throw_exception_debug(&_27$$17, "phalcon/Mvc/Model.zep", 2488);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &primaryKey);
				}
				ZEPHIR_OBS_NVAR(&value);
				_29$$14 = zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_29$$14))) {
					ZEPHIR_INIT_NVAR(&_30$$19);
					object_init_ex(&_30$$19, phalcon_mvc_model_exceptions_primarykeyattributenotset_ce);
					zephir_constructor_start(&_30$$19);
					ZEPHIR_INIT_NVAR(&_31$$19);
					zephir_get_class(&_31$$19, this_ptr, 0);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_30$$19, "__construct", &_zephir_call_cache[19], &attributeField, &_31$$19);
					zephir_check_call_status();
					zephir_constructor_finish(&_30$$19);
					zephir_throw_exception_debug(&_30$$19, "phalcon/Mvc/Model.zep", 2499);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2505);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_32$$14, &writeConnection, "escapeIdentifier", &_zephir_call_cache[20], &primaryKey);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_33$$14);
				ZEPHIR_CONCAT_VS(&_33$$14, &_32$$14, " = ?");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&conditions, &_33$$14, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2506);
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
	ZEPHIR_INIT_VAR(&_35);
	ZVAL_STRING(&_35, "orm.events");
	ZEPHIR_CALL_CE_STATIC_CACHED(&_34, phalcon_support_settings_ce, "get", &_zephir_call_cache[21], &_35);
	zephir_check_call_status();
	if (zephir_is_true(&_34)) {
		if (0) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1022, &__$true);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1022, &__$false);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_INIT_VAR(&_37$$20);
		ZVAL_STRING(&_37$$20, "beforeDelete");
		ZEPHIR_CALL_METHOD_CACHED(&_36$$20, this_ptr, "fireEventCancel", &_zephir_call_cache[22], &_37$$20);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_36$$20)) {
			RETURN_MM_BOOL(0);
		}
		zephir_read_property_cached(&_38$$20, this_ptr, _zephir_prop_2, 1022, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_38$$20)) {
			RETURN_MM_BOOL(1);
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&schema, this_ptr, "getSchema", &_zephir_call_cache[23]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&source, this_ptr, "getSource", &_zephir_call_cache[24]);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	ZEPHIR_INIT_NVAR(&_35);
	zephir_fast_join_str(&_35, SL(" AND "), &conditions);
	ZEPHIR_CALL_METHOD_CACHED(&success, &writeConnection, "delete", &_zephir_call_cache[25], &table, &_35, &values, &bindTypes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_40);
	ZVAL_STRING(&_40, "orm.virtual_foreign_keys");
	ZEPHIR_CALL_CE_STATIC_CACHED(&_39, phalcon_support_settings_ce, "get", &_zephir_call_cache[26], &_40);
	zephir_check_call_status();
	if (zephir_is_true(&_39)) {
		ZEPHIR_CALL_METHOD_CACHED(&_41$$25, this_ptr, "checkForeignKeysReverseCascade", &_zephir_call_cache[27]);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_41$$25)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(&_40);
	ZVAL_STRING(&_40, "orm.events");
	ZEPHIR_CALL_CE_STATIC_CACHED(&_42, phalcon_support_settings_ce, "get", &_zephir_call_cache[28], &_40);
	zephir_check_call_status();
	if (zephir_is_true(&_42)) {
		if (zephir_is_true(&success)) {
			ZEPHIR_INIT_VAR(&_43$$28);
			ZVAL_STRING(&_43$$28, "afterDelete");
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "fireEvent", &_zephir_call_cache[29], &_43$$28);
			zephir_check_call_status();
		}
	}
	if (zephir_is_true(&success)) {
		zephir_read_property_cached(&_44$$29, this_ptr, _zephir_prop_3, 1014, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_44$$29, "registerWrite", &_zephir_call_cache[30], this_ptr);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_45$$29);
		array_init(&_45$$29);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1016, &_45$$29);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_46$$29);
		array_init(&_46$$29);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1015, &_46$$29);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_47$$29, this_ptr, _zephir_prop_3, 1014, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_47$$29, "clearReusableObjects", &_zephir_call_cache[31]);
		zephir_check_call_status();
	}
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, 2);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 1017, &_0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	zend_bool hasRelatedToSave = 0, _15$$4, _20$$21, _27$$25;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *visited, visited_sub, e, exists, identityField, manager, metaData, objId, relatedToSave, schema, source, success, table, writeConnection, savedSnapshot, savedOldSnapshot, _0, _1, _23, _24, _2$$5, _3$$6, _4$$9, _5$$10, _6$$4, _7$$4, _14$$4, _16$$4, _17$$4, _8$$11, _9$$11, _10$$11, _11$$12, _12$$12, _13$$13, _18$$17, _19$$19, _21$$21, _22$$22, _25$$24, _26$$25, _28$$25, _29$$25, _30$$28, _31$$27, _32$$27, _33$$27;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&visited_sub);
	ZVAL_UNDEF(&e);
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
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$10);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&_18$$17);
	ZVAL_UNDEF(&_19$$19);
	ZVAL_UNDEF(&_21$$21);
	ZVAL_UNDEF(&_22$$22);
	ZVAL_UNDEF(&_25$$24);
	ZVAL_UNDEF(&_26$$25);
	ZVAL_UNDEF(&_28$$25);
	ZVAL_UNDEF(&_29$$25);
	ZVAL_UNDEF(&_30$$28);
	ZVAL_UNDEF(&_31$$27);
	ZVAL_UNDEF(&_32$$27);
	ZVAL_UNDEF(&_33$$27);
	ZEND_TLS zephir_method_cache _zephir_call_cache[32];
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
	ZEPHIR_CALL_FUNCTION(&objId, "spl_object_id", NULL, 31, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_0, visited, "has", &_zephir_call_cache[0], &objId);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, visited, "set", &_zephir_call_cache[1], &objId, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&metaData, this_ptr, "getModelsMetaData", &_zephir_call_cache[2]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&writeConnection, this_ptr, "getWriteConnection", &_zephir_call_cache[3]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "prepareSave");
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "fireEvent", &_zephir_call_cache[4], &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&relatedToSave, this_ptr, "collectRelatedToSave", &_zephir_call_cache[5]);
	zephir_check_call_status();
	hasRelatedToSave = !(ZEPHIR_IS_EMPTY(&relatedToSave));

	/* try_start_1: */

		if (hasRelatedToSave) {
			ZEPHIR_CALL_METHOD_CACHED(&_2$$5, this_ptr, "preSaveRelatedRecords", &_zephir_call_cache[6], &writeConnection, &relatedToSave, visited);
			zephir_check_call_status_or_jump(try_end_1);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_2$$5)) {
				ZEPHIR_INIT_VAR(&_3$$6);
				array_init(&_3$$6);
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1023, &_3$$6);
				if (UNEXPECTED(EG(exception))) {
					goto try_end_1;
				}
				RETURN_MM_BOOL(0);
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&schema, this_ptr, "getSchema", &_zephir_call_cache[7]);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD_CACHED(&source, this_ptr, "getSource", &_zephir_call_cache[8]);
		zephir_check_call_status_or_jump(try_end_1);
		if (zephir_is_true(&schema)) {
			ZEPHIR_INIT_VAR(&table);
			zephir_create_array(&table, 2, 0);
			zephir_array_fast_append(&table, &schema);
			zephir_array_fast_append(&table, &source);
		} else {
			ZEPHIR_CPY_WRT(&table, &source);
		}
		ZEPHIR_CALL_METHOD_CACHED(&exists, this_ptr, "has", &_zephir_call_cache[9], &metaData, &writeConnection);
		zephir_check_call_status_or_jump(try_end_1);
		if (zephir_is_true(&exists)) {
			ZVAL_UNDEF(&_4$$9);
			ZVAL_LONG(&_4$$9, 2);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1021, &_4$$9);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_1;
			}
		} else {
			ZVAL_UNDEF(&_5$$10);
			ZVAL_LONG(&_5$$10, 1);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1021, &_5$$10);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_1;
			}
		}
		ZEPHIR_INIT_VAR(&_6$$4);
		array_init(&_6$$4);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1020, &_6$$4);
		if (UNEXPECTED(EG(exception))) {
			goto try_end_1;
		}
		ZEPHIR_CALL_METHOD_CACHED(&identityField, &metaData, "getIdentityField", &_zephir_call_cache[10], this_ptr);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD_CACHED(&_7$$4, this_ptr, "preSave", &_zephir_call_cache[11], &metaData, &exists, &identityField);
		zephir_check_call_status_or_jump(try_end_1);
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_7$$4)) {
			ZEPHIR_INIT_VAR(&_8$$11);
			array_init(&_8$$11);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1023, &_8$$11);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_1;
			}
			ZEPHIR_INIT_VAR(&_10$$11);
			ZVAL_STRING(&_10$$11, "orm.exception_on_failed_save");
			ZEPHIR_CALL_CE_STATIC_CACHED(&_9$$11, phalcon_support_settings_ce, "get", &_zephir_call_cache[12], &_10$$11);
			zephir_check_call_status_or_jump(try_end_1);
			if (UNEXPECTED(zephir_is_true(&_9$$11))) {
				ZEPHIR_INIT_VAR(&_11$$12);
				object_init_ex(&_11$$12, phalcon_mvc_model_validationfailed_ce);
				zephir_constructor_start(&_11$$12);
				ZEPHIR_CALL_METHOD_CACHED(&_12$$12, this_ptr, "getMessages", &_zephir_call_cache[13]);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_11$$12, "__construct", &_zephir_call_cache[14], this_ptr, &_12$$12);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_constructor_finish(&_11$$12);
				zephir_throw_exception_debug(&_11$$12, "phalcon/Mvc/Model.zep", 2699);
				goto try_end_1;

			}
			if (hasRelatedToSave) {
				ZVAL_BOOL(&_13$$13, 0);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &writeConnection, "rollback", &_zephir_call_cache[15], &_13$$13);
				zephir_check_call_status_or_jump(try_end_1);
			}
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_CALL_METHOD_CACHED(&manager, this_ptr, "getModelsManager", &_zephir_call_cache[16]);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD_CACHED(&_14$$4, &manager, "isKeepingSnapshots", &_zephir_call_cache[17], this_ptr);
		zephir_check_call_status_or_jump(try_end_1);
		_15$$4 = zephir_is_true(&_14$$4);
		if (_15$$4) {
			ZEPHIR_INIT_VAR(&_17$$4);
			ZVAL_STRING(&_17$$4, "orm.update_snapshot_on_save");
			ZEPHIR_CALL_CE_STATIC_CACHED(&_16$$4, phalcon_support_settings_ce, "get", &_zephir_call_cache[18], &_17$$4);
			zephir_check_call_status_or_jump(try_end_1);
			_15$$4 = zephir_is_true(&_16$$4);
		}
		if (_15$$4) {
			ZEPHIR_OBS_NVAR(&savedSnapshot);
			zephir_read_property_cached(&savedSnapshot, this_ptr, _zephir_prop_3, 1018, PH_NOISY_CC);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_1;
			}
			ZEPHIR_OBS_NVAR(&savedOldSnapshot);
			zephir_read_property_cached(&savedOldSnapshot, this_ptr, _zephir_prop_4, 1024, PH_NOISY_CC);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_1;
			}
		}
		if (zephir_is_true(&exists)) {
			ZEPHIR_CALL_METHOD_CACHED(&success, this_ptr, "doLowUpdate", &_zephir_call_cache[19], &metaData, &writeConnection, &table);
			zephir_check_call_status_or_jump(try_end_1);
		} else {
			ZEPHIR_CALL_METHOD_CACHED(&success, this_ptr, "doLowInsert", &_zephir_call_cache[20], &metaData, &writeConnection, &table, &identityField);
			zephir_check_call_status_or_jump(try_end_1);
		}
		if (ZEPHIR_IS_TRUE_IDENTICAL(&success)) {
			ZVAL_UNDEF(&_18$$17);
			ZVAL_LONG(&_18$$17, 0);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1017, &_18$$17);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_1;
			}
		}
		if (hasRelatedToSave) {
			if (ZEPHIR_IS_FALSE_IDENTICAL(&success)) {
				ZVAL_BOOL(&_19$$19, 0);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &writeConnection, "rollback", &_zephir_call_cache[21], &_19$$19);
				zephir_check_call_status_or_jump(try_end_1);
			} else {
				ZEPHIR_CALL_METHOD_CACHED(&success, this_ptr, "postSaveRelatedRecords", &_zephir_call_cache[22], &writeConnection, &relatedToSave, visited);
				zephir_check_call_status_or_jump(try_end_1);
			}
		}

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_OBJ(&_1, EG(exception));
		Z_ADDREF_P(&_1);
		if (zephir_is_instance_of(&_1, SL("Throwable"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&e, &_1);
			_20$$21 = hasRelatedToSave;
			if (_20$$21) {
				ZEPHIR_CALL_METHOD_CACHED(&_21$$21, &writeConnection, "isUnderTransaction", &_zephir_call_cache[23]);
				zephir_check_call_status();
				_20$$21 = zephir_is_true(&_21$$21);
			}
			if (_20$$21) {
				ZVAL_BOOL(&_22$$22, 0);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &writeConnection, "rollback", &_zephir_call_cache[24], &_22$$22);
				zephir_check_call_status();
			}
			zephir_throw_exception_debug(&e, "phalcon/Mvc/Model.zep", 2770);
			ZEPHIR_MM_RESTORE();
			return;
		} else {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&_24);
	ZVAL_STRING(&_24, "orm.events");
	ZEPHIR_CALL_CE_STATIC_CACHED(&_23, phalcon_support_settings_ce, "get", &_zephir_call_cache[25], &_24);
	zephir_check_call_status();
	if (zephir_is_true(&_23)) {
		ZEPHIR_CALL_METHOD_CACHED(&_25$$24, this_ptr, "postSave", &_zephir_call_cache[26], &success, &exists);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&success, &_25$$24);
	}
	if (ZEPHIR_IS_FALSE_IDENTICAL(&success)) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "cancelOperation", &_zephir_call_cache[27]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_26$$25, &manager, "isKeepingSnapshots", &_zephir_call_cache[28], this_ptr);
		zephir_check_call_status();
		_27$$25 = zephir_is_true(&_26$$25);
		if (_27$$25) {
			ZEPHIR_INIT_VAR(&_29$$25);
			ZVAL_STRING(&_29$$25, "orm.update_snapshot_on_save");
			ZEPHIR_CALL_CE_STATIC_CACHED(&_28$$25, phalcon_support_settings_ce, "get", &_zephir_call_cache[29], &_29$$25);
			zephir_check_call_status();
			_27$$25 = zephir_is_true(&_28$$25);
		}
		if (_27$$25) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1018, &savedSnapshot);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1024, &savedOldSnapshot);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} else {
		if (hasRelatedToSave) {
			ZEPHIR_INIT_VAR(&_30$$28);
			array_init(&_30$$28);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 1015, &_30$$28);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_INIT_VAR(&_31$$27);
		array_init(&_31$$27);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 1016, &_31$$27);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_32$$27, this_ptr, _zephir_prop_8, 1014, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_32$$27, "clearReusableObjects", &_zephir_call_cache[30]);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_33$$27);
		ZVAL_STRING(&_33$$27, "afterSave");
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "fireEvent", &_zephir_call_cache[31], &_33$$27);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_24);
	array_init(&_24);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1023, &_24);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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

	ZEPHIR_RETURN_CALL_FUNCTION("get_object_vars", NULL, 109, this_ptr);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_0, "notifyEvent", &_zephir_call_cache[0], &eventName_zv, this_ptr);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_1, "notifyEvent", &_zephir_call_cache[0], &eventName_zv, this_ptr);
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
	zend_bool _13, _9$$6, _10$$6, _14$$10, _15$$10;
	zend_string *_8;
	zend_ulong _7;
	zval changed;
	zval metaData, name, snapshot, columnMap, allAttributes, value, _0, *_3, _4, _5, *_6, _12, _1$$3, _2$$3, _11$$6, _16$$10;
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
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&changed);
	ZEND_TLS zephir_method_cache _zephir_call_cache[9];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("snapshot", 8, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1018, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&snapshot, &_0);
	if (UNEXPECTED(Z_TYPE_P(&snapshot) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_exceptions_snapshotsdisabled_ce);
		zephir_constructor_start(&_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_get_class(&_2$$3, this_ptr, 0);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0], &_2$$3);
		zephir_check_call_status();
		zephir_constructor_finish(&_1$$3);
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model.zep", 2896);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&metaData, this_ptr, "getModelsMetaData", &_zephir_call_cache[1]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&columnMap, &metaData, "getReverseColumnMap", &_zephir_call_cache[2], this_ptr);
	zephir_check_call_status();
	if (Z_TYPE_P(&columnMap) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD_CACHED(&allAttributes, &metaData, "getDataTypes", &_zephir_call_cache[3], this_ptr);
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
	zephir_is_iterable(_3, 0, "phalcon/Mvc/Model.zep", 2957);
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
				zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2932);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				continue;
			}
			ZEPHIR_OBS_NVAR(&value);
			_10$$6 = zephir_fetch_property_zval(&value, this_ptr, &name, PH_SILENT_CC);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_10$$6)) {
				zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2942);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				continue;
			}
			ZEPHIR_OBS_NVAR(&_11$$6);
			zephir_array_fetch(&_11$$6, &snapshot, &name, PH_NOISY, "phalcon/Mvc/Model.zep", 2950);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!ZEPHIR_IS_IDENTICAL(&value, &_11$$6)) {
				zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2951);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				continue;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _3, "rewind", &_zephir_call_cache[4]);
		zephir_check_call_status();
		_13 = 1;
		while (1) {
			if (_13) {
				_13 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _3, "next", &_zephir_call_cache[5]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_12, _3, "valid", &_zephir_call_cache[6]);
			zephir_check_call_status();
			if (!zend_is_true(&_12)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&name, _3, "key", &_zephir_call_cache[7]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&_5, _3, "current", &_zephir_call_cache[8]);
			zephir_check_call_status();
				_14$$10 = zephir_array_key_exists(&snapshot, &name);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_14$$10)) {
					zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2932);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
				ZEPHIR_OBS_NVAR(&value);
				_15$$10 = zephir_fetch_property_zval(&value, this_ptr, &name, PH_SILENT_CC);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_15$$10)) {
					zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2942);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
				ZEPHIR_OBS_NVAR(&_16$$10);
				zephir_array_fetch(&_16$$10, &snapshot, &name, PH_NOISY, "phalcon/Mvc/Model.zep", 2950);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!ZEPHIR_IS_IDENTICAL(&value, &_16$$10)) {
					zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 2951);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
		}
	}
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_0, "getCustomEventsManager", &_zephir_call_cache[0], this_ptr);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[6];
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
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(&_3$$3) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_5$$3);
			zephir_string_to_char_array(&_5$$3, &_3$$3);
			_4$$3 = &_5$$3;
		} else {
			_4$$3 = &_3$$3;
		}
		zephir_is_iterable(_4$$3, 0, "phalcon/Mvc/Model.zep", 3023);
		if (Z_TYPE_P(_4$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_4$$3), _6$$3)
			{
				ZEPHIR_INIT_NVAR(&message);
				ZVAL_COPY(&message, _6$$3);
				ZEPHIR_CALL_METHOD_CACHED(&_7$$5, &message, "getField", &_zephir_call_cache[0]);
				zephir_check_call_status();
				_8$$5 = zephir_fast_in_array(&_7$$5, filter);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_8$$5) {
					zephir_array_append(&filtered, &message, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3019);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _4$$3, "rewind", &_zephir_call_cache[1]);
			zephir_check_call_status();
			_10$$3 = 1;
			while (1) {
				if (_10$$3) {
					_10$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _4$$3, "next", &_zephir_call_cache[2]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_9$$3, _4$$3, "valid", &_zephir_call_cache[3]);
				zephir_check_call_status();
				if (!zend_is_true(&_9$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&message, _4$$3, "current", &_zephir_call_cache[4]);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_11$$7, &message, "getField", &_zephir_call_cache[5]);
					zephir_check_call_status();
					_12$$7 = zephir_fast_in_array(&_11$$7, filter);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_12$$7) {
						zephir_array_append(&filtered, &message, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3019);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
			}
		}
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&metaData) == IS_NULL) {
		zephir_read_property_cached(&_0$$3, this_ptr, _zephir_prop_1, 1013, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&container, &_0$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "modelsMetadata");
		ZEPHIR_CALL_METHOD_CACHED(&_1$$3, &container, "getShared", &_zephir_call_cache[0], &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&metaData, &_1$$3);
		if (UNEXPECTED(Z_TYPE_P(&metaData) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_3$$4);
			object_init_ex(&_3$$4, phalcon_mvc_model_exceptions_invalidmodelsmetadataservice_ce);
			zephir_constructor_start(&_3$$4);
			ZEPHIR_INIT_VAR(&_4$$4);
			zephir_get_class(&_4$$4, this_ptr, 0);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_3$$4, "__construct", &_zephir_call_cache[1], &_4$$4);
			zephir_check_call_status();
			zephir_constructor_finish(&_3$$4);
			zephir_throw_exception_debug(&_3$$4, "phalcon/Mvc/Model.zep", 3055);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1025, &metaData);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_0) != IS_NULL) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 1026, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_RETURN_CALL_METHOD_CACHED(&_1$$3, "getConnection", &_zephir_call_cache[0]);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 1014, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_2, "getReadConnection", &_zephir_call_cache[1], this_ptr);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_0, "getReadConnectionService", &_zephir_call_cache[0], this_ptr);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_INIT_VAR(&lowerAlias);
	zephir_fast_strtolower(&lowerAlias, &alias_zv);
	ZEPHIR_CALL_METHOD_CACHED(&_1, &manager, "getRelationByAlias", &_zephir_call_cache[0], &className, &lowerAlias);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&relation, &_1);
	if (UNEXPECTED(Z_TYPE_P(&relation) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_mvc_model_exceptions_relationnotdefined_ce);
		zephir_constructor_start(&_2$$3);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$3, "__construct", &_zephir_call_cache[1], &className, &alias_zv);
		zephir_check_call_status();
		zephir_constructor_finish(&_2$$3);
		zephir_throw_exception_debug(&_2$$3, "phalcon/Mvc/Model.zep", 3130);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(arguments) == IS_NULL) {
		zephir_read_property_cached(&_3$$4, this_ptr, _zephir_prop_1, 1015, PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_4$$4 = zephir_array_isset_value(&_3$$4, &lowerAlias);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_4$$4) {
			zephir_read_property_cached(&_5$$5, this_ptr, _zephir_prop_1, 1015, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_memory_observe(&_6$$5);
			zephir_array_fetch(&_6$$5, &_5$$5, &lowerAlias, PH_NOISY, "phalcon/Mvc/Model.zep", 3155);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_CCTOR(&_6$$5);
		}
		zephir_read_property_cached(&_7$$4, this_ptr, _zephir_prop_2, 1016, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_8$$4 = zephir_array_key_exists(&_7$$4, &lowerAlias);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_8$$4) {
			zephir_read_property_cached(&_9$$6, this_ptr, _zephir_prop_2, 1016, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_memory_observe(&_10$$6);
			zephir_array_fetch(&_10$$6, &_9$$6, &lowerAlias, PH_NOISY, "phalcon/Mvc/Model.zep", 3166);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_CCTOR(&_10$$6);
		}
		ZEPHIR_CALL_METHOD_CACHED(&result, &manager, "getRelationRecords", &_zephir_call_cache[2], &relation, this_ptr, arguments);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("related"), &lowerAlias, &result);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_CALL_METHOD_CACHED(&result, &manager, "getRelationRecords", &_zephir_call_cache[3], &relation, this_ptr, arguments);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_0, "getModelSchema", &_zephir_call_cache[0], this_ptr);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_0, "getModelSource", &_zephir_call_cache[0], this_ptr);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[9];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&snapshot, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1024, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&oldSnapshot, &_0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "orm.update_snapshot_on_save");
	ZEPHIR_CALL_CE_STATIC_CACHED(&_1, phalcon_support_settings_ce, "get", &_zephir_call_cache[0], &_2);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_1))) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, phalcon_mvc_model_exceptions_updatesnapshotdisabled_ce);
		zephir_constructor_start(&_3$$3);
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_get_class(&_4$$3, this_ptr, 0);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_3$$3, "__construct", &_zephir_call_cache[1], &_4$$3);
		zephir_check_call_status();
		zephir_constructor_finish(&_3$$3);
		zephir_throw_exception_debug(&_3$$3, "phalcon/Mvc/Model.zep", 3251);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(Z_TYPE_P(&snapshot) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_5$$4);
		object_init_ex(&_5$$4, phalcon_mvc_model_exceptions_snapshotsdisabled_ce);
		zephir_constructor_start(&_5$$4);
		ZEPHIR_INIT_VAR(&_6$$4);
		zephir_get_class(&_6$$4, this_ptr, 0);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_5$$4, "__construct", &_zephir_call_cache[2], &_6$$4);
		zephir_check_call_status();
		zephir_constructor_finish(&_5$$4);
		zephir_throw_exception_debug(&_5$$4, "phalcon/Mvc/Model.zep", 3255);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 1017, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!ZEPHIR_IS_LONG(&_0, 0))) {
		ZEPHIR_INIT_VAR(&_7$$5);
		object_init_ex(&_7$$5, phalcon_mvc_model_exceptions_recordnotpersisted_ce);
		zephir_constructor_start(&_7$$5);
		ZEPHIR_INIT_VAR(&_8$$5);
		zephir_get_class(&_8$$5, this_ptr, 0);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_7$$5, "__construct", &_zephir_call_cache[3], &_8$$5);
		zephir_check_call_status();
		zephir_constructor_finish(&_7$$5);
		zephir_throw_exception_debug(&_7$$5, "phalcon/Mvc/Model.zep", 3262);
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
	zephir_is_iterable(_9, 0, "phalcon/Mvc/Model.zep", 3280);
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
				zephir_array_fetch(&_15$$6, &oldSnapshot, &name, PH_NOISY, "phalcon/Mvc/Model.zep", 3275);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_14$$6 = !ZEPHIR_IS_IDENTICAL(&value, &_15$$6);
			}
			if (_14$$6) {
				zephir_array_append(&updated, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3276);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _9, "rewind", &_zephir_call_cache[4]);
		zephir_check_call_status();
		_17 = 1;
		while (1) {
			if (_17) {
				_17 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _9, "next", &_zephir_call_cache[5]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_16, _9, "valid", &_zephir_call_cache[6]);
			zephir_check_call_status();
			if (!zend_is_true(&_16)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&name, _9, "key", &_zephir_call_cache[7]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&value, _9, "current", &_zephir_call_cache[8]);
			zephir_check_call_status();
				_18$$8 = zephir_array_key_exists(&oldSnapshot, &name);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_19$$8 = !(_18$$8);
				if (!(_19$$8)) {
					ZEPHIR_OBS_NVAR(&_20$$8);
					zephir_array_fetch(&_20$$8, &oldSnapshot, &name, PH_NOISY, "phalcon/Mvc/Model.zep", 3275);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_19$$8 = !ZEPHIR_IS_IDENTICAL(&value, &_20$$8);
				}
				if (_19$$8) {
					zephir_array_append(&updated, &name, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3276);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
		}
	}
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_0) != IS_NULL) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 1026, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_RETURN_CALL_METHOD_CACHED(&_1$$3, "getConnection", &_zephir_call_cache[0]);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 1014, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_2, "getWriteConnection", &_zephir_call_cache[1], this_ptr);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_0, "getWriteConnectionService", &_zephir_call_cache[0], this_ptr);
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
	zend_bool allFields = 0, _0$$3, _1$$5;
	zval *fieldName = NULL, fieldName_sub, *allFields_param = NULL, __$null, changedFields, intersect;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fieldName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&changedFields);
	ZVAL_UNDEF(&intersect);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_CALL_METHOD_CACHED(&changedFields, this_ptr, "getChangedFields", &_zephir_call_cache[0]);
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
		ZEPHIR_CALL_FUNCTION(&intersect, "array_intersect", NULL, 228, fieldName, &changedFields);
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
	zend_bool _0;
	zval *this_ptr = getThis();

	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("snapshot", 8, 1);
	}
	_0 = zephir_isempty_property_fast(this_ptr, _zephir_prop_0);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_BOOL(!(_0));
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
	zend_bool allFields = 0, _0$$3, _1$$5;
	zval *fieldName = NULL, fieldName_sub, *allFields_param = NULL, __$null, updatedFields, intersect;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fieldName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&updatedFields);
	ZVAL_UNDEF(&intersect);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_CALL_METHOD_CACHED(&updatedFields, this_ptr, "getUpdatedFields", &_zephir_call_cache[0]);
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
		ZEPHIR_CALL_FUNCTION(&intersect, "array_intersect", NULL, 228, fieldName, &updatedFields);
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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

	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "toArray", &_zephir_call_cache[0]);
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&_1);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[23];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!ZEPHIR_IS_LONG(&_0, 0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_exceptions_recordcannotrefresh_ce);
		zephir_constructor_start(&_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_get_class(&_2$$3, this_ptr, 0);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0], &_2$$3);
		zephir_check_call_status();
		zephir_constructor_finish(&_1$$3);
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model.zep", 3459);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&metaData, this_ptr, "getModelsMetaData", &_zephir_call_cache[1]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&readConnection, this_ptr, "getReadConnection", &_zephir_call_cache[2]);
	zephir_check_call_status();
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 1014, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&manager, &_3);
	ZEPHIR_CALL_METHOD_CACHED(&schema, this_ptr, "getSchema", &_zephir_call_cache[3]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&source, this_ptr, "getSource", &_zephir_call_cache[4]);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_2, 1027, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&uniqueKey, &_3);
	if (!(zephir_is_true(&uniqueKey))) {
		ZEPHIR_CALL_METHOD_CACHED(&_4$$6, this_ptr, "has", &_zephir_call_cache[5], &metaData, &readConnection);
		zephir_check_call_status();
		if (UNEXPECTED(!zephir_is_true(&_4$$6))) {
			ZEPHIR_INIT_VAR(&_5$$7);
			object_init_ex(&_5$$7, phalcon_mvc_model_exceptions_recordcannotrefresh_ce);
			zephir_constructor_start(&_5$$7);
			ZEPHIR_INIT_VAR(&_6$$7);
			zephir_get_class(&_6$$7, this_ptr, 0);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_5$$7, "__construct", &_zephir_call_cache[6], &_6$$7);
			zephir_check_call_status();
			zephir_constructor_finish(&_5$$7);
			zephir_throw_exception_debug(&_5$$7, "phalcon/Mvc/Model.zep", 3482);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_7$$6, this_ptr, _zephir_prop_2, 1027, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&uniqueKey, &_7$$6);
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_3, 1028, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&uniqueParams, &_3);
	if (UNEXPECTED(Z_TYPE_P(&uniqueParams) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_8$$8);
		object_init_ex(&_8$$8, phalcon_mvc_model_exceptions_recordcannotrefresh_ce);
		zephir_constructor_start(&_8$$8);
		ZEPHIR_INIT_VAR(&_9$$8);
		zephir_get_class(&_9$$8, this_ptr, 0);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_8$$8, "__construct", &_zephir_call_cache[7], &_9$$8);
		zephir_check_call_status();
		zephir_constructor_finish(&_8$$8);
		zephir_throw_exception_debug(&_8$$8, "phalcon/Mvc/Model.zep", 3491);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&fields);
	array_init(&fields);
	ZEPHIR_CALL_METHOD_CACHED(&_10, &metaData, "getAttributes", &_zephir_call_cache[8], this_ptr);
	zephir_check_call_status();
	if (Z_TYPE_P(&_10) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_12);
		zephir_string_to_char_array(&_12, &_10);
		_11 = &_12;
	} else {
		_11 = &_10;
	}
	zephir_is_iterable(_11, 0, "phalcon/Mvc/Model.zep", 3506);
	if (Z_TYPE_P(_11) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_11), _13)
		{
			ZEPHIR_INIT_NVAR(&attribute);
			ZVAL_COPY(&attribute, _13);
			ZEPHIR_INIT_NVAR(&_14$$9);
			zephir_create_array(&_14$$9, 1, 0);
			zephir_array_fast_append(&_14$$9, &attribute);
			zephir_array_append(&fields, &_14$$9, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3500);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _11, "rewind", &_zephir_call_cache[9]);
		zephir_check_call_status();
		_16 = 1;
		while (1) {
			if (_16) {
				_16 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _11, "next", &_zephir_call_cache[10]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_15, _11, "valid", &_zephir_call_cache[11]);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&attribute, _11, "current", &_zephir_call_cache[12]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_17$$10);
				zephir_create_array(&_17$$10, 1, 0);
				zephir_array_fast_append(&_17$$10, &attribute);
				zephir_array_append(&fields, &_17$$10, PH_SEPARATE, "phalcon/Mvc/Model.zep", 3500);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&dialect, &readConnection, "getDialect", &_zephir_call_cache[13]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_18);
	zephir_create_array(&_18, 3, 0);
	zephir_array_update_string(&_18, SL("columns"), &fields, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD_CACHED(&_19, &readConnection, "escapeIdentifier", &_zephir_call_cache[14], &table);
	zephir_check_call_status();
	zephir_array_update_string(&_18, SL("tables"), &_19, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_18, SL("where"), &uniqueKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD_CACHED(&tables, &dialect, "select", &_zephir_call_cache[15], &_18);
	zephir_check_call_status();
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_4, 1029, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZVAL_LONG(&_20, 2);
	ZEPHIR_CALL_METHOD_CACHED(&row, &readConnection, "fetchOne", &_zephir_call_cache[16], &tables, &_20, &uniqueParams, &_3);
	zephir_check_call_status();
	if (Z_TYPE_P(&row) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD_CACHED(&columnMap, &metaData, "getColumnMap", &_zephir_call_cache[17], this_ptr);
		zephir_check_call_status();
		ZVAL_NULL(&_21$$11);
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "assign", &_zephir_call_cache[18], &row, &_21$$11, &columnMap);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_22$$11, &manager, "isKeepingSnapshots", &_zephir_call_cache[19], this_ptr);
		zephir_check_call_status();
		if (zephir_is_true(&_22$$11)) {
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "setSnapshotData", &_zephir_call_cache[20], &row, &columnMap);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "setOldSnapshotData", &_zephir_call_cache[21], &row, &columnMap);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_VAR(&_23);
	ZVAL_STRING(&_23, "afterFetch");
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "fireEvent", &_zephir_call_cache[22], &_23);
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
	zval visited, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&visited);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_support_collection_ce);
	zephir_constructor_start(&_0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[0]);
	zephir_check_call_status();
	zephir_constructor_finish(&_0);
	ZEPHIR_CPY_WRT(&visited, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "doSave", &_zephir_call_cache[1], &visited);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
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
	ZEPHIR_CALL_METHOD_CACHED(&attributes, this_ptr, "toArray", &_zephir_call_cache[0], &_0, &_1);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1017, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&dirtyState, &_0);
	ZEPHIR_CALL_METHOD_CACHED(&_2, this_ptr, "getModelsManager", &_zephir_call_cache[1]);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_2);
	ZEPHIR_CALL_METHOD_CACHED(&_2, &manager, "isKeepingSnapshots", &_zephir_call_cache[2], this_ptr);
	zephir_check_call_status();
	_3 = zephir_is_true(&_2);
	if (_3) {
		zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1018, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_3 = Z_TYPE_P(&_0) != IS_NULL;
	}
	_4 = _3;
	if (_4) {
		zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 1018, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_5 = !ZEPHIR_IS_EQUAL(&attributes, &_1);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_4 = _5;
	}
	if (_4) {
		zephir_read_property_cached(&_6$$3, this_ptr, _zephir_prop_1, 1018, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&snapshot, &_6$$3);
	}
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 3, 0);
	zephir_array_update_string(&_7, SL("attributes"), &attributes, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_7, SL("snapshot"), &snapshot, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_7, SL("dirtyState"), &dirtyState, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 13, &_7);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "setConnectionService", &_zephir_call_cache[0], this_ptr, &connectionService_zv);
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
	if (UNEXPECTED(EG(exception))) {
		return;
	}
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "setCustomEventsManager", &_zephir_call_cache[0], this_ptr, eventsManager);
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
	zend_bool _15$$3, _3$$4, _9$$8, _16$$11, _22$$15;
	zend_string *_2$$3;
	zend_ulong _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *columnMap = NULL, columnMap_sub, __$null, key, value, attribute, *_0$$3, _14$$3, _4$$6, _5$$6, _6$$7, _7$$7, _8$$8, _10$$9, _11$$9, _12$$10, _13$$10, _17$$13, _18$$13, _19$$14, _20$$14, _21$$15, _23$$16, _24$$16, _25$$17, _26$$17;
	zval data, snapshot;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_23$$16);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_26$$17);
	ZEND_TLS zephir_method_cache _zephir_call_cache[13];
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
		zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 3681);
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
					ZEPHIR_INIT_NVAR(&_5$$6);
					ZVAL_STRING(&_5$$6, "orm.ignore_unknown_columns");
					ZEPHIR_CALL_CE_STATIC_CACHED(&_4$$6, phalcon_support_settings_ce, "get", &_zephir_call_cache[0], &_5$$6);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&_4$$6))) {
						ZEPHIR_INIT_NVAR(&_6$$7);
						object_init_ex(&_6$$7, phalcon_mvc_model_exceptions_columnnotinmap_ce);
						zephir_constructor_start(&_6$$7);
						ZEPHIR_INIT_NVAR(&_7$$7);
						zephir_get_class(&_7$$7, this_ptr, 0);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_6$$7, "__construct", &_zephir_call_cache[1], &key, &_7$$7);
						zephir_check_call_status();
						zephir_constructor_finish(&_6$$7);
						zephir_throw_exception_debug(&_6$$7, "phalcon/Mvc/Model.zep", 3663);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
				if (Z_TYPE_P(&attribute) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&_8$$8);
					_9$$8 = zephir_array_isset_long_fetch(&_8$$8, &attribute, 0, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CPY_WRT(&attribute, &_8$$8);
					if (!(_9$$8)) {
						ZEPHIR_INIT_NVAR(&_11$$9);
						ZVAL_STRING(&_11$$9, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC_CACHED(&_10$$9, phalcon_support_settings_ce, "get", &_zephir_call_cache[2], &_11$$9);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_10$$9))) {
							ZEPHIR_INIT_NVAR(&_12$$10);
							object_init_ex(&_12$$10, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							zephir_constructor_start(&_12$$10);
							ZEPHIR_INIT_NVAR(&_13$$10);
							zephir_get_class(&_13$$10, this_ptr, 0);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_12$$10, "__construct", &_zephir_call_cache[3], &key, &_13$$10);
							zephir_check_call_status();
							zephir_constructor_finish(&_12$$10);
							zephir_throw_exception_debug(&_12$$10, "phalcon/Mvc/Model.zep", 3672);
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
			ZEPHIR_CALL_METHOD_CACHED(NULL, &data, "rewind", &_zephir_call_cache[4]);
			zephir_check_call_status();
			_15$$3 = 1;
			while (1) {
				if (_15$$3) {
					_15$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, &data, "next", &_zephir_call_cache[5]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_14$$3, &data, "valid", &_zephir_call_cache[6]);
				zephir_check_call_status();
				if (!zend_is_true(&_14$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&key, &data, "key", &_zephir_call_cache[7]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&value, &data, "current", &_zephir_call_cache[8]);
				zephir_check_call_status();
					if (Z_TYPE_P(&key) != IS_STRING) {
						continue;
					}
					ZEPHIR_OBS_NVAR(&attribute);
					_16$$11 = zephir_array_isset_fetch(&attribute, columnMap, &key, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_16$$11)) {
						ZEPHIR_INIT_NVAR(&_18$$13);
						ZVAL_STRING(&_18$$13, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC_CACHED(&_17$$13, phalcon_support_settings_ce, "get", &_zephir_call_cache[9], &_18$$13);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_17$$13))) {
							ZEPHIR_INIT_NVAR(&_19$$14);
							object_init_ex(&_19$$14, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							zephir_constructor_start(&_19$$14);
							ZEPHIR_INIT_NVAR(&_20$$14);
							zephir_get_class(&_20$$14, this_ptr, 0);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_19$$14, "__construct", &_zephir_call_cache[10], &key, &_20$$14);
							zephir_check_call_status();
							zephir_constructor_finish(&_19$$14);
							zephir_throw_exception_debug(&_19$$14, "phalcon/Mvc/Model.zep", 3663);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
					if (Z_TYPE_P(&attribute) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&_21$$15);
						_22$$15 = zephir_array_isset_long_fetch(&_21$$15, &attribute, 0, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CPY_WRT(&attribute, &_21$$15);
						if (!(_22$$15)) {
							ZEPHIR_INIT_NVAR(&_24$$16);
							ZVAL_STRING(&_24$$16, "orm.ignore_unknown_columns");
							ZEPHIR_CALL_CE_STATIC_CACHED(&_23$$16, phalcon_support_settings_ce, "get", &_zephir_call_cache[11], &_24$$16);
							zephir_check_call_status();
							if (UNEXPECTED(!zephir_is_true(&_23$$16))) {
								ZEPHIR_INIT_NVAR(&_25$$17);
								object_init_ex(&_25$$17, phalcon_mvc_model_exceptions_columnnotinmap_ce);
								zephir_constructor_start(&_25$$17);
								ZEPHIR_INIT_NVAR(&_26$$17);
								zephir_get_class(&_26$$17, this_ptr, 0);
								ZEPHIR_CALL_METHOD_CACHED(NULL, &_25$$17, "__construct", &_zephir_call_cache[12], &key, &_26$$17);
								zephir_check_call_status();
								zephir_constructor_finish(&_25$$17);
								zephir_throw_exception_debug(&_25$$17, "phalcon/Mvc/Model.zep", 3672);
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
	} else {
		if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
			zephir_throw_variable_type_error(&data, "snapshot", "array");
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&snapshot, &data);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1024, &snapshot);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "setReadConnectionService", &_zephir_call_cache[0], this_ptr, &connectionService_zv);
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
	zend_bool _21$$3, _3$$4, _4$$4, _5$$4, _9$$4, _15$$9, _22$$12, _23$$12, _24$$12, _28$$12, _34$$17;
	zend_string *_2$$3;
	zend_ulong _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *columnMap = NULL, columnMap_sub, __$null, key, value, attribute, *_0$$3, _20$$3, _6$$4, _7$$4, _8$$6, _10$$7, _11$$7, _12$$8, _13$$8, _14$$9, _16$$10, _17$$10, _18$$11, _19$$11, _25$$12, _26$$12, _27$$14, _29$$15, _30$$15, _31$$16, _32$$16, _33$$17, _35$$18, _36$$18, _37$$19, _38$$19;
	zval data, snapshot;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_20$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_25$$12);
	ZVAL_UNDEF(&_26$$12);
	ZVAL_UNDEF(&_27$$14);
	ZVAL_UNDEF(&_29$$15);
	ZVAL_UNDEF(&_30$$15);
	ZVAL_UNDEF(&_31$$16);
	ZVAL_UNDEF(&_32$$16);
	ZVAL_UNDEF(&_33$$17);
	ZVAL_UNDEF(&_35$$18);
	ZVAL_UNDEF(&_36$$18);
	ZVAL_UNDEF(&_37$$19);
	ZVAL_UNDEF(&_38$$19);
	ZEND_TLS zephir_method_cache _zephir_call_cache[17];
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
		zephir_is_iterable(&data, 0, "phalcon/Mvc/Model.zep", 3780);
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
					ZEPHIR_INIT_NVAR(&_7$$4);
					ZVAL_STRING(&_7$$4, "orm.case_insensitive_column_map");
					ZEPHIR_CALL_CE_STATIC_CACHED(&_6$$4, phalcon_support_settings_ce, "get", &_zephir_call_cache[0], &_7$$4);
					zephir_check_call_status();
					_5$$4 = zephir_is_true(&_6$$4);
				}
				if (_5$$4) {
					ZEPHIR_CALL_CE_STATIC_CACHED(&_8$$6, phalcon_mvc_model_hydration_caseinsensitivecolumnmap_ce, "caseInsensitiveColumnMap", &_zephir_call_cache[1], columnMap, &key);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&key, &_8$$6);
				}
				ZEPHIR_OBS_NVAR(&attribute);
				_9$$4 = zephir_array_isset_fetch(&attribute, columnMap, &key, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_9$$4)) {
					ZEPHIR_INIT_NVAR(&_11$$7);
					ZVAL_STRING(&_11$$7, "orm.ignore_unknown_columns");
					ZEPHIR_CALL_CE_STATIC_CACHED(&_10$$7, phalcon_support_settings_ce, "get", &_zephir_call_cache[2], &_11$$7);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&_10$$7))) {
						ZEPHIR_INIT_NVAR(&_12$$8);
						object_init_ex(&_12$$8, phalcon_mvc_model_exceptions_columnnotinmap_ce);
						zephir_constructor_start(&_12$$8);
						ZEPHIR_INIT_NVAR(&_13$$8);
						zephir_get_class(&_13$$8, this_ptr, 0);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_12$$8, "__construct", &_zephir_call_cache[3], &key, &_13$$8);
						zephir_check_call_status();
						zephir_constructor_finish(&_12$$8);
						zephir_throw_exception_debug(&_12$$8, "phalcon/Mvc/Model.zep", 3762);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
				if (Z_TYPE_P(&attribute) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&_14$$9);
					_15$$9 = zephir_array_isset_long_fetch(&_14$$9, &attribute, 0, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CPY_WRT(&attribute, &_14$$9);
					if (!(_15$$9)) {
						ZEPHIR_INIT_NVAR(&_17$$10);
						ZVAL_STRING(&_17$$10, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC_CACHED(&_16$$10, phalcon_support_settings_ce, "get", &_zephir_call_cache[4], &_17$$10);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_16$$10))) {
							ZEPHIR_INIT_NVAR(&_18$$11);
							object_init_ex(&_18$$11, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							zephir_constructor_start(&_18$$11);
							ZEPHIR_INIT_NVAR(&_19$$11);
							zephir_get_class(&_19$$11, this_ptr, 0);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_18$$11, "__construct", &_zephir_call_cache[5], &key, &_19$$11);
							zephir_check_call_status();
							zephir_constructor_finish(&_18$$11);
							zephir_throw_exception_debug(&_18$$11, "phalcon/Mvc/Model.zep", 3771);
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
			ZEPHIR_CALL_METHOD_CACHED(NULL, &data, "rewind", &_zephir_call_cache[6]);
			zephir_check_call_status();
			_21$$3 = 1;
			while (1) {
				if (_21$$3) {
					_21$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, &data, "next", &_zephir_call_cache[7]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_20$$3, &data, "valid", &_zephir_call_cache[8]);
				zephir_check_call_status();
				if (!zend_is_true(&_20$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&key, &data, "key", &_zephir_call_cache[9]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&value, &data, "current", &_zephir_call_cache[10]);
				zephir_check_call_status();
					if (Z_TYPE_P(&key) != IS_STRING) {
						continue;
					}
					_22$$12 = Z_TYPE_P(columnMap) == IS_ARRAY;
					if (_22$$12) {
						_23$$12 = zephir_array_isset_value(columnMap, &key);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_22$$12 = !(_23$$12);
					}
					_24$$12 = _22$$12;
					if (_24$$12) {
						ZEPHIR_INIT_NVAR(&_26$$12);
						ZVAL_STRING(&_26$$12, "orm.case_insensitive_column_map");
						ZEPHIR_CALL_CE_STATIC_CACHED(&_25$$12, phalcon_support_settings_ce, "get", &_zephir_call_cache[11], &_26$$12);
						zephir_check_call_status();
						_24$$12 = zephir_is_true(&_25$$12);
					}
					if (_24$$12) {
						ZEPHIR_CALL_CE_STATIC_CACHED(&_27$$14, phalcon_mvc_model_hydration_caseinsensitivecolumnmap_ce, "caseInsensitiveColumnMap", &_zephir_call_cache[12], columnMap, &key);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&key, &_27$$14);
					}
					ZEPHIR_OBS_NVAR(&attribute);
					_28$$12 = zephir_array_isset_fetch(&attribute, columnMap, &key, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_28$$12)) {
						ZEPHIR_INIT_NVAR(&_30$$15);
						ZVAL_STRING(&_30$$15, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC_CACHED(&_29$$15, phalcon_support_settings_ce, "get", &_zephir_call_cache[13], &_30$$15);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_29$$15))) {
							ZEPHIR_INIT_NVAR(&_31$$16);
							object_init_ex(&_31$$16, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							zephir_constructor_start(&_31$$16);
							ZEPHIR_INIT_NVAR(&_32$$16);
							zephir_get_class(&_32$$16, this_ptr, 0);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_31$$16, "__construct", &_zephir_call_cache[14], &key, &_32$$16);
							zephir_check_call_status();
							zephir_constructor_finish(&_31$$16);
							zephir_throw_exception_debug(&_31$$16, "phalcon/Mvc/Model.zep", 3762);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
					if (Z_TYPE_P(&attribute) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&_33$$17);
						_34$$17 = zephir_array_isset_long_fetch(&_33$$17, &attribute, 0, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CPY_WRT(&attribute, &_33$$17);
						if (!(_34$$17)) {
							ZEPHIR_INIT_NVAR(&_36$$18);
							ZVAL_STRING(&_36$$18, "orm.ignore_unknown_columns");
							ZEPHIR_CALL_CE_STATIC_CACHED(&_35$$18, phalcon_support_settings_ce, "get", &_zephir_call_cache[15], &_36$$18);
							zephir_check_call_status();
							if (UNEXPECTED(!zephir_is_true(&_35$$18))) {
								ZEPHIR_INIT_NVAR(&_37$$19);
								object_init_ex(&_37$$19, phalcon_mvc_model_exceptions_columnnotinmap_ce);
								zephir_constructor_start(&_37$$19);
								ZEPHIR_INIT_NVAR(&_38$$19);
								zephir_get_class(&_38$$19, this_ptr, 0);
								ZEPHIR_CALL_METHOD_CACHED(NULL, &_37$$19, "__construct", &_zephir_call_cache[16], &key, &_38$$19);
								zephir_check_call_status();
								zephir_constructor_finish(&_37$$19);
								zephir_throw_exception_debug(&_37$$19, "phalcon/Mvc/Model.zep", 3771);
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
	} else {
		if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
			zephir_throw_variable_type_error(&data, "snapshot", "array");
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&snapshot, &data);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1018, &snapshot);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	zend_bool enabled = 1, _0, _9$$4;
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
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
		zephir_is_iterable(_3$$4, 0, "phalcon/Mvc/Model.zep", 3829);
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
			ZEPHIR_CALL_METHOD_CACHED(NULL, _3$$4, "rewind", &_zephir_call_cache[0]);
			zephir_check_call_status();
			_9$$4 = 1;
			while (1) {
				if (_9$$4) {
					_9$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _3$$4, "next", &_zephir_call_cache[1]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_8$$4, _3$$4, "valid", &_zephir_call_cache[2]);
				zephir_check_call_status();
				if (!zend_is_true(&_8$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&alias, _3$$4, "current", &_zephir_call_cache[3]);
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
	if (UNEXPECTED(EG(exception))) {
		return;
	}
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "setWriteConnectionService", &_zephir_call_cache[0], this_ptr, &connectionService_zv);
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
		if (UNEXPECTED(EG(exception))) {
			return;
		}
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1022, &__$false);
		if (UNEXPECTED(EG(exception))) {
			return;
		}
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
	zend_bool _25, _4$$4, _5$$4, _9$$4, _14$$9, _16$$3, _18$$3, _19$$3, _26$$18, _27$$18, _31$$18, _36$$23, _38$$17, _40$$17, _41$$17;
	zval data;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *columns = NULL, columns_sub, *useGetter = NULL, useGetter_sub, __$null, __$true, attribute, attributeField, columnMap, metaData, method, _0, *_1, _2, *_3, _24, _6$$4, _7$$4, _8$$5, _10$$6, _11$$6, _12$$7, _13$$7, _15$$3, _17$$3, _20$$12, _21$$11, _22$$11, _23$$15, _28$$18, _29$$18, _30$$19, _32$$20, _33$$20, _34$$21, _35$$21, _37$$17, _39$$17, _42$$26, _43$$25, _44$$25, _45$$29;
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
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_28$$18);
	ZVAL_UNDEF(&_29$$18);
	ZVAL_UNDEF(&_30$$19);
	ZVAL_UNDEF(&_32$$20);
	ZVAL_UNDEF(&_33$$20);
	ZVAL_UNDEF(&_34$$21);
	ZVAL_UNDEF(&_35$$21);
	ZVAL_UNDEF(&_37$$17);
	ZVAL_UNDEF(&_39$$17);
	ZVAL_UNDEF(&_42$$26);
	ZVAL_UNDEF(&_43$$25);
	ZVAL_UNDEF(&_44$$25);
	ZVAL_UNDEF(&_45$$29);
	ZVAL_UNDEF(&data);
	ZEND_TLS zephir_method_cache _zephir_call_cache[15];
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
	ZEPHIR_CALL_METHOD_CACHED(&metaData, this_ptr, "getModelsMetaData", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&columnMap, &metaData, "getColumnMap", &_zephir_call_cache[1], this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_0, &metaData, "getAttributes", &_zephir_call_cache[2], this_ptr);
	zephir_check_call_status();
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &_0);
		_1 = &_2;
	} else {
		_1 = &_0;
	}
	zephir_is_iterable(_1, 0, "phalcon/Mvc/Model.zep", 3981);
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
					ZEPHIR_INIT_NVAR(&_7$$4);
					ZVAL_STRING(&_7$$4, "orm.case_insensitive_column_map");
					ZEPHIR_CALL_CE_STATIC_CACHED(&_6$$4, phalcon_support_settings_ce, "get", &_zephir_call_cache[3], &_7$$4);
					zephir_check_call_status();
					_5$$4 = zephir_is_true(&_6$$4);
				}
				if (_5$$4) {
					ZEPHIR_CALL_CE_STATIC_CACHED(&_8$$5, phalcon_mvc_model_hydration_caseinsensitivecolumnmap_ce, "caseInsensitiveColumnMap", &_zephir_call_cache[4], &columnMap, &attribute);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&attribute, &_8$$5);
				}
				ZEPHIR_OBS_NVAR(&attributeField);
				_9$$4 = zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_9$$4)) {
					ZEPHIR_INIT_NVAR(&_11$$6);
					ZVAL_STRING(&_11$$6, "orm.ignore_unknown_columns");
					ZEPHIR_CALL_CE_STATIC_CACHED(&_10$$6, phalcon_support_settings_ce, "get", &_zephir_call_cache[5], &_11$$6);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&_10$$6))) {
						ZEPHIR_INIT_NVAR(&_12$$7);
						object_init_ex(&_12$$7, phalcon_mvc_model_exceptions_columnnotinmap_ce);
						zephir_constructor_start(&_12$$7);
						ZEPHIR_INIT_NVAR(&_13$$7);
						zephir_get_class(&_13$$7, this_ptr, 0);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_12$$7, "__construct", &_zephir_call_cache[6], &attribute, &_13$$7);
						zephir_check_call_status();
						zephir_constructor_finish(&_12$$7);
						zephir_throw_exception_debug(&_12$$7, "phalcon/Mvc/Model.zep", 3939);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &attribute);
			}
			if (Z_TYPE_P(columns) == IS_ARRAY) {
				_14$$9 = zephir_fast_in_array(&attributeField, columns);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_14$$9)) {
					continue;
				}
			}
			ZEPHIR_INIT_NVAR(&_15$$3);
			zephir_camelize(&_15$$3, &attributeField, NULL );
			ZEPHIR_INIT_NVAR(&method);
			ZEPHIR_CONCAT_SV(&method, "get", &_15$$3);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
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

					ZEPHIR_CALL_METHOD_ZVAL(&_20$$12, this_ptr, &method, NULL, 0);
					zephir_check_call_status_or_jump(try_end_1);
					zephir_array_update_zval(&data, &attributeField, &_20$$12, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						goto try_end_1;
					}

				try_end_1:

				if (EG(exception)) {
					ZEPHIR_INIT_NVAR(&_21$$11);
					ZVAL_OBJ(&_21$$11, EG(exception));
					Z_ADDREF_P(&_21$$11);
					ZEPHIR_INIT_NVAR(&_22$$11);
					if (zephir_is_instance_of(&_21$$11, SL("Error"))) {
						zend_clear_exception();
						ZEPHIR_CPY_WRT(&_22$$11, &_21$$11);
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
				_19$$3 = zephir_isset_property_value_zval(this_ptr, &attributeField);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_19$$3) {
					ZEPHIR_OBS_NVAR(&_23$$15);
					zephir_read_property_zval(&_23$$15, this_ptr, &attributeField, PH_NOISY_CC);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&data, &attributeField, &_23$$15, PH_COPY | PH_SEPARATE);
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "rewind", &_zephir_call_cache[7]);
		zephir_check_call_status();
		_25 = 1;
		while (1) {
			if (_25) {
				_25 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "next", &_zephir_call_cache[8]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_24, _1, "valid", &_zephir_call_cache[9]);
			zephir_check_call_status();
			if (!zend_is_true(&_24)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&attribute, _1, "current", &_zephir_call_cache[10]);
			zephir_check_call_status();
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					_26$$18 = zephir_array_isset_value(&columnMap, &attribute);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_27$$18 = !(_26$$18);
					if (_27$$18) {
						ZEPHIR_INIT_NVAR(&_29$$18);
						ZVAL_STRING(&_29$$18, "orm.case_insensitive_column_map");
						ZEPHIR_CALL_CE_STATIC_CACHED(&_28$$18, phalcon_support_settings_ce, "get", &_zephir_call_cache[11], &_29$$18);
						zephir_check_call_status();
						_27$$18 = zephir_is_true(&_28$$18);
					}
					if (_27$$18) {
						ZEPHIR_CALL_CE_STATIC_CACHED(&_30$$19, phalcon_mvc_model_hydration_caseinsensitivecolumnmap_ce, "caseInsensitiveColumnMap", &_zephir_call_cache[12], &columnMap, &attribute);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&attribute, &_30$$19);
					}
					ZEPHIR_OBS_NVAR(&attributeField);
					_31$$18 = zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_31$$18)) {
						ZEPHIR_INIT_NVAR(&_33$$20);
						ZVAL_STRING(&_33$$20, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC_CACHED(&_32$$20, phalcon_support_settings_ce, "get", &_zephir_call_cache[13], &_33$$20);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_32$$20))) {
							ZEPHIR_INIT_NVAR(&_34$$21);
							object_init_ex(&_34$$21, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							zephir_constructor_start(&_34$$21);
							ZEPHIR_INIT_NVAR(&_35$$21);
							zephir_get_class(&_35$$21, this_ptr, 0);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_34$$21, "__construct", &_zephir_call_cache[14], &attribute, &_35$$21);
							zephir_check_call_status();
							zephir_constructor_finish(&_34$$21);
							zephir_throw_exception_debug(&_34$$21, "phalcon/Mvc/Model.zep", 3939);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &attribute);
				}
				if (Z_TYPE_P(columns) == IS_ARRAY) {
					_36$$23 = zephir_fast_in_array(&attributeField, columns);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_36$$23)) {
						continue;
					}
				}
				ZEPHIR_INIT_NVAR(&_37$$17);
				zephir_camelize(&_37$$17, &attributeField, NULL );
				ZEPHIR_INIT_NVAR(&method);
				ZEPHIR_CONCAT_SV(&method, "get", &_37$$17);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_38$$17 = ZEPHIR_IS_TRUE_IDENTICAL(useGetter);
				if (_38$$17) {
					ZEPHIR_INIT_NVAR(&_39$$17);
					ZVAL_STRING(&_39$$17, "getSource");
					_38$$17 = !ZEPHIR_IS_IDENTICAL(&_39$$17, &method);
				}
				_40$$17 = _38$$17;
				if (_40$$17) {
					_40$$17 = (zephir_method_exists(this_ptr, &method)  == SUCCESS);
				}
				if (_40$$17) {

					/* try_start_2: */

						ZEPHIR_CALL_METHOD_ZVAL(&_42$$26, this_ptr, &method, NULL, 0);
						zephir_check_call_status_or_jump(try_end_2);
						zephir_array_update_zval(&data, &attributeField, &_42$$26, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							goto try_end_2;
						}

					try_end_2:

					if (EG(exception)) {
						ZEPHIR_INIT_NVAR(&_43$$25);
						ZVAL_OBJ(&_43$$25, EG(exception));
						Z_ADDREF_P(&_43$$25);
						ZEPHIR_INIT_NVAR(&_44$$25);
						if (zephir_is_instance_of(&_43$$25, SL("Error"))) {
							zend_clear_exception();
							ZEPHIR_CPY_WRT(&_44$$25, &_43$$25);
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
					_41$$17 = zephir_isset_property_value_zval(this_ptr, &attributeField);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_41$$17) {
						ZEPHIR_OBS_NVAR(&_45$$29);
						zephir_read_property_zval(&_45$$29, this_ptr, &attributeField, PH_NOISY_CC);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_zval(&data, &attributeField, &_45$$29, PH_COPY | PH_SEPARATE);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[12];
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
	ZEPHIR_CALL_FUNCTION(&attributes, "unserialize", NULL, 17, &data_zv);
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
		ZEPHIR_CALL_CE_STATIC_CACHED(&container, phalcon_di_di_ce, "getDefault", &_zephir_call_cache[0]);
		zephir_check_call_status();
		if (Z_TYPE_P(&container) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_2$$5);
			object_init_ex(&_2$$5, phalcon_mvc_model_exceptions_modelormservicesunavailable_ce);
			zephir_constructor_start(&_2$$5);
			ZEPHIR_INIT_VAR(&_3$$5);
			zephir_get_class(&_3$$5, this_ptr, 0);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$5, "__construct", &_zephir_call_cache[1], &_3$$5);
			zephir_check_call_status();
			zephir_constructor_finish(&_2$$5);
			zephir_throw_exception_debug(&_2$$5, "phalcon/Mvc/Model.zep", 4005);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1013, &container);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "modelsManager");
		ZEPHIR_CALL_METHOD_CACHED(&_4$$3, &container, "getShared", &_zephir_call_cache[2], &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&manager, &_4$$3);
		if (UNEXPECTED(Z_TYPE_P(&manager) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_6$$6);
			object_init_ex(&_6$$6, phalcon_mvc_model_exceptions_invalidmodelsmanagerservice_ce);
			zephir_constructor_start(&_6$$6);
			ZEPHIR_INIT_VAR(&_7$$6);
			zephir_get_class(&_7$$6, this_ptr, 0);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_6$$6, "__construct", &_zephir_call_cache[3], &_7$$6);
			zephir_check_call_status();
			zephir_constructor_finish(&_6$$6);
			zephir_throw_exception_debug(&_6$$6, "phalcon/Mvc/Model.zep", 4019);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1014, &manager);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &manager, "initialize", &_zephir_call_cache[4], this_ptr);
		zephir_check_call_status();
		if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("onconstruct")) == SUCCESS)) {
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "onConstruct", &_zephir_call_cache[5]);
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
			zephir_is_iterable(_9$$8, 0, "phalcon/Mvc/Model.zep", 4058);
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
						if (UNEXPECTED(EG(exception))) {
							goto try_end_1;
						}

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
				ZEPHIR_CALL_METHOD_CACHED(NULL, _9$$8, "rewind", &_zephir_call_cache[6]);
				zephir_check_call_status();
				_17$$8 = 1;
				while (1) {
					if (_17$$8) {
						_17$$8 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _9$$8, "next", &_zephir_call_cache[7]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_16$$8, _9$$8, "valid", &_zephir_call_cache[8]);
					zephir_check_call_status();
					if (!zend_is_true(&_16$$8)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&key, _9$$8, "key", &_zephir_call_cache[9]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&value, _9$$8, "current", &_zephir_call_cache[10]);
					zephir_check_call_status();

						/* try_start_2: */

							zephir_update_property_zval_zval(this_ptr, &key, &value);
							if (UNEXPECTED(EG(exception))) {
								goto try_end_2;
							}

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
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&_4$$3, &manager, "isKeepingSnapshots", &_zephir_call_cache[11], this_ptr);
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
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1018, &properties);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[5];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD_CACHED(&metaData, this_ptr, "getModelsMetaData", &_zephir_call_cache[0]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_2$$3, this_ptr, "getWriteConnection", &_zephir_call_cache[1]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_1$$3, this_ptr, "has", &_zephir_call_cache[2], &metaData, &_2$$3);
		zephir_check_call_status();
		if (!(zephir_is_true(&_1$$3))) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_create_array(&_3$$4, 1, 0);
			ZEPHIR_INIT_VAR(&_4$$4);
			object_init_ex(&_4$$4, phalcon_messages_message_ce);
			zephir_constructor_start(&_4$$4);
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
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_4$$4, "__construct", &_zephir_call_cache[3], &_6$$4, &_7$$4, &_8$$4, &_9$$4, &_5$$4);
			zephir_check_call_status();
			zephir_constructor_finish(&_4$$4);
			zephir_array_fast_append(&_3$$4, &_4$$4);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1020, &_3$$4);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "save", &_zephir_call_cache[4]);
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
	zend_bool _0;
	zval *this_ptr = getThis();

	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("errorMessages", 13, 1);
	}
	_0 = zephir_isempty_property_fast(this_ptr, _zephir_prop_0);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_BOOL(!(_0));
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
	if (UNEXPECTED(EG(exception))) {
		return;
	}
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[6];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &attributes_param);
	zephir_get_arrval(&attributes, attributes_param);
	ZEPHIR_INIT_VAR(&keysAttributes);
	array_init(&keysAttributes);
	zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model.zep", 4218);
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &attributes, "rewind", &_zephir_call_cache[0]);
		zephir_check_call_status();
		_2 = 1;
		while (1) {
			if (_2) {
				_2 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &attributes, "next", &_zephir_call_cache[1]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_1, &attributes, "valid", &_zephir_call_cache[2]);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&attribute, &attributes, "current", &_zephir_call_cache[3]);
			zephir_check_call_status();
				zephir_array_update_zval(&keysAttributes, &attribute, &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&_3, this_ptr, "getModelsMetaData", &_zephir_call_cache[4]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_3, "setEmptyStringAttributes", &_zephir_call_cache[5], this_ptr, &keysAttributes);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_0, "addBelongsTo", &_zephir_call_cache[0], this_ptr, fields, &referenceModel_zv, referencedFields, &options);
	zephir_check_call_status();
	RETURN_MM();
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("operationMade", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1021, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_LONG(&_0, 3)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "notDeleted");
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "fireEvent", &_zephir_call_cache[0], &_1$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "notSaved");
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "fireEvent", &_zephir_call_cache[1], &_2$$4);
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
	zend_string *_11$$7, *_44$$28;
	zend_ulong _10$$7, _43$$28;
	zend_bool error = 0, validateWithNulls = 0, _36, _4$$3, _22$$3, _24$$3, _16$$7, _12$$8, _17$$10, _20$$12, _23$$15, _28$$18, _37$$24, _55$$24, _57$$24, _49$$28, _45$$29, _50$$31, _53$$33, _56$$36, _61$$39;
	zval conditions, _26$$3, _31$$18, _59$$24, _64$$39;
	zval manager, belongsTo, foreignKey, relation, position, bindParams, extraConditions, message, messageField, fields, referencedFields, field, referencedModel, value, allowNulls, _0, *_1, _2, *_3, _35, _6$$3, _25$$3, _27$$3, _5$$5, *_7$$7, _8$$7, *_9$$7, _15$$7, _13$$8, _14$$8, _18$$10, _19$$10, _21$$12, _30$$18, _32$$18, _33$$18, _34$$18, _29$$20, _39$$24, _58$$24, _60$$24, _38$$26, *_40$$28, _41$$28, *_42$$28, _48$$28, _46$$29, _47$$29, _51$$31, _52$$31, _54$$33, _63$$39, _65$$39, _66$$39, _67$$39, _62$$41, _68$$45, _69$$45, _70$$46;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	ZVAL_UNDEF(&_25$$3);
	ZVAL_UNDEF(&_27$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_30$$18);
	ZVAL_UNDEF(&_32$$18);
	ZVAL_UNDEF(&_33$$18);
	ZVAL_UNDEF(&_34$$18);
	ZVAL_UNDEF(&_29$$20);
	ZVAL_UNDEF(&_39$$24);
	ZVAL_UNDEF(&_58$$24);
	ZVAL_UNDEF(&_60$$24);
	ZVAL_UNDEF(&_38$$26);
	ZVAL_UNDEF(&_41$$28);
	ZVAL_UNDEF(&_48$$28);
	ZVAL_UNDEF(&_46$$29);
	ZVAL_UNDEF(&_47$$29);
	ZVAL_UNDEF(&_51$$31);
	ZVAL_UNDEF(&_52$$31);
	ZVAL_UNDEF(&_54$$33);
	ZVAL_UNDEF(&_63$$39);
	ZVAL_UNDEF(&_65$$39);
	ZVAL_UNDEF(&_66$$39);
	ZVAL_UNDEF(&_67$$39);
	ZVAL_UNDEF(&_62$$41);
	ZVAL_UNDEF(&_68$$45);
	ZVAL_UNDEF(&_69$$45);
	ZVAL_UNDEF(&_70$$46);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&_26$$3);
	ZVAL_UNDEF(&_31$$18);
	ZVAL_UNDEF(&_59$$24);
	ZVAL_UNDEF(&_64$$39);
	ZEND_TLS zephir_method_cache _zephir_call_cache[36];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD_CACHED(&belongsTo, &manager, "getBelongsTo", &_zephir_call_cache[0], this_ptr);
	zephir_check_call_status();
	error = 0;
	if (Z_TYPE_P(&belongsTo) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &belongsTo);
		_1 = &_2;
	} else {
		_1 = &belongsTo;
	}
	zephir_is_iterable(_1, 0, "phalcon/Mvc/Model.zep", 4460);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&relation);
			ZVAL_COPY(&relation, _3);
			validateWithNulls = 0;
			ZEPHIR_CALL_METHOD_CACHED(&foreignKey, &relation, "getForeignKey", &_zephir_call_cache[1]);
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
				zephir_array_fetch_string(&_5$$5, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 4337);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				action = zephir_get_intval(&_5$$5);
			}
			if (action != 1) {
				continue;
			}
			ZEPHIR_CALL_METHOD_CACHED(&_6$$3, &relation, "getReferencedModel", &_zephir_call_cache[2]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&referencedModel, &manager, "load", &_zephir_call_cache[3], &_6$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&conditions);
			array_init(&conditions);
			ZEPHIR_INIT_NVAR(&bindParams);
			array_init(&bindParams);
			numberNull = 0;
			ZEPHIR_CALL_METHOD_CACHED(&fields, &relation, "getFields", &_zephir_call_cache[4]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&referencedFields, &relation, "getReferencedFields", &_zephir_call_cache[5]);
			zephir_check_call_status();
			if (Z_TYPE_P(&fields) == IS_ARRAY) {
				if (Z_TYPE_P(&fields) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_8$$7);
					zephir_string_to_char_array(&_8$$7, &fields);
					_7$$7 = &_8$$7;
				} else {
					_7$$7 = &fields;
				}
				zephir_is_iterable(_7$$7, 0, "phalcon/Mvc/Model.zep", 4380);
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
						_12$$8 = zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_OBS_NVAR(&_13$$8);
						zephir_array_fetch(&_13$$8, &referencedFields, &position, PH_NOISY, "phalcon/Mvc/Model.zep", 4372);
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
						zephir_array_append(&conditions, &_14$$8, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4372);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4373);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (Z_TYPE_P(&value) == IS_NULL) {
							numberNull++;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _7$$7, "rewind", &_zephir_call_cache[6]);
					zephir_check_call_status();
					_16$$7 = 1;
					while (1) {
						if (_16$$7) {
							_16$$7 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _7$$7, "next", &_zephir_call_cache[7]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_15$$7, _7$$7, "valid", &_zephir_call_cache[8]);
						zephir_check_call_status();
						if (!zend_is_true(&_15$$7)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&position, _7$$7, "key", &_zephir_call_cache[9]);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&field, _7$$7, "current", &_zephir_call_cache[10]);
						zephir_check_call_status();
							ZEPHIR_OBS_NVAR(&value);
							_17$$10 = zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&_18$$10);
							zephir_array_fetch(&_18$$10, &referencedFields, &position, PH_NOISY, "phalcon/Mvc/Model.zep", 4372);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&_19$$10);
							ZEPHIR_CONCAT_SVSV(&_19$$10, "[", &_18$$10, "] = ?", &position);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&conditions, &_19$$10, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4372);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4373);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (Z_TYPE_P(&value) == IS_NULL) {
								numberNull++;
							}
					}
				}
				validateWithNulls = numberNull == zephir_fast_count_int(&fields);
			} else {
				ZEPHIR_OBS_NVAR(&value);
				_20$$12 = zephir_fetch_property_zval(&value, this_ptr, &fields, PH_SILENT_CC);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_21$$12);
				ZEPHIR_CONCAT_SVS(&_21$$12, "[", &referencedFields, "] = ?0");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&conditions, &_21$$12, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4384);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4385);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&value) == IS_NULL) {
					validateWithNulls = 1;
				}
			}
			ZEPHIR_OBS_NVAR(&extraConditions);
			_22$$3 = zephir_array_isset_string_fetch(&extraConditions, &foreignKey, SL("conditions"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_22$$3) {
				zephir_array_append(&conditions, &extraConditions, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4396);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			if (validateWithNulls) {
				ZEPHIR_OBS_NVAR(&allowNulls);
				_23$$15 = zephir_array_isset_string_fetch(&allowNulls, &foreignKey, SL("allowNulls"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_23$$15) {
					validateWithNulls = zephir_get_boolval(&allowNulls);
				} else {
					validateWithNulls = 0;
				}
			}
			_24$$3 = !validateWithNulls;
			if (_24$$3) {
				ZEPHIR_INIT_NVAR(&_26$$3);
				zephir_create_array(&_26$$3, 2, 0);
				ZEPHIR_INIT_NVAR(&_27$$3);
				zephir_fast_join_str(&_27$$3, SL(" AND "), &conditions);
				zephir_array_fast_append(&_26$$3, &_27$$3);
				zephir_array_update_string(&_26$$3, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD_CACHED(&_25$$3, &referencedModel, "count", &_zephir_call_cache[11], &_26$$3);
				zephir_check_call_status();
				_24$$3 = !zephir_is_true(&_25$$3);
			}
			if (_24$$3) {
				ZEPHIR_OBS_NVAR(&message);
				_28$$18 = zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_28$$18)) {
					ZEPHIR_INIT_NVAR(&message);
					if (Z_TYPE_P(&fields) == IS_ARRAY) {
						ZEPHIR_INIT_NVAR(&_29$$20);
						zephir_fast_join_str(&_29$$20, SL(", "), &fields);
						ZEPHIR_CONCAT_SVS(&message, "Value of fields \"", &_29$$20, "\" does not exist on referenced table");
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
				ZEPHIR_INIT_NVAR(&_30$$18);
				object_init_ex(&_30$$18, phalcon_messages_message_ce);
				zephir_constructor_start(&_30$$18);
				ZEPHIR_INIT_NVAR(&_31$$18);
				zephir_create_array(&_31$$18, 2, 0);
				ZEPHIR_INIT_NVAR(&_32$$18);
				zephir_get_class(&_32$$18, this_ptr, 0);
				zephir_array_update_string(&_31$$18, SL("model"), &_32$$18, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD_CACHED(&_33$$18, &relation, "getReferencedModel", &_zephir_call_cache[12]);
				zephir_check_call_status();
				zephir_array_update_string(&_31$$18, SL("referenceModel"), &_33$$18, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_32$$18);
				ZVAL_STRING(&_32$$18, "ConstraintViolation");
				ZVAL_LONG(&_34$$18, 0);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_30$$18, "__construct", &_zephir_call_cache[13], &message, &messageField, &_32$$18, &_34$$18, &_31$$18);
				zephir_check_call_status();
				zephir_constructor_finish(&_30$$18);
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessage", &_zephir_call_cache[14], &_30$$18);
				zephir_check_call_status();
				error = 1;
				break;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "rewind", &_zephir_call_cache[15]);
		zephir_check_call_status();
		_36 = 1;
		while (1) {
			if (_36) {
				_36 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "next", &_zephir_call_cache[16]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_35, _1, "valid", &_zephir_call_cache[17]);
			zephir_check_call_status();
			if (!zend_is_true(&_35)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&relation, _1, "current", &_zephir_call_cache[18]);
			zephir_check_call_status();
				validateWithNulls = 0;
				ZEPHIR_CALL_METHOD_CACHED(&foreignKey, &relation, "getForeignKey", &_zephir_call_cache[19]);
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
					zephir_array_fetch_string(&_38$$26, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 4337);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					action = zephir_get_intval(&_38$$26);
				}
				if (action != 1) {
					continue;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_39$$24, &relation, "getReferencedModel", &_zephir_call_cache[20]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&referencedModel, &manager, "load", &_zephir_call_cache[21], &_39$$24);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&conditions);
				array_init(&conditions);
				ZEPHIR_INIT_NVAR(&bindParams);
				array_init(&bindParams);
				numberNull = 0;
				ZEPHIR_CALL_METHOD_CACHED(&fields, &relation, "getFields", &_zephir_call_cache[22]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&referencedFields, &relation, "getReferencedFields", &_zephir_call_cache[23]);
				zephir_check_call_status();
				if (Z_TYPE_P(&fields) == IS_ARRAY) {
					if (Z_TYPE_P(&fields) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_41$$28);
						zephir_string_to_char_array(&_41$$28, &fields);
						_40$$28 = &_41$$28;
					} else {
						_40$$28 = &fields;
					}
					zephir_is_iterable(_40$$28, 0, "phalcon/Mvc/Model.zep", 4380);
					if (Z_TYPE_P(_40$$28) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_40$$28), _43$$28, _44$$28, _42$$28)
						{
							ZEPHIR_INIT_NVAR(&position);
							if (_44$$28 != NULL) { 
								ZVAL_STR_COPY(&position, _44$$28);
							} else {
								ZVAL_LONG(&position, _43$$28);
							}
							ZEPHIR_INIT_NVAR(&field);
							ZVAL_COPY(&field, _42$$28);
							ZEPHIR_OBS_NVAR(&value);
							_45$$29 = zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&_46$$29);
							zephir_array_fetch(&_46$$29, &referencedFields, &position, PH_NOISY, "phalcon/Mvc/Model.zep", 4372);
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
							zephir_array_append(&conditions, &_47$$29, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4372);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4373);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (Z_TYPE_P(&value) == IS_NULL) {
								numberNull++;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _40$$28, "rewind", &_zephir_call_cache[24]);
						zephir_check_call_status();
						_49$$28 = 1;
						while (1) {
							if (_49$$28) {
								_49$$28 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _40$$28, "next", &_zephir_call_cache[25]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_48$$28, _40$$28, "valid", &_zephir_call_cache[26]);
							zephir_check_call_status();
							if (!zend_is_true(&_48$$28)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&position, _40$$28, "key", &_zephir_call_cache[27]);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(&field, _40$$28, "current", &_zephir_call_cache[28]);
							zephir_check_call_status();
								ZEPHIR_OBS_NVAR(&value);
								_50$$31 = zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&_51$$31);
								zephir_array_fetch(&_51$$31, &referencedFields, &position, PH_NOISY, "phalcon/Mvc/Model.zep", 4372);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_INIT_NVAR(&_52$$31);
								ZEPHIR_CONCAT_SVSV(&_52$$31, "[", &_51$$31, "] = ?", &position);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&conditions, &_52$$31, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4372);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4373);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (Z_TYPE_P(&value) == IS_NULL) {
									numberNull++;
								}
						}
					}
					validateWithNulls = numberNull == zephir_fast_count_int(&fields);
				} else {
					ZEPHIR_OBS_NVAR(&value);
					_53$$33 = zephir_fetch_property_zval(&value, this_ptr, &fields, PH_SILENT_CC);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_54$$33);
					ZEPHIR_CONCAT_SVS(&_54$$33, "[", &referencedFields, "] = ?0");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&conditions, &_54$$33, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4384);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4385);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (Z_TYPE_P(&value) == IS_NULL) {
						validateWithNulls = 1;
					}
				}
				ZEPHIR_OBS_NVAR(&extraConditions);
				_55$$24 = zephir_array_isset_string_fetch(&extraConditions, &foreignKey, SL("conditions"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_55$$24) {
					zephir_array_append(&conditions, &extraConditions, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4396);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				if (validateWithNulls) {
					ZEPHIR_OBS_NVAR(&allowNulls);
					_56$$36 = zephir_array_isset_string_fetch(&allowNulls, &foreignKey, SL("allowNulls"), 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_56$$36) {
						validateWithNulls = zephir_get_boolval(&allowNulls);
					} else {
						validateWithNulls = 0;
					}
				}
				_57$$24 = !validateWithNulls;
				if (_57$$24) {
					ZEPHIR_INIT_NVAR(&_59$$24);
					zephir_create_array(&_59$$24, 2, 0);
					ZEPHIR_INIT_NVAR(&_60$$24);
					zephir_fast_join_str(&_60$$24, SL(" AND "), &conditions);
					zephir_array_fast_append(&_59$$24, &_60$$24);
					zephir_array_update_string(&_59$$24, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD_CACHED(&_58$$24, &referencedModel, "count", &_zephir_call_cache[29], &_59$$24);
					zephir_check_call_status();
					_57$$24 = !zephir_is_true(&_58$$24);
				}
				if (_57$$24) {
					ZEPHIR_OBS_NVAR(&message);
					_61$$39 = zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_61$$39)) {
						ZEPHIR_INIT_NVAR(&message);
						if (Z_TYPE_P(&fields) == IS_ARRAY) {
							ZEPHIR_INIT_NVAR(&_62$$41);
							zephir_fast_join_str(&_62$$41, SL(", "), &fields);
							ZEPHIR_CONCAT_SVS(&message, "Value of fields \"", &_62$$41, "\" does not exist on referenced table");
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
					ZEPHIR_INIT_NVAR(&_63$$39);
					object_init_ex(&_63$$39, phalcon_messages_message_ce);
					zephir_constructor_start(&_63$$39);
					ZEPHIR_INIT_NVAR(&_64$$39);
					zephir_create_array(&_64$$39, 2, 0);
					ZEPHIR_INIT_NVAR(&_65$$39);
					zephir_get_class(&_65$$39, this_ptr, 0);
					zephir_array_update_string(&_64$$39, SL("model"), &_65$$39, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD_CACHED(&_66$$39, &relation, "getReferencedModel", &_zephir_call_cache[30]);
					zephir_check_call_status();
					zephir_array_update_string(&_64$$39, SL("referenceModel"), &_66$$39, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_65$$39);
					ZVAL_STRING(&_65$$39, "ConstraintViolation");
					ZVAL_LONG(&_67$$39, 0);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_63$$39, "__construct", &_zephir_call_cache[31], &message, &messageField, &_65$$39, &_67$$39, &_64$$39);
					zephir_check_call_status();
					zephir_constructor_finish(&_63$$39);
					ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessage", &_zephir_call_cache[32], &_63$$39);
					zephir_check_call_status();
					error = 1;
					break;
				}
		}
	}
	if (error) {
		ZEPHIR_INIT_VAR(&_69$$45);
		ZVAL_STRING(&_69$$45, "orm.events");
		ZEPHIR_CALL_CE_STATIC_CACHED(&_68$$45, phalcon_support_settings_ce, "get", &_zephir_call_cache[33], &_69$$45);
		zephir_check_call_status();
		if (zephir_is_true(&_68$$45)) {
			ZEPHIR_INIT_VAR(&_70$$46);
			ZVAL_STRING(&_70$$46, "onValidationFails");
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "fireEvent", &_zephir_call_cache[34], &_70$$46);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "cancelOperation", &_zephir_call_cache[35]);
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
	zend_bool _10, _4$$3, _5$$3, _7$$3, _11$$8, _12$$8, _14$$8;
	zval manager, relations, relation, foreignKey, related, _0, *_1, _2, *_3, _9, _8$$3, _6$$5, _15$$8, _13$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_13$$10);
	ZEND_TLS zephir_method_cache _zephir_call_cache[11];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD_CACHED(&relations, &manager, "getHasOneAndHasMany", &_zephir_call_cache[0], this_ptr);
	zephir_check_call_status();
	if (Z_TYPE_P(&relations) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &relations);
		_1 = &_2;
	} else {
		_1 = &relations;
	}
	zephir_is_iterable(_1, 0, "phalcon/Mvc/Model.zep", 4534);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&relation);
			ZVAL_COPY(&relation, _3);
			ZEPHIR_CALL_METHOD_CACHED(&foreignKey, &relation, "getForeignKey", &_zephir_call_cache[1]);
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
				zephir_array_fetch_string(&_6$$5, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 4510);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				action = zephir_get_intval(&_6$$5);
			}
			if (action != 2) {
				continue;
			}
			ZEPHIR_CALL_METHOD_CACHED(&related, &manager, "getRelationRecords", &_zephir_call_cache[2], &relation, this_ptr);
			zephir_check_call_status();
			_7$$3 = zephir_is_true(&related);
			if (_7$$3) {
				ZEPHIR_CALL_METHOD_CACHED(&_8$$3, &related, "delete", &_zephir_call_cache[3]);
				zephir_check_call_status();
				_7$$3 = ZEPHIR_IS_FALSE_IDENTICAL(&_8$$3);
			}
			if (_7$$3) {
				RETURN_MM_BOOL(0);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "rewind", &_zephir_call_cache[4]);
		zephir_check_call_status();
		_10 = 1;
		while (1) {
			if (_10) {
				_10 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "next", &_zephir_call_cache[5]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_9, _1, "valid", &_zephir_call_cache[6]);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&relation, _1, "current", &_zephir_call_cache[7]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&foreignKey, &relation, "getForeignKey", &_zephir_call_cache[8]);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
					continue;
				}
				action = 0;
				_11$$8 = Z_TYPE_P(&foreignKey) == IS_ARRAY;
				if (_11$$8) {
					_12$$8 = zephir_array_isset_value_string(&foreignKey, SL("action"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_11$$8 = _12$$8;
				}
				if (_11$$8) {
					ZEPHIR_OBS_NVAR(&_13$$10);
					zephir_array_fetch_string(&_13$$10, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 4510);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					action = zephir_get_intval(&_13$$10);
				}
				if (action != 2) {
					continue;
				}
				ZEPHIR_CALL_METHOD_CACHED(&related, &manager, "getRelationRecords", &_zephir_call_cache[9], &relation, this_ptr);
				zephir_check_call_status();
				_14$$8 = zephir_is_true(&related);
				if (_14$$8) {
					ZEPHIR_CALL_METHOD_CACHED(&_15$$8, &related, "delete", &_zephir_call_cache[10]);
					zephir_check_call_status();
					_14$$8 = ZEPHIR_IS_FALSE_IDENTICAL(&_15$$8);
				}
				if (_14$$8) {
					RETURN_MM_BOOL(0);
				}
		}
	}
	RETURN_MM_BOOL(1);
}

/**
 * Reads both "hasMany" and "hasOne" relations and checks the virtual
 * foreign keys (restrict) when deleting records
 */
PHP_METHOD(Phalcon_Mvc_Model, checkForeignKeysReverseRestrict)
{
	zval _12$$7, _25$$15;
	zval manager, relations, foreignKey, relation, relationClass, fields, message, messageField, _0, *_1, _2, *_3, _15, _7$$3, _8$$3, _9$$3, _6$$5, _11$$7, _13$$7, _14$$7, _20$$11, _21$$11, _22$$11, _19$$13, _24$$15, _26$$15, _27$$15, _28$$19, _29$$19, _30$$20;
	zend_bool error = 0, _16, _4$$3, _5$$3, _10$$7, _17$$11, _18$$11, _23$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
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
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_25$$15);
	ZEND_TLS zephir_method_cache _zephir_call_cache[20];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsManager", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1014, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD_CACHED(&relations, &manager, "getHasOneAndHasMany", &_zephir_call_cache[0], this_ptr);
	zephir_check_call_status();
	error = 0;
	if (Z_TYPE_P(&relations) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &relations);
		_1 = &_2;
	} else {
		_1 = &relations;
	}
	zephir_is_iterable(_1, 0, "phalcon/Mvc/Model.zep", 4634);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&relation);
			ZVAL_COPY(&relation, _3);
			ZEPHIR_CALL_METHOD_CACHED(&foreignKey, &relation, "getForeignKey", &_zephir_call_cache[1]);
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
				zephir_array_fetch_string(&_6$$5, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 4579);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				action = zephir_get_intval(&_6$$5);
			}
			if (action != 1) {
				continue;
			}
			ZEPHIR_CALL_METHOD_CACHED(&relationClass, &relation, "getReferencedModel", &_zephir_call_cache[2]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&fields, &relation, "getFields", &_zephir_call_cache[3]);
			zephir_check_call_status();
			ZVAL_NULL(&_8$$3);
			ZEPHIR_INIT_NVAR(&_9$$3);
			ZVAL_STRING(&_9$$3, "count");
			ZEPHIR_CALL_METHOD_CACHED(&_7$$3, &manager, "getRelationRecords", &_zephir_call_cache[4], &relation, this_ptr, &_8$$3, &_9$$3);
			zephir_check_call_status();
			if (zephir_is_true(&_7$$3)) {
				ZEPHIR_OBS_NVAR(&message);
				_10$$7 = zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_10$$7)) {
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
				ZEPHIR_INIT_NVAR(&_11$$7);
				object_init_ex(&_11$$7, phalcon_messages_message_ce);
				zephir_constructor_start(&_11$$7);
				ZEPHIR_INIT_NVAR(&_12$$7);
				zephir_create_array(&_12$$7, 2, 0);
				ZEPHIR_INIT_NVAR(&_13$$7);
				zephir_get_class(&_13$$7, this_ptr, 0);
				zephir_array_update_string(&_12$$7, SL("model"), &_13$$7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_12$$7, SL("referenceModel"), &relationClass, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_13$$7);
				ZVAL_STRING(&_13$$7, "ConstraintViolation");
				ZVAL_LONG(&_14$$7, 0);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_11$$7, "__construct", &_zephir_call_cache[5], &message, &messageField, &_13$$7, &_14$$7, &_12$$7);
				zephir_check_call_status();
				zephir_constructor_finish(&_11$$7);
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessage", &_zephir_call_cache[6], &_11$$7);
				zephir_check_call_status();
				error = 1;
				break;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "rewind", &_zephir_call_cache[7]);
		zephir_check_call_status();
		_16 = 1;
		while (1) {
			if (_16) {
				_16 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "next", &_zephir_call_cache[8]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_15, _1, "valid", &_zephir_call_cache[9]);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&relation, _1, "current", &_zephir_call_cache[10]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&foreignKey, &relation, "getForeignKey", &_zephir_call_cache[11]);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
					continue;
				}
				action = 1;
				_17$$11 = Z_TYPE_P(&foreignKey) == IS_ARRAY;
				if (_17$$11) {
					_18$$11 = zephir_array_isset_value_string(&foreignKey, SL("action"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_17$$11 = _18$$11;
				}
				if (_17$$11) {
					ZEPHIR_OBS_NVAR(&_19$$13);
					zephir_array_fetch_string(&_19$$13, &foreignKey, SL("action"), PH_NOISY, "phalcon/Mvc/Model.zep", 4579);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					action = zephir_get_intval(&_19$$13);
				}
				if (action != 1) {
					continue;
				}
				ZEPHIR_CALL_METHOD_CACHED(&relationClass, &relation, "getReferencedModel", &_zephir_call_cache[12]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&fields, &relation, "getFields", &_zephir_call_cache[13]);
				zephir_check_call_status();
				ZVAL_NULL(&_21$$11);
				ZEPHIR_INIT_NVAR(&_22$$11);
				ZVAL_STRING(&_22$$11, "count");
				ZEPHIR_CALL_METHOD_CACHED(&_20$$11, &manager, "getRelationRecords", &_zephir_call_cache[14], &relation, this_ptr, &_21$$11, &_22$$11);
				zephir_check_call_status();
				if (zephir_is_true(&_20$$11)) {
					ZEPHIR_OBS_NVAR(&message);
					_23$$15 = zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_23$$15)) {
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
					ZEPHIR_INIT_NVAR(&_24$$15);
					object_init_ex(&_24$$15, phalcon_messages_message_ce);
					zephir_constructor_start(&_24$$15);
					ZEPHIR_INIT_NVAR(&_25$$15);
					zephir_create_array(&_25$$15, 2, 0);
					ZEPHIR_INIT_NVAR(&_26$$15);
					zephir_get_class(&_26$$15, this_ptr, 0);
					zephir_array_update_string(&_25$$15, SL("model"), &_26$$15, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_25$$15, SL("referenceModel"), &relationClass, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_26$$15);
					ZVAL_STRING(&_26$$15, "ConstraintViolation");
					ZVAL_LONG(&_27$$15, 0);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_24$$15, "__construct", &_zephir_call_cache[15], &message, &messageField, &_26$$15, &_27$$15, &_25$$15);
					zephir_check_call_status();
					zephir_constructor_finish(&_24$$15);
					ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessage", &_zephir_call_cache[16], &_24$$15);
					zephir_check_call_status();
					error = 1;
					break;
				}
		}
	}
	if (error) {
		ZEPHIR_INIT_VAR(&_29$$19);
		ZVAL_STRING(&_29$$19, "orm.events");
		ZEPHIR_CALL_CE_STATIC_CACHED(&_28$$19, phalcon_support_settings_ce, "get", &_zephir_call_cache[17], &_29$$19);
		zephir_check_call_status();
		if (zephir_is_true(&_28$$19)) {
			ZEPHIR_INIT_VAR(&_30$$20);
			ZVAL_STRING(&_30$$20, "onValidationFails");
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "fireEvent", &_zephir_call_cache[18], &_30$$20);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "cancelOperation", &_zephir_call_cache[19]);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(Z_TYPE_P(&_0) != IS_ARRAY)) {
		zephir_throw_variable_type_error(&_0, "related", "array");
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&related, &_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 1015, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(Z_TYPE_P(&_1) != IS_ARRAY)) {
		zephir_throw_variable_type_error(&_1, "dirtyRelated", "array");
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&dirtyRelated, &_1);
	zephir_is_iterable(&related, 0, "phalcon/Mvc/Model.zep", 4686);
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
		ZEPHIR_CALL_METHOD_CACHED(&_7$$3, &record, "hasSnapshotData", &_zephir_call_cache[0]);
		zephir_check_call_status();
		_8$$3 = zephir_is_true(&_7$$3);
		if (_8$$3) {
			ZEPHIR_CALL_METHOD_CACHED(&_9$$3, &record, "hasChanged", &_zephir_call_cache[1]);
			zephir_check_call_status();
			_8$$3 = !zephir_is_true(&_9$$3);
		}
		if (_8$$3) {
			continue;
		}
		ZVAL_LONG(&_10$$3, 1);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &record, "setDirtyState", &_zephir_call_cache[2], &_10$$3);
		zephir_check_call_status();
		zephir_array_update_zval(&dirtyRelated, &name, &record, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} ZEND_HASH_FOREACH_END();
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
	zend_string *_80$$62;
	zend_ulong _79$$62;
	zend_bool useExplicitIdentity = 0, useSequences = 0, _30, _67, _5$$6, _8$$5, _9$$5, _10$$5, _11$$9, _12$$9, _13$$10, _16$$12, _17$$12, _21$$12, _24$$17, _31$$22, _34$$21, _35$$21, _36$$21, _37$$25, _38$$25, _39$$26, _42$$28, _43$$28, _47$$28, _50$$33, _59$$37, _56$$39, _60$$42, _61$$46, _69$$53, _70$$53, _71$$53, _72$$53, _82$$62;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *metaData, metaData_sub, *connection, connection_sub, *table = NULL, table_sub, *identityField, identityField_sub, __$null, attributes, automaticAttributes, bindDataTypes, bindSkip, bindType, columnMap, defaultValue, defaultValues, field, lastInsertedId, manager, rawValue, rawValues, sequenceName, schema, source, success, attributeField, bindTypes, fields, snapshot, unsetDefaultValues, value, values, _0, _1, _2, *_3, *_4, _29, _6$$7, _7$$7, _14$$11, _15$$11, _18$$13, _19$$13, _20$$13, _22$$16, _23$$16, _25$$18, _26$$18, _27$$18, _28$$18, _32$$23, _33$$23, _40$$27, _41$$27, _44$$29, _45$$29, _46$$29, _48$$32, _49$$32, _51$$34, _52$$34, _53$$34, _54$$34, _55$$37, _57$$40, _58$$40, _62$$48, _63$$48, _64$$52, _65$$52, _66$$52, _68$$53, _73$$53, _74$$61, _75$$61, *_76$$62, _77$$62, *_78$$62, _81$$62, _83$$62, _84$$62;
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
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_22$$16);
	ZVAL_UNDEF(&_23$$16);
	ZVAL_UNDEF(&_25$$18);
	ZVAL_UNDEF(&_26$$18);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_28$$18);
	ZVAL_UNDEF(&_32$$23);
	ZVAL_UNDEF(&_33$$23);
	ZVAL_UNDEF(&_40$$27);
	ZVAL_UNDEF(&_41$$27);
	ZVAL_UNDEF(&_44$$29);
	ZVAL_UNDEF(&_45$$29);
	ZVAL_UNDEF(&_46$$29);
	ZVAL_UNDEF(&_48$$32);
	ZVAL_UNDEF(&_49$$32);
	ZVAL_UNDEF(&_51$$34);
	ZVAL_UNDEF(&_52$$34);
	ZVAL_UNDEF(&_53$$34);
	ZVAL_UNDEF(&_54$$34);
	ZVAL_UNDEF(&_55$$37);
	ZVAL_UNDEF(&_57$$40);
	ZVAL_UNDEF(&_58$$40);
	ZVAL_UNDEF(&_62$$48);
	ZVAL_UNDEF(&_63$$48);
	ZVAL_UNDEF(&_64$$52);
	ZVAL_UNDEF(&_65$$52);
	ZVAL_UNDEF(&_66$$52);
	ZVAL_UNDEF(&_68$$53);
	ZVAL_UNDEF(&_73$$53);
	ZVAL_UNDEF(&_74$$61);
	ZVAL_UNDEF(&_75$$61);
	ZVAL_UNDEF(&_77$$62);
	ZVAL_UNDEF(&_81$$62);
	ZVAL_UNDEF(&_83$$62);
	ZVAL_UNDEF(&_84$$62);
	ZEND_TLS zephir_method_cache _zephir_call_cache[38];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&manager, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1019, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&rawValues, &_0);
	ZEPHIR_CALL_METHOD_CACHED(&attributes, metaData, "getAttributes", &_zephir_call_cache[0], this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&bindDataTypes, metaData, "getBindTypes", &_zephir_call_cache[1], this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&automaticAttributes, metaData, "getAutomaticCreateAttributes", &_zephir_call_cache[2], this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&defaultValues, metaData, "getDefaultValues", &_zephir_call_cache[3], this_ptr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "orm.column_renaming");
	ZEPHIR_CALL_CE_STATIC_CACHED(&_1, phalcon_support_settings_ce, "get", &_zephir_call_cache[4], &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_CALL_METHOD_CACHED(&columnMap, metaData, "getColumnMap", &_zephir_call_cache[5], this_ptr);
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
	zephir_is_iterable(_3, 0, "phalcon/Mvc/Model.zep", 4808);
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
					zephir_constructor_start(&_6$$7);
					ZEPHIR_INIT_NVAR(&_7$$7);
					zephir_get_class(&_7$$7, this_ptr, 0);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_6$$7, "__construct", &_zephir_call_cache[6], &field, &_7$$7);
					zephir_check_call_status();
					zephir_constructor_finish(&_6$$7);
					zephir_throw_exception_debug(&_6$$7, "phalcon/Mvc/Model.zep", 4736);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &field);
			}
			_8$$5 = zephir_array_key_exists(&automaticAttributes, &attributeField);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_9$$5 = !(_8$$5);
			if (_9$$5) {
				_10$$5 = !ZEPHIR_IS_EQUAL(&field, identityField);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_9$$5 = _10$$5;
			}
			if (_9$$5) {
				ZEPHIR_OBS_NVAR(&rawValue);
				_11$$9 = zephir_array_isset_fetch(&rawValue, &rawValues, &attributeField, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_11$$9) {
					ZEPHIR_OBS_NVAR(&bindType);
					_13$$10 = zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_13$$10))) {
						ZEPHIR_INIT_NVAR(&_14$$11);
						object_init_ex(&_14$$11, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
						zephir_constructor_start(&_14$$11);
						ZEPHIR_INIT_NVAR(&_15$$11);
						zephir_get_class(&_15$$11, this_ptr, 0);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_14$$11, "__construct", &_zephir_call_cache[7], &field, &_15$$11);
						zephir_check_call_status();
						zephir_constructor_finish(&_14$$11);
						zephir_throw_exception_debug(&_14$$11, "phalcon/Mvc/Model.zep", 4753);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4756);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&values, &rawValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4757);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4758);
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
					_12$$9 = zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_12$$9) {
						_16$$12 = Z_TYPE_P(&value) == IS_NULL;
						if (_16$$12) {
							_17$$12 = zephir_array_key_exists(&defaultValues, &field);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							_16$$12 = _17$$12;
						}
						if (_16$$12) {
							ZEPHIR_OBS_NVAR(&_18$$13);
							zephir_array_fetch(&_18$$13, &defaultValues, &field, PH_NOISY, "phalcon/Mvc/Model.zep", 4762);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&snapshot, &attributeField, &_18$$13, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&_19$$13);
							zephir_array_fetch(&_19$$13, &defaultValues, &field, PH_NOISY, "phalcon/Mvc/Model.zep", 4763);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&unsetDefaultValues, &attributeField, &_19$$13, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_METHOD_CACHED(&_20$$13, connection, "supportsDefaultValue", &_zephir_call_cache[8]);
							zephir_check_call_status();
							if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_20$$13))) {
								continue;
							}
							ZEPHIR_CALL_METHOD_CACHED(&value, connection, "getDefaultValue", &_zephir_call_cache[9]);
							zephir_check_call_status();
						} else {
							zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
						ZEPHIR_OBS_NVAR(&bindType);
						_21$$12 = zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (UNEXPECTED(!(_21$$12))) {
							ZEPHIR_INIT_NVAR(&_22$$16);
							object_init_ex(&_22$$16, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
							zephir_constructor_start(&_22$$16);
							ZEPHIR_INIT_NVAR(&_23$$16);
							zephir_get_class(&_23$$16, this_ptr, 0);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_22$$16, "__construct", &_zephir_call_cache[10], &field, &_23$$16);
							zephir_check_call_status();
							zephir_constructor_finish(&_22$$16);
							zephir_throw_exception_debug(&_22$$16, "phalcon/Mvc/Model.zep", 4778);
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4781);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4782);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4783);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						_24$$17 = zephir_array_key_exists(&defaultValues, &field);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_24$$17) {
							ZEPHIR_OBS_NVAR(&_25$$18);
							zephir_array_fetch(&_25$$18, &defaultValues, &field, PH_NOISY, "phalcon/Mvc/Model.zep", 4786);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&snapshot, &attributeField, &_25$$18, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&_26$$18);
							zephir_array_fetch(&_26$$18, &defaultValues, &field, PH_NOISY, "phalcon/Mvc/Model.zep", 4787);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&unsetDefaultValues, &attributeField, &_26$$18, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_METHOD_CACHED(&_27$$18, connection, "supportsDefaultValue", &_zephir_call_cache[11]);
							zephir_check_call_status();
							if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_27$$18))) {
								continue;
							}
							ZEPHIR_CALL_METHOD_CACHED(&_28$$18, connection, "getDefaultValue", &_zephir_call_cache[12]);
							zephir_check_call_status();
							zephir_array_append(&values, &_28$$18, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4793);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4795);
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
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4799);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4800);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _3, "rewind", &_zephir_call_cache[13]);
		zephir_check_call_status();
		_30 = 1;
		while (1) {
			if (_30) {
				_30 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _3, "next", &_zephir_call_cache[14]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_29, _3, "valid", &_zephir_call_cache[15]);
			zephir_check_call_status();
			if (!zend_is_true(&_29)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&field, _3, "current", &_zephir_call_cache[16]);
			zephir_check_call_status();
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					_31$$22 = zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_31$$22))) {
						ZEPHIR_INIT_NVAR(&_32$$23);
						object_init_ex(&_32$$23, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
						zephir_constructor_start(&_32$$23);
						ZEPHIR_INIT_NVAR(&_33$$23);
						zephir_get_class(&_33$$23, this_ptr, 0);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_32$$23, "__construct", &_zephir_call_cache[17], &field, &_33$$23);
						zephir_check_call_status();
						zephir_constructor_finish(&_32$$23);
						zephir_throw_exception_debug(&_32$$23, "phalcon/Mvc/Model.zep", 4736);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &field);
				}
				_34$$21 = zephir_array_key_exists(&automaticAttributes, &attributeField);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_35$$21 = !(_34$$21);
				if (_35$$21) {
					_36$$21 = !ZEPHIR_IS_EQUAL(&field, identityField);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_35$$21 = _36$$21;
				}
				if (_35$$21) {
					ZEPHIR_OBS_NVAR(&rawValue);
					_37$$25 = zephir_array_isset_fetch(&rawValue, &rawValues, &attributeField, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_37$$25) {
						ZEPHIR_OBS_NVAR(&bindType);
						_39$$26 = zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (UNEXPECTED(!(_39$$26))) {
							ZEPHIR_INIT_NVAR(&_40$$27);
							object_init_ex(&_40$$27, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
							zephir_constructor_start(&_40$$27);
							ZEPHIR_INIT_NVAR(&_41$$27);
							zephir_get_class(&_41$$27, this_ptr, 0);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_40$$27, "__construct", &_zephir_call_cache[18], &field, &_41$$27);
							zephir_check_call_status();
							zephir_constructor_finish(&_40$$27);
							zephir_throw_exception_debug(&_40$$27, "phalcon/Mvc/Model.zep", 4753);
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4756);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&values, &rawValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4757);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4758);
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
						_38$$25 = zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_38$$25) {
							_42$$28 = Z_TYPE_P(&value) == IS_NULL;
							if (_42$$28) {
								_43$$28 = zephir_array_key_exists(&defaultValues, &field);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								_42$$28 = _43$$28;
							}
							if (_42$$28) {
								ZEPHIR_OBS_NVAR(&_44$$29);
								zephir_array_fetch(&_44$$29, &defaultValues, &field, PH_NOISY, "phalcon/Mvc/Model.zep", 4762);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_zval(&snapshot, &attributeField, &_44$$29, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&_45$$29);
								zephir_array_fetch(&_45$$29, &defaultValues, &field, PH_NOISY, "phalcon/Mvc/Model.zep", 4763);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_zval(&unsetDefaultValues, &attributeField, &_45$$29, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CALL_METHOD_CACHED(&_46$$29, connection, "supportsDefaultValue", &_zephir_call_cache[19]);
								zephir_check_call_status();
								if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_46$$29))) {
									continue;
								}
								ZEPHIR_CALL_METHOD_CACHED(&value, connection, "getDefaultValue", &_zephir_call_cache[20]);
								zephir_check_call_status();
							} else {
								zephir_array_update_zval(&snapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
							ZEPHIR_OBS_NVAR(&bindType);
							_47$$28 = zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (UNEXPECTED(!(_47$$28))) {
								ZEPHIR_INIT_NVAR(&_48$$32);
								object_init_ex(&_48$$32, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
								zephir_constructor_start(&_48$$32);
								ZEPHIR_INIT_NVAR(&_49$$32);
								zephir_get_class(&_49$$32, this_ptr, 0);
								ZEPHIR_CALL_METHOD_CACHED(NULL, &_48$$32, "__construct", &_zephir_call_cache[21], &field, &_49$$32);
								zephir_check_call_status();
								zephir_constructor_finish(&_48$$32);
								zephir_throw_exception_debug(&_48$$32, "phalcon/Mvc/Model.zep", 4778);
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4781);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4782);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4783);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							_50$$33 = zephir_array_key_exists(&defaultValues, &field);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (_50$$33) {
								ZEPHIR_OBS_NVAR(&_51$$34);
								zephir_array_fetch(&_51$$34, &defaultValues, &field, PH_NOISY, "phalcon/Mvc/Model.zep", 4786);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_zval(&snapshot, &attributeField, &_51$$34, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&_52$$34);
								zephir_array_fetch(&_52$$34, &defaultValues, &field, PH_NOISY, "phalcon/Mvc/Model.zep", 4787);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_zval(&unsetDefaultValues, &attributeField, &_52$$34, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CALL_METHOD_CACHED(&_53$$34, connection, "supportsDefaultValue", &_zephir_call_cache[22]);
								zephir_check_call_status();
								if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_53$$34))) {
									continue;
								}
								ZEPHIR_CALL_METHOD_CACHED(&_54$$34, connection, "getDefaultValue", &_zephir_call_cache[23]);
								zephir_check_call_status();
								zephir_array_append(&values, &_54$$34, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4793);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} else {
								zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4795);
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
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4799);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4800);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					}
				}
		}
	}
	if (!ZEPHIR_IS_FALSE_IDENTICAL(identityField)) {
		ZEPHIR_CALL_METHOD_CACHED(&defaultValue, connection, "getDefaultIdValue", &_zephir_call_cache[24]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_55$$37, connection, "useExplicitIdValue", &_zephir_call_cache[25]);
		zephir_check_call_status();
		useExplicitIdentity = zephir_get_boolval(&_55$$37);
		if (useExplicitIdentity) {
			zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4818);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&attributeField);
			_56$$39 = zephir_array_isset_fetch(&attributeField, &columnMap, identityField, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (UNEXPECTED(!(_56$$39))) {
				ZEPHIR_INIT_VAR(&_57$$40);
				object_init_ex(&_57$$40, phalcon_mvc_model_exceptions_identitynotincolumnmap_ce);
				zephir_constructor_start(&_57$$40);
				ZEPHIR_INIT_VAR(&_58$$40);
				zephir_get_class(&_58$$40, this_ptr, 0);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_57$$40, "__construct", &_zephir_call_cache[26], identityField, &_58$$40);
				zephir_check_call_status();
				zephir_constructor_finish(&_57$$40);
				zephir_throw_exception_debug(&_57$$40, "phalcon/Mvc/Model.zep", 4826);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(&attributeField, identityField);
		}
		ZEPHIR_OBS_NVAR(&value);
		_59$$37 = zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_59$$37) {
			_60$$42 = Z_TYPE_P(&value) == IS_NULL;
			if (!(_60$$42)) {
				_60$$42 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
			}
			if (_60$$42) {
				if (useExplicitIdentity) {
					zephir_array_append(&values, &defaultValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4838);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4838);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else if (ZEPHIR_IS_EMPTY(&values)) {
					zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4845);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&values, &defaultValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4846);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4847);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} else {
				if (!(useExplicitIdentity)) {
					zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4855);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_OBS_NVAR(&bindType);
				_61$$46 = zephir_array_isset_fetch(&bindType, &bindDataTypes, identityField, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_61$$46))) {
					ZEPHIR_INIT_VAR(&_62$$48);
					object_init_ex(&_62$$48, phalcon_mvc_model_exceptions_identitynotintablecolumns_ce);
					zephir_constructor_start(&_62$$48);
					ZEPHIR_INIT_VAR(&_63$$48);
					zephir_get_class(&_63$$48, this_ptr, 0);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_62$$48, "__construct", &_zephir_call_cache[27], identityField, &_63$$48);
					zephir_check_call_status();
					zephir_constructor_finish(&_62$$48);
					zephir_throw_exception_debug(&_62$$48, "phalcon/Mvc/Model.zep", 4862);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4865);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4866);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} else {
			if (useExplicitIdentity) {
				zephir_array_append(&values, &defaultValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4870);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4871);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else if (ZEPHIR_IS_EMPTY(&values)) {
				zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4878);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&values, &defaultValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4879);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 4880);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	if (Z_TYPE_P(table) == IS_ARRAY) {
		zephir_memory_observe(&_64$$52);
		zephir_array_fetch_long(&_64$$52, table, 0, PH_NOISY, "phalcon/Mvc/Model.zep", 4889);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&_65$$52);
		zephir_array_fetch_long(&_65$$52, table, 1, PH_NOISY, "phalcon/Mvc/Model.zep", 4889);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_66$$52);
		ZEPHIR_CONCAT_VSV(&_66$$52, &_64$$52, ".", &_65$$52);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(table, &_66$$52);
	}
	ZEPHIR_CALL_METHOD_CACHED(&success, connection, "insert", &_zephir_call_cache[28], table, &values, &fields, &bindTypes);
	zephir_check_call_status();
	_67 = zephir_is_true(&success);
	if (_67) {
		_67 = !ZEPHIR_IS_FALSE_IDENTICAL(identityField);
	}
	if (_67) {
		ZEPHIR_INIT_VAR(&sequenceName);
		ZVAL_NULL(&sequenceName);
		ZEPHIR_CALL_METHOD_CACHED(&_68$$53, connection, "supportSequences", &_zephir_call_cache[29]);
		zephir_check_call_status();
		useSequences = zephir_get_boolval(&_68$$53);
		if (useSequences) {
			if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("getsequencename")) == SUCCESS)) {
				ZEPHIR_CALL_METHOD_CACHED(&sequenceName, this_ptr, "getSequenceName", &_zephir_call_cache[30]);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(&source, this_ptr, "getSource", &_zephir_call_cache[31]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&schema, this_ptr, "getSchema", &_zephir_call_cache[32]);
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
		_69$$53 = zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_70$$53 = Z_TYPE_P(&value) != IS_NULL;
		if (_70$$53) {
			_70$$53 = !ZEPHIR_IS_STRING_IDENTICAL(&value, "");
		}
		_71$$53 = _70$$53;
		if (_71$$53) {
			_72$$53 = useSequences;
			if (!(_72$$53)) {
				_72$$53 = !ZEPHIR_IS_LONG(&value, 0);
			}
			_71$$53 = _72$$53;
		}
		if (_71$$53) {
			ZEPHIR_CPY_WRT(&lastInsertedId, &value);
		} else {
			ZEPHIR_CALL_METHOD_CACHED(&lastInsertedId, connection, "lastInsertId", &_zephir_call_cache[33], &sequenceName);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(&_73$$53);
		ZVAL_STRING(&_73$$53, "orm.cast_last_insert_id_to_int");
		ZEPHIR_CALL_CE_STATIC_CACHED(&_68$$53, phalcon_support_settings_ce, "get", &_zephir_call_cache[34], &_73$$53);
		zephir_check_call_status();
		if (UNEXPECTED(zephir_is_true(&_68$$53))) {
			ZVAL_LONG(&_74$$61, 10);
			ZEPHIR_CALL_FUNCTION(&_75$$61, "intval", NULL, 37, &lastInsertedId, &_74$$61);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&lastInsertedId, &_75$$61);
		}
		zephir_update_property_zval_zval(this_ptr, &attributeField, &lastInsertedId);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_zval(&snapshot, &attributeField, &lastInsertedId, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1027, &__$null);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1028, &__$null);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (zephir_is_true(&success)) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &manager, "registerWrite", &_zephir_call_cache[35], this_ptr);
		zephir_check_call_status();
		if (Z_TYPE_P(&unsetDefaultValues) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_77$$62);
			zephir_string_to_char_array(&_77$$62, &unsetDefaultValues);
			_76$$62 = &_77$$62;
		} else {
			_76$$62 = &unsetDefaultValues;
		}
		zephir_is_iterable(_76$$62, 0, "phalcon/Mvc/Model.zep", 4971);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_76$$62), _79$$62, _80$$62, _78$$62)
		{
			ZEPHIR_INIT_NVAR(&attributeField);
			if (_80$$62 != NULL) { 
				ZVAL_STR_COPY(&attributeField, _80$$62);
			} else {
				ZVAL_LONG(&attributeField, _79$$62);
			}
			ZEPHIR_INIT_NVAR(&defaultValue);
			ZVAL_COPY(&defaultValue, _78$$62);
			zephir_update_property_zval_zval(this_ptr, &attributeField, &defaultValue);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_CALL_METHOD_CACHED(&_81$$62, &manager, "isKeepingSnapshots", &_zephir_call_cache[36], this_ptr);
		zephir_check_call_status();
		_82$$62 = zephir_is_true(&_81$$62);
		if (_82$$62) {
			ZEPHIR_INIT_VAR(&_84$$62);
			ZVAL_STRING(&_84$$62, "orm.update_snapshot_on_save");
			ZEPHIR_CALL_CE_STATIC_CACHED(&_83$$62, phalcon_support_settings_ce, "get", &_zephir_call_cache[37], &_84$$62);
			zephir_check_call_status();
			_82$$62 = zephir_is_true(&_83$$62);
		}
		if (_82$$62) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1018, &snapshot);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
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
	zval _28$$26, _29$$26, _53$$50, _54$$50;
	zval _111;
	zend_bool changed = 0, useDynamicUpdate = 0, _3, _113, _115, _32$$5, _7$$7, _12$$6, _13$$11, _16$$11, _17$$11, _18$$14, _19$$20, _22$$20, _24$$20, _30$$27, _33$$31, _38$$30, _39$$35, _42$$35, _43$$35, _44$$38, _45$$44, _48$$44, _50$$44, _55$$51, _76$$55, _59$$57, _64$$56, _65$$61, _68$$61, _69$$61, _70$$64, _71$$64, _72$$64, _74$$64, _77$$68, _82$$67, _83$$72, _86$$72, _87$$72, _88$$75, _89$$75, _90$$75, _92$$75, _103$$79, _98$$82, _101$$81, _104$$88, _107$$87;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_26 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *metaData, metaData_sub, *connection, connection_sub, *table = NULL, table_sub, __$null, automaticAttributes, attributeField, bindSkip, bindDataTypes, bindType, bindTypes, columnMap, dataType, dataTypes, defaultValues, field, fields, manager, nonPrimary, newSnapshot, rawValue, rawValues, success, primaryKeys, snapshot, snapshotValue, uniqueKey, uniqueParams, value, values, updateValue, _0, _1, _2, _112, _114, _116, *_4$$5, _5$$5, *_6$$5, _31$$5, _8$$8, _9$$8, _10$$9, _11$$9, _14$$12, _15$$12, _20$$21, _21$$21, _23$$22, _25$$25, _27$$25, _34$$32, _35$$32, _36$$33, _37$$33, _40$$36, _41$$36, _46$$45, _47$$45, _49$$46, _51$$49, _52$$49, *_56$$55, _57$$55, *_58$$55, _75$$55, _60$$58, _61$$58, _62$$59, _63$$59, _66$$62, _67$$62, _73$$64, _78$$69, _79$$69, _80$$70, _81$$70, _84$$73, _85$$73, _91$$75, _93$$80, _94$$80, *_95$$79, _96$$79, *_97$$79, _102$$79, _99$$83, _100$$83, _105$$89, _106$$89, _108$$93, _109$$93, _110$$93, _117$$96, _118$$97;
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
	ZVAL_UNDEF(&_112);
	ZVAL_UNDEF(&_114);
	ZVAL_UNDEF(&_116);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_31$$5);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_20$$21);
	ZVAL_UNDEF(&_21$$21);
	ZVAL_UNDEF(&_23$$22);
	ZVAL_UNDEF(&_25$$25);
	ZVAL_UNDEF(&_27$$25);
	ZVAL_UNDEF(&_34$$32);
	ZVAL_UNDEF(&_35$$32);
	ZVAL_UNDEF(&_36$$33);
	ZVAL_UNDEF(&_37$$33);
	ZVAL_UNDEF(&_40$$36);
	ZVAL_UNDEF(&_41$$36);
	ZVAL_UNDEF(&_46$$45);
	ZVAL_UNDEF(&_47$$45);
	ZVAL_UNDEF(&_49$$46);
	ZVAL_UNDEF(&_51$$49);
	ZVAL_UNDEF(&_52$$49);
	ZVAL_UNDEF(&_57$$55);
	ZVAL_UNDEF(&_75$$55);
	ZVAL_UNDEF(&_60$$58);
	ZVAL_UNDEF(&_61$$58);
	ZVAL_UNDEF(&_62$$59);
	ZVAL_UNDEF(&_63$$59);
	ZVAL_UNDEF(&_66$$62);
	ZVAL_UNDEF(&_67$$62);
	ZVAL_UNDEF(&_73$$64);
	ZVAL_UNDEF(&_78$$69);
	ZVAL_UNDEF(&_79$$69);
	ZVAL_UNDEF(&_80$$70);
	ZVAL_UNDEF(&_81$$70);
	ZVAL_UNDEF(&_84$$73);
	ZVAL_UNDEF(&_85$$73);
	ZVAL_UNDEF(&_91$$75);
	ZVAL_UNDEF(&_93$$80);
	ZVAL_UNDEF(&_94$$80);
	ZVAL_UNDEF(&_96$$79);
	ZVAL_UNDEF(&_102$$79);
	ZVAL_UNDEF(&_99$$83);
	ZVAL_UNDEF(&_100$$83);
	ZVAL_UNDEF(&_105$$89);
	ZVAL_UNDEF(&_106$$89);
	ZVAL_UNDEF(&_108$$93);
	ZVAL_UNDEF(&_109$$93);
	ZVAL_UNDEF(&_110$$93);
	ZVAL_UNDEF(&_117$$96);
	ZVAL_UNDEF(&_118$$97);
	ZVAL_UNDEF(&_111);
	ZVAL_UNDEF(&_28$$26);
	ZVAL_UNDEF(&_29$$26);
	ZVAL_UNDEF(&_53$$50);
	ZVAL_UNDEF(&_54$$50);
	ZEND_TLS zephir_method_cache _zephir_call_cache[46];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&rawValues, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1014, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD_CACHED(&_1, &manager, "isUsingDynamicUpdate", &_zephir_call_cache[0], this_ptr);
	zephir_check_call_status();
	useDynamicUpdate = zephir_get_boolval(&_1);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 1018, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&snapshot, &_0);
	ZEPHIR_CALL_METHOD_CACHED(&dataTypes, metaData, "getDataTypes", &_zephir_call_cache[1], this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&bindDataTypes, metaData, "getBindTypes", &_zephir_call_cache[2], this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&defaultValues, metaData, "getDefaultValues", &_zephir_call_cache[3], this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&nonPrimary, metaData, "getNonPrimaryKeyAttributes", &_zephir_call_cache[4], this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&automaticAttributes, metaData, "getAutomaticUpdateAttributes", &_zephir_call_cache[5], this_ptr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "orm.column_renaming");
	ZEPHIR_CALL_CE_STATIC_CACHED(&_1, phalcon_support_settings_ce, "get", &_zephir_call_cache[6], &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_CALL_METHOD_CACHED(&columnMap, metaData, "getColumnMap", &_zephir_call_cache[7], this_ptr);
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
		zephir_is_iterable(_4$$5, 0, "phalcon/Mvc/Model.zep", 5131);
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
						ZEPHIR_INIT_NVAR(&_9$$8);
						ZVAL_STRING(&_9$$8, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC_CACHED(&_8$$8, phalcon_support_settings_ce, "get", &_zephir_call_cache[8], &_9$$8);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_8$$8))) {
							ZEPHIR_INIT_NVAR(&_10$$9);
							object_init_ex(&_10$$9, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
							zephir_constructor_start(&_10$$9);
							ZEPHIR_INIT_NVAR(&_11$$9);
							zephir_get_class(&_11$$9, this_ptr, 0);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_10$$9, "__construct", &_zephir_call_cache[9], &field, &_11$$9);
							zephir_check_call_status();
							zephir_constructor_finish(&_10$$9);
							zephir_throw_exception_debug(&_10$$9, "phalcon/Mvc/Model.zep", 5025);
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &field);
				}
				_12$$6 = zephir_array_key_exists(&automaticAttributes, &attributeField);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_12$$6)) {
					ZEPHIR_OBS_NVAR(&bindType);
					_13$$11 = zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_13$$11))) {
						ZEPHIR_INIT_NVAR(&_14$$12);
						object_init_ex(&_14$$12, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
						zephir_constructor_start(&_14$$12);
						ZEPHIR_INIT_NVAR(&_15$$12);
						zephir_get_class(&_15$$12, this_ptr, 0);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_14$$12, "__construct", &_zephir_call_cache[10], &field, &_15$$12);
						zephir_check_call_status();
						zephir_constructor_finish(&_14$$12);
						zephir_throw_exception_debug(&_14$$12, "phalcon/Mvc/Model.zep", 5036);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&rawValue);
					_16$$11 = zephir_array_isset_fetch(&rawValue, &rawValues, &attributeField, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_16$$11) {
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5043);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&values, &rawValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5044);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5045);
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
						_17$$11 = zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_17$$11) {
							ZEPHIR_OBS_NVAR(&snapshotValue);
							_18$$14 = zephir_array_isset_fetch(&snapshotValue, &snapshot, &attributeField, 0);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (!(_18$$14)) {
								changed = 1;
							} else {
								if (Z_TYPE_P(&value) == IS_NULL) {
									changed = Z_TYPE_P(&snapshotValue) != IS_NULL;
								} else {
									if (Z_TYPE_P(&snapshotValue) == IS_NULL) {
										changed = 1;
									} else {
										ZEPHIR_OBS_NVAR(&dataType);
										_19$$20 = zephir_array_isset_fetch(&dataType, &dataTypes, &field, 0);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										if (UNEXPECTED(!(_19$$20))) {
											ZEPHIR_INIT_NVAR(&_20$$21);
											object_init_ex(&_20$$21, phalcon_mvc_model_exceptions_datatypenotdefined_ce);
											zephir_constructor_start(&_20$$21);
											ZEPHIR_INIT_NVAR(&_21$$21);
											zephir_get_class(&_21$$21, this_ptr, 0);
											ZEPHIR_CALL_METHOD_CACHED(NULL, &_20$$21, "__construct", &_zephir_call_cache[11], &field, &_21$$21);
											zephir_check_call_status();
											zephir_constructor_finish(&_20$$21);
											zephir_throw_exception_debug(&_20$$21, "phalcon/Mvc/Model.zep", 5069);
											ZEPHIR_MM_RESTORE();
											return;
										}
										_22$$20 = (Z_TYPE_P(&snapshotValue) == IS_OBJECT);
										if (_22$$20) {
											_22$$20 = zephir_instance_of_ev(&snapshotValue, phalcon_db_rawvalue_ce);
										}
										if (_22$$20) {
											ZEPHIR_CALL_METHOD_CACHED(&_23$$22, &snapshotValue, "getValue", &_zephir_call_cache[12]);
											zephir_check_call_status();
											ZEPHIR_CPY_WRT(&snapshotValue, &_23$$22);
										}
										ZEPHIR_CPY_WRT(&updateValue, &value);
										_24$$20 = (Z_TYPE_P(&value) == IS_OBJECT);
										if (_24$$20) {
											_24$$20 = zephir_instance_of_ev(&value, phalcon_db_rawvalue_ce);
										}
										if (_24$$20) {
											ZEPHIR_CALL_METHOD_CACHED(&updateValue, &value, "getValue", &_zephir_call_cache[13]);
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
											ZEPHIR_CALL_FUNCTION(&_25$$25, "floatval", &_26, 22, &snapshotValue);
											zephir_check_call_status();
											ZEPHIR_CALL_FUNCTION(&_27$$25, "floatval", &_26, 22, &updateValue);
											zephir_check_call_status();
											changed = !ZEPHIR_IS_IDENTICAL(&_25$$25, &_27$$25);
											goto zephir_switch_0_end;
										zephir_switch_0_clause_3: ;
										zephir_switch_0_clause_4: ;
										zephir_switch_0_clause_5: ;
										zephir_switch_0_clause_6: ;
										zephir_switch_0_clause_7: ;
										zephir_switch_0_clause_8: ;
										zephir_switch_0_clause_9: ;
											zephir_cast_to_string(&_28$$26, &snapshotValue);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_cast_to_string(&_29$$26, &updateValue);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											changed = !ZEPHIR_IS_IDENTICAL(&_28$$26, &_29$$26);
											goto zephir_switch_0_end;
										zephir_switch_0_clause_10: ;
											_30$$27 = !ZEPHIR_IS_EQUAL(&updateValue, &snapshotValue);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											changed = _30$$27;
										zephir_switch_0_end: ;

									}
								}
							}
							if (changed) {
								zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5118);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5119);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5120);
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
			ZEPHIR_CALL_METHOD_CACHED(NULL, _4$$5, "rewind", &_zephir_call_cache[14]);
			zephir_check_call_status();
			_32$$5 = 1;
			while (1) {
				if (_32$$5) {
					_32$$5 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _4$$5, "next", &_zephir_call_cache[15]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_31$$5, _4$$5, "valid", &_zephir_call_cache[16]);
				zephir_check_call_status();
				if (!zend_is_true(&_31$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&field, _4$$5, "current", &_zephir_call_cache[17]);
				zephir_check_call_status();
					changed = 0;
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						_33$$31 = zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (UNEXPECTED(!(_33$$31))) {
							ZEPHIR_INIT_NVAR(&_35$$32);
							ZVAL_STRING(&_35$$32, "orm.ignore_unknown_columns");
							ZEPHIR_CALL_CE_STATIC_CACHED(&_34$$32, phalcon_support_settings_ce, "get", &_zephir_call_cache[18], &_35$$32);
							zephir_check_call_status();
							if (UNEXPECTED(!zephir_is_true(&_34$$32))) {
								ZEPHIR_INIT_NVAR(&_36$$33);
								object_init_ex(&_36$$33, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
								zephir_constructor_start(&_36$$33);
								ZEPHIR_INIT_NVAR(&_37$$33);
								zephir_get_class(&_37$$33, this_ptr, 0);
								ZEPHIR_CALL_METHOD_CACHED(NULL, &_36$$33, "__construct", &_zephir_call_cache[19], &field, &_37$$33);
								zephir_check_call_status();
								zephir_constructor_finish(&_36$$33);
								zephir_throw_exception_debug(&_36$$33, "phalcon/Mvc/Model.zep", 5025);
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} else {
						ZEPHIR_CPY_WRT(&attributeField, &field);
					}
					_38$$30 = zephir_array_key_exists(&automaticAttributes, &attributeField);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_38$$30)) {
						ZEPHIR_OBS_NVAR(&bindType);
						_39$$35 = zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (UNEXPECTED(!(_39$$35))) {
							ZEPHIR_INIT_NVAR(&_40$$36);
							object_init_ex(&_40$$36, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
							zephir_constructor_start(&_40$$36);
							ZEPHIR_INIT_NVAR(&_41$$36);
							zephir_get_class(&_41$$36, this_ptr, 0);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_40$$36, "__construct", &_zephir_call_cache[20], &field, &_41$$36);
							zephir_check_call_status();
							zephir_constructor_finish(&_40$$36);
							zephir_throw_exception_debug(&_40$$36, "phalcon/Mvc/Model.zep", 5036);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_OBS_NVAR(&rawValue);
						_42$$35 = zephir_array_isset_fetch(&rawValue, &rawValues, &attributeField, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_42$$35) {
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5043);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&values, &rawValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5044);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5045);
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
							_43$$35 = zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (_43$$35) {
								ZEPHIR_OBS_NVAR(&snapshotValue);
								_44$$38 = zephir_array_isset_fetch(&snapshotValue, &snapshot, &attributeField, 0);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (!(_44$$38)) {
									changed = 1;
								} else {
									if (Z_TYPE_P(&value) == IS_NULL) {
										changed = Z_TYPE_P(&snapshotValue) != IS_NULL;
									} else {
										if (Z_TYPE_P(&snapshotValue) == IS_NULL) {
											changed = 1;
										} else {
											ZEPHIR_OBS_NVAR(&dataType);
											_45$$44 = zephir_array_isset_fetch(&dataType, &dataTypes, &field, 0);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											if (UNEXPECTED(!(_45$$44))) {
												ZEPHIR_INIT_NVAR(&_46$$45);
												object_init_ex(&_46$$45, phalcon_mvc_model_exceptions_datatypenotdefined_ce);
												zephir_constructor_start(&_46$$45);
												ZEPHIR_INIT_NVAR(&_47$$45);
												zephir_get_class(&_47$$45, this_ptr, 0);
												ZEPHIR_CALL_METHOD_CACHED(NULL, &_46$$45, "__construct", &_zephir_call_cache[21], &field, &_47$$45);
												zephir_check_call_status();
												zephir_constructor_finish(&_46$$45);
												zephir_throw_exception_debug(&_46$$45, "phalcon/Mvc/Model.zep", 5069);
												ZEPHIR_MM_RESTORE();
												return;
											}
											_48$$44 = (Z_TYPE_P(&snapshotValue) == IS_OBJECT);
											if (_48$$44) {
												_48$$44 = zephir_instance_of_ev(&snapshotValue, phalcon_db_rawvalue_ce);
											}
											if (_48$$44) {
												ZEPHIR_CALL_METHOD_CACHED(&_49$$46, &snapshotValue, "getValue", &_zephir_call_cache[22]);
												zephir_check_call_status();
												ZEPHIR_CPY_WRT(&snapshotValue, &_49$$46);
											}
											ZEPHIR_CPY_WRT(&updateValue, &value);
											_50$$44 = (Z_TYPE_P(&value) == IS_OBJECT);
											if (_50$$44) {
												_50$$44 = zephir_instance_of_ev(&value, phalcon_db_rawvalue_ce);
											}
											if (_50$$44) {
												ZEPHIR_CALL_METHOD_CACHED(&updateValue, &value, "getValue", &_zephir_call_cache[23]);
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
												ZEPHIR_CALL_FUNCTION(&_51$$49, "floatval", &_26, 22, &snapshotValue);
												zephir_check_call_status();
												ZEPHIR_CALL_FUNCTION(&_52$$49, "floatval", &_26, 22, &updateValue);
												zephir_check_call_status();
												changed = !ZEPHIR_IS_IDENTICAL(&_51$$49, &_52$$49);
												goto zephir_switch_1_end;
											zephir_switch_1_clause_3: ;
											zephir_switch_1_clause_4: ;
											zephir_switch_1_clause_5: ;
											zephir_switch_1_clause_6: ;
											zephir_switch_1_clause_7: ;
											zephir_switch_1_clause_8: ;
											zephir_switch_1_clause_9: ;
												zephir_cast_to_string(&_53$$50, &snapshotValue);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_cast_to_string(&_54$$50, &updateValue);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												changed = !ZEPHIR_IS_IDENTICAL(&_53$$50, &_54$$50);
												goto zephir_switch_1_end;
											zephir_switch_1_clause_10: ;
												_55$$51 = !ZEPHIR_IS_EQUAL(&updateValue, &snapshotValue);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												changed = _55$$51;
											zephir_switch_1_end: ;

										}
									}
								}
								if (changed) {
									zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5118);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5119);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5120);
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
		if (ZEPHIR_IS_EMPTY(&fields)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1024, &snapshot);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_MM_BOOL(1);
		}
	} else {
		if (Z_TYPE_P(&nonPrimary) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_57$$55);
			zephir_string_to_char_array(&_57$$55, &nonPrimary);
			_56$$55 = &_57$$55;
		} else {
			_56$$55 = &nonPrimary;
		}
		zephir_is_iterable(_56$$55, 0, "phalcon/Mvc/Model.zep", 5196);
		if (Z_TYPE_P(_56$$55) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_56$$55), _58$$55)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _58$$55);
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					_59$$57 = zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_59$$57))) {
						ZEPHIR_INIT_NVAR(&_61$$58);
						ZVAL_STRING(&_61$$58, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC_CACHED(&_60$$58, phalcon_support_settings_ce, "get", &_zephir_call_cache[24], &_61$$58);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_60$$58))) {
							ZEPHIR_INIT_NVAR(&_62$$59);
							object_init_ex(&_62$$59, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
							zephir_constructor_start(&_62$$59);
							ZEPHIR_INIT_NVAR(&_63$$59);
							zephir_get_class(&_63$$59, this_ptr, 0);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_62$$59, "__construct", &_zephir_call_cache[25], &field, &_63$$59);
							zephir_check_call_status();
							zephir_constructor_finish(&_62$$59);
							zephir_throw_exception_debug(&_62$$59, "phalcon/Mvc/Model.zep", 5147);
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &field);
				}
				_64$$56 = zephir_array_key_exists(&automaticAttributes, &attributeField);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_64$$56)) {
					ZEPHIR_OBS_NVAR(&bindType);
					_65$$61 = zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_65$$61))) {
						ZEPHIR_INIT_NVAR(&_66$$62);
						object_init_ex(&_66$$62, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
						zephir_constructor_start(&_66$$62);
						ZEPHIR_INIT_NVAR(&_67$$62);
						zephir_get_class(&_67$$62, this_ptr, 0);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_66$$62, "__construct", &_zephir_call_cache[26], &field, &_67$$62);
						zephir_check_call_status();
						zephir_constructor_finish(&_66$$62);
						zephir_throw_exception_debug(&_66$$62, "phalcon/Mvc/Model.zep", 5159);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&rawValue);
					_68$$61 = zephir_array_isset_fetch(&rawValue, &rawValues, &attributeField, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_68$$61) {
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5167);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&values, &rawValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5168);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5169);
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
						_69$$61 = zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_69$$61) {
							_70$$64 = Z_TYPE_P(&value) == IS_STRING;
							if (_70$$64) {
								_71$$64 = zephir_array_isset_value(&defaultValues, &field);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								_70$$64 = _71$$64;
							}
							_72$$64 = _70$$64;
							if (_72$$64) {
								ZEPHIR_OBS_NVAR(&_73$$64);
								zephir_array_fetch(&_73$$64, &defaultValues, &field, PH_NOISY, "phalcon/Mvc/Model.zep", 5178);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								_72$$64 = ZEPHIR_IS_IDENTICAL(&value, &_73$$64);
							}
							_74$$64 = _72$$64;
							if (_74$$64) {
								_74$$64 = zephir_memnstr_str(&value, SL("("), "phalcon/Mvc/Model.zep", 5178);
							}
							if (_74$$64) {
								zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								continue;
							}
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5184);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5185);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5186);
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
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5190);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&values, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5191);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5192);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _56$$55, "rewind", &_zephir_call_cache[27]);
			zephir_check_call_status();
			_76$$55 = 1;
			while (1) {
				if (_76$$55) {
					_76$$55 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _56$$55, "next", &_zephir_call_cache[28]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_75$$55, _56$$55, "valid", &_zephir_call_cache[29]);
				zephir_check_call_status();
				if (!zend_is_true(&_75$$55)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&field, _56$$55, "current", &_zephir_call_cache[30]);
				zephir_check_call_status();
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						_77$$68 = zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (UNEXPECTED(!(_77$$68))) {
							ZEPHIR_INIT_NVAR(&_79$$69);
							ZVAL_STRING(&_79$$69, "orm.ignore_unknown_columns");
							ZEPHIR_CALL_CE_STATIC_CACHED(&_78$$69, phalcon_support_settings_ce, "get", &_zephir_call_cache[31], &_79$$69);
							zephir_check_call_status();
							if (UNEXPECTED(!zephir_is_true(&_78$$69))) {
								ZEPHIR_INIT_NVAR(&_80$$70);
								object_init_ex(&_80$$70, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
								zephir_constructor_start(&_80$$70);
								ZEPHIR_INIT_NVAR(&_81$$70);
								zephir_get_class(&_81$$70, this_ptr, 0);
								ZEPHIR_CALL_METHOD_CACHED(NULL, &_80$$70, "__construct", &_zephir_call_cache[32], &field, &_81$$70);
								zephir_check_call_status();
								zephir_constructor_finish(&_80$$70);
								zephir_throw_exception_debug(&_80$$70, "phalcon/Mvc/Model.zep", 5147);
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} else {
						ZEPHIR_CPY_WRT(&attributeField, &field);
					}
					_82$$67 = zephir_array_key_exists(&automaticAttributes, &attributeField);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_82$$67)) {
						ZEPHIR_OBS_NVAR(&bindType);
						_83$$72 = zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (UNEXPECTED(!(_83$$72))) {
							ZEPHIR_INIT_NVAR(&_84$$73);
							object_init_ex(&_84$$73, phalcon_mvc_model_exceptions_bindtypenotdefined_ce);
							zephir_constructor_start(&_84$$73);
							ZEPHIR_INIT_NVAR(&_85$$73);
							zephir_get_class(&_85$$73, this_ptr, 0);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_84$$73, "__construct", &_zephir_call_cache[33], &field, &_85$$73);
							zephir_check_call_status();
							zephir_constructor_finish(&_84$$73);
							zephir_throw_exception_debug(&_84$$73, "phalcon/Mvc/Model.zep", 5159);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_OBS_NVAR(&rawValue);
						_86$$72 = zephir_array_isset_fetch(&rawValue, &rawValues, &attributeField, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_86$$72) {
							zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5167);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&values, &rawValue, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5168);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5169);
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
							_87$$72 = zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (_87$$72) {
								_88$$75 = Z_TYPE_P(&value) == IS_STRING;
								if (_88$$75) {
									_89$$75 = zephir_array_isset_value(&defaultValues, &field);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									_88$$75 = _89$$75;
								}
								_90$$75 = _88$$75;
								if (_90$$75) {
									ZEPHIR_OBS_NVAR(&_91$$75);
									zephir_array_fetch(&_91$$75, &defaultValues, &field, PH_NOISY, "phalcon/Mvc/Model.zep", 5178);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									_90$$75 = ZEPHIR_IS_IDENTICAL(&value, &_91$$75);
								}
								_92$$75 = _90$$75;
								if (_92$$75) {
									_92$$75 = zephir_memnstr_str(&value, SL("("), "phalcon/Mvc/Model.zep", 5178);
								}
								if (_92$$75) {
									zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									continue;
								}
								zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5184);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5185);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5186);
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
								zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5190);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&values, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5191);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5192);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
						}
					}
			}
		}
	}
	if (ZEPHIR_IS_EMPTY(&fields)) {
		RETURN_MM_BOOL(1);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_4, 1027, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&uniqueKey, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_5, 1028, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&uniqueParams, &_0);
	if (Z_TYPE_P(&uniqueParams) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD_CACHED(&primaryKeys, metaData, "getPrimaryKeyAttributes", &_zephir_call_cache[34], this_ptr);
		zephir_check_call_status();
		if (UNEXPECTED(ZEPHIR_IS_EMPTY(&primaryKeys))) {
			ZEPHIR_INIT_VAR(&_93$$80);
			object_init_ex(&_93$$80, phalcon_mvc_model_exceptions_primarykeyrequired_ce);
			zephir_constructor_start(&_93$$80);
			ZEPHIR_INIT_VAR(&_94$$80);
			zephir_get_class(&_94$$80, this_ptr, 0);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_93$$80, "__construct", &_zephir_call_cache[35], &_94$$80);
			zephir_check_call_status();
			zephir_constructor_finish(&_93$$80);
			zephir_throw_exception_debug(&_93$$80, "phalcon/Mvc/Model.zep", 5217);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&uniqueParams);
		array_init(&uniqueParams);
		if (Z_TYPE_P(&primaryKeys) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_96$$79);
			zephir_string_to_char_array(&_96$$79, &primaryKeys);
			_95$$79 = &_96$$79;
		} else {
			_95$$79 = &primaryKeys;
		}
		zephir_is_iterable(_95$$79, 0, "phalcon/Mvc/Model.zep", 5242);
		if (Z_TYPE_P(_95$$79) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_95$$79), _97$$79)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _97$$79);
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					_98$$82 = zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_98$$82))) {
						ZEPHIR_INIT_NVAR(&_99$$83);
						object_init_ex(&_99$$83, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
						zephir_constructor_start(&_99$$83);
						ZEPHIR_INIT_NVAR(&_100$$83);
						zephir_get_class(&_100$$83, this_ptr, 0);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_99$$83, "__construct", &_zephir_call_cache[36], &field, &_100$$83);
						zephir_check_call_status();
						zephir_constructor_finish(&_99$$83);
						zephir_throw_exception_debug(&_99$$83, "phalcon/Mvc/Model.zep", 5228);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &field);
				}
				ZEPHIR_OBS_NVAR(&value);
				_101$$81 = zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_101$$81) {
					zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5236);
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
					zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5239);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _95$$79, "rewind", &_zephir_call_cache[37]);
			zephir_check_call_status();
			_103$$79 = 1;
			while (1) {
				if (_103$$79) {
					_103$$79 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _95$$79, "next", &_zephir_call_cache[38]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_102$$79, _95$$79, "valid", &_zephir_call_cache[39]);
				zephir_check_call_status();
				if (!zend_is_true(&_102$$79)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&field, _95$$79, "current", &_zephir_call_cache[40]);
				zephir_check_call_status();
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						_104$$88 = zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (UNEXPECTED(!(_104$$88))) {
							ZEPHIR_INIT_NVAR(&_105$$89);
							object_init_ex(&_105$$89, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
							zephir_constructor_start(&_105$$89);
							ZEPHIR_INIT_NVAR(&_106$$89);
							zephir_get_class(&_106$$89, this_ptr, 0);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_105$$89, "__construct", &_zephir_call_cache[41], &field, &_106$$89);
							zephir_check_call_status();
							zephir_constructor_finish(&_105$$89);
							zephir_throw_exception_debug(&_105$$89, "phalcon/Mvc/Model.zep", 5228);
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_CPY_WRT(&attributeField, &field);
					}
					ZEPHIR_OBS_NVAR(&value);
					_107$$87 = zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_107$$87) {
						zephir_array_update_zval(&newSnapshot, &attributeField, &value, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5236);
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
						zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5239);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
			}
		}
	}
	if (Z_TYPE_P(table) == IS_ARRAY) {
		zephir_memory_observe(&_108$$93);
		zephir_array_fetch_long(&_108$$93, table, 0, PH_NOISY, "phalcon/Mvc/Model.zep", 5248);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&_109$$93);
		zephir_array_fetch_long(&_109$$93, table, 1, PH_NOISY, "phalcon/Mvc/Model.zep", 5248);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_110$$93);
		ZEPHIR_CONCAT_VSV(&_110$$93, &_108$$93, ".", &_109$$93);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(table, &_110$$93);
	}
	ZEPHIR_INIT_VAR(&_111);
	zephir_create_array(&_111, 3, 0);
	zephir_array_update_string(&_111, SL("conditions"), &uniqueKey, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_111, SL("bind"), &uniqueParams, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&_112);
	zephir_read_property_cached(&_112, this_ptr, _zephir_prop_6, 1029, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&_111, SL("bindTypes"), &_112, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD_CACHED(&success, connection, "update", &_zephir_call_cache[42], table, &fields, &values, &_111, &bindTypes);
	zephir_check_call_status();
	if (zephir_is_true(&success)) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &manager, "registerWrite", &_zephir_call_cache[43], this_ptr);
		zephir_check_call_status();
	}
	_113 = zephir_is_true(&success);
	if (_113) {
		ZEPHIR_CALL_METHOD_CACHED(&_114, &manager, "isKeepingSnapshots", &_zephir_call_cache[44], this_ptr);
		zephir_check_call_status();
		_113 = zephir_is_true(&_114);
	}
	_115 = _113;
	if (_115) {
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_STRING(&_2, "orm.update_snapshot_on_save");
		ZEPHIR_CALL_CE_STATIC_CACHED(&_116, phalcon_support_settings_ce, "get", &_zephir_call_cache[45], &_2);
		zephir_check_call_status();
		_115 = zephir_is_true(&_116);
	}
	if (_115) {
		if (Z_TYPE_P(&snapshot) == IS_ARRAY) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1024, &snapshot);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_117$$96);
			zephir_fast_array_merge(&_117$$96, &snapshot, &newSnapshot);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1018, &_117$$96);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_INIT_VAR(&_118$$97);
			array_init(&_118$$97);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1024, &_118$$97);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1018, &newSnapshot);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	if (zephir_start_with_str(&method_zv, SL("get"))) {
		ZVAL_LONG(&_2$$3, 3);
		ZEPHIR_INIT_VAR(&alias);
		zephir_substr(&alias, &method_zv, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_METHOD_CACHED(&_3$$3, &manager, "getRelationByAlias", &_zephir_call_cache[0], &modelName_zv, &alias);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_3$$3);
		if (Z_TYPE_P(&relation) != IS_OBJECT) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getRelated", &_zephir_call_cache[1], &alias, &extraArgs);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_start_with_str(&method_zv, SL("count"))) {
		ZEPHIR_INIT_NVAR(&queryMethod);
		ZVAL_STRING(&queryMethod, "count");
		ZVAL_LONG(&_5$$5, 5);
		ZEPHIR_INIT_VAR(&_6$$5);
		zephir_substr(&_6$$5, &method_zv, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_METHOD_CACHED(&_4$$5, &manager, "getRelationByAlias", &_zephir_call_cache[2], &modelName_zv, &_6$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_4$$5);
		if (Z_TYPE_P(&relation) != IS_OBJECT) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_RETURN_CALL_METHOD_CACHED(&manager, "getRelationRecords", &_zephir_call_cache[3], &relation, this_ptr, &extraArgs, &queryMethod);
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
	zend_bool _16$$3, _5$$8, _8$$7, _10$$7, _9$$11, _17$$16, _20$$15, _22$$15, _21$$19;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberEmpty = 0, numberPrimary = 0;
	zval *metaData, metaData_sub, *connection, connection_sub, __$null, attributeField, bindDataTypes, columnMap, field, joinWhere, num, primaryKeys, schema, source, table, type, uniqueKey, uniqueParams, uniqueTypes, value, wherePk, _0, _30, _31, _32, _33, _1$$3, _2$$3, *_3$$3, *_4$$3, _15$$3, _6$$9, _7$$9, _13$$7, _14$$7, _11$$14, _12$$14, _18$$17, _19$$17, _25$$15, _26$$15, _23$$22, _24$$22, _27$$25, _28$$26, _29$$27, _34$$30, _35$$31;
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
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_11$$14);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_18$$17);
	ZVAL_UNDEF(&_19$$17);
	ZVAL_UNDEF(&_25$$15);
	ZVAL_UNDEF(&_26$$15);
	ZVAL_UNDEF(&_23$$22);
	ZVAL_UNDEF(&_24$$22);
	ZVAL_UNDEF(&_27$$25);
	ZVAL_UNDEF(&_28$$26);
	ZVAL_UNDEF(&_29$$27);
	ZVAL_UNDEF(&_34$$30);
	ZVAL_UNDEF(&_35$$31);
	ZEND_TLS zephir_method_cache _zephir_call_cache[18];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&uniqueKey, &_0);
	if (Z_TYPE_P(&uniqueKey) == IS_NULL) {
		ZEPHIR_CALL_METHOD_CACHED(&primaryKeys, metaData, "getPrimaryKeyAttributes", &_zephir_call_cache[0], this_ptr);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&bindDataTypes, metaData, "getBindTypes", &_zephir_call_cache[1], this_ptr);
		zephir_check_call_status();
		numberPrimary = zephir_fast_count_int(&primaryKeys);
		if (!(numberPrimary)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "orm.column_renaming");
		ZEPHIR_CALL_CE_STATIC_CACHED(&_1$$3, phalcon_support_settings_ce, "get", &_zephir_call_cache[2], &_2$$3);
		zephir_check_call_status();
		if (zephir_is_true(&_1$$3)) {
			ZEPHIR_CALL_METHOD_CACHED(&columnMap, metaData, "getColumnMap", &_zephir_call_cache[3], this_ptr);
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
		zephir_is_iterable(_3$$3, 0, "phalcon/Mvc/Model.zep", 5449);
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
						zephir_constructor_start(&_6$$9);
						ZEPHIR_INIT_NVAR(&_7$$9);
						zephir_get_class(&_7$$9, this_ptr, 0);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_6$$9, "__construct", &_zephir_call_cache[4], &field, &_7$$9);
						zephir_check_call_status();
						zephir_constructor_finish(&_6$$9);
						zephir_throw_exception_debug(&_6$$9, "phalcon/Mvc/Model.zep", 5410);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &field);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_NULL(&value);
				ZEPHIR_OBS_NVAR(&value);
				_8$$7 = zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_8$$7) {
					_9$$11 = Z_TYPE_P(&value) == IS_NULL;
					if (!(_9$$11)) {
						_9$$11 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
					}
					if (_9$$11) {
						numberEmpty++;
					}
					zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5431);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5433);
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
					zephir_constructor_start(&_11$$14);
					ZEPHIR_INIT_NVAR(&_12$$14);
					zephir_get_class(&_12$$14, this_ptr, 0);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_11$$14, "__construct", &_zephir_call_cache[5], &field, &_12$$14);
					zephir_check_call_status();
					zephir_constructor_finish(&_11$$14);
					zephir_throw_exception_debug(&_11$$14, "phalcon/Mvc/Model.zep", 5438);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&uniqueTypes, &type, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5441);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_13$$7, connection, "escapeIdentifier", &_zephir_call_cache[6], &field);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_14$$7);
				ZEPHIR_CONCAT_VS(&_14$$7, &_13$$7, " = ?");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&wherePk, &_14$$7, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5442);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _3$$3, "rewind", &_zephir_call_cache[7]);
			zephir_check_call_status();
			_16$$3 = 1;
			while (1) {
				if (_16$$3) {
					_16$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _3$$3, "next", &_zephir_call_cache[8]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_15$$3, _3$$3, "valid", &_zephir_call_cache[9]);
				zephir_check_call_status();
				if (!zend_is_true(&_15$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&field, _3$$3, "current", &_zephir_call_cache[10]);
				zephir_check_call_status();
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						_17$$16 = zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (UNEXPECTED(!(_17$$16))) {
							ZEPHIR_INIT_NVAR(&_18$$17);
							object_init_ex(&_18$$17, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
							zephir_constructor_start(&_18$$17);
							ZEPHIR_INIT_NVAR(&_19$$17);
							zephir_get_class(&_19$$17, this_ptr, 0);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_18$$17, "__construct", &_zephir_call_cache[11], &field, &_19$$17);
							zephir_check_call_status();
							zephir_constructor_finish(&_18$$17);
							zephir_throw_exception_debug(&_18$$17, "phalcon/Mvc/Model.zep", 5410);
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_CPY_WRT(&attributeField, &field);
					}
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_NULL(&value);
					ZEPHIR_OBS_NVAR(&value);
					_20$$15 = zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_20$$15) {
						_21$$19 = Z_TYPE_P(&value) == IS_NULL;
						if (!(_21$$19)) {
							_21$$19 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
						}
						if (_21$$19) {
							numberEmpty++;
						}
						zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5431);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5433);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						numberEmpty++;
					}
					ZEPHIR_OBS_NVAR(&type);
					_22$$15 = zephir_array_isset_fetch(&type, &bindDataTypes, &field, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_22$$15))) {
						ZEPHIR_INIT_NVAR(&_23$$22);
						object_init_ex(&_23$$22, phalcon_mvc_model_exceptions_columnnotintablecolumns_ce);
						zephir_constructor_start(&_23$$22);
						ZEPHIR_INIT_NVAR(&_24$$22);
						zephir_get_class(&_24$$22, this_ptr, 0);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_23$$22, "__construct", &_zephir_call_cache[12], &field, &_24$$22);
						zephir_check_call_status();
						zephir_constructor_finish(&_23$$22);
						zephir_throw_exception_debug(&_23$$22, "phalcon/Mvc/Model.zep", 5438);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&uniqueTypes, &type, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5441);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(&_25$$15, connection, "escapeIdentifier", &_zephir_call_cache[13], &field);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_26$$15);
					ZEPHIR_CONCAT_VS(&_26$$15, &_25$$15, " = ?");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&wherePk, &_26$$15, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5442);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		if (numberPrimary == numberEmpty) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(&joinWhere);
		zephir_fast_join_str(&joinWhere, SL(" AND "), &wherePk);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1027, &joinWhere);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1028, &uniqueParams);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1029, &uniqueTypes);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&uniqueKey, &joinWhere);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_3, 1017, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_BOOL(1);
	}
	if (Z_TYPE_P(&uniqueKey) == IS_NULL) {
		zephir_read_property_cached(&_27$$25, this_ptr, _zephir_prop_0, 1027, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&uniqueKey, &_27$$25);
	}
	if (Z_TYPE_P(&uniqueParams) == IS_NULL) {
		zephir_read_property_cached(&_28$$26, this_ptr, _zephir_prop_1, 1028, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&uniqueParams, &_28$$26);
	}
	if (Z_TYPE_P(&uniqueTypes) == IS_NULL) {
		zephir_read_property_cached(&_29$$27, this_ptr, _zephir_prop_2, 1029, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&uniqueTypes, &_29$$27);
	}
	ZEPHIR_CALL_METHOD_CACHED(&schema, this_ptr, "getSchema", &_zephir_call_cache[14]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&source, this_ptr, "getSource", &_zephir_call_cache[15]);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	ZEPHIR_CALL_METHOD_CACHED(&_30, connection, "escapeIdentifier", &_zephir_call_cache[16], &table);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_31);
	ZEPHIR_CONCAT_SVSV(&_31, "SELECT COUNT(*) \"rowcount\" FROM ", &_30, " WHERE ", &uniqueKey);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZVAL_NULL(&_32);
	ZEPHIR_CALL_METHOD_CACHED(&num, connection, "fetchOne", &_zephir_call_cache[17], &_31, &_32, &uniqueParams, &uniqueTypes);
	zephir_check_call_status();
	zephir_memory_observe(&_33);
	zephir_array_fetch_string(&_33, &num, SL("rowcount"), PH_NOISY, "phalcon/Mvc/Model.zep", 5503);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_is_true(&_33)) {
		ZVAL_UNDEF(&_34$$30);
		ZVAL_LONG(&_34$$30, 0);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1017, &_34$$30);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_BOOL(1);
	} else {
		ZVAL_UNDEF(&_35$$31);
		ZVAL_LONG(&_35$$31, 1);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1017, &_35$$31);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_0, "addHasMany", &_zephir_call_cache[0], this_ptr, fields, &referenceModel_zv, referencedFields, &options);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_0, "addHasManyToMany", &_zephir_call_cache[0], this_ptr, fields, &intermediateModel_zv, intermediateFields, intermediateReferencedFields, &referenceModel_zv, referencedFields, &options);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_0, "addHasOne", &_zephir_call_cache[0], this_ptr, fields, &referenceModel_zv, referencedFields, &options);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_0, "addHasOneThrough", &_zephir_call_cache[0], this_ptr, fields, &intermediateModel_zv, intermediateFields, intermediateReferencedFields, &referenceModel_zv, referencedFields, &options);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (keepSnapshot) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "keepSnapshots", &_zephir_call_cache[0], this_ptr, &_1);
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
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *success_param = NULL, *exists_param = NULL, _0$$4, _1$$5;
	zend_bool success, exists;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
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
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "fireEvent", &_zephir_call_cache[0], &_0$$4);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_1$$5);
			ZVAL_STRING(&_1$$5, "afterCreate");
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "fireEvent", &_zephir_call_cache[1], &_1$$5);
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
	zval _24$$13, _40$$19, _45$$20, _73$$34, _86$$39, _91$$40, _119$$54, _136$$60, _153$$66, _208$$93, _224$$99, _229$$100, _257$$114, _270$$119, _275$$120, _303$$134, _320$$140, _337$$146;
	zend_string *_5;
	zend_ulong _4;
	zval conditions, placeholders, loopConditions, loopPlaceholders, keptKeys, _48$$15, _94$$35, _122$$55, _232$$95, _278$$115, _306$$135;
	zend_bool nesting = 0, isThrough = 0, doSync = 0, _188, _8$$4, _14$$9, _16$$9, _75$$9, _120$$9, _17$$12, _50$$15, _33$$18, _51$$23, _56$$26, _69$$31, _96$$35, _79$$38, _97$$43, _102$$46, _115$$51, _142$$55, _132$$57, _137$$56, _138$$56, _149$$63, _154$$62, _155$$62, _168$$69, _161$$70, _169$$73, _182$$76, _191$$84, _198$$89, _200$$89, _259$$89, _304$$89, _201$$92, _234$$95, _217$$98, _235$$103, _240$$106, _253$$111, _280$$115, _263$$118, _281$$123, _286$$126, _299$$131, _326$$135, _316$$137, _321$$136, _322$$136, _333$$143, _338$$142, _339$$142, _352$$149, _345$$150, _353$$153, _366$$156;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, referencedFieldsCount = 0, i = 0, j = 0, t = 0, h = 0, columnCount, _18$$12, _19$$12, _34$$18, _35$$18, _52$$23, _53$$23, _57$$26, _58$$26, _80$$38, _81$$38, _98$$43, _99$$43, _103$$46, _104$$46, _162$$70, _163$$70, _170$$73, _171$$73, _202$$92, _203$$92, _218$$98, _219$$98, _236$$103, _237$$103, _241$$106, _242$$106, _264$$118, _265$$118, _282$$123, _283$$123, _287$$126, _288$$126, _346$$150, _347$$150, _354$$153, _355$$153;
	zval *connection, connection_sub, *related, related_sub, *visited, visited_sub, __$true, className, manager, relation, name, record, columns, referencedModel, referencedFields, relatedRecords, recordAfter, intermediateModel, intermediateFields, intermediateModelName, intermediateReferencedFields, existingIntermediateModel, columnA, columnB, existingRecords, existingRecord, keepKey, override, _0, *_1, _2, *_3, _187, _371, _6$$3, _7$$4, _10$$4, _9$$6, _11$$9, _12$$9, _13$$9, _15$$9, *_28$$9, *_29$$9, _74$$9, _20$$13, _21$$13, _22$$13, _23$$13, _25$$13, _26$$14, _27$$14, _30$$15, _32$$15, _47$$15, _49$$15, _61$$15, _31$$16, _36$$19, _37$$19, _38$$19, _39$$19, _41$$19, _42$$20, _43$$20, _44$$20, _46$$20, _54$$24, _55$$25, _59$$27, _60$$28, _62$$29, *_63$$31, _64$$31, *_65$$31, _68$$31, _66$$32, _67$$32, _70$$33, _71$$33, _72$$34, _76$$35, _78$$35, _93$$35, _95$$35, _107$$35, _77$$36, _82$$39, _83$$39, _84$$39, _85$$39, _87$$39, _88$$40, _89$$40, _90$$40, _92$$40, _100$$44, _101$$45, _105$$47, _106$$48, _108$$49, *_109$$51, _110$$51, *_111$$51, _114$$51, _112$$52, _113$$52, _116$$53, _117$$53, _118$$54, _121$$55, _123$$55, *_124$$55, *_125$$55, _141$$55, *_126$$57, _127$$57, *_128$$57, _131$$57, _129$$58, _130$$58, _133$$59, _134$$59, _135$$60, _139$$56, _140$$61, *_143$$63, _144$$63, *_145$$63, _148$$63, _146$$64, _147$$64, _150$$65, _151$$65, _152$$66, _156$$62, _157$$67, *_158$$69, _159$$69, *_160$$69, _167$$69, _165$$70, _164$$71, _166$$72, _173$$73, _172$$74, _174$$75, *_175$$76, _176$$76, *_177$$76, _181$$76, _178$$77, _179$$77, _180$$78, _183$$79, _184$$79, _185$$80, _186$$82, _189$$83, _190$$84, _194$$84, _192$$86, _193$$87, _195$$89, _196$$89, _197$$89, _199$$89, *_212$$89, *_213$$89, _258$$89, _204$$93, _205$$93, _206$$93, _207$$93, _209$$93, _210$$94, _211$$94, _214$$95, _216$$95, _231$$95, _233$$95, _245$$95, _215$$96, _220$$99, _221$$99, _222$$99, _223$$99, _225$$99, _226$$100, _227$$100, _228$$100, _230$$100, _238$$104, _239$$105, _243$$107, _244$$108, _246$$109, *_247$$111, _248$$111, *_249$$111, _252$$111, _250$$112, _251$$112, _254$$113, _255$$113, _256$$114, _260$$115, _262$$115, _277$$115, _279$$115, _291$$115, _261$$116, _266$$119, _267$$119, _268$$119, _269$$119, _271$$119, _272$$120, _273$$120, _274$$120, _276$$120, _284$$124, _285$$125, _289$$127, _290$$128, _292$$129, *_293$$131, _294$$131, *_295$$131, _298$$131, _296$$132, _297$$132, _300$$133, _301$$133, _302$$134, _305$$135, _307$$135, *_308$$135, *_309$$135, _325$$135, *_310$$137, _311$$137, *_312$$137, _315$$137, _313$$138, _314$$138, _317$$139, _318$$139, _319$$140, _323$$136, _324$$141, *_327$$143, _328$$143, *_329$$143, _332$$143, _330$$144, _331$$144, _334$$145, _335$$145, _336$$146, _340$$142, _341$$147, *_342$$149, _343$$149, *_344$$149, _351$$149, _349$$150, _348$$151, _350$$152, _357$$153, _356$$154, _358$$155, *_359$$156, _360$$156, *_361$$156, _365$$156, _362$$157, _363$$157, _364$$158, _367$$159, _368$$159, _369$$160, _370$$162;
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
	ZVAL_UNDEF(&_187);
	ZVAL_UNDEF(&_371);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_74$$9);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_27$$14);
	ZVAL_UNDEF(&_30$$15);
	ZVAL_UNDEF(&_32$$15);
	ZVAL_UNDEF(&_47$$15);
	ZVAL_UNDEF(&_49$$15);
	ZVAL_UNDEF(&_61$$15);
	ZVAL_UNDEF(&_31$$16);
	ZVAL_UNDEF(&_36$$19);
	ZVAL_UNDEF(&_37$$19);
	ZVAL_UNDEF(&_38$$19);
	ZVAL_UNDEF(&_39$$19);
	ZVAL_UNDEF(&_41$$19);
	ZVAL_UNDEF(&_42$$20);
	ZVAL_UNDEF(&_43$$20);
	ZVAL_UNDEF(&_44$$20);
	ZVAL_UNDEF(&_46$$20);
	ZVAL_UNDEF(&_54$$24);
	ZVAL_UNDEF(&_55$$25);
	ZVAL_UNDEF(&_59$$27);
	ZVAL_UNDEF(&_60$$28);
	ZVAL_UNDEF(&_62$$29);
	ZVAL_UNDEF(&_64$$31);
	ZVAL_UNDEF(&_68$$31);
	ZVAL_UNDEF(&_66$$32);
	ZVAL_UNDEF(&_67$$32);
	ZVAL_UNDEF(&_70$$33);
	ZVAL_UNDEF(&_71$$33);
	ZVAL_UNDEF(&_72$$34);
	ZVAL_UNDEF(&_76$$35);
	ZVAL_UNDEF(&_78$$35);
	ZVAL_UNDEF(&_93$$35);
	ZVAL_UNDEF(&_95$$35);
	ZVAL_UNDEF(&_107$$35);
	ZVAL_UNDEF(&_77$$36);
	ZVAL_UNDEF(&_82$$39);
	ZVAL_UNDEF(&_83$$39);
	ZVAL_UNDEF(&_84$$39);
	ZVAL_UNDEF(&_85$$39);
	ZVAL_UNDEF(&_87$$39);
	ZVAL_UNDEF(&_88$$40);
	ZVAL_UNDEF(&_89$$40);
	ZVAL_UNDEF(&_90$$40);
	ZVAL_UNDEF(&_92$$40);
	ZVAL_UNDEF(&_100$$44);
	ZVAL_UNDEF(&_101$$45);
	ZVAL_UNDEF(&_105$$47);
	ZVAL_UNDEF(&_106$$48);
	ZVAL_UNDEF(&_108$$49);
	ZVAL_UNDEF(&_110$$51);
	ZVAL_UNDEF(&_114$$51);
	ZVAL_UNDEF(&_112$$52);
	ZVAL_UNDEF(&_113$$52);
	ZVAL_UNDEF(&_116$$53);
	ZVAL_UNDEF(&_117$$53);
	ZVAL_UNDEF(&_118$$54);
	ZVAL_UNDEF(&_121$$55);
	ZVAL_UNDEF(&_123$$55);
	ZVAL_UNDEF(&_141$$55);
	ZVAL_UNDEF(&_127$$57);
	ZVAL_UNDEF(&_131$$57);
	ZVAL_UNDEF(&_129$$58);
	ZVAL_UNDEF(&_130$$58);
	ZVAL_UNDEF(&_133$$59);
	ZVAL_UNDEF(&_134$$59);
	ZVAL_UNDEF(&_135$$60);
	ZVAL_UNDEF(&_139$$56);
	ZVAL_UNDEF(&_140$$61);
	ZVAL_UNDEF(&_144$$63);
	ZVAL_UNDEF(&_148$$63);
	ZVAL_UNDEF(&_146$$64);
	ZVAL_UNDEF(&_147$$64);
	ZVAL_UNDEF(&_150$$65);
	ZVAL_UNDEF(&_151$$65);
	ZVAL_UNDEF(&_152$$66);
	ZVAL_UNDEF(&_156$$62);
	ZVAL_UNDEF(&_157$$67);
	ZVAL_UNDEF(&_159$$69);
	ZVAL_UNDEF(&_167$$69);
	ZVAL_UNDEF(&_165$$70);
	ZVAL_UNDEF(&_164$$71);
	ZVAL_UNDEF(&_166$$72);
	ZVAL_UNDEF(&_173$$73);
	ZVAL_UNDEF(&_172$$74);
	ZVAL_UNDEF(&_174$$75);
	ZVAL_UNDEF(&_176$$76);
	ZVAL_UNDEF(&_181$$76);
	ZVAL_UNDEF(&_178$$77);
	ZVAL_UNDEF(&_179$$77);
	ZVAL_UNDEF(&_180$$78);
	ZVAL_UNDEF(&_183$$79);
	ZVAL_UNDEF(&_184$$79);
	ZVAL_UNDEF(&_185$$80);
	ZVAL_UNDEF(&_186$$82);
	ZVAL_UNDEF(&_189$$83);
	ZVAL_UNDEF(&_190$$84);
	ZVAL_UNDEF(&_194$$84);
	ZVAL_UNDEF(&_192$$86);
	ZVAL_UNDEF(&_193$$87);
	ZVAL_UNDEF(&_195$$89);
	ZVAL_UNDEF(&_196$$89);
	ZVAL_UNDEF(&_197$$89);
	ZVAL_UNDEF(&_199$$89);
	ZVAL_UNDEF(&_258$$89);
	ZVAL_UNDEF(&_204$$93);
	ZVAL_UNDEF(&_205$$93);
	ZVAL_UNDEF(&_206$$93);
	ZVAL_UNDEF(&_207$$93);
	ZVAL_UNDEF(&_209$$93);
	ZVAL_UNDEF(&_210$$94);
	ZVAL_UNDEF(&_211$$94);
	ZVAL_UNDEF(&_214$$95);
	ZVAL_UNDEF(&_216$$95);
	ZVAL_UNDEF(&_231$$95);
	ZVAL_UNDEF(&_233$$95);
	ZVAL_UNDEF(&_245$$95);
	ZVAL_UNDEF(&_215$$96);
	ZVAL_UNDEF(&_220$$99);
	ZVAL_UNDEF(&_221$$99);
	ZVAL_UNDEF(&_222$$99);
	ZVAL_UNDEF(&_223$$99);
	ZVAL_UNDEF(&_225$$99);
	ZVAL_UNDEF(&_226$$100);
	ZVAL_UNDEF(&_227$$100);
	ZVAL_UNDEF(&_228$$100);
	ZVAL_UNDEF(&_230$$100);
	ZVAL_UNDEF(&_238$$104);
	ZVAL_UNDEF(&_239$$105);
	ZVAL_UNDEF(&_243$$107);
	ZVAL_UNDEF(&_244$$108);
	ZVAL_UNDEF(&_246$$109);
	ZVAL_UNDEF(&_248$$111);
	ZVAL_UNDEF(&_252$$111);
	ZVAL_UNDEF(&_250$$112);
	ZVAL_UNDEF(&_251$$112);
	ZVAL_UNDEF(&_254$$113);
	ZVAL_UNDEF(&_255$$113);
	ZVAL_UNDEF(&_256$$114);
	ZVAL_UNDEF(&_260$$115);
	ZVAL_UNDEF(&_262$$115);
	ZVAL_UNDEF(&_277$$115);
	ZVAL_UNDEF(&_279$$115);
	ZVAL_UNDEF(&_291$$115);
	ZVAL_UNDEF(&_261$$116);
	ZVAL_UNDEF(&_266$$119);
	ZVAL_UNDEF(&_267$$119);
	ZVAL_UNDEF(&_268$$119);
	ZVAL_UNDEF(&_269$$119);
	ZVAL_UNDEF(&_271$$119);
	ZVAL_UNDEF(&_272$$120);
	ZVAL_UNDEF(&_273$$120);
	ZVAL_UNDEF(&_274$$120);
	ZVAL_UNDEF(&_276$$120);
	ZVAL_UNDEF(&_284$$124);
	ZVAL_UNDEF(&_285$$125);
	ZVAL_UNDEF(&_289$$127);
	ZVAL_UNDEF(&_290$$128);
	ZVAL_UNDEF(&_292$$129);
	ZVAL_UNDEF(&_294$$131);
	ZVAL_UNDEF(&_298$$131);
	ZVAL_UNDEF(&_296$$132);
	ZVAL_UNDEF(&_297$$132);
	ZVAL_UNDEF(&_300$$133);
	ZVAL_UNDEF(&_301$$133);
	ZVAL_UNDEF(&_302$$134);
	ZVAL_UNDEF(&_305$$135);
	ZVAL_UNDEF(&_307$$135);
	ZVAL_UNDEF(&_325$$135);
	ZVAL_UNDEF(&_311$$137);
	ZVAL_UNDEF(&_315$$137);
	ZVAL_UNDEF(&_313$$138);
	ZVAL_UNDEF(&_314$$138);
	ZVAL_UNDEF(&_317$$139);
	ZVAL_UNDEF(&_318$$139);
	ZVAL_UNDEF(&_319$$140);
	ZVAL_UNDEF(&_323$$136);
	ZVAL_UNDEF(&_324$$141);
	ZVAL_UNDEF(&_328$$143);
	ZVAL_UNDEF(&_332$$143);
	ZVAL_UNDEF(&_330$$144);
	ZVAL_UNDEF(&_331$$144);
	ZVAL_UNDEF(&_334$$145);
	ZVAL_UNDEF(&_335$$145);
	ZVAL_UNDEF(&_336$$146);
	ZVAL_UNDEF(&_340$$142);
	ZVAL_UNDEF(&_341$$147);
	ZVAL_UNDEF(&_343$$149);
	ZVAL_UNDEF(&_351$$149);
	ZVAL_UNDEF(&_349$$150);
	ZVAL_UNDEF(&_348$$151);
	ZVAL_UNDEF(&_350$$152);
	ZVAL_UNDEF(&_357$$153);
	ZVAL_UNDEF(&_356$$154);
	ZVAL_UNDEF(&_358$$155);
	ZVAL_UNDEF(&_360$$156);
	ZVAL_UNDEF(&_365$$156);
	ZVAL_UNDEF(&_362$$157);
	ZVAL_UNDEF(&_363$$157);
	ZVAL_UNDEF(&_364$$158);
	ZVAL_UNDEF(&_367$$159);
	ZVAL_UNDEF(&_368$$159);
	ZVAL_UNDEF(&_369$$160);
	ZVAL_UNDEF(&_370$$162);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&placeholders);
	ZVAL_UNDEF(&loopConditions);
	ZVAL_UNDEF(&loopPlaceholders);
	ZVAL_UNDEF(&keptKeys);
	ZVAL_UNDEF(&_48$$15);
	ZVAL_UNDEF(&_94$$35);
	ZVAL_UNDEF(&_122$$55);
	ZVAL_UNDEF(&_232$$95);
	ZVAL_UNDEF(&_278$$115);
	ZVAL_UNDEF(&_306$$135);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_40$$19);
	ZVAL_UNDEF(&_45$$20);
	ZVAL_UNDEF(&_73$$34);
	ZVAL_UNDEF(&_86$$39);
	ZVAL_UNDEF(&_91$$40);
	ZVAL_UNDEF(&_119$$54);
	ZVAL_UNDEF(&_136$$60);
	ZVAL_UNDEF(&_153$$66);
	ZVAL_UNDEF(&_208$$93);
	ZVAL_UNDEF(&_224$$99);
	ZVAL_UNDEF(&_229$$100);
	ZVAL_UNDEF(&_257$$114);
	ZVAL_UNDEF(&_270$$119);
	ZVAL_UNDEF(&_275$$120);
	ZVAL_UNDEF(&_303$$134);
	ZVAL_UNDEF(&_320$$140);
	ZVAL_UNDEF(&_337$$146);
	ZEND_TLS zephir_method_cache _zephir_call_cache[177];
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
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getModelsManager", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_0);
	if (Z_TYPE_P(related) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, related);
		_1 = &_2;
	} else {
		_1 = related;
	}
	zephir_is_iterable(_1, 0, "phalcon/Mvc/Model.zep", 6166);
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
			ZEPHIR_CALL_METHOD_CACHED(&_6$$3, &manager, "getRelationByAlias", &_zephir_call_cache[1], &className, &name);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&relation, &_6$$3);
			if (Z_TYPE_P(&relation) == IS_OBJECT) {
				ZEPHIR_CALL_METHOD_CACHED(&_7$$4, &relation, "getType", &_zephir_call_cache[2]);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(&_7$$4, 0)) {
					continue;
				}
				_8$$4 = Z_TYPE_P(&record) != IS_OBJECT;
				if (_8$$4) {
					_8$$4 = Z_TYPE_P(&record) != IS_ARRAY;
				}
				if (UNEXPECTED(_8$$4)) {
					ZEPHIR_INIT_NVAR(&_9$$6);
					object_init_ex(&_9$$6, phalcon_mvc_model_exceptions_relationrequiresobjectorarray_ce);
					zephir_constructor_start(&_9$$6);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_9$$6, "__construct", &_zephir_call_cache[3], &className, &name);
					zephir_check_call_status();
					zephir_constructor_finish(&_9$$6);
					zephir_throw_exception_debug(&_9$$6, "phalcon/Mvc/Model.zep", 5885);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&columns, &relation, "getFields", &_zephir_call_cache[4]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&referencedModel, &relation, "getReferencedModel", &_zephir_call_cache[5]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&referencedFields, &relation, "getReferencedFields", &_zephir_call_cache[6]);
				zephir_check_call_status();
				if (Z_TYPE_P(&record) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&relatedRecords);
					zephir_create_array(&relatedRecords, 1, 0);
					zephir_array_fast_append(&relatedRecords, &record);
				} else {
					ZEPHIR_CPY_WRT(&relatedRecords, &record);
				}
				ZEPHIR_CALL_METHOD_CACHED(&_10$$4, &relation, "isThrough", &_zephir_call_cache[7]);
				zephir_check_call_status();
				isThrough = zephir_get_boolval(&_10$$4);
				if (isThrough) {
					ZEPHIR_CALL_METHOD_CACHED(&intermediateModelName, &relation, "getIntermediateModel", &_zephir_call_cache[8]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&intermediateFields, &relation, "getIntermediateFields", &_zephir_call_cache[9]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&intermediateReferencedFields, &relation, "getIntermediateReferencedFields", &_zephir_call_cache[10]);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&placeholders);
					array_init(&placeholders);
					ZEPHIR_INIT_NVAR(&conditions);
					array_init(&conditions);
					ZEPHIR_INIT_NVAR(&keptKeys);
					array_init(&keptKeys);
					ZEPHIR_INIT_NVAR(&_12$$9);
					ZVAL_STRING(&_12$$9, "sync");
					ZEPHIR_CALL_METHOD_CACHED(&_11$$9, &relation, "getOption", &_zephir_call_cache[11], &_12$$9);
					zephir_check_call_status();
					doSync = zephir_get_boolval(&_11$$9);
					ZEPHIR_OBS_NVAR(&override);
					zephir_read_property_cached(&_13$$9, this_ptr, _zephir_prop_0, 1023, PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_14$$9 = zephir_array_isset_fetch(&override, &_13$$9, &name, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_14$$9) {
						doSync = zephir_get_boolval(&override);
					} else {
						ZEPHIR_OBS_NVAR(&override);
						zephir_read_property_cached(&_15$$9, this_ptr, _zephir_prop_0, 1023, PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_16$$9 = zephir_array_isset_string_fetch(&override, &_15$$9, SL("*"), 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_16$$9) {
							doSync = zephir_get_boolval(&override);
						}
					}
					if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
						columnCount = (zephir_fast_count_int(&columns) - 1);
						_19$$12 = columnCount;
						_18$$12 = 0;
						_17$$12 = 0;
						if (_18$$12 <= _19$$12) {
							while (1) {
								if (_17$$12) {
									_18$$12++;
									if (!(_18$$12 <= _19$$12)) {
										break;
									}
								} else {
									_17$$12 = 1;
								}
								i = _18$$12;
								ZEPHIR_OBS_NVAR(&columnA);
								zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5932);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&_20$$13);
								zephir_array_fetch_long(&_20$$13, &intermediateFields, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5933);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_INIT_NVAR(&_21$$13);
								ZVAL_LONG(&_21$$13, i);
								ZEPHIR_INIT_NVAR(&_22$$13);
								ZEPHIR_CONCAT_SVSVS(&_22$$13, "[", &_20$$13, "] = :APR", &_21$$13, ":");
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&conditions, &_22$$13, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5933);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_INIT_NVAR(&_23$$13);
								ZVAL_LONG(&_23$$13, i);
								ZEPHIR_INIT_NVAR(&_24$$13);
								ZEPHIR_CONCAT_SV(&_24$$13, "APR", &_23$$13);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&_25$$13);
								zephir_read_property_zval(&_25$$13, this_ptr, &columnA, PH_NOISY_CC);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_zval(&placeholders, &_24$$13, &_25$$13, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
						}
						i = (columnCount + 1);
					} else {
						ZEPHIR_INIT_NVAR(&_26$$14);
						ZEPHIR_CONCAT_SVS(&_26$$14, "[", &intermediateFields, "] = :APR0:");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&conditions, &_26$$14, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5938);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_OBS_NVAR(&_27$$14);
						zephir_read_property_zval(&_27$$14, this_ptr, &columns, PH_NOISY_CC);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_string(&placeholders, SL("APR0"), &_27$$14, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						i = 1;
					}
					if (Z_TYPE_P(&relatedRecords) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_12$$9);
						zephir_string_to_char_array(&_12$$9, &relatedRecords);
						_28$$9 = &_12$$9;
					} else {
						_28$$9 = &relatedRecords;
					}
					zephir_is_iterable(_28$$9, 0, "phalcon/Mvc/Model.zep", 6068);
					if (Z_TYPE_P(_28$$9) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_28$$9), _29$$9)
						{
							ZEPHIR_INIT_NVAR(&recordAfter);
							ZVAL_COPY(&recordAfter, _29$$9);
							ZEPHIR_CALL_METHOD_CACHED(&_30$$15, &recordAfter, "doSave", &_zephir_call_cache[12], visited);
							zephir_check_call_status();
							if (!(zephir_is_true(&_30$$15))) {
								ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessagesFrom", &_zephir_call_cache[13], &recordAfter);
								zephir_check_call_status();
								if (nesting) {
									ZVAL_BOOL(&_31$$16, 1);
								} else {
									ZVAL_BOOL(&_31$$16, 0);
								}
								ZEPHIR_CALL_METHOD_CACHED(NULL, connection, "rollback", &_zephir_call_cache[14], &_31$$16);
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
							ZEPHIR_CALL_METHOD_CACHED(&_32$$15, &relation, "getType", &_zephir_call_cache[15]);
							zephir_check_call_status();
							if (ZEPHIR_IS_LONG_IDENTICAL(&_32$$15, 4)) {
								if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
									referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
									_35$$18 = referencedFieldsCount;
									_34$$18 = 0;
									_33$$18 = 0;
									if (_34$$18 <= _35$$18) {
										while (1) {
											if (_33$$18) {
												_34$$18++;
												if (!(_34$$18 <= _35$$18)) {
													break;
												}
											} else {
												_33$$18 = 1;
											}
											j = _34$$18;
											ZEPHIR_OBS_NVAR(&columnA);
											zephir_array_fetch_long(&columnA, &referencedFields, j, PH_NOISY, "phalcon/Mvc/Model.zep", 5973);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											t = (j + i);
											ZEPHIR_OBS_NVAR(&_36$$19);
											zephir_array_fetch_long(&_36$$19, &intermediateReferencedFields, j, PH_NOISY, "phalcon/Mvc/Model.zep", 5975);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_INIT_NVAR(&_37$$19);
											ZVAL_LONG(&_37$$19, t);
											ZEPHIR_INIT_NVAR(&_38$$19);
											ZEPHIR_CONCAT_SVSVS(&_38$$19, "[", &_36$$19, "] = :APR", &_37$$19, ":");
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_append(&loopConditions, &_38$$19, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5975);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_INIT_NVAR(&_39$$19);
											ZVAL_LONG(&_39$$19, t);
											ZEPHIR_INIT_NVAR(&_40$$19);
											ZEPHIR_CONCAT_SV(&_40$$19, "APR", &_39$$19);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_OBS_NVAR(&_41$$19);
											zephir_read_property_zval(&_41$$19, &recordAfter, &columnA, PH_NOISY_CC);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_update_zval(&loopPlaceholders, &_40$$19, &_41$$19, PH_COPY | PH_SEPARATE);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
										}
									}
								} else {
									ZEPHIR_INIT_NVAR(&_42$$20);
									ZVAL_LONG(&_42$$20, i);
									ZEPHIR_INIT_NVAR(&_43$$20);
									ZEPHIR_CONCAT_SVSVS(&_43$$20, "[", &intermediateReferencedFields, "] = :APR", &_42$$20, ":");
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&loopConditions, &_43$$20, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5979);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_INIT_NVAR(&_44$$20);
									ZVAL_LONG(&_44$$20, i);
									ZEPHIR_INIT_NVAR(&_45$$20);
									ZEPHIR_CONCAT_SV(&_45$$20, "APR", &_44$$20);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_OBS_NVAR(&_46$$20);
									zephir_read_property_zval(&_46$$20, &recordAfter, &referencedFields, PH_NOISY_CC);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_update_zval(&loopPlaceholders, &_45$$20, &_46$$20, PH_COPY | PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
							}
							ZEPHIR_CALL_METHOD_CACHED(&_47$$15, &manager, "load", &_zephir_call_cache[16], &intermediateModelName);
							zephir_check_call_status();
							ZEPHIR_CPY_WRT(&intermediateModel, &_47$$15);
							ZEPHIR_INIT_NVAR(&_48$$15);
							zephir_create_array(&_48$$15, 2, 0);
							ZEPHIR_INIT_NVAR(&_49$$15);
							zephir_fast_join_str(&_49$$15, SL(" AND "), &loopConditions);
							zephir_array_fast_append(&_48$$15, &_49$$15);
							zephir_array_update_string(&_48$$15, SL("bind"), &loopPlaceholders, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD_CACHED(&existingIntermediateModel, &intermediateModel, "findFirst", &_zephir_call_cache[17], &_48$$15);
							zephir_check_call_status();
							if (zephir_is_true(&existingIntermediateModel)) {
								ZEPHIR_CPY_WRT(&intermediateModel, &existingIntermediateModel);
							}
							_50$$15 = !zephir_is_true(&existingIntermediateModel);
							if (!(_50$$15)) {
								ZEPHIR_CALL_METHOD_CACHED(&_47$$15, &relation, "getType", &_zephir_call_cache[18]);
								zephir_check_call_status();
								_50$$15 = ZEPHIR_IS_LONG_IDENTICAL(&_47$$15, 3);
							}
							if (_50$$15) {
								if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
									_53$$23 = columnCount;
									_52$$23 = 0;
									_51$$23 = 0;
									if (_52$$23 <= _53$$23) {
										while (1) {
											if (_51$$23) {
												_52$$23++;
												if (!(_52$$23 <= _53$$23)) {
													break;
												}
											} else {
												_51$$23 = 1;
											}
											h = _52$$23;
											ZEPHIR_OBS_NVAR(&columnA);
											zephir_array_fetch_long(&columnA, &columns, h, PH_NOISY, "phalcon/Mvc/Model.zep", 6010);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_OBS_NVAR(&columnB);
											zephir_array_fetch_long(&columnB, &intermediateFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 6011);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_OBS_NVAR(&_54$$24);
											zephir_read_property_zval(&_54$$24, this_ptr, &columnA, PH_NOISY_CC);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_update_property_zval_zval(&intermediateModel, &columnB, &_54$$24);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
										}
									}
								} else {
									ZEPHIR_OBS_NVAR(&_55$$25);
									zephir_read_property_zval(&_55$$25, this_ptr, &columns, PH_NOISY_CC);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_update_property_zval_zval(&intermediateModel, &intermediateFields, &_55$$25);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
								if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
									referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
									_58$$26 = referencedFieldsCount;
									_57$$26 = 0;
									_56$$26 = 0;
									if (_57$$26 <= _58$$26) {
										while (1) {
											if (_56$$26) {
												_57$$26++;
												if (!(_57$$26 <= _58$$26)) {
													break;
												}
											} else {
												_56$$26 = 1;
											}
											h = _57$$26;
											ZEPHIR_OBS_NVAR(&columnA);
											zephir_array_fetch_long(&columnA, &referencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 6020);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_OBS_NVAR(&columnB);
											zephir_array_fetch_long(&columnB, &intermediateReferencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 6021);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_OBS_NVAR(&_59$$27);
											zephir_read_property_zval(&_59$$27, &recordAfter, &columnA, PH_NOISY_CC);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_update_property_zval_zval(&intermediateModel, &columnB, &_59$$27);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
										}
									}
								} else {
									ZEPHIR_OBS_NVAR(&_60$$28);
									zephir_read_property_zval(&_60$$28, &recordAfter, &referencedFields, PH_NOISY_CC);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_update_property_zval_zval(&intermediateModel, &intermediateReferencedFields, &_60$$28);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
							}
							ZEPHIR_CALL_METHOD_CACHED(&_61$$15, &intermediateModel, "doSave", &_zephir_call_cache[19], visited);
							zephir_check_call_status();
							if (!(zephir_is_true(&_61$$15))) {
								ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessagesFrom", &_zephir_call_cache[20], &intermediateModel);
								zephir_check_call_status();
								if (nesting) {
									ZVAL_BOOL(&_62$$29, 1);
								} else {
									ZVAL_BOOL(&_62$$29, 0);
								}
								ZEPHIR_CALL_METHOD_CACHED(NULL, connection, "rollback", &_zephir_call_cache[21], &_62$$29);
								zephir_check_call_status();
								RETURN_MM_BOOL(0);
							}
							if (doSync) {
								ZEPHIR_INIT_NVAR(&keepKey);
								if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
									ZVAL_STRING(&keepKey, "");
									if (Z_TYPE_P(&referencedFields) == IS_STRING) {
										ZEPHIR_INIT_NVAR(&_64$$31);
										zephir_string_to_char_array(&_64$$31, &referencedFields);
										_63$$31 = &_64$$31;
									} else {
										_63$$31 = &referencedFields;
									}
									zephir_is_iterable(_63$$31, 0, "phalcon/Mvc/Model.zep", 6056);
									if (Z_TYPE_P(_63$$31) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_63$$31), _65$$31)
										{
											ZEPHIR_INIT_NVAR(&columnA);
											ZVAL_COPY(&columnA, _65$$31);
											ZEPHIR_OBS_NVAR(&_66$$32);
											zephir_read_property_zval(&_66$$32, &recordAfter, &columnA, PH_NOISY_CC);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_INIT_NVAR(&_67$$32);
											ZEPHIR_CONCAT_VS(&_67$$32, &_66$$32, "|");
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_concat_self(&keepKey, &_67$$32);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD_CACHED(NULL, _63$$31, "rewind", &_zephir_call_cache[22]);
										zephir_check_call_status();
										_69$$31 = 1;
										while (1) {
											if (_69$$31) {
												_69$$31 = 0;
											} else {
												ZEPHIR_CALL_METHOD_CACHED(NULL, _63$$31, "next", &_zephir_call_cache[23]);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD_CACHED(&_68$$31, _63$$31, "valid", &_zephir_call_cache[24]);
											zephir_check_call_status();
											if (!zend_is_true(&_68$$31)) {
												break;
											}
											ZEPHIR_CALL_METHOD_CACHED(&columnA, _63$$31, "current", &_zephir_call_cache[25]);
											zephir_check_call_status();
												ZEPHIR_OBS_NVAR(&_70$$33);
												zephir_read_property_zval(&_70$$33, &recordAfter, &columnA, PH_NOISY_CC);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_INIT_NVAR(&_71$$33);
												ZEPHIR_CONCAT_VS(&_71$$33, &_70$$33, "|");
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_concat_self(&keepKey, &_71$$33);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
										}
									}
								} else {
									ZEPHIR_OBS_NVAR(&_72$$34);
									zephir_read_property_zval(&_72$$34, &recordAfter, &referencedFields, PH_NOISY_CC);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_cast_to_string(&_73$$34, &_72$$34);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CPY_WRT(&keepKey, &_73$$34);
								}
								zephir_array_update_zval(&keptKeys, &keepKey, &__$true, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _28$$9, "rewind", &_zephir_call_cache[26]);
						zephir_check_call_status();
						_75$$9 = 1;
						while (1) {
							if (_75$$9) {
								_75$$9 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _28$$9, "next", &_zephir_call_cache[27]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_74$$9, _28$$9, "valid", &_zephir_call_cache[28]);
							zephir_check_call_status();
							if (!zend_is_true(&_74$$9)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&recordAfter, _28$$9, "current", &_zephir_call_cache[29]);
							zephir_check_call_status();
								ZEPHIR_CALL_METHOD_CACHED(&_76$$35, &recordAfter, "doSave", &_zephir_call_cache[30], visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_76$$35))) {
									ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessagesFrom", &_zephir_call_cache[31], &recordAfter);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_77$$36, 1);
									} else {
										ZVAL_BOOL(&_77$$36, 0);
									}
									ZEPHIR_CALL_METHOD_CACHED(NULL, connection, "rollback", &_zephir_call_cache[32], &_77$$36);
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
								ZEPHIR_CALL_METHOD_CACHED(&_78$$35, &relation, "getType", &_zephir_call_cache[33]);
								zephir_check_call_status();
								if (ZEPHIR_IS_LONG_IDENTICAL(&_78$$35, 4)) {
									if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
										referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
										_81$$38 = referencedFieldsCount;
										_80$$38 = 0;
										_79$$38 = 0;
										if (_80$$38 <= _81$$38) {
											while (1) {
												if (_79$$38) {
													_80$$38++;
													if (!(_80$$38 <= _81$$38)) {
														break;
													}
												} else {
													_79$$38 = 1;
												}
												j = _80$$38;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &referencedFields, j, PH_NOISY, "phalcon/Mvc/Model.zep", 5973);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												t = (j + i);
												ZEPHIR_OBS_NVAR(&_82$$39);
												zephir_array_fetch_long(&_82$$39, &intermediateReferencedFields, j, PH_NOISY, "phalcon/Mvc/Model.zep", 5975);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_INIT_NVAR(&_83$$39);
												ZVAL_LONG(&_83$$39, t);
												ZEPHIR_INIT_NVAR(&_84$$39);
												ZEPHIR_CONCAT_SVSVS(&_84$$39, "[", &_82$$39, "] = :APR", &_83$$39, ":");
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_append(&loopConditions, &_84$$39, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5975);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_INIT_NVAR(&_85$$39);
												ZVAL_LONG(&_85$$39, t);
												ZEPHIR_INIT_NVAR(&_86$$39);
												ZEPHIR_CONCAT_SV(&_86$$39, "APR", &_85$$39);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_OBS_NVAR(&_87$$39);
												zephir_read_property_zval(&_87$$39, &recordAfter, &columnA, PH_NOISY_CC);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_update_zval(&loopPlaceholders, &_86$$39, &_87$$39, PH_COPY | PH_SEPARATE);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
											}
										}
									} else {
										ZEPHIR_INIT_NVAR(&_88$$40);
										ZVAL_LONG(&_88$$40, i);
										ZEPHIR_INIT_NVAR(&_89$$40);
										ZEPHIR_CONCAT_SVSVS(&_89$$40, "[", &intermediateReferencedFields, "] = :APR", &_88$$40, ":");
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_append(&loopConditions, &_89$$40, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5979);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_INIT_NVAR(&_90$$40);
										ZVAL_LONG(&_90$$40, i);
										ZEPHIR_INIT_NVAR(&_91$$40);
										ZEPHIR_CONCAT_SV(&_91$$40, "APR", &_90$$40);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_OBS_NVAR(&_92$$40);
										zephir_read_property_zval(&_92$$40, &recordAfter, &referencedFields, PH_NOISY_CC);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_update_zval(&loopPlaceholders, &_91$$40, &_92$$40, PH_COPY | PH_SEPARATE);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									}
								}
								ZEPHIR_CALL_METHOD_CACHED(&_93$$35, &manager, "load", &_zephir_call_cache[34], &intermediateModelName);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&intermediateModel, &_93$$35);
								ZEPHIR_INIT_NVAR(&_94$$35);
								zephir_create_array(&_94$$35, 2, 0);
								ZEPHIR_INIT_NVAR(&_95$$35);
								zephir_fast_join_str(&_95$$35, SL(" AND "), &loopConditions);
								zephir_array_fast_append(&_94$$35, &_95$$35);
								zephir_array_update_string(&_94$$35, SL("bind"), &loopPlaceholders, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD_CACHED(&existingIntermediateModel, &intermediateModel, "findFirst", &_zephir_call_cache[35], &_94$$35);
								zephir_check_call_status();
								if (zephir_is_true(&existingIntermediateModel)) {
									ZEPHIR_CPY_WRT(&intermediateModel, &existingIntermediateModel);
								}
								_96$$35 = !zephir_is_true(&existingIntermediateModel);
								if (!(_96$$35)) {
									ZEPHIR_CALL_METHOD_CACHED(&_93$$35, &relation, "getType", &_zephir_call_cache[36]);
									zephir_check_call_status();
									_96$$35 = ZEPHIR_IS_LONG_IDENTICAL(&_93$$35, 3);
								}
								if (_96$$35) {
									if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
										_99$$43 = columnCount;
										_98$$43 = 0;
										_97$$43 = 0;
										if (_98$$43 <= _99$$43) {
											while (1) {
												if (_97$$43) {
													_98$$43++;
													if (!(_98$$43 <= _99$$43)) {
														break;
													}
												} else {
													_97$$43 = 1;
												}
												h = _98$$43;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &columns, h, PH_NOISY, "phalcon/Mvc/Model.zep", 6010);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_OBS_NVAR(&columnB);
												zephir_array_fetch_long(&columnB, &intermediateFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 6011);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_OBS_NVAR(&_100$$44);
												zephir_read_property_zval(&_100$$44, this_ptr, &columnA, PH_NOISY_CC);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_update_property_zval_zval(&intermediateModel, &columnB, &_100$$44);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
											}
										}
									} else {
										ZEPHIR_OBS_NVAR(&_101$$45);
										zephir_read_property_zval(&_101$$45, this_ptr, &columns, PH_NOISY_CC);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_update_property_zval_zval(&intermediateModel, &intermediateFields, &_101$$45);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									}
									if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
										referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
										_104$$46 = referencedFieldsCount;
										_103$$46 = 0;
										_102$$46 = 0;
										if (_103$$46 <= _104$$46) {
											while (1) {
												if (_102$$46) {
													_103$$46++;
													if (!(_103$$46 <= _104$$46)) {
														break;
													}
												} else {
													_102$$46 = 1;
												}
												h = _103$$46;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &referencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 6020);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_OBS_NVAR(&columnB);
												zephir_array_fetch_long(&columnB, &intermediateReferencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 6021);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_OBS_NVAR(&_105$$47);
												zephir_read_property_zval(&_105$$47, &recordAfter, &columnA, PH_NOISY_CC);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_update_property_zval_zval(&intermediateModel, &columnB, &_105$$47);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
											}
										}
									} else {
										ZEPHIR_OBS_NVAR(&_106$$48);
										zephir_read_property_zval(&_106$$48, &recordAfter, &referencedFields, PH_NOISY_CC);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_update_property_zval_zval(&intermediateModel, &intermediateReferencedFields, &_106$$48);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									}
								}
								ZEPHIR_CALL_METHOD_CACHED(&_107$$35, &intermediateModel, "doSave", &_zephir_call_cache[37], visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_107$$35))) {
									ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessagesFrom", &_zephir_call_cache[38], &intermediateModel);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_108$$49, 1);
									} else {
										ZVAL_BOOL(&_108$$49, 0);
									}
									ZEPHIR_CALL_METHOD_CACHED(NULL, connection, "rollback", &_zephir_call_cache[39], &_108$$49);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
								if (doSync) {
									if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
										ZVAL_STRING(&keepKey, "");
										if (Z_TYPE_P(&referencedFields) == IS_STRING) {
											ZEPHIR_INIT_NVAR(&_110$$51);
											zephir_string_to_char_array(&_110$$51, &referencedFields);
											_109$$51 = &_110$$51;
										} else {
											_109$$51 = &referencedFields;
										}
										zephir_is_iterable(_109$$51, 0, "phalcon/Mvc/Model.zep", 6056);
										if (Z_TYPE_P(_109$$51) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_109$$51), _111$$51)
											{
												ZEPHIR_INIT_NVAR(&columnA);
												ZVAL_COPY(&columnA, _111$$51);
												ZEPHIR_OBS_NVAR(&_112$$52);
												zephir_read_property_zval(&_112$$52, &recordAfter, &columnA, PH_NOISY_CC);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_INIT_NVAR(&_113$$52);
												ZEPHIR_CONCAT_VS(&_113$$52, &_112$$52, "|");
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_concat_self(&keepKey, &_113$$52);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD_CACHED(NULL, _109$$51, "rewind", &_zephir_call_cache[40]);
											zephir_check_call_status();
											_115$$51 = 1;
											while (1) {
												if (_115$$51) {
													_115$$51 = 0;
												} else {
													ZEPHIR_CALL_METHOD_CACHED(NULL, _109$$51, "next", &_zephir_call_cache[41]);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD_CACHED(&_114$$51, _109$$51, "valid", &_zephir_call_cache[42]);
												zephir_check_call_status();
												if (!zend_is_true(&_114$$51)) {
													break;
												}
												ZEPHIR_CALL_METHOD_CACHED(&columnA, _109$$51, "current", &_zephir_call_cache[43]);
												zephir_check_call_status();
													ZEPHIR_OBS_NVAR(&_116$$53);
													zephir_read_property_zval(&_116$$53, &recordAfter, &columnA, PH_NOISY_CC);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													ZEPHIR_INIT_NVAR(&_117$$53);
													ZEPHIR_CONCAT_VS(&_117$$53, &_116$$53, "|");
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													zephir_concat_self(&keepKey, &_117$$53);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
											}
										}
									} else {
										ZEPHIR_OBS_NVAR(&_118$$54);
										zephir_read_property_zval(&_118$$54, &recordAfter, &referencedFields, PH_NOISY_CC);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_cast_to_string(&_119$$54, &_118$$54);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CPY_WRT(&keepKey, &_119$$54);
									}
									zephir_array_update_zval(&keptKeys, &keepKey, &__$true, PH_COPY | PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
						}
					}
					_120$$9 = doSync;
					if (_120$$9) {
						ZEPHIR_CALL_METHOD_CACHED(&_11$$9, &relation, "getType", &_zephir_call_cache[44]);
						zephir_check_call_status();
						_120$$9 = ZEPHIR_IS_LONG_IDENTICAL(&_11$$9, 4);
					}
					if (_120$$9) {
						ZEPHIR_CALL_METHOD_CACHED(&_121$$55, &manager, "load", &_zephir_call_cache[45], &intermediateModelName);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&intermediateModel, &_121$$55);
						ZEPHIR_INIT_NVAR(&_122$$55);
						zephir_create_array(&_122$$55, 2, 0);
						ZEPHIR_INIT_NVAR(&_123$$55);
						zephir_fast_join_str(&_123$$55, SL(" AND "), &conditions);
						zephir_array_fast_append(&_122$$55, &_123$$55);
						zephir_array_update_string(&_122$$55, SL("bind"), &placeholders, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD_CACHED(&existingRecords, &intermediateModel, "find", &_zephir_call_cache[46], &_122$$55);
						zephir_check_call_status();
						if (Z_TYPE_P(&existingRecords) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_123$$55);
							zephir_string_to_char_array(&_123$$55, &existingRecords);
							_124$$55 = &_123$$55;
						} else {
							_124$$55 = &existingRecords;
						}
						zephir_is_iterable(_124$$55, 0, "phalcon/Mvc/Model.zep", 6098);
						if (Z_TYPE_P(_124$$55) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_124$$55), _125$$55)
							{
								ZEPHIR_INIT_NVAR(&existingRecord);
								ZVAL_COPY(&existingRecord, _125$$55);
								if (UNEXPECTED(Z_TYPE_P(&intermediateReferencedFields) == IS_ARRAY)) {
									ZVAL_STRING(&keepKey, "");
									if (Z_TYPE_P(&intermediateReferencedFields) == IS_STRING) {
										ZEPHIR_INIT_NVAR(&_127$$57);
										zephir_string_to_char_array(&_127$$57, &intermediateReferencedFields);
										_126$$57 = &_127$$57;
									} else {
										_126$$57 = &intermediateReferencedFields;
									}
									zephir_is_iterable(_126$$57, 0, "phalcon/Mvc/Model.zep", 6086);
									if (Z_TYPE_P(_126$$57) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_126$$57), _128$$57)
										{
											ZEPHIR_INIT_NVAR(&columnB);
											ZVAL_COPY(&columnB, _128$$57);
											ZEPHIR_OBS_NVAR(&_129$$58);
											zephir_read_property_zval(&_129$$58, &existingRecord, &columnB, PH_NOISY_CC);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_INIT_NVAR(&_130$$58);
											ZEPHIR_CONCAT_VS(&_130$$58, &_129$$58, "|");
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_concat_self(&keepKey, &_130$$58);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD_CACHED(NULL, _126$$57, "rewind", &_zephir_call_cache[47]);
										zephir_check_call_status();
										_132$$57 = 1;
										while (1) {
											if (_132$$57) {
												_132$$57 = 0;
											} else {
												ZEPHIR_CALL_METHOD_CACHED(NULL, _126$$57, "next", &_zephir_call_cache[48]);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD_CACHED(&_131$$57, _126$$57, "valid", &_zephir_call_cache[49]);
											zephir_check_call_status();
											if (!zend_is_true(&_131$$57)) {
												break;
											}
											ZEPHIR_CALL_METHOD_CACHED(&columnB, _126$$57, "current", &_zephir_call_cache[50]);
											zephir_check_call_status();
												ZEPHIR_OBS_NVAR(&_133$$59);
												zephir_read_property_zval(&_133$$59, &existingRecord, &columnB, PH_NOISY_CC);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_INIT_NVAR(&_134$$59);
												ZEPHIR_CONCAT_VS(&_134$$59, &_133$$59, "|");
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_concat_self(&keepKey, &_134$$59);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
										}
									}
								} else {
									ZEPHIR_OBS_NVAR(&_135$$60);
									zephir_read_property_zval(&_135$$60, &existingRecord, &intermediateReferencedFields, PH_NOISY_CC);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_cast_to_string(&_136$$60, &_135$$60);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CPY_WRT(&keepKey, &_136$$60);
								}
								_137$$56 = zephir_array_isset_value(&keptKeys, &keepKey);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								_138$$56 = !(_137$$56);
								if (_138$$56) {
									ZEPHIR_CALL_METHOD_CACHED(&_139$$56, &existingRecord, "delete", &_zephir_call_cache[51]);
									zephir_check_call_status();
									_138$$56 = !zephir_is_true(&_139$$56);
								}
								if (_138$$56) {
									ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessagesFrom", &_zephir_call_cache[52], &existingRecord);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_140$$61, 1);
									} else {
										ZVAL_BOOL(&_140$$61, 0);
									}
									ZEPHIR_CALL_METHOD_CACHED(NULL, connection, "rollback", &_zephir_call_cache[53], &_140$$61);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _124$$55, "rewind", &_zephir_call_cache[54]);
							zephir_check_call_status();
							_142$$55 = 1;
							while (1) {
								if (_142$$55) {
									_142$$55 = 0;
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, _124$$55, "next", &_zephir_call_cache[55]);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD_CACHED(&_141$$55, _124$$55, "valid", &_zephir_call_cache[56]);
								zephir_check_call_status();
								if (!zend_is_true(&_141$$55)) {
									break;
								}
								ZEPHIR_CALL_METHOD_CACHED(&existingRecord, _124$$55, "current", &_zephir_call_cache[57]);
								zephir_check_call_status();
									if (UNEXPECTED(Z_TYPE_P(&intermediateReferencedFields) == IS_ARRAY)) {
										ZVAL_STRING(&keepKey, "");
										if (Z_TYPE_P(&intermediateReferencedFields) == IS_STRING) {
											ZEPHIR_INIT_NVAR(&_144$$63);
											zephir_string_to_char_array(&_144$$63, &intermediateReferencedFields);
											_143$$63 = &_144$$63;
										} else {
											_143$$63 = &intermediateReferencedFields;
										}
										zephir_is_iterable(_143$$63, 0, "phalcon/Mvc/Model.zep", 6086);
										if (Z_TYPE_P(_143$$63) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_143$$63), _145$$63)
											{
												ZEPHIR_INIT_NVAR(&columnB);
												ZVAL_COPY(&columnB, _145$$63);
												ZEPHIR_OBS_NVAR(&_146$$64);
												zephir_read_property_zval(&_146$$64, &existingRecord, &columnB, PH_NOISY_CC);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_INIT_NVAR(&_147$$64);
												ZEPHIR_CONCAT_VS(&_147$$64, &_146$$64, "|");
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_concat_self(&keepKey, &_147$$64);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD_CACHED(NULL, _143$$63, "rewind", &_zephir_call_cache[58]);
											zephir_check_call_status();
											_149$$63 = 1;
											while (1) {
												if (_149$$63) {
													_149$$63 = 0;
												} else {
													ZEPHIR_CALL_METHOD_CACHED(NULL, _143$$63, "next", &_zephir_call_cache[59]);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD_CACHED(&_148$$63, _143$$63, "valid", &_zephir_call_cache[60]);
												zephir_check_call_status();
												if (!zend_is_true(&_148$$63)) {
													break;
												}
												ZEPHIR_CALL_METHOD_CACHED(&columnB, _143$$63, "current", &_zephir_call_cache[61]);
												zephir_check_call_status();
													ZEPHIR_OBS_NVAR(&_150$$65);
													zephir_read_property_zval(&_150$$65, &existingRecord, &columnB, PH_NOISY_CC);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													ZEPHIR_INIT_NVAR(&_151$$65);
													ZEPHIR_CONCAT_VS(&_151$$65, &_150$$65, "|");
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													zephir_concat_self(&keepKey, &_151$$65);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
											}
										}
									} else {
										ZEPHIR_OBS_NVAR(&_152$$66);
										zephir_read_property_zval(&_152$$66, &existingRecord, &intermediateReferencedFields, PH_NOISY_CC);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_cast_to_string(&_153$$66, &_152$$66);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CPY_WRT(&keepKey, &_153$$66);
									}
									_154$$62 = zephir_array_isset_value(&keptKeys, &keepKey);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									_155$$62 = !(_154$$62);
									if (_155$$62) {
										ZEPHIR_CALL_METHOD_CACHED(&_156$$62, &existingRecord, "delete", &_zephir_call_cache[62]);
										zephir_check_call_status();
										_155$$62 = !zephir_is_true(&_156$$62);
									}
									if (_155$$62) {
										ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessagesFrom", &_zephir_call_cache[63], &existingRecord);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_157$$67, 1);
										} else {
											ZVAL_BOOL(&_157$$67, 0);
										}
										ZEPHIR_CALL_METHOD_CACHED(NULL, connection, "rollback", &_zephir_call_cache[64], &_157$$67);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
							}
						}
					}
				} else {
					if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
						columnCount = (zephir_fast_count_int(&columns) - 1);
						if (Z_TYPE_P(&relatedRecords) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_159$$69);
							zephir_string_to_char_array(&_159$$69, &relatedRecords);
							_158$$69 = &_159$$69;
						} else {
							_158$$69 = &relatedRecords;
						}
						zephir_is_iterable(_158$$69, 0, "phalcon/Mvc/Model.zep", 6126);
						if (Z_TYPE_P(_158$$69) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_158$$69), _160$$69)
							{
								ZEPHIR_INIT_NVAR(&recordAfter);
								ZVAL_COPY(&recordAfter, _160$$69);
								_163$$70 = columnCount;
								_162$$70 = 0;
								_161$$70 = 0;
								if (_162$$70 <= _163$$70) {
									while (1) {
										if (_161$$70) {
											_162$$70++;
											if (!(_162$$70 <= _163$$70)) {
												break;
											}
										} else {
											_161$$70 = 1;
										}
										i = _162$$70;
										ZEPHIR_OBS_NVAR(&columnA);
										zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 6104);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_OBS_NVAR(&columnB);
										zephir_array_fetch_long(&columnB, &referencedFields, i, PH_NOISY, "phalcon/Mvc/Model.zep", 6105);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_OBS_NVAR(&_164$$71);
										zephir_read_property_zval(&_164$$71, this_ptr, &columnA, PH_NOISY_CC);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_update_property_zval_zval(&recordAfter, &columnB, &_164$$71);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									}
								}
								ZEPHIR_CALL_METHOD_CACHED(&_165$$70, &recordAfter, "doSave", &_zephir_call_cache[65], visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_165$$70))) {
									ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessagesFrom", &_zephir_call_cache[66], &recordAfter);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_166$$72, 1);
									} else {
										ZVAL_BOOL(&_166$$72, 0);
									}
									ZEPHIR_CALL_METHOD_CACHED(NULL, connection, "rollback", &_zephir_call_cache[67], &_166$$72);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _158$$69, "rewind", &_zephir_call_cache[68]);
							zephir_check_call_status();
							_168$$69 = 1;
							while (1) {
								if (_168$$69) {
									_168$$69 = 0;
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, _158$$69, "next", &_zephir_call_cache[69]);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD_CACHED(&_167$$69, _158$$69, "valid", &_zephir_call_cache[70]);
								zephir_check_call_status();
								if (!zend_is_true(&_167$$69)) {
									break;
								}
								ZEPHIR_CALL_METHOD_CACHED(&recordAfter, _158$$69, "current", &_zephir_call_cache[71]);
								zephir_check_call_status();
									_171$$73 = columnCount;
									_170$$73 = 0;
									_169$$73 = 0;
									if (_170$$73 <= _171$$73) {
										while (1) {
											if (_169$$73) {
												_170$$73++;
												if (!(_170$$73 <= _171$$73)) {
													break;
												}
											} else {
												_169$$73 = 1;
											}
											i = _170$$73;
											ZEPHIR_OBS_NVAR(&columnA);
											zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 6104);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_OBS_NVAR(&columnB);
											zephir_array_fetch_long(&columnB, &referencedFields, i, PH_NOISY, "phalcon/Mvc/Model.zep", 6105);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_OBS_NVAR(&_172$$74);
											zephir_read_property_zval(&_172$$74, this_ptr, &columnA, PH_NOISY_CC);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_update_property_zval_zval(&recordAfter, &columnB, &_172$$74);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
										}
									}
									ZEPHIR_CALL_METHOD_CACHED(&_173$$73, &recordAfter, "doSave", &_zephir_call_cache[72], visited);
									zephir_check_call_status();
									if (!(zephir_is_true(&_173$$73))) {
										ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessagesFrom", &_zephir_call_cache[73], &recordAfter);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_174$$75, 1);
										} else {
											ZVAL_BOOL(&_174$$75, 0);
										}
										ZEPHIR_CALL_METHOD_CACHED(NULL, connection, "rollback", &_zephir_call_cache[74], &_174$$75);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
							}
						}
					} else {
						if (Z_TYPE_P(&relatedRecords) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_176$$76);
							zephir_string_to_char_array(&_176$$76, &relatedRecords);
							_175$$76 = &_176$$76;
						} else {
							_175$$76 = &relatedRecords;
						}
						zephir_is_iterable(_175$$76, 0, "phalcon/Mvc/Model.zep", 6151);
						if (Z_TYPE_P(_175$$76) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_175$$76), _177$$76)
							{
								ZEPHIR_INIT_NVAR(&recordAfter);
								ZVAL_COPY(&recordAfter, _177$$76);
								ZEPHIR_OBS_NVAR(&_178$$77);
								zephir_read_property_zval(&_178$$77, this_ptr, &columns, PH_NOISY_CC);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_update_property_zval_zval(&recordAfter, &referencedFields, &_178$$77);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CALL_METHOD_CACHED(&_179$$77, &recordAfter, "doSave", &_zephir_call_cache[75], visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_179$$77))) {
									ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessagesFrom", &_zephir_call_cache[76], &recordAfter);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_180$$78, 1);
									} else {
										ZVAL_BOOL(&_180$$78, 0);
									}
									ZEPHIR_CALL_METHOD_CACHED(NULL, connection, "rollback", &_zephir_call_cache[77], &_180$$78);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _175$$76, "rewind", &_zephir_call_cache[78]);
							zephir_check_call_status();
							_182$$76 = 1;
							while (1) {
								if (_182$$76) {
									_182$$76 = 0;
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, _175$$76, "next", &_zephir_call_cache[79]);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD_CACHED(&_181$$76, _175$$76, "valid", &_zephir_call_cache[80]);
								zephir_check_call_status();
								if (!zend_is_true(&_181$$76)) {
									break;
								}
								ZEPHIR_CALL_METHOD_CACHED(&recordAfter, _175$$76, "current", &_zephir_call_cache[81]);
								zephir_check_call_status();
									ZEPHIR_OBS_NVAR(&_183$$79);
									zephir_read_property_zval(&_183$$79, this_ptr, &columns, PH_NOISY_CC);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_update_property_zval_zval(&recordAfter, &referencedFields, &_183$$79);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_METHOD_CACHED(&_184$$79, &recordAfter, "doSave", &_zephir_call_cache[82], visited);
									zephir_check_call_status();
									if (!(zephir_is_true(&_184$$79))) {
										ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessagesFrom", &_zephir_call_cache[83], &recordAfter);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_185$$80, 1);
										} else {
											ZVAL_BOOL(&_185$$80, 0);
										}
										ZEPHIR_CALL_METHOD_CACHED(NULL, connection, "rollback", &_zephir_call_cache[84], &_185$$80);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
							}
						}
					}
				}
			} else {
				if (UNEXPECTED(Z_TYPE_P(&record) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_186$$82);
					object_init_ex(&_186$$82, phalcon_mvc_model_exceptions_relationnotdefined_ce);
					zephir_constructor_start(&_186$$82);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_186$$82, "__construct", &_zephir_call_cache[85], &className, &name);
					zephir_check_call_status();
					zephir_constructor_finish(&_186$$82);
					zephir_throw_exception_debug(&_186$$82, "phalcon/Mvc/Model.zep", 6158);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "rewind", &_zephir_call_cache[86]);
		zephir_check_call_status();
		_188 = 1;
		while (1) {
			if (_188) {
				_188 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "next", &_zephir_call_cache[87]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_187, _1, "valid", &_zephir_call_cache[88]);
			zephir_check_call_status();
			if (!zend_is_true(&_187)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&name, _1, "key", &_zephir_call_cache[89]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&record, _1, "current", &_zephir_call_cache[90]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_189$$83, &manager, "getRelationByAlias", &_zephir_call_cache[91], &className, &name);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&relation, &_189$$83);
				if (Z_TYPE_P(&relation) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD_CACHED(&_190$$84, &relation, "getType", &_zephir_call_cache[92]);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG(&_190$$84, 0)) {
						continue;
					}
					_191$$84 = Z_TYPE_P(&record) != IS_OBJECT;
					if (_191$$84) {
						_191$$84 = Z_TYPE_P(&record) != IS_ARRAY;
					}
					if (UNEXPECTED(_191$$84)) {
						ZEPHIR_INIT_NVAR(&_192$$86);
						object_init_ex(&_192$$86, phalcon_mvc_model_exceptions_relationrequiresobjectorarray_ce);
						zephir_constructor_start(&_192$$86);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_192$$86, "__construct", &_zephir_call_cache[93], &className, &name);
						zephir_check_call_status();
						zephir_constructor_finish(&_192$$86);
						zephir_throw_exception_debug(&_192$$86, "phalcon/Mvc/Model.zep", 5885);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(&columns, &relation, "getFields", &_zephir_call_cache[94]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&referencedModel, &relation, "getReferencedModel", &_zephir_call_cache[95]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&referencedFields, &relation, "getReferencedFields", &_zephir_call_cache[96]);
					zephir_check_call_status();
					if (Z_TYPE_P(&record) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_193$$87);
						zephir_create_array(&_193$$87, 1, 0);
						zephir_array_fast_append(&_193$$87, &record);
						ZEPHIR_CPY_WRT(&relatedRecords, &_193$$87);
					} else {
						ZEPHIR_CPY_WRT(&relatedRecords, &record);
					}
					ZEPHIR_CALL_METHOD_CACHED(&_194$$84, &relation, "isThrough", &_zephir_call_cache[97]);
					zephir_check_call_status();
					isThrough = zephir_get_boolval(&_194$$84);
					if (isThrough) {
						ZEPHIR_CALL_METHOD_CACHED(&intermediateModelName, &relation, "getIntermediateModel", &_zephir_call_cache[98]);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&intermediateFields, &relation, "getIntermediateFields", &_zephir_call_cache[99]);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&intermediateReferencedFields, &relation, "getIntermediateReferencedFields", &_zephir_call_cache[100]);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&placeholders);
						array_init(&placeholders);
						ZEPHIR_INIT_NVAR(&conditions);
						array_init(&conditions);
						ZEPHIR_INIT_NVAR(&keptKeys);
						array_init(&keptKeys);
						ZEPHIR_INIT_NVAR(&_196$$89);
						ZVAL_STRING(&_196$$89, "sync");
						ZEPHIR_CALL_METHOD_CACHED(&_195$$89, &relation, "getOption", &_zephir_call_cache[101], &_196$$89);
						zephir_check_call_status();
						doSync = zephir_get_boolval(&_195$$89);
						ZEPHIR_OBS_NVAR(&override);
						zephir_read_property_cached(&_197$$89, this_ptr, _zephir_prop_0, 1023, PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_198$$89 = zephir_array_isset_fetch(&override, &_197$$89, &name, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_198$$89) {
							doSync = zephir_get_boolval(&override);
						} else {
							ZEPHIR_OBS_NVAR(&override);
							zephir_read_property_cached(&_199$$89, this_ptr, _zephir_prop_0, 1023, PH_READONLY);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							_200$$89 = zephir_array_isset_string_fetch(&override, &_199$$89, SL("*"), 0);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (_200$$89) {
								doSync = zephir_get_boolval(&override);
							}
						}
						if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
							columnCount = (zephir_fast_count_int(&columns) - 1);
							_203$$92 = columnCount;
							_202$$92 = 0;
							_201$$92 = 0;
							if (_202$$92 <= _203$$92) {
								while (1) {
									if (_201$$92) {
										_202$$92++;
										if (!(_202$$92 <= _203$$92)) {
											break;
										}
									} else {
										_201$$92 = 1;
									}
									i = _202$$92;
									ZEPHIR_OBS_NVAR(&columnA);
									zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5932);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_OBS_NVAR(&_204$$93);
									zephir_array_fetch_long(&_204$$93, &intermediateFields, i, PH_NOISY, "phalcon/Mvc/Model.zep", 5933);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_INIT_NVAR(&_205$$93);
									ZVAL_LONG(&_205$$93, i);
									ZEPHIR_INIT_NVAR(&_206$$93);
									ZEPHIR_CONCAT_SVSVS(&_206$$93, "[", &_204$$93, "] = :APR", &_205$$93, ":");
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&conditions, &_206$$93, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5933);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_INIT_NVAR(&_207$$93);
									ZVAL_LONG(&_207$$93, i);
									ZEPHIR_INIT_NVAR(&_208$$93);
									ZEPHIR_CONCAT_SV(&_208$$93, "APR", &_207$$93);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_OBS_NVAR(&_209$$93);
									zephir_read_property_zval(&_209$$93, this_ptr, &columnA, PH_NOISY_CC);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_update_zval(&placeholders, &_208$$93, &_209$$93, PH_COPY | PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
							}
							i = (columnCount + 1);
						} else {
							ZEPHIR_INIT_NVAR(&_210$$94);
							ZEPHIR_CONCAT_SVS(&_210$$94, "[", &intermediateFields, "] = :APR0:");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&conditions, &_210$$94, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5938);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&_211$$94);
							zephir_read_property_zval(&_211$$94, this_ptr, &columns, PH_NOISY_CC);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_string(&placeholders, SL("APR0"), &_211$$94, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							i = 1;
						}
						if (Z_TYPE_P(&relatedRecords) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_196$$89);
							zephir_string_to_char_array(&_196$$89, &relatedRecords);
							_212$$89 = &_196$$89;
						} else {
							_212$$89 = &relatedRecords;
						}
						zephir_is_iterable(_212$$89, 0, "phalcon/Mvc/Model.zep", 6068);
						if (Z_TYPE_P(_212$$89) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_212$$89), _213$$89)
							{
								ZEPHIR_INIT_NVAR(&recordAfter);
								ZVAL_COPY(&recordAfter, _213$$89);
								ZEPHIR_CALL_METHOD_CACHED(&_214$$95, &recordAfter, "doSave", &_zephir_call_cache[102], visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_214$$95))) {
									ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessagesFrom", &_zephir_call_cache[103], &recordAfter);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_215$$96, 1);
									} else {
										ZVAL_BOOL(&_215$$96, 0);
									}
									ZEPHIR_CALL_METHOD_CACHED(NULL, connection, "rollback", &_zephir_call_cache[104], &_215$$96);
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
								ZEPHIR_CALL_METHOD_CACHED(&_216$$95, &relation, "getType", &_zephir_call_cache[105]);
								zephir_check_call_status();
								if (ZEPHIR_IS_LONG_IDENTICAL(&_216$$95, 4)) {
									if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
										referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
										_219$$98 = referencedFieldsCount;
										_218$$98 = 0;
										_217$$98 = 0;
										if (_218$$98 <= _219$$98) {
											while (1) {
												if (_217$$98) {
													_218$$98++;
													if (!(_218$$98 <= _219$$98)) {
														break;
													}
												} else {
													_217$$98 = 1;
												}
												j = _218$$98;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &referencedFields, j, PH_NOISY, "phalcon/Mvc/Model.zep", 5973);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												t = (j + i);
												ZEPHIR_OBS_NVAR(&_220$$99);
												zephir_array_fetch_long(&_220$$99, &intermediateReferencedFields, j, PH_NOISY, "phalcon/Mvc/Model.zep", 5975);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_INIT_NVAR(&_221$$99);
												ZVAL_LONG(&_221$$99, t);
												ZEPHIR_INIT_NVAR(&_222$$99);
												ZEPHIR_CONCAT_SVSVS(&_222$$99, "[", &_220$$99, "] = :APR", &_221$$99, ":");
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_append(&loopConditions, &_222$$99, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5975);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_INIT_NVAR(&_223$$99);
												ZVAL_LONG(&_223$$99, t);
												ZEPHIR_INIT_NVAR(&_224$$99);
												ZEPHIR_CONCAT_SV(&_224$$99, "APR", &_223$$99);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_OBS_NVAR(&_225$$99);
												zephir_read_property_zval(&_225$$99, &recordAfter, &columnA, PH_NOISY_CC);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_update_zval(&loopPlaceholders, &_224$$99, &_225$$99, PH_COPY | PH_SEPARATE);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
											}
										}
									} else {
										ZEPHIR_INIT_NVAR(&_226$$100);
										ZVAL_LONG(&_226$$100, i);
										ZEPHIR_INIT_NVAR(&_227$$100);
										ZEPHIR_CONCAT_SVSVS(&_227$$100, "[", &intermediateReferencedFields, "] = :APR", &_226$$100, ":");
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_append(&loopConditions, &_227$$100, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5979);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_INIT_NVAR(&_228$$100);
										ZVAL_LONG(&_228$$100, i);
										ZEPHIR_INIT_NVAR(&_229$$100);
										ZEPHIR_CONCAT_SV(&_229$$100, "APR", &_228$$100);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_OBS_NVAR(&_230$$100);
										zephir_read_property_zval(&_230$$100, &recordAfter, &referencedFields, PH_NOISY_CC);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_update_zval(&loopPlaceholders, &_229$$100, &_230$$100, PH_COPY | PH_SEPARATE);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									}
								}
								ZEPHIR_CALL_METHOD_CACHED(&_231$$95, &manager, "load", &_zephir_call_cache[106], &intermediateModelName);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&intermediateModel, &_231$$95);
								ZEPHIR_INIT_NVAR(&_232$$95);
								zephir_create_array(&_232$$95, 2, 0);
								ZEPHIR_INIT_NVAR(&_233$$95);
								zephir_fast_join_str(&_233$$95, SL(" AND "), &loopConditions);
								zephir_array_fast_append(&_232$$95, &_233$$95);
								zephir_array_update_string(&_232$$95, SL("bind"), &loopPlaceholders, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD_CACHED(&existingIntermediateModel, &intermediateModel, "findFirst", &_zephir_call_cache[107], &_232$$95);
								zephir_check_call_status();
								if (zephir_is_true(&existingIntermediateModel)) {
									ZEPHIR_CPY_WRT(&intermediateModel, &existingIntermediateModel);
								}
								_234$$95 = !zephir_is_true(&existingIntermediateModel);
								if (!(_234$$95)) {
									ZEPHIR_CALL_METHOD_CACHED(&_231$$95, &relation, "getType", &_zephir_call_cache[108]);
									zephir_check_call_status();
									_234$$95 = ZEPHIR_IS_LONG_IDENTICAL(&_231$$95, 3);
								}
								if (_234$$95) {
									if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
										_237$$103 = columnCount;
										_236$$103 = 0;
										_235$$103 = 0;
										if (_236$$103 <= _237$$103) {
											while (1) {
												if (_235$$103) {
													_236$$103++;
													if (!(_236$$103 <= _237$$103)) {
														break;
													}
												} else {
													_235$$103 = 1;
												}
												h = _236$$103;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &columns, h, PH_NOISY, "phalcon/Mvc/Model.zep", 6010);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_OBS_NVAR(&columnB);
												zephir_array_fetch_long(&columnB, &intermediateFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 6011);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_OBS_NVAR(&_238$$104);
												zephir_read_property_zval(&_238$$104, this_ptr, &columnA, PH_NOISY_CC);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_update_property_zval_zval(&intermediateModel, &columnB, &_238$$104);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
											}
										}
									} else {
										ZEPHIR_OBS_NVAR(&_239$$105);
										zephir_read_property_zval(&_239$$105, this_ptr, &columns, PH_NOISY_CC);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_update_property_zval_zval(&intermediateModel, &intermediateFields, &_239$$105);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									}
									if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
										referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
										_242$$106 = referencedFieldsCount;
										_241$$106 = 0;
										_240$$106 = 0;
										if (_241$$106 <= _242$$106) {
											while (1) {
												if (_240$$106) {
													_241$$106++;
													if (!(_241$$106 <= _242$$106)) {
														break;
													}
												} else {
													_240$$106 = 1;
												}
												h = _241$$106;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &referencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 6020);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_OBS_NVAR(&columnB);
												zephir_array_fetch_long(&columnB, &intermediateReferencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 6021);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_OBS_NVAR(&_243$$107);
												zephir_read_property_zval(&_243$$107, &recordAfter, &columnA, PH_NOISY_CC);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_update_property_zval_zval(&intermediateModel, &columnB, &_243$$107);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
											}
										}
									} else {
										ZEPHIR_OBS_NVAR(&_244$$108);
										zephir_read_property_zval(&_244$$108, &recordAfter, &referencedFields, PH_NOISY_CC);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_update_property_zval_zval(&intermediateModel, &intermediateReferencedFields, &_244$$108);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									}
								}
								ZEPHIR_CALL_METHOD_CACHED(&_245$$95, &intermediateModel, "doSave", &_zephir_call_cache[109], visited);
								zephir_check_call_status();
								if (!(zephir_is_true(&_245$$95))) {
									ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessagesFrom", &_zephir_call_cache[110], &intermediateModel);
									zephir_check_call_status();
									if (nesting) {
										ZVAL_BOOL(&_246$$109, 1);
									} else {
										ZVAL_BOOL(&_246$$109, 0);
									}
									ZEPHIR_CALL_METHOD_CACHED(NULL, connection, "rollback", &_zephir_call_cache[111], &_246$$109);
									zephir_check_call_status();
									RETURN_MM_BOOL(0);
								}
								if (doSync) {
									if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
										ZVAL_STRING(&keepKey, "");
										if (Z_TYPE_P(&referencedFields) == IS_STRING) {
											ZEPHIR_INIT_NVAR(&_248$$111);
											zephir_string_to_char_array(&_248$$111, &referencedFields);
											_247$$111 = &_248$$111;
										} else {
											_247$$111 = &referencedFields;
										}
										zephir_is_iterable(_247$$111, 0, "phalcon/Mvc/Model.zep", 6056);
										if (Z_TYPE_P(_247$$111) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_247$$111), _249$$111)
											{
												ZEPHIR_INIT_NVAR(&columnA);
												ZVAL_COPY(&columnA, _249$$111);
												ZEPHIR_OBS_NVAR(&_250$$112);
												zephir_read_property_zval(&_250$$112, &recordAfter, &columnA, PH_NOISY_CC);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_INIT_NVAR(&_251$$112);
												ZEPHIR_CONCAT_VS(&_251$$112, &_250$$112, "|");
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_concat_self(&keepKey, &_251$$112);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD_CACHED(NULL, _247$$111, "rewind", &_zephir_call_cache[112]);
											zephir_check_call_status();
											_253$$111 = 1;
											while (1) {
												if (_253$$111) {
													_253$$111 = 0;
												} else {
													ZEPHIR_CALL_METHOD_CACHED(NULL, _247$$111, "next", &_zephir_call_cache[113]);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD_CACHED(&_252$$111, _247$$111, "valid", &_zephir_call_cache[114]);
												zephir_check_call_status();
												if (!zend_is_true(&_252$$111)) {
													break;
												}
												ZEPHIR_CALL_METHOD_CACHED(&columnA, _247$$111, "current", &_zephir_call_cache[115]);
												zephir_check_call_status();
													ZEPHIR_OBS_NVAR(&_254$$113);
													zephir_read_property_zval(&_254$$113, &recordAfter, &columnA, PH_NOISY_CC);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													ZEPHIR_INIT_NVAR(&_255$$113);
													ZEPHIR_CONCAT_VS(&_255$$113, &_254$$113, "|");
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													zephir_concat_self(&keepKey, &_255$$113);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
											}
										}
									} else {
										ZEPHIR_OBS_NVAR(&_256$$114);
										zephir_read_property_zval(&_256$$114, &recordAfter, &referencedFields, PH_NOISY_CC);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_cast_to_string(&_257$$114, &_256$$114);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CPY_WRT(&keepKey, &_257$$114);
									}
									zephir_array_update_zval(&keptKeys, &keepKey, &__$true, PH_COPY | PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _212$$89, "rewind", &_zephir_call_cache[116]);
							zephir_check_call_status();
							_259$$89 = 1;
							while (1) {
								if (_259$$89) {
									_259$$89 = 0;
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, _212$$89, "next", &_zephir_call_cache[117]);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD_CACHED(&_258$$89, _212$$89, "valid", &_zephir_call_cache[118]);
								zephir_check_call_status();
								if (!zend_is_true(&_258$$89)) {
									break;
								}
								ZEPHIR_CALL_METHOD_CACHED(&recordAfter, _212$$89, "current", &_zephir_call_cache[119]);
								zephir_check_call_status();
									ZEPHIR_CALL_METHOD_CACHED(&_260$$115, &recordAfter, "doSave", &_zephir_call_cache[120], visited);
									zephir_check_call_status();
									if (!(zephir_is_true(&_260$$115))) {
										ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessagesFrom", &_zephir_call_cache[121], &recordAfter);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_261$$116, 1);
										} else {
											ZVAL_BOOL(&_261$$116, 0);
										}
										ZEPHIR_CALL_METHOD_CACHED(NULL, connection, "rollback", &_zephir_call_cache[122], &_261$$116);
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
									ZEPHIR_CALL_METHOD_CACHED(&_262$$115, &relation, "getType", &_zephir_call_cache[123]);
									zephir_check_call_status();
									if (ZEPHIR_IS_LONG_IDENTICAL(&_262$$115, 4)) {
										if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
											referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
											_265$$118 = referencedFieldsCount;
											_264$$118 = 0;
											_263$$118 = 0;
											if (_264$$118 <= _265$$118) {
												while (1) {
													if (_263$$118) {
														_264$$118++;
														if (!(_264$$118 <= _265$$118)) {
															break;
														}
													} else {
														_263$$118 = 1;
													}
													j = _264$$118;
													ZEPHIR_OBS_NVAR(&columnA);
													zephir_array_fetch_long(&columnA, &referencedFields, j, PH_NOISY, "phalcon/Mvc/Model.zep", 5973);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													t = (j + i);
													ZEPHIR_OBS_NVAR(&_266$$119);
													zephir_array_fetch_long(&_266$$119, &intermediateReferencedFields, j, PH_NOISY, "phalcon/Mvc/Model.zep", 5975);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													ZEPHIR_INIT_NVAR(&_267$$119);
													ZVAL_LONG(&_267$$119, t);
													ZEPHIR_INIT_NVAR(&_268$$119);
													ZEPHIR_CONCAT_SVSVS(&_268$$119, "[", &_266$$119, "] = :APR", &_267$$119, ":");
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													zephir_array_append(&loopConditions, &_268$$119, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5975);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													ZEPHIR_INIT_NVAR(&_269$$119);
													ZVAL_LONG(&_269$$119, t);
													ZEPHIR_INIT_NVAR(&_270$$119);
													ZEPHIR_CONCAT_SV(&_270$$119, "APR", &_269$$119);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													ZEPHIR_OBS_NVAR(&_271$$119);
													zephir_read_property_zval(&_271$$119, &recordAfter, &columnA, PH_NOISY_CC);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													zephir_array_update_zval(&loopPlaceholders, &_270$$119, &_271$$119, PH_COPY | PH_SEPARATE);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
												}
											}
										} else {
											ZEPHIR_INIT_NVAR(&_272$$120);
											ZVAL_LONG(&_272$$120, i);
											ZEPHIR_INIT_NVAR(&_273$$120);
											ZEPHIR_CONCAT_SVSVS(&_273$$120, "[", &intermediateReferencedFields, "] = :APR", &_272$$120, ":");
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_append(&loopConditions, &_273$$120, PH_SEPARATE, "phalcon/Mvc/Model.zep", 5979);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_INIT_NVAR(&_274$$120);
											ZVAL_LONG(&_274$$120, i);
											ZEPHIR_INIT_NVAR(&_275$$120);
											ZEPHIR_CONCAT_SV(&_275$$120, "APR", &_274$$120);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_OBS_NVAR(&_276$$120);
											zephir_read_property_zval(&_276$$120, &recordAfter, &referencedFields, PH_NOISY_CC);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_update_zval(&loopPlaceholders, &_275$$120, &_276$$120, PH_COPY | PH_SEPARATE);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
										}
									}
									ZEPHIR_CALL_METHOD_CACHED(&_277$$115, &manager, "load", &_zephir_call_cache[124], &intermediateModelName);
									zephir_check_call_status();
									ZEPHIR_CPY_WRT(&intermediateModel, &_277$$115);
									ZEPHIR_INIT_NVAR(&_278$$115);
									zephir_create_array(&_278$$115, 2, 0);
									ZEPHIR_INIT_NVAR(&_279$$115);
									zephir_fast_join_str(&_279$$115, SL(" AND "), &loopConditions);
									zephir_array_fast_append(&_278$$115, &_279$$115);
									zephir_array_update_string(&_278$$115, SL("bind"), &loopPlaceholders, PH_COPY | PH_SEPARATE);
									ZEPHIR_CALL_METHOD_CACHED(&existingIntermediateModel, &intermediateModel, "findFirst", &_zephir_call_cache[125], &_278$$115);
									zephir_check_call_status();
									if (zephir_is_true(&existingIntermediateModel)) {
										ZEPHIR_CPY_WRT(&intermediateModel, &existingIntermediateModel);
									}
									_280$$115 = !zephir_is_true(&existingIntermediateModel);
									if (!(_280$$115)) {
										ZEPHIR_CALL_METHOD_CACHED(&_277$$115, &relation, "getType", &_zephir_call_cache[126]);
										zephir_check_call_status();
										_280$$115 = ZEPHIR_IS_LONG_IDENTICAL(&_277$$115, 3);
									}
									if (_280$$115) {
										if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
											_283$$123 = columnCount;
											_282$$123 = 0;
											_281$$123 = 0;
											if (_282$$123 <= _283$$123) {
												while (1) {
													if (_281$$123) {
														_282$$123++;
														if (!(_282$$123 <= _283$$123)) {
															break;
														}
													} else {
														_281$$123 = 1;
													}
													h = _282$$123;
													ZEPHIR_OBS_NVAR(&columnA);
													zephir_array_fetch_long(&columnA, &columns, h, PH_NOISY, "phalcon/Mvc/Model.zep", 6010);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													ZEPHIR_OBS_NVAR(&columnB);
													zephir_array_fetch_long(&columnB, &intermediateFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 6011);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													ZEPHIR_OBS_NVAR(&_284$$124);
													zephir_read_property_zval(&_284$$124, this_ptr, &columnA, PH_NOISY_CC);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													zephir_update_property_zval_zval(&intermediateModel, &columnB, &_284$$124);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
												}
											}
										} else {
											ZEPHIR_OBS_NVAR(&_285$$125);
											zephir_read_property_zval(&_285$$125, this_ptr, &columns, PH_NOISY_CC);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_update_property_zval_zval(&intermediateModel, &intermediateFields, &_285$$125);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
										}
										if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
											referencedFieldsCount = (zephir_fast_count_int(&referencedFields) - 1);
											_288$$126 = referencedFieldsCount;
											_287$$126 = 0;
											_286$$126 = 0;
											if (_287$$126 <= _288$$126) {
												while (1) {
													if (_286$$126) {
														_287$$126++;
														if (!(_287$$126 <= _288$$126)) {
															break;
														}
													} else {
														_286$$126 = 1;
													}
													h = _287$$126;
													ZEPHIR_OBS_NVAR(&columnA);
													zephir_array_fetch_long(&columnA, &referencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 6020);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													ZEPHIR_OBS_NVAR(&columnB);
													zephir_array_fetch_long(&columnB, &intermediateReferencedFields, h, PH_NOISY, "phalcon/Mvc/Model.zep", 6021);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													ZEPHIR_OBS_NVAR(&_289$$127);
													zephir_read_property_zval(&_289$$127, &recordAfter, &columnA, PH_NOISY_CC);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													zephir_update_property_zval_zval(&intermediateModel, &columnB, &_289$$127);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
												}
											}
										} else {
											ZEPHIR_OBS_NVAR(&_290$$128);
											zephir_read_property_zval(&_290$$128, &recordAfter, &referencedFields, PH_NOISY_CC);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_update_property_zval_zval(&intermediateModel, &intermediateReferencedFields, &_290$$128);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
										}
									}
									ZEPHIR_CALL_METHOD_CACHED(&_291$$115, &intermediateModel, "doSave", &_zephir_call_cache[127], visited);
									zephir_check_call_status();
									if (!(zephir_is_true(&_291$$115))) {
										ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessagesFrom", &_zephir_call_cache[128], &intermediateModel);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_292$$129, 1);
										} else {
											ZVAL_BOOL(&_292$$129, 0);
										}
										ZEPHIR_CALL_METHOD_CACHED(NULL, connection, "rollback", &_zephir_call_cache[129], &_292$$129);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
									if (doSync) {
										if (UNEXPECTED(Z_TYPE_P(&referencedFields) == IS_ARRAY)) {
											ZVAL_STRING(&keepKey, "");
											if (Z_TYPE_P(&referencedFields) == IS_STRING) {
												ZEPHIR_INIT_NVAR(&_294$$131);
												zephir_string_to_char_array(&_294$$131, &referencedFields);
												_293$$131 = &_294$$131;
											} else {
												_293$$131 = &referencedFields;
											}
											zephir_is_iterable(_293$$131, 0, "phalcon/Mvc/Model.zep", 6056);
											if (Z_TYPE_P(_293$$131) == IS_ARRAY) {
												ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_293$$131), _295$$131)
												{
													ZEPHIR_INIT_NVAR(&columnA);
													ZVAL_COPY(&columnA, _295$$131);
													ZEPHIR_OBS_NVAR(&_296$$132);
													zephir_read_property_zval(&_296$$132, &recordAfter, &columnA, PH_NOISY_CC);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													ZEPHIR_INIT_NVAR(&_297$$132);
													ZEPHIR_CONCAT_VS(&_297$$132, &_296$$132, "|");
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													zephir_concat_self(&keepKey, &_297$$132);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
												} ZEND_HASH_FOREACH_END();
											} else {
												ZEPHIR_CALL_METHOD_CACHED(NULL, _293$$131, "rewind", &_zephir_call_cache[130]);
												zephir_check_call_status();
												_299$$131 = 1;
												while (1) {
													if (_299$$131) {
														_299$$131 = 0;
													} else {
														ZEPHIR_CALL_METHOD_CACHED(NULL, _293$$131, "next", &_zephir_call_cache[131]);
														zephir_check_call_status();
													}
													ZEPHIR_CALL_METHOD_CACHED(&_298$$131, _293$$131, "valid", &_zephir_call_cache[132]);
													zephir_check_call_status();
													if (!zend_is_true(&_298$$131)) {
														break;
													}
													ZEPHIR_CALL_METHOD_CACHED(&columnA, _293$$131, "current", &_zephir_call_cache[133]);
													zephir_check_call_status();
														ZEPHIR_OBS_NVAR(&_300$$133);
														zephir_read_property_zval(&_300$$133, &recordAfter, &columnA, PH_NOISY_CC);
														if (UNEXPECTED(EG(exception))) {
															ZEPHIR_MM_RESTORE();
															return;
														}
														ZEPHIR_INIT_NVAR(&_301$$133);
														ZEPHIR_CONCAT_VS(&_301$$133, &_300$$133, "|");
														if (UNEXPECTED(EG(exception))) {
															ZEPHIR_MM_RESTORE();
															return;
														}
														zephir_concat_self(&keepKey, &_301$$133);
														if (UNEXPECTED(EG(exception))) {
															ZEPHIR_MM_RESTORE();
															return;
														}
												}
											}
										} else {
											ZEPHIR_OBS_NVAR(&_302$$134);
											zephir_read_property_zval(&_302$$134, &recordAfter, &referencedFields, PH_NOISY_CC);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_cast_to_string(&_303$$134, &_302$$134);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_CPY_WRT(&keepKey, &_303$$134);
										}
										zephir_array_update_zval(&keptKeys, &keepKey, &__$true, PH_COPY | PH_SEPARATE);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									}
							}
						}
						_304$$89 = doSync;
						if (_304$$89) {
							ZEPHIR_CALL_METHOD_CACHED(&_195$$89, &relation, "getType", &_zephir_call_cache[134]);
							zephir_check_call_status();
							_304$$89 = ZEPHIR_IS_LONG_IDENTICAL(&_195$$89, 4);
						}
						if (_304$$89) {
							ZEPHIR_CALL_METHOD_CACHED(&_305$$135, &manager, "load", &_zephir_call_cache[135], &intermediateModelName);
							zephir_check_call_status();
							ZEPHIR_CPY_WRT(&intermediateModel, &_305$$135);
							ZEPHIR_INIT_NVAR(&_306$$135);
							zephir_create_array(&_306$$135, 2, 0);
							ZEPHIR_INIT_NVAR(&_307$$135);
							zephir_fast_join_str(&_307$$135, SL(" AND "), &conditions);
							zephir_array_fast_append(&_306$$135, &_307$$135);
							zephir_array_update_string(&_306$$135, SL("bind"), &placeholders, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD_CACHED(&existingRecords, &intermediateModel, "find", &_zephir_call_cache[136], &_306$$135);
							zephir_check_call_status();
							if (Z_TYPE_P(&existingRecords) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_307$$135);
								zephir_string_to_char_array(&_307$$135, &existingRecords);
								_308$$135 = &_307$$135;
							} else {
								_308$$135 = &existingRecords;
							}
							zephir_is_iterable(_308$$135, 0, "phalcon/Mvc/Model.zep", 6098);
							if (Z_TYPE_P(_308$$135) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_308$$135), _309$$135)
								{
									ZEPHIR_INIT_NVAR(&existingRecord);
									ZVAL_COPY(&existingRecord, _309$$135);
									if (UNEXPECTED(Z_TYPE_P(&intermediateReferencedFields) == IS_ARRAY)) {
										ZVAL_STRING(&keepKey, "");
										if (Z_TYPE_P(&intermediateReferencedFields) == IS_STRING) {
											ZEPHIR_INIT_NVAR(&_311$$137);
											zephir_string_to_char_array(&_311$$137, &intermediateReferencedFields);
											_310$$137 = &_311$$137;
										} else {
											_310$$137 = &intermediateReferencedFields;
										}
										zephir_is_iterable(_310$$137, 0, "phalcon/Mvc/Model.zep", 6086);
										if (Z_TYPE_P(_310$$137) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_310$$137), _312$$137)
											{
												ZEPHIR_INIT_NVAR(&columnB);
												ZVAL_COPY(&columnB, _312$$137);
												ZEPHIR_OBS_NVAR(&_313$$138);
												zephir_read_property_zval(&_313$$138, &existingRecord, &columnB, PH_NOISY_CC);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_INIT_NVAR(&_314$$138);
												ZEPHIR_CONCAT_VS(&_314$$138, &_313$$138, "|");
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_concat_self(&keepKey, &_314$$138);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD_CACHED(NULL, _310$$137, "rewind", &_zephir_call_cache[137]);
											zephir_check_call_status();
											_316$$137 = 1;
											while (1) {
												if (_316$$137) {
													_316$$137 = 0;
												} else {
													ZEPHIR_CALL_METHOD_CACHED(NULL, _310$$137, "next", &_zephir_call_cache[138]);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD_CACHED(&_315$$137, _310$$137, "valid", &_zephir_call_cache[139]);
												zephir_check_call_status();
												if (!zend_is_true(&_315$$137)) {
													break;
												}
												ZEPHIR_CALL_METHOD_CACHED(&columnB, _310$$137, "current", &_zephir_call_cache[140]);
												zephir_check_call_status();
													ZEPHIR_OBS_NVAR(&_317$$139);
													zephir_read_property_zval(&_317$$139, &existingRecord, &columnB, PH_NOISY_CC);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													ZEPHIR_INIT_NVAR(&_318$$139);
													ZEPHIR_CONCAT_VS(&_318$$139, &_317$$139, "|");
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													zephir_concat_self(&keepKey, &_318$$139);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
											}
										}
									} else {
										ZEPHIR_OBS_NVAR(&_319$$140);
										zephir_read_property_zval(&_319$$140, &existingRecord, &intermediateReferencedFields, PH_NOISY_CC);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_cast_to_string(&_320$$140, &_319$$140);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CPY_WRT(&keepKey, &_320$$140);
									}
									_321$$136 = zephir_array_isset_value(&keptKeys, &keepKey);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									_322$$136 = !(_321$$136);
									if (_322$$136) {
										ZEPHIR_CALL_METHOD_CACHED(&_323$$136, &existingRecord, "delete", &_zephir_call_cache[141]);
										zephir_check_call_status();
										_322$$136 = !zephir_is_true(&_323$$136);
									}
									if (_322$$136) {
										ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessagesFrom", &_zephir_call_cache[142], &existingRecord);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_324$$141, 1);
										} else {
											ZVAL_BOOL(&_324$$141, 0);
										}
										ZEPHIR_CALL_METHOD_CACHED(NULL, connection, "rollback", &_zephir_call_cache[143], &_324$$141);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _308$$135, "rewind", &_zephir_call_cache[144]);
								zephir_check_call_status();
								_326$$135 = 1;
								while (1) {
									if (_326$$135) {
										_326$$135 = 0;
									} else {
										ZEPHIR_CALL_METHOD_CACHED(NULL, _308$$135, "next", &_zephir_call_cache[145]);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD_CACHED(&_325$$135, _308$$135, "valid", &_zephir_call_cache[146]);
									zephir_check_call_status();
									if (!zend_is_true(&_325$$135)) {
										break;
									}
									ZEPHIR_CALL_METHOD_CACHED(&existingRecord, _308$$135, "current", &_zephir_call_cache[147]);
									zephir_check_call_status();
										if (UNEXPECTED(Z_TYPE_P(&intermediateReferencedFields) == IS_ARRAY)) {
											ZVAL_STRING(&keepKey, "");
											if (Z_TYPE_P(&intermediateReferencedFields) == IS_STRING) {
												ZEPHIR_INIT_NVAR(&_328$$143);
												zephir_string_to_char_array(&_328$$143, &intermediateReferencedFields);
												_327$$143 = &_328$$143;
											} else {
												_327$$143 = &intermediateReferencedFields;
											}
											zephir_is_iterable(_327$$143, 0, "phalcon/Mvc/Model.zep", 6086);
											if (Z_TYPE_P(_327$$143) == IS_ARRAY) {
												ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_327$$143), _329$$143)
												{
													ZEPHIR_INIT_NVAR(&columnB);
													ZVAL_COPY(&columnB, _329$$143);
													ZEPHIR_OBS_NVAR(&_330$$144);
													zephir_read_property_zval(&_330$$144, &existingRecord, &columnB, PH_NOISY_CC);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													ZEPHIR_INIT_NVAR(&_331$$144);
													ZEPHIR_CONCAT_VS(&_331$$144, &_330$$144, "|");
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													zephir_concat_self(&keepKey, &_331$$144);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
												} ZEND_HASH_FOREACH_END();
											} else {
												ZEPHIR_CALL_METHOD_CACHED(NULL, _327$$143, "rewind", &_zephir_call_cache[148]);
												zephir_check_call_status();
												_333$$143 = 1;
												while (1) {
													if (_333$$143) {
														_333$$143 = 0;
													} else {
														ZEPHIR_CALL_METHOD_CACHED(NULL, _327$$143, "next", &_zephir_call_cache[149]);
														zephir_check_call_status();
													}
													ZEPHIR_CALL_METHOD_CACHED(&_332$$143, _327$$143, "valid", &_zephir_call_cache[150]);
													zephir_check_call_status();
													if (!zend_is_true(&_332$$143)) {
														break;
													}
													ZEPHIR_CALL_METHOD_CACHED(&columnB, _327$$143, "current", &_zephir_call_cache[151]);
													zephir_check_call_status();
														ZEPHIR_OBS_NVAR(&_334$$145);
														zephir_read_property_zval(&_334$$145, &existingRecord, &columnB, PH_NOISY_CC);
														if (UNEXPECTED(EG(exception))) {
															ZEPHIR_MM_RESTORE();
															return;
														}
														ZEPHIR_INIT_NVAR(&_335$$145);
														ZEPHIR_CONCAT_VS(&_335$$145, &_334$$145, "|");
														if (UNEXPECTED(EG(exception))) {
															ZEPHIR_MM_RESTORE();
															return;
														}
														zephir_concat_self(&keepKey, &_335$$145);
														if (UNEXPECTED(EG(exception))) {
															ZEPHIR_MM_RESTORE();
															return;
														}
												}
											}
										} else {
											ZEPHIR_OBS_NVAR(&_336$$146);
											zephir_read_property_zval(&_336$$146, &existingRecord, &intermediateReferencedFields, PH_NOISY_CC);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_cast_to_string(&_337$$146, &_336$$146);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_CPY_WRT(&keepKey, &_337$$146);
										}
										_338$$142 = zephir_array_isset_value(&keptKeys, &keepKey);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										_339$$142 = !(_338$$142);
										if (_339$$142) {
											ZEPHIR_CALL_METHOD_CACHED(&_340$$142, &existingRecord, "delete", &_zephir_call_cache[152]);
											zephir_check_call_status();
											_339$$142 = !zephir_is_true(&_340$$142);
										}
										if (_339$$142) {
											ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessagesFrom", &_zephir_call_cache[153], &existingRecord);
											zephir_check_call_status();
											if (nesting) {
												ZVAL_BOOL(&_341$$147, 1);
											} else {
												ZVAL_BOOL(&_341$$147, 0);
											}
											ZEPHIR_CALL_METHOD_CACHED(NULL, connection, "rollback", &_zephir_call_cache[154], &_341$$147);
											zephir_check_call_status();
											RETURN_MM_BOOL(0);
										}
								}
							}
						}
					} else {
						if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
							columnCount = (zephir_fast_count_int(&columns) - 1);
							if (Z_TYPE_P(&relatedRecords) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_343$$149);
								zephir_string_to_char_array(&_343$$149, &relatedRecords);
								_342$$149 = &_343$$149;
							} else {
								_342$$149 = &relatedRecords;
							}
							zephir_is_iterable(_342$$149, 0, "phalcon/Mvc/Model.zep", 6126);
							if (Z_TYPE_P(_342$$149) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_342$$149), _344$$149)
								{
									ZEPHIR_INIT_NVAR(&recordAfter);
									ZVAL_COPY(&recordAfter, _344$$149);
									_347$$150 = columnCount;
									_346$$150 = 0;
									_345$$150 = 0;
									if (_346$$150 <= _347$$150) {
										while (1) {
											if (_345$$150) {
												_346$$150++;
												if (!(_346$$150 <= _347$$150)) {
													break;
												}
											} else {
												_345$$150 = 1;
											}
											i = _346$$150;
											ZEPHIR_OBS_NVAR(&columnA);
											zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 6104);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_OBS_NVAR(&columnB);
											zephir_array_fetch_long(&columnB, &referencedFields, i, PH_NOISY, "phalcon/Mvc/Model.zep", 6105);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_OBS_NVAR(&_348$$151);
											zephir_read_property_zval(&_348$$151, this_ptr, &columnA, PH_NOISY_CC);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_update_property_zval_zval(&recordAfter, &columnB, &_348$$151);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
										}
									}
									ZEPHIR_CALL_METHOD_CACHED(&_349$$150, &recordAfter, "doSave", &_zephir_call_cache[155], visited);
									zephir_check_call_status();
									if (!(zephir_is_true(&_349$$150))) {
										ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessagesFrom", &_zephir_call_cache[156], &recordAfter);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_350$$152, 1);
										} else {
											ZVAL_BOOL(&_350$$152, 0);
										}
										ZEPHIR_CALL_METHOD_CACHED(NULL, connection, "rollback", &_zephir_call_cache[157], &_350$$152);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _342$$149, "rewind", &_zephir_call_cache[158]);
								zephir_check_call_status();
								_352$$149 = 1;
								while (1) {
									if (_352$$149) {
										_352$$149 = 0;
									} else {
										ZEPHIR_CALL_METHOD_CACHED(NULL, _342$$149, "next", &_zephir_call_cache[159]);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD_CACHED(&_351$$149, _342$$149, "valid", &_zephir_call_cache[160]);
									zephir_check_call_status();
									if (!zend_is_true(&_351$$149)) {
										break;
									}
									ZEPHIR_CALL_METHOD_CACHED(&recordAfter, _342$$149, "current", &_zephir_call_cache[161]);
									zephir_check_call_status();
										_355$$153 = columnCount;
										_354$$153 = 0;
										_353$$153 = 0;
										if (_354$$153 <= _355$$153) {
											while (1) {
												if (_353$$153) {
													_354$$153++;
													if (!(_354$$153 <= _355$$153)) {
														break;
													}
												} else {
													_353$$153 = 1;
												}
												i = _354$$153;
												ZEPHIR_OBS_NVAR(&columnA);
												zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 6104);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_OBS_NVAR(&columnB);
												zephir_array_fetch_long(&columnB, &referencedFields, i, PH_NOISY, "phalcon/Mvc/Model.zep", 6105);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												ZEPHIR_OBS_NVAR(&_356$$154);
												zephir_read_property_zval(&_356$$154, this_ptr, &columnA, PH_NOISY_CC);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_update_property_zval_zval(&recordAfter, &columnB, &_356$$154);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
											}
										}
										ZEPHIR_CALL_METHOD_CACHED(&_357$$153, &recordAfter, "doSave", &_zephir_call_cache[162], visited);
										zephir_check_call_status();
										if (!(zephir_is_true(&_357$$153))) {
											ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessagesFrom", &_zephir_call_cache[163], &recordAfter);
											zephir_check_call_status();
											if (nesting) {
												ZVAL_BOOL(&_358$$155, 1);
											} else {
												ZVAL_BOOL(&_358$$155, 0);
											}
											ZEPHIR_CALL_METHOD_CACHED(NULL, connection, "rollback", &_zephir_call_cache[164], &_358$$155);
											zephir_check_call_status();
											RETURN_MM_BOOL(0);
										}
								}
							}
						} else {
							if (Z_TYPE_P(&relatedRecords) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_360$$156);
								zephir_string_to_char_array(&_360$$156, &relatedRecords);
								_359$$156 = &_360$$156;
							} else {
								_359$$156 = &relatedRecords;
							}
							zephir_is_iterable(_359$$156, 0, "phalcon/Mvc/Model.zep", 6151);
							if (Z_TYPE_P(_359$$156) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_359$$156), _361$$156)
								{
									ZEPHIR_INIT_NVAR(&recordAfter);
									ZVAL_COPY(&recordAfter, _361$$156);
									ZEPHIR_OBS_NVAR(&_362$$157);
									zephir_read_property_zval(&_362$$157, this_ptr, &columns, PH_NOISY_CC);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_update_property_zval_zval(&recordAfter, &referencedFields, &_362$$157);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_METHOD_CACHED(&_363$$157, &recordAfter, "doSave", &_zephir_call_cache[165], visited);
									zephir_check_call_status();
									if (!(zephir_is_true(&_363$$157))) {
										ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessagesFrom", &_zephir_call_cache[166], &recordAfter);
										zephir_check_call_status();
										if (nesting) {
											ZVAL_BOOL(&_364$$158, 1);
										} else {
											ZVAL_BOOL(&_364$$158, 0);
										}
										ZEPHIR_CALL_METHOD_CACHED(NULL, connection, "rollback", &_zephir_call_cache[167], &_364$$158);
										zephir_check_call_status();
										RETURN_MM_BOOL(0);
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _359$$156, "rewind", &_zephir_call_cache[168]);
								zephir_check_call_status();
								_366$$156 = 1;
								while (1) {
									if (_366$$156) {
										_366$$156 = 0;
									} else {
										ZEPHIR_CALL_METHOD_CACHED(NULL, _359$$156, "next", &_zephir_call_cache[169]);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD_CACHED(&_365$$156, _359$$156, "valid", &_zephir_call_cache[170]);
									zephir_check_call_status();
									if (!zend_is_true(&_365$$156)) {
										break;
									}
									ZEPHIR_CALL_METHOD_CACHED(&recordAfter, _359$$156, "current", &_zephir_call_cache[171]);
									zephir_check_call_status();
										ZEPHIR_OBS_NVAR(&_367$$159);
										zephir_read_property_zval(&_367$$159, this_ptr, &columns, PH_NOISY_CC);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_update_property_zval_zval(&recordAfter, &referencedFields, &_367$$159);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CALL_METHOD_CACHED(&_368$$159, &recordAfter, "doSave", &_zephir_call_cache[172], visited);
										zephir_check_call_status();
										if (!(zephir_is_true(&_368$$159))) {
											ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessagesFrom", &_zephir_call_cache[173], &recordAfter);
											zephir_check_call_status();
											if (nesting) {
												ZVAL_BOOL(&_369$$160, 1);
											} else {
												ZVAL_BOOL(&_369$$160, 0);
											}
											ZEPHIR_CALL_METHOD_CACHED(NULL, connection, "rollback", &_zephir_call_cache[174], &_369$$160);
											zephir_check_call_status();
											RETURN_MM_BOOL(0);
										}
								}
							}
						}
					}
				} else {
					if (UNEXPECTED(Z_TYPE_P(&record) != IS_ARRAY)) {
						ZEPHIR_INIT_NVAR(&_370$$162);
						object_init_ex(&_370$$162, phalcon_mvc_model_exceptions_relationnotdefined_ce);
						zephir_constructor_start(&_370$$162);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_370$$162, "__construct", &_zephir_call_cache[175], &className, &name);
						zephir_check_call_status();
						zephir_constructor_finish(&_370$$162);
						zephir_throw_exception_debug(&_370$$162, "phalcon/Mvc/Model.zep", 6158);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
		}
	}
	if (nesting) {
		ZVAL_BOOL(&_371, 1);
	} else {
		ZVAL_BOOL(&_371, 0);
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, connection, "commit", &_zephir_call_cache[176], &_371);
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
	zval _30$$32, _53$$52;
	zval eventName;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool exists, error = 0, isNull = 0, _34$$11, _12$$17, _17$$16, _18$$21, _19$$23, _20$$24, _21$$27, _22$$27, _23$$27, _24$$27, _26$$33, _27$$33, _35$$37, _40$$36, _41$$41, _42$$43, _43$$44, _44$$47, _45$$47, _46$$47, _47$$47, _49$$53, _50$$53;
	zval *metaData, metaData_sub, *exists_param = NULL, *identityField, identityField_sub, __$true, __$false, notNull, columnMap, dataTypeNumeric, automaticAttributes, defaultValues, field, attributeField, value, emptyStringValues, _0, _1, _5, _7, _59, _63, _2$$3, _3$$3, _4$$3, _6$$8, _8$$11, _9$$11, *_10$$11, *_11$$11, _33$$11, _13$$18, _14$$18, _15$$19, _16$$19, _25$$27, _28$$32, _29$$32, _31$$32, _32$$32, _36$$38, _37$$38, _38$$39, _39$$39, _48$$47, _51$$52, _52$$52, _54$$52, _55$$52, _56$$56, _57$$56, _58$$57, _60$$58, _61$$58, _62$$59, _64$$60, _65$$60, _66$$60, _67$$60, _68$$60, _69$$60;
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
	ZVAL_UNDEF(&_59);
	ZVAL_UNDEF(&_63);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_33$$11);
	ZVAL_UNDEF(&_13$$18);
	ZVAL_UNDEF(&_14$$18);
	ZVAL_UNDEF(&_15$$19);
	ZVAL_UNDEF(&_16$$19);
	ZVAL_UNDEF(&_25$$27);
	ZVAL_UNDEF(&_28$$32);
	ZVAL_UNDEF(&_29$$32);
	ZVAL_UNDEF(&_31$$32);
	ZVAL_UNDEF(&_32$$32);
	ZVAL_UNDEF(&_36$$38);
	ZVAL_UNDEF(&_37$$38);
	ZVAL_UNDEF(&_38$$39);
	ZVAL_UNDEF(&_39$$39);
	ZVAL_UNDEF(&_48$$47);
	ZVAL_UNDEF(&_51$$52);
	ZVAL_UNDEF(&_52$$52);
	ZVAL_UNDEF(&_54$$52);
	ZVAL_UNDEF(&_55$$52);
	ZVAL_UNDEF(&_56$$56);
	ZVAL_UNDEF(&_57$$56);
	ZVAL_UNDEF(&_58$$57);
	ZVAL_UNDEF(&_60$$58);
	ZVAL_UNDEF(&_61$$58);
	ZVAL_UNDEF(&_62$$59);
	ZVAL_UNDEF(&_64$$60);
	ZVAL_UNDEF(&_65$$60);
	ZVAL_UNDEF(&_66$$60);
	ZVAL_UNDEF(&_67$$60);
	ZVAL_UNDEF(&_68$$60);
	ZVAL_UNDEF(&_69$$60);
	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&_30$$32);
	ZVAL_UNDEF(&_53$$52);
	ZEND_TLS zephir_method_cache _zephir_call_cache[35];
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
	ZEPHIR_CALL_CE_STATIC_CACHED(&_0, phalcon_support_settings_ce, "get", &_zephir_call_cache[0], &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "beforeValidation");
		ZEPHIR_CALL_METHOD_CACHED(&_2$$3, this_ptr, "fireEventCancel", &_zephir_call_cache[1], &_3$$3);
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
		ZEPHIR_CALL_METHOD_CACHED(&_4$$3, this_ptr, "fireEventCancel", &_zephir_call_cache[2], &eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_4$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "orm.virtual_foreign_keys");
	ZEPHIR_CALL_CE_STATIC_CACHED(&_5, phalcon_support_settings_ce, "get", &_zephir_call_cache[3], &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_5)) {
		ZEPHIR_CALL_METHOD_CACHED(&_6$$8, this_ptr, "checkForeignKeysRestrict", &_zephir_call_cache[4]);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_6$$8)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "orm.not_null_validations");
	ZEPHIR_CALL_CE_STATIC_CACHED(&_7, phalcon_support_settings_ce, "get", &_zephir_call_cache[5], &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_7)) {
		ZEPHIR_CALL_METHOD_CACHED(&notNull, metaData, "getNotNullAttributes", &_zephir_call_cache[6], this_ptr);
		zephir_check_call_status();
		if (Z_TYPE_P(&notNull) == IS_ARRAY) {
			ZEPHIR_CALL_METHOD_CACHED(&dataTypeNumeric, metaData, "getDataTypesNumeric", &_zephir_call_cache[7], this_ptr);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_9$$11);
			ZVAL_STRING(&_9$$11, "orm.column_renaming");
			ZEPHIR_CALL_CE_STATIC_CACHED(&_8$$11, phalcon_support_settings_ce, "get", &_zephir_call_cache[8], &_9$$11);
			zephir_check_call_status();
			if (zephir_is_true(&_8$$11)) {
				ZEPHIR_CALL_METHOD_CACHED(&columnMap, metaData, "getColumnMap", &_zephir_call_cache[9], this_ptr);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&columnMap);
				ZVAL_NULL(&columnMap);
			}
			if (exists) {
				ZEPHIR_CALL_METHOD_CACHED(&automaticAttributes, metaData, "getAutomaticUpdateAttributes", &_zephir_call_cache[10], this_ptr);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(&automaticAttributes, metaData, "getAutomaticCreateAttributes", &_zephir_call_cache[11], this_ptr);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&defaultValues, metaData, "getDefaultValues", &_zephir_call_cache[12], this_ptr);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&emptyStringValues, metaData, "getEmptyStringAttributes", &_zephir_call_cache[13], this_ptr);
			zephir_check_call_status();
			error = 0;
			if (Z_TYPE_P(&notNull) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_9$$11);
				zephir_string_to_char_array(&_9$$11, &notNull);
				_10$$11 = &_9$$11;
			} else {
				_10$$11 = &notNull;
			}
			zephir_is_iterable(_10$$11, 0, "phalcon/Mvc/Model.zep", 6338);
			if (Z_TYPE_P(_10$$11) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_10$$11), _11$$11)
				{
					ZEPHIR_INIT_NVAR(&field);
					ZVAL_COPY(&field, _11$$11);
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						_12$$17 = zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (UNEXPECTED(!(_12$$17))) {
							ZEPHIR_INIT_NVAR(&_14$$18);
							ZVAL_STRING(&_14$$18, "orm.ignore_unknown_columns");
							ZEPHIR_CALL_CE_STATIC_CACHED(&_13$$18, phalcon_support_settings_ce, "get", &_zephir_call_cache[14], &_14$$18);
							zephir_check_call_status();
							if (UNEXPECTED(!zephir_is_true(&_13$$18))) {
								ZEPHIR_INIT_NVAR(&_15$$19);
								object_init_ex(&_15$$19, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
								zephir_constructor_start(&_15$$19);
								ZEPHIR_INIT_NVAR(&_16$$19);
								zephir_get_class(&_16$$19, this_ptr, 0);
								ZEPHIR_CALL_METHOD_CACHED(NULL, &_15$$19, "__construct", &_zephir_call_cache[15], &field, &_16$$19);
								zephir_check_call_status();
								zephir_constructor_finish(&_15$$19);
								zephir_throw_exception_debug(&_15$$19, "phalcon/Mvc/Model.zep", 6258);
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} else {
						ZEPHIR_CPY_WRT(&attributeField, &field);
					}
					_17$$16 = zephir_array_key_exists(&automaticAttributes, &attributeField);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_17$$16)) {
						isNull = 0;
						ZEPHIR_OBS_NVAR(&value);
						_18$$21 = zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_18$$21) {
							if (Z_TYPE_P(&value) != IS_OBJECT) {
								_19$$23 = zephir_array_isset_value(&dataTypeNumeric, &field);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (!(_19$$23)) {
									_20$$24 = zephir_array_isset_value(&emptyStringValues, &field);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (_20$$24) {
										if (Z_TYPE_P(&value) == IS_NULL) {
											isNull = 1;
										}
									} else {
										_21$$27 = Z_TYPE_P(&value) == IS_NULL;
										if (!(_21$$27)) {
											_22$$27 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
											if (_22$$27) {
												_23$$27 = zephir_array_isset_value(&defaultValues, &field);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												_24$$27 = !(_23$$27);
												if (!(_24$$27)) {
													ZEPHIR_OBS_NVAR(&_25$$27);
													zephir_array_fetch(&_25$$27, &defaultValues, &field, PH_NOISY, "phalcon/Mvc/Model.zep", 6288);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													_24$$27 = !ZEPHIR_IS_IDENTICAL(&value, &_25$$27);
												}
												_22$$27 = _24$$27;
											}
											_21$$27 = _22$$27;
										}
										if (_21$$27) {
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
								_26$$33 = ZEPHIR_IS_EQUAL(&field, identityField);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (_26$$33) {
									continue;
								}
								_27$$33 = zephir_array_isset_value(&defaultValues, &field);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (_27$$33) {
									continue;
								}
							}
							ZEPHIR_INIT_NVAR(&_28$$32);
							object_init_ex(&_28$$32, phalcon_messages_message_ce);
							zephir_constructor_start(&_28$$32);
							ZEPHIR_INIT_NVAR(&_29$$32);
							ZEPHIR_CONCAT_VS(&_29$$32, &attributeField, " is required");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&_30$$32);
							zephir_create_array(&_30$$32, 1, 0);
							ZEPHIR_INIT_NVAR(&_31$$32);
							zephir_get_class(&_31$$32, this_ptr, 0);
							zephir_array_update_string(&_30$$32, SL("model"), &_31$$32, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_31$$32);
							ZVAL_STRING(&_31$$32, "PresenceOf");
							ZVAL_LONG(&_32$$32, 0);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_28$$32, "__construct", &_zephir_call_cache[16], &_29$$32, &attributeField, &_31$$32, &_32$$32, &_30$$32);
							zephir_check_call_status();
							zephir_constructor_finish(&_28$$32);
							zephir_update_property_array_append(this_ptr, SL("errorMessages"), &_28$$32);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							error = 1;
						}
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _10$$11, "rewind", &_zephir_call_cache[17]);
				zephir_check_call_status();
				_34$$11 = 1;
				while (1) {
					if (_34$$11) {
						_34$$11 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _10$$11, "next", &_zephir_call_cache[18]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_33$$11, _10$$11, "valid", &_zephir_call_cache[19]);
					zephir_check_call_status();
					if (!zend_is_true(&_33$$11)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&field, _10$$11, "current", &_zephir_call_cache[20]);
					zephir_check_call_status();
						if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
							ZEPHIR_OBS_NVAR(&attributeField);
							_35$$37 = zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (UNEXPECTED(!(_35$$37))) {
								ZEPHIR_INIT_NVAR(&_37$$38);
								ZVAL_STRING(&_37$$38, "orm.ignore_unknown_columns");
								ZEPHIR_CALL_CE_STATIC_CACHED(&_36$$38, phalcon_support_settings_ce, "get", &_zephir_call_cache[21], &_37$$38);
								zephir_check_call_status();
								if (UNEXPECTED(!zephir_is_true(&_36$$38))) {
									ZEPHIR_INIT_NVAR(&_38$$39);
									object_init_ex(&_38$$39, phalcon_mvc_model_exceptions_columnnotintablemap_ce);
									zephir_constructor_start(&_38$$39);
									ZEPHIR_INIT_NVAR(&_39$$39);
									zephir_get_class(&_39$$39, this_ptr, 0);
									ZEPHIR_CALL_METHOD_CACHED(NULL, &_38$$39, "__construct", &_zephir_call_cache[22], &field, &_39$$39);
									zephir_check_call_status();
									zephir_constructor_finish(&_38$$39);
									zephir_throw_exception_debug(&_38$$39, "phalcon/Mvc/Model.zep", 6258);
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
						} else {
							ZEPHIR_CPY_WRT(&attributeField, &field);
						}
						_40$$36 = zephir_array_key_exists(&automaticAttributes, &attributeField);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (!(_40$$36)) {
							isNull = 0;
							ZEPHIR_OBS_NVAR(&value);
							_41$$41 = zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (_41$$41) {
								if (Z_TYPE_P(&value) != IS_OBJECT) {
									_42$$43 = zephir_array_isset_value(&dataTypeNumeric, &field);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (!(_42$$43)) {
										_43$$44 = zephir_array_isset_value(&emptyStringValues, &field);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										if (_43$$44) {
											if (Z_TYPE_P(&value) == IS_NULL) {
												isNull = 1;
											}
										} else {
											_44$$47 = Z_TYPE_P(&value) == IS_NULL;
											if (!(_44$$47)) {
												_45$$47 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
												if (_45$$47) {
													_46$$47 = zephir_array_isset_value(&defaultValues, &field);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													_47$$47 = !(_46$$47);
													if (!(_47$$47)) {
														ZEPHIR_OBS_NVAR(&_48$$47);
														zephir_array_fetch(&_48$$47, &defaultValues, &field, PH_NOISY, "phalcon/Mvc/Model.zep", 6288);
														if (UNEXPECTED(EG(exception))) {
															ZEPHIR_MM_RESTORE();
															return;
														}
														_47$$47 = !ZEPHIR_IS_IDENTICAL(&value, &_48$$47);
													}
													_45$$47 = _47$$47;
												}
												_44$$47 = _45$$47;
											}
											if (_44$$47) {
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
									_49$$53 = ZEPHIR_IS_EQUAL(&field, identityField);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (_49$$53) {
										continue;
									}
									_50$$53 = zephir_array_isset_value(&defaultValues, &field);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (_50$$53) {
										continue;
									}
								}
								ZEPHIR_INIT_NVAR(&_51$$52);
								object_init_ex(&_51$$52, phalcon_messages_message_ce);
								zephir_constructor_start(&_51$$52);
								ZEPHIR_INIT_NVAR(&_52$$52);
								ZEPHIR_CONCAT_VS(&_52$$52, &attributeField, " is required");
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_INIT_NVAR(&_53$$52);
								zephir_create_array(&_53$$52, 1, 0);
								ZEPHIR_INIT_NVAR(&_54$$52);
								zephir_get_class(&_54$$52, this_ptr, 0);
								zephir_array_update_string(&_53$$52, SL("model"), &_54$$52, PH_COPY | PH_SEPARATE);
								ZEPHIR_INIT_NVAR(&_54$$52);
								ZVAL_STRING(&_54$$52, "PresenceOf");
								ZVAL_LONG(&_55$$52, 0);
								ZEPHIR_CALL_METHOD_CACHED(NULL, &_51$$52, "__construct", &_zephir_call_cache[23], &_52$$52, &attributeField, &_54$$52, &_55$$52, &_53$$52);
								zephir_check_call_status();
								zephir_constructor_finish(&_51$$52);
								zephir_update_property_array_append(this_ptr, SL("errorMessages"), &_51$$52);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								error = 1;
							}
						}
				}
			}
			if (error) {
				ZEPHIR_INIT_VAR(&_57$$56);
				ZVAL_STRING(&_57$$56, "orm.events");
				ZEPHIR_CALL_CE_STATIC_CACHED(&_56$$56, phalcon_support_settings_ce, "get", &_zephir_call_cache[24], &_57$$56);
				zephir_check_call_status();
				if (zephir_is_true(&_56$$56)) {
					ZEPHIR_INIT_VAR(&_58$$57);
					ZVAL_STRING(&_58$$57, "onValidationFails");
					ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "fireEvent", &_zephir_call_cache[25], &_58$$57);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "cancelOperation", &_zephir_call_cache[26]);
					zephir_check_call_status();
				}
				RETURN_MM_BOOL(0);
			}
		}
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "validation");
	ZEPHIR_CALL_METHOD_CACHED(&_59, this_ptr, "fireEventCancel", &_zephir_call_cache[27], &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_59)) {
		ZEPHIR_INIT_VAR(&_61$$58);
		ZVAL_STRING(&_61$$58, "orm.events");
		ZEPHIR_CALL_CE_STATIC_CACHED(&_60$$58, phalcon_support_settings_ce, "get", &_zephir_call_cache[28], &_61$$58);
		zephir_check_call_status();
		if (zephir_is_true(&_60$$58)) {
			ZEPHIR_INIT_VAR(&_62$$59);
			ZVAL_STRING(&_62$$59, "onValidationFails");
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "fireEvent", &_zephir_call_cache[29], &_62$$59);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "orm.events");
	ZEPHIR_CALL_CE_STATIC_CACHED(&_63, phalcon_support_settings_ce, "get", &_zephir_call_cache[30], &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_63)) {
		if (exists) {
			ZEPHIR_INIT_NVAR(&eventName);
			ZVAL_STRING(&eventName, "afterValidationOnUpdate");
		} else {
			ZEPHIR_INIT_NVAR(&eventName);
			ZVAL_STRING(&eventName, "afterValidationOnCreate");
		}
		ZEPHIR_CALL_METHOD_CACHED(&_64$$60, this_ptr, "fireEventCancel", &_zephir_call_cache[31], &eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_64$$60)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(&_66$$60);
		ZVAL_STRING(&_66$$60, "afterValidation");
		ZEPHIR_CALL_METHOD_CACHED(&_65$$60, this_ptr, "fireEventCancel", &_zephir_call_cache[32], &_66$$60);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_65$$60)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(&_66$$60);
		ZVAL_STRING(&_66$$60, "beforeSave");
		ZEPHIR_CALL_METHOD_CACHED(&_67$$60, this_ptr, "fireEventCancel", &_zephir_call_cache[33], &_66$$60);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_67$$60)) {
			RETURN_MM_BOOL(0);
		}
		if (0) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1022, &__$true);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1022, &__$false);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		if (exists) {
			ZEPHIR_INIT_NVAR(&eventName);
			ZVAL_STRING(&eventName, "beforeUpdate");
		} else {
			ZEPHIR_INIT_NVAR(&eventName);
			ZVAL_STRING(&eventName, "beforeCreate");
		}
		ZEPHIR_CALL_METHOD_CACHED(&_68$$60, this_ptr, "fireEventCancel", &_zephir_call_cache[34], &eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_68$$60)) {
			RETURN_MM_BOOL(0);
		}
		zephir_read_property_cached(&_69$$60, this_ptr, _zephir_prop_0, 1022, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_69$$60)) {
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
	zend_bool nesting = 0, _18, _12$$8, _24$$16;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, columnCount = 0, i = 0, _13$$8, _14$$8, _25$$16, _26$$16;
	zval *connection, connection_sub, *related, related_sub, *visited, visited_sub, className, manager, type, relation, columns, referencedFields, name, record, columnA, columnB, _0, _1, *_2, _3, *_4, _17, _7$$3, _8$$6, _9$$6, _10$$5, _11$$7, _15$$9, _16$$10, _19$$11, _20$$14, _21$$14, _22$$13, _23$$15, _27$$17, _28$$18;
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
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_28$$18);
	ZEND_TLS zephir_method_cache _zephir_call_cache[23];
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
	ZEPHIR_CALL_METHOD_CACHED(NULL, connection, "begin", &_zephir_call_cache[0], &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, this_ptr, 0);
	ZEPHIR_CALL_METHOD_CACHED(&_1, this_ptr, "getModelsManager", &_zephir_call_cache[1]);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_1);
	if (Z_TYPE_P(related) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_3);
		zephir_string_to_char_array(&_3, related);
		_2 = &_3;
	} else {
		_2 = related;
	}
	zephir_is_iterable(_2, 0, "phalcon/Mvc/Model.zep", 6504);
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
			ZEPHIR_CALL_METHOD_CACHED(&_7$$3, &manager, "getRelationByAlias", &_zephir_call_cache[2], &className, &name);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&relation, &_7$$3);
			if (Z_TYPE_P(&relation) == IS_OBJECT) {
				ZEPHIR_CALL_METHOD_CACHED(&type, &relation, "getType", &_zephir_call_cache[3]);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(&type, 0)) {
					if (UNEXPECTED(Z_TYPE_P(&record) != IS_OBJECT)) {
						ZEPHIR_INIT_NVAR(&_8$$6);
						object_init_ex(&_8$$6, phalcon_mvc_model_exceptions_belongstorequiresobject_ce);
						zephir_constructor_start(&_8$$6);
						ZEPHIR_INIT_NVAR(&_9$$6);
						zephir_get_class(&_9$$6, this_ptr, 0);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_8$$6, "__construct", &_zephir_call_cache[4], &_9$$6, &name);
						zephir_check_call_status();
						zephir_constructor_finish(&_8$$6);
						zephir_throw_exception_debug(&_8$$6, "phalcon/Mvc/Model.zep", 6461);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(&_10$$5, &record, "doSave", &_zephir_call_cache[5], visited);
					zephir_check_call_status();
					if (!(zephir_is_true(&_10$$5))) {
						ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessagesFrom", &_zephir_call_cache[6], &record);
						zephir_check_call_status();
						if (nesting) {
							ZVAL_BOOL(&_11$$7, 1);
						} else {
							ZVAL_BOOL(&_11$$7, 0);
						}
						ZEPHIR_CALL_METHOD_CACHED(NULL, connection, "rollback", &_zephir_call_cache[7], &_11$$7);
						zephir_check_call_status();
						RETURN_MM_BOOL(0);
					}
					ZEPHIR_CALL_METHOD_CACHED(&columns, &relation, "getFields", &_zephir_call_cache[8]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&referencedFields, &relation, "getReferencedFields", &_zephir_call_cache[9]);
					zephir_check_call_status();
					if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
						columnCount = (zephir_fast_count_int(&columns) - 1);
						_14$$8 = columnCount;
						_13$$8 = 0;
						_12$$8 = 0;
						if (_13$$8 <= _14$$8) {
							while (1) {
								if (_12$$8) {
									_13$$8++;
									if (!(_13$$8 <= _14$$8)) {
										break;
									}
								} else {
									_12$$8 = 1;
								}
								i = _13$$8;
								ZEPHIR_OBS_NVAR(&columnA);
								zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 6493);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&columnB);
								zephir_array_fetch_long(&columnB, &referencedFields, i, PH_NOISY, "phalcon/Mvc/Model.zep", 6494);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&_15$$9);
								zephir_read_property_zval(&_15$$9, &record, &columnB, PH_NOISY_CC);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_update_property_zval_zval(this_ptr, &columnA, &_15$$9);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
						}
					} else {
						ZEPHIR_OBS_NVAR(&_16$$10);
						zephir_read_property_zval(&_16$$10, &record, &referencedFields, PH_NOISY_CC);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_update_property_zval_zval(this_ptr, &columns, &_16$$10);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _2, "rewind", &_zephir_call_cache[10]);
		zephir_check_call_status();
		_18 = 1;
		while (1) {
			if (_18) {
				_18 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _2, "next", &_zephir_call_cache[11]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_17, _2, "valid", &_zephir_call_cache[12]);
			zephir_check_call_status();
			if (!zend_is_true(&_17)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&name, _2, "key", &_zephir_call_cache[13]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&record, _2, "current", &_zephir_call_cache[14]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_19$$11, &manager, "getRelationByAlias", &_zephir_call_cache[15], &className, &name);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&relation, &_19$$11);
				if (Z_TYPE_P(&relation) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD_CACHED(&type, &relation, "getType", &_zephir_call_cache[16]);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG(&type, 0)) {
						if (UNEXPECTED(Z_TYPE_P(&record) != IS_OBJECT)) {
							ZEPHIR_INIT_NVAR(&_20$$14);
							object_init_ex(&_20$$14, phalcon_mvc_model_exceptions_belongstorequiresobject_ce);
							zephir_constructor_start(&_20$$14);
							ZEPHIR_INIT_NVAR(&_21$$14);
							zephir_get_class(&_21$$14, this_ptr, 0);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_20$$14, "__construct", &_zephir_call_cache[17], &_21$$14, &name);
							zephir_check_call_status();
							zephir_constructor_finish(&_20$$14);
							zephir_throw_exception_debug(&_20$$14, "phalcon/Mvc/Model.zep", 6461);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD_CACHED(&_22$$13, &record, "doSave", &_zephir_call_cache[18], visited);
						zephir_check_call_status();
						if (!(zephir_is_true(&_22$$13))) {
							ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessagesFrom", &_zephir_call_cache[19], &record);
							zephir_check_call_status();
							if (nesting) {
								ZVAL_BOOL(&_23$$15, 1);
							} else {
								ZVAL_BOOL(&_23$$15, 0);
							}
							ZEPHIR_CALL_METHOD_CACHED(NULL, connection, "rollback", &_zephir_call_cache[20], &_23$$15);
							zephir_check_call_status();
							RETURN_MM_BOOL(0);
						}
						ZEPHIR_CALL_METHOD_CACHED(&columns, &relation, "getFields", &_zephir_call_cache[21]);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&referencedFields, &relation, "getReferencedFields", &_zephir_call_cache[22]);
						zephir_check_call_status();
						if (UNEXPECTED(Z_TYPE_P(&columns) == IS_ARRAY)) {
							columnCount = (zephir_fast_count_int(&columns) - 1);
							_26$$16 = columnCount;
							_25$$16 = 0;
							_24$$16 = 0;
							if (_25$$16 <= _26$$16) {
								while (1) {
									if (_24$$16) {
										_25$$16++;
										if (!(_25$$16 <= _26$$16)) {
											break;
										}
									} else {
										_24$$16 = 1;
									}
									i = _25$$16;
									ZEPHIR_OBS_NVAR(&columnA);
									zephir_array_fetch_long(&columnA, &columns, i, PH_NOISY, "phalcon/Mvc/Model.zep", 6493);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_OBS_NVAR(&columnB);
									zephir_array_fetch_long(&columnB, &referencedFields, i, PH_NOISY, "phalcon/Mvc/Model.zep", 6494);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_OBS_NVAR(&_27$$17);
									zephir_read_property_zval(&_27$$17, &record, &columnB, PH_NOISY_CC);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_update_property_zval_zval(this_ptr, &columnA, &_27$$17);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
							}
						} else {
							ZEPHIR_OBS_NVAR(&_28$$18);
							zephir_read_property_zval(&_28$$18, &record, &referencedFields, PH_NOISY_CC);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_update_property_zval_zval(this_ptr, &columns, &_28$$18);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					}
				}
		}
	}
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "setModelSchema", &_zephir_call_cache[0], this_ptr, &schema_zv);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "setModelSource", &_zephir_call_cache[0], this_ptr, &source_zv);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &attributes_param);
	zephir_get_arrval(&attributes, attributes_param);
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "skipAttributesOnCreate", &_zephir_call_cache[0], &attributes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "skipAttributesOnUpdate", &_zephir_call_cache[1], &attributes);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[6];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &attributes_param);
	zephir_get_arrval(&attributes, attributes_param);
	ZEPHIR_INIT_VAR(&keysAttributes);
	array_init(&keysAttributes);
	zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model.zep", 6587);
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &attributes, "rewind", &_zephir_call_cache[0]);
		zephir_check_call_status();
		_2 = 1;
		while (1) {
			if (_2) {
				_2 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &attributes, "next", &_zephir_call_cache[1]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_1, &attributes, "valid", &_zephir_call_cache[2]);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&attribute, &attributes, "current", &_zephir_call_cache[3]);
			zephir_check_call_status();
				zephir_array_update_zval(&keysAttributes, &attribute, &__$null, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&_3, this_ptr, "getModelsMetaData", &_zephir_call_cache[4]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_3, "setAutomaticCreateAttributes", &_zephir_call_cache[5], this_ptr, &keysAttributes);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[6];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &attributes_param);
	zephir_get_arrval(&attributes, attributes_param);
	ZEPHIR_INIT_VAR(&keysAttributes);
	array_init(&keysAttributes);
	zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model.zep", 6624);
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &attributes, "rewind", &_zephir_call_cache[0]);
		zephir_check_call_status();
		_2 = 1;
		while (1) {
			if (_2) {
				_2 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &attributes, "next", &_zephir_call_cache[1]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_1, &attributes, "valid", &_zephir_call_cache[2]);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&attribute, &attributes, "current", &_zephir_call_cache[3]);
			zephir_check_call_status();
				zephir_array_update_zval(&keysAttributes, &attribute, &__$null, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&_3, this_ptr, "getModelsMetaData", &_zephir_call_cache[4]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_3, "setAutomaticUpdateAttributes", &_zephir_call_cache[5], this_ptr, &keysAttributes);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (dynamicUpdate) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "useDynamicUpdate", &_zephir_call_cache[0], this_ptr, &_1);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[8];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(validator, phalcon_filter_validation_validationinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &validator);
	ZVAL_NULL(&_0);
	ZEPHIR_CALL_METHOD_CACHED(&messages, validator, "validate", &_zephir_call_cache[0], &_0, this_ptr);
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
		zephir_constructor_start(&_2$$4);
		ZEPHIR_CALL_METHOD_CACHED(&_3$$4, &message, "getMessage", &_zephir_call_cache[1]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_4$$4, &message, "getField", &_zephir_call_cache[2]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_5$$4, &message, "getType", &_zephir_call_cache[3]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_6$$4, &message, "getCode", &_zephir_call_cache[4]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_7$$4, &message, "getMetaData", &_zephir_call_cache[5]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$4, "__construct", &_zephir_call_cache[6], &_3$$4, &_4$$4, &_5$$4, &_6$$4, &_7$$4);
		zephir_check_call_status();
		zephir_constructor_finish(&_2$$4);
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "appendMessage", &_zephir_call_cache[7], &_2$$4);
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

