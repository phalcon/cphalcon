
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
use Phalcon\Html\TagFactory;

/**
 * Component for a group of INPUT[type=checkbox] elements.
 *
 * The name is automatically suffixed with [] when not already present so that
 * PHP collects all checked values into an array on form submission.
 *
 * Options are passed as an associative array:
 *   ['value' => 'Label']
 * or with per-item attributes:
 *   ['value' => ['label' => 'Label', 'disabled' => true]]
 *
 * @phpstan-import-type forms_attributes from FormsTypes
 * @phpstan-import-type forms_group_options from FormsTypes
 * @phpstan-import-type html_attributes from HtmlTypes
 */
class CheckGroup extends AbstractElement
{
    /**
     * @phpstan-var forms_group_options
     */
    protected array optionsValues = [];

    /**
     * Constructor
     *
     * @phpstan-param forms_group_options $options
     * @phpstan-param forms_attributes $attributes
     */
    public function __construct(
        string name,
        array options = [],
        array attributes = []
    ) {
        if !memstr(name, "[") {
            let name = name . "[]";
        }

        let this->optionsValues = options;

        parent::__construct(name, attributes);
    }

    /**
     * Returns the group options
     *
     * @phpstan-return forms_group_options
     */
    public function getOptions() -> array
    {
        return this->optionsValues;
    }

    /**
     * Renders the checkbox group returning HTML
     *
     * @phpstan-param html_attributes $attributes
     */
    public function render(array attributes = []) -> string
    {
        var helper, merged, value;

        let value  = this->getValue(),
            merged = array_merge(this->attributes, attributes),
            helper = this->getLocalTagFactory()->newInstance("inputCheckboxGroup");

        return (string) helper->__invoke(this->name, this->optionsValues, value, merged);
    }

    /**
     * Sets the group options
     *
     * @phpstan-param forms_group_options $options
     */
    public function setOptions(array options) -> <ElementInterface>
    {
        let this->optionsValues = options;

        return this;
    }
}
