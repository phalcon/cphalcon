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

namespace Phalcon\Tests\Database\Mvc\Model\Query\Builder;

use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

#[Group('phql')]
final class JoinTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * join() emits a plain JOIN; the typed helpers prefix the join keyword.
     *
     * @return array<string, array{0: string, 1: string}>
     */
    public static function getExamples(): array
    {
        return [
            'join'      => ['join', 'JOIN'],
            'innerJoin' => ['innerJoin', 'INNER JOIN'],
            'leftJoin'  => ['leftJoin', 'LEFT JOIN'],
            'rightJoin' => ['rightJoin', 'RIGHT JOIN'],
        ];
    }

    /**
     * Tests Phalcon\Mvc\Model\Query\Builder :: join()/innerJoin()/leftJoin()/rightJoin()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getExamples')]
    public function testMvcModelQueryBuilderJoin(string $method, string $keyword): void
    {
        $builder = new Builder();

        $phql = $builder
            ->columns('*')
            ->addFrom(Invoices::class)
            ->{$method}(Customers::class, 'Customers.cst_id = Invoices.inv_cst_id', 'c')
            ->getPhql();

        $expected = 'SELECT * '
            . 'FROM [' . Invoices::class . '] '
            . $keyword . ' [' . Customers::class . '] AS [c] '
            . 'ON Customers.cst_id = Invoices.inv_cst_id';

        $this->assertSame($expected, $phql);
    }
}
