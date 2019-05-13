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
use Phalcon\Test\Module\IntegrationTest;

class ReferenceCest
{
    use DialectTrait;

    public function shouldWorkPerfectlyWithCReferenceAsObject(IntegrationTester $I)
    {
        $references = $this->getReferences();

        $reference1 = $references['fk1'];
        $I->assertEquals($reference1->getName(), 'fk1');
        $I->assertEquals($reference1->getColumns(), ['column1']);
        $I->assertEquals($reference1->getReferencedTable(), 'ref_table');
        $I->assertEquals($reference1->getReferencedColumns(), ['column2']);
        $I->assertEquals($reference1->getOnDelete(), null);
        $I->assertEquals($reference1->getOnUpdate(), null);

        $reference2 = $references['fk2'];
        $I->assertEquals($reference2->getName(), 'fk2');
        $I->assertEquals($reference2->getColumns(), ['column3', 'column4']);
        $I->assertEquals($reference2->getReferencedTable(), 'ref_table');
        $I->assertEquals($reference2->getReferencedColumns(), ['column5', 'column6']);
        $I->assertEquals($reference1->getOnDelete(), null);
        $I->assertEquals($reference1->getOnUpdate(), null);

        $reference3 = $references['fk3'];
        $I->assertEquals($reference3->getName(), 'fk3');
        $I->assertEquals($reference3->getColumns(), ['column1']);
        $I->assertEquals($reference3->getReferencedTable(), 'ref_table');
        $I->assertEquals($reference3->getReferencedColumns(), ['column2']);
        $I->assertEquals($reference3->getOnDelete(), 'CASCADE');
        $I->assertEquals($reference3->getOnUpdate(), null);

        $reference4 = $references['fk4'];
        $I->assertEquals($reference4->getName(), 'fk4');
        $I->assertEquals($reference4->getColumns(), ['column1']);
        $I->assertEquals($reference4->getReferencedTable(), 'ref_table');
        $I->assertEquals($reference4->getReferencedColumns(), ['column2']);
        $I->assertEquals($reference4->getOnDelete(), null);
        $I->assertEquals($reference4->getOnUpdate(), 'SET NULL');

        $reference5 = $references['fk5'];
        $I->assertEquals($reference5->getName(), 'fk5');
        $I->assertEquals($reference5->getColumns(), ['column1']);
        $I->assertEquals($reference5->getReferencedTable(), 'ref_table');
        $I->assertEquals($reference5->getReferencedColumns(), ['column2']);
        $I->assertEquals($reference5->getOnDelete(), 'CASCADE');
        $I->assertEquals($reference5->getOnUpdate(), 'NO ACTION');
    }
}
