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

namespace Phalcon\Tests\Database\Db\Adapter\Pdo;

use Phalcon\Db\Dialect\Postgresql as DialectPostgresql;
use Phalcon\Db\Reference;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

use function env;

final class PostgresqlTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    /**
     * Executed before each test
     *
     * @return void
     */
    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * @return array<array{0: string, 1: bool}>
     */
    public static function getShouldAddForeignKeyProvider(): array
    {
        return [
            ['fk1', true],
            ['fk2', true],
        ];
    }

    /**
     * @return array<array{0: string, 1: int}>
     */
    public static function getShouldCheckAddedForeignKeyProvider(): array
    {
        return [
            [self::getForeignKeySql('fk1'), 1],
            [self::getForeignKeySql('foreign_key_child_child_int_fkey'), 1],
        ];
    }

    /**
     * @return array<array{0: string, 1: bool}>
     */
    public static function getShouldDropForeignKeyProvider(): array
    {
        return [
            ['fk1', true],
            ['foreign_key_child_child_int_fkey', true],
        ];
    }

    /**
     * @param string $foreignKeyName
     *
     * @return string
     */
    private static function getForeignKeySql(string $foreignKeyName): string
    {
        $sql = rtrim(
            (string) file_get_contents(
                supportDir('assets/Db/postgresql/example9.sql')
            )
        );

        return str_replace('%_FK_%', $foreignKeyName, $sql);
    }

    /**
     * Tests Postgresql::addForeignKey
     *
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-07-05
     */
    #[Group('pgsql')]
    #[DataProvider('getShouldAddForeignKeyProvider')]
    public function testDbAdapterPdoPostgresqlShouldAddForeignKey(
        string $reference,
        bool $expected
    ): void {
        $db      = $this->container->get('db');
        $dialect = new DialectPostgresql();

        $references = $this->getReferenceAddForeignKey();
        $sql        = $dialect->addForeignKey(
            'foreign_key_child',
            'public',
            $references[$reference]
        );

        $this->assertEquals($expected, $db->execute($sql));
    }

    /**
     * Tests Postgresql::is created
     *
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-07-05
     */
    #[Group('pgsql')]
    #[DataProvider('getShouldCheckAddedForeignKeyProvider')]
    public function testDbAdapterPdoPostgresqlShouldCheckAddedForeignKey(
        string $sql,
        int $expected
    ): void {
        $db = $this->container->get('db');

        $this->assertEquals($expected, $db->execute($sql));
    }

    /**
     * Tests Postgresql::describeReferences
     *
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-08-18
     */
    #[Group('pgsql')]
    public function testDbAdapterPdoPostgresqlShouldCreateReferenceObject(): void
    {
        $db = $this->container->get('db');

        $expected = new Reference(
            'test_describereferences',
            [
                'referencedTable'   => 'foreign_key_parent',
                'referencedSchema'  => env('DATA_POSTGRES_NAME'),
                'columns'           => ['child_int'],
                'referencedColumns' => ['refer_int'],
                'onUpdate'          => 'CASCADE',
                'onDelete'          => 'RESTRICT',
            ]
        );

        $references = $db->describeReferences('foreign_key_child', 'public');

        /**
         * The sibling add/drop foreign-key tests in this class mutate the
         * shared foreign_key_child table, so assert the schema-defined
         * reference is present and correctly described rather than that it is
         * the only one on the table (mirrors DescribeReferencesTest).
         */
        $this->assertArrayHasKey('test_describereferences', $references);
        $this->assertEquals($expected, $references['test_describereferences']);
    }

    /**
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-07-05
     */
    #[Group('pgsql')]
    #[DataProvider('getShouldDropForeignKeyProvider')]
    public function testDbAdapterPdoPostgresqlShouldDropForeignKey(
        string $reference,
        bool $expected
    ): void {
        $db      = $this->container->get('db');
        $dialect = new DialectPostgresql();

        $sql = $dialect->dropForeignKey('foreign_key_child', 'public', $reference);

        $this->assertEquals($expected, $db->execute($sql));
    }

    /**
     * @return array<string, Reference>
     */
    private function getReferenceAddForeignKey(): array
    {
        return [
            'fk1' => new Reference(
                'fk1',
                [
                    'referencedTable'   => 'foreign_key_parent',
                    'columns'           => ['child_int'],
                    'referencedColumns' => ['refer_int'],
                    'onDelete'          => 'CASCADE',
                    'onUpdate'          => 'RESTRICT',
                ]
            ),
            'fk2' => new Reference(
                '',
                [
                    'referencedTable'   => 'foreign_key_parent',
                    'columns'           => ['child_int'],
                    'referencedColumns' => ['refer_int'],
                ]
            ),
        ];
    }
}
