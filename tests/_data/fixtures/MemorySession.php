<?php

namespace Codeception\Lib\Connector\Phalcon;

use Phalcon\Session\ManagerInterface;
use SessionHandlerInterface;

/**
 * Class MemorySession
 */
class MemorySession implements ManagerInterface
{
    /**
     * @var array
     */
    protected $memory = [];

    /**
     * @var string
     */
    protected $name;

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

    /**
     * MemorySession constructor.
     *
     * @param array|null $options
     */
    public function __construct(array $options = null)
    {
        $this->sessionId = $this->generateId();

        if (is_array($options)) {
            $this->setOptions($options);
        }
    }

    /**
     * Alias: Gets a session variable from an application context
     *
     * @param string $index
     * @return mixed
     */
    public function __get(string $index)
    {
        return $this->get($index);
    }

    /**
     * Alias: Check whether a session variable is set in an application context
     *
     * @param  string $index
     * @return bool
     */
    public function __isset(string $index)
    {
        return $this->has($index);
    }

    /**
     * Alias: Sets a session variable in an application context
     *
     * @param string $index
     * @param mixed $value
     */
    public function __set(string $index, $value)
    {
        $this->set($index, $value);
    }

    /**
     * Alias: Removes a session variable from an application context
     *
     * @param string $index
     */
    public function __unset(string $index)
    {
        $this->remove($index);
    }

    /**
     * @inheritdoc
     *
     * @param bool $removeData
     * @return bool
     */
    public function destroy($removeData = false)
    {
        if ($removeData) {
            if (!empty($this->sessionId)) {
                foreach ($this->memory as $key => $value) {
                    if (0 === strpos($key, $this->sessionId . '#')) {
                        unset($this->memory[$key]);
                    }
                }
            } else {
                $this->memory = [];
            }
        }

        $this->started = false;

        return true;
    }

    /**
     * @inheritdoc
     *
     * @return bool
     */
    public function exists(): bool
    {
        return $this->started;
    }

    /**
     * @inheritdoc
     *
     * @param string $index
     * @param mixed $defaultValue
     * @param bool $remove
     * @return mixed
     */
    public function get(string $index, $defaultValue = null, bool $remove = false)
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
     * @return array
     */
    public function getOptions(): array
    {
        return $this->options;
    }

    /**
     * @inheritdoc
     *
     * @param string $index
     * @return bool
     */
    public function has(string $index): bool
    {
        return isset($this->memory[$this->prepareIndex($index)]);
    }

    /**
     * @inheritdoc
     *
     * @param bool $deleteOldSession
     * @return \Phalcon\Session\AdapterInterface
     */
    public function regenerateId($deleteOldSession = true): ManagerInterface
    {
        $this->sessionId = $this->generateId();

        return $this;
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
     * @inheritdoc
     *
     * @param string $index
     * @param mixed $value
     */
    public function set(string $index, $value)
    {
        $this->memory[$this->prepareIndex($index)] = $value;
    }

    /**
     * @inheritdoc
     *
     * @param string $name
     */
    public function setId(string $id)
    {
        $this->sessionId = $id;
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
    public function start(): bool
    {
        if ($this->status() !== PHP_SESSION_ACTIVE) {
            $this->memory = [];
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
    public function status(): int
    {
        if ($this->isStarted()) {
            return PHP_SESSION_ACTIVE;
        }

        return PHP_SESSION_NONE;
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

    public function writeClose()
    {
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
     * @return string
     */
    private function generateId()
    {
        return md5(time());
    }

    /**
     * Returns the stored session handler
     *
     * @return \SessionHandlerInterface
     */
    public function getHandler(): SessionHandlerInterface
    {
        // TODO: Implement getHandler() method.
    }

    /**
     * Set the handler for the session
     *
     * @param \SessionHandlerInterface $handler
     *
     * @return ManagerInterface
     */
    public function setHandler(\SessionHandlerInterface $handler): ManagerInterface
    {
        // TODO: Implement setHandler() method.
    }

    /**
     * Registers a handler with the session
     *
     * @param \SessionHandlerInterface $handler
     *
     * @return bool
     */
    public function registerHandler(\SessionHandlerInterface $handler): bool
    {
        // TODO: Implement registerHandler() method.
}}
