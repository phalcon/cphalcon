
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/exception.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Mvc\Model\MetaData
 *
 * <p>Because Phalcon\Mvc\Model requires meta-data like field names, data types, primary keys, etc.
 * this component collect them and store for further querying by Phalcon\Mvc\Model.
 * Phalcon\Mvc\Model\MetaData can also use adapters to store temporarily or permanently the meta-data.</p>
 *
 * <p>A standard Phalcon\Mvc\Model\MetaData can be used to query model attributes:</p>
 *
 * <code>
 *	$metaData = new Phalcon\Mvc\Model\MetaData\Memory();
 *	$attributes = $metaData->getAttributes(new Robots());
 *	print_r($attributes);
 * </code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, MetaData, phalcon, mvc_model_metadata, phalcon_mvc_model_metadata_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_metadata_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_metadata_ce, SL("_strategy"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_metadata_ce, SL("_metaData"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_metadata_ce, SL("_columnMap"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_ATTRIBUTES"), 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_PRIMARY_KEY"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_NON_PRIMARY_KEY"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_NOT_NULL"), 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_DATA_TYPES"), 4 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_DATA_TYPES_NUMERIC"), 5 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_DATE_AT"), 6 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_DATE_IN"), 7 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_IDENTITY_COLUMN"), 8 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_DATA_TYPES_BIND"), 9 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_AUTOMATIC_DEFAULT_INSERT"), 10 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_AUTOMATIC_DEFAULT_UPDATE"), 11 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_COLUMN_MAP"), 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_REVERSE_COLUMN_MAP"), 1 TSRMLS_CC);

	return SUCCESS;

}

