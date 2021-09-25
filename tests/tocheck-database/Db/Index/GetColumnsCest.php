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

namespace Phalcon\Tests\Integration\Db\Index;

use IntegrationTester;
use Phalcon\Tests\Fixtures\Traits\DialectTrait;

class GetColumnsCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Index :: getColumns()
     */
    public function dbIndexGetColumns(IntegrationTester $I)
    {
        $I->wantToTest('Db\Index - getColumns()');

        $indexes = $this->getIndexes();


        $index1 = $indexes['index1'];

        $I->assertEquals(
            ['column1'],
            $index1->getColumns()
        );


        $index2 = $indexes['index2'];

        $I->assertEquals(
            ['column1', 'column2'],
            $index2->getColumns()
        );


        $index3 = $indexes['PRIMARY'];

        $I->assertEquals(
            ['column3'],
            $index3->getColumns()
        );


        $index4 = $indexes['index4'];

        $I->assertEquals(
            ['column4'],
            $index4->getColumns()
        );


        $index5 = $indexes['index5'];

        $I->assertEquals(
            ['column7'],
            $index5->getColumns()
        );
    }
}
