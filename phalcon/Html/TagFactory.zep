
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
 */

namespace Phalcon\Html;

use Phalcon\Html\Escaper\EscaperInterface;
use Phalcon\Html\Helper\Anchor;
use Phalcon\Html\Helper\Base;
use Phalcon\Html\Helper\Body;
use Phalcon\Html\Helper\Breadcrumbs;
use Phalcon\Html\Helper\Button;
use Phalcon\Html\Helper\Close;
use Phalcon\Html\Helper\Doctype;
use Phalcon\Html\Helper\Element;
use Phalcon\Html\Helper\Form;
use Phalcon\Html\Helper\FriendlyTitle;
use Phalcon\Html\Helper\Img;
use Phalcon\Html\Helper\Input\Checkbox;
use Phalcon\Html\Helper\Input\Generic;
use Phalcon\Html\Helper\Input\Radio;
use Phalcon\Html\Helper\Input\Select;
use Phalcon\Html\Helper\Input\Textarea;
use Phalcon\Html\Helper\Label;
use Phalcon\Html\Helper\Link;
use Phalcon\Html\Helper\Meta;
use Phalcon\Html\Helper\Ol;
use Phalcon\Html\Helper\Preload;
use Phalcon\Html\Helper\Script;
use Phalcon\Html\Helper\Style;
use Phalcon\Html\Helper\Tag;
use Phalcon\Html\Helper\Title;
use Phalcon\Html\Helper\Ul;
use Phalcon\Html\Helper\VoidTag;
use Phalcon\Http\ResponseInterface;
use Phalcon\Mvc\Url\UrlInterface;

/**
 * ServiceLocator implementation for Tag helpers.
 *
 * Built-in services are seeded by the constructor. Users may add or override
 * services via `set()`, passing one of:
 *  - a closure / callable (full recipe)
 *  - a class-string (escaper is injected automatically)
 *  - a `[className, [depKey, ...]]` tuple where each dep key is resolved from
 *    the factory's own services or its injected `response` / `url`
 *  - a `[className, [depKey, ...], [extraArg, ...]]` tuple where the extra
 *    args are passed verbatim to the constructor after the resolved deps
 *
 * Helpers are cached per name after first construction.
 *
 * `__call()` resolves the named helper and dispatches to its `__invoke()`,
 * so each entry in the @method block below describes the result of calling
 * `$factory->serviceName(...)` rather than `newInstance("serviceName")`.
 *
 * @property EscaperInterface       $escaper
 * @property ResponseInterface|null $response
 * @property UrlInterface|null      $url
 * @property array                  $factories
 * @property array                  $instances
 *
 * @method string      a(string $href, string $text, array $attributes = [], bool $raw = false)
 * @method string      aRaw(string $href, string $text, array $attributes = [])
 * @method string      base(string $href, array $attributes = [])
 * @method string      body(array $attributes = [])
 * @method Breadcrumbs breadcrumbs(string $indent = '    ', string $delimiter = "\n")
 * @method string      button(string $text, array $attributes = [], bool $raw = false)
 * @method string      buttonRaw(string $text, array $attributes = [])
 * @method string      close(string $tag, bool $raw = false)
 * @method Doctype     doctype(int $type = Doctype::HTML5, string $delimiter = "\n")
 * @method string      element(string $tag, string $text, array $attributes = [], bool $raw = false)
 * @method string      elementRaw(string $tag, string $text, array $attributes = [])
 * @method string      form(array $attributes = [])
 * @method string      friendlyTitle(string $text, string $separator = '-', bool $lowercase = true, mixed $replace = null)
 * @method string      img(string $src, array $attributes = [])
 * @method Checkbox    inputCheckbox(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputColor(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputDate(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputDateTime(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputDateTimeLocal(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputEmail(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputFile(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputHidden(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputImage(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputInput(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputMonth(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputNumeric(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputPassword(string $name, string $value = null, array $attributes = [])
 * @method Radio       inputRadio(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputRange(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputSearch(string $name, string $value = null, array $attributes = [])
 * @method Select      inputSelect(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputSubmit(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputTel(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputText(string $name, string $value = null, array $attributes = [])
 * @method Textarea    inputTextarea(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputTime(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputUrl(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputWeek(string $name, string $value = null, array $attributes = [])
 * @method string      label(string $label, array $attributes = [], bool $raw = false)
 * @method string      labelRaw(string $label, array $attributes = [])
 * @method Link        link(string $indent = '    ', string $delimiter = PHP_EOL)
 * @method Meta        meta(string $indent = '    ', string $delimiter = PHP_EOL)
 * @method Ol          ol(string $indent = '    ', string $delimiter = null, array $attributes = [])
 * @method Ol          olRaw(string $indent = '    ', string $delimiter = null, array $attributes = [])
 * @method string      preload(string $href, string $type = 'style', array $attributes = [])
 * @method Script      script(string $indent = '    ', string $delimiter = PHP_EOL)
 * @method Style       style(string $indent = '    ', string $delimiter = PHP_EOL)
 * @method string      tag(string $name, array $attributes = [])
 * @method Title       title(string $indent = '    ', string $delimiter = PHP_EOL)
 * @method Ul          ul(string $indent = '    ', string $delimiter = null, array $attributes = [])
 * @method Ul          ulRaw(string $indent = '    ', string $delimiter = null, array $attributes = [])
 * @method string      voidTag(string $name, array $attributes = [])
 */
