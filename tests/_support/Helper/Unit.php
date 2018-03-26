<?php

namespace Helper;

use Phalcon\Tag;
use ReflectionClass;
use Codeception\Module;
use Codeception\TestInterface;
use Codeception\Specify\Config as SpecifyConfig;

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
     * @var TestInterface
     */
    protected $test;

    /**
     * Executed before each test.
     *
     * @param TestInterface $test
     */
    public function _before(TestInterface $test)
    {
        $this->test = $test;

        SpecifyConfig::setDeepClone(false);
    }

    public function getProtectedProperty($obj, $prop)
    {
        $reflection = new ReflectionClass($obj);

        $property = $reflection->getProperty($prop);
        $property->setAccessible(true);

        return $property->getValue($obj);
    }

    public function setProtectedProperty($obj, $prop, $value)
    {
        $reflection = new ReflectionClass($obj);

        $property = $reflection->getProperty($prop);
        $property->setAccessible(true);
        $property->setValue($obj, $value);

        $this->assertEquals($value, $property->getValue($obj));
    }

    /**
     * Calls private or protected method.
     *
     * @param string|object $obj
     * @param mixed         $method,... Method with a variable number of arguments
     *
     * @return mixed
     * @throws \ReflectionException
     */
    public function callProtectedMethod($obj, $method)
    {
        $reflectionClass = new ReflectionClass($obj);

        $reflectionMethod = $reflectionClass->getMethod($method);
        $reflectionMethod->setAccessible(true);

        if (!is_object($obj)) {
            $obj = $reflectionClass->newInstanceWithoutConstructor();
        }

        // $obj, $method
        $args = array_slice(func_get_args(), 2);
        array_unshift($args, $obj);

        return call_user_func_array([$reflectionMethod, 'invoke'], $args);
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
}
