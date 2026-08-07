
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
use Phalcon\Support\Debug\Traits\TemplateAwareTrait;
use Phalcon\Support\Version;
use Phalcon\Traits\Support\Helper\Str\InterpolateTrait;

/**
 * Renders an ExceptionReport as the HTML debug page using embedded, overridable
 * template strings filled by the interpolator. All styling and interactivity
 * (theme, tabs, syntax highlighting, copy/editor links) are provided by the
 * external debug.css / debug.js assets.
 */
class HtmlRenderer implements Renderer
{
    use InterpolateTrait;
    use TemplateAwareTrait;

    public function getCssSources(string uri) -> string
    {
        return this->toInterpolate(
            this->getTemplate("cssLink"),
            ["uri": uri, "path": "debug.css"]
        );
    }

    public function getJsSources(string uri) -> string
    {
        return this->toInterpolate(
            this->getTemplate("jsLink"),
            ["uri": uri, "path": "debug.js"]
        );
    }

    public function getVersion() -> string
    {
        var version, link;

        let version = new Version();
        let link    = "https://docs.phalcon.io/"
            . version->getPart(Version::VERSION_MAJOR)
            . "."
            . version->getPart(Version::VERSION_MEDIUM)
            . "/";

        return this->toInterpolate(
            this->getTemplate("version"),
            ["link": link, "version": version->get()]
        );
    }

    public function render(<ExceptionReport> report) -> string
    {
        var className, escapedMessage, html;

        let className      = report->getClassName();
        let escapedMessage = this->escapeString(report->getMessage());

        let html = this->toInterpolate(
            this->getTemplate("document"),
            [
                "className":      className,
                "escapedMessage": escapedMessage,
                "cssSources":     this->getCssSources(report->getUri())
            ]
        );

        let html .= this->toInterpolate(
            this->getTemplate("masthead"),
            ["version": this->getVersion()]
        );

        let html .= this->toInterpolate(
            this->getTemplate("errorMain"),
            [
                "className":      className,
                "escapedMessage": escapedMessage,
                "file":           report->getFile(),
                "line":           (string) report->getLine(),
                "phpVersion":     PHP_VERSION
            ]
        );

        if true === report->isShowBackTrace() {
            let html .= this->renderTabs(report);
            let html .= this->renderBacktrace(report->getBacktrace());
            let html .= this->renderSuperglobal("request", report->getRequest());
            let html .= this->renderSuperglobal("server", report->getServer());
            let html .= this->renderIncludedFiles(report->getIncludedFiles());
            let html .= this->renderMemory(report);
            let html .= this->renderVariables(report->getVariables());
        }

        return html
            . this->getTemplate("wrapClose")
            . this->getJsSources(report->getUri())
            . this->getTemplate("documentClose");
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
    <script src='%uri%%path%'></script>",
            "version": "<a class='version-badge' href='%link%' target='_new'><b>v%version%</b></a>",
            "document": "<!DOCTYPE html>
<html lang='en' data-theme='light'>
<head>
    <meta charset='utf-8'>
    <meta name='viewport' content='width=device-width, initial-scale=1'>
    <title>%className%:%escapedMessage%</title>%cssSources%
</head>
<body>
<div class='wrap'>",
            "masthead": "
    <div class='masthead'>
        <div class='brand'><img class='logo' src='https://assets.phalcon.io/phalcon/images/svg/logo--tablet.svg' alt='Phalcon' /><span>Phalcon Debug</span></div>
        <div class='actions-top'>
            <button class='btn' data-action='copy-trace'>Copy trace</button>
            <button class='btn' data-action='toggle-theme' title='Toggle theme'>Theme</button>
            %version%
        </div>
    </div>",
            "errorMain": "
    <div class='error-card'>
        <span class='error-type'>%className%</span>
        <h1 class='error-message'>%escapedMessage%</h1>
        <div class='meta'>
            <span class='item'><code>%file%</code> : <code>%line%</code></span>
            <span class='sep'>|</span><span class='item'>PHP <code>%phpVersion%</code></span>
        </div>
    </div>",
            "tabs": "
    <div class='tabs' role='tablist'>
        <button class='tab is-active' data-tab='backtrace'>Backtrace <span class='count'>%backtraceCount%</span></button>
        <button class='tab' data-tab='request'>Request <span class='count'>%requestCount%</span></button>
        <button class='tab' data-tab='server'>Server <span class='count'>%serverCount%</span></button>
        <button class='tab' data-tab='files'>Included Files <span class='count'>%filesCount%</span></button>
        <button class='tab' data-tab='memory'>Memory</button>%variablesTab%
    </div>",
            "variablesTab": "
        <button class='tab' data-tab='variables'>Variables <span class='count'>%variablesCount%</span></button>",
            "backtracePanel": "
    <div class='panel is-active' id='backtrace'>
        <div class='bt-tools'>
            <button class='btn' data-action='expand-all'>Expand all</button>
            <button class='btn' data-action='collapse-all'>Collapse all</button>
        </div>",
            "panelOpen": "
    <div class='panel' id='%id%'>",
            "panelClose": "
    </div>",
            "wrapClose": "
</div>",
            "documentClose": "
</body>
</html>",
            "frameOpen": "
        <details class='frame %appClass%'%open%>
            <summary><div class='frame-head'>
                <span class='frame-num'>#%num%</span>
                <span class='frame-call'>%signature%</span>%appTag%
                <span class='chev'>&#9656;</span>
            </div></summary>",
            "appTag": "<span class='tag-app'>app</span>",
            "frameFile": "
            <div class='frame-file' data-file='%file%' data-line='%line%'>
                <span class='path'><b>%file%</b> : %line%</span>
            </div>",
            "frameClose": "
        </details>",
            "codeOpen": "
            <div class='code'><table>",
            "codeRow": "<tr%hlClass%><td class='ln'>%num%</td><td class='src'>%src%</td></tr>",
            "codeClose": "</table></div>",
            "link": "<a href='%url%' target='_new'>%name%</a>",
            "tableOpen": "<table class='grid'><thead><tr><th>%headerOne%</th><th>%headerTwo%</th></tr></thead><tbody>",
            "gridRow": "<tr><td class='k'>%key%</td><td class='v'>%value%</td></tr>",
            "tableClose": "</tbody></table>",
            "memory": "
        <div class='stats'>
            <div class='stat'><div class='label'>Memory usage (real)</div><div class='value'>%memory% <small>MB</small></div></div>
            <div class='stat'><div class='label'>Peak usage</div><div class='value'>%peak% <small>MB</small></div></div>
        </div>"
        ];

