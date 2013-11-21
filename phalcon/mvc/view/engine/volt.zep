
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

/**
 * Phalcon\Mvc\View\Engine\Volt
 *
 * Designer friendly and fast template engine for PHP written in C
 */
class Volt extends Phalcon\Mvc\View\Engine implements Phalcon\Mvc\View\EngineInterface
{

	protected _options;

	protected _compiler;

	/**
	 * Set Volt's options
	 *
	 * @param array options
	 */
	public function setOptions($options)
	{
		if typeof options != "array" {
			throw new Phalcon\Mvc\View\Exception("Options parameter must be an array");
		}
		let this->_options = options;
	}

	/**
	 * Return Volt's options
	 *
	 * @return array
	 */
	public function getOptions()
	{
		return this->_options;
	}

	/**
	 * Returns the Volt's compiler
	 *
	 * @return Phalcon\Mvc\View\Engine\Volt\Compiler
	 */
	public function getCompiler()  -> <Phalcon\Mvc\View\Engine\Volt\Compiler>
	{
		var compiler, dependencyInjector, options;

		let compiler = this->_compiler;
		if typeof compiler != "object" {

			let compiler = new Phalcon\Mvc\View\Engine\Volt\Compiler(this->_view);

			/**
			 * Pass the IoC to the compiler only of it's an object
			 */
			let dependencyInjector = this->_dependencyInjector;
			if typeof dependencyInjector != "object" {
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
	 *
	 * @param string  templatePath
	 * @param array   params
	 * @param boolean mustClean
	 */
	public function render(string! templatePath, var params, boolean mustClean=false)
	{
		var compiler, compiledTemplatePath, key, value;

		if mustClean === true {
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

		if mustClean === true {
			this->_view->setContent(ob_get_contents());
		}
	}

	/**
	 * Length filter. If an array/object is passed a count is performed otherwise a strlen/mb_strlen
	 *
	 * @param mixed $item
	 * @return int
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
	 *
	 * @param  mixed needle
	 * @param  mixed haystack
	 * @return boolean
	 */
	public function isIncluded(needle, haystack) -> boolean
	{
		if typeof haystack == "array" {
			return in_array(needle, haystack);
		}

		if typeof haystack == "string" {
			if function_exists("mb_strpos") {
				return mb_strpos(haystack, needle);
			}
			return strpos(haystack, needle);
		}

		throw new Phalcon\Mvc\View\Exception("Invalid haystack");
	}

	/**
	 * Performs a string conversion
	 *
	 * @param  string text
	 * @param  string from
	 * @param  string to
	 * @return string
	 */
	public function convertEncoding(string text, string! from, string! to) -> string
	{

		/**
		 * Try to use utf8_encode if conversion is 'latin1' to 'utf8'
		 */
		if from == "latin1" {
			if to == "utf8" {
				return utf8_encode(text);
			}
		}

		/**
		 * Try to use utf8_decode if conversion is 'utf8' to 'latin1'
		 */
		if to == "latin1" {
			if from == "utf8" {
				return utf8_decode(text);
			}
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
		throw new Phalcon\Mvc\View\Exception("Any of 'mbstring' or 'iconv' is required to perform the charset conversion");
	}

	/**
	 * Extracts a slice from a string/array/traversable object value
	 *
	 * @param mixed value
	 */
	public function slice(value, start, end=null)
	{

		var length, position, slice;

		/**
		 * Objects must implement a Traversable interface
		 */
		if typeof value == "object" {

			if end === null {
				let length = count(value);
			} else {
				let length = end;
			}

			let position = 0, slice = [];
			loop {

				if !value->valid() {
					break;
				}

				if position >= start {
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
	 *
	 * @param array value
	 * @return array
	 */
	public function sort(value)
	{
		asort(value);
		return value;
	}

}
