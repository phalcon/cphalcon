<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Mvc\Model\Query\Builder;

use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Storage\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Mvc\RecordsTrait;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

final class OrderByTest extends AbstractDatabaseTestCase
{
    use DiTrait;
    use RecordsTrait;

    /**
     * Executed before each test
     *
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
     * @issue  https://github.com/phalcon/cphalcon/issues/15411
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-04-20
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelQueryBuilderOrderBy(): void
    {
        $builder = new Builder();
        $phql    = $builder
            ->columns('inv_id, inv_title')
            ->addFrom(Invoices::class)
            ->orderBy('inv_title')
            ->getPhql()
        ;

        $expected = 'SELECT inv_id, inv_title '
            . 'FROM [Phalcon\Tests\Support\Models\Invoices] '
            . 'ORDER BY inv_title';
        $actual   = $phql;
        $this->assertEquals($expected, $actual);

        $phql = $builder
            ->orderBy('inv_title DESC')
            ->getPhql()
        ;

        $expected = 'SELECT inv_id, inv_title '
            . 'FROM [Phalcon\Tests\Support\Models\Invoices] '
            . 'ORDER BY inv_title DESC';
        $actual   = $phql;
        $this->assertEquals($expected, $actual);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17077
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-05
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelQueryBuilderOrderByArrayComplexWithoutDirection(): void
    {
        $builder = new Builder();
        $phql    = $builder
            ->columns('inv_id, inv_title')
            ->addFrom(Invoices::class)
            ->orderBy(['COALESCE(inv_a, inv_b)'])
            ->getPhql()
        ;

        $expected = 'SELECT inv_id, inv_title '
            . 'FROM [Phalcon\Tests\Support\Models\Invoices] '
            . 'ORDER BY COALESCE(inv_a, inv_b)';
        $this->assertEquals($expected, $phql);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17077
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-05
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelQueryBuilderOrderByArraySimpleColumns(): void
    {
        $builder = new Builder();
        $builder
            ->columns('inv_id, inv_title')
            ->addFrom(Invoices::class)
        ;

        $prefix = 'SELECT inv_id, inv_title '
            . 'FROM [Phalcon\Tests\Support\Models\Invoices] '
            . 'ORDER BY ';

        // Bare column - autoescaped
        $this->assertEquals(
            $prefix . '[inv_title]',
            $builder->orderBy(['inv_title'])->getPhql()
        );

        // Column with direction - autoescaped, direction preserved
        $this->assertEquals(
            $prefix . '[inv_title] DESC',
            $builder->orderBy(['inv_title DESC'])->getPhql()
        );

        // Extra whitespace between column and direction is normalized
        $this->assertEquals(
            $prefix . '[inv_title] DESC',
            $builder->orderBy(['inv_title    DESC'])->getPhql()
        );

        // Lowercase direction is preserved as written
        $this->assertEquals(
            $prefix . '[inv_title] desc',
            $builder->orderBy(['inv_title desc'])->getPhql()
        );

        // Dotted identifier is left untouched by autoescape
        $this->assertEquals(
            $prefix . 'i.inv_title ASC',
            $builder->orderBy(['i.inv_title ASC'])->getPhql()
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-05
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelQueryBuilderOrderByWithComplexExpression(): void
    {
        $builder = new Builder();
        $phql    = $builder
            ->columns('inv_id, inv_title')
            ->addFrom(Invoices::class)
            ->orderBy(
                [
                    'CASE WHEN inv_status_flag = 1 THEN 0 ELSE 1 END ASC',
                    'NOT inv_status_flag',
                    'inv_title DESC',
                ]
            )
            ->getPhql()
        ;

        $expected = 'SELECT inv_id, inv_title '
            . 'FROM [Phalcon\Tests\Support\Models\Invoices] '
            . 'ORDER BY CASE WHEN inv_status_flag = 1 THEN 0 ELSE 1 END ASC, '
            . 'NOT inv_status_flag, [inv_title] DESC';
        $actual   = $phql;
        $this->assertEquals($expected, $actual);
    }
}
