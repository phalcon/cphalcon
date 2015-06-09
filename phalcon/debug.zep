
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

namespace Phalcon;

/**
 * Phalcon\Debug
 *
 * Provides debug capabilities to Phalcon applications
 */
class Debug
{
	public _uri = "http://static.phalconphp.com/debug/2.0.0/";

	public _theme = "default";

	protected _hideDocumentRoot = false;

	protected _showBackTrace = true;

	protected _showFiles = true;

	protected _showFileFragment = false;

	protected _data;

	protected static _isActive;

	/**
	 * Change the base URI for static resources
	 */
	public function setUri(string! uri) -> <Debug>
	{
		let this->_uri = uri;
		return this;
	}

	/**
	 * Sets if files the exception"s backtrace must be showed
	 */
	public function setShowBackTrace(boolean showBackTrace) -> <Debug>
	{
		let this->_showBackTrace = showBackTrace;
		return this;
	}

	/**
	 * Set if files part of the backtrace must be shown in the output
	 */
	public function setShowFiles(boolean showFiles) -> <Debug>
	{
		let this->_showFiles = showFiles;
		return this;
	}

	/**
	 * Sets if files must be completely opened and showed in the output
	 * or just the fragment related to the exception
	 */
	public function setShowFileFragment(boolean showFileFragment) -> <Debug>
	{
		let this->_showFileFragment = showFileFragment;
		return this;
	}

	/**
	 * Listen for uncaught exceptions and unsilent notices or warnings
	 */
	public function listen(boolean exceptions = true, boolean lowSeverity = false) -> <Debug>
	{
		if exceptions {
			this->listenExceptions();
		}
		if lowSeverity {
			this->listenLowSeverity();
		}
		return this;
	}

	/**
	 * Listen for uncaught exceptions
	 */
	public function listenExceptions() -> <Debug>
	{
		set_exception_handler([this, "onUncaughtException"]);
		return this;
	}

	/**
	 * Listen for unsilent notices or warnings
	 */
	public function listenLowSeverity() -> <Debug>
	{
		set_error_handler([this, "onUncaughtLowSeverity"]);
		set_exception_handler([this, "onUncaughtException"]);
		return this;
	}

	/**
	 * Halts the request showing a backtrace
	 */
	public function halt()
	{
		throw new Exception("Halted request");
	}

	/**
	 * Adds a variable to the debug output
	 */
	public function debugVar(varz, string key = null) -> <Debug>
	{
		let this->_data[] = [varz, debug_backtrace(), time()];
		return this;
	}

	/**
	 * Clears are variables added previously
	 */
	public function clearVars() -> <Debug>
	{
		let this->_data = null;
		return this;
	}

	/**
	 * Escapes a string with htmlentities
	 */
	protected function _escapeString(var value) -> string
	{
		if typeof value == "string" {
			return htmlentities(str_replace("\n", "\\n", value), ENT_COMPAT, "utf-8");
		}
		return value;
	}

	/**
	 * Produces a recursive representation of an array
	 */
	protected function _getArrayDump(array! argument, n = 0) -> string | null
	{
		var numberArguments, dump, varDump, k, v;

		let numberArguments = count(argument);

		if n >= 3 || numberArguments == 0 {
			return null;
		}

		if numberArguments >= 10 {
			return numberArguments;
		}

		let dump = [];
		for k, v in argument {

			if is_scalar(v) {
				if v == "" {
					let varDump = "[" . k . "] =&gt; (empty string)";
				} else {
					let varDump = "[" . k . "] =&gt; " . this->_escapeString(v);
				}
				let dump[] = varDump;
				continue;
			}

			if typeof v == "array" {
				let dump[] = "[" . k . "] =&gt; Array(" . this->_getArrayDump(v, n + 1) . ")";
				continue;
			}

			if typeof v == "object" {
				let dump[] = "[" . k . "] =&gt; Object(" . get_class(v) . ")";
				continue;
			}

			if typeof v == "null" {
				let dump[] = "[" . k . "] =&gt; null";
				continue;
			}

			let dump[] = "[" . k . "] =&gt; " . v;
		}

		return join(", ", dump);
	}

