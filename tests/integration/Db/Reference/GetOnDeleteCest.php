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

class GetOnDeleteCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Reference :: getOnDelete()
     */
    public function dbReferenceGetOnDelete(IntegrationTester $I)
    {
        $I->wantToTest('Db\Reference - getOnDelete()');

        $references = $this->getReferences();


        $reference1 = $references['fk1'];

        $I->assertNull(
            $reference1->getOnDelete()
        );


        $reference2 = $references['fk2'];

        $I->assertNull(
            $reference1->getOnDelete()
        );


        $reference3 = $references['fk3'];

        $I->assertEquals(
            'CASCADE',
            $reference3->getOnDelete()
        );


        $reference4 = $references['fk4'];

        $I->assertNull(
            $reference4->getOnDelete()
        );


        $reference5 = $references['fk5'];

        $I->assertEquals(
            'CASCADE',
            $reference5->getOnDelete()
        );
    }
}
