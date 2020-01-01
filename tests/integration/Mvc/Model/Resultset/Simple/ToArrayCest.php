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

namespace Phalcon\Test\Integration\Mvc\Model\Resultset\Simple;

use Phalcon\Mvc\Model\Query\Builder;
use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Robots;

/**
 * Class ToArrayCest
 */
class ToArrayCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\Model\Resultset\Simple :: toArray()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-01
     */
    public function mvcModelResultsetSimpleToArray(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Resultset\Simple - toArray()');

        $this->newDi();
        $this->setDiModelsManager();
        $this->setDiModelsMetadata();
        $this->setDiMysql();

        $rows = (new Builder())
            ->from([
                'Robots' => Robots::class,
            ])
            ->orderBy('Robots.id DESC')
            ->columns([
                'Robots.id',
                'Robots.type',
                'robot_name' => 'Robots.name',
            ])
            ->getQuery()
            ->execute();

        //$renamedArray = $rows->toArray();
        $untouchedArray = $rows->toArray(false);

        $I->assertInternalType('array', $untouchedArray);
        //$I->assertInternalType('array', $renamedArray);
        $I->assertArrayHasKey('robot_name', $untouchedArray[0]);
    }
}
