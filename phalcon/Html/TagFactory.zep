
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
use Phalcon\Contracts\Html\HtmlTypes;
use Phalcon\Html\Escaper\EscaperInterface;
use Phalcon\Html\Exceptions\ServiceNotRegistered;
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
use Phalcon\Html\Helper\Input\CheckboxGroup;
use Phalcon\Html\Helper\Input\Generic;
use Phalcon\Html\Helper\Input\Radio;
use Phalcon\Html\Helper\Input\RadioGroup;
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
 * `__call()` resolves the named helper and dispatches to its `__invoke()`,
 * so each entry in the @method block below describes the result of calling
 * `$factory->serviceName(...)` rather than `newInstance("serviceName")`.
 *
 * @phpstan-import-type html_attributes from HtmlTypes
 * @phpstan-import-type html_group_options from HtmlTypes
 * @phpstan-import-type html_factory_instances from HtmlTypes
 * @phpstan-import-type html_factory_services from HtmlTypes
 *
 * @method string        a(string $href, string $text, html_attributes $attributes = [], bool $raw = false)
 * @method string        aRaw(string $href, string $text, html_attributes $attributes = [])
 * @method string        base(string $href, html_attributes $attributes = [])
 * @method string        body(html_attributes $attributes = [])
 * @method Breadcrumbs   breadcrumbs(string $indent = '    ', string $delimiter = "\n")
 * @method string        button(string $text, html_attributes $attributes = [], bool $raw = false)
 * @method string        buttonRaw(string $text, html_attributes $attributes = [])
 * @method string        close(string $tag, bool $raw = false)
 * @method Doctype       doctype(int $type = Doctype::HTML5, string $delimiter = "\n")
 * @method string        element(string $tag, string $text, html_attributes $attributes = [], bool $raw = false)
 * @method string        elementRaw(string $tag, string $text, html_attributes $attributes = [])
 * @method string        form(html_attributes $attributes = [])
 * @method string        friendlyTitle(string $text, string $separator = '-', bool $lower = true, mixed $replace = null)
 * @method string        img(string $src, html_attributes $attributes = [])
 * @method Checkbox      inputCheckbox(string $name, string $value = null, html_attributes $attributes = [])
 * @method CheckboxGroup inputCheckboxGroup(string $name, array $options, mixed $checked = null, array $attributes = [])
 * @method Generic       inputColor(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputDate(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputDateTime(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputDateTimeLocal(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputEmail(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputFile(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputHidden(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputImage(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputInput(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputMonth(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputNumeric(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputPassword(string $name, string $value = null, html_attributes $attributes = [])
 * @method Radio         inputRadio(string $name, string $value = null, html_attributes $attributes = [])
 * @method RadioGroup    inputRadioGroup(string $name, array $options, mixed $checked = null, array $attributes = [])
 * @method Generic       inputRange(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputSearch(string $name, string $value = null, html_attributes $attributes = [])
 * @method Select        inputSelect(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputSubmit(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputTel(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputText(string $name, string $value = null, html_attributes $attributes = [])
 * @method Textarea      inputTextarea(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputTime(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputUrl(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputWeek(string $name, string $value = null, html_attributes $attributes = [])
 * @method string        label(string $label, html_attributes $attributes = [], bool $raw = false)
 * @method string        labelRaw(string $label, html_attributes $attributes = [])
 * @method Link          link(string $indent = '    ', string $delimiter = "\n")
 * @method Meta          meta(string $indent = '    ', string $delimiter = "\n")
 * @method Ol            ol(string $indent = '    ', string $delimiter = null, html_attributes $attributes = [])
 * @method Ol            olRaw(string $indent = '    ', string $delimiter = null, html_attributes $attributes = [])
 * @method string        preload(string $href, string $type = 'style', html_attributes $attributes = [])
 * @method Script        script(string $indent = '    ', string $delimiter = "\n")
 * @method Style         style(string $indent = '    ', string $delimiter = "\n")
 * @method string        tag(string $name, html_attributes $attributes = [])
 * @method Title         title(string $indent = '    ', string $delimiter = "\n")
 * @method Ul            ul(string $indent = '    ', string $delimiter = null, html_attributes $attributes = [])
 * @method Ul            ulRaw(string $indent = '    ', string $delimiter = null, html_attributes $attributes = [])
 * @method string        voidTag(string $name, html_attributes $attributes = [])
 */
class TagFactory
{
    private <Doctype> doctype;
    private <EscaperInterface> escaper;
    private ?<ResponseInterface> response = null;
    private ?<UrlInterface> url = null;

    /**
     * @phpstan-var html_factory_services
     */
    protected array factories = [];
    /**
     * @phpstan-var html_factory_instances
     */
    protected array instances = [];

    /**
     * TagFactory constructor.
     *
     * `$services` maps a service name to a zero-arg Closure that returns the
     * helper instance.
     *
     * @phpstan-param html_factory_services $services
     */
    public function __construct(
        <EscaperInterface> escaper,
         array services = [],
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
     * @phpstan-param array<int, mixed> $arguments
     *
     * @throws \Phalcon\Html\Exception
     */
    public function __call(string name, array arguments)
    {
        var helper;

        let helper = this->newInstance(name);

        return call_user_func_array([helper, "__invoke"], arguments);
    }

    /**
     */
    public function has(string name) -> bool
    {
        return isset this->factories[name];
    }

    /**
     * Create or return a cached instance of the helper.
     *
     * @throws \Phalcon\Html\Exception
     *
     * @phpstan-return ($name is 'doctype' ? Doctype : object)
     */
    public function newInstance(string name) -> object
    {
        var factory;

        if !isset this->factories[name] {
            throw new ServiceNotRegistered(name);
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
     */
    public function set(string name, <Closure> definition) -> void
    {
        let this->factories[name] = definition;
        unset(this->instances[name]);
    }

    /**
     * Default service recipes. Every entry is a callable that returns a
     * fully-constructed helper instance. Services are built lazily and cached.
     *
     * @phpstan-return html_factory_services
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
            "inputCheckboxGroup": function () use (escaper) {
                return new CheckboxGroup(escaper, this->newInstance("doctype"));
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
            "inputRadioGroup": function () use (escaper) {
                return new RadioGroup(escaper, this->newInstance("doctype"));
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
