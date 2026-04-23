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

namespace Phalcon\Tests\Unit\Cli\Dispatcher;

use Phalcon\Cli\Dispatcher;
use Phalcon\Di\FactoryDefault\Cli as DiFactoryDefault;
use Phalcon\Tests\AbstractUnitTestCase;

/**
 * Class IsFinishedTest extends AbstractUnitTestCase
 */
final class IsFinishedTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testCliDispatcherIsFinished(): void
    {
        $dispatcher = new Dispatcher();
        $dispatcher->setDefaultNamespace('Phalcon\Tests\Support\Tasks');
        $dispatcher->setDI(new DiFactoryDefault());

        $actual = $dispatcher->isFinished();
        $this->assertFalse($actual);

        $dispatcher->dispatch();

        $actual = $dispatcher->isFinished();
        $this->assertTrue($actual);
    }
}
