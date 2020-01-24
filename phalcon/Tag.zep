
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon;

use Phalcon\Di\DiInterface;
use Phalcon\Escaper\EscaperInterface;
use Phalcon\Tag\Select;
use Phalcon\Tag\Exception;
use Phalcon\Url\UrlInterface;

/**
 * Phalcon\Tag is designed to simplify building of HTML tags.
 * It provides a set of helpers to generate HTML in a dynamic way.
 * This component is a class that you can extend to add more helpers.
 */
class Tag
{
    const HTML32 = 1;
    const HTML401_STRICT = 2;
    const HTML401_TRANSITIONAL = 3;
    const HTML401_FRAMESET = 4;
    const HTML5 = 5;
    const XHTML10_STRICT = 6;
    const XHTML10_TRANSITIONAL = 7;
    const XHTML10_FRAMESET = 8;
    const XHTML11 = 9;
    const XHTML20 = 10;
    const XHTML5 = 11;

    protected static autoEscape = true;

    /**
     * DI Container
     */
    protected static container;

    /**
     * Pre-assigned values for components
     */
    protected static displayValues;

    protected static documentAppendTitle = null;

    protected static documentPrependTitle = null;

    /**
     * HTML document title
     */
    protected static documentTitle = null;

    protected static documentTitleSeparator = null;

    protected static documentType = 11;

    protected static escaperService = null;

    protected static urlService = null;

    /**
     * Appends a text to current document title
     */
    public static function appendTitle(var title) -> void
    {
        if self::documentAppendTitle === null {
            let self::documentAppendTitle = [];
        }

        if typeof title == "array" {
            let self::documentAppendTitle = title ;
        } else {
            let self::documentAppendTitle[] = title ;
        }
    }

    /**
     * Builds a HTML input[type="check"] tag
     *
     * @param array parameters = [
     *     'class' => '',
     *     'id' => '',
     *     'name' => ''
     *     'value' => ''
     * ]
     */
    public static function checkField(var parameters) -> string
    {
        return self::inputFieldChecked("checkbox", parameters);
    }

    /**
     * Builds a HTML input[type="color"] tag
     *
     * @param array parameters = [
     *     'class' => '',
     *     'id' => '',
     *     'name' => ''
     *     'value' => ''
     * ]
     */
    public static function colorField(var parameters) -> string
    {
        return self::inputField("color", parameters);
    }

    /**
     * Builds a HTML input[type="date"] tag
     *
     * @param array parameters = [
     *     'class' => '',
     *     'id' => '',
     *     'name' => ''
     *     'value' => ''
     * ]
     */
    public static function dateField(var parameters) -> string
    {
        return self::inputField("date", parameters);
    }

    /**
    * Builds a HTML input[type="datetime"] tag
    *
     * @param array parameters = [
     *     'class' => '',
     *     'id' => '',
     *     'name' => ''
     *     'value' => ''
     * ]
    */
    public static function dateTimeField(var parameters) -> string
    {
        return self::inputField("datetime", parameters);
    }

    /**
    * Builds a HTML input[type="datetime-local"] tag
    *
     * @param array parameters = [
     *     'class' => '',
     *     'id' => '',
     *     'name' => ''
     *     'value' => ''
     * ]
    */
    public static function dateTimeLocalField(var parameters) -> string
    {
        return self::inputField("datetime-local", parameters);
    }

    /**
     * Alias of Phalcon\Tag::setDefault()
     */
    public static function displayTo(string! id, value) -> void
    {
        self::setDefault(id, value);
    }

    /**
     * Builds a HTML input[type="email"] tag
     *
     * @param array parameters = [
     *     'class' => '',
     *     'id' => '',
     *     'name' => ''
     *     'value' => ''
     * ]
     */
    public static function emailField(var parameters) -> string
    {
        return self::inputField("email", parameters);
    }

    /**
     * Builds a HTML close FORM tag
     */
    public static function endForm() -> string
    {
        return "</form>";
    }

    /**
     * Builds a HTML input[type="file"] tag
     *
     * @param array parameters = [
     *     'class' => '',
     *     'id' => '',
     *     'name' => ''
     *     'value' => ''
     * ]
     */
    public static function fileField(var parameters) -> string
    {
        return self::inputField("file", parameters);
    }

