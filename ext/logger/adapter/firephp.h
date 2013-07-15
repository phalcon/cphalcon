
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

#ifndef PHALCON_LOGGER_ADAPTER_FIREPHP_H
#define PHALCON_LOGGER_ADAPTER_FIREPHP_H

extern zend_class_entry *phalcon_logger_adapter_firephp_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_Adapter_Firephp);

PHP_METHOD(Phalcon_Logger_Adapter_Firephp, getFormatter);
PHP_METHOD(Phalcon_Logger_Adapter_Firephp, logInternal);
PHP_METHOD(Phalcon_Logger_Adapter_Firephp, close);

PHALCON_INIT_FUNCS(phalcon_logger_adapter_firephp_method_entry){
	PHP_ME(Phalcon_Logger_Adapter_Firephp, getFormatter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_Firephp, logInternal, arginfo_phalcon_logger_adapter_file_loginternal, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_Firephp, close, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

#endif /* PHALCON_LOGGER_ADAPTER_FIREPHP_H */
