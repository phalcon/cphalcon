<?php

namespace Phalcon\Test\Module;

use Codeception\Module;
use Codeception\TestInterface;
use Codeception\Exception\ModuleException;

/**
 * \Phalcon\Test\Module\Libmemcached
 *
 * Connects to [memcached](http://www.memcached.org/) using _Memcached_ extension.
 * Performs a cleanup by flushing all values after each test run.
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Module
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Libmemcached extends Module
{
    /**
     * @var \Memcached
     */
    public $memcached;

    /**
     * {@inheritdoc}
     */
    protected $config = [
        'host'          => '127.0.0.1',
        'port'          => 11211,
        'weight'        => 0,
        'persistent_id' => 'phalcon_cache'
    ];

    /**
     * Triggered after module is created and configuration is loaded,
     *
     * @throws ModuleException
     */
    public function _initialize()
    {
        if (!class_exists('\Memcached')) {
            throw new ModuleException(__CLASS__, 'The memcached extension is not loaded');
        }
    }

    /**
     * Code to run after each test.
     *
     * @param TestInterface $test
     */
    public function _after(TestInterface $test)
    {
        $this->_cleanup();
    }

    public function _cleanup()
    {
        if (!$this->memcached) {
            $this->connect();
        }

        $this->memcached->flush();
        $this->memcached->quit();
    }

    /**
     * Grabs value from memcached by key.
     *
     * <code>
     * $users_count = $I->grabValueFromLibmemcached('users_count');
     * </code>
     *
     * @param mixed $key
     * @return mixed
     */
    public function grabValueFromLibmemcached($key)
    {
        if (!$this->memcached) {
            $this->connect();
        }

        $value = $this->memcached->get($key);

        if ($this->memcached->getResultCode() !== \Memcached::RES_SUCCESS) {
            $this->fail("Cannot find key '$key' in the Memcached");
        }

        $this->debugSection('Value', $value);

        return $value;
    }

    /**
     * Checks item in Memcached exists and the same as expected.
     *
     * <code>
     * // With only one argument, only checks the key exists
     * $I->seeInLibmemcached('users_count');
     *
     * // Checks a 'users_count' exists and has the value 200
     * $I->seeInLibmemcached('users_count', 200);
     * </code>
     *
     * @param mixed $key
     * @param mixed $value
     */
    public function seeInLibmemcached($key, $value = null)
    {
        if (!$this->memcached) {
            $this->connect();
        }

        $actual = $this->memcached->get($key);
        $this->debugSection('Value', $actual);

        if ($this->memcached->getResultCode() !== \Memcached::RES_SUCCESS) {
            $this->fail("Cannot find key '$key' in the Memcached");
        }

        if ($value !== null) {
            $this->assertEquals($value, $actual, "Cannot find key '$key' in the Memcached with the provided value");
        }
    }

    /**
     * Checks item in Memcached doesn't exist or is the same as expected.
     *
     * <code>
     * // With only one argument, only checks the key does not exist
     * $I->dontSeeInLibmemcached('users_count');
     *
     * // Checks a 'users_count' exists does not exist or its value is not the one provided
     * $I->dontSeeInLibmemcached('users_count', 200);
     * </code>
     *
     * @param mixed $key
     * @param mixed $value
     */
    public function dontSeeInLibmemcached($key, $value = null)
    {
        if (!$this->memcached) {
            $this->connect();
        }

        $actual = $this->memcached->get($key);
        $this->debugSection('Value', $actual);

        if ($value === null) {
            if ($this->memcached->getResultCode() !== \Memcached::RES_NOTFOUND) {
                $this->fail("The key '$key' exists in the Memcached");
            }

            return;
        }

        if ($this->memcached->getResultCode() !== \Memcached::RES_SUCCESS) {
            $this->fail("Cannot find key '$key' in the Memcached");
        }

        $this->assertEquals($value, $actual, "The key '$key' exists in Memcached with the provided value");
    }

    /**
     * Stores an item `$value` with `$key` on the Memcached server.
     *
     * <code>
     * $I->haveInLibmemcached('users_count', 200);
     * </code>
     *
     * @param string $key
     * @param mixed  $value
     * @param int    $expiration
     */
    public function haveInLibmemcached($key, $value, $expiration = null)
    {
        if (!$this->memcached) {
            $this->connect();
        }

        $this->memcached->set($key, $value, $expiration);

        if ($this->memcached->getResultCode() !== \Memcached::RES_SUCCESS) {
            $this->fail("[{$this->memcached->getResultCode()}] Unable to store the '$key' in the Memcached");
        }
    }

    /**
     * Flushes all Memcached data.
     */
    public function clearMemcache()
    {
        if (!$this->memcached) {
            $this->connect();
        }

        $this->memcached->flush();
    }

    /**
     * Connect to the Memcached.
     *
     * @throws ModuleException
     */
    protected function connect()
    {
        $this->memcached = new \Memcached($this->config['persistent_id']);

        // Persistent memcached pools need to be reconnected if getServerList() is empty
        if (empty($this->memcached->getServerList())) {
            $connect = $this->memcached->addServer(
                $this->config['host'],
                $this->config['port'],
                $this->config['weight']
            );

            if (!$connect) {
                throw new ModuleException(__CLASS__, 'Cannot connect to the Memcached server');
            }
        }
    }
}
