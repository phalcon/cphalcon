<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Mvc\Model\Resultset;

use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;
use TypeError;

#[Group('phql')]
final class FilterTest extends AbstractDatabaseTestCase
{
    use ResultsetFixtureTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $this->seedResultsetFixture();
    }

    /**
     * An identity filter keeps every record, so the returned array holds one
     * entry per row of the resultset.
     *
     * @return array<string, array{0: string, 1: int}>
     */
    public static function getExamples(): array
    {
        return [
            'simple'  => ['simple', 3],
            'complex' => ['complex', 4],
            'empty'   => ['empty', 0],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getExamples')]
    public function testMvcModelResultsetFilter(string $type, int $expected): void
    {
        $resultset = $this->getResultset($type);

        $filtered = $resultset->filter(
            fn ($record) => $record
        );

        $this->assertIsArray($filtered);
        $this->assertCount($expected, $filtered);
    }

    /**
     * A filter that cannot be called throws the TypeError of
     * call_user_func_array(). An empty resultset does not call the filter.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/815
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetFilterNotCallable(): void
    {
        $simple = $this->getResultset('simple');
        $empty  = $this->getResultset('empty');

        $this->assertSame([], $empty->filter('unknownFilterFunction'));

        $this->expectException(TypeError::class);
        $this->expectExceptionMessage(
            'call_user_func_array(): Argument #1 ($callback) must be a valid callback, '
            . 'function "unknownFilterFunction" not found or invalid function name'
        );

        $simple->filter('unknownFilterFunction');
    }
}
