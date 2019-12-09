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

namespace Phalcon\Test\Unit\Domain\Payload\Payload;

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

        $I->assertEquals('ACCEPTED', Status::ACCEPTED);
        $I->assertEquals('AUTHENTICATED', Status::AUTHENTICATED);
        $I->assertEquals('AUTHORIZED', Status::AUTHORIZED);
        $I->assertEquals('CREATED', Status::CREATED);
        $I->assertEquals('DELETED', Status::DELETED);
        $I->assertEquals('ERROR', Status::ERROR);
        $I->assertEquals('FAILURE', Status::FAILURE);
        $I->assertEquals('FOUND', Status::FOUND);
        $I->assertEquals('NOT_ACCEPTED', Status::NOT_ACCEPTED);
        $I->assertEquals('NOT_AUTHENTICATED', Status::NOT_AUTHENTICATED);
        $I->assertEquals('NOT_AUTHORIZED', Status::NOT_AUTHORIZED);
        $I->assertEquals('NOT_CREATED', Status::NOT_CREATED);
        $I->assertEquals('NOT_DELETED', Status::NOT_DELETED);
        $I->assertEquals('NOT_FOUND', Status::NOT_FOUND);
        $I->assertEquals('NOT_UPDATED', Status::NOT_UPDATED);
        $I->assertEquals('NOT_VALID', Status::NOT_VALID);
        $I->assertEquals('PROCESSING', Status::PROCESSING);
        $I->assertEquals('SUCCESS', Status::SUCCESS);
        $I->assertEquals('UPDATED', Status::UPDATED);
        $I->assertEquals('VALID', Status::VALID);
    }
}
