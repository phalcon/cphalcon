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

namespace Phalcon\Tests\Integration\Mvc\Model\Query\Builder;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Snapshot\Robots;

class LimitCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests Phalcon\Mvc\Model\Query\Builder :: limit()
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12419
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2016-12-18
     *
     * @dataProvider limitOffsetProvider
     */
    public function mvcModelQueryBuilderLimit(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Mvc\Model\Query\Builder - limit()');

        $limit    = $example[0];
        $offset   = $example[1];
        $expected = $example[2];

        $builder = new Builder(null, $this->container);

        $phql = $builder
            ->columns(['name'])
            ->from(Robots::class)
            ->limit($limit, $offset)
            ->getPhql()
        ;

        $I->assertEquals(
        /** Just prevent IDE to highlight this as not valid SQL dialect */
            'SELECT name ' . "FROM {$expected}",
            $phql
        );
    }

    protected function limitOffsetProvider(): array
    {
        return [
            [-7, null, '[' . Robots::class . '] LIMIT :APL0:'],
            /**
             * @todo Check these examples
             */
            //  ["-7234", null, "[" . Robots::class . "] LIMIT :APL0:"],
            //  ["18", null, "[" . Robots::class . "] LIMIT :APL0:"],
            //  ["18", 2, "[" . Robots::class . "] LIMIT :APL0: OFFSET :APL1:"],
            //  ["-1000", -200, "[" . Robots::class . "] LIMIT :APL0: OFFSET :APL1:"],
            //  ["1000", "-200", "[" . Robots::class . "] LIMIT :APL0: OFFSET :APL1:"],
            //  ["0", "-200", "[" . Robots::class . "]"],
            //  [
            //      "%3CMETA%20HTTP-EQUIV%3D%22refresh%22%20CONT ENT%3D%220%3Burl%3Djavascript%3Aqss%3D7%22%3E",
            //      50, "[" . Robots::class . "]"
            //  ],
        ];
    }
}
