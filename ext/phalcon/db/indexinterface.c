
#ifdef HAVE_CONFIG_H
#include "ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

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
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Db\IndexInterface
 *
 * Interface for Phalcon\Db\Index
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_IndexInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Db, IndexInterface, phalcon, db_indexinterface, phalcon_db_indexinterface_method_entry);


	return SUCCESS;

}

/**
 * Phalcon\Db\Index constructor
 *
 * @param string indexName
 * @param array columns
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_IndexInterface, __construct);

/**
 * Gets the index name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_IndexInterface, getName);

/**
 * Gets the columns that comprends the index
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_IndexInterface, getColumns);

/**
 * Restore a Phalcon\Db\Index object from export
 *
 * @param array data
 * @return Phalcon\Db\IndexInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_IndexInterface, __set_state);

