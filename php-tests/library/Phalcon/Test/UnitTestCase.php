<?php
/**
 * UnitTestCase.php
 * Phalcon_Test_UnitTestCase
 *
 * Unit Test Helper
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2015 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Test;

abstract class UnitTestCase extends \PHPUnit_Framework_TestCase
{
    // Holds the configuration variables and other stuff
    // I can use the DI container but for tests like the Translate
    // we do not need the overhead
    protected $config = array();

    // The Di container
    protected $di;

    /**
     * Sets the test up by loading the DI container and other stuff
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-30
     *
     * @return \Phalcon\DI
     */
    protected function setUp()
    {
        $this->checkExtension('phalcon');

        // Set the config up
        $this->config = Config::init();

        // Reset the DI container
        \Phalcon\DI::reset();

        // Instantiate a new DI container
        $di = new \Phalcon\DI();

        // Set the URL
        $di->set(
            'url',
            function () {
                $url = new \Phalcon\Mvc\Url();
                $url->setBaseUri('/');
                return $url;
            }
        );

        $di->set(
            'escaper',
            function () {
                return new \Phalcon\Escaper();
            }
        );

        $this->di = $di;
    }

    /**
     * Checks if a particular extension is loaded and if not it marks
     * the tests skipped
     *
     * @param $extension
     */
    public function checkExtension($extension)
    {
        if (!extension_loaded($extension)) {
            $this->markTestSkipped("Warning: {$extension} extension is not loaded");
        }
    }

    /**
     * Returns a unique file name
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
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

        if ($actual) {
            unlink($file);
        }
    }
}