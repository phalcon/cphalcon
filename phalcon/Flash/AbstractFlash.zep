
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
        bool implicitFlush;
        var content, msg, htmlMessage, preparedMsg;

        let implicitFlush = this->implicitFlush;

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

        let template     = "<div%divString%>%iconString%%message%</div>" . PHP_EOL,
            divString    = "",
            iconString   = "";

        if !empty this->customTemplate {
            return this->customTemplate;
        }

        if !empty cssClassses || !empty cssIconClasses {
            let divString = " class=\"%cssClass%\"";
            if !empty cssIconClasses {
                let iconString = "<i class=\"%cssIconClasses%\"></i> ";
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
        var classes, cssClasses, cssIconClasses, typeClasses, typeIconClasses, automaticHtml;

        let automaticHtml = this->automaticHtml;

        if true !== automaticHtml {
            return message;
        }

        let classes        = this->cssClasses,
            cssIconClasses = this->cssIconClasses;

        if fetch typeClasses, classes[type] {
            if typeof typeClasses == "array" {
                let cssClasses = join(" ", typeClasses);
            } else {
                let cssClasses = typeClasses;
            }
        } else {
            let cssClasses = "";
        }

        if fetch typeIconClasses, cssIconClasses[type] {
            if typeof typeIconClasses == "array" {
                let cssIconClasses = join(" ", typeIconClasses);
            } else {
                let cssIconClasses = typeIconClasses;
            }
        } else {
            let cssIconClasses = "";
        }


        return this->interpolator->__invoke(
            this->getTemplate(cssClasses, cssIconClasses),
            [
                "cssClass"     : cssClasses,
                "iconCssClass" : cssIconClasses,
                "message"      : message
            ]
        );
    }
}
