
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

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
 * Interface for Phalcon\Mvc\View engine adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_EngineInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\View\\Engine, EngineInterface, phalcon, mvc_view_engine_engineinterface, phalcon_mvc_view_engine_engineinterface_method_entry);

	return SUCCESS;
}

/**
 * Returns cached output on another view stage
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_View_Engine_EngineInterface, getContent);
/**
 * Renders a partial inside another view
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_View_Engine_EngineInterface, partial);
/**
 * Renders a view using the template engine
 *
 * TODO: Change params to array type
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_View_Engine_EngineInterface, render);
