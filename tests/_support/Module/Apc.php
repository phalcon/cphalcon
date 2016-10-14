<?php

namespace Phalcon\Test\Module;

use Codeception\TestInterface;
use Codeception\Exception\ModuleException;
use Codeception\Module as CodeceptionModule;

/**
 * \Phalcon\Test\Module\Apc
 *
 * Note: Performs a cleanup by flushing all values after each test run.
 *
 * @link http://php.net/manual/en/intro.apcu.php
 * @link http://php.net/manual/en/intro.apc.php
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Module
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Apc extends CodeceptionModule
{
    /**
     * Code to run before each test.
     *
     * @param TestInterface $test
     * @throws ModuleException
     */
    public function _before(TestInterface $test)
    {
        if (!extension_loaded('apc') && !extension_loaded('apcu')) {
            throw new ModuleException(
                __CLASS__,
                'The APC(u) extension not loaded.'
            );
        }

        if (!ini_get('apc.enabled') || (PHP_SAPI === 'cli' && !ini_get('apc.enable_cli'))) {
            throw new ModuleException(
                __CLASS__,
                'The "apc.enable_cli" parameter must be set to "On".'
            );
        }
    }

    /**
     * Code to run after each test.
     *
     * @param TestInterface $test
     */
    public function _after(TestInterface $test)
    {
        $this->clear();
    }

    /**
     * Grabs value from APC(u) by key.
     *
     * Example:
     *
     * ``` php
     * <?php
     * $users_count = $I->grabValueFromApc('users_count');
     * ?>
     * ```
     *
     * @param string|array $key
     * @return mixed
     */
    public function grabValueFromApc($key)
    {
        $value = $this->fetch($key);
        $this->debugSection('Value', $value);

        return $value;
    }

    /**
     * Checks item in APC(u) exists and the same as expected.
     *
     * Examples:
     *
     * ``` php
     * <?php
     * // With only one argument, only checks the key exists
     * $I->seeInApc('users_count');
     *
     * // Checks a 'users_count' exists and has the value 200
     * $I->seeInApc('users_count', 200);
     * ?>
     * ```
     *
     * @param $key
     * @param $value
     */
    public function seeInApc($key, $value = null)
    {
        if (null === $value) {
            $this->assertTrue($this->exists($key), "Cannot find key '$key' in APC(u).");
        } else {
            $actual = $this->grabValueFromApc($key);
            $this->assertEquals($value, $actual, "Cannot find key '$key' in APC(u) with the provided value.");
        }
    }

    /**
     * Checks item in APC(u) doesn't exist or is the same as expected.
     *
     * Examples:
     *
     * ``` php
     * <?php
     * // With only one argument, only checks the key does not exist
     * $I->dontSeeInApc('users_count');
     *
     * // Checks a 'users_count' exists does not exist or its value is not the one provided
     * $I->dontSeeInApc('users_count', 200);
     * ?>
     * ```
     *
     * @param $key
     * @param $value
     */
    public function dontSeeInApc($key, $value = null)
    {
        if (null === $value) {
            $this->assertFalse($this->exists($key), "The key '$key' exists in APC(u).");
        } else {
            $actual = $this->grabValueFromApc($key);
            if (false !== $actual) {
                $this->assertEquals($value, $actual, "The key '$key' exists in APC(u) with the provided value.");
            }
        }
    }

    /**
     * Stores an item `$value` with `$key` on the APC(u).
     *
     * @param string $key
     * @param mixed $value
     * @param int $expiration
     */
    public function haveInApc($key, $value, $expiration = null)
    {
        $this->assertTrue($this->store($key, $value,$expiration));
    }

    /**
     * Clears the APC(u) cache
     */
    public function flushApc()
    {
        // Returns TRUE always
        $this->clear();
    }

    /**
     * Clears the APC(u) cache.
     *
     * @return bool
     */
    protected function clear()
    {
        if (function_exists('apcu_clear_cache')) {
            return apcu_clear_cache();
        }

        return apc_clear_cache('user');
    }

    /**
     * Checks if entry exists
     *
     * @param mixed $key
     *
     * @return bool|\string[]
     */
    protected function exists($key)
    {
        if (function_exists('apcu_exists')) {
            return apcu_exists($key);
        }

        return apc_exists($key);
    }

    /**
     * Fetch a stored variable from the cache
     *
     * @param string $key
     *
     * @return mixed
     */
    protected function fetch($key)
    {
        $success = false;

        if (function_exists('apcu_fetch')) {
            $data = apcu_fetch($key, $success);
        } else {
            $data = apc_fetch($key, $success);
        }

        $this->debugSection('Fetching a stored variable', $success ? 'OK' : 'FAILED');

        return $data;
    }

    /**
     * Cache a variable in the data store.
     *
     * @param mixed $key
     * @param mixed $var
     * @param int $ttl
     *
     * @return array|bool
     */
    protected function store($key, $var, $ttl = 0)
    {
        if (function_exists('apcu_store')) {
            return apcu_store($key, $var, $ttl);
        }

        return apc_store($key, $var, $ttl);
    }
}
