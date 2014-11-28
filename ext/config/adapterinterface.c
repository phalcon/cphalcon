
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  |          Vladimir Kolesnikov <vladimir@free-sevastopol.com>            |
  +------------------------------------------------------------------------+
*/

#include "config/adapterinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_config_adapterinterface_ce;

static const zend_function_entry phalcon_config_adapterinterface_method_entry[] = {
	ZEND_FENTRY(setBasePath, NULL, arginfo_phalcon_config_adapterinterface_setbasepath, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(getBasePath, NULL, NULL, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Config\AdapterInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Config_AdapterInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Config, AdapterInterface, config_adapterinterface, phalcon_config_adapterinterface_method_entry);

	return SUCCESS;
}

/**
 * Sets base path
 *
 * @param string $basePath
 * @return Phalcon\Config\Adapter
 */
PHALCON_DOC_METHOD(Phalcon_Config_AdapterInterface, setBasePath);

/**
 * Gets base path
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Config_AdapterInterface, getBasePath);
