<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Mvc\Dispatcher\Helper;

use Phalcon\Dispatcher\DispatcherInterface;
use Phalcon\Mvc\Controller;

/**
 * Dispatcher controller that returns false from afterBinding.
 *
 * Used to cover the afterBinding method return-false branch in
 * AbstractDispatcher::dispatch() (L579-580).
 */
class DispatcherTestAfterBindingReturnFalseController extends Controller
{
    public function afterBinding(DispatcherInterface $dispatcher): bool
    {
        $this->trace('afterBinding-method');

        return false;
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
