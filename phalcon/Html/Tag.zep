
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html;

use Phalcon\Di\DiInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Escaper;
use Phalcon\Escaper\EscaperInterface;
use Phalcon\Helper\Arr;
use Phalcon\Html\Exception;
use Phalcon\Url\UrlInterface;

/**
 * Phalcon\Html\Tag
 *
 * Phalcon\Html\Tag is designed to simplify building of HTML tags. It provides a
 * set of helpers to dynamically generate HTML.
 */
class Tag implements InjectionAwareInterface
{
    /**
     * @var DiInterface
     */
    protected container;

    /**
     * @var array
     */
    private append = [];

    /**
     * @var int
     */
    private docType = 5; // HTML5

    /**
     * @var <EscaperInterface>
     */
    private escaper;

    /**
     * @var array
     */
    private prepend = [];

    /**
     * @var string
     */
    private separator = "";

    /**
     * @var string
     */
    private title = "";

    /**
     * @var array
     */
    private values = [];

    /**
     * @var <UrlInterface>
     */
    private url;

    /**
     * Constants
     */
    const HTML32               = 1;
    const HTML401_STRICT       = 2;
    const HTML401_TRANSITIONAL = 3;
    const HTML401_FRAMESET     = 4;
    const HTML5                = 5;
    const XHTML10_STRICT       = 6;
    const XHTML10_TRANSITIONAL = 7;
    const XHTML10_FRAMESET     = 8;
    const XHTML11              = 9;
    const XHTML20              = 10;
    const XHTML5               = 11;

    /**
     * Constructor
     */
    public function __construct(<EscaperInterface> escaper = null, <UrlInterface> url = null)
    {
        let this->escaper = escaper,
            this->url     = url;
    }

    /**
     * Appends a text to current document title
     */
    public function appendTitle(var title) -> <Tag>
    {
        if typeof title === "array" {
            let this->append = title;
        } else {
            let this->append[] = (string) title;
        }

        return this;
    }

    /**
     * Builds a HTML input[type="button"] tag
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->button('Click Me');
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ button('Click Me') }}{% endraw %}
     * ```
     */
    public function button(string! name, array parameters = []) -> string
    {
        return this->renderInput("button", name, parameters);
    }

    /**
     * Resets the request and internal values to avoid those fields will have
     * any default value.
     */
    public function clear() -> void
    {
        let this->append     = [],
            this->docType    = self::HTML5,
            this->prepend    = [],
            this->separator  = "",
            this->title      = "",
            this->values     = [];
    }

    /**
     * Builds a HTML tag
     *
     * Parameters
     * `onlyStart` Only process the start of th element
     * `selfClose` It is a self close element
     * `useEol`    Append PHP_EOL at the end
     */
    public function element(string! tag, array parameters = []) -> string
    {
        var onlyStart, output, selfClose, useEol;

        let useEol    = Arr::get(parameters, "useEol", false),
            onlyStart = Arr::get(parameters, "onlyStart", false),
            selfClose = Arr::get(parameters, "selfClose", false);

        /**
         * Unset options for this control
         */
        unset parameters["onlyStart"];
        unset parameters["selfClose"];
        unset parameters["useEol"];

        let output = this->renderAttributes("<" . tag, parameters);

        if this->docType > self::HTML5 {
            if selfClose {
                let output .= " />";
            } else {
                let output .= ">";
            }
        } else {
            if onlyStart {
                let output .= ">";
            } else {
                let output .= "></" . tag . ">";
            }
        }

        if useEol {
            let output .= PHP_EOL;
        }

        return output;
    }

    /**
     * Builds the closing tag of an html element
     *
     * Parameters
     * `useEol`    Append PHP_EOL at the end
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tab = new Tag();
     *
     * echo $tag->elementClose(
     *     [
     *         'name' => 'aside',
     *     ]
     * ); // </aside>
     *
     * echo $tag->elementClose(
     *     [
     *         'name'   => 'aside',
     *         'useEol' => true,
     *     ]
     * ); // '</aside>' . PHP_EOL
     * ```
     */
    public function elementClose(string! tag, array parameters = []) -> string
    {
        var useEol = false;

        let useEol = Arr::get(parameters, "useEol", false);

        if useEol {
            return "</" . tag . ">" . PHP_EOL;
        }

        return "</" . tag . ">";

    }

    /**
     * Returns the closing tag of a form element
     */
    public function endForm(bool eol = true) -> string
    {
        if eol {
            return "</form>" . PHP_EOL;
        } else {
            return "</form>";
        }
    }

