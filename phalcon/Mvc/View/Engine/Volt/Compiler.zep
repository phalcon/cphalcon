
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\View\Engine\Volt;

use Closure;
use Phalcon\Di\DiInterface;
use Phalcon\Mvc\ViewBaseInterface;
use Phalcon\Di\InjectionAwareInterface;

/**
 * This class reads and compiles Volt templates into PHP plain code
 *
 *```php
 * $compiler = new \Phalcon\Mvc\View\Engine\Volt\Compiler();
 *
 * $compiler->compile("views/partials/header.volt");
 *
 * require $compiler->getCompiledTemplatePath();
 *```
 */
class Compiler implements InjectionAwareInterface
{
    /**
     * @var bool
     */
    protected autoescape = false;

    /**
     * @var int
     */
    protected blockLevel = 0;

    /**
     * @var array|null
     *
     * TODO: Make array only?
     */
    protected blocks;

    /**
     * @var DiInterface|null
     */
    protected container = null;

    /**
     * @var string|null
     */
    protected compiledTemplatePath;

    /**
     * @var string|null
     */
    protected currentBlock = null;

    /**
     * @var string|null
     */
    protected currentPath = null;

    /**
     * @var int
     */
    protected exprLevel = 0;

    /**
     * @var bool
     */
    protected extended = false;

    /**
     * @var array
     */
    protected extensions = [];

    /**
     * @var array|bool
     *
     * TODO: Make it always array
     */
    protected extendedBlocks;

    /**
     * @var array
     */
    protected filters = [];

    /**
     * @var int
     */
    protected foreachLevel = 0;

    /**
     * @var array
     */
    protected forElsePointers = [];

    /**
     * @var array
     */
    protected functions = [];

    /**
     * @var int
     */
    protected level = 0;

    /**
     * @var array
     */
    protected loopPointers = [];

    /**
     * @var array
     */
    protected macros = [];

    /**
     * @var array
     */
    protected options = [];

    /**
     * @var string
     */
    protected prefix = "";

    /**
     * @var ViewBaseInterface|null
     */
    protected view;

    /**
     * Phalcon\Mvc\View\Engine\Volt\Compiler
     *
     * @param ViewBaseInterface|null view
     */
    public function __construct(<ViewBaseInterface> view = null)
    {
        let this->view = view;
    }

    /**
     * Registers a Volt's extension
     *
     * @var mixed extension
     *
     * @return Compiler
     */
    public function addExtension(extension) -> <Compiler>
    {
        if unlikely typeof extension != "object" {
            throw new Exception("The extension is not valid");
        }

        /**
         * Initialize the extension
         */
        if method_exists(extension, "initialize") {
            extension->initialize(this);
        }

        let this->extensions[] = extension;

        return this;
    }

    /**
     * Register a new filter in the compiler
     *
     * @param string name
     * @param mixed definition
     *
     * @return Compiler
     */
    public function addFilter(string! name, var definition) -> <Compiler>
    {
        let this->filters[name] = definition;

        return this;
    }

    /**
     * Register a new function in the compiler
     *
     * @param string name
     * @param mixed definition
     *
     * @return Compiler
     */
    public function addFunction(string! name, var definition) -> <Compiler>
    {
        let this->functions[name] = definition;

        return this;
    }

