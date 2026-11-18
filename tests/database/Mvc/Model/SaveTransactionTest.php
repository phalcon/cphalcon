<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Mvc\Model;

use PDO;
use Phalcon\Db\Adapter\Pdo\AbstractPdo;
use Phalcon\Mvc\Model\Exceptions\BelongsToRequiresObject;
use Phalcon\Mvc\Model\Exceptions\RelationNotDefined;
use Phalcon\Mvc\Model\Exceptions\RelationRequiresObjectOrArray;
use Phalcon\Mvc\Model\ValidationFailed;
use Phalcon\Support\Settings;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\CustomersMigration;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\CustomersRelatedToSave;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;
use Throwable;

/**
 * A save with related records runs in a transaction. When the save throws an
 * exception or fails, the transaction must not stay open.
 */
final class SaveTransactionTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        /** @var PDO $connection */
        $connection = self::getPdoConnection();
        (new CustomersMigration($connection));
        (new InvoicesMigration($connection));
    }

    public function tearDown(): void
    {
        Settings::reset();

        parent::tearDown();
    }

    /**
     * @return array<string, array{0: array<string, mixed>, 1: class-string}>
     */
    public static function getRelatedRecordsThatThrow(): array
    {
        return [
            'belongsTo not an object'        => [
                ['invoice' => 'abc'],
                BelongsToRequiresObject::class,
            ],
            'hasMany not an object or array' => [
                ['invoices' => 'abc'],
                RelationRequiresObjectOrArray::class,
            ],
            'no relation'                    => [
                ['unknown' => 'abc'],
                RelationNotDefined::class,
            ],
        ];
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17756
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-17
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getRelatedRecordsThatThrow')]
    public function testMvcModelSaveTransactionRelatedThrowsClosesTransaction(
        array $related,
        string $exceptionClass
    ): void {
        $customer                 = new CustomersRelatedToSave();
        $customer->cst_name_first = 'first';
        $customer->setRelatedToSave($related);

        /** @var AbstractPdo $connection */
        $connection = $customer->getWriteConnection();

        $actual = null;
        try {
            $customer->save();
        } catch (Throwable $ex) {
            $actual = $ex;
        }

        $underTransaction = $this->closeTransaction($connection);

        $this->assertInstanceOf($exceptionClass, $actual);
        $this->assertFalse($underTransaction);
        $this->assertSame(0, Customers::count());
    }

    /**
     * A transaction that the user began stays open. The save rolls back only
     * its own level.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17756
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-17
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getRelatedRecordsThatThrow')]
    public function testMvcModelSaveTransactionRelatedThrowsKeepsOuterTransaction(
        array $related,
        string $exceptionClass
    ): void {
        $customer                 = new CustomersRelatedToSave();
        $customer->cst_name_first = 'first';
        $customer->setRelatedToSave($related);

        /** @var AbstractPdo $connection */
        $connection = $customer->getWriteConnection();
        $connection->begin();

        $actual = null;
        try {
            $customer->save();
        } catch (Throwable $ex) {
            $actual = $ex;
        }

        $level            = $connection->getTransactionLevel();
        $underTransaction = $this->closeTransaction($connection);

        $this->assertInstanceOf($exceptionClass, $actual);
        $this->assertSame(1, $level);
        $this->assertTrue($underTransaction);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17756
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-17
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelSaveTransactionValidationFailedClosesTransaction(): void
    {
        Settings::set('orm.exception_on_failed_save', true);

        $customer                 = new CustomersRelatedToSave();
        $customer->cst_name_first = 'first';
        $customer->setFailValidation(true);
        $customer->setRelatedToSave(['invoices' => []]);

        /** @var AbstractPdo $connection */
        $connection = $customer->getWriteConnection();

        $actual = null;
        try {
            $customer->save();
        } catch (Throwable $ex) {
            $actual = $ex;
        }

        $underTransaction = $this->closeTransaction($connection);

        $this->assertInstanceOf(ValidationFailed::class, $actual);
        $this->assertFalse($underTransaction);
        $this->assertSame(0, Customers::count());
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17756
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-17
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelSaveTransactionValidationFailsClosesTransaction(): void
    {
        $customer                 = new CustomersRelatedToSave();
        $customer->cst_name_first = 'first';
        $customer->setFailValidation(true);
        $customer->setRelatedToSave(['invoices' => []]);

        /** @var AbstractPdo $connection */
        $connection = $customer->getWriteConnection();

        $actual           = $customer->save();
        $underTransaction = $this->closeTransaction($connection);

        $this->assertFalse($actual);
        $this->assertFalse($underTransaction);
        $this->assertSame(0, Customers::count());
    }

    /**
     * Returns if the connection is in a transaction, then rolls back each
     * open level. With MySQL and PostgreSQL, an open transaction locks the
     * tables, and the next setUp() waits.
     */
    private function closeTransaction(AbstractPdo $connection): bool
    {
        $underTransaction = $connection->isUnderTransaction();

        while ($connection->getTransactionLevel() > 0) {
            $connection->rollback(false);
        }

        return $underTransaction;
    }
}
