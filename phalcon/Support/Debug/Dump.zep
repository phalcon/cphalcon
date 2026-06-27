
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Debug;

use Phalcon\Contracts\Support\Debug\TemplateAware;
use Phalcon\Di\DiInterface;
use Phalcon\Support\Helper\Json\Encode;
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
class Dump implements TemplateAware
{
    /**
     * @var bool
     */
    protected detailed = false;

    /**
     * @var array
     */
    protected methods = [];

    /**
     * @var array
     */
    protected styles = [];

    /**
     * Template overrides keyed by name.
     *
     * @todo Move getTemplate()/setTemplate()/templates into a shared trait once
     *       Zephir supports traits (mirrors
     *       Phalcon\Support\Debug\Traits\TemplateAwareTrait in the PHP source).
     *
     * @var array
     */
    protected templates = [];

    /**
     * @var Encode
     */
    private encode;

    /**
     * Phalcon\Debug\Dump constructor
     */
    public function __construct( array styles = [], bool detailed = false)
    {
        let this->encode = new Encode();

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

    public function getDetailed() -> bool
    {
        return this->detailed;
    }

    /**
     * Returns the template for the given name (override if set, default
     * otherwise).
     *
     * @param string $name
     *
     * @return string
     */
    public function getTemplate(string name) -> string
    {
        var template;

        if fetch template, this->templates[name] {
            return template;
        }

        return this->defaultTemplate(name);
    }

    /**
     * Alias of variable() method
     */
    public function one(var variable, string name = null) -> string
    {
        return this->variable(variable, name);
    }

    public function setDetailed(bool flag) -> void
    {
        let this->detailed = flag;
    }

    /**
     * Set styles for vars type
     */
    public function setStyles( array styles = []) -> array
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
     * Overrides the template for the given name.
     *
     * @param string $name
     * @param string $template
     *
     * @return static
     */
    public function setTemplate(string name, string template) -> <static>
    {
        let this->templates[name] = template;

        return this;
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
        return this->encode->__invoke(
            variable,
            JSON_PRETTY_PRINT | JSON_UNESCAPED_SLASHES | JSON_UNESCAPED_UNICODE | JSON_THROW_ON_ERROR
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
            this->getTemplate("pre"),
            [
                "%style%":  this->getStyle("pre"),
                "%output%": this->output(variable, name)
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
     * Returns the embedded default template for the given name.
     *
     * @param string $name
     *
     * @return string
     */
    protected function defaultTemplate(string name) -> string
    {
        var defaults, template;

        let defaults = [
            "pre"                     : "<pre style=\"%style%\">%output%</pre>",
            "bold"                    : "<b style=\"%style%\">%text%</b>",
            "varParens"               : "(<span style=\"%style%\">%var%</span>)",
            "lengthValue"             : "(<span style=\"%style%\">%length%</span>) \"<span style=\"%style%\">%var%</span>\"",
            "arrayHeader"             : "<b style=\"%style%\">Array</b> (<span style=\"%style%\">%count%</span>) (\n",
            "arrayKey"                : "[<span style=\"%style%\">%key%</span>] => ",
            "objectHeader"            : "<b style=\"%style%\">Object</b> %class%",
            "objectExtends"           : " <b style=\"%style%\">extends</b> %parent%",
            "objectProperty"          : "-><span style=\"%style%\">%key%</span> (<span style=\"%style%\">%type%</span>) = ",
            "objectMethods"           : "%class% <b style=\"%style%\">methods</b>: (<span style=\"%style%\">%count%</span>) (\n",
            "objectMethod"            : "-><span style=\"%style%\">%method%</span>();\n",
            "objectMethodConstructor" : "-><span style=\"%style%\">%method%</span>(); [<b style=\"%style%\">constructor</b>]\n"
        ];

        if fetch template, defaults[name] {
            return template;
        }

        return "";
    }

    /**
     * Get style for type
     */
    protected function getStyle( string type) -> string
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
        var key, value, output, space, type, attr, reflect, props, property;

        let space = "  ",
            output = "";

        if name {
            let output = name . " ";
        }

        if typeof variable == "array" {
            let output .= strtr(
                this->getTemplate("arrayHeader"),
                [
                    "%style%": this->getStyle("arr"),
                    "%count%": count(variable)
                ]
            );

            for key, value in variable {
                let output .= str_repeat(space, tab)
                    . strtr(
                        this->getTemplate("arrayKey"),
                        ["%style%": this->getStyle("arr"), "%key%": key]
                    );

                if tab == 1 && name != "" && !is_int(key) && name == key {
                    continue;
                }

                let output .= this->output(value, "", tab + 1) . "\n";
            }

            return output . str_repeat(space, tab - 1) . ")";
        }

        if typeof variable == "object" {
            let output .= strtr(
                this->getTemplate("objectHeader"),
                [
                    "%style%": this->getStyle("obj"),
                    "%class%": get_class(variable)
                ]
            );

            if get_parent_class(variable) {
                let output .= strtr(
                    this->getTemplate("objectExtends"),
                    [
                        "%style%":  this->getStyle("obj"),
                        "%parent%": get_parent_class(variable)
                    ]
                );
            }

            let output .= " (\n";

            if variable instanceof DiInterface {
                // Skip debugging di
                let output .= str_repeat(space, tab) . "[skipped]\n";
            } elseif !this->detailed || variable instanceof stdClass {
                // Debug only public properties
                for key, value in get_object_vars(variable) {
                    let output .= str_repeat(space, tab)
                        . strtr(
                            this->getTemplate("objectProperty"),
                            ["%style%": this->getStyle("obj"), "%key%": key, "%type%": "public"]
                        );
                    let output .= this->output(value, "", tab + 1) . "\n";
                }
            } else {
                // Debug all properties
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

                    let output .= str_repeat(space, tab)
                        . strtr(
                            this->getTemplate("objectProperty"),
                            ["%style%": this->getStyle("obj"), "%key%": key, "%type%": type]
                        );
                    let output .= this->output(property->getValue(variable), "", tab + 1) . "\n";
                }
            }

            let attr = get_class_methods(variable);
            let output .= str_repeat(space, tab)
                . strtr(
                    this->getTemplate("objectMethods"),
                    ["%style%": this->getStyle("obj"), "%class%": get_class(variable), "%count%": count(attr)]
                );

            if in_array(get_class(variable), this->methods) {
                let output .= str_repeat(space, tab) . "[already listed]\n";
            } else {
                for value in attr {
                    let this->methods[] = get_class(variable);

                    if value == "__construct" {
                        let output .= str_repeat(space, tab + 1)
                            . strtr(
                                this->getTemplate("objectMethodConstructor"),
                                ["%style%": this->getStyle("obj"), "%method%": value]
                            );
                    } else {
                        let output .= str_repeat(space, tab + 1)
                            . strtr(
                                this->getTemplate("objectMethod"),
                                ["%style%": this->getStyle("obj"), "%method%": value]
                            );
                    }
                }

                let output .= str_repeat(space, tab) . ")\n";
            }

            return output . str_repeat(space, tab - 1) . ")";
        }

        if is_int(variable) {
            return output . strtr(
                this->getOutputBold("Integer") . " " . this->getTemplate("varParens"),
                ["%style%": this->getStyle("int"), "%var%": variable]
            );
        }

        if is_float(variable) {
            return output . strtr(
                this->getOutputBold("Float") . " " . this->getTemplate("varParens"),
                ["%style%": this->getStyle("float"), "%var%": variable]
            );
        }

        if is_numeric(variable) {
            return output . strtr(
                this->getOutputBold("Numeric String") . " " . this->getTemplate("lengthValue"),
                ["%style%": this->getStyle("num"), "%length%": mb_strlen(variable), "%var%": variable]
            );
        }

        if is_string(variable) {
            return output . strtr(
                this->getOutputBold("String") . " " . this->getTemplate("lengthValue"),
                [
                    "%style%":  this->getStyle("str"),
                    "%length%": mb_strlen(variable),
                    "%var%":    nl2br(htmlentities(variable, ENT_IGNORE, "utf-8"))
                ]
            );
        }

        if is_bool(variable) {
            return output . strtr(
                this->getOutputBold("Boolean") . " " . this->getTemplate("varParens"),
                ["%style%": this->getStyle("bool"), "%var%": (variable ? "TRUE" : "FALSE")]
            );
        }

        if is_null(variable) {
            return output . strtr(
                this->getOutputBold("NULL"),
                ["%style%": this->getStyle("null")]
            );
        }

        return output . strtr(
            this->getTemplate("varParens"),
            ["%style%": this->getStyle("other"), "%var%": variable]
        );
    }

    /**
     * @param string $text
     *
     * @return string
     */
    private function getOutputBold(string text) -> string
    {
        return strtr(
            this->getTemplate("bold"),
            ["%text%": text]
        );
    }
}
