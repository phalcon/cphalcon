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

class GetReferencedColumnsCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Reference :: getReferencedColumns()
     */
    public function dbReferenceGetReferencedColumns(IntegrationTester $I)
    {
        $I->wantToTest('Db\Reference - getReferencedColumns()');

        $references = $this->getReferences();


        $reference1 = $references['fk1'];

        $I->assertEquals(
            ['column2'],
            $reference1->getReferencedColumns()
        );


        $reference2 = $references['fk2'];

        $I->assertEquals(
            ['column5', 'column6'],
            $reference2->getReferencedColumns()
        );


        $reference3 = $references['fk3'];

        $I->assertEquals(
            ['column2'],
            $reference3->getReferencedColumns()
        );


        $reference4 = $references['fk4'];

        $I->assertEquals(
            ['column2'],
            $reference4->getReferencedColumns()
        );


        $reference5 = $references['fk5'];

        $I->assertEquals(
            ['column2'],
            $reference5->getReferencedColumns()
        );
    }
}
