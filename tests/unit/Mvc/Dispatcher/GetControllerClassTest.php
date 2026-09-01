<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Mvc\Dispatcher;

use Foo\IndexController;
use Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\BaseDispatcher;

class GetControllerClassTest extends BaseDispatcher
{
    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testMvcDispatcherGetControllerClass(): void
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->setNamespaceName('Foo');
        $dispatcher->setControllerName('');
        $dispatcher->setActionName('');

        $this->assertEquals(
            'Foo',
            $dispatcher->getNamespaceName()
        );

        $this->assertEquals(
            '',
            $dispatcher->getControllerName()
        );

        $this->assertEquals(
            '',
            $dispatcher->getActionName()
        );

        $this->assertEquals(
            IndexController::class,
            $dispatcher->getControllerClass()
        );
    }
}
