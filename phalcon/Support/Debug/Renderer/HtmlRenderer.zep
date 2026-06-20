
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Debug\Renderer;

use Phalcon\Contracts\Support\Debug\Renderer;
use Phalcon\Support\Debug\Report\BacktraceItem;
use Phalcon\Support\Debug\Report\ExceptionReport;
use Phalcon\Support\Version;

/**
 * Renders an ExceptionReport as the HTML debug page using embedded, overridable
 * template strings filled by strtr.
 */
class HtmlRenderer implements Renderer
{
    /**
     * Template overrides keyed by name.
     *
     * @todo Move getTemplate()/setTemplate()/templates into a shared trait once
     *       Zephir supports traits (mirrors
     *       Phalcon\Support\Debug\Traits\TemplateAwareTrait in the PHP source).
     *
     * @var array
     */
    protected templates = [];

    /**
     * @param string $uri
     *
     * @return string
     */
    public function getCssSources(string uri) -> string
    {
        var template, paths, path, output;

        let template = this->getTemplate("cssLink");
        let paths    = [
            "assets/jquery-ui/themes/ui-lightness/jquery-ui.min.css",
            "assets/jquery-ui/themes/ui-lightness/theme.css",
            "themes/default/style.css"
        ];

        let output = "";

        for path in paths {
            let output .= strtr(template, ["%uri%": uri, "%path%": path]);
        }

        return output;
    }

    /**
     * @param string $uri
     *
     * @return string
     */
    public function getJsSources(string uri) -> string
    {
        var template, paths, path, output;

        let template = this->getTemplate("jsLink");
        let paths    = [
            "assets/jquery/dist/jquery.min.js",
            "assets/jquery-ui/jquery-ui.min.js",
            "assets/jquery.scrollTo/jquery.scrollTo.min.js",
            "prettify/prettify.js",
            "pretty.js"
        ];

        let output = "";

        for path in paths {
            let output .= strtr(template, ["%uri%": uri, "%path%": path]);
        }

        return output;
    }

    /**
     * Returns the template for the given name (override if set, default
     * otherwise).
     *
     * @param string $name
     *
     * @return string
     */
    public function getTemplate(string name) -> string
    {
        var template;

        if fetch template, this->templates[name] {
            return template;
        }

        return this->defaultTemplate(name);
    }

    /**
     * @return string
     */
    public function getVersion() -> string
    {
        var version, link;

        let version = new Version();
        let link    = "https://docs.phalcon.io/"
            . version->getPart(Version::VERSION_MAJOR)
            . "."
            . version->getPart(Version::VERSION_MEDIUM)
            . "/";

        return strtr(
            this->getTemplate("version"),
            ["%link%": link, "%version%": version->get()]
        );
    }

    /**
     * @param ExceptionReport $report
     *
     * @return string
     */
    public function render(<ExceptionReport> report) -> string
    {
        var className, escapedMessage, html, variablesTab;

        let className      = report->getClassName();
        let escapedMessage = this->escapeString(report->getMessage());

        let html = strtr(
            this->getTemplate("document"),
            [
                "%className%":      className,
                "%escapedMessage%": escapedMessage,
                "%cssSources%":     this->getCssSources(report->getUri())
            ]
        );

        let html .= this->getVersion();

        let html .= strtr(
            this->getTemplate("errorMain"),
            [
                "%className%":      className,
                "%escapedMessage%": escapedMessage,
                "%file%":           report->getFile(),
                "%line%":           (string) report->getLine()
            ]
        );

        if true === report->isShowBackTrace() {
            if report->hasVariables() {
                let variablesTab = this->getTemplate("variablesTab");
            } else {
                let variablesTab = "";
            }

            let html .= strtr(
                this->getTemplate("tabs"),
                ["%variablesTab%": variablesTab]
            );

            let html .= this->renderBacktrace(report->getBacktrace());
            let html .= this->renderSuperglobal("request", report->getRequest());
            let html .= this->renderSuperglobal("server", report->getServer());
            let html .= this->renderIncludedFiles(report->getIncludedFiles());
            let html .= this->renderMemory(report->getMemoryUsage());
            let html .= this->renderVariables(report->getVariables());
            let html .= this->getTemplate("errorInfoClose");
        }

        return html
            . this->getJsSources(report->getUri())
            . this->getTemplate("documentClose");
    }

    /**
     * Overrides the template for the given name.
     *
     * @param string $name
     * @param string $template
     *
     * @return static
     */
    public function setTemplate(string name, string template) -> <static>
    {
        let this->templates[name] = template;

        return this;
    }

