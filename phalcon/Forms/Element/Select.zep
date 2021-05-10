
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Forms\Element;

use Phalcon\Tag\Select as SelectTag;

/**
 * Phalcon\Forms\Element\Select
 *
 * Component SELECT (choice) for forms
 */
class Select extends AbstractElement
{
    /**
     * @var object|array|null
     */
    protected optionsValues = null;

    /**
     * Phalcon\Forms\Element constructor
     *
     * @param object|array options
     * @param array        attributes
     */
    public function __construct(string name, options = null, array attributes = [])
    {
        let this->optionsValues = options;

        parent::__construct(name, attributes);
    }

    /**
     * Adds an option to the current options
     *
     * @param array|string option
     */
    public function addOption(var option) -> <ElementInterface>
    {
        var key, value;

        if typeof option == "array" {
            for key, value in option {
                let this->optionsValues[key] = value;
            }
        } else {
            let this->optionsValues[] = option;
        }

        return this;
    }

    /**
     * Returns the choices' options
     *
     * @return array|object
     */
    public function getOptions()
    {
        return this->optionsValues;
    }

    /**
     * Renders the element widget returning HTML
     */
    public function render(array attributes = []) -> string
    {
        /**
         * Merged passed attributes with previously defined ones
         */
        return SelectTag::selectField(
            this->prepareAttributes(attributes),
            this->optionsValues
        );
    }

    /**
     * Set the choice's options
     *
     * @param array|object options
     */
    public function setOptions(var options) -> <ElementInterface>
    {
        let this->optionsValues = options;

        return this;
    }
}
