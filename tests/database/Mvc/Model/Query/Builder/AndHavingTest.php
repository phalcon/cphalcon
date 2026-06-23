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
final class AndHavingTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    /**
     * andHaving()/orHaving() nest the new condition onto the current HAVING
     * clause with the matching glue.
     *
     * @return array<string, array{0: string, 1: string}>
     */
    public static function getExamples(): array
    {
        return [
            'andHaving' => ['andHaving', 'AND'],
            'orHaving'  => ['orHaving', 'OR'],
        ];
    }

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Mvc\Model\Query\Builder :: andHaving()/orHaving()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getExamples')]
    public function testMvcModelQueryBuilderAndHaving(string $method, string $glue): void
    {
        $builder = new Builder();

        $phql = $builder
            ->columns('*')
            ->addFrom(Invoices::class)
            ->having('SUM(inv_total) > 0')
            ->{$method}('COUNT(*) > 1')
            ->getPhql();

        $expected = 'SELECT * '
            . 'FROM [' . Invoices::class . '] '
            . 'HAVING (SUM(inv_total) > 0) ' . $glue . ' (COUNT(*) > 1)';

        $this->assertSame($expected, $phql);
    }
}
