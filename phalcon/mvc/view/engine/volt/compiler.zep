
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
class Compiler implements Phalcon\Di\InjectionAwareInterface
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
	 *
	 * @param Phalcon\Mvc\ViewInterface view
	 */
	public function __construct(view=null)
	{
		if typeof view == "object" {
			let this->_view = view;
		}
	}

	/**
	 * Sets the dependency injector
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public function setDI(<Phalcon\DiInterface> dependencyInjector)
	{
		if typeof dependencyInjector != "object" {
			throw new Phalcon\Mvc\View\Exception("Dependency Injector is invalid");
		}
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the internal dependency injector
	 *
	 * @return Phalcon\DiInterface
	 */
	public function getDI() -> <Phalcon\DiInterface>
	{
		return this->_dependencyInjector;
	}

	/**
	 * Sets the compiler options
	 *
	 * @param array options
	 */
	public function setOptions(options)
	{
		if typeof options != "array" {
			throw new Phalcon\Mvc\View\Exception("Options must be an array");
		}
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
	 *
	 * @return array
	 */
	public function getOptions()
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
	public function fireExtensionEvent(string! name, arguments=null)
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
	public function addExtension(extension)
	{
		if typeof extension != "object" {
			throw new Phalcon\Mvc\View\Exception("The extension is not valid");
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
	 *
	 * @return array
	 */
	public function getExtensions()
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
	public function addFunction(string! name, definition)
	{
		let this->_functions[name] = definition;
		return this;
	}

	/**
	 * Register the user registered functions
	 *
	 * @return array
	 */
	public function getFunctions()
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
	public function addFilter(string! name, definition)
	{
		let this->_filters[name] = definition;
		return this;
	}

	/**
	 * Register the user registered filters
	 *
	 * @return array
	 */
	public function getFilters()
	{
		return this->_filters;
	}

	/**
	 * Set a unique prefix to be used as prefix for compiled variables
	 *
	 * @param string prefix
	 * @return Phalcon\Mvc\View\Engine\Volt\Compiler
	 */
	public function setUniquePrefix(string! prefix) -> <Phalcon\Mvc\View\Engine\Volt\Compiler>
	{
		let this->_prefix = prefix;
		return this;
	}

	/**
	 * Return a unique prefix to be used as prefix for compiled variables and contexts
	 *
	 * @return string
	 */
	public function getUniquePrefix() -> string
	{
		var prefix, calculatedPrefix;

		let prefix = this->_prefix;

		/**
		 * If the unique prefix is not set we use a hash using the modified Berstein algotithm
		 */
		if !prefix {
			let prefix = phalcon_unique_path_key(this->_currentPath);
			let this->_prefix = prefix;
		}

		/**
		 * The user could use a closure generator
		 */
		if typeof prefix == "object" {
			if prefix instanceof Closure {
				let calculatedPrefix = call_user_func_array(prefix, [this]),
					this->_prefix = calculatedPrefix,
					prefix = calculatedPrefix;
			}
		}

		if typeof prefix != "string" {
			throw new Phalcon\Mvc\View\Exception("The unique compilation prefix is invalid");
		}

		return prefix;
	}

	/**
	 * Resolves attribute reading
	 *
	 * @param array expr
	 * @return string
	 */
	public function attributeReader(expr)
	{
		var exprCode, loopContext, left, leftType, variable,
			level, prefix, dependencyInjector, leftCode, right;

		let exprCode = null, loopContext = null;

		let left = expr["left"];

		if left["type"] == 265 {

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
			if leftType != 46 {
				if leftType != 350 {
					let exprCode .= "(" . leftCode . ")";
				} else {
					let exprCode .= leftCode;
				}
			} else {
				let exprCode .= leftCode;
			}
		}

		let exprCode .= "->";

		let right = expr["right"];

		if right["type"] == 265 {
			let exprCode .= right["value"];
		} else {
			let exprCode .= this->expression(right);
		}

		return exprCode;
	}

	/**
	 * Resolves function intermediate code into PHP function calls
	 *
	 * @param array expr
	 * @return string
	 */
	public function functionCall(expr)
	{
		var code, funcArguments, arguments, nameExpr,
			nameType, name, extensions, functions, definition, macros,
			extendedBlocks, block, currentBlock, exprLevel, escapedCode,
			method, arrayHelpers, className;

		/**
		 * Valid filters are always arrays
		 */
		if typeof expr != "array" {
			throw new Phalcon\Mvc\View\Exception("Corrupted function call");
		}

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
		if nameType == 265 {

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

						if definition instanceof "Closure" {
							return call_user_func_array(definition, [arguments, funcArguments]);
						}
					}

					throw new Phalcon\Mvc\View\Exception("Invalid definition for user function '" . name . "' in " . expr["file"] . " on line " . expr["line"]);
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
			if name == "get_content" {
				return "$this->getContent()";
			}

			/**
			 * Alias of "get_content"
			 */
			if name == "content" {
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
						 * If the super() is the first level we don"t escape it
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
						"date_field": true,
						"numeric_field": true
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
			 * The function doesn\t exist throw an exception
			 */
			throw new Phalcon\Mvc\View\Exception("Undefined function '" . name . "' in " . expr["file"] . " on line " . expr["line"]);

		}

		return this->expression(nameExpr) . "(" . arguments . ")";
	}

	/**
	 * Resolves filter intermediate code into a valid PHP expression
	 *
	 * @param array test
	 * @param string left
	 * @return string
	 */
	public function resolveTest(test, left) -> string
	{
		var type, name, testName;

		/**
		 * Valid tests are always arrays
		 */
		if typeof test != "array" {
			throw new Phalcon\Mvc\View\Exception("Corrupted test");
		}

		let type = test["type"];

		/**
		 * Check if right part is a single identifier
		 */
		if type == 265 {

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
		if type == 350 {

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
	 *
	 * @param array filter
	 * @param string left
	 * @return string
	 */
	protected function resolveFilter(filter, left)
	{
		var code, type, functionName, name, file, line,
			extensions, filters, funcArguments, arguments, definition;

		/**
		 * Valid filters are always arrays
		 */
		if typeof filter != "array" {
			throw new Phalcon\Mvc\View\Exception("Corrupted filter");
		}

		let code = null, type = filter["type"];

		/**
		 * Check if the filter is a single identifier
		 */
		if type == 265 {
			let name = filter["value"];
		} else {
			if type == 350 {
				let functionName = filter["name"];
				let name = functionName["value"];
			} else {
				/**
				 * Unknown filter throw an exception
				 */
				throw new Phalcon\Mvc\View\Exception("Unknown filter type in " . filter["file"] . " on line " . filter["line"]);
			}
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
			let code = this->fireExtensionEvent("compileFilter", [arguments, funcArguments]);
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
					if definition instanceof Closure {
						return call_user_func_array(definition, [arguments, funcArguments]);
					}
				}

				/**
				 * Invalid filter definition throw an exception
				 */
				throw new Phalcon\Mvc\View\Exception("Invalid definition for user filter '" . name . "' in " . filter["file"] . " on line " . filter["line"]);
			}
		}

		/**
		 * "length" uses the length method implemented in the Volt adapter
		 */
		if name == "length" {
			return "this->length(" . arguments . ")";
		}

		/**
		 * "e" filter uses the escaper component
		 */
		if name == "e" {
			return "this->escaper->escapeHtml(" . arguments . ")";
		}

		/**
		 * "escape" filter uses the escaper component
		 */
		if name == "escape" {
			return "this->escaper->escapeHtml(" . arguments . ")";
		}

		/**
		 * "escapecss" filter uses the escaper component to filter css
		 */
		if name == "escape_css" {
			return "this->escaper->escapeCss(" . arguments . ")";
		}

		/**
		 * "escapejs" filter uses the escaper component to escape javascript
		 */
		if name == "escape_js" {
			return "this->escaper->escapeJs(" . arguments . ")";
		}

		/**
		 * "escapeattr" filter uses the escaper component to escape html attributes
		 */
		if name == "escape_attr" {
			return "this->escaper->escapeHtmlAttr(" . arguments . ")";
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
		 * "urlencode" calls the "urlencode" function in the PHP userland
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
		 * "lowercase" calls the "strtolower" function or "mb_strtolower" if the mbstring extension is loaded
		 */
		if name == "lowercase" {
			return "Phalcon\\Text::lower(" . arguments . ")";
		}

		/**
		 * "lowercase" calls the "strtolower" function or "mb_strtolower" if the mbstring extension is loaded
		 */
		if name == "lower" {
			return "Phalcon\\Text::lower(" . arguments . ")";
		}

		/**
		 * "uppercase" calls the "strtouppwer" function or "mb_strtoupper" if the mbstring extension is loaded
		 */
		if name == "uppercase" {
			return "Phalcon\\Text::upper(" . arguments . ")";
		}

		/**
		 * "uppercase" calls the "strtouppwer" function or "mb_strtoupper" if the mbstring extension is loaded
		 */
		if name == "upper" {
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
			return "this->sort(" . arguments . ")";
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
		throw new Phalcon\Mvc\View\Exception("Unknown filter '" . name . "' in " . filter["file"] . " on line " . filter["line"]);
	}

	/**
	 * Resolves an expression node in an AST volt tree
	 *
	 * @param array expr
	 * @return string
	 */
	public function expression(expr)
	{
		var exprCode, extensions, items, singleExpr, singleExprCode, name,
			left, leftCode, right, rightCode, type, startCode, endCode, start, end;

		/**
		 * Valid expressions are always arrays
		 */
		if typeof expr != "array" {
			throw new Phalcon\Mvc\View\Exception("Corrupted expression");
		}

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

			if !isset expr["type"] {
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

			let type = expr["type"];

			/**
			 * Attribute reading needs special handling
			 */
			if type == 46 {
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
			if type == 311 {
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
				case 360:
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
				case 260:
					let exprCode = "'" . str_replace("'", "\\'", expr["value"]) . "'";
					break;
				case 261:
					let exprCode = "null";
					break;
				case 262:
					let exprCode = "false";
					break;
				case 263:
					let exprCode = "true";
					break;
				case 265:
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
				case 276:
					let exprCode = "range(" . leftCode . ", " . rightCode . ")";
					break;
				case 350:
					let exprCode = this->functionCall(expr);
					break;
				case 356:
					let exprCode = "(" . leftCode . ")";
					break;
				case 361:
					let exprCode = leftCode . "[" . rightCode . "]";
					break;
				case 365:

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

				case 362:
					let exprCode = "!isset(" . leftCode . ")";
					break;

				case 363:
					let exprCode = "isset(" . leftCode . ")";
					break;

				case 309:
					let exprCode = "$this->isIncluded(" . leftCode . ", " . rightCode . ")";
					break;

				case 369:
					let exprCode = "!$this->isIncluded(" . leftCode . ", " . rightCode . ")";
					break;

				case 366:
					let exprCode = "(" . this->expression(expr["ternary"]) . " ? " . leftCode . " : " . rightCode . ")";
					break;

				case 367:
					let exprCode = "-" . rightCode;
					break;

				case 368:
					let exprCode = "+" . rightCode;
					break;

				case 364:
					let exprCode = expr["value"];
					break;

				default:
					throw new Phalcon\Mvc\View\Exception("Unknown expression " . type . " in " . expr["file"] . " on line " . expr["line"]);
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
	protected function _statementListOrExtends(statements)
	{
		var statement;
		boolean isStatementList;

		/**
		 * Resolve the statement list as normal
		 */
		if typeof statements == "array" {
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
			//return this->_statementList(statements);
		}

		/**
		 * Is an array but not a statement list?
		 */
		return statements;
	}

	/**
	 * Compiles a template into a string
	 *
	 *<code>
	 * echo $compiler->compileString('{{ "hello world" }}');
	 *</code>
	 *
	 * @param string  viewCode
	 * @param boolean extendsMode
	 * @return string
	 */
	public function compileString(string! viewCode, boolean extendsMode=false) -> string
	{
		let this->_currentPath = "eval code";
		//return this->_compileSource(viewCode, extendsMode);
		return "";
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
	public function compileFile(string! path, string! compiledPath, boolean extendsMode=false)
	{
		var viewCode, compilation, finalCompilation;

		if path == compiledPath {
			throw new Phalcon\Mvc\View\Exception("Template path and compilation template path cannot be the same");
		}

		/**
		 * Check if the template does exist
		 */
		if !file_exists(path) {
			throw new Phalcon\Mvc\View\Exception("Template file " . path . " does not exist");
		}

		/**
		 * Always use file_get_contents instead of read the file directly, this respect the open_basedir directive
		 */
		let viewCode = file_get_contents(path);
		if viewCode === false {
			throw new Phalcon\Mvc\View\Exception("Template file " . path . " could not be opened");
		}

		let this->_currentPath = path;
		let compilation = null; //this->_compileSource(viewCode, extendsMode);

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
			throw new Phalcon\Mvc\View\Exception("Volt directory can't be written");
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
	public function compile(string! templatePath, boolean extendsMode=false)
	{
		var stat, compileAlways;
		var prefix, compiledPath, compiledSeparator, blocksCode,
			compiledExtension, compilation, options, realCompiledPath,
			compiledTemplatePath, realTemplatePath, templateSepPath;

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
			if fetch compileAlways, options["compileAlways"] {
				if typeof compileAlways != "bool" {
					throw new Phalcon\Mvc\View\Exception("compileAlways must be a bool value");
				}
			}

			/**
			 * Prefix is prepended to the template name
			 */
			if fetch prefix, options["prefix"] {
				if typeof prefix != "string" {
					throw new Phalcon\Mvc\View\Exception("prefix must be a string");
				}
			}

			/**
			 * Compiled path is a directory where the compiled templates will be located
			 */
			if fetch compiledPath, options["compiledPath"] {
				if typeof compiledPath != "string" {
					if typeof compiledPath != "object" {
						throw new Phalcon\Mvc\View\Exception("compiledPath must be a string or a closure");
					}
				}
			}

			/**
			 * There is no compiled separator by default
			 */
			if fetch compiledSeparator, options["compiledSeparator"] {
				if typeof compiledSeparator != "string" {
					throw new Phalcon\Mvc\View\Exception("compiledSeparator must be a string");
				}
			}

			/**
			 * By default the compile extension is .php
			 */
			if fetch compiledExtension, options["compiledExtension"] {
				if typeof compiledExtension != "string" {
					throw new Phalcon\Mvc\View\Exception("compiledExtension must be a string");
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

				let realTemplatePath = realpath(templatePath);

				/**
				 * Create the virtual path replacing the directory separator by the compiled separator
				 */
				let templateSepPath = phalcon_prepare_virtual_path(realTemplatePath, compiledSeparator);
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

				if compiledPath instanceof Closure {

					let compiledTemplatePath = call_user_func_array(compiledPath, [templatePath, options, extendsMode]);

					/**
					 * The closure must return a valid path
					 */
					if typeof compiledTemplatePath == "string" {
						throw new Phalcon\Mvc\View\Exception("compiledPath closure didn't return a valid string");
					}
				} else {
					throw new Phalcon\Mvc\View\Exception("compiledPath must be a string or a closure");
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
								throw new Phalcon\Mvc\View\Exception("Extends compilation file " . realCompiledPath . " could not be opened");
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
					throw new Phalcon\Mvc\View\Exception("Compiled template file " . realCompiledPath . " does not exist");
				}

			}
		}

		let this->_compiledTemplatePath = realCompiledPath;

		return compilation;
	}

	/**
	 * Returns the path that is currently being compiled
	 *
	 * @return string
	 */
	public function getTemplatePath()
	{
		return this->_currentPath;
	}

	/**
	 * Returns the path to the last compiled template
	 *
	 * @return string
	 */
	public function getCompiledTemplatePath()
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
		return phvolt_parse_view(viewCode, "eval code");
	}

}
