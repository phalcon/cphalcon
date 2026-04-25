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

namespace Phalcon\Tests\Database\Mvc\Model\Transaction;

use Phalcon\Mvc\Model\Transaction\Failed;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\PersonasMigration;
use Phalcon\Tests\Support\Models\Personas;
use Phalcon\Tests\Support\Traits\DiTrait;

/**
 *
 * @group phql
 */
final class RollbackTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $connection = self::getConnection();
        new PersonasMigration($connection);
    }

    public function tearDown(): void
    {
        $this->tearDownDatabase();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     * @group pgsql
     */
    public function testMvcModelTransactionRollback(): void
    {
        $tm          = $this->container->getShared('transactionManager');
        $count       = Personas::count();
        $transaction = $tm->get();

        for ($i = 0; $i < 10; $i++) {
            $persona                    = new Personas();
            $persona->setTransaction($transaction);
            $persona->cedula            = 'T-Cx' . $i;
            $persona->tipo_documento_id = 1;
            $persona->nombres           = 'LOST LOST';
            $persona->telefono          = '2';
            $persona->cupo              = 0;
            $persona->estado            = 'A';

            $result = $persona->save();

            $this->assertTrue($result);
        }

        $transaction->rollback();

        $expected = $count;
        $actual   = Personas::count();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     * @group pgsql
     */
    public function testMvcModelTransactionRollbackException(): void
    {
        $tm    = $this->container->getShared('transactionManager');
        $count = Personas::count();

        $transaction = $tm
            ->get()
            ->throwRollbackException(true)
        ;

        for ($i = 0; $i < 10; $i++) {
            $persona                    = new Personas();
            $persona->setTransaction($transaction);
            $persona->cedula            = 'T-Ex' . $i;
            $persona->tipo_documento_id = 1;
            $persona->nombres           = 'LOST LOST';
            $persona->telefono          = '2';
            $persona->cupo              = 0;
            $persona->estado            = 'A';

            $result = $persona->save();

            $this->assertTrue($result);
        }

        $this->expectException(Failed::class);
        $this->expectExceptionMessage('Transaction aborted');

        $transaction->rollback();

        $expected = $count;
        $actual   = Personas::count();
        $this->assertSame($expected, $actual);
    }
}
