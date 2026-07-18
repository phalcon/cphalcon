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

namespace Phalcon\Tests\Unit\ADR\Payload\PayloadFactory;

use Phalcon\ADR\Payload\PayloadFactory;
use Phalcon\ADR\Payload\Status;
use Phalcon\Contracts\ADR\Payload\Payload as PayloadInterface;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class FactoriesTest extends AbstractUnitTestCase
{
    public static function factoryProvider(): array
    {
        return [
            ['accepted',        Status::ACCEPTED],
            ['created',         Status::CREATED],
            ['deleted',         Status::DELETED],
            ['error',           Status::ERROR],
            ['forbidden',       Status::NOT_AUTHORIZED],
            ['found',           Status::FOUND],
            ['invalid',         Status::NOT_VALID],
            ['notFound',        Status::NOT_FOUND],
            ['processing',      Status::PROCESSING],
            ['success',         Status::SUCCESS],
            ['unauthenticated', Status::NOT_AUTHENTICATED],
            ['updated',         Status::UPDATED],
        ];
    }

    /**
     * Unit Tests Phalcon\ADR\Payload\PayloadFactory :: named factories
     *
     * @dataProvider factoryProvider
     */
    public function testAdrPayloadPayloadFactoryNamedFactories(string $method, string $expectedStatus): void
    {
        $factory = new PayloadFactory();
        $payload = $factory->{$method}('value');

        $this->assertInstanceOf(PayloadInterface::class, $payload);
        $this->assertSame($expectedStatus, $payload->getStatus());
    }
}
