
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

namespace Phalcon\Mvc\View\Engine\Markdown;

use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Mvc\View\Exception;
use Phalcon\Mvc\View\Engine\Markdown as Markdown;

/**
 * Phalcon\Mvc\View\Engine\Markdown\Compiler
 *
 * This class reads and compiles Markdown templates into PHP plain code
 *
 *<code>
 *  $compiler = new \Phalcon\Mvc\View\Engine\Markdown\Compiler();
 *
 *  $compiler->compile('views/partials/header.md');
 *
 *  require $compiler->getCompiledTemplatePath();
 *</code>
 */
class Compiler implements InjectionAwareInterface
{
	protected _dependencyInjector;

	protected _view;

	protected _options;

	protected _currentPath;

	protected _compiledTemplatePath;

	protected _compilation = "";

	protected _toc = "";

	protected _meta = "";

	protected _defaultCompileOption = [
		Markdown::TABLES, Markdown::FENCED_CODE, Markdown::AUTOLINK,
		Markdown::STRIKETHROUGH, Markdown::NO_INTRA_EMPHASIS,
		Markdown::TASK, Markdown::SCRIPT_TAGS
	];

	/**
	 * Phalcon\Mvc\View\Engine\Markdown\Compiler
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
	public function setDI(<\Phalcon\DiInterface> dependencyInjector)
	{
		if typeof dependencyInjector != "object" {
			throw new Exception("Dependency Injector is invalid");
		}
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the internal dependency injector
	 *
	 * @return Phalcon\DiInterface
	 */
	public function getDI() -> <\Phalcon\DiInterface>
	{
		return this->_dependencyInjector;
	}

	/**
	 * Sets the compiler options
	 *
	 * @param array options
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
	 *
	 * @return array
	 */
	public function getOptions()
	{
		return this->_options;
	}

	/**
	 * Compiles a Markdown source code returning a PHP plain version
	 *
	 * @param string  viewCode
	 * @return string
	 */
	protected function _compileSource(string! viewCode) -> string
	{
		var intermediate, options, code,
			compileOption, compileRender, afterCompile;

		let compileOption = this->_defaultCompileOption,
			compileRender = [], afterCompile = null;

		let options = this->_options;
		if typeof options == "array" {

			if isset options["compileOption"] && typeof options["compileOption"] == "array" {
				let compileOption = options["compileOption"];
			}

			if isset options["compileRender"] && typeof options["compileRender"] == "array" {
				let compileRender = options["compileRender"];
			}

			if isset options["beforeCompile"] && typeof options["beforeCompile"] == "object" && options["beforeCompile"] instanceof \Closure {
				let code = call_user_func_array(options["beforeCompile"], [viewCode]);
				let viewCode = (string)code;
			}

			if isset options["afterCompile"] && typeof options["afterCompile"] == "object" && options["afterCompile"] instanceof \Closure {
				let afterCompile = options["afterCompile"];
			}

		}

		let intermediate = phmarkdown_parse_view(viewCode, compileOption, compileRender);

		if typeof intermediate == "array" {
			if isset intermediate["result"] {
				let this->_compilation = intermediate["result"];
			}

			if isset intermediate["toc"] {
				let this->_toc = intermediate["toc"];
			}

			if isset intermediate["meta"] {
				let this->_meta = intermediate["meta"];
			}

			if is_callable(afterCompile) {
				let code = call_user_func_array(afterCompile, [this]);
				if code != null {
					let this->_compilation = code;
				}
			}

			return this->_compilation;
		}

		throw new Exception("Invalid intermediate representation");
	}

	/**
	 * Compiles a template into a string
	 *
	 *<code>
	 *  echo $compiler->compileString('hello world');
	 *</code>
	 *
	 * @param  string  viewCode
	 * @return string
	 */
	public function compileString(string! viewCode) -> string
	{
		let this->_currentPath = "eval code";
		return this->_compileSource(viewCode);
	}

	/**
	 * Compiles a template into a file forcing the destination path
	 *
	 *<code>
	 *  $compiler->compile('views/layouts/main.md', 'views/layouts/main.markdown.php');
	 *</code>
	 *
	 * @param string path
	 * @param string compiledPath
	 * @return string|array
	 */
	public function compileFile(string! path, string! compiledPath)
	{
		var viewCode, compilation;

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
		let compilation = this->_compileSource(viewCode);

		/**
		 * Always use file_put_contents to write files instead of write the file directly, this respect the open_basedir directive
		 */
		if file_put_contents(compiledPath, compilation) === false {
			throw new Exception("Markdown directory can't be written");
		}

		return compilation;
	}

	/**
	 * Compiles a template into a file applying the compiler options
	 * This method does not return the compiled path if the template was not compiled
	 *
	 *<code>
	 *  $compiler->compile('views/layouts/main.md');
	 *  require $compiler->getCompiledTemplatePath();
	 *</code>
	 *
	 * @param string templatePath
	 * @return string|array
	 */
	public function compile(string! templatePath)
	{
		var stat, compileAlways, prefix, compiledPath, compiledSeparator,
			compiledExtension, compilation, options, realCompiledPath,
			compiledTemplatePath, templateSepPath;

		/**
		 * Re-initialize some properties already initialized when the object is cloned
		 */
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
			let compiledTemplatePath = compiledPath . prefix . templateSepPath . compiledExtension;

		} else {

			/**
			 * A closure can dynamically compile the path
			 */
			if typeof compiledPath == "object" {

				if compiledPath instanceof \Closure {

					let compiledTemplatePath = call_user_func_array(compiledPath, [templatePath, options]);

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
			let compilation = this->compileFile(templatePath, realCompiledPath);
		} else {
			if stat === true {
				if file_exists(compiledTemplatePath) {

					/**
					 * Compare modification timestamps to check if the file needs to be recompiled
					 */
					if compare_mtime(templatePath, realCompiledPath) {
						let compilation = this->compileFile(templatePath, realCompiledPath);
					}
				} else {

					/**
					 * The file doesn't exist so we compile the php version for the first time
					 */
					let compilation = this->compileFile(templatePath, realCompiledPath);
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
	 * Parses a Markdown template returning its intermediate representation
	 *
	 *<code>
	 *  print_r($compiler->parse('# example'));
	 *</code>
	 *
	 * @param string viewCode
	 * @return array
	 */
	public function parse(string! viewCode)
	{
		return this->compileString(viewCode);
	}

	/**
	 * Returns the compiled content to the last compiled template
	 *
	 * @return string
	 */
	public function getCompiled()
	{
		return this->_compilation;
	}

	/**
	 * Returns the toc content to the last compiled template
	 *
	 * @return string
	 */
	public function getToc()
	{
		return this->_toc;
	}

	/**
	 * Returns the meta content to the last compiled template
	 *
	 * @return string
	 */
	public function getMeta()
	{
		return this->_meta;
	}
}
