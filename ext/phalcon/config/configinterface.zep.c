
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
 * Interface for Phalcon\Config\Config class
 */
ZEPHIR_INIT_CLASS(Phalcon_Config_ConfigInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Config, ConfigInterface, phalcon, config_configinterface, phalcon_config_configinterface_method_entry);

	zend_class_implements(phalcon_config_configinterface_ce, 1, phalcon_support_collection_collectioninterface_ce);
	return SUCCESS;
}

/**
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Config_ConfigInterface, getPathDelimiter);
/**
 * @param array|ConfigInterface $toMerge
 *
 * @return ConfigInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Config_ConfigInterface, merge);
/**
 * @param string      $path
 * @param mixed|null  $defaultValue
 * @param string|null $delimiter
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Config_ConfigInterface, path);
/**
 * @param string|null $delimiter
 *
 * @return ConfigInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Config_ConfigInterface, setPathDelimiter);
