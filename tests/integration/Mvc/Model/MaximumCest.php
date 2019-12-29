<?php

declare(strict_types=1);

namespace Phalcon\Test\Integration\Mvc\Model;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Personnes;
use Phalcon\Test\Models\Pessoas;

class MaximumCest
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

        $max = Personnes::maximum(
            [
                'column' => 'ciudad_id',
            ]
        );
        $I->assertEquals($max, 302172);

        $max = Personnes::maximum(
            [
                'column' => 'ciudad_id', 'conditions' => "estado='I'",
            ]
        );
        $I->assertEquals($max, 127591);

        $group = Personnes::maximum(
            [
                'column' => 'ciudad_id',
                'group'  => 'estado',
            ]
        );
        $I->assertCount(2, $group);

        $results = [
            'A' => 302172,
            'I' => 127591,
        ];

        foreach ($group as $row) {
            $I->assertEquals($results[$row->estado], $row->maximum);
        }

        $group = Personnes::maximum(
            [
                'column' => 'ciudad_id',
                'group'  => 'estado',
                'order'  => 'maximum DESC',
            ]
        );
        $I->assertEquals($group[0]->maximum, 302172);
    }

    /**
     * @dataProvider adaptersProvider
     */
    public function executeTestsRenamed(IntegrationTester $I, Example $example)
    {
        $diFunction = 'setDi' . $example[0];

        $this->{$diFunction}();

        $max = Pessoas::maximum(
            [
                'column' => 'cidadeId',
            ]
        );
        $I->assertEquals(302172, $max);

        $max = Pessoas::maximum(
            [
                'column'     => 'cidadeId',
                'conditions' => "estado='I'",
            ]
        );
        $I->assertEquals(127591, $max);

        $group = Pessoas::maximum(
            [
                'column' => 'cidadeId',
                'group'  => 'estado',
            ]
        );

        $I->assertCount(2, $group);

        $results = [
            'A' => 302172,
            'I' => 127591,
        ];

        foreach ($group as $row) {
            $I->assertEquals(
                $results[$row->estado],
                $row->maximum
            );
        }

        $group = Pessoas::maximum(
            [
                'column' => 'cidadeId',
                'group'  => 'estado',
                'order'  => 'maximum DESC',
            ]
        );

        $I->assertEquals(
            302172,
            $group[0]->maximum
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
