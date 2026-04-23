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

namespace Phalcon\Tests\Unit\Support\Helper\Str;

use Phalcon\Support\Helper\Str\Ucwords;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

final class UcwordsTest extends AbstractUnitTestCase
{
    /**
     * @return string[][]
     */
    public static function getData(): array
    {
        return [
            [
                'hello goodbye',
                'Hello Goodbye',
            ],

            [
                'HELLO GOODBYE',
                'Hello Goodbye',
            ],

            [
                '1234',
                '1234',
            ],
            [
                'ПРИВЕТ МИР!',
                'Привет Мир!',
            ],

            [
                'ПриВЕт Мир!',
                'Привет Мир!',
            ],

            [
                'привет мир!',
                'Привет Мир!',
            ],

            [
                'MÄNNER MÄNNER',
                'Männer Männer',
            ],

            [
                'mÄnnER mÄnnER',
                'Männer Männer',
            ],

            [
                'männer männer',
                'Männer Männer',
            ],
        ];
    }

    /**
     * @dataProvider getData
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    #[DataProvider('getData')]
    public function testSupportHelperStrUcwords(
        string $text,
        string $expected,
    ): void {
        $object = new Ucwords();
        $actual = $object($text);

        $this->assertSame($expected, $actual);
    }
}
