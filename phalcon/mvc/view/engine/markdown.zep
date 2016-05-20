
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

namespace Phalcon\Mvc\View\Engine;

use Phalcon\Mvc\View\Engine;
use Phalcon\Mvc\View\EngineInterface;
use Phalcon\Mvc\View\Engine\Markdown\Compiler;
use Phalcon\Mvc\View\Exception;

/**
 * Phalcon\Mvc\View\Engine\Markdown
 *
 * Designer friendly and fast template engine for PHP written in C
 */
class Markdown extends Engine implements EngineInterface
{
	const SKIP_HTML             = "skip-html";
	const HARD_WRAP             = "hard-wrap";
	const USE_XHTML             = "xhtml";
	const ESCAPE                = "escape";
	const TABLES                = "tables";
	const FENCED_CODE           = "fenced-code";
	const FENCED_CODE_SCRIPT    = "fenced-code-script";
	const AUTOLINK              = "autolink";
	const STRIKETHROUGH         = "strikethrough";
	const NO_INTRA_EMPHASIS     = "no-intra-emphasis";
	const FOOTNOTES             = "footnotes";
	const UNDERLINE             = "underline";
	const HIGHLIGHT             = "highlight";
	const QUOTE                 = "quote";
	const SUPERSCRIPT           = "superscript";
	const MATH                  = "math";
	const MATH_EXPLICIT         = "math-explicit";
	const SPACE_HEADERS         = "space-headers";
	const DISABLE_INDENTED_CODE = "disable-indented-code";
	const HEADER_ID             = "header-id";
	const LINE_CONTINUE         = "line-continue";
	const TASK                  = "task";
	const SPECIAL_ATTRIBUTE     = "special-attribute";
	const SCRIPT_TAGS           = "script-tags";
	const META_BLOCK            = "meta-block";
	const TOC                   = "toc";

	protected _options;

	protected _compiler;

	/**
	 * Set Markdown's options
	 *
	 * @param array options
	 */
	public function setOptions(array! options)
	{
		let this->_options = options;
	}

	/**
	 * Return Markdown's options
	 *
	 * @return array
	 */
	public function getOptions()
	{
		return this->_options;
	}

	/**
	 * Returns the Markdown's compiler
	 *
	 * @return Phalcon\Mvc\View\Engine\Markdown\Compiler
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
			let dependencyInjector = <\Phalcon\Di> this->_dependencyInjector;
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
	 *
	 * @param string  $templatePath
	 * @param array   $params
	 * @param boolean $mustClean
	 */
	public function render(string! templatePath, var params, boolean mustClean = false)
	{
		var compiler, compiledTemplatePath, key, value;

		if mustClean {
			ob_clean();
		}

		/**
		 * The compilation process is done by Phalcon\Mvc\View\Engine\Markdown\Compiler
		 */
		let compiler = this->getCompiler();

		compiler->compile(templatePath);

		let compiledTemplatePath = compiler->getCompiledTemplatePath();

		/**
		 * Export the variables the current symbol table
		 */
		if typeof params == "array" {
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

}
