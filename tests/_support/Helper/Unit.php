<?php

namespace Helper;

use Codeception\Module;
use function file_exists;
use function is_file;
use PHPUnit\Framework\SkippedTestError;
use ReflectionClass;
use ReflectionException;
use function unlink;

// here you can define custom actions
// all public methods declared in helper class will be available in $I

class Unit extends Module
{
    /**
     * Calls private or protected method.
     *
     * @param string|object $obj
     *
     * @throws ReflectionException
     */
    public function callProtectedMethod($obj, string $method)
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

        return call_user_func_array(
            [$reflectionMethod, 'invoke'],
            $args
        );
    }

    /**
     * Checks if an extension is loaded and if not, skips the test
     *
     * @param string $extension The extension to check
     */
    public function checkExtensionIsLoaded(string $extension)
    {
        if (true !== extension_loaded($extension)) {
            $this->skipTest(
                sprintf(
                    "Extension '%s' is not loaded. Skipping test",
                    $extension
                )
            );
        }
    }

    /**
     * Throws the SkippedTestError exception to skip a test
     *
     * @param string $message The message to display
     */
    public function skipTest(string $message)
    {
        throw new SkippedTestError($message);
    }

    /**
     * Returns a unique file name
     *
     * @param string $prefix A prefix for the file
     * @param string $suffix A suffix for the file
     *
     * @since  2014-09-13
     *
     * @author Nikos Dimopoulos <nikos@phalcon.io>
     */
    public function getNewFileName(string $prefix = '', string $suffix = 'log'): string
    {
        $prefix = ($prefix) ? $prefix . '_' : '';
        $suffix = ($suffix) ? $suffix : 'log';

        return uniqid($prefix, true) . '.' . $suffix;
    }

    public function safeDeleteFile(string $filename)
    {
        if (true === file_exists($filename) && true === is_file($filename)) {
            unlink($filename);
        }
    }

    /**
     * @throws ReflectionException
     */
    public function getProtectedProperty($obj, $prop)
    {
        $reflection = new ReflectionClass($obj);

        $property = $reflection->getProperty($prop);

        $property->setAccessible(true);

        return $property->getValue($obj);
    }

    /**
     * @throws ReflectionException
     */
    public function setProtectedProperty($obj, $prop, $value)
    {
        $reflection = new ReflectionClass($obj);

        $property = $reflection->getProperty($prop);

        $property->setAccessible(true);
        $property->setValue($obj, $value);

        $this->assertSame(
            $value,
            $property->getValue($obj)
        );
    }
}
