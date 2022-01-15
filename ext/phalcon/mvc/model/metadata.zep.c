
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
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\MetaData
 *
 * Because Phalcon\Mvc\Model requires meta-data like field names, data types,
 * primary keys, etc. This component collect them and store for further
 * querying by Phalcon\Mvc\Model. Phalcon\Mvc\Model\MetaData can also use
 * adapters to store temporarily or permanently the meta-data.
 *
 * A standard Phalcon\Mvc\Model\MetaData can be used to query model attributes:
 *
 * ```php
 * $metaData = new \Phalcon\Mvc\Model\MetaData\Memory();
 *
 * $attributes = $metaData->getAttributes(
 *     new Robots()
 * );
 *
 * print_r($attributes);
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, MetaData, phalcon, mvc_model_metadata, phalcon_mvc_model_metadata_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var CacheAdapterInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_model_metadata_ce, SL("adapter"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_metadata_ce, SL("columnMap"), ZEND_ACC_PROTECTED);
	/**
	 * @var DiInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_model_metadata_ce, SL("container"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_metadata_ce, SL("metaData"), ZEND_ACC_PROTECTED);
	/**
	 * @var StrategyInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_model_metadata_ce, SL("strategy"), ZEND_ACC_PROTECTED);
	phalcon_mvc_model_metadata_ce->create_object = zephir_init_properties_Phalcon_Mvc_Model_MetaData;
	zephir_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_ATTRIBUTES"), 0);

	zephir_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_AUTOMATIC_DEFAULT_INSERT"), 10);

	zephir_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_AUTOMATIC_DEFAULT_UPDATE"), 11);

	zephir_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_COLUMN_MAP"), 0);

	zephir_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_DATE_AT"), 6);

	zephir_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_DATE_IN"), 7);

	zephir_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_DATA_TYPES"), 4);

	zephir_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_DATA_TYPES_BIND"), 9);

	zephir_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_DATA_TYPES_NUMERIC"), 5);

	zephir_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_DEFAULT_VALUES"), 12);

	zephir_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_EMPTY_STRING_VALUES"), 13);

	zephir_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_IDENTITY_COLUMN"), 8);

	zephir_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_NON_PRIMARY_KEY"), 2);

	zephir_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_NOT_NULL"), 3);

	zephir_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_PRIMARY_KEY"), 1);

	zephir_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_REVERSE_COLUMN_MAP"), 1);

	zend_class_implements(phalcon_mvc_model_metadata_ce, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_mvc_model_metadata_ce, 1, phalcon_mvc_model_metadatainterface_ce);
	return SUCCESS;
}

/**
 * Returns table attributes names (fields)
 *
 *```php
 * print_r(
 *     $metaData->getAttributes(
 *         new Robots()
 *     )
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAttributes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);


	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", NULL, 25, model, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/Mvc/Model/MetaData.zep", 102);
		return;
	}
	RETURN_CCTOR(&data);
}

