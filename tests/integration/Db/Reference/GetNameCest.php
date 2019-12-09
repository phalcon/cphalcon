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

class GetNameCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Reference :: getName()
     */
    public function dbReferenceGetName(IntegrationTester $I)
    {
        $I->wantToTest('Db\Reference - getName()');

        $references = $this->getReferences();


        $reference1 = $references['fk1'];

        $I->assertEquals(
            'fk1',
            $reference1->getName()
        );


        $reference2 = $references['fk2'];

        $I->assertEquals(
            'fk2',
            $reference2->getName()
        );


        $reference3 = $references['fk3'];

        $I->assertEquals(
            'fk3',
            $reference3->getName()
        );


        $reference4 = $references['fk4'];

        $I->assertEquals(
            'fk4',
            $reference4->getName()
        );


        $reference5 = $references['fk5'];

        $I->assertEquals(
            'fk5',
            $reference5->getName()
        );
    }
}
