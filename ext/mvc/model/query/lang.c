
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

#include "mvc/model/query/lang.h"
#include "mvc/model/query/scanner.h"
#include "mvc/model/query/phql.h"
#include "mvc/model/exception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"

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
zend_class_entry *phalcon_mvc_model_query_lang_ce;

PHP_METHOD(Phalcon_Mvc_Model_Query_Lang, parsePHQL);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_lang_parsephql, 0, 0, 1)
	ZEND_ARG_INFO(0, phql)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_model_query_lang_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_Query_Lang, parsePHQL, arginfo_phalcon_mvc_model_query_lang_parsephql, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\Query\Lang initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Query_Lang){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Query, Lang, mvc_model_query_lang, phalcon_mvc_model_query_lang_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;
}

/**
 * Parses a PHQL statement returning an intermediate representation (IR)
 *
 * @param string $phql
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Lang, parsePHQL){

	zval *phql;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &phql);
	
	if (Z_TYPE_P(phql) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "PHQL statement must be string");
		return;
	}
	if (phql_parse_phql(return_value, phql TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	RETURN_MM();
}

