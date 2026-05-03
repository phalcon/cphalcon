
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

use Phalcon\Html\Escaper\EscaperInterface;
use Phalcon\Html\Helper\Doctype;

/**
 * Shared base for inputs that can be checked: `<input type="checkbox">` and
 * `<input type="radio">`. Holds the optional surrounding `<label>` markup,
 * the `unchecked` companion hidden input, and the rule that decides whether
 * the rendered tag carries `checked="checked"`.
 *
 * The match between `checked` and `value` is loose (`==`) by default so that
 * mixed int/string form input round-trips correctly (e.g. `value=0` against
 * `checked="0"`). Strict (`===`) matching is available via `strict(true)`.
 *
 * @property array $label
 * @property bool  $strict
 */
abstract class AbstractChecked extends AbstractInput
{
    /**
     * @var array
     */
    protected label = [];

    /**
     * @var bool
     */
    protected strict = false;

    /**
     * @param EscaperInterface $escaper
     * @param Doctype          $doctype
     */
    public function __construct(<EscaperInterface> escaper, <Doctype> doctype = null)
    {
        parent::__construct(escaper, doctype);

        let this->label = [
            "start" : "",
            "text"  : "",
            "end"   : ""
        ];
    }

    /**
     * Returns the HTML for the input, optionally surrounded by the label
     * fragment configured via `label()` and preceded by the hidden companion
     * input emitted when an `unchecked` attribute is supplied.
     *
     * @return string
     */
    public function __toString()
    {
        var element, label, unchecked;

        this->processChecked();

        let unchecked   = this->processUnchecked(),
            element     = parent::__toString(),
            label       = this->label,
            this->label = [
                "start" : "",
                "text"  : "",
                "end"   : ""
            ];

        return unchecked
            . label["start"]
            . element
            . label["text"]
            . label["end"];
    }

    /**
     * Attaches a wrapping `<label>` to the element. The supplied attributes
     * are merged with a default `for` pointing at the input's `id`. A `text`
     * pseudo-attribute, if present, becomes the label text and is stripped
     * from the rendered attributes.
     *
     * @param array $attributes
     *
     * @return AbstractChecked
     */
    public function label(array attributes = []) -> <AbstractChecked>
    {
        var text;

        if !fetch text, attributes["text"] {
            let text = "";
        }

        unset attributes["text"];

        let attributes = array_merge(
            [
                "for" : this->attributes["id"]
            ],
            attributes
        );

        let this->label = [
            "start" : this->renderTag("label", attributes),
            "text"  : text,
            "end"   : "</label>"
        ];

        return this;
    }

    /**
     * Toggles strict (`===`) comparison between the `checked` attribute and
     * the `value` attribute when deciding whether to render the input as
     * checked. Defaults to loose (`==`), which matches typical form-input
     * round-tripping where types may differ between the source data and the
     * value rendered into the markup.
     *
     * @param bool $flag
     *
     * @return AbstractChecked
     */
    public function strict(bool flag = true) -> <AbstractChecked>
    {
        let this->strict = flag;

        return this;
    }

    /**
     * Decides whether the rendered tag carries `checked="checked"` by
     * comparing the user-supplied `checked` attribute against `value`.
     */
    protected function processChecked() -> void
    {
        var checked, value, matched;
        array attributes;

        let attributes = this->attributes;
        if !fetch checked, attributes["checked"] {
            let checked = null;
        }

        unset attributes["checked"];

        if checked !== null {
            if !fetch value, attributes["value"] {
                let value = null;
            }

            if this->strict {
                let matched = checked === value;
            } else {
                let matched = checked == value;
            }

            if matched {
                let attributes["checked"] = "checked";
            }
        }

        let this->attributes = attributes;
    }

    /**
     * Returns the markup for the optional hidden companion input that lets
     * a checkbox/radio submit a value when unchecked.
     *
     * @return string
     */
    protected function processUnchecked() -> string
    {
        var unchecked;
        array attributes;

        let attributes = this->attributes;
        if !fetch unchecked, attributes["unchecked"] {
            let unchecked = "";
        }

        unset attributes["unchecked"];

        if !empty unchecked {
            let unchecked = this->renderTag(
                "hidden",
                [
                    "name"  : this->attributes["name"],
                    "value" : unchecked
                ]
            );
        }

        let this->attributes = attributes;

        return unchecked;
    }
}