    /**
     * Builds a HTML FORM tag
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tab = new Tag();
     *
     * echo $tag->form('posts/save');
     *
     * echo $tag->form(
     *     'posts/save',
     *     [
     *         "method" => "post",
     *     ]
     * );
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ form('posts/save') }}{% endraw %}
     * {% raw %}{{ form('posts/save', ['method': 'post') }}{% endraw %}
     * ```
     */
    public function form(string action, array parameters = []) -> string
    {
        var output, params, service;

        let service = this->getService("url");

        let parameters["method"] = Arr::get(parameters, "method", "post"),
            parameters["action"] = service->get(action);

        /**
         * Check for extra parameters
         */
        if fetch params, parameters["parameters"] {
            let parameters["action"] .= "?" . params;

            unset parameters["parameters"];
        }

        let output = this->renderAttributes("<form", parameters) . ">";

        return output;

    }

    /**
     * Converts text to URL-friendly strings
     *
     * Parameters
     * `text`      The text to be processed
     * `separator` Separator to use (default '-')
     * `lowercase` Convert to lowercase
     * `replace`
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tab = new Tag();
     *
     * echo $tag->friendlyTitle(
     *     [
     *         'text'       => 'These are big important news',
     *         'separator' => '-',
     *     ]
     * );
     * ```
     *
     * Volt Syntax:
     * ```php
     * {% raw %}{{ friendly_title(['text': 'These are big important news', 'separator': '-']) }}{% endraw %}
     * ```
     */
    public function friendlyTitle(string! text, array parameters = []) -> string
    {
        var count, from, locale, lowercase, replace, separator, to, output;

        if extension_loaded("iconv") {
            /**
             * Save the old locale and set the new locale to UTF-8
             */
            let locale = setlocale(LC_ALL, "en_US.UTF-8"),
                text   = iconv("UTF-8", "ASCII//TRANSLIT", text);
        }

        let lowercase = Arr::get(parameters, "lowercase", true),
            replace   = Arr::get(parameters, "replace", []),
            separator = Arr::get(parameters, "separator", "-");

        if !empty replace {
            if unlikely (typeof replace !== "array" && typeof replace !== "string") {
                throw new Exception(
                    "Parameter replace must be an array or a string"
                );
            }

            if typeof replace === "string" {
                let from = [replace];
            } else {
                let from = replace;
            }

            let count = count(from),
                to    = array_fill(0, count - 1, " "),
                text  = str_replace(from, to, text);
        }

        let output = preg_replace("/[^a-zA-Z0-9\\/_|+ -]/", "", text);
        if lowercase {
            let output = strtolower(output);
        }

        let output = preg_replace("/[\\/_|+ -]+/", separator, output),
            output = trim(output, separator);

        if extension_loaded("iconv") {
            /**
             * Revert back to the old locale
             */
            setlocale(LC_ALL, locale);
        }

        return output;
    }

    /**
     * Returns the internal dependency injector
     */
    public function getDI() -> <DiInterface>
    {
        return this->container;
    }

    /**
     * Get the document type declaration of content. If the docType has not
     * been set properly, XHTML5 is returned
     */
    public function getDocType() -> string
    {
        switch this->docType
        {
            case 1:
                return "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">" . PHP_EOL;
                /* no break */

            case 2:
                return "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\"" . PHP_EOL .
                        "\t\"http://www.w3.org/TR/html4/strict.dtd\">" . PHP_EOL;
                /* no break */

            case 3:
                return "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"" . PHP_EOL .
                        "\t\"http://www.w3.org/TR/html4/loose.dtd\">" . PHP_EOL;
                /* no break */

            case 4:
                return "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Frameset//EN\"" . PHP_EOL .
                        "\t\"http://www.w3.org/TR/html4/frameset.dtd\">" . PHP_EOL;
                /* no break */

            case 6:
                return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"" . PHP_EOL .
                        "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">" . PHP_EOL;
                /* no break */

            case 7:
                return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\"" . PHP_EOL .
                        "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">" . PHP_EOL;
                /* no break */

            case 8:
                return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Frameset//EN\"" . PHP_EOL .
                        "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd\">" . PHP_EOL;
                /* no break */

            case 9:
                return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\"" . PHP_EOL .
                        "\t\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">" . PHP_EOL;
                /* no break */

            case 10:
                return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 2.0//EN\"" . PHP_EOL .
                        "\t\"http://www.w3.org/MarkUp/DTD/xhtml2.dtd\">" . PHP_EOL;
                /* no break */
        }

        return "<!DOCTYPE html>" . PHP_EOL;
    }