class TagFactory
{
    /**
     * @var EscaperInterface
     */
    private escaper;

    /**
     * @var ResponseInterface|null
     */
    private response = null;

    /**
     * @var UrlInterface|null
     */
    private url = null;

    /**
     * @var array
     */
    protected factories = [];

    /**
     * @var array
     */
    protected instances = [];

    /**
     * TagFactory constructor.
     *
     * @param EscaperInterface       $escaper
     * @param array                  $services
     * @param ResponseInterface|null $response
     * @param UrlInterface|null      $url
     */
    public function __construct(
        <EscaperInterface> escaper,
        array! services = [],
        <ResponseInterface> response = null,
        <UrlInterface> url = null
    ) {
        var name, definition;

        let this->escaper  = escaper,
            this->response = response,
            this->url      = url,
            this->factories = this->getDefaultServices();

        for name, definition in services {
            this->set(name, definition);
        }
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
        return isset(this->factories[name]);
    }

    /**
     * Create or return a cached instance of the helper.
     *
     * @param string $name
     *
     * @return mixed
     * @throws Exception
     */
    public function newInstance(string name) -> var
    {
        var factory, className, deps, args, depName, resolved, extra, extraArg;

        if !isset this->factories[name] {
            throw new Exception("Service " . name . " is not registered");
        }

        if !isset this->instances[name] {
            let factory = this->factories[name];

            if typeof factory === "object" || (typeof factory === "array" && is_callable(factory)) {
                let this->instances[name] = call_user_func(factory);
            } elseif typeof factory === "array" {
                let className = factory[0],
                    deps      = factory[1],
                    args      = [this->escaper];

                for depName in deps {
                    let resolved = this->resolveDependency(depName),
                        args[]   = resolved;
                }

                if isset factory[2] {
                    let extra = factory[2];
                    for extraArg in extra {
                        let args[] = extraArg;
                    }
                }

                let this->instances[name] = create_instance_params(className, args);
            } else {
                let this->instances[name] = create_instance_params(
                    factory,
                    [this->escaper]
                );
            }
        }

        return this->instances[name];
    }

    /**
     * Register a helper. Accepts a closure/callable (full recipe), a
     * class-string (wrapped into a closure that injects the escaper), or a
     * `[className, [depName, ...]]` tuple where each dep is resolved from
     * the factory's own services or its injected `response`/`url`.
     *
     * @param string $name
     * @param mixed  $definition
     */
    public function set(string name, var definition) -> void
    {
        let this->factories[name] = definition;
        unset(this->instances[name]);
    }

    /**
     * Resolves a dependency key for the tuple form of a service recipe.
     * Recognized keys: `response`, `url`. Anything else is treated as a
     * sibling service name and resolved via `newInstance()`. Tuple form is
     * `[className, [depKey, ...]]` or `[className, [depKey, ...], [extraArg, ...]]`
     * where extra args are passed through to the constructor verbatim.
     *
     * @param string $name
     *
     * @return mixed
     */
    protected function resolveDependency(string name) -> var
    {
        if name === "response" {
            return this->response;
        }

        if name === "url" {
            return this->url;
        }

        return this->newInstance(name);
    }

