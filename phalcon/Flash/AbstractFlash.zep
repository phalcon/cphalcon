
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Flash;

use Phalcon\Contracts\Flash\FlashTypes;
use Phalcon\Di\Di;
use Phalcon\Di\DiInterface;
use Phalcon\Di\AbstractInjectionAware;
use Phalcon\Flash\Exceptions\EscaperServiceUnavailable;
use Phalcon\Flash\Exceptions\FlashMessageNotStringOrArray;
use Phalcon\Html\Escaper\EscaperInterface;
use Phalcon\Session\ManagerInterface as SessionInterface;
use Phalcon\Traits\Support\Helper\Str\InterpolateTrait;

/**
 * Shows HTML notifications related to different circumstances. Classes can be
 * stylized using CSS
 *
 *```php
 * $flash->success("The record was successfully deleted");
 * $flash->error("Cannot open the file");
 *```
 *
 * @phpstan-import-type flash_messages from FlashTypes
 * @phpstan-import-type flash_css_classes from FlashTypes
 */
abstract class AbstractFlash extends AbstractInjectionAware implements FlashInterface
{
    use InterpolateTrait;

    protected bool autoescape = true;
    protected bool automaticHtml = true;
    /**
     * @phpstan-var flash_css_classes
     */
    protected array cssClasses = [];
    /**
     * @phpstan-var flash_css_classes
     */
    protected array cssIconClasses = [];
    protected string customTemplate = "";
    protected ?<EscaperInterface> escaperService = null;
    protected bool implicitFlush = true;
    /**
     * @phpstan-var flash_messages
     */
    protected array messages = [];
    protected ?<SessionInterface> sessionService = null;

