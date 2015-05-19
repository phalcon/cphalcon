
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/math.h"


/**
 * Phalcon\Paginator\Adapter\QueryBuilder
 *
 * Pagination using a PHQL query builder as source of data
 *
 *<code>
 *  $builder = $this->modelsManager->createBuilder()
 *                   ->columns('id, name')
 *                   ->from('Robots')
 *                   ->orderBy('name');
 *
 *  $paginator = new Phalcon\Paginator\Adapter\QueryBuilder(array(
 *      "builder" => $builder,
 *      "limit"=> 20,
 *      "page" => 1
 *  ));
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter_QueryBuilder) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Paginator\\Adapter, QueryBuilder, phalcon, paginator_adapter_querybuilder, phalcon_paginator_adapter_ce, phalcon_paginator_adapter_querybuilder_method_entry, 0);

	/**
	 * Configuration of paginator by model
	 */
	zend_declare_property_null(phalcon_paginator_adapter_querybuilder_ce, SL("_config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Paginator's data
	 */
	zend_declare_property_null(phalcon_paginator_adapter_querybuilder_ce, SL("_builder"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_paginator_adapter_querybuilder_ce TSRMLS_CC, 1, phalcon_paginator_adapterinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Paginator\Adapter\QueryBuilder
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *config_param = NULL, *builder, *limit, *page;
	zval *config = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config_param);

	zephir_get_arrval(config, config_param);


	zephir_update_property_this(this_ptr, SL("_config"), config TSRMLS_CC);
	ZEPHIR_OBS_VAR(builder);
	if (!(zephir_array_isset_string_fetch(&builder, config, SS("builder"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "Parameter 'builder' is required", "phalcon/paginator/adapter/querybuilder.zep", 67);
		return;
	}
	ZEPHIR_OBS_VAR(limit);
	if (!(zephir_array_isset_string_fetch(&limit, config, SS("limit"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "Parameter 'limit' is required", "phalcon/paginator/adapter/querybuilder.zep", 71);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setquerybuilder", NULL, 0, builder);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setlimit", NULL, 0, limit);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(page);
	if (zephir_array_isset_string_fetch(&page, config, SS("page"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcurrentpage", NULL, 0, page);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the current page number
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getCurrentPage) {


	RETURN_MEMBER(this_ptr, "_page");

}

/**
 * Set query builder object
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, setQueryBuilder) {

	zval *builder;

	zephir_fetch_params(0, 1, 0, &builder);



	zephir_update_property_this(this_ptr, SL("_builder"), builder TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Get query builder object
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getQueryBuilder) {


	RETURN_MEMBER(this_ptr, "_builder");

}

/**
 * Returns a slice of the resultset to show in the pagination
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getPaginate) {

	int numberPage, before, ZEPHIR_LAST_CALL_STATUS;
	zval *originalBuilder, *builder, *totalBuilder, *totalPages, *limit, *number, *query = NULL, *page, *items = NULL, *totalQuery = NULL, *result = NULL, *row = NULL, *rowcount, *next = NULL, *_0, *_1 = NULL, *_2, _3, _4, *_5;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(originalBuilder);
	zephir_read_property_this(&originalBuilder, this_ptr, SL("_builder"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(builder);
	if (zephir_clone(builder, originalBuilder TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(totalBuilder);
	if (zephir_clone(totalBuilder, builder TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(limit);
	zephir_read_property_this(&limit, this_ptr, SL("_limitRows"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_page"), PH_NOISY_CC);
	numberPage = zephir_get_intval(_0);
	if (!(numberPage)) {
		numberPage = 1;
	}
	ZEPHIR_INIT_VAR(number);
	ZVAL_LONG(number, (zephir_get_numberval(limit) * ((numberPage - 1))));
	if (ZEPHIR_LT(number, limit)) {
		ZEPHIR_CALL_METHOD(NULL, builder, "limit", NULL, 0, limit);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, builder, "limit", NULL, 0, limit, number);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&query, builder, "getquery", NULL, 0);
	zephir_check_call_status();
	if (numberPage == 1) {
		before = 1;
	} else {
		before = (numberPage - 1);
	}
	ZEPHIR_CALL_METHOD(&items, query, "execute", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "COUNT(*) [rowcount]", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, totalBuilder, "columns", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_NULL(_1);
	ZEPHIR_CALL_METHOD(NULL, totalBuilder, "orderby", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&totalQuery, totalBuilder, "getquery", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, totalQuery, "execute", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&row, result, "getfirst", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, row, SL("rowcount"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(rowcount);
	ZVAL_LONG(rowcount, zephir_get_intval(_2));
	ZEPHIR_SINIT_VAR(_3);
	div_function(&_3, rowcount, limit TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_DOUBLE(&_4, zephir_ceil(&_3 TSRMLS_CC));
	ZEPHIR_INIT_VAR(totalPages);
	ZVAL_LONG(totalPages, zephir_get_intval(&_4));
	if (ZEPHIR_GT_LONG(totalPages, numberPage)) {
		ZEPHIR_INIT_VAR(next);
		ZVAL_LONG(next, (numberPage + 1));
	} else {
		ZEPHIR_CPY_WRT(next, totalPages);
	}
	ZEPHIR_INIT_VAR(page);
	object_init(page);
	zephir_update_property_zval(page, SL("items"), items TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_5);
	ZVAL_LONG(_5, 1);
	zephir_update_property_zval(page, SL("first"), _5 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_5);
	ZVAL_LONG(_5, before);
	zephir_update_property_zval(page, SL("before"), _5 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_5);
	ZVAL_LONG(_5, numberPage);
	zephir_update_property_zval(page, SL("current"), _5 TSRMLS_CC);
	zephir_update_property_zval(page, SL("last"), totalPages TSRMLS_CC);
	zephir_update_property_zval(page, SL("next"), next TSRMLS_CC);
	zephir_update_property_zval(page, SL("total_pages"), totalPages TSRMLS_CC);
	zephir_update_property_zval(page, SL("total_items"), rowcount TSRMLS_CC);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_limitRows"), PH_NOISY_CC);
	zephir_update_property_zval(page, SL("limit"), _5 TSRMLS_CC);
	RETURN_CCTOR(page);

}

