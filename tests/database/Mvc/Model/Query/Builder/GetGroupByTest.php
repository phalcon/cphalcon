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
use Phalcon\Storage\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

final class GetGroupByTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    /**
     * @return void
     */
    public function setUp(): void
    {
        try {
            $this->setNewFactoryDefault();
        } catch (Exception $e) {
            $this->fail($e->getMessage());
        }

        $this->setDatabase();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelQueryBuilderGetGroupBy(): void
    {
        $builder = new Builder([], $this->container);
        $builder->from(Invoices::class)
                ->columns(['inv_status_flag', 'COUNT(*)'])
                ->groupBy(['inv_status_flag']);

        $expected = 'SELECT inv_status_flag, COUNT(*) FROM ['
            . Invoices::class
            . '] GROUP BY [inv_status_flag]';
        $actual   = $builder->getPhql();
        $this->assertSame($expected, $actual);
    }

    /**
     * Tests that function expressions in GROUP BY are not bracket-wrapped.
     *
     * @see    https://github.com/phalcon/cphalcon/issues/16599
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-04-29
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelQueryBuilderGetGroupByFunctionExpression(): void
    {
        $builder = new Builder([], $this->container);
        $builder->from(Invoices::class)
                ->columns([
                    "DATE_PART('year', inv_created_at) year",
                    'inv_status_flag',
                    'COUNT(*) count',
                ])
                ->groupBy([
                    "DATE_PART('year', inv_created_at)",
                    'inv_status_flag',
                ]);

        $expected = "SELECT DATE_PART('year', inv_created_at) year, inv_status_flag, COUNT(*) count"
            . ' FROM [' . Invoices::class . ']'
            . " GROUP BY DATE_PART('year', inv_created_at), [inv_status_flag]";
        $actual   = $builder->getPhql();
        $this->assertSame($expected, $actual);
    }
}
