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

class GetPreviousNamespaceNameTest extends BaseDispatcher
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcDispatcherGetPreviousNamespaceName(): void
    {
        $dispatcher = $this->getDispatcher();
        $dispatcher->setActionName('forwardExternal');
        $dispatcher->dispatch();
        $this->assertSame(
            'Phalcon\Tests\Unit\Mvc\Dispatcher\Helper',
            $dispatcher->getPreviousNamespaceName()
        );
    }
}
