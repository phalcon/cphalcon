
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

#include "mvc/view/engineinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_mvc_view_engineinterface_ce;

static const zend_function_entry phalcon_mvc_view_engineinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_EngineInterface, getContent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_EngineInterface, partial, arginfo_phalcon_mvc_view_engineinterface_partial)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_EngineInterface, render, arginfo_phalcon_mvc_view_engineinterface_render)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\View\EngineInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_View_EngineInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc\\View, EngineInterface, mvc_view_engineinterface, phalcon_mvc_view_engineinterface_method_entry);

	return SUCCESS;
}

/**
 * Returns cached ouput on another view stage
 *
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_View_EngineInterface, getContent);

/**
 * Renders a partial inside another view
 *
 * @param string $partialPath
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_View_EngineInterface, partial);

/**
 * Renders a view using the template engine
 *
 * @param string $path
 * @param array $params
 * @param boolean $mustClean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_View_EngineInterface, render);
