<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Fixtures\Di;

use Phalcon\Di\Exception;
use Phalcon\Di\Traits\DiExceptionsTrait;

/**
 * Trait DiExceptionsTrait
 *
 * @package Phalcon\Di\Traits
 */
class DiExceptionsProxy
{
    use DiExceptionsTrait;

    /**
     * @param int   $position
     * @param array $argument
     *
     * @throws Exception
     */
    private function proxyCheckArgumentTypeExists(int $position, array $argument): void
    {
        $this->checkArgumentTypeExists($position, $argument);
    }

    /**
     * @param string $name
     *
     * @throws Exception
     */
    private function checkClassExists(string $name): void
    {
        $this->checkClassExists($name);
    }

    /**
     * @param array $definition
     *
     * @throws Exception
     */
    private function checkClassNameExists(array $definition): void
    {
        /**
         * The class name is required
         */
        if (true !== isset($definition['className'])) {
            throw new Exception(
                'Invalid service definition. Missing "className" parameter'
            );
        }
    }

    /**
     * @param mixed $arguments
     * @param int   $position
     *
     * @throws Exception
     */
    private function checkMethodArgumentsIsArray($arguments, $position): void
    {
        if (true !== is_array($arguments)) {
            throw new Exception(
                'Call arguments must be an array on position ' .
                (string) $position
            );
        }
    }

    /**
     * @param mixed $method
     * @param int   $position
     *
     * @throws Exception
     */
    private function checkMethodCallPosition($method, $position): void
    {
        /**
         * The call parameter must be an array of arrays
         */
        if (true !== is_array($method)) {
            throw new Exception(
                'Method call must be an array on position ' .
                (string) $position
            );
        }
    }

    /**
     * @param array $method
     * @param int   $position
     *
     * @throws Exception
     */
    private function checkMethodMethodExists(array $method, $position): void
    {
        /**
         * A param 'method' is required
         */
        if (true !== isset($method['method'])) {
            throw new Exception(
                'The method name is required on position ' .
                (string) $position
            );
        }
    }

    /**
     * @param mixed $instance
     *
     * @throws Exception
     */
    private function checkPropertiesInjectionConstruct($instance): void
    {
        if (true !== is_object($instance)) {
            throw new Exception(
                "The definition has properties injection " .
                "parameters but the constructor didn't return an instance"
            );
        }
    }

    /**
     * @param mixed $property
     * @param int   $position
     *
     * @throws Exception
     */
    private function checkPropertyIsArray($property, $position): void
    {
        /**
         * The call parameter must be an array of arrays
         */
        if (true !== is_array($property)) {
            throw new Exception(
                "Property must be an array on position " .
                (string) $position
            );
        }
    }

    /**
     * @param array $property
     * @param int   $position
     *
     * @throws Exception
     */
    private function checkPropertyNameExists(array $property, $position): void
    {
        /**
         * A param 'name' is required
         */
        if (true !== isset($property['name'])) {
            throw new Exception(
                'The property name is required on position ' .
                (string) $position
            );
        }
    }

    /**
     * @param array $property
     * @param int   $position
     *
     * @throws Exception
     */
    private function checkPropertyValueExists(array $property, $position): void
    {
        /**
         * A param 'value' is required
         */
        if (true !== isset($property['value'])) {
            throw new Exception(
                'The property value is required on position ' .
                (string) $position
            );
        }
    }

    /**
     * @param array  $argument
     * @param string $name
     * @param int    $position
     *
     * @throws Exception
     */
    private function checkServiceParameters(
        array $argument,
        string $name,
        int $position
    ): void {
        if (true !== isset($argument[$name])) {
            throw new Exception(
                'Service "' . $name . '" is required in parameter ' .
                'on position ' . (string) $position
            );
        }
    }

    /**
     * @param mixed $instance
     *
     * @throws Exception
     */
    private function checkSetterInjectionConstructor($instance): void
    {
        if (true !== is_object($instance)) {
            throw new Exception(
                "The definition has setter injection " .
                "parameters but the constructor didn't return an instance"
            );
        }
    }

    /**
     * @param mixed $parameters
     *
     * @throws Exception
     */
    private function checkSetterInjectionParameters($parameters): void
    {
        if (true !== is_array($parameters)) {
            throw new Exception(
                'Setter injection parameters must be an array'
            );
        }
    }

    /**
     * @param string $name
     *
     * @throws Exception
     */
    private function throwCannotResolveService(string $name): void
    {
        throw new Exception(
            "Service '" . $name . "' cannot be resolved"
        );
    }

    /**
     * @param string $name
     *
     * @throws Exception
     */
    private function throwServiceNotFound(string $name): void
    {
        throw new Exception(
            "Service '" . $name .
            "' was not found in the dependency injection container"
        );
    }

    /**
     * @param string $method
     *
     * @throws Exception
     */
    private function throwUndefinedMethod(string $method): void
    {
        /**
         * The method doesn't start with set/get throw an exception
         */
        throw new Exception(
            "Call to undefined method or service '" . $method . "'"
        );
    }

    /**
     * @param int $position
     *
     * @throws Exception
     */
    private function throwUnknownServiceInParameter(int $position): void
    {
        /**
         * Unknown parameter type
         */
        throw new Exception(
            'Unknown service type in parameter on ' .
            'position ' . $position
        );
    }
}
