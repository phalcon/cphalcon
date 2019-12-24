# 0.9.0b2
 - Support for reusable records. A relation can be marked to cache queried records in memory to speedup getting related records
 - Added 'elseif' statement to Volt
 - Changed static key in Volt's 'cache' to any valid expression
 - Added Phalcon\Logger\Adapter\Syslog and Phalcon\Logger\Adapter\Stream to Phalcon\Logger
 - Added Phalcon\Logger\Multiple to send logs to multiples adapters
 - Added formatters abstraction to Phalcon\Logger, now including: Phalcon\Logger\Formatter\Line, Phalcon\Logger\Formatter\Json and Phalcon\Logger\Formatter\Syslog
 - Added Phalcon\Annotations\Adapter\Files to Phalcon\Annotations, this adapter stores annotations in PHP files

# 0.9.0b1
 - Added Phalcon\Annotations, a general purpose component to read annotations from docblocks
 - Phalcon\Mvc\Model now supports saving related records using magic methods with a unique call to 'save'
 - Adding autoescaping option to Phalcon\Tag
 - Added andWhere/orWhere to Phalcon\Mvc\Model\Criteria
 - Added passing an HTTP body to the Phalcon\Http\Response's constructor
 - Phalcon\Mvc\View is now able to pass variables to the views using magic methods
 - Support for slice with filter and built-in syntax in Volt
 - Added magic methods in the ORM to find/findFirst by a single field
 - Improved XSS protection in Phalcon\Tag
 - Implemented queuing events with priorities in Phalcon\Events
 - Implemented collecting of returned responses in Phalcon\Events
 - Added toArray method to Phalcon\Mvc\Model\Resultset classes
 - Added hydration modes to Phalcon\Mvc\Model\Resultset (HYDRATE_RECORDS, HYDRATE_ARRAYS, HYDRATE_OBJECTS)

# 0.8.0b1
 - Improved Phalcon\Escaper, this component provides contextual escaping of different kinds of texts (CSS, Javascript, URL, HTML Attributes etc)
 - Added serialization of Mvc\Collection instances
 - Added Phalcon\Mvc\View::setLayout to change the layout instead of looking for a controller with the same name as the latest controller dispatched
 - Now is possible to pass an option called 'options' to any of the Phalcon\Db\Adapter\Pdo adapters to set extra
 PDO options in the connection
 - Removed filtering of keys from Phalcon\Cache\Backend\File
 - Support for creating groups of routes using Phalcon\Router\Route\Group
 - Added Phalcon\Mvc\Micro middleware events
 - Implemented virtual scopes in Phalcon\Mvc\View

# 0.8.0a2
 - Added support for behaviors in the ORM including: Phalcon\Mvc\Model\Behavior\Timestampable and Phalcon\Mvc\Model\Behavior\SoftDelete
 - Improved serialization of Mvc\Model instances and complex resultsets
 - Added an option to change the layouts directory and partials directory in Phalcon\Mvc\View
 - Added an option to disable an specific level of rendering in Phalcon\Mvc\View
 - Added Phalcon\Mvc\Model::setup to globally enable/disable specific features in the ORM
 - Added Phalcon\Db::setup to globally enable/disable specific features in the database component
 - Added Phalcon\Mvc\Model\Resultset::delete to delete every complete object returned in a resultset using a transaction
 - Added Phalcon\Mvc\Model\Resultset::update to update every complete object returned in a resultset using a transaction
 - Added support for converters in Phalcon\Mvc\Router
 - Added Phalcon\Mvc\View::getRender to return contents of a template into a string
 - Added methods to support HTTP method PATCH
 - Now Phalcon\Mvc\Model uses the last part of a namespaced class name as source name
 - Phalcon\Di now implements ArrayAccess to get/set services
 - Phalcon\Mvc\Micro now implements ArrayAccess to get services from the related services container
 - Improved building of complex service definitions in the DI
 - Added toArray method to Phalcon\Mvc\Model instances
 - Added autoescape mode in Volt