        if fetch template, defaults[name] {
            return template;
        }

        return "";
    }

    /**
     * Escapes a string with htmlentities
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
     */
    protected function getArrayDump(array argument, int number = 0) -> string | null
    {
        var numberArguments, dump, varDump, key, value;

        let numberArguments = count(argument);

        if number >= 3 || numberArguments == 0 {
            return null;
        }

        if numberArguments >= 10 {
            return (string) numberArguments;
        }

        let dump = [];

        for key, value in argument {
            if value === "" {
                let varDump = "(empty string)";
            } elseif is_scalar(value) {
                let varDump = this->escapeString(value);
            } elseif typeof value == "array" {
                let varDump = "Array(" . this->getArrayDump(value, number + 1) . ")";
            } elseif typeof value == "object" {
                let varDump = "Object(" . get_class(value) . ")";
            } elseif value === null {
                let varDump = "null";
            } else {
                let varDump = value;
            }

            let dump[] = "[" . key . "] =&gt; " . varDump;
        }

        return join(", ", dump);
    }

    /**
     * Produces a string representation of a variable
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
            return (string) variable;
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

    private function formatBytes(int bytes) -> string
    {
        var amount;

        let amount = bytes / 1048576;

        return number_format(amount, 1);
    }

    /**
     * Frames whose file lives outside a vendor directory are application code.
     */
    private function isApp(var file) -> bool
    {
        if null === file {
            return false;
        }

        return false === strpos(file, "/vendor/");
    }

    /**
     * @param BacktraceItem[] $backtrace
     */
    private function renderBacktrace(array backtrace) -> string
    {
        var html, index, item;

        let html = this->getTemplate("backtracePanel");

        for index, item in backtrace {
            let html .= this->renderTraceItem(index, item);
        }

        return html . this->getTemplate("panelClose");
    }

    private function renderFragment(array fragment) -> string
    {
        var firstLine, lastLine, line, lines, html, counter, currentLine;

        let firstLine = fragment["firstLine"];
        let lastLine  = fragment["lastLine"];
        let line      = fragment["line"];
        let lines     = fragment["lines"];

        let html    = this->getTemplate("codeOpen");
        let counter = firstLine;

        while counter <= lastLine {
            let currentLine = rtrim(isset(lines[counter - 1]) ? lines[counter - 1] : "", "\r\n");

            let html .= this->toInterpolate(
                this->getTemplate("codeRow"),
                [
                    "hlClass" : (counter === line) ? " class='hl'" : "",
                    "num"     : (string)counter,
                    "src"     : htmlentities(
                        str_replace("\t", "  ", currentLine),
                        ENT_COMPAT,
                        "UTF-8"
                    )
                ]
            );

            let counter++;
        }

        return html . this->getTemplate("codeClose");
    }

    private function renderIncludedFiles(array files) -> string
    {
        var html, key, value;

        let html = this->toInterpolate(this->getTemplate("panelOpen"), ["id": "files"])
            . this->toInterpolate(
                this->getTemplate("tableOpen"),
                ["headerOne": "#", "headerTwo": "Path"]
            );

        for key, value in files {
            let html .= this->toInterpolate(
                this->getTemplate("gridRow"),
                [
                    "key":   (string) key,
                    "value": this->escapeString(value)
                ]
            );
        }

        return html . this->getTemplate("tableClose") . this->getTemplate("panelClose");
    }

    private function renderMemory(<ExceptionReport> report) -> string
    {
        return this->toInterpolate(this->getTemplate("panelOpen"), ["id": "memory"])
            . this->toInterpolate(
                this->getTemplate("memory"),
                [
                    "memory": this->formatBytes(report->getMemoryUsage()),
                    "peak":   this->formatBytes(report->getPeakMemoryUsage())
                ]
            )
            . this->getTemplate("panelClose");
    }

    private function renderSignature(<BacktraceItem> item) -> string
    {
        var html, name, link, classHtml, fnName, fnLink, functionHtml, arguments, argument;

        let html = "";

        if null !== item->getClassName() {
            let name = this->escapeString(item->getClassName());
            let link = item->getClassLink();

            if null !== link {
                let classHtml = this->toInterpolate(
                    this->getTemplate("link"),
                    ["url": link, "name": name]
                );
            } else {
                let classHtml = name;
            }

            let html .= "<span class='cls'>" . classHtml . "</span>";
            let html .= "<span class='op'>" . (string) item->getType() . "</span>";
        }

        let fnName = this->escapeString(item->getFunctionName());
        let fnLink = item->getFunctionLink();

        if null !== fnLink {
            let functionHtml = this->toInterpolate(
                this->getTemplate("link"),
                ["url": fnLink, "name": fnName]
            );
        } else {
            let functionHtml = fnName;
        }

        let html .= "<span class='fn'>" . functionHtml . "</span>";

        if true === item->hasArgs() {
            let arguments = [];

            for argument in item->getArgs() {
                let arguments[] = this->getVarDump(argument);
            }

            let html .= "<span class='op'>(</span>" . join(", ", arguments) . "<span class='op'>)</span>";
        }

        return html;
    }

    private function renderSuperglobal(string div, array source) -> string
    {
        var html, key, value;

        let html = this->toInterpolate(this->getTemplate("panelOpen"), ["id": div])
            . this->toInterpolate(
                this->getTemplate("tableOpen"),
                ["headerOne": "Key", "headerTwo": "Value"]
            );

        for key, value in source {
            let html .= this->toInterpolate(
                this->getTemplate("gridRow"),
                [
                    "key":   this->escapeString((string) key),
                    "value": this->getVarDump(value)
                ]
            );
        }

        return html . this->getTemplate("tableClose") . this->getTemplate("panelClose");
    }

    private function renderTabs(<ExceptionReport> report) -> string
    {
        var variablesTab, variablesCount, backtraceCount, requestCount, serverCount, filesCount;

        let variablesTab = "";

        if report->hasVariables() {
            let variablesCount = count(report->getVariables());
            let variablesTab   = this->toInterpolate(
                this->getTemplate("variablesTab"),
                ["variablesCount": (string) variablesCount]
            );
        }

        let backtraceCount = count(report->getBacktrace());
        let requestCount   = count(report->getRequest());
        let serverCount    = count(report->getServer());
        let filesCount     = count(report->getIncludedFiles());

        return this->toInterpolate(
            this->getTemplate("tabs"),
            [
                "backtraceCount": (string) backtraceCount,
                "requestCount":   (string) requestCount,
                "serverCount":    (string) serverCount,
                "filesCount":     (string) filesCount,
                "variablesTab":   variablesTab
            ]
        );
    }

    private function renderTraceItem(int index, <BacktraceItem> item) -> string
    {
        var html, isApp, appClass, openAttr, appTag, fragment, frameNumber;

        let frameNumber = index;
        let isApp       = this->isApp(item->getFile());
        let appClass    = isApp ? "app" : "vendor";
        let openAttr    = (frameNumber == 0) ? " open" : "";
        let appTag      = isApp ? this->getTemplate("appTag") : "";

        let html = this->toInterpolate(
            this->getTemplate("frameOpen"),
            [
                "appClass":  appClass,
                "open":      openAttr,
                "num":       (string) frameNumber,
                "signature": this->renderSignature(item),
                "appTag":    appTag
            ]
        );

        if null !== item->getFile() {
            let html .= this->toInterpolate(
                this->getTemplate("frameFile"),
                [
                    "file": item->getFile(),
                    "line": (string) item->getLine()
                ]
            );

            let fragment = item->getFragment();

            if null !== fragment {
                let html .= this->renderFragment(fragment);
            }
        }

        return html . this->getTemplate("frameClose");
    }

    private function renderVariables(array variables) -> string
    {
        var html, key, value;

        if empty variables {
            return "";
        }

        let html = this->toInterpolate(this->getTemplate("panelOpen"), ["id": "variables"])
            . this->toInterpolate(
                this->getTemplate("tableOpen"),
                ["headerOne": "Key", "headerTwo": "Value"]
            );

        for key, value in variables {
            let html .= this->toInterpolate(
                this->getTemplate("gridRow"),
                [
                    "key":   this->escapeString((string) key),
                    "value": this->getVarDump(value[0])
                ]
            );
        }

        return html . this->getTemplate("tableClose") . this->getTemplate("panelClose");
    }
}
