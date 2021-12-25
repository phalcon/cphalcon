
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Debug;

use InvalidArgumentException; // @todo this will also be removed when traits are available
use Phalcon\Di\Di;
use Reflection;
use ReflectionClass;
use ReflectionProperty;
use stdClass;

/**
 * Dumps information about a variable(s)
 *
 * ```php
 * $foo = 123;
 *
 * echo (new \Phalcon\Debug\Dump())->variable($foo, "foo");
 * ```
 *
 * ```php
 * $foo = "string";
 * $bar = ["key" => "value"];
 * $baz = new stdClass();
 *
 * echo (new \Phalcon\Debug\Dump())->variables($foo, $bar, $baz);
 * ```
 */
class Dump
{
    /**
     * @var bool
     */
    protected detailed = false { get, set };

    /**
     * @var array
     */
    protected methods = [];

    /**
     * @var array
     */
    protected styles = [];

    /**
     * Phalcon\Debug\Dump constructor
     */
    public function __construct(array! styles = [], bool detailed = false)
    {
        this->setStyles(styles);

        let this->detailed = detailed;
    }


    /**
     * Alias of variables() method
     */
    public function all() -> string
    {
        return call_user_func_array(
            [
                this,
                "variables"
            ],
            func_get_args()
        );
    }

    /**
     * Alias of variable() method
     */
    public function one(var variable, string name = null) -> string
    {
        return this->variable(variable, name);
    }

    /**
     * Set styles for vars type
     */
    public function setStyles(array! styles = []) -> array
    {
        var defaultStyles;

        let defaultStyles = [
            "pre"   : "background-color:#f3f3f3; font-size:11px; padding:10px; border:1px solid #ccc; text-align:left; color:#333",
            "arr"   : "color:red",
            "bool"  : "color:green",
            "float" : "color:fuchsia",
            "int"   : "color:blue",
            "null"  : "color:black",
            "num"   : "color:navy",
            "obj"   : "color:purple",
            "other" : "color:maroon",
            "res"   : "color:lime",
            "str"   : "color:teal"
        ];

        let this->styles = array_merge(defaultStyles, styles);

        return this->styles;
    }

    /**
     * Returns an JSON string of information about a single variable.
     *
     * ```php
     * $foo = [
     *     "key" => "value",
     * ];
     *
     * echo (new \Phalcon\Debug\Dump())->toJson($foo);
     *
     * $foo = new stdClass();
     * $foo->bar = "buz";
     *
     * echo (new \Phalcon\Debug\Dump())->toJson($foo);
     * ```
     */
    public function toJson(var variable) -> string
    {
        return this->encode(
            variable,
            JSON_PRETTY_PRINT | JSON_UNESCAPED_SLASHES | JSON_UNESCAPED_UNICODE
        );
    }

    /**
     * Returns an HTML string of information about a single variable.
     *
     * ```php
     * echo (new \Phalcon\Debug\Dump())->variable($foo, "foo");
     * ```
     */
    public function variable(var variable, string name = null) -> string
    {
        return strtr(
            "<pre style=\":style\">:output</pre>",
            [
                ":style":  this->getStyle("pre"),
                ":output": this->output(variable, name)
            ]
        );
    }

    /**
     * Returns an HTML string of debugging information about any number of
     * variables, each wrapped in a "pre" tag.
     *
     * ```php
     * $foo = "string";
     * $bar = ["key" => "value"];
     * $baz = new stdClass();
     *
     * echo (new \Phalcon\Debug\Dump())->variables($foo, $bar, $baz);
     * ```
     */
    public function variables() -> string
    {
        var key, value;
        string output;

        let output = "";

        for key, value in func_get_args() {
            let output .= this->one(
                value,
                "var " . key
            );
        }

        return output;
    }

    /**
     * Get style for type
     */
    protected function getStyle(string! type) -> string
    {
        var style;

        if !fetch style, this->styles[type] {
            return "color:gray";
        }

        return style;
    }

