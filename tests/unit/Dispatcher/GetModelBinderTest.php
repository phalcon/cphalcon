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

namespace Phalcon\Tests\Unit\Dispatcher;

use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\Model\Binder;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetModelBinderTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDispatcherGetModelBinder(): void
    {
        $dispatcher = new Dispatcher();

        $this->assertNull($dispatcher->getModelBinder());

        $binder = new Binder();
        $dispatcher->setModelBinder($binder);

        $this->assertSame($binder, $dispatcher->getModelBinder());
    }
}
