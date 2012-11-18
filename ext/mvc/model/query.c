
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
 * $phql  = "SELECT c.price*0.16 AS taxes, c.* FROM Cars AS c JOIN Brands AS b WHERE b.name = :name: ORDER BY c.name";
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
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_models"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_sqlAliases"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_sqlAliasesModels"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_sqlModelsAliases"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_sqlAliasesModelsInstances"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_sqlColumnAliases"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_modelsInstances"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_query_ce TSRMLS_CC, 2, phalcon_mvc_model_queryinterface_ce, phalcon_di_injectionawareinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Query constructor
 *
 * @param string $phql
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, __construct){

	zval *phql;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &phql) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_phql"), phql TSRMLS_CC);
	
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
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the ORM services");
		return;
	}
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "modelsManager", 1);
	
	PHALCON_INIT_VAR(manager);
	PHALCON_CALL_METHOD_PARAMS_1(manager, dependency_injector, "getshared", service, PH_NO_CHECK);
	if (Z_TYPE_P(manager) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Injected service 'modelsManager' is invalid");
		return;
	}
	
	PHALCON_INIT_NVAR(service);
	ZVAL_STRING(service, "modelsMetadata", 1);
	
	PHALCON_INIT_VAR(meta_data);
	PHALCON_CALL_METHOD_PARAMS_1(meta_data, dependency_injector, "getshared", service, PH_NO_CHECK);
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
	zval *ambiguity = NULL, *class_name, *models;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &expr) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(column_name);
	phalcon_array_fetch_string(&column_name, expr, SL("name"), PH_NOISY_CC);
	
	/** 
	 * Check if the qualified name is a column alias
	 */
	PHALCON_INIT_VAR(sql_column_aliases);
	phalcon_read_property(&sql_column_aliases, this_ptr, SL("_sqlColumnAliases"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(sql_column_aliases, column_name);
	if (eval_int) {
		PHALCON_INIT_VAR(source_column);
		array_init(source_column);
		add_assoc_stringl_ex(source_column, SS("type"), SL("qualified"), 1);
		phalcon_array_update_string(&source_column, SL("name"), &column_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
		RETURN_CTOR(source_column);
	}
	
	PHALCON_INIT_VAR(meta_data);
	phalcon_read_property(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
	
	/** 
	 * Check if the qualified name has a domain
	 */
	eval_int = phalcon_array_isset_string(expr, SS("domain"));
	if (eval_int) {
		PHALCON_INIT_VAR(column_domain);
		phalcon_array_fetch_string(&column_domain, expr, SL("domain"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(sql_aliases);
		phalcon_read_property(&sql_aliases, this_ptr, SL("_sqlAliases"), PH_NOISY_CC);
	
		/** 
		 * The column has a domain, we need to check if it's an alias
		 */
		eval_int = phalcon_array_isset(sql_aliases, column_domain);
		if (!eval_int) {
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "Unknown table or alias '", column_domain, "' (1)");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
		}
	
		PHALCON_INIT_VAR(source);
		phalcon_array_fetch(&source, sql_aliases, column_domain, PH_NOISY_CC);
	
		/** 
		 * Retrieve the corresponding model by its alias
		 */
		PHALCON_INIT_VAR(sql_aliases_models_instances);
		phalcon_read_property(&sql_aliases_models_instances, this_ptr, SL("_sqlAliasesModelsInstances"), PH_NOISY_CC);
		eval_int = phalcon_array_isset(sql_aliases_models_instances, column_domain);
		if (!eval_int) {
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "There is no model related to table or alias '", column_domain, "'");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
		}
	
		/** 
		 * Change the selected column by its real name on its mapped table
		 */
		PHALCON_INIT_VAR(model);
		phalcon_array_fetch(&model, sql_aliases_models_instances, column_domain, PH_NOISY_CC);
	
		PHALCON_INIT_VAR(column_map);
		PHALCON_CALL_METHOD_PARAMS_1(column_map, meta_data, "getreversecolumnmap", model, PH_NO_CHECK);
		if (Z_TYPE_P(column_map) != IS_NULL) {
			eval_int = phalcon_array_isset(column_map, column_name);
			if (eval_int) {
				PHALCON_INIT_VAR(real_column_name);
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
	
		PHALCON_INIT_VAR(models_instances);
		phalcon_read_property(&models_instances, this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
	
		if (!phalcon_valid_foreach(models_instances TSRMLS_CC)) {
			return;
		}
	
		ah0 = Z_ARRVAL_P(models_instances);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
		ph_cycle_start_0:
	
			if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
				goto ph_cycle_end_0;
			}
	
			PHALCON_GET_FOREACH_VALUE(model);
	
			PHALCON_INIT_NVAR(has_attribute);
			PHALCON_CALL_METHOD_PARAMS_2(has_attribute, meta_data, "hasattribute", model, column_name, PH_NO_CHECK);
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
			goto ph_cycle_start_0;
	
		ph_cycle_end_0:
	
		if (PHALCON_IS_FALSE(has_model)) {
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "Column '", column_name, "' doesn't belong to any of the selected models");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
		}
	
		/** 
		 * Obtain the model's source from the _models list
		 */
		PHALCON_INIT_VAR(class_name);
		phalcon_get_class(class_name, has_model TSRMLS_CC);
	
		PHALCON_INIT_VAR(models);
		phalcon_read_property(&models, this_ptr, SL("_models"), PH_NOISY_CC);
		eval_int = phalcon_array_isset(models, class_name);
		if (eval_int) {
			PHALCON_INIT_NVAR(source);
			phalcon_array_fetch(&source, models, class_name, PH_NOISY_CC);
		} else {
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "Column '", column_name, "' doesn't belong to any of the selected models");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
		}
	
		/** 
		 * Rename the column
		 */
		PHALCON_INIT_NVAR(column_map);
		PHALCON_CALL_METHOD_PARAMS_1(column_map, meta_data, "getreversecolumnmap", has_model, PH_NO_CHECK);
		if (Z_TYPE_P(column_map) == IS_ARRAY) { 
			eval_int = phalcon_array_isset(column_map, column_name);
			if (eval_int) {
				PHALCON_INIT_NVAR(real_column_name);
				phalcon_array_fetch(&real_column_name, column_map, column_name, PH_NOISY_CC);
			} else {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Column '", column_name, "' doesn't belong to any of the selected models");
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
	array_init(source_column);
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
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(argument_type);
	phalcon_array_fetch_string(&argument_type, argument, SL("type"), PH_NOISY_CC);
	if (phalcon_compare_strict_long(argument_type, 352 TSRMLS_CC)) {
		PHALCON_INIT_VAR(argument_expr);
		array_init(argument_expr);
		add_assoc_stringl_ex(argument_expr, SS("type"), SL("all"), 1);
	} else {
		PHALCON_INIT_NVAR(argument_expr);
		PHALCON_CALL_METHOD_PARAMS_1(argument_expr, this_ptr, "_getexpression", argument, PH_NO_CHECK);
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
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &expr) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(name);
	phalcon_array_fetch_string(&name, expr, SL("name"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_string(expr, SS("arguments"));
	if (eval_int) {
		PHALCON_INIT_VAR(arguments);
		phalcon_array_fetch_string(&arguments, expr, SL("arguments"), PH_NOISY_CC);
		eval_int = phalcon_array_isset_long(arguments, 0);
		if (eval_int) {
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
	
			ph_cycle_start_0:
	
				if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
					goto ph_cycle_end_0;
				}
	
				PHALCON_GET_FOREACH_VALUE(argument);
	
				PHALCON_INIT_NVAR(argument_expr);
				PHALCON_CALL_METHOD_PARAMS_1(argument_expr, this_ptr, "_getcallargument", argument, PH_NO_CHECK);
				phalcon_array_append(&function_args, argument_expr, PH_SEPARATE TSRMLS_CC);
	
				zend_hash_move_forward_ex(ah0, &hp0);
				goto ph_cycle_start_0;
	
			ph_cycle_end_0:
			if(0){}
	
		} else {
			/** 
			 * There is only one argument
			 */
			PHALCON_INIT_NVAR(argument_expr);
			PHALCON_CALL_METHOD_PARAMS_1(argument_expr, this_ptr, "_getcallargument", arguments, PH_NO_CHECK);
	
			PHALCON_INIT_NVAR(function_args);
			array_init(function_args);
			phalcon_array_append(&function_args, argument_expr, PH_SEPARATE TSRMLS_CC);
		}
	
		PHALCON_INIT_VAR(function_call);
		array_init(function_call);
		add_assoc_stringl_ex(function_call, SS("type"), SL("functionCall"), 1);
		phalcon_array_update_string(&function_call, SL("name"), &name, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&function_call, SL("arguments"), &function_args, PH_COPY | PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_INIT_NVAR(function_call);
		array_init(function_call);
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
 * @param boolean $fullPlaceholder
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getExpression){

	zval *expr, *quoting = NULL, *full_placeholder = NULL, *temp_not_quoting;
	zval *expr_left, *left, *expr_right, *right, *expr_type;
	zval *expr_return = NULL, *expr_value = NULL, *value = NULL, *escaped_value;
	zval *question_mark, *empty_string, *numeric_place;
	zval *placeholder = NULL, *expression_message, *expression;
	zval *expr_domain, *list_items, *expr_list_item = NULL;
	zval *expr_item = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zz", &expr, &quoting, &full_placeholder) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!quoting) {
		PHALCON_INIT_NVAR(quoting);
		ZVAL_BOOL(quoting, 1);
	}
	
	if (!full_placeholder) {
		PHALCON_INIT_NVAR(full_placeholder);
		ZVAL_BOOL(full_placeholder, 0);
	}
	
	eval_int = phalcon_array_isset_string(expr, SS("type"));
	if (eval_int) {
		PHALCON_INIT_VAR(temp_not_quoting);
		ZVAL_BOOL(temp_not_quoting, 1);
	
		/** 
		 * Resolving left part of the expression if any
		 */
		eval_int = phalcon_array_isset_string(expr, SS("left"));
		if (eval_int) {
			PHALCON_INIT_VAR(expr_left);
			phalcon_array_fetch_string(&expr_left, expr, SL("left"), PH_NOISY_CC);
	
			PHALCON_INIT_VAR(left);
			PHALCON_CALL_METHOD_PARAMS_3(left, this_ptr, "_getexpression", expr_left, temp_not_quoting, full_placeholder, PH_NO_CHECK);
		}
	
		/** 
		 * Resolving right part of the expression if any
		 */
		eval_int = phalcon_array_isset_string(expr, SS("right"));
		if (eval_int) {
			PHALCON_INIT_VAR(expr_right);
			phalcon_array_fetch_string(&expr_right, expr, SL("right"), PH_NOISY_CC);
	
			PHALCON_INIT_VAR(right);
			PHALCON_CALL_METHOD_PARAMS_3(right, this_ptr, "_getexpression", expr_right, temp_not_quoting, full_placeholder, PH_NO_CHECK);
		}
	
		/** 
		 * Every node in the AST has a unique integer type
		 */
		PHALCON_INIT_VAR(expr_type);
		phalcon_array_fetch_string(&expr_type, expr, SL("type"), PH_NOISY_CC);
	
		if (phalcon_compare_strict_long(expr_type, 60 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
			add_assoc_stringl_ex(expr_return, SS("op"), SL("<"), 1);
			phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 61 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
			add_assoc_stringl_ex(expr_return, SS("op"), SL("="), 1);
			phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 62 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
			add_assoc_stringl_ex(expr_return, SS("op"), SL(">"), 1);
			phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 270 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
			add_assoc_stringl_ex(expr_return, SS("op"), SL("<>"), 1);
			phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 271 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
			add_assoc_stringl_ex(expr_return, SS("op"), SL("<="), 1);
			phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 272 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
			add_assoc_stringl_ex(expr_return, SS("op"), SL(">="), 1);
			phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 266 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
			add_assoc_stringl_ex(expr_return, SS("op"), SL("AND"), 1);
			phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 267 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
			add_assoc_stringl_ex(expr_return, SS("op"), SL("OR"), 1);
			phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 355 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(expr_return);
			PHALCON_CALL_METHOD_PARAMS_1(expr_return, this_ptr, "_getqualified", expr, PH_NO_CHECK);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 43 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
			add_assoc_stringl_ex(expr_return, SS("op"), SL("+"), 1);
			phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 45 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
			add_assoc_stringl_ex(expr_return, SS("op"), SL("-"), 1);
			phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 42 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
			add_assoc_stringl_ex(expr_return, SS("op"), SL("*"), 1);
			phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 47 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
			add_assoc_stringl_ex(expr_return, SS("op"), SL("/"), 1);
			phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 37 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
			add_assoc_stringl_ex(expr_return, SS("op"), SL("%"), 1);
			phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 356 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("parentheses"), 1);
			phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 367 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("unary-op"), 1);
			add_assoc_stringl_ex(expr_return, SS("op"), SL("-"), 1);
			phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 258 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_value);
			phalcon_array_fetch_string(&expr_value, expr, SL("value"), PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("literal"), 1);
			phalcon_array_update_string(&expr_return, SL("value"), &expr_value, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 259 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(expr_value);
			phalcon_array_fetch_string(&expr_value, expr, SL("value"), PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("literal"), 1);
			phalcon_array_update_string(&expr_return, SL("value"), &expr_value, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 260 TSRMLS_CC)) {
			PHALCON_INIT_VAR(value);
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
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("literal"), 1);
			phalcon_array_update_string(&expr_return, SL("value"), &expr_value, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 273 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(value);
			phalcon_array_fetch_string(&value, expr, SL("value"), PH_NOISY_CC);
	
			PHALCON_INIT_VAR(question_mark);
			ZVAL_STRING(question_mark, "?", 1);
	
			PHALCON_INIT_VAR(empty_string);
			ZVAL_STRING(empty_string, "", 1);
	
			PHALCON_INIT_VAR(numeric_place);
			phalcon_fast_str_replace(numeric_place, question_mark, empty_string, value TSRMLS_CC);
			if (PHALCON_IS_TRUE(full_placeholder)) {
				PHALCON_INIT_VAR(placeholder);
				PHALCON_CONCAT_SVS(placeholder, ":", numeric_place, ":");
			} else {
				PHALCON_INIT_NVAR(placeholder);
				PHALCON_CONCAT_SV(placeholder, ":", numeric_place);
			}
	
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("placeholder"), 1);
			phalcon_array_update_string(&expr_return, SL("value"), &placeholder, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 274 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(value);
			phalcon_array_fetch_string(&value, expr, SL("value"), PH_NOISY_CC);
			if (PHALCON_IS_TRUE(full_placeholder)) {
				PHALCON_INIT_NVAR(placeholder);
				PHALCON_CONCAT_SVS(placeholder, ":", value, ":");
			} else {
				PHALCON_INIT_NVAR(placeholder);
				PHALCON_CONCAT_SV(placeholder, ":", value);
			}
	
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("placeholder"), 1);
			phalcon_array_update_string(&expr_return, SL("value"), &placeholder, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 322 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("literal"), 1);
			add_assoc_stringl_ex(expr_return, SS("value"), SL("NULL"), 1);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 268 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
			add_assoc_stringl_ex(expr_return, SS("op"), SL("LIKE"), 1);
			phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 351 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
			add_assoc_stringl_ex(expr_return, SS("op"), SL("NOT LIKE"), 1);
			phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 33 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("unary-op"), 1);
			add_assoc_stringl_ex(expr_return, SS("op"), SL("NOT "), 1);
			phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 365 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("unary-op"), 1);
			add_assoc_stringl_ex(expr_return, SS("op"), SL(" IS NULL"), 1);
			phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 366 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("unary-op"), 1);
			add_assoc_stringl_ex(expr_return, SS("op"), SL(" IS NOT NULL"), 1);
			phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 315 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
			add_assoc_stringl_ex(expr_return, SS("op"), SL("IN"), 1);
			phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 323 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
			add_assoc_stringl_ex(expr_return, SS("op"), SL("NOT IN"), 1);
			phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 330 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("unary-op"), 1);
			add_assoc_stringl_ex(expr_return, SS("op"), SL("DISTINCT "), 1);
			phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 331 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(expr_return);
			array_init(expr_return);
			add_assoc_stringl_ex(expr_return, SS("type"), SL("binary-op"), 1);
			add_assoc_stringl_ex(expr_return, SS("op"), SL("BETWEEN"), 1);
			phalcon_array_update_string(&expr_return, SL("left"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&expr_return, SL("right"), &right, PH_COPY | PH_SEPARATE TSRMLS_CC);
			goto ph_end_0;
		}
	
		if (phalcon_compare_strict_long(expr_type, 350 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(expr_return);
			PHALCON_CALL_METHOD_PARAMS_1(expr_return, this_ptr, "_getfunctioncall", expr, PH_NO_CHECK);
			goto ph_end_0;
		}
	
		PHALCON_INIT_VAR(expression_message);
		PHALCON_CONCAT_SV(expression_message, "Unknown expression type ", expr_type);
	
		PHALCON_INIT_VAR(expression);
		object_init_ex(expression, phalcon_mvc_model_exception_ce);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(expression, "__construct", expression_message, PH_CHECK);
		phalcon_throw_exception(expression TSRMLS_CC);
		return;
	
		ph_end_0:
	
		RETURN_CCTOR(expr_return);
	}
	
	/** 
	 * Is a qualified column
	 */
	eval_int = phalcon_array_isset_string(expr, SS("domain"));
	if (eval_int) {
		PHALCON_INIT_VAR(expr_domain);
		PHALCON_CALL_METHOD_PARAMS_1(expr_domain, this_ptr, "_getqualified", expr, PH_NO_CHECK);
	
		RETURN_CCTOR(expr_domain);
	}
	
	/** 
	 * Is the expression doesn't have a type it's a list of nodes
	 */
	eval_int = phalcon_array_isset_long(expr, 0);
	if (eval_int) {
		PHALCON_INIT_VAR(list_items);
		array_init(list_items);
	
		if (!phalcon_valid_foreach(expr TSRMLS_CC)) {
			return;
		}
	
		ah0 = Z_ARRVAL_P(expr);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
		ph_cycle_start_1:
	
			if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
				goto ph_cycle_end_1;
			}
	
			PHALCON_GET_FOREACH_VALUE(expr_list_item);
	
			PHALCON_INIT_NVAR(expr_item);
			PHALCON_CALL_METHOD_PARAMS_1(expr_item, this_ptr, "_getexpression", expr_list_item, PH_NO_CHECK);
			phalcon_array_append(&list_items, expr_item, PH_SEPARATE TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_1;
	
		ph_cycle_end_1:
	
		PHALCON_INIT_NVAR(expr_return);
		array_init(expr_return);
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
	zval *source = NULL, *model_name = NULL, *sql_column_alias = NULL;
	zval *sql_column = NULL, *sql_aliases, *column_domain;
	zval *exception_message = NULL, *sql_aliases_models;
	zval *column_data, *sql_expr_column, *balias;
	zval *sql_alias;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &column) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(column, SS("type"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	
	PHALCON_INIT_VAR(sql_columns);
	array_init(sql_columns);
	
	/** 
	 * Check for select * (all)
	 */
	PHALCON_INIT_VAR(column_type);
	phalcon_array_fetch_string(&column_type, column, SL("type"), PH_NOISY_CC);
	if (phalcon_compare_strict_long(column_type, 352 TSRMLS_CC)) {
		PHALCON_INIT_VAR(models);
		phalcon_read_property(&models, this_ptr, SL("_models"), PH_NOISY_CC);
	
		if (!phalcon_valid_foreach(models TSRMLS_CC)) {
			return;
		}
	
		ah0 = Z_ARRVAL_P(models);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
		ph_cycle_start_0:
	
			if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
				goto ph_cycle_end_0;
			}
	
			PHALCON_GET_FOREACH_KEY(model_name, ah0, hp0);
			PHALCON_GET_FOREACH_VALUE(source);
	
			PHALCON_CPY_WRT(sql_column_alias, source);
	
			PHALCON_INIT_NVAR(sql_column);
			array_init(sql_column);
			add_assoc_stringl_ex(sql_column, SS("type"), SL("object"), 1);
			phalcon_array_update_string(&sql_column, SL("model"), &model_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&sql_column, SL("column"), &sql_column_alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&sql_columns, sql_column, PH_SEPARATE TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;
	
		ph_cycle_end_0:
	
	
		RETURN_CTOR(sql_columns);
	}
	
	eval_int = phalcon_array_isset_string(column, SS("column"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	
	/** 
	 * Check if selected column is qualified.*
	 */
	if (phalcon_compare_strict_long(column_type, 353 TSRMLS_CC)) {
		PHALCON_INIT_VAR(sql_aliases);
		phalcon_read_property(&sql_aliases, this_ptr, SL("_sqlAliases"), PH_NOISY_CC);
	
		/** 
		 * We only allow the alias.*
		 */
		PHALCON_INIT_VAR(column_domain);
		phalcon_array_fetch_string(&column_domain, column, SL("column"), PH_NOISY_CC);
		eval_int = phalcon_array_isset(sql_aliases, column_domain);
		if (!eval_int) {
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "Unknown table or alias '", column_domain, "' (2)");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
		}
	
		/** 
		 * Get the SQL alias if any
		 */
		PHALCON_INIT_VAR(source);
		phalcon_array_fetch(&source, sql_aliases, column_domain, PH_NOISY_CC);
		PHALCON_CPY_WRT(sql_column_alias, source);
	
		/** 
		 * Get the real source name
		 */
		PHALCON_INIT_VAR(sql_aliases_models);
		phalcon_read_property(&sql_aliases_models, this_ptr, SL("_sqlAliasesModels"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(model_name);
		phalcon_array_fetch(&model_name, sql_aliases_models, column_domain, PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(sql_column);
		array_init(sql_column);
		add_assoc_stringl_ex(sql_column, SS("type"), SL("object"), 1);
		phalcon_array_update_string(&sql_column, SL("model"), &model_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&sql_column, SL("column"), &sql_column_alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&sql_columns, sql_column, PH_SEPARATE TSRMLS_CC);
	
		RETURN_CTOR(sql_columns);
	}
	
	/** 
	 * Check for columns qualified and not qualified
	 */
	if (phalcon_compare_strict_long(column_type, 354 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(sql_column);
		array_init(sql_column);
		add_assoc_stringl_ex(sql_column, SS("type"), SL("scalar"), 1);
	
		PHALCON_INIT_VAR(column_data);
		phalcon_array_fetch_string(&column_data, column, SL("column"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(sql_expr_column);
		PHALCON_CALL_METHOD_PARAMS_1(sql_expr_column, this_ptr, "_getexpression", column_data, PH_NO_CHECK);
	
		/** 
		 * Create balias and sqlAlias
		 */
		eval_int = phalcon_array_isset_string(sql_expr_column, SS("balias"));
		if (eval_int) {
			PHALCON_INIT_VAR(balias);
			phalcon_array_fetch_string(&balias, sql_expr_column, SL("balias"), PH_NOISY_CC);
			phalcon_array_update_string(&sql_column, SL("balias"), &balias, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
			PHALCON_INIT_VAR(sql_alias);
			PHALCON_CALL_FUNC_PARAMS_1(sql_alias, "strtolower", balias);
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
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &manager, &qualified_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(qualified_name, SS("name"));
	if (eval_int) {
		PHALCON_INIT_VAR(model_name);
		phalcon_array_fetch_string(&model_name, qualified_name, SL("name"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(model);
		PHALCON_CALL_METHOD_PARAMS_1(model, manager, "load", model_name, PH_NO_CHECK);
	
		PHALCON_INIT_VAR(source);
		PHALCON_CALL_METHOD(source, model, "getsource", PH_NO_CHECK);
	
		PHALCON_INIT_VAR(schema);
		PHALCON_CALL_METHOD(schema, model, "getschema", PH_NO_CHECK);
		if (zend_is_true(schema)) {
			PHALCON_INIT_VAR(complete_source);
			array_init(complete_source);
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
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &manager, &join) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(join, SS("qualified"));
	if (eval_int) {
		PHALCON_INIT_VAR(qualified);
		phalcon_array_fetch_string(&qualified, join, SL("qualified"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(qualified_type);
		phalcon_array_fetch_string(&qualified_type, qualified, SL("type"), PH_NOISY_CC);
		if (phalcon_compare_strict_long(qualified_type, 355 TSRMLS_CC)) {
			PHALCON_INIT_VAR(model_name);
			phalcon_array_fetch_string(&model_name, qualified, SL("name"), PH_NOISY_CC);
	
			PHALCON_INIT_VAR(model);
			PHALCON_CALL_METHOD_PARAMS_1(model, manager, "load", model_name, PH_NO_CHECK);
	
			PHALCON_INIT_VAR(source);
			PHALCON_CALL_METHOD(source, model, "getsource", PH_NO_CHECK);
	
			PHALCON_INIT_VAR(schema);
			PHALCON_CALL_METHOD(schema, model, "getschema", PH_NO_CHECK);
	
			PHALCON_INIT_VAR(data);
			array_init(data);
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
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &join) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(join, SS("type"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	
	PHALCON_INIT_VAR(type);
	phalcon_array_fetch_string(&type, join, SL("type"), PH_NOISY_CC);
	
	if (phalcon_compare_strict_long(type, 360 TSRMLS_CC)) {
		PHALCON_INIT_VAR(join_type);
		ZVAL_STRING(join_type, "INNER", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 361 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(join_type);
		ZVAL_STRING(join_type, "LEFT", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 362 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(join_type);
		ZVAL_STRING(join_type, "RIGHT", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 363 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(join_type);
		ZVAL_STRING(join_type, "CROSS", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 364 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(join_type);
		ZVAL_STRING(join_type, "FULL OUTER", 1);
		goto ph_end_0;
	}
	
	PHALCON_INIT_VAR(exception_message);
	PHALCON_CONCAT_SV(exception_message, "Unknown join type ", type);
	PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
	return;
	
	ph_end_0:
	
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
	zval *pre_condition = NULL, *has_relations = NULL, *join_alias = NULL;
	zval *join_model = NULL, *sql_join_conditions = NULL, *relations = NULL;
	zval *fields = NULL, *referenced_fields = NULL, *model_alias = NULL;
	zval *left = NULL, *left_expr = NULL, *right = NULL, *right_expr = NULL, *sql_join_condition = NULL;
	zval *join_source = NULL, *sql_join = NULL;
	HashTable *ah0, *ah1, *ah2, *ah3;
	HashPosition hp0, hp1, hp2, hp3;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &select) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(models);
	phalcon_read_property(&models, this_ptr, SL("_models"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql_aliases);
	phalcon_read_property(&sql_aliases, this_ptr, SL("_sqlAliases"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql_aliases_models);
	phalcon_read_property(&sql_aliases_models, this_ptr, SL("_sqlAliasesModels"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql_models_aliases);
	phalcon_read_property(&sql_models_aliases, this_ptr, SL("_sqlModelsAliases"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql_aliases_models_instances);
	phalcon_read_property(&sql_aliases_models_instances, this_ptr, SL("_sqlAliasesModelsInstances"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(models_instances);
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
	
	PHALCON_INIT_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(joins);
	phalcon_array_fetch_string(&joins, select, SL("joins"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_long(joins, 0);
	if (!eval_int) {
		PHALCON_INIT_VAR(select_joins);
		array_init(select_joins);
		phalcon_array_append(&select_joins, joins, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(select_joins, joins);
	}
	
	
	if (!phalcon_valid_foreach(select_joins TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(select_joins);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
			goto ph_cycle_end_0;
		}
	
		PHALCON_GET_FOREACH_VALUE(join_item);
	
		PHALCON_INIT_NVAR(join_data);
		PHALCON_CALL_METHOD_PARAMS_2(join_data, this_ptr, "_getjoin", manager, join_item, PH_NO_CHECK);
	
		PHALCON_INIT_NVAR(source);
		phalcon_array_fetch_string(&source, join_data, SL("source"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(schema);
		phalcon_array_fetch_string(&schema, join_data, SL("schema"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(model);
		phalcon_array_fetch_string(&model, join_data, SL("model"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(model_name);
		phalcon_array_fetch_string(&model_name, join_data, SL("modelName"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(complete_source);
		array_init(complete_source);
		phalcon_array_append(&complete_source, source, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&complete_source, schema, PH_SEPARATE TSRMLS_CC);
	
		/** 
		 * Check join alias
		 */
		PHALCON_INIT_NVAR(join_type);
		PHALCON_CALL_METHOD_PARAMS_1(join_type, this_ptr, "_getjointype", join_item, PH_NO_CHECK);
		phalcon_array_update_zval(&join_types, model_name, &join_type, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
		/** 
		 * Process join alias
		 */
		eval_int = phalcon_array_isset_string(join_item, SS("alias"));
		if (eval_int) {
			PHALCON_INIT_NVAR(alias_expr);
			phalcon_array_fetch_string(&alias_expr, join_item, SL("alias"), PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(alias);
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
		goto ph_cycle_start_0;
	
	ph_cycle_end_0:
	
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
	
	ph_cycle_start_1:
	
		if (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS) {
			goto ph_cycle_end_1;
		}
	
		PHALCON_GET_FOREACH_VALUE(join_item);
	
		/** 
		 * Check for predefined conditions
		 */
		eval_int = phalcon_array_isset_string(join_item, SS("conditions"));
		if (eval_int) {
			PHALCON_INIT_NVAR(join_expr);
			phalcon_array_fetch_string(&join_expr, join_item, SL("conditions"), PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(pre_condition);
			PHALCON_CALL_METHOD_PARAMS_1(pre_condition, this_ptr, "_getexpression", join_expr, PH_NO_CHECK);
			phalcon_array_update_zval(&join_pre_condition, model_name, &pre_condition, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	
		zend_hash_move_forward_ex(ah1, &hp1);
		goto ph_cycle_start_1;
	
	ph_cycle_end_1:
	
	/** 
	 * Create join relationships dynamically
	 */
	PHALCON_INIT_NVAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	
	if (!phalcon_valid_foreach(from_models TSRMLS_CC)) {
		return;
	}
	
	ah2 = Z_ARRVAL_P(from_models);
	zend_hash_internal_pointer_reset_ex(ah2, &hp2);
	
	ph_cycle_start_2:
	
		if (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) != SUCCESS) {
			goto ph_cycle_end_2;
		}
	
		PHALCON_GET_FOREACH_KEY(model_name, ah2, hp2);
		PHALCON_GET_FOREACH_VALUE(source);
	
		PHALCON_INIT_NVAR(has_relations);
		ZVAL_BOOL(has_relations, 0);
	
		if (!phalcon_valid_foreach(join_models TSRMLS_CC)) {
			return;
		}
	
		ah3 = Z_ARRVAL_P(join_models);
		zend_hash_internal_pointer_reset_ex(ah3, &hp3);
	
		ph_cycle_start_3:
	
			if (zend_hash_get_current_data_ex(ah3, (void**) &hd, &hp3) != SUCCESS) {
				goto ph_cycle_end_3;
			}
	
			PHALCON_GET_FOREACH_KEY(join_model, ah3, hp3);
			PHALCON_GET_FOREACH_VALUE(join_alias);
	
			PHALCON_INIT_NVAR(sql_join_conditions);
			array_init(sql_join_conditions);
			eval_int = phalcon_array_isset(join_pre_condition, join_model);
			if (!eval_int) {
				/** 
				 * Check for relations between models
				 */
				PHALCON_INIT_NVAR(relations);
				PHALCON_CALL_METHOD_PARAMS_2(relations, manager, "getrelations", model_name, join_model, PH_NO_CHECK);
				if (PHALCON_IS_NOT_FALSE(relations)) {
					PHALCON_INIT_NVAR(fields);
					phalcon_array_fetch_string(&fields, relations, SL("fi"), PH_NOISY_CC);
	
					PHALCON_INIT_NVAR(referenced_fields);
					phalcon_array_fetch_string(&referenced_fields, relations, SL("rf"), PH_NOISY_CC);
					if (Z_TYPE_P(fields) == IS_ARRAY) { 
						PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Not implemented yet");
						return;
					} else {
						/** 
						 * Get the related model alias of the left part
						 */
						PHALCON_INIT_NVAR(model_alias);
						phalcon_array_fetch(&model_alias, sql_models_aliases, model_name, PH_NOISY_CC);
	
						/** 
						 * Create the left part of the expression
						 */
						PHALCON_INIT_NVAR(left);
						array_init(left);
						add_assoc_long_ex(left, SS("type"), 355);
						phalcon_array_update_string(&left, SL("domain"), &model_alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
						phalcon_array_update_string(&left, SL("name"), &fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
						PHALCON_INIT_NVAR(left_expr);
						PHALCON_CALL_METHOD_PARAMS_1(left_expr, this_ptr, "_getqualified", left, PH_NO_CHECK);
	
						/** 
						 * Get the related model alias of the right part
						 */
						PHALCON_INIT_NVAR(join_alias);
						phalcon_array_fetch(&join_alias, sql_models_aliases, join_model, PH_NOISY_CC);
	
						/** 
						 * Create the right part of the expression
						 */
						PHALCON_INIT_NVAR(right);
						array_init(right);
						add_assoc_stringl_ex(right, SS("type"), SL("qualified"), 1);
						phalcon_array_update_string(&right, SL("domain"), &join_alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
						phalcon_array_update_string(&right, SL("name"), &referenced_fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
						PHALCON_INIT_NVAR(right_expr);
						PHALCON_CALL_METHOD_PARAMS_1(right_expr, this_ptr, "_getqualified", right, PH_NO_CHECK);
	
						/** 
						 * Create a binary operation for the join conditions
						 */
						PHALCON_INIT_NVAR(sql_join_condition);
						array_init(sql_join_condition);
						add_assoc_stringl_ex(sql_join_condition, SS("type"), SL("binary-op"), 1);
						add_assoc_stringl_ex(sql_join_condition, SS("op"), SL("="), 1);
						phalcon_array_update_string(&sql_join_condition, SL("left"), &left_expr, PH_COPY | PH_SEPARATE TSRMLS_CC);
						phalcon_array_update_string(&sql_join_condition, SL("right"), &right_expr, PH_COPY | PH_SEPARATE TSRMLS_CC);
						phalcon_array_append(&sql_join_conditions, sql_join_condition, PH_SEPARATE TSRMLS_CC);
					}
				}
			} else {
				PHALCON_INIT_NVAR(pre_condition);
				phalcon_array_fetch(&pre_condition, join_pre_condition, join_model, PH_NOISY_CC);
				phalcon_array_append(&sql_join_conditions, pre_condition, PH_SEPARATE TSRMLS_CC);
			}
	
			PHALCON_INIT_NVAR(join_type);
			phalcon_array_fetch(&join_type, join_types, join_model, PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(join_source);
			phalcon_array_fetch(&join_source, join_sources, join_model, PH_NOISY_CC);
	
			/** 
			 * Final join representation
			 */
			PHALCON_INIT_NVAR(sql_join);
			array_init(sql_join);
			phalcon_array_update_string(&sql_join, SL("type"), &join_type, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&sql_join, SL("source"), &join_source, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&sql_join, SL("conditions"), &sql_join_conditions, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&sql_joins, sql_join, PH_SEPARATE TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah3, &hp3);
			goto ph_cycle_start_3;
	
		ph_cycle_end_3:
	
	
		zend_hash_move_forward_ex(ah2, &hp2);
		goto ph_cycle_start_2;
	
	ph_cycle_end_2:
	
	
	RETURN_CTOR(sql_joins);
}

/**
 * Returns a processed limit clause for a SELECT statement
 *
 * @param array $limit
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getLimitClause){

	zval *limit, *limit_expr;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &limit) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(limit_expr);
	PHALCON_CALL_METHOD_PARAMS_1(limit_expr, this_ptr, "_getexpression", limit, PH_NO_CHECK);
	
	RETURN_CCTOR(limit_expr);
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
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &order) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_long(order, 0);
	if (!eval_int) {
		PHALCON_INIT_VAR(order_columns);
		array_init(order_columns);
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
	
	ph_cycle_start_0:
	
		if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
			goto ph_cycle_end_0;
		}
	
		PHALCON_GET_FOREACH_VALUE(order_item);
	
		PHALCON_INIT_NVAR(order_column);
		phalcon_array_fetch_string(&order_column, order_item, SL("column"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(order_part_expr);
		PHALCON_CALL_METHOD_PARAMS_1(order_part_expr, this_ptr, "_getexpression", order_column, PH_NO_CHECK);
	
		/** 
		 * Check if the order has a predefined ordering mode
		 */
		eval_int = phalcon_array_isset_string(order_item, SS("sort"));
		if (eval_int) {
			PHALCON_INIT_NVAR(order_sort);
			phalcon_array_fetch_string(&order_sort, order_item, SL("sort"), PH_NOISY_CC);
			if (phalcon_compare_strict_long(order_sort, 327 TSRMLS_CC)) {
				PHALCON_INIT_NVAR(order_part_sort);
				array_init(order_part_sort);
				phalcon_array_append(&order_part_sort, order_part_expr, PH_SEPARATE TSRMLS_CC);
				add_next_index_stringl(order_part_sort, SL("ASC"), 1);
			} else {
				PHALCON_INIT_NVAR(order_part_sort);
				array_init(order_part_sort);
				phalcon_array_append(&order_part_sort, order_part_expr, PH_SEPARATE TSRMLS_CC);
				add_next_index_stringl(order_part_sort, SL("DESC"), 1);
			}
		} else {
			PHALCON_INIT_NVAR(order_part_sort);
			array_init(order_part_sort);
			phalcon_array_append(&order_part_sort, order_part_expr, PH_SEPARATE TSRMLS_CC);
		}
	
		phalcon_array_append(&order_parts, order_part_sort, PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
	
	ph_cycle_end_0:
	
	
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
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &group) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_long(group, 0);
	if (eval_int) {
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
	
		ph_cycle_start_0:
	
			if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
				goto ph_cycle_end_0;
			}
	
			PHALCON_GET_FOREACH_VALUE(group_item);
	
			PHALCON_INIT_NVAR(group_part_expr);
			PHALCON_CALL_METHOD_PARAMS_1(group_part_expr, this_ptr, "_getexpression", group_item, PH_NO_CHECK);
			phalcon_array_append(&group_parts, group_part_expr, PH_SEPARATE TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;
	
		ph_cycle_end_0:
		if(0){}
	
	} else {
		PHALCON_INIT_NVAR(group_part_expr);
		PHALCON_CALL_METHOD_PARAMS_1(group_part_expr, this_ptr, "_getexpression", group, PH_NO_CHECK);
	
		PHALCON_INIT_NVAR(group_parts);
		array_init(group_parts);
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
	zval *type = NULL, *sql_select, *where, *where_expr, *group_by;
	zval *sql_group, *having, *having_expr, *order;
	zval *sql_order, *limit;
	zval *r0 = NULL;
	HashTable *ah0, *ah1, *ah2;
	HashPosition hp0, hp1, hp2;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(ast);
	phalcon_read_property(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(select);
	phalcon_array_fetch_string(&select, ast, SL("select"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_string(select, SS("tables"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	
	eval_int = phalcon_array_isset_string(select, SS("columns"));
	if (!eval_int) {
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
	
	PHALCON_INIT_VAR(tables);
	phalcon_array_fetch_string(&tables, select, SL("tables"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_long(tables, 0);
	if (!eval_int) {
		PHALCON_INIT_VAR(selected_models);
		array_init(selected_models);
		phalcon_array_append(&selected_models, tables, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(selected_models, tables);
	}
	
	PHALCON_INIT_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(meta_data);
	phalcon_read_property(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
	
	/** 
	 * Processing selected columns
	 */
	
	if (!phalcon_valid_foreach(selected_models TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(selected_models);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
			goto ph_cycle_end_0;
		}
	
		PHALCON_GET_FOREACH_VALUE(selected_model);
	
		PHALCON_INIT_NVAR(qualified_name);
		phalcon_array_fetch_string(&qualified_name, selected_model, SL("qualifiedName"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(model_name);
		phalcon_array_fetch_string(&model_name, qualified_name, SL("name"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(model);
		PHALCON_CALL_METHOD_PARAMS_1(model, manager, "load", model_name, PH_NO_CHECK);
	
		/** 
		 * Define a complete schema/source
		 */
		PHALCON_INIT_NVAR(schema);
		PHALCON_CALL_METHOD(schema, model, "getschema", PH_NO_CHECK);
	
		PHALCON_INIT_NVAR(source);
		PHALCON_CALL_METHOD(source, model, "getsource", PH_NO_CHECK);
		if (zend_is_true(schema)) {
			PHALCON_INIT_NVAR(complete_source);
			array_init(complete_source);
			phalcon_array_append(&complete_source, source, PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&complete_source, schema, PH_SEPARATE TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(complete_source, source);
		}
	
		/** 
		 * If an alias is defined for a model the model cannot be referenced in the column
		 * list
		 */
		eval_int = phalcon_array_isset_string(selected_model, SS("alias"));
		if (eval_int) {
			PHALCON_INIT_NVAR(alias);
			phalcon_array_fetch_string(&alias, selected_model, SL("alias"), PH_NOISY_CC);
			eval_int = phalcon_array_isset(sql_aliases, alias);
			if (eval_int) {
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
				array_init(complete_source);
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
		goto ph_cycle_start_0;
	
	ph_cycle_end_0:
	
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
	eval_int = phalcon_array_isset_string(select, SS("joins"));
	if (eval_int) {
		PHALCON_INIT_VAR(r0);
		phalcon_array_fetch_string(&r0, select, SL("joins"), PH_NOISY_CC);
		if (phalcon_fast_count_ev(r0 TSRMLS_CC)) {
			PHALCON_INIT_VAR(sql_joins);
			PHALCON_CALL_METHOD_PARAMS_1(sql_joins, this_ptr, "_getjoins", select, PH_NO_CHECK);
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
	PHALCON_INIT_VAR(columns);
	phalcon_array_fetch_string(&columns, select, SL("columns"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_long(columns, 0);
	if (!eval_int) {
		PHALCON_INIT_VAR(select_columns);
		array_init(select_columns);
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
	
	ph_cycle_start_1:
	
		if (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS) {
			goto ph_cycle_end_1;
		}
	
		PHALCON_GET_FOREACH_VALUE(column);
	
		PHALCON_INIT_NVAR(sql_column_group);
		PHALCON_CALL_METHOD_PARAMS_1(sql_column_group, this_ptr, "_getselectcolumn", column, PH_NO_CHECK);
	
		if (!phalcon_valid_foreach(sql_column_group TSRMLS_CC)) {
			return;
		}
	
		ah2 = Z_ARRVAL_P(sql_column_group);
		zend_hash_internal_pointer_reset_ex(ah2, &hp2);
	
		ph_cycle_start_2:
	
			if (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) != SUCCESS) {
				goto ph_cycle_end_2;
			}
	
			PHALCON_GET_FOREACH_VALUE(sql_column);
	
			/** 
			 * If 'alias' is set, the user has defined a alias for the column
			 */
			eval_int = phalcon_array_isset_string(column, SS("alias"));
			if (eval_int) {
				PHALCON_INIT_NVAR(alias);
				phalcon_array_fetch_string(&alias, column, SL("alias"), PH_NOISY_CC);
				phalcon_array_update_string(&sql_column, SL("balias"), &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_zval(&sql_columns, alias, &sql_column, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_zval_bool(&sql_column_aliases, alias, 1, PH_SEPARATE TSRMLS_CC);
			} else {
				/** 
				 * 'balias' is the best alias selected for the column
				 */
				eval_int = phalcon_array_isset_string(sql_column, SS("balias"));
				if (eval_int) {
					PHALCON_INIT_NVAR(alias);
					phalcon_array_fetch_string(&alias, sql_column, SL("balias"), PH_NOISY_CC);
					phalcon_array_update_zval(&sql_columns, alias, &sql_column, PH_COPY | PH_SEPARATE TSRMLS_CC);
				} else {
					PHALCON_INIT_NVAR(type);
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
			goto ph_cycle_start_2;
	
		ph_cycle_end_2:
	
	
		zend_hash_move_forward_ex(ah1, &hp1);
		goto ph_cycle_start_1;
	
	ph_cycle_end_1:
	
	phalcon_update_property_zval(this_ptr, SL("_sqlColumnAliases"), sql_column_aliases TSRMLS_CC);
	
	/** 
	 * sql_select is the final prepared SELECT
	 */
	PHALCON_INIT_VAR(sql_select);
	array_init(sql_select);
	phalcon_array_update_string(&sql_select, SL("models"), &sql_models, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_select, SL("tables"), &sql_tables, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_select, SL("columns"), &sql_columns, PH_COPY | PH_SEPARATE TSRMLS_CC);
	if (phalcon_fast_count_ev(sql_joins TSRMLS_CC)) {
		phalcon_array_update_string(&sql_select, SL("joins"), &sql_joins, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	/** 
	 * Process WHERE clause if any
	 */
	eval_int = phalcon_array_isset_string(ast, SS("where"));
	if (eval_int) {
		PHALCON_INIT_VAR(where);
		phalcon_array_fetch_string(&where, ast, SL("where"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(where_expr);
		PHALCON_CALL_METHOD_PARAMS_1(where_expr, this_ptr, "_getexpression", where, PH_NO_CHECK);
		phalcon_array_update_string(&sql_select, SL("where"), &where_expr, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	/** 
	 * Process GROUP BY clause if any
	 */
	eval_int = phalcon_array_isset_string(ast, SS("groupBy"));
	if (eval_int) {
		PHALCON_INIT_VAR(group_by);
		phalcon_array_fetch_string(&group_by, ast, SL("groupBy"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(sql_group);
		PHALCON_CALL_METHOD_PARAMS_1(sql_group, this_ptr, "_getgroupclause", group_by, PH_NO_CHECK);
		phalcon_array_update_string(&sql_select, SL("group"), &sql_group, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	/** 
	 * Process HAVING clause if any
	 */
	eval_int = phalcon_array_isset_string(ast, SS("having"));
	if (eval_int) {
		PHALCON_INIT_VAR(having);
		phalcon_array_fetch_string(&having, ast, SL("having"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(having_expr);
		PHALCON_CALL_METHOD_PARAMS_1(having_expr, this_ptr, "_getexpression", having, PH_NO_CHECK);
		phalcon_array_update_string(&sql_select, SL("having"), &having_expr, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	/** 
	 * Process ORDER BY clause if any
	 */
	eval_int = phalcon_array_isset_string(ast, SS("orderBy"));
	if (eval_int) {
		PHALCON_INIT_VAR(order);
		phalcon_array_fetch_string(&order, ast, SL("orderBy"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(sql_order);
		PHALCON_CALL_METHOD_PARAMS_1(sql_order, this_ptr, "_getorderclause", order, PH_NO_CHECK);
		phalcon_array_update_string(&sql_select, SL("order"), &sql_order, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	/** 
	 * Process LIMIT clause if any
	 */
	eval_int = phalcon_array_isset_string(ast, SS("limit"));
	if (eval_int) {
		PHALCON_INIT_VAR(limit);
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

	zval *ast, *qualified_name, *model_name, *manager;
	zval *source, *sql_aliases, *not_quoting, *expr_values;
	zval *values, *expr_value = NULL, *expr_insert = NULL, *expr_type = NULL;
	zval *value = NULL, *sql_insert, *sql_fields, *fields;
	zval *field = NULL, *name = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(ast);
	phalcon_read_property(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_string(ast, SS("qualifiedName"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted INSERT AST");
		return;
	}
	
	eval_int = phalcon_array_isset_string(ast, SS("values"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted INSERT AST");
		return;
	}
	
	PHALCON_INIT_VAR(qualified_name);
	phalcon_array_fetch_string(&qualified_name, ast, SL("qualifiedName"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(model_name);
	phalcon_array_fetch_string(&model_name, qualified_name, SL("name"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(source);
	PHALCON_CALL_METHOD_PARAMS_2(source, this_ptr, "_gettable", manager, qualified_name, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(sql_aliases);
	array_init(sql_aliases);
	
	PHALCON_INIT_VAR(not_quoting);
	ZVAL_BOOL(not_quoting, 0);
	
	PHALCON_INIT_VAR(expr_values);
	array_init(expr_values);
	
	PHALCON_INIT_VAR(values);
	phalcon_array_fetch_string(&values, ast, SL("values"), PH_NOISY_CC);
	
	if (!phalcon_valid_foreach(values TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(values);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
			goto ph_cycle_end_0;
		}
	
		PHALCON_GET_FOREACH_VALUE(expr_value);
	
		PHALCON_INIT_NVAR(expr_insert);
		PHALCON_CALL_METHOD_PARAMS_3(expr_insert, this_ptr, "_getexpression", expr_value, sql_aliases, not_quoting, PH_NO_CHECK);
	
		PHALCON_INIT_NVAR(expr_type);
		phalcon_array_fetch_string(&expr_type, expr_value, SL("type"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(value);
		array_init(value);
		phalcon_array_update_string(&value, SL("type"), &expr_type, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&value, SL("value"), &expr_insert, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&expr_values, value, PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
	
	ph_cycle_end_0:
	
	PHALCON_INIT_VAR(sql_insert);
	array_init(sql_insert);
	phalcon_array_update_string(&sql_insert, SL("model"), &model_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_insert, SL("table"), &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
	eval_int = phalcon_array_isset_string(ast, SS("fields"));
	if (eval_int) {
		PHALCON_INIT_VAR(sql_fields);
		array_init(sql_fields);
	
		PHALCON_INIT_VAR(fields);
		phalcon_array_fetch_string(&fields, ast, SL("fields"), PH_NOISY_CC);
	
		if (!phalcon_valid_foreach(fields TSRMLS_CC)) {
			return;
		}
	
		ah1 = Z_ARRVAL_P(fields);
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	
		ph_cycle_start_1:
	
			if (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS) {
				goto ph_cycle_end_1;
			}
	
			PHALCON_GET_FOREACH_VALUE(field);
	
			PHALCON_INIT_NVAR(name);
			phalcon_array_fetch_string(&name, field, SL("name"), PH_NOISY_CC);
			phalcon_array_append(&sql_fields, name, PH_SEPARATE TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah1, &hp1);
			goto ph_cycle_start_1;
	
		ph_cycle_end_1:
	
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

	zval *ast, *update, *models, *sql_aliases, *sql_tables;
	zval *tables, *update_tables = NULL, *manager, *table = NULL;
	zval *qualified_name = NULL, *model_name = NULL, *source = NULL, *alias = NULL;
	zval *source_alias = NULL, *sql_fields, *sql_values;
	zval *values, *update_values = NULL, *not_quoting = NULL, *full_placeholder;
	zval *update_value = NULL, *column = NULL, *sql_column = NULL, *expr_column = NULL;
	zval *expr_value = NULL, *type = NULL, *value = NULL, *sql_update, *where;
	zval *where_expr, *limit, *sql_limit;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(ast);
	phalcon_read_property(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_string(ast, SS("update"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted UPDATE AST");
		return;
	}
	
	PHALCON_INIT_VAR(update);
	phalcon_array_fetch_string(&update, ast, SL("update"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_string(update, SS("tables"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted UPDATE AST");
		return;
	}
	
	eval_int = phalcon_array_isset_string(update, SS("values"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted UPDATE AST");
		return;
	}
	
	PHALCON_INIT_VAR(models);
	array_init(models);
	
	PHALCON_INIT_VAR(sql_aliases);
	array_init(sql_aliases);
	
	PHALCON_INIT_VAR(sql_tables);
	array_init(sql_tables);
	
	PHALCON_INIT_VAR(tables);
	phalcon_array_fetch_string(&tables, update, SL("tables"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_long(tables, 0);
	if (!eval_int) {
		PHALCON_INIT_VAR(update_tables);
		array_init(update_tables);
		phalcon_array_append(&update_tables, tables, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(update_tables, tables);
	}
	
	PHALCON_INIT_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	
	if (!phalcon_valid_foreach(update_tables TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(update_tables);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
			goto ph_cycle_end_0;
		}
	
		PHALCON_GET_FOREACH_VALUE(table);
	
		PHALCON_INIT_NVAR(qualified_name);
		phalcon_array_fetch_string(&qualified_name, table, SL("qualifiedName"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(model_name);
		phalcon_array_fetch_string(&model_name, qualified_name, SL("name"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(source);
		PHALCON_CALL_METHOD_PARAMS_2(source, this_ptr, "_gettable", manager, qualified_name, PH_NO_CHECK);
		eval_int = phalcon_array_isset_string(table, SS("alias"));
		if (eval_int) {
			PHALCON_INIT_NVAR(alias);
			phalcon_array_fetch_string(&alias, table, SL("alias"), PH_NOISY_CC);
			phalcon_array_update_zval(&sql_aliases, alias, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
			PHALCON_INIT_NVAR(source_alias);
			PHALCON_CONCAT_VSV(source_alias, source, " ", alias);
			phalcon_array_append(&sql_tables, source_alias, PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_update_zval(&sql_aliases, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&sql_tables, source, PH_SEPARATE TSRMLS_CC);
		}
	
		phalcon_array_append(&models, model_name, PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
	
	ph_cycle_end_0:
	
	PHALCON_INIT_VAR(sql_fields);
	array_init(sql_fields);
	
	PHALCON_INIT_VAR(sql_values);
	array_init(sql_values);
	
	PHALCON_INIT_VAR(values);
	phalcon_array_fetch_string(&values, update, SL("values"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_long(values, 0);
	if (!eval_int) {
		PHALCON_INIT_VAR(update_values);
		array_init(update_values);
		phalcon_array_append(&update_values, values, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(update_values, values);
	}
	
	PHALCON_INIT_VAR(not_quoting);
	ZVAL_BOOL(not_quoting, 0);
	
	PHALCON_INIT_VAR(full_placeholder);
	ZVAL_BOOL(full_placeholder, 1);
	
	if (!phalcon_valid_foreach(update_values TSRMLS_CC)) {
		return;
	}
	
	ah1 = Z_ARRVAL_P(update_values);
	zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	
	ph_cycle_start_1:
	
		if (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS) {
			goto ph_cycle_end_1;
		}
	
		PHALCON_GET_FOREACH_VALUE(update_value);
	
		PHALCON_INIT_NVAR(column);
		phalcon_array_fetch_string(&column, update_value, SL("column"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(sql_column);
		PHALCON_CALL_METHOD_PARAMS_4(sql_column, this_ptr, "_getexpression", column, sql_aliases, not_quoting, full_placeholder, PH_NO_CHECK);
		phalcon_array_append(&sql_fields, sql_column, PH_SEPARATE TSRMLS_CC);
	
		PHALCON_INIT_NVAR(expr_column);
		phalcon_array_fetch_string(&expr_column, update_value, SL("expr"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(expr_value);
		PHALCON_CALL_METHOD_PARAMS_4(expr_value, this_ptr, "_getexpression", expr_column, sql_aliases, not_quoting, full_placeholder, PH_NO_CHECK);
	
		PHALCON_INIT_NVAR(type);
		phalcon_array_fetch_string(&type, expr_column, SL("type"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(value);
		array_init(value);
		phalcon_array_update_string(&value, SL("type"), &type, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&value, SL("value"), &expr_value, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&sql_values, value, PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah1, &hp1);
		goto ph_cycle_start_1;
	
	ph_cycle_end_1:
	
	PHALCON_INIT_VAR(sql_update);
	array_init(sql_update);
	phalcon_array_update_string(&sql_update, SL("tables"), &sql_tables, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_update, SL("models"), &models, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_update, SL("fields"), &sql_fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_update, SL("values"), &sql_values, PH_COPY | PH_SEPARATE TSRMLS_CC);
	eval_int = phalcon_array_isset_string(ast, SS("where"));
	if (eval_int) {
		ZVAL_BOOL(not_quoting, 1);
	
		PHALCON_INIT_VAR(where);
		phalcon_array_fetch_string(&where, ast, SL("where"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(where_expr);
		PHALCON_CALL_METHOD_PARAMS_4(where_expr, this_ptr, "_getexpression", where, sql_aliases, not_quoting, full_placeholder, PH_NO_CHECK);
		phalcon_array_update_string(&sql_update, SL("where"), &where_expr, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(ast, SS("limit"));
	if (eval_int) {
		PHALCON_INIT_VAR(limit);
		phalcon_array_fetch_string(&limit, ast, SL("limit"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(sql_limit);
		PHALCON_CALL_METHOD_PARAMS_2(sql_limit, this_ptr, "_getlimitclause", limit, sql_aliases, PH_NO_CHECK);
		phalcon_array_update_string(&sql_update, SL("limit"), &sql_limit, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	
	RETURN_CTOR(sql_update);
}

/**
 * Analyzes a DELETE intermediate code and produces an array to be executed later
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareDelete){

	zval *ast, *delete, *models, *sql_aliases, *sql_tables;
	zval *tables, *delete_tables = NULL, *manager, *table = NULL;
	zval *qualified_name = NULL, *model_name = NULL, *source = NULL, *alias = NULL;
	zval *exception_message = NULL, *source_alias = NULL, *sql_delete;
	zval *not_quoting, *full_placeholder, *where;
	zval *where_expr, *limit, *sql_limit;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(ast);
	phalcon_read_property(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_string(ast, SS("delete"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted DELETE AST");
		return;
	}
	
	PHALCON_INIT_VAR(delete);
	phalcon_array_fetch_string(&delete, ast, SL("delete"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_string(delete, SS("tables"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted DELETE AST");
		return;
	}
	
	PHALCON_INIT_VAR(models);
	array_init(models);
	
	PHALCON_INIT_VAR(sql_aliases);
	array_init(sql_aliases);
	
	PHALCON_INIT_VAR(sql_tables);
	array_init(sql_tables);
	
	PHALCON_INIT_VAR(tables);
	phalcon_array_fetch_string(&tables, delete, SL("tables"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_long(tables, 0);
	if (!eval_int) {
		PHALCON_INIT_VAR(delete_tables);
		array_init(delete_tables);
		phalcon_array_append(&delete_tables, tables, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(delete_tables, tables);
	}
	
	PHALCON_INIT_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	
	if (!phalcon_valid_foreach(delete_tables TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(delete_tables);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
			goto ph_cycle_end_0;
		}
	
		PHALCON_GET_FOREACH_VALUE(table);
	
		PHALCON_INIT_NVAR(qualified_name);
		phalcon_array_fetch_string(&qualified_name, table, SL("qualifiedName"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(model_name);
		phalcon_array_fetch_string(&model_name, qualified_name, SL("name"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(source);
		PHALCON_CALL_METHOD_PARAMS_2(source, this_ptr, "_gettable", manager, qualified_name, PH_NO_CHECK);
		eval_int = phalcon_array_isset_string(table, SS("alias"));
		if (eval_int) {
			PHALCON_INIT_NVAR(alias);
			phalcon_array_fetch_string(&alias, table, SL("alias"), PH_NOISY_CC);
			eval_int = phalcon_array_isset(sql_aliases, alias);
			if (eval_int) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Alias \"", alias, " is already used");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
	
			phalcon_array_update_zval(&sql_aliases, alias, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
			PHALCON_INIT_NVAR(source_alias);
			PHALCON_CONCAT_VSV(source_alias, source, " ", alias);
			phalcon_array_append(&sql_tables, source_alias, PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_update_zval(&sql_aliases, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&sql_tables, source, PH_SEPARATE TSRMLS_CC);
		}
	
		phalcon_array_append(&models, model_name, PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
	
	ph_cycle_end_0:
	
	PHALCON_INIT_VAR(sql_delete);
	array_init(sql_delete);
	phalcon_array_update_string(&sql_delete, SL("tables"), &sql_tables, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_delete, SL("models"), &models, PH_COPY | PH_SEPARATE TSRMLS_CC);
	eval_int = phalcon_array_isset_string(ast, SS("where"));
	if (eval_int) {
		PHALCON_INIT_VAR(not_quoting);
		ZVAL_BOOL(not_quoting, 1);
	
		PHALCON_INIT_VAR(full_placeholder);
		ZVAL_BOOL(full_placeholder, 1);
	
		PHALCON_INIT_VAR(where);
		phalcon_array_fetch_string(&where, ast, SL("where"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(where_expr);
		PHALCON_CALL_METHOD_PARAMS_4(where_expr, this_ptr, "_getexpression", where, sql_aliases, not_quoting, full_placeholder, PH_NO_CHECK);
		phalcon_array_update_string(&sql_delete, SL("where"), &where_expr, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(ast, SS("limit"));
	if (eval_int) {
		PHALCON_INIT_VAR(limit);
		phalcon_array_fetch_string(&limit, ast, SL("limit"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(sql_limit);
		PHALCON_CALL_METHOD_PARAMS_2(sql_limit, this_ptr, "_getlimitclause", limit, sql_aliases, PH_NO_CHECK);
		phalcon_array_update_string(&sql_delete, SL("limit"), &sql_limit, PH_COPY | PH_SEPARATE TSRMLS_CC);
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

	zval *phql, *ast, *ir_phql = NULL, *type, *exception_message;
	int eval_int;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(phql);
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
		eval_int = phalcon_array_isset_string(ast, SS("type"));
		if (eval_int) {
			/** 
			 * Produce an independent database system representation
			 */
			PHALCON_INIT_VAR(type);
			phalcon_array_fetch_string(&type, ast, SL("type"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_type"), type TSRMLS_CC);
	
			if (phalcon_compare_strict_long(type, 309 TSRMLS_CC)) {
				PHALCON_CALL_METHOD(ir_phql, this_ptr, "_prepareselect", PH_NO_CHECK);
				goto ph_end_0;
			}
	
			if (phalcon_compare_strict_long(type, 306 TSRMLS_CC)) {
				PHALCON_INIT_NVAR(ir_phql);
				PHALCON_CALL_METHOD(ir_phql, this_ptr, "_prepareinsert", PH_NO_CHECK);
				goto ph_end_0;
			}
	
			if (phalcon_compare_strict_long(type, 300 TSRMLS_CC)) {
				PHALCON_INIT_NVAR(ir_phql);
				PHALCON_CALL_METHOD(ir_phql, this_ptr, "_prepareupdate", PH_NO_CHECK);
				goto ph_end_0;
			}
	
			if (phalcon_compare_strict_long(type, 303 TSRMLS_CC)) {
				PHALCON_INIT_NVAR(ir_phql);
				PHALCON_CALL_METHOD(ir_phql, this_ptr, "_preparedelete", PH_NO_CHECK);
				goto ph_end_0;
			}
	
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SV(exception_message, "Unknown statement ", type);
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
	
			ph_end_0:
			if(0){}
		}
	}
	
	if (Z_TYPE_P(ir_phql) == IS_NULL) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted AST");
		return;
	}
	
	
	RETURN_CCTOR(ir_phql);
}

PHP_METHOD(Phalcon_Mvc_Model_Query, setCache){


	
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
	zval *manager, *models_instances, *models, *number_models;
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
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &intermediate, &bind_params, &bind_types) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(intermediate);
	
	PHALCON_INIT_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(models_instances);
	phalcon_read_property(&models_instances, this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(models);
	phalcon_array_fetch_string(&models, intermediate, SL("models"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(number_models);
	phalcon_fast_count(number_models, models TSRMLS_CC);
	if (phalcon_compare_strict_long(number_models, 1 TSRMLS_CC)) {
		/** 
		 * Load first model if is not loaded
		 */
		PHALCON_INIT_VAR(model_name);
		phalcon_array_fetch_long(&model_name, models, 0, PH_NOISY_CC);
		eval_int = phalcon_array_isset(models_instances, model_name);
		if (!eval_int) {
			PHALCON_INIT_VAR(model);
			PHALCON_CALL_METHOD_PARAMS_1(model, manager, "load", model_name, PH_NO_CHECK);
		} else {
			PHALCON_INIT_NVAR(model);
			phalcon_array_fetch(&model, models_instances, model_name, PH_NOISY_CC);
		}
	
		PHALCON_INIT_VAR(connection);
		PHALCON_CALL_METHOD(connection, model, "getconnection", PH_NO_CHECK);
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
	
		ph_cycle_start_0:
	
			if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
				goto ph_cycle_end_0;
			}
	
			PHALCON_GET_FOREACH_VALUE(model_name);
	
			eval_int = phalcon_array_isset(models_instances, model_name);
			if (!eval_int) {
				PHALCON_INIT_NVAR(model);
				PHALCON_CALL_METHOD_PARAMS_1(model, manager, "load", model_name, PH_NO_CHECK);
			} else {
				PHALCON_INIT_NVAR(model);
				phalcon_array_fetch(&model, models_instances, model_name, PH_NOISY_CC);
			}
	
			PHALCON_INIT_NVAR(connection);
			PHALCON_CALL_METHOD(connection, model, "getconnection", PH_NO_CHECK);
	
			PHALCON_INIT_NVAR(type);
			PHALCON_CALL_METHOD(type, connection, "gettype", PH_NO_CHECK);
			phalcon_array_update_zval_bool(&connections, type, 1, PH_SEPARATE TSRMLS_CC);
	
			PHALCON_INIT_NVAR(connection_types);
			phalcon_fast_count(connection_types, connections TSRMLS_CC);
			if (phalcon_compare_strict_long(connection_types, 2 TSRMLS_CC)) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Cannot use models of different database systems in the same query");
				return;
			}
	
			phalcon_array_update_zval(&models_instances, model_name, &model, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;
	
		ph_cycle_end_0:
		if(0){}
	
	}
	
	PHALCON_INIT_VAR(columns);
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
	
	ph_cycle_start_1:
	
		if (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS) {
			goto ph_cycle_end_1;
		}
	
		PHALCON_GET_FOREACH_VALUE(column);
	
		PHALCON_INIT_NVAR(column_type);
		phalcon_array_fetch_string(&column_type, column, SL("type"), PH_NOISY_CC);
		if (PHALCON_COMPARE_STRING(column_type, "scalar")) {
			eval_int = phalcon_array_isset_string(column, SS("balias"));
			if (!eval_int) {
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
		goto ph_cycle_start_1;
	
	ph_cycle_end_1:
	
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
	
	PHALCON_INIT_VAR(meta_data);
	phalcon_read_property(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
	
	if (!phalcon_valid_foreach(columns TSRMLS_CC)) {
		return;
	}
	
	ALLOC_HASHTABLE(ah2);
	zend_hash_init(ah2, 0, NULL, NULL, 0);
	zend_hash_copy(ah2, Z_ARRVAL_P(columns), NULL, NULL, sizeof(zval*));
	zend_hash_internal_pointer_reset_ex(ah2, &hp2);
	
	ph_cycle_start_2:
	
		if (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) != SUCCESS) {
			goto ph_cycle_end_2;
		}
	
		PHALCON_GET_FOREACH_KEY(alias, ah2, hp2);
		PHALCON_GET_FOREACH_VALUE(column);
	
		PHALCON_INIT_NVAR(type);
		phalcon_array_fetch_string(&type, column, SL("type"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(sql_column);
		phalcon_array_fetch_string(&sql_column, column, SL("column"), PH_NOISY_CC);
		if (PHALCON_COMPARE_STRING(type, "object")) {
			PHALCON_INIT_NVAR(model_name);
			phalcon_array_fetch_string(&model_name, column, SL("model"), PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(instance);
			phalcon_array_fetch(&instance, models_instances, model_name, PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(attributes);
			PHALCON_CALL_METHOD_PARAMS_1(attributes, meta_data, "getattributes", instance, PH_NO_CHECK);
			if (PHALCON_IS_TRUE(is_complex)) {
				/** 
				 * If the resultset is complex we open every model into their columns
				 */
				PHALCON_INIT_NVAR(column_map);
				PHALCON_CALL_METHOD_PARAMS_1(column_map, meta_data, "getcolumnmap", instance, PH_NO_CHECK);
	
				if (!phalcon_valid_foreach(attributes TSRMLS_CC)) {
					return;
				}
	
				ah3 = Z_ARRVAL_P(attributes);
				zend_hash_internal_pointer_reset_ex(ah3, &hp3);
	
				ph_cycle_start_3:
	
					if (zend_hash_get_current_data_ex(ah3, (void**) &hd, &hp3) != SUCCESS) {
						goto ph_cycle_end_3;
					}
	
					PHALCON_GET_FOREACH_VALUE(attribute);
	
					PHALCON_INIT_NVAR(hidden_alias);
					PHALCON_CONCAT_SVSV(hidden_alias, "_", sql_column, "_", attribute);
	
					PHALCON_INIT_NVAR(column_alias);
					array_init(column_alias);
					phalcon_array_append(&column_alias, attribute, PH_SEPARATE TSRMLS_CC);
					phalcon_array_append(&column_alias, sql_column, PH_SEPARATE TSRMLS_CC);
					phalcon_array_append(&column_alias, hidden_alias, PH_SEPARATE TSRMLS_CC);
					phalcon_array_append(&select_columns, column_alias, PH_SEPARATE TSRMLS_CC);
	
					zend_hash_move_forward_ex(ah3, &hp3);
					goto ph_cycle_start_3;
	
				ph_cycle_end_3:
	
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
	
				ph_cycle_start_4:
	
					if (zend_hash_get_current_data_ex(ah4, (void**) &hd, &hp4) != SUCCESS) {
						goto ph_cycle_end_4;
					}
	
					PHALCON_GET_FOREACH_VALUE(attribute);
	
					PHALCON_INIT_NVAR(column_alias);
					array_init(column_alias);
					phalcon_array_append(&column_alias, attribute, PH_SEPARATE TSRMLS_CC);
					phalcon_array_append(&column_alias, sql_column, PH_SEPARATE TSRMLS_CC);
					phalcon_array_append(&select_columns, column_alias, PH_SEPARATE TSRMLS_CC);
	
					zend_hash_move_forward_ex(ah4, &hp4);
					goto ph_cycle_start_4;
	
				ph_cycle_end_4:
				if(0){}
	
			}
		} else {
			if (Z_TYPE_P(alias) == IS_LONG) {
				PHALCON_INIT_NVAR(column_alias);
				array_init(column_alias);
				phalcon_array_append(&column_alias, sql_column, PH_SEPARATE TSRMLS_CC);
				add_next_index_null(column_alias);
			} else {
				PHALCON_INIT_NVAR(column_alias);
				array_init(column_alias);
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
				eval_int = phalcon_array_isset_string(column, SS("sqlAlias"));
				if (eval_int) {
					PHALCON_INIT_NVAR(sql_alias);
					phalcon_array_fetch_string(&sql_alias, column, SL("sqlAlias"), PH_NOISY_CC);
					phalcon_array_update_zval(&simple_column_map, sql_alias, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
				} else {
					phalcon_array_update_zval(&simple_column_map, alias, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
				}
			}
		}
	
		zend_hash_move_forward_ex(ah2, &hp2);
		goto ph_cycle_start_2;
	
	ph_cycle_end_2:
	zend_hash_destroy(ah2);
	efree(ah2);
	
	phalcon_array_update_string(&intermediate, SL("columns"), &select_columns, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	/** 
	 * The corresponding SQL dialect generates the SQL statement based accordingly with
	 * the database system
	 */
	PHALCON_INIT_VAR(dialect);
	PHALCON_CALL_METHOD(dialect, connection, "getdialect", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(sql_select);
	PHALCON_CALL_METHOD_PARAMS_1(sql_select, dialect, "select", intermediate, PH_NO_CHECK);
	
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
	
		ph_cycle_start_5:
	
			if (zend_hash_get_current_data_ex(ah5, (void**) &hd, &hp5) != SUCCESS) {
				goto ph_cycle_end_5;
			}
	
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
			goto ph_cycle_start_5;
	
		ph_cycle_end_5:
		if(0){}
	
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
	
		ph_cycle_start_6:
	
			if (zend_hash_get_current_data_ex(ah6, (void**) &hd, &hp6) != SUCCESS) {
				goto ph_cycle_end_6;
			}
	
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
			goto ph_cycle_start_6;
	
		ph_cycle_end_6:
		if(0){}
	
	} else {
		PHALCON_CPY_WRT(processed_types, bind_types);
	}
	
	/** 
	 * Execute the query
	 */
	PHALCON_INIT_VAR(result);
	PHALCON_CALL_METHOD_PARAMS_3(result, connection, "query", sql_select, processed, processed_types, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(count);
	PHALCON_CALL_METHOD_PARAMS_1(count, result, "numrows", result, PH_NO_CHECK);
	if (zend_is_true(count)) {
		PHALCON_CPY_WRT(result_data, result);
	} else {
		PHALCON_INIT_VAR(result_data);
		ZVAL_BOOL(result_data, 0);
	}
	
	/** 
	 * Choose a resultset type
	 */
	PHALCON_INIT_VAR(cache);
	if (PHALCON_IS_FALSE(is_complex)) {
		if (PHALCON_IS_TRUE(is_simple_std)) {
			PHALCON_INIT_VAR(result_object);
			object_init_ex(result_object, phalcon_mvc_model_row_ce);
		} else {
			PHALCON_CPY_WRT(result_object, model);
	
			PHALCON_INIT_NVAR(simple_column_map);
			PHALCON_CALL_METHOD_PARAMS_1(simple_column_map, meta_data, "getcolumnmap", model, PH_NO_CHECK);
		}
	
		PHALCON_INIT_VAR(resultset);
		object_init_ex(resultset, phalcon_mvc_model_resultset_simple_ce);
		PHALCON_CALL_METHOD_PARAMS_4_NORETURN(resultset, "__construct", simple_column_map, result_object, result_data, cache, PH_CHECK);
	
		RETURN_CTOR(resultset);
	}
	
	PHALCON_INIT_NVAR(resultset);
	object_init_ex(resultset, phalcon_mvc_model_resultset_complex_ce);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(resultset, "__construct", columns, result_data, cache, PH_CHECK);
	
	RETURN_CTOR(resultset);
}

/**
 * Executes the INSERT intermediate representation producing a Phalcon\Mvc\Model\Query\Status
 *
 * @param array $intermediate
 * @param array $placeholders
 * @return Phalcon\Mvc\Model\Query\StatusInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeInsert){

	zval *intermediate, *placeholders, *model_name;
	zval *manager, *model, *connection, *meta_data;
	zval *attributes, *fields = NULL, *values, *number_fields;
	zval *number_values, *not_equal, *double_colon;
	zval *empty_string, *null_value, *not_exists;
	zval *insert_values, *value = NULL, *number = NULL, *type = NULL, *expr_value = NULL;
	zval *insert_value = NULL, *wildcard = NULL, *exception_message = NULL;
	zval *field_name = NULL, *attribute = NULL, *insert_model;
	zval *success, *status;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &intermediate, &placeholders) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(model_name);
	phalcon_array_fetch_string(&model_name, intermediate, SL("model"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(model);
	PHALCON_CALL_METHOD_PARAMS_1(model, manager, "load", model_name, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(connection);
	PHALCON_CALL_METHOD(connection, model, "getconnection", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(meta_data);
	phalcon_read_property(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(attributes);
	PHALCON_CALL_METHOD_PARAMS_1(attributes, meta_data, "getattributes", model, PH_NO_CHECK);
	eval_int = phalcon_array_isset_string(intermediate, SS("fields"));
	if (eval_int) {
		PHALCON_INIT_VAR(fields);
		phalcon_array_fetch_string(&fields, intermediate, SL("fields"), PH_NOISY_CC);
	} else {
		PHALCON_CPY_WRT(fields, attributes);
	}
	
	PHALCON_INIT_VAR(values);
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
	
	PHALCON_INIT_VAR(double_colon);
	ZVAL_STRING(double_colon, ":", 1);
	
	PHALCON_INIT_VAR(empty_string);
	ZVAL_STRING(empty_string, "", 1);
	
	PHALCON_INIT_VAR(null_value);
	
	PHALCON_INIT_VAR(not_exists);
	ZVAL_BOOL(not_exists, 0);
	
	PHALCON_INIT_VAR(insert_values);
	array_init(insert_values);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(model, "setforceexists", not_exists, PH_NO_CHECK);
	
	if (!phalcon_valid_foreach(values TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(values);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
			goto ph_cycle_end_0;
		}
	
		PHALCON_GET_FOREACH_KEY(number, ah0, hp0);
		PHALCON_GET_FOREACH_VALUE(value);
	
		PHALCON_INIT_NVAR(type);
		phalcon_array_fetch_string(&type, value, SL("type"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(expr_value);
		phalcon_array_fetch_string(&expr_value, value, SL("value"), PH_NOISY_CC);
	
		if (phalcon_compare_strict_long(type, 260 TSRMLS_CC)) {
			PHALCON_CPY_WRT(insert_value, expr_value);
			goto ph_end_1;
		}
	
		if (phalcon_compare_strict_long(type, 258 TSRMLS_CC)) {
			PHALCON_CPY_WRT(insert_value, expr_value);
			goto ph_end_1;
		}
	
		if (phalcon_compare_strict_long(type, 259 TSRMLS_CC)) {
			PHALCON_CPY_WRT(insert_value, expr_value);
			goto ph_end_1;
		}
	
		if (phalcon_compare_strict_long(type, 322 TSRMLS_CC)) {
			PHALCON_CPY_WRT(insert_value, null_value);
			goto ph_end_1;
		}
	
		if (phalcon_compare_strict_long(type, 274 TSRMLS_CC)) {
			if (Z_TYPE_P(placeholders) == IS_ARRAY) { 
				PHALCON_INIT_NVAR(wildcard);
				phalcon_fast_str_replace(wildcard, double_colon, empty_string, expr_value TSRMLS_CC);
				eval_int = phalcon_array_isset(placeholders, wildcard);
				if (eval_int) {
					PHALCON_INIT_NVAR(insert_value);
					phalcon_array_fetch(&insert_value, placeholders, wildcard, PH_NOISY_CC);
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
			goto ph_end_1;
		}
	
		PHALCON_INIT_NVAR(insert_value);
		object_init_ex(insert_value, phalcon_db_rawvalue_ce);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(insert_value, "__construct", expr_value, PH_CHECK);
		goto ph_end_1;
	
		ph_end_1:
	
		PHALCON_INIT_NVAR(field_name);
		phalcon_array_fetch(&field_name, fields, number, PH_NOISY_CC);
		phalcon_array_update_zval(&insert_values, field_name, &insert_value, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
	
	ph_cycle_end_0:
	
	
	if (!phalcon_valid_foreach(attributes TSRMLS_CC)) {
		return;
	}
	
	ah1 = Z_ARRVAL_P(attributes);
	zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	
	ph_cycle_start_2:
	
		if (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS) {
			goto ph_cycle_end_2;
		}
	
		PHALCON_GET_FOREACH_VALUE(attribute);
	
		eval_int = phalcon_array_isset(insert_values, attribute);
		if (!eval_int) {
			phalcon_array_update_zval(&insert_values, attribute, &null_value, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	
		zend_hash_move_forward_ex(ah1, &hp1);
		goto ph_cycle_start_2;
	
	ph_cycle_end_2:
	
	PHALCON_INIT_VAR(insert_model);
	PHALCON_CALL_STATIC_PARAMS_2(insert_model, "phalcon\\mvc\\model", "dumpresult", model, insert_values);
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD(success, insert_model, "create", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(status);
	object_init_ex(status, phalcon_mvc_model_query_status_ce);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(status, "__construct", success, insert_model, PH_CHECK);
	
	RETURN_CTOR(status);
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
	zval *models, *model_name, *manager, *model, *parameters;
	zval *where_conditions = NULL, *records, *double_colon;
	zval *empty_string, *fields, *values, *null_value;
	zval *record = NULL, *field = NULL, *number = NULL, *value = NULL, *type = NULL, *expr_value = NULL;
	zval *update_value = NULL, *wildcard = NULL, *exception_message = NULL;
	zval *success = NULL, *status = NULL;
	zval *r0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &intermediate, &bind_params, &bind_types) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(models);
	phalcon_array_fetch_string(&models, intermediate, SL("models"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_long(models, 1);
	if (eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Updating several models at the same time is still not supported");
		return;
	}
	
	PHALCON_INIT_VAR(model_name);
	phalcon_array_fetch_long(&model_name, models, 0, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(model);
	PHALCON_CALL_METHOD_PARAMS_1(model, manager, "load", model_name, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(parameters);
	array_init(parameters);
	eval_int = phalcon_array_isset_string(intermediate, SS("where"));
	if (eval_int) {
		PHALCON_INIT_VAR(where_conditions);
		phalcon_array_fetch_string(&where_conditions, intermediate, SL("where"), PH_NOISY_CC);
		phalcon_array_update_string(&parameters, SL("conditions"), &where_conditions, PH_COPY | PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_INIT_NVAR(where_conditions);
	}
	
	if (Z_TYPE_P(bind_params) == IS_ARRAY) { 
		phalcon_array_update_string(&parameters, SL("bind"), &bind_params, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	if (Z_TYPE_P(bind_types) == IS_ARRAY) { 
		phalcon_array_update_string(&parameters, SL("bindTypes"), &bind_types, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(records);
	PHALCON_CALL_METHOD_PARAMS_1(records, model, "find", parameters, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(double_colon);
	ZVAL_STRING(double_colon, ":", 1);
	
	PHALCON_INIT_VAR(empty_string);
	ZVAL_STRING(empty_string, "", 1);
	
	PHALCON_INIT_VAR(fields);
	phalcon_array_fetch_string(&fields, intermediate, SL("fields"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(values);
	phalcon_array_fetch_string(&values, intermediate, SL("values"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(null_value);
	PHALCON_CALL_METHOD_NORETURN(records, "rewind", PH_NO_CHECK);
	ph_cycle_start_0:
	
		PHALCON_INIT_NVAR(r0);
		PHALCON_CALL_METHOD(r0, records, "valid", PH_NO_CHECK);
		if (PHALCON_IS_NOT_TRUE(r0)) {
			goto ph_cycle_end_0;
		}
		PHALCON_INIT_NVAR(record);
		PHALCON_CALL_METHOD(record, records, "current", PH_NO_CHECK);
	
		if (!phalcon_valid_foreach(fields TSRMLS_CC)) {
			return;
		}
	
		ah0 = Z_ARRVAL_P(fields);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
		ph_cycle_start_1:
	
			if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
				goto ph_cycle_end_1;
			}
	
			PHALCON_GET_FOREACH_KEY(number, ah0, hp0);
			PHALCON_GET_FOREACH_VALUE(field);
	
			PHALCON_INIT_NVAR(value);
			phalcon_array_fetch(&value, values, number, PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(type);
			phalcon_array_fetch_string(&type, value, SL("type"), PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(expr_value);
			phalcon_array_fetch_string(&expr_value, value, SL("value"), PH_NOISY_CC);
	
			if (phalcon_compare_strict_long(type, 260 TSRMLS_CC)) {
				PHALCON_CPY_WRT(update_value, expr_value);
				goto ph_end_2;
			}
	
			if (phalcon_compare_strict_long(type, 258 TSRMLS_CC)) {
				PHALCON_CPY_WRT(update_value, expr_value);
				goto ph_end_2;
			}
	
			if (phalcon_compare_strict_long(type, 259 TSRMLS_CC)) {
				PHALCON_CPY_WRT(update_value, expr_value);
				goto ph_end_2;
			}
	
			if (phalcon_compare_strict_long(type, 322 TSRMLS_CC)) {
				PHALCON_CPY_WRT(update_value, null_value);
				goto ph_end_2;
			}
	
			if (phalcon_compare_strict_long(type, 274 TSRMLS_CC)) {
				if (Z_TYPE_P(bind_params) == IS_ARRAY) { 
					PHALCON_INIT_NVAR(wildcard);
					phalcon_fast_str_replace(wildcard, double_colon, empty_string, expr_value TSRMLS_CC);
					eval_int = phalcon_array_isset(bind_params, wildcard);
					if (eval_int) {
						PHALCON_INIT_NVAR(update_value);
						phalcon_array_fetch(&update_value, bind_params, wildcard, PH_NOISY_CC);
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
				goto ph_end_2;
			}
	
			PHALCON_INIT_NVAR(update_value);
			object_init_ex(update_value, phalcon_db_rawvalue_ce);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(update_value, "__construct", expr_value, PH_CHECK);
			goto ph_end_2;
	
			ph_end_2:
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(record, "writeattribute", field, update_value, PH_NO_CHECK);
	
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_1;
	
		ph_cycle_end_1:
	
		PHALCON_INIT_NVAR(success);
		PHALCON_CALL_METHOD(success, record, "update", PH_NO_CHECK);
		if (PHALCON_IS_FALSE(success)) {
			PHALCON_INIT_NVAR(status);
			object_init_ex(status, phalcon_mvc_model_query_status_ce);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(status, "__construct", success, record, PH_CHECK);
	
			RETURN_CTOR(status);
		}
	
		PHALCON_CALL_METHOD_NORETURN(records, "next", PH_NO_CHECK);
		goto ph_cycle_start_0;
	ph_cycle_end_0:
	
	PHALCON_INIT_NVAR(success);
	ZVAL_BOOL(success, 1);
	
	PHALCON_INIT_NVAR(status);
	object_init_ex(status, phalcon_mvc_model_query_status_ce);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(status, "__construct", success, null_value, PH_CHECK);
	
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
	zval *models, *model_name, *manager, *model, *parameters;
	zval *where_conditions = NULL, *records, *record = NULL, *success = NULL;
	zval *status = NULL, *null_value;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &intermediate, &bind_params, &bind_types) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(models);
	phalcon_array_fetch_string(&models, intermediate, SL("models"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_long(models, 1);
	if (eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Updating several models at the same time is still not supported");
		return;
	}
	
	PHALCON_INIT_VAR(model_name);
	phalcon_array_fetch_long(&model_name, models, 0, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(model);
	PHALCON_CALL_METHOD_PARAMS_1(model, manager, "load", model_name, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(parameters);
	array_init(parameters);
	eval_int = phalcon_array_isset_string(intermediate, SS("where"));
	if (eval_int) {
		PHALCON_INIT_VAR(where_conditions);
		phalcon_array_fetch_string(&where_conditions, intermediate, SL("where"), PH_NOISY_CC);
		phalcon_array_update_string(&parameters, SL("conditions"), &where_conditions, PH_COPY | PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_INIT_NVAR(where_conditions);
	}
	
	if (Z_TYPE_P(bind_params) == IS_ARRAY) { 
		phalcon_array_update_string(&parameters, SL("bind"), &bind_params, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	if (Z_TYPE_P(bind_types) == IS_ARRAY) { 
		phalcon_array_update_string(&parameters, SL("bindTypes"), &bind_types, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(records);
	PHALCON_CALL_METHOD_PARAMS_1(records, model, "find", parameters, PH_NO_CHECK);
	PHALCON_CALL_METHOD_NORETURN(records, "rewind", PH_NO_CHECK);
	ph_cycle_start_0:
	
		PHALCON_INIT_NVAR(r0);
		PHALCON_CALL_METHOD(r0, records, "valid", PH_NO_CHECK);
		if (PHALCON_IS_NOT_TRUE(r0)) {
			goto ph_cycle_end_0;
		}
		PHALCON_INIT_NVAR(record);
		PHALCON_CALL_METHOD(record, records, "current", PH_NO_CHECK);
	
		PHALCON_INIT_NVAR(success);
		PHALCON_CALL_METHOD(success, record, "delete", PH_NO_CHECK);
		if (PHALCON_IS_FALSE(success)) {
			PHALCON_INIT_NVAR(status);
			object_init_ex(status, phalcon_mvc_model_query_status_ce);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(status, "__construct", success, record, PH_CHECK);
	
			RETURN_CTOR(status);
		}
	
		PHALCON_CALL_METHOD_NORETURN(records, "next", PH_NO_CHECK);
		goto ph_cycle_start_0;
	ph_cycle_end_0:
	
	PHALCON_INIT_NVAR(success);
	ZVAL_BOOL(success, 1);
	
	PHALCON_INIT_VAR(null_value);
	ZVAL_BOOL(null_value, 1);
	
	PHALCON_INIT_NVAR(status);
	object_init_ex(status, phalcon_mvc_model_query_status_ce);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(status, "__construct", success, null_value, PH_CHECK);
	
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

	zval *bind_params = NULL, *bind_types = NULL, *intermediate;
	zval *type, *result = NULL, *exception_message;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &bind_params, &bind_types) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!bind_params) {
		PHALCON_INIT_NVAR(bind_params);
	}
	
	if (!bind_types) {
		PHALCON_INIT_NVAR(bind_types);
	}
	
	PHALCON_INIT_VAR(intermediate);
	PHALCON_CALL_METHOD(intermediate, this_ptr, "parse", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(type);
	phalcon_read_property(&type, this_ptr, SL("_type"), PH_NOISY_CC);
	
	if (phalcon_compare_strict_long(type, 309 TSRMLS_CC)) {
		PHALCON_INIT_VAR(result);
		PHALCON_CALL_METHOD_PARAMS_3(result, this_ptr, "_executeselect", intermediate, bind_params, bind_types, PH_NO_CHECK);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 306 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(result);
		PHALCON_CALL_METHOD_PARAMS_3(result, this_ptr, "_executeinsert", intermediate, bind_params, bind_types, PH_NO_CHECK);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 300 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(result);
		PHALCON_CALL_METHOD_PARAMS_3(result, this_ptr, "_executeupdate", intermediate, bind_params, bind_types, PH_NO_CHECK);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 303 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(result);
		PHALCON_CALL_METHOD_PARAMS_3(result, this_ptr, "_executedelete", intermediate, bind_params, bind_types, PH_NO_CHECK);
		goto ph_end_0;
	}
	
	PHALCON_INIT_VAR(exception_message);
	PHALCON_CONCAT_SV(exception_message, "Unknown statement ", type);
	PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
	return;
	
	ph_end_0:
	
	RETURN_CCTOR(result);
}

