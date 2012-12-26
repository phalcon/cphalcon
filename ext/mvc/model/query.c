
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/file.h"
#include "mvc/model/query/scanner.h"
#include "mvc/model/query/phql.h"

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
 *
 */


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
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, __construct){

	zval *phql = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &phql) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!phql) {
		PHALCON_INIT_VAR(phql);
	}
	
	if (Z_TYPE_P(phql) != IS_NULL) {
		phalcon_update_property_zval(this_ptr, SL("_phql"), phql TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the dependency injection container
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setDI){

	zval *dependency_injector, *service = NULL, *manager;
	zval *meta_data;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the ORM services");
		return;
	}
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "modelsManager", 1);
	
	PHALCON_INIT_VAR(manager);
	PHALCON_CALL_METHOD_PARAMS_1(manager, dependency_injector, "getshared", service);
	if (Z_TYPE_P(manager) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Injected service 'modelsManager' is invalid");
		return;
	}
	
	PHALCON_INIT_NVAR(service);
	ZVAL_STRING(service, "modelsMetadata", 1);
	
	PHALCON_INIT_VAR(meta_data);
	PHALCON_CALL_METHOD_PARAMS_1(meta_data, dependency_injector, "getshared", service);
	if (Z_TYPE_P(meta_data) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Injected service 'modelsMetadata' is invalid");
		return;
	}
	
	phalcon_update_property_zval(this_ptr, SL("_manager"), manager TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_metaData"), meta_data TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
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
 * Replaces the model's name to its source name in a qualifed-name expression
 *
 * @param array $expr
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getQualified){

	zval *expr, *column_name, *sql_column_aliases;
	zval *source_column = NULL, *meta_data, *column_domain;
	zval *sql_aliases, *exception_message = NULL, *source = NULL;
	zval *sql_aliases_models_instances, *model = NULL;
	zval *column_map = NULL, *real_column_name = NULL, *one, *number;
	zval *has_model = NULL, *models_instances, *has_attribute = NULL;
	zval *ambiguity = NULL, *models, *class_name;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &expr) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(column_name);
	phalcon_array_fetch_string(&column_name, expr, SL("name"), PH_NOISY_CC);
	
	/** 
	 * Check if the qualified name is a column alias
	 */
	PHALCON_OBS_VAR(sql_column_aliases);
	phalcon_read_property(&sql_column_aliases, this_ptr, SL("_sqlColumnAliases"), PH_NOISY_CC);
	if (phalcon_array_isset(sql_column_aliases, column_name)) {
		PHALCON_INIT_VAR(source_column);
		array_init_size(source_column, 2);
		add_assoc_stringl_ex(source_column, SS("type"), SL("qualified"), 1);
		phalcon_array_update_string(&source_column, SL("name"), &column_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
		RETURN_CTOR(source_column);
	}
	
	PHALCON_OBS_VAR(meta_data);
	phalcon_read_property(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
	
	/** 
	 * Check if the qualified name has a domain
	 */
	if (phalcon_array_isset_string(expr, SS("domain"))) {
	
		PHALCON_OBS_VAR(column_domain);
		phalcon_array_fetch_string(&column_domain, expr, SL("domain"), PH_NOISY_CC);
	
		PHALCON_OBS_VAR(sql_aliases);
		phalcon_read_property(&sql_aliases, this_ptr, SL("_sqlAliases"), PH_NOISY_CC);
	
		/** 
		 * The column has a domain, we need to check if it's an alias
		 */
		if (!phalcon_array_isset(sql_aliases, column_domain)) {
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "Unknown table or alias '", column_domain, "' (1)");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
		}
	
		PHALCON_OBS_VAR(source);
		phalcon_array_fetch(&source, sql_aliases, column_domain, PH_NOISY_CC);
	
		/** 
		 * Retrieve the corresponding model by its alias
		 */
		PHALCON_OBS_VAR(sql_aliases_models_instances);
		phalcon_read_property(&sql_aliases_models_instances, this_ptr, SL("_sqlAliasesModelsInstances"), PH_NOISY_CC);
		if (!phalcon_array_isset(sql_aliases_models_instances, column_domain)) {
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "There is no model related to table or alias '", column_domain, "'");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
		}
	
		/** 
		 * Change the selected column by its real name on its mapped table
		 */
		if (PHALCON_GLOBAL(orm).column_renaming) {
			PHALCON_OBS_VAR(model);
			phalcon_array_fetch(&model, sql_aliases_models_instances, column_domain, PH_NOISY_CC);
	
			PHALCON_INIT_VAR(column_map);
			PHALCON_CALL_METHOD_PARAMS_1(column_map, meta_data, "getreversecolumnmap", model);
		} else {
			PHALCON_INIT_NVAR(column_map);
		}
	
		if (Z_TYPE_P(column_map) == IS_ARRAY) { 
			if (phalcon_array_isset(column_map, column_name)) {
				PHALCON_OBS_VAR(real_column_name);
				phalcon_array_fetch(&real_column_name, column_map, column_name, PH_NOISY_CC);
			} else {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVSVS(exception_message, "Column '", column_name, "' doesn't belong to the model or alias '", column_domain, "'");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
		} else {
			PHALCON_CPY_WRT(real_column_name, column_name);
		}
	} else {
		/** 
		 * If the column IR doesn't have a domain, we must check for ambiguities
		 */
		PHALCON_INIT_VAR(one);
		ZVAL_LONG(one, 1);
	
		PHALCON_INIT_VAR(number);
		ZVAL_LONG(number, 0);
	
		PHALCON_INIT_VAR(has_model);
		ZVAL_BOOL(has_model, 0);
	
		PHALCON_OBS_VAR(models_instances);
		phalcon_read_property(&models_instances, this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
	
		if (!phalcon_valid_foreach(models_instances TSRMLS_CC)) {
			return;
		}
	
		ah0 = Z_ARRVAL_P(models_instances);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(model);
	
			PHALCON_INIT_NVAR(has_attribute);
			PHALCON_CALL_METHOD_PARAMS_2(has_attribute, meta_data, "hasattribute", model, column_name);
			if (zend_is_true(has_attribute)) {
				PHALCON_SEPARATE(number);
				increment_function(number);
	
				PHALCON_INIT_NVAR(ambiguity);
				is_smaller_function(ambiguity, one, number TSRMLS_CC);
				if (PHALCON_IS_TRUE(ambiguity)) {
					PHALCON_INIT_NVAR(exception_message);
					PHALCON_CONCAT_SVS(exception_message, "The column '", column_name, "' is ambiguous");
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
					return;
				}
	
				PHALCON_CPY_WRT(has_model, model);
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		if (PHALCON_IS_FALSE(has_model)) {
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "Column '", column_name, "' doesn't belong to any of the selected models (1)");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
		}
	
		/** 
		 * Check if the _models property is correctly prepared
		 */
		PHALCON_OBS_VAR(models);
		phalcon_read_property(&models, this_ptr, SL("_models"), PH_NOISY_CC);
		if (Z_TYPE_P(models) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The models list was not loaded correctly");
			return;
		}
	
		/** 
		 * Obtain the model's source from the _models list
		 */
		PHALCON_INIT_VAR(class_name);
		phalcon_get_class(class_name, has_model, 0 TSRMLS_CC);
		if (phalcon_array_isset(models, class_name)) {
			PHALCON_OBS_NVAR(source);
			phalcon_array_fetch(&source, models, class_name, PH_NOISY_CC);
		} else {
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "Column '", column_name, "' doesn't belong to any of the selected models (2)");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
		}
	
		/** 
		 * Rename the column
		 */
		if (PHALCON_GLOBAL(orm).column_renaming) {
			PHALCON_INIT_NVAR(column_map);
			PHALCON_CALL_METHOD_PARAMS_1(column_map, meta_data, "getreversecolumnmap", has_model);
		} else {
			PHALCON_INIT_NVAR(column_map);
		}
	
		if (Z_TYPE_P(column_map) == IS_ARRAY) { 
			if (phalcon_array_isset(column_map, column_name)) {
				PHALCON_OBS_NVAR(real_column_name);
				phalcon_array_fetch(&real_column_name, column_map, column_name, PH_NOISY_CC);
			} else {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Column '", column_name, "' doesn't belong to any of the selected models (3)");
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
	PHALCON_INIT_NVAR(source_column);
	array_init_size(source_column, 4);
	add_assoc_stringl_ex(source_column, SS("type"), SL("qualified"), 1);
	phalcon_array_update_string(&source_column, SL("domain"), &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&source_column, SL("name"), &real_column_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&source_column, SL("balias"), &column_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	RETURN_CTOR(source_column);
}

/**
 * Resolves a expression in a single call argument
 *
 * @param array $argument
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getCallArgument){

	zval *argument, *argument_type, *argument_expr = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &argument) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(argument_type);
	phalcon_array_fetch_string(&argument_type, argument, SL("type"), PH_NOISY_CC);
	if (phalcon_compare_strict_long(argument_type, 352 TSRMLS_CC)) {
		PHALCON_INIT_VAR(argument_expr);
		array_init_size(argument_expr, 1);
		add_assoc_stringl_ex(argument_expr, SS("type"), SL("all"), 1);
	} else {
		PHALCON_INIT_NVAR(argument_expr);
		PHALCON_CALL_METHOD_PARAMS_1(argument_expr, this_ptr, "_getexpression", argument);
	}
	
	
	RETURN_CCTOR(argument_expr);
}

/**
 * Resolves a expression in a single call argument
 *
 * @param array $expr
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getFunctionCall){

	zval *expr, *name, *arguments, *function_args = NULL, *argument = NULL;
	zval *argument_expr = NULL, *function_call = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &expr) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(name);
	phalcon_array_fetch_string(&name, expr, SL("name"), PH_NOISY_CC);
	if (phalcon_array_isset_string(expr, SS("arguments"))) {
	
		PHALCON_OBS_VAR(arguments);
		phalcon_array_fetch_string(&arguments, expr, SL("arguments"), PH_NOISY_CC);
		if (phalcon_array_isset_long(arguments, 0)) {
	
			/** 
			 * There are more than one argument
			 */
			PHALCON_INIT_VAR(function_args);
			array_init(function_args);
	
			if (!phalcon_valid_foreach(arguments TSRMLS_CC)) {
				return;
			}
	
			ah0 = Z_ARRVAL_P(arguments);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_FOREACH_VALUE(argument);
	
				PHALCON_INIT_NVAR(argument_expr);
				PHALCON_CALL_METHOD_PARAMS_1(argument_expr, this_ptr, "_getcallargument", argument);
				phalcon_array_append(&function_args, argument_expr, PH_SEPARATE TSRMLS_CC);
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
		} else {
			/** 
			 * There is only one argument
			 */
			PHALCON_INIT_NVAR(argument_expr);
			PHALCON_CALL_METHOD_PARAMS_1(argument_expr, this_ptr, "_getcallargument", arguments);
	
			PHALCON_INIT_NVAR(function_args);
			array_init_size(function_args, 1);
			phalcon_array_append(&function_args, argument_expr, PH_SEPARATE TSRMLS_CC);
		}
	
		PHALCON_INIT_VAR(function_call);
		array_init_size(function_call, 3);
		add_assoc_stringl_ex(function_call, SS("type"), SL("functionCall"), 1);
		phalcon_array_update_string(&function_call, SL("name"), &name, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&function_call, SL("arguments"), &function_args, PH_COPY | PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_INIT_NVAR(function_call);
		array_init_size(function_call, 2);
		add_assoc_stringl_ex(function_call, SS("type"), SL("functionCall"), 1);
		phalcon_array_update_string(&function_call, SL("name"), &name, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	
	RETURN_CTOR(function_call);
}

/**
 * Resolves an expression from its intermediate code into a string
 *
 * @param array $expr
 * @param boolean $quoting
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getExpression){

	zval *expr, *quoting = NULL, *temp_not_quoting, *expr_left;
	zval *left, *expr_right, *right, *expr_type, *expr_return = NULL;
	zval *expr_value = NULL, *value = NULL, *escaped_value, *question_mark;
	zval *double_colon, *placeholder = NULL, *expression_message;
	zval *expression, *expr_domain, *list_items;
	zval *expr_list_item = NULL, *expr_item = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &expr, &quoting) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!quoting) {
		PHALCON_INIT_VAR(quoting);
		ZVAL_BOOL(quoting, 1);
	}
	
	if (phalcon_array_isset_string(expr, SS("type"))) {
	
		PHALCON_INIT_VAR(temp_not_quoting);
		ZVAL_BOOL(temp_not_quoting, 1);
	
		/** 
		 * Resolving left part of the expression if any
		 */
		if (phalcon_array_isset_string(expr, SS("left"))) {
			PHALCON_OBS_VAR(expr_left);
			phalcon_array_fetch_string(&expr_left, expr, SL("left"), PH_NOISY_CC);
	
			PHALCON_INIT_VAR(left);
			PHALCON_CALL_METHOD_PARAMS_2(left, this_ptr, "_getexpression", expr_left, temp_not_quoting);
		}
	
		/** 
		 * Resolving right part of the expression if any
		 */
		if (phalcon_array_isset_string(expr, SS("right"))) {
			PHALCON_OBS_VAR(expr_right);
			phalcon_array_fetch_string(&expr_right, expr, SL("right"), PH_NOISY_CC);
	
			PHALCON_INIT_VAR(right);
			PHALCON_CALL_METHOD_PARAMS_2(right, this_ptr, "_getexpression", expr_right, temp_not_quoting);
		}
	
		/** 
		 * Every node in the AST has a unique integer type
		 */
		PHALCON_OBS_VAR(expr_type);
		phalcon_array_fetch_string(&expr_type, expr, SL("type"), PH_NOISY_CC);
	
		switch (phalcon_get_intval(expr_type)) {
	
			case 60:
				PHALCON_INIT_VAR(expr_return);
				array_init_size(expr_return, 4);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(expr_return, SS("op"), SL("<"), 1);
				phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 61:
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 4);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(expr_return, SS("op"), SL("="), 1);
				phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 62:
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 4);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(expr_return, SS("op"), SL(">"), 1);
				phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 270:
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 4);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(expr_return, SS("op"), SL("<>"), 1);
				phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 271:
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 4);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(expr_return, SS("op"), SL("<="), 1);
				phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 272:
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 4);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(expr_return, SS("op"), SL(">="), 1);
				phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 266:
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 4);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(expr_return, SS("op"), SL("AND"), 1);
				phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 267:
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 4);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(expr_return, SS("op"), SL("OR"), 1);
				phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 355:
				PHALCON_INIT_NVAR(expr_return);
				PHALCON_CALL_METHOD_PARAMS_1(expr_return, this_ptr, "_getqualified", expr);
				break;
	
			case 43:
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 4);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(expr_return, SS("op"), SL("+"), 1);
				phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 45:
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 4);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(expr_return, SS("op"), SL("-"), 1);
				phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 42:
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 4);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(expr_return, SS("op"), SL("*"), 1);
				phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 47:
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 4);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(expr_return, SS("op"), SL("/"), 1);
				phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 37:
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 4);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(expr_return, SS("op"), SL("%"), 1);
				phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 356:
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 2);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("parentheses"), 1);
				phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 367:
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 3);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("unary-op"), 1);
				add_assoc_stringl_ex(expr_return, SS("op"), SL("-"), 1);
				phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 258:
				PHALCON_OBS_VAR(expr_value);
				phalcon_array_fetch_string(&expr_value, expr, SL("value"), PH_NOISY_CC);
	
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 2);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("literal"), 1);
				phalcon_array_update_string(&expr_return, SL("value"), &expr_value, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 259:
				PHALCON_OBS_NVAR(expr_value);
				phalcon_array_fetch_string(&expr_value, expr, SL("value"), PH_NOISY_CC);
	
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 2);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("literal"), 1);
				phalcon_array_update_string(&expr_return, SL("value"), &expr_value, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 260:
				PHALCON_OBS_VAR(value);
				phalcon_array_fetch_string(&value, expr, SL("value"), PH_NOISY_CC);
				if (PHALCON_IS_TRUE(quoting)) {
					PHALCON_INIT_VAR(escaped_value);
					PHALCON_CALL_FUNC_PARAMS_1(escaped_value, "addslashes", value);
	
					PHALCON_INIT_NVAR(expr_value);
					PHALCON_CONCAT_SVS(expr_value, "'", escaped_value, "'");
				} else {
					PHALCON_CPY_WRT(expr_value, value);
				}
	
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 2);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("literal"), 1);
				phalcon_array_update_string(&expr_return, SL("value"), &expr_value, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 273:
				PHALCON_OBS_NVAR(value);
				phalcon_array_fetch_string(&value, expr, SL("value"), PH_NOISY_CC);
	
				PHALCON_INIT_VAR(question_mark);
				ZVAL_STRING(question_mark, "?", 1);
	
				PHALCON_INIT_VAR(double_colon);
				ZVAL_STRING(double_colon, ":", 1);
	
				PHALCON_INIT_VAR(placeholder);
				phalcon_fast_str_replace(placeholder, question_mark, double_colon, value TSRMLS_CC);
	
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 2);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("placeholder"), 1);
				phalcon_array_update_string(&expr_return, SL("value"), &placeholder, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 274:
				PHALCON_OBS_NVAR(value);
				phalcon_array_fetch_string(&value, expr, SL("value"), PH_NOISY_CC);
	
				PHALCON_INIT_NVAR(placeholder);
				PHALCON_CONCAT_SV(placeholder, ":", value);
	
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 2);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("placeholder"), 1);
				phalcon_array_update_string(&expr_return, SL("value"), &placeholder, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 322:
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 2);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("literal"), 1);
				add_assoc_stringl_ex(expr_return, SS("value"), SL("NULL"), 1);
				break;
	
			case 268:
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 4);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(expr_return, SS("op"), SL("LIKE"), 1);
				phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 351:
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 4);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(expr_return, SS("op"), SL("NOT LIKE"), 1);
				phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 33:
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 3);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("unary-op"), 1);
				add_assoc_stringl_ex(expr_return, SS("op"), SL("NOT "), 1);
				phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 365:
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 3);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("unary-op"), 1);
				add_assoc_stringl_ex(expr_return, SS("op"), SL(" IS NULL"), 1);
				phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 366:
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 3);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("unary-op"), 1);
				add_assoc_stringl_ex(expr_return, SS("op"), SL(" IS NOT NULL"), 1);
				phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 315:
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 4);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(expr_return, SS("op"), SL("IN"), 1);
				phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 323:
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 4);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(expr_return, SS("op"), SL("NOT IN"), 1);
				phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 330:
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 3);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("unary-op"), 1);
				add_assoc_stringl_ex(expr_return, SS("op"), SL("DISTINCT "), 1);
				phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 331:
				PHALCON_INIT_NVAR(expr_return);
				array_init_size(expr_return, 4);
				add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(expr_return, SS("op"), SL("BETWEEN"), 1);
				phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
				break;
	
			case 350:
				PHALCON_INIT_NVAR(expr_return);
				PHALCON_CALL_METHOD_PARAMS_1(expr_return, this_ptr, "_getfunctioncall", expr);
				break;
	
			default:
				PHALCON_INIT_VAR(expression_message);
				PHALCON_CONCAT_SV(expression_message, "Unknown expression type ", expr_type);
	
				PHALCON_INIT_VAR(expression);
				object_init_ex(expression, phalcon_mvc_model_exception_ce);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(expression, "__construct", expression_message);
	
				phalcon_throw_exception(expression TSRMLS_CC);
				return;
	
		}
	
		RETURN_CCTOR(expr_return);
	}
	
	/** 
	 * Is a qualified column
	 */
	if (phalcon_array_isset_string(expr, SS("domain"))) {
		PHALCON_INIT_VAR(expr_domain);
		PHALCON_CALL_METHOD_PARAMS_1(expr_domain, this_ptr, "_getqualified", expr);
		RETURN_CCTOR(expr_domain);
	}
	
	/** 
	 * Is the expression doesn't have a type it's a list of nodes
	 */
	if (phalcon_array_isset_long(expr, 0)) {
	
		PHALCON_INIT_VAR(list_items);
		array_init(list_items);
	
		if (!phalcon_valid_foreach(expr TSRMLS_CC)) {
			return;
		}
	
		ah0 = Z_ARRVAL_P(expr);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(expr_list_item);
	
			PHALCON_INIT_NVAR(expr_item);
			PHALCON_CALL_METHOD_PARAMS_1(expr_item, this_ptr, "_getexpression", expr_list_item);
			phalcon_array_append(&list_items, expr_item, PH_SEPARATE TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		PHALCON_INIT_NVAR(expr_return);
		array_init_size(expr_return, 2);
		add_assoc_stringl_ex(expr_return, SS("type"), SL("list"), 1);
		phalcon_array_append(&expr_return, list_items, PH_SEPARATE TSRMLS_CC);
	
		RETURN_CCTOR(expr_return);
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

	zval *column, *sql_columns, *column_type, *models;
	zval *source = NULL, *model_name = NULL, *sql_column = NULL, *sql_aliases;
	zval *column_domain, *exception_message = NULL, *sql_column_alias = NULL;
	zval *sql_aliases_models, *sql_models_aliases;
	zval *best_alias, *is_same_model, *prepared_alias = NULL;
	zval *column_data, *sql_expr_column, *balias;
	zval *sql_alias;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &column) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!phalcon_array_isset_string(column, SS("type"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	
	PHALCON_INIT_VAR(sql_columns);
	array_init(sql_columns);
	
	/** 
	 * Check for select * (all)
	 */
	PHALCON_OBS_VAR(column_type);
	phalcon_array_fetch_string(&column_type, column, SL("type"), PH_NOISY_CC);
	if (phalcon_compare_strict_long(column_type, 352 TSRMLS_CC)) {
	
		PHALCON_OBS_VAR(models);
		phalcon_read_property(&models, this_ptr, SL("_models"), PH_NOISY_CC);
	
		if (!phalcon_valid_foreach(models TSRMLS_CC)) {
			return;
		}
	
		ah0 = Z_ARRVAL_P(models);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_KEY(model_name, ah0, hp0);
			PHALCON_GET_FOREACH_VALUE(source);
	
			PHALCON_INIT_NVAR(sql_column);
			array_init_size(sql_column, 3);
			add_assoc_stringl_ex(sql_column, SS("type"), SL("object"), 1);
			phalcon_array_update_string(&sql_column, SL("model"), &model_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&sql_column, SL("column"), &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&sql_columns, sql_column, PH_SEPARATE TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	
		RETURN_CTOR(sql_columns);
	}
	
	if (!phalcon_array_isset_string(column, SS("column"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	
	/** 
	 * Check if selected column is qualified.*
	 */
	if (phalcon_compare_strict_long(column_type, 353 TSRMLS_CC)) {
	
		PHALCON_OBS_VAR(sql_aliases);
		phalcon_read_property(&sql_aliases, this_ptr, SL("_sqlAliases"), PH_NOISY_CC);
	
		/** 
		 * We only allow the alias.*
		 */
		PHALCON_OBS_VAR(column_domain);
		phalcon_array_fetch_string(&column_domain, column, SL("column"), PH_NOISY_CC);
		if (!phalcon_array_isset(sql_aliases, column_domain)) {
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "Unknown table or alias '", column_domain, "' (2)");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
		}
	
		/** 
		 * Get the SQL alias if any
		 */
		PHALCON_OBS_VAR(source);
		phalcon_array_fetch(&source, sql_aliases, column_domain, PH_NOISY_CC);
		PHALCON_CPY_WRT(sql_column_alias, source);
	
		/** 
		 * Get the real source name
		 */
		PHALCON_OBS_VAR(sql_aliases_models);
		phalcon_read_property(&sql_aliases_models, this_ptr, SL("_sqlAliasesModels"), PH_NOISY_CC);
	
		PHALCON_OBS_VAR(model_name);
		phalcon_array_fetch(&model_name, sql_aliases_models, column_domain, PH_NOISY_CC);
	
		/** 
		 * Get the best alias for the column
		 */
		PHALCON_OBS_VAR(sql_models_aliases);
		phalcon_read_property(&sql_models_aliases, this_ptr, SL("_sqlModelsAliases"), PH_NOISY_CC);
	
		PHALCON_OBS_VAR(best_alias);
		phalcon_array_fetch(&best_alias, sql_models_aliases, model_name, PH_NOISY_CC);
	
		/** 
		 * If the best alias is the model name we lowercase the first letter
		 */
		PHALCON_INIT_VAR(is_same_model);
		is_equal_function(is_same_model, best_alias, model_name TSRMLS_CC);
		if (PHALCON_IS_TRUE(is_same_model)) {
			PHALCON_INIT_VAR(prepared_alias);
			PHALCON_CALL_FUNC_PARAMS_1(prepared_alias, "lcfirst", model_name);
		} else {
			PHALCON_CPY_WRT(prepared_alias, best_alias);
		}
	
		/** 
		 * The sql_column is a complex type returning a complete object
		 */
		PHALCON_INIT_NVAR(sql_column);
		array_init_size(sql_column, 4);
		add_assoc_stringl_ex(sql_column, SS("type"), SL("object"), 1);
		phalcon_array_update_string(&sql_column, SL("model"), &model_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&sql_column, SL("column"), &sql_column_alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&sql_column, SL("balias"), &prepared_alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&sql_columns, sql_column, PH_SEPARATE TSRMLS_CC);
	
		RETURN_CTOR(sql_columns);
	}
	
	/** 
	 * Check for columns qualified and not qualified
	 */
	if (phalcon_compare_strict_long(column_type, 354 TSRMLS_CC)) {
	
		/** 
		 * The sql_column is a scalar type returning a simple string
		 */
		PHALCON_INIT_NVAR(sql_column);
		array_init_size(sql_column, 1);
		add_assoc_stringl_ex(sql_column, SS("type"), SL("scalar"), 1);
	
		PHALCON_OBS_VAR(column_data);
		phalcon_array_fetch_string(&column_data, column, SL("column"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(sql_expr_column);
		PHALCON_CALL_METHOD_PARAMS_1(sql_expr_column, this_ptr, "_getexpression", column_data);
	
		/** 
		 * Create balias and sqlAlias
		 */
		if (phalcon_array_isset_string(sql_expr_column, SS("balias"))) {
			PHALCON_OBS_VAR(balias);
			phalcon_array_fetch_string(&balias, sql_expr_column, SL("balias"), PH_NOISY_CC);
			phalcon_array_update_string(&sql_column, SL("balias"), &balias, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
			PHALCON_INIT_VAR(sql_alias);
			phalcon_fast_strtolower(sql_alias, balias);
			phalcon_array_update_string(&sql_column, SL("sqlAlias"), &sql_alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	
		phalcon_array_update_string(&sql_column, SL("column"), &sql_expr_column, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&sql_columns, sql_column, PH_SEPARATE TSRMLS_CC);
	
		RETURN_CTOR(sql_columns);
	}
	
	PHALCON_INIT_NVAR(exception_message);
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
	zval *model, *source, *schema, *complete_source;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &manager, &qualified_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (phalcon_array_isset_string(qualified_name, SS("name"))) {
	
		PHALCON_OBS_VAR(model_name);
		phalcon_array_fetch_string(&model_name, qualified_name, SL("name"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(model);
		PHALCON_CALL_METHOD_PARAMS_1(model, manager, "load", model_name);
	
		PHALCON_INIT_VAR(source);
		PHALCON_CALL_METHOD(source, model, "getsource");
	
		PHALCON_INIT_VAR(schema);
		PHALCON_CALL_METHOD(schema, model, "getschema");
		if (zend_is_true(schema)) {
			PHALCON_INIT_VAR(complete_source);
			array_init_size(complete_source, 2);
			phalcon_array_append(&complete_source, schema, PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&complete_source, source, PH_SEPARATE TSRMLS_CC);
			RETURN_CTOR(complete_source);
		}
	
	
		RETURN_CCTOR(source);
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
	zval *model_name, *model, *source, *schema, *data;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &manager, &join) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (phalcon_array_isset_string(join, SS("qualified"))) {
	
		PHALCON_OBS_VAR(qualified);
		phalcon_array_fetch_string(&qualified, join, SL("qualified"), PH_NOISY_CC);
	
		PHALCON_OBS_VAR(qualified_type);
		phalcon_array_fetch_string(&qualified_type, qualified, SL("type"), PH_NOISY_CC);
		if (phalcon_compare_strict_long(qualified_type, 355 TSRMLS_CC)) {
			PHALCON_OBS_VAR(model_name);
			phalcon_array_fetch_string(&model_name, qualified, SL("name"), PH_NOISY_CC);
	
			PHALCON_INIT_VAR(model);
			PHALCON_CALL_METHOD_PARAMS_1(model, manager, "load", model_name);
	
			PHALCON_INIT_VAR(source);
			PHALCON_CALL_METHOD(source, model, "getsource");
	
			PHALCON_INIT_VAR(schema);
			PHALCON_CALL_METHOD(schema, model, "getschema");
	
			PHALCON_INIT_VAR(data);
			array_init_size(data, 4);
			phalcon_array_update_string(&data, SL("schema"), &schema, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&data, SL("source"), &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&data, SL("modelName"), &model_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&data, SL("model"), &model, PH_COPY | PH_SEPARATE TSRMLS_CC);
			RETURN_CTOR(data);
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

	zval *join, *type, *join_type = NULL, *exception_message;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &join) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!phalcon_array_isset_string(join, SS("type"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	
	PHALCON_OBS_VAR(type);
	phalcon_array_fetch_string(&type, join, SL("type"), PH_NOISY_CC);
	
	switch (phalcon_get_intval(type)) {
	
		case 360:
			PHALCON_INIT_VAR(join_type);
			ZVAL_STRING(join_type, "INNER", 1);
			break;
	
		case 361:
			PHALCON_INIT_NVAR(join_type);
			ZVAL_STRING(join_type, "LEFT", 1);
			break;
	
		case 362:
			PHALCON_INIT_NVAR(join_type);
			ZVAL_STRING(join_type, "RIGHT", 1);
			break;
	
		case 363:
			PHALCON_INIT_NVAR(join_type);
			ZVAL_STRING(join_type, "CROSS", 1);
			break;
	
		case 364:
			PHALCON_INIT_NVAR(join_type);
			ZVAL_STRING(join_type, "FULL OUTER", 1);
			break;
	
		default:
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SV(exception_message, "Unknown join type ", type);
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
	
	}
	
	RETURN_CTOR(join_type);
}

/**
 * Resolves all the JOINS in a SELECT statement
 *
 * @param array $select
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoins){

	zval *select, *models, *sql_aliases, *sql_aliases_models;
	zval *sql_models_aliases, *sql_aliases_models_instances;
	zval *models_instances, *from_models = NULL, *sql_joins;
	zval *join_models, *join_sources, *join_types;
	zval *manager = NULL, *joins, *select_joins = NULL, *join_item = NULL;
	zval *join_data = NULL, *source = NULL, *schema = NULL, *model = NULL, *model_name = NULL;
	zval *complete_source = NULL, *join_type = NULL, *alias_expr = NULL;
	zval *alias = NULL, *join_pre_condition, *join_expr = NULL;
	zval *pre_condition = NULL, *one, *has_relations = NULL, *join_alias = NULL;
	zval *join_model = NULL, *sql_join_conditions = NULL, *relation = NULL;
	zval *relations = NULL, *number_relations = NULL, *invalid = NULL;
	zval *exception_message = NULL, *fields = NULL, *referenced_fields = NULL;
	zval *model_alias = NULL, *left = NULL, *left_expr = NULL, *right = NULL, *right_expr = NULL;
	zval *sql_join_condition = NULL, *join_source = NULL, *sql_join = NULL;
	HashTable *ah0, *ah1, *ah2, *ah3;
	HashPosition hp0, hp1, hp2, hp3;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &select) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(models);
	phalcon_read_property(&models, this_ptr, SL("_models"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(sql_aliases);
	phalcon_read_property(&sql_aliases, this_ptr, SL("_sqlAliases"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(sql_aliases_models);
	phalcon_read_property(&sql_aliases_models, this_ptr, SL("_sqlAliasesModels"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(sql_models_aliases);
	phalcon_read_property(&sql_models_aliases, this_ptr, SL("_sqlModelsAliases"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(sql_aliases_models_instances);
	phalcon_read_property(&sql_aliases_models_instances, this_ptr, SL("_sqlAliasesModelsInstances"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(models_instances);
	phalcon_read_property(&models_instances, this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
	PHALCON_CPY_WRT(from_models, models);
	
	PHALCON_INIT_VAR(sql_joins);
	array_init(sql_joins);
	
	PHALCON_INIT_VAR(join_models);
	array_init(join_models);
	
	PHALCON_INIT_VAR(join_sources);
	array_init(join_sources);
	
	PHALCON_INIT_VAR(join_types);
	array_init(join_types);
	
	PHALCON_OBS_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(joins);
	phalcon_array_fetch_string(&joins, select, SL("joins"), PH_NOISY_CC);
	if (!phalcon_array_isset_long(joins, 0)) {
		PHALCON_INIT_VAR(select_joins);
		array_init_size(select_joins, 1);
		phalcon_array_append(&select_joins, joins, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(select_joins, joins);
	}
	
	
	if (!phalcon_valid_foreach(select_joins TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(select_joins);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(join_item);
	
		PHALCON_INIT_NVAR(join_data);
		PHALCON_CALL_METHOD_PARAMS_2(join_data, this_ptr, "_getjoin", manager, join_item);
	
		PHALCON_OBS_NVAR(source);
		phalcon_array_fetch_string(&source, join_data, SL("source"), PH_NOISY_CC);
	
		PHALCON_OBS_NVAR(schema);
		phalcon_array_fetch_string(&schema, join_data, SL("schema"), PH_NOISY_CC);
	
		PHALCON_OBS_NVAR(model);
		phalcon_array_fetch_string(&model, join_data, SL("model"), PH_NOISY_CC);
	
		PHALCON_OBS_NVAR(model_name);
		phalcon_array_fetch_string(&model_name, join_data, SL("modelName"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(complete_source);
		array_init_size(complete_source, 2);
		phalcon_array_append(&complete_source, source, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&complete_source, schema, PH_SEPARATE TSRMLS_CC);
	
		/** 
		 * Check join alias
		 */
		PHALCON_INIT_NVAR(join_type);
		PHALCON_CALL_METHOD_PARAMS_1(join_type, this_ptr, "_getjointype", join_item);
		phalcon_array_update_zval(&join_types, model_name, &join_type, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
		/** 
		 * Process join alias
		 */
		if (phalcon_array_isset_string(join_item, SS("alias"))) {
			PHALCON_OBS_NVAR(alias_expr);
			phalcon_array_fetch_string(&alias_expr, join_item, SL("alias"), PH_NOISY_CC);
	
			PHALCON_OBS_NVAR(alias);
			phalcon_array_fetch_string(&alias, alias_expr, SL("name"), PH_NOISY_CC);
			phalcon_array_append(&complete_source, alias, PH_SEPARATE TSRMLS_CC);
	
			/** 
			 * Update alias => alias
			 */
			phalcon_array_update_zval(&sql_aliases, alias, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
			/** 
			 * Update model => alias
			 */
			phalcon_array_update_zval(&join_models, model_name, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
			/** 
			 * Update model => alias
			 */
			phalcon_array_update_zval(&sql_models_aliases, model_name, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
			/** 
			 * Update model => model
			 */
			phalcon_array_update_zval(&sql_aliases_models, alias, &model_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
			/** 
			 * Update alias => model
			 */
			phalcon_array_update_zval(&sql_aliases_models_instances, alias, &model, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
			/** 
			 * Update model => alias
			 */
			phalcon_array_update_zval(&models, model_name, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
		} else {
			/** 
			 * Update model => source
			 */
			phalcon_array_update_zval(&sql_aliases, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
			/** 
			 * Update model => source
			 */
			phalcon_array_update_zval(&join_models, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
			/** 
			 * Update model => model
			 */
			phalcon_array_update_zval(&sql_models_aliases, model_name, &model_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
			/** 
			 * Update model => model
			 */
			phalcon_array_update_zval(&sql_aliases_models, model_name, &model_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
			/** 
			 * Update model => model instance
			 */
			phalcon_array_update_zval(&sql_aliases_models_instances, model_name, &model, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
			/** 
			 * Update model => source
			 */
			phalcon_array_update_zval(&models, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	
		phalcon_array_update_zval(&models_instances, model_name, &model, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_zval(&join_sources, model_name, &complete_source, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * Update temporary properties
	 */
	phalcon_update_property_zval(this_ptr, SL("_models"), models TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_sqlAliases"), sql_aliases TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_sqlAliasesModels"), sql_aliases_models TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_sqlModelsAliases"), sql_models_aliases TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_sqlAliasesModelsInstances"), sql_aliases_models_instances TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_modelsInstances"), models_instances TSRMLS_CC);
	
	/** 
	 * Check if the joins already have conditions
	 */
	PHALCON_INIT_VAR(join_pre_condition);
	array_init(join_pre_condition);
	
	if (!phalcon_valid_foreach(select_joins TSRMLS_CC)) {
		return;
	}
	
	ah1 = Z_ARRVAL_P(select_joins);
	zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	
	while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(join_item);
	
		/** 
		 * Check for predefined conditions
		 */
		if (phalcon_array_isset_string(join_item, SS("conditions"))) {
			PHALCON_OBS_NVAR(join_expr);
			phalcon_array_fetch_string(&join_expr, join_item, SL("conditions"), PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(pre_condition);
			PHALCON_CALL_METHOD_PARAMS_1(pre_condition, this_ptr, "_getexpression", join_expr);
			phalcon_array_update_zval(&join_pre_condition, model_name, &pre_condition, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	
		zend_hash_move_forward_ex(ah1, &hp1);
	}
	
	/** 
	 * Create join relationships dynamically
	 */
	PHALCON_INIT_VAR(one);
	ZVAL_LONG(one, 1);
	
	PHALCON_OBS_NVAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	
	if (!phalcon_valid_foreach(from_models TSRMLS_CC)) {
		return;
	}
	
	ah2 = Z_ARRVAL_P(from_models);
	zend_hash_internal_pointer_reset_ex(ah2, &hp2);
	
	while (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) == SUCCESS) {
	
		PHALCON_GET_FOREACH_KEY(model_name, ah2, hp2);
		PHALCON_GET_FOREACH_VALUE(source);
	
		PHALCON_INIT_NVAR(has_relations);
		ZVAL_BOOL(has_relations, 0);
	
		if (!phalcon_valid_foreach(join_models TSRMLS_CC)) {
			return;
		}
	
		ah3 = Z_ARRVAL_P(join_models);
		zend_hash_internal_pointer_reset_ex(ah3, &hp3);
	
		while (zend_hash_get_current_data_ex(ah3, (void**) &hd, &hp3) == SUCCESS) {
	
			PHALCON_GET_FOREACH_KEY(join_model, ah3, hp3);
			PHALCON_GET_FOREACH_VALUE(join_alias);
	
			PHALCON_INIT_NVAR(sql_join_conditions);
			array_init(sql_join_conditions);
			if (!phalcon_array_isset(join_pre_condition, join_model)) {
	
				/** 
				 * Check if the joined model is an alias
				 */
				PHALCON_INIT_NVAR(relation);
				PHALCON_CALL_METHOD_PARAMS_2(relation, manager, "getrelationbyalias", model_name, join_model);
				if (PHALCON_IS_FALSE(relation)) {
	
					/** 
					 * Check for relations between models
					 */
					PHALCON_INIT_NVAR(relations);
					PHALCON_CALL_METHOD_PARAMS_2(relations, manager, "getrelations", model_name, join_model);
					if (Z_TYPE_P(relations) == IS_ARRAY) { 
	
						/** 
						 * More than one relation must throw an exception
						 */
						PHALCON_INIT_NVAR(number_relations);
						phalcon_fast_count(number_relations, relations TSRMLS_CC);
	
						PHALCON_INIT_NVAR(invalid);
						is_not_equal_function(invalid, number_relations, one TSRMLS_CC);
						if (PHALCON_IS_TRUE(invalid)) {
							PHALCON_INIT_NVAR(exception_message);
							PHALCON_CONCAT_SVSVS(exception_message, "There is more than one relation between '", model_name, "' and '", join_model, "\", the join must be done using an alias");
							PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
							return;
						}
	
						/** 
						 * Get the first relationship
						 */
						PHALCON_OBS_NVAR(relation);
						phalcon_array_fetch_long(&relation, relations, 0, PH_NOISY_CC);
					}
				}
	
				/** 
				 * Valid relations are objects
				 */
				if (Z_TYPE_P(relation) == IS_OBJECT) {
	
					/** 
					 * TODO. Create joins with compound keys
					 */
					PHALCON_INIT_NVAR(fields);
					PHALCON_CALL_METHOD(fields, relation, "getfields");
					if (Z_TYPE_P(fields) == IS_ARRAY) { 
						PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Not implemented yet");
						return;
					}
	
					PHALCON_INIT_NVAR(referenced_fields);
					PHALCON_CALL_METHOD(referenced_fields, relation, "getreferencedfields");
	
					/** 
					 * Get the related model alias of the left part
					 */
					PHALCON_OBS_NVAR(model_alias);
					phalcon_array_fetch(&model_alias, sql_models_aliases, model_name, PH_NOISY_CC);
	
					/** 
					 * Create the left part of the expression
					 */
					PHALCON_INIT_NVAR(left);
					array_init_size(left, 3);
					add_assoc_long_ex(left, SS("type"), 355);
					phalcon_array_update_string(&left, SL("domain"), &model_alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
					phalcon_array_update_string(&left, SL("name"), &fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
					PHALCON_INIT_NVAR(left_expr);
					PHALCON_CALL_METHOD_PARAMS_1(left_expr, this_ptr, "_getqualified", left);
	
					/** 
					 * Get the related model alias of the right part
					 */
					PHALCON_OBS_NVAR(join_alias);
					phalcon_array_fetch(&join_alias, sql_models_aliases, join_model, PH_NOISY_CC);
	
					/** 
					 * Create the right part of the expression
					 */
					PHALCON_INIT_NVAR(right);
					array_init_size(right, 3);
					add_assoc_stringl_ex(right, SS("type"), SL("qualified"), 1);
					phalcon_array_update_string(&right, SL("domain"), &join_alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
					phalcon_array_update_string(&right, SL("name"), &referenced_fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
					PHALCON_INIT_NVAR(right_expr);
					PHALCON_CALL_METHOD_PARAMS_1(right_expr, this_ptr, "_getqualified", right);
	
					/** 
					 * Create a binary operation for the join conditions
					 */
					PHALCON_INIT_NVAR(sql_join_condition);
					array_init_size(sql_join_condition, 4);
					add_assoc_stringl_ex(sql_join_condition, SS("type"), SL("binary-op"), 1);
					add_assoc_stringl_ex(sql_join_condition, SS("op"), SL("="), 1);
					phalcon_array_update_string(&sql_join_condition, SL("left"), &left_expr, PH_COPY | PH_SEPARATE TSRMLS_CC);
					phalcon_array_update_string(&sql_join_condition, SL("right"), &right_expr, PH_COPY | PH_SEPARATE TSRMLS_CC);
					phalcon_array_append(&sql_join_conditions, sql_join_condition, PH_SEPARATE TSRMLS_CC);
				}
			} else {
				PHALCON_OBS_NVAR(pre_condition);
				phalcon_array_fetch(&pre_condition, join_pre_condition, join_model, PH_NOISY_CC);
				phalcon_array_append(&sql_join_conditions, pre_condition, PH_SEPARATE TSRMLS_CC);
			}
	
			PHALCON_OBS_NVAR(join_type);
			phalcon_array_fetch(&join_type, join_types, join_model, PH_NOISY_CC);
	
			PHALCON_OBS_NVAR(join_source);
			phalcon_array_fetch(&join_source, join_sources, join_model, PH_NOISY_CC);
	
			/** 
			 * Final join representation
			 */
			PHALCON_INIT_NVAR(sql_join);
			array_init_size(sql_join, 3);
			phalcon_array_update_string(&sql_join, SL("type"), &join_type, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&sql_join, SL("source"), &join_source, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&sql_join, SL("conditions"), &sql_join_conditions, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&sql_joins, sql_join, PH_SEPARATE TSRMLS_CC);
	
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

	zval *order, *order_columns = NULL, *order_parts, *order_item = NULL;
	zval *order_column = NULL, *order_part_expr = NULL, *order_sort = NULL;
	zval *order_part_sort = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &order) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!phalcon_array_isset_long(order, 0)) {
		PHALCON_INIT_VAR(order_columns);
		array_init_size(order_columns, 1);
		phalcon_array_append(&order_columns, order, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(order_columns, order);
	}
	
	PHALCON_INIT_VAR(order_parts);
	array_init(order_parts);
	
	if (!phalcon_valid_foreach(order_columns TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(order_columns);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(order_item);
	
		PHALCON_OBS_NVAR(order_column);
		phalcon_array_fetch_string(&order_column, order_item, SL("column"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(order_part_expr);
		PHALCON_CALL_METHOD_PARAMS_1(order_part_expr, this_ptr, "_getexpression", order_column);
	
		/** 
		 * Check if the order has a predefined ordering mode
		 */
		if (phalcon_array_isset_string(order_item, SS("sort"))) {
	
			PHALCON_OBS_NVAR(order_sort);
			phalcon_array_fetch_string(&order_sort, order_item, SL("sort"), PH_NOISY_CC);
			if (phalcon_compare_strict_long(order_sort, 327 TSRMLS_CC)) {
				PHALCON_INIT_NVAR(order_part_sort);
				array_init_size(order_part_sort, 2);
				phalcon_array_append(&order_part_sort, order_part_expr, PH_SEPARATE TSRMLS_CC);
				add_next_index_stringl(order_part_sort, SL("ASC"), 1);
			} else {
				PHALCON_INIT_NVAR(order_part_sort);
				array_init_size(order_part_sort, 2);
				phalcon_array_append(&order_part_sort, order_part_expr, PH_SEPARATE TSRMLS_CC);
				add_next_index_stringl(order_part_sort, SL("DESC"), 1);
			}
		} else {
			PHALCON_INIT_NVAR(order_part_sort);
			array_init_size(order_part_sort, 1);
			phalcon_array_append(&order_part_sort, order_part_expr, PH_SEPARATE TSRMLS_CC);
		}
	
		phalcon_array_append(&order_parts, order_part_sort, PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	
	RETURN_CTOR(order_parts);
}

/**
 * Returns a processed group clause for a SELECT statement
 *
 * @param array $group
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getGroupClause){

	zval *group, *group_parts = NULL, *group_item = NULL, *group_part_expr = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &group) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (phalcon_array_isset_long(group, 0)) {
	
		/** 
		 * The select is gruped by several columns
		 */
		PHALCON_INIT_VAR(group_parts);
		array_init(group_parts);
	
		if (!phalcon_valid_foreach(group TSRMLS_CC)) {
			return;
		}
	
		ah0 = Z_ARRVAL_P(group);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(group_item);
	
			PHALCON_INIT_NVAR(group_part_expr);
			PHALCON_CALL_METHOD_PARAMS_1(group_part_expr, this_ptr, "_getexpression", group_item);
			phalcon_array_append(&group_parts, group_part_expr, PH_SEPARATE TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	} else {
		PHALCON_INIT_NVAR(group_part_expr);
		PHALCON_CALL_METHOD_PARAMS_1(group_part_expr, this_ptr, "_getexpression", group);
	
		PHALCON_INIT_NVAR(group_parts);
		array_init_size(group_parts, 1);
		phalcon_array_append(&group_parts, group_part_expr, PH_SEPARATE TSRMLS_CC);
	}
	
	RETURN_CTOR(group_parts);
}

/**
 * Analyzes a SELECT intermediate code and produces an array to be executed later
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareSelect){

	zval *ast, *select, *sql_models, *sql_tables, *sql_aliases;
	zval *sql_columns, *sql_aliases_models, *sql_models_aliases;
	zval *sql_aliases_models_instances, *models;
	zval *models_instances, *tables, *selected_models = NULL;
	zval *manager, *meta_data, *selected_model = NULL, *qualified_name = NULL;
	zval *model_name = NULL, *model = NULL, *schema = NULL, *source = NULL, *complete_source = NULL;
	zval *alias = NULL, *exception_message = NULL, *sql_joins = NULL;
	zval *columns, *select_columns = NULL, *position, *sql_column_aliases;
	zval *column = NULL, *sql_column_group = NULL, *sql_column = NULL;
	zval *lower_alias = NULL, *type = NULL, *sql_select, *where, *where_expr;
	zval *group_by, *sql_group, *having, *having_expr;
	zval *order, *sql_order, *limit;
	zval *r0 = NULL;
	HashTable *ah0, *ah1, *ah2;
	HashPosition hp0, hp1, hp2;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(ast);
	phalcon_read_property(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(select);
	phalcon_array_fetch_string(&select, ast, SL("select"), PH_NOISY_CC);
	if (!phalcon_array_isset_string(select, SS("tables"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	
	if (!phalcon_array_isset_string(select, SS("columns"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	
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
	
	PHALCON_OBS_VAR(tables);
	phalcon_array_fetch_string(&tables, select, SL("tables"), PH_NOISY_CC);
	if (!phalcon_array_isset_long(tables, 0)) {
		PHALCON_INIT_VAR(selected_models);
		array_init_size(selected_models, 1);
		phalcon_array_append(&selected_models, tables, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(selected_models, tables);
	}
	
	PHALCON_OBS_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(meta_data);
	phalcon_read_property(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
	
	/** 
	 * Processing selected columns
	 */
	
	if (!phalcon_valid_foreach(selected_models TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(selected_models);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(selected_model);
	
		PHALCON_OBS_NVAR(qualified_name);
		phalcon_array_fetch_string(&qualified_name, selected_model, SL("qualifiedName"), PH_NOISY_CC);
	
		PHALCON_OBS_NVAR(model_name);
		phalcon_array_fetch_string(&model_name, qualified_name, SL("name"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(model);
		PHALCON_CALL_METHOD_PARAMS_1(model, manager, "load", model_name);
	
		/** 
		 * Define a complete schema/source
		 */
		PHALCON_INIT_NVAR(schema);
		PHALCON_CALL_METHOD(schema, model, "getschema");
	
		PHALCON_INIT_NVAR(source);
		PHALCON_CALL_METHOD(source, model, "getsource");
		if (zend_is_true(schema)) {
			PHALCON_INIT_NVAR(complete_source);
			array_init_size(complete_source, 2);
			phalcon_array_append(&complete_source, source, PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&complete_source, schema, PH_SEPARATE TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(complete_source, source);
		}
	
		/** 
		 * If an alias is defined for a model the model cannot be referenced in the column
		 * list
		 */
		if (phalcon_array_isset_string(selected_model, SS("alias"))) {
	
			PHALCON_OBS_NVAR(alias);
			phalcon_array_fetch_string(&alias, selected_model, SL("alias"), PH_NOISY_CC);
			if (phalcon_array_isset(sql_aliases, alias)) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Alias \"", alias, " is already used");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
	
			phalcon_array_update_zval(&sql_aliases, alias, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&sql_aliases_models, alias, &model_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&sql_models_aliases, model_name, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&sql_aliases_models_instances, alias, &model, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
			/** 
			 * Append or convert complete source to an array
			 */
			if (Z_TYPE_P(complete_source) == IS_ARRAY) { 
				phalcon_array_append(&complete_source, alias, PH_SEPARATE TSRMLS_CC);
			} else {
				PHALCON_INIT_NVAR(complete_source);
				array_init_size(complete_source, 3);
				phalcon_array_append(&complete_source, source, PH_SEPARATE TSRMLS_CC);
				add_next_index_null(complete_source);
				phalcon_array_append(&complete_source, alias, PH_SEPARATE TSRMLS_CC);
			}
	
			phalcon_array_update_zval(&models, model_name, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_update_zval(&sql_aliases, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&sql_aliases_models, model_name, &model_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&sql_models_aliases, model_name, &model_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&sql_aliases_models_instances, model_name, &model, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&models, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	
		phalcon_array_append(&sql_models, model_name, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&sql_tables, complete_source, PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_zval(&models_instances, model_name, &model, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * Assign Models/Tables information
	 */
	phalcon_update_property_zval(this_ptr, SL("_models"), models TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_modelsInstances"), models_instances TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_sqlAliases"), sql_aliases TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_sqlAliasesModels"), sql_aliases_models TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_sqlModelsAliases"), sql_models_aliases TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_sqlAliasesModelsInstances"), sql_aliases_models_instances TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_modelsInstances"), models_instances TSRMLS_CC);
	
	/** 
	 * Processing joins
	 */
	if (phalcon_array_isset_string(select, SS("joins"))) {
	
		PHALCON_OBS_VAR(r0);
		phalcon_array_fetch_string(&r0, select, SL("joins"), PH_NOISY_CC);
		if (phalcon_fast_count_ev(r0 TSRMLS_CC)) {
			PHALCON_INIT_VAR(sql_joins);
			PHALCON_CALL_METHOD_PARAMS_1(sql_joins, this_ptr, "_getjoins", select);
		} else {
			PHALCON_INIT_NVAR(sql_joins);
			array_init(sql_joins);
		}
	} else {
		PHALCON_INIT_NVAR(sql_joins);
		array_init(sql_joins);
	}
	
	/** 
	 * Processing selected columns
	 */
	PHALCON_OBS_VAR(columns);
	phalcon_array_fetch_string(&columns, select, SL("columns"), PH_NOISY_CC);
	if (!phalcon_array_isset_long(columns, 0)) {
		PHALCON_INIT_VAR(select_columns);
		array_init_size(select_columns, 1);
		phalcon_array_append(&select_columns, columns, PH_SEPARATE TSRMLS_CC);
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
	
	if (!phalcon_valid_foreach(select_columns TSRMLS_CC)) {
		return;
	}
	
	ah1 = Z_ARRVAL_P(select_columns);
	zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	
	while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(column);
	
		PHALCON_INIT_NVAR(sql_column_group);
		PHALCON_CALL_METHOD_PARAMS_1(sql_column_group, this_ptr, "_getselectcolumn", column);
	
		if (!phalcon_valid_foreach(sql_column_group TSRMLS_CC)) {
			return;
		}
	
		ah2 = Z_ARRVAL_P(sql_column_group);
		zend_hash_internal_pointer_reset_ex(ah2, &hp2);
	
		while (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(sql_column);
	
			/** 
			 * If 'alias' is set, the user had defined a alias for the column
			 */
			if (phalcon_array_isset_string(column, SS("alias"))) {
				PHALCON_OBS_NVAR(alias);
				phalcon_array_fetch_string(&alias, column, SL("alias"), PH_NOISY_CC);
	
				/** 
				 * The best alias is the one provided by the user
				 */
				phalcon_array_update_string(&sql_column, SL("balias"), &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
				/** 
				 * Calculate a lowercased version of the alias
				 */
				PHALCON_INIT_NVAR(lower_alias);
				phalcon_fast_strtolower(lower_alias, alias);
				phalcon_array_update_string(&sql_column, SL("sqlAlias"), &lower_alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_zval(&sql_columns, alias, &sql_column, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_zval_bool(&sql_column_aliases, alias, 1, PH_SEPARATE TSRMLS_CC);
			} else {
				/** 
				 * 'balias' is the best alias selected for the column
				 */
				if (phalcon_array_isset_string(sql_column, SS("balias"))) {
					PHALCON_OBS_NVAR(alias);
					phalcon_array_fetch_string(&alias, sql_column, SL("balias"), PH_NOISY_CC);
					phalcon_array_update_zval(&sql_columns, alias, &sql_column, PH_COPY | PH_SEPARATE TSRMLS_CC);
				} else {
					PHALCON_OBS_NVAR(type);
					phalcon_array_fetch_string(&type, sql_column, SL("type"), PH_NOISY_CC);
					if (PHALCON_COMPARE_STRING(type, "scalar")) {
						PHALCON_INIT_NVAR(alias);
						PHALCON_CONCAT_SV(alias, "_", position);
						phalcon_array_update_zval(&sql_columns, alias, &sql_column, PH_COPY | PH_SEPARATE TSRMLS_CC);
					} else {
						phalcon_array_append(&sql_columns, sql_column, PH_SEPARATE TSRMLS_CC);
					}
				}
			}
			PHALCON_SEPARATE(position);
			increment_function(position);
	
			zend_hash_move_forward_ex(ah2, &hp2);
		}
	
	
		zend_hash_move_forward_ex(ah1, &hp1);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_sqlColumnAliases"), sql_column_aliases TSRMLS_CC);
	
	/** 
	 * sql_select is the final prepared SELECT
	 */
	PHALCON_INIT_VAR(sql_select);
	array_init_size(sql_select, 3);
	phalcon_array_update_string(&sql_select, SL("models"), &sql_models, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_select, SL("tables"), &sql_tables, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_select, SL("columns"), &sql_columns, PH_COPY | PH_SEPARATE TSRMLS_CC);
	if (phalcon_fast_count_ev(sql_joins TSRMLS_CC)) {
		phalcon_array_update_string(&sql_select, SL("joins"), &sql_joins, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	/** 
	 * Process WHERE clause if any
	 */
	if (phalcon_array_isset_string(ast, SS("where"))) {
		PHALCON_OBS_VAR(where);
		phalcon_array_fetch_string(&where, ast, SL("where"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(where_expr);
		PHALCON_CALL_METHOD_PARAMS_1(where_expr, this_ptr, "_getexpression", where);
		phalcon_array_update_string(&sql_select, SL("where"), &where_expr, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	/** 
	 * Process GROUP BY clause if any
	 */
	if (phalcon_array_isset_string(ast, SS("groupBy"))) {
		PHALCON_OBS_VAR(group_by);
		phalcon_array_fetch_string(&group_by, ast, SL("groupBy"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(sql_group);
		PHALCON_CALL_METHOD_PARAMS_1(sql_group, this_ptr, "_getgroupclause", group_by);
		phalcon_array_update_string(&sql_select, SL("group"), &sql_group, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	/** 
	 * Process HAVING clause if any
	 */
	if (phalcon_array_isset_string(ast, SS("having"))) {
		PHALCON_OBS_VAR(having);
		phalcon_array_fetch_string(&having, ast, SL("having"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(having_expr);
		PHALCON_CALL_METHOD_PARAMS_1(having_expr, this_ptr, "_getexpression", having);
		phalcon_array_update_string(&sql_select, SL("having"), &having_expr, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	/** 
	 * Process ORDER BY clause if any
	 */
	if (phalcon_array_isset_string(ast, SS("orderBy"))) {
		PHALCON_OBS_VAR(order);
		phalcon_array_fetch_string(&order, ast, SL("orderBy"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(sql_order);
		PHALCON_CALL_METHOD_PARAMS_1(sql_order, this_ptr, "_getorderclause", order);
		phalcon_array_update_string(&sql_select, SL("order"), &sql_order, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	/** 
	 * Process LIMIT clause if any
	 */
	if (phalcon_array_isset_string(ast, SS("limit"))) {
		PHALCON_OBS_VAR(limit);
		phalcon_array_fetch_string(&limit, ast, SL("limit"), PH_NOISY_CC);
		phalcon_array_update_string(&sql_select, SL("limit"), &limit, PH_COPY | PH_SEPARATE TSRMLS_CC);
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
	zval *model, *source = NULL, *schema, *sql_aliases, *not_quoting;
	zval *expr_values, *values, *expr_value = NULL, *expr_insert = NULL;
	zval *expr_type = NULL, *value = NULL, *sql_insert, *meta_data;
	zval *sql_fields, *fields, *field = NULL, *name = NULL, *has_attribute = NULL;
	zval *exception_message = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(ast);
	phalcon_read_property(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	if (!phalcon_array_isset_string(ast, SS("qualifiedName"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted INSERT AST");
		return;
	}
	
	if (!phalcon_array_isset_string(ast, SS("values"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted INSERT AST");
		return;
	}
	
	PHALCON_OBS_VAR(qualified_name);
	phalcon_array_fetch_string(&qualified_name, ast, SL("qualifiedName"), PH_NOISY_CC);
	
	/** 
	 * Check if the related model exists
	 */
	if (!phalcon_array_isset_string(qualified_name, SS("name"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted INSERT AST");
		return;
	}
	
	PHALCON_OBS_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(model_name);
	phalcon_array_fetch_string(&model_name, qualified_name, SL("name"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(model);
	PHALCON_CALL_METHOD_PARAMS_1(model, manager, "load", model_name);
	
	PHALCON_INIT_VAR(source);
	PHALCON_CALL_METHOD(source, model, "getsource");
	
	PHALCON_INIT_VAR(schema);
	PHALCON_CALL_METHOD(schema, model, "getschema");
	if (zend_is_true(schema)) {
		PHALCON_INIT_NVAR(source);
		array_init_size(source, 2);
		phalcon_array_append(&source, schema, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&source, source, PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(sql_aliases);
	array_init(sql_aliases);
	
	PHALCON_INIT_VAR(not_quoting);
	ZVAL_BOOL(not_quoting, 0);
	
	PHALCON_INIT_VAR(expr_values);
	array_init(expr_values);
	
	PHALCON_OBS_VAR(values);
	phalcon_array_fetch_string(&values, ast, SL("values"), PH_NOISY_CC);
	
	if (!phalcon_valid_foreach(values TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(values);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(expr_value);
	
		PHALCON_INIT_NVAR(expr_insert);
		PHALCON_CALL_METHOD_PARAMS_2(expr_insert, this_ptr, "_getexpression", expr_value, not_quoting);
	
		PHALCON_OBS_NVAR(expr_type);
		phalcon_array_fetch_string(&expr_type, expr_value, SL("type"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(value);
		array_init_size(value, 2);
		phalcon_array_update_string(&value, SL("type"), &expr_type, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&value, SL("value"), &expr_insert, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&expr_values, value, PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	PHALCON_INIT_VAR(sql_insert);
	array_init(sql_insert);
	phalcon_array_update_string(&sql_insert, SL("model"), &model_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_insert, SL("table"), &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	PHALCON_OBS_VAR(meta_data);
	phalcon_read_property(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
	if (phalcon_array_isset_string(ast, SS("fields"))) {
	
		PHALCON_INIT_VAR(sql_fields);
		array_init(sql_fields);
	
		PHALCON_OBS_VAR(fields);
		phalcon_array_fetch_string(&fields, ast, SL("fields"), PH_NOISY_CC);
	
		if (!phalcon_valid_foreach(fields TSRMLS_CC)) {
			return;
		}
	
		ah1 = Z_ARRVAL_P(fields);
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	
		while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(field);
	
			PHALCON_OBS_NVAR(name);
			phalcon_array_fetch_string(&name, field, SL("name"), PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(has_attribute);
			PHALCON_CALL_METHOD_PARAMS_2(has_attribute, meta_data, "hasattribute", model, name);
			if (!zend_is_true(has_attribute)) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVSVS(exception_message, "The model '", model_name, "' doesn't have the attribute '", name, "'");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
	
			phalcon_array_append(&sql_fields, name, PH_SEPARATE TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah1, &hp1);
		}
	
		phalcon_array_update_string(&sql_insert, SL("fields"), &sql_fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	phalcon_array_update_string(&sql_insert, SL("values"), &expr_values, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
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
	zval *model_name = NULL, *model = NULL, *source = NULL, *schema = NULL, *complete_source = NULL;
	zval *alias = NULL, *sql_fields, *sql_values, *values;
	zval *update_values = NULL, *not_quoting = NULL, *update_value = NULL;
	zval *column = NULL, *sql_column = NULL, *expr_column = NULL, *expr_value = NULL;
	zval *type = NULL, *value = NULL, *sql_update, *where, *where_expr;
	zval *limit;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(ast);
	phalcon_read_property(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	if (!phalcon_array_isset_string(ast, SS("update"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted UPDATE AST");
		return;
	}
	
	PHALCON_OBS_VAR(update);
	phalcon_array_fetch_string(&update, ast, SL("update"), PH_NOISY_CC);
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
	phalcon_array_fetch_string(&tables, update, SL("tables"), PH_NOISY_CC);
	if (!phalcon_array_isset_long(tables, 0)) {
		PHALCON_INIT_VAR(update_tables);
		array_init_size(update_tables, 1);
		phalcon_array_append(&update_tables, tables, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(update_tables, tables);
	}
	
	PHALCON_OBS_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	
	if (!phalcon_valid_foreach(update_tables TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(update_tables);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(table);
	
		PHALCON_OBS_NVAR(qualified_name);
		phalcon_array_fetch_string(&qualified_name, table, SL("qualifiedName"), PH_NOISY_CC);
	
		PHALCON_OBS_NVAR(model_name);
		phalcon_array_fetch_string(&model_name, qualified_name, SL("name"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(model);
		PHALCON_CALL_METHOD_PARAMS_1(model, manager, "load", model_name);
	
		PHALCON_INIT_NVAR(source);
		PHALCON_CALL_METHOD(source, model, "getsource");
	
		PHALCON_INIT_NVAR(schema);
		PHALCON_CALL_METHOD(schema, model, "getschema");
		if (zend_is_true(schema)) {
			PHALCON_INIT_NVAR(complete_source);
			array_init_size(complete_source, 2);
			phalcon_array_append(&complete_source, source, PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&complete_source, schema, PH_SEPARATE TSRMLS_CC);
		} else {
			PHALCON_INIT_NVAR(complete_source);
			array_init_size(complete_source, 2);
			phalcon_array_append(&complete_source, source, PH_SEPARATE TSRMLS_CC);
			add_next_index_null(complete_source);
		}
	
		if (phalcon_array_isset_string(table, SS("alias"))) {
			PHALCON_OBS_NVAR(alias);
			phalcon_array_fetch_string(&alias, table, SL("alias"), PH_NOISY_CC);
			phalcon_array_update_zval(&sql_aliases, alias, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&complete_source, alias, PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&sql_tables, complete_source, PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&sql_aliases_models_instances, alias, &model, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&models, alias, &model_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_update_zval(&sql_aliases, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&sql_aliases_models_instances, model_name, &model, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&sql_tables, source, PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&models, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	
		phalcon_array_append(&sql_models, model_name, PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_zval(&models_instances, model_name, &model, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * Update the models/alias/sources in the object
	 */
	phalcon_update_property_zval(this_ptr, SL("_models"), models TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_modelsInstances"), models_instances TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_sqlAliases"), sql_aliases TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_sqlAliasesModelsInstances"), sql_aliases_models_instances TSRMLS_CC);
	
	PHALCON_INIT_VAR(sql_fields);
	array_init(sql_fields);
	
	PHALCON_INIT_VAR(sql_values);
	array_init(sql_values);
	
	PHALCON_OBS_VAR(values);
	phalcon_array_fetch_string(&values, update, SL("values"), PH_NOISY_CC);
	if (!phalcon_array_isset_long(values, 0)) {
		PHALCON_INIT_VAR(update_values);
		array_init_size(update_values, 1);
		phalcon_array_append(&update_values, values, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(update_values, values);
	}
	
	PHALCON_INIT_VAR(not_quoting);
	ZVAL_BOOL(not_quoting, 0);
	
	if (!phalcon_valid_foreach(update_values TSRMLS_CC)) {
		return;
	}
	
	ah1 = Z_ARRVAL_P(update_values);
	zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	
	while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(update_value);
	
		PHALCON_OBS_NVAR(column);
		phalcon_array_fetch_string(&column, update_value, SL("column"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(sql_column);
		PHALCON_CALL_METHOD_PARAMS_2(sql_column, this_ptr, "_getexpression", column, not_quoting);
		phalcon_array_append(&sql_fields, sql_column, PH_SEPARATE TSRMLS_CC);
	
		PHALCON_OBS_NVAR(expr_column);
		phalcon_array_fetch_string(&expr_column, update_value, SL("expr"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(expr_value);
		PHALCON_CALL_METHOD_PARAMS_2(expr_value, this_ptr, "_getexpression", expr_column, not_quoting);
	
		PHALCON_OBS_NVAR(type);
		phalcon_array_fetch_string(&type, expr_column, SL("type"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(value);
		array_init_size(value, 2);
		phalcon_array_update_string(&value, SL("type"), &type, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&value, SL("value"), &expr_value, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&sql_values, value, PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah1, &hp1);
	}
	
	PHALCON_INIT_VAR(sql_update);
	array_init(sql_update);
	phalcon_array_update_string(&sql_update, SL("tables"), &sql_tables, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_update, SL("models"), &sql_models, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_update, SL("fields"), &sql_fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_update, SL("values"), &sql_values, PH_COPY | PH_SEPARATE TSRMLS_CC);
	if (phalcon_array_isset_string(ast, SS("where"))) {
		ZVAL_BOOL(not_quoting, 1);
	
		PHALCON_OBS_VAR(where);
		phalcon_array_fetch_string(&where, ast, SL("where"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(where_expr);
		PHALCON_CALL_METHOD_PARAMS_2(where_expr, this_ptr, "_getexpression", where, not_quoting);
		phalcon_array_update_string(&sql_update, SL("where"), &where_expr, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	if (phalcon_array_isset_string(ast, SS("limit"))) {
		PHALCON_OBS_VAR(limit);
		phalcon_array_fetch_string(&limit, ast, SL("limit"), PH_NOISY_CC);
		phalcon_array_update_string(&sql_update, SL("limit"), &limit, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	
	RETURN_CTOR(sql_update);
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
	zval *model_name = NULL, *model = NULL, *source = NULL, *schema = NULL, *complete_source = NULL;
	zval *alias = NULL, *sql_delete, *not_quoting, *where;
	zval *where_expr, *limit;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(ast);
	phalcon_read_property(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	if (!phalcon_array_isset_string(ast, SS("delete"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted DELETE AST");
		return;
	}
	
	PHALCON_OBS_VAR(delete);
	phalcon_array_fetch_string(&delete, ast, SL("delete"), PH_NOISY_CC);
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
	phalcon_array_fetch_string(&tables, delete, SL("tables"), PH_NOISY_CC);
	if (!phalcon_array_isset_long(tables, 0)) {
		PHALCON_INIT_VAR(delete_tables);
		array_init_size(delete_tables, 1);
		phalcon_array_append(&delete_tables, tables, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(delete_tables, tables);
	}
	
	PHALCON_OBS_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	
	if (!phalcon_valid_foreach(delete_tables TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(delete_tables);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(table);
	
		PHALCON_OBS_NVAR(qualified_name);
		phalcon_array_fetch_string(&qualified_name, table, SL("qualifiedName"), PH_NOISY_CC);
	
		PHALCON_OBS_NVAR(model_name);
		phalcon_array_fetch_string(&model_name, qualified_name, SL("name"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(model);
		PHALCON_CALL_METHOD_PARAMS_1(model, manager, "load", model_name);
	
		PHALCON_INIT_NVAR(source);
		PHALCON_CALL_METHOD(source, model, "getsource");
	
		PHALCON_INIT_NVAR(schema);
		PHALCON_CALL_METHOD(schema, model, "getschema");
		if (zend_is_true(schema)) {
			PHALCON_INIT_NVAR(complete_source);
			array_init_size(complete_source, 2);
			phalcon_array_append(&complete_source, source, PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&complete_source, schema, PH_SEPARATE TSRMLS_CC);
		} else {
			PHALCON_INIT_NVAR(complete_source);
			array_init_size(complete_source, 2);
			phalcon_array_append(&complete_source, source, PH_SEPARATE TSRMLS_CC);
			add_next_index_null(complete_source);
		}
	
		if (phalcon_array_isset_string(table, SS("alias"))) {
			PHALCON_OBS_NVAR(alias);
			phalcon_array_fetch_string(&alias, table, SL("alias"), PH_NOISY_CC);
			phalcon_array_update_zval(&sql_aliases, alias, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&complete_source, alias, PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&sql_tables, complete_source, PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&sql_aliases_models_instances, alias, &model, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&models, alias, &model_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_update_zval(&sql_aliases, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&sql_aliases_models_instances, model_name, &model, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&sql_tables, source, PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&models, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	
		phalcon_array_append(&sql_models, model_name, PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_zval(&models_instances, model_name, &model, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * Update the models/alias/sources in the object
	 */
	phalcon_update_property_zval(this_ptr, SL("_models"), models TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_modelsInstances"), models_instances TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_sqlAliases"), sql_aliases TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_sqlAliasesModelsInstances"), sql_aliases_models_instances TSRMLS_CC);
	
	PHALCON_INIT_VAR(sql_delete);
	array_init(sql_delete);
	phalcon_array_update_string(&sql_delete, SL("tables"), &sql_tables, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_delete, SL("models"), &sql_models, PH_COPY | PH_SEPARATE TSRMLS_CC);
	if (phalcon_array_isset_string(ast, SS("where"))) {
		PHALCON_INIT_VAR(not_quoting);
		ZVAL_BOOL(not_quoting, 1);
	
		PHALCON_OBS_VAR(where);
		phalcon_array_fetch_string(&where, ast, SL("where"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(where_expr);
		PHALCON_CALL_METHOD_PARAMS_2(where_expr, this_ptr, "_getexpression", where, not_quoting);
		phalcon_array_update_string(&sql_delete, SL("where"), &where_expr, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	if (phalcon_array_isset_string(ast, SS("limit"))) {
		PHALCON_OBS_VAR(limit);
		phalcon_array_fetch_string(&limit, ast, SL("limit"), PH_NOISY_CC);
		phalcon_array_update_string(&sql_delete, SL("limit"), &limit, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	
	RETURN_CTOR(sql_delete);
}

/**
 * Parses the intermediate code produced by Phalcon\Mvc\Model\Query\Lang generating another
 * intermediate representation that could be executed by Phalcon\Mvc\Model\Query
 *
 * @param Phalcon\Mvc\Model\ManagerInterface $manager
 * @param Phalcon\Mvc\Model\MetaDataInterface $metaData
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, parse){

	zval *intermediate, *phql, *ast, *ir_phql = NULL, *type, *exception_message;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(intermediate);
	phalcon_read_property(&intermediate, this_ptr, SL("_intermediate"), PH_NOISY_CC);
	if (Z_TYPE_P(intermediate) == IS_ARRAY) { 
		RETURN_CCTOR(intermediate);
	}
	
	PHALCON_OBS_VAR(phql);
	phalcon_read_property(&phql, this_ptr, SL("_phql"), PH_NOISY_CC);
	
	/** 
	 * This function parses the PHQL statement
	 */
	PHALCON_INIT_VAR(ast);
	if (phql_parse_phql(ast, phql TSRMLS_CC) == FAILURE) {
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_ast"), ast TSRMLS_CC);
	
	PHALCON_INIT_VAR(ir_phql);
	if (Z_TYPE_P(ast) == IS_ARRAY) { 
		if (phalcon_array_isset_string(ast, SS("type"))) {
			/** 
			 * Produce an independent database system representation
			 */
			PHALCON_OBS_VAR(type);
			phalcon_array_fetch_string(&type, ast, SL("type"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_type"), type TSRMLS_CC);
	
			switch (phalcon_get_intval(type)) {
	
				case 309:
					PHALCON_CALL_METHOD(ir_phql, this_ptr, "_prepareselect");
					break;
	
				case 306:
					PHALCON_INIT_NVAR(ir_phql);
					PHALCON_CALL_METHOD(ir_phql, this_ptr, "_prepareinsert");
					break;
	
				case 300:
					PHALCON_INIT_NVAR(ir_phql);
					PHALCON_CALL_METHOD(ir_phql, this_ptr, "_prepareupdate");
					break;
	
				case 303:
					PHALCON_INIT_NVAR(ir_phql);
					PHALCON_CALL_METHOD(ir_phql, this_ptr, "_preparedelete");
					break;
	
				default:
					PHALCON_INIT_VAR(exception_message);
					PHALCON_CONCAT_SV(exception_message, "Unknown statement ", type);
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
					return;
	
			}
		}
	}
	
	if (Z_TYPE_P(ir_phql) == IS_NULL) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted AST");
		return;
	}
	
	phalcon_update_property_zval(this_ptr, SL("_intermediate"), ir_phql TSRMLS_CC);
	
	RETURN_CCTOR(ir_phql);
}

/**
 * Sets the cache parameters of the query
 *
 * @param array $cacheOptions
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, cache){

	zval *cache_options;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &cache_options) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_cacheOptions"), cache_options TSRMLS_CC);
	
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
	zval *type = NULL, *connection_types = NULL, *columns, *have_objects = NULL;
	zval *have_scalars = NULL, *is_complex = NULL, *number_objects;
	zval *column = NULL, *column_type = NULL, *is_simple_std = NULL, *select_columns;
	zval *simple_column_map = NULL, *meta_data, *alias = NULL;
	zval *sql_column = NULL, *instance = NULL, *attributes = NULL, *column_map = NULL;
	zval *attribute = NULL, *hidden_alias = NULL, *column_alias = NULL;
	zval *sql_alias = NULL, *dialect, *sql_select, *processed = NULL;
	zval *value = NULL, *wildcard = NULL, *string_wildcard = NULL, *processed_types = NULL;
	zval *result, *count, *result_data = NULL, *cache, *result_object = NULL;
	zval *resultset = NULL;
	HashTable *ah0, *ah1, *ah2, *ah3, *ah4, *ah5, *ah6;
	HashPosition hp0, hp1, hp2, hp3, hp4, hp5, hp6;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &intermediate, &bind_params, &bind_types) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_SEPARATE_PARAM(intermediate);
	
	PHALCON_OBS_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	
	/** 
	 * Models instances is an array if the SELECT was prepared with parse
	 */
	PHALCON_OBS_VAR(models_instances);
	phalcon_read_property(&models_instances, this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
	if (Z_TYPE_P(models_instances) != IS_ARRAY) { 
		PHALCON_INIT_NVAR(models_instances);
		array_init(models_instances);
	}
	
	PHALCON_OBS_VAR(models);
	phalcon_array_fetch_string(&models, intermediate, SL("models"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(number_models);
	phalcon_fast_count(number_models, models TSRMLS_CC);
	if (phalcon_compare_strict_long(number_models, 1 TSRMLS_CC)) {
	
		/** 
		 * Load first model if is not loaded
		 */
		PHALCON_OBS_VAR(model_name);
		phalcon_array_fetch_long(&model_name, models, 0, PH_NOISY_CC);
		if (!phalcon_array_isset(models_instances, model_name)) {
			PHALCON_INIT_VAR(model);
			PHALCON_CALL_METHOD_PARAMS_1(model, manager, "load", model_name);
		} else {
			PHALCON_OBS_NVAR(model);
			phalcon_array_fetch(&model, models_instances, model_name, PH_NOISY_CC);
		}
	
		PHALCON_INIT_VAR(connection);
		PHALCON_CALL_METHOD(connection, model, "getconnection");
		phalcon_array_update_zval(&models_instances, model_name, &model, PH_COPY | PH_SEPARATE TSRMLS_CC);
	} else {
		/** 
		 * Check if all the models belongs to the same connection
		 */
		PHALCON_INIT_VAR(connections);
		array_init(connections);
	
		if (!phalcon_valid_foreach(models TSRMLS_CC)) {
			return;
		}
	
		ah0 = Z_ARRVAL_P(models);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(model_name);
	
			if (!phalcon_array_isset(models_instances, model_name)) {
				PHALCON_INIT_NVAR(model);
				PHALCON_CALL_METHOD_PARAMS_1(model, manager, "load", model_name);
			} else {
				PHALCON_OBS_NVAR(model);
				phalcon_array_fetch(&model, models_instances, model_name, PH_NOISY_CC);
			}
	
			PHALCON_INIT_NVAR(connection);
			PHALCON_CALL_METHOD(connection, model, "getconnection");
	
			PHALCON_INIT_NVAR(type);
			PHALCON_CALL_METHOD(type, connection, "gettype");
			phalcon_array_update_zval_bool(&connections, type, 1, PH_SEPARATE TSRMLS_CC);
	
			PHALCON_INIT_NVAR(connection_types);
			phalcon_fast_count(connection_types, connections TSRMLS_CC);
			if (phalcon_compare_strict_long(connection_types, 2 TSRMLS_CC)) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Cannot use models of different database systems in the same query");
				return;
			}
	
			phalcon_array_update_zval(&models_instances, model_name, &model, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	PHALCON_OBS_VAR(columns);
	phalcon_array_fetch_string(&columns, intermediate, SL("columns"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(have_objects);
	ZVAL_BOOL(have_objects, 0);
	
	PHALCON_INIT_VAR(have_scalars);
	ZVAL_BOOL(have_scalars, 0);
	
	PHALCON_INIT_VAR(is_complex);
	ZVAL_BOOL(is_complex, 0);
	
	/** 
	 * Check if the resultset have objects and how many of them have
	 */
	PHALCON_INIT_VAR(number_objects);
	ZVAL_LONG(number_objects, 0);
	
	if (!phalcon_valid_foreach(columns TSRMLS_CC)) {
		return;
	}
	
	ah1 = Z_ARRVAL_P(columns);
	zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	
	while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(column);
	
		PHALCON_OBS_NVAR(column_type);
		phalcon_array_fetch_string(&column_type, column, SL("type"), PH_NOISY_CC);
		if (PHALCON_COMPARE_STRING(column_type, "scalar")) {
			if (!phalcon_array_isset_string(column, SS("balias"))) {
				PHALCON_INIT_NVAR(is_complex);
				ZVAL_BOOL(is_complex, 1);
			}
	
			PHALCON_INIT_NVAR(have_scalars);
			ZVAL_BOOL(have_scalars, 1);
		} else {
			PHALCON_INIT_NVAR(have_objects);
			ZVAL_BOOL(have_objects, 1);
			PHALCON_SEPARATE(number_objects);
			increment_function(number_objects);
		}
	
		zend_hash_move_forward_ex(ah1, &hp1);
	}
	
	/** 
	 * Check if the resultset to return is complex or simple
	 */
	if (PHALCON_IS_FALSE(is_complex)) {
		if (PHALCON_IS_TRUE(have_objects)) {
			if (PHALCON_IS_TRUE(have_scalars)) {
				ZVAL_BOOL(is_complex, 1);
			} else {
				if (phalcon_compare_strict_long(number_objects, 1 TSRMLS_CC)) {
					PHALCON_INIT_VAR(is_simple_std);
					ZVAL_BOOL(is_simple_std, 0);
				} else {
					ZVAL_BOOL(is_complex, 1);
				}
			}
		} else {
			PHALCON_INIT_NVAR(is_simple_std);
			ZVAL_BOOL(is_simple_std, 1);
		}
	}
	
	/** 
	 * Processing selected columns
	 */
	PHALCON_INIT_VAR(select_columns);
	array_init(select_columns);
	
	PHALCON_INIT_VAR(simple_column_map);
	array_init(simple_column_map);
	
	PHALCON_OBS_VAR(meta_data);
	phalcon_read_property(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
	
	if (!phalcon_valid_foreach(columns TSRMLS_CC)) {
		return;
	}
	
	ALLOC_HASHTABLE(ah2);
	zend_hash_init(ah2, 0, NULL, NULL, 0);
	zend_hash_copy(ah2, Z_ARRVAL_P(columns), NULL, NULL, sizeof(zval*));
	zend_hash_internal_pointer_reset_ex(ah2, &hp2);
	
	while (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) == SUCCESS) {
	
		PHALCON_GET_FOREACH_KEY(alias, ah2, hp2);
		PHALCON_GET_FOREACH_VALUE(column);
	
		PHALCON_OBS_NVAR(type);
		phalcon_array_fetch_string(&type, column, SL("type"), PH_NOISY_CC);
	
		PHALCON_OBS_NVAR(sql_column);
		phalcon_array_fetch_string(&sql_column, column, SL("column"), PH_NOISY_CC);
		if (PHALCON_COMPARE_STRING(type, "object")) {
	
			PHALCON_OBS_NVAR(model_name);
			phalcon_array_fetch_string(&model_name, column, SL("model"), PH_NOISY_CC);
	
			PHALCON_OBS_NVAR(instance);
			phalcon_array_fetch(&instance, models_instances, model_name, PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(attributes);
			PHALCON_CALL_METHOD_PARAMS_1(attributes, meta_data, "getattributes", instance);
			if (PHALCON_IS_TRUE(is_complex)) {
	
				/** 
				 * If the resultset is complex we open every model into their columns
				 */
				if (PHALCON_GLOBAL(orm).column_renaming) {
					PHALCON_INIT_NVAR(column_map);
					PHALCON_CALL_METHOD_PARAMS_1(column_map, meta_data, "getcolumnmap", instance);
				} else {
					PHALCON_INIT_NVAR(column_map);
				}
	
				if (!phalcon_valid_foreach(attributes TSRMLS_CC)) {
					return;
				}
	
				ah3 = Z_ARRVAL_P(attributes);
				zend_hash_internal_pointer_reset_ex(ah3, &hp3);
	
				while (zend_hash_get_current_data_ex(ah3, (void**) &hd, &hp3) == SUCCESS) {
	
					PHALCON_GET_FOREACH_VALUE(attribute);
	
					PHALCON_INIT_NVAR(hidden_alias);
					PHALCON_CONCAT_SVSV(hidden_alias, "_", sql_column, "_", attribute);
	
					PHALCON_INIT_NVAR(column_alias);
					array_init_size(column_alias, 3);
					phalcon_array_append(&column_alias, attribute, PH_SEPARATE TSRMLS_CC);
					phalcon_array_append(&column_alias, sql_column, PH_SEPARATE TSRMLS_CC);
					phalcon_array_append(&column_alias, hidden_alias, PH_SEPARATE TSRMLS_CC);
					phalcon_array_append(&select_columns, column_alias, PH_SEPARATE TSRMLS_CC);
	
					zend_hash_move_forward_ex(ah3, &hp3);
				}
	
				/** 
				 * We cache required meta-data to make its future access faster
				 */
				phalcon_array_update_string_multi_2(&columns, alias, SL("instance"), &instance, 0 TSRMLS_CC);
				phalcon_array_update_string_multi_2(&columns, alias, SL("attributes"), &attributes, 0 TSRMLS_CC);
				phalcon_array_update_string_multi_2(&columns, alias, SL("columnMap"), &column_map, 0 TSRMLS_CC);
			} else {
				/** 
				 * Query only the columns that are registered as attributes in the metaData
				 */
	
				if (!phalcon_valid_foreach(attributes TSRMLS_CC)) {
					return;
				}
	
				ah4 = Z_ARRVAL_P(attributes);
				zend_hash_internal_pointer_reset_ex(ah4, &hp4);
	
				while (zend_hash_get_current_data_ex(ah4, (void**) &hd, &hp4) == SUCCESS) {
	
					PHALCON_GET_FOREACH_VALUE(attribute);
	
					PHALCON_INIT_NVAR(column_alias);
					array_init_size(column_alias, 2);
					phalcon_array_append(&column_alias, attribute, PH_SEPARATE TSRMLS_CC);
					phalcon_array_append(&column_alias, sql_column, PH_SEPARATE TSRMLS_CC);
					phalcon_array_append(&select_columns, column_alias, PH_SEPARATE TSRMLS_CC);
	
					zend_hash_move_forward_ex(ah4, &hp4);
				}
	
			}
		} else {
			if (Z_TYPE_P(alias) == IS_LONG) {
				PHALCON_INIT_NVAR(column_alias);
				array_init_size(column_alias, 2);
				phalcon_array_append(&column_alias, sql_column, PH_SEPARATE TSRMLS_CC);
				add_next_index_null(column_alias);
			} else {
				PHALCON_INIT_NVAR(column_alias);
				array_init_size(column_alias, 3);
				phalcon_array_append(&column_alias, sql_column, PH_SEPARATE TSRMLS_CC);
				add_next_index_null(column_alias);
				phalcon_array_append(&column_alias, alias, PH_SEPARATE TSRMLS_CC);
			}
			phalcon_array_append(&select_columns, column_alias, PH_SEPARATE TSRMLS_CC);
		}
	
		/** 
		 * Simulate a column map
		 */
		if (PHALCON_IS_FALSE(is_complex)) {
			if (PHALCON_IS_TRUE(is_simple_std)) {
				if (phalcon_array_isset_string(column, SS("sqlAlias"))) {
					PHALCON_OBS_NVAR(sql_alias);
					phalcon_array_fetch_string(&sql_alias, column, SL("sqlAlias"), PH_NOISY_CC);
					phalcon_array_update_zval(&simple_column_map, sql_alias, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
				} else {
					phalcon_array_update_zval(&simple_column_map, alias, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
				}
			}
		}
	
		zend_hash_move_forward_ex(ah2, &hp2);
	}
	zend_hash_destroy(ah2);
	efree(ah2);
	
	phalcon_array_update_string(&intermediate, SL("columns"), &select_columns, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	/** 
	 * The corresponding SQL dialect generates the SQL statement based accordingly with
	 * the database system
	 */
	PHALCON_INIT_VAR(dialect);
	PHALCON_CALL_METHOD(dialect, connection, "getdialect");
	
	PHALCON_INIT_VAR(sql_select);
	PHALCON_CALL_METHOD_PARAMS_1(sql_select, dialect, "select", intermediate);
	
	/** 
	 * Replace the placeholders
	 */
	if (Z_TYPE_P(bind_params) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(processed);
		array_init(processed);
	
		if (!phalcon_valid_foreach(bind_params TSRMLS_CC)) {
			return;
		}
	
		ah5 = Z_ARRVAL_P(bind_params);
		zend_hash_internal_pointer_reset_ex(ah5, &hp5);
	
		while (zend_hash_get_current_data_ex(ah5, (void**) &hd, &hp5) == SUCCESS) {
	
			PHALCON_GET_FOREACH_KEY(wildcard, ah5, hp5);
			PHALCON_GET_FOREACH_VALUE(value);
	
			if (Z_TYPE_P(wildcard) == IS_LONG) {
				PHALCON_INIT_NVAR(string_wildcard);
				PHALCON_CONCAT_SV(string_wildcard, ":", wildcard);
				phalcon_array_update_zval(&processed, string_wildcard, &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
			} else {
				phalcon_array_update_zval(&processed, wildcard, &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
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
	
		if (!phalcon_valid_foreach(bind_types TSRMLS_CC)) {
			return;
		}
	
		ah6 = Z_ARRVAL_P(bind_types);
		zend_hash_internal_pointer_reset_ex(ah6, &hp6);
	
		while (zend_hash_get_current_data_ex(ah6, (void**) &hd, &hp6) == SUCCESS) {
	
			PHALCON_GET_FOREACH_KEY(wildcard, ah6, hp6);
			PHALCON_GET_FOREACH_VALUE(value);
	
			if (Z_TYPE_P(wildcard) == IS_LONG) {
				PHALCON_INIT_NVAR(string_wildcard);
				PHALCON_CONCAT_SV(string_wildcard, ":", wildcard);
				phalcon_array_update_zval(&processed_types, string_wildcard, &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
			} else {
				phalcon_array_update_zval(&processed_types, wildcard, &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
			}
	
			zend_hash_move_forward_ex(ah6, &hp6);
		}
	
	} else {
		PHALCON_CPY_WRT(processed_types, bind_types);
	}
	
	/** 
	 * Execute the query
	 */
	PHALCON_INIT_VAR(result);
	PHALCON_CALL_METHOD_PARAMS_3(result, connection, "query", sql_select, processed, processed_types);
	
	PHALCON_INIT_VAR(count);
	PHALCON_CALL_METHOD_PARAMS_1(count, result, "numrows", result);
	if (zend_is_true(count)) {
		PHALCON_CPY_WRT(result_data, result);
	} else {
		PHALCON_INIT_VAR(result_data);
		ZVAL_BOOL(result_data, 0);
	}
	
	/** 
	 * Choose a resultset type
	 */
	PHALCON_OBS_VAR(cache);
	phalcon_read_property(&cache, this_ptr, SL("_cache"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(is_complex)) {
		if (PHALCON_IS_TRUE(is_simple_std)) {
			PHALCON_INIT_VAR(result_object);
			object_init_ex(result_object, phalcon_mvc_model_row_ce);
		} else {
			PHALCON_CPY_WRT(result_object, model);
	
			PHALCON_INIT_NVAR(simple_column_map);
			PHALCON_CALL_METHOD_PARAMS_1(simple_column_map, meta_data, "getcolumnmap", model);
		}
	
		PHALCON_INIT_VAR(resultset);
		object_init_ex(resultset, phalcon_mvc_model_resultset_simple_ce);
		PHALCON_CALL_METHOD_PARAMS_4_NORETURN(resultset, "__construct", simple_column_map, result_object, result_data, cache);
	
	
		RETURN_CTOR(resultset);
	}
	
	PHALCON_INIT_NVAR(resultset);
	object_init_ex(resultset, phalcon_mvc_model_resultset_complex_ce);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(resultset, "__construct", columns, result_data, cache);
	
	
	RETURN_CTOR(resultset);
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
	zval *model = NULL, *connection, *meta_data, *attributes;
	zval *automatic_fields = NULL, *fields = NULL, *column_map = NULL;
	zval *values, *number_fields, *number_values;
	zval *not_equal, *dialect, *double_colon, *empty_string;
	zval *null_value, *not_exists, *insert_values;
	zval *value = NULL, *number = NULL, *type = NULL, *expr_value = NULL, *insert_value = NULL;
	zval *insert_expr = NULL, *wildcard = NULL, *exception_message = NULL;
	zval *field_name = NULL, *attribute_name = NULL, *dependency_injector;
	zval *insert_model, *success, *status;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &intermediate, &bind_params, &bind_types) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(model_name);
	phalcon_array_fetch_string(&model_name, intermediate, SL("model"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(models_instances);
	phalcon_read_property(&models_instances, this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
	if (phalcon_array_isset(models_instances, model_name)) {
		PHALCON_OBS_VAR(model);
		phalcon_array_fetch(&model, models_instances, model_name, PH_NOISY_CC);
	} else {
		PHALCON_INIT_NVAR(model);
		PHALCON_CALL_METHOD_PARAMS_1(model, manager, "load", model_name);
	}
	
	PHALCON_INIT_VAR(connection);
	PHALCON_CALL_METHOD(connection, model, "getconnection");
	
	PHALCON_OBS_VAR(meta_data);
	phalcon_read_property(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(attributes);
	PHALCON_CALL_METHOD_PARAMS_1(attributes, meta_data, "getattributes", model);
	
	PHALCON_INIT_VAR(automatic_fields);
	ZVAL_BOOL(automatic_fields, 0);
	if (phalcon_array_isset_string(intermediate, SS("fields"))) {
		PHALCON_OBS_VAR(fields);
		phalcon_array_fetch_string(&fields, intermediate, SL("fields"), PH_NOISY_CC);
	} else {
		ZVAL_BOOL(automatic_fields, 1);
		PHALCON_CPY_WRT(fields, attributes);
		if (PHALCON_GLOBAL(orm).column_renaming) {
			PHALCON_INIT_VAR(column_map);
			PHALCON_CALL_METHOD_PARAMS_1(column_map, meta_data, "getcolumnmap", model);
		} else {
			PHALCON_INIT_NVAR(column_map);
		}
	}
	
	PHALCON_OBS_VAR(values);
	phalcon_array_fetch_string(&values, intermediate, SL("values"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(number_fields);
	phalcon_fast_count(number_fields, fields TSRMLS_CC);
	
	PHALCON_INIT_VAR(number_values);
	phalcon_fast_count(number_values, values TSRMLS_CC);
	
	PHALCON_INIT_VAR(not_equal);
	is_identical_function(not_equal, number_values, number_fields TSRMLS_CC);
	if (PHALCON_IS_FALSE(not_equal)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The columns count does not match the values count");
		return;
	}
	
	PHALCON_INIT_VAR(dialect);
	PHALCON_CALL_METHOD(dialect, connection, "getdialect");
	
	PHALCON_INIT_VAR(double_colon);
	ZVAL_STRING(double_colon, ":", 1);
	
	PHALCON_INIT_VAR(empty_string);
	ZVAL_STRING(empty_string, "", 1);
	
	PHALCON_INIT_VAR(null_value);
	
	PHALCON_INIT_VAR(not_exists);
	ZVAL_BOOL(not_exists, 0);
	
	PHALCON_INIT_VAR(insert_values);
	array_init(insert_values);
	
	if (!phalcon_valid_foreach(values TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(values);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_KEY(number, ah0, hp0);
		PHALCON_GET_FOREACH_VALUE(value);
	
		PHALCON_OBS_NVAR(type);
		phalcon_array_fetch_string(&type, value, SL("type"), PH_NOISY_CC);
	
		PHALCON_OBS_NVAR(expr_value);
		phalcon_array_fetch_string(&expr_value, value, SL("value"), PH_NOISY_CC);
	
		switch (phalcon_get_intval(type)) {
	
			case 260:
				PHALCON_INIT_NVAR(insert_value);
				PHALCON_CALL_METHOD_PARAMS_1(insert_value, dialect, "getsqlexpression", expr_value);
				break;
	
			case 258:
				PHALCON_INIT_NVAR(insert_value);
				PHALCON_CALL_METHOD_PARAMS_1(insert_value, dialect, "getsqlexpression", expr_value);
				break;
	
			case 259:
				PHALCON_INIT_NVAR(insert_value);
				PHALCON_CALL_METHOD_PARAMS_1(insert_value, dialect, "getsqlexpression", expr_value);
				break;
	
			case 322:
				PHALCON_CPY_WRT(insert_value, null_value);
				break;
	
			case 273:
				if (Z_TYPE_P(bind_params) == IS_ARRAY) { 
	
					PHALCON_INIT_NVAR(insert_expr);
					PHALCON_CALL_METHOD_PARAMS_1(insert_expr, dialect, "getsqlexpression", expr_value);
	
					PHALCON_INIT_NVAR(wildcard);
					phalcon_fast_str_replace(wildcard, double_colon, empty_string, insert_expr TSRMLS_CC);
					if (phalcon_array_isset(bind_params, wildcard)) {
						PHALCON_OBS_NVAR(insert_value);
						phalcon_array_fetch(&insert_value, bind_params, wildcard, PH_NOISY_CC);
					} else {
						PHALCON_INIT_NVAR(exception_message);
						PHALCON_CONCAT_SVS(exception_message, "Bound parameter '", wildcard, "' cannot be replaced because it's not in the placeholders list");
						PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
						return;
					}
				} else {
					PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Bound parameter cannot be replaced because placeholders is not an array");
					return;
				}
				break;
	
			case 274:
				if (Z_TYPE_P(bind_params) == IS_ARRAY) { 
	
					PHALCON_INIT_NVAR(insert_expr);
					PHALCON_CALL_METHOD_PARAMS_1(insert_expr, dialect, "getsqlexpression", expr_value);
	
					PHALCON_INIT_NVAR(wildcard);
					phalcon_fast_str_replace(wildcard, double_colon, empty_string, insert_expr TSRMLS_CC);
					if (phalcon_array_isset(bind_params, wildcard)) {
						PHALCON_OBS_NVAR(insert_value);
						phalcon_array_fetch(&insert_value, bind_params, wildcard, PH_NOISY_CC);
					} else {
						PHALCON_INIT_NVAR(exception_message);
						PHALCON_CONCAT_SVS(exception_message, "Bound parameter '", wildcard, "' cannot be replaced because it's not in the placeholders list");
						PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
						return;
					}
				} else {
					PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Bound parameter cannot be replaced because placeholders is not an array");
					return;
				}
				break;
	
			default:
				PHALCON_INIT_NVAR(insert_expr);
				PHALCON_CALL_METHOD_PARAMS_1(insert_expr, dialect, "getsqlexpression", expr_value);
	
				PHALCON_INIT_NVAR(insert_value);
				object_init_ex(insert_value, phalcon_db_rawvalue_ce);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(insert_value, "__construct", insert_expr);
	
				break;
	
		}
	
		PHALCON_OBS_NVAR(field_name);
		phalcon_array_fetch(&field_name, fields, number, PH_NOISY_CC);
	
		/** 
		 * If the user didn't defined a column list we assume all the model's attributes as
		 * columns
		 */
		if (PHALCON_IS_TRUE(automatic_fields)) {
			if (Z_TYPE_P(column_map) == IS_ARRAY) { 
				if (phalcon_array_isset(column_map, field_name)) {
					PHALCON_OBS_NVAR(attribute_name);
					phalcon_array_fetch(&attribute_name, column_map, field_name, PH_NOISY_CC);
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
	
		phalcon_array_update_zval(&insert_values, attribute_name, &insert_value, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ce0 = phalcon_fetch_class(model_name TSRMLS_CC);
	
	PHALCON_INIT_VAR(insert_model);
	object_init_ex(insert_model, ce0);
	if (phalcon_has_constructor(insert_model TSRMLS_CC)) {
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(insert_model, "__construct", dependency_injector);
	}
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_1(success, insert_model, "create", insert_values);
	
	PHALCON_INIT_VAR(status);
	object_init_ex(status, phalcon_mvc_model_query_status_ce);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(status, "__construct", success, insert_model);
	
	
	RETURN_CTOR(status);
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
	zval *selected_tables, *selected_models, *source;
	zval *model_name, *select_column, *selected_columns;
	zval *select_ir, *where_conditions, *limit_conditions;
	zval *type_select, *dependency_injector, *query;
	zval *records;
	zval *a0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &model, &intermediate, &bind_params, &bind_types) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(selected_tables);
	phalcon_array_fetch_string(&selected_tables, intermediate, SL("tables"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(selected_models);
	phalcon_array_fetch_string(&selected_models, intermediate, SL("models"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(source);
	PHALCON_CALL_METHOD(source, model, "getsource");
	
	PHALCON_INIT_VAR(model_name);
	phalcon_get_class(model_name, model, 0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(select_column);
	array_init_size(select_column, 1);
	
	PHALCON_INIT_VAR(a0);
	array_init_size(a0, 3);
	add_assoc_stringl_ex(a0, SS("type"), SL("object"), 1);
	phalcon_array_update_string(&a0, SL("model"), &model_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&a0, SL("column"), &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_append(&select_column, a0, PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(selected_columns);
	array_init_size(selected_columns, 1);
	phalcon_array_append(&selected_columns, select_column, PH_SEPARATE TSRMLS_CC);
	
	/** 
	 * Instead of create a PQHL string statement we manually create the IR
	 * representation
	 */
	PHALCON_INIT_VAR(select_ir);
	array_init_size(select_ir, 3);
	phalcon_array_update_string(&select_ir, SL("columns"), &select_column, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&select_ir, SL("models"), &selected_models, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&select_ir, SL("tables"), &selected_tables, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	/** 
	 * Check if a WHERE clause was especified
	 */
	if (phalcon_array_isset_string(intermediate, SS("where"))) {
		PHALCON_OBS_VAR(where_conditions);
		phalcon_array_fetch_string(&where_conditions, intermediate, SL("where"), PH_NOISY_CC);
		phalcon_array_update_string(&select_ir, SL("where"), &where_conditions, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	/** 
	 * Check if a WHERE clause was especified
	 */
	if (phalcon_array_isset_string(intermediate, SS("limit"))) {
		PHALCON_OBS_VAR(limit_conditions);
		phalcon_array_fetch_string(&limit_conditions, intermediate, SL("limit"), PH_NOISY_CC);
		phalcon_array_update_string(&select_ir, SL("limit"), &limit_conditions, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(type_select);
	ZVAL_LONG(type_select, 309);
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
	/** 
	 * We create another Phalcon\Mvc\Model\Query to get the related records
	 */
	PHALCON_INIT_VAR(query);
	object_init_ex(query, phalcon_mvc_model_query_ce);
	PHALCON_CALL_METHOD_NORETURN(query, "__construct");
	
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "setdi", dependency_injector);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "settype", type_select);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "setintermediate", select_ir);
	
	PHALCON_INIT_VAR(records);
	PHALCON_CALL_METHOD_PARAMS_2(records, query, "execute", bind_params, bind_types);
	
	RETURN_CCTOR(records);
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
	zval *model = NULL, *manager, *connection, *dialect, *double_colon;
	zval *empty_string, *fields, *values, *update_values;
	zval *select_bind_params = NULL, *select_bind_types = NULL;
	zval *null_value, *field = NULL, *number = NULL, *field_name = NULL;
	zval *value = NULL, *type = NULL, *expr_value = NULL, *update_value = NULL;
	zval *update_expr = NULL, *wildcard = NULL, *exception_message = NULL;
	zval *records, *success = NULL, *status = NULL, *record = NULL;
	zval *r0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &intermediate, &bind_params, &bind_types) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(models);
	phalcon_array_fetch_string(&models, intermediate, SL("models"), PH_NOISY_CC);
	if (phalcon_array_isset_long(models, 1)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Updating several models at the same time is still not supported");
		return;
	}
	
	PHALCON_OBS_VAR(model_name);
	phalcon_array_fetch_long(&model_name, models, 0, PH_NOISY_CC);
	
	/** 
	 * Load the model from the modelsManager or from the _modelsInstances property
	 */
	PHALCON_OBS_VAR(models_instances);
	phalcon_read_property(&models_instances, this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
	if (phalcon_array_isset(models_instances, model_name)) {
		PHALCON_OBS_VAR(model);
		phalcon_array_fetch(&model, models_instances, model_name, PH_NOISY_CC);
	} else {
		PHALCON_OBS_VAR(manager);
		phalcon_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(model);
		PHALCON_CALL_METHOD_PARAMS_1(model, manager, "load", model_name);
	}
	
	PHALCON_INIT_VAR(connection);
	PHALCON_CALL_METHOD(connection, model, "getconnection");
	
	PHALCON_INIT_VAR(dialect);
	PHALCON_CALL_METHOD(dialect, connection, "getdialect");
	
	PHALCON_INIT_VAR(double_colon);
	ZVAL_STRING(double_colon, ":", 1);
	
	PHALCON_INIT_VAR(empty_string);
	ZVAL_STRING(empty_string, "", 1);
	
	PHALCON_OBS_VAR(fields);
	phalcon_array_fetch_string(&fields, intermediate, SL("fields"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(values);
	phalcon_array_fetch_string(&values, intermediate, SL("values"), PH_NOISY_CC);
	
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
	
	if (!phalcon_valid_foreach(fields TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(fields);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_KEY(number, ah0, hp0);
		PHALCON_GET_FOREACH_VALUE(field);
	
		PHALCON_OBS_NVAR(field_name);
		phalcon_array_fetch_string(&field_name, field, SL("name"), PH_NOISY_CC);
	
		PHALCON_OBS_NVAR(value);
		phalcon_array_fetch(&value, values, number, PH_NOISY_CC);
	
		PHALCON_OBS_NVAR(type);
		phalcon_array_fetch_string(&type, value, SL("type"), PH_NOISY_CC);
	
		PHALCON_OBS_NVAR(expr_value);
		phalcon_array_fetch_string(&expr_value, value, SL("value"), PH_NOISY_CC);
	
		switch (phalcon_get_intval(type)) {
	
			case 260:
				PHALCON_INIT_NVAR(update_value);
				PHALCON_CALL_METHOD_PARAMS_1(update_value, dialect, "getsqlexpression", expr_value);
				break;
	
			case 258:
				PHALCON_INIT_NVAR(update_value);
				PHALCON_CALL_METHOD_PARAMS_1(update_value, dialect, "getsqlexpression", expr_value);
				break;
	
			case 259:
				PHALCON_INIT_NVAR(update_value);
				PHALCON_CALL_METHOD_PARAMS_1(update_value, dialect, "getsqlexpression", expr_value);
				break;
	
			case 322:
				PHALCON_CPY_WRT(update_value, null_value);
				break;
	
			case 273:
				if (Z_TYPE_P(bind_params) == IS_ARRAY) { 
	
					PHALCON_INIT_NVAR(update_expr);
					PHALCON_CALL_METHOD_PARAMS_1(update_expr, dialect, "getsqlexpression", expr_value);
	
					PHALCON_INIT_NVAR(wildcard);
					phalcon_fast_str_replace(wildcard, double_colon, empty_string, update_expr TSRMLS_CC);
					if (phalcon_array_isset(bind_params, wildcard)) {
						PHALCON_OBS_NVAR(update_value);
						phalcon_array_fetch(&update_value, bind_params, wildcard, PH_NOISY_CC);
						PHALCON_SEPARATE(select_bind_params);
						phalcon_array_unset(select_bind_params, wildcard);
						PHALCON_SEPARATE(select_bind_types);
						phalcon_array_unset(select_bind_types, wildcard);
					} else {
						PHALCON_INIT_NVAR(exception_message);
						PHALCON_CONCAT_SVS(exception_message, "Bound parameter '", wildcard, "' cannot be replaced because it's not in the placeholders list");
						PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
						return;
					}
				} else {
					PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Bound parameter cannot be replaced because placeholders is not an array");
					return;
				}
				break;
	
			case 274:
				if (Z_TYPE_P(bind_params) == IS_ARRAY) { 
	
					PHALCON_INIT_NVAR(update_expr);
					PHALCON_CALL_METHOD_PARAMS_1(update_expr, dialect, "getsqlexpression", expr_value);
	
					PHALCON_INIT_NVAR(wildcard);
					phalcon_fast_str_replace(wildcard, double_colon, empty_string, update_expr TSRMLS_CC);
					if (phalcon_array_isset(bind_params, wildcard)) {
						PHALCON_OBS_NVAR(update_value);
						phalcon_array_fetch(&update_value, bind_params, wildcard, PH_NOISY_CC);
						PHALCON_SEPARATE(select_bind_params);
						phalcon_array_unset(select_bind_params, wildcard);
						PHALCON_SEPARATE(select_bind_types);
						phalcon_array_unset(select_bind_types, wildcard);
					} else {
						PHALCON_INIT_NVAR(exception_message);
						PHALCON_CONCAT_SVS(exception_message, "Bound parameter '", wildcard, "' cannot be replaced because it's not in the placeholders list");
						PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
						return;
					}
				} else {
					PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Bound parameter cannot be replaced because placeholders is not an array");
					return;
				}
				break;
	
			default:
				PHALCON_INIT_NVAR(update_expr);
				PHALCON_CALL_METHOD_PARAMS_1(update_expr, dialect, "getsqlexpression", expr_value);
	
				PHALCON_INIT_NVAR(update_value);
				object_init_ex(update_value, phalcon_db_rawvalue_ce);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(update_value, "__construct", update_expr);
	
				break;
	
		}
		phalcon_array_update_zval(&update_values, field_name, &update_value, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * We need to query the records related to the update
	 */
	PHALCON_INIT_VAR(records);
	PHALCON_CALL_METHOD_PARAMS_4(records, this_ptr, "_getrelatedrecords", model, intermediate, select_bind_params, select_bind_types);
	
	/** 
	 * If there are no records to apply the update we return success
	 */
	if (!phalcon_fast_count_ev(records TSRMLS_CC)) {
		PHALCON_INIT_VAR(success);
		ZVAL_BOOL(success, 1);
	
		PHALCON_INIT_VAR(status);
		object_init_ex(status, phalcon_mvc_model_query_status_ce);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(status, "__construct", success, null_value);
	
		RETURN_CTOR(status);
	}
	
	PHALCON_CALL_METHOD_NORETURN(records, "rewind");
	
	while (1) {
	
		PHALCON_INIT_NVAR(r0);
		PHALCON_CALL_METHOD(r0, records, "valid");
		if (PHALCON_IS_NOT_FALSE(r0)) {
		} else {
			break;
		}
	
		PHALCON_INIT_NVAR(record);
		PHALCON_CALL_METHOD(record, records, "current");
	
		/** 
		 * We apply the executed values to every record found
		 */
		PHALCON_INIT_NVAR(success);
		PHALCON_CALL_METHOD_PARAMS_1(success, record, "update", update_values);
		if (PHALCON_IS_FALSE(success)) {
			PHALCON_INIT_NVAR(status);
			object_init_ex(status, phalcon_mvc_model_query_status_ce);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(status, "__construct", success, record);
	
			RETURN_CTOR(status);
		}
	
		PHALCON_CALL_METHOD_NORETURN(records, "next");
	}
	
	PHALCON_INIT_NVAR(success);
	ZVAL_BOOL(success, 1);
	
	PHALCON_INIT_NVAR(status);
	object_init_ex(status, phalcon_mvc_model_query_status_ce);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(status, "__construct", success, null_value);
	
	
	RETURN_CTOR(status);
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
	zval *model = NULL, *manager, *records, *success = NULL, *null_value = NULL;
	zval *status = NULL, *record = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &intermediate, &bind_params, &bind_types) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(models);
	phalcon_array_fetch_string(&models, intermediate, SL("models"), PH_NOISY_CC);
	if (phalcon_array_isset_long(models, 1)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Delete from several models at the same time is still not supported");
		return;
	}
	
	PHALCON_OBS_VAR(model_name);
	phalcon_array_fetch_long(&model_name, models, 0, PH_NOISY_CC);
	
	/** 
	 * Load the model from the modelsManager or from the _modelsInstances property
	 */
	PHALCON_OBS_VAR(models_instances);
	phalcon_read_property(&models_instances, this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
	if (phalcon_array_isset(models_instances, model_name)) {
		PHALCON_OBS_VAR(model);
		phalcon_array_fetch(&model, models_instances, model_name, PH_NOISY_CC);
	} else {
		PHALCON_OBS_VAR(manager);
		phalcon_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(model);
		PHALCON_CALL_METHOD_PARAMS_1(model, manager, "load", model_name);
	}
	
	/** 
	 * Get the records to be deleted
	 */
	PHALCON_INIT_VAR(records);
	PHALCON_CALL_METHOD_PARAMS_4(records, this_ptr, "_getrelatedrecords", model, intermediate, bind_params, bind_types);
	
	/** 
	 * If there are no records to delete we return success
	 */
	if (!phalcon_fast_count_ev(records TSRMLS_CC)) {
		PHALCON_INIT_VAR(success);
		ZVAL_BOOL(success, 1);
	
		PHALCON_INIT_VAR(null_value);
	
		PHALCON_INIT_VAR(status);
		object_init_ex(status, phalcon_mvc_model_query_status_ce);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(status, "__construct", success, null_value);
	
		RETURN_CTOR(status);
	}
	
	PHALCON_CALL_METHOD_NORETURN(records, "rewind");
	
	while (1) {
	
		PHALCON_INIT_NVAR(r0);
		PHALCON_CALL_METHOD(r0, records, "valid");
		if (PHALCON_IS_NOT_FALSE(r0)) {
		} else {
			break;
		}
	
		PHALCON_INIT_NVAR(record);
		PHALCON_CALL_METHOD(record, records, "current");
	
		/** 
		 * We delete every record found
		 */
		PHALCON_INIT_NVAR(success);
		PHALCON_CALL_METHOD(success, record, "delete");
		if (PHALCON_IS_FALSE(success)) {
			PHALCON_INIT_NVAR(status);
			object_init_ex(status, phalcon_mvc_model_query_status_ce);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(status, "__construct", success, record);
	
			RETURN_CTOR(status);
		}
	
		PHALCON_CALL_METHOD_NORETURN(records, "next");
	}
	
	PHALCON_INIT_NVAR(success);
	ZVAL_BOOL(success, 1);
	
	PHALCON_INIT_NVAR(null_value);
	ZVAL_BOOL(null_value, 1);
	
	PHALCON_INIT_NVAR(status);
	object_init_ex(status, phalcon_mvc_model_query_status_ce);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(status, "__construct", success, null_value);
	
	
	RETURN_CTOR(status);
}

/**
 * Executes a parsed PHQL statement
 *
 * @param array $bindParams
 * @param array $bindTypes
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, execute){

	zval *bind_params = NULL, *bind_types = NULL, *cache_options;
	zval *key, *lifetime = NULL, *cache_service = NULL, *dependency_injector;
	zval *cache, *result = NULL, *is_fresh, *intermediate;
	zval *type, *exception_message;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &bind_params, &bind_types) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!bind_params) {
		PHALCON_INIT_VAR(bind_params);
	}
	
	if (!bind_types) {
		PHALCON_INIT_VAR(bind_types);
	}
	
	PHALCON_OBS_VAR(cache_options);
	phalcon_read_property(&cache_options, this_ptr, SL("_cacheOptions"), PH_NOISY_CC);
	if (Z_TYPE_P(cache_options) != IS_NULL) {
		if (Z_TYPE_P(cache_options) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid caching options");
			return;
		}
	
		/** 
		 * The user must set a cache key
		 */
		if (phalcon_array_isset_string(cache_options, SS("key"))) {
			PHALCON_OBS_VAR(key);
			phalcon_array_fetch_string(&key, cache_options, SL("key"), PH_NOISY_CC);
		} else {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A cache key must be provided to identify the cached resultset in the cache backend");
			return;
		}
	
		/** 
		 * By defaut use use 3600 seconds (1 hour) as cache lifetime
		 */
		if (phalcon_array_isset_string(cache_options, SS("lifetime"))) {
			PHALCON_OBS_VAR(lifetime);
			phalcon_array_fetch_string(&lifetime, cache_options, SL("lifetime"), PH_NOISY_CC);
		} else {
			PHALCON_INIT_NVAR(lifetime);
			ZVAL_LONG(lifetime, 3600);
		}
	
		/** 
		 * 'modelsCache' is the default name for the models cache service
		 */
		if (phalcon_array_isset_string(cache_options, SS("service"))) {
			PHALCON_OBS_VAR(cache_service);
			phalcon_array_fetch_string(&cache_service, cache_options, SL("service"), PH_NOISY_CC);
		} else {
			PHALCON_INIT_NVAR(cache_service);
			ZVAL_STRING(cache_service, "modelsCache", 1);
		}
	
		PHALCON_OBS_VAR(dependency_injector);
		phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(cache);
		PHALCON_CALL_METHOD_PARAMS_1(cache, dependency_injector, "getshared", cache_service);
		if (Z_TYPE_P(cache) == IS_OBJECT) {
	
			PHALCON_INIT_VAR(result);
			PHALCON_CALL_METHOD_PARAMS_2(result, cache, "get", key, lifetime);
			if (Z_TYPE_P(result) != IS_NULL) {
				if (Z_TYPE_P(result) != IS_OBJECT) {
					PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The cache didn't return a valid resultset");
					return;
				}
	
				PHALCON_INIT_VAR(is_fresh);
				ZVAL_BOOL(is_fresh, 0);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(result, "setisfresh", is_fresh);
	
				RETURN_CCTOR(result);
			}
		} else {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The cache service must be an object");
			return;
		}
	
		phalcon_update_property_zval(this_ptr, SL("_cache"), cache TSRMLS_CC);
	}
	
	/** 
	 * The statement is parsed from its PHQL string or a previously processed IR
	 */
	PHALCON_INIT_VAR(intermediate);
	PHALCON_CALL_METHOD(intermediate, this_ptr, "parse");
	
	PHALCON_OBS_VAR(type);
	phalcon_read_property(&type, this_ptr, SL("_type"), PH_NOISY_CC);
	
	switch (phalcon_get_intval(type)) {
	
		case 309:
			PHALCON_INIT_NVAR(result);
			PHALCON_CALL_METHOD_PARAMS_3(result, this_ptr, "_executeselect", intermediate, bind_params, bind_types);
			break;
	
		case 306:
			PHALCON_INIT_NVAR(result);
			PHALCON_CALL_METHOD_PARAMS_3(result, this_ptr, "_executeinsert", intermediate, bind_params, bind_types);
			break;
	
		case 300:
			PHALCON_INIT_NVAR(result);
			PHALCON_CALL_METHOD_PARAMS_3(result, this_ptr, "_executeupdate", intermediate, bind_params, bind_types);
			break;
	
		case 303:
			PHALCON_INIT_NVAR(result);
			PHALCON_CALL_METHOD_PARAMS_3(result, this_ptr, "_executedelete", intermediate, bind_params, bind_types);
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
	if (Z_TYPE_P(cache_options) != IS_NULL) {
	
		/** 
		 * Only PHQL SELECTs can be cached
		 */
		if (!phalcon_compare_strict_long(type, 309 TSRMLS_CC)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Only PHQL statements that return resultsets can be cached");
			return;
		}
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(cache, "save", key, result, lifetime);
	}
	
	
	RETURN_CCTOR(result);
}

/**
 * Sets the type of PHQL statement to be executed
 *
 * @param int $type
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setType){

	zval *type;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &type) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_type"), type TSRMLS_CC);
	
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
 * Allows to set the IR to be executed
 *
 * @param array $intermediate
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setIntermediate){

	zval *intermediate;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &intermediate) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_intermediate"), intermediate TSRMLS_CC);
	
}

/**
 * Returns the intermediate representation of the PHQL statement
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getIntermediate){


	RETURN_MEMBER(this_ptr, "_intermediate");
}

