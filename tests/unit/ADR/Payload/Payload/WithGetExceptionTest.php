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
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use RuntimeException;

final class WithGetExceptionTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Payload\Payload :: withException()/getException()
     */
    public function testAdrPayloadPayloadWithGetException(): void
    {
        $exception = new RuntimeException('boom');
        $payload   = new Payload();
        $new       = $payload->withException($exception);

        $this->assertNotSame($payload, $new);
        $this->assertNull($payload->getException());
        $this->assertSame($exception, $new->getException());
    }
}
