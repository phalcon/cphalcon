<?php

declare(strict_types=1);

namespace Codeception\Lib\Connector\Phalcon;

use Phalcon\Session\AdapterInterface;
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
     */
    public function __construct(array $options = null)
    {
        $this->sessionId = $this->generateId();

        if (is_array($options)) {
            $this->setOptions($options);
        }
    }

    private function generateId(): string
    {
        return md5(
            time()
        );
    }

    /**
     * Alias: Gets a session variable from an application context
     */
    public function __get(string $index)
    {
        return $this->get($index);
    }

    /**
     * Alias: Sets a session variable in an application context
     */
    public function __set(string $index, $value)
    {
        $this->set($index, $value);
    }

    /**
     * @inheritdoc
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

    private function prepareIndex(string $index): string
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
     */
    public function set(string $index, $value)
    {
        $this->memory[$this->prepareIndex($index)] = $value;
    }

    /**
     * Alias: Check whether a session variable is set in an application context
     */
    public function __isset(string $index): bool
    {
        return $this->has($index);
    }

    /**
     * @inheritdoc
     */
    public function has(string $index): bool
    {
        return isset(
            $this->memory[$this->prepareIndex($index)]
        );
    }

    /**
     * Alias: Removes a session variable from an application context
     */
    public function __unset(string $index)
    {
        $this->remove($index);
    }

    /**
     * @inheritdoc
     */
    public function remove(string $index)
    {
        unset(
            $this->memory[$this->prepareIndex($index)]
        );
    }

    /**
     * @inheritdoc
     */
    public function destroy(bool $removeData = false): bool
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
     */
    public function exists(): bool
    {
        return $this->started;
    }

    /**
     * @inheritdoc
     */
    public function getId(): string
    {
        return $this->sessionId;
    }

    /**
     * @inheritdoc
     */
    public function getName(): string
    {
        return $this->name;
    }

    /**
     * @inheritdoc
     */
    public function setName(string $name)
    {
        $this->name = $name;
    }

    /**
     * @inheritdoc
     */
    public function getOptions(): array
    {
        return $this->options;
    }

    /**
     * @inheritdoc
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
     *
     * @return AdapterInterface
     */
    public function regenerateId(bool $deleteOldSession = true): ManagerInterface
    {
        $this->sessionId = $this->generateId();

        return $this;
    }

    /**
     * @inheritdoc
     */
    public function setId(string $id)
    {
        $this->sessionId = $id;
    }

    /**
     * @inheritdoc
     */
    public function start(): bool
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
     */
    public function toArray(): array
    {
        return (array) $this->memory;
    }

    public function writeClose()
    {
    }

    /**
     * Returns the stored session handler
     */
    public function getAdapter(): SessionHandlerInterface
    {
        // TODO: Implement getAdapter() method.
    }

    /**
     * Set the handler for the session
     */
    public function setAdapter(SessionHandlerInterface $handler): ManagerInterface
    {
        // TODO: Implement setAdapter() method.
    }

    /**
     * Registers a handler with the session
     */
    public function registerHandler(SessionHandlerInterface $handler): bool
    {
        // TODO: Implement registerHandler() method.
    }
}
