
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Helper\Input;

use Phalcon\Html\Helper\AbstractList;
use Phalcon\Html\Helper\Input\Select\SelectDataInterface;

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
     * Add an element to the list
     *
     * @param string      $text
     * @param string|null $value
     * @param array       $attributes
     * @param bool        $raw
     *
     * @return Select
     */
    public function add(
        string text,
        string value = null,
        array attributes = [],
        bool raw = false
    ) -> <Select> {
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
     * @return Select
     */
    public function addPlaceholder(
        string text,
        var value = null,
        array attributes = [],
        bool raw = false
    ) -> <Select> {
        if null !== value {
            let attributes["value"] = (string) value;
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
     * @param SelectDataInterface data
     *
     * @return Select
     */
    public function fromData(<SelectDataInterface> data) -> <Select>
    {
        var key, subKey, subValue, value;

        for key, value in data->getOptions() {
            if typeof value == "array" {
                this->optGroup((string) key);

                for subKey, subValue in value {
                    this->add((string) subValue, (string) subKey);
                }

                this->optGroup((string) key);
            } else {
                this->add((string) value, (string) key);
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
     * @return Select
     */
    public function optGroup(
        string label = null,
        array attributes = []
    ) -> <Select> {
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
     * @param string $selected
     *
     * @return Select
     */
    public function selected(string selected) -> <Select>
    {
        let this->selected = selected;

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
        var value = null
    ) -> array {
        if is_numeric(value) || !empty(value)  {
            let attributes["value"] = value;
            if !empty this->selected && value === this->selected {
                let attributes["selected"] = "selected";
            }
        }

        return attributes;
    }
}
