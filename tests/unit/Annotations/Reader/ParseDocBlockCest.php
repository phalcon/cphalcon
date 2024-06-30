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

namespace Phalcon\Tests\Unit\Annotations\Reader;

use Phalcon\Annotations\Reader;
use UnitTester;

use function ksort;

class ParseDocBlockCest
{
    /**
     * Tests Phalcon\Annotations\Reader :: parseDocBlock()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-21
     */
    public function annotationsReaderParseDocBlock(UnitTester $I)
    {
        $I->wantToTest('Annotations\Reader - parseDocBlock()');

        $docBlock = <<<EOF
/**
 * This is a property string
 *
 * @var string
 * @Simple
 * @SingleParam("Param")
 * @MultipleParams("First", Second, 1, 1.1, -10, false, true, null)
 */
EOF;

        $reader = new Reader();
        $parsed = $reader->parseDocBlock($docBlock);

        $I->assertIsArray($parsed);

        $expected = 4;
        $actual   = $parsed;
        $I->assertCount($expected, $actual);

        $expected = [
            'file' => 'eval code',
            'line' => 1,
            'name' => 'var',
            'type' => 300,
        ];
        ksort($parsed[0]);
        $actual = $parsed[0];
        $I->assertSame($expected, $actual);

        $expected = [
            'file' => 'eval code',
            'line' => 1,
            'name' => 'Simple',
            'type' => 300,
        ];
        ksort($parsed[1]);
        $actual = $parsed[1];
        $I->assertSame($expected, $actual);

        $expected = [
            'arguments' => [
                [
                    'expr' => [
                        'type'  => 303,
                        'value' => 'Param',
                    ],
                ],
            ],
            'file'      => 'eval code',
            'line'      => 1,
            'name'      => 'SingleParam',
            'type'      => 300,
        ];
        ksort($parsed[2]);
        $actual = $parsed[2];
        $I->assertSame($expected, $actual);

        $expected = [
            'arguments' => [
                [
                    'expr' => [
                        'type'  => 303,
                        'value' => 'First',
                    ],
                ],
                [
                    'expr' => [
                        'type'  => 307,
                        'value' => 'Second',
                    ],
                ],
                [
                    'expr' => [
                        'type'  => 301,
                        'value' => '1',
                    ],
                ],
                [
                    'expr' => [
                        'type'  => 302,
                        'value' => '1.1',
                    ],
                ],
                [
                    'expr' => [
                        'type'  => 301,
                        'value' => '-10',
                    ],
                ],
                [
                    'expr' => [
                        'type' => 305,
                    ],
                ],
                [
                    'expr' => [
                        'type' => 306,
                    ],
                ],
                [
                    'expr' => [
                        'type' => 304,
                    ],
                ],
            ],
            'file'      => 'eval code',
            'line'      => 1,
            'name'      => 'MultipleParams',
            'type'      => 300,
        ];
        ksort($parsed[3]);
        $actual = $parsed[3];
        $I->assertSame($expected, $actual);
    }
}
