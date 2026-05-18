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

namespace Phalcon\Tests\Database\Db\Check;

use Phalcon\Db\Check;
use Phalcon\Db\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;

final class ConstructTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Db\Check :: __construct() — named CHECK with expression.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbCheckConstructNamed(): void
    {
        $check = new Check(
            'chk_price_positive',
            [
                'expression' => 'price > 0',
            ]
        );

        $this->assertSame('chk_price_positive', $check->getName());
        $this->assertSame('price > 0', $check->getExpression());
    }

    /**
     * Tests Phalcon\Db\Check :: __construct() — unnamed (empty string name)
     * is allowed; the dialect emits the clause without a `CONSTRAINT` prefix.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbCheckConstructUnnamed(): void
    {
        $check = new Check(
            '',
            [
                'expression' => 'qty >= 1',
            ]
        );

        $this->assertSame('', $check->getName());
        $this->assertSame('qty >= 1', $check->getExpression());
    }

    /**
     * Tests Phalcon\Db\Check :: __construct() — throws when `expression` is
     * missing from the definition array.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbCheckExpressionRequired(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('CHECK expression is required');

        new Check('chk_missing', []);
    }

    /**
     * Tests Phalcon\Db\Check :: __construct() — throws when `expression` is
     * an empty string.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbCheckExpressionEmptyRejected(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'CHECK expression must be a non-empty string'
        );

        new Check(
            'chk_empty',
            [
                'expression' => '',
            ]
        );
    }
}
