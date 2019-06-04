<?php

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Personnes;
use Phalcon\Test\Models\Pessoas;

class SumCest
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

    public function testSumMysql(IntegrationTester $I)
    {
        $this->setDiMysql();

        $this->executeTestsNormal($I);
        $this->executeTestsRenamed($I);
    }

    public function testSumSqlite(IntegrationTester $I)
    {
        $this->setDiSqlite();

        $this->executeTestsNormal($I);
        $this->executeTestsRenamed($I);
    }

    /**
     * @medium
     */
    public function testSumPostgresql(IntegrationTester $I)
    {
        $this->setDiPostgresql();

        $this->executeTestsNormal(
            $I,
            995386020.00,
            994819000.00
        );

        $this->executeTestsRenamed(
            $I,
            995386020.00,
            994819000.00
        );
    }

    protected function executeTestsNormal(
        IntegrationTester $I,
        $cupo_sum = 995066020.00,
        $a_sum = 994499000.00
    ) {
        $total = Personnes::sum(
            [
                'column' => 'cupo',
            ]
        );

        $I->assertEquals($cupo_sum, $total);

        $total = Personnes::sum(
            [
                'column'     => 'cupo',
                'conditions' => "estado='I'",
            ]
        );

        $I->assertEquals(567020.00, $total);

        $group = Personnes::sum(
            [
                'column' => 'cupo',
                'group'  => 'estado',
            ]
        );

        $I->assertCount(2, $group);

        $results = [
            'A' => $a_sum,
            'I' => 567020.00,
        ];

        foreach ($group as $row) {
            $I->assertEquals($results[$row->estado], $row->sumatory);
        }

        $group = Personnes::sum(
            [
                'column' => 'cupo',
                'group'  => 'ciudad_id',
                'order'  => 'sumatory DESC',
            ]
        );

        $I->assertEquals(358467690.00, $group[0]->sumatory);
    }

    protected function executeTestsRenamed(
        IntegrationTester $I,
        $cupo_sum = 995066020.00,
        $a_sum = 994499000.00
    ) {
        $total = Pessoas::sum(
            [
                'column' => 'credito',
            ]
        );

        $I->assertEquals($cupo_sum, $total);

        $total = Pessoas::sum(
            [
                'column'     => 'credito',
                'conditions' => "estado='I'",
            ]
        );

        $I->assertEquals(567020.00, $total);

        $group = Pessoas::sum(
            [
                'column' => 'credito',
                'group'  => 'estado',
            ]
        );

        $I->assertCount(2, $group);

        $results = [
            'A' => $a_sum,
            'I' => 567020.00,
        ];

        foreach ($group as $row) {
            $I->assertEquals(
                $results[$row->estado],
                $row->sumatory
            );
        }

        $group = Pessoas::sum(
            [
                'column' => 'credito',
                'group'  => 'cidadeId',
                'order'  => 'sumatory DESC',
            ]
        );

        $I->assertEquals(358467690.00, $group[0]->sumatory);
    }
}
