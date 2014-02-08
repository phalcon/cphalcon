
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
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/hash.h"
#include "ext/spl/spl_exceptions.h"
#include "phalcon/mvc/model/query/scanner.h"
#include "phalcon/mvc/model/query/phql.h"


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
 * $result = manager->executeQuery($phql, array(
 *   "name": "Lamborghini"
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
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, Query, phalcon, mvc_model_query, phalcon_mvc_model_query_method_entry, 0);

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

	zend_class_implements(phalcon_mvc_model_query_ce TSRMLS_CC, 1, phalcon_mvc_model_queryinterface_ce);
	zend_class_implements(phalcon_mvc_model_query_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);

	return SUCCESS;

}

/**
 * Sets the dependency injection container
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setDI) {

	zval *dependencyInjector, *manager, *metaData, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dependencyInjector);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "modelsManager", 1);
	ZEPHIR_INIT_VAR(manager);
	zephir_call_method_p1(manager, dependencyInjector, "getshared", _0);
	if ((Z_TYPE_P(manager) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Injected service 'modelsManager' is invalid");
		return;
	}
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "modelsMetadata", 1);
	ZEPHIR_INIT_VAR(metaData);
	zephir_call_method_p1(metaData, dependencyInjector, "getshared", _0);
	if ((Z_TYPE_P(metaData) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Injected service 'modelsMetaData' is invalid");
		return;
	}
	zephir_update_property_this(this_ptr, SL("_manager"), manager TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_metaData"), metaData TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the dependency injection container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Tells to the query if only the first row in the resultset must be returned
 *
 * @param boolean uniqueRow
 * @return Phalcon\Mvc\Model\Query
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setUniqueRow) {

	zval *uniqueRow_param = NULL;
	zend_bool uniqueRow;

	zephir_fetch_params(0, 1, 0, &uniqueRow_param);

		uniqueRow = zephir_get_boolval(uniqueRow_param);


	zephir_update_property_this(this_ptr, SL("_uniqueRow"), uniqueRow ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Check if the query is programmed to get only the first row in the resultset
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getUniqueRow) {


	RETURN_MEMBER(this_ptr, "_uniqueRow");

}

/**
 * Replaces the model's name to its source name in a qualifed-name expression
 *
 * @param array expr
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getQualified) {

	zend_function *_8 = NULL;
	HashTable *_4;
	HashPosition _3;
	int number;
	zend_bool hasModel;
	zval *expr, *columnName, *sqlColumnAliases, *metaData, *sqlAliases, *source = NULL, *sqlAliasesModelsInstances, *realColumnName = NULL, *columnDomain, *model = NULL, *models, *columnMap = NULL, *_0 = NULL, *_1, *_2 = NULL, **_5, *_6 = NULL, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr);



	ZEPHIR_OBS_VAR(columnName);
	zephir_array_fetch_string(&columnName, expr, SL("name"), PH_NOISY TSRMLS_CC);
	ZEPHIR_OBS_VAR(sqlColumnAliases);
	zephir_read_property_this(&sqlColumnAliases, this_ptr, SL("_sqlColumnAliases"), PH_NOISY_CC);
	if (zephir_array_isset(sqlColumnAliases, columnName)) {
		array_init_size(return_value, 3);
		add_assoc_stringl_ex(return_value, SS("type"), SL("qualified"), 1);
		zephir_array_update_string(&return_value, SL("name"), &columnName, PH_COPY | PH_SEPARATE);
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(metaData);
	zephir_read_property_this(&metaData, this_ptr, SL("_metaData"), PH_NOISY_CC);
	if (zephir_array_isset_string(expr, SS("domain"))) {
		ZEPHIR_OBS_VAR(sqlAliases);
		zephir_read_property_this(&sqlAliases, this_ptr, SL("_sqlAliases"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(columnDomain);
		zephir_array_fetch_string(&columnDomain, expr, SL("domain"), PH_NOISY TSRMLS_CC);
		ZEPHIR_OBS_VAR(source);
		if (!(zephir_array_isset_fetch(&source, sqlAliases, columnDomain, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(_0);
			object_init_ex(_0, phalcon_mvc_model_exception_ce);
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_2);
			ZEPHIR_CONCAT_SVSV(_2, "Unknown model or alias '", columnDomain, "' (1), when preparing: ", _1);
			zephir_call_method_p1_noret(_0, "__construct", _2);
			zephir_throw_exception(_0 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(columnMap);
		if (ZEPHIR_GLOBAL(orm).column_renaming) {
			ZEPHIR_OBS_VAR(sqlAliasesModelsInstances);
			zephir_read_property_this(&sqlAliasesModelsInstances, this_ptr, SL("_sqlAliasesModelsInstances"), PH_NOISY_CC);
			ZEPHIR_OBS_VAR(model);
			if (!(zephir_array_isset_fetch(&model, sqlAliasesModelsInstances, columnDomain, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_LNVAR(_0);
				object_init_ex(_0, phalcon_mvc_model_exception_ce);
				_1 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_2);
				ZEPHIR_CONCAT_SVSV(_2, "There is no model related to model or alias '", columnDomain, "', when executing: ", _1);
				zephir_call_method_p1_noret(_0, "__construct", _2);
				zephir_throw_exception(_0 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_call_method_p1(columnMap, metaData, "getreversecolumnmap", model);
		} else {
			ZVAL_NULL(columnMap);
		}
		if ((Z_TYPE_P(columnMap) == IS_ARRAY)) {
			ZEPHIR_OBS_VAR(realColumnName);
			if (!(zephir_array_isset_fetch(&realColumnName, columnMap, columnName, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_LNVAR(_0);
				object_init_ex(_0, phalcon_mvc_model_exception_ce);
				_1 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_2);
				ZEPHIR_CONCAT_SVSVSV(_2, "Column '", columnName, "' doesn't belong to the model or alias '", columnDomain, "', when executing: ", _1);
				zephir_call_method_p1_noret(_0, "__construct", _2);
				zephir_throw_exception(_0 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(realColumnName, columnName);
		}
	} else {
		number = 0;
		hasModel = 0;
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
		zephir_is_iterable(_1, &_4, &_3, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
			; zend_hash_move_forward_ex(_4, &_3)
		) {
			ZEPHIR_GET_HVALUE(model, _5);
			ZEPHIR_INIT_NVAR(_6);
			zephir_call_method_p2(_6, metaData, "hasattribute", model, columnName);
			if (zephir_is_true(_6)) {
				number++;
				if ((number > 1)) {
					ZEPHIR_INIT_LNVAR(_0);
					object_init_ex(_0, phalcon_mvc_model_exception_ce);
					_7 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
					ZEPHIR_INIT_LNVAR(_2);
					ZEPHIR_CONCAT_SVSV(_2, "The column '", columnName, "' is ambiguous, when preparing: ", _7);
					zephir_call_method_p1_cache_noret(_0, "__construct", &_8, _2);
					zephir_throw_exception(_0 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				hasModel = zephir_is_true(model);
			}
		}
		if ((hasModel == 0)) {
			ZEPHIR_INIT_LNVAR(_0);
			object_init_ex(_0, phalcon_mvc_model_exception_ce);
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
			ZEPHIR_INIT_LNVAR(_2);
			ZEPHIR_CONCAT_SVSV(_2, "Column '", columnName, "' doesn't belong to any of the selected models (1), when preparing: ", _1);
			zephir_call_method_p1_noret(_0, "__construct", _2);
			zephir_throw_exception(_0 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_VAR(models);
		zephir_read_property_this(&models, this_ptr, SL("_models"), PH_NOISY_CC);
		if ((Z_TYPE_P(models) != IS_ARRAY)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The models list was not loaded correctly");
			return;
		}
		ZEPHIR_OBS_NVAR(source);
		ZEPHIR_INIT_NVAR(_6);
		zephir_get_class(_6, (hasModel ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)), 0 TSRMLS_CC);
		if (!(zephir_array_isset_fetch(&source, models, _6, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_LNVAR(_0);
			object_init_ex(_0, phalcon_mvc_model_exception_ce);
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
			ZEPHIR_INIT_LNVAR(_2);
			ZEPHIR_CONCAT_SVSV(_2, "Column '", columnName, "' doesn't belong to any of the selected models (2), when preparing: ", _1);
			zephir_call_method_p1_noret(_0, "__construct", _2);
			zephir_throw_exception(_0 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(columnMap);
		if (ZEPHIR_GLOBAL(orm).column_renaming) {
			zephir_call_method_p1(columnMap, metaData, "getreversecolumnmap", (hasModel ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
		} else {
			ZVAL_NULL(columnMap);
		}
		if ((Z_TYPE_P(columnMap) == IS_ARRAY)) {
			ZEPHIR_OBS_NVAR(realColumnName);
			if (!(zephir_array_isset_fetch(&realColumnName, columnMap, columnName, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_LNVAR(_0);
				object_init_ex(_0, phalcon_mvc_model_exception_ce);
				_1 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_2);
				ZEPHIR_CONCAT_SVSV(_2, "Column '", columnName, "' doesn't belong to any of the selected models (3), when preparing: ", _1);
				zephir_call_method_p1_noret(_0, "__construct", _2);
				zephir_throw_exception(_0 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(realColumnName, columnName);
		}
	}
	array_init_size(return_value, 7);
	add_assoc_stringl_ex(return_value, SS("type"), SL("qualified"), 1);
	zephir_array_update_string(&return_value, SL("domain"), &source, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("name"), &realColumnName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("balias"), &columnName, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * Resolves a expression in a single call argument
 *
 * @param array argument
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getCallArgument) {

	zval *argument, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &argument);



	zephir_array_fetch_string(&_0, argument, SL("type"), PH_NOISY | PH_READONLY TSRMLS_CC);
	if (ZEPHIR_IS_LONG(_0, 352)) {
		array_init_size(return_value, 2);
		add_assoc_stringl_ex(return_value, SS("type"), SL("all"), 1);
		RETURN_MM();
	}
	zephir_call_method_p1(return_value, this_ptr, "_getexpression", argument);
	RETURN_MM();

}

/**
 * Resolves a expression in a single call argument
 *
 * @param array expr
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getFunctionCall) {

	zend_function *_4 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *expr, *arguments, *argument = NULL, *functionArgs, **_2, *_3 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr);



	ZEPHIR_OBS_VAR(arguments);
	if (zephir_array_isset_string_fetch(&arguments, expr, SS("arguments"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(functionArgs);
		if (zephir_array_isset_long(arguments, 0)) {
			array_init(functionArgs);
			zephir_is_iterable(arguments, &_1, &_0, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
				; zend_hash_move_forward_ex(_1, &_0)
			) {
				ZEPHIR_GET_HVALUE(argument, _2);
				ZEPHIR_INIT_NVAR(_3);
				zephir_call_method_p1_cache(_3, this_ptr, "_getcallargument", &_4, argument);
				zephir_array_append(&functionArgs, _3, PH_SEPARATE);
			}
		} else {
			array_init_size(functionArgs, 2);
			ZEPHIR_INIT_NVAR(_3);
			zephir_call_method_p1(_3, this_ptr, "_getcallargument", arguments);
			zephir_array_fast_append(functionArgs, _3);
		}
		array_init_size(return_value, 5);
		add_assoc_stringl_ex(return_value, SS("type"), SL("functionCall"), 1);
		ZEPHIR_OBS_VAR(_5);
		zephir_array_fetch_string(&_5, expr, SL("name"), PH_NOISY TSRMLS_CC);
		zephir_array_update_string(&return_value, SL("name"), &_5, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&return_value, SL("arguments"), &functionArgs, PH_COPY | PH_SEPARATE);
		RETURN_MM();
	}
	array_init_size(return_value, 3);
	add_assoc_stringl_ex(return_value, SS("type"), SL("functionCall"), 1);
	ZEPHIR_OBS_NVAR(_5);
	zephir_array_fetch_string(&_5, expr, SL("name"), PH_NOISY TSRMLS_CC);
	zephir_array_update_string(&return_value, SL("name"), &_5, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * Resolves an expression from its intermediate code into a string
 *
 * @param array expr
 * @param boolean quoting
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getExpression) {

	zend_function *_10 = NULL;
	HashTable *_8;
	HashPosition _7;
	zend_bool quoting, tempNotQuoting;
	zval *expr, *quoting_param = NULL, *exprType, *exprLeft, *exprRight, *left, *right, *listItems, *exprListItem = NULL, *exprReturn = NULL, *value, *escapedValue = NULL, *exprValue = NULL, *_0 = NULL, *_1 = NULL, *_2, _3, _4, *_5 = NULL, *_6, **_9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expr, &quoting_param);

	if (!quoting_param) {
		quoting = 1;
	} else {
		quoting = zephir_get_boolval(quoting_param);
	}


	ZEPHIR_OBS_VAR(exprType);
	if (zephir_array_isset_string_fetch(&exprType, expr, SS("type"), 0 TSRMLS_CC)) {
		tempNotQuoting = 1;
		ZEPHIR_OBS_VAR(exprLeft);
		if (zephir_array_isset_string_fetch(&exprLeft, expr, SS("left"), 0 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(left);
			zephir_call_method_p2(left, this_ptr, "_getexpression", exprLeft, (tempNotQuoting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
		}
		ZEPHIR_OBS_VAR(exprRight);
		if (zephir_array_isset_string_fetch(&exprRight, expr, SS("right"), 0 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(right);
			zephir_call_method_p2(right, this_ptr, "_getexpression", exprRight, (tempNotQuoting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
		}
		do {
			if (ZEPHIR_IS_LONG(exprType, '<')) {
				ZEPHIR_INIT_VAR(exprReturn);
				array_init_size(exprReturn, 7);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("<"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '=')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 7);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("="), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '>')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 7);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL(">"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 270)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 7);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("<>"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 271)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 7);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("<="), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 272)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 7);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL(">="), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 266)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 7);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("AND"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 267)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 7);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("OR"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 355)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_call_method_p1(exprReturn, this_ptr, "_getqualified", expr);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 359)) {
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '+')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 7);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("+"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '-')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 7);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("-"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '*')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 7);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("*"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '/')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 7);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("/"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '%')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 7);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("%"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 38)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 7);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("&"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 124)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 7);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("|"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 356)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 3);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("parentheses"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 367)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 5);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("unary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("-"), 1);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 258) || ZEPHIR_IS_LONG(exprType, 259)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 3);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("literal"), 1);
				ZEPHIR_OBS_VAR(_0);
				zephir_array_fetch_string(&_0, expr, SL("value"), PH_NOISY TSRMLS_CC);
				zephir_array_update_string(&exprReturn, SL("value"), &_0, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 333)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 3);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("literal"), 1);
				add_assoc_stringl_ex(exprReturn, SS("value"), SL("TRUE"), 1);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 334)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 3);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("literal"), 1);
				add_assoc_stringl_ex(exprReturn, SS("value"), SL("FALSE"), 1);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 260)) {
				ZEPHIR_OBS_VAR(value);
				zephir_array_fetch_string(&value, expr, SL("value"), PH_NOISY TSRMLS_CC);
				if ((quoting == 1)) {
					if (zephir_memnstr_str(value, SL("'"), "phalcon/mvc/model/query.zep", 483)) {
						ZEPHIR_INIT_VAR(escapedValue);
						zephir_call_func_p1(escapedValue, "phalcon_orm_singlequotes", value);
					} else {
						ZEPHIR_CPY_WRT(escapedValue, value);
					}
					ZEPHIR_INIT_VAR(exprValue);
					ZEPHIR_CONCAT_SVS(exprValue, "'", escapedValue, "'");
				} else {
					ZEPHIR_CPY_WRT(exprValue, value);
				}
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 3);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("literal"), 1);
				zephir_array_update_string(&exprReturn, SL("value"), &exprValue, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 273)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 3);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("placeholder"), 1);
				ZEPHIR_INIT_VAR(_1);
				zephir_array_fetch_string(&_2, expr, SL("value"), PH_NOISY | PH_READONLY TSRMLS_CC);
				ZEPHIR_SINIT_VAR(_3);
				ZVAL_STRING(&_3, "?", 0);
				ZEPHIR_SINIT_VAR(_4);
				ZVAL_STRING(&_4, ":", 0);
				zephir_fast_str_replace(_1, &_3, &_4, _2);
				zephir_array_update_string(&exprReturn, SL("value"), &_1, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 274)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 3);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("placeholder"), 1);
				zephir_array_fetch_string(&_2, expr, SL("value"), PH_NOISY | PH_READONLY TSRMLS_CC);
				ZEPHIR_INIT_VAR(_5);
				ZEPHIR_CONCAT_SV(_5, ":", _2);
				zephir_array_update_string(&exprReturn, SL("value"), &_5, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 322)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 3);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("literal"), 1);
				add_assoc_stringl_ex(exprReturn, SS("value"), SL("NULL"), 1);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 268)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 7);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("LIKE"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 351)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 7);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("NOT LIKE"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 275)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 7);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("ILIKE"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 357)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 7);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("NOT ILIKE"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '!')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 5);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("unary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("NOT "), 1);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 365)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 5);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("unary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL(" IS NULL"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 366)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 5);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("unary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL(" IS NOT NULL"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 315)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 7);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("IN"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 323)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 7);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("NOT IN"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 330)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 5);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("unary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("DISTINCT "), 1);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 331)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 7);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("BETWEEN"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 276)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 7);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("AGAINST"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 332)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 5);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("cast"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 335)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 5);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("convert"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 358)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				array_init_size(exprReturn, 3);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("literal"), 1);
				ZEPHIR_OBS_NVAR(_0);
				zephir_array_fetch_string(&_0, expr, SL("name"), PH_NOISY TSRMLS_CC);
				zephir_array_update_string(&exprReturn, SL("value"), &_0, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 350)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_call_method_p1(exprReturn, this_ptr, "_getfunctioncall", expr);
				break;
			}
			ZEPHIR_INIT_LNVAR(_5);
			object_init_ex(_5, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_VAR(_6);
			ZEPHIR_CONCAT_SV(_6, "Unknown expression type ", exprType);
			zephir_call_method_p1_noret(_5, "__construct", _6);
			zephir_throw_exception(_5 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		} while(0);

		RETURN_CCTOR(exprReturn);
	}
	if (zephir_array_isset_string(expr, SS("domain"))) {
		zephir_call_method_p1(return_value, this_ptr, "_getqualified", expr);
		RETURN_MM();
	}
	if (zephir_array_isset_long(expr, 0)) {
		ZEPHIR_INIT_VAR(listItems);
		array_init(listItems);
		zephir_is_iterable(expr, &_8, &_7, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
			; zend_hash_move_forward_ex(_8, &_7)
		) {
			ZEPHIR_GET_HVALUE(exprListItem, _9);
			ZEPHIR_INIT_NVAR(_1);
			zephir_call_method_p1_cache(_1, this_ptr, "_getexpression", &_10, exprListItem);
			zephir_array_append(&listItems, _1, PH_SEPARATE);
		}
		array_init_size(return_value, 3);
		add_assoc_stringl_ex(return_value, SS("type"), SL("list"), 1);
		zephir_array_fast_append(return_value, listItems);
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Unknown expression");
	return;

}

/**
 * Resolves a column from its intermediate representation into an array used to determine
 * if the resulset produced is simple or complex
 *
 * @param array column
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getSelectColumn) {

	zval *_4 = NULL;
	HashTable *_2;
	HashPosition _1;
	zval *column, *sqlColumns, *columnType, *sqlAliases, *modelName = NULL, *source = NULL, *columnDomain, *sqlColumnAlias = NULL, *bestAlias, *preparedAlias = NULL, *sqlExprColumn, *sqlAliasesModels, *sqlModelsAliases, *sqlColumn, *columnData, *balias, *_0, **_3, *_5 = NULL, *_6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);



	ZEPHIR_OBS_VAR(columnType);
	if (!(zephir_array_isset_string_fetch(&columnType, column, SS("type"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	ZEPHIR_INIT_VAR(sqlColumns);
	array_init(sqlColumns);
	if (ZEPHIR_IS_LONG(columnType, 352)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_models"), PH_NOISY_CC);
		zephir_is_iterable(_0, &_2, &_1, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
			; zend_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HMKEY(modelName, _2, _1);
			ZEPHIR_GET_HVALUE(source, _3);
			ZEPHIR_INIT_NVAR(_4);
			array_init_size(_4, 5);
			add_assoc_stringl_ex(_4, SS("type"), SL("object"), 1);
			zephir_array_update_string(&_4, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_4, SL("column"), &source, PH_COPY | PH_SEPARATE);
			zephir_array_append(&sqlColumns, _4, PH_SEPARATE);
		}
		RETURN_CCTOR(sqlColumns);
	}
	if (!(zephir_array_isset_string(column, SS("column")))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	if (ZEPHIR_IS_LONG(columnType, 353)) {
		ZEPHIR_OBS_VAR(sqlAliases);
		zephir_read_property_this(&sqlAliases, this_ptr, SL("_sqlAliases"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(columnDomain);
		zephir_array_fetch_string(&columnDomain, column, SL("column"), PH_NOISY TSRMLS_CC);
		ZEPHIR_OBS_VAR(source);
		if (!(zephir_array_isset_fetch(&source, sqlAliases, columnDomain, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(_5);
			object_init_ex(_5, phalcon_mvc_model_exception_ce);
			_0 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_6);
			ZEPHIR_CONCAT_SVSV(_6, "Unknown model or alias '", columnDomain, "' (2), when preparing: ", _0);
			zephir_call_method_p1_noret(_5, "__construct", _6);
			zephir_throw_exception(_5 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(sqlColumnAlias, source);
		ZEPHIR_OBS_VAR(sqlAliasesModels);
		zephir_read_property_this(&sqlAliasesModels, this_ptr, SL("_sqlAliasesModels"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(modelName);
		zephir_array_fetch(&modelName, sqlAliasesModels, columnDomain, PH_NOISY TSRMLS_CC);
		ZEPHIR_OBS_VAR(sqlModelsAliases);
		zephir_read_property_this(&sqlModelsAliases, this_ptr, SL("_sqlModelsAliases"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(bestAlias);
		zephir_array_fetch(&bestAlias, sqlModelsAliases, modelName, PH_NOISY TSRMLS_CC);
		if (ZEPHIR_IS_EQUAL(bestAlias, modelName)) {
			ZEPHIR_INIT_VAR(preparedAlias);
			zephir_call_func_p1(preparedAlias, "lcfirst", modelName);
		} else {
			ZEPHIR_CPY_WRT(preparedAlias, bestAlias);
		}
		ZEPHIR_INIT_NVAR(_4);
		array_init_size(_4, 7);
		add_assoc_stringl_ex(_4, SS("type"), SL("object"), 1);
		zephir_array_update_string(&_4, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_4, SL("column"), &sqlColumnAlias, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_4, SL("balias"), &preparedAlias, PH_COPY | PH_SEPARATE);
		zephir_array_append(&sqlColumns, _4, PH_SEPARATE);
		RETURN_CCTOR(sqlColumns);
	}
	if (ZEPHIR_IS_LONG(columnType, 354)) {
		ZEPHIR_INIT_VAR(sqlColumn);
		array_init_size(sqlColumn, 2);
		add_assoc_stringl_ex(sqlColumn, SS("type"), SL("scalar"), 1);
		ZEPHIR_OBS_VAR(columnData);
		zephir_array_fetch_string(&columnData, column, SL("column"), PH_NOISY TSRMLS_CC);
		ZEPHIR_INIT_VAR(sqlExprColumn);
		zephir_call_method_p1(sqlExprColumn, this_ptr, "_getexpression", columnData);
		ZEPHIR_OBS_VAR(balias);
		if (zephir_array_isset_string_fetch(&balias, sqlExprColumn, SS("balias"), 0 TSRMLS_CC)) {
			zephir_array_update_string(&sqlColumn, SL("balias"), &balias, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&sqlColumn, SL("sqlAlias"), &balias, PH_COPY | PH_SEPARATE);
		}
		zephir_array_update_string(&sqlColumn, SL("column"), &sqlExprColumn, PH_COPY | PH_SEPARATE);
		zephir_array_append(&sqlColumns, sqlColumn, PH_SEPARATE);
		RETURN_CCTOR(sqlColumns);
	}
	ZEPHIR_INIT_LNVAR(_5);
	object_init_ex(_5, phalcon_mvc_model_exception_ce);
	ZEPHIR_INIT_LNVAR(_6);
	ZEPHIR_CONCAT_SV(_6, "Unknown type of column ", columnType);
	zephir_call_method_p1_noret(_5, "__construct", _6);
	zephir_throw_exception(_5 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Resolves a table in a SELECT statement checking if the model exists
 *
 * @param Phalcon\Mvc\Model\ManagerInterface manager
 * @param array qualifiedName
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getTable) {

	zval *manager, *qualifiedName, *modelName, *model, *source, *schema;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &manager, &qualifiedName);



	ZEPHIR_OBS_VAR(modelName);
	if (zephir_array_isset_string_fetch(&modelName, qualifiedName, SS("name"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(model);
		zephir_call_method_p1(model, manager, "load", modelName);
		ZEPHIR_INIT_VAR(source);
		zephir_call_method(source, model, "getsource");
		ZEPHIR_INIT_VAR(schema);
		zephir_call_method(schema, model, "getschema");
		if (zephir_is_true(schema)) {
			array_init_size(return_value, 3);
			zephir_array_fast_append(return_value, schema);
			zephir_array_fast_append(return_value, source);
			RETURN_MM();
		}
		RETURN_CCTOR(source);
	}
	ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
	return;

}

/**
 * Resolves a JOIN clause checking if the associated models exist
 *
 * @param Phalcon\Mvc\Model\ManagerInterface manager
 * @param array join
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoin) {

	zval *manager, *join, *qualified, *modelName, *source, *model, *schema, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &manager, &join);



	ZEPHIR_OBS_VAR(qualified);
	if (zephir_array_isset_string_fetch(&qualified, join, SS("qualified"), 0 TSRMLS_CC)) {
		zephir_array_fetch_string(&_0, qualified, SL("type"), PH_NOISY | PH_READONLY TSRMLS_CC);
		if (ZEPHIR_IS_LONG(_0, 355)) {
			ZEPHIR_OBS_VAR(modelName);
			zephir_array_fetch_string(&modelName, qualified, SL("name"), PH_NOISY TSRMLS_CC);
			ZEPHIR_INIT_VAR(model);
			zephir_call_method_p1(model, manager, "load", modelName);
			ZEPHIR_INIT_VAR(source);
			zephir_call_method(source, model, "getsource");
			ZEPHIR_INIT_VAR(schema);
			zephir_call_method(schema, model, "getschema");
			array_init_size(return_value, 7);
			zephir_array_update_string(&return_value, SL("schema"), &schema, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&return_value, SL("source"), &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&return_value, SL("modelName"), &modelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&return_value, SL("model"), &model, PH_COPY | PH_SEPARATE);
			RETURN_MM();
		}
	}
	ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
	return;

}

/**
 * Resolves a JOIN type
 *
 * @param array join
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoinType) {

	zval *join, *type, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &join);



	ZEPHIR_OBS_VAR(type);
	if (!(zephir_array_isset_string_fetch(&type, join, SS("type"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	do {
		if (ZEPHIR_IS_LONG(type, 360)) {
			RETURN_MM_STRING("INNER", 1);
		}
		if (ZEPHIR_IS_LONG(type, 361)) {
			RETURN_MM_STRING("LEFT", 1);
		}
		if (ZEPHIR_IS_LONG(type, 362)) {
			RETURN_MM_STRING("RIGHT", 1);
		}
		if (ZEPHIR_IS_LONG(type, 363)) {
			RETURN_MM_STRING("CROSS", 1);
		}
		if (ZEPHIR_IS_LONG(type, 364)) {
			RETURN_MM_STRING("FULL OUTER", 1);
		}
	} while(0);

	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, phalcon_mvc_model_exception_ce);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SVSV(_2, "Unknown join type ", type, ", when preparing: ", _1);
	zephir_call_method_p1_noret(_0, "__construct", _2);
	zephir_throw_exception(_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Resolves joins involving has-one/belongs-to/has-many relations
 *
 * @param string joinType
 * @param string joinSource
 * @param string modelAlias
 * @param string joinAlias
 * @param Phalcon\Mvc\Model\RelationInterface relation
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getSingleJoin) {

	zend_function *_9 = NULL, *_10 = NULL, *_12 = NULL;
	HashTable *_4;
	HashPosition _3;
	zval *_1 = NULL, *_2 = NULL, *_11 = NULL;
	zval *joinType_param = NULL, *joinSource, *modelAlias, *joinAlias, *relation, *fields, *referencedFields, *sqlJoinConditions, *sqlJoinPartialConditions, *position = NULL, *field = NULL, *referencedField = NULL, *_0 = NULL, **_5, *_6 = NULL, *_7, *_8 = NULL;
	zval *joinType = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &joinType_param, &joinSource, &modelAlias, &joinAlias, &relation);

	if (Z_TYPE_P(joinType_param) != IS_STRING && Z_TYPE_P(joinType_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'joinType' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(joinType_param) == IS_STRING) {
		joinType = joinType_param;
	} else {
		ZEPHIR_INIT_VAR(joinType);
		ZVAL_EMPTY_STRING(joinType);
	}


	ZEPHIR_INIT_VAR(fields);
	zephir_call_method(fields, relation, "getfields");
	ZEPHIR_INIT_VAR(referencedFields);
	zephir_call_method(referencedFields, relation, "getreferencedfields");
	if ((Z_TYPE_P(fields) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(sqlJoinConditions);
		array_init_size(sqlJoinConditions, 7);
		add_assoc_stringl_ex(sqlJoinConditions, SS("type"), SL("binary-op"), 1);
		add_assoc_stringl_ex(sqlJoinConditions, SS("op"), SL("="), 1);
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_INIT_VAR(_1);
		array_init_size(_1, 5);
		add_assoc_long_ex(_1, SS("type"), 355);
		zephir_array_update_string(&_1, SL("domain"), &modelAlias, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_1, SL("name"), &fields, PH_COPY | PH_SEPARATE);
		zephir_call_method_p1(_0, this_ptr, "_getqualified", _1);
		zephir_array_update_string(&sqlJoinConditions, SL("left"), &_0, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_0);
		ZEPHIR_INIT_VAR(_2);
		array_init_size(_2, 5);
		add_assoc_stringl_ex(_2, SS("type"), SL("qualified"), 1);
		zephir_array_update_string(&_2, SL("domain"), &joinAlias, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_2, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
		zephir_call_method_p1(_0, this_ptr, "_getqualified", _2);
		zephir_array_update_string(&sqlJoinConditions, SL("right"), &_0, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_INIT_VAR(sqlJoinPartialConditions);
		array_init(sqlJoinPartialConditions);
		zephir_is_iterable(fields, &_4, &_3, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
			; zend_hash_move_forward_ex(_4, &_3)
		) {
			ZEPHIR_GET_HMKEY(position, _4, _3);
			ZEPHIR_GET_HVALUE(field, _5);
			ZEPHIR_OBS_NVAR(referencedField);
			if (!(zephir_array_isset_fetch(&referencedField, referencedFields, position, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_LNVAR(_6);
				object_init_ex(_6, phalcon_mvc_model_exception_ce);
				_7 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_8);
				ZEPHIR_CONCAT_SVSVSV(_8, "The number of fields must be equal to the number of referenced fields in join ", modelAlias, "-", joinAlias, ", when preparing: ", _7);
				zephir_call_method_p1_cache_noret(_6, "__construct", &_9, _8);
				zephir_throw_exception(_6 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(_1);
			array_init_size(_1, 7);
			add_assoc_stringl_ex(_1, SS("type"), SL("binary-op"), 1);
			add_assoc_stringl_ex(_1, SS("op"), SL("="), 1);
			ZEPHIR_INIT_NVAR(_0);
			ZEPHIR_INIT_NVAR(_2);
			array_init_size(_2, 5);
			add_assoc_long_ex(_2, SS("type"), 355);
			zephir_array_update_string(&_2, SL("domain"), &modelAlias, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_2, SL("name"), &field, PH_COPY | PH_SEPARATE);
			zephir_call_method_p1_cache(_0, this_ptr, "_getqualified", &_10, _2);
			zephir_array_update_string(&_1, SL("left"), &_0, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_0);
			ZEPHIR_INIT_NVAR(_11);
			array_init_size(_11, 5);
			add_assoc_stringl_ex(_11, SS("type"), SL("qualified"), 1);
			zephir_array_update_string(&_11, SL("domain"), &joinAlias, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_11, SL("name"), &referencedField, PH_COPY | PH_SEPARATE);
			zephir_call_method_p1_cache(_0, this_ptr, "_getqualified", &_12, _11);
			zephir_array_update_string(&_1, SL("right"), &_0, PH_COPY | PH_SEPARATE);
			zephir_array_append(&sqlJoinPartialConditions, _1, PH_SEPARATE);
		}
	}
	array_init_size(return_value, 5);
	zephir_array_update_string(&return_value, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("conditions"), &sqlJoinConditions, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * Resolves joins involving many-to-many relations
 *
 * @param string joinType
 * @param string joinSource
 * @param string modelAlias
 * @param string joinAlias
 * @param Phalcon\Mvc\Model\RelationInterface relation
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getMultiJoin) {

	zval *_8 = NULL, *_10 = NULL, *_12 = NULL, *_13, *_14, *_15, *_16;
	zend_function *_6 = NULL, *_9 = NULL, *_11 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *joinType, *joinSource, *modelAlias, *joinAlias, *relation, *sqlJoins, *fields, *referencedFields, *intermediateModelName, *intermediateModel, *intermediateSource, *intermediateSchema, *intermediateFields, *intermediateReferencedFields, *referencedModelName, *manager, *field = NULL, *position = NULL, *intermediateField = NULL, *sqlEqualsJoinCondition = NULL, **_2, *_3 = NULL, *_4, *_5 = NULL, *_7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &joinType, &joinSource, &modelAlias, &joinAlias, &relation);



	ZEPHIR_INIT_VAR(sqlJoins);
	array_init(sqlJoins);
	ZEPHIR_INIT_VAR(fields);
	zephir_call_method(fields, relation, "getfields");
	ZEPHIR_INIT_VAR(referencedFields);
	zephir_call_method(referencedFields, relation, "getreferencedfields");
	ZEPHIR_INIT_VAR(intermediateModelName);
	zephir_call_method(intermediateModelName, relation, "getintermediatemodel");
	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(intermediateModel);
	zephir_call_method_p1(intermediateModel, manager, "load", intermediateModelName);
	ZEPHIR_INIT_VAR(intermediateSource);
	zephir_call_method(intermediateSource, intermediateModel, "getsource");
	ZEPHIR_INIT_VAR(intermediateSchema);
	zephir_call_method(intermediateSchema, intermediateModel, "getschema");
	zephir_update_property_array(this_ptr, SL("_sqlAliases"), intermediateModelName, intermediateSource TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_sqlAliasesModelsInstances"), intermediateModelName, intermediateModel TSRMLS_CC);
	ZEPHIR_INIT_VAR(intermediateFields);
	zephir_call_method(intermediateFields, relation, "getintermediatefields");
	ZEPHIR_INIT_VAR(intermediateReferencedFields);
	zephir_call_method(intermediateReferencedFields, relation, "getintermediatereferencedfields");
	ZEPHIR_INIT_VAR(referencedModelName);
	zephir_call_method(referencedModelName, relation, "getreferencedmodel");
	if ((Z_TYPE_P(fields) == IS_ARRAY)) {
		zephir_is_iterable(fields, &_1, &_0, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			; zend_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HMKEY(field, _1, _0);
			ZEPHIR_GET_HVALUE(position, _2);
			if (!(zephir_array_isset(referencedFields, position))) {
				ZEPHIR_INIT_LNVAR(_3);
				object_init_ex(_3, phalcon_mvc_model_exception_ce);
				_4 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_5);
				ZEPHIR_CONCAT_SVSVSV(_5, "The number of fields must be equal to the number of referenced fields in join ", modelAlias, "-", joinAlias, ", when preparing: ", _4);
				zephir_call_method_p1_cache_noret(_3, "__construct", &_6, _5);
				zephir_throw_exception(_3 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(intermediateField);
			zephir_array_fetch(&intermediateField, intermediateFields, position, PH_NOISY TSRMLS_CC);
			ZEPHIR_INIT_NVAR(sqlEqualsJoinCondition);
			array_init_size(sqlEqualsJoinCondition, 7);
			add_assoc_stringl_ex(sqlEqualsJoinCondition, SS("type"), SL("binary-op"), 1);
			add_assoc_stringl_ex(sqlEqualsJoinCondition, SS("op"), SL("="), 1);
			ZEPHIR_INIT_NVAR(_7);
			ZEPHIR_INIT_NVAR(_8);
			array_init_size(_8, 5);
			add_assoc_long_ex(_8, SS("type"), 355);
			zephir_array_update_string(&_8, SL("domain"), &modelAlias, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_8, SL("name"), &field, PH_COPY | PH_SEPARATE);
			zephir_call_method_p1_cache(_7, this_ptr, "_getqualified", &_9, _8);
			zephir_array_update_string(&sqlEqualsJoinCondition, SL("left"), &_7, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_7);
			ZEPHIR_INIT_NVAR(_10);
			array_init_size(_10, 5);
			add_assoc_stringl_ex(_10, SS("type"), SL("qualified"), 1);
			zephir_array_update_string(&_10, SL("domain"), &joinAlias, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_10, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
			zephir_call_method_p1_cache(_7, this_ptr, "_getqualified", &_11, _10);
			zephir_array_update_string(&sqlEqualsJoinCondition, SL("right"), &_7, PH_COPY | PH_SEPARATE);
		}
	} else {
		ZEPHIR_INIT_BNVAR(sqlJoins);
		array_init_size(sqlJoins, 3);
		ZEPHIR_INIT_NVAR(_8);
		array_init_size(_8, 5);
		zephir_array_update_string(&_8, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_8, SL("source"), &intermediateSource, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_10);
		array_init_size(_10, 2);
		ZEPHIR_INIT_VAR(_12);
		array_init_size(_12, 7);
		add_assoc_stringl_ex(_12, SS("type"), SL("binary-op"), 1);
		add_assoc_stringl_ex(_12, SS("op"), SL("="), 1);
		ZEPHIR_INIT_NVAR(_7);
		ZEPHIR_INIT_VAR(_13);
		array_init_size(_13, 5);
		add_assoc_long_ex(_13, SS("type"), 355);
		zephir_array_update_string(&_13, SL("domain"), &modelAlias, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_13, SL("name"), &fields, PH_COPY | PH_SEPARATE);
		zephir_call_method_p1(_7, this_ptr, "_getqualified", _13);
		zephir_array_update_string(&_12, SL("left"), &_7, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_7);
		ZEPHIR_INIT_VAR(_14);
		array_init_size(_14, 5);
		add_assoc_stringl_ex(_14, SS("type"), SL("qualified"), 1);
		zephir_array_update_string(&_14, SL("domain"), &intermediateModelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_14, SL("name"), &intermediateFields, PH_COPY | PH_SEPARATE);
		zephir_call_method_p1(_7, this_ptr, "_getqualified", _14);
		zephir_array_update_string(&_12, SL("right"), &_7, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(_10, _12);
		zephir_array_update_string(&_8, SL("conditions"), &_10, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(sqlJoins, _8);
		ZEPHIR_INIT_NVAR(_8);
		array_init_size(_8, 5);
		zephir_array_update_string(&_8, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_8, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_10);
		array_init_size(_10, 2);
		ZEPHIR_INIT_NVAR(_12);
		array_init_size(_12, 7);
		add_assoc_stringl_ex(_12, SS("type"), SL("binary-op"), 1);
		add_assoc_stringl_ex(_12, SS("op"), SL("="), 1);
		ZEPHIR_INIT_NVAR(_7);
		ZEPHIR_INIT_VAR(_15);
		array_init_size(_15, 5);
		add_assoc_long_ex(_15, SS("type"), 355);
		zephir_array_update_string(&_15, SL("domain"), &intermediateModelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_15, SL("name"), &intermediateReferencedFields, PH_COPY | PH_SEPARATE);
		zephir_call_method_p1(_7, this_ptr, "_getqualified", _15);
		zephir_array_update_string(&_12, SL("left"), &_7, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_7);
		ZEPHIR_INIT_VAR(_16);
		array_init_size(_16, 5);
		add_assoc_stringl_ex(_16, SS("type"), SL("qualified"), 1);
		zephir_array_update_string(&_16, SL("domain"), &referencedModelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_16, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
		zephir_call_method_p1(_7, this_ptr, "_getqualified", _16);
		zephir_array_update_string(&_12, SL("right"), &_7, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(_10, _12);
		zephir_array_update_string(&_8, SL("conditions"), &_10, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(sqlJoins, _8);
	}
	RETURN_CCTOR(sqlJoins);

}

/**
 * Processes the JOINs in the query returning an internal representation for the database dialect
 *
 * @param array select
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoins) {

	zval *_25 = NULL, *_26 = NULL;
	zend_function *_3 = NULL, *_4 = NULL, *_8 = NULL, *_9 = NULL, *_14 = NULL, *_21 = NULL, *_22 = NULL, *_23 = NULL;
	HashTable *_1, *_11, *_16, *_19;
	HashPosition _0, _10, _15, _18;
	zval *select, *models, *sqlAliases, *sqlAliasesModels, *sqlModelsAliases, *sqlAliasesModelsInstances, *modelsInstances, *fromModels = NULL, *sqlJoins = NULL, *joinModels, *joinSources, *joinTypes, *joinPreCondition, *joinPrepared, *manager = NULL, *selectJoins = NULL, *joinItem = NULL, *joins, *joinData = NULL, *schema = NULL, *source = NULL, *model = NULL, *modelName = NULL, *completeSource = NULL, *joinType = NULL, *aliasExpr = NULL, *alias = NULL, *joinAliasName = NULL, *joinExpr = NULL, *fromModelName = NULL, *joinAlias = NULL, *joinModel = NULL, *joinSource = NULL, *preCondition = NULL, *modelNameAlias = NULL, *relation = NULL, *relations = NULL, *modelAlias = NULL, *sqlJoin = NULL, **_2, *_5 = NULL, *_6, *_7 = NULL, **_12, *_13 = NULL, **_17, **_20, *_24 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &select);



	ZEPHIR_OBS_VAR(models);
	zephir_read_property_this(&models, this_ptr, SL("_models"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(sqlAliases);
	zephir_read_property_this(&sqlAliases, this_ptr, SL("_sqlAliases"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(sqlAliasesModels);
	zephir_read_property_this(&sqlAliasesModels, this_ptr, SL("_sqlAliasesModels"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(sqlModelsAliases);
	zephir_read_property_this(&sqlModelsAliases, this_ptr, SL("_sqlModelsAliases"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(sqlAliasesModelsInstances);
	zephir_read_property_this(&sqlAliasesModelsInstances, this_ptr, SL("_sqlAliasesModelsInstances"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(modelsInstances);
	zephir_read_property_this(&modelsInstances, this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(fromModels, models);
	ZEPHIR_INIT_VAR(sqlJoins);
	array_init(sqlJoins);
	ZEPHIR_INIT_VAR(joinModels);
	array_init(joinModels);
	ZEPHIR_INIT_VAR(joinSources);
	array_init(joinSources);
	ZEPHIR_INIT_VAR(joinTypes);
	array_init(joinTypes);
	ZEPHIR_INIT_VAR(joinPreCondition);
	array_init(joinPreCondition);
	ZEPHIR_INIT_VAR(joinPrepared);
	array_init(joinPrepared);
	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(joins);
	zephir_array_fetch_string(&joins, select, SL("joins"), PH_NOISY TSRMLS_CC);
	if (!(zephir_array_isset_long(joins, 0))) {
		ZEPHIR_INIT_VAR(selectJoins);
		array_init_size(selectJoins, 2);
		zephir_array_fast_append(selectJoins, joins);
	} else {
		ZEPHIR_CPY_WRT(selectJoins, joins);
	}
	zephir_is_iterable(selectJoins, &_1, &_0, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(joinItem, _2);
		ZEPHIR_INIT_NVAR(joinData);
		zephir_call_method_p2_cache(joinData, this_ptr, "_getjoin", &_3, manager, joinItem);
		ZEPHIR_OBS_NVAR(source);
		zephir_array_fetch_string(&source, joinData, SL("source"), PH_NOISY TSRMLS_CC);
		ZEPHIR_OBS_NVAR(schema);
		zephir_array_fetch_string(&schema, joinData, SL("schema"), PH_NOISY TSRMLS_CC);
		ZEPHIR_OBS_NVAR(model);
		zephir_array_fetch_string(&model, joinData, SL("model"), PH_NOISY TSRMLS_CC);
		ZEPHIR_OBS_NVAR(modelName);
		zephir_array_fetch_string(&modelName, joinData, SL("modelName"), PH_NOISY TSRMLS_CC);
		ZEPHIR_INIT_NVAR(completeSource);
		array_init_size(completeSource, 3);
		zephir_array_fast_append(completeSource, source);
		zephir_array_fast_append(completeSource, schema);
		ZEPHIR_INIT_NVAR(joinType);
		zephir_call_method_p1_cache(joinType, this_ptr, "_getjointype", &_4, joinItem);
		ZEPHIR_OBS_NVAR(aliasExpr);
		if (zephir_array_isset_string_fetch(&aliasExpr, joinItem, SS("alias"), 0 TSRMLS_CC)) {
			ZEPHIR_OBS_NVAR(alias);
			zephir_array_fetch_string(&alias, aliasExpr, SL("name"), PH_NOISY TSRMLS_CC);
			if (zephir_array_isset(joinModels, alias)) {
				ZEPHIR_INIT_LNVAR(_5);
				object_init_ex(_5, phalcon_mvc_model_exception_ce);
				_6 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_7);
				ZEPHIR_CONCAT_SVSV(_7, "Cannot use '", alias, "' as join alias because it was already used, when preparing: ", _6);
				zephir_call_method_p1_cache_noret(_5, "__construct", &_8, _7);
				zephir_throw_exception(_5 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&completeSource, alias, PH_SEPARATE);
			zephir_array_update_zval(&joinTypes, alias, &joinType, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliases, alias, &alias, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&joinModels, alias, &modelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlModelsAliases, modelName, &alias, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModels, alias, &modelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModelsInstances, alias, &model, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&models, modelName, &alias, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&joinSources, alias, &completeSource, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&joinPrepared, alias, &joinItem, PH_COPY | PH_SEPARATE);
		} else {
			if (zephir_array_isset(joinModels, modelName)) {
				ZEPHIR_INIT_LNVAR(_5);
				object_init_ex(_5, phalcon_mvc_model_exception_ce);
				_6 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_7);
				ZEPHIR_CONCAT_SVSV(_7, "Cannot use '", modelName, "' as join alias because it was already used, when preparing: ", _6);
				zephir_call_method_p1_cache_noret(_5, "__construct", &_9, _7);
				zephir_throw_exception(_5 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&joinTypes, modelName, &joinType, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliases, modelName, &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&joinModels, modelName, &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlModelsAliases, modelName, &modelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModels, modelName, &modelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModelsInstances, modelName, &model, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&models, modelName, &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&joinSources, modelName, &completeSource, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&joinPrepared, modelName, &joinItem, PH_COPY | PH_SEPARATE);
		}
		zephir_array_update_zval(&modelsInstances, modelName, &model, PH_COPY | PH_SEPARATE);
	}
	zephir_update_property_this(this_ptr, SL("_models"), models TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_sqlAliases"), sqlAliases TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_sqlAliasesModels"), sqlAliasesModels TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_sqlModelsAliases"), sqlModelsAliases TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_sqlAliasesModelsInstances"), sqlAliasesModelsInstances TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_modelsInstances"), modelsInstances TSRMLS_CC);
	zephir_is_iterable(joinPrepared, &_11, &_10, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
		; zend_hash_move_forward_ex(_11, &_10)
	) {
		ZEPHIR_GET_HMKEY(joinAliasName, _11, _10);
		ZEPHIR_GET_HVALUE(joinItem, _12);
		ZEPHIR_OBS_NVAR(joinExpr);
		if (zephir_array_isset_string_fetch(&joinExpr, joinItem, SS("conditions"), 0 TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_13);
			zephir_call_method_p1_cache(_13, this_ptr, "_getexpression", &_14, joinExpr);
			zephir_array_update_zval(&joinPreCondition, joinAliasName, &_13, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_NVAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	zephir_is_iterable(fromModels, &_16, &_15, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_16, (void**) &_17, &_15) == SUCCESS
		; zend_hash_move_forward_ex(_16, &_15)
	) {
		ZEPHIR_GET_HMKEY(fromModelName, _16, _15);
		ZEPHIR_GET_HVALUE(source, _17);
		zephir_is_iterable(joinModels, &_19, &_18, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_19, (void**) &_20, &_18) == SUCCESS
			; zend_hash_move_forward_ex(_19, &_18)
		) {
			ZEPHIR_GET_HMKEY(joinAlias, _19, _18);
			ZEPHIR_GET_HVALUE(joinModel, _20);
			ZEPHIR_OBS_NVAR(joinSource);
			zephir_array_fetch(&joinSource, joinSources, joinAlias, PH_NOISY TSRMLS_CC);
			ZEPHIR_OBS_NVAR(joinType);
			zephir_array_fetch(&joinType, joinTypes, joinAlias, PH_NOISY TSRMLS_CC);
			ZEPHIR_OBS_NVAR(preCondition);
			if (!(zephir_array_isset_fetch(&preCondition, joinPreCondition, joinAlias, 0 TSRMLS_CC))) {
				ZEPHIR_OBS_NVAR(modelNameAlias);
				zephir_array_fetch(&modelNameAlias, sqlAliasesModels, joinAlias, PH_NOISY TSRMLS_CC);
				ZEPHIR_INIT_NVAR(relation);
				zephir_call_method_p2(relation, manager, "getrelationbyalias", fromModelName, modelNameAlias);
				if (ZEPHIR_IS_FALSE(relation)) {
					ZEPHIR_INIT_NVAR(relations);
					zephir_call_method_p2(relations, manager, "getrelationsbetween", fromModelName, modelNameAlias);
					if ((Z_TYPE_P(relations) == IS_ARRAY)) {
						if ((zephir_fast_count_int(relations TSRMLS_CC) != 1)) {
							ZEPHIR_INIT_LNVAR(_5);
							object_init_ex(_5, phalcon_mvc_model_exception_ce);
							_6 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
							ZEPHIR_INIT_LNVAR(_7);
							ZEPHIR_CONCAT_SVSVSV(_7, "There is more than one relation between models '", modelName, "' and '", joinModel, "', the join must be done using an alias, when preparing: ", _6);
							zephir_call_method_p1_cache_noret(_5, "__construct", &_21, _7);
							zephir_throw_exception(_5 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_OBS_NVAR(relation);
						zephir_array_fetch_long(&relation, relations, 0, PH_NOISY TSRMLS_CC);
					}
				}
				if ((Z_TYPE_P(relation) == IS_OBJECT)) {
					ZEPHIR_OBS_NVAR(modelAlias);
					zephir_array_fetch(&modelAlias, sqlModelsAliases, fromModelName, PH_NOISY TSRMLS_CC);
					ZEPHIR_INIT_NVAR(sqlJoin);
					ZEPHIR_INIT_NVAR(_13);
					zephir_call_method(_13, relation, "isthrough");
					if (!(zephir_is_true(_13))) {
						zephir_call_method_p5_cache(sqlJoin, this_ptr, "_getsinglejoin", &_22, joinType, joinSource, modelAlias, joinAlias, relation);
					} else {
						zephir_call_method_p5_cache(sqlJoin, this_ptr, "_getmultijoin", &_23, joinType, joinSource, modelAlias, joinAlias, relation);
					}
					if (zephir_array_isset_long(sqlJoin, 0)) {
						ZEPHIR_INIT_NVAR(_24);
						zephir_fast_array_merge(_24, &(sqlJoins), &(sqlJoin) TSRMLS_CC);
						ZEPHIR_CPY_WRT(sqlJoins, _24);
					} else {
						zephir_array_append(&sqlJoins, sqlJoin, PH_SEPARATE);
					}
				} else {
					ZEPHIR_INIT_NVAR(_25);
					array_init_size(_25, 5);
					zephir_array_update_string(&_25, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_25, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(_24);
					array_init(_24);
					zephir_array_update_string(&_25, SL("conditions"), &_24, PH_COPY | PH_SEPARATE);
					zephir_array_append(&sqlJoins, _25, PH_SEPARATE);
				}
			} else {
				ZEPHIR_INIT_NVAR(_25);
				array_init_size(_25, 5);
				zephir_array_update_string(&_25, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_25, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_26);
				array_init_size(_26, 2);
				zephir_array_fast_append(_26, preCondition);
				zephir_array_update_string(&_25, SL("conditions"), &_26, PH_COPY | PH_SEPARATE);
				zephir_array_append(&sqlJoins, _25, PH_SEPARATE);
			}
		}
	}
	RETURN_CCTOR(sqlJoins);

}

/**
 * Returns a processed order clause for a SELECT statement
 *
 * @param array $order
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getOrderClause) {

	zend_function *_4 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *order, *orderColumns = NULL, *orderParts, *orderItem = NULL, *orderPartExpr = NULL, *orderSort, *orderPartSort = NULL, **_2, *_3, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &order);



	if (!(zephir_array_isset_long(order, 0))) {
		ZEPHIR_INIT_VAR(orderColumns);
		array_init_size(orderColumns, 2);
		zephir_array_fast_append(orderColumns, order);
	} else {
		ZEPHIR_CPY_WRT(orderColumns, order);
	}
	ZEPHIR_INIT_VAR(orderParts);
	array_init(orderParts);
	zephir_is_iterable(orderColumns, &_1, &_0, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(orderItem, _2);
		zephir_array_fetch_string(&_3, orderItem, SL("column"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_NVAR(orderPartExpr);
		zephir_call_method_p1_cache(orderPartExpr, this_ptr, "_getexpression", &_4, _3);
		if (zephir_array_isset_string_fetch(&orderSort, orderItem, SS("sort"), 1 TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(orderPartSort);
			if (ZEPHIR_IS_LONG(orderSort, 327)) {
				array_init_size(orderPartSort, 3);
				zephir_array_fast_append(orderPartSort, orderPartExpr);
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_STRING(_5, "ASC", 1);
				zephir_array_fast_append(orderPartSort, _5);
			} else {
				array_init_size(orderPartSort, 3);
				zephir_array_fast_append(orderPartSort, orderPartExpr);
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_STRING(_5, "DESC", 1);
				zephir_array_fast_append(orderPartSort, _5);
			}
		} else {
			ZEPHIR_INIT_NVAR(orderPartSort);
			array_init_size(orderPartSort, 2);
			zephir_array_fast_append(orderPartSort, orderPartExpr);
		}
		zephir_array_append(&orderParts, orderPartSort, PH_SEPARATE);
	}
	RETURN_CCTOR(orderParts);

}

/**
 * Returns a processed group clause for a SELECT statement
 *
 * @param array $group
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getGroupClause) {

	zend_function *_4 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *group, *groupItem = NULL, *groupParts, **_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &group);



	ZEPHIR_INIT_VAR(groupParts);
	if (zephir_array_isset_long(group, 0)) {
		array_init(groupParts);
		zephir_is_iterable(group, &_1, &_0, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			; zend_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(groupItem, _2);
			ZEPHIR_INIT_NVAR(_3);
			zephir_call_method_p1_cache(_3, this_ptr, "_getexpression", &_4, groupItem);
			zephir_array_append(&groupParts, _3, PH_SEPARATE);
		}
	} else {
		array_init_size(groupParts, 2);
		ZEPHIR_INIT_NVAR(_3);
		zephir_call_method_p1(_3, this_ptr, "_getexpression", group);
		zephir_array_fast_append(groupParts, _3);
	}
	RETURN_CCTOR(groupParts);

}

/**
 * Analyzes a SELECT intermediate code and produces an array to be executed later
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareSelect) {

	zval *_17 = NULL;
	zend_function *_7 = NULL, *_11 = NULL;
	HashTable *_1, *_9, *_13;
	HashPosition _0, _8, _12;
	int position;
	zval *ast, *sqlModels, *sqlTables, *sqlAliases, *sqlColumns, *select, *tables, *columns, *sqlAliasesModels, *sqlModelsAliases, *sqlAliasesModelsInstances, *models, *modelsInstances, *selectedModels = NULL, *manager, *metaData, *selectedModel = NULL, *qualifiedName = NULL, *modelName = NULL, *nsAlias = NULL, *realModelName = NULL, *model = NULL, *schema = NULL, *source = NULL, *completeSource = NULL, *alias = NULL, *joins, *sqlJoins = NULL, *selectColumns = NULL, *sqlColumnAliases, *column = NULL, *sqlColumn = NULL, *sqlSelect, *having, *where, *groupBy, *order, *limit, **_2, *_3 = NULL, *_4 = NULL, *_5, *_6 = NULL, **_10, **_14, *_15, _16 = zval_used_for_init, *_18 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(ast);
	zephir_read_property_this(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(select);
	zephir_array_fetch_string(&select, ast, SL("select"), PH_NOISY TSRMLS_CC);
	ZEPHIR_OBS_VAR(tables);
	if (!(zephir_array_isset_string_fetch(&tables, select, SS("tables"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	ZEPHIR_OBS_VAR(columns);
	if (!(zephir_array_isset_string_fetch(&columns, select, SS("columns"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	ZEPHIR_INIT_VAR(sqlModels);
	array_init(sqlModels);
	ZEPHIR_INIT_VAR(sqlTables);
	array_init(sqlTables);
	ZEPHIR_INIT_VAR(sqlAliases);
	array_init(sqlAliases);
	ZEPHIR_INIT_VAR(sqlColumns);
	array_init(sqlColumns);
	ZEPHIR_INIT_VAR(sqlAliasesModels);
	array_init(sqlAliasesModels);
	ZEPHIR_INIT_VAR(sqlModelsAliases);
	array_init(sqlModelsAliases);
	ZEPHIR_INIT_VAR(sqlAliasesModelsInstances);
	array_init(sqlAliasesModelsInstances);
	ZEPHIR_INIT_VAR(models);
	array_init(models);
	ZEPHIR_INIT_VAR(modelsInstances);
	array_init(modelsInstances);
	if (!(zephir_array_isset_long(tables, 0))) {
		ZEPHIR_INIT_VAR(selectedModels);
		array_init_size(selectedModels, 2);
		zephir_array_fast_append(selectedModels, tables);
	} else {
		ZEPHIR_CPY_WRT(selectedModels, tables);
	}
	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(metaData);
	zephir_read_property_this(&metaData, this_ptr, SL("_metaData"), PH_NOISY_CC);
	zephir_is_iterable(selectedModels, &_1, &_0, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(selectedModel, _2);
		ZEPHIR_OBS_NVAR(qualifiedName);
		zephir_array_fetch_string(&qualifiedName, selectedModel, SL("qualifiedName"), PH_NOISY TSRMLS_CC);
		ZEPHIR_OBS_NVAR(modelName);
		zephir_array_fetch_string(&modelName, qualifiedName, SL("name"), PH_NOISY TSRMLS_CC);
		ZEPHIR_OBS_NVAR(nsAlias);
		if (zephir_array_isset_string_fetch(&nsAlias, qualifiedName, SS("ns-alias"), 0 TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_3);
			zephir_call_method_p1(_3, manager, "getnamespacealias", nsAlias);
			ZEPHIR_INIT_NVAR(realModelName);
			ZEPHIR_CONCAT_VSV(realModelName, _3, "\\", modelName);
		} else {
			ZEPHIR_CPY_WRT(realModelName, modelName);
		}
		ZEPHIR_INIT_NVAR(model);
		zephir_call_method_p1(model, manager, "load", realModelName);
		ZEPHIR_INIT_NVAR(schema);
		zephir_call_method(schema, model, "getschema");
		ZEPHIR_INIT_NVAR(source);
		zephir_call_method(source, model, "getsource");
		if (zephir_is_true(schema)) {
			ZEPHIR_INIT_NVAR(completeSource);
			array_init_size(completeSource, 3);
			zephir_array_fast_append(completeSource, source);
			zephir_array_fast_append(completeSource, schema);
		} else {
			ZEPHIR_CPY_WRT(completeSource, source);
		}
		ZEPHIR_OBS_NVAR(alias);
		if (zephir_array_isset_string_fetch(&alias, selectedModel, SS("alias"), 0 TSRMLS_CC)) {
			if (zephir_array_isset(sqlAliases, alias)) {
				ZEPHIR_INIT_LNVAR(_4);
				object_init_ex(_4, phalcon_mvc_model_exception_ce);
				_5 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_6);
				ZEPHIR_CONCAT_SVSV(_6, "Alias '", alias, "' is already used, when preparing: ", _5);
				zephir_call_method_p1_cache_noret(_4, "__construct", &_7, _6);
				zephir_throw_exception(_4 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&sqlAliasesModels, alias, &modelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlModelsAliases, modelName, &alias, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModelsInstances, alias, &model, PH_COPY | PH_SEPARATE);
			if ((Z_TYPE_P(completeSource) == IS_ARRAY)) {
				zephir_array_append(&completeSource, alias, PH_SEPARATE);
			} else {
				ZEPHIR_INIT_NVAR(completeSource);
				array_init_size(completeSource, 5);
				zephir_array_fast_append(completeSource, source);
				zephir_array_fast_append(completeSource, ZEPHIR_GLOBAL(global_null));
				zephir_array_fast_append(completeSource, alias);
			}
			zephir_array_update_zval(&models, modelName, &alias, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&sqlAliases, modelName, &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModels, modelName, &modelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlModelsAliases, modelName, &modelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModelsInstances, modelName, &model, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&models, modelName, &source, PH_COPY | PH_SEPARATE);
		}
		zephir_array_append(&sqlModels, modelName, PH_SEPARATE);
		zephir_array_append(&sqlTables, completeSource, PH_SEPARATE);
		zephir_array_update_zval(&modelsInstances, modelName, &model, PH_COPY | PH_SEPARATE);
	}
	zephir_update_property_this(this_ptr, SL("_models"), models TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_modelsInstances"), modelsInstances TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_sqlAliases"), sqlAliases TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_sqlAliasesModels"), sqlAliasesModels TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_sqlModelsAliases"), sqlModelsAliases TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_sqlAliasesModelsInstances"), sqlAliasesModelsInstances TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_modelsInstances"), modelsInstances TSRMLS_CC);
	ZEPHIR_OBS_VAR(joins);
	if (zephir_array_isset_string_fetch(&joins, select, SS("joins"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(sqlJoins);
		if (zephir_fast_count_int(joins TSRMLS_CC)) {
			zephir_call_method_p1(sqlJoins, this_ptr, "_getjoins", select);
		} else {
			array_init(sqlJoins);
		}
	} else {
		ZEPHIR_INIT_NVAR(sqlJoins);
		array_init(sqlJoins);
	}
	if (!(zephir_array_isset_long(columns, 0))) {
		ZEPHIR_INIT_VAR(selectColumns);
		array_init_size(selectColumns, 2);
		zephir_array_fast_append(selectColumns, columns);
	} else {
		ZEPHIR_CPY_WRT(selectColumns, columns);
	}
	position = 0;
	ZEPHIR_INIT_VAR(sqlColumnAliases);
	array_init(sqlColumnAliases);
	zephir_is_iterable(selectColumns, &_9, &_8, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_9, (void**) &_10, &_8) == SUCCESS
		; zend_hash_move_forward_ex(_9, &_8)
	) {
		ZEPHIR_GET_HVALUE(column, _10);
		ZEPHIR_INIT_NVAR(_3);
		zephir_call_method_p1_cache(_3, this_ptr, "_getselectcolumn", &_11, column);
		zephir_is_iterable(_3, &_13, &_12, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_13, (void**) &_14, &_12) == SUCCESS
			; zend_hash_move_forward_ex(_13, &_12)
		) {
			ZEPHIR_GET_HVALUE(sqlColumn, _14);
			ZEPHIR_OBS_NVAR(alias);
			if (zephir_array_isset_string_fetch(&alias, column, SS("alias"), 0 TSRMLS_CC)) {
				zephir_array_update_string(&sqlColumn, SL("balias"), &alias, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&sqlColumn, SL("sqlAlias"), &alias, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlColumns, alias, &sqlColumn, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlColumnAliases, alias, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
			} else {
				ZEPHIR_OBS_NVAR(alias);
				if (zephir_array_isset_string_fetch(&alias, sqlColumn, SS("balias"), 0 TSRMLS_CC)) {
					zephir_array_update_zval(&sqlColumns, alias, &sqlColumn, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_fetch_string(&_15, sqlColumn, SL("type"), PH_NOISY | PH_READONLY TSRMLS_CC);
					if (ZEPHIR_IS_STRING(_15, "scalar")) {
						ZEPHIR_SINIT_NVAR(_16);
						ZVAL_LONG(&_16, position);
						ZEPHIR_INIT_LNVAR(_17);
						ZEPHIR_CONCAT_SV(_17, "_", &_16);
						zephir_array_update_zval(&sqlColumns, _17, &sqlColumn, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_append(&sqlColumns, sqlColumn, PH_SEPARATE);
					}
				}
			}
			position++;
		}
	}
	zephir_update_property_this(this_ptr, SL("_sqlColumnAliases"), sqlColumnAliases TSRMLS_CC);
	ZEPHIR_INIT_VAR(sqlSelect);
	array_init_size(sqlSelect, 5);
	zephir_array_update_string(&sqlSelect, SL("models"), &sqlModels, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlSelect, SL("tables"), &sqlTables, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlSelect, SL("columns"), &sqlColumns, PH_COPY | PH_SEPARATE);
	if (zephir_fast_count_int(sqlJoins TSRMLS_CC)) {
		zephir_array_update_string(&sqlSelect, SL("joins"), &sqlJoins, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(where);
	if (zephir_array_isset_string_fetch(&where, ast, SS("where"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(_3);
		zephir_call_method_p1(_3, this_ptr, "_getexpression", where);
		zephir_array_update_string(&sqlSelect, SL("where"), &_3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(groupBy);
	if (zephir_array_isset_string_fetch(&groupBy, ast, SS("groupBy"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_18);
		zephir_call_method_p1(_18, this_ptr, "_getgroupclause", groupBy);
		zephir_array_update_string(&sqlSelect, SL("group"), &_18, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(having);
	if (zephir_array_isset_string_fetch(&having, ast, SS("having"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(_18);
		zephir_call_method_p1(_18, this_ptr, "_getexpression", having);
		zephir_array_update_string(&sqlSelect, SL("having"), &_18, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(order);
	if (zephir_array_isset_string_fetch(&order, ast, SS("orderBy"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(_18);
		zephir_call_method_p1(_18, this_ptr, "_getorderclause", order);
		zephir_array_update_string(&sqlSelect, SL("order"), &_18, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&limit, ast, SS("limit"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&sqlSelect, SL("limit"), &limit, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(sqlSelect);

}

/**
 * Analyzes an INSERT intermediate code and produces an array to be executed later
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareInsert) {

	zend_function *_7 = NULL, *_14 = NULL;
	zval *_4 = NULL;
	HashTable *_2, *_9;
	HashPosition _1, _8;
	zend_bool notQuoting;
	zval *ast, *qualifiedName, *manager, *modelName, *model, *source, *schema, *sqlAliases, *exprValues, *exprValue = NULL, *sqlInsert, *metaData, *fields, *sqlFields, *field = NULL, *name = NULL, *_0, **_3, *_5 = NULL, *_6 = NULL, **_10, *_11 = NULL, *_12, *_13 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(ast);
	zephir_read_property_this(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	if (!(zephir_array_isset_string(ast, SS("qualifiedName")))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted INSERT AST");
		return;
	}
	if (!(zephir_array_isset_string(ast, SS("values")))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted INSERT AST");
		return;
	}
	ZEPHIR_OBS_VAR(qualifiedName);
	zephir_array_fetch_string(&qualifiedName, ast, SL("qualifiedName"), PH_NOISY TSRMLS_CC);
	if (!(zephir_array_isset_string(qualifiedName, SS("name")))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted INSERT AST");
		return;
	}
	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(modelName);
	zephir_array_fetch_string(&modelName, qualifiedName, SL("name"), PH_NOISY TSRMLS_CC);
	ZEPHIR_INIT_VAR(model);
	zephir_call_method_p1(model, manager, "load", modelName);
	ZEPHIR_INIT_VAR(source);
	zephir_call_method(source, model, "getsource");
	ZEPHIR_INIT_VAR(schema);
	zephir_call_method(schema, model, "getschema");
	if (zephir_is_true(schema)) {
		ZEPHIR_INIT_BNVAR(source);
		array_init_size(source, 3);
		zephir_array_fast_append(source, schema);
		zephir_array_fast_append(source, source);
	}
	ZEPHIR_INIT_VAR(sqlAliases);
	array_init(sqlAliases);
	notQuoting = 0;
	ZEPHIR_INIT_VAR(exprValues);
	array_init(exprValues);
	zephir_array_fetch_string(&_0, ast, SL("values"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(exprValue, _3);
		ZEPHIR_INIT_NVAR(_4);
		array_init_size(_4, 3);
		ZEPHIR_OBS_NVAR(_5);
		zephir_array_fetch_string(&_5, exprValue, SL("type"), PH_NOISY TSRMLS_CC);
		zephir_array_update_string(&_4, SL("type"), &_5, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_6);
		zephir_call_method_p2_cache(_6, this_ptr, "_getexpression", &_7, exprValue, (notQuoting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
		zephir_array_update_string(&_4, SL("value"), &_6, PH_COPY | PH_SEPARATE);
		zephir_array_append(&exprValues, _4, PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(sqlInsert);
	array_init_size(sqlInsert, 3);
	zephir_array_update_string(&sqlInsert, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlInsert, SL("table"), &source, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(metaData);
	zephir_read_property_this(&metaData, this_ptr, SL("_metaData"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(fields);
	if (zephir_array_isset_string_fetch(&fields, ast, SS("fields"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(sqlFields);
		array_init(sqlFields);
		zephir_is_iterable(fields, &_9, &_8, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_9, (void**) &_10, &_8) == SUCCESS
			; zend_hash_move_forward_ex(_9, &_8)
		) {
			ZEPHIR_GET_HVALUE(field, _10);
			ZEPHIR_OBS_NVAR(name);
			zephir_array_fetch_string(&name, field, SL("name"), PH_NOISY TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_6);
			zephir_call_method_p2(_6, metaData, "hasattribute", model, name);
			if (!(zephir_is_true(_6))) {
				ZEPHIR_INIT_LNVAR(_11);
				object_init_ex(_11, phalcon_mvc_model_exception_ce);
				_12 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_13);
				ZEPHIR_CONCAT_SVSVSV(_13, "The model '", modelName, "' doesn't have the attribute '", name, "', when preparing: ", _12);
				zephir_call_method_p1_cache_noret(_11, "__construct", &_14, _13);
				zephir_throw_exception(_11 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&sqlFields, name, PH_SEPARATE);
		}
		zephir_array_update_string(&sqlInsert, SL("fields"), &sqlFields, PH_COPY | PH_SEPARATE);
	}
	zephir_array_update_string(&sqlInsert, SL("values"), &exprValues, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(sqlInsert);

}

/**
 * Analyzes an UPDATE intermediate code and produces an array to be executed later
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareUpdate) {

	zval *_9 = NULL;
	zend_function *_8 = NULL, *_12 = NULL;
	HashTable *_1, *_5;
	HashPosition _0, _4;
	zend_bool notQuoting;
	zval *ast, *update, *tables, *values, *modelsInstances, *models, *sqlTables, *sqlAliases, *sqlAliasesModelsInstances, *updateTables = NULL, *nsAlias = NULL, *realModelName = NULL, *completeSource = NULL, *sqlModels, *manager, *table = NULL, *qualifiedName = NULL, *modelName = NULL, *model = NULL, *source = NULL, *schema = NULL, *alias = NULL, *sqlFields, *sqlValues, *updateValues = NULL, *updateValue = NULL, *exprColumn = NULL, *sqlUpdate, *where, *limit, **_2, *_3 = NULL, **_6, *_7, *_10 = NULL, *_11 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(ast);
	zephir_read_property_this(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(update);
	if (!(zephir_array_isset_string_fetch(&update, ast, SS("update"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted UPDATE AST");
		return;
	}
	ZEPHIR_OBS_VAR(tables);
	if (!(zephir_array_isset_string_fetch(&tables, update, SS("tables"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted UPDATE AST");
		return;
	}
	ZEPHIR_OBS_VAR(values);
	if (!(zephir_array_isset_string_fetch(&values, update, SS("values"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted UPDATE AST");
		return;
	}
	ZEPHIR_INIT_VAR(models);
	array_init(models);
	ZEPHIR_INIT_VAR(modelsInstances);
	array_init(modelsInstances);
	ZEPHIR_INIT_VAR(sqlTables);
	array_init(sqlTables);
	ZEPHIR_INIT_VAR(sqlModels);
	array_init(sqlModels);
	ZEPHIR_INIT_VAR(sqlAliases);
	array_init(sqlAliases);
	ZEPHIR_INIT_VAR(sqlAliasesModelsInstances);
	array_init(sqlAliasesModelsInstances);
	if (!(zephir_array_isset_long(tables, 0))) {
		ZEPHIR_INIT_VAR(updateTables);
		array_init_size(updateTables, 2);
		zephir_array_fast_append(updateTables, tables);
	} else {
		ZEPHIR_CPY_WRT(updateTables, tables);
	}
	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	zephir_is_iterable(updateTables, &_1, &_0, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(table, _2);
		ZEPHIR_OBS_NVAR(qualifiedName);
		zephir_array_fetch_string(&qualifiedName, table, SL("qualifiedName"), PH_NOISY TSRMLS_CC);
		ZEPHIR_OBS_NVAR(modelName);
		zephir_array_fetch_string(&modelName, qualifiedName, SL("name"), PH_NOISY TSRMLS_CC);
		ZEPHIR_OBS_NVAR(nsAlias);
		if (zephir_array_isset_string_fetch(&nsAlias, qualifiedName, SS("ns-alias"), 0 TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_3);
			zephir_call_method_p1(_3, manager, "getnamespacealias", nsAlias);
			ZEPHIR_INIT_NVAR(realModelName);
			ZEPHIR_CONCAT_VSV(realModelName, _3, "\\", modelName);
		} else {
			ZEPHIR_CPY_WRT(realModelName, modelName);
		}
		ZEPHIR_INIT_NVAR(model);
		zephir_call_method_p1(model, manager, "load", realModelName);
		ZEPHIR_INIT_NVAR(source);
		zephir_call_method(source, model, "getsource");
		ZEPHIR_INIT_NVAR(schema);
		zephir_call_method(schema, model, "getschema");
		ZEPHIR_INIT_NVAR(completeSource);
		if (zephir_is_true(schema)) {
			array_init_size(completeSource, 3);
			zephir_array_fast_append(completeSource, source);
			zephir_array_fast_append(completeSource, schema);
		} else {
			array_init_size(completeSource, 3);
			zephir_array_fast_append(completeSource, source);
			zephir_array_fast_append(completeSource, ZEPHIR_GLOBAL(global_null));
		}
		ZEPHIR_OBS_NVAR(alias);
		if (zephir_array_isset_string_fetch(&alias, table, SS("alias"), 0 TSRMLS_CC)) {
			zephir_array_update_zval(&sqlAliases, alias, &alias, PH_COPY | PH_SEPARATE);
			zephir_array_append(&completeSource, alias, PH_SEPARATE);
			zephir_array_append(&sqlTables, completeSource, PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModelsInstances, alias, &model, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&models, alias, &modelName, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&sqlAliases, modelName, &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModelsInstances, modelName, &model, PH_COPY | PH_SEPARATE);
			zephir_array_append(&sqlTables, source, PH_SEPARATE);
			zephir_array_update_zval(&models, modelName, &source, PH_COPY | PH_SEPARATE);
		}
		zephir_array_append(&sqlModels, modelName, PH_SEPARATE);
		zephir_array_update_zval(&modelsInstances, modelName, &model, PH_COPY | PH_SEPARATE);
	}
	zephir_update_property_this(this_ptr, SL("_models"), models TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_modelsInstances"), modelsInstances TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_sqlAliases"), sqlAliases TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_sqlAliasesModelsInstances"), sqlAliasesModelsInstances TSRMLS_CC);
	ZEPHIR_INIT_VAR(sqlFields);
	array_init(sqlFields);
	ZEPHIR_INIT_VAR(sqlValues);
	array_init(sqlValues);
	if (!(zephir_array_isset_long(values, 0))) {
		ZEPHIR_INIT_VAR(updateValues);
		array_init_size(updateValues, 2);
		zephir_array_fast_append(updateValues, values);
	} else {
		ZEPHIR_CPY_WRT(updateValues, values);
	}
	notQuoting = 0;
	zephir_is_iterable(updateValues, &_5, &_4, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
		; zend_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(updateValue, _6);
		ZEPHIR_INIT_NVAR(_3);
		zephir_array_fetch_string(&_7, updateValue, SL("column"), PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_call_method_p2_cache(_3, this_ptr, "_getexpression", &_8, _7, (notQuoting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
		zephir_array_append(&sqlFields, _3, PH_SEPARATE);
		ZEPHIR_OBS_NVAR(exprColumn);
		zephir_array_fetch_string(&exprColumn, updateValue, SL("expr"), PH_NOISY TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_9);
		array_init_size(_9, 3);
		ZEPHIR_OBS_NVAR(_10);
		zephir_array_fetch_string(&_10, exprColumn, SL("type"), PH_NOISY TSRMLS_CC);
		zephir_array_update_string(&_9, SL("type"), &_10, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_11);
		zephir_call_method_p2_cache(_11, this_ptr, "_getexpression", &_12, exprColumn, (notQuoting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
		zephir_array_update_string(&_9, SL("value"), &_11, PH_COPY | PH_SEPARATE);
		zephir_array_append(&sqlValues, _9, PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(sqlUpdate);
	array_init_size(sqlUpdate, 7);
	zephir_array_update_string(&sqlUpdate, SL("tables"), &sqlTables, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlUpdate, SL("models"), &sqlModels, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlUpdate, SL("fields"), &sqlFields, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlUpdate, SL("values"), &sqlValues, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(where);
	if (zephir_array_isset_string_fetch(&where, ast, SS("where"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(_11);
		zephir_call_method_p2(_11, this_ptr, "_getexpression", where, ZEPHIR_GLOBAL(global_true));
		zephir_array_update_string(&sqlUpdate, SL("where"), &_11, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&limit, ast, SS("limit"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&sqlUpdate, SL("limit"), &limit, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(sqlUpdate);

}

/**
 * Analyzes a DELETE intermediate code and produces an array to be executed later
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareDelete) {

	HashTable *_1;
	HashPosition _0;
	zval *ast, *delete, *tables, *models, *modelsInstances, *sqlTables, *sqlModels, *sqlAliases, *sqlAliasesModelsInstances, *deleteTables = NULL, *manager, *table = NULL, *qualifiedName = NULL, *modelName = NULL, *nsAlias = NULL, *realModelName = NULL, *model = NULL, *source = NULL, *schema = NULL, *completeSource = NULL, *alias = NULL, *sqlDelete, *where, *limit, **_2, *_3 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(ast);
	zephir_read_property_this(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(delete);
	if (!(zephir_array_isset_string_fetch(&delete, ast, SS("delete"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted DELETE AST");
		return;
	}
	ZEPHIR_OBS_VAR(tables);
	if (!(zephir_array_isset_string_fetch(&tables, delete, SS("tables"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted DELETE AST");
		return;
	}
	ZEPHIR_INIT_VAR(models);
	array_init(models);
	ZEPHIR_INIT_VAR(modelsInstances);
	array_init(modelsInstances);
	ZEPHIR_INIT_VAR(sqlTables);
	array_init(sqlTables);
	ZEPHIR_INIT_VAR(sqlModels);
	array_init(sqlModels);
	ZEPHIR_INIT_VAR(sqlAliases);
	array_init(sqlAliases);
	ZEPHIR_INIT_VAR(sqlAliasesModelsInstances);
	array_init(sqlAliasesModelsInstances);
	if (!(zephir_array_isset_long(tables, 0))) {
		ZEPHIR_INIT_VAR(deleteTables);
		array_init_size(deleteTables, 2);
		zephir_array_fast_append(deleteTables, tables);
	} else {
		ZEPHIR_CPY_WRT(deleteTables, tables);
	}
	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	zephir_is_iterable(deleteTables, &_1, &_0, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(table, _2);
		ZEPHIR_OBS_NVAR(qualifiedName);
		zephir_array_fetch_string(&qualifiedName, table, SL("qualifiedName"), PH_NOISY TSRMLS_CC);
		ZEPHIR_OBS_NVAR(modelName);
		zephir_array_fetch_string(&modelName, qualifiedName, SL("name"), PH_NOISY TSRMLS_CC);
		ZEPHIR_OBS_NVAR(nsAlias);
		if (zephir_array_isset_string_fetch(&nsAlias, qualifiedName, SS("ns-alias"), 0 TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_3);
			zephir_call_method_p1(_3, manager, "getnamespacealias", nsAlias);
			ZEPHIR_INIT_NVAR(realModelName);
			ZEPHIR_CONCAT_VSV(realModelName, _3, "\\", modelName);
		} else {
			ZEPHIR_CPY_WRT(realModelName, modelName);
		}
		ZEPHIR_INIT_NVAR(model);
		zephir_call_method_p1(model, manager, "load", realModelName);
		ZEPHIR_INIT_NVAR(source);
		zephir_call_method(source, model, "getsource");
		ZEPHIR_INIT_NVAR(schema);
		zephir_call_method(schema, model, "getschema");
		ZEPHIR_INIT_NVAR(completeSource);
		if (zephir_is_true(schema)) {
			array_init_size(completeSource, 3);
			zephir_array_fast_append(completeSource, source);
			zephir_array_fast_append(completeSource, schema);
		} else {
			array_init_size(completeSource, 3);
			zephir_array_fast_append(completeSource, source);
			zephir_array_fast_append(completeSource, ZEPHIR_GLOBAL(global_null));
		}
		ZEPHIR_OBS_NVAR(alias);
		if (zephir_array_isset_string_fetch(&alias, table, SS("alias"), 0 TSRMLS_CC)) {
			zephir_array_update_zval(&sqlAliases, alias, &alias, PH_COPY | PH_SEPARATE);
			zephir_array_append(&completeSource, alias, PH_SEPARATE);
			zephir_array_append(&sqlTables, completeSource, PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModelsInstances, alias, &model, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&models, alias, &modelName, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&sqlAliases, modelName, &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModelsInstances, modelName, &model, PH_COPY | PH_SEPARATE);
			zephir_array_append(&sqlTables, source, PH_SEPARATE);
			zephir_array_update_zval(&models, modelName, &source, PH_COPY | PH_SEPARATE);
		}
		zephir_array_append(&sqlModels, modelName, PH_SEPARATE);
		zephir_array_update_zval(&modelsInstances, modelName, &model, PH_COPY | PH_SEPARATE);
	}
	zephir_update_property_this(this_ptr, SL("_models"), models TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_modelsInstances"), modelsInstances TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_sqlAliases"), sqlAliases TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_sqlAliasesModelsInstances"), sqlAliasesModelsInstances TSRMLS_CC);
	ZEPHIR_INIT_VAR(sqlDelete);
	array_init(sqlDelete);
	zephir_array_update_string(&sqlDelete, SL("tables"), &sqlTables, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlDelete, SL("models"), &sqlModels, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(where);
	if (zephir_array_isset_string_fetch(&where, ast, SS("where"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(_3);
		zephir_call_method_p2(_3, this_ptr, "_getexpression", where, ZEPHIR_GLOBAL(global_true));
		zephir_array_update_string(&sqlDelete, SL("where"), &_3, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&limit, ast, SS("limit"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&sqlDelete, SL("limit"), &limit, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(sqlDelete);

}

/**
 * Parses the intermediate code produced by Phalcon\Mvc\Model\Query\Lang generating another
 * intermediate representation that could be executed by Phalcon\Mvc\Model\Query
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, parse) {

	zval *intermediate, *phql, *ast, *irPhql = NULL, irPhqlCache, *uniqueId = NULL, *type, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(intermediate);
	zephir_read_property_this(&intermediate, this_ptr, SL("_intermediate"), PH_NOISY_CC);
	if ((Z_TYPE_P(intermediate) == IS_ARRAY)) {
		RETURN_CCTOR(intermediate);
	}
	ZEPHIR_OBS_VAR(phql);
	zephir_read_property_this(&phql, this_ptr, SL("_phql"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(ast);
	if (phql_parse_phql(ast, phql TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(irPhql);
	ZVAL_NULL(irPhql);
	ZEPHIR_SINIT_VAR(irPhqlCache);
	ZVAL_NULL(&irPhqlCache);
	ZEPHIR_INIT_VAR(uniqueId);
	ZVAL_NULL(uniqueId);
	if ((Z_TYPE_P(ast) == IS_ARRAY)) {
		ZEPHIR_OBS_NVAR(uniqueId);
		if (zephir_array_isset_string_fetch(&uniqueId, ast, SS("id"), 0 TSRMLS_CC)) {
			ZEPHIR_OBS_NVAR(irPhql);
			_0 = zephir_fetch_static_property_ce(phalcon_mvc_model_query_ce, SL("_irPhqlCache") TSRMLS_CC);
			if (zephir_array_isset_fetch(&irPhql, _0, uniqueId, 0 TSRMLS_CC)) {
				if ((Z_TYPE_P(irPhql) == IS_ARRAY)) {
					zephir_array_fetch_string(&_1, ast, SL("type"), PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_update_property_this(this_ptr, SL("_type"), _1 TSRMLS_CC);
					RETURN_CCTOR(irPhql);
				}
			}
		}
		ZEPHIR_OBS_VAR(type);
		if (zephir_array_isset_string_fetch(&type, ast, SS("type"), 0 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
			do {
				if (ZEPHIR_IS_LONG(type, 309)) {
					ZEPHIR_INIT_BNVAR(irPhql);
					zephir_call_method(irPhql, this_ptr, "_prepareselect");
					break;
				}
				if (ZEPHIR_IS_LONG(type, 306)) {
					ZEPHIR_INIT_BNVAR(irPhql);
					zephir_call_method(irPhql, this_ptr, "_prepareinsert");
					break;
				}
				if (ZEPHIR_IS_LONG(type, 300)) {
					ZEPHIR_INIT_BNVAR(irPhql);
					zephir_call_method(irPhql, this_ptr, "_prepareupdate");
					break;
				}
				if (ZEPHIR_IS_LONG(type, 303)) {
					ZEPHIR_INIT_BNVAR(irPhql);
					zephir_call_method(irPhql, this_ptr, "_preparedelete");
					break;
				}
				ZEPHIR_INIT_VAR(_2);
				object_init_ex(_2, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(_3);
				ZEPHIR_CONCAT_SVSV(_3, "Unknown statement ", type, ", when preparing: ", phql);
				zephir_call_method_p1_noret(_2, "__construct", _3);
				zephir_throw_exception(_2 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			} while(0);

		}
	}
	if ((Z_TYPE_P(irPhql) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted AST");
		return;
	}
	if ((Z_TYPE_P(uniqueId) == IS_LONG)) {
	}
	zephir_update_property_this(this_ptr, SL("_intermediate"), irPhql TSRMLS_CC);
	RETURN_CCTOR(irPhql);

}

/**
 * Returns the current cache backend instance
 *
 * @return Phalcon\Cache\BackendInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getCache) {


	RETURN_MEMBER(this_ptr, "_cache");

}

/**
 * Executes the SELECT intermediate representation producing a Phalcon\Mvc\Model\Resultset
 *
 * @param array intermediate
 * @param array bindParams
 * @param array bindTypes
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeSelect) {

	zval *_15 = NULL;
	HashTable *_2, *_6, *_10, *_13, *_18, *_21, *_24;
	HashPosition _1, _5, _9, _12, _17, _20, _23;
	int numberObjects;
	zend_bool resultData, haveObjects, haveScalars, isComplex, isSimpleStd;
	zval *intermediate, *bindParams, *bindTypes, *manager, *modelName = NULL, *models, *model = NULL, *connection = NULL, *connections, *columns, *column = NULL, *selectColumns, *simpleColumnMap, *metaData, *aliasCopy = NULL, *sqlColumn = NULL, *attributes = NULL, *instance = NULL, *columnMap = NULL, *attribute = NULL, *isKeepingSnapshots = NULL, *columnAlias = NULL, *sqlAlias = NULL, *dialect, *sqlSelect, *processed = NULL, *wildcard = NULL, *value = NULL, *processedTypes = NULL, *typeWildcard = NULL, *result, *cache, *resultObject = NULL, *_0, **_3, *_4 = NULL, **_7, *_8, **_11, **_14, *_16 = NULL, **_19, **_22, **_25, *_26 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &intermediate, &bindParams, &bindTypes);

	ZEPHIR_SEPARATE_PARAM(intermediate);


	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(models);
	zephir_array_fetch_string(&models, intermediate, SL("models"), PH_NOISY TSRMLS_CC);
	if ((zephir_fast_count_int(models TSRMLS_CC) == 1)) {
		ZEPHIR_OBS_VAR(modelName);
		zephir_array_fetch_long(&modelName, models, 0, PH_NOISY TSRMLS_CC);
		ZEPHIR_OBS_VAR(model);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
		if (!(zephir_array_isset_fetch(&model, _0, modelName, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(model);
			zephir_call_method_p1(model, manager, "load", modelName);
			zephir_update_property_array(this_ptr, SL("_modelsInstances"), modelName, model TSRMLS_CC);
		}
		ZEPHIR_INIT_VAR(connection);
		if ((zephir_method_exists_ex(model, SS("selectreadconnection") TSRMLS_CC) == SUCCESS)) {
			zephir_call_method_p3(connection, model, "selectreadconnection", intermediate, bindParams, bindTypes);
			if ((Z_TYPE_P(connection) != IS_OBJECT)) {
				ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "'selectReadConnection' didn't return a valid connection");
				return;
			}
		} else {
			zephir_call_method(connection, model, "getreadconnection");
		}
	} else {
		ZEPHIR_INIT_VAR(connections);
		array_init(connections);
		zephir_is_iterable(models, &_2, &_1, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
			; zend_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(modelName, _3);
			ZEPHIR_OBS_NVAR(model);
			_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
			if (!(zephir_array_isset_fetch(&model, _0, modelName, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(model);
				zephir_call_method_p1(model, manager, "load", modelName);
				zephir_update_property_array(this_ptr, SL("_modelsInstances"), modelName, model TSRMLS_CC);
			}
			ZEPHIR_INIT_NVAR(connection);
			zephir_call_method(connection, model, "getreadconnection");
			ZEPHIR_INIT_NVAR(_4);
			zephir_call_method(_4, connection, "gettype");
			zephir_array_update_zval(&connections, _4, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
			if ((zephir_fast_count_int(connections TSRMLS_CC) == 2)) {
				ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Cannot use models of different database systems in the same query");
				return;
			}
		}
	}
	ZEPHIR_OBS_VAR(columns);
	zephir_array_fetch_string(&columns, intermediate, SL("columns"), PH_NOISY TSRMLS_CC);
	haveObjects = 0;
	haveScalars = 0;
	isComplex = 0;
	numberObjects = 0;
	zephir_is_iterable(columns, &_6, &_5, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
		; zend_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HVALUE(column, _7);
		zephir_array_fetch_string(&_8, column, SL("type"), PH_NOISY | PH_READONLY TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_8, "scalar")) {
			if (!(zephir_array_isset_string(column, SS("balias")))) {
				isComplex = 1;
			}
			haveScalars = 1;
		} else {
			haveObjects = 1;
			numberObjects++;
		}
	}
	if ((isComplex == 0)) {
		if ((haveObjects == 1)) {
			if ((haveScalars == 1)) {
				isComplex = 1;
			} else {
				if ((numberObjects == 1)) {
					isSimpleStd = 0;
				} else {
					isComplex = 1;
				}
			}
		} else {
			isSimpleStd = 1;
		}
	}
	ZEPHIR_INIT_VAR(selectColumns);
	array_init(selectColumns);
	ZEPHIR_INIT_VAR(simpleColumnMap);
	array_init(simpleColumnMap);
	ZEPHIR_OBS_VAR(metaData);
	zephir_read_property_this(&metaData, this_ptr, SL("_metaData"), PH_NOISY_CC);
	zephir_is_iterable(columns, &_10, &_9, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
		; zend_hash_move_forward_ex(_10, &_9)
	) {
		ZEPHIR_GET_HMKEY(aliasCopy, _10, _9);
		ZEPHIR_GET_HVALUE(column, _11);
		ZEPHIR_OBS_NVAR(sqlColumn);
		zephir_array_fetch_string(&sqlColumn, column, SL("column"), PH_NOISY TSRMLS_CC);
		zephir_array_fetch_string(&_8, column, SL("type"), PH_NOISY | PH_READONLY TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_8, "object")) {
			ZEPHIR_OBS_NVAR(modelName);
			zephir_array_fetch_string(&modelName, column, SL("model"), PH_NOISY TSRMLS_CC);
			ZEPHIR_OBS_NVAR(instance);
			_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
			if (!(zephir_array_isset_fetch(&instance, _0, modelName, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(instance);
				zephir_call_method_p1(instance, manager, "load", modelName);
				zephir_update_property_array(this_ptr, SL("_modelsInstances"), modelName, instance TSRMLS_CC);
			}
			ZEPHIR_INIT_NVAR(attributes);
			zephir_call_method_p1(attributes, metaData, "getattributes", instance);
			if ((isComplex == 1)) {
				ZEPHIR_INIT_NVAR(columnMap);
				if (ZEPHIR_GLOBAL(orm).column_renaming) {
					zephir_call_method_p1(columnMap, metaData, "getcolumnmap", instance);
				} else {
					ZVAL_NULL(columnMap);
				}
				zephir_is_iterable(attributes, &_13, &_12, 0, 0);
				for (
					; zend_hash_get_current_data_ex(_13, (void**) &_14, &_12) == SUCCESS
					; zend_hash_move_forward_ex(_13, &_12)
				) {
					ZEPHIR_GET_HVALUE(attribute, _14);
					ZEPHIR_INIT_NVAR(_15);
					array_init_size(_15, 5);
					zephir_array_fast_append(_15, attribute);
					zephir_array_fast_append(_15, sqlColumn);
					ZEPHIR_INIT_LNVAR(_16);
					ZEPHIR_CONCAT_SVSV(_16, "_", sqlColumn, "_", attribute);
					zephir_array_fast_append(_15, _16);
					zephir_array_append(&selectColumns, _15, PH_SEPARATE);
				}
				zephir_array_update_multi(&columns, &instance TSRMLS_CC, SL("zs"), 3, aliasCopy, SL("instance"));
				zephir_array_update_multi(&columns, &attributes TSRMLS_CC, SL("zs"), 3, aliasCopy, SL("attributes"));
				zephir_array_update_multi(&columns, &columnMap TSRMLS_CC, SL("zs"), 3, aliasCopy, SL("columnMap"));
				ZEPHIR_INIT_NVAR(isKeepingSnapshots);
				zephir_call_method_p1(isKeepingSnapshots, manager, "iskeepingsnapshots", instance);
				if (zephir_is_true(isKeepingSnapshots)) {
					zephir_array_update_multi(&columns, &isKeepingSnapshots TSRMLS_CC, SL("zs"), 3, aliasCopy, SL("keepSnapshots"));
				}
			} else {
				zephir_is_iterable(attributes, &_18, &_17, 0, 0);
				for (
					; zend_hash_get_current_data_ex(_18, (void**) &_19, &_17) == SUCCESS
					; zend_hash_move_forward_ex(_18, &_17)
				) {
					ZEPHIR_GET_HVALUE(attribute, _19);
					ZEPHIR_INIT_NVAR(_15);
					array_init_size(_15, 3);
					zephir_array_fast_append(_15, attribute);
					zephir_array_fast_append(_15, sqlColumn);
					zephir_array_append(&selectColumns, _15, PH_SEPARATE);
				}
			}
		} else {
			ZEPHIR_INIT_NVAR(columnAlias);
			if ((Z_TYPE_P(aliasCopy) == IS_LONG)) {
				array_init_size(columnAlias, 3);
				zephir_array_fast_append(columnAlias, sqlColumn);
				zephir_array_fast_append(columnAlias, ZEPHIR_GLOBAL(global_null));
			} else {
				array_init_size(columnAlias, 5);
				zephir_array_fast_append(columnAlias, sqlColumn);
				zephir_array_fast_append(columnAlias, ZEPHIR_GLOBAL(global_null));
				zephir_array_fast_append(columnAlias, aliasCopy);
			}
			zephir_array_append(&selectColumns, columnAlias, PH_SEPARATE);
		}
		if ((isComplex == 0)) {
			if ((isSimpleStd == 1)) {
				ZEPHIR_OBS_NVAR(sqlAlias);
				if (zephir_array_isset_string_fetch(&sqlAlias, column, SS("sqlAlias"), 0 TSRMLS_CC)) {
					zephir_array_update_zval(&simpleColumnMap, sqlAlias, &aliasCopy, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&simpleColumnMap, aliasCopy, &aliasCopy, PH_COPY | PH_SEPARATE);
				}
			}
		}
	}
	zephir_array_update_string(&intermediate, SL("columns"), &selectColumns, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(dialect);
	zephir_call_method(dialect, connection, "getdialect");
	ZEPHIR_INIT_VAR(sqlSelect);
	zephir_call_method_p1(sqlSelect, dialect, "select", intermediate);
	if ((Z_TYPE_P(bindParams) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(processed);
		array_init(processed);
		zephir_is_iterable(bindParams, &_21, &_20, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_21, (void**) &_22, &_20) == SUCCESS
			; zend_hash_move_forward_ex(_21, &_20)
		) {
			ZEPHIR_GET_HMKEY(wildcard, _21, _20);
			ZEPHIR_GET_HVALUE(value, _22);
			if ((Z_TYPE_P(wildcard) == IS_LONG)) {
				ZEPHIR_INIT_LNVAR(_16);
				ZEPHIR_CONCAT_SV(_16, ":", wildcard);
				zephir_array_update_zval(&processed, _16, &value, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&processed, wildcard, &value, PH_COPY | PH_SEPARATE);
			}
		}
	} else {
		ZEPHIR_CPY_WRT(processed, bindParams);
	}
	if ((Z_TYPE_P(bindTypes) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(processedTypes);
		array_init(processedTypes);
		zephir_is_iterable(bindTypes, &_24, &_23, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_24, (void**) &_25, &_23) == SUCCESS
			; zend_hash_move_forward_ex(_24, &_23)
		) {
			ZEPHIR_GET_HMKEY(typeWildcard, _24, _23);
			ZEPHIR_GET_HVALUE(value, _25);
			if ((Z_TYPE_P(typeWildcard) == IS_STRING)) {
				ZEPHIR_INIT_LNVAR(_26);
				ZEPHIR_CONCAT_SV(_26, ":", typeWildcard);
				zephir_array_update_zval(&processedTypes, _26, &value, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&processedTypes, typeWildcard, &value, PH_COPY | PH_SEPARATE);
			}
		}
	} else {
		ZEPHIR_CPY_WRT(processedTypes, bindTypes);
	}
	ZEPHIR_INIT_VAR(result);
	zephir_call_method_p3(result, connection, "query", sqlSelect, processed, processedTypes);
	ZEPHIR_INIT_NVAR(_4);
	zephir_call_method_p1(_4, result, "numrows", result);
	if (zephir_is_true(_4)) {
		resultData = zephir_is_true(result);
	} else {
		resultData = 0;
	}
	ZEPHIR_OBS_VAR(cache);
	zephir_read_property_this(&cache, this_ptr, SL("_cache"), PH_NOISY_CC);
	if ((isComplex == 0)) {
		ZEPHIR_INIT_NVAR(isKeepingSnapshots);
		if ((isSimpleStd == 1)) {
			ZEPHIR_INIT_VAR(resultObject);
			object_init_ex(resultObject, phalcon_mvc_model_row_ce);
			if (zephir_has_constructor(resultObject TSRMLS_CC)) {
				zephir_call_method_noret(resultObject, "__construct");
			}
			ZVAL_BOOL(isKeepingSnapshots, 0);
		} else {
			ZEPHIR_CPY_WRT(resultObject, model);
			ZEPHIR_INIT_BNVAR(simpleColumnMap);
			zephir_call_method_p1(simpleColumnMap, metaData, "getcolumnmap", model);
			zephir_call_method_p1(isKeepingSnapshots, manager, "iskeepingsnapshots", model);
		}
		object_init_ex(return_value, phalcon_mvc_model_resultset_simple_ce);
		zephir_call_method_p5_noret(return_value, "__construct", simpleColumnMap, resultObject, (resultData ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)), cache, isKeepingSnapshots);
		RETURN_MM();
	}
	object_init_ex(return_value, phalcon_mvc_model_resultset_complex_ce);
	zephir_call_method_p3_noret(return_value, "__construct", columns, (resultData ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)), cache);
	RETURN_MM();

}

/**
 * Executes the INSERT intermediate representation producing a Phalcon\Mvc\Model\Query\Status
 *
 * @param array intermediate
 * @param array bindParams
 * @param array bindTypes
 * @return Phalcon\Mvc\Model\Query\StatusInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeInsert) {

	zend_function *_10 = NULL, *_11 = NULL, *_12 = NULL;
	HashTable *_2;
	HashPosition _1;
	zend_bool notExists, automaticFields;
	zval *intermediate, *bindParams, *bindTypes, *modelName, *manager, *connection, *metaData, *attributes, *fields = NULL, *columnMap, *dialect, *insertValues, *number = NULL, *value = NULL, *model, *values, *exprValue = NULL, *insertValue = NULL, *wildcard = NULL, *fieldName = NULL, *attributeName = NULL, *insertModel, *_0, **_3, *_4, *_5 = NULL, _6 = zval_used_for_init, _7 = zval_used_for_init, *_8 = NULL, *_9 = NULL, *_13;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &intermediate, &bindParams, &bindTypes);



	ZEPHIR_OBS_VAR(modelName);
	zephir_array_fetch_string(&modelName, intermediate, SL("model"), PH_NOISY TSRMLS_CC);
	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(model);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&model, _0, modelName, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_BNVAR(model);
		zephir_call_method_p1(model, manager, "load", modelName);
	}
	ZEPHIR_INIT_VAR(connection);
	if ((zephir_method_exists_ex(model, SS("selectwriteconnection") TSRMLS_CC) == SUCCESS)) {
		zephir_call_method_p3(connection, model, "selectwriteconnection", intermediate, bindParams, bindTypes);
		if ((Z_TYPE_P(connection) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "'selectWriteConnection' didn't return a valid connection");
			return;
		}
	} else {
		zephir_call_method(connection, model, "getwriteconnection");
	}
	ZEPHIR_OBS_VAR(metaData);
	zephir_read_property_this(&metaData, this_ptr, SL("_metaData"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(attributes);
	zephir_call_method_p1(attributes, metaData, "getattributes", model);
	automaticFields = 0;
	ZEPHIR_OBS_VAR(fields);
	if (!(zephir_array_isset_string_fetch(&fields, intermediate, SS("fields"), 0 TSRMLS_CC))) {
		automaticFields = 1;
		ZEPHIR_CPY_WRT(fields, attributes);
		ZEPHIR_INIT_VAR(columnMap);
		if (ZEPHIR_GLOBAL(orm).column_renaming) {
			zephir_call_method_p1(columnMap, metaData, "getcolumnmap", model);
		} else {
			ZVAL_NULL(columnMap);
		}
	}
	ZEPHIR_OBS_VAR(values);
	zephir_array_fetch_string(&values, intermediate, SL("values"), PH_NOISY TSRMLS_CC);
	if ((zephir_fast_count_int(fields TSRMLS_CC) != zephir_fast_count_int(values TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The column count does not match the values count");
		return;
	}
	ZEPHIR_INIT_VAR(dialect);
	zephir_call_method(dialect, connection, "getdialect");
	notExists = 0;
	ZEPHIR_INIT_VAR(insertValues);
	array_init(insertValues);
	zephir_is_iterable(values, &_2, &_1, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(number, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		ZEPHIR_OBS_NVAR(exprValue);
		zephir_array_fetch_string(&exprValue, value, SL("value"), PH_NOISY TSRMLS_CC);
		zephir_array_fetch_string(&_4, value, SL("type"), PH_NOISY | PH_READONLY TSRMLS_CC);
		do {
			if (ZEPHIR_IS_LONG(_4, 260) || ZEPHIR_IS_LONG(_4, 258) || ZEPHIR_IS_LONG(_4, 259)) {
				ZEPHIR_INIT_NVAR(insertValue);
				zephir_call_method_p1(insertValue, dialect, "getsqlexpression", exprValue);
				break;
			}
			if (ZEPHIR_IS_LONG(_4, 322)) {
				ZEPHIR_INIT_NVAR(insertValue);
				ZVAL_NULL(insertValue);
				break;
			}
			if (ZEPHIR_IS_LONG(_4, 273) || ZEPHIR_IS_LONG(_4, 274)) {
				if ((Z_TYPE_P(bindParams) != IS_ARRAY)) {
					ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Bound parameter cannot be replaced because placeholders is not an array");
					return;
				}
				ZEPHIR_INIT_NVAR(wildcard);
				ZEPHIR_INIT_NVAR(_5);
				zephir_call_method_p1(_5, dialect, "getsqlexpression", exprValue);
				ZEPHIR_SINIT_NVAR(_6);
				ZVAL_STRING(&_6, ":", 0);
				ZEPHIR_SINIT_NVAR(_7);
				ZVAL_STRING(&_7, "", 0);
				zephir_fast_str_replace(wildcard, &_6, &_7, _5);
				ZEPHIR_OBS_NVAR(insertValue);
				if (!(zephir_array_isset_fetch(&insertValue, bindParams, wildcard, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_LNVAR(_8);
					object_init_ex(_8, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_9);
					ZEPHIR_CONCAT_SVS(_9, "Bound parameter '", wildcard, "' cannot be replaced because it isn't in the placeholders list");
					zephir_call_method_p1_cache_noret(_8, "__construct", &_10, _9);
					zephir_throw_exception(_8 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				break;
			}
			ZEPHIR_INIT_NVAR(insertValue);
			object_init_ex(insertValue, phalcon_db_rawvalue_ce);
			ZEPHIR_INIT_NVAR(_5);
			zephir_call_method_p1(_5, dialect, "getsqlexpression", exprValue);
			zephir_call_method_p1_cache_noret(insertValue, "__construct", &_11, _5);
			break;
		} while(0);

		ZEPHIR_OBS_NVAR(fieldName);
		zephir_array_fetch(&fieldName, fields, number, PH_NOISY TSRMLS_CC);
		if ((automaticFields == 1)) {
			if ((Z_TYPE_P(columnMap) == IS_ARRAY)) {
				ZEPHIR_OBS_NVAR(attributeName);
				if (!(zephir_array_isset_fetch(&attributeName, columnMap, fieldName, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_LNVAR(_8);
					object_init_ex(_8, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_9);
					ZEPHIR_CONCAT_SVS(_9, "Column '", fieldName, "' isn't part of the column map");
					zephir_call_method_p1_cache_noret(_8, "__construct", &_12, _9);
					zephir_throw_exception(_8 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(attributeName, fieldName);
			}
		} else {
			ZEPHIR_CPY_WRT(attributeName, fieldName);
		}
		zephir_array_update_zval(&insertValues, attributeName, &insertValue, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_NVAR(_5);
	zephir_call_method_p1(_5, manager, "load", modelName);
	ZEPHIR_INIT_VAR(insertModel);
	if (zephir_clone(insertModel, _5 TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	ZEPHIR_INIT_VAR(_13);
	zephir_call_method_p1(_13, insertModel, "create", insertValues);
	zephir_call_method_p2_noret(return_value, "__construct", _13, insertModel);
	RETURN_MM();

}

/**
 * Executes the UPDATE intermediate representation producing a Phalcon\Mvc\Model\Query\Status
 *
 * @param array intermediate
 * @param array bindParams
 * @param array bindTypes
 * @return Phalcon\Mvc\Model\Query\StatusInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeUpdate) {

	zend_function *_13 = NULL, *_14 = NULL, *_19 = NULL;
	HashTable *_3, *_16;
	HashPosition _2, _15;
	zval *intermediate, *bindParams, *bindTypes, *models, *modelName, *model, *connection, *dialect, *fields, *values, *updateValues, *fieldName = NULL, *value = NULL, *selectBindParams = NULL, *selectBindTypes = NULL, *number = NULL, *field = NULL, *records, *exprValue = NULL, *updateValue = NULL, *wildcard = NULL, *record = NULL, *_0, *_1, **_4, *_5, *_6 = NULL, _7 = zval_used_for_init, _8 = zval_used_for_init, *_9, *_10, *_11 = NULL, *_12 = NULL, **_17, *_18 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &intermediate, &bindParams, &bindTypes);



	ZEPHIR_OBS_VAR(models);
	zephir_array_fetch_string(&models, intermediate, SL("models"), PH_NOISY TSRMLS_CC);
	if (zephir_array_isset_long(models, 1)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Updating several models at the same time is still not supported");
		return;
	}
	ZEPHIR_OBS_VAR(modelName);
	zephir_array_fetch_long(&modelName, models, 0, PH_NOISY TSRMLS_CC);
	ZEPHIR_OBS_VAR(model);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&model, _0, modelName, 0 TSRMLS_CC))) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_manager"), PH_NOISY_CC);
		ZEPHIR_INIT_BNVAR(model);
		zephir_call_method_p1(model, _1, "load", modelName);
	}
	ZEPHIR_INIT_VAR(connection);
	if ((zephir_method_exists_ex(model, SS("selectwriteconnection") TSRMLS_CC) == SUCCESS)) {
		zephir_call_method_p3(connection, model, "selectwriteconnection", intermediate, bindParams, bindTypes);
		if ((Z_TYPE_P(connection) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "'selectWriteConnection' didn't return a valid connection");
			return;
		}
	} else {
		zephir_call_method(connection, model, "getwriteconnection");
	}
	ZEPHIR_INIT_VAR(dialect);
	zephir_call_method(dialect, connection, "getdialect");
	ZEPHIR_OBS_VAR(fields);
	zephir_array_fetch_string(&fields, intermediate, SL("fields"), PH_NOISY TSRMLS_CC);
	ZEPHIR_OBS_VAR(values);
	zephir_array_fetch_string(&values, intermediate, SL("values"), PH_NOISY TSRMLS_CC);
	ZEPHIR_INIT_VAR(updateValues);
	array_init(updateValues);
	ZEPHIR_CPY_WRT(selectBindParams, bindParams);
	ZEPHIR_CPY_WRT(selectBindTypes, bindTypes);
	zephir_is_iterable(fields, &_3, &_2, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		; zend_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(number, _3, _2);
		ZEPHIR_GET_HVALUE(field, _4);
		ZEPHIR_OBS_NVAR(fieldName);
		zephir_array_fetch_string(&fieldName, field, SL("name"), PH_NOISY TSRMLS_CC);
		ZEPHIR_OBS_NVAR(value);
		zephir_array_fetch(&value, values, number, PH_NOISY TSRMLS_CC);
		ZEPHIR_OBS_NVAR(exprValue);
		zephir_array_fetch_string(&exprValue, value, SL("value"), PH_NOISY TSRMLS_CC);
		zephir_array_fetch_string(&_5, value, SL("type"), PH_NOISY | PH_READONLY TSRMLS_CC);
		do {
			if (ZEPHIR_IS_LONG(_5, 260) || ZEPHIR_IS_LONG(_5, 258) || ZEPHIR_IS_LONG(_5, 259)) {
				ZEPHIR_INIT_NVAR(updateValue);
				zephir_call_method_p1(updateValue, dialect, "getsqlexpression", exprValue);
				break;
			}
			if (ZEPHIR_IS_LONG(_5, 322)) {
				ZEPHIR_INIT_NVAR(updateValue);
				ZVAL_NULL(updateValue);
				break;
			}
			if (ZEPHIR_IS_LONG(_5, 273) || ZEPHIR_IS_LONG(_5, 274)) {
				if ((Z_TYPE_P(bindParams) == IS_ARRAY)) {
					ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Bound parameter cannot be replaced because placeholders is not an array");
					return;
				}
				ZEPHIR_INIT_NVAR(wildcard);
				ZEPHIR_INIT_NVAR(_6);
				zephir_call_method_p1(_6, dialect, "getsqlexpression", exprValue);
				ZEPHIR_SINIT_NVAR(_7);
				ZVAL_STRING(&_7, ":", 0);
				ZEPHIR_SINIT_NVAR(_8);
				ZVAL_STRING(&_8, "", 0);
				zephir_fast_str_replace(wildcard, &_7, &_8, _6);
				ZEPHIR_OBS_NVAR(updateValue);
				if (zephir_array_isset_fetch(&updateValue, bindParams, wildcard, 0 TSRMLS_CC)) {
					zephir_array_fetch(&_9, selectBindParams, wildcard, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_unset(&selectBindParams, _9, PH_SEPARATE);
					zephir_array_fetch(&_10, selectBindTypes, wildcard, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_unset(&selectBindTypes, _10, PH_SEPARATE);
				} else {
					ZEPHIR_INIT_LNVAR(_11);
					object_init_ex(_11, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_12);
					ZEPHIR_CONCAT_SVS(_12, "Bound parameter '", wildcard, "' cannot be replaced because it's not in the placeholders list");
					zephir_call_method_p1_cache_noret(_11, "__construct", &_13, _12);
					zephir_throw_exception(_11 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				break;
			}
			ZEPHIR_INIT_NVAR(updateValue);
			object_init_ex(updateValue, phalcon_db_rawvalue_ce);
			ZEPHIR_INIT_NVAR(_6);
			zephir_call_method_p1(_6, dialect, "getsqlexpression", exprValue);
			zephir_call_method_p1_cache_noret(updateValue, "__construct", &_14, _6);
			break;
		} while(0);

		zephir_array_update_zval(&updateValues, fieldName, &updateValue, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(records);
	zephir_call_method_p4(records, this_ptr, "_getrelatedrecords", model, intermediate, selectBindParams, selectBindTypes);
	if (!(zephir_fast_count_int(records TSRMLS_CC))) {
		object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
		zephir_call_method_p2_noret(return_value, "__construct", ZEPHIR_GLOBAL(global_true), ZEPHIR_GLOBAL(global_null));
		RETURN_MM();
	}
	ZEPHIR_INIT_BNVAR(connection);
	if ((zephir_method_exists_ex(model, SS("selectwriteconnection") TSRMLS_CC) == SUCCESS)) {
		zephir_call_method_p3(connection, model, "selectwriteconnection", intermediate, bindParams, bindTypes);
		if ((Z_TYPE_P(connection) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "'selectWriteConnection' didn't return a valid connection");
			return;
		}
	} else {
		zephir_call_method(connection, model, "getwriteconnection");
	}
	zephir_call_method_noret(connection, "begin");
	ZEPHIR_INIT_NVAR(_6);
	zephir_call_func_p1(_6, "iterator", records);
	zephir_is_iterable(_6, &_16, &_15, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_16, (void**) &_17, &_15) == SUCCESS
		; zend_hash_move_forward_ex(_16, &_15)
	) {
		ZEPHIR_GET_HVALUE(record, _17);
		ZEPHIR_INIT_NVAR(_18);
		zephir_call_method_p1(_18, record, "update", updateValues);
		if (!(zephir_is_true(_18))) {
			zephir_call_method_noret(connection, "rollback");
			object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
			zephir_call_method_p2_cache_noret(return_value, "__construct", &_19, ZEPHIR_GLOBAL(global_false), record);
			RETURN_MM();
		}
	}
	zephir_call_method_noret(connection, "commit");
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	zephir_call_method_p2_noret(return_value, "__construct", ZEPHIR_GLOBAL(global_true), ZEPHIR_GLOBAL(global_null));
	RETURN_MM();

}

/**
 * Executes the DELETE intermediate representation producing a Phalcon\Mvc\Model\Query\Status
 *
 * @param array intermediate
 * @param array bindParams
 * @param array bindTypes
 * @return Phalcon\Mvc\Model\Query\StatusInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeDelete) {

	zend_function *_7 = NULL;
	HashTable *_4;
	HashPosition _3;
	zval *intermediate, *bindParams, *bindTypes, *models, *modelName, *model, *records, *connection, *record = NULL, *_0, *_1, *_2, **_5, *_6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &intermediate, &bindParams, &bindTypes);



	ZEPHIR_OBS_VAR(models);
	zephir_array_fetch_string(&models, intermediate, SL("models"), PH_NOISY TSRMLS_CC);
	if (zephir_array_isset_long(models, 1)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Delete from several models at the same time is still not supported");
		return;
	}
	ZEPHIR_OBS_VAR(modelName);
	zephir_array_fetch_long(&modelName, models, 0, PH_NOISY TSRMLS_CC);
	ZEPHIR_OBS_VAR(model);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&model, _0, modelName, 0 TSRMLS_CC))) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_manager"), PH_NOISY_CC);
		ZEPHIR_INIT_BNVAR(model);
		zephir_call_method_p1(model, _1, "load", modelName);
	}
	ZEPHIR_INIT_VAR(records);
	zephir_call_method_p4(records, this_ptr, "_getrelatedrecords", model, intermediate, bindParams, bindTypes);
	if (!(zephir_fast_count_int(records TSRMLS_CC))) {
		object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
		zephir_call_method_p2_noret(return_value, "__construct", ZEPHIR_GLOBAL(global_true), ZEPHIR_GLOBAL(global_null));
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(connection);
	if ((zephir_method_exists_ex(model, SS("selectwriteconnection") TSRMLS_CC) == SUCCESS)) {
		zephir_call_method_p3(connection, model, "selectwriteconnection", intermediate, bindParams, bindTypes);
		if ((Z_TYPE_P(connection) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "'selectWriteConnection' didn't return a valid connection");
			return;
		}
	} else {
		zephir_call_method(connection, model, "getwriteconnection");
	}
	zephir_call_method_noret(connection, "begin");
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p1(_2, "iterator", records);
	zephir_is_iterable(_2, &_4, &_3, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
		; zend_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(record, _5);
		ZEPHIR_INIT_NVAR(_6);
		zephir_call_method(_6, record, "delete");
		if (!(zephir_is_true(_6))) {
			zephir_call_method_noret(connection, "rollback");
			object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
			zephir_call_method_p2_cache_noret(return_value, "__construct", &_7, ZEPHIR_GLOBAL(global_false), record);
			RETURN_MM();
		}
	}
	zephir_call_method_noret(connection, "commit");
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	zephir_call_method_p2_noret(return_value, "__construct", ZEPHIR_GLOBAL(global_true), ZEPHIR_GLOBAL(global_null));
	RETURN_MM();

}

/**
 * Query the records on which the UPDATE/DELETE operation well be done
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param array intermediate
 * @param array bindParams
 * @param array bindTypes
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getRelatedRecords) {

	zval *_0, *_1, *_2;
	zval *model, *intermediate, *bindParams, *bindTypes, *selectIr, *whereConditions, *limitConditions, *query, *_3, *_4 = NULL, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &model, &intermediate, &bindParams, &bindTypes);



	ZEPHIR_INIT_VAR(selectIr);
	array_init_size(selectIr, 5);
	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 2);
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 2);
	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 5);
	add_assoc_stringl_ex(_2, SS("type"), SL("object"), 1);
	ZEPHIR_INIT_VAR(_3);
	zephir_get_class(_3, model, 0 TSRMLS_CC);
	zephir_array_update_string(&_2, SL("model"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_3);
	zephir_call_method(_3, model, "getsource");
	zephir_array_update_string(&_2, SL("column"), &_3, PH_COPY | PH_SEPARATE);
	zephir_array_fast_append(_1, _2);
	zephir_array_fast_append(_0, _1);
	zephir_array_update_string(&selectIr, SL("columns"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(_4);
	zephir_array_fetch_string(&_4, intermediate, SL("models"), PH_NOISY TSRMLS_CC);
	zephir_array_update_string(&selectIr, SL("models"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_4);
	zephir_array_fetch_string(&_4, intermediate, SL("tables"), PH_NOISY TSRMLS_CC);
	zephir_array_update_string(&selectIr, SL("tables"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(whereConditions);
	if (zephir_array_isset_string_fetch(&whereConditions, intermediate, SS("where"), 0 TSRMLS_CC)) {
		zephir_array_update_string(&selectIr, SL("where"), &whereConditions, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(limitConditions);
	if (zephir_array_isset_string_fetch(&limitConditions, intermediate, SS("limit"), 0 TSRMLS_CC)) {
		zephir_array_update_string(&selectIr, SL("limit"), &limitConditions, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(query);
	object_init_ex(query, phalcon_mvc_model_query_ce);
	if (zephir_has_constructor(query TSRMLS_CC)) {
		zephir_call_method_noret(query, "__construct");
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	zephir_call_method_p1_noret(query, "setdi", _5);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_LONG(_3, 309);
	zephir_call_method_p1_noret(query, "settype", _3);
	zephir_call_method_p1_noret(query, "setintermediate", selectIr);
	zephir_call_method_p2(return_value, query, "execute", bindParams, bindTypes);
	RETURN_MM();

}

/**
 * Executes a parsed PHQL statement
 *
 * @param array bindParams
 * @param array bindTypes
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, execute) {

	zval *bindParams = NULL, *bindTypes = NULL, *uniqueRow, *cacheOptions, *key, *cacheService = NULL, *cache, *result = NULL, *preparedResult = NULL, *defaultBindParams, *mergedParams = NULL, *defaultBindTypes, *mergedTypes = NULL, *type, *lifetime = NULL, *intermediate, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &bindParams, &bindTypes);

	if (!bindParams) {
		bindParams = ZEPHIR_GLOBAL(global_null);
	}
	if (!bindTypes) {
		bindTypes = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(uniqueRow);
	zephir_read_property_this(&uniqueRow, this_ptr, SL("_uniqueRow"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(cacheOptions);
	zephir_read_property_this(&cacheOptions, this_ptr, SL("_cacheOptions"), PH_NOISY_CC);
	if ((Z_TYPE_P(cacheOptions) != IS_NULL)) {
		if ((Z_TYPE_P(cacheOptions) != IS_ARRAY)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid caching options");
			return;
		}
		ZEPHIR_OBS_VAR(key);
		if (zephir_array_isset_string_fetch(&key, cacheOptions, SS("key"), 0 TSRMLS_CC)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A cache key must be provided to identify the cached resultset in the cache backend");
			return;
		}
		ZEPHIR_OBS_VAR(lifetime);
		if (zephir_array_isset_string_fetch(&lifetime, cacheOptions, SS("lifetime"), 0 TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(lifetime);
			ZVAL_LONG(lifetime, 3600);
		}
		ZEPHIR_OBS_VAR(cacheService);
		if (!(zephir_array_isset_string_fetch(&cacheService, cacheOptions, SS("service"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(cacheService);
			ZVAL_STRING(cacheService, "modelsCache", 1);
		}
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(cache);
		zephir_call_method_p1(cache, _0, "getshared", cacheService);
		if ((Z_TYPE_P(cache) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Cache service must be an object");
			return;
		}
		ZEPHIR_INIT_VAR(result);
		zephir_call_method_p2(result, cache, "get", key, lifetime);
		if ((Z_TYPE_P(result) != IS_NULL)) {
			if ((Z_TYPE_P(result) != IS_OBJECT)) {
				ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Cache didn't return a valid resultset");
				return;
			}
			zephir_call_method_p1_noret(result, "setisfresh", ZEPHIR_GLOBAL(global_false));
			if (zephir_is_true(uniqueRow)) {
				ZEPHIR_INIT_VAR(preparedResult);
				zephir_call_method(preparedResult, result, "getfirst");
			} else {
				ZEPHIR_CPY_WRT(preparedResult, result);
			}
			RETURN_CCTOR(preparedResult);
		}
		zephir_update_property_this(this_ptr, SL("_cache"), cache TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(intermediate);
	zephir_call_method(intermediate, this_ptr, "parse");
	ZEPHIR_OBS_VAR(defaultBindParams);
	zephir_read_property_this(&defaultBindParams, this_ptr, SL("_bindParams"), PH_NOISY_CC);
	if ((Z_TYPE_P(defaultBindParams) == IS_ARRAY)) {
		if ((Z_TYPE_P(bindParams) == IS_ARRAY)) {
			ZEPHIR_INIT_VAR(mergedParams);
			zephir_fast_array_merge(mergedParams, &(defaultBindParams), &(bindParams) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedParams, defaultBindParams);
		}
	} else {
		ZEPHIR_CPY_WRT(mergedParams, bindParams);
	}
	ZEPHIR_OBS_VAR(defaultBindTypes);
	zephir_read_property_this(&defaultBindTypes, this_ptr, SL("_bindTypes"), PH_NOISY_CC);
	if ((Z_TYPE_P(defaultBindTypes) == IS_ARRAY)) {
		if ((Z_TYPE_P(bindTypes) == IS_ARRAY)) {
			ZEPHIR_INIT_VAR(mergedTypes);
			zephir_fast_array_merge(mergedTypes, &(defaultBindTypes), &(bindTypes) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedTypes, defaultBindTypes);
		}
	} else {
		ZEPHIR_CPY_WRT(mergedTypes, bindTypes);
	}
	ZEPHIR_OBS_VAR(type);
	zephir_read_property_this(&type, this_ptr, SL("_type"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_LONG(type, 309)) {
			ZEPHIR_INIT_NVAR(result);
			zephir_call_method_p3(result, this_ptr, "_executeselect", intermediate, mergedParams, mergedTypes);
			break;
		}
		if (ZEPHIR_IS_LONG(type, 306)) {
			ZEPHIR_INIT_NVAR(result);
			zephir_call_method_p3(result, this_ptr, "_executeinsert", intermediate, mergedParams, mergedTypes);
			break;
		}
		if (ZEPHIR_IS_LONG(type, 300)) {
			ZEPHIR_INIT_NVAR(result);
			zephir_call_method_p3(result, this_ptr, "_executeupdate", intermediate, mergedParams, mergedTypes);
			break;
		}
		if (ZEPHIR_IS_LONG(type, 303)) {
			ZEPHIR_INIT_NVAR(result);
			zephir_call_method_p3(result, this_ptr, "_executedelete", intermediate, mergedParams, mergedTypes);
			break;
		}
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SV(_2, "Unknown statement ", type);
		zephir_call_method_p1_noret(_1, "__construct", _2);
		zephir_throw_exception(_1 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	if ((Z_TYPE_P(cacheOptions) != IS_NULL)) {
		if (!ZEPHIR_IS_LONG(type, 309)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Only PHQL statements that return resultsets can be cached");
			return;
		}
		zephir_call_method_p3_noret(cache, "save", key, result, lifetime);
	}
	if (zephir_is_true(uniqueRow)) {
		ZEPHIR_INIT_NVAR(preparedResult);
		zephir_call_method(preparedResult, result, "getfirst");
	} else {
		ZEPHIR_CPY_WRT(preparedResult, result);
	}
	RETURN_CCTOR(preparedResult);

}

/**
 * Executes the query returning the first result
 *
 * @param array bindParams
 * @param array bindTypes
 * @return Ṕhalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getSingleResult) {

	zval *bindParams = NULL, *bindTypes = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &bindParams, &bindTypes);

	if (!bindParams) {
		bindParams = ZEPHIR_GLOBAL(global_null);
	}
	if (!bindTypes) {
		bindTypes = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_uniqueRow"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		zephir_call_method_p2(return_value, this_ptr, "execute", bindParams, bindTypes);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_call_method_p2(_1, this_ptr, "execute", bindParams, bindTypes);
	zephir_call_method(return_value, _1, "getfirst");
	RETURN_MM();

}

/**
 * Sets the type of PHQL statement to be executed
 *
 * @param int type
 * @return Phalcon\Mvc\Model\Query
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setType) {

	zval *type_param = NULL, *_0;
	int type;

	zephir_fetch_params(0, 1, 0, &type_param);

		type = zephir_get_intval(type_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, type);
	zephir_update_property_zval(this_ptr, SL("_type"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Gets the type of PHQL statement executed
 *
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getType) {


	RETURN_MEMBER(this_ptr, "_type");

}

/**
 * Set default bind parameters
 *
 * @param array bindParams
 * @return Phalcon\Mvc\Model\Query
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setBindParams) {

	zval *bindParams;

	zephir_fetch_params(0, 1, 0, &bindParams);



	zephir_update_property_this(this_ptr, SL("_bindParams"), bindParams TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns default bind params
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getBindParams) {


	RETURN_MEMBER(this_ptr, "_bindParams");

}

/**
 * Set default bind parameters
 *
 * @param array bindTypes
 * @return Phalcon\Mvc\Model\Query
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setBindTypes) {

	zval *bindTypes;

	zephir_fetch_params(0, 1, 0, &bindTypes);



	zephir_update_property_this(this_ptr, SL("_bindTypes"), bindTypes TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns default bind types
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getBindTypes) {


	RETURN_MEMBER(this_ptr, "_bindTypes");

}

/**
 * Allows to set the IR to be executed
 *
 * @param array intermediate
 * @return Phalcon\Mvc\Model\Query
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setIntermediate) {

	zval *intermediate;

	zephir_fetch_params(0, 1, 0, &intermediate);



	zephir_update_property_this(this_ptr, SL("_intermediate"), intermediate TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the intermediate representation of the PHQL statement
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getIntermediate) {


	RETURN_MEMBER(this_ptr, "_intermediate");

}

/**
 * Sets the cache parameters of the query
 *
 * @param array cacheOptions
 * @return Phalcon\Mvc\Model\Query
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, cache) {

	zval *cacheOptions;

	zephir_fetch_params(0, 1, 0, &cacheOptions);



	zephir_update_property_this(this_ptr, SL("_cacheOptions"), cacheOptions TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the current cache options
 *
 * @param array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getCacheOptions) {


	RETURN_MEMBER(this_ptr, "_cacheOptions");

}

