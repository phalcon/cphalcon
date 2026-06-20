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
use Phalcon\Tests\AbstractUnitTestCase;
use ReflectionProperty;

final class IsFinishedTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDispatcherIsFinished(): void
    {
        $dispatcher = new Dispatcher();

        $this->assertFalse($dispatcher->isFinished());

        $property = new ReflectionProperty($dispatcher, 'finished');
        $property->setValue($dispatcher, true);

        $this->assertTrue($dispatcher->isFinished());
    }
}
