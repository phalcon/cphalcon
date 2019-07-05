
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Flash;

use Phalcon\Di;
use Phalcon\Di\DiInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Escaper\EscaperInterface;
use Phalcon\Flash\Exception;

/**
 * Shows HTML notifications related to different circumstances. Classes can be
 * stylized using CSS
 *
 *```php
 * $flash->success("The record was successfully deleted");
 * $flash->error("Cannot open the file");
 *```
 */
abstract class AbstractFlash implements FlashInterface, InjectionAwareInterface
{
    /**
     * @var bool
     */
    protected autoescape = true;

    /**
     * @var bool
     */
    protected automaticHtml = true;

    /**
     * @var array
     */
    protected cssClasses = [];

    /**
     * @var string
     */
    protected customTemplate = "";

    protected container = null;

    protected escaperService = null;

    /**
     * @var bool
     */
    protected implicitFlush = true;

    protected messages = [];

    /**
     * Phalcon\Flash constructor
     */
    public function __construct(cssClasses = null) -> void
    {
        if typeof cssClasses != "array" {
            let cssClasses = [
                "error":   "errorMessage",
                "notice":  "noticeMessage",
                "success": "successMessage",
                "warning": "warningMessage"
            ];
        }

        let this->cssClasses = cssClasses;
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
    public function error(string message) -> string
    {
        return this->{"message"}("error", message);
    }

    /**
     * Returns the autoescape mode in generated html
     */
    public function getAutoescape() -> bool
    {
        return this->autoescape;
    }

    /**
     * Returns the custom template set
     */
    public function getCustomTemplate() -> string
    {
        return this->customTemplate;
    }

    /**
     * Returns the internal dependency injector
     */
    public function getDI() -> <DiInterface>
    {
        var di;

        let di = this->container;

        if typeof di != "object" {
            let di = Di::getDefault();
        }

        return di;
    }

    /**
     * Returns the Escaper Service
     */
    public function getEscaperService() -> <EscaperInterface>
    {
        var escaper, container;

        let escaper = this->escaperService;

        if typeof escaper != "object" {
            let container = <DiInterface> this->getDI();

            let escaper = <EscaperInterface> container->getShared("escaper"),
                this->escaperService = escaper;
        }

        return escaper;
    }
    /**
     * Shows a HTML notice/information message
     *
     *```php
     * $flash->notice("This is an information");
     *```
     */
    public function notice(string message) -> string
    {
        return this->{"message"}("notice", message);
    }

    /**
     * Set the autoescape mode in generated html
     */
    public function setAutoescape(bool autoescape) -> <Flash>
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
     * Set an custom template for showing the messages
     */
    public function setCustomTemplate(string! customTemplate) -> <FlashInterface>
    {
        let this->customTemplate = customTemplate;

        return this;
    }

    /**
     * Sets the dependency injector
     */
    public function setDI(<DiInterface> container) -> <FlashInterface>
    {
        let this->container = container;

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
     */
    public function success(string message) -> string
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
     * @return string|void
     */
    public function outputMessage(string type, var message)
    {
        bool implicitFlush;
        var content, msg, htmlMessage, preparedMsg;

        let implicitFlush = (bool) this->implicitFlush;

        if typeof message == "array" {
            /**
             * We create the message with implicit flush or other
             */
            if !implicitFlush {
                let content = "";
            }

            /**
             * We create the message with implicit flush or other
             */
            for msg in message {
                /**
                 * Check if the message needs to be escaped
                 */
                let preparedMsg = this->prepareEscapedMessage(msg);

                /**
                 * We create the applying formatting or not
                 */
                let htmlMessage = this->prepareHtmlMessage(type, preparedMsg);

                if implicitFlush {
                    echo htmlMessage;
                } else {
                    let content .= htmlMessage;
                    let this->messages[] = htmlMessage;
                }
            }

            /**
             * We return the message as a string if the implicitFlush is turned
             * off
             */
            if !implicitFlush {
                return content;
            }
        } else {
            /**
             * Check if the message needs to be escaped
             */
            let preparedMsg = this->prepareEscapedMessage(message);

            /**
             * We create the applying formatting or not
             */
            let htmlMessage = this->prepareHtmlMessage(type, preparedMsg);

            /**
             * We return the message as a string if the implicitFlush is turned
             * off
             */
            if implicitFlush {
                echo htmlMessage;
            } else {
                let this->messages[] = htmlMessage;

                return htmlMessage;
            }
        }
    }

    /**
     * Shows a HTML warning message
     *
     *```php
     * $flash->warning("Hey, this is important");
     *```
     */
    public function warning(string message) -> string
    {
        return this->{"message"}("warning", message);
    }


    private function getTemplate(string cssClassses) -> string
    {
        if "" === this->customTemplate {
            if "" === cssClassses {
                return "<div>%message%</div>" . PHP_EOL;
            } else {
                return "<div class=\"%cssClass%\">%message%</div>" . PHP_EOL;
            }
        }

        return this->customTemplate;
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
        var classes, cssClasses, typeClasses, automaticHtml;

        let automaticHtml = (bool) this->automaticHtml;

        if !automaticHtml {
            return message;
        }

        let classes = this->cssClasses;

        if fetch typeClasses, classes[type] {
            if typeof typeClasses == "array" {
                let cssClasses = join(" ", typeClasses);
            } else {
                let cssClasses = typeClasses;
            }
        } else {
            let cssClasses = "";
        }

        return str_replace(
            [
                "%cssClass%",
                "%message%"
            ],
            [
                cssClasses,
                message
            ],
            this->getTemplate(cssClasses)
        );
    }
}
