
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Debug;

use InvalidArgumentException;
use JsonException;
use Phalcon\Container\Container;
use Phalcon\Contracts\Support\Debug\TemplateAware;
use Phalcon\Contracts\Support\SupportTypes;
use Phalcon\Di\DiInterface;
use Phalcon\Support\Debug\Traits\TemplateAwareTrait;
use Phalcon\Support\Helper\Json\Encode;
use Phalcon\Traits\Support\Helper\Str\InterpolateTrait;
use Reflection;
use ReflectionClass;
use ReflectionException;
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
 *
 * @phpstan-import-type support_debug_styles from SupportTypes
 */
class Dump implements TemplateAware
{
    use InterpolateTrait;
    use TemplateAwareTrait;

    protected bool detailed = false;
    /**
     * @var array<array-key, class-string>
     */
    protected array methods = [];
    /**
     * @phpstan-var support_debug_styles
     */
    protected array styles = [];
    private <Encode> encode;

    /**
     * Dump constructor.
     *
     * @phpstan-param support_debug_styles $styles
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
     * Alias of variable() method
     *
     * @throws ReflectionException
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
     *
     * @phpstan-param  support_debug_styles $styles
     * @phpstan-return support_debug_styles
     */
    public function setStyles( array styles = []) -> array
    {
        var defaultStyles;

        let defaultStyles = [
            "pre"   : "background-color:#f3f3f3; font-size:11px; " .
                "padding:10px; border:1px solid #ccc; " .
                "text-align:left; color:#333",
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
     *
     * @throws InvalidArgumentException
     * @throws JsonException
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
     *
     * @throws ReflectionException
     */
    public function variable(var variable, string name = null) -> string
    {
        var message;
        array context;
        
        let message = this->getTemplate("pre");
        let context = [
            "style"  : this->getStyle("pre"),
            "output" : this->output(variable, name)
        ];

        return this->toInterpolate(message, context);
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
     *
     * @throws ReflectionException
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
     *
     * @throws ReflectionException
     */
    protected function output(
        var variable,
        string name = null,
        int tab = 1
    ) -> string {
        var attr, key, message, 
            output = "",
            property, props, reflect, type, value,vars;
        array context = [];
        string space  = "  ";

        if (!empty(name)) {
            let output .= name . " ";
        }

        if (typeof variable === "array") {
            let message = this->getTemplate("arrayHeader");
            let context = [
                "style" : this->getStyle("arr"),
                "count" : count(variable)
            ];

            let output .= this->toInterpolate(message, context);
            for key, value in variable {
                let output .= str_repeat(space, tab);

                let message = this->getTemplate("arrayKey");
                let context = [
                    "style" : this->getStyle("arr"),
                    "key"   : key
                ];
                let output  .= this->toInterpolate(message, context);

                if (
                    1 === tab &&
                    !empty(name) &&
                    typeof key !== "int" &&
                    name === key
                ) {
                    continue;
                }

                let output .= this->output(value, "", tab + 1) . "\n";
            }

            return output . str_repeat(space, tab - 1) . ")";
        }

        if (is_object(variable)) {
            let message = this->getTemplate("objectHeader");
            let context = [
                "style" : this->getStyle("obj"),
                "class" : get_class(variable)
            ];
            let output  .= this->toInterpolate(message, context);

            if (false !== get_parent_class(variable)) {
                let message = this->getTemplate("objectExtends");
                let context = [
                    "style"  : this->getStyle("obj"),
                    "parent" : get_parent_class(variable)
                ];
                let output  .= this->toInterpolate(message, context);
            }

            let output .= " (\n";

            if (
                typeof variable === "object" &&
                (variable instanceof DiInterface || variable instanceof Container)
            ) {
                // Skip debugging di and container
                let output .= str_repeat(space, tab) . "[skipped]\n";
            } elseif (true !== this->detailed || variable instanceof stdClass) {
                // Debug only public properties
                let vars = get_object_vars(variable);
                for key, value in vars {
                    let message = this->getTemplate("objectProperty");
                    let context = [
                        "style" : this->getStyle("obj"),
                        "key"   : key,
                        "type"  : "public"
                    ];

                    let output .= str_repeat(space, tab)
                        . this->toInterpolate(message, context)
                        . this->output(value, "", tab + 1)
                        . "\n";
                }
            } else {
                // Debug all properties
                let reflect = new ReflectionClass(variable);
                let props   = reflect->getProperties(
                    ReflectionProperty::IS_PUBLIC |
                    ReflectionProperty::IS_PROTECTED |
                    ReflectionProperty::IS_PRIVATE
                );

                for property in props {
                    let key  = property->getName();
                    let type = implode(
                        " ",
                        Reflection::getModifierNames(property->getModifiers())
                    );

                    let message = this->getTemplate("objectProperty");
                    let context = [
                        "style" : this->getStyle("obj"),
                        "key"   : key,
                        "type"  : type
                    ];

                    let output .= str_repeat(space, tab)
                        . this->toInterpolate(message, context)
                        . this->output(property->getValue(variable), "", tab + 1)
                        . "\n";
                }
            }

            let attr    = get_class_methods(variable);
            let message = this->getTemplate("objectMethods");
            let context = [
                "style" : this->getStyle("obj"),
                "class" : get_class(variable),
                "count" : count(attr)
            ];

            let output .= str_repeat(space, tab)
                . this->toInterpolate(message, context);


            if (true === in_array(get_class(variable), this->methods)) {
                let output .= str_repeat(space, tab) . "[already listed]\n";
            } else {
                for value in attr {
                    let this->methods[] = get_class(variable);

                    let message = this->getTemplate("objectMethod");
                    if ("__construct" === value) {
                        let message = this->getTemplate("objectMethodConstructor");
                    }
                    let context = [
                        "style"  : this->getStyle("obj"),
                        "method" : value
                    ];

                    let output .= str_repeat(space, tab + 1)
                        . this->toInterpolate(message, context);
                }

                let output .= str_repeat(space, tab) . ")\n";
            }

            return output . str_repeat(space, tab - 1) . ")";
        }

        if (typeof variable === "int") {
            let message = this->getOutputBold("Integer") . " " . this->getTemplate("varParens");
            let context = [
                "style" : this->getStyle("int"),
                "var"   : variable
            ];

            return output . this->toInterpolate(message, context);
        }

        if (typeof variable === "float") {
            let message = this->getOutputBold("Float") . " " . this->getTemplate("varParens");
            let context = [
                "style" : this->getStyle("float"),
                "var"   : variable
            ];

            return output . this->toInterpolate(message, context);
        }

        if (is_numeric(variable)) {
            let message = this->getOutputBold("Numeric String") . " " . this->getTemplate("lengthValue");
            let context = [
                "style"  : this->getStyle("num"),
                "length" : mb_strlen((string)variable),
                "var"    : variable
            ];

            return output . this->toInterpolate(message, context);
        }

        if (typeof variable === "string") {
            let message = this->getOutputBold("String") . " " . this->getTemplate("lengthValue");
            let context = [
                "style"  : this->getStyle("str"),
                "length" : mb_strlen(variable),
                "var"    : nl2br(htmlentities(variable, ENT_IGNORE, "utf-8"))
            ];

            return output . this->toInterpolate(message, context);
        }

        if (typeof variable === "bool") {
            let message = this->getOutputBold("Boolean") . " " . this->getTemplate("varParens");
            let context = [
                "style" : this->getStyle("bool"),
                "var"   : (variable) ? "TRUE" : "FALSE"
            ];

            return output . this->toInterpolate(message, context);
        }

        if (null === variable) {
            let message = this->getOutputBold("NULL");
            let context = [
                "style" : this->getStyle("null")
            ];

            return output . this->toInterpolate(message, context);
        }

        let message = this->getTemplate("varParens");
        let context = [
            "style" : this->getStyle("other"),
            "var"   : variable
        ];

        return output . this->toInterpolate(message, context);
    }

    /**
     * @param string $text
     *
     * @return string
     */
    private function getOutputBold(string text) -> string
    {
        return this->toInterpolate(
            this->getTemplate("bold"),
            ["text": text]
        );
    }
}
