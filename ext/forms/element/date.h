
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

extern zend_class_entry *phalcon_forms_element_date_ce;

PHALCON_INIT_CLASS(Phalcon_Forms_Element_Date);

PHP_METHOD(Phalcon_Forms_Element_Date, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_date_render, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_forms_element_date_method_entry){
	PHP_ME(Phalcon_Forms_Element_Date, render, arginfo_phalcon_forms_element_date_render, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

