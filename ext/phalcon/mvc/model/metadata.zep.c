
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/string.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
 *	$metaData = new \Phalcon\Mvc\Model\MetaData\Memory();
 *	$attributes = $metaData->getAttributes(new Robots());
 *	print_r($attributes);
 * </code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, MetaData, phalcon, mvc_model_metadata, phalcon_mvc_model_metadata_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

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

	zend_class_implements(phalcon_mvc_model_metadata_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *key, *table, *schema, *strategy = NULL, *className, *metaData, *data = NULL, *modelMetadata = NULL, *modelColumnMap = NULL, *dependencyInjector = NULL, *keyName, *prefixKey = NULL, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &model, &key, &table, &schema);



	if (!(zephir_instance_of_ev(model, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(strategy);
	ZVAL_NULL(strategy);
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, model, 0 TSRMLS_CC);
	if (Z_TYPE_P(key) != IS_NULL) {
		ZEPHIR_OBS_VAR(metaData);
		zephir_read_property_this(&metaData, this_ptr, SL("_metaData"), PH_NOISY_CC);
		if (!(zephir_array_isset(metaData, key))) {
			ZEPHIR_INIT_VAR(prefixKey);
			ZEPHIR_CONCAT_SV(prefixKey, "meta-", key);
			ZEPHIR_CALL_METHOD(&data, this_ptr, "read", NULL, prefixKey);
			zephir_check_call_status();
			if (Z_TYPE_P(data) != IS_NULL) {
				zephir_update_property_array(this_ptr, SL("_metaData"), key, data TSRMLS_CC);
			} else {
				if ((zephir_method_exists_ex(model, SS("metadata") TSRMLS_CC) == SUCCESS)) {
					ZEPHIR_CALL_METHOD(&modelMetadata, model, "metadata",  NULL);
					zephir_check_call_status();
					if (Z_TYPE_P(modelMetadata) != IS_ARRAY) {
						ZEPHIR_INIT_VAR(_0);
						object_init_ex(_0, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_VAR(_1);
						ZEPHIR_CONCAT_SV(_1, "Invalid meta-data for model ", className);
						ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _1);
						zephir_check_call_status();
						zephir_throw_exception_debug(_0, "phalcon/mvc/model/metadata.zep", 119 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_OBS_VAR(dependencyInjector);
					zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
					ZEPHIR_CALL_METHOD(&strategy, this_ptr, "getstrategy",  NULL);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&modelMetadata, strategy, "getmetadata", NULL, model, dependencyInjector);
					zephir_check_call_status();
				}
				zephir_update_property_array(this_ptr, SL("_metaData"), key, modelMetadata TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, prefixKey, modelMetadata);
				zephir_check_call_status();
			}
		}
	}
	if (!(ZEPHIR_GLOBAL(orm).column_renaming)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(keyName);
	zephir_fast_strtolower(keyName, className);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_columnMap"), PH_NOISY_CC);
	if (zephir_array_isset(_2, keyName)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_NVAR(prefixKey);
	ZEPHIR_CONCAT_SV(prefixKey, "map-", keyName);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "read", NULL, prefixKey);
	zephir_check_call_status();
	if (Z_TYPE_P(data) != IS_NULL) {
		zephir_update_property_array(this_ptr, SL("_columnMap"), keyName, data TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (Z_TYPE_P(strategy) != IS_OBJECT) {
		ZEPHIR_OBS_NVAR(dependencyInjector);
		zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&strategy, this_ptr, "getstrategy",  NULL);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&modelColumnMap, strategy, "getcolumnmaps", NULL, model, dependencyInjector);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_columnMap"), keyName, modelColumnMap TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, prefixKey, modelColumnMap);
	zephir_check_call_status();
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



	if (!(zephir_instance_of_ev(strategy, phalcon_mvc_model_metadata_strategyinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'strategy' must be an instance of 'Phalcon\\Mvc\\Model\\MetaData\\StrategyInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_strategy"), strategy TSRMLS_CC);

}

/**
 * Return the strategy to obtain the meta-data
 *
 * @return Phalcon\Mvc\Model\MetaData\Strategy\StrategyInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getStrategy) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *strategy;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(strategy);
	zephir_read_property_this(&strategy, this_ptr, SL("_strategy"), PH_NOISY_CC);
	if (Z_TYPE_P(strategy) == IS_NULL) {
		ZEPHIR_INIT_BNVAR(strategy);
		object_init_ex(strategy, phalcon_mvc_model_metadata_strategy_introspection_ce);
		if (zephir_has_constructor(strategy TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, strategy, "__construct", NULL);
			zephir_check_call_status();
		}
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

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *source = NULL, *schema = NULL, *key, *_0, *_1, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	if (!(zephir_instance_of_ev(model, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&source, model, "getsource",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&schema, model, "getschema",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	zephir_get_class(_0, model, 1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(key);
	ZEPHIR_CONCAT_VSVV(key, _0, "-", schema, source);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_metaData"), PH_NOISY_CC);
	if (!(zephir_array_isset(_1, key))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_initialize", &_2, model, key, source, schema);
		zephir_check_call_status();
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_metaData"), PH_NOISY_CC);
	zephir_array_fetch(&_4, _3, key, PH_NOISY | PH_READONLY, "phalcon/mvc/model/metadata.zep", 261 TSRMLS_CC);
	RETURN_CTOR(_4);

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
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, readMetaDataIndex) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	int index, ZEPHIR_LAST_CALL_STATUS;
	zval *model, *index_param = NULL, *source = NULL, *schema = NULL, *key, *metaData, *_0, *_1, *_2, *_4, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &index_param);

	index = zephir_get_intval(index_param);


	if (!(zephir_instance_of_ev(model, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&source, model, "getsource",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&schema, model, "getschema",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	zephir_get_class(_0, model, 1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(key);
	ZEPHIR_CONCAT_VSVV(key, _0, "-", schema, source);
	ZEPHIR_OBS_VAR(metaData);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_metaData"), PH_NOISY_CC);
	zephir_array_fetch(&_2, _1, key, PH_READONLY, "phalcon/mvc/model/metadata.zep", 287 TSRMLS_CC);
	if (zephir_array_isset_long_fetch(&metaData, _2, index, 0 TSRMLS_CC)) {
		RETURN_CCTOR(metaData);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_initialize", &_3, model, key, source, schema);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_metaData"), PH_NOISY_CC);
	zephir_array_fetch(&_5, _4, key, PH_NOISY | PH_READONLY, "phalcon/mvc/model/metadata.zep", 292 TSRMLS_CC);
	zephir_array_fetch_long(&_6, _5, index, PH_NOISY | PH_READONLY, "phalcon/mvc/model/metadata.zep", 292 TSRMLS_CC);
	RETURN_CTOR(_6);

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

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	zend_bool _0, _1;
	int index, ZEPHIR_LAST_CALL_STATUS;
	zval *model, *index_param = NULL, *data, *source = NULL, *schema = NULL, *key, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &model, &index_param, &data);

	index = zephir_get_intval(index_param);


	if (!(zephir_instance_of_ev(model, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	_0 = Z_TYPE_P(data) != IS_ARRAY;
	if (_0) {
		_0 = Z_TYPE_P(data) != IS_STRING;
	}
	_1 = _0;
	if (_1) {
		_1 = Z_TYPE_P(data) != IS_BOOL;
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid data for index", "phalcon/mvc/model/metadata.zep", 311);
		return;
	}
	ZEPHIR_CALL_METHOD(&source, model, "getsource",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&schema, model, "getschema",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	zephir_get_class(_2, model, 1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(key);
	ZEPHIR_CONCAT_VSVV(key, _2, "-", schema, source);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_metaData"), PH_NOISY_CC);
	if (!(zephir_array_isset(_3, key))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_initialize", &_4, model, key, source, schema);
		zephir_check_call_status();
	}
	zephir_update_property_array_multi(this_ptr, SL("_metaData"), &data TSRMLS_CC, SL("zl"), 2, key, index);
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

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *keyName, *data = NULL, *_0, *_1, *_2, *_3, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	if (!(zephir_instance_of_ev(model, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(keyName);
	zephir_get_class(keyName, model, 1 TSRMLS_CC);
	ZEPHIR_OBS_VAR(data);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_columnMap"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&data, _0, keyName, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_NULL(_1);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_NULL(_2);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_NULL(_3);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_initialize", &_4, model, _1, _2, _3);
		zephir_check_call_status();
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_columnMap"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(data);
		zephir_array_fetch(&data, _5, keyName, PH_NOISY, "phalcon/mvc/model/metadata.zep", 346 TSRMLS_CC);
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

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	int index, ZEPHIR_LAST_CALL_STATUS;
	zval *model, *index_param = NULL, *keyName, *columnMapModel = NULL, *_0, *_1, *_2, *_3, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &index_param);

	index = zephir_get_intval(index_param);


	if (!(zephir_instance_of_ev(model, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(keyName);
	zephir_get_class(keyName, model, 1 TSRMLS_CC);
	ZEPHIR_OBS_VAR(columnMapModel);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_columnMap"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&columnMapModel, _0, keyName, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_NULL(_1);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_NULL(_2);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_NULL(_3);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_initialize", &_4, model, _1, _2, _3);
		zephir_check_call_status();
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_columnMap"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(columnMapModel);
		zephir_array_fetch(&columnMapModel, _5, keyName, PH_NOISY, "phalcon/mvc/model/metadata.zep", 370 TSRMLS_CC);
	}
	zephir_array_fetch_long(&_6, columnMapModel, index, PH_NOISY | PH_READONLY, "phalcon/mvc/model/metadata.zep", 373 TSRMLS_CC);
	RETURN_CTOR(_6);

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

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *data = NULL, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	if (!(zephir_instance_of_ev(model, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", &_1, model, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/mvc/model/metadata.zep", 391);
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

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *data = NULL, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	if (!(zephir_instance_of_ev(model, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 1);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", &_1, model, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/mvc/model/metadata.zep", 411);
		return;
	}
	RETURN_CCTOR(data);

}

/**
 * Returns an array of fields which are not part of the primary key
 *
 *<code>
 *	print_r($metaData->getNonPrimaryKeyAttributes(new Robots()));
 *</code>
 *
 * @param	Phalcon\Mvc\ModelInterface model
 * @return 	array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getNonPrimaryKeyAttributes) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *data = NULL, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	if (!(zephir_instance_of_ev(model, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 2);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", &_1, model, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/mvc/model/metadata.zep", 431);
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

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *data = NULL, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	if (!(zephir_instance_of_ev(model, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 3);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", &_1, model, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/mvc/model/metadata.zep", 451);
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

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *data = NULL, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	if (!(zephir_instance_of_ev(model, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", &_1, model, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/mvc/model/metadata.zep", 471);
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

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *data = NULL, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	if (!(zephir_instance_of_ev(model, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 5);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", &_1, model, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/mvc/model/metadata.zep", 491);
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

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	if (!(zephir_instance_of_ev(model, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 8);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "readmetadataindex", &_1, model, &_0);
	zephir_check_call_status();
	RETURN_MM();

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

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *data = NULL, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	if (!(zephir_instance_of_ev(model, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 9);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", &_1, model, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/mvc/model/metadata.zep", 526);
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

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *data = NULL, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	if (!(zephir_instance_of_ev(model, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 10);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", &_1, model, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/mvc/model/metadata.zep", 546);
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

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *data = NULL, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	if (!(zephir_instance_of_ev(model, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 11);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readmetadataindex", &_1, model, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/mvc/model/metadata.zep", 566);
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

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *attributes, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &attributes);



	if (!(zephir_instance_of_ev(model, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 10);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "writemetadataindex", &_1, model, &_0, attributes);
	zephir_check_call_status();
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

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *attributes, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &attributes);



	if (!(zephir_instance_of_ev(model, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 11);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "writemetadataindex", &_1, model, &_0, attributes);
	zephir_check_call_status();
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

	zend_bool _2;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *data = NULL, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	if (!(zephir_instance_of_ev(model, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readcolumnmapindex", &_1, model, &_0);
	zephir_check_call_status();
	_2 = Z_TYPE_P(data) != IS_NULL;
	if (_2) {
		_2 = Z_TYPE_P(data) != IS_ARRAY;
	}
	if (_2) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/mvc/model/metadata.zep", 617);
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

	zend_bool _2;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *data = NULL, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	if (!(zephir_instance_of_ev(model, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 1);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "readcolumnmapindex", &_1, model, &_0);
	zephir_check_call_status();
	_2 = Z_TYPE_P(data) != IS_NULL;
	if (_2) {
		_2 = Z_TYPE_P(data) != IS_ARRAY;
	}
	if (_2) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt", "phalcon/mvc/model/metadata.zep", 638);
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

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *attribute = NULL;
	zval *model, *attribute_param = NULL, *columnMap = NULL, *_0 = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &attribute_param);

	zephir_get_strval(attribute, attribute_param);


	if (!(zephir_instance_of_ev(model, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&columnMap, this_ptr, "getreversecolumnmap", NULL, model);
	zephir_check_call_status();
	if (Z_TYPE_P(columnMap) == IS_ARRAY) {
		RETURN_MM_BOOL(zephir_array_isset(columnMap, attribute));
	} else {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "readmetadata", &_1, model);
		zephir_check_call_status();
		zephir_array_fetch_long(&_2, _0, 4, PH_READONLY, "phalcon/mvc/model/metadata.zep", 662 TSRMLS_CC);
		RETURN_MM_BOOL(zephir_array_isset(_2, attribute));
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
	RETURN_BOOL(zephir_fast_count_int(_0 TSRMLS_CC) == 0);

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

