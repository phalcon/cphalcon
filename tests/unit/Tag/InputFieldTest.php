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
use PHPUnit\Framework\Attributes\DataProvider;

/**
 * Covers Tag::inputField() through the helpers that delegate to it.
 *
 * The helper has two modes. Every typed field renders the resolved value in
 * the `value` attribute and derives `name`/`id` from the first parameter;
 * submitButton() and imageInput() instead pass the first parameter through as
 * the value and derive nothing.
 */
final class InputFieldTest extends AbstractTagTestCase
{
    /**
     * @return array<array-key, array{0: string, 1: string}>
     */
    public static function getFields(): array
    {
        return [
            ['colorField', 'color'],
            ['dateField', 'date'],
            ['dateTimeField', 'datetime'],
            ['dateTimeLocalField', 'datetime-local'],
            ['emailField', 'email'],
            ['fileField', 'file'],
            ['hiddenField', 'hidden'],
            ['monthField', 'month'],
            ['numericField', 'number'],
            ['passwordField', 'password'],
            ['rangeField', 'range'],
            ['searchField', 'search'],
            ['telField', 'tel'],
            ['textField', 'text'],
            ['timeField', 'time'],
            ['urlField', 'url'],
            ['weekField', 'week'],
        ];
    }

    #[DataProvider('getFields')]
    public function testFieldFromArray(string $method, string $type): void
    {
        $this->assertSame(
            '<input type="' . $type . '" id="name" name="name" '
            . 'value="Phalcon" class="my-class">',
            Tag::$method(['name', 'value' => 'Phalcon', 'class' => 'my-class'])
        );
    }

    #[DataProvider('getFields')]
    public function testFieldFromString(string $method, string $type): void
    {
        $this->assertSame(
            '<input type="' . $type . '" id="name" name="name">',
            Tag::$method('name')
        );
    }

    public function testFieldUsesThePostValue(): void
    {
        $_POST['name'] = 'Posted';

        $this->assertSame(
            '<input type="text" id="name" name="name" value="Posted">',
            Tag::textField('name')
        );
    }

    public function testFieldUsesTheStoredDefaultValue(): void
    {
        Tag::setDefault('name', 'Stored');

        $this->assertSame(
            '<input type="text" id="name" name="name" value="Stored">',
            Tag::textField('name')
        );
    }

    public function testFieldWithArrayNameSkipsTheAutomaticId(): void
    {
        $this->assertSame(
            '<input type="text" name="user[name]">',
            Tag::textField('user[name]')
        );
    }

    public function testFieldWithEmptyNameFallsBackToTheId(): void
    {
        $this->assertSame(
            '<input type="text" id="name" name="name">',
            Tag::textField(['name', 'name' => ''])
        );
    }

    public function testFieldWithIdKeyOnly(): void
    {
        /**
         * With no positional index the `id` key becomes the first parameter,
         * and `name` is derived from it - the same as checkField().
         */
        $this->assertSame(
            '<input type="text" id="name" name="name">',
            Tag::textField(['id' => 'name'])
        );
    }

    public function testFieldWithNonScalarIdRendersAnEmptyId(): void
    {
        $this->assertSame(
            '<input type="text" id="" name="">',
            Tag::textField([['name']])
        );
    }

    public function testFieldWithSeparateName(): void
    {
        $this->assertSame(
            '<input type="text" id="name" name="alias">',
            Tag::textField(['name', 'name' => 'alias'])
        );
    }

    public function testFieldWithXhtmlDocTypeIsSelfClosed(): void
    {
        Tag::setDocType(Tag::XHTML5);

        $this->assertSame(
            '<input type="text" id="name" name="name" />',
            Tag::textField('name')
        );
    }

    public function testImageInput(): void
    {
        $this->assertSame(
            '<input type="image" src="img/logo.png">',
            Tag::imageInput(['src' => 'img/logo.png'])
        );
    }

    public function testImageInputWithXhtmlDocTypeIsSelfClosed(): void
    {
        Tag::setDocType(Tag::XHTML5);

        $this->assertSame(
            '<input type="image" src="img/logo.png" />',
            Tag::imageInput(['src' => 'img/logo.png'])
        );
    }

    public function testSubmitButtonKeepsAnExplicitValue(): void
    {
        $this->assertSame(
            '<input type="submit" value="Send">',
            Tag::submitButton(['Save', 'value' => 'Send'])
        );
    }

    public function testSubmitButtonUsesTheFirstParameterAsValue(): void
    {
        $this->assertSame(
            '<input type="submit" value="Save">',
            Tag::submitButton('Save')
        );
    }

    public function testSubmitButtonWithoutAValue(): void
    {
        $this->assertSame(
            '<input type="submit" class="my-class">',
            Tag::submitButton(['class' => 'my-class'])
        );
    }
}