# 0.8.0a1
 - Removed unnecessary intermediate zvals when retrieving array items reducing overall memory comsumption
 - Removed unnecessary intermediate zvals when retrieving object members reducing overall memory comsumption
 - Removed PH_CHECK constant making simpler calling functions and methods internally
 - Added Phalcon\Text::increment, Phalcon\Text::random, Phalcon\Text::lower, Phalcon\Text::upper, Phalcon\Text::startsWith, Phalcon\Text::endsWith
 - Added Phalcon\Config::merge to merge recursively a configuration with another one
 - Added Phalcon\Config::toArray method to recursively convert an object to an array
 - Improved Volt runtime error/syntax error messages including always line and file
 - Added Phalcon\Security providing a set of functions to improve the security in Phalcon applications like bcrypt password hashing and CSRF protection
 - Added Phalcon\Mvc\View\Engine\Volt\Compiler::addFunction to register user functions
 - Added Phalcon\Mvc\View\Engine\Volt\Compiler::addFilter to register user filters
 - Added Phalcon\Mvc\Model\Relation as class for model relationships
 - Added '[' and ']' as delimiters to escape PHQL reserverd words
 - Reduced memory usage in PHQL parser/tokenizer
 - Added support for aliasing of model relationships in Phalcon\Mvc\Model
 - Relationships in Models are now case insensitive to be compliant with the PHP standard
 - Looking for a relationship in the models manager now performs a search in O(1) order
 - Added "cache" statement in Volt to cache view fragments
 - Added "do" statement to Volt to execute an expression without printing its evaluated value
 - Added "include" statement to Volt to perform a statical include of other views in compiling time
 - Added an internal method cache to speed up overall execution
 - Reduced memory allocation when reading/writing properties from objects
 - Added missing Phalcon\Mvc\Collection::getMessages() and Phalcon\Mvc\Collection::appendMessage
 - Added Phalcon\Config::get method to obtain a value from the configuration object setting a default value
 - Added an optional default value to Phalcon\Session\Adapter::get if this method returns a null value
 - Added OO methods to Phalcon\Session\Bag::get
 - Added an optional default value to Phalcon\Session\Bag::get if this method returns a null value
 - Added multiple inheritance and two-way replacement of blocks in Volt
 - Added evaluation of "tests" to Volt
 - Added support to call methods and read properties in sub-objects in Volt
 - Volt now checks if a variable name is a registered service and injects it to the views
 - The "For" statement in Volt now supports get the current key and add an optional if evaluation
 - Added support to read PHP constants in Volt
 - Added "prefix" option to Volt, allowing prefixing the resulting compiled paths
 - Now registerAutoloader in module definitions receives the services container (DI) as first parameter
 - Fixed skipAttributes methods in Phalcon\Mvc\Model
 - Fixed use of muliples databases in the ORM
 - Fixed use of a common events manager databases in the ORM
 - Now Phalcon\Mvc\Router can be configured to remove extra slashes passed in the URI
 - In Phalcon\Mvc\Router the default route is '/' when none is giving


# [0.7.0](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v0.7.0) (2012-12-04)
 - Now the namespace can be set in a path of the route and it will passed automatically to the dispatcher
 - Implementing URL generation based on routes without regular expressions
 - Now is possible register a template engine in Phalcon\Mvc\View with an anonymous function
 - Passing 'compileAlways' => true as option for Volt makes that the templates will be always compiled instead of checking if they have changes
 - Now Phalcon\Cache\Backend adapters return false in the "exists" method if the cache has expired
 - Fixed bug in Phalcon\Db\Result\Pdo::seek when using bind parameters

# 0.7.0b1
 - Implemented a fast way to retrieve object's members without adding a memory frame
 - Now Phalcon\Mvc\Dispatcher checks for methods beforeExecuteRoute and afterExecuteRoute in the controller handler
 - Added phalcon_start_with to check if a zval string starts with other string avoiding substrs in PHP userland
 - Added interfaces to most classes helping the developer to easily create component replacements and add new adapters/classes
 - Implemented interfaces on their own components
 - Implemented event propagation, event cancelation and ability to stop events in EventsManager
 - Added Phalcon\Dispatcher::getDefaultNamespace
 - Added a $merge parameter to every Phalcon\Loader strategy to merge current values with a new array
 - Implemented registering services as "always shared"
 - Now Phalcon\Mvc\Model::save, Phalcon\Mvc\Model::create, Phalcon\Mvc\Model::update receives an array to assign the model's attributes from it
 - Support for UTF-8/UTF-16 characters on 32 bit platforms for PHQL/Volt parsers
 - Support for custom schemas in PHQL
 - Now is possible pass bound parameters to Phalcon\DB::fetchOne and Phalcon\Db::fetchAll
 - Implemented independent column map for models and a full escaping system for columns/tables/schemas according to the database system conventions
 - Added a $merge parameter to Phalcon\Mvc\Application::registerModules to merge new modules with current ones
 - Phalcon\Mvc\Application now allows registering a module using an anonymous function
 - Added Phalcon\Mvc\Model\Query\Builder aiding in the creation of PHQL queries using an OO interface
 - Support for COUNT(DISTINCT x) syntax in PHQL
 - Allowing user-defined messages in most Phalcon\Mvc\Model\Validators
 - Now Phalcon\Mvc\Model\Validator\StringLength uses mb_strlen when it is available
 - Allowed pass a URI manually to Phalcon\Mvc\Micro::handle()
 - Fixed missing json_encode filter in Volt
 - Moving cache implementation from Phalcon\Mvc\Model to Phalcon\Mvc\Model\Query, this allows caching both simple and complex resultsets
 - Added Phalcon\Paginator\Adapter\QueryBuilder to use a PHQL Query Builder as source of data
 - Added adapter for Oracle databases in Phalcon\Db

