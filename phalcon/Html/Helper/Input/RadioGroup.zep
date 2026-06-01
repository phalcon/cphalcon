
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
 */

namespace Phalcon\Html\Helper\Input;

/**
 * Renders a group of `<input type="radio">` elements from an options array.
 *
 * The $checked parameter should be a single scalar value matching the selected
 * option's value attribute.
 */
class RadioGroup extends AbstractGroup
{
    /**
     * @var string
     */
    protected type = "radio";

    /**
     * Returns true when $value loosely equals the checked scalar.
     *
     * @param string $value
     *
     * @return bool
     */
    protected function isChecked(string value) -> bool
    {
        if this->checked === null {
            return false;
        }

        return (string) this->checked === value;
    }
}
