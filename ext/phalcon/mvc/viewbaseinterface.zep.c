
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\ViewInterface
 *
 * Interface for Phalcon\Mvc\View and Phalcon\Mvc\View\Simple
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_ViewBaseInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc, ViewBaseInterface, phalcon, mvc_viewbaseinterface, phalcon_mvc_viewbaseinterface_method_entry);

	return SUCCESS;
}

/**
 * Returns cached output from another view stage
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewBaseInterface, getContent);
/**
 * Returns parameters to views
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewBaseInterface, getParamsToView);
/**
 * Gets views directory
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewBaseInterface, getViewsDir);
/**
 * Renders a partial view
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewBaseInterface, partial);
/**
 * Externally sets the view content
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewBaseInterface, setContent);
/**
 * Adds parameters to views (alias of setVar)
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewBaseInterface, setParamToView);
/**
 * Adds parameters to views
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewBaseInterface, setVar);
/**
 * Sets views directory. Depending of your platform, always add a trailing
 * slash or backslash
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ViewBaseInterface, setViewsDir);
