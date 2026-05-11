
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

use Closure;
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
 * services via `set()`, passing a Closure that returns the helper instance.
 *
 * Helpers are cached per name after first construction.
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
 * @method Link        link(string $indent = '    ', string $delimiter = "\n")
 * @method Meta        meta(string $indent = '    ', string $delimiter = "\n")
 * @method Ol          ol(string $indent = '    ', string $delimiter = null, array $attributes = [])
 * @method Ol          olRaw(string $indent = '    ', string $delimiter = null, array $attributes = [])
 * @method string      preload(string $href, string $type = 'style', array $attributes = [])
 * @method Script      script(string $indent = '    ', string $delimiter = "\n")
 * @method Style       style(string $indent = '    ', string $delimiter = "\n")
 * @method string      tag(string $name, array $attributes = [])
 * @method Title       title(string $indent = '    ', string $delimiter = "\n")
 * @method Ul          ul(string $indent = '    ', string $delimiter = null, array $attributes = [])
 * @method Ul          ulRaw(string $indent = '    ', string $delimiter = null, array $attributes = [])
 * @method string      voidTag(string $name, array $attributes = [])
 */
class TagFactory
{
    /**
     * @var Doctype
     */
    private doctype;

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
     * @param EscaperInterface          $escaper
     * @param array<string, Closure>    $services  Map of service name to a
     *                                             zero-arg Closure that returns
     *                                             the helper instance.
     * @param ResponseInterface|null    $response
     * @param UrlInterface|null         $url
     */
    public function __construct(
        <EscaperInterface> escaper,
        array! services = [],
        <ResponseInterface> response = null,
        <UrlInterface> url = null
    ) {
        var name, definition;

        let this->escaper   = escaper,
            this->response  = response,
            this->url       = url,
            this->doctype   = new Doctype(),
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
     * @return mixed
     * @throws \Phalcon\Html\Exception
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
        return isset this->factories[name];
    }

    /**
     * Create or return a cached instance of the helper.
     *
     * @param string $name
     *
     * @return object
     * @throws \Phalcon\Html\Exception
     */
    public function newInstance(string name) -> object
    {
        var factory;

        if !isset this->factories[name] {
            throw new Exception("Service " . name . " is not registered");
        }

        if !isset this->instances[name] {
            let factory = this->factories[name];
            let this->instances[name] = call_user_func(factory);
        }

        return this->instances[name];
    }

    /**
     * Register a helper via a zero-argument Closure. The Closure is invoked on
     * the first matching `newInstance()` call and its return value is cached.
     * Passing a new definition clears any cached instance so the next call to
     * `newInstance()` rebuilds it.
     *
     * @param string  $name
     * @param Closure $definition
     */
    public function set(string name, <Closure> definition) -> void
    {
        let this->factories[name] = definition;
        unset(this->instances[name]);
    }

