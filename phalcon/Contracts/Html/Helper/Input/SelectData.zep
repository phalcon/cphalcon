
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

namespace Phalcon\Contracts\Html\Helper\Input;

/**
 * Interface for SELECT option data providers.
 *
 * Return format: [value => label] for flat options;
 * [groupLabel => [value => label, ...]] for optgroups.
 */
interface SelectData
{
    /**
     * Returns the per-option attribute map.
     *
     * Format: [optionValue => [attrName => stringValue, ...]].
     * Implementations must return resolved string values; no escaping,
     * ordering, or rendering is performed here.
     */
    public function getAttributes() -> array;

    public function getOptions() -> array;
}
