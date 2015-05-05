
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


/**
 * Phalcon\Paginator\Adapter
 */
ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Paginator, Adapter, phalcon, paginator_adapter, phalcon_paginator_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Number of rows to show in the paginator. By default is null
	 */
	zend_declare_property_null(phalcon_paginator_adapter_ce, SL("_limitRows"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Current page in paginate
	 */
	zend_declare_property_null(phalcon_paginator_adapter_ce, SL("_page"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Set the current page number
 */
PHP_METHOD(Phalcon_Paginator_Adapter, setCurrentPage) {

	zval *page_param = NULL, *_0;
	int page;

	zephir_fetch_params(0, 1, 0, &page_param);

	page = zephir_get_intval(page_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, page);
	zephir_update_property_this(this_ptr, SL("_page"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Set current rows limit
 */
PHP_METHOD(Phalcon_Paginator_Adapter, setLimit) {

	zval *limitRows_param = NULL, *_0;
	int limitRows;

	zephir_fetch_params(0, 1, 0, &limitRows_param);

	limitRows = zephir_get_intval(limitRows_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, limitRows);
	zephir_update_property_this(this_ptr, SL("_limitRows"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Get current rows limit
 */
PHP_METHOD(Phalcon_Paginator_Adapter, getLimit) {


	RETURN_MEMBER(this_ptr, "_limitRows");

}

