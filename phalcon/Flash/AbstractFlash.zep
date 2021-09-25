
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

namespace Phalcon\Flash;

use Phalcon\Di;
use Phalcon\Di\DiInterface;
use Phalcon\Di\AbstractInjectionAware;
use Phalcon\Escaper\EscaperInterface;
use Phalcon\Session\ManagerInterface as SessionInterface;
use Phalcon\Support\Helper\Str\Interpolate;

/**
 * Shows HTML notifications related to different circumstances. Classes can be
 * stylized using CSS
 *
 *```php
 * $flash->success("The record was successfully deleted");
 * $flash->error("Cannot open the file");
 *```
 */
abstract class AbstractFlash extends AbstractInjectionAware implements FlashInterface
{
    /**
     * @var bool
     */
    protected autoescape = true { get };

    /**
     * @var bool
     */
    protected automaticHtml = true;

    /**
     * @var array
     */
    protected cssClasses = [] { get };

    /**
     * @var array
     */
    protected cssIconClasses = [] { get };

    /**
     * @var string
     */
    protected customTemplate = "" { get };

    /**
     * @var EscaperInterface | null
     */
    protected escaperService = null;

    /**
     * @var bool
     */
    protected implicitFlush = true;

    /**
     * @var Interpolate
     */
    protected interpolator;

    /**
     * @var array
     */
    protected messages = [];

    /**
     * @var SessionInterface | null
     */
    protected sessionService = null;

    /**
     * Phalcon\Flash constructor
     */
    public function __construct(<EscaperInterface> escaper = null, <SessionInterface> session = null)
    {
        let this->escaperService = escaper,
            this->sessionService = session,
            this->interpolator   = new Interpolate();

        let this->cssClasses = [
            "error"   : "errorMessage",
            "notice"  : "noticeMessage",
            "success" : "successMessage",
            "warning" : "warningMessage"
        ];
    }

    /**
     * Clears accumulated messages when implicit flush is disabled
     */
    public function clear() -> void
    {
        let this->messages = [];
    }

    /**
     * Shows a HTML error message
     *
     *```php
     * $flash->error("This is an error");
     *```
     *
     * @return null|string|void
     */
    public function error(string message) -> string | null
    {
        return this->{"message"}("error", message);
    }

    /**
     * Returns the Escaper Service
     */
    public function getEscaperService() -> <EscaperInterface>
    {
        var container;

        if this->escaperService {
            return this->escaperService;
        }

        let container = <DiInterface> this->container;
        if unlikely typeof container != "object" {
            throw new Exception(
                Exception::containerServiceNotFound("the 'escaper' service")
            );
        }

        if likely container->has("escaper") {
            return <RequestInterface> container->getShared("escaper");
        } else {
            throw new Exception(
                Exception::containerServiceNotFound("the 'escaper' service")
            );
        }
    }

    /**
     * Shows a HTML notice/information message
     *
     *```php
     * $flash->notice("This is an information");
     *```
     *
     * @return null|string|void
     */
    public function notice(string message) -> string | null
    {
        return this->{"message"}("notice", message);
    }

    /**
     * Set the autoescape mode in generated HTML
     */
    public function setAutoescape(bool autoescape) -> <FlashInterface>
    {
        let this->autoescape = autoescape;

        return this;
    }

    /**
     * Set if the output must be implicitly formatted with HTML
     */
    public function setAutomaticHtml(bool automaticHtml) -> <FlashInterface>
    {
        let this->automaticHtml = automaticHtml;

        return this;
    }

    /**
     * Set an array with CSS classes to format the messages
     */
    public function setCssClasses(array! cssClasses) -> <FlashInterface>
    {
        let this->cssClasses = cssClasses;

        return this;
    }

    /**
     * Set an array with CSS classes to format the icon messages
     */
    public function setCssIconClasses(array! cssIconClasses) -> <FlashInterface>
    {
        let this->cssIconClasses  = cssIconClasses;

        return this;
    }

    /**
     * Set a custom template for showing the messages
     */
    public function setCustomTemplate(string! customTemplate) -> <FlashInterface>
    {
        let this->customTemplate = customTemplate;

        return this;
    }

