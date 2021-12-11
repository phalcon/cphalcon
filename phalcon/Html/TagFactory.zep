
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html;

use Phalcon\Html\Escaper;
use Phalcon\Html\Escaper\EscaperInterface;
use Phalcon\Factory\AbstractFactory;

/**
 * ServiceLocator implementation for Tag helpers.
 *
 * Services are registered using the constructor using a key-value pair. The
 * key is the name of the tag helper, while the value is a callable that returns
 * the object.
 *
 * The class implements `__call()` to allow calling helper objects as methods.
 *
 * @property EscaperInterface $escaper
 * @property array            $services
 *
 * @method a(string $href, string $text, array $attributes = [], bool $raw = false): string
 * @method base(string $href, array $attributes = []): string
 * @method body(array $attributes = []): string
 * @method button(string $text, array $attributes = [], bool $raw = false): string
 * @method close(string $tag, bool $raw = false): string
 * @method doctype(int $flag, string $delimiter): string
 * @method element(string $tag, string $text, array $attributes = [], bool $raw = false): string
 * @method form(array $attributes = []): string
 * @method img(string $src, array $attributes = []): string
 * @method inputCheckbox(string $name, string $value = null, array $attributes = []): string
 * @method inputColor(string $name, string $value = null, array $attributes = []): string
 * @method inputDate(string $name, string $value = null, array $attributes = []): string
 * @method inputDateTime(string $name, string $value = null, array $attributes = []): string
 * @method inputDateTimeLocal(string $name, string $value = null, array $attributes = []): string
 * @method inputEmail(string $name, string $value = null, array $attributes = []): string
 * @method inputFile(string $name, string $value = null, array $attributes = []): string
 * @method inputHidden(string $name, string $value = null, array $attributes = []): string
 * @method inputImage(string $name, string $value = null, array $attributes = []): string
 * @method inputInput(string $name, string $value = null, array $attributes = []): string
 * @method inputMonth(string $name, string $value = null, array $attributes = []): string
 * @method inputNumeric(string $name, string $value = null, array $attributes = []): string
 * @method inputPassword(string $name, string $value = null, array $attributes = []): string
 * @method inputRadio(string $name, string $value = null, array $attributes = []): string
 * @method inputRange(string $name, string $value = null, array $attributes = []): string
 * @method inputSearch(string $name, string $value = null, array $attributes = []): string
 * @method inputSelect(string $name, string $value = null, array $attributes = []): string
 * @method inputSubmit(string $name, string $value = null, array $attributes = []): string
 * @method inputTel(string $name, string $value = null, array $attributes = []): string
 * @method inputText(string $name, string $value = null, array $attributes = []): string
 * @method inputTextarea(string $name, string $value = null, array $attributes = []): string
 * @method inputTime(string $name, string $value = null, array $attributes = []): string
 * @method inputUrl(string $name, string $value = null, array $attributes = []): string
 * @method inputWeek(string $name, string $value = null, array $attributes = []): string
 * @method label(array $attributes = []): string
 * @method link(string $indent = '    ', string $delimiter = PHP_EOL): string
 * @method meta(string $indent = '    ', string $delimiter = PHP_EOL): string
 * @method ol(string $text, array $attributes = [], bool $raw = false): string
 * @method script(string $indent = '    ', string $delimiter = PHP_EOL): string
 * @method style(string $indent = '    ', string $delimiter = PHP_EOL): string
 * @method title(string $separator = '', string $indent = '', string $delimiter = PHP_EOL): string
 * @method ul(string $text, array $attributes = [], bool $raw = false): string
 */
class TagFactory extends AbstractFactory
{
    /**
     * @var EscaperInterface
     */
    private escaper;

    /**
     * @var array
     */
    protected services = [];

    /**
     * TagFactory constructor.
     *
     * @param Escaper $escaper
     * @param array   $services
     */
    public function __construct(<EscaperInterface> escaper, array! services = [])
    {
        let this->escaper = escaper;

        this->init(services);
    }

    /**
     * Magic call to make the helper objects available as methods.
     *
     * @param string $name
     * @param array  $arguments
     *
     * @return false|mixed
     */
    public function __call(string name, array arguments)
    {
        var helper;

        let helper = this->newInstance(name);

        return call_user_func_array([helper, "__invoke"], arguments);
    }

