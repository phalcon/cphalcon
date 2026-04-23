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

final class HasParamTest extends AbstractUnitTestCase
{
    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-02
     */
    public function testCliDispatcherHasParam(): void
    {
        $dispatcher = new Dispatcher();

        $dispatcher->setParams(
            [
                'a' => 1,
                'b' => '2',
                'c' => 'three',
            ]
        );

        $actual = $dispatcher->hasParam('a');
        $this->assertTrue($actual);

        $actual = $dispatcher->hasParam('b');
        $this->assertTrue($actual);

        $actual = $dispatcher->hasParam('c');
        $this->assertTrue($actual);

        $actual = $dispatcher->hasParam('d');
        $this->assertFalse($actual);
    }
}
