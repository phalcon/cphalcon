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

namespace Phalcon\Tests\Unit\Contracts\ADR\Domain;

use Phalcon\ADR\Payload\Payload;
use Phalcon\ADR\Payload\Status;
use Phalcon\Contracts\ADR\Domain;
use Phalcon\Contracts\ADR\Payload\Payload as PayloadContract;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class InvokeTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\Contracts\ADR\Domain :: __invoke()
     */
    public function testContractsAdrDomainInvokeReturnsPayload(): void
    {
        $domain = new class implements Domain {
            public function __invoke($input): PayloadContract
            {
                return Payload::success($input);
            }
        };

        $this->assertInstanceOf(Domain::class, $domain);

        $payload = $domain(['id' => 1]);

        $this->assertInstanceOf(PayloadContract::class, $payload);
        $this->assertSame(Status::SUCCESS, $payload->getStatus());
        $this->assertSame(['id' => 1], $payload->getResult());
    }
}
