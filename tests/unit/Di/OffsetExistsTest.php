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

namespace Phalcon\Tests\Unit\Di;

use Phalcon\Di\Di;
use Phalcon\Html\Escaper;
use Phalcon\Tests\AbstractUnitTestCase;

final class OffsetExistsTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiOffsetExists(): void
    {
        $container = new Di();

        $actual = isset($container['escaper']);
        $this->assertFalse($actual);

        $container->set('escaper', Escaper::class);

        $actual = isset($container['escaper']);
        $this->assertTrue($actual);
    }
}
