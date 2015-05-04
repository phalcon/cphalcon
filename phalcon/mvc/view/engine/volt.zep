
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Mvc\View\Engine;

use Phalcon\DiInterface;
use Phalcon\Mvc\View\Engine;
use Phalcon\Mvc\View\EngineInterface;
use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Mvc\View\Exception;

/**
 * Phalcon\Mvc\View\Engine\Volt
 *
 * Designer friendly and fast template engine for PHP written in C
 */
class Volt extends Engine implements EngineInterface
{

	protected _options;

	protected _compiler;

	/**
	 * Set Volt's options
	 */
	public function setOptions(array! options)
	{
		let this->_options = options;
	}

	/**
	 * Return Volt's options	 
	 */
	public function getOptions() -> array
	{
		return this->_options;
	}

	/**
	 * Returns the Volt's compiler
	 */
	public function getCompiler() -> <Compiler>
	{
		var compiler, dependencyInjector, options;

		let compiler = this->_compiler;
		if typeof compiler != "object" {

			let compiler = new Compiler(this->_view);

			/**
			 * Pass the IoC to the compiler only of it's an object
			 */
			let dependencyInjector = <DiInterface> this->_dependencyInjector;
			if typeof dependencyInjector == "object" {
				compiler->setDi(dependencyInjector);
			}

			/**
			 * Pass the options to the compiler only if they're an array
			 */
			let options = this->_options;
			if typeof options == "array" {
				compiler->setOptions(options);
			}

			let this->_compiler = compiler;
		}
		return compiler;
	}

	/**
	 * Renders a view using the template engine
	 */
	public function render(string! templatePath, var params, boolean mustClean = false)
	{
		var compiler, compiledTemplatePath, key, value;

		if mustClean {
			ob_clean();
		}

		/**
		 * The compilation process is done by Phalcon\Mvc\View\Engine\Volt\Compiler
		 */
		let compiler = this->getCompiler();

		compiler->compile(templatePath);

		let compiledTemplatePath = compiler->getCompiledTemplatePath();

		/**
		 * Export the variables the current symbol table
		 */
		if typeof params == "array"	{
			for key, value in params {
				let {key} = value;
			}
		}

		require compiledTemplatePath;

		if mustClean {
			this->_view->setContent(ob_get_contents());
			//ob_clean();
		}
	}

	/**
	 * Length filter. If an array/object is passed a count is performed otherwise a strlen/mb_strlen
	 */
	public function length(var item) -> int
	{
		var length;

		let length = 0;

		if typeof item == "object" {
			let length = count(item);
		} else {
			if typeof item == "array" {
				let length = count(item);
			} else {
				if function_exists("mb_strlen") {
					let length = mb_strlen(item);
				} else {
					let length = strlen(item);
				}
			}
		}

		return length;
	}

	/**
	 * Checks if the needle is included in the haystack
	 */
	public function isIncluded(var needle, var haystack) -> boolean
	{
		if typeof haystack == "array" {
			return in_array(needle, haystack);
		}

		if typeof haystack == "string" {
			if function_exists("mb_strpos") {
				return mb_strpos(haystack, needle) !== false;
			}
			return strpos(haystack, needle) !== false;
		}

		throw new Exception("Invalid haystack");
	}

	/**
	 * Performs a string conversion
	 */
	public function convertEncoding(string text, string! from, string! to) -> string
	{
		/**
		 * Try to use utf8_encode if conversion is 'latin1' to 'utf8'
		 */
		if from == "latin1" || to == "utf8" {
			return utf8_encode(text);
		}

		/**
		 * Try to use utf8_decode if conversion is 'utf8' to 'latin1'
		 */
		if to == "latin1" || from == "utf8" {
			return utf8_decode(text);
		}

		/**
		 * Fallback to mb_convert_encoding
		 */
		if function_exists("mb_convert_encoding") {
			return mb_convert_encoding(text, from, to);
		}

		/**
		 * Fallback to iconv
		 */
		if function_exists("iconv") {
			return iconv(from, to, text);
		}

		/**
		 * There are no enough extensions available
		 */
		throw new Exception("Any of 'mbstring' or 'iconv' is required to perform the charset conversion");
	}

	/**
	 * Extracts a slice from a string/array/traversable object value
	 */
	public function slice(var value, int start = 0, var end = null)
	{
		var length, slice;
		int position;

		/**
		 * Objects must implement a Traversable interface
		 */
		if typeof value == "object" {

			if end === null {
				let end = count(value) - 1;
			}

			let position = 0, slice = [];

			value->rewind();

			while value->valid() {
				if position >= start && position <= end {
					let slice[] = value->current();
				}

				value->next();
				let position++;
			}

			return slice;
		}

		/**
		 * Calculate the slice length
		 */
		if end !== null {
			let length = (end - start) + 1;
		} else {
			let length = null;
		}

		/**
		 * Use array_slice on arrays
		 */
		if typeof value == "array" {
			return array_slice(value, start, length);
		}

		/**
		 * Use mb_substr if available
		 */
		if function_exists("mb_substr") {
			if length !== null {
				return mb_substr(value, start, length);
			}
			return mb_substr(value, start);
		}

		/**
		 * Use the standard substr function
		 */
		if length !== null {
			return substr(value, start, length);
		}
		return substr(value, start);
	}

	/**
	 * Sorts an array
	 */
	public function sort(array value) -> array
	{
		asort(value);
		return value;
	}
}
