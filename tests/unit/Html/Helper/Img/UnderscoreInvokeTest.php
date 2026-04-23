<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Img;

use Phalcon\Html\Escaper;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Img;
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
                '<img src="/my-url" />',
                [],
            ],
            [
                '<img src="/my-url" id="my-id" name="my-name" />',
                [
                    'id'   => 'my-id',
                    'name' => 'my-name',
                ],
            ],
            [
                '<img src="/my-url" id="my-id" name="my-name" class="my-class" />',
                [
                    'src'   => '/other-url',
                    'class' => 'my-class',
                    'name'  => 'my-name',
                    'id'    => 'my-id',
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
    public function testHtmlHelperImgUnderscoreInvoke(
        string $expected,
        array $attributes
    ): void {
        $escaper = new Escaper();
        $helper  = new Img($escaper);

        $actual = $helper('/my-url', $attributes);
        $this->assertSame($expected, $actual);

        $factory = new TagFactory($escaper);
        $locator = $factory->newInstance('img');
        $actual  = $locator('/my-url', $attributes);
        $this->assertSame($expected, $actual);

        $factory = new TagFactory($escaper);
        $actual  = $factory->img('/my-url', $attributes);
        $this->assertSame($expected, $actual);
    }
}
