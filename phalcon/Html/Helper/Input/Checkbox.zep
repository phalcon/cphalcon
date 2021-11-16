
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Helper\Input;

use Phalcon\Html\Escaper\EscaperInterface;

/**
 * Class Checkbox
 *
 * @property array $label
 */
class Checkbox extends AbstractInput
{
    /**
     * @var array
     */
    protected label = [];

    /**
     * @var string
     */
    protected type = "checkbox";

    /**
     * AbstractHelper constructor.
     *
     * @param EscaperInterface $escaper
     */
    public function __construct(<EscaperInterface> escaper)
    {
        parent::__construct(escaper);

        let this->label = [
            "start" : "",
            "text"  : "",
            "end"   : ""
        ];
    }

    /**
     * Returns the HTML for the input.
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
     * Attaches a label to the element
     *
     * @param array $attributes
     *
     * @return Checkbox
     */
    public function label(array attributes = []) -> <Checkbox>
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
     * Processes the checked value
     */
    private function processChecked() -> void
    {
        var checked, value;
        array attributes;

        let attributes = this->attributes;
        if !fetch checked, attributes["checked"] {
            let checked = "";
        }

        unset attributes["checked"];

        if !empty checked {
            if !fetch value, attributes["value"] {
                let value = "";
            }
            if checked === value {
                let attributes["checked"] = "checked";
            }
        }

        let this->attributes = attributes;
    }

    /**
     * Returns the unchecked hidden element if available
     *
     * @return string
     */
    private function processUnchecked() -> string
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
