
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Autoload;

use Phalcon\Events\AbstractEventsAware;

/**
 * The Phalcon Autoloader provides an easy way to automatically load classes
 * (namespaced or not) as well as files. It also features extension loading,
 * allowing the user to autoload files with different extensions than .php.
 *
 * @property string|null          $checkedPath
 * @property array                $classes
 * @property array                $debug
 * @property array                $directories
 * @property array                $extensions
 * @property string|callable|null $fileCheckingCallback
 * @property array                $files
 * @property string|null          $foundPath
 * @property bool                 $isDebug
 * @property bool                 $isRegistered
 * @property array                $namespaces
 */
class Loader extends AbstractEventsAware
{
    /**
     * @var string|null
     */
    protected checkedPath = null;

    /**
     * @var array
     */
    protected classes = [];

    /**
     * @var array
     */
    protected debug = [];

    /**
     * @var array
     */
    protected directories = [];

    /**
     * @var array
     */
    protected extensions = [];

    /**
     * @var string|callable
     */
    protected fileCheckingCallback = "is_file";

    /**
     * @var array
     */
    protected files = [];

    /**
     * @var string|null
     */
    protected foundPath = null;

    /**
     * @var bool
     */
    protected isDebug = false;

    /**
     * @var bool
     */
    protected isRegistered = false;

    /**
     * @var array
     */
    protected namespaces = [];

    /**
     * Loader constructor.
     */
    public function __construct(bool isDebug = false)
    {
        let this->extensions[hash("sha256", "php")] = "php",
            this->isDebug    = isDebug;
    }

    /**
     * Adds a class to the internal collection for the mapping
     *
     * @param string $name
     * @param string $file
     *
     * @return Loader
     */
    public function addClass(string name, string file) -> <Loader>
    {
        let this->classes[name] = file;

        return this;
    }

    /**
     * Adds a directory for the loaded files
     *
     * @param string $directory
     *
     * @return Loader
     */
    public function addDirectory(string directory) -> <Loader>
    {
        let this->directories[hash("sha256", directory)] = directory;

        return this;
    }

    /**
     * Adds an extension for the loaded files
     *
     * @param string $extension
     *
     * @return Loader
     */
    public function addExtension(string extension) -> <Loader>
    {
        let this->extensions[hash("sha256", extension)] = extension;

        return this;
    }

    /**
     * Adds a file to be added to the loader
     *
     * @param string $file
     *
     * @return Loader
     */
    public function addFile(string file) -> <Loader>
    {
        let this->files[hash("sha256", file)] = file;

        return this;
    }

    /**
     * @param string $name
     * @param mixed  $directories
     * @param bool   $prepend
     *
     * @return Loader
     * @throws Exception
     */
    public function addNamespace(
        string name,
        var directories,
        bool prepend = false
    ) -> <Loader> {
        var dirSeparator, nsName, nsSeparator, source, target;

        let nsName       = name,
            nsSeparator  = "\\",
            dirSeparator = DIRECTORY_SEPARATOR,
            nsName       = trim(nsName, nsSeparator) . nsSeparator,
            directories  = this->checkDirectories(directories, dirSeparator);

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
     *
     * @param string $className
     *
     * @return bool
     */
    public function autoload(string className) -> bool
    {
        let this->debug = [];

        this->addDebug("Loading: " . className);
        this->fireManagerEvent("loader:beforeCheckClass", className);

        if (true === this->autoloadCheckClasses(className)) {
            return true;
        }

        this->addDebug("Class: 404: " . className);

        if (true === this->autoloadCheckNamespaces(className)) {
            return true;
        }

        this->addDebug("Namespace: 404: " . className);

        if (
            true === this->autoloadCheckDirectories(
                this->directories,
                className,
                true
            )
        ) {
            return true;
        }

        this->addDebug("Directories: 404: " . className);

        this->fireManagerEvent("loader:afterCheckClass", className);

        /**
         * Cannot find the class, return false
         */
        return false;
    }

    /**
     * Get the path the loader is checking for a path
     *
     * @return string|null
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
     * @return string[]
     */
    public function getNamespaces() -> array
    {
        return this->namespaces;
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

            if (true === this->requireFile(file)) {
                let this->foundPath = file;
                this->fireManagerEvent("loader:pathFound", file);
            }
        }
    }

    /**
     * Register the autoload method
     */
    public function register(bool prepend = false) -> <Loader>
    {
        if (true !== this->isRegistered) {
            this->loadFiles();

            spl_autoload_register(
                [this, "autoload"],
                true,
                prepend
            );

            let this->isRegistered = true;
        }

        return this;
    }

