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

namespace Phalcon\Tests\Unit\ADR\Responder\StatusMapper;

use Phalcon\ADR\Payload\Status;
use Phalcon\ADR\Responder\StatusMapper;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class ToHttpCodeTest extends AbstractUnitTestCase
{
    public static function statusProvider(): array
    {
        return [
            [Status::ACCEPTED,           202],
            [Status::AUTHENTICATED,      200],
            [Status::AUTHORIZED,         200],
            [Status::CREATED,            201],
            [Status::DELETED,            200],
            [Status::ERROR,              500],
            [Status::FAILURE,            400],
            [Status::FOUND,              200],
            [Status::METHOD_NOT_ALLOWED, 405],
            [Status::NOT_ACCEPTED,       406],
            [Status::NOT_AUTHENTICATED,  401],
            [Status::NOT_AUTHORIZED,     403],
            [Status::NOT_CREATED,        422],
            [Status::NOT_DELETED,        422],
            [Status::NOT_FOUND,          404],
            [Status::NOT_UPDATED,        422],
            [Status::NOT_VALID,          422],
            [Status::PROCESSING,         102],
            [Status::SUCCESS,            200],
            [Status::UPDATED,            200],
            [Status::VALID,              200],
        ];
    }

    /**
     * Unit Tests Phalcon\ADR\Responder\StatusMapper :: toHttpCode()
     *
     * @dataProvider statusProvider
     */
    public function testAdrResponderStatusMapperToHttpCode(string $status, int $expected): void
    {
        $mapper = new StatusMapper();

        $this->assertSame($expected, $mapper->toHttpCode($status));
    }

    /**
     * Unit Tests Phalcon\ADR\Responder\StatusMapper :: toHttpCode() overrides
     */
    public function testAdrResponderStatusMapperToHttpCodeHonoursOverrides(): void
    {
        $mapper = new StatusMapper(
            [
                Status::SUCCESS => 204,
            ]
        );

        $this->assertSame(204, $mapper->toHttpCode(Status::SUCCESS));
        $this->assertSame(201, $mapper->toHttpCode(Status::CREATED));
    }

    /**
     * Unit Tests Phalcon\ADR\Responder\StatusMapper :: toHttpCode() unmapped -> 500
     */
    public function testAdrResponderStatusMapperToHttpCodeUnmappedReturns500(): void
    {
        $mapper = new StatusMapper();

        $this->assertSame(500, $mapper->toHttpCode('NON_EXISTENT'));
    }
}
