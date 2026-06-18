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

namespace Phalcon\Tests\Database\Db\RawValue;

use Phalcon\Db\RawValue;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

final class ConstructTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Db\RawValue :: __construct()
     *
     * @author       Sid Roberts <https://github.com/SidRoberts>
     * @since        2019-04-17
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    #[DataProvider('valueProvider')]
    public function testDbRawvalueConstruct(
        mixed $value,
        string $expected
    ): void {
        $rawValue = new RawValue($value);

        $this->assertEquals($expected, $rawValue->getValue());
    }

    public static function valueProvider(): array
    {
        return [
            [
                'hello',
                'hello',
            ],

            [
                null,
                'NULL',
            ],

            [
                123,
                '123',
            ],

            [
                '',
                "''",
            ],
        ];
    }
}
