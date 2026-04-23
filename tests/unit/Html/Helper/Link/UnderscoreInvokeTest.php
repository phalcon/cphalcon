<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Link;

use Phalcon\Html\Escaper;
use Phalcon\Html\Helper\Link;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;

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
                [
                    'https://phalcon.io/page/1' => ['rel' => 'prev'],
                    'https://phalcon.io/page/2' => ['rel' => 'next'],
                ],
                '    ',
                PHP_EOL,
                "    <link rel=\"prev\" href=\"https://phalcon.io/page/1\" />" . PHP_EOL
                . "    <link rel=\"next\" href=\"https://phalcon.io/page/2\" />" . PHP_EOL,
            ],
            [
                [
                    'https://phalcon.io/page/1' => ['rel' => 'prev'],
                    'https://phalcon.io/page/2' => ['rel' => 'next'],
                ],
                '--',
                '+',
                "--<link rel=\"prev\" href=\"https://phalcon.io/page/1\" />+"
                . "--<link rel=\"next\" href=\"https://phalcon.io/page/2\" />+",
            ],
            [
                [
                    'https://phalcon.io/assets/base.css' => [
                        'rel'   => 'stylesheet',
                        'media' => 'screen',
                    ],
                ],
                '    ',
                PHP_EOL,
                "    <link rel=\"stylesheet\" " .
                "href=\"https://phalcon.io/assets/base.css\" " .
                "media=\"screen\" />" . PHP_EOL,
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testHtmlHelperLinkUnderscoreInvoke(
        array $add,
        string $indent,
        string $delimiter,
        string $expected
    ): void {
        $escaper = new Escaper();
        $helper  = new Link($escaper);

        $result = $helper($indent, $delimiter);
        foreach ($add as $url => $attributes) {
            $result->add($url, $attributes);
        }

        $actual = (string)$result;
        $this->assertSame($expected, $actual);

        $factory = new TagFactory($escaper);
        $locator = $factory->newInstance('link');
        $result  = $locator($indent, $delimiter);

        foreach ($add as $url => $attributes) {
            $result->add($url, $attributes);
        }

        $actual = (string)$result;
        $this->assertSame($expected, $actual);
    }
}