	/**
	 * Produces an string representation of a variable
	 */
	protected function _getVarDump(var variable) -> string
	{
		var className, dumpedObject, dump;

		if is_scalar(variable) {

			/**
			 * Boolean variables are represented as "true"/"false"
			 */
			if typeof variable == "boolean" {
				if variable {
					return "true";
				} else {
					return "false";
				}
			}

			/**
			 * String variables are escaped to avoid XSS injections
			 */
			if typeof variable == "string" {
				return this->_escapeString(variable);
			}

			/**
			 * Other scalar variables are just converted to strings
			 */
			return variable;
		}

		/**
		 * If the variable is an object print its class name
		 */
		if typeof variable == "object" {
			let className = get_class(variable);

			/**
			 * Try to check for a "dump" method, this surely produces a better printable representation
			 */
			if method_exists(variable, "dump") {
				let dumpedObject = variable->dump();

				/**
				 * dump() must return an array, generate a recursive representation using getArrayDump
				 */
				let dump = "Object(" . className  . ": " . this->_getArrayDump(dumpedObject) . ")";
			} else {

				/**
				 * If dump() is not available just print the class name
				 */
				let dump = "Object(" . className . ")</span>";
			}
			return dump;
		}

		/**
		 * Recursively process the array and enclose it in []
		 */
		if typeof variable == "array" {
			return "Array(" . this->_getArrayDump(variable) . ")";
		}

		/**
		 * Null variables are represented as "null"
		 */
		if typeof variable == "null" {
			return "null";
		}

		/**
		 * Other types are represented by its type
		 */
		return gettype(variable);
	}

	/**
	 * Returns the major framework's version
	 */
	public function getMajorVersion() -> string
	{
		var parts;

		let parts = explode(" ", \Phalcon\Version::get());
		return parts[0];
	}

	/**
	 * Generates a link to the current version documentation
	 */
	public function getVersion() -> string
	{
		return "<div class=\"version\">Phalcon Framework <a target=\"_new\" href=\"http://docs.phalconphp.com/en/" .
			this->getMajorVersion() . "/\">" .
			\Phalcon\Version::get() . "</a></div>";
	}

	/**
	 * Returns the css sources
	 */
	public function getCssSources() -> string
	{
		var uri, sources;

		let uri = this->_uri;
		let sources  = "<link href=\"" . uri . "jquery/jquery-ui.css\" type=\"text/css\" rel=\"stylesheet\" />";
		let sources .= "<link href=\"" . uri . "themes/default/style.css\" type=\"text/css\" rel=\"stylesheet\" />";
		return sources;
	}

	/**
	 * Returns the javascript sources
	 */
	public function getJsSources() -> string
	{
		var uri, sources;

		let uri = this->_uri;
		let sources  = "<script type=\"text/javascript\" src=\"" . uri . "jquery/jquery.js\"></script>";
		let sources .= "<script type=\"text/javascript\" src=\"" . uri . "jquery/jquery-ui.js\"></script>";
		let sources .= "<script type=\"text/javascript\" src=\"" . uri . "jquery/jquery.scrollTo.js\"></script>";
		let sources .= "<script type=\"text/javascript\" src=\"" . uri . "prettify/prettify.js\"></script>";
		let sources .= "<script type=\"text/javascript\" src=\"" . uri . "pretty.js\"></script>";
		return sources;
	}