    /**
     * Resolves attribute reading
     *
     * @param array expr
     *
     * @return string
     */
    public function attributeReader(array! expr) -> string
    {
        var left, leftType, variable, level, leftCode, right;
        string exprCode;

        let exprCode = "";

        let left = expr["left"];

        if left["type"] == PHVOLT_T_IDENTIFIER {
            let variable = left["value"];

            /**
             * Check if the variable is the loop context
             */
            if variable == "loop" {
                let level = this->foreachLevel,
                    exprCode .= "$" . this->getUniquePrefix() . level . "loop",
                    this->loopPointers[level] = level;
            } else {
                /**
                 * Services registered in the dependency injector container are
                 * available always
                 */
                if this->container !== null && this->container->has(variable) {
                    let exprCode .= "$this->" . variable;
                } else {
                    let exprCode .= "$" . variable;
                }
            }
        } else {
            let leftCode = this->expression(left),
                leftType = left["type"];

            if leftType != PHVOLT_T_DOT && leftType != PHVOLT_T_FCALL {
                let exprCode .= leftCode;
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
     * Compiles a template into a file applying the compiler options
     * This method does not return the compiled path if the template was not compiled
     *
     *```php
     * $compiler->compile("views/layouts/main.volt");
     *
     * require $compiler->getCompiledTemplatePath();
     *```
     *
     * @param string templatePath
     * @param bool extendsMode
     *
     * @throws \Phalcon\Mvc\View\Engine\Volt\Exception
     * @return mixed
     */
    public function compile(string! templatePath, bool extendsMode = false)
    {
        var blocksCode, compilation, compileAlways, compiledExtension,
            compiledPath, compiledSeparator, compiledTemplatePath, options,
            prefix, stat, templateSepPath;

        /**
         * Re-initialize some properties already initialized when the object is
         * cloned
         */
        let this->extended = false;
        let this->extendedBlocks = false;
        let this->blocks = null;
        let this->level = 0;
        let this->foreachLevel = 0;
        let this->blockLevel = 0;
        let this->exprLevel = 0;

        let compilation = null;

        let options = this->options;

        /**
         * This makes that templates will be compiled always
         */
        if !fetch compileAlways, options["always"] {
            if fetch compileAlways, options["compileAlways"] {
                trigger_error(
                    "The 'compileAlways' option is deprecated. Use 'always' instead.",
                    E_USER_DEPRECATED
                );
            } else {
                let compileAlways = false;
            }
        }

        if unlikely typeof compileAlways != "boolean" {
            throw new Exception("'always' must be a bool value");
        }

        /**
         * Prefix is prepended to the template name
         */
        if !fetch prefix, options["prefix"] {
            let prefix = "";
        }

        if unlikely typeof prefix != "string" {
            throw new Exception("'prefix' must be a string");
        }

        /**
         * Compiled path is a directory where the compiled templates will be
         * located
         */
        if !fetch compiledPath, options["path"] {
            if fetch compiledPath, options["compiledPath"] {
                trigger_error(
                    "The 'compiledPath' option is deprecated. Use 'path' instead.",
                    E_USER_DEPRECATED
                );
            } else {
                let compiledPath = "";
            }
        }

        /**
         * There is no compiled separator by default
         */
        if !fetch compiledSeparator, options["separator"] {
            if fetch compiledSeparator, options["compiledSeparator"] {
                trigger_error(
                    "The 'compiledSeparator' option is deprecated. Use 'separator' instead.",
                    E_USER_DEPRECATED
                );
            } else {
                let compiledSeparator = "%%";
            }
        }

        if unlikely typeof compiledSeparator != "string" {
            throw new Exception("'separator' must be a string");
        }

        /**
         * By default the compile extension is .php
         */
        if !fetch compiledExtension, options["extension"] {
            if fetch compiledExtension, options["compiledExtension"] {
                trigger_error(
                    "The 'compiledExtension' option is deprecated. Use 'extension' instead.",
                    E_USER_DEPRECATED
                );
            } else {
                let compiledExtension = ".php";
            }
        }

        if unlikely typeof compiledExtension != "string" {
            throw new Exception("'extension' must be a string");
        }

        /**
         * Stat option assumes the compilation of the file
         */
        if !fetch stat, options["stat"] {
            let stat = true;
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
                 * Create the virtual path replacing the directory separator by
                 * the compiled separator
                 */
                let templateSepPath = prepare_virtual_path(
                    realpath(templatePath),
                    compiledSeparator
                );
            } else {
                let templateSepPath = templatePath;
            }

            /**
             * In extends mode we add an additional 'e' suffix to the file
             */
            if extendsMode {
                let compiledTemplatePath = compiledPath . prefix . templateSepPath . compiledSeparator . "e" . compiledSeparator . compiledExtension;
            } else {
                let compiledTemplatePath = compiledPath . prefix . templateSepPath . compiledExtension;
            }
        } elseif typeof compiledPath == "object" && compiledPath instanceof Closure {
            /**
             * A closure can dynamically compile the path
             */
            let compiledTemplatePath = call_user_func_array(
                compiledPath,
                [templatePath, options, extendsMode]
            );

            /**
             * The closure must return a valid path
             */
            if unlikely typeof compiledTemplatePath != "string" {
                throw new Exception(
                    "'path' closure didn't return a valid string"
                );
            }
        } else {
            throw new Exception(
                "'path' must be a string or a closure"
            );
        }

        /**
         * Compile always must be used only in the development stage
         */
        if !file_exists(compiledTemplatePath) || compileAlways {
            /**
             * The file needs to be compiled because it either doesn't exist or
             * needs to compiled every time
             */
            let compilation = this->compileFile(
                templatePath,
                compiledTemplatePath,
                extendsMode
            );
        } else {
            if stat === true {
                /**
                 * Compare modification timestamps to check if the file
                 * needs to be recompiled
                 */
                if compare_mtime(templatePath, compiledTemplatePath) {
                    let compilation = this->compileFile(
                        templatePath,
                        compiledTemplatePath,
                        extendsMode
                    );
                } else {
                    if extendsMode {
                        /**
                         * In extends mode we read the file that must
                         * contains a serialized array of blocks
                         */
                        let blocksCode = file_get_contents(compiledTemplatePath);

                        if unlikely blocksCode === false {
                            throw new Exception(
                                "Extends compilation file " . compiledTemplatePath . " could not be opened"
                            );
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
            }
        }

        let this->compiledTemplatePath = compiledTemplatePath;

        return compilation;
    }

    /**
     * Compiles a "autoescape" statement returning PHP code
     *
     * @param array statement
     * @param bool extendsMode
     *
     * @return string
     */
    public function compileAutoEscape(array! statement, bool extendsMode) -> string
    {
        var autoescape, oldAutoescape, compilation;

        /**
         * A valid option is required
         */
        if unlikely !fetch autoescape, statement["enable"] {
            throw new Exception("Corrupted statement");
        }

        /**
         * "autoescape" mode
         */
        let oldAutoescape = this->autoescape,
            this->autoescape = autoescape;

        let compilation = this->statementList(
            statement["block_statements"],
            extendsMode
        );

        let this->autoescape = oldAutoescape;

        return compilation;
    }

    /**
     * Compiles calls to macros
     *
     * @param array statement
     * @param bool extendsMode
     */
    public function compileCall(array! statement, bool extendsMode)
    {
        // Not implemented?
    }

    /**
     * Compiles a "case"/"default" clause returning PHP code
     *
     * @param array statement
     * @param bool caseClause
     *
     * @return string
     */
    public function compileCase(array! statement, bool caseClause = true) -> string
    {
        var expr;

        if unlikely caseClause === false {
            /**
             * "default" statement
             */
            return "<?php default: ?>";
        }

        /**
         * A valid expression is required
         */
        if unlikely !fetch expr, statement["expr"] {
            throw new Exception("Corrupt statement", statement);
        }

        /**
         * "case" statement
         */
        return "<?php case " . this->expression(expr) . ": ?>";
    }

    /**
     * Compiles a "do" statement returning PHP code
     *
     * @param array statement
     *
     * @return string
     */
    public function compileDo(array! statement) -> string
    {
        var expr;

        /**
         * A valid expression is required
         */
        if unlikely !fetch expr, statement["expr"] {
            throw new Exception("Corrupted statement");
        }

        /**
         * "Do" statement
         */
        return "<?php " . this->expression(expr) . "; ?>";
    }

    /**
     * Compiles a {% raw %}`{{` `}}`{% endraw %} statement returning PHP code
     *
     * @param array statement
     *
     * @return string
     */
    public function compileEcho(array! statement) -> string
    {
        var expr, exprCode, name;

        /**
         * A valid expression is required
         */
        if unlikely !fetch expr, statement["expr"] {
            throw new Exception("Corrupt statement", statement);
        }

        /**
         * Evaluate common expressions
         */
        let exprCode = this->expression(expr);

        if expr["type"] == PHVOLT_T_FCALL  {
            if this->isTagFactory(expr) === true {
                let exprCode = this->expression(expr, true);
            }

            let name = expr["name"];
            if name["type"] == PHVOLT_T_IDENTIFIER {
                /**
                 * super() is a function however the return of this function
                 * must be output as it is
                 */
                if name["value"] == "super" {
                    return exprCode;
                }
            }
        }

        /**
         * Echo statement
         */
        if this->autoescape {
            return "<?= $this->escaper->html(" . exprCode . ") ?>";
        }

        return "<?= " . exprCode . " ?>";
    }

    /**
     * Compiles a "elseif" statement returning PHP code
     *
     * @param array statement
     *
     * @return string
     */
    public function compileElseIf(array! statement) -> string
    {
        var expr;

        /**
         * A valid expression is required
         */
        if unlikely !fetch expr, statement["expr"] {
            throw new Exception("Corrupt statement", statement);
        }

        /**
         * "elseif" statement
         */
        return "<?php } elseif (" . this->expression(expr) . ") { ?>";
    }

    /**
     * Compiles a template into a file forcing the destination path
     *
     *```php
     * $compiler->compileFile(
     *     "views/layouts/main.volt",
     *     "views/layouts/main.volt.php"
     * );
     *```
     *
     * @param string path
     * @param string compiledPath
     * @param bool extendsMode
     *
     * @throws \Phalcon\Mvc\View\Engine\Volt\Exception
     * @return string|array
     */
    public function compileFile(string! path, string! compiledPath, bool extendsMode = false)
    {
        var viewCode, compilation, finalCompilation;

        if unlikely path == compiledPath {
            throw new Exception(
                "Template path and compilation template path cannot be the same"
            );
        }

        /**
         * Check if the template does exist
         */
        if unlikely !file_exists(path) {
            throw new Exception("Template file " . path . " does not exist");
        }

        /**
         * Always use file_get_contents instead of read the file directly, this
         * respect the open_basedir directive
         */
        let viewCode = file_get_contents(path);

        if unlikely viewCode === false {
            throw new Exception(
                "Template file " . path . " could not be opened"
            );
        }

        let this->currentPath = path;

        let compilation = this->compileSource(viewCode, extendsMode);

        /**
         * We store the file serialized if it's an array of blocks
         */
        if typeof compilation == "array" {
            let finalCompilation = serialize(compilation);
        } else {
            let finalCompilation = compilation;
        }

        /**
         * Always use file_put_contents to write files instead of write the file
         * directly, this respect the open_basedir directive
         */
        if unlikely file_put_contents(compiledPath, finalCompilation) === false {
            throw new Exception("Volt directory can't be written");
        }

        return compilation;
    }

    /**
     * Compiles a "foreach" intermediate code representation into plain PHP code
     *
     * @param array statement
     * @param bool extendsMode
     *
     * @return string
     */
    public function compileForeach(array! statement, bool extendsMode = false) -> string
    {
        var prefix, level, prefixLevel, expr, exprCode, bstatement, type,
            blockStatements, forElse, code, loopContext, iterator, key, ifExpr,
            variable;
        string compilation;

        /**
         * A valid expression is required
         */
        if unlikely !isset statement["expr"] {
            throw new Exception("Corrupted statement");
        }

        let compilation = "",
            forElse = null;

        let this->foreachLevel++;
        let prefix = this->getUniquePrefix();
        let level = this->foreachLevel;

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
                /**
                 * Check if the statement is valid
                 */
                if !fetch type, bstatement["type"] {
                    break;
                }

                if type == PHVOLT_T_ELSEFOR {
                    let compilation .= "<?php $" . prefixLevel . "iterated = false; ?>";
                    let forElse = prefixLevel;
                    let this->forElsePointers[level] = forElse;

                    break;
                }
            }
        }

        /**
         * Process statements block
         */
        let code = this->statementList(blockStatements, extendsMode);
        let loopContext = this->loopPointers;

        /**
         * Generate the loop context for the "foreach"
         */
        if isset loopContext[level] {
            let compilation .= "<?php $" . prefixLevel . "iterator = " . exprCode . "; ";
            let compilation .= "$" . prefixLevel . "incr = 0; ";
            let compilation .= "$" . prefixLevel . "loop = new stdClass(); ";
            let compilation .= "$" . prefixLevel . "loop->self = &$" . prefixLevel . "loop; ";
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
         * Update the forelse var if it's iterated at least one time
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

        let this->foreachLevel--;

        return compilation;
    }

    /**
     * Generates a 'forelse' PHP code
     *
     * @return string
     */
    public function compileForElse() -> string
    {
        var level, prefix;

        let level = this->foreachLevel;

        if !fetch prefix, this->forElsePointers[level] {
            return "";
        }

        if isset this->loopPointers[level] {
            return "<?php $" . prefix . "incr++; } if (!$" . prefix . "iterated) { ?>";
        }

        return "<?php } if (!$" . prefix . "iterated) { ?>";
    }

    /**
     * Compiles a 'if' statement returning PHP code
     *
     * @param array statement
     * @param bool extendsMode
     *
     * @throws \Phalcon\Mvc\View\Engine\Volt\Exception
     * @return string
     */
    public function compileIf(array! statement, bool extendsMode = false) -> string
    {
        var blockStatements, expr;
        string compilation;

        /**
         * A valid expression is required
         */
        if unlikely !fetch expr, statement["expr"] {
            throw new Exception("Corrupt statement", statement);
        }

        /**
         * Process statements in the "true" block
         */
        let compilation = "<?php if (" . this->expression(expr) . ") { ?>" . this->statementList(statement["true_statements"], extendsMode);

        /**
         * Check for a "else"/"elseif" block
         */
        if fetch blockStatements, statement["false_statements"] {
            /**
             * Process statements in the "false" block
             */
            let compilation .= "<?php } else { ?>" . this->statementList(blockStatements, extendsMode);
        }

        let compilation .= "<?php } ?>";

        return compilation;
    }

    /**
     * Compiles a 'include' statement returning PHP code
     *
     * @param array statement
     *
     * @throws \Phalcon\Mvc\View\Engine\Volt\Exception
     * @return string
     */
    public function compileInclude(array! statement) -> string
    {
        var pathExpr, path, subCompiler, finalPath, compilation, params;

        /**
         * Include statement
         * A valid expression is required
         */
        if unlikely !fetch pathExpr, statement["path"] {
            throw new Exception("Corrupted statement");
        }

        /**
         * Check if the expression is a string
         * If the path is an string try to make an static compilation
         */
        if pathExpr["type"] == 260 {
            /**
             * Static compilation cannot be performed if the user passed extra
             * parameters
             */
            if !isset statement["params"]  {
                /**
                 * Get the static path
                 */
                let path = pathExpr["value"];

                let finalPath = this->getFinalPath(path);

                /**
                 * Clone the original compiler
                 * Perform a sub-compilation of the included file
                 * If the compilation doesn't return anything we include the compiled path
                 */
                let subCompiler = clone this;
                let compilation = subCompiler->compile(finalPath, false);

                if compilation === null {
                    /**
                     * Use file-get-contents to respect the openbase_dir
                     * directive
                     */
                    let compilation = file_get_contents(
                        subCompiler->getCompiledTemplatePath()
                    );
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
     *
     * @param array statement
     * @param bool extendsMode
     *
     * @return string
     */
    public function compileMacro(array! statement, bool extendsMode) -> string
    {
        var name, defaultValue, parameters, position, parameter, variableName,
            blockStatements;
        string code, macroName;

        /**
         * A valid name is required
         */
        if unlikely !fetch name, statement["name"] {
            throw new Exception("Corrupted statement");
        }

        /**
         * Check if the macro is already defined
         */
        if unlikely isset this->macros[name] {
            throw new Exception("Macro '" . name . "' is already defined");
        }

        /**
         * Register the macro
         */
        let this->macros[name] = name;
        let macroName = "$this->macros['" . name . "']";
        let code = "<?php ";

        if !fetch parameters, statement["parameters"] {
            let code .= macroName . " = function() { ?>";
        } else {
            /**
             * Parameters are always received as an array
             */
            let code .= macroName . " = function($__p = null) { ";

            for position, parameter in parameters {
                let variableName = parameter["variable"];

                let code .= "if (isset($__p[" . position . "])) { ";
                let code .= "$" . variableName . " = $__p[" . position ."];";
                let code .= " } else { ";
                let code .= "if (array_key_exists(\"" . variableName . "\", $__p)) { ";
                let code .= "$" . variableName . " = $__p[\"" . variableName ."\"];";
                let code .= " } else { ";

                if likely fetch defaultValue, parameter["default"] {
                    let code .= "$" . variableName . " = " . this->expression(defaultValue) . ";";
                } else {
                    let code .= " throw new \\Phalcon\\Mvc\\View\\Exception(\"Macro '" . name . "' was called without parameter: " . variableName . "\"); ";
                }

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
            let code .= this->statementList(blockStatements, extendsMode) . "<?php }; ";
        }  else {
            let code .= "<?php }; ";
        }

        /**
         * Bind the closure to the $this object allowing to call services
         */
        let code .= macroName . " = \\Closure::bind(" . macroName . ", $this); ?>";

        return code;
    }

    /**
     * Compiles a "return" statement returning PHP code
     *
     * @throws \Phalcon\Mvc\View\Engine\Volt\Exception
     * @return string
     */
    public function compileReturn(array! statement) -> string
    {
        var expr;

        /**
         * A valid expression is required
         */
        if unlikely !fetch expr, statement["expr"] {
            throw new Exception("Corrupted statement");
        }

        /**
         * "Return" statement
         */
        return "<?php return " . this->expression(expr) . "; ?>";
    }

    /**
     * Compiles a "set" statement returning PHP code. The method accepts an
     * array produced by the Volt parser and creates the `set` statement in PHP.
     * This method is not particularly useful in development, since it requires
     * advanced knowledge of the Volt parser.
     *
     * ```php
     * <?php
     *
     * use Phalcon\Mvc\View\Engine\Volt\Compiler;
     *
     * $compiler = new Compiler();
     *
     * // {% set a = ['first': 1] %}

     * $source = [
     *     "type" => 306,
     *     "assignments" => [
     *         [
     *             "variable" => [
     *                 "type" => 265,
     *                 "value" => "a",
     *                 "file" => "eval code",
     *                 "line" => 1
     *             ],
     *             "op" => 61,
     *             "expr" => [
     *                 "type" => 360,
     *                 "left" => [
     *                     [
     *                         "expr" => [
     *                             "type" => 258,
     *                             "value" => "1",
     *                             "file" => "eval code",
     *                             "line" => 1
     *                         ],
     *                         "name" => "first",
     *                         "file" => "eval code",
     *                         "line" => 1
     *                     ]
     *                 ],
     *                 "file" => "eval code",
     *                 "line" => 1
     *             ],
     *             "file" => "eval code",
     *             "line" => 1
     *         ]
     *     ]
     * ];
     *
     * echo $compiler->compileSet($source);
     * // <?php $a = ['first' => 1]; ?>";
     * ```
     *
     * @param array $statement
     *
     * @throws \Phalcon\Mvc\View\Engine\Volt\Exception
     * @return string
     */
    public function compileSet(array! statement) -> string
    {
        var assignments, assignment, exprCode, target;
        string compilation;

        /**
         * A valid assignment list is required
         */
        if unlikely !fetch assignments, statement["assignments"] {
            throw new Exception("Corrupted statement");
        }

        let compilation = "<?php";

        /**
         * A single set can have several assignments
         */
        for assignment in assignments {
            let exprCode = this->expression(
                assignment["expr"]
            );

            /**
             * Resolve the expression assigned
             */
            let target = this->expression(
                assignment["variable"]
            );

            /**
             * Assignment operator
             * Generate the right operator
             */
            switch assignment["op"] {

                case PHVOLT_T_ADD_ASSIGN:
                    let compilation .= " " . target . " += " . exprCode . ";";
                    break;

                case PHVOLT_T_SUB_ASSIGN:
                    let compilation .= " " . target . " -= " . exprCode . ";";
                    break;

                case PHVOLT_T_MUL_ASSIGN:
                    let compilation .= " " . target . " *= " . exprCode . ";";
                    break;

                case PHVOLT_T_DIV_ASSIGN:
                    let compilation .= " " . target . " /= " . exprCode . ";";
                    break;

                default:
                    let compilation .= " " . target . " = " . exprCode . ";";
                    break;
            }

        }

        let compilation .= " ?>";

        return compilation;
    }

    /**
     * Compiles a template into a string
     *
     *```php
     * echo $compiler->compileString({% raw %}'{{ "hello world" }}'{% endraw %});
     *```
     *
     * @param string viewCode
     * @param bool extendsMode
     *
     * @return string
     */
    public function compileString(string! viewCode, bool extendsMode = false) -> string
    {
        let this->currentPath = "eval code";

        return this->compileSource(viewCode, extendsMode);
    }

    /**
     * Compiles a 'switch' statement returning PHP code
     *
     * @param array statement
     * @param bool extendsMode
     *
     * @throws \Phalcon\Mvc\View\Engine\Volt\Exception
     * @return string
     */
    public function compileSwitch(array! statement, bool extendsMode = false) -> string
    {
        var compilation, caseClauses, expr, lines;

        /**
         * A valid expression is required
         */
        if unlikely !fetch expr, statement["expr"] {
            throw new Exception("Corrupt statement", statement);
        }

        /**
         * Process statements in the "true" block
         */
        let compilation = "<?php switch (" . this->expression(expr) . "): ?>";

        /**
         * Check for a "case"/"default" blocks
         */
        if fetch caseClauses, statement["case_clauses"] {
            let lines = this->statementList(caseClauses, extendsMode);

            /**
             * Any output (including whitespace) between a switch statement and
             * the first case will result in a syntax error. This is the
             * responsibility of the user. However, we can clear empty lines and
             * whitespace here to reduce the number of errors.
             *
             * https://php.net/control-structures.alternative-syntax
             */
             if strlen(lines) !== 0 {
                /**
                 * (*ANYCRLF) - specifies a newline convention: (*CR), (*LF) or (*CRLF)
                 * \h+ - 1+ horizontal whitespace chars
                 * $ - end of line (now, before CR or LF)
                 * m - multiline mode on ($ matches at the end of a line).
                 * u - unicode
                 *
                 * g - global search, - is implicit with preg_replace(), you don't need to include it.
                 */
                let lines = preg_replace(
                    "/(*ANYCRLF)^\h+|\h+$|(\h){2,}/mu",
                    "",
                    lines
                );
             }

            let compilation .= lines;
        }

        let compilation .= "<?php endswitch ?>";

        return compilation;
    }

    /**
     * Resolves an expression node in an AST volt tree
     *
     * @param array $expr
     * @param bool  $doubleQuotes
     *
     * @return string
     */
    final public function expression(array! expr, bool doubleQuotes = false) -> string
    {
        var end, endCode, exprCode, extensions, items, left, leftCode, name,
            right, rightCode, singleExpr, singleExprCode, start, startCode, type;

        let exprCode = null, this->exprLevel++;

        /**
         * Check if any of the registered extensions provide compilation for
         * this expression
         */
        let extensions = this->extensions;

        loop {
            if typeof extensions === "array" {
                /**
                 * Notify the extensions about being resolving an expression
                 */
                let exprCode = this->fireExtensionEvent(
                    "resolveExpression",
                    [expr]
                );

                if typeof exprCode === "string" {
                    break;
                }
            }

            if !fetch type, expr["type"] {
                let items = [];

                for singleExpr in expr {
                    let singleExprCode = this->expression(
                        singleExpr["expr"],
                        doubleQuotes
                    );

                    if fetch name, singleExpr["name"] {
                        let items[] = "'" . name . "' => " . singleExprCode;
                    } else {
                        let items[] = singleExprCode;
                    }
                }

                let exprCode = implode(", ", items);

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
                let leftCode = this->expression(left, doubleQuotes);
            }

            /**
             * Operator "is" also needs special handling
             */
            if type == PHVOLT_T_IS {
                let exprCode = this->resolveTest(
                    expr["right"],
                    leftCode
                );

                break;
            }

            /**
             * We don't resolve the right expression for filters
             */
            if type == 124 {
                let exprCode = this->resolveFilter(
                    expr["right"],
                    leftCode
                );

                break;
            }

            /**
             * From here, right part of expression is always resolved
             */
            if fetch right, expr["right"] {
                let rightCode = this->expression(right, doubleQuotes);
            }

            let exprCode = null;

            switch type {
                case PHVOLT_T_NOT:
                    let exprCode = "!" . rightCode;
                    break;

                case PHVOLT_T_MUL:
                    let exprCode = leftCode . " * " . rightCode;
                    break;

                case PHVOLT_T_ADD:
                    let exprCode = leftCode . " + " . rightCode;
                    break;

                case PHVOLT_T_SUB:
                    let exprCode = leftCode . " - " . rightCode;
                    break;

                case PHVOLT_T_DIV:
                    let exprCode = leftCode . " / " . rightCode;
                    break;

                case 37:
                    let exprCode = leftCode . " % " . rightCode;
                    break;

                case PHVOLT_T_LESS:
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
                        let exprCode = "[" . leftCode . "]";
                    } else {
                        let exprCode = "[]";
                    }

                    break;

                case 258:
                    let exprCode = expr["value"];
                    break;

                case 259:
                    let exprCode = expr["value"];
                    break;

                case PHVOLT_T_STRING:
                    if likely doubleQuotes === false {
                        let exprCode = "'" . str_replace("'", "\\'", expr["value"]) . "'";
                    } else {
                        let exprCode = "\"" . expr["value"] . "\"";
                    }
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

                case PHVOLT_T_AND:
                    let exprCode = leftCode . " && " . rightCode;
                    break;

                case 267:
                    let exprCode = leftCode . " || " . rightCode;
                    break;

                case PHVOLT_T_LESSEQUAL:
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
                    let exprCode = this->functionCall(expr, doubleQuotes);
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
                        let startCode = this->expression(start, doubleQuotes);
                    } else {
                        let startCode = "null";
                    }

                    /**
                     * Evaluate the end part of the slice
                     */
                    if fetch end, expr["end"] {
                        let endCode = this->expression(end, doubleQuotes);
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
                    let exprCode = "(" . this->expression(expr["ternary"], doubleQuotes) . " ? " . leftCode . " : " . rightCode . ")";
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
                    throw new Exception(
                        "Unknown expression " . type . " in " . expr["file"] . " on line " . expr["line"]
                    );
            }

            break;
        }

        let this->exprLevel--;

        return exprCode;
    }

    /**
     * Fires an event to registered extensions
     *
     * @param string $name
     * @param array  $arguments
     *
     * @return mixed
     */
    final public function fireExtensionEvent(string! name, array arguments = [])
    {
        var extensions, extension, status;

        let extensions = this->extensions;

        for extension in extensions {
            /**
             * Check if the extension implements the required event name
             */
            if method_exists(extension, name) {
                if !empty arguments {
                    let status = call_user_func_array(
                        [extension, name],
                        arguments
                    );
                } else {
                    let status = call_user_func([extension, name]);
                }

                /**
                 * Only string statuses means the extension processes
                 * something
                 */
                if typeof status == "string" {
                    return status;
                }
            }
        }
    }

    /**
     * Resolves function intermediate code into PHP function calls
     *
     * @param array $expr
     * @param bool  $doubleQuotes
     *
     * @throws \Phalcon\Mvc\View\Engine\Volt\Exception
     * @return string
     */
    public function functionCall(array! expr, bool doubleQuotes = false) -> string
    {
        var arguments, arrayHelpers, block, code, currentBlock, definition,
            escapedCode, exprLevel, extendedBlocks, extensions, funcArguments,
            functions, method, name, nameExpr, nameType, tagService;

        let code          = null,
            funcArguments = null,
            nameExpr      = expr["name"],
            nameType      = nameExpr["type"];

        /**
         * The TagFactory helpers sometimes receive line endings
         * as parameters. Using single quotes is not going to make
         * that work. As such we need to recalculate the arguments
         */
        if fetch funcArguments, expr["arguments"] {
            let arguments = this->expression(funcArguments, doubleQuotes);
        } else {
            let arguments = "";
        }

        /**
         * Check if it's a single function
         */
        if nameType == PHVOLT_T_IDENTIFIER {
            let name = nameExpr["value"];

            /**
             * Check if any of the registered extensions provide compilation for
             * this function
             */
            let extensions = this->extensions;

            if typeof extensions == "array" {
                /**
                 * Notify the extensions about being compiling a function
                 */
                let code = this->fireExtensionEvent(
                    "compileFunction",
                    [name, arguments, funcArguments]
                );

                if typeof code == "string" {
                    return code;
                }
            }

            /**
             * Check if it's a user defined function
             */
            let functions = this->functions;

            if typeof functions == "array" {
                if fetch definition, functions[name] {
                    /**
                     * Use the string as function
                     */
                    if typeof definition == "string" {
                        return definition . "(" . arguments . ")";
                    }

                    /**
                     * Execute the function closure returning the compiled
                     * definition
                     */
                    if typeof definition == "object" {
                        if definition instanceof Closure {
                            return call_user_func_array(
                                definition,
                                [arguments, funcArguments]
                            );
                        }
                    }

                    throw new Exception(
                        "Invalid definition for user function '" . name . "' in " . expr["file"] . " on line " . expr["line"]
                    );
                }
            }

            /**
             * This function includes the previous rendering stage
             */
            if name == "get_content" || name == "content" {
                return "$this->getContent()";
            }

            /**
             * This function includes views of volt or others template engines
             * dynamically
             */
            if name == "partial" {
                return "$this->partial(" . arguments . ")";
            }

            /**
             * This function embeds the parent block in the current block
             */
            if name == "super" {
                let extendedBlocks = this->extendedBlocks;

                if typeof extendedBlocks == "array" {
                    let currentBlock = this->currentBlock;

                    if fetch block, extendedBlocks[currentBlock] {
                        let exprLevel = this->exprLevel;

                        if typeof block == "array" {
                            let code = this->statementListOrExtends(block);

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

            /**
             * Check if it's a method in Phalcon\Tag
             * @todo This needs a lot of refactoring and will break a lot of applications if removed
             */
            if name === "preload" {
                return "$this->preload(" . arguments . ")";
            }

            /**
             * Check if it's a method in Phalcon\Tag
             * @todo This needs a lot of refactoring and will break a lot of applications if removed
             */
            let method = lcfirst(camelize(name));
            let arrayHelpers = [
                "link_to":        true,
                "image":          true,
                "form_legacy":    true,
                "submit_button":  true,
                "radio_field":    true,
                "check_field":    true,
                "file_field":     true,
                "hidden_field":   true,
                "password_field": true,
                "text_area":      true,
                "text_field":     true,
                "email_field":    true,
                "date_field":     true,
                "tel_field":      true,
                "numeric_field":  true,
                "image_input":    true
            ];

            if method_exists("Phalcon\\Tag", method) {
                if isset arrayHelpers[name] {
                    return "\Phalcon\Tag::" . method . "([" . arguments . "])";
                }

                return "\Phalcon\Tag::" . method . "(" . arguments . ")";
            }

            /**
             * These are for the TagFactory
             */
            if this->container !== null && true === this->container->has("tag") {
                let tagService = this->container->get("tag");
                if true === tagService->has(name) {
                    /**
                     * recalculate the arguments because we need them double
                     * quoted
                     */
                    let funcArguments = null;
                    if fetch funcArguments, expr["arguments"] {
                        let arguments = this->expression(funcArguments, true);
                    } else {
                        let arguments = "";
                    }

                    return "$this->tag->" . name . "(" . arguments . ")";
                }
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
                return "(new Phalcon\\Support\\Version)->get()";
            }

            if name == "version_id" {
                return "(new Phalcon\\Support\\Version)->getId()";
            }

            if name == "preload" {
                return "$this->preload(" . arguments . ")";
            }

            /**
             * Read PHP constants in templates
             */
            if name == "constant" {
                return "constant(" . arguments . ")";
            }

            /**
             * By default it tries to call a macro
             */
            return "$this->callMacro('" . name . "', [" . arguments . "])";
        }

        return this->expression(nameExpr, doubleQuotes) . "(" . arguments . ")";
    }

    /**
     * Returns the path to the last compiled template
     *
     * @return string
     */
    public function getCompiledTemplatePath() -> string
    {
        return this->compiledTemplatePath;
    }

    /**
     * Returns the internal dependency injector
     *
     * @return DiInterface
     */
    public function getDI() -> <DiInterface>
    {
        return this->container;
    }

    /**
     * Returns the list of extensions registered in Volt
     *
     * @return array
     */
    public function getExtensions() -> array
    {
        return this->extensions;
    }

    /**
     * Register the user registered filters
     *
     * @return array
     */
    public function getFilters() -> array
    {
        return this->filters;
    }

    /**
     * Register the user registered functions
     *
     * @return array
     */
    public function getFunctions() -> array
    {
        return this->functions;
    }

    /**
     * Returns a compiler's option
     *
     * @param string option
     *
     * @return string|null
     */
    public function getOption(string! option) -> string | null
    {
        var value;

        if !fetch value, this->options[option] {
            return null;
        }

        return value;
    }

    /**
     * Returns the compiler options
     *
     * @return array
     */
    public function getOptions() -> array
    {
        return this->options;
    }

    /**
     * Returns the path that is currently being compiled
     *
     * @return string
     */
    public function getTemplatePath() -> string
    {
        return this->currentPath;
    }

    /**
     * Return a unique prefix to be used as prefix for compiled variables and
     * contexts
     *
     * @return string
     */
    public function getUniquePrefix() -> string
    {
        /**
         * If the unique prefix is not set we use a hash using the modified
         * Berstein algorithm
         */
        if !this->prefix {
            let this->prefix = unique_path_key(this->currentPath);
        }

        /**
         * The user could use a closure generator
         */
        if typeof this->prefix == "object" {
            if this->prefix instanceof Closure {
                let this->prefix = call_user_func_array(
                    this->prefix,
                    [
                        this
                    ]
                );
            }
        }

        if unlikely typeof this->prefix != "string" {
            throw new Exception("The unique compilation prefix is invalid");
        }

        return this->prefix;
    }


    /**
     * Parses a Volt template returning its intermediate representation
     *
     *```php
     * print_r(
     *     $compiler->parse("{% raw %}{{ 3 + 2 }}{% endraw %}")
     * );
     *```
     *
     * @param string viewCode
     *
     * @return array
     */
    public function parse(string! viewCode) -> array
    {
        var currentPath = "eval code";

        return phvolt_parse_view(viewCode, currentPath);
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

            switch (name) {
                case "empty":
                    return "empty(" . left . ")";
                case "even":
                    return "(((" . left . ") % 2) == 0)";
                case "odd":
                    return "(((" . left . ") % 2) != 0)";
                case "numeric":
                    return "is_numeric(" . left . ")";
                case "scalar":
                    return "is_scalar(" . left . ")";
                case "iterable":
                    return "(is_array(" . left . ") || (" . left . ") instanceof Traversable)";
            }

        }

        /**
         * Check if right part is a function call
         */
        if type == PHVOLT_T_FCALL {
            let testName = test["name"];

            if fetch name, testName["value"] {
                switch (name) {
                    case "divisibleby":
                        return "(((" . left . ") % (" . this->expression(test["arguments"]) . ")) == 0)";
                    case "sameas":
                        return "(" . left . ") === (" . this->expression(test["arguments"]) . ")";
                    case "type":
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
     * Sets the dependency injector
     */
    public function setDI(<DiInterface> container) -> void
    {
        let this->container = container;
    }

    /**
     * Sets a single compiler option
     *
     * @param mixed value
     */
    public function setOption(string! option, value)
    {
        let this->options[option] = value;
    }

    /**
     * Sets the compiler options
     */
    public function setOptions(array! options)
    {
        let this->options = options;
    }

    /**
     * Set a unique prefix to be used as prefix for compiled variables
     */
    public function setUniquePrefix(string! prefix) -> <Compiler>
    {
        let this->prefix = prefix;

        return this;
    }

    /**
     * Compiles a Volt source code returning a PHP plain version
     */
    protected function compileSource(string! viewCode, bool extendsMode = false) -> string
    {
        var currentPath, intermediate, extended, finalCompilation, blocks,
            extendedBlocks, name, block, blockCompilation, localBlock,
            compilation, options, autoescape;

        let currentPath = this->currentPath;

        /**
         * Check for compilation options
         */
        let options = this->options;

        if typeof options == "array" {
            /**
             * Enable autoescape globally
             */
            if fetch autoescape, options["autoescape"] {
                if unlikely typeof autoescape != "boolean" {
                    throw new Exception("'autoescape' must be bool");
                }

                let this->autoescape = autoescape;
            }
        }

        let intermediate = phvolt_parse_view(viewCode, currentPath);

        /**
         * The parsing must return a valid array
         */
        if unlikely typeof intermediate != "array" {
            throw new Exception("Invalid intermediate representation");
        }

        let compilation = this->statementList(intermediate, extendsMode);

        /**
         * Check if the template is extending another
         */
        let extended = this->extended;

        if extended === true {
            /**
             * Multiple-Inheritance is allowed
             */
            if extendsMode === true {
                let finalCompilation = [];
            } else {
                let finalCompilation = null;
            }

            let blocks = this->blocks;
            let extendedBlocks = this->extendedBlocks;

            for name, block in extendedBlocks {
                /**
                 * If name is a string then is a block name
                 */
                if typeof name == "string" {
                    if isset blocks[name] {
                        /**
                         * The block is set in the local template
                         */
                        let localBlock         = blocks[name],
                            this->currentBlock = name;

                        /**
                         * This is to ensure in PHP 8.0 we pass an array to statementList
                         */
                        if null === localBlock {
                            let localBlock = [];
                        }

                        let blockCompilation = this->statementList(localBlock);
                    } else {
                        if typeof block == "array" {
                            /**
                             * The block is not set local only in the extended
                             * template
                             */
                            let blockCompilation = this->statementList(block);
                        } else {
                            let blockCompilation = block;
                        }
                    }

                    if extendsMode {
                        let finalCompilation[name] = blockCompilation;
                    } else {
                        let finalCompilation .= blockCompilation;
                    }
                } else {
                    /**
                     * Here the block is an already compiled text
                     */
                    if extendsMode {
                        let finalCompilation[] = block;
                    } else {
                        let finalCompilation .= block;
                    }
                }
            }

            return finalCompilation;
        }

        if extendsMode {
            /**
             * In extends mode we return the template blocks instead of the
             * compilation
             */
            return this->blocks;
        }

        return compilation;
    }

    /**
     * Gets the final path with VIEW
     */
    protected function getFinalPath(string path)
    {
        var view, viewsDirs, viewsDir;

        let view = this->view;

        if typeof view == "object" {
            let viewsDirs = view->getViewsDir();

            if typeof viewsDirs == "array" {
                for viewsDir in viewsDirs {
                    if file_exists(viewsDir . path) {
                        return viewsDir . path;
                    }
                }

                // Otherwise, take the last viewsDir
                return viewsDir . path;
            } else {
                return viewsDirs . path;
            }
        }

        return path;
    }

    /**
     * Resolves filter intermediate code into PHP function calls
     */
    final protected function resolveFilter(array! filter, string left) -> string
    {
        var code, type, functionName, name, file, line, extensions, filters,
            funcArguments, arguments, definition;

        let code = null,
            type = filter["type"];

        /**
         * Check if the filter is a single identifier
         */
        if type == PHVOLT_T_IDENTIFIER {
            let name = filter["value"];
        } else {
            if unlikely type != PHVOLT_T_FCALL {
                /**
                 * Unknown filter throw an exception
                 */
                throw new Exception(
                    "Unknown filter type in " . filter["file"] . " on line " . filter["line"]
                );
            }

            let functionName = filter["name"],
                name = functionName["value"];
        }

        let funcArguments = null,
            arguments = null;

        /**
         * Resolve arguments
         */
        if fetch funcArguments, filter["arguments"] {
            /**
             * "default" filter is not the first argument, improve this!
             */
            if name != "default" {
                let file = filter["file"],
                    line = filter["line"];

                /**
                 * TODO: Implement this function directly
                 */
                array_unshift(
                    funcArguments,
                    [
                        "expr": [
                            "type":  364,
                            "value": left,
                            "file":  file,
                            "line":  line
                        ],
                        "file": file,
                        "line": line
                    ]
                );
            }

            let arguments = this->expression(funcArguments);
        } else {
            let arguments = left;
        }

        /**
         * Check if any of the registered extensions provide compilation for
         * this filter
         */
        let extensions = this->extensions;

        if typeof extensions == "array" {
            /**
             * Notify the extensions about being compiling a function
             */
            let code = this->fireExtensionEvent(
                "compileFilter",
                [name, arguments, funcArguments]
            );

            if typeof code == "string" {
                return code;
            }
        }

        /**
         * Check if it's a user defined filter
         */
        let filters = this->filters;

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
                    return call_user_func_array(
                        definition,
                        [arguments, funcArguments]
                    );
                }
            }

            /**
             * Invalid filter definition throw an exception
             */
            throw new Exception(
                "Invalid definition for user filter '" . name . "' in " . filter["file"] . " on line " . filter["line"]
            );
        }

        switch (name) {
            case "abs":
                return "abs(" . arguments . ")";
            case "capitalize":
                return "ucwords(" . arguments . ")";
            case "convert_encoding":
                return "$this->convertEncoding(" . arguments . ")";
            case "default":
                return "(empty(" . left . ") ? ("
                    . arguments . ") : ("
                    . left . "))";
            case "e":
            case "escape":
                return "$this->escaper->html(" . arguments . ")";
            case "escape_attr":
                return "$this->escaper->attributes(" . arguments . ")";
            case "escape_css":
                return "$this->escaper->css(" . arguments . ")";
            case "escape_js":
                return "$this->escaper->js(" . arguments . ")";
            case "format":
                return "sprintf(" . arguments . ")";
            case "join":
                return "join('" . funcArguments[1]["expr"]["value"]
                    . "', " . funcArguments[0]["expr"]["value"] . ")";
            case "json_encode":
                return "json_encode(" . arguments . ")";
            case "json_decode":
                return "json_decode(" . arguments . ")";
            case "keys":
                return "array_keys(" . arguments . ")";
            case "left_trim":
                return "ltrim(" . arguments . ")";
            case "length":
                return "$this->length(" . arguments . ")";
            case "lower":
            case "lowercase":
                if this->container !== null && true === this->container->has("helper") {
                    return "$this->helper->lower(" . arguments . ")";
                } else {
                    return "strtolower(" . arguments . ")";
                }
            case "right_trim":
                return "rtrim(" . arguments . ")";
            case "nl2br":
                return "nl2br(" . arguments . ")";
            case "slashes":
                return "addslashes(" . arguments . ")";
            case "slice":
                return "$this->slice(" . arguments . ")";
            case "sort":
                return "$this->sort(" . arguments . ")";
            case "stripslashes":
                return "stripslashes(" . arguments . ")";
            case "striptags":
                return "strip_tags(" . arguments . ")";
            case "trim":
                return "trim(" . arguments . ")";
            case "upper":
            case "uppercase":
                if this->container !== null && true === this->container->has("helper") {
                    return "$this->helper->upper(" . arguments . ")";
                } else {
                    return "strtoupper(" . arguments . ")";
                }
            case "url_encode":
                return "urlencode(" . arguments . ")";
        }

        throw new Exception(
            "Unknown filter \"" . name . "\" in "
                . filter["file"] . " on line " . filter["line"]
        );
    }

    /**
     * Traverses a statement list compiling each of its nodes
     */
    final protected function statementList(array! statements, bool extendsMode = false) -> string
    {
        var extended, blockMode, compilation, extensions, statement,
            tempCompilation, type, blockName, blockStatements, blocks, path,
            finalPath, subCompiler, level;

        /**
         * Nothing to compile
         */
        if !count(statements) {
            return "";
        }

        /**
         * Increase the statement recursion level in extends mode
         */
        let extended = this->extended;
        let blockMode = extended || extendsMode;

        if blockMode === true {
            let this->blockLevel++;
        }

        let this->level++;

        let compilation = null;

        let extensions = this->extensions;

        for statement in statements {
            /**
             * All statements must be arrays
             */
            if unlikely typeof statement != "array" {
                throw new Exception("Corrupted statement");
            }

            /**
             * Check if the statement is valid
             */
            if unlikely !isset statement["type"] {
                throw new Exception(
                    "Invalid statement in " . statement["file"] . " on line " . statement["line"],
                    statement
                );
            }

            /**
             * Check if extensions have implemented custom compilation for this
             * statement
             */
            if typeof extensions == "array" {
                /**
                 * Notify the extensions about being resolving a statement
                 */
                let tempCompilation = this->fireExtensionEvent(
                    "compileStatement",
                    [statement]
                );

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
             * Compile the statement according to the statement's type
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

                case PHVOLT_T_SWITCH:
                    let compilation .= this->compileSwitch(
                        statement,
                        extendsMode
                    );

                    break;

                case PHVOLT_T_CASE:
                    let compilation .= this->compileCase(statement);
                    break;

                case PHVOLT_T_DEFAULT:
                    let compilation .= this->compileCase(statement, false);
                    break;

                case PHVOLT_T_FOR:
                    let compilation .= this->compileForeach(
                        statement,
                        extendsMode
                    );

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

                    let blocks = this->blocks;

                    if blockMode {
                        if typeof blocks != "array" {
                            let blocks = [];
                        }

                        /**
                         * Create a unamed block
                         */
                        if compilation !== null {
                            let blocks[] = compilation;
                            let compilation = null;
                        }

                        /**
                         * In extends mode we add the block statements to the
                         * blocks variable
                         */
                        let blocks[blockName] = blockStatements;
                        let this->blocks = blocks;
                    } else {
                        if typeof blockStatements == "array" {
                            let compilation .= this->statementList(
                                blockStatements,
                                extendsMode
                            );
                        }
                    }

                    break;

                case PHVOLT_T_EXTENDS:
                    /**
                     * Extends statement
                     */
                    let path = statement["path"];

                    let finalPath = this->getFinalPath(
                        path["value"]
                    );

                    let extended = true;

                    /**
                     * Perform a sub-compilation of the extended file
                     */
                    let subCompiler = clone this;

                    let tempCompilation = subCompiler->compile(
                        finalPath,
                        extended
                    );

                    /**
                     * If the compilation doesn't return anything we include the
                     * compiled path
                     */
                    if tempCompilation === null {
                        let tempCompilation = file_get_contents(
                            subCompiler->getCompiledTemplatePath()
                        );
                    }

                    let this->extended = true;
                    let this->extendedBlocks = tempCompilation;
                    let blockMode = extended;

                    break;

                case PHVOLT_T_INCLUDE:
                    let compilation .= this->compileInclude(statement);

                    break;

                case PHVOLT_T_DO:
                    let compilation .= this->compileDo(statement);
                    break;

                case PHVOLT_T_RETURN:
                    let compilation .= this->compileReturn(statement);
                    break;

                case PHVOLT_T_AUTOESCAPE:
                    let compilation .= this->compileAutoEscape(
                        statement,
                        extendsMode
                    );

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
                    let compilation .= this->compileMacro(
                        statement,
                        extendsMode
                    );

                    break;

                case 325:
                    /**
                     * "Call" statement
                     */
                    let compilation .= this->compileCall(
                        statement,
                        extendsMode
                    );

                    break;

                case 358:
                    /**
                     * Empty statement
                     */
                    break;

                default:
                    throw new Exception(
                        "Unknown statement " . type . " in " . statement["file"] . " on line " . statement["line"]
                    );

            }
        }

        /**
         * Reduce the statement level nesting
         */
        if blockMode === true {
            let level = this->blockLevel;

            if level == 1 {
                if compilation !== null {
                    let this->blocks[] = compilation;
                }
            }

            let this->blockLevel--;
        }

        let this->level--;

        return compilation;
    }

    /**
     * Compiles a block of statements
     *
     * @param array statements
     * @return string|array
     */
    final protected function statementListOrExtends(var statements)
    {
        var statement;
        bool isStatementList;

        /**
         * Resolve the statement list as normal
         */
        if typeof statements != "array" {
            return statements;
        }

        /**
         * If all elements in the statement list are arrays we resolve this as a
         * statementList
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
        if isStatementList {
            return this->statementList(statements);
        }

        /**
         * Is an array but not a statement list?
         */
        return statements;
    }

    private function isTagFactory(array expression) -> bool
    {
        var left, leftValue, name;

        /**
         * This will check recursively:
         * - If we have a "name" array.
         * - If the "name" has a "left" sub-array
         * - If the "left" sub-array has a "value" of "tag"
         * - If the "left" has another sub-array then recurse
         */
        if fetch name, expression["name"] {
            if fetch left, name["left"] {
                /**
                 * There is a value, get it and check it
                 */
                if fetch leftValue, left["value"] {
                    return (leftValue === "tag");
                } else {
                    /**
                     * There is a "name" so that is nested, recursion
                     */
                    if isset left["name"] && typeof left["name"] === "array" {
                        return this->isTagFactory(left);
                    }
                }
            }
        }

        return false;
    }
}
