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

namespace Phalcon\Tests\Unit\Domain\Payload\Payload;

use Phalcon\Domain\Payload\Status;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class StatusTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\Domain\Payload\Status :: constants
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-24
     */
    public function testHttpPayloadPayloadStatus(): void
    {
        $this->assertSame('ACCEPTED', Status::ACCEPTED);
        $this->assertSame('AUTHENTICATED', Status::AUTHENTICATED);
        $this->assertSame('AUTHORIZED', Status::AUTHORIZED);
        $this->assertSame('CREATED', Status::CREATED);
        $this->assertSame('DELETED', Status::DELETED);
        $this->assertSame('ERROR', Status::ERROR);
        $this->assertSame('FAILURE', Status::FAILURE);
        $this->assertSame('FOUND', Status::FOUND);
        $this->assertSame('NOT_ACCEPTED', Status::NOT_ACCEPTED);
        $this->assertSame('NOT_AUTHENTICATED', Status::NOT_AUTHENTICATED);
        $this->assertSame('NOT_AUTHORIZED', Status::NOT_AUTHORIZED);
        $this->assertSame('NOT_CREATED', Status::NOT_CREATED);
        $this->assertSame('NOT_DELETED', Status::NOT_DELETED);
        $this->assertSame('NOT_FOUND', Status::NOT_FOUND);
        $this->assertSame('NOT_UPDATED', Status::NOT_UPDATED);
        $this->assertSame('NOT_VALID', Status::NOT_VALID);
        $this->assertSame('PROCESSING', Status::PROCESSING);
        $this->assertSame('SUCCESS', Status::SUCCESS);
        $this->assertSame('UPDATED', Status::UPDATED);
        $this->assertSame('VALID', Status::VALID);
    }
}
