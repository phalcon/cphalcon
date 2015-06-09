
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

namespace Phalcon\Mvc\View\Engine\Volt;

use Phalcon\DiInterface;
use Phalcon\Mvc\ViewBaseInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Mvc\View\Exception;

/**
 * Phalcon\Mvc\View\Engine\Volt\Compiler
 *
 * This class reads and compiles Volt templates into PHP plain code
 *
 *<code>
 *	$compiler = new \Phalcon\Mvc\View\Engine\Volt\Compiler();
 *
 *	$compiler->compile('views/partials/header.volt');
 *
 *	require $compiler->getCompiledTemplatePath();
 *</code>
 */
class Compiler implements InjectionAwareInterface
{

	protected _dependencyInjector;

	protected _view;

	protected _options;

	protected _arrayHelpers;

	protected _level = 0;

	protected _foreachLevel = 0;

	protected _blockLevel = 0;

	protected _exprLevel = 0;

	protected _extended = false;

	protected _autoescape = false;

	protected _extendedBlocks;

	protected _currentBlock;

	protected _blocks;

	protected _forElsePointers;

	protected _loopPointers;

	protected _extensions;

	protected _functions;

	protected _filters;

	protected _macros;

	protected _prefix;

	protected _currentPath;

	protected _compiledTemplatePath;

	/**
	 * Phalcon\Mvc\View\Engine\Volt\Compiler
	 */
	public function __construct(<ViewBaseInterface> view = null)
	{
		if typeof view == "object" {
			let this->_view = view;
		}
	}

