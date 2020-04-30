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

namespace Phalcon\Test\Unit\Annotations\Reader;

use Phalcon\Annotations\Reader;
use UnitTester;

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
        $I->assertCount(4, $parsed);
        $I->assertEquals(
            [
                'type' => 300,
                'name' => 'var',
                'file' => 'eval code',
                'line' => 1,

            ],
            $parsed[0]
        );
        $I->assertEquals(
            [
                'type' => 300,
                'name' => 'Simple',
                'file' => 'eval code',
                'line' => 1,
            ],
            $parsed[1]
        );
        $I->assertEquals(
            [
                'type'      => 300,
                'name'      => 'SingleParam',
                'file'      => 'eval code',
                'line'      => 1,
                'arguments' => [
                    [
                        'expr' => [
                            'type'  => 303,
                            'value' => 'Param',
                        ],
                    ],
                ],
            ],
            $parsed[2]
        );
        $I->assertEquals(
            [
                'type'      => 300,
                'name'      => 'MultipleParams',
                'file'      => 'eval code',
                'line'      => 1,
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
            ],
            $parsed[3]
        );
    }
}
