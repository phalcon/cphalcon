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

namespace Phalcon\Tests\Database\Mvc\Model\Resultset;

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

#[Group('phql')]
final class UpdateTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $connection = self::getPdoConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(1, 1, 0, 'Test Invoice One');
        $migration->insert(2, 1, 0, 'Test Invoice Two');
    }

    public function tearDown(): void
    {
        $this->tearDownDatabase();
    }

    /**
     * @return array<string, array{0: bool}>
     */
    public static function getTransactionExamples(): array
    {
        return [
            'outer transaction'       => [false],
            'stale transaction level' => [true],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetUpdate(): void
    {
        $invoices = Invoices::find(
            [
                'conditions' => 'inv_status_flag = 0',
            ]
        );

        $this->assertTrue(
            $invoices->update(['inv_status_flag' => 1])
        );
    }

    /**
     * Updating a resultset inside an outer transaction must not commit it
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-16
     * @issue  https://github.com/phalcon/cphalcon/issues/17546
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getTransactionExamples')]
    public function testMvcModelResultsetUpdateInsideTransaction(bool $stale): void
    {
        $db         = $this->container->get('db');
        $parameters = [
            'conditions' => 'inv_status_flag = 0',
        ];

        if ($stale) {
            $db->begin();
            $db->getInternalHandler()->commit();
        }

        $this->assertTrue($db->begin());
        $this->assertTrue(
            Invoices::find($parameters)->update(['inv_status_flag' => 1])
        );
        $this->assertSame(0, Invoices::count($parameters));
        $this->assertSame(1, $db->getTransactionLevel());
        $this->assertTrue($db->isUnderTransaction());

        $this->assertTrue($db->rollback());
        $this->assertSame(2, Invoices::count($parameters));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    public function testMvcModelResultsetUpdateThrowsOnInvalidData(): void
    {
        $invoices = Invoices::find(
            [
                'conditions' => 'inv_status_flag = 0',
            ]
        );

        $this->expectException(\PDOException::class);

        $invoices->update(['inv_title' => str_repeat('a', 1000)]);
    }
}
