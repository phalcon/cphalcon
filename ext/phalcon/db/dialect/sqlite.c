
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


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
 |          Rack Lin <racklin@gmail.com>                                  |
 |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Db\Dialect\Sqlite
 *
 * Generates database specific SQL for the Sqlite RBDM
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect_Sqlite) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Dialect, Sqlite, phalcon, db_dialect_sqlite, phalcon_db_dialect_ce, NULL, 0);

	zend_declare_property_null(phalcon_db_dialect_sqlite_ce, SL("_escapeChar"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_class_implements(phalcon_db_dialect_sqlite_ce TSRMLS_CC, 1, phalcon_db_dialectinterface_ce);

	return SUCCESS;

}

