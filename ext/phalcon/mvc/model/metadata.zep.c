
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
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
 * <code>
 * $metaData = new \Phalcon\Mvc\Model\MetaData\Memory();
 *
 * $attributes = $metaData->getAttributes(
 *     new Robots()
 * );
 *
 * print_r($attributes);
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, MetaData, phalcon, mvc_model_metadata, phalcon_mvc_model_metadata_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var CacheAdapterInterface
	 */
	zend_declare_property_null(phalcon_mvc_model_metadata_ce, SL("adapter"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_metadata_ce, SL("columnMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_metadata_ce, SL("container"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_metadata_ce, SL("metaData"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_metadata_ce, SL("strategy"), ZEND_ACC_PROTECTED TSRMLS_CC);

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

	zend_class_implements(phalcon_mvc_model_metadata_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_mvc_model_metadata_ce TSRMLS_CC, 1, phalcon_mvc_model_metadatainterface_ce);
	return SUCCESS;

}

/**
 * Returns table attributes names (fields)
 *
 *<code>
 * print_r(
 *     $metaData->getAttributes(
 *         new Robots()
 *     )
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAttributes) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", NULL, 11, model, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/Mvc/Model/MetaData.zep", 91);
		return;
	}
	RETURN_CCTOR(&data);

}

/**
 * Returns attributes that must be ignored from the INSERT SQL generation
 *
 *<code>
 * print_r(
 *     $metaData->getAutomaticCreateAttributes(
 *         new Robots()
 *     )
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAutomaticCreateAttributes) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZVAL_LONG(&_0, 10);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", NULL, 11, model, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/Mvc/Model/MetaData.zep", 118);
		return;
	}
	RETURN_CCTOR(&data);

}

/**
 * Returns attributes that must be ignored from the UPDATE SQL generation
 *
 *<code>
 * print_r(
 *     $metaData->getAutomaticUpdateAttributes(
 *         new Robots()
 *     )
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAutomaticUpdateAttributes) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZVAL_LONG(&_0, 11);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", NULL, 11, model, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/Mvc/Model/MetaData.zep", 145);
		return;
	}
	RETURN_CCTOR(&data);

}

/**
 * Returns attributes and their bind data types
 *
 *<code>
 * print_r(
 *     $metaData->getBindTypes(
 *         new Robots()
 *     )
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getBindTypes) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZVAL_LONG(&_0, 9);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", NULL, 11, model, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/Mvc/Model/MetaData.zep", 172);
		return;
	}
	RETURN_CCTOR(&data);

}

/**
 * Returns the column map if any
 *
 *<code>
 * print_r(
 *     $metaData->getColumnMap(
 *         new Robots()
 *     )
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getColumnMap) {

	zend_bool _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readcolumnmapindex", NULL, 12, model, &_0);
	zephir_check_call_status();
	_1 = Z_TYPE_P(&data) != IS_NULL;
	if (_1) {
		_1 = Z_TYPE_P(&data) != IS_ARRAY;
	}
	if (UNEXPECTED(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/Mvc/Model/MetaData.zep", 196);
		return;
	}
	RETURN_CCTOR(&data);

}

/**
 * Returns attributes (which have default values) and their default values
 *
 *<code>
 * print_r(
 *     $metaData->getDefaultValues(
 *         new Robots()
 *     )
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDefaultValues) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZVAL_LONG(&_0, 12);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", NULL, 11, model, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/Mvc/Model/MetaData.zep", 220);
		return;
	}
	RETURN_CCTOR(&data);

}

/**
 * Returns attributes and their data types
 *
 *<code>
 * print_r(
 *     $metaData->getDataTypes(
 *         new Robots()
 *     )
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDataTypes) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", NULL, 11, model, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/Mvc/Model/MetaData.zep", 244);
		return;
	}
	RETURN_CCTOR(&data);

}

/**
 * Returns attributes which types are numerical
 *
 *<code>
 * print_r(
 *     $metaData->getDataTypesNumeric(
 *         new Robots()
 *     )
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDataTypesNumeric) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZVAL_LONG(&_0, 5);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", NULL, 11, model, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/Mvc/Model/MetaData.zep", 271);
		return;
	}
	RETURN_CCTOR(&data);

}

/**
 * Returns the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDI) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "container");

}

/**
 * Returns attributes allow empty strings
 *
 *<code>
 * print_r(
 *     $metaData->getEmptyStringAttributes(
 *         new Robots()
 *     )
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getEmptyStringAttributes) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZVAL_LONG(&_0, 13);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", NULL, 11, model, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/Mvc/Model/MetaData.zep", 306);
		return;
	}
	RETURN_CCTOR(&data);

}

/**
 * Returns the name of identity field (if one is present)
 *
 *<code>
 * print_r(
 *     $metaData->getIdentityField(
 *         new Robots()
 *     )
 * );
 *</code>
 *
 * @param  Phalcon\Mvc\ModelInterface model
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getIdentityField) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZVAL_LONG(&_0, 8);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "readmetadataindex", NULL, 11, model, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns an array of fields which are not part of the primary key
 *
 *<code>
 * print_r(
 *     $metaData->getNonPrimaryKeyAttributes(
 *         new Robots()
 *     )
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getNonPrimaryKeyAttributes) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZVAL_LONG(&_0, 2);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", NULL, 11, model, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/Mvc/Model/MetaData.zep", 349);
		return;
	}
	RETURN_CCTOR(&data);

}

/**
 * Returns an array of not null attributes
 *
 *<code>
 * print_r(
 *     $metaData->getNotNullAttributes(
 *         new Robots()
 *     )
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getNotNullAttributes) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZVAL_LONG(&_0, 3);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", NULL, 11, model, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/Mvc/Model/MetaData.zep", 373);
		return;
	}
	RETURN_CCTOR(&data);

}

/**
 * Returns an array of fields which are part of the primary key
 *
 *<code>
 * print_r(
 *     $metaData->getPrimaryKeyAttributes(
 *         new Robots()
 *     )
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getPrimaryKeyAttributes) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZVAL_LONG(&_0, 1);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", NULL, 11, model, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/Mvc/Model/MetaData.zep", 397);
		return;
	}
	RETURN_CCTOR(&data);

}

/**
 * Returns the reverse column map if any
 *
 *<code>
 * print_r(
 *     $metaData->getReverseColumnMap(
 *         new Robots()
 *     )
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getReverseColumnMap) {

	zend_bool _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZVAL_LONG(&_0, 1);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readcolumnmapindex", NULL, 12, model, &_0);
	zephir_check_call_status();
	_1 = Z_TYPE_P(&data) != IS_NULL;
	if (_1) {
		_1 = Z_TYPE_P(&data) != IS_ARRAY;
	}
	if (UNEXPECTED(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/Mvc/Model/MetaData.zep", 424);
		return;
	}
	RETURN_CCTOR(&data);

}

/**
 * Return the strategy to obtain the meta-data
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getStrategy) {

	zval _0, _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("strategy"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_metadata_strategy_introspection_ce);
		if (zephir_has_constructor(&_1$$3 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_property_zval(this_ptr, SL("strategy"), &_1$$3);
	}
	RETURN_MM_MEMBER(getThis(), "strategy");

}

/**
 * Check if a model has certain attribute
 *
 *<code>
 * var_dump(
 *     $metaData->hasAttribute(
 *         new Robots(),
 *         "name"
 *     )
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, hasAttribute) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attribute;
	zval *model, model_sub, *attribute_param = NULL, columnMap, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&attribute);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &attribute_param);

	zephir_get_strval(&attribute, attribute_param);


	ZEPHIR_CALL_METHOD(&columnMap, this_ptr, "getreversecolumnmap", NULL, 0, model);
	zephir_check_call_status();
	if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
		RETURN_MM_BOOL(zephir_array_isset(&columnMap, &attribute));
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "readmetadata", NULL, 13, model);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, &_0, 4, PH_READONLY, "phalcon/Mvc/Model/MetaData.zep", 464 TSRMLS_CC);
	RETURN_MM_BOOL(zephir_array_isset(&_1, &attribute));

}

/**
 * Checks if the internal meta-data container is empty
 *
 *<code>
 * var_dump(
 *     $metaData->isEmpty()
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, isEmpty) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("metaData"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_fast_count_int(&_0 TSRMLS_CC) == 0);

}

/**
 * Reads metadata from the adapter
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, read) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

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


	zephir_read_property(&_0, this_ptr, SL("adapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Reads the ordered/reversed column map for certain model
 *
 *<code>
 * print_r(
 *     $metaData->readColumnMap(
 *         new Robots()
 *     )
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, readColumnMap) {

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	if (!(ZEPHIR_GLOBAL(orm).column_renaming)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&keyName);
	zephir_get_class(&keyName, model, 1 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&data);
	zephir_read_property(&_0, this_ptr, SL("columnMap"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&data, &_0, &keyName, 0 TSRMLS_CC))) {
		ZVAL_NULL(&_1$$4);
		ZVAL_NULL(&_2$$4);
		ZVAL_NULL(&_3$$4);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 14, model, &_1$$4, &_2$$4, &_3$$4);
		zephir_check_call_status();
		zephir_read_property(&_1$$4, this_ptr, SL("columnMap"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&data);
		zephir_array_fetch(&data, &_1$$4, &keyName, PH_NOISY, "phalcon/Mvc/Model/MetaData.zep", 513 TSRMLS_CC);
	}
	RETURN_CCTOR(&data);

}

/**
 * Reads column-map information for certain model using a MODEL_* constant
 *
 *<code>
 * print_r(
 *     $metaData->readColumnMapIndex(
 *         new Robots(),
 *         MetaData::MODELS_REVERSE_COLUMN_MAP
 *     )
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, readColumnMapIndex) {

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &index_param);

	index = zephir_get_intval(index_param);


	if (!(ZEPHIR_GLOBAL(orm).column_renaming)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&keyName);
	zephir_get_class(&keyName, model, 1 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&columnMapModel);
	zephir_read_property(&_0, this_ptr, SL("columnMap"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&columnMapModel, &_0, &keyName, 0 TSRMLS_CC))) {
		ZVAL_NULL(&_1$$4);
		ZVAL_NULL(&_2$$4);
		ZVAL_NULL(&_3$$4);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 14, model, &_1$$4, &_2$$4, &_3$$4);
		zephir_check_call_status();
		zephir_read_property(&_1$$4, this_ptr, SL("columnMap"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&columnMapModel);
		zephir_array_fetch(&columnMapModel, &_1$$4, &keyName, PH_NOISY, "phalcon/Mvc/Model/MetaData.zep", 544 TSRMLS_CC);
	}
	zephir_array_isset_long_fetch(&map, &columnMapModel, index, 1 TSRMLS_CC);
	RETURN_CTOR(&map);

}

/**
 * Reads the complete meta-data for certain model
 *
 *<code>
 * print_r(
 *     $metaData->readMetaData(
 *         new Robots()
 *     )
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, readMetaData) {

	zval key;
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_CALL_METHOD(&source, model, "getsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&schema, model, "getschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, model, 1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VSVV(&_1, &_0, "-", &schema, &source);
	zephir_get_strval(&key, &_1);
	zephir_read_property(&_2, this_ptr, SL("metaData"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_2, &key))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 14, model, &key, &source, &schema);
		zephir_check_call_status();
	}
	zephir_read_property(&_3, this_ptr, SL("metaData"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, &key, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/MetaData.zep", 580 TSRMLS_CC);
	RETURN_CTOR(&_4);

}

/**
 * Reads meta-data for certain model
 *
 *<code>
 * print_r(
 *     $metaData->readMetaDataIndex(
 *         new Robots(),
 *         0
 *     )
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, readMetaDataIndex) {

	zval key;
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &index_param);

	index = zephir_get_intval(index_param);


	ZEPHIR_CALL_METHOD(&source, model, "getsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&schema, model, "getschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, model, 1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VSVV(&_1, &_0, "-", &schema, &source);
	zephir_get_strval(&key, &_1);
	zephir_read_property(&_2, this_ptr, SL("metaData"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_3, &_2, &key, PH_READONLY, "phalcon/Mvc/Model/MetaData.zep", 608 TSRMLS_CC);
	if (!(zephir_array_isset_long(&_3, index))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 14, model, &key, &source, &schema);
		zephir_check_call_status();
	}
	zephir_read_property(&_4, this_ptr, SL("metaData"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_5, &_4, &key, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/MetaData.zep", 612 TSRMLS_CC);
	zephir_array_fetch_long(&_6, &_5, index, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/MetaData.zep", 612 TSRMLS_CC);
	RETURN_CTOR(&_6);

}

/**
 * Resets internal meta-data in order to regenerate it
 *
 *<code>
 * $metaData->reset();
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, reset) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("metaData"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, SL("columnMap"), &_1);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set the attributes that must be ignored from the INSERT SQL generation
 *
 *<code>
 * $metaData->setAutomaticCreateAttributes(
 *     new Robots(),
 *     [
 *         "created_at" => true,
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, setAutomaticCreateAttributes) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval *model, model_sub, *attributes_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&attributes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &attributes_param);

	zephir_get_arrval(&attributes, attributes_param);


	ZVAL_LONG(&_0, 10);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "writemetadataindex", NULL, 15, model, &_0, &attributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Set the attributes that must be ignored from the UPDATE SQL generation
 *
 *<code>
 * $metaData->setAutomaticUpdateAttributes(
 *     new Robots(),
 *     [
 *         "modified_at" => true,
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, setAutomaticUpdateAttributes) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval *model, model_sub, *attributes_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&attributes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &attributes_param);

	zephir_get_arrval(&attributes, attributes_param);


	ZVAL_LONG(&_0, 11);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "writemetadataindex", NULL, 15, model, &_0, &attributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Set the attributes that allow empty string values
 *
 *<code>
 * $metaData->setEmptyStringAttributes(
 *     new Robots(),
 *     [
 *         "name" => true,
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, setEmptyStringAttributes) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval *model, model_sub, *attributes_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&attributes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &attributes_param);

	zephir_get_arrval(&attributes, attributes_param);


	ZVAL_LONG(&_0, 13);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "writemetadataindex", NULL, 15, model, &_0, &attributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, setDI) {

	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	zephir_fetch_params(0, 1, 0, &container);



	zephir_update_property_zval(this_ptr, SL("container"), container);

}

/**
 * Set the meta-data extraction strategy
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, setStrategy) {

	zval *strategy, strategy_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strategy_sub);

	zephir_fetch_params(0, 1, 0, &strategy);



	zephir_update_property_zval(this_ptr, SL("strategy"), strategy);

}

/**
 * Writes the metadata to adapter
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, write) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *key_param = NULL, *data_param = NULL, result, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &data_param);

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
	zephir_get_arrval(&data, data_param);


	zephir_read_property(&_0, this_ptr, SL("adapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, &_0, "set", NULL, 0, &key, &data);
	zephir_check_call_status();
	if (!(zephir_is_true(&result))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Failed to store metaData to the cache adapter.", "phalcon/Mvc/Model/MetaData.zep", 719);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Writes meta-data for certain model using a MODEL_* constant
 *
 *<code>
 * print_r(
 *     $metaData->writeColumnMapIndex(
 *         new Robots(),
 *         MetaData::MODELS_REVERSE_COLUMN_MAP,
 *         [
 *             "leName" => "name",
 *         ]
 *     )
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, writeMetaDataIndex) {

	zend_bool _0, _1;
	zval key;
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid data for index", "phalcon/Mvc/Model/MetaData.zep", 744);
		return;
	}
	ZEPHIR_CALL_METHOD(&source, model, "getsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&schema, model, "getschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_get_class(&_2, model, 1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VSVV(&_3, &_2, "-", &schema, &source);
	zephir_get_strval(&key, &_3);
	zephir_read_property(&_4, this_ptr, SL("metaData"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_4, &key))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 14, model, &key, &source, &schema);
		zephir_check_call_status();
	}
	zephir_update_property_array_multi(this_ptr, SL("metaData"), data TSRMLS_CC, SL("zl"), 2, &key, index);
	ZEPHIR_MM_RESTORE();

}

/**
 * Initialize the metadata for certain table
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, initialize) {

	zval prefixKey;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, *key, key_sub, *table, table_sub, *schema, schema_sub, strategy, className, metaData, data, modelMetadata, modelColumnMap, container, keyName, _5, _6, _0$$3, _1$$4, _2$$8, _3$$8, _4$$9, _7$$13;
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
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$8);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_7$$13);
	ZVAL_UNDEF(&prefixKey);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &model, &key, &table, &schema);



	ZEPHIR_INIT_VAR(&strategy);
	ZVAL_NULL(&strategy);
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, model, 0 TSRMLS_CC);
	if (Z_TYPE_P(key) != IS_NULL) {
		zephir_read_property(&_0$$3, this_ptr, SL("metaData"), PH_NOISY_CC | PH_READONLY);
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
				if ((zephir_method_exists_ex(model, SL("metadata") TSRMLS_CC) == SUCCESS)) {
					ZEPHIR_CALL_METHOD(&modelMetadata, model, "metadata", NULL, 0);
					zephir_check_call_status();
					if (UNEXPECTED(Z_TYPE_P(&modelMetadata) != IS_ARRAY)) {
						ZEPHIR_INIT_VAR(&_2$$8);
						object_init_ex(&_2$$8, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_VAR(&_3$$8);
						ZEPHIR_CONCAT_SV(&_3$$8, "Invalid meta-data for model ", &className);
						ZEPHIR_CALL_METHOD(NULL, &_2$$8, "__construct", NULL, 1, &_3$$8);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_2$$8, "phalcon/Mvc/Model/MetaData.zep", 796 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					zephir_read_property(&_4$$9, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CPY_WRT(&container, &_4$$9);
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
	zephir_read_property(&_5, this_ptr, SL("columnMap"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_5, &keyName)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CONCAT_SV(&_6, "map-", &keyName);
	zephir_get_strval(&prefixKey, &_6);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "read", NULL, 0, &prefixKey);
	zephir_check_call_status();
	if (Z_TYPE_P(&data) != IS_NULL) {
		zephir_update_property_array(this_ptr, SL("columnMap"), &keyName, &data);
		RETURN_MM_NULL();
	}
	if (Z_TYPE_P(&strategy) != IS_OBJECT) {
		zephir_read_property(&_7$$13, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&container, &_7$$13);
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

