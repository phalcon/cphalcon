<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Helper;

use Codeception\Exception\ModuleException;
use Codeception\Module;
use Codeception\TestInterface;
use function intval;
use Memcached;

class PhalconLibmemcached extends Module
{
    /**
     * @var Memcached
     */
    public $memcached;

    /**
     * {@inheritdoc}
     */
    protected $config = [];

    /**
     * Triggered after module is created and configuration is loaded,
     *
     * @throws ModuleException
     */
    public function _initialize()
    {
        if (!class_exists('\Memcached')) {
            throw new ModuleException(
                __CLASS__,
                'The memcached extension is not loaded'
            );
        }

        $this->config = [
            'host'          => env('DATA_MEMCACHED_HOST', '127.0.0.1'),
            'port'          => env('DATA_MEMCACHED_PORT', 11211),
            'weight'        => env('DATA_MEMCACHED_WEIGHT', 0),
            'persistent_id' => 'phalcon_cache',
        ];
    }

    /**
     * Code to run after each test.
     */
    public function _after(TestInterface $test)
    {
        $this->_cleanup();
    }

    /**
     * @throws ModuleException
     */
    public function _cleanup()
    {
        if (!$this->memcached) {
            $this->connect();
        }

        $this->memcached->flush();
        $this->memcached->quit();
    }

    /**
     * Connect to the Memcached.
     *
     * @throws ModuleException
     */
    protected function connect()
    {
        $this->memcached = new Memcached(
            $this->config['persistent_id']
        );

        // Persistent memcached pools need to be reconnected if getServerList() is empty
        if (empty($this->memcached->getServerList())) {
            $connect = $this->memcached->addServer(
                $this->config['host'],
                intval($this->config['port']),
                intval($this->config['weight'])
            );

            if (!$connect) {
                throw new ModuleException(
                    __CLASS__,
                    'Cannot connect to the Memcached server'
                );
            }
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
     * Grabs value from memcached by key.
     *
     * <code>
     * $users_count = $I->grabValueFromLibmemcached('users_count');
     * </code>
     *
     * @throws ModuleException
     */
    public function grabValueFromLibmemcached($key)
    {
        if (!$this->memcached) {
            $this->connect();
        }

        $value = $this->memcached->get($key);

        if ($this->memcached->getResultCode() !== Memcached::RES_SUCCESS) {
            $this->fail("Cannot find key '$key' in the Memcached");
        }

        $this->debugSection('Value', $value);

        return $value;
    }

    /**
     * Stores an item `$value` with `$key` on the Memcached server.
     *
     * <code>
     * $I->haveInLibmemcached('users_count', 200);
     * </code>
     *
     * @param string $key
     * @param int    $expiration
     *
     * @throws ModuleException
     */
    public function haveInLibmemcached($key, $value, $expiration = null)
    {
        if (!$this->memcached) {
            $this->connect();
        }

        $this->memcached->set($key, $value, intval($expiration));

        if ($this->memcached->getResultCode() !== Memcached::RES_SUCCESS) {
            $this->fail(
                "[{$this->memcached->getResultCode()}] Unable to store the '$key' in the Memcached"
            );
        }
    }

    /**
     * Checks item in Memcached doesn't exist or is the same as expected.
     *
     * <code>
     * // With only one argument, only checks the key does not exist
     * $I->dontSeeInLibmemcached('users_count');
     *
     * // Checks a 'users_count' exists does not exist or its value is not the
     * one provided
     * $I->dontSeeInLibmemcached('users_count', 200);
     * </code>
     *
     * @throws ModuleException
     */
    public function dontSeeInLibmemcached($key, $value = null)
    {
        if (!$this->memcached) {
            $this->connect();
        }

        $actual = $this->memcached->get($key);

        $this->debugSection('Value', $actual);

        if ($value === null) {
            if ($this->memcached->getResultCode() !== Memcached::RES_NOTFOUND) {
                $this->fail("The key '$key' exists in the Memcached");
            }

            return;
        }

        if ($this->memcached->getResultCode() !== Memcached::RES_SUCCESS) {
            $this->fail("Cannot find key '$key' in the Memcached");
        }

        $this->assertSame(
            $value,
            $actual,
            "The key '$key' exists in Memcached with the provided value"
        );
    }

    /**
     * Removes an item from memcached
     *
     * <code>
     * // With only one argument, only checks the key exists
     * $I->removeFromLibmemcached('users_count');
     *
     * // Checks a 'users_count' exists and has the value 200
     * $I->seeInLibmemcached('users_count', 200);
     * </code>
     *
     * @throws ModuleException
     */
    public function removeFromLibmemcached($key)
    {
        if (!$this->memcached) {
            $this->connect();
        }

        $actual = $this->memcached->get($key);

        $this->debugSection('Value', $actual);

        if ($this->memcached->getResultCode() === Memcached::RES_SUCCESS) {
            $actual = $this->memcached->delete($key);

            $this->assertTrue(
                $actual,
                "Cannot delete key '$key' from Memcached"
            );
        }
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
     * @throws ModuleException
     */
    public function seeInLibmemcached($key, $value = null)
    {
        if (!$this->memcached) {
            $this->connect();
        }

        $actual = $this->memcached->get($key);

        $this->debugSection('Value', $actual);

        if ($this->memcached->getResultCode() !== Memcached::RES_SUCCESS) {
            $this->fail("Cannot find key '$key' in the Memcached");
        }

        if ($value !== null) {
            $this->assertSame(
                $value,
                $actual,
                "Cannot find key '$key' in the Memcached with the provided value"
            );
        }
    }
}