    /**
     * @param string $name
     *
     * @return bool
     */
    public function has(string name) -> bool
    {
        return isset(this->mapper[name]);
    }

    /**
     * Create a new instance of the object
     *
     * @param string $name
     *
     * @return mixed
     * @throws Exception
     */
    public function newInstance(string name) -> var
    {
        var definition;

        if !isset this->services[name] {
            let definition           = this->getService(name),
                this->services[name] = create_instance_params(
                    definition,
                    [
                        this->escaper
                    ]
                );
        }

        return this->services[name];
    }

    /**
     * @param string   $name
     * @param callable $method
     */
    public function set(string name, var method) -> void
    {
        let this->mapper[name] = method;
        unset(this->services[name]);
    }

    /**
     * @return string
     */
    protected function getExceptionClass() -> string
    {
        return "Phalcon\\Html\\Exception";
    }

    /**
     * Returns the available services
     *
     * @return string[]
     */
    protected function getServices() -> array
    {
        return [
            "a"                  : "Phalcon\\Html\\Helper\\Anchor",
            "base"               : "Phalcon\\Html\\Helper\\Base",
            "body"               : "Phalcon\\Html\\Helper\\Body",
            "button"             : "Phalcon\\Html\\Helper\\Button",
            "close"              : "Phalcon\\Html\\Helper\\Close",
            "doctype"            : "Phalcon\\Html\\Helper\\Doctype",
            "element"            : "Phalcon\\Html\\Helper\\Element",
            "form"               : "Phalcon\\Html\\Helper\\Form",
            "img"                : "Phalcon\\Html\\Helper\\Img",
            "inputCheckbox"      : "Phalcon\\Html\\Helper\\Input\\Checkbox",
            "inputColor"         : "Phalcon\\Html\\Helper\\Input\\Color",
            "inputDate"          : "Phalcon\\Html\\Helper\\Input\\Date",
            "inputDateTime"      : "Phalcon\\Html\\Helper\\Input\\DateTime",
            "inputDateTimeLocal" : "Phalcon\\Html\\Helper\\Input\\DateTimeLocal",
            "inputEmail"         : "Phalcon\\Html\\Helper\\Input\\Email",
            "inputFile"          : "Phalcon\\Html\\Helper\\Input\\File",
            "inputHidden"        : "Phalcon\\Html\\Helper\\Input\\Hidden",
            "inputImage"         : "Phalcon\\Html\\Helper\\Input\\Image",
            "inputInput"         : "Phalcon\\Html\\Helper\\Input\\Input",
            "inputMonth"         : "Phalcon\\Html\\Helper\\Input\\Month",
            "inputNumeric"       : "Phalcon\\Html\\Helper\\Input\\Numeric",
            "inputPassword"      : "Phalcon\\Html\\Helper\\Input\\Password",
            "inputRadio"         : "Phalcon\\Html\\Helper\\Input\\Radio",
            "inputRange"         : "Phalcon\\Html\\Helper\\Input\\Range",
            "inputSearch"        : "Phalcon\\Html\\Helper\\Input\\Search",
            "inputSelect"        : "Phalcon\\Html\\Helper\\Input\\Select",
            "inputSubmit"        : "Phalcon\\Html\\Helper\\Input\\Submit",
            "inputTel"           : "Phalcon\\Html\\Helper\\Input\\Tel",
            "inputText"          : "Phalcon\\Html\\Helper\\Input\\Text",
            "inputTextarea"      : "Phalcon\\Html\\Helper\\Input\\Textarea",
            "inputTime"          : "Phalcon\\Html\\Helper\\Input\\Time",
            "inputUrl"           : "Phalcon\\Html\\Helper\\Input\\Url",
            "inputWeek"          : "Phalcon\\Html\\Helper\\Input\\Week",
            "label"              : "Phalcon\\Html\\Helper\\Label",
            "link"               : "Phalcon\\Html\\Helper\\Link",
            "meta"               : "Phalcon\\Html\\Helper\\Meta",
            "ol"                 : "Phalcon\\Html\\Helper\\Ol",
            "script"             : "Phalcon\\Html\\Helper\\Script",
            "style"              : "Phalcon\\Html\\Helper\\Style",
            "title"              : "Phalcon\\Html\\Helper\\Title",
            "ul"                 : "Phalcon\\Html\\Helper\\Ul"
        ];
    }
}
