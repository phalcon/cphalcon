<?php

namespace Phalcon\Test\Integration\Mvc\Dispatcher\Helper;

use Exception;
use Phalcon\Dispatcher\DispatcherInterface;
use Phalcon\Events\Event;

/**
 * \Phalcon\Test\Integration\Mvc\Dispatcher\Helper\DispatcherListener
 * Early listener for all dispatch events.
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link          http://www.phalcon.io
 * @author        Andres Gutierrez <andres@phalcon.io>
 * @author        Nikolaos Dimopoulos <nikos@phalcon.io>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalcon.io
 * so that we can send you a copy immediately.
 */
class DispatcherListener
{
    /**
     * @var array
     */
    protected $trace = [];

    public function clearTrace()
    {
        $this->trace = [];
    }

    public function getTrace()
    {
        return $this->trace;
    }

    public function compare(array $eventTraces)
    {
        return $this->trace === $eventTraces;
    }

    public function beforeDispatchLoop(Event $event, DispatcherInterface $dispatcher)
    {
        $this->trace('beforeDispatchLoop');
    }

    public function trace($text)
    {
        $this->trace[] = $text;
    }

    public function beforeDispatch(Event $event, DispatcherInterface $dispatcher)
    {
        $this->trace('beforeDispatch');
    }

    public function beforeExecuteRoute(Event $event, DispatcherInterface $dispatcher)
    {
        $this->trace('beforeExecuteRoute');
    }

    public function afterInitialize(Event $event, DispatcherInterface $dispatcher)
    {
        $this->trace('afterInitialize');
    }

    public function afterExecuteRoute(Event $event, DispatcherInterface $dispatcher)
    {
        $this->trace('afterExecuteRoute');
    }

    public function afterDispatch(Event $event, DispatcherInterface $dispatcher)
    {
        $this->trace('afterDispatch');
    }

    public function afterDispatchLoop(Event $event, DispatcherInterface $dispatcher)
    {
        $this->trace('afterDispatchLoop');
    }

    public function beforeNotFoundAction(Event $event, DispatcherInterface $dispatcher)
    {
        $this->trace('beforeNotFoundAction');
    }

    public function beforeException(Event $event, DispatcherInterface $dispatcher, Exception $exception)
    {
        $this->trace(
            'beforeException: ' . $exception->getMessage()
        );
    }
}
