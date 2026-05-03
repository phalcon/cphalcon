
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

namespace Phalcon\Html\Helper;

use Phalcon\Html\Escaper\EscaperInterface;
use Phalcon\Html\Exception;

/**
 * @property string           $delimiter
 * @property EscaperInterface $escaper
 * @property string           $indent
 * @property int              $indentLevel
 */
abstract class AbstractHelper
{
    /**
     * @var string
     */
    protected delimiter = "";

    /**
     * @var Doctype|null
     */
    protected doctype = null;

    /**
     * @var EscaperInterface
     */
    protected escaper;

    /**
     * @var string
     */
    protected indent = "    ";

    /**
     * @var int
     */
    protected indentLevel = 1;

    /**
     * AbstractHelper constructor.
     *
     * @param EscaperInterface $escaper
     */
    public function __construct(<EscaperInterface> escaper, <Doctype> doctype = null)
    {
        let this->delimiter = PHP_EOL,
            this->escaper   = escaper,
            this->doctype   = doctype;
    }

    /**
     * Produces a closing tag
     *
     * @param string $tag
     * @param bool   $raw
     *
     * @return string
     */
    protected function close(string tag, bool raw = false) -> string
    {
        let tag = raw ? tag : this->escaper->html(tag);

        return "</" . tag . ">";
    }

    /**
     * Replicates the indent x times as per indentLevel
     *
     * @return string
     */
    protected function indent() -> string
    {
        return str_repeat(this->indent, this->indentLevel);
    }

    /**
     * Keeps all the attributes sorted - same order all the tome
     *
     * @param array $overrides
     * @param array $attributes
     *
     * @return array
     */
    protected function orderAttributes(array overrides, array attributes) -> array
    {
        var intersect, results;
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
            results   = array_merge(intersect, attributes),
            results   = array_merge(overrides, results);

        /**
         * Just in case remove the "escape" attribute
         */
        unset results["escape"];

        return results;
    }

    /**
     * Traverses an array and calls the method defined in the first element
     * with attributes as the second, returning the resulting string
     *
     * @param array  $elements
     * @param string $delimiter
     *
     * @return string
     */
    protected function renderArrayElements(
        array elements,
        string delimiter
    ) -> string {
        var item, result;

        let result = "";
        for item in elements {
            let result .= item[2]
                . call_user_func_array([this, item[0]], item[1])
                . delimiter;
        }

        return result;
    }

    /**
     * Renders all the attributes
     *
     * @param array $attributes
     *
     * @return string
     */
    protected function renderAttributes(array attributes) -> string
    {
        var key, result, value;

        let result = "";
        for key, value in attributes {
            if typeof key === "string" && null !== value {
                if (true === value) {
                    let result .= key . " ";
                } else {
                    let result .= key . "=\"" . this->escaper->attributes(value) . "\" ";
                }
            }
        }

        return result;
    }

    /**
     * Forces a single key into the attribute array, stripping any user-supplied
     * value for that key first. Used by helpers whose first positional argument
     * is itself an attribute (`href` for Anchor, `src` for Img, etc.) to make
     * sure that argument always wins.
     *
     * @param string $key
     * @param string $value
     * @param array  $attributes
     *
     * @return array
     */
    protected function injectAttribute(string key, string value, array attributes) -> array
    {
        unset attributes[key];

        return array_merge(
            [key: value],
            attributes
        );
    }

    /**
     * Renders an element
     *
     * @param string $tag
     * @param array  $attributes
     *
     * @return string
     * @throws Exception
     */
    protected function renderElement(string tag, array attributes = []) -> string
    {
        return this->renderTag(tag, attributes);
    }

    /**
     * Renders an element
     *
     * @param string $tag
     * @param string $text
     * @param array  $attributes
     * @param bool   $raw
     *
     * @return string
     * @throws Exception
     */
    protected function renderFullElement(
        string tag,
        string text,
        array attributes = [],
        bool raw = false
    ) -> string {
        var content;

        let content = raw ? text : this->escaper->html(text);

        return this->renderElement(tag, attributes)
            . content
            . this->close(tag, raw);
    }

    /**
     * Renders a tag
     *
     * @param string $tag
     * @param array  $attributes
     * @param string $close
     *
     * @return string
     */
    protected function renderTag(
        string tag,
        array attributes = [],
        string close = ""
    ) -> string {
        var attrs, close, escapedAttrs;

        let escapedAttrs = "";
        if (true !== empty(attributes)) {
            let attrs        = this->orderAttributes([], attributes),
                escapedAttrs = " " . rtrim(this->renderAttributes(attrs));
        }

        let close = empty(trim(close)) ? "" : " " . trim(close);

        return "<" . tag . escapedAttrs . close . ">";
    }

    /**
     * Produces a self close tag i.e. <img />
     *
     * @param string $tag
     * @param array  $attributes
     *
     * @return string
     */
    protected function selfClose(string tag, array attributes = []) -> string
    {
        return this->renderTag(tag, attributes, "/");
    }
}
