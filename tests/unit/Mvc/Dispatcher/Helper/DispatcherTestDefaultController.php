<?php

namespace Phalcon\Tests\Unit\Mvc\Dispatcher\Helper;

use Exception;
use Phalcon\Mvc\Controller;

/**
 * @author        Andres Gutierrez <andres@phalcon.io>
 * @author        Nikolaos Dimopoulos <nikos@phalcon.io>
 */
class DispatcherTestDefaultController extends Controller
{
    public const RETURN_VALUE_INT    = 5;
    public const RETURN_VALUE_STRING = 'string';

    public function afterExecuteRoute()
    {
        $this->trace('afterExecuteRoute-method');
    }

    public function beforeExecuteRoute()
    {
        $this->trace('beforeExecuteRoute-method');
    }

    public function exceptionAction()
    {
        $this->trace('exceptionAction');

        throw new Exception('An exception occurred.');
    }

    public function forwardExternalAction()
    {
        $this->trace('forwardExternalAction');

        $di = $this->getDI();

        $dispatcher = $di->getShared('dispatcher');

        $dispatcher->forward(
            [
                'controller' => 'dispatcher-test-default-two',
                'action'     => 'index',
            ]
        );
    }

    public function forwardLocalAction()
    {
        $this->trace('forwardLocalAction');

        $di = $this->getDI();

        $dispatcher = $di->getShared('dispatcher');

        $dispatcher->forward(
            [
                'action' => 'index2',
            ]
        );
    }

    public function index2Action()
    {
        $this->trace('index2Action');
    }

    public function indexAction()
    {
        $this->trace('indexAction');
    }

    public function initialize()
    {
        $this->trace('initialize-method');
    }

    public function multiplyAction($a, $b)
    {
        $this->trace('multiplyAction');

        return (int)$a * (int)$b;
    }

    public function returnIntAction()
    {
        $this->trace('returnIntAction');

        return self::RETURN_VALUE_INT;
    }

    public function returnStringAction()
    {
        $this->trace('returnStringAction');

        return self::RETURN_VALUE_STRING;
    }

    /**
     * Add tracing information into the current dispatch tracer
     */
    protected function trace($text)
    {
        $this->getDI()->getShared('dispatcherListener')->trace($text);
    }
}
