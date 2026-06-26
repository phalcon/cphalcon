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

namespace Phalcon\Tests\Database\Mvc\Model\Relation;

use Phalcon\Mvc\Model\Relation;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class IsThroughTest extends AbstractDatabaseTestCase
{
    /**
     * isThrough() is true only for the has-one/has-many through types.
     *
     * @return array<string, array{0: int, 1: bool}>
     */
    public static function getExamples(): array
    {
        return [
            'belongsTo'      => [Relation::BELONGS_TO, false],
            'hasOne'         => [Relation::HAS_ONE, false],
            'hasMany'        => [Relation::HAS_MANY, false],
            'hasOneThrough'  => [Relation::HAS_ONE_THROUGH, true],
            'hasManyThrough' => [Relation::HAS_MANY_THROUGH, true],
        ];
    }

    /**
     * Tests Phalcon\Mvc\Model\Relation :: isThrough()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    #[DataProvider('getExamples')]
    public function testMvcModelRelationIsThrough(int $type, bool $expected): void
    {
        $relation = new Relation($type, 'RefModel', 'id', 'ref', []);

        $this->assertSame($expected, $relation->isThrough());
    }
}
