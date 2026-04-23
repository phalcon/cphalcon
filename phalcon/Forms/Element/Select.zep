
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Forms\Element;

use Phalcon\Forms\Exception;
use Phalcon\Html\Helper\Input\Select\ArrayData;
use Phalcon\Html\Helper\Input\Select\ResultsetData;
use Phalcon\Html\TagFactory;
use Phalcon\Mvc\Model\ResultsetInterface;

/**
 * Component SELECT (choice) for forms
 */
class Select extends AbstractElement
{
    /**
     * @var object|array|null
     */
    protected optionsValues = null;

    /**
     * Constructor
     *
     * @param string            name
     * @param object|array|null options
     * @param array             attributes
     */
    public function __construct(string name, options = null, array attributes = [])
    {
        let this->optionsValues = options;

        parent::__construct(name, attributes);
    }

    /**
     * Adds an option to the current options
     *
     * @param array|string option
     */
    public function addOption(var option) -> <ElementInterface>
    {
        var key, value;

        if typeof option == "array" {
            for key, value in option {
                let this->optionsValues[key] = value;
            }
        } else {
            let this->optionsValues[] = option;
        }

        return this;
    }

    /**
     * Returns the choices' options
     *
     * @return array|object
     */
    public function getOptions()
    {
        return this->optionsValues;
    }

    /**
     * Renders the element widget returning HTML
     */
    public function render(array attributes = []) -> string
    {
        var attrs, emptyText, emptyValue, html, name, options,
            select, tagFactory, using, useEmpty, value;

        let attrs = this->prepareAttributes(attributes);

        let name = attrs[0];
        unset attrs[0];

        if isset attrs["value"] {
            let value = attrs["value"];
            unset attrs["value"];
        } else {
            let value = null;
        }

        if isset attrs["useEmpty"] {
            let useEmpty = attrs["useEmpty"];
        } else {
            let useEmpty = false;
        }

        if isset attrs["emptyValue"] {
            let emptyValue = attrs["emptyValue"];
        } else {
            let emptyValue = "";
        }

        if isset attrs["emptyText"] {
            let emptyText = attrs["emptyText"];
        } else {
            let emptyText = "Choose...";
        }

        if isset attrs["using"] {
            let using = attrs["using"];
        } else {
            let using = null;
        }

        unset attrs["useEmpty"];
        unset attrs["emptyValue"];
        unset attrs["emptyText"];
        unset attrs["using"];

        if !isset attrs["name"] {
            let attrs["name"] = name;
        }

        if !strpos(name, "[") && !isset attrs["id"] {
            let attrs["id"] = name;
        }

        let tagFactory = this->getLocalTagFactory(),
            select     = tagFactory->newInstance("inputSelect");

        select->__invoke("", "", attrs);

        if value !== null {
            select->selected((string) value);
        }

        if useEmpty {
            select->addPlaceholder(emptyText, emptyValue, [], true);
        }

        let options = this->optionsValues;

        if typeof options == "array" {
            select->fromData(new ArrayData(options));
        } elseif typeof options == "object" && options instanceof ResultsetInterface {
            if unlikely using === null || typeof using != "array" {
                throw Exception::usingParameterRequired();
            }

            select->fromData(new ResultsetData(options, using));
        }

        let html = (string) select;

        if html === "" {
            return tagFactory->newInstance("element")->__invoke("select", PHP_EOL, attrs, true);
        }

        return html;
    }

    /**
     * Set the choice's options
     *
     * @param array|object options
     */
    public function setOptions(var options) -> <ElementInterface>
    {
        let this->optionsValues = options;

        return this;
    }

    /**
     * Returns an array of prepared attributes for Phalcon\Html\TagFactory
     * helpers according to the element parameters
     */
    protected function prepareAttributes(array attributes = []) -> array
    {
        var value, name, mergedAttributes, defaultAttributes;

        let name = this->name;

        let attributes[0] = name;

        /**
         * Merge passed parameters with default ones
         */
        let defaultAttributes = this->attributes,
            mergedAttributes = array_merge(defaultAttributes, attributes);

        /**
         * Get the current element value
         */
        let value = this->getValue();

        /**
         * If the widget has a value set it as default value
         */
        if value !== null {
            let mergedAttributes["value"] = value;
        }

        return mergedAttributes;
    }
}