    /**
     * Gets the current document title. The title will be automatically escaped.
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tag = new Tag();
     *
     * $tag
     *        ->setTitleSeparator(' ')
     *         ->prependTitle(['Hello'])
     *         ->setTitle('World')
     *         ->appendTitle(['from Phalcon']);
     *
     * echo $tag->getTitle();             // Hello World from Phalcon
     * echo $tag->getTitle(false);        // World from Phalcon
     * echo $tag->getTitle(true, false);  // Hello World
     * echo $tag->getTitle(false, false); // World
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ get_title() }}{% endraw %}
     * ```
     */
    public function getTitle(bool prepend = true, bool append = true) -> string
    {
        var item, output, title, appendTitle, prependTitle, separator, escaper;
        array items;

        let escaper   = this->getService("escaper"),
            items     = [],
            output    = "",
            title     = escaper->escapeHtml(this->title),
            separator = escaper->escapeHtml(this->separator);

        if prepend {
            let prependTitle = this->prepend;

            if !empty prependTitle {
                var prependArray = array_reverse(prependTitle);
                for item in prependArray {
                    let items[] = escaper->escapeHtml(item);
                }
            }
        }

        if !empty title {
            let items[] = title;
        }

        if append {
            let appendTitle = this->append;

            if !empty appendTitle {
                for item in appendTitle {
                    let items[] = escaper->escapeHtml(item);
                }
            }
        }

        if !empty items {
            let output = implode(separator, items);
        }

        return output;
    }

    /**
     * Gets the current document title separator
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->getTitleSeparator();
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ get_title_separator() }}{% endraw %}
     * ```
     */
    public function getTitleSeparator() -> string
    {
        return this->separator;
    }

    /**
     * Every helper calls this function to check whether a component has a
     * predefined value using `setAttribute` or value from $_POST
     */
    public function getValue(string name, array parameters = []) -> var | null
    {
        var value;

        if !fetch value, parameters["value"] {
            /**
             * Check if there is a predefined value for it
             */
            if !fetch value, this->values[name] {
                /**
                 * Check if there is a post value for the item
                 */
                if !fetch value, _POST[name] {
                    return null;
                }
            }
        }

        return value;
    }

    /**
     * Check if a helper has a default value set using `setAttribute()` or
     * value from $_POST
     */
    public function hasValue(string name) -> bool
    {
        /**
         * Check if there is a predefined or a POST value for it
         */
        return isset this->values[name] || isset _POST[name];
    }

    /**
     * Builds HTML IMG tags
     *
     * Parameters
     * `local` Local resource or not (default `true`)
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->image('img/bg.png');
     *
     * echo $tag->image(
     *     'img/photo.jpg',
     *     [
     *         'alt' => 'Some Photo',
     *     ]
     * );
     *
     * echo $tag->image(
     *     'http://static.mywebsite.com/img/bg.png',
     *     [
     *         'local' => false,
     *     ]
     * );
     * ```
     *
     * Volt Syntax:
     * ```php
     * {% raw %}{{ image('img/bg.png') }}{% endraw %}
     * {% raw %}{{ image('img/photo.jpg', ['alt': 'Some Photo') }}{% endraw %}
     * {% raw %}{{ image('http://static.mywebsite.com/img/bg.png', ['local': false]) }}{% endraw %}
     * ```
     */
    public function image(string url = "", array parameters = []) -> string
    {
        var local, service, src, output;

        let local = Arr::get(parameters, "local", true),
            src   = Arr::get(parameters, "src", url);

        /**
         * Use the "url" service if the URI is local
         */
        if local {
            let service = this->getService("url"),
                src     = service->getStatic(url);
        }

        unset parameters["local"];

        let parameters["src"]  = src;

        let output = this->renderAttributes("<img", parameters) . this->renderCloseTag();

        return output;
    }

    /**
     * Builds a HTML input[type="check"] tag
     *
     * ```php
     * echo $tag->inputCheckbox(
     *     [
     *         'name'  => 'terms,
     *         'value' => 'Y',
     *     ]
     * );
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ input_checkbox(['name': 'terms, 'value': 'Y']) }}{% endraw %}
     * ```
     */
    public function inputCheckbox(string! name, array parameters = []) -> string
    {
        return this->renderInputChecked("checkbox", name, parameters);
    }

    /**
     * Builds a HTML input[type='color'] tag
     */
    public function inputColor(string! name, array parameters = []) -> string
    {
        return this->renderInput("color", name, parameters);
    }

    /**
     * Builds a HTML input[type='date'] tag
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->inputDate(
     *     [
     *         'name'  => 'born',
     *         'value' => '14-12-1980',
     *     ]
     * );
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ input_date(['name':'born', 'value':'14-12-1980']) }}{% endraw %}
     * ```
     */
    public function inputDate(string! name, array parameters = []) -> string
    {
        return this->renderInput("date", name, parameters);
    }

    /**
    * Builds a HTML input[type='datetime'] tag
    *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->inputDateTime(
     *     [
     *         'name'  => 'born',
     *         'value' => '14-12-1980',
     *     ]
     * );
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ input_date_time(['name':'born', 'value':'14-12-1980']) }}{% endraw %}
     * ```
    */
    public function inputDateTime(string! name, array parameters = []) -> string
    {
        return this->renderInput("datetime", name, parameters);
    }

