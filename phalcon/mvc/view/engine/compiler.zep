
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

use Phalcon\Mvc\View\Engine;
use Phalcon\Mvc\View\EngineInterface;
use Phalcon\Mvc\View\Exception;

/**
 * Phalcon\Mvc\View\Engine\Compiler
 */
class Compiler extends Engine implements EngineInterface
{

	protected _options;

	protected _compiledTemplatePath;

	/**
	 * Set Volt's options
	 *
	 * @param array options
	 */
	public function setOptions(array! options)
	{
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
	 * Compiles a source code returning a PHP plain version
	 *
	 * @param string  viewCode
	 * @return string
	 */
	protected function _compileSource(string! viewCode) -> string
	{
		var options, compiledSource;

		let options = this->_options;

		if typeof options == "array" {

			/**
			 * This makes that templates will be compiled source
			 */
			if isset options["compiledSource"] {
				let compiledSource = options["compiledSource"];

				if is_callable(compiledSource) {
					return call_user_func_array(compiledSource, [viewCode]);
				}
			}

		}

		throw new Exception("compileSource must be a string or closure");
	}

	/**
	 * Compiles a template into a file forcing the destination path
	 *
	 * @param string path
	 * @param string compiledPath
	 * @return string
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

		let compilation = this->_compileSource(viewCode);

		/**
		 * Always use file_put_contents to write files instead of write the file directly, this respect the open_basedir directive
		 */
		if file_put_contents(compiledPath, compilation) === false {
			throw new Exception("Compile directory can't be written");
		}

		return compilation;
	}

	/**
	 * Compiles a template
	 *
	 * @param string templatePath
	 * @return string
	 */
	public function compile(string !templatePath)
	{
		var stat, compileAlways, prefix, compiledPath, compiledSeparator,
			compiledExtension, compilation, options, realCompiledPath,
			compiledTemplatePath, templateSepPath;

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
	 * Renders a view using the template engine
	 *
	 * @param string  $templatePath
	 * @param array   $params
	 * @param boolean $mustClean
	 */
	public function render(string! templatePath, var params, boolean mustClean = false)
	{
		var key, value;

		if mustClean {
			ob_clean();
		}

		/**
		 * The compilation process is done
		 */
		this->compile(templatePath);

		/**
		 * Export the variables the current symbol table
		 */
		if typeof params == "array" {
			for key, value in params {
				let {key} = value;
			}
		}

		require this->_compiledTemplatePath;

		if mustClean {
			this->_view->setContent(ob_get_contents());
			//ob_clean();
		}
	}

}
