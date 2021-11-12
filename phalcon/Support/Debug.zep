
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Support;

use ErrorException;
use ReflectionClass;
use ReflectionFunction;
use Phalcon\Html\TagFactory;
use Phalcon\Support\Debug\Exception;

/**
 * Provides debug capabilities to Phalcon applications
 */
class Debug
{
    /**
     * @var array
     */
    protected blacklist = ["request" : [], "server" : []];

    /**
     * @var array
     */
    protected data = [];

    /**
     * @var bool
     */
    protected hideDocumentRoot = false;

    /**
     * @var bool
     */
    protected static isActive = false;

    /**
     * @var bool
     */
    protected showBackTrace = true;

    /**
     * @var bool
     */
    protected showFileFragment = false;

    /**
     * @var bool
     */
    protected showFiles = true;

    /**
     * @var TagFactory
     */
    protected tagFactory;

    /**
     * @var string
    */
    protected uri = "https://assets.phalcon.io/debug/5.0.x/";

    /**
     * Constructor
     *
     * @param TagFactory $tagFactory
     */
    public function __construct(<TagFactory> tagFactory)
    {
        let this->tagFactory = tagFactory;
    }

    /**
     * Clears are variables added previously
     */
    public function clearVars() -> <Debug>
    {
        let this->data = [];

        return this;
    }

    /**
     * Adds a variable to the debug output
     */
    public function debugVar(varz, string key = null) -> <Debug>
    {
        let this->data[] = [
            varz,
            debug_backtrace(),
            time()
        ];

        return this;
    }

    /**
     * Returns the CSS sources
     */
    public function getCssSources() -> string
    {
        var uri, sources;

        let uri = this->uri;

        let sources  = "<link rel=\"stylesheet\" type=\"text/css\" href=\""
                     . uri . "assets/jquery-ui/themes/ui-lightness/jquery-ui.min.css\" />"
                     . "<link rel=\"stylesheet\" type=\"text/css\" href=\""
                     . uri . "assets/jquery-ui/themes/ui-lightness/theme.css\" />"
                     . "<link rel=\"stylesheet\" type=\"text/css\" href=\""
                     . uri . "themes/default/style.css\" />";

        return sources;
    }

    /**
     * Returns the JavaScript sources
     */
    public function getJsSources() -> string
    {
        var uri, sources;

        let uri = this->uri;

        let sources  = "<script type=\"text/javascript\" src=\""
                     . uri . "assets/jquery/dist/jquery.min.js\"></script>"
                     . "<script type=\"text/javascript\" src=\""
                     . uri . "assets/jquery-ui/jquery-ui.min.js\"></script>"
                     . "<script type=\"text/javascript\" src=\""
                     . uri . "assets/jquery.scrollTo/jquery.scrollTo.min.js\"></script>"
                     . "<script type=\"text/javascript\" src=\""
                     . uri . "prettify/prettify.js\"></script>"
                     . "<script type=\"text/javascript\" src=\""
                     . uri . "pretty.js\"></script>";

        return sources;
    }

    /**
     * Generates a link to the current version documentation
     */
    public function getVersion() -> string
    {
        var link, version;

        let version = new Version(),
            link    = this->tagFactory->a(
                "https://docs.phalcon.io/"
                    . version->getPart(Version::VERSION_MAJOR)
                    . "."
                    . version->getPart(Version::VERSION_MEDIUM)
                    . "/en/",
                version->get(),
                [
                    "target": "_new"
                ]
            );

        return "<div class=\"version\">Phalcon Framework " . link . "</div>";
    }

    /**
     * Halts the request showing a backtrace
     */
    public function halt() -> void
    {
        throw new Exception("Halted request");
    }

    /**
     * Listen for uncaught exceptions and unsilent notices or warnings
     */
    public function listen(bool exceptions = true, bool lowSeverity = false) -> <Debug>
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
        set_exception_handler(
            [this, "onUncaughtException"]
        );

