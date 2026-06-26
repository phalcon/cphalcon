<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Forms\Form;

use Phalcon\Filter\Validation\Validator\PresenceOf;
use Phalcon\Forms\Element\Check;
use Phalcon\Forms\Element\CheckGroup;
use Phalcon\Forms\Element\Date;
use Phalcon\Forms\Element\Email;
use Phalcon\Forms\Element\File;
use Phalcon\Forms\Element\Hidden;
use Phalcon\Forms\Element\Numeric;
use Phalcon\Forms\Element\Password;
use Phalcon\Forms\Element\Radio;
use Phalcon\Forms\Element\RadioGroup;
use Phalcon\Forms\Element\Select;
use Phalcon\Forms\Element\Submit;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Element\TextArea;
use Phalcon\Forms\Exception;
use Phalcon\Forms\Form;
use Phalcon\Forms\FormsLocator;
use Phalcon\Forms\Loader\ArrayLoader;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

final class LoadTest extends AbstractUnitTestCase
{
    private FormsLocator $locator;

    protected function setUp(): void
    {
        parent::setUp();
        $this->locator = new FormsLocator();
    }

    // -----------------------------------------------------------------------
    // All 14 element types
    // -----------------------------------------------------------------------

    /**
     * @return array<string, array{string, class-string}>
     */
    public static function getElementTypeMap(): array
    {
        return [
            'check'      => ['check',      Check::class],
            'date'       => ['date',        Date::class],
            'email'      => ['email',       Email::class],
            'file'       => ['file',        File::class],
            'hidden'     => ['hidden',      Hidden::class],
            'numeric'    => ['numeric',     Numeric::class],
            'password'   => ['password',    Password::class],
            'radio'      => ['radio',       Radio::class],
            'radiogroup' => ['radiogroup', RadioGroup::class],
            'select'     => ['select',      Select::class],
            'submit'     => ['submit',      Submit::class],
            'text'       => ['text',        Text::class],
            'textarea'   => ['textarea',    TextArea::class],
        ];
    }

    // -----------------------------------------------------------------------
    // Multiple elements added in one call
    // -----------------------------------------------------------------------

    public function testLoadAddsAllElements(): void
    {
        $form   = new Form();
        $schema = new ArrayLoader([
            ['type' => 'text',     'name' => 'username'],
            ['type' => 'email',    'name' => 'email'],
            ['type' => 'password', 'name' => 'password'],
            ['type' => 'submit',   'name' => 'submit'],
        ]);

        $form->load($schema, $this->locator);

        $this->assertCount(4, $form->getElements());
    }

    /**
     * CheckGroup auto-appends [] to the name, so the stored key is field[].
     */
    public function testLoadCreatesCheckGroupElement(): void
    {
        $form   = new Form();
        $schema = new ArrayLoader([
            ['type' => 'checkgroup', 'name' => 'field'],
        ]);

        $form->load($schema, $this->locator);

        $this->assertTrue($form->has('field[]'));
        $this->assertInstanceOf(CheckGroup::class, $form->get('field[]'));
    }

    /**
     * @param class-string $expectedClass
     */
    #[DataProvider('getElementTypeMap')]
    public function testLoadCreatesCorrectElementType(
        string $type,
        string $expectedClass
    ): void {
        $form   = new Form();
        $schema = new ArrayLoader([
            ['type' => $type, 'name' => 'field'],
        ]);

        $form->load($schema, $this->locator);

        $this->assertTrue($form->has('field'));
        $this->assertInstanceOf($expectedClass, $form->get('field'));
    }

    // -----------------------------------------------------------------------
    // Load is additive (chaining)
    // -----------------------------------------------------------------------

    public function testLoadIsAdditive(): void
    {
        $form = new Form();
        $form->load(new ArrayLoader([
            ['type' => 'text', 'name' => 'first_name'],
        ]), $this->locator);
        $form->load(new ArrayLoader([
            ['type' => 'text', 'name' => 'last_name'],
        ]), $this->locator);

        $this->assertCount(2, $form->getElements());
        $this->assertTrue($form->has('first_name'));
        $this->assertTrue($form->has('last_name'));
    }

    // -----------------------------------------------------------------------
    // Method return type
    // -----------------------------------------------------------------------

    public function testLoadReturnsSameForm(): void
    {
        $form   = new Form();
        $schema = new ArrayLoader([
            ['type' => 'text', 'name' => 'username'],
        ]);

        $returned = $form->load($schema, $this->locator);

        $this->assertSame($form, $returned);
    }

    public function testLoadSetsAttributes(): void
    {
        $form   = new Form();
        $schema = new ArrayLoader([
            ['type' => 'text', 'name' => 'name', 'attributes' => ['class' => 'field', 'required' => true]],
        ]);

        $form->load($schema, $this->locator);

        $element = $form->get('name');
        $this->assertSame('field', $element->getAttributes()['class']);
    }