/**
 * Returns attributes that must be ignored from the INSERT SQL generation
 *
 *```php
 * print_r(
 *     $metaData->getAutomaticCreateAttributes(
 *         new Robots()
 *     )
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAutomaticCreateAttributes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);


	ZVAL_LONG(&_0, 10);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", NULL, 25, model, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/Mvc/Model/MetaData.zep", 129);
		return;
	}
	RETURN_CCTOR(&data);
}

/**
 * Returns attributes that must be ignored from the UPDATE SQL generation
 *
 *```php
 * print_r(
 *     $metaData->getAutomaticUpdateAttributes(
 *         new Robots()
 *     )
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAutomaticUpdateAttributes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);


	ZVAL_LONG(&_0, 11);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", NULL, 25, model, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/Mvc/Model/MetaData.zep", 156);
		return;
	}
	RETURN_CCTOR(&data);
}

/**
 * Returns attributes and their bind data types
 *
 *```php
 * print_r(
 *     $metaData->getBindTypes(
 *         new Robots()
 *     )
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getBindTypes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);


	ZVAL_LONG(&_0, 9);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", NULL, 25, model, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/Mvc/Model/MetaData.zep", 183);
		return;
	}
	RETURN_CCTOR(&data);
}

/**
 * Returns the column map if any
 *
 *```php
 * print_r(
 *     $metaData->getColumnMap(
 *         new Robots()
 *     )
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getColumnMap)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);


	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readcolumnmapindex", NULL, 26, model, &_0);
	zephir_check_call_status();
	_1 = Z_TYPE_P(&data) != IS_NULL;
	if (_1) {
		_1 = Z_TYPE_P(&data) != IS_ARRAY;
	}
	if (UNEXPECTED(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/Mvc/Model/MetaData.zep", 207);
		return;
	}
	RETURN_CCTOR(&data);
}

/**
 * Returns attributes (which have default values) and their default values
 *
 *```php
 * print_r(
 *     $metaData->getDefaultValues(
 *         new Robots()
 *     )
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDefaultValues)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);


	ZVAL_LONG(&_0, 12);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", NULL, 25, model, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/Mvc/Model/MetaData.zep", 231);
		return;
	}
	RETURN_CCTOR(&data);
}

/**
 * Returns attributes and their data types
 *
 *```php
 * print_r(
 *     $metaData->getDataTypes(
 *         new Robots()
 *     )
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDataTypes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);


	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", NULL, 25, model, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/Mvc/Model/MetaData.zep", 255);
		return;
	}
	RETURN_CCTOR(&data);
}

/**
 * Returns attributes which types are numerical
 *
 *```php
 * print_r(
 *     $metaData->getDataTypesNumeric(
 *         new Robots()
 *     )
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDataTypesNumeric)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);


	ZVAL_LONG(&_0, 5);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", NULL, 25, model, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/Mvc/Model/MetaData.zep", 282);
		return;
	}
	RETURN_CCTOR(&data);
}

/**
 * Returns the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDI)
{
	zval container, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injection container is required to access internal services", "phalcon/Mvc/Model/MetaData.zep", 300);
		return;
	}
	RETURN_CCTOR(&container);
}

/**
 * Returns attributes allow empty strings
 *
 *```php
 * print_r(
 *     $metaData->getEmptyStringAttributes(
 *         new Robots()
 *     )
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getEmptyStringAttributes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);


	ZVAL_LONG(&_0, 13);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", NULL, 25, model, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/Mvc/Model/MetaData.zep", 327);
		return;
	}
	RETURN_CCTOR(&data);
}

/**
 * Returns the name of identity field (if one is present)
 *
 *```php
 * print_r(
 *     $metaData->getIdentityField(
 *         new Robots()
 *     )
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getIdentityField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);


	ZVAL_LONG(&_0, 8);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "readmetadataindex", NULL, 25, model, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns an array of fields which are not part of the primary key
 *
 *```php
 * print_r(
 *     $metaData->getNonPrimaryKeyAttributes(
 *         new Robots()
 *     )
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getNonPrimaryKeyAttributes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);


	ZVAL_LONG(&_0, 2);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", NULL, 25, model, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/Mvc/Model/MetaData.zep", 367);
		return;
	}
	RETURN_CCTOR(&data);
}

/**
 * Returns an array of not null attributes
 *
 *```php
 * print_r(
 *     $metaData->getNotNullAttributes(
 *         new Robots()
 *     )
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getNotNullAttributes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);


	ZVAL_LONG(&_0, 3);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", NULL, 25, model, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/Mvc/Model/MetaData.zep", 391);
		return;
	}
	RETURN_CCTOR(&data);
}

/**
 * Returns an array of fields which are part of the primary key
 *
 *```php
 * print_r(
 *     $metaData->getPrimaryKeyAttributes(
 *         new Robots()
 *     )
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getPrimaryKeyAttributes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);


	ZVAL_LONG(&_0, 1);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", NULL, 25, model, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/Mvc/Model/MetaData.zep", 415);
		return;
	}
	RETURN_CCTOR(&data);
}

/**
 * Returns the reverse column map if any
 *
 *```php
 * print_r(
 *     $metaData->getReverseColumnMap(
 *         new Robots()
 *     )
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getReverseColumnMap)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);


	ZVAL_LONG(&_0, 1);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readcolumnmapindex", NULL, 26, model, &_0);
	zephir_check_call_status();
	_1 = Z_TYPE_P(&data) != IS_NULL;
	if (_1) {
		_1 = Z_TYPE_P(&data) != IS_ARRAY;
	}
	if (UNEXPECTED(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/Mvc/Model/MetaData.zep", 442);
		return;
	}
	RETURN_CCTOR(&data);
}

/**
 * Return the strategy to obtain the meta-data
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getStrategy)
{
	zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("strategy"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_metadata_strategy_introspection_ce);
		if (zephir_has_constructor(&_1$$3)) {
			ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		zephir_update_property_zval(this_ptr, ZEND_STRL("strategy"), &_1$$3);
	}
	RETURN_MM_MEMBER(getThis(), "strategy");
}

/**
 * Check if a model has certain attribute
 *
 *```php
 * var_dump(
 *     $metaData->hasAttribute(
 *         new Robots(),
 *         "name"
 *     )
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, hasAttribute)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attribute;
	zval *model, model_sub, *attribute_param = NULL, columnMap, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&attribute);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
		Z_PARAM_STR(attribute)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &attribute_param);
	zephir_get_strval(&attribute, attribute_param);


	ZEPHIR_CALL_METHOD(&columnMap, this_ptr, "getreversecolumnmap", NULL, 0, model);
	zephir_check_call_status();
	if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
		RETURN_MM_BOOL(zephir_array_isset(&columnMap, &attribute));
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "readmetadata", NULL, 27, model);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, &_0, 4, PH_READONLY, "phalcon/Mvc/Model/MetaData.zep", 482);
	RETURN_MM_BOOL(zephir_array_isset(&_1, &attribute));
}

/**
 * Checks if the internal meta-data container is empty
 *
 *```php
 * var_dump(
 *     $metaData->isEmpty()
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, isEmpty)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("metaData"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_fast_count_int(&_0) == 0);
}

/**
 * Reads metadata from the adapter
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, read)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);
	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &key);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Reads the ordered/reversed column map for certain model
 *
 *```php
 * print_r(
 *     $metaData->readColumnMap(
 *         new Robots()
 *     )
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, readColumnMap)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, keyName, data, _0, _1$$4, _2$$4, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&keyName);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);


	if (!(ZEPHIR_GLOBAL(orm).column_renaming)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&keyName);
	zephir_get_class(&keyName, model, 1);
	ZEPHIR_OBS_VAR(&data);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("columnMap"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&data, &_0, &keyName, 0))) {
		ZVAL_NULL(&_1$$4);
		ZVAL_NULL(&_2$$4);
		ZVAL_NULL(&_3$$4);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 28, model, &_1$$4, &_2$$4, &_3$$4);
		zephir_check_call_status();
		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("columnMap"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&data);
		zephir_array_fetch(&data, &_1$$4, &keyName, PH_NOISY, "phalcon/Mvc/Model/MetaData.zep", 531);
	}
	RETURN_CCTOR(&data);
}

/**
 * Reads column-map information for certain model using a MODEL_* constant
 *
 *```php
 * print_r(
 *     $metaData->readColumnMapIndex(
 *         new Robots(),
 *         MetaData::MODELS_REVERSE_COLUMN_MAP
 *     )
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, readColumnMapIndex)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long index, ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, *index_param = NULL, keyName, columnMapModel, map, _0, _1$$4, _2$$4, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&keyName);
	ZVAL_UNDEF(&columnMapModel);
	ZVAL_UNDEF(&map);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
		Z_PARAM_LONG(index)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &index_param);
	index = zephir_get_intval(index_param);


	if (!(ZEPHIR_GLOBAL(orm).column_renaming)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&keyName);
	zephir_get_class(&keyName, model, 1);
	ZEPHIR_OBS_VAR(&columnMapModel);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("columnMap"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&columnMapModel, &_0, &keyName, 0))) {
		ZVAL_NULL(&_1$$4);
		ZVAL_NULL(&_2$$4);
		ZVAL_NULL(&_3$$4);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 28, model, &_1$$4, &_2$$4, &_3$$4);
		zephir_check_call_status();
		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("columnMap"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&columnMapModel);
		zephir_array_fetch(&columnMapModel, &_1$$4, &keyName, PH_NOISY, "phalcon/Mvc/Model/MetaData.zep", 562);
	}
	zephir_array_isset_long_fetch(&map, &columnMapModel, index, 1);
	RETURN_CTOR(&map);
}

/**
 * Reads the complete meta-data for certain model
 *
 *```php
 * print_r(
 *     $metaData->readMetaData(
 *         new Robots()
 *     )
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, readMetaData)
{
	zval key;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, source, schema, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&key);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);


	ZEPHIR_CALL_METHOD(&source, model, "getsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&schema, model, "getschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, model, 1);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VSVV(&_1, &_0, "-", &schema, &source);
	zephir_get_strval(&key, &_1);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("metaData"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_2, &key))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 28, model, &key, &source, &schema);
		zephir_check_call_status();
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("metaData"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, &key, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/MetaData.zep", 598);
	RETURN_CTOR(&_4);
}

/**
 * Reads meta-data for certain model
 *
 *```php
 * print_r(
 *     $metaData->readMetaDataIndex(
 *         new Robots(),
 *         0
 *     )
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, readMetaDataIndex)
{
	zval key;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long index, ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, *index_param = NULL, source, schema, _0, _1, _2, _3, _4, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&key);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
		Z_PARAM_LONG(index)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &index_param);
	index = zephir_get_intval(index_param);


	ZEPHIR_CALL_METHOD(&source, model, "getsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&schema, model, "getschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, model, 1);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VSVV(&_1, &_0, "-", &schema, &source);
	zephir_get_strval(&key, &_1);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("metaData"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_3, &_2, &key, PH_READONLY, "phalcon/Mvc/Model/MetaData.zep", 626);
	if (!(zephir_array_isset_long(&_3, index))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 28, model, &key, &source, &schema);
		zephir_check_call_status();
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("metaData"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_5, &_4, &key, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/MetaData.zep", 630);
	zephir_array_fetch_long(&_6, &_5, index, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/MetaData.zep", 630);
	RETURN_CTOR(&_6);
}

/**
 * Resets internal meta-data in order to regenerate it
 *
 *```php
 * $metaData->reset();
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, reset)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("metaData"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, ZEND_STRL("columnMap"), &_1);
	ZEPHIR_MM_RESTORE();
}

/**
 * Set the attributes that must be ignored from the INSERT SQL generation
 *
 *```php
 * $metaData->setAutomaticCreateAttributes(
 *     new Robots(),
 *     [
 *         "created_at" => true,
 *     ]
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, setAutomaticCreateAttributes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval *model, model_sub, *attributes_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&attributes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &attributes_param);
	zephir_get_arrval(&attributes, attributes_param);


	ZVAL_LONG(&_0, 10);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "writemetadataindex", NULL, 29, model, &_0, &attributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Set the attributes that must be ignored from the UPDATE SQL generation
 *
 *```php
 * $metaData->setAutomaticUpdateAttributes(
 *     new Robots(),
 *     [
 *         "modified_at" => true,
 *     ]
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, setAutomaticUpdateAttributes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval *model, model_sub, *attributes_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&attributes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &attributes_param);
	zephir_get_arrval(&attributes, attributes_param);


	ZVAL_LONG(&_0, 11);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "writemetadataindex", NULL, 29, model, &_0, &attributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Set the attributes that allow empty string values
 *
 *```php
 * $metaData->setEmptyStringAttributes(
 *     new Robots(),
 *     [
 *         "name" => true,
 *     ]
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, setEmptyStringAttributes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval *model, model_sub, *attributes_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&attributes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &attributes_param);
	zephir_get_arrval(&attributes, attributes_param);


	ZVAL_LONG(&_0, 13);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "writemetadataindex", NULL, 29, model, &_0, &attributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, setDI)
{
	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &container);


	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), container);
}

/**
 * Set the meta-data extraction strategy
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, setStrategy)
{
	zval *strategy, strategy_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strategy_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(strategy, phalcon_mvc_model_metadata_strategy_strategyinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &strategy);


	zephir_update_property_zval(this_ptr, ZEND_STRL("strategy"), strategy);
}

/**
 * Writes the metadata to adapter
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, write)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *key_param = NULL, *data_param = NULL, result, option, _1, _2, _0$$3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&data);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_ARRAY(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &data_param);
	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
	}
	zephir_get_arrval(&data, data_param);



	/* try_start_1: */

		ZEPHIR_INIT_VAR(&option);
		ZVAL_BOOL(&option, ZEPHIR_GLOBAL(orm).exception_on_failed_metadata_save);
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&result, &_0$$3, "set", NULL, 0, &key, &data);
		zephir_check_call_status_or_jump(try_end_1);
		if (ZEPHIR_IS_FALSE_IDENTICAL(&result)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwwriteexception", NULL, 30, &option);
			zephir_check_call_status_or_jump(try_end_1);
		}

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_1);
		ZVAL_OBJ(&_1, EG(exception));
		Z_ADDREF_P(&_1);
		ZEPHIR_INIT_VAR(&_2);
		if (zephir_is_instance_of(&_1, SL("Exception"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&_2, &_1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwwriteexception", NULL, 30, &option);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Writes meta-data for certain model using a MODEL_* constant
 *
 *```php
 * print_r(
 *     $metaData->writeColumnMapIndex(
 *         new Robots(),
 *         MetaData::MODELS_REVERSE_COLUMN_MAP,
 *         [
 *             "leName" => "name",
 *         ]
 *     )
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, writeMetaDataIndex)
{
	zend_bool _0, _1;
	zval key;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long index, ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, *index_param = NULL, *data, data_sub, source, schema, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&key);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
		Z_PARAM_LONG(index)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &model, &index_param, &data);
	index = zephir_get_intval(index_param);


	_0 = Z_TYPE_P(data) != IS_ARRAY;
	if (_0) {
		_0 = Z_TYPE_P(data) != IS_STRING;
	}
	_1 = _0;
	if (_1) {
		_1 = ((Z_TYPE_P(data) == IS_TRUE || Z_TYPE_P(data) == IS_FALSE) != 1);
	}
	if (UNEXPECTED(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid data for index", "phalcon/Mvc/Model/MetaData.zep", 765);
		return;
	}
	ZEPHIR_CALL_METHOD(&source, model, "getsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&schema, model, "getschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_get_class(&_2, model, 1);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VSVV(&_3, &_2, "-", &schema, &source);
	zephir_get_strval(&key, &_3);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("metaData"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_4, &key))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 28, model, &key, &source, &schema);
		zephir_check_call_status();
	}
	zephir_update_property_array_multi(this_ptr, SL("metaData"), data, SL("zl"), 2, &key, index);
	ZEPHIR_MM_RESTORE();
}

/**
 * Initialize the metadata for certain table
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, initialize)
{
	zval prefixKey;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, *key, key_sub, *table, table_sub, *schema, schema_sub, strategy, className, metaData, data, modelMetadata, modelColumnMap, container, keyName, _4, _5, _0$$3, _1$$4, _2$$8, _3$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&schema_sub);
	ZVAL_UNDEF(&strategy);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&modelMetadata);
	ZVAL_UNDEF(&modelColumnMap);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&keyName);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$8);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&prefixKey);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
		Z_PARAM_ZVAL(key)
		Z_PARAM_ZVAL(table)
		Z_PARAM_ZVAL(schema)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &model, &key, &table, &schema);


	ZEPHIR_INIT_VAR(&strategy);
	ZVAL_NULL(&strategy);
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, model, 0);
	if (Z_TYPE_P(key) != IS_NULL) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("metaData"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&metaData, &_0$$3);
		if (!(zephir_array_isset(&metaData, key))) {
			ZEPHIR_INIT_VAR(&_1$$4);
			ZEPHIR_CONCAT_SV(&_1$$4, "meta-", key);
			zephir_get_strval(&prefixKey, &_1$$4);
			ZEPHIR_CALL_METHOD(&data, this_ptr, "read", NULL, 0, &prefixKey);
			zephir_check_call_status();
			if (Z_TYPE_P(&data) != IS_NULL) {
				zephir_update_property_array(this_ptr, SL("metaData"), key, &data);
			} else {
				if ((zephir_method_exists_ex(model, ZEND_STRL("metadata")) == SUCCESS)) {
					ZEPHIR_CALL_METHOD(&modelMetadata, model, "metadata", NULL, 0);
					zephir_check_call_status();
					if (UNEXPECTED(Z_TYPE_P(&modelMetadata) != IS_ARRAY)) {
						ZEPHIR_INIT_VAR(&_2$$8);
						object_init_ex(&_2$$8, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_VAR(&_3$$8);
						ZEPHIR_CONCAT_SV(&_3$$8, "Invalid meta-data for model ", &className);
						ZEPHIR_CALL_METHOD(NULL, &_2$$8, "__construct", NULL, 31, &_3$$8);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_2$$8, "phalcon/Mvc/Model/MetaData.zep", 817);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CALL_METHOD(&container, this_ptr, "getdi", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&strategy, this_ptr, "getstrategy", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&modelMetadata, &strategy, "getmetadata", NULL, 0, model, &container);
					zephir_check_call_status();
				}
				zephir_update_property_array(this_ptr, SL("metaData"), key, &modelMetadata);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &prefixKey, &modelMetadata);
				zephir_check_call_status();
			}
		}
	}
	if (!(ZEPHIR_GLOBAL(orm).column_renaming)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&keyName);
	zephir_fast_strtolower(&keyName, &className);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("columnMap"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_4, &keyName)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_SV(&_5, "map-", &keyName);
	zephir_get_strval(&prefixKey, &_5);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "read", NULL, 0, &prefixKey);
	zephir_check_call_status();
	if (Z_TYPE_P(&data) != IS_NULL) {
		zephir_update_property_array(this_ptr, SL("columnMap"), &keyName, &data);
		RETURN_MM_NULL();
	}
	if (Z_TYPE_P(&strategy) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&container, this_ptr, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&strategy, this_ptr, "getstrategy", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&modelColumnMap, &strategy, "getcolumnmaps", NULL, 0, model, &container);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("columnMap"), &keyName, &modelColumnMap);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &prefixKey, &modelColumnMap);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Throws an exception when the metadata cannot be written
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, throwWriteException)
{
	zval message;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *option, option_sub, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&message);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(option)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &option);


	ZEPHIR_INIT_VAR(&message);
	ZVAL_STRING(&message, "Failed to store metaData to the cache adapter");
	if (zephir_is_true(option)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_model_exception_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 31, &message);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/MetaData.zep", 901);
		ZEPHIR_MM_RESTORE();
		return;
	} else {
		ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 7, &message);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * @todo Remove this when we get traits
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getArrVal)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *collection_param = NULL, *index, index_sub, *defaultValue = NULL, defaultValue_sub, __$null, value;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ARRAY(collection)
		Z_PARAM_ZVAL(index)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &collection_param, &index, &defaultValue);
	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	if (UNEXPECTED(!(zephir_array_isset_fetch(&value, &collection, index, 1)))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	RETURN_CTOR(&value);
}

zend_object *zephir_init_properties_Phalcon_Mvc_Model_MetaData(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("metaData"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("metaData"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("columnMap"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("columnMap"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

