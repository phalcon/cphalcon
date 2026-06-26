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
final class GetForeignKeyTest extends AbstractDatabaseTestCase
{
    /**
     * getForeignKey() returns a truthy foreignKey option, otherwise false.
     *
     * @return array<string, array{0: array, 1: mixed}>
     */
    public static function getExamples(): array
    {
        return [
            'array'  => [
                ['foreignKey' => ['action' => Relation::ACTION_CASCADE]],
                ['action' => Relation::ACTION_CASCADE]
            ],
            'true'   => [['foreignKey' => true], true],
            'false'  => [['foreignKey' => false], false],
            'absent' => [[], false],
        ];
    }

    /**
     * Tests Phalcon\Mvc\Model\Relation :: getForeignKey()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    #[DataProvider('getExamples')]
    public function testMvcModelRelationGetForeignKey(array $options, mixed $expected): void
    {
        $relation = new Relation(
            Relation::BELONGS_TO,
            'RefModel',
            'field',
            'refField',
            $options
        );

        $this->assertSame($expected, $relation->getForeignKey());
    }
}
