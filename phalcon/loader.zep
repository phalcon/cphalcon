
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
 * Phalcon\Loader
 *
 * This component helps to load your project classes automatically based on some conventions
 *
 *<code>
 * //Creates the autoloader
 * $loader = new Phalcon\Loader();
 *
 * //Register some namespaces
 * $loader->registerNamespaces(array(
 *   'Example\Base' => 'vendor/example/base/',
 *   'Example\Adapter' => 'vendor/example/adapter/',
 *   'Example' => 'vendor/example/'
 * ));
 *
 * //register autoloader
 * $loader->register();
 *
 * //Requiring this class will automatically include file vendor/example/adapter/Some.php
 * $adapter = Example\Adapter\Some();
 *</code>
 */
class Loader implements Phalcon\Events\EventsAwareInterface
{

	protected _eventsManager = null;

	protected _foundPath = null;

	protected _checkedPath = null;

	protected _prefixes = null;

	protected _classes = null;

	protected _extensions;

	protected _namespaces = null;

	protected _directories = null;

	protected _registered = false;

	/**
	 * Phalcon\Loader constructor
	 */
	public function __construct()
	{
		let this->_extensions = ["php"];
	}

	/**
	 * Sets the events manager
	 *
	 * @param Phalcon\Events\ManagerInterface eventsManager
	 */
	public function setEventsManager(<Phalcon\Events\ManagerInterface> eventsManager)
	{
		let this->_eventsManager = eventsManager;
	}

	/**
	 * Returns the internal event manager
	 *
	 * @return Phalcon\Events\ManagerInterface
	 */
	public function getEventsManager() -> <Phalcon\Events\ManagerInterface>
	{
		return this->_eventsManager;
	}

	/**
	 * Sets an array of extensions that the loader must try in each attempt to locate the file
	 *
	 * @param array extensions
	 * @return Phalcon\Loader
	 */
	public function setExtensions(extensions) -> <Phalcon\Loader>
	{
		if typeof extensions != "array" {
			throw new Phalcon\Loader\Exception('Parameter extensions must be an array');
		}
		let this->_extensions = extensions;
		return this;
	}

	/**
	 * Return file extensions registered in the loader
	 *
	 * @return boolean
	 */
	public function getExtensions()
	{
		return this->_extensions;
	}

	/**
	 * Register namespaces and their related directories
	 *
	 * @param array namespaces
	 * @param boolean merge
	 * @return Phalcon\Loader
	 */
	public function registerNamespaces(namespaces, merge=false){

		if typeof namespaces != "array" {
			throw new Phalcon\Loader\Exception('Parameter namespaces must be an array');
		}

		if merge {
			let currentNamespaces = this->_namespaces;
			if (is_array(currentNamespaces)) {
				let mergedNamespaces = array_merge(currentNamespaces, namespaces);
			} else {
				let mergedNamespaces = namespaces;
			}
			let this->_namespaces = mergedNamespaces;
		} else {
			let this->_namespaces = namespaces;
		}

		return this;
	}

	/**
	 * Return current namespaces registered in the autoloader
	 *
	 * @param array
	 */
	public function getNamespaces()
	{
		return this->_namespaces;
	}

	/**
	 * Register directories on which "not found" classes could be found
	 *
	 * @param array prefixes
	 * @param boolean merge
	 * @return Phalcon\Loader
	 */
	public function registerPrefixes(prefixes, merge=false)
	{
		if typeof prefixes != "array" {
			throw new Phalcon\Loader\Exception('Parameter prefixes must be an array');
		}
		if merge {
			let currentPrefixes = this->_prefixes;
			if typeof currentPrefixes == "array" {
				let mergedPrefixes = array_merge(currentPrefixes, prefixes);
			} else {
				let mergedPrefixes = prefixes;
			}
			let this->_prefixes = mergedPrefixes;
		} else {
			let this->_prefixes = prefixes;
		}
		return this;
	}

	/**
	 * Return current prefixes registered in the autoloader
	 *
	 * @param array
	 */
	public function getPrefixes()
	{
		return this->_prefixes;
	}

	/**
	 * Register directories on which "not found" classes could be found
	 *
	 * @param array directories
	 * @param boolean merge
	 * @return Phalcon\Loader
	 */
	public function registerDirs(directories, boolean merge=false) -> <Phalcon\Loader>
	{
		if typeof directories != "array" {
			throw new Phalcon\Loader\Exception('Parameter directories must be an array');
		}
		if merge {
			let currentDirectories = this->_directories;
			if typeof currentDirectories == "array" {
				let mergedDirectories = array_merge(currentDirectories, directories);
			} else {
				let mergedDirectories = directories;
			}
			let this->_directories = mergedDirectories;
		} else {
			let this->_directories = directories;
		}
		return this;
	}

	/**
	 * Return current directories registered in the autoloader
	 *
	 * @param array
	 */
	public function getDirs()
	{
		return this->_directories;
	}

	/**
	 * Register classes and their locations
	 *
	 * @param array classes
	 * @param boolean merge
	 * @return Phalcon\Loader
	 */
	public function registerClasses(classes, merge=false) -> <Phalcon\Loader>
	{
		if typeof classes != "array" {
			throw new Phalcon\Loader\Exception('Parameter classes must be an array');
		}
		if merge {
			let currentClasses = this->_classes;
			if typeof currentClasses == "array" {
				let mergedClasses = array_merge(currentClasses, classes);
			} else {
				let mergedClasses = classes;
			}
			let this->_classes = mergedClasses;
		} else {
			let this->_classes = classes;
		}
		return this;
	}

