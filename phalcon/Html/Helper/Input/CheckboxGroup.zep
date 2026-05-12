
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Helper\Input;

/**
 * Renders a group of `<input type="checkbox">` elements from an options array.
 *
 * The $checked parameter should be an array of selected values, or a single
 * scalar value (treated as a one-element array).
 */
class CheckboxGroup extends AbstractGroup
{
    /**
     * @var string
     */
    protected type = "checkbox";

    /**
     * Returns true when $value appears in the checked list.
     *
     * @param string $value
     *
     * @return bool
     */
    protected function isChecked(string value) -> bool
    {
        var selected;

        if this->checked === null {
            return false;
        }

        if typeof this->checked === "array" {
            let selected = this->checked;
        } else {
            let selected = [this->checked];
        }

        return in_array(value, selected, false);
    }
}