    // -----------------------------------------------------------------------
    // Group elements: options propagated
    // -----------------------------------------------------------------------

    public function testLoadSetsCheckGroupOptions(): void
    {
        $form   = new Form();
        $schema = new ArrayLoader([
            [
                'type'    => 'checkgroup',
                'name'    => 'colors',
                'options' => ['red' => 'Red', 'blue' => 'Blue'],
            ],
        ]);

        $form->load($schema, $this->locator);

        /** @var CheckGroup $element */
        $element = $form->get('colors[]');
        $this->assertInstanceOf(CheckGroup::class, $element);
        $this->assertSame(['red' => 'Red', 'blue' => 'Blue'], $element->getOptions());
    }

    public function testLoadSetsDefault(): void
    {
        $form   = new Form();
        $schema = new ArrayLoader([
            ['type' => 'text', 'name' => 'country', 'default' => 'GB'],
        ]);

        $form->load($schema, $this->locator);

        $this->assertSame('GB', $form->get('country')->getDefault());
    }

    public function testLoadSetsDefaultFalsyEmptyString(): void
    {
        $form   = new Form();
        $schema = new ArrayLoader([
            ['type' => 'text', 'name' => 'prefix', 'default' => ''],
        ]);

        $form->load($schema, $this->locator);

        // array_key_exists check: '' is still set
        $this->assertSame('', $form->get('prefix')->getDefault());
    }

    public function testLoadSetsDefaultFalsyZero(): void
    {
        $form   = new Form();
        $schema = new ArrayLoader([
            ['type' => 'numeric', 'name' => 'quantity', 'default' => 0],
        ]);

        $form->load($schema, $this->locator);

        $this->assertSame(0, $form->get('quantity')->getDefault());
    }

    public function testLoadSetsFilters(): void
    {
        $form   = new Form();
        $schema = new ArrayLoader([
            ['type' => 'text', 'name' => 'name', 'filters' => ['trim', 'lower']],
        ]);

        $form->load($schema, $this->locator);

        $this->assertSame(['trim', 'lower'], $form->get('name')->getFilters());
    }

    // -----------------------------------------------------------------------
    // Metadata propagation
    // -----------------------------------------------------------------------

    public function testLoadSetsLabel(): void
    {
        $form   = new Form();
        $schema = new ArrayLoader([
            ['type' => 'text', 'name' => 'email', 'label' => 'Email Address'],
        ]);

        $form->load($schema, $this->locator);

        $this->assertSame('Email Address', $form->get('email')->getLabel());
    }

    public function testLoadSetsRadioGroupOptions(): void
    {
        $form   = new Form();
        $schema = new ArrayLoader([
            [
                'type'    => 'radiogroup',
                'name'    => 'gender',
                'options' => ['m' => 'Male', 'f' => 'Female'],
            ],
        ]);

        $form->load($schema, $this->locator);

        /** @var RadioGroup $element */
        $element = $form->get('gender');
        $this->assertInstanceOf(RadioGroup::class, $element);
        $this->assertSame(['m' => 'Male', 'f' => 'Female'], $element->getOptions());
    }

    public function testLoadSetsValidators(): void
    {
        $form      = new Form();
        $validator = new PresenceOf();
        $schema    = new ArrayLoader([
            ['type' => 'text', 'name' => 'name', 'validators' => [$validator]],
        ]);

        $form->load($schema, $this->locator);

        $validators = $form->get('name')->getValidators();
        $this->assertCount(1, $validators);
        $this->assertInstanceOf(PresenceOf::class, $validators[0]);
    }

    // -----------------------------------------------------------------------
    // Unknown type throws
    // -----------------------------------------------------------------------

    public function testLoadThrowsOnUnknownType(): void
    {
        $form   = new Form();
        $schema = new ArrayLoader([
            ['type' => 'unknowntype', 'name' => 'field'],
        ]);

        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/Unknown form element type.*unknowntype/i');

        $form->load($schema, $this->locator);
    }

    public function testLoadTypeIsCaseInsensitive(): void
    {
        $form   = new Form();
        $schema = new ArrayLoader([
            ['type' => 'TEXT', 'name' => 'username'],
        ]);

        $form->load($schema, $this->locator);

        $this->assertInstanceOf(Text::class, $form->get('username'));
    }

    // -----------------------------------------------------------------------
    // Empty schema is a no-op
    // -----------------------------------------------------------------------

    public function testLoadWithEmptySchemaDoesNothing(): void
    {
        $form = new Form();
        $form->load(new ArrayLoader([]), $this->locator);

        $this->assertCount(0, $form->getElements());
    }
}
