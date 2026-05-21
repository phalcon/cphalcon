
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

use Phalcon\Html\Helper\AbstractHelper;
use Phalcon\Html\Helper\Doctype;

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
    ) -> <static> {
        let this->attributes = [
            "type" : this->type,
            "name" : name
        ];

        if !isset attributes["id"] && !memstr(name, "[") {
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
        var closeTag;

        let closeTag         = "",
            attributes       = this->attributes,
            this->attributes = [];

        if (this->doctype->getType() > Doctype::HTML5) {
            let closeTag = "/";
        }

        return this->renderTag(
            "input",
            attributes,
            closeTag
        );
    }

    /**
     * Sets the value of the element
     *
     * @param string|null $value
     *
     * @return AbstractInput
     */
    public function setValue(string value = null) -> <static>
    {
        if value !== null {
            let this->attributes["value"] = value;
        }

        return this;
    }
}
