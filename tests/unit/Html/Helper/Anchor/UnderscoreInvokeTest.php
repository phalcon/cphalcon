<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Anchor;

use Phalcon\Html\Escaper;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Anchor;
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
                '<a href="/myurl">click&lt;&gt;me</a>',
                [],
                false,
            ],
            [
                '<a href="/myurl">click&lt;&gt;me</a>',
                [
                    'href' => '/somethingelse',
                ],
                false,
            ],
            [
                '<a href="/myurl" id="my-id" name="my-name">click&lt;&gt;me</a>',
                [
                    'id'   => 'my-id',
                    'name' => 'my-name',
                ],
                false,
            ],
            [
                '<a href="/myurl" id="my-id" name="my-name" class="my-class">click&lt;&gt;me</a>',
                [
                    'class' => 'my-class',
                    'name'  => 'my-name',
                    'id'    => 'my-id',
                ],
                false,
            ],
            [
                '<a href="/myurl">click<>me</a>',
                [],
                true,
            ],
            [
                '<a href="/myurl">click<>me</a>',
                [
                    'href' => '/somethingelse',
                ],
                true,
            ],
            [
                '<a href="/myurl" id="my-id" name="my-name">click<>me</a>',
                [
                    'id'   => 'my-id',
                    'name' => 'my-name',
                ],
                true,
            ],
            [
                '<a href="/myurl" id="my-id" name="my-name" class="my-class">click<>me</a>',
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
    public function testHtmlHelperAnchorUnderscoreInvoke(
        string $expected,
        array $attributes,
        bool $raw
    ): void {
        $escaper = new Escaper();
        $anchor  = new Anchor($escaper);

        $actual = $anchor('/myurl', 'click<>me', $attributes, $raw);
        $this->assertSame($expected, $actual);

        $factory = new TagFactory($escaper);
        $locator = $factory->newInstance('a');
        $actual  = $locator('/myurl', 'click<>me', $attributes, $raw);
        $this->assertSame($expected, $actual);

        $factory = new TagFactory($escaper);
        $actual  = $factory->a('/myurl', 'click<>me', $attributes, $raw);
        $this->assertSame($expected, $actual);
    }
}
