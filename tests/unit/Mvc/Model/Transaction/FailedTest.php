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

namespace Phalcon\Tests\Unit\Mvc\Model\Transaction;

use Phalcon\Mvc\Model\Transaction\Failed;
use Phalcon\Mvc\ModelInterface;
use Phalcon\Tests\AbstractUnitTestCase;

final class FailedTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-06
     */
    public function testGetRecordReturnsNullWhenNoRecord(): void
    {
        $failed = new Failed('transaction failed');

        $this->assertNull($failed->getRecord());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-06
     */
    public function testGetRecordMessagesFallsBackToMessage(): void
    {
        $failed = new Failed('the failure message');

        $this->assertSame('the failure message', $failed->getRecordMessages());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-06
     */
    public function testGetRecordAndMessagesWithRecord(): void
    {
        $messages = ['first', 'second'];

        $record = $this->createMock(ModelInterface::class);
        $record->method('getMessages')->willReturn($messages);

        $failed = new Failed('failed', $record);

        $this->assertSame($record, $failed->getRecord());
        $this->assertSame($messages, $failed->getRecordMessages());
    }
}