    /**
    * Builds a HTML input[type='datetime-local'] tag
    *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->inputDateTimeLocal(
     *     [
     *         'name'  => 'born',
     *         'value' => '14-12-1980',
     *     ]
     * );
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ input_date_time_local(['name':'born', 'value':'14-12-1980']) }}{% endraw %}
     * ```
    */
    public function inputDateTimeLocal(string! name, array parameters = []) -> string
    {
        return this->renderInput("datetime-local", name, parameters);
    }

    /**
     * Builds a HTML input[type='email'] tag
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->inputEmail(
     *     [
     *         'name' => 'email',
      *     ]
     * );
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ input_email(['name': 'email']);{% endraw %}
     * ```
     */
    public function inputEmail(string! name, array parameters = []) -> string
    {
        return this->renderInput("email", name, parameters);
    }

    /**
     * Builds a HTML input[type='file'] tag
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->inputFile(
     *     [
     *         'name' => 'file',
      *     ]
     * );
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ input_file(['name': 'file']){% endraw %}
     * ```
     */
    public function inputFile(string! name, array parameters = []) -> string
    {
        return this->renderInput("file", name, parameters);
    }

    /**
     * Builds a HTML input[type='hidden'] tag
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->inputHidden(
     *     [
     *         'name'  => 'my-field',
     *         'value' => 'mike',
     *     ]
     * );
     * ```
     */
    public function inputHidden(string! name, array parameters = []) -> string
    {
        return this->renderInput("hidden", name, parameters);
    }

    /**
     * Builds a HTML input[type="image"] tag
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tag = new Tag();
     * echo $tag->inputImage(
     *     [
     *         'src' => '/img/button.png',
     *     ]
     * );
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ input_image(['src': '/img/button.png']) }}{% endraw %}
     * ```
     */
    public function inputImage(string! name, array parameters = []) -> string
    {
        return this->renderInput("image", name, parameters);
    }

    /**
     * Builds a HTML input[type='month'] tag
     */
    public function inputMonth(string! name, array parameters = []) -> string
    {
        return this->renderInput("month", name, parameters);
    }

    /**
     * Builds a HTML input[type='number'] tag
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->numericField(
     *     [
     *         'name' => 'price',
     *         'min'  => '1',
     *         'max'  => '5',
     *     ]
     * );
     * ```
     */
    public function inputNumeric(string! name, array parameters = []) -> string
    {
        return this->renderInput("numeric", name, parameters);
    }

    /**
     * Builds a HTML input[type='password'] tag
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->passwordField(
     *     [
     *         'name' => 'my-field',
     *         'size' => 30,
     *     ]
     * );
     * ```
     */
    public function inputPassword(string! name, array parameters = []) -> string
    {
        return this->renderInput("password", name, parameters);
    }

    /**
     * Builds a HTML input[type="radio"] tag
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->inputRadio(
     *     [
     *         'name'  => 'weather',
     *         'value" => 'hot',
     *     ]
     * );
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ input_radio(['name': 'weather', 'value": 'hot']) }}{% endraw %}
     * ```
     */
    public function inputRadio(string! name, array parameters = []) -> string
    {
        return this->renderInputChecked("radio", name, parameters);
    }

    /**
    * Builds a HTML input[type='range'] tag
    */
    public function inputRange(string! name, array parameters = []) -> string
    {
        return this->renderInput("range", name, parameters);
    }

    /**
     * Builds a HTML input[type='search'] tag
     */
    public function inputSearch(string! name, array parameters = []) -> string
    {
        return this->renderInput("search", name, parameters);
    }

    /**
    * Builds a HTML input[type='tel'] tag
    */
    public function inputTel(string! name, array parameters = []) -> string
    {
        return this->renderInput("tel", name, parameters);
    }

    /**
     * Builds a HTML input[type='text'] tag
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->inputText(
     *     [
     *         'name' => 'my-field',
     *         'size' => 30,
     *     ]
     * );
     * ```
     */
    public function inputText(string! name, array parameters = []) -> string
    {
        return this->renderInput("text", name, parameters);
    }

    /**
     * Builds a HTML input[type='time'] tag
     */
    public function inputTime(string! name, array parameters = []) -> string
    {
        return this->renderInput("time", name, parameters);
    }

    /**
     * Builds a HTML input[type='url'] tag
     */
    public function inputUrl(string! name, array parameters = []) -> string
    {
        return this->renderInput("url", name, parameters);
    }

    /**
     * Builds a HTML input[type='week'] tag
     */
    public function inputWeek(string! name, array parameters = []) -> string
    {
        return this->renderInput("week", name, parameters);
    }

