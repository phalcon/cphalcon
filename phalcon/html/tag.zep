
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

	/**
	 * @var int
	 */
	private docType = 5; // HTML5


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

	public function clear() -> void
	{
	}

	/**
	 * Get the document type declaration of content. If the docType has not
	 * been set properly, XHTML5 is returned
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

	public function formEnd() -> string
	{
	}

	public function get(string name, array parameters = [])
	{
	}

	public function has(string name) -> bool
	{
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

	public function setAutoescape(bool autoescape) -> void
	{
	}

	public function setDefault(string! id, value) -> void
	{
	}

	public function setDefaults(array! values, bool merge = false) -> void
	{
	}

	public function stylesheet(array parameters = []) -> string
	{
	}

	public function textArea(array parameters = []) -> string
	{
	}

	public function titleAppend(string title) -> void
	{
	}

	public function titleFriendly(string text, string separator = "-", bool lowercase = true, var replace = null) -> string
	{
	}

	public function titleGet(bool prepend = true, bool append = true) -> string
	{
	}

	public function titlePrepend(string title) -> void
	{
	}

	public function titleRender() -> string
	{
	}

	public function titleSeparatorGet() -> string
	{
	}

	public function titleSeparatorSet(string separator) -> void
	{
	}

	public function titleSet(string title) -> void
	{
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

	private function inputField(string type, parameters, bool asValue = false) -> string
	{
	}

	private function inputFieldChecked(string type, array parameters = []) -> string
	{
	}

}
