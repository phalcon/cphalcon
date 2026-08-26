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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\Alnum;
use Phalcon\Filter\Validation\Validator\Alpha;
use Phalcon\Filter\Validation\Validator\Confirmation;
use Phalcon\Filter\Validation\Validator\CreditCard;
use Phalcon\Filter\Validation\Validator\Digit;
use Phalcon\Filter\Validation\Validator\Numericality;
use Phalcon\Filter\Validation\Validator\Regex;
use Phalcon\Filter\Validation\Validator\StringLength\Max;
use Phalcon\Filter\Validation\Validator\StringLength\Min;
use Phalcon\Filter\Validation\ValidatorInterface;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use Stringable;

use function str_repeat;

/**
 * An array-shaped field (`field[]=x`) cast to string is the constant "Array",
 * which satisfies every string predicate. The validators must reject a value
 * that cannot be a string instead of casting it.
 */
final class NonStringValueTest extends AbstractUnitTestCase
{
    /**
     * @return array<string, array{ValidatorInterface, array<string, mixed>}>
     */
    public static function getValidators(): array
    {
        return [
            'Alnum'        => [new Alnum(), ['field' => ['x y']]],
            'Alpha'        => [new Alpha(), ['field' => ['anything']]],
            'Confirmation' => [
                new Confirmation(['with' => 'other']),
                ['field' => ['secretA'], 'other' => ['otherB']],
            ],
            'CreditCard'   => [new CreditCard(), ['field' => ['4111111111111111']]],
            'Digit'        => [new Digit(), ['field' => ['1']]],
            'Numericality' => [new Numericality(), ['field' => ['1']]],
            'Regex'        => [new Regex(['pattern' => '/^A/']), ['field' => ['Array']]],
            'Max'          => [new Max(['max' => 10]), ['field' => [str_repeat('x', 100)]]],
            'Min'          => [new Min(['min' => 5]), ['field' => ['a']]],
            'object'       => [new Alpha(), ['field' => new \stdClass()]],
        ];
    }

    /**
     * @param array<string, mixed> $data
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    #[DataProvider('getValidators')]
    public function testFilterValidationValidatorRejectsNonStringValue(
        ValidatorInterface $validator,
        array $data
    ): void {
        $validation = new Validation();
        $validation->add('field', $validator);

        $messages = $validation->validate($data);

        $this->assertSame(1, $messages->count());
        $this->assertSame('field', $messages->offsetGet(0)->getField());
    }

    /**
     * A Stringable object is a string for the validators.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testFilterValidationValidatorAcceptsStringable(): void
    {
        $value = new class () implements Stringable {
            public function __toString(): string
            {
                return 'abc';
            }
        };

        $validation = new Validation();
        $validation->add('field', new Alpha());
        $validation->add('field', new Min(['min' => 3]));

        $this->assertSame(0, $validation->validate(['field' => $value])->count());
    }
}