    /**
     * Builds a HTML FORM tag
     *
     * @param array parameters = [
     *     'method' => 'post',
     *     'action' => '',
     *     'parameters' => '',
     *     'name' => '',
     *     'class' => '',
     *     'id' => ''
     * ]
     */
    public static function form(var parameters) -> string
    {
        var params, paramsAction, action, code;

        if typeof parameters != "array" {
            let params = [parameters];
        } else {
            let params = parameters;
        }

        if !fetch paramsAction, params[0] {
            fetch paramsAction, params["action"];
        }

        /**
         * By default the method is POST
         */
        if !isset params["method"] {
            let params["method"] = "post";
        }

        let action = null;

        if !empty paramsAction {
            let action = self::getUrlService()->get(paramsAction);
        }

        /**
         * Check for extra parameters
         */
        if fetch parameters, params["parameters"] {
            let action .= "?" . parameters;
        }

        if !empty action {
            let params["action"] = action;
        }

        let code = self::renderAttributes("<form", params),
            code .= ">";

        return code;
    }

    /**
     * Converts texts into URL-friendly titles
     */
    public static function friendlyTitle(
        string text,
        string separator = "-",
        bool lowercase = true,
        var replace = null
    ) -> string
    {
        var friendly, locale, search;

        if extension_loaded("iconv") {
            /**
             * Save the old locale and set the new locale to UTF-8
             */
            let locale = setlocale(LC_ALL, "en_US.UTF-8"),
                text = iconv("UTF-8", "ASCII//TRANSLIT", text);
        }

        if replace {
            if unlikely (typeof replace != "array" && typeof replace != "string") {
                throw new Exception(
                    "Parameter replace must be an array or a string"
                );
            }

            if typeof replace == "array" {
                for search in replace {
                    let text = str_replace(search, " ", text);
                }
            } else {
                let text = str_replace(replace, " ", text);
            }
        }

        let friendly = preg_replace(
            "/[^a-zA-Z0-9\\/_|+ -]/",
            "",
            text
        );

        if lowercase {
            let friendly = strtolower(friendly);
        }

        let friendly = preg_replace("/[\\/_|+ -]+/", separator, friendly),
            friendly = trim(friendly, separator);

        if extension_loaded("iconv") {
            /**
             * Revert back to the old locale
             */
            setlocale(LC_ALL, locale);
        }
        return friendly;
    }

    /**
     * Get the document type declaration of content
     */
    public static function getDocType() -> string
    {
        switch self::documentType
        {
            case 1:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">" . PHP_EOL;
            /* no break */

            case 2:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\"" . PHP_EOL . "\t\"http://www.w3.org/TR/html4/strict.dtd\">" . PHP_EOL;
            /* no break */

            case 3:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"" . PHP_EOL . "\t\"http://www.w3.org/TR/html4/loose.dtd\">" . PHP_EOL;
            /* no break */

            case 4:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Frameset//EN\"" . PHP_EOL . "\t\"http://www.w3.org/TR/html4/frameset.dtd\">" . PHP_EOL;
            /* no break */

            case 6:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"" . PHP_EOL . "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">" . PHP_EOL;
            /* no break */

            case 7:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\"" . PHP_EOL."\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">" . PHP_EOL;
            /* no break */

            case 8:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Frameset//EN\"" . PHP_EOL . "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd\">" . PHP_EOL;
            /* no break */

            case 9:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\"" . PHP_EOL . "\t\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">" . PHP_EOL;
            /* no break */

            case 10: return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 2.0//EN\"" . PHP_EOL . "\t\"http://www.w3.org/MarkUp/DTD/xhtml2.dtd\">" . PHP_EOL;
            /* no break */

            case 5:
            case 11: return "<!DOCTYPE html>" . PHP_EOL;
            /* no break */
        }

        return "";
    }

    /**
     * Obtains the 'escaper' service if required
     */
    public static function getEscaper(array! params) -> <EscaperInterface> | null
    {
        var autoescape;

        if !fetch autoescape, params["escape"] {
            let autoescape = self::autoEscape;
        }

        if !autoescape {
            return null;
        }

        return self::getEscaperService();
    }

    /**
     * Internally gets the request dispatcher
     */
    public static function getDI() -> <DiInterface>
    {
        var di;

        let di = self::container;

        if typeof di != "object" {
            let di = Di::getDefault();
        }

        return di;
    }

