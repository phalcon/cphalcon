
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html;

use Phalcon\DiInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Html\Exception;

/**
 * Phalcon\Html\Tag
 *
 * Phalcon\Tag is designed to simplify building of HTML tags. It provides a set
 * of helpers to dynamically generate HTML.
 */
class Tag implements InjectionAwareInterface
{
	/**
	 * @var <DiInterface>
	 */
	protected container;

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
	 * Sets the dependency injector
	 */
	public function setDI(<DiInterface> container) -> void
	{
		let this->container = container;
	}

	/**
	 * Returns the internal dependency injector
	 */
	public function getDI() -> <DiInterface>
	{
		return this->container;
	}

	public function getEscaper(array! params) -> <EscaperInterface> | null
	{
	}

	public function renderAttributes(string! code, array! attributes) -> string
	{
	}

	public function getUrlService() -> <UrlInterface>
	{
	}

	public function getEscaperService() -> <EscaperInterface>
	{
	}

	public function setAutoescape(bool autoescape) -> void
	{
	}

	public function setDefault(string! id, value) -> void
	{
	}

	public function setDefaults(array! values, bool merge = false) -> void
	{
	}

	public function displayTo(string! id, value) -> void
	{
	}

	public function hasValue(var name) -> bool
	{
	}

	public function getValue(var name, array params = [])
	{
	}

	public function clear() -> void
	{
	}

	public function linkTo(parameters, text = null, local = true) -> string
	{
	}

	public function colorField(var parameters) -> string
	{
	}

	public function textField(var parameters) -> string
	{
	}

	public function numericField(var parameters) -> string
	{
	}

	public function rangeField(var parameters) -> string
	{
	}

	public function emailField(var parameters) -> string
	{
	}

	public function dateField(var parameters) -> string
	{
	}

	public function dateTimeField(var parameters) -> string
	{
	}

	public function dateTimeLocalField(var parameters) -> string
	{
	}

	public function monthField(var parameters) -> string
	{
	}

	public function timeField(var parameters) -> string
	{
	}

	public function weekField(var parameters) -> string
	{
	}

	public function passwordField(var parameters) -> string
	{
	}

	public function hiddenField(var parameters) -> string
	{
	}

	public function fileField(var parameters) -> string
	{
	}

	public function searchField(var parameters) -> string
	{
	}

	public function telField(var parameters) -> string
	{
	}

	public function urlField(var parameters) -> string
	{
	}

	public function checkField(var parameters) -> string
	{
	}

	public function radioField(var parameters) -> string
	{
	}

	public function imageInput(var parameters) -> string
	{
	}

	public function submitButton(var parameters) -> string
	{
	}

	public function selectStatic(parameters, data = null) -> string
	{
	}

	public function select(var parameters, data = null) -> string
	{
	}

	public function textArea(var parameters) -> string
	{
	}

	public function form(var parameters) -> string
	{
	}

	public function endForm() -> string
	{
	}

	public function setTitle(string title) -> void
	{
	}

	public function setTitleSeparator(string titleSeparator) -> void
	{
	}

	public function appendTitle(var title) -> void
	{
	}

	public function prependTitle(var title) -> void
	{
	}

	public function getTitle(bool prepend = true, bool append = true) -> string
	{
	}

	public function renderTitle() -> string
	{
	}

	public function getTitleSeparator() -> string
	{
	}

	public function stylesheetLink(var parameters = null, bool local = true) -> string
	{
	}

	public function javascriptInclude(var parameters = null, bool local = true) -> string
	{
	}

	public function image(var parameters = null, bool local = true) -> string
	{
	}

	public function friendlyTitle(string text, string separator = "-", bool lowercase = true, var replace = null) -> string
	{
	}

	public function setDocType(int doctype) -> void
	{
	}

	public function getDocType() -> string
	{
	}

	public function tagHtml(string tagName, var parameters = null, bool selfClose = false,
		bool onlyStart = false, bool useEol = false) -> string
	{
	}

	public function tagHtmlClose(string tagName, bool useEol = false) -> string
	{
	}

	private function inputField(string type, parameters, bool asValue = false) -> string
	{
	}

	private function inputFieldChecked(string type, var parameters) -> string
	{
	}

}
