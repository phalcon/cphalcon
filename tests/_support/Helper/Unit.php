<?php

namespace Helper;

use Codeception\Module;
use Codeception\Specify\Config as SpecifyConfig;
use Codeception\TestInterface;
use Phalcon\Tag;

/**
 * Unit Helper
 *
 * Here you can define custom actions
 * all public methods declared in helper class will be available in $I
 *
 * @package Helper
 */
class Unit extends Module
{
    /**
     * @var \Codeception\TestInterface
     */
    protected $test;

    /**
     * Executed before each test.
     *
     * @param \Codeception\TestInterface $test
     */
    public function _before(TestInterface $test)
    {
        $this->test = $test;

        SpecifyConfig::setDeepClone(false);
    }

    /**
     * Executed after each test.
     *
     * @param \Codeception\TestInterface $test
     */
    public function _after(TestInterface $test)
    {
    }

    public function getProtectedProperty($obj, $prop)
    {
        $reflection = new \ReflectionClass($obj);
        $property = $reflection->getProperty($prop);
        $property->setAccessible(true);

        return $property->getValue($obj);
    }

    /**
     * Returns a unique file name
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     *
     * @param string $prefix A prefix for the file
     * @param string $suffix A suffix for the file
     *
     * @return string
     *
     */
    public function getNewFileName($prefix = '', $suffix = 'log')
    {
        $prefix = ($prefix) ? $prefix . '_' : '';
        $suffix = ($suffix) ? $suffix       : 'log';

        return uniqid($prefix, true) . '.' . $suffix;
    }

    /**
     * Removes a file from the system
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     *
     * @param string $path
     * @param string $fileName
     */
    public function cleanFile($path, $fileName)
    {
        $file  = (substr($path, -1, 1) != "/") ? ($path . '/') : $path;
        $file .= $fileName;

        $actual = file_exists($file);

        if ($actual) {
            unlink($file);
        }
    }

    /**
     * Runs the test for a Tag::$function with $options
     *
     * @param string  $function
     * @param mixed   $options
     * @param string  $expected
     * @param boolean $xhtml
     * @param string  $set
     */
    public function testFieldParameter($function, $options, $expected, $xhtml, $set = '')
    {
        Tag::resetInput();

        if ($xhtml) {
            Tag::setDocType(Tag::XHTML10_STRICT);
            $expected .= ' />';
        } else {
            Tag::setDocType(Tag::HTML5);
            $expected .= '>';
        }

        if ($set) {
            Tag::displayTo('x_name', 'x_value');
        }

        $actual = Tag::$function($options);

        if ($set) {
            Tag::$set('x_name', '');
        }

        $this->assertEquals($expected, $actual);
    }

    /**
     * Stores an item `$value` with `$key` on the Memcached server.
     *
     * @todo Will be removed after updating Codeception to version v2.2.5
     *
     * @param string $key
     * @param mixed $value
     * @param int $expiration
     */
    public function haveInMemcache($key, $value, $expiration = null)
    {
        /** @var \Codeception\Module\Memcache $memcache */
        $memcache = $this->getModule('Memcache');

        switch (get_class($memcache->memcache)) {
            case 'Memcache':
                $this->assertTrue($memcache->memcache->set($key, $value, null, $expiration));
                break;
            case 'Memcached':
                $this->assertTrue($memcache->memcache->set($key, $value, $expiration));
                break;
        }
    }

    /**
     * Checks item in Memcached doesn't exist or is the same as expected.
     *
     * @todo Will be removed after updating Codeception to version v2.2.5
     *
     * @param $key
     * @param $value
     */
    public function dontSeeInMemcache($key, $value = null)
    {
        /** @var \Codeception\Module\Memcache $memcache */
        $memcache = $this->getModule('Memcache');

        $actual = $memcache->memcache->get($key);
        $this->debugSection("Value", $actual);

        if (null === $value) {
            $this->assertTrue(false === $actual, "The key '$key' exists in Memcached");
        } else {
            if (false !== $actual) {
                $this->assertEquals($value, $actual, "The key '$key' exists in Memcached with the provided value");
            }
        }
    }

    /**
     * Returns the value of a given key
     *
     * @param $key
     * @return mixed
     */
    public function grabFromMemcached($key)
    {
        /** @var \Codeception\Module\Memcache $memcache */
        $memcache = $this->getModule('Memcache');

        return $memcache->memcache->get($key);
    }
}
