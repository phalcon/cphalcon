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

namespace Phalcon\Tests\Unit\Tag;

use Phalcon\Tag;
use Phalcon\Tag\Exception;

use function fclose;
use function fopen;

/**
 * Covers Tag::renderAttributes(), the single place every helper turns its
 * parameter bag into markup.
 *
 * A fixed list of attributes is emitted first, in that order, so the output is
 * stable no matter how the caller ordered the array; anything else follows in
 * insertion order. Only string keys are rendered, which is what keeps the
 * positional parameters the helpers rely on out of the markup.
 */
final class RenderAttributesTest extends AbstractTagTestCase
{
    public function testRenderAttributesDropsTheEscapeKey(): void
    {
        $this->assertSame(
            '<tag id="one"',
            Tag::renderAttributes('<tag', ['id' => 'one', 'escape' => false])
        );
    }

    public function testRenderAttributesEscapesWhenAutoescapeIsOn(): void
    {
        Tag::setAutoescape(true);

        $this->assertSame(
            '<tag id="a&quot;b"',
            Tag::renderAttributes('<tag', ['id' => 'a"b'])
        );
    }

    public function testRenderAttributesKeepsTheKnownOrder(): void
    {
        $this->assertSame(
            '<tag rel="r" type="t" for="f" src="s" href="h" action="a"'
            . ' id="i" name="n" value="v" class="c" data-extra="e"',
            Tag::renderAttributes(
                '<tag',
                [
                    'data-extra' => 'e',
                    'class'      => 'c',
                    'value'      => 'v',
                    'name'       => 'n',
                    'id'         => 'i',
                    'action'     => 'a',
                    'href'       => 'h',
                    'src'        => 's',
                    'for'        => 'f',
                    'type'       => 't',
                    'rel'        => 'r',
                ]
            )
        );
    }

    public function testRenderAttributesSkipsIntegerKeys(): void
    {
        $this->assertSame(
            '<tag id="one"',
            Tag::renderAttributes('<tag', ['positional', 'id' => 'one'])
        );
    }

    public function testRenderAttributesSkipsNullValues(): void
    {
        $this->assertSame(
            '<tag class="one"',
            Tag::renderAttributes('<tag', ['id' => null, 'class' => 'one'])
        );
    }

    public function testRenderAttributesThrowsForAnArrayValue(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Value at index: 'class' type: 'array' cannot be rendered"
        );

        Tag::renderAttributes('<tag', ['class' => ['one']]);
    }

    public function testRenderAttributesThrowsForAResourceValue(): void
    {
        $handle = fopen('php://memory', 'rb');

        try {
            $this->expectException(Exception::class);
            $this->expectExceptionMessage(
                "Value at index: 'class' type: 'resource' cannot be rendered"
            );

            Tag::renderAttributes('<tag', ['class' => $handle]);
        } finally {
            fclose($handle);
        }
    }

    public function testRenderAttributesWithoutEscapingWhenAutoescapeIsOff(): void
    {
        $this->assertSame(
            '<tag id="a"b"',
            Tag::renderAttributes('<tag', ['id' => 'a"b'])
        );
    }
}