    /**
     * Returns the embedded default template for the given name.
     *
     * @param string $name
     *
     * @return string
     */
    protected function defaultTemplate(string name) -> string
    {
        var defaults, template;

        let defaults = [
            "cssLink": "
    <link href='%uri%%path%'
          rel='stylesheet'
          type='text/css' />",
            "jsLink": "
    <script type='application/javascript'
            src='%uri%%path%'></script>",
            "version": "<div class='version'>
    Phalcon Framework <a href='%link%' target='_new'>%version%</a>
</div>",
            "document": "<!DOCTYPE html>
<html lang='en'>
<head>
    <title>%className%:%escapedMessage%</title>%cssSources%
</head>
<body>
",
            "errorMain": "
<div align='center'>
    <div class='error-main'>
        <h1>%className%: %escapedMessage%</h1>
        <span class='error-file'>%file% (%line%)</span>
    </div>",
            "documentClose": "
        </div>
    </body>
</html>",
            "errorInfoClose": "
            </div>",
            "tabs": "

    <div class='error-info'>
        <div id='tabs'>
            <ul>
                <li><a href='#backtrace'>Backtrace</a></li>
                <li><a href='#request'>Request</a></li>
                <li><a href='#server'>Server</a></li>
                <li><a href='#files'>Included Files</a></li>
                <li><a href='#memory'>Memory</a></li>%variablesTab%
            </ul>",
            "variablesTab": "
                <li><a href='#variables'>Variables</a></li>",
            "backtraceOpen": "

        <div id='backtrace'>
            <table style='border-collapse: collapse; border-spacing: 0; text-align=center; width:100%'>
                <tbody>",
            "closeTable": "
                </tbody>
            </table>
        </div>",
            "traceRow": "
                    <tr>
                        <td style='text-align: right; vertical-align: top'
                            class='error-number'>
                            #
                        </td>
                        <td>",
            "traceClass": "
                        <span class='error-class'>
                            %classNameWithLink%
                        </span>",
            "traceFunction": "
                        <span class='error-function'>
                            %functionNameWithLink%
                        </span>",
            "traceParameter": "
                        <span class='error-parameter'>
                            %dump%
                        </span>",
            "traceFile": "
                        <br/>
                        <div class='error-file'>
                            %file% (%line%)
                        </div>",
            "traceFragmentOpen": "
                        <pre class='prettyprint highlight:%firstLine%:%line% linenums:%firstLine%'>",
            "traceFragmentScrollOpen": "
                        <pre class='prettyprint highlight:%firstLine%:%line% linenums error-scroll'>",
            "traceFragmentClose": "
                            </pre>",
            "traceRowClose": "
                    </td>
                </tr>",
            "link": "<a target='_new' href='%url%'>%name%</a>",
            "tableHeader": "
        <div id='%divId%'>
            <table style='border-collapse: collapse; border-spacing: 0; text-align: center'
                   class='superglobal-detail'>
                <thead>
                <tr>
                    <th>%headerOne%</th>
                </tr>
                <tr>
                    <th>%headerTwo%</th>
                </tr>
                </thead>
                <tbody>",
            "superglobalRow": "
                    <tr>
                        <td class='key'>%key%</td>
                        <td>%dump%</td>
                    </tr>",
            "superglobalClose": "
                    </tbody>
                </table>
            </div>",
            "includedFileRow": "
                        <tr>
                            <td>%key%</td>
                            <td>%value%</td>
                        </tr>",
            "memory": "
                    <tr>
                        <td>
                            Usage
                        </td>
                        <td>%usage%</td>
                    </tr>
                </tbody>
                </table>
            </div>",
            "variableRow": "<tr><td class=\"key\">%key%</td><td>%dump%</td></tr>"
        ];

        if fetch template, defaults[name] {
            return template;
        }

        return "";
    }

    /**
     * Escapes a string with htmlentities
     *
     * @param string $value
     *
     * @return string
     */
    protected function escapeString(string value) -> string
    {
        return htmlentities(
            str_replace("\n", "\\n", value),
            ENT_COMPAT,
            "utf-8"
        );
    }

    /**
     * Produces a recursive representation of an array
     *
     * @param array $argument
     * @param int   $n
     *
     * @return string|null
     */
    protected function getArrayDump(array argument, int n = 0) -> string | null
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
     * Produces a string representation of a variable
     *
     * @param mixed $variable
     *
     * @return string
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

        if typeof variable == "string" {
            return this->escapeString(variable);
        }

        if is_scalar(variable) {
            return variable;
        }

        if typeof variable == "object" {
            let className = get_class(variable);

            if method_exists(variable, "dump") {
                let dumpedObject = variable->dump();

                return "Object(" . className . ": " . this->getArrayDump(dumpedObject) . ")";
            }

            return "Object(" . className . ")";
        }

        if typeof variable == "array" {
            return "Array(" . this->getArrayDump(variable) . ")";
        }

        if variable === null {
            return "null";
        }

