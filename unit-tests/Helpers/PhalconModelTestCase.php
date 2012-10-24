<?php
/**
 * PhalconModelTestCase.php
 * PhalconModelTestCase
 *
 * Model Test Helper
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2012 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Eduar Carvajal <eduar@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@niden.net>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

class PhalconModelTestCase extends PhalconUnitTestCase
{
    /**
     * Constructor - registers the internal autoloader
     */
    public function __construct()
    {
        spl_autoload_register(array($this, 'internalAutoloader'));
    }

    /**
     * Destructor - destroys the internal autoloader
     */
    public function __destruct()
    {
        spl_autoload_unregister(array($this, 'internalAutoloader'));
    }

    public function internalAutoloader($className)
    {
        if (file_exists(ROOT_PATH . '/apps/models/' . $className . '.php')) {
            require_once ROOT_PATH . '/apps/models/' . $className . '.php';
        }
    }

    /**
     * Sets the test up by loading the DI container and other stuff
     *
     * @param string $dbType Sets the database type for the test
     *
     * @return Phalcon\DI
     */
    protected function setUp($dbType = 'mysql')
    {
        $di = parent::setUp();

        // Set Models manager
        $di->set('modelsManager', function() {
            return new \Phalcon\Mvc\Model\Manager();
        });

        // Set Models metadata
        $di->set('modelsMetadata', function() {
            return new \Phalcon\Mvc\Model\Metadata\Memory();
        });

        // Set the connection to MySQL

        $di->set('db', function() use ($dbType) {
            $config = PhalconConfig::init();
            return new \Phalcon\Db\Adapter\Pdo\Mysql($config['db'][$dbType]);
        });

        return $di;

    }
}