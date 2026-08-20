
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

/**
 * Shared base for rendering a group of same-named inputs (checkbox or radio)
 * from an options array.
 *
 * Each option in the $options array may be either:
 *   - a scalar string label:  ['value' => 'Label text']
 *   - a rich definition:      ['value' => ['label' => 'Label text', 'disabled' => true, ...]]
 *
 * The $checked parameter is resolved by the concrete subclass:
 *   - CheckboxGroup compares against an array of selected values
 *   - RadioGroup compares against a single scalar value
 *
 * @phpstan-import-type html_attributes from HtmlTypes
 * @phpstan-import-type html_group_definition from HtmlTypes
 * @phpstan-import-type html_group_options from HtmlTypes
 */
abstract class AbstractGroup extends AbstractHelper
{
    /**
     * @var mixed
     */
    protected checked = null;
    protected string name = "";
    /**
     * @phpstan-var html_group_options
     */
    protected array options = [];
    /**
     * @phpstan-var html_attributes
     */
    protected array sharedAttributes = [];
    protected string type = "checkbox";

    /**
     * @phpstan-param html_group_options $options
     * @phpstan-param html_attributes     $attributes
     */
    public function __invoke(
        string name,
        array options,
        var checked = null,
        array attributes = []
    ) -> <static> {
        let this->name             = name,
            this->options          = options,
            this->checked          = checked,
            this->sharedAttributes = attributes;

        return this;
    }

    /**
     * Renders the group of inputs as a string.
     */
    public function __toString() -> string
    {
        var definition, value;
        array lines;

        let lines = [];

        for value, definition in this->options {
            if typeof definition !== "string" && typeof definition !== "array" {
                continue;
            }

            let lines[] = this->renderItem((string) value, definition);
        }

        let this->options          = [],
            this->checked          = null,
            this->sharedAttributes = [];

        return implode(PHP_EOL, lines);
    }

    /**
     * Determines whether the given value is considered checked.
     *
     * @param string $value
     *
     * @return bool
     */
    abstract protected function isChecked(string value) -> bool;

    /**
     * Renders a single input + optional label pair.
     *
     * @phpstan-param html_group_definition $definition
     */
    protected function renderItem(string value, var definition) -> string
    {
        var baseId, input, inputAttrs, itemExtras, label, labelText;

        if typeof definition === "array" {
            if isset definition["label"] && typeof definition["label"] === "string" {
                let labelText = definition["label"];
            } else {
                let labelText = value;
            }

            let itemExtras = definition;
            unset itemExtras["label"];
        } else {
            let labelText  = (string) definition,
                itemExtras = [];
        }

        let baseId = rtrim(str_replace(["[", "]"], ["_", ""], this->name), "_") . "_" . value;

        let inputAttrs = array_merge(
            this->sharedAttributes,
            itemExtras,
            [
                "id"    : (isset itemExtras["id"] ? itemExtras["id"] : baseId),
                "name"  : this->name,
                "value" : value
            ]
        );

        if this->isChecked(value) {
            let inputAttrs["checked"] = "checked";
        } else {
            unset inputAttrs["checked"];
        }

        let inputAttrs = array_merge(["type": this->type], inputAttrs);

        let input = this->renderTag("input", inputAttrs);
        let label = this->renderFullElement("label", labelText, ["for": inputAttrs["id"]]);

        return input . label;
    }
}