	/**
	 * Shows a backtrace item
	 */
	protected final function showTraceItem(int n, array! trace)
	{
		var space, twoSpaces, underscore, minus, className, namespaceSeparator,
			prepareInternalClass, preparedFunctionName, html, classReflection, prepareUriClass,
			functionName, functionReflection, traceArgs, arguments, argument,
			filez, line, showFiles, lines, numberLines, showFileFragment,
			beforeLine, firstLine, afterLine, lastLine, commentPattern, utf8, entCompat, tab,
			comment, i, linePosition, currentLine;

		let space = " ";
		let twoSpaces = "  ";
		let underscore = "_";
		let minus = "-";

		/**
		 * Every trace in the backtrace have a unique number
		 */
		let html = "<tr><td align=\"right\" valign=\"top\" class=\"error-number\">#" . n . "</td><td>";

		if isset trace["class"] {

			let className = trace["class"];

			/**
			 * We assume that classes starting by Phalcon are framework"s classes
			 */
			if preg_match("/^Phalcon/", className) {

				let namespaceSeparator = "\\";

				/**
				 * Prepare the class name according to the Phalcon"s conventions
				 */
				let prepareUriClass = str_replace(namespaceSeparator, underscore, className);

				/**
				 * Generate a link to the official docs
				 */
				let html .= "<span class=\"error-class\"><a target=\"_new\" href=\"http://docs.phalconphp.com/en/latest/api/" . prepareUriClass . ".html\">" . className . "</a></span>";
			} else {

				let classReflection = new \ReflectionClass(className);

				/**
				 * Check if classes are PHP"s classes
				 */
				if classReflection->isInternal() {

					let prepareInternalClass = str_replace(underscore, minus, strtolower(className));

					/**
					 * Generate a link to the official docs
					 */
					let html .= "<span class=\"error-class\"><a target=\"_new\" href=\"http://php.net/manual/en/class." . prepareInternalClass . ".php\">" . className . "</a></span>";
				} else {
					let html .= "<span class=\"error-class\">" . className . "</span>";
				}
			}

			/**
			 * Object access operator: static/instance
			 */
			let html .= trace["type"];
		}

		/**
		 * Normally the backtrace contains only classes
		 */
		let functionName = trace["function"];
		if isset trace["class"] {
			let html .= "<span class=\"error-function\">" . functionName . "</span>";
		} else {

			/**
			 * Check if the function exists
			 */
			if function_exists(functionName) {

				let functionReflection = new \ReflectionFunction(functionName);

				/**
				 * Internal functions links to the PHP documentation
				 */
				if functionReflection->isInternal() {
					/**
					 * Prepare function"s name according to the conventions in the docs
					 */
					let preparedFunctionName = str_replace(underscore, minus, functionName);
					let html .= "<span class=\"error-function\"><a target=\"_new\" href=\"http://php.net/manual/en/function." . preparedFunctionName . ".php\">" . functionName . "</a></span>";
				} else {
					let html .= "<span class=\"error-function\">" . functionName . "</span>";
				}
			} else {
				let html .= "<span class=\"error-function\">" . functionName . "</span>";
			}
		}

		/**
		 * Check for arguments in the function
		 */
		if isset trace["args"] {

			let traceArgs = trace["args"];
			if count(traceArgs) {
				let arguments = [];
				for argument in traceArgs {

					/**
					 * Every argument is generated using _getVarDump
					 * Append the HTML generated to the argument"s list
					 */
					let arguments[] = "<span class=\"error-parameter\">" . this->_getVarDump(argument) . "</span>";
				}

				/**
				 * Join all the arguments
				 */
				let html .= "(" . join(", ", arguments)  . ")";
			} else {
				let html .= "()";
			}
		}

		/**
		 * When "file" is present, it usually means the function is provided by the user
		 */
		if fetch filez, trace["file"] {

			let line = (string) trace["line"];

			/**
			 * Realpath to the file and its line using a special header
			 */
			let html .= "<br/><div class=\"error-file\">" . filez . " (" . line . ")</div>";

			let showFiles = this->_showFiles;

			/**
			 * The developer can change if the files must be opened or not
			 */
			if showFiles {

				/**
				 * Open the file to an array using "file", this respects the openbase-dir directive
				 */
				let lines = file(filez);

				let numberLines = count(lines);
				let showFileFragment = this->_showFileFragment;

				/**
				 * File fragments just show a piece of the file where the exception is located
				 */
				if showFileFragment {

					/**
					 * Take seven lines back to the current exception's line, @TODO add an option for this
					 */
					let beforeLine = line - 7;

					/**
					 * Check for overflows
					 */
					if beforeLine < 1 {
						let firstLine = 1;
					} else {
						let firstLine = beforeLine;
					}

					/**
					 * Take five lines after the current exception's line, @TODO add an option for this
					 */
					let afterLine = line + 5;

					/**
					 * Check for overflows
					 */
					if afterLine > numberLines {
						let lastLine = numberLines;
					} else {
						let lastLine = afterLine;
					}

					let html .= "<pre class=\"prettyprint highlight:" . firstLine . ":" . line . " linenums:" . firstLine . "\">";
				} else {
					let firstLine = 1;
					let lastLine = numberLines;
					let html .= "<pre class=\"prettyprint highlight:" . firstLine . ":" . line . " linenums error-scroll\">";
				}

				let commentPattern = "#\\*\\/#";

				/**
				 * We assume the file is utf-8 encoded, @TODO add an option for this
				 */
				let utf8 = "UTF-8";

				/**
				 * Don't escape quotes
				 */
				let entCompat = ENT_COMPAT;

				let tab = "\t";
				let comment = "* /";

				let i = firstLine;
				while i <= lastLine {

					/**
					 * Current line in the file
					 */
					let linePosition = i - 1;

					/**
					 * Current line content in the piece of file
					 */
					let currentLine = lines[linePosition];

					/**
					 * File fragments are cleaned, removing tabs and comments
					 */
					if showFileFragment {
						if i == firstLine {
							if preg_match(commentPattern, rtrim(currentLine)) {
								let currentLine = str_replace(comment, space, currentLine);
							}
						}
					}

					/**
					 * Print a non break space if the current line is a line break, this allows to show the html zebra properly
					 */
					if currentLine == "\n" {
						let html .= "&nbsp;\n";
					} else {
						if currentLine == "\r\n" {
							let html .= "&nbsp;\n";
						} else {
							let html .= htmlentities(str_replace(tab, twoSpaces, currentLine), entCompat, utf8);
						}
					}

					let i++;
				}
				let html .= "</pre>";
			}
		}

		let html .= "</td></tr>";

		return html;
	}

