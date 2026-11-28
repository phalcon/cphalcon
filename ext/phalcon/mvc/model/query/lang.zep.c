
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "phalcon/mvc/model/query/scanner.h"
#include "phalcon/mvc/model/query/phql.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\Query\Lang
 *
 * PHQL is implemented as a parser (written in C) that translates syntax in
 * that of the target RDBMS. It allows Phalcon to offer a unified SQL language to
 * the developer, while internally doing all the work of translating PHQL
 * instructions to the most optimal SQL instructions depending on the
 * RDBMS type associated with a model.
 *
 * To achieve the highest performance possible, we wrote a parser that uses
 * the same technology as SQLite. This technology provides a small in-memory
 * parser with a very low memory footprint that is also thread-safe.
 *
 * ```php
 * use Phalcon\Mvc\Model\Query\Lang;
 *
 * $intermediate = Lang::parsePHQL(
 *     "SELECT r.* FROM Invoices r LIMIT 10"
 * );
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query_Lang)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Query, Lang, phalcon, mvc_model_query_lang, phalcon_mvc_model_query_lang_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;
}

/**
 * Parses a PHQL statement returning an intermediate representation (IR)
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Lang, parsePHQL)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval phql_zv, _0, _1, _2;
	zend_string *phql = NULL;

	ZVAL_UNDEF(&phql_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(phql)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&phql_zv);
	ZVAL_STR_COPY(&phql_zv, phql);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "orm.enable_literals");
	ZEPHIR_CALL_CE_STATIC_CACHED(&_0, phalcon_support_settings_ce, "get", &_zephir_call_cache[0], &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "orm.cache_level");
	ZEPHIR_CALL_CE_STATIC_CACHED(&_2, phalcon_support_settings_ce, "get", &_zephir_call_cache[1], &_1);
	zephir_check_call_status();
	ZEPHIR_LAST_CALL_STATUS = phql_parse_phql(return_value, &phql_zv, &_0, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

