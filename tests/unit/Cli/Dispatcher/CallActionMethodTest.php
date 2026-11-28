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
use TypeError;

final class CallActionMethodTest extends AbstractUnitTestCase
{
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
     * An action that cannot be called throws the TypeError of
     * call_user_func_array().
     *
     * @issue  https://github.com/phalcon/phalcon/issues/815
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    public function testCliDispatcherCallActionMethodNotCallable(): void
    {
        $dispatcher = new Dispatcher();
        $task       = new MainTask();

        $this->expectException(TypeError::class);
        $this->expectExceptionMessage(
            'call_user_func_array(): Argument #1 ($callback) must be a valid callback, '
            . 'class ' . MainTask::class . ' does not have a method "unknownAction"'
        );

        $dispatcher->callActionMethod($task, 'unknownAction', []);
    }
}