    /**
     * Register classes and their locations
     *
     * @param array $classes
     * @param bool  $merge
     *
     * @return Loader
     */
    public function setClasses(array classes, bool merge = false) -> <Loader>
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
     * @param array $directories
     * @param bool  $merge
     *
     * @return Loader
     */
    public function setDirectories(array directories, bool merge = false) -> <Loader>
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
     * @param array $extensions
     * @param bool  $merge
     *
     * @return Loader
     */
    public function setExtensions(array extensions, bool merge = false) -> <Loader>
    {
        var extension;

        if (!merge) {
            let this->extensions = [],
                this->extensions[hash("sha256", "php")] = "php";
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
     * @param string|callable|null $method
     *
     * @return Loader
     * @throws Exception
     */
    public function setFileCheckingCallback(method = null) -> <Loader>
    {
        if (true === is_callable(method)) {
            let this->fileCheckingCallback = method;
        } elseif (null === method) {
            let this->fileCheckingCallback = function (file) {
                return true;
            };
        } else {
            throw new Exception(
                "The 'method' parameter must be either a callable or NULL"
            );
        }

        return this;
    }

    /**
     * Registers files that are "non-classes" hence need a "require". This is
     * very useful for including files that only have functions
     *
     * @param array $files
     * @param bool  $merge
     *
     * @return Loader
     */
    public function setFiles(array files, bool merge = false) -> <Loader>
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
     * @param array $namespaces
     * @param bool  $merge
     *
     * @return Loader
     */
    public function setNamespaces(array namespaces, bool merge = false) -> <Loader>
    {
        var dirSeparator, directories, name;

        let dirSeparator = DIRECTORY_SEPARATOR;

        if (!merge) {
            let this->namespaces = [];
        }

        for name, directories in namespaces {
            let directories = this->checkDirectories(directories, dirSeparator);
            this->addNamespace(name, directories);
        }

        return this;
    }

    /**
     * Unregister the autoload method
     *
     * @return Loader
     */
    public function unregister() -> <Loader>
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
     * @param string $file The file to require
     *
     * @return bool
     */
    protected function requireFile(string file) -> bool
    {
        /**
         * Check if the file specified even exists
         */
        if (false !== call_user_func(this->fileCheckingCallback, file)) {
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
     *
     * @param string $message
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
     * @param array  $collection
     * @param string $collectionName
     * @param string $method
     * @param bool   $merge
     *
     * @return Loader
     */
    private function addToCollection(
        array collection,
        string collectionName,
        string method,
        bool merge = false
    ) -> <Loader> {
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
     * @param string $className
     *
     * @return bool
     */
    private function autoloadCheckClasses(string className) -> bool
    {
        var filePath;

        if (true === isset(this->classes[className])) {
            let filePath = this->classes[className];
            this->fireManagerEvent("loader:pathFound", filePath);

            this->requireFile(filePath);
            this->addDebug("Class: load: " . filePath);

            return true;
        }

        return false;
    }

    /**
     * Checks the registered directories to find the class. Includes the file if
     * found and returns true; false otherwise
     *
     * @param array  $directories
     * @param string $className
     * @param bool   $isDirectory
     *
     * @return bool
     */
    private function autoloadCheckDirectories(
        array directories,
        string className,
        bool isDirectory = false
    ) -> bool {
        var className, dirSeparator, directory, extension, extensions,
            filePath, fixedDirectory, nsSeparator;

        let dirSeparator = DIRECTORY_SEPARATOR,
            nsSeparator  = "\\",
            className    = str_replace(nsSeparator, dirSeparator, className),
            extensions   = this->extensions;

        for directory in directories {
            /**
             * Add a trailing directory separator if the user forgot to do that
             */
            let fixedDirectory = rtrim(directory, dirSeparator) . dirSeparator;

            for extension in extensions {
                /**
                 * Create a possible path for the file
                 */
                let filePath          = fixedDirectory . className . "." . extension,
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
     * @param string $className
     *
     * @return bool
     */
    private function autoloadCheckNamespaces(string className) -> bool
    {
        var directories, fileName, namespaces, nsSeparator, prefix;

        let nsSeparator = "\\",
            namespaces  = this->namespaces;

        for prefix, directories in namespaces {
            if (true !== starts_with(className, prefix)) {
                continue;
            }

            /**
             * Append the namespace separator to the prefix
             */
            let prefix   = rtrim(prefix, nsSeparator) . nsSeparator,
                fileName = substr(className, strlen(prefix));

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
     * @param mixed  $directories
     * @param string $dirSeparator
     *
     * @return array<string, string>
     * @throws Exception
     */
    private function checkDirectories(directories, string dirSeparator) -> array
    {
        var directory;
        array results;

        if (!is_string(directories) && !is_array(directories)) {
            throw new Exception(
                "The directories parameter is not a string or array"
            );
        }

        if (is_string(directories)) {
            let directories = [directories];
        }

        let results = [];
        for directory in directories {
            let directory = rtrim(directory, dirSeparator) . dirSeparator;

            let results[hash("sha256", directory)] = directory;
        }

        return results;
    }
}
