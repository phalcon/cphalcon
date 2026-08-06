
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Autoload;

use Phalcon\Autoload\Exceptions\LoaderDirectoriesNotArray;
use Phalcon\Autoload\Exceptions\LoaderMethodNotCallable;
use Phalcon\Events\Exception as EventsException;
use Phalcon\Events\Traits\EventsAwareTrait;

/**
 * The Phalcon Autoloader provides an easy way to automatically load classes
 * (namespaced or not) as well as files. It also features extension loading,
 * allowing the user to autoload files with different extensions than .php.
 *
 * @phpstan-type TNamespaces array<string, TStrings>
 * @phpstan-type TStrings array<string, string>
 */
class Loader
{
    use EventsAwareTrait;

    protected ?string checkedPath = null;
    /**
     * @var array<string, string>
     */
    protected array classes = [];
    /**
     * @var array<int, string>
     */
    protected array debug = [];
    /**
     * @var array<string, string>
     */
    protected array directories = [];
    /**
     * @var array<string, string>
     */
    protected array extensions = [];
    /**
     * @var callable|string
     */
    protected fileCheckingCallback = "is_file";
    /**
     * @var array<string, string>
     */
    protected array files = [];
    protected ?string foundPath = null;
    protected bool isDebug = false;
    protected bool isRegistered = false;

    /**
     * @var array<string, TStrings>
     */
    protected array namespaces = [];
    protected int nestingLevel = 0;

    /**
     * Loader constructor.
     */
    public function __construct(bool isDebug = false)
    {
        let this->extensions["php"] = "php",
            this->isDebug    = isDebug;
    }

    /**
     * Adds a class to the internal collection for the mapping
     */
    public function addClass(string name, string file) -> <static>
    {
        let this->classes[name] = file;

        return this;
    }

    /**
     * Adds a directory for the loaded files
     */
    public function addDirectory(string directory) -> <static>
    {
        let this->directories[directory] = directory;

        return this;
    }

    /**
     * Adds an extension for the loaded files
     */
    public function addExtension(string extension) -> <static>
    {
        let this->extensions[extension] = extension;

        return this;
    }

    /**
     * Adds a file to be added to the loader
     */
    public function addFile(string file) -> <static>
    {
        let this->files[file] = file;

        return this;
    }

    /**
     * @param string|TStrings $directories
     */
    public function addNamespace(
        string name,
        var directories,
        bool prepend = false
    ) -> <static> {
        var dirSeparator, nsName, nsSeparator, source, target;

        let nsName       = name,
            nsSeparator  = "\\",
            dirSeparator = DIRECTORY_SEPARATOR,
            nsName       = trim(nsName, nsSeparator) . nsSeparator,
            directories  = this->checkDirectories(directories, dirSeparator, name);

        // initialize the namespace prefix array if needed
        if (!isset(this->namespaces[nsName])) {
            let this->namespaces[nsName] = [];
        }

        let source = (prepend) ? directories : this->namespaces[nsName],
            target = (prepend) ? this->namespaces[nsName] : directories;

        let this->namespaces[nsName] = array_unique(
            array_merge(source, target)
        );

        return this;
    }

    /**
     * Autoloads the registered classes
     * @throws EventsException
     */
    public function autoload(string className) -> bool
    {
        bool result;

        /**
         * Reset the debug trail only on the outermost call. A "require_once"
         * routinely triggers a nested autoload (a class extending a not yet
         * loaded parent); resetting on a nested call would clobber the trail
         * of the outer call mid-flight.
         */
        if (0 === this->nestingLevel) {
            let this->debug = [];
        }

        let result             = true,
            this->nestingLevel = this->nestingLevel + 1;

        this->addDebug("Loading: " . className);
        this->fireManagerEvent("loader:beforeCheckClass", className);

        if (true !== this->autoloadCheckClasses(className)) {
            this->addDebug("Class: 404: " . className);

            if (true !== this->autoloadCheckNamespaces(className)) {
                this->addDebug("Namespace: 404: " . className);

                if (
                    true !== this->autoloadCheckDirectories(
                        this->directories,
                        className,
                        true
                    )
                ) {
                    this->addDebug("Directories: 404: " . className);
                    this->fireManagerEvent("loader:afterCheckClass", className);

                    /**
                     * Cannot find the class
                     */
                    let result = false;
                }
            }
        }

        let this->nestingLevel = this->nestingLevel - 1;

        return result;
    }

    /**
     * Get the path the loader is checking for a path
     */
    public function getCheckedPath() -> string | null
    {
        return this->checkedPath;
    }

