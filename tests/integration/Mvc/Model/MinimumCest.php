<?php

namespace Phalcon\Test\Integration\Mvc\Model;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Personnes;
use Phalcon\Test\Models\Pessoas;

class MinimumCest
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

    /**
     * @dataProvider adaptersProvider
     */
    public function executeTestsNormal(IntegrationTester $I, Example $example)
    {
        $diFunction = 'setDi' . $example[0];

        $this->{$diFunction}();

        $min = Personnes::minimum(
            [
                'column' => 'ciudad_id',
            ]
        );
        $I->assertEquals(20404, $min);

        $min = Personnes::minimum(
            [
                'column'     => 'ciudad_id',
                'conditions' => "estado='I'",
            ]
        );
        $I->assertEquals(127591, $min);

        $group = Personnes::minimum(
            [
                'column' => 'ciudad_id',
                'group'  => 'estado',
            ]
        );
        $I->assertCount(2, $group);

        $results = [
            'A' => 20404,
            'I' => 127591,
        ];

        foreach ($group as $row) {
            $I->assertEquals($results[$row->estado], $row->minimum);
        }

        $group = Personnes::minimum(
            [
                'column' => 'ciudad_id',
                'group'  => 'estado',
                'order'  => 'minimum DESC',
            ]
        );

        $I->assertEquals(
            127591,
            $group[0]->minimum
        );

        $group = Personnes::minimum(
            [
                'column' => 'ciudad_id',
                'group'  => 'estado',
                'order'  => 'minimum ASC',
            ]
        );

        $I->assertEquals(
            20404,
            $group[0]->minimum
        );
    }

    /**
     * @dataProvider adaptersProvider
     */
    public function executeTestsRenamed(IntegrationTester $I, Example $example)
    {
        $diFunction = 'setDi' . $example[0];

        $this->{$diFunction}();

        $min = Pessoas::minimum(
            [
                'column' => 'cidadeId',
            ]
        );

        $I->assertEquals(
            20404,
            $min
        );

        $min = Pessoas::minimum(
            [
                'column'     => 'cidadeId',
                'conditions' => "estado='I'",
            ]
        );

        $I->assertEquals(
            127591,
            $min
        );

        $group = Pessoas::minimum(
            [
                'column' => 'cidadeId',
                'group'  => 'estado',
            ]
        );
        $I->assertCount(2, $group);

        $results = [
            'A' => 20404,
            'I' => 127591,
        ];

        foreach ($group as $row) {
            $I->assertEquals(
                $results[$row->estado],
                $row->minimum
            );
        }

        $group = Pessoas::minimum(
            [
                'column' => 'cidadeId',
                'group'  => 'estado',
                'order'  => 'minimum DESC',
            ]
        );

        $I->assertEquals(
            127591,
            $group[0]->minimum
        );

        $group = Pessoas::minimum(
            [
                'column' => 'cidadeId',
                'group'  => 'estado',
                'order'  => 'minimum ASC',
            ]
        );

        $I->assertEquals(
            20404,
            $group[0]->minimum
        );
    }

    private function adaptersProvider(): array
    {
        return [
            [
                'Mysql',
            ],
            [
                'Postgresql',
            ],
            [
                'Sqlite',
            ],
        ];
    }
}
