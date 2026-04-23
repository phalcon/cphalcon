<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Title;

use Phalcon\Html\Escaper;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Title;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;

use function uniqid;

use const PHP_EOL;

final class UnderscoreInvokeTest extends AbstractUnitTestCase
{
    /**
     * @return array
     */
    public static function getExamples(): array
    {
        return [
            [
                '',
                '',
                '',
                [],
                'Accounting',
                false,
                [],
                'Accounting',
                '<title>Accounting</title>',
            ],
            [
                '',
                '',
                '',
                [],
                '<Accounting>',
                false,
                [],
                '&lt;Accounting&gt;',
                '<title>&lt;Accounting&gt;</title>',
            ],
            [
                '',
                '',
                '',
                [],
                '<Accounting>',
                true,
                [],
                '<Accounting>',
                '<title><Accounting></title>',
            ],
            [
                '',
                '--',
                '',
                [],
                'Accounting',
                true,
                [],
                'Accounting',
                '--<title>Accounting</title>',
            ],
            [
                '',
                '',
                '+',
                [],
                'Accounting',
                true,
                [],
                'Accounting',
                '<title>Accounting</title>+',
            ],
            [
                ' | ',
                '',
                '',
                [
                    'Admin >' => false,
                    'Home >'  => false,
                ],
                'Accounting',
                false,
                [],
                'Accounting',
                '<title>Home &gt; | Admin &gt; | Accounting</title>',
            ],
            [
                ' | ',
                '',
                '',
                [],
                'Accounting',
                false,
                [
                    '< Admin' => false,
                    '< Home'  => false,
                ],
                'Accounting',
                '<title>Accounting | &lt; Admin | &lt; Home</title>',
            ],
            [
                ' | ',
                '',
                '',
                [
                    'Admin >' => true,
                    'Home >'  => true,
                ],
                'Accounting',
                false,
                [],
                'Accounting',
                '<title>Home > | Admin > | Accounting</title>',
            ],
            [
                ' | ',
                '',
                '',
                [],
                'Accounting',
                false,
                [
                    '< Admin' => true,
                    '< Home'  => true,
                ],
                'Accounting',
                '<title>Accounting | < Admin | < Home</title>',
            ],
        ];
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/16283
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-02-20
     */
    public function testHtmlHelperTitlePrependTwice(): void
    {
        $escaper = new Escaper();
        $tag     = new TagFactory($escaper);

        $title     = uniqid('tit-'); // Start
        $prepend1  = uniqid('pr1-'); // Category
        $prepend2  = uniqid('pr2-'); // Product
        $separator = ' - ';

        $tag
            ->title()
            ->set($title)
            ->setSeparator($separator)
        ;

        // Start
        $expected = '    <title>' . $title . '</title>' . PHP_EOL;
        $actual   = (string)$tag->title();
        $this->assertSame($expected, $actual);

        $tag
            ->title()
            ->set($title)
            ->setSeparator($separator)
            ->prepend($prepend1)
        ;

        // Category - Start
        $expected = '    <title>'
            . $prepend1
            . $separator
            . $title
            . '</title>'
            . PHP_EOL;
        $actual   = (string)$tag->title();
        $this->assertSame($expected, $actual);

        $tag
            ->title()
            ->set($title)
            ->setSeparator($separator)
            ->prepend($prepend1)
            ->prepend($prepend2)
        ;

        // Product - Category - Start
        $expected = '    <title>'
            . $prepend2
            . $separator
            . $prepend1
            . $separator
            . $title
            . '</title>'
            . PHP_EOL;
        $actual   = (string)$tag->title();
        $this->assertSame($expected, $actual);
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testHtmlHelperTitleUnderscoreInvoke(
        string $separator,
        string $indent,
        string $delimiter,
        array $prepend,
        string $title,
        bool $titleRaw,
        array $append,
        string $get,
        string $render
    ): void {
        $escaper = new Escaper();
        $helper  = new Title($escaper);

        $result = $helper($indent, $delimiter);

        $result->setSeparator($separator);

        if (!empty($prepend)) {
            foreach ($prepend as $text => $raw) {
                $result->prepend($text, $raw);
            }
        }

        $result->set($title, $titleRaw);
        if (!empty($append)) {
            foreach ($append as $text => $raw) {
                $result->append($text, $raw);
            }
        }

        $expected = $get;
        $actual   = $result->get();
        $this->assertSame($expected, $actual);

        $expected = $render;
        $actual   = (string)$result;
        $this->assertSame($expected, $actual);

        $factory = new TagFactory($escaper);
        $locator = $factory->newInstance('title');

        $result = $locator($indent, $delimiter);

        $result->setSeparator($separator);
        if (!empty($prepend)) {
            foreach ($prepend as $text => $raw) {
                $result->prepend($text, $raw);
            }
        }

        $result->set($title, $titleRaw);

        if (!empty($append)) {
            foreach ($append as $text => $raw) {
                $result->append($text, $raw);
            }
        }


        $expected = $get;
        $actual   = $result->get();
        $this->assertSame($expected, $actual);

        $expected = $render;
        $actual   = (string)$result;
        $this->assertSame($expected, $actual);
    }
}
