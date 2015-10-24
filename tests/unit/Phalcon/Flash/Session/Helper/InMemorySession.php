<?php
/**
 * InMemorySession.php
 * \Phalcon\Flash\Session\Helper\InMemorySession
 *
 * in memory implementation for Phalcon\Session\Adapter
 *
 * PhalconPHP Framework
 *
 * @author    Iván Guillén <zeopix@gmail.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\unit\Phalcon\Flash\Session\Helper;

use Phalcon\Session\AdapterInterface;

class InMemorySession implements AdapterInterface
{
    /**
     * @var array
     */
    protected $memory;

    /**
     * @var array
     */
    protected $options;

    /**
     * @var string
     */
    protected $sessionId;

    /**
     * @var string
     */
    protected $name;

    /**
     * @var bool
     */
    protected $started;

    public function __construct()
    {
        $this->sessionId = $this->generateId();
        $this->started = false;
    }

    /**
     * @inheritdoc
     */
    public function start()
    {
        $this->memory = [];
        $this->started = true;
    }
    /**
     * @inheritdoc
     */
    public function setOptions(array $options)
    {
        $this->options = $options;
    }

    /**
     * @inheritdoc
     */
    public function getOptions()
    {
        return $this->options;
    }
    /**
     * @inheritdoc
     */
    public function get($index, $defaultValue = null)
    {
        return $this->memory[$index] ?: $defaultValue;
    }

    /**
     * @inheritdoc
     */
    public function set($index, $value)
    {
        $this->memory[$index] = $value;
    }

    /**
     * @inheritdoc
     */
    public function has($index)
    {
        return isset($this->memory[$index]);
    }
    /**
     * Removes a session variable from an application context
     *
     * @param string $index
     */
    public function remove($index)
    {
        if (isset($this->memory[$index])) {
            unset($this->memory[$index]);
        }
    }
    /**
     * Returns active session id
     *
     * @return string
     */
    public function getId()
    {
        return $this->sessionId;
    }
    /**
     * Check whether the session has been started
     *
     * @return bool
     */
    public function isStarted()
    {
        return $this->started;
    }

    /**
     * Destroys the active session
     *
     * @inheritdoc
     */
    public function destroy($removeData = NULL)
    {
        if ($removeData) {
            $this->memory = [];
        }
        $this->started = false;
    }

    /**
     *
     * @inheritdoc
     */
    public function regenerateId($deleteOldSession = true)
    {
        $this->sessionId = $this->generateId();
        return $this;
    }

    /**
     * @param string $name
     */
    public function setName($name)
    {
        $this->name = $name;
    }

    /**
     * @return string
     */
    public function getName()
    {
        return $this->name;
    }

    /**
     * @return string
     */
    private function generateId()
    {
        return md5(time());
    }
}
