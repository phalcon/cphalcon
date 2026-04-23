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
use Phalcon\Tests\AbstractUnitTestCase;

/**
 * Class GetTaskSuffixTest extends AbstractUnitTestCase
 */
final class GetSetTaskSuffixTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testCliDispatcherGetTaskSuffix(): void
    {
        $dispatcher = new Dispatcher();

        $expected = "Task";
        $actual   = $dispatcher->getTaskSuffix();
        $this->assertSame($expected, $actual);

        $value = "Phalcon";
        $dispatcher->setTaskSuffix($value);

        $expected = $value;
        $actual   = $dispatcher->getTaskSuffix();
        $this->assertSame($expected, $actual);
    }
}
