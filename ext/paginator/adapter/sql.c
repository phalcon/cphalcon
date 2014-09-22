
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

#include "paginator/adapter/sql.h"
#include "paginator/adapterinterface.h"
#include "paginator/exception.h"
#include "db/adapterinterface.h"

#include "ext/pdo/php_pdo_driver.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"

#include "internal/arginfo.h"

/**
 * Phalcon\Paginator\Adapter\Sql
 *
 * Pagination using a SQL as source of data
 *
 */
zend_class_entry *phalcon_paginator_adapter_sql_ce;

PHP_METHOD(Phalcon_Paginator_Adapter_Sql, __construct);
PHP_METHOD(Phalcon_Paginator_Adapter_Sql, getPaginate);
PHP_METHOD(Phalcon_Paginator_Adapter_Sql, setCurrentPage);
PHP_METHOD(Phalcon_Paginator_Adapter_Sql, getCurrentPage);
PHP_METHOD(Phalcon_Paginator_Adapter_Sql, setLimit);
PHP_METHOD(Phalcon_Paginator_Adapter_Sql, getLimit);
PHP_METHOD(Phalcon_Paginator_Adapter_Sql, setDb);
PHP_METHOD(Phalcon_Paginator_Adapter_Sql, getDb);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_sql___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_sql_setlimit, 0, 0, 1)
	ZEND_ARG_INFO(0, limit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_sql_setdb, 0, 0, 1)
	ZEND_ARG_INFO(0, db)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_paginator_adapter_sql_method_entry[] = {
	PHP_ME(Phalcon_Paginator_Adapter_Sql, __construct, arginfo_phalcon_paginator_adapter_sql___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Paginator_Adapter_Sql, getPaginate, arginfo_phalcon_paginator_adapterinterface_getpaginate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_Sql, setLimit, arginfo_phalcon_paginator_adapter_sql_setlimit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_Sql, getLimit, arginfo_empty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_Sql, setCurrentPage, arginfo_phalcon_paginator_adapterinterface_setcurrentpage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_Sql, getCurrentPage, arginfo_phalcon_paginator_adapterinterface_getcurrentpage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_Sql, setDb, arginfo_phalcon_paginator_adapter_sql_setdb, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_Sql, getDb, arginfo_empty, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Paginator\Adapter\Sql initializer
 */
PHALCON_INIT_CLASS(Phalcon_Paginator_Adapter_Sql){

	PHALCON_REGISTER_CLASS(Phalcon\\Paginator\\Adapter, Sql, paginator_adapter_sql, phalcon_paginator_adapter_sql_method_entry, 0);

	zend_declare_property_null(phalcon_paginator_adapter_sql_ce, SL("_db"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_sql_ce, SL("_sql"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_sql_ce, SL("_total_sql"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_sql_ce, SL("_bind"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_sql_ce, SL("_limitRows"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_paginator_adapter_sql_ce, SL("_page"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_paginator_adapter_sql_ce TSRMLS_CC, 1, phalcon_paginator_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Paginator\Adapter\Sql
 *
 * @param array $config
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Sql, __construct){

	zval *config, *db, *sql, *total_sql, *bind, *limit, *page;
	long int i_limit;

	phalcon_fetch_params(0, 1, 0, &config);
	
	if (!phalcon_array_isset_string_fetch(&db, config, SS("db"))) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_paginator_exception_ce, "Parameter 'db' is required");
		return;
	}
	
	if (!phalcon_array_isset_string_fetch(&sql, config, SS("sql"))) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_paginator_exception_ce, "Parameter 'sql' is required");
		return;
	}
	
	if (!phalcon_array_isset_string_fetch(&total_sql, config, SS("total_sql"))) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_paginator_exception_ce, "Parameter 'sql' is required");
		return;
	}

	if (phalcon_array_isset_string_fetch(&bind, config, SS("bind"))) {
		if (Z_TYPE_P(bind) != IS_ARRAY) {
			phalcon_update_property_empty_array(this_ptr, SL("_bind") TSRMLS_CC);
		} else {
			phalcon_update_property_this(this_ptr, SL("_bind"), bind TSRMLS_CC);
		}
	} else {
		phalcon_update_property_empty_array(this_ptr, SL("_bind") TSRMLS_CC);
	}

	PHALCON_VERIFY_INTERFACE_EX(db, phalcon_db_adapterinterface_ce, phalcon_paginator_exception_ce, 0);

	phalcon_update_property_this(this_ptr, SL("_db"), db TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_sql"), sql TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_total_sql"), total_sql TSRMLS_CC);

	if (!phalcon_array_isset_string_fetch(&limit, config, SS("limit"))) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_paginator_exception_ce, "Parameter 'limit' is required");
		return;
	}

	i_limit = phalcon_get_intval(limit);
	if (i_limit < 1) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_paginator_exception_ce, "'limit' should be positive");
		return;
	}

	phalcon_update_property_this(this_ptr, SL("_limitRows"), limit TSRMLS_CC);
	
	if (phalcon_array_isset_string_fetch(&page, config, SS("page"))) {
		phalcon_update_property_this(this_ptr, SL("_page"), page TSRMLS_CC);
	}
}

