<?php

namespace Phalcon\Tests\Unit\Mvc\Dispatcher\Helper;

use Exception;
use Phalcon\Mvc\Controller;

/**
 * @author        Andres Gutierrez <andres@phalcon.io>
 * @author        Nikolaos Dimopoulos <nikos@phalcon.io>
 */
class DispatcherTestAfterExecuteRouteExceptionController extends Controller
{
    public function afterExecuteRoute()
    {
        $this->trace('afterExecuteRoute-method');

        throw new Exception('afterExecuteRoute exception occurred');
    }

    public function beforeExecuteRoute()
    {
        $this->trace('beforeExecuteRoute-method');
    }

    public function indexAction()
    {
        $this->trace('indexAction');
    }

    public function initialize()
    {
        $this->trace('initialize-method');
    }

    /**
     * Add tracing information into the current dispatch tracer
     */
    protected function trace($text)
    {
        $this->getDI()->getShared('dispatcherListener')->trace($text);
    }
}