    /**
     * Returns an Escaper service from the default DI
     */
    public static function getEscaperService() -> <EscaperInterface>
    {
        var escaper, container;

        let escaper = self::escaperService;

        if typeof escaper != "object" {
            let container = self::getDI();

            if unlikely typeof container != "object" {
                throw new Exception(
                    Exception::containerServiceNotFound("the 'escaper' service")
                );
            }

            let escaper = <EscaperInterface> container->getShared("escaper"),
                self::escaperService = escaper;
        }

        return escaper;
    }

    /**
     * Gets the current document title. The title will be automatically escaped.
     */
    public static function getTitle(bool prepend = true, bool append = true) -> string
    {
        var items, output, title, documentTitle, documentAppendTitle,
            documentPrependTitle, documentTitleSeparator, escaper;

        let escaper = <EscaperInterface> self::getEscaper(["escape": true]);
        let items = [];
        let output = "";
        let documentTitle = escaper->escapeHtml(self::documentTitle);

        let documentTitleSeparator = escaper->escapeHtml(
            self::documentTitleSeparator
        );

        if prepend {
            if self::documentPrependTitle === null {
                let self::documentPrependTitle = [];
            }

            let documentPrependTitle = self::documentPrependTitle;

            if !empty documentPrependTitle {
                var tmp = array_reverse(documentPrependTitle);

                for title in tmp {
                    let items[] = escaper->escapeHtml(title);
                }
            }
        }

        if !empty documentTitle {
            let items[] = documentTitle;
        }

        if append {
            if self::documentAppendTitle === null {
                let self::documentAppendTitle = [];
            }

            let documentAppendTitle = self::documentAppendTitle;

            if !empty documentAppendTitle {
                for title in documentAppendTitle {
                    let items[] = escaper->escapeHtml(title);
                }
            }
        }

        if empty documentTitleSeparator {
            let documentTitleSeparator = "";
        }

        if !empty items {
            let output = implode(documentTitleSeparator, items);
        }

        return output;
    }

    /**
     * Gets the current document title separator
     */
    public static function getTitleSeparator() -> string
    {
        return self::documentTitleSeparator;
    }

    /**
     * Returns a URL service from the default DI
     */
    public static function getUrlService() -> <UrlInterface>
    {
        var url, container;

        let url = self::urlService;

        if typeof url != "object" {
            let container = self::getDI();

            if unlikely typeof container != "object" {
                throw new Exception(
                    Exception::containerServiceNotFound("the 'url' service")
                );
            }

            let url = <UrlInterface> container->getShared("url"),
                self::urlService = url;
        }

        return url;
    }