    /**
     * Prepare an HTML string of information about a single variable.
     */
    protected function output(var variable, string name = null, int tab = 1) -> string
    {
        var key, value, output, space, type, attr;

        let space = "  ",
            output = "";

        if name {
            let output = name . " ";
        }

        if typeof variable == "array" {
            let output .= strtr(
                "<b style=\":style\">Array</b> (<span style=\":style\">:count</span>) (\n",
                [
                    ":style": this->getStyle("arr"),
                    ":count": count(variable)
                ]
            );

            for key, value in variable {
                let output .= str_repeat(space, tab) . strtr("[<span style=\":style\">:key</span>] => ", [":style": this->getStyle("arr"), ":key": key]);

                if tab == 1 && name != "" && !is_int(key) && name == key {
                    continue;
                }

                let output .= this->output(value, "", tab + 1) . "\n";
            }

            return output . str_repeat(space, tab - 1) . ")";
        }

        if typeof variable == "object" {
            let output .= strtr(
                "<b style=\":style\">Object</b> :class",
                [
                    ":style": this->getStyle("obj"),
                    ":class": get_class(variable)
                ]
            );

            if get_parent_class(variable) {
                let output .= strtr(
                    " <b style=\":style\">extends</b> :parent",
                    [
                        ":style": this->getStyle("obj"),
                        ":parent": get_parent_class(variable)
                    ]
                );
            }
            let output .= " (\n";

            if variable instanceof Di {
                // Skip debugging di
                let output .= str_repeat(space, tab) . "[skipped]\n";
            } elseif !this->detailed || variable instanceof stdClass {
                // Debug only public properties
                for key, value in get_object_vars(variable) {
                    let output .= str_repeat(space, tab) . strtr("-><span style=\":style\">:key</span> (<span style=\":style\">:type</span>) = ", [":style": this->getStyle("obj"), ":key": key, ":type": "public"]);
                    let output .= this->output(value, "", tab + 1) . "\n";
                }
            } else {
                // Debug all properties
                var reflect, props, property;

                let reflect = new ReflectionClass(variable);
                let props = reflect->getProperties(
                    ReflectionProperty::IS_PUBLIC |
                    ReflectionProperty::IS_PROTECTED |
                    ReflectionProperty::IS_PRIVATE
                );

                for property in props {
                    property->setAccessible(true);

                    let key = property->getName();

                    let type = implode(
                        " ",
                        Reflection::getModifierNames(
                            property->getModifiers()
                        )
                    );

                    let output .= str_repeat(space, tab) . strtr("-><span style=\":style\">:key</span> (<span style=\":style\">:type</span>) = ", [":style": this->getStyle("obj"), ":key": key, ":type": type]);
                    let output .= this->output(property->getValue(variable), "", tab + 1) . "\n";
                }
            }

            let attr = get_class_methods(variable);
            let output .= str_repeat(space, tab) . strtr(":class <b style=\":style\">methods</b>: (<span style=\":style\">:count</span>) (\n", [":style": this->getStyle("obj"), ":class": get_class(variable), ":count": count(attr)]);

            if in_array(get_class(variable), this->methods) {
                let output .= str_repeat(space, tab) . "[already listed]\n";
            } else {
                for value in attr {
                    let this->methods[] = get_class(variable);

                    if value == "__construct" {
                        let output .= str_repeat(space, tab + 1) . strtr("-><span style=\":style\">:method</span>(); [<b style=\":style\">constructor</b>]\n", [":style": this->getStyle("obj"), ":method": value]);
                    } else {
                        let output .= str_repeat(space, tab + 1) . strtr("-><span style=\":style\">:method</span>();\n", [":style": this->getStyle("obj"), ":method": value]);
                    }
                }

                let output .= str_repeat(space, tab) . ")\n";
            }

            return output . str_repeat(space, tab - 1) . ")";
        }

        if is_int(variable) {
            return output . strtr("<b style=\":style\">Integer</b> (<span style=\":style\">:var</span>)", [":style": this->getStyle("int"), ":var": variable]);
        }

        if is_float(variable) {
            return output . strtr("<b style=\":style\">Float</b> (<span style=\":style\">:var</span>)", [":style": this->getStyle("float"), ":var": variable]);
        }

        if is_numeric(variable) {
            return output . strtr("<b style=\":style\">Numeric string</b> (<span style=\":style\">:length</span>) \"<span style=\":style\">:var</span>\"", [":style": this->getStyle("num"), ":length": strlen(variable), ":var": variable]);
        }

        if is_string(variable) {
            return output . strtr("<b style=\":style\">String</b> (<span style=\":style\">:length</span>) \"<span style=\":style\">:var</span>\"", [":style": this->getStyle("str"), ":length": strlen(variable), ":var": nl2br(htmlentities(variable, ENT_IGNORE, "utf-8"))]);
        }

        if is_bool(variable) {
            return output . strtr("<b style=\":style\">Boolean</b> (<span style=\":style\">:var</span>)", [":style": this->getStyle("bool"), ":var": (variable ? "TRUE" : "FALSE")]);
        }

        if is_null(variable) {
            return output . strtr("<b style=\":style\">NULL</b>", [":style": this->getStyle("null")]);
        }

        return output . strtr("(<span style=\":style\">:var</span>)", [":style": this->getStyle("other"), ":var": variable]);
    }

    /**
     * @todo This will be removed when traits are introduced
     */
    private function encode(
        var data,
        int options = 0,
        int depth = 512
    ) -> string
    {
        var encoded;

        let encoded = json_encode(data, options, depth);

        if unlikely JSON_ERROR_NONE !== json_last_error() {
            throw new InvalidArgumentException(
                "json_encode error: " . json_last_error_msg()
            );
        }

        return encoded;
    }
}
