
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/file.h"

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


/**
 * Phalcon\Mvc\Model\MetaData initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model, MetaData, mvc_model_metadata, phalcon_mvc_model_metadata_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

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
 * @param Phalcon\Mvc\ModelInterface $model
 * @param string $key
 * @param string $table
 * @param string $schema
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, _initialize){

	zval *model, *key, *table, *schema, *strategy = NULL, *class_name;
	zval *meta_data = NULL, *prefix_key = NULL, *data = NULL, *model_metadata = NULL;
	zval *exception_message, *dependency_injector = NULL;
	zval *key_name, *column_map = NULL, *model_column_map;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &model, &key, &table, &schema);
	
	PHALCON_INIT_VAR(strategy);
	
	PHALCON_INIT_VAR(class_name);
	phalcon_get_class(class_name, model, 0 TSRMLS_CC);
	if (Z_TYPE_P(key) != IS_NULL) {
	
		PHALCON_OBS_VAR(meta_data);
		phalcon_read_property_this(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
		if (!phalcon_array_isset(meta_data, key)) {
	
			PHALCON_INIT_VAR(prefix_key);
			PHALCON_CONCAT_SV(prefix_key, "meta-", key);
	
			/** 
			 * The meta-data is read from the adapter always
			 */
			PHALCON_INIT_VAR(data);
			phalcon_call_method_p1(data, this_ptr, "read", prefix_key);
			if (Z_TYPE_P(data) != IS_NULL) {
				if (Z_TYPE_P(meta_data) != IS_ARRAY) { 
					PHALCON_INIT_NVAR(meta_data);
					array_init(meta_data);
				}
				phalcon_array_update_zval(&meta_data, key, &data, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_update_property_this(this_ptr, SL("_metaData"), meta_data TSRMLS_CC);
			} else {
				/** 
				 * Check if there is a method 'metaData' in the model to retrieve meta-data from it
				 */
				if (phalcon_method_exists_ex(model, SS("metadata") TSRMLS_CC) == SUCCESS) {
	
					PHALCON_INIT_VAR(model_metadata);
					phalcon_call_method(model_metadata, model, "metadata");
					if (Z_TYPE_P(model_metadata) != IS_ARRAY) { 
						PHALCON_INIT_VAR(exception_message);
						PHALCON_CONCAT_SV(exception_message, "Invalid meta-data for model ", class_name);
						PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
						return;
					}
				} else {
					PHALCON_OBS_VAR(dependency_injector);
					phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
					/** 
					 * Get the meta-data extraction strategy
					 */
					phalcon_call_method(strategy, this_ptr, "getstrategy");
	
					/** 
					 * Get the meta-data
					 */
					PHALCON_INIT_NVAR(model_metadata);
					phalcon_call_method_p2(model_metadata, strategy, "getmetadata", model, dependency_injector);
				}
	
				/** 
				 * Store the meta-data locally
				 */
				phalcon_update_property_array(this_ptr, SL("_metaData"), key, model_metadata TSRMLS_CC);
	
				/** 
				 * Store the meta-data in the adapter
				 */
				phalcon_call_method_p2_noret(this_ptr, "write", prefix_key, model_metadata);
			}
		}
	}
	
	/** 
	 * Check for a column map, store in _columnMap in order and reversed order
	 */
	if (!PHALCON_GLOBAL(orm).column_renaming) {
		RETURN_MM_NULL();
	}
	
	PHALCON_INIT_VAR(key_name);
	phalcon_fast_strtolower(key_name, class_name);
	
	PHALCON_OBS_VAR(column_map);
	phalcon_read_property_this(&column_map, this_ptr, SL("_columnMap"), PH_NOISY_CC);
	if (phalcon_array_isset(column_map, key_name)) {
		RETURN_MM_NULL();
	}
	
	if (Z_TYPE_P(column_map) != IS_ARRAY) { 
		PHALCON_INIT_NVAR(column_map);
		array_init(column_map);
	}
	
	/** 
	 * Create the map key name
	 */
	PHALCON_INIT_NVAR(prefix_key);
	PHALCON_CONCAT_SV(prefix_key, "map-", key_name);
	
	/** 
	 * Check if the meta-data is already in the adapter
	 */
	PHALCON_INIT_NVAR(data);
	phalcon_call_method_p1(data, this_ptr, "read", prefix_key);
	if (Z_TYPE_P(data) != IS_NULL) {
		phalcon_array_update_zval(&column_map, key_name, &data, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_columnMap"), column_map TSRMLS_CC);
		RETURN_MM_NULL();
	}
	
	/** 
	 * Get the meta-data extraction strategy
	 */
	if (Z_TYPE_P(strategy) != IS_OBJECT) {
		PHALCON_OBS_NVAR(dependency_injector);
		phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(strategy);
		phalcon_call_method(strategy, this_ptr, "getstrategy");
	}
	
	/** 
	 * Get the meta-data
	 */
	PHALCON_INIT_VAR(model_column_map);
	phalcon_call_method_p2(model_column_map, strategy, "getcolumnmaps", model, dependency_injector);
	
	/** 
	 * Update the column map locally
	 */
	phalcon_update_property_array(this_ptr, SL("_columnMap"), key_name, model_column_map TSRMLS_CC);
	
	/** 
	 * Write the data to the adapter
	 */
	phalcon_call_method_p2_noret(this_ptr, "write", prefix_key, model_column_map);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, setDI){

	zval *dependency_injector;

	phalcon_fetch_params(0, 1, 0, &dependency_injector);
	
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "The dependency injector is invalid");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
}

