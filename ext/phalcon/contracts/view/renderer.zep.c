
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

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
 * Renders a template with the given data and returns the result as a string.
 *
 * A neutral abstraction: it is not tied to MVC, to ADR, or to any particular
 * template engine. `Phalcon\Mvc\View\Simple` satisfies it out of the box, and
 * userland engines only need this one method to become a drop-in renderer.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_View_Renderer)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\View, Renderer, phalcon, contracts_view_renderer, phalcon_contracts_view_renderer_method_entry);

	return SUCCESS;
}

/**
 * Renders the template and returns the output.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_View_Renderer, render);
