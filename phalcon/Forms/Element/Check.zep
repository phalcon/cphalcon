
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Forms\Element;

/**
 * Component INPUT[type=check] for forms
 */
class Check extends AbstractElement
{
    /**
     * @var string
     */
    protected method = "inputCheckbox";

    /**
     * @var mixed
     */
    protected uncheckedValue = null;

    /**
     * @var bool
     */
    protected uncheckedValueSet = false;

    /**
     * Returns the value to bind when the checkbox is absent from submitted
     * data. Only meaningful when hasUncheckedValue() is true.
     */
    public function getUncheckedValue() -> var
    {
        return this->uncheckedValue;
    }

    /**
     * Whether an "unchecked value" has been explicitly registered.
     */
    public function hasUncheckedValue() -> bool
    {
        return this->uncheckedValueSet;
    }

    /**
     * Registers a value to bind when the checkbox is absent from submitted
     * data (the typical browser behavior for an unchecked input). Without
     * this opt-in, an unchecked checkbox leaves the entity property
     * untouched. See cphalcon issue #16982.
     */
    public function setUncheckedValue(var value) -> <static>
    {
        let this->uncheckedValue = value;
        let this->uncheckedValueSet = true;

        return this;
    }
}
