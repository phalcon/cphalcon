
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
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "phalcon/mvc/model/query/scanner.h"
#include "phalcon/mvc/model/query/phql.h"


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
 * <code>
 * $intermediate = Phalcon\Mvc\Model\Query\Lang::parsePHQL("SELECT r.* FROM Robots r LIMIT 10");
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query_Lang) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Query, Lang, phalcon, mvc_model_query_lang, phalcon_mvc_model_query_lang_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * Parses a PHQL statement returning an intermediate representation (IR)
 *
 * @param string phql
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Lang, parsePHQL) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *phql_param = NULL;
	zval *phql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &phql_param);

	if (unlikely(Z_TYPE_P(phql_param) != IS_STRING && Z_TYPE_P(phql_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'phql' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(phql_param) == IS_STRING)) {
		zephir_get_strval(phql, phql_param);
	} else {
		ZEPHIR_INIT_VAR(phql);
		ZVAL_EMPTY_STRING(phql);
	}


	ZEPHIR_LAST_CALL_STATUS = phql_parse_phql(return_value, phql TSRMLS_CC);
	zephir_check_call_status();
	RETURN_MM();

}