    /**
     * Builds a script[type="javascript"] tag
     *
     * Parameters
     * `local` Local resource or not (default `true`)
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->javascript(
     *     'http://ajax.googleapis.com/ajax/libs/jquery/2.2.3/jquery.min.js',
     *        [
     *         'local' => false,
     *     ]
     * );
     *
     * echo $tag->javascript('javascript/jquery.js');
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ javascript('http://ajax.googleapis.com/ajax/libs/jquery/2.2.3/jquery.min.js', ['local': false]) }}{% endraw %}
     * {% raw %}{{ javascript('javascript/jquery.js') }}{% endraw %}
     * ```
     */
    public function javascript(string url, array parameters = []) -> string
    {
        var service, output;
        bool local;

        let local = (bool) Arr::get(parameters, "local", true);

        /**
         * URLs are generated through the "url" service
         */
        if local {
            let service           = this->getService("url"),
                parameters["src"] = service->getStatic(url);
        } else {
            let parameters["src"] = url;
        }

        unset parameters["local"];

        let parameters["type"] = Arr::get(parameters, "type", "text/javascript");

        if this->docType >= self::HTML5 && "text/javascript" == parameters["type"] {
            unset(parameters["type"]);
        }

        let output = this->renderAttributes("<script", parameters) ."></script>" . PHP_EOL;

        return output;

    }

    /**
     * Builds a HTML A tag using framework conventions
     *
     * Parameters
     * `local` Local resource or not (default `true`)
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->link('signup/register', 'Register Here!');
     *
     * echo $tag->link(
     *     'signup/register',
     *     'Register Here!',
     *     [
     *         'class' => 'btn-primary',
     *     ]
     * );
     *
     * echo $tag->link(
     *     'https://phalconphp.com/',
     *     'Phalcon!',
     *     [
     *         'local' => false,
     *     ]
     * );
     *
     * echo $tag->link(
     *     'https://phalconphp.com/',
     *     'Phalcon!',
     *     [
     *         'local'  => false,
     *         'target' => '_new',
     *     ]
     * );
     * ```
     */
    public function link(string url, string text = "", array parameters = []) -> string
    {
        var local, query, output, service, text;

        let service = this->getService("url"),
            url     = Arr::get(parameters, "url", url),
            text    = Arr::get(parameters, "text", text),
            local   = Arr::get(parameters, "local", true),
            query   = Arr::get(parameters, "query", null);

        unset parameters["url"];
        unset parameters["local"];
        unset parameters["text"];
        unset parameters["query"];

        let parameters["href"] = service->get(url, query, local);

        let output = this->renderAttributes("<a", parameters) . ">" . text . "</a>";

        return output;
    }

    /**
     * Prepends a text to current document title
     */
    public function prependTitle(var title) -> <Tag>
    {
        if typeof title === "array" {
            let this->prepend = title;
        } else {
            let this->prepend[] = (string) title;
        }

        return this;
    }

    /**
     * Renders the title with title tags. The title is automaticall escaped
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tag = new Tag();
     *
     * $tag
     *        ->setTitleSeparator(' ')
     *         ->prependTitle(['Hello'])
     *         ->setTitle('World')
     *         ->appendTitle(['from Phalcon']);
     *
     * echo $tag->renderTitle();             // <title>Hello World from Phalcon</title>
     * echo $tag->renderTitle(false);        // <title>World from Phalcon</title>
     * echo $tag->renderTitle(true, false);  // <title>Hello World</title>
     * echo $tag->renderTitle(false, false); // <title>World</title>
     * ```
     *
     * ```php
     * {% raw %}{{ render_title() }}{% endraw %}
     * ```
     */
    public function renderTitle(bool prepend = true, bool append = true) -> string
    {
        return "<title>" . this->getTitle(prepend, append) . "</title>" . PHP_EOL;
    }

    /**
     * Builds a HTML input[type="reset"] tag
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->reset('Reset')
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ reset('Save') }}{% endraw %}
     * ```
     */
    public function reset(string! name, array parameters = []) -> string
    {
        return this->renderInput("reset", name, parameters);
    }

