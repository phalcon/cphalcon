
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Forms\Element;

use Phalcon\Contracts\Forms\FormsTypes;
use Phalcon\Contracts\Html\HtmlTypes;
use Phalcon\Tag\Select as SelectTag;

/**
 * Component SELECT (choice) for forms
 *
 * @phpstan-import-type forms_attributes from FormsTypes
 * @phpstan-import-type forms_select_options from FormsTypes
 * @phpstan-import-type html_attributes from HtmlTypes
 */
class Select extends AbstractElement
{
    /**
     * @var array|object|null
     *
     * @phpstan-var forms_select_options|object|null
     */
    protected optionsValues = null;

    /**
     * Constructor
     *
     * @phpstan-param forms_select_options|object|null $options
     * @phpstan-param forms_attributes $attributes
     */
    public function __construct(string name, options = null, array attributes = [])
    {
        let this->optionsValues = options;

        parent::__construct(name, attributes);
    }

    /**
     * Adds an option to the current options
     *
     * @param mixed option
     */
    public function addOption(var option) -> <ElementInterface>
    {
        var key, value;

        if this->optionsValues === null {
            let this->optionsValues = [];
        }

        if typeof this->optionsValues == "array" {
            if typeof option == "array" {
                for key, value in option {
                    let this->optionsValues[key] = value;
                }
            } else {
                let this->optionsValues[] = option;
            }
        }

        return this;
    }

    /**
     * Returns the choices' options
     *
     * @phpstan-return forms_select_options|object|null
     */
    public function getOptions()
    {
        return this->optionsValues;
    }

    /**
     * Renders the element widget returning HTML
     *
     * @phpstan-param html_attributes $attributes
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
     * @phpstan-param forms_select_options|object $options
     */
    public function setOptions(var options) -> <ElementInterface>
    {
        let this->optionsValues = options;

        return this;
    }

    /**
     * Returns an array of prepared attributes for Phalcon\Html\TagFactory
     * helpers according to the element parameters
     *
     * @phpstan-param html_attributes $attributes
     * @phpstan-return array<array-key, mixed>
     */
    protected function prepareAttributes(array attributes = []) -> array
    {
        var value, name, mergedAttributes, defaultAttributes;

        let name = this->name;

        let attributes[0] = name;

        /**
         * Merge passed parameters with default ones
         */
        let defaultAttributes = this->attributes,
            mergedAttributes = array_merge(defaultAttributes, attributes);

        /**
         * Get the current element value
         */
        let value = this->getValue();

        /**
         * If the widget has a value set it as default value
         */
        if value !== null {
            let mergedAttributes["value"] = value;
        }

        return mergedAttributes;
    }
}
