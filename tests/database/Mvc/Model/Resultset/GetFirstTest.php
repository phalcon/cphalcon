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

namespace Phalcon\Tests\Database\Mvc\Model\Resultset;

use Phalcon\Mvc\Model\ManagerInterface;
use Phalcon\Mvc\Model\Resultset;
use Phalcon\Mvc\Model\Row;
use Phalcon\Storage\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Mvc\RecordsTrait;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;
use stdClass;

use function get_debug_type;

#[Group('phql')]
final class GetFirstTest extends AbstractDatabaseTestCase
{
    use DiTrait;
    use RecordsTrait;

    /**
     * @var InvoicesMigration
     */
    private $invoiceMigration;

    /**
     * Executed before each test
     */
    public function setUp(): void
    {
        try {
            $this->setNewFactoryDefault();
        } catch (Exception $e) {
            $this->fail($e->getMessage());
        }

        $this->setDatabase();

        $this->invoiceMigration = new InvoicesMigration(self::getPdoConnection());
    }

    /**
     * The hydration mode and the type of the row.
     *
     * @return array<string, array{0: int, 1: string}>
     */
    public static function getHydrateModeExamples(): array
    {
        return [
            'arrays'  => [Resultset::HYDRATE_ARRAYS, 'array'],
            'objects' => [Resultset::HYDRATE_OBJECTS, stdClass::class],
        ];
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/15027
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-05-06
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetGetFirst(): void
    {
        /**
         * @todo The following tests are skipped for sqlite because we will get
         *       a General Error 5 database is locked error.
         */
        $invId = ('sqlite' === self::getDriver()) ? 'null' : 'default';

        $this->insertDataInvoices($this->invoiceMigration, 7, $invId, 2, 'ccc');

        /** @var ManagerInterface $manager */
        $manager = $this->getService('modelsManager');

        $sql = sprintf('SELECT i.inv_id FROM [%s] AS i', Invoices::class);
        $this->assertInstanceOf(Row::class, $manager->createQuery($sql)->execute()->getFirst());

        $sql = sprintf('SELECT * FROM [%s] AS i', Invoices::class);
        $this->assertInstanceOf(Invoices::class, $manager->createQuery($sql)->execute()->getFirst());

        $sql = sprintf('SELECT i.inv_id FROM [%s] AS i WHERE inv_total = -42', Invoices::class);
        $this->assertNull($manager->createQuery($sql)->execute()->getFirst());
    }

    /**
     * With the hydration mode arrays or objects, getFirst() on a simple
     * resultset gives the row as an array or a stdClass.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/819
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getHydrateModeExamples')]
    public function testMvcModelResultsetGetFirstHydrateMode(int $mode, string $expected): void
    {
        $this->invoiceMigration->insert(1, 1, 0, 'inv-title-1');
        $this->invoiceMigration->insert(2, 1, 0, 'inv-title-2');

        $resultset = Invoices::find(['order' => 'inv_id']);
        $resultset->setHydrateMode($mode);

        $first = $resultset->getFirst();

        $this->assertSame($expected, get_debug_type($first));
        $this->assertSame('inv-title-1', ((array) $first)['inv_title']);
    }
}