    /**
     * Default service recipes. Every entry is a Closure that returns a
     * fully-constructed helper instance. Services are built lazily and cached.
     *
     * @return array
     */
    protected function getDefaultServices() -> array
    {
        var escaper, response, url;

        let escaper  = this->escaper,
            response = this->response,
            url      = this->url;

        return [
            "a": function () use (escaper) {
                return new Anchor(escaper, this->newInstance("doctype"));
            },
            "aRaw": function () use (escaper) {
                return new Anchor(escaper, this->newInstance("doctype"), true);
            },
            "base": function () use (escaper) {
                return new Base(escaper, this->newInstance("doctype"));
            },
            "body": function () use (escaper) {
                return new Body(escaper, this->newInstance("doctype"));
            },
            "breadcrumbs": function () use (escaper, url) {
                return new Breadcrumbs(escaper, url);
            },
            "button": function () use (escaper) {
                return new Button(escaper, this->newInstance("doctype"));
            },
            "buttonRaw": function () use (escaper) {
                return new Button(escaper, this->newInstance("doctype"), true);
            },
            "close": function () use (escaper) {
                return new Close(escaper, this->newInstance("doctype"));
            },
            "doctype": function () {
                return this->doctype;
            },
            "element": function () use (escaper) {
                return new Element(escaper, this->newInstance("doctype"));
            },
            "elementRaw": function () use (escaper) {
                return new Element(escaper, this->newInstance("doctype"), true);
            },
            "form": function () use (escaper) {
                return new Form(escaper, this->newInstance("doctype"));
            },
            "friendlyTitle": function () use (escaper) {
                return new FriendlyTitle(escaper);
            },
            "img": function () use (escaper) {
                return new Img(escaper, this->newInstance("doctype"));
            },
            "inputCheckbox": function () use (escaper) {
                return new Checkbox(escaper, this->newInstance("doctype"));
            },
            "inputColor": function () use (escaper) {
                return new Generic(escaper, this->newInstance("doctype"), "color");
            },
            "inputDate": function () use (escaper) {
                return new Generic(escaper, this->newInstance("doctype"), "date");
            },
            "inputDateTime": function () use (escaper) {
                return new Generic(escaper, this->newInstance("doctype"), "datetime");
            },
            "inputDateTimeLocal": function () use (escaper) {
                return new Generic(escaper, this->newInstance("doctype"), "datetime-local");
            },
            "inputEmail": function () use (escaper) {
                return new Generic(escaper, this->newInstance("doctype"), "email");
            },
            "inputFile": function () use (escaper) {
                return new Generic(escaper, this->newInstance("doctype"), "file");
            },
            "inputHidden": function () use (escaper) {
                return new Generic(escaper, this->newInstance("doctype"), "hidden");
            },
            "inputImage": function () use (escaper) {
                return new Generic(escaper, this->newInstance("doctype"), "image");
            },
            "inputInput": function () use (escaper) {
                return new Generic(escaper, this->newInstance("doctype"));
            },
            "inputMonth": function () use (escaper) {
                return new Generic(escaper, this->newInstance("doctype"), "month");
            },
            "inputNumeric": function () use (escaper) {
                return new Generic(escaper, this->newInstance("doctype"), "number");
            },
            "inputPassword": function () use (escaper) {
                return new Generic(escaper, this->newInstance("doctype"), "password");
            },
            "inputRadio": function () use (escaper) {
                return new Radio(escaper, this->newInstance("doctype"));
            },
            "inputRange": function () use (escaper) {
                return new Generic(escaper, this->newInstance("doctype"), "range");
            },
            "inputSearch": function () use (escaper) {
                return new Generic(escaper, this->newInstance("doctype"), "search");
            },
            "inputSelect": function () use (escaper) {
                return new Select(escaper, this->newInstance("doctype"));
            },
            "inputSubmit": function () use (escaper) {
                return new Generic(escaper, this->newInstance("doctype"), "submit");
            },
            "inputTel": function () use (escaper) {
                return new Generic(escaper, this->newInstance("doctype"), "tel");
            },
            "inputText": function () use (escaper) {
                return new Generic(escaper, this->newInstance("doctype"), "text");
            },
            "inputTextarea": function () use (escaper) {
                return new Textarea(escaper, this->newInstance("doctype"));
            },
            "inputTime": function () use (escaper) {
                return new Generic(escaper, this->newInstance("doctype"), "time");
            },
            "inputUrl": function () use (escaper) {
                return new Generic(escaper, this->newInstance("doctype"), "url");
            },
            "inputWeek": function () use (escaper) {
                return new Generic(escaper, this->newInstance("doctype"), "week");
            },
            "label": function () use (escaper) {
                return new Label(escaper, this->newInstance("doctype"));
            },
            "labelRaw": function () use (escaper) {
                return new Label(escaper, this->newInstance("doctype"), true);
            },
            "link": function () use (escaper) {
                return new Link(escaper, this->newInstance("doctype"));
            },
            "meta": function () use (escaper) {
                return new Meta(escaper, this->newInstance("doctype"));
            },
            "ol": function () use (escaper) {
                return new Ol(escaper, this->newInstance("doctype"));
            },
            "olRaw": function () use (escaper) {
                return new Ol(escaper, this->newInstance("doctype"), true);
            },
            "preload": function () use (escaper, response) {
                return new Preload(escaper, response);
            },
            "script": function () use (escaper) {
                return new Script(escaper, this->newInstance("doctype"));
            },
            "style": function () use (escaper) {
                return new Style(escaper, this->newInstance("doctype"));
            },
            "tag": function () use (escaper) {
                return new Tag(escaper, this->newInstance("doctype"));
            },
            "title": function () use (escaper) {
                return new Title(escaper, this->newInstance("doctype"));
            },
            "ul": function () use (escaper) {
                return new Ul(escaper, this->newInstance("doctype"));
            },
            "ulRaw": function () use (escaper) {
                return new Ul(escaper, this->newInstance("doctype"), true);
            },
            "voidTag": function () use (escaper) {
                return new VoidTag(escaper, this->newInstance("doctype"));
            }
        ];
    }
}
