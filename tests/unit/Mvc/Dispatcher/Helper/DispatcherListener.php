<?php

namespace Phalcon\Tests\Unit\Mvc\Dispatcher\Helper;

use Exception;
use Phalcon\Dispatcher\DispatcherInterface;
use Phalcon\Events\Event;

/**
 * @author        Andres Gutierrez <andres@phalcon.io>
 * @author        Nikolaos Dimopoulos <nikos@phalcon.io>
 */
class DispatcherListener
{
    /**
     * @var array
     */
    protected $trace = [];

    public function afterDispatch(Event $event, DispatcherInterface $dispatcher)
    {
        $this->trace('afterDispatch');
    }

    public function afterDispatchLoop(Event $event, DispatcherInterface $dispatcher)
    {
        $this->trace('afterDispatchLoop');
    }

    public function afterExecuteRoute(Event $event, DispatcherInterface $dispatcher)
    {
        $this->trace('afterExecuteRoute');
    }

    public function afterInitialize(Event $event, DispatcherInterface $dispatcher)
    {
        $this->trace('afterInitialize');
    }

    public function beforeDispatch(Event $event, DispatcherInterface $dispatcher)
    {
        $this->trace('beforeDispatch');
    }

    public function beforeDispatchLoop(Event $event, DispatcherInterface $dispatcher)
    {
        $this->trace('beforeDispatchLoop');
    }

    public function beforeException(Event $event, DispatcherInterface $dispatcher, Exception $exception)
    {
        $this->trace(
            'beforeException: ' . $exception->getMessage()
        );
    }

    public function beforeExecuteRoute(Event $event, DispatcherInterface $dispatcher)
    {
        $this->trace('beforeExecuteRoute');
    }

    public function beforeNotFoundAction(Event $event, DispatcherInterface $dispatcher)
    {
        $this->trace('beforeNotFoundAction');
    }

    public function clearTrace()
    {
        $this->trace = [];
    }

    public function compare(array $eventTraces)
    {
        return $this->trace === $eventTraces;
    }

    public function getTrace()
    {
        return $this->trace;
    }

    public function trace($text)
    {
        $this->trace[] = $text;
    }
}
