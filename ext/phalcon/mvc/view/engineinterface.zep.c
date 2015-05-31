
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_View_EngineInterface, __construct);

/**
 * Returns cached output on another view stage
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_View_EngineInterface, getContent);

/**
 * Renders a partial inside another view
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_View_EngineInterface, partial);

/**
 * Renders a view using the template engine
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_View_EngineInterface, render);