    /**
     * Every helper calls this function to check whether a component has a
     * predefined value using Phalcon\Tag::setDefault() or value from $_POST
     */
    public static function getValue(var name, array params = [])
    {
        var value;

        if !fetch value, params["value"] {
            /**
             * Check if there is a predefined value for it
             */
            if !fetch value, self::displayValues[name] {
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
     * Check if a helper has a default value set using Phalcon\Tag::setDefault()
     * or value from $_POST
     */
    public static function hasValue(var name) -> bool
    {
        /**
         * Check if there is a predefined or a POST value for it
         */
        return isset self::displayValues[name] || isset _POST[name];
    }

    /**
     * Builds a HTML input[type="hidden"] tag
     *
     * @param array parameters = [
     *     'class' => '',
     *     'name' => '',
     *     'src' => '',
     *     'id' => '',
     *     'value' => ''
     * ]
     */
    public static function hiddenField(var parameters) -> string
    {
        return self::inputField("hidden", parameters);
    }

    /**
     * Builds HTML IMG tags
     *
     * @param array|string parameters = [
     *     'src' => '',
     *     'class' => '',
     *     'id' => '',
     *     'name' => ''
     * ]
     */
    public static function image(var parameters = null, bool local = true) -> string
    {
        var params, code, src;

        if typeof parameters != "array" {
            let params = [parameters];
        } else {
            let params = parameters;

            if isset params[1] {
                let local = (bool) params[1];
            }
        }

        if !isset params["src"] {
            if fetch src, params[0] {
                let params["src"] = src;
            } else {
                let params["src"] = "";
            }
        }

        /**
         * Use the "url" service if the URI is local
         */
        if local {
            let params["src"] = self::getUrlService()->getStatic(params["src"]);
        }

        let code = self::renderAttributes("<img", params);

        /**
         * Check if Doctype is XHTML
         */
        if self::documentType > self::HTML5 {
            let code .= " />";
        } else {
            let code .= ">";
        }

        return code;
    }

    /**
     * Builds a HTML input[type="image"] tag
     *
     * @param array parameters = [
     *     'class' => '',
     *     'name' => '',
     *     'src' => '',
     *     'id' => ''
     * ]
     */
    public static function imageInput(var parameters) -> string
    {
        return self::inputField("image", parameters, true);
    }

    /**
     * Builds a SCRIPT[type="javascript"] tag
     *
     * @param array|string parameters = [
     *     'local' => false,
     *     'src' => '',
     *     'type' => 'text/javascript'
     *     'rel' => ''
     * ]
     */
    public static function javascriptInclude(var parameters = null, bool local = true) -> string
    {
        var params, code;

        if typeof parameters != "array" {
            let params = [parameters, local];
        } else {
            let params = parameters;
        }

        if isset params[1] {
            let local = (bool) params[1];
        } else {
            if isset params["local"] {
                let local = (bool) params["local"];

                unset params["local"];
            }
        }

        if !isset params["type"] && self::documentType < self::HTML5 {
            let params["type"] = "text/javascript";
        }

        if !isset params["src"] {
            if isset params[0] {
                let params["src"] = params[0];
            } else {
                let params["src"] = "";
            }
        }

        /**
         * URLs are generated through the "url" service
         */
        if local {
            let params["src"] = self::getUrlService()->getStatic(params["src"]);
        }

        let code = self::renderAttributes("<script", params),
            code .= "></script>" . PHP_EOL;

        return code;
    }

    /**
     * Builds a HTML A tag using framework conventions
     *
     * @param parameters array|string = [
     *     'action' => '',
     *     'text' => '',
     *     'local' => false,
     *     'query' => '',
     *     'class' => '',
     *     'name' => '',
     *     'href' => '',
     *     'id' => ''
     * ]
     */
    public static function linkTo(parameters, text = null, local = true) -> string
    {
        var params, action, query, url, code;

        if typeof parameters != "array" {
            let params = [parameters, text, local];
        } else {
            let params = parameters;
        }

        if !fetch action, params[0] {
            if !fetch action, params["action"] {
                let action = "";
            } else {
                unset params["action"];
            }
        }

        if !fetch text, params[1] {
            if !fetch text, params["text"] {
                let text = "";
            } else {
                unset params["text"];
            }
        }

        if !fetch local, params[2] {
            if !fetch local, params["local"] {
                let local = true;
            } else {
                unset params["local"];
            }
        }

        if fetch query, params["query"] {
            unset params["query"];
        } else  {
            let query = null;
        }

        let url = self::getUrlService(),
            params["href"] = url->get(action, query, local),
            code = self::renderAttributes("<a", params),
            code .= ">" . text . "</a>";

        return code;
    }

    /**
     * Builds a HTML input[type="month"] tag
     *
     * @param array parameters = [
     *     'class' => '',
     *     'name' => '',
     *     'src' => '',
     *     'id' => '',
     *     'value' => ''
     * ]
     */
    public static function monthField(var parameters) -> string
    {
        return self::inputField("month", parameters);
    }

    /**
     * Builds a HTML input[type="number"] tag
     *
     * @param array parameters = [
     *     'class' => '',
     *     'name' => '',
     *     'src' => '',
     *     'id' => '',
     *     'value' => ''
     * ]
     */
    public static function numericField(var parameters) -> string
    {
        return self::inputField("number", parameters);
    }


    /**
     * Builds a HTML input[type="password"] tag
     *
     * @param array parameters = [
     *     'class' => '',
     *     'name' => '',
     *     'src' => '',
     *     'id' => '',
     *     'value' => ''
     * ]
     */
    public static function passwordField(var parameters) -> string
    {
        return self::inputField("password", parameters);
    }

    /**
     * Prepends a text to current document title
     */
    public static function prependTitle(var title) -> void
    {
        if self::documentPrependTitle === null {
            let self::documentPrependTitle = [];
        }

        if typeof title == "array" {
            let self::documentPrependTitle = title ;
        } else {
            let self::documentPrependTitle[] = title ;
        }
    }

    /**
     * Builds a HTML input[type="radio"] tag
     *
     * @param array parameters = [
     *     'class' => '',
     *     'name' => '',
     *     'src' => '',
     *     'id' => '',
     *     'value' => ''
     * ]
     */
    public static function radioField(var parameters) -> string
    {
        return self::inputFieldChecked("radio", parameters);
    }

    /**
    * Builds a HTML input[type="range"] tag
    *
     * @param array parameters = [
     *     'class' => '',
     *     'name' => '',
     *     'src' => '',
     *     'id' => '',
     *     'value' => ''
     * ]
    */
    public static function rangeField(var parameters) -> string
    {
        return self::inputField("range", parameters);
    }

    /**
     * Renders parameters keeping order in their HTML attributes
     *
     * @param array attributes = [
     *     'rel' => null,
     *     'type' => null,
     *     'for' => null,
     *     'src' => null,
     *     'href' => null,
     *     'action' => null,
     *     'id' => null,
     *     'name' => null,
     *     'value' => null,
     *     'class' => null
     * ]
     */
    public static function renderAttributes(string! code, array! attributes) -> string
    {
        var order, escaper, attrs, attribute, value, escaped, key, newCode;

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

        let attrs = [];

        for key, value in order {
            if fetch attribute, attributes[key] {
                let attrs[key] = attribute;
            }
        }

        for key, value in attributes {
            if !isset attrs[key] {
                let attrs[key] = value;
            }
        }

        let escaper = <EscaperInterface> self::getEscaper(attributes);

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
     * Renders the title with title tags. The title is automatically escaped
     */
    public static function renderTitle(bool prepend = true, bool append = true) -> string
    {
        return "<title>" . self::getTitle(prepend, append) . "</title>" . PHP_EOL;
    }

    /**
     * Resets the request and internal values to avoid those fields will have
     * any default value.
     *
     * @deprecated Will be removed in 4.0.0
     */
    deprecated public static function resetInput() -> void
    {
        let self::displayValues = [],
            self::documentTitle = null,
            self::documentAppendTitle = [],
            self::documentPrependTitle = [],
            self::documentTitleSeparator = null;
    }

    /**
     * Builds a HTML input[type="search"] tag
     *
     * @param array parameters = [
     *     'class' => '',
     *     'name' => '',
     *     'src' => '',
     *     'id' => '',
     *     'value' => ''
     * ]
     */
    public static function searchField(var parameters) -> string
    {
        return self::inputField("search", parameters);
    }

    /**
     * Builds a HTML SELECT tag using a Phalcon\Mvc\Model resultset as options
     *
     * @param array parameters = [
     *     'id' => '',
     *     'name' => '',
     *     'value' => '',
     *     'useEmpty' => false,
     *     'emptyValue' => '',
     *     'emptyText' => '',
     * ]
     */
    public static function select(var parameters, data = null) -> string
    {
        return Select::selectField(parameters, data);
    }

    /**
     * Builds a HTML SELECT tag using a PHP array for options
     *
     * @param array parameters = [
     *     'id' => '',
     *     'name' => '',
     *     'value' => '',
     *     'useEmpty' => false,
     *     'emptyValue' => '',
     *     'emptyText' => '',
     * ]
     */
    public static function selectStatic(parameters, data = null) -> string
    {
        return Select::selectField(parameters, data);
    }

    /**
     * Set autoescape mode in generated html
     */
    public static function setAutoescape(bool autoescape) -> void
    {
        let self::autoEscape = autoescape;
    }

    /**
     * Assigns default values to generated tags by helpers
     */
    public static function setDefault(string! id, value) -> void
    {
        if value !== null {
            if unlikely (typeof value == "array" || typeof value == "object") {
                throw new Exception(
                    "Only scalar values can be assigned to UI components"
                );
            }
        }

        let self::displayValues[id] = value;
    }

    /**
     * Assigns default values to generated tags by helpers
     */
    public static function setDefaults(array! values, bool merge = false) -> void
    {
        if merge && typeof self::displayValues == "array" {
            let self::displayValues = array_merge(self::displayValues, values);
        } else {
            let self::displayValues = values;
        }
    }

    /**
     * Sets the dependency injector container.
     */
    public static function setDI(<DiInterface> container) -> void
    {
        let self::container = container;
    }

    /**
     * Set the document type of content
     */
    public static function setDocType(int doctype) -> void
    {
        if doctype < self::HTML32 || doctype > self::XHTML5 {
            let self::documentType = self::HTML5;
        } else {
            let self::documentType = doctype;
        }
    }

    /**
     * Set the title of view content
     */
    public static function setTitle(string title) -> void
    {
        let self::documentTitle = title;
    }

    /**
     * Set the title separator of view content
     */
    public static function setTitleSeparator(string titleSeparator) -> void
    {
        let self::documentTitleSeparator = titleSeparator;
    }

    /**
     * Builds a LINK[rel="stylesheet"] tag
     */
    public static function stylesheetLink(var parameters = null, bool local = true) -> string
    {
        var params, code;

        if typeof parameters != "array" {
            let params = [parameters, local];
        } else {
            let params = parameters;
        }

        if isset params[1] {
            let local = (bool) params[1];
        } else {
            if isset params["local"] {
                let local = (bool) params["local"];

                unset params["local"];
            }
        }

        if !isset params["type"] {
            let params["type"] = "text/css";
        }

        if !isset params["href"] {
            if isset params[0] {
                let params["href"] = params[0];
            } else {
                let params["href"] = "";
            }
        }

        /**
         * URLs are generated through the "url" service
         */
        if local {
            let params["href"] = self::getUrlService()->getStatic(
                params["href"]
            );
        }

        if !isset params["rel"] {
            let params["rel"] = "stylesheet";
        }

        let code = self::renderAttributes("<link", params);

        /**
         * Check if Doctype is XHTML
         */
        if self::documentType > self::HTML5 {
            let code .= " />" . PHP_EOL;
        } else {
            let code .= ">" . PHP_EOL;
        }

        return code;
    }

    /**
     * Builds a HTML input[type="submit"] tag
     */
    public static function submitButton(var parameters) -> string
    {
        return self::inputField("submit", parameters, true);
    }

    /**
     * Builds a HTML tag
     */
    public static function tagHtml(
        string tagName,
        var parameters = null,
        bool selfClose = false,
        bool onlyStart = false,
        bool useEol = false
    ) -> string
    {
        var params, localCode;

        if typeof parameters != "array" {
            let params = [parameters];
        } else {
            let params = parameters;
        }

        let localCode = self::renderAttributes("<" . tagName, params);

        /**
         * Check if Doctype is XHTML
         */
        if self::documentType > self::HTML5 {
            if selfClose {
                let localCode .= " />";
            } else {
                let localCode .= ">";
            }
        } else {
            if onlyStart {
                let localCode .= ">";
            } else {
                let localCode .= "></" . tagName . ">";
            }
        }

        if useEol {
            let localCode .= PHP_EOL;
        }

        return localCode;
    }

    /**
     * Builds a HTML tag closing tag
     */
    public static function tagHtmlClose(string tagName, bool useEol = false) -> string
    {
        if useEol {
            return "</" . tagName . ">" . PHP_EOL;
        }

        return "</" . tagName . ">";
    }

    /**
    * Builds a HTML input[type="tel"] tag
    *
    * @param array parameters = [
    *     'id' => '',
    *     'name' => '',
    *     'value' => '',
    *     'class' => ''
    * ]
    */
    public static function telField(var parameters) -> string
    {
        return self::inputField("tel", parameters);
    }

    /**
     * Builds a HTML TEXTAREA tag
     *
     * @paraym array parameters = [
     *     'id' => '',
     *     'name' => '',
     *     'value' => '',
     *     'class' => ''
     * ]
     */
    public static function textArea(var parameters) -> string
    {
        var params, id, name, content, code;

        if typeof parameters != "array" {
            let params = [parameters];
        } else {
            let params = parameters;
        }

        if !isset params[0] {
            if isset params["id"] {
                let params[0] = params["id"];
            }
        }

        let id = params[0];

        if !isset params["name"] {
            let params["name"] = id;
        } else {
            let name = params["name"];

            if empty name {
                let params["name"] = id;
            }
        }

        if !isset params["id"] {
            let params["id"] = id;
        }

        if isset params["value"] {
            let content = params["value"];

            unset params["value"];
        } else {
            let content = self::getValue(id, params);
        }

        let code = self::renderAttributes("<textarea", params),
            code .= ">" . htmlspecialchars(content) . "</textarea>";

        return code;
    }

    /**
     * Builds a HTML input[type="text"] tag
     *
     * @param array parameters = [
     *     'id' => '',
     *     'name' => '',
     *     'value' => '',
     *     'class' => ''
     * ]
     */
    public static function textField(var parameters) -> string
    {
        return self::inputField("text", parameters);
    }

    /**
     * Builds a HTML input[type="time"] tag
     *
     * @param array paramters = [
     *     'id' => '',
     *     'name' => '',
     *     'value' => '',
     *     'class' => ''
     * ]
     */
    public static function timeField(var parameters) -> string
    {
        return self::inputField("time", parameters);
    }

    /**
     * Builds a HTML input[type="url"] tag
     *
     * @param array paramters = [
     *     'id' => '',
     *     'name' => '',
     *     'value' => '',
     *     'class' => ''
     * ]
     */
    public static function urlField(var parameters) -> string
    {
        return self::inputField("url", parameters);
    }

    /**
     * Builds a HTML input[type="week"] tag
     *
     * @param array parameters = [
     *     'id' => '',
     *     'name' => '',
     *     'value' => '',
     *     'class' => ''
     * ]
     */
    public static function weekField(var parameters) -> string
    {
        return self::inputField("week", parameters);
    }

    /**
     * Builds generic INPUT tags
     *
     * @param array paramters = [
     *     'id' => '',
     *     'name' => '',
     *     'value' => '',
     *     'class' => '',
     *     'type' => ''
     * ]
     */
    static final protected function inputField(string type, parameters, bool asValue = false) -> string
    {
        var params, id, value, code, name;

        let params = [];

        if typeof parameters != "array" {
            let params[] = parameters;
        } else {
            let params = parameters;
        }

        if asValue == false {
            if !fetch id, params[0] {
                let params[0] = params["id"];
            }

            if fetch name, params["name"] {
                if empty name {
                    let params["name"] = id;
                }
            } else {
                let params["name"] = id;
            }

            /**
             * Automatically assign the id if the name is not an array
             */
            if typeof id == "string" {
                if !memstr(id, "[") && !isset params["id"] {
                    let params["id"] = id;
                }
            }

            let params["value"] = self::getValue(id, params);
        } else {
            /**
             * Use the "id" as value if the user hadn't set it
             */
            if !isset params["value"] {
                if fetch value, params[0] {
                    let params["value"] = value;
                }
            }
        }

        let params["type"] = type,
            code = self::renderAttributes("<input", params);

        /**
         * Check if Doctype is XHTML
         */
        if self::documentType > self::HTML5 {
            let code .= " />";
        } else {
            let code .= ">";
        }

        return code;
    }

    /**
     * Builds INPUT tags that implements the checked attribute
     */
    static final protected function inputFieldChecked(string type, var parameters) -> string
    {
        var params, value, id, code, name, currentValue;

        if  typeof parameters != "array" {
            let params = [parameters];
        } else {
            let params = parameters;
        }

        if !isset params[0] {
            let params[0] = params["id"];
        }

        let id = params[0];

        if !isset params["name"] {
            let params["name"] = id;
        } else {
            let name = params["name"];

            if empty name {
                let params["name"] = id;
            }
        }

        /**
        * Automatically assign the id if the name is not an array
        */
        if !strpos(id, "[") {
            if !isset params["id"] {
                let params["id"] = id;
            }
        }

        /**
         * Automatically check inputs
         */
        if fetch currentValue, params["value"] {
            unset params["value"];

            let value = self::getValue(id, params);

            if value != null && currentValue == value {
                let params["checked"] = "checked";
            }

            let params["value"] = currentValue;
        } else {
            let value = self::getValue(id, params);

            /**
            * Evaluate the value in POST
            */
            if value != null {
                let params["checked"] = "checked";
            }

            /**
            * Update the value anyways
            */
            let params["value"] = value;
        }

        let params["type"] = type,
            code = self::renderAttributes("<input", params);

        /**
         * Check if Doctype is XHTML
         */
        if self::documentType > self::HTML5 {
            let code .= " />";
        } else {
            let code .= ">";
        }

        return code;
    }
}
