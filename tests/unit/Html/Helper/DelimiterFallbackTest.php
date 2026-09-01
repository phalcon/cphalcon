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

namespace Phalcon\Tests\Unit\Html\Helper;

use Phalcon\Html\Escaper;
use Phalcon\Html\Helper\Input\Select;
use Phalcon\Html\Helper\Meta;
use Phalcon\Html\Helper\Ol;
use Phalcon\Html\Helper\Title;
use Phalcon\Html\Helper\Ul;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

use const PHP_EOL;

/**
 * Locks in how each helper resolves the `delimiter` argument of `__invoke()`.
 *
 * `AbstractList` treats any falsy delimiter as "not supplied" and falls back
 * to PHP_EOL. `AbstractSeries` and `Title` only fall back on `null`, so their
 * delimiter argument must stay nullable.
 */
final class DelimiterFallbackTest extends AbstractUnitTestCase
{
    /**
     * @return array<string, array{0: string|null}>
     */
    public static function getFalsyDelimiterExamples(): array
    {
        return [
            'empty string' => [''],
            'string zero'  => ['0'],
            'null'         => [null],
        ];
    }

    #[DataProvider('getFalsyDelimiterExamples')]
    public function testAbstractListFallsBackToPhpEol(?string $delimiter): void
    {
        $helper = new Ul(new Escaper());

        $helper('  ', $delimiter);
        $helper->add('a');
        $helper->add('b');

        $expected = '<ul>' . PHP_EOL
            . '  <li>a</li>' . PHP_EOL
            . '  <li>b</li>' . PHP_EOL
            . '</ul>';

        $this->assertSame($expected, (string) $helper);
    }

    public function testOlFallsBackToPhpEol(): void
    {
        $helper = new Ol(new Escaper());

        $helper('  ', '');
        $helper->add('a');

        $expected = '<ol>' . PHP_EOL
            . '  <li>a</li>' . PHP_EOL
            . '</ol>';

        $this->assertSame($expected, (string) $helper);
    }

    public function testSelectFallsBackToPhpEol(): void
    {
        $helper = new Select(new Escaper());

        $helper('  ', '');
        $helper->add('A', '1');

        $expected = '<select>' . PHP_EOL
            . '  <option value="1">A</option>' . PHP_EOL
            . '</select>';

        $this->assertSame($expected, (string) $helper);
    }

    /**
     * `AbstractSeries` keeps a nullable delimiter. Passing `null` must not
     * raise a TypeError.
     */
    public function testSeriesAcceptsNullDelimiter(): void
    {
        $helper = new Meta(new Escaper());

        $helper('  ', null);
        $helper->addName('a', 'b');

        $expected = '  <meta name="a" content="b">' . PHP_EOL;

        $this->assertSame($expected, (string) $helper);
    }

    /**
     * `Title` keeps a nullable delimiter. Passing `null` must not raise a
     * TypeError.
     */
    public function testTitleAcceptsNullDelimiter(): void
    {
        $helper = new Title(new Escaper());

        $helper('    ', null);
        $helper->set('Hi');

        $expected = '    <title>Hi</title>' . PHP_EOL;

        $this->assertSame($expected, (string) $helper);
    }
}
