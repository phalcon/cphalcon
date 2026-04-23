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

use Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\BaseDispatcher;

class SetDefaultControllerTest extends BaseDispatcher
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcDispatcherSetDefaultController(): void
    {
        $dispatcher = $this->getDispatcher();
        $dispatcher->setDefaultController('dispatcher-test-default');
        $dispatcher->setControllerName('');
        $dispatcher->dispatch();
        $this->assertSame('dispatcher-test-default', $dispatcher->getControllerName());
    }
}
