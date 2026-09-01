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

/**
 * Covers the store the helpers read their values from.
 *
 * A value is looked up in three places, in order: the parameters handed to the
 * helper, the values assigned through setDefault()/setDefaults(), and $_POST.
 * Only scalars (and null) may be assigned through setDefault().
 */
final class ValuesTest extends AbstractTagTestCase
{
    public function testDisplayToIsAnAliasOfSetDefault(): void
    {
        Tag::displayTo('name', 'Phalcon');

        $this->assertSame('Phalcon', Tag::getValue('name'));
    }

    public function testGetValueFallsBackToPost(): void
    {
        $_POST['name'] = 'Posted';

        $this->assertSame('Posted', Tag::getValue('name'));
    }

    public function testGetValuePrefersTheParameters(): void
    {
        $_POST['name'] = 'Posted';

        Tag::setDefault('name', 'Stored');

        $this->assertSame(
            'Given',
            Tag::getValue('name', ['value' => 'Given'])
        );
    }

    public function testGetValuePrefersTheStoredValueOverPost(): void
    {
        $_POST['name'] = 'Posted';

        Tag::setDefault('name', 'Stored');

        $this->assertSame('Stored', Tag::getValue('name'));
    }

    public function testGetValueWithNothingStoredIsNull(): void
    {
        $this->assertNull(Tag::getValue('name'));
    }

    public function testHasValueWithAPostValue(): void
    {
        $_POST['name'] = 'Posted';

        $this->assertTrue(Tag::hasValue('name'));
    }

    public function testHasValueWithAStoredValue(): void
    {
        Tag::setDefault('name', 'Stored');

        $this->assertTrue(Tag::hasValue('name'));
    }

    public function testHasValueWithNothingStored(): void
    {
        $this->assertFalse(Tag::hasValue('name'));
    }

    public function testSetDefaultAcceptsNull(): void
    {
        Tag::setDefault('name', null);

        $this->assertNull(Tag::getValue('name'));
    }

    public function testSetDefaultsMerged(): void
    {
        Tag::setDefaults(['one' => 'first']);
        Tag::setDefaults(['two' => 'second'], true);

        $this->assertSame('first', Tag::getValue('one'));
        $this->assertSame('second', Tag::getValue('two'));
    }

    public function testSetDefaultsReplaced(): void
    {
        Tag::setDefaults(['one' => 'first']);
        Tag::setDefaults(['two' => 'second']);

        $this->assertNull(Tag::getValue('one'));
        $this->assertSame('second', Tag::getValue('two'));
    }

    public function testSetDefaultThrowsForANonScalarValue(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Only scalar values can be assigned to UI components'
        );

        Tag::setDefault('name', ['Phalcon']);
    }
}
