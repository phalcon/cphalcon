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

namespace Phalcon\Test\Integration\Mvc\Model\Transaction\Manager;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Mvc\Model\Transaction;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class GetCest
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
     * Tests Phalcon\Mvc\Model\Transaction\Manager :: get()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2012-08-07
     *
     * @dataProvider adaptersProvider
     */
    public function mvcModelTransactionManagerGet(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Mvc\Model\Transaction\Manager - get() with ' . $example[0]);

        $diFunction = 'setDi' . $example[0];

        $this->{$diFunction}();

        $tm = $this->container->getShared('transactionManager');
        $db = $this->container->getShared('db');

        $transaction = $tm->get();

        $I->assertInstanceOf(
            Transaction::class,
            $transaction
        );

        $I->assertSame(
            $transaction,
            $tm->get(true)
        );

        $I->assertSame(
            $transaction,
            $tm->get(false)
        );

        $I->assertEquals(
            $db->getConnectionId(),
            $transaction->getConnection()->getConnectionId()
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
