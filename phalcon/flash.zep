
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon;

use Phalcon\Flash\Exception;
use Phalcon\Di\InjectionAwareInterface;

/**
 * Phalcon\Flash
 *
 * Shows HTML notifications related to different circumstances. Classes can be stylized using CSS
 *
 *<code>
 * $flash->success("The record was successfully deleted");
 * $flash->error("Cannot open the file");
 *</code>
 */
abstract class Flash implements FlashInterface, InjectionAwareInterface
{

	protected _autoescape = true;

	protected _automaticHtml = true;

	protected _cssClasses;

	protected _customTemplate = "";

	protected _dependencyInjector = null;

	protected _escaperService = null;

	protected _implicitFlush = true;

	protected _messages;

	/**
	 * Phalcon\Flash constructor
	 */
	public function __construct(cssClasses = null)
	{
		if typeof cssClasses != "array" {
			let cssClasses = [
				"error": "errorMessage",
				"notice": "noticeMessage",
				"success": "successMessage",
				"warning": "warningMessage"
			];
		}
		let this->_cssClasses = cssClasses;
	}

	/**
	 * Clears accumulated messages when implicit flush is disabled
	 */
	public function clear() -> void
	{
		let this->_messages = [];
	}

	/**
	 * Shows a HTML error message
	 *
	 *<code>
	 * $flash->error("This is an error");
	 *</code>
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
		return this->_autoescape;
	}

	/**
	 * Returns the custom template set
	 */
	public function getCustomTemplate() -> string
	{
		return this->_customTemplate;
	}

	/**
	 * Returns the internal dependency injector
	 */
	public function getDI() -> <DiInterface>
	{
		var di;
		let di = this->_dependencyInjector;

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
		var escaper, dependencyInjector;

		let escaper = this->_escaperService;
		if typeof escaper != "object" {
			let dependencyInjector = <DiInterface> this->getDI();

			let escaper = <EscaperInterface> dependencyInjector->getShared("escaper"),
				this->_escaperService = escaper;
		}

		return escaper;
	}
	/**
	 * Shows a HTML notice/information message
	 *
	 *<code>
	 * $flash->notice("This is an information");
	 *</code>
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
		let this->_autoescape = autoescape;
		return this;
	}

	/**
	 * Set if the output must be implicitly formatted with HTML
	 */
	public function setAutomaticHtml(bool automaticHtml) -> <FlashInterface>
	{
		let this->_automaticHtml = automaticHtml;
		return this;
	}

	/**
	 * Set an array with CSS classes to format the messages
	 */
	public function setCssClasses(array! cssClasses) -> <FlashInterface>
	{
		let this->_cssClasses = cssClasses;
		return this;
	}

	/**
	 * Set an custom template for showing the messages
	 */
	public function setCustomTemplate(string! customTemplate) -> <FlashInterface>
	{
		let this->_customTemplate = customTemplate;
		return this;
	}

	/**
	 * Sets the dependency injector
	 */
	public function setDI(<DiInterface> dependencyInjector) -> <Flash>
	{
		let this->_dependencyInjector = dependencyInjector;
		return this;
	}

	/**
	 * Sets the Escaper Service
	 */
	public function setEscaperService(<EscaperInterface> escaperService) -> <Flash>
	{
		let this->_escaperService = escaperService;
		return this;
	}

	/**
	 * Set whether the output must be implicitly flushed to the output or returned as string
	 */
	public function setImplicitFlush(bool implicitFlush) -> <FlashInterface>
	{
		let this->_implicitFlush = implicitFlush;
		return this;
	}

	/**
	 * Shows a HTML success message
	 *
	 *<code>
	 * $flash->success("The process was finished successfully");
	 *</code>
	 */
	public function success(string message) -> string
	{
		return this->{"message"}("success", message);
	}

	/**
	 * Outputs a message formatting it with HTML
	 *
	 *<code>
	 * $flash->outputMessage("error", $message);
	 *</code>
	 *
	 * @param string|array message
	 * @return string|void
	 */
	public function outputMessage(string type, var message)
	{
		bool implicitFlush;
		var content, msg,
			htmlMessage, preparedMsg;

		let implicitFlush = (bool) this->_implicitFlush;
		if typeof message == "array" {

			/**
			 * We create the message with implicit flush or other
			 */
			if implicitFlush === false {
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

				if implicitFlush === true {
					echo htmlMessage;
				} else {
					let content .= htmlMessage;
					let this->_messages[] = htmlMessage;
				}
			}

			/**
			 * We return the message as string if the implicitFlush is turned off
			 */
			if implicitFlush === false {
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
			 * We return the message as string if the implicit_flush is turned off
			 */
			if implicitFlush === true {
				echo htmlMessage;
			} else {
				let this->_messages[] = htmlMessage;
				return htmlMessage;
			}
		}
	}

	/**
	 * Shows a HTML warning message
	 *
	 *<code>
	 * $flash->warning("Hey, this is important");
	 *</code>
	 */
	public function warning(string message) -> string
	{
		return this->{"message"}("warning", message);
	}


	private function getTemplate(string cssClassses) -> string
	{
		if ("" === this->_customTemplate) {
			if ("" === cssClassses) {
				return "<div>%message%</div>" . PHP_EOL;
			} else {
				return "<div class=\"%cssClass%\">%message%</div>" . PHP_EOL;
			}
		}

		return this->_customTemplate;
	}

	/**
	 * Returns the message escaped if the autoEscape is true, otherwise the
	 * original message is returned
	 */
	private function prepareEscapedMessage(string message) -> string
	{
		var autoEscape, escaper;

		let autoEscape = (bool) this->_autoescape;

		if autoEscape === true {
			let escaper = this->getEscaperService();
			return escaper->escapeHtml(message);
		} else {
			return message;
		}
	}

	/**
	 * Prepares the HTML output for the message. If automaticHtml is not set then
	 * the original message is returned
	 */
	private function prepareHtmlMessage(string type, string message) -> string
	{
		var classes, cssClasses, typeClasses, automaticHtml;

		let automaticHtml = (bool) this->_automaticHtml;

		if automaticHtml === true {
			let classes = this->_cssClasses;
			if fetch typeClasses, classes[type] {
				if typeof typeClasses == "array" {
					let cssClasses = join(" ", typeClasses);
				} else {
					let cssClasses = typeClasses;
				}
			} else {
				let cssClasses = "";
			}

			return str_replace(["%cssClass%", "%message%"], [cssClasses, message], this->getTemplate(cssClasses));
		} else {
			return message;
		}
	}
}
