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

namespace Phalcon\Tests\Database\Mvc\Model\Query;

use Phalcon\Mvc\Model\Query;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

use function sprintf;
use function substr_count;

#[Group('phql')]
final class SubSelectArrayPlaceholderTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        Query::clean();
    }

    /**
     * When the same outer PHQL embeds a sub-SELECT with an array
     * placeholder (e.g. `{ids:array}`) and is executed twice with the
     * same bind name but a different number of bind values, the
     * dialect must expand the placeholder against the current count
     * on each call. Previously the parse-time `times` baked into the
     * cached intermediate leaked into the nested SELECT because the
     * outer `bindCounts` was not propagated to the recursive
     * `Dialect::select()` call.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17004
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    public function testMvcModelQuerySubSelectArrayPlaceholderRefreshesPlaceholderCount(): void
    {
        $phql = sprintf(
            'SELECT [%s].* FROM [%s] WHERE inv_id IN '
            . '(SELECT [%s].inv_id FROM [%s] WHERE inv_id IN ({ids:array}))',
            Invoices::class,
            Invoices::class,
            Invoices::class,
            Invoices::class
        );

        $firstQuery = new Query($phql, $this->container);
        $firstQuery->setBindParams(['ids' => [1, 2]]);
        $firstSql = $firstQuery->getSql()['sql'];

        $this->assertSame(
            2,
            substr_count($firstSql, ':ids'),
            'first call should render two :ids placeholders'
        );

        $secondQuery = new Query($phql, $this->container);
        $secondQuery->setBindParams(['ids' => [1, 2, 3]]);
        $secondSql = $secondQuery->getSql()['sql'];

        $this->assertSame(
            3,
            substr_count($secondSql, ':ids'),
            'second call with three bind values must render three :ids placeholders'
        );
    }
}
