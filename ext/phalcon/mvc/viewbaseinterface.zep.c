
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
 * Interface for Phalcon\Mvc\View and Phalcon\Mvc\View\Simple
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_ViewBaseInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc, ViewBaseInterface, phalcon, mvc_viewbaseinterface, phalcon_mvc_viewbaseinterface_method_entry);

	return SUCCESS;

}

/**
 * Sets views directory. Depending of your platform, always add a trailing slash or backslash
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewBaseInterface, setViewsDir);

/**
 * Gets views directory
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewBaseInterface, getViewsDir);

/**
 * Adds parameters to views (alias of setVar)
 *
 * @param string key
 * @param mixed value
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewBaseInterface, setParamToView);

/**
 * Adds parameters to views
 *
 * @param string key
 * @param mixed value
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewBaseInterface, setVar);

/**
 * Returns parameters to views
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewBaseInterface, getParamsToView);

/**
 * Returns the cache instance used to cache
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewBaseInterface, getCache);

/**
 * Cache the actual view render to certain level
 *
 * @param boolean|array options
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewBaseInterface, cache);

/**
 * Externally sets the view content
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewBaseInterface, setContent);

/**
 * Returns cached output from another view stage
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewBaseInterface, getContent);