        return gettype(variable);
    }

    /**
     * @param BacktraceItem[] $backtrace
     *
     * @return string
     */
    private function renderBacktrace(array backtrace) -> string
    {
        var html, item;

        let html = this->getTemplate("backtraceOpen");

        for item in backtrace {
            let html .= this->renderTraceItem(item);
        }

        return html . this->getTemplate("closeTable");
    }

    /**
     * @param BacktraceItem $item
     *
     * @return string
     */
    private function renderFile(<BacktraceItem> item) -> string
    {
        var html, fragment;

        if null === item->getFile() {
            return "";
        }

        let html = strtr(
            this->getTemplate("traceFile"),
            [
                "%file%": item->getFile(),
                "%line%": (string) item->getLine()
            ]
        );

        let fragment = item->getFragment();

        if null === fragment {
            return html;
        }

        return html . this->renderFragment(fragment);
    }

    /**
     * @param array $fragment
     *
     * @return string
     */
    private function renderFragment(array fragment) -> string
    {
        var isFragment, firstLine, lastLine, lines, html, template, i, currentLine;

        let isFragment = ("fragment" === fragment["mode"]);
        let firstLine  = fragment["firstLine"];
        let lastLine   = fragment["lastLine"];
        let lines      = fragment["lines"];

        if isFragment {
            let template = "traceFragmentOpen";
        } else {
            let template = "traceFragmentScrollOpen";
        }

        let html = strtr(
            this->getTemplate(template),
            [
                "%firstLine%": (string) firstLine,
                "%line%":      (string) fragment["line"]
            ]
        );

        let i = firstLine;

        while i <= lastLine {
            let currentLine = lines[i - 1];

            if isFragment && i == firstLine {
                if preg_match("#\\*\\/#", rtrim(currentLine)) {
                    let currentLine = str_replace("* /", " ", currentLine);
                }
            }

            if currentLine == "\n" || currentLine == "\r\n" {
                let html .= "&nbsp;\n";
            } else {
                let html .= htmlentities(
                    str_replace("\t", "  ", currentLine),
                    ENT_COMPAT,
                    "UTF-8"
                );
            }

            let i++;
        }

        return html . this->getTemplate("traceFragmentClose");
    }

    /**
     * @param array $files
     *
     * @return string
     */
    private function renderIncludedFiles(array files) -> string
    {
        var html, key, value;

        let html = this->renderTableHeader("files", "#", "Path");

        for key, value in files {
            let html .= strtr(
                this->getTemplate("includedFileRow"),
                ["%key%": (string) key, "%value%": value]
            );
        }

        return html . this->getTemplate("closeTable");
    }

    /**
     * @param string|null $link
     * @param string      $name
     *
     * @return string
     */
    private function renderLink(var link, string name) -> string
    {
        if null === link {
            return name;
        }

        return strtr(
            this->getTemplate("link"),
            ["%url%": link, "%name%": name]
        );
    }

    /**
     * @param int $usage
     *
     * @return string
     */
    private function renderMemory(int usage) -> string
    {
        var localUsage = usage;

        return this->renderTableHeader("memory", "Memory", "")
            . strtr(
                this->getTemplate("memory"),
                ["%usage%": (string) localUsage]
            );
    }

    /**
     * @param string $div
     * @param array  $source
     *
     * @return string
     */
    private function renderSuperglobal(string div, array source) -> string
    {
        var html, key, value;

        let html = this->renderTableHeader(div, "Key", "Value");

        for key, value in source {
            let html .= strtr(
                this->getTemplate("superglobalRow"),
                [
                    "%key%":  (string) key,
                    "%dump%": this->getVarDump(value)
                ]
            );
        }

        return html . this->getTemplate("superglobalClose");
    }

    /**
     * @param string $divId
     * @param string $headerOne
     * @param string $headerTwo
     *
     * @return string
     */
    private function renderTableHeader(string divId, string headerOne, string headerTwo) -> string
    {
        return strtr(
            this->getTemplate("tableHeader"),
            [
                "%divId%":     divId,
                "%headerOne%": headerOne,
                "%headerTwo%": headerTwo
            ]
        );
    }

    /**
     * @param BacktraceItem $item
     *
     * @return string
     */
    private function renderTraceItem(<BacktraceItem> item) -> string
    {
        var html, classNameWithLink, functionNameWithLink, arguments, argument;

        let html = this->getTemplate("traceRow");

        if null !== item->getClassName() {
            let classNameWithLink = this->renderLink(
                item->getClassLink(),
                item->getClassName()
            );

            let html .= strtr(
                this->getTemplate("traceClass"),
                ["%classNameWithLink%": classNameWithLink]
            );

            let html .= (string) item->getType();
        }

        let functionNameWithLink = this->renderLink(
            item->getFunctionLink(),
            item->getFunctionName()
        );

        let html .= strtr(
            this->getTemplate("traceFunction"),
            ["%functionNameWithLink%": functionNameWithLink]
        );

        if true === item->hasArgs() {
            let arguments = [];

            for argument in item->getArgs() {
                let arguments[] = strtr(
                    this->getTemplate("traceParameter"),
                    ["%dump%": this->getVarDump(argument)]
                );
            }

            let html .= "(" . join(", ", arguments) . ")";
        }

        let html .= this->renderFile(item);

        return html . this->getTemplate("traceRowClose");
    }

    /**
     * @param array $variables
     *
     * @return string
     */
    private function renderVariables(array variables) -> string
    {
        var html, key, value;

        if empty variables {
            return "";
        }

        let html = this->renderTableHeader("variables", "Key", "Value");

        for key, value in variables {
            let html .= strtr(
                this->getTemplate("variableRow"),
                [
                    "%key%":  (string) key,
                    "%dump%": this->getVarDump(value[0])
                ]
            );
        }

        return html . this->getTemplate("closeTable");
    }
}