    /**
     * Returns the class-map currently registered in the autoloader
     *
     * @return string[]
     */
    public function getClasses() -> array
    {
        return this->classes;
    }

    /**
     * Returns debug information collected
     *
     * @return string[]
     */
    public function getDebug() -> array
    {
        return this->debug;
    }

    /**
     * Returns the directories currently registered in the autoloader
     *
     * @return string[]
     */
    public function getDirectories() -> array
    {
        return this->directories;
    }

    /**
     * Returns the file extensions registered in the loader
     *
     * @return string[]
     */
    public function getExtensions() -> array
    {
        return this->extensions;
    }

    /**
     * Returns the files currently registered in the autoloader
     *
     * @return string[]
     */
    public function getFiles() -> array
    {
        return this->files;
    }

    /**
     * Get the path when a class was found
     *
     * @return string|null
     */
    public function getFoundPath() -> string | null
    {
        return this->foundPath;
    }

    /**
     * Returns the namespaces currently registered in the autoloader
     *
     * @return array<string, TStrings>
     */
    public function getNamespaces() -> array
    {
        return this->namespaces;
    }

    /**
     * Returns isRegistered
     */
    public function isRegistered() -> bool
    {
        return this->isRegistered;
    }

    /**
     * Checks if a file exists and then adds the file by doing virtual require
     */
    public function loadFiles() -> void
    {
        var file, files;

        let files = this->files;

        for file in files {
            this->fireManagerEvent("loader:beforeCheckPath", file);

            this->requireFile(file);
        }
    }

    /**
     * Register the autoload method
     *
     * @throws EventsException
     */
    public function register(bool prepend = false) -> <static>
    {
        if (true !== $this->isRegistered) {
            this->loadFiles();
            this->registerAutoload(prepend);

            let this->isRegistered = true;
        }

        return this;
    }

    /**
     * Register classes and their locations
     *
     * @param TStrings $classes
     */
    public function setClasses(array classes, bool merge = false) -> <static>
    {
        var className, name;

        if (!merge) {
            let this->classes = [];
        }

        for name, className in classes {
            this->addClass(name, className);
        }

        return this;
    }

    /**
     * Register directories in which "not found" classes could be found
     *
     * @param TStrings $directories
     * @param bool  $merge
     *
     * @return static
     */
    public function setDirectories(array directories, bool merge = false) -> <static>
    {
        return this->addToCollection(
            directories,
            "directories",
            "addDirectory",
            merge
        );
    }

    /**
     * Sets an array of file extensions that the loader must try in each attempt
     * to locate the file
     *
     * @param TStrings $extensions
     */
    public function setExtensions(array extensions, bool merge = false) -> <static>
    {
        var extension;

        if (!merge) {
            let this->extensions = [],
                this->extensions["php"] = "php";
        }

        for extension in extensions {
            this->addExtension(extension);
        }

        return this;
    }

    /**
     * Sets the file check callback.
     *
     * ```php
     * // Default behavior.
     * $loader->setFileCheckingCallback("is_file");
     *
     * // Faster than `is_file()`, but implies some issues if
     * // the file is removed from the filesystem.
     * $loader->setFileCheckingCallback("stream_resolve_include_path");
     *
     * // Do not check file existence.
     * $loader->setFileCheckingCallback(null);
     * ```
     *
     * @param callable|string|null $method
     *
     * @throws Exception
     */
    public function setFileCheckingCallback(var method = null) -> <static>
    {
        if (true === is_callable(method)) {
            let this->fileCheckingCallback = method;
        } elseif (null === method) {
            let this->fileCheckingCallback = function (file) {
                return true;
            };
        } else {
            throw new LoaderMethodNotCallable();
        }

        return this;
    }

    /**
     * Registers files that are "non-classes" hence need a "require". This is
     * very useful for including files that only have functions
     *
     * @param TStrings $files
     */
    public function setFiles(array files, bool merge = false) -> <static>
    {
        return this->addToCollection(
            files,
            "files",
            "addFile",
            merge
        );
    }

    /**
     * Register namespaces and their related directories
     *
     * @param array<string, TStrings> $namespaces
     */
    public function setNamespaces(array namespaces, bool merge = false) -> <static>
    {
        var directories, name;

        if (!merge) {
            let this->namespaces = [];
        }

        for name, directories in namespaces {
            this->addNamespace(name, directories);
        }

        return this;
    }

    /**
     * Unregister the autoload method
     */
    public function unregister() -> <static>
    {
        if (true === this->isRegistered) {
            spl_autoload_unregister(
                [
                    this,
                    "autoload"
                ]
            );

            let this->isRegistered = false;
        }

        return this;
    }

