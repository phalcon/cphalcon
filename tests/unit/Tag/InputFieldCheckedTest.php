<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Tag;

use Phalcon\Tag;
use PHPUnit\Framework\Attributes\DataProvider;

/**
 * Covers Tag::inputFieldChecked() through checkField() and radioField().
 *
 * The `checked` attribute is decided in one of two ways. With a `value` in the
 * parameters the field is checked only when the stored value matches it, which
 * is how a group of checkboxes sharing a name is rendered. Without one, any
 * stored value at all checks the field and is also rendered as the value.
 */
final class InputFieldCheckedTest extends AbstractTagTestCase
{
    /**
     * @return array<array-key, array{0: string, 1: string}>
     */
    public static function getFields(): array
    {
        return [
            ['checkField', 'checkbox'],
            ['radioField', 'radio'],
        ];
    }

    #[DataProvider('getFields')]
    public function testFieldFromString(string $method, string $type): void
    {
        $this->assertSame(
            '<input type="' . $type . '" id="name" name="name">',
            Tag::$method('name')
        );
    }

    public function testFieldIsCheckedFromThePostValue(): void
    {
        $_POST['name'] = 'yes';

        $this->assertSame(
            '<input type="checkbox" id="name" name="name" '
            . 'value="yes" checked="checked">',
            Tag::checkField('name')
        );
    }

    public function testFieldIsCheckedFromTheStoredValue(): void
    {
        Tag::setDefault('name', 'yes');

        $this->assertSame(
            '<input type="checkbox" id="name" name="name" '
            . 'value="yes" checked="checked">',
            Tag::checkField('name')
        );
    }

    /**
     * The POST value is a string. cphalcon compares it with a loose
     * comparison.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/843
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-21
     */
    #[DataProvider('getFields')]
    public function testFieldIsCheckedWhenThePostValueMatchesLoosely(
        string $method,
        string $type
    ): void {
        $_POST['name'] = '1';

        $this->assertSame(
            '<input type="' . $type . '" id="name" name="name" '
            . 'value="1" checked="checked">',
            Tag::$method(['name', 'value' => 1])
        );

        $_POST['name'] = '2';

        $this->assertSame(
            '<input type="' . $type . '" id="name" name="name" value="1">',
            Tag::$method(['name', 'value' => 1])
        );
    }

    #[DataProvider('getFields')]
    public function testFieldIsCheckedWhenTheStoredValueMatches(
        string $method,
        string $type
    ): void {
        Tag::setDefault('name', 'yes');

        $this->assertSame(
            '<input type="' . $type . '" id="name" name="name" '
            . 'value="yes" checked="checked">',
            Tag::$method(['name', 'value' => 'yes'])
        );
    }

    #[DataProvider('getFields')]
    public function testFieldIsNotCheckedWhenTheStoredValueDiffers(
        string $method,
        string $type
    ): void {
        Tag::setDefault('name', 'no');

        $this->assertSame(
            '<input type="' . $type . '" id="name" name="name" value="yes">',
            Tag::$method(['name', 'value' => 'yes'])
        );
    }

    public function testFieldWithArrayNameSkipsTheAutomaticId(): void
    {
        $this->assertSame(
            '<input type="checkbox" name="user[name]">',
            Tag::checkField('user[name]')
        );
    }

    public function testFieldWithEmptyNameFallsBackToTheId(): void
    {
        $this->assertSame(
            '<input type="checkbox" id="name" name="name">',
            Tag::checkField(['name', 'name' => ''])
        );
    }

    public function testFieldWithIdKeyOnly(): void
    {
        $this->assertSame(
            '<input type="checkbox" id="name" name="name">',
            Tag::checkField(['id' => 'name'])
        );
    }

    public function testFieldWithSeparateName(): void
    {
        $this->assertSame(
            '<input type="checkbox" id="name" name="alias">',
            Tag::checkField(['name', 'name' => 'alias'])
        );
    }

    public function testFieldWithUncheckedValueIsRenderedAnyway(): void
    {
        $this->assertSame(
            '<input type="checkbox" id="name" name="name" value="yes">',
            Tag::checkField(['name', 'value' => 'yes'])
        );
    }

    public function testFieldWithXhtmlDocTypeIsSelfClosed(): void
    {
        Tag::setDocType(Tag::XHTML5);

        $this->assertSame(
            '<input type="checkbox" id="name" name="name" />',
            Tag::checkField('name')
        );
    }
}
