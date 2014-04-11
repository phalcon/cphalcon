
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

namespace Phalcon;

/**
 * Phalcon\Debug
 *
 * Provides debug capabilities to Phalcon applications
 */
class Debug
{
	public _uri = "http://static.phalconphp.com/debug/1.2.0/";

	public _theme = "default";

	protected _hideDocumentRoot = false;

	protected _showBackTrace = true;

	protected _showFiles = true;

	protected _showFileFragment = false;

	protected _data;

	protected static _isActive;

	/**
	 * Change the base URI for static resources
	 *
	 * @param string uri
	 * @return Phalcon\Debug
	 */
	public function setUri(uri)
	{
		let this->_uri = uri;
		return this;
	}

	/**
	 * Sets if files the exception"s backtrace must be showed
	 *
	 * @param boolean showBackTrace
	 * @return Phalcon\Debug
	 */
	public function setShowBackTrace(showBackTrace)
	{
		let this->_showBackTrace = showBackTrace;
		return this;
	}

	/**
	 * Set if files part of the backtrace must be shown in the output
	 *
	 * @param boolean showFiles
	 * @return Phalcon\Debug
	 */
	public function setShowFiles(showFiles)
	{
		let this->_showFiles = showFiles;
		return this;
	}

	/**
	 * Sets if files must be completely opened and showed in the output
	 * or just the fragment related to the exception
	 *
	 * @param boolean showFileFragment
	 * @return Phalcon\Debug
	 */
	public function setShowFileFragment(showFileFragment)
	{
		let this->_showFileFragment = showFileFragment;
		return this;
	}

	/**
	 * Listen for uncaught exceptions and unsilent notices or warnings
	 *
	 * @param boolean exceptions
	 * @param boolean lowSeverity
	 * @return Phalcon\Debug
	 */
	public function listen(exceptions=true, lowSeverity=false)
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
	 *
	 * @return Phalcon\Debug
	 */
	public function listenExceptions()
	{
	    set_exception_handler([this, "onUncaughtException"]);
		return this;
	}

	/**
	 * Listen for unsilent notices or warnings
	 *
	 * @return Phalcon\Debug
	 */
	public function listenLowSeverity()
	{
		set_exception_handler([this, "onUncaughtLowSeverity"]);
		return this;
	}

	/**
	 * Adds a variable to the debug output
	 *
	 * @param mixed var
	 * @param string key
	 * @return Phalcon\Debug
	 */
	public function debugVar(varz, key=null)
	{
		let this->_data[] = [varz, debug_backtrace(), time()];
		return this;
	}

	/**
	 * Clears are variables added previously
	 *
	 * @return Phalcon\Debug
	 */
	public function clearVars()
	{
		let this->_data = null;
		return this;
	}

	/**
	 * Escapes a string with htmlentities
	 *
	 * @param string value
	 * @return string
	 */
	protected function _escapeString(value)
	{
	    var replacedValue;
		if typeof value == "string" {
			let replacedValue = str_replace("\n", "\\n", value);
			return htmlentities(replacedValue, ENT_COMPAT, "utf-8");
		}
		return value;
	}

	/**
	 * Produces a recursive representation of an array
	 *
	 * @param array argument
	 * @return string
	 */
	protected function _getArrayDump(argument, n = 0)
	{
	    var numberArguments, one, dump, varDump, escapedString, next, arrayDump, k, v, arguments, className, joinedDump;

		let numberArguments = count(argument);
		if n < 3 {
			if numberArguments > 0 {
				if numberArguments < 10 {
					let one = 1;
					let dump = [];
					for  k,v in argument {
						if is_scalar(v) {
							if v == "" {
								let varDump = "[". k . "] =&gt; (empty string)";
							} else {
								let escapedString = this->_escapeString(v);
								let varDump = "[" . k . "] =&gt; " . escapedString;
							}
							let dump[] = varDump;
						} else {

							if typeof v == "array" {
								let next = n + one;
								let arrayDump = this->_getArrayDump(v, next);
								let varDump = "[" . k . "] =&gt; Array(" . arrayDump . ")";
								let dump[] = varDump;
								continue;
							}

							if typeof v == "object" {
								let className = get_class(v);
								let varDump = "[" . k . "] =&gt; Object(" . className . ")";
								let dump[] = varDump;
								continue;
							}

							if typeof v == "null" {
								let varDump = "[" . k . "] =&gt; null";
								let dump[] = varDump;
								continue;
							}

							let varDump = "[" . k . "] =&gt; ".v;
							let dump[] = varDump;
						}
					}
					let joinedDump = join(", ", dump);
					return joinedDump;
				}
				return numberArguments;
			}
		}
		return null;
	}

