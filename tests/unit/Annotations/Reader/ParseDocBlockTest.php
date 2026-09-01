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

use Phalcon\Annotations\Exception;
use Phalcon\Annotations\Reader;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

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
     * A docblock whose processed form ends while the scanner is in RAW mode
     * (`@!`, a lone `@`, text after the last annotation) must stop at the
     * terminator instead of reading past the buffer. The result is
     * deterministic across calls.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testAnnotationsReaderParseDocBlockEndOfInputInRawMode(): void
    {
        $reader = new Reader();

        foreach (['@!', '@', '/** @', '/** @Foo */ trailing text'] as $docBlock) {
            $first  = $reader->parseDocBlock($docBlock);
            $second = $reader->parseDocBlock($docBlock);

            $this->assertSame($first, $second, $docBlock);
        }

        $actual = $reader->parseDocBlock('/** @Foo */ trailing text');
        $this->assertIsArray($actual);
        $this->assertCount(1, $actual);
        $this->assertSame('Foo', $actual[0]['name']);
    }

    /**
     * The argument list is built in linear time; 40,000 arguments used to
     * take about nine seconds.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testAnnotationsReaderParseDocBlockLargeArgumentList(): void
    {
        $count    = 40000;
        $docBlock = '/** @Foo(' . implode(',', array_fill(0, $count, '1')) . ') */';
        $reader   = new Reader();

        $start  = microtime(true);
        $actual = $reader->parseDocBlock($docBlock);
        $spent  = microtime(true) - $start;

        $this->assertCount($count, $actual[0]['arguments']);
        $this->assertSame('1', $actual[0]['arguments'][$count - 1]['expr']['value']);
        $this->assertLessThan(3.0, $spent);
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

    /**
     * A backslash as the last byte of a quoted string must be a scanning
     * error, not an escape that swallows the terminator.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testAnnotationsReaderParseDocBlockTrailingBackslashInString(): void
    {
        $reader = new Reader();

        foreach (['/** @Foo("abc\\', "/** @Foo('abc\\"] as $docBlock) {
            $caught = null;

            try {
                $reader->parseDocBlock($docBlock);
            } catch (Exception $ex) {
                $caught = $ex;
            }

            $this->assertNotNull($caught, $docBlock);
            $this->assertStringContainsString('Scanning error', $caught->getMessage());
        }

        // An escaped quote inside the string still parses.
        $actual = $reader->parseDocBlock('/** @Foo("a\\"b") */');
        $this->assertIsArray($actual);
        $this->assertCount(1, $actual);
    }
}
