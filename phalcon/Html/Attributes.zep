
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
 */

namespace Phalcon\Html;

use Phalcon\Html\Attributes\RenderInterface;
use Phalcon\Html\Exceptions\AttributeNotRenderable;
use Phalcon\Support\Collection;

/**
 * This class helps to work with HTML Attributes
 */
class Attributes extends Collection implements RenderInterface
{
    /**
     * Render attributes as HTML attributes
     */
    public function render() -> string
    {
        return this->renderAttributes(this->toArray());
    }

    /**
     * Alias of the render method
     */
    public function __toString() -> string
    {
        return this->render();
    }

    /**
     * @todo remove this when we refactor forms. Maybe remove this class? Put it into traits
     */
    protected function renderAttributes(array attributes) -> string
    {
        var intersect, key, result, results, value;
        array order;

        let order = [
            "rel"    : null,
            "type"   : null,
            "for"    : null,
            "src"    : null,
            "href"   : null,
            "action" : null,
            "id"     : null,
            "name"   : null,
            "value"  : null,
            "class"  : null
        ];

        let intersect = array_intersect_key(order, attributes),
            results   = array_merge(intersect, attributes);

        /**
         * Just in case remove the "escape" attribute
         */
        unset results["escape"];


        let result = "";
        for key, value in results {
            if typeof key === "string" && null !== value {
                if (typeof value === "array" || is_resource(value)) {
                    throw new AttributeNotRenderable(key, gettype(value));
                }

                let result .= key . "=\""
                . htmlspecialchars(value, ENT_QUOTES, "utf-8", true)
                . "\" ";
            }
        }

        return result;
    }
}
