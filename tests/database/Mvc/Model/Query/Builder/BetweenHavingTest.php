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
final class BetweenHavingTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * betweenHaving()/notBetweenHaving() append a (NOT) BETWEEN condition to
     * the HAVING clause with auto bind-params.
     *
     * @return array<string, array{0: string, 1: string}>
     */
    public static function getExamples(): array
    {
        return [
            'betweenHaving'    => ['betweenHaving', 'BETWEEN'],
            'notBetweenHaving' => ['notBetweenHaving', 'NOT BETWEEN'],
        ];
    }

    /**
     * Tests Phalcon\Mvc\Model\Query\Builder :: betweenHaving()/notBetweenHaving()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getExamples')]
    public function testMvcModelQueryBuilderBetweenHaving(string $method, string $keyword): void
    {
        $builder = new Builder();

        $phql = $builder
            ->columns('*')
            ->addFrom(Invoices::class)
            ->{$method}('SUM(inv_total)', 100, 200)
            ->getPhql();

        $expected = 'SELECT * '
            . 'FROM [' . Invoices::class . '] '
            . 'HAVING SUM(inv_total) ' . $keyword . ' :AP0: AND :AP1:';

        $this->assertSame($expected, $phql);
    }
}
