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
 * Covers the document title: the three parts it is assembled from, the
 * separator between them, and the two flags that leave a part out.
 *
 * Passing an array to appendTitle()/prependTitle() replaces the accumulated
 * parts rather than adding to them, and the prepended parts come out in
 * reverse order - the part added last is rendered first. Both are asserted
 * because they are easy to change by accident.
 */
final class TitleTest extends AbstractTagTestCase
{
    public function testAppendTitleWithArrayReplacesTheParts(): void
    {
        Tag::setTitle('Home');
        Tag::setTitleSeparator(' - ');
        Tag::appendTitle('Dropped');
        Tag::appendTitle(['Kept', 'Also kept']);

        $this->assertSame('Home - Kept - Also kept', Tag::getTitle());
    }

    public function testAppendTitleWithStringAddsToTheParts(): void
    {
        Tag::setTitle('Home');
        Tag::setTitleSeparator(' - ');
        Tag::appendTitle('One');
        Tag::appendTitle('Two');

        $this->assertSame('Home - One - Two', Tag::getTitle());
    }

    public function testGetTitleEscapesEveryPart(): void
    {
        Tag::setTitle('Home & <Away>');
        Tag::setTitleSeparator(' & ');
        Tag::appendTitle('<Append>');
        Tag::prependTitle('<Prepend>');

        $this->assertSame(
            '&lt;Prepend&gt; &amp; Home &amp; &lt;Away&gt;'
            . ' &amp; &lt;Append&gt;',
            Tag::getTitle()
        );
    }

    public function testGetTitleSeparator(): void
    {
        Tag::setTitleSeparator(' | ');

        $this->assertSame(' | ', Tag::getTitleSeparator());
    }

    public function testGetTitleSeparatorWhenNullIsEmpty(): void
    {
        Tag::resetInput();

        $this->assertSame('', Tag::getTitleSeparator());
    }

    public function testGetTitleWithNoPartsIsEmpty(): void
    {
        $this->assertSame('', Tag::getTitle());
    }

    public function testGetTitleWithNullTitleIsEmpty(): void
    {
        Tag::resetInput();

        $this->assertSame('', Tag::getTitle());
    }

    public function testGetTitleWithoutAppendLeavesOutTheAppendedParts(): void
    {
        Tag::setTitle('Home');
        Tag::setTitleSeparator(' - ');
        Tag::appendTitle('Append');
        Tag::prependTitle('Prepend');

        $this->assertSame('Prepend - Home', Tag::getTitle(true, false));
    }

    public function testGetTitleWithoutPrependLeavesOutThePrependedParts(): void
    {
        Tag::setTitle('Home');
        Tag::setTitleSeparator(' - ');
        Tag::appendTitle('Append');
        Tag::prependTitle('Prepend');

        $this->assertSame('Home - Append', Tag::getTitle(false, true));
    }

    public function testGetTitleWithoutSeparatorJoinsThePartsDirectly(): void
    {
        Tag::setTitle('Home');
        Tag::appendTitle('Append');
        Tag::prependTitle('Prepend');

        $this->assertSame('PrependHomeAppend', Tag::getTitle());
    }

    public function testGetTitleWithSeparator(): void
    {
        Tag::setTitle('Home');
        Tag::setTitleSeparator(' - ');
        Tag::appendTitle('Append');
        Tag::prependTitle('Prepend');

        $this->assertSame('Prepend - Home - Append', Tag::getTitle());
    }

    public function testGetTitleWithTitleOnly(): void
    {
        Tag::setTitle('Home');

        $this->assertSame('Home', Tag::getTitle());
    }

    public function testPrependTitleWithArrayReplacesTheParts(): void
    {
        Tag::setTitle('Home');
        Tag::setTitleSeparator(' - ');
        Tag::prependTitle('Dropped');
        Tag::prependTitle(['Second', 'First']);

        $this->assertSame('First - Second - Home', Tag::getTitle());
    }

    public function testPrependTitleWithStringRendersInReverseOrder(): void
    {
        Tag::setTitle('Home');
        Tag::setTitleSeparator(' - ');
        Tag::prependTitle('One');
        Tag::prependTitle('Two');

        $this->assertSame('Two - One - Home', Tag::getTitle());
    }

    public function testRenderTitle(): void
    {
        Tag::setTitle('Home');
        Tag::setTitleSeparator(' - ');
        Tag::appendTitle('Append');
        Tag::prependTitle('Prepend');

        $this->assertSame(
            '<title>Prepend - Home - Append</title>' . PHP_EOL,
            Tag::renderTitle()
        );
    }

    public function testRenderTitleWithoutPrependAndAppend(): void
    {
        Tag::setTitle('Home');
        Tag::appendTitle('Append');
        Tag::prependTitle('Prepend');

        $this->assertSame(
            '<title>Home</title>' . PHP_EOL,
            Tag::renderTitle(false, false)
        );
    }

    public function testResetInputClearsTheTitleAndTheValues(): void
    {
        Tag::setDefault('name', 'Phalcon');
        Tag::setTitle('Home');
        Tag::setTitleSeparator(' - ');
        Tag::appendTitle('Append');
        Tag::prependTitle('Prepend');

        Tag::resetInput();

        $this->assertSame('', Tag::getTitle());
        $this->assertSame('', Tag::getTitleSeparator());
        $this->assertFalse(Tag::hasValue('name'));
    }

    public function testSetTitleReplacesThePreviousTitle(): void
    {
        Tag::setTitle('Home');
        Tag::setTitle('About');

        $this->assertSame('About', Tag::getTitle());
    }
}
