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

namespace Phalcon\Tests\Unit\Mvc\Model\Query;

use Phalcon\Mvc\Model\Query\Status;
use Phalcon\Mvc\ModelInterface;
use Phalcon\Tests\AbstractUnitTestCase;

final class StatusTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-06
     */
    public function testSuccessWithNullModel(): void
    {
        $status = new Status(true);

        $this->assertTrue($status->success());
        $this->assertNull($status->getModel());
        $this->assertSame([], $status->getMessages());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-06
     */
    public function testFailureWithModel(): void
    {
        $messages = ['validation failed'];

        $model = $this->createMock(ModelInterface::class);
        $model->method('getMessages')->willReturn($messages);

        $status = new Status(false, $model);

        $this->assertFalse($status->success());
        $this->assertSame($model, $status->getModel());
        $this->assertSame($messages, $status->getMessages());
    }
}
