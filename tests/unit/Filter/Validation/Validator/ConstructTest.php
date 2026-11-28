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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator;

use Phalcon\Filter\Validation\Validator\Alnum;
use Phalcon\Filter\Validation\Validator\Alpha;
use Phalcon\Filter\Validation\Validator\Between;
use Phalcon\Filter\Validation\Validator\Callback;
use Phalcon\Filter\Validation\Validator\Confirmation;
use Phalcon\Filter\Validation\Validator\CreditCard;
use Phalcon\Filter\Validation\Validator\Date;
use Phalcon\Filter\Validation\Validator\Digit;
use Phalcon\Filter\Validation\Validator\Email;
use Phalcon\Filter\Validation\Validator\ExclusionIn;
use Phalcon\Filter\Validation\Validator\File;
use Phalcon\Filter\Validation\Validator\Identical;
use Phalcon\Filter\Validation\Validator\InclusionIn;
use Phalcon\Filter\Validation\Validator\Ip;
use Phalcon\Filter\Validation\Validator\Numericality;
use Phalcon\Filter\Validation\Validator\PresenceOf;
use Phalcon\Filter\Validation\Validator\Regex;
use Phalcon\Filter\Validation\Validator\StringLength;
use Phalcon\Filter\Validation\Validator\Uniqueness;
use Phalcon\Filter\Validation\Validator\Url;
use Phalcon\Filter\Validation\ValidatorCompositeInterface;
use Phalcon\Filter\Validation\ValidatorInterface;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

final class ConstructTest extends AbstractUnitTestCase
{
    public static function getExamples(): array
    {
        return [
            [Alnum::class],
            [Alpha::class],
            [Between::class],
            [Callback::class],
            [Confirmation::class],
            [CreditCard::class],
            [Date::class],
            [Digit::class],
            [Email::class],
            [ExclusionIn::class],
            [File::class],
            [File\Size\Equal::class],
            [File\Size\Max::class],
            [File\Size\Min::class],
            [File\Resolution\Equal::class],
            [File\Resolution\Max::class],
            [File\Resolution\Min::class],
            [Identical::class],
            [InclusionIn::class],
            [Ip::class],
            [Numericality::class],
            [PresenceOf::class],
            [Regex::class],
            [StringLength::class],
            [StringLength\Min::class],
            [StringLength\Max::class],
            [Uniqueness::class],
            [Url::class],
        ];
    }

    public static function getTemplateCases(): array
    {
        $default = 'Field :field is required';

        // options, expected options, expected template, template changed, expected templates
        return [
            'no options'         => [[], [], $default, false, []],
            'other option'       => [['allowEmpty' => true], ['allowEmpty' => true], $default, false, []],
            'template'           => [
                ['template' => 'Tpl', 'allowEmpty' => true],
                ['allowEmpty' => true, 'message' => 'Tpl'],
                'Tpl',
                true,
                [],
            ],
            'integer key'        => [
                ['Msg0', 'allowEmpty' => true],
                ['allowEmpty' => true, 'message' => 'Msg0'],
                'Msg0',
                true,
                [],
            ],
            'message first'      => [['message' => 'Msg', 'template' => 'Tpl'], ['message' => 'Msg'], 'Msg', true, []],
            'template first'     => [['template' => 'Tpl', 'message' => 'Msg'], ['message' => 'Tpl'], 'Tpl', true, []],
            'empty string first' => [
                ['template' => '', 'message' => 'Msg'],
                ['template' => '', 'message' => 'Msg'],
                '',
                true,
                [],
            ],
            'null first'         => [
                ['message' => null, 'template' => 'Tpl'],
                ['message' => null, 'template' => 'Tpl'],
                $default,
                false,
                [],
            ],
            'array templates'    => [
                ['message' => ['name' => 'Name msg']],
                ['message' => ['name' => 'Name msg']],
                $default,
                false,
                ['name' => 'Name msg'],
            ],
            'other integer key'  => [[1 => 'One'], [1 => 'One'], $default, false, []],
        ];
    }

    /**
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    #[DataProvider('getExamples')]
    public function testFilterValidationValidatorAlnumConstruct(
        string $class
    ): void {
        $validator = new $class();

        $this->assertInstanceOf(
            ValidatorInterface::class,
            $validator
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testFilterValidationValidatorConstruct(): void
    {
        $message = uniqid('mes-');
        $default = new PresenceOf();                        // default message
        $custom  = new PresenceOf(['message' => $message]); // custom message

        // expected: null - empty message for default text (not set)
        $actual = $default->getOption('message');
        $this->assertNull($actual);

        // expected: text message - has custom message (developer set this message)
        $expected = $message;
        $actual   = $custom->getOption('message');
        $this->assertSame($expected, $actual);

        $custom   = new PresenceOf(['template' => $message]); // custom message
        $expected = $message;
        $actual   = $custom->getOption('message');
        $this->assertSame($expected, $actual);

        $custom   = new PresenceOf([$message]); // custom message
        $expected = $message;
        $actual   = $custom->getOption('message');
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-27
     */
    #[DataProvider('getTemplateCases')]
    public function testFilterValidationValidatorConstructTemplate(
        array $options,
        array $expectedOptions,
        string $expectedTemplate,
        bool $expectedChanged,
        array $expectedTemplates
    ): void {
        $validator = new PresenceOf($options);

        $actual = $this->getProtectedProperty($validator, 'options');
        $this->assertSame($expectedOptions, $actual);

        $actual = $this->getProtectedProperty($validator, 'template');
        $this->assertSame($expectedTemplate, $actual);

        $actual = $this->getProtectedProperty($validator, 'templateChanged');
        $this->assertSame($expectedChanged, $actual);

        $actual = $validator->getTemplates();
        $this->assertSame($expectedTemplates, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-27
     */
    public function testFilterValidationValidatorConstructTemplateReference(): void
    {
        $message   = 'Msg';
        $validator = new PresenceOf(['message' => &$message]);

        $actual = $this->getProtectedProperty($validator, 'template');
        $this->assertSame('Msg', $actual);

        $actual = $this->getProtectedProperty($validator, 'templateChanged');
        $this->assertTrue($actual);

        $templates = ['name' => 'Name msg'];
        $validator = new PresenceOf(['message' => &$templates]);

        $expected = ['name' => 'Name msg'];
        $actual   = $validator->getTemplates();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testFilterValidationValidatorStringLengthConstruct(): void
    {
        $validator = new StringLength();

        $this->assertInstanceOf(
            ValidatorCompositeInterface::class,
            $validator,
            'StringLength implements ValidatorCompositeInterface'
        );
    }
}