	/**
	 * Return the current class-map registered in the autoloader
	 *
	 * @param array
	 */
	public function getClasses()
	{
		return this->_classes;
	}

	/**
	 * Register the autoload method
	 *
	 * @return Phalcon\Loader
	 */
	public function register()
	{
		if this->_registered === false {
			spl_autoload_register([this, "autoLoad"]);
			let this->_registered = true;
		}
		return this;
	}

	/**
	 * Unregister the autoload method
	 *
	 * @return Phalcon\Loader
	 */
	public function unregister()
	{
		if this->_registered === true {
			spl_autoload_unregister([this, "autoLoad"]);
			let this->_registered = false;
		}
		return this;
	}

	/**
	 * Makes the work of autoload registered classes
	 *
	 * @param string className
	 * @return boolean
	 */
	public function autoLoad(string! className)
	{

		let eventsManager = this->_eventsManager;
		if typeof eventsManager == "object" {
			eventsManager->fire("loader:beforeCheckClass", this, className);
		}

		/**
		 * First we check for static paths for classes
		 */
		let classes = this->_classes;
		if typeof classes == "array" {
			if fetch filePath, classes[className] {
				if typeof eventsManager == "object" {
					let this->_foundPath = filePath;
					eventsManager->fire("loader:pathFound", this, filePath);
				}
				//require filePath;
				return true;
			}
		}

		let extensions = this->_extensions;

		let ds = DIRECTORY_SEPARATOR,
			namespaceSeparator = "\\";

		/**
		 * Checking in namespaces
		 */
		let namespaces = this->_namespaces;
		if typeof namespaces == "array" {

			for nsPrefix, directory in namespaces {

				/**
				 * The class name must start with the current namespace
				 */
				if starts_with(className, nsPrefix) {

					/**
					 * Get the possible file path
					 */
					let fileName = phalcon_possible_autoload_filepath(nsPrefix, className, ds);
					if fileName {

						/**
						 * Add a trailing directory separator if the user forgot to do that
						 */
						let fixedDirectory = phalcon_fix_path(directory, ds);

						for extension in extensions {

							let filePath = fixedDirectory . fileName . "." . extension;

							/**
							 * Check if a events manager is available
							 */
							if typeof eventsManager == "object" {
								let this->_checkedPath = filePath;
								eventsManager->fire("loader:beforeCheckPath", this);
							}

							/**
							 * This is probably a good path, let's check if the file exist
							 */
							if file_exists(filePath) {

								if typeof eventsManager == "object" {
									let this->_foundPath = filePath;
									eventsManager->fire("loader:pathFound", this, filePath);
								}

								/**
								 * Simulate a require
								 */
								//require filePath;

								/**
								 * Return true mean success
								 */
								return true;
							}
						}
					}
				}
			}
		}

		/**
		 * Checking in prefixes
		 */
		let prefixes = this->_prefixes;
		if typeof prefixes == "array" {

			for prefix, directory in prefixes {

				/**
				 * The class name starts with the prefix?
				 */
				if starts_with(className, prefix) {

					/**
					 * Get the possible file path
					 */
					let fileName = phalcon_possible_autoload_filepath(prefix, className, ds, "_");

					if fileName {

						/**
						 * Add a trailing directory separator if the user forgot to do that
						 */
						let fixedDirectory = phalcon_fix_path(directory, ds);

						for extension in extensions {

							let filePath = fixedDirectory . fileName . "." . extension;

							if typeof eventsManager == "object" {
								let this->_checkedPath = filePath;
								eventsManager->fire("loader:beforeCheckPath", this, filePath);
							}

							if file_exists(filePath) {

								/**
								 * Call 'pathFound' event
								 */
								if typeof eventsManager == "object" {
									let this->_foundPath = filePath;
									eventsManager->fire("loader:pathFound", this, filePath);
								}

								//require filePath;
								return true;
							}
						}
					}
				}
			}
		}

		/**
		 * Change the pseudo-separator by the directory separator in the class name
		 */
		let dsClassName = str_replace("_", ds, className);

		/**
		 * And change the namespace separator by directory separator too
		 */
		let nsClassName = str_replace("\\", ds, dsClassName);

		/**
		 * Checking in directories
		 */
		let directories = this->_directories;
		if typeof directories == "array" {

			for directory in directories {

				/**
				 * Add a trailing directory separator if the user forgot to do that
				 */
				let fixedDirectory = phalcon_fix_path(directory, ds);

				for extension in extensions {

					/**
					 * Create a possible path for the file
					 */
					let filePath = fixedDirectory . nsClassName . "." . extension;

					if typeof eventsManager == "object" {
						let this->_checkedPath = filePath;
						eventsManager->fire("loader:beforeCheckPath", this, filePath);
					}

					/**
					 * Check in every directory if the class exists here
					 */
					if file_exists(filePath) {

						/**
						 * Call 'pathFound' event
						 */
						if typeof eventsManager == "object" {
							let this->_foundPath = filePath;
							eventsManager->fire("loader:pathFound", this, filePath);
						}

						/**
						 * Simulate a require
						 */
						//require filePath;

						/**
						 * Return true meaning success
						 */
						return true;
					}
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
		 * Cannot find the class return false
		 */
		return false;
	}

	/**
	 * Get the path when a class was found
	 *
	 * @return string
	 */
	public function getFoundPath()
	{
		return this->_foundPath;
	}

	/**
	 * Get the path the loader is checking for a path
	 *
	 * @return string
	 */
	public function getCheckedPath()
	{
		return this->_checkedPath;
	}

}
