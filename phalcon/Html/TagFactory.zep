
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html;

use Phalcon\Factory\AbstractFactory;
use Phalcon\Html\Escaper\EscaperInterface;
use Phalcon\Html\Helper\Doctype;
use Phalcon\Html\Helper\Input\Checkbox;
use Phalcon\Html\Helper\Input\Color;
use Phalcon\Html\Helper\Input\Date;
use Phalcon\Html\Helper\Input\DateTime;
use Phalcon\Html\Helper\Input\DateTimeLocal;
use Phalcon\Html\Helper\Input\Email;
use Phalcon\Html\Helper\Input\File;
use Phalcon\Html\Helper\Input\Hidden;
use Phalcon\Html\Helper\Input\Image;
use Phalcon\Html\Helper\Input\Input;
use Phalcon\Html\Helper\Input\Month;
use Phalcon\Html\Helper\Input\Numeric;
use Phalcon\Html\Helper\Input\Password;
use Phalcon\Html\Helper\Input\Radio;
use Phalcon\Html\Helper\Input\Range;
use Phalcon\Html\Helper\Input\Search;
use Phalcon\Html\Helper\Input\Select;
use Phalcon\Html\Helper\Input\Submit;
use Phalcon\Html\Helper\Input\Tel;
use Phalcon\Html\Helper\Input\Text;
use Phalcon\Html\Helper\Input\Textarea;
use Phalcon\Html\Helper\Input\Time;
use Phalcon\Html\Helper\Input\Url;
use Phalcon\Html\Helper\Input\Week;
use Phalcon\Html\Helper\Meta;
use Phalcon\Html\Helper\Ol;
use Phalcon\Html\Helper\Script;
use Phalcon\Html\Helper\Style;
use Phalcon\Html\Helper\Title;
use Phalcon\Html\Helper\Ul;
use Phalcon\Html\Link\Link;

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
 * @method string        a(string $href, string $text, array $attributes = [], bool $raw = false)
 * @method string        base(string $href, array $attributes = [])
 * @method string        body(array $attributes = [])
 * @method string        button(string $text, array $attributes = [], bool $raw = false)
 * @method string        close(string $tag, bool $raw = false)
 * @method Doctype       doctype(int $flag, string $delimiter)
 * @method string        element(string $tag, string $text, array $attributes = [], bool $raw = false)
 * @method string        form(array $attributes = [])
 * @method string        img(string $src, array $attributes = [])
 * @method Checkbox      inputCheckbox(string $name, string $value = null, array $attributes = [])
 * @method Color         inputColor(string $name, string $value = null, array $attributes = [])
 * @method Date          inputDate(string $name, string $value = null, array $attributes = [])
 * @method DateTime      inputDateTime(string $name, string $value = null, array $attributes = [])
 * @method DateTimeLocal inputDateTimeLocal(string $name, string $value = null, array $attributes = [])
 * @method Email         inputEmail(string $name, string $value = null, array $attributes = [])
 * @method File          inputFile(string $name, string $value = null, array $attributes = [])
 * @method Hidden        inputHidden(string $name, string $value = null, array $attributes = [])
 * @method Image         inputImage(string $name, string $value = null, array $attributes = [])
 * @method Input         inputInput(string $name, string $value = null, array $attributes = [])
 * @method Month         inputMonth(string $name, string $value = null, array $attributes = [])
 * @method Numeric       inputNumeric(string $name, string $value = null, array $attributes = [])
 * @method Password      inputPassword(string $name, string $value = null, array $attributes = [])
 * @method Radio         inputRadio(string $name, string $value = null, array $attributes = [])
 * @method Range         inputRange(string $name, string $value = null, array $attributes = [])
 * @method Search        inputSearch(string $name, string $value = null, array $attributes = [])
 * @method Select        inputSelect(string $name, string $value = null, array $attributes = [])
 * @method Submit        inputSubmit(string $name, string $value = null, array $attributes = [])
 * @method Tel           inputTel(string $name, string $value = null, array $attributes = [])
 * @method Text          inputText(string $name, string $value = null, array $attributes = [])
 * @method Textarea      inputTextarea(string $name, string $value = null, array $attributes = [])
 * @method Time          inputTime(string $name, string $value = null, array $attributes = [])
 * @method Url           inputUrl(string $name, string $value = null, array $attributes = [])
 * @method Week          inputWeek(string $name, string $value = null, array $attributes = [])
 * @method string        label(string $label, array $attributes = [], bool $raw = false)
 * @method Link          link(string $indent = '    ', string $delimiter = PHP_EOL)
 * @method Meta          meta(string $indent = '    ', string $delimiter = PHP_EOL)
 * @method Ol            ol(string $text, array $attributes = [], bool $raw = false)
 * @method Script        script(string $indent = '    ', string $delimiter = PHP_EOL)
 * @method Stype         style(string $indent = '    ', string $delimiter = PHP_EOL)
 * @method Title         title(string $indent = '    ', string $delimiter = PHP_EOL)
 * @method Ul            ul(string $text, array $attributes = [], bool $raw = false)
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
