
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html;

use Phalcon\Support\Collection;
use Phalcon\Html\Attributes\RenderInterface;

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
        return $this->renderAttributes(this->toArray());
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
                let result .= key . "=\""
                . htmlspecialchars(value, ENT_QUOTES, "utf-8", true)
                . "\" ";
            }
        }

        return result;
    }
}
