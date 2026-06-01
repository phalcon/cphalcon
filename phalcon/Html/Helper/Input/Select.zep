
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

use Phalcon\Html\Helper\AbstractList;
use Phalcon\Contracts\Html\Helper\Input\SelectData;

/**
 * Class Select
 */
class Select extends AbstractList
{
    /**
     * @var string
     */
    protected elementTag = "option";

    /**
     * @var bool
     */
    protected inOptGroup = false;

    /**
     * @var string
     */
    protected selected = "";

    /**
     * @var bool
     */
    protected strict = false;

    /**
     * Add an element to the list
     *
     * @param string      $text
     * @param string|null $value
     * @param array       $attributes
     * @param bool        $raw
     *
     * @return static
     */
    public function add(
        string text,
        string value = null,
        array attributes = [],
        bool raw = false
    ) -> <static> {
        let attributes = this->processValue(attributes, value);

        let this->store[] = [
            "renderFullElement",
            [
                this->elementTag,
                text,
                attributes,
                raw
            ],
            this->indent()
        ];

        return this;
    }

    /**
     * Add a placeholder to the element
     *
     * @param string $text
     * @param string $value
     * @param array  $attributes
     * @param bool   $raw
     *
     * @return static
     */
    public function addPlaceholder(
        string text,
        string value = null,
        array attributes = [],
        bool raw = false
    ) -> <static> {
        if null !== value {
            let attributes["value"] = value;
        }

        let this->store[] = [
            "renderFullElement",
            [
                this->elementTag,
                text,
                attributes,
                raw
            ],
            this->indent()
        ];

        return this;
    }

    /**
     * Populates the select from a data provider.
     *
     * Flat entries: key = option value, value = label string.
     * Optgroup entries: key = group label, value = [value => label] array.
     *
     * @param SelectData data
     *
     * @return static
     */
    public function fromData(<SelectData> data) -> <static>
    {
        var attributes, key, optionAttrs, subAttrs, subKey, subValue, value;

        let attributes = data->getAttributes();

        for key, value in data->getOptions() {
            if typeof value == "array" {
                this->optGroup((string) key);

                for subKey, subValue in value {
                    let subAttrs = isset(attributes[subKey]) ? attributes[subKey] : [];

                    this->add((string) subValue, (string) subKey, subAttrs);
                }

                this->optGroup((string) key);
            } else {
                let optionAttrs = isset(attributes[key]) ? attributes[key] : [];

                this->add((string) value, (string) key, optionAttrs);
            }
        }

        return this;
    }

    /**
     * Creates an option group
     *
     * @param string $label
     * @param array  $attributes
     *
     * @return static
     */
    public function optGroup(
        string label = null,
        array attributes = []
    ) -> <static> {
        if !this->inOptGroup {
            let this->store[]     = [
                "optGroupStart",
                [
                    label,
                    attributes
                ],
                this->indent()
            ],
            this->indentLevel += 1;
        } else {
            let this->indentLevel -= 1,
                this->store[]     = [
                    "optGroupEnd",
                    [],
                    this->indent()
                ];
        }

        let this->inOptGroup = !this->inOptGroup;

        return this;
    }

    /**
     * Adds a non-selectable placeholder option as the first entry. Renders
     * as `<option value="" disabled selected>$text</option>`, matching the
     * common HTML idiom for "Choose..."-style prompts.
     *
     * @param string $text
     *
     * @return static
     */
    public function placeholder(string text) -> <static>
    {
        let this->store[] = [
            "renderFullElement",
            [
                this->elementTag,
                text,
                [
                    "value"    : "",
                    "disabled" : "disabled",
                    "selected" : "selected"
                ],
                false
            ],
            this->indent()
        ];

        return this;
    }

    /**
     * @param string $selected
     *
     * @return static
     */
    public function selected(string selected) -> <static>
    {
        let this->selected = selected;

        return this;
    }

    /**
     * Toggles strict (`===`) comparison between an option's `value` and
     * the previously stored `selected` value. Defaults to loose (`==`),
     * matching the round-tripping fix in `AbstractChecked` so mixed
     * int/string form data marks the right option as selected.
     *
     * @param bool $flag
     *
     * @return static
     */
    public function strict(bool flag = true) -> <static>
    {
        let this->strict = flag;

        return this;
    }

    /**
     * @return string
     */
    protected function getTag() -> string
    {
        return "select";
    }

    /**
     * @return string
     */
    protected function optGroupEnd() -> string
    {
        return "</optgroup>";
    }

    /**
     * @param string $label
     * @param array  $attributes
     *
     * @return string
     */
    protected function optGroupStart(
        string label,
        array attributes
    ) -> string {
        let attributes["label"] = label;

        return this->renderTag("optgroup", attributes);
    }

    /**
     * Checks if the value has been passed and if it is the same as the
     * value stored in the object
     *
     * @param array  $attributes
     * @param string $value
     *
     * @return array
     */
    private function processValue(
        array attributes,
        string value = null
    ) -> array {
        var matched;

        if is_numeric(value) || !empty(value)  {
            let attributes["value"] = value;
            if this->selected !== "" {
                if this->strict {
                    let matched = value === this->selected;
                } else {
                    let matched = value == this->selected;
                }

                if matched {
                    let attributes["selected"] = "selected";
                }
            }
        }

        return attributes;
    }
}
