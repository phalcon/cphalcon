
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
 * Phalcon\Config\ConfigInterface
 *
 * Interface for Phalcon\Config class
 */
ZEPHIR_INIT_CLASS(Phalcon_Config_ConfigInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Config, ConfigInterface, phalcon, config_configinterface, phalcon_config_configinterface_method_entry);

	zend_class_implements(phalcon_config_configinterface_ce, 1, phalcon_support_collection_collectioninterface_ce);
	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Config_ConfigInterface, getPathDelimiter);
ZEPHIR_DOC_METHOD(Phalcon_Config_ConfigInterface, merge);
ZEPHIR_DOC_METHOD(Phalcon_Config_ConfigInterface, path);
ZEPHIR_DOC_METHOD(Phalcon_Config_ConfigInterface, setPathDelimiter);
