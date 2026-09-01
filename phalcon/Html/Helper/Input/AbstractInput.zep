
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

use Phalcon\Contracts\Html\HtmlTypes;
use Phalcon\Html\Helper\AbstractHelper;
use Phalcon\Html\Helper\Doctype;

/**
 * Class AbstractInput
 *
 * @phpstan-import-type html_attributes from HtmlTypes
 */
abstract class AbstractInput extends AbstractHelper
{
    /**
     * @phpstan-var html_attributes
     */
    protected array attributes = [];
    protected string type = "text";

    /**
     * @phpstan-param html_attributes $attributes
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
     */
    public function __toString()
    {
        var closeTag, output;

        let closeTag = "";
        if null !== this->doctype && this->doctype->getType() > Doctype::HTML5 {
            let closeTag = "/";
        }

        let output = this->renderTag(
            "input",
            this->attributes,
            closeTag
        );

        let this->attributes = [];

        return output;
    }

    /**
     * Sets the value of the element
     */
    public function setValue(string value = null) -> <static>
    {
        if value !== null {
            let this->attributes["value"] = value;
        }

        return this;
    }
}
