
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon;

use Phalcon\Loader\Exception;
use Phalcon\Events\ManagerInterface;
use Phalcon\Events\EventsAwareInterface;

/**
 * This component helps to load your project classes automatically based on some
 * conventions
 *
 *```php
 * use Phalcon\Loader;
 *
 * // Creates the autoloader
 * $loader = new Loader();
 *
 * // Register some namespaces
 * $loader->registerNamespaces(
 *     [
 *         "Example\\Base"    => "vendor/example/base/",
 *         "Example\\Adapter" => "vendor/example/adapter/",
 *         "Example"          => "vendor/example/",
 *     ]
 * );
 *
 * // Register autoloader
 * $loader->register();
 *
 * // Requiring this class will automatically include file vendor/example/adapter/Some.php
 * $adapter = new \Example\Adapter\Some();
 *```
 */
class Loader implements EventsAwareInterface
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
    protected directories = [];

    /**
     * @var ManagerInterface|null
     */
    protected eventsManager = null;

    /**
     * @var array
     */
    protected extensions = ["php"];

    /**
     * @var string
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
     * @var array
     */
    protected namespaces = [];

    /**
     * @var bool
     */
    protected registered = false;

    /**
     * Autoloads the registered classes
     */
    public function autoLoad(string! className) -> bool
    {
        var eventsManager, classes, extensions, filePath, ds, fixedDirectory,
            directories, ns, namespaces, nsPrefix, directory, fileName,
            extension, nsClassName, fileCheckingCallback;

        let eventsManager = this->eventsManager;

        if typeof eventsManager == "object" {
            eventsManager->fire("loader:beforeCheckClass", this, className);
        }

        /**
         * First we check for static paths for classes
         */
        let classes = this->classes;

        if fetch filePath, classes[className] {
            if typeof eventsManager == "object" {
                let this->foundPath = filePath;
                eventsManager->fire("loader:pathFound", this, filePath);
            }

            require filePath;

            return true;
        }

        let extensions = this->extensions;

        let ds = DIRECTORY_SEPARATOR,
            ns = "\\";

        /**
         * Checking in namespaces
         */
        let namespaces = this->namespaces;

        let fileCheckingCallback = this->fileCheckingCallback;

        for nsPrefix, directories in namespaces {
            /**
             * The class name must start with the current namespace
             */
            if !starts_with(className, nsPrefix) {
                continue;
            }

            /**
             * Append the namespace separator to the prefix
             */
            let fileName = substr(className, strlen(nsPrefix . ns));

            if !fileName {
                continue;
            }

            let fileName = str_replace(ns, ds, fileName);

            for directory in directories {
                /**
                 * Add a trailing directory separator if the user forgot to do
                 * that
                 */
                let fixedDirectory = rtrim(directory, ds) . ds;

                for extension in extensions {
                    let filePath = fixedDirectory . fileName . "." . extension;

                    /**
                     * Check if a events manager is available
                     */
                    if typeof eventsManager == "object" {
                        let this->checkedPath = filePath;

                        eventsManager->fire("loader:beforeCheckPath", this);
                    }

                    /**
                     * This is probably a good path, let's check if the file
                     * exists
                     */
                    if call_user_func(fileCheckingCallback, filePath) {
                        if typeof eventsManager == "object" {
                            let this->foundPath = filePath;

                            eventsManager->fire(
                                "loader:pathFound",
                                this,
                                filePath
                            );
                        }

                        /**
                         * Simulate a require
                         */
                        require filePath;

                        /**
                         * Return true mean success
                         */
                        return true;
                    }
                }
            }
        }

        /**
         * Change the namespace separator by directory separator too
         */
        let nsClassName = str_replace(ns, ds, className);

        /**
         * Checking in directories
         */
        let directories = this->directories;

        for directory in directories {
            /**
             * Add a trailing directory separator if the user forgot to do that
             */
            let fixedDirectory = rtrim(directory, ds) . ds;

            for extension in extensions {
                /**
                 * Create a possible path for the file
                 */
                let filePath = fixedDirectory . nsClassName . "." . extension;

                if typeof eventsManager == "object" {
                    let this->checkedPath = filePath;

                    eventsManager->fire(
                        "loader:beforeCheckPath",
                        this,
                        filePath
                    );
                }

                /**
                 * Check in every directory if the class exists here
                 */
                if call_user_func(fileCheckingCallback, filePath) {
                    /**
                     * Call 'pathFound' event
                     */
                    if typeof eventsManager == "object" {
                        let this->foundPath = filePath;

                        eventsManager->fire("loader:pathFound", this, filePath);
                    }

                    /**
                     * Simulate a require
                     */
                    require filePath;

                    /**
                     * Return true meaning success
                     */
                    return true;
                }
            }
        }

        /**
         * Call 'afterCheckClass' event
         */
        if typeof eventsManager == "object" {
            eventsManager->fire("loader:afterCheckClass", this, className);
        }

        /**
         * Cannot find the class, return false
         */
        return false;
    }

    /**
     * Get the path the loader is checking for a path
     */
    public function getCheckedPath() -> string
    {
        return this->checkedPath;
    }
    /**
     * Returns the class-map currently registered in the autoloader
     */
    public function getClasses() -> array
    {
        return this->classes;
    }

    /**
     * Returns the directories currently registered in the autoloader
     */
    public function getDirs() -> array
    {
        return this->directories;
    }

    /**
     * Returns the internal event manager
     */
    public function getEventsManager() -> <ManagerInterface> | null
    {
        return this->eventsManager;
    }

    /**
     * Returns the file extensions registered in the loader
     */
    public function getExtensions() -> array
    {
        return this->extensions;
    }

    /**
     * Returns the files currently registered in the autoloader
     */
    public function getFiles() -> array
    {
        return this->files;
    }

    /**
     * Get the path when a class was found
     */
    public function getFoundPath() -> string
    {
        return this->foundPath;
    }

    /**
     * Returns the namespaces currently registered in the autoloader
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
        var filePath, fileCheckingCallback;

        let fileCheckingCallback = this->fileCheckingCallback;

        for filePath in this->files {
            if typeof this->eventsManager == "object" {
                let this->checkedPath = filePath;
                    this->eventsManager->fire(
                        "loader:beforeCheckPath",
                        this,
                        filePath
                    );
            }

            /**
             * Check if the file specified even exists
             */
            if call_user_func(fileCheckingCallback, filePath) {
                /**
                 * Call 'pathFound' event
                 */
                if typeof this->eventsManager == "object" {
                    let this->foundPath = filePath;

                    this->eventsManager->fire(
                        "loader:pathFound",
                        this,
                        filePath
                    );
                }

                /**
                 * Simulate a require
                 */
                require filePath;
            }
        }
    }

    /**
     * Register the autoload method
     */
    public function register(bool prepend = false) -> <Loader>
    {
        if this->registered === false {
            /**
             * Loads individual files added using Loader->registerFiles()
             */
            this->loadFiles();

            /**
             * Registers directories & namespaces to PHP's autoload
             */
            spl_autoload_register(
                [this, "autoLoad"],
                true,
                prepend
            );

            let this->registered = true;
        }

        return this;
    }

    /**
     * Register classes and their locations
     */
    public function registerClasses(array! classes, bool merge = false) -> <Loader>
    {
        if merge {
            let this->classes = array_merge(this->classes, classes);
        } else {
            let this->classes = classes;
        }

        return this;
    }

    /**
     * Register directories in which "not found" classes could be found
     */
    public function registerDirs(array! directories, bool merge = false) -> <Loader>
    {
        if merge {
            let this->directories = array_merge(this->directories, directories);
        } else {
            let this->directories = directories;
        }

        return this;
    }

    /**
     * Registers files that are "non-classes" hence need a "require". This is
     * very useful for including files that only have functions
     */
    public function registerFiles(array! files, bool merge = false) -> <Loader>
    {
        if merge {
            let this->files = array_merge(this->files, files);
        } else {
            let this->files = files;
        }

        return this;
    }

    /**
     * Register namespaces and their related directories
     */
    public function registerNamespaces(array! namespaces, bool merge = false) -> <Loader>
    {
        var preparedNamespaces, name, paths;

        let preparedNamespaces = this->prepareNamespace(namespaces);

        if merge {
            for name, paths in preparedNamespaces {
                if !isset this->namespaces[name] {
                    let this->namespaces[name] = [];
                }

                let this->namespaces[name] = array_merge(
                    this->namespaces[name],
                    paths
                );
            }
        } else {
            let this->namespaces = preparedNamespaces;
        }

        return this;
    }

    /**
     * Sets the events manager
     */
    public function setEventsManager(<ManagerInterface> eventsManager) -> void
    {
        let this->eventsManager = eventsManager;
    }

    /**
     * Sets an array of file extensions that the loader must try in each attempt
     * to locate the file
     */
    public function setExtensions(array! extensions) -> <Loader>
    {
        let this->extensions = extensions;

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
     */
    public function setFileCheckingCallback(var callback = null) -> <Loader>
    {
        if likely is_callable(callback) {
            let this->fileCheckingCallback = callback;
        } elseif callback === null {
            let this->fileCheckingCallback = function (file) {
                return true;
            };
        } else {
            throw new Exception(
                "The 'callback' parameter must be either a callable or NULL."
            );
        }

        return this;
    }

    /**
     * Unregister the autoload method
     */
    public function unregister() -> <Loader>
    {
        if this->registered === true {
            spl_autoload_unregister(
                [
                    this,
                    "autoLoad"
                ]
            );

            let this->registered = false;
        }

        return this;
    }

    protected function prepareNamespace(array! namespaceName) -> array
    {
        var localPaths, name, paths, prepared;

        let prepared = [];

        for name, paths in namespaceName {
            if typeof paths != "array" {
                let localPaths = [paths];
            } else {
                let localPaths = paths;
            }

            let prepared[name] = localPaths;
        }

        return prepared;
    }
}
