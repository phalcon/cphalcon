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
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class AutoescapeTest extends AbstractDatabaseTestCase
{
    /**
     * A bare identifier is wrapped in brackets; identifiers that already
     * contain a bracket, dot, parenthesis, or are numeric are left untouched.
     *
     * Tests Phalcon\Mvc\Model\Query\Builder :: autoescape()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelQueryBuilderAutoescape(): void
    {
        $builder = new Builder();

        $this->assertSame('[name]', $builder->autoescape('name'));
        $this->assertSame('a.b', $builder->autoescape('a.b'));
        $this->assertSame('COUNT(*)', $builder->autoescape('COUNT(*)'));
        $this->assertSame('[col]', $builder->autoescape('[col]'));
        $this->assertSame('5', $builder->autoescape('5'));
    }
}
