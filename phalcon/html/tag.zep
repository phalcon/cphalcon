
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
use Phalcon\Escaper;
use Phalcon\EscaperInterface;
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

	/**
	 * @var bool
	 */
	private autoescape = true;

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

	public function buttonSubmit(array parameters = []) -> string
	{
	}

	/**
	 * Resets the request and internal values to avoid those fields will have
	 * any default value.
	 */
	public function clear() -> void
	{
		let this->autoEscape = true,
			this->append     = [],
			this->docType    = self::HTML5,
			this->prepend    = [],
			this->separator  = "",
			this->title      = "",
			this->values     = [];
	}

	/**
	 * Get the document type declaration of content. If the docType has not
	 * been set properly, XHTML5 is returned
	 *
	 * @return string
	 */
	public function docTypeGet() -> string
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
	 * Set the document type of content
	 *
	 * @param int doctype A valid doctype for the content
	 *
	 * @return <Tag>
	 */
	public function docTypeSet(int doctype) -> <Tag>
	{
		if (doctype < self::HTML32 || doctype > self::XHTML5) {
			let this->docType = self::HTML5;
		} else {
			let this->docType = doctype;
		}

		return this;
	}

	public function element(array parameters = []) -> string
	{
	}

	/**
	 * Builds the closing tag of an html element
	 *
	 * @param array parameters ["name", "useEol"]
	 *
	 * @return string
	 *
	 *<code>
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
	 * ); // "</aside>" . PHP_EOL
	 *</code>
	 */
	public function elementClose(array parameters = []) -> string
	{
		var name, useEol = false;

		if !fetch name, parameters["name"] {
			throw new Exception("The 'name' parameter must be specified");
		}

		let useEol = this->arrayGetDefault("useEol", parameters, false);

		if useEol {
			return "</" . name . ">" . PHP_EOL;
		}
		return "</" . name . ">";

	}

	public function form(array parameters = []) -> string
	{
	}

	/**
	 * Returns the closing tag of a form element
	 *
	 * @param bool eol
	 *
	 * @return string
	 */
	public function formEnd(bool eol = true) -> string
	{
		if eol {
			return "</form>" . PHP_EOL;
		} else {
			return "</form>";
		}
	}

	/**
	 * Every helper calls this function to check whether a component has a predefined
	 * value using `setDefault` or value from $_POST
	 *
	 * @param string name
	 * @param array  parameters
	 */
	public function get(string name, array parameters = []) -> var | null
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
	 * Check if a helper has a default value set using Phalcon\Tag::setDefault or value from $_POST
	 *
	 * @param string name
	 *
	 * @return bool
	 */
	public function has(string name) -> bool
	{
		/**
		 * Check if there is a predefined or a POST value for it
		 */
		return isset this->values[name] || isset _POST[name];
	}

	public function image(array parameters = []) -> string
	{
	}

	public function inputCheckbox(array parameters = []) -> string
	{
	}

	public function inputColor(array parameters = []) -> string
	{
	}

	public function inputDate(array parameters = []) -> string
	{
	}

	public function inputDateTime(array parameters = []) -> string
	{
	}

	public function inputDateTimeLocal(array parameters = []) -> string
	{
	}

	public function inputEmail(array parameters = []) -> string
	{
	}

	public function inputFile(array parameters = []) -> string
	{
	}

	public function inputHidden(array parameters = []) -> string
	{
	}

	public function inputImage(array parameters = []) -> string
	{
	}

	public function inputMonth(array parameters = []) -> string
	{
	}

	public function inputNumeric(array parameters = []) -> string
	{
	}

	public function inputPassword(array parameters = []) -> string
	{
	}

	public function inputRadio(array parameters = []) -> string
	{
	}

	public function inputRange(array parameters = []) -> string
	{
	}

	public function inputSearch(array parameters = []) -> string
	{
	}

	public function inputTel(array parameters = []) -> string
	{
	}

	public function inputText(array parameters = []) -> string
	{
	}

	public function inputTime(array parameters = []) -> string
	{
	}

	public function inputUrl(array parameters = []) -> string
	{
	}

	public function inputWeek(array parameters = []) -> string
	{
	}

	public function javascript(array parameters = []) -> string
	{
	}

	public function link(array parameters = []) -> string
	{
	}

	public function renderAttributes(string! code, array! attributes) -> string
	{
	}

	public function select(array parameters = [], data = null) -> string
	{
	}

	public function selectStatic(array parameters, data = null) -> string
	{
	}

	/**
	 * Set autoescape mode in generated html
	 *
	 * @param bool autoescape
	 *
	 * @return <Tag>
	 */
	public function setAutoescape(bool autoescape) -> <Tag>
	{
		let this->autoescape = autoescape;

		return this;
	}

	/**
	 * Assigns default values to generated tags by helpers
	 *
	 * <code>
	 * use Phalcon\Html\Tag;
	 *
	 * $tag = new Tag();
	 *
	 * // Assigning "peter" to "name" component
	 * $tag->setDefault("name", "peter");
	 *
	 * // Later in the view
	 * echo $tag->inputText("name"); // Will have the value "peter" by default
	 * </code>
	 *
	 * @param string value
	 */
	public function setDefault(string! name, value) -> <Tag>
	{
		if value !== null {
			if typeof value == "array" || typeof value == "object" {
				throw new Exception("Only scalar values can be assigned to UI components");
			}
		}

		let this->values[name] = value;

		return this;
	}

	/**
	 * Assigns default values to generated tags by helpers
	 *
	 * <code>
	 * use Phalcon\Html\Tag;
	 *
	 * $tag = new Tag();
	 *
	 * // Assigning "peter" to "name" component
	 * $tag->setDefault(
	 *     [
	 *         "name" => "peter",
	 *     ]
	 * );
	 *
	 * // Later in the view
	 * echo $tag->inputText("name"); // Will have the value "peter" by default
	 * </code>
	 */
	public function setDefaults(array! values, bool merge = false) -> <Tag>
	{
		if merge {
			let this->values = array_merge(this->values, values);
		} else {
			let this->values = values;
		}

		return this;
	}

	public function stylesheet(array parameters = []) -> string
	{
	}

	public function textArea(array parameters = []) -> string
	{
	}

	/**
	 * Appends a text to current document title
	 */
	public function titleAppend(array title) -> <Tag>
	{
		let this->append = title;

		return this;
	}

	public function titleFriendly(string text, string separator = "-", bool lowercase = true, var replace = null) -> string
	{
	}

	/**
	 * Gets the current document title.
	 * The title will be automatically escaped.
	 *
	 * <code>
	 * Tag::prependTitle('Hello');
	 * Tag::setTitle('World');
	 * Tag::appendTitle('from Phalcon');
	 *
	 * echo Tag::getTitle();             // Hello World from Phalcon
	 * echo Tag::getTitle(false);        // World from Phalcon
	 * echo Tag::getTitle(true, false);  // Hello World
	 * echo Tag::getTitle(false, false); // World
	 * </code>
	 *
	 * <code>
	 * {{ get_title() }}
	 * </code>
	 */
	public function titleGet(bool prepend = true, bool append = true) -> string
	{
		var item,
			items,
			output,
			title,
			appendTitle,
			prependTitle,
			separator,
			escaper;

		let escaper   = <EscaperInterface> this->getEscaper(["escape": true]),
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
	 * Prepends a text to current document title
	 */
	public function titlePrepend(array title) -> <Tag>
	{
		let this->prepend = title;

		return this;
	}

	/**
	 * Renders the title with title tags. The title is automaticall escaped
	 *
	 * <code>
	 * use Phalcon\Html\Tag;
	 *
	 * $tag = new Tag();
	 *
	 * $tag
	 * 		->titlePrepend('Hello')
	 * 		->titleSet('World')
	 * 		->titleAppend('from Phalcon');
	 *
	 * echo $tag->titleRender(); // <title>Hello World From Phalcon</title>
	 * </code>
	 *
	 * <code>
	 * {{ render_title() }}
	 * </code>
	 */
	public function titleRender() -> string
	{
		return "<title>" . this->titleGet() . "</title>" . PHP_EOL;
	}

	/**
	 * Gets the current document title separator
	 *
	 * <code>
	 * use Phalcon\Html\Tag;
	 *
	 * $tag = new Tag();
	 *
	 * echo $tag->titleSeparatorGet();
	 * </code>
	 *
	 * <code>
	 * {{ title_separator_get() }}
	 * </code>
	 */
	public function titleSeparatorGet() -> string
	{
		return this->separator;
	}

	/**
	 * Set the title separator of view content
	 *
	 * <code>
	 * use Phalcon\Html\Tag;
	 *
	 * $tag = new Tag();
	 *
	 * echo $tag->titleSeparatorSet('-');
	 * </code>
	 */
	public function titleSeparatorSet(string separator) -> <Tag>
	{
		let this->separator = separator;

		return this;
	}

	/**
	 * Set the title separator of view content
	 *
	 * <code>
	 * use Phalcon\Html\Tag;
	 *
	 * $tag = new Tag();
	 *
	 * $tag->titleSet('Phalcon Framework');
	 * </code>
	 */
	public function titleSet(string title) -> <Tag>
	{
		let this->title = title;

		return this;
	}

	/**
	 * Helper method to check an array for an element. If it exists it returns it,
	 * if not, it returns the supplied default value
	 *
	 * @param string name
	 * @param arrays parameters
	 * @param mixed  defaultValue
	 */
	private function arrayGetDefault(string name, array parameters, var defaultValue = null) -> var
	{
		if isset(parameters[name]) {
			return parameters[name];
		} else {
			return defaultValue;
		}
	}

	/**
	 * Obtains the 'escaper' service if required
	 */
	private function getEscaper(array! parameters) -> <EscaperInterface> | null
	{
		var autoescape;

		if !fetch autoescape, parameters["escape"] {
			let autoescape = this->autoescape;
		}

		if !autoescape {
			return null;
		}

		return this->getEscaperService();
	}

	/**
	 * Returns the escaper service from the DI container
	 */
	private function getEscaperService() -> <EscaperInterface>
	{
		var escaper, container;

		let escaper = this->escaper;
		if typeof escaper != "object" {
			let container = this->getDI();

			if typeof container != "object" {
				throw new Exception("A dependency injector container is required to obtain the 'escaper' service");
			}

			let escaper       = <EscaperInterface> container->getShared("escaper"),
				this->escaper = escaper;
		}

		return escaper;
	}

	private function inputField(string type, parameters, bool asValue = false) -> string
	{
	}

	private function inputFieldChecked(string type, array parameters = []) -> string
	{
	}

}