	/**
	 * Throws an exception when a notice or warning is raised
	 */
	public function onUncaughtLowSeverity(severity, message, file, line)
	{
		if error_reporting() & severity {
			throw new \ErrorException(message, 0, severity, file, line);
		}
	}

	/**
	 * Handles uncaught exceptions
	 */
	public function onUncaughtException(<\Exception> exception) -> boolean
	{
		var obLevel, className, escapedMessage, html, showBackTrace,
		dataVars, n, traceItem, keyRequest, value, keyServer, keyFile, keyVar, dataVar;

		let obLevel = ob_get_level();

		/**
		 * Cancel the output buffer if active
		 */
		if obLevel > 0 {
			ob_end_clean();
		}

		/**
		 * Avoid that multiple exceptions being showed
		 */
		if self::_isActive {
			echo exception->getMessage();
			return;
		}

		/**
		 * Globally block the debug component to avoid other exceptions to be shown
		 */
		let self::_isActive = true;

		let className = get_class(exception);

		/**
		 * Escape the exception's message avoiding possible XSS injections?
		 */
		let escapedMessage = this->_escapeString(exception->getMessage());

		/**
		 * CSS static sources to style the error presentation
		 * Use the exception info as document"s title
		 */
		let html = "<html><head><title>" . className . ": " . escapedMessage . "</title>";
		let html .= this->getCssSources() . "</head><body>";

		/**
		 * Get the version link
		 */
		let html .= this->getVersion();

		/**
		 * Main exception info
		 */
		let html .= "<div align=\"center\"><div class=\"error-main\">";
		let html .= "<h1>" . className . ": " . escapedMessage . "</h1>";
		let html .= "<span class=\"error-file\">" . exception->getFile() . " (" . exception->getLine() . ")</span>";
		let html .= "</div>";

		let showBackTrace = this->_showBackTrace;

		/**
		 * Check if the developer wants to show the backtrace or not
		 */
		if showBackTrace {

			let dataVars = this->_data;

			/**
			 * Create the tabs in the page
			 */
			let html .= "<div class=\"error-info\"><div id=\"tabs\"><ul>";
			let html .= "<li><a href=\"#error-tabs-1\">Backtrace</a></li>";
			let html .= "<li><a href=\"#error-tabs-2\">Request</a></li>";
			let html .= "<li><a href=\"#error-tabs-3\">Server</a></li>";
			let html .= "<li><a href=\"#error-tabs-4\">Included Files</a></li>";
			let html .= "<li><a href=\"#error-tabs-5\">Memory</a></li>";
			if typeof dataVars == "array" {
				let html .= "<li><a href=\"#error-tabs-6\">Variables</a></li>";
			}
			let html .= "</ul>";

			/**
			 * Print backtrace
			 */
			let html .= "<div id=\"error-tabs-1\"><table cellspacing=\"0\" align=\"center\" width=\"100%\">";
			for n, traceItem in exception->getTrace()  {
				/**
				 * Every line in the trace is rendered using "showTraceItem"
				 */
				let html .= this->showTraceItem(n, traceItem);
			}
			let html .= "</table></div>";

			/**
			 * Print _REQUEST superglobal
			 */
			let html .= "<div id=\"error-tabs-2\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">";
			let html .= "<tr><th>Key</th><th>Value</th></tr>";
			for keyRequest, value in _REQUEST {
				if typeof value != "array" {
					let html .= "<tr><td class=\"key\">" . keyRequest . "</td><td>" . value . "</td></tr>";
				} else {
					let html .= "<tr><td class=\"key\">" . keyRequest . "</td><td>" . print_r(value, true) . "</td></tr>";
				}
			}
			let html .= "</table></div>";

			/**
			 * Print _SERVER superglobal
			 */
			let html .= "<div id=\"error-tabs-3\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">";
			let html .= "<tr><th>Key</th><th>Value</th></tr>";
			for keyServer, value in _SERVER {
				let html .= "<tr><td class=\"key\">" . keyServer . "</td><td>" . value . "</td></tr>";
			}
			let html .= "</table></div>";

			/**
			 * Show included files
			 */
			let html .= "<div id=\"error-tabs-4\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">";
			let html .= "<tr><th>#</th><th>Path</th></tr>";
			for keyFile, value in get_included_files() {
				let html .= "<tr><td>" . keyFile . "</th><td>" . value . "</td></tr>";
			}
			let html .= "</table></div>";

			/**
			 * Memory usage
			 */
			let html .= "<div id=\"error-tabs-5\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">";
			let html .= "<tr><th colspan=\"2\">Memory</th></tr><tr><td>Usage</td><td>" . memory_get_usage(true) . "</td></tr>";
			let html .= "</table></div>";

			/**
			 * Print extra variables passed to the component
			 */
			if typeof  dataVars == "array" {
				let html .= "<div id=\"error-tabs-6\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">";
				let html .= "<tr><th>Key</th><th>Value</th></tr>";
				for keyVar, dataVar in dataVars {
					let html .= "<tr><td class=\"key\">" . keyVar . "</td><td>" . this->_getVarDump(dataVar[0]) . "</td></tr>";
				}
				let html .= "</table></div>";
			}

			let html .= "</div>";
		}

		/**
		 * Get Javascript sources
		 */
		let html .=  this->getJsSources() . "</div></body></html>";

		/**
		 * Print the HTML, @TODO, add an option to store the html
		 */
		echo html;

		/**
		 * Unlock the exception renderer
		 */
		let self::_isActive = false;

		return true;
	}
}
