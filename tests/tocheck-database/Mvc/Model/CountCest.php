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

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Personnes;
use Phalcon\Test\Models\Pessoas;

class CountCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    public function testCountMysql(IntegrationTester $I)
    {
        $this->setDiMysql();

        $this->executeTestsNormal($I);
        $this->executeTestsRenamed($I);
    }

    public function testCountSqlite(IntegrationTester $I)
    {
        $this->setDiSqlite();

        $this->executeTestsNormal($I);
        $this->executeTestsRenamed($I);
    }

    /**
     * @medium
     */
    public function testCountPostgresql(IntegrationTester $I)
    {
        $this->setDiPostgresql();

        $this->executeTestsNormal(
            $I,
            2196,
            2194
        );

        $this->executeTestsRenamed(
            $I,
            2196,
            2194
        );
    }

    protected function executeTestsNormal(
        IntegrationTester $I,
        $total_rows = 2180,
        $estado_rows = 2178
    ) {
        $rowcount = Personnes::count();

        $I->assertEquals($total_rows, $rowcount);

        $rowcount = Personnes::count(
            [
                'distinct' => 'estado',
            ]
        );

        $I->assertEquals(2, $rowcount);

        $rowcount = Personnes::count("estado='A'");
        $I->assertEquals($estado_rows, $rowcount);

        $group = Personnes::count(
            [
                'group' => 'estado',
            ]
        );

        $I->assertCount(2, $group);

        $group = Personnes::count(
            [
                'group' => 'estado',
                'order' => 'estado',
            ]
        );
        $I->assertCount(2, $group);

        $results = [
            'A' => $estado_rows,
            'I' => 2,
        ];

        foreach ($group as $row) {
            $I->assertEquals(
                $results[$row->estado],
                $row->rowcount
            );
        }

        $I->assertEquals(
            $estado_rows,
            $group[0]->rowcount
        );

        $I->assertEquals(
            2,
            $group[1]->rowcount
        );

        $group = Personnes::count(
            [
                'group' => 'estado',
            ]
        );
        $I->assertCount(2, $group);

        $group = Personnes::count(
            [
                'group' => 'ciudad_id',
            ]
        );
        $I->assertCount(285, $group);

        $group = Personnes::count(
            [
                'group' => 'ciudad_id',
                'order' => 'rowcount DESC',
            ]
        );
        $I->assertEquals(727, $group[0]->rowcount);
    }

    protected function executeTestsRenamed(
        IntegrationTester $I,
        $total_rows = 2180,
        $estado_rows = 2178
    ) {
        $rowcount = Pessoas::count();

        $I->assertEquals($total_rows, $rowcount);

        $rowcount = Pessoas::count(
            [
                'distinct' => 'estado',
            ]
        );

        $I->assertEquals(2, $rowcount);

        $rowcount = Pessoas::count("estado='A'");
        $I->assertEquals($estado_rows, $rowcount);

        $group = Pessoas::count(
            [
                'group' => 'estado',
            ]
        );

        $I->assertCount(2, $group);

        $group = Pessoas::count(
            [
                'group' => 'estado',
                'order' => 'estado',
            ]
        );

        $I->assertCount(2, $group);

        $results = [
            'A' => $estado_rows,
            'I' => 2,
        ];

        foreach ($group as $row) {
            $I->assertEquals(
                $results[$row->estado],
                $row->rowcount
            );
        }

        $I->assertEquals(
            $estado_rows,
            $group[0]->rowcount
        );

        $I->assertEquals(
            2,
            $group[1]->rowcount
        );

        $group = Pessoas::count(
            [
                'group' => 'estado',
            ]
        );

        $I->assertCount(2, $group);

        $group = Pessoas::count(
            [
                'group' => 'cidadeId',
            ]
        );

        $I->assertCount(285, $group);

        $group = Pessoas::count(
            [
                'group' => 'cidadeId',
                'order' => 'rowcount DESC',
            ]
        );

        $I->assertEquals(727, $group[0]->rowcount);
    }
}
