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
use Phalcon\Logger\Exception;
use Phalcon\Tests\AbstractUnitTestCase;

final class CommitTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerAdapterNoopCommit(): void
    {
        $adapter = new Noop();

        $adapter->begin();

        $this->assertTrue(
            $adapter->inTransaction()
        );

        $adapter->commit();

        $this->assertFalse(
            $adapter->inTransaction()
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerAdapterNoopCommitNoTransaction(): void
    {
        $adapter = new Noop();

        $this->assertFalse(
            $adapter->inTransaction()
        );

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('There is no active transaction');

        $adapter->commit();
    }
}