/**
 * Returns the DependencyInjector container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Set the meta-data extraction strategy
 *
 * @param Phalcon\Mvc\Model\MetaData\Strategy\Introspection $strategy
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, setStrategy){

	zval *strategy;

	phalcon_fetch_params(0, 1, 0, &strategy);
	
	if (Z_TYPE_P(strategy) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "The meta-data extraction strategy is not valid");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_strategy"), strategy TSRMLS_CC);
	
}

/**
 * Return the strategy to obtain the meta-data
 *
 * @return Phalcon\Mvc\Model\MetaData\Strategy\Introspection
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getStrategy){

	zval *strategy = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(strategy);
	phalcon_read_property_this(&strategy, this_ptr, SL("_strategy"), PH_NOISY_CC);
	if (Z_TYPE_P(strategy) == IS_NULL) {
		PHALCON_INIT_NVAR(strategy);
		object_init_ex(strategy, phalcon_mvc_model_metadata_strategy_introspection_ce);
		phalcon_update_property_this(this_ptr, SL("_strategy"), strategy TSRMLS_CC);
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
 * @param Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, readMetaData){

	zval *model, *table, *schema, *class_name, *key, *meta_data = NULL;
	zval *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	if (Z_TYPE_P(model) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A model instance is required to retrieve the meta-data");
		return;
	}
	
	PHALCON_INIT_VAR(table);
	phalcon_call_method(table, model, "getsource");
	
	PHALCON_INIT_VAR(schema);
	phalcon_call_method(schema, model, "getschema");
	
	PHALCON_INIT_VAR(class_name);
	phalcon_get_class(class_name, model, 1 TSRMLS_CC);
	
	/** 
	 * Unique key for meta-data is created using class-name-schema-table
	 */
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_VSVV(key, class_name, "-", schema, table);
	
	PHALCON_OBS_VAR(meta_data);
	phalcon_read_property_this(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
	if (!phalcon_array_isset(meta_data, key)) {
		phalcon_call_method_p4_noret(this_ptr, "_initialize", model, key, table, schema);
	
		PHALCON_OBS_NVAR(meta_data);
		phalcon_read_property_this(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
	}
	
	PHALCON_OBS_VAR(data);
	phalcon_array_fetch(&data, meta_data, key, PH_NOISY_CC);
	
	RETURN_CCTOR(data);
}

/**
 * Reads meta-data for certain model using a MODEL_* constant
 *
 *<code>
 *	print_r($metaData->writeColumnMapIndex(new Robots(), MetaData::MODELS_REVERSE_COLUMN_MAP, array('leName' => 'name')));
 *</code>
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @param int $index
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, readMetaDataIndex){

	zval *model, *index, *table, *schema, *class_name;
	zval *key, *meta_data = NULL, *meta_data_index, *attributes;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model, &index);
	
	if (Z_TYPE_P(model) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A model instance is required to retrieve the meta-data");
		return;
	}
	if (Z_TYPE_P(index) != IS_LONG) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Index must be a valid integer constant");
		return;
	}
	
	PHALCON_INIT_VAR(table);
	phalcon_call_method(table, model, "getsource");
	
	PHALCON_INIT_VAR(schema);
	phalcon_call_method(schema, model, "getschema");
	
	PHALCON_INIT_VAR(class_name);
	phalcon_get_class(class_name, model, 1 TSRMLS_CC);
	
	/** 
	 * Unique key for meta-data is created using class-name-schema-table
	 */
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_VSVV(key, class_name, "-", schema, table);
	
	PHALCON_OBS_VAR(meta_data);
	phalcon_read_property_this(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
	if (!phalcon_array_isset(meta_data, key)) {
		phalcon_call_method_p4_noret(this_ptr, "_initialize", model, key, table, schema);
	
		PHALCON_OBS_NVAR(meta_data);
		phalcon_read_property_this(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
	}
	
	PHALCON_OBS_VAR(meta_data_index);
	phalcon_array_fetch(&meta_data_index, meta_data, key, PH_NOISY_CC);
	
	PHALCON_OBS_VAR(attributes);
	phalcon_array_fetch(&attributes, meta_data_index, index, PH_NOISY_CC);
	
	RETURN_CCTOR(attributes);
}

/**
 * Writes meta-data for certain model using a MODEL_* constant
 *
 *<code>
 *	print_r($metaData->writeColumnMapIndex(new Robots(), MetaData::MODELS_REVERSE_COLUMN_MAP, array('leName' => 'name')));
 *</code>
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @param int $index
 * @param mixed $data
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, writeMetaDataIndex){

	zval *model, *index, *data, *table, *schema, *class_name;
	zval *key, *meta_data = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &model, &index, &data);
	
	if (Z_TYPE_P(model) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A model instance is required to retrieve the meta-data");
		return;
	}
	if (Z_TYPE_P(index) != IS_LONG) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Index must be a valid integer constant");
		return;
	}
	
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		if (Z_TYPE_P(data) != IS_STRING) {
			if (Z_TYPE_P(data) != IS_BOOL) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid data for index");
				return;
			}
		}
	}
	
	PHALCON_INIT_VAR(table);
	phalcon_call_method(table, model, "getsource");
	
	PHALCON_INIT_VAR(schema);
	phalcon_call_method(schema, model, "getschema");
	
	PHALCON_INIT_VAR(class_name);
	phalcon_get_class(class_name, model, 1 TSRMLS_CC);
	
	/** 
	 * Unique key for meta-data is created using class-name-schema-table
	 */
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_VSVV(key, class_name, "-", schema, table);
	
	PHALCON_OBS_VAR(meta_data);
	phalcon_read_property_this(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
	if (!phalcon_array_isset(meta_data, key)) {
		phalcon_call_method_p4_noret(this_ptr, "_initialize", model, key, table, schema);
	
		PHALCON_OBS_NVAR(meta_data);
		phalcon_read_property_this(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
	}
	
	phalcon_array_update_multi_2(&meta_data, key, index, &data, 0 TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_metaData"), meta_data TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Reads the ordered/reversed column map for certain model
 *
 *<code>
 *	print_r($metaData->readColumnMap(new Robots()));
 *</code>
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, readColumnMap){

	zval *model, *key_name, *column_map = NULL, *null_value;
	zval *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	if (Z_TYPE_P(model) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A model instance is required to retrieve the meta-data");
		return;
	}
	
	PHALCON_INIT_VAR(key_name);
	phalcon_get_class(key_name, model, 1 TSRMLS_CC);
	
	PHALCON_OBS_VAR(column_map);
	phalcon_read_property_this(&column_map, this_ptr, SL("_columnMap"), PH_NOISY_CC);
	if (!phalcon_array_isset(column_map, key_name)) {
		PHALCON_INIT_VAR(null_value);
		phalcon_call_method_p4_noret(this_ptr, "_initialize", model, null_value, null_value, null_value);
	
		PHALCON_OBS_NVAR(column_map);
		phalcon_read_property_this(&column_map, this_ptr, SL("_columnMap"), PH_NOISY_CC);
	}
	
	PHALCON_OBS_VAR(data);
	phalcon_array_fetch(&data, column_map, key_name, PH_NOISY_CC);
	
	RETURN_CCTOR(data);
}

/**
 * Reads column-map information for certain model using a MODEL_* constant
 *
 *<code>
 *	print_r($metaData->readColumnMapIndex(new Robots(), MetaData::MODELS_REVERSE_COLUMN_MAP));
 *</code>
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @param int $index
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, readColumnMapIndex){

	zval *model, *index, *key_name, *column_map = NULL, *null_value;
	zval *column_map_model, *attributes;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model, &index);
	
	if (Z_TYPE_P(model) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A model instance is required to retrieve the meta-data");
		return;
	}
	if (Z_TYPE_P(index) != IS_LONG) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Index must be a valid integer constant");
		return;
	}
	
	PHALCON_INIT_VAR(key_name);
	phalcon_get_class(key_name, model, 1 TSRMLS_CC);
	
	PHALCON_OBS_VAR(column_map);
	phalcon_read_property_this(&column_map, this_ptr, SL("_columnMap"), PH_NOISY_CC);
	if (!phalcon_array_isset(column_map, key_name)) {
		PHALCON_INIT_VAR(null_value);
		phalcon_call_method_p4_noret(this_ptr, "_initialize", model, null_value, null_value, null_value);
	
		PHALCON_OBS_NVAR(column_map);
		phalcon_read_property_this(&column_map, this_ptr, SL("_columnMap"), PH_NOISY_CC);
	}
	
	PHALCON_OBS_VAR(column_map_model);
	phalcon_array_fetch(&column_map_model, column_map, key_name, PH_NOISY_CC);
	
	PHALCON_OBS_VAR(attributes);
	phalcon_array_fetch(&attributes, column_map_model, index, PH_NOISY_CC);
	
	RETURN_CCTOR(attributes);
}

/**
 * Returns table attributes names (fields)
 *
 *<code>
 *	print_r($metaData->getAttributes(new Robots()));
 *</code>
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @return 	array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAttributes){

	zval *model, *index, *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	PHALCON_INIT_VAR(index);
	ZVAL_LONG(index, 0);
	
	PHALCON_INIT_VAR(data);
	phalcon_call_method_p2(data, this_ptr, "readmetadataindex", model, index);
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupted");
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
 * @param Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getPrimaryKeyAttributes){

	zval *model, *index, *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	PHALCON_INIT_VAR(index);
	ZVAL_LONG(index, 1);
	
	PHALCON_INIT_VAR(data);
	phalcon_call_method_p2(data, this_ptr, "readmetadataindex", model, index);
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt");
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
 * @param Phalcon\Mvc\ModelInterface $model
 * @return 	array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getNonPrimaryKeyAttributes){

	zval *model, *index, *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	PHALCON_INIT_VAR(index);
	ZVAL_LONG(index, 2);
	
	PHALCON_INIT_VAR(data);
	phalcon_call_method_p2(data, this_ptr, "readmetadataindex", model, index);
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt");
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
 * @param Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getNotNullAttributes){

	zval *model, *index, *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	PHALCON_INIT_VAR(index);
	ZVAL_LONG(index, 3);
	
	PHALCON_INIT_VAR(data);
	phalcon_call_method_p2(data, this_ptr, "readmetadataindex", model, index);
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt");
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
 * @param Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDataTypes){

	zval *model, *index, *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	PHALCON_INIT_VAR(index);
	ZVAL_LONG(index, 4);
	
	PHALCON_INIT_VAR(data);
	phalcon_call_method_p2(data, this_ptr, "readmetadataindex", model, index);
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt");
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
 * @param  Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDataTypesNumeric){

	zval *model, *index, *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	PHALCON_INIT_VAR(index);
	ZVAL_LONG(index, 5);
	
	PHALCON_INIT_VAR(data);
	phalcon_call_method_p2(data, this_ptr, "readmetadataindex", model, index);
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt");
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
 * @param  Phalcon\Mvc\ModelInterface $model
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getIdentityField){

	zval *model, *index, *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	PHALCON_INIT_VAR(index);
	ZVAL_LONG(index, 8);
	
	PHALCON_INIT_VAR(data);
	phalcon_call_method_p2(data, this_ptr, "readmetadataindex", model, index);
	RETURN_CCTOR(data);
}

/**
 * Returns attributes and their bind data types
 *
 *<code>
 *	print_r($metaData->getBindTypes(new Robots()));
 *</code>
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getBindTypes){

	zval *model, *index, *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	PHALCON_INIT_VAR(index);
	ZVAL_LONG(index, 9);
	
	PHALCON_INIT_VAR(data);
	phalcon_call_method_p2(data, this_ptr, "readmetadataindex", model, index);
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt");
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
 * @param Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAutomaticCreateAttributes){

	zval *model, *index, *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	PHALCON_INIT_VAR(index);
	ZVAL_LONG(index, 10);
	
	PHALCON_INIT_VAR(data);
	phalcon_call_method_p2(data, this_ptr, "readmetadataindex", model, index);
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt");
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
 * @param Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAutomaticUpdateAttributes){

	zval *model, *index, *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	PHALCON_INIT_VAR(index);
	ZVAL_LONG(index, 11);
	
	PHALCON_INIT_VAR(data);
	phalcon_call_method_p2(data, this_ptr, "readmetadataindex", model, index);
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt");
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
 * @param  Phalcon\Mvc\ModelInterface $model
 * @param  array $attributes
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, setAutomaticCreateAttributes){

	zval *model, *attributes, *create_index;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model, &attributes);
	
	PHALCON_INIT_VAR(create_index);
	ZVAL_LONG(create_index, 10);
	phalcon_call_method_p3_noret(this_ptr, "writemetadataindex", model, create_index, attributes);
	
	PHALCON_MM_RESTORE();
}

/**
 * Set the attributes that must be ignored from the UPDATE SQL generation
 *
 *<code>
 *	$metaData->setAutomaticUpdateAttributes(new Robots(), array('modified_at' => true));
 *</code>
 *
 * @param  Phalcon\Mvc\ModelInterface $model
 * @param  array $attributes
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, setAutomaticUpdateAttributes){

	zval *model, *attributes, *create_index;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model, &attributes);
	
	PHALCON_INIT_VAR(create_index);
	ZVAL_LONG(create_index, 11);
	phalcon_call_method_p3_noret(this_ptr, "writemetadataindex", model, create_index, attributes);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the column map if any
 *
 *<code>
 *	print_r($metaData->getColumnMap(new Robots()));
 *</code>
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getColumnMap){

	zval *model, *index, *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	PHALCON_INIT_VAR(index);
	ZVAL_LONG(index, 0);
	
	PHALCON_INIT_VAR(data);
	phalcon_call_method_p2(data, this_ptr, "readcolumnmapindex", model, index);
	if (Z_TYPE_P(data) != IS_NULL) {
		if (Z_TYPE_P(data) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt");
			return;
		}
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
 * @param Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getReverseColumnMap){

	zval *model, *index, *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	PHALCON_INIT_VAR(index);
	ZVAL_LONG(index, 1);
	
	PHALCON_INIT_VAR(data);
	phalcon_call_method_p2(data, this_ptr, "readcolumnmapindex", model, index);
	if (Z_TYPE_P(data) != IS_NULL) {
		if (Z_TYPE_P(data) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The meta-data is invalid or is corrupt");
			return;
		}
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
 * @param Phalcon\Mvc\ModelInterface $model
 * @param string $attribute
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, hasAttribute){

	zval *model, *attribute, *column_map, *meta_data;
	zval *data_types;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model, &attribute);
	
	if (Z_TYPE_P(attribute) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Attribute must be a string");
		return;
	}
	
	PHALCON_INIT_VAR(column_map);
	phalcon_call_method_p1(column_map, this_ptr, "getreversecolumnmap", model);
	if (Z_TYPE_P(column_map) == IS_ARRAY) { 
		if (phalcon_array_isset(column_map, attribute)) {
			RETURN_MM_TRUE;
		}
	} else {
		PHALCON_INIT_VAR(meta_data);
		phalcon_call_method_p1(meta_data, this_ptr, "readmetadata", model);
	
		PHALCON_OBS_VAR(data_types);
		phalcon_array_fetch_long(&data_types, meta_data, 4, PH_NOISY_CC);
		if (phalcon_array_isset(data_types, attribute)) {
			RETURN_MM_TRUE;
		}
	}
	
	RETURN_MM_FALSE;
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
PHP_METHOD(Phalcon_Mvc_Model_MetaData, isEmpty){

	zval *meta_data;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(meta_data);
	phalcon_read_property_this(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
	if (phalcon_fast_count_ev(meta_data TSRMLS_CC)) {
		RETURN_MM_FALSE;
	}
	
	RETURN_MM_TRUE;
}

/**
 * Resets internal meta-data in order to regenerate it
 *
 *<code>
 *	$metaData->reset();
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, reset){

	zval *empty_array;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);
	phalcon_update_property_this(this_ptr, SL("_metaData"), empty_array TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_columnMap"), empty_array TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

