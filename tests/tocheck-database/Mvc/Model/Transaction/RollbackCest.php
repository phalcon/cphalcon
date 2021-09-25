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

namespace Phalcon\Tests\Integration\Mvc\Model\Transaction;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Mvc\Model\Transaction\Failed;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Personas;

class RollbackCest
{
    use DiTrait;

    private $records = [];

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->records = [];
    }

    public function _after(IntegrationTester $I)
    {
        $db = $this->container->get('db');

        foreach ($this->records as $record) {
            $db->execute("DELETE FROM personas WHERE personas.cedula = '" . $record . "'");
        }

        $this->records = [];

        $db->close();
    }

    /**
     * Tests Phalcon\Mvc\Model\Transaction :: rollback()
     *
     * @dataProvider getFunctions
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function mvcModelTransactionRollback(IntegrationTester $I, Example $function)
    {
        $I->wantToTest('Mvc\Model\Transaction - rollback()');

        $method = $function[0];
        $this->$method();

        $tm = $this->container->getShared('transactionManager');

        $count       = Personas::count();
        $transaction = $tm->get();

        for ($i = 0; $i < 10; $i++) {
            $persona = new Personas();
            $persona->setTransaction($transaction);
            $persona->cedula            = 'T-Cx' . $i;
            $persona->tipo_documento_id = 1;
            $persona->nombres           = 'LOST LOST';
            $persona->telefono          = '2';
            $persona->cupo              = 0;
            $persona->estado            = 'A';

            $result = $persona->save();

            $this->records[] = $persona->cedula;
            $I->assertTrue($result);
        }

        $transaction->rollback();

        $I->assertEquals(
            $count,
            Personas::count()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model\Transaction :: rollback() - exception
     *
     * @dataProvider getFunctions
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function mvcModelTransactionRollbackException(IntegrationTester $I, Example $function)
    {
        $I->wantToTest('Mvc\Model\Transaction - rollback() - exception');

        $method = $function[0];
        $this->$method();

        $tm = $this->container->getShared('transactionManager');

        $count       = Personas::count();
        $transaction = $tm
            ->get()
            ->throwRollbackException(true)
        ;

        for ($i = 0; $i < 10; $i++) {
            $persona = new Personas();
            $persona->setTransaction($transaction);
            $persona->cedula            = 'T-Cx' . $i;
            $persona->tipo_documento_id = 1;
            $persona->nombres           = 'LOST LOST';
            $persona->telefono          = '2';
            $persona->cupo              = 0;
            $persona->estado            = 'A';

            $result = $persona->save();

            $this->records[] = $persona->cedula;

            $I->assertTrue($result);
        }

        $I->expectThrowable(
            new Failed('Transaction aborted'),
            function () use ($transaction) {
                $transaction->rollback();
            }
        );

        $I->assertEquals(
            $count,
            Personas::count()
        );
    }


    private function getFunctions(): array
    {
        return [
            ['setDiMysql'],
            ['setDiPostgresql'],
        ];
    }
}
