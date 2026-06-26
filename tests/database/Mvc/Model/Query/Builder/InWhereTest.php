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
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

#[Group('phql')]
final class InWhereTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * inWhere()/notInWhere() append a (NOT) IN condition with one auto
     * bind-param per value.
     *
     * @return array<string, array{0: string, 1: string}>
     */
    public static function getExamples(): array
    {
        return [
            'inWhere'    => ['inWhere', 'IN'],
            'notInWhere' => ['notInWhere', 'NOT IN'],
        ];
    }

    /**
     * Tests Phalcon\Mvc\Model\Query\Builder :: inWhere()/notInWhere()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getExamples')]
    public function testMvcModelQueryBuilderInWhere(string $method, string $keyword): void
    {
        $builder = new Builder();

        $phql = $builder
            ->columns('*')
            ->addFrom(Invoices::class)
            ->{$method}('inv_status_flag', [1, 2, 3])
            ->getPhql();

        $expected = 'SELECT * '
            . 'FROM [' . Invoices::class . '] '
            . 'WHERE inv_status_flag ' . $keyword . ' (:AP0:, :AP1:, :AP2:)';

        $this->assertSame($expected, $phql);
    }
}
