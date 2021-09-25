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

namespace Phalcon\Tests\Integration\Db\Reference;

use IntegrationTester;
use Phalcon\Tests\Fixtures\Traits\DialectTrait;

class GetColumnsCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Reference :: getColumns()
     */
    public function dbReferenceGetColumns(IntegrationTester $I)
    {
        $I->wantToTest('Db\Reference - getColumns()');

        $references = $this->getReferences();


        $reference1 = $references['fk1'];

        $I->assertEquals(
            ['column1'],
            $reference1->getColumns()
        );


        $reference2 = $references['fk2'];

        $I->assertEquals(
            ['column3', 'column4'],
            $reference2->getColumns()
        );


        $reference3 = $references['fk3'];

        $I->assertEquals(
            ['column1'],
            $reference3->getColumns()
        );


        $reference4 = $references['fk4'];

        $I->assertEquals(
            ['column1'],
            $reference4->getColumns()
        );


        $reference5 = $references['fk5'];

        $I->assertEquals(
            ['column1'],
            $reference5->getColumns()
        );
    }
}
