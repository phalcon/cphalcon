
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

extern zend_class_entry *phalcon_translate_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Translate_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapterinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapterinterface__, 0, 0, 1)
	ZEND_ARG_INFO(0, translateKey)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapterinterface_query, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapterinterface_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_translate_adapterinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Translate_AdapterInterface, __construct, arginfo_phalcon_translate_adapterinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Translate_AdapterInterface, _, arginfo_phalcon_translate_adapterinterface__)
	PHP_ABSTRACT_ME(Phalcon_Translate_AdapterInterface, query, arginfo_phalcon_translate_adapterinterface_query)
	PHP_ABSTRACT_ME(Phalcon_Translate_AdapterInterface, exists, arginfo_phalcon_translate_adapterinterface_exists)
	PHP_FE_END
};