    /**
     * AbstractFlash constructor.
     */
    public function __construct(
        <EscaperInterface> escaper = null,
        <SessionInterface> session = null
    ) {
        let this->escaperService = escaper,
            this->sessionService = session;

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
     */
    public function error(string message) -> string | null
    {
        return this->message("error", message);
    }

    /**
     * Returns the flag that defines whether to automatically escape content or not
     */
    public function getAutoescape() -> bool
    {
        return this->autoescape;
    }

    /**
     * Returns the flag that defines whether to automatically use HTML or not
     */
    public function getAutomaticHtml() -> bool
    {
        return this->automaticHtml;
    }

    /**
     * Returns the array of the CSS classes for formatting messages. The key is
     * the type of message and the value is the CSS class
     *
     * @phpstan-return flash_css_classes
     */
    public function getCssClasses() -> array
    {
        return this->cssClasses;
    }

    /**
     * Returns the array of the icon CSS classes for formatting messages. The
     * key is the type of message and the value is the icon CSS class
     *
     * @phpstan-return flash_css_classes
     */
    public function getCssIconClasses() -> array
    {
        return this->cssIconClasses;
    }

    /**
     * Returns the custom template for formatting messages

     */
    public function getCustomTemplate() -> string
    {
        return this->customTemplate;
    }

    /**
     * Returns the Escaper Service
     *
     * @throws Exception
     */
    public function getEscaperService() -> <EscaperInterface>
    {
        if null !== this->escaperService {
            return this->escaperService;
        }

        if (
            null !== this->container &&
            true === this->container->has("escaper")
        ) {
            let this->escaperService = this->container->getShared("escaper");

            return this->escaperService;
        }

        throw new EscaperServiceUnavailable();
    }

    /**
     * Outputs a message. Delivery semantics differ per implementation:
     * `Direct` renders and emits immediately, `Session` stores the raw
     * message for output on a later request.
     */
    abstract public function message(string type, var message) -> string | null;

    /**
     * Shows a HTML notice/information message
     *
     *```php
     * $flash->notice("This is an information");
     *```
     */
    public function notice(string message) -> string | null
    {
        return this->message("notice", message);
    }

    /**
     * Outputs a message formatting it with HTML
     *
     *```php
     * $flash->outputMessage("error", $message);
     *```
     *
     * @throws Exception
     */
    public function outputMessage(string type, var message) -> string | null
    {
        var content, html, item, prepared;

        let content = "";

        if typeof message !== "array" && typeof message !== "string" {
            throw new FlashMessageNotStringOrArray();
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
         * If we are here then implicitFlush is off - otherwise it has been
         * echoed back during the loop. Return the string back.
         */
        return content;
    }

    /**
     * Set the autoescape mode in generated HTML
     */
    public function setAutoescape(bool autoescape) -> <static>
    {
        let this->autoescape = autoescape;

        return this;
    }

    /**
     * Set if the output must be implicitly formatted with HTML
     */
    public function setAutomaticHtml(bool automaticHtml) -> <static>
    {
        let this->automaticHtml = automaticHtml;

        return this;
    }

    /**
     * Set an array with CSS classes to format the messages
     *
     * @phpstan-param flash_css_classes $cssClasses
     */
    public function setCssClasses(array cssClasses) -> <static>
    {
        let this->cssClasses = cssClasses;

        return this;
    }

    /**
     * Set an array with CSS classes to format the icon messages
     *
     * @phpstan-param flash_css_classes $cssIconClasses
     */
    public function setCssIconClasses(array cssIconClasses) -> <static>
    {
        let this->cssIconClasses  = cssIconClasses;

        return this;
    }

    /**
     * Set a custom template for showing the messages
     */
    public function setCustomTemplate(string customTemplate) -> <static>
    {
        let this->customTemplate = customTemplate;

        return this;
    }

    /**
     * Sets the Escaper Service
     */
    public function setEscaperService(<EscaperInterface> escaperService) -> <static>
    {
        let this->escaperService = escaperService;

        return this;
    }

    /**
     * Set whether the output must be implicitly flushed to the output or
     * returned as string
     *
     * Note: `output()` is an echo API and requires implicit flush to remain
     * enabled (the default). With implicit flush disabled, `message()` returns
     * the rendered string while `output()` does not emit it.
     */
    public function setImplicitFlush(bool implicitFlush) -> <static>
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
     */
    public function success(string message) -> string | null
    {
        return this->message("success", message);
    }

    /**
     * Shows a HTML warning message
     *
     *```php
     * $flash->warning("Hey, this is important");
     *```
     */
    public function warning(string message) -> string | null
    {
        return this->message("warning", message);
    }

    /**
     * Checks the collection and returns the content as a string
     * (array is joined)
     *
     * @phpstan-param flash_css_classes $collection
     */
    private function checkClasses(array collection, string type) -> string
    {
        var content;

        let content = "";

        if isset collection[type] {
            let content = collection[type];
        }

        if typeof content !== "array" {
            let content = [content];
        }

        return join(" ", content);
    }

    /**
     * Returns the template for the CSS classes (with icon classes). It will
     * either be the custom one (defined) or the default
     */
    private function getTemplate(string cssClasses, string cssIconClasses) -> string
    {
        string divString, iconString, template;

        let template   = "<div%divString%>%iconString%%message%</div>" . PHP_EOL,
            divString  = "",
            iconString = "";

        if !empty this->customTemplate {
            return this->customTemplate;
        }

        if !empty cssClasses {
            let divString = " class=\"%cssClass%\"";
            if !empty cssIconClasses {
                let iconString = "<i class=\"%cssIconClass%\"></i> ";
            }
        }

        return this->toInterpolate(
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
        var escaper;

        if true !== this->autoescape {
            return message;
        }

        let escaper = this->getEscaperService();

        return escaper->html(message);
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

        /**
         * The class lands in a `class="…"` attribute. Escape it so a crafted
         * class cannot break out of the attribute.
         */
        let cssClasses     = htmlspecialchars(this->checkClasses(this->cssClasses, type), ENT_QUOTES, "utf-8"),
            cssIconClasses = htmlspecialchars(this->checkClasses(this->cssIconClasses, type), ENT_QUOTES, "utf-8");

        return this->toInterpolate(
            this->getTemplate(cssClasses, cssIconClasses),
            [
                "cssClass"     : cssClasses,
                "cssIconClass" : cssIconClasses,
                "message"      : message
            ]
        );
    }
}
