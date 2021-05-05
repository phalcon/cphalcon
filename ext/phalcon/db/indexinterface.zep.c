
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Interface for Phalcon\Db\Index
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_IndexInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Db, IndexInterface, phalcon, db_indexinterface, phalcon_db_indexinterface_method_entry);

	return SUCCESS;
}

/**
 * Gets the columns that corresponds the index
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_IndexInterface, getColumns);
/**
 * Gets the index name
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_IndexInterface, getName);
/**
 * Gets the index type
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_IndexInterface, getType);
