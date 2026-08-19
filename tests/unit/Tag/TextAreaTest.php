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
 * Covers Tag::textArea().
 *
 * The content is the only part of a Tag helper that is not an attribute, and
 * it goes through htmlspecialchars() rather than the escaper service - so it
 * is escaped whether or not autoescape is on.
 */
final class TextAreaTest extends AbstractTagTestCase
{
    public function testTextAreaEscapesTheContent(): void
    {
        $this->assertSame(
            '<textarea id="comment" name="comment">'
            . '&lt;b&gt;A &amp; B&lt;/b&gt;</textarea>',
            Tag::textArea(['comment', 'value' => '<b>A & B</b>'])
        );
    }

    public function testTextAreaFromString(): void
    {
        $this->assertSame(
            '<textarea id="comment" name="comment"></textarea>',
            Tag::textArea('comment')
        );
    }

    public function testTextAreaUsesThePostValue(): void
    {
        $_POST['comment'] = 'Posted';

        $this->assertSame(
            '<textarea id="comment" name="comment">Posted</textarea>',
            Tag::textArea('comment')
        );
    }

    public function testTextAreaUsesTheStoredDefaultValue(): void
    {
        Tag::setDefault('comment', 'Stored');

        $this->assertSame(
            '<textarea id="comment" name="comment">Stored</textarea>',
            Tag::textArea('comment')
        );
    }

    public function testTextAreaUsesTheValueParameter(): void
    {
        $this->assertSame(
            '<textarea id="comment" name="comment">Hello</textarea>',
            Tag::textArea(['comment', 'value' => 'Hello'])
        );
    }

    public function testTextAreaWithEmptyNameFallsBackToTheId(): void
    {
        $this->assertSame(
            '<textarea id="comment" name="comment"></textarea>',
            Tag::textArea(['comment', 'name' => ''])
        );
    }

    public function testTextAreaWithSeparateIdAndName(): void
    {
        $this->assertSame(
            '<textarea id="other" name="alias"></textarea>',
            Tag::textArea(['comment', 'id' => 'other', 'name' => 'alias'])
        );
    }

    public function testTextAreaWithTrueIdBecomesThePositionalParameter(): void
    {
        /**
         * The fallback only fires for the literal `true`, so the id is cast to
         * "1" and becomes the name as well.
         */
        $this->assertSame(
            '<textarea id="1" name="1"></textarea>',
            Tag::textArea(['id' => true])
        );
    }
}