    /**
     * Builds a select element. It accepts an array or a resultset from
     * a Phalcon\Mvc\Model
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->select(
     *     'status',
     *     [
     *         'id'        => 'status-id',
     *         'useEmpty'  => true,
     *         'emptyValue => '',
     *         'emptyText' => 'Choose Status...',
     *     ],
     *     [
     *         'A' => 'Active',
     *         'I' => 'Inactive',
     *     ]
     * );
     *
     * echo $tag->select(
     *     'status',
     *     [
     *         'id'        => 'status-id',
     *         'useEmpty'  => true,
     *         'emptyValue => '',
     *         'emptyText' => 'Choose Type...',
     *         'using'     => [
     *             'id,
     *             'name',
     *         ],
     *     ],
     *     Robots::find(
     *         [
     *             'conditions' => 'type = :type:',
     *             'bind'       => [
     *                 'type' => 'mechanical',
     *             ]
     *         ]
     *     )
     * );
     * ```
     */
    public function select(string! name, array parameters = [], data = null) -> string
    {
        var emptyText, emptyValue, id, output, outputEmpty, useEmpty, using, value;

        let id                 = Arr::get(parameters, "id", name),
            name               = Arr::get(parameters, "name", name),
            useEmpty           = Arr::get(parameters, "useEmpty", false),
            using              = [],
            parameters["name"] = name,
            parameters["id"]   = id,
            outputEmpty        = "";

        /**
         * First check the data passed. We only accept datasets or arrays
         */
        if unlikely (typeof data !== "array" && data !== "object") {
            throw new Exception(
                "The dataset must be either an array or a ResultsetInterface"
            );
        }

        /**
         * For the ResultsetInterface we need the 'using' parameter
         */
        if typeof data === "object" {
            let using = Arr::get(
                parameters,
                "using",
                []
            );

            if typeof using === "array" && count(using) === 2 {
                unset parameters["using"];
            } else {
                throw new Exception(
                    "The 'using' parameter is not a valid array"
                );
            }
        }

        /**
         * Check if `useEmpty` has been passed
         */
        if useEmpty {
            let emptyText   = Arr::get(parameters, "emptyText", "Choose..."),
                emptyValue  = Arr::get(parameters, "emptyValue", ""),
                outputEmpty = sprintf(
                    "\t<option value=\"%s\">%s</option>" . PHP_EOL,
                    emptyValue,
                    emptyText
                );

            unset parameters["useEmpty"];
            unset parameters["emptyText"];
            unset parameters["emptyValue"];
        }

        if !fetch value, parameters["value"] {
            let value = this->getValue(id, parameters);
        } else {
            unset parameters["value"];
        }

        let output = this->renderAttributes("<select", parameters) . ">" . PHP_EOL
                   . outputEmpty;

        if typeof data == "object" {
            /**
             * Create the SELECT's option from a resultset
             */
            let output .= this->renderSelectResultset(data, using, value, "</option>" . PHP_EOL);
        } elseif typeof data == "array" {
            /**
             * Create the SELECT's option from an array
             */
            let output .= this->renderSelectArray(data, value, "</option>" . PHP_EOL);
        } else {
            throw new Exception("Invalid data provided to SELECT helper");
        }

        let output .= "</select>";

        return output;
    }

    /**
     * Assigns default values to generated tags by helpers
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tag = new Tag();
     *
     * // Assigning 'peter' to 'name' component
     * $tag->setAttribute('name', 'peter');
     *
     * // Later in the view
     * echo $tag->inputText('name'); // Will have the value 'peter' by default
     * ```
     */
    public function setAttribute(string! name, value) -> <Tag>
    {
        if value !== null {
            if unlikely (typeof value == "array" || typeof value == "object") {
                throw new Exception(
                    "Only scalar values can be assigned to UI components"
                );
            }
        }

        let this->values[name] = value;

        return this;
    }

    /**
     * Assigns default values to generated tags by helpers
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tag = new Tag();
     *
     * // Assigning 'peter' to 'name' component
     * $tag->setAttribute(
     *     [
     *         'name' => 'peter',
     *     ]
     * );
     *
     * // Later in the view
     * echo $tag->inputText('name'); // Will have the value 'peter' by default
     * ```
     */
    public function setAttributes(array! values, bool merge = false) -> <Tag>
    {
        if merge {
            let this->values = array_merge(this->values, values);
        } else {
            let this->values = values;
        }

        return this;
    }

    /**
     * Sets the dependency injector
     */
    public function setDI(<DiInterface> container) -> void
    {
        let this->container = container;
    }

    /**
     * Set the document type of content
     */
    public function setDocType(int doctype) -> <Tag>
    {
        if (doctype < self::HTML32 || doctype > self::XHTML5) {
            let this->docType = self::HTML5;
        } else {
            let this->docType = doctype;
        }

        return this;
    }

    /**
     * Set the title separator of view content
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tag = new Tag();
     *
     * $tag->setTitle('Phalcon Framework');
     * ```
     */
    public function setTitle(string title) -> <Tag>
    {
        let this->title = title;

        return this;
    }

    /**
     * Set the title separator of view content
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->setTitleSeparator('-');
     * ```
     */
    public function setTitleSeparator(string separator) -> <Tag>
    {
        let this->separator = separator;

        return this;
    }