	/**
	 * Produces an string representation of a variable
	 *
	 * @param mixed variable
	 * @return string
	 */
	protected function _getVarDump(variable)
	{
	    var className, dumpedObject, dump, arrayDump;

		if is_scalar(variable) {

			/**
			 * Boolean variables are represented as "true"/"false"
			 */
			if typeof variable == "bool" {
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
				let arrayDump = this->_getArrayDump(dumpedObject);
				let dump = "Object(" . className  . ": " . arrayDump . ")";
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
			let arrayDump = this->_getArrayDump(variable);
			return "Array(" . arrayDump . ")";
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
	 * Returns the major framework"s version
	 *
	 * @return string
	 */
	public function getMajorVersion()
	{
	    var parts;

		let parts = explode(" ", \Phalcon\Version::get());
		return parts[0];
	}

	/**
	 * Generates a link to the current version documentation
	 *
	 * @return string
	 */
	public function getVersion()
	{
		return "<div class=\"version\">Phalcon Framework <a target=\"_new\" href=\"http://docs.phalconphp.com/en/" .  this->getMajorVersion() . "/\">" . \Phalcon\Version::get() . "</a></div>";
	}

	/**
	 * Returns the css sources
	 *
	 * @return string
	 */
	public function getCssSources()
	{
	    var uri, sources;

		let uri = this->_uri;
		let sources  = "<link href=\"".uri."jquery/jquery-ui.css\" type=\"text/css\" rel=\"stylesheet\" />";
		let sources .= "<link href=\"".uri."themes/default/style.css\" type=\"text/css\" rel=\"stylesheet\" />";
		return sources;
	}

	/**
	 * Returns the javascript sources
	 *
	 * @return string
	 */
	public function getJsSources()
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
	 *
	 * @param int n
	 * @param array trace
	 */
	protected function showTraceItem(n, trace)
	{

        var space, twoSpaces, underscore, minus, isPhalconClass, className, pattern, namespaceSeparator,
        prepareInternalClass, preparedFunctionName, html, classReflection, prepareUriClass, isInternal,
        lowerClassName, type, functionName, functionReflection, traceArgs, arguments, argument, dumpedArgument,
        spanArgument, joinedArguments, one, filez, line, showFiles, lines, numberLines, showFileFragment, seven,
        beforeLine, firstLine, afterLine, lastLine, commentPattern, utf8, entCompat, tab, comment, i, linePosition,
        currentLine, trimmed, isComment, spacedCurrentLine, escapedLine;

		let space = " ";
		let twoSpaces = "  ";
		let underscore = "_";
		let minus = "-";

        /**
		 * Every trace in the backtrace have a unique number
		 */
		let html = "<tr><td align=\"right\" valign=\"top\" class=\"error-number\">#".n."</td><td>";

		if isset trace["class"] {

			let className = trace["class"];

			let pattern = "/^Phalcon/";

			let isPhalconClass = preg_match(pattern, className);

			/**
			 * We assume that classes starting by Phalcon are framework"s classes
			 */
			if isPhalconClass {

				let namespaceSeparator = "\\";

				/**
				 * Prepare the class name according to the Phalcon"s conventions
				 */
				let prepareUriClass = str_replace(namespaceSeparator, underscore, className);

				/**
				 * Generate a link to the official docs
				 */
				let html .= "<span class=\"error-class\"><a target=\"_new\" href=\"http://docs.phalconphp.com/en/latest/api/".prepareUriClass.".html\">".className."</a></span>";
			} else {

				let classReflection = new \ReflectionClass(className);

				/**
				 * Check if classes are PHP"s classes
				 */
				let isInternal = classReflection->isInternal();
				if isInternal {
					let lowerClassName = strtolower(className);
					let prepareInternalClass = str_replace(underscore, minus, lowerClassName);

					/**
					 * Generate a link to the official docs
					 */
					let html .= "<span class=\"error-class\"><a target=\"_new\" href=\"http://php.net/manual/en/class.".prepareInternalClass.".php\">".className."</a></span>";
				} else {
					let html .= "<span class=\"error-class\">".className."</span>";
				}
			}

			/**
			 * Object access operator: static/instance
			 */
			let type = trace["type"];
			let html .= type;
		}

		/**
		 * Normally the backtrace contains only classes
		 */
		if isset trace["class"] {
			let functionName = trace["function"];
			let html .= "<span class=\"error-function\">".functionName."</span>";
		} else {

			let functionName = trace["function"];

			/**
			 * Check if the function exists
			 */
			if function_exists(functionName) {

				let functionReflection = new \ReflectionFunction(functionName);

				let isInternal = functionReflection->isInternal();

				/**
				 * Internal functions links to the PHP documentation
				 */
				if isInternal {
					/**
					 * Prepare function"s name according to the conventions in the docs
					 */
					let preparedFunctionName = str_replace(underscore, minus, functionName);
					let html .= "<span class=\"error-function\"><a target=\"_new\" href=\"http://php.net/manual/en/function.".preparedFunctionName.".php\">".functionName."</a></span>";
				} else {
					let html .= "<span class=\"error-function\">".functionName."</span>";
				}
			} else {
				let html .= "<span class=\"error-function\">".functionName."</span>";
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
					 */
					let dumpedArgument = this->_getVarDump(argument);
					let spanArgument = "<span class=\"error-parameter\">".dumpedArgument."</span>";

					/**
					 * Append the HTML generated to the argument"s list
					 */
					let arguments[] = spanArgument;
				}

				/**
				 * Join all the arguments
				 */
				let joinedArguments = join(", ", arguments);

				let html .= "(" . joinedArguments  . ")";
			} else {
				let html .= "()";
			}
		}

		/**
		 * When "file" is present, it usually means the function is provided by the user
		 */
		if isset trace["file"] {

			let one = 1;

			let filez = trace["file"];
			let line = trace["line"];

			/**
			 * Realpath to the file and its line using a special header
			 */
			let html .= "<br/><div class=\"error-file\">".filez." (".line.")</div>";

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
					 * Take seven lines back to the current exception"s line, @TODO add an option for this
					 */
					let seven = 7;

					let beforeLine = line - seven;

					/**
					 * Check for overflows
					 */
					if beforeLine < 1 {
						let firstLine = one;
					} else {
						let firstLine = beforeLine;
					}

					/**
					 * Take five lines after the current exception"s line, @TODO add an option for this
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
					let firstLine = one;
					let lastLine = numberLines;
					let html .= "<pre class=\"prettyprint highlight:" . firstLine . ":" . line . " linenums error-scroll\">";
				}

				let commentPattern = "#\\*\\/#";

				/**
				 * We assume the file is utf-8 encoded, @TODO add an option for this
				 */
				let utf8 = "UTF-8";

				/**
				 * Don"t escape quotes
				 */
				let entCompat = ENT_COMPAT;

				let tab = "\t";
				let comment = "* /";

				let i = firstLine;
				while i <= lastLine {

					/**
					 * Current line in the file
					 */
					let linePosition = i - one;

					/**
					 * Current line content in the piece of file
					 */
					let currentLine = lines[linePosition];

					/**
					 * File fragments are cleaned, removing tabs and comments
					 */
					if showFileFragment {
						if i == firstLine {
							let trimmed = rtrim(currentLine);
							let isComment = preg_match(commentPattern, currentLine);
							if isComment {
								let spacedCurrentLine = str_replace(comment, space, currentLine);
								let currentLine = spacedCurrentLine;
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
							let spacedCurrentLine = str_replace(tab, twoSpaces, currentLine);
							let escapedLine = htmlentities(spacedCurrentLine, entCompat, utf8);
							let html .= escapedLine;
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
	 * Handles uncaught exceptions
	 *
	 * @param \Exception exception
	 * @return boolean
	 */
	public function onUncaughtException(exception)
	{
        var obLevel, isActive, message, className, cssSources, escapedMessage, html, version, file, line, showBackTrace,
        dataVars, trace, n, traceItem, htmlItem, keyRequest, value, keyServer, files, keyFile, trueUsage, memory, keyVar,
         dataVar, variable, dumpedArgument, jsSources;

		let obLevel = ob_get_level();

		/**
		 * Cancel the output buffer if active
		 */
		if obLevel > 0 {
			ob_end_clean();
		}

		let isActive = self::_isActive;

		/**
		 * Avoid that multiple exceptions being showed
		 */
		if isActive {
			let message = exception->getMessage();
			echo message;
			return;
		}

		let isActive = true;

		/**
		 * Globally block the debug component to avoid other exceptions must be shown
		 */
		let self::_isActive = isActive;

		let className = get_class(exception);

		let message = exception->getMessage();

		/**
		 * CSS static sources to style the error presentation
		 */
		let cssSources = this->getCssSources();

		/**
		 * Escape the exception"s message avoiding possible XSS injections?
		 */
		let escapedMessage = message;

		/**
		 * Use the exception info as document"s title
		 */
		let html = "<html><head><title>".className.": ".escapedMessage."</title>";
		let html .= cssSources."</head><body>";

		/**
		 * Get the version link
		 */
		let version = this->getVersion();
		let html .= version;

		let file = exception->getFile();
		let line = exception->getLine();

		/**
		 * Main exception info
		 */
		let html .= "<div align=\"center\"><div class=\"error-main\">";
		let html .= "<h1>".className.": ".escapedMessage."</h1>";
		let html .= "<span class=\"error-file\">".file." (".line.")</span>";
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
			if typeof  dataVars == "array" {
				let html .= "<li><a href=\"#error-tabs-6\">Variables</a></li>";
			}
			let html .= "</ul>";

			/**
			 * Print backtrace
			 */
			let html .= "<div id=\"error-tabs-1\"><table cellspacing=\"0\" align=\"center\" width=\"100%\">";
			let trace = exception->getTrace();
			for n,traceItem in trace  {

				/**
				 * Every line in the trace is rendered using "showTraceItem"
				 */
				let htmlItem = this->showTraceItem(n, traceItem);

				let html .= htmlItem;
			}
			let html .= "</table></div>";

			/**
			 * Print _REQUEST superglobal
			 */
			let html .= "<div id=\"error-tabs-2\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">";
			let html .= "<tr><th>Key</th><th>Value</th></tr>";
			for keyRequest,value in _REQUEST {
				let html .= "<tr><td class=\"key\">".keyRequest."</td><td>".value."</td></tr>";
			}
			let html .= "</table></div>";

			/**
			 * Print _SERVER superglobal
			 */
			let html .= "<div id=\"error-tabs-3\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">";
			let html .= "<tr><th>Key</th><th>Value</th></tr>";
			for keyServer,value in _SERVER {
				let html .= "<tr><td class=\"key\">".keyServer."</td><td>".value."</td></tr>";
			}
			let html .= "</table></div>";

			/**
			 * Show included files
			 */
			let files = get_included_files();

			let html .= "<div id=\"error-tabs-4\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">";
			let html .= "<tr><th>#</th><th>Path</th></tr>";
			for keyFile,value in files {
				let html .= "<tr><td>".keyFile."</th><td>".value."</td></tr>";
			}
			let html .= "</table></div>";

			/**
			 * Memory usage
			 */
			let trueUsage = true;
			let memory = memory_get_usage(trueUsage);

			let html .= "<div id=\"error-tabs-5\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">";
			let html .= "<tr><th colspan=\"2\">Memory</th></tr><tr><td>Usage</td><td>".memory."</td></tr>";
			let html .= "</table></div>";

			/**
			 * Print extra variables passed to the component
			 */
			if typeof  dataVars == "array" {
				let html .= "<div id=\"error-tabs-6\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">";
				let html .= "<tr><th>Key</th><th>Value</th></tr>";
				for keyVar,dataVar in dataVars {
					let variable = dataVar[0];
					let dumpedArgument = this->_getVarDump(variable);
					let html .= "<tr><td class=\"key\">".keyVar."</td><td>".dumpedArgument."</td></tr>";
				}
				let html .= "</table></div>";
			}

			let html .= "</div>";
		}

		/**
		 * Get Javascript sources
		 */
		let jsSources = this->getJsSources();
		let html .=  jsSources . "</div></body></html>";

		/**
		 * Print the HTML, @TODO, add an option to store the html
		 */
		echo html;

		let isActive = false;

		/**
		 * Unlock the exception renderer
		 */
		let self::_isActive = isActive;

		return true;
	}

}
