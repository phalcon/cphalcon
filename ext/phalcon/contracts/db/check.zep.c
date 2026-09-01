
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

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
 * Canonical contract for Phalcon\Db\Check.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Db_Check)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Db, Check, phalcon, contracts_db_check, phalcon_contracts_db_check_method_entry);

	return SUCCESS;
}

/**
 * Gets the CHECK expression (the SQL boolean predicate).
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Check, getExpression);
/**
 * Gets the constraint name. An empty string indicates an unnamed CHECK
 * constraint - the dialect will emit the clause without a `CONSTRAINT`
 * prefix in that case.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Check, getName);