        return this;
    }

    /**
     * Listen for unsilent notices or warnings
     */
    public function listenLowSeverity() -> <Debug>
    {
        set_error_handler(
            [this, "onUncaughtLowSeverity"]
        );

        set_exception_handler(
            [this, "onUncaughtException"]
        );

        return this;
    }

    /**
     * Handles uncaught exceptions
     */
    public function onUncaughtException(<\Throwable> exception) -> bool
    {
        var obLevel;

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
        if self::isActive {
            echo exception->getMessage();

            return;
        }

        /**
         * Globally block the debug component to avoid other exceptions to be shown
         */
        let self::isActive = true;

        /**
         * Print the HTML, @TODO, add an option to store the HTML
         */
        echo this->renderHtml(exception);

        /**
         * Unlock the exception renderer
         */
        let self::isActive = false;

        return true;
    }

    /**
     * Throws an exception when a notice or warning is raised
     */
    public function onUncaughtLowSeverity(severity, message, file, line, context) -> void
    {
        if unlikely error_reporting() & severity {
            throw new ErrorException(message, 0, severity, file, line);
        }
    }

    /*
     * Render exception to html format.
     */
    public function renderHtml(<\Throwable> exception) -> string
    {
        var blacklist, className, dataVar, dataVars, escapedMessage, html,
            keyFile, keyRequest, keyServer, keyVar, n, showBackTrace, traceItem,
            value;

         let className = get_class(exception);

        /**
         * Escape the exceptions message avoiding possible XSS injections?
         */
        let escapedMessage = this->escapeString(
            exception->getMessage()
        );

        /**
         * CSS static sources to style the error presentation
         * Use the exception info as document title
         */
        let html = "<html><head>"
                 . "<title>" . className . ": " . escapedMessage . "</title>"
                 . this->getCssSources()
                 . "</head><body>";

        /**
         * Get the version link
         */
        let html .= this->getVersion();

        /**
         * Main exception info
         */
        let html .= "<div align=\"center\">"
                  . "<div class=\"error-main\">"
                  . "<h1>" . className . ": " . escapedMessage . "</h1>"
                  . "<span class=\"error-file\">" . exception->getFile() . " (" . exception->getLine() . ")</span>"
                  . "</div>";

         let showBackTrace = this->showBackTrace;

        /**
         * Check if the developer wants to show the backtrace or not
         */
        if showBackTrace {
            let dataVars = this->data;

            /**
             * Create the tabs in the page
             */
            let html .= "<div class=\"error-info\"><div id=\"tabs\"><ul>"
                      . "<li><a href=\"#error-tabs-1\">Backtrace</a></li>"
                      . "<li><a href=\"#error-tabs-2\">Request</a></li>"
                      . "<li><a href=\"#error-tabs-3\">Server</a></li>"
                      . "<li><a href=\"#error-tabs-4\">Included Files</a></li>"
                      . "<li><a href=\"#error-tabs-5\">Memory</a></li>";

             if !empty dataVars {
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
            let html .= "<div id=\"error-tabs-2\">"
                      . "<table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">"
                      . "<tr><th>Key</th><th>Value</th></tr>";
            let blacklist = this->getArrVal(this->blacklist, "request", []);

             for keyRequest, value in _REQUEST {
                if true !== isset(blacklist[strtolower(keyRequest)]) {
                    if typeof value != "array" {
                        let html .= "<tr><td class=\"key\">" . keyRequest . "</td><td>" . value . "</td></tr>";
                    } else {
                        let html .= "<tr><td class=\"key\">" . keyRequest . "</td><td>" . print_r(value, true) . "</td></tr>";
                    }
                }
            }

             let html .= "</table></div>";

            /**
             * Print _SERVER superglobal
             */
            let html .= "<div id=\"error-tabs-3\">"
                      . "<table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">"
                      . "<tr><th>Key</th><th>Value</th></tr>";
            let blacklist = this->getArrVal(this->blacklist, "server", []);

             for keyServer, value in _SERVER {
                if true !== isset(blacklist[strtolower(keyServer)]) {
                    let html .= "<tr><td class=\"key\">" . keyServer . "</td><td>" . this->getVarDump(value) . "</td></tr>";
                }
            }

             let html .= "</table></div>";

            /**
             * Show included files
             */
            let html .= "<div id=\"error-tabs-4\">"
                      . "<table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">"
                      . "<tr><th>#</th><th>Path</th></tr>";

             for keyFile, value in get_included_files() {
                let html .= "<tr><td>" . keyFile . "</th><td>" . value . "</td></tr>";
            }

             let html .= "</table></div>";

            /**
             * Memory usage
             */
            let html .= "<div id=\"error-tabs-5\">"
                      . "<table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">"
                      . "<tr><th colspan=\"2\">Memory</th></tr><tr><td>Usage</td><td>" . memory_get_usage(true) . "</td></tr>"
                      . "</table></div>";

            /**
             * Print extra variables passed to the component
             */
            if !empty dataVars {
                let html .= "<div id=\"error-tabs-6\">"
                          . "<table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">"
                          . "<tr><th>Key</th><th>Value</th></tr>";

                 for keyVar, dataVar in dataVars {
                    let html .= "<tr><td class=\"key\">" . keyVar . "</td><td>" . this->getVarDump(dataVar[0]) . "</td></tr>";
                }

                 let html .= "</table></div>";
            }

             let html .= "</div>";
        }

        /**
         * Get JavaScript sources
         */
        let html .= this->getJsSources() . "</div></body></html>";

        return html;
    }

    /**
     * Sets if files the exception\"s backtrace must be showed
     */
    public function setBlacklist(array blacklist) -> <Debug>
    {
        var area, result, subArray, value;

        let area     = this->getArrVal(blacklist, "request", []),
            subArray = [],
            result   = [];

        for value in area {
            let value           = strtolower(value),
                subArray[value] = 1;
        }

        let result["request"] = subArray,
            area              = this->getArrVal(blacklist, "server", []),
            subArray          = [];

        for value in area {
            let value           = strtolower(value),
                subArray[value] = 1;
        }

        let result["server"] = subArray,
            this->blacklist = result;

        return this;
    }

    /**
     * Sets if files the exception\"s backtrace must be showed
     */
    public function setShowBackTrace(bool showBackTrace) -> <Debug>
    {
        let this->showBackTrace = showBackTrace;

        return this;
    }

    /**
     * Sets if files must be completely opened and showed in the output
     * or just the fragment related to the exception
     */
    public function setShowFileFragment(bool showFileFragment) -> <Debug>
    {
        let this->showFileFragment = showFileFragment;

        return this;
    }

    /**
     * Set if files part of the backtrace must be shown in the output
     */
    public function setShowFiles(bool showFiles) -> <Debug>
    {
        let this->showFiles = showFiles;

        return this;
    }

    /**
     * Change the base URI for static resources
     */
    public function setUri(string! uri) -> <Debug>
    {
        let this->uri = uri;

        return this;
    }

    /**
     * Escapes a string with htmlentities
     */
    protected function escapeString(var value) -> string
    {
        if typeof value == "string" {
            return htmlentities(
                str_replace("\n", "\\n", value),
                ENT_COMPAT,
                "utf-8"
            );
        }

        return value;
    }

    /**
     * Produces a recursive representation of an array
     */
    protected function getArrayDump(array! argument, n = 0) -> string | null
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
            if v == "" {
                let varDump = "(empty string)";
            } elseif is_scalar(v) {
                let varDump = this->escapeString(v);
            } elseif typeof v == "array" {
                let varDump = "Array(" . this->getArrayDump(v, n + 1) . ")";
            } elseif typeof v == "object" {
                let varDump = "Object(" . get_class(v) . ")";
            } elseif v === null {
                let varDump = "null";
            } else {
                let varDump = v;
            }

            let dump[] = "[" . k . "] =&gt; " . varDump;
        }

        return join(", ", dump);
    }

    /**
     * Produces an string representation of a variable
     */
    protected function getVarDump(var variable) -> string
    {
        var className, dumpedObject;

        if variable === true {
            return "true";
        }

        if variable === false {
            return "false";
        }

        /**
         * String variables are escaped to avoid XSS injections
         */
        if typeof variable == "string" {
            return this->escapeString(variable);
        }

        /**
         * Scalar variables are just converted to strings
         */
        if is_scalar(variable) {
            return variable;
        }

        /**
         * If the variable is an object print its class name
         */
        if typeof variable == "object" {
            let className = get_class(variable);

            /**
             * Try to check for a "dump" method, this surely produces a better
             * printable representation
             */
            if method_exists(variable, "dump") {
                let dumpedObject = variable->dump();

                /**
                 * dump() must return an array, generate a recursive
                 * representation using `getArrayDump()`
                 */
                return "Object(" . className  . ": " . this->getArrayDump(dumpedObject) . ")";
            } else {

                /**
                 * If dump() is not available just print the class name
                 */
                return "Object(" . className . ")";
            }
        }

        /**
         * Recursively process the array and enclose it in []
         */
        if typeof variable == "array" {
            return "Array(" . this->getArrayDump(variable) . ")";
        }

        /**
         * Null variables are represented as "null"
         */
        if variable === null {
            return "null";
        }

        /**
         * Other types are represented by its type
         */
        return gettype(variable);
    }

    /**
     * Shows a backtrace item
     */
    final protected function showTraceItem(int n, array! trace) -> string
    {
        var className, prepareInternalClass, preparedFunctionName, html,
            classReflection, prepareUriClass, functionName, functionReflection,
            traceArgs, arguments, argument, filez, line, showFiles, lines,
            numberLines, showFileFragment, firstLine, lastLine, i, linePosition,
            currentLine, classNameWithLink, functionNameWithLink, parts;

        /**
         * Every trace in the backtrace have a unique number
         */
        let html = "<tr><td align=\"right\" valign=\"top\" class=\"error-number\">#" . n . "</td><td>";

        if fetch className, trace["class"] {
            /**
             * We assume that classes starting by Phalcon are framework
             * classes
             */
            if preg_match("/^Phalcon/", className) {
                /**
                 * Prepare the class name according to the Phalcon conventions
                 */
                let parts = explode("\\", className);
                let prepareUriClass = parts[0] . "_" . parts[1];

                /**
                 * Generate a link to the official docs
                 */
                let classNameWithLink = "<a target=\"_new\" href=\"https://docs.phalcon.io/4.0/en/api/" . prepareUriClass . "\">" . className . "</a>";
            } else {
                let classReflection = new ReflectionClass(className);

                /**
                 * Check if classes are PHP classes
                 */
                if classReflection->isInternal() {
                    let prepareInternalClass = str_replace(
                        "_",
                        "-",
                        strtolower(className)
                    );

                    /**
                     * Generate a link to the official docs
                     */
                    let classNameWithLink = "<a target=\"_new\" href=\"https://secure.php.net/manual/en/class." . prepareInternalClass . ".php\">" . className . "</a>";
                } else {
                    let classNameWithLink = className;
                }
            }

            let html .= "<span class=\"error-class\">" . classNameWithLink . "</span>";

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
            let functionNameWithLink = functionName;
        } else {
            /**
             * Check if the function exists
             */
            if function_exists(functionName) {
                let functionReflection = new ReflectionFunction(functionName);

                /**
                 * Internal functions links to the PHP documentation
                 */
                if functionReflection->isInternal() {
                    /**
                     * Prepare the function name according to the
                     * conventions in the docs
                     */
                    let preparedFunctionName = str_replace(
                        "_",
                        "-",
                        functionName
                    );

                    let functionNameWithLink = "<a target=\"_new\" href=\"https://secure.php.net/manual/en/function." . preparedFunctionName . ".php\">" . functionName . "</a>";
                } else {
                    let functionNameWithLink = functionName;
                }
            } else {
                let functionNameWithLink = functionName;
            }
        }

        let html .= "<span class=\"error-function\">" . functionNameWithLink . "</span>";

        /**
         * Check for arguments in the function
         */
        if fetch traceArgs, trace["args"] {
            let arguments = [];

            for argument in traceArgs {
                /**
                 * Every argument is generated using getVarDump
                 * Append the HTML generated to the argument list
                 */
                let arguments[] = "<span class=\"error-parameter\">" . this->getVarDump(argument) . "</span>";
            }

            /**
             * Join all the arguments
             */
            let html .= "(" . join(", ", arguments)  . ")";
        }

        /**
         * When "file" is present, it usually means the function is provided by
         * the user
         */
        if fetch filez, trace["file"] {
            let line = (string) trace["line"];

            /**
             * Realpath to the file and its line using a special header
             */
            let html .= "<br/><div class=\"error-file\">" . filez . " (" . line . ")</div>";

            let showFiles = this->showFiles;

            /**
             * The developer can change if the files must be opened or not
             */
            if showFiles {
                /**
                 * Open the file to an array using "file", this respects the
                 * openbase-dir directive
                 */
                let lines = file(filez);

                let numberLines = count(lines);
                let showFileFragment = this->showFileFragment;

                /**
                 * File fragments just show a piece of the file where the
                 * exception is located
                 */
                if showFileFragment {
                    /**
                     * Take seven lines back to the current exception line, @TODO add an option for this
                     */
                    int beforeLine = line - 7;

                    /**
                     * Check for overflows
                     */
                    if beforeLine < 1 {
                        let firstLine = 1;
                    } else {
                        let firstLine = beforeLine;
                    }

                    /**
                     * Take five lines after the current exception line, @TODO add an option for this
                     */
                    int afterLine = line + 5;

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
                            if preg_match("#\\*\\/#", rtrim(currentLine)) {
                                let currentLine = str_replace(
                                    "* /",
                                    " ",
                                    currentLine
                                );
                            }
                        }
                    }

                    /**
                     * Print a non break space if the current line is a line
                     * break, this allows to show the HTML zebra properly
                     */
                    if currentLine == "\n" || currentLine == "\r\n" {
                        let html .= "&nbsp;\n";
                    } else {
                        /**
                         * Do not escape quotes
                         * We assume the file is utf-8 encoded, @TODO add an option for this
                         */
                        let html .= htmlentities(
                            str_replace("\t", "  ", currentLine),
                            ENT_COMPAT,
                            "UTF-8"
                        );
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
     * @todo Remove this when we get traits
     */
    private function getArrVal(
        array! collection,
        var index,
        var defaultValue = null
    ) -> var {
        var value;

        if unlikely !fetch value, collection[index] {
            return defaultValue;
        }

        return value;
    }
}
