
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

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
 * Interface for SELECT option data providers.
 *
 * Return format: [value => label] for flat options;
 * [groupLabel => [value => label, ...]] for optgroups.
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_Select_SelectDataInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Html\\Helper\\Input\\Select, SelectDataInterface, phalcon, html_helper_input_select_selectdatainterface, phalcon_html_helper_input_select_selectdatainterface_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Html_Helper_Input_Select_SelectDataInterface, getOptions);