# [0.6.1](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v0.6.1) (2012-11-15)
 - Fixed bug in Phalcon\Mvc\Micro's not-found handler
 - Fixed bug reading named-parameters with quantifiers in Phalcon\Mvc\Router
 - Now named-routes are processed without use regular expressions
 - Now $this->view->disable() disables the auto-rendering mode completely
 - Added Phalcon\Mvc\View::enable that re-enables the auto-rendering mode
 - Added Phalcon\Cache\Backend::stop() to stop the cache without store anything into the backend
 - Fixed bug in Phalcon\Mvc\View that saves an empty cached content when using a cache
 - Implemented Phalcon\Db::FETCH_OBJ to return objects instead of arrays

# 0.6.0
 - Added functions version, version_id, date and time to Volt
 - PHQL OFFSET complete implementation
 - Fixed bug in Phalcon\Mvc\Collection::find and Phalcon\Mvc\Collection::findFirst

# 0.6.0b1
 - Removing unnecessary duplications in zval PHALCON_GET_FOREACH_VALUE
 - Merging PHALCON_INIT_NVAR into PHALCON_GET_FOREACH_KEY
 - Added HTML/XHTML document type support in Phalcon\Tag
 - Added "exists" method to every backend in Phalcon\Cache\Backend
 - Now is required pass true as parameter to Phalcon\Http\Request::getClientAddress if the user want to check the client address in the $_SERVER['HTTP_X_FORWARDED_FOR'] header
 - Removed unnecessary duplication of function names when calling function and methods
 - Now Phalcon can call functions from the PHP userspace without use call_user_func_array/call_user_func increasing performance
 - Added beforeException event triggered from Phalcon\Dispatcher before launch an exception allowing injecting code before launch a real exception modifing the behavior of the component
 - Now is possible attach listeners directly to specific events in Phalcon\Event\Managers
 - Added Phalcon\Http\Request::get and Phalcon\Http\Request::has to read/check values from $_REQUEST
 - Added Phalcon\Cache\Backend\Mongo that uses a MongoDB collection as backend
 - Added options (compiled path, compiled separator, stat) for Volt

# 0.6.0a1
 - Concatenation on the same variable is now faster by using realloc instead of zval duplication
 - Some internal macros like PHALCON_INIT_VAR now produce fewer C-code making the extension lighter
 - Removed initialization of the memory stack frame when isn't needed
 - Inlining of scope locating functions to make read/write on objects faster
 - Array joins are now faster because a zval needle isn't needed anymore
 - Implemented fast copy/ctor to return_value reducing the overall memory usage
 - Added Phalcon\Tag::friendlyTitle to create friendly titles
 - Added a new C-based template engine highly coupled with Phalcon called Volt
 - Registered Phalcon\Mvc\Model\Transaction\Manager in Phalcon\Di\FactoryDefault as 'transactionManager'
 - Added Phalcon\Escaper to add contextual escaping of different kinds of texts
 - Registered Phalcon\Escaper in Phalcon\Di\FactoryDefault as 'escaper'
 - Phalcon\Tag now caches resolved services such as 'url' and 'dispatcher' making the view generation faster
 - Added support to the OFFSET clause in PHQL
 - Optimized Phalcon\Mvc\Model\Metadata to use fewer memory when using a high number of tables
 - Changed the use of strpos by phalcon_memnstr to search for strings into other strings reducing unnecessary zval allocations
 - Added faster camelize/uncamelize functions
 - Now a model can implement the method metaData to return the model meta-data insteaf of leave Phalcon do it automatically
 - Phalcon\Mvc\Model::skipAttributes allows setting a group of attributes that must be skipped from the INSERT/UPDATE SQL generation
 - Added Phalcon\Mvc\Collection to manage non-structured data models, for example: MongoDB

