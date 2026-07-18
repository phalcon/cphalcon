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

namespace Phalcon\Tests\Unit\ADR\Payload\Payload;

use Phalcon\ADR\Payload\Payload;
use Phalcon\ADR\Payload\Status;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class WithGetStatusTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Payload\Payload :: withStatus()/getStatus()
     */
    public function testAdrPayloadPayloadWithGetStatus(): void
    {
        $payload = new Payload();
        $new     = $payload->withStatus(Status::SUCCESS);

        $this->assertNotSame($payload, $new);
        $this->assertNull($payload->getStatus());
        $this->assertSame(Status::SUCCESS, $new->getStatus());
    }
}
