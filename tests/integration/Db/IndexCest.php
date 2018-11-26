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
        $I->assertEquals($index1->getName(), 'index1');
        $I->assertEquals($index1->getColumns(), ['column1']);

        $index2 = $indexes['index2'];
        $I->assertEquals($index2->getName(), 'index2');
        $I->assertEquals($index2->getColumns(), ['column1', 'column2']);

        $index3 = $indexes['PRIMARY'];
        $I->assertEquals($index3->getName(), 'PRIMARY');
        $I->assertEquals($index3->getColumns(), ['column3']);

        $index4 = $indexes['index4'];
        $I->assertEquals($index4->getName(), 'index4');
        $I->assertEquals($index4->getColumns(), ['column4']);
        $I->assertEquals($index4->getType(), 'UNIQUE');

        $index5 = $indexes['index5'];
        $I->assertEquals($index5->getName(), 'index5');
        $I->assertEquals($index5->getColumns(), ['column7']);
        $I->assertEquals($index5->getType(), 'FULLTEXT');
    }
}
