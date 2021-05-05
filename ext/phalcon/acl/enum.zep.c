
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Constants for Phalcon\Acl\Adapter adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_Enum)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Acl, Enum, phalcon, acl_enum, NULL, 0);

	zephir_declare_class_constant_long(phalcon_acl_enum_ce, SL("ALLOW"), 1);

	zephir_declare_class_constant_long(phalcon_acl_enum_ce, SL("DENY"), 0);

	return SUCCESS;
}