    /**
     * If the file exists, require it and return true; false otherwise
     *
     * @throws EventsException
     */
    protected function requireFile(string file) -> bool
    {
        /**
         * Check if the file specified even exists
         */
        if (false !== call_user_func(this->fileCheckingCallback, file)) {
            let this->foundPath = file;

            /**
             * Call 'pathFound' event
             */
            this->fireManagerEvent("loader:pathFound", file);
            this->addDebug("Require: " . file);

            /**
             * Check if the file specified even exists
             */
            require_once file;

            return true;
        }

        this->addDebug("Require: 404: " . file);

        return false;
    }

    /**
     * Adds a debugging message in the collection
     */
    private function addDebug(string message) -> void
    {
        if (true === this->isDebug) {
            let this->debug[] = message;
        }
    }

    /**
     * Traverses a collection and adds elements to it using the relevant
     * class method
     *
     * @param TStrings $collection
     */
    private function addToCollection(
        array collection,
        string collectionName,
        string method,
        bool merge = false
    ) -> <static> {
        var element;

        if (!merge) {
            let this->{collectionName} = [];
        }

        for element in collection {
            this->{method}(element);
        }

        return this;
    }

    /**
     * Checks the registered classes to find the class. Includes the file if
     * found and returns true; false otherwise
     *
     * @throws EventsException
     */
    private function autoloadCheckClasses(string className) -> bool
    {
        var filePath;

        if (true === isset(this->classes[className])) {
            let filePath = this->classes[className];

            this->fireManagerEvent("loader:beforeCheckPath", filePath);

            if (true === this->requireFile(filePath)) {
                this->addDebug("Class: load: " . filePath);

                return true;
            }
        }

        return false;
    }

    /**
     * Checks the registered directories to find the class. Includes the file if
     * found and returns true; false otherwise
     *
     * @param TStrings $directories
     *
     * @throws EventsException
     */
    private function autoloadCheckDirectories(
        array directories,
        string className,
        bool isDirectory = false
    ) -> bool {
        var dirSeparator, directory, extension, extensions,
            filePath, fixedDirectory, localClassName, nsSeparator;

        let dirSeparator   = DIRECTORY_SEPARATOR,
            nsSeparator    = "\\",
            localClassName = str_replace(nsSeparator, dirSeparator, className),
            extensions     = this->extensions;

        for directory in directories {
            /**
             * Add a trailing directory separator if the user forgot to do that
             */
            let fixedDirectory = rtrim(directory, dirSeparator) . dirSeparator;

            for extension in extensions {
                /**
                 * Create a possible path for the file
                 */
                let filePath          = fixedDirectory . localClassName . "." . extension,
                    this->checkedPath = filePath;

                this->fireManagerEvent("loader:beforeCheckPath", filePath);

                if (true === this->requireFile(filePath)) {
                    if (isDirectory) {
                        this->addDebug("Directories: " . filePath);
                    }
                    return true;
                }
            }
        }

        return false;
    }

    /**
     * Checks the registered namespaces to find the class. Includes the file if
     * found and returns true; false otherwise
     *
     * @throws EventsException
     */
    private function autoloadCheckNamespaces(string className) -> bool
    {
        var directories, fileName, namespaces, prefix;

        let namespaces = this->namespaces;

        for prefix, directories in namespaces {
            if (true !== starts_with(className, prefix)) {
                continue;
            }

            let fileName = substr(className, strlen(prefix));

            if (true === this->autoloadCheckDirectories(directories, fileName)) {
                this->addDebug("Namespace: " . prefix . " - " . this->checkedPath);
                return true;
            }
        }

        return false;
    }

    /**
     * Checks if the directories is an array or a string and throws an exception
     * if not. It converts the string to an array and then traverses the array
     * to normalize the directories with the proper directory separator at the
     * end
     *
     * @param string|TStrings $directories
     *
     * @return TStrings
     */
    private function checkDirectories(
        directories,
        string dirSeparator,
        string name = ""
    ) -> array {
        var directory;
        array results;

        if (!is_string(directories) && !is_array(directories)) {
            throw new LoaderDirectoriesNotArray(name);
        }

        if (is_string(directories)) {
            let directories = [directories];
        }

        let results = [];
        for directory in directories {
            let directory = rtrim(directory, dirSeparator) . dirSeparator;

            let results[directory] = directory;
        }

        return results;
    }

    private function registerAutoload(bool prepend) -> bool
    {
        return spl_autoload_register([this, "autoload"], true, prepend);
    }
}
