
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
  |          Kenji Minamoto <kenji.minamoto@gmail.com>                     |
  +------------------------------------------------------------------------+
*/

#include "mvc/model/query.h"
#include "mvc/model/queryinterface.h"
#include "mvc/model/query/scanner.h"
#include "mvc/model/query/phql.h"
#include "mvc/model/query/status.h"
#include "mvc/model/resultset/complex.h"
#include "mvc/model/resultset/simple.h"
#include "mvc/model/exception.h"
#include "mvc/model/managerinterface.h"
#include "mvc/model/metadatainterface.h"
#include "mvc/model/row.h"
#include "cache/backendinterface.h"
#include "cache/frontendinterface.h"
#include "diinterface.h"
#include "di/injectionawareinterface.h"
#include "db/rawvalue.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/framework/orm.h"
#include "kernel/hash.h"
#include "kernel/file.h"

#include "interned-strings.h"

/**
 * Phalcon\Mvc\Model\Query
 *
 * This class takes a PHQL intermediate representation and executes it.
 *
 *<code>
 *
 * $phql = "SELECT c.price*0.16 AS taxes, c.* FROM Cars AS c JOIN Brands AS b
 *          WHERE b.name = :name: ORDER BY c.name";
 *
 * $result = $manager->executeQuery($phql, array(
 *   'name' => 'Lamborghini'
 * ));
 *
 * foreach ($result as $row) {
 *   echo "Name: ", $row->cars->name, "\n";
 *   echo "Price: ", $row->cars->price, "\n";
 *   echo "Taxes: ", $row->taxes, "\n";
 * }
 *
 *</code>
 */
zend_class_entry *phalcon_mvc_model_query_ce;

PHP_METHOD(Phalcon_Mvc_Model_Query, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Query, setDI);
PHP_METHOD(Phalcon_Mvc_Model_Query, getDI);
PHP_METHOD(Phalcon_Mvc_Model_Query, setUniqueRow);
PHP_METHOD(Phalcon_Mvc_Model_Query, getUniqueRow);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getQualified);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getCallArgument);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getFunctionCall);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getExpression);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getSelectColumn);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getTable);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoin);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoinType);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getSingleJoin);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getMultiJoin);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoins);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getOrderClause);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getGroupClause);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getLimitClause);
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareSelect);
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareInsert);
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareUpdate);
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareDelete);
PHP_METHOD(Phalcon_Mvc_Model_Query, parse);
PHP_METHOD(Phalcon_Mvc_Model_Query, cache);
PHP_METHOD(Phalcon_Mvc_Model_Query, getCacheOptions);
PHP_METHOD(Phalcon_Mvc_Model_Query, getCache);
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeSelect);
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeInsert);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getRelatedRecords);
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeUpdate);
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeDelete);
PHP_METHOD(Phalcon_Mvc_Model_Query, execute);
PHP_METHOD(Phalcon_Mvc_Model_Query, getSingleResult);
PHP_METHOD(Phalcon_Mvc_Model_Query, setType);
PHP_METHOD(Phalcon_Mvc_Model_Query, getType);
PHP_METHOD(Phalcon_Mvc_Model_Query, setBindParams);
PHP_METHOD(Phalcon_Mvc_Model_Query, getBindParams);
PHP_METHOD(Phalcon_Mvc_Model_Query, setBindTypes);
PHP_METHOD(Phalcon_Mvc_Model_Query, getBindTypes);
PHP_METHOD(Phalcon_Mvc_Model_Query, setIntermediate);
PHP_METHOD(Phalcon_Mvc_Model_Query, getIntermediate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, phql)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_setuniquerow, 0, 0, 1)
	ZEND_ARG_INFO(0, uniqueRow)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_cache, 0, 0, 1)
	ZEND_ARG_INFO(0, cacheOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_getsingleresult, 0, 0, 0)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_setbindparams, 0, 0, 1)
	ZEND_ARG_INFO(0, bindParams)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_setbindtypes, 0, 0, 1)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_setintermediate, 0, 0, 1)
	ZEND_ARG_INFO(0, intermediate)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_model_query_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_Query, __construct, arginfo_phalcon_mvc_model_query___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Query, setDI, arginfo_phalcon_di_injectionawareinterface_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getDI, arginfo_phalcon_di_injectionawareinterface_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, setUniqueRow, arginfo_phalcon_mvc_model_query_setuniquerow, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getUniqueRow, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, _getQualified, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _getCallArgument, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _getFunctionCall, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _getExpression, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _getSelectColumn, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _getTable, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _getJoin, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _getJoinType, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _getSingleJoin, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _getMultiJoin, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _getJoins, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _getOrderClause, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _getGroupClause, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _getLimitClause, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _prepareSelect, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _prepareInsert, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _prepareUpdate, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _prepareDelete, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, parse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, cache, arginfo_phalcon_mvc_model_query_cache, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getCacheOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getCache, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, _executeSelect, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _executeInsert, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _getRelatedRecords, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _executeUpdate, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, _executeDelete, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Query, execute, arginfo_phalcon_mvc_model_queryinterface_execute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getSingleResult, arginfo_phalcon_mvc_model_query_getsingleresult, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, setType, arginfo_phalcon_mvc_model_query_settype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, setBindParams, arginfo_phalcon_mvc_model_query_setbindparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getBindParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, setBindTypes, arginfo_phalcon_mvc_model_query_setbindtypes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getBindTypes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, setIntermediate, arginfo_phalcon_mvc_model_query_setintermediate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getIntermediate, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\Query initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Query){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model, Query, mvc_model_query, phalcon_mvc_model_query_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_manager"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_metaData"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_phql"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_ast"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_intermediate"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_models"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_sqlAliases"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_sqlAliasesModels"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_sqlModelsAliases"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_sqlAliasesModelsInstances"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_sqlColumnAliases"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_modelsInstances"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_cache"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_cacheOptions"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_uniqueRow"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_bindParams"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_bindTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_irPhqlCache"), ZEND_ACC_STATIC|ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_query_ce, SL("TYPE_SELECT"), 309 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_query_ce, SL("TYPE_INSERT"), 306 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_query_ce, SL("TYPE_UPDATE"), 300 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_query_ce, SL("TYPE_DELETE"), 303 TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_query_ce TSRMLS_CC, 2, phalcon_mvc_model_queryinterface_ce, phalcon_di_injectionawareinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Query constructor
 *
 * @param string $phql
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, __construct){

	zval *phql = NULL, *dependency_injector = NULL;

	phalcon_fetch_params(0, 0, 2, &phql, &dependency_injector);
	
	if (phql && Z_TYPE_P(phql) != IS_NULL) {
		phalcon_update_property_this(this_ptr, SL("_phql"), phql TSRMLS_CC);
	}

	if (dependency_injector && Z_TYPE_P(dependency_injector) == IS_OBJECT) {
		PHALCON_MM_GROW();
		PHALCON_CALL_METHOD(NULL, this_ptr, "setdi", dependency_injector);
		PHALCON_MM_RESTORE();
	}
}

/**
 * Sets the dependency injection container
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setDI){

	zval *dependency_injector, *service = NULL, *manager = NULL;
	zval *meta_data = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &dependency_injector);
	PHALCON_VERIFY_INTERFACE_EX(dependency_injector, phalcon_diinterface_ce, phalcon_mvc_model_exception_ce, 1);
	
	PHALCON_INIT_VAR(service);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_modelsManager);
	
	PHALCON_CALL_METHOD(&manager, dependency_injector, "getshared", service);
	if (Z_TYPE_P(manager) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Injected service 'modelsManager' is invalid");
		return;
	}
	
	PHALCON_VERIFY_INTERFACE(manager, phalcon_mvc_model_managerinterface_ce);

	PHALCON_INIT_NVAR(service);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_modelsMetadata);
	
	PHALCON_CALL_METHOD(&meta_data, dependency_injector, "getshared", service);
	if (Z_TYPE_P(meta_data) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Injected service 'modelsMetadata' is invalid");
		return;
	}
	
	PHALCON_VERIFY_INTERFACE(meta_data, phalcon_mvc_model_metadatainterface_ce);

	phalcon_update_property_this(this_ptr, SL("_manager"), manager TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_metaData"), meta_data TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the dependency injection container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Tells to the query if only the first row in the resultset must be returned
 *
 * @param boolean $uniqueRow
 * @return Phalcon\Mvc\Model\Query
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setUniqueRow){

	zval *unique_row;

	phalcon_fetch_params(0, 1, 0, &unique_row);
	
	phalcon_update_property_this(this_ptr, SL("_uniqueRow"), unique_row TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Check if the query is programmed to get only the first row in the resultset
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getUniqueRow){


	RETURN_MEMBER(this_ptr, "_uniqueRow");
}

/**
 * Replaces the model's name to its source name in a qualifed-name expression
 *
 * @param array $expr
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getQualified){

	zval *expr, *column_name, *sql_column_aliases;
	zval *meta_data, *column_domain;
	zval *source, *exception_message = NULL;
	zval *model = NULL, *column_map = NULL, *real_column_name = NULL;
	zval *has_model = NULL, *models_instances;
	zval *has_attribute = NULL, *models, *class_name;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	zval *s_qualified;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &expr);
	
	PHALCON_OBS_VAR(column_name);
	phalcon_array_fetch_string(&column_name, expr, ISL(name), PH_NOISY);
	
	sql_column_aliases = phalcon_fetch_nproperty_this(this_ptr, SL("_sqlColumnAliases"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * Check if the qualified name is a column alias
	 */
	if (phalcon_array_isset(sql_column_aliases, column_name)) {
		array_init_size(return_value, 2);
		MAKE_STD_ZVAL(s_qualified);
		PHALCON_ZVAL_MAYBE_INTERNED_STRING(s_qualified, phalcon_interned_qualified);
		add_assoc_zval_ex(return_value, ISS(type), s_qualified);
		phalcon_array_update_string(&return_value, ISL(name), column_name, PH_COPY);
		RETURN_MM();
	}
	
	meta_data = phalcon_fetch_nproperty_this(this_ptr, SL("_metaData"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * Check if the qualified name has a domain
	 */
	if (phalcon_array_isset_string(expr, SS("domain"))) {
		zval *sql_aliases;

		PHALCON_OBS_VAR(column_domain);
		phalcon_array_fetch_string(&column_domain, expr, ISL(domain), PH_NOISY);
	
		sql_aliases = phalcon_fetch_nproperty_this(this_ptr, SL("_sqlAliases"), PH_NOISY TSRMLS_CC);
	
		/** 
		 * The column has a domain, we need to check if it's an alias
		 */
		if (!phalcon_array_isset_fetch(&source, sql_aliases, column_domain)) {
			zval *phql = phalcon_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY TSRMLS_CC);
	
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SVSV(exception_message, "Unknown model or alias '", column_domain, "' (1), when preparing: ", phql);
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
		}
	
		/** 
		 * Change the selected column by its real name on its mapped table
		 */
		if (PHALCON_GLOBAL(orm).column_renaming) {
	
			/** 
			 * Retrieve the corresponding model by its alias
			 */
			zval *sql_aliases_models_instances = phalcon_fetch_nproperty_this(this_ptr, SL("_sqlAliasesModelsInstances"), PH_NOISY TSRMLS_CC);
	
			/** 
			 * We need to model instance to retrieve the reversed column map
			 */
			if (!phalcon_array_isset(sql_aliases_models_instances, column_domain)) {
				zval *phql = phalcon_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY TSRMLS_CC);
	
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVSV(exception_message, "There is no model related to model or alias '", column_domain, "', when executing: ", phql);
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
	
			PHALCON_OBS_VAR(model);
			phalcon_array_fetch(&model, sql_aliases_models_instances, column_domain, PH_NOISY);
	
			PHALCON_CALL_METHOD(&column_map, meta_data, "getreversecolumnmap", model);
		} else {
			PHALCON_INIT_VAR(column_map);
		}
	
		if (Z_TYPE_P(column_map) == IS_ARRAY) { 
			if (phalcon_array_isset(column_map, column_name)) {
				PHALCON_OBS_VAR(real_column_name);
				phalcon_array_fetch(&real_column_name, column_map, column_name, PH_NOISY);
			} else {
				zval *phql = phalcon_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY TSRMLS_CC);
	
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVSVSV(exception_message, "Column '", column_name, "' doesn't belong to the model or alias '", column_domain, "', when executing: ", phql);
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
		} else {
			PHALCON_CPY_WRT(real_column_name, column_name);
		}
	} else {
		long int number = 0;

		/** 
		 * If the column IR doesn't have a domain, we must check for ambiguities
		 */
		PHALCON_INIT_VAR(has_model);
		ZVAL_FALSE(has_model);
	
		PHALCON_OBS_VAR(models_instances);
		phalcon_read_property_this(&models_instances, this_ptr, SL("_modelsInstances"), PH_NOISY TSRMLS_CC);
	
		phalcon_is_iterable(models_instances, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(model);
	
			/** 
			 * Check if the atribute belongs to the current model
			 */
			PHALCON_CALL_METHOD(&has_attribute, meta_data, "hasattribute", model, column_name);
			if (zend_is_true(has_attribute)) {
				++number;
				if (number > 1) {
					zval *phql = phalcon_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY TSRMLS_CC);
	
					PHALCON_INIT_NVAR(exception_message);
					PHALCON_CONCAT_SVSV(exception_message, "The column '", column_name, "' is ambiguous, when preparing: ", phql);
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
					return;
				}
	
				PHALCON_CPY_WRT(has_model, model);
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		/** 
		 * After check in every model, the column does not belong to any of the selected
		 * models
		 */
		if (PHALCON_IS_FALSE(has_model)) {
			zval *phql = phalcon_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY TSRMLS_CC);
	
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_SVSV(exception_message, "Column '", column_name, "' doesn't belong to any of the selected models (1), when preparing: ", phql);
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
		}
	
		/** 
		 * Check if the _models property is correctly prepared
		 */
		PHALCON_OBS_VAR(models);
		phalcon_read_property_this(&models, this_ptr, SL("_models"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(models) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The models list was not loaded correctly");
			return;
		}
	
		/** 
		 * Obtain the model's source from the _models list
		 */
		PHALCON_INIT_VAR(class_name);
		phalcon_get_class(class_name, has_model, 0 TSRMLS_CC);
		if (!phalcon_array_isset_fetch(&source, models, class_name)) {
			zval *phql = phalcon_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY TSRMLS_CC);
	
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_SVSV(exception_message, "Column '", column_name, "' doesn't belong to any of the selected models (2), when preparing: ", phql);
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
		}
	
		/** 
		 * Rename the column
		 */
		if (PHALCON_GLOBAL(orm).column_renaming) {
			PHALCON_CALL_METHOD(&column_map, meta_data, "getreversecolumnmap", has_model);
		} else {
			PHALCON_INIT_VAR(column_map);
		}
	
		if (Z_TYPE_P(column_map) == IS_ARRAY) {
	
			/** 
			 * The real column name is in the column map
			 */
			if (phalcon_array_isset(column_map, column_name)) {
				PHALCON_OBS_NVAR(real_column_name);
				phalcon_array_fetch(&real_column_name, column_map, column_name, PH_NOISY);
			} else {
				zval *phql = phalcon_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY TSRMLS_CC);
	
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVSV(exception_message, "Column '", column_name, "' doesn't belong to any of the selected models (3), when preparing: ", phql);
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
		} else {
			PHALCON_CPY_WRT(real_column_name, column_name);
		}
	}
	
	/** 
	 * Create an array with the qualified info
	 */
	MAKE_STD_ZVAL(s_qualified);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(s_qualified, phalcon_interned_qualified);
	array_init_size(return_value, 4);
	add_assoc_zval_ex(return_value, ISS(type), s_qualified);
	phalcon_array_update_string(&return_value, ISL(domain), source, PH_COPY);
	phalcon_array_update_string(&return_value, ISL(name), real_column_name, PH_COPY);
	phalcon_array_update_string(&return_value, ISL(balias), column_name, PH_COPY);
	
	RETURN_MM();
}