    /**
     * Builds a LINK[rel="stylesheet"] tag
     *
     * Parameters
     * `local` Local resource or not (default `true`)
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->stylesheet(
     *     'http://fonts.googleapis.com/css?family=Rosario',
     *     [
     *         'local' => false,
     *     ]
     * );
     *
     * echo $tag->stylesheet('css/style.css');
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ stylesheet('http://fonts.googleapis.com/css?family=Rosario', ['local': false]) }}{% endraw %}
     * {% raw %}{{ stylesheet('css/style.css') }}{% endraw %}
     * ```
     */
    public function stylesheet(string url, array parameters = []) -> string
    {
        var service, output;
        bool local;

        let local = (bool) Arr::get(parameters, "local", true);

        unset parameters["local"];

        /**
         * URLs are generated through the "url" service
         */
        if local {
            let service            = this->getService("url"),
                parameters["href"] = service->getStatic(url);
        } else {
            let parameters["href"] = url;
        }

        if !isset parameters["rel"] {
            let parameters["rel"] = "stylesheet";
        }

        let parameters["type"] = Arr::get(parameters, "type", "text/css"),
            output             = this->renderAttributes("<link", parameters) . this->renderCloseTag(true);

        return output;
    }

    /**
     * Builds a HTML input[type="submit"] tag
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->submit('Save');
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ submit('Save') }}{% endraw %}
     * ```
     */
    public function submit(string! name, array parameters = []) -> string
    {
        return this->renderInput("submit", name, parameters);
    }

    /**
     * Builds a HTML TEXTAREA tag
     *
     * ```php
     * use Phalcon\Html\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->textArea(
     *     'comments',
     *     [
     *         'cols' => 10,
     *         'rows' => 4,
     *     ]
     * );
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ text_area('comments', ['cols': 10, 'rows': 4]) }}{% endraw %}
     * ```
     */
    public function textArea(string! name, array parameters = []) -> string
    {
        var content, output;

        let parameters["id"]   = Arr::get(parameters, "id", name),
            parameters["name"] = Arr::get(parameters, "name", name);

        if isset parameters["value"] {
            let content = parameters["value"];

            unset parameters["value"];
        } else {
            let content = this->getValue(parameters["id"], parameters);
        }


        let output = this->renderAttributes("<textarea", parameters) . ">" .
                     htmlspecialchars(content) . "</textarea>";

        return output;
    }

    /**
     * Returns the escaper service from the DI container
     */
    private function getService(string name)
    {
        var service, container;

        if "escaper" === name {
            let service = this->escaper;
        } else {
            let service = this->url;
        }

        if typeof service !== "object" {
            let container = this->getDI();

            if unlikely typeof container != "object" {
                throw new Exception(
                    Exception::containerServiceNotFound(
                        "the '" . name . "' service"
                    )
                );
            }

            if "escaper" === name {
                let service       = <EscaperInterface> container->getShared(name),
                    this->escaper = service;
            } else {
                let service   = <UrlInterface> container->getShared(name),
                    this->url = service;
            }
        }

        return service;
    }

    /**
     * Renders the attributes of an HTML element
     */
    private function renderAttributes(string! code, array! attributes) -> string
    {
        var attrs, escaper, escaped, key, newCode, intersect, order, value;

        let order = [
            "rel"    : null,
            "type"   : null,
            "for"    : null,
            "src"    : null,
            "href"   : null,
            "action" : null,
            "id"     : null,
            "name"   : null,
            "value"  : null,
            "class"  : null
        ];

        let intersect = array_intersect_key(order, attributes),
            attrs     = array_merge(intersect, attributes),
            escaper   = this->getService("escaper");

        unset attrs["escape"];

        let newCode = code;

        for key, value in attrs {
            if typeof key == "string" && value !== null {
                if unlikely (typeof value == "array" || typeof value == "resource") {
                    throw new Exception(
                        "Value at index: '" . key . "' type: '" . gettype(value) . "' cannot be rendered"
                    );
                }

                if escaper {
                    let escaped = escaper->escapeHtmlAttr(value);
                } else {
                    let escaped = value;
                }

                let newCode .= " " . key . "=\"" . escaped . "\"";
            }
        }

        return newCode;
    }

    /**
     * Returns the closing tag depending on the doctype
     */
    private function renderCloseTag(bool addEol = false) -> string
    {
        var eol = "";

        if addEol {
            let eol = PHP_EOL;
        }

        /**
         * Check if Doctype is XHTML
         */
        if this->docType > self::HTML5 {
            return " />" . eol;
        } else {
            return ">" . eol;
        }
    }

