<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DialectTrait;

class ReferenceCest
{
    use DialectTrait;

    public function shouldWorkPerfectlyWithCReferenceAsObject(IntegrationTester $I)
    {
        $references = $this->getReferences();



        $reference1 = $references['fk1'];

        $I->assertEquals(
            'fk1',
            $reference1->getName()
        );

        $I->assertEquals(
            ['column1'],
            $reference1->getColumns()
        );

        $I->assertEquals(
            'ref_table',
            $reference1->getReferencedTable()
        );

        $I->assertEquals(
            ['column2'],
            $reference1->getReferencedColumns()
        );

        $I->assertNull(
            $reference1->getOnDelete()
        );

        $I->assertNull(
            $reference1->getOnUpdate()
        );



        $reference2 = $references['fk2'];

        $I->assertEquals(
            'fk2',
            $reference2->getName()
        );

        $I->assertEquals(
            ['column3', 'column4'],
            $reference2->getColumns()
        );

        $I->assertEquals(
            'ref_table',
            $reference2->getReferencedTable()
        );

        $I->assertEquals(
            ['column5', 'column6'],
            $reference2->getReferencedColumns()
        );

        $I->assertNull(
            $reference1->getOnDelete()
        );

        $I->assertNull(
            $reference1->getOnUpdate()
        );



        $reference3 = $references['fk3'];

        $I->assertEquals(
            'fk3',
            $reference3->getName()
        );

        $I->assertEquals(
            ['column1'],
            $reference3->getColumns()
        );

        $I->assertEquals(
            'ref_table',
            $reference3->getReferencedTable()
        );

        $I->assertEquals(
            ['column2'],
            $reference3->getReferencedColumns()
        );

        $I->assertEquals(
            'CASCADE',
            $reference3->getOnDelete()
        );

        $I->assertNull(
            $reference3->getOnUpdate()
        );



        $reference4 = $references['fk4'];

        $I->assertEquals(
            'fk4',
            $reference4->getName()
        );

        $I->assertEquals(
            ['column1'],
            $reference4->getColumns()
        );

        $I->assertEquals(
            'ref_table',
            $reference4->getReferencedTable()
        );

        $I->assertEquals(
            ['column2'],
            $reference4->getReferencedColumns()
        );

        $I->assertNull(
            $reference4->getOnDelete()
        );

        $I->assertEquals(
            'SET NULL',
            $reference4->getOnUpdate()
        );



        $reference5 = $references['fk5'];

        $I->assertEquals(
            'fk5',
            $reference5->getName()
        );

        $I->assertEquals(
            ['column1'],
            $reference5->getColumns()
        );

        $I->assertEquals(
            'ref_table',
            $reference5->getReferencedTable()
        );

        $I->assertEquals(
            ['column2'],
            $reference5->getReferencedColumns()
        );

        $I->assertEquals(
            'CASCADE',
            $reference5->getOnDelete()
        );

        $I->assertEquals(
            'NO ACTION',
            $reference5->getOnUpdate()
        );
    }
}
