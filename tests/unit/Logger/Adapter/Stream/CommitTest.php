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

namespace Phalcon\Tests\Unit\Logger\Adapter\Stream;

use Phalcon\Logger\Adapter\Stream;
use Phalcon\Logger\Exception;
use Phalcon\Tests\AbstractUnitTestCase;

final class CommitTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerAdapterStreamCommit(): void
    {
        $fileName   = $this->getNewFileName('log', 'log');
        $outputPath = logsDir();
        $adapter    = new Stream($outputPath . $fileName);

        $adapter->begin();

        $actual = $adapter->inTransaction();
        $this->assertTrue($actual);

        $adapter->commit();

        $actual = $adapter->inTransaction();
        $this->assertFalse($actual);

        $adapter->close();
        $this->safeDeleteFile($outputPath . $fileName);
    }

    /**
     * Tests Phalcon\Logger\Adapter\Stream :: commit() - no transaction
     */
    public function testLoggerAdapterStreamCommitNoTransaction(): void
    {
        $fileName   = $this->getNewFileName('log', 'log');
        $outputPath = logsDir();

        try {
            $adapter = new Stream($outputPath . $fileName);

            $actual = $adapter->inTransaction();
            $this->assertFalse($actual);

            $adapter->commit();
            $adapter->close();
        } catch (Exception $ex) {
            $expected = 'There is no active transaction';
            $actual   = $ex->getMessage();
            $this->assertSame($expected, $actual);
        }

        $this->safeDeleteFile($outputPath . $fileName);
    }
}
