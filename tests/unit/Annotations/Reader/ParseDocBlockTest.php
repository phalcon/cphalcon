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
use Phalcon\Tests\AbstractUnitTestCase;

final class ParseDocBlockTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-21
     */
    public function testAnnotationsReaderParseDocBlock(): void
    {
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

        $this->assertIsArray($parsed);
        $this->assertCount(4, $parsed);
        $this->assertEquals(
            [
                'type' => 300,
                'name' => 'var',
                'file' => 'eval code',
                'line' => 1,
            ],
            $parsed[0]
        );
        $this->assertEquals(
            [
                'type' => 300,
                'name' => 'Simple',
                'file' => 'eval code',
                'line' => 1,
            ],
            $parsed[1]
        );
        $this->assertEquals(
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
        $this->assertEquals(
            [
                'type'      => 300,
                'name'      => 'MultipleParams',
                'file'      => 'eval code',
                'line'      => 1,
                'arguments' => [
                    ['expr' => ['type' => 303, 'value' => 'First']],
                    ['expr' => ['type' => 307, 'value' => 'Second']],
                    ['expr' => ['type' => 301, 'value' => '1']],
                    ['expr' => ['type' => 302, 'value' => '1.1']],
                    ['expr' => ['type' => 301, 'value' => '-10']],
                    ['expr' => ['type' => 305]],
                    ['expr' => ['type' => 306]],
                    ['expr' => ['type' => 304]],
                ],
            ],
            $parsed[3]
        );
    }

    /**
     * An annotation argument that is a string containing a parenthesis must be
     * parsed correctly - the parenthesis inside the string is not a structural
     * one and must not break the docblock scanning.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-05
     * @issue  https://github.com/phalcon/cphalcon/issues/16084
     */
    public function testAnnotationsReaderParseDocBlockParenthesesInString(): void
    {
        $docBlock = <<<EOF
/**
 * @SingleQuoteOpenParen(key='value(')
 * @SingleQuoteCloseParen(key='value)')
 * @DoubleQuoteParens(key="value()")
 */
EOF;

        $reader = new Reader();
        $parsed = $reader->parseDocBlock($docBlock);

        $this->assertIsArray($parsed);
        $this->assertCount(3, $parsed);

        $this->assertSame('SingleQuoteOpenParen', $parsed[0]['name']);
        $this->assertSame('key', $parsed[0]['arguments'][0]['name']);
        $this->assertSame('value(', $parsed[0]['arguments'][0]['expr']['value']);

        $this->assertSame('SingleQuoteCloseParen', $parsed[1]['name']);
        $this->assertSame('value)', $parsed[1]['arguments'][0]['expr']['value']);

        $this->assertSame('DoubleQuoteParens', $parsed[2]['name']);
        $this->assertSame('value()', $parsed[2]['arguments'][0]['expr']['value']);
    }
}
