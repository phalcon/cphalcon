<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Element;

use Phalcon\Html\Escaper;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Element;
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
                '<canvas>test tag</canvas>',
                'canvas',
                'test tag',
                [],
                false,
            ],
            [
                '<canvas>Jack &amp; Jill</canvas>',
                'canvas',
                'Jack & Jill',
                [],
                false,
            ],
            [
                '<canvas>&lt;script&gt;alert(&quot;hello&quot;);&lt;/script&gt;test tag</canvas>',
                'canvas',
                '<script>alert("hello");</script>test tag',
                [],
                false,
            ],
            [
                '<section id="my-id" name="my-name">test tag</section>',
                'section',
                'test tag',
                [
                    'id'   => 'my-id',
                    'name' => 'my-name',
                ],
                false,
            ],
            [
                '<address id="my-id" name="my-name" class="my-class">test tag</address>',
                'address',
                'test tag',
                [
                    'class' => 'my-class',
                    'name'  => 'my-name',
                    'id'    => 'my-id',
                ],
                false,
            ],
            [
                '<canvas>test tag</canvas>',
                'canvas',
                'test tag',
                [],
                true,
            ],
            [
                '<canvas>Jack & Jill</canvas>',
                'canvas',
                'Jack & Jill',
                [],
                true,
            ],
            [
                '<canvas><script>alert("hello");</script>test tag</canvas>',
                'canvas',
                '<script>alert("hello");</script>test tag',
                [],
                true,
            ],
            [
                '<section id="my-id" name="my-name">test tag</section>',
                'section',
                'test tag',
                [
                    'id'   => 'my-id',
                    'name' => 'my-name',
                ],
                true,
            ],
            [
                '<address id="my-id" name="my-name" class="my-class">test tag</address>',
                'address',
                'test tag',
                [
                    'class' => 'my-class',
                    'name'  => 'my-name',
                    'id'    => 'my-id',
                ],
                true,
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testHtmlHelperElementUnderscoreInvoke(
        string $expected,
        string $tag,
        string $text,
        array $attributes,
        bool $raw
    ): void {
        $escaper = new Escaper();
        $helper  = new Element($escaper);

        $actual = $helper($tag, $text, $attributes, $raw);
        $this->assertSame($expected, $actual);

        $factory = new TagFactory($escaper);
        $locator = $factory->newInstance('element');
        $actual  = $locator($tag, $text, $attributes, $raw);
        $this->assertSame($expected, $actual);

        $factory = new TagFactory($escaper);
        $actual  = $factory->element($tag, $text, $attributes, $raw);
        $this->assertSame($expected, $actual);
    }
}