/**
 * Initialize the metadata for certain table
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param string|null key
 * @param string|null table
 * @param string|null schema
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, _initialize) {

	zval *model, *key, *table, *schema, *strategy, *className, *metaData, *data = NULL, *modelMetadata, *dependencyInjector = NULL, *columnMap, *keyName, *prefixKey = NULL, *_0 = NULL, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &model, &key, &table, &schema);



	ZEPHIR_INIT_VAR(strategy);
	ZVAL_NULL(strategy);
	ZEPHIR_INIT_VAR(className);
	zephir_call_func_p1(className, "get_class", model);
	if ((Z_TYPE_P(key) != IS_NULL)) {
		metaData = zephir_fetch_nproperty_this(this_ptr, SL("_metaData"), PH_NOISY_CC);
		if (!(zephir_array_isset(metaData, key))) {
			ZEPHIR_INIT_VAR(prefixKey);
			ZEPHIR_CONCAT_SV(prefixKey, "meta-", key);
			ZEPHIR_INIT_VAR(data);
			zephir_call_method_p1(data, this_ptr, "read", prefixKey);
			if ((Z_TYPE_P(data) != IS_NULL)) {
				zephir_update_property_array(this_ptr, SL("_metaData"), key, metaData TSRMLS_CC);
			} else {
				ZEPHIR_INIT_VAR(modelMetadata);
				if ((zephir_method_exists_str(model, SS("metadata") TSRMLS_CC) == SUCCESS)) {
					zephir_call_method(modelMetadata, model, "metadata");
					if ((Z_TYPE_P(modelMetadata) != IS_ARRAY)) {
						ZEPHIR_INIT_VAR(_0);
						object_init_ex(_0, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_VAR(_1);
						ZEPHIR_CONCAT_SV(_1, "Invalid meta-data for model ", className);
						zephir_call_method_p1_noret(_0, "__construct", _1);
						zephir_throw_exception(_0 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_OBS_VAR(dependencyInjector);
					zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
					ZEPHIR_INIT_BNVAR(strategy);
					zephir_call_method(strategy, this_ptr, "getstrategy");
					zephir_call_method_p2(modelMetadata, strategy, "getmetadata", model, dependencyInjector);
				}
				zephir_update_property_array(this_ptr, SL("_metaData"), key, modelMetadata TSRMLS_CC);
				zephir_call_method_p2_noret(this_ptr, "write", prefixKey, modelMetadata);
			}
		}
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "orm.column_renaming", 1);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p1(_2, "globals_get", _0);
	if (zephir_is_true(_2)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(keyName);
	zephir_call_func_p1(keyName, "strtolower", className);
	ZEPHIR_OBS_VAR(columnMap);
	zephir_read_property_this(&columnMap, this_ptr, SL("_columnMap"), PH_NOISY_CC);
	if (zephir_array_isset(columnMap, keyName)) {
		RETURN_MM_NULL();
	}
	if ((Z_TYPE_P(columnMap) != IS_ARRAY)) {
		ZEPHIR_INIT_BNVAR(columnMap);
		array_init(columnMap);
	}
	ZEPHIR_INIT_NVAR(prefixKey);
	ZEPHIR_CONCAT_SV(prefixKey, "map-", keyName);
	ZEPHIR_INIT_NVAR(data);
	zephir_call_method_p1(data, this_ptr, "read", prefixKey);
	if ((Z_TYPE_P(data) != IS_NULL)) {
		zephir_array_update_zval(&columnMap, keyName, &data, PH_COPY | PH_SEPARATE);
		zephir_update_property_this(this_ptr, SL("_columnMap"), columnMap TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if ((Z_TYPE_P(strategy) != IS_OBJECT)) {
		ZEPHIR_OBS_NVAR(dependencyInjector);
		zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_INIT_BNVAR(strategy);
		zephir_call_method(strategy, this_ptr, "getstrategy");
	}
	ZEPHIR_INIT_NVAR(_0);
	zephir_call_method_p2(_0, strategy, "getcolumnmaps", model, dependencyInjector);
	zephir_update_property_array(this_ptr, SL("_columnMap"), keyName, _0 TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_columnMap"), PH_NOISY_CC);
	zephir_call_method_p2_noret(this_ptr, "write", prefixKey, _3);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the DependencyInjector container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Set the meta-data extraction strategy
 *
 * @param Phalcon\Mvc\Model\MetaData\Strategy\Introspection strategy
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, setStrategy) {

	zval *strategy;

	zephir_fetch_params(0, 1, 0, &strategy);



	zephir_update_property_this(this_ptr, SL("_strategy"), strategy TSRMLS_CC);

}

/**
 * Return the strategy to obtain the meta-data
 *
 * @return Phalcon\Mvc\Model\MetaData\Strategy\Introspection
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getStrategy) {

	zval *strategy;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(strategy);
	zephir_read_property_this(&strategy, this_ptr, SL("_strategy"), PH_NOISY_CC);
	if ((Z_TYPE_P(strategy) == IS_NULL)) {
		ZEPHIR_INIT_BNVAR(strategy);
		object_init_ex(strategy, phalcon_mvc_model_metadata_strategy_introspection_ce);
		zephir_update_property_this(this_ptr, SL("_strategy"), strategy TSRMLS_CC);
	}
	RETURN_CCTOR(strategy);

}

/**
 * Reads the complete meta-data for certain model
 *
 *<code>
 *	print_r($metaData->readMetaData(new Robots());
 *</code>
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, readMetaData) {

	zval *model, *source, *schema, *key, *metaData, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_INIT_VAR(source);
	zephir_call_method(source, model, "getsource");
	ZEPHIR_INIT_VAR(schema);
	zephir_call_method(schema, model, "getschema");
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "get_class_lower", model);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_VAR(_2);
	concat_function(_2, _1, schema TSRMLS_CC);
	ZEPHIR_INIT_VAR(key);
	concat_function(key, _2, source TSRMLS_CC);
	metaData = zephir_fetch_nproperty_this(this_ptr, SL("_metaData"), PH_NOISY_CC);
	if (!(zephir_array_isset(metaData, key))) {
		zephir_call_method_p4_noret(this_ptr, "_initialize", model, key, source, schema);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Reads meta-data for certain model using a MODEL_* constant
 *
 *<code>
 *	print_r($metaData->writeColumnMapIndex(new Robots(), MetaData::MODELS_REVERSE_COLUMN_MAP, array('leName' => 'name')));
 *</code>
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param int index
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, readMetaDataIndex) {

	int index;
	zval *model, *index_param = NULL, *source, *schema, *key, *metaData, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &index_param);

		index = zephir_get_intval(index_param);


	ZEPHIR_INIT_VAR(source);
	zephir_call_method(source, model, "getsource");
	ZEPHIR_INIT_VAR(schema);
	zephir_call_method(schema, model, "getschema");
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "get_class_lower", model);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_VAR(_2);
	concat_function(_2, _1, schema TSRMLS_CC);
	ZEPHIR_INIT_VAR(key);
	concat_function(key, _2, source TSRMLS_CC);
	metaData = zephir_fetch_nproperty_this(this_ptr, SL("_metaData"), PH_NOISY_CC);
	if (!(zephir_array_isset(metaData, key))) {
		zephir_call_method_p4_noret(this_ptr, "_initialize", model, key, source, schema);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Writes meta-data for certain model using a MODEL_* constant
 *
 *<code>
 *	print_r($metaData->writeColumnMapIndex(new Robots(), MetaData::MODELS_REVERSE_COLUMN_MAP, array('leName' => 'name')));
 *</code>
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param int index
 * @param mixed data
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, writeMetaDataIndex) {

	int index;
	zval *model, *index_param = NULL, *data, *source, *schema, *key, *metaData, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &model, &index_param, &data);

		index = zephir_get_intval(index_param);


	if ((((Z_TYPE_P(data) != IS_ARRAY) && (Z_TYPE_P(data) != IS_STRING)) && (Z_TYPE_P(data) != IS_BOOL))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid data for index");
		return;
	}
	ZEPHIR_INIT_VAR(source);
	zephir_call_method(source, model, "getsource");
	ZEPHIR_INIT_VAR(schema);
	zephir_call_method(schema, model, "getschema");
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "get_class_lower", model);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VS(_1, _0, "-");
	ZEPHIR_INIT_VAR(_2);
	concat_function(_2, _1, schema TSRMLS_CC);
	ZEPHIR_INIT_VAR(key);
	concat_function(key, _2, source TSRMLS_CC);
	metaData = zephir_fetch_nproperty_this(this_ptr, SL("_metaData"), PH_NOISY_CC);
	if (!(zephir_array_isset(metaData, key))) {
		zephir_call_method_p4_noret(this_ptr, "_initialize", model, key, source, schema);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Reads the ordered/reversed column map for certain model
 *
 *<code>
 *	print_r($metaData->readColumnMap(new Robots()));
 *</code>
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, readColumnMap) {

	zval *model, *keyName, *columnMap = NULL, *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_INIT_VAR(keyName);
	zephir_call_func_p1(keyName, "get_class_lower", model);
	ZEPHIR_OBS_VAR(columnMap);
	zephir_read_property_this(&columnMap, this_ptr, SL("_columnMap"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(data);
	if (!(zephir_array_isset_fetch(&data, columnMap, keyName TSRMLS_CC))) {
		zephir_call_method_p4_noret(this_ptr, "_initialize", model, ZEPHIR_GLOBAL(global_null), ZEPHIR_GLOBAL(global_null), ZEPHIR_GLOBAL(global_null));
		ZEPHIR_OBS_NVAR(columnMap);
		zephir_read_property_this(&columnMap, this_ptr, SL("_columnMap"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(data);
		zephir_array_fetch(&data, columnMap, keyName, PH_NOISY TSRMLS_CC);
	}
	RETURN_CCTOR(data);

}

/**
 * Reads column-map information for certain model using a MODEL_* constant
 *
 *<code>
 *	print_r($metaData->readColumnMapIndex(new Robots(), MetaData::MODELS_REVERSE_COLUMN_MAP));
 *</code>
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param int index
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, readColumnMapIndex) {

	int index;
	zval *model, *index_param = NULL, *keyName, *columnMap = NULL, *columnMapModel = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &index_param);

		index = zephir_get_intval(index_param);


	ZEPHIR_INIT_VAR(keyName);
	zephir_call_func_p1(keyName, "get_class_lower", model);
	ZEPHIR_OBS_VAR(columnMap);
	zephir_read_property_this(&columnMap, this_ptr, SL("_columnMap"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(columnMapModel);
	if (!(zephir_array_isset_fetch(&columnMapModel, columnMap, keyName TSRMLS_CC))) {
		zephir_call_method_p4_noret(this_ptr, "_initialize", model, ZEPHIR_GLOBAL(global_null), ZEPHIR_GLOBAL(global_null), ZEPHIR_GLOBAL(global_null));
		ZEPHIR_OBS_NVAR(columnMap);
		zephir_read_property_this(&columnMap, this_ptr, SL("_columnMap"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(columnMapModel);
		zephir_array_fetch(&columnMapModel, columnMap, keyName, PH_NOISY TSRMLS_CC);
	}
	zephir_array_fetch_long(&_0, columnMapModel, index, PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	RETURN_ZVAL(_0, 1, 0);

}

/**
 * Returns table attributes names (fields)
 *
 *<code>
 *	print_r($metaData->getAttributes(new Robots()));
 *</code>
 *
 * @param	Phalcon\Mvc\ModelInterface $model
 * @return 	array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAttributes) {

	zval *model, *data, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0);
	ZEPHIR_INIT_VAR(data);
	zephir_call_method_p2(data, this_ptr, "readmetadataindex", model, _0);
	if ((Z_TYPE_P(data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt");
		return;
	}
	RETURN_CCTOR(data);

}

/**
 * Returns an array of fields which are part of the primary key
 *
 *<code>
 *	print_r($metaData->getPrimaryKeyAttributes(new Robots()));
 *</code>
 *
 * @param	Phalcon\Mvc\ModelInterface model
 * @return	array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getPrimaryKeyAttributes) {

	zval *model, *data, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 1);
	ZEPHIR_INIT_VAR(data);
	zephir_call_method_p2(data, this_ptr, "readmetadataindex", model, _0);
	if ((Z_TYPE_P(data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt");
		return;
	}
	RETURN_CCTOR(data);

}

/**
 * Returns an arrau of fields which are not part of the primary key
 *
 *<code>
 *	print_r($metaData->getNonPrimaryKeyAttributes(new Robots()));
 *</code>
 *
 * @param	Phalcon\Mvc\ModelInterface model
 * @return 	array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getNonPrimaryKeyAttributes) {

	zval *model, *data, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 2);
	ZEPHIR_INIT_VAR(data);
	zephir_call_method_p2(data, this_ptr, "readmetadataindex", model, _0);
	if ((Z_TYPE_P(data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt");
		return;
	}
	RETURN_CCTOR(data);

}

/**
 * Returns an array of not null attributes
 *
 *<code>
 *	print_r($metaData->getNotNullAttributes(new Robots()));
 *</code>
 *
 * @param	Phalcon\Mvc\ModelInterface model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getNotNullAttributes) {

	zval *model, *data, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 3);
	ZEPHIR_INIT_VAR(data);
	zephir_call_method_p2(data, this_ptr, "readmetadataindex", model, _0);
	if ((Z_TYPE_P(data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt");
		return;
	}
	RETURN_CCTOR(data);

}

/**
 * Returns attributes and their data types
 *
 *<code>
 *	print_r($metaData->getDataTypes(new Robots()));
 *</code>
 *
 * @param	Phalcon\Mvc\ModelInterface model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDataTypes) {

	zval *model, *data, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 4);
	ZEPHIR_INIT_VAR(data);
	zephir_call_method_p2(data, this_ptr, "readmetadataindex", model, _0);
	if ((Z_TYPE_P(data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt");
		return;
	}
	RETURN_CCTOR(data);

}

/**
 * Returns attributes which types are numerical
 *
 *<code>
 *	print_r($metaData->getDataTypesNumeric(new Robots()));
 *</code>
 *
 * @param  Phalcon\Mvc\ModelInterface model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDataTypesNumeric) {

	zval *model, *data, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 5);
	ZEPHIR_INIT_VAR(data);
	zephir_call_method_p2(data, this_ptr, "readmetadataindex", model, _0);
	if ((Z_TYPE_P(data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt");
		return;
	}
	RETURN_CCTOR(data);

}

/**
 * Returns the name of identity field (if one is present)
 *
 *<code>
 *	print_r($metaData->getIdentityField(new Robots()));
 *</code>
 *
 * @param  Phalcon\Mvc\ModelInterface model
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getIdentityField) {

	zval *model, *data, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 8);
	ZEPHIR_INIT_VAR(data);
	zephir_call_method_p2(data, this_ptr, "readmetadataindex", model, _0);
	if ((Z_TYPE_P(data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt");
		return;
	}
	RETURN_CCTOR(data);

}

/**
 * Returns attributes and their bind data types
 *
 *<code>
 *	print_r($metaData->getBindTypes(new Robots()));
 *</code>
 *
 * @param	Phalcon\Mvc\ModelInterface model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getBindTypes) {

	zval *model, *data, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 9);
	ZEPHIR_INIT_VAR(data);
	zephir_call_method_p2(data, this_ptr, "readmetadataindex", model, _0);
	if ((Z_TYPE_P(data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt");
		return;
	}
	RETURN_CCTOR(data);

}

/**
 * Returns attributes that must be ignored from the INSERT SQL generation
 *
 *<code>
 *	print_r($metaData->getAutomaticCreateAttributes(new Robots()));
 *</code>
 *
 * @param	Phalcon\Mvc\ModelInterface model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAutomaticCreateAttributes) {

	zval *model, *data, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 10);
	ZEPHIR_INIT_VAR(data);
	zephir_call_method_p2(data, this_ptr, "readmetadataindex", model, _0);
	if ((Z_TYPE_P(data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt");
		return;
	}
	RETURN_CCTOR(data);

}

/**
 * Returns attributes that must be ignored from the UPDATE SQL generation
 *
 *<code>
 *	print_r($metaData->getAutomaticUpdateAttributes(new Robots()));
 *</code>
 *
 * @param	Phalcon\Mvc\ModelInterface model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAutomaticUpdateAttributes) {

	zval *model, *data, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 11);
	ZEPHIR_INIT_VAR(data);
	zephir_call_method_p2(data, this_ptr, "readmetadataindex", model, _0);
	if ((Z_TYPE_P(data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt");
		return;
	}
	RETURN_CCTOR(data);

}

/**
 * Set the attributes that must be ignored from the INSERT SQL generation
 *
 *<code>
 *	$metaData->setAutomaticCreateAttributes(new Robots(), array('created_at' => true));
 *</code>
 *
 * @param  Phalcon\Mvc\ModelInterface model
 * @param  array attributes
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, setAutomaticCreateAttributes) {

	zval *model, *attributes, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &attributes);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 10);
	zephir_call_method_p3_noret(this_ptr, "writemetadataindex", model, _0, attributes);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set the attributes that must be ignored from the UPDATE SQL generation
 *
 *<code>
 *	$metaData->setAutomaticUpdateAttributes(new Robots(), array('modified_at' => true));
 *</code>
 *
 * @param  Phalcon\Mvc\ModelInterface model
 * @param  array attributes
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, setAutomaticUpdateAttributes) {

	zval *model, *attributes, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &attributes);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 11);
	zephir_call_method_p3_noret(this_ptr, "writemetadataindex", model, _0, attributes);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the column map if any
 *
 *<code>
 *	print_r($metaData->getColumnMap(new Robots()));
 *</code>
 *
 * @param	Phalcon\Mvc\ModelInterface model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getColumnMap) {

	zval *model, *data, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0);
	ZEPHIR_INIT_VAR(data);
	zephir_call_method_p2(data, this_ptr, "readcolumnmapindex", model, _0);
	if (((Z_TYPE_P(data) != IS_NULL) && (Z_TYPE_P(data) != IS_ARRAY))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt");
		return;
	}
	RETURN_CCTOR(data);

}

/**
 * Returns the reverse column map if any
 *
 *<code>
 *	print_r($metaData->getReverseColumnMap(new Robots()));
 *</code>
 *
 * @param	Phalcon\Mvc\ModelInterface model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getReverseColumnMap) {

	zval *model, *data, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 1);
	ZEPHIR_INIT_VAR(data);
	zephir_call_method_p2(data, this_ptr, "readcolumnmapindex", model, _0);
	if (((Z_TYPE_P(data) != IS_NULL) && (Z_TYPE_P(data) != IS_ARRAY))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt");
		return;
	}
	RETURN_CCTOR(data);

}

/**
 * Check if a model has certain attribute
 *
 *<code>
 *	var_dump($metaData->hasAttribute(new Robots(), 'name'));
 *</code>
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param string attribute
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, hasAttribute) {

	zval *attribute = NULL;
	zval *model, *attribute_param = NULL, *columnMap, *metaData, *dataTypes;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &attribute_param);

		zephir_get_strval(attribute, attribute_param);


	ZEPHIR_INIT_VAR(columnMap);
	zephir_call_method_p1(columnMap, this_ptr, "getreversecolumnmap", model);
	if ((Z_TYPE_P(columnMap) == IS_ARRAY)) {
		RETURN_MM_BOOL(zephir_array_isset(columnMap, attribute));
	} else {
		ZEPHIR_INIT_VAR(metaData);
		zephir_call_method_p1(metaData, this_ptr, "readmetadata", model);
		zephir_array_fetch_long(&dataTypes, metaData, 4, PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_MM_BOOL(zephir_array_isset(dataTypes, attribute));
	}
	RETURN_MM_BOOL(0);

}

/**
 * Checks if the internal meta-data container is empty
 *
 *<code>
 *	var_dump($metaData->isEmpty());
 *</code>
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, isEmpty) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_metaData"), PH_NOISY_CC);
	RETURN_BOOL((zephir_fast_count_int(_0 TSRMLS_CC) > 0));

}

/**
 * Resets internal meta-data in order to regenerate it
 *
 *<code>
 *	$metaData->reset();
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, reset) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_metaData"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("_columnMap"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

