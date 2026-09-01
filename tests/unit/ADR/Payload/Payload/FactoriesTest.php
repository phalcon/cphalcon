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
use Phalcon\Contracts\ADR\Payload\Payload as PayloadInterface;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class FactoriesTest extends AbstractUnitTestCase
{
    public static function factoryProvider(): array
    {
        return [
            ['accepted',        Status::ACCEPTED],
            ['authenticated',   Status::AUTHENTICATED],
            ['authorized',      Status::AUTHORIZED],
            ['created',         Status::CREATED],
            ['deleted',         Status::DELETED],
            ['error',           Status::ERROR],
            ['forbidden',       Status::NOT_AUTHORIZED],
            ['found',           Status::FOUND],
            ['invalid',         Status::NOT_VALID],
            ['notAccepted',     Status::NOT_ACCEPTED],
            ['notCreated',      Status::NOT_CREATED],
            ['notDeleted',      Status::NOT_DELETED],
            ['notFound',        Status::NOT_FOUND],
            ['notUpdated',      Status::NOT_UPDATED],
            ['processing',      Status::PROCESSING],
            ['success',         Status::SUCCESS],
            ['unauthenticated', Status::NOT_AUTHENTICATED],
            ['updated',         Status::UPDATED],
            ['valid',           Status::VALID],
        ];
    }

    /**
     * Unit Tests Phalcon\ADR\Payload\Payload :: named factories
     *
     * @dataProvider factoryProvider
     */
    public function testAdrPayloadPayloadNamedFactories(string $method, string $expectedStatus): void
    {
        $payload = Payload::{$method}('value');

        $this->assertInstanceOf(PayloadInterface::class, $payload);
        $this->assertSame($expectedStatus, $payload->getStatus());
    }
}
