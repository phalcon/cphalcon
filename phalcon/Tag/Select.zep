
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tag;

use Phalcon\Html\Escaper\EscaperInterface;
use Phalcon\Mvc\Model\ResultsetInterface;
use Phalcon\Tag as BaseTag;
use Stringable;

/**
 * Phalcon\Tag\Select
 *
 * Generates a SELECT HTML tag using a static array of values or a
 * Phalcon\Mvc\Model resultset
 *
 * @phpstan-import-type tag_parameters from BaseTag
 * @phpstan-import-type tag_select_data from BaseTag
 */
abstract class Select
{
    /**
     * Generates a SELECT tag
     *
     * @phpstan-param tag_parameters|string $parameters
     *
     * @param array|string $parameters = [
     *     'id' => '',
     *     'name' => '',
     *     'value' => '',
     *     'useEmpty' => false,
     *     'emptyValue' => '',
     *     'emptyText' => '',
     * ]
     *
     * @return string
     * @throws Exception
     */
    public static function selectField(
        var parameters,
        var data = null
    ) -> string {
        var params, name, id, value, useEmpty, code, emptyValue, emptyText,
            options, using, escaper;

        if typeof parameters != "array" {
            let params = [parameters, data];
        } else {
            let params = parameters;
        }

        if !fetch id, params[0] {
            let params[0] = params["id"];
        }

        let id = self::toStringValue(params[0]);

        /**
         * Automatically assign the id if the name is not an array
         */
        if !memstr(id, "[") {
            if !isset params["id"] {
                let params["id"] = id;
            }
        }

        if !fetch name, params["name"] {
            let params["name"] = id;
        } else {
            if !name {
                let params["name"] = id;
            }
        }

        if !fetch value, params["value"] {
            let value = BaseTag::getValue(id, params);
        } else {
            unset params["value"];
        }

        if fetch useEmpty, params["useEmpty"] {
            if !fetch emptyValue, params["emptyValue"] {
                let emptyValue = "";
            } else {
                unset params["emptyValue"];
            }

            if !fetch emptyText, params["emptyText"] {
                let emptyText = "Choose...";
            } else {
                unset params["emptyText"];
            }

            unset params["useEmpty"];
        }

        if !fetch options, params[1] {
            let options = data;
        }

        if typeof options == "object" {
            /**
             * The options is a resultset
             */
            if unlikely !fetch using, params["using"] {
                throw new Exception("The 'using' parameter is required");
            }

            if unlikely (typeof using != "array" && typeof using != "object") {
                throw new Exception(
                    "The 'using' parameter should be an array"
                );
            }
        }

        unset params["using"];

        let code = BaseTag::renderAttributes("<select", params) . ">" . PHP_EOL;

        if useEmpty {
            /**
             * Create an empty value. Escape it the same way as the real
             * options so a crafted emptyValue/emptyText cannot inject markup.
             */
            let escaper = <EscaperInterface> BaseTag::getEscaperService();
            let code .= self::echoOption(escaper->attributes(emptyValue))
                . escaper->html(emptyText)
                . "</option>" . PHP_EOL;
        }

        if typeof options == "object" {
            /**
             * Create the SELECT's option from a resultset
             */
            let code .= self::optionsFromResultset(
                options,
                using,
                value,
                "</option>" . PHP_EOL
            );
        } else {
            if typeof options == "array" {
                /**
                 * Create the SELECT's option from an array
                 */
                let code .= self::optionsFromArray(
                    options,
                    value,
                    "</option>" . PHP_EOL
                );
            }
        }

        let code .= "</select>";

        return code;
    }

    protected static function echoOption(string value, bool selected = false) -> string
    {
        string extra;

        let extra = selected ? "selected=\"selected\" " : "";

        return "\t<option " . extra . "value=\"" . value . "\">";
    }

    /**
     * Reduces an arbitrary option value to the string the markup needs.
     * Option data is user supplied, so anything that cannot be expressed as
     * a string reads back as an empty string rather than aborting the tag.
     */
    protected static function toStringValue(var value) -> string
    {
        if (is_scalar(value)
            || (typeof value === "object" && value instanceof Stringable)) {
            return (string) value;
        }

        return "";
    }

