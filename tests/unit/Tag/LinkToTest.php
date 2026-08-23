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

/**
 * Covers the named-key form of Tag::linkTo() and the `query` entry.
 *
 * Each of `action`, `text` and `local` can arrive either positionally or under
 * its own key; the key is only read when the positional slot is empty, and is
 * removed from the bag so it never reaches the markup. The `local` channels
 * themselves are characterized in LocalParameterTest.
 */
final class LinkToTest extends AbstractTagTestCase
{
    public function testLinkToEscapesText(): void
    {
        $this->assertSame(
            '<a href="https://phalcon.io/admin/users">'
            . '&lt;script&gt;alert(1)&lt;/script&gt;</a>',
            Tag::linkTo(['admin/users', '<script>alert(1)</script>'])
        );
    }

    public function testLinkToEscapesTextThatClosesTheAnchor(): void
    {
        $this->assertSame(
            '<a href="https://phalcon.io/admin/users">'
            . '&lt;/a&gt;&lt;img src=x onerror=alert(1)&gt;</a>',
            Tag::linkTo(
                [
                    'action' => 'admin/users',
                    'text'   => '</a><img src=x onerror=alert(1)>',
                ]
            )
        );
    }

    public function testLinkToWithExtraAttributes(): void
    {
        $this->assertSame(
            '<a href="https://phalcon.io/admin/products" id="link"'
            . ' class="btn">Products</a>',
            Tag::linkTo(
                [
                    'admin/products',
                    'Products',
                    'id'    => 'link',
                    'class' => 'btn',
                ]
            )
        );
    }
    public function testLinkToWithNamedKeys(): void
    {
        $this->assertSame(
            '<a href="https://phalcon.io/admin/products">Products</a>',
            Tag::linkTo(
                [
                    'action' => 'admin/products',
                    'text'   => 'Products',
                ]
            )
        );
    }

    public function testLinkToWithNoActionAtAll(): void
    {
        $this->assertSame(
            '<a href="https://phalcon.io/"></a>',
            Tag::linkTo([])
        );
    }

    public function testLinkToWithNonScalarText(): void
    {
        $this->assertSame(
            '<a href="https://phalcon.io/admin/products"></a>',
            Tag::linkTo(['admin/products', ['Products']])
        );
    }

    public function testLinkToWithQuery(): void
    {
        $this->assertSame(
            '<a href="https://phalcon.io/admin/products?page=2">Products</a>',
            Tag::linkTo(
                [
                    'admin/products',
                    'Products',
                    'query' => ['page' => 2],
                ]
            )
        );
    }

    public function testLinkToWithQueryThatIsNotAnArrayIsIgnored(): void
    {
        $this->assertSame(
            '<a href="https://phalcon.io/admin/products">Products</a>',
            Tag::linkTo(
                [
                    'admin/products',
                    'Products',
                    'query' => 'page=2',
                ]
            )
        );
    }
}
