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

namespace Phalcon\Test\Integration\Db\Reference;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DialectTrait;

class GetOnUpdateCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Reference :: getOnUpdate()
     */
    public function dbReferenceGetOnUpdate(IntegrationTester $I)
    {
        $I->wantToTest('Db\Reference - getOnUpdate()');

        $references = $this->getReferences();


        $reference1 = $references['fk1'];

        $I->assertNull(
            $reference1->getOnUpdate()
        );


        $reference2 = $references['fk2'];

        $I->assertNull(
            $reference1->getOnUpdate()
        );


        $reference3 = $references['fk3'];

        $I->assertNull(
            $reference3->getOnUpdate()
        );


        $reference4 = $references['fk4'];

        $I->assertEquals(
            'SET NULL',
            $reference4->getOnUpdate()
        );


        $reference5 = $references['fk5'];

        $I->assertEquals(
            'NO ACTION',
            $reference5->getOnUpdate()
        );
    }
}
