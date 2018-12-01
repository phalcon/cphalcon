<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures;

use Phalcon\Session\AdapterInterface;

class MemorySession implements AdapterInterface
{
    /**
     * @var string
     */
    protected $name;

    /**
     * @var array
     */
    protected $memory = [];

    /**
     * @var array
     */
    protected $options = [];

    /**
     * @var string
     */
    protected $sessionId;

    /**
     * @var bool
     */
    protected $started = false;

    public function __construct(array $options = null)
    {
        $this->sessionId = $this->generateId();

        if (is_array($options)) {
            $this->setOptions($options);
        }
    }

    /**
     * @return string
     */
    private function generateId()
    {
        return md5(time());
    }

    /**
     * Alias: Gets a session variable from an application context
     *
     * @param string $index
     *
     * @return mixed
     */
    public function __get($index)
    {
        return $this->get($index);
    }

    /**
     * Alias: Sets a session variable in an application context
     *
     * @param string $index
     * @param mixed  $value
     */
    public function __set($index, $value)
    {
        $this->set($index, $value);
    }

    /**
     * @inheritdoc
     *
     * @param string $index
     * @param mixed  $defaultValue
     * @param bool   $remove
     *
     * @return mixed
     */
    public function get(string $index, $defaultValue = null)
    {
        $key = $this->prepareIndex($index);

        if (!isset($this->memory[$key])) {
            return $defaultValue;
        }

        $return = $this->memory[$key];

        if ($remove) {
            unset($this->memory[$key]);
        }

        return $return;
    }

    /**
     * @param $index
     *
     * @return string
     */
    private function prepareIndex($index)
    {
        if ($this->sessionId) {
            $key = $this->sessionId . '#' . $index;
        } else {
            $key = $index;
        }

        return $key;
    }

    /**
     * @inheritdoc
     *
     * @param string $index
     * @param mixed  $value
     */
    public function set(string $index, $value)
    {
        $this->memory[$this->prepareIndex($index)] = $value;
    }

    /**
     * Alias: Check whether a session variable is set in an application context
     *
     * @param  string $index
     *
     * @return bool
     */
    public function __isset($index)
    {
        return $this->has($index);
    }

    /**
     * @inheritdoc
     *
     * @param string $index
     *
     * @return bool
     */
    public function has(string $index): bool
    {
        return isset($this->memory[$this->prepareIndex($index)]);
    }

    /**
     * Alias: Removes a session variable from an application context
     *
     * @param string $index
     */
    public function __unset($index)
    {
        $this->remove($index);
    }

    /**
     * @inheritdoc
     *
     * @param string $index
     */
    public function remove(string $index)
    {
        unset($this->memory[$this->prepareIndex($index)]);
    }

    /**
     *
     */
    public function abort()
    {

    }

    /**
     *
     */
    public function clear()
    {

    }

    /**
     * Called internally from other session methods
     */
    public function close()
    {
        return true;
    }

    /**
     *
     */
    public function commit()
    {

    }

    /**
     * @param string $data
     *
     * @return bool
     */
    public function decode($data)
    {
        return true;
    }

    /**
     * @inheritdoc
     *
     * @param bool $removeData
     *
     * @return bool
     */
    public function destroy(string $sessionId = null): bool
    {
        if (!empty($sessionId)) {
            foreach ($this->memory as $key => $value) {
                if (0 === strpos($key, $sessionId . '#')) {
                    unset($this->memory[$key]);
                }
            }
        } else {
            $this->memory = [];
        }

        $this->started = false;

        return true;
    }

    /**
     * @return string
     */
    public function encode()
    {
        return '';
    }

    public function gc($maxLifeTime)
    {
        return 0;
    }

    /**
     * @return array
     */
    public function getCookieParams(): array
    {
        return [];
    }

    /**
     * @inheritdoc
     *
     * @return string
     */
    public function getId(): string
    {
        return $this->sessionId;
    }

    /**
     * @inheritdoc
     *
     * @return string
     */
    public function getName(): string
    {
        return $this->name;
    }

    /**
     * @inheritdoc
     *
     * @param string $name
     */
    public function setName(string $name)
    {
        $this->name = $name;
    }

    /**
     * @param string $key
     * @param null   $defaultValue
     *
     * @return string
     */
    public function getOption($key, $defaultValue = null)
    {
        return '';
    }

    /**
     * @inheritdoc
     *
     * @return array
     */
    public function getOptions(): array
    {
        return $this->options;
    }

    /**
     * @inheritdoc
     *
     * @param array $options
     */
    public function setOptions(array $options)
    {
        if (isset($options['uniqueId'])) {
            $this->sessionId = $options['uniqueId'];
        }

        $this->options = $options;
    }

    /**
     * @inheritdoc
     */
    public function open($savePath, $sessionName)
    {
        return true;
    }

    /**
     * @inheritdoc
     *
     * @param bool $deleteOldSession
     *
     * @return \Phalcon\Session\AdapterInterface
     */
    public function regenerateId(bool $deleteOldSession = null): AdapterInterface
    {
        $this->sessionId = $this->generateId();

        return $this;
    }

    /**
     * @inheritdoc
     */
    public function read($sessionId)
    {
        return "";
    }

    /**
     * @param int    $lifetime
     * @param string $path
     * @param string $domain
     * @param bool   $secure
     * @param bool   $httpOnly
     */
    public function setCookieParams(
        $lifetime,
        $path,
        $domain,
        $secure = false,
        $httpOnly = false
    ) {
    }

    /**
     * @param string $id
     *
     * @return string
     */
    public function setId($id)
    {
        $oldId = $this->sessionId;

        $this->sessionId = $id;

        return $oldId;
    }

    /**
     * @inheritdoc
     */
    public function start()
    {
        if ($this->status() !== PHP_SESSION_ACTIVE) {
            $this->memory  = [];
            $this->started = true;

            return true;
        }

        return false;
    }

    /**
     * Returns the status of the current session
     *
     * ``` php
     * <?php
     * if ($session->status() !== PHP_SESSION_ACTIVE) {
     *     $session->start();
     * }
     * ?>
     * ```
     *
     * @return int
     */
    public function status()
    {
        if ($this->isStarted()) {
            return PHP_SESSION_ACTIVE;
        }

        return PHP_SESSION_NONE;
    }

    /**
     * @inheritdoc
     *
     * @return bool
     */
    public function isStarted(): bool
    {
        return $this->started;
    }

    /**
     * Dump all session
     *
     * @return array
     */
    public function toArray()
    {
        return (array) $this->memory;
    }

    /**
     * @inheritdoc
     */
    public function write($sessionId, $data)
    {
        return true;
    }
}
