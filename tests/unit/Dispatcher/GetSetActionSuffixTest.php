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

final class GetSetActionSuffixTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-17
     */
    public function testDispatcherGetSetActionSuffix(): void
    {
        $dispatcher = new Dispatcher();

        $expected = 'Action';
        $actual   = $dispatcher->getActionSuffix();
        $this->assertSame($expected, $actual);

        $dispatcher->setActionSuffix('two');

        $expected = 'two';
        $actual   = $dispatcher->getActionSuffix();
        $this->assertSame($expected, $actual);
    }
}
