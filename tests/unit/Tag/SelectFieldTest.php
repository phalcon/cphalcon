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
use Phalcon\Tag\Select;
use Phalcon\Tests\Unit\Html\Helper\Input\Select\Fake\FakeResultset;

use const PHP_EOL;

/**
 * Covers the parts of Tag\Select::selectField() that the per-source test files
 * do not reach: how the SELECT itself is named, the empty option, the checks on
 * the `using` parameter, and selecting more than one option at a time.
 *
 * An array `value` is what a multiple-select posts back, and it is compared
 * against the raw array key for an array source but against the already
 * escaped value for a resultset - so both are asserted.
 */
final class SelectFieldTest extends AbstractTagTestCase
{
    public function testSelectFromResultsetWithAnArrayValue(): void
    {
        $resultset = new FakeResultset(
            [
                ['id' => 1, 'name' => 'One'],
                ['id' => 2, 'name' => 'Two'],
                ['id' => 3, 'name' => 'Three'],
            ]
        );

        $html = Select::selectField(
            [
                'choices',
                $resultset,
                'using' => ['id', 'name'],
                'value' => ['1', '3'],
            ]
        );

        $this->assertStringContainsString(
            '<option selected="selected" value="1">One</option>',
            $html
        );
        $this->assertStringContainsString(
            '<option value="2">Two</option>',
            $html
        );
        $this->assertStringContainsString(
            '<option selected="selected" value="3">Three</option>',
            $html
        );
    }

    public function testSelectFromResultsetWithAnInvalidRowThrows(): void
    {
        $resultset = new FakeResultset(['not-a-row']);

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Resultset returned an invalid value');

        Select::selectField(
            [
                'choices',
                $resultset,
                'using' => ['id', 'name'],
            ]
        );
    }

    public function testSelectFromResultsetWithoutUsingThrows(): void
    {
        $resultset = new FakeResultset([['id' => 1, 'name' => 'One']]);

        $this->expectException(Exception::class);
        $this->expectExceptionMessage("The 'using' parameter is required");

        Select::selectField(['choices', $resultset]);
    }

    public function testSelectFromResultsetWithStringUsingThrows(): void
    {
        $resultset = new FakeResultset([['id' => 1, 'name' => 'One']]);

        $this->expectException(Exception::class);
        $this->expectExceptionMessage("The 'using' parameter should be an array");

        Select::selectField(
            [
                'choices',
                $resultset,
                'using' => 'id',
            ]
        );
    }

    public function testSelectRendersTheFullTag(): void
    {
        $this->assertSame(
            '<select id="choices" name="choices">' . PHP_EOL
            . "\t" . '<option value="a">Apple</option>' . PHP_EOL
            . '</select>',
            Tag::select('choices', ['a' => 'Apple'])
        );
    }

    public function testSelectWithAnArrayValueMarksEveryMatch(): void
    {
        $html = Tag::selectStatic(
            [
                'choices',
                ['a' => 'Apple', 'b' => 'Banana', 'c' => 'Cherry'],
                'value' => ['a', 'c'],
            ]
        );

        $this->assertStringContainsString(
            '<option selected="selected" value="a">Apple</option>',
            $html
        );
        $this->assertStringContainsString(
            '<option value="b">Banana</option>',
            $html
        );
        $this->assertStringContainsString(
            '<option selected="selected" value="c">Cherry</option>',
            $html
        );
    }

    public function testSelectWithEmptyNameFallsBackToTheId(): void
    {
        $html = Tag::selectStatic(
            [
                'choices',
                ['a' => 'Apple'],
                'name' => '',
            ]
        );

        $this->assertStringContainsString(
            '<select id="choices" name="choices">',
            $html
        );
    }

    public function testSelectWithIdKeyOnly(): void
    {
        $html = Select::selectField(
            ['id' => 'choices'],
            ['a' => 'Apple']
        );

        $this->assertStringContainsString(
            '<select id="choices" name="choices">',
            $html
        );
        $this->assertStringContainsString(
            '<option value="a">Apple</option>',
            $html
        );
    }

    public function testSelectWithSeparateName(): void
    {
        $html = Tag::selectStatic(
            [
                'choices',
                ['a' => 'Apple'],
                'name' => 'alias',
            ]
        );

        $this->assertStringContainsString(
            '<select id="choices" name="alias">',
            $html
        );
    }

    public function testSelectWithTrueEmptyTextRendersItCast(): void
    {
        /**
         * `emptyText` is removed from the bag only for the literal `true`,
         * which then reaches the markup cast to "1".
         */
        $html = Tag::selectStatic(
            [
                'choices',
                ['a' => 'Apple'],
                'useEmpty'  => true,
                'emptyText' => true,
            ]
        );

        $this->assertStringContainsString('<option value="">1</option>', $html);
    }
}
