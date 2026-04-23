<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Base;

use Phalcon\Html\Escaper;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Base;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;

final class UnderscoreInvokeTest extends AbstractUnitTestCase
{
    /**
     * @return array
     */
    public static function getExamples(): array
    {
        return [
            [
                '<base>',
                '',
                [],
            ],
            [
                '<base href="https://phalcon.io">',
                'https://phalcon.io',
                [],
            ],
            [
                '<base href="https://phalcon.io">',
                'https://phalcon.io',
                [
                    'href' => 'https://phalcon.io',
                ],
            ],
            [
                '<base href="https://phalcon.io" target="_top">',
                'https://phalcon.io',
                [
                    'target' => '_top',
                ],
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testHtmlHelperBaseUnderscoreInvoke(
        string $expected,
        string $href,
        array $attributes
    ): void {
        $escaper = new Escaper();
        $helper  = new Base($escaper);

        $actual = $helper($href, $attributes);
        $this->assertSame($expected, $actual);

        $factory = new TagFactory($escaper);
        $locator = $factory->newInstance('base');
        $actual  = $locator($href, $attributes);
        $this->assertSame($expected, $actual);

        $factory = new TagFactory($escaper);
        $actual  = $factory->base($href, $attributes);
        $this->assertSame($expected, $actual);
    }
}
