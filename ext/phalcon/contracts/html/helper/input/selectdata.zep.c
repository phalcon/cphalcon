
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
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
 */
/**
 * Interface for SELECT option data providers.
 *
 * Return format: [value => label] for flat options;
 * [groupLabel => [value => label, ...]] for optgroups.
 *
 * @phpstan-import-type html_select_attributes from HtmlTypes
 * @phpstan-import-type html_select_options from HtmlTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Html_Helper_Input_SelectData)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Html\\Helper\\Input, SelectData, phalcon, contracts_html_helper_input_selectdata, phalcon_contracts_html_helper_input_selectdata_method_entry);

	return SUCCESS;
}

/**
 * Returns the per-option attribute map.
 *
 * Format: [optionValue => [attrName => stringValue, ...]].
 * Implementations must return resolved string values; no escaping,
 * ordering, or rendering is performed here.
 *
 * @phpstan-return html_select_attributes
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Html_Helper_Input_SelectData, getAttributes);
/**
 * @phpstan-return html_select_options
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Html_Helper_Input_SelectData, getOptions);
