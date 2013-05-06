
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
  +------------------------------------------------------------------------+
*/

extern zend_class_entry *phalcon_assets_resource_css_ce;

PHALCON_INIT_CLASS(Phalcon_Assets_Resource_Css);

PHP_METHOD(Phalcon_Assets_Resource_Css, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_css___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_assets_resource_css_method_entry){
	PHP_ME(Phalcon_Assets_Resource_Css, __construct, arginfo_phalcon_assets_resource_css___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_FE_END
};

