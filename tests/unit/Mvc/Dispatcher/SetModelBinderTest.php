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

use Phalcon\Mvc\Model\Binder;
use Phalcon\Mvc\Model\BinderInterface;
use Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\BaseDispatcher;

class SetModelBinderTest extends BaseDispatcher
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcDispatcherSetModelBinder(): void
    {
        $dispatcher  = $this->getDispatcher();
        $modelBinder = new Binder();
        $dispatcher->setModelBinder($modelBinder);
        $this->assertInstanceOf(
            BinderInterface::class,
            $dispatcher->getModelBinder()
        );
    }
}
