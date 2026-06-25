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

namespace Phalcon\Tests\Unit\Logger\Adapter\Noop;

use Phalcon\Logger\Adapter\Noop;
use Phalcon\Tests\AbstractUnitTestCase;

final class BeginTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerAdapterNoopBegin(): void
    {
        $adapter = new Noop();

        $this->assertFalse(
            $adapter->inTransaction()
        );

        $adapter->begin();

        $this->assertTrue(
            $adapter->inTransaction()
        );

        $adapter->commit();

        $this->assertFalse(
            $adapter->inTransaction()
        );
    }
}