# 0.5.2
 - Fixed bug in Phalcon\Mvc\Model::_exists making PHQL inserts fail
 - Fixed bug passing extra parameters to Phalcon\Mvc\Model magic methods

# 0.5.1
 - Fixed bug in Phalcon\Loader producing that pathFound event wasn't triggered
 - Added throwing exception in Phalcon\Loader when trying to write in a read only file
 - Now Phalcon\Loader replaces _ by DIRECTORY_SEPARATOR in most strategies
 - Fixed bug in Phalcon\Mvc\Model\Resultset::seek that doesn't allow to paginate results in Phalcon\Paginator
 - Fixed bug in Phalcon\Mvc\Dispatcher that doesn't throws an exception when an infinite forward is produced
 - PDO error mode was changed to PDO::ERRMODE_EXCEPTION producing exceptions instead of silent error messages
 - Fixed wrong precedence in PHQL operators
 - Fixed bug that makes that the correct value for SERIAL columns wasn't filled for PostgreSQL
 - Added an extra parameter "data" to an event triggering in Phalcon\Events allowing getting more information about certain event
 - Added an extra parameter to Phalcon\Db::query and Phalcon\Db::execute to bind parameters by their data type
 - Added recognition of the related sequence for PostgreSQL when inserting data into tables with SERIAL columns Phalcon\Mvc\Model
 - Phalcon\Db\Adapter\*::describeColumns try to find the best bind param type for every column
 - Added bindType to Phalcon\Db\Column to know what its best bind param to cast according to its data type
 - Added getDefaultValue() to Phalcon\Db\Adapter\* in order the best value to insert in an auto-increment or serial column
 - Added bindTypes param to Phalcon\Mvc\Model::find and Phalcon\Mvc\Model::findFirst
 - Due to the new agressive type-casting when binding parameters, Phalcon\Mvc\Model isn't capable anymore of generate reliable automatic keys for the cache
 - Fixed bug that makes actions and events implemented in a parent class innaccessibles for Phalcon
 - Now Phalcon\Text::camelize checks for underscores and dashes
 - Added Phalcon\Mvc\Model::getRelated to return related relation models on namespaced models

# 0.5.0
- Added Phalcon\CLI components to create CLI applications
- Added SQLite support

# 0.5.0a4
- Removed support for Twig and Mustache
- Added PhalconQL (PHQL), a high level query language directly engaged with the Phalcon\Mvc\Model component
- Multiples refactorings removing unused code
- Added support to match routes on a determined individual or a set of HTTP methods
- Added support for named parameters without requiring a regular expression in Phalcon\Mvc\Router
- Added Phalcon\Mvc\Router\Route to encapsulate the information of a route
- Added Phalcon\Mvc\Micro to create applications in a micro-framework style
- Added Phalcon\Di\FactoryDefault that has the Phalcon Components registered as Default

# 0.5.0a3
 - Added Phalcon\Di as dependency injector container
 - Added Phalcon\Events as events management component
 - Removed Phalcon\Router\Rewrite
 - Phalcon\Router\Regex moved to Phalcon\Mvc\Router
 - Phalcon\Dispatcher moved to Phalcon\Mvc\Dispatcher
 - Phalcon\Mvc\Dispatcher::forward now only accepts an array parameter
 - Dispatcher events has been removed (beforeDispatch and afterDispatch) in favor of the new EventsManager component
 - Controller look up based on controllersDir has been removed in favor of autoloaders
 - Phalcon\Controller moved to Phalcon\Mvc\Controller
 - Phalcon\Model moved to Phalcon\Mvc\Model
 - Phalcon\Transaction moved to Phalcon\Mvc\Model\Transaction
 - Removed Phalcon\Db\Pool
 - ModelsManager look up based on modelsDir has been removed in favor of autoloaders
 - Phalcon\Db\Pdo::describeColumns return an array of Phalcon\Db\Columns
 - Removed Phalcon\Controller\Front
 - Most "Factories" and "Singletons" implementations were removed
 - Phalcon\Mvc\Model\Metadata adapters must be instantiated directly