    /**
     * Default service recipes. Each entry is either a class-string (escaper
     * is injected automatically) or a `[className, [depKey, ...]]` tuple
     * where each dep key is resolved by `resolveDependency()`.
     *
     * @return array
     */
    protected function getDefaultServices() -> array
    {
        return [
            "a"                  : "Phalcon\\Html\\Helper\\Anchor",
            "aRaw"               : ["Phalcon\\Html\\Helper\\Anchor", [], [null, true]],
            "base"               : "Phalcon\\Html\\Helper\\Base",
            "body"               : "Phalcon\\Html\\Helper\\Body",
            "breadcrumbs"        : ["Phalcon\\Html\\Helper\\Breadcrumbs", ["url"]],
            "button"             : "Phalcon\\Html\\Helper\\Button",
            "buttonRaw"          : ["Phalcon\\Html\\Helper\\Button", [], [null, true]],
            "close"              : "Phalcon\\Html\\Helper\\Close",
            "doctype"            : "Phalcon\\Html\\Helper\\Doctype",
            "element"            : "Phalcon\\Html\\Helper\\Element",
            "elementRaw"         : ["Phalcon\\Html\\Helper\\Element", [], [null, true]],
            "form"               : "Phalcon\\Html\\Helper\\Form",
            "friendlyTitle"      : "Phalcon\\Html\\Helper\\FriendlyTitle",
            "img"                : "Phalcon\\Html\\Helper\\Img",
            "inputCheckbox"      : ["Phalcon\\Html\\Helper\\Input\\Checkbox", ["doctype"]],
            "inputColor"         : ["Phalcon\\Html\\Helper\\Input\\Generic", ["doctype"], ["color"]],
            "inputDate"          : ["Phalcon\\Html\\Helper\\Input\\Generic", ["doctype"], ["date"]],
            "inputDateTime"      : ["Phalcon\\Html\\Helper\\Input\\Generic", ["doctype"], ["datetime"]],
            "inputDateTimeLocal" : ["Phalcon\\Html\\Helper\\Input\\Generic", ["doctype"], ["datetime-local"]],
            "inputEmail"         : ["Phalcon\\Html\\Helper\\Input\\Generic", ["doctype"], ["email"]],
            "inputFile"          : ["Phalcon\\Html\\Helper\\Input\\Generic", ["doctype"], ["file"]],
            "inputHidden"        : ["Phalcon\\Html\\Helper\\Input\\Generic", ["doctype"], ["hidden"]],
            "inputImage"         : ["Phalcon\\Html\\Helper\\Input\\Generic", ["doctype"], ["image"]],
            "inputInput"         : ["Phalcon\\Html\\Helper\\Input\\Generic", ["doctype"]],
            "inputMonth"         : ["Phalcon\\Html\\Helper\\Input\\Generic", ["doctype"], ["month"]],
            "inputNumeric"       : ["Phalcon\\Html\\Helper\\Input\\Generic", ["doctype"], ["number"]],
            "inputPassword"      : ["Phalcon\\Html\\Helper\\Input\\Generic", ["doctype"], ["password"]],
            "inputRadio"         : ["Phalcon\\Html\\Helper\\Input\\Radio", ["doctype"]],
            "inputRange"         : ["Phalcon\\Html\\Helper\\Input\\Generic", ["doctype"], ["range"]],
            "inputSearch"        : ["Phalcon\\Html\\Helper\\Input\\Generic", ["doctype"], ["search"]],
            "inputSelect"        : ["Phalcon\\Html\\Helper\\Input\\Select", ["doctype"]],
            "inputSubmit"        : ["Phalcon\\Html\\Helper\\Input\\Generic", ["doctype"], ["submit"]],
            "inputTel"           : ["Phalcon\\Html\\Helper\\Input\\Generic", ["doctype"], ["tel"]],
            "inputText"          : ["Phalcon\\Html\\Helper\\Input\\Generic", ["doctype"], ["text"]],
            "inputTextarea"      : ["Phalcon\\Html\\Helper\\Input\\Textarea", ["doctype"]],
            "inputTime"          : ["Phalcon\\Html\\Helper\\Input\\Generic", ["doctype"], ["time"]],
            "inputUrl"           : ["Phalcon\\Html\\Helper\\Input\\Generic", ["doctype"], ["url"]],
            "inputWeek"          : ["Phalcon\\Html\\Helper\\Input\\Generic", ["doctype"], ["week"]],
            "label"              : "Phalcon\\Html\\Helper\\Label",
            "labelRaw"           : ["Phalcon\\Html\\Helper\\Label", [], [null, true]],
            "link"               : "Phalcon\\Html\\Helper\\Link",
            "meta"               : "Phalcon\\Html\\Helper\\Meta",
            "ol"                 : "Phalcon\\Html\\Helper\\Ol",
            "olRaw"              : ["Phalcon\\Html\\Helper\\Ol", [], [null, true]],
            "preload"            : ["Phalcon\\Html\\Helper\\Preload", ["response"]],
            "script"             : "Phalcon\\Html\\Helper\\Script",
            "style"              : "Phalcon\\Html\\Helper\\Style",
            "tag"                : "Phalcon\\Html\\Helper\\Tag",
            "title"              : "Phalcon\\Html\\Helper\\Title",
            "ul"                 : "Phalcon\\Html\\Helper\\Ul",
            "ulRaw"              : ["Phalcon\\Html\\Helper\\Ul", [], [null, true]],
            "voidTag"            : ["Phalcon\\Html\\Helper\\VoidTag", ["doctype"]]
        ];
    }
}
