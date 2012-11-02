<?php
/**
 * PhalconUnitTestCase.php
 * PhalconUnitTestCase
 *
 * Unit Test Helper
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

class PhalconUnitTestCase extends \PHPUnit_Framework_TestCase
{
    // Holds the configuration variables and other stuff
    // I can use the DI container but for tests like the Translate
    // we do not need the overhead
    protected $_config = array();

    // The Di container
    protected $_di;

    /**
     * Constructor - registers the internal autoloader
     */
    public function __construct()
    {
        spl_autoload_register(array($this, 'slashAutoloader'));
    }

    /**
     * Destructor - destroys the internal autoloader
     */
    public function __destruct()
    {
        spl_autoload_unregister(array($this, 'slashAutoloader'));
    }

    public function slashAutoloader($className)
    {
        if (file_exists(ROOT_PATH . '/app/controllers/' . $className . '.php'))
        {
            require_once ROOT_PATH . '/app/controllers/' . $className . '.php';
        }

        if (file_exists(ROOT_PATH . '/app/models/' . $className . '.php'))
        {
            require_once ROOT_PATH . '/app/models/' . $className . '.php';
        }

        $filename = str_replace('_', DIRECTORY_SEPARATOR, $className).'.php';

        if (file_exists(ROOT_PATH . '/Phalcon/' . $filename))
        {
            require_once ROOT_PATH . '/Phalcon/' . $filename;
        }
    }

    /**
     * Sets the test up by loading the DI container and other stuff
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     *
     * @return \Phalcon\DI
     */
    protected function setUp()
    {
        // Set the config up
        $this->_config = PhalconConfig::init();

        // Reset the DI container
        \Phalcon\DI::reset();

        // Instantiate a new DI container
        $di = new \Phalcon\DI();

        // Set the URL
        $di->set('url', function() {
            $url = new \Phalcon\Mvc\Url();
            $url->setBaseUri('/');
            return $url;
        });

        $this->_di = $di;
    }

    /**
     * Returns a unique file name
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     *
     * @param string $prefix    A prefix for the file
     * @param string $suffix    A suffix for the file
     *
     * @return string
     *
     */
    protected function getFileName($prefix = '', $suffix = 'log')
    {
        $prefix = ($prefix) ? $prefix . '_' : '';
        $suffix = ($suffix) ? $suffix       : 'log';

        return uniqid($prefix, true) . '.' . $suffix;
    }

    /**
     * Removes a file from the system
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     *
     * @param $path
     * @param $fileName
     */
    protected function cleanFile($path, $fileName)
    {
        $file  = (substr($path, -1, 1) != "/") ? ($path . '/') : $path;
        $file .= $fileName;

        $actual = file_exists($file);

        if ($actual)
        {
            unlink($file);
        }
    }
}