    /**
     * Generate the OPTION tags based on an array
     *
     * @phpstan-param tag_select_data $data
     */
    private static function optionsFromArray(
        array data,
        var value,
        string closeOption
    ) -> string {
        var strValue, strOptionValue, code, optionValue, optionText, escaped,
            escapedText, escaper;

        let code    = "",
            escaper = <EscaperInterface> BaseTag::getEscaperService();

        for optionValue, optionText in data {
            let escaped = escaper->attributes(optionValue);

            if typeof optionText == "array" {
                let code .= "\t<optgroup label=\"" . escaped . "\">"
                    . PHP_EOL
                    . self::optionsFromArray(optionText, value, closeOption)
                    . "\t</optgroup>"
                    . PHP_EOL;

                continue;
            }

            let escapedText = escaper->html(self::toStringValue(optionText));

            if typeof value == "array" {
                if in_array(optionValue, value) {
                    let code .= self::echoOption(escaped, true)
                        . escapedText . closeOption;
                } else {
                    let code .= self::echoOption(escaped)
                        . escapedText . closeOption;
                }
            } else {
                let strOptionValue = (string) optionValue,
                    strValue = self::toStringValue(value);

                if strOptionValue === strValue {
                    let code .= self::echoOption(escaped, true)
                        . escapedText . closeOption;
                } else {
                    let code .= self::echoOption(escaped)
                        . escapedText . closeOption;
                }
            }
        }

        return code;
    }

    /**
     * Generate the OPTION tags based on a resultset
     */
    private static function optionsFromResultset(
        <ResultsetInterface> resultset,
        var using,
        var value,
        string closeOption
    ) -> string
    {
        var code, escaper, executed, params, option, usingZero, usingOne,
            optionValue, optionText, strValue, strOptionValue;

        let code = "";
        let params = null;

        if typeof using == "array" {
            if unlikely count(using) != 2 {
                throw new Exception("Parameter 'using' requires two values");
            }

            let usingZero = self::toStringValue(using[0]),
                usingOne  = self::toStringValue(using[1]);
        }

        let escaper = <EscaperInterface> BaseTag::getEscaperService();

        for option in iterator(resultset) {
            if typeof using == "array" {
                if typeof option == "object" {
                    if method_exists(option, "readAttribute") {
                        let optionValue = option->readAttribute(usingZero);
                        let optionText = option->readAttribute(usingOne);
                    } else {
                        let optionValue = option->{usingZero};
                        let optionText = option->{usingOne};
                    }
                } else {
                    if unlikely typeof option != "array" {
                        throw new Exception(
                            "Resultset returned an invalid value"
                        );
                    }

                    let optionValue = option[usingZero];
                    let optionText = option[usingOne];
                }

                let optionValue = escaper->attributes(self::toStringValue(optionValue));
                let optionText = escaper->html(self::toStringValue(optionText));

                /**
                 * If the value is equal to the option's value we mark it as
                 * selected
                 */
                if typeof value == "array" {
                    if in_array(optionValue, value) {
                        let code .= self::echoOption(optionValue, true)
                            . optionText
                            . closeOption;
                    } else {
                        let code .= self::echoOption(optionValue)
                            . optionText
                            . closeOption;
                    }
                } else {
                    let strOptionValue = optionValue,
                        strValue = self::toStringValue(value);

                    if strOptionValue === strValue {
                        let code .= self::echoOption(strOptionValue, true)
                            . optionText
                            . closeOption;
                    } else {
                        let code .= self::echoOption(strOptionValue)
                            . optionText . closeOption;
                    }
                }
            } else {
                /**
                 * Render through the developer-supplied closure. Restricting
                 * this to Closure (rather than any object) keeps the invoked
                 * callable out of reach of user-controlled data: a closure is
                 * defined in application code and can never be a name built
                 * from request input.
                 */
                if using instanceof \Closure {
                    if params === null {
                        let params = [];
                    }

                    let params[0] = option;
                    let executed  = call_user_func_array(using, params);
                    let code .= self::toStringValue(executed);
                }
            }
        }

        return code;
    }
}
