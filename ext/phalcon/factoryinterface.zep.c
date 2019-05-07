
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_FactoryInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon, FactoryInterface, phalcon, factoryinterface, phalcon_factoryinterface_method_entry);

	return SUCCESS;

}

/**
 * @param \Phalcon\Config|array config
 */
ZEPHIR_DOC_METHOD(Phalcon_FactoryInterface, load);

