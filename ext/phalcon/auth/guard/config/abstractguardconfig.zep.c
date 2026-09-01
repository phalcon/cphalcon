
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_Guard_Config_AbstractGuardConfig)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth\\Guard\\Config, AbstractGuardConfig, phalcon, auth_guard_config_abstractguardconfig, NULL, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(phalcon_auth_guard_config_abstractguardconfig_ce, 1, phalcon_contracts_auth_guard_guardconfig_ce);
	return SUCCESS;
}

