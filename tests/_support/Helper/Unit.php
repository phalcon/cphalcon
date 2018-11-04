<?php

namespace Helper;

use ReflectionClass;

// here you can define custom actions
// all public methods declared in helper class will be available in $I

class Unit extends \Codeception\Module
{
    /**
     * Calls private or protected method.
     *
     * @param string|object $obj
     * @param mixed         $method,... Method with a variable number of
     *                                  arguments
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
}
