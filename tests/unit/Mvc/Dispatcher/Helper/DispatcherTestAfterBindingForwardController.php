<?php

namespace Phalcon\Tests\Unit\Mvc\Dispatcher\Helper;

use Phalcon\Dispatcher\DispatcherInterface;
use Phalcon\Mvc\Controller;

/**
 * Dispatcher controller whose afterBinding() method forwards once.
 *
 * Used to cover the afterBinding method forward branch in
 * AbstractDispatcher::dispatch() (L586-587).
 */
class DispatcherTestAfterBindingForwardController extends Controller
{
    private bool $forwarded = false;

    public function afterBinding(DispatcherInterface $dispatcher): bool
    {
        $this->trace('afterBinding-method');

        if (!$this->forwarded) {
            $this->forwarded = true;
            $dispatcher->forward(['action' => 'index2']);
        }

        return true;
    }

    public function index2Action(): void
    {
        $this->trace('index2Action');
    }

    public function indexAction(): void
    {
        $this->trace('indexAction');
    }

    public function initialize(): void
    {
        $this->trace('initialize-method');
    }

    protected function trace(string $text): void
    {
        $this->getDI()->getShared('dispatcherListener')->trace($text);
    }
}
