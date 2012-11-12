
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"

/**
 * Phalcon\Mvc\ViewInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_ViewInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc, ViewInterface, mvc_viewinterface, phalcon_mvc_viewinterface_method_entry);

	return SUCCESS;
}

/**
 * Sets views directory. Depending of your platform, always add a trailing slash or backslash
 *
 * @param string $viewsDir
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, setViewsDir);

/**
 * Gets views directory
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, getViewsDir);

/**
 * Sets base path. Depending of your platform, always add a trailing slash or backslash
 *
 * @param string $basePath
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, setBasePath);

/**
 * Sets the render level for the view
 *
 * @param string $level
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, setRenderLevel);

/**
 * Sets default view name. Must be a file without extension in the views directory
 *
 * @param string $name
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, setMainView);

/**
 * Appends template before controller layout
 *
 * @param string|array $templateBefore
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, setTemplateBefore);

/**
 * Resets any template before layouts
 *
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, cleanTemplateBefore);

/**
 * Appends template after controller layout
 *
 * @param string|array $templateAfter
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, setTemplateAfter);

/**
 * Resets any template before layouts
 *
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, cleanTemplateAfter);

/**
 * Adds parameters to views (alias of setVar)
 *
 * @param string $key
 * @param mixed $value
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, setParamToView);

/**
 * Adds parameters to views
 *
 * @param string $key
 * @param mixed $value
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, setVar);

/**
 * Returns parameters to views
 *
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, getParamsToView);

/**
 * Gets the name of the controller rendered
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, getControllerName);

/**
 * Gets the name of the action rendered
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, getActionName);

/**
 * Gets extra parameters of the action rendered
 *
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, getParams);

/**
 * Starts rendering process enabling the output buffering
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, start);

/**
 * Register templating engines
 *
 * @param array $engines
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, registerEngines);

/**
 * Executes render process from dispatching data
 *
 * @param string $controllerName
 * @param string $actionName
 * @param array $params
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, render);

/**
 * Choose a view different to render than last-controller/last-action
 *
 * @param string $renderView
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, pick);

/**
 * Renders a partial view
 *
 * @param string $partialPath
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, partial);

/**
 * Finishes the render process by stopping the output buffering
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, finish);

/**
 * Returns the cache instance used to cache
 *
 * @return Phalcon\Cache\BackendInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, getCache);

/**
 * Cache the actual view render to certain level
 *
 * @param boolean|array $options
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, cache);

/**
 * Externally sets the view content
 *
 * @param string $content
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, setContent);

/**
 * Returns cached ouput from another view stage
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, getContent);

/**
 * Returns the path of the view that is currently rendered
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, getActiveRenderPath);

/**
 * Disables the auto-rendering process
 *
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, disable);

/**
 * Enables the auto-rendering process
 *
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, enable);

/**
 * Resets the view component to its factory default values
 *
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ViewInterface, reset);

