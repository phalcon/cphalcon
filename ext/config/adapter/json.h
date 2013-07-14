
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
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#ifndef PHALCON_CONFIG_ADAPTER_JSON_H
#define PHALCON_CONFIG_ADAPTER_JSON_H

extern zend_class_entry *phalcon_config_adapter_json_ce;

PHALCON_INIT_CLASS(Phalcon_Config_Adapter_Json);

PHP_METHOD(Phalcon_Config_Adapter_Json, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_adapter_json___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_config_adapter_json_method_entry){
	PHP_ME(Phalcon_Config_Adapter_Json, __construct, arginfo_phalcon_config_adapter_json___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

#endif /* PHALCON_CONFIG_ADAPTER_JSON_H */
