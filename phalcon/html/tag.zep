
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

	public function buttonSubmit(array parameters = []) -> string
	{
	}

	public function clear() -> void
	{
	}

	public function docTypeGet() -> void
	{
	}

	public function docTypeSet(int doctype) -> void
	{
	}

	public function element(array parameters = []) -> string
	{
	}

	public function elementClose(array parameters = []) -> string
	{
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

	private function inputField(string type, parameters, bool asValue = false) -> string
	{
	}

	private function inputFieldChecked(string type, array parameters = []) -> string
	{
	}

}
