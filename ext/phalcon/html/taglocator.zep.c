
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
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Html\TagLocator
 *
 * Lazy loads, stores and exposes tag helper objects
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_TagLocator) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html, TagLocator, phalcon, html_taglocator, phalcon_service_locator_ce, NULL, 0);

	return SUCCESS;

}

