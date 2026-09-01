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

use const PHP_EOL;

/**
 * Covers Tag::tagHtml() and Tag::tagHtmlClose().
 *
 * Which of `$selfClose` and `$onlyStart` is honored depends on the doctype: an
 * XHTML doctype reads `$selfClose` and closes the tag inline, an HTML one reads
 * `$onlyStart` and otherwise emits a matching close tag.
 */
final class TagHtmlTest extends AbstractTagTestCase
{
    public function testTagHtmlClose(): void
    {
        $this->assertSame('</aside>', Tag::tagHtmlClose('aside'));
    }

    public function testTagHtmlCloseStripsTagNameInjection(): void
    {
        $this->assertSame(
            '</xscript>',
            Tag::tagHtmlClose('x"><script>')
        );
    }

    public function testTagHtmlCloseWithEol(): void
    {
        $this->assertSame(
            '</aside>' . PHP_EOL,
            Tag::tagHtmlClose('aside', true)
        );
    }

    public function testTagHtmlStripsTagNameInjection(): void
    {
        $this->assertSame(
            '<xscript></xscript>',
            Tag::tagHtml('x"><script>')
        );
    }

    public function testTagHtmlWithAttributes(): void
    {
        $this->assertSame(
            '<aside id="one" class="two"></aside>',
            Tag::tagHtml('aside', ['id' => 'one', 'class' => 'two'])
        );
    }

    public function testTagHtmlWithEol(): void
    {
        $this->assertSame(
            '<aside></aside>' . PHP_EOL,
            Tag::tagHtml('aside', [], false, false, true)
        );
    }

    public function testTagHtmlWithHtmlDocType(): void
    {
        $this->assertSame('<aside></aside>', Tag::tagHtml('aside'));
    }

    public function testTagHtmlWithHtmlDocTypeAndOnlyStart(): void
    {
        $this->assertSame('<aside>', Tag::tagHtml('aside', [], false, true));
    }

    public function testTagHtmlWithStringParameters(): void
    {
        /**
         * A bare string becomes the positional index 0, and positional entries
         * are never rendered as attributes.
         */
        $this->assertSame('<aside></aside>', Tag::tagHtml('aside', 'ignored'));
    }

    public function testTagHtmlWithXhtmlDocType(): void
    {
        Tag::setDocType(Tag::XHTML5);

        $this->assertSame('<img>', Tag::tagHtml('img'));
    }

    public function testTagHtmlWithXhtmlDocTypeAndSelfClose(): void
    {
        Tag::setDocType(Tag::XHTML5);

        $this->assertSame('<img />', Tag::tagHtml('img', [], true));
    }
}