    /**
     * Sets the Escaper Service
     */
    public function setEscaperService(<EscaperInterface> escaperService) -> <FlashInterface>
    {
        let this->escaperService = escaperService;

        return this;
    }

    /**
     * Set whether the output must be implicitly flushed to the output or
     * returned as string
     */
    public function setImplicitFlush(bool implicitFlush) -> <FlashInterface>
    {
        let this->implicitFlush = implicitFlush;

        return this;
    }

    /**
     * Shows a HTML success message
     *
     *```php
     * $flash->success("The process was finished successfully");
     *```
     *
     * @return null|string|void
     */
    public function success(string message) -> string | null
    {
        return this->{"message"}("success", message);
    }

    /**
     * Outputs a message formatting it with HTML
     *
     *```php
     * $flash->outputMessage("error", $message);
     *```
     *
     * @param string|array message
     * @return null|string|void
     */
    public function outputMessage(string type, var message)
    {
        var content, html, item, prepared;

        let content = "";

        if typeof message !== "array" && typeof message !== "string" {
            throw new Exception("The message must be an array or a string");
        }

        /**
         * Make this an array. Same code processes string and array
         */
        if typeof message !== "array" {
            let message = [message];
        }

        for item in message {
            let prepared = this->prepareEscapedMessage(item),
                html     = this->prepareHtmlMessage(type, prepared);

            if (true === this->implicitFlush) {
                echo html;
            } else {
                let content          .= html,
                    this->messages[] = html;
            }
        }

        /**
         * We return the message as a string if the implicitFlush is turned
         * off
         */
        if (true !== this->implicitFlush) {
            return content;
        }

        return null;
    }

    /**
     * Shows a HTML warning message
     *
     *```php
     * $flash->warning("Hey, this is important");
     *```
     *
     * @return null|string|void
     */
    public function warning(string message) -> string | null
    {
        return this->{"message"}("warning", message);
    }

    /**
     * Gets the template (custom or default)
     */
    private function getTemplate(string cssClassses, string cssIconClasses) -> string
    {
        string divString, iconString, template;

        let template   = "<div%divString%>%iconString%%message%</div>" . PHP_EOL,
            divString  = "",
            iconString = "";

        if !empty this->customTemplate {
            return this->customTemplate;
        }

        if !empty cssClassses {
            let divString = " class=\"%cssClass%\"";
            if !empty cssIconClasses {
                let iconString = "<i class=\"%cssIconClass%\"></i> ";
            }
        }

        return this->interpolator->__invoke(
            template,
            [
                "divString"  : divString,
                "iconString" : iconString
            ]
        );
    }

    /**
     * Returns the message escaped if the autoEscape is true, otherwise the
     * original message is returned
     */
    private function prepareEscapedMessage(string message) -> string
    {
        var autoEscape, escaper;

        let autoEscape = (bool) this->autoescape;

        if !autoEscape {
            return message;
        }

        let escaper = this->getEscaperService();

        return escaper->escapeHtml(message);
    }

    /**
     * Prepares the HTML output for the message. If automaticHtml is not set
     * then the original message is returned
     */
    private function prepareHtmlMessage(string type, string message) -> string
    {
        var cssClasses, cssIconClasses;

        if true !== this->automaticHtml {
            return message;
        }

        let cssClasses     = this->checkClasses(this->cssClasses, type),
            cssIconClasses = this->checkClasses(this->cssIconClasses, type);

        return this->interpolator->__invoke(
            this->getTemplate(cssClasses, cssIconClasses),
            [
                "cssClass"     : cssClasses,
                "cssIconClass" : cssIconClasses,
                "message"      : message
            ]
        );
    }

    /**
     * Checks the collection and returns the content as a string
     * (array is joined)
     */
    private function checkClasses(array collection, string type) -> string
    {
        var content;

        let content = "";

        if isset collection[type] {
            let content = collection[type];
        }

        if true !== empty(content) {
            if typeof content !== "array" {
                let content = [content];
            }

            let content = join(" ", content);
        }

        return content;
    }
}
