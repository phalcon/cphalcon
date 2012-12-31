
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
  +------------------------------------------------------------------------+
*/

extern zend_class_entry *phalcon_di_service_builder_ce;

PHALCON_INIT_CLASS(Phalcon_DI_Service_Builder);

PHP_METHOD(Phalcon_DI_Service_Builder, _buildParameter);
PHP_METHOD(Phalcon_DI_Service_Builder, _buildParameters);
PHP_METHOD(Phalcon_DI_Service_Builder, build);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_builder_build, 0, 0, 2)
	ZEND_ARG_INFO(0, dependencyInjector)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_di_service_builder_method_entry){
	PHP_ME(Phalcon_DI_Service_Builder, _buildParameter, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_DI_Service_Builder, _buildParameters, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_DI_Service_Builder, build, arginfo_phalcon_di_service_builder_build, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

