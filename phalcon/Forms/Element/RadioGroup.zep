
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Forms\Element;

use Phalcon\Html\TagFactory;

/**
 * Component for a group of INPUT[type=radio] elements.
 *
 * Options are passed as an associative array:
 *   ['value' => 'Label']
 * or with per-item attributes:
 *   ['value' => ['label' => 'Label', 'disabled' => true]]
 */
class RadioGroup extends AbstractElement
{
    /**
     * @var array
     */
    protected options = [];

    /**
     * Constructor
     *
     * @param string $name
     * @param array  $options
     * @param array  $attributes
     */
    public function __construct(
        string name,
        array options = [],
        array attributes = []
    ) {
        let this->options = options;

        parent::__construct(name, attributes);
    }

    /**
     * Returns the group options
     *
     * @return array
     */
    public function getOptions() -> array
    {
        return this->options;
    }

    /**
     * Renders the radio group returning HTML
     *
     * @param array $attributes
     *
     * @return string
     */
    public function render(array attributes = []) -> string
    {
        var helper, merged, value;

        let value  = this->getValue(),
            merged = array_merge(this->attributes, attributes),
            helper = this->getLocalTagFactory()->newInstance("inputRadioGroup");

        return (string) helper->__invoke(this->name, this->options, value, merged);
    }

    /**
     * Sets the group options
     *
     * @param array $options
     *
     * @return ElementInterface
     */
    public function setOptions(array options) -> <ElementInterface>
    {
        let this->options = options;

        return this;
    }
}
