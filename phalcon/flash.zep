
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
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

	protected _cssClasses;

	protected _implicitFlush = true;

	protected _automaticHtml = true;

	protected _escaperService = null;

	protected _autoescape = true;

	protected _dependencyInjector = null;

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
	 * Returns the autoescape mode in generated html
	 */
	public function getAutoescape() -> bool
	{
			return this->_autoescape;
	}

	/**
	 * Set the autoescape mode in generated html
	 */
	public function setAutoescape(boolean autoescape) -> <Flash>
	{
		let this->_autoescape = autoescape;
		return this;
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
	 * Sets the Escaper Service
	 */
	public function setEscaperService(<EscaperInterface> escaperService) -> <Flash>
	{
		let this->_escaperService = escaperService;
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
	 * Set whether the output must be implicitly flushed to the output or returned as string
	 */
	public function setImplicitFlush(boolean implicitFlush) -> <FlashInterface>
	{
		let this->_implicitFlush = implicitFlush;
		return this;
	}

	/**
	 * Set if the output must be implicitly formatted with HTML
	 */
	public function setAutomaticHtml(boolean automaticHtml) -> <FlashInterface>
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
	 * Shows a HTML error message
	 *
	 *<code>
	 * $flash->error("This is an error");
	 *</code>
	 */
	public function error(var message) -> string
	{
		return this->{"message"}("error", message);
	}

	/**
	 * Shows a HTML notice/information message
	 *
	 *<code>
	 * $flash->notice("This is an information");
	 *</code>
	 */
	public function notice(var message) -> string
	{
		return this->{"message"}("notice", message);
	}

	/**
	 * Shows a HTML success message
	 *
	 *<code>
	 * $flash->success("The process was finished successfully");
	 *</code>
	 */
	public function success(var message) -> string
	{
		return this->{"message"}("success", message);
	}

	/**
	 * Shows a HTML warning message
	 *
	 *<code>
	 * $flash->warning("Hey, this is important");
	 *</code>
	 */
	public function warning(var message) -> string
	{
		return this->{"message"}("warning", message);
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
		boolean automaticHtml, implicitFlush;
		var content, cssClasses, classes, typeClasses, eol, msg,
			htmlMessage, autoEscape, escaper, preparedMsg;

		let automaticHtml = (bool) this->_automaticHtml,
			autoEscape = (bool) this->_autoescape;

		if automaticHtml === true {
			let classes = this->_cssClasses;
			if fetch typeClasses, classes[type] {
				if typeof typeClasses == "array" {
					let cssClasses = " class=\"" . join(" ", typeClasses) . "\"";
				} else {
					let cssClasses = " class=\"" . typeClasses . "\"";
				}
			} else {
				let cssClasses = "";
			}
			let eol = PHP_EOL;
		}

		if autoEscape === true {
			let escaper = this->getEscaperService();
		}

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
				if autoEscape === true {
					let preparedMsg = escaper->escapeHtml(msg);
				} else {
					let preparedMsg = msg;
				}

				/**
				 * We create the applying formatting or not
				 */
				if automaticHtml === true {
					let htmlMessage = "<div" . cssClasses . ">" . preparedMsg . "</div>" . eol;
				} else {
					let htmlMessage = preparedMsg;
				}

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
			if autoEscape === true {
				let preparedMsg = escaper->escapeHtml(message);
			} else {
				let preparedMsg = message;
			}

			/**
			 * We create the applying formatting or not
			 */
			if automaticHtml === true {
				let htmlMessage = "<div" . cssClasses . ">" . preparedMsg . "</div>" . eol;
			} else {
				let htmlMessage = preparedMsg;
			}

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
	 * Clears accumulated messages when implicit flush is disabled
	 */
	public function clear() -> void
	{
		let this->_messages = [];
	}
}