/**
 * Set current page number
 *
 * @param int $page
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Sql, setCurrentPage){

	zval **current_page;

	phalcon_fetch_params_ex(1, 0, &current_page);
	PHALCON_ENSURE_IS_LONG(current_page);
	
	phalcon_update_property_this(this_ptr, SL("_page"), *current_page TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Get current page number
 *
 * @param int $page
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Sql, getCurrentPage){

	RETURN_MEMBER(this_ptr, "_page");
}

/**
 * Set current rows limit
 *
 * @param int $limit
 *
 * @return Phalcon\Paginator\Adapter\Sql $this Fluent interface
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Sql, setLimit){

	zval **current_limit;

	phalcon_fetch_params_ex(1, 0, &current_limit);
	PHALCON_ENSURE_IS_LONG(current_limit);

	phalcon_update_property_this(this_ptr, SL("_limitRows"), *current_limit TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Get current rows limit
 *
 * @return int $limit
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Sql, getLimit){

	RETURN_MEMBER(this_ptr, "_limitRows");
}

/**
 * Set query builder object
 *
 * @param Phalcon\Db\AdapterInterface $db
 *
 * @return Phalcon\Paginator\Adapter\Sql $this Fluent interface
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Sql, setDb){

	zval *db;

	phalcon_fetch_params(0, 1, 0, &db);
	PHALCON_VERIFY_INTERFACE_EX(db, phalcon_db_adapterinterface_ce, phalcon_paginator_exception_ce, 0);

	phalcon_update_property_this(this_ptr, SL("_db"), db TSRMLS_CC);

	RETURN_THISW();
}

/**
 * Get query builder object
 *
 * @return Phalcon\Db\AdapterInterface $db
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Sql, getDb){

	RETURN_MEMBER(this_ptr, "_db");
}

/**
 * Returns a slice of the resultset to show in the pagination
 *
 * @return stdClass
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Sql, getPaginate){

	zval *db, *sql, *total_sql, *bind;
	zval *limit, *number_page;
	zval *fetch_mode, *items = NULL;
	zval *row = NULL, *rowcount;
	long int i_limit, i_number_page, i_number, i_before, i_rowcount;
	long int i_total_pages, i_next;
	ldiv_t tp;

	PHALCON_MM_GROW();

	db = phalcon_fetch_nproperty_this(this_ptr, SL("_db"), PH_NOISY TSRMLS_CC);
	sql = phalcon_fetch_nproperty_this(this_ptr, SL("_sql"), PH_NOISY TSRMLS_CC);
	total_sql = phalcon_fetch_nproperty_this(this_ptr, SL("_total_sql"), PH_NOISY TSRMLS_CC);
	bind = phalcon_fetch_nproperty_this(this_ptr, SL("_bind"), PH_NOISY TSRMLS_CC);

	limit         = phalcon_fetch_nproperty_this(this_ptr, SL("_limitRows"), PH_NOISY TSRMLS_CC);
	number_page   = phalcon_fetch_nproperty_this(this_ptr, SL("_page"), PH_NOISY TSRMLS_CC);
	i_limit       = phalcon_get_intval(limit);
	i_number_page = phalcon_get_intval(number_page);

	if (i_limit < 1) {
		/* This should never happen unless someone deliberately modified the properties of the object */
		i_limit = 10;
	}

	if (!i_number_page) {
		i_number_page = 1;
	}

	i_number = (i_number_page - 1) * i_limit;
	i_before = (i_number_page == 1) ? 1 : (i_number_page - 1);

	PHALCON_INIT_VAR(fetch_mode);
	ZVAL_LONG(fetch_mode, PDO_FETCH_OBJ);

	PHALCON_CALL_METHOD(&row, db, "fetchone", total_sql, fetch_mode, bind);
	
	PHALCON_OBS_VAR(rowcount);
	phalcon_read_property(&rowcount, row, SL("rowcount"), PH_NOISY TSRMLS_CC);

	/* Set the limit clause avoiding negative offsets */
	if (i_number < i_limit) {
		phalcon_array_update_string(&bind, SL("limit"), limit, PH_COPY);
		phalcon_array_update_string_long(&bind, SL("offset"), 0, 0);
	} else {
		zval *number;
		PHALCON_ALLOC_GHOST_ZVAL(number);
		ZVAL_LONG(number, i_number);
		phalcon_array_update_string(&bind, SL("limit"), limit, PH_COPY);
		phalcon_array_update_string(&bind, SL("offset"), number, PH_COPY);
	}

	PHALCON_CALL_METHOD(&items, db, "fetchall", sql, fetch_mode, bind);
	
	i_rowcount    = phalcon_get_intval(rowcount);
	tp            = ldiv(i_rowcount, i_limit);
	i_total_pages = tp.quot + (tp.rem ? 1 : 0);
	i_next        = (i_number_page < i_total_pages) ? (i_number_page + 1) : i_total_pages;

	object_init(return_value);
	phalcon_update_property_zval(return_value, SL("items"),       items TSRMLS_CC);
	phalcon_update_property_long(return_value, SL("before"),      i_before TSRMLS_CC);
	phalcon_update_property_long(return_value, SL("first"),       1 TSRMLS_CC);
	phalcon_update_property_long(return_value, SL("next"),        i_next TSRMLS_CC);
	phalcon_update_property_long(return_value, SL("last"),        i_total_pages TSRMLS_CC);
	phalcon_update_property_long(return_value, SL("current"),     i_number_page TSRMLS_CC);
	phalcon_update_property_long(return_value, SL("total_pages"), i_total_pages TSRMLS_CC);
	phalcon_update_property_long(return_value, SL("total_items"), i_rowcount TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}
