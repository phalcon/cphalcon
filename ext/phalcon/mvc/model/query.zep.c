
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "phalcon/mvc/model/orm.h"
#include "kernel/iterator.h"
#include "phalcon/mvc/model/query/scanner.h"
#include "phalcon/mvc/model/query/phql.h"


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
 * Phalcon\Mvc\Model\Query constructor
 *
 * @param string phql
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *phql = NULL, *dependencyInjector = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &phql, &dependencyInjector);

	if (!phql) {
		phql = ZEPHIR_GLOBAL(global_null);
	}
	if (!dependencyInjector) {
		dependencyInjector = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(phql) != IS_NULL) {
		zephir_update_property_this(this_ptr, SL("_phql"), phql TSRMLS_CC);
	}
	if (Z_TYPE_P(dependencyInjector) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdi", NULL, 0, dependencyInjector);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the dependency injection container
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setDI) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *dependencyInjector, *manager = NULL, *metaData = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dependencyInjector);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "modelsManager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&manager, dependencyInjector, "getshared", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (Z_TYPE_P(manager) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Injected service 'modelsManager' is invalid", "phalcon/mvc/model/query.zep", 138);
		return;
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "modelsMetadata", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&metaData, dependencyInjector, "getshared", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (Z_TYPE_P(metaData) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Injected service 'modelsMetaData' is invalid", "phalcon/mvc/model/query.zep", 143);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_manager"), manager TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_metaData"), metaData TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the dependency injection container
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Tells to the query if only the first row in the resultset must be returned
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
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getUniqueRow) {


	RETURN_MEMBER(this_ptr, "_uniqueRow");

}