/**
 * Resolves a expression in a single call argument
 *
 * @param array $argument
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getCallArgument){

	zval *argument, *argument_type;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &argument);
	
	PHALCON_OBS_VAR(argument_type);
	phalcon_array_fetch_string(&argument_type, argument, ISL(type), PH_NOISY);
	if (PHALCON_IS_LONG(argument_type, PHQL_T_STARALL)) {
		zval *s_all;
		MAKE_STD_ZVAL(s_all);
		PHALCON_ZVAL_MAYBE_INTERNED_STRING(s_all, phalcon_interned_all);
		array_init_size(return_value, 1);
		add_assoc_zval_ex(return_value, ISS(type), s_all);
		RETURN_MM();
	}
	
	PHALCON_RETURN_CALL_METHOD(this_ptr, "_getexpression", argument);
	RETURN_MM();
}

/**
 * Resolves a expression in a single call argument
 *
 * @param array $expr
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getFunctionCall){

	zval *expr, *name, *arguments, *function_args = NULL, *argument = NULL;
	zval *argument_expr = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int distinct;

	zval *s_functionCall;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &expr);
	
	array_init_size(return_value, 4);

	PHALCON_OBS_VAR(name);
	phalcon_array_fetch_string(&name, expr, ISL(name), PH_NOISY);
	if (phalcon_array_isset_string_fetch(&arguments, expr, SS("arguments"))) {

		distinct = phalcon_array_isset_string(expr, SS("distinct")) ? 1 : 0;
	
		if (phalcon_array_isset_long(arguments, 0)) {
	
			/** 
			 * There are more than one argument
			 */
			PHALCON_INIT_VAR(function_args);
			array_init_size(function_args, zend_hash_num_elements(Z_ARRVAL_P(arguments)));
	
			phalcon_is_iterable(arguments, &ah0, &hp0, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_HVALUE(argument);
	
				PHALCON_CALL_METHOD(&argument_expr, this_ptr, "_getcallargument", argument);
				phalcon_array_append(&function_args, argument_expr, 0);
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
		} else {
			/** 
			 * There is only one argument
			 */
			PHALCON_CALL_METHOD(&argument_expr, this_ptr, "_getcallargument", arguments);
	
			PHALCON_INIT_NVAR(function_args);
			array_init_size(function_args, 1);
			phalcon_array_append(&function_args, argument_expr, 0);
		}
	
		MAKE_STD_ZVAL(s_functionCall);
		PHALCON_ZVAL_MAYBE_INTERNED_STRING(s_functionCall, phalcon_interned_functionCall);
		add_assoc_zval_ex(return_value, ISS(type), s_functionCall);
		phalcon_array_update_string(&return_value, ISL(name), name, PH_COPY);
		phalcon_array_update_string(&return_value, ISL(arguments), function_args, PH_COPY);

		if (distinct) {
			add_assoc_bool_ex(return_value, ISS(distinct), distinct);
		}
	} else {
		MAKE_STD_ZVAL(s_functionCall);
		PHALCON_ZVAL_MAYBE_INTERNED_STRING(s_functionCall, phalcon_interned_functionCall);
		add_assoc_zval_ex(return_value, ISS(type), s_functionCall);
		phalcon_array_update_string(&return_value, ISL(name), name, PH_COPY);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Resolves an expression from its intermediate code into a string
 *
 * @param array $expr
 * @param boolean $quoting
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getExpression){

	zval *expr, *quoting = NULL, *temp_not_quoting;
	zval *left = NULL, *right = NULL, *expr_type;
	zval *expr_value = NULL, *value = NULL, *escaped_value = NULL;
	zval *placeholder = NULL, *exception_message;
	zval *list_items, *expr_list_item = NULL;
	zval *expr_item = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &expr, &quoting);
	
	if (!quoting) {
		quoting = PHALCON_GLOBAL(z_true);
	}
	
	if (phalcon_array_isset_string(expr, ISS(type))) {
		zval *expr_left, *expr_right;

		PHALCON_INIT_VAR(temp_not_quoting);
		ZVAL_TRUE(temp_not_quoting);
	
		/** 
		 * Resolving left part of the expression if any
		 */
		if (phalcon_array_isset_string_fetch(&expr_left, expr, SS("left"))) {
			PHALCON_CALL_METHOD(&left, this_ptr, "_getexpression", expr_left, temp_not_quoting);
		}
	
		/** 
		 * Resolving right part of the expression if any
		 */
		if (phalcon_array_isset_string_fetch(&expr_right, expr, SS("right"))) {
			PHALCON_CALL_METHOD(&right, this_ptr, "_getexpression", expr_right, temp_not_quoting);
		}
	
		/** 
		 * Every node in the AST has a unique integer type
		 */
		PHALCON_OBS_VAR(expr_type);
		phalcon_array_fetch_string(&expr_type, expr, ISL(type), PH_NOISY);
	
		switch (phalcon_get_intval(expr_type)) {
	
			case PHQL_T_LESS:
				assert(left != NULL && right != NULL);
				array_init_size(return_value, 4);
				add_assoc_stringl_ex(return_value, ISS(type), SL("binary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL("<"), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
	
			case PHQL_T_EQUALS:
				assert(left != NULL && right != NULL);
				array_init_size(return_value, 4);
				add_assoc_stringl_ex(return_value, ISS(type), SL("binary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL("="), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
	
			case PHQL_T_GREATER:
				assert(left != NULL && right != NULL);
				array_init_size(return_value, 4);
				add_assoc_stringl_ex(return_value, ISS(type), SL("binary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL(">"), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
	
			case PHQL_T_NOTEQUALS:
				assert(left != NULL && right != NULL);
				array_init_size(return_value, 4);
				add_assoc_stringl_ex(return_value, ISS(type), SL("binary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL("<>"), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
	
			case PHQL_T_LESSEQUAL:
				assert(left != NULL && right != NULL);
				array_init_size(return_value, 4);
				add_assoc_stringl_ex(return_value, ISS(type), SL("binary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL("<="), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
	
			case PHQL_T_GREATEREQUAL:
				assert(left != NULL && right != NULL);
				array_init_size(return_value, 4);
				add_assoc_stringl_ex(return_value, ISS(type), SL("binary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL(">="), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
	
			case PHQL_T_AND:
				assert(left != NULL && right != NULL);
				array_init_size(return_value, 4);
				add_assoc_stringl_ex(return_value, ISS(type), SL("binary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL("AND"), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
	
			case PHQL_T_OR:
				assert(left != NULL && right != NULL);
				array_init_size(return_value, 4);
				add_assoc_stringl_ex(return_value, ISS(type), SL("binary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL("OR"), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
	
			case PHQL_T_QUALIFIED:
				PHALCON_RETURN_CALL_METHOD(this_ptr, "_getqualified", expr);
				break;
	
			case 359: /** @todo Is this code returned anywhere? */
				PHALCON_RETURN_CALL_METHOD(this_ptr, "_getaliased", expr);
				break;
	
			case PHQL_T_ADD:
				assert(left != NULL && right != NULL);
				array_init_size(return_value, 4);
				add_assoc_stringl_ex(return_value, ISS(type), SL("binary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL("+"), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
	
			case PHQL_T_SUB:
				assert(left != NULL && right != NULL);
				array_init_size(return_value, 4);
				add_assoc_stringl_ex(return_value, ISS(type), SL("binary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL("-"), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
	
			case PHQL_T_MUL:
				assert(left != NULL && right != NULL);
				array_init_size(return_value, 4);
				add_assoc_stringl_ex(return_value, ISS(type), SL("binary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL("*"), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
	
			case PHQL_T_DIV:
				assert(left != NULL && right != NULL);
				array_init_size(return_value, 4);
				add_assoc_stringl_ex(return_value, ISS(type), SL("binary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL("/"), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
	
			case PHQL_T_MOD:
				assert(left != NULL && right != NULL);
				array_init_size(return_value, 4);
				add_assoc_stringl_ex(return_value, ISS(type), SL("binary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL("%"), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
	
			case PHQL_T_BITWISE_AND:
				assert(left != NULL && right != NULL);
				array_init_size(return_value, 4);
				add_assoc_stringl_ex(return_value, ISS(type), SL("binary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL("&"), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
	
			case PHQL_T_BITWISE_OR:
				assert(left != NULL && right != NULL);
				array_init_size(return_value, 4);
				add_assoc_stringl_ex(return_value, ISS(type), SL("binary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL("|"), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
	
			case PHQL_T_ENCLOSED:
				assert(left != NULL);
				array_init_size(return_value, 2);
				add_assoc_stringl_ex(return_value, ISS(type), SL("parentheses"), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				break;
	
			case PHQL_T_MINUS:
				assert(right != NULL);
				array_init_size(return_value, 3);
				add_assoc_stringl_ex(return_value, ISS(type), SL("unary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL("-"), 1);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
	
			case PHQL_T_INTEGER:
			case PHQL_T_DOUBLE:
				PHALCON_OBS_VAR(value);
				phalcon_array_fetch_string(&value, expr, SL("value"), PH_NOISY);
	
				array_init_size(return_value, 2);
				add_assoc_stringl_ex(return_value, ISS(type), SL("literal"), 1);
				phalcon_array_update_string(&return_value, ISL(value), value, PH_COPY);
				break;
			
			case PHQL_T_RAW_QUALIFIED:
				PHALCON_OBS_VAR(value);
				phalcon_array_fetch_string(&value, expr, SL("name"), PH_NOISY);
	
				array_init_size(return_value, 2);
				add_assoc_stringl_ex(return_value, ISS(type), SL("literal"), 1);
				phalcon_array_update_string(&return_value, ISL(value), value, PH_COPY);
				break;

			case PHQL_T_TRUE:
				array_init_size(return_value, 2);
				add_assoc_stringl_ex(return_value, ISS(type), SL("literal"), 1);
				add_assoc_stringl_ex(return_value, ISS(value), SL("TRUE"), 1);
				break;
	
			case PHQL_T_FALSE:
				array_init_size(return_value, 2);
				add_assoc_stringl_ex(return_value, ISS(type), SL("literal"), 1);
				add_assoc_stringl_ex(return_value, ISS(value), SL("FALSE"), 1);
				break;
	
			case PHQL_T_STRING:
				PHALCON_OBS_VAR(value);
				phalcon_array_fetch_string(&value, expr, SL("value"), PH_NOISY);
				if (PHALCON_IS_TRUE(quoting)) {
	
					/** 
					 * Check if static literals have single quotes and escape them
					 */
					if (phalcon_memnstr_str(value, SL("'"))) {
						PHALCON_INIT_VAR(escaped_value);
						phalcon_orm_singlequotes(escaped_value, value TSRMLS_CC);
					} else {
						PHALCON_CPY_WRT(escaped_value, value);
					}
	
					PHALCON_INIT_VAR(expr_value);
					PHALCON_CONCAT_SVS(expr_value, "'", escaped_value, "'");
				} else {
					PHALCON_CPY_WRT(expr_value, value);
				}
	
				array_init_size(return_value, 2);
				add_assoc_stringl_ex(return_value, ISS(type), SL("literal"), 1);
				phalcon_array_update_string(&return_value, ISL(value), expr_value, PH_COPY);
				break;
	
			case PHQL_T_NPLACEHOLDER: {
				zval question_mark, colon;

				PHALCON_OBS_VAR(value);
				phalcon_array_fetch_string(&value, expr, SL("value"), PH_NOISY);
	
				INIT_ZVAL(question_mark);
				INIT_ZVAL(colon);

				ZVAL_STRING(&question_mark, "?", 0);
				ZVAL_STRING(&colon, ":", 0);
	
				PHALCON_INIT_VAR(placeholder);
				phalcon_fast_str_replace(placeholder, &question_mark, &colon, value);
	
				array_init_size(return_value, 2);
				add_assoc_stringl_ex(return_value, ISS(type), SL("placeholder"), 1);
				phalcon_array_update_string(&return_value, ISL(value), placeholder, PH_COPY);
				break;
			}
	
			case PHQL_T_SPLACEHOLDER:
				PHALCON_OBS_NVAR(value);
				phalcon_array_fetch_string(&value, expr, SL("value"), PH_NOISY);
	
				PHALCON_INIT_NVAR(placeholder);
				PHALCON_CONCAT_SV(placeholder, ":", value);
	
				array_init_size(return_value, 2);
				add_assoc_stringl_ex(return_value, ISS(type), SL("placeholder"), 1);
				phalcon_array_update_string(&return_value, ISL(value), placeholder, PH_COPY);
				break;
	
			case PHQL_T_NULL:
				array_init_size(return_value, 2);
				add_assoc_stringl_ex(return_value, ISS(type), SL("literal"), 1);
				add_assoc_stringl_ex(return_value, ISS(value), SL("NULL"), 1);
				break;
	
			case PHQL_T_LIKE:
				assert(left != NULL && right != NULL);
				array_init_size(return_value, 4);
				add_assoc_stringl_ex(return_value, ISS(type), SL("binary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL("LIKE"), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
	
			case PHQL_T_NLIKE:
				assert(left != NULL && right != NULL);
				array_init_size(return_value, 4);
				add_assoc_stringl_ex(return_value, ISS(type), SL("binary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL("NOT LIKE"), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
	
			case PHQL_T_ILIKE:
				assert(left != NULL && right != NULL);
				array_init_size(return_value, 4);
				add_assoc_stringl_ex(return_value, ISS(type), SL("binary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL("ILIKE"), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
	
			case PHQL_T_NILIKE:
				assert(left != NULL && right != NULL);
				array_init_size(return_value, 4);
				add_assoc_stringl_ex(return_value, ISS(type), SL("binary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL("NOT ILIKE"), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
	
			case PHQL_T_NOT:
				assert(right != NULL);
				array_init_size(return_value, 3);
				add_assoc_stringl_ex(return_value, ISS(type), SL("unary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL("NOT "), 1);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
	
			case PHQL_T_ISNULL:
				assert(left != NULL);
				array_init_size(return_value, 3);
				add_assoc_stringl_ex(return_value, ISS(type), SL("unary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL(" IS NULL"), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				break;
	
			case PHQL_T_ISNOTNULL:
				assert(left != NULL);
				array_init_size(return_value, 3);
				add_assoc_stringl_ex(return_value, ISS(type), SL("unary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL(" IS NOT NULL"), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				break;
	
			case PHQL_T_IN:
				assert(left != NULL && right != NULL);
				array_init_size(return_value, 4);
				add_assoc_stringl_ex(return_value, ISS(type), SL("binary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL("IN"), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
	
			case PHQL_T_NOTIN:
				assert(left != NULL && right != NULL);
				array_init_size(return_value, 4);
				add_assoc_stringl_ex(return_value, ISS(type), SL("binary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL("NOT IN"), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
	
			case PHQL_T_DISTINCT:
				assert(0);
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Unexpected PHQL_T_DISTINCT - this should not happen");
				return;
			/*
				assert(right != NULL);
				array_init_size(return_value, 3);
				add_assoc_stringl_ex(return_value, ISS(type), SL("unary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL("DISTINCT "), 1);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
			*/
	
			case PHQL_T_BETWEEN:
				assert(left != NULL && right != NULL);
				array_init_size(return_value, 4);
				add_assoc_stringl_ex(return_value, ISS(type), SL("binary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL("BETWEEN"), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
	
			case PHQL_T_AGAINST:
				assert(left != NULL && right != NULL);
				array_init_size(return_value, 4);
				add_assoc_stringl_ex(return_value, ISS(type), SL("binary-op"), 1);
				add_assoc_stringl_ex(return_value, ISS(op), SL("AGAINST"), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
	
			case PHQL_T_CAST:
				assert(left != NULL && right != NULL);
				array_init_size(return_value, 3);
				add_assoc_stringl_ex(return_value, ISS(type), SL("cast"), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
	
			case PHQL_T_CONVERT:
				assert(left != NULL && right != NULL);
				array_init_size(return_value, 3);
				add_assoc_stringl_ex(return_value, ISS(type), SL("convert"), 1);
				phalcon_array_update_string(&return_value, ISL(left), left, PH_COPY);
				phalcon_array_update_string(&return_value, ISL(right), right, PH_COPY);
				break;
	
			case PHQL_T_FCALL:
				PHALCON_RETURN_CALL_METHOD(this_ptr, "_getfunctioncall", expr);
				break;
	
			default:
				PHALCON_INIT_VAR(exception_message);
				PHALCON_CONCAT_SV(exception_message, "Unknown expression type ", expr_type);
	
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
		}
	
		RETURN_MM();
	}
	
	/** 
	 * Is a qualified column
	 */
	if (phalcon_array_isset_string(expr, SS("domain"))) {
		PHALCON_RETURN_CALL_METHOD(this_ptr, "_getqualified", expr);
		RETURN_MM();
	}
	
	/** 
	 * Is the expression doesn't have a type it's a list of nodes
	 */
	if (phalcon_array_isset_long(expr, 0)) {
	
		PHALCON_INIT_VAR(list_items);
		array_init(list_items);
	
		phalcon_is_iterable(expr, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(expr_list_item);
	
			PHALCON_CALL_METHOD(&expr_item, this_ptr, "_getexpression", expr_list_item);
			phalcon_array_append(&list_items, expr_item, 0);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		array_init_size(return_value, 2);
		add_assoc_stringl_ex(return_value, ISS(type), SL("list"), 1);
		phalcon_array_append(&return_value, list_items, 0);
	
		RETURN_MM();
	}
	
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Unknown expression");
	return;
}

/**
 * Resolves a column from its intermediate representation into an array used to determine
 * if the resulset produced is simple or complex
 *
 * @param array $column
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getSelectColumn){

	zval *column, *column_type;
	zval *source = NULL, *model_name = NULL, *sql_column = NULL;
	zval *column_domain, *exception_message = NULL;
	zval *sql_column_alias = NULL;
	zval *prepared_alias = NULL;
	zval *column_data, *sql_expr_column = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &column);
	
	if (!phalcon_array_isset_string(column, ISS(type))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	
	/** 
	 * Check for select * (all)
	 */
	PHALCON_OBS_VAR(column_type);
	phalcon_array_fetch_string(&column_type, column, ISL(type), PH_NOISY);
	if (PHALCON_IS_LONG(column_type, PHQL_T_STARALL)) {
		zval *models = phalcon_fetch_nproperty_this(this_ptr, SL("_models"), PH_NOISY TSRMLS_CC);
	
		phalcon_is_iterable(models, &ah0, &hp0, 0, 0);

		array_init_size(return_value, zend_hash_num_elements(ah0));
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HKEY(model_name, ah0, hp0);
			PHALCON_GET_HVALUE(source);
	
			PHALCON_INIT_NVAR(sql_column);
			array_init_size(sql_column, 3);
			add_assoc_stringl_ex(sql_column, ISS(type), SL("object"), 1);
			phalcon_array_update_string(&sql_column, ISL(model), model_name, PH_COPY);
			phalcon_array_update_string(&sql_column, ISL(column), source, PH_COPY);

			phalcon_array_append(&return_value, sql_column, 0);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		RETURN_MM();
	}
	
	if (!phalcon_array_isset_string(column, SS("column"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	
	/** 
	 * Check if selected column is qualified.*
	 */
	if (PHALCON_IS_LONG(column_type, PHQL_T_DOMAINALL)) {
		zval *source, *sql_aliases_models;
		zval *sql_aliases = phalcon_fetch_nproperty_this(this_ptr, SL("_sqlAliases"), PH_NOISY TSRMLS_CC);
	
		/** 
		 * We only allow the alias.*
		 */
		PHALCON_OBS_VAR(column_domain);
		phalcon_array_fetch_string(&column_domain, column, SL("column"), PH_NOISY);
		if (!phalcon_array_isset_fetch(&source, sql_aliases, column_domain)) {
			zval *phql = phalcon_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY TSRMLS_CC);
	
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SVSV(exception_message, "Unknown model or alias '", column_domain, "' (2), when preparing: ", phql);
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
		}
	
		/** 
		 * Get the SQL alias if any
		 */
		PHALCON_CPY_WRT(sql_column_alias, source);
	
		/** 
		 * Get the real source name
		 */
		sql_aliases_models = phalcon_fetch_nproperty_this(this_ptr, SL("_sqlAliasesModels"), PH_NOISY TSRMLS_CC);
	
		PHALCON_OBS_VAR(model_name);
		phalcon_array_fetch(&model_name, sql_aliases_models, column_domain, PH_NOISY);
	
		if (PHALCON_IS_EQUAL(column_domain, model_name)) {
			PHALCON_INIT_VAR(prepared_alias);
			phalcon_lcfirst(prepared_alias, model_name);
		} else {
			PHALCON_CPY_WRT(prepared_alias, column_domain);
		}
	
		/** 
		 * The sql_column is a complex type returning a complete object
		 */
		PHALCON_INIT_VAR(sql_column);
		array_init_size(sql_column, 4);
		add_assoc_stringl_ex(sql_column, ISS(type), SL("object"), 1);
		phalcon_array_update_string(&sql_column, ISL(model), model_name, PH_COPY);
		phalcon_array_update_string(&sql_column, ISL(column), sql_column_alias, PH_COPY);
		phalcon_array_update_string(&sql_column, ISL(balias), prepared_alias, PH_COPY);

		array_init_size(return_value, 1);
		phalcon_array_append(&return_value, sql_column, 0);
	
		RETURN_MM();
	}
	
	/** 
	 * Check for columns qualified and not qualified
	 */
	if (PHALCON_IS_LONG(column_type, PHQL_T_EXPR)) {
		zval *balias;

		/** 
		 * The sql_column is a scalar type returning a simple string
		 */
		PHALCON_INIT_NVAR(sql_column);
		array_init_size(sql_column, 4);
		add_assoc_stringl_ex(sql_column, ISS(type), SL("scalar"), 1);
	
		PHALCON_OBS_VAR(column_data);
		phalcon_array_fetch_string(&column_data, column, SL("column"), PH_NOISY);
	
		PHALCON_CALL_METHOD(&sql_expr_column, this_ptr, "_getexpression", column_data);
	
		/** 
		 * Create balias and sqlAlias
		 */
		if (phalcon_array_isset_string_fetch(&balias, sql_expr_column, SS("balias"))) {
			phalcon_array_update_string(&sql_column, ISL(balias), balias, PH_COPY);
			phalcon_array_update_string(&sql_column, ISL(sqlAlias), balias, PH_COPY);
		}
	
		phalcon_array_update_string(&sql_column, ISL(column), sql_expr_column, PH_COPY);

		array_init_size(return_value, 1);
		phalcon_array_append(&return_value, sql_column, 0);
	
		RETURN_MM();
	}
	
	PHALCON_INIT_VAR(exception_message);
	PHALCON_CONCAT_SV(exception_message, "Unknown type of column ", column_type);
	PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
	return;
}

/**
 * Resolves a table in a SELECT statement checking if the model exists
 *
 * @param Phalcon\Mvc\Model\ManagerInterface $manager
 * @param array $qualifiedName
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getTable){

	zval *manager, *qualified_name, *model_name;
	zval *model = NULL, *source = NULL, *schema = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &manager, &qualified_name);
	
	if (phalcon_array_isset_string_fetch(&model_name, qualified_name, SS("name"))) {
	
		PHALCON_CALL_METHOD(&model, manager, "load", model_name);
		PHALCON_CALL_METHOD(&source, model, "getsource");
		PHALCON_CALL_METHOD(&schema, model, "getschema");
		if (zend_is_true(schema)) {
			array_init_size(return_value, 2);
			phalcon_array_append(&return_value, schema, 0);
			phalcon_array_append(&return_value, source, 0);
			RETURN_MM();
		}
	
		RETURN_CTOR(source);
	}
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
	return;
}

/**
 * Resolves a JOIN clause checking if the associated models exist
 *
 * @param Phalcon\Mvc\Model\ManagerInterface $manager
 * @param array $join
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoin){

	zval *manager, *join, *qualified, *qualified_type;
	zval *model_name, *model = NULL, *source = NULL, *schema = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &manager, &join);
	
	if (phalcon_array_isset_string_fetch(&qualified, join, SS("qualified"))) {
	
		PHALCON_OBS_VAR(qualified_type);
		phalcon_array_fetch_string(&qualified_type, qualified, ISL(type), PH_NOISY);
		if (PHALCON_IS_LONG(qualified_type, PHQL_T_QUALIFIED)) {
			PHALCON_OBS_VAR(model_name);
			phalcon_array_fetch_string(&model_name, qualified, ISL(name), PH_NOISY);
	
			PHALCON_CALL_METHOD(&model, manager, "load", model_name);
			PHALCON_CALL_METHOD(&source, model, "getsource");
			PHALCON_CALL_METHOD(&schema, model, "getschema");
	
			array_init_size(return_value, 4);
			phalcon_array_update_string(&return_value, SL("schema"), schema, PH_COPY);
			phalcon_array_update_string(&return_value, SL("source"), source, PH_COPY);
			phalcon_array_update_string(&return_value, SL("modelName"), model_name, PH_COPY);
			phalcon_array_update_string(&return_value, SL("model"), model, PH_COPY);
			RETURN_MM();
		}
	}
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
	return;
}

/**
 * Resolves a JOIN type
 *
 * @param array $join
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoinType){

	zval *join, *type, *exception_message;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &join);
	
	if (!phalcon_array_isset_string(join, ISS(type))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	
	PHALCON_OBS_VAR(type);
	phalcon_array_fetch_string(&type, join, ISL(type), PH_NOISY);
	
	switch (phalcon_get_intval(type)) {
	
		case PHQL_T_INNERJOIN:
			RETVAL_STRING("INNER", 1);
			break;
	
		case PHQL_T_LEFTJOIN:
			RETVAL_STRING("LEFT", 1);
			break;
	
		case PHQL_T_RIGHTJOIN:
			RETVAL_STRING("RIGHT", 1);
			break;
	
		case PHQL_T_CROSSJOIN:
			RETVAL_STRING("CROSS", 1);
			break;
	
		case PHQL_T_FULLJOIN:
			RETVAL_STRING("FULL OUTER", 1);
			break;
	
		default: {
			zval *phql = phalcon_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY TSRMLS_CC);
	
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SVSV(exception_message, "Unknown join type ", type, ", when preparing: ", phql);
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
		}
	
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Resolves joins involving has-one/belongs-to/has-many relations
 *
 * @param string $joinType
 * @param string $joinSource
 * @param string $modelAlias
 * @param string $joinAlias
 * @param Phalcon\Mvc\Model\RelationInterface $relation
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getSingleJoin){

	zval *join_type, *join_source, *model_alias;
	zval *join_alias, *relation, *fields = NULL, *referenced_fields = NULL;
	zval *left = NULL, *left_expr = NULL, *right = NULL, *right_expr = NULL, *sql_join_condition;
	zval *sql_join_conditions, *sql_join_partial_conditions;
	zval *field = NULL, *position = NULL, *exception_message = NULL;
	zval *sql_equals_join_condition = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 5, 0, &join_type, &join_source, &model_alias, &join_alias, &relation);
	
	/** 
	 * Local fields in the 'from' relation
	 */
	PHALCON_CALL_METHOD(&fields, relation, "getfields");
	
	/** 
	 * Referenced fields in the joined relation
	 */
	PHALCON_CALL_METHOD(&referenced_fields, relation, "getreferencedfields");

	PHALCON_INIT_VAR(sql_join_conditions);
	array_init_size(sql_join_conditions, 1);

	if (Z_TYPE_P(fields) != IS_ARRAY) { 
		/** 
		 * Create the left part of the expression
		 */
		PHALCON_INIT_VAR(left);
		array_init_size(left, 3);
		add_assoc_long_ex(left, ISS(type), PHQL_T_QUALIFIED);
		phalcon_array_update_string(&left, ISL(domain), model_alias, PH_COPY);
		phalcon_array_update_string(&left, ISL(name), fields, PH_COPY);
	
		PHALCON_CALL_METHOD(&left_expr, this_ptr, "_getqualified", left);
	
		/** 
		 * Create the right part of the expression
		 */
		PHALCON_INIT_VAR(right);
		array_init_size(right, 3);
		add_assoc_stringl_ex(right, ISS(type), SL("qualified"), 1);
		phalcon_array_update_string(&right, ISL(domain), join_alias, PH_COPY);
		phalcon_array_update_string(&right, ISL(name), referenced_fields, PH_COPY);
	
		PHALCON_CALL_METHOD(&right_expr, this_ptr, "_getqualified", right);
	
		/** 
		 * Create a binary operation for the join conditions
		 */
		PHALCON_INIT_VAR(sql_join_condition);
		array_init_size(sql_join_condition, 4);
		add_assoc_stringl_ex(sql_join_condition, ISS(type), SL("binary-op"), 1);
		add_assoc_stringl_ex(sql_join_condition, ISS(op), SL("="), 1);
		phalcon_array_update_string(&sql_join_condition, ISL(left), left_expr, PH_COPY);
		phalcon_array_update_string(&sql_join_condition, ISL(right), right_expr, PH_COPY);
	
		phalcon_array_append(&sql_join_conditions, sql_join_condition, 0);
	} else {
		/** 
		 * Resolve the compound operation
		 */
		PHALCON_INIT_VAR(sql_join_partial_conditions);
	
		phalcon_is_iterable(fields, &ah0, &hp0, 0, 0);
		array_init_size(sql_join_partial_conditions, zend_hash_num_elements(ah0));
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
			zval *referenced_field;

			PHALCON_GET_HKEY(position, ah0, hp0);
			PHALCON_GET_HVALUE(field);
	
			if (!phalcon_array_isset_fetch(&referenced_field, referenced_fields, position)) {
				zval *phql = phalcon_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY TSRMLS_CC);
	
				PHALCON_INIT_VAR(exception_message);
				PHALCON_CONCAT_SVSVSV(exception_message, "The number of fields must be equal to the number of referenced fields in join ", model_alias, "-", join_alias, ", when preparing: ", phql);
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
	
			/** 
			 * Create the left part of the expression
			 */
			PHALCON_INIT_NVAR(left);
			array_init_size(left, 3);
			add_assoc_long_ex(left, ISS(type), PHQL_T_QUALIFIED);
			phalcon_array_update_string(&left, ISL(domain), model_alias, PH_COPY);
			phalcon_array_update_string(&left, ISL(name), field, PH_COPY);
	
			PHALCON_CALL_METHOD(&left_expr, this_ptr, "_getqualified", left);
	
			/** 
			 * Create the right part of the expression
			 */
			PHALCON_INIT_NVAR(right);
			array_init_size(right, 3);
			add_assoc_stringl_ex(right, ISS(type), SL("qualified"), 1);
			phalcon_array_update_string(&right, ISL(domain), join_alias, PH_COPY);
			phalcon_array_update_string(&right, ISL(name), referenced_field, PH_COPY);
	
			PHALCON_CALL_METHOD(&right_expr, this_ptr, "_getqualified", right);
	
			/** 
			 * Create a binary operation for the join conditions
			 */
			PHALCON_INIT_NVAR(sql_equals_join_condition);
			array_init_size(sql_equals_join_condition, 4);
			add_assoc_stringl_ex(sql_equals_join_condition, ISS(type), SL("binary-op"), 1);
			add_assoc_stringl_ex(sql_equals_join_condition, ISS(op), SL("="), 1);
			phalcon_array_update_string(&sql_equals_join_condition, ISL(left), left_expr, PH_COPY);
			phalcon_array_update_string(&sql_equals_join_condition, ISL(right), right_expr, PH_COPY);
			phalcon_array_append(&sql_join_partial_conditions, sql_equals_join_condition, 0);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	/** 
	 * A single join
	 */
	array_init_size(return_value, 3);
	phalcon_array_update_string(&return_value, ISL(type), join_type, PH_COPY);
	phalcon_array_update_string(&return_value, ISL(source), join_source, PH_COPY);
	phalcon_array_update_string(&return_value, ISL(conditions), sql_join_conditions, PH_COPY);
	
	RETURN_MM();
}

/**
 * Resolves joins involving many-to-many relations
 *
 * @param string $joinType
 * @param string $joinSource
 * @param string $modelAlias
 * @param string $joinAlias
 * @param Phalcon\Mvc\Model\RelationInterface $relation
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getMultiJoin){

	zval *join_type, *join_source, *model_alias;
	zval *join_alias, *relation, *fields = NULL;
	zval *referenced_fields = NULL, *intermediate_model_name = NULL;
	zval *manager, *intermediate_model = NULL, *intermediate_source = NULL;
	zval *intermediate_schema = NULL, *intermediate_full_source;
	zval *intermediate_fields = NULL, *intermediate_referenced_fields = NULL;
	zval *referenced_model_name = NULL, *field = NULL, *position = NULL;
	zval *exception_message = NULL;
	zval *left = NULL, *left_expr = NULL, *right = NULL, *right_expr = NULL, *sql_equals_join_condition = NULL;
	zval *sql_join_condition_first, *sql_join_conditions_first;
	zval *sql_join_first, *sql_join_condition_second;
	zval *sql_join_conditions_second, *sql_join_second;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 5, 0, &join_type, &join_source, &model_alias, &join_alias, &relation);
	
	array_init(return_value);
	
	/** 
	 * Local fields in the 'from' relation
	 */
	PHALCON_CALL_METHOD(&fields, relation, "getfields");
	
	/** 
	 * Referenced fields in the joined relation
	 */
	PHALCON_CALL_METHOD(&referenced_fields, relation, "getreferencedfields");
	
	/** 
	 * Intermediate model
	 */
	PHALCON_CALL_METHOD(&intermediate_model_name, relation, "getintermediatemodel");
	
	manager = phalcon_fetch_nproperty_this(this_ptr, SL("_manager"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(manager) != IS_OBJECT) {
		zend_throw_exception_ex(phalcon_mvc_model_exception_ce, 0 TSRMLS_CC, "dependency Injector is required to get '%s' service", "modelsManager");
	}
	
	/** 
	 * Get the intermediate model instance
	 */
	PHALCON_CALL_METHOD(&intermediate_model, manager, "load", intermediate_model_name);
	
	/** 
	 * Source of the related model
	 */
	PHALCON_CALL_METHOD(&intermediate_source, intermediate_model, "getsource");
	
	/** 
	 * Schema of the related model
	 */
	PHALCON_CALL_METHOD(&intermediate_schema, intermediate_model, "getschema");
	
	PHALCON_INIT_VAR(intermediate_full_source);
	array_init_size(intermediate_full_source, 2);
	phalcon_array_append(&intermediate_full_source, intermediate_schema, 0);
	phalcon_array_append(&intermediate_full_source, intermediate_source, 0);
	
	/** 
	 * Update the internal sqlAliases to set up the intermediate model
	 */
	phalcon_update_property_array(this_ptr, SL("_sqlAliases"), intermediate_model_name, intermediate_source TSRMLS_CC);
	
	/** 
	 * Update the internal _sqlAliasesModelsInstances to rename columns if necessary
	 */
	phalcon_update_property_array(this_ptr, SL("_sqlAliasesModelsInstances"), intermediate_model_name, intermediate_model TSRMLS_CC);
	
	/** 
	 * Fields that join the 'from' model with the 'intermediate' model
	 */
	PHALCON_CALL_METHOD(&intermediate_fields, relation, "getintermediatefields");
	
	/** 
	 * Fields that join the 'intermediate' model with the intermediate model
	 */
	PHALCON_CALL_METHOD(&intermediate_referenced_fields, relation, "getintermediatereferencedfields");
	
	/** 
	 * Intermediate model
	 */
	PHALCON_CALL_METHOD(&referenced_model_name, relation, "getreferencedmodel");
	if (Z_TYPE_P(fields) == IS_ARRAY) { 
		/** @todo The code seems dead - the empty array will be returned */
		phalcon_is_iterable(fields, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HKEY(position, ah0, hp0);
			PHALCON_GET_HVALUE(field);
	
			if (!phalcon_array_isset(referenced_fields, position)) {
				zval *phql = phalcon_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY TSRMLS_CC);
	
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVSVSV(exception_message, "The number of fields must be equal to the number of referenced fields in join ", model_alias, "-", join_alias, ", when preparing: ", phql);
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
	
			/**
			 * Create the left part of the expression
			 */
			PHALCON_INIT_NVAR(left);
			array_init_size(left, 3);
			add_assoc_long_ex(left, ISS(type), PHQL_T_QUALIFIED);
			phalcon_array_update_string(&left, ISL(domain), model_alias, PH_COPY);
			phalcon_array_update_string(&left, ISL(name), field, PH_COPY);
	
			PHALCON_CALL_METHOD(&left_expr, this_ptr, "_getqualified", left);
	
			/** 
			 * Create the right part of the expression
			 */
			PHALCON_INIT_NVAR(right);
			array_init_size(right, 3);
			add_assoc_stringl_ex(right, ISS(type), SL("qualified"), 1);
			phalcon_array_update_string(&right, ISL(domain), join_alias, PH_COPY);
			phalcon_array_update_string(&right, ISL(name), referenced_fields, PH_COPY);
	
			PHALCON_CALL_METHOD(&right_expr, this_ptr, "_getqualified", right);
	
			/** 
			 * Create a binary operation for the join conditions
			 */
			PHALCON_INIT_NVAR(sql_equals_join_condition);
			array_init_size(sql_equals_join_condition, 4);
			add_assoc_stringl_ex(sql_equals_join_condition, ISS(type), SL("binary-op"), 1);
			add_assoc_stringl_ex(sql_equals_join_condition, ISS(op), SL("="), 1);
			phalcon_array_update_string(&sql_equals_join_condition, ISL(left), left_expr, PH_COPY);
			phalcon_array_update_string(&sql_equals_join_condition, ISL(right), right_expr, PH_COPY);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	} else {
		/** 
		 * Create the left part of the expression
		 */
		PHALCON_INIT_NVAR(left);
		array_init_size(left, 3);
		add_assoc_long_ex(left, ISS(type), PHQL_T_QUALIFIED);
		phalcon_array_update_string(&left, ISL(domain), model_alias, PH_COPY);
		phalcon_array_update_string(&left, ISL(name), fields, PH_COPY);
	
		PHALCON_CALL_METHOD(&left_expr, this_ptr, "_getqualified", left);
	
		/** 
		 * Create the right part of the expression
		 */
		PHALCON_INIT_NVAR(right);
		array_init_size(right, 3);
		add_assoc_stringl_ex(right, ISS(type), SL("qualified"), 1);
		phalcon_array_update_string(&right, ISL(domain), intermediate_model_name, PH_COPY);
		phalcon_array_update_string(&right, ISL(name), intermediate_fields, PH_COPY);
	
		PHALCON_CALL_METHOD(&right_expr, this_ptr, "_getqualified", right);
	
		/** 
		 * Create a binary operation for the join conditions
		 */
		PHALCON_INIT_VAR(sql_join_condition_first);
		array_init_size(sql_join_condition_first, 4);
		add_assoc_stringl_ex(sql_join_condition_first, ISS(type), SL("binary-op"), 1);
		add_assoc_stringl_ex(sql_join_condition_first, ISS(op), SL("="), 1);
		phalcon_array_update_string(&sql_join_condition_first, ISL(left), left_expr, PH_COPY);
		phalcon_array_update_string(&sql_join_condition_first, ISL(right), right_expr, PH_COPY);
	
		PHALCON_INIT_VAR(sql_join_conditions_first);
		array_init_size(sql_join_conditions_first, 1);
		phalcon_array_append(&sql_join_conditions_first, sql_join_condition_first, 0);
	
		/** 
		 * A single join
		 */
		PHALCON_INIT_VAR(sql_join_first);
		array_init_size(sql_join_first, 3);
		phalcon_array_update_string(&sql_join_first, ISL(type), join_type, PH_COPY);
		phalcon_array_update_string(&sql_join_first, ISL(source), intermediate_source, PH_COPY);
		phalcon_array_update_string(&sql_join_first, ISL(conditions), sql_join_conditions_first, PH_COPY);
	
		/** 
		 * Create the left part of the expression
		 */
		PHALCON_INIT_NVAR(left);
		array_init_size(left, 3);
		add_assoc_long_ex(left, ISS(type), PHQL_T_QUALIFIED);
		phalcon_array_update_string(&left, ISL(domain), intermediate_model_name, PH_COPY);
		phalcon_array_update_string(&left, ISL(name), intermediate_referenced_fields, PH_COPY);
	
		PHALCON_CALL_METHOD(&left_expr, this_ptr, "_getqualified", left);
	
		/** 
		 * Create the right part of the expression
		 */
		PHALCON_INIT_NVAR(right);
		array_init_size(right, 3);
		add_assoc_stringl_ex(right, ISS(type), SL("qualified"), 1);
		phalcon_array_update_string(&right, ISL(domain), referenced_model_name, PH_COPY);
		phalcon_array_update_string(&right, ISL(name), referenced_fields, PH_COPY);
	
		PHALCON_CALL_METHOD(&right_expr, this_ptr, "_getqualified", right);
	
		/** 
		 * Create a binary operation for the join conditions
		 */
		PHALCON_INIT_VAR(sql_join_condition_second);
		array_init_size(sql_join_condition_second, 4);
		add_assoc_stringl_ex(sql_join_condition_second, ISS(type), SL("binary-op"), 1);
		add_assoc_stringl_ex(sql_join_condition_second, ISS(op), SL("="), 1);
		phalcon_array_update_string(&sql_join_condition_second, ISL(left), left_expr, PH_COPY);
		phalcon_array_update_string(&sql_join_condition_second, ISL(right), right_expr, PH_COPY);
	
		PHALCON_INIT_VAR(sql_join_conditions_second);
		array_init_size(sql_join_conditions_second, 1);
		phalcon_array_append(&sql_join_conditions_second, sql_join_condition_second, 0);
	
		/** 
		 * A single join
		 */
		PHALCON_INIT_VAR(sql_join_second);
		array_init_size(sql_join_second, 3);
		phalcon_array_update_string(&sql_join_second, ISL(type), join_type, PH_COPY);
		phalcon_array_update_string(&sql_join_second, ISL(source), join_source, PH_COPY);
		phalcon_array_update_string(&sql_join_second, ISL(conditions), sql_join_conditions_second, PH_COPY);

		phalcon_array_update_long(&return_value, 0, sql_join_first, PH_COPY);
		phalcon_array_update_long(&return_value, 1, sql_join_second, PH_COPY);
	}
	
	RETURN_MM();
}

/**
 * Processes the JOINs in the query returning an internal representation for the database dialect
 *
 * @param array $select
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoins){

	zval *select, *models, *sql_aliases, *sql_aliases_models;
	zval *sql_models_aliases, *sql_aliases_models_instances;
	zval *models_instances, *from_models = NULL, *sql_joins = NULL;
	zval *join_models, *join_sources, *join_types;
	zval *join_pre_condition, *join_prepared;
	zval *manager = NULL, *joins, *select_joins = NULL, *join_item = NULL;
	zval *join_data = NULL, *source = NULL, *schema = NULL, *model = NULL, *model_name = NULL;
	zval *complete_source = NULL, *join_type = NULL, *alias_expr = NULL;
	zval *alias = NULL, *exception_message, *join_alias_name = NULL;
	zval *join_expr = NULL, *pre_condition = NULL, *from_model_name = NULL;
	zval *join_model = NULL, *join_alias = NULL, *join_source = NULL;
	zval *model_name_alias = NULL, *relation = NULL, *relations = NULL;
	zval *model_alias = NULL, *is_through = NULL;
	zval *sql_join = NULL, *new_sql_joins = NULL, *sql_join_conditions = NULL;
	HashTable *ah0, *ah1, *ah2, *ah3;
	HashPosition hp0, hp1, hp2, hp3;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &select);
	
	PHALCON_OBS_VAR(models);
	phalcon_read_property_this(&models, this_ptr, SL("_models"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(sql_aliases);
	phalcon_read_property_this(&sql_aliases, this_ptr, SL("_sqlAliases"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(sql_aliases_models);
	phalcon_read_property_this(&sql_aliases_models, this_ptr, SL("_sqlAliasesModels"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(sql_models_aliases);
	phalcon_read_property_this(&sql_models_aliases, this_ptr, SL("_sqlModelsAliases"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(sql_aliases_models_instances);
	phalcon_read_property_this(&sql_aliases_models_instances, this_ptr, SL("_sqlAliasesModelsInstances"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(models_instances);
	phalcon_read_property_this(&models_instances, this_ptr, SL("_modelsInstances"), PH_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(from_models, models);
	
	PHALCON_INIT_VAR(sql_joins);
	array_init(sql_joins);
	
	PHALCON_INIT_VAR(join_models);
	array_init(join_models);
	
	PHALCON_INIT_VAR(join_sources);
	array_init(join_sources);
	
	PHALCON_INIT_VAR(join_types);
	array_init(join_types);
	
	PHALCON_INIT_VAR(join_pre_condition);
	array_init(join_pre_condition);
	
	PHALCON_INIT_VAR(join_prepared);
	array_init(join_prepared);
	
	manager = phalcon_fetch_nproperty_this(this_ptr, SL("_manager"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(manager) != IS_OBJECT) {
		zend_throw_exception_ex(phalcon_mvc_model_exception_ce, 0 TSRMLS_CC, "dependency Injector is required to get '%s' service", "modelsManager");
	}

	PHALCON_OBS_VAR(joins);
	phalcon_array_fetch_string(&joins, select, SL("joins"), PH_NOISY);
	if (!phalcon_array_isset_long(joins, 0)) {
		PHALCON_INIT_VAR(select_joins);
		array_init_size(select_joins, 1);
		phalcon_array_append(&select_joins, joins, 0);
	} else {
		PHALCON_CPY_WRT(select_joins, joins);
	}
	
	phalcon_is_iterable(select_joins, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(join_item);
	
		/** 
		 * Check join alias
		 */
		PHALCON_CALL_METHOD(&join_data, this_ptr, "_getjoin", manager, join_item);
	
		PHALCON_OBS_NVAR(source);
		phalcon_array_fetch_string(&source, join_data, SL("source"), PH_NOISY);
	
		PHALCON_OBS_NVAR(schema);
		phalcon_array_fetch_string(&schema, join_data, SL("schema"), PH_NOISY);
	
		PHALCON_OBS_NVAR(model);
		phalcon_array_fetch_string(&model, join_data, SL("model"), PH_NOISY);
	
		PHALCON_OBS_NVAR(model_name);
		phalcon_array_fetch_string(&model_name, join_data, SL("modelName"), PH_NOISY);
	
		PHALCON_INIT_NVAR(complete_source);
		array_init_size(complete_source, 2);
		phalcon_array_append(&complete_source, source, PH_SEPARATE);
		phalcon_array_append(&complete_source, schema, 0);
	
		/** 
		 * Check join alias
		 */
		PHALCON_CALL_METHOD(&join_type, this_ptr, "_getjointype", join_item);
	
		/** 
		 * Process join alias
		 */
		if (phalcon_array_isset_string_fetch(&alias_expr, join_item, SS("alias"))) {
	
			PHALCON_OBS_NVAR(alias);
			phalcon_array_fetch_string(&alias, alias_expr, ISL(name), PH_NOISY);
	
			/** 
			 * Check if alias is unique
			 */
			if (phalcon_array_isset(join_models, alias)) {
				zval *phql = phalcon_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY TSRMLS_CC);
	
				PHALCON_INIT_VAR(exception_message);
				PHALCON_CONCAT_SVSV(exception_message, "Cannot use '", alias, "' as join alias because it was already used when preparing: ", phql);
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
	
			/** 
			 * Add the alias to the source
			 */
			phalcon_array_append(&complete_source, alias, PH_SEPARATE);
	
			/** 
			 * Set the join type
			 */
			phalcon_array_update_zval(&join_types, alias, join_type, PH_COPY | PH_SEPARATE);
	
			/** 
			 * Update alias => alias
			 */
			phalcon_array_update_zval(&sql_aliases, alias, alias, PH_COPY | PH_SEPARATE);
	
			/** 
			 * Update model => alias
			 */
			phalcon_array_update_zval(&join_models, alias, model_name, PH_COPY | PH_SEPARATE);
	
			/** 
			 * Update model => alias
			 */
			phalcon_array_update_zval(&sql_models_aliases, model_name, alias, PH_COPY | PH_SEPARATE);
	
			/** 
			 * Update alias => model
			 */
			phalcon_array_update_zval(&sql_aliases_models, alias, model_name, PH_COPY | PH_SEPARATE);
	
			/** 
			 * Update alias => model
			 */
			phalcon_array_update_zval(&sql_aliases_models_instances, alias, model, PH_COPY | PH_SEPARATE);
	
			/** 
			 * Update model => alias
			 */
			phalcon_array_update_zval(&models, model_name, alias, PH_COPY | PH_SEPARATE);
	
			/** 
			 * Complete source related to a model
			 */
			phalcon_array_update_zval(&join_sources, alias, complete_source, PH_COPY | PH_SEPARATE);
	
			/** 
			 * Complete source related to a model
			 */
			phalcon_array_update_zval(&join_prepared, alias, join_item, PH_COPY | PH_SEPARATE);
		} else {
			/** 
			 * Check if alias is unique
			 */
			if (phalcon_array_isset(join_models, model_name)) {
				zval *phql = phalcon_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY TSRMLS_CC);
	
				PHALCON_INIT_VAR(exception_message);
				PHALCON_CONCAT_SVSV(exception_message, "Cannot use '", model_name, "' as join alias because it was already used when preparing: ", phql);
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
	
			/** 
			 * Set the join type
			 */
			phalcon_array_update_zval(&join_types, model_name, join_type, PH_COPY | PH_SEPARATE);
	
			/** 
			 * Update model => source
			 */
			phalcon_array_update_zval(&sql_aliases, model_name, source, PH_COPY | PH_SEPARATE);
	
			/** 
			 * Update model => source
			 */
			phalcon_array_update_zval(&join_models, model_name, source, PH_COPY | PH_SEPARATE);
	
			/** 
			 * Update model => model
			 */
			phalcon_array_update_zval(&sql_models_aliases, model_name, model_name, PH_COPY | PH_SEPARATE);
	
			/** 
			 * Update model => model
			 */
			phalcon_array_update_zval(&sql_aliases_models, model_name, model_name, PH_COPY | PH_SEPARATE);
	
			/** 
			 * Update model => model instance
			 */
			phalcon_array_update_zval(&sql_aliases_models_instances, model_name, model, PH_COPY | PH_SEPARATE);
	
			/** 
			 * Update model => source
			 */
			phalcon_array_update_zval(&models, model_name, source, PH_COPY | PH_SEPARATE);
	
			/** 
			 * Complete source related to a model
			 */
			phalcon_array_update_zval(&join_sources, model_name, complete_source, PH_COPY | PH_SEPARATE);
	
			/** 
			 * Complete source related to a model
			 */
			phalcon_array_update_zval(&join_prepared, model_name, join_item, PH_COPY | PH_SEPARATE);
		}
	
		phalcon_array_update_zval(&models_instances, model_name, model, PH_COPY | PH_SEPARATE);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * Update temporary properties
	 */
	phalcon_update_property_this(this_ptr, SL("_models"), models TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_sqlAliases"), sql_aliases TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_sqlAliasesModels"), sql_aliases_models TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_sqlModelsAliases"), sql_models_aliases TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_sqlAliasesModelsInstances"), sql_aliases_models_instances TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_modelsInstances"), models_instances TSRMLS_CC);
	
	phalcon_is_iterable(join_prepared, &ah1, &hp1, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
		PHALCON_GET_HKEY(join_alias_name, ah1, hp1);
		PHALCON_GET_HVALUE(join_item);
	
		/** 
		 * Check for predefined conditions
		 */
		if (phalcon_array_isset_string_fetch(&join_expr, join_item, SS("conditions"))) {
			PHALCON_CALL_METHOD(&pre_condition, this_ptr, "_getexpression", join_expr);
			phalcon_array_update_zval(&join_pre_condition, join_alias_name, pre_condition, PH_COPY | PH_SEPARATE);
		}
	
		zend_hash_move_forward_ex(ah1, &hp1);
	}
	
	/** 
	 * Create join relationships dynamically
	 */
	phalcon_is_iterable(from_models, &ah2, &hp2, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) == SUCCESS) {
	
		PHALCON_GET_HKEY(from_model_name, ah2, hp2);
		PHALCON_GET_HVALUE(source);
	
		phalcon_is_iterable(join_models, &ah3, &hp3, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah3, (void**) &hd, &hp3) == SUCCESS) {
	
			PHALCON_GET_HKEY(join_alias, ah3, hp3);
			PHALCON_GET_HVALUE(join_model);
	
			/** 
			 * Real source name for joined model
			 */
			PHALCON_OBS_NVAR(join_source);
			phalcon_array_fetch(&join_source, join_sources, join_alias, PH_NOISY);
	
			/** 
			 * Join type is: LEFT, RIGHT, INNER, etc
			 */
			PHALCON_OBS_NVAR(join_type);
			phalcon_array_fetch(&join_type, join_types, join_alias, PH_NOISY);
	
			/** 
			 * Check if the model already have pre-defined conditions
			 */
			if (!phalcon_array_isset(join_pre_condition, join_alias)) {
	
				/** 
				 * Get the model name from its source
				 */
				PHALCON_OBS_NVAR(model_name_alias);
				phalcon_array_fetch(&model_name_alias, sql_aliases_models, join_alias, PH_NOISY);
	
				/** 
				 * Check if the joined model is an alias
				 */
				PHALCON_CALL_METHOD(&relation, manager, "getrelationbyalias", from_model_name, model_name_alias);
				if (PHALCON_IS_FALSE(relation)) {
	
					/** 
					 * Check for relations between models
					 */
					PHALCON_CALL_METHOD(&relations, manager, "getrelationsbetween", from_model_name, model_name_alias);
					if (Z_TYPE_P(relations) == IS_ARRAY) { 
	
						/** 
						 * More than one relation must throw an exception
						 */
						if (zend_hash_num_elements(Z_ARRVAL_P(relations)) != 1) {
							zval *phql = phalcon_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY TSRMLS_CC);
	
							PHALCON_INIT_VAR(exception_message);
							PHALCON_CONCAT_SVSVSV(exception_message, "There is more than one relation between models '", model_name, "' and '", join_model, "\", the join must be done using an alias when preparing: ", phql);
							PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
							return;
						}
	
						/** 
						 * Get the first relationship
						 */
						PHALCON_OBS_NVAR(relation);
						phalcon_array_fetch_long(&relation, relations, 0, PH_NOISY);
					}
				}
	
				/** 
				 * Valid relations are objects
				 */
				if (Z_TYPE_P(relation) == IS_OBJECT) {
	
					/** 
					 * Get the related model alias of the left part
					 */
					PHALCON_OBS_NVAR(model_alias);
					phalcon_array_fetch(&model_alias, sql_models_aliases, from_model_name, PH_NOISY);
	
					/** 
					 * Generate the conditions based on the type of join
					 */
					PHALCON_CALL_METHOD(&is_through, relation, "isthrough");
					if (!zend_is_true(is_through)) {
						PHALCON_CALL_METHOD(&sql_join, this_ptr, "_getsinglejoin", join_type, join_source, model_alias, join_alias, relation);
					} else {
						PHALCON_CALL_METHOD(&sql_join, this_ptr, "_getmultijoin", join_type, join_source, model_alias, join_alias, relation);
					}
	
					/** 
					 * Append or merge joins
					 */
					if (phalcon_array_isset_long(sql_join, 0)) {
						PHALCON_INIT_NVAR(new_sql_joins);
						phalcon_fast_array_merge(new_sql_joins, &sql_joins, &sql_join TSRMLS_CC);
						PHALCON_CPY_WRT(sql_joins, new_sql_joins);
					} else {
						phalcon_array_append(&sql_joins, sql_join, PH_SEPARATE);
					}
				} else {
					PHALCON_INIT_NVAR(sql_join_conditions);
					array_init(sql_join_conditions);
	
					/** 
					 * Join without conditions because no relation has been found between the models
					 */
					PHALCON_INIT_NVAR(sql_join);
					array_init_size(sql_join, 3);
					phalcon_array_update_string(&sql_join, ISL(type), join_type, PH_COPY | PH_SEPARATE);
					phalcon_array_update_string(&sql_join, ISL(source), join_source, PH_COPY);
					phalcon_array_update_string(&sql_join, ISL(conditions), sql_join_conditions, PH_COPY);
					phalcon_array_append(&sql_joins, sql_join, PH_SEPARATE);
				}
			} else {
				/** 
				 * Get the conditions stablished by the developer
				 */
				PHALCON_OBS_NVAR(pre_condition);
				phalcon_array_fetch(&pre_condition, join_pre_condition, join_alias, PH_NOISY);
	
				PHALCON_INIT_NVAR(sql_join_conditions);
				array_init_size(sql_join_conditions, 1);
				phalcon_array_append(&sql_join_conditions, pre_condition, PH_SEPARATE);
	
				/** 
				 * Join with conditions stablished by the developer
				 */
				PHALCON_INIT_NVAR(sql_join);
				array_init_size(sql_join, 3);
				phalcon_array_update_string(&sql_join, ISL(type), join_type, PH_COPY | PH_SEPARATE);
				phalcon_array_update_string(&sql_join, ISL(source), join_source, PH_COPY);
				phalcon_array_update_string(&sql_join, ISL(conditions), sql_join_conditions, PH_COPY);
				phalcon_array_append(&sql_joins, sql_join, PH_SEPARATE);
			}
	
			zend_hash_move_forward_ex(ah3, &hp3);
		}
	
		zend_hash_move_forward_ex(ah2, &hp2);
	}
	
	RETURN_CTOR(sql_joins);
}

/**
 * Returns a processed order clause for a SELECT statement
 *
 * @param array $order
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getOrderClause){

	zval *order, *order_columns = NULL, *order_item = NULL;
	zval *order_column = NULL, *order_part_expr = NULL, *order_sort = NULL;
	zval *order_part_sort = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &order);
	
	if (!phalcon_array_isset_long(order, 0)) {
		PHALCON_INIT_VAR(order_columns);
		array_init_size(order_columns, 1);
		phalcon_array_append(&order_columns, order, 0);
	} else {
		PHALCON_CPY_WRT(order_columns, order);
	}
	
	phalcon_is_iterable(order_columns, &ah0, &hp0, 0, 0);
	array_init_size(return_value, zend_hash_num_elements(ah0));
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(order_item);
	
		PHALCON_OBS_NVAR(order_column);
		phalcon_array_fetch_string(&order_column, order_item, SL("column"), PH_NOISY);
	
		PHALCON_CALL_METHOD(&order_part_expr, this_ptr, "_getexpression", order_column);
	
		/** 
		 * Check if the order has a predefined ordering mode
		 */
		if (phalcon_array_isset_string_fetch(&order_sort, order_item, SS("sort"))) {

			PHALCON_INIT_NVAR(order_part_sort);
			if (PHALCON_IS_LONG(order_sort, PHQL_T_ASC)) {
				array_init_size(order_part_sort, 2);
				phalcon_array_append(&order_part_sort, order_part_expr, 0);
				add_next_index_stringl(order_part_sort, SL("ASC"), 1);
			} else {
				array_init_size(order_part_sort, 2);
				phalcon_array_append(&order_part_sort, order_part_expr, 0);
				add_next_index_stringl(order_part_sort, SL("DESC"), 1);
			}
		} else {
			PHALCON_INIT_NVAR(order_part_sort);
			array_init_size(order_part_sort, 1);
			phalcon_array_append(&order_part_sort, order_part_expr, 0);
		}
	
		phalcon_array_append(&return_value, order_part_sort, 0);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	RETURN_MM();
}

/**
 * Returns a processed group clause for a SELECT statement
 *
 * @param array $group
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getGroupClause){

	zval *group, *group_item = NULL, *group_part_expr = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &group);
	
	if (phalcon_array_isset_long(group, 0)) {
	
		/** 
		 * The select is grouped by several columns
		 */
		phalcon_is_iterable(group, &ah0, &hp0, 0, 0);

		array_init_size(return_value, zend_hash_num_elements(ah0));
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(group_item);
	
			PHALCON_CALL_METHOD(&group_part_expr, this_ptr, "_getexpression", group_item);
			phalcon_array_append(&return_value, group_part_expr, 0);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	} else {
		PHALCON_CALL_METHOD(&group_part_expr, this_ptr, "_getexpression", group);
	
		array_init_size(return_value, 1);
		phalcon_array_append(&return_value, group_part_expr, 0);
	}
	
	RETURN_MM();
}

PHP_METHOD(Phalcon_Mvc_Model_Query, _getLimitClause) {
	zval *limit_clause, *tmp = NULL;
	zval *limit, *offset;

	phalcon_fetch_params(0, 1, 0, &limit_clause);
	assert(Z_TYPE_P(limit_clause) == IS_ARRAY);

	array_init_size(return_value, zend_hash_num_elements(Z_ARRVAL_P(limit_clause)));

	PHALCON_MM_GROW();

	if (likely(phalcon_array_isset_string_fetch(&limit, limit_clause, SS("number")))) {
		PHALCON_CALL_METHOD(&tmp, getThis(), "_getexpression", limit);
		phalcon_array_update_string(&return_value, ISL(number), tmp, PH_COPY);
	}

	if (phalcon_array_isset_string_fetch(&offset, limit_clause, SS("offset"))) {
		PHALCON_CALL_METHOD(&tmp, getThis(), "_getexpression", offset);
		phalcon_array_update_string(&return_value, ISL(offset), tmp, PH_COPY);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Analyzes a SELECT intermediate code and produces an array to be executed later
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareSelect){

	zval *ast, *select, *distinct = NULL, *sql_models, *sql_tables, *sql_aliases;
	zval *sql_columns, *sql_aliases_models, *sql_models_aliases;
	zval *sql_aliases_models_instances, *models;
	zval *models_instances, *tables, *selected_models = NULL;
	zval *manager, *selected_model = NULL, *qualified_name = NULL;
	zval *model_name = NULL, *real_namespace = NULL;
	zval *real_model_name = NULL, *model = NULL, *schema = NULL, *source = NULL;
	zval *complete_source = NULL, *alias = NULL, *exception_message = NULL;
	zval *joins, *sql_joins = NULL, *columns, *select_columns = NULL;
	zval *position, *sql_column_aliases, *column = NULL;
	zval *sql_column_group = NULL, *sql_column = NULL, *type = NULL, *sql_select;
	zval *where, *where_expr = NULL, *group_by, *sql_group = NULL;
	zval *having, *having_expr = NULL, *order, *sql_order = NULL;
	zval *limit, *sql_limit = NULL;
	HashTable *ah0, *ah1, *ah2;
	HashPosition hp0, hp1, hp2;
	zval **hd;

	PHALCON_MM_GROW();

	ast = phalcon_fetch_nproperty_this(this_ptr, SL("_ast"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(select);
	phalcon_array_fetch_string(&select, ast, SL("select"), PH_NOISY);
	if (!phalcon_array_isset_string_fetch(&tables, select, SS("tables"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	
	if (!phalcon_array_isset_string_fetch(&columns, select, SS("columns"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	
	phalcon_array_isset_string_fetch(&distinct, select, SS("distinct"));

	/** 
	 * sql_models are all the models that are using in the query
	 */
	PHALCON_INIT_VAR(sql_models);
	array_init(sql_models);
	
	/** 
	 * sql_tables are all the mapped sources regarding the models in use
	 */
	PHALCON_INIT_VAR(sql_tables);
	array_init(sql_tables);
	
	/** 
	 * sql_aliases are the aliases as keys and the mapped sources as values
	 */
	PHALCON_INIT_VAR(sql_aliases);
	array_init(sql_aliases);
	
	/** 
	 * sql_columns are all every column expression
	 */
	PHALCON_INIT_VAR(sql_columns);
	array_init(sql_columns);
	
	/** 
	 * sql_aliases_models are the aliases as keys and the model names as values
	 */
	PHALCON_INIT_VAR(sql_aliases_models);
	array_init(sql_aliases_models);
	
	/** 
	 * sql_aliases_models are the model names as keys and the aliases as values
	 */
	PHALCON_INIT_VAR(sql_models_aliases);
	array_init(sql_models_aliases);
	
	/** 
	 * sql_aliases_models_instances are the aliases as keys and the model instances as
	 * values
	 */
	PHALCON_INIT_VAR(sql_aliases_models_instances);
	array_init(sql_aliases_models_instances);
	
	/** 
	 * Models information
	 */
	PHALCON_INIT_VAR(models);
	array_init(models);
	
	PHALCON_INIT_VAR(models_instances);
	array_init(models_instances);
	
	if (!phalcon_array_isset_long(tables, 0)) {
		PHALCON_INIT_VAR(selected_models);
		array_init_size(selected_models, 1);
		phalcon_array_append(&selected_models, tables, 0);
	} else {
		PHALCON_CPY_WRT(selected_models, tables);
	}
	
	manager = phalcon_fetch_nproperty_this(this_ptr, SL("_manager"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(manager) != IS_OBJECT) {
		zend_throw_exception_ex(phalcon_mvc_model_exception_ce, 0 TSRMLS_CC, "dependency Injector is required to get '%s' service", "modelsManager");
	}

	/** 
	 * Processing selected columns
	 */
	phalcon_is_iterable(selected_models, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
		zval *ns_alias;
	
		PHALCON_GET_HVALUE(selected_model);
	
		PHALCON_OBS_NVAR(qualified_name);
		phalcon_array_fetch_string(&qualified_name, selected_model, SL("qualifiedName"), PH_NOISY);
	
		PHALCON_OBS_NVAR(model_name);
		phalcon_array_fetch_string(&model_name, qualified_name, ISL(name), PH_NOISY);
	
		/** 
		 * Check if the table have a namespace alias
		 */
		if (phalcon_array_isset_string_fetch(&ns_alias, qualified_name, SS("ns-alias"))) {
	
			/** 
			 * Get the real namespace alias
			 */
			PHALCON_CALL_METHOD(&real_namespace, manager, "getnamespacealias", ns_alias);
	
			/** 
			 * Create the real namespaced name
			 */
			PHALCON_INIT_NVAR(real_model_name);
			PHALCON_CONCAT_VSV(real_model_name, real_namespace, "\\", model_name);
		} else {
			PHALCON_CPY_WRT(real_model_name, model_name);
		}
	
		/** 
		 * Load a model instance from the models manager
		 */
		PHALCON_CALL_METHOD(&model, manager, "load", real_model_name);
	
		/** 
		 * Define a complete schema/source
		 */
		PHALCON_CALL_METHOD(&schema, model, "getschema");
		PHALCON_CALL_METHOD(&source, model, "getsource");
	
		/** 
		 * Obtain the real source including the schema
		 */
		if (zend_is_true(schema)) {
			PHALCON_INIT_NVAR(complete_source);
			array_init_size(complete_source, 2);
			phalcon_array_append(&complete_source, source, PH_SEPARATE);
			phalcon_array_append(&complete_source, schema, 0);
		} else {
			PHALCON_CPY_WRT(complete_source, source);
		}
	
		/** 
		 * If an alias is defined for a model the model cannot be referenced in the column
		 * list
		 */
		if (phalcon_array_isset_string_fetch(&alias, selected_model, SS("alias"))) {
	
			/** 
			 * Check that the alias hasn't been used before
			 */
			if (phalcon_array_isset(sql_aliases, alias)) {
				zval *phql = phalcon_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY TSRMLS_CC);
	
				PHALCON_INIT_VAR(exception_message);
				PHALCON_CONCAT_SVSV(exception_message, "Alias \"", alias, " is already used when preparing: ", phql);
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
	
			phalcon_array_update_zval(&sql_aliases, alias, alias, PH_COPY | PH_SEPARATE);
			phalcon_array_update_zval(&sql_aliases_models, alias, model_name, PH_COPY | PH_SEPARATE);
			phalcon_array_update_zval(&sql_models_aliases, model_name, alias, PH_COPY | PH_SEPARATE);
			phalcon_array_update_zval(&sql_aliases_models_instances, alias, model, PH_COPY | PH_SEPARATE);
	
			/** 
			 * Append or convert complete source to an array
			 */
			if (Z_TYPE_P(complete_source) == IS_ARRAY) { 
				phalcon_array_append(&complete_source, alias, PH_SEPARATE);
			} else {
				PHALCON_INIT_NVAR(complete_source);
				array_init_size(complete_source, 3);
				phalcon_array_append(&complete_source, source, PH_SEPARATE);
				add_next_index_null(complete_source);
				phalcon_array_append(&complete_source, alias, 0);
			}
	
			phalcon_array_update_zval(&models, model_name, alias, PH_COPY | PH_SEPARATE);
		} else {
			phalcon_array_update_zval(&sql_aliases, model_name, source, PH_COPY | PH_SEPARATE);
			phalcon_array_update_zval(&sql_aliases_models, model_name, model_name, PH_COPY | PH_SEPARATE);
			phalcon_array_update_zval(&sql_models_aliases, model_name, model_name, PH_COPY | PH_SEPARATE);
			phalcon_array_update_zval(&sql_aliases_models_instances, model_name, model, PH_COPY | PH_SEPARATE);
			phalcon_array_update_zval(&models, model_name, source, PH_COPY | PH_SEPARATE);
		}
	
		phalcon_array_append(&sql_models, model_name, PH_SEPARATE);
		phalcon_array_append(&sql_tables, complete_source, PH_SEPARATE);
		phalcon_array_update_zval(&models_instances, model_name, model, PH_COPY | PH_SEPARATE);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * Assign Models/Tables information
	 */
	phalcon_update_property_this(this_ptr, SL("_models"), models TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_modelsInstances"), models_instances TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_sqlAliases"), sql_aliases TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_sqlAliasesModels"), sql_aliases_models TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_sqlModelsAliases"), sql_models_aliases TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_sqlAliasesModelsInstances"), sql_aliases_models_instances TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_modelsInstances"), models_instances TSRMLS_CC);
	
	/** 
	 * Processing joins
	 */
	if (phalcon_array_isset_string_fetch(&joins, select, SS("joins"))) {
	
		PHALCON_INIT_VAR(sql_joins);
		if (phalcon_fast_count_ev(joins TSRMLS_CC)) {
			PHALCON_CALL_METHOD(&sql_joins, this_ptr, "_getjoins", select);
		} else {
			array_init(sql_joins);
		}
	} else {
		PHALCON_INIT_NVAR(sql_joins);
		array_init(sql_joins);
	}
	
	/** 
	 * Processing selected columns
	 */
	if (!phalcon_array_isset_long(columns, 0)) {
		PHALCON_INIT_VAR(select_columns);
		array_init_size(select_columns, 1);
		phalcon_array_append(&select_columns, columns, PH_SEPARATE);
	} else {
		PHALCON_CPY_WRT(select_columns, columns);
	}
	
	/** 
	 * Resolve selected columns
	 */
	PHALCON_INIT_VAR(position);
	ZVAL_LONG(position, 0);
	
	PHALCON_INIT_VAR(sql_column_aliases);
	array_init(sql_column_aliases);
	
	phalcon_is_iterable(select_columns, &ah1, &hp1, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
		PHALCON_GET_HVALUE(column);
	
		PHALCON_CALL_METHOD(&sql_column_group, this_ptr, "_getselectcolumn", column);
	
		phalcon_is_iterable(sql_column_group, &ah2, &hp2, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) == SUCCESS) {
	
			PHALCON_GET_HVALUE(sql_column);
	
			/** 
			 * If 'alias' is set, the user had defined a alias for the column
			 */
			if (phalcon_array_isset_string_fetch(&alias, column, SS("alias"))) {
	
				/** 
				 * The best alias is the one provided by the user
				 */
				phalcon_array_update_string(&sql_column, ISL(balias), alias, PH_COPY | PH_SEPARATE);
				phalcon_array_update_string(&sql_column, ISL(sqlAlias), alias, PH_COPY | PH_SEPARATE);
				phalcon_array_update_zval(&sql_columns, alias, sql_column, PH_COPY | PH_SEPARATE);
				phalcon_array_update_zval_bool(&sql_column_aliases, alias, 1, PH_SEPARATE);
			} else {

				/** 
				 * 'balias' is the best alias selected for the column
				 */
				if (phalcon_array_isset_string_fetch(&alias, sql_column, SS("balias"))) {
					phalcon_array_update_zval(&sql_columns, alias, sql_column, PH_COPY | PH_SEPARATE);
				} else {
					PHALCON_OBS_NVAR(type);
					phalcon_array_fetch_string(&type, sql_column, ISL(type), PH_NOISY);
					if (PHALCON_IS_STRING(type, "scalar")) {
						PHALCON_INIT_VAR(alias);
						PHALCON_CONCAT_SV(alias, "_", position);
						phalcon_array_update_zval(&sql_columns, alias, sql_column, PH_COPY | PH_SEPARATE);
					} else {
						phalcon_array_append(&sql_columns, sql_column, PH_SEPARATE);
					}
				}
			}

			phalcon_increment(position);
	
			zend_hash_move_forward_ex(ah2, &hp2);
		}
	
		zend_hash_move_forward_ex(ah1, &hp1);
	}
	
	phalcon_update_property_this(this_ptr, SL("_sqlColumnAliases"), sql_column_aliases TSRMLS_CC);
	
	/** 
	 * sql_select is the final prepared SELECT
	 */
	PHALCON_INIT_VAR(sql_select);
	array_init_size(sql_select, 10);

	if (distinct) {
		phalcon_array_update_string(&sql_select, SL("distinct"), distinct, PH_COPY);
	}

	phalcon_array_update_string(&sql_select, ISL(models), sql_models, PH_COPY);
	phalcon_array_update_string(&sql_select, ISL(tables), sql_tables, PH_COPY);
	phalcon_array_update_string(&sql_select, ISL(columns), sql_columns, PH_COPY);
	if (phalcon_fast_count_ev(sql_joins TSRMLS_CC)) {
		phalcon_array_update_string(&sql_select, ISL(joins), sql_joins, PH_COPY);
	}
	
	/** 
	 * Process WHERE clause if any
	 */
	if (phalcon_array_isset_string_fetch(&where, ast, SS("where"))) {
		PHALCON_CALL_METHOD(&where_expr, this_ptr, "_getexpression", where);
		phalcon_array_update_string(&sql_select, ISL(where), where_expr, PH_COPY);
	}
	
	/** 
	 * Process GROUP BY clause if any
	 */
	if (phalcon_array_isset_string_fetch(&group_by, ast, SS("groupBy"))) {
		PHALCON_CALL_METHOD(&sql_group, this_ptr, "_getgroupclause", group_by);
		phalcon_array_update_string(&sql_select, ISL(group), sql_group, PH_COPY);
	}
	
	/** 
	 * Process HAVING clause if any
	 */
	if (phalcon_array_isset_string_fetch(&having, ast, SS("having"))) {
		PHALCON_CALL_METHOD(&having_expr, this_ptr, "_getexpression", having);
		phalcon_array_update_string(&sql_select, ISL(having), having_expr, PH_COPY);
	}
	
	/** 
	 * Process ORDER BY clause if any
	 */
	if (phalcon_array_isset_string(ast, SS("orderBy"))) {
		PHALCON_OBS_VAR(order);
		phalcon_array_fetch_string(&order, ast, SL("orderBy"), PH_NOISY);
	
		PHALCON_CALL_METHOD(&sql_order, this_ptr, "_getorderclause", order);
		phalcon_array_update_string(&sql_select, ISL(order), sql_order, PH_COPY);
	}
	
	/** 
	 * Process LIMIT clause if any
	 */
	if (phalcon_array_isset_string_fetch(&limit, ast, SS("limit"))) {
		PHALCON_CALL_METHOD(&sql_limit, this_ptr, "_getlimitclause", limit);
		phalcon_array_update_string(&sql_select, ISL(limit), sql_limit, PH_COPY);
	}
	
	RETURN_CTOR(sql_select);
}

/**
 * Analyzes an INSERT intermediate code and produces an array to be executed later
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareInsert){

	zval *ast, *qualified_name, *manager, *model_name;
	zval *model = NULL, *source = NULL, *schema = NULL, *sql_aliases, *not_quoting;
	zval *expr_values, *values, *expr_value = NULL, *expr_insert = NULL;
	zval *expr_type = NULL, *value = NULL, *sql_insert, *meta_data;
	zval *sql_fields, *fields, *field = NULL, *name = NULL, *has_attribute = NULL;
	zval *phql = NULL, *exception_message = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(ast);
	phalcon_read_property_this(&ast, this_ptr, SL("_ast"), PH_NOISY TSRMLS_CC);
	if (!phalcon_array_isset_string(ast, SS("qualifiedName"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted INSERT AST");
		return;
	}
	
	if (!phalcon_array_isset_string(ast, SS("values"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted INSERT AST");
		return;
	}
	
	PHALCON_OBS_VAR(qualified_name);
	phalcon_array_fetch_string(&qualified_name, ast, SL("qualifiedName"), PH_NOISY);
	
	/** 
	 * Check if the related model exists
	 */
	if (!phalcon_array_isset_string(qualified_name, SS("name"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted INSERT AST");
		return;
	}
	
	manager = phalcon_fetch_nproperty_this(this_ptr, SL("_manager"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(manager) != IS_OBJECT) {
		zend_throw_exception_ex(phalcon_mvc_model_exception_ce, 0 TSRMLS_CC, "dependency Injector is required to get '%s' service", "modelsManager");
	}

	PHALCON_OBS_VAR(model_name);
	phalcon_array_fetch_string(&model_name, qualified_name, ISL(name), PH_NOISY);
	
	PHALCON_CALL_METHOD(&model, manager, "load", model_name);
	PHALCON_CALL_METHOD(&source, model, "getsource");
	PHALCON_CALL_METHOD(&schema, model, "getschema");
	if (zend_is_true(schema)) {
		PHALCON_INIT_NVAR(source);
		array_init_size(source, 2);
		phalcon_array_append(&source, schema, PH_SEPARATE);
		phalcon_array_append(&source, source, 0);
	}
	
	PHALCON_INIT_VAR(sql_aliases);
	array_init(sql_aliases);
	
	PHALCON_INIT_VAR(not_quoting);
	ZVAL_BOOL(not_quoting, 0);
	
	PHALCON_INIT_VAR(expr_values);
	array_init(expr_values);
	
	PHALCON_OBS_VAR(values);
	phalcon_array_fetch_string(&values, ast, SL("values"), PH_NOISY);
	
	phalcon_is_iterable(values, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(expr_value);
	
		/** 
		 * Resolve every expression in the 'values' clause
		 */
		PHALCON_CALL_METHOD(&expr_insert, this_ptr, "_getexpression", expr_value, not_quoting);
	
		PHALCON_OBS_NVAR(expr_type);
		phalcon_array_fetch_string(&expr_type, expr_value, ISL(type), PH_NOISY);
	
		PHALCON_INIT_NVAR(value);
		array_init_size(value, 2);
		phalcon_array_update_string(&value, ISL(type), expr_type, PH_COPY | PH_SEPARATE);
		phalcon_array_update_string(&value, ISL(value), expr_insert, PH_COPY | PH_SEPARATE);
		phalcon_array_append(&expr_values, value, PH_SEPARATE);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	PHALCON_INIT_VAR(sql_insert);
	array_init(sql_insert);
	phalcon_array_update_string(&sql_insert, ISL(model), model_name, PH_COPY | PH_SEPARATE);
	phalcon_array_update_string(&sql_insert, ISL(table), source, PH_COPY | PH_SEPARATE);
	
	PHALCON_OBS_VAR(meta_data);
	phalcon_read_property_this(&meta_data, this_ptr, SL("_metaData"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_string_fetch(&fields, ast, SS("fields"))) {
	
		PHALCON_INIT_VAR(sql_fields);
		array_init(sql_fields);
	
		phalcon_is_iterable(fields, &ah1, &hp1, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
			PHALCON_GET_HVALUE(field);
	
			PHALCON_OBS_NVAR(name);
			phalcon_array_fetch_string(&name, field, ISL(name), PH_NOISY);
	
			/** 
			 * Check that inserted fields are part of the model
			 */
			PHALCON_CALL_METHOD(&has_attribute, meta_data, "hasattribute", model, name);
			if (!zend_is_true(has_attribute)) {
				PHALCON_OBS_NVAR(phql);
				phalcon_read_property_this(&phql, this_ptr, SL("_phql"), PH_NOISY TSRMLS_CC);
	
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVSVS(exception_message, "The model '", model_name, "' doesn't have the attribute '", name, "'");
				PHALCON_SCONCAT_SV(exception_message, ", when preparing: ", phql);
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
	
			/** 
			 * Add the file to the insert list
			 */
			phalcon_array_append(&sql_fields, name, PH_SEPARATE);
	
			zend_hash_move_forward_ex(ah1, &hp1);
		}
	
		phalcon_array_update_string(&sql_insert, ISL(fields), sql_fields, PH_COPY | PH_SEPARATE);
	}
	
	phalcon_array_update_string(&sql_insert, ISL(values), expr_values, PH_COPY | PH_SEPARATE);
	
	RETURN_CTOR(sql_insert);
}

/**
 * Analyzes an UPDATE intermediate code and produces an array to be executed later
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareUpdate){

	zval *ast, *update, *models, *models_instances;
	zval *sql_tables, *sql_models, *sql_aliases;
	zval *sql_aliases_models_instances, *tables;
	zval *update_tables = NULL, *manager, *table = NULL, *qualified_name = NULL;
	zval *model_name = NULL, *ns_alias = NULL, *real_namespace = NULL;
	zval *real_model_name = NULL, *model = NULL, *source = NULL, *schema = NULL;
	zval *complete_source = NULL, *alias = NULL, *sql_fields, *sql_values;
	zval *values, *update_values = NULL, *not_quoting = NULL, *update_value = NULL;
	zval *column = NULL, *sql_column = NULL, *expr_column = NULL, *expr_value = NULL;
	zval *type = NULL, *value = NULL, *where, *where_expr = NULL;
	zval *limit, *sql_limit = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(ast);
	phalcon_read_property_this(&ast, this_ptr, SL("_ast"), PH_NOISY TSRMLS_CC);
	if (!phalcon_array_isset_string(ast, SS("update"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted UPDATE AST");
		return;
	}
	
	PHALCON_OBS_VAR(update);
	phalcon_array_fetch_string(&update, ast, SL("update"), PH_NOISY);
	if (!phalcon_array_isset_string(update, SS("tables"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted UPDATE AST");
		return;
	}
	
	if (!phalcon_array_isset_string(update, SS("values"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted UPDATE AST");
		return;
	}
	
	/** 
	 * We use these arrays to store info related to models, alias and its sources. With
	 * them we can rename columns later
	 */
	PHALCON_INIT_VAR(models);
	array_init(models);
	
	PHALCON_INIT_VAR(models_instances);
	array_init(models_instances);
	
	PHALCON_INIT_VAR(sql_tables);
	array_init(sql_tables);
	
	PHALCON_INIT_VAR(sql_models);
	array_init(sql_models);
	
	PHALCON_INIT_VAR(sql_aliases);
	array_init(sql_aliases);
	
	PHALCON_INIT_VAR(sql_aliases_models_instances);
	array_init(sql_aliases_models_instances);
	
	PHALCON_OBS_VAR(tables);
	phalcon_array_fetch_string(&tables, update, SL("tables"), PH_NOISY);
	if (!phalcon_array_isset_long(tables, 0)) {
		PHALCON_INIT_VAR(update_tables);
		array_init_size(update_tables, 1);
		phalcon_array_append(&update_tables, tables, PH_SEPARATE);
	} else {
		PHALCON_CPY_WRT(update_tables, tables);
	}
	
	manager = phalcon_fetch_nproperty_this(this_ptr, SL("_manager"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(manager) != IS_OBJECT) {
		zend_throw_exception_ex(phalcon_mvc_model_exception_ce, 0 TSRMLS_CC, "dependency Injector is required to get '%s' service", "modelsManager");
	}
	
	phalcon_is_iterable(update_tables, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(table);
	
		PHALCON_OBS_NVAR(qualified_name);
		phalcon_array_fetch_string(&qualified_name, table, SL("qualifiedName"), PH_NOISY);
	
		PHALCON_OBS_NVAR(model_name);
		phalcon_array_fetch_string(&model_name, qualified_name, ISL(name), PH_NOISY);
	
		/** 
		 * Check if the table have a namespace alias
		 */
		if (phalcon_array_isset_string(qualified_name, SS("ns-alias"))) {
			PHALCON_OBS_NVAR(ns_alias);
			phalcon_array_fetch_string(&ns_alias, qualified_name, SL("ns-alias"), PH_NOISY);
	
			/** 
			 * Get the real namespace alias
			 */
			PHALCON_CALL_METHOD(&real_namespace, manager, "getnamespacealias", ns_alias);
	
			/** 
			 * Create the real namespaced name
			 */
			PHALCON_INIT_NVAR(real_model_name);
			PHALCON_CONCAT_VSV(real_model_name, real_namespace, "\\", model_name);
		} else {
			PHALCON_CPY_WRT(real_model_name, model_name);
		}
	
		/** 
		 * Load a model instance from the models manager
		 */
		PHALCON_CALL_METHOD(&model, manager, "load", real_model_name);
		PHALCON_CALL_METHOD(&source, model, "getsource");
		PHALCON_CALL_METHOD(&schema, model, "getschema");
	
		/** 
		 * Create a full source representation including schema
		 */
		if (zend_is_true(schema)) {
			PHALCON_INIT_NVAR(complete_source);
			array_init_size(complete_source, 2);
			phalcon_array_append(&complete_source, source, PH_SEPARATE);
			phalcon_array_append(&complete_source, schema, PH_SEPARATE);
		} else {
			PHALCON_INIT_NVAR(complete_source);
			array_init_size(complete_source, 2);
			phalcon_array_append(&complete_source, source, PH_SEPARATE);
			add_next_index_null(complete_source);
		}
	
		/** 
		 * Check if the table is aliased
		 */
		if (phalcon_array_isset_string(table, SS("alias"))) {
			PHALCON_OBS_NVAR(alias);
			phalcon_array_fetch_string(&alias, table, SL("alias"), PH_NOISY);
			phalcon_array_update_zval(&sql_aliases, alias, alias, PH_COPY | PH_SEPARATE);
			phalcon_array_append(&complete_source, alias, PH_SEPARATE);
			phalcon_array_append(&sql_tables, complete_source, PH_SEPARATE);
			phalcon_array_update_zval(&sql_aliases_models_instances, alias, model, PH_COPY | PH_SEPARATE);
			phalcon_array_update_zval(&models, alias, model_name, PH_COPY | PH_SEPARATE);
		} else {
			phalcon_array_update_zval(&sql_aliases, model_name, source, PH_COPY | PH_SEPARATE);
			phalcon_array_update_zval(&sql_aliases_models_instances, model_name, model, PH_COPY | PH_SEPARATE);
			phalcon_array_append(&sql_tables, source, PH_SEPARATE);
			phalcon_array_update_zval(&models, model_name, source, PH_COPY | PH_SEPARATE);
		}
	
		phalcon_array_append(&sql_models, model_name, PH_SEPARATE);
		phalcon_array_update_zval(&models_instances, model_name, model, PH_COPY | PH_SEPARATE);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * Update the models/alias/sources in the object
	 */
	phalcon_update_property_this(this_ptr, SL("_models"), models TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_modelsInstances"), models_instances TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_sqlAliases"), sql_aliases TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_sqlAliasesModelsInstances"), sql_aliases_models_instances TSRMLS_CC);
	
	PHALCON_INIT_VAR(sql_fields);
	array_init(sql_fields);
	
	PHALCON_INIT_VAR(sql_values);
	array_init(sql_values);
	
	PHALCON_OBS_VAR(values);
	phalcon_array_fetch_string(&values, update, SL("values"), PH_NOISY);
	if (!phalcon_array_isset_long(values, 0)) {
		PHALCON_INIT_VAR(update_values);
		array_init_size(update_values, 1);
		phalcon_array_append(&update_values, values, PH_SEPARATE);
	} else {
		PHALCON_CPY_WRT(update_values, values);
	}
	
	PHALCON_INIT_VAR(not_quoting);
	ZVAL_BOOL(not_quoting, 0);
	
	phalcon_is_iterable(update_values, &ah1, &hp1, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
		PHALCON_GET_HVALUE(update_value);
	
		PHALCON_OBS_NVAR(column);
		phalcon_array_fetch_string(&column, update_value, SL("column"), PH_NOISY);
	
		PHALCON_CALL_METHOD(&sql_column, this_ptr, "_getexpression", column, not_quoting);
		phalcon_array_append(&sql_fields, sql_column, PH_SEPARATE);
	
		PHALCON_OBS_NVAR(expr_column);
		phalcon_array_fetch_string(&expr_column, update_value, SL("expr"), PH_NOISY);
	
		PHALCON_CALL_METHOD(&expr_value, this_ptr, "_getexpression", expr_column, not_quoting);
	
		PHALCON_OBS_NVAR(type);
		phalcon_array_fetch_string(&type, expr_column, ISL(type), PH_NOISY);
	
		PHALCON_INIT_NVAR(value);
		array_init_size(value, 2);
		phalcon_array_update_string(&value, ISL(type), type, PH_COPY | PH_SEPARATE);
		phalcon_array_update_string(&value, SL("value"), expr_value, PH_COPY | PH_SEPARATE);
		phalcon_array_append(&sql_values, value, PH_SEPARATE);
	
		zend_hash_move_forward_ex(ah1, &hp1);
	}
	
	array_init_size(return_value, 7);
	phalcon_array_update_string(&return_value, ISL(tables), sql_tables, PH_COPY | PH_SEPARATE);
	phalcon_array_update_string(&return_value, ISL(models), sql_models, PH_COPY);
	phalcon_array_update_string(&return_value, ISL(fields), sql_fields, PH_COPY);
	phalcon_array_update_string(&return_value, ISL(values), sql_values, PH_COPY);
	if (phalcon_array_isset_string_fetch(&where, ast, SS("where"))) {
		ZVAL_TRUE(not_quoting);
	
		PHALCON_CALL_METHOD(&where_expr, this_ptr, "_getexpression", where, not_quoting);
		phalcon_array_update_string(&return_value, ISL(where), where_expr, PH_COPY);
	}
	
	if (phalcon_array_isset_string_fetch(&limit, ast, SS("limit"))) {
		PHALCON_CALL_METHOD(&sql_limit, this_ptr, "_getlimitclause", limit);
		phalcon_array_update_string(&return_value, ISL(limit), sql_limit, PH_COPY);
	}
	
	RETURN_MM();
}

/**
 * Analyzes a DELETE intermediate code and produces an array to be executed later
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareDelete){

	zval *ast, *delete, *models, *models_instances;
	zval *sql_tables, *sql_models, *sql_aliases;
	zval *sql_aliases_models_instances, *tables;
	zval *delete_tables = NULL, *manager, *table = NULL, *qualified_name = NULL;
	zval *model_name = NULL, *ns_alias = NULL, *real_namespace = NULL;
	zval *real_model_name = NULL, *model = NULL, *source = NULL, *schema = NULL;
	zval *complete_source = NULL, *alias = NULL, *not_quoting;
	zval *where, *where_expr = NULL;
	zval *limit, *sql_limit = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(ast);
	phalcon_read_property_this(&ast, this_ptr, SL("_ast"), PH_NOISY TSRMLS_CC);
	if (!phalcon_array_isset_string(ast, SS("delete"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted DELETE AST");
		return;
	}
	
	PHALCON_OBS_VAR(delete);
	phalcon_array_fetch_string(&delete, ast, SL("delete"), PH_NOISY);
	if (!phalcon_array_isset_string(delete, SS("tables"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted DELETE AST");
		return;
	}
	
	/** 
	 * We use these arrays to store info related to models, alias and its sources. With
	 * them we can rename columns later
	 */
	PHALCON_INIT_VAR(models);
	array_init(models);
	
	PHALCON_INIT_VAR(models_instances);
	array_init(models_instances);
	
	PHALCON_INIT_VAR(sql_tables);
	array_init(sql_tables);
	
	PHALCON_INIT_VAR(sql_models);
	array_init(sql_models);
	
	PHALCON_INIT_VAR(sql_aliases);
	array_init(sql_aliases);
	
	PHALCON_INIT_VAR(sql_aliases_models_instances);
	array_init(sql_aliases_models_instances);
	
	PHALCON_OBS_VAR(tables);
	phalcon_array_fetch_string(&tables, delete, SL("tables"), PH_NOISY);
	if (!phalcon_array_isset_long(tables, 0)) {
		PHALCON_INIT_VAR(delete_tables);
		array_init_size(delete_tables, 1);
		phalcon_array_append(&delete_tables, tables, PH_SEPARATE);
	} else {
		PHALCON_CPY_WRT(delete_tables, tables);
	}
	
	manager = phalcon_fetch_nproperty_this(this_ptr, SL("_manager"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(manager) != IS_OBJECT) {
		zend_throw_exception_ex(phalcon_mvc_model_exception_ce, 0 TSRMLS_CC, "dependency Injector is required to get '%s' service", "modelsManager");
	}

	phalcon_is_iterable(delete_tables, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(table);
	
		PHALCON_OBS_NVAR(qualified_name);
		phalcon_array_fetch_string(&qualified_name, table, SL("qualifiedName"), PH_NOISY);
	
		PHALCON_OBS_NVAR(model_name);
		phalcon_array_fetch_string(&model_name, qualified_name, ISL(name), PH_NOISY);
	
		/** 
		 * Check if the table have a namespace alias
		 */
		if (phalcon_array_isset_string(qualified_name, SS("ns-alias"))) {
			PHALCON_OBS_NVAR(ns_alias);
			phalcon_array_fetch_string(&ns_alias, qualified_name, SL("ns-alias"), PH_NOISY);
	
			/** 
			 * Get the real namespace alias
			 */
			PHALCON_CALL_METHOD(&real_namespace, manager, "getnamespacealias", ns_alias);
	
			/** 
			 * Create the real namespaced name
			 */
			PHALCON_INIT_NVAR(real_model_name);
			PHALCON_CONCAT_VSV(real_model_name, real_namespace, "\\", model_name);
		} else {
			PHALCON_CPY_WRT(real_model_name, model_name);
		}
	
		/** 
		 * Load a model instance from the models manager
		 */
		PHALCON_CALL_METHOD(&model, manager, "load", real_model_name);
		PHALCON_CALL_METHOD(&source, model, "getsource");
		PHALCON_CALL_METHOD(&schema, model, "getschema");
		if (zend_is_true(schema)) {
			PHALCON_INIT_NVAR(complete_source);
			array_init_size(complete_source, 2);
			phalcon_array_append(&complete_source, source, 0);
			phalcon_array_append(&complete_source, schema, 0);
		} else {
			PHALCON_INIT_NVAR(complete_source);
			array_init_size(complete_source, 2);
			phalcon_array_append(&complete_source, source, 0);
			add_next_index_null(complete_source);
		}
	
		if (phalcon_array_isset_string(table, SS("alias"))) {
			PHALCON_OBS_NVAR(alias);
			phalcon_array_fetch_string(&alias, table, SL("alias"), PH_NOISY);
			phalcon_array_update_zval(&sql_aliases, alias, alias, PH_COPY | PH_SEPARATE);
			phalcon_array_append(&complete_source, alias, PH_SEPARATE);
			phalcon_array_append(&sql_tables, complete_source, PH_SEPARATE);
			phalcon_array_update_zval(&sql_aliases_models_instances, alias, model, PH_COPY | PH_SEPARATE);
			phalcon_array_update_zval(&models, alias, model_name, PH_COPY | PH_SEPARATE);
		} else {
			phalcon_array_update_zval(&sql_aliases, model_name, source, PH_COPY | PH_SEPARATE);
			phalcon_array_update_zval(&sql_aliases_models_instances, model_name, model, PH_COPY | PH_SEPARATE);
			phalcon_array_append(&sql_tables, source, PH_SEPARATE);
			phalcon_array_update_zval(&models, model_name, source, PH_COPY | PH_SEPARATE);
		}
	
		phalcon_array_append(&sql_models, model_name, PH_SEPARATE);
		phalcon_array_update_zval(&models_instances, model_name, model, PH_COPY | PH_SEPARATE);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * Update the models/alias/sources in the object
	 */
	phalcon_update_property_this(this_ptr, SL("_models"), models TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_modelsInstances"), models_instances TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_sqlAliases"), sql_aliases TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_sqlAliasesModelsInstances"), sql_aliases_models_instances TSRMLS_CC);
	
	array_init_size(return_value, 4);
	phalcon_array_update_string(&return_value, ISL(tables), sql_tables, PH_COPY | PH_SEPARATE);
	phalcon_array_update_string(&return_value, ISL(models), sql_models, PH_COPY | PH_SEPARATE);
	if (phalcon_array_isset_string_fetch(&where, ast, SS("where"))) {
		PHALCON_INIT_VAR(not_quoting);
		ZVAL_TRUE(not_quoting);
	
		PHALCON_CALL_METHOD(&where_expr, this_ptr, "_getexpression", where, not_quoting);
		phalcon_array_update_string(&return_value, ISL(where), where_expr, PH_COPY);
	}
	
	if (phalcon_array_isset_string_fetch(&limit, ast, SS("limit"))) {
		PHALCON_CALL_METHOD(&sql_limit, this_ptr, "_getlimitclause", limit);
		phalcon_array_update_string(&return_value, ISL(limit), sql_limit, PH_COPY);
	}

	RETURN_MM();
}

/**
 * Parses the intermediate code produced by Phalcon\Mvc\Model\Query\Lang generating another
 * intermediate representation that could be executed by Phalcon\Mvc\Model\Query
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, parse){

	zval *intermediate, *phql, *ast, *ir_phql = NULL, *ir_phql_cache = NULL;
	zval *unique_id = NULL, *type = NULL, *exception_message;

	PHALCON_MM_GROW();

	intermediate = phalcon_fetch_nproperty_this(this_ptr, SL("_intermediate"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(intermediate) == IS_ARRAY) { 
		RETURN_CTOR(intermediate);
	}
	
	phql = phalcon_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * This function parses the PHQL statement
	 */
	PHALCON_INIT_VAR(ast);
	if (phql_parse_phql(ast, phql TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	
	PHALCON_INIT_VAR(ir_phql);
	
	PHALCON_INIT_VAR(ir_phql_cache);
	
	PHALCON_INIT_VAR(unique_id);
	
	if (Z_TYPE_P(ast) == IS_ARRAY) { 
	
		/** 
		 * Check if the prepared PHQL is already cached
		 */
		if (phalcon_array_isset_string(ast, SS("id"))) {
	
			/** 
			 * Parsed ASTs have a unique id
			 */
			PHALCON_OBS_NVAR(unique_id);
			phalcon_array_fetch_string(&unique_id, ast, SL("id"), PH_NOISY);
	
			PHALCON_OBS_NVAR(ir_phql_cache);
			phalcon_read_static_property(&ir_phql_cache, SL("phalcon\\mvc\\model\\query"), SL("_irPhqlCache") TSRMLS_CC);
			if (phalcon_array_isset(ir_phql_cache, unique_id)) {
	
				PHALCON_OBS_NVAR(ir_phql);
				phalcon_array_fetch(&ir_phql, ir_phql_cache, unique_id, PH_NOISY);
				if (Z_TYPE_P(ir_phql) == IS_ARRAY) { 
					/** 
					 * Assign the type to the query
					 */
					PHALCON_OBS_VAR(type);
					phalcon_array_fetch_string(&type, ast, ISL(type), PH_NOISY);
					phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
					RETURN_CTOR(ir_phql);
				}
			}
		}
	
		/** 
		 * A valid AST must have a type
		 */
		if (phalcon_array_isset_string(ast, ISS(type))) {
			phalcon_update_property_this(this_ptr, SL("_ast"), ast TSRMLS_CC);
	
			/** 
			 * Produce an independent database system representation
			 */
			PHALCON_OBS_NVAR(type);
			phalcon_array_fetch_string(&type, ast, ISL(type), PH_NOISY);
			phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	
			switch (phalcon_get_intval(type)) {
	
				case PHQL_T_SELECT:
					PHALCON_CALL_METHOD(&ir_phql, this_ptr, "_prepareselect");
					break;
	
				case PHQL_T_INSERT:
					PHALCON_CALL_METHOD(&ir_phql, this_ptr, "_prepareinsert");
					break;
	
				case PHQL_T_UPDATE:
					PHALCON_CALL_METHOD(&ir_phql, this_ptr, "_prepareupdate");
					break;
	
				case PHQL_T_DELETE:
					PHALCON_CALL_METHOD(&ir_phql, this_ptr, "_preparedelete");
					break;
	
				default:
					PHALCON_INIT_VAR(exception_message);
					PHALCON_CONCAT_SVSV(exception_message, "Unknown statement ", type, ", when preparing: ", phql);
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
					return;
			}
		}
	}
	
	if (Z_TYPE_P(ir_phql) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted AST");
		return;
	}
	
	/** 
	 * Store the prepared AST in the cache
	 */
	if (Z_TYPE_P(unique_id) == IS_LONG) {
		if (Z_TYPE_P(ir_phql_cache) != IS_ARRAY) { 
			PHALCON_INIT_NVAR(ir_phql_cache);
			array_init(ir_phql_cache);
		}
		phalcon_array_update_zval(&ir_phql_cache, unique_id, ir_phql, PH_COPY | PH_SEPARATE);
		phalcon_update_static_property_ce(phalcon_mvc_model_query_ce, SL("_irPhqlCache"), ir_phql_cache TSRMLS_CC);
	}
	
	phalcon_update_property_this(this_ptr, SL("_intermediate"), ir_phql TSRMLS_CC);
	
	RETURN_CTOR(ir_phql);
}

/**
 * Sets the cache parameters of the query
 *
 * @param array $cacheOptions
 * @return Phalcon\Mvc\Model\Query
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, cache){

	zval *cache_options;

	phalcon_fetch_params(0, 1, 0, &cache_options);
	
	phalcon_update_property_this(this_ptr, SL("_cacheOptions"), cache_options TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the current cache options
 *
 * @param array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getCacheOptions){


	RETURN_MEMBER(this_ptr, "_cacheOptions");
}

/**
 * Returns the current cache backend instance
 *
 * @return Phalcon\Cache\BackendInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getCache){


	RETURN_MEMBER(this_ptr, "_cache");
}

/**
 * Executes the SELECT intermediate representation producing a Phalcon\Mvc\Model\Resultset
 *
 * @param array $intermediate
 * @param array $bindParams
 * @param array $bindTypes
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeSelect){

	zval *intermediate, *bind_params, *bind_types;
	zval *manager, *models_instances = NULL, *models, *number_models;
	zval *model_name = NULL, *model = NULL, *connection = NULL, *connections;
	zval *type = NULL, *connection_types = NULL, *columns;
	zval *column = NULL, *column_type = NULL, *select_columns;
	zval *simple_column_map = NULL, *meta_data, *z_null;
	zval *alias_copy = NULL, *sql_column = NULL, *instance = NULL, *attributes = NULL;
	zval *column_map = NULL, *attribute = NULL, *hidden_alias = NULL;
	zval *column_alias = NULL, *is_keeping_snapshots = NULL;
	zval *sql_alias = NULL, *dialect = NULL, *sql_select = NULL, *processed = NULL;
	zval *value = NULL, *wildcard = NULL, *string_wildcard = NULL, *processed_types = NULL;
	zval *type_wildcard = NULL, *result = NULL, *count = NULL, *result_data = NULL;
	zval *cache, *result_object = NULL;
	HashTable *ah0, *ah1, *ah2, *ah3, *ah4, *ah5, *ah6;
	HashPosition hp0, hp1, hp2, hp3, hp4, hp5, hp6;
	zval **hd;
	int have_scalars = 0, have_objects = 0, is_complex = 0, is_simple_std = 0;
	size_t number_objects = 0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &intermediate, &bind_params, &bind_types);
	
	PHALCON_SEPARATE_PARAM(intermediate);
	
	manager = phalcon_fetch_nproperty_this(this_ptr, SL("_manager"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(manager) != IS_OBJECT) {
		zend_throw_exception_ex(phalcon_mvc_model_exception_ce, 0 TSRMLS_CC, "Dependency Injector is required to get '%s' service", "modelsManager");
	}

	/** 
	 * Models instances is an array if the SELECT was prepared with parse
	 */
	PHALCON_OBS_VAR(models_instances);
	phalcon_read_property_this(&models_instances, this_ptr, SL("_modelsInstances"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(models_instances) != IS_ARRAY) { 
		PHALCON_INIT_NVAR(models_instances);
		array_init(models_instances);
	}
	
	PHALCON_OBS_VAR(models);
	phalcon_array_fetch_string(&models, intermediate, SL("models"), PH_NOISY);
	
	PHALCON_INIT_VAR(number_models);
	phalcon_fast_count(number_models, models TSRMLS_CC);
	if (PHALCON_IS_LONG(number_models, 1)) {
	
		/** 
		 * Load first model if is not loaded
		 */
		PHALCON_OBS_VAR(model_name);
		phalcon_array_fetch_long(&model_name, models, 0, PH_NOISY);
		if (!phalcon_array_isset(models_instances, model_name)) {
			PHALCON_CALL_METHOD(&model, manager, "load", model_name);
			phalcon_array_update_zval(&models_instances, model_name, model, PH_COPY | PH_SEPARATE);
		} else {
			PHALCON_OBS_NVAR(model);
			phalcon_array_fetch(&model, models_instances, model_name, PH_NOISY);
		}
	
		/** 
		 * The 'selectConnection' method could be implemented in a 
		 */
		if (phalcon_method_exists_ex(model, SS("selectreadconnection") TSRMLS_CC) == SUCCESS) {
	
			PHALCON_CALL_METHOD(&connection, model, "selectreadconnection", intermediate, bind_params, bind_types);
			if (Z_TYPE_P(connection) != IS_OBJECT) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "'selectReadConnection' didn't returned a valid connection");
				return;
			}
		} else {
			/** 
			 * Get the current connection to the model
			 */
			PHALCON_CALL_METHOD(&connection, model, "getreadconnection");
		}
	} else {
		/** 
		 * Check if all the models belongs to the same connection
		 */
		PHALCON_INIT_VAR(connections);
		array_init(connections);
	
		phalcon_is_iterable(models, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(model_name);
	
			if (!phalcon_array_isset(models_instances, model_name)) {
				PHALCON_CALL_METHOD(&model, manager, "load", model_name);
				phalcon_array_update_zval(&models_instances, model_name, model, PH_COPY | PH_SEPARATE);
			} else {
				PHALCON_OBS_NVAR(model);
				phalcon_array_fetch(&model, models_instances, model_name, PH_NOISY);
			}
	
			/** 
			 * Get the models connection
			 */
			PHALCON_CALL_METHOD(&connection, model, "getreadconnection");
	
			/** 
			 * Get the type of connection the model is using (mysql, postgresql, etc)
			 */
			PHALCON_CALL_METHOD(&type, connection, "gettype");
	
			/** 
			 * Mark the type of connection in the connection flags
			 */
			phalcon_array_update_zval_bool(&connections, type, 1, PH_SEPARATE);
	
			PHALCON_INIT_NVAR(connection_types);
			phalcon_fast_count(connection_types, connections TSRMLS_CC);
	
			/** 
			 * More than one type of connection is not allowed
			 */
			if (PHALCON_IS_LONG(connection_types, 2)) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Cannot use models of different database systems in the same query");
				return;
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	PHALCON_OBS_VAR(columns);
	phalcon_array_fetch_string(&columns, intermediate, SL("columns"), PH_NOISY);
	
	/** 
	 * Check if the resultset have objects and how many of them have
	 */
	phalcon_is_iterable(columns, &ah1, &hp1, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
		PHALCON_GET_HVALUE(column);
	
		PHALCON_OBS_NVAR(column_type);
		phalcon_array_fetch_string(&column_type, column, ISL(type), PH_NOISY);
		if (PHALCON_IS_STRING(column_type, "scalar")) {
			if (!phalcon_array_isset_string(column, SS("balias"))) {
				is_complex = 1;
			}
	
			have_scalars = 1;
		} else {
			have_objects = 1;
			++number_objects;
		}
	
		zend_hash_move_forward_ex(ah1, &hp1);
	}
	
	/** 
	 * Check if the resultset to return is complex or simple
	 */
	if (!is_complex) {
		if (have_objects) {
			if (have_scalars) {
				is_complex = 1;
			} else if (number_objects == 1) {
				is_simple_std = 0;
			} else {
				is_complex = 1;
			}
		} else {
			is_simple_std = 1;
		}
	}
	
	/** 
	 * Processing selected columns
	 */
	PHALCON_INIT_VAR(select_columns);
	array_init(select_columns);
	
	PHALCON_INIT_VAR(simple_column_map);
	array_init(simple_column_map);
	
	meta_data = phalcon_fetch_nproperty_this(this_ptr, SL("_metaData"), PH_NOISY TSRMLS_CC);
	
	z_null = PHALCON_GLOBAL(z_null);
	
	phalcon_is_iterable(columns, &ah2, &hp2, 1, 0);
	
	while (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) == SUCCESS) {
	
		zval key = phalcon_get_current_key_w(ah2, &hp2);
		PHALCON_CPY_WRT_CTOR(alias_copy, &key);

		PHALCON_GET_HVALUE(column);
	
		PHALCON_OBS_NVAR(type);
		phalcon_array_fetch_string(&type, column, ISL(type), PH_NOISY);
	
		PHALCON_OBS_NVAR(sql_column);
		phalcon_array_fetch_string(&sql_column, column, SL("column"), PH_NOISY);
	
		/** 
		 * Complete objects are treated in a different way
		 */
		if (PHALCON_IS_STRING(type, "object")) {
	
			PHALCON_OBS_NVAR(model_name);
			phalcon_array_fetch_string(&model_name, column, SL("model"), PH_NOISY);
	
			/** 
			 * Base instance
			 */
			if (phalcon_array_isset(models_instances, model_name)) {
				PHALCON_OBS_NVAR(instance);
				phalcon_array_fetch(&instance, models_instances, model_name, PH_NOISY);
			} else {
				PHALCON_CALL_METHOD(&instance, manager, "load", model_name);
				phalcon_array_update_zval(&models_instances, model_name, instance, PH_COPY | PH_SEPARATE);
			}
	
			PHALCON_CALL_METHOD(&attributes, meta_data, "getattributes", instance);
			if (is_complex) {
	
				/** 
				 * If the resultset is complex we open every model into their columns
				 */
				if (PHALCON_GLOBAL(orm).column_renaming) {
					PHALCON_CALL_METHOD(&column_map, meta_data, "getcolumnmap", instance);
				} else {
					PHALCON_CPY_WRT(column_map, z_null);
				}
	
				/** 
				 * Add every attribute in the model to the generated select
				 */
				phalcon_is_iterable(attributes, &ah3, &hp3, 0, 0);
	
				while (zend_hash_get_current_data_ex(ah3, (void**) &hd, &hp3) == SUCCESS) {
	
					PHALCON_GET_HVALUE(attribute);
	
					PHALCON_INIT_NVAR(hidden_alias);
					PHALCON_CONCAT_SVSV(hidden_alias, "_", sql_column, "_", attribute);
	
					PHALCON_INIT_NVAR(column_alias);
					array_init_size(column_alias, 3);
					phalcon_array_append(&column_alias, attribute, 0);
					phalcon_array_append(&column_alias, sql_column, 0);
					phalcon_array_append(&column_alias, hidden_alias, 0);
					phalcon_array_append(&select_columns, column_alias, PH_SEPARATE);
	
					zend_hash_move_forward_ex(ah3, &hp3);
				}
	
				/** 
				 * We cache required meta-data to make its future access faster
				 */
				phalcon_array_update_string_multi_2(&columns, alias_copy, SL("instance"),   instance, 0);
				phalcon_array_update_string_multi_2(&columns, alias_copy, SL("attributes"), attributes, 0);
				phalcon_array_update_string_multi_2(&columns, alias_copy, SL("columnMap"),  column_map, 0);
	
				/** 
				 * Check if the model keeps snapshots
				 */
				PHALCON_CALL_METHOD(&is_keeping_snapshots, manager, "iskeepingsnapshots", instance);
				if (zend_is_true(is_keeping_snapshots)) {
					phalcon_array_update_string_multi_2(&columns, alias_copy, SL("keepSnapshots"), is_keeping_snapshots, 0);
				}
			} else {
				/** 
				 * Query only the columns that are registered as attributes in the metaData
				 */
				phalcon_is_iterable(attributes, &ah4, &hp4, 0, 0);
	
				while (zend_hash_get_current_data_ex(ah4, (void**) &hd, &hp4) == SUCCESS) {
	
					PHALCON_GET_HVALUE(attribute);
	
					PHALCON_INIT_NVAR(column_alias);
					array_init_size(column_alias, 2);
					phalcon_array_append(&column_alias, attribute, 0);
					phalcon_array_append(&column_alias, sql_column, 0);
					phalcon_array_append(&select_columns, column_alias, PH_SEPARATE);
	
					zend_hash_move_forward_ex(ah4, &hp4);
				}
	
			}
		} else {
			/** 
			 * Create an alias if the column doesn't have one
			 */
			if (Z_TYPE_P(alias_copy) == IS_LONG) {
				PHALCON_INIT_NVAR(column_alias);
				array_init_size(column_alias, 2);
				phalcon_array_append(&column_alias, sql_column, 0);
				phalcon_array_append(&column_alias, z_null, 0);
			} else {
				PHALCON_INIT_NVAR(column_alias);
				array_init_size(column_alias, 3);
				phalcon_array_append(&column_alias, sql_column, 0);
				phalcon_array_append(&column_alias, z_null, 0);
				phalcon_array_append(&column_alias, alias_copy, 0);
			}
			phalcon_array_append(&select_columns, column_alias, PH_SEPARATE);
		}
	
		/** 
		 * Simulate a column map
		 */
		if (!is_complex && is_simple_std) {
			if (phalcon_array_isset_string_fetch(&sql_alias, column, SS("sqlAlias"))) {
				phalcon_array_update_zval(&simple_column_map, sql_alias, alias_copy, PH_COPY | PH_SEPARATE);
			} else {
				phalcon_array_update_zval(&simple_column_map, alias_copy, alias_copy, PH_COPY | PH_SEPARATE);
			}
		}
	
		zend_hash_move_forward_ex(ah2, &hp2);
	}
	zend_hash_destroy(ah2);
	efree(ah2);
	
	phalcon_array_update_string(&intermediate, SL("columns"), select_columns, PH_COPY | PH_SEPARATE);
	
	/** 
	 * The corresponding SQL dialect generates the SQL statement based accordingly with
	 * the database system
	 */
	PHALCON_CALL_METHOD(&dialect, connection, "getdialect");
	PHALCON_CALL_METHOD(&sql_select, dialect, "select", intermediate);

	/** 
	 * Replace the placeholders
	 */
	if (Z_TYPE_P(bind_params) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(processed);
		array_init(processed);
	
		phalcon_is_iterable(bind_params, &ah5, &hp5, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah5, (void**) &hd, &hp5) == SUCCESS) {
	
			PHALCON_GET_HKEY(wildcard, ah5, hp5);
			PHALCON_GET_HVALUE(value);
	
			if (Z_TYPE_P(wildcard) == IS_LONG) {
				PHALCON_INIT_NVAR(string_wildcard);
				PHALCON_CONCAT_SV(string_wildcard, ":", wildcard);
				phalcon_array_update_zval(&processed, string_wildcard, value, PH_COPY);
			} else {
				phalcon_array_update_zval(&processed, wildcard, value, PH_COPY);
			}
	
			zend_hash_move_forward_ex(ah5, &hp5);
		}
	
	} else {
		PHALCON_CPY_WRT(processed, bind_params);
	}
	
	/** 
	 * Replace the bind Types
	 */
	if (Z_TYPE_P(bind_types) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(processed_types);
		array_init(processed_types);
	
		phalcon_is_iterable(bind_types, &ah6, &hp6, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah6, (void**) &hd, &hp6) == SUCCESS) {
	
			PHALCON_GET_HKEY(type_wildcard, ah6, hp6);
			PHALCON_GET_HVALUE(value);
	
			if (Z_TYPE_P(type_wildcard) == IS_LONG) {
				PHALCON_INIT_NVAR(string_wildcard);
				PHALCON_CONCAT_SV(string_wildcard, ":", type_wildcard);
				phalcon_array_update_zval(&processed_types, string_wildcard, value, PH_COPY | PH_SEPARATE);
			} else {
				phalcon_array_update_zval(&processed_types, type_wildcard, value, PH_COPY | PH_SEPARATE);
			}
	
			zend_hash_move_forward_ex(ah6, &hp6);
		}
	
	} else {
		PHALCON_CPY_WRT(processed_types, bind_types);
	}
	
	/** 
	 * Execute the query
	 */
	PHALCON_CALL_METHOD(&result, connection, "query", sql_select, processed, processed_types);
	
	/** 
	 * Check if the query has data
	 */
	PHALCON_CALL_METHOD(&count, result, "numrows", result);
	if (zend_is_true(count)) {
		PHALCON_CPY_WRT(result_data, result);
	} else {
		PHALCON_INIT_NVAR(result_data);
		ZVAL_BOOL(result_data, 0);
	}
	
	/** 
	 * Choose a resultset type
	 */
	PHALCON_OBS_VAR(cache);
	phalcon_read_property_this(&cache, this_ptr, SL("_cache"), PH_NOISY TSRMLS_CC);
	if (!is_complex) {
	
		/** 
		 * Select the base object
		 */
		if (is_simple_std) {
			/** 
			 * If the result is a simple standard object use an Phalcon\Mvc\Model\Row as base
			 */
			PHALCON_INIT_VAR(result_object);
			object_init_ex(result_object, phalcon_mvc_model_row_ce);
	
			/** 
			 * Standard objects can't keep snapshots
			 */
			PHALCON_INIT_NVAR(is_keeping_snapshots);
			ZVAL_BOOL(is_keeping_snapshots, 0);
		} else {
			PHALCON_CPY_WRT(result_object, model);
	
			/** 
			 * Get the column map
			 */
			PHALCON_CALL_METHOD(&simple_column_map, meta_data, "getcolumnmap", model);
	
			/** 
			 * Check if the model keeps snapshots
			 */
			PHALCON_CALL_METHOD(&is_keeping_snapshots, manager, "iskeepingsnapshots", model);
		}
	
		/** 
		 * Simple resultsets contains only complete objects
		 */
		object_init_ex(return_value, phalcon_mvc_model_resultset_simple_ce);
		PHALCON_CALL_METHOD(NULL, return_value, "__construct", simple_column_map, result_object, result_data, cache, is_keeping_snapshots);
	
		RETURN_MM();
	}
	
	/** 
	 * Complex resultsets may contain complete objects and scalars
	 */
	object_init_ex(return_value, phalcon_mvc_model_resultset_complex_ce);
	PHALCON_CALL_METHOD(NULL, return_value, "__construct", columns, result_data, cache);
	
	RETURN_MM();
}

/**
 * Executes the INSERT intermediate representation producing a Phalcon\Mvc\Model\Query\Status
 *
 * @param array $intermediate
 * @param array $bindParams
 * @param array $bindTypes
 * @return Phalcon\Mvc\Model\Query\StatusInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeInsert){

	zval *intermediate, *bind_params, *bind_types;
	zval *model_name, *manager, *models_instances;
	zval *model = NULL, *connection = NULL, *meta_data, *attributes = NULL;
	zval *automatic_fields = NULL, *fields = NULL, *column_map = NULL;
	zval *values, *number_fields, *number_values;
	zval *dialect = NULL, *double_colon, *empty_string;
	zval *null_value, *not_exists, *insert_values;
	zval *value = NULL, *number = NULL, *type = NULL, *expr_value = NULL, *insert_value = NULL;
	zval *insert_expr = NULL, *wildcard = NULL, *exception_message = NULL;
	zval *field_name = NULL, *attribute_name = NULL, *base_model = NULL;
	zval *insert_model, *success = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &intermediate, &bind_params, &bind_types);
	
	PHALCON_OBS_VAR(model_name);
	phalcon_array_fetch_string(&model_name, intermediate, SL("model"), PH_NOISY);
	
	manager = phalcon_fetch_nproperty_this(this_ptr, SL("_manager"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(manager) != IS_OBJECT) {
		zend_throw_exception_ex(phalcon_mvc_model_exception_ce, 0 TSRMLS_CC, "Dependency Injector is required to get '%s' service", "modelsManager");
	}

	PHALCON_OBS_VAR(models_instances);
	phalcon_read_property_this(&models_instances, this_ptr, SL("_modelsInstances"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset(models_instances, model_name)) {
		PHALCON_OBS_VAR(model);
		phalcon_array_fetch(&model, models_instances, model_name, PH_NOISY);
	} else {
		PHALCON_CALL_METHOD(&model, manager, "load", model_name);
	}
	
	/** 
	 * Get the model connection
	 */
	if (phalcon_method_exists_ex(model, SS("selectwriteconnection") TSRMLS_CC) == SUCCESS) {
		PHALCON_CALL_METHOD(&connection, model, "selectwriteconnection", intermediate, bind_params, bind_types);
		if (Z_TYPE_P(connection) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "'selectWriteConnection' didn't returned a valid connection");
			return;
		}
	} else {
		PHALCON_CALL_METHOD(&connection, model, "getwriteconnection");
	}
	
	PHALCON_OBS_VAR(meta_data);
	phalcon_read_property_this(&meta_data, this_ptr, SL("_metaData"), PH_NOISY TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&attributes, meta_data, "getattributes", model);
	
	PHALCON_INIT_VAR(automatic_fields);
	ZVAL_FALSE(automatic_fields);
	
	/** 
	 * The 'fields' index may already have the fields to be used in the query
	 */
	if (phalcon_array_isset_string(intermediate, SS("fields"))) {
		PHALCON_OBS_VAR(fields);
		phalcon_array_fetch_string(&fields, intermediate, SL("fields"), PH_NOISY);
	} else {
		ZVAL_TRUE(automatic_fields);
		PHALCON_CPY_WRT(fields, attributes);
		if (PHALCON_GLOBAL(orm).column_renaming) {
			PHALCON_CALL_METHOD(&column_map, meta_data, "getcolumnmap", model);
		} else {
			PHALCON_INIT_VAR(column_map);
		}
	}
	
	PHALCON_OBS_VAR(values);
	phalcon_array_fetch_string(&values, intermediate, SL("values"), PH_NOISY);
	
	PHALCON_INIT_VAR(number_fields);
	phalcon_fast_count(number_fields, fields TSRMLS_CC);
	
	PHALCON_INIT_VAR(number_values);
	phalcon_fast_count(number_values, values TSRMLS_CC);
	
	/** 
	 * The number of calculated values must be equal to the number of fields in the
	 * model
	 */
	if (!PHALCON_IS_EQUAL(number_fields, number_values)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The column count does not match the values count");
		return;
	}
	
	/** 
	 * Get the dialect to resolve the SQL expressions
	 */
	PHALCON_CALL_METHOD(&dialect, connection, "getdialect");
	
	PHALCON_INIT_VAR(double_colon);
	ZVAL_STRING(double_colon, ":", 1);
	
	PHALCON_INIT_VAR(empty_string);
	ZVAL_EMPTY_STRING(empty_string);
	
	PHALCON_INIT_VAR(null_value);
	
	PHALCON_INIT_VAR(not_exists);
	ZVAL_BOOL(not_exists, 0);
	
	PHALCON_INIT_VAR(insert_values);
	array_init(insert_values);
	
	phalcon_is_iterable(values, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HKEY(number, ah0, hp0);
		PHALCON_GET_HVALUE(value);
	
		PHALCON_OBS_NVAR(type);
		phalcon_array_fetch_string(&type, value, ISL(type), PH_NOISY);
	
		PHALCON_OBS_NVAR(expr_value);
		phalcon_array_fetch_string(&expr_value, value, SL("value"), PH_NOISY);
	
		switch (phalcon_get_intval(type)) {
	
			case PHQL_T_STRING:
			case PHQL_T_INTEGER:
			case PHQL_T_DOUBLE:
				PHALCON_CALL_METHOD(&insert_value, dialect, "getsqlexpression", expr_value);
				break;
	
			case PHQL_T_NULL:
				PHALCON_CPY_WRT(insert_value, null_value);
				break;
	
			case PHQL_T_NPLACEHOLDER:
			case PHQL_T_SPLACEHOLDER:
				if (Z_TYPE_P(bind_params) != IS_ARRAY) { 
					PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Bound parameter cannot be replaced because placeholders is not an array");
					return;
				}
	
				PHALCON_CALL_METHOD(&insert_expr, dialect, "getsqlexpression", expr_value);
	
				PHALCON_INIT_NVAR(wildcard);
				phalcon_fast_str_replace(wildcard, double_colon, empty_string, insert_expr);
				if (!phalcon_array_isset(bind_params, wildcard)) {
					PHALCON_INIT_NVAR(exception_message);
					PHALCON_CONCAT_SVS(exception_message, "Bound parameter '", wildcard, "' cannot be replaced because it isn't in the placeholders list");
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
					return;
				}
	
				PHALCON_OBS_NVAR(insert_value);
				phalcon_array_fetch(&insert_value, bind_params, wildcard, PH_NOISY);
				break;
	
			default:
				PHALCON_CALL_METHOD(&insert_expr, dialect, "getsqlexpression", expr_value);
	
				PHALCON_INIT_NVAR(insert_value);
				object_init_ex(insert_value, phalcon_db_rawvalue_ce);
				PHALCON_CALL_METHOD(NULL, insert_value, "__construct", insert_expr);
	
				break;
	
		}
	
		PHALCON_OBS_NVAR(field_name);
		phalcon_array_fetch(&field_name, fields, number, PH_NOISY);
	
		/** 
		 * If the user didn't defined a column list we assume all the model's attributes as
		 * columns
		 */
		if (PHALCON_IS_TRUE(automatic_fields)) {
	
			if (Z_TYPE_P(column_map) == IS_ARRAY) { 
				if (phalcon_array_isset(column_map, field_name)) {
					PHALCON_OBS_NVAR(attribute_name);
					phalcon_array_fetch(&attribute_name, column_map, field_name, PH_NOISY);
				} else {
					PHALCON_INIT_NVAR(exception_message);
					PHALCON_CONCAT_SVS(exception_message, "Column '", field_name, "\" isn't part of the column map");
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
					return;
				}
			} else {
				PHALCON_CPY_WRT(attribute_name, field_name);
			}
		} else {
			PHALCON_CPY_WRT(attribute_name, field_name);
		}
	
		phalcon_array_update_zval(&insert_values, attribute_name, insert_value, PH_COPY | PH_SEPARATE);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * Get a base model from the Models Manager
	 */
	PHALCON_CALL_METHOD(&base_model, manager, "load", model_name);
	
	/** 
	 * Clone the base model
	 */
	PHALCON_INIT_VAR(insert_model);
	if (phalcon_clone(insert_model, base_model TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	
	/** 
	 * Call 'create' to ensure that an insert is performed
	 */
	PHALCON_CALL_METHOD(&success, insert_model, "create", insert_values);
	
	/** 
	 * Return the insertation status
	 */
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	PHALCON_CALL_METHOD(NULL, return_value, "__construct", success, insert_model);
	
	RETURN_MM();
}

/**
 * Query the records on which the UPDATE/DELETE operation well be done
 *
 * @param Phalcon\Mvc\Model $model
 * @param array $intermediate
 * @param array $bindParams
 * @param array $bindTypes
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getRelatedRecords){

	zval *model, *intermediate, *bind_params, *bind_types;
	zval *selected_tables, *selected_models, *source = NULL;
	zval *model_name, *select_column, *selected_columns;
	zval *select_ir, *where_conditions, *limit_conditions;
	zval *type_select, *dependency_injector, *query;
	zval *a0 = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &model, &intermediate, &bind_params, &bind_types);
	
	PHALCON_OBS_VAR(selected_tables);
	phalcon_array_fetch_string(&selected_tables, intermediate, SL("tables"), PH_NOISY);
	
	PHALCON_OBS_VAR(selected_models);
	phalcon_array_fetch_string(&selected_models, intermediate, SL("models"), PH_NOISY);
	
	PHALCON_CALL_METHOD(&source, model, "getsource");
	
	PHALCON_INIT_VAR(model_name);
	phalcon_get_class(model_name, model, 0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(select_column);
	array_init_size(select_column, 1);
	
	PHALCON_INIT_VAR(a0);
	array_init_size(a0, 3);
	add_assoc_stringl_ex(a0, ISS(type), SL("object"), 1);
	phalcon_array_update_string(&a0, SL("model"), model_name, PH_COPY | PH_SEPARATE);
	phalcon_array_update_string(&a0, SL("column"), source, PH_COPY | PH_SEPARATE);
	phalcon_array_append(&select_column, a0, PH_SEPARATE);
	
	PHALCON_INIT_VAR(selected_columns);
	array_init_size(selected_columns, 1);
	phalcon_array_append(&selected_columns, select_column, PH_SEPARATE);
	
	/** 
	 * Instead of create a PQHL string statement we manually create the IR
	 * representation
	 */
	PHALCON_INIT_VAR(select_ir);
	array_init_size(select_ir, 3);
	phalcon_array_update_string(&select_ir, SL("columns"), select_column, PH_COPY | PH_SEPARATE);
	phalcon_array_update_string(&select_ir, SL("models"), selected_models, PH_COPY | PH_SEPARATE);
	phalcon_array_update_string(&select_ir, SL("tables"), selected_tables, PH_COPY | PH_SEPARATE);
	
	/** 
	 * Check if a WHERE clause was especified
	 */
	if (phalcon_array_isset_string(intermediate, SS("where"))) {
		PHALCON_OBS_VAR(where_conditions);
		phalcon_array_fetch_string(&where_conditions, intermediate, SL("where"), PH_NOISY);
		phalcon_array_update_string(&select_ir, SL("where"), where_conditions, PH_COPY | PH_SEPARATE);
	}
	
	/** 
	 * Check if a WHERE clause was especified
	 */
	if (phalcon_array_isset_string(intermediate, SS("limit"))) {
		PHALCON_OBS_VAR(limit_conditions);
		phalcon_array_fetch_string(&limit_conditions, intermediate, SL("limit"), PH_NOISY);
		phalcon_array_update_string(&select_ir, SL("limit"), limit_conditions, PH_COPY | PH_SEPARATE);
	}
	
	PHALCON_INIT_VAR(type_select);
	ZVAL_LONG(type_select, 309);
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * We create another Phalcon\Mvc\Model\Query to get the related records
	 */
	PHALCON_INIT_VAR(query);
	object_init_ex(query, phalcon_mvc_model_query_ce);
	PHALCON_CALL_METHOD(NULL, query, "__construct");
	
	PHALCON_CALL_METHOD(NULL, query, "setdi", dependency_injector);
	PHALCON_CALL_METHOD(NULL, query, "settype", type_select);
	PHALCON_CALL_METHOD(NULL, query, "setintermediate", select_ir);
	
	PHALCON_RETURN_CALL_METHOD(query, "execute", bind_params, bind_types);
	PHALCON_MM_RESTORE();
}

/**
 * Executes the UPDATE intermediate representation producing a Phalcon\Mvc\Model\Query\Status
 *
 * @param array $intermediate
 * @param array $bindParams
 * @param array $bindTypes
 * @return Phalcon\Mvc\Model\Query\StatusInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeUpdate){

	zval *intermediate, *bind_params, *bind_types;
	zval *models, *model_name, *models_instances;
	zval *model = NULL, *manager, *connection = NULL, *dialect = NULL, *double_colon;
	zval *empty_string, *fields, *values, *update_values;
	zval *select_bind_params = NULL, *select_bind_types = NULL;
	zval *null_value, *field = NULL, *number = NULL, *field_name = NULL;
	zval *value = NULL, *type = NULL, *expr_value = NULL, *update_value = NULL;
	zval *update_expr = NULL, *wildcard = NULL, *exception_message = NULL;
	zval *records = NULL, *success = NULL, *record = NULL;
	zval *r0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &intermediate, &bind_params, &bind_types);
	
	PHALCON_OBS_VAR(models);
	phalcon_array_fetch_string(&models, intermediate, SL("models"), PH_NOISY);
	if (phalcon_array_isset_long(models, 1)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Updating several models at the same time is still not supported");
		return;
	}
	
	PHALCON_OBS_VAR(model_name);
	phalcon_array_fetch_long(&model_name, models, 0, PH_NOISY);
	
	/** 
	 * Load the model from the modelsManager or from the _modelsInstances property
	 */
	PHALCON_OBS_VAR(models_instances);
	phalcon_read_property_this(&models_instances, this_ptr, SL("_modelsInstances"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset(models_instances, model_name)) {
		PHALCON_OBS_VAR(model);
		phalcon_array_fetch(&model, models_instances, model_name, PH_NOISY);
	} else {
		manager = phalcon_fetch_nproperty_this(this_ptr, SL("_manager"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(manager) != IS_OBJECT) {
			zend_throw_exception_ex(phalcon_mvc_model_exception_ce, 0 TSRMLS_CC, "dependency Injector is required to get '%s' service", "modelsManager");
		}

		PHALCON_CALL_METHOD(&model, manager, "load", model_name);
	}
	
	if (phalcon_method_exists_ex(model, SS("selectwriteconnection") TSRMLS_CC) == SUCCESS) {
		PHALCON_CALL_METHOD(&connection, model, "selectwriteconnection", intermediate, bind_params, bind_types);
		if (Z_TYPE_P(connection) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "'selectWriteConnection' didn't returned a valid connection");
			return;
		}
	} else {
		PHALCON_CALL_METHOD(&connection, model, "getwriteconnection");
	}
	
	PHALCON_CALL_METHOD(&dialect, connection, "getdialect");
	
	PHALCON_INIT_VAR(double_colon);
	ZVAL_STRING(double_colon, ":", 1);
	
	PHALCON_INIT_VAR(empty_string);
	ZVAL_EMPTY_STRING(empty_string);
	
	PHALCON_OBS_VAR(fields);
	phalcon_array_fetch_string(&fields, intermediate, SL("fields"), PH_NOISY);
	
	PHALCON_OBS_VAR(values);
	phalcon_array_fetch_string(&values, intermediate, SL("values"), PH_NOISY);
	
	/** 
	 * update_values is applied to every record
	 */
	PHALCON_INIT_VAR(update_values);
	array_init(update_values);
	
	/** 
	 * If a placeholder is unused in the update values, we assume that it's used in the
	 * SELECT
	 */
	PHALCON_CPY_WRT(select_bind_params, bind_params);
	PHALCON_CPY_WRT(select_bind_types, bind_types);
	
	PHALCON_INIT_VAR(null_value);
	
	phalcon_is_iterable(fields, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HKEY(number, ah0, hp0);
		PHALCON_GET_HVALUE(field);
	
		PHALCON_OBS_NVAR(field_name);
		phalcon_array_fetch_string(&field_name, field, ISL(name), PH_NOISY);
	
		PHALCON_OBS_NVAR(value);
		phalcon_array_fetch(&value, values, number, PH_NOISY);
	
		PHALCON_OBS_NVAR(type);
		phalcon_array_fetch_string(&type, value, ISL(type), PH_NOISY);
	
		PHALCON_OBS_NVAR(expr_value);
		phalcon_array_fetch_string(&expr_value, value, SL("value"), PH_NOISY);
	
		switch (phalcon_get_intval(type)) {
	
			case PHQL_T_STRING:
			case PHQL_T_DOUBLE:
			case PHQL_T_INTEGER:
				PHALCON_CALL_METHOD(&update_value, dialect, "getsqlexpression", expr_value);
				break;
	
			case PHQL_T_NULL:
				PHALCON_CPY_WRT(update_value, null_value);
				break;
	
			case PHQL_T_NPLACEHOLDER:
			case PHQL_T_SPLACEHOLDER:
				if (Z_TYPE_P(bind_params) != IS_ARRAY) {
					PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Bound parameter cannot be replaced because placeholders is not an array");
					return;
				}
	
				PHALCON_CALL_METHOD(&update_expr, dialect, "getsqlexpression", expr_value);
	
				PHALCON_INIT_NVAR(wildcard);
				phalcon_fast_str_replace(wildcard, double_colon, empty_string, update_expr);
				if (phalcon_array_isset(bind_params, wildcard)) {
					PHALCON_OBS_NVAR(update_value);
					phalcon_array_fetch(&update_value, bind_params, wildcard, PH_NOISY);
					phalcon_array_unset(&select_bind_params, wildcard, PH_SEPARATE);
					phalcon_array_unset(&select_bind_types, wildcard, PH_SEPARATE);
				} else {
					PHALCON_INIT_NVAR(exception_message);
					PHALCON_CONCAT_SVS(exception_message, "Bound parameter '", wildcard, "' cannot be replaced because it's not in the placeholders list");
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
					return;
				}
	
				break;

			default:
				PHALCON_CALL_METHOD(&update_expr, dialect, "getsqlexpression", expr_value);
	
				PHALCON_INIT_NVAR(update_value);
				object_init_ex(update_value, phalcon_db_rawvalue_ce);
				PHALCON_CALL_METHOD(NULL, update_value, "__construct", update_expr);
	
				break;
	
		}
		phalcon_array_update_zval(&update_values, field_name, update_value, PH_COPY | PH_SEPARATE);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * We need to query the records related to the update
	 */
	PHALCON_CALL_METHOD(&records, this_ptr, "_getrelatedrecords", model, intermediate, select_bind_params, select_bind_types);
	
	/** 
	 * If there are no records to apply the update we return success
	 */
	if (!phalcon_fast_count_ev(records TSRMLS_CC)) {
		PHALCON_INIT_VAR(success);
		ZVAL_TRUE(success);
		object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
		PHALCON_CALL_METHOD(NULL, return_value, "__construct", success, null_value);
	
		RETURN_MM();
	}
	
	PHALCON_CALL_METHOD(&connection, model, "getwriteconnection");
	
	/** 
	 * Create a transaction in the write connection
	 */
	PHALCON_CALL_METHOD(NULL, connection, "begin");
	PHALCON_CALL_METHOD(NULL, records, "rewind");
	
	while (1) {
		PHALCON_CALL_METHOD(&r0, records, "valid");
		if (PHALCON_IS_NOT_FALSE(r0)) {
		} else {
			break;
		}
	
		/** 
		 * Get the current record in the iterator
		 */
		PHALCON_CALL_METHOD(&record, records, "current");
	
		/** 
		 * We apply the executed values to every record found
		 */
		PHALCON_CALL_METHOD(&success, record, "update", update_values);
		if (!zend_is_true(success)) {
			/** 
			 * Rollback the transaction on failure
			 */
			PHALCON_CALL_METHOD(NULL, connection, "rollback");
			object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
			PHALCON_CALL_METHOD(NULL, return_value, "__construct", success, record);
	
			RETURN_MM();
		}
	
		/** 
		 * Move the cursor to the next record
		 */
		PHALCON_CALL_METHOD(NULL, records, "next");
	}
	
	/** 
	 * Commit transaction on success
	 */
	PHALCON_CALL_METHOD(NULL, connection, "commit");
	
	PHALCON_INIT_NVAR(success);
	ZVAL_TRUE(success);
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	PHALCON_CALL_METHOD(NULL, return_value, "__construct", success, null_value);
	
	RETURN_MM();
}

/**
 * Executes the DELETE intermediate representation producing a Phalcon\Mvc\Model\Query\Status
 *
 * @param array $intermediate
 * @param array $bindParams
 * @param array $bindTypes
 * @return Phalcon\Mvc\Model\Query\StatusInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeDelete){

	zval *intermediate, *bind_params, *bind_types;
	zval *models, *model_name, *models_instances;
	zval *model = NULL, *manager, *records = NULL, *success = NULL, *null_value = NULL;
	zval *connection = NULL, *record = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &intermediate, &bind_params, &bind_types);
	
	PHALCON_OBS_VAR(models);
	phalcon_array_fetch_string(&models, intermediate, SL("models"), PH_NOISY);
	if (phalcon_array_isset_long(models, 1)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Delete from several models at the same time is still not supported");
		return;
	}
	
	PHALCON_OBS_VAR(model_name);
	phalcon_array_fetch_long(&model_name, models, 0, PH_NOISY);
	
	/** 
	 * Load the model from the modelsManager or from the _modelsInstances property
	 */
	PHALCON_OBS_VAR(models_instances);
	phalcon_read_property_this(&models_instances, this_ptr, SL("_modelsInstances"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset(models_instances, model_name)) {
		PHALCON_OBS_VAR(model);
		phalcon_array_fetch(&model, models_instances, model_name, PH_NOISY);
	} else {
		manager = phalcon_fetch_nproperty_this(this_ptr, SL("_manager"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(manager) != IS_OBJECT) {
			zend_throw_exception_ex(phalcon_mvc_model_exception_ce, 0 TSRMLS_CC, "dependency Injector is required to get '%s' service", "modelsManager");
		}

		PHALCON_CALL_METHOD(&model, manager, "load", model_name);
	}
	
	/** 
	 * Get the records to be deleted
	 */
	PHALCON_CALL_METHOD(&records, this_ptr, "_getrelatedrecords", model, intermediate, bind_params, bind_types);
	
	/** 
	 * If there are no records to delete we return success
	 */
	if (!phalcon_fast_count_ev(records TSRMLS_CC)) {
		PHALCON_INIT_VAR(success);
		ZVAL_TRUE(success);
	
		PHALCON_INIT_VAR(null_value);
		object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
		PHALCON_CALL_METHOD(NULL, return_value, "__construct", success, null_value);
	
		RETURN_MM();
	}
	
	if (phalcon_method_exists_ex(model, SS("selectwriteconnection") TSRMLS_CC) == SUCCESS) {
		PHALCON_CALL_METHOD(&connection, model, "selectwriteconnection", intermediate, bind_params, bind_types);
		if (Z_TYPE_P(connection) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "'selectWriteConnection' didn't returned a valid connection");
			return;
		}
	} else {
		PHALCON_CALL_METHOD(&connection, model, "getwriteconnection");
	}
	
	/** 
	 * Create a transaction in the write connection
	 */
	PHALCON_CALL_METHOD(NULL, connection, "begin");
	PHALCON_CALL_METHOD(NULL, records, "rewind");
	
	while (1) {
	
		PHALCON_CALL_METHOD(&r0, records, "valid");
		if (PHALCON_IS_NOT_FALSE(r0)) {
		} else {
			break;
		}
	
		PHALCON_CALL_METHOD(&record, records, "current");
	
		/** 
		 * We delete every record found
		 */
		PHALCON_CALL_METHOD(&success, record, "delete");
		if (!zend_is_true(success)) {
			/** 
			 * Rollback the transaction
			 */
			PHALCON_CALL_METHOD(NULL, connection, "rollback");
			object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
			PHALCON_CALL_METHOD(NULL, return_value, "__construct", success, record);
	
			RETURN_MM();
		}
	
		/** 
		 * Move the cursor to the next record
		 */
		PHALCON_CALL_METHOD(NULL, records, "next");
	}
	
	/** 
	 * Commit the transaction
	 */
	PHALCON_CALL_METHOD(NULL, connection, "commit");
	
	PHALCON_INIT_NVAR(success);
	ZVAL_TRUE(success);
	
	PHALCON_INIT_NVAR(null_value);
	ZVAL_TRUE(null_value);
	
	/** 
	 * Create a status to report the deletion status
	 */
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	PHALCON_CALL_METHOD(NULL, return_value, "__construct", success, null_value);
	
	RETURN_MM();
}

/**
 * Executes a parsed PHQL statement
 *
 * @param array $bindParams
 * @param array $bindTypes
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, execute){

	zval *bind_params = NULL, *bind_types = NULL, *unique_row;
	zval *cache_options, *key = NULL, *lifetime = NULL, *cache_service = NULL;
	zval *dependency_injector, *cache = NULL, *frontend = NULL, *result = NULL, *is_fresh;
	zval *prepared_result = NULL, *intermediate = NULL, *default_bind_params;
	zval *merged_params = NULL, *default_bind_types;
	zval *merged_types = NULL, *type, *exception_message;
	int cache_options_is_not_null;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &bind_params, &bind_types);
	
	if (!bind_params) {
		bind_params = PHALCON_GLOBAL(z_null);
	}
	
	if (!bind_types) {
		bind_types = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_OBS_VAR(unique_row);
	phalcon_read_property_this(&unique_row, this_ptr, SL("_uniqueRow"), PH_NOISY TSRMLS_CC);
	
	cache_options             = phalcon_fetch_nproperty_this(this_ptr, SL("_cacheOptions"), PH_NOISY TSRMLS_CC);
	cache_options_is_not_null = (Z_TYPE_P(cache_options) != IS_NULL); /* to keep scan-build happy */

	if (cache_options_is_not_null) {
		if (Z_TYPE_P(cache_options) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid caching options");
			return;
		}
	
		/** 
		 * The user must set a cache key
		 */
		if (!phalcon_array_isset_string_fetch(&key, cache_options, SS("key"))) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A cache key must be provided to identify the cached resultset in the cache backend");
			return;
		}
	
		/** 
		 * 'modelsCache' is the default name for the models cache service
		 */
		if (!phalcon_array_isset_string_fetch(&cache_service, cache_options, SS("service"))) {
			PHALCON_INIT_VAR(cache_service);
			PHALCON_ZVAL_MAYBE_INTERNED_STRING(cache_service, phalcon_interned_modelsCache);
		}
	
		PHALCON_OBS_VAR(dependency_injector);
		phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
	
		PHALCON_CALL_METHOD(&cache, dependency_injector, "getshared", cache_service);
		if (Z_TYPE_P(cache) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The cache service must be an object");
			return;
		}

		PHALCON_VERIFY_INTERFACE(cache, phalcon_cache_backendinterface_ce);
	
		/**
		 * By defaut use use 3600 seconds (1 hour) as cache lifetime
		 */
		if (!phalcon_array_isset_string_fetch(&lifetime, cache_options, SS("lifetime"))) {
			PHALCON_CALL_METHOD(&frontend, cache, "getfrontend");

			if (Z_TYPE_P(frontend) == IS_OBJECT) {
				PHALCON_VERIFY_INTERFACE_EX(frontend, phalcon_cache_frontendinterface_ce, phalcon_mvc_model_exception_ce, 1);
				PHALCON_CALL_METHOD(&lifetime, frontend, "getlifetime");
			}
			else {
				PHALCON_INIT_VAR(lifetime);
				ZVAL_LONG(lifetime, 3600);
			}
		}

		PHALCON_CALL_METHOD(&result, cache, "get", key, lifetime);
		if (Z_TYPE_P(result) != IS_NULL) {
			if (Z_TYPE_P(result) != IS_OBJECT) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The cache didn't return a valid resultset");
				return;
			}
	
			PHALCON_INIT_VAR(is_fresh);
			ZVAL_BOOL(is_fresh, 0);
			PHALCON_CALL_METHOD(NULL, result, "setisfresh", is_fresh);
	
			/** 
			 * Check if only the first row must be returned
			 */
			if (zend_is_true(unique_row)) {
				PHALCON_CALL_METHOD(&prepared_result, result, "getfirst");
			} else {
				PHALCON_CPY_WRT(prepared_result, result);
			}
	
			RETURN_CTOR(prepared_result);
		}
	
		phalcon_update_property_this(this_ptr, SL("_cache"), cache TSRMLS_CC);
		assert(key != NULL);
	}
	
	/** 
	 * The statement is parsed from its PHQL string or a previously processed IR
	 */
	PHALCON_CALL_METHOD(&intermediate, this_ptr, "parse");
	
	/** 
	 * Check for default bind parameters and merge them with the passed ones
	 */
	PHALCON_OBS_VAR(default_bind_params);
	phalcon_read_property_this(&default_bind_params, this_ptr, SL("_bindParams"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(default_bind_params) == IS_ARRAY) { 
		if (Z_TYPE_P(bind_params) == IS_ARRAY) { 
			PHALCON_INIT_VAR(merged_params);
			phalcon_fast_array_merge(merged_params, &default_bind_params, &bind_params TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(merged_params, default_bind_params);
		}
	} else {
		PHALCON_CPY_WRT(merged_params, bind_params);
	}

	/** 
	 * Check for default bind types and merge them with the passed ones
	 */
	PHALCON_OBS_VAR(default_bind_types);
	phalcon_read_property_this(&default_bind_types, this_ptr, SL("_bindTypes"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(default_bind_types) == IS_ARRAY) { 
		if (Z_TYPE_P(bind_types) == IS_ARRAY) { 
			PHALCON_INIT_VAR(merged_types);
			phalcon_fast_array_merge(merged_types, &default_bind_types, &bind_types TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(merged_types, default_bind_types);
		}
	} else {
		PHALCON_CPY_WRT(merged_types, bind_types);
	}
	
	PHALCON_OBS_VAR(type);
	phalcon_read_property_this(&type, this_ptr, SL("_type"), PH_NOISY TSRMLS_CC);
	
	switch (phalcon_get_intval(type)) {
	
		case PHQL_T_SELECT:
			PHALCON_CALL_METHOD(&result, this_ptr, "_executeselect", intermediate, merged_params, merged_types);
			break;
	
		case PHQL_T_INSERT:
			PHALCON_CALL_METHOD(&result, this_ptr, "_executeinsert", intermediate, merged_params, merged_types);
			break;
	
		case PHQL_T_UPDATE:
			PHALCON_CALL_METHOD(&result, this_ptr, "_executeupdate", intermediate, merged_params, merged_types);
			break;
	
		case PHQL_T_DELETE:
			PHALCON_CALL_METHOD(&result, this_ptr, "_executedelete", intermediate, merged_params, merged_types);
			break;
	
		default:
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SV(exception_message, "Unknown statement ", type);
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
	
	}
	
	/** 
	 * We store the resultset in the cache if any
	 */
	if (cache_options_is_not_null) {
	
		/** 
		 * Only PHQL SELECTs can be cached
		 */
		if (!PHALCON_IS_LONG(type, PHQL_T_SELECT)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Only PHQL statements that return resultsets can be cached");
			return;
		}

		assert(key != NULL);
		PHALCON_CALL_METHOD(NULL, cache, "save", key, result, lifetime);
	}
	
	/** 
	 * Check if only the first row must be returned
	 */
	if (zend_is_true(unique_row)) {
		PHALCON_RETURN_CALL_METHOD(result, "getfirst");
		RETURN_MM();
	}

	RETURN_CTOR(result);
}

/**
 * Executes the query returning the first result
 *
 * @param array $bindParams
 * @param array $bindTypes
 * @return Ṕhalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getSingleResult){

	zval *bind_params = NULL, *bind_types = NULL, *unique_row;
	zval *first_result = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &bind_params, &bind_types);
	
	if (!bind_params) {
		bind_params = PHALCON_GLOBAL(z_null);
	}
	
	if (!bind_types) {
		bind_types = PHALCON_GLOBAL(z_null);
	}
	
	unique_row = phalcon_fetch_nproperty_this(this_ptr, SL("_uniqueRow"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * The query is already programmed to return just one row
	 */
	if (zend_is_true(unique_row)) {
		PHALCON_RETURN_CALL_METHOD(this_ptr, "execute", bind_params, bind_types);
		RETURN_MM();
	}
	
	PHALCON_RETURN_CALL_METHOD(this_ptr, "execute", bind_params, bind_types);
	PHALCON_CALL_METHOD(&first_result, return_value, "getfirst"); /* @todo is this correct? */
	RETURN_MM();
}

/**
 * Sets the type of PHQL statement to be executed
 *
 * @param int $type
 * @return Phalcon\Mvc\Model\Query
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setType){

	zval *type;

	phalcon_fetch_params(0, 1, 0, &type);
	
	phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Gets the type of PHQL statement executed
 *
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getType){


	RETURN_MEMBER(this_ptr, "_type");
}

/**
 * Set default bind parameters
 *
 * @param array $bindParams
 * @return Phalcon\Mvc\Model\Query
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setBindParams){

	zval *bind_params;

	phalcon_fetch_params(0, 1, 0, &bind_params);
	
	if (Z_TYPE_P(bind_params) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "Bind parameters must be an array");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_bindParams"), bind_params TSRMLS_CC);
	
	RETURN_THISW();
}

/**
 * Returns default bind params
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getBindParams){


	RETURN_MEMBER(this_ptr, "_bindParams");
}

/**
 * Set default bind parameters
 *
 * @param array $bindTypes
 * @return Phalcon\Mvc\Model\Query
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setBindTypes){

	zval *bind_types;

	phalcon_fetch_params(0, 1, 0, &bind_types);
	
	if (Z_TYPE_P(bind_types) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "Bind types must be an array");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_bindTypes"), bind_types TSRMLS_CC);
	
	RETURN_THISW();
}

/**
 * Returns default bind types
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getBindTypes){


	RETURN_MEMBER(this_ptr, "_bindTypes");
}

/**
 * Allows to set the IR to be executed
 *
 * @param array $intermediate
 * @return Phalcon\Mvc\Model\Query
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setIntermediate){

	zval *intermediate;

	phalcon_fetch_params(0, 1, 0, &intermediate);
	
	phalcon_update_property_this(this_ptr, SL("_intermediate"), intermediate TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the intermediate representation of the PHQL statement
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getIntermediate){


	RETURN_MEMBER(this_ptr, "_intermediate");
}
