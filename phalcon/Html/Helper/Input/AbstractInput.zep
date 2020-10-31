
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Helper\Input;

use Phalcon\Html\Helper\AbstractHelper;

/**
 * Class AbstractInput
 *
 * @property array  $attributes
 * @property string $type
 * @property string $value
 */
abstract class AbstractInput extends AbstractHelper
{
    /**
     * @var string
     */
    protected type = "text";

    /**
     * @var array
     */
    protected attributes = [];

    /**
     * @param string      $name
     * @param string|null $value
     * @param array       $attributes
     *
     * @return AbstractInput
     */
    public function __invoke(
        string name,
        string value = null,
        array attributes = []
    ) -> <AbstractInput> {
        let this->attributes = [
            "type" : this->type,
            "name" : name
        ];

        if !isset attributes["id"] {
            let this->attributes["id"] = name;
        }

        this->setValue(value);

        let this->attributes = array_merge(this->attributes, attributes);

        return this;
    }

    /**
     * Returns the HTML for the input.
     *
     * @return string
     */
    public function __toString()
    {
        array attributes;

        let attributes       = this->attributes,
            this->attributes = [];

        return this->renderTag(
            "input",
            attributes,
            "/"
        );
    }

    /**
     * Sets the value of the element
     *
     * @param string|null $value
     *
     * @return AbstractInput
     */
    public function setValue(string value = null) -> <AbstractInput>
    {
        if is_numeric(value) || !empty(value)  {
            let this->attributes["value"] = value;
        }

        return this;
    }
}
