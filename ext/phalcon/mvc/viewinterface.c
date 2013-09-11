
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

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
 * Phalcon\Mvc\ViewInterface
 *
 * Interface for Phalcon\Mvc\View
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_ViewInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc, ViewInterface, phalcon, mvc_viewinterface, phalcon_mvc_viewinterface_method_entry);


	return SUCCESS;

}

/**
 * Sets views directory. Depending of your platform, always add a trailing slash or backslash
 *
 * @param string viewsDir
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, setViewsDir);

/**
 * Gets views directory
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, getViewsDir);

/**
 * Sets the layouts sub-directory. Must be a directory under the views directory. Depending of your platform, always add a trailing slash or backslash
 *
 * @param string layoutsDir
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, setLayoutsDir);

/**
 * Gets the current layouts sub-directory
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, getLayoutsDir);

/**
 * Sets a partials sub-directory. Must be a directory under the views directory. Depending of your platform, always add a trailing slash or backslash
 *
 * @param string partialsDir
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, setPartialsDir);

/**
 * Gets the current partials sub-directory
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, getPartialsDir);

/**
 * Sets base path. Depending of your platform, always add a trailing slash or backslash
 *
 * @param string basePath
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, setBasePath);

/**
 * Sets the render level for the view
 *
 * @param string level
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, setRenderLevel);

/**
 * Sets default view name. Must be a file without extension in the views directory
 *
 * @param string viewPath
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, setMainView);

/**
 * Returns the name of the main view
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, getMainView);

/**
 * Change the layout to be used instead of using the name of the latest controller name
 *
 * @param string layout
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, setLayout);

/**
 * Returns the name of the main view
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, getLayout);

/**
 * Appends template before controller layout
 *
 * @param string|array templateBefore
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, setTemplateBefore);

/**
 * Resets any template before layouts
 *
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, cleanTemplateBefore);

/**
 * Appends template after controller layout
 *
 * @param string|array templateAfter
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, setTemplateAfter);

/**
 * Resets any template before layouts
 *
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, cleanTemplateAfter);

/**
 * Adds parameters to views (alias of setVar)
 *
 * @param string key
 * @param mixed value
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, setParamToView);

/**
 * Adds parameters to views
 *
 * @param string key
 * @param mixed value
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, setVar);

/**
 * Returns parameters to views
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, getParamsToView);

/**
 * Gets the name of the controller rendered
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, getControllerName);

/**
 * Gets the name of the action rendered
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, getActionName);

/**
 * Gets extra parameters of the action rendered
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, getParams);

/**
 * Starts rendering process enabling the output buffering
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, start);

/**
 * Register templating engines
 *
 * @param array engines
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, registerEngines);

/**
 * Executes render process from dispatching data
 *
 * @param string controllerName
 * @param string actionName
 * @param array params
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, render);

/**
 * Choose a view different to render than last-controller/last-action
 *
 * @param string renderView
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, pick);

/**
 * Renders a partial view
 *
 * @param string partialPath
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, partial);

/**
 * Finishes the render process by stopping the output buffering
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, finish);

/**
 * Returns the cache instance used to cache
 *
 * @return Phalcon\Cache\BackendInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, getCache);

/**
 * Cache the actual view render to certain level
 *
 * @param boolean|array options
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, cache);

/**
 * Externally sets the view content
 *
 * @param string content
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, setContent);

/**
 * Returns cached ouput from another view stage
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, getContent);

/**
 * Returns the path of the view that is currently rendered
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, getActiveRenderPath);

/**
 * Disables the auto-rendering process
 *
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, disable);

/**
 * Enables the auto-rendering process
 *
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, enable);

/**
 * Resets the view component to its factory default values
 *
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, reset);

