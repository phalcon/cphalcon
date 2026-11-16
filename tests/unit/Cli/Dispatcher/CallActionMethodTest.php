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

namespace Phalcon\Tests\Unit\Cli\Dispatcher;

use Phalcon\Cli\Dispatcher;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\Tasks\MainTask;
use Phalcon\Tests\Support\Traits\ErrorHandlerTrait;

final class CallActionMethodTest extends AbstractUnitTestCase
{
    use ErrorHandlerTrait;

    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-24
     */
    public function testCliDispatcherCallActionMethod(): void
    {
        $dispatcher = new Dispatcher();

        $task = new MainTask();

        $returnedValue = $dispatcher->callActionMethod(
            $task,
            'helloAction',
            [
                'Sid',
                '.',
            ]
        );

        $expected = 'Hello Sid.';
        $actual   = $returnedValue;
        $this->assertSame($expected, $actual);
    }

    /**
     * An action that cannot be called gives a warning and null, the same as
     * cphalcon.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/815
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    public function testCliDispatcherCallActionMethodNotCallable(): void
    {
        $dispatcher = new Dispatcher();
        $task       = new MainTask();

        [$actual, $messages] = $this->collectErrors(
            static fn () => $dispatcher->callActionMethod($task, 'unknownAction', [])
        );

        $this->assertNull($actual);
        $this->assertSame(
            ['class ' . MainTask::class . ' does not have a method "unknownAction"'],
            $messages
        );
    }
}