# 0.5.0a2
 - Removed memory leaks when reading class constants
 - Replaced the database native adapters by PDO

# 0.5.0a1
 - Classes are now registered as PHP namespaces.
 - Improved stability running Phalcon with PHP versions lower or equal than 5.3.3
 - Thousand of unnecessary intermediate variables were removed improving stability
 - Phalcon now performs a reduced number of copy-on-write checks
 - Added class modifiers like Abstract or Final to Phalcon classes
 - Fixed memory leaks generated when throwing internal exceptions
 - Removed deprecated experimental function and method calls

# 0.4.4
 - Fixed problem with Phalcon_Session functions not registered

# 0.4.3
 - Fixed problem with partials, that removed any output previously generated
 - Added Phalcon_Session::destroy
 - Fixed memory leaks generated when throwing internal exceptions

# 0.4.2
 - Added support for PostgreSQL database
 - Phalcon_View is now fully integrated with Phalcon_Cache
 - Dropped unnecessary registration of arguments for exception classes
 - Dropped unnecessary zval copy-on-write checks
 - Fixed double registration of Phalcon_Config in MODULE_MINIT
 - Fixed method definition of __destruct adding ZEND_ACC_DTOR
 - Fixed bug in Phalcon_Model_Query making that the component does not apply quoting properly
 - Fixed segmentation fault in Phalcon_Loader
 - Fixed memory leaks generated when retreiving some static properties
 - Replaced PHP's str_replace for a slightly faster once
 - Improved stability working with static properties in multi-threaded web servers
 - Fixed bug in integration between Phalcon_Db and Phalcon_Logger

# 0.4.1
- Complex concatenations are now made without a lot of intermediate zvals improving the overall memory usage
- Improved throwing of simple exceptions with a unique string parameter
- Added Phalcon_Dispatcher::setParam to change a routing parameter
- Added Phalcon_Request::redirect to make HTTP redirections from controllers
- Phalcon_Model_* is now completely decoupled from Phalcon_Controller_Front
- Phalcon_Model_Base::_createSQLSelectMulti and Phalcon_Model_Base::_createSQLSelectOne has been joined into a single method
- Added Phalcon_Db::bindParams in order to avoid SQL injections
- Added "bind" parameter to Phalcon_Model_Base::find, Phalcon_Model_Base::findFirst, Phalcon_Model_Base::count,
Phalcon_Model_Base::sum, etc. to avoid SQL injections
- The database adapter Phalcon_Db_Adapter_Mysql was moved from mysql extension to mysqli
- Added Phalcon_Db_Result_Mysql to encapsulate the resultset functionality. Those methods were before in Phalcon_Db.
- Fixed bug rebuilding symbol table in Phalcon_View_Engine_Php::render
- Added Phalcon_View::pick to choose a view to show different than last-controller/last-action
- Now is possible to define routes with a shortened syntax in Regex
- Phalcon is now using Compare-and-Swap to reduce the number of writes to cache adapters like files or APC, also avoiding the unnecesary register of shutdown functions

# 0.4.0
- Fixed possible segmentation fault when releasing memory of zval strings that has constant values
- Fixed bug avoiding that auto-globals will jit-initialized inside Phalcon on some old versions of PHP
- Moved zval separation to phalcon_array_update_*
- Moved zval separation to phalcon_array_append_*
- Moved zval constructor to phalcon_array_update_*
- Implemented functions to avoid use arrays of zvals parameters for static and method calls
- Removed error reporting silence from the extension
- Removed thousands of unnecessary referencing/deferencing vars when calling functions/methods
- Moved multi-dimensional array updates to fewer complex functions
- Moved access to static properties to a function that controls possible invalid access to non existent properties
- Fixed memory leaks in Phalcon_Cache and Phalcon_Transaction_Manager
- Added virtual foreign keys to Phalcon_Model (ORM)
- Implemented the possibility to serialize Phalcon_Model_Resultset objects
- Implemented the possibility to access Phalcon_Model_Resultset as an array of objects
- Added Phalcon_Cache_Backend_Apc, Phalcon_Cache_Backend_Memcache, Phalcon_Cache_Frontend_None and Phalcon_Cache_Frontend_Data
- Added Phalcon_Request::hasPost and Phalcon_Request::hasQuery
- Added parameter "persistent" to Phalcon_Db allowing creating persistent connections
- Added alphanum to Phalcon_Filter to filter strings allowing filtering only alpha-numeric characters
- Refactored Phalcon_Tag::select and Phalcon_Tag::selectStatic, now uses the same code in Phalcon_Tag_Select
- Added Phalcon_Tag::checkField helper to create input[type="checkbox"] tags
- Added Phalcon_View::getParams to recover extra params sent to the request
- Sometimes when Phalcon throws an internal exception or E_ERROR the memory stack is not properly cleaned
  producing an unstable state, this situation was fixed