    /**
     * Builds `input` elements
     */
    private function renderInput(string type, string name, array parameters = []) -> string
    {
        var name, id, output;

        let id = Arr::get(parameters, "id", name);

        let parameters["id"]    = id,
            parameters["name"]  = name,
            parameters["type"]  = type,
            parameters["value"] = this->getValue(id, parameters);

        let output = this->renderAttributes("<input", parameters) . this->renderCloseTag();

        return output;
    }
    /**
     * Builds INPUT tags that implements the checked attribute
     */
    private function renderInputChecked(string type, string name, array parameters = []) -> string
    {
        var currentValue, id, name, output, value;

        let id = Arr::get(parameters, "id", name);

        /**
         * Automatically check inputs
         */
        if fetch currentValue, parameters["value"] {
            unset parameters["value"];

            let value = this->getValue(id, parameters);

            if value !== null && currentValue === value {
                let parameters["checked"] = "checked";
            }

            let parameters["value"] = currentValue;
        } else {
            let value = this->getValue(id, parameters);

            /**
            * Evaluate the value in POST
            */
            if value !== null {
                let parameters["checked"] = "checked";
            }

            /**
            * Update the value anyways
            */
            let parameters["value"] = value;
        }

        let parameters["id"]    = id,
            parameters["name"]  = name,
            parameters["type"]  = type;

        let output = this->renderAttributes("<input", parameters) . this->renderCloseTag();

        return output;
    }

    /**
     * Generates the option values or optgroup from an array
     */
    private function renderSelectArray(array options, var value, string closeOption) -> string
    {
        var label, strOptionValue, strValue, optionText, optionValue, output;

        let output = "";

        for optionValue, optionText in options {
            let label = htmlspecialchars(optionValue);

            /**
             * Check if this is an option group
             */
             if typeof optionText === "array" {
                let output .= "\t<optgroup label=\"" . label . "\">" . PHP_EOL
                            . this->renderSelectArray(optionText, value, closeOption) . "\t</optgroup>" . PHP_EOL;

                continue;
             }

             if typeof value === "array" {
                if in_array(optionValue, value) {
                    let output .= "\t<option selected=\"selected\" value=\"" . label . "\">"
                                . optionText . closeOption;
                } else {
                    let output .= "\t<option value=\"" . label . "\">" . optionText . closeOption;
                }
             } else {
                let strOptionValue = (string) optionValue,
                    strValue       = (string) value;

                if strOptionValue === strValue {
                    let output .= "\t<option selected=\"selected\" value=\"" . label . "\">"
                                . optionText . closeOption;
                } else {
                    let output .= "\t<option value=\"" . label . "\">" . optionText . closeOption;
                }
             }
        }

        return output;
    }

    /**
     * Generates the option values from a resultset
     */
    private function renderSelectResultset(<ResulsetInterface> resultset, using, var value, string closeOption) -> string
    {
        var escaper, option, output, optionValue, optionText, parameters,
            strOptionValue, strValue;

        let escaper    = this->getService("escaper"),
            parameters = [],
            output     = "";

        /**
         * This needs to be here because we don't want assignments inside the
         * loop for things that will not change
         */
        if typeof using === "array" {
            let optionValue = using[0],
                optionText  = using[1];
        }

        for option in iterator(resultset) {

            if typeof using == "array" {
                if typeof option == "object" {
                    if method_exists(option, "readAttribute") {
                        let optionValue = option->readAttribute(optionValue),
                            optionText  = option->readAttribute(optionText);
                    } else {
                        let optionValue = option->optionValue,
                            optionText  = option->optionText;
                    }
                } else {
                    if unlikely typeof option != "array" {
                        throw new Exception(
                            "Resultset returned an invalid value"
                        );
                    }

                    let optionValue = option[optionValue],
                        optionText  = option[optionText];
                }

                let optionValue = escaper->escapeHtmlAttr(optionValue);
                let optionText  = escaper->escapeHtml(optionText);

                /**
                 * If the value is equal to the option's value we mark it as selected
                 */
                if typeof value == "array" {
                    if in_array(optionValue, value) {
                        let output .= "\t<option selected=\"selected\" value=\"" . optionValue . "\">"
                                    . optionText . closeOption;
                    } else {
                        let output .= "\t<option value=\"" . optionValue . "\">" . optionText . closeOption;
                    }
                } else {
                    let strOptionValue = (string) optionValue,
                        strValue       = (string) value;
                    if strOptionValue === strValue {
                        let output .= "\t<option selected=\"selected\" value=\"" . strOptionValue . "\">"
                                    . optionText . closeOption;
                    } else {
                        let output .= "\t<option value=\"" . strOptionValue . "\">" . optionText . closeOption;
                    }
                }
            } else {

                /**
                 * Check if using is a closure
                 */
                if typeof using == "object" {
                    let parameters[0] = option,
                        output       .= call_user_func_array(using, parameters);
                }
            }
        }

        return output;
    }
}