	/**
	 * Sets the dependency injector
	 */
	public function setDI(<DiInterface> dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the internal dependency injector
	 */
	public function getDI() -> <DiInterface>
	{
		return this->_dependencyInjector;
	}

	/**
	 * Sets the compiler options
	 */
	public function setOptions(array! options)
	{
		let this->_options = options;
	}

	/**
	 * Sets a single compiler option
	 *
	 * @param string option
	 * @param mixed value
	 */
	public function setOption(string! option, value)
	{
		let this->_options[option] = value;
	}

	/**
	 * Returns a compiler's option
	 *
	 * @param string option
	 * @return string
	 */
	public function getOption(string! option)
	{
		var value;
		if fetch value, this->_options[option] {
			return value;
		}
		return null;
	}

	/**
	 * Returns the compiler options
	 */
	public function getOptions() -> array
	{
		return this->_options;
	}

	/**
	 * Fires an event to registered extensions
	 *
	 * @param string name
	 * @param array arguments
	 * @return mixed
	 */
	public final function fireExtensionEvent(string! name, arguments = null)
	{
		var extensions, extension, status;

		let extensions = this->_extensions;
		if typeof extensions == "array" {
			for extension in extensions {

				/**
				 * Check if the extension implements the required event name
				 */
				if method_exists(extension, name) {

					if typeof arguments == "array" {
						let status = call_user_func_array([extension, name], arguments);
					} else {
						let status = call_user_func([extension, name]);
					}

					/**
					 * Only string statuses means the extension process something
					 */
					if typeof status == "string" {
						return status;
					}
				}
			}
		}
	}

	/**
	 * Registers a Volt's extension
	 *
	 * @param object extension
	 * @return Phalcon\Mvc\View\Engine\Volt\Compiler
	 */
	public function addExtension(extension) -> <Compiler>
	{
		if typeof extension != "object" {
			throw new Exception("The extension is not valid");
		}

		/**
		 * Initialize the extension
		 */
		if method_exists(extension, "initialize") {
			extension->initialize(this);
		}

		let this->_extensions[] = extension;
		return this;
	}

	/**
	 * Returns the list of extensions registered in Volt
	 */
	public function getExtensions() -> array
	{
		return this->_extensions;
	}

	/**
	 * Register a new function in the compiler
	 *
	 * @param string name
	 * @param Closure|string definition
	 * @return Phalcon\Mvc\View\Engine\Volt\Compiler
	 */
	public function addFunction(string! name, definition) -> <Compiler>
	{
		let this->_functions[name] = definition;
		return this;
	}

	/**
	 * Register the user registered functions
	 */
	public function getFunctions() -> array
	{
		return this->_functions;
	}

	/**
	 * Register a new filter in the compiler
	 *
	 * @param string name
	 * @param Closure|string definition
	 * @return Phalcon\Mvc\View\Engine\Volt\Compiler
	 */
	public function addFilter(string! name, definition) -> <Compiler>
	{
		let this->_filters[name] = definition;
		return this;
	}

	/**
	 * Register the user registered filters
	 */
	public function getFilters() -> array
	{
		return this->_filters;
	}

	/**
	 * Set a unique prefix to be used as prefix for compiled variables
	 */
	public function setUniquePrefix(string! prefix) -> <Compiler>
	{
		let this->_prefix = prefix;
		return this;
	}

	/**
	 * Return a unique prefix to be used as prefix for compiled variables and contexts
	 */
	public function getUniquePrefix() -> string
	{
		var prefix, calculatedPrefix;

		let prefix = this->_prefix;

		/**
		 * If the unique prefix is not set we use a hash using the modified Berstein algotithm
		 */
		if !prefix {
			let prefix = unique_path_key(this->_currentPath);
			let this->_prefix = prefix;
		}

		/**
		 * The user could use a closure generator
		 */
		if typeof prefix == "object" {
			if prefix instanceof \Closure {
				let calculatedPrefix = call_user_func_array(prefix, [this]),
					this->_prefix = calculatedPrefix,
					prefix = calculatedPrefix;
			}
		}

		if typeof prefix != "string" {
			throw new Exception("The unique compilation prefix is invalid");
		}

		return prefix;
	}

	/**
	 * Resolves attribute reading
	 */
	public function attributeReader(array! expr) -> string
	{
		var exprCode, left, leftType, variable,
			level, dependencyInjector, leftCode, right;

		let exprCode = null;

		let left = expr["left"];

		if left["type"] == PHVOLT_T_IDENTIFIER {

			let variable = left["value"];

			/**
			 * Check if the variable is the loop context
			 */
			if variable == "loop" {
				let level = this->_foreachLevel,
					exprCode .= "$" . this->getUniquePrefix() . level . "loop",
					this->_loopPointers[level] = level;
			} else {

				/**
				 * Services registered in the dependency injector container are availables always
				 */
				let dependencyInjector = this->_dependencyInjector;
				if typeof dependencyInjector == "object" {
					if dependencyInjector->has(variable) {
						let exprCode .= "$this->" . variable;
					} else {
						let exprCode .= "$" . variable;
					}
				} else {
					let exprCode .= "$" . variable;
				}
			}

		} else {
			let leftCode = this->expression(left), leftType = left["type"];
			if leftType != PHVOLT_T_DOT && leftType != PHVOLT_T_FCALL {
				let exprCode .= "(" . leftCode . ")";
			} else {
				let exprCode .= leftCode;
			}
		}

		let exprCode .= "->";

		let right = expr["right"];

		if right["type"] == PHVOLT_T_IDENTIFIER {
			let exprCode .= right["value"];
		} else {
			let exprCode .= this->expression(right);
		}

		return exprCode;
	}

	/**
	 * Resolves function intermediate code into PHP function calls
	 */
	public function functionCall(array! expr) -> string
	{
		var code, funcArguments, arguments, nameExpr,
			nameType, name, extensions, functions, definition, macros,
			extendedBlocks, block, currentBlock, exprLevel, escapedCode,
			method, arrayHelpers, className;

		let code = null;

		let funcArguments = null;
		if fetch funcArguments, expr["arguments"] {
			let arguments = this->expression(funcArguments);
		} else {
			let arguments = "";
		}

		let nameExpr = expr["name"], nameType = nameExpr["type"];

		/**
		 * Check if it's a single function
		 */
		if nameType == PHVOLT_T_IDENTIFIER {

			let name = nameExpr["value"];

			/**
			 * Check if any of the registered extensions provide compilation for this function
			 */
			let extensions = this->_extensions;
			if typeof extensions == "array" {

				/**
				 * Notify the extensions about being compiling a function
				 */
				let code = this->fireExtensionEvent("compileFunction", [name, arguments, funcArguments]);
				if typeof code == "string" {
					return code;
				}
			}

			/**
			 * Check if it's a user defined function
			 */
			let functions = this->_functions;
			if typeof functions == "array" {
				if fetch definition, functions[name] {

					/**
					 * Use the string as function
					 */
					if typeof definition == "string" {
						return definition . "(" . arguments . ")";
					}

					/**
					 * Execute the function closure returning the compiled definition
					 */
					if typeof definition == "object" {

						if definition instanceof \Closure {
							return call_user_func_array(definition, [arguments, funcArguments]);
						}
					}

					throw new Exception("Invalid definition for user function '" . name . "' in " . expr["file"] . " on line " . expr["line"]);
				}
			}

			let macros = this->_macros;

			/**
			 * Check if the function name is a macro
			 */
			if isset macros[name] {
				return "vmacro_" . name . "(array(" . arguments . "))";
			}

			/**
			 * This function includes the previous rendering stage
			 */
			if name == "get_content" || name == "content" {
				return "$this->getContent()";
			}

			/**
			 * This function includes views of volt or others template engines dynamically
			 */
			if name == "partial" {
				return "$this->partial(" . arguments . ")";
			}

			/**
			 * This function embeds the parent block in the current block
			 */
			if name == "super" {
				let extendedBlocks = this->_extendedBlocks;
				if typeof extendedBlocks == "array" {

					let currentBlock = this->_currentBlock;
					if fetch block, extendedBlocks[currentBlock] {

						let exprLevel = this->_exprLevel;
						if typeof block == "array" {
							let code = this->_statementListOrExtends(block);
							if exprLevel == 1 {
								let escapedCode = code;
							} else {
								let escapedCode = addslashes(code);
							}
						} else {
							if exprLevel == 1 {
								let escapedCode = block;
							} else {
								let escapedCode = addslashes(block);
							}
						}

						/**
						 * If the super() is the first level we don't escape it
						 */
						if exprLevel == 1 {
							return escapedCode;
						}
						return "'" . escapedCode . "'";
					}
				}
				return "''";
			}

			let method = lcfirst(camelize(name)), className = "Phalcon\\Tag";

			/**
			 * Check if it's a method in Phalcon\Tag
			 */
			if method_exists(className, method) {

				let arrayHelpers = this->_arrayHelpers;
				if typeof arrayHelpers != "array" {
					let arrayHelpers = [
						"link_to": true,
						"image": true,
						"form": true,
						"select": true,
						"select_static": true,
						"submit_button": true,
						"radio_field": true,
						"check_field": true,
						"file_field": true,
						"hidden_field": true,
						"password_field": true,
						"text_area": true,
						"text_field": true,
						"email_field": true,
						"date_field": true,
						"numeric_field": true,
						"image_input": true
					];
					let this->_arrayHelpers = arrayHelpers;
				}

				if isset arrayHelpers[name] {
					return "$this->tag->" . method . "(array(" . arguments . "))";
				}
				return "$this->tag->" . method . "(" . arguments . ")";
			}

			/**
			 * Get a dynamic URL
			 */
			if name == "url" {
				return "$this->url->get(" . arguments . ")";
			}

			/**
			 * Get a static URL
			 */
			if name == "static_url" {
				return "$this->url->getStatic(" . arguments . ")";
			}

			if name == "date" {
				return "date(" . arguments . ")";
			}

			if name == "time" {
				return "time()";
			}

			if name == "dump" {
				return "var_dump(" . arguments . ")";
			}

			if name == "version" {
				return "Phalcon\\Version::get()";
			}

			if name == "version_id" {
				return "Phalcon\\Version::getId()";
			}

			/**
			 * Read PHP constants in templates
			 */
			if name == "constant" {
				return "constant(" . arguments . ")";
			}

			/**
			 * The function doesn't exist throw an exception
			 */
			throw new Exception("Undefined function '" . name . "' in " . expr["file"] . " on line " . expr["line"]);
		}

		return this->expression(nameExpr) . "(" . arguments . ")";
	}

	/**
	 * Resolves filter intermediate code into a valid PHP expression
	 */
	public function resolveTest(array! test, string left) -> string
	{
		var type, name, testName;

		let type = test["type"];

		/**
		 * Check if right part is a single identifier
		 */
		if type == PHVOLT_T_IDENTIFIER {

			let name = test["value"];

			/**
			 * Empty uses the PHP's empty operator
			 */
			if name == "empty" {
				return "empty(" . left . ")";
			}

			/**
			 * Check if a value is even
			 */
			if name == "even" {
				return "(((" . left . ") % 2) == 0)";
			}

			/**
			 * Check if a value is odd
			 */
			if name == "odd" {
				return "(((" . left . ") % 2) != 0)";
			}

			/**
			 * Check if a value is numeric
			 */
			if name == "numeric" {
				return "is_numeric(" . left . ")";
			}

			/**
			 * Check if a value is scalar
			 */
			if name == "scalar" {
				return "is_scalar(" . left . ")";
			}

			/**
			 * Check if a value is iterable
			 */
			if name == "iterable" {
				return "(is_array(" . left . ") || (" . left . ") instanceof Traversable)";
			}

		}

		/**
		 * Check if right part is a function call
		 */
		if type == PHVOLT_T_FCALL {

			let testName = test["name"];
			if fetch name, testName["value"] {

				if name == "divisibleby" {
					return "(((" . left . ") % (" . this->expression(test["arguments"]) . ")) == 0)";
				}

				/**
				 * Checks if a value is equals to other
				 */
				if name == "sameas" {
					return "(" . left . ") === (" . this->expression(test["arguments"]) . ")";
				}

				/**
				 * Checks if a variable match a type
				 */
				if name == "type" {
					return "gettype(" . left . ") === (" . this->expression(test["arguments"]) . ")";
				}
			}
		}

		/**
		 * Fall back to the equals operator
		 */
		return left . " == " . this->expression(test);
	}

	/**
	 * Resolves filter intermediate code into PHP function calls
	 */
	final protected function resolveFilter(array! filter, string left) -> string
	{
		var code, type, functionName, name, file, line,
			extensions, filters, funcArguments, arguments, definition;

		let code = null, type = filter["type"];

		/**
		 * Check if the filter is a single identifier
		 */
		if type == PHVOLT_T_IDENTIFIER {
			let name = filter["value"];
		} else {

			if type != PHVOLT_T_FCALL {

				/**
				 * Unknown filter throw an exception
				 */
				throw new Exception("Unknown filter type in " . filter["file"] . " on line " . filter["line"]);
			}

			let functionName = filter["name"],
				name = functionName["value"];
		}

		let funcArguments = null, arguments = null;

		/**
		 * Resolve arguments
		 */
		if fetch funcArguments, filter["arguments"] {

			/**
			 * "default" filter is not the first argument, improve this!
			 */
			if name != "default" {

				let file = filter["file"], line = filter["line"];

				/**
				 * TODO: Implement this function directly
				 */
				array_unshift(funcArguments, [
					"expr": [
						"type":  364,
						"value": left,
						"file": file,
						"line": line
					],
					"file": file,
					"line": line
				]);
			}

			let arguments = this->expression(funcArguments);
		} else {
			let arguments = left;
		}

		/**
		 * Check if any of the registered extensions provide compilation for this filter
		 */
		let extensions = this->_extensions;
		if typeof extensions == "array" {

			/**
			 * Notify the extensions about being compiling a function
			 */
			let code = this->fireExtensionEvent("compileFilter", [name, arguments, funcArguments]);
			if typeof code == "string" {
				return code;
			}
		}

		/**
		 * Check if it's a user defined filter
		 */
		let filters = this->_filters;
		if typeof filters == "array" {
			if fetch definition, filters[name] {

				/**
				 * The definition is a string
				 */
				if typeof definition == "string" {
					return definition . "(" . arguments . ")";
				}

				/**
				 * The definition is a closure
				 */
				if typeof definition == "object" {
					if definition instanceof \Closure {
						return call_user_func_array(definition, [arguments, funcArguments]);
					}
				}

				/**
				 * Invalid filter definition throw an exception
				 */
				throw new Exception("Invalid definition for user filter '" . name . "' in " . filter["file"] . " on line " . filter["line"]);
			}
		}

		/**
		 * "length" uses the length method implemented in the Volt adapter
		 */
		if name == "length" {
			return "$this->length(" . arguments . ")";
		}

		/**
		 * "e"/"escape" filter uses the escaper component
		 */
		if name == "e" || name == "escape" {
			return "$this->escaper->escapeHtml(" . arguments . ")";
		}

		/**
		 * "escape_css" filter uses the escaper component to filter css
		 */
		if name == "escape_css" {
			return "$this->escaper->escapeCss(" . arguments . ")";
		}

		/**
		 * "escape_js" filter uses the escaper component to escape javascript
		 */
		if name == "escape_js" {
			return "$this->escaper->escapeJs(" . arguments . ")";
		}

		/**
		 * "escape_attr" filter uses the escaper component to escape html attributes
		 */
		if name == "escape_attr" {
			return "$this->escaper->escapeHtmlAttr(" . arguments . ")";
		}

		/**
		 * "trim" calls the "trim" function in the PHP userland
		 */
		if name == "trim" {
			return "trim(" . arguments . ")";
		}

		/**
		 * "left_trim" calls the "ltrim" function in the PHP userland
		 */
		if name == "left_trim" {
			return "ltrim(" . arguments . ")";
		}

		/**
		 * "right_trim" calls the "rtrim" function in the PHP userland
		 */
		if name == "right_trim" {
			return "rtrim(" . arguments . ")";
		}

		/**
		 * "striptags" calls the "strip_tags" function in the PHP userland
		 */
		if name == "striptags" {
			return "strip_tags(" . arguments . ")";
		}

		/**
		 * "url_encode" calls the "urlencode" function in the PHP userland
		 */
		if name == "url_encode" {
			return "urlencode(" . arguments . ")";
		}

		/**
		 * "slashes" calls the "addslashes" function in the PHP userland
		 */
		if name == "slashes" {
			return "addslashes(" . arguments . ")";
		}

		/**
		 * "stripslashes" calls the "stripslashes" function in the PHP userland
		 */
		if name == "stripslashes" {
			return "stripslashes(" . arguments . ")";
		}

		/**
		 * "nl2br" calls the "nl2br" function in the PHP userland
		 */
		if name == "nl2br" {
			return "nl2br(" . arguments . ")";
		}

		/**
		 * "keys" uses calls the "array_keys" function in the PHP userland
		 */
		if name == "keys" {
			return "array_keys(" . arguments . ")";
		}

		/**
		 * "join" uses calls the "join" function in the PHP userland
		 */
		if name == "join" {
			return "join(" . arguments . ")";
		}

		/**
		 * "lower"/"lowercase" calls the "strtolower" function or "mb_strtolower" if the mbstring extension is loaded
		 */
		if name == "lower" || name == "lowercase" {
			return "Phalcon\\Text::lower(" . arguments . ")";
		}

		/**
		 * "upper"/"uppercase" calls the "strtoupper" function or "mb_strtoupper" if the mbstring extension is loaded
		 */
		if name == "upper" || name == "uppercase" {
			return "Phalcon\\Text::upper(" . arguments . ")";
		}

		/**
		 * "capitalize" filter calls "ucwords"
		 */
		if name == "capitalize" {
			return "ucwords(" . arguments . ")";
		}

		/**
		 * "sort" calls "sort" method in the engine adapter
		 */
		if name == "sort" {
			return "$this->sort(" . arguments . ")";
		}

		/**
		 * "json_encode" calls the "json_encode" function in the PHP userland
		 */
		if name == "json_encode" {
			return "json_encode(" . arguments . ")";
		}

		/**
		 * "json_decode" calls the "json_decode" function in the PHP userland
		 */
		if name == "json_decode" {
			return "json_decode(" . arguments . ")";
		}

		/**
		 * "format" calls the "sprintf" function in the PHP userland
		 */
		if name == "format" {
			return "sprintf(" . arguments . ")";
		}

		/**
		 * "abs" calls the "abs" function in the PHP userland
		 */
		if name == "abs" {
			return "abs(" . arguments . ")";
		}

		/**
		 * "slice" slices string/arrays/traversable objects
		 */
		if name == "slice" {
			return "$this->slice(" . arguments . ")";
		}

		/**
		 * "default" checks if a variable is empty
		 */
		if name == "default" {
			return "(empty(" . left . ") ? (" . arguments . ") : (" . left . "))";
		}

		/**
		 * This function uses mbstring or iconv to convert strings from one chartset to another
		 */
		if name == "convert_encoding" {
			return "$this->convertEncoding(" . arguments . ")";
		}

		/**
		 * Unknown filter throw an exception
		 */
		throw new Exception("Unknown filter \"" . name . "\" in " . filter["file"] . " on line " . filter["line"]);
	}

	/**
	 * Resolves an expression node in an AST volt tree
	 */
	final public function expression(array! expr) -> string
	{
		var exprCode, extensions, items, singleExpr, singleExprCode, name,
			left, leftCode, right, rightCode, type, startCode, endCode, start, end;

		let exprCode = null, this->_exprLevel++;

		/**
		 * Check if any of the registered extensions provide compilation for this expression
		 */
		let extensions = this->_extensions;

		loop {

			if typeof extensions == "array" {

				/**
				 * Notify the extensions about being resolving an expression
				 */
				let exprCode = this->fireExtensionEvent("resolveExpression", [expr]);
				if typeof exprCode == "string" {
					break;
				}
			}

			if !fetch type, expr["type"] {
				let items = [];
				for singleExpr in expr {
					let singleExprCode = this->expression(singleExpr["expr"]);
					if fetch name, singleExpr["name"] {
						let items[] = "'" . name . "' => " . singleExprCode;
					} else {
						let items[] = singleExprCode;
					}
				}
				let exprCode = join(", ", items);
				break;
			}

			/**
			 * Attribute reading needs special handling
			 */
			if type == PHVOLT_T_DOT {
				let exprCode = this->attributeReader(expr);
				break;
			}

			/**
			 * Left part of expression is always resolved
			 */
			if fetch left, expr["left"] {
				let leftCode = this->expression(left);
			}

			/**
			 * Operator "is" also needs special handling
			 */
			if type == PHVOLT_T_IS {
				let exprCode = this->resolveTest(expr["right"], leftCode);
				break;
			}

			/**
			 * We don't resolve the right expression for filters
			 */
			if type == 124 {
				let exprCode = this->resolveFilter(expr["right"], leftCode);
				break;
			}

			/**
			 * From here, right part of expression is always resolved
			 */
			if fetch right, expr["right"] {
				let rightCode = this->expression(right);
			}

			let exprCode = null;
			switch type {

				case 33:
					let exprCode = "!" . rightCode;
					break;

				case 42:
					let exprCode = leftCode . " * " . rightCode;
					break;

				case 43:
					let exprCode = leftCode . " + " . rightCode;
					break;

				case 45:
					let exprCode = leftCode . " - " . rightCode;
					break;

				case 47:
					let exprCode = leftCode . " / " . rightCode;
					break;

				case 37:
					let exprCode = leftCode . " % " . rightCode;
					break;

				case 60:
					let exprCode = leftCode . " < " . rightCode;
					break;

				case 61:
					let exprCode = leftCode . " > " . rightCode;
					break;

				case 62:
					let exprCode = leftCode . " > " . rightCode;
					break;

				case 126:
					let exprCode = leftCode . " . " . rightCode;
					break;

				case 278:
					let exprCode = "pow(" . leftCode . ", " . rightCode . ")";
					break;

				case PHVOLT_T_ARRAY:
					if isset expr["left"] {
						let exprCode = "array(" . leftCode . ")";
					} else {
						let exprCode = "array()";
					}
					break;

				case 258:
					let exprCode = expr["value"];
					break;

				case 259:
					let exprCode = expr["value"];
					break;

				case PHVOLT_T_STRING:
					let exprCode = "'" . str_replace("'", "\\'", expr["value"]) . "'";
					break;

				case PHVOLT_T_NULL:
					let exprCode = "null";
					break;

				case PHVOLT_T_FALSE:
					let exprCode = "false";
					break;

				case PHVOLT_T_TRUE:
					let exprCode = "true";
					break;

				case PHVOLT_T_IDENTIFIER:
					let exprCode = "$" . expr["value"];
					break;

				case 266:
					let exprCode = leftCode . " && " . rightCode;
					break;

				case 267:
					let exprCode = leftCode . " || " . rightCode;
					break;

				case 270:
					let exprCode = leftCode . " <= " . rightCode;
					break;

				case 271:
					let exprCode = leftCode . " >= " . rightCode;
					break;

				case 272:
					let exprCode = leftCode . " == " . rightCode;
					break;

				case 273:
					let exprCode = leftCode . " != " . rightCode;
					break;

				case 274:
					let exprCode = leftCode . " === " . rightCode;
					break;

				case 275:
					let exprCode = leftCode . " !== " . rightCode;
					break;

				case PHVOLT_T_RANGE:
					let exprCode = "range(" . leftCode . ", " . rightCode . ")";
					break;

				case PHVOLT_T_FCALL:
					let exprCode = this->functionCall(expr);
					break;

				case PHVOLT_T_ENCLOSED:
					let exprCode = "(" . leftCode . ")";
					break;

				case PHVOLT_T_ARRAYACCESS:
					let exprCode = leftCode . "[" . rightCode . "]";
					break;

				case PHVOLT_T_SLICE:

					/**
					 * Evaluate the start part of the slice
					 */
					if fetch start, expr["start"] {
						let startCode = this->expression(start);
					} else {
						let startCode = "null";
					}

					/**
					 * Evaluate the end part of the slice
					 */
					if fetch end, expr["end"] {
						let endCode = this->expression(end);
					} else {
						let endCode = "null";
					}

					let exprCode = "$this->slice(" . leftCode . ", " . startCode . ", " . endCode . ")";
					break;

				case PHVOLT_T_NOT_ISSET:
					let exprCode = "!isset(" . leftCode . ")";
					break;

				case PHVOLT_T_ISSET:
					let exprCode = "isset(" . leftCode . ")";
					break;

				case PHVOLT_T_NOT_ISEMPTY:
					let exprCode = "!empty(" . leftCode . ")";
					break;

				case PHVOLT_T_ISEMPTY:
					let exprCode = "empty(" . leftCode . ")";
					break;

				case PHVOLT_T_NOT_ISEVEN:
					let exprCode = "!(((" . leftCode . ") % 2) == 0)";
					break;

				case PHVOLT_T_ISEVEN:
					let exprCode = "(((" . leftCode . ") % 2) == 0)";
					break;

				case PHVOLT_T_NOT_ISODD:
					let exprCode = "!(((" . leftCode . ") % 2) != 0)";
					break;

				case PHVOLT_T_ISODD:
					let exprCode = "(((" . leftCode . ") % 2) != 0)";
					break;

				case PHVOLT_T_NOT_ISNUMERIC:
					let exprCode = "!is_numeric(" . leftCode . ")";
					break;

				case PHVOLT_T_ISNUMERIC:
					let exprCode = "is_numeric(" . leftCode . ")";
					break;

				case PHVOLT_T_NOT_ISSCALAR:
					let exprCode = "!is_scalar(" . leftCode . ")";
					break;

				case PHVOLT_T_ISSCALAR:
					let exprCode = "is_scalar(" . leftCode . ")";
					break;

				case PHVOLT_T_NOT_ISITERABLE:
					let exprCode = "!(is_array(" . leftCode . ") || (" . leftCode . ") instanceof Traversable)";
					break;

				case PHVOLT_T_ISITERABLE:
					let exprCode = "(is_array(" . leftCode . ") || (" . leftCode . ") instanceof Traversable)";
					break;

				case PHVOLT_T_IN:
					let exprCode = "$this->isIncluded(" . leftCode . ", " . rightCode . ")";
					break;

				case PHVOLT_T_NOT_IN:
					let exprCode = "!$this->isIncluded(" . leftCode . ", " . rightCode . ")";
					break;

				case PHVOLT_T_TERNARY:
					let exprCode = "(" . this->expression(expr["ternary"]) . " ? " . leftCode . " : " . rightCode . ")";
					break;

				case PHVOLT_T_MINUS:
					let exprCode = "-" . rightCode;
					break;

				case PHVOLT_T_PLUS:
					let exprCode = "+" . rightCode;
					break;

				case PHVOLT_T_RESOLVED_EXPR:
					let exprCode = expr["value"];
					break;

				default:
					throw new Exception("Unknown expression " . type . " in " . expr["file"] . " on line " . expr["line"]);
			}

			break;
		}

		let this->_exprLevel--;

		return exprCode;
	}

	/**
	 * Compiles a block of statements
	 *
	 * @param array statements
	 * @return string|array
	 */
	final protected function _statementListOrExtends(var statements)
	{
		var statement;
		boolean isStatementList;

		/**
		 * Resolve the statement list as normal
		 */
		if typeof statements != "array" {
			return statements;
		}

		/**
		 * If all elements in the statement list are arrays we resolve this as a statementList
		 */
		let isStatementList = true;
		if !isset statements["type"] {
			for statement in statements {
				if typeof statement != "array" {
					let isStatementList = false;
					break;
				}
			}
		}

		/**
		 * Resolve the statement list as normal
		 */
		if isStatementList === true {
			return this->_statementList(statements);
		}

		/**
		 * Is an array but not a statement list?
		 */
		return statements;
	}

	/**
	 * Compiles a "foreach" intermediate code representation into plain PHP code
	 */
	public function compileForeach(array! statement, boolean extendsMode = false) -> string
	{
		var compilation, prefix, level, prefixLevel, expr,
			exprCode, bstatement, type, blockStatements, forElse, code,
			loopContext, iterator, key, ifExpr, variable;

		/**
		 * A valid expression is required
		 */
		if !isset statement["expr"] {
			throw new Exception("Corrupted statement");
		}

		let compilation = "", forElse = null;

		let this->_foreachLevel++;

		let prefix = this->getUniquePrefix();
		let level = this->_foreachLevel;

		/**
		 * prefixLevel is used to prefix every temporal variable
		 */
		let prefixLevel = prefix . level;

		/**
		 * Evaluate common expressions
		 */
		let expr = statement["expr"];
		let exprCode = this->expression(expr);

		/**
		 * Process the block statements
		 */
		let blockStatements = statement["block_statements"];

		let forElse = false;
		if typeof blockStatements == "array" {

			for bstatement in blockStatements {

				if typeof bstatement != "array" {
					break;
				}

				/**
				 * Check if the statement is valid
				 */
				if !fetch type, bstatement["type"] {
					break;
				}

				if type == PHVOLT_T_ELSEFOR {
					let compilation .= "<?php $" . prefixLevel . "iterated = false; ?>";
					let forElse = prefixLevel;
					let this->_forElsePointers[level] = forElse;
					break;
				}

			}
		}

		/**
		 * Process statements block
		 */
		let code = this->_statementList(blockStatements, extendsMode);

		let loopContext = this->_loopPointers;

		/**
		 * Generate the loop context for the "foreach"
		 */
		if isset loopContext[level] {
			let compilation .= "<?php $" . prefixLevel . "iterator = " . exprCode . "; ";
			let compilation .= "$" . prefixLevel . "incr = 0; ";
			let compilation .= "$" . prefixLevel . "loop = new stdClass(); ";
			let compilation .= "$" . prefixLevel . "loop->length = count($" . prefixLevel . "iterator); ";
			let compilation .= "$" . prefixLevel . "loop->index = 1; ";
			let compilation .= "$" . prefixLevel . "loop->index0 = 1; ";
			let compilation .= "$" . prefixLevel . "loop->revindex = $" . prefixLevel . "loop->length; ";
			let compilation .= "$" . prefixLevel . "loop->revindex0 = $" . prefixLevel . "loop->length - 1; ?>";
			let iterator = "$" . prefixLevel . "iterator";
		} else {
			let iterator = exprCode;
		}

		/**
		 * Foreach statement
		 */
		let variable = statement["variable"];

		/**
		 * Check if a "key" variable needs to be calculated
		 */
		if fetch key, statement["key"] {
			let compilation .= "<?php foreach (" . iterator . " as $" . key . " => $" . variable . ") { ";
		} else {
			let compilation .= "<?php foreach (" . iterator . " as $" . variable . ") { ";
		}

		/**
		 * Check for an "if" expr in the block
		 */
		if fetch ifExpr, statement["if_expr"] {
			let compilation .= "if (" . this->expression(ifExpr) . ") { ?>";
		} else {
			let compilation .= "?>";
		}

		/**
		 * Generate the loop context inside the cycle
		 */
		if isset loopContext[level] {
			let compilation .= "<?php $" . prefixLevel . "loop->first = ($" . prefixLevel . "incr == 0); ";
			let compilation .= "$" . prefixLevel . "loop->index = $" . prefixLevel . "incr + 1; ";
			let compilation .= "$" . prefixLevel . "loop->index0 = $" . prefixLevel . "incr; ";
			let compilation .= "$" . prefixLevel . "loop->revindex = $" . prefixLevel . "loop->length - $" . prefixLevel . "incr; ";
			let compilation .= "$" . prefixLevel . "loop->revindex0 = $" . prefixLevel . "loop->length - ($" . prefixLevel . "incr + 1); ";
			let compilation .= "$" . prefixLevel . "loop->last = ($" . prefixLevel . "incr == ($" . prefixLevel . "loop->length - 1)); ?>";
		}

		/**
		 * Update the forelse var if it"s iterated at least one time
		 */
		if typeof forElse == "string" {
			let compilation .= "<?php $" . forElse . "iterated = true; ?>";
		}

		/**
		 * Append the internal block compilation
		 */
		let compilation .= code;

		if isset statement["if_expr"] {
			let compilation .= "<?php } ?>";
		}

		if typeof forElse == "string" {
			let compilation .= "<?php } ?>";
		} else {
			if isset loopContext[level] {
				let compilation .= "<?php $" . prefixLevel . "incr++; } ?>";
			} else {
				let compilation .= "<?php } ?>";
			}
		}

		let this->_foreachLevel--;

		return compilation;
	}

	/**
	 * Generates a 'forelse' PHP code
	 */
	public function compileForElse() -> string
	{
		var level, prefix;

		let level = this->_foreachLevel;
		if fetch prefix, this->_forElsePointers[level] {
			if isset this->_loopPointers[level] {
				return "<?php $" . prefix . "incr++; } if (!$" . prefix . "iterated) { ?>";
			} else {
				return "<?php } if (!$" . prefix . "iterated) { ?>";
			}
		}
		return "";
	}

	/**
	 * Compiles a 'if' statement returning PHP code
	 */
	public function compileIf(array! statement, boolean extendsMode = false) -> string
	{
		var compilation, blockStatements, expr;

		/**
		 * A valid expression is required
		 */
		if !fetch expr, statement["expr"] {
			throw new Exception("Corrupt statement");
		}

		/**
		 * Process statements in the "true" block
		 */
		let compilation = "<?php if (" . this->expression(expr) . ") { ?>" . this->_statementList(statement["true_statements"], extendsMode);

		/**
		 * Check for a "else"/"elseif" block
		 */
		if fetch blockStatements, statement["false_statements"] {

			/**
			 * Process statements in the "false" block
			 */
			let compilation .= "<?php } else { ?>" . this->_statementList(blockStatements, extendsMode);
		}

		let compilation .= "<?php } ?>";

		return compilation;
	}

	/**
	 * Compiles a "elseif" statement returning PHP code
	 */
	public function compileElseIf(array! statement) -> string
	{
		var expr;

		/**
		 * A valid expression is required
		 */
		if !fetch expr, statement["expr"] {
			throw new Exception("Corrupt statement");
		}

		/**
		 * "elseif" statement
		 */
		return "<?php } elseif (" . this->expression(expr) . ") { ?>";
	}

	/**
	 * Compiles a "cache" statement returning PHP code
	 */
	public function compileCache(array! statement, boolean extendsMode = false) -> string
	{
		var compilation, expr, exprCode, lifetime;

		/**
		 * A valid expression is required
		 */
		if !fetch expr, statement["expr"] {
			throw new Exception("Corrupt statement");
		}

		/**
		 * Cache statement
		 */
		let exprCode = this->expression(expr);
		let compilation = "<?php $_cache[" . this->expression(expr) . "] = $this->di->get('viewCache'); ";
		if fetch lifetime, statement["lifetime"] {
			let compilation .= "$_cacheKey[" . exprCode . "]";
			if lifetime["type"] == PHVOLT_T_IDENTIFIER {
				let compilation .= " = $_cache[" . exprCode . "]->start(" . exprCode . ", $" . lifetime["value"] . "); ";
			} else {
				let compilation .= " = $_cache[" . exprCode . "]->start(" . exprCode . ", " . lifetime["value"] . "); ";
			}
		} else {
			let compilation .= "$_cacheKey[" . exprCode . "] = $_cache[" . exprCode."]->start(" . exprCode . "); ";
		}
		let compilation .= "if ($_cacheKey[" . exprCode . "] === null) { ?>";

		/**
		 * Get the code in the block
		 */
		let compilation .= this->_statementList(statement["block_statements"], extendsMode);

		/**
		 * Check if the cache has a lifetime
		 */
		if fetch lifetime, statement["lifetime"] {
			if lifetime["type"] == PHVOLT_T_IDENTIFIER {
				let compilation .= "<?php $_cache[" . exprCode . "]->save(" . exprCode . ", null, $" . lifetime["value"] . "); ";
			} else {
				let compilation .= "<?php $_cache[" . exprCode . "]->save(" . exprCode . ", null, " . lifetime["value"] . "); ";
			}
			let compilation .= "} else { echo $_cacheKey[" . exprCode . "]; } ?>";
		} else {
			let compilation .= "<?php $_cache[" . exprCode . "]->save(" . exprCode . "); } else { echo $_cacheKey[" . exprCode . "]; } ?>";
		}

		return compilation;
	}

	/**
	 * Compiles a "set" statement returning PHP code
	 */
	public function compileSet(array! statement) -> string
	{
		var assignments, assignment, exprCode, variable, compilation;

		/**
		 * A valid assigment list is required
		 */
		if !fetch assignments, statement["assignments"] {
			throw new Exception("Corrupted statement");
		}

		let compilation = "<?php";

		/**
		 * A single set can have several assigments
		 */
		for assignment in assignments {

			let exprCode = this->expression(assignment["expr"]);

			/**
			 * Set statement
			 */
			let variable = assignment["variable"];

			/**
			 * Assignment operator
			 * Generate the right operator
			 */
			switch assignment["op"] {

				case PHVOLT_T_ADD_ASSIGN:
					let compilation .= " $" . variable . " += " . exprCode . ";";
					break;

				case PHVOLT_T_SUB_ASSIGN:
					let compilation .= " $" . variable . " -= " . exprCode . ";";
					break;

				case PHVOLT_T_MUL_ASSIGN:
					let compilation .= " $" . variable . " *= " . exprCode . ";";
					break;

				case PHVOLT_T_DIV_ASSIGN:
					let compilation .= " $" . variable . " /= " . exprCode . ";";
					break;

				default:
					let compilation .= " $" . variable . " = " . exprCode . ";";
					break;
			}

		}

		let compilation .= " ?>";
		return compilation;
	}

	/**
	 * Compiles a "do" statement returning PHP code
	 */
	public function compileDo(array! statement) -> string
	{
		var expr;

		/**
		 * A valid expression is required
		 */
		if !fetch expr, statement["expr"] {
			throw new Exception("Corrupted statement");
		}

		/**
		 * "Do" statement
		 */
		return "<?php " . this->expression(expr) . "; ?>";
	}

	/**
	 * Compiles a "return" statement returning PHP code
	 */
	public function compileReturn(array! statement) -> string
	{
		var expr;

		/**
		 * A valid expression is required
		 */
		if !fetch expr, statement["expr"] {
			throw new Exception("Corrupted statement");
		}

		/**
		 * "Return" statement
		 */
		return "<?php return " . this->expression(expr) . "; ?>";
	}

	/**
	 * Compiles a "autoescape" statement returning PHP code
	 */
	public function compileAutoEscape(array! statement, boolean extendsMode) -> string
	{
		var autoescape, oldAutoescape, compilation;

		/**
		 * A valid option is required
		 */
		if !fetch autoescape, statement["enable"] {
			throw new Exception("Corrupted statement");
		}

		/**
		 * "autoescape" mode
		 */
		let oldAutoescape = this->_autoescape,
			this->_autoescape = autoescape;

		let compilation = this->_statementList(statement["block_statements"], extendsMode),
			this->_autoescape = oldAutoescape;

		return compilation;
	}

	/**
	 * Compiles a '{{' '}}' statement returning PHP code
	 *
	 * @param array   statement
	 * @param boolean extendsMode
	 * @return string
	 */
	public function compileEcho(array! statement) -> string
	{
		var expr, exprCode, name;

		/**
		 * A valid expression is required
		 */
		if !fetch expr, statement["expr"] {
			throw new Exception("Corrupt statement");
		}

		/**
		 * Evaluate common expressions
		 */
		let exprCode = this->expression(expr);

		if expr["type"] == PHVOLT_T_FCALL  {

			let name = expr["name"];

			if name["type"] == PHVOLT_T_IDENTIFIER {

				/**
				 * super() is a function however the return of this function must be output as it is
				 */
				if name["value"] == "super" {
					return exprCode;
				}
			}
		}

		/**
		 * Echo statement
		 */
		if this->_autoescape {
			return "<?php echo $this->escaper->escapeHtml(" . exprCode . "); ?>";
		}

		return "<?php echo " . exprCode . "; ?>";
	}

	/**
	 * Compiles a 'include' statement returning PHP code
	 */
	public function compileInclude(array! statement) -> string
	{
		var pathExpr, path, view, subCompiler, finalPath, compilation, params;

		/**
		 * Include statement
		 * A valid expression is required
		 */
		if !fetch pathExpr, statement["path"] {
			throw new Exception("Corrupted statement");
		}

		/**
		 * Check if the expression is a string
		 * If the path is an string try to make an static compilation
		 */
		if pathExpr["type"] == 260 {

			/**
			 * Static compilation cannot be performed if the user passed extra parameters
			 */
			if !isset statement["params"]  {

				/**
				 * Get the static path
				 */
				let path = pathExpr["value"];

				let view = this->_view;
				if typeof view == "object" {
					let finalPath = view->getViewsDir() . path;
				} else {
					let finalPath = path;
				}

				/**
				 * Clone the original compiler
				 * Perform a subcompilation of the included file
				 * If the compilation doesn"t return anything we include the compiled path
				 */
				let subCompiler = clone this;
				let compilation = subCompiler->compile(finalPath, false);
				if typeof compilation == "null" {

					/**
					 * Use file-get-contents to respect the openbase_dir directive
					 */
					let compilation = file_get_contents(subCompiler->getCompiledTemplatePath());
				}

				return compilation;
			}

		}

		/**
		 * Resolve the path's expression
		 */
		let path = this->expression(pathExpr);

		/**
		 * Use partial
		 */
		if !fetch params, statement["params"] {
			return "<?php $this->partial(" . path . "); ?>";
		}

		return "<?php $this->partial(" . path . ", " . this->expression(params) . "); ?>";
	}

	/**
	 * Compiles macros
	 */
	public function compileMacro(array! statement, boolean extendsMode) -> string
	{
		var code, name, parameters, position, parameter, variableName, blockStatements;

		/**
		 * A valid name is required
		 */
		if !fetch name, statement["name"] {
			throw new Exception("Corrupted statement");
		}

		/**
		 * Check if the macro is already defined
		 */
		if isset this->_macros[name] {
			throw new Exception("Macro '" . name . "' is already defined");
		}

		/**
		 * Register the macro
		 */
		let this->_macros[name] = name;

		let code = "<?php function vmacro_";

		if !fetch parameters, statement["parameters"] {
			let code .=  name . "() { ?>";
		} else {

			/**
			 * Parameters are always received as an array
			 */
			let code .=  name . "($__p) { ";
			for position, parameter in parameters {

				let variableName = parameter["variable"];

				let code .= "if (isset($__p[" . position . "])) { ";
				let code .= "$" . variableName . " = $__p[" . position."];";
				let code .= " } else { ";
				let code .= "if (isset($__p[\"" . variableName."\"])) { ";
				let code .= "$" . variableName . " = $__p[\"" . variableName."\"];";
				let code .= " } else { ";
				let code .= " throw new \\Phalcon\\Mvc\\View\\Exception(\"Macro " . name . " was called without parameter: " . variableName . "\"); ";
				let code .= " } } ";
			}

			let code .= " ?>";
		}

		/**
		 * Block statements are allowed
		 */
		if fetch blockStatements, statement["block_statements"] {

			/**
			 * Process statements block
			 */
			let code .= this->_statementList(blockStatements, extendsMode) . "<?php } ?>";
		}  else {
			let code .= "<?php } ?>";
		}

		return code;
	}

	/**
	 * Compiles calls to macros
	 *
	 * @param array    statement
	 * @param boolean  extendsMode
	 * @return string
	 */
	public function compileCall(array! statement, boolean extendsMode)
	{

	}

	/**
	 * Traverses a statement list compiling each of its nodes
	 */
	final protected function _statementList(array! statements, boolean extendsMode = false) -> string
	{
		var extended, blockMode, compilation, extensions,
			statement, tempCompilation, type, blockName, blockStatements,
			blocks, path, view, finalPath, subCompiler, level;

		/**
		 * Nothing to compile
		 */
		if !count(statements) {
			return "";
		}

		/**
		 * Increase the statement recursion level in extends mode
		 */
		let extended = this->_extended;
		let blockMode = extended || extendsMode;
		if blockMode === true {
			let this->_blockLevel++;
		}

		let this->_level++;

		let compilation = null;

		let extensions = this->_extensions;
		for statement in statements {

			/**
			 * All statements must be arrays
			 */
			if typeof statement != "array" {
				throw new Exception("Corrupted statement");
			}

			/**
			 * Check if the statement is valid
			 */
			if !isset statement["type"] {
				throw new Exception("Invalid statement in " . statement["file"] . " on line " . statement["line"]);
			}

			/**
			 * Check if extensions have implemented custom compilation for this statement
			 */
			if typeof extensions == "array" {

				/**
				 * Notify the extensions about being resolving a statement
				 */
				let tempCompilation = this->fireExtensionEvent("compileStatement", [statement]);
				if typeof tempCompilation == "string" {
					let compilation .= tempCompilation;
					continue;
				}
			}

			/**
			 * Get the statement type
			 */
			let type = statement["type"];

			/**
			 * Compile the statement according to the statement"s type
			 */
			switch type {

				case PHVOLT_T_RAW_FRAGMENT:
					let compilation .= statement["value"];
					break;

				case PHVOLT_T_IF:
					let compilation .= this->compileIf(statement, extendsMode);
					break;

				case PHVOLT_T_ELSEIF:
					let compilation .= this->compileElseIf(statement);
					break;

				case PHVOLT_T_FOR:
					let compilation .= this->compileForeach(statement, extendsMode);
					break;

				case PHVOLT_T_SET:
					let compilation .= this->compileSet(statement);
					break;

				case PHVOLT_T_ECHO:
					let compilation .= this->compileEcho(statement);
					break;

				case PHVOLT_T_BLOCK:

					/**
					 * Block statement
					 */
					let blockName = statement["name"];

					fetch blockStatements, statement["block_statements"];

					let blocks = this->_blocks;
					if blockMode {

						if typeof blocks != "array" {
							let blocks = [];
						}

						/**
						 * Create a unamed block
						 */
						if typeof compilation != "null" {
							let blocks[] = compilation;
							let compilation = null;
						}

						/**
						 * In extends mode we add the block statements to the blocks variable
						 */
						let blocks[blockName] = blockStatements;
						let this->_blocks = blocks;

					} else {
						if typeof blockStatements == "array" {
							let compilation .= this->_statementList(blockStatements, extendsMode);
						}
					}
					break;

				case PHVOLT_T_EXTENDS:

					/**
					 * Extends statement
					 */
					let path = statement["path"];
					let view = this->_view;
					if typeof view == "object" {
						let finalPath = view->getViewsDir() . path;
					} else {
						let finalPath = path;
					}

					let extended = true;

					/**
					 * Perform a subcompilation of the extended file
					 */
					let subCompiler = clone this;
					let tempCompilation = subCompiler->compile(finalPath, extended);

					/**
					 * If the compilation doesn"t return anything we include the compiled path
					 */
					if typeof tempCompilation == "null" {
						let tempCompilation = file_get_contents(subCompiler->getCompiledTemplatePath());
					}

					let this->_extended = true;
					let this->_extendedBlocks = tempCompilation;
					let blockMode = extended;
					break;

				case PHVOLT_T_INCLUDE:
					let compilation .= this->compileInclude(statement);
					break;

				case PHVOLT_T_CACHE:
					let compilation .= this->compileCache(statement, extendsMode);
					break;

				case PHVOLT_T_DO:
					let compilation .= this->compileDo(statement);
					break;

				case PHVOLT_T_RETURN:
					let compilation .= this->compileReturn(statement);
					break;

				case PHVOLT_T_AUTOESCAPE:
					let compilation .= this->compileAutoEscape(statement, extendsMode);
					break;

				case PHVOLT_T_CONTINUE:
					/**
					 * "Continue" statement
					 */
					let compilation .= "<?php continue; ?>";
					break;

				case PHVOLT_T_BREAK:
					/**
					 * "Break" statement
					 */
					let compilation .= "<?php break; ?>";
					break;

				case 321:
					/**
					 * "Forelse" condition
					 */
					let compilation .= this->compileForElse();
					break;

				case PHVOLT_T_MACRO:
					/**
					 * Define a macro
					 */
					let compilation .= this->compileMacro(statement, extendsMode);
					break;

				case 325:
					/**
					 * "Call" statement
					 */
					let compilation .= this->compileCall(statement, extendsMode);
					break;

				case 358:
					/**
					 * Empty statement
					 */
					break;

				default:
					throw new Exception("Unknown statement " . type . " in " . statement["file"] . " on line " . statement["line"]);

			}
		}

		/**
		 * Reduce the statement level nesting
		 */
		if blockMode === true {
			let level = this->_blockLevel;
			if level == 1 {
				if typeof compilation != "null" {
					let this->_blocks[] = compilation;
				}
			}
			let this->_blockLevel--;
		}

		let this->_level--;

		return compilation;
	}

	/**
	 * Compiles a Volt source code returning a PHP plain version
	 */
	protected function _compileSource(string! viewCode, boolean extendsMode = false) -> string
	{
		var currentPath, intermediate, extended,
			finalCompilation, blocks, extendedBlocks, name, block,
			blockCompilation, localBlock, compilation;

		let currentPath = this->_currentPath;

		let intermediate = phvolt_parse_view(viewCode, currentPath);

		/**
		 * The parsing must return a valid array
		 */
		if typeof intermediate != "array" {
			throw new Exception("Invalid intermediate representation");
		}

		let compilation = this->_statementList(intermediate, extendsMode);

		/**
		 * Check if the template is extending another
		 */
		let extended = this->_extended;
		if extended === true {

			/**
			 * Multiple-Inheritance is allowed
			 */
			if extendsMode === true {
				let finalCompilation = [];
			} else {
				let finalCompilation = null;
			}

			let blocks = this->_blocks;
			let extendedBlocks = this->_extendedBlocks;

			for name, block in extendedBlocks {

				/**
				 * If name is a string then is a block name
				 */
				if typeof name == "string" {

					if isset blocks[name] {
						/**
						 * The block is set in the local template
						 */
						let localBlock = blocks[name],
							this->_currentBlock = name,
							blockCompilation = this->_statementList(localBlock);
					} else {
						if typeof block == "array" {
							/**
							 * The block is not set local only in the extended template
							 */
							let blockCompilation = this->_statementList(block);
						} else {
							let blockCompilation = block;
						}
					}

					if extendsMode === true {
						let finalCompilation[name] = blockCompilation;
					} else {
						let finalCompilation .= blockCompilation;
					}
				} else {

					/**
					 * Here the block is an already compiled text
					 */
					if extendsMode === true {
						let finalCompilation[] = block;
					} else {
						let finalCompilation .= block;
					}
				}
			}

			return finalCompilation;
		}

		if extendsMode === true {
			/**
			 * In extends mode we return the template blocks instead of the compilation
			 */
			return this->_blocks;
		}
		return compilation;
	}

	/**
	 * Compiles a template into a string
	 *
	 *<code>
	 * echo $compiler->compileString('{{ "hello world" }}');
	 *</code>
	 */
	public function compileString(string! viewCode, boolean extendsMode = false) -> string
	{
		let this->_currentPath = "eval code";
		return this->_compileSource(viewCode, extendsMode);
	}

	/**
	 * Compiles a template into a file forcing the destination path
	 *
	 *<code>
	 *	$compiler->compile('views/layouts/main.volt', 'views/layouts/main.volt.php');
	 *</code>
	 *
	 * @param string path
	 * @param string compiledPath
	 * @param boolean extendsMode
	 * @return string|array
	 */
	public function compileFile(string! path, string! compiledPath, boolean extendsMode = false)
	{
		var viewCode, compilation, finalCompilation;

		if path == compiledPath {
			throw new Exception("Template path and compilation template path cannot be the same");
		}

		/**
		 * Check if the template does exist
		 */
		if !file_exists(path) {
			throw new Exception("Template file " . path . " does not exist");
		}

		/**
		 * Always use file_get_contents instead of read the file directly, this respect the open_basedir directive
		 */
		let viewCode = file_get_contents(path);
		if viewCode === false {
			throw new Exception("Template file " . path . " could not be opened");
		}

		let this->_currentPath = path;
		let compilation = this->_compileSource(viewCode, extendsMode);

		/**
		 * We store the file serialized if it's an array of blocks
		 */
		if typeof compilation == "array" {
			let finalCompilation = serialize(compilation);
		} else {
			let finalCompilation = compilation;
		}

		/**
		 * Always use file_put_contents to write files instead of write the file directly, this respect the open_basedir directive
		 */
		if file_put_contents(compiledPath, finalCompilation) === false {
			throw new Exception("Volt directory can't be written");
		}

		return compilation;
	}

	/**
	 * Compiles a template into a file applying the compiler options
	 * This method does not return the compiled path if the template was not compiled
	 *
	 *<code>
	 *	$compiler->compile('views/layouts/main.volt');
	 *	require $compiler->getCompiledTemplatePath();
	 *</code>
	 *
	 * @param string templatePath
	 * @param boolean extendsMode
	 * @return string|array
	 */
	public function compile(string! templatePath, boolean extendsMode = false)
	{
		var stat, compileAlways, prefix, compiledPath, compiledSeparator, blocksCode,
			compiledExtension, compilation, options, realCompiledPath,
			compiledTemplatePath, templateSepPath;

		/**
		 * Re-initialize some properties already initialized when the object is cloned
		 */
		let this->_extended = false;
		let this->_extendedBlocks = false;
		let this->_blocks = null;
		let this->_level = 0;
		let this->_foreachLevel = 0;
		let this->_blockLevel = 0;
		let this->_exprLevel = 0;

		let stat = true;
		let compileAlways = false;
		let compiledPath = "";
		let prefix = null;
		let compiledSeparator = "%%";
		let compiledExtension = ".php";
		let compilation = null;

		let options = this->_options;
		if typeof options == "array" {

			/**
			 * This makes that templates will be compiled always
			 */
			if isset options["compileAlways"] {
				let compileAlways = options["compileAlways"];
				if typeof compileAlways != "boolean" {
					throw new Exception("compileAlways must be a bool value");
				}
			}

			/**
			 * Prefix is prepended to the template name
			 */
			if isset options["prefix"] {
				let prefix = options["prefix"];
				if typeof prefix != "string" {
					throw new Exception("prefix must be a string");
				}
			}

			/**
			 * Compiled path is a directory where the compiled templates will be located
			 */
			if isset options["compiledPath"] {
				let compiledPath = options["compiledPath"];
				if typeof compiledPath != "string" {
					if typeof compiledPath != "object" {
						throw new Exception("compiledPath must be a string or a closure");
					}
				}
			}

			/**
			 * There is no compiled separator by default
			 */
			if isset options["compiledSeparator"] {
				let compiledSeparator = options["compiledSeparator"];
				if typeof compiledSeparator != "string" {
					throw new Exception("compiledSeparator must be a string");
				}
			}

			/**
			 * By default the compile extension is .php
			 */
			if isset options["compiledExtension"] {
				let compiledExtension = options["compiledExtension"];
				if typeof compiledExtension != "string" {
					throw new Exception("compiledExtension must be a string");
				}
			}

			/**
			 * Stat option assumes the compilation of the file
			 */
			if isset options["stat"] {
				let stat = options["stat"];
			}
		}

		/**
		 * Check if there is a compiled path
		 */
		if typeof compiledPath == "string" {

			/**
			 * Calculate the template realpath's
			 */
			if !empty compiledPath {
				/**
				 * Create the virtual path replacing the directory separator by the compiled separator
				 */
				let templateSepPath = prepare_virtual_path(realpath(templatePath), compiledSeparator);
			} else {
				let templateSepPath = templatePath;
			}

			/**
			 * In extends mode we add an additional 'e' suffix to the file
			 */
			if extendsMode === true {
				let compiledTemplatePath = compiledPath . prefix . templateSepPath . compiledSeparator . "e" . compiledSeparator . compiledExtension;
			} else {
				let compiledTemplatePath = compiledPath . prefix . templateSepPath . compiledExtension;
			}

		} else {

			/**
			 * A closure can dynamically compile the path
			 */
			if typeof compiledPath == "object" {

				if compiledPath instanceof \Closure {

					let compiledTemplatePath = call_user_func_array(compiledPath, [templatePath, options, extendsMode]);

					/**
					 * The closure must return a valid path
					 */
					if typeof compiledTemplatePath != "string" {
						throw new Exception("compiledPath closure didn't return a valid string");
					}
				} else {
					throw new Exception("compiledPath must be a string or a closure");
				}
			}
		}

		/**
		 * Use the real path to avoid collisions
		 */
		let realCompiledPath = compiledTemplatePath;

		if compileAlways {

			/**
			 * Compile always must be used only in the development stage
			 */
			let compilation = this->compileFile(templatePath, realCompiledPath, extendsMode);
		} else {
			if stat === true {
				if file_exists(compiledTemplatePath) {

					/**
					 * Compare modification timestamps to check if the file needs to be recompiled
					 */
					if compare_mtime(templatePath, realCompiledPath) {
						let compilation = this->compileFile(templatePath, realCompiledPath, extendsMode);
					} else {

						if extendsMode === true {

							/**
							 * In extends mode we read the file that must contains a serialized array of blocks
							 */
							let blocksCode = file_get_contents(realCompiledPath);
							if blocksCode === false {
								throw new Exception("Extends compilation file " . realCompiledPath . " could not be opened");
							}

							/**
							 * Unserialize the array blocks code
							 */
							if blocksCode {
								let compilation = unserialize(blocksCode);
							} else {
								let compilation = [];
							}
						}
					}
				} else {

					/**
					 * The file doesn't exist so we compile the php version for the first time
					 */
					let compilation = this->compileFile(templatePath, realCompiledPath, extendsMode);
				}
			} else {

				/**
				 * Stat is off but the compiled file doesn't exist
				 */
				if !file_exists(realCompiledPath) {
					throw new Exception("Compiled template file " . realCompiledPath . " does not exist");
				}

			}
		}

		let this->_compiledTemplatePath = realCompiledPath;

		return compilation;
	}

	/**
	 * Returns the path that is currently being compiled
	 */
	public function getTemplatePath() -> string
	{
		return this->_currentPath;
	}

	/**
	 * Returns the path to the last compiled template
	 */
	public function getCompiledTemplatePath() -> string
	{
		return this->_compiledTemplatePath;
	}

	/**
	 * Parses a Volt template returning its intermediate representation
	 *
	 *<code>
	 *	print_r($compiler->parse('{{ 3 + 2 }}'));
	 *</code>
	 *
	 * @param string viewCode
	 * @return array
	 */
	public function parse(string! viewCode)
	{
		var currentPath = "eval code";
		return phvolt_parse_view(viewCode, currentPath);
	}
}