- Phalcon_View was refactored to allow other templating engines like Mustache or Twig
- Added Phalcon_Translate for multi-lingual translation messages based on adapters
- Added calculation functions to Phalcon_Model: count, sum, average, minimum and maximum
- Dispatcher exceptions now throws a HTTP 404 Not found status
- Added Phalcon_Router_Regex to define routes based on regular expressions
- Renamed Phalcon_Request::getBestQualityCharset() to Phalcon_Request::getBestCharset()
- Added Phalcon_Request::getBestLanguage()

# 0.3.5
 - Most of throw exception process has been rewrriten to use fewer instructions
 - Super global initialization is now slightly fast
 - Fixed bug in Phalcon_Db::close
 - Added logging capabilities to Phalcon_Db
 - Added Phalcon_Model_Metadata::getIdentityField allowing to know the identity (auto_increment) field
 - Added DDL and DML methods to Phalcon_Db
 - Added Phalcon_Db_Column to describe table columns
 - Added Phalcon_Db_Index to describe table indexes
 - Added Phalcon_Db_Reference to describe table references (foreign keys)

# 0.3.4
 - Fixed wrong implementation in Phalcon_Tag::javascriptInclude
 - Added Phalcon_Cache_Frontend_Output
 - Renamed Phalcon_Db_Mysql to Phalcon_Db_Adapter_Mysql
 - Renamed Phalcon_Cache_Adapter_File to Phalcon_Cache_Frontend_File
 - Added Phalcon_Request::setRawHeader
 - Added Phalcon_Paginator_Adapter_Array
 - Fixed bugs in model paginator
 - Added Phalcon_Tag::hiddenField
 - Added Phalcon_Tag::fileField
 - Added Phalcon_Loader to autoload classes based on some conventions
 - Added Phalcon_Db_Profiler to profile database operations and determine posible bottlenecks
 - Added methods to query table metadata: Phalcon_Db::describeTable, Phalcon_Db::describeIndexes and Phalcon_Db::describeReferences
 - Fixed segmentation fault in Phalcon_Db::tableExists
 - Fixed memory leak in Phalcon_Paginator
 - Adding Zend Thread Safety (ZTS) support to Phalcon Memory Manager

# 0.3.3
 - Added Phalcon_Tag::setDefault as an alias for Phalcon_Tag::displayTo
 - Added Phalcon_View::setVar as an alias for Phalcon_View::setParamToView
 - Added ACL managment with in-memory lists
 - Fixed segfaults on methods with array optional parameters
 - Fixed segfaults on some isset
 - Added built-in model attributes validators
 - Added Phalcon_ACL to manage access lists
 - Added missing Phalcon_Tag::passwordField

# 0.3.2
 - Fixed separation of super globals by mistake causing segmentation faults
 - Support for compilation on Visual C++ 6.0
 - Fixed segmentation faults when required parameters are not given for most methods

# 0.3.1
 - Phalcon garbage collector incrementally releases memory allocated after the end of a particular execution trace reducing memory fragmentation.

# 0.3.0
 - Refactored many code patterns as C macros, the total base code was reduced by about 8000 lines of code less.
 - Most function calls was rewriten to avoid any string length counting by avoiding potential use of strlen. Functions and methods names have fixed string lengths improving general performance. This improvement was also implemented for static string concatenation.
 - We have implemented some kind of Register Allocation to take advantage of processor registers. However, compiler will choose best register allocations when it compiles the extension.
 - Support for PHP 5.4. A number of issues when running Phalcon under PHP 5.4 were identified and corrected.
 - In some cases memory was copied without need when updating internal arrays, them were fixed.
 - A function cache was included to avoid potential function lookups on internal HashTables. This cache stores internal pointers to functions low level code improving performance.

# 0.2.6
 - Fixed segfault when reading _SESSION superglobal when no session_start has been made
 - Added Phalcon_Cache with adapter File
 - Added method Phalcon_Model_Manager::getHasOneRecords
