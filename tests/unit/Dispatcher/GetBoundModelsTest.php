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

final class GetBoundModelsTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDispatcherGetBoundModels(): void
    {
        $dispatcher = new Dispatcher();

        // No binder set yet → empty array.
        $this->assertSame([], $dispatcher->getBoundModels());

        // With a binder, the dispatcher delegates to its
        // getBoundModels(). A fresh binder has no bound models.
        $dispatcher->setModelBinder(new Binder());
        $this->assertSame([], $dispatcher->getBoundModels());
    }
}
