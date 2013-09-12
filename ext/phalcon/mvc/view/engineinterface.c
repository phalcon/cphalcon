
#ifdef HAVE_CONFIG_H
#include "ext_config.h"
#endif

#include "php.h"
#include "../php_ext.h"
#include "../ext.h"

#include "kernel/main.h"


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
/**
 * Phalcon\Mvc\View\EngineInterface
 *
 * Interface for Phalcon\Mvc\View engine adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_EngineInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\View, EngineInterface, phalcon, mvc_view_engineinterface, phalcon_mvc_view_engineinterface_method_entry);


	return SUCCESS;

}

/**
 * Phalcon\Mvc\View\Engine constructor
 *
 * @param Phalcon\Mvc\ViewInterface view
 * @param Phalcon\DiInterface dependencyInjector
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_View_EngineInterface, __construct);

/**
 * Returns cached ouput on another view stage
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_View_EngineInterface, getContent);

/**
 * Renders a partial inside another view
 *
 * @param string partialPath
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_View_EngineInterface, partial);

/**
 * Renders a view using the template engine
 *
 * @param string path
 * @param array params
 * @param boolean mustClean
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_View_EngineInterface, render);

