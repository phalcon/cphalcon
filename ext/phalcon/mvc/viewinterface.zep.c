
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Mvc\ViewInterface
 *
 * Interface for Phalcon\Mvc\View
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_ViewInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc, ViewInterface, phalcon, mvc_viewinterface, phalcon_mvc_viewinterface_method_entry);

	zend_class_implements(phalcon_mvc_viewinterface_ce TSRMLS_CC, 1, phalcon_mvc_viewbaseinterface_ce);
	return SUCCESS;

}

/**
 * Sets the layouts sub-directory. Must be a directory under the views directory. Depending of your platform, always add a trailing slash or backslash
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, setLayoutsDir);

/**
 * Gets the current layouts sub-directory
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, getLayoutsDir);

/**
 * Sets a partials sub-directory. Must be a directory under the views directory. Depending of your platform, always add a trailing slash or backslash
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, setPartialsDir);

/**
 * Gets the current partials sub-directory
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, getPartialsDir);

/**
 * Sets base path. Depending of your platform, always add a trailing slash or backslash
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, setBasePath);

/**
 * Sets the render level for the view
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, setRenderLevel);

/**
 * Sets default view name. Must be a file without extension in the views directory
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, setMainView);

/**
 * Returns the name of the main view
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, getMainView);

/**
 * Change the layout to be used instead of using the name of the latest controller name
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, setLayout);

/**
 * Returns the name of the main view
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
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, cleanTemplateAfter);

/**
 * Gets the name of the controller rendered
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, getControllerName);

/**
 * Gets the name of the action rendered
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, getActionName);

/**
 * Gets extra parameters of the action rendered
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, getParams);

/**
 * Starts rendering process enabling the output buffering
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, start);

/**
 * Register templating engines
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
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, pick);

/**
 * Renders a partial view
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, partial);

/**
 * Finishes the render process by stopping the output buffering
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, finish);

/**
 * Returns the path of the view that is currently rendered
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, getActiveRenderPath);

/**
 * Disables the auto-rendering process
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, disable);

/**
 * Enables the auto-rendering process
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, enable);

/**
 * Resets the view component to its factory default values
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, reset);

/**
 * Whether the automatic rendering is disabled
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewInterface, isDisabled);

