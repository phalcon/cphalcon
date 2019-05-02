<?php

namespace Phalcon\Test\Integration\Db;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DialectTrait;
use Phalcon\Test\Module\IntegrationTest;

class IndexCest
{
    use DialectTrait;

    public function shouldWorkPerfectlyWithIndexAsObject(IntegrationTester $I)
    {
        $indexes = $this->getIndexes();

        $index1 = $indexes['index1'];

        $I->assertEquals(
            'index1',
            $index1->getName()
        );

        $I->assertEquals(
            ['column1'],
            $index1->getColumns()
        );



        $index2 = $indexes['index2'];

        $I->assertEquals(
            'index2',
            $index2->getName()
        );

        $I->assertEquals(
            ['column1', 'column2'],
            $index2->getColumns()
        );



        $index3 = $indexes['PRIMARY'];

        $I->assertEquals(
            'PRIMARY',
            $index3->getName()
        );

        $I->assertEquals(
            ['column3'],
            $index3->getColumns()
        );



        $index4 = $indexes['index4'];

        $I->assertEquals(
            'index4',
            $index4->getName()
        );

        $I->assertEquals(
            ['column4'],
            $index4->getColumns()
        );

        $I->assertEquals(
            'UNIQUE',
            $index4->getType()
        );



        $index5 = $indexes['index5'];

        $I->assertEquals(
            'index5',
            $index5->getName()
        );

        $I->assertEquals(
            ['column7'],
            $index5->getColumns()
        );

        $I->assertEquals(
            'FULLTEXT',
            $index5->getType()
        );
    }
}
