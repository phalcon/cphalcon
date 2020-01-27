
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Helper;

use Phalcon\Html\Exception;
use Phalcon\Escaper\EscaperInterface;

/**
 * Phalcon\Html\Helper\AbstractHelper
 *
 * Abstract class for all HTML helpers
 */
abstract class AbstractHelper
{
    /**
     * @var EscaperInterface
     */
    protected escaper;

    /**
     * Constructor
     */
    public function __construct(<EscaperInterface> escaper)
    {
        let this->escaper = escaper;
    }

    /**
     * Renders an element
     */
    protected function renderFullElement(
        string tag,
        string text,
        array attributes = [],
        bool raw = false
    ) -> string {

        var content;

        let content = raw ? text : this->escaper->escapeHtml(text);

        return this->renderElement(tag, attributes) . content . "</" . tag . ">";
    }

    /**
     * Renders an element
     */
    protected function renderElement(string! tag, array! attributes = []) -> string
    {
        var attrs, escapedAttrs;

        let escapedAttrs = "";
        if count(attributes) > 0 {
            let attrs        = this->orderAttributes([], attributes),
                escapedAttrs = " " . rtrim(this->renderAttributes(attrs));
        }

        return "<" . tag . escapedAttrs . ">";
    }

    /**
     * Keeps all the attributes sorted - same order all the tome
     *
     * @param array overrides
     * @param array attributes
     *
     * @return array
     */
    protected function orderAttributes(array overrides, array attributes) -> array
    {
        var intersect, order, results;

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
            results   = array_merge(intersect, attributes),
            results   = array_merge(overrides, results);

        /**
         * Just in case remove the "escape" attribute
         */
        unset results["escape"];

        return results;
    }

    /**
     * Renders all the attributes
     */
    protected function renderAttributes(array! attributes) -> string
    {
        var key, result, value;

        let result = "";
        for key, value in attributes {
            if typeof key === "string" && null !== value {
                if typeof value === "array"    ||
                   typeof value === "resource" ||
                   typeof value === "object" {
                    throw new Exception(
                        "Value at index: \"" . key . "\" type: \"" . gettype(value) . "\" cannot be rendered"
                    );
                }

                let result .= key . "=\"" . this->escaper->escapeHtmlAttr(value) . "\" ";
            }
        }

        return result;
    }

    /**
     * Produces a self close tag i.e. <img />
     */
    protected function selfClose(string! tag, array! attributes = []) -> string
    {
        var attrs, escapedAttrs;

        let escapedAttrs = "";
        if count(attributes) > 0 {
            let attrs        = this->orderAttributes([], attributes),
                escapedAttrs = " " . rtrim(this->renderAttributes(attrs));
        }

        return "<" . tag . escapedAttrs . "/>";
    }
}