/**
 * Replaces the model's name to its source name in a qualifed-name expression
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getQualified) {

	zephir_fcall_cache_entry *_7 = NULL;
	HashTable *_4;
	HashPosition _3;
	int number, ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, *columnName, *sqlColumnAliases, *metaData, *sqlAliases, *source = NULL, *sqlAliasesModelsInstances, *realColumnName = NULL, *columnDomain, *model = NULL, *models, *columnMap = NULL, *hasModel = NULL, *className, *_0 = NULL, *_1, *_2 = NULL, **_5, *_6 = NULL, *_8;
	zval *expr = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr_param);

	expr = expr_param;



	ZEPHIR_OBS_VAR(columnName);
	zephir_array_fetch_string(&columnName, expr, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 187 TSRMLS_CC);
	ZEPHIR_OBS_VAR(sqlColumnAliases);
	zephir_read_property_this(&sqlColumnAliases, this_ptr, SL("_sqlColumnAliases"), PH_NOISY_CC);
	if (zephir_array_isset(sqlColumnAliases, columnName)) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		add_assoc_stringl_ex(return_value, SS("type"), SL("qualified"), 1);
		zephir_array_update_string(&return_value, SL("name"), &columnName, PH_COPY | PH_SEPARATE);
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(metaData);
	zephir_read_property_this(&metaData, this_ptr, SL("_metaData"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(columnDomain);
	if (zephir_array_isset_string_fetch(&columnDomain, expr, SS("domain"), 0 TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(sqlAliases);
		zephir_read_property_this(&sqlAliases, this_ptr, SL("_sqlAliases"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(source);
		if (!(zephir_array_isset_fetch(&source, sqlAliases, columnDomain, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(_0);
			object_init_ex(_0, phalcon_mvc_model_exception_ce);
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_2);
			ZEPHIR_CONCAT_SVSV(_2, "Unknown model or alias '", columnDomain, "' (1), when preparing: ", _1);
			ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 2, _2);
			zephir_check_call_status();
			zephir_throw_exception_debug(_0, "phalcon/mvc/model/query.zep", 213 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_GLOBAL(orm).column_renaming) {
			ZEPHIR_OBS_VAR(sqlAliasesModelsInstances);
			zephir_read_property_this(&sqlAliasesModelsInstances, this_ptr, SL("_sqlAliasesModelsInstances"), PH_NOISY_CC);
			ZEPHIR_OBS_VAR(model);
			if (!(zephir_array_isset_fetch(&model, sqlAliasesModelsInstances, columnDomain, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_0);
				object_init_ex(_0, phalcon_mvc_model_exception_ce);
				_1 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_2);
				ZEPHIR_CONCAT_SVSV(_2, "There is no model related to model or alias '", columnDomain, "', when executing: ", _1);
				ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 2, _2);
				zephir_check_call_status();
				zephir_throw_exception_debug(_0, "phalcon/mvc/model/query.zep", 230 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&columnMap, metaData, "getreversecolumnmap", NULL, 0, model);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(columnMap);
			ZVAL_NULL(columnMap);
		}
		if (Z_TYPE_P(columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_VAR(realColumnName);
			if (!(zephir_array_isset_fetch(&realColumnName, columnMap, columnName, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_0);
				object_init_ex(_0, phalcon_mvc_model_exception_ce);
				_1 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_2);
				ZEPHIR_CONCAT_SVSVSV(_2, "Column '", columnName, "' doesn't belong to the model or alias '", columnDomain, "', when executing: ", _1);
				ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 2, _2);
				zephir_check_call_status();
				zephir_throw_exception_debug(_0, "phalcon/mvc/model/query.zep", 240 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(realColumnName, columnName);
		}
	} else {
		number = 0;
		ZEPHIR_INIT_VAR(hasModel);
		ZVAL_BOOL(hasModel, 0);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
		zephir_is_iterable(_1, &_4, &_3, 0, 0, "phalcon/mvc/model/query.zep", 270);
		for (
		  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_4, &_3)
		) {
			ZEPHIR_GET_HVALUE(model, _5);
			ZEPHIR_CALL_METHOD(&_6, metaData, "hasattribute", &_7, 0, model, columnName);
			zephir_check_call_status();
			if (zephir_is_true(_6)) {
				number++;
				if (number > 1) {
					ZEPHIR_INIT_NVAR(_0);
					object_init_ex(_0, phalcon_mvc_model_exception_ce);
					_8 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
					ZEPHIR_INIT_LNVAR(_2);
					ZEPHIR_CONCAT_SVSV(_2, "The column '", columnName, "' is ambiguous, when preparing: ", _8);
					ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 2, _2);
					zephir_check_call_status();
					zephir_throw_exception_debug(_0, "phalcon/mvc/model/query.zep", 261 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CPY_WRT(hasModel, model);
			}
		}
		if (ZEPHIR_IS_FALSE_IDENTICAL(hasModel)) {
			ZEPHIR_INIT_NVAR(_0);
			object_init_ex(_0, phalcon_mvc_model_exception_ce);
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
			ZEPHIR_INIT_LNVAR(_2);
			ZEPHIR_CONCAT_SVSV(_2, "Column '", columnName, "' doesn't belong to any of the selected models (1), when preparing: ", _1);
			ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 2, _2);
			zephir_check_call_status();
			zephir_throw_exception_debug(_0, "phalcon/mvc/model/query.zep", 271 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_VAR(models);
		zephir_read_property_this(&models, this_ptr, SL("_models"), PH_NOISY_CC);
		if (Z_TYPE_P(models) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The models list was not loaded correctly", "phalcon/mvc/model/query.zep", 279);
			return;
		}
		ZEPHIR_INIT_VAR(className);
		zephir_get_class(className, hasModel, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(source);
		if (!(zephir_array_isset_fetch(&source, models, className, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(_0);
			object_init_ex(_0, phalcon_mvc_model_exception_ce);
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
			ZEPHIR_INIT_LNVAR(_2);
			ZEPHIR_CONCAT_SVSV(_2, "Can't obtain model's source from models list: '", className, "', when preparing: ", _1);
			ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 2, _2);
			zephir_check_call_status();
			zephir_throw_exception_debug(_0, "phalcon/mvc/model/query.zep", 287 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_GLOBAL(orm).column_renaming) {
			ZEPHIR_CALL_METHOD(&columnMap, metaData, "getreversecolumnmap", NULL, 0, hasModel);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(columnMap);
			ZVAL_NULL(columnMap);
		}
		if (Z_TYPE_P(columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(realColumnName);
			if (!(zephir_array_isset_fetch(&realColumnName, columnMap, columnName, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_0);
				object_init_ex(_0, phalcon_mvc_model_exception_ce);
				_1 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_2);
				ZEPHIR_CONCAT_SVSV(_2, "Column '", columnName, "' doesn't belong to any of the selected models (3), when preparing: ", _1);
				ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 2, _2);
				zephir_check_call_status();
				zephir_throw_exception_debug(_0, "phalcon/mvc/model/query.zep", 304 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(realColumnName, columnName);
		}
	}
	zephir_create_array(return_value, 4, 0 TSRMLS_CC);
	add_assoc_stringl_ex(return_value, SS("type"), SL("qualified"), 1);
	zephir_array_update_string(&return_value, SL("domain"), &source, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("name"), &realColumnName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("balias"), &columnName, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * Resolves a expression in a single call argument
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getCallArgument) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *argument_param = NULL, *_0;
	zval *argument = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &argument_param);

	argument = argument_param;



	zephir_array_fetch_string(&_0, argument, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 328 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(_0, 352)) {
		zephir_create_array(return_value, 1, 0 TSRMLS_CC);
		add_assoc_stringl_ex(return_value, SS("type"), SL("all"), 1);
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getexpression", NULL, 309, argument);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Resolves a expression in a single call argument
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getCaseExpression) {

	zephir_fcall_cache_entry *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *expr_param = NULL, *whenClauses, *whenExpr = NULL, *_0, **_3, *_5 = NULL, *_6, *_8;
	zval *expr = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr_param);

	expr = expr_param;



	ZEPHIR_INIT_VAR(whenClauses);
	array_init(whenClauses);
	zephir_array_fetch_string(&_0, expr, SL("right"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 342 TSRMLS_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/mvc/model/query.zep", 357);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(whenExpr, _3);
		if (zephir_array_isset_string(whenExpr, SS("right"))) {
			ZEPHIR_INIT_NVAR(_4);
			zephir_create_array(_4, 3, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_4, SS("type"), SL("when"), 1);
			zephir_array_fetch_string(&_6, whenExpr, SL("left"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 346 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_5, this_ptr, "_getexpression", &_7, 309, _6);
			zephir_check_call_status();
			zephir_array_update_string(&_4, SL("expr"), &_5, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_8, whenExpr, SL("right"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 347 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_5, this_ptr, "_getexpression", &_7, 309, _8);
			zephir_check_call_status();
			zephir_array_update_string(&_4, SL("then"), &_5, PH_COPY | PH_SEPARATE);
			zephir_array_append(&whenClauses, _4, PH_SEPARATE, "phalcon/mvc/model/query.zep", 348);
		} else {
			ZEPHIR_INIT_NVAR(_4);
			zephir_create_array(_4, 2, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_4, SS("type"), SL("else"), 1);
			zephir_array_fetch_string(&_6, whenExpr, SL("left"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 352 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_5, this_ptr, "_getexpression", &_7, 309, _6);
			zephir_check_call_status();
			zephir_array_update_string(&_4, SL("expr"), &_5, PH_COPY | PH_SEPARATE);
			zephir_array_append(&whenClauses, _4, PH_SEPARATE, "phalcon/mvc/model/query.zep", 353);
		}
	}
	zephir_create_array(return_value, 3, 0 TSRMLS_CC);
	add_assoc_stringl_ex(return_value, SS("type"), SL("case"), 1);
	zephir_array_fetch_string(&_6, expr, SL("left"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 359 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "_getexpression", &_7, 309, _6);
	zephir_check_call_status();
	zephir_array_update_string(&return_value, SL("expr"), &_5, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("when-clauses"), &whenClauses, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * Resolves a expression in a single call argument
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getFunctionCall) {

	zephir_fcall_cache_entry *_4 = NULL;
	HashTable *_1;
	HashPosition _0;
	int distinct, ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, *arguments, *argument = NULL, *functionArgs, **_2, *_3 = NULL, *_5 = NULL, *_6;
	zval *expr = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr_param);

	expr = expr_param;



	ZEPHIR_OBS_VAR(arguments);
	if (zephir_array_isset_string_fetch(&arguments, expr, SS("arguments"), 0 TSRMLS_CC)) {
		if (zephir_array_isset_string(expr, SS("distinct"))) {
			distinct = 1;
		} else {
			distinct = 0;
		}
		ZEPHIR_INIT_VAR(functionArgs);
		if (zephir_array_isset_long(arguments, 0)) {
			array_init(functionArgs);
			zephir_is_iterable(arguments, &_1, &_0, 0, 0, "phalcon/mvc/model/query.zep", 387);
			for (
			  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			  ; zephir_hash_move_forward_ex(_1, &_0)
			) {
				ZEPHIR_GET_HVALUE(argument, _2);
				ZEPHIR_CALL_METHOD(&_3, this_ptr, "_getcallargument", &_4, 310, argument);
				zephir_check_call_status();
				zephir_array_append(&functionArgs, _3, PH_SEPARATE, "phalcon/mvc/model/query.zep", 385);
			}
		} else {
			zephir_create_array(functionArgs, 1, 0 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_3, this_ptr, "_getcallargument", &_4, 310, arguments);
			zephir_check_call_status();
			zephir_array_fast_append(functionArgs, _3);
		}
		if (distinct) {
			zephir_create_array(return_value, 4, 0 TSRMLS_CC);
			add_assoc_stringl_ex(return_value, SS("type"), SL("functionCall"), 1);
			ZEPHIR_OBS_VAR(_5);
			zephir_array_fetch_string(&_5, expr, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 397 TSRMLS_CC);
			zephir_array_update_string(&return_value, SL("name"), &_5, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&return_value, SL("arguments"), &functionArgs, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_VAR(_6);
			ZVAL_LONG(_6, distinct);
			zephir_array_update_string(&return_value, SL("distinct"), &_6, PH_COPY | PH_SEPARATE);
			RETURN_MM();
		} else {
			zephir_create_array(return_value, 3, 0 TSRMLS_CC);
			add_assoc_stringl_ex(return_value, SS("type"), SL("functionCall"), 1);
			ZEPHIR_OBS_NVAR(_5);
			zephir_array_fetch_string(&_5, expr, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 404 TSRMLS_CC);
			zephir_array_update_string(&return_value, SL("name"), &_5, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&return_value, SL("arguments"), &functionArgs, PH_COPY | PH_SEPARATE);
			RETURN_MM();
		}
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(return_value, SS("type"), SL("functionCall"), 1);
	ZEPHIR_OBS_NVAR(_5);
	zephir_array_fetch_string(&_5, expr, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 413 TSRMLS_CC);
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

	HashTable *_10;
	HashPosition _9;
	zephir_fcall_cache_entry *_0 = NULL, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool quoting, tempNotQuoting;
	zval *expr, *quoting_param = NULL, *exprType, *exprLeft, *exprRight, *left = NULL, *right = NULL, *listItems, *exprListItem = NULL, *exprReturn = NULL, *value, *escapedValue = NULL, *exprValue = NULL, *_2 = NULL, *_3 = NULL, *_4, _5 = zval_used_for_init, _6 = zval_used_for_init, *_7 = NULL, *_8 = NULL, **_11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expr, &quoting_param);

	if (!quoting_param) {
		quoting = 1;
	} else {
		quoting = zephir_get_boolval(quoting_param);
	}
	ZEPHIR_INIT_VAR(left);
	ZVAL_NULL(left);
	ZEPHIR_INIT_VAR(right);
	ZVAL_NULL(right);


	ZEPHIR_OBS_VAR(exprType);
	if (zephir_array_isset_string_fetch(&exprType, expr, SS("type"), 0 TSRMLS_CC)) {
		tempNotQuoting = 1;
		if (!ZEPHIR_IS_LONG(exprType, 409)) {
			ZEPHIR_OBS_VAR(exprLeft);
			if (zephir_array_isset_string_fetch(&exprLeft, expr, SS("left"), 0 TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(&left, this_ptr, "_getexpression", &_0, 309, exprLeft, (tempNotQuoting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
				zephir_check_call_status();
			}
			ZEPHIR_OBS_VAR(exprRight);
			if (zephir_array_isset_string_fetch(&exprRight, expr, SS("right"), 0 TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(&right, this_ptr, "_getexpression", &_0, 309, exprRight, (tempNotQuoting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
				zephir_check_call_status();
			}
		}
		do {
			if (ZEPHIR_IS_LONG(exprType, '<')) {
				ZEPHIR_INIT_VAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("<"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '=')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("="), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '>')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL(">"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 270)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("<>"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 271)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("<="), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 272)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL(">="), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 266)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("AND"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 267)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("OR"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 355)) {
				ZEPHIR_CALL_METHOD(&exprReturn, this_ptr, "_getqualified", &_1, 311, expr);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '+')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("+"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '-')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("-"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '*')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("*"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '/')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("/"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '%')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("%"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '&')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("&"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '|')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("|"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 356) || ZEPHIR_IS_LONG(exprType, 407)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("parentheses"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 367)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("unary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("-"), 1);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 258) || ZEPHIR_IS_LONG(exprType, 259)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("literal"), 1);
				ZEPHIR_OBS_VAR(_2);
				zephir_array_fetch_string(&_2, expr, SL("value"), PH_NOISY, "phalcon/mvc/model/query.zep", 529 TSRMLS_CC);
				zephir_array_update_string(&exprReturn, SL("value"), &_2, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 333)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("literal"), 1);
				add_assoc_stringl_ex(exprReturn, SS("value"), SL("TRUE"), 1);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 334)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("literal"), 1);
				add_assoc_stringl_ex(exprReturn, SS("value"), SL("FALSE"), 1);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 260)) {
				ZEPHIR_OBS_VAR(value);
				zephir_array_fetch_string(&value, expr, SL("value"), PH_NOISY, "phalcon/mvc/model/query.zep", 541 TSRMLS_CC);
				if (quoting == 1) {
					if (zephir_memnstr_str(value, SL("'"), "phalcon/mvc/model/query.zep", 546)) {
						ZEPHIR_INIT_VAR(escapedValue);
						phalcon_orm_singlequotes(escapedValue, value TSRMLS_CC);
					} else {
						ZEPHIR_CPY_WRT(escapedValue, value);
					}
					ZEPHIR_INIT_VAR(exprValue);
					ZEPHIR_CONCAT_SVS(exprValue, "'", escapedValue, "'");
				} else {
					ZEPHIR_CPY_WRT(exprValue, value);
				}
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("literal"), 1);
				zephir_array_update_string(&exprReturn, SL("value"), &exprValue, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 273)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("placeholder"), 1);
				ZEPHIR_INIT_VAR(_3);
				zephir_array_fetch_string(&_4, expr, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 559 TSRMLS_CC);
				ZEPHIR_SINIT_VAR(_5);
				ZVAL_STRING(&_5, "?", 0);
				ZEPHIR_SINIT_VAR(_6);
				ZVAL_STRING(&_6, ":", 0);
				zephir_fast_str_replace(&_3, &_5, &_6, _4 TSRMLS_CC);
				zephir_array_update_string(&exprReturn, SL("value"), &_3, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 274)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("placeholder"), 1);
				zephir_array_fetch_string(&_4, expr, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 563 TSRMLS_CC);
				ZEPHIR_INIT_VAR(_7);
				ZEPHIR_CONCAT_SV(_7, ":", _4);
				zephir_array_update_string(&exprReturn, SL("value"), &_7, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 277)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("placeholder"), 1);
				ZEPHIR_INIT_NVAR(_3);
				zephir_array_fetch_string(&_4, expr, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 567 TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_STRING(&_5, "?", 0);
				ZEPHIR_SINIT_NVAR(_6);
				ZVAL_STRING(&_6, ":", 0);
				zephir_fast_str_replace(&_3, &_5, &_6, _4 TSRMLS_CC);
				zephir_array_update_string(&exprReturn, SL("value"), &_3, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 278)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("placeholder"), 1);
				zephir_array_fetch_string(&_4, expr, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 571 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_7);
				ZEPHIR_CONCAT_SV(_7, ":", _4);
				zephir_array_update_string(&exprReturn, SL("value"), &_7, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 322)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("literal"), 1);
				add_assoc_stringl_ex(exprReturn, SS("value"), SL("NULL"), 1);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 268)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("LIKE"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 351)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("NOT LIKE"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 275)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("ILIKE"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 357)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("NOT ILIKE"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, '!')) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("unary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("NOT "), 1);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 365)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("unary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL(" IS NULL"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 366)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("unary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL(" IS NOT NULL"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 315)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("IN"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 323)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("NOT IN"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 408)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("unary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("EXISTS"), 1);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 330)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("unary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("DISTINCT "), 1);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 331)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("BETWEEN"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 276)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 4, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("binary-op"), 1);
				add_assoc_stringl_ex(exprReturn, SS("op"), SL("AGAINST"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 332)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("cast"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 335)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 3, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("convert"), 1);
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 358)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("literal"), 1);
				ZEPHIR_OBS_NVAR(_2);
				zephir_array_fetch_string(&_2, expr, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 639 TSRMLS_CC);
				zephir_array_update_string(&exprReturn, SL("value"), &_2, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 350)) {
				ZEPHIR_CALL_METHOD(&exprReturn, this_ptr, "_getfunctioncall", NULL, 312, expr);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 409)) {
				ZEPHIR_CALL_METHOD(&exprReturn, this_ptr, "_getcaseexpression", NULL, 313, expr);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(exprType, 309)) {
				ZEPHIR_INIT_NVAR(exprReturn);
				zephir_create_array(exprReturn, 2, 0 TSRMLS_CC);
				add_assoc_stringl_ex(exprReturn, SS("type"), SL("select"), 1);
				ZEPHIR_INIT_NVAR(_3);
				ZVAL_BOOL(_3, 1);
				ZEPHIR_CALL_METHOD(&_8, this_ptr, "_prepareselect", NULL, 314, expr, _3);
				zephir_check_call_status();
				zephir_array_update_string(&exprReturn, SL("value"), &_8, PH_COPY | PH_SEPARATE);
				break;
			}
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_LNVAR(_7);
			ZEPHIR_CONCAT_SV(_7, "Unknown expression type ", exprType);
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 2, _7);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3, "phalcon/mvc/model/query.zep", 655 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		} while(0);

		RETURN_CCTOR(exprReturn);
	}
	if (zephir_array_isset_string(expr, SS("domain"))) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getqualified", &_1, 311, expr);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_array_isset_long(expr, 0)) {
		ZEPHIR_INIT_VAR(listItems);
		array_init(listItems);
		zephir_is_iterable(expr, &_10, &_9, 0, 0, "phalcon/mvc/model/query.zep", 676);
		for (
		  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
		  ; zephir_hash_move_forward_ex(_10, &_9)
		) {
			ZEPHIR_GET_HVALUE(exprListItem, _11);
			ZEPHIR_CALL_METHOD(&_8, this_ptr, "_getexpression", &_0, 309, exprListItem);
			zephir_check_call_status();
			zephir_array_append(&listItems, _8, PH_SEPARATE, "phalcon/mvc/model/query.zep", 674);
		}
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		add_assoc_stringl_ex(return_value, SS("type"), SL("list"), 1);
		zephir_array_fast_append(return_value, listItems);
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Unknown expression", "phalcon/mvc/model/query.zep", 679);
	return;

}

/**
 * Resolves a column from its intermediate representation into an array used to determine
 * if the resultset produced is simple or complex
 *
 * @param array column
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getSelectColumn) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *column_param = NULL, *sqlColumns, *columnType, *sqlAliases, *modelName = NULL, *source = NULL, *columnDomain, *sqlColumnAlias = NULL, *preparedAlias = NULL, *sqlExprColumn = NULL, *sqlAliasesModels, *sqlColumn, *columnData, *balias, *_0, **_3, *_5 = NULL, *_6 = NULL;
	zval *column = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column_param);

	column = column_param;



	ZEPHIR_OBS_VAR(columnType);
	if (!(zephir_array_isset_string_fetch(&columnType, column, SS("type"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST", "phalcon/mvc/model/query.zep", 696);
		return;
	}
	ZEPHIR_INIT_VAR(sqlColumns);
	array_init(sqlColumns);
	if (ZEPHIR_IS_LONG(columnType, 352)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_models"), PH_NOISY_CC);
		zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/mvc/model/query.zep", 712);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HMKEY(modelName, _2, _1);
			ZEPHIR_GET_HVALUE(source, _3);
			ZEPHIR_INIT_NVAR(_4);
			zephir_create_array(_4, 3, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_4, SS("type"), SL("object"), 1);
			zephir_array_update_string(&_4, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_4, SL("column"), &source, PH_COPY | PH_SEPARATE);
			zephir_array_append(&sqlColumns, _4, PH_SEPARATE, "phalcon/mvc/model/query.zep", 710);
		}
		RETURN_CCTOR(sqlColumns);
	}
	if (!(zephir_array_isset_string(column, SS("column")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST", "phalcon/mvc/model/query.zep", 716);
		return;
	}
	if (ZEPHIR_IS_LONG(columnType, 353)) {
		ZEPHIR_OBS_VAR(sqlAliases);
		zephir_read_property_this(&sqlAliases, this_ptr, SL("_sqlAliases"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(columnDomain);
		zephir_array_fetch_string(&columnDomain, column, SL("column"), PH_NOISY, "phalcon/mvc/model/query.zep", 729 TSRMLS_CC);
		ZEPHIR_OBS_VAR(source);
		if (!(zephir_array_isset_fetch(&source, sqlAliases, columnDomain, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(_5);
			object_init_ex(_5, phalcon_mvc_model_exception_ce);
			_0 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_6);
			ZEPHIR_CONCAT_SVSV(_6, "Unknown model or alias '", columnDomain, "' (2), when preparing: ", _0);
			ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, 2, _6);
			zephir_check_call_status();
			zephir_throw_exception_debug(_5, "phalcon/mvc/model/query.zep", 732 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(sqlColumnAlias, source);
		ZEPHIR_OBS_VAR(sqlAliasesModels);
		zephir_read_property_this(&sqlAliasesModels, this_ptr, SL("_sqlAliasesModels"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(modelName);
		zephir_array_fetch(&modelName, sqlAliasesModels, columnDomain, PH_NOISY, "phalcon/mvc/model/query.zep", 744 TSRMLS_CC);
		if (ZEPHIR_IS_EQUAL(columnDomain, modelName)) {
			ZEPHIR_CALL_FUNCTION(&preparedAlias, "lcfirst", NULL, 144, modelName);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(preparedAlias, columnDomain);
		}
		ZEPHIR_INIT_NVAR(_4);
		zephir_create_array(_4, 4, 0 TSRMLS_CC);
		add_assoc_stringl_ex(_4, SS("type"), SL("object"), 1);
		zephir_array_update_string(&_4, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_4, SL("column"), &sqlColumnAlias, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_4, SL("balias"), &preparedAlias, PH_COPY | PH_SEPARATE);
		zephir_array_append(&sqlColumns, _4, PH_SEPARATE, "phalcon/mvc/model/query.zep", 763);
		RETURN_CCTOR(sqlColumns);
	}
	if (ZEPHIR_IS_LONG(columnType, 354)) {
		ZEPHIR_INIT_VAR(sqlColumn);
		zephir_create_array(sqlColumn, 1, 0 TSRMLS_CC);
		add_assoc_stringl_ex(sqlColumn, SS("type"), SL("scalar"), 1);
		ZEPHIR_OBS_VAR(columnData);
		zephir_array_fetch_string(&columnData, column, SL("column"), PH_NOISY, "phalcon/mvc/model/query.zep", 777 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&sqlExprColumn, this_ptr, "_getexpression", NULL, 309, columnData);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(balias);
		if (zephir_array_isset_string_fetch(&balias, sqlExprColumn, SS("balias"), 0 TSRMLS_CC)) {
			zephir_array_update_string(&sqlColumn, SL("balias"), &balias, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&sqlColumn, SL("sqlAlias"), &balias, PH_COPY | PH_SEPARATE);
		}
		zephir_array_update_string(&sqlColumn, SL("column"), &sqlExprColumn, PH_COPY | PH_SEPARATE);
		zephir_array_append(&sqlColumns, sqlColumn, PH_SEPARATE, "phalcon/mvc/model/query.zep", 789);
		RETURN_CCTOR(sqlColumns);
	}
	ZEPHIR_INIT_NVAR(_5);
	object_init_ex(_5, phalcon_mvc_model_exception_ce);
	ZEPHIR_INIT_LNVAR(_6);
	ZEPHIR_CONCAT_SV(_6, "Unknown type of column ", columnType);
	ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, 2, _6);
	zephir_check_call_status();
	zephir_throw_exception_debug(_5, "phalcon/mvc/model/query.zep", 794 TSRMLS_CC);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *manager, *qualifiedName, *modelName, *model = NULL, *source = NULL, *schema = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &manager, &qualifiedName);



	ZEPHIR_OBS_VAR(modelName);
	if (!(zephir_array_isset_string_fetch(&modelName, qualifiedName, SS("name"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST", "phalcon/mvc/model/query.zep", 809);
		return;
	}
	ZEPHIR_CALL_METHOD(&model, manager, "load", NULL, 0, modelName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, model, "getsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&schema, model, "getschema", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(schema)) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(return_value, schema);
		zephir_array_fast_append(return_value, source);
		RETURN_MM();
	}
	RETURN_CCTOR(source);

}

/**
 * Resolves a JOIN clause checking if the associated models exist
 *
 * @param Phalcon\Mvc\Model\ManagerInterface manager
 * @param array join
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoin) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *manager, *join, *qualified, *modelName, *realModelName = NULL, *nsAlias, *source = NULL, *model = NULL, *schema = NULL, *_0, *_1 = NULL, *_2, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &manager, &join);



	ZEPHIR_OBS_VAR(qualified);
	if (zephir_array_isset_string_fetch(&qualified, join, SS("qualified"), 0 TSRMLS_CC)) {
		zephir_array_fetch_string(&_0, qualified, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 836 TSRMLS_CC);
		if (ZEPHIR_IS_LONG(_0, 355)) {
			ZEPHIR_OBS_VAR(modelName);
			zephir_array_fetch_string(&modelName, qualified, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 838 TSRMLS_CC);
			if (zephir_memnstr_str(modelName, SL(":"), "phalcon/mvc/model/query.zep", 840)) {
				ZEPHIR_INIT_VAR(nsAlias);
				zephir_fast_explode_str(nsAlias, SL(":"), modelName, LONG_MAX TSRMLS_CC);
				zephir_array_fetch_long(&_2, nsAlias, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 842 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_1, manager, "getnamespacealias", NULL, 0, _2);
				zephir_check_call_status();
				zephir_array_fetch_long(&_3, nsAlias, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 842 TSRMLS_CC);
				ZEPHIR_INIT_VAR(realModelName);
				ZEPHIR_CONCAT_VSV(realModelName, _1, "\\", _3);
			} else {
				ZEPHIR_CPY_WRT(realModelName, modelName);
			}
			ZEPHIR_INIT_VAR(_4);
			ZVAL_BOOL(_4, 1);
			ZEPHIR_CALL_METHOD(&model, manager, "load", NULL, 0, realModelName, _4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&source, model, "getsource", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&schema, model, "getschema", NULL, 0);
			zephir_check_call_status();
			zephir_create_array(return_value, 4, 0 TSRMLS_CC);
			zephir_array_update_string(&return_value, SL("schema"), &schema, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&return_value, SL("source"), &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&return_value, SL("modelName"), &realModelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&return_value, SL("model"), &model, PH_COPY | PH_SEPARATE);
			RETURN_MM();
		}
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST", "phalcon/mvc/model/query.zep", 860);
	return;

}

/**
 * Resolves a JOIN type
 *
 * @param array join
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoinType) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *join, *type, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &join);



	ZEPHIR_OBS_VAR(type);
	if (!(zephir_array_isset_string_fetch(&type, join, SS("type"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST", "phalcon/mvc/model/query.zep", 874);
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
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 2, _2);
	zephir_check_call_status();
	zephir_throw_exception_debug(_0, "phalcon/mvc/model/query.zep", 895 TSRMLS_CC);
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

	HashTable *_6;
	HashPosition _5;
	zephir_fcall_cache_entry *_3 = NULL, *_11 = NULL;
	zval *_0 = NULL, *_2 = NULL, *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *joinType_param = NULL, *joinSource, *modelAlias, *joinAlias, *relation, *fields = NULL, *referencedFields = NULL, *sqlJoinConditions = NULL, *sqlJoinPartialConditions, *position = NULL, *field = NULL, *referencedField = NULL, *_1 = NULL, **_7, *_8 = NULL, *_9, *_10 = NULL;
	zval *joinType = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &joinType_param, &joinSource, &modelAlias, &joinAlias, &relation);

	if (unlikely(Z_TYPE_P(joinType_param) != IS_STRING && Z_TYPE_P(joinType_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'joinType' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(joinType_param) == IS_STRING)) {
		zephir_get_strval(joinType, joinType_param);
	} else {
		ZEPHIR_INIT_VAR(joinType);
		ZVAL_EMPTY_STRING(joinType);
	}
	ZEPHIR_INIT_VAR(sqlJoinConditions);
	ZVAL_NULL(sqlJoinConditions);


	ZEPHIR_CALL_METHOD(&fields, relation, "getfields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&referencedFields, relation, "getreferencedfields", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(fields) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(sqlJoinConditions);
		zephir_create_array(sqlJoinConditions, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_0);
		zephir_create_array(_0, 4, 0 TSRMLS_CC);
		add_assoc_stringl_ex(_0, SS("type"), SL("binary-op"), 1);
		add_assoc_stringl_ex(_0, SS("op"), SL("="), 1);
		ZEPHIR_INIT_VAR(_2);
		zephir_create_array(_2, 3, 0 TSRMLS_CC);
		add_assoc_long_ex(_2, SS("type"), 355);
		zephir_array_update_string(&_2, SL("domain"), &modelAlias, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_2, SL("name"), &fields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "_getqualified", &_3, 311, _2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL("left"), &_1, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_4);
		zephir_create_array(_4, 3, 0 TSRMLS_CC);
		add_assoc_stringl_ex(_4, SS("type"), SL("qualified"), 1);
		zephir_array_update_string(&_4, SL("domain"), &joinAlias, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_4, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "_getqualified", &_3, 311, _4);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL("right"), &_1, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(sqlJoinConditions, _0);
	} else {
		ZEPHIR_INIT_VAR(sqlJoinPartialConditions);
		array_init(sqlJoinPartialConditions);
		zephir_is_iterable(fields, &_6, &_5, 0, 0, "phalcon/mvc/model/query.zep", 983);
		for (
		  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6, &_5)
		) {
			ZEPHIR_GET_HMKEY(position, _6, _5);
			ZEPHIR_GET_HVALUE(field, _7);
			ZEPHIR_OBS_NVAR(referencedField);
			if (!(zephir_array_isset_fetch(&referencedField, referencedFields, position, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_8);
				object_init_ex(_8, phalcon_mvc_model_exception_ce);
				_9 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_10);
				ZEPHIR_CONCAT_SVSVSV(_10, "The number of fields must be equal to the number of referenced fields in join ", modelAlias, "-", joinAlias, ", when preparing: ", _9);
				ZEPHIR_CALL_METHOD(NULL, _8, "__construct", &_11, 2, _10);
				zephir_check_call_status();
				zephir_throw_exception_debug(_8, "phalcon/mvc/model/query.zep", 959 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(_0);
			zephir_create_array(_0, 4, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_0, SS("type"), SL("binary-op"), 1);
			add_assoc_stringl_ex(_0, SS("op"), SL("="), 1);
			ZEPHIR_INIT_NVAR(_2);
			zephir_create_array(_2, 3, 0 TSRMLS_CC);
			add_assoc_long_ex(_2, SS("type"), 355);
			zephir_array_update_string(&_2, SL("domain"), &modelAlias, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_2, SL("name"), &field, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_1, this_ptr, "_getqualified", &_3, 311, _2);
			zephir_check_call_status();
			zephir_array_update_string(&_0, SL("left"), &_1, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_4);
			zephir_create_array(_4, 3, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_4, SS("type"), SL("qualified"), 1);
			zephir_array_update_string(&_4, SL("domain"), &joinAlias, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_4, SL("name"), &referencedField, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_1, this_ptr, "_getqualified", &_3, 311, _4);
			zephir_check_call_status();
			zephir_array_update_string(&_0, SL("right"), &_1, PH_COPY | PH_SEPARATE);
			zephir_array_append(&sqlJoinPartialConditions, _0, PH_SEPARATE, "phalcon/mvc/model/query.zep", 980);
		}
	}
	zephir_create_array(return_value, 3, 0 TSRMLS_CC);
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

	zval *_8 = NULL, *_10 = NULL, *_11 = NULL, *_12, *_13, *_14, *_15;
	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL;
	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *joinType, *joinSource, *modelAlias, *joinAlias, *relation, *sqlJoins = NULL, *fields = NULL, *referencedFields = NULL, *intermediateModelName = NULL, *intermediateModel = NULL, *intermediateSource = NULL, *intermediateSchema = NULL, *intermediateFields = NULL, *intermediateReferencedFields = NULL, *referencedModelName = NULL, *manager, *field = NULL, *position = NULL, *intermediateField = NULL, *sqlEqualsJoinCondition = NULL, **_2, *_3 = NULL, *_4, *_5 = NULL, *_7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &joinType, &joinSource, &modelAlias, &joinAlias, &relation);



	ZEPHIR_INIT_VAR(sqlJoins);
	array_init(sqlJoins);
	ZEPHIR_CALL_METHOD(&fields, relation, "getfields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&referencedFields, relation, "getreferencedfields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&intermediateModelName, relation, "getintermediatemodel", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&intermediateModel, manager, "load", NULL, 0, intermediateModelName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&intermediateSource, intermediateModel, "getsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&intermediateSchema, intermediateModel, "getschema", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_sqlAliases"), intermediateModelName, intermediateSource TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_sqlAliasesModelsInstances"), intermediateModelName, intermediateModel TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&intermediateFields, relation, "getintermediatefields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&intermediateReferencedFields, relation, "getintermediatereferencedfields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&referencedModelName, relation, "getreferencedmodel", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(fields) == IS_ARRAY) {
		zephir_is_iterable(fields, &_1, &_0, 0, 0, "phalcon/mvc/model/query.zep", 1107);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HMKEY(field, _1, _0);
			ZEPHIR_GET_HVALUE(position, _2);
			if (!(zephir_array_isset(referencedFields, position))) {
				ZEPHIR_INIT_NVAR(_3);
				object_init_ex(_3, phalcon_mvc_model_exception_ce);
				_4 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_5);
				ZEPHIR_CONCAT_SVSVSV(_5, "The number of fields must be equal to the number of referenced fields in join ", modelAlias, "-", joinAlias, ", when preparing: ", _4);
				ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_6, 2, _5);
				zephir_check_call_status();
				zephir_throw_exception_debug(_3, "phalcon/mvc/model/query.zep", 1078 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(intermediateField);
			zephir_array_fetch(&intermediateField, intermediateFields, position, PH_NOISY, "phalcon/mvc/model/query.zep", 1084 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(sqlEqualsJoinCondition);
			zephir_create_array(sqlEqualsJoinCondition, 4, 0 TSRMLS_CC);
			add_assoc_stringl_ex(sqlEqualsJoinCondition, SS("type"), SL("binary-op"), 1);
			add_assoc_stringl_ex(sqlEqualsJoinCondition, SS("op"), SL("="), 1);
			ZEPHIR_INIT_NVAR(_8);
			zephir_create_array(_8, 3, 0 TSRMLS_CC);
			add_assoc_long_ex(_8, SS("type"), 355);
			zephir_array_update_string(&_8, SL("domain"), &modelAlias, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_8, SL("name"), &field, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_7, this_ptr, "_getqualified", &_9, 311, _8);
			zephir_check_call_status();
			zephir_array_update_string(&sqlEqualsJoinCondition, SL("left"), &_7, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_10);
			zephir_create_array(_10, 3, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_10, SS("type"), SL("qualified"), 1);
			zephir_array_update_string(&_10, SL("domain"), &joinAlias, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_10, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_7, this_ptr, "_getqualified", &_9, 311, _10);
			zephir_check_call_status();
			zephir_array_update_string(&sqlEqualsJoinCondition, SL("right"), &_7, PH_COPY | PH_SEPARATE);
		}
	} else {
		ZEPHIR_INIT_NVAR(sqlJoins);
		zephir_create_array(sqlJoins, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_8);
		zephir_create_array(_8, 3, 0 TSRMLS_CC);
		zephir_array_update_string(&_8, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_8, SL("source"), &intermediateSource, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_10);
		zephir_create_array(_10, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_11);
		zephir_create_array(_11, 4, 0 TSRMLS_CC);
		add_assoc_stringl_ex(_11, SS("type"), SL("binary-op"), 1);
		add_assoc_stringl_ex(_11, SS("op"), SL("="), 1);
		ZEPHIR_INIT_VAR(_12);
		zephir_create_array(_12, 3, 0 TSRMLS_CC);
		add_assoc_long_ex(_12, SS("type"), 355);
		zephir_array_update_string(&_12, SL("domain"), &modelAlias, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_12, SL("name"), &fields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_7, this_ptr, "_getqualified", &_9, 311, _12);
		zephir_check_call_status();
		zephir_array_update_string(&_11, SL("left"), &_7, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_13);
		zephir_create_array(_13, 3, 0 TSRMLS_CC);
		add_assoc_stringl_ex(_13, SS("type"), SL("qualified"), 1);
		zephir_array_update_string(&_13, SL("domain"), &intermediateModelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_13, SL("name"), &intermediateFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_7, this_ptr, "_getqualified", &_9, 311, _13);
		zephir_check_call_status();
		zephir_array_update_string(&_11, SL("right"), &_7, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(_10, _11);
		zephir_array_update_string(&_8, SL("conditions"), &_10, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(sqlJoins, _8);
		ZEPHIR_INIT_NVAR(_8);
		zephir_create_array(_8, 3, 0 TSRMLS_CC);
		zephir_array_update_string(&_8, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_8, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_10);
		zephir_create_array(_10, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_11);
		zephir_create_array(_11, 4, 0 TSRMLS_CC);
		add_assoc_stringl_ex(_11, SS("type"), SL("binary-op"), 1);
		add_assoc_stringl_ex(_11, SS("op"), SL("="), 1);
		ZEPHIR_INIT_VAR(_14);
		zephir_create_array(_14, 3, 0 TSRMLS_CC);
		add_assoc_long_ex(_14, SS("type"), 355);
		zephir_array_update_string(&_14, SL("domain"), &intermediateModelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_14, SL("name"), &intermediateReferencedFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_7, this_ptr, "_getqualified", &_9, 311, _14);
		zephir_check_call_status();
		zephir_array_update_string(&_11, SL("left"), &_7, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_15);
		zephir_create_array(_15, 3, 0 TSRMLS_CC);
		add_assoc_stringl_ex(_15, SS("type"), SL("qualified"), 1);
		zephir_array_update_string(&_15, SL("domain"), &referencedModelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_15, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_7, this_ptr, "_getqualified", &_9, 311, _15);
		zephir_check_call_status();
		zephir_array_update_string(&_11, SL("right"), &_7, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(_10, _11);
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
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL, *_8 = NULL, *_13 = NULL, *_20 = NULL, *_21 = NULL, *_23 = NULL, *_24 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1, *_10, *_15, *_18;
	HashPosition _0, _9, _14, _17;
	zval *select, *models, *sqlAliases, *sqlAliasesModels, *sqlModelsAliases, *sqlAliasesModelsInstances, *modelsInstances, *fromModels = NULL, *sqlJoins = NULL, *joinModels, *joinSources, *joinTypes, *joinPreCondition, *joinPrepared, *manager = NULL, *selectJoins = NULL, *joinItem = NULL, *joins, *joinData = NULL, *schema = NULL, *source = NULL, *model = NULL, *realModelName = NULL, *completeSource = NULL, *joinType = NULL, *aliasExpr = NULL, *alias = NULL, *joinAliasName = NULL, *joinExpr = NULL, *fromModelName = NULL, *joinAlias = NULL, *joinModel = NULL, *joinSource = NULL, *preCondition = NULL, *modelNameAlias = NULL, *relation = NULL, *relations = NULL, *modelAlias = NULL, *sqlJoin = NULL, **_2, *_5 = NULL, *_6, *_7 = NULL, **_11, *_12 = NULL, **_16, **_19, *_22 = NULL;

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
	zephir_array_fetch_string(&joins, select, SL("joins"), PH_NOISY, "phalcon/mvc/model/query.zep", 1198 TSRMLS_CC);
	if (!(zephir_array_isset_long(joins, 0))) {
		ZEPHIR_INIT_VAR(selectJoins);
		zephir_create_array(selectJoins, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(selectJoins, joins);
	} else {
		ZEPHIR_CPY_WRT(selectJoins, joins);
	}
	zephir_is_iterable(selectJoins, &_1, &_0, 0, 0, "phalcon/mvc/model/query.zep", 1347);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(joinItem, _2);
		ZEPHIR_CALL_METHOD(&joinData, this_ptr, "_getjoin", &_3, 315, manager, joinItem);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(source);
		zephir_array_fetch_string(&source, joinData, SL("source"), PH_NOISY, "phalcon/mvc/model/query.zep", 1211 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(schema);
		zephir_array_fetch_string(&schema, joinData, SL("schema"), PH_NOISY, "phalcon/mvc/model/query.zep", 1212 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(model);
		zephir_array_fetch_string(&model, joinData, SL("model"), PH_NOISY, "phalcon/mvc/model/query.zep", 1213 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(realModelName);
		zephir_array_fetch_string(&realModelName, joinData, SL("modelName"), PH_NOISY, "phalcon/mvc/model/query.zep", 1214 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(completeSource);
		zephir_create_array(completeSource, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(completeSource, source);
		zephir_array_fast_append(completeSource, schema);
		ZEPHIR_CALL_METHOD(&joinType, this_ptr, "_getjointype", &_4, 316, joinItem);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(aliasExpr);
		if (zephir_array_isset_string_fetch(&aliasExpr, joinItem, SS("alias"), 0 TSRMLS_CC)) {
			ZEPHIR_OBS_NVAR(alias);
			zephir_array_fetch_string(&alias, aliasExpr, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 1227 TSRMLS_CC);
			if (zephir_array_isset(joinModels, alias)) {
				ZEPHIR_INIT_NVAR(_5);
				object_init_ex(_5, phalcon_mvc_model_exception_ce);
				_6 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_7);
				ZEPHIR_CONCAT_SVSV(_7, "Cannot use '", alias, "' as join alias because it was already used, when preparing: ", _6);
				ZEPHIR_CALL_METHOD(NULL, _5, "__construct", &_8, 2, _7);
				zephir_check_call_status();
				zephir_throw_exception_debug(_5, "phalcon/mvc/model/query.zep", 1233 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&completeSource, alias, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1239);
			zephir_array_update_zval(&joinTypes, alias, &joinType, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliases, alias, &alias, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&joinModels, alias, &realModelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlModelsAliases, realModelName, &alias, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModels, alias, &realModelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModelsInstances, alias, &model, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&models, realModelName, &alias, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&joinSources, alias, &completeSource, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&joinPrepared, alias, &joinItem, PH_COPY | PH_SEPARATE);
		} else {
			if (zephir_array_isset(joinModels, realModelName)) {
				ZEPHIR_INIT_NVAR(_5);
				object_init_ex(_5, phalcon_mvc_model_exception_ce);
				_6 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_7);
				ZEPHIR_CONCAT_SVSV(_7, "Cannot use '", realModelName, "' as join alias because it was already used, when preparing: ", _6);
				ZEPHIR_CALL_METHOD(NULL, _5, "__construct", &_8, 2, _7);
				zephir_check_call_status();
				zephir_throw_exception_debug(_5, "phalcon/mvc/model/query.zep", 1292 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&joinTypes, realModelName, &joinType, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliases, realModelName, &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&joinModels, realModelName, &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlModelsAliases, realModelName, &realModelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModels, realModelName, &realModelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModelsInstances, realModelName, &model, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&models, realModelName, &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&joinSources, realModelName, &completeSource, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&joinPrepared, realModelName, &joinItem, PH_COPY | PH_SEPARATE);
		}
		zephir_array_update_zval(&modelsInstances, realModelName, &model, PH_COPY | PH_SEPARATE);
	}
	zephir_update_property_this(this_ptr, SL("_models"), models TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_sqlAliases"), sqlAliases TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_sqlAliasesModels"), sqlAliasesModels TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_sqlModelsAliases"), sqlModelsAliases TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_sqlAliasesModelsInstances"), sqlAliasesModelsInstances TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_modelsInstances"), modelsInstances TSRMLS_CC);
	zephir_is_iterable(joinPrepared, &_10, &_9, 0, 0, "phalcon/mvc/model/query.zep", 1367);
	for (
	  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
	  ; zephir_hash_move_forward_ex(_10, &_9)
	) {
		ZEPHIR_GET_HMKEY(joinAliasName, _10, _9);
		ZEPHIR_GET_HVALUE(joinItem, _11);
		ZEPHIR_OBS_NVAR(joinExpr);
		if (zephir_array_isset_string_fetch(&joinExpr, joinItem, SS("conditions"), 0 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&_12, this_ptr, "_getexpression", &_13, 309, joinExpr);
			zephir_check_call_status();
			zephir_array_update_zval(&joinPreCondition, joinAliasName, &_12, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_NVAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_5);
	zephir_is_iterable(fromModels, &_15, &_14, 0, 0, "phalcon/mvc/model/query.zep", 1473);
	for (
	  ; zephir_hash_get_current_data_ex(_15, (void**) &_16, &_14) == SUCCESS
	  ; zephir_hash_move_forward_ex(_15, &_14)
	) {
		ZEPHIR_GET_HMKEY(fromModelName, _15, _14);
		ZEPHIR_GET_HVALUE(_5, _16);
		zephir_is_iterable(joinModels, &_18, &_17, 0, 0, "phalcon/mvc/model/query.zep", 1471);
		for (
		  ; zephir_hash_get_current_data_ex(_18, (void**) &_19, &_17) == SUCCESS
		  ; zephir_hash_move_forward_ex(_18, &_17)
		) {
			ZEPHIR_GET_HMKEY(joinAlias, _18, _17);
			ZEPHIR_GET_HVALUE(joinModel, _19);
			ZEPHIR_OBS_NVAR(joinSource);
			zephir_array_fetch(&joinSource, joinSources, joinAlias, PH_NOISY, "phalcon/mvc/model/query.zep", 1376 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(joinType);
			zephir_array_fetch(&joinType, joinTypes, joinAlias, PH_NOISY, "phalcon/mvc/model/query.zep", 1381 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(preCondition);
			if (!(zephir_array_isset_fetch(&preCondition, joinPreCondition, joinAlias, 0 TSRMLS_CC))) {
				ZEPHIR_OBS_NVAR(modelNameAlias);
				zephir_array_fetch(&modelNameAlias, sqlAliasesModels, joinAlias, PH_NOISY, "phalcon/mvc/model/query.zep", 1391 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&relation, manager, "getrelationbyalias", &_20, 0, fromModelName, modelNameAlias);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(relation)) {
					ZEPHIR_CALL_METHOD(&relations, manager, "getrelationsbetween", &_21, 0, fromModelName, modelNameAlias);
					zephir_check_call_status();
					if (Z_TYPE_P(relations) == IS_ARRAY) {
						if (zephir_fast_count_int(relations TSRMLS_CC) != 1) {
							ZEPHIR_INIT_NVAR(_22);
							object_init_ex(_22, phalcon_mvc_model_exception_ce);
							_6 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
							ZEPHIR_INIT_LNVAR(_7);
							ZEPHIR_CONCAT_SVSVSV(_7, "There is more than one relation between models '", fromModelName, "' and '", joinModel, "', the join must be done using an alias, when preparing: ", _6);
							ZEPHIR_CALL_METHOD(NULL, _22, "__construct", &_8, 2, _7);
							zephir_check_call_status();
							zephir_throw_exception_debug(_22, "phalcon/mvc/model/query.zep", 1409 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_OBS_NVAR(relation);
						zephir_array_fetch_long(&relation, relations, 0, PH_NOISY, "phalcon/mvc/model/query.zep", 1415 TSRMLS_CC);
					}
				}
				if (Z_TYPE_P(relation) == IS_OBJECT) {
					ZEPHIR_OBS_NVAR(modelAlias);
					zephir_array_fetch(&modelAlias, sqlModelsAliases, fromModelName, PH_NOISY, "phalcon/mvc/model/query.zep", 1427 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_12, relation, "isthrough", NULL, 0);
					zephir_check_call_status();
					if (!(zephir_is_true(_12))) {
						ZEPHIR_CALL_METHOD(&sqlJoin, this_ptr, "_getsinglejoin", &_23, 317, joinType, joinSource, modelAlias, joinAlias, relation);
						zephir_check_call_status();
					} else {
						ZEPHIR_CALL_METHOD(&sqlJoin, this_ptr, "_getmultijoin", &_24, 318, joinType, joinSource, modelAlias, joinAlias, relation);
						zephir_check_call_status();
					}
					if (zephir_array_isset_long(sqlJoin, 0)) {
						ZEPHIR_INIT_NVAR(_22);
						zephir_fast_array_merge(_22, &(sqlJoins), &(sqlJoin) TSRMLS_CC);
						ZEPHIR_CPY_WRT(sqlJoins, _22);
					} else {
						zephir_array_append(&sqlJoins, sqlJoin, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1444);
					}
				} else {
					ZEPHIR_INIT_NVAR(_25);
					zephir_create_array(_25, 3, 0 TSRMLS_CC);
					zephir_array_update_string(&_25, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_25, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(_22);
					array_init(_22);
					zephir_array_update_string(&_25, SL("conditions"), &_22, PH_COPY | PH_SEPARATE);
					zephir_array_append(&sqlJoins, _25, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1456);
				}
			} else {
				ZEPHIR_INIT_NVAR(_25);
				zephir_create_array(_25, 3, 0 TSRMLS_CC);
				zephir_array_update_string(&_25, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_25, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_26);
				zephir_create_array(_26, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(_26, preCondition);
				zephir_array_update_string(&_25, SL("conditions"), &_26, PH_COPY | PH_SEPARATE);
				zephir_array_append(&sqlJoins, _25, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1468);
			}
		}
	}
	RETURN_CCTOR(sqlJoins);

}

/**
 * Returns a processed order clause for a SELECT statement
 *
 * @param array|string $order
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getOrderClause) {

	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *order, *orderColumns = NULL, *orderParts, *orderItem = NULL, *orderPartExpr = NULL, *orderSort, *orderPartSort = NULL, **_2, *_3, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &order);



	if (!(zephir_array_isset_long(order, 0))) {
		ZEPHIR_INIT_VAR(orderColumns);
		zephir_create_array(orderColumns, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(orderColumns, order);
	} else {
		ZEPHIR_CPY_WRT(orderColumns, order);
	}
	ZEPHIR_INIT_VAR(orderParts);
	array_init(orderParts);
	zephir_is_iterable(orderColumns, &_1, &_0, 0, 0, "phalcon/mvc/model/query.zep", 1514);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(orderItem, _2);
		zephir_array_fetch_string(&_3, orderItem, SL("column"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 1496 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&orderPartExpr, this_ptr, "_getexpression", &_4, 309, _3);
		zephir_check_call_status();
		if (zephir_array_isset_string_fetch(&orderSort, orderItem, SS("sort"), 1 TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(orderPartSort);
			if (ZEPHIR_IS_LONG(orderSort, 327)) {
				zephir_create_array(orderPartSort, 2, 0 TSRMLS_CC);
				zephir_array_fast_append(orderPartSort, orderPartExpr);
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_STRING(_5, "ASC", 1);
				zephir_array_fast_append(orderPartSort, _5);
			} else {
				zephir_create_array(orderPartSort, 2, 0 TSRMLS_CC);
				zephir_array_fast_append(orderPartSort, orderPartExpr);
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_STRING(_5, "DESC", 1);
				zephir_array_fast_append(orderPartSort, _5);
			}
		} else {
			ZEPHIR_INIT_NVAR(orderPartSort);
			zephir_create_array(orderPartSort, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(orderPartSort, orderPartExpr);
		}
		zephir_array_append(&orderParts, orderPartSort, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1511);
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

	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *group, *groupItem = NULL, *groupParts, **_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &group);



	ZEPHIR_INIT_VAR(groupParts);
	if (zephir_array_isset_long(group, 0)) {
		array_init(groupParts);
		zephir_is_iterable(group, &_1, &_0, 0, 0, "phalcon/mvc/model/query.zep", 1535);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(groupItem, _2);
			ZEPHIR_CALL_METHOD(&_3, this_ptr, "_getexpression", &_4, 309, groupItem);
			zephir_check_call_status();
			zephir_array_append(&groupParts, _3, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1533);
		}
	} else {
		zephir_create_array(groupParts, 1, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "_getexpression", &_4, 309, group);
		zephir_check_call_status();
		zephir_array_fast_append(groupParts, _3);
	}
	RETURN_CCTOR(groupParts);

}

/**
 * Returns a processed limit clause for a SELECT statement
 *
 * @param array $limit
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getLimitClause) {

	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *limit;
	zval *limitClause, *number, *offset, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &limitClause);

	ZEPHIR_INIT_VAR(limit);
	array_init(limit);


	ZEPHIR_OBS_VAR(number);
	if (zephir_array_isset_string_fetch(&number, limitClause, SS("number"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "_getexpression", &_1, 309, number);
		zephir_check_call_status();
		zephir_array_update_string(&limit, SL("number"), &_0, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(offset);
	if (zephir_array_isset_string_fetch(&offset, limitClause, SS("offset"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "_getexpression", &_1, 309, offset);
		zephir_check_call_status();
		zephir_array_update_string(&limit, SL("offset"), &_0, PH_COPY | PH_SEPARATE);
	}
	RETURN_CTOR(limit);

}

/**
 * Analyzes a SELECT intermediate code and produces an array to be executed later
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareSelect) {

	zval *_32 = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL, *_11 = NULL, *_27 = NULL, *_33 = NULL;
	HashTable *_1, *_25, *_29;
	HashPosition _0, _24, _28;
	int position, ZEPHIR_LAST_CALL_STATUS;
	zval *ast = NULL, *merge = NULL, *sqlModels, *sqlTables, *sqlAliases, *sqlColumns, *select = NULL, *tables, *columns, *sqlAliasesModels, *sqlModelsAliases, *sqlAliasesModelsInstances, *models, *modelsInstances, *selectedModels = NULL, *manager, *metaData, *selectedModel = NULL, *qualifiedName = NULL, *modelName = NULL, *nsAlias = NULL, *realModelName = NULL, *model = NULL, *schema = NULL, *source = NULL, *completeSource = NULL, *alias = NULL, *joins, *sqlJoins = NULL, *selectColumns = NULL, *sqlColumnAliases, *column = NULL, *sqlColumn = NULL, *sqlSelect, *distinct, *having, *where, *groupBy, *order, *limit, **_2, *_3 = NULL, *_4, *_6, *_7 = NULL, *_9, *_10 = NULL, *_12, *_13, *_14, *_15, *_16, *_17, *_18, *_19, *_20, *_21, *_22, *_23, **_26, **_30, _31 = zval_used_for_init, *_34 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &ast, &merge);

	if (!ast) {
		ZEPHIR_CPY_WRT(ast, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(ast);
	}
	if (!merge) {
		ZEPHIR_CPY_WRT(merge, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(merge);
	}


	if (ZEPHIR_IS_EMPTY(ast)) {
		ZEPHIR_OBS_NVAR(ast);
		zephir_read_property_this(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(merge) == IS_NULL) {
		ZEPHIR_INIT_NVAR(merge);
		ZVAL_BOOL(merge, 0);
	}
	ZEPHIR_OBS_VAR(select);
	if (!(zephir_array_isset_string_fetch(&select, ast, SS("select"), 0 TSRMLS_CC))) {
		ZEPHIR_CPY_WRT(select, ast);
	}
	ZEPHIR_OBS_VAR(tables);
	if (!(zephir_array_isset_string_fetch(&tables, select, SS("tables"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST", "phalcon/mvc/model/query.zep", 1590);
		return;
	}
	ZEPHIR_OBS_VAR(columns);
	if (!(zephir_array_isset_string_fetch(&columns, select, SS("columns"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST", "phalcon/mvc/model/query.zep", 1594);
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
		zephir_create_array(selectedModels, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(selectedModels, tables);
	} else {
		ZEPHIR_CPY_WRT(selectedModels, tables);
	}
	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(metaData);
	zephir_read_property_this(&metaData, this_ptr, SL("_metaData"), PH_NOISY_CC);
	if (Z_TYPE_P(manager) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A models-manager is required to execute the query", "phalcon/mvc/model/query.zep", 1648);
		return;
	}
	if (Z_TYPE_P(metaData) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A meta-data is required to execute the query", "phalcon/mvc/model/query.zep", 1652);
		return;
	}
	zephir_is_iterable(selectedModels, &_1, &_0, 0, 0, "phalcon/mvc/model/query.zep", 1736);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(selectedModel, _2);
		ZEPHIR_OBS_NVAR(qualifiedName);
		zephir_array_fetch_string(&qualifiedName, selectedModel, SL("qualifiedName"), PH_NOISY, "phalcon/mvc/model/query.zep", 1660 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(modelName);
		zephir_array_fetch_string(&modelName, qualifiedName, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 1661 TSRMLS_CC);
		if (zephir_memnstr_str(modelName, SL(":"), "phalcon/mvc/model/query.zep", 1666)) {
			ZEPHIR_INIT_NVAR(nsAlias);
			zephir_fast_explode_str(nsAlias, SL(":"), modelName, LONG_MAX TSRMLS_CC);
			zephir_array_fetch_long(&_4, nsAlias, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 1668 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_3, manager, "getnamespacealias", &_5, 0, _4);
			zephir_check_call_status();
			zephir_array_fetch_long(&_6, nsAlias, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 1668 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(realModelName);
			ZEPHIR_CONCAT_VSV(realModelName, _3, "\\", _6);
		} else {
			ZEPHIR_CPY_WRT(realModelName, modelName);
		}
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_BOOL(_7, 1);
		ZEPHIR_CALL_METHOD(&model, manager, "load", &_8, 0, realModelName, _7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&schema, model, "getschema", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&source, model, "getsource", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(schema)) {
			ZEPHIR_INIT_NVAR(completeSource);
			zephir_create_array(completeSource, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(completeSource, source);
			zephir_array_fast_append(completeSource, schema);
		} else {
			ZEPHIR_CPY_WRT(completeSource, source);
		}
		ZEPHIR_OBS_NVAR(alias);
		if (zephir_array_isset_string_fetch(&alias, selectedModel, SS("alias"), 0 TSRMLS_CC)) {
			if (zephir_array_isset(sqlAliases, alias)) {
				ZEPHIR_INIT_NVAR(_7);
				object_init_ex(_7, phalcon_mvc_model_exception_ce);
				_9 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_10);
				ZEPHIR_CONCAT_SVSV(_10, "Alias '", alias, "' is already used, when preparing: ", _9);
				ZEPHIR_CALL_METHOD(NULL, _7, "__construct", &_11, 2, _10);
				zephir_check_call_status();
				zephir_throw_exception_debug(_7, "phalcon/mvc/model/query.zep", 1702 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&sqlAliases, alias, &alias, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModels, alias, &realModelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlModelsAliases, realModelName, &alias, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModelsInstances, alias, &model, PH_COPY | PH_SEPARATE);
			if (Z_TYPE_P(completeSource) == IS_ARRAY) {
				zephir_array_append(&completeSource, alias, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1714);
			} else {
				ZEPHIR_INIT_NVAR(completeSource);
				zephir_create_array(completeSource, 3, 0 TSRMLS_CC);
				zephir_array_fast_append(completeSource, source);
				zephir_array_fast_append(completeSource, ZEPHIR_GLOBAL(global_null));
				zephir_array_fast_append(completeSource, alias);
			}
			zephir_array_update_zval(&models, realModelName, &alias, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&sqlAliases, realModelName, &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModels, realModelName, &realModelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlModelsAliases, realModelName, &realModelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModelsInstances, realModelName, &model, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&models, realModelName, &source, PH_COPY | PH_SEPARATE);
		}
		zephir_array_append(&sqlModels, realModelName, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1728);
		zephir_array_append(&sqlTables, completeSource, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1729);
		zephir_array_update_zval(&modelsInstances, realModelName, &model, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_is_true(merge))) {
		zephir_update_property_this(this_ptr, SL("_models"), models TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_modelsInstances"), modelsInstances TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_sqlAliases"), sqlAliases TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_sqlAliasesModels"), sqlAliasesModels TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_sqlModelsAliases"), sqlModelsAliases TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_sqlAliasesModelsInstances"), sqlAliasesModelsInstances TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_modelsInstances"), modelsInstances TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_7);
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_models"), PH_NOISY_CC);
		zephir_fast_array_merge(_7, &(_9), &(models) TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_models"), _7 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_12);
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
		zephir_fast_array_merge(_12, &(_13), &(modelsInstances) TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_modelsInstances"), _12 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_14);
		_15 = zephir_fetch_nproperty_this(this_ptr, SL("_sqlAliases"), PH_NOISY_CC);
		zephir_fast_array_merge(_14, &(_15), &(sqlAliases) TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_sqlAliases"), _14 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_16);
		_17 = zephir_fetch_nproperty_this(this_ptr, SL("_sqlAliasesModels"), PH_NOISY_CC);
		zephir_fast_array_merge(_16, &(_17), &(sqlAliasesModels) TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_sqlAliasesModels"), _16 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_18);
		_19 = zephir_fetch_nproperty_this(this_ptr, SL("_sqlModelsAliases"), PH_NOISY_CC);
		zephir_fast_array_merge(_18, &(_19), &(sqlModelsAliases) TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_sqlModelsAliases"), _18 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_20);
		_21 = zephir_fetch_nproperty_this(this_ptr, SL("_sqlAliasesModelsInstances"), PH_NOISY_CC);
		zephir_fast_array_merge(_20, &(_21), &(sqlAliasesModelsInstances) TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_sqlAliasesModelsInstances"), _20 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_22);
		_23 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
		zephir_fast_array_merge(_22, &(_23), &(modelsInstances) TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_modelsInstances"), _22 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(joins);
	if (zephir_array_isset_string_fetch(&joins, select, SS("joins"), 0 TSRMLS_CC)) {
		if (zephir_fast_count_int(joins TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&sqlJoins, this_ptr, "_getjoins", NULL, 319, select);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(sqlJoins);
			array_init(sqlJoins);
		}
	} else {
		ZEPHIR_INIT_NVAR(sqlJoins);
		array_init(sqlJoins);
	}
	if (!(zephir_array_isset_long(columns, 0))) {
		ZEPHIR_INIT_VAR(selectColumns);
		zephir_create_array(selectColumns, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(selectColumns, columns);
	} else {
		ZEPHIR_CPY_WRT(selectColumns, columns);
	}
	position = 0;
	ZEPHIR_INIT_VAR(sqlColumnAliases);
	array_init(sqlColumnAliases);
	zephir_is_iterable(selectColumns, &_25, &_24, 0, 0, "phalcon/mvc/model/query.zep", 1817);
	for (
	  ; zephir_hash_get_current_data_ex(_25, (void**) &_26, &_24) == SUCCESS
	  ; zephir_hash_move_forward_ex(_25, &_24)
	) {
		ZEPHIR_GET_HVALUE(column, _26);
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "_getselectcolumn", &_27, 320, column);
		zephir_check_call_status();
		zephir_is_iterable(_3, &_29, &_28, 0, 0, "phalcon/mvc/model/query.zep", 1816);
		for (
		  ; zephir_hash_get_current_data_ex(_29, (void**) &_30, &_28) == SUCCESS
		  ; zephir_hash_move_forward_ex(_29, &_28)
		) {
			ZEPHIR_GET_HVALUE(sqlColumn, _30);
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
					zephir_array_fetch_string(&_4, sqlColumn, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 1806 TSRMLS_CC);
					if (ZEPHIR_IS_STRING(_4, "scalar")) {
						ZEPHIR_SINIT_NVAR(_31);
						ZVAL_LONG(&_31, position);
						ZEPHIR_INIT_LNVAR(_32);
						ZEPHIR_CONCAT_SV(_32, "_", &_31);
						zephir_array_update_zval(&sqlColumns, _32, &sqlColumn, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_append(&sqlColumns, sqlColumn, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1809);
					}
				}
			}
			position++;
		}
	}
	zephir_update_property_this(this_ptr, SL("_sqlColumnAliases"), sqlColumnAliases TSRMLS_CC);
	ZEPHIR_INIT_VAR(sqlSelect);
	zephir_create_array(sqlSelect, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&sqlSelect, SL("models"), &sqlModels, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlSelect, SL("tables"), &sqlTables, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlSelect, SL("columns"), &sqlColumns, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(distinct);
	if (zephir_array_isset_string_fetch(&distinct, select, SS("distinct"), 0 TSRMLS_CC)) {
		zephir_array_update_string(&sqlSelect, SL("distinct"), &distinct, PH_COPY | PH_SEPARATE);
	}
	if (zephir_fast_count_int(sqlJoins TSRMLS_CC)) {
		zephir_array_update_string(&sqlSelect, SL("joins"), &sqlJoins, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(where);
	if (zephir_array_isset_string_fetch(&where, ast, SS("where"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "_getexpression", &_33, 309, where);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("where"), &_3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(groupBy);
	if (zephir_array_isset_string_fetch(&groupBy, ast, SS("groupBy"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_34, this_ptr, "_getgroupclause", NULL, 321, groupBy);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("group"), &_34, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(having);
	if (zephir_array_isset_string_fetch(&having, ast, SS("having"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_34, this_ptr, "_getexpression", &_33, 309, having);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("having"), &_34, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(order);
	if (zephir_array_isset_string_fetch(&order, ast, SS("orderBy"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_34, this_ptr, "_getorderclause", NULL, 322, order);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("order"), &_34, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(limit);
	if (zephir_array_isset_string_fetch(&limit, ast, SS("limit"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_34, this_ptr, "_getlimitclause", NULL, 323, limit);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("limit"), &_34, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(sqlSelect);

}

/**
 * Analyzes an INSERT intermediate code and produces an array to be executed later
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareInsert) {

	zephir_fcall_cache_entry *_9 = NULL, *_13 = NULL, *_16 = NULL;
	zval *_7 = NULL;
	HashTable *_5, *_11;
	HashPosition _4, _10;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool notQuoting;
	zval *ast, *qualifiedName, *nsAlias, *manager, *modelName, *model = NULL, *source = NULL, *schema = NULL, *exprValues, *exprValue = NULL, *sqlInsert, *metaData, *fields, *sqlFields, *field = NULL, *name = NULL, *realModelName = NULL, *_0 = NULL, *_1, *_2, *_3 = NULL, **_6, *_8 = NULL, **_12, *_14, *_15 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(ast);
	zephir_read_property_this(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	if (!(zephir_array_isset_string(ast, SS("qualifiedName")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted INSERT AST", "phalcon/mvc/model/query.zep", 1887);
		return;
	}
	if (!(zephir_array_isset_string(ast, SS("values")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted INSERT AST", "phalcon/mvc/model/query.zep", 1891);
		return;
	}
	ZEPHIR_OBS_VAR(qualifiedName);
	zephir_array_fetch_string(&qualifiedName, ast, SL("qualifiedName"), PH_NOISY, "phalcon/mvc/model/query.zep", 1894 TSRMLS_CC);
	if (!(zephir_array_isset_string(qualifiedName, SS("name")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted INSERT AST", "phalcon/mvc/model/query.zep", 1900);
		return;
	}
	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(modelName);
	zephir_array_fetch_string(&modelName, qualifiedName, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 1904 TSRMLS_CC);
	if (zephir_memnstr_str(modelName, SL(":"), "phalcon/mvc/model/query.zep", 1909)) {
		ZEPHIR_INIT_VAR(nsAlias);
		zephir_fast_explode_str(nsAlias, SL(":"), modelName, LONG_MAX TSRMLS_CC);
		zephir_array_fetch_long(&_1, nsAlias, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 1911 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_0, manager, "getnamespacealias", NULL, 0, _1);
		zephir_check_call_status();
		zephir_array_fetch_long(&_2, nsAlias, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 1911 TSRMLS_CC);
		ZEPHIR_INIT_VAR(realModelName);
		ZEPHIR_CONCAT_VSV(realModelName, _0, "\\", _2);
	} else {
		ZEPHIR_CPY_WRT(realModelName, modelName);
	}
	ZEPHIR_INIT_VAR(_3);
	ZVAL_BOOL(_3, 1);
	ZEPHIR_CALL_METHOD(&model, manager, "load", NULL, 0, realModelName, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, model, "getsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&schema, model, "getschema", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(schema)) {
		ZEPHIR_INIT_NVAR(source);
		zephir_create_array(source, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(source, schema);
		zephir_array_fast_append(source, source);
	}
	notQuoting = 0;
	ZEPHIR_INIT_VAR(exprValues);
	array_init(exprValues);
	zephir_array_fetch_string(&_1, ast, SL("values"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 1927 TSRMLS_CC);
	zephir_is_iterable(_1, &_5, &_4, 0, 0, "phalcon/mvc/model/query.zep", 1938);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(exprValue, _6);
		ZEPHIR_INIT_NVAR(_7);
		zephir_create_array(_7, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_8);
		zephir_array_fetch_string(&_8, exprValue, SL("type"), PH_NOISY, "phalcon/mvc/model/query.zep", 1933 TSRMLS_CC);
		zephir_array_update_string(&_7, SL("type"), &_8, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "_getexpression", &_9, 309, exprValue, (notQuoting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
		zephir_check_call_status();
		zephir_array_update_string(&_7, SL("value"), &_0, PH_COPY | PH_SEPARATE);
		zephir_array_append(&exprValues, _7, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1935);
	}
	ZEPHIR_INIT_VAR(sqlInsert);
	zephir_create_array(sqlInsert, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&sqlInsert, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlInsert, SL("table"), &source, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(metaData);
	zephir_read_property_this(&metaData, this_ptr, SL("_metaData"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(fields);
	if (zephir_array_isset_string_fetch(&fields, ast, SS("fields"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(sqlFields);
		array_init(sqlFields);
		zephir_is_iterable(fields, &_11, &_10, 0, 0, "phalcon/mvc/model/query.zep", 1964);
		for (
		  ; zephir_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
		  ; zephir_hash_move_forward_ex(_11, &_10)
		) {
			ZEPHIR_GET_HVALUE(field, _12);
			ZEPHIR_OBS_NVAR(name);
			zephir_array_fetch_string(&name, field, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 1949 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_0, metaData, "hasattribute", &_13, 0, model, name);
			zephir_check_call_status();
			if (!(zephir_is_true(_0))) {
				ZEPHIR_INIT_NVAR(_3);
				object_init_ex(_3, phalcon_mvc_model_exception_ce);
				_14 = zephir_fetch_nproperty_this(this_ptr, SL("_phql"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_15);
				ZEPHIR_CONCAT_SVSVSV(_15, "The model '", modelName, "' doesn't have the attribute '", name, "', when preparing: ", _14);
				ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_16, 2, _15);
				zephir_check_call_status();
				zephir_throw_exception_debug(_3, "phalcon/mvc/model/query.zep", 1955 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&sqlFields, name, PH_SEPARATE, "phalcon/mvc/model/query.zep", 1961);
		}
		zephir_array_update_string(&sqlInsert, SL("fields"), &sqlFields, PH_COPY | PH_SEPARATE);
	}
	zephir_array_update_string(&sqlInsert, SL("values"), &exprValues, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(sqlInsert);

}

/**
 * Analyzes an UPDATE intermediate code and produces an array to be executed later
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareUpdate) {

	zval *_13 = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL, *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1, *_10;
	HashPosition _0, _9;
	zend_bool notQuoting;
	zval *ast, *update, *tables, *values, *modelsInstances, *models, *sqlTables, *sqlAliases, *sqlAliasesModelsInstances, *updateTables = NULL, *nsAlias = NULL, *realModelName = NULL, *completeSource = NULL, *sqlModels, *manager, *table = NULL, *qualifiedName = NULL, *modelName = NULL, *model = NULL, *source = NULL, *schema = NULL, *alias = NULL, *sqlFields, *sqlValues, *updateValues = NULL, *updateValue = NULL, *exprColumn = NULL, *sqlUpdate, *where, *limit, **_2, *_3 = NULL, *_4, *_6, *_7 = NULL, **_11, *_14 = NULL, *_15 = NULL, _16;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(ast);
	zephir_read_property_this(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(update);
	if (!(zephir_array_isset_string_fetch(&update, ast, SS("update"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted UPDATE AST", "phalcon/mvc/model/query.zep", 1988);
		return;
	}
	ZEPHIR_OBS_VAR(tables);
	if (!(zephir_array_isset_string_fetch(&tables, update, SS("tables"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted UPDATE AST", "phalcon/mvc/model/query.zep", 1992);
		return;
	}
	ZEPHIR_OBS_VAR(values);
	if (!(zephir_array_isset_string_fetch(&values, update, SS("values"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted UPDATE AST", "phalcon/mvc/model/query.zep", 1996);
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
		zephir_create_array(updateTables, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(updateTables, tables);
	} else {
		ZEPHIR_CPY_WRT(updateTables, tables);
	}
	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	zephir_is_iterable(updateTables, &_1, &_0, 0, 0, "phalcon/mvc/model/query.zep", 2071);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(table, _2);
		ZEPHIR_OBS_NVAR(qualifiedName);
		zephir_array_fetch_string(&qualifiedName, table, SL("qualifiedName"), PH_NOISY, "phalcon/mvc/model/query.zep", 2019 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(modelName);
		zephir_array_fetch_string(&modelName, qualifiedName, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 2020 TSRMLS_CC);
		if (zephir_memnstr_str(modelName, SL(":"), "phalcon/mvc/model/query.zep", 2025)) {
			ZEPHIR_INIT_NVAR(nsAlias);
			zephir_fast_explode_str(nsAlias, SL(":"), modelName, LONG_MAX TSRMLS_CC);
			zephir_array_fetch_long(&_4, nsAlias, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2027 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_3, manager, "getnamespacealias", &_5, 0, _4);
			zephir_check_call_status();
			zephir_array_fetch_long(&_6, nsAlias, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2027 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(realModelName);
			ZEPHIR_CONCAT_VSV(realModelName, _3, "\\", _6);
		} else {
			ZEPHIR_CPY_WRT(realModelName, modelName);
		}
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_BOOL(_7, 1);
		ZEPHIR_CALL_METHOD(&model, manager, "load", &_8, 0, realModelName, _7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&source, model, "getsource", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&schema, model, "getschema", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(completeSource);
		if (zephir_is_true(schema)) {
			zephir_create_array(completeSource, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(completeSource, source);
			zephir_array_fast_append(completeSource, schema);
		} else {
			zephir_create_array(completeSource, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(completeSource, source);
			zephir_array_fast_append(completeSource, ZEPHIR_GLOBAL(global_null));
		}
		ZEPHIR_OBS_NVAR(alias);
		if (zephir_array_isset_string_fetch(&alias, table, SS("alias"), 0 TSRMLS_CC)) {
			zephir_array_update_zval(&sqlAliases, alias, &alias, PH_COPY | PH_SEPARATE);
			zephir_array_append(&completeSource, alias, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2053);
			zephir_array_append(&sqlTables, completeSource, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2054);
			zephir_array_update_zval(&sqlAliasesModelsInstances, alias, &model, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&models, alias, &realModelName, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&sqlAliases, realModelName, &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModelsInstances, realModelName, &model, PH_COPY | PH_SEPARATE);
			zephir_array_append(&sqlTables, source, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2060);
			zephir_array_update_zval(&models, realModelName, &source, PH_COPY | PH_SEPARATE);
		}
		zephir_array_append(&sqlModels, realModelName, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2064);
		zephir_array_update_zval(&modelsInstances, realModelName, &model, PH_COPY | PH_SEPARATE);
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
		zephir_create_array(updateValues, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(updateValues, values);
	} else {
		ZEPHIR_CPY_WRT(updateValues, values);
	}
	notQuoting = 0;
	zephir_is_iterable(updateValues, &_10, &_9, 0, 0, "phalcon/mvc/model/query.zep", 2096);
	for (
	  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
	  ; zephir_hash_move_forward_ex(_10, &_9)
	) {
		ZEPHIR_GET_HVALUE(updateValue, _11);
		zephir_array_fetch_string(&_4, updateValue, SL("column"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2087 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "_getexpression", &_12, 309, _4, (notQuoting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
		zephir_check_call_status();
		zephir_array_append(&sqlFields, _3, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2087);
		ZEPHIR_OBS_NVAR(exprColumn);
		zephir_array_fetch_string(&exprColumn, updateValue, SL("expr"), PH_NOISY, "phalcon/mvc/model/query.zep", 2088 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_13);
		zephir_create_array(_13, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_14);
		zephir_array_fetch_string(&_14, exprColumn, SL("type"), PH_NOISY, "phalcon/mvc/model/query.zep", 2090 TSRMLS_CC);
		zephir_array_update_string(&_13, SL("type"), &_14, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_15, this_ptr, "_getexpression", &_12, 309, exprColumn, (notQuoting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
		zephir_check_call_status();
		zephir_array_update_string(&_13, SL("value"), &_15, PH_COPY | PH_SEPARATE);
		zephir_array_append(&sqlValues, _13, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2092);
	}
	ZEPHIR_INIT_VAR(sqlUpdate);
	zephir_create_array(sqlUpdate, 4, 0 TSRMLS_CC);
	zephir_array_update_string(&sqlUpdate, SL("tables"), &sqlTables, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlUpdate, SL("models"), &sqlModels, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlUpdate, SL("fields"), &sqlFields, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlUpdate, SL("values"), &sqlValues, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(where);
	if (zephir_array_isset_string_fetch(&where, ast, SS("where"), 0 TSRMLS_CC)) {
		ZEPHIR_SINIT_VAR(_16);
		ZVAL_BOOL(&_16, 1);
		ZEPHIR_CALL_METHOD(&_15, this_ptr, "_getexpression", &_12, 309, where, &_16);
		zephir_check_call_status();
		zephir_array_update_string(&sqlUpdate, SL("where"), &_15, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(limit);
	if (zephir_array_isset_string_fetch(&limit, ast, SS("limit"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_15, this_ptr, "_getlimitclause", NULL, 323, limit);
		zephir_check_call_status();
		zephir_array_update_string(&sqlUpdate, SL("limit"), &_15, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(sqlUpdate);

}

/**
 * Analyzes a DELETE intermediate code and produces an array to be executed later
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareDelete) {

	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *ast, *delete, *tables, *models, *modelsInstances, *sqlTables, *sqlModels, *sqlAliases, *sqlAliasesModelsInstances, *deleteTables = NULL, *manager, *table = NULL, *qualifiedName = NULL, *modelName = NULL, *nsAlias = NULL, *realModelName = NULL, *model = NULL, *source = NULL, *schema = NULL, *completeSource = NULL, *alias = NULL, *sqlDelete, *where, *limit, **_2, *_3 = NULL, *_4, *_6, *_7 = NULL, _9, *_10 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(ast);
	zephir_read_property_this(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(delete);
	if (!(zephir_array_isset_string_fetch(&delete, ast, SS("delete"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted DELETE AST", "phalcon/mvc/model/query.zep", 2128);
		return;
	}
	ZEPHIR_OBS_VAR(tables);
	if (!(zephir_array_isset_string_fetch(&tables, delete, SS("tables"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted DELETE AST", "phalcon/mvc/model/query.zep", 2132);
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
		zephir_create_array(deleteTables, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(deleteTables, tables);
	} else {
		ZEPHIR_CPY_WRT(deleteTables, tables);
	}
	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	zephir_is_iterable(deleteTables, &_1, &_0, 0, 0, "phalcon/mvc/model/query.zep", 2203);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(table, _2);
		ZEPHIR_OBS_NVAR(qualifiedName);
		zephir_array_fetch_string(&qualifiedName, table, SL("qualifiedName"), PH_NOISY, "phalcon/mvc/model/query.zep", 2154 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(modelName);
		zephir_array_fetch_string(&modelName, qualifiedName, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 2155 TSRMLS_CC);
		if (zephir_memnstr_str(modelName, SL(":"), "phalcon/mvc/model/query.zep", 2163)) {
			ZEPHIR_INIT_NVAR(nsAlias);
			zephir_fast_explode_str(nsAlias, SL(":"), modelName, LONG_MAX TSRMLS_CC);
			zephir_array_fetch_long(&_4, nsAlias, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2165 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_3, manager, "getnamespacealias", &_5, 0, _4);
			zephir_check_call_status();
			zephir_array_fetch_long(&_6, nsAlias, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2165 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(realModelName);
			ZEPHIR_CONCAT_VSV(realModelName, _3, "\\", _6);
		} else {
			ZEPHIR_CPY_WRT(realModelName, modelName);
		}
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_BOOL(_7, 1);
		ZEPHIR_CALL_METHOD(&model, manager, "load", &_8, 0, realModelName, _7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&source, model, "getsource", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&schema, model, "getschema", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(completeSource);
		if (zephir_is_true(schema)) {
			zephir_create_array(completeSource, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(completeSource, source);
			zephir_array_fast_append(completeSource, schema);
		} else {
			zephir_create_array(completeSource, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(completeSource, source);
			zephir_array_fast_append(completeSource, ZEPHIR_GLOBAL(global_null));
		}
		ZEPHIR_OBS_NVAR(alias);
		if (zephir_array_isset_string_fetch(&alias, table, SS("alias"), 0 TSRMLS_CC)) {
			zephir_array_update_zval(&sqlAliases, alias, &alias, PH_COPY | PH_SEPARATE);
			zephir_array_append(&completeSource, alias, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2185);
			zephir_array_append(&sqlTables, completeSource, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2186);
			zephir_array_update_zval(&sqlAliasesModelsInstances, alias, &model, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&models, alias, &realModelName, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&sqlAliases, realModelName, &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&sqlAliasesModelsInstances, realModelName, &model, PH_COPY | PH_SEPARATE);
			zephir_array_append(&sqlTables, source, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2192);
			zephir_array_update_zval(&models, realModelName, &source, PH_COPY | PH_SEPARATE);
		}
		zephir_array_append(&sqlModels, realModelName, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2196);
		zephir_array_update_zval(&modelsInstances, realModelName, &model, PH_COPY | PH_SEPARATE);
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
		ZEPHIR_SINIT_VAR(_9);
		ZVAL_BOOL(&_9, 1);
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "_getexpression", NULL, 309, where, &_9);
		zephir_check_call_status();
		zephir_array_update_string(&sqlDelete, SL("where"), &_3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(limit);
	if (zephir_array_isset_string_fetch(&limit, ast, SS("limit"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_10, this_ptr, "_getlimitclause", NULL, 323, limit);
		zephir_check_call_status();
		zephir_array_update_string(&sqlDelete, SL("limit"), &_10, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(sqlDelete);

}

/**
 * Parses the intermediate code produced by Phalcon\Mvc\Model\Query\Lang generating another
 * intermediate representation that could be executed by Phalcon\Mvc\Model\Query
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, parse) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *intermediate, *phql, *ast, *irPhql = NULL, *uniqueId = NULL, *type, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(intermediate);
	zephir_read_property_this(&intermediate, this_ptr, SL("_intermediate"), PH_NOISY_CC);
	if (Z_TYPE_P(intermediate) == IS_ARRAY) {
		RETURN_CCTOR(intermediate);
	}
	ZEPHIR_OBS_VAR(phql);
	zephir_read_property_this(&phql, this_ptr, SL("_phql"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(ast);
	ZEPHIR_LAST_CALL_STATUS = phql_parse_phql(ast, phql TSRMLS_CC);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(irPhql);
	ZVAL_NULL(irPhql);
	ZEPHIR_INIT_VAR(uniqueId);
	ZVAL_NULL(uniqueId);
	if (Z_TYPE_P(ast) == IS_ARRAY) {
		ZEPHIR_OBS_NVAR(uniqueId);
		if (zephir_array_isset_string_fetch(&uniqueId, ast, SS("id"), 0 TSRMLS_CC)) {
			ZEPHIR_OBS_NVAR(irPhql);
			_0 = zephir_fetch_static_property_ce(phalcon_mvc_model_query_ce, SL("_irPhqlCache") TSRMLS_CC);
			if (zephir_array_isset_fetch(&irPhql, _0, uniqueId, 0 TSRMLS_CC)) {
				if (Z_TYPE_P(irPhql) == IS_ARRAY) {
					zephir_array_fetch_string(&_1, ast, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2254 TSRMLS_CC);
					zephir_update_property_this(this_ptr, SL("_type"), _1 TSRMLS_CC);
					RETURN_CCTOR(irPhql);
				}
			}
		}
		ZEPHIR_OBS_VAR(type);
		if (zephir_array_isset_string_fetch(&type, ast, SS("type"), 0 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_ast"), ast TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
			do {
				if (ZEPHIR_IS_LONG(type, 309)) {
					ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "_prepareselect", NULL, 314);
					zephir_check_call_status();
					break;
				}
				if (ZEPHIR_IS_LONG(type, 306)) {
					ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "_prepareinsert", NULL, 324);
					zephir_check_call_status();
					break;
				}
				if (ZEPHIR_IS_LONG(type, 300)) {
					ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "_prepareupdate", NULL, 325);
					zephir_check_call_status();
					break;
				}
				if (ZEPHIR_IS_LONG(type, 303)) {
					ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "_preparedelete", NULL, 326);
					zephir_check_call_status();
					break;
				}
				ZEPHIR_INIT_VAR(_2);
				object_init_ex(_2, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(_3);
				ZEPHIR_CONCAT_SVSV(_3, "Unknown statement ", type, ", when preparing: ", phql);
				ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 2, _3);
				zephir_check_call_status();
				zephir_throw_exception_debug(_2, "phalcon/mvc/model/query.zep", 2287 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			} while(0);

		}
	}
	if (Z_TYPE_P(irPhql) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Corrupted AST", "phalcon/mvc/model/query.zep", 2293);
		return;
	}
	if (Z_TYPE_P(uniqueId) == IS_LONG) {
		zephir_update_static_property_array_multi_ce(phalcon_mvc_model_query_ce, SL("_irPhqlCache"), &irPhql TSRMLS_CC, SL("z"), 1, uniqueId);
	}
	zephir_update_property_this(this_ptr, SL("_intermediate"), irPhql TSRMLS_CC);
	RETURN_CCTOR(irPhql);

}

/**
 * Returns the current cache backend instance
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getCache) {


	RETURN_MEMBER(this_ptr, "_cache");

}

/**
 * Executes the SELECT intermediate representation producing a Phalcon\Mvc\Model\Resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeSelect) {

	zval *_20 = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_14 = NULL, *_15 = NULL, *_16 = NULL, *_22 = NULL;
	HashTable *_1, *_8, *_12, *_18, *_24, *_28, *_31;
	HashPosition _0, _7, _11, _17, _23, _27, _30;
	int numberObjects, ZEPHIR_LAST_CALL_STATUS;
	zend_bool simulate, haveObjects, haveScalars, isComplex, isSimpleStd, isKeepingSnapshots, _26;
	zval *intermediate, *bindParams, *bindTypes, *simulate_param = NULL, *manager, *modelName = NULL, *models, *model = NULL, *connection = NULL, *connectionTypes, *columns, *column = NULL, *selectColumns, *simpleColumnMap = NULL, *metaData, *aliasCopy = NULL, *sqlColumn = NULL, *attributes = NULL, *instance = NULL, *columnMap = NULL, *attribute = NULL, *columnAlias = NULL, *sqlAlias = NULL, *dialect = NULL, *sqlSelect = NULL, *processed = NULL, *wildcard = NULL, *value = NULL, *processedTypes = NULL, *typeWildcard = NULL, *result = NULL, *resultData = NULL, *cache, *resultObject = NULL, *columns1 = NULL, **_2, *_3, *_4 = NULL, *_6 = NULL, **_9, *_10, **_13, **_19, *_21 = NULL, **_25, **_29, **_32, *_33 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &intermediate, &bindParams, &bindTypes, &simulate_param);

	ZEPHIR_SEPARATE_PARAM(intermediate);
	if (!simulate_param) {
		simulate = 0;
	} else {
		simulate = zephir_get_boolval(simulate_param);
	}


	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(connectionTypes);
	array_init(connectionTypes);
	ZEPHIR_OBS_VAR(models);
	zephir_array_fetch_string(&models, intermediate, SL("models"), PH_NOISY, "phalcon/mvc/model/query.zep", 2336 TSRMLS_CC);
	zephir_is_iterable(models, &_1, &_0, 0, 0, "phalcon/mvc/model/query.zep", 2369);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(modelName, _2);
		ZEPHIR_OBS_NVAR(model);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
		if (!(zephir_array_isset_fetch(&model, _3, modelName, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(_4);
			ZVAL_BOOL(_4, 1);
			ZEPHIR_CALL_METHOD(&model, manager, "load", &_5, 0, modelName, _4);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("_modelsInstances"), modelName, model TSRMLS_CC);
		}
		if ((zephir_method_exists_ex(model, SS("selectreadconnection") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(&connection, model, "selectreadconnection", NULL, 0, intermediate, bindParams, bindTypes);
			zephir_check_call_status();
			if (Z_TYPE_P(connection) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "'selectReadConnection' didn't return a valid connection", "phalcon/mvc/model/query.zep", 2354);
				return;
			}
		} else {
			ZEPHIR_CALL_METHOD(&connection, model, "getreadconnection", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_6, connection, "gettype", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_zval(&connectionTypes, _6, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		if (zephir_fast_count_int(connectionTypes TSRMLS_CC) == 2) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Cannot use models of different database systems in the same query", "phalcon/mvc/model/query.zep", 2365);
			return;
		}
	}
	ZEPHIR_OBS_VAR(columns);
	zephir_array_fetch_string(&columns, intermediate, SL("columns"), PH_NOISY, "phalcon/mvc/model/query.zep", 2369 TSRMLS_CC);
	haveObjects = 0;
	haveScalars = 0;
	isComplex = 0;
	numberObjects = 0;
	ZEPHIR_CPY_WRT(columns1, columns);
	zephir_is_iterable(columns, &_8, &_7, 0, 0, "phalcon/mvc/model/query.zep", 2400);
	for (
	  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
	  ; zephir_hash_move_forward_ex(_8, &_7)
	) {
		ZEPHIR_GET_HVALUE(column, _9);
		if (Z_TYPE_P(column) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid column definition", "phalcon/mvc/model/query.zep", 2384);
			return;
		}
		zephir_array_fetch_string(&_10, column, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2387 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_10, "scalar")) {
			if (!(zephir_array_isset_string(column, SS("balias")))) {
				isComplex = 1;
			}
			haveScalars = 1;
		} else {
			haveObjects = 1;
			numberObjects++;
		}
	}
	if (isComplex == 0) {
		if (haveObjects == 1) {
			if (haveScalars == 1) {
				isComplex = 1;
			} else {
				if (numberObjects == 1) {
					isSimpleStd = 0;
				} else {
					isComplex = 1;
				}
			}
		} else {
			isSimpleStd = 1;
		}
	}
	ZEPHIR_INIT_VAR(instance);
	ZVAL_NULL(instance);
	ZEPHIR_INIT_VAR(selectColumns);
	array_init(selectColumns);
	ZEPHIR_INIT_VAR(simpleColumnMap);
	array_init(simpleColumnMap);
	ZEPHIR_OBS_VAR(metaData);
	zephir_read_property_this(&metaData, this_ptr, SL("_metaData"), PH_NOISY_CC);
	zephir_is_iterable(columns, &_12, &_11, 0, 0, "phalcon/mvc/model/query.zep", 2511);
	for (
	  ; zephir_hash_get_current_data_ex(_12, (void**) &_13, &_11) == SUCCESS
	  ; zephir_hash_move_forward_ex(_12, &_11)
	) {
		ZEPHIR_GET_HMKEY(aliasCopy, _12, _11);
		ZEPHIR_GET_HVALUE(column, _13);
		ZEPHIR_OBS_NVAR(sqlColumn);
		zephir_array_fetch_string(&sqlColumn, column, SL("column"), PH_NOISY, "phalcon/mvc/model/query.zep", 2426 TSRMLS_CC);
		zephir_array_fetch_string(&_10, column, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2431 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_10, "object")) {
			ZEPHIR_OBS_NVAR(modelName);
			zephir_array_fetch_string(&modelName, column, SL("model"), PH_NOISY, "phalcon/mvc/model/query.zep", 2433 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(instance);
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
			if (!(zephir_array_isset_fetch(&instance, _3, modelName, 0 TSRMLS_CC))) {
				ZEPHIR_CALL_METHOD(&instance, manager, "load", &_14, 0, modelName);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("_modelsInstances"), modelName, instance TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&attributes, metaData, "getattributes", &_15, 0, instance);
			zephir_check_call_status();
			if (isComplex == 1) {
				if (ZEPHIR_GLOBAL(orm).column_renaming) {
					ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", &_16, 0, instance);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(columnMap);
					ZVAL_NULL(columnMap);
				}
				zephir_is_iterable(attributes, &_18, &_17, 0, 0, "phalcon/mvc/model/query.zep", 2465);
				for (
				  ; zephir_hash_get_current_data_ex(_18, (void**) &_19, &_17) == SUCCESS
				  ; zephir_hash_move_forward_ex(_18, &_17)
				) {
					ZEPHIR_GET_HVALUE(attribute, _19);
					ZEPHIR_INIT_NVAR(_20);
					zephir_create_array(_20, 3, 0 TSRMLS_CC);
					zephir_array_fast_append(_20, attribute);
					zephir_array_fast_append(_20, sqlColumn);
					ZEPHIR_INIT_LNVAR(_21);
					ZEPHIR_CONCAT_SVSV(_21, "_", sqlColumn, "_", attribute);
					zephir_array_fast_append(_20, _21);
					zephir_array_append(&selectColumns, _20, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2459);
				}
				zephir_array_update_multi(&columns1, &instance TSRMLS_CC, SL("zs"), 3, aliasCopy, SL("instance"));
				zephir_array_update_multi(&columns1, &attributes TSRMLS_CC, SL("zs"), 3, aliasCopy, SL("attributes"));
				zephir_array_update_multi(&columns1, &columnMap TSRMLS_CC, SL("zs"), 3, aliasCopy, SL("columnMap"));
				ZEPHIR_CALL_METHOD(&_6, manager, "iskeepingsnapshots", &_22, 0, instance);
				zephir_check_call_status();
				isKeepingSnapshots = zephir_get_boolval(_6);
				if (isKeepingSnapshots) {
					ZEPHIR_INIT_NVAR(_4);
					ZVAL_BOOL(_4, isKeepingSnapshots);
					zephir_array_update_multi(&columns1, &_4 TSRMLS_CC, SL("zs"), 3, aliasCopy, SL("keepSnapshots"));
				}
			} else {
				zephir_is_iterable(attributes, &_24, &_23, 0, 0, "phalcon/mvc/model/query.zep", 2485);
				for (
				  ; zephir_hash_get_current_data_ex(_24, (void**) &_25, &_23) == SUCCESS
				  ; zephir_hash_move_forward_ex(_24, &_23)
				) {
					ZEPHIR_GET_HVALUE(attribute, _25);
					ZEPHIR_INIT_NVAR(_20);
					zephir_create_array(_20, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(_20, attribute);
					zephir_array_fast_append(_20, sqlColumn);
					zephir_array_append(&selectColumns, _20, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2483);
				}
			}
		} else {
			ZEPHIR_INIT_NVAR(columnAlias);
			if (Z_TYPE_P(aliasCopy) == IS_LONG) {
				zephir_create_array(columnAlias, 2, 0 TSRMLS_CC);
				zephir_array_fast_append(columnAlias, sqlColumn);
				zephir_array_fast_append(columnAlias, ZEPHIR_GLOBAL(global_null));
			} else {
				zephir_create_array(columnAlias, 3, 0 TSRMLS_CC);
				zephir_array_fast_append(columnAlias, sqlColumn);
				zephir_array_fast_append(columnAlias, ZEPHIR_GLOBAL(global_null));
				zephir_array_fast_append(columnAlias, aliasCopy);
			}
			zephir_array_append(&selectColumns, columnAlias, PH_SEPARATE, "phalcon/mvc/model/query.zep", 2496);
		}
		_26 = isComplex == 0;
		if (_26) {
			_26 = isSimpleStd == 1;
		}
		if (_26) {
			ZEPHIR_OBS_NVAR(sqlAlias);
			if (zephir_array_isset_string_fetch(&sqlAlias, column, SS("sqlAlias"), 0 TSRMLS_CC)) {
				zephir_array_update_zval(&simpleColumnMap, sqlAlias, &aliasCopy, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&simpleColumnMap, aliasCopy, &aliasCopy, PH_COPY | PH_SEPARATE);
			}
		}
	}
	zephir_array_update_string(&intermediate, SL("columns"), &selectColumns, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&dialect, connection, "getdialect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&sqlSelect, dialect, "select", NULL, 0, intermediate);
	zephir_check_call_status();
	if (Z_TYPE_P(bindParams) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(processed);
		array_init(processed);
		zephir_is_iterable(bindParams, &_28, &_27, 0, 0, "phalcon/mvc/model/query.zep", 2531);
		for (
		  ; zephir_hash_get_current_data_ex(_28, (void**) &_29, &_27) == SUCCESS
		  ; zephir_hash_move_forward_ex(_28, &_27)
		) {
			ZEPHIR_GET_HMKEY(wildcard, _28, _27);
			ZEPHIR_GET_HVALUE(value, _29);
			if (Z_TYPE_P(wildcard) == IS_LONG) {
				ZEPHIR_INIT_LNVAR(_21);
				ZEPHIR_CONCAT_SV(_21, ":", wildcard);
				zephir_array_update_zval(&processed, _21, &value, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&processed, wildcard, &value, PH_COPY | PH_SEPARATE);
			}
		}
	} else {
		ZEPHIR_CPY_WRT(processed, bindParams);
	}
	if (Z_TYPE_P(bindTypes) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(processedTypes);
		array_init(processedTypes);
		zephir_is_iterable(bindTypes, &_31, &_30, 0, 0, "phalcon/mvc/model/query.zep", 2547);
		for (
		  ; zephir_hash_get_current_data_ex(_31, (void**) &_32, &_30) == SUCCESS
		  ; zephir_hash_move_forward_ex(_31, &_30)
		) {
			ZEPHIR_GET_HMKEY(typeWildcard, _31, _30);
			ZEPHIR_GET_HVALUE(value, _32);
			if (Z_TYPE_P(wildcard) == IS_LONG) {
				ZEPHIR_INIT_LNVAR(_33);
				ZEPHIR_CONCAT_SV(_33, ":", typeWildcard);
				zephir_array_update_zval(&processedTypes, _33, &value, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&processedTypes, typeWildcard, &value, PH_COPY | PH_SEPARATE);
			}
		}
	} else {
		ZEPHIR_CPY_WRT(processedTypes, bindTypes);
	}
	if (simulate) {
		zephir_create_array(return_value, 3, 0 TSRMLS_CC);
		zephir_array_update_string(&return_value, SL("sql"), &sqlSelect, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&return_value, SL("bind"), &processed, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&return_value, SL("bindTypes"), &processedTypes, PH_COPY | PH_SEPARATE);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&result, connection, "query", NULL, 0, sqlSelect, processed, processedTypes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, result, "numrows", NULL, 0, result);
	zephir_check_call_status();
	if (zephir_is_true(_6)) {
		ZEPHIR_CPY_WRT(resultData, result);
	} else {
		ZEPHIR_INIT_NVAR(resultData);
		ZVAL_BOOL(resultData, 0);
	}
	ZEPHIR_OBS_VAR(cache);
	zephir_read_property_this(&cache, this_ptr, SL("_cache"), PH_NOISY_CC);
	if (isComplex == 0) {
		if (isSimpleStd == 1) {
			ZEPHIR_INIT_VAR(resultObject);
			object_init_ex(resultObject, phalcon_mvc_model_row_ce);
			if (zephir_has_constructor(resultObject TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, resultObject, "__construct", NULL, 0);
				zephir_check_call_status();
			}
			isKeepingSnapshots = 0;
		} else {
			if (Z_TYPE_P(instance) == IS_OBJECT) {
				ZEPHIR_CPY_WRT(resultObject, instance);
			} else {
				ZEPHIR_CPY_WRT(resultObject, model);
			}
			ZEPHIR_CALL_METHOD(&simpleColumnMap, metaData, "getcolumnmap", NULL, 0, model);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_6, manager, "iskeepingsnapshots", NULL, 0, model);
			zephir_check_call_status();
			isKeepingSnapshots = zephir_get_boolval(_6);
		}
		object_init_ex(return_value, phalcon_mvc_model_resultset_simple_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 327, simpleColumnMap, resultObject, resultData, cache, (isKeepingSnapshots ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
		zephir_check_call_status();
		RETURN_MM();
	}
	object_init_ex(return_value, phalcon_mvc_model_resultset_complex_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 328, columns1, resultData, cache);
	zephir_check_call_status();
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

	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_12 = NULL, *_13 = NULL, *_14 = NULL;
	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool automaticFields;
	zval *intermediate, *bindParams, *bindTypes, *modelName, *manager, *connection = NULL, *metaData, *attributes = NULL, *fields = NULL, *columnMap = NULL, *dialect = NULL, *insertValues, *number = NULL, *value = NULL, *model = NULL, *values, *exprValue = NULL, *insertValue = NULL, *wildcard = NULL, *fieldName = NULL, *attributeName = NULL, *insertModel, *_0, *_1 = NULL, **_4, *_5, *_7 = NULL, _9 = zval_used_for_init, _10 = zval_used_for_init, *_11 = NULL, *_15 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &intermediate, &bindParams, &bindTypes);



	ZEPHIR_OBS_VAR(modelName);
	zephir_array_fetch_string(&modelName, intermediate, SL("model"), PH_NOISY, "phalcon/mvc/model/query.zep", 2644 TSRMLS_CC);
	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(model);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&model, _0, modelName, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_BOOL(_1, 1);
		ZEPHIR_CALL_METHOD(&model, manager, "load", NULL, 0, modelName, _1);
		zephir_check_call_status();
	}
	if ((zephir_method_exists_ex(model, SS("selectwriteconnection") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&connection, model, "selectwriteconnection", NULL, 0, intermediate, bindParams, bindTypes);
		zephir_check_call_status();
		if (Z_TYPE_P(connection) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "'selectWriteConnection' didn't return a valid connection", "phalcon/mvc/model/query.zep", 2657);
			return;
		}
	} else {
		ZEPHIR_CALL_METHOD(&connection, model, "getwriteconnection", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(metaData);
	zephir_read_property_this(&metaData, this_ptr, SL("_metaData"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&attributes, metaData, "getattributes", NULL, 0, model);
	zephir_check_call_status();
	automaticFields = 0;
	ZEPHIR_OBS_VAR(fields);
	if (!(zephir_array_isset_string_fetch(&fields, intermediate, SS("fields"), 0 TSRMLS_CC))) {
		automaticFields = 1;
		ZEPHIR_CPY_WRT(fields, attributes);
		if (ZEPHIR_GLOBAL(orm).column_renaming) {
			ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, 0, model);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(columnMap);
			ZVAL_NULL(columnMap);
		}
	}
	ZEPHIR_OBS_VAR(values);
	zephir_array_fetch_string(&values, intermediate, SL("values"), PH_NOISY, "phalcon/mvc/model/query.zep", 2680 TSRMLS_CC);
	if (zephir_fast_count_int(fields TSRMLS_CC) != zephir_fast_count_int(values TSRMLS_CC)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The column count does not match the values count", "phalcon/mvc/model/query.zep", 2686);
		return;
	}
	ZEPHIR_CALL_METHOD(&dialect, connection, "getdialect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(insertValues);
	array_init(insertValues);
	zephir_is_iterable(values, &_3, &_2, 0, 0, "phalcon/mvc/model/query.zep", 2753);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(number, _3, _2);
		ZEPHIR_GET_HVALUE(value, _4);
		ZEPHIR_OBS_NVAR(exprValue);
		zephir_array_fetch_string(&exprValue, value, SL("value"), PH_NOISY, "phalcon/mvc/model/query.zep", 2697 TSRMLS_CC);
		zephir_array_fetch_string(&_5, value, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2698 TSRMLS_CC);
		do {
			if (ZEPHIR_IS_LONG(_5, 260) || ZEPHIR_IS_LONG(_5, 258) || ZEPHIR_IS_LONG(_5, 259)) {
				ZEPHIR_CALL_METHOD(&insertValue, dialect, "getsqlexpression", &_6, 0, exprValue);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(_5, 322)) {
				ZEPHIR_INIT_NVAR(insertValue);
				ZVAL_NULL(insertValue);
				break;
			}
			if (ZEPHIR_IS_LONG(_5, 273) || ZEPHIR_IS_LONG(_5, 274)) {
				if (Z_TYPE_P(bindParams) != IS_ARRAY) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Bound parameter cannot be replaced because placeholders is not an array", "phalcon/mvc/model/query.zep", 2714);
					return;
				}
				ZEPHIR_CALL_METHOD(&_7, dialect, "getsqlexpression", &_8, 0, exprValue);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_9);
				ZVAL_STRING(&_9, ":", 0);
				ZEPHIR_SINIT_NVAR(_10);
				ZVAL_STRING(&_10, "", 0);
				ZEPHIR_INIT_NVAR(wildcard);
				zephir_fast_str_replace(&wildcard, &_9, &_10, _7 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(insertValue);
				if (!(zephir_array_isset_fetch(&insertValue, bindParams, wildcard, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(_1);
					object_init_ex(_1, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_11);
					ZEPHIR_CONCAT_SVS(_11, "Bound parameter '", wildcard, "' cannot be replaced because it isn't in the placeholders list");
					ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_12, 2, _11);
					zephir_check_call_status();
					zephir_throw_exception_debug(_1, "phalcon/mvc/model/query.zep", 2719 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				break;
			}
			ZEPHIR_INIT_NVAR(insertValue);
			object_init_ex(insertValue, phalcon_db_rawvalue_ce);
			ZEPHIR_CALL_METHOD(&_7, dialect, "getsqlexpression", &_13, 0, exprValue);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, insertValue, "__construct", &_14, 78, _7);
			zephir_check_call_status();
			break;
		} while(0);

		ZEPHIR_OBS_NVAR(fieldName);
		zephir_array_fetch(&fieldName, fields, number, PH_NOISY, "phalcon/mvc/model/query.zep", 2729 TSRMLS_CC);
		if (automaticFields == 1) {
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(attributeName);
				if (!(zephir_array_isset_fetch(&attributeName, columnMap, fieldName, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(_1);
					object_init_ex(_1, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_11);
					ZEPHIR_CONCAT_SVS(_11, "Column '", fieldName, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_12, 2, _11);
					zephir_check_call_status();
					zephir_throw_exception_debug(_1, "phalcon/mvc/model/query.zep", 2737 TSRMLS_CC);
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
	ZEPHIR_CALL_METHOD(&_7, manager, "load", NULL, 0, modelName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(insertModel);
	if (zephir_clone(insertModel, _7 TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	ZEPHIR_CALL_METHOD(&_15, insertModel, "create", NULL, 0, insertValues);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 329, _15, insertModel);
	zephir_check_call_status();
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

	zend_object_iterator *_17;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_13 = NULL, *_14 = NULL, *_15 = NULL, *_16 = NULL, *_18 = NULL;
	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *intermediate, *bindParams, *bindTypes, *models, *modelName, *model = NULL, *connection = NULL, *dialect = NULL, *fields, *values, *updateValues, *fieldName = NULL, *value = NULL, *selectBindParams = NULL, *selectBindTypes = NULL, *number = NULL, *field = NULL, *records = NULL, *exprValue = NULL, *updateValue = NULL, *wildcard = NULL, *record = NULL, *_0, *_1, **_4, *_5, *_7 = NULL, _9 = zval_used_for_init, _10 = zval_used_for_init, *_11 = NULL, *_12 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &intermediate, &bindParams, &bindTypes);



	ZEPHIR_OBS_VAR(models);
	zephir_array_fetch_string(&models, intermediate, SL("models"), PH_NOISY, "phalcon/mvc/model/query.zep", 2777 TSRMLS_CC);
	if (zephir_array_isset_long(models, 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Updating several models at the same time is still not supported", "phalcon/mvc/model/query.zep", 2780);
		return;
	}
	ZEPHIR_OBS_VAR(modelName);
	zephir_array_fetch_long(&modelName, models, 0, PH_NOISY, "phalcon/mvc/model/query.zep", 2783 TSRMLS_CC);
	ZEPHIR_OBS_VAR(model);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&model, _0, modelName, 0 TSRMLS_CC))) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_manager"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&model, _1, "load", NULL, 0, modelName);
		zephir_check_call_status();
	}
	if ((zephir_method_exists_ex(model, SS("selectwriteconnection") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&connection, model, "selectwriteconnection", NULL, 0, intermediate, bindParams, bindTypes);
		zephir_check_call_status();
		if (Z_TYPE_P(connection) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "'selectWriteConnection' didn't return a valid connection", "phalcon/mvc/model/query.zep", 2795);
			return;
		}
	} else {
		ZEPHIR_CALL_METHOD(&connection, model, "getwriteconnection", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&dialect, connection, "getdialect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(fields);
	zephir_array_fetch_string(&fields, intermediate, SL("fields"), PH_NOISY, "phalcon/mvc/model/query.zep", 2803 TSRMLS_CC);
	ZEPHIR_OBS_VAR(values);
	zephir_array_fetch_string(&values, intermediate, SL("values"), PH_NOISY, "phalcon/mvc/model/query.zep", 2804 TSRMLS_CC);
	ZEPHIR_INIT_VAR(updateValues);
	array_init(updateValues);
	ZEPHIR_CPY_WRT(selectBindParams, bindParams);
	ZEPHIR_CPY_WRT(selectBindTypes, bindTypes);
	zephir_is_iterable(fields, &_3, &_2, 0, 0, "phalcon/mvc/model/query.zep", 2867);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(number, _3, _2);
		ZEPHIR_GET_HVALUE(field, _4);
		ZEPHIR_OBS_NVAR(value);
		zephir_array_fetch(&value, values, number, PH_NOISY, "phalcon/mvc/model/query.zep", 2819 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(exprValue);
		zephir_array_fetch_string(&exprValue, value, SL("value"), PH_NOISY, "phalcon/mvc/model/query.zep", 2820 TSRMLS_CC);
		if (zephir_array_isset_string(field, SS("balias"))) {
			ZEPHIR_OBS_NVAR(fieldName);
			zephir_array_fetch_string(&fieldName, field, SL("balias"), PH_NOISY, "phalcon/mvc/model/query.zep", 2823 TSRMLS_CC);
		} else {
			ZEPHIR_OBS_NVAR(fieldName);
			zephir_array_fetch_string(&fieldName, field, SL("name"), PH_NOISY, "phalcon/mvc/model/query.zep", 2825 TSRMLS_CC);
		}
		zephir_array_fetch_string(&_5, value, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/query.zep", 2828 TSRMLS_CC);
		do {
			if (ZEPHIR_IS_LONG(_5, 260) || ZEPHIR_IS_LONG(_5, 258) || ZEPHIR_IS_LONG(_5, 259)) {
				ZEPHIR_CALL_METHOD(&updateValue, dialect, "getsqlexpression", &_6, 0, exprValue);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(_5, 322)) {
				ZEPHIR_INIT_NVAR(updateValue);
				ZVAL_NULL(updateValue);
				break;
			}
			if (ZEPHIR_IS_LONG(_5, 273) || ZEPHIR_IS_LONG(_5, 274)) {
				if (Z_TYPE_P(bindParams) != IS_ARRAY) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Bound parameter cannot be replaced because placeholders is not an array", "phalcon/mvc/model/query.zep", 2844);
					return;
				}
				ZEPHIR_CALL_METHOD(&_7, dialect, "getsqlexpression", &_8, 0, exprValue);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_9);
				ZVAL_STRING(&_9, ":", 0);
				ZEPHIR_SINIT_NVAR(_10);
				ZVAL_STRING(&_10, "", 0);
				ZEPHIR_INIT_NVAR(wildcard);
				zephir_fast_str_replace(&wildcard, &_9, &_10, _7 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(updateValue);
				if (zephir_array_isset_fetch(&updateValue, bindParams, wildcard, 0 TSRMLS_CC)) {
					zephir_array_unset(&selectBindParams, wildcard, PH_SEPARATE);
					zephir_array_unset(&selectBindTypes, wildcard, PH_SEPARATE);
				} else {
					ZEPHIR_INIT_NVAR(_11);
					object_init_ex(_11, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_12);
					ZEPHIR_CONCAT_SVS(_12, "Bound parameter '", wildcard, "' cannot be replaced because it's not in the placeholders list");
					ZEPHIR_CALL_METHOD(NULL, _11, "__construct", &_13, 2, _12);
					zephir_check_call_status();
					zephir_throw_exception_debug(_11, "phalcon/mvc/model/query.zep", 2852 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				break;
			}
			ZEPHIR_INIT_NVAR(updateValue);
			object_init_ex(updateValue, phalcon_db_rawvalue_ce);
			ZEPHIR_CALL_METHOD(&_7, dialect, "getsqlexpression", &_14, 0, exprValue);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, updateValue, "__construct", &_15, 78, _7);
			zephir_check_call_status();
			break;
		} while(0);

		zephir_array_update_zval(&updateValues, fieldName, &updateValue, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&records, this_ptr, "_getrelatedrecords", NULL, 330, model, intermediate, selectBindParams, selectBindTypes);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(records TSRMLS_CC))) {
		object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
		ZEPHIR_INIT_NVAR(_11);
		ZVAL_BOOL(_11, 1);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_16, 329, _11);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_method_exists_ex(model, SS("selectwriteconnection") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&connection, model, "selectwriteconnection", NULL, 0, intermediate, bindParams, bindTypes);
		zephir_check_call_status();
		if (Z_TYPE_P(connection) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "'selectWriteConnection' didn't return a valid connection", "phalcon/mvc/model/query.zep", 2879);
			return;
		}
	} else {
		ZEPHIR_CALL_METHOD(&connection, model, "getwriteconnection", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, connection, "begin", NULL, 0);
	zephir_check_call_status();
	_17 = zephir_get_iterator(records TSRMLS_CC);
	_17->funcs->rewind(_17 TSRMLS_CC);
	for (;_17->funcs->valid(_17 TSRMLS_CC) == SUCCESS && !EG(exception); _17->funcs->move_forward(_17 TSRMLS_CC)) {
		{
			zval **ZEPHIR_TMP_ITERATOR_PTR;
			_17->funcs->get_current_data(_17, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
			ZEPHIR_CPY_WRT(record, (*ZEPHIR_TMP_ITERATOR_PTR));
		}
		ZEPHIR_CALL_METHOD(&_7, record, "update", NULL, 0, updateValues);
		zephir_check_call_status();
		if (!(zephir_is_true(_7))) {
			ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_18, 0);
			zephir_check_call_status();
			object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
			ZEPHIR_INIT_NVAR(_11);
			ZVAL_BOOL(_11, 0);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_16, 329, _11, record);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	_17->funcs->dtor(_17 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, connection, "commit", NULL, 0);
	zephir_check_call_status();
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_BOOL(_11, 1);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_16, 329, _11);
	zephir_check_call_status();
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

	zend_object_iterator *_4;
	zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *intermediate, *bindParams, *bindTypes, *models, *modelName, *model = NULL, *records = NULL, *connection = NULL, *record = NULL, *_0, *_1, *_2 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &intermediate, &bindParams, &bindTypes);



	ZEPHIR_OBS_VAR(models);
	zephir_array_fetch_string(&models, intermediate, SL("models"), PH_NOISY, "phalcon/mvc/model/query.zep", 2926 TSRMLS_CC);
	if (zephir_array_isset_long(models, 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Delete from several models at the same time is still not supported", "phalcon/mvc/model/query.zep", 2929);
		return;
	}
	ZEPHIR_OBS_VAR(modelName);
	zephir_array_fetch_long(&modelName, models, 0, PH_NOISY, "phalcon/mvc/model/query.zep", 2932 TSRMLS_CC);
	ZEPHIR_OBS_VAR(model);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsInstances"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&model, _0, modelName, 0 TSRMLS_CC))) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_manager"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&model, _1, "load", NULL, 0, modelName);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&records, this_ptr, "_getrelatedrecords", NULL, 330, model, intermediate, bindParams, bindTypes);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(records TSRMLS_CC))) {
		object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_BOOL(_2, 1);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_3, 329, _2);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_method_exists_ex(model, SS("selectwriteconnection") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&connection, model, "selectwriteconnection", NULL, 0, intermediate, bindParams, bindTypes);
		zephir_check_call_status();
		if (Z_TYPE_P(connection) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "'selectWriteConnection' didn't return a valid connection", "phalcon/mvc/model/query.zep", 2956);
			return;
		}
	} else {
		ZEPHIR_CALL_METHOD(&connection, model, "getwriteconnection", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, connection, "begin", NULL, 0);
	zephir_check_call_status();
	_4 = zephir_get_iterator(records TSRMLS_CC);
	_4->funcs->rewind(_4 TSRMLS_CC);
	for (;_4->funcs->valid(_4 TSRMLS_CC) == SUCCESS && !EG(exception); _4->funcs->move_forward(_4 TSRMLS_CC)) {
		{
			zval **ZEPHIR_TMP_ITERATOR_PTR;
			_4->funcs->get_current_data(_4, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
			ZEPHIR_CPY_WRT(record, (*ZEPHIR_TMP_ITERATOR_PTR));
		}
		ZEPHIR_CALL_METHOD(&_5, record, "delete", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(_5))) {
			ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_6, 0);
			zephir_check_call_status();
			object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_BOOL(_2, 0);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_3, 329, _2, record);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	_4->funcs->dtor(_4 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, connection, "commit", NULL, 0);
	zephir_check_call_status();
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_BOOL(_2, 1);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_3, 329, _2);
	zephir_check_call_status();
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;
	zval *model, *intermediate, *bindParams, *bindTypes, *selectIr, *whereConditions, *limitConditions, *query, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &model, &intermediate, &bindParams, &bindTypes);



	ZEPHIR_INIT_VAR(selectIr);
	zephir_create_array(selectIr, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 3, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_1, SS("type"), SL("object"), 1);
	ZEPHIR_INIT_VAR(_2);
	zephir_get_class(_2, model, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("model"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_3, model, "getsource", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("column"), &_3, PH_COPY | PH_SEPARATE);
	zephir_array_fast_append(_0, _1);
	zephir_array_update_string(&selectIr, SL("columns"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(_4);
	zephir_array_fetch_string(&_4, intermediate, SL("models"), PH_NOISY, "phalcon/mvc/model/query.zep", 3017 TSRMLS_CC);
	zephir_array_update_string(&selectIr, SL("models"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_4);
	zephir_array_fetch_string(&_4, intermediate, SL("tables"), PH_NOISY, "phalcon/mvc/model/query.zep", 3019 TSRMLS_CC);
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
	ZEPHIR_CALL_METHOD(NULL, query, "__construct", NULL, 331);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, query, "setdi", NULL, 332, _5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 309);
	ZEPHIR_CALL_METHOD(NULL, query, "settype", NULL, 333, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, query, "setintermediate", NULL, 334, selectIr);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(query, "execute", NULL, 335, bindParams, bindTypes);
	zephir_check_call_status();
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

	zend_bool _2, _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *bindParams = NULL, *bindTypes = NULL, *uniqueRow, *cacheOptions, *key, *cacheService = NULL, *cache = NULL, *result = NULL, *preparedResult = NULL, *defaultBindParams, *mergedParams = NULL, *defaultBindTypes, *mergedTypes = NULL, *type, *lifetime = NULL, *intermediate = NULL, *_0, *_1 = NULL, *_4;

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
	if (Z_TYPE_P(cacheOptions) != IS_NULL) {
		if (Z_TYPE_P(cacheOptions) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid caching options", "phalcon/mvc/model/query.zep", 3065);
			return;
		}
		ZEPHIR_OBS_VAR(key);
		if (!(zephir_array_isset_string_fetch(&key, cacheOptions, SS("key"), 0 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A cache key must be provided to identify the cached resultset in the cache backend", "phalcon/mvc/model/query.zep", 3072);
			return;
		}
		ZEPHIR_OBS_VAR(lifetime);
		if (!(zephir_array_isset_string_fetch(&lifetime, cacheOptions, SS("lifetime"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(lifetime);
			ZVAL_LONG(lifetime, 3600);
		}
		ZEPHIR_OBS_VAR(cacheService);
		if (!(zephir_array_isset_string_fetch(&cacheService, cacheOptions, SS("service"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(cacheService);
			ZVAL_STRING(cacheService, "modelsCache", 1);
		}
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&cache, _0, "getshared", NULL, 0, cacheService);
		zephir_check_call_status();
		if (Z_TYPE_P(cache) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Cache service must be an object", "phalcon/mvc/model/query.zep", 3091);
			return;
		}
		ZEPHIR_CALL_METHOD(&result, cache, "get", NULL, 0, key, lifetime);
		zephir_check_call_status();
		if (Z_TYPE_P(result) != IS_NULL) {
			if (Z_TYPE_P(result) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Cache didn't return a valid resultset", "phalcon/mvc/model/query.zep", 3098);
				return;
			}
			ZEPHIR_INIT_VAR(_1);
			ZVAL_BOOL(_1, 0);
			ZEPHIR_CALL_METHOD(NULL, result, "setisfresh", NULL, 0, _1);
			zephir_check_call_status();
			if (zephir_is_true(uniqueRow)) {
				ZEPHIR_CALL_METHOD(&preparedResult, result, "getfirst", NULL, 0);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(preparedResult, result);
			}
			RETURN_CCTOR(preparedResult);
		}
		zephir_update_property_this(this_ptr, SL("_cache"), cache TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&intermediate, this_ptr, "parse", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(defaultBindParams);
	zephir_read_property_this(&defaultBindParams, this_ptr, SL("_bindParams"), PH_NOISY_CC);
	if (Z_TYPE_P(defaultBindParams) == IS_ARRAY) {
		if (Z_TYPE_P(bindParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(mergedParams);
			zephir_add_function_ex(mergedParams, defaultBindParams, bindParams TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedParams, defaultBindParams);
		}
	} else {
		ZEPHIR_CPY_WRT(mergedParams, bindParams);
	}
	ZEPHIR_OBS_VAR(defaultBindTypes);
	zephir_read_property_this(&defaultBindTypes, this_ptr, SL("_bindTypes"), PH_NOISY_CC);
	if (Z_TYPE_P(defaultBindTypes) == IS_ARRAY) {
		if (Z_TYPE_P(bindTypes) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(mergedTypes);
			zephir_add_function_ex(mergedTypes, defaultBindTypes, bindTypes TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedTypes, defaultBindTypes);
		}
	} else {
		ZEPHIR_CPY_WRT(mergedTypes, bindTypes);
	}
	_2 = Z_TYPE_P(mergedParams) != IS_NULL;
	if (_2) {
		_2 = Z_TYPE_P(mergedParams) != IS_ARRAY;
	}
	if (_2) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Bound parameters must be an array", "phalcon/mvc/model/query.zep", 3152);
		return;
	}
	_3 = Z_TYPE_P(mergedTypes) != IS_NULL;
	if (_3) {
		_3 = Z_TYPE_P(mergedTypes) != IS_ARRAY;
	}
	if (_3) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Bound parameter types must be an array", "phalcon/mvc/model/query.zep", 3156);
		return;
	}
	ZEPHIR_OBS_VAR(type);
	zephir_read_property_this(&type, this_ptr, SL("_type"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_LONG(type, 309)) {
			ZEPHIR_CALL_METHOD(&result, this_ptr, "_executeselect", NULL, 336, intermediate, mergedParams, mergedTypes);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_LONG(type, 306)) {
			ZEPHIR_CALL_METHOD(&result, this_ptr, "_executeinsert", NULL, 337, intermediate, mergedParams, mergedTypes);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_LONG(type, 300)) {
			ZEPHIR_CALL_METHOD(&result, this_ptr, "_executeupdate", NULL, 338, intermediate, mergedParams, mergedTypes);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_LONG(type, 303)) {
			ZEPHIR_CALL_METHOD(&result, this_ptr, "_executedelete", NULL, 339, intermediate, mergedParams, mergedTypes);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_INIT_NVAR(_1);
		object_init_ex(_1, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_SV(_4, "Unknown statement ", type);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "phalcon/mvc/model/query.zep", 3179 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	if (Z_TYPE_P(cacheOptions) != IS_NULL) {
		if (!ZEPHIR_IS_LONG(type, 309)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Only PHQL statements that return resultsets can be cached", "phalcon/mvc/model/query.zep", 3191);
			return;
		}
		ZEPHIR_CALL_METHOD(NULL, cache, "save", NULL, 0, key, result, lifetime);
		zephir_check_call_status();
	}
	if (zephir_is_true(uniqueRow)) {
		ZEPHIR_CALL_METHOD(&preparedResult, result, "getfirst", NULL, 0);
		zephir_check_call_status();
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *bindParams = NULL, *bindTypes = NULL, *_0, *_1 = NULL;

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
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, bindParams, bindTypes);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "execute", NULL, 335, bindParams, bindTypes);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_1, "getfirst", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets the type of PHQL statement to be executed
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setType) {

	zval *type_param = NULL, *_0;
	int type;

	zephir_fetch_params(0, 1, 0, &type_param);

	type = zephir_get_intval(type_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, type);
	zephir_update_property_this(this_ptr, SL("_type"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Gets the type of PHQL statement executed
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getType) {


	RETURN_MEMBER(this_ptr, "_type");

}

/**
 * Set default bind parameters
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setBindParams) {

	zval *bindParams_param = NULL;
	zval *bindParams = NULL;

	zephir_fetch_params(0, 1, 0, &bindParams_param);

	bindParams = bindParams_param;



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
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setBindTypes) {

	zval *bindTypes_param = NULL;
	zval *bindTypes = NULL;

	zephir_fetch_params(0, 1, 0, &bindTypes_param);

	bindTypes = bindTypes_param;



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
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setIntermediate) {

	zval *intermediate_param = NULL;
	zval *intermediate = NULL;

	zephir_fetch_params(0, 1, 0, &intermediate_param);

	intermediate = intermediate_param;



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

/**
 * Returns the SQL to be generated by the internal PHQL (only works in SELECT statements)
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getSql) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *intermediate = NULL, *_0, *_1, *_2, _3;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&intermediate, this_ptr, "parse", NULL, 0);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
	if (ZEPHIR_IS_LONG(_0, 309)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_bindParams"), PH_NOISY_CC);
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_bindTypes"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_BOOL(&_3, 1);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_executeselect", NULL, 336, intermediate, _1, _2, &_3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "This type of statement generates multiple SQL statements", "phalcon/mvc/model/query.zep", 3337);
	return;

}

