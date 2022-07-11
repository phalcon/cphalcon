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
use UnitTester;

class StatusCest
{
    /**
     * Unit Tests Phalcon\Domain\Payload\Status :: constants
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-24
     */
    public function httpPayloadPayloadStatus(UnitTester $I)
    {
        $I->wantToTest('Domain\Payload\Status - constants');

        $I->assertSame('ACCEPTED', Status::ACCEPTED);
        $I->assertSame('AUTHENTICATED', Status::AUTHENTICATED);
        $I->assertSame('AUTHORIZED', Status::AUTHORIZED);
        $I->assertSame('CREATED', Status::CREATED);
        $I->assertSame('DELETED', Status::DELETED);
        $I->assertSame('ERROR', Status::ERROR);
        $I->assertSame('FAILURE', Status::FAILURE);
        $I->assertSame('FOUND', Status::FOUND);
        $I->assertSame('NOT_ACCEPTED', Status::NOT_ACCEPTED);
        $I->assertSame('NOT_AUTHENTICATED', Status::NOT_AUTHENTICATED);
        $I->assertSame('NOT_AUTHORIZED', Status::NOT_AUTHORIZED);
        $I->assertSame('NOT_CREATED', Status::NOT_CREATED);
        $I->assertSame('NOT_DELETED', Status::NOT_DELETED);
        $I->assertSame('NOT_FOUND', Status::NOT_FOUND);
        $I->assertSame('NOT_UPDATED', Status::NOT_UPDATED);
        $I->assertSame('NOT_VALID', Status::NOT_VALID);
        $I->assertSame('PROCESSING', Status::PROCESSING);
        $I->assertSame('SUCCESS', Status::SUCCESS);
        $I->assertSame('UPDATED', Status::UPDATED);
        $I->assertSame('VALID', Status::VALID);
    }
}
