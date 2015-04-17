
<<<<<<< HEAD:ext/phalcon/mvc/view/engine/volt.zep.h
extern zend_class_entry *phalcon_mvc_view_engine_volt_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt);

PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, setOptions);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, getOptions);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, getCompiler);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, render);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, length);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, isIncluded);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, convertEncoding);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, slice);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, sort);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_setoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_render, 0, 0, 2)
	ZEND_ARG_INFO(0, templatePath)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, mustClean)
ZEND_END_ARG_INFO()
=======
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
  +------------------------------------------------------------------------+
*/

#ifndef PHALCON_MVC_VIEW_ENGINE_VOLT_H
#define PHALCON_MVC_VIEW_ENGINE_VOLT_H
>>>>>>> master:ext/mvc/view/engine/volt.h

#include "php_phalcon.h"

extern zend_class_entry *phalcon_mvc_view_engine_volt_ce;

<<<<<<< HEAD:ext/phalcon/mvc/view/engine/volt.zep.h
ZEPHIR_INIT_FUNCS(phalcon_mvc_view_engine_volt_method_entry) {
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, setOptions, arginfo_phalcon_mvc_view_engine_volt_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, getCompiler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, render, arginfo_phalcon_mvc_view_engine_volt_render, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, length, arginfo_phalcon_mvc_view_engine_volt_length, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, isIncluded, arginfo_phalcon_mvc_view_engine_volt_isincluded, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, convertEncoding, arginfo_phalcon_mvc_view_engine_volt_convertencoding, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, slice, arginfo_phalcon_mvc_view_engine_volt_slice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, sort, arginfo_phalcon_mvc_view_engine_volt_sort, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
=======
PHALCON_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt);

#endif /* PHALCON_MVC_VIEW_ENGINE_VOLT_H */
>>>>>>> master:ext/mvc/view/engine/volt.h
