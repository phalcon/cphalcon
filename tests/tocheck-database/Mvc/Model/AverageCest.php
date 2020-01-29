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

class AverageCest
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

    public function testAverageMysql(IntegrationTester $I)
    {
        $this->setDiMysql();

        $this->executeTestsNormal($I);
        $this->executeTestsRenamed($I);
    }

    public function testAverageSqlite(IntegrationTester $I)
    {
        $this->setDiSqlite();

        $this->executeTestsNormal($I);
        $this->executeTestsRenamed($I);
    }

    /**
     * @medium
     */
    public function testAveragePostgresql(IntegrationTester $I)
    {
        $this->setDiPostgresql();

        $this->executeTestsNormal(
            $I,
            453272.32,
            453427.07
        );

        $this->executeTestsRenamed(
            $I,
            453272.32,
            453427.07
        );
    }

    protected function executeTestsNormal(IntegrationTester $I, $cupo_average = 456452.30, $a_average = 456611.11)
    {
        $total = Personnes::average(
            [
                'column' => 'cupo',
            ]
        );

        $I->assertEquals(
            $cupo_average,
            sprintf('%.2f', $total)
        );

        $total = Personnes::average(
            [
                'column'     => 'cupo',
                'conditions' => "estado='I'",
            ]
        );

        $I->assertEquals(283510.00, $total);

        $group = Personnes::average(
            [
                'column' => 'cupo',
                'group'  => 'estado',
            ]
        );

        $I->assertCount(2, $group);

        $results = [
            'A' => $a_average,
            'I' => 283510.00,
        ];

        foreach ($group as $row) {
            $I->assertEquals(
                $results[$row->estado],
                sprintf('%.2f', $row->average)
            );
        }

        $group = Personnes::average(
            [
                'column' => 'cupo',
                'group'  => 'ciudad_id',
                'order'  => 'average DESC',
            ]
        );

        $I->assertEquals(996200.00, $group[0]->average);
    }

    protected function executeTestsRenamed(
        IntegrationTester $I,
        $cupo_average = 456452.30,
        $a_average = 456611.11
    ) {
        //Average
        $total = Pessoas::average(
            [
                'column' => 'credito',
            ]
        );
        $I->assertEquals(
            $cupo_average,
            sprintf('%.2f', $total)
        );

        $total = Pessoas::average(
            [
                'column'     => 'credito',
                'conditions' => "estado='I'",
            ]
        );
        $I->assertEquals(283510.00, $total);

        $group = Pessoas::average(
            [
                'column' => 'credito',
                'group'  => 'estado',
            ]
        );
        $I->assertCount(2, $group);

        $results = [
            'A' => $a_average,
            'I' => 283510.00,
        ];
        foreach ($group as $row) {
            $I->assertEquals(
                $results[$row->estado],
                sprintf('%.2f', $row->average)
            );
        }

        $group = Pessoas::average(
            [
                'column' => 'credito',
                'group'  => 'cidadeId',
                'order'  => 'average DESC',
            ]
        );
        $I->assertEquals(996200.00, $group[0]->average);
    }
}
