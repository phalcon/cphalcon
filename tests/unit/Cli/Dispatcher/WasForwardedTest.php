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

final class WasForwardedTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testCliDispatcherWasForwarded(): void
    {
        $dispatcher = new Dispatcher();
        $dispatcher->setDefaultNamespace('Phalcon\Tests\Support\Tasks');
        $dispatcher->setDI(new DiFactoryDefault());

        $actual = $dispatcher->wasForwarded();
        $this->assertFalse($actual);

        $dispatcher->forward(
            [
                'task'   => 'echo',
                'action' => 'main',
            ]
        );

        $dispatcher->dispatch();

        $actual = $dispatcher->wasForwarded();
        $this->assertTrue($actual);
    }
}